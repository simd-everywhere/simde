#define SIMDE_TEST_ARM_NEON_INSN uzp

#include "test-neon.h"
#include <simde/arm/neon/uzp.h>

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vuzp_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float16_t r[2][4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE( 59.585), SIMDE_FLOAT16_VALUE( - 87.027), SIMDE_FLOAT16_VALUE( - 74.361), SIMDE_FLOAT16_VALUE( - 30.649) },
      {  SIMDE_FLOAT16_VALUE( 93.073), SIMDE_FLOAT16_VALUE( - 31.922),  SIMDE_FLOAT16_VALUE( 17.320), SIMDE_FLOAT16_VALUE( - 55.446) },
    { {  SIMDE_FLOAT16_VALUE( 59.585), SIMDE_FLOAT16_VALUE( - 74.361),  SIMDE_FLOAT16_VALUE( 93.073),  SIMDE_FLOAT16_VALUE( 17.320)  },
      { SIMDE_FLOAT16_VALUE( - 87.027), SIMDE_FLOAT16_VALUE( - 30.649), SIMDE_FLOAT16_VALUE( - 31.922), SIMDE_FLOAT16_VALUE( - 55.446)  } } },
    { {  SIMDE_FLOAT16_VALUE(  9.958),  SIMDE_FLOAT16_VALUE( 85.170), SIMDE_FLOAT16_VALUE( - 72.074), SIMDE_FLOAT16_VALUE( - 27.806) },
      {  SIMDE_FLOAT16_VALUE( 78.386),  SIMDE_FLOAT16_VALUE(  6.905),  SIMDE_FLOAT16_VALUE( 69.743),  SIMDE_FLOAT16_VALUE( 45.300) },
    { {  SIMDE_FLOAT16_VALUE(  9.958), SIMDE_FLOAT16_VALUE( - 72.074),  SIMDE_FLOAT16_VALUE( 78.386),  SIMDE_FLOAT16_VALUE( 69.743)  },
      {  SIMDE_FLOAT16_VALUE( 85.170), SIMDE_FLOAT16_VALUE( - 27.806),  SIMDE_FLOAT16_VALUE(  6.905),  SIMDE_FLOAT16_VALUE( 45.300)  } } },
    { { SIMDE_FLOAT16_VALUE( - 69.822), SIMDE_FLOAT16_VALUE( - 45.174), SIMDE_FLOAT16_VALUE( - 30.230), SIMDE_FLOAT16_VALUE( - 86.717) },
      {  SIMDE_FLOAT16_VALUE( 40.263),  SIMDE_FLOAT16_VALUE( 89.268),  SIMDE_FLOAT16_VALUE( 94.905),  SIMDE_FLOAT16_VALUE( 59.037) },
    { { SIMDE_FLOAT16_VALUE( - 69.822), SIMDE_FLOAT16_VALUE( - 30.230),  SIMDE_FLOAT16_VALUE( 40.263),  SIMDE_FLOAT16_VALUE( 94.905)  },
      { SIMDE_FLOAT16_VALUE( - 45.174), SIMDE_FLOAT16_VALUE( - 86.717),  SIMDE_FLOAT16_VALUE( 89.268),  SIMDE_FLOAT16_VALUE( 59.037)  } } },
    { {  SIMDE_FLOAT16_VALUE(  0.579),  SIMDE_FLOAT16_VALUE( 53.168), SIMDE_FLOAT16_VALUE( - 49.281), SIMDE_FLOAT16_VALUE( -  2.295) },
      {  SIMDE_FLOAT16_VALUE( 64.385),  SIMDE_FLOAT16_VALUE( 51.685),  SIMDE_FLOAT16_VALUE( 44.562),  SIMDE_FLOAT16_VALUE(  6.481) },
    { {  SIMDE_FLOAT16_VALUE(  0.579), SIMDE_FLOAT16_VALUE( - 49.281),  SIMDE_FLOAT16_VALUE( 64.385),  SIMDE_FLOAT16_VALUE( 44.562)  },
      {  SIMDE_FLOAT16_VALUE( 53.168), SIMDE_FLOAT16_VALUE( -  2.295),  SIMDE_FLOAT16_VALUE( 51.685),  SIMDE_FLOAT16_VALUE(  6.481)  } } },
    { { SIMDE_FLOAT16_VALUE( - 86.361), SIMDE_FLOAT16_VALUE( - 69.966),  SIMDE_FLOAT16_VALUE( 26.111),  SIMDE_FLOAT16_VALUE(  5.103) },
      { SIMDE_FLOAT16_VALUE( - 54.134), SIMDE_FLOAT16_VALUE( - 87.125),  SIMDE_FLOAT16_VALUE( 29.118), SIMDE_FLOAT16_VALUE( -  4.129) },
    { { SIMDE_FLOAT16_VALUE( - 86.361),  SIMDE_FLOAT16_VALUE( 26.111), SIMDE_FLOAT16_VALUE( - 54.134),  SIMDE_FLOAT16_VALUE( 29.118)  },
      { SIMDE_FLOAT16_VALUE( - 69.966),  SIMDE_FLOAT16_VALUE(  5.103), SIMDE_FLOAT16_VALUE( - 87.125), SIMDE_FLOAT16_VALUE( -  4.129)  } } },
    { {  SIMDE_FLOAT16_VALUE( 88.320),  SIMDE_FLOAT16_VALUE( 36.543),  SIMDE_FLOAT16_VALUE( 16.274),  SIMDE_FLOAT16_VALUE( 89.586) },
      { SIMDE_FLOAT16_VALUE( - 43.919), SIMDE_FLOAT16_VALUE( - 42.540),  SIMDE_FLOAT16_VALUE( 43.983),  SIMDE_FLOAT16_VALUE( 48.582) },
    { {  SIMDE_FLOAT16_VALUE( 88.320),  SIMDE_FLOAT16_VALUE( 16.274), SIMDE_FLOAT16_VALUE( - 43.919),  SIMDE_FLOAT16_VALUE( 43.983)  },
      {  SIMDE_FLOAT16_VALUE( 36.543),  SIMDE_FLOAT16_VALUE( 89.586), SIMDE_FLOAT16_VALUE( - 42.540),  SIMDE_FLOAT16_VALUE( 48.582)  } } },
    { {  SIMDE_FLOAT16_VALUE( 41.012),  SIMDE_FLOAT16_VALUE( 97.838),  SIMDE_FLOAT16_VALUE( 17.977),  SIMDE_FLOAT16_VALUE(  3.700) },
      { SIMDE_FLOAT16_VALUE( -  3.857), SIMDE_FLOAT16_VALUE( - 64.852), SIMDE_FLOAT16_VALUE( - 33.562),  SIMDE_FLOAT16_VALUE( 17.944) },
    { {  SIMDE_FLOAT16_VALUE( 41.012),  SIMDE_FLOAT16_VALUE( 17.977), SIMDE_FLOAT16_VALUE( -  3.857), SIMDE_FLOAT16_VALUE( - 33.562)  },
      {  SIMDE_FLOAT16_VALUE( 97.838),  SIMDE_FLOAT16_VALUE(  3.700), SIMDE_FLOAT16_VALUE( - 64.852),  SIMDE_FLOAT16_VALUE( 17.944)  } } },
    { { SIMDE_FLOAT16_VALUE( - 74.409), SIMDE_FLOAT16_VALUE( -  5.545), SIMDE_FLOAT16_VALUE( - 17.427), SIMDE_FLOAT16_VALUE( - 74.159) },
      { SIMDE_FLOAT16_VALUE( - 93.810),  SIMDE_FLOAT16_VALUE( 50.112),  SIMDE_FLOAT16_VALUE( 65.086),  SIMDE_FLOAT16_VALUE( 63.782) },
    { { SIMDE_FLOAT16_VALUE( - 74.409), SIMDE_FLOAT16_VALUE( - 17.427), SIMDE_FLOAT16_VALUE( - 93.810),  SIMDE_FLOAT16_VALUE( 65.086)  },
      { SIMDE_FLOAT16_VALUE( -  5.545), SIMDE_FLOAT16_VALUE( - 74.159),  SIMDE_FLOAT16_VALUE( 50.112),  SIMDE_FLOAT16_VALUE( 63.782)  } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4x2_t r = simde_vuzp_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r.val[0], simde_vld1_f16(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f16x4(r.val[1], simde_vld1_f16(test_vec[i].r[1]), 1);
  }

  return 0;

#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4x2_t c = simde_vuzp_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2][2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   929.29), SIMDE_FLOAT32_C(   951.10) },
      { SIMDE_FLOAT32_C(   363.77), SIMDE_FLOAT32_C(   789.61) },
      {
          { SIMDE_FLOAT32_C(   929.29), SIMDE_FLOAT32_C(   363.77) },
          { SIMDE_FLOAT32_C(   951.10), SIMDE_FLOAT32_C(   789.61) },
      },
    },
    { { SIMDE_FLOAT32_C(  -759.57), SIMDE_FLOAT32_C(   685.98) },
      { SIMDE_FLOAT32_C(   841.21), SIMDE_FLOAT32_C(   515.20) },
      {
          { SIMDE_FLOAT32_C(  -759.57), SIMDE_FLOAT32_C(   841.21) },
          { SIMDE_FLOAT32_C(   685.98), SIMDE_FLOAT32_C(   515.20) },
      },
    },
    { { SIMDE_FLOAT32_C(    69.74), SIMDE_FLOAT32_C(  -338.66) },
      { SIMDE_FLOAT32_C(   456.03), SIMDE_FLOAT32_C(  -463.79) },
      {
          { SIMDE_FLOAT32_C(    69.74), SIMDE_FLOAT32_C(   456.03) },
          { SIMDE_FLOAT32_C(  -338.66), SIMDE_FLOAT32_C(  -463.79) },
      },
    },
    { { SIMDE_FLOAT32_C(  -878.94), SIMDE_FLOAT32_C(   168.02) },
      { SIMDE_FLOAT32_C(  -767.09), SIMDE_FLOAT32_C(   264.02) },
      {
          { SIMDE_FLOAT32_C(  -878.94), SIMDE_FLOAT32_C(  -767.09) },
          { SIMDE_FLOAT32_C(   168.02), SIMDE_FLOAT32_C(   264.02) },
      },
    },
    { { SIMDE_FLOAT32_C(  -711.03), SIMDE_FLOAT32_C(   572.52) },
      { SIMDE_FLOAT32_C(   131.81), SIMDE_FLOAT32_C(  -844.24) },
      {
          { SIMDE_FLOAT32_C(  -711.03), SIMDE_FLOAT32_C(   131.81) },
          { SIMDE_FLOAT32_C(   572.52), SIMDE_FLOAT32_C(  -844.24) },
      },
    },
    { { SIMDE_FLOAT32_C(  -898.82), SIMDE_FLOAT32_C(  -685.93) },
      { SIMDE_FLOAT32_C(  -963.34), SIMDE_FLOAT32_C(  -684.35) },
      {
          { SIMDE_FLOAT32_C(  -898.82), SIMDE_FLOAT32_C(  -963.34) },
          { SIMDE_FLOAT32_C(  -685.93), SIMDE_FLOAT32_C(  -684.35) },
      },
    },
    { { SIMDE_FLOAT32_C(  -332.36), SIMDE_FLOAT32_C(   141.67) },
      { SIMDE_FLOAT32_C(  -308.83), SIMDE_FLOAT32_C(   753.40) },
      {
          { SIMDE_FLOAT32_C(  -332.36), SIMDE_FLOAT32_C(  -308.83) },
          { SIMDE_FLOAT32_C(   141.67), SIMDE_FLOAT32_C(   753.40) },
      },
    },
    { { SIMDE_FLOAT32_C(   573.65), SIMDE_FLOAT32_C(  -669.39) },
      { SIMDE_FLOAT32_C(   323.27), SIMDE_FLOAT32_C(   502.94) },
      {
          { SIMDE_FLOAT32_C(   573.65), SIMDE_FLOAT32_C(   323.27) },
          { SIMDE_FLOAT32_C(  -669.39), SIMDE_FLOAT32_C(   502.94) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2x2_t r = simde_vuzp_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], simde_vld1_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], simde_vld1_f32(test_vec[i].r[1]), 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2x2_t c = simde_vuzp_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[2][8];
  } test_vec[] = {
    { { -INT8_C(  16), -INT8_C(  95),  INT8_C( 126),  INT8_C( 101), -INT8_C( 104), -INT8_C(  55), -INT8_C(  25), -INT8_C(  95) },
      { -INT8_C(  93),  INT8_C(  64),  INT8_C( 101),  INT8_C(  61),  INT8_C(  13), -INT8_C(  69), -INT8_C(  19), -INT8_C(   4) },
      {
          { -INT8_C(  16),  INT8_C( 126), -INT8_C( 104), -INT8_C(  25), -INT8_C(  93),  INT8_C( 101),  INT8_C(  13), -INT8_C(  19) },
          { -INT8_C(  95),  INT8_C( 101), -INT8_C(  55), -INT8_C(  95),  INT8_C(  64),  INT8_C(  61), -INT8_C(  69), -INT8_C(   4) },
      },
    },
    { { -INT8_C(   2),  INT8_C( 116),  INT8_C(  70),  INT8_C(  52),  INT8_C( 122), -INT8_C(  58),  INT8_C(  86),  INT8_C(   8) },
      {  INT8_C(  13), -INT8_C(  26), -INT8_C(  56), -INT8_C( 121),  INT8_C(  18), -INT8_C(  54), -INT8_C( 106),  INT8_C(   2) },
      {
          { -INT8_C(   2),  INT8_C(  70),  INT8_C( 122),  INT8_C(  86),  INT8_C(  13), -INT8_C(  56),  INT8_C(  18), -INT8_C( 106) },
          {  INT8_C( 116),  INT8_C(  52), -INT8_C(  58),  INT8_C(   8), -INT8_C(  26), -INT8_C( 121), -INT8_C(  54),  INT8_C(   2) },
      },
    },
    { {  INT8_C( 107),  INT8_C(  20),  INT8_C( 104),  INT8_C(   4), -INT8_C(  35),  INT8_C(  79), -INT8_C(  91),      INT8_MIN },
      { -INT8_C( 113),  INT8_C(  10), -INT8_C(  67), -INT8_C( 100), -INT8_C(  59), -INT8_C(  86), -INT8_C( 104), -INT8_C(  61) },
      {
          {  INT8_C( 107),  INT8_C( 104), -INT8_C(  35), -INT8_C(  91), -INT8_C( 113), -INT8_C(  67), -INT8_C(  59), -INT8_C( 104) },
          {  INT8_C(  20),  INT8_C(   4),  INT8_C(  79),      INT8_MIN,  INT8_C(  10), -INT8_C( 100), -INT8_C(  86), -INT8_C(  61) },
      },
    },
    { {  INT8_C(  30), -INT8_C(  33), -INT8_C(   8), -INT8_C( 104), -INT8_C(  91),  INT8_C(  78), -INT8_C(  96), -INT8_C(  78) },
      {  INT8_C(  52),  INT8_C( 105),  INT8_C(  58),  INT8_C(  70),  INT8_C(  51), -INT8_C(  48),  INT8_C(  72), -INT8_C(  98) },
      {
          {  INT8_C(  30), -INT8_C(   8), -INT8_C(  91), -INT8_C(  96),  INT8_C(  52),  INT8_C(  58),  INT8_C(  51),  INT8_C(  72) },
          { -INT8_C(  33), -INT8_C( 104),  INT8_C(  78), -INT8_C(  78),  INT8_C( 105),  INT8_C(  70), -INT8_C(  48), -INT8_C(  98) },
      },
    },
    { { -INT8_C(  28), -INT8_C(  80), -INT8_C(  94), -INT8_C(  62), -INT8_C(   1),  INT8_C(  71),  INT8_C(  66), -INT8_C( 114) },
      {  INT8_C(  81),  INT8_C(   0),  INT8_C(  43),  INT8_C(  23), -INT8_C(  86), -INT8_C(  61), -INT8_C(  38), -INT8_C(  55) },
      {
          { -INT8_C(  28), -INT8_C(  94), -INT8_C(   1),  INT8_C(  66),  INT8_C(  81),  INT8_C(  43), -INT8_C(  86), -INT8_C(  38) },
          { -INT8_C(  80), -INT8_C(  62),  INT8_C(  71), -INT8_C( 114),  INT8_C(   0),  INT8_C(  23), -INT8_C(  61), -INT8_C(  55) },
      },
    },
    { { -INT8_C(  94), -INT8_C(  46),  INT8_C(  97),  INT8_C(  71),  INT8_C(  32),  INT8_C(   2), -INT8_C(   6),  INT8_C(  84) },
      {  INT8_C( 107),  INT8_C(  52), -INT8_C( 102), -INT8_C(  98),  INT8_C(   4), -INT8_C(  29),  INT8_C(  60), -INT8_C(  24) },
      {
          { -INT8_C(  94),  INT8_C(  97),  INT8_C(  32), -INT8_C(   6),  INT8_C( 107), -INT8_C( 102),  INT8_C(   4),  INT8_C(  60) },
          { -INT8_C(  46),  INT8_C(  71),  INT8_C(   2),  INT8_C(  84),  INT8_C(  52), -INT8_C(  98), -INT8_C(  29), -INT8_C(  24) },
      },
    },
    { { -INT8_C( 109), -INT8_C(  33), -INT8_C(  86), -INT8_C( 109),  INT8_C(  38), -INT8_C(  19),  INT8_C(  33),  INT8_C( 120) },
      { -INT8_C(  19),  INT8_C(  76), -INT8_C( 113), -INT8_C( 105),  INT8_C(  16),  INT8_C( 105),  INT8_C(  96), -INT8_C(  78) },
      {
          { -INT8_C( 109), -INT8_C(  86),  INT8_C(  38),  INT8_C(  33), -INT8_C(  19), -INT8_C( 113),  INT8_C(  16),  INT8_C(  96) },
          { -INT8_C(  33), -INT8_C( 109), -INT8_C(  19),  INT8_C( 120),  INT8_C(  76), -INT8_C( 105),  INT8_C( 105), -INT8_C(  78) },
      },
    },
    { {  INT8_C(  60), -INT8_C(  62), -INT8_C(   6),  INT8_C(  92), -INT8_C(  60), -INT8_C(  12), -INT8_C(  79),  INT8_C(  47) },
      {  INT8_C(  40),  INT8_C(  75), -INT8_C(  51),  INT8_C(  44),  INT8_C(  46),  INT8_C(   9),  INT8_C(  20), -INT8_C(  62) },
      {
          {  INT8_C(  60), -INT8_C(   6), -INT8_C(  60), -INT8_C(  79),  INT8_C(  40), -INT8_C(  51),  INT8_C(  46),  INT8_C(  20) },
          { -INT8_C(  62),  INT8_C(  92), -INT8_C(  12),  INT8_C(  47),  INT8_C(  75),  INT8_C(  44),  INT8_C(   9), -INT8_C(  62) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8x2_t r = simde_vuzp_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], simde_vld1_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], simde_vld1_s8(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8x2_t c = simde_vuzp_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[2][4];
  } test_vec[] = {
    { { -INT16_C( 28880), -INT16_C( 22644),  INT16_C(  8023),  INT16_C( 26036) },
      { -INT16_C( 28471), -INT16_C( 15106),  INT16_C( 18561),  INT16_C( 11767) },
      {
          { -INT16_C( 28880),  INT16_C(  8023), -INT16_C( 28471),  INT16_C( 18561) },
          { -INT16_C( 22644),  INT16_C( 26036), -INT16_C( 15106),  INT16_C( 11767) },
      },
    },
    { {  INT16_C( 13251),  INT16_C( 27928),  INT16_C(  6580), -INT16_C(  9190) },
      {  INT16_C( 31504), -INT16_C( 17767), -INT16_C( 13685), -INT16_C( 17646) },
      {
          {  INT16_C( 13251),  INT16_C(  6580),  INT16_C( 31504), -INT16_C( 13685) },
          {  INT16_C( 27928), -INT16_C(  9190), -INT16_C( 17767), -INT16_C( 17646) },
      },
    },
    { { -INT16_C( 24999), -INT16_C( 20382),  INT16_C(  5822), -INT16_C( 30955) },
      {  INT16_C(  5031),  INT16_C( 10315),  INT16_C( 16988),  INT16_C(  8021) },
      {
          { -INT16_C( 24999),  INT16_C(  5822),  INT16_C(  5031),  INT16_C( 16988) },
          { -INT16_C( 20382), -INT16_C( 30955),  INT16_C( 10315),  INT16_C(  8021) },
      },
    },
    { {  INT16_C( 28021),  INT16_C( 10637), -INT16_C( 22650), -INT16_C( 27130) },
      { -INT16_C( 24798), -INT16_C( 21167),  INT16_C( 25449), -INT16_C( 15767) },
      {
          {  INT16_C( 28021), -INT16_C( 22650), -INT16_C( 24798),  INT16_C( 25449) },
          {  INT16_C( 10637), -INT16_C( 27130), -INT16_C( 21167), -INT16_C( 15767) },
      },
    },
    { { -INT16_C( 13567), -INT16_C( 16525), -INT16_C( 30494), -INT16_C( 30394) },
      { -INT16_C( 28260), -INT16_C(  1871),  INT16_C(  1747),  INT16_C( 18711) },
      {
          { -INT16_C( 13567), -INT16_C( 30494), -INT16_C( 28260),  INT16_C(  1747) },
          { -INT16_C( 16525), -INT16_C( 30394), -INT16_C(  1871),  INT16_C( 18711) },
      },
    },
    { { -INT16_C( 23436), -INT16_C(  1422),  INT16_C( 30795),  INT16_C( 28305) },
      { -INT16_C(  7657), -INT16_C( 32741), -INT16_C( 31675),  INT16_C( 17987) },
      {
          { -INT16_C( 23436),  INT16_C( 30795), -INT16_C(  7657), -INT16_C( 31675) },
          { -INT16_C(  1422),  INT16_C( 28305), -INT16_C( 32741),  INT16_C( 17987) },
      },
    },
    { { -INT16_C( 18864),  INT16_C( 12806),  INT16_C( 19518), -INT16_C(  9541) },
      {  INT16_C( 27870), -INT16_C( 20014), -INT16_C(  5518), -INT16_C(  6406) },
      {
          { -INT16_C( 18864),  INT16_C( 19518),  INT16_C( 27870), -INT16_C(  5518) },
          {  INT16_C( 12806), -INT16_C(  9541), -INT16_C( 20014), -INT16_C(  6406) },
      },
    },
    { {  INT16_C( 28046), -INT16_C(  9503),  INT16_C( 29413), -INT16_C(   696) },
      {  INT16_C( 25428), -INT16_C( 26243), -INT16_C( 16152),  INT16_C( 14559) },
      {
          {  INT16_C( 28046),  INT16_C( 29413),  INT16_C( 25428), -INT16_C( 16152) },
          { -INT16_C(  9503), -INT16_C(   696), -INT16_C( 26243),  INT16_C( 14559) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4x2_t r = simde_vuzp_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], simde_vld1_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], simde_vld1_s16(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4x2_t c = simde_vuzp_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2][2];
  } test_vec[] = {
    { {  INT32_C(  1801551691), -INT32_C(  2123910970) },
      { -INT32_C(   406438839),  INT32_C(  1744642352) },
      {
          {  INT32_C(  1801551691), -INT32_C(   406438839) },
          { -INT32_C(  2123910970),  INT32_C(  1744642352) },
      },
    },
    { {  INT32_C(  1736006795), -INT32_C(   571974838) },
      { -INT32_C(  1018486927),  INT32_C(   227361474) },
      {
          {  INT32_C(  1736006795), -INT32_C(  1018486927) },
          { -INT32_C(   571974838),  INT32_C(   227361474) },
      },
    },
    { { -INT32_C(  2022117695), -INT32_C(   402071650) },
      {  INT32_C(  1288687388),  INT32_C(  2075380976) },
      {
          { -INT32_C(  2022117695),  INT32_C(  1288687388) },
          { -INT32_C(   402071650),  INT32_C(  2075380976) },
      },
    },
    { {  INT32_C(  1927490600), -INT32_C(   112145529) },
      { -INT32_C(  1396925462), -INT32_C(  1615246882) },
      {
          {  INT32_C(  1927490600), -INT32_C(  1396925462) },
          { -INT32_C(   112145529), -INT32_C(  1615246882) },
      },
    },
    { { -INT32_C(   702074313),  INT32_C(   767438609) },
      { -INT32_C(   293958146), -INT32_C(  2106970791) },
      {
          { -INT32_C(   702074313), -INT32_C(   293958146) },
          {  INT32_C(   767438609), -INT32_C(  2106970791) },
      },
    },
    { { -INT32_C(   504083110),  INT32_C(    47858712) },
      { -INT32_C(  1095854112),  INT32_C(   408774624) },
      {
          { -INT32_C(   504083110), -INT32_C(  1095854112) },
          {  INT32_C(    47858712),  INT32_C(   408774624) },
      },
    },
    { { -INT32_C(  1410431847), -INT32_C(  1294422860) },
      { -INT32_C(  1834921415), -INT32_C(   636220544) },
      {
          { -INT32_C(  1410431847), -INT32_C(  1834921415) },
          { -INT32_C(  1294422860), -INT32_C(   636220544) },
      },
    },
    { {  INT32_C(  1891305816),  INT32_C(   762484301) },
      {  INT32_C(   233513005),  INT32_C(   556091783) },
      {
          {  INT32_C(  1891305816),  INT32_C(   233513005) },
          {  INT32_C(   762484301),  INT32_C(   556091783) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2x2_t r = simde_vuzp_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], simde_vld1_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], simde_vld1_s32(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2x2_t c = simde_vuzp_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[2][8];
  } test_vec[] = {
    { { UINT8_C(221), UINT8_C(128), UINT8_C(185), UINT8_C(185), UINT8_C( 80), UINT8_C(201), UINT8_C( 16), UINT8_C(240) },
      { UINT8_C(182), UINT8_C(179), UINT8_C(131), UINT8_C(144), UINT8_C( 26), UINT8_C(213), UINT8_C( 46), UINT8_C(116) },
      {
          { UINT8_C(221), UINT8_C(185), UINT8_C( 80), UINT8_C( 16), UINT8_C(182), UINT8_C(131), UINT8_C( 26), UINT8_C( 46) },
          { UINT8_C(128), UINT8_C(185), UINT8_C(201), UINT8_C(240), UINT8_C(179), UINT8_C(144), UINT8_C(213), UINT8_C(116) },
      },
    },
    { { UINT8_C(128), UINT8_C(109), UINT8_C(182), UINT8_C( 21), UINT8_C(134), UINT8_C( 17), UINT8_C(237), UINT8_C(242) },
      { UINT8_C(198), UINT8_C(216), UINT8_C(134), UINT8_C(196), UINT8_C( 59), UINT8_C(141), UINT8_C(156), UINT8_C( 24) },
      {
          { UINT8_C(128), UINT8_C(182), UINT8_C(134), UINT8_C(237), UINT8_C(198), UINT8_C(134), UINT8_C( 59), UINT8_C(156) },
          { UINT8_C(109), UINT8_C( 21), UINT8_C( 17), UINT8_C(242), UINT8_C(216), UINT8_C(196), UINT8_C(141), UINT8_C( 24) },
      },
    },
    { { UINT8_C( 14), UINT8_C( 85), UINT8_C(209), UINT8_C( 94), UINT8_C( 31), UINT8_C(225), UINT8_C( 78), UINT8_C(213) },
      { UINT8_C(148), UINT8_C(210), UINT8_C(101), UINT8_C(174), UINT8_C(167), UINT8_C(148), UINT8_C( 34), UINT8_C( 39) },
      {
          { UINT8_C( 14), UINT8_C(209), UINT8_C( 31), UINT8_C( 78), UINT8_C(148), UINT8_C(101), UINT8_C(167), UINT8_C( 34) },
          { UINT8_C( 85), UINT8_C( 94), UINT8_C(225), UINT8_C(213), UINT8_C(210), UINT8_C(174), UINT8_C(148), UINT8_C( 39) },
      },
    },
    { { UINT8_C(  1), UINT8_C(217), UINT8_C( 60), UINT8_C(135), UINT8_C(234), UINT8_C( 42), UINT8_C(121), UINT8_C(176) },
      { UINT8_C(  2), UINT8_C(  0), UINT8_C(116), UINT8_C( 62), UINT8_C(141), UINT8_C( 16), UINT8_C( 86), UINT8_C(155) },
      {
          { UINT8_C(  1), UINT8_C( 60), UINT8_C(234), UINT8_C(121), UINT8_C(  2), UINT8_C(116), UINT8_C(141), UINT8_C( 86) },
          { UINT8_C(217), UINT8_C(135), UINT8_C( 42), UINT8_C(176), UINT8_C(  0), UINT8_C( 62), UINT8_C( 16), UINT8_C(155) },
      },
    },
    { { UINT8_C(102), UINT8_C( 40), UINT8_C(249), UINT8_C(133), UINT8_C(  9), UINT8_C( 72), UINT8_C( 90), UINT8_C(158) },
      { UINT8_C( 26), UINT8_C(192), UINT8_C( 76), UINT8_C(193), UINT8_C( 84), UINT8_C(111), UINT8_C(232), UINT8_C( 85) },
      {
          { UINT8_C(102), UINT8_C(249), UINT8_C(  9), UINT8_C( 90), UINT8_C( 26), UINT8_C( 76), UINT8_C( 84), UINT8_C(232) },
          { UINT8_C( 40), UINT8_C(133), UINT8_C( 72), UINT8_C(158), UINT8_C(192), UINT8_C(193), UINT8_C(111), UINT8_C( 85) },
      },
    },
    { { UINT8_C( 72), UINT8_C( 37), UINT8_C(220), UINT8_C( 50), UINT8_C( 79), UINT8_C( 86), UINT8_C(226), UINT8_C( 81) },
      { UINT8_C( 86), UINT8_C( 86), UINT8_C(143), UINT8_C(227), UINT8_C(103), UINT8_C(230), UINT8_C(127), UINT8_C(205) },
      {
          { UINT8_C( 72), UINT8_C(220), UINT8_C( 79), UINT8_C(226), UINT8_C( 86), UINT8_C(143), UINT8_C(103), UINT8_C(127) },
          { UINT8_C( 37), UINT8_C( 50), UINT8_C( 86), UINT8_C( 81), UINT8_C( 86), UINT8_C(227), UINT8_C(230), UINT8_C(205) },
      },
    },
    { { UINT8_C( 14), UINT8_C(120), UINT8_C( 82), UINT8_C( 23), UINT8_C(192), UINT8_C(172), UINT8_C(181), UINT8_C(218) },
      { UINT8_C(108), UINT8_C(  2), UINT8_C(155), UINT8_C(192), UINT8_C(113), UINT8_C(132), UINT8_C( 21), UINT8_C(185) },
      {
          { UINT8_C( 14), UINT8_C( 82), UINT8_C(192), UINT8_C(181), UINT8_C(108), UINT8_C(155), UINT8_C(113), UINT8_C( 21) },
          { UINT8_C(120), UINT8_C( 23), UINT8_C(172), UINT8_C(218), UINT8_C(  2), UINT8_C(192), UINT8_C(132), UINT8_C(185) },
      },
    },
    { { UINT8_C(169), UINT8_C(242), UINT8_C(235), UINT8_C(248), UINT8_C( 72), UINT8_C(205), UINT8_C( 73), UINT8_C(158) },
      { UINT8_C( 35), UINT8_C(217), UINT8_C(129), UINT8_C(138), UINT8_C(191), UINT8_C(  0), UINT8_C( 87), UINT8_C(205) },
      {
          { UINT8_C(169), UINT8_C(235), UINT8_C( 72), UINT8_C( 73), UINT8_C( 35), UINT8_C(129), UINT8_C(191), UINT8_C( 87) },
          { UINT8_C(242), UINT8_C(248), UINT8_C(205), UINT8_C(158), UINT8_C(217), UINT8_C(138), UINT8_C(  0), UINT8_C(205) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8x2_t r = simde_vuzp_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], simde_vld1_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], simde_vld1_u8(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x2_t c = simde_vuzp_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[2][4];
  } test_vec[] = {
    { { UINT16_C(53183), UINT16_C( 8344), UINT16_C(47465), UINT16_C(51179) },
      { UINT16_C(23788), UINT16_C( 1786), UINT16_C(23927), UINT16_C(30761) },
      {
          { UINT16_C(53183), UINT16_C(47465), UINT16_C(23788), UINT16_C(23927) },
          { UINT16_C( 8344), UINT16_C(51179), UINT16_C( 1786), UINT16_C(30761) },
      },
    },
    { { UINT16_C(50756), UINT16_C(22956), UINT16_C( 7637), UINT16_C(43027) },
      { UINT16_C(20916), UINT16_C(48634), UINT16_C(  346), UINT16_C( 6692) },
      {
          { UINT16_C(50756), UINT16_C( 7637), UINT16_C(20916), UINT16_C(  346) },
          { UINT16_C(22956), UINT16_C(43027), UINT16_C(48634), UINT16_C( 6692) },
      },
    },
    { { UINT16_C(48336), UINT16_C(14650), UINT16_C( 9590), UINT16_C(25089) },
      { UINT16_C(64386), UINT16_C(63848), UINT16_C(37209), UINT16_C(40306) },
      {
          { UINT16_C(48336), UINT16_C( 9590), UINT16_C(64386), UINT16_C(37209) },
          { UINT16_C(14650), UINT16_C(25089), UINT16_C(63848), UINT16_C(40306) },
      },
    },
    { { UINT16_C( 7768), UINT16_C(11767), UINT16_C( 2619), UINT16_C(61397) },
      { UINT16_C(53340), UINT16_C(46765), UINT16_C(53713), UINT16_C(41424) },
      {
          { UINT16_C( 7768), UINT16_C( 2619), UINT16_C(53340), UINT16_C(53713) },
          { UINT16_C(11767), UINT16_C(61397), UINT16_C(46765), UINT16_C(41424) },
      },
    },
    { { UINT16_C( 2701), UINT16_C(  986), UINT16_C(56112), UINT16_C(45669) },
      { UINT16_C(52951), UINT16_C(12459), UINT16_C( 7519), UINT16_C(47053) },
      {
          { UINT16_C( 2701), UINT16_C(56112), UINT16_C(52951), UINT16_C( 7519) },
          { UINT16_C(  986), UINT16_C(45669), UINT16_C(12459), UINT16_C(47053) },
      },
    },
    { { UINT16_C(50235), UINT16_C(30692), UINT16_C(47823), UINT16_C(11110) },
      { UINT16_C( 5002), UINT16_C(23521), UINT16_C(45796), UINT16_C(29436) },
      {
          { UINT16_C(50235), UINT16_C(47823), UINT16_C( 5002), UINT16_C(45796) },
          { UINT16_C(30692), UINT16_C(11110), UINT16_C(23521), UINT16_C(29436) },
      },
    },
    { { UINT16_C(54972), UINT16_C(60533), UINT16_C(56242), UINT16_C(35230) },
      { UINT16_C(19113), UINT16_C( 2233), UINT16_C(34407), UINT16_C(41920) },
      {
          { UINT16_C(54972), UINT16_C(56242), UINT16_C(19113), UINT16_C(34407) },
          { UINT16_C(60533), UINT16_C(35230), UINT16_C( 2233), UINT16_C(41920) },
      },
    },
    { { UINT16_C(42059), UINT16_C( 6682), UINT16_C(32862), UINT16_C(59461) },
      { UINT16_C( 9876), UINT16_C(30787), UINT16_C(16344), UINT16_C(38378) },
      {
          { UINT16_C(42059), UINT16_C(32862), UINT16_C( 9876), UINT16_C(16344) },
          { UINT16_C( 6682), UINT16_C(59461), UINT16_C(30787), UINT16_C(38378) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4x2_t r = simde_vuzp_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r.val[0], simde_vld1_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], simde_vld1_u16(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4x2_t c = simde_vuzp_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2][2];
  } test_vec[] = {
    { { UINT32_C(4244796768), UINT32_C(1520735748) },
      { UINT32_C(1408214781), UINT32_C( 807312678) },
      {
          { UINT32_C(4244796768), UINT32_C(1408214781) },
          { UINT32_C(1520735748), UINT32_C( 807312678) },
      },
    },
    { { UINT32_C(2360753501), UINT32_C(2681976087) },
      { UINT32_C( 762530411), UINT32_C(1624729856) },
      {
          { UINT32_C(2360753501), UINT32_C( 762530411) },
          { UINT32_C(2681976087), UINT32_C(1624729856) },
      },
    },
    { { UINT32_C(3797801438), UINT32_C(1832714608) },
      { UINT32_C(3468766375), UINT32_C( 654237641) },
      {
          { UINT32_C(3797801438), UINT32_C(3468766375) },
          { UINT32_C(1832714608), UINT32_C( 654237641) },
      },
    },
    { { UINT32_C( 867349532), UINT32_C(3570568553) },
      { UINT32_C(3607185111), UINT32_C(2369247663) },
      {
          { UINT32_C( 867349532), UINT32_C(3607185111) },
          { UINT32_C(3570568553), UINT32_C(2369247663) },
      },
    },
    { { UINT32_C( 577738162), UINT32_C(1049668758) },
      { UINT32_C(2718716377), UINT32_C(1288243760) },
      {
          { UINT32_C( 577738162), UINT32_C(2718716377) },
          { UINT32_C(1049668758), UINT32_C(1288243760) },
      },
    },
    { { UINT32_C( 662666174), UINT32_C(3774632201) },
      { UINT32_C(1186528663), UINT32_C(2312368086) },
      {
          { UINT32_C( 662666174), UINT32_C(1186528663) },
          { UINT32_C(3774632201), UINT32_C(2312368086) },
      },
    },
    { { UINT32_C( 464208772), UINT32_C(3361291247) },
      { UINT32_C(3161154956), UINT32_C( 755512431) },
      {
          { UINT32_C( 464208772), UINT32_C(3161154956) },
          { UINT32_C(3361291247), UINT32_C( 755512431) },
      },
    },
    { { UINT32_C(3092547503), UINT32_C(1889095897) },
      { UINT32_C( 615993678), UINT32_C(3316484672) },
      {
          { UINT32_C(3092547503), UINT32_C( 615993678) },
          { UINT32_C(1889095897), UINT32_C(3316484672) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2x2_t r = simde_vuzp_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r.val[0], simde_vld1_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], simde_vld1_u32(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2x2_t c = simde_vuzp_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float16_t r[2][8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE( 73.721),  SIMDE_FLOAT16_VALUE( 46.339), SIMDE_FLOAT16_VALUE( - 10.427), SIMDE_FLOAT16_VALUE( - 38.234),
        SIMDE_FLOAT16_VALUE( - 26.097),  SIMDE_FLOAT16_VALUE( 16.887), SIMDE_FLOAT16_VALUE( - 35.759),  SIMDE_FLOAT16_VALUE( 44.147) },
      { SIMDE_FLOAT16_VALUE( - 60.955), SIMDE_FLOAT16_VALUE( - 22.797),  SIMDE_FLOAT16_VALUE( 18.481),  SIMDE_FLOAT16_VALUE( 74.071),
        SIMDE_FLOAT16_VALUE( - 22.559), SIMDE_FLOAT16_VALUE( - 85.762),  SIMDE_FLOAT16_VALUE( 19.915),  SIMDE_FLOAT16_VALUE( 70.645) },
    { {  SIMDE_FLOAT16_VALUE( 73.721), SIMDE_FLOAT16_VALUE( - 10.427), SIMDE_FLOAT16_VALUE( - 26.097), SIMDE_FLOAT16_VALUE( - 35.759),
        SIMDE_FLOAT16_VALUE( - 60.955),  SIMDE_FLOAT16_VALUE( 18.481), SIMDE_FLOAT16_VALUE( - 22.559),  SIMDE_FLOAT16_VALUE( 19.915)  },
      {  SIMDE_FLOAT16_VALUE( 46.339), SIMDE_FLOAT16_VALUE( - 38.234),  SIMDE_FLOAT16_VALUE( 16.887),  SIMDE_FLOAT16_VALUE( 44.147),
        SIMDE_FLOAT16_VALUE( - 22.797),  SIMDE_FLOAT16_VALUE( 74.071), SIMDE_FLOAT16_VALUE( - 85.762),  SIMDE_FLOAT16_VALUE( 70.645)  } } },
    { { SIMDE_FLOAT16_VALUE( - 40.265), SIMDE_FLOAT16_VALUE( -  2.182),  SIMDE_FLOAT16_VALUE( 72.917),  SIMDE_FLOAT16_VALUE( 13.517),
        SIMDE_FLOAT16_VALUE( - 43.058), SIMDE_FLOAT16_VALUE( - 92.395),  SIMDE_FLOAT16_VALUE( 74.671),  SIMDE_FLOAT16_VALUE( 43.330) },
      { SIMDE_FLOAT16_VALUE( - 30.362),  SIMDE_FLOAT16_VALUE(  8.299), SIMDE_FLOAT16_VALUE( - 59.100),  SIMDE_FLOAT16_VALUE( 42.001),
         SIMDE_FLOAT16_VALUE(  3.619), SIMDE_FLOAT16_VALUE( -  9.776),  SIMDE_FLOAT16_VALUE( 59.224), SIMDE_FLOAT16_VALUE( - 70.831) },
    { { SIMDE_FLOAT16_VALUE( - 40.265),  SIMDE_FLOAT16_VALUE( 72.917), SIMDE_FLOAT16_VALUE( - 43.058),  SIMDE_FLOAT16_VALUE( 74.671),
        SIMDE_FLOAT16_VALUE( - 30.362), SIMDE_FLOAT16_VALUE( - 59.100),  SIMDE_FLOAT16_VALUE(  3.619),  SIMDE_FLOAT16_VALUE( 59.224)  },
      { SIMDE_FLOAT16_VALUE( -  2.182),  SIMDE_FLOAT16_VALUE( 13.517), SIMDE_FLOAT16_VALUE( - 92.395),  SIMDE_FLOAT16_VALUE( 43.330),
         SIMDE_FLOAT16_VALUE(  8.299),  SIMDE_FLOAT16_VALUE( 42.001), SIMDE_FLOAT16_VALUE( -  9.776), SIMDE_FLOAT16_VALUE( - 70.831)  } } },
    { {  SIMDE_FLOAT16_VALUE(  5.621), SIMDE_FLOAT16_VALUE( - 81.247),  SIMDE_FLOAT16_VALUE( 88.883), SIMDE_FLOAT16_VALUE( - 67.993),
        SIMDE_FLOAT16_VALUE( - 42.899),  SIMDE_FLOAT16_VALUE( 93.583), SIMDE_FLOAT16_VALUE( - 78.748), SIMDE_FLOAT16_VALUE( - 91.309) },
      {  SIMDE_FLOAT16_VALUE( 81.834), SIMDE_FLOAT16_VALUE( -  9.827),  SIMDE_FLOAT16_VALUE( 45.970), SIMDE_FLOAT16_VALUE( - 17.700),
         SIMDE_FLOAT16_VALUE( 29.375),  SIMDE_FLOAT16_VALUE( 29.732),  SIMDE_FLOAT16_VALUE(  6.694), SIMDE_FLOAT16_VALUE( - 39.767) },
    { {  SIMDE_FLOAT16_VALUE(  5.621),  SIMDE_FLOAT16_VALUE( 88.883), SIMDE_FLOAT16_VALUE( - 42.899), SIMDE_FLOAT16_VALUE( - 78.748),
         SIMDE_FLOAT16_VALUE( 81.834),  SIMDE_FLOAT16_VALUE( 45.970),  SIMDE_FLOAT16_VALUE( 29.375),  SIMDE_FLOAT16_VALUE(  6.694)  },
      { SIMDE_FLOAT16_VALUE( - 81.247), SIMDE_FLOAT16_VALUE( - 67.993),  SIMDE_FLOAT16_VALUE( 93.583), SIMDE_FLOAT16_VALUE( - 91.309),
        SIMDE_FLOAT16_VALUE( -  9.827), SIMDE_FLOAT16_VALUE( - 17.700),  SIMDE_FLOAT16_VALUE( 29.732), SIMDE_FLOAT16_VALUE( - 39.767)  } } },
    { { SIMDE_FLOAT16_VALUE( - 46.220), SIMDE_FLOAT16_VALUE( - 82.527),  SIMDE_FLOAT16_VALUE( 16.982), SIMDE_FLOAT16_VALUE( - 71.688),
         SIMDE_FLOAT16_VALUE( 87.960),  SIMDE_FLOAT16_VALUE( 65.171), SIMDE_FLOAT16_VALUE( -  7.922),  SIMDE_FLOAT16_VALUE(  7.006) },
      { SIMDE_FLOAT16_VALUE( - 65.689),  SIMDE_FLOAT16_VALUE(  3.075), SIMDE_FLOAT16_VALUE( - 37.945),  SIMDE_FLOAT16_VALUE( 93.491),
        SIMDE_FLOAT16_VALUE( - 96.072), SIMDE_FLOAT16_VALUE( - 91.531), SIMDE_FLOAT16_VALUE( - 19.597), SIMDE_FLOAT16_VALUE( - 43.425) },
    { { SIMDE_FLOAT16_VALUE( - 46.220),  SIMDE_FLOAT16_VALUE( 16.982),  SIMDE_FLOAT16_VALUE( 87.960), SIMDE_FLOAT16_VALUE( -  7.922),
        SIMDE_FLOAT16_VALUE( - 65.689), SIMDE_FLOAT16_VALUE( - 37.945), SIMDE_FLOAT16_VALUE( - 96.072), SIMDE_FLOAT16_VALUE( - 19.597)  },
      { SIMDE_FLOAT16_VALUE( - 82.527), SIMDE_FLOAT16_VALUE( - 71.688),  SIMDE_FLOAT16_VALUE( 65.171),  SIMDE_FLOAT16_VALUE(  7.006),
         SIMDE_FLOAT16_VALUE(  3.075),  SIMDE_FLOAT16_VALUE( 93.491), SIMDE_FLOAT16_VALUE( - 91.531), SIMDE_FLOAT16_VALUE( - 43.425)  } } },
    { {  SIMDE_FLOAT16_VALUE(  2.917),  SIMDE_FLOAT16_VALUE( 56.631), SIMDE_FLOAT16_VALUE( -  8.652), SIMDE_FLOAT16_VALUE( - 52.253),
        SIMDE_FLOAT16_VALUE( - 58.261), SIMDE_FLOAT16_VALUE( - 54.516), SIMDE_FLOAT16_VALUE( - 72.534), SIMDE_FLOAT16_VALUE( -  2.400) },
      {  SIMDE_FLOAT16_VALUE( 16.476), SIMDE_FLOAT16_VALUE( - 79.379), SIMDE_FLOAT16_VALUE( - 98.048),  SIMDE_FLOAT16_VALUE( 82.106),
         SIMDE_FLOAT16_VALUE( 39.266), SIMDE_FLOAT16_VALUE( - 94.860),  SIMDE_FLOAT16_VALUE( 35.909), SIMDE_FLOAT16_VALUE( - 75.766) },
    { {  SIMDE_FLOAT16_VALUE(  2.917), SIMDE_FLOAT16_VALUE( -  8.652), SIMDE_FLOAT16_VALUE( - 58.261), SIMDE_FLOAT16_VALUE( - 72.534),
         SIMDE_FLOAT16_VALUE( 16.476), SIMDE_FLOAT16_VALUE( - 98.048),  SIMDE_FLOAT16_VALUE( 39.266),  SIMDE_FLOAT16_VALUE( 35.909)  },
      {  SIMDE_FLOAT16_VALUE( 56.631), SIMDE_FLOAT16_VALUE( - 52.253), SIMDE_FLOAT16_VALUE( - 54.516), SIMDE_FLOAT16_VALUE( -  2.400),
        SIMDE_FLOAT16_VALUE( - 79.379),  SIMDE_FLOAT16_VALUE( 82.106), SIMDE_FLOAT16_VALUE( - 94.860), SIMDE_FLOAT16_VALUE( - 75.766)  } } },
    { {  SIMDE_FLOAT16_VALUE( 44.120),  SIMDE_FLOAT16_VALUE(  3.642), SIMDE_FLOAT16_VALUE( - 74.784),  SIMDE_FLOAT16_VALUE( 65.438),
         SIMDE_FLOAT16_VALUE(  4.092),  SIMDE_FLOAT16_VALUE( 98.436),  SIMDE_FLOAT16_VALUE( 58.246), SIMDE_FLOAT16_VALUE( - 60.461) },
      {  SIMDE_FLOAT16_VALUE( 76.015), SIMDE_FLOAT16_VALUE( - 62.906), SIMDE_FLOAT16_VALUE( - 27.211), SIMDE_FLOAT16_VALUE( - 53.115),
        SIMDE_FLOAT16_VALUE( - 19.255),  SIMDE_FLOAT16_VALUE( 64.714), SIMDE_FLOAT16_VALUE( - 24.123), SIMDE_FLOAT16_VALUE( - 77.006) },
    { {  SIMDE_FLOAT16_VALUE( 44.120), SIMDE_FLOAT16_VALUE( - 74.784),  SIMDE_FLOAT16_VALUE(  4.092),  SIMDE_FLOAT16_VALUE( 58.246),
         SIMDE_FLOAT16_VALUE( 76.015), SIMDE_FLOAT16_VALUE( - 27.211), SIMDE_FLOAT16_VALUE( - 19.255), SIMDE_FLOAT16_VALUE( - 24.123)  },
      {  SIMDE_FLOAT16_VALUE(  3.642),  SIMDE_FLOAT16_VALUE( 65.438),  SIMDE_FLOAT16_VALUE( 98.436), SIMDE_FLOAT16_VALUE( - 60.461),
        SIMDE_FLOAT16_VALUE( - 62.906), SIMDE_FLOAT16_VALUE( - 53.115),  SIMDE_FLOAT16_VALUE( 64.714), SIMDE_FLOAT16_VALUE( - 77.006)  } } },
    { {  SIMDE_FLOAT16_VALUE( 28.681),  SIMDE_FLOAT16_VALUE( 95.430), SIMDE_FLOAT16_VALUE( -  1.556),  SIMDE_FLOAT16_VALUE( 56.474),
        SIMDE_FLOAT16_VALUE( -  8.834),  SIMDE_FLOAT16_VALUE( 57.675), SIMDE_FLOAT16_VALUE( - 74.749),  SIMDE_FLOAT16_VALUE( 76.983) },
      { SIMDE_FLOAT16_VALUE( - 99.195), SIMDE_FLOAT16_VALUE( - 28.023),  SIMDE_FLOAT16_VALUE( 87.270), SIMDE_FLOAT16_VALUE( -  1.591),
         SIMDE_FLOAT16_VALUE( 11.636), SIMDE_FLOAT16_VALUE( -  6.493), SIMDE_FLOAT16_VALUE( - 32.712), SIMDE_FLOAT16_VALUE( - 72.389) },
    { {  SIMDE_FLOAT16_VALUE( 28.681), SIMDE_FLOAT16_VALUE( -  1.556), SIMDE_FLOAT16_VALUE( -  8.834), SIMDE_FLOAT16_VALUE( - 74.749),
        SIMDE_FLOAT16_VALUE( - 99.195),  SIMDE_FLOAT16_VALUE( 87.270),  SIMDE_FLOAT16_VALUE( 11.636), SIMDE_FLOAT16_VALUE( - 32.712)  },
      {  SIMDE_FLOAT16_VALUE( 95.430),  SIMDE_FLOAT16_VALUE( 56.474),  SIMDE_FLOAT16_VALUE( 57.675),  SIMDE_FLOAT16_VALUE( 76.983),
        SIMDE_FLOAT16_VALUE( - 28.023), SIMDE_FLOAT16_VALUE( -  1.591), SIMDE_FLOAT16_VALUE( -  6.493), SIMDE_FLOAT16_VALUE( - 72.389)  } } },
    { {  SIMDE_FLOAT16_VALUE( 77.839), SIMDE_FLOAT16_VALUE( - 60.894), SIMDE_FLOAT16_VALUE( - 29.168), SIMDE_FLOAT16_VALUE( - 10.467),
        SIMDE_FLOAT16_VALUE( - 99.954),  SIMDE_FLOAT16_VALUE(  6.428), SIMDE_FLOAT16_VALUE( - 12.713),  SIMDE_FLOAT16_VALUE( 92.257) },
      {  SIMDE_FLOAT16_VALUE(  5.688),  SIMDE_FLOAT16_VALUE( 43.890),  SIMDE_FLOAT16_VALUE( 48.122), SIMDE_FLOAT16_VALUE( -  2.823),
         SIMDE_FLOAT16_VALUE( 65.174),  SIMDE_FLOAT16_VALUE( 27.456),  SIMDE_FLOAT16_VALUE( 71.730),  SIMDE_FLOAT16_VALUE( 27.816) },
    { {  SIMDE_FLOAT16_VALUE( 77.839), SIMDE_FLOAT16_VALUE( - 29.168), SIMDE_FLOAT16_VALUE( - 99.954), SIMDE_FLOAT16_VALUE( - 12.713),
         SIMDE_FLOAT16_VALUE(  5.688),  SIMDE_FLOAT16_VALUE( 48.122),  SIMDE_FLOAT16_VALUE( 65.174),  SIMDE_FLOAT16_VALUE( 71.730)  },
      { SIMDE_FLOAT16_VALUE( - 60.894), SIMDE_FLOAT16_VALUE( - 10.467),  SIMDE_FLOAT16_VALUE(  6.428),  SIMDE_FLOAT16_VALUE( 92.257),
         SIMDE_FLOAT16_VALUE( 43.890), SIMDE_FLOAT16_VALUE( -  2.823),  SIMDE_FLOAT16_VALUE( 27.456),  SIMDE_FLOAT16_VALUE( 27.816)  } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8x2_t r = simde_vuzpq_f16(a, b);
    simde_test_arm_neon_assert_equal_f16x8(r.val[0], simde_vld1q_f16(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f16x8(r.val[1], simde_vld1q_f16(test_vec[i].r[1]), 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8x2_t c = simde_vuzpq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[2][4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   336.86), SIMDE_FLOAT32_C(   940.59), SIMDE_FLOAT32_C(   624.20), SIMDE_FLOAT32_C(   198.24) },
      { SIMDE_FLOAT32_C(  -819.71), SIMDE_FLOAT32_C(   812.42), SIMDE_FLOAT32_C(  -979.32), SIMDE_FLOAT32_C(  -307.51) },
      {
          { SIMDE_FLOAT32_C(   336.86), SIMDE_FLOAT32_C(   624.20), SIMDE_FLOAT32_C(  -819.71), SIMDE_FLOAT32_C(  -979.32) },
          { SIMDE_FLOAT32_C(   940.59), SIMDE_FLOAT32_C(   198.24), SIMDE_FLOAT32_C(   812.42), SIMDE_FLOAT32_C(  -307.51) },
      },
    },
    { { SIMDE_FLOAT32_C(   894.01), SIMDE_FLOAT32_C(  -916.74), SIMDE_FLOAT32_C(  -332.33), SIMDE_FLOAT32_C(     0.85) },
      { SIMDE_FLOAT32_C(   121.08), SIMDE_FLOAT32_C(   820.47), SIMDE_FLOAT32_C(  -541.38), SIMDE_FLOAT32_C(   730.98) },
      {
          { SIMDE_FLOAT32_C(   894.01), SIMDE_FLOAT32_C(  -332.33), SIMDE_FLOAT32_C(   121.08), SIMDE_FLOAT32_C(  -541.38) },
          { SIMDE_FLOAT32_C(  -916.74), SIMDE_FLOAT32_C(     0.85), SIMDE_FLOAT32_C(   820.47), SIMDE_FLOAT32_C(   730.98) },
      },
    },
    { { SIMDE_FLOAT32_C(   -88.10), SIMDE_FLOAT32_C(  -685.13), SIMDE_FLOAT32_C(  -502.77), SIMDE_FLOAT32_C(  -970.47) },
      { SIMDE_FLOAT32_C(   803.17), SIMDE_FLOAT32_C(   233.77), SIMDE_FLOAT32_C(   409.34), SIMDE_FLOAT32_C(   846.91) },
      {
          { SIMDE_FLOAT32_C(   -88.10), SIMDE_FLOAT32_C(  -502.77), SIMDE_FLOAT32_C(   803.17), SIMDE_FLOAT32_C(   409.34) },
          { SIMDE_FLOAT32_C(  -685.13), SIMDE_FLOAT32_C(  -970.47), SIMDE_FLOAT32_C(   233.77), SIMDE_FLOAT32_C(   846.91) },
      },
    },
    { { SIMDE_FLOAT32_C(   785.89), SIMDE_FLOAT32_C(  -295.61), SIMDE_FLOAT32_C(   -65.85), SIMDE_FLOAT32_C(   708.46) },
      { SIMDE_FLOAT32_C(  -432.93), SIMDE_FLOAT32_C(   209.38), SIMDE_FLOAT32_C(   884.61), SIMDE_FLOAT32_C(   903.93) },
      {
          { SIMDE_FLOAT32_C(   785.89), SIMDE_FLOAT32_C(   -65.85), SIMDE_FLOAT32_C(  -432.93), SIMDE_FLOAT32_C(   884.61) },
          { SIMDE_FLOAT32_C(  -295.61), SIMDE_FLOAT32_C(   708.46), SIMDE_FLOAT32_C(   209.38), SIMDE_FLOAT32_C(   903.93) },
      },
    },
    { { SIMDE_FLOAT32_C(   149.97), SIMDE_FLOAT32_C(   508.80), SIMDE_FLOAT32_C(   102.16), SIMDE_FLOAT32_C(   330.26) },
      { SIMDE_FLOAT32_C(   321.22), SIMDE_FLOAT32_C(   122.85), SIMDE_FLOAT32_C(  -977.25), SIMDE_FLOAT32_C(   215.24) },
      {
          { SIMDE_FLOAT32_C(   149.97), SIMDE_FLOAT32_C(   102.16), SIMDE_FLOAT32_C(   321.22), SIMDE_FLOAT32_C(  -977.25) },
          { SIMDE_FLOAT32_C(   508.80), SIMDE_FLOAT32_C(   330.26), SIMDE_FLOAT32_C(   122.85), SIMDE_FLOAT32_C(   215.24) },
      },
    },
    { { SIMDE_FLOAT32_C(   206.11), SIMDE_FLOAT32_C(  -309.58), SIMDE_FLOAT32_C(  -783.92), SIMDE_FLOAT32_C(  -672.81) },
      { SIMDE_FLOAT32_C(  -489.11), SIMDE_FLOAT32_C(  -325.29), SIMDE_FLOAT32_C(  -941.84), SIMDE_FLOAT32_C(   422.79) },
      {
          { SIMDE_FLOAT32_C(   206.11), SIMDE_FLOAT32_C(  -783.92), SIMDE_FLOAT32_C(  -489.11), SIMDE_FLOAT32_C(  -941.84) },
          { SIMDE_FLOAT32_C(  -309.58), SIMDE_FLOAT32_C(  -672.81), SIMDE_FLOAT32_C(  -325.29), SIMDE_FLOAT32_C(   422.79) },
      },
    },
    { { SIMDE_FLOAT32_C(   -10.42), SIMDE_FLOAT32_C(  -444.60), SIMDE_FLOAT32_C(   452.32), SIMDE_FLOAT32_C(  -207.25) },
      { SIMDE_FLOAT32_C(   789.16), SIMDE_FLOAT32_C(  -138.34), SIMDE_FLOAT32_C(  -360.35), SIMDE_FLOAT32_C(   575.05) },
      {
          { SIMDE_FLOAT32_C(   -10.42), SIMDE_FLOAT32_C(   452.32), SIMDE_FLOAT32_C(   789.16), SIMDE_FLOAT32_C(  -360.35) },
          { SIMDE_FLOAT32_C(  -444.60), SIMDE_FLOAT32_C(  -207.25), SIMDE_FLOAT32_C(  -138.34), SIMDE_FLOAT32_C(   575.05) },
      },
    },
    { { SIMDE_FLOAT32_C(   566.05), SIMDE_FLOAT32_C(   573.80), SIMDE_FLOAT32_C(   283.51), SIMDE_FLOAT32_C(  -866.88) },
      { SIMDE_FLOAT32_C(  -216.82), SIMDE_FLOAT32_C(   168.12), SIMDE_FLOAT32_C(  -962.96), SIMDE_FLOAT32_C(   933.15) },
      {
          { SIMDE_FLOAT32_C(   566.05), SIMDE_FLOAT32_C(   283.51), SIMDE_FLOAT32_C(  -216.82), SIMDE_FLOAT32_C(  -962.96) },
          { SIMDE_FLOAT32_C(   573.80), SIMDE_FLOAT32_C(  -866.88), SIMDE_FLOAT32_C(   168.12), SIMDE_FLOAT32_C(   933.15) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4x2_t r = simde_vuzpq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r.val[0], simde_vld1q_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], simde_vld1q_f32(test_vec[i].r[1]), 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x2_t c = simde_vuzpq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[2][16];
  } test_vec[] = {
    { {  INT8_C( 122),  INT8_C(  73), -INT8_C(  37),  INT8_C(  66),  INT8_C( 123),  INT8_C( 122),  INT8_C(  37),  INT8_C(  13),
        -INT8_C(  49), -INT8_C(   9),  INT8_C(  86),  INT8_C(  52),  INT8_C( 118), -INT8_C(  30),  INT8_C(  83), -INT8_C(  46) },
      { -INT8_C(  34),  INT8_C(  15),  INT8_C(  51), -INT8_C(  94), -INT8_C(  38),  INT8_C(  91),  INT8_C(  64), -INT8_C(  31),
         INT8_C(  90), -INT8_C(  46),  INT8_C(  96),  INT8_C(  12),  INT8_C(  83),  INT8_C(  13),  INT8_C(  24), -INT8_C(  51) },
      {
          {  INT8_C( 122), -INT8_C(  37),  INT8_C( 123),  INT8_C(  37), -INT8_C(  49),  INT8_C(  86),  INT8_C( 118),  INT8_C(  83),
            -INT8_C(  34),  INT8_C(  51), -INT8_C(  38),  INT8_C(  64),  INT8_C(  90),  INT8_C(  96),  INT8_C(  83),  INT8_C(  24) },
          {  INT8_C(  73),  INT8_C(  66),  INT8_C( 122),  INT8_C(  13), -INT8_C(   9),  INT8_C(  52), -INT8_C(  30), -INT8_C(  46),
             INT8_C(  15), -INT8_C(  94),  INT8_C(  91), -INT8_C(  31), -INT8_C(  46),  INT8_C(  12),  INT8_C(  13), -INT8_C(  51) },
      },
    },
    { {  INT8_C(  87), -INT8_C(  12),  INT8_C(  16), -INT8_C(  46),  INT8_C( 110),  INT8_C(  53), -INT8_C(  33),  INT8_C(  61),
         INT8_C(  44),  INT8_C(  53),  INT8_C( 113), -INT8_C(  94),  INT8_C(  23), -INT8_C(  60),  INT8_C( 117), -INT8_C(  10) },
      { -INT8_C(  45), -INT8_C(  88), -INT8_C( 104), -INT8_C(  83),  INT8_C(   3), -INT8_C(  39), -INT8_C( 113),  INT8_C(  93),
        -INT8_C(  85), -INT8_C(  17),  INT8_C( 105), -INT8_C(   1), -INT8_C(   3), -INT8_C( 126), -INT8_C(  52),  INT8_C(  84) },
      {
          {  INT8_C(  87),  INT8_C(  16),  INT8_C( 110), -INT8_C(  33),  INT8_C(  44),  INT8_C( 113),  INT8_C(  23),  INT8_C( 117),
            -INT8_C(  45), -INT8_C( 104),  INT8_C(   3), -INT8_C( 113), -INT8_C(  85),  INT8_C( 105), -INT8_C(   3), -INT8_C(  52) },
          { -INT8_C(  12), -INT8_C(  46),  INT8_C(  53),  INT8_C(  61),  INT8_C(  53), -INT8_C(  94), -INT8_C(  60), -INT8_C(  10),
            -INT8_C(  88), -INT8_C(  83), -INT8_C(  39),  INT8_C(  93), -INT8_C(  17), -INT8_C(   1), -INT8_C( 126),  INT8_C(  84) },
      },
    },
    { {  INT8_C( 118), -INT8_C(  36),  INT8_C(  38), -INT8_C(  28),  INT8_C(  17),  INT8_C(   5),  INT8_C(  33),  INT8_C(  61),
         INT8_C(  59), -INT8_C( 110), -INT8_C(  32),  INT8_C(  82),  INT8_C(  86),  INT8_C(  85),  INT8_C(  72),  INT8_C(  41) },
      { -INT8_C(   3), -INT8_C(  31), -INT8_C(  41),  INT8_C(   0), -INT8_C(  70),  INT8_C( 102),  INT8_C(  93),  INT8_C( 101),
         INT8_C(  85), -INT8_C(  57),  INT8_C( 100),  INT8_C(  82),  INT8_C(  73),  INT8_C(  49), -INT8_C(  90), -INT8_C(  65) },
      {
          {  INT8_C( 118),  INT8_C(  38),  INT8_C(  17),  INT8_C(  33),  INT8_C(  59), -INT8_C(  32),  INT8_C(  86),  INT8_C(  72),
            -INT8_C(   3), -INT8_C(  41), -INT8_C(  70),  INT8_C(  93),  INT8_C(  85),  INT8_C( 100),  INT8_C(  73), -INT8_C(  90) },
          { -INT8_C(  36), -INT8_C(  28),  INT8_C(   5),  INT8_C(  61), -INT8_C( 110),  INT8_C(  82),  INT8_C(  85),  INT8_C(  41),
            -INT8_C(  31),  INT8_C(   0),  INT8_C( 102),  INT8_C( 101), -INT8_C(  57),  INT8_C(  82),  INT8_C(  49), -INT8_C(  65) },
      },
    },
    { {  INT8_C(  13), -INT8_C(  52), -INT8_C(  93),  INT8_C(  31), -INT8_C(  46), -INT8_C(  60),  INT8_C(  92),  INT8_C(  13),
         INT8_C(  86),  INT8_C(  60),  INT8_C(  95), -INT8_C(  84), -INT8_C( 111), -INT8_C(  88), -INT8_C(  43), -INT8_C( 114) },
      { -INT8_C( 119), -INT8_C(  84), -INT8_C( 114),  INT8_C(  67),  INT8_C(  18), -INT8_C(  20), -INT8_C(  88),  INT8_C( 104),
        -INT8_C(  77),  INT8_C(  13), -INT8_C(  70), -INT8_C(   4),  INT8_C(  62),  INT8_C(  97), -INT8_C(  69),  INT8_C(  75) },
      {
          {  INT8_C(  13), -INT8_C(  93), -INT8_C(  46),  INT8_C(  92),  INT8_C(  86),  INT8_C(  95), -INT8_C( 111), -INT8_C(  43),
            -INT8_C( 119), -INT8_C( 114),  INT8_C(  18), -INT8_C(  88), -INT8_C(  77), -INT8_C(  70),  INT8_C(  62), -INT8_C(  69) },
          { -INT8_C(  52),  INT8_C(  31), -INT8_C(  60),  INT8_C(  13),  INT8_C(  60), -INT8_C(  84), -INT8_C(  88), -INT8_C( 114),
            -INT8_C(  84),  INT8_C(  67), -INT8_C(  20),  INT8_C( 104),  INT8_C(  13), -INT8_C(   4),  INT8_C(  97),  INT8_C(  75) },
      },
    },
    { {  INT8_C(  45),  INT8_C(  94),  INT8_C( 106), -INT8_C(   1),  INT8_C(  34), -INT8_C(  57),  INT8_C(  12),  INT8_C( 120),
         INT8_C(   3),  INT8_C( 108),  INT8_C(  36), -INT8_C( 107),  INT8_C(  20), -INT8_C(   7),  INT8_C(  35), -INT8_C(  99) },
      { -INT8_C(  90), -INT8_C(  78), -INT8_C(  32), -INT8_C(  72), -INT8_C(  98), -INT8_C( 120),  INT8_C(  32),  INT8_C(  81),
        -INT8_C( 107), -INT8_C(  37),  INT8_C(  77), -INT8_C(  45),  INT8_C(  60),  INT8_C(   8),  INT8_C(  31),  INT8_C( 105) },
      {
          {  INT8_C(  45),  INT8_C( 106),  INT8_C(  34),  INT8_C(  12),  INT8_C(   3),  INT8_C(  36),  INT8_C(  20),  INT8_C(  35),
            -INT8_C(  90), -INT8_C(  32), -INT8_C(  98),  INT8_C(  32), -INT8_C( 107),  INT8_C(  77),  INT8_C(  60),  INT8_C(  31) },
          {  INT8_C(  94), -INT8_C(   1), -INT8_C(  57),  INT8_C( 120),  INT8_C( 108), -INT8_C( 107), -INT8_C(   7), -INT8_C(  99),
            -INT8_C(  78), -INT8_C(  72), -INT8_C( 120),  INT8_C(  81), -INT8_C(  37), -INT8_C(  45),  INT8_C(   8),  INT8_C( 105) },
      },
    },
    { {  INT8_C( 102), -INT8_C( 119),  INT8_C( 105), -INT8_C( 120),  INT8_C(  80),  INT8_C( 117),  INT8_C(   0),  INT8_C(  84),
        -INT8_C(  31),  INT8_C(  36), -INT8_C(  23), -INT8_C(  11),  INT8_C(  29),  INT8_C(  12), -INT8_C( 110), -INT8_C(  61) },
      { -INT8_C(  66),  INT8_C( 114),  INT8_C( 124),  INT8_C(  92), -INT8_C(   5), -INT8_C( 100), -INT8_C(  83), -INT8_C( 112),
         INT8_C( 119), -INT8_C(   6),  INT8_C( 100), -INT8_C(  77),  INT8_C(   2), -INT8_C( 125),  INT8_C(  29),  INT8_C( 104) },
      {
          {  INT8_C( 102),  INT8_C( 105),  INT8_C(  80),  INT8_C(   0), -INT8_C(  31), -INT8_C(  23),  INT8_C(  29), -INT8_C( 110),
            -INT8_C(  66),  INT8_C( 124), -INT8_C(   5), -INT8_C(  83),  INT8_C( 119),  INT8_C( 100),  INT8_C(   2),  INT8_C(  29) },
          { -INT8_C( 119), -INT8_C( 120),  INT8_C( 117),  INT8_C(  84),  INT8_C(  36), -INT8_C(  11),  INT8_C(  12), -INT8_C(  61),
             INT8_C( 114),  INT8_C(  92), -INT8_C( 100), -INT8_C( 112), -INT8_C(   6), -INT8_C(  77), -INT8_C( 125),  INT8_C( 104) },
      },
    },
    { {  INT8_C(  12), -INT8_C( 122), -INT8_C(  16),  INT8_C(  93), -INT8_C(   5), -INT8_C(  16), -INT8_C(  79), -INT8_C(  35),
         INT8_C(  20), -INT8_C( 102), -INT8_C(  46),  INT8_C(  50), -INT8_C(  90),  INT8_C( 101), -INT8_C(  11),  INT8_C( 101) },
      { -INT8_C(  41),  INT8_C( 113), -INT8_C(  63), -INT8_C(  46),  INT8_C(  14),  INT8_C( 111),  INT8_C(  99), -INT8_C( 123),
         INT8_C( 105), -INT8_C(  57),  INT8_C(  57),  INT8_C( 108),  INT8_C(  74),  INT8_C(  86), -INT8_C(  44),  INT8_C(  86) },
      {
          {  INT8_C(  12), -INT8_C(  16), -INT8_C(   5), -INT8_C(  79),  INT8_C(  20), -INT8_C(  46), -INT8_C(  90), -INT8_C(  11),
            -INT8_C(  41), -INT8_C(  63),  INT8_C(  14),  INT8_C(  99),  INT8_C( 105),  INT8_C(  57),  INT8_C(  74), -INT8_C(  44) },
          { -INT8_C( 122),  INT8_C(  93), -INT8_C(  16), -INT8_C(  35), -INT8_C( 102),  INT8_C(  50),  INT8_C( 101),  INT8_C( 101),
             INT8_C( 113), -INT8_C(  46),  INT8_C( 111), -INT8_C( 123), -INT8_C(  57),  INT8_C( 108),  INT8_C(  86),  INT8_C(  86) },
      },
    },
    { { -INT8_C(  36), -INT8_C(  59), -INT8_C(  77), -INT8_C(  41), -INT8_C(  75),  INT8_C( 100), -INT8_C(  76), -INT8_C(  54),
        -INT8_C(   2), -INT8_C( 121), -INT8_C(   4), -INT8_C(  91), -INT8_C(  20), -INT8_C(  15),  INT8_C(  10), -INT8_C(  61) },
      {  INT8_C(  99), -INT8_C(  53), -INT8_C( 106),  INT8_C( 113),  INT8_C(  58), -INT8_C(   7), -INT8_C(  10), -INT8_C(  92),
        -INT8_C(  64),  INT8_C(  47),  INT8_C(  16),  INT8_C(  10), -INT8_C( 123), -INT8_C(  28),  INT8_C(  96),  INT8_C(  97) },
      {
          { -INT8_C(  36), -INT8_C(  77), -INT8_C(  75), -INT8_C(  76), -INT8_C(   2), -INT8_C(   4), -INT8_C(  20),  INT8_C(  10),
             INT8_C(  99), -INT8_C( 106),  INT8_C(  58), -INT8_C(  10), -INT8_C(  64),  INT8_C(  16), -INT8_C( 123),  INT8_C(  96) },
          { -INT8_C(  59), -INT8_C(  41),  INT8_C( 100), -INT8_C(  54), -INT8_C( 121), -INT8_C(  91), -INT8_C(  15), -INT8_C(  61),
            -INT8_C(  53),  INT8_C( 113), -INT8_C(   7), -INT8_C(  92),  INT8_C(  47),  INT8_C(  10), -INT8_C(  28),  INT8_C(  97) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16x2_t r = simde_vuzpq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], simde_vld1q_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], simde_vld1q_s8(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16x2_t c = simde_vuzpq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[2][8];
  } test_vec[] = {
    { {  INT16_C( 18981), -INT16_C( 19032), -INT16_C(  1653), -INT16_C( 25342), -INT16_C( 26301),  INT16_C(   658), -INT16_C( 19301), -INT16_C( 11855) },
      { -INT16_C( 13642),  INT16_C( 19323), -INT16_C( 29207), -INT16_C( 12273),  INT16_C( 24472),  INT16_C( 16673), -INT16_C( 23665), -INT16_C( 18984) },
      {
          {  INT16_C( 18981), -INT16_C(  1653), -INT16_C( 26301), -INT16_C( 19301), -INT16_C( 13642), -INT16_C( 29207),  INT16_C( 24472), -INT16_C( 23665) },
          { -INT16_C( 19032), -INT16_C( 25342),  INT16_C(   658), -INT16_C( 11855),  INT16_C( 19323), -INT16_C( 12273),  INT16_C( 16673), -INT16_C( 18984) },
      },
    },
    { { -INT16_C( 32275),  INT16_C( 30826),  INT16_C( 28026), -INT16_C( 17130), -INT16_C( 22522), -INT16_C( 24129),  INT16_C( 28765),  INT16_C(  4979) },
      { -INT16_C(  4550),  INT16_C(  9055),  INT16_C( 28283),  INT16_C(  5364),  INT16_C(  5581),  INT16_C( 23893),  INT16_C( 11960), -INT16_C( 23022) },
      {
          { -INT16_C( 32275),  INT16_C( 28026), -INT16_C( 22522),  INT16_C( 28765), -INT16_C(  4550),  INT16_C( 28283),  INT16_C(  5581),  INT16_C( 11960) },
          {  INT16_C( 30826), -INT16_C( 17130), -INT16_C( 24129),  INT16_C(  4979),  INT16_C(  9055),  INT16_C(  5364),  INT16_C( 23893), -INT16_C( 23022) },
      },
    },
    { {  INT16_C( 31919),  INT16_C( 10526),  INT16_C( 13545), -INT16_C(  4122), -INT16_C( 23075),  INT16_C( 14993),  INT16_C(  1046),  INT16_C( 20557) },
      { -INT16_C( 21262),  INT16_C( 28276),  INT16_C( 26650), -INT16_C(  6014), -INT16_C( 10371),  INT16_C( 13637),  INT16_C( 22277), -INT16_C( 19237) },
      {
          {  INT16_C( 31919),  INT16_C( 13545), -INT16_C( 23075),  INT16_C(  1046), -INT16_C( 21262),  INT16_C( 26650), -INT16_C( 10371),  INT16_C( 22277) },
          {  INT16_C( 10526), -INT16_C(  4122),  INT16_C( 14993),  INT16_C( 20557),  INT16_C( 28276), -INT16_C(  6014),  INT16_C( 13637), -INT16_C( 19237) },
      },
    },
    { { -INT16_C(  1325), -INT16_C( 16931), -INT16_C( 15570),  INT16_C(  2988),  INT16_C( 15721),  INT16_C( 32581), -INT16_C( 27839),  INT16_C( 13519) },
      {  INT16_C( 17215),  INT16_C( 23202),  INT16_C(  9387),  INT16_C( 10306), -INT16_C( 30725),  INT16_C(   350),  INT16_C( 14814), -INT16_C( 20043) },
      {
          { -INT16_C(  1325), -INT16_C( 15570),  INT16_C( 15721), -INT16_C( 27839),  INT16_C( 17215),  INT16_C(  9387), -INT16_C( 30725),  INT16_C( 14814) },
          { -INT16_C( 16931),  INT16_C(  2988),  INT16_C( 32581),  INT16_C( 13519),  INT16_C( 23202),  INT16_C( 10306),  INT16_C(   350), -INT16_C( 20043) },
      },
    },
    { { -INT16_C( 27853),  INT16_C( 25198),  INT16_C(  6998), -INT16_C( 16531), -INT16_C( 19624), -INT16_C( 26050),  INT16_C(  3654), -INT16_C( 31282) },
      {  INT16_C( 28753), -INT16_C(   545),  INT16_C(  8596), -INT16_C( 28891), -INT16_C( 31832), -INT16_C( 31088),  INT16_C( 18109), -INT16_C(  4040) },
      {
          { -INT16_C( 27853),  INT16_C(  6998), -INT16_C( 19624),  INT16_C(  3654),  INT16_C( 28753),  INT16_C(  8596), -INT16_C( 31832),  INT16_C( 18109) },
          {  INT16_C( 25198), -INT16_C( 16531), -INT16_C( 26050), -INT16_C( 31282), -INT16_C(   545), -INT16_C( 28891), -INT16_C( 31088), -INT16_C(  4040) },
      },
    },
    { { -INT16_C( 22823),  INT16_C( 12114), -INT16_C( 16191),  INT16_C(  6895),  INT16_C( 11635), -INT16_C( 17996), -INT16_C( 32197), -INT16_C( 29378) },
      {  INT16_C(  7922), -INT16_C( 31094), -INT16_C( 20673), -INT16_C(  6123), -INT16_C( 22989), -INT16_C(  3986), -INT16_C( 22804), -INT16_C( 14880) },
      {
          { -INT16_C( 22823), -INT16_C( 16191),  INT16_C( 11635), -INT16_C( 32197),  INT16_C(  7922), -INT16_C( 20673), -INT16_C( 22989), -INT16_C( 22804) },
          {  INT16_C( 12114),  INT16_C(  6895), -INT16_C( 17996), -INT16_C( 29378), -INT16_C( 31094), -INT16_C(  6123), -INT16_C(  3986), -INT16_C( 14880) },
      },
    },
    { {  INT16_C( 13133),  INT16_C(  3828), -INT16_C(  7181),  INT16_C( 26152), -INT16_C(  9199),  INT16_C( 19487),  INT16_C( 23902),  INT16_C( 20697) },
      {  INT16_C( 25467), -INT16_C( 17450), -INT16_C(  5101),  INT16_C( 18083),  INT16_C(  4498),  INT16_C( 32310),  INT16_C(  5816),  INT16_C(  1347) },
      {
          {  INT16_C( 13133), -INT16_C(  7181), -INT16_C(  9199),  INT16_C( 23902),  INT16_C( 25467), -INT16_C(  5101),  INT16_C(  4498),  INT16_C(  5816) },
          {  INT16_C(  3828),  INT16_C( 26152),  INT16_C( 19487),  INT16_C( 20697), -INT16_C( 17450),  INT16_C( 18083),  INT16_C( 32310),  INT16_C(  1347) },
      },
    },
    { {  INT16_C( 14153),  INT16_C( 15379),  INT16_C( 15387),  INT16_C( 11426), -INT16_C( 16104),  INT16_C( 30584),  INT16_C( 21023), -INT16_C( 25913) },
      { -INT16_C( 24907), -INT16_C( 14251), -INT16_C(  1910),  INT16_C(  7182),  INT16_C( 17418), -INT16_C( 15718), -INT16_C(  8869), -INT16_C( 23353) },
      {
          {  INT16_C( 14153),  INT16_C( 15387), -INT16_C( 16104),  INT16_C( 21023), -INT16_C( 24907), -INT16_C(  1910),  INT16_C( 17418), -INT16_C(  8869) },
          {  INT16_C( 15379),  INT16_C( 11426),  INT16_C( 30584), -INT16_C( 25913), -INT16_C( 14251),  INT16_C(  7182), -INT16_C( 15718), -INT16_C( 23353) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8x2_t r = simde_vuzpq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], simde_vld1q_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], simde_vld1q_s16(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8x2_t c = simde_vuzpq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[2][4];
  } test_vec[] = {
    { {  INT32_C(  1135740105),  INT32_C(   497863278),  INT32_C(   193109829), -INT32_C(  1962880757) },
      {  INT32_C(  2070865737),  INT32_C(   111450563), -INT32_C(  1085389284),  INT32_C(  1874856614) },
      {
          {  INT32_C(  1135740105),  INT32_C(   193109829),  INT32_C(  2070865737), -INT32_C(  1085389284) },
          {  INT32_C(   497863278), -INT32_C(  1962880757),  INT32_C(   111450563),  INT32_C(  1874856614) },
      },
    },
    { {  INT32_C(  2108912142), -INT32_C(  2120589508),  INT32_C(   160242942),  INT32_C(   915705325) },
      {  INT32_C(   934347380), -INT32_C(  1220717157),  INT32_C(  1098288283), -INT32_C(  1531890026) },
      {
          {  INT32_C(  2108912142),  INT32_C(   160242942),  INT32_C(   934347380),  INT32_C(  1098288283) },
          { -INT32_C(  2120589508),  INT32_C(   915705325), -INT32_C(  1220717157), -INT32_C(  1531890026) },
      },
    },
    { { -INT32_C(   450796376), -INT32_C(  1050231869), -INT32_C(   976489513), -INT32_C(   184852608) },
      { -INT32_C(    47403678), -INT32_C(  1632278270), -INT32_C(  1948308491),  INT32_C(   170954850) },
      {
          { -INT32_C(   450796376), -INT32_C(   976489513), -INT32_C(    47403678), -INT32_C(  1948308491) },
          { -INT32_C(  1050231869), -INT32_C(   184852608), -INT32_C(  1632278270),  INT32_C(   170954850) },
      },
    },
    { { -INT32_C(  1209052684), -INT32_C(   461810163), -INT32_C(   894876599),  INT32_C(    96380323) },
      {  INT32_C(  1409542738),  INT32_C(  1240643668),  INT32_C(  1171641059),  INT32_C(  1464862050) },
      {
          { -INT32_C(  1209052684), -INT32_C(   894876599),  INT32_C(  1409542738),  INT32_C(  1171641059) },
          { -INT32_C(   461810163),  INT32_C(    96380323),  INT32_C(  1240643668),  INT32_C(  1464862050) },
      },
    },
    { {  INT32_C(  1661878102), -INT32_C(   548894827),  INT32_C(  1873408459), -INT32_C(   395024490) },
      { -INT32_C(  1505921198),  INT32_C(   334442287),  INT32_C(  1683538945),  INT32_C(   549169353) },
      {
          {  INT32_C(  1661878102),  INT32_C(  1873408459), -INT32_C(  1505921198),  INT32_C(  1683538945) },
          { -INT32_C(   548894827), -INT32_C(   395024490),  INT32_C(   334442287),  INT32_C(   549169353) },
      },
    },
    { {  INT32_C(  2105788904),  INT32_C(   475843409),  INT32_C(  1401619901), -INT32_C(  1086586771) },
      { -INT32_C(  1486521993), -INT32_C(  1430629208), -INT32_C(   502394343), -INT32_C(  1560098373) },
      {
          {  INT32_C(  2105788904),  INT32_C(  1401619901), -INT32_C(  1486521993), -INT32_C(   502394343) },
          {  INT32_C(   475843409), -INT32_C(  1086586771), -INT32_C(  1430629208), -INT32_C(  1560098373) },
      },
    },
    { { -INT32_C(   484407662),  INT32_C(   234913105), -INT32_C(   278754430),  INT32_C(    61775499) },
      { -INT32_C(  1079373033), -INT32_C(  2123799448),  INT32_C(   828602230), -INT32_C(   741054912) },
      {
          { -INT32_C(   484407662), -INT32_C(   278754430), -INT32_C(  1079373033),  INT32_C(   828602230) },
          {  INT32_C(   234913105),  INT32_C(    61775499), -INT32_C(  2123799448), -INT32_C(   741054912) },
      },
    },
    { {  INT32_C(  1035400684), -INT32_C(   196299150), -INT32_C(   840651198),  INT32_C(  1674613324) },
      {  INT32_C(   237140646),  INT32_C(  1435471070),  INT32_C(  1149694467),  INT32_C(  1142381400) },
      {
          {  INT32_C(  1035400684), -INT32_C(   840651198),  INT32_C(   237140646),  INT32_C(  1149694467) },
          { -INT32_C(   196299150),  INT32_C(  1674613324),  INT32_C(  1435471070),  INT32_C(  1142381400) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4x2_t r = simde_vuzpq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r.val[0], simde_vld1q_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], simde_vld1q_s32(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4x2_t c = simde_vuzpq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[2][16];
  } test_vec[] = {
    { { UINT8_C( 32), UINT8_C(240), UINT8_C( 75), UINT8_C( 60), UINT8_C(238), UINT8_C(113), UINT8_C(237), UINT8_C( 92),
        UINT8_C( 44), UINT8_C(211), UINT8_C(242), UINT8_C(151), UINT8_C( 20), UINT8_C( 59), UINT8_C(160), UINT8_C( 43) },
      { UINT8_C( 51), UINT8_C( 41), UINT8_C(155), UINT8_C(227), UINT8_C(199), UINT8_C(249), UINT8_C(233), UINT8_C(251),
        UINT8_C( 68), UINT8_C(216), UINT8_C(183), UINT8_C(229), UINT8_C(161), UINT8_C( 14), UINT8_C(130), UINT8_C(193) },
      {
          { UINT8_C( 32), UINT8_C( 75), UINT8_C(238), UINT8_C(237), UINT8_C( 44), UINT8_C(242), UINT8_C( 20), UINT8_C(160),
            UINT8_C( 51), UINT8_C(155), UINT8_C(199), UINT8_C(233), UINT8_C( 68), UINT8_C(183), UINT8_C(161), UINT8_C(130) },
          { UINT8_C(240), UINT8_C( 60), UINT8_C(113), UINT8_C( 92), UINT8_C(211), UINT8_C(151), UINT8_C( 59), UINT8_C( 43),
            UINT8_C( 41), UINT8_C(227), UINT8_C(249), UINT8_C(251), UINT8_C(216), UINT8_C(229), UINT8_C( 14), UINT8_C(193) },
      },
    },
    { {    UINT8_MAX, UINT8_C(206), UINT8_C(253), UINT8_C(237), UINT8_C( 63), UINT8_C(234), UINT8_C( 73), UINT8_C(107),
        UINT8_C(189), UINT8_C( 59), UINT8_C(  3), UINT8_C(209), UINT8_C(119), UINT8_C(163), UINT8_C(252), UINT8_C(170) },
      { UINT8_C(204), UINT8_C(152), UINT8_C(141), UINT8_C(147), UINT8_C(145), UINT8_C(118), UINT8_C(143), UINT8_C(213),
        UINT8_C( 79), UINT8_C( 70), UINT8_C(186), UINT8_C(240), UINT8_C( 85), UINT8_C( 60), UINT8_C(177), UINT8_C( 84) },
      {
          {    UINT8_MAX, UINT8_C(253), UINT8_C( 63), UINT8_C( 73), UINT8_C(189), UINT8_C(  3), UINT8_C(119), UINT8_C(252),
            UINT8_C(204), UINT8_C(141), UINT8_C(145), UINT8_C(143), UINT8_C( 79), UINT8_C(186), UINT8_C( 85), UINT8_C(177) },
          { UINT8_C(206), UINT8_C(237), UINT8_C(234), UINT8_C(107), UINT8_C( 59), UINT8_C(209), UINT8_C(163), UINT8_C(170),
            UINT8_C(152), UINT8_C(147), UINT8_C(118), UINT8_C(213), UINT8_C( 70), UINT8_C(240), UINT8_C( 60), UINT8_C( 84) },
      },
    },
    { { UINT8_C( 10), UINT8_C(174), UINT8_C( 65), UINT8_C( 74), UINT8_C(152), UINT8_C(139), UINT8_C(181), UINT8_C( 85),
        UINT8_C(198), UINT8_C(184), UINT8_C( 38), UINT8_C( 61), UINT8_C( 91), UINT8_C( 34), UINT8_C(231), UINT8_C( 40) },
      { UINT8_C(186), UINT8_C(117), UINT8_C(187), UINT8_C( 75), UINT8_C(235), UINT8_C( 74), UINT8_C( 32), UINT8_C( 58),
        UINT8_C(145), UINT8_C(218), UINT8_C( 42), UINT8_C(230), UINT8_C( 23), UINT8_C(219), UINT8_C( 58), UINT8_C( 33) },
      {
          { UINT8_C( 10), UINT8_C( 65), UINT8_C(152), UINT8_C(181), UINT8_C(198), UINT8_C( 38), UINT8_C( 91), UINT8_C(231),
            UINT8_C(186), UINT8_C(187), UINT8_C(235), UINT8_C( 32), UINT8_C(145), UINT8_C( 42), UINT8_C( 23), UINT8_C( 58) },
          { UINT8_C(174), UINT8_C( 74), UINT8_C(139), UINT8_C( 85), UINT8_C(184), UINT8_C( 61), UINT8_C( 34), UINT8_C( 40),
            UINT8_C(117), UINT8_C( 75), UINT8_C( 74), UINT8_C( 58), UINT8_C(218), UINT8_C(230), UINT8_C(219), UINT8_C( 33) },
      },
    },
    { { UINT8_C(137), UINT8_C(123), UINT8_C(107), UINT8_C( 33), UINT8_C(  6), UINT8_C( 33), UINT8_C(118), UINT8_C(205),
        UINT8_C(217), UINT8_C(156), UINT8_C( 10), UINT8_C( 53), UINT8_C(191), UINT8_C(242), UINT8_C( 93), UINT8_C(121) },
      { UINT8_C(103), UINT8_C( 24), UINT8_C(197), UINT8_C( 82), UINT8_C( 99), UINT8_C(229), UINT8_C(141), UINT8_C(244),
        UINT8_C(192), UINT8_C(183), UINT8_C(218), UINT8_C(215), UINT8_C(147), UINT8_C( 20), UINT8_C(248), UINT8_C( 28) },
      {
          { UINT8_C(137), UINT8_C(107), UINT8_C(  6), UINT8_C(118), UINT8_C(217), UINT8_C( 10), UINT8_C(191), UINT8_C( 93),
            UINT8_C(103), UINT8_C(197), UINT8_C( 99), UINT8_C(141), UINT8_C(192), UINT8_C(218), UINT8_C(147), UINT8_C(248) },
          { UINT8_C(123), UINT8_C( 33), UINT8_C( 33), UINT8_C(205), UINT8_C(156), UINT8_C( 53), UINT8_C(242), UINT8_C(121),
            UINT8_C( 24), UINT8_C( 82), UINT8_C(229), UINT8_C(244), UINT8_C(183), UINT8_C(215), UINT8_C( 20), UINT8_C( 28) },
      },
    },
    { { UINT8_C(143), UINT8_C(100), UINT8_C( 62), UINT8_C(150), UINT8_C(133), UINT8_C(180), UINT8_C( 99), UINT8_C( 94),
        UINT8_C( 81), UINT8_C(109), UINT8_C(147), UINT8_C( 16), UINT8_C( 95), UINT8_C(240), UINT8_C(137), UINT8_C(198) },
      { UINT8_C(  9), UINT8_C( 78), UINT8_C( 25), UINT8_C(108), UINT8_C( 52), UINT8_C(166), UINT8_C( 96), UINT8_C(244),
        UINT8_C( 93), UINT8_C( 58), UINT8_C(203), UINT8_C(240), UINT8_C( 78), UINT8_C(195), UINT8_C( 13), UINT8_C(221) },
      {
          { UINT8_C(143), UINT8_C( 62), UINT8_C(133), UINT8_C( 99), UINT8_C( 81), UINT8_C(147), UINT8_C( 95), UINT8_C(137),
            UINT8_C(  9), UINT8_C( 25), UINT8_C( 52), UINT8_C( 96), UINT8_C( 93), UINT8_C(203), UINT8_C( 78), UINT8_C( 13) },
          { UINT8_C(100), UINT8_C(150), UINT8_C(180), UINT8_C( 94), UINT8_C(109), UINT8_C( 16), UINT8_C(240), UINT8_C(198),
            UINT8_C( 78), UINT8_C(108), UINT8_C(166), UINT8_C(244), UINT8_C( 58), UINT8_C(240), UINT8_C(195), UINT8_C(221) },
      },
    },
    { { UINT8_C( 39), UINT8_C( 75), UINT8_C(115), UINT8_C(172),    UINT8_MAX, UINT8_C(214), UINT8_C( 11), UINT8_C( 80),
        UINT8_C( 68), UINT8_C(158), UINT8_C( 96), UINT8_C(163), UINT8_C(143), UINT8_C(234), UINT8_C(106), UINT8_C(152) },
      { UINT8_C( 56), UINT8_C(131), UINT8_C(  4), UINT8_C(108), UINT8_C( 41), UINT8_C(100), UINT8_C( 96), UINT8_C(134),
        UINT8_C(158), UINT8_C( 43), UINT8_C(119), UINT8_C(236), UINT8_C(239), UINT8_C(132), UINT8_C(201), UINT8_C( 22) },
      {
          { UINT8_C( 39), UINT8_C(115),    UINT8_MAX, UINT8_C( 11), UINT8_C( 68), UINT8_C( 96), UINT8_C(143), UINT8_C(106),
            UINT8_C( 56), UINT8_C(  4), UINT8_C( 41), UINT8_C( 96), UINT8_C(158), UINT8_C(119), UINT8_C(239), UINT8_C(201) },
          { UINT8_C( 75), UINT8_C(172), UINT8_C(214), UINT8_C( 80), UINT8_C(158), UINT8_C(163), UINT8_C(234), UINT8_C(152),
            UINT8_C(131), UINT8_C(108), UINT8_C(100), UINT8_C(134), UINT8_C( 43), UINT8_C(236), UINT8_C(132), UINT8_C( 22) },
      },
    },
    { { UINT8_C(207), UINT8_C( 61), UINT8_C(195), UINT8_C(206), UINT8_C( 19), UINT8_C(206), UINT8_C( 31), UINT8_C( 87),
        UINT8_C(108), UINT8_C(127), UINT8_C(251), UINT8_C(251), UINT8_C(105), UINT8_C(101), UINT8_C(147), UINT8_C(162) },
      { UINT8_C(232), UINT8_C(151), UINT8_C( 14), UINT8_C( 17), UINT8_C(251), UINT8_C(111), UINT8_C(151), UINT8_C(153),
        UINT8_C(154), UINT8_C( 14), UINT8_C(133), UINT8_C(137), UINT8_C(146), UINT8_C( 79), UINT8_C(160), UINT8_C( 97) },
      {
          { UINT8_C(207), UINT8_C(195), UINT8_C( 19), UINT8_C( 31), UINT8_C(108), UINT8_C(251), UINT8_C(105), UINT8_C(147),
            UINT8_C(232), UINT8_C( 14), UINT8_C(251), UINT8_C(151), UINT8_C(154), UINT8_C(133), UINT8_C(146), UINT8_C(160) },
          { UINT8_C( 61), UINT8_C(206), UINT8_C(206), UINT8_C( 87), UINT8_C(127), UINT8_C(251), UINT8_C(101), UINT8_C(162),
            UINT8_C(151), UINT8_C( 17), UINT8_C(111), UINT8_C(153), UINT8_C( 14), UINT8_C(137), UINT8_C( 79), UINT8_C( 97) },
      },
    },
    { { UINT8_C(140), UINT8_C( 99), UINT8_C( 48), UINT8_C(159), UINT8_C( 49), UINT8_C( 79), UINT8_C(247), UINT8_C(157),
        UINT8_C(206), UINT8_C(242), UINT8_C(153), UINT8_C( 56), UINT8_C( 87), UINT8_C( 44), UINT8_C(218), UINT8_C( 63) },
      { UINT8_C(196), UINT8_C(232), UINT8_C( 80), UINT8_C(191), UINT8_C( 87), UINT8_C(231), UINT8_C( 89), UINT8_C(242),
        UINT8_C(246), UINT8_C(222), UINT8_C(123), UINT8_C(136), UINT8_C( 45), UINT8_C( 27), UINT8_C(234), UINT8_C(185) },
      {
          { UINT8_C(140), UINT8_C( 48), UINT8_C( 49), UINT8_C(247), UINT8_C(206), UINT8_C(153), UINT8_C( 87), UINT8_C(218),
            UINT8_C(196), UINT8_C( 80), UINT8_C( 87), UINT8_C( 89), UINT8_C(246), UINT8_C(123), UINT8_C( 45), UINT8_C(234) },
          { UINT8_C( 99), UINT8_C(159), UINT8_C( 79), UINT8_C(157), UINT8_C(242), UINT8_C( 56), UINT8_C( 44), UINT8_C( 63),
            UINT8_C(232), UINT8_C(191), UINT8_C(231), UINT8_C(242), UINT8_C(222), UINT8_C(136), UINT8_C( 27), UINT8_C(185) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16x2_t r = simde_vuzpq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], simde_vld1q_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], simde_vld1q_u8(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16x2_t c = simde_vuzpq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[2][8];
  } test_vec[] = {
    { { UINT16_C(15666), UINT16_C( 9230), UINT16_C( 9080), UINT16_C(20406), UINT16_C(26210), UINT16_C( 1132), UINT16_C(52811), UINT16_C(62092) },
      { UINT16_C( 2971), UINT16_C(24403), UINT16_C(65053), UINT16_C(13489), UINT16_C(33869), UINT16_C( 3101), UINT16_C(43650), UINT16_C(46245) },
      {
          { UINT16_C(15666), UINT16_C( 9080), UINT16_C(26210), UINT16_C(52811), UINT16_C( 2971), UINT16_C(65053), UINT16_C(33869), UINT16_C(43650) },
          { UINT16_C( 9230), UINT16_C(20406), UINT16_C( 1132), UINT16_C(62092), UINT16_C(24403), UINT16_C(13489), UINT16_C( 3101), UINT16_C(46245) },
      },
    },
    { { UINT16_C(46055), UINT16_C(24536), UINT16_C(36567), UINT16_C(14766), UINT16_C( 6900), UINT16_C(16189), UINT16_C(51689), UINT16_C(33841) },
      { UINT16_C(34260), UINT16_C(61923), UINT16_C(38019), UINT16_C(53285), UINT16_C(16920), UINT16_C(39900), UINT16_C(33261), UINT16_C(54351) },
      {
          { UINT16_C(46055), UINT16_C(36567), UINT16_C( 6900), UINT16_C(51689), UINT16_C(34260), UINT16_C(38019), UINT16_C(16920), UINT16_C(33261) },
          { UINT16_C(24536), UINT16_C(14766), UINT16_C(16189), UINT16_C(33841), UINT16_C(61923), UINT16_C(53285), UINT16_C(39900), UINT16_C(54351) },
      },
    },
    { { UINT16_C(10293), UINT16_C( 3124), UINT16_C(58038), UINT16_C(43845), UINT16_C(33533), UINT16_C(59114), UINT16_C( 7243), UINT16_C( 8298) },
      { UINT16_C(19873), UINT16_C( 9233), UINT16_C(14305), UINT16_C(64244), UINT16_C(53625), UINT16_C(26261), UINT16_C(58450), UINT16_C(34619) },
      {
          { UINT16_C(10293), UINT16_C(58038), UINT16_C(33533), UINT16_C( 7243), UINT16_C(19873), UINT16_C(14305), UINT16_C(53625), UINT16_C(58450) },
          { UINT16_C( 3124), UINT16_C(43845), UINT16_C(59114), UINT16_C( 8298), UINT16_C( 9233), UINT16_C(64244), UINT16_C(26261), UINT16_C(34619) },
      },
    },
    { { UINT16_C(28428), UINT16_C(50067), UINT16_C(55377), UINT16_C(20078), UINT16_C(22618), UINT16_C(42548), UINT16_C(40564), UINT16_C( 5574) },
      { UINT16_C(55275), UINT16_C(52537), UINT16_C(11790), UINT16_C(35015), UINT16_C(23807), UINT16_C(20974), UINT16_C(10560), UINT16_C(19929) },
      {
          { UINT16_C(28428), UINT16_C(55377), UINT16_C(22618), UINT16_C(40564), UINT16_C(55275), UINT16_C(11790), UINT16_C(23807), UINT16_C(10560) },
          { UINT16_C(50067), UINT16_C(20078), UINT16_C(42548), UINT16_C( 5574), UINT16_C(52537), UINT16_C(35015), UINT16_C(20974), UINT16_C(19929) },
      },
    },
    { { UINT16_C(27800), UINT16_C(59920), UINT16_C(32325), UINT16_C(40760), UINT16_C(28118), UINT16_C(19269), UINT16_C( 2827), UINT16_C(63328) },
      { UINT16_C(39651), UINT16_C(61892), UINT16_C(35784), UINT16_C(51065), UINT16_C(26855), UINT16_C(10008), UINT16_C(61841), UINT16_C(10868) },
      {
          { UINT16_C(27800), UINT16_C(32325), UINT16_C(28118), UINT16_C( 2827), UINT16_C(39651), UINT16_C(35784), UINT16_C(26855), UINT16_C(61841) },
          { UINT16_C(59920), UINT16_C(40760), UINT16_C(19269), UINT16_C(63328), UINT16_C(61892), UINT16_C(51065), UINT16_C(10008), UINT16_C(10868) },
      },
    },
    { { UINT16_C(33886), UINT16_C(41748), UINT16_C(19458), UINT16_C(55618), UINT16_C(35001), UINT16_C(50468), UINT16_C(33939), UINT16_C(30396) },
      { UINT16_C(32798), UINT16_C(58984), UINT16_C(57611), UINT16_C(62125), UINT16_C(50761), UINT16_C(56089), UINT16_C(36535), UINT16_C( 5381) },
      {
          { UINT16_C(33886), UINT16_C(19458), UINT16_C(35001), UINT16_C(33939), UINT16_C(32798), UINT16_C(57611), UINT16_C(50761), UINT16_C(36535) },
          { UINT16_C(41748), UINT16_C(55618), UINT16_C(50468), UINT16_C(30396), UINT16_C(58984), UINT16_C(62125), UINT16_C(56089), UINT16_C( 5381) },
      },
    },
    { { UINT16_C( 6418), UINT16_C( 5560), UINT16_C(64357), UINT16_C( 8174), UINT16_C( 4739), UINT16_C( 5860), UINT16_C(41110), UINT16_C(46477) },
      { UINT16_C(62752), UINT16_C(11163), UINT16_C(18902), UINT16_C( 8221), UINT16_C(13839), UINT16_C(50939), UINT16_C(  196), UINT16_C(55260) },
      {
          { UINT16_C( 6418), UINT16_C(64357), UINT16_C( 4739), UINT16_C(41110), UINT16_C(62752), UINT16_C(18902), UINT16_C(13839), UINT16_C(  196) },
          { UINT16_C( 5560), UINT16_C( 8174), UINT16_C( 5860), UINT16_C(46477), UINT16_C(11163), UINT16_C( 8221), UINT16_C(50939), UINT16_C(55260) },
      },
    },
    { { UINT16_C(37913), UINT16_C(32492), UINT16_C(55951), UINT16_C( 4765), UINT16_C(33260), UINT16_C(33321), UINT16_C(46625), UINT16_C(16695) },
      { UINT16_C(54187), UINT16_C(33132), UINT16_C(35100), UINT16_C(11169), UINT16_C(40128), UINT16_C(34033), UINT16_C(52636), UINT16_C(46427) },
      {
          { UINT16_C(37913), UINT16_C(55951), UINT16_C(33260), UINT16_C(46625), UINT16_C(54187), UINT16_C(35100), UINT16_C(40128), UINT16_C(52636) },
          { UINT16_C(32492), UINT16_C( 4765), UINT16_C(33321), UINT16_C(16695), UINT16_C(33132), UINT16_C(11169), UINT16_C(34033), UINT16_C(46427) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8x2_t r = simde_vuzpq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r.val[0], simde_vld1q_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], simde_vld1q_u16(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8x2_t c = simde_vuzpq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[2][4];
  } test_vec[] = {
    { { UINT32_C(1622875691), UINT32_C( 117780204), UINT32_C(2996661462), UINT32_C( 959522199) },
      { UINT32_C(2276532505), UINT32_C(2007160179), UINT32_C(2433206818), UINT32_C(3600242091) },
      {
          { UINT32_C(1622875691), UINT32_C(2996661462), UINT32_C(2276532505), UINT32_C(2433206818) },
          { UINT32_C( 117780204), UINT32_C( 959522199), UINT32_C(2007160179), UINT32_C(3600242091) },
      },
    },
    { { UINT32_C(1597461107), UINT32_C(1466317953), UINT32_C(1057555368), UINT32_C(1115175465) },
      { UINT32_C(3469289819), UINT32_C( 558263295), UINT32_C(3786558774), UINT32_C( 364333730) },
      {
          { UINT32_C(1597461107), UINT32_C(1057555368), UINT32_C(3469289819), UINT32_C(3786558774) },
          { UINT32_C(1466317953), UINT32_C(1115175465), UINT32_C( 558263295), UINT32_C( 364333730) },
      },
    },
    { { UINT32_C( 494202524), UINT32_C(3530873642), UINT32_C( 118652638), UINT32_C( 340429496) },
      { UINT32_C(3017937844), UINT32_C(3050580095), UINT32_C( 395741045), UINT32_C(1831620049) },
      {
          { UINT32_C( 494202524), UINT32_C( 118652638), UINT32_C(3017937844), UINT32_C( 395741045) },
          { UINT32_C(3530873642), UINT32_C( 340429496), UINT32_C(3050580095), UINT32_C(1831620049) },
      },
    },
    { { UINT32_C(1720426812), UINT32_C(1513750396), UINT32_C( 912411517), UINT32_C(2303372501) },
      { UINT32_C(1044131007), UINT32_C(3404927317), UINT32_C(1776454040), UINT32_C( 332795607) },
      {
          { UINT32_C(1720426812), UINT32_C( 912411517), UINT32_C(1044131007), UINT32_C(1776454040) },
          { UINT32_C(1513750396), UINT32_C(2303372501), UINT32_C(3404927317), UINT32_C( 332795607) },
      },
    },
    { { UINT32_C( 729375151), UINT32_C(3733369441), UINT32_C(3541362941), UINT32_C(1398562452) },
      { UINT32_C(3767703947), UINT32_C(1118471594), UINT32_C(3870002191), UINT32_C(1257865627) },
      {
          { UINT32_C( 729375151), UINT32_C(3541362941), UINT32_C(3767703947), UINT32_C(3870002191) },
          { UINT32_C(3733369441), UINT32_C(1398562452), UINT32_C(1118471594), UINT32_C(1257865627) },
      },
    },
    { { UINT32_C(1148613347), UINT32_C( 572718117), UINT32_C(2029336548), UINT32_C( 550195861) },
      { UINT32_C(2499829227), UINT32_C(4074220515), UINT32_C(3537404471), UINT32_C(3860713731) },
      {
          { UINT32_C(1148613347), UINT32_C(2029336548), UINT32_C(2499829227), UINT32_C(3537404471) },
          { UINT32_C( 572718117), UINT32_C( 550195861), UINT32_C(4074220515), UINT32_C(3860713731) },
      },
    },
    { { UINT32_C(1747620675), UINT32_C(1938509199), UINT32_C( 434864260), UINT32_C(3174741714) },
      { UINT32_C(4149361172), UINT32_C( 501819877), UINT32_C(2951725483), UINT32_C(3583315090) },
      {
          { UINT32_C(1747620675), UINT32_C( 434864260), UINT32_C(4149361172), UINT32_C(2951725483) },
          { UINT32_C(1938509199), UINT32_C(3174741714), UINT32_C( 501819877), UINT32_C(3583315090) },
      },
    },
    { { UINT32_C( 775864479), UINT32_C(2443299085), UINT32_C( 480939081), UINT32_C(1473897539) },
      { UINT32_C(  72231967), UINT32_C(  18954069), UINT32_C(2326794744), UINT32_C(3177137437) },
      {
          { UINT32_C( 775864479), UINT32_C( 480939081), UINT32_C(  72231967), UINT32_C(2326794744) },
          { UINT32_C(2443299085), UINT32_C(1473897539), UINT32_C(  18954069), UINT32_C(3177137437) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4x2_t r = simde_vuzpq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], simde_vld1q_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], simde_vld1q_u32(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4x2_t c = simde_vuzpq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[8];
    simde_poly8_t b[8];
    simde_poly8_t r[2][8];
  } test_vec[] = {
    { { SIMDE_POLY8_C(221), SIMDE_POLY8_C(128), SIMDE_POLY8_C(185), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(201), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(240) },
      { SIMDE_POLY8_C(182), SIMDE_POLY8_C(179), SIMDE_POLY8_C(131), SIMDE_POLY8_C(144), SIMDE_POLY8_C( 26), SIMDE_POLY8_C(213), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(116) },
      {
          { SIMDE_POLY8_C(221), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 80), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(182), SIMDE_POLY8_C(131), SIMDE_POLY8_C( 26), SIMDE_POLY8_C( 46) },
          { SIMDE_POLY8_C(128), SIMDE_POLY8_C(185), SIMDE_POLY8_C(201), SIMDE_POLY8_C(240), SIMDE_POLY8_C(179), SIMDE_POLY8_C(144), SIMDE_POLY8_C(213), SIMDE_POLY8_C(116) },
      },
    },
    { { SIMDE_POLY8_C(128), SIMDE_POLY8_C(109), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(134), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(237), SIMDE_POLY8_C(242) },
      { SIMDE_POLY8_C(198), SIMDE_POLY8_C(216), SIMDE_POLY8_C(134), SIMDE_POLY8_C(196), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(141), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 24) },
      {
          { SIMDE_POLY8_C(128), SIMDE_POLY8_C(182), SIMDE_POLY8_C(134), SIMDE_POLY8_C(237), SIMDE_POLY8_C(198), SIMDE_POLY8_C(134), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(156) },
          { SIMDE_POLY8_C(109), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(242), SIMDE_POLY8_C(216), SIMDE_POLY8_C(196), SIMDE_POLY8_C(141), SIMDE_POLY8_C( 24) },
      },
    },
    { { SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(209), SIMDE_POLY8_C( 94), SIMDE_POLY8_C( 31), SIMDE_POLY8_C(225), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(213) },
      { SIMDE_POLY8_C(148), SIMDE_POLY8_C(210), SIMDE_POLY8_C(101), SIMDE_POLY8_C(174), SIMDE_POLY8_C(167), SIMDE_POLY8_C(148), SIMDE_POLY8_C( 34), SIMDE_POLY8_C( 39) },
      {
          { SIMDE_POLY8_C( 14), SIMDE_POLY8_C(209), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(148), SIMDE_POLY8_C(101), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 34) },
          { SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(225), SIMDE_POLY8_C(213), SIMDE_POLY8_C(210), SIMDE_POLY8_C(174), SIMDE_POLY8_C(148), SIMDE_POLY8_C( 39) },
      },
    },
    { { SIMDE_POLY8_C(  1), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(135), SIMDE_POLY8_C(234), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(121), SIMDE_POLY8_C(176) },
      { SIMDE_POLY8_C(  2), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(116), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(141), SIMDE_POLY8_C( 16), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(155) },
      {
          { SIMDE_POLY8_C(  1), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(234), SIMDE_POLY8_C(121), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(116), SIMDE_POLY8_C(141), SIMDE_POLY8_C( 86) },
          { SIMDE_POLY8_C(217), SIMDE_POLY8_C(135), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(176), SIMDE_POLY8_C(  0), SIMDE_POLY8_C( 62), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(155) },
      },
    },
    { { SIMDE_POLY8_C(102), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(249), SIMDE_POLY8_C(133), SIMDE_POLY8_C(  9), SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(158) },
      { SIMDE_POLY8_C( 26), SIMDE_POLY8_C(192), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(193), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(111), SIMDE_POLY8_C(232), SIMDE_POLY8_C( 85) },
      {
          { SIMDE_POLY8_C(102), SIMDE_POLY8_C(249), SIMDE_POLY8_C(  9), SIMDE_POLY8_C( 90), SIMDE_POLY8_C( 26), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(232) },
          { SIMDE_POLY8_C( 40), SIMDE_POLY8_C(133), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(158), SIMDE_POLY8_C(192), SIMDE_POLY8_C(193), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 85) },
      },
    },
    { { SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(220), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 79), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(226), SIMDE_POLY8_C( 81) },
      { SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(143), SIMDE_POLY8_C(227), SIMDE_POLY8_C(103), SIMDE_POLY8_C(230), SIMDE_POLY8_C(127), SIMDE_POLY8_C(205) },
      {
          { SIMDE_POLY8_C( 72), SIMDE_POLY8_C(220), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(226), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(143), SIMDE_POLY8_C(103), SIMDE_POLY8_C(127) },
          { SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 81), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(227), SIMDE_POLY8_C(230), SIMDE_POLY8_C(205) },
      },
    },
    { { SIMDE_POLY8_C( 14), SIMDE_POLY8_C(120), SIMDE_POLY8_C( 82), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(192), SIMDE_POLY8_C(172), SIMDE_POLY8_C(181), SIMDE_POLY8_C(218) },
      { SIMDE_POLY8_C(108), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(155), SIMDE_POLY8_C(192), SIMDE_POLY8_C(113), SIMDE_POLY8_C(132), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(185) },
      {
          { SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(192), SIMDE_POLY8_C(181), SIMDE_POLY8_C(108), SIMDE_POLY8_C(155), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 21) },
          { SIMDE_POLY8_C(120), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(172), SIMDE_POLY8_C(218), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(192), SIMDE_POLY8_C(132), SIMDE_POLY8_C(185) },
      },
    },
    { { SIMDE_POLY8_C(169), SIMDE_POLY8_C(242), SIMDE_POLY8_C(235), SIMDE_POLY8_C(248), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(205), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(158) },
      { SIMDE_POLY8_C( 35), SIMDE_POLY8_C(217), SIMDE_POLY8_C(129), SIMDE_POLY8_C(138), SIMDE_POLY8_C(191), SIMDE_POLY8_C(  0), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(205) },
      {
          { SIMDE_POLY8_C(169), SIMDE_POLY8_C(235), SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 35), SIMDE_POLY8_C(129), SIMDE_POLY8_C(191), SIMDE_POLY8_C( 87) },
          { SIMDE_POLY8_C(242), SIMDE_POLY8_C(248), SIMDE_POLY8_C(205), SIMDE_POLY8_C(158), SIMDE_POLY8_C(217), SIMDE_POLY8_C(138), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(205) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);
    simde_poly8x8x2_t r = simde_vuzp_p8(a, b);

    simde_test_arm_neon_assert_equal_p8x8(r.val[0], simde_vld1_p8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_p8x8(r.val[1], simde_vld1_p8(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8_t a = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t b = simde_test_arm_neon_random_p8x8();
    simde_poly8x8x2_t c = simde_vuzp_p8(a, b);

    simde_test_arm_neon_write_p8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[4];
    simde_poly16_t b[4];
    simde_poly16_t r[2][4];
  } test_vec[] = {
    { { SIMDE_POLY16_C(53183), SIMDE_POLY16_C( 8344), SIMDE_POLY16_C(47465), SIMDE_POLY16_C(51179) },
      { SIMDE_POLY16_C(23788), SIMDE_POLY16_C( 1786), SIMDE_POLY16_C(23927), SIMDE_POLY16_C(30761) },
      {
          { SIMDE_POLY16_C(53183), SIMDE_POLY16_C(47465), SIMDE_POLY16_C(23788), SIMDE_POLY16_C(23927) },
          { SIMDE_POLY16_C( 8344), SIMDE_POLY16_C(51179), SIMDE_POLY16_C( 1786), SIMDE_POLY16_C(30761) },
      },
    },
    { { SIMDE_POLY16_C(50756), SIMDE_POLY16_C(22956), SIMDE_POLY16_C( 7637), SIMDE_POLY16_C(43027) },
      { SIMDE_POLY16_C(20916), SIMDE_POLY16_C(48634), SIMDE_POLY16_C(  346), SIMDE_POLY16_C( 6692) },
      {
          { SIMDE_POLY16_C(50756), SIMDE_POLY16_C( 7637), SIMDE_POLY16_C(20916), SIMDE_POLY16_C(  346) },
          { SIMDE_POLY16_C(22956), SIMDE_POLY16_C(43027), SIMDE_POLY16_C(48634), SIMDE_POLY16_C( 6692) },
      },
    },
    { { SIMDE_POLY16_C(48336), SIMDE_POLY16_C(14650), SIMDE_POLY16_C( 9590), SIMDE_POLY16_C(25089) },
      { SIMDE_POLY16_C(64386), SIMDE_POLY16_C(63848), SIMDE_POLY16_C(37209), SIMDE_POLY16_C(40306) },
      {
          { SIMDE_POLY16_C(48336), SIMDE_POLY16_C( 9590), SIMDE_POLY16_C(64386), SIMDE_POLY16_C(37209) },
          { SIMDE_POLY16_C(14650), SIMDE_POLY16_C(25089), SIMDE_POLY16_C(63848), SIMDE_POLY16_C(40306) },
      },
    },
    { { SIMDE_POLY16_C( 7768), SIMDE_POLY16_C(11767), SIMDE_POLY16_C( 2619), SIMDE_POLY16_C(61397) },
      { SIMDE_POLY16_C(53340), SIMDE_POLY16_C(46765), SIMDE_POLY16_C(53713), SIMDE_POLY16_C(41424) },
      {
          { SIMDE_POLY16_C( 7768), SIMDE_POLY16_C( 2619), SIMDE_POLY16_C(53340), SIMDE_POLY16_C(53713) },
          { SIMDE_POLY16_C(11767), SIMDE_POLY16_C(61397), SIMDE_POLY16_C(46765), SIMDE_POLY16_C(41424) },
      },
    },
    { { SIMDE_POLY16_C( 2701), SIMDE_POLY16_C(  986), SIMDE_POLY16_C(56112), SIMDE_POLY16_C(45669) },
      { SIMDE_POLY16_C(52951), SIMDE_POLY16_C(12459), SIMDE_POLY16_C( 7519), SIMDE_POLY16_C(47053) },
      {
          { SIMDE_POLY16_C( 2701), SIMDE_POLY16_C(56112), SIMDE_POLY16_C(52951), SIMDE_POLY16_C( 7519) },
          { SIMDE_POLY16_C(  986), SIMDE_POLY16_C(45669), SIMDE_POLY16_C(12459), SIMDE_POLY16_C(47053) },
      },
    },
    { { SIMDE_POLY16_C(50235), SIMDE_POLY16_C(30692), SIMDE_POLY16_C(47823), SIMDE_POLY16_C(11110) },
      { SIMDE_POLY16_C( 5002), SIMDE_POLY16_C(23521), SIMDE_POLY16_C(45796), SIMDE_POLY16_C(29436) },
      {
          { SIMDE_POLY16_C(50235), SIMDE_POLY16_C(47823), SIMDE_POLY16_C( 5002), SIMDE_POLY16_C(45796) },
          { SIMDE_POLY16_C(30692), SIMDE_POLY16_C(11110), SIMDE_POLY16_C(23521), SIMDE_POLY16_C(29436) },
      },
    },
    { { SIMDE_POLY16_C(54972), SIMDE_POLY16_C(60533), SIMDE_POLY16_C(56242), SIMDE_POLY16_C(35230) },
      { SIMDE_POLY16_C(19113), SIMDE_POLY16_C( 2233), SIMDE_POLY16_C(34407), SIMDE_POLY16_C(41920) },
      {
          { SIMDE_POLY16_C(54972), SIMDE_POLY16_C(56242), SIMDE_POLY16_C(19113), SIMDE_POLY16_C(34407) },
          { SIMDE_POLY16_C(60533), SIMDE_POLY16_C(35230), SIMDE_POLY16_C( 2233), SIMDE_POLY16_C(41920) },
      },
    },
    { { SIMDE_POLY16_C(42059), SIMDE_POLY16_C( 6682), SIMDE_POLY16_C(32862), SIMDE_POLY16_C(59461) },
      { SIMDE_POLY16_C( 9876), SIMDE_POLY16_C(30787), SIMDE_POLY16_C(16344), SIMDE_POLY16_C(38378) },
      {
          { SIMDE_POLY16_C(42059), SIMDE_POLY16_C(32862), SIMDE_POLY16_C( 9876), SIMDE_POLY16_C(16344) },
          { SIMDE_POLY16_C( 6682), SIMDE_POLY16_C(59461), SIMDE_POLY16_C(30787), SIMDE_POLY16_C(38378) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);
    simde_poly16x4x2_t r = simde_vuzp_p16(a, b);
    simde_test_arm_neon_assert_equal_p16x4(r.val[0], simde_vld1_p16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_p16x4(r.val[1], simde_vld1_p16(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x4_t a = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t b = simde_test_arm_neon_random_p16x4();
    simde_poly16x4x2_t c = simde_vuzp_p16(a, b);

    simde_test_arm_neon_write_p16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[16];
    simde_poly8_t b[16];
    simde_poly8_t r[2][16];
  } test_vec[] = {
    { { SIMDE_POLY8_C( 32), SIMDE_POLY8_C(240), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(238), SIMDE_POLY8_C(113), SIMDE_POLY8_C(237), SIMDE_POLY8_C( 92),
        SIMDE_POLY8_C( 44), SIMDE_POLY8_C(211), SIMDE_POLY8_C(242), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(160), SIMDE_POLY8_C( 43) },
      { SIMDE_POLY8_C( 51), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(155), SIMDE_POLY8_C(227), SIMDE_POLY8_C(199), SIMDE_POLY8_C(249), SIMDE_POLY8_C(233), SIMDE_POLY8_C(251),
        SIMDE_POLY8_C( 68), SIMDE_POLY8_C(216), SIMDE_POLY8_C(183), SIMDE_POLY8_C(229), SIMDE_POLY8_C(161), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(130), SIMDE_POLY8_C(193) },
      {
          { SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 75), SIMDE_POLY8_C(238), SIMDE_POLY8_C(237), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(160),
            SIMDE_POLY8_C( 51), SIMDE_POLY8_C(155), SIMDE_POLY8_C(199), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 68), SIMDE_POLY8_C(183), SIMDE_POLY8_C(161), SIMDE_POLY8_C(130) },
          { SIMDE_POLY8_C(240), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 92), SIMDE_POLY8_C(211), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 43),
            SIMDE_POLY8_C( 41), SIMDE_POLY8_C(227), SIMDE_POLY8_C(249), SIMDE_POLY8_C(251), SIMDE_POLY8_C(216), SIMDE_POLY8_C(229), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(193) },
      },
    },
    { {    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C(206), SIMDE_POLY8_C(253), SIMDE_POLY8_C(237), SIMDE_POLY8_C( 63), SIMDE_POLY8_C(234), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(107),
        SIMDE_POLY8_C(189), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(209), SIMDE_POLY8_C(119), SIMDE_POLY8_C(163), SIMDE_POLY8_C(252), SIMDE_POLY8_C(170) },
      { SIMDE_POLY8_C(204), SIMDE_POLY8_C(152), SIMDE_POLY8_C(141), SIMDE_POLY8_C(147), SIMDE_POLY8_C(145), SIMDE_POLY8_C(118), SIMDE_POLY8_C(143), SIMDE_POLY8_C(213),
        SIMDE_POLY8_C( 79), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(186), SIMDE_POLY8_C(240), SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(177), SIMDE_POLY8_C( 84) },
      {
          {    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C(253), SIMDE_POLY8_C( 63), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(189), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(119), SIMDE_POLY8_C(252),
            SIMDE_POLY8_C(204), SIMDE_POLY8_C(141), SIMDE_POLY8_C(145), SIMDE_POLY8_C(143), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(186), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(177) },
          { SIMDE_POLY8_C(206), SIMDE_POLY8_C(237), SIMDE_POLY8_C(234), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(209), SIMDE_POLY8_C(163), SIMDE_POLY8_C(170),
            SIMDE_POLY8_C(152), SIMDE_POLY8_C(147), SIMDE_POLY8_C(118), SIMDE_POLY8_C(213), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(240), SIMDE_POLY8_C( 60), SIMDE_POLY8_C( 84) },
      },
    },
    { { SIMDE_POLY8_C( 10), SIMDE_POLY8_C(174), SIMDE_POLY8_C( 65), SIMDE_POLY8_C( 74), SIMDE_POLY8_C(152), SIMDE_POLY8_C(139), SIMDE_POLY8_C(181), SIMDE_POLY8_C( 85),
        SIMDE_POLY8_C(198), SIMDE_POLY8_C(184), SIMDE_POLY8_C( 38), SIMDE_POLY8_C( 61), SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(231), SIMDE_POLY8_C( 40) },
      { SIMDE_POLY8_C(186), SIMDE_POLY8_C(117), SIMDE_POLY8_C(187), SIMDE_POLY8_C( 75), SIMDE_POLY8_C(235), SIMDE_POLY8_C( 74), SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 58),
        SIMDE_POLY8_C(145), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(219), SIMDE_POLY8_C( 58), SIMDE_POLY8_C( 33) },
      {
          { SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 65), SIMDE_POLY8_C(152), SIMDE_POLY8_C(181), SIMDE_POLY8_C(198), SIMDE_POLY8_C( 38), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(231),
            SIMDE_POLY8_C(186), SIMDE_POLY8_C(187), SIMDE_POLY8_C(235), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 42), SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 58) },
          { SIMDE_POLY8_C(174), SIMDE_POLY8_C( 74), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(184), SIMDE_POLY8_C( 61), SIMDE_POLY8_C( 34), SIMDE_POLY8_C( 40),
            SIMDE_POLY8_C(117), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 74), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(218), SIMDE_POLY8_C(230), SIMDE_POLY8_C(219), SIMDE_POLY8_C( 33) },
      },
    },
    { { SIMDE_POLY8_C(137), SIMDE_POLY8_C(123), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(118), SIMDE_POLY8_C(205),
        SIMDE_POLY8_C(217), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(191), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 93), SIMDE_POLY8_C(121) },
      { SIMDE_POLY8_C(103), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(197), SIMDE_POLY8_C( 82), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(229), SIMDE_POLY8_C(141), SIMDE_POLY8_C(244),
        SIMDE_POLY8_C(192), SIMDE_POLY8_C(183), SIMDE_POLY8_C(218), SIMDE_POLY8_C(215), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(248), SIMDE_POLY8_C( 28) },
      {
          { SIMDE_POLY8_C(137), SIMDE_POLY8_C(107), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(118), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(191), SIMDE_POLY8_C( 93),
            SIMDE_POLY8_C(103), SIMDE_POLY8_C(197), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(141), SIMDE_POLY8_C(192), SIMDE_POLY8_C(218), SIMDE_POLY8_C(147), SIMDE_POLY8_C(248) },
          { SIMDE_POLY8_C(123), SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(205), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(242), SIMDE_POLY8_C(121),
            SIMDE_POLY8_C( 24), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(229), SIMDE_POLY8_C(244), SIMDE_POLY8_C(183), SIMDE_POLY8_C(215), SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 28) },
      },
    },
    { { SIMDE_POLY8_C(143), SIMDE_POLY8_C(100), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(150), SIMDE_POLY8_C(133), SIMDE_POLY8_C(180), SIMDE_POLY8_C( 99), SIMDE_POLY8_C( 94),
        SIMDE_POLY8_C( 81), SIMDE_POLY8_C(109), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 16), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(240), SIMDE_POLY8_C(137), SIMDE_POLY8_C(198) },
      { SIMDE_POLY8_C(  9), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(108), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(166), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(244),
        SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(203), SIMDE_POLY8_C(240), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(195), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(221) },
      {
          { SIMDE_POLY8_C(143), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(133), SIMDE_POLY8_C( 99), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(137),
            SIMDE_POLY8_C(  9), SIMDE_POLY8_C( 25), SIMDE_POLY8_C( 52), SIMDE_POLY8_C( 96), SIMDE_POLY8_C( 93), SIMDE_POLY8_C(203), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 13) },
          { SIMDE_POLY8_C(100), SIMDE_POLY8_C(150), SIMDE_POLY8_C(180), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(109), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(240), SIMDE_POLY8_C(198),
            SIMDE_POLY8_C( 78), SIMDE_POLY8_C(108), SIMDE_POLY8_C(166), SIMDE_POLY8_C(244), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(240), SIMDE_POLY8_C(195), SIMDE_POLY8_C(221) },
      },
    },
    { { SIMDE_POLY8_C( 39), SIMDE_POLY8_C( 75), SIMDE_POLY8_C(115), SIMDE_POLY8_C(172),    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C(214), SIMDE_POLY8_C( 11), SIMDE_POLY8_C( 80),
        SIMDE_POLY8_C( 68), SIMDE_POLY8_C(158), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(163), SIMDE_POLY8_C(143), SIMDE_POLY8_C(234), SIMDE_POLY8_C(106), SIMDE_POLY8_C(152) },
      { SIMDE_POLY8_C( 56), SIMDE_POLY8_C(131), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(108), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(100), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(134),
        SIMDE_POLY8_C(158), SIMDE_POLY8_C( 43), SIMDE_POLY8_C(119), SIMDE_POLY8_C(236), SIMDE_POLY8_C(239), SIMDE_POLY8_C(132), SIMDE_POLY8_C(201), SIMDE_POLY8_C( 22) },
      {
          { SIMDE_POLY8_C( 39), SIMDE_POLY8_C(115),    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C( 11), SIMDE_POLY8_C( 68), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(143), SIMDE_POLY8_C(106),
            SIMDE_POLY8_C( 56), SIMDE_POLY8_C(  4), SIMDE_POLY8_C( 41), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(158), SIMDE_POLY8_C(119), SIMDE_POLY8_C(239), SIMDE_POLY8_C(201) },
          { SIMDE_POLY8_C( 75), SIMDE_POLY8_C(172), SIMDE_POLY8_C(214), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(158), SIMDE_POLY8_C(163), SIMDE_POLY8_C(234), SIMDE_POLY8_C(152),
            SIMDE_POLY8_C(131), SIMDE_POLY8_C(108), SIMDE_POLY8_C(100), SIMDE_POLY8_C(134), SIMDE_POLY8_C( 43), SIMDE_POLY8_C(236), SIMDE_POLY8_C(132), SIMDE_POLY8_C( 22) },
      },
    },
    { { SIMDE_POLY8_C(207), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(195), SIMDE_POLY8_C(206), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(206), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 87),
        SIMDE_POLY8_C(108), SIMDE_POLY8_C(127), SIMDE_POLY8_C(251), SIMDE_POLY8_C(251), SIMDE_POLY8_C(105), SIMDE_POLY8_C(101), SIMDE_POLY8_C(147), SIMDE_POLY8_C(162) },
      { SIMDE_POLY8_C(232), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(251), SIMDE_POLY8_C(111), SIMDE_POLY8_C(151), SIMDE_POLY8_C(153),
        SIMDE_POLY8_C(154), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(133), SIMDE_POLY8_C(137), SIMDE_POLY8_C(146), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(160), SIMDE_POLY8_C( 97) },
      {
          { SIMDE_POLY8_C(207), SIMDE_POLY8_C(195), SIMDE_POLY8_C( 19), SIMDE_POLY8_C( 31), SIMDE_POLY8_C(108), SIMDE_POLY8_C(251), SIMDE_POLY8_C(105), SIMDE_POLY8_C(147),
            SIMDE_POLY8_C(232), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(251), SIMDE_POLY8_C(151), SIMDE_POLY8_C(154), SIMDE_POLY8_C(133), SIMDE_POLY8_C(146), SIMDE_POLY8_C(160) },
          { SIMDE_POLY8_C( 61), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(127), SIMDE_POLY8_C(251), SIMDE_POLY8_C(101), SIMDE_POLY8_C(162),
            SIMDE_POLY8_C(151), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(111), SIMDE_POLY8_C(153), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(137), SIMDE_POLY8_C( 79), SIMDE_POLY8_C( 97) },
      },
    },
    { { SIMDE_POLY8_C(140), SIMDE_POLY8_C( 99), SIMDE_POLY8_C( 48), SIMDE_POLY8_C(159), SIMDE_POLY8_C( 49), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(247), SIMDE_POLY8_C(157),
        SIMDE_POLY8_C(206), SIMDE_POLY8_C(242), SIMDE_POLY8_C(153), SIMDE_POLY8_C( 56), SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 63) },
      { SIMDE_POLY8_C(196), SIMDE_POLY8_C(232), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(191), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(231), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(242),
        SIMDE_POLY8_C(246), SIMDE_POLY8_C(222), SIMDE_POLY8_C(123), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(234), SIMDE_POLY8_C(185) },
      {
          { SIMDE_POLY8_C(140), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(247), SIMDE_POLY8_C(206), SIMDE_POLY8_C(153), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(218),
            SIMDE_POLY8_C(196), SIMDE_POLY8_C( 80), SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(246), SIMDE_POLY8_C(123), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(234) },
          { SIMDE_POLY8_C( 99), SIMDE_POLY8_C(159), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(157), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 56), SIMDE_POLY8_C( 44), SIMDE_POLY8_C( 63),
            SIMDE_POLY8_C(232), SIMDE_POLY8_C(191), SIMDE_POLY8_C(231), SIMDE_POLY8_C(242), SIMDE_POLY8_C(222), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(185) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);
    simde_poly8x16x2_t r = simde_vuzpq_p8(a, b);

    simde_test_arm_neon_assert_equal_p8x16(r.val[0], simde_vld1q_p8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_p8x16(r.val[1], simde_vld1q_p8(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t b = simde_test_arm_neon_random_p8x16();
    simde_poly8x16x2_t c = simde_vuzpq_p8(a, b);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzpq_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[8];
    simde_poly16_t b[8];
    simde_poly16_t r[2][8];
  } test_vec[] = {
    { { SIMDE_POLY16_C(15666), SIMDE_POLY16_C( 9230), SIMDE_POLY16_C( 9080), SIMDE_POLY16_C(20406), SIMDE_POLY16_C(26210), SIMDE_POLY16_C( 1132), SIMDE_POLY16_C(52811), SIMDE_POLY16_C(62092) },
      { SIMDE_POLY16_C( 2971), SIMDE_POLY16_C(24403), SIMDE_POLY16_C(65053), SIMDE_POLY16_C(13489), SIMDE_POLY16_C(33869), SIMDE_POLY16_C( 3101), SIMDE_POLY16_C(43650), SIMDE_POLY16_C(46245) },
      {
          { SIMDE_POLY16_C(15666), SIMDE_POLY16_C( 9080), SIMDE_POLY16_C(26210), SIMDE_POLY16_C(52811), SIMDE_POLY16_C( 2971), SIMDE_POLY16_C(65053), SIMDE_POLY16_C(33869), SIMDE_POLY16_C(43650) },
          { SIMDE_POLY16_C( 9230), SIMDE_POLY16_C(20406), SIMDE_POLY16_C( 1132), SIMDE_POLY16_C(62092), SIMDE_POLY16_C(24403), SIMDE_POLY16_C(13489), SIMDE_POLY16_C( 3101), SIMDE_POLY16_C(46245) },
      },
    },
    { { SIMDE_POLY16_C(46055), SIMDE_POLY16_C(24536), SIMDE_POLY16_C(36567), SIMDE_POLY16_C(14766), SIMDE_POLY16_C( 6900), SIMDE_POLY16_C(16189), SIMDE_POLY16_C(51689), SIMDE_POLY16_C(33841) },
      { SIMDE_POLY16_C(34260), SIMDE_POLY16_C(61923), SIMDE_POLY16_C(38019), SIMDE_POLY16_C(53285), SIMDE_POLY16_C(16920), SIMDE_POLY16_C(39900), SIMDE_POLY16_C(33261), SIMDE_POLY16_C(54351) },
      {
          { SIMDE_POLY16_C(46055), SIMDE_POLY16_C(36567), SIMDE_POLY16_C( 6900), SIMDE_POLY16_C(51689), SIMDE_POLY16_C(34260), SIMDE_POLY16_C(38019), SIMDE_POLY16_C(16920), SIMDE_POLY16_C(33261) },
          { SIMDE_POLY16_C(24536), SIMDE_POLY16_C(14766), SIMDE_POLY16_C(16189), SIMDE_POLY16_C(33841), SIMDE_POLY16_C(61923), SIMDE_POLY16_C(53285), SIMDE_POLY16_C(39900), SIMDE_POLY16_C(54351) },
      },
    },
    { { SIMDE_POLY16_C(10293), SIMDE_POLY16_C( 3124), SIMDE_POLY16_C(58038), SIMDE_POLY16_C(43845), SIMDE_POLY16_C(33533), SIMDE_POLY16_C(59114), SIMDE_POLY16_C( 7243), SIMDE_POLY16_C( 8298) },
      { SIMDE_POLY16_C(19873), SIMDE_POLY16_C( 9233), SIMDE_POLY16_C(14305), SIMDE_POLY16_C(64244), SIMDE_POLY16_C(53625), SIMDE_POLY16_C(26261), SIMDE_POLY16_C(58450), SIMDE_POLY16_C(34619) },
      {
          { SIMDE_POLY16_C(10293), SIMDE_POLY16_C(58038), SIMDE_POLY16_C(33533), SIMDE_POLY16_C( 7243), SIMDE_POLY16_C(19873), SIMDE_POLY16_C(14305), SIMDE_POLY16_C(53625), SIMDE_POLY16_C(58450) },
          { SIMDE_POLY16_C( 3124), SIMDE_POLY16_C(43845), SIMDE_POLY16_C(59114), SIMDE_POLY16_C( 8298), SIMDE_POLY16_C( 9233), SIMDE_POLY16_C(64244), SIMDE_POLY16_C(26261), SIMDE_POLY16_C(34619) },
      },
    },
    { { SIMDE_POLY16_C(28428), SIMDE_POLY16_C(50067), SIMDE_POLY16_C(55377), SIMDE_POLY16_C(20078), SIMDE_POLY16_C(22618), SIMDE_POLY16_C(42548), SIMDE_POLY16_C(40564), SIMDE_POLY16_C( 5574) },
      { SIMDE_POLY16_C(55275), SIMDE_POLY16_C(52537), SIMDE_POLY16_C(11790), SIMDE_POLY16_C(35015), SIMDE_POLY16_C(23807), SIMDE_POLY16_C(20974), SIMDE_POLY16_C(10560), SIMDE_POLY16_C(19929) },
      {
          { SIMDE_POLY16_C(28428), SIMDE_POLY16_C(55377), SIMDE_POLY16_C(22618), SIMDE_POLY16_C(40564), SIMDE_POLY16_C(55275), SIMDE_POLY16_C(11790), SIMDE_POLY16_C(23807), SIMDE_POLY16_C(10560) },
          { SIMDE_POLY16_C(50067), SIMDE_POLY16_C(20078), SIMDE_POLY16_C(42548), SIMDE_POLY16_C( 5574), SIMDE_POLY16_C(52537), SIMDE_POLY16_C(35015), SIMDE_POLY16_C(20974), SIMDE_POLY16_C(19929) },
      },
    },
    { { SIMDE_POLY16_C(27800), SIMDE_POLY16_C(59920), SIMDE_POLY16_C(32325), SIMDE_POLY16_C(40760), SIMDE_POLY16_C(28118), SIMDE_POLY16_C(19269), SIMDE_POLY16_C( 2827), SIMDE_POLY16_C(63328) },
      { SIMDE_POLY16_C(39651), SIMDE_POLY16_C(61892), SIMDE_POLY16_C(35784), SIMDE_POLY16_C(51065), SIMDE_POLY16_C(26855), SIMDE_POLY16_C(10008), SIMDE_POLY16_C(61841), SIMDE_POLY16_C(10868) },
      {
          { SIMDE_POLY16_C(27800), SIMDE_POLY16_C(32325), SIMDE_POLY16_C(28118), SIMDE_POLY16_C( 2827), SIMDE_POLY16_C(39651), SIMDE_POLY16_C(35784), SIMDE_POLY16_C(26855), SIMDE_POLY16_C(61841) },
          { SIMDE_POLY16_C(59920), SIMDE_POLY16_C(40760), SIMDE_POLY16_C(19269), SIMDE_POLY16_C(63328), SIMDE_POLY16_C(61892), SIMDE_POLY16_C(51065), SIMDE_POLY16_C(10008), SIMDE_POLY16_C(10868) },
      },
    },
    { { SIMDE_POLY16_C(33886), SIMDE_POLY16_C(41748), SIMDE_POLY16_C(19458), SIMDE_POLY16_C(55618), SIMDE_POLY16_C(35001), SIMDE_POLY16_C(50468), SIMDE_POLY16_C(33939), SIMDE_POLY16_C(30396) },
      { SIMDE_POLY16_C(32798), SIMDE_POLY16_C(58984), SIMDE_POLY16_C(57611), SIMDE_POLY16_C(62125), SIMDE_POLY16_C(50761), SIMDE_POLY16_C(56089), SIMDE_POLY16_C(36535), SIMDE_POLY16_C( 5381) },
      {
          { SIMDE_POLY16_C(33886), SIMDE_POLY16_C(19458), SIMDE_POLY16_C(35001), SIMDE_POLY16_C(33939), SIMDE_POLY16_C(32798), SIMDE_POLY16_C(57611), SIMDE_POLY16_C(50761), SIMDE_POLY16_C(36535) },
          { SIMDE_POLY16_C(41748), SIMDE_POLY16_C(55618), SIMDE_POLY16_C(50468), SIMDE_POLY16_C(30396), SIMDE_POLY16_C(58984), SIMDE_POLY16_C(62125), SIMDE_POLY16_C(56089), SIMDE_POLY16_C( 5381) },
      },
    },
    { { SIMDE_POLY16_C( 6418), SIMDE_POLY16_C( 5560), SIMDE_POLY16_C(64357), SIMDE_POLY16_C( 8174), SIMDE_POLY16_C( 4739), SIMDE_POLY16_C( 5860), SIMDE_POLY16_C(41110), SIMDE_POLY16_C(46477) },
      { SIMDE_POLY16_C(62752), SIMDE_POLY16_C(11163), SIMDE_POLY16_C(18902), SIMDE_POLY16_C( 8221), SIMDE_POLY16_C(13839), SIMDE_POLY16_C(50939), SIMDE_POLY16_C(  196), SIMDE_POLY16_C(55260) },
      {
          { SIMDE_POLY16_C( 6418), SIMDE_POLY16_C(64357), SIMDE_POLY16_C( 4739), SIMDE_POLY16_C(41110), SIMDE_POLY16_C(62752), SIMDE_POLY16_C(18902), SIMDE_POLY16_C(13839), SIMDE_POLY16_C(  196) },
          { SIMDE_POLY16_C( 5560), SIMDE_POLY16_C( 8174), SIMDE_POLY16_C( 5860), SIMDE_POLY16_C(46477), SIMDE_POLY16_C(11163), SIMDE_POLY16_C( 8221), SIMDE_POLY16_C(50939), SIMDE_POLY16_C(55260) },
      },
    },
    { { SIMDE_POLY16_C(37913), SIMDE_POLY16_C(32492), SIMDE_POLY16_C(55951), SIMDE_POLY16_C( 4765), SIMDE_POLY16_C(33260), SIMDE_POLY16_C(33321), SIMDE_POLY16_C(46625), SIMDE_POLY16_C(16695) },
      { SIMDE_POLY16_C(54187), SIMDE_POLY16_C(33132), SIMDE_POLY16_C(35100), SIMDE_POLY16_C(11169), SIMDE_POLY16_C(40128), SIMDE_POLY16_C(34033), SIMDE_POLY16_C(52636), SIMDE_POLY16_C(46427) },
      {
          { SIMDE_POLY16_C(37913), SIMDE_POLY16_C(55951), SIMDE_POLY16_C(33260), SIMDE_POLY16_C(46625), SIMDE_POLY16_C(54187), SIMDE_POLY16_C(35100), SIMDE_POLY16_C(40128), SIMDE_POLY16_C(52636) },
          { SIMDE_POLY16_C(32492), SIMDE_POLY16_C( 4765), SIMDE_POLY16_C(33321), SIMDE_POLY16_C(16695), SIMDE_POLY16_C(33132), SIMDE_POLY16_C(11169), SIMDE_POLY16_C(34033), SIMDE_POLY16_C(46427) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);
    simde_poly16x8x2_t r = simde_vuzpq_p16(a, b);
    simde_test_arm_neon_assert_equal_p16x8(r.val[0], simde_vld1q_p16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_p16x8(r.val[1], simde_vld1q_p16(test_vec[i].r[1]));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t b = simde_test_arm_neon_random_p16x8();
    simde_poly16x8x2_t c = simde_vuzpq_p16(a, b);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8x2(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_p16)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
