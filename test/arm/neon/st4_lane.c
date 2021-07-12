#define SIMDE_TEST_ARM_NEON_INSN st4_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/st4_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst4_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[4];
    int8_t val[4][8];
    int lane;
  } test_vec[] = {
    { { -INT8_C( 117),  INT8_C(  32),  INT8_C(  21), -INT8_C( 101) },
        { { -INT8_C( 117), -INT8_C( 122), -INT8_C(  93), -INT8_C(   2), -INT8_C(   7), -INT8_C(  66), -INT8_C(  85),  INT8_C( 101) },
          {  INT8_C(  32),  INT8_C(  87), -INT8_C(  19),  INT8_C(  83),  INT8_C(  50), -INT8_C(  35),  INT8_C(  94),  INT8_C(  59) },
          {  INT8_C(  21),  INT8_C(  94), -INT8_C( 118), -INT8_C(  76),  INT8_C(  81), -INT8_C(  59),  INT8_C( 123), -INT8_C(  80) },
          { -INT8_C( 101), -INT8_C(  37), -INT8_C(  25),  INT8_C(  20), -INT8_C( 100), -INT8_C(  52),  INT8_C(  82),  INT8_C(  40) } },
       INT32_C(           0) },
    { { -INT8_C(  10), -INT8_C(  99),  INT8_C(  32), -INT8_C(  51) },
        { {  INT8_C(  82), -INT8_C(  10),  INT8_C(  38),  INT8_C(  75), -INT8_C(  76), -INT8_C(  46), -INT8_C(  80), -INT8_C(  43) },
          {  INT8_C(  41), -INT8_C(  99),  INT8_C(  40),  INT8_C(  91),  INT8_C( 123), -INT8_C( 122), -INT8_C( 106), -INT8_C( 112) },
          { -INT8_C(  28),  INT8_C(  32),  INT8_C(  69),  INT8_C(  53), -INT8_C(  27), -INT8_C(  64), -INT8_C(  26), -INT8_C( 127) },
          { -INT8_C( 101), -INT8_C(  51), -INT8_C( 107),  INT8_C(  55), -INT8_C( 102), -INT8_C(  25),  INT8_C(  95), -INT8_C(  20) } },
       INT32_C(           1) },
    { {  INT8_C(  56), -INT8_C(  36),  INT8_C(  47),  INT8_C( 105) },
        { { -INT8_C(  35), -INT8_C( 122),  INT8_C(  56), -INT8_C( 110),  INT8_C(  88), -INT8_C(  24),  INT8_C( 103), -INT8_C( 127) },
          { -INT8_C( 122), -INT8_C( 113), -INT8_C(  36),  INT8_C(   1),  INT8_C(  21),  INT8_C( 114), -INT8_C( 111), -INT8_C(   6) },
          { -INT8_C( 110), -INT8_C(  42),  INT8_C(  47),  INT8_C( 120), -INT8_C( 106),  INT8_C(  21), -INT8_C(   7),  INT8_C(  49) },
          { -INT8_C(  29), -INT8_C( 114),  INT8_C( 105),  INT8_C( 125),  INT8_C( 117), -INT8_C(  56),  INT8_C( 105),  INT8_C(  83) } },
       INT32_C(           2) },
    { { -INT8_C(  90), -INT8_C(  16),  INT8_C(  15),  INT8_C( 124) },
        { {  INT8_C(  78), -INT8_C(  95), -INT8_C(  27), -INT8_C(  90), -INT8_C( 118),  INT8_C(  76),  INT8_C(  39),  INT8_C(  16) },
          { -INT8_C(  37),  INT8_C(   3),  INT8_C(  17), -INT8_C(  16),  INT8_C( 117), -INT8_C(  94), -INT8_C(  22),  INT8_C(   8) },
          {  INT8_C( 121),  INT8_C(  26),      INT8_MIN,  INT8_C(  15),  INT8_C(  47),  INT8_C( 121),  INT8_C(  65),  INT8_C(  18) },
          {  INT8_C(   7), -INT8_C(  86), -INT8_C( 113),  INT8_C( 124),  INT8_C( 114), -INT8_C(   7), -INT8_C(  49), -INT8_C(  63) } },
       INT32_C(           3) },
    { {  INT8_C(   0), -INT8_C(  24),  INT8_C(   9), -INT8_C( 101) },
        { { -INT8_C( 102), -INT8_C(  76),  INT8_C( 103),  INT8_C(  36),  INT8_C(   0), -INT8_C( 113),  INT8_C(  52), -INT8_C(  37) },
          { -INT8_C( 110),  INT8_C(  69), -INT8_C(  52),  INT8_C(   8), -INT8_C(  24), -INT8_C(  74),  INT8_C(  16),  INT8_C(  97) },
          { -INT8_C(  48), -INT8_C( 112),  INT8_C( 112),  INT8_C(   0),  INT8_C(   9), -INT8_C(  79),  INT8_C(  18),  INT8_C(  16) },
          {  INT8_C(  91), -INT8_C(  94), -INT8_C( 116), -INT8_C(  50), -INT8_C( 101),  INT8_C(  92), -INT8_C( 113),  INT8_C(  53) } },
       INT32_C(           4) },
    { { -INT8_C( 114),  INT8_C(  48),  INT8_C(  82), -INT8_C(   9) },
        { {  INT8_C(  16), -INT8_C(  10),  INT8_C(  90),  INT8_C(  17), -INT8_C( 123), -INT8_C( 114), -INT8_C(  20),  INT8_C(  24) },
          { -INT8_C(  44), -INT8_C(  72),  INT8_C(  32), -INT8_C(  68),  INT8_C( 111),  INT8_C(  48),  INT8_C(  29),  INT8_C(  63) },
          { -INT8_C(  64), -INT8_C( 115),  INT8_C(  63), -INT8_C(  55),  INT8_C(  63),  INT8_C(  82), -INT8_C(  39), -INT8_C( 102) },
          { -INT8_C(  12),  INT8_C( 101),  INT8_C( 104), -INT8_C( 113), -INT8_C(  63), -INT8_C(   9), -INT8_C(  60), -INT8_C(  46) } },
       INT32_C(           5) },
    { { -INT8_C( 117),  INT8_C(  54), -INT8_C(  63),  INT8_C(  54) },
        { { -INT8_C(  18),  INT8_C(  30), -INT8_C(  29),  INT8_C( 115), -INT8_C(  83), -INT8_C(  49), -INT8_C( 117), -INT8_C( 127) },
          { -INT8_C( 120), -INT8_C(  85),  INT8_C(  61), -INT8_C(   9), -INT8_C(  37),  INT8_C(  90),  INT8_C(  54), -INT8_C( 101) },
          { -INT8_C(  25),  INT8_C( 118),  INT8_C( 100),  INT8_C(  38), -INT8_C(  56),  INT8_C(  61), -INT8_C(  63), -INT8_C(  68) },
          { -INT8_C(  93),  INT8_C(  41),  INT8_C(  75),  INT8_C( 100),  INT8_C(  33),  INT8_C(  15),  INT8_C(  54),  INT8_C(  15) } },
       INT32_C(           6) },
    { {  INT8_C( 113), -INT8_C(  38),  INT8_C( 117),  INT8_C(  33) },
        { {  INT8_C(  46),  INT8_C(  25), -INT8_C( 126), -INT8_C(  37), -INT8_C(  23),  INT8_C(  14),  INT8_C(  92),  INT8_C( 113) },
          { -INT8_C(  71), -INT8_C( 103),  INT8_C( 104), -INT8_C( 107), -INT8_C(  13), -INT8_C(  98),  INT8_C(  48), -INT8_C(  38) },
          {  INT8_C(  20), -INT8_C( 107),  INT8_C(   1), -INT8_C(  36), -INT8_C(  46), -INT8_C(  62), -INT8_C( 104),  INT8_C( 117) },
          { -INT8_C(  21), -INT8_C(  29), -INT8_C(  38),  INT8_C(  12), -INT8_C(  13),  INT8_C(  16),  INT8_C(  27),  INT8_C(  33) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8x4_t val = {{simde_vld1_s8(test_vec[i].val[0]),
                             simde_vld1_s8(test_vec[i].val[1]),
                             simde_vld1_s8(test_vec[i].val[2]),
                             simde_vld1_s8(test_vec[i].val[3])}};
    int8_t a[4];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst4_lane_s8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i8(a[0], test_vec[i].a[0]);
    simde_assert_equal_i8(a[1], test_vec[i].a[1]);
    simde_assert_equal_i8(a[2], test_vec[i].a[2]);
    simde_assert_equal_i8(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a[4];
    simde_int8x8x4_t val = simde_test_arm_neon_random_i8x8x4();
    const int lane = lanes[i];
    simde_vst4_lane_s8(a, val, lane);

    simde_test_codegen_write_vi8(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t val[4][4];
    int lane;
  } test_vec[] = {
    { {  INT16_C( 18751),  INT16_C( 21463),  INT16_C( 19842),  INT16_C( 19554) },
        { {  INT16_C( 18751), -INT16_C( 18019), -INT16_C(  7647),  INT16_C( 31719) },
          {  INT16_C( 21463),  INT16_C( 30326),  INT16_C(  5838), -INT16_C(  2864) },
          {  INT16_C( 19842), -INT16_C( 31548), -INT16_C(  7393), -INT16_C( 27248) },
          {  INT16_C( 19554),  INT16_C( 19804), -INT16_C( 22843),  INT16_C(  1116) } },
       INT32_C(           0) },
    { {  INT16_C(  4541), -INT16_C( 14807),  INT16_C( 26399), -INT16_C( 16366) },
        { { -INT16_C(  1552),  INT16_C(  4541), -INT16_C( 23076), -INT16_C( 19572) },
          {  INT16_C(   760), -INT16_C( 14807), -INT16_C(  1512), -INT16_C( 25669) },
          {  INT16_C( 32583),  INT16_C( 26399), -INT16_C( 20638), -INT16_C( 15108) },
          {  INT16_C( 23035), -INT16_C( 16366),  INT16_C( 28415), -INT16_C(  4156) } },
       INT32_C(           1) },
    { { -INT16_C( 29657), -INT16_C( 24550), -INT16_C( 15088), -INT16_C( 28473) },
        { { -INT16_C( 32152),  INT16_C( 17408), -INT16_C( 29657),  INT16_C(  8183) },
          {  INT16_C(  8335), -INT16_C( 22555), -INT16_C( 24550),  INT16_C( 25154) },
          {  INT16_C( 24864), -INT16_C( 32055), -INT16_C( 15088),  INT16_C(  2887) },
          {  INT16_C( 22814),  INT16_C(  7883), -INT16_C( 28473),  INT16_C( 12045) } },
       INT32_C(           2) },
    { {  INT16_C( 10584), -INT16_C(   505), -INT16_C( 19311), -INT16_C(   489) },
        { {  INT16_C(  3602),  INT16_C( 14707),  INT16_C( 27290),  INT16_C( 10584) },
          {  INT16_C( 15755), -INT16_C( 23087),  INT16_C(  5086), -INT16_C(   505) },
          { -INT16_C( 12171), -INT16_C( 31360), -INT16_C( 14442), -INT16_C( 19311) },
          {  INT16_C( 23584), -INT16_C(  5934), -INT16_C(  7956), -INT16_C(   489) } },
       INT32_C(           3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4x4_t val = {{simde_vld1_s16(test_vec[i].val[0]),
                              simde_vld1_s16(test_vec[i].val[1]),
                              simde_vld1_s16(test_vec[i].val[2]),
                              simde_vld1_s16(test_vec[i].val[3])}};
    int16_t a[4];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst4_lane_s16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i16(a[0], test_vec[i].a[0]);
    simde_assert_equal_i16(a[1], test_vec[i].a[1]);
    simde_assert_equal_i16(a[2], test_vec[i].a[2]);
    simde_assert_equal_i16(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    int16_t a[4];
    simde_int16x4x4_t val = simde_test_arm_neon_random_i16x4x4();
    const int lane = lanes[i];
    simde_vst4_lane_s16(a, val, lane);

    simde_test_codegen_write_vi16(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t val[4][2];
    int lane;
  } test_vec[] = {
    { { -INT32_C(   160598564),  INT32_C(  2106407530), -INT32_C(   406179992), -INT32_C(   280676446) },
        { { -INT32_C(   160598564),  INT32_C(   551364691) },
          {  INT32_C(  2106407530),  INT32_C(  1776330705) },
          { -INT32_C(   406179992), -INT32_C(   941418603) },
          { -INT32_C(   280676446),  INT32_C(   633861961) } },
       INT32_C(           0) },
    { { -INT32_C(   941622948),  INT32_C(  2070815763), -INT32_C(   223394225),  INT32_C(  1475127531) },
        { { -INT32_C(  1088670612), -INT32_C(   941622948) },
          {  INT32_C(    88370228),  INT32_C(  2070815763) },
          { -INT32_C(   396150701), -INT32_C(   223394225) },
          { -INT32_C(   958270339),  INT32_C(  1475127531) } },
       INT32_C(           1) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2x4_t val = {{simde_vld1_s32(test_vec[i].val[0]),
                              simde_vld1_s32(test_vec[i].val[1]),
                              simde_vld1_s32(test_vec[i].val[2]),
                              simde_vld1_s32(test_vec[i].val[3])}};
    int32_t a[4];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst4_lane_s32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i32(a[0], test_vec[i].a[0]);
    simde_assert_equal_i32(a[1], test_vec[i].a[1]);
    simde_assert_equal_i32(a[2], test_vec[i].a[2]);
    simde_assert_equal_i32(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a[4];
    simde_int32x2x4_t val = simde_test_arm_neon_random_i32x2x4();
    const int lane = lanes[i];
    simde_vst4_lane_s32(a, val, lane);

    simde_test_codegen_write_vi32(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[4];
    int64_t val[4][1];
  } test_vec[] = {
    { {  INT64_C( 6264845093810014713),  INT64_C( 4366389087829573396), -INT64_C( 4830588686067564620), -INT64_C(  745919699940331069) },
        { {  INT64_C( 6264845093810014713) },
          {  INT64_C( 4366389087829573396) },
          { -INT64_C( 4830588686067564620) },
          { -INT64_C(  745919699940331069) } },
    },
    { {  INT64_C( 5962901414644157438),  INT64_C( 3869908751395191226), -INT64_C( 5650001105951416147), -INT64_C( 6751884696061759654) },
        { {  INT64_C( 5962901414644157438) },
          {  INT64_C( 3869908751395191226) },
          { -INT64_C( 5650001105951416147) },
          { -INT64_C( 6751884696061759654) } },
    }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1x4_t val = {{simde_vld1_s64(test_vec[i].val[0]),
                              simde_vld1_s64(test_vec[i].val[1]),
                              simde_vld1_s64(test_vec[i].val[2]),
                              simde_vld1_s64(test_vec[i].val[3])}};
    int64_t a[4];
    simde_vst4_lane_s64(a, val, 0);

    simde_assert_equal_i64(a[0], test_vec[i].a[0]);
    simde_assert_equal_i64(a[1], test_vec[i].a[1]);
    simde_assert_equal_i64(a[2], test_vec[i].a[2]);
    simde_assert_equal_i64(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    int64_t a[4];
    simde_int64x1x4_t val = simde_test_arm_neon_random_i64x1x4();
    simde_vst4_lane_s64(a, val, 0);

    simde_test_codegen_write_vi64(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[4];
    uint8_t val[4][8];
    int lane;
  } test_vec[] = {
    { { UINT8_C(181), UINT8_C(137), UINT8_C(104), UINT8_C(146) },
        { { UINT8_C(181), UINT8_C(176), UINT8_C( 53), UINT8_C( 16), UINT8_C(165), UINT8_C(173), UINT8_C(175), UINT8_C(  2) },
          { UINT8_C(137), UINT8_C( 89), UINT8_C(  0), UINT8_C(240), UINT8_C( 75), UINT8_C(211), UINT8_C(138), UINT8_C(202) },
          { UINT8_C(104), UINT8_C( 42), UINT8_C( 98), UINT8_C( 36), UINT8_C( 28), UINT8_C( 41), UINT8_C(226), UINT8_C( 44) },
          { UINT8_C(146), UINT8_C(231), UINT8_C( 22), UINT8_C(190), UINT8_C(193), UINT8_C(157), UINT8_C(188), UINT8_C(118) } },
       INT32_C(           0) },
    { { UINT8_C(241), UINT8_C(245), UINT8_C(  8), UINT8_C( 43) },
        { { UINT8_C( 77), UINT8_C(241), UINT8_C(135), UINT8_C(243), UINT8_C(158), UINT8_C( 54), UINT8_C(245), UINT8_C( 39) },
          { UINT8_C(143), UINT8_C(245), UINT8_C( 23), UINT8_C(219), UINT8_C(200), UINT8_C(162), UINT8_C(165), UINT8_C( 48) },
          { UINT8_C(204), UINT8_C(  8), UINT8_C( 85), UINT8_C(232), UINT8_C( 49), UINT8_C( 55), UINT8_C( 20), UINT8_C(195) },
          { UINT8_C( 30), UINT8_C( 43), UINT8_C(130), UINT8_C(224), UINT8_C(200), UINT8_C( 62), UINT8_C( 86), UINT8_C( 21) } },
       INT32_C(           1) },
    { { UINT8_C(  8), UINT8_C(126), UINT8_C( 97), UINT8_C(118) },
        { { UINT8_C( 47), UINT8_C(221), UINT8_C(  8), UINT8_C(205), UINT8_C( 19), UINT8_C(253), UINT8_C(244), UINT8_C(163) },
          { UINT8_C(242), UINT8_C( 11), UINT8_C(126), UINT8_C(186), UINT8_C(173), UINT8_C( 35), UINT8_C(235), UINT8_C(121) },
          { UINT8_C( 43), UINT8_C( 64), UINT8_C( 97), UINT8_C( 92), UINT8_C(119), UINT8_C(118), UINT8_C( 32), UINT8_C(150) },
          { UINT8_C(161), UINT8_C(162), UINT8_C(118), UINT8_C(105), UINT8_C(224), UINT8_C(204), UINT8_C(126), UINT8_C( 15) } },
       INT32_C(           2) },
    { { UINT8_C(189), UINT8_C(137), UINT8_C(212), UINT8_C( 44) },
        { { UINT8_C(170), UINT8_C(135), UINT8_C(220), UINT8_C(189), UINT8_C(132), UINT8_C(208), UINT8_C( 96), UINT8_C(119) },
          { UINT8_C(219), UINT8_C(222), UINT8_C( 49), UINT8_C(137), UINT8_C(  2), UINT8_C( 28), UINT8_C(  2), UINT8_C( 45) },
          { UINT8_C( 92), UINT8_C(100), UINT8_C(138), UINT8_C(212), UINT8_C(218), UINT8_C(170), UINT8_C(106), UINT8_C(123) },
          { UINT8_C( 76), UINT8_C(224), UINT8_C(228), UINT8_C( 44), UINT8_C(172), UINT8_C( 98), UINT8_C( 59), UINT8_C( 86) } },
       INT32_C(           3) },
    { { UINT8_C(231), UINT8_C( 51), UINT8_C(182), UINT8_C( 77) },
        { { UINT8_C(233), UINT8_C( 23), UINT8_C( 20), UINT8_C(110), UINT8_C(231), UINT8_C(116), UINT8_C(229), UINT8_C(194) },
          { UINT8_C( 83), UINT8_C( 22), UINT8_C( 75), UINT8_C( 85), UINT8_C( 51), UINT8_C( 78), UINT8_C(130), UINT8_C(143) },
          { UINT8_C(178), UINT8_C( 12), UINT8_C( 99), UINT8_C(140), UINT8_C(182), UINT8_C(205), UINT8_C(  7), UINT8_C(  2) },
          { UINT8_C(173), UINT8_C(235), UINT8_C( 46), UINT8_C( 90), UINT8_C( 77), UINT8_C(105), UINT8_C(176), UINT8_C( 55) } },
       INT32_C(           4) },
    { { UINT8_C(138), UINT8_C( 99), UINT8_C(  8), UINT8_C( 76) },
        { { UINT8_C(128), UINT8_C(196), UINT8_C(165), UINT8_C(103), UINT8_C( 57), UINT8_C(138), UINT8_C( 42), UINT8_C(140) },
          { UINT8_C(160), UINT8_C(117), UINT8_C(225), UINT8_C(211), UINT8_C(195), UINT8_C( 99), UINT8_C( 99), UINT8_C(117) },
          { UINT8_C(112), UINT8_C(198), UINT8_C(  1), UINT8_C( 38), UINT8_C(148), UINT8_C(  8), UINT8_C( 41), UINT8_C( 65) },
          { UINT8_C(243), UINT8_C( 87), UINT8_C(155), UINT8_C( 65), UINT8_C(193), UINT8_C( 76), UINT8_C(120), UINT8_C( 65) } },
       INT32_C(           5) },
    { { UINT8_C(213), UINT8_C(129), UINT8_C( 26), UINT8_C( 51) },
        { { UINT8_C( 16), UINT8_C( 29), UINT8_C(169), UINT8_C( 73), UINT8_C(167), UINT8_C(211), UINT8_C(213), UINT8_C( 71) },
          { UINT8_C( 72), UINT8_C(182), UINT8_C( 27), UINT8_C( 12), UINT8_C( 26), UINT8_C(126), UINT8_C(129), UINT8_C(138) },
          { UINT8_C( 68), UINT8_C(131), UINT8_C(176), UINT8_C(216), UINT8_C(139), UINT8_C(217), UINT8_C( 26), UINT8_C(127) },
          { UINT8_C( 49), UINT8_C(181), UINT8_C(192), UINT8_C(242), UINT8_C(  1), UINT8_C( 56), UINT8_C( 51), UINT8_C( 18) } },
       INT32_C(           6) },
    { { UINT8_C(248), UINT8_C( 33), UINT8_C( 70), UINT8_C( 96) },
        { { UINT8_C( 85), UINT8_C(220), UINT8_C( 91), UINT8_C(252), UINT8_C(175), UINT8_C( 49), UINT8_C( 67), UINT8_C(248) },
          { UINT8_C(231), UINT8_C( 94), UINT8_C(  4), UINT8_C(  1), UINT8_C(220), UINT8_C(133), UINT8_C(139), UINT8_C( 33) },
          { UINT8_C(  8), UINT8_C( 60), UINT8_C(249), UINT8_C(148), UINT8_C( 21), UINT8_C( 19), UINT8_C( 19), UINT8_C( 70) },
          { UINT8_C(201), UINT8_C(211), UINT8_C( 56), UINT8_C(202), UINT8_C( 11), UINT8_C(108), UINT8_C(220), UINT8_C( 96) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8x4_t val = {{simde_vld1_u8(test_vec[i].val[0]),
                              simde_vld1_u8(test_vec[i].val[1]),
                              simde_vld1_u8(test_vec[i].val[2]),
                              simde_vld1_u8(test_vec[i].val[3])}};
    uint8_t a[4];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst4_lane_u8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u8(a[0], test_vec[i].a[0]);
    simde_assert_equal_u8(a[1], test_vec[i].a[1]);
    simde_assert_equal_u8(a[2], test_vec[i].a[2]);
    simde_assert_equal_u8(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a[4];
    simde_uint8x8x4_t val = simde_test_arm_neon_random_u8x8x4();
    const int lane = lanes[i];
    simde_vst4_lane_u8(a, val, lane);

    simde_test_codegen_write_vu8(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t val[4][4];
    int lane;
  } test_vec[] = {
    { { UINT16_C( 5940), UINT16_C(19433), UINT16_C(18807), UINT16_C(53244) },
        { { UINT16_C( 5940), UINT16_C(39814), UINT16_C(48463), UINT16_C(22394) },
          { UINT16_C(19433), UINT16_C(46498), UINT16_C(31312), UINT16_C( 7208) },
          { UINT16_C(18807), UINT16_C(41171), UINT16_C(58228), UINT16_C(64400) },
          { UINT16_C(53244), UINT16_C(36441), UINT16_C(63235), UINT16_C(14126) } },
       INT32_C(           0) },
    { { UINT16_C(24019), UINT16_C(59408), UINT16_C(63208), UINT16_C(19013) },
        { { UINT16_C(46094), UINT16_C(24019), UINT16_C(19826), UINT16_C(23476) },
          { UINT16_C(22168), UINT16_C(59408), UINT16_C(14801), UINT16_C(18436) },
          { UINT16_C(55170), UINT16_C(63208), UINT16_C(30907), UINT16_C(47089) },
          { UINT16_C(19015), UINT16_C(19013), UINT16_C(29505), UINT16_C(20353) } },
       INT32_C(           1) },
    { { UINT16_C(24993), UINT16_C( 9535), UINT16_C(43312), UINT16_C(17191) },
        { { UINT16_C(21544), UINT16_C(39596), UINT16_C(24993), UINT16_C(14837) },
          { UINT16_C( 1719), UINT16_C(34849), UINT16_C( 9535), UINT16_C(49616) },
          { UINT16_C(47357), UINT16_C(47287), UINT16_C(43312), UINT16_C(30575) },
          { UINT16_C(46323), UINT16_C(13761), UINT16_C(17191), UINT16_C(20356) } },
       INT32_C(           2) },
    { { UINT16_C(18802), UINT16_C(46821), UINT16_C(14595), UINT16_C(40712) },
        { { UINT16_C(12695), UINT16_C(14825), UINT16_C(57234), UINT16_C(18802) },
          { UINT16_C(38117), UINT16_C( 9426), UINT16_C(41657), UINT16_C(46821) },
          { UINT16_C(40027), UINT16_C(35694), UINT16_C(56645), UINT16_C(14595) },
          { UINT16_C(50321), UINT16_C(47470), UINT16_C(61959), UINT16_C(40712) } },
       INT32_C(           3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4x4_t val = {{simde_vld1_u16(test_vec[i].val[0]),
                               simde_vld1_u16(test_vec[i].val[1]),
                               simde_vld1_u16(test_vec[i].val[2]),
                               simde_vld1_u16(test_vec[i].val[3])}};
    uint16_t a[4];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst4_lane_u16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u16(a[0], test_vec[i].a[0]);
    simde_assert_equal_u16(a[1], test_vec[i].a[1]);
    simde_assert_equal_u16(a[2], test_vec[i].a[2]);
    simde_assert_equal_u16(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    uint16_t a[4];
    simde_uint16x4x4_t val = simde_test_arm_neon_random_u16x4x4();
    const int lane = lanes[i];
    simde_vst4_lane_u16(a, val, lane);

    simde_test_codegen_write_vu16(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t val[4][2];
    int lane;
  } test_vec[] = {
    { { UINT32_C(3031400368), UINT32_C(3219718125), UINT32_C(3802020061), UINT32_C(4066775446) },
        { { UINT32_C(3031400368), UINT32_C(4285871924) },
          { UINT32_C(3219718125), UINT32_C(2603222966) },
          { UINT32_C(3802020061), UINT32_C(2452233766) },
          { UINT32_C(4066775446), UINT32_C(1888111040) } },
      UINT32_C(         0) },
    { { UINT32_C(1593547120), UINT32_C(3370862571), UINT32_C(1043911847), UINT32_C(2937502439) },
        { { UINT32_C(4230232520), UINT32_C(1593547120) },
          { UINT32_C(1327359129), UINT32_C(3370862571) },
          { UINT32_C(2796194175), UINT32_C(1043911847) },
          { UINT32_C(2771427045), UINT32_C(2937502439) } },
      UINT32_C(         1) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2x4_t val = {{simde_vld1_u32(test_vec[i].val[0]),
                               simde_vld1_u32(test_vec[i].val[1]),
                               simde_vld1_u32(test_vec[i].val[2]),
                               simde_vld1_u32(test_vec[i].val[3])}};
    uint32_t a[4];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst4_lane_u32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u32(a[0], test_vec[i].a[0]);
    simde_assert_equal_u32(a[1], test_vec[i].a[1]);
    simde_assert_equal_u32(a[2], test_vec[i].a[2]);
    simde_assert_equal_u32(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    uint32_t a[4];
    simde_uint32x2x4_t val = simde_test_arm_neon_random_u32x2x4();
    const int lane = lanes[i];
    simde_vst4_lane_u32(a, val, lane);

    simde_test_codegen_write_vu32(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[4];
    uint64_t val[4][1];
  } test_vec[] = {
    { { UINT64_C( 6170604279074668508), UINT64_C(18254115969575623263), UINT64_C(10738215892683015460), UINT64_C(16557381817995811049) },
        { { UINT64_C( 6170604279074668508) },
          { UINT64_C(18254115969575623263) },
          { UINT64_C(10738215892683015460) },
          { UINT64_C(16557381817995811049) } },
    },
    { { UINT64_C( 5340864450959017954), UINT64_C( 4568942617375634857), UINT64_C(17615055932985392234), UINT64_C( 2307711346325363480) },
        { { UINT64_C( 5340864450959017954) },
          { UINT64_C( 4568942617375634857) },
          { UINT64_C(17615055932985392234) },
          { UINT64_C( 2307711346325363480) } },
    }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1x4_t val = {{simde_vld1_u64(test_vec[i].val[0]),
                              simde_vld1_u64(test_vec[i].val[1]),
                              simde_vld1_u64(test_vec[i].val[2]),
                              simde_vld1_u64(test_vec[i].val[3])}};
    uint64_t a[4];
    simde_vst4_lane_u64(a, val, 0);

    simde_assert_equal_u64(a[0], test_vec[i].a[0]);
    simde_assert_equal_u64(a[1], test_vec[i].a[1]);
    simde_assert_equal_u64(a[2], test_vec[i].a[2]);
    simde_assert_equal_u64(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    uint64_t a[4];
    simde_uint64x1x4_t val = simde_test_arm_neon_random_u64x1x4();
    simde_vst4_lane_u64(a, val, 0);

    simde_test_codegen_write_vu64(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t val[4][2];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -16.19), SIMDE_FLOAT32_C(    92.30), SIMDE_FLOAT32_C(    70.06), SIMDE_FLOAT32_C(   -85.19) },
        { { SIMDE_FLOAT32_C(   -16.19), SIMDE_FLOAT32_C(    32.21) },
          { SIMDE_FLOAT32_C(    92.30), SIMDE_FLOAT32_C(    25.96) },
          { SIMDE_FLOAT32_C(    70.06), SIMDE_FLOAT32_C(   -58.97) },
          { SIMDE_FLOAT32_C(   -85.19), SIMDE_FLOAT32_C(    94.51) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT32_C(   -43.37), SIMDE_FLOAT32_C(     8.08), SIMDE_FLOAT32_C(   -14.46), SIMDE_FLOAT32_C(   -35.49) },
        { { SIMDE_FLOAT32_C(    73.37), SIMDE_FLOAT32_C(   -43.37) },
          { SIMDE_FLOAT32_C(   -77.70), SIMDE_FLOAT32_C(     8.08) },
          { SIMDE_FLOAT32_C(    69.71), SIMDE_FLOAT32_C(   -14.46) },
          { SIMDE_FLOAT32_C(   -36.48), SIMDE_FLOAT32_C(   -35.49) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2x4_t val = {{simde_vld1_f32(test_vec[i].val[0]),
                               simde_vld1_f32(test_vec[i].val[1]),
                               simde_vld1_f32(test_vec[i].val[2]),
                               simde_vld1_f32(test_vec[i].val[3])}};
    simde_float32_t a[4];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst4_lane_f32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_f32(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f32(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f32(a[2], test_vec[i].a[2], 1);
    simde_assert_equal_f32(a[3], test_vec[i].a[3], 1);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32_t a[4];
    simde_float32x2x4_t val = simde_test_arm_neon_random_f32x2x4(-100.0f, 100.0f);
    const int lane = lanes[i];
    simde_vst4_lane_f32(a, val, lane);

    simde_test_codegen_write_vf32(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[4];
    simde_float64_t val[4][1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -82.99), SIMDE_FLOAT64_C(   -60.99), SIMDE_FLOAT64_C(    50.39), SIMDE_FLOAT64_C(   -86.91) },
        { { SIMDE_FLOAT64_C(   -82.99) },
          { SIMDE_FLOAT64_C(   -60.99) },
          { SIMDE_FLOAT64_C(    50.39) },
          { SIMDE_FLOAT64_C(   -86.91) } },
    },
    { { SIMDE_FLOAT64_C(    -7.34), SIMDE_FLOAT64_C(    34.75), SIMDE_FLOAT64_C(   -85.55), SIMDE_FLOAT64_C(    68.92) },
        { { SIMDE_FLOAT64_C(    -7.34) },
          { SIMDE_FLOAT64_C(    34.75) },
          { SIMDE_FLOAT64_C(   -85.55) },
          { SIMDE_FLOAT64_C(    68.92) } },
    }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1x4_t val = {{simde_vld1_f64(test_vec[i].val[0]),
                              simde_vld1_f64(test_vec[i].val[1]),
                              simde_vld1_f64(test_vec[i].val[2]),
                              simde_vld1_f64(test_vec[i].val[3])}};
    simde_float64_t a[4];
    simde_vst4_lane_f64(a, val, 0);

    simde_assert_equal_f64(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f64(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f64(a[2], test_vec[i].a[2], 1);
    simde_assert_equal_f64(a[3], test_vec[i].a[3], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64_t a[4];
    simde_float64x1x4_t val = simde_test_arm_neon_random_f64x1x4(-100.0, 100.0);
    simde_vst4_lane_f64(a, val, 0);

    simde_test_codegen_write_vf64(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[4];
    int8_t val[4][16];
    int lane;
  } test_vec[] = {
    { {  INT8_C(  72), -INT8_C(  88), -INT8_C(  65), -INT8_C( 103) },
       { {  INT8_C(  72), -INT8_C( 124), -INT8_C(  24),  INT8_C(  26), -INT8_C(  18), -INT8_C(  92), -INT8_C(   1), -INT8_C(  41),
            INT8_C(  49),  INT8_C(  87), -INT8_C(   4), -INT8_C(  53),  INT8_C( 116),  INT8_C(  32), -INT8_C(   9), -INT8_C( 124) },
         { -INT8_C(  88),  INT8_C( 102), -INT8_C( 115),  INT8_C(  25),  INT8_C(  66), -INT8_C(  42), -INT8_C(  91),  INT8_C(  56),
            INT8_C( 109), -INT8_C(  46), -INT8_C(  51), -INT8_C(  18), -INT8_C(  82),  INT8_C(  58), -INT8_C(  78), -INT8_C(  10) },
         { -INT8_C(  65), -INT8_C( 102),  INT8_C(  16), -INT8_C(  83),  INT8_C(  63),  INT8_C(  16), -INT8_C( 124),  INT8_C( 112),
            INT8_C( 103), -INT8_C( 127),  INT8_C(  59), -INT8_C(  37), -INT8_C(  95),  INT8_C(  50),  INT8_C(  95),  INT8_C(  73) },
         { -INT8_C( 103), -INT8_C(  19),  INT8_C(  99), -INT8_C(  37), -INT8_C(  61),  INT8_C(   8),  INT8_C(  19),  INT8_C(  48),
           -INT8_C(  38), -INT8_C(  32),  INT8_C(  30), -INT8_C( 119),  INT8_C(  27), -INT8_C(  48),      INT8_MAX, -INT8_C(  38) } },
      INT32_C(           0) },
   { { -INT8_C( 112), -INT8_C(  38),  INT8_C( 108),  INT8_C(  57) },
       { {  INT8_C( 106), -INT8_C( 112), -INT8_C( 121), -INT8_C(  87), -INT8_C(  96),  INT8_C(  11),  INT8_C(  26),  INT8_C(   7),
           -INT8_C( 116),  INT8_C(  85), -INT8_C(  29),  INT8_C(  46), -INT8_C( 120),  INT8_C(  66),  INT8_C( 119),  INT8_C(  33) },
         {  INT8_C(  47), -INT8_C(  38), -INT8_C(   4), -INT8_C(  14), -INT8_C(  30),  INT8_C(  16),  INT8_C(  34), -INT8_C(  67),
           -INT8_C(  16),  INT8_C(  64),  INT8_C(  70),  INT8_C(  11),  INT8_C(  16), -INT8_C(  59), -INT8_C(  27),  INT8_C( 123) },
         {  INT8_C(  85),  INT8_C( 108),  INT8_C(  36), -INT8_C(  11),  INT8_C( 120),  INT8_C(  62), -INT8_C(   3),  INT8_C(   4),
           -INT8_C( 108), -INT8_C(  32),  INT8_C(  50),  INT8_C(  28),  INT8_C(  34), -INT8_C(  86),  INT8_C(  61),  INT8_C(  82) },
         { -INT8_C( 124),  INT8_C(  57),  INT8_C(  68),  INT8_C( 103),  INT8_C(  73),  INT8_C( 103),  INT8_C(  36),  INT8_C(  58),
           -INT8_C(  89),  INT8_C( 106),  INT8_C(  69), -INT8_C(  72),  INT8_C(  47),  INT8_C(  43),  INT8_C(  51), -INT8_C( 123) } },
      INT32_C(           1) },
   { {  INT8_C( 122), -INT8_C(  36),  INT8_C(  87), -INT8_C(  83) },
       { { -INT8_C( 105),  INT8_C(  87),  INT8_C( 122),  INT8_C(  15), -INT8_C( 106),  INT8_C( 119),  INT8_C(  20),  INT8_C(  42),
            INT8_C(  87),  INT8_C(  70),  INT8_C(  70),  INT8_C( 122), -INT8_C(  16), -INT8_C( 125), -INT8_C(  52),  INT8_C( 117) },
         { -INT8_C(  68),  INT8_C(  16), -INT8_C(  36),  INT8_C(   6),  INT8_C( 119),  INT8_C(   0),  INT8_C(  64),  INT8_C(  31),
            INT8_C( 106), -INT8_C( 123), -INT8_C(  41), -INT8_C( 103), -INT8_C(  80),  INT8_C(  10),  INT8_C(  30),  INT8_C(  72) },
         {  INT8_C(  97), -INT8_C( 103),  INT8_C(  87), -INT8_C(   9),  INT8_C(  16),  INT8_C( 107),  INT8_C(  33),  INT8_C( 104),
           -INT8_C(  78),  INT8_C( 103), -INT8_C(  30), -INT8_C(  94), -INT8_C(  22), -INT8_C(  82),  INT8_C(  23), -INT8_C(  89) },
         { -INT8_C(  66), -INT8_C(  13), -INT8_C(  83),  INT8_C(  54), -INT8_C(  13), -INT8_C(  19),  INT8_C(  85),  INT8_C(  93),
            INT8_C( 114),  INT8_C(  44), -INT8_C(   9),  INT8_C(  35),  INT8_C(  54),  INT8_C(  21),  INT8_C( 107), -INT8_C( 105) } },
      INT32_C(           2) },
   { { -INT8_C(  65), -INT8_C( 127),  INT8_C(  52), -INT8_C( 105) },
       { { -INT8_C(  82), -INT8_C(  62), -INT8_C( 113), -INT8_C(  65),  INT8_C(  46), -INT8_C(  80),  INT8_C(  39), -INT8_C(  32),
            INT8_C(  24),  INT8_C(   9), -INT8_C( 126),  INT8_C(   2), -INT8_C(  73), -INT8_C( 102), -INT8_C(  87),  INT8_C( 117) },
         { -INT8_C( 115),  INT8_C(  86), -INT8_C(  85), -INT8_C( 127),  INT8_C(  67),  INT8_C(   0), -INT8_C(  34), -INT8_C(  74),
            INT8_C(  44), -INT8_C(  43), -INT8_C(  39),  INT8_C(  98), -INT8_C(  21),  INT8_C(  68), -INT8_C(   6), -INT8_C( 103) },
         {  INT8_C(   6), -INT8_C( 119),  INT8_C(  88),  INT8_C(  52),  INT8_C(  57),      INT8_MAX,  INT8_C(  20),  INT8_C(  81),
           -INT8_C( 120), -INT8_C( 105),  INT8_C(  84),  INT8_C(  63),  INT8_C(  49), -INT8_C(   3), -INT8_C(  75), -INT8_C(  66) },
         {  INT8_C(  84),  INT8_C(  96),  INT8_C(  63), -INT8_C( 105),  INT8_C(  97),  INT8_C(  30),  INT8_C(  77), -INT8_C( 115),
           -INT8_C(  13),  INT8_C(  38), -INT8_C(  16), -INT8_C(  34),  INT8_C( 106), -INT8_C(  22),  INT8_C( 120),  INT8_C( 113) } },
      INT32_C(           3) },
   { {  INT8_C(  80), -INT8_C(  98), -INT8_C(  22),  INT8_C(  28) },
       { {  INT8_C( 115), -INT8_C(  48), -INT8_C(  91), -INT8_C(  84),  INT8_C(  80), -INT8_C(  70), -INT8_C(   2), -INT8_C(  40),
            INT8_C(  81),  INT8_C(  82),  INT8_C(  24), -INT8_C( 126),  INT8_C(  79), -INT8_C(  51),  INT8_C(  64), -INT8_C(  93) },
         {  INT8_C(  45),      INT8_MIN,  INT8_C(  59), -INT8_C( 114), -INT8_C(  98), -INT8_C( 120),  INT8_C(  28), -INT8_C( 111),
           -INT8_C(  81),  INT8_C(  12),  INT8_C( 112),  INT8_C(  25), -INT8_C(  10), -INT8_C(  24), -INT8_C( 118),  INT8_C( 105) },
         { -INT8_C(  72),  INT8_C(  48),  INT8_C(  21),  INT8_C(   8), -INT8_C(  22),  INT8_C(  19), -INT8_C(  31),  INT8_C(  59),
            INT8_C( 101), -INT8_C(   7), -INT8_C(  67), -INT8_C(  75), -INT8_C(  58), -INT8_C(   3),  INT8_C(  88), -INT8_C(  13) },
         {  INT8_C( 125), -INT8_C( 109), -INT8_C( 126),  INT8_C(  27),  INT8_C(  28), -INT8_C(  98), -INT8_C(  83), -INT8_C(  53),
           -INT8_C(  86),  INT8_C(  29), -INT8_C(  28), -INT8_C(  96),  INT8_C(   5),  INT8_C( 111),  INT8_C(   9), -INT8_C(  67) } },
      INT32_C(           4) },
   { { -INT8_C(  89), -INT8_C(  60),  INT8_C(  95),  INT8_C(  82) },
       { { -INT8_C(  97),  INT8_C(  30), -INT8_C(  58), -INT8_C( 119),  INT8_C(  50), -INT8_C(  89), -INT8_C(  60), -INT8_C( 105),
           -INT8_C(  96), -INT8_C( 127),  INT8_C(  76),  INT8_C( 102),  INT8_C( 126), -INT8_C(  91),  INT8_C(  89), -INT8_C(   4) },
         {  INT8_C(  56), -INT8_C(  37),  INT8_C(  23),  INT8_C(  84),  INT8_C( 121), -INT8_C(  60),  INT8_C(  31),  INT8_C(  35),
           -INT8_C(  31),  INT8_C(   4), -INT8_C(  61), -INT8_C(  26),  INT8_C( 115), -INT8_C(  52), -INT8_C(  92),  INT8_C(  18) },
         { -INT8_C(  21),  INT8_C( 106), -INT8_C( 101),  INT8_C(  29),  INT8_C(  17),  INT8_C(  95), -INT8_C(  76), -INT8_C(  79),
           -INT8_C(  32),  INT8_C(   1),  INT8_C(  23),  INT8_C(  94), -INT8_C(  90),  INT8_C( 112),  INT8_C(  90), -INT8_C(  34) },
         {  INT8_C(  76),  INT8_C( 114),  INT8_C(  51), -INT8_C(  59),  INT8_C(  54),  INT8_C(  82), -INT8_C(  23),  INT8_C(  24),
            INT8_C(  86), -INT8_C(  84), -INT8_C(   2), -INT8_C(  55),  INT8_C( 121), -INT8_C(  94), -INT8_C(  37),  INT8_C( 100) } },
      INT32_C(           5) },
   { { -INT8_C(  50),  INT8_C(  47),  INT8_C(  61),  INT8_C(  36) },
       { {  INT8_C(  12),  INT8_C( 118), -INT8_C( 127),  INT8_C(  29), -INT8_C(  43),  INT8_C(  53), -INT8_C(  50), -INT8_C(  75),
            INT8_C(  54), -INT8_C(  27),  INT8_C(  20), -INT8_C(  36),  INT8_C(  86),  INT8_C( 110), -INT8_C(  69), -INT8_C(  94) },
         { -INT8_C(  32), -INT8_C(  18),  INT8_C( 103),  INT8_C(  23),  INT8_C(  64),  INT8_C(  80),  INT8_C(  47), -INT8_C( 105),
           -INT8_C(   3),  INT8_C(  45),  INT8_C(  96),  INT8_C( 118), -INT8_C(  48),  INT8_C(  60), -INT8_C(  38), -INT8_C(  36) },
         { -INT8_C(  78),  INT8_C(  91), -INT8_C(   6), -INT8_C( 120), -INT8_C( 112), -INT8_C(  56),  INT8_C(  61), -INT8_C(  57),
           -INT8_C(  82),  INT8_C(  81), -INT8_C(  93),  INT8_C(   4), -INT8_C(  64),  INT8_C(  94), -INT8_C(  90), -INT8_C(  96) },
         {  INT8_C(  76),  INT8_C(  13), -INT8_C(  73), -INT8_C( 115),  INT8_C(  94), -INT8_C(  26),  INT8_C(  36),  INT8_C(  91),
            INT8_C(  20), -INT8_C( 124), -INT8_C(  47), -INT8_C(  28), -INT8_C(  64), -INT8_C(  85), -INT8_C(  64),  INT8_C( 115) } },
      INT32_C(           6) },
   { {  INT8_C(  49), -INT8_C( 100), -INT8_C(  46), -INT8_C( 101) },
       { {  INT8_C(   6), -INT8_C(  70), -INT8_C(   5), -INT8_C( 106), -INT8_C( 125),  INT8_C(  56),  INT8_C(  93),  INT8_C(  49),
           -INT8_C( 118),  INT8_C(   1),  INT8_C(  53),  INT8_C(  74),  INT8_C(  95), -INT8_C(  37), -INT8_C(  22), -INT8_C(  84) },
         { -INT8_C(  24), -INT8_C(  94),  INT8_C(  57),  INT8_C(  70), -INT8_C( 120),  INT8_C(  93), -INT8_C(  95), -INT8_C( 100),
           -INT8_C(  31),  INT8_C( 114),      INT8_MIN, -INT8_C(  94),  INT8_C(  29),  INT8_C(  65),  INT8_C(  21),  INT8_C(  35) },
         { -INT8_C(   5),  INT8_C(  16), -INT8_C(  70),  INT8_C( 126),  INT8_C(  72),  INT8_C(  23), -INT8_C(  81), -INT8_C(  46),
            INT8_C(  24), -INT8_C(  28),  INT8_C(  28),  INT8_C( 120), -INT8_C(  65),  INT8_C(   7),  INT8_C(  36), -INT8_C(  88) },
         { -INT8_C(  87),  INT8_C(  93), -INT8_C(  18),  INT8_C(  49), -INT8_C(  70), -INT8_C( 112), -INT8_C(  50), -INT8_C( 101),
            INT8_C(   2),  INT8_C(  78),  INT8_C(  61),  INT8_C(  32), -INT8_C( 113),  INT8_C(  82),  INT8_C(  67), -INT8_C( 117) } },
      INT32_C(           7) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16x4_t val = {{simde_vld1q_s8(test_vec[i].val[0]),
                             simde_vld1q_s8(test_vec[i].val[1]),
                             simde_vld1q_s8(test_vec[i].val[2]),
                             simde_vld1q_s8(test_vec[i].val[3])}};
    int8_t a[4];
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst4q_lane_s8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i8(a[0], test_vec[i].a[0]);
    simde_assert_equal_i8(a[1], test_vec[i].a[1]);
    simde_assert_equal_i8(a[2], test_vec[i].a[2]);
    simde_assert_equal_i8(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a[4];
    simde_int8x16x4_t val = simde_test_arm_neon_random_i8x16x4();
    const int lane = lanes[i];
    simde_vst4q_lane_s8(a, val, lane);

    simde_test_codegen_write_vi8(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t val[4][8];
    int lane;
  } test_vec[] = {
    { { -INT16_C( 19815),  INT16_C( 24653), -INT16_C( 25090), -INT16_C(  1059) },
        { { -INT16_C( 19815), -INT16_C( 21425), -INT16_C( 11505), -INT16_C( 22482),  INT16_C( 29953),  INT16_C( 10173), -INT16_C( 14075), -INT16_C( 27421) },
          {  INT16_C( 24653), -INT16_C( 30984),  INT16_C( 30192), -INT16_C(  9286), -INT16_C(  7138),  INT16_C( 30977),  INT16_C( 19584),  INT16_C(  6734) },
          { -INT16_C( 25090),  INT16_C(  3526), -INT16_C(  2703),  INT16_C( 29365),  INT16_C( 29546),  INT16_C( 28569),  INT16_C( 32060), -INT16_C( 30461) },
          { -INT16_C(  1059), -INT16_C( 13040), -INT16_C( 13712), -INT16_C( 29016), -INT16_C( 22097),  INT16_C( 12040),  INT16_C( 22261), -INT16_C(  3255) } },
       INT32_C(           0) },
    { {  INT16_C( 25857),  INT16_C( 20120),  INT16_C(  1684), -INT16_C( 11932) },
        { {  INT16_C(  4340),  INT16_C( 25857), -INT16_C( 18939),  INT16_C( 28631),  INT16_C( 28969),  INT16_C( 26079), -INT16_C(  7442), -INT16_C( 13329) },
          { -INT16_C(    34),  INT16_C( 20120),  INT16_C( 16585),  INT16_C( 30941), -INT16_C(  6678), -INT16_C(  8280), -INT16_C(  3781),  INT16_C( 12243) },
          { -INT16_C( 11263),  INT16_C(  1684),  INT16_C( 27786), -INT16_C( 19338),  INT16_C( 21981), -INT16_C( 13543),  INT16_C(  2103),  INT16_C(  5526) },
          {  INT16_C( 11783), -INT16_C( 11932),  INT16_C( 16750),  INT16_C( 22601), -INT16_C(  3802),  INT16_C( 24888),  INT16_C(  3043), -INT16_C(  7023) } },
       INT32_C(           1) },
    { {  INT16_C( 24977),  INT16_C( 25000),  INT16_C( 28006),  INT16_C(  7588) },
        { {  INT16_C(  9695),  INT16_C( 27115),  INT16_C( 24977),  INT16_C( 28189),  INT16_C( 14262), -INT16_C(  4807), -INT16_C( 12481),  INT16_C( 18179) },
          {  INT16_C( 26621),  INT16_C( 27672),  INT16_C( 25000), -INT16_C( 12604), -INT16_C(   941),  INT16_C( 13871), -INT16_C( 16377), -INT16_C(  6630) },
          {  INT16_C(  1510),  INT16_C( 30544),  INT16_C( 28006),  INT16_C(  7398),  INT16_C(  8100), -INT16_C(  7158),  INT16_C(  3567), -INT16_C(  5077) },
          {  INT16_C( 17268),  INT16_C(  7256),  INT16_C(  7588), -INT16_C(  2070),  INT16_C(  6425),  INT16_C(  8493),  INT16_C( 18650), -INT16_C( 16377) } },
       INT32_C(           2) },
    { {  INT16_C( 27088), -INT16_C( 22697), -INT16_C( 22698),  INT16_C(  4242) },
        { {  INT16_C( 22349), -INT16_C( 19401),  INT16_C(  7621),  INT16_C( 27088), -INT16_C(  9667),  INT16_C( 11341),  INT16_C( 30951),  INT16_C( 23320) },
          {  INT16_C( 29115),  INT16_C( 24695),  INT16_C( 24974), -INT16_C( 22697), -INT16_C( 31365),  INT16_C( 21960), -INT16_C( 12083),  INT16_C(  6677) },
          {  INT16_C( 19495), -INT16_C(  4914), -INT16_C( 24726), -INT16_C( 22698), -INT16_C( 23687),  INT16_C( 25043), -INT16_C(  5348), -INT16_C( 10308) },
          {  INT16_C( 13404), -INT16_C(  5577), -INT16_C( 28779),  INT16_C(  4242),  INT16_C( 23060), -INT16_C(  7835),  INT16_C( 31274),  INT16_C( 21243) } },
       INT32_C(           3) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8x4_t val = {{simde_vld1q_s16(test_vec[i].val[0]),
                              simde_vld1q_s16(test_vec[i].val[1]),
                              simde_vld1q_s16(test_vec[i].val[2]),
                              simde_vld1q_s16(test_vec[i].val[3])}};
    int16_t a[4];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst4q_lane_s16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i16(a[0], test_vec[i].a[0]);
    simde_assert_equal_i16(a[1], test_vec[i].a[1]);
    simde_assert_equal_i16(a[2], test_vec[i].a[2]);
    simde_assert_equal_i16(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    int16_t a[4];
    simde_int16x8x4_t val = simde_test_arm_neon_random_i16x8x4();
    const int lane = lanes[i];
    simde_vst4q_lane_s16(a, val, lane);

    simde_test_codegen_write_vi16(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t val[4][4];
    int lane;
  } test_vec[] = {
    { { -INT32_C(  1902356739),  INT32_C(   958496514),  INT32_C(   830509708), -INT32_C(   426005928) },
        { { -INT32_C(  1902356739), -INT32_C(    17984603), -INT32_C(   714356581), -INT32_C(  1555839569) },
          {  INT32_C(   958496514), -INT32_C(  1199212659), -INT32_C(   427306686), -INT32_C(   218810635) },
          {  INT32_C(   830509708), -INT32_C(  1070568155), -INT32_C(   443114698),  INT32_C(  1653135712) },
          { -INT32_C(   426005928),  INT32_C(  1671307297), -INT32_C(   431348239), -INT32_C(   405192869) } },
       INT32_C(           0) },
    { { -INT32_C(    38319929),  INT32_C(  1385825120), -INT32_C(  1372609589),  INT32_C(   646603518) },
        { { -INT32_C(   149399087), -INT32_C(    38319929),  INT32_C(  1138904547),  INT32_C(  2141547302) },
          {  INT32_C(   912605205),  INT32_C(  1385825120), -INT32_C(  2093423576), -INT32_C(   177598173) },
          {  INT32_C(   854360683), -INT32_C(  1372609589),  INT32_C(   401740273), -INT32_C(  1852401796) },
          {  INT32_C(   952695768),  INT32_C(   646603518),  INT32_C(  1772733254),  INT32_C(  1063130068) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4x4_t val = {{simde_vld1q_s32(test_vec[i].val[0]),
                              simde_vld1q_s32(test_vec[i].val[1]),
                              simde_vld1q_s32(test_vec[i].val[2]),
                              simde_vld1q_s32(test_vec[i].val[3])}};
    int32_t a[4];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst4q_lane_s32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i32(a[0], test_vec[i].a[0]);
    simde_assert_equal_i32(a[1], test_vec[i].a[1]);
    simde_assert_equal_i32(a[2], test_vec[i].a[2]);
    simde_assert_equal_i32(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a[4];
    simde_int32x4x4_t val = simde_test_arm_neon_random_i32x4x4();
    const int lane = lanes[i];
    simde_vst4q_lane_s32(a, val, lane);

    simde_test_codegen_write_vi32(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[4];
    int64_t val[4][2];
    int lane;
  } test_vec[] = {
    { { -INT64_C( 2048554574392611208),  INT64_C( 3276738228486001043), -INT64_C( 2385288397935753845),  INT64_C( 4275333102794866202) },
        { { -INT64_C( 2048554574392611208),  INT64_C( 4596242182005963783) },
          {  INT64_C( 3276738228486001043),  INT64_C( 5436651599519402349) },
          { -INT64_C( 2385288397935753845), -INT64_C( 4853393685083125892) },
          {  INT64_C( 4275333102794866202), -INT64_C( 6345595945497379119) } },
       INT32_C(           0) },
    { {  INT64_C( 5078480573643547542), -INT64_C(  232649732142963966), -INT64_C( 3657823483509700406),  INT64_C( 6491469122710229196) },
        { {  INT64_C( 6441431548656426415),  INT64_C( 5078480573643547542) },
          { -INT64_C( 2095365621357344287), -INT64_C(  232649732142963966) },
          { -INT64_C( 7797446204114964845), -INT64_C( 3657823483509700406) },
          {  INT64_C( 8199199426422352853),  INT64_C( 6491469122710229196) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2x4_t val = {{simde_vld1q_s64(test_vec[i].val[0]),
                              simde_vld1q_s64(test_vec[i].val[1]),
                              simde_vld1q_s64(test_vec[i].val[2]),
                              simde_vld1q_s64(test_vec[i].val[3])}};
    int64_t a[4];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst4q_lane_s64, HEDLEY_UNREACHABLE(), test_vec[i].lane, a, val);

    simde_assert_equal_i64(a[0], test_vec[i].a[0]);
    simde_assert_equal_i64(a[1], test_vec[i].a[1]);
    simde_assert_equal_i64(a[2], test_vec[i].a[2]);
    simde_assert_equal_i64(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    int64_t a[4];
    simde_int64x2x4_t val = simde_test_arm_neon_random_i64x2x4();
    simde_vst4q_lane_s64(a, val, i);

    simde_test_codegen_write_vi64(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[4];
    uint8_t val[4][16];
    int lane;
  } test_vec[] = {
    { { UINT8_C(222), UINT8_C(183), UINT8_C(129), UINT8_C(116) },
        { { UINT8_C(222), UINT8_C(187), UINT8_C( 47), UINT8_C(139), UINT8_C(158), UINT8_C(226), UINT8_C(216), UINT8_C( 91),
            UINT8_C(215), UINT8_C( 48), UINT8_C( 38), UINT8_C(226), UINT8_C(124), UINT8_C( 36), UINT8_C( 29), UINT8_C(  1) },
          { UINT8_C(183), UINT8_C(213), UINT8_C(130), UINT8_C( 43), UINT8_C(153), UINT8_C( 77), UINT8_C( 94), UINT8_C( 75),
            UINT8_C( 87), UINT8_C( 10), UINT8_C(246), UINT8_C(176), UINT8_C( 69), UINT8_C(198), UINT8_C(182), UINT8_C( 36) },
          { UINT8_C(129), UINT8_C(230), UINT8_C(175), UINT8_C( 32), UINT8_C(200), UINT8_C(135), UINT8_C(123), UINT8_C(159),
            UINT8_C(184), UINT8_C(161), UINT8_C(129), UINT8_C( 52), UINT8_C(197), UINT8_C(158), UINT8_C( 53), UINT8_C(124) },
          { UINT8_C(116), UINT8_C(183), UINT8_C(167), UINT8_C( 13), UINT8_C(  4), UINT8_C(  6), UINT8_C( 88), UINT8_C( 92),
            UINT8_C( 16), UINT8_C( 78), UINT8_C( 12), UINT8_C( 86), UINT8_C( 20), UINT8_C(194), UINT8_C(122), UINT8_C(149) } },
       INT32_C(           0) },
    { { UINT8_C( 41), UINT8_C(186), UINT8_C(182), UINT8_C(252) },
        { { UINT8_C(168), UINT8_C( 41), UINT8_C(181), UINT8_C(113), UINT8_C(177), UINT8_C( 48), UINT8_C( 16), UINT8_C(105),
            UINT8_C(209), UINT8_C(146), UINT8_C(157), UINT8_C(150), UINT8_C( 48), UINT8_C(211), UINT8_C( 19), UINT8_C(164) },
          { UINT8_C(138), UINT8_C(186), UINT8_C(177), UINT8_C(143), UINT8_C(192), UINT8_C(  9), UINT8_C(235), UINT8_C(209),
            UINT8_C( 87), UINT8_C(247), UINT8_C( 39), UINT8_C(107), UINT8_C(185), UINT8_C(161), UINT8_C(  1), UINT8_C( 98) },
          { UINT8_C(202), UINT8_C(182), UINT8_C(211), UINT8_C(123), UINT8_C(231), UINT8_C(227), UINT8_C(228), UINT8_C(184),
            UINT8_C(117), UINT8_C(130), UINT8_C( 79), UINT8_C(166), UINT8_C( 85), UINT8_C( 98), UINT8_C( 74), UINT8_C(223) },
          { UINT8_C( 28), UINT8_C(252), UINT8_C(110), UINT8_C(221), UINT8_C(  5), UINT8_C( 89), UINT8_C(174), UINT8_C( 93),
            UINT8_C( 80), UINT8_C(213), UINT8_C(200), UINT8_C( 10), UINT8_C(118), UINT8_C(201), UINT8_C(108), UINT8_C( 64) } },
       INT32_C(           1) },
    { { UINT8_C(188), UINT8_C(202), UINT8_C( 96), UINT8_C(180) },
        { { UINT8_C(128), UINT8_C( 63), UINT8_C(188), UINT8_C(103), UINT8_C( 34), UINT8_C(160), UINT8_C( 31), UINT8_C(152),
            UINT8_C( 34), UINT8_C(110), UINT8_C( 62), UINT8_C(119), UINT8_C(208), UINT8_C(136), UINT8_C( 87), UINT8_C(237) },
          { UINT8_C(132), UINT8_C(197), UINT8_C(202), UINT8_C(138), UINT8_C( 31), UINT8_C(120), UINT8_C(231), UINT8_C(111),
            UINT8_C( 77), UINT8_C(175), UINT8_C(121), UINT8_C(195), UINT8_C(121), UINT8_C(229), UINT8_C(  3), UINT8_C(249) },
          { UINT8_C( 36), UINT8_C(191), UINT8_C( 96), UINT8_C( 71), UINT8_C( 96), UINT8_C(127), UINT8_C(223), UINT8_C(130),
            UINT8_C(238), UINT8_C( 29), UINT8_C(250), UINT8_C(190), UINT8_C(165), UINT8_C( 81), UINT8_C(171), UINT8_C( 42) },
          { UINT8_C( 22), UINT8_C(117), UINT8_C(180), UINT8_C( 53), UINT8_C(237), UINT8_C(155), UINT8_C(165), UINT8_C( 58),
            UINT8_C( 74), UINT8_C( 30), UINT8_C(253), UINT8_C(195), UINT8_C(  4), UINT8_C(  1), UINT8_C(188), UINT8_C( 40) } },
       INT32_C(           2) },
    { { UINT8_C( 32), UINT8_C( 87), UINT8_C( 13), UINT8_C( 24) },
        { { UINT8_C(192), UINT8_C( 28), UINT8_C(111), UINT8_C( 32), UINT8_C(156), UINT8_C( 78), UINT8_C(163), UINT8_C(138),
            UINT8_C(107), UINT8_C(157), UINT8_C( 72), UINT8_C( 17), UINT8_C(238), UINT8_C(244), UINT8_C( 59), UINT8_C(  4) },
          { UINT8_C(105), UINT8_C(239), UINT8_C( 58), UINT8_C( 87), UINT8_C(138), UINT8_C(223), UINT8_C(145), UINT8_C(212),
            UINT8_C(253), UINT8_C(143), UINT8_C(152), UINT8_C(  1), UINT8_C(144), UINT8_C( 84), UINT8_C( 42), UINT8_C( 80) },
          { UINT8_C(113), UINT8_C(153), UINT8_C(113), UINT8_C( 13), UINT8_C(232), UINT8_C( 20), UINT8_C(151), UINT8_C( 83),
            UINT8_C(177), UINT8_C(223), UINT8_C(100), UINT8_C(159), UINT8_C(211), UINT8_C(159), UINT8_C(163), UINT8_C( 61) },
          { UINT8_C(142), UINT8_C(221), UINT8_C(148), UINT8_C( 24), UINT8_C(188), UINT8_C( 37), UINT8_C(237), UINT8_C(186),
            UINT8_C(180), UINT8_C(133), UINT8_C(187), UINT8_C( 68), UINT8_C(217), UINT8_C(229), UINT8_C(149), UINT8_C( 74) } },
       INT32_C(           3) },
    { { UINT8_C( 26), UINT8_C(152), UINT8_C( 65), UINT8_C(133) },
        { { UINT8_C(127), UINT8_C(  6), UINT8_C( 87), UINT8_C(103), UINT8_C( 26), UINT8_C(238), UINT8_C(186), UINT8_C(203),
            UINT8_C(206), UINT8_C( 31), UINT8_C(106), UINT8_C(161), UINT8_C(190), UINT8_C( 13), UINT8_C(222), UINT8_C( 77) },
          { UINT8_C(235), UINT8_C(114), UINT8_C(101), UINT8_C(167), UINT8_C(152), UINT8_C( 82), UINT8_C( 97), UINT8_C( 76),
            UINT8_C(215), UINT8_C( 29), UINT8_C(145), UINT8_C(177), UINT8_C(  2), UINT8_C( 38), UINT8_C(251), UINT8_C(129) },
          { UINT8_C( 44), UINT8_C( 83), UINT8_C(232), UINT8_C( 70), UINT8_C( 65), UINT8_C(163), UINT8_C( 17), UINT8_C( 15),
            UINT8_C(194), UINT8_C(123), UINT8_C(177), UINT8_C(128), UINT8_C(136), UINT8_C(143), UINT8_C(205), UINT8_C(115) },
          { UINT8_C(  2), UINT8_C( 51), UINT8_C( 27), UINT8_C(154), UINT8_C(133), UINT8_C(124), UINT8_C(230), UINT8_C( 93),
            UINT8_C(153), UINT8_C(119), UINT8_C( 14), UINT8_C(156), UINT8_C(157), UINT8_C(  9), UINT8_C( 29), UINT8_C(201) } },
       INT32_C(           4) },
    { { UINT8_C( 32), UINT8_C(112), UINT8_C(142), UINT8_C(108) },
        { { UINT8_C( 92), UINT8_C(  6), UINT8_C( 15), UINT8_C(158), UINT8_C(169), UINT8_C( 32), UINT8_C(173), UINT8_C(107),
            UINT8_C(155), UINT8_C( 94), UINT8_C(235), UINT8_C( 36), UINT8_C(238), UINT8_C(185), UINT8_C(151), UINT8_C(240) },
          { UINT8_C(236), UINT8_C(178), UINT8_C(138), UINT8_C(113), UINT8_C( 47), UINT8_C(112), UINT8_C(206), UINT8_C(200),
            UINT8_C(232), UINT8_C(220), UINT8_C(100), UINT8_C(133), UINT8_C(230), UINT8_C(130), UINT8_C( 79), UINT8_C( 66) },
          { UINT8_C(136), UINT8_C( 94), UINT8_C(224), UINT8_C( 49), UINT8_C(127), UINT8_C(142), UINT8_C(156), UINT8_C( 26),
            UINT8_C(236), UINT8_C(135), UINT8_C( 62), UINT8_C(218), UINT8_C( 64), UINT8_C(214), UINT8_C(202), UINT8_C( 44) },
          { UINT8_C(136), UINT8_C( 84), UINT8_C(158), UINT8_C(183), UINT8_C(197), UINT8_C(108), UINT8_C(128), UINT8_C(173),
            UINT8_C( 73), UINT8_C(228), UINT8_C( 50), UINT8_C( 47), UINT8_C(102), UINT8_C(129), UINT8_C(113), UINT8_C(238) } },
       INT32_C(           5) },
    { { UINT8_C(121), UINT8_C( 56), UINT8_C(162), UINT8_C(229) },
        { { UINT8_C(224), UINT8_C( 82), UINT8_C( 31), UINT8_C( 95), UINT8_C(224), UINT8_C(187), UINT8_C(121), UINT8_C(204),
            UINT8_C( 67), UINT8_C(184), UINT8_C(167), UINT8_C(131), UINT8_C(142), UINT8_C(113), UINT8_C(176), UINT8_C( 22) },
          { UINT8_C(198), UINT8_C( 78), UINT8_C(206), UINT8_C(139), UINT8_C(186), UINT8_C( 78), UINT8_C( 56), UINT8_C(  3),
            UINT8_C( 50), UINT8_C(106), UINT8_C( 50), UINT8_C(153), UINT8_C(236), UINT8_C(164), UINT8_C(135), UINT8_C(204) },
          { UINT8_C(246), UINT8_C(167), UINT8_C( 43), UINT8_C(214), UINT8_C( 98), UINT8_C(164), UINT8_C(162), UINT8_C(165),
            UINT8_C( 92), UINT8_C( 73), UINT8_C( 41), UINT8_C(234), UINT8_C(187), UINT8_C(217), UINT8_C(  1), UINT8_C(129) },
          { UINT8_C( 39), UINT8_C(207), UINT8_C( 12), UINT8_C(225), UINT8_C( 29), UINT8_C( 68), UINT8_C(229), UINT8_C( 79),
            UINT8_C(174), UINT8_C( 23), UINT8_C(232), UINT8_C(154), UINT8_C(187), UINT8_C(112), UINT8_C(102), UINT8_C(177) } },
       INT32_C(           6) },
    { { UINT8_C(146), UINT8_C(174), UINT8_C(184), UINT8_C(208) },
        { { UINT8_C( 23), UINT8_C(145), UINT8_C(135), UINT8_C(121), UINT8_C( 54), UINT8_C( 42), UINT8_C( 31), UINT8_C(146),
            UINT8_C(115), UINT8_C( 72), UINT8_C(125), UINT8_C( 46), UINT8_C( 33), UINT8_C(126), UINT8_C(175), UINT8_C( 72) },
          { UINT8_C( 77), UINT8_C(187), UINT8_C( 41), UINT8_C(106),    UINT8_MAX, UINT8_C( 14), UINT8_C(185), UINT8_C(174),
            UINT8_C( 38), UINT8_C(162), UINT8_C( 72), UINT8_C(225), UINT8_C( 18), UINT8_C(175), UINT8_C(147), UINT8_C( 41) },
          { UINT8_C( 64), UINT8_C( 26), UINT8_C(162), UINT8_C(118), UINT8_C( 68), UINT8_C(193), UINT8_C(  9), UINT8_C(184),
            UINT8_C(  9), UINT8_C(134), UINT8_C(230), UINT8_C( 42), UINT8_C(  4), UINT8_C(150), UINT8_C(114), UINT8_C( 81) },
          { UINT8_C( 81), UINT8_C(156), UINT8_C(187), UINT8_C( 81), UINT8_C(170), UINT8_C(116),    UINT8_MAX, UINT8_C(208),
            UINT8_C( 22), UINT8_C( 71), UINT8_C(178), UINT8_C( 40), UINT8_C(246), UINT8_C( 69), UINT8_C( 81), UINT8_C( 55) } },
       INT32_C(           7) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16x4_t val = {{simde_vld1q_u8(test_vec[i].val[0]),
                             simde_vld1q_u8(test_vec[i].val[1]),
                             simde_vld1q_u8(test_vec[i].val[2]),
                             simde_vld1q_u8(test_vec[i].val[3])}};
    uint8_t a[4];
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst4q_lane_u8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u8(a[0], test_vec[i].a[0]);
    simde_assert_equal_u8(a[1], test_vec[i].a[1]);
    simde_assert_equal_u8(a[2], test_vec[i].a[2]);
    simde_assert_equal_u8(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a[4];
    simde_uint8x16x4_t val = simde_test_arm_neon_random_u8x16x4();
    const int lane = lanes[i];
    simde_vst4q_lane_u8(a, val, lane);

    simde_test_codegen_write_vu8(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t val[4][8];
    int lane;
  } test_vec[] = {
    { { UINT16_C(10421), UINT16_C( 9861), UINT16_C(26735), UINT16_C( 9701) },
        { { UINT16_C(10421), UINT16_C(55459), UINT16_C(32761), UINT16_C(14102), UINT16_C(52497), UINT16_C( 2686), UINT16_C( 2511), UINT16_C(39356) },
          { UINT16_C( 9861), UINT16_C(38256), UINT16_C(19027), UINT16_C(26625), UINT16_C(54884), UINT16_C(20210), UINT16_C(18139), UINT16_C(37061) },
          { UINT16_C(26735), UINT16_C(26728), UINT16_C(32743), UINT16_C(63647), UINT16_C( 7500), UINT16_C( 6914), UINT16_C(48934), UINT16_C(43957) },
          { UINT16_C( 9701), UINT16_C(14657), UINT16_C(17008), UINT16_C(54433), UINT16_C(37912), UINT16_C(62242), UINT16_C(59610), UINT16_C(18819) } },
       INT32_C(           0) },
    { { UINT16_C(14513), UINT16_C( 7440), UINT16_C(43396), UINT16_C(61572) },
        { { UINT16_C(60496), UINT16_C(14513), UINT16_C(20587), UINT16_C(46896), UINT16_C(13165), UINT16_C(38098), UINT16_C(34802), UINT16_C(55103) },
          { UINT16_C(32941), UINT16_C( 7440), UINT16_C(45763), UINT16_C(56305), UINT16_C( 5190), UINT16_C( 8399), UINT16_C(21244), UINT16_C(19562) },
          { UINT16_C( 6974), UINT16_C(43396), UINT16_C(46444), UINT16_C(55648), UINT16_C(13288), UINT16_C(55917), UINT16_C(44474), UINT16_C(26545) },
          { UINT16_C(49709), UINT16_C(61572), UINT16_C(30324), UINT16_C(47820), UINT16_C(39818), UINT16_C(34522), UINT16_C(17645), UINT16_C(11474) } },
       INT32_C(           1) },
    { { UINT16_C(13836), UINT16_C(43653), UINT16_C(24682), UINT16_C(29608) },
        { { UINT16_C(22368), UINT16_C(52437), UINT16_C(13836), UINT16_C(62629), UINT16_C( 4969), UINT16_C( 9166), UINT16_C(32704), UINT16_C(60811) },
          { UINT16_C( 3905), UINT16_C(46558), UINT16_C(43653), UINT16_C( 3951), UINT16_C(19013), UINT16_C(12949), UINT16_C(26766), UINT16_C(61022) },
          { UINT16_C(13503), UINT16_C(52154), UINT16_C(24682), UINT16_C(54207), UINT16_C(36211), UINT16_C(13302), UINT16_C(33036), UINT16_C(20000) },
          { UINT16_C(65169), UINT16_C( 5635), UINT16_C(29608), UINT16_C(60710), UINT16_C(48061), UINT16_C(19232), UINT16_C(32291), UINT16_C(57914) } },
       INT32_C(           2) },
    { { UINT16_C(51183), UINT16_C(34735), UINT16_C( 2589), UINT16_C(34573) },
        { { UINT16_C(62642), UINT16_C( 7341), UINT16_C(27732), UINT16_C(51183), UINT16_C(59129), UINT16_C( 1786), UINT16_C( 7015), UINT16_C(63572) },
          { UINT16_C(22297), UINT16_C(49679), UINT16_C(13770), UINT16_C(34735), UINT16_C(53232), UINT16_C( 5331), UINT16_C( 3406), UINT16_C(  246) },
          { UINT16_C(41985), UINT16_C(22045), UINT16_C( 3088), UINT16_C( 2589), UINT16_C( 6386), UINT16_C(23056), UINT16_C(25651), UINT16_C(19538) },
          { UINT16_C(25019), UINT16_C(34318), UINT16_C(48790), UINT16_C(34573), UINT16_C(57485), UINT16_C(56219), UINT16_C(37357), UINT16_C(61404) } },
       INT32_C(           3) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8x4_t val = {{simde_vld1q_u16(test_vec[i].val[0]),
                              simde_vld1q_u16(test_vec[i].val[1]),
                              simde_vld1q_u16(test_vec[i].val[2]),
                              simde_vld1q_u16(test_vec[i].val[3])}};
    uint16_t a[4];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst4q_lane_u16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u16(a[0], test_vec[i].a[0]);
    simde_assert_equal_u16(a[1], test_vec[i].a[1]);
    simde_assert_equal_u16(a[2], test_vec[i].a[2]);
    simde_assert_equal_u16(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    uint16_t a[4];
    simde_uint16x8x4_t val = simde_test_arm_neon_random_u16x8x4();
    const int lane = lanes[i];
    simde_vst4q_lane_u16(a, val, lane);

    simde_test_codegen_write_vu16(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t val[4][4];
    int lane;
  } test_vec[] = {
    { { UINT32_C(1233570076), UINT32_C(3802835575), UINT32_C(3471329323), UINT32_C(4106483564) },
        { { UINT32_C(1233570076), UINT32_C(1934700963), UINT32_C(3595718584), UINT32_C( 482006439) },
          { UINT32_C(3802835575), UINT32_C( 780617608), UINT32_C(2685710040), UINT32_C(2680316547) },
          { UINT32_C(3471329323), UINT32_C( 826358137), UINT32_C( 805868681), UINT32_C(3779969641) },
          { UINT32_C(4106483564), UINT32_C( 388188734), UINT32_C(2092382201), UINT32_C(3306912153) } },
       INT32_C(           0) },
    { { UINT32_C(3312244028), UINT32_C(3129981633), UINT32_C( 576072121), UINT32_C(3147551177) },
        { { UINT32_C( 999490497), UINT32_C(3312244028), UINT32_C(3539367017), UINT32_C(2746434358) },
          { UINT32_C(2023192378), UINT32_C(3129981633), UINT32_C(2335590386), UINT32_C(2186301888) },
          { UINT32_C(2445141076), UINT32_C( 576072121), UINT32_C(3572780190), UINT32_C(3380062351) },
          { UINT32_C(3762425631), UINT32_C(3147551177), UINT32_C(3645362456), UINT32_C(2002491171) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4x4_t val = {{simde_vld1q_u32(test_vec[i].val[0]),
                              simde_vld1q_u32(test_vec[i].val[1]),
                              simde_vld1q_u32(test_vec[i].val[2]),
                              simde_vld1q_u32(test_vec[i].val[3])}};
    uint32_t a[4];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst4q_lane_u32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u32(a[0], test_vec[i].a[0]);
    simde_assert_equal_u32(a[1], test_vec[i].a[1]);
    simde_assert_equal_u32(a[2], test_vec[i].a[2]);
    simde_assert_equal_u32(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    uint32_t a[4];
    simde_uint32x4x4_t val = simde_test_arm_neon_random_u32x4x4();
    const int lane = lanes[i];
    simde_vst4q_lane_u32(a, val, lane);

    simde_test_codegen_write_vu32(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[4];
    uint64_t val[4][2];
    int lane;
  } test_vec[] = {
    { { UINT64_C(14997841147184378370), UINT64_C(12809749988570511882), UINT64_C(  836909148827903678), UINT64_C(14697895197898141577) },
        { { UINT64_C(14997841147184378370), UINT64_C(17381142849367608731) },
          { UINT64_C(12809749988570511882), UINT64_C( 8267848534497501692) },
          { UINT64_C(  836909148827903678), UINT64_C(13916210496762642137) },
          { UINT64_C(14697895197898141577), UINT64_C( 8821553021314297738) } },
       INT32_C(           0) },
    { { UINT64_C( 5033627712026668387), UINT64_C( 1525550653981379062), UINT64_C( 8368164178402603551), UINT64_C( 4173157680549852312) },
        { { UINT64_C(13426609144858121689), UINT64_C( 5033627712026668387) },
          { UINT64_C( 8220063172305714809), UINT64_C( 1525550653981379062) },
          { UINT64_C(13477217977247888237), UINT64_C( 8368164178402603551) },
          { UINT64_C( 3136984967385230894), UINT64_C( 4173157680549852312) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2x4_t val = {{simde_vld1q_u64(test_vec[i].val[0]),
                              simde_vld1q_u64(test_vec[i].val[1]),
                              simde_vld1q_u64(test_vec[i].val[2]),
                              simde_vld1q_u64(test_vec[i].val[3])}};
    uint64_t a[4];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst4q_lane_u64, HEDLEY_UNREACHABLE(), test_vec[i].lane, a, val);

    simde_assert_equal_u64(a[0], test_vec[i].a[0]);
    simde_assert_equal_u64(a[1], test_vec[i].a[1]);
    simde_assert_equal_u64(a[2], test_vec[i].a[2]);
    simde_assert_equal_u64(a[3], test_vec[i].a[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    uint64_t a[4];
    simde_uint64x2x4_t val = simde_test_arm_neon_random_u64x2x4();
    simde_vst4q_lane_u64(a, val, i);

    simde_test_codegen_write_vu64(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t val[4][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    45.64), SIMDE_FLOAT32_C(   -12.54), SIMDE_FLOAT32_C(   -13.87), SIMDE_FLOAT32_C(   -54.45) },
        { { SIMDE_FLOAT32_C(    45.64), SIMDE_FLOAT32_C(    15.04), SIMDE_FLOAT32_C(    42.40), SIMDE_FLOAT32_C(   -29.53) },
          { SIMDE_FLOAT32_C(   -12.54), SIMDE_FLOAT32_C(   -11.31), SIMDE_FLOAT32_C(   -67.73), SIMDE_FLOAT32_C(    55.09) },
          { SIMDE_FLOAT32_C(   -13.87), SIMDE_FLOAT32_C(   -63.08), SIMDE_FLOAT32_C(    23.37), SIMDE_FLOAT32_C(     7.88) },
          { SIMDE_FLOAT32_C(   -54.45), SIMDE_FLOAT32_C(    -4.07), SIMDE_FLOAT32_C(   -42.90), SIMDE_FLOAT32_C(   -15.92) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT32_C(   -57.77), SIMDE_FLOAT32_C(    40.38), SIMDE_FLOAT32_C(    51.54), SIMDE_FLOAT32_C(    19.48) },
        { { SIMDE_FLOAT32_C(   -14.94), SIMDE_FLOAT32_C(   -57.77), SIMDE_FLOAT32_C(   -50.44), SIMDE_FLOAT32_C(    15.21) },
          { SIMDE_FLOAT32_C(     9.91), SIMDE_FLOAT32_C(    40.38), SIMDE_FLOAT32_C(   -60.19), SIMDE_FLOAT32_C(   -93.59) },
          { SIMDE_FLOAT32_C(   -66.94), SIMDE_FLOAT32_C(    51.54), SIMDE_FLOAT32_C(   -24.67), SIMDE_FLOAT32_C(   -20.06) },
          { SIMDE_FLOAT32_C(   -45.39), SIMDE_FLOAT32_C(    19.48), SIMDE_FLOAT32_C(    90.47), SIMDE_FLOAT32_C(   -99.75) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4x4_t val = {{simde_vld1q_f32(test_vec[i].val[0]),
                               simde_vld1q_f32(test_vec[i].val[1]),
                               simde_vld1q_f32(test_vec[i].val[2]),
                               simde_vld1q_f32(test_vec[i].val[3])}};
    simde_float32_t a[4];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst4q_lane_f32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_f32(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f32(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f32(a[2], test_vec[i].a[2], 1);
    simde_assert_equal_f32(a[3], test_vec[i].a[3], 1);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32_t a[4];
    simde_float32x4x4_t val = simde_test_arm_neon_random_f32x4x4(-100.0f, 100.0f);
    const int lane = lanes[i];
    simde_vst4q_lane_f32(a, val, lane);

    simde_test_codegen_write_vf32(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst4q_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[4];
    simde_float64_t val[4][2];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(     6.25), SIMDE_FLOAT64_C(   -44.85), SIMDE_FLOAT64_C(    27.50), SIMDE_FLOAT64_C(    34.64) },
        { { SIMDE_FLOAT64_C(     6.25), SIMDE_FLOAT64_C(    43.57) },
          { SIMDE_FLOAT64_C(   -44.85), SIMDE_FLOAT64_C(   -84.14) },
          { SIMDE_FLOAT64_C(    27.50), SIMDE_FLOAT64_C(    77.26) },
          { SIMDE_FLOAT64_C(    34.64), SIMDE_FLOAT64_C(    -6.79) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT64_C(   -30.77), SIMDE_FLOAT64_C(   -64.90), SIMDE_FLOAT64_C(   -72.21), SIMDE_FLOAT64_C(    75.84) },
        { { SIMDE_FLOAT64_C(   -30.77), SIMDE_FLOAT64_C(   -11.75) },
          { SIMDE_FLOAT64_C(   -64.90), SIMDE_FLOAT64_C(    26.58) },
          { SIMDE_FLOAT64_C(   -72.21), SIMDE_FLOAT64_C(    -5.43) },
          { SIMDE_FLOAT64_C(    75.84), SIMDE_FLOAT64_C(    10.83) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2x4_t val = {{simde_vld1q_f64(test_vec[i].val[0]),
                              simde_vld1q_f64(test_vec[i].val[1]),
                              simde_vld1q_f64(test_vec[i].val[2]),
                              simde_vld1q_f64(test_vec[i].val[3])}};
    simde_float64_t a[4];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst4q_lane_f64, HEDLEY_UNREACHABLE(), test_vec[i].lane, a, val);
    simde_vst4q_lane_f64(a, val, 0);

    simde_assert_equal_f64(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f64(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f64(a[2], test_vec[i].a[2], 1);
    simde_assert_equal_f64(a[3], test_vec[i].a[3], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64_t a[4];
    simde_float64x2x4_t val = simde_test_arm_neon_random_f64x2x4(-100.0, 100.0);
    simde_vst4q_lane_f64(a, val, i);

    simde_test_codegen_write_vf64(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2x4(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_lane_f64)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
