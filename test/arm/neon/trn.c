#define SIMDE_TEST_ARM_NEON_INSN trn

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/trn.h>

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vtrn_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2][2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   394.91), SIMDE_FLOAT32_C(   715.66) },
      { SIMDE_FLOAT32_C(  -854.42), SIMDE_FLOAT32_C(   359.77) },
      {
          { SIMDE_FLOAT32_C(   394.91), SIMDE_FLOAT32_C(  -854.42) },
          { SIMDE_FLOAT32_C(   715.66), SIMDE_FLOAT32_C(   359.77) },
      },
    },
    { { SIMDE_FLOAT32_C(  -579.97), SIMDE_FLOAT32_C(  -698.40) },
      { SIMDE_FLOAT32_C(   147.69), SIMDE_FLOAT32_C(   533.92) },
      {
          { SIMDE_FLOAT32_C(  -579.97), SIMDE_FLOAT32_C(   147.69) },
          { SIMDE_FLOAT32_C(  -698.40), SIMDE_FLOAT32_C(   533.92) },
      },
    },
    { { SIMDE_FLOAT32_C(  -647.47), SIMDE_FLOAT32_C(   944.41) },
      { SIMDE_FLOAT32_C(  -570.83), SIMDE_FLOAT32_C(  -698.09) },
      {
          { SIMDE_FLOAT32_C(  -647.47), SIMDE_FLOAT32_C(  -570.83) },
          { SIMDE_FLOAT32_C(   944.41), SIMDE_FLOAT32_C(  -698.09) },
      },
    },
    { { SIMDE_FLOAT32_C(  -636.98), SIMDE_FLOAT32_C(   269.75) },
      { SIMDE_FLOAT32_C(   457.30), SIMDE_FLOAT32_C(  -517.32) },
      {
          { SIMDE_FLOAT32_C(  -636.98), SIMDE_FLOAT32_C(   457.30) },
          { SIMDE_FLOAT32_C(   269.75), SIMDE_FLOAT32_C(  -517.32) },
      },
    },
    { { SIMDE_FLOAT32_C(   625.59), SIMDE_FLOAT32_C(   316.45) },
      { SIMDE_FLOAT32_C(  -969.65), SIMDE_FLOAT32_C(   377.99) },
      {
          { SIMDE_FLOAT32_C(   625.59), SIMDE_FLOAT32_C(  -969.65) },
          { SIMDE_FLOAT32_C(   316.45), SIMDE_FLOAT32_C(   377.99) },
      },
    },
    { { SIMDE_FLOAT32_C(   858.52), SIMDE_FLOAT32_C(  -465.14) },
      { SIMDE_FLOAT32_C(   468.83), SIMDE_FLOAT32_C(   -15.96) },
      {
          { SIMDE_FLOAT32_C(   858.52), SIMDE_FLOAT32_C(   468.83) },
          { SIMDE_FLOAT32_C(  -465.14), SIMDE_FLOAT32_C(   -15.96) },
      },
    },
    { { SIMDE_FLOAT32_C(   -52.83), SIMDE_FLOAT32_C(   881.31) },
      { SIMDE_FLOAT32_C(  -110.73), SIMDE_FLOAT32_C(   761.20) },
      {
          { SIMDE_FLOAT32_C(   -52.83), SIMDE_FLOAT32_C(  -110.73) },
          { SIMDE_FLOAT32_C(   881.31), SIMDE_FLOAT32_C(   761.20) },
      },
    },
    { { SIMDE_FLOAT32_C(  -940.87), SIMDE_FLOAT32_C(   486.49) },
      { SIMDE_FLOAT32_C(   618.70), SIMDE_FLOAT32_C(   454.05) },
      {
          { SIMDE_FLOAT32_C(  -940.87), SIMDE_FLOAT32_C(   618.70) },
          { SIMDE_FLOAT32_C(   486.49), SIMDE_FLOAT32_C(   454.05) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2x2_t r = simde_vtrn_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], simde_vld1_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], simde_vld1_f32(test_vec[i].r[1]), 1);
  }

  return 0;
}

static int
test_simde_vtrn_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[2][8];
  } test_vec[] = {
    { { -INT8_C(  66),  INT8_C(  38), -INT8_C(  90),  INT8_C(  86),  INT8_C(  96),  INT8_C(  65),  INT8_C(  68), -INT8_C(  61) },
      {  INT8_C( 123),  INT8_C(  78), -INT8_C(  60),  INT8_C( 111),  INT8_C(  17),  INT8_C(   8),  INT8_C(  37),  INT8_C(  95) },
      {
          { -INT8_C(  66),  INT8_C( 123), -INT8_C(  90), -INT8_C(  60),  INT8_C(  96),  INT8_C(  17),  INT8_C(  68),  INT8_C(  37) },
          {  INT8_C(  38),  INT8_C(  78),  INT8_C(  86),  INT8_C( 111),  INT8_C(  65),  INT8_C(   8), -INT8_C(  61),  INT8_C(  95) },
      },
    },
    { { -INT8_C(  36),  INT8_C( 105),  INT8_C(  18),  INT8_C(  56), -INT8_C(  95),  INT8_C(  16), -INT8_C(  54),  INT8_C(  86) },
      { -INT8_C(  27), -INT8_C(  28), -INT8_C( 104), -INT8_C(  70), -INT8_C(  36),  INT8_C( 120), -INT8_C(  63), -INT8_C( 102) },
      {
          { -INT8_C(  36), -INT8_C(  27),  INT8_C(  18), -INT8_C( 104), -INT8_C(  95), -INT8_C(  36), -INT8_C(  54), -INT8_C(  63) },
          {  INT8_C( 105), -INT8_C(  28),  INT8_C(  56), -INT8_C(  70),  INT8_C(  16),  INT8_C( 120),  INT8_C(  86), -INT8_C( 102) },
      },
    },
    { { -INT8_C(  98),  INT8_C( 103), -INT8_C(  16), -INT8_C(   1), -INT8_C(  88),  INT8_C(  52), -INT8_C(  62),  INT8_C(  35) },
      { -INT8_C( 126), -INT8_C( 121), -INT8_C( 109), -INT8_C( 108), -INT8_C( 113), -INT8_C(  72), -INT8_C(  13),  INT8_C( 107) },
      {
          { -INT8_C(  98), -INT8_C( 126), -INT8_C(  16), -INT8_C( 109), -INT8_C(  88), -INT8_C( 113), -INT8_C(  62), -INT8_C(  13) },
          {  INT8_C( 103), -INT8_C( 121), -INT8_C(   1), -INT8_C( 108),  INT8_C(  52), -INT8_C(  72),  INT8_C(  35),  INT8_C( 107) },
      },
    },
    { {  INT8_C(  33),  INT8_C(   5), -INT8_C(  93), -INT8_C(  62),  INT8_C(  21),  INT8_C( 110),  INT8_C(  24), -INT8_C(   5) },
      {  INT8_C(  82), -INT8_C(  80), -INT8_C(  75),  INT8_C(  46),  INT8_C(  40),  INT8_C( 118), -INT8_C(  56), -INT8_C(  57) },
      {
          {  INT8_C(  33),  INT8_C(  82), -INT8_C(  93), -INT8_C(  75),  INT8_C(  21),  INT8_C(  40),  INT8_C(  24), -INT8_C(  56) },
          {  INT8_C(   5), -INT8_C(  80), -INT8_C(  62),  INT8_C(  46),  INT8_C( 110),  INT8_C( 118), -INT8_C(   5), -INT8_C(  57) },
      },
    },
    { { -INT8_C(  35), -INT8_C(  72), -INT8_C(  58), -INT8_C( 123), -INT8_C(  19), -INT8_C( 120), -INT8_C(  87),  INT8_C( 111) },
      {  INT8_C(  15),  INT8_C(  60),  INT8_C(   3), -INT8_C(  98), -INT8_C(  12), -INT8_C(  10),  INT8_C(   9),  INT8_C(  21) },
      {
          { -INT8_C(  35),  INT8_C(  15), -INT8_C(  58),  INT8_C(   3), -INT8_C(  19), -INT8_C(  12), -INT8_C(  87),  INT8_C(   9) },
          { -INT8_C(  72),  INT8_C(  60), -INT8_C( 123), -INT8_C(  98), -INT8_C( 120), -INT8_C(  10),  INT8_C( 111),  INT8_C(  21) },
      },
    },
    { { -INT8_C(   5), -INT8_C(  83), -INT8_C(  41),  INT8_C(  17),  INT8_C(  27), -INT8_C(  17),  INT8_C(  12),  INT8_C( 109) },
      { -INT8_C(  97), -INT8_C(  63), -INT8_C( 101), -INT8_C(  56),  INT8_C(  55),  INT8_C(  99), -INT8_C( 113),  INT8_C(  20) },
      {
          { -INT8_C(   5), -INT8_C(  97), -INT8_C(  41), -INT8_C( 101),  INT8_C(  27),  INT8_C(  55),  INT8_C(  12), -INT8_C( 113) },
          { -INT8_C(  83), -INT8_C(  63),  INT8_C(  17), -INT8_C(  56), -INT8_C(  17),  INT8_C(  99),  INT8_C( 109),  INT8_C(  20) },
      },
    },
    { {  INT8_C(  27),  INT8_C(  85), -INT8_C( 103),  INT8_C(   8), -INT8_C(  35),  INT8_C(  66),  INT8_C( 120), -INT8_C(  19) },
      {  INT8_C( 126),  INT8_C( 123), -INT8_C( 117),  INT8_C( 114),  INT8_C( 114), -INT8_C( 107), -INT8_C( 121),  INT8_C( 109) },
      {
          {  INT8_C(  27),  INT8_C( 126), -INT8_C( 103), -INT8_C( 117), -INT8_C(  35),  INT8_C( 114),  INT8_C( 120), -INT8_C( 121) },
          {  INT8_C(  85),  INT8_C( 123),  INT8_C(   8),  INT8_C( 114),  INT8_C(  66), -INT8_C( 107), -INT8_C(  19),  INT8_C( 109) },
      },
    },
    { {  INT8_C(  66),  INT8_C(  94),  INT8_C( 126),  INT8_C(  93),  INT8_C(  77), -INT8_C( 118), -INT8_C(  54), -INT8_C(  19) },
      {  INT8_C(  75),  INT8_C( 101), -INT8_C(  75), -INT8_C( 126), -INT8_C(  56),  INT8_C(  68), -INT8_C( 106), -INT8_C(  29) },
      {
          {  INT8_C(  66),  INT8_C(  75),  INT8_C( 126), -INT8_C(  75),  INT8_C(  77), -INT8_C(  56), -INT8_C(  54), -INT8_C( 106) },
          {  INT8_C(  94),  INT8_C( 101),  INT8_C(  93), -INT8_C( 126), -INT8_C( 118),  INT8_C(  68), -INT8_C(  19), -INT8_C(  29) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8x2_t r = simde_vtrn_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], simde_vld1_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], simde_vld1_s8(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrn_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[2][4];
  } test_vec[] = {
    { {  INT16_C( 29957), -INT16_C( 14479), -INT16_C( 14585),  INT16_C( 20407) },
      { -INT16_C( 13813), -INT16_C(  5946), -INT16_C(  9907),  INT16_C( 28653) },
      {
          {  INT16_C( 29957), -INT16_C( 13813), -INT16_C( 14585), -INT16_C(  9907) },
          { -INT16_C( 14479), -INT16_C(  5946),  INT16_C( 20407),  INT16_C( 28653) },
      },
    },
    { { -INT16_C(  5745),  INT16_C( 30710),  INT16_C( 14724), -INT16_C( 32756) },
      {  INT16_C( 19325), -INT16_C( 32716), -INT16_C( 11477),  INT16_C( 12334) },
      {
          { -INT16_C(  5745),  INT16_C( 19325),  INT16_C( 14724), -INT16_C( 11477) },
          {  INT16_C( 30710), -INT16_C( 32716), -INT16_C( 32756),  INT16_C( 12334) },
      },
    },
    { { -INT16_C( 24760),  INT16_C( 20728), -INT16_C( 20633),  INT16_C( 29343) },
      {  INT16_C( 25978), -INT16_C( 14502),  INT16_C( 18494), -INT16_C( 12746) },
      {
          { -INT16_C( 24760),  INT16_C( 25978), -INT16_C( 20633),  INT16_C( 18494) },
          {  INT16_C( 20728), -INT16_C( 14502),  INT16_C( 29343), -INT16_C( 12746) },
      },
    },
    { {  INT16_C( 11313), -INT16_C( 18875),  INT16_C( 21093), -INT16_C(  7626) },
      {  INT16_C( 27293), -INT16_C( 14238), -INT16_C( 28355), -INT16_C( 30983) },
      {
          {  INT16_C( 11313),  INT16_C( 27293),  INT16_C( 21093), -INT16_C( 28355) },
          { -INT16_C( 18875), -INT16_C( 14238), -INT16_C(  7626), -INT16_C( 30983) },
      },
    },
    { { -INT16_C(  3792), -INT16_C( 26666),  INT16_C( 30112),  INT16_C(  6666) },
      {  INT16_C( 25818),  INT16_C(  6625),  INT16_C(  6060), -INT16_C(  8473) },
      {
          { -INT16_C(  3792),  INT16_C( 25818),  INT16_C( 30112),  INT16_C(  6060) },
          { -INT16_C( 26666),  INT16_C(  6625),  INT16_C(  6666), -INT16_C(  8473) },
      },
    },
    { {  INT16_C( 11331), -INT16_C( 22380), -INT16_C( 13698),  INT16_C(  7051) },
      { -INT16_C(  4811),  INT16_C( 29412), -INT16_C(  8834), -INT16_C( 20488) },
      {
          {  INT16_C( 11331), -INT16_C(  4811), -INT16_C( 13698), -INT16_C(  8834) },
          { -INT16_C( 22380),  INT16_C( 29412),  INT16_C(  7051), -INT16_C( 20488) },
      },
    },
    { { -INT16_C( 12594),  INT16_C( 28230),  INT16_C( 20547),  INT16_C(  7817) },
      {  INT16_C( 27317),  INT16_C( 24887),  INT16_C(  7810), -INT16_C( 15041) },
      {
          { -INT16_C( 12594),  INT16_C( 27317),  INT16_C( 20547),  INT16_C(  7810) },
          {  INT16_C( 28230),  INT16_C( 24887),  INT16_C(  7817), -INT16_C( 15041) },
      },
    },
    { { -INT16_C( 11446), -INT16_C( 13970), -INT16_C(  1634), -INT16_C( 11292) },
      { -INT16_C( 14106),  INT16_C( 25925),  INT16_C( 16037),  INT16_C( 29460) },
      {
          { -INT16_C( 11446), -INT16_C( 14106), -INT16_C(  1634),  INT16_C( 16037) },
          { -INT16_C( 13970),  INT16_C( 25925), -INT16_C( 11292),  INT16_C( 29460) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4x2_t r = simde_vtrn_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], simde_vld1_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], simde_vld1_s16(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrn_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2][2];
  } test_vec[] = {
    { {  INT32_C(  2034330713), -INT32_C(   659240214) },
      { -INT32_C(   236237116),  INT32_C(   331646780) },
      {
          {  INT32_C(  2034330713), -INT32_C(   236237116) },
          { -INT32_C(   659240214),  INT32_C(   331646780) },
      },
    },
    { { -INT32_C(  1506908108),  INT32_C(  1079419151) },
      { -INT32_C(  1477742611),  INT32_C(   506021572) },
      {
          { -INT32_C(  1506908108), -INT32_C(  1477742611) },
          {  INT32_C(  1079419151),  INT32_C(   506021572) },
      },
    },
    { { -INT32_C(  1667798350), -INT32_C(   126596300) },
      { -INT32_C(   689348711),  INT32_C(   468299494) },
      {
          { -INT32_C(  1667798350), -INT32_C(   689348711) },
          { -INT32_C(   126596300),  INT32_C(   468299494) },
      },
    },
    { {  INT32_C(   633411606), -INT32_C(  1503323975) },
      {  INT32_C(  1280135559),  INT32_C(  1231713943) },
      {
          {  INT32_C(   633411606),  INT32_C(  1280135559) },
          { -INT32_C(  1503323975),  INT32_C(  1231713943) },
      },
    },
    { {  INT32_C(   367329760), -INT32_C(   452110004) },
      { -INT32_C(  1615071303), -INT32_C(  1145395803) },
      {
          {  INT32_C(   367329760), -INT32_C(  1615071303) },
          { -INT32_C(   452110004), -INT32_C(  1145395803) },
      },
    },
    { {  INT32_C(  1994423485),  INT32_C(   454837908) },
      {  INT32_C(   778529175), -INT32_C(  1082666529) },
      {
          {  INT32_C(  1994423485),  INT32_C(   778529175) },
          {  INT32_C(   454837908), -INT32_C(  1082666529) },
      },
    },
    { {  INT32_C(   517233874),  INT32_C(  1845813941) },
      {  INT32_C(  2114895833),  INT32_C(   557434980) },
      {
          {  INT32_C(   517233874),  INT32_C(  2114895833) },
          {  INT32_C(  1845813941),  INT32_C(   557434980) },
      },
    },
    { { -INT32_C(   661186236), -INT32_C(   151735457) },
      { -INT32_C(    81503460), -INT32_C(     4482259) },
      {
          { -INT32_C(   661186236), -INT32_C(    81503460) },
          { -INT32_C(   151735457), -INT32_C(     4482259) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2x2_t r = simde_vtrn_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], simde_vld1_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], simde_vld1_s32(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrn_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[2][8];
  } test_vec[] = {
    { { UINT8_C(156), UINT8_C(211), UINT8_C(239), UINT8_C(201), UINT8_C(251), UINT8_C( 68), UINT8_C(216), UINT8_C(173) },
      { UINT8_C(147), UINT8_C( 21), UINT8_C( 33), UINT8_C(140), UINT8_C(167), UINT8_C(115), UINT8_C( 36), UINT8_C( 31) },
      {
          { UINT8_C(156), UINT8_C(147), UINT8_C(239), UINT8_C( 33), UINT8_C(251), UINT8_C(167), UINT8_C(216), UINT8_C( 36) },
          { UINT8_C(211), UINT8_C( 21), UINT8_C(201), UINT8_C(140), UINT8_C( 68), UINT8_C(115), UINT8_C(173), UINT8_C( 31) },
      },
    },
    { { UINT8_C( 53), UINT8_C( 85), UINT8_C(184), UINT8_C( 44), UINT8_C(  3), UINT8_C(  4), UINT8_C(166), UINT8_C( 52) },
      { UINT8_C( 61), UINT8_C(108), UINT8_C( 17), UINT8_C( 42), UINT8_C( 56), UINT8_C(179), UINT8_C(216), UINT8_C(212) },
      {
          { UINT8_C( 53), UINT8_C( 61), UINT8_C(184), UINT8_C( 17), UINT8_C(  3), UINT8_C( 56), UINT8_C(166), UINT8_C(216) },
          { UINT8_C( 85), UINT8_C(108), UINT8_C( 44), UINT8_C( 42), UINT8_C(  4), UINT8_C(179), UINT8_C( 52), UINT8_C(212) },
      },
    },
    { { UINT8_C(134), UINT8_C(199), UINT8_C(157), UINT8_C(129), UINT8_C( 11), UINT8_C(118), UINT8_C( 46), UINT8_C(158) },
      { UINT8_C(139), UINT8_C( 80), UINT8_C( 43), UINT8_C( 50), UINT8_C(195), UINT8_C( 79), UINT8_C( 81), UINT8_C(249) },
      {
          { UINT8_C(134), UINT8_C(139), UINT8_C(157), UINT8_C( 43), UINT8_C( 11), UINT8_C(195), UINT8_C( 46), UINT8_C( 81) },
          { UINT8_C(199), UINT8_C( 80), UINT8_C(129), UINT8_C( 50), UINT8_C(118), UINT8_C( 79), UINT8_C(158), UINT8_C(249) },
      },
    },
    { { UINT8_C(164), UINT8_C(  9), UINT8_C( 37), UINT8_C(167), UINT8_C( 13), UINT8_C(203), UINT8_C(219), UINT8_C( 75) },
      { UINT8_C( 56), UINT8_C(236), UINT8_C(117), UINT8_C(112), UINT8_C(159), UINT8_C( 77), UINT8_C( 69), UINT8_C( 37) },
      {
          { UINT8_C(164), UINT8_C( 56), UINT8_C( 37), UINT8_C(117), UINT8_C( 13), UINT8_C(159), UINT8_C(219), UINT8_C( 69) },
          { UINT8_C(  9), UINT8_C(236), UINT8_C(167), UINT8_C(112), UINT8_C(203), UINT8_C( 77), UINT8_C( 75), UINT8_C( 37) },
      },
    },
    { { UINT8_C( 21), UINT8_C(226), UINT8_C(166), UINT8_C( 32), UINT8_C( 88), UINT8_C(213), UINT8_C(191), UINT8_C(227) },
      { UINT8_C( 37), UINT8_C(234), UINT8_C( 22), UINT8_C(232), UINT8_C( 57), UINT8_C(103), UINT8_C(225), UINT8_C(221) },
      {
          { UINT8_C( 21), UINT8_C( 37), UINT8_C(166), UINT8_C( 22), UINT8_C( 88), UINT8_C( 57), UINT8_C(191), UINT8_C(225) },
          { UINT8_C(226), UINT8_C(234), UINT8_C( 32), UINT8_C(232), UINT8_C(213), UINT8_C(103), UINT8_C(227), UINT8_C(221) },
      },
    },
    { { UINT8_C(113), UINT8_C(  6), UINT8_C(132), UINT8_C(126), UINT8_C(210), UINT8_C( 95), UINT8_C(201), UINT8_C( 10) },
      { UINT8_C( 75), UINT8_C( 63), UINT8_C(122), UINT8_C(235), UINT8_C(140), UINT8_C(191), UINT8_C( 16), UINT8_C(161) },
      {
          { UINT8_C(113), UINT8_C( 75), UINT8_C(132), UINT8_C(122), UINT8_C(210), UINT8_C(140), UINT8_C(201), UINT8_C( 16) },
          { UINT8_C(  6), UINT8_C( 63), UINT8_C(126), UINT8_C(235), UINT8_C( 95), UINT8_C(191), UINT8_C( 10), UINT8_C(161) },
      },
    },
    { { UINT8_C(162), UINT8_C(183), UINT8_C(194), UINT8_C(250), UINT8_C(140), UINT8_C(129), UINT8_C(222), UINT8_C(177) },
      { UINT8_C(107), UINT8_C(244), UINT8_C(153), UINT8_C(164), UINT8_C( 91), UINT8_C(123), UINT8_C(129), UINT8_C(204) },
      {
          { UINT8_C(162), UINT8_C(107), UINT8_C(194), UINT8_C(153), UINT8_C(140), UINT8_C( 91), UINT8_C(222), UINT8_C(129) },
          { UINT8_C(183), UINT8_C(244), UINT8_C(250), UINT8_C(164), UINT8_C(129), UINT8_C(123), UINT8_C(177), UINT8_C(204) },
      },
    },
    { { UINT8_C(129), UINT8_C(  5), UINT8_C( 75), UINT8_C( 83), UINT8_C(100), UINT8_C( 20), UINT8_C( 93), UINT8_C(175) },
      { UINT8_C( 83), UINT8_C(216), UINT8_C(154), UINT8_C(224), UINT8_C(151), UINT8_C(171), UINT8_C(129), UINT8_C( 57) },
      {
          { UINT8_C(129), UINT8_C( 83), UINT8_C( 75), UINT8_C(154), UINT8_C(100), UINT8_C(151), UINT8_C( 93), UINT8_C(129) },
          { UINT8_C(  5), UINT8_C(216), UINT8_C( 83), UINT8_C(224), UINT8_C( 20), UINT8_C(171), UINT8_C(175), UINT8_C( 57) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8x2_t r = simde_vtrn_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], simde_vld1_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], simde_vld1_u8(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrn_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[2][4];
  } test_vec[] = {
    { { UINT16_C(39077), UINT16_C(38350), UINT16_C( 1512), UINT16_C(63202) },
      { UINT16_C(45315), UINT16_C( 4567), UINT16_C(18974), UINT16_C(10275) },
      {
          { UINT16_C(39077), UINT16_C(45315), UINT16_C( 1512), UINT16_C(18974) },
          { UINT16_C(38350), UINT16_C( 4567), UINT16_C(63202), UINT16_C(10275) },
      },
    },
    { { UINT16_C(14563), UINT16_C(36858), UINT16_C(33303), UINT16_C(63726) },
      { UINT16_C(24487), UINT16_C(30580), UINT16_C(30894), UINT16_C(21608) },
      {
          { UINT16_C(14563), UINT16_C(24487), UINT16_C(33303), UINT16_C(30894) },
          { UINT16_C(36858), UINT16_C(30580), UINT16_C(63726), UINT16_C(21608) },
      },
    },
    { { UINT16_C(13841), UINT16_C(63977), UINT16_C(52284), UINT16_C(16367) },
      { UINT16_C(50813), UINT16_C(39761), UINT16_C(29712), UINT16_C(62660) },
      {
          { UINT16_C(13841), UINT16_C(50813), UINT16_C(52284), UINT16_C(29712) },
          { UINT16_C(63977), UINT16_C(39761), UINT16_C(16367), UINT16_C(62660) },
      },
    },
    { { UINT16_C(48812), UINT16_C(50051), UINT16_C(28993), UINT16_C(59580) },
      { UINT16_C(12497), UINT16_C(32608), UINT16_C(51369), UINT16_C(47827) },
      {
          { UINT16_C(48812), UINT16_C(12497), UINT16_C(28993), UINT16_C(51369) },
          { UINT16_C(50051), UINT16_C(32608), UINT16_C(59580), UINT16_C(47827) },
      },
    },
    { { UINT16_C(48639), UINT16_C(15283), UINT16_C(41609), UINT16_C( 1658) },
      { UINT16_C(52073), UINT16_C(31138), UINT16_C(26175), UINT16_C(60269) },
      {
          { UINT16_C(48639), UINT16_C(52073), UINT16_C(41609), UINT16_C(26175) },
          { UINT16_C(15283), UINT16_C(31138), UINT16_C( 1658), UINT16_C(60269) },
      },
    },
    { { UINT16_C(61732), UINT16_C(26031), UINT16_C(27490), UINT16_C(13134) },
      { UINT16_C(44699), UINT16_C(17587), UINT16_C(34422), UINT16_C(30206) },
      {
          { UINT16_C(61732), UINT16_C(44699), UINT16_C(27490), UINT16_C(34422) },
          { UINT16_C(26031), UINT16_C(17587), UINT16_C(13134), UINT16_C(30206) },
      },
    },
    { { UINT16_C(45379), UINT16_C(52400), UINT16_C(11092), UINT16_C(48595) },
      { UINT16_C(30198), UINT16_C(13878), UINT16_C(42203), UINT16_C(65313) },
      {
          { UINT16_C(45379), UINT16_C(30198), UINT16_C(11092), UINT16_C(42203) },
          { UINT16_C(52400), UINT16_C(13878), UINT16_C(48595), UINT16_C(65313) },
      },
    },
    { { UINT16_C(53397), UINT16_C(63333), UINT16_C(45883), UINT16_C(55083) },
      { UINT16_C(56929), UINT16_C(55067), UINT16_C( 6756), UINT16_C(43085) },
      {
          { UINT16_C(53397), UINT16_C(56929), UINT16_C(45883), UINT16_C( 6756) },
          { UINT16_C(63333), UINT16_C(55067), UINT16_C(55083), UINT16_C(43085) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4x2_t r = simde_vtrn_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r.val[0], simde_vld1_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], simde_vld1_u16(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrn_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2][2];
  } test_vec[] = {
    { { UINT32_C(4008918152), UINT32_C(1302258451) },
      { UINT32_C( 362140121), UINT32_C(3609334470) },
      {
          { UINT32_C(4008918152), UINT32_C( 362140121) },
          { UINT32_C(1302258451), UINT32_C(3609334470) },
      },
    },
    { { UINT32_C(2784007120), UINT32_C( 955628426) },
      { UINT32_C(1766220593), UINT32_C(4102521708) },
      {
          { UINT32_C(2784007120), UINT32_C(1766220593) },
          { UINT32_C( 955628426), UINT32_C(4102521708) },
      },
    },
    { { UINT32_C(3538057919), UINT32_C( 924877150) },
      { UINT32_C( 407745874), UINT32_C(2565828552) },
      {
          { UINT32_C(3538057919), UINT32_C( 407745874) },
          { UINT32_C( 924877150), UINT32_C(2565828552) },
      },
    },
    { { UINT32_C(2369707779), UINT32_C(3435541403) },
      { UINT32_C(  37031062), UINT32_C(1324792975) },
      {
          { UINT32_C(2369707779), UINT32_C(  37031062) },
          { UINT32_C(3435541403), UINT32_C(1324792975) },
      },
    },
    { { UINT32_C(2502023479), UINT32_C(2899067226) },
      { UINT32_C(3200588278), UINT32_C(2354558089) },
      {
          { UINT32_C(2502023479), UINT32_C(3200588278) },
          { UINT32_C(2899067226), UINT32_C(2354558089) },
      },
    },
    { { UINT32_C( 790205844), UINT32_C(1610342344) },
      { UINT32_C(2069967084), UINT32_C( 600463596) },
      {
          { UINT32_C( 790205844), UINT32_C(2069967084) },
          { UINT32_C(1610342344), UINT32_C( 600463596) },
      },
    },
    { { UINT32_C(2344151857), UINT32_C( 574063916) },
      { UINT32_C( 669121694), UINT32_C(1169373361) },
      {
          { UINT32_C(2344151857), UINT32_C( 669121694) },
          { UINT32_C( 574063916), UINT32_C(1169373361) },
      },
    },
    { { UINT32_C(2507460045), UINT32_C(2566156204) },
      { UINT32_C(2333365919), UINT32_C(3752844974) },
      {
          { UINT32_C(2507460045), UINT32_C(2333365919) },
          { UINT32_C(2566156204), UINT32_C(3752844974) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2x2_t r = simde_vtrn_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r.val[0], simde_vld1_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], simde_vld1_u32(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrnq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[2][4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -21.16), SIMDE_FLOAT32_C(  -415.28), SIMDE_FLOAT32_C(   122.64), SIMDE_FLOAT32_C(  -871.38) },
      { SIMDE_FLOAT32_C(   823.55), SIMDE_FLOAT32_C(   479.12), SIMDE_FLOAT32_C(  -299.37), SIMDE_FLOAT32_C(  -925.94) },
      {
          { SIMDE_FLOAT32_C(   -21.16), SIMDE_FLOAT32_C(   823.55), SIMDE_FLOAT32_C(   122.64), SIMDE_FLOAT32_C(  -299.37) },
          { SIMDE_FLOAT32_C(  -415.28), SIMDE_FLOAT32_C(   479.12), SIMDE_FLOAT32_C(  -871.38), SIMDE_FLOAT32_C(  -925.94) },
      },
    },
    { { SIMDE_FLOAT32_C(  -127.06), SIMDE_FLOAT32_C(  -474.56), SIMDE_FLOAT32_C(  -700.09), SIMDE_FLOAT32_C(   980.65) },
      { SIMDE_FLOAT32_C(  -759.85), SIMDE_FLOAT32_C(   613.71), SIMDE_FLOAT32_C(   336.49), SIMDE_FLOAT32_C(   564.00) },
      {
          { SIMDE_FLOAT32_C(  -127.06), SIMDE_FLOAT32_C(  -759.85), SIMDE_FLOAT32_C(  -700.09), SIMDE_FLOAT32_C(   336.49) },
          { SIMDE_FLOAT32_C(  -474.56), SIMDE_FLOAT32_C(   613.71), SIMDE_FLOAT32_C(   980.65), SIMDE_FLOAT32_C(   564.00) },
      },
    },
    { { SIMDE_FLOAT32_C(  -466.35), SIMDE_FLOAT32_C(   378.63), SIMDE_FLOAT32_C(  -371.33), SIMDE_FLOAT32_C(   706.88) },
      { SIMDE_FLOAT32_C(   -64.44), SIMDE_FLOAT32_C(   420.87), SIMDE_FLOAT32_C(  -117.58), SIMDE_FLOAT32_C(   403.73) },
      {
          { SIMDE_FLOAT32_C(  -466.35), SIMDE_FLOAT32_C(   -64.44), SIMDE_FLOAT32_C(  -371.33), SIMDE_FLOAT32_C(  -117.58) },
          { SIMDE_FLOAT32_C(   378.63), SIMDE_FLOAT32_C(   420.87), SIMDE_FLOAT32_C(   706.88), SIMDE_FLOAT32_C(   403.73) },
      },
    },
    { { SIMDE_FLOAT32_C(   250.86), SIMDE_FLOAT32_C(   812.70), SIMDE_FLOAT32_C(   383.33), SIMDE_FLOAT32_C(    70.53) },
      { SIMDE_FLOAT32_C(  -526.93), SIMDE_FLOAT32_C(  -755.27), SIMDE_FLOAT32_C(  -138.40), SIMDE_FLOAT32_C(   451.91) },
      {
          { SIMDE_FLOAT32_C(   250.86), SIMDE_FLOAT32_C(  -526.93), SIMDE_FLOAT32_C(   383.33), SIMDE_FLOAT32_C(  -138.40) },
          { SIMDE_FLOAT32_C(   812.70), SIMDE_FLOAT32_C(  -755.27), SIMDE_FLOAT32_C(    70.53), SIMDE_FLOAT32_C(   451.91) },
      },
    },
    { { SIMDE_FLOAT32_C(  -170.55), SIMDE_FLOAT32_C(   984.25), SIMDE_FLOAT32_C(   580.53), SIMDE_FLOAT32_C(  -347.00) },
      { SIMDE_FLOAT32_C(   463.36), SIMDE_FLOAT32_C(  -718.84), SIMDE_FLOAT32_C(  -272.94), SIMDE_FLOAT32_C(  -663.70) },
      {
          { SIMDE_FLOAT32_C(  -170.55), SIMDE_FLOAT32_C(   463.36), SIMDE_FLOAT32_C(   580.53), SIMDE_FLOAT32_C(  -272.94) },
          { SIMDE_FLOAT32_C(   984.25), SIMDE_FLOAT32_C(  -718.84), SIMDE_FLOAT32_C(  -347.00), SIMDE_FLOAT32_C(  -663.70) },
      },
    },
    { { SIMDE_FLOAT32_C(  -193.40), SIMDE_FLOAT32_C(    26.97), SIMDE_FLOAT32_C(  -683.05), SIMDE_FLOAT32_C(    46.75) },
      { SIMDE_FLOAT32_C(  -359.31), SIMDE_FLOAT32_C(   653.44), SIMDE_FLOAT32_C(  -389.25), SIMDE_FLOAT32_C(   174.33) },
      {
          { SIMDE_FLOAT32_C(  -193.40), SIMDE_FLOAT32_C(  -359.31), SIMDE_FLOAT32_C(  -683.05), SIMDE_FLOAT32_C(  -389.25) },
          { SIMDE_FLOAT32_C(    26.97), SIMDE_FLOAT32_C(   653.44), SIMDE_FLOAT32_C(    46.75), SIMDE_FLOAT32_C(   174.33) },
      },
    },
    { { SIMDE_FLOAT32_C(    32.08), SIMDE_FLOAT32_C(   239.42), SIMDE_FLOAT32_C(  -118.78), SIMDE_FLOAT32_C(   967.64) },
      { SIMDE_FLOAT32_C(  -339.71), SIMDE_FLOAT32_C(   763.63), SIMDE_FLOAT32_C(   371.37), SIMDE_FLOAT32_C(   911.15) },
      {
          { SIMDE_FLOAT32_C(    32.08), SIMDE_FLOAT32_C(  -339.71), SIMDE_FLOAT32_C(  -118.78), SIMDE_FLOAT32_C(   371.37) },
          { SIMDE_FLOAT32_C(   239.42), SIMDE_FLOAT32_C(   763.63), SIMDE_FLOAT32_C(   967.64), SIMDE_FLOAT32_C(   911.15) },
      },
    },
    { { SIMDE_FLOAT32_C(   576.34), SIMDE_FLOAT32_C(  -245.30), SIMDE_FLOAT32_C(   -18.32), SIMDE_FLOAT32_C(  -950.59) },
      { SIMDE_FLOAT32_C(    -0.57), SIMDE_FLOAT32_C(   843.29), SIMDE_FLOAT32_C(   501.32), SIMDE_FLOAT32_C(   828.88) },
      {
          { SIMDE_FLOAT32_C(   576.34), SIMDE_FLOAT32_C(    -0.57), SIMDE_FLOAT32_C(   -18.32), SIMDE_FLOAT32_C(   501.32) },
          { SIMDE_FLOAT32_C(  -245.30), SIMDE_FLOAT32_C(   843.29), SIMDE_FLOAT32_C(  -950.59), SIMDE_FLOAT32_C(   828.88) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4x2_t r = simde_vtrnq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r.val[0], simde_vld1q_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], simde_vld1q_f32(test_vec[i].r[1]), 1);
  }

  return 0;
}

static int
test_simde_vtrnq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[2][16];
  } test_vec[] = {
    { { -INT8_C(  33), -INT8_C(   2),  INT8_C(  49),  INT8_C(  24),  INT8_C(  54),  INT8_C(  26),  INT8_C(  79), -INT8_C(  31),
         INT8_C(  21), -INT8_C( 121),  INT8_C(  14), -INT8_C(  47),  INT8_C( 102), -INT8_C(  38),  INT8_C(  73),  INT8_C(  24) },
      { -INT8_C(   8),  INT8_C(   7),  INT8_C(  22), -INT8_C(  62),  INT8_C(  52), -INT8_C(  22), -INT8_C( 122),  INT8_C( 110),
         INT8_C(  20), -INT8_C(  71),  INT8_C(  94), -INT8_C(   2), -INT8_C(  12), -INT8_C(  71), -INT8_C(  73), -INT8_C(  44) },
      {
          { -INT8_C(  33), -INT8_C(   8),  INT8_C(  49),  INT8_C(  22),  INT8_C(  54),  INT8_C(  52),  INT8_C(  79), -INT8_C( 122),
             INT8_C(  21),  INT8_C(  20),  INT8_C(  14),  INT8_C(  94),  INT8_C( 102), -INT8_C(  12),  INT8_C(  73), -INT8_C(  73) },
          { -INT8_C(   2),  INT8_C(   7),  INT8_C(  24), -INT8_C(  62),  INT8_C(  26), -INT8_C(  22), -INT8_C(  31),  INT8_C( 110),
            -INT8_C( 121), -INT8_C(  71), -INT8_C(  47), -INT8_C(   2), -INT8_C(  38), -INT8_C(  71),  INT8_C(  24), -INT8_C(  44) },
      },
    },
    { { -INT8_C(  73), -INT8_C(  24), -INT8_C(  20), -INT8_C(  19),  INT8_C(   2),  INT8_C(  59), -INT8_C(  49),  INT8_C(  23),
        -INT8_C(  62), -INT8_C(  35), -INT8_C(  23),  INT8_C(  40), -INT8_C(  73),  INT8_C(  50),  INT8_C(  64), -INT8_C(  81) },
      {  INT8_C(  58),  INT8_C(  86),  INT8_C( 114),  INT8_C( 110),  INT8_C(  64), -INT8_C(   8), -INT8_C(  36),  INT8_C(  85),
        -INT8_C(  79),  INT8_C(  58),  INT8_C(  83), -INT8_C(  90), -INT8_C(  13),  INT8_C(  10),  INT8_C( 122), -INT8_C(  85) },
      {
          { -INT8_C(  73),  INT8_C(  58), -INT8_C(  20),  INT8_C( 114),  INT8_C(   2),  INT8_C(  64), -INT8_C(  49), -INT8_C(  36),
            -INT8_C(  62), -INT8_C(  79), -INT8_C(  23),  INT8_C(  83), -INT8_C(  73), -INT8_C(  13),  INT8_C(  64),  INT8_C( 122) },
          { -INT8_C(  24),  INT8_C(  86), -INT8_C(  19),  INT8_C( 110),  INT8_C(  59), -INT8_C(   8),  INT8_C(  23),  INT8_C(  85),
            -INT8_C(  35),  INT8_C(  58),  INT8_C(  40), -INT8_C(  90),  INT8_C(  50),  INT8_C(  10), -INT8_C(  81), -INT8_C(  85) },
      },
    },
    { { -INT8_C(  14),  INT8_C( 102), -INT8_C( 104), -INT8_C(  11), -INT8_C(  95),  INT8_C( 103),  INT8_C(  12),  INT8_C(  99),
         INT8_C(  68), -INT8_C(  11), -INT8_C( 117), -INT8_C(   5),  INT8_C(  40), -INT8_C(  52), -INT8_C(  85),  INT8_C(  98) },
      {  INT8_C(  34),  INT8_C(  29), -INT8_C(  48),  INT8_C(  99),  INT8_C(  21), -INT8_C(  84), -INT8_C(  72), -INT8_C(  58),
        -INT8_C(  25),  INT8_C(  11),  INT8_C( 108), -INT8_C(  38),  INT8_C(  22), -INT8_C(  26), -INT8_C( 123),  INT8_C(   8) },
      {
          { -INT8_C(  14),  INT8_C(  34), -INT8_C( 104), -INT8_C(  48), -INT8_C(  95),  INT8_C(  21),  INT8_C(  12), -INT8_C(  72),
             INT8_C(  68), -INT8_C(  25), -INT8_C( 117),  INT8_C( 108),  INT8_C(  40),  INT8_C(  22), -INT8_C(  85), -INT8_C( 123) },
          {  INT8_C( 102),  INT8_C(  29), -INT8_C(  11),  INT8_C(  99),  INT8_C( 103), -INT8_C(  84),  INT8_C(  99), -INT8_C(  58),
            -INT8_C(  11),  INT8_C(  11), -INT8_C(   5), -INT8_C(  38), -INT8_C(  52), -INT8_C(  26),  INT8_C(  98),  INT8_C(   8) },
      },
    },
    { {  INT8_C(  76),  INT8_C(  30), -INT8_C(   3), -INT8_C(  19), -INT8_C( 123),  INT8_C(  10),  INT8_C(  80), -INT8_C(  54),
        -INT8_C(   1), -INT8_C(  36), -INT8_C(  59),  INT8_C(  39), -INT8_C(  88),  INT8_C( 112), -INT8_C( 119), -INT8_C(  54) },
      { -INT8_C( 115),  INT8_C(  89),  INT8_C(  45), -INT8_C(  94),  INT8_C(   6), -INT8_C(  27),  INT8_C( 105), -INT8_C(  19),
        -INT8_C(  15), -INT8_C(  43), -INT8_C(  57),  INT8_C(   7), -INT8_C(  68),  INT8_C(  77),  INT8_C(  15),  INT8_C(   8) },
      {
          {  INT8_C(  76), -INT8_C( 115), -INT8_C(   3),  INT8_C(  45), -INT8_C( 123),  INT8_C(   6),  INT8_C(  80),  INT8_C( 105),
            -INT8_C(   1), -INT8_C(  15), -INT8_C(  59), -INT8_C(  57), -INT8_C(  88), -INT8_C(  68), -INT8_C( 119),  INT8_C(  15) },
          {  INT8_C(  30),  INT8_C(  89), -INT8_C(  19), -INT8_C(  94),  INT8_C(  10), -INT8_C(  27), -INT8_C(  54), -INT8_C(  19),
            -INT8_C(  36), -INT8_C(  43),  INT8_C(  39),  INT8_C(   7),  INT8_C( 112),  INT8_C(  77), -INT8_C(  54),  INT8_C(   8) },
      },
    },
    { {  INT8_C( 107),  INT8_C(  13), -INT8_C(  10), -INT8_C(  16),  INT8_C(  23),  INT8_C(  70), -INT8_C(  70),  INT8_C(  22),
         INT8_C(  34),      INT8_MIN,  INT8_C(  62), -INT8_C(  54), -INT8_C(  16), -INT8_C(  57), -INT8_C( 107),  INT8_C( 126) },
      {  INT8_C(  33), -INT8_C(  62),  INT8_C(  32),  INT8_C(  39), -INT8_C(  88), -INT8_C( 119),  INT8_C(  20), -INT8_C( 103),
         INT8_C(  95), -INT8_C(  37), -INT8_C(  96),  INT8_C(  27),  INT8_C(  40), -INT8_C(  81),  INT8_C(  35), -INT8_C( 109) },
      {
          {  INT8_C( 107),  INT8_C(  33), -INT8_C(  10),  INT8_C(  32),  INT8_C(  23), -INT8_C(  88), -INT8_C(  70),  INT8_C(  20),
             INT8_C(  34),  INT8_C(  95),  INT8_C(  62), -INT8_C(  96), -INT8_C(  16),  INT8_C(  40), -INT8_C( 107),  INT8_C(  35) },
          {  INT8_C(  13), -INT8_C(  62), -INT8_C(  16),  INT8_C(  39),  INT8_C(  70), -INT8_C( 119),  INT8_C(  22), -INT8_C( 103),
                 INT8_MIN, -INT8_C(  37), -INT8_C(  54),  INT8_C(  27), -INT8_C(  57), -INT8_C(  81),  INT8_C( 126), -INT8_C( 109) },
      },
    },
    { { -INT8_C(  68),  INT8_C(  25), -INT8_C( 124), -INT8_C(  45),  INT8_C(  96),  INT8_C(  62), -INT8_C(  22), -INT8_C( 126),
        -INT8_C(  66),  INT8_C(  40),  INT8_C(  77), -INT8_C(  81), -INT8_C(  17), -INT8_C(  30),  INT8_C(  45),  INT8_C(  16) },
      { -INT8_C(  92),  INT8_C(  77),  INT8_C(  55),  INT8_C(  76), -INT8_C(  41),  INT8_C(  75), -INT8_C(  27),  INT8_C(  54),
         INT8_C(  39), -INT8_C( 123),  INT8_C(  81),  INT8_C(  79),  INT8_C(  53),  INT8_C( 116), -INT8_C(  29), -INT8_C(  15) },
      {
          { -INT8_C(  68), -INT8_C(  92), -INT8_C( 124),  INT8_C(  55),  INT8_C(  96), -INT8_C(  41), -INT8_C(  22), -INT8_C(  27),
            -INT8_C(  66),  INT8_C(  39),  INT8_C(  77),  INT8_C(  81), -INT8_C(  17),  INT8_C(  53),  INT8_C(  45), -INT8_C(  29) },
          {  INT8_C(  25),  INT8_C(  77), -INT8_C(  45),  INT8_C(  76),  INT8_C(  62),  INT8_C(  75), -INT8_C( 126),  INT8_C(  54),
             INT8_C(  40), -INT8_C( 123), -INT8_C(  81),  INT8_C(  79), -INT8_C(  30),  INT8_C( 116),  INT8_C(  16), -INT8_C(  15) },
      },
    },
    { { -INT8_C( 114),  INT8_C( 103), -INT8_C(  59), -INT8_C(  18), -INT8_C(  91), -INT8_C(  81),  INT8_C( 112),  INT8_C( 100),
        -INT8_C(  41), -INT8_C(  67),  INT8_C(  19), -INT8_C(  58), -INT8_C(  97),  INT8_C(  64), -INT8_C(  41),  INT8_C(  68) },
      { -INT8_C( 115),  INT8_C(  14), -INT8_C( 112),  INT8_C( 100),  INT8_C(  90),  INT8_C( 118), -INT8_C( 102), -INT8_C( 127),
        -INT8_C(   5), -INT8_C(  21), -INT8_C(  48),  INT8_C(  48),  INT8_C(  96), -INT8_C(  77),  INT8_C(  34), -INT8_C(  18) },
      {
          { -INT8_C( 114), -INT8_C( 115), -INT8_C(  59), -INT8_C( 112), -INT8_C(  91),  INT8_C(  90),  INT8_C( 112), -INT8_C( 102),
            -INT8_C(  41), -INT8_C(   5),  INT8_C(  19), -INT8_C(  48), -INT8_C(  97),  INT8_C(  96), -INT8_C(  41),  INT8_C(  34) },
          {  INT8_C( 103),  INT8_C(  14), -INT8_C(  18),  INT8_C( 100), -INT8_C(  81),  INT8_C( 118),  INT8_C( 100), -INT8_C( 127),
            -INT8_C(  67), -INT8_C(  21), -INT8_C(  58),  INT8_C(  48),  INT8_C(  64), -INT8_C(  77),  INT8_C(  68), -INT8_C(  18) },
      },
    },
    { {  INT8_C(  26), -INT8_C(  25), -INT8_C(  36), -INT8_C(  64), -INT8_C( 106),  INT8_C(  76),  INT8_C(  36),  INT8_C( 109),
         INT8_C(  10),  INT8_C(  55),  INT8_C(  51), -INT8_C(  87),  INT8_C( 119),  INT8_C(  10), -INT8_C(  19),  INT8_C(   4) },
      {  INT8_C(  25),  INT8_C( 126),  INT8_C( 105),  INT8_C( 115), -INT8_C(  12),  INT8_C(   3), -INT8_C(  12), -INT8_C(  17),
        -INT8_C(  17), -INT8_C(  60),  INT8_C(  32),  INT8_C(  79),  INT8_C( 120),  INT8_C(  66),  INT8_C(  61), -INT8_C( 110) },
      {
          {  INT8_C(  26),  INT8_C(  25), -INT8_C(  36),  INT8_C( 105), -INT8_C( 106), -INT8_C(  12),  INT8_C(  36), -INT8_C(  12),
             INT8_C(  10), -INT8_C(  17),  INT8_C(  51),  INT8_C(  32),  INT8_C( 119),  INT8_C( 120), -INT8_C(  19),  INT8_C(  61) },
          { -INT8_C(  25),  INT8_C( 126), -INT8_C(  64),  INT8_C( 115),  INT8_C(  76),  INT8_C(   3),  INT8_C( 109), -INT8_C(  17),
             INT8_C(  55), -INT8_C(  60), -INT8_C(  87),  INT8_C(  79),  INT8_C(  10),  INT8_C(  66),  INT8_C(   4), -INT8_C( 110) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16x2_t r = simde_vtrnq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], simde_vld1q_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], simde_vld1q_s8(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrnq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[2][8];
  } test_vec[] = {
    { {  INT16_C( 10915), -INT16_C( 16438),  INT16_C(  7957), -INT16_C( 18291), -INT16_C( 19156),  INT16_C( 21219), -INT16_C( 21359),  INT16_C( 13451) },
      { -INT16_C( 24388),  INT16_C( 21235),  INT16_C( 19711), -INT16_C( 13138),  INT16_C( 19613),  INT16_C(  3470),  INT16_C(  9286), -INT16_C(  5705) },
      {
          {  INT16_C( 10915), -INT16_C( 24388),  INT16_C(  7957),  INT16_C( 19711), -INT16_C( 19156),  INT16_C( 19613), -INT16_C( 21359),  INT16_C(  9286) },
          { -INT16_C( 16438),  INT16_C( 21235), -INT16_C( 18291), -INT16_C( 13138),  INT16_C( 21219),  INT16_C(  3470),  INT16_C( 13451), -INT16_C(  5705) },
      },
    },
    { { -INT16_C( 32434),  INT16_C( 25769),  INT16_C( 13984), -INT16_C( 13284), -INT16_C(    20),  INT16_C( 32031), -INT16_C( 21844),  INT16_C( 26801) },
      { -INT16_C( 23222),  INT16_C( 19130),  INT16_C( 27121), -INT16_C( 29162), -INT16_C( 23115), -INT16_C(  1125),  INT16_C( 21193),  INT16_C(  6117) },
      {
          { -INT16_C( 32434), -INT16_C( 23222),  INT16_C( 13984),  INT16_C( 27121), -INT16_C(    20), -INT16_C( 23115), -INT16_C( 21844),  INT16_C( 21193) },
          {  INT16_C( 25769),  INT16_C( 19130), -INT16_C( 13284), -INT16_C( 29162),  INT16_C( 32031), -INT16_C(  1125),  INT16_C( 26801),  INT16_C(  6117) },
      },
    },
    { { -INT16_C( 28972),  INT16_C( 29819), -INT16_C( 26428), -INT16_C( 20415),  INT16_C( 24727),  INT16_C( 17198), -INT16_C(  8438),  INT16_C( 21676) },
      {  INT16_C( 26244),  INT16_C( 30110), -INT16_C( 18993), -INT16_C( 31741), -INT16_C( 24998),  INT16_C(  9088),  INT16_C( 26097), -INT16_C( 15046) },
      {
          { -INT16_C( 28972),  INT16_C( 26244), -INT16_C( 26428), -INT16_C( 18993),  INT16_C( 24727), -INT16_C( 24998), -INT16_C(  8438),  INT16_C( 26097) },
          {  INT16_C( 29819),  INT16_C( 30110), -INT16_C( 20415), -INT16_C( 31741),  INT16_C( 17198),  INT16_C(  9088),  INT16_C( 21676), -INT16_C( 15046) },
      },
    },
    { { -INT16_C( 18701), -INT16_C( 18631),  INT16_C( 31310), -INT16_C(  6808), -INT16_C( 26918), -INT16_C(  7127), -INT16_C( 10891), -INT16_C(  1479) },
      { -INT16_C( 10437),  INT16_C(  2927),  INT16_C( 29580), -INT16_C(  6513),  INT16_C(  3857),  INT16_C(   521),  INT16_C( 17524),  INT16_C( 26567) },
      {
          { -INT16_C( 18701), -INT16_C( 10437),  INT16_C( 31310),  INT16_C( 29580), -INT16_C( 26918),  INT16_C(  3857), -INT16_C( 10891),  INT16_C( 17524) },
          { -INT16_C( 18631),  INT16_C(  2927), -INT16_C(  6808), -INT16_C(  6513), -INT16_C(  7127),  INT16_C(   521), -INT16_C(  1479),  INT16_C( 26567) },
      },
    },
    { {  INT16_C(   506),  INT16_C( 18463), -INT16_C( 30853),  INT16_C( 22061),  INT16_C( 22045), -INT16_C( 28102),  INT16_C( 29483),  INT16_C( 26508) },
      { -INT16_C(   949), -INT16_C( 10382),  INT16_C(   367), -INT16_C( 32578), -INT16_C( 14575), -INT16_C( 31357),  INT16_C( 18955),  INT16_C(  1517) },
      {
          {  INT16_C(   506), -INT16_C(   949), -INT16_C( 30853),  INT16_C(   367),  INT16_C( 22045), -INT16_C( 14575),  INT16_C( 29483),  INT16_C( 18955) },
          {  INT16_C( 18463), -INT16_C( 10382),  INT16_C( 22061), -INT16_C( 32578), -INT16_C( 28102), -INT16_C( 31357),  INT16_C( 26508),  INT16_C(  1517) },
      },
    },
    { {  INT16_C(  3147), -INT16_C( 14515),  INT16_C( 31635), -INT16_C( 20451),  INT16_C( 22481), -INT16_C(   702), -INT16_C( 12341),  INT16_C(  5732) },
      { -INT16_C( 10549),  INT16_C( 15085), -INT16_C( 21545), -INT16_C(  5958),  INT16_C( 15731),  INT16_C( 32366),  INT16_C( 23432), -INT16_C( 11388) },
      {
          {  INT16_C(  3147), -INT16_C( 10549),  INT16_C( 31635), -INT16_C( 21545),  INT16_C( 22481),  INT16_C( 15731), -INT16_C( 12341),  INT16_C( 23432) },
          { -INT16_C( 14515),  INT16_C( 15085), -INT16_C( 20451), -INT16_C(  5958), -INT16_C(   702),  INT16_C( 32366),  INT16_C(  5732), -INT16_C( 11388) },
      },
    },
    { { -INT16_C( 11929), -INT16_C(  1382), -INT16_C( 18612),  INT16_C(  7850), -INT16_C(  5105), -INT16_C(  9701),  INT16_C( 32699), -INT16_C( 30992) },
      { -INT16_C(  8875),  INT16_C( 11456),  INT16_C( 31625), -INT16_C(  1003), -INT16_C( 31816),  INT16_C( 16506), -INT16_C(   290),  INT16_C( 17684) },
      {
          { -INT16_C( 11929), -INT16_C(  8875), -INT16_C( 18612),  INT16_C( 31625), -INT16_C(  5105), -INT16_C( 31816),  INT16_C( 32699), -INT16_C(   290) },
          { -INT16_C(  1382),  INT16_C( 11456),  INT16_C(  7850), -INT16_C(  1003), -INT16_C(  9701),  INT16_C( 16506), -INT16_C( 30992),  INT16_C( 17684) },
      },
    },
    { { -INT16_C( 20784),  INT16_C(  7231), -INT16_C(  5786),  INT16_C( 30010),  INT16_C( 21973), -INT16_C( 28337),  INT16_C( 16340),  INT16_C( 10519) },
      { -INT16_C( 10212), -INT16_C( 23210),  INT16_C( 27475),  INT16_C(  2977),  INT16_C(  7406), -INT16_C( 13236),  INT16_C( 24602), -INT16_C(  5615) },
      {
          { -INT16_C( 20784), -INT16_C( 10212), -INT16_C(  5786),  INT16_C( 27475),  INT16_C( 21973),  INT16_C(  7406),  INT16_C( 16340),  INT16_C( 24602) },
          {  INT16_C(  7231), -INT16_C( 23210),  INT16_C( 30010),  INT16_C(  2977), -INT16_C( 28337), -INT16_C( 13236),  INT16_C( 10519), -INT16_C(  5615) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8x2_t r = simde_vtrnq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], simde_vld1q_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], simde_vld1q_s16(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrnq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[2][4];
  } test_vec[] = {
    { {  INT32_C(  1703801270), -INT32_C(   232086468),  INT32_C(     5800579), -INT32_C(  1062703425) },
      { -INT32_C(  1987166982),  INT32_C(  1610152052),  INT32_C(   676881874),  INT32_C(  1462420385) },
      {
          {  INT32_C(  1703801270), -INT32_C(  1987166982),  INT32_C(     5800579),  INT32_C(   676881874) },
          { -INT32_C(   232086468),  INT32_C(  1610152052), -INT32_C(  1062703425),  INT32_C(  1462420385) },
      },
    },
    { { -INT32_C(   239290187), -INT32_C(   538712484),  INT32_C(   685784169), -INT32_C(  1528198998) },
      {  INT32_C(   942503876),  INT32_C(  1100490351),  INT32_C(   745205899),  INT32_C(  1753519283) },
      {
          { -INT32_C(   239290187),  INT32_C(   942503876),  INT32_C(   685784169),  INT32_C(   745205899) },
          { -INT32_C(   538712484),  INT32_C(  1100490351), -INT32_C(  1528198998),  INT32_C(  1753519283) },
      },
    },
    { { -INT32_C(  1453768628), -INT32_C(  1870119641),  INT32_C(   599287929), -INT32_C(  1261985296) },
      { -INT32_C(  1997671400), -INT32_C(  1513519846),  INT32_C(   684864373),  INT32_C(   345069256) },
      {
          { -INT32_C(  1453768628), -INT32_C(  1997671400),  INT32_C(   599287929),  INT32_C(   684864373) },
          { -INT32_C(  1870119641), -INT32_C(  1513519846), -INT32_C(  1261985296),  INT32_C(   345069256) },
      },
    },
    { { -INT32_C(  1111627114), -INT32_C(  1605548505), -INT32_C(  1614608722), -INT32_C(  1068266841) },
      { -INT32_C(  1723318145),  INT32_C(   977211845),  INT32_C(   224596293), -INT32_C(    48106393) },
      {
          { -INT32_C(  1111627114), -INT32_C(  1723318145), -INT32_C(  1614608722),  INT32_C(   224596293) },
          { -INT32_C(  1605548505),  INT32_C(   977211845), -INT32_C(  1068266841), -INT32_C(    48106393) },
      },
    },
    { {  INT32_C(   112975838), -INT32_C(   744093659), -INT32_C(  1234015730),  INT32_C(  1937164020) },
      { -INT32_C(   871514618),  INT32_C(   335957199), -INT32_C(  1004443299),  INT32_C(  1019298653) },
      {
          {  INT32_C(   112975838), -INT32_C(   871514618), -INT32_C(  1234015730), -INT32_C(  1004443299) },
          { -INT32_C(   744093659),  INT32_C(   335957199),  INT32_C(  1937164020),  INT32_C(  1019298653) },
      },
    },
    { {  INT32_C(  1195539490), -INT32_C(  1826953083),  INT32_C(  1196002642),  INT32_C(  1505410899) },
      {  INT32_C(  1294321533),  INT32_C(  1885416467), -INT32_C(   214662251), -INT32_C(   399509818) },
      {
          {  INT32_C(  1195539490),  INT32_C(  1294321533),  INT32_C(  1196002642), -INT32_C(   214662251) },
          { -INT32_C(  1826953083),  INT32_C(  1885416467),  INT32_C(  1505410899), -INT32_C(   399509818) },
      },
    },
    { { -INT32_C(   147885710), -INT32_C(  1400157863),  INT32_C(   703845590),  INT32_C(   293842324) },
      { -INT32_C(  2007062411),  INT32_C(  1794752724),  INT32_C(   157101379), -INT32_C(  1762554845) },
      {
          { -INT32_C(   147885710), -INT32_C(  2007062411),  INT32_C(   703845590),  INT32_C(   157101379) },
          { -INT32_C(  1400157863),  INT32_C(  1794752724),  INT32_C(   293842324), -INT32_C(  1762554845) },
      },
    },
    { {  INT32_C(  1452089597),  INT32_C(  1073879145), -INT32_C(  2123762195),  INT32_C(   412282019) },
      {  INT32_C(  1772155285), -INT32_C(   187459151), -INT32_C(   352505657), -INT32_C(  1182732612) },
      {
          {  INT32_C(  1452089597),  INT32_C(  1772155285), -INT32_C(  2123762195), -INT32_C(   352505657) },
          {  INT32_C(  1073879145), -INT32_C(   187459151),  INT32_C(   412282019), -INT32_C(  1182732612) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4x2_t r = simde_vtrnq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r.val[0], simde_vld1q_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], simde_vld1q_s32(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrnq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[2][16];
  } test_vec[] = {
    { { UINT8_C(125), UINT8_C( 52), UINT8_C(219), UINT8_C( 49), UINT8_C(184), UINT8_C( 70), UINT8_C( 81), UINT8_C( 21),
        UINT8_C(251), UINT8_C(161), UINT8_C( 96), UINT8_C( 40), UINT8_C(  3), UINT8_C(143), UINT8_C(153), UINT8_C(129) },
      { UINT8_C(  6), UINT8_C(209), UINT8_C(203), UINT8_C( 43), UINT8_C(151), UINT8_C( 96), UINT8_C(213), UINT8_C(182),
        UINT8_C( 61), UINT8_C(132), UINT8_C( 40), UINT8_C( 31), UINT8_C(188), UINT8_C(204), UINT8_C(218), UINT8_C( 57) },
      {
          { UINT8_C(125), UINT8_C(  6), UINT8_C(219), UINT8_C(203), UINT8_C(184), UINT8_C(151), UINT8_C( 81), UINT8_C(213),
            UINT8_C(251), UINT8_C( 61), UINT8_C( 96), UINT8_C( 40), UINT8_C(  3), UINT8_C(188), UINT8_C(153), UINT8_C(218) },
          { UINT8_C( 52), UINT8_C(209), UINT8_C( 49), UINT8_C( 43), UINT8_C( 70), UINT8_C( 96), UINT8_C( 21), UINT8_C(182),
            UINT8_C(161), UINT8_C(132), UINT8_C( 40), UINT8_C( 31), UINT8_C(143), UINT8_C(204), UINT8_C(129), UINT8_C( 57) },
      },
    },
    { { UINT8_C(  0), UINT8_C(182), UINT8_C(106), UINT8_C(185), UINT8_C(252), UINT8_C(188), UINT8_C(206), UINT8_C(247),
        UINT8_C( 93), UINT8_C( 46), UINT8_C( 32), UINT8_C( 97), UINT8_C(189), UINT8_C(185), UINT8_C(226), UINT8_C(196) },
      { UINT8_C(138), UINT8_C(173), UINT8_C(239), UINT8_C( 33), UINT8_C( 14), UINT8_C(196), UINT8_C(216), UINT8_C( 75),
        UINT8_C( 72), UINT8_C(  0), UINT8_C(107), UINT8_C(  5), UINT8_C(204), UINT8_C( 69), UINT8_C( 62), UINT8_C(204) },
      {
          { UINT8_C(  0), UINT8_C(138), UINT8_C(106), UINT8_C(239), UINT8_C(252), UINT8_C( 14), UINT8_C(206), UINT8_C(216),
            UINT8_C( 93), UINT8_C( 72), UINT8_C( 32), UINT8_C(107), UINT8_C(189), UINT8_C(204), UINT8_C(226), UINT8_C( 62) },
          { UINT8_C(182), UINT8_C(173), UINT8_C(185), UINT8_C( 33), UINT8_C(188), UINT8_C(196), UINT8_C(247), UINT8_C( 75),
            UINT8_C( 46), UINT8_C(  0), UINT8_C( 97), UINT8_C(  5), UINT8_C(185), UINT8_C( 69), UINT8_C(196), UINT8_C(204) },
      },
    },
    { { UINT8_C(251), UINT8_C(169), UINT8_C(133), UINT8_C(248), UINT8_C(101), UINT8_C( 83), UINT8_C(239), UINT8_C(194),
        UINT8_C(130), UINT8_C( 15), UINT8_C( 35), UINT8_C( 63), UINT8_C(200), UINT8_C(  5), UINT8_C(  3), UINT8_C( 82) },
      { UINT8_C(179), UINT8_C(243), UINT8_C(116), UINT8_C(193), UINT8_C(183), UINT8_C( 76), UINT8_C( 12), UINT8_C(  0),
        UINT8_C( 76), UINT8_C(119), UINT8_C(  5), UINT8_C( 24), UINT8_C(189), UINT8_C( 67), UINT8_C(228), UINT8_C(184) },
      {
          { UINT8_C(251), UINT8_C(179), UINT8_C(133), UINT8_C(116), UINT8_C(101), UINT8_C(183), UINT8_C(239), UINT8_C( 12),
            UINT8_C(130), UINT8_C( 76), UINT8_C( 35), UINT8_C(  5), UINT8_C(200), UINT8_C(189), UINT8_C(  3), UINT8_C(228) },
          { UINT8_C(169), UINT8_C(243), UINT8_C(248), UINT8_C(193), UINT8_C( 83), UINT8_C( 76), UINT8_C(194), UINT8_C(  0),
            UINT8_C( 15), UINT8_C(119), UINT8_C( 63), UINT8_C( 24), UINT8_C(  5), UINT8_C( 67), UINT8_C( 82), UINT8_C(184) },
      },
    },
    { { UINT8_C(236), UINT8_C(106), UINT8_C(176), UINT8_C( 81), UINT8_C(189), UINT8_C(160), UINT8_C( 20), UINT8_C( 63),
        UINT8_C(175), UINT8_C( 55), UINT8_C(127), UINT8_C(120), UINT8_C( 61), UINT8_C(130), UINT8_C(202), UINT8_C(240) },
      { UINT8_C(117), UINT8_C( 62), UINT8_C(177), UINT8_C( 45), UINT8_C(138), UINT8_C(189), UINT8_C( 45), UINT8_C(214),
        UINT8_C( 53), UINT8_C( 50), UINT8_C(238), UINT8_C(242), UINT8_C(117), UINT8_C(211), UINT8_C(170), UINT8_C( 98) },
      {
          { UINT8_C(236), UINT8_C(117), UINT8_C(176), UINT8_C(177), UINT8_C(189), UINT8_C(138), UINT8_C( 20), UINT8_C( 45),
            UINT8_C(175), UINT8_C( 53), UINT8_C(127), UINT8_C(238), UINT8_C( 61), UINT8_C(117), UINT8_C(202), UINT8_C(170) },
          { UINT8_C(106), UINT8_C( 62), UINT8_C( 81), UINT8_C( 45), UINT8_C(160), UINT8_C(189), UINT8_C( 63), UINT8_C(214),
            UINT8_C( 55), UINT8_C( 50), UINT8_C(120), UINT8_C(242), UINT8_C(130), UINT8_C(211), UINT8_C(240), UINT8_C( 98) },
      },
    },
    { { UINT8_C( 61), UINT8_C( 91), UINT8_C(179), UINT8_C(250), UINT8_C(251), UINT8_C(199), UINT8_C( 58), UINT8_C(170),
           UINT8_MAX, UINT8_C(185), UINT8_C( 34), UINT8_C( 60), UINT8_C( 59), UINT8_C(237), UINT8_C( 44), UINT8_C(177) },
      { UINT8_C( 43), UINT8_C(221), UINT8_C(222), UINT8_C(182), UINT8_C(154), UINT8_C( 11), UINT8_C(140), UINT8_C(207),
        UINT8_C( 61), UINT8_C(123), UINT8_C(193), UINT8_C(178), UINT8_C( 78), UINT8_C(108), UINT8_C( 20), UINT8_C(139) },
      {
          { UINT8_C( 61), UINT8_C( 43), UINT8_C(179), UINT8_C(222), UINT8_C(251), UINT8_C(154), UINT8_C( 58), UINT8_C(140),
               UINT8_MAX, UINT8_C( 61), UINT8_C( 34), UINT8_C(193), UINT8_C( 59), UINT8_C( 78), UINT8_C( 44), UINT8_C( 20) },
          { UINT8_C( 91), UINT8_C(221), UINT8_C(250), UINT8_C(182), UINT8_C(199), UINT8_C( 11), UINT8_C(170), UINT8_C(207),
            UINT8_C(185), UINT8_C(123), UINT8_C( 60), UINT8_C(178), UINT8_C(237), UINT8_C(108), UINT8_C(177), UINT8_C(139) },
      },
    },
    { { UINT8_C(199), UINT8_C(200), UINT8_C(133), UINT8_C(194), UINT8_C(143), UINT8_C(191), UINT8_C(108), UINT8_C(142),
        UINT8_C(120), UINT8_C(143), UINT8_C(202), UINT8_C(180), UINT8_C(124), UINT8_C(246), UINT8_C(101), UINT8_C(167) },
      { UINT8_C(211), UINT8_C( 67), UINT8_C( 93), UINT8_C(110), UINT8_C( 78), UINT8_C(234), UINT8_C( 61), UINT8_C(139),
        UINT8_C(101),    UINT8_MAX, UINT8_C( 61), UINT8_C(179), UINT8_C(107), UINT8_C( 82), UINT8_C( 62), UINT8_C( 50) },
      {
          { UINT8_C(199), UINT8_C(211), UINT8_C(133), UINT8_C( 93), UINT8_C(143), UINT8_C( 78), UINT8_C(108), UINT8_C( 61),
            UINT8_C(120), UINT8_C(101), UINT8_C(202), UINT8_C( 61), UINT8_C(124), UINT8_C(107), UINT8_C(101), UINT8_C( 62) },
          { UINT8_C(200), UINT8_C( 67), UINT8_C(194), UINT8_C(110), UINT8_C(191), UINT8_C(234), UINT8_C(142), UINT8_C(139),
            UINT8_C(143),    UINT8_MAX, UINT8_C(180), UINT8_C(179), UINT8_C(246), UINT8_C( 82), UINT8_C(167), UINT8_C( 50) },
      },
    },
    { { UINT8_C( 26), UINT8_C(195), UINT8_C(244), UINT8_C(169), UINT8_C(131), UINT8_C( 96), UINT8_C( 56), UINT8_C(251),
        UINT8_C(239), UINT8_C(  2), UINT8_C(175), UINT8_C(107), UINT8_C(249), UINT8_C( 20), UINT8_C( 19), UINT8_C(204) },
      { UINT8_C( 87), UINT8_C(112), UINT8_C( 58), UINT8_C(165), UINT8_C( 90), UINT8_C(120), UINT8_C( 48), UINT8_C(191),
        UINT8_C(119), UINT8_C(110), UINT8_C(114), UINT8_C(226), UINT8_C(192), UINT8_C(176), UINT8_C( 20), UINT8_C(218) },
      {
          { UINT8_C( 26), UINT8_C( 87), UINT8_C(244), UINT8_C( 58), UINT8_C(131), UINT8_C( 90), UINT8_C( 56), UINT8_C( 48),
            UINT8_C(239), UINT8_C(119), UINT8_C(175), UINT8_C(114), UINT8_C(249), UINT8_C(192), UINT8_C( 19), UINT8_C( 20) },
          { UINT8_C(195), UINT8_C(112), UINT8_C(169), UINT8_C(165), UINT8_C( 96), UINT8_C(120), UINT8_C(251), UINT8_C(191),
            UINT8_C(  2), UINT8_C(110), UINT8_C(107), UINT8_C(226), UINT8_C( 20), UINT8_C(176), UINT8_C(204), UINT8_C(218) },
      },
    },
    { { UINT8_C(116), UINT8_C(  8), UINT8_C(131), UINT8_C(247), UINT8_C(104), UINT8_C(187), UINT8_C(242), UINT8_C( 88),
        UINT8_C(190), UINT8_C(162), UINT8_C(195), UINT8_C(183), UINT8_C(182), UINT8_C(214), UINT8_C(131), UINT8_C( 14) },
      { UINT8_C( 71), UINT8_C(190), UINT8_C(179), UINT8_C(161), UINT8_C( 54), UINT8_C(228), UINT8_C( 97), UINT8_C(173),
        UINT8_C( 82), UINT8_C(211), UINT8_C(143), UINT8_C( 18), UINT8_C(132), UINT8_C(163), UINT8_C(236), UINT8_C(248) },
      {
          { UINT8_C(116), UINT8_C( 71), UINT8_C(131), UINT8_C(179), UINT8_C(104), UINT8_C( 54), UINT8_C(242), UINT8_C( 97),
            UINT8_C(190), UINT8_C( 82), UINT8_C(195), UINT8_C(143), UINT8_C(182), UINT8_C(132), UINT8_C(131), UINT8_C(236) },
          { UINT8_C(  8), UINT8_C(190), UINT8_C(247), UINT8_C(161), UINT8_C(187), UINT8_C(228), UINT8_C( 88), UINT8_C(173),
            UINT8_C(162), UINT8_C(211), UINT8_C(183), UINT8_C( 18), UINT8_C(214), UINT8_C(163), UINT8_C( 14), UINT8_C(248) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16x2_t r = simde_vtrnq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], simde_vld1q_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], simde_vld1q_u8(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrnq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[2][8];
  } test_vec[] = {
    { { UINT16_C(60557), UINT16_C( 2003), UINT16_C(18326), UINT16_C(50944), UINT16_C(20033), UINT16_C(41177), UINT16_C(55949), UINT16_C(55500) },
      { UINT16_C(24134), UINT16_C(17611), UINT16_C(40546), UINT16_C(12683), UINT16_C(16844), UINT16_C(15740), UINT16_C(47346), UINT16_C(32687) },
      {
          { UINT16_C(60557), UINT16_C(24134), UINT16_C(18326), UINT16_C(40546), UINT16_C(20033), UINT16_C(16844), UINT16_C(55949), UINT16_C(47346) },
          { UINT16_C( 2003), UINT16_C(17611), UINT16_C(50944), UINT16_C(12683), UINT16_C(41177), UINT16_C(15740), UINT16_C(55500), UINT16_C(32687) },
      },
    },
    { { UINT16_C(33444), UINT16_C(14982), UINT16_C(34505), UINT16_C( 2818), UINT16_C(56277), UINT16_C(25259), UINT16_C(30645), UINT16_C(64314) },
      { UINT16_C( 1493), UINT16_C(14399), UINT16_C(52132), UINT16_C(28777), UINT16_C(58636), UINT16_C(65453), UINT16_C(23709), UINT16_C(16766) },
      {
          { UINT16_C(33444), UINT16_C( 1493), UINT16_C(34505), UINT16_C(52132), UINT16_C(56277), UINT16_C(58636), UINT16_C(30645), UINT16_C(23709) },
          { UINT16_C(14982), UINT16_C(14399), UINT16_C( 2818), UINT16_C(28777), UINT16_C(25259), UINT16_C(65453), UINT16_C(64314), UINT16_C(16766) },
      },
    },
    { { UINT16_C( 1502), UINT16_C(43132), UINT16_C(32395), UINT16_C(24755), UINT16_C(24153), UINT16_C( 3779), UINT16_C(64981), UINT16_C(43786) },
      { UINT16_C(18691), UINT16_C(42979), UINT16_C(19476), UINT16_C( 8471), UINT16_C(50225), UINT16_C(53024), UINT16_C(40480), UINT16_C(65040) },
      {
          { UINT16_C( 1502), UINT16_C(18691), UINT16_C(32395), UINT16_C(19476), UINT16_C(24153), UINT16_C(50225), UINT16_C(64981), UINT16_C(40480) },
          { UINT16_C(43132), UINT16_C(42979), UINT16_C(24755), UINT16_C( 8471), UINT16_C( 3779), UINT16_C(53024), UINT16_C(43786), UINT16_C(65040) },
      },
    },
    { { UINT16_C(36003), UINT16_C(12198), UINT16_C(22794), UINT16_C(25487), UINT16_C(21175), UINT16_C(36210), UINT16_C(31824), UINT16_C(21304) },
      { UINT16_C( 7109), UINT16_C(56058), UINT16_C( 4455), UINT16_C(39163), UINT16_C( 7125), UINT16_C(62823), UINT16_C(30905), UINT16_C(24051) },
      {
          { UINT16_C(36003), UINT16_C( 7109), UINT16_C(22794), UINT16_C( 4455), UINT16_C(21175), UINT16_C( 7125), UINT16_C(31824), UINT16_C(30905) },
          { UINT16_C(12198), UINT16_C(56058), UINT16_C(25487), UINT16_C(39163), UINT16_C(36210), UINT16_C(62823), UINT16_C(21304), UINT16_C(24051) },
      },
    },
    { { UINT16_C(39428), UINT16_C( 3980), UINT16_C( 7155), UINT16_C(43890), UINT16_C(58478), UINT16_C(48696), UINT16_C(28768), UINT16_C( 9745) },
      { UINT16_C( 2955), UINT16_C(61952), UINT16_C(64284), UINT16_C(61834), UINT16_C(61974), UINT16_C(53222), UINT16_C(55658), UINT16_C(28204) },
      {
          { UINT16_C(39428), UINT16_C( 2955), UINT16_C( 7155), UINT16_C(64284), UINT16_C(58478), UINT16_C(61974), UINT16_C(28768), UINT16_C(55658) },
          { UINT16_C( 3980), UINT16_C(61952), UINT16_C(43890), UINT16_C(61834), UINT16_C(48696), UINT16_C(53222), UINT16_C( 9745), UINT16_C(28204) },
      },
    },
    { { UINT16_C(47219), UINT16_C(26493), UINT16_C(61652), UINT16_C(16914), UINT16_C(19156), UINT16_C(13568), UINT16_C( 4538), UINT16_C(17755) },
      { UINT16_C(23324), UINT16_C(14391), UINT16_C(49494), UINT16_C(27689), UINT16_C( 4019), UINT16_C( 7483), UINT16_C(26856), UINT16_C(23692) },
      {
          { UINT16_C(47219), UINT16_C(23324), UINT16_C(61652), UINT16_C(49494), UINT16_C(19156), UINT16_C( 4019), UINT16_C( 4538), UINT16_C(26856) },
          { UINT16_C(26493), UINT16_C(14391), UINT16_C(16914), UINT16_C(27689), UINT16_C(13568), UINT16_C( 7483), UINT16_C(17755), UINT16_C(23692) },
      },
    },
    { { UINT16_C( 2336), UINT16_C(62659), UINT16_C(54777), UINT16_C(52790), UINT16_C(13855), UINT16_C(55555), UINT16_C(24135), UINT16_C(25374) },
      { UINT16_C(21945), UINT16_C( 3995), UINT16_C(50198), UINT16_C(51835), UINT16_C(46803), UINT16_C(48359), UINT16_C(29470), UINT16_C(16152) },
      {
          { UINT16_C( 2336), UINT16_C(21945), UINT16_C(54777), UINT16_C(50198), UINT16_C(13855), UINT16_C(46803), UINT16_C(24135), UINT16_C(29470) },
          { UINT16_C(62659), UINT16_C( 3995), UINT16_C(52790), UINT16_C(51835), UINT16_C(55555), UINT16_C(48359), UINT16_C(25374), UINT16_C(16152) },
      },
    },
    { { UINT16_C(56189), UINT16_C(30259), UINT16_C(27312), UINT16_C(53060), UINT16_C(18336), UINT16_C(59560), UINT16_C(50853), UINT16_C(24139) },
      { UINT16_C(59163), UINT16_C(12653), UINT16_C(59563), UINT16_C(32763), UINT16_C(58271), UINT16_C(48443), UINT16_C(21334), UINT16_C(54268) },
      {
          { UINT16_C(56189), UINT16_C(59163), UINT16_C(27312), UINT16_C(59563), UINT16_C(18336), UINT16_C(58271), UINT16_C(50853), UINT16_C(21334) },
          { UINT16_C(30259), UINT16_C(12653), UINT16_C(53060), UINT16_C(32763), UINT16_C(59560), UINT16_C(48443), UINT16_C(24139), UINT16_C(54268) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8x2_t r = simde_vtrnq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r.val[0], simde_vld1q_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], simde_vld1q_u16(test_vec[i].r[1]));
  }

  return 0;
}

static int
test_simde_vtrnq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[2][4];
  } test_vec[] = {
    { { UINT32_C(1309098840), UINT32_C( 298067663), UINT32_C( 699572772), UINT32_C( 489541366) },
      { UINT32_C(2219089279), UINT32_C(2283573183), UINT32_C(1328363319), UINT32_C( 765180373) },
      {
          { UINT32_C(1309098840), UINT32_C(2219089279), UINT32_C( 699572772), UINT32_C(1328363319) },
          { UINT32_C( 298067663), UINT32_C(2283573183), UINT32_C( 489541366), UINT32_C( 765180373) },
      },
    },
    { { UINT32_C(3430654716), UINT32_C(3973922760), UINT32_C(3608514529), UINT32_C(3723838301) },
      { UINT32_C(2673949152), UINT32_C(   2588105), UINT32_C(2303743156), UINT32_C( 179759885) },
      {
          { UINT32_C(3430654716), UINT32_C(2673949152), UINT32_C(3608514529), UINT32_C(2303743156) },
          { UINT32_C(3973922760), UINT32_C(   2588105), UINT32_C(3723838301), UINT32_C( 179759885) },
      },
    },
    { { UINT32_C(1456877965), UINT32_C(1380103024), UINT32_C(2670286914), UINT32_C(2071731867) },
      { UINT32_C( 555408728), UINT32_C( 237060698), UINT32_C(2761388438), UINT32_C(3937291612) },
      {
          { UINT32_C(1456877965), UINT32_C( 555408728), UINT32_C(2670286914), UINT32_C(2761388438) },
          { UINT32_C(1380103024), UINT32_C( 237060698), UINT32_C(2071731867), UINT32_C(3937291612) },
      },
    },
    { { UINT32_C(4013982846), UINT32_C(2034336311), UINT32_C(1964534490), UINT32_C(3790640521) },
      { UINT32_C(3439463282), UINT32_C(3822789453), UINT32_C(4052186005), UINT32_C(1071330752) },
      {
          { UINT32_C(4013982846), UINT32_C(3439463282), UINT32_C(1964534490), UINT32_C(4052186005) },
          { UINT32_C(2034336311), UINT32_C(3822789453), UINT32_C(3790640521), UINT32_C(1071330752) },
      },
    },
    { { UINT32_C(4029553593), UINT32_C(2020175774), UINT32_C(1659798233), UINT32_C(2302926359) },
      { UINT32_C( 911623657), UINT32_C(4263129705), UINT32_C(1710203301), UINT32_C(2426719191) },
      {
          { UINT32_C(4029553593), UINT32_C( 911623657), UINT32_C(1659798233), UINT32_C(1710203301) },
          { UINT32_C(2020175774), UINT32_C(4263129705), UINT32_C(2302926359), UINT32_C(2426719191) },
      },
    },
    { { UINT32_C(2223100646), UINT32_C( 469625409), UINT32_C(2206067564), UINT32_C(3004023241) },
      { UINT32_C(1877566214), UINT32_C( 980222869), UINT32_C(2090884517), UINT32_C( 235684904) },
      {
          { UINT32_C(2223100646), UINT32_C(1877566214), UINT32_C(2206067564), UINT32_C(2090884517) },
          { UINT32_C( 469625409), UINT32_C( 980222869), UINT32_C(3004023241), UINT32_C( 235684904) },
      },
    },
    { { UINT32_C(1486064919), UINT32_C(3832778872), UINT32_C(1147728251), UINT32_C(3103225266) },
      { UINT32_C(1848173016), UINT32_C(2309527012), UINT32_C( 436553970), UINT32_C(2754155149) },
      {
          { UINT32_C(1486064919), UINT32_C(1848173016), UINT32_C(1147728251), UINT32_C( 436553970) },
          { UINT32_C(3832778872), UINT32_C(2309527012), UINT32_C(3103225266), UINT32_C(2754155149) },
      },
    },
    { { UINT32_C( 402439327), UINT32_C(3355209804), UINT32_C( 319513697), UINT32_C(2982872025) },
      { UINT32_C(3357537252), UINT32_C(2069022857), UINT32_C(2643875600), UINT32_C( 155303785) },
      {
          { UINT32_C( 402439327), UINT32_C(3357537252), UINT32_C( 319513697), UINT32_C(2643875600) },
          { UINT32_C(3355209804), UINT32_C(2069022857), UINT32_C(2982872025), UINT32_C( 155303785) },
      },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4x2_t r = simde_vtrnq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], simde_vld1q_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], simde_vld1q_u32(test_vec[i].r[1]));
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vtrnq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrnq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrnq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrnq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrnq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrnq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrnq_u32)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
