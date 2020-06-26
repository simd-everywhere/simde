#define SIMDE_TEST_ARM_NEON_INSN zip

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/zip.h>

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vzip_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2][2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -358.82), SIMDE_FLOAT32_C(    78.84) },
      { SIMDE_FLOAT32_C(   983.85), SIMDE_FLOAT32_C(  -720.74) },
      {
          { SIMDE_FLOAT32_C(  -358.82), SIMDE_FLOAT32_C(   983.85) },
          { SIMDE_FLOAT32_C(    78.84), SIMDE_FLOAT32_C(  -720.74) },
      },
    },
    { { SIMDE_FLOAT32_C(   775.76), SIMDE_FLOAT32_C(   749.10) },
      { SIMDE_FLOAT32_C(  -498.97), SIMDE_FLOAT32_C(   508.88) },
      {
          { SIMDE_FLOAT32_C(   775.76), SIMDE_FLOAT32_C(  -498.97) },
          { SIMDE_FLOAT32_C(   749.10), SIMDE_FLOAT32_C(   508.88) },
      },
    },
    { { SIMDE_FLOAT32_C(  -772.99), SIMDE_FLOAT32_C(  -138.42) },
      { SIMDE_FLOAT32_C(   768.93), SIMDE_FLOAT32_C(  -389.94) },
      {
          { SIMDE_FLOAT32_C(  -772.99), SIMDE_FLOAT32_C(   768.93) },
          { SIMDE_FLOAT32_C(  -138.42), SIMDE_FLOAT32_C(  -389.94) },
      },
    },
    { { SIMDE_FLOAT32_C(   998.17), SIMDE_FLOAT32_C(  -286.00) },
      { SIMDE_FLOAT32_C(   648.24), SIMDE_FLOAT32_C(  -347.96) },
      {
          { SIMDE_FLOAT32_C(   998.17), SIMDE_FLOAT32_C(   648.24) },
          { SIMDE_FLOAT32_C(  -286.00), SIMDE_FLOAT32_C(  -347.96) },
      },
    },
    { { SIMDE_FLOAT32_C(  -694.32), SIMDE_FLOAT32_C(  -443.35) },
      { SIMDE_FLOAT32_C(  -763.65), SIMDE_FLOAT32_C(   250.75) },
      {
          { SIMDE_FLOAT32_C(  -694.32), SIMDE_FLOAT32_C(  -763.65) },
          { SIMDE_FLOAT32_C(  -443.35), SIMDE_FLOAT32_C(   250.75) },
      },
    },
    { { SIMDE_FLOAT32_C(   -26.88), SIMDE_FLOAT32_C(  -994.99) },
      { SIMDE_FLOAT32_C(   145.10), SIMDE_FLOAT32_C(  -814.15) },
      {
          { SIMDE_FLOAT32_C(   -26.88), SIMDE_FLOAT32_C(   145.10) },
          { SIMDE_FLOAT32_C(  -994.99), SIMDE_FLOAT32_C(  -814.15) },
      },
    },
    { { SIMDE_FLOAT32_C(   982.86), SIMDE_FLOAT32_C(  -888.57) },
      { SIMDE_FLOAT32_C(  -651.00), SIMDE_FLOAT32_C(   623.08) },
      {
          { SIMDE_FLOAT32_C(   982.86), SIMDE_FLOAT32_C(  -651.00) },
          { SIMDE_FLOAT32_C(  -888.57), SIMDE_FLOAT32_C(   623.08) },
      },
    },
    { { SIMDE_FLOAT32_C(  -237.29), SIMDE_FLOAT32_C(    58.52) },
      { SIMDE_FLOAT32_C(   -15.19), SIMDE_FLOAT32_C(   403.89) },
      {
          { SIMDE_FLOAT32_C(  -237.29), SIMDE_FLOAT32_C(   -15.19) },
          { SIMDE_FLOAT32_C(    58.52), SIMDE_FLOAT32_C(   403.89) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2x2_t r = simde_vzip_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], simde_vld1_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], simde_vld1_f32(test_vec[i].r[1]), 1);
  }

  return 0;
}

static int
test_simde_vzip_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[2][8];
  } test_vec[] = {
    { { -INT8_C(  26), -INT8_C(  14), -INT8_C(  73), -INT8_C(  66),  INT8_C(  84), -INT8_C(  37), -INT8_C(  44),  INT8_C(  48) },
      { -INT8_C(  17),  INT8_C( 122), -INT8_C(  84), -INT8_C(  31), -INT8_C( 118),  INT8_C(  66), -INT8_C(   5), -INT8_C(  66) },
      {
          { -INT8_C(  26), -INT8_C(  17), -INT8_C(  14),  INT8_C( 122), -INT8_C(  73), -INT8_C(  84), -INT8_C(  66), -INT8_C(  31) },
          {  INT8_C(  84), -INT8_C( 118), -INT8_C(  37),  INT8_C(  66), -INT8_C(  44), -INT8_C(   5),  INT8_C(  48), -INT8_C(  66) },
      },
    },
    { { -INT8_C(  65), -INT8_C(  32),  INT8_C(  65), -INT8_C(  83),  INT8_C(  64),  INT8_C(  26), -INT8_C(  27), -INT8_C(  82) },
      {  INT8_C(  10), -INT8_C(  11), -INT8_C(   8),  INT8_C( 126),      INT8_MAX,  INT8_C(  56), -INT8_C(  15),  INT8_C( 101) },
      {
          { -INT8_C(  65),  INT8_C(  10), -INT8_C(  32), -INT8_C(  11),  INT8_C(  65), -INT8_C(   8), -INT8_C(  83),  INT8_C( 126) },
          {  INT8_C(  64),      INT8_MAX,  INT8_C(  26),  INT8_C(  56), -INT8_C(  27), -INT8_C(  15), -INT8_C(  82),  INT8_C( 101) },
      },
    },
    { {  INT8_C(  43), -INT8_C(  87),  INT8_C(  35),      INT8_MAX, -INT8_C( 124), -INT8_C(   9), -INT8_C(  80),  INT8_C( 115) },
      {  INT8_C( 114),  INT8_C(  92),  INT8_C(  85), -INT8_C(   4), -INT8_C(  98),  INT8_C(  80), -INT8_C(  70),  INT8_C(  94) },
      {
          {  INT8_C(  43),  INT8_C( 114), -INT8_C(  87),  INT8_C(  92),  INT8_C(  35),  INT8_C(  85),      INT8_MAX, -INT8_C(   4) },
          { -INT8_C( 124), -INT8_C(  98), -INT8_C(   9),  INT8_C(  80), -INT8_C(  80), -INT8_C(  70),  INT8_C( 115),  INT8_C(  94) },
      },
    },
    { {  INT8_C(  48), -INT8_C(   5),  INT8_C(  11),  INT8_C( 113),  INT8_C(  21), -INT8_C(  16),  INT8_C(  31),  INT8_C(  32) },
      { -INT8_C(  27),  INT8_C(  24), -INT8_C(  98),  INT8_C( 100),  INT8_C(  80), -INT8_C( 112), -INT8_C(  55),  INT8_C( 123) },
      {
          {  INT8_C(  48), -INT8_C(  27), -INT8_C(   5),  INT8_C(  24),  INT8_C(  11), -INT8_C(  98),  INT8_C( 113),  INT8_C( 100) },
          {  INT8_C(  21),  INT8_C(  80), -INT8_C(  16), -INT8_C( 112),  INT8_C(  31), -INT8_C(  55),  INT8_C(  32),  INT8_C( 123) },
      },
    },
    { {  INT8_C(  57), -INT8_C(  19), -INT8_C(   5), -INT8_C(  67), -INT8_C(  28), -INT8_C(  85),  INT8_C(  49),  INT8_C(  86) },
      {  INT8_C(   7), -INT8_C( 122),  INT8_C(  82), -INT8_C(  90), -INT8_C(  42),  INT8_C(  13),  INT8_C(   4),  INT8_C(   6) },
      {
          {  INT8_C(  57),  INT8_C(   7), -INT8_C(  19), -INT8_C( 122), -INT8_C(   5),  INT8_C(  82), -INT8_C(  67), -INT8_C(  90) },
          { -INT8_C(  28), -INT8_C(  42), -INT8_C(  85),  INT8_C(  13),  INT8_C(  49),  INT8_C(   4),  INT8_C(  86),  INT8_C(   6) },
      },
    },
    { {  INT8_C(   8),  INT8_C(  15),  INT8_C( 119),  INT8_C(  30), -INT8_C(   1), -INT8_C( 105),  INT8_C(  62), -INT8_C(  28) },
      { -INT8_C(  81), -INT8_C(  36),  INT8_C(  72), -INT8_C(   1),  INT8_C( 108),  INT8_C(  17),  INT8_C( 123), -INT8_C(  91) },
      {
          {  INT8_C(   8), -INT8_C(  81),  INT8_C(  15), -INT8_C(  36),  INT8_C( 119),  INT8_C(  72),  INT8_C(  30), -INT8_C(   1) },
          { -INT8_C(   1),  INT8_C( 108), -INT8_C( 105),  INT8_C(  17),  INT8_C(  62),  INT8_C( 123), -INT8_C(  28), -INT8_C(  91) },
      },
    },
    { { -INT8_C(   2),  INT8_C( 118),  INT8_C(  99), -INT8_C(  29),  INT8_C(  33), -INT8_C( 108),  INT8_C(  57),  INT8_C(  40) },
      {  INT8_C(  26), -INT8_C( 116), -INT8_C(  50), -INT8_C(  16), -INT8_C( 103), -INT8_C(  46), -INT8_C(  10), -INT8_C(  95) },
      {
          { -INT8_C(   2),  INT8_C(  26),  INT8_C( 118), -INT8_C( 116),  INT8_C(  99), -INT8_C(  50), -INT8_C(  29), -INT8_C(  16) },
          {  INT8_C(  33), -INT8_C( 103), -INT8_C( 108), -INT8_C(  46),  INT8_C(  57), -INT8_C(  10),  INT8_C(  40), -INT8_C(  95) },
      },
    },
    { { -INT8_C(  31),  INT8_C( 110), -INT8_C(  65), -INT8_C(  32),  INT8_C(   5), -INT8_C(   3), -INT8_C(  60), -INT8_C(  76) },
      { -INT8_C(  38),  INT8_C(  12), -INT8_C(  77),  INT8_C(  70),  INT8_C(  30),  INT8_C(  46), -INT8_C(  20),  INT8_C(  28) },
      {
          { -INT8_C(  31), -INT8_C(  38),  INT8_C( 110),  INT8_C(  12), -INT8_C(  65), -INT8_C(  77), -INT8_C(  32),  INT8_C(  70) },
          {  INT8_C(   5),  INT8_C(  30), -INT8_C(   3),  INT8_C(  46), -INT8_C(  60), -INT8_C(  20), -INT8_C(  76),  INT8_C(  28) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8x2_t r = simde_vzip_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], simde_vld1_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], simde_vld1_s8(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzip_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[2][4];
  } test_vec[] = {
    { { -INT16_C( 26683),  INT16_C( 14034), -INT16_C(  3551),  INT16_C( 32721) },
      {  INT16_C(  2584), -INT16_C( 16387), -INT16_C(  1878),  INT16_C( 21655) },
      {
          { -INT16_C( 26683),  INT16_C(  2584),  INT16_C( 14034), -INT16_C( 16387) },
          { -INT16_C(  3551), -INT16_C(  1878),  INT16_C( 32721),  INT16_C( 21655) },
      },
    },
    { { -INT16_C(  3666), -INT16_C( 14488),  INT16_C(  5375),  INT16_C( 21517) },
      { -INT16_C( 18844),  INT16_C( 26070), -INT16_C( 14981),  INT16_C( 16854) },
      {
          { -INT16_C(  3666), -INT16_C( 18844), -INT16_C( 14488),  INT16_C( 26070) },
          {  INT16_C(  5375), -INT16_C( 14981),  INT16_C( 21517),  INT16_C( 16854) },
      },
    },
    { { -INT16_C( 22436),  INT16_C( 32119),  INT16_C( 18586), -INT16_C( 19716) },
      { -INT16_C(  1454), -INT16_C(   910),  INT16_C(  2546), -INT16_C( 24239) },
      {
          { -INT16_C( 22436), -INT16_C(  1454),  INT16_C( 32119), -INT16_C(   910) },
          {  INT16_C( 18586),  INT16_C(  2546), -INT16_C( 19716), -INT16_C( 24239) },
      },
    },
    { { -INT16_C( 17926), -INT16_C(  1688),  INT16_C( 30157),  INT16_C( 12621) },
      {  INT16_C(  9003), -INT16_C( 22633),  INT16_C( 28136),  INT16_C( 17640) },
      {
          { -INT16_C( 17926),  INT16_C(  9003), -INT16_C(  1688), -INT16_C( 22633) },
          {  INT16_C( 30157),  INT16_C( 28136),  INT16_C( 12621),  INT16_C( 17640) },
      },
    },
    { {  INT16_C( 24341), -INT16_C( 20543), -INT16_C( 16728), -INT16_C(  1439) },
      { -INT16_C( 11336), -INT16_C( 21769),  INT16_C( 18653), -INT16_C( 10421) },
      {
          {  INT16_C( 24341), -INT16_C( 11336), -INT16_C( 20543), -INT16_C( 21769) },
          { -INT16_C( 16728),  INT16_C( 18653), -INT16_C(  1439), -INT16_C( 10421) },
      },
    },
    { { -INT16_C( 19455), -INT16_C( 12335),  INT16_C(  7721),  INT16_C( 21760) },
      { -INT16_C( 26814),  INT16_C( 11004), -INT16_C(  7164),  INT16_C(  6511) },
      {
          { -INT16_C( 19455), -INT16_C( 26814), -INT16_C( 12335),  INT16_C( 11004) },
          {  INT16_C(  7721), -INT16_C(  7164),  INT16_C( 21760),  INT16_C(  6511) },
      },
    },
    { {  INT16_C( 12355), -INT16_C(  5176),  INT16_C( 10990), -INT16_C( 22810) },
      { -INT16_C(  8707), -INT16_C(  9647), -INT16_C( 25563),  INT16_C(  9906) },
      {
          {  INT16_C( 12355), -INT16_C(  8707), -INT16_C(  5176), -INT16_C(  9647) },
          {  INT16_C( 10990), -INT16_C( 25563), -INT16_C( 22810),  INT16_C(  9906) },
      },
    },
    { { -INT16_C( 31920),  INT16_C( 31477), -INT16_C(  2399), -INT16_C(  7217) },
      { -INT16_C( 13427), -INT16_C( 28146),  INT16_C( 32175), -INT16_C(  3413) },
      {
          { -INT16_C( 31920), -INT16_C( 13427),  INT16_C( 31477), -INT16_C( 28146) },
          { -INT16_C(  2399),  INT16_C( 32175), -INT16_C(  7217), -INT16_C(  3413) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4x2_t r = simde_vzip_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], simde_vld1_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], simde_vld1_s16(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzip_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2][2];
  } test_vec[] = {
    { { -INT32_C(   960648692), -INT32_C(  1572658442) },
      { -INT32_C(     8820380), -INT32_C(   932021964) },
      {
          { -INT32_C(   960648692), -INT32_C(     8820380) },
          { -INT32_C(  1572658442), -INT32_C(   932021964) },
      },
    },
    { { -INT32_C(  1950299668),  INT32_C(    91704458) },
      {  INT32_C(  1292135811), -INT32_C(  1098573390) },
      {
          { -INT32_C(  1950299668),  INT32_C(  1292135811) },
          {  INT32_C(    91704458), -INT32_C(  1098573390) },
      },
    },
    { { -INT32_C(  1165737276), -INT32_C(   933443484) },
      {  INT32_C(  1724372273),  INT32_C(   992885071) },
      {
          { -INT32_C(  1165737276),  INT32_C(  1724372273) },
          { -INT32_C(   933443484),  INT32_C(   992885071) },
      },
    },
    { { -INT32_C(  1916342526), -INT32_C(  1097712325) },
      {  INT32_C(  1544263338),  INT32_C(  1931120815) },
      {
          { -INT32_C(  1916342526),  INT32_C(  1544263338) },
          { -INT32_C(  1097712325),  INT32_C(  1931120815) },
      },
    },
    { {  INT32_C(   909025234), -INT32_C(  1728148889) },
      { -INT32_C(  1342257824),  INT32_C(    32124414) },
      {
          {  INT32_C(   909025234), -INT32_C(  1342257824) },
          { -INT32_C(  1728148889),  INT32_C(    32124414) },
      },
    },
    { {  INT32_C(  1468968988), -INT32_C(  1760222995) },
      {  INT32_C(  1710432438), -INT32_C(  2082927183) },
      {
          {  INT32_C(  1468968988),  INT32_C(  1710432438) },
          { -INT32_C(  1760222995), -INT32_C(  2082927183) },
      },
    },
    { {  INT32_C(   330958764), -INT32_C(   240338799) },
      {  INT32_C(  2090904190), -INT32_C(   209876265) },
      {
          {  INT32_C(   330958764),  INT32_C(  2090904190) },
          { -INT32_C(   240338799), -INT32_C(   209876265) },
      },
    },
    { {  INT32_C(   659163962), -INT32_C(   507617493) },
      {  INT32_C(   826782080),  INT32_C(  1806966975) },
      {
          {  INT32_C(   659163962),  INT32_C(   826782080) },
          { -INT32_C(   507617493),  INT32_C(  1806966975) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2x2_t r = simde_vzip_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], simde_vld1_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], simde_vld1_s32(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzip_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[2][8];
  } test_vec[] = {
    { { UINT8_C( 45), UINT8_C(117), UINT8_C(190), UINT8_C(201), UINT8_C(  7), UINT8_C(205), UINT8_C( 18), UINT8_C(175) },
      { UINT8_C( 25), UINT8_C(  6), UINT8_C(174), UINT8_C(106), UINT8_C( 95), UINT8_C(  1), UINT8_C( 19), UINT8_C(123) },
      {
          { UINT8_C( 45), UINT8_C( 25), UINT8_C(117), UINT8_C(  6), UINT8_C(190), UINT8_C(174), UINT8_C(201), UINT8_C(106) },
          { UINT8_C(  7), UINT8_C( 95), UINT8_C(205), UINT8_C(  1), UINT8_C( 18), UINT8_C( 19), UINT8_C(175), UINT8_C(123) },
      },
    },
    { { UINT8_C( 28), UINT8_C( 48), UINT8_C( 25), UINT8_C( 23), UINT8_C( 60), UINT8_C(125), UINT8_C(102), UINT8_C( 12) },
      { UINT8_C(248), UINT8_C( 49), UINT8_C( 20), UINT8_C(252), UINT8_C(118), UINT8_C(241), UINT8_C(127), UINT8_C(163) },
      {
          { UINT8_C( 28), UINT8_C(248), UINT8_C( 48), UINT8_C( 49), UINT8_C( 25), UINT8_C( 20), UINT8_C( 23), UINT8_C(252) },
          { UINT8_C( 60), UINT8_C(118), UINT8_C(125), UINT8_C(241), UINT8_C(102), UINT8_C(127), UINT8_C( 12), UINT8_C(163) },
      },
    },
    { { UINT8_C(102), UINT8_C( 61), UINT8_C(109), UINT8_C(109), UINT8_C( 10), UINT8_C(127), UINT8_C( 28), UINT8_C( 36) },
      { UINT8_C(134), UINT8_C(202), UINT8_C(142), UINT8_C(229), UINT8_C(204), UINT8_C(161), UINT8_C( 96), UINT8_C(232) },
      {
          { UINT8_C(102), UINT8_C(134), UINT8_C( 61), UINT8_C(202), UINT8_C(109), UINT8_C(142), UINT8_C(109), UINT8_C(229) },
          { UINT8_C( 10), UINT8_C(204), UINT8_C(127), UINT8_C(161), UINT8_C( 28), UINT8_C( 96), UINT8_C( 36), UINT8_C(232) },
      },
    },
    { { UINT8_C(210), UINT8_C(121),    UINT8_MAX, UINT8_C( 14), UINT8_C(246), UINT8_C(101), UINT8_C( 27), UINT8_C(238) },
      { UINT8_C(150), UINT8_C( 47), UINT8_C(234), UINT8_C( 12), UINT8_C( 32), UINT8_C(105), UINT8_C(176), UINT8_C(135) },
      {
          { UINT8_C(210), UINT8_C(150), UINT8_C(121), UINT8_C( 47),    UINT8_MAX, UINT8_C(234), UINT8_C( 14), UINT8_C( 12) },
          { UINT8_C(246), UINT8_C( 32), UINT8_C(101), UINT8_C(105), UINT8_C( 27), UINT8_C(176), UINT8_C(238), UINT8_C(135) },
      },
    },
    { { UINT8_C(167), UINT8_C( 29), UINT8_C(244), UINT8_C(177), UINT8_C(156), UINT8_C( 17), UINT8_C(213), UINT8_C( 34) },
      { UINT8_C(219), UINT8_C(100), UINT8_C(  7), UINT8_C(167), UINT8_C(  5), UINT8_C(103), UINT8_C(144), UINT8_C(215) },
      {
          { UINT8_C(167), UINT8_C(219), UINT8_C( 29), UINT8_C(100), UINT8_C(244), UINT8_C(  7), UINT8_C(177), UINT8_C(167) },
          { UINT8_C(156), UINT8_C(  5), UINT8_C( 17), UINT8_C(103), UINT8_C(213), UINT8_C(144), UINT8_C( 34), UINT8_C(215) },
      },
    },
    { { UINT8_C(224), UINT8_C(143), UINT8_C(230), UINT8_C(214), UINT8_C(245), UINT8_C(  1), UINT8_C(196), UINT8_C(139) },
      { UINT8_C( 48), UINT8_C(174), UINT8_C(152), UINT8_C( 81), UINT8_C( 24), UINT8_C( 72), UINT8_C(216), UINT8_C(191) },
      {
          { UINT8_C(224), UINT8_C( 48), UINT8_C(143), UINT8_C(174), UINT8_C(230), UINT8_C(152), UINT8_C(214), UINT8_C( 81) },
          { UINT8_C(245), UINT8_C( 24), UINT8_C(  1), UINT8_C( 72), UINT8_C(196), UINT8_C(216), UINT8_C(139), UINT8_C(191) },
      },
    },
    { { UINT8_C(101), UINT8_C(204), UINT8_C(112), UINT8_C(  1), UINT8_C(221), UINT8_C( 70), UINT8_C( 36), UINT8_C(185) },
      { UINT8_C(170), UINT8_C( 43), UINT8_C( 96), UINT8_C(175), UINT8_C(147), UINT8_C(240), UINT8_C(135), UINT8_C(115) },
      {
          { UINT8_C(101), UINT8_C(170), UINT8_C(204), UINT8_C( 43), UINT8_C(112), UINT8_C( 96), UINT8_C(  1), UINT8_C(175) },
          { UINT8_C(221), UINT8_C(147), UINT8_C( 70), UINT8_C(240), UINT8_C( 36), UINT8_C(135), UINT8_C(185), UINT8_C(115) },
      },
    },
    { { UINT8_C(128), UINT8_C(109), UINT8_C( 74), UINT8_C(117), UINT8_C(110), UINT8_C( 14), UINT8_C(  0), UINT8_C(158) },
      { UINT8_C(189), UINT8_C(152), UINT8_C(239), UINT8_C(213), UINT8_C(224), UINT8_C(199), UINT8_C(148), UINT8_C( 69) },
      {
          { UINT8_C(128), UINT8_C(189), UINT8_C(109), UINT8_C(152), UINT8_C( 74), UINT8_C(239), UINT8_C(117), UINT8_C(213) },
          { UINT8_C(110), UINT8_C(224), UINT8_C( 14), UINT8_C(199), UINT8_C(  0), UINT8_C(148), UINT8_C(158), UINT8_C( 69) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8x2_t r = simde_vzip_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], simde_vld1_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], simde_vld1_u8(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzip_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[2][4];
  } test_vec[] = {
    { { UINT16_C(39442), UINT16_C(17230), UINT16_C(36311), UINT16_C(63975) },
      { UINT16_C(17092), UINT16_C(21998), UINT16_C(48945), UINT16_C( 9146) },
      {
          { UINT16_C(39442), UINT16_C(17092), UINT16_C(17230), UINT16_C(21998) },
          { UINT16_C(36311), UINT16_C(48945), UINT16_C(63975), UINT16_C( 9146) },
      },
    },
    { { UINT16_C(23687), UINT16_C(28300), UINT16_C(30888), UINT16_C(65167) },
      { UINT16_C(17067), UINT16_C(55130), UINT16_C(36877), UINT16_C( 8076) },
      {
          { UINT16_C(23687), UINT16_C(17067), UINT16_C(28300), UINT16_C(55130) },
          { UINT16_C(30888), UINT16_C(36877), UINT16_C(65167), UINT16_C( 8076) },
      },
    },
    { { UINT16_C(55850), UINT16_C(  611), UINT16_C(19047), UINT16_C(11515) },
      { UINT16_C(60044), UINT16_C(48769), UINT16_C(15273), UINT16_C(12513) },
      {
          { UINT16_C(55850), UINT16_C(60044), UINT16_C(  611), UINT16_C(48769) },
          { UINT16_C(19047), UINT16_C(15273), UINT16_C(11515), UINT16_C(12513) },
      },
    },
    { { UINT16_C(28055), UINT16_C(16542), UINT16_C(11749), UINT16_C(36926) },
      { UINT16_C(39023), UINT16_C(32103), UINT16_C(62248), UINT16_C(21404) },
      {
          { UINT16_C(28055), UINT16_C(39023), UINT16_C(16542), UINT16_C(32103) },
          { UINT16_C(11749), UINT16_C(62248), UINT16_C(36926), UINT16_C(21404) },
      },
    },
    { { UINT16_C(65485), UINT16_C(13653), UINT16_C(20553), UINT16_C(54881) },
      { UINT16_C(57914), UINT16_C(58260), UINT16_C(29982), UINT16_C(46356) },
      {
          { UINT16_C(65485), UINT16_C(57914), UINT16_C(13653), UINT16_C(58260) },
          { UINT16_C(20553), UINT16_C(29982), UINT16_C(54881), UINT16_C(46356) },
      },
    },
    { { UINT16_C(45794), UINT16_C(51445), UINT16_C(13280), UINT16_C(20312) },
      { UINT16_C(49356), UINT16_C(62668), UINT16_C(27059), UINT16_C(33095) },
      {
          { UINT16_C(45794), UINT16_C(49356), UINT16_C(51445), UINT16_C(62668) },
          { UINT16_C(13280), UINT16_C(27059), UINT16_C(20312), UINT16_C(33095) },
      },
    },
    { { UINT16_C(40040), UINT16_C(45750), UINT16_C( 6125), UINT16_C(10120) },
      { UINT16_C( 7417), UINT16_C( 5899), UINT16_C( 8081), UINT16_C(29645) },
      {
          { UINT16_C(40040), UINT16_C( 7417), UINT16_C(45750), UINT16_C( 5899) },
          { UINT16_C( 6125), UINT16_C( 8081), UINT16_C(10120), UINT16_C(29645) },
      },
    },
    { { UINT16_C(49873), UINT16_C(45371), UINT16_C(38134), UINT16_C(49665) },
      { UINT16_C(52564), UINT16_C( 1974), UINT16_C(65078), UINT16_C(40840) },
      {
          { UINT16_C(49873), UINT16_C(52564), UINT16_C(45371), UINT16_C( 1974) },
          { UINT16_C(38134), UINT16_C(65078), UINT16_C(49665), UINT16_C(40840) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4x2_t r = simde_vzip_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r.val[0], simde_vld1_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], simde_vld1_u16(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzip_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2][2];
  } test_vec[] = {
    { { UINT32_C(2533684775), UINT32_C(2516841981) },
      { UINT32_C( 791409457), UINT32_C(2232449215) },
      {
          { UINT32_C(2533684775), UINT32_C( 791409457) },
          { UINT32_C(2516841981), UINT32_C(2232449215) },
      },
    },
    { { UINT32_C(3580136835), UINT32_C(1752780447) },
      { UINT32_C(2448707753), UINT32_C(1837365830) },
      {
          { UINT32_C(3580136835), UINT32_C(2448707753) },
          { UINT32_C(1752780447), UINT32_C(1837365830) },
      },
    },
    { { UINT32_C(3976497136), UINT32_C(2927888252) },
      { UINT32_C(3135090683), UINT32_C(2856316455) },
      {
          { UINT32_C(3976497136), UINT32_C(3135090683) },
          { UINT32_C(2927888252), UINT32_C(2856316455) },
      },
    },
    { { UINT32_C( 444638075), UINT32_C(2592274929) },
      { UINT32_C(2402056009), UINT32_C(1644015473) },
      {
          { UINT32_C( 444638075), UINT32_C(2402056009) },
          { UINT32_C(2592274929), UINT32_C(1644015473) },
      },
    },
    { { UINT32_C(3008233783), UINT32_C(  73519625) },
      { UINT32_C(2847817601), UINT32_C(2824076589) },
      {
          { UINT32_C(3008233783), UINT32_C(2847817601) },
          { UINT32_C(  73519625), UINT32_C(2824076589) },
      },
    },
    { { UINT32_C(2462241697), UINT32_C( 355288268) },
      { UINT32_C( 749033915), UINT32_C(1066246664) },
      {
          { UINT32_C(2462241697), UINT32_C( 749033915) },
          { UINT32_C( 355288268), UINT32_C(1066246664) },
      },
    },
    { { UINT32_C(2901662883), UINT32_C( 816862382) },
      { UINT32_C(3235475091), UINT32_C( 224930924) },
      {
          { UINT32_C(2901662883), UINT32_C(3235475091) },
          { UINT32_C( 816862382), UINT32_C( 224930924) },
      },
    },
    { { UINT32_C(3432983040), UINT32_C( 719506543) },
      { UINT32_C( 777488165), UINT32_C(3429753897) },
      {
          { UINT32_C(3432983040), UINT32_C( 777488165) },
          { UINT32_C( 719506543), UINT32_C(3429753897) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2x2_t r = simde_vzip_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r.val[0], simde_vld1_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], simde_vld1_u32(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzipq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[2][4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -748.99), SIMDE_FLOAT32_C(  -706.11), SIMDE_FLOAT32_C(   869.97), SIMDE_FLOAT32_C(   247.18) },
      { SIMDE_FLOAT32_C(   281.30), SIMDE_FLOAT32_C(  -318.87), SIMDE_FLOAT32_C(  -402.07), SIMDE_FLOAT32_C(   850.87) },
      {
          { SIMDE_FLOAT32_C(  -748.99), SIMDE_FLOAT32_C(   281.30), SIMDE_FLOAT32_C(  -706.11), SIMDE_FLOAT32_C(  -318.87) },
          { SIMDE_FLOAT32_C(   869.97), SIMDE_FLOAT32_C(  -402.07), SIMDE_FLOAT32_C(   247.18), SIMDE_FLOAT32_C(   850.87) },
      },
    },
    { { SIMDE_FLOAT32_C(  -830.23), SIMDE_FLOAT32_C(  -661.11), SIMDE_FLOAT32_C(  -631.24), SIMDE_FLOAT32_C(   130.32) },
      { SIMDE_FLOAT32_C(  -203.49), SIMDE_FLOAT32_C(   634.65), SIMDE_FLOAT32_C(   396.96), SIMDE_FLOAT32_C(   711.13) },
      {
          { SIMDE_FLOAT32_C(  -830.23), SIMDE_FLOAT32_C(  -203.49), SIMDE_FLOAT32_C(  -661.11), SIMDE_FLOAT32_C(   634.65) },
          { SIMDE_FLOAT32_C(  -631.24), SIMDE_FLOAT32_C(   396.96), SIMDE_FLOAT32_C(   130.32), SIMDE_FLOAT32_C(   711.13) },
      },
    },
    { { SIMDE_FLOAT32_C(   282.82), SIMDE_FLOAT32_C(   202.09), SIMDE_FLOAT32_C(  -453.11), SIMDE_FLOAT32_C(   640.01) },
      { SIMDE_FLOAT32_C(   822.42), SIMDE_FLOAT32_C(   187.30), SIMDE_FLOAT32_C(    18.58), SIMDE_FLOAT32_C(   809.63) },
      {
          { SIMDE_FLOAT32_C(   282.82), SIMDE_FLOAT32_C(   822.42), SIMDE_FLOAT32_C(   202.09), SIMDE_FLOAT32_C(   187.30) },
          { SIMDE_FLOAT32_C(  -453.11), SIMDE_FLOAT32_C(    18.58), SIMDE_FLOAT32_C(   640.01), SIMDE_FLOAT32_C(   809.63) },
      },
    },
    { { SIMDE_FLOAT32_C(  -225.67), SIMDE_FLOAT32_C(   681.44), SIMDE_FLOAT32_C(   463.00), SIMDE_FLOAT32_C(   309.35) },
      { SIMDE_FLOAT32_C(   589.93), SIMDE_FLOAT32_C(   877.78), SIMDE_FLOAT32_C(   246.23), SIMDE_FLOAT32_C(   840.94) },
      {
          { SIMDE_FLOAT32_C(  -225.67), SIMDE_FLOAT32_C(   589.93), SIMDE_FLOAT32_C(   681.44), SIMDE_FLOAT32_C(   877.78) },
          { SIMDE_FLOAT32_C(   463.00), SIMDE_FLOAT32_C(   246.23), SIMDE_FLOAT32_C(   309.35), SIMDE_FLOAT32_C(   840.94) },
      },
    },
    { { SIMDE_FLOAT32_C(  -828.33), SIMDE_FLOAT32_C(   116.19), SIMDE_FLOAT32_C(    88.12), SIMDE_FLOAT32_C(   452.97) },
      { SIMDE_FLOAT32_C(   797.32), SIMDE_FLOAT32_C(   686.05), SIMDE_FLOAT32_C(   303.84), SIMDE_FLOAT32_C(   967.09) },
      {
          { SIMDE_FLOAT32_C(  -828.33), SIMDE_FLOAT32_C(   797.32), SIMDE_FLOAT32_C(   116.19), SIMDE_FLOAT32_C(   686.05) },
          { SIMDE_FLOAT32_C(    88.12), SIMDE_FLOAT32_C(   303.84), SIMDE_FLOAT32_C(   452.97), SIMDE_FLOAT32_C(   967.09) },
      },
    },
    { { SIMDE_FLOAT32_C(  -975.06), SIMDE_FLOAT32_C(   672.60), SIMDE_FLOAT32_C(    97.41), SIMDE_FLOAT32_C(  -178.55) },
      { SIMDE_FLOAT32_C(   307.24), SIMDE_FLOAT32_C(  -505.62), SIMDE_FLOAT32_C(  -467.42), SIMDE_FLOAT32_C(  -409.94) },
      {
          { SIMDE_FLOAT32_C(  -975.06), SIMDE_FLOAT32_C(   307.24), SIMDE_FLOAT32_C(   672.60), SIMDE_FLOAT32_C(  -505.62) },
          { SIMDE_FLOAT32_C(    97.41), SIMDE_FLOAT32_C(  -467.42), SIMDE_FLOAT32_C(  -178.55), SIMDE_FLOAT32_C(  -409.94) },
      },
    },
    { { SIMDE_FLOAT32_C(   696.47), SIMDE_FLOAT32_C(    79.47), SIMDE_FLOAT32_C(  -769.92), SIMDE_FLOAT32_C(   518.88) },
      { SIMDE_FLOAT32_C(  -733.23), SIMDE_FLOAT32_C(   248.65), SIMDE_FLOAT32_C(   328.52), SIMDE_FLOAT32_C(    41.09) },
      {
          { SIMDE_FLOAT32_C(   696.47), SIMDE_FLOAT32_C(  -733.23), SIMDE_FLOAT32_C(    79.47), SIMDE_FLOAT32_C(   248.65) },
          { SIMDE_FLOAT32_C(  -769.92), SIMDE_FLOAT32_C(   328.52), SIMDE_FLOAT32_C(   518.88), SIMDE_FLOAT32_C(    41.09) },
      },
    },
    { { SIMDE_FLOAT32_C(   -69.90), SIMDE_FLOAT32_C(  -208.48), SIMDE_FLOAT32_C(  -649.56), SIMDE_FLOAT32_C(  -479.97) },
      { SIMDE_FLOAT32_C(  -330.70), SIMDE_FLOAT32_C(   596.67), SIMDE_FLOAT32_C(  -639.03), SIMDE_FLOAT32_C(  -159.03) },
      {
          { SIMDE_FLOAT32_C(   -69.90), SIMDE_FLOAT32_C(  -330.70), SIMDE_FLOAT32_C(  -208.48), SIMDE_FLOAT32_C(   596.67) },
          { SIMDE_FLOAT32_C(  -649.56), SIMDE_FLOAT32_C(  -639.03), SIMDE_FLOAT32_C(  -479.97), SIMDE_FLOAT32_C(  -159.03) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4x2_t r = simde_vzipq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r.val[0], simde_vld1q_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], simde_vld1q_f32(test_vec[i].r[1]), 1);
  }

  return 0;
}

static int
test_simde_vzipq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[2][16];
  } test_vec[] = {
    { {  INT8_C( 106), -INT8_C( 117), -INT8_C( 106), -INT8_C( 113), -INT8_C(  27), -INT8_C(  54),  INT8_C(  13), -INT8_C(  22),
        -INT8_C( 117),  INT8_C(  99),  INT8_C(   3),  INT8_C(  35),  INT8_C(  32), -INT8_C(  99), -INT8_C(  83), -INT8_C(  26) },
      {  INT8_C(  80), -INT8_C(  97), -INT8_C(  66),  INT8_C(  69),  INT8_C(  11), -INT8_C(  96), -INT8_C(  40),  INT8_C(  91),
        -INT8_C( 122),  INT8_C(  27), -INT8_C(  48),  INT8_C(   8),  INT8_C(  78),  INT8_C( 103), -INT8_C(  89), -INT8_C(  72) },
      {
          {  INT8_C( 106),  INT8_C(  80), -INT8_C( 117), -INT8_C(  97), -INT8_C( 106), -INT8_C(  66), -INT8_C( 113),  INT8_C(  69),
            -INT8_C(  27),  INT8_C(  11), -INT8_C(  54), -INT8_C(  96),  INT8_C(  13), -INT8_C(  40), -INT8_C(  22),  INT8_C(  91) },
          { -INT8_C( 117), -INT8_C( 122),  INT8_C(  99),  INT8_C(  27),  INT8_C(   3), -INT8_C(  48),  INT8_C(  35),  INT8_C(   8),
             INT8_C(  32),  INT8_C(  78), -INT8_C(  99),  INT8_C( 103), -INT8_C(  83), -INT8_C(  89), -INT8_C(  26), -INT8_C(  72) },
      },
    },
    { { -INT8_C(  14),  INT8_C(  61),  INT8_C(  72), -INT8_C(  41),  INT8_C(   7),  INT8_C(  85), -INT8_C(  62), -INT8_C( 110),
        -INT8_C(  72), -INT8_C(  59), -INT8_C(  75), -INT8_C(  39),  INT8_C(  98),  INT8_C(  98), -INT8_C(  65), -INT8_C(  78) },
      {  INT8_C(   1),  INT8_C( 126), -INT8_C(   8),  INT8_C(  12),  INT8_C(  30), -INT8_C(  48),  INT8_C( 103), -INT8_C(  91),
        -INT8_C(  21),  INT8_C(  55), -INT8_C(  83),  INT8_C(  57), -INT8_C(  98),  INT8_C(  84), -INT8_C(  14), -INT8_C( 112) },
      {
          { -INT8_C(  14),  INT8_C(   1),  INT8_C(  61),  INT8_C( 126),  INT8_C(  72), -INT8_C(   8), -INT8_C(  41),  INT8_C(  12),
             INT8_C(   7),  INT8_C(  30),  INT8_C(  85), -INT8_C(  48), -INT8_C(  62),  INT8_C( 103), -INT8_C( 110), -INT8_C(  91) },
          { -INT8_C(  72), -INT8_C(  21), -INT8_C(  59),  INT8_C(  55), -INT8_C(  75), -INT8_C(  83), -INT8_C(  39),  INT8_C(  57),
             INT8_C(  98), -INT8_C(  98),  INT8_C(  98),  INT8_C(  84), -INT8_C(  65), -INT8_C(  14), -INT8_C(  78), -INT8_C( 112) },
      },
    },
    { { -INT8_C( 111),  INT8_C(  58),  INT8_C( 104), -INT8_C( 104), -INT8_C( 113),  INT8_C(  42),  INT8_C(  42),  INT8_C(  71),
        -INT8_C(  17), -INT8_C(  33),  INT8_C(  32),  INT8_C(  82),  INT8_C(  65), -INT8_C(  32),  INT8_C(   4),  INT8_C(  66) },
      {  INT8_C(  94), -INT8_C(   4),  INT8_C(  78),  INT8_C( 124), -INT8_C(  51), -INT8_C(  74),  INT8_C(  33), -INT8_C(  72),
        -INT8_C(  19), -INT8_C(  50), -INT8_C(  14), -INT8_C( 116),  INT8_C(  34), -INT8_C(  28),  INT8_C(  28), -INT8_C(  77) },
      {
          { -INT8_C( 111),  INT8_C(  94),  INT8_C(  58), -INT8_C(   4),  INT8_C( 104),  INT8_C(  78), -INT8_C( 104),  INT8_C( 124),
            -INT8_C( 113), -INT8_C(  51),  INT8_C(  42), -INT8_C(  74),  INT8_C(  42),  INT8_C(  33),  INT8_C(  71), -INT8_C(  72) },
          { -INT8_C(  17), -INT8_C(  19), -INT8_C(  33), -INT8_C(  50),  INT8_C(  32), -INT8_C(  14),  INT8_C(  82), -INT8_C( 116),
             INT8_C(  65),  INT8_C(  34), -INT8_C(  32), -INT8_C(  28),  INT8_C(   4),  INT8_C(  28),  INT8_C(  66), -INT8_C(  77) },
      },
    },
    { {  INT8_C(  30), -INT8_C( 124),  INT8_C(  75), -INT8_C(  83), -INT8_C(  82),  INT8_C( 117), -INT8_C(  12), -INT8_C(  98),
         INT8_C(  84),  INT8_C(  21), -INT8_C(  16), -INT8_C( 107), -INT8_C(  11), -INT8_C(  12), -INT8_C(  41),  INT8_C(  83) },
      { -INT8_C(  15),  INT8_C(  38), -INT8_C(  49), -INT8_C(  66), -INT8_C(  36), -INT8_C(  15),  INT8_C( 118), -INT8_C(  55),
        -INT8_C(  65),  INT8_C( 104),  INT8_C(  85), -INT8_C(  30),  INT8_C(  76),  INT8_C( 114), -INT8_C( 107),  INT8_C( 106) },
      {
          {  INT8_C(  30), -INT8_C(  15), -INT8_C( 124),  INT8_C(  38),  INT8_C(  75), -INT8_C(  49), -INT8_C(  83), -INT8_C(  66),
            -INT8_C(  82), -INT8_C(  36),  INT8_C( 117), -INT8_C(  15), -INT8_C(  12),  INT8_C( 118), -INT8_C(  98), -INT8_C(  55) },
          {  INT8_C(  84), -INT8_C(  65),  INT8_C(  21),  INT8_C( 104), -INT8_C(  16),  INT8_C(  85), -INT8_C( 107), -INT8_C(  30),
            -INT8_C(  11),  INT8_C(  76), -INT8_C(  12),  INT8_C( 114), -INT8_C(  41), -INT8_C( 107),  INT8_C(  83),  INT8_C( 106) },
      },
    },
    { { -INT8_C(  10), -INT8_C(  31),  INT8_C(  23), -INT8_C(  91),  INT8_C(  86),  INT8_C(  12),  INT8_C(  67), -INT8_C(  85),
         INT8_C(  33),  INT8_C(  51),  INT8_C(  64),  INT8_C(  22),  INT8_C(  39),  INT8_C(  24),  INT8_C( 105),  INT8_C(  24) },
      {  INT8_C(  62),  INT8_C(  56), -INT8_C(  42),  INT8_C(  26),  INT8_C(  41),  INT8_C(  77), -INT8_C(  29), -INT8_C(  23),
        -INT8_C(  75),  INT8_C(  57), -INT8_C(  53),  INT8_C(   2), -INT8_C(  85),  INT8_C(  96),  INT8_C( 108), -INT8_C(  95) },
      {
          { -INT8_C(  10),  INT8_C(  62), -INT8_C(  31),  INT8_C(  56),  INT8_C(  23), -INT8_C(  42), -INT8_C(  91),  INT8_C(  26),
             INT8_C(  86),  INT8_C(  41),  INT8_C(  12),  INT8_C(  77),  INT8_C(  67), -INT8_C(  29), -INT8_C(  85), -INT8_C(  23) },
          {  INT8_C(  33), -INT8_C(  75),  INT8_C(  51),  INT8_C(  57),  INT8_C(  64), -INT8_C(  53),  INT8_C(  22),  INT8_C(   2),
             INT8_C(  39), -INT8_C(  85),  INT8_C(  24),  INT8_C(  96),  INT8_C( 105),  INT8_C( 108),  INT8_C(  24), -INT8_C(  95) },
      },
    },
    { {  INT8_C(  65), -INT8_C( 124),  INT8_C(  70), -INT8_C( 104), -INT8_C( 112), -INT8_C( 119),  INT8_C(  67), -INT8_C(  79),
        -INT8_C(  68), -INT8_C( 125), -INT8_C(  57), -INT8_C(  28), -INT8_C( 101),  INT8_C(  48), -INT8_C(   4), -INT8_C(  39) },
      {  INT8_C( 104), -INT8_C(  45), -INT8_C(  13), -INT8_C( 110),  INT8_C(  32), -INT8_C(  41),  INT8_C( 123), -INT8_C(  43),
         INT8_C(  16),  INT8_C(  70), -INT8_C(  41), -INT8_C(  69), -INT8_C(  90),  INT8_C(  68),  INT8_C(  92), -INT8_C(  24) },
      {
          {  INT8_C(  65),  INT8_C( 104), -INT8_C( 124), -INT8_C(  45),  INT8_C(  70), -INT8_C(  13), -INT8_C( 104), -INT8_C( 110),
            -INT8_C( 112),  INT8_C(  32), -INT8_C( 119), -INT8_C(  41),  INT8_C(  67),  INT8_C( 123), -INT8_C(  79), -INT8_C(  43) },
          { -INT8_C(  68),  INT8_C(  16), -INT8_C( 125),  INT8_C(  70), -INT8_C(  57), -INT8_C(  41), -INT8_C(  28), -INT8_C(  69),
            -INT8_C( 101), -INT8_C(  90),  INT8_C(  48),  INT8_C(  68), -INT8_C(   4),  INT8_C(  92), -INT8_C(  39), -INT8_C(  24) },
      },
    },
    { { -INT8_C(  56), -INT8_C(  93),      INT8_MIN,  INT8_C(  88),  INT8_C(  44), -INT8_C(  61),  INT8_C(   9), -INT8_C(  23),
         INT8_C(  70), -INT8_C(  48), -INT8_C(  51), -INT8_C(  30),  INT8_C(   0), -INT8_C(  55), -INT8_C(  69),  INT8_C( 104) },
      { -INT8_C( 100), -INT8_C(  81), -INT8_C(   6), -INT8_C(  68), -INT8_C( 122),  INT8_C( 117), -INT8_C( 110), -INT8_C( 106),
        -INT8_C(  69),  INT8_C( 105),  INT8_C(  81),  INT8_C(  98), -INT8_C(  83), -INT8_C(  83),  INT8_C(  74),  INT8_C( 117) },
      {
          { -INT8_C(  56), -INT8_C( 100), -INT8_C(  93), -INT8_C(  81),      INT8_MIN, -INT8_C(   6),  INT8_C(  88), -INT8_C(  68),
             INT8_C(  44), -INT8_C( 122), -INT8_C(  61),  INT8_C( 117),  INT8_C(   9), -INT8_C( 110), -INT8_C(  23), -INT8_C( 106) },
          {  INT8_C(  70), -INT8_C(  69), -INT8_C(  48),  INT8_C( 105), -INT8_C(  51),  INT8_C(  81), -INT8_C(  30),  INT8_C(  98),
             INT8_C(   0), -INT8_C(  83), -INT8_C(  55), -INT8_C(  83), -INT8_C(  69),  INT8_C(  74),  INT8_C( 104),  INT8_C( 117) },
      },
    },
    { {  INT8_C(  80), -INT8_C(  54), -INT8_C(  51),  INT8_C( 125), -INT8_C( 115), -INT8_C(  42),  INT8_C( 102), -INT8_C(  45),
        -INT8_C(  90),  INT8_C(  51), -INT8_C(  75), -INT8_C(  90), -INT8_C(   4),  INT8_C( 113),  INT8_C(  15), -INT8_C( 103) },
      {  INT8_C(  32),  INT8_C(   9),  INT8_C(  85), -INT8_C(  90),      INT8_MAX, -INT8_C(  25),  INT8_C(  60),  INT8_C(  58),
         INT8_C(  81), -INT8_C( 115), -INT8_C( 100), -INT8_C(   2),  INT8_C(  58), -INT8_C(  26),  INT8_C( 116), -INT8_C( 117) },
      {
          {  INT8_C(  80),  INT8_C(  32), -INT8_C(  54),  INT8_C(   9), -INT8_C(  51),  INT8_C(  85),  INT8_C( 125), -INT8_C(  90),
            -INT8_C( 115),      INT8_MAX, -INT8_C(  42), -INT8_C(  25),  INT8_C( 102),  INT8_C(  60), -INT8_C(  45),  INT8_C(  58) },
          { -INT8_C(  90),  INT8_C(  81),  INT8_C(  51), -INT8_C( 115), -INT8_C(  75), -INT8_C( 100), -INT8_C(  90), -INT8_C(   2),
            -INT8_C(   4),  INT8_C(  58),  INT8_C( 113), -INT8_C(  26),  INT8_C(  15),  INT8_C( 116), -INT8_C( 103), -INT8_C( 117) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16x2_t r = simde_vzipq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], simde_vld1q_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], simde_vld1q_s8(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzipq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[2][8];
  } test_vec[] = {
    { {  INT16_C(  3008), -INT16_C( 17292), -INT16_C( 32024), -INT16_C( 11129),  INT16_C( 23848), -INT16_C( 24759),  INT16_C( 23386),  INT16_C( 16016) },
      {  INT16_C( 20554),  INT16_C( 14369), -INT16_C(  8685), -INT16_C( 28269),  INT16_C( 23126),  INT16_C( 29189),  INT16_C(  8337),  INT16_C( 21143) },
      {
          {  INT16_C(  3008),  INT16_C( 20554), -INT16_C( 17292),  INT16_C( 14369), -INT16_C( 32024), -INT16_C(  8685), -INT16_C( 11129), -INT16_C( 28269) },
          {  INT16_C( 23848),  INT16_C( 23126), -INT16_C( 24759),  INT16_C( 29189),  INT16_C( 23386),  INT16_C(  8337),  INT16_C( 16016),  INT16_C( 21143) },
      },
    },
    { {  INT16_C(  3116),  INT16_C(  5134), -INT16_C( 26994), -INT16_C( 18456),  INT16_C( 13043),  INT16_C( 19798), -INT16_C(  6515), -INT16_C( 10100) },
      { -INT16_C( 21194),  INT16_C( 18704), -INT16_C( 23669), -INT16_C(  7718), -INT16_C(  8194), -INT16_C( 28844), -INT16_C(  5376),  INT16_C( 11489) },
      {
          {  INT16_C(  3116), -INT16_C( 21194),  INT16_C(  5134),  INT16_C( 18704), -INT16_C( 26994), -INT16_C( 23669), -INT16_C( 18456), -INT16_C(  7718) },
          {  INT16_C( 13043), -INT16_C(  8194),  INT16_C( 19798), -INT16_C( 28844), -INT16_C(  6515), -INT16_C(  5376), -INT16_C( 10100),  INT16_C( 11489) },
      },
    },
    { { -INT16_C(  3849), -INT16_C( 31168),  INT16_C( 10630),  INT16_C( 31037), -INT16_C( 27813), -INT16_C(  5946),  INT16_C( 21113), -INT16_C( 20544) },
      { -INT16_C( 11777), -INT16_C( 29703), -INT16_C( 11404),  INT16_C( 29292), -INT16_C( 16205), -INT16_C( 19710), -INT16_C(  7252), -INT16_C( 23585) },
      {
          { -INT16_C(  3849), -INT16_C( 11777), -INT16_C( 31168), -INT16_C( 29703),  INT16_C( 10630), -INT16_C( 11404),  INT16_C( 31037),  INT16_C( 29292) },
          { -INT16_C( 27813), -INT16_C( 16205), -INT16_C(  5946), -INT16_C( 19710),  INT16_C( 21113), -INT16_C(  7252), -INT16_C( 20544), -INT16_C( 23585) },
      },
    },
    { {  INT16_C(  8147),  INT16_C( 22825),  INT16_C( 26184), -INT16_C( 23598), -INT16_C( 26119),  INT16_C( 29324),  INT16_C( 19691), -INT16_C(  5342) },
      {  INT16_C(  6941), -INT16_C( 28042), -INT16_C(  7442), -INT16_C( 24316),  INT16_C(  1699),  INT16_C( 20308),  INT16_C( 13290), -INT16_C( 16910) },
      {
          {  INT16_C(  8147),  INT16_C(  6941),  INT16_C( 22825), -INT16_C( 28042),  INT16_C( 26184), -INT16_C(  7442), -INT16_C( 23598), -INT16_C( 24316) },
          { -INT16_C( 26119),  INT16_C(  1699),  INT16_C( 29324),  INT16_C( 20308),  INT16_C( 19691),  INT16_C( 13290), -INT16_C(  5342), -INT16_C( 16910) },
      },
    },
    { {  INT16_C(  7251), -INT16_C( 25833), -INT16_C(  5758),  INT16_C( 31807), -INT16_C( 13438),  INT16_C( 28398),  INT16_C(  4119),  INT16_C( 13657) },
      { -INT16_C( 12501),  INT16_C(  6855), -INT16_C( 13391),  INT16_C( 21691),  INT16_C(  4306), -INT16_C( 17245), -INT16_C( 27069), -INT16_C( 27015) },
      {
          {  INT16_C(  7251), -INT16_C( 12501), -INT16_C( 25833),  INT16_C(  6855), -INT16_C(  5758), -INT16_C( 13391),  INT16_C( 31807),  INT16_C( 21691) },
          { -INT16_C( 13438),  INT16_C(  4306),  INT16_C( 28398), -INT16_C( 17245),  INT16_C(  4119), -INT16_C( 27069),  INT16_C( 13657), -INT16_C( 27015) },
      },
    },
    { { -INT16_C( 28494),  INT16_C( 13362),  INT16_C( 29050), -INT16_C(   848), -INT16_C( 24772),  INT16_C( 21354), -INT16_C( 15441), -INT16_C(  9336) },
      {  INT16_C( 20370),  INT16_C( 17653), -INT16_C( 20453), -INT16_C(  4712),  INT16_C( 15552),  INT16_C(  1193),  INT16_C(  8914), -INT16_C( 31590) },
      {
          { -INT16_C( 28494),  INT16_C( 20370),  INT16_C( 13362),  INT16_C( 17653),  INT16_C( 29050), -INT16_C( 20453), -INT16_C(   848), -INT16_C(  4712) },
          { -INT16_C( 24772),  INT16_C( 15552),  INT16_C( 21354),  INT16_C(  1193), -INT16_C( 15441),  INT16_C(  8914), -INT16_C(  9336), -INT16_C( 31590) },
      },
    },
    { { -INT16_C( 13133),  INT16_C( 11704),  INT16_C( 26941),  INT16_C( 31017), -INT16_C( 27640), -INT16_C( 18483),  INT16_C( 21847), -INT16_C(  5486) },
      { -INT16_C( 30811), -INT16_C( 16338), -INT16_C( 14792), -INT16_C(  1875),  INT16_C( 22018), -INT16_C( 11012), -INT16_C( 26760),  INT16_C( 11096) },
      {
          { -INT16_C( 13133), -INT16_C( 30811),  INT16_C( 11704), -INT16_C( 16338),  INT16_C( 26941), -INT16_C( 14792),  INT16_C( 31017), -INT16_C(  1875) },
          { -INT16_C( 27640),  INT16_C( 22018), -INT16_C( 18483), -INT16_C( 11012),  INT16_C( 21847), -INT16_C( 26760), -INT16_C(  5486),  INT16_C( 11096) },
      },
    },
    { {  INT16_C(  4451), -INT16_C( 24232), -INT16_C( 32134), -INT16_C( 32230), -INT16_C(  6378),  INT16_C( 27961), -INT16_C( 13251), -INT16_C(  7593) },
      { -INT16_C( 31405), -INT16_C( 29790),  INT16_C( 20300),  INT16_C( 20100), -INT16_C( 32603),  INT16_C(  7459),  INT16_C( 31511),  INT16_C( 31561) },
      {
          {  INT16_C(  4451), -INT16_C( 31405), -INT16_C( 24232), -INT16_C( 29790), -INT16_C( 32134),  INT16_C( 20300), -INT16_C( 32230),  INT16_C( 20100) },
          { -INT16_C(  6378), -INT16_C( 32603),  INT16_C( 27961),  INT16_C(  7459), -INT16_C( 13251),  INT16_C( 31511), -INT16_C(  7593),  INT16_C( 31561) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8x2_t r = simde_vzipq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], simde_vld1q_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], simde_vld1q_s16(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzipq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[2][4];
  } test_vec[] = {
    { { -INT32_C(    99917994), -INT32_C(   280558692),  INT32_C(   308406472), -INT32_C(  1858489826) },
      {  INT32_C(   758961887), -INT32_C(  1062247511), -INT32_C(   830256915),  INT32_C(   425864131) },
      {
          { -INT32_C(    99917994),  INT32_C(   758961887), -INT32_C(   280558692), -INT32_C(  1062247511) },
          {  INT32_C(   308406472), -INT32_C(   830256915), -INT32_C(  1858489826),  INT32_C(   425864131) },
      },
    },
    { {  INT32_C(   638807690),  INT32_C(   957700977),  INT32_C(  1632400963),  INT32_C(   133334312) },
      {  INT32_C(    87371355),  INT32_C(  2126898321), -INT32_C(   280213460), -INT32_C(    49696909) },
      {
          {  INT32_C(   638807690),  INT32_C(    87371355),  INT32_C(   957700977),  INT32_C(  2126898321) },
          {  INT32_C(  1632400963), -INT32_C(   280213460),  INT32_C(   133334312), -INT32_C(    49696909) },
      },
    },
    { { -INT32_C(  1910236131), -INT32_C(  1161348745), -INT32_C(   669314128), -INT32_C(   186642791) },
      { -INT32_C(   822536900),  INT32_C(   642563833),  INT32_C(  2048235783),  INT32_C(  1702370888) },
      {
          { -INT32_C(  1910236131), -INT32_C(   822536900), -INT32_C(  1161348745),  INT32_C(   642563833) },
          { -INT32_C(   669314128),  INT32_C(  2048235783), -INT32_C(   186642791),  INT32_C(  1702370888) },
      },
    },
    { { -INT32_C(  1292657605), -INT32_C(  2056406315),  INT32_C(  1734248654), -INT32_C(   748994922) },
      {  INT32_C(  1285641555),  INT32_C(   443739411), -INT32_C(   829060986), -INT32_C(   516747866) },
      {
          { -INT32_C(  1292657605),  INT32_C(  1285641555), -INT32_C(  2056406315),  INT32_C(   443739411) },
          {  INT32_C(  1734248654), -INT32_C(   829060986), -INT32_C(   748994922), -INT32_C(   516747866) },
      },
    },
    { {  INT32_C(  2123638441), -INT32_C(  1358691871),  INT32_C(   538337929), -INT32_C(   202149472) },
      { -INT32_C(   633367354),  INT32_C(   150254209), -INT32_C(   522811078),  INT32_C(  1069681302) },
      {
          {  INT32_C(  2123638441), -INT32_C(   633367354), -INT32_C(  1358691871),  INT32_C(   150254209) },
          {  INT32_C(   538337929), -INT32_C(   522811078), -INT32_C(   202149472),  INT32_C(  1069681302) },
      },
    },
    { {  INT32_C(   297686576), -INT32_C(   524238249), -INT32_C(  1006578140),  INT32_C(   246936392) },
      {  INT32_C(   166262407), -INT32_C(   502145624), -INT32_C(    37492890),  INT32_C(   574391793) },
      {
          {  INT32_C(   297686576),  INT32_C(   166262407), -INT32_C(   524238249), -INT32_C(   502145624) },
          { -INT32_C(  1006578140), -INT32_C(    37492890),  INT32_C(   246936392),  INT32_C(   574391793) },
      },
    },
    { {  INT32_C(   842267355), -INT32_C(   535628612),  INT32_C(   312742858), -INT32_C(  1910416634) },
      { -INT32_C(    90764974),  INT32_C(  1306372326), -INT32_C(  2125815665),  INT32_C(    10716709) },
      {
          {  INT32_C(   842267355), -INT32_C(    90764974), -INT32_C(   535628612),  INT32_C(  1306372326) },
          {  INT32_C(   312742858), -INT32_C(  2125815665), -INT32_C(  1910416634),  INT32_C(    10716709) },
      },
    },
    { {  INT32_C(  1026741889), -INT32_C(  1793178422),  INT32_C(  1588052567),  INT32_C(  1894565918) },
      { -INT32_C(  1200978990), -INT32_C(  1174059221),  INT32_C(   205213671),  INT32_C(  1460461270) },
      {
          {  INT32_C(  1026741889), -INT32_C(  1200978990), -INT32_C(  1793178422), -INT32_C(  1174059221) },
          {  INT32_C(  1588052567),  INT32_C(   205213671),  INT32_C(  1894565918),  INT32_C(  1460461270) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4x2_t r = simde_vzipq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r.val[0], simde_vld1q_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], simde_vld1q_s32(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzipq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[2][16];
  } test_vec[] = {
    { { UINT8_C(183), UINT8_C(104), UINT8_C(229), UINT8_C(148), UINT8_C(145), UINT8_C( 93), UINT8_C(206), UINT8_C( 25),
        UINT8_C(179), UINT8_C(235), UINT8_C(112), UINT8_C( 10), UINT8_C( 54), UINT8_C(251), UINT8_C(230), UINT8_C(234) },
      { UINT8_C(252), UINT8_C( 45), UINT8_C( 96), UINT8_C(130), UINT8_C(187), UINT8_C(  4), UINT8_C(186), UINT8_C( 78),
        UINT8_C( 95), UINT8_C( 69), UINT8_C(242), UINT8_C(216), UINT8_C(128), UINT8_C(201), UINT8_C(251), UINT8_C( 55) },
      {
          { UINT8_C(183), UINT8_C(252), UINT8_C(104), UINT8_C( 45), UINT8_C(229), UINT8_C( 96), UINT8_C(148), UINT8_C(130),
            UINT8_C(145), UINT8_C(187), UINT8_C( 93), UINT8_C(  4), UINT8_C(206), UINT8_C(186), UINT8_C( 25), UINT8_C( 78) },
          { UINT8_C(179), UINT8_C( 95), UINT8_C(235), UINT8_C( 69), UINT8_C(112), UINT8_C(242), UINT8_C( 10), UINT8_C(216),
            UINT8_C( 54), UINT8_C(128), UINT8_C(251), UINT8_C(201), UINT8_C(230), UINT8_C(251), UINT8_C(234), UINT8_C( 55) },
      },
    },
    { { UINT8_C( 49), UINT8_C(224), UINT8_C(203), UINT8_C(195), UINT8_C( 61), UINT8_C(153), UINT8_C(220), UINT8_C(240),
        UINT8_C(132), UINT8_C( 76), UINT8_C(251), UINT8_C(187), UINT8_C( 71), UINT8_C(225), UINT8_C(165), UINT8_C( 68) },
      { UINT8_C( 15), UINT8_C(  5), UINT8_C(198), UINT8_C(202), UINT8_C(  9), UINT8_C(128), UINT8_C( 24), UINT8_C(104),
        UINT8_C(198), UINT8_C( 10), UINT8_C( 64), UINT8_C( 70), UINT8_C(211), UINT8_C( 59), UINT8_C(125), UINT8_C(  5) },
      {
          { UINT8_C( 49), UINT8_C( 15), UINT8_C(224), UINT8_C(  5), UINT8_C(203), UINT8_C(198), UINT8_C(195), UINT8_C(202),
            UINT8_C( 61), UINT8_C(  9), UINT8_C(153), UINT8_C(128), UINT8_C(220), UINT8_C( 24), UINT8_C(240), UINT8_C(104) },
          { UINT8_C(132), UINT8_C(198), UINT8_C( 76), UINT8_C( 10), UINT8_C(251), UINT8_C( 64), UINT8_C(187), UINT8_C( 70),
            UINT8_C( 71), UINT8_C(211), UINT8_C(225), UINT8_C( 59), UINT8_C(165), UINT8_C(125), UINT8_C( 68), UINT8_C(  5) },
      },
    },
    { { UINT8_C( 27), UINT8_C( 72), UINT8_C(200), UINT8_C( 88), UINT8_C(225), UINT8_C(164), UINT8_C( 73), UINT8_C(102),
        UINT8_C(240), UINT8_C( 68), UINT8_C( 33), UINT8_C( 55), UINT8_C( 37), UINT8_C(198), UINT8_C(123), UINT8_C( 52) },
      { UINT8_C(203), UINT8_C( 66),    UINT8_MAX, UINT8_C(213), UINT8_C(194), UINT8_C( 23), UINT8_C( 61), UINT8_C(136),
        UINT8_C( 34), UINT8_C(126), UINT8_C(206), UINT8_C(245), UINT8_C(185), UINT8_C( 75), UINT8_C(250), UINT8_C(213) },
      {
          { UINT8_C( 27), UINT8_C(203), UINT8_C( 72), UINT8_C( 66), UINT8_C(200),    UINT8_MAX, UINT8_C( 88), UINT8_C(213),
            UINT8_C(225), UINT8_C(194), UINT8_C(164), UINT8_C( 23), UINT8_C( 73), UINT8_C( 61), UINT8_C(102), UINT8_C(136) },
          { UINT8_C(240), UINT8_C( 34), UINT8_C( 68), UINT8_C(126), UINT8_C( 33), UINT8_C(206), UINT8_C( 55), UINT8_C(245),
            UINT8_C( 37), UINT8_C(185), UINT8_C(198), UINT8_C( 75), UINT8_C(123), UINT8_C(250), UINT8_C( 52), UINT8_C(213) },
      },
    },
    { { UINT8_C(147), UINT8_C(194), UINT8_C( 45), UINT8_C(117), UINT8_C(102), UINT8_C(118), UINT8_C(219), UINT8_C( 86),
        UINT8_C(186), UINT8_C(252), UINT8_C(142), UINT8_C(224), UINT8_C(194), UINT8_C(  9), UINT8_C( 20), UINT8_C(141) },
      { UINT8_C( 75), UINT8_C( 19), UINT8_C( 98), UINT8_C( 14), UINT8_C( 43), UINT8_C(160), UINT8_C(150), UINT8_C( 77),
        UINT8_C( 30), UINT8_C(101), UINT8_C( 66), UINT8_C(215), UINT8_C(176), UINT8_C( 61), UINT8_C(172), UINT8_C( 68) },
      {
          { UINT8_C(147), UINT8_C( 75), UINT8_C(194), UINT8_C( 19), UINT8_C( 45), UINT8_C( 98), UINT8_C(117), UINT8_C( 14),
            UINT8_C(102), UINT8_C( 43), UINT8_C(118), UINT8_C(160), UINT8_C(219), UINT8_C(150), UINT8_C( 86), UINT8_C( 77) },
          { UINT8_C(186), UINT8_C( 30), UINT8_C(252), UINT8_C(101), UINT8_C(142), UINT8_C( 66), UINT8_C(224), UINT8_C(215),
            UINT8_C(194), UINT8_C(176), UINT8_C(  9), UINT8_C( 61), UINT8_C( 20), UINT8_C(172), UINT8_C(141), UINT8_C( 68) },
      },
    },
    { {    UINT8_MAX, UINT8_C(218), UINT8_C(185), UINT8_C(102), UINT8_C( 80), UINT8_C(148), UINT8_C(188), UINT8_C( 11),
        UINT8_C(144), UINT8_C( 74), UINT8_C(235), UINT8_C( 82), UINT8_C( 84),    UINT8_MAX, UINT8_C(223), UINT8_C(159) },
      { UINT8_C( 19), UINT8_C( 66), UINT8_C(173), UINT8_C( 62), UINT8_C(226), UINT8_C( 68), UINT8_C(139), UINT8_C(  0),
        UINT8_C(169), UINT8_C(205), UINT8_C(215), UINT8_C( 89), UINT8_C( 10), UINT8_C(132), UINT8_C(157), UINT8_C( 10) },
      {
          {    UINT8_MAX, UINT8_C( 19), UINT8_C(218), UINT8_C( 66), UINT8_C(185), UINT8_C(173), UINT8_C(102), UINT8_C( 62),
            UINT8_C( 80), UINT8_C(226), UINT8_C(148), UINT8_C( 68), UINT8_C(188), UINT8_C(139), UINT8_C( 11), UINT8_C(  0) },
          { UINT8_C(144), UINT8_C(169), UINT8_C( 74), UINT8_C(205), UINT8_C(235), UINT8_C(215), UINT8_C( 82), UINT8_C( 89),
            UINT8_C( 84), UINT8_C( 10),    UINT8_MAX, UINT8_C(132), UINT8_C(223), UINT8_C(157), UINT8_C(159), UINT8_C( 10) },
      },
    },
    { { UINT8_C( 94), UINT8_C( 86), UINT8_C(112), UINT8_C(174), UINT8_C(234), UINT8_C( 44), UINT8_C(185), UINT8_C(122),
        UINT8_C(119), UINT8_C(164), UINT8_C(204), UINT8_C(203), UINT8_C(164), UINT8_C(172), UINT8_C(106), UINT8_C(183) },
      { UINT8_C(238), UINT8_C( 24), UINT8_C(245), UINT8_C(208), UINT8_C( 92), UINT8_C(128), UINT8_C(208), UINT8_C(  5),
        UINT8_C( 77), UINT8_C(167), UINT8_C( 94), UINT8_C( 88), UINT8_C( 43), UINT8_C(252), UINT8_C( 98), UINT8_C(137) },
      {
          { UINT8_C( 94), UINT8_C(238), UINT8_C( 86), UINT8_C( 24), UINT8_C(112), UINT8_C(245), UINT8_C(174), UINT8_C(208),
            UINT8_C(234), UINT8_C( 92), UINT8_C( 44), UINT8_C(128), UINT8_C(185), UINT8_C(208), UINT8_C(122), UINT8_C(  5) },
          { UINT8_C(119), UINT8_C( 77), UINT8_C(164), UINT8_C(167), UINT8_C(204), UINT8_C( 94), UINT8_C(203), UINT8_C( 88),
            UINT8_C(164), UINT8_C( 43), UINT8_C(172), UINT8_C(252), UINT8_C(106), UINT8_C( 98), UINT8_C(183), UINT8_C(137) },
      },
    },
    { { UINT8_C( 82), UINT8_C(210), UINT8_C( 56), UINT8_C( 61), UINT8_C(254), UINT8_C(241), UINT8_C(183), UINT8_C(117),
        UINT8_C(150), UINT8_C(132), UINT8_C( 64), UINT8_C( 58), UINT8_C( 48), UINT8_C(171), UINT8_C(241), UINT8_C( 30) },
      { UINT8_C(195), UINT8_C(230), UINT8_C(238), UINT8_C( 31), UINT8_C(102), UINT8_C(190), UINT8_C( 36), UINT8_C(179),
        UINT8_C(101), UINT8_C(130), UINT8_C( 11), UINT8_C(145), UINT8_C(126), UINT8_C(109), UINT8_C( 26), UINT8_C(209) },
      {
          { UINT8_C( 82), UINT8_C(195), UINT8_C(210), UINT8_C(230), UINT8_C( 56), UINT8_C(238), UINT8_C( 61), UINT8_C( 31),
            UINT8_C(254), UINT8_C(102), UINT8_C(241), UINT8_C(190), UINT8_C(183), UINT8_C( 36), UINT8_C(117), UINT8_C(179) },
          { UINT8_C(150), UINT8_C(101), UINT8_C(132), UINT8_C(130), UINT8_C( 64), UINT8_C( 11), UINT8_C( 58), UINT8_C(145),
            UINT8_C( 48), UINT8_C(126), UINT8_C(171), UINT8_C(109), UINT8_C(241), UINT8_C( 26), UINT8_C( 30), UINT8_C(209) },
      },
    },
    { { UINT8_C( 63), UINT8_C( 82), UINT8_C( 14), UINT8_C( 62), UINT8_C( 68), UINT8_C(197), UINT8_C(179), UINT8_C(218),
        UINT8_C( 73), UINT8_C(244), UINT8_C( 20), UINT8_C(121), UINT8_C(159), UINT8_C(  5), UINT8_C(151), UINT8_C( 98) },
      { UINT8_C(235), UINT8_C(133), UINT8_C(129), UINT8_C( 81), UINT8_C( 67), UINT8_C(165), UINT8_C(  4), UINT8_C(169),
        UINT8_C( 39), UINT8_C( 16), UINT8_C( 58), UINT8_C(166), UINT8_C(125), UINT8_C( 84), UINT8_C(119), UINT8_C(189) },
      {
          { UINT8_C( 63), UINT8_C(235), UINT8_C( 82), UINT8_C(133), UINT8_C( 14), UINT8_C(129), UINT8_C( 62), UINT8_C( 81),
            UINT8_C( 68), UINT8_C( 67), UINT8_C(197), UINT8_C(165), UINT8_C(179), UINT8_C(  4), UINT8_C(218), UINT8_C(169) },
          { UINT8_C( 73), UINT8_C( 39), UINT8_C(244), UINT8_C( 16), UINT8_C( 20), UINT8_C( 58), UINT8_C(121), UINT8_C(166),
            UINT8_C(159), UINT8_C(125), UINT8_C(  5), UINT8_C( 84), UINT8_C(151), UINT8_C(119), UINT8_C( 98), UINT8_C(189) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16x2_t r = simde_vzipq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], simde_vld1q_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], simde_vld1q_u8(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzipq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[2][8];
  } test_vec[] = {
    { { UINT16_C(36776), UINT16_C(50991), UINT16_C(55785), UINT16_C( 4670), UINT16_C(53567), UINT16_C(64246), UINT16_C(18557), UINT16_C(28447) },
      { UINT16_C(38812), UINT16_C(39983), UINT16_C(53745), UINT16_C(29110), UINT16_C(47188), UINT16_C(39243), UINT16_C(50912), UINT16_C(34824) },
      {
          { UINT16_C(36776), UINT16_C(38812), UINT16_C(50991), UINT16_C(39983), UINT16_C(55785), UINT16_C(53745), UINT16_C( 4670), UINT16_C(29110) },
          { UINT16_C(53567), UINT16_C(47188), UINT16_C(64246), UINT16_C(39243), UINT16_C(18557), UINT16_C(50912), UINT16_C(28447), UINT16_C(34824) },
      },
    },
    { { UINT16_C(14166), UINT16_C(16207), UINT16_C(36113), UINT16_C(20561), UINT16_C(18271), UINT16_C(56394), UINT16_C(27280), UINT16_C(11339) },
      { UINT16_C(31233), UINT16_C(62408), UINT16_C(32331), UINT16_C(41060), UINT16_C(44854), UINT16_C( 5945), UINT16_C(16758), UINT16_C(52383) },
      {
          { UINT16_C(14166), UINT16_C(31233), UINT16_C(16207), UINT16_C(62408), UINT16_C(36113), UINT16_C(32331), UINT16_C(20561), UINT16_C(41060) },
          { UINT16_C(18271), UINT16_C(44854), UINT16_C(56394), UINT16_C( 5945), UINT16_C(27280), UINT16_C(16758), UINT16_C(11339), UINT16_C(52383) },
      },
    },
    { { UINT16_C(61304), UINT16_C(35083), UINT16_C(23932), UINT16_C(56282), UINT16_C( 9380), UINT16_C(13496), UINT16_C(  910), UINT16_C(36961) },
      { UINT16_C(10622), UINT16_C(51587), UINT16_C(59304), UINT16_C(56937), UINT16_C(41623), UINT16_C( 3573), UINT16_C(38371), UINT16_C(23769) },
      {
          { UINT16_C(61304), UINT16_C(10622), UINT16_C(35083), UINT16_C(51587), UINT16_C(23932), UINT16_C(59304), UINT16_C(56282), UINT16_C(56937) },
          { UINT16_C( 9380), UINT16_C(41623), UINT16_C(13496), UINT16_C( 3573), UINT16_C(  910), UINT16_C(38371), UINT16_C(36961), UINT16_C(23769) },
      },
    },
    { { UINT16_C(58500), UINT16_C(  229), UINT16_C(48961), UINT16_C(59100), UINT16_C(38116), UINT16_C(29210), UINT16_C(31639), UINT16_C( 5378) },
      { UINT16_C(34213), UINT16_C(19935), UINT16_C(18541), UINT16_C( 1067), UINT16_C( 8683), UINT16_C(52753), UINT16_C(60086), UINT16_C(14890) },
      {
          { UINT16_C(58500), UINT16_C(34213), UINT16_C(  229), UINT16_C(19935), UINT16_C(48961), UINT16_C(18541), UINT16_C(59100), UINT16_C( 1067) },
          { UINT16_C(38116), UINT16_C( 8683), UINT16_C(29210), UINT16_C(52753), UINT16_C(31639), UINT16_C(60086), UINT16_C( 5378), UINT16_C(14890) },
      },
    },
    { { UINT16_C( 4302), UINT16_C( 4154), UINT16_C( 5839), UINT16_C(46070), UINT16_C( 4266), UINT16_C(16934), UINT16_C(10380), UINT16_C(12631) },
      { UINT16_C(13998), UINT16_C( 7038), UINT16_C(43391), UINT16_C(27167), UINT16_C(12490), UINT16_C(32824), UINT16_C(25370), UINT16_C(59578) },
      {
          { UINT16_C( 4302), UINT16_C(13998), UINT16_C( 4154), UINT16_C( 7038), UINT16_C( 5839), UINT16_C(43391), UINT16_C(46070), UINT16_C(27167) },
          { UINT16_C( 4266), UINT16_C(12490), UINT16_C(16934), UINT16_C(32824), UINT16_C(10380), UINT16_C(25370), UINT16_C(12631), UINT16_C(59578) },
      },
    },
    { { UINT16_C(62835), UINT16_C(17144), UINT16_C(60939), UINT16_C(46838), UINT16_C( 7423), UINT16_C(35832), UINT16_C(20292), UINT16_C(62140) },
      { UINT16_C(14982), UINT16_C( 1293), UINT16_C(11491), UINT16_C(44655), UINT16_C(42844), UINT16_C(30254), UINT16_C(59658), UINT16_C(32095) },
      {
          { UINT16_C(62835), UINT16_C(14982), UINT16_C(17144), UINT16_C( 1293), UINT16_C(60939), UINT16_C(11491), UINT16_C(46838), UINT16_C(44655) },
          { UINT16_C( 7423), UINT16_C(42844), UINT16_C(35832), UINT16_C(30254), UINT16_C(20292), UINT16_C(59658), UINT16_C(62140), UINT16_C(32095) },
      },
    },
    { { UINT16_C(22494), UINT16_C(59840), UINT16_C(46662), UINT16_C(17823), UINT16_C(38866), UINT16_C( 5840), UINT16_C(36071), UINT16_C(27913) },
      { UINT16_C( 5830), UINT16_C(43378), UINT16_C(57667), UINT16_C(40791), UINT16_C(34440), UINT16_C(37654), UINT16_C(30063), UINT16_C(19728) },
      {
          { UINT16_C(22494), UINT16_C( 5830), UINT16_C(59840), UINT16_C(43378), UINT16_C(46662), UINT16_C(57667), UINT16_C(17823), UINT16_C(40791) },
          { UINT16_C(38866), UINT16_C(34440), UINT16_C( 5840), UINT16_C(37654), UINT16_C(36071), UINT16_C(30063), UINT16_C(27913), UINT16_C(19728) },
      },
    },
    { { UINT16_C(53452), UINT16_C( 4662), UINT16_C(54918), UINT16_C(22615), UINT16_C(10093), UINT16_C(21615), UINT16_C(30899), UINT16_C(31169) },
      { UINT16_C(13198), UINT16_C(53539), UINT16_C(31252), UINT16_C(40305), UINT16_C(34560), UINT16_C(28464), UINT16_C(16636), UINT16_C(51388) },
      {
          { UINT16_C(53452), UINT16_C(13198), UINT16_C( 4662), UINT16_C(53539), UINT16_C(54918), UINT16_C(31252), UINT16_C(22615), UINT16_C(40305) },
          { UINT16_C(10093), UINT16_C(34560), UINT16_C(21615), UINT16_C(28464), UINT16_C(30899), UINT16_C(16636), UINT16_C(31169), UINT16_C(51388) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8x2_t r = simde_vzipq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r.val[0], simde_vld1q_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], simde_vld1q_u16(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vzipq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[2][4];
  } test_vec[] = {
    { { UINT32_C(4087665949), UINT32_C(3816891322), UINT32_C(3003239570), UINT32_C(1218963958) },
      { UINT32_C(3855336699), UINT32_C(2367470621), UINT32_C(2238585450), UINT32_C(2997669013) },
      {
          { UINT32_C(4087665949), UINT32_C(3855336699), UINT32_C(3816891322), UINT32_C(2367470621) },
          { UINT32_C(3003239570), UINT32_C(2238585450), UINT32_C(1218963958), UINT32_C(2997669013) },
      },
    },
    { { UINT32_C(1554403489), UINT32_C( 104802163), UINT32_C(3921232115), UINT32_C( 607215657) },
      { UINT32_C(1091239204), UINT32_C( 617555641), UINT32_C(3601415489), UINT32_C(2877904137) },
      {
          { UINT32_C(1554403489), UINT32_C(1091239204), UINT32_C( 104802163), UINT32_C( 617555641) },
          { UINT32_C(3921232115), UINT32_C(3601415489), UINT32_C( 607215657), UINT32_C(2877904137) },
      },
    },
    { { UINT32_C( 419901350), UINT32_C(1243563606), UINT32_C(2939410566), UINT32_C(1574135096) },
      { UINT32_C( 463396194), UINT32_C(1161784580), UINT32_C(3021728171), UINT32_C(3831473214) },
      {
          { UINT32_C( 419901350), UINT32_C( 463396194), UINT32_C(1243563606), UINT32_C(1161784580) },
          { UINT32_C(2939410566), UINT32_C(3021728171), UINT32_C(1574135096), UINT32_C(3831473214) },
      },
    },
    { { UINT32_C( 721315539), UINT32_C( 846470572), UINT32_C( 786540534), UINT32_C(1854649612) },
      { UINT32_C(2525637266), UINT32_C(1121700247), UINT32_C(4059559858), UINT32_C(1876252315) },
      {
          { UINT32_C( 721315539), UINT32_C(2525637266), UINT32_C( 846470572), UINT32_C(1121700247) },
          { UINT32_C( 786540534), UINT32_C(4059559858), UINT32_C(1854649612), UINT32_C(1876252315) },
      },
    },
    { { UINT32_C(1771688893), UINT32_C(3885764081), UINT32_C(3239411124), UINT32_C(3308233010) },
      { UINT32_C(1650178507), UINT32_C( 900020099), UINT32_C(3374750766), UINT32_C(2939747570) },
      {
          { UINT32_C(1771688893), UINT32_C(1650178507), UINT32_C(3885764081), UINT32_C( 900020099) },
          { UINT32_C(3239411124), UINT32_C(3374750766), UINT32_C(3308233010), UINT32_C(2939747570) },
      },
    },
    { { UINT32_C(3222917583), UINT32_C(2477241822), UINT32_C(1700052274), UINT32_C( 690651998) },
      { UINT32_C(3230369085), UINT32_C(3941937340), UINT32_C(3216252108), UINT32_C(3882806296) },
      {
          { UINT32_C(3222917583), UINT32_C(3230369085), UINT32_C(2477241822), UINT32_C(3941937340) },
          { UINT32_C(1700052274), UINT32_C(3216252108), UINT32_C( 690651998), UINT32_C(3882806296) },
      },
    },
    { { UINT32_C(2628290494), UINT32_C(1865371452), UINT32_C(1792312076), UINT32_C(1150549511) },
      { UINT32_C(1074012035), UINT32_C( 472578383), UINT32_C( 769383957), UINT32_C(2299873739) },
      {
          { UINT32_C(2628290494), UINT32_C(1074012035), UINT32_C(1865371452), UINT32_C( 472578383) },
          { UINT32_C(1792312076), UINT32_C( 769383957), UINT32_C(1150549511), UINT32_C(2299873739) },
      },
    },
    { { UINT32_C( 220577233), UINT32_C( 427578636), UINT32_C(3749925080), UINT32_C(3525515086) },
      { UINT32_C(2232559414), UINT32_C( 916536353), UINT32_C(3865345051), UINT32_C(2540665286) },
      {
          { UINT32_C( 220577233), UINT32_C(2232559414), UINT32_C( 427578636), UINT32_C( 916536353) },
          { UINT32_C(3749925080), UINT32_C(3865345051), UINT32_C(3525515086), UINT32_C(2540665286) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4x2_t r = simde_vzipq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], simde_vld1q_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], simde_vld1q_u32(test_vec[i].r[1]));
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vzipq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzipq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzipq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzipq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzipq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzipq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzipq_u32)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
