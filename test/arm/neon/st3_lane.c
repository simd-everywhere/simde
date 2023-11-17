#define SIMDE_TEST_ARM_NEON_INSN st3_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/st3_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst3_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[3];
    int8_t val[3][8];
    int lane;
  } test_vec[] = {
    { {  INT8_C(  68), -INT8_C(  14),  INT8_C(  95) },
        { {  INT8_C(  68), -INT8_C(  81), -INT8_C(  40),  INT8_C(   2), -INT8_C(  39), -INT8_C(  18), -INT8_C(  36), -INT8_C(  53) },
          { -INT8_C(  14),  INT8_C(   4),  INT8_C(  96), -INT8_C( 103), -INT8_C( 100), -INT8_C(  67), -INT8_C(  89), -INT8_C(  88) },
          {  INT8_C(  95), -INT8_C(  20),  INT8_C(  59), -INT8_C(  36),  INT8_C(  49), -INT8_C( 118), -INT8_C(  43),  INT8_C(  54) } },
       INT32_C(           0) },
    { { -INT8_C(  31), -INT8_C(  54),  INT8_C(   9) },
        { { -INT8_C(  41), -INT8_C(  31), -INT8_C(   6),  INT8_C( 104), -INT8_C(  56),  INT8_C(  86), -INT8_C(  14),  INT8_C(  13) },
          {  INT8_C(   5), -INT8_C(  54),  INT8_C(  15), -INT8_C(  34), -INT8_C(  71), -INT8_C(  21), -INT8_C(  87), -INT8_C(  85) },
          { -INT8_C(  16),  INT8_C(   9),  INT8_C(  68), -INT8_C( 116), -INT8_C(  57), -INT8_C(  20),  INT8_C(  52),  INT8_C(  38) } },
       INT32_C(           1) },
    { {  INT8_C(   2),  INT8_C(  58),  INT8_C( 114) },
        { { -INT8_C(  40),  INT8_C( 112),  INT8_C(   2),  INT8_C(   9), -INT8_C(   6), -INT8_C(  41),  INT8_C(  63), -INT8_C(  47) },
          { -INT8_C(  71),  INT8_C(  57),  INT8_C(  58), -INT8_C( 127), -INT8_C( 113),  INT8_C(  44), -INT8_C( 114), -INT8_C( 108) },
          { -INT8_C(   9), -INT8_C(  98),  INT8_C( 114), -INT8_C(  80), -INT8_C( 119),  INT8_C(  28),  INT8_C(  91),  INT8_C( 121) } },
       INT32_C(           2) },
    { { -INT8_C(  20), -INT8_C(  91),  INT8_C( 115) },
        { {  INT8_C(  37), -INT8_C(  97),  INT8_C(   6), -INT8_C(  20), -INT8_C( 117),  INT8_C(  58),  INT8_C(  19),  INT8_C(  99) },
          { -INT8_C(  86),  INT8_C(  21),  INT8_C( 108), -INT8_C(  91), -INT8_C(  19), -INT8_C(  85),  INT8_C( 118), -INT8_C(  90) },
          { -INT8_C(  28), -INT8_C(  80),  INT8_C(  39),  INT8_C( 115), -INT8_C(  35), -INT8_C(  74),  INT8_C(   7), -INT8_C(  44) } },
       INT32_C(           3) },
    { { -INT8_C( 106), -INT8_C( 105), -INT8_C( 123) },
        { {  INT8_C(  84),  INT8_C( 122), -INT8_C( 124), -INT8_C(  35), -INT8_C( 106), -INT8_C(  33),  INT8_C(  87), -INT8_C(  69) },
          {  INT8_C( 126),  INT8_C(  93), -INT8_C(  88),  INT8_C(  10), -INT8_C( 105), -INT8_C(  69),  INT8_C( 109),  INT8_C(  66) },
          { -INT8_C(  48), -INT8_C(  38), -INT8_C(  25), -INT8_C(  67), -INT8_C( 123),  INT8_C(  93),  INT8_C(  99),  INT8_C( 106) } },
       INT32_C(           4) },
    { { -INT8_C(  27), -INT8_C(  55),  INT8_C(  24) },
        { {  INT8_C(  14), -INT8_C( 117), -INT8_C(  35), -INT8_C(  21),  INT8_C(  65), -INT8_C(  27), -INT8_C(  65), -INT8_C( 107) },
          {  INT8_C(  95),  INT8_C(  67),  INT8_C( 114), -INT8_C(  11),  INT8_C(  34), -INT8_C(  55), -INT8_C(  80), -INT8_C(  96) },
          {  INT8_C(  38),  INT8_C(  88), -INT8_C(  86), -INT8_C(  66),  INT8_C(  19),  INT8_C(  24),  INT8_C(   0), -INT8_C(  28) } },
       INT32_C(           5) },
    { { -INT8_C(  31),  INT8_C( 102),  INT8_C(   2) },
        { { -INT8_C(  14), -INT8_C(  25), -INT8_C(  95),  INT8_C( 119),  INT8_C(  68),  INT8_C(   5), -INT8_C(  31),  INT8_C(  82) },
          { -INT8_C( 112), -INT8_C(  65),  INT8_C(  61), -INT8_C(  47), -INT8_C(  92), -INT8_C(   4),  INT8_C( 102),  INT8_C(   3) },
          {  INT8_C(  63), -INT8_C(  40), -INT8_C(   8),  INT8_C(  97), -INT8_C(  94), -INT8_C(  88),  INT8_C(   2), -INT8_C(  56) } },
       INT32_C(           6) },
    { { -INT8_C(  74),  INT8_C(  47),  INT8_C( 126) },
        { {  INT8_C(   1), -INT8_C(  84), -INT8_C( 122),  INT8_C(  20), -INT8_C(  60), -INT8_C( 122), -INT8_C(   8), -INT8_C(  74) },
          {  INT8_C( 109), -INT8_C( 102),  INT8_C(  46), -INT8_C(  78), -INT8_C(  97),  INT8_C(  15),  INT8_C(   4),  INT8_C(  47) },
          { -INT8_C(  50),  INT8_C(  66),  INT8_C(   0),  INT8_C( 114),  INT8_C(  62),  INT8_C( 102),  INT8_C( 117),  INT8_C( 126) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8x3_t val = {{simde_vld1_s8(test_vec[i].val[0]),
                             simde_vld1_s8(test_vec[i].val[1]),
                             simde_vld1_s8(test_vec[i].val[2])}};
    int8_t a[3];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3_lane_s8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i8(a[0], test_vec[i].a[0]);
    simde_assert_equal_i8(a[1], test_vec[i].a[1]);
    simde_assert_equal_i8(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a[3];
    simde_int8x8x3_t val = simde_test_arm_neon_random_i8x8x3();
    const int lane = lanes[i];
    simde_vst3_lane_s8(a, val, lane);

    simde_test_codegen_write_vi8(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[3];
    int16_t val[3][4];
    int lane;
  } test_vec[] = {
    { { -INT16_C( 19636),  INT16_C( 30292), -INT16_C( 29496) },
        { { -INT16_C( 19636), -INT16_C( 25674),  INT16_C( 13585), -INT16_C(  7811) },
          {  INT16_C( 30292), -INT16_C(   452), -INT16_C( 10845),  INT16_C(  5302) },
          { -INT16_C( 29496),  INT16_C( 11407),  INT16_C(  1455), -INT16_C( 11616) } },
       INT32_C(           0) },
    { { -INT16_C( 11858),  INT16_C( 11053), -INT16_C( 15291) },
        { { -INT16_C( 18022), -INT16_C( 11858),  INT16_C( 26437), -INT16_C( 28153) },
          { -INT16_C( 17126),  INT16_C( 11053), -INT16_C( 21773),  INT16_C( 18189) },
          {  INT16_C( 18720), -INT16_C( 15291), -INT16_C(   994), -INT16_C(  6440) } },
       INT32_C(           1) },
    { { -INT16_C( 19860), -INT16_C(  8673),  INT16_C( 29210) },
        { {  INT16_C( 26504),  INT16_C( 14098), -INT16_C( 19860),  INT16_C(  1546) },
          { -INT16_C( 18324), -INT16_C( 20009), -INT16_C(  8673),  INT16_C( 14915) },
          {  INT16_C( 28828), -INT16_C( 28827),  INT16_C( 29210),  INT16_C( 15318) } },
       INT32_C(           2) },
    { { -INT16_C( 24640), -INT16_C(  3663),  INT16_C(  1010) },
        { {  INT16_C(  7099), -INT16_C(  9729), -INT16_C( 10473), -INT16_C( 24640) },
          { -INT16_C( 11714), -INT16_C( 21545), -INT16_C(  7803), -INT16_C(  3663) },
          { -INT16_C( 30311), -INT16_C( 18270), -INT16_C(  6553),  INT16_C(  1010) } },
       INT32_C(           3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4x3_t val = {{simde_vld1_s16(test_vec[i].val[0]),
                              simde_vld1_s16(test_vec[i].val[1]),
                              simde_vld1_s16(test_vec[i].val[2])}};
    int16_t a[3];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst3_lane_s16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i16(a[0], test_vec[i].a[0]);
    simde_assert_equal_i16(a[1], test_vec[i].a[1]);
    simde_assert_equal_i16(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    int16_t a[3];
    simde_int16x4x3_t val = simde_test_arm_neon_random_i16x4x3();
    const int lane = lanes[i];
    simde_vst3_lane_s16(a, val, lane);

    simde_test_codegen_write_vi16(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[3];
    int32_t val[3][2];
    int lane;
  } test_vec[] = {
    { { -INT32_C(   123238509),  INT32_C(   265582818), -INT32_C(   718394596) },
        { { -INT32_C(   123238509), -INT32_C(   952686871) },
          {  INT32_C(   265582818),  INT32_C(   945269294) },
          { -INT32_C(   718394596), -INT32_C(  1612531604) } },
       INT32_C(           0) },
    { { -INT32_C(   267094179), -INT32_C(  1011867423),  INT32_C(  1258301743) },
        { {  INT32_C(  1747970252), -INT32_C(   267094179) },
          { -INT32_C(   387335169), -INT32_C(  1011867423) },
          { -INT32_C(   942504807),  INT32_C(  1258301743) } },
       INT32_C(           1) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2x3_t val = {{simde_vld1_s32(test_vec[i].val[0]),
                              simde_vld1_s32(test_vec[i].val[1]),
                              simde_vld1_s32(test_vec[i].val[2])}};
    int32_t a[3];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3_lane_s32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i32(a[0], test_vec[i].a[0]);
    simde_assert_equal_i32(a[1], test_vec[i].a[1]);
    simde_assert_equal_i32(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a[3];
    simde_int32x2x3_t val = simde_test_arm_neon_random_i32x2x3();
    const int lane = lanes[i];
    simde_vst3_lane_s32(a, val, lane);

    simde_test_codegen_write_vi32(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[3];
    int64_t val[3][2];
    int lane;
  } test_vec[] = {
    { {  INT64_C(  269425340872446909),  INT64_C( 9012106986654512119),  INT64_C(  412261884533944970) },
       { {  INT64_C(  269425340872446909) },
         {  INT64_C( 9012106986654512119) },
         {  INT64_C(  412261884533944970) } },
      INT32_C(           0) },
   { { -INT64_C( 6510873652261283296), -INT64_C(  325126668632009587), -INT64_C( 3338734926053976162) },
       { { -INT64_C( 6510873652261283296) },
         { -INT64_C(  325126668632009587) },
         { -INT64_C( 3338734926053976162) } },
      INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1x3_t val = {{simde_vld1_s64(test_vec[i].val[0]),
                              simde_vld1_s64(test_vec[i].val[1]),
                              simde_vld1_s64(test_vec[i].val[2])}};
    int64_t a[3];
    simde_vst3_lane_s64(a, val, 0);

    simde_assert_equal_i64(a[0], test_vec[i].a[0]);
    simde_assert_equal_i64(a[1], test_vec[i].a[1]);
    simde_assert_equal_i64(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    int64_t a[3];
    simde_int64x1x3_t val = simde_test_arm_neon_random_i64x1x3();
    const int lane = lanes[i];
    simde_vst3_lane_s64(a, val, 0);

    simde_test_codegen_write_vi64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[3];
    uint8_t val[3][8];
    int lane;
  } test_vec[] = {
    { { UINT8_C(252), UINT8_C( 37), UINT8_C( 62) },
        { { UINT8_C(252), UINT8_C(169), UINT8_C(185), UINT8_C(185), UINT8_C( 48), UINT8_C( 48), UINT8_C( 82), UINT8_C(153) },
          { UINT8_C( 37), UINT8_C(233), UINT8_C( 58), UINT8_C( 96), UINT8_C(247), UINT8_C( 15), UINT8_C(111), UINT8_C( 84) },
          { UINT8_C( 62), UINT8_C( 32), UINT8_C(204), UINT8_C(218), UINT8_C(173), UINT8_C(  5), UINT8_C( 45), UINT8_C(206) } },
       INT32_C(           0) },
    { { UINT8_C(175), UINT8_C(158), UINT8_C( 13) },
        { { UINT8_C(194), UINT8_C(175), UINT8_C(250), UINT8_C(118), UINT8_C(192), UINT8_C( 96), UINT8_C(229), UINT8_C(188) },
          { UINT8_C( 10), UINT8_C(158), UINT8_C(117), UINT8_C( 58), UINT8_C(206), UINT8_C(199), UINT8_C(211), UINT8_C(243) },
          { UINT8_C(176), UINT8_C( 13), UINT8_C( 83), UINT8_C(167), UINT8_C( 29), UINT8_C(195), UINT8_C(251), UINT8_C( 91) } },
       INT32_C(           1) },
    { { UINT8_C( 53), UINT8_C(  5), UINT8_C(253) },
        { { UINT8_C(227), UINT8_C(199), UINT8_C( 53), UINT8_C(144), UINT8_C(204), UINT8_C( 99), UINT8_C( 95), UINT8_C(142) },
          { UINT8_C( 18), UINT8_C( 89), UINT8_C(  5), UINT8_C(210), UINT8_C(185), UINT8_C(234), UINT8_C(143), UINT8_C(195) },
          { UINT8_C(136), UINT8_C(  4), UINT8_C(253), UINT8_C( 86), UINT8_C(204), UINT8_C(208), UINT8_C( 73), UINT8_C(124) } },
       INT32_C(           2) },
    { { UINT8_C(251), UINT8_C(179), UINT8_C( 68) },
        { { UINT8_C(222), UINT8_C(156), UINT8_C( 36), UINT8_C(251), UINT8_C( 95), UINT8_C( 31), UINT8_C( 86), UINT8_C( 66) },
          { UINT8_C(231), UINT8_C(139), UINT8_C(211), UINT8_C(179), UINT8_C(238), UINT8_C( 50), UINT8_C( 66), UINT8_C(  0) },
          { UINT8_C(139), UINT8_C( 71), UINT8_C(211), UINT8_C( 68), UINT8_C( 49), UINT8_C( 98), UINT8_C(  8), UINT8_C(185) } },
       INT32_C(           3) },
    { { UINT8_C(214), UINT8_C(242), UINT8_C(155) },
        { { UINT8_C(102), UINT8_C(  5), UINT8_C( 15), UINT8_C( 50), UINT8_C(214), UINT8_C( 88), UINT8_C(175), UINT8_C(180) },
          { UINT8_C(244), UINT8_C(211), UINT8_C(175), UINT8_C( 84), UINT8_C(242), UINT8_C(  5), UINT8_C(150), UINT8_C(217) },
          { UINT8_C(144), UINT8_C(105), UINT8_C(141), UINT8_C(127), UINT8_C(155), UINT8_C(207), UINT8_C(127), UINT8_C( 38) } },
       INT32_C(           4) },
    { { UINT8_C(115), UINT8_C(252), UINT8_C( 70) },
        { { UINT8_C( 22), UINT8_C( 82), UINT8_C(107), UINT8_C( 71), UINT8_C(180), UINT8_C(115), UINT8_C(  0), UINT8_C( 27) },
          { UINT8_C(120), UINT8_C( 15), UINT8_C( 77), UINT8_C( 78), UINT8_C(103), UINT8_C(252), UINT8_C(  2), UINT8_C( 91) },
          { UINT8_C(207), UINT8_C(177), UINT8_C(175), UINT8_C(194), UINT8_C(182), UINT8_C( 70), UINT8_C(155), UINT8_C( 71) } },
       INT32_C(           5) },
    { { UINT8_C(113), UINT8_C(103), UINT8_C( 38) },
        { { UINT8_C(175), UINT8_C( 40), UINT8_C(198), UINT8_C( 75), UINT8_C(247), UINT8_C( 69), UINT8_C(113), UINT8_C( 13) },
          { UINT8_C(152), UINT8_C(220), UINT8_C( 84), UINT8_C( 76), UINT8_C( 79), UINT8_C( 84), UINT8_C(103), UINT8_C(200) },
          { UINT8_C( 99), UINT8_C(181), UINT8_C( 22), UINT8_C(202), UINT8_C(177), UINT8_C( 25), UINT8_C( 38), UINT8_C(129) } },
       INT32_C(           6) },
    { { UINT8_C(203), UINT8_C(107), UINT8_C( 24) },
        { { UINT8_C(202), UINT8_C(213), UINT8_C( 67), UINT8_C(129), UINT8_C( 27), UINT8_C(222), UINT8_C(200), UINT8_C(203) },
          { UINT8_C(  7), UINT8_C(142), UINT8_C( 22), UINT8_C(254), UINT8_C(211), UINT8_C(135), UINT8_C( 12), UINT8_C(107) },
          { UINT8_C(100), UINT8_C( 96), UINT8_C(184), UINT8_C(179), UINT8_C(181), UINT8_C( 31), UINT8_C(123), UINT8_C( 24) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8x3_t val = {{simde_vld1_u8(test_vec[i].val[0]),
                              simde_vld1_u8(test_vec[i].val[1]),
                              simde_vld1_u8(test_vec[i].val[2])}};
    uint8_t a[3];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3_lane_u8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u8(a[0], test_vec[i].a[0]);
    simde_assert_equal_u8(a[1], test_vec[i].a[1]);
    simde_assert_equal_u8(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a[3];
    simde_uint8x8x3_t val = simde_test_arm_neon_random_u8x8x3();
    const int lane = lanes[i];
    simde_vst3_lane_u8(a, val, lane);

    simde_test_codegen_write_vu8(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[3];
    uint16_t val[3][4];
    int lane;
  } test_vec[] = {
    { { UINT16_C(16273), UINT16_C(18374), UINT16_C(14511) },
        { { UINT16_C(16273), UINT16_C(43473), UINT16_C(40084), UINT16_C(38537) },
          { UINT16_C(18374), UINT16_C(59088), UINT16_C(53758), UINT16_C(33900) },
          { UINT16_C(14511), UINT16_C(16185), UINT16_C(53010), UINT16_C( 6016) } },
       INT32_C(           0) },
    { { UINT16_C(64585), UINT16_C(20255), UINT16_C(61083) },
        { { UINT16_C( 8634), UINT16_C(64585), UINT16_C(31972), UINT16_C(30081) },
          { UINT16_C(21179), UINT16_C(20255), UINT16_C(43247), UINT16_C(46565) },
          { UINT16_C(46832), UINT16_C(61083), UINT16_C( 2183), UINT16_C(13938) } },
       INT32_C(           1) },
    { { UINT16_C(62842), UINT16_C(45615), UINT16_C( 7992) },
        { { UINT16_C(43840), UINT16_C(21109), UINT16_C(62842), UINT16_C(13417) },
          { UINT16_C(45591), UINT16_C(64305), UINT16_C(45615), UINT16_C(60017) },
          { UINT16_C(36868), UINT16_C(62266), UINT16_C( 7992), UINT16_C(10409) } },
       INT32_C(           2) },
    { { UINT16_C(35986), UINT16_C( 5347), UINT16_C(51731) },
        { { UINT16_C(17621), UINT16_C(23574), UINT16_C(34892), UINT16_C(35986) },
          { UINT16_C( 2100), UINT16_C(44766), UINT16_C(18429), UINT16_C( 5347) },
          { UINT16_C( 5370), UINT16_C(10512), UINT16_C(33222), UINT16_C(51731) } },
       INT32_C(           3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4x3_t val = {{simde_vld1_u16(test_vec[i].val[0]),
                               simde_vld1_u16(test_vec[i].val[1]),
                               simde_vld1_u16(test_vec[i].val[2])}};
    uint16_t a[3];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst3_lane_u16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u16(a[0], test_vec[i].a[0]);
    simde_assert_equal_u16(a[1], test_vec[i].a[1]);
    simde_assert_equal_u16(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    uint16_t a[3];
    simde_uint16x4x3_t val = simde_test_arm_neon_random_u16x4x3();
    const int lane = lanes[i];
    simde_vst3_lane_u16(a, val, lane);

    simde_test_codegen_write_vu16(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[3];
    uint32_t val[3][2];
    int lane;
  } test_vec[] = {
    { { UINT32_C(2339170847), UINT32_C(2176724097), UINT32_C( 857889276) },
        { { UINT32_C(2339170847), UINT32_C(2621937295) },
          { UINT32_C(2176724097), UINT32_C(2784906734) },
          { UINT32_C( 857889276), UINT32_C(2911481199) } },
      UINT32_C(         0) },
    { { UINT32_C( 790974736), UINT32_C(2842100007), UINT32_C(1858218098) },
        { { UINT32_C(2448987242), UINT32_C( 790974736) },
          { UINT32_C(3418001724), UINT32_C(2842100007) },
          { UINT32_C( 472524078), UINT32_C(1858218098) } },
      UINT32_C(         1) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2x3_t val = {{simde_vld1_u32(test_vec[i].val[0]),
                               simde_vld1_u32(test_vec[i].val[1]),
                               simde_vld1_u32(test_vec[i].val[2])}};
    uint32_t a[3];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3_lane_u32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u32(a[0], test_vec[i].a[0]);
    simde_assert_equal_u32(a[1], test_vec[i].a[1]);
    simde_assert_equal_u32(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    uint32_t a[3];
    simde_uint32x2x3_t val = simde_test_arm_neon_random_u32x2x3();
    const int lane = lanes[i];
    simde_vst3_lane_u32(a, val, lane);

    simde_test_codegen_write_vu32(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[3];
    uint64_t val[3][1];
    int lane;
  } test_vec[] = {
    { { UINT64_C( 9820617213119390696), UINT64_C( 9673927912867748552), UINT64_C( 9141607021924738105) },
        { { UINT64_C( 9820617213119390696) },
          { UINT64_C( 9673927912867748552) },
          { UINT64_C( 9141607021924738105) } },
       INT32_C(           0) },
    { { UINT64_C( 7992953132776502036), UINT64_C(11451113253560516111), UINT64_C(  942796949381914977) },
        { { UINT64_C( 7992953132776502036) },
          { UINT64_C(11451113253560516111) },
          { UINT64_C(  942796949381914977) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1x3_t val = {{simde_vld1_u64(test_vec[i].val[0]),
                              simde_vld1_u64(test_vec[i].val[1]),
                              simde_vld1_u64(test_vec[i].val[2])}};
    uint64_t a[3];
    simde_vst3_lane_u64(a, val, 0);

    simde_assert_equal_u64(a[0], test_vec[i].a[0]);
    simde_assert_equal_u64(a[1], test_vec[i].a[1]);
    simde_assert_equal_u64(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    uint64_t a[3];
    simde_uint64x1x3_t val = simde_test_arm_neon_random_u64x1x3();
    const int lane = lanes[i];
    simde_vst3_lane_u64(a, val, 0);

    simde_test_codegen_write_vu64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[3];
    simde_float16_t val[3][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( - 94.290), SIMDE_FLOAT16_VALUE( - 50.509),  SIMDE_FLOAT16_VALUE( 23.704) },
    { { SIMDE_FLOAT16_VALUE( -  0.571), SIMDE_FLOAT16_VALUE( - 94.290),  SIMDE_FLOAT16_VALUE( 93.093),  SIMDE_FLOAT16_VALUE( 89.891)  },
      { SIMDE_FLOAT16_VALUE( - 59.956), SIMDE_FLOAT16_VALUE( - 50.509),  SIMDE_FLOAT16_VALUE( 35.194),  SIMDE_FLOAT16_VALUE( 22.787)  },
      { SIMDE_FLOAT16_VALUE( - 24.560),  SIMDE_FLOAT16_VALUE( 23.704), SIMDE_FLOAT16_VALUE( - 11.110), SIMDE_FLOAT16_VALUE( - 19.691)  } },
         INT8_C(      1) },
    { { SIMDE_FLOAT16_VALUE( -  6.814), SIMDE_FLOAT16_VALUE( - 31.127), SIMDE_FLOAT16_VALUE( - 34.824) },
    { { SIMDE_FLOAT16_VALUE( - 17.965), SIMDE_FLOAT16_VALUE( -  6.814), SIMDE_FLOAT16_VALUE( - 65.421),  SIMDE_FLOAT16_VALUE( 26.500)  },
      {  SIMDE_FLOAT16_VALUE( 84.515), SIMDE_FLOAT16_VALUE( - 31.127),  SIMDE_FLOAT16_VALUE( 85.025), SIMDE_FLOAT16_VALUE( - 51.272)  },
      { SIMDE_FLOAT16_VALUE( - 38.529), SIMDE_FLOAT16_VALUE( - 34.824), SIMDE_FLOAT16_VALUE( - 81.647),  SIMDE_FLOAT16_VALUE( 47.194)  } },
         INT8_C(      1) },
    { { SIMDE_FLOAT16_VALUE( - 73.789), SIMDE_FLOAT16_VALUE( -  3.383), SIMDE_FLOAT16_VALUE( - 13.801) },
    { { SIMDE_FLOAT16_VALUE( - 94.005), SIMDE_FLOAT16_VALUE( - 35.738), SIMDE_FLOAT16_VALUE( - 73.789), SIMDE_FLOAT16_VALUE( - 45.230)  },
      {  SIMDE_FLOAT16_VALUE( 12.330),  SIMDE_FLOAT16_VALUE( 74.051), SIMDE_FLOAT16_VALUE( -  3.383), SIMDE_FLOAT16_VALUE( - 10.054)  },
      { SIMDE_FLOAT16_VALUE( - 64.841),  SIMDE_FLOAT16_VALUE(  8.563), SIMDE_FLOAT16_VALUE( - 13.801),  SIMDE_FLOAT16_VALUE( 10.504)  } },
         INT8_C(      2) },
    { {  SIMDE_FLOAT16_VALUE(  0.435),  SIMDE_FLOAT16_VALUE( 62.466),  SIMDE_FLOAT16_VALUE( 94.721) },
    { {  SIMDE_FLOAT16_VALUE(  0.435), SIMDE_FLOAT16_VALUE( - 13.638),  SIMDE_FLOAT16_VALUE(  0.530), SIMDE_FLOAT16_VALUE( - 61.496)  },
      {  SIMDE_FLOAT16_VALUE( 62.466),  SIMDE_FLOAT16_VALUE( 24.828),  SIMDE_FLOAT16_VALUE(  9.968), SIMDE_FLOAT16_VALUE( - 50.721)  },
      {  SIMDE_FLOAT16_VALUE( 94.721),  SIMDE_FLOAT16_VALUE( 44.136),  SIMDE_FLOAT16_VALUE( 78.905), SIMDE_FLOAT16_VALUE( - 55.458)  } },
         INT8_C(      0) },
    { { SIMDE_FLOAT16_VALUE( - 22.144),  SIMDE_FLOAT16_VALUE( 90.977), SIMDE_FLOAT16_VALUE( -  5.890) },
    { {  SIMDE_FLOAT16_VALUE( 26.172), SIMDE_FLOAT16_VALUE( - 89.305), SIMDE_FLOAT16_VALUE( - 59.818), SIMDE_FLOAT16_VALUE( - 22.144)  },
      { SIMDE_FLOAT16_VALUE( - 44.719), SIMDE_FLOAT16_VALUE( - 60.282),  SIMDE_FLOAT16_VALUE( 94.935),  SIMDE_FLOAT16_VALUE( 90.977)  },
      {  SIMDE_FLOAT16_VALUE( 80.867), SIMDE_FLOAT16_VALUE( - 45.339), SIMDE_FLOAT16_VALUE( - 19.747), SIMDE_FLOAT16_VALUE( -  5.890)  } },
         INT8_C(      3) },
    { {  SIMDE_FLOAT16_VALUE( 23.224),  SIMDE_FLOAT16_VALUE( 49.585),  SIMDE_FLOAT16_VALUE( 78.018) },
    { { SIMDE_FLOAT16_VALUE( - 48.686),  SIMDE_FLOAT16_VALUE( 23.224),  SIMDE_FLOAT16_VALUE( 40.332),  SIMDE_FLOAT16_VALUE( 74.959)  },
      { SIMDE_FLOAT16_VALUE( - 65.641),  SIMDE_FLOAT16_VALUE( 49.585),  SIMDE_FLOAT16_VALUE(  6.886),  SIMDE_FLOAT16_VALUE( 98.862)  },
      { SIMDE_FLOAT16_VALUE( - 29.125),  SIMDE_FLOAT16_VALUE( 78.018), SIMDE_FLOAT16_VALUE( -  4.487),  SIMDE_FLOAT16_VALUE( 50.278)  } },
         INT8_C(      1) },
    { { SIMDE_FLOAT16_VALUE( - 90.627), SIMDE_FLOAT16_VALUE( -  1.372), SIMDE_FLOAT16_VALUE( - 87.387) },
    { { SIMDE_FLOAT16_VALUE( - 58.435),  SIMDE_FLOAT16_VALUE( 67.021), SIMDE_FLOAT16_VALUE( - 90.627),  SIMDE_FLOAT16_VALUE( 69.960)  },
      {  SIMDE_FLOAT16_VALUE( 62.852),  SIMDE_FLOAT16_VALUE( 29.780), SIMDE_FLOAT16_VALUE( -  1.372),  SIMDE_FLOAT16_VALUE( 41.058)  },
      {  SIMDE_FLOAT16_VALUE( 43.350), SIMDE_FLOAT16_VALUE( - 69.931), SIMDE_FLOAT16_VALUE( - 87.387),  SIMDE_FLOAT16_VALUE( 98.569)  } },
         INT8_C(      2) },
    { {  SIMDE_FLOAT16_VALUE( 33.021),  SIMDE_FLOAT16_VALUE( 22.025),  SIMDE_FLOAT16_VALUE( 69.528) },
    { {  SIMDE_FLOAT16_VALUE( 40.864),  SIMDE_FLOAT16_VALUE( 81.943), SIMDE_FLOAT16_VALUE( - 40.609),  SIMDE_FLOAT16_VALUE( 33.021)  },
      {  SIMDE_FLOAT16_VALUE( 93.909),  SIMDE_FLOAT16_VALUE( 69.201),  SIMDE_FLOAT16_VALUE( 43.541),  SIMDE_FLOAT16_VALUE( 22.025)  },
      {  SIMDE_FLOAT16_VALUE( 45.748), SIMDE_FLOAT16_VALUE( - 89.541),  SIMDE_FLOAT16_VALUE( 49.879),  SIMDE_FLOAT16_VALUE( 69.528)  } },
         INT8_C(      3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float16x4x3_t val = {{simde_vld1_f16(test_vec[i].val[0]),
                               simde_vld1_f16(test_vec[i].val[1]),
                               simde_vld1_f16(test_vec[i].val[2])}};
    simde_float16_t a[3];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst3_lane_f16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_f16(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f16(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f16(a[2], test_vec[i].a[2], 1);
  }

  return 0;
}

static int
test_simde_vst3_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[3];
    simde_float32_t val[3][2];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    23.12), SIMDE_FLOAT32_C(   -89.02), SIMDE_FLOAT32_C(   -58.84) },
        { { SIMDE_FLOAT32_C(    23.12), SIMDE_FLOAT32_C(   -86.41) },
          { SIMDE_FLOAT32_C(   -89.02), SIMDE_FLOAT32_C(    26.63) },
          { SIMDE_FLOAT32_C(   -58.84), SIMDE_FLOAT32_C(   -62.75) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT32_C(   -25.70), SIMDE_FLOAT32_C(    92.17), SIMDE_FLOAT32_C(    13.73) },
        { { SIMDE_FLOAT32_C(    73.20), SIMDE_FLOAT32_C(   -25.70) },
          { SIMDE_FLOAT32_C(    20.19), SIMDE_FLOAT32_C(    92.17) },
          { SIMDE_FLOAT32_C(   -17.26), SIMDE_FLOAT32_C(    13.73) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2x3_t val = {{simde_vld1_f32(test_vec[i].val[0]),
                               simde_vld1_f32(test_vec[i].val[1]),
                               simde_vld1_f32(test_vec[i].val[2])}};
    simde_float32_t a[3];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3_lane_f32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_f32(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f32(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f32(a[2], test_vec[i].a[2], 1);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32_t a[3];
    simde_float32x2x3_t val = simde_test_arm_neon_random_f32x2x3(-100.0f, 100.0f);
    const int lane = lanes[i];
    simde_vst3_lane_f32(a, val, lane);

    simde_test_codegen_write_vf32(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[3];
    simde_float64_t val[3][1];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    99.90), SIMDE_FLOAT64_C(    75.46), SIMDE_FLOAT64_C(   -94.38) },
        { { SIMDE_FLOAT64_C(    99.90) },
          { SIMDE_FLOAT64_C(    75.46) },
          { SIMDE_FLOAT64_C(   -94.38) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT64_C(   -29.91), SIMDE_FLOAT64_C(    66.51), SIMDE_FLOAT64_C(   -36.58) },
        { { SIMDE_FLOAT64_C(   -29.91) },
          { SIMDE_FLOAT64_C(    66.51) },
          { SIMDE_FLOAT64_C(   -36.58) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1x3_t val = {{simde_vld1_f64(test_vec[i].val[0]),
                              simde_vld1_f64(test_vec[i].val[1]),
                              simde_vld1_f64(test_vec[i].val[2])}};
    simde_float64_t a[3];
    simde_vst3_lane_f64(a, val, 0);

    simde_assert_equal_f64(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f64(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f64(a[2], test_vec[i].a[2], 1);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64_t a[3];
    simde_float64x1x3_t val = simde_test_arm_neon_random_f64x1x3(-100.0, 100.0);
    const int lane = lanes[i];
    simde_vst3_lane_f64(a, val, 0);

    simde_test_codegen_write_vf64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[3];
    int8_t val[3][16];
    int lane;
  } test_vec[] = {
    { { -INT8_C(  26),  INT8_C(  81),  INT8_C(  97) },
        { { -INT8_C(  26),  INT8_C(  90), -INT8_C(  55),  INT8_C(  30),  INT8_C(  47),  INT8_C(  77),  INT8_C(  95),  INT8_C(   4),
            -INT8_C(  64),  INT8_C( 112), -INT8_C(  77), -INT8_C(  93),  INT8_C(  13),  INT8_C(  79),  INT8_C(  88), -INT8_C(  64) },
          {  INT8_C(  81),  INT8_C(  76),  INT8_C(  37), -INT8_C( 100),  INT8_C(  42),  INT8_C(  23),  INT8_C(  41),  INT8_C(  84),
             INT8_C(  54), -INT8_C(  17), -INT8_C(  49),  INT8_C(  48),  INT8_C(  60),  INT8_C(   6),  INT8_C( 108),  INT8_C(  35) },
          {  INT8_C(  97),  INT8_C(  53),  INT8_C(  65), -INT8_C( 112), -INT8_C( 126), -INT8_C(  96), -INT8_C( 107),  INT8_C(  66),
             INT8_C(  16),  INT8_C(  72), -INT8_C(  26),  INT8_C(  29), -INT8_C( 104),  INT8_C(  62), -INT8_C(  35), -INT8_C(  23) } },
       INT32_C(           0) },
    { {  INT8_C(   3),  INT8_C(  63), -INT8_C(  74) },
        { { -INT8_C( 117),  INT8_C(   3), -INT8_C( 122), -INT8_C(  75),  INT8_C(  26), -INT8_C(  81),  INT8_C(  10),  INT8_C(  80),
            -INT8_C(  98), -INT8_C(  39), -INT8_C( 127), -INT8_C(  37), -INT8_C(  33), -INT8_C(  19), -INT8_C(   2),  INT8_C(  64) },
          {  INT8_C(  34),  INT8_C(  63), -INT8_C(  47), -INT8_C(  92), -INT8_C(  33),  INT8_C( 102), -INT8_C(  25), -INT8_C(  17),
            -INT8_C(  82), -INT8_C(  51),  INT8_C(  13),  INT8_C(  70),  INT8_C(  11), -INT8_C(  22),  INT8_C(  48), -INT8_C( 106) },
          { -INT8_C(  19), -INT8_C(  74),  INT8_C(  76),  INT8_C(   8),  INT8_C( 101),  INT8_C(  86),  INT8_C(  88),  INT8_C(   4),
             INT8_C(  47), -INT8_C(  39), -INT8_C(  33),  INT8_C(  14), -INT8_C(  58), -INT8_C(  35),  INT8_C(  79), -INT8_C(  24) } },
       INT32_C(           1) },
    { { -INT8_C( 115), -INT8_C(  41), -INT8_C(  99) },
        { {  INT8_C(  28),  INT8_C(  32), -INT8_C( 115), -INT8_C(   5), -INT8_C( 122),  INT8_C( 116), -INT8_C(  22),  INT8_C(  52),
             INT8_C(  65), -INT8_C(   9),  INT8_C( 123),  INT8_C(  76), -INT8_C(  30), -INT8_C(  85), -INT8_C(  29), -INT8_C(  49) },
          {  INT8_C(  97),  INT8_C(  47), -INT8_C(  41), -INT8_C(  58), -INT8_C( 123),  INT8_C(  48), -INT8_C(  54), -INT8_C(  76),
             INT8_C(   9), -INT8_C(  87), -INT8_C(  62), -INT8_C(  48), -INT8_C( 122),  INT8_C(  17), -INT8_C(  72), -INT8_C(  94) },
          {  INT8_C(  49),  INT8_C(  69), -INT8_C(  99), -INT8_C(  73), -INT8_C(  71), -INT8_C( 120), -INT8_C(  20), -INT8_C(   6),
                 INT8_MAX,  INT8_C( 103),  INT8_C(  71),  INT8_C(  97),  INT8_C(  18),  INT8_C(  42),  INT8_C(  49),  INT8_C( 115) } },
       INT32_C(           2) },
    { { -INT8_C(  34), -INT8_C(  55),  INT8_C(  79) },
        { {  INT8_C(  89),  INT8_C(   8),  INT8_C(  57), -INT8_C(  34),  INT8_C(  56),  INT8_C(   4), -INT8_C( 110),  INT8_C(  66),
            -INT8_C(  83),  INT8_C(  84),  INT8_C(  18),  INT8_C(  52),  INT8_C( 102), -INT8_C(  54), -INT8_C(  42), -INT8_C( 105) },
          {  INT8_C(  16),  INT8_C( 116),  INT8_C(  79), -INT8_C(  55), -INT8_C(   4),  INT8_C(  59), -INT8_C(  60),  INT8_C( 123),
            -INT8_C(  94),  INT8_C(  11), -INT8_C(  35), -INT8_C(  76),  INT8_C(  53),  INT8_C(  14),  INT8_C(  39), -INT8_C( 114) },
          {  INT8_C(  22),  INT8_C(  96),  INT8_C( 108),  INT8_C(  79),  INT8_C( 100), -INT8_C(   2), -INT8_C( 111),  INT8_C(  18),
             INT8_C(  82), -INT8_C(  93),  INT8_C(  70), -INT8_C(  72),  INT8_C( 109),  INT8_C(  28),  INT8_C(  80),  INT8_C( 125) } },
       INT32_C(           3) },
    { { -INT8_C(  38),  INT8_C(  67), -INT8_C(  55) },
        { { -INT8_C( 112), -INT8_C(  97),  INT8_C(  71), -INT8_C( 116), -INT8_C(  38),  INT8_C(  11),  INT8_C(   8),  INT8_C( 124),
             INT8_C(  22), -INT8_C(  27),  INT8_C(  48),  INT8_C(  75), -INT8_C(  13),  INT8_C(  87), -INT8_C(  39),  INT8_C(   9) },
          { -INT8_C(  73),  INT8_C(  69),  INT8_C(  88),  INT8_C(  28),  INT8_C(  67), -INT8_C(  23),  INT8_C(  46), -INT8_C( 107),
            -INT8_C( 116),  INT8_C( 116),  INT8_C(  78), -INT8_C(   6), -INT8_C( 112), -INT8_C(  98),  INT8_C( 119),  INT8_C(  33) },
          {  INT8_C(  61), -INT8_C(  66), -INT8_C(  83),  INT8_C(  23), -INT8_C(  55), -INT8_C(  75), -INT8_C( 109), -INT8_C(  33),
            -INT8_C( 102), -INT8_C(  61),  INT8_C(  42), -INT8_C( 115),  INT8_C(  26),  INT8_C(   3), -INT8_C( 105), -INT8_C(  47) } },
       INT32_C(           4) },
    { {  INT8_C(  27), -INT8_C(  12),  INT8_C(  97) },
        { {  INT8_C(  72), -INT8_C(  17), -INT8_C(  19), -INT8_C( 117), -INT8_C(  39),  INT8_C(  27),  INT8_C(  33),  INT8_C( 101),
            -INT8_C( 113),  INT8_C( 111),  INT8_C(  95),  INT8_C(  32),  INT8_C(  13), -INT8_C(  41),  INT8_C(  65),  INT8_C(  74) },
          { -INT8_C( 107), -INT8_C(  18),  INT8_C(  97),  INT8_C(  95), -INT8_C(  92), -INT8_C(  12),  INT8_C(  62),  INT8_C(  62),
            -INT8_C(  73),  INT8_C( 105), -INT8_C(  52), -INT8_C(  47),  INT8_C( 108),  INT8_C(  99), -INT8_C(  94), -INT8_C(  75) },
          {  INT8_C(  82), -INT8_C( 112),  INT8_C(  64),  INT8_C(  43), -INT8_C(  85),  INT8_C(  97), -INT8_C( 111),  INT8_C(  59),
            -INT8_C(  48), -INT8_C(  16),  INT8_C(  91), -INT8_C(  35), -INT8_C(  57), -INT8_C( 100),  INT8_C(  39),  INT8_C(  93) } },
       INT32_C(           5) },
    { {  INT8_C( 109),  INT8_C(  29),  INT8_C(  53) },
        { { -INT8_C( 118), -INT8_C( 120), -INT8_C(  68),  INT8_C(  46),  INT8_C( 124), -INT8_C(   6),  INT8_C( 109),  INT8_C(  51),
             INT8_C(  99),  INT8_C(  57),  INT8_C(   4), -INT8_C(  48), -INT8_C( 100), -INT8_C(  89), -INT8_C( 123), -INT8_C(  18) },
          {  INT8_C(  55), -INT8_C(  59),  INT8_C(  26), -INT8_C(  30),  INT8_C(  39), -INT8_C(  85),  INT8_C(  29), -INT8_C(   9),
            -INT8_C( 101),  INT8_C( 120), -INT8_C(  43),  INT8_C(  99),  INT8_C(  20), -INT8_C(   4), -INT8_C(  64), -INT8_C(  97) },
          { -INT8_C( 123),  INT8_C( 124), -INT8_C(  51),  INT8_C(   1),  INT8_C( 118),  INT8_C(  58),  INT8_C(  53), -INT8_C(  38),
             INT8_C( 115),  INT8_C(  57), -INT8_C(  86),  INT8_C(  15), -INT8_C(  32),  INT8_C(  47), -INT8_C(   2),  INT8_C(  23) } },
       INT32_C(           6) },
    { {  INT8_C(  94), -INT8_C(  65),  INT8_C( 115) },
        { { -INT8_C(  12),  INT8_C(  24), -INT8_C(   6),  INT8_C(  27), -INT8_C(  61),  INT8_C(  23),  INT8_C(  19),  INT8_C(  94),
            -INT8_C( 112), -INT8_C(  24), -INT8_C(  63), -INT8_C(  92), -INT8_C(  28), -INT8_C( 127),  INT8_C(  67),  INT8_C( 105) },
          { -INT8_C(   3),  INT8_C(  17),  INT8_C( 107),  INT8_C( 116),  INT8_C(  75), -INT8_C(  96),  INT8_C(  78), -INT8_C(  65),
            -INT8_C(  39), -INT8_C(   8), -INT8_C(  50), -INT8_C(  70),  INT8_C(  39), -INT8_C(  52), -INT8_C(  47),  INT8_C(  27) },
          { -INT8_C(  28), -INT8_C(  53),  INT8_C(  55), -INT8_C(  89), -INT8_C(  29),  INT8_C(  74),  INT8_C(   6),  INT8_C( 115),
             INT8_C(  50), -INT8_C(  57),  INT8_C(  23),  INT8_C(  22),  INT8_C(  73),  INT8_C(  91),      INT8_MIN,  INT8_C(  70) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16x3_t val = {{simde_vld1q_s8(test_vec[i].val[0]),
                             simde_vld1q_s8(test_vec[i].val[1]),
                             simde_vld1q_s8(test_vec[i].val[2])}};
    int8_t a[3];
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst3q_lane_s8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i8(a[0], test_vec[i].a[0]);
    simde_assert_equal_i8(a[1], test_vec[i].a[1]);
    simde_assert_equal_i8(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a[3];
    simde_int8x16x3_t val = simde_test_arm_neon_random_i8x16x3();
    const int lane = lanes[i];
    simde_vst3q_lane_s8(a, val, lane);

    simde_test_codegen_write_vi8(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[3];
    int16_t val[3][8];
    int lane;
  } test_vec[] = {
    { {  INT16_C(  5764), -INT16_C( 13756), -INT16_C( 20546) },
        { {  INT16_C(  5764),  INT16_C(  7083),  INT16_C( 30159),  INT16_C( 14541), -INT16_C( 23610), -INT16_C( 31600),  INT16_C( 20496), -INT16_C(   547) },
          { -INT16_C( 13756),  INT16_C( 16481), -INT16_C( 10032),  INT16_C( 17856),  INT16_C(  9653),  INT16_C( 30089), -INT16_C( 22512), -INT16_C( 27644) },
          { -INT16_C( 20546), -INT16_C( 29265),  INT16_C( 32036), -INT16_C(  5179),  INT16_C( 21792),  INT16_C( 12399),  INT16_C( 19877), -INT16_C(  5587) } },
       INT32_C(           0) },
    { { -INT16_C(  6358),  INT16_C( 27049),  INT16_C( 21519) },
        { { -INT16_C( 29161), -INT16_C(  6358), -INT16_C(  5529),  INT16_C(  7212), -INT16_C( 18928),  INT16_C(  8337), -INT16_C( 27298),  INT16_C(  7349) },
          {  INT16_C( 25669),  INT16_C( 27049),  INT16_C( 28641),  INT16_C(   340), -INT16_C( 15164),  INT16_C( 27185),  INT16_C( 24337),  INT16_C( 10324) },
          {  INT16_C( 32493),  INT16_C( 21519),  INT16_C( 15465),  INT16_C( 31088),  INT16_C(   754),  INT16_C( 20633),  INT16_C( 20119), -INT16_C(  9108) } },
       INT32_C(           1) },
    { { -INT16_C( 25980), -INT16_C(  9757),  INT16_C( 11567) },
        { {  INT16_C(  5555), -INT16_C( 27578), -INT16_C( 25980),  INT16_C( 18838), -INT16_C( 14498),  INT16_C( 28595),  INT16_C(  1830),  INT16_C(  5271) },
          { -INT16_C( 22651), -INT16_C(  4504), -INT16_C(  9757), -INT16_C( 10905),  INT16_C(   475),  INT16_C( 29221), -INT16_C( 28337),  INT16_C(   591) },
          { -INT16_C( 27226),  INT16_C( 11159),  INT16_C( 11567), -INT16_C( 29068),  INT16_C( 10228),  INT16_C(  7165), -INT16_C( 27346), -INT16_C( 19665) } },
       INT32_C(           2) },
    { {  INT16_C( 19444),  INT16_C(  5471), -INT16_C( 20814) },
        { { -INT16_C( 26820),  INT16_C(  8098),  INT16_C(  2416),  INT16_C( 19444),  INT16_C(  6410),  INT16_C( 23230),  INT16_C(  3498),  INT16_C( 20572) },
          { -INT16_C(  3166), -INT16_C( 11909), -INT16_C(  4320),  INT16_C(  5471),  INT16_C( 23830),  INT16_C( 17456),  INT16_C( 24562),  INT16_C( 12024) },
          { -INT16_C( 25866),  INT16_C( 26445),  INT16_C( 16803), -INT16_C( 20814),  INT16_C( 28762),  INT16_C(  1032),  INT16_C( 25725),  INT16_C(  8020) } },
       INT32_C(           3) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8x3_t val = {{simde_vld1q_s16(test_vec[i].val[0]),
                              simde_vld1q_s16(test_vec[i].val[1]),
                              simde_vld1q_s16(test_vec[i].val[2])}};
    int16_t a[3];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3q_lane_s16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i16(a[0], test_vec[i].a[0]);
    simde_assert_equal_i16(a[1], test_vec[i].a[1]);
    simde_assert_equal_i16(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    int16_t a[3];
    simde_int16x8x3_t val = simde_test_arm_neon_random_i16x8x3();
    const int lane = lanes[i];
    simde_vst3q_lane_s16(a, val, lane);

    simde_test_codegen_write_vi16(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[3];
    int32_t val[3][4];
    int lane;
  } test_vec[] = {
    { {  INT32_C(  1379578233), -INT32_C(  1506301715), -INT32_C(   401259582) },
        { {  INT32_C(  1379578233),  INT32_C(  1139395877), -INT32_C(   167530427),  INT32_C(  1003898180) },
          { -INT32_C(  1506301715), -INT32_C(   269025980), -INT32_C(   871311129), -INT32_C(  1022815927) },
          { -INT32_C(   401259582),  INT32_C(  1445723665), -INT32_C(   229888338),  INT32_C(  1630348147) } },
       INT32_C(           0) },
    { {  INT32_C(  1241447778), -INT32_C(  1530268170), -INT32_C(   757788164) },
        { {  INT32_C(   252143051),  INT32_C(  1241447778),  INT32_C(   521474006), -INT32_C(   488497632) },
          {  INT32_C(  1942681442), -INT32_C(  1530268170), -INT32_C(  1751706077),  INT32_C(    83412025) },
          { -INT32_C(  1944846551), -INT32_C(   757788164),  INT32_C(  1089661728),  INT32_C(  1797510153) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4x3_t val = {{simde_vld1q_s32(test_vec[i].val[0]),
                              simde_vld1q_s32(test_vec[i].val[1]),
                              simde_vld1q_s32(test_vec[i].val[2])}};
    int32_t a[3];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst3q_lane_s32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_i32(a[0], test_vec[i].a[0]);
    simde_assert_equal_i32(a[1], test_vec[i].a[1]);
    simde_assert_equal_i32(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a[3];
    simde_int32x4x3_t val = simde_test_arm_neon_random_i32x4x3();
    const int lane = lanes[i];
    simde_vst3q_lane_s32(a, val, lane);

    simde_test_codegen_write_vi32(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[3];
    int64_t val[3][2];
    int lane;
  } test_vec[] = {
    { { -INT64_C( 5120652558463441272), -INT64_C( 7898967772028435522),  INT64_C( 4696676503986084820) },
        { { -INT64_C( 5120652558463441272),  INT64_C( 2138740331392256732) },
          { -INT64_C( 7898967772028435522),  INT64_C( 2307090508662098180) },
          {  INT64_C( 4696676503986084820), -INT64_C( 5847388719539512131) } },
       INT32_C(           0) },
    { {  INT64_C( 7061699804944736071), -INT64_C(  270699133269988192),  INT64_C( 7981788802446421716) },
        { {  INT64_C( 1487733855126148458),  INT64_C( 7061699804944736071) },
          { -INT64_C( 5516059663137307699), -INT64_C(  270699133269988192) },
          {  INT64_C( 2468454019439221789),  INT64_C( 7981788802446421716) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2x3_t val = {{simde_vld1q_s64(test_vec[i].val[0]),
                              simde_vld1q_s64(test_vec[i].val[1]),
                              simde_vld1q_s64(test_vec[i].val[2])}};
    int64_t a[3];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3q_lane_s64, HEDLEY_UNREACHABLE(), test_vec[i].lane, a, val);

    simde_assert_equal_i64(a[0], test_vec[i].a[0]);
    simde_assert_equal_i64(a[1], test_vec[i].a[1]);
    simde_assert_equal_i64(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    int64_t a[3];
    simde_int64x2x3_t val = simde_test_arm_neon_random_i64x2x3();
    const int lane = lanes[i];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3q_lane_s64, HEDLEY_UNREACHABLE(), lane, a, val);

    simde_test_codegen_write_vi64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[3];
    uint8_t val[3][16];
    int lane;
  } test_vec[] = {
    { { UINT8_C( 72), UINT8_C(  5), UINT8_C(149) },
        { { UINT8_C( 72), UINT8_C(188), UINT8_C(109), UINT8_C( 18), UINT8_C(242), UINT8_C(226), UINT8_C( 91), UINT8_C(152),
            UINT8_C(134), UINT8_C(  2), UINT8_C( 16), UINT8_C( 90), UINT8_C(202), UINT8_C(132), UINT8_C(216), UINT8_C(209) },
          { UINT8_C(  5), UINT8_C(223), UINT8_C(132), UINT8_C(164), UINT8_C( 60), UINT8_C(180), UINT8_C(172), UINT8_C(183),
            UINT8_C( 45), UINT8_C(228), UINT8_C(  3), UINT8_C(203), UINT8_C(123), UINT8_C(217), UINT8_C( 72), UINT8_C(195) },
          { UINT8_C(149), UINT8_C(182), UINT8_C(214), UINT8_C(135), UINT8_C(152), UINT8_C( 49), UINT8_C( 32), UINT8_C( 30),
            UINT8_C( 51), UINT8_C( 48), UINT8_C(120), UINT8_C(253), UINT8_C(180), UINT8_C( 80), UINT8_C(206), UINT8_C(186) } },
       INT32_C(           0) },
    { { UINT8_C( 82), UINT8_C(  4), UINT8_C( 56) },
        { { UINT8_C( 48), UINT8_C( 82), UINT8_C( 94), UINT8_C(108), UINT8_C(  6), UINT8_C( 10), UINT8_C( 35), UINT8_C( 51),
            UINT8_C(239), UINT8_C( 38), UINT8_C(254), UINT8_C(106),    UINT8_MAX, UINT8_C( 71), UINT8_C( 46), UINT8_C(148) },
          { UINT8_C(253), UINT8_C(  4), UINT8_C( 27), UINT8_C(149), UINT8_C( 53), UINT8_C( 59), UINT8_C(180), UINT8_C(105),
            UINT8_C(107), UINT8_C( 44), UINT8_C(102), UINT8_C( 32), UINT8_C(125), UINT8_C( 53), UINT8_C(218), UINT8_C(173) },
          { UINT8_C(135), UINT8_C( 56), UINT8_C( 25), UINT8_C(142), UINT8_C( 66), UINT8_C( 60), UINT8_C(193), UINT8_C( 49),
            UINT8_C( 98), UINT8_C(192), UINT8_C(156), UINT8_C( 97), UINT8_C(  7), UINT8_C(202), UINT8_C(245), UINT8_C(  4) } },
       INT32_C(           1) },
    { { UINT8_C(153), UINT8_C( 29), UINT8_C(149) },
        { { UINT8_C(206), UINT8_C( 16), UINT8_C(153), UINT8_C(  3), UINT8_C( 76), UINT8_C( 77), UINT8_C(108), UINT8_C(183),
            UINT8_C(122), UINT8_C(211), UINT8_C(215), UINT8_C(247), UINT8_C(  8), UINT8_C(177), UINT8_C(164), UINT8_C(143) },
          { UINT8_C(233), UINT8_C(189), UINT8_C( 29), UINT8_C( 44), UINT8_C(249), UINT8_C(223), UINT8_C( 93), UINT8_C( 91),
            UINT8_C(159), UINT8_C(249), UINT8_C(188), UINT8_C(166), UINT8_C(195), UINT8_C(177), UINT8_C(170), UINT8_C(145) },
          { UINT8_C(193), UINT8_C( 67), UINT8_C(149), UINT8_C( 13), UINT8_C(145), UINT8_C(  1), UINT8_C(197), UINT8_C( 11),
            UINT8_C(212), UINT8_C(156), UINT8_C(  2), UINT8_C(220), UINT8_C( 78), UINT8_C(166), UINT8_C(108), UINT8_C( 55) } },
       INT32_C(           2) },
    { { UINT8_C( 92), UINT8_C( 44), UINT8_C(181) },
        { { UINT8_C( 99), UINT8_C(137), UINT8_C( 99), UINT8_C( 92), UINT8_C(104), UINT8_C(193), UINT8_C(183), UINT8_C(  7),
            UINT8_C(186), UINT8_C(115), UINT8_C(173), UINT8_C(126), UINT8_C( 36), UINT8_C( 87), UINT8_C( 15), UINT8_C(229) },
          { UINT8_C(155), UINT8_C(164), UINT8_C(243), UINT8_C( 44), UINT8_C(166), UINT8_C(184), UINT8_C( 55), UINT8_C(122),
            UINT8_C( 84), UINT8_C( 57), UINT8_C( 87), UINT8_C(162), UINT8_C(223), UINT8_C(195), UINT8_C(218), UINT8_C( 66) },
          { UINT8_C( 76), UINT8_C( 61), UINT8_C(158), UINT8_C(181), UINT8_C(254), UINT8_C( 85), UINT8_C(188), UINT8_C(185),
            UINT8_C(200), UINT8_C(106), UINT8_C( 55), UINT8_C(236), UINT8_C(193), UINT8_C( 70), UINT8_C(209), UINT8_C( 92) } },
       INT32_C(           3) },
    { { UINT8_C(124), UINT8_C( 12), UINT8_C(179) },
        { { UINT8_C(235), UINT8_C(196), UINT8_C(136), UINT8_C(145), UINT8_C(124), UINT8_C(191), UINT8_C( 11), UINT8_C(209),
            UINT8_C(248), UINT8_C( 98), UINT8_C(115), UINT8_C(215), UINT8_C( 37), UINT8_C( 77), UINT8_C( 25), UINT8_C(114) },
          { UINT8_C(139), UINT8_C(183), UINT8_C( 39), UINT8_C(137), UINT8_C( 12), UINT8_C(227), UINT8_C( 66), UINT8_C(212),
            UINT8_C( 77), UINT8_C(121), UINT8_C(192), UINT8_C( 15), UINT8_C(192), UINT8_C(146), UINT8_C(107), UINT8_C(171) },
          { UINT8_C( 86), UINT8_C(244), UINT8_C( 60), UINT8_C(211), UINT8_C(179), UINT8_C( 71), UINT8_C(164), UINT8_C(172),
            UINT8_C(170), UINT8_C( 23), UINT8_C(131), UINT8_C(207), UINT8_C(101), UINT8_C(157), UINT8_C( 65), UINT8_C(240) } },
       INT32_C(           4) },
    { { UINT8_C(188), UINT8_C( 85), UINT8_C(115) },
        { { UINT8_C( 84), UINT8_C(104), UINT8_C(121), UINT8_C( 97), UINT8_C( 76), UINT8_C(188), UINT8_C( 53), UINT8_C(153),
            UINT8_C( 53), UINT8_C(246), UINT8_C(168), UINT8_C(245), UINT8_C(136), UINT8_C( 20), UINT8_C(160), UINT8_C(222) },
          { UINT8_C(  8), UINT8_C(220), UINT8_C(177), UINT8_C(187), UINT8_C( 36), UINT8_C( 85), UINT8_C(103), UINT8_C(206),
            UINT8_C(109), UINT8_C(235), UINT8_C(157), UINT8_C(210), UINT8_C(136), UINT8_C(223), UINT8_C(194), UINT8_C(220) },
          { UINT8_C( 71), UINT8_C( 59), UINT8_C( 61), UINT8_C(147), UINT8_C(247), UINT8_C(115), UINT8_C( 45), UINT8_C( 45),
            UINT8_C(105), UINT8_C(213), UINT8_C( 34), UINT8_C(241), UINT8_C(233), UINT8_C(195), UINT8_C(207), UINT8_C(241) } },
       INT32_C(           5) },
    { { UINT8_C(145), UINT8_C( 55), UINT8_C(217) },
        { { UINT8_C(159), UINT8_C(129), UINT8_C(173), UINT8_C(195), UINT8_C(214), UINT8_C( 20), UINT8_C(145), UINT8_C( 67),
               UINT8_MAX, UINT8_C( 47), UINT8_C( 21), UINT8_C(135), UINT8_C( 14), UINT8_C(215), UINT8_C(100), UINT8_C( 85) },
          { UINT8_C( 19), UINT8_C(161), UINT8_C(233), UINT8_C( 10), UINT8_C( 20), UINT8_C( 22), UINT8_C( 55), UINT8_C(125),
            UINT8_C(235), UINT8_C( 90), UINT8_C(110), UINT8_C(213), UINT8_C( 29), UINT8_C( 62), UINT8_C(198), UINT8_C(188) },
          { UINT8_C(191), UINT8_C(115), UINT8_C(128), UINT8_C(149), UINT8_C(136), UINT8_C( 17), UINT8_C(217), UINT8_C(135),
            UINT8_C( 64), UINT8_C(238), UINT8_C( 15), UINT8_C( 78), UINT8_C(198), UINT8_C(115), UINT8_C(164), UINT8_C(217) } },
       INT32_C(           6) },
    { { UINT8_C(142), UINT8_C( 32), UINT8_C(129) },
        { { UINT8_C( 20), UINT8_C(141), UINT8_C(227), UINT8_C( 41), UINT8_C(163), UINT8_C( 27), UINT8_C(166), UINT8_C(142),
            UINT8_C(117), UINT8_C( 21), UINT8_C( 99), UINT8_C(146), UINT8_C( 83), UINT8_C( 42), UINT8_C( 78), UINT8_C( 18) },
          { UINT8_C(157), UINT8_C(206), UINT8_C(167), UINT8_C( 37), UINT8_C(224), UINT8_C(128), UINT8_C(173), UINT8_C( 32),
            UINT8_C(111), UINT8_C(188), UINT8_C(111), UINT8_C( 53), UINT8_C( 47), UINT8_C( 19), UINT8_C( 14), UINT8_C( 67) },
          { UINT8_C(160), UINT8_C(241), UINT8_C(108), UINT8_C( 67), UINT8_C( 12), UINT8_C( 19), UINT8_C(209), UINT8_C(129),
            UINT8_C( 40), UINT8_C( 53), UINT8_C( 19), UINT8_C(123), UINT8_C( 95), UINT8_C( 98), UINT8_C(141), UINT8_C(252) } },
       INT32_C(           7) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16x3_t val = {{simde_vld1q_u8(test_vec[i].val[0]),
                             simde_vld1q_u8(test_vec[i].val[1]),
                             simde_vld1q_u8(test_vec[i].val[2])}};
    uint8_t a[3];
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst3q_lane_u8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u8(a[0], test_vec[i].a[0]);
    simde_assert_equal_u8(a[1], test_vec[i].a[1]);
    simde_assert_equal_u8(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a[3];
    simde_uint8x16x3_t val = simde_test_arm_neon_random_u8x16x3();
    const int lane = lanes[i];
    simde_vst3q_lane_u8(a, val, lane);

    simde_test_codegen_write_vu8(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[3];
    uint16_t val[3][8];
    int lane;
  } test_vec[] = {
    { { UINT16_C( 4358), UINT16_C(45621), UINT16_C(43180) },
        { { UINT16_C( 4358), UINT16_C(52346), UINT16_C(19773), UINT16_C(65303), UINT16_C( 8856), UINT16_C(22134), UINT16_C( 6774), UINT16_C( 4144) },
          { UINT16_C(45621), UINT16_C(48866), UINT16_C(36301), UINT16_C(59806), UINT16_C(47730), UINT16_C(55782), UINT16_C(39907), UINT16_C(59950) },
          { UINT16_C(43180), UINT16_C(60086), UINT16_C(52725), UINT16_C(36585), UINT16_C(24559), UINT16_C(26340), UINT16_C( 5242), UINT16_C(44918) } },
       INT32_C(           0) },
    { { UINT16_C(37997), UINT16_C(65173), UINT16_C( 8671) },
        { { UINT16_C(22982), UINT16_C(37997), UINT16_C( 3046), UINT16_C(22653), UINT16_C(25541), UINT16_C(43314), UINT16_C(24830), UINT16_C(43923) },
          { UINT16_C(18697), UINT16_C(65173), UINT16_C(32278), UINT16_C( 1676), UINT16_C(28894), UINT16_C(22636), UINT16_C(57988), UINT16_C(19207) },
          { UINT16_C(29755), UINT16_C( 8671), UINT16_C(23680), UINT16_C(17786), UINT16_C(44224), UINT16_C(48878), UINT16_C(33036), UINT16_C( 5481) } },
       INT32_C(           1) },
    { { UINT16_C(41085), UINT16_C( 3100), UINT16_C(63119) },
        { { UINT16_C(65226), UINT16_C(57620), UINT16_C(41085), UINT16_C(23527), UINT16_C(21265), UINT16_C(38323), UINT16_C(47669), UINT16_C(29152) },
          { UINT16_C(48942), UINT16_C(44690), UINT16_C( 3100), UINT16_C(56564), UINT16_C(58040), UINT16_C(50586), UINT16_C( 1124), UINT16_C(11994) },
          { UINT16_C(60930), UINT16_C(32527), UINT16_C(63119), UINT16_C(41178), UINT16_C(36169), UINT16_C(32565), UINT16_C( 5703), UINT16_C(30448) } },
       INT32_C(           2) },
    { { UINT16_C(18381), UINT16_C(56580), UINT16_C(19365) },
        { { UINT16_C(33493), UINT16_C(61732), UINT16_C( 6287), UINT16_C(18381), UINT16_C(26875), UINT16_C(24332), UINT16_C(59244), UINT16_C(28301) },
          { UINT16_C(40405), UINT16_C(25838), UINT16_C(51347), UINT16_C(56580), UINT16_C(14934), UINT16_C(40284), UINT16_C(19536), UINT16_C( 9491) },
          { UINT16_C(14542), UINT16_C(23831), UINT16_C(58448), UINT16_C(19365), UINT16_C(45388), UINT16_C(47274), UINT16_C(14488), UINT16_C(28199) } },
       INT32_C(           3) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8x3_t val = {{simde_vld1q_u16(test_vec[i].val[0]),
                              simde_vld1q_u16(test_vec[i].val[1]),
                              simde_vld1q_u16(test_vec[i].val[2])}};
    uint16_t a[3];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3q_lane_u16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u16(a[0], test_vec[i].a[0]);
    simde_assert_equal_u16(a[1], test_vec[i].a[1]);
    simde_assert_equal_u16(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    uint16_t a[3];
    simde_uint16x8x3_t val = simde_test_arm_neon_random_u16x8x3();
    const int lane = lanes[i];
    simde_vst3q_lane_u16(a, val, lane);

    simde_test_codegen_write_vu16(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[3];
    uint32_t val[3][4];
    int lane;
  } test_vec[] = {
    { { UINT32_C(4245526618), UINT32_C( 296530267), UINT32_C(3726671930) },
        { { UINT32_C(4245526618), UINT32_C(1472855460), UINT32_C(3972331738), UINT32_C(3530275023) },
          { UINT32_C( 296530267), UINT32_C(3321195609), UINT32_C( 337617397), UINT32_C( 594780873) },
          { UINT32_C(3726671930), UINT32_C(1463150973), UINT32_C(2974087906), UINT32_C( 226799538) } },
       INT32_C(           0) },
    { { UINT32_C(2441024412), UINT32_C(2356055722), UINT32_C( 790625146) },
        { { UINT32_C(3122540640), UINT32_C(2441024412), UINT32_C(2108006324), UINT32_C(2074089537) },
          { UINT32_C( 374981017), UINT32_C(2356055722), UINT32_C( 993964680), UINT32_C(3259548257) },
          { UINT32_C(2390517746), UINT32_C( 790625146), UINT32_C(3685533082), UINT32_C(1985367517) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4x3_t val = {{simde_vld1q_u32(test_vec[i].val[0]),
                              simde_vld1q_u32(test_vec[i].val[1]),
                              simde_vld1q_u32(test_vec[i].val[2])}};
    uint32_t a[3];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst3q_lane_u32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_u32(a[0], test_vec[i].a[0]);
    simde_assert_equal_u32(a[1], test_vec[i].a[1]);
    simde_assert_equal_u32(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    uint32_t a[3];
    simde_uint32x4x3_t val = simde_test_arm_neon_random_u32x4x3();
    const int lane = lanes[i];
    simde_vst3q_lane_u32(a, val, lane);

    simde_test_codegen_write_vu32(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[3];
    uint64_t val[3][2];
    int lane;
  } test_vec[] = {
    { { UINT64_C(12898659581318511290), UINT64_C(  500302278456964456), UINT64_C( 3201079187964383532) },
       { { UINT64_C(12898659581318511290), UINT64_C( 1443322119720072349) },
         { UINT64_C(  500302278456964456), UINT64_C(17015850850943128150) },
         { UINT64_C( 3201079187964383532), UINT64_C(16888312240960162936) } },
      INT32_C(           0) },
   { { UINT64_C(12956845716471420337), UINT64_C(17514489777424454308), UINT64_C(10550314667189752879) },
       { { UINT64_C(16255566433045257547), UINT64_C(12956845716471420337) },
         { UINT64_C( 5621575177120535111), UINT64_C(17514489777424454308) },
         { UINT64_C(10196460566231612692), UINT64_C(10550314667189752879) } },
      INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2x3_t val = {{simde_vld1q_u64(test_vec[i].val[0]),
                              simde_vld1q_u64(test_vec[i].val[1]),
                              simde_vld1q_u64(test_vec[i].val[2])}};
    uint64_t a[3];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3q_lane_u64, HEDLEY_UNREACHABLE(), test_vec[i].lane, a, val);

    simde_assert_equal_u64(a[0], test_vec[i].a[0]);
    simde_assert_equal_u64(a[1], test_vec[i].a[1]);
    simde_assert_equal_u64(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    uint64_t a[3];
    simde_uint64x2x3_t val = simde_test_arm_neon_random_u64x2x3();
    const int lane = lanes[i];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3q_lane_u64, HEDLEY_UNREACHABLE(), lane, a, val);

    simde_test_codegen_write_vu64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[3];
    simde_float16_t val[3][8];
    int lane;
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE( 56.833),  SIMDE_FLOAT16_VALUE( 73.442), SIMDE_FLOAT16_VALUE( - 22.618) },
    { {  SIMDE_FLOAT16_VALUE( 90.228),  SIMDE_FLOAT16_VALUE(  1.415), SIMDE_FLOAT16_VALUE( - 54.694),  SIMDE_FLOAT16_VALUE( 41.258),
         SIMDE_FLOAT16_VALUE( 74.577),  SIMDE_FLOAT16_VALUE( 13.483),  SIMDE_FLOAT16_VALUE( 56.833),  SIMDE_FLOAT16_VALUE( 68.200)  },
      { SIMDE_FLOAT16_VALUE( - 65.650), SIMDE_FLOAT16_VALUE( - 68.388), SIMDE_FLOAT16_VALUE( - 13.278), SIMDE_FLOAT16_VALUE( - 65.890),
         SIMDE_FLOAT16_VALUE( 16.926), SIMDE_FLOAT16_VALUE( - 26.315),  SIMDE_FLOAT16_VALUE( 73.442),  SIMDE_FLOAT16_VALUE( 26.641)  },
      { SIMDE_FLOAT16_VALUE( - 42.649),  SIMDE_FLOAT16_VALUE( 80.336),  SIMDE_FLOAT16_VALUE( 27.756),  SIMDE_FLOAT16_VALUE(  8.267),
         SIMDE_FLOAT16_VALUE( 24.942),  SIMDE_FLOAT16_VALUE( 96.066), SIMDE_FLOAT16_VALUE( - 22.618), SIMDE_FLOAT16_VALUE( - 58.346)  } },
         INT8_C(      6) },
    { { SIMDE_FLOAT16_VALUE( - 74.185), SIMDE_FLOAT16_VALUE( - 78.069), SIMDE_FLOAT16_VALUE( - 86.364) },
    { { SIMDE_FLOAT16_VALUE( - 69.189), SIMDE_FLOAT16_VALUE( - 74.185),  SIMDE_FLOAT16_VALUE(  5.043), SIMDE_FLOAT16_VALUE( - 18.088),
         SIMDE_FLOAT16_VALUE( 14.723),  SIMDE_FLOAT16_VALUE(  9.202),  SIMDE_FLOAT16_VALUE( 78.389), SIMDE_FLOAT16_VALUE( - 87.305)  },
      { SIMDE_FLOAT16_VALUE( - 12.507), SIMDE_FLOAT16_VALUE( - 78.069), SIMDE_FLOAT16_VALUE( - 96.953), SIMDE_FLOAT16_VALUE( - 96.401),
         SIMDE_FLOAT16_VALUE( 42.165),  SIMDE_FLOAT16_VALUE( 75.353), SIMDE_FLOAT16_VALUE( - 82.128),  SIMDE_FLOAT16_VALUE( 17.448)  },
      {  SIMDE_FLOAT16_VALUE( 57.653), SIMDE_FLOAT16_VALUE( - 86.364),  SIMDE_FLOAT16_VALUE( 30.786), SIMDE_FLOAT16_VALUE( - 50.101),
         SIMDE_FLOAT16_VALUE( 60.669), SIMDE_FLOAT16_VALUE( - 26.173),  SIMDE_FLOAT16_VALUE( 10.148), SIMDE_FLOAT16_VALUE( - 92.619)  } },
         INT8_C(      1) },
    { { SIMDE_FLOAT16_VALUE( - 30.210), SIMDE_FLOAT16_VALUE( - 13.667), SIMDE_FLOAT16_VALUE( - 47.603) },
    { { SIMDE_FLOAT16_VALUE( - 96.908), SIMDE_FLOAT16_VALUE( - 14.691),  SIMDE_FLOAT16_VALUE( 67.605),  SIMDE_FLOAT16_VALUE( 52.785),
         SIMDE_FLOAT16_VALUE( 10.770),  SIMDE_FLOAT16_VALUE( 49.923),  SIMDE_FLOAT16_VALUE( 79.174), SIMDE_FLOAT16_VALUE( - 30.210)  },
      { SIMDE_FLOAT16_VALUE( - 86.230), SIMDE_FLOAT16_VALUE( - 40.180),  SIMDE_FLOAT16_VALUE( 81.322), SIMDE_FLOAT16_VALUE( -  4.303),
        SIMDE_FLOAT16_VALUE( - 25.810),  SIMDE_FLOAT16_VALUE( 19.169), SIMDE_FLOAT16_VALUE( -  7.542), SIMDE_FLOAT16_VALUE( - 13.667)  },
      {  SIMDE_FLOAT16_VALUE( 48.690), SIMDE_FLOAT16_VALUE( - 84.400), SIMDE_FLOAT16_VALUE( - 42.388), SIMDE_FLOAT16_VALUE( - 71.989),
         SIMDE_FLOAT16_VALUE( 81.668),  SIMDE_FLOAT16_VALUE( 61.074),  SIMDE_FLOAT16_VALUE( 68.365), SIMDE_FLOAT16_VALUE( - 47.603)  } },
         INT8_C(      7) },
    { { SIMDE_FLOAT16_VALUE( - 74.022),  SIMDE_FLOAT16_VALUE( 72.818),  SIMDE_FLOAT16_VALUE( 75.403) },
    { {  SIMDE_FLOAT16_VALUE( 65.684),  SIMDE_FLOAT16_VALUE( 92.561), SIMDE_FLOAT16_VALUE( - 76.038),  SIMDE_FLOAT16_VALUE( 75.659),
        SIMDE_FLOAT16_VALUE( - 74.022),  SIMDE_FLOAT16_VALUE( 74.037), SIMDE_FLOAT16_VALUE( - 67.037),  SIMDE_FLOAT16_VALUE( 61.026)  },
      {  SIMDE_FLOAT16_VALUE( 43.862), SIMDE_FLOAT16_VALUE( - 42.260), SIMDE_FLOAT16_VALUE( -  8.530),  SIMDE_FLOAT16_VALUE( 15.388),
         SIMDE_FLOAT16_VALUE( 72.818), SIMDE_FLOAT16_VALUE( -  3.493),  SIMDE_FLOAT16_VALUE( 29.692),  SIMDE_FLOAT16_VALUE( 78.968)  },
      { SIMDE_FLOAT16_VALUE( - 91.120),  SIMDE_FLOAT16_VALUE( 22.041), SIMDE_FLOAT16_VALUE( - 61.013), SIMDE_FLOAT16_VALUE( - 71.187),
         SIMDE_FLOAT16_VALUE( 75.403),  SIMDE_FLOAT16_VALUE( 95.292),  SIMDE_FLOAT16_VALUE( 21.707), SIMDE_FLOAT16_VALUE( - 88.034)  } },
         INT8_C(      4) },
    { {  SIMDE_FLOAT16_VALUE( 66.250),  SIMDE_FLOAT16_VALUE( 86.996), SIMDE_FLOAT16_VALUE( - 40.809) },
    { {  SIMDE_FLOAT16_VALUE( 56.098), SIMDE_FLOAT16_VALUE( - 69.469), SIMDE_FLOAT16_VALUE( - 38.141),  SIMDE_FLOAT16_VALUE( 95.730),
         SIMDE_FLOAT16_VALUE( 66.250),  SIMDE_FLOAT16_VALUE( 88.246), SIMDE_FLOAT16_VALUE( - 73.861),  SIMDE_FLOAT16_VALUE( 88.929)  },
      {  SIMDE_FLOAT16_VALUE( 91.342),  SIMDE_FLOAT16_VALUE( 25.976),  SIMDE_FLOAT16_VALUE( 27.770),  SIMDE_FLOAT16_VALUE( 57.030),
         SIMDE_FLOAT16_VALUE( 86.996),  SIMDE_FLOAT16_VALUE( 24.429),  SIMDE_FLOAT16_VALUE( 36.571),  SIMDE_FLOAT16_VALUE( 25.024)  },
      { SIMDE_FLOAT16_VALUE( - 51.937),  SIMDE_FLOAT16_VALUE(  0.024),  SIMDE_FLOAT16_VALUE( 26.121),  SIMDE_FLOAT16_VALUE( 82.133),
        SIMDE_FLOAT16_VALUE( - 40.809), SIMDE_FLOAT16_VALUE( - 89.179), SIMDE_FLOAT16_VALUE( - 45.771), SIMDE_FLOAT16_VALUE( - 76.817)  } },
         INT8_C(      4) },
    { {  SIMDE_FLOAT16_VALUE( 41.869), SIMDE_FLOAT16_VALUE( - 27.827), SIMDE_FLOAT16_VALUE( - 92.856) },
    { { SIMDE_FLOAT16_VALUE( - 35.175),  SIMDE_FLOAT16_VALUE( 47.619),  SIMDE_FLOAT16_VALUE( 41.869),  SIMDE_FLOAT16_VALUE( 17.848),
        SIMDE_FLOAT16_VALUE( - 56.188), SIMDE_FLOAT16_VALUE( - 50.409),  SIMDE_FLOAT16_VALUE( 65.876), SIMDE_FLOAT16_VALUE( - 32.688)  },
      {  SIMDE_FLOAT16_VALUE(  3.311), SIMDE_FLOAT16_VALUE( - 49.604), SIMDE_FLOAT16_VALUE( - 27.827), SIMDE_FLOAT16_VALUE( -  2.760),
         SIMDE_FLOAT16_VALUE( 20.012),  SIMDE_FLOAT16_VALUE( 66.946),  SIMDE_FLOAT16_VALUE( 31.788), SIMDE_FLOAT16_VALUE( - 52.736)  },
      { SIMDE_FLOAT16_VALUE( - 93.576),  SIMDE_FLOAT16_VALUE(  4.057), SIMDE_FLOAT16_VALUE( - 92.856),  SIMDE_FLOAT16_VALUE( 68.167),
        SIMDE_FLOAT16_VALUE( - 17.311), SIMDE_FLOAT16_VALUE( - 69.405),  SIMDE_FLOAT16_VALUE( 82.245), SIMDE_FLOAT16_VALUE( -  7.897)  } },
         INT8_C(      2) },
    { {  SIMDE_FLOAT16_VALUE( 84.635), SIMDE_FLOAT16_VALUE( - 34.646), SIMDE_FLOAT16_VALUE( - 57.874) },
    { {  SIMDE_FLOAT16_VALUE( 81.549), SIMDE_FLOAT16_VALUE( -  2.028),  SIMDE_FLOAT16_VALUE( 84.635), SIMDE_FLOAT16_VALUE( - 29.533),
        SIMDE_FLOAT16_VALUE( - 38.208),  SIMDE_FLOAT16_VALUE( 73.008),  SIMDE_FLOAT16_VALUE( 35.951), SIMDE_FLOAT16_VALUE( - 30.779)  },
      {  SIMDE_FLOAT16_VALUE( 42.215), SIMDE_FLOAT16_VALUE( - 27.247), SIMDE_FLOAT16_VALUE( - 34.646), SIMDE_FLOAT16_VALUE( -  1.564),
         SIMDE_FLOAT16_VALUE( 71.796), SIMDE_FLOAT16_VALUE( - 51.547),  SIMDE_FLOAT16_VALUE( 32.523), SIMDE_FLOAT16_VALUE( - 43.421)  },
      {  SIMDE_FLOAT16_VALUE(  0.439),  SIMDE_FLOAT16_VALUE( 13.866), SIMDE_FLOAT16_VALUE( - 57.874), SIMDE_FLOAT16_VALUE( - 87.206),
        SIMDE_FLOAT16_VALUE( - 61.660),  SIMDE_FLOAT16_VALUE( 80.530), SIMDE_FLOAT16_VALUE( - 56.810), SIMDE_FLOAT16_VALUE( - 20.126)  } },
         INT8_C(      2) },
    { { SIMDE_FLOAT16_VALUE( - 78.288),  SIMDE_FLOAT16_VALUE( 36.942),  SIMDE_FLOAT16_VALUE( 21.455) },
    { { SIMDE_FLOAT16_VALUE( -  1.116),  SIMDE_FLOAT16_VALUE( 88.525), SIMDE_FLOAT16_VALUE( - 54.747),  SIMDE_FLOAT16_VALUE( 70.086),
        SIMDE_FLOAT16_VALUE( -  0.981), SIMDE_FLOAT16_VALUE( - 78.288), SIMDE_FLOAT16_VALUE( - 64.328),  SIMDE_FLOAT16_VALUE( 72.247)  },
      {  SIMDE_FLOAT16_VALUE( 50.505),  SIMDE_FLOAT16_VALUE( 62.460),  SIMDE_FLOAT16_VALUE( 55.021),  SIMDE_FLOAT16_VALUE( 63.023),
         SIMDE_FLOAT16_VALUE( 46.784),  SIMDE_FLOAT16_VALUE( 36.942), SIMDE_FLOAT16_VALUE( - 96.105), SIMDE_FLOAT16_VALUE( - 30.818)  },
      { SIMDE_FLOAT16_VALUE( - 28.408), SIMDE_FLOAT16_VALUE( - 39.921),  SIMDE_FLOAT16_VALUE(  8.839), SIMDE_FLOAT16_VALUE( - 70.832),
         SIMDE_FLOAT16_VALUE( 33.768),  SIMDE_FLOAT16_VALUE( 21.455), SIMDE_FLOAT16_VALUE( - 89.062),  SIMDE_FLOAT16_VALUE( 97.215)  } },
         INT8_C(      5) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float16x8x3_t val = {{simde_vld1q_f16(test_vec[i].val[0]),
                               simde_vld1q_f16(test_vec[i].val[1]),
                               simde_vld1q_f16(test_vec[i].val[2])}};
    simde_float16_t a[3];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3q_lane_f16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_f16(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f16(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f16(a[2], test_vec[i].a[2], 1);
  }

  return 0;
}

static int
test_simde_vst3q_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[3];
    simde_float32_t val[3][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    52.99), SIMDE_FLOAT32_C(    86.46), SIMDE_FLOAT32_C(   -89.46) },
        { { SIMDE_FLOAT32_C(    52.99), SIMDE_FLOAT32_C(   -17.68), SIMDE_FLOAT32_C(    89.79), SIMDE_FLOAT32_C(   -47.89) },
          { SIMDE_FLOAT32_C(    86.46), SIMDE_FLOAT32_C(    86.93), SIMDE_FLOAT32_C(   -39.01), SIMDE_FLOAT32_C(    26.65) },
          { SIMDE_FLOAT32_C(   -89.46), SIMDE_FLOAT32_C(    -3.48), SIMDE_FLOAT32_C(    44.25), SIMDE_FLOAT32_C(    86.88) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT32_C(    80.11), SIMDE_FLOAT32_C(    59.12), SIMDE_FLOAT32_C(    37.68) },
        { { SIMDE_FLOAT32_C(    32.77), SIMDE_FLOAT32_C(    80.11), SIMDE_FLOAT32_C(   -33.81), SIMDE_FLOAT32_C(   -10.16) },
          { SIMDE_FLOAT32_C(    25.78), SIMDE_FLOAT32_C(    59.12), SIMDE_FLOAT32_C(    60.97), SIMDE_FLOAT32_C(    23.96) },
          { SIMDE_FLOAT32_C(    90.97), SIMDE_FLOAT32_C(    37.68), SIMDE_FLOAT32_C(    20.90), SIMDE_FLOAT32_C(   -85.54) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4x3_t val = {{simde_vld1q_f32(test_vec[i].val[0]),
                               simde_vld1q_f32(test_vec[i].val[1]),
                               simde_vld1q_f32(test_vec[i].val[2])}};
    simde_float32_t a[3];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst3q_lane_f32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_f32(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f32(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f32(a[2], test_vec[i].a[2], 1);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32_t a[3];
    simde_float32x4x3_t val = simde_test_arm_neon_random_f32x4x3(-100.0f, 100.0f);
    const int lane = lanes[i];
    simde_vst3q_lane_f32(a, val, lane);

    simde_test_codegen_write_vf32(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[3];
    simde_float64_t val[3][2];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    73.35), SIMDE_FLOAT64_C(   -88.49), SIMDE_FLOAT64_C(    36.60) },
        { { SIMDE_FLOAT64_C(    73.35), SIMDE_FLOAT64_C(   -12.64) },
          { SIMDE_FLOAT64_C(   -88.49), SIMDE_FLOAT64_C(    11.61) },
          { SIMDE_FLOAT64_C(    36.60), SIMDE_FLOAT64_C(   -46.96) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT64_C(    44.08), SIMDE_FLOAT64_C(    -5.73), SIMDE_FLOAT64_C(     9.48) },
        { { SIMDE_FLOAT64_C(   -78.09), SIMDE_FLOAT64_C(    44.08) },
          { SIMDE_FLOAT64_C(   -78.20), SIMDE_FLOAT64_C(    -5.73) },
          { SIMDE_FLOAT64_C(   -95.05), SIMDE_FLOAT64_C(     9.48) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2x3_t val = {{simde_vld1q_f64(test_vec[i].val[0]),
                              simde_vld1q_f64(test_vec[i].val[1]),
                              simde_vld1q_f64(test_vec[i].val[2])}};
    simde_float64_t a[3];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3q_lane_f64, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_f64(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f64(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_f64(a[2], test_vec[i].a[2], 1);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64_t a[3];
    simde_float64x2x3_t val = simde_test_arm_neon_random_f64x2x3(-100.0, 100.0);
    const int lane = lanes[i];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3q_lane_f64, HEDLEY_UNREACHABLE(),
                                lane, a, val);

    simde_test_codegen_write_vf64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[3];
    simde_poly8_t val[3][8];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY8_C(252), SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 62) },
        { { SIMDE_POLY8_C(252), SIMDE_POLY8_C(169), SIMDE_POLY8_C(185), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(153) },
          { SIMDE_POLY8_C( 37), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 58), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(247), SIMDE_POLY8_C( 15), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 84) },
          { SIMDE_POLY8_C( 62), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(204), SIMDE_POLY8_C(218), SIMDE_POLY8_C(173), SIMDE_POLY8_C(  5), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(206) } },
       INT32_C(           0) },
    { { SIMDE_POLY8_C(175), SIMDE_POLY8_C(158), SIMDE_POLY8_C( 13) },
        { { SIMDE_POLY8_C(194), SIMDE_POLY8_C(175), SIMDE_POLY8_C(250), SIMDE_POLY8_C(118), SIMDE_POLY8_C(192), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(229), SIMDE_POLY8_C(188) },
          { SIMDE_POLY8_C( 10), SIMDE_POLY8_C(158), SIMDE_POLY8_C(117), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(206), SIMDE_POLY8_C(199), SIMDE_POLY8_C(211), SIMDE_POLY8_C(243) },
          { SIMDE_POLY8_C(176), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 29), SIMDE_POLY8_C(195), SIMDE_POLY8_C(251), SIMDE_POLY8_C( 91) } },
       INT32_C(           1) },
    { { SIMDE_POLY8_C( 53), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(253) },
        { { SIMDE_POLY8_C(227), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(144), SIMDE_POLY8_C(204), SIMDE_POLY8_C( 99), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(142) },
          { SIMDE_POLY8_C( 18), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(210), SIMDE_POLY8_C(185), SIMDE_POLY8_C(234), SIMDE_POLY8_C(143), SIMDE_POLY8_C(195) },
          { SIMDE_POLY8_C(136), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(253), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(204), SIMDE_POLY8_C(208), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(124) } },
       INT32_C(           2) },
    { { SIMDE_POLY8_C(251), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 68) },
        { { SIMDE_POLY8_C(222), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 36), SIMDE_POLY8_C(251), SIMDE_POLY8_C( 95), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 66) },
          { SIMDE_POLY8_C(231), SIMDE_POLY8_C(139), SIMDE_POLY8_C(211), SIMDE_POLY8_C(179), SIMDE_POLY8_C(238), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(  0) },
          { SIMDE_POLY8_C(139), SIMDE_POLY8_C( 71), SIMDE_POLY8_C(211), SIMDE_POLY8_C( 68), SIMDE_POLY8_C( 49), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(  8), SIMDE_POLY8_C(185) } },
       INT32_C(           3) },
    { { SIMDE_POLY8_C(214), SIMDE_POLY8_C(242), SIMDE_POLY8_C(155) },
        { { SIMDE_POLY8_C(102), SIMDE_POLY8_C(  5), SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(214), SIMDE_POLY8_C( 88), SIMDE_POLY8_C(175), SIMDE_POLY8_C(180) },
          { SIMDE_POLY8_C(244), SIMDE_POLY8_C(211), SIMDE_POLY8_C(175), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(242), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(150), SIMDE_POLY8_C(217) },
          { SIMDE_POLY8_C(144), SIMDE_POLY8_C(105), SIMDE_POLY8_C(141), SIMDE_POLY8_C(127), SIMDE_POLY8_C(155), SIMDE_POLY8_C(207), SIMDE_POLY8_C(127), SIMDE_POLY8_C( 38) } },
       INT32_C(           4) },
    { { SIMDE_POLY8_C(115), SIMDE_POLY8_C(252), SIMDE_POLY8_C( 70) },
        { { SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 71), SIMDE_POLY8_C(180), SIMDE_POLY8_C(115), SIMDE_POLY8_C(  0), SIMDE_POLY8_C( 27) },
          { SIMDE_POLY8_C(120), SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(103), SIMDE_POLY8_C(252), SIMDE_POLY8_C(  2), SIMDE_POLY8_C( 91) },
          { SIMDE_POLY8_C(207), SIMDE_POLY8_C(177), SIMDE_POLY8_C(175), SIMDE_POLY8_C(194), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(155), SIMDE_POLY8_C( 71) } },
       INT32_C(           5) },
    { { SIMDE_POLY8_C(113), SIMDE_POLY8_C(103), SIMDE_POLY8_C( 38) },
        { { SIMDE_POLY8_C(175), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(198), SIMDE_POLY8_C( 75), SIMDE_POLY8_C(247), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 13) },
          { SIMDE_POLY8_C(152), SIMDE_POLY8_C(220), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 79), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(103), SIMDE_POLY8_C(200) },
          { SIMDE_POLY8_C( 99), SIMDE_POLY8_C(181), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(202), SIMDE_POLY8_C(177), SIMDE_POLY8_C( 25), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(129) } },
       INT32_C(           6) },
    { { SIMDE_POLY8_C(203), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 24) },
        { { SIMDE_POLY8_C(202), SIMDE_POLY8_C(213), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(222), SIMDE_POLY8_C(200), SIMDE_POLY8_C(203) },
          { SIMDE_POLY8_C(  7), SIMDE_POLY8_C(142), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(254), SIMDE_POLY8_C(211), SIMDE_POLY8_C(135), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(107) },
          { SIMDE_POLY8_C(100), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(184), SIMDE_POLY8_C(179), SIMDE_POLY8_C(181), SIMDE_POLY8_C( 31), SIMDE_POLY8_C(123), SIMDE_POLY8_C( 24) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly8x8x3_t val = {{simde_vld1_p8(test_vec[i].val[0]),
                              simde_vld1_p8(test_vec[i].val[1]),
                              simde_vld1_p8(test_vec[i].val[2])}};
    simde_poly8_t a[3];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3_lane_p8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_p8(a[0], test_vec[i].a[0]);
    simde_assert_equal_p8(a[1], test_vec[i].a[1]);
    simde_assert_equal_p8(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8_t a[3];
    simde_poly8x8x3_t val = simde_test_arm_neon_random_p8x8x3();
    const int lane = lanes[i];
    simde_vst3_lane_p8(a, val, lane);

    simde_test_codegen_write_vp8(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[3];
    simde_poly16_t val[3][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY16_C(16273), SIMDE_POLY16_C(18374), SIMDE_POLY16_C(14511) },
        { { SIMDE_POLY16_C(16273), SIMDE_POLY16_C(43473), SIMDE_POLY16_C(40084), SIMDE_POLY16_C(38537) },
          { SIMDE_POLY16_C(18374), SIMDE_POLY16_C(59088), SIMDE_POLY16_C(53758), SIMDE_POLY16_C(33900) },
          { SIMDE_POLY16_C(14511), SIMDE_POLY16_C(16185), SIMDE_POLY16_C(53010), SIMDE_POLY16_C( 6016) } },
       INT32_C(           0) },
    { { SIMDE_POLY16_C(64585), SIMDE_POLY16_C(20255), SIMDE_POLY16_C(61083) },
        { { SIMDE_POLY16_C( 8634), SIMDE_POLY16_C(64585), SIMDE_POLY16_C(31972), SIMDE_POLY16_C(30081) },
          { SIMDE_POLY16_C(21179), SIMDE_POLY16_C(20255), SIMDE_POLY16_C(43247), SIMDE_POLY16_C(46565) },
          { SIMDE_POLY16_C(46832), SIMDE_POLY16_C(61083), SIMDE_POLY16_C( 2183), SIMDE_POLY16_C(13938) } },
       INT32_C(           1) },
    { { SIMDE_POLY16_C(62842), SIMDE_POLY16_C(45615), SIMDE_POLY16_C( 7992) },
        { { SIMDE_POLY16_C(43840), SIMDE_POLY16_C(21109), SIMDE_POLY16_C(62842), SIMDE_POLY16_C(13417) },
          { SIMDE_POLY16_C(45591), SIMDE_POLY16_C(64305), SIMDE_POLY16_C(45615), SIMDE_POLY16_C(60017) },
          { SIMDE_POLY16_C(36868), SIMDE_POLY16_C(62266), SIMDE_POLY16_C( 7992), SIMDE_POLY16_C(10409) } },
       INT32_C(           2) },
    { { SIMDE_POLY16_C(35986), SIMDE_POLY16_C( 5347), SIMDE_POLY16_C(51731) },
        { { SIMDE_POLY16_C(17621), SIMDE_POLY16_C(23574), SIMDE_POLY16_C(34892), SIMDE_POLY16_C(35986) },
          { SIMDE_POLY16_C( 2100), SIMDE_POLY16_C(44766), SIMDE_POLY16_C(18429), SIMDE_POLY16_C( 5347) },
          { SIMDE_POLY16_C( 5370), SIMDE_POLY16_C(10512), SIMDE_POLY16_C(33222), SIMDE_POLY16_C(51731) } },
       INT32_C(           3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly16x4x3_t val = {{simde_vld1_p16(test_vec[i].val[0]),
                               simde_vld1_p16(test_vec[i].val[1]),
                               simde_vld1_p16(test_vec[i].val[2])}};
    simde_poly16_t a[3];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst3_lane_p16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_p16(a[0], test_vec[i].a[0]);
    simde_assert_equal_p16(a[1], test_vec[i].a[1]);
    simde_assert_equal_p16(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16_t a[3];
    simde_poly16x4x3_t val = simde_test_arm_neon_random_p16x4x3();
    const int lane = lanes[i];
    simde_vst3_lane_p16(a, val, lane);

    simde_test_codegen_write_vp16(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[3];
    simde_poly64_t val[3][1];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY64_C( 9820617213119390696), SIMDE_POLY64_C( 9673927912867748552), SIMDE_POLY64_C( 9141607021924738105) },
        { { SIMDE_POLY64_C( 9820617213119390696) },
          { SIMDE_POLY64_C( 9673927912867748552) },
          { SIMDE_POLY64_C( 9141607021924738105) } },
       INT32_C(           0) },
    { { SIMDE_POLY64_C( 7992953132776502036), SIMDE_POLY64_C(11451113253560516111), SIMDE_POLY64_C(  942796949381914977) },
        { { SIMDE_POLY64_C( 7992953132776502036) },
          { SIMDE_POLY64_C(11451113253560516111) },
          { SIMDE_POLY64_C(  942796949381914977) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly64x1x3_t val = {{simde_vld1_p64(test_vec[i].val[0]),
                              simde_vld1_p64(test_vec[i].val[1]),
                              simde_vld1_p64(test_vec[i].val[2])}};
    simde_poly64_t a[3];
    simde_vst3_lane_p64(a, val, 0);

    simde_assert_equal_p64(a[0], test_vec[i].a[0]);
    simde_assert_equal_p64(a[1], test_vec[i].a[1]);
    simde_assert_equal_p64(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    simde_poly64_t a[3];
    simde_poly64x1x3_t val = simde_test_arm_neon_random_p64x1x3();
    const int lane = lanes[i];
    simde_vst3_lane_p64(a, val, lane);

    simde_test_codegen_write_vp64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x1x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[3];
    simde_poly8_t val[3][16];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY8_C( 72), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(149) },
        { { SIMDE_POLY8_C( 72), SIMDE_POLY8_C(188), SIMDE_POLY8_C(109), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(242), SIMDE_POLY8_C(226), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(152),
            SIMDE_POLY8_C(134), SIMDE_POLY8_C(  2), SIMDE_POLY8_C( 16), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(202), SIMDE_POLY8_C(132), SIMDE_POLY8_C(216), SIMDE_POLY8_C(209) },
          { SIMDE_POLY8_C(  5), SIMDE_POLY8_C(223), SIMDE_POLY8_C(132), SIMDE_POLY8_C(164), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(180), SIMDE_POLY8_C(172), SIMDE_POLY8_C(183),
            SIMDE_POLY8_C( 45), SIMDE_POLY8_C(228), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(203), SIMDE_POLY8_C(123), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(195) },
          { SIMDE_POLY8_C(149), SIMDE_POLY8_C(182), SIMDE_POLY8_C(214), SIMDE_POLY8_C(135), SIMDE_POLY8_C(152), SIMDE_POLY8_C( 49), SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 30),
            SIMDE_POLY8_C( 51), SIMDE_POLY8_C( 48), SIMDE_POLY8_C(120), SIMDE_POLY8_C(253), SIMDE_POLY8_C(180), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(206), SIMDE_POLY8_C(186) } },
       INT32_C(           0) },
    { { SIMDE_POLY8_C( 82), SIMDE_POLY8_C(  4), SIMDE_POLY8_C( 56) },
        { { SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 82), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(108), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 51),
            SIMDE_POLY8_C(239), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(254), SIMDE_POLY8_C(106),    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(148) },
          { SIMDE_POLY8_C(253), SIMDE_POLY8_C(  4), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(149), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(180), SIMDE_POLY8_C(105),
            SIMDE_POLY8_C(107), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(102), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(125), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(218), SIMDE_POLY8_C(173) },
          { SIMDE_POLY8_C(135), SIMDE_POLY8_C( 56), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(142), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(193), SIMDE_POLY8_C( 49),
            SIMDE_POLY8_C( 98), SIMDE_POLY8_C(192), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 97), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(202), SIMDE_POLY8_C(245), SIMDE_POLY8_C(  4) } },
       INT32_C(           1) },
    { { SIMDE_POLY8_C(153), SIMDE_POLY8_C( 29), SIMDE_POLY8_C(149) },
        { { SIMDE_POLY8_C(206), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(153), SIMDE_POLY8_C(  3), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(108), SIMDE_POLY8_C(183),
            SIMDE_POLY8_C(122), SIMDE_POLY8_C(211), SIMDE_POLY8_C(215), SIMDE_POLY8_C(247), SIMDE_POLY8_C(  8), SIMDE_POLY8_C(177), SIMDE_POLY8_C(164), SIMDE_POLY8_C(143) },
          { SIMDE_POLY8_C(233), SIMDE_POLY8_C(189), SIMDE_POLY8_C( 29), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(249), SIMDE_POLY8_C(223), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 91),
            SIMDE_POLY8_C(159), SIMDE_POLY8_C(249), SIMDE_POLY8_C(188), SIMDE_POLY8_C(166), SIMDE_POLY8_C(195), SIMDE_POLY8_C(177), SIMDE_POLY8_C(170), SIMDE_POLY8_C(145) },
          { SIMDE_POLY8_C(193), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(149), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(145), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(197), SIMDE_POLY8_C( 11),
            SIMDE_POLY8_C(212), SIMDE_POLY8_C(156), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(220), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(166), SIMDE_POLY8_C(108), SIMDE_POLY8_C( 55) } },
       INT32_C(           2) },
    { { SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(181) },
        { { SIMDE_POLY8_C( 99), SIMDE_POLY8_C(137), SIMDE_POLY8_C( 99), SIMDE_POLY8_C( 92), SIMDE_POLY8_C(104), SIMDE_POLY8_C(193), SIMDE_POLY8_C(183), SIMDE_POLY8_C(  7),
            SIMDE_POLY8_C(186), SIMDE_POLY8_C(115), SIMDE_POLY8_C(173), SIMDE_POLY8_C(126), SIMDE_POLY8_C( 36), SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 15), SIMDE_POLY8_C(229) },
          { SIMDE_POLY8_C(155), SIMDE_POLY8_C(164), SIMDE_POLY8_C(243), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(166), SIMDE_POLY8_C(184), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(122),
            SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 57), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(162), SIMDE_POLY8_C(223), SIMDE_POLY8_C(195), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 66) },
          { SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(158), SIMDE_POLY8_C(181), SIMDE_POLY8_C(254), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(188), SIMDE_POLY8_C(185),
            SIMDE_POLY8_C(200), SIMDE_POLY8_C(106), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(236), SIMDE_POLY8_C(193), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(209), SIMDE_POLY8_C( 92) } },
       INT32_C(           3) },
    { { SIMDE_POLY8_C(124), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(179) },
        { { SIMDE_POLY8_C(235), SIMDE_POLY8_C(196), SIMDE_POLY8_C(136), SIMDE_POLY8_C(145), SIMDE_POLY8_C(124), SIMDE_POLY8_C(191), SIMDE_POLY8_C( 11), SIMDE_POLY8_C(209),
            SIMDE_POLY8_C(248), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(115), SIMDE_POLY8_C(215), SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(114) },
          { SIMDE_POLY8_C(139), SIMDE_POLY8_C(183), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(137), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(227), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(212),
            SIMDE_POLY8_C( 77), SIMDE_POLY8_C(121), SIMDE_POLY8_C(192), SIMDE_POLY8_C( 15), SIMDE_POLY8_C(192), SIMDE_POLY8_C(146), SIMDE_POLY8_C(107), SIMDE_POLY8_C(171) },
          { SIMDE_POLY8_C( 86), SIMDE_POLY8_C(244), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(211), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 71), SIMDE_POLY8_C(164), SIMDE_POLY8_C(172),
            SIMDE_POLY8_C(170), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(131), SIMDE_POLY8_C(207), SIMDE_POLY8_C(101), SIMDE_POLY8_C(157), SIMDE_POLY8_C( 65), SIMDE_POLY8_C(240) } },
       INT32_C(           4) },
    { { SIMDE_POLY8_C(188), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(115) },
        { { SIMDE_POLY8_C( 84), SIMDE_POLY8_C(104), SIMDE_POLY8_C(121), SIMDE_POLY8_C( 97), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(188), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(153),
            SIMDE_POLY8_C( 53), SIMDE_POLY8_C(246), SIMDE_POLY8_C(168), SIMDE_POLY8_C(245), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(160), SIMDE_POLY8_C(222) },
          { SIMDE_POLY8_C(  8), SIMDE_POLY8_C(220), SIMDE_POLY8_C(177), SIMDE_POLY8_C(187), SIMDE_POLY8_C( 36), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(103), SIMDE_POLY8_C(206),
            SIMDE_POLY8_C(109), SIMDE_POLY8_C(235), SIMDE_POLY8_C(157), SIMDE_POLY8_C(210), SIMDE_POLY8_C(136), SIMDE_POLY8_C(223), SIMDE_POLY8_C(194), SIMDE_POLY8_C(220) },
          { SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(147), SIMDE_POLY8_C(247), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 45),
            SIMDE_POLY8_C(105), SIMDE_POLY8_C(213), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(241), SIMDE_POLY8_C(233), SIMDE_POLY8_C(195), SIMDE_POLY8_C(207), SIMDE_POLY8_C(241) } },
       INT32_C(           5) },
    { { SIMDE_POLY8_C(145), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(217) },
        { { SIMDE_POLY8_C(159), SIMDE_POLY8_C(129), SIMDE_POLY8_C(173), SIMDE_POLY8_C(195), SIMDE_POLY8_C(214), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 67),
               SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C( 47), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(135), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(215), SIMDE_POLY8_C(100), SIMDE_POLY8_C( 85) },
          { SIMDE_POLY8_C( 19), SIMDE_POLY8_C(161), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(125),
            SIMDE_POLY8_C(235), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(110), SIMDE_POLY8_C(213), SIMDE_POLY8_C( 29), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(198), SIMDE_POLY8_C(188) },
          { SIMDE_POLY8_C(191), SIMDE_POLY8_C(115), SIMDE_POLY8_C(128), SIMDE_POLY8_C(149), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(217), SIMDE_POLY8_C(135),
            SIMDE_POLY8_C( 64), SIMDE_POLY8_C(238), SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(198), SIMDE_POLY8_C(115), SIMDE_POLY8_C(164), SIMDE_POLY8_C(217) } },
       INT32_C(           6) },
    { { SIMDE_POLY8_C(142), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(129) },
        { { SIMDE_POLY8_C( 20), SIMDE_POLY8_C(141), SIMDE_POLY8_C(227), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(163), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(166), SIMDE_POLY8_C(142),
            SIMDE_POLY8_C(117), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(146), SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 42), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 18) },
          { SIMDE_POLY8_C(157), SIMDE_POLY8_C(206), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(224), SIMDE_POLY8_C(128), SIMDE_POLY8_C(173), SIMDE_POLY8_C( 32),
            SIMDE_POLY8_C(111), SIMDE_POLY8_C(188), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 47), SIMDE_POLY8_C( 19), SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 67) },
          { SIMDE_POLY8_C(160), SIMDE_POLY8_C(241), SIMDE_POLY8_C(108), SIMDE_POLY8_C( 67), SIMDE_POLY8_C( 12), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(209), SIMDE_POLY8_C(129),
            SIMDE_POLY8_C( 40), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(123), SIMDE_POLY8_C( 95), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(141), SIMDE_POLY8_C(252) } },
       INT32_C(           7) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly8x16x3_t val = {{simde_vld1q_p8(test_vec[i].val[0]),
                             simde_vld1q_p8(test_vec[i].val[1]),
                             simde_vld1q_p8(test_vec[i].val[2])}};
    simde_poly8_t a[3];
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst3q_lane_p8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_p8(a[0], test_vec[i].a[0]);
    simde_assert_equal_p8(a[1], test_vec[i].a[1]);
    simde_assert_equal_p8(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8_t a[3];
    simde_poly8x16x3_t val = simde_test_arm_neon_random_p8x16x3();
    int lane = simde_test_codegen_random_i8() & 15;
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst3q_lane_p8, HEDLEY_UNREACHABLE(),
                                lane, a, val);

    simde_test_codegen_write_vp8(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[3];
    simde_poly16_t val[3][8];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY16_C( 4358), SIMDE_POLY16_C(45621), SIMDE_POLY16_C(43180) },
        { { SIMDE_POLY16_C( 4358), SIMDE_POLY16_C(52346), SIMDE_POLY16_C(19773), SIMDE_POLY16_C(65303), SIMDE_POLY16_C( 8856), SIMDE_POLY16_C(22134), SIMDE_POLY16_C( 6774), SIMDE_POLY16_C( 4144) },
          { SIMDE_POLY16_C(45621), SIMDE_POLY16_C(48866), SIMDE_POLY16_C(36301), SIMDE_POLY16_C(59806), SIMDE_POLY16_C(47730), SIMDE_POLY16_C(55782), SIMDE_POLY16_C(39907), SIMDE_POLY16_C(59950) },
          { SIMDE_POLY16_C(43180), SIMDE_POLY16_C(60086), SIMDE_POLY16_C(52725), SIMDE_POLY16_C(36585), SIMDE_POLY16_C(24559), SIMDE_POLY16_C(26340), SIMDE_POLY16_C( 5242), SIMDE_POLY16_C(44918) } },
       INT32_C(           0) },
    { { SIMDE_POLY16_C(37997), SIMDE_POLY16_C(65173), SIMDE_POLY16_C( 8671) },
        { { SIMDE_POLY16_C(22982), SIMDE_POLY16_C(37997), SIMDE_POLY16_C( 3046), SIMDE_POLY16_C(22653), SIMDE_POLY16_C(25541), SIMDE_POLY16_C(43314), SIMDE_POLY16_C(24830), SIMDE_POLY16_C(43923) },
          { SIMDE_POLY16_C(18697), SIMDE_POLY16_C(65173), SIMDE_POLY16_C(32278), SIMDE_POLY16_C( 1676), SIMDE_POLY16_C(28894), SIMDE_POLY16_C(22636), SIMDE_POLY16_C(57988), SIMDE_POLY16_C(19207) },
          { SIMDE_POLY16_C(29755), SIMDE_POLY16_C( 8671), SIMDE_POLY16_C(23680), SIMDE_POLY16_C(17786), SIMDE_POLY16_C(44224), SIMDE_POLY16_C(48878), SIMDE_POLY16_C(33036), SIMDE_POLY16_C( 5481) } },
       INT32_C(           1) },
    { { SIMDE_POLY16_C(41085), SIMDE_POLY16_C( 3100), SIMDE_POLY16_C(63119) },
        { { SIMDE_POLY16_C(65226), SIMDE_POLY16_C(57620), SIMDE_POLY16_C(41085), SIMDE_POLY16_C(23527), SIMDE_POLY16_C(21265), SIMDE_POLY16_C(38323), SIMDE_POLY16_C(47669), SIMDE_POLY16_C(29152) },
          { SIMDE_POLY16_C(48942), SIMDE_POLY16_C(44690), SIMDE_POLY16_C( 3100), SIMDE_POLY16_C(56564), SIMDE_POLY16_C(58040), SIMDE_POLY16_C(50586), SIMDE_POLY16_C( 1124), SIMDE_POLY16_C(11994) },
          { SIMDE_POLY16_C(60930), SIMDE_POLY16_C(32527), SIMDE_POLY16_C(63119), SIMDE_POLY16_C(41178), SIMDE_POLY16_C(36169), SIMDE_POLY16_C(32565), SIMDE_POLY16_C( 5703), SIMDE_POLY16_C(30448) } },
       INT32_C(           2) },
    { { SIMDE_POLY16_C(18381), SIMDE_POLY16_C(56580), SIMDE_POLY16_C(19365) },
        { { SIMDE_POLY16_C(33493), SIMDE_POLY16_C(61732), SIMDE_POLY16_C( 6287), SIMDE_POLY16_C(18381), SIMDE_POLY16_C(26875), SIMDE_POLY16_C(24332), SIMDE_POLY16_C(59244), SIMDE_POLY16_C(28301) },
          { SIMDE_POLY16_C(40405), SIMDE_POLY16_C(25838), SIMDE_POLY16_C(51347), SIMDE_POLY16_C(56580), SIMDE_POLY16_C(14934), SIMDE_POLY16_C(40284), SIMDE_POLY16_C(19536), SIMDE_POLY16_C( 9491) },
          { SIMDE_POLY16_C(14542), SIMDE_POLY16_C(23831), SIMDE_POLY16_C(58448), SIMDE_POLY16_C(19365), SIMDE_POLY16_C(45388), SIMDE_POLY16_C(47274), SIMDE_POLY16_C(14488), SIMDE_POLY16_C(28199) } },
       INT32_C(           3) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly16x8x3_t val = {{simde_vld1q_p16(test_vec[i].val[0]),
                              simde_vld1q_p16(test_vec[i].val[1]),
                              simde_vld1q_p16(test_vec[i].val[2])}};
    simde_poly16_t a[3];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3q_lane_p16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_p16(a[0], test_vec[i].a[0]);
    simde_assert_equal_p16(a[1], test_vec[i].a[1]);
    simde_assert_equal_p16(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16_t a[3];
    simde_poly16x8x3_t val = simde_test_arm_neon_random_p16x8x3();
    int lane = simde_test_codegen_random_i8() & 7;
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3q_lane_p16, HEDLEY_UNREACHABLE(),
                                lane, a, val);

    simde_test_codegen_write_vp16(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[3];
    simde_poly64_t val[3][2];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY64_C(12898659581318511290), SIMDE_POLY64_C(  500302278456964456), SIMDE_POLY64_C( 3201079187964383532) },
       { { SIMDE_POLY64_C(12898659581318511290), SIMDE_POLY64_C( 1443322119720072349) },
         { SIMDE_POLY64_C(  500302278456964456), SIMDE_POLY64_C(17015850850943128150) },
         { SIMDE_POLY64_C( 3201079187964383532), SIMDE_POLY64_C(16888312240960162936) } },
      INT32_C(           0) },
   { { SIMDE_POLY64_C(12956845716471420337), SIMDE_POLY64_C(17514489777424454308), SIMDE_POLY64_C(10550314667189752879) },
       { { SIMDE_POLY64_C(16255566433045257547), SIMDE_POLY64_C(12956845716471420337) },
         { SIMDE_POLY64_C( 5621575177120535111), SIMDE_POLY64_C(17514489777424454308) },
         { SIMDE_POLY64_C(10196460566231612692), SIMDE_POLY64_C(10550314667189752879) } },
      INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly64x2x3_t val = {{simde_vld1q_p64(test_vec[i].val[0]),
                              simde_vld1q_p64(test_vec[i].val[1]),
                              simde_vld1q_p64(test_vec[i].val[2])}};
    simde_poly64_t a[3];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3q_lane_p64, HEDLEY_UNREACHABLE(), test_vec[i].lane, a, val);

    simde_assert_equal_p64(a[0], test_vec[i].a[0]);
    simde_assert_equal_p64(a[1], test_vec[i].a[1]);
    simde_assert_equal_p64(a[2], test_vec[i].a[2]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64_t a[3];
    simde_poly64x2x3_t val = simde_test_arm_neon_random_p64x2x3();
    int lane = simde_test_codegen_random_i8() & 1;
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst3q_lane_p64, HEDLEY_UNREACHABLE(), lane, a, val);

    simde_test_codegen_write_vp64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2x3(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[3];
    simde_bfloat16_t val[3][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE( - 94.290), SIMDE_BFLOAT16_VALUE( - 50.509),  SIMDE_BFLOAT16_VALUE( 23.704) },
    { { SIMDE_BFLOAT16_VALUE( -  0.571), SIMDE_BFLOAT16_VALUE( - 94.290),  SIMDE_BFLOAT16_VALUE( 93.093),  SIMDE_BFLOAT16_VALUE( 89.891)  },
      { SIMDE_BFLOAT16_VALUE( - 59.956), SIMDE_BFLOAT16_VALUE( - 50.509),  SIMDE_BFLOAT16_VALUE( 35.194),  SIMDE_BFLOAT16_VALUE( 22.787)  },
      { SIMDE_BFLOAT16_VALUE( - 24.560),  SIMDE_BFLOAT16_VALUE( 23.704), SIMDE_BFLOAT16_VALUE( - 11.110), SIMDE_BFLOAT16_VALUE( - 19.691)  } },
         INT8_C(      1) },
    { { SIMDE_BFLOAT16_VALUE( -  6.814), SIMDE_BFLOAT16_VALUE( - 31.127), SIMDE_BFLOAT16_VALUE( - 34.824) },
    { { SIMDE_BFLOAT16_VALUE( - 17.965), SIMDE_BFLOAT16_VALUE( -  6.814), SIMDE_BFLOAT16_VALUE( - 65.421),  SIMDE_BFLOAT16_VALUE( 26.500)  },
      {  SIMDE_BFLOAT16_VALUE( 84.515), SIMDE_BFLOAT16_VALUE( - 31.127),  SIMDE_BFLOAT16_VALUE( 85.025), SIMDE_BFLOAT16_VALUE( - 51.272)  },
      { SIMDE_BFLOAT16_VALUE( - 38.529), SIMDE_BFLOAT16_VALUE( - 34.824), SIMDE_BFLOAT16_VALUE( - 81.647),  SIMDE_BFLOAT16_VALUE( 47.194)  } },
         INT8_C(      1) },
    { { SIMDE_BFLOAT16_VALUE( - 73.789), SIMDE_BFLOAT16_VALUE( -  3.383), SIMDE_BFLOAT16_VALUE( - 13.801) },
    { { SIMDE_BFLOAT16_VALUE( - 94.005), SIMDE_BFLOAT16_VALUE( - 35.738), SIMDE_BFLOAT16_VALUE( - 73.789), SIMDE_BFLOAT16_VALUE( - 45.230)  },
      {  SIMDE_BFLOAT16_VALUE( 12.330),  SIMDE_BFLOAT16_VALUE( 74.051), SIMDE_BFLOAT16_VALUE( -  3.383), SIMDE_BFLOAT16_VALUE( - 10.054)  },
      { SIMDE_BFLOAT16_VALUE( - 64.841),  SIMDE_BFLOAT16_VALUE(  8.563), SIMDE_BFLOAT16_VALUE( - 13.801),  SIMDE_BFLOAT16_VALUE( 10.504)  } },
         INT8_C(      2) },
    { {  SIMDE_BFLOAT16_VALUE(  0.435),  SIMDE_BFLOAT16_VALUE( 62.466),  SIMDE_BFLOAT16_VALUE( 94.721) },
    { {  SIMDE_BFLOAT16_VALUE(  0.435), SIMDE_BFLOAT16_VALUE( - 13.638),  SIMDE_BFLOAT16_VALUE(  0.530), SIMDE_BFLOAT16_VALUE( - 61.496)  },
      {  SIMDE_BFLOAT16_VALUE( 62.466),  SIMDE_BFLOAT16_VALUE( 24.828),  SIMDE_BFLOAT16_VALUE(  9.968), SIMDE_BFLOAT16_VALUE( - 50.721)  },
      {  SIMDE_BFLOAT16_VALUE( 94.721),  SIMDE_BFLOAT16_VALUE( 44.136),  SIMDE_BFLOAT16_VALUE( 78.905), SIMDE_BFLOAT16_VALUE( - 55.458)  } },
         INT8_C(      0) },
    { { SIMDE_BFLOAT16_VALUE( - 22.144),  SIMDE_BFLOAT16_VALUE( 90.977), SIMDE_BFLOAT16_VALUE( -  5.890) },
    { {  SIMDE_BFLOAT16_VALUE( 26.172), SIMDE_BFLOAT16_VALUE( - 89.305), SIMDE_BFLOAT16_VALUE( - 59.818), SIMDE_BFLOAT16_VALUE( - 22.144)  },
      { SIMDE_BFLOAT16_VALUE( - 44.719), SIMDE_BFLOAT16_VALUE( - 60.282),  SIMDE_BFLOAT16_VALUE( 94.935),  SIMDE_BFLOAT16_VALUE( 90.977)  },
      {  SIMDE_BFLOAT16_VALUE( 80.867), SIMDE_BFLOAT16_VALUE( - 45.339), SIMDE_BFLOAT16_VALUE( - 19.747), SIMDE_BFLOAT16_VALUE( -  5.890)  } },
         INT8_C(      3) },
    { {  SIMDE_BFLOAT16_VALUE( 23.224),  SIMDE_BFLOAT16_VALUE( 49.585),  SIMDE_BFLOAT16_VALUE( 78.018) },
    { { SIMDE_BFLOAT16_VALUE( - 48.686),  SIMDE_BFLOAT16_VALUE( 23.224),  SIMDE_BFLOAT16_VALUE( 40.332),  SIMDE_BFLOAT16_VALUE( 74.959)  },
      { SIMDE_BFLOAT16_VALUE( - 65.641),  SIMDE_BFLOAT16_VALUE( 49.585),  SIMDE_BFLOAT16_VALUE(  6.886),  SIMDE_BFLOAT16_VALUE( 98.862)  },
      { SIMDE_BFLOAT16_VALUE( - 29.125),  SIMDE_BFLOAT16_VALUE( 78.018), SIMDE_BFLOAT16_VALUE( -  4.487),  SIMDE_BFLOAT16_VALUE( 50.278)  } },
         INT8_C(      1) },
    { { SIMDE_BFLOAT16_VALUE( - 90.627), SIMDE_BFLOAT16_VALUE( -  1.372), SIMDE_BFLOAT16_VALUE( - 87.387) },
    { { SIMDE_BFLOAT16_VALUE( - 58.435),  SIMDE_BFLOAT16_VALUE( 67.021), SIMDE_BFLOAT16_VALUE( - 90.627),  SIMDE_BFLOAT16_VALUE( 69.960)  },
      {  SIMDE_BFLOAT16_VALUE( 62.852),  SIMDE_BFLOAT16_VALUE( 29.780), SIMDE_BFLOAT16_VALUE( -  1.372),  SIMDE_BFLOAT16_VALUE( 41.058)  },
      {  SIMDE_BFLOAT16_VALUE( 43.350), SIMDE_BFLOAT16_VALUE( - 69.931), SIMDE_BFLOAT16_VALUE( - 87.387),  SIMDE_BFLOAT16_VALUE( 98.569)  } },
         INT8_C(      2) },
    { {  SIMDE_BFLOAT16_VALUE( 33.021),  SIMDE_BFLOAT16_VALUE( 22.025),  SIMDE_BFLOAT16_VALUE( 69.528) },
    { {  SIMDE_BFLOAT16_VALUE( 40.864),  SIMDE_BFLOAT16_VALUE( 81.943), SIMDE_BFLOAT16_VALUE( - 40.609),  SIMDE_BFLOAT16_VALUE( 33.021)  },
      {  SIMDE_BFLOAT16_VALUE( 93.909),  SIMDE_BFLOAT16_VALUE( 69.201),  SIMDE_BFLOAT16_VALUE( 43.541),  SIMDE_BFLOAT16_VALUE( 22.025)  },
      {  SIMDE_BFLOAT16_VALUE( 45.748), SIMDE_BFLOAT16_VALUE( - 89.541),  SIMDE_BFLOAT16_VALUE( 49.879),  SIMDE_BFLOAT16_VALUE( 69.528)  } },
         INT8_C(      3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_bfloat16x4x3_t val = {{simde_vld1_bf16(test_vec[i].val[0]),
                               simde_vld1_bf16(test_vec[i].val[1]),
                               simde_vld1_bf16(test_vec[i].val[2])}};
    simde_bfloat16_t a[3];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst3_lane_bf16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_bf16(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_bf16(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_bf16(a[2], test_vec[i].a[2], 1);
  }

  return 0;
}

static int
test_simde_vst3q_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[3];
    simde_bfloat16_t val[3][8];
    int lane;
  } test_vec[] = {
    { {  SIMDE_BFLOAT16_VALUE( 56.833),  SIMDE_BFLOAT16_VALUE( 73.442), SIMDE_BFLOAT16_VALUE( - 22.618) },
    { {  SIMDE_BFLOAT16_VALUE( 90.228),  SIMDE_BFLOAT16_VALUE(  1.415), SIMDE_BFLOAT16_VALUE( - 54.694),  SIMDE_BFLOAT16_VALUE( 41.258),
         SIMDE_BFLOAT16_VALUE( 74.577),  SIMDE_BFLOAT16_VALUE( 13.483),  SIMDE_BFLOAT16_VALUE( 56.833),  SIMDE_BFLOAT16_VALUE( 68.200)  },
      { SIMDE_BFLOAT16_VALUE( - 65.650), SIMDE_BFLOAT16_VALUE( - 68.388), SIMDE_BFLOAT16_VALUE( - 13.278), SIMDE_BFLOAT16_VALUE( - 65.890),
         SIMDE_BFLOAT16_VALUE( 16.926), SIMDE_BFLOAT16_VALUE( - 26.315),  SIMDE_BFLOAT16_VALUE( 73.442),  SIMDE_BFLOAT16_VALUE( 26.641)  },
      { SIMDE_BFLOAT16_VALUE( - 42.649),  SIMDE_BFLOAT16_VALUE( 80.336),  SIMDE_BFLOAT16_VALUE( 27.756),  SIMDE_BFLOAT16_VALUE(  8.267),
         SIMDE_BFLOAT16_VALUE( 24.942),  SIMDE_BFLOAT16_VALUE( 96.066), SIMDE_BFLOAT16_VALUE( - 22.618), SIMDE_BFLOAT16_VALUE( - 58.346)  } },
         INT8_C(      6) },
    { { SIMDE_BFLOAT16_VALUE( - 74.185), SIMDE_BFLOAT16_VALUE( - 78.069), SIMDE_BFLOAT16_VALUE( - 86.364) },
    { { SIMDE_BFLOAT16_VALUE( - 69.189), SIMDE_BFLOAT16_VALUE( - 74.185),  SIMDE_BFLOAT16_VALUE(  5.043), SIMDE_BFLOAT16_VALUE( - 18.088),
         SIMDE_BFLOAT16_VALUE( 14.723),  SIMDE_BFLOAT16_VALUE(  9.202),  SIMDE_BFLOAT16_VALUE( 78.389), SIMDE_BFLOAT16_VALUE( - 87.305)  },
      { SIMDE_BFLOAT16_VALUE( - 12.507), SIMDE_BFLOAT16_VALUE( - 78.069), SIMDE_BFLOAT16_VALUE( - 96.953), SIMDE_BFLOAT16_VALUE( - 96.401),
         SIMDE_BFLOAT16_VALUE( 42.165),  SIMDE_BFLOAT16_VALUE( 75.353), SIMDE_BFLOAT16_VALUE( - 82.128),  SIMDE_BFLOAT16_VALUE( 17.448)  },
      {  SIMDE_BFLOAT16_VALUE( 57.653), SIMDE_BFLOAT16_VALUE( - 86.364),  SIMDE_BFLOAT16_VALUE( 30.786), SIMDE_BFLOAT16_VALUE( - 50.101),
         SIMDE_BFLOAT16_VALUE( 60.669), SIMDE_BFLOAT16_VALUE( - 26.173),  SIMDE_BFLOAT16_VALUE( 10.148), SIMDE_BFLOAT16_VALUE( - 92.619)  } },
         INT8_C(      1) },
    { { SIMDE_BFLOAT16_VALUE( - 30.210), SIMDE_BFLOAT16_VALUE( - 13.667), SIMDE_BFLOAT16_VALUE( - 47.603) },
    { { SIMDE_BFLOAT16_VALUE( - 96.908), SIMDE_BFLOAT16_VALUE( - 14.691),  SIMDE_BFLOAT16_VALUE( 67.605),  SIMDE_BFLOAT16_VALUE( 52.785),
         SIMDE_BFLOAT16_VALUE( 10.770),  SIMDE_BFLOAT16_VALUE( 49.923),  SIMDE_BFLOAT16_VALUE( 79.174), SIMDE_BFLOAT16_VALUE( - 30.210)  },
      { SIMDE_BFLOAT16_VALUE( - 86.230), SIMDE_BFLOAT16_VALUE( - 40.180),  SIMDE_BFLOAT16_VALUE( 81.322), SIMDE_BFLOAT16_VALUE( -  4.303),
        SIMDE_BFLOAT16_VALUE( - 25.810),  SIMDE_BFLOAT16_VALUE( 19.169), SIMDE_BFLOAT16_VALUE( -  7.542), SIMDE_BFLOAT16_VALUE( - 13.667)  },
      {  SIMDE_BFLOAT16_VALUE( 48.690), SIMDE_BFLOAT16_VALUE( - 84.400), SIMDE_BFLOAT16_VALUE( - 42.388), SIMDE_BFLOAT16_VALUE( - 71.989),
         SIMDE_BFLOAT16_VALUE( 81.668),  SIMDE_BFLOAT16_VALUE( 61.074),  SIMDE_BFLOAT16_VALUE( 68.365), SIMDE_BFLOAT16_VALUE( - 47.603)  } },
         INT8_C(      7) },
    { { SIMDE_BFLOAT16_VALUE( - 74.022),  SIMDE_BFLOAT16_VALUE( 72.818),  SIMDE_BFLOAT16_VALUE( 75.403) },
    { {  SIMDE_BFLOAT16_VALUE( 65.684),  SIMDE_BFLOAT16_VALUE( 92.561), SIMDE_BFLOAT16_VALUE( - 76.038),  SIMDE_BFLOAT16_VALUE( 75.659),
        SIMDE_BFLOAT16_VALUE( - 74.022),  SIMDE_BFLOAT16_VALUE( 74.037), SIMDE_BFLOAT16_VALUE( - 67.037),  SIMDE_BFLOAT16_VALUE( 61.026)  },
      {  SIMDE_BFLOAT16_VALUE( 43.862), SIMDE_BFLOAT16_VALUE( - 42.260), SIMDE_BFLOAT16_VALUE( -  8.530),  SIMDE_BFLOAT16_VALUE( 15.388),
         SIMDE_BFLOAT16_VALUE( 72.818), SIMDE_BFLOAT16_VALUE( -  3.493),  SIMDE_BFLOAT16_VALUE( 29.692),  SIMDE_BFLOAT16_VALUE( 78.968)  },
      { SIMDE_BFLOAT16_VALUE( - 91.120),  SIMDE_BFLOAT16_VALUE( 22.041), SIMDE_BFLOAT16_VALUE( - 61.013), SIMDE_BFLOAT16_VALUE( - 71.187),
         SIMDE_BFLOAT16_VALUE( 75.403),  SIMDE_BFLOAT16_VALUE( 95.292),  SIMDE_BFLOAT16_VALUE( 21.707), SIMDE_BFLOAT16_VALUE( - 88.034)  } },
         INT8_C(      4) },
    { {  SIMDE_BFLOAT16_VALUE( 66.250),  SIMDE_BFLOAT16_VALUE( 86.996), SIMDE_BFLOAT16_VALUE( - 40.809) },
    { {  SIMDE_BFLOAT16_VALUE( 56.098), SIMDE_BFLOAT16_VALUE( - 69.469), SIMDE_BFLOAT16_VALUE( - 38.141),  SIMDE_BFLOAT16_VALUE( 95.730),
         SIMDE_BFLOAT16_VALUE( 66.250),  SIMDE_BFLOAT16_VALUE( 88.246), SIMDE_BFLOAT16_VALUE( - 73.861),  SIMDE_BFLOAT16_VALUE( 88.929)  },
      {  SIMDE_BFLOAT16_VALUE( 91.342),  SIMDE_BFLOAT16_VALUE( 25.976),  SIMDE_BFLOAT16_VALUE( 27.770),  SIMDE_BFLOAT16_VALUE( 57.030),
         SIMDE_BFLOAT16_VALUE( 86.996),  SIMDE_BFLOAT16_VALUE( 24.429),  SIMDE_BFLOAT16_VALUE( 36.571),  SIMDE_BFLOAT16_VALUE( 25.024)  },
      { SIMDE_BFLOAT16_VALUE( - 51.937),  SIMDE_BFLOAT16_VALUE(  0.024),  SIMDE_BFLOAT16_VALUE( 26.121),  SIMDE_BFLOAT16_VALUE( 82.133),
        SIMDE_BFLOAT16_VALUE( - 40.809), SIMDE_BFLOAT16_VALUE( - 89.179), SIMDE_BFLOAT16_VALUE( - 45.771), SIMDE_BFLOAT16_VALUE( - 76.817)  } },
         INT8_C(      4) },
    { {  SIMDE_BFLOAT16_VALUE( 41.869), SIMDE_BFLOAT16_VALUE( - 27.827), SIMDE_BFLOAT16_VALUE( - 92.856) },
    { { SIMDE_BFLOAT16_VALUE( - 35.175),  SIMDE_BFLOAT16_VALUE( 47.619),  SIMDE_BFLOAT16_VALUE( 41.869),  SIMDE_BFLOAT16_VALUE( 17.848),
        SIMDE_BFLOAT16_VALUE( - 56.188), SIMDE_BFLOAT16_VALUE( - 50.409),  SIMDE_BFLOAT16_VALUE( 65.876), SIMDE_BFLOAT16_VALUE( - 32.688)  },
      {  SIMDE_BFLOAT16_VALUE(  3.311), SIMDE_BFLOAT16_VALUE( - 49.604), SIMDE_BFLOAT16_VALUE( - 27.827), SIMDE_BFLOAT16_VALUE( -  2.760),
         SIMDE_BFLOAT16_VALUE( 20.012),  SIMDE_BFLOAT16_VALUE( 66.946),  SIMDE_BFLOAT16_VALUE( 31.788), SIMDE_BFLOAT16_VALUE( - 52.736)  },
      { SIMDE_BFLOAT16_VALUE( - 93.576),  SIMDE_BFLOAT16_VALUE(  4.057), SIMDE_BFLOAT16_VALUE( - 92.856),  SIMDE_BFLOAT16_VALUE( 68.167),
        SIMDE_BFLOAT16_VALUE( - 17.311), SIMDE_BFLOAT16_VALUE( - 69.405),  SIMDE_BFLOAT16_VALUE( 82.245), SIMDE_BFLOAT16_VALUE( -  7.897)  } },
         INT8_C(      2) },
    { {  SIMDE_BFLOAT16_VALUE( 84.635), SIMDE_BFLOAT16_VALUE( - 34.646), SIMDE_BFLOAT16_VALUE( - 57.874) },
    { {  SIMDE_BFLOAT16_VALUE( 81.549), SIMDE_BFLOAT16_VALUE( -  2.028),  SIMDE_BFLOAT16_VALUE( 84.635), SIMDE_BFLOAT16_VALUE( - 29.533),
        SIMDE_BFLOAT16_VALUE( - 38.208),  SIMDE_BFLOAT16_VALUE( 73.008),  SIMDE_BFLOAT16_VALUE( 35.951), SIMDE_BFLOAT16_VALUE( - 30.779)  },
      {  SIMDE_BFLOAT16_VALUE( 42.215), SIMDE_BFLOAT16_VALUE( - 27.247), SIMDE_BFLOAT16_VALUE( - 34.646), SIMDE_BFLOAT16_VALUE( -  1.564),
         SIMDE_BFLOAT16_VALUE( 71.796), SIMDE_BFLOAT16_VALUE( - 51.547),  SIMDE_BFLOAT16_VALUE( 32.523), SIMDE_BFLOAT16_VALUE( - 43.421)  },
      {  SIMDE_BFLOAT16_VALUE(  0.439),  SIMDE_BFLOAT16_VALUE( 13.866), SIMDE_BFLOAT16_VALUE( - 57.874), SIMDE_BFLOAT16_VALUE( - 87.206),
        SIMDE_BFLOAT16_VALUE( - 61.660),  SIMDE_BFLOAT16_VALUE( 80.530), SIMDE_BFLOAT16_VALUE( - 56.810), SIMDE_BFLOAT16_VALUE( - 20.126)  } },
         INT8_C(      2) },
    { { SIMDE_BFLOAT16_VALUE( - 78.288),  SIMDE_BFLOAT16_VALUE( 36.942),  SIMDE_BFLOAT16_VALUE( 21.455) },
    { { SIMDE_BFLOAT16_VALUE( -  1.116),  SIMDE_BFLOAT16_VALUE( 88.525), SIMDE_BFLOAT16_VALUE( - 54.747),  SIMDE_BFLOAT16_VALUE( 70.086),
        SIMDE_BFLOAT16_VALUE( -  0.981), SIMDE_BFLOAT16_VALUE( - 78.288), SIMDE_BFLOAT16_VALUE( - 64.328),  SIMDE_BFLOAT16_VALUE( 72.247)  },
      {  SIMDE_BFLOAT16_VALUE( 50.505),  SIMDE_BFLOAT16_VALUE( 62.460),  SIMDE_BFLOAT16_VALUE( 55.021),  SIMDE_BFLOAT16_VALUE( 63.023),
         SIMDE_BFLOAT16_VALUE( 46.784),  SIMDE_BFLOAT16_VALUE( 36.942), SIMDE_BFLOAT16_VALUE( - 96.105), SIMDE_BFLOAT16_VALUE( - 30.818)  },
      { SIMDE_BFLOAT16_VALUE( - 28.408), SIMDE_BFLOAT16_VALUE( - 39.921),  SIMDE_BFLOAT16_VALUE(  8.839), SIMDE_BFLOAT16_VALUE( - 70.832),
         SIMDE_BFLOAT16_VALUE( 33.768),  SIMDE_BFLOAT16_VALUE( 21.455), SIMDE_BFLOAT16_VALUE( - 89.062),  SIMDE_BFLOAT16_VALUE( 97.215)  } },
         INT8_C(      5) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_bfloat16x8x3_t val = {{simde_vld1q_bf16(test_vec[i].val[0]),
                               simde_vld1q_bf16(test_vec[i].val[1]),
                               simde_vld1q_bf16(test_vec[i].val[2])}};
    simde_bfloat16_t a[3];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst3q_lane_bf16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);

    simde_assert_equal_bf16(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_bf16(a[1], test_vec[i].a[1], 1);
    simde_assert_equal_bf16(a[2], test_vec[i].a[2], 1);
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_lane_bf16)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
