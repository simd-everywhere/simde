#define SIMDE_TEST_ARM_NEON_INSN st4

#include "test-neon.h"
#include "../../../simde/arm/neon/st4.h"
#include "../../../simde/arm/neon/ld4.h"

static int
test_simde_vst4_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[4][2];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(  -689.58), SIMDE_FLOAT32_C(   424.29) },
          { SIMDE_FLOAT32_C(   916.54), SIMDE_FLOAT32_C(   -41.78) },
          { SIMDE_FLOAT32_C(  -325.95), SIMDE_FLOAT32_C(   260.26) },
          { SIMDE_FLOAT32_C(   116.36), SIMDE_FLOAT32_C(   580.20) } },
    },
    {
        { { SIMDE_FLOAT32_C(   803.46), SIMDE_FLOAT32_C(  -524.34) },
          { SIMDE_FLOAT32_C(   883.19), SIMDE_FLOAT32_C(   354.46) },
          { SIMDE_FLOAT32_C(  -857.98), SIMDE_FLOAT32_C(  -147.95) },
          { SIMDE_FLOAT32_C(   897.83), SIMDE_FLOAT32_C(  -851.78) } },
    },
    {
        { { SIMDE_FLOAT32_C(   -35.29), SIMDE_FLOAT32_C(   -62.28) },
          { SIMDE_FLOAT32_C(   884.68), SIMDE_FLOAT32_C(    86.78) },
          { SIMDE_FLOAT32_C(  -849.14), SIMDE_FLOAT32_C(  -158.90) },
          { SIMDE_FLOAT32_C(  -307.79), SIMDE_FLOAT32_C(   570.18) } },
    },
    {
        { { SIMDE_FLOAT32_C(   -50.74), SIMDE_FLOAT32_C(  -233.72) },
          { SIMDE_FLOAT32_C(   -85.94), SIMDE_FLOAT32_C(  -909.11) },
          { SIMDE_FLOAT32_C(   304.67), SIMDE_FLOAT32_C(  -365.69) },
          { SIMDE_FLOAT32_C(   175.26), SIMDE_FLOAT32_C(   615.10) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -941.39), SIMDE_FLOAT32_C(    91.80) },
          { SIMDE_FLOAT32_C(  -426.69), SIMDE_FLOAT32_C(  -267.34) },
          { SIMDE_FLOAT32_C(  -647.93), SIMDE_FLOAT32_C(   689.67) },
          { SIMDE_FLOAT32_C(  -687.14), SIMDE_FLOAT32_C(  -844.48) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -834.67), SIMDE_FLOAT32_C(  -803.95) },
          { SIMDE_FLOAT32_C(   509.99), SIMDE_FLOAT32_C(  -692.65) },
          { SIMDE_FLOAT32_C(    48.09), SIMDE_FLOAT32_C(   407.82) },
          { SIMDE_FLOAT32_C(  -544.43), SIMDE_FLOAT32_C(  -987.20) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -654.46), SIMDE_FLOAT32_C(  -659.75) },
          { SIMDE_FLOAT32_C(    99.58), SIMDE_FLOAT32_C(  -503.60) },
          { SIMDE_FLOAT32_C(   181.35), SIMDE_FLOAT32_C(   791.79) },
          { SIMDE_FLOAT32_C(  -933.42), SIMDE_FLOAT32_C(  -869.40) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -441.93), SIMDE_FLOAT32_C(   -19.36) },
          { SIMDE_FLOAT32_C(  -778.51), SIMDE_FLOAT32_C(   862.75) },
          { SIMDE_FLOAT32_C(   614.95), SIMDE_FLOAT32_C(   396.75) },
          { SIMDE_FLOAT32_C(   477.84), SIMDE_FLOAT32_C(   673.56) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x4_t a = simde_vld4_f32(test_vec[i].r[0]);
    simde_float32_t r_[4][2];
    simde_vst4_f32(r_[0], a);
    simde_test_arm_neon_assert_equal_f32x2(simde_vld1_f32(r_[0]), simde_vld1_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x2(simde_vld1_f32(r_[1]), simde_vld1_f32(test_vec[i].r[1]), 1);
    simde_test_arm_neon_assert_equal_f32x2(simde_vld1_f32(r_[2]), simde_vld1_f32(test_vec[i].r[2]), 1);
    simde_test_arm_neon_assert_equal_f32x2(simde_vld1_f32(r_[3]), simde_vld1_f32(test_vec[i].r[3]), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2x4_t a = { { simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f), } };
    simde_test_arm_neon_write_f32x2x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[4][1];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(   707.61) },
          { SIMDE_FLOAT64_C(  -971.47) },
          { SIMDE_FLOAT64_C(  -441.32) },
          { SIMDE_FLOAT64_C(  -148.98) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -269.53) },
          { SIMDE_FLOAT64_C(   354.98) },
          { SIMDE_FLOAT64_C(   144.52) },
          { SIMDE_FLOAT64_C(  -104.41) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -605.32) },
          { SIMDE_FLOAT64_C(  -468.14) },
          { SIMDE_FLOAT64_C(   158.58) },
          { SIMDE_FLOAT64_C(   905.28) } },
    },
    {
        { { SIMDE_FLOAT64_C(   650.83) },
          { SIMDE_FLOAT64_C(   663.12) },
          { SIMDE_FLOAT64_C(  -169.26) },
          { SIMDE_FLOAT64_C(    76.45) } },
    },
    {
        { { SIMDE_FLOAT64_C(   675.41) },
          { SIMDE_FLOAT64_C(  -454.30) },
          { SIMDE_FLOAT64_C(   137.93) },
          { SIMDE_FLOAT64_C(  -140.65) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -712.94) },
          { SIMDE_FLOAT64_C(   757.76) },
          { SIMDE_FLOAT64_C(  -262.89) },
          { SIMDE_FLOAT64_C(  -720.63) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -799.59) },
          { SIMDE_FLOAT64_C(   227.55) },
          { SIMDE_FLOAT64_C(   643.28) },
          { SIMDE_FLOAT64_C(   155.50) } },
    },
    {
        { { SIMDE_FLOAT64_C(   263.38) },
          { SIMDE_FLOAT64_C(   632.32) },
          { SIMDE_FLOAT64_C(  -483.06) },
          { SIMDE_FLOAT64_C(   -29.01) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x4_t a = simde_vld4_f64(test_vec[i].r[0]);
    simde_float64_t r_[4][1];
    simde_vst4_f64(r_[0], a);
    simde_test_arm_neon_assert_equal_f64x1(simde_vld1_f64(r_[0]), simde_vld1_f64(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f64x1(simde_vld1_f64(r_[1]), simde_vld1_f64(test_vec[i].r[1]), 1);
    simde_test_arm_neon_assert_equal_f64x1(simde_vld1_f64(r_[2]), simde_vld1_f64(test_vec[i].r[2]), 1);
    simde_test_arm_neon_assert_equal_f64x1(simde_vld1_f64(r_[3]), simde_vld1_f64(test_vec[i].r[3]), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1x4_t a = { { simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x1(-1000.0, 1000.0), } };
    simde_test_arm_neon_write_f64x1x4(2,a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[4][8];
  } test_vec[] = {
    {
        { {  INT8_C(  63), -INT8_C(  59),  INT8_C(   6), -INT8_C(  34), -INT8_C(  30), -INT8_C( 106), -INT8_C(  53),  INT8_C(  66) },
          { -INT8_C(  74), -INT8_C(  39),  INT8_C( 125), -INT8_C(  65), -INT8_C(  21), -INT8_C( 117),  INT8_C(  67), -INT8_C(  52) },
          { -INT8_C( 119), -INT8_C( 109),  INT8_C(  11), -INT8_C( 114), -INT8_C(  26),  INT8_C( 117),  INT8_C(   0), -INT8_C(  23) },
          {  INT8_C(  48), -INT8_C( 120),  INT8_C(  74), -INT8_C(   5), -INT8_C(  98),  INT8_C( 118),  INT8_C( 122), -INT8_C(  35) } },
    },
    {
        { {  INT8_C(  59),      INT8_MIN, -INT8_C(  68),  INT8_C(  30),  INT8_C(  23), -INT8_C( 121),  INT8_C(  96), -INT8_C(  51) },
          {  INT8_C(  96), -INT8_C(  35), -INT8_C( 116),  INT8_C(  75),  INT8_C( 105), -INT8_C(  49),  INT8_C(  24), -INT8_C(  14) },
          {  INT8_C(  98),  INT8_C(  35), -INT8_C( 127),  INT8_C(  72), -INT8_C( 104), -INT8_C( 127),  INT8_C(  49), -INT8_C(  56) },
          {  INT8_C(  10),  INT8_C( 123), -INT8_C(  61), -INT8_C(  88), -INT8_C(  15),  INT8_C(  61), -INT8_C( 123),  INT8_C(  45) } },
    },
    {
        { { -INT8_C(  66),  INT8_C(  65),  INT8_C(  75), -INT8_C(  43), -INT8_C(  56), -INT8_C(  85), -INT8_C(  94),  INT8_C(  40) },
          { -INT8_C( 119),  INT8_C(  46),  INT8_C( 116), -INT8_C(  14), -INT8_C(   3), -INT8_C( 116), -INT8_C(  28),  INT8_C(  95) },
          { -INT8_C(  81),  INT8_C( 101), -INT8_C(  88),  INT8_C(  71), -INT8_C(  25), -INT8_C(  39),  INT8_C(  15), -INT8_C(  15) },
          {  INT8_C(  85), -INT8_C(  45), -INT8_C( 103),  INT8_C(  70),  INT8_C(  16),  INT8_C(  30),  INT8_C( 115), -INT8_C(  50) } },
    },
    {
        { {  INT8_C(  96), -INT8_C(  66), -INT8_C(  93),  INT8_C(  40),  INT8_C( 106),  INT8_C(  69),  INT8_C(  81), -INT8_C(  13) },
          {  INT8_C( 115), -INT8_C(  59), -INT8_C(  27),  INT8_C( 112),  INT8_C(  81), -INT8_C(  55), -INT8_C(  48),  INT8_C(   0) },
          {  INT8_C(  47),  INT8_C( 120),  INT8_C(  71),  INT8_C(  22),  INT8_C(  81),  INT8_C(  86),  INT8_C(   7), -INT8_C(  90) },
          {  INT8_C(  41), -INT8_C(  96), -INT8_C(  19),  INT8_C(  58), -INT8_C(  66),  INT8_C(  96),  INT8_C(   8),  INT8_C(  30) } },
    },
    {
        { {  INT8_C(  31), -INT8_C(  84),  INT8_C(  71), -INT8_C( 119), -INT8_C(  15), -INT8_C( 104),  INT8_C( 124),  INT8_C( 101) },
          {  INT8_C(  93),  INT8_C(  97), -INT8_C(  43), -INT8_C(  82),  INT8_C(  42), -INT8_C(  91), -INT8_C(  82),  INT8_C(  89) },
          {  INT8_C(  29), -INT8_C(  11),  INT8_C( 111),  INT8_C( 111),  INT8_C(  75),  INT8_C( 118),  INT8_C(  21),  INT8_C( 117) },
          {  INT8_C(  22),  INT8_C(   2), -INT8_C(  81), -INT8_C(  43),  INT8_C(  99), -INT8_C(  73), -INT8_C(  13), -INT8_C( 126) } },
    },
    {
        { {  INT8_C(  99),  INT8_C(  58),  INT8_C(  11),  INT8_C(  85), -INT8_C(  46), -INT8_C( 121), -INT8_C(  70),  INT8_C(  47) },
          { -INT8_C(  24), -INT8_C( 113), -INT8_C(  35),  INT8_C(  18),  INT8_C(  53), -INT8_C( 117),  INT8_C( 108),  INT8_C(  82) },
          {      INT8_MIN, -INT8_C(  37), -INT8_C(  63), -INT8_C(  52),  INT8_C(  82), -INT8_C(  41),  INT8_C(  65),  INT8_C( 104) },
          { -INT8_C(  39), -INT8_C(  16),  INT8_C(  61),  INT8_C(  60), -INT8_C(  89),  INT8_C(  49), -INT8_C(  66),  INT8_C(  11) } },
    },
    {
        { {  INT8_C( 107), -INT8_C(  55),  INT8_C(  96),  INT8_C(  62),  INT8_C(  80),  INT8_C(  26),  INT8_C( 109),  INT8_C(  56) },
          { -INT8_C(  87),  INT8_C(  75),  INT8_C(  75), -INT8_C(  34), -INT8_C(  42), -INT8_C(  73),  INT8_C(  49),  INT8_C(  87) },
          { -INT8_C( 110), -INT8_C(  14),  INT8_C(  35), -INT8_C(  28), -INT8_C(  55),  INT8_C( 100),  INT8_C(  77), -INT8_C(  93) },
          {  INT8_C(  84), -INT8_C( 118), -INT8_C(  33), -INT8_C(   5), -INT8_C(  69), -INT8_C(  98),  INT8_C(   6),  INT8_C(  39) } },
    },
    {
        { {  INT8_C( 103),  INT8_C( 102),  INT8_C( 101), -INT8_C(  72),      INT8_MIN, -INT8_C(  46), -INT8_C(  16),  INT8_C(  42) },
          {  INT8_C(  29),  INT8_C(  59),  INT8_C(   8), -INT8_C(  12), -INT8_C(  14),  INT8_C(  57),  INT8_C(  75), -INT8_C( 123) },
          {  INT8_C(  44),  INT8_C( 110),  INT8_C( 105), -INT8_C(  11), -INT8_C(  46), -INT8_C(  74), -INT8_C( 104),  INT8_C(  38) },
          {  INT8_C(  65),  INT8_C( 120),  INT8_C(  33), -INT8_C(   4),  INT8_C(  22),  INT8_C(  40),  INT8_C(  35),  INT8_C( 125) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x4_t a = simde_vld4_s8(test_vec[i].r[0]);
    int8_t r_[4][8];
    simde_vst4_s8(r_[0], a);
    simde_test_arm_neon_assert_equal_i8x8(simde_vld1_s8(r_[0]), simde_vld1_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x8(simde_vld1_s8(r_[1]), simde_vld1_s8(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i8x8(simde_vld1_s8(r_[2]), simde_vld1_s8(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_i8x8(simde_vld1_s8(r_[3]), simde_vld1_s8(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8x4_t a = { { simde_test_arm_neon_random_i8x8(),
                             simde_test_arm_neon_random_i8x8(),
                             simde_test_arm_neon_random_i8x8(),
                             simde_test_arm_neon_random_i8x8(), } };
    simde_test_arm_neon_write_i8x8x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[4][4];
  } test_vec[] = {
    {
        { {  INT16_C( 31519), -INT16_C(   692), -INT16_C( 29182), -INT16_C( 14238) },
          { -INT16_C( 25406), -INT16_C( 13925),  INT16_C( 13554), -INT16_C( 12416) },
          { -INT16_C(  3353), -INT16_C( 15110), -INT16_C( 28519),  INT16_C( 30718) },
          {  INT16_C( 30471),  INT16_C(  2871),  INT16_C( 17819), -INT16_C( 17780) } },
    },
    {
        { { -INT16_C( 10048), -INT16_C( 15689),  INT16_C(  6502),  INT16_C( 10634) },
          {  INT16_C(  9909), -INT16_C( 22286),  INT16_C( 29530),  INT16_C( 16759) },
          {  INT16_C( 29029), -INT16_C(   507),  INT16_C(   769),  INT16_C(  2165) },
          { -INT16_C( 21382),  INT16_C(  5396), -INT16_C( 24335), -INT16_C( 19761) } },
    },
    {
        { { -INT16_C( 31112), -INT16_C(  8332), -INT16_C(    96),  INT16_C( 21768) },
          { -INT16_C(  1499),  INT16_C( 32765),  INT16_C( 29805), -INT16_C( 11583) },
          { -INT16_C( 14619), -INT16_C(  6448),  INT16_C( 17866),  INT16_C( 17647) },
          {  INT16_C(  1009), -INT16_C(  7334),  INT16_C( 10659),  INT16_C(  7061) } },
    },
    {
        { {  INT16_C(  2480),  INT16_C( 20730),  INT16_C(   520),  INT16_C( 11685) },
          { -INT16_C( 23555),  INT16_C( 27309),  INT16_C( 28183), -INT16_C(   707) },
          {  INT16_C(  3380), -INT16_C(   285), -INT16_C( 11693),  INT16_C( 17475) },
          { -INT16_C( 25131),  INT16_C( 30759), -INT16_C( 17210),  INT16_C( 30356) } },
    },
    {
        { { -INT16_C( 28986), -INT16_C( 12602),  INT16_C( 27793), -INT16_C( 28932) },
          { -INT16_C( 22257),  INT16_C(  9976),  INT16_C( 13591),  INT16_C( 19235) },
          {  INT16_C(  1859), -INT16_C( 27062), -INT16_C( 29223), -INT16_C( 20518) },
          {  INT16_C(   554), -INT16_C(  4057), -INT16_C( 17474), -INT16_C( 31641) } },
    },
    {
        { {  INT16_C( 11594), -INT16_C(  9389),  INT16_C( 20377), -INT16_C( 22423) },
          {  INT16_C( 25080),  INT16_C(  4047), -INT16_C(  3433), -INT16_C(  9638) },
          { -INT16_C( 23303), -INT16_C( 11408),  INT16_C( 18993),  INT16_C( 23426) },
          { -INT16_C( 22196),  INT16_C(  2892), -INT16_C( 19611), -INT16_C( 20593) } },
    },
    {
        { { -INT16_C(  7456),  INT16_C( 31370), -INT16_C(  3279),  INT16_C( 10530) },
          { -INT16_C(  3756), -INT16_C(  5320), -INT16_C( 27676), -INT16_C(  8763) },
          {  INT16_C( 13623),  INT16_C( 27056),  INT16_C( 12928), -INT16_C( 13116) },
          {  INT16_C(  4316),  INT16_C( 16855),  INT16_C( 26563), -INT16_C( 23312) } },
    },
    {
        { {  INT16_C( 31305),  INT16_C( 31518),  INT16_C( 16493), -INT16_C( 15964) },
          { -INT16_C(  8910),  INT16_C(  5805),  INT16_C( 29296), -INT16_C( 22541) },
          { -INT16_C( 23384),  INT16_C( 10256), -INT16_C( 10794), -INT16_C( 19724) },
          { -INT16_C( 13083), -INT16_C( 22029), -INT16_C(  7373),  INT16_C( 31821) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x4_t a = simde_vld4_s16(test_vec[i].r[0]);
    int16_t r_[4][4];
    simde_vst4_s16(r_[0], a);
    simde_test_arm_neon_assert_equal_i16x4(simde_vld1_s16(r_[0]), simde_vld1_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x4(simde_vld1_s16(r_[1]), simde_vld1_s16(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i16x4(simde_vld1_s16(r_[2]), simde_vld1_s16(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_i16x4(simde_vld1_s16(r_[3]), simde_vld1_s16(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4x4_t a = { { simde_test_arm_neon_random_i16x4(),
                              simde_test_arm_neon_random_i16x4(),
                              simde_test_arm_neon_random_i16x4(),
                              simde_test_arm_neon_random_i16x4(), } };
    simde_test_arm_neon_write_i16x4x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[4][2];
  } test_vec[] = {
    {
        { { -INT32_C(  1400465696), -INT32_C(  1945575769) },
          {  INT32_C(    28894490), -INT32_C(  1668380727) },
          { -INT32_C(  1899261259), -INT32_C(  1133830515) },
          {  INT32_C(  1061439128),  INT32_C(  1451060598) } },
    },
    {
        { { -INT32_C(  1425931516), -INT32_C(    80278815) },
          { -INT32_C(  1191317265),  INT32_C(   760515447) },
          { -INT32_C(  1413799906), -INT32_C(   681105858) },
          { -INT32_C(   501830804),  INT32_C(   490312473) } },
    },
    {
        { {  INT32_C(  2026388374),  INT32_C(   896729158) },
          {  INT32_C(  1743679728),  INT32_C(   445924092) },
          { -INT32_C(  1580904606), -INT32_C(   512217995) },
          { -INT32_C(   255553833), -INT32_C(  1223819999) } },
    },
    {
        { {  INT32_C(  2117064248), -INT32_C(   961240106) },
          {  INT32_C(   254648851),  INT32_C(  1193919204) },
          { -INT32_C(  2014777839), -INT32_C(   228040678) },
          {  INT32_C(   266480878),  INT32_C(  1657204777) } },
    },
    {
        { { -INT32_C(  1662978362), -INT32_C(  1402825575) },
          {  INT32_C(   465342262),  INT32_C(  1667425617) },
          { -INT32_C(   286635308), -INT32_C(  1730129238) },
          { -INT32_C(  1465400449),  INT32_C(  2030726579) } },
    },
    {
        { { -INT32_C(    65672349), -INT32_C(  1230407809) },
          {  INT32_C(  1490117894),  INT32_C(   515584842) },
          {  INT32_C(   655205757),  INT32_C(  1992289783) },
          {  INT32_C(  1663002288),  INT32_C(   937175507) } },
    },
    {
        { { -INT32_C(  1808535276),  INT32_C(  1867177064) },
          { -INT32_C(  1933108415), -INT32_C(   878017970) },
          {  INT32_C(   519223079),  INT32_C(  1435873701) },
          { -INT32_C(   356928489), -INT32_C(   232679971) } },
    },
    {
        { { -INT32_C(   276408953),  INT32_C(  1935593521) },
          {  INT32_C(   973022699), -INT32_C(   838555225) },
          {  INT32_C(   116258401), -INT32_C(  1101299033) },
          {  INT32_C(   329782326),  INT32_C(   822463146) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x4_t a = simde_vld4_s32(test_vec[i].r[0]);
    int32_t r_[4][2];
    simde_vst4_s32(r_[0], a);
    simde_test_arm_neon_assert_equal_i32x2(simde_vld1_s32(r_[0]), simde_vld1_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x2(simde_vld1_s32(r_[1]), simde_vld1_s32(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i32x2(simde_vld1_s32(r_[2]), simde_vld1_s32(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_i32x2(simde_vld1_s32(r_[3]), simde_vld1_s32(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2x4_t a = { { simde_test_arm_neon_random_i32x2(),
                              simde_test_arm_neon_random_i32x2(),
                              simde_test_arm_neon_random_i32x2(),
                              simde_test_arm_neon_random_i32x2(), } };
    simde_test_arm_neon_write_i32x2x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[4][1];
  } test_vec[] = {
    {
        { { -INT64_C( 3780091122451676323) },
          { -INT64_C(  503908098603502708) },
          { -INT64_C( 4632755620009786861) },
          {  INT64_C( 8129883617665927448) } },
    },
    {
        { {  INT64_C( 8366243247627140393) },
          {  INT64_C( 4236626280537417104) },
          {  INT64_C( 2870773247892581064) },
          {  INT64_C( 7301886664130958802) } },
    },
    {
        { {  INT64_C( 1539614821672331264) },
          {  INT64_C( 3357066724966392116) },
          { -INT64_C( 4047858703376389220) },
          {  INT64_C(  563796609296270130) } },
    },
    {
        { { -INT64_C( 8411231696460937302) },
          {  INT64_C( 8918110082058103854) },
          {  INT64_C( 6351476417177782632) },
          {  INT64_C( 9046774880947064958) } },
    },
    {
        { { -INT64_C(  647688449277723615) },
          { -INT64_C( 3496957802599093985) },
          {  INT64_C( 1789706526398390104) },
          {  INT64_C( 6300581194683489569) } },
    },
    {
        { {  INT64_C( 3415928710909336998) },
          { -INT64_C( 7281857419021585477) },
          { -INT64_C( 8073003122075099580) },
          {  INT64_C( 7141006680510403467) } },
    },
    {
        { {  INT64_C( 8453319972168591377) },
          {  INT64_C( 7352276068853054508) },
          { -INT64_C( 7303647759720767322) },
          {  INT64_C( 3237655042800232398) } },
    },
    {
        { {  INT64_C( 2850107836670525790) },
          {  INT64_C( 6026272243264594969) },
          { -INT64_C( 1195691266530548290) },
          { -INT64_C( 7387195064608701388) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x4_t a = simde_vld4_s64(test_vec[i].r[0]);
    int64_t r_[4][1];
    simde_vst4_s64(r_[0], a);
    simde_test_arm_neon_assert_equal_i64x1(simde_vld1_s64(r_[0]), simde_vld1_s64(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i64x1(simde_vld1_s64(r_[1]), simde_vld1_s64(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i64x1(simde_vld1_s64(r_[2]), simde_vld1_s64(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_i64x1(simde_vld1_s64(r_[3]), simde_vld1_s64(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1x4_t a = { { simde_test_arm_neon_random_i64x1(),
                              simde_test_arm_neon_random_i64x1(),
                              simde_test_arm_neon_random_i64x1(),
                              simde_test_arm_neon_random_i64x1(), } };
    simde_test_arm_neon_write_i64x1x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[4][8];
  } test_vec[] = {
    {
        { { UINT8_C(236), UINT8_C( 44), UINT8_C( 59), UINT8_C(168), UINT8_C(197), UINT8_C( 84), UINT8_C(117), UINT8_C( 14) },
          { UINT8_C(173), UINT8_C(171), UINT8_C(135), UINT8_C(  4), UINT8_C( 32), UINT8_C(188), UINT8_C( 30), UINT8_C(  3) },
          { UINT8_C(213), UINT8_C(114), UINT8_C( 39), UINT8_C(190), UINT8_C( 80), UINT8_C(235), UINT8_C( 97), UINT8_C(  7) },
          { UINT8_C( 29), UINT8_C(112), UINT8_C(  7), UINT8_C( 33), UINT8_C(186), UINT8_C( 65), UINT8_C(180), UINT8_C(166) } },
    },
    {
        { { UINT8_C(109), UINT8_C(239), UINT8_C( 79), UINT8_C( 50), UINT8_C( 67), UINT8_C(196), UINT8_C( 64), UINT8_C(241) },
          { UINT8_C(111), UINT8_C(199), UINT8_C(245), UINT8_C(143), UINT8_C(131), UINT8_C( 19), UINT8_C(146), UINT8_C( 89) },
          { UINT8_C(133), UINT8_C(185), UINT8_C( 23), UINT8_C(213), UINT8_C(164), UINT8_C(120), UINT8_C(220), UINT8_C(194) },
          { UINT8_C(232), UINT8_C(228), UINT8_C(227), UINT8_C(163), UINT8_C( 37), UINT8_C(151), UINT8_C( 73), UINT8_C(146) } },
    },
    {
        { { UINT8_C(135), UINT8_C(152), UINT8_C(196), UINT8_C(202), UINT8_C( 93), UINT8_C(  4), UINT8_C(187), UINT8_C(204) },
          { UINT8_C(203), UINT8_C(176), UINT8_C( 92), UINT8_C( 79), UINT8_C(196), UINT8_C(238), UINT8_C(168), UINT8_C( 73) },
          { UINT8_C(168), UINT8_C(191), UINT8_C( 31), UINT8_C( 76), UINT8_C( 55), UINT8_C(251), UINT8_C( 14), UINT8_C( 32) },
          { UINT8_C(223), UINT8_C(242), UINT8_C(195), UINT8_C(  4), UINT8_C(137), UINT8_C( 12), UINT8_C(150), UINT8_C( 16) } },
    },
    {
        { { UINT8_C(165), UINT8_C( 90), UINT8_C(219), UINT8_C(  2), UINT8_C( 94), UINT8_C(150), UINT8_C(206), UINT8_C( 42) },
          { UINT8_C( 71), UINT8_C( 42), UINT8_C(121), UINT8_C( 11), UINT8_C( 25), UINT8_C( 33), UINT8_C( 84), UINT8_C(193) },
          { UINT8_C(224), UINT8_C(115), UINT8_C( 13), UINT8_C( 23), UINT8_C(111), UINT8_C( 28), UINT8_C( 55), UINT8_C( 78) },
          { UINT8_C( 14), UINT8_C(250), UINT8_C( 83), UINT8_C(151), UINT8_C(  7), UINT8_C(233), UINT8_C(168), UINT8_C(172) } },
    },
    {
        { { UINT8_C( 68), UINT8_C(131), UINT8_C(174), UINT8_C(162), UINT8_C( 25), UINT8_C(124), UINT8_C(204), UINT8_C( 96) },
          { UINT8_C(167), UINT8_C( 69), UINT8_C(107), UINT8_C(192), UINT8_C(102), UINT8_C(192), UINT8_C(129), UINT8_C( 70) },
          { UINT8_C( 51), UINT8_C(142), UINT8_C( 94), UINT8_C(162), UINT8_C(170), UINT8_C(149), UINT8_C(241), UINT8_C(184) },
          { UINT8_C(144), UINT8_C( 68), UINT8_C( 80), UINT8_C(151), UINT8_C( 45), UINT8_C(248), UINT8_C( 67), UINT8_C(113) } },
    },
    {
        { { UINT8_C(123), UINT8_C(241), UINT8_C( 20), UINT8_C(148), UINT8_C(109), UINT8_C(224), UINT8_C(245), UINT8_C( 20) },
          { UINT8_C( 38), UINT8_C( 96), UINT8_C(212), UINT8_C(140), UINT8_C( 32), UINT8_C( 85), UINT8_C(211), UINT8_C( 84) },
          { UINT8_C(228), UINT8_C( 49), UINT8_C(246), UINT8_C(142), UINT8_C(198), UINT8_C(231), UINT8_C( 71), UINT8_C( 86) },
          { UINT8_C( 43), UINT8_C(151), UINT8_C(237), UINT8_C( 89), UINT8_C(143), UINT8_C( 48), UINT8_C(202), UINT8_C( 10) } },
    },
    {
        { { UINT8_C( 33), UINT8_C(222), UINT8_C(158), UINT8_C(143), UINT8_C(191), UINT8_C(147), UINT8_C(163), UINT8_C(229) },
          { UINT8_C(244), UINT8_C(120), UINT8_C(113), UINT8_C( 20), UINT8_C(205), UINT8_C( 68), UINT8_C(104), UINT8_C(177) },
          { UINT8_C(117), UINT8_C( 95), UINT8_C( 64), UINT8_C( 60), UINT8_C( 70), UINT8_C(135), UINT8_C(146), UINT8_C(114) },
          { UINT8_C( 30), UINT8_C(128), UINT8_C(203), UINT8_C(173), UINT8_C(176), UINT8_C(149), UINT8_C(183), UINT8_C(210) } },
    },
    {
        { { UINT8_C(116), UINT8_C( 85), UINT8_C( 97), UINT8_C( 51), UINT8_C(233), UINT8_C(  4), UINT8_C( 24), UINT8_C(221) },
          { UINT8_C(124), UINT8_C(137), UINT8_C(241), UINT8_C( 74), UINT8_C(206), UINT8_C( 90), UINT8_C(251), UINT8_C( 67) },
          { UINT8_C(185), UINT8_C( 59), UINT8_C(127),    UINT8_MAX, UINT8_C(194), UINT8_C( 18), UINT8_C(113), UINT8_C(224) },
          { UINT8_C(146), UINT8_C( 60), UINT8_C(141), UINT8_C( 66), UINT8_C(210), UINT8_C( 68), UINT8_C( 20), UINT8_C( 70) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x4_t a = simde_vld4_u8(test_vec[i].r[0]);
    uint8_t r_[4][8];
    simde_vst4_u8(r_[0], a);
    simde_test_arm_neon_assert_equal_u8x8(simde_vld1_u8(r_[0]), simde_vld1_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x8(simde_vld1_u8(r_[1]), simde_vld1_u8(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u8x8(simde_vld1_u8(r_[2]), simde_vld1_u8(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_u8x8(simde_vld1_u8(r_[3]), simde_vld1_u8(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8x4_t a = { { simde_test_arm_neon_random_u8x8(),
                              simde_test_arm_neon_random_u8x8(),
                              simde_test_arm_neon_random_u8x8(),
                              simde_test_arm_neon_random_u8x8(), } };
    simde_test_arm_neon_write_u8x8x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[4][4];
  } test_vec[] = {
    {
        { { UINT16_C(25235), UINT16_C(32070), UINT16_C(23452), UINT16_C(26403) },
          { UINT16_C(19088), UINT16_C(37205), UINT16_C(24906), UINT16_C(41109) },
          { UINT16_C(24611), UINT16_C(34656), UINT16_C( 1915), UINT16_C(58351) },
          { UINT16_C(19991), UINT16_C(62166), UINT16_C(35984), UINT16_C( 9023) } },
    },
    {
        { { UINT16_C(34287), UINT16_C(35744), UINT16_C(50401), UINT16_C(29170) },
          { UINT16_C(18190), UINT16_C(22786), UINT16_C(38825), UINT16_C(52473) },
          { UINT16_C(23032), UINT16_C(29523), UINT16_C(16992), UINT16_C(30807) },
          { UINT16_C(11664), UINT16_C( 8554), UINT16_C(43450), UINT16_C(43332) } },
    },
    {
        { { UINT16_C(58671), UINT16_C( 4148), UINT16_C( 9897), UINT16_C(46977) },
          { UINT16_C(33645), UINT16_C( 5648), UINT16_C( 2587), UINT16_C( 5091) },
          { UINT16_C(13923), UINT16_C(50310), UINT16_C(56697), UINT16_C( 2364) },
          { UINT16_C(42507), UINT16_C(50474), UINT16_C(28495), UINT16_C(32366) } },
    },
    {
        { { UINT16_C(41556), UINT16_C(64910), UINT16_C( 4040), UINT16_C(13748) },
          { UINT16_C(50579), UINT16_C(44620), UINT16_C(12239), UINT16_C(12993) },
          { UINT16_C(18277), UINT16_C(57078), UINT16_C(12837), UINT16_C(12520) },
          { UINT16_C( 4824), UINT16_C(10485), UINT16_C(25473), UINT16_C(54694) } },
    },
    {
        { { UINT16_C(13573), UINT16_C(52690), UINT16_C(34628), UINT16_C(55042) },
          { UINT16_C(20044), UINT16_C( 7045), UINT16_C(18045), UINT16_C(58189) },
          { UINT16_C(17550), UINT16_C(46017), UINT16_C(43382), UINT16_C(20451) },
          { UINT16_C(55484), UINT16_C(15735), UINT16_C( 7483), UINT16_C(16403) } },
    },
    {
        { { UINT16_C(58706), UINT16_C(38669), UINT16_C( 3948), UINT16_C(47214) },
          { UINT16_C(62558), UINT16_C(56275), UINT16_C( 8506), UINT16_C(51390) },
          { UINT16_C(32869), UINT16_C(56187), UINT16_C(24105), UINT16_C(58666) },
          { UINT16_C(41270), UINT16_C(28963), UINT16_C(14015), UINT16_C( 4529) } },
    },
    {
        { { UINT16_C(48667), UINT16_C(34984), UINT16_C( 6094), UINT16_C(11328) },
          { UINT16_C( 5131), UINT16_C(17671), UINT16_C(50741), UINT16_C(39438) },
          { UINT16_C(35142), UINT16_C(28533), UINT16_C(41192), UINT16_C( 7765) },
          { UINT16_C(30785), UINT16_C(  144), UINT16_C(16814), UINT16_C(51474) } },
    },
    {
        { { UINT16_C(47616), UINT16_C(52817), UINT16_C(37585), UINT16_C(56570) },
          { UINT16_C(  422), UINT16_C(56098), UINT16_C(12487), UINT16_C( 3445) },
          { UINT16_C(60089), UINT16_C(41341), UINT16_C(53898), UINT16_C(52416) },
          { UINT16_C(20554), UINT16_C(63692), UINT16_C(56977), UINT16_C(37313) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x4_t a = simde_vld4_u16(test_vec[i].r[0]);
    uint16_t r_[4][4];
    simde_vst4_u16(r_[0], a);
    simde_test_arm_neon_assert_equal_u16x4(simde_vld1_u16(r_[0]), simde_vld1_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x4(simde_vld1_u16(r_[1]), simde_vld1_u16(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u16x4(simde_vld1_u16(r_[2]), simde_vld1_u16(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_u16x4(simde_vld1_u16(r_[3]), simde_vld1_u16(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4x4_t a = { { simde_test_arm_neon_random_u16x4(),
                               simde_test_arm_neon_random_u16x4(),
                               simde_test_arm_neon_random_u16x4(),
                               simde_test_arm_neon_random_u16x4(), } };
    simde_test_arm_neon_write_u16x4x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[4][2];
  } test_vec[] = {
    {
        { { UINT32_C( 287570488), UINT32_C(3599178496) },
          { UINT32_C(1485592264), UINT32_C( 501606591) },
          { UINT32_C(3928827715), UINT32_C( 178524505) },
          { UINT32_C(2038690194), UINT32_C(2093701700) } },
    },
    {
        { { UINT32_C(1418653268), UINT32_C(3526038794) },
          { UINT32_C( 707442539), UINT32_C(3796373407) },
          { UINT32_C(2429318454), UINT32_C( 429552007) },
          { UINT32_C(2794593634), UINT32_C(3424870008) } },
    },
    {
        { { UINT32_C(1445048652), UINT32_C( 824724678) },
          { UINT32_C(2740670979), UINT32_C(2558894946) },
          { UINT32_C(2686997017), UINT32_C( 632931011) },
          { UINT32_C(1489718496), UINT32_C(4129615530) } },
    },
    {
        { { UINT32_C(1699562911), UINT32_C(2509665681) },
          { UINT32_C( 708375240), UINT32_C(2931998101) },
          { UINT32_C(3528387343), UINT32_C(2381777069) },
          { UINT32_C(4276470612), UINT32_C(1374948017) } },
    },
    {
        { { UINT32_C(3786817871), UINT32_C(2138459575) },
          { UINT32_C(3567889983), UINT32_C(2072210283) },
          { UINT32_C(  72208726), UINT32_C( 764495321) },
          { UINT32_C(3106633480), UINT32_C(3490324609) } },
    },
    {
        { { UINT32_C( 414302561), UINT32_C(1301751566) },
          { UINT32_C(1092698325), UINT32_C(  45917356) },
          { UINT32_C(1325795702), UINT32_C(1451071566) },
          { UINT32_C(2417010703), UINT32_C( 710941384) } },
    },
    {
        { { UINT32_C(3913421531), UINT32_C( 255253049) },
          { UINT32_C(3327154202), UINT32_C(1925778684) },
          { UINT32_C(1690488597), UINT32_C(1991917415) },
          { UINT32_C(2953235175), UINT32_C(3235538917) } },
    },
    {
        { { UINT32_C(2997492857), UINT32_C( 297918710) },
          { UINT32_C( 903287096), UINT32_C( 866623517) },
          { UINT32_C(3617024368), UINT32_C(2421051816) },
          { UINT32_C(  20993052), UINT32_C( 885070523) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x4_t a = simde_vld4_u32(test_vec[i].r[0]);
    uint32_t r_[4][2];
    simde_vst4_u32(r_[0], a);
    simde_test_arm_neon_assert_equal_u32x2(simde_vld1_u32(r_[0]), simde_vld1_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x2(simde_vld1_u32(r_[1]), simde_vld1_u32(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u32x2(simde_vld1_u32(r_[2]), simde_vld1_u32(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_u32x2(simde_vld1_u32(r_[3]), simde_vld1_u32(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2x4_t a = { { simde_test_arm_neon_random_u32x2(),
                               simde_test_arm_neon_random_u32x2(),
                               simde_test_arm_neon_random_u32x2(),
                               simde_test_arm_neon_random_u32x2(), } };
    simde_test_arm_neon_write_u32x2x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[4][1];
  } test_vec[] = {
    {
        { { UINT64_C( 1179357718284256622) },
          { UINT64_C(16633838223353923937) },
          { UINT64_C(  671166547432719182) },
          { UINT64_C( 8790657086991020295) } },
    },
    {
        { { UINT64_C(13627466252990443637) },
          { UINT64_C(  245321614931489477) },
          { UINT64_C(13710522657751908817) },
          { UINT64_C(14539150475085914944) } },
    },
    {
        { { UINT64_C( 2736488037995766752) },
          { UINT64_C( 1089604195266768999) },
          { UINT64_C( 3442035367200120654) },
          { UINT64_C( 9822420776060073779) } },
    },
    {
        { { UINT64_C( 9558816664267794211) },
          { UINT64_C(12230299233737002349) },
          { UINT64_C(14428534390205121823) },
          { UINT64_C( 1862977276162848682) } },
    },
    {
        { { UINT64_C(14440584792126561990) },
          { UINT64_C(16614955261948528529) },
          { UINT64_C( 7029891109240455986) },
          { UINT64_C( 5041653883906285543) } },
    },
    {
        { { UINT64_C( 7516102983959483179) },
          { UINT64_C( 2325239418112426390) },
          { UINT64_C( 5783879118112634923) },
          { UINT64_C(12689215781325436758) } },
    },
    {
        { { UINT64_C( 7491885110950052281) },
          { UINT64_C( 6869688401445342279) },
          { UINT64_C(  791374270059134274) },
          { UINT64_C(  699175389701810813) } },
    },
    {
        { { UINT64_C(13146449792888138298) },
          { UINT64_C( 9399648215238457054) },
          { UINT64_C(13204035387945497727) },
          { UINT64_C( 5813141163015282002) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x4_t a = simde_vld4_u64(test_vec[i].r[0]);
    uint64_t r_[4][1];
    simde_vst4_u64(r_[0], a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vld1_u64(r_[0]), simde_vld1_u64(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u64x1(simde_vld1_u64(r_[1]), simde_vld1_u64(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u64x1(simde_vld1_u64(r_[2]), simde_vld1_u64(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_u64x1(simde_vld1_u64(r_[3]), simde_vld1_u64(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1x4_t a = { { simde_test_arm_neon_random_u64x1(),
                               simde_test_arm_neon_random_u64x1(),
                               simde_test_arm_neon_random_u64x1(),
                               simde_test_arm_neon_random_u64x1(), } };
    simde_test_arm_neon_write_u64x1x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[4][4];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(    75.64), SIMDE_FLOAT32_C(  -407.29), SIMDE_FLOAT32_C(   332.51), SIMDE_FLOAT32_C(   461.77) },
          { SIMDE_FLOAT32_C(   783.17), SIMDE_FLOAT32_C(   833.60), SIMDE_FLOAT32_C(  -482.33), SIMDE_FLOAT32_C(  -148.62) },
          { SIMDE_FLOAT32_C(   660.01), SIMDE_FLOAT32_C(   310.90), SIMDE_FLOAT32_C(  -853.14), SIMDE_FLOAT32_C(   652.67) },
          { SIMDE_FLOAT32_C(  -671.26), SIMDE_FLOAT32_C(  -373.46), SIMDE_FLOAT32_C(   708.85), SIMDE_FLOAT32_C(   603.68) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -376.26), SIMDE_FLOAT32_C(  -154.06), SIMDE_FLOAT32_C(   597.16), SIMDE_FLOAT32_C(    -7.09) },
          { SIMDE_FLOAT32_C(   -24.41), SIMDE_FLOAT32_C(  -124.32), SIMDE_FLOAT32_C(   601.63), SIMDE_FLOAT32_C(  -149.35) },
          { SIMDE_FLOAT32_C(  -763.30), SIMDE_FLOAT32_C(   380.51), SIMDE_FLOAT32_C(  -949.30), SIMDE_FLOAT32_C(  -987.90) },
          { SIMDE_FLOAT32_C(  -183.46), SIMDE_FLOAT32_C(   171.65), SIMDE_FLOAT32_C(   213.64), SIMDE_FLOAT32_C(   892.19) } },
    },
    {
        { { SIMDE_FLOAT32_C(   764.36), SIMDE_FLOAT32_C(  -453.85), SIMDE_FLOAT32_C(   353.96), SIMDE_FLOAT32_C(   547.52) },
          { SIMDE_FLOAT32_C(  -620.25), SIMDE_FLOAT32_C(   871.62), SIMDE_FLOAT32_C(  -601.10), SIMDE_FLOAT32_C(  -960.25) },
          { SIMDE_FLOAT32_C(   182.52), SIMDE_FLOAT32_C(  -454.25), SIMDE_FLOAT32_C(   692.42), SIMDE_FLOAT32_C(   511.26) },
          { SIMDE_FLOAT32_C(   172.29), SIMDE_FLOAT32_C(   401.26), SIMDE_FLOAT32_C(   114.93), SIMDE_FLOAT32_C(   796.03) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -752.80), SIMDE_FLOAT32_C(  -287.91), SIMDE_FLOAT32_C(  -211.06), SIMDE_FLOAT32_C(   222.79) },
          { SIMDE_FLOAT32_C(   587.77), SIMDE_FLOAT32_C(  -609.43), SIMDE_FLOAT32_C(  -926.56), SIMDE_FLOAT32_C(   824.47) },
          { SIMDE_FLOAT32_C(   771.08), SIMDE_FLOAT32_C(  -875.86), SIMDE_FLOAT32_C(   836.57), SIMDE_FLOAT32_C(  -412.38) },
          { SIMDE_FLOAT32_C(   295.79), SIMDE_FLOAT32_C(    50.21), SIMDE_FLOAT32_C(  -520.19), SIMDE_FLOAT32_C(    60.14) } },
    },
    {
        { { SIMDE_FLOAT32_C(   596.36), SIMDE_FLOAT32_C(   833.77), SIMDE_FLOAT32_C(  -392.34), SIMDE_FLOAT32_C(   976.10) },
          { SIMDE_FLOAT32_C(   705.39), SIMDE_FLOAT32_C(     6.56), SIMDE_FLOAT32_C(  -984.14), SIMDE_FLOAT32_C(  -112.09) },
          { SIMDE_FLOAT32_C(   552.32), SIMDE_FLOAT32_C(   708.27), SIMDE_FLOAT32_C(  -600.84), SIMDE_FLOAT32_C(  -275.39) },
          { SIMDE_FLOAT32_C(   109.54), SIMDE_FLOAT32_C(   514.09), SIMDE_FLOAT32_C(  -479.36), SIMDE_FLOAT32_C(   356.74) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -773.81), SIMDE_FLOAT32_C(   309.58), SIMDE_FLOAT32_C(  -420.47), SIMDE_FLOAT32_C(   813.96) },
          { SIMDE_FLOAT32_C(   700.16), SIMDE_FLOAT32_C(  -347.03), SIMDE_FLOAT32_C(   638.43), SIMDE_FLOAT32_C(   471.24) },
          { SIMDE_FLOAT32_C(  -222.89), SIMDE_FLOAT32_C(   475.00), SIMDE_FLOAT32_C(  -941.14), SIMDE_FLOAT32_C(  -927.10) },
          { SIMDE_FLOAT32_C(  -474.79), SIMDE_FLOAT32_C(  -461.33), SIMDE_FLOAT32_C(   133.04), SIMDE_FLOAT32_C(  -878.44) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -627.57), SIMDE_FLOAT32_C(   740.70), SIMDE_FLOAT32_C(  -902.33), SIMDE_FLOAT32_C(  -922.18) },
          { SIMDE_FLOAT32_C(  -252.73), SIMDE_FLOAT32_C(  -886.48), SIMDE_FLOAT32_C(   -34.27), SIMDE_FLOAT32_C(  -700.42) },
          { SIMDE_FLOAT32_C(   821.80), SIMDE_FLOAT32_C(   364.89), SIMDE_FLOAT32_C(    24.19), SIMDE_FLOAT32_C(   -68.66) },
          { SIMDE_FLOAT32_C(  -121.02), SIMDE_FLOAT32_C(   544.83), SIMDE_FLOAT32_C(  -711.92), SIMDE_FLOAT32_C(   105.17) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -145.58), SIMDE_FLOAT32_C(  -132.39), SIMDE_FLOAT32_C(   -80.87), SIMDE_FLOAT32_C(  -445.43) },
          { SIMDE_FLOAT32_C(   520.58), SIMDE_FLOAT32_C(  -442.44), SIMDE_FLOAT32_C(  -974.19), SIMDE_FLOAT32_C(  -702.31) },
          { SIMDE_FLOAT32_C(  -967.44), SIMDE_FLOAT32_C(  -915.34), SIMDE_FLOAT32_C(  -629.41), SIMDE_FLOAT32_C(  -442.24) },
          { SIMDE_FLOAT32_C(  -376.67), SIMDE_FLOAT32_C(   503.63), SIMDE_FLOAT32_C(  -320.68), SIMDE_FLOAT32_C(    -4.24) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x4_t a = simde_vld4q_f32(test_vec[i].r[0]);
    simde_float32_t r_[4][4];
    simde_vst4q_f32(r_[0], a);
    simde_test_arm_neon_assert_equal_f32x4(simde_vld1q_f32(r_[0]), simde_vld1q_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x4(simde_vld1q_f32(r_[1]), simde_vld1q_f32(test_vec[i].r[1]), 1);
    simde_test_arm_neon_assert_equal_f32x4(simde_vld1q_f32(r_[2]), simde_vld1q_f32(test_vec[i].r[2]), 1);
    simde_test_arm_neon_assert_equal_f32x4(simde_vld1q_f32(r_[3]), simde_vld1q_f32(test_vec[i].r[3]), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4x4_t a = { { simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f), } };
    simde_test_arm_neon_write_f32x4x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[4][2];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(    81.52), SIMDE_FLOAT64_C(   107.86) },
          { SIMDE_FLOAT64_C(   872.05), SIMDE_FLOAT64_C(   704.82) },
          { SIMDE_FLOAT64_C(   134.47), SIMDE_FLOAT64_C(  -575.45) },
          { SIMDE_FLOAT64_C(  -408.51), SIMDE_FLOAT64_C(   228.76) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -606.73), SIMDE_FLOAT64_C(  -858.87) },
          { SIMDE_FLOAT64_C(   369.51), SIMDE_FLOAT64_C(  -773.02) },
          { SIMDE_FLOAT64_C(   320.04), SIMDE_FLOAT64_C(  -123.36) },
          { SIMDE_FLOAT64_C(    73.86), SIMDE_FLOAT64_C(   966.79) } },
    },
    {
        { { SIMDE_FLOAT64_C(    90.88), SIMDE_FLOAT64_C(   -40.80) },
          { SIMDE_FLOAT64_C(   409.84), SIMDE_FLOAT64_C(  -176.92) },
          { SIMDE_FLOAT64_C(  -383.10), SIMDE_FLOAT64_C(   823.54) },
          { SIMDE_FLOAT64_C(   113.53), SIMDE_FLOAT64_C(  -168.25) } },
    },
    {
        { { SIMDE_FLOAT64_C(    31.19), SIMDE_FLOAT64_C(   783.96) },
          { SIMDE_FLOAT64_C(  -573.69), SIMDE_FLOAT64_C(   428.08) },
          { SIMDE_FLOAT64_C(   489.77), SIMDE_FLOAT64_C(   526.13) },
          { SIMDE_FLOAT64_C(  -711.80), SIMDE_FLOAT64_C(  -428.71) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -366.02), SIMDE_FLOAT64_C(  -839.76) },
          { SIMDE_FLOAT64_C(  -723.90), SIMDE_FLOAT64_C(   768.46) },
          { SIMDE_FLOAT64_C(  -415.21), SIMDE_FLOAT64_C(  -132.41) },
          { SIMDE_FLOAT64_C(    -2.78), SIMDE_FLOAT64_C(   -21.94) } },
    },
    {
        { { SIMDE_FLOAT64_C(     8.72), SIMDE_FLOAT64_C(  -633.27) },
          { SIMDE_FLOAT64_C(   205.05), SIMDE_FLOAT64_C(  -671.24) },
          { SIMDE_FLOAT64_C(   243.37), SIMDE_FLOAT64_C(  -721.09) },
          { SIMDE_FLOAT64_C(  -704.45), SIMDE_FLOAT64_C(  -665.75) } },
    },
    {
        { { SIMDE_FLOAT64_C(   238.11), SIMDE_FLOAT64_C(   705.39) },
          { SIMDE_FLOAT64_C(   157.33), SIMDE_FLOAT64_C(   855.01) },
          { SIMDE_FLOAT64_C(   528.93), SIMDE_FLOAT64_C(  -729.14) },
          { SIMDE_FLOAT64_C(  -313.24), SIMDE_FLOAT64_C(  -439.88) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -945.18), SIMDE_FLOAT64_C(   113.07) },
          { SIMDE_FLOAT64_C(   988.21), SIMDE_FLOAT64_C(   544.59) },
          { SIMDE_FLOAT64_C(  -360.81), SIMDE_FLOAT64_C(  -723.60) },
          { SIMDE_FLOAT64_C(  -884.12), SIMDE_FLOAT64_C(   273.17) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x4_t a = simde_vld4q_f64(test_vec[i].r[0]);
    simde_float64_t r_[4][2];
    simde_vst4q_f64(r_[0], a);
    simde_test_arm_neon_assert_equal_f64x2(simde_vld1q_f64(r_[0]), simde_vld1q_f64(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f64x2(simde_vld1q_f64(r_[1]), simde_vld1q_f64(test_vec[i].r[1]), 1);
    simde_test_arm_neon_assert_equal_f64x2(simde_vld1q_f64(r_[2]), simde_vld1q_f64(test_vec[i].r[2]), 1);
    simde_test_arm_neon_assert_equal_f64x2(simde_vld1q_f64(r_[3]), simde_vld1q_f64(test_vec[i].r[3]), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2x4_t a = { { simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x2(-1000.0, 1000.0), } };
    simde_test_arm_neon_write_f64x2x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[4][16];
  } test_vec[] = {
    {
        { { -INT8_C(  34),  INT8_C(  72),  INT8_C( 108), -INT8_C(  22),  INT8_C( 125),  INT8_C(  48),  INT8_C(  94), -INT8_C(  15),
            -INT8_C(   9), -INT8_C(  11),  INT8_C(  22),  INT8_C(  38),  INT8_C(  91), -INT8_C(  90), -INT8_C(  38), -INT8_C(  93) },
          {  INT8_C(  89),  INT8_C(  65),  INT8_C( 109),  INT8_C(  11), -INT8_C(  62), -INT8_C(  87), -INT8_C( 125), -INT8_C(  55),
             INT8_C(  91), -INT8_C(  14), -INT8_C(  68), -INT8_C(   5), -INT8_C(  47),  INT8_C(  44), -INT8_C( 110), -INT8_C(  81) },
          {  INT8_C( 117), -INT8_C(   2), -INT8_C( 103), -INT8_C(  14),  INT8_C(  47), -INT8_C(   9), -INT8_C(  29),  INT8_C(  38),
            -INT8_C(  19), -INT8_C(   7),  INT8_C(  76),  INT8_C(  72), -INT8_C(  97),  INT8_C(  39), -INT8_C(  21), -INT8_C(   7) },
          {  INT8_C( 104),  INT8_C(  89),  INT8_C(   4),  INT8_C(  42),  INT8_C(   2), -INT8_C( 121), -INT8_C(  12),  INT8_C(  94),
             INT8_C( 121), -INT8_C(  80),  INT8_C(  89),  INT8_C(  74), -INT8_C(  36), -INT8_C(  20), -INT8_C(   7),  INT8_C(  81) } },
    },
    {
        { { -INT8_C(  22), -INT8_C( 109),  INT8_C(  67),  INT8_C(  25), -INT8_C( 118),  INT8_C(  38),  INT8_C(  64),  INT8_C( 119),
             INT8_C(  31), -INT8_C( 116), -INT8_C(  65), -INT8_C(  65), -INT8_C(  77), -INT8_C(  85), -INT8_C(  72),  INT8_C(  27) },
          {  INT8_C(   4), -INT8_C(  68),  INT8_C(  70),  INT8_C(   6),  INT8_C(  67),  INT8_C(  58),  INT8_C( 100), -INT8_C(  68),
            -INT8_C(  22), -INT8_C(  66),  INT8_C(   6), -INT8_C(  58), -INT8_C(  86), -INT8_C(   1),  INT8_C(  24), -INT8_C( 108) },
          { -INT8_C( 110),  INT8_C(  91), -INT8_C(  82),  INT8_C(  29), -INT8_C( 126), -INT8_C(  18), -INT8_C( 108), -INT8_C(  95),
             INT8_C( 122),  INT8_C(  84),  INT8_C(  96),  INT8_C(  46), -INT8_C(   1),  INT8_C(  24),  INT8_C(  73),  INT8_C(   3) },
          { -INT8_C(  44), -INT8_C( 113),  INT8_C(   9),  INT8_C(  23), -INT8_C(  55),  INT8_C( 110), -INT8_C(  45), -INT8_C(  77),
             INT8_C(  44), -INT8_C(  39),  INT8_C( 122), -INT8_C(  42), -INT8_C(  39), -INT8_C( 110),  INT8_C( 106),  INT8_C( 107) } },
    },
    {
        { { -INT8_C(  19),  INT8_C(  24), -INT8_C( 120),  INT8_C( 111),  INT8_C(   6),  INT8_C(  29),  INT8_C(  17), -INT8_C( 127),
             INT8_C( 113),  INT8_C( 113), -INT8_C(  81),  INT8_C( 112), -INT8_C( 118), -INT8_C(   8),  INT8_C( 115),  INT8_C(  94) },
          { -INT8_C( 120),  INT8_C( 124),  INT8_C( 118),  INT8_C(  81), -INT8_C(  22),  INT8_C(  73),  INT8_C(   5),  INT8_C(  22),
             INT8_C(  35),      INT8_MAX, -INT8_C(  20), -INT8_C(   4),  INT8_C(  17),  INT8_C(  87),  INT8_C( 103), -INT8_C(   2) },
          {  INT8_C( 111), -INT8_C(  16),  INT8_C( 110),  INT8_C( 118),  INT8_C(  13),      INT8_MAX, -INT8_C(   9),  INT8_C( 126),
            -INT8_C(  16), -INT8_C(  90), -INT8_C(  18),  INT8_C( 122), -INT8_C(  98),  INT8_C(  97), -INT8_C(  39),  INT8_C(  38) },
          { -INT8_C(  35),  INT8_C(  79),  INT8_C( 120), -INT8_C(  56), -INT8_C( 104),  INT8_C( 125), -INT8_C(  34), -INT8_C(  69),
            -INT8_C(   4), -INT8_C(  53), -INT8_C(  73),  INT8_C(  13),  INT8_C(  34),  INT8_C(  31),  INT8_C(  11), -INT8_C( 111) } },
    },
    {
        { {  INT8_C(  15),  INT8_C( 121),  INT8_C(   7),  INT8_C(  28), -INT8_C(   8), -INT8_C(   2), -INT8_C( 102), -INT8_C(  23),
            -INT8_C(  92), -INT8_C( 120),  INT8_C(  99),  INT8_C(  67), -INT8_C(  23),  INT8_C(  60),  INT8_C( 105), -INT8_C(  58) },
          { -INT8_C( 117), -INT8_C(  31), -INT8_C( 114),  INT8_C(  36),  INT8_C(  94),  INT8_C( 109), -INT8_C(  33),  INT8_C(  90),
             INT8_C(  56), -INT8_C( 105),  INT8_C( 103),  INT8_C(  90), -INT8_C(  74),  INT8_C( 115), -INT8_C(  21), -INT8_C(  59) },
          { -INT8_C(  20), -INT8_C(  13), -INT8_C(  31), -INT8_C(  27), -INT8_C(  15),  INT8_C( 123), -INT8_C(  50), -INT8_C( 106),
             INT8_C(   3),  INT8_C(  49), -INT8_C(  39), -INT8_C(  20),  INT8_C( 110),  INT8_C(  66), -INT8_C(  78), -INT8_C(   7) },
          {  INT8_C(  36),  INT8_C(  65),  INT8_C(  29), -INT8_C( 126), -INT8_C(  82), -INT8_C(   3), -INT8_C(  35), -INT8_C(  26),
            -INT8_C( 108),  INT8_C(  68),  INT8_C(  64),  INT8_C(  74), -INT8_C(  73),  INT8_C(  43),  INT8_C(  15), -INT8_C(  92) } },
    },
    {
        { {  INT8_C(  30), -INT8_C(  16), -INT8_C( 119),  INT8_C(  16),  INT8_C( 107),  INT8_C(  87), -INT8_C(  90),  INT8_C( 110),
            -INT8_C( 120),      INT8_MAX,  INT8_C(  90), -INT8_C(  10), -INT8_C(  63),  INT8_C(  12), -INT8_C(  16), -INT8_C(  27) },
          {  INT8_C(  77),  INT8_C(  13),  INT8_C( 104), -INT8_C(   5),  INT8_C(  10),  INT8_C(  69), -INT8_C(  31), -INT8_C(  98),
            -INT8_C( 119),  INT8_C(  33), -INT8_C(  24),  INT8_C(  65),  INT8_C(  77), -INT8_C(   9), -INT8_C(  27),  INT8_C( 107) },
          { -INT8_C(  25),  INT8_C( 110),  INT8_C( 123),  INT8_C(  82), -INT8_C(  59),  INT8_C(  33), -INT8_C(  64),  INT8_C(  77),
            -INT8_C(  96),  INT8_C(  26),  INT8_C(  68),  INT8_C(  98),  INT8_C(  39),  INT8_C(  52),  INT8_C(  71),  INT8_C( 116) },
          {  INT8_C(  65), -INT8_C(  81),  INT8_C( 112),  INT8_C(  76), -INT8_C(  12),  INT8_C(  81), -INT8_C(  22),  INT8_C( 126),
             INT8_C( 115), -INT8_C(  45), -INT8_C(  65), -INT8_C(  64), -INT8_C(  54), -INT8_C(  92),  INT8_C(  43), -INT8_C(  78) } },
    },
    {
        { {  INT8_C(  18), -INT8_C(  89),  INT8_C(   4), -INT8_C(  41), -INT8_C(  56), -INT8_C(  59),  INT8_C(  36),  INT8_C( 105),
            -INT8_C(  33),  INT8_C( 104), -INT8_C(  53),  INT8_C(   6), -INT8_C( 100),  INT8_C(  18),  INT8_C( 123), -INT8_C(  34) },
          { -INT8_C(  62), -INT8_C(  21),  INT8_C(  42), -INT8_C(  74),  INT8_C(  60),  INT8_C(  20),  INT8_C(  52), -INT8_C(  81),
            -INT8_C(  25), -INT8_C(  13),  INT8_C( 111), -INT8_C(  78), -INT8_C( 105), -INT8_C( 101),  INT8_C( 100), -INT8_C(  87) },
          {  INT8_C(  66),  INT8_C( 104),      INT8_MIN,  INT8_C(  10),  INT8_C(  45), -INT8_C(  91),  INT8_C( 115),  INT8_C(  13),
             INT8_C(  13),  INT8_C(  62),  INT8_C(  19), -INT8_C(  86),  INT8_C(  81), -INT8_C( 114), -INT8_C( 120),  INT8_C(  19) },
          {  INT8_C( 121), -INT8_C(  78), -INT8_C(  55), -INT8_C(  74), -INT8_C(  58), -INT8_C(   2),  INT8_C( 101), -INT8_C(  82),
            -INT8_C(  15), -INT8_C(  43),  INT8_C(  96), -INT8_C( 119),  INT8_C( 112), -INT8_C(  60),  INT8_C(  50), -INT8_C(  78) } },
    },
    {
        { {  INT8_C(  44), -INT8_C(  77), -INT8_C(  68),  INT8_C(  90),  INT8_C(  88),  INT8_C(  48),  INT8_C( 103),  INT8_C( 101),
             INT8_C( 110),  INT8_C( 122),  INT8_C(  15), -INT8_C(  65),  INT8_C(   9), -INT8_C( 105), -INT8_C(  46), -INT8_C( 126) },
          {  INT8_C(  73), -INT8_C( 100),  INT8_C(  56),  INT8_C(  16), -INT8_C( 102), -INT8_C(  98), -INT8_C(  66), -INT8_C( 117),
             INT8_C( 115),  INT8_C(  30),  INT8_C(  20), -INT8_C(  29), -INT8_C(  30),  INT8_C(  71), -INT8_C( 107),  INT8_C(  14) },
          { -INT8_C(   6),  INT8_C(  81),  INT8_C( 104),  INT8_C(  82), -INT8_C( 127), -INT8_C(  49), -INT8_C(  73), -INT8_C(  16),
             INT8_C(  74), -INT8_C(  57), -INT8_C(  81),  INT8_C(  83),  INT8_C(  94), -INT8_C( 126), -INT8_C(  43), -INT8_C(  88) },
          {  INT8_C(  30),  INT8_C(  14), -INT8_C(  72), -INT8_C(  72), -INT8_C(  84),  INT8_C( 118),  INT8_C(  67),  INT8_C(  31),
            -INT8_C( 108),  INT8_C(  88),  INT8_C(   2),  INT8_C( 118), -INT8_C(  97), -INT8_C( 105), -INT8_C( 124), -INT8_C( 103) } },
    },
    {
        { { -INT8_C(  24), -INT8_C(  19), -INT8_C(  21),  INT8_C( 106), -INT8_C(  68), -INT8_C(  94),  INT8_C(  90),  INT8_C(   6),
             INT8_C( 105),  INT8_C(   9),  INT8_C(  89), -INT8_C(  56), -INT8_C( 117),  INT8_C(  47),  INT8_C( 112), -INT8_C(  87) },
          {  INT8_C(  61),  INT8_C(  40),  INT8_C(  97), -INT8_C(  23), -INT8_C(  98), -INT8_C(  91),  INT8_C(   8),  INT8_C(  50),
            -INT8_C(   3),  INT8_C(  10), -INT8_C(  88), -INT8_C( 100), -INT8_C(  95),  INT8_C(  44),  INT8_C(  53), -INT8_C( 119) },
          {  INT8_C(  25),  INT8_C(  32), -INT8_C(  13), -INT8_C(  42), -INT8_C(  62),  INT8_C(  77), -INT8_C(  36),  INT8_C(  44),
             INT8_C(  87),  INT8_C(  54), -INT8_C(  12), -INT8_C(  30),  INT8_C( 101),  INT8_C( 100), -INT8_C( 116), -INT8_C(  94) },
          { -INT8_C( 116), -INT8_C(  19), -INT8_C( 117),  INT8_C(  42), -INT8_C( 110), -INT8_C( 109),  INT8_C(  92), -INT8_C( 113),
            -INT8_C(  99),  INT8_C(   4),  INT8_C(  43),  INT8_C(  62),  INT8_C(  48),  INT8_C(  96), -INT8_C(  57),  INT8_C(  74) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x4_t a = simde_vld4q_s8(test_vec[i].r[0]);
    int8_t r_[4][16];
    simde_vst4q_s8(r_[0], a);
    simde_test_arm_neon_assert_equal_i8x16(simde_vld1q_s8(r_[0]), simde_vld1q_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x16(simde_vld1q_s8(r_[1]), simde_vld1q_s8(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i8x16(simde_vld1q_s8(r_[2]), simde_vld1q_s8(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_i8x16(simde_vld1q_s8(r_[3]), simde_vld1q_s8(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x4_t a = { { simde_test_arm_neon_random_i8x16(),
                              simde_test_arm_neon_random_i8x16(),
                              simde_test_arm_neon_random_i8x16(),
                              simde_test_arm_neon_random_i8x16(), } };
    simde_test_arm_neon_write_i8x16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[4][8];
  } test_vec[] = {
    {
        { { -INT16_C( 31882), -INT16_C( 24888), -INT16_C( 32483), -INT16_C( 18734),  INT16_C(  7154),  INT16_C( 15860),  INT16_C( 16768),  INT16_C( 28691) },
          {  INT16_C( 12954),  INT16_C( 19194),  INT16_C( 27020),  INT16_C( 17320),  INT16_C( 10596),  INT16_C( 10490),  INT16_C( 23918), -INT16_C(  6850) },
          {  INT16_C(  1760), -INT16_C(   637),  INT16_C( 21895),  INT16_C( 31156), -INT16_C( 22416), -INT16_C(  3913), -INT16_C( 13591), -INT16_C( 31648) },
          {  INT16_C( 23548), -INT16_C( 30514),  INT16_C( 30404),  INT16_C( 10699), -INT16_C( 14945),  INT16_C(  3409), -INT16_C( 28894),  INT16_C(   754) } },
    },
    {
        { {  INT16_C( 30357),  INT16_C(  7423), -INT16_C( 19509),  INT16_C( 15510),  INT16_C( 19803),  INT16_C( 17708), -INT16_C( 29417),  INT16_C(  5065) },
          { -INT16_C( 26648), -INT16_C( 21349),  INT16_C( 26125), -INT16_C( 21291),  INT16_C( 10027),  INT16_C( 19897), -INT16_C( 21322),  INT16_C( 19535) },
          {  INT16_C( 20002), -INT16_C(  4760), -INT16_C(   510),  INT16_C( 23849),  INT16_C( 22091),  INT16_C( 25250),  INT16_C( 27619), -INT16_C( 13451) },
          {  INT16_C(  4098),  INT16_C(  3959),  INT16_C( 19830), -INT16_C( 24133),  INT16_C( 30068),  INT16_C( 10990),  INT16_C( 15649),  INT16_C( 17270) } },
    },
    {
        { { -INT16_C(  8308), -INT16_C( 29136),  INT16_C( 23261),  INT16_C( 10731), -INT16_C( 29008), -INT16_C( 27765),  INT16_C(   505), -INT16_C(   930) },
          { -INT16_C( 10991), -INT16_C( 30709), -INT16_C( 14558), -INT16_C( 27095),  INT16_C(  6204),  INT16_C( 24001),  INT16_C( 14165), -INT16_C(  7776) },
          { -INT16_C( 12266), -INT16_C(  2961),  INT16_C( 23338), -INT16_C(  9699), -INT16_C( 22295), -INT16_C(  7571), -INT16_C( 13399), -INT16_C( 17442) },
          { -INT16_C(  5471), -INT16_C( 15549),  INT16_C( 27825), -INT16_C(  4774),  INT16_C(  7044), -INT16_C(  9654), -INT16_C(  5550),  INT16_C( 27067) } },
    },
    {
        { {  INT16_C( 11194), -INT16_C(  6819),  INT16_C( 31366),  INT16_C( 28607),  INT16_C( 11554), -INT16_C( 13231),  INT16_C( 12536), -INT16_C( 26233) },
          { -INT16_C( 13798), -INT16_C( 13475), -INT16_C( 18634), -INT16_C( 17480),  INT16_C(   722),  INT16_C(  9365),  INT16_C( 20716), -INT16_C( 22899) },
          { -INT16_C(  5509),  INT16_C(   395),  INT16_C( 19300), -INT16_C( 30864), -INT16_C( 15752),  INT16_C( 28755), -INT16_C(  9486),  INT16_C(  3082) },
          {  INT16_C( 26532), -INT16_C(  9513), -INT16_C( 28898), -INT16_C(  3947),  INT16_C( 10897),  INT16_C( 32020), -INT16_C( 23941), -INT16_C(  2525) } },
    },
    {
        { { -INT16_C( 20596), -INT16_C(  3592),  INT16_C( 26874),  INT16_C( 29304), -INT16_C( 13526),  INT16_C(  7394), -INT16_C(  4955),  INT16_C( 18728) },
          { -INT16_C(   173),  INT16_C( 28963), -INT16_C( 18034),  INT16_C(  8033),  INT16_C( 30435),  INT16_C( 24220), -INT16_C( 16360), -INT16_C( 23467) },
          {  INT16_C( 19823),  INT16_C( 27029),  INT16_C(  3509), -INT16_C(  7973), -INT16_C( 16936),  INT16_C( 32252),  INT16_C(  9642), -INT16_C(   570) },
          { -INT16_C(  5596), -INT16_C( 19601), -INT16_C( 12125), -INT16_C( 31022),  INT16_C( 28486),  INT16_C( 24293),  INT16_C( 14895), -INT16_C( 25085) } },
    },
    {
        { { -INT16_C( 26489),  INT16_C( 15367), -INT16_C(  7514),  INT16_C( 32284),  INT16_C(  6559),  INT16_C( 18940), -INT16_C( 15810),  INT16_C( 25159) },
          { -INT16_C( 18772),  INT16_C( 20245), -INT16_C(  6010), -INT16_C( 12842), -INT16_C( 17577), -INT16_C( 31189),  INT16_C( 12021),  INT16_C( 31780) },
          {  INT16_C( 11207),  INT16_C( 28088), -INT16_C( 10995), -INT16_C( 21269), -INT16_C(  6162),  INT16_C( 11510),  INT16_C( 15786),  INT16_C( 22158) },
          { -INT16_C( 23309),  INT16_C( 31142),  INT16_C( 31884), -INT16_C(  7354),  INT16_C( 29239),  INT16_C( 11369), -INT16_C( 29280),  INT16_C( 26536) } },
    },
    {
        { {  INT16_C( 24760), -INT16_C( 14892), -INT16_C( 16331),  INT16_C(  9073),  INT16_C( 26535),  INT16_C( 20815), -INT16_C(  8540), -INT16_C( 26712) },
          {  INT16_C( 20098),  INT16_C(  3601),  INT16_C( 22474),  INT16_C(   497),  INT16_C( 23241),  INT16_C( 27181), -INT16_C( 10777), -INT16_C( 24623) },
          { -INT16_C( 22987),  INT16_C( 27492), -INT16_C( 10906),  INT16_C(  3470), -INT16_C(  8643), -INT16_C(  7841),  INT16_C(  1980),  INT16_C( 15993) },
          { -INT16_C( 30123),  INT16_C(  8012),  INT16_C( 15841), -INT16_C( 21728),  INT16_C( 19863),  INT16_C( 32277), -INT16_C(  6622),  INT16_C( 22301) } },
    },
    {
        { { -INT16_C( 32372), -INT16_C(  3390),  INT16_C( 20822), -INT16_C( 27904),  INT16_C( 24367), -INT16_C(  5259), -INT16_C(  4506), -INT16_C( 17623) },
          {  INT16_C( 30072),  INT16_C( 23002), -INT16_C(  1358),  INT16_C( 18692),  INT16_C(  6471),  INT16_C( 27079), -INT16_C(  7168), -INT16_C( 29504) },
          { -INT16_C( 31899), -INT16_C( 17537),  INT16_C( 32724),  INT16_C(   847), -INT16_C( 15138),  INT16_C( 17646),  INT16_C(  6066),  INT16_C( 11007) },
          { -INT16_C(  9844),  INT16_C( 16003), -INT16_C( 30509),  INT16_C(  6791),  INT16_C( 20129), -INT16_C( 24189),  INT16_C( 17202), -INT16_C( 26834) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x4_t a = simde_vld4q_s16(test_vec[i].r[0]);
    int16_t r_[4][8];
    simde_vst4q_s16(r_[0], a);
    simde_test_arm_neon_assert_equal_i16x8(simde_vld1q_s16(r_[0]), simde_vld1q_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x8(simde_vld1q_s16(r_[1]), simde_vld1q_s16(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i16x8(simde_vld1q_s16(r_[2]), simde_vld1q_s16(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_i16x8(simde_vld1q_s16(r_[3]), simde_vld1q_s16(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8x4_t a = { { simde_test_arm_neon_random_i16x8(),
                              simde_test_arm_neon_random_i16x8(),
                              simde_test_arm_neon_random_i16x8(),
                              simde_test_arm_neon_random_i16x8(), } };
    simde_test_arm_neon_write_i16x8x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[4][4];
  } test_vec[] = {
    {
        { { -INT32_C(      989676), -INT32_C(   970188658),  INT32_C(   240406759),  INT32_C(  1223255076) },
          {  INT32_C(  1330392774), -INT32_C(   126023316),  INT32_C(  1391418618),  INT32_C(  1167432753) },
          {  INT32_C(   272991618), -INT32_C(  2049478242), -INT32_C(   443274303),  INT32_C(  1445821840) },
          {  INT32_C(   413563307),  INT32_C(  2098209667), -INT32_C(  1328545921),  INT32_C(   519398811) } },
    },
    {
        { { -INT32_C(  2010236182),  INT32_C(  1812858283), -INT32_C(  1051614671), -INT32_C(   887652833) },
          {  INT32_C(  2078522872),  INT32_C(  1610150880), -INT32_C(  1911568398),  INT32_C(   397149484) },
          { -INT32_C(   341845441),  INT32_C(   290958816),  INT32_C(  1876076879),  INT32_C(   523954471) },
          { -INT32_C(  2019943001),  INT32_C(    48730640), -INT32_C(  2037320102),  INT32_C(  1000160507) } },
    },
    {
        { { -INT32_C(   148488937),  INT32_C(   973635050),  INT32_C(  1319754278),  INT32_C(  1785586627) },
          {  INT32_C(   284297216), -INT32_C(   200091238), -INT32_C(   881089585), -INT32_C(   167372577) },
          {  INT32_C(  1089285205), -INT32_C(   797248087), -INT32_C(  1826741297),  INT32_C(   117279494) },
          {  INT32_C(   773255059), -INT32_C(  1742591800), -INT32_C(  1419534901),  INT32_C(   195127734) } },
    },
    {
        { {  INT32_C(  1045139349),  INT32_C(  1410254212), -INT32_C(   286839576),  INT32_C(  1274340536) },
          { -INT32_C(  1669788972), -INT32_C(    30106573), -INT32_C(   274098375), -INT32_C(  1778693376) },
          {  INT32_C(  1590970074), -INT32_C(   189603316), -INT32_C(   941385457),  INT32_C(  1376966526) },
          {  INT32_C(   367955170),  INT32_C(  1628644136), -INT32_C(  1152270918), -INT32_C(   498054136) } },
    },
    {
        { { -INT32_C(  1639963502),  INT32_C(   378794759),  INT32_C(   182285964),  INT32_C(   794619725) },
          { -INT32_C(  1555805317),  INT32_C(   671438958),  INT32_C(   501437973),  INT32_C(   889140386) },
          {  INT32_C(  1607679832), -INT32_C(  1082825166),  INT32_C(   701059804), -INT32_C(  1118230974) },
          { -INT32_C(   547250831),  INT32_C(   168257269),  INT32_C(  1579674556),  INT32_C(  2006066719) } },
    },
    {
        { { -INT32_C(  1730714266), -INT32_C(  1487450933), -INT32_C(   506388065), -INT32_C(  1197594041) },
          { -INT32_C(  1114112057),  INT32_C(   566730341), -INT32_C(  1468010615),  INT32_C(  2065699349) },
          {  INT32_C(  1125447543), -INT32_C(   487953597), -INT32_C(   742147188), -INT32_C(  1383374107) },
          { -INT32_C(   949345695),  INT32_C(  1256731073),  INT32_C(   921921568), -INT32_C(   240053382) } },
    },
    {
        { {  INT32_C(  1295303946), -INT32_C(  1120919759), -INT32_C(  1064176678), -INT32_C(  1217586091) },
          {  INT32_C(     8312639),  INT32_C(   692741640),  INT32_C(  1214201294),  INT32_C(  1513754704) },
          {  INT32_C(   128478934),  INT32_C(  1757730957),  INT32_C(   556291531), -INT32_C(  1311206030) },
          {  INT32_C(  1957779052), -INT32_C(  1952580676), -INT32_C(  1982596039), -INT32_C(   471593715) } },
    },
    {
        { {  INT32_C(   166366332),  INT32_C(   795979364),  INT32_C(  1984993540), -INT32_C(  1708709842) },
          {  INT32_C(   990894206),  INT32_C(   214346963), -INT32_C(  1231644247),  INT32_C(   597260967) },
          {  INT32_C(  1781302022),  INT32_C(   899259953),  INT32_C(  1722542647), -INT32_C(  1862217198) },
          {  INT32_C(  2127302570),  INT32_C(  1703580348), -INT32_C(   769974229), -INT32_C(  1594510182) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x4_t a = simde_vld4q_s32(test_vec[i].r[0]);
    int32_t r_[4][4];
    simde_vst4q_s32(r_[0], a);
    simde_test_arm_neon_assert_equal_i32x4(simde_vld1q_s32(r_[0]), simde_vld1q_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x4(simde_vld1q_s32(r_[1]), simde_vld1q_s32(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i32x4(simde_vld1q_s32(r_[2]), simde_vld1q_s32(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_i32x4(simde_vld1q_s32(r_[3]), simde_vld1q_s32(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4x4_t a = { { simde_test_arm_neon_random_i32x4(),
                              simde_test_arm_neon_random_i32x4(),
                              simde_test_arm_neon_random_i32x4(),
                              simde_test_arm_neon_random_i32x4(), } };
    simde_test_arm_neon_write_i32x4x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[4][2];
  } test_vec[] = {
    {
        { {  INT64_C( 2323480239158856504), -INT64_C( 7268188027562328881) },
          {  INT64_C( 8918025635194903627), -INT64_C( 6371724379595706323) },
          { -INT64_C( 4739617567444809951),  INT64_C( 2312099047740514299) },
          {  INT64_C( 1396580870107935957),  INT64_C( 1814153471798534422) } },
    },
    {
        { { -INT64_C( 1792313988706308494),  INT64_C( 5044164008851158795) },
          { -INT64_C( 6906677354376142036),  INT64_C( 6449248019222543726) },
          {  INT64_C( 2996823526888682178), -INT64_C( 7149454029627983854) },
          { -INT64_C( 1146212828123761428),  INT64_C( 6040407445528264082) } },
    },
    {
        { {  INT64_C( 8921798441361903241), -INT64_C( 3558750931547989616) },
          { -INT64_C( 5608006142463226950), -INT64_C( 2125981215630785895) },
          { -INT64_C( 6309163639219060595), -INT64_C( 1161289663920968142) },
          {  INT64_C( 2117632472918992784),  INT64_C( 1951402852589539289) } },
    },
    {
        { {  INT64_C( 2884699555999358279), -INT64_C( 8785361835340812047) },
          {  INT64_C( 8135641224296480582),  INT64_C( 4383330603330842410) },
          {  INT64_C( 6445676259549439316),  INT64_C( 1571918788469633108) },
          { -INT64_C( 3757754017495709742), -INT64_C( 8707894378774627339) } },
    },
    {
        { { -INT64_C( 4828345439028591811), -INT64_C( 2100130908718334475) },
          {  INT64_C( 8451607785007462877),  INT64_C( 7158902783001808544) },
          {  INT64_C( 7381126499199953739),  INT64_C( 2915805105912247684) },
          { -INT64_C( 8668038506802134338), -INT64_C( 1708918572159789890) } },
    },
    {
        { { -INT64_C( 2470775971157159458), -INT64_C( 6560925629188808321) },
          {  INT64_C( 5123292668241352875),  INT64_C(  301868878507307691) },
          {  INT64_C( 6123217454288325573), -INT64_C(   39107065307829014) },
          { -INT64_C( 7315628175381145432), -INT64_C( 2430235049214171875) } },
    },
    {
        { { -INT64_C( 8212605687520584995), -INT64_C( 2470555122214755230) },
          {  INT64_C( 1131960355242526507), -INT64_C( 8708949397329570004) },
          {  INT64_C( 8602790175723626290), -INT64_C( 4506164145478057371) },
          {  INT64_C( 4119826140852094251),  INT64_C( 5141318664229649704) } },
    },
    {
        { {  INT64_C( 4129098084982297537), -INT64_C( 8531707347363268030) },
          {  INT64_C( 3248170678849270990), -INT64_C(  744122856350182833) },
          { -INT64_C( 8288566929857459732), -INT64_C( 2127391082581537902) },
          {  INT64_C( 4730135244160442226), -INT64_C( 1762223588667645086) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x4_t a = simde_vld4q_s64(test_vec[i].r[0]);
    int64_t r_[4][2];
    simde_vst4q_s64(r_[0], a);
    simde_test_arm_neon_assert_equal_i64x2(simde_vld1q_s64(r_[0]), simde_vld1q_s64(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i64x2(simde_vld1q_s64(r_[1]), simde_vld1q_s64(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i64x2(simde_vld1q_s64(r_[2]), simde_vld1q_s64(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_i64x2(simde_vld1q_s64(r_[3]), simde_vld1q_s64(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2x4_t a = { { simde_test_arm_neon_random_i64x2(),
                              simde_test_arm_neon_random_i64x2(),
                              simde_test_arm_neon_random_i64x2(),
                              simde_test_arm_neon_random_i64x2(), } };
    simde_test_arm_neon_write_i64x2x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[4][16];
  } test_vec[] = {
    {
        { { UINT8_C(199), UINT8_C(113), UINT8_C(214), UINT8_C( 27), UINT8_C( 68), UINT8_C(167), UINT8_C(138), UINT8_C( 27),
            UINT8_C( 60), UINT8_C( 59), UINT8_C( 74), UINT8_C( 83), UINT8_C(253), UINT8_C(193), UINT8_C( 38), UINT8_C(188) },
          { UINT8_C(119), UINT8_C( 78), UINT8_C(188), UINT8_C(233), UINT8_C(199), UINT8_C(125), UINT8_C( 34), UINT8_C( 63),
            UINT8_C(178), UINT8_C( 87), UINT8_C( 31), UINT8_C( 74), UINT8_C( 68), UINT8_C(229), UINT8_C(173), UINT8_C( 11) },
          { UINT8_C( 86), UINT8_C(131), UINT8_C( 38), UINT8_C(154), UINT8_C( 42), UINT8_C(177), UINT8_C(182), UINT8_C(102),
            UINT8_C(236), UINT8_C(  0), UINT8_C(186), UINT8_C(234), UINT8_C(193), UINT8_C(224), UINT8_C(166), UINT8_C( 57) },
          { UINT8_C( 47), UINT8_C( 99), UINT8_C( 34), UINT8_C(246), UINT8_C(224), UINT8_C( 68), UINT8_C( 53), UINT8_C(146),
            UINT8_C(156), UINT8_C( 84), UINT8_C(221), UINT8_C(224), UINT8_C( 58), UINT8_C(138), UINT8_C(235), UINT8_C(144) } },
    },
    {
        { { UINT8_C( 13), UINT8_C( 18), UINT8_C( 43), UINT8_C( 55), UINT8_C(195), UINT8_C(225), UINT8_C(158), UINT8_C(175),
            UINT8_C(225), UINT8_C( 88), UINT8_C(153), UINT8_C(162), UINT8_C( 56), UINT8_C( 64), UINT8_C(219), UINT8_C(103) },
          { UINT8_C(163), UINT8_C(253), UINT8_C( 94), UINT8_C(131), UINT8_C( 66), UINT8_C(147), UINT8_C( 22), UINT8_C(222),
            UINT8_C(232), UINT8_C(243), UINT8_C(190), UINT8_C( 34), UINT8_C(125), UINT8_C(169), UINT8_C(178), UINT8_C(138) },
          { UINT8_C(187), UINT8_C(221), UINT8_C(193), UINT8_C(126), UINT8_C(190), UINT8_C( 95), UINT8_C( 46), UINT8_C(159),
            UINT8_C(183), UINT8_C(199), UINT8_C( 66), UINT8_C(240), UINT8_C(  7), UINT8_C( 29), UINT8_C( 87), UINT8_C(170) },
          { UINT8_C( 27), UINT8_C(181), UINT8_C( 46), UINT8_C( 93), UINT8_C( 73), UINT8_C( 68), UINT8_C( 59), UINT8_C( 49),
            UINT8_C( 55), UINT8_C(249), UINT8_C( 83), UINT8_C(180), UINT8_C(162), UINT8_C(  5), UINT8_C( 62), UINT8_C( 94) } },
    },
    {
        { { UINT8_C(227),    UINT8_MAX, UINT8_C(220), UINT8_C(161), UINT8_C( 95), UINT8_C( 10), UINT8_C( 65), UINT8_C( 22),
            UINT8_C(210), UINT8_C(131), UINT8_C(  6), UINT8_C(217), UINT8_C(160), UINT8_C( 94), UINT8_C(132), UINT8_C(187) },
          { UINT8_C( 19), UINT8_C(178), UINT8_C( 24), UINT8_C( 92), UINT8_C(246), UINT8_C( 83), UINT8_C(141), UINT8_C( 45),
            UINT8_C( 76), UINT8_C(224), UINT8_C(225), UINT8_C(239), UINT8_C(230), UINT8_C( 31), UINT8_C( 77), UINT8_C(201) },
          { UINT8_C( 30), UINT8_C( 41), UINT8_C(106), UINT8_C(125), UINT8_C( 52), UINT8_C(171), UINT8_C(148), UINT8_C(  6),
            UINT8_C( 46), UINT8_C(154), UINT8_C(223), UINT8_C(207), UINT8_C(248), UINT8_C( 99), UINT8_C(138), UINT8_C( 12) },
          { UINT8_C( 21), UINT8_C(163), UINT8_C(104), UINT8_C( 11), UINT8_C(246), UINT8_C(246), UINT8_C( 56), UINT8_C( 67),
            UINT8_C(214), UINT8_C( 25), UINT8_C( 50), UINT8_C(188), UINT8_C( 56), UINT8_C(127), UINT8_C(133), UINT8_C( 87) } },
    },
    {
        { { UINT8_C(168), UINT8_C(240), UINT8_C(212), UINT8_C(220), UINT8_C(155), UINT8_C(104), UINT8_C(226), UINT8_C(202),
            UINT8_C(  3), UINT8_C(194), UINT8_C(153), UINT8_C(251), UINT8_C( 37), UINT8_C( 35), UINT8_C(  7), UINT8_C( 59) },
          { UINT8_C(198), UINT8_C(112), UINT8_C( 70), UINT8_C(189), UINT8_C(102), UINT8_C(127), UINT8_C(  0), UINT8_C( 60),
            UINT8_C(152), UINT8_C( 50), UINT8_C(249), UINT8_C(209), UINT8_C(177), UINT8_C(126), UINT8_C( 40), UINT8_C( 89) },
          { UINT8_C(110), UINT8_C(252), UINT8_C( 54), UINT8_C( 10), UINT8_C(101), UINT8_C( 24), UINT8_C(212), UINT8_C(104),
            UINT8_C(218), UINT8_C(109), UINT8_C( 99), UINT8_C(  0), UINT8_C(144), UINT8_C(107), UINT8_C( 59), UINT8_C( 87) },
          { UINT8_C(219), UINT8_C(129), UINT8_C( 20), UINT8_C( 65), UINT8_C(  0), UINT8_C( 20), UINT8_C(125), UINT8_C(153),
            UINT8_C( 70), UINT8_C(118), UINT8_C(106), UINT8_C(247), UINT8_C(245), UINT8_C(146), UINT8_C( 80), UINT8_C( 99) } },
    },
    {
        { { UINT8_C(142), UINT8_C(134), UINT8_C(109), UINT8_C(243), UINT8_C(159), UINT8_C( 65), UINT8_C( 91), UINT8_C(121),
            UINT8_C(174), UINT8_C(191), UINT8_C(121), UINT8_C( 63), UINT8_C( 42), UINT8_C(180), UINT8_C(150), UINT8_C(  5) },
          { UINT8_C( 54), UINT8_C(170), UINT8_C( 70), UINT8_C( 54), UINT8_C(190), UINT8_C(195), UINT8_C(207), UINT8_C(  4),
            UINT8_C( 58), UINT8_C( 57), UINT8_C(251), UINT8_C( 47), UINT8_C(203), UINT8_C( 75), UINT8_C(146), UINT8_C( 90) },
          { UINT8_C(210), UINT8_C(  0), UINT8_C( 77), UINT8_C(113), UINT8_C( 65), UINT8_C(169), UINT8_C(234), UINT8_C(240),
            UINT8_C(104), UINT8_C(100), UINT8_C( 47), UINT8_C(146), UINT8_C( 24), UINT8_C(197), UINT8_C(151), UINT8_C( 78) },
          { UINT8_C(111), UINT8_C(221), UINT8_C(133), UINT8_C( 45), UINT8_C(160), UINT8_C( 84), UINT8_C( 49), UINT8_C(218),
            UINT8_C(142), UINT8_C( 44), UINT8_C(  9), UINT8_C( 89), UINT8_C(119), UINT8_C(156), UINT8_C(179), UINT8_C( 73) } },
    },
    {
        { { UINT8_C(156), UINT8_C(  1), UINT8_C(186), UINT8_C(221), UINT8_C(170), UINT8_C(165), UINT8_C(205), UINT8_C( 18),
            UINT8_C(  9), UINT8_C(252), UINT8_C(164), UINT8_C( 33), UINT8_C(193), UINT8_C( 59), UINT8_C(112), UINT8_C( 48) },
          { UINT8_C( 24), UINT8_C(245), UINT8_C( 93), UINT8_C(184), UINT8_C( 73), UINT8_C(142), UINT8_C(147), UINT8_C(215),
            UINT8_C(186), UINT8_C(156), UINT8_C( 49), UINT8_C( 50), UINT8_C( 56), UINT8_C(228), UINT8_C(123), UINT8_C(212) },
          { UINT8_C(229), UINT8_C( 54), UINT8_C(178), UINT8_C(143), UINT8_C(219), UINT8_C(127), UINT8_C(161), UINT8_C(228),
            UINT8_C(124), UINT8_C( 69), UINT8_C(  5), UINT8_C( 61), UINT8_C(128), UINT8_C(117), UINT8_C(110), UINT8_C(152) },
          { UINT8_C(106), UINT8_C(203), UINT8_C( 81), UINT8_C(180), UINT8_C( 90), UINT8_C(228), UINT8_C(139), UINT8_C( 20),
            UINT8_C(128), UINT8_C(188), UINT8_C( 70), UINT8_C(185), UINT8_C(161), UINT8_C(194), UINT8_C(141), UINT8_C(134) } },
    },
    {
        { { UINT8_C(248), UINT8_C( 63), UINT8_C( 22), UINT8_C(211), UINT8_C(191), UINT8_C(183), UINT8_C(183), UINT8_C( 59),
            UINT8_C(253), UINT8_C(188), UINT8_C(120), UINT8_C(125), UINT8_C( 50), UINT8_C(230), UINT8_C( 22), UINT8_C(156) },
          { UINT8_C(178), UINT8_C(103), UINT8_C( 80), UINT8_C( 12), UINT8_C( 75), UINT8_C(220), UINT8_C( 32), UINT8_C(203),
            UINT8_C(152), UINT8_C(103), UINT8_C(132), UINT8_C( 57), UINT8_C( 41), UINT8_C( 18), UINT8_C(192), UINT8_C( 33) },
          { UINT8_C( 81), UINT8_C(214), UINT8_C(244), UINT8_C( 16), UINT8_C(141), UINT8_C(171), UINT8_C( 75), UINT8_C(138),
            UINT8_C(103), UINT8_C(196), UINT8_C(  8), UINT8_C(153), UINT8_C(170), UINT8_C( 30), UINT8_C( 54), UINT8_C( 92) },
          { UINT8_C(133), UINT8_C(134), UINT8_C(104), UINT8_C(208), UINT8_C( 98), UINT8_C(137), UINT8_C(155), UINT8_C(251),
            UINT8_C(240), UINT8_C( 32), UINT8_C( 52), UINT8_C( 25), UINT8_C( 50), UINT8_C(244), UINT8_C( 58), UINT8_C(131) } },
    },
    {
        { { UINT8_C(202), UINT8_C( 46), UINT8_C(148), UINT8_C( 88), UINT8_C(217), UINT8_C(223), UINT8_C(226), UINT8_C( 64),
            UINT8_C(163), UINT8_C(234), UINT8_C(218), UINT8_C( 78), UINT8_C(  8), UINT8_C( 16), UINT8_C(170), UINT8_C(141) },
          { UINT8_C(150), UINT8_C( 19), UINT8_C( 93), UINT8_C(249), UINT8_C(156), UINT8_C(249), UINT8_C(244), UINT8_C(140),
            UINT8_C( 25), UINT8_C( 40), UINT8_C(165), UINT8_C( 75), UINT8_C( 29), UINT8_C(223), UINT8_C(206), UINT8_C(231) },
          { UINT8_C( 13), UINT8_C( 98), UINT8_C( 63), UINT8_C(230), UINT8_C( 66), UINT8_C( 34), UINT8_C( 38), UINT8_C(229),
            UINT8_C( 12), UINT8_C(  0), UINT8_C( 51), UINT8_C( 21), UINT8_C( 16), UINT8_C(222), UINT8_C(162), UINT8_C(167) },
          { UINT8_C(241), UINT8_C(  0), UINT8_C(160), UINT8_C(141), UINT8_C(249), UINT8_C(148), UINT8_C( 25), UINT8_C( 18),
            UINT8_C(188), UINT8_C(190), UINT8_C( 93), UINT8_C(217), UINT8_C(157), UINT8_C( 43), UINT8_C(193), UINT8_C(170) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x4_t a = simde_vld4q_u8(test_vec[i].r[0]);
    uint8_t r_[4][16];
    simde_vst4q_u8(r_[0], a);
    simde_test_arm_neon_assert_equal_u8x16(simde_vld1q_u8(r_[0]), simde_vld1q_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x16(simde_vld1q_u8(r_[1]), simde_vld1q_u8(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u8x16(simde_vld1q_u8(r_[2]), simde_vld1q_u8(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_u8x16(simde_vld1q_u8(r_[3]), simde_vld1q_u8(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x4_t a = { { simde_test_arm_neon_random_u8x16(),
                               simde_test_arm_neon_random_u8x16(),
                               simde_test_arm_neon_random_u8x16(),
                               simde_test_arm_neon_random_u8x16(), } };
    simde_test_arm_neon_write_u8x16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[4][8];
  } test_vec[] = {
    {
        { { UINT16_C(41941), UINT16_C(52209), UINT16_C(19769), UINT16_C(16936), UINT16_C(35654), UINT16_C(  522), UINT16_C( 2384), UINT16_C(57624) },
          { UINT16_C(62850), UINT16_C(24249), UINT16_C(59668), UINT16_C(34009), UINT16_C(24544), UINT16_C(43839), UINT16_C(29309), UINT16_C(21046) },
          { UINT16_C(10006), UINT16_C(20254), UINT16_C(18037), UINT16_C(48017), UINT16_C(39889), UINT16_C( 8637), UINT16_C(54692), UINT16_C( 9731) },
          { UINT16_C(48331), UINT16_C(57220), UINT16_C(23974), UINT16_C(34403), UINT16_C(41916), UINT16_C(14897), UINT16_C(26389), UINT16_C(11148) } },
    },
    {
        { { UINT16_C(43663), UINT16_C( 1146), UINT16_C( 3056), UINT16_C(49599), UINT16_C(32167), UINT16_C(19427), UINT16_C(58962), UINT16_C( 7538) },
          { UINT16_C(63138), UINT16_C(18684), UINT16_C(24660), UINT16_C( 4303), UINT16_C(    3), UINT16_C( 6218), UINT16_C(55144), UINT16_C(63300) },
          { UINT16_C(48769), UINT16_C(29435), UINT16_C(47818), UINT16_C(28979), UINT16_C( 5687), UINT16_C(35516), UINT16_C(12028), UINT16_C(40871) },
          { UINT16_C(42021), UINT16_C(31207), UINT16_C(46596), UINT16_C( 1929), UINT16_C(54455), UINT16_C( 7967), UINT16_C(25515), UINT16_C(11286) } },
    },
    {
        { { UINT16_C( 4386), UINT16_C(60574), UINT16_C(53963), UINT16_C(  861), UINT16_C( 6632), UINT16_C(58765), UINT16_C(13384), UINT16_C(28036) },
          { UINT16_C(27608), UINT16_C(56550), UINT16_C(28450), UINT16_C(55779), UINT16_C(  835), UINT16_C(61176), UINT16_C( 3686), UINT16_C(34843) },
          { UINT16_C(47391), UINT16_C(60020), UINT16_C(53643), UINT16_C(29933), UINT16_C(31467), UINT16_C(13145), UINT16_C(56751), UINT16_C(34720) },
          { UINT16_C(34376), UINT16_C(27236), UINT16_C(18421), UINT16_C(14659), UINT16_C(15178), UINT16_C(45351), UINT16_C(16969), UINT16_C(26681) } },
    },
    {
        { { UINT16_C(44796), UINT16_C(34643), UINT16_C(16511), UINT16_C(27387), UINT16_C(21691), UINT16_C(27293), UINT16_C(15665), UINT16_C(31473) },
          { UINT16_C(21955), UINT16_C(47588), UINT16_C(10397), UINT16_C(59378), UINT16_C( 6499), UINT16_C(44440), UINT16_C(53852), UINT16_C(22549) },
          { UINT16_C(26752), UINT16_C(65503), UINT16_C(56233), UINT16_C(25706), UINT16_C( 1839), UINT16_C(25038), UINT16_C(48965), UINT16_C( 2267) },
          { UINT16_C(48917), UINT16_C(45761), UINT16_C(46055), UINT16_C(19353), UINT16_C(13005), UINT16_C(10744), UINT16_C( 3332), UINT16_C(33921) } },
    },
    {
        { { UINT16_C(24694), UINT16_C( 8067), UINT16_C(60731), UINT16_C(27523), UINT16_C(20981), UINT16_C(15052), UINT16_C(42768), UINT16_C( 9538) },
          { UINT16_C( 1126), UINT16_C(20183), UINT16_C(29111), UINT16_C(33945), UINT16_C(37283), UINT16_C(42925), UINT16_C(11934), UINT16_C( 5163) },
          { UINT16_C(44687), UINT16_C(51763), UINT16_C(46748), UINT16_C(37173), UINT16_C(  263), UINT16_C( 6347), UINT16_C( 3496), UINT16_C( 3901) },
          { UINT16_C( 5393), UINT16_C(51549), UINT16_C(63110), UINT16_C(10573), UINT16_C(64391), UINT16_C( 9680), UINT16_C(64297), UINT16_C(47162) } },
    },
    {
        { { UINT16_C(28073), UINT16_C(17795), UINT16_C(47140), UINT16_C(11222), UINT16_C(41402), UINT16_C(25155), UINT16_C(33199), UINT16_C(49265) },
          { UINT16_C(52886), UINT16_C( 7305), UINT16_C(55236), UINT16_C(19269), UINT16_C( 5586), UINT16_C(64369), UINT16_C(43792), UINT16_C(47540) },
          { UINT16_C(14104), UINT16_C(15615), UINT16_C(54767), UINT16_C(43368), UINT16_C(43895), UINT16_C( 9740), UINT16_C(32044), UINT16_C(49894) },
          { UINT16_C(28748), UINT16_C( 4318), UINT16_C( 9031), UINT16_C( 6492), UINT16_C(52536), UINT16_C(18452), UINT16_C(51320), UINT16_C(36866) } },
    },
    {
        { { UINT16_C(  511), UINT16_C(61389), UINT16_C(13782), UINT16_C(19864), UINT16_C(42208), UINT16_C( 3443), UINT16_C(23074), UINT16_C(28367) },
          { UINT16_C(44746), UINT16_C( 4478), UINT16_C(56017), UINT16_C( 2602), UINT16_C(16039), UINT16_C( 8018), UINT16_C(21511), UINT16_C( 1712) },
          { UINT16_C(32085), UINT16_C(11509), UINT16_C(36530), UINT16_C(37497), UINT16_C(60722), UINT16_C(21663), UINT16_C(28487), UINT16_C( 4546) },
          { UINT16_C(16669), UINT16_C(60962), UINT16_C(19483), UINT16_C(50168), UINT16_C(19338), UINT16_C(37346), UINT16_C(37535), UINT16_C(62872) } },
    },
    {
        { { UINT16_C(36111), UINT16_C(49441), UINT16_C(39451), UINT16_C(20052), UINT16_C(62343), UINT16_C(52898), UINT16_C(25954), UINT16_C(32735) },
          { UINT16_C(  422), UINT16_C(49518), UINT16_C(26189), UINT16_C(55428), UINT16_C(26545), UINT16_C(20841), UINT16_C(  505), UINT16_C( 2374) },
          { UINT16_C(26511), UINT16_C(43722), UINT16_C( 7681), UINT16_C(35320), UINT16_C(39698), UINT16_C(29783), UINT16_C(14080), UINT16_C(42740) },
          { UINT16_C(25144), UINT16_C(34407), UINT16_C(60616), UINT16_C(31326), UINT16_C(51027), UINT16_C(19659), UINT16_C( 4553), UINT16_C(22613) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x4_t a = simde_vld4q_u16(test_vec[i].r[0]);
    uint16_t r_[4][8];
    simde_vst4q_u16(r_[0], a);
    simde_test_arm_neon_assert_equal_u16x8(simde_vld1q_u16(r_[0]), simde_vld1q_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x8(simde_vld1q_u16(r_[1]), simde_vld1q_u16(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u16x8(simde_vld1q_u16(r_[2]), simde_vld1q_u16(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_u16x8(simde_vld1q_u16(r_[3]), simde_vld1q_u16(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8x4_t a = { { simde_test_arm_neon_random_u16x8(),
                               simde_test_arm_neon_random_u16x8(),
                               simde_test_arm_neon_random_u16x8(),
                               simde_test_arm_neon_random_u16x8(), } };
    simde_test_arm_neon_write_u16x8x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[4][4];
  } test_vec[] = {
    {
        { { UINT32_C(3728940657), UINT32_C(2883927187), UINT32_C(1509623776), UINT32_C(2421118004) },
          { UINT32_C(2408628464), UINT32_C(1163029108), UINT32_C(3888084798), UINT32_C(1031637707) },
          { UINT32_C(1008451753), UINT32_C(3722903804), UINT32_C(1010230024), UINT32_C( 667715127) },
          { UINT32_C(3132513350), UINT32_C(  83823046), UINT32_C(1290518400), UINT32_C(4069091401) } },
    },
    {
        { { UINT32_C( 623813672), UINT32_C(2885818020), UINT32_C( 820525305), UINT32_C(  72922302) },
          { UINT32_C(3602845200), UINT32_C(2564472343), UINT32_C(3353659005), UINT32_C(1471769902) },
          { UINT32_C(3044861969), UINT32_C(4150427390), UINT32_C(1965509302), UINT32_C( 259620863) },
          { UINT32_C(2783328398), UINT32_C(1950204151), UINT32_C(3040551302), UINT32_C(2668426638) } },
    },
    {
        { { UINT32_C(3679815901), UINT32_C(3167926022), UINT32_C(   3275009), UINT32_C( 118532985) },
          { UINT32_C(3668768483), UINT32_C(1028647606), UINT32_C(2599586315), UINT32_C(1547304575) },
          { UINT32_C(2352451206), UINT32_C(1195903301), UINT32_C(2085059075), UINT32_C( 142825253) },
          { UINT32_C(  81997645), UINT32_C( 625029657), UINT32_C(1019163580), UINT32_C(3080255537) } },
    },
    {
        { { UINT32_C(3426996359), UINT32_C(3692268505), UINT32_C( 710433541), UINT32_C(   3398578) },
          { UINT32_C( 604247563), UINT32_C(  71910728), UINT32_C(2839545976), UINT32_C(2288048385) },
          { UINT32_C(2186585001), UINT32_C( 878667822), UINT32_C(1969141699), UINT32_C(2658505107) },
          { UINT32_C(4022499751), UINT32_C( 921963710), UINT32_C( 366949396), UINT32_C(3063758605) } },
    },
    {
        { { UINT32_C( 289010402), UINT32_C( 491100250), UINT32_C(3801260879), UINT32_C(3699378229) },
          { UINT32_C(1087128449), UINT32_C(1668726863), UINT32_C(  41506548), UINT32_C(2025330325) },
          { UINT32_C(1653207304), UINT32_C(3649031817), UINT32_C(2797277809), UINT32_C(2609069082) },
          { UINT32_C(3470479231), UINT32_C(  53563919), UINT32_C(1023781544), UINT32_C(3384131265) } },
    },
    {
        { { UINT32_C( 959200943), UINT32_C(2115152652), UINT32_C(3609513405), UINT32_C(2289280777) },
          { UINT32_C(  89542390), UINT32_C(1208584352), UINT32_C(4085648946), UINT32_C(2092776396) },
          { UINT32_C(2260068730), UINT32_C(1376044948), UINT32_C(2653497748), UINT32_C(3341196496) },
          { UINT32_C(2345434603), UINT32_C( 936695045), UINT32_C(2955631332), UINT32_C( 254601365) } },
    },
    {
        { { UINT32_C(1704387025), UINT32_C(1035442856), UINT32_C(2497438147), UINT32_C(1750794621) },
          { UINT32_C(2213816190), UINT32_C(3787180285), UINT32_C(3079792162), UINT32_C(2680667854) },
          { UINT32_C(1208245663), UINT32_C(3146104055), UINT32_C( 441409693), UINT32_C(3766725217) },
          { UINT32_C(3462625233), UINT32_C(1638866495), UINT32_C(3524804868), UINT32_C(2658263039) } },
    },
    {
        { { UINT32_C( 887518780), UINT32_C(3488574258), UINT32_C( 770260683), UINT32_C(3104664808) },
          { UINT32_C( 579367139), UINT32_C(2474850191), UINT32_C(2003213432), UINT32_C(3088504699) },
          { UINT32_C(2146237517), UINT32_C( 860805992), UINT32_C(  23083033), UINT32_C(2293919140) },
          { UINT32_C(1839874782), UINT32_C(4060098170), UINT32_C(1164601034), UINT32_C(2348646462) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x4_t a = simde_vld4q_u32(test_vec[i].r[0]);
    uint32_t r_[4][4];
    simde_vst4q_u32(r_[0], a);
    simde_test_arm_neon_assert_equal_u32x4(simde_vld1q_u32(r_[0]), simde_vld1q_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x4(simde_vld1q_u32(r_[1]), simde_vld1q_u32(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u32x4(simde_vld1q_u32(r_[2]), simde_vld1q_u32(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_u32x4(simde_vld1q_u32(r_[3]), simde_vld1q_u32(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4x4_t a = { { simde_test_arm_neon_random_u32x4(),
                               simde_test_arm_neon_random_u32x4(),
                               simde_test_arm_neon_random_u32x4(),
                               simde_test_arm_neon_random_u32x4(), } };
    simde_test_arm_neon_write_u32x4x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[4][2];
  } test_vec[] = {
    {
        { { UINT64_C(17994282767602999463), UINT64_C( 5900124874337722814) },
          { UINT64_C(16276046153218596126), UINT64_C(14492302271717940355) },
          { UINT64_C( 5670138105515411424), UINT64_C(11214615616490047489) },
          { UINT64_C(13550620140279240558), UINT64_C( 4756029227251229206) } },
    },
    {
        { { UINT64_C(  699651170678450390), UINT64_C(16558043089518339505) },
          { UINT64_C(17368446265642213907), UINT64_C( 6783874077295229056) },
          { UINT64_C( 8710658528546922193), UINT64_C( 5546868177732254878) },
          { UINT64_C(12150326040775363281), UINT64_C(13997099620296738650) } },
    },
    {
        { { UINT64_C( 2021410885588485325), UINT64_C(17599833302191158203) },
          { UINT64_C(15205630606892455989), UINT64_C(  989653098730721287) },
          { UINT64_C(10417581119902930936), UINT64_C( 2556289692719170402) },
          { UINT64_C( 7127094136074738587), UINT64_C( 9971838817698290966) } },
    },
    {
        { { UINT64_C( 1572761993486533741), UINT64_C(13143495041028347733) },
          { UINT64_C( 9650285388887746606), UINT64_C(14586383341098583889) },
          { UINT64_C( 6200013032233135682), UINT64_C(16575217745203405878) },
          { UINT64_C(15482351346760340200), UINT64_C( 4020069550614230947) } },
    },
    {
        { { UINT64_C(17071800069804381845), UINT64_C( 7960750631839172060) },
          { UINT64_C(16821684882832222742), UINT64_C(16754713684095872088) },
          { UINT64_C(14207847374977347978), UINT64_C(14258910641444711150) },
          { UINT64_C(11524380798457325246), UINT64_C( 1529659866651351039) } },
    },
    {
        { { UINT64_C( 1139552684648806434), UINT64_C(13501621248261761515) },
          { UINT64_C(10660492641222770698), UINT64_C( 8152958224382156421) },
          { UINT64_C(16647641767192918744), UINT64_C(17955817554110941815) },
          { UINT64_C( 2433699290213510816), UINT64_C(11879183878057995290) } },
    },
    {
        { { UINT64_C( 2067897310420752592), UINT64_C(12904993346091496239) },
          { UINT64_C(13360963614897824430), UINT64_C(14036028930123799641) },
          { UINT64_C( 4257942392911259221), UINT64_C( 1529658613400447091) },
          { UINT64_C( 2894067227854578130), UINT64_C(11464501405206596710) } },
    },
    {
        { { UINT64_C( 6612605765185874046), UINT64_C( 6905739573299649881) },
          { UINT64_C( 7437405613276018238), UINT64_C( 1814628061543367749) },
          { UINT64_C(15259716683592616066), UINT64_C(  248378324111632517) },
          { UINT64_C( 9297759752137294496), UINT64_C( 2558113451269474251) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x4_t a = simde_vld4q_u64(test_vec[i].r[0]);
    uint64_t r_[4][2];
    simde_vst4q_u64(r_[0], a);
    simde_test_arm_neon_assert_equal_u64x2(simde_vld1q_u64(r_[0]), simde_vld1q_u64(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u64x2(simde_vld1q_u64(r_[1]), simde_vld1q_u64(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u64x2(simde_vld1q_u64(r_[2]), simde_vld1q_u64(test_vec[i].r[2]));
    simde_test_arm_neon_assert_equal_u64x2(simde_vld1q_u64(r_[3]), simde_vld1q_u64(test_vec[i].r[3]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2x4_t a = { { simde_test_arm_neon_random_u64x2(),
                               simde_test_arm_neon_random_u64x2(),
                               simde_test_arm_neon_random_u64x2(),
                               simde_test_arm_neon_random_u64x2(), } };
    simde_test_arm_neon_write_u64x2x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
