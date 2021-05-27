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

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_lane_u32)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
