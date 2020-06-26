#define SIMDE_TEST_ARM_NEON_INSN uzp

#include "test-neon.h"
#include <simde/arm/neon/uzp.h>

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vuzp_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzp_s8 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzp_s16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzp_s32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzp_u8 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzp_u16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzp_u32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzpq_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzpq_s8 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzpq_s16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzpq_s32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzpq_u8 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzpq_u16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vuzpq_u32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzpq_u32)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
