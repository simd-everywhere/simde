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

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_lane_u32)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
