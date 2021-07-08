#define SIMDE_TEST_ARM_NEON_INSN st2_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/st2_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst2_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[2];
    int8_t val[2][8];
    int lane;
  } test_vec[] = {
    { { -INT8_C(  57),  INT8_C(  64) },
        { { -INT8_C(  57),  INT8_C(   8),  INT8_C(  40), -INT8_C( 126),  INT8_C(   4), -INT8_C(  71),  INT8_C(  23),  INT8_C( 123) },
          {  INT8_C(  64), -INT8_C(  26),  INT8_C(   3), -INT8_C(  81), -INT8_C(   8),  INT8_C(  40),  INT8_C( 114), -INT8_C(  82) } },
       INT32_C(           0) },
    { {  INT8_C( 110),  INT8_C( 117) },
        { {  INT8_C(  97),  INT8_C( 110), -INT8_C( 100), -INT8_C(  44), -INT8_C(  80), -INT8_C(  60),  INT8_C(  93),  INT8_C(  69) },
          { -INT8_C(  41),  INT8_C( 117), -INT8_C(  28),  INT8_C( 119), -INT8_C(  78),  INT8_C(  94),  INT8_C(  58),  INT8_C( 122) } },
       INT32_C(           1) },
    { { -INT8_C(   4),  INT8_C(  11) },
        { {  INT8_C( 102),  INT8_C(  98), -INT8_C(   4),  INT8_C( 107),  INT8_C(  27),  INT8_C(  19), -INT8_C(  26),  INT8_C(  92) },
          { -INT8_C(   6), -INT8_C(  22),  INT8_C(  11), -INT8_C(  14),  INT8_C(  18),  INT8_C( 125), -INT8_C(  96),  INT8_C( 115) } },
       INT32_C(           2) },
    { { -INT8_C( 100), -INT8_C(  52) },
        { { -INT8_C(  20),  INT8_C(  60),  INT8_C(  71), -INT8_C( 100),  INT8_C(   1), -INT8_C(  92), -INT8_C(  31), -INT8_C(  40) },
          {  INT8_C(  25), -INT8_C(  59),  INT8_C(  80), -INT8_C(  52),  INT8_C(  35), -INT8_C( 118),  INT8_C(  70), -INT8_C( 118) } },
       INT32_C(           3) },
    { {  INT8_C(  86), -INT8_C(  20) },
        { { -INT8_C(  20),  INT8_C(  66), -INT8_C(  11),  INT8_C(   7),  INT8_C(  86), -INT8_C(  37),  INT8_C(  99),  INT8_C(  80) },
          { -INT8_C(  59),  INT8_C( 111),  INT8_C(  66), -INT8_C(  41), -INT8_C(  20), -INT8_C(  30),  INT8_C(  75), -INT8_C(  40) } },
       INT32_C(           4) },
    { {  INT8_C(  85),  INT8_C(  98) },
        { {  INT8_C(  30), -INT8_C( 110),  INT8_C( 116),  INT8_C(  31),  INT8_C(  55),  INT8_C(  85), -INT8_C(   8),  INT8_C(  80) },
          {  INT8_C(  27),  INT8_C(  72),  INT8_C(  28),  INT8_C(  62), -INT8_C(  46),  INT8_C(  98), -INT8_C(  56), -INT8_C(  66) } },
       INT32_C(           5) },
    { {  INT8_C(  75),  INT8_C(  93) },
        { { -INT8_C(  91), -INT8_C(  67), -INT8_C(  59), -INT8_C(   5), -INT8_C( 103),  INT8_C(  41),  INT8_C(  75),  INT8_C(  94) },
          { -INT8_C( 104), -INT8_C( 115),  INT8_C(  54), -INT8_C( 124),  INT8_C( 111), -INT8_C( 127),  INT8_C(  93), -INT8_C( 115) } },
       INT32_C(           6) },
    { {  INT8_C(  66), -INT8_C(  65) },
        { {  INT8_C(  19), -INT8_C(  47), -INT8_C(  83),  INT8_C(  74),  INT8_C(  39), -INT8_C(  91), -INT8_C( 101),  INT8_C(  66) },
          { -INT8_C(  19), -INT8_C(  73),      INT8_MIN, -INT8_C(  65),  INT8_C(  26),  INT8_C(  73),  INT8_C( 125), -INT8_C(  65) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8x2_t val = {
        {simde_vld1_s8(test_vec[i].val[0]), simde_vld1_s8(test_vec[i].val[1])}};
    int8_t a[2];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2_lane_s8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_i8(a[0], test_vec[i].a[0]);
    simde_assert_equal_i8(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a[2];
    simde_int8x8x2_t val = simde_test_arm_neon_random_i8x8x2();
    const int lane = lanes[i];
    simde_vst2_lane_s8(a, val, lane);

    simde_test_codegen_write_vi8(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[2];
    int16_t val[2][4];
    int lane;
  } test_vec[] = {
    { { -INT16_C(  4280), -INT16_C( 20357) },
        { { -INT16_C(  4280), -INT16_C( 11642), -INT16_C( 10323),  INT16_C( 27416) },
          { -INT16_C( 20357), -INT16_C(  6137), -INT16_C(   305), -INT16_C(  2484) } },
       INT32_C(           0) },
    { {  INT16_C( 19249),  INT16_C( 23959) },
        { { -INT16_C( 26713),  INT16_C( 19249), -INT16_C( 18690),  INT16_C( 30347) },
          {  INT16_C( 28650),  INT16_C( 23959), -INT16_C( 17264), -INT16_C( 10050) } },
       INT32_C(           1) },
    { { -INT16_C( 15844), -INT16_C( 13110) },
        { {  INT16_C( 17835),  INT16_C( 22954), -INT16_C( 15844), -INT16_C( 26684) },
          { -INT16_C( 13197),  INT16_C( 17023), -INT16_C( 13110),  INT16_C( 28984) } },
       INT32_C(           2) },
    { {  INT16_C(  2775), -INT16_C( 10977) },
        { {  INT16_C( 27235),  INT16_C( 25021),  INT16_C( 18464),  INT16_C(  2775) },
          {  INT16_C( 28343),  INT16_C( 18280),  INT16_C(  9770), -INT16_C( 10977) } },
       INT32_C(           3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4x2_t val = {
        {simde_vld1_s16(test_vec[i].val[0]), simde_vld1_s16(test_vec[i].val[1])}};
    int16_t a[2];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2_lane_s16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_i16(a[0], test_vec[i].a[0]);
    simde_assert_equal_i16(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    int16_t a[2];
    simde_int16x4x2_t val = simde_test_arm_neon_random_i16x4x2();
    const int lane = lanes[i];
    simde_vst2_lane_s16(a, val, lane);

    simde_test_codegen_write_vi16(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t val[2][4];
    int lane;
  } test_vec[] = {
    { {  INT32_C(   685474359),  INT32_C(  2131342498) },
        { {  INT32_C(   685474359), -INT32_C(  1864658893) },
          {  INT32_C(  2131342498), -INT32_C(   327239839) } },
       INT32_C(           0) },
    { { -INT32_C(  1321931919),  INT32_C(  2041075778) },
        { {  INT32_C(  1138576405), -INT32_C(  1321931919) },
          { -INT32_C(   288422633),  INT32_C(  2041075778) } },
       INT32_C(           1) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2x2_t val = {
        {simde_vld1_s32(test_vec[i].val[0]), simde_vld1_s32(test_vec[i].val[1])}};
    int32_t a[2];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2_lane_s32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_i32(a[0], test_vec[i].a[0]);
    simde_assert_equal_i32(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a[2];
    simde_int32x2x2_t val = simde_test_arm_neon_random_i32x2x2();
    const int lane = lanes[i];
    simde_vst2_lane_s32(a, val, lane);

    simde_test_codegen_write_vi32(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t val[2][1];
  } test_vec[] = {
    { { -INT64_C(  397998265130752573),  INT64_C(  509302689169805797) },
        { { -INT64_C(  397998265130752573) },
          {  INT64_C(  509302689169805797) } },
    },
    { { -INT64_C( 3177833508722953341),  INT64_C( 4924030339379107931) },
        { { -INT64_C( 3177833508722953341) },
          {  INT64_C( 4924030339379107931) } },
    }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1x2_t val = {
        {simde_vld1_s64(test_vec[i].val[0]), simde_vld1_s64(test_vec[i].val[1])}};
    int64_t a[2];
    simde_vst2_lane_s64(a, val, 0);
    simde_assert_equal_i64(a[0], test_vec[i].a[0]);
    simde_assert_equal_i64(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    int64_t a[2];
    simde_int64x1x2_t val = simde_test_arm_neon_random_i64x1x2();
    simde_vst2_lane_s64(a, val, 0);

    simde_test_codegen_write_vi64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[2];
    uint8_t val[2][8];
    int lane;
  } test_vec[] = {
    { { UINT8_C( 86), UINT8_C(248) },
        { { UINT8_C( 86), UINT8_C(213), UINT8_C(226), UINT8_C( 35), UINT8_C(160), UINT8_C( 71), UINT8_C( 37), UINT8_C(143) },
          { UINT8_C(248), UINT8_C( 33), UINT8_C( 59), UINT8_C(206), UINT8_C(106), UINT8_C(162), UINT8_C( 89), UINT8_C(239) } },
       INT32_C(           0) },
    { { UINT8_C(212), UINT8_C( 97) },
        { { UINT8_C( 47), UINT8_C(212), UINT8_C(160), UINT8_C(  6), UINT8_C(236), UINT8_C( 18), UINT8_C(159), UINT8_C(251) },
          { UINT8_C( 66), UINT8_C( 97), UINT8_C( 95), UINT8_C( 98), UINT8_C(222), UINT8_C(120), UINT8_C(130), UINT8_C( 52) } },
       INT32_C(           1) },
    { { UINT8_C( 87), UINT8_C(114) },
        { { UINT8_C( 77), UINT8_C(100), UINT8_C( 87), UINT8_C(237), UINT8_C(172), UINT8_C(125), UINT8_C(124), UINT8_C(164) },
          { UINT8_C(158), UINT8_C(183), UINT8_C(114), UINT8_C(  8), UINT8_C( 90), UINT8_C(203), UINT8_C(247), UINT8_C(137) } },
       INT32_C(           2) },
    { { UINT8_C(140), UINT8_C(110) },
        { { UINT8_C(160), UINT8_C(151), UINT8_C(144), UINT8_C(140), UINT8_C(170), UINT8_C( 47), UINT8_C(136), UINT8_C(236) },
          { UINT8_C(144), UINT8_C(231), UINT8_C( 78), UINT8_C(110), UINT8_C( 95), UINT8_C(209), UINT8_C(162), UINT8_C(172) } },
       INT32_C(           3) },
    { { UINT8_C(119), UINT8_C(195) },
        { { UINT8_C( 53), UINT8_C(250), UINT8_C(153), UINT8_C(225), UINT8_C(119), UINT8_C( 22), UINT8_C(133), UINT8_C( 21) },
          { UINT8_C(205), UINT8_C(247), UINT8_C( 29), UINT8_C( 39), UINT8_C(195), UINT8_C( 21), UINT8_C(177), UINT8_C( 99) } },
       INT32_C(           4) },
    { { UINT8_C(119), UINT8_C( 17) },
        { { UINT8_C(172), UINT8_C( 65), UINT8_C(239), UINT8_C( 86), UINT8_C(112), UINT8_C(119), UINT8_C( 67), UINT8_C(  0) },
          { UINT8_C( 94), UINT8_C(145), UINT8_C(111), UINT8_C(189), UINT8_C( 98), UINT8_C( 17), UINT8_C(105), UINT8_C(152) } },
       INT32_C(           5) },
    { { UINT8_C(151), UINT8_C( 28) },
        { { UINT8_C( 11), UINT8_C(  3), UINT8_C(121), UINT8_C(130), UINT8_C( 25),    UINT8_MAX, UINT8_C(151), UINT8_C(230) },
          { UINT8_C(246), UINT8_C(181), UINT8_C( 14), UINT8_C(185), UINT8_C(202), UINT8_C(191), UINT8_C( 28), UINT8_C(118) } },
       INT32_C(           6) },
    { { UINT8_C(226), UINT8_C(252) },
        { { UINT8_C(  0), UINT8_C( 12), UINT8_C(205), UINT8_C(112), UINT8_C(131), UINT8_C( 16), UINT8_C(112), UINT8_C(226) },
          { UINT8_C(161), UINT8_C(223), UINT8_C(159), UINT8_C(  4), UINT8_C(241), UINT8_C(  9), UINT8_C(156), UINT8_C(252) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8x2_t val = {
        {simde_vld1_u8(test_vec[i].val[0]), simde_vld1_u8(test_vec[i].val[1])}};
    uint8_t a[2];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2_lane_u8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_u8(a[0], test_vec[i].a[0]);
    simde_assert_equal_u8(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a[2];
    simde_uint8x8x2_t val = simde_test_arm_neon_random_u8x8x2();
    const int lane = lanes[i];
    simde_vst2_lane_u8(a, val, lane);

    simde_test_codegen_write_vu8(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[2];
    uint16_t val[2][4];
    int lane;
  } test_vec[] = {
    { { UINT16_C(62176), UINT16_C(46222) },
        { { UINT16_C(62176), UINT16_C(53589), UINT16_C(49850), UINT16_C(10054) },
          { UINT16_C(46222), UINT16_C(51489), UINT16_C( 9024), UINT16_C(42418) } },
       INT32_C(           0) },
    { { UINT16_C(23344), UINT16_C(57272) },
        { { UINT16_C(45667), UINT16_C(23344), UINT16_C(28231), UINT16_C(44285) },
          { UINT16_C( 4067), UINT16_C(57272), UINT16_C(29494), UINT16_C( 5829) } },
       INT32_C(           1) },
    { { UINT16_C(11997), UINT16_C(59276) },
        { { UINT16_C( 6758), UINT16_C( 8423), UINT16_C(11997), UINT16_C(27463) },
          { UINT16_C(26850), UINT16_C( 8757), UINT16_C(59276), UINT16_C(61383) } },
       INT32_C(           2) },
    { { UINT16_C(18828), UINT16_C( 7843) },
        { { UINT16_C(63385), UINT16_C(57419), UINT16_C(18533), UINT16_C(18828) },
          { UINT16_C(17495), UINT16_C(36136), UINT16_C(60856), UINT16_C( 7843) } },
       INT32_C(           3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4x2_t val = {
        {simde_vld1_u16(test_vec[i].val[0]), simde_vld1_u16(test_vec[i].val[1])}};
    uint16_t a[2];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2_lane_u16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_u16(a[0], test_vec[i].a[0]);
    simde_assert_equal_u16(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    uint16_t a[2];
    simde_uint16x4x2_t val = simde_test_arm_neon_random_u16x4x2();
    const int lane = lanes[i];
    simde_vst2_lane_u16(a, val, lane);

    simde_test_codegen_write_vu16(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t val[2][4];
    int lane;
  } test_vec[] = {
    { { UINT32_C(2944965963), UINT32_C( 388028227) },
        { { UINT32_C(2944965963), UINT32_C(3210285130) },
          { UINT32_C( 388028227), UINT32_C( 132153964) } },
      UINT32_C(         0) },
    { { UINT32_C(2036514196), UINT32_C( 178418110) },
        { { UINT32_C(3894994871), UINT32_C(2036514196) },
          { UINT32_C(2198664336), UINT32_C( 178418110) } },
      UINT32_C(         1) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2x2_t val = {
        {simde_vld1_u32(test_vec[i].val[0]), simde_vld1_u32(test_vec[i].val[1])}};
    uint32_t a[2];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2_lane_u32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_u32(a[0], test_vec[i].a[0]);
    simde_assert_equal_u32(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    uint32_t a[2];
    simde_uint32x2x2_t val = simde_test_arm_neon_random_u32x2x2();
    const int lane = lanes[i];
    simde_vst2_lane_u32(a, val, lane);

    simde_test_codegen_write_vu32(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t val[2][1];
  } test_vec[] = {
    { { UINT64_C( 4671586217597814761), UINT64_C( 9221507607604285949) },
        { { UINT64_C( 4671586217597814761) },
          { UINT64_C( 9221507607604285949) } },
    },
    { { UINT64_C(16667829075929106599), UINT64_C(  647665260169911972) },
        { { UINT64_C(16667829075929106599) },
          { UINT64_C(  647665260169911972) } },
    }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1x2_t val = {
        {simde_vld1_u64(test_vec[i].val[0]), simde_vld1_u64(test_vec[i].val[1])}};
    uint64_t a[2];
    simde_vst2_lane_u64(a, val, 0);
    simde_assert_equal_u64(a[0], test_vec[i].a[0]);
    simde_assert_equal_u64(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    uint64_t a[2];
    simde_uint64x1x2_t val = simde_test_arm_neon_random_u64x1x2();
    simde_vst2_lane_u64(a, val, 0);

    simde_test_codegen_write_vu64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t val[2][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    72.16), SIMDE_FLOAT32_C(    51.97) },
        { { SIMDE_FLOAT32_C(    72.16), SIMDE_FLOAT32_C(   -27.20) },
          { SIMDE_FLOAT32_C(    51.97), SIMDE_FLOAT32_C(   -29.61) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT32_C(   -89.88), SIMDE_FLOAT32_C(    88.55) },
        { { SIMDE_FLOAT32_C(   -75.64), SIMDE_FLOAT32_C(   -89.88) },
          { SIMDE_FLOAT32_C(    52.86), SIMDE_FLOAT32_C(    88.55) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2x2_t val = {
        {simde_vld1_f32(test_vec[i].val[0]), simde_vld1_f32(test_vec[i].val[1])}};
    simde_float32_t a[2];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2_lane_f32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_f32(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f32(a[1], test_vec[i].a[1], 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32_t a[2];
    simde_float32x2x2_t val = simde_test_arm_neon_random_f32x2x2(-100.0f, 100.0f);
    const int lane = lanes[i];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2_lane_f32, HEDLEY_UNREACHABLE(),
                                lane, a, val);

    simde_test_codegen_write_vf32(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t val[2][1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -59.48), SIMDE_FLOAT64_C(    20.76) },
        { { SIMDE_FLOAT64_C(   -59.48) },
          { SIMDE_FLOAT64_C(    20.76) } },
    },
    { { SIMDE_FLOAT64_C(   -99.14), SIMDE_FLOAT64_C(   -99.40) },
        { { SIMDE_FLOAT64_C(   -99.14) },
          { SIMDE_FLOAT64_C(   -99.40) } },
    }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1x2_t val = {
        {simde_vld1_f64(test_vec[i].val[0]), simde_vld1_f64(test_vec[i].val[1])}};
    simde_float64_t a[2];
    simde_vst2_lane_f64(a, val, 0);
    simde_assert_equal_f64(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f64(a[1], test_vec[i].a[1], 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64_t a[2];
    simde_float64x1x2_t val = simde_test_arm_neon_random_f64x1x2(-100.0, 100.0);
    simde_vst2_lane_f64(a, val, 0);

    simde_test_codegen_write_vf64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[2];
    int8_t val[2][16];
    int lane;
  } test_vec[] = {
    { { -INT8_C(   7), -INT8_C(   7) },
        { { -INT8_C(   7),  INT8_C( 109), -INT8_C(  86),  INT8_C( 126), -INT8_C(  99),  INT8_C(  23),  INT8_C(  20),  INT8_C(   7),
             INT8_C(  35), -INT8_C(  95), -INT8_C(  72), -INT8_C( 122), -INT8_C( 112), -INT8_C(  90),  INT8_C(  39), -INT8_C(  28) },
          { -INT8_C(   7), -INT8_C(  14),  INT8_C(  72), -INT8_C( 117),  INT8_C( 100),  INT8_C(  33),  INT8_C(   0), -INT8_C(  61),
            -INT8_C(  29),  INT8_C(  70), -INT8_C(  57),  INT8_C(  77),  INT8_C(  63),      INT8_MAX,  INT8_C(  40),  INT8_C(  57) } },
       INT32_C(           0) },
    { { -INT8_C(  46),  INT8_C(  41) },
        { { -INT8_C(  20), -INT8_C(  46), -INT8_C(  73), -INT8_C( 118), -INT8_C(  22), -INT8_C(  53), -INT8_C( 111),  INT8_C(  13),
             INT8_C( 108),  INT8_C(  74), -INT8_C( 109), -INT8_C(   4), -INT8_C(  16), -INT8_C(  70), -INT8_C(  32), -INT8_C(  23) },
          { -INT8_C(  84),  INT8_C(  41),  INT8_C( 116),  INT8_C(  16),  INT8_C(  74),  INT8_C( 116), -INT8_C(  45),  INT8_C(  45),
            -INT8_C(  69), -INT8_C( 102),  INT8_C( 122), -INT8_C(   6),  INT8_C(  25), -INT8_C(  94),  INT8_C(  51),  INT8_C(   6) } },
       INT32_C(           1) },
    { { -INT8_C( 112),  INT8_C( 117) },
        { {  INT8_C( 117), -INT8_C(  22), -INT8_C( 112),  INT8_C(  95), -INT8_C(  74),  INT8_C(  33),  INT8_C( 108),  INT8_C(  34),
             INT8_C( 107), -INT8_C(   1),  INT8_C(  31),  INT8_C(  92), -INT8_C(  71), -INT8_C(   1),  INT8_C(  69),  INT8_C( 101) },
          {  INT8_C(  40), -INT8_C(  70),  INT8_C( 117),  INT8_C( 114),  INT8_C(  46),  INT8_C(  72), -INT8_C(  96), -INT8_C(  23),
            -INT8_C(  30),  INT8_C(  26), -INT8_C(  28), -INT8_C(   4), -INT8_C(  67),  INT8_C(  23),  INT8_C(   2),  INT8_C(  50) } },
       INT32_C(           2) },
    { { -INT8_C(  72), -INT8_C(  87) },
        { {  INT8_C(   2), -INT8_C( 110), -INT8_C( 111), -INT8_C(  72), -INT8_C(  77), -INT8_C(   3), -INT8_C(  38),  INT8_C(  31),
            -INT8_C(   4), -INT8_C(   7),  INT8_C( 123), -INT8_C(  75), -INT8_C(   7), -INT8_C(  64),  INT8_C(  26),  INT8_C(  33) },
          {  INT8_C( 122), -INT8_C( 113), -INT8_C( 108), -INT8_C(  87), -INT8_C(  41),  INT8_C(  52), -INT8_C( 110), -INT8_C(  71),
             INT8_C(  78),  INT8_C( 118), -INT8_C(  75),  INT8_C(  11), -INT8_C( 114), -INT8_C(  73),  INT8_C(  61), -INT8_C( 112) } },
       INT32_C(           3) },
    { { -INT8_C(  53), -INT8_C(   2) },
        { {  INT8_C(  73), -INT8_C(  50),  INT8_C(  72), -INT8_C(   3), -INT8_C(  53),  INT8_C(  34),  INT8_C(  28), -INT8_C(  57),
             INT8_C(  28), -INT8_C( 105),  INT8_C( 124),  INT8_C(  21),  INT8_C(  87), -INT8_C( 106),  INT8_C(  54), -INT8_C(  46) },
          {  INT8_C(  37), -INT8_C(  54),  INT8_C( 123), -INT8_C(   4), -INT8_C(   2),  INT8_C(  13), -INT8_C(  74),  INT8_C(  77),
            -INT8_C( 124),  INT8_C( 107),  INT8_C(  88),  INT8_C(  18),  INT8_C(  35), -INT8_C( 106), -INT8_C(  94),  INT8_C( 108) } },
       INT32_C(           4) },
    { { -INT8_C( 123), -INT8_C(  30) },
        { {  INT8_C( 100), -INT8_C(  22),  INT8_C( 105),  INT8_C(  48),  INT8_C(  12), -INT8_C( 123), -INT8_C(   9),  INT8_C(  40),
             INT8_C(  28),  INT8_C( 116),  INT8_C(  61),  INT8_C( 116),  INT8_C(  10),  INT8_C( 116),  INT8_C(  70),  INT8_C(  48) },
          {  INT8_C(  62), -INT8_C(  63),  INT8_C(  44),  INT8_C(  61), -INT8_C(  50), -INT8_C(  30), -INT8_C( 118),  INT8_C(  82),
             INT8_C(  78), -INT8_C(  30),  INT8_C( 100),  INT8_C( 113),  INT8_C( 120),  INT8_C(   6), -INT8_C(  35), -INT8_C(  35) } },
       INT32_C(           5) },
    { {  INT8_C(  37), -INT8_C( 123) },
        { { -INT8_C(  16),  INT8_C(  71),  INT8_C(  13), -INT8_C(   3), -INT8_C(  52),  INT8_C(   4),  INT8_C(  37), -INT8_C(  23),
             INT8_C( 120),  INT8_C(  99),  INT8_C(  93), -INT8_C( 125), -INT8_C(  41), -INT8_C(  93), -INT8_C(  77),  INT8_C(  21) },
          {  INT8_C( 100), -INT8_C(  33),  INT8_C(  82),  INT8_C(  50), -INT8_C(  62), -INT8_C(  36), -INT8_C( 123),  INT8_C(  16),
            -INT8_C(  65), -INT8_C(  23), -INT8_C( 127),  INT8_C(  55), -INT8_C(  16),  INT8_C(  94),  INT8_C(  20), -INT8_C(  32) } },
       INT32_C(           6) },
    { { -INT8_C(  98),  INT8_C(  64) },
        { { -INT8_C(  91),  INT8_C(  33), -INT8_C(  35),  INT8_C( 114),  INT8_C(  38),  INT8_C(   3),  INT8_C(  91), -INT8_C(  98),
             INT8_C( 102), -INT8_C(  72),  INT8_C(  33),  INT8_C(  61),  INT8_C(  91), -INT8_C(  44),  INT8_C(  82), -INT8_C(  65) },
          { -INT8_C(  76), -INT8_C(  91), -INT8_C(  15),  INT8_C( 118), -INT8_C( 127),  INT8_C( 118), -INT8_C( 122),  INT8_C(  64),
             INT8_C(  96),  INT8_C(   7),  INT8_C( 120),  INT8_C(  80),  INT8_C( 101), -INT8_C( 116),  INT8_C(  48),  INT8_C(  11) } },
       INT32_C(           7) },
    { { -INT8_C( 112),  INT8_C(  31) },
        { { -INT8_C(  82),  INT8_C(  14),  INT8_C( 125), -INT8_C(  44),  INT8_C(  17), -INT8_C(  40),  INT8_C( 114),  INT8_C( 119),
            -INT8_C( 112), -INT8_C( 108), -INT8_C(  76), -INT8_C(  21),  INT8_C( 104),  INT8_C(   6), -INT8_C(  86),  INT8_C(  28) },
          { -INT8_C(  85), -INT8_C( 101), -INT8_C( 110),  INT8_C(  45),  INT8_C(  18),  INT8_C(  24),  INT8_C( 109),  INT8_C( 114),
             INT8_C(  31), -INT8_C(  27), -INT8_C(  62), -INT8_C( 123),  INT8_C( 114), -INT8_C(  14), -INT8_C( 112),  INT8_C(  32) } },
       INT32_C(           8) },
    { {  INT8_C(  60), -INT8_C(  21) },
        { {  INT8_C(   0),  INT8_C(  13), -INT8_C(  12),  INT8_C(  17), -INT8_C(  27),  INT8_C( 102), -INT8_C( 120),  INT8_C( 117),
            -INT8_C(   6),  INT8_C(  60),  INT8_C(  96),  INT8_C(  99),  INT8_C(  67),  INT8_C(  10),      INT8_MAX, -INT8_C(  18) },
          { -INT8_C(  91),  INT8_C(  18),  INT8_C(  27), -INT8_C(  73),  INT8_C(  42), -INT8_C( 119),  INT8_C(  41),  INT8_C(  74),
             INT8_C( 110), -INT8_C(  21), -INT8_C(  49), -INT8_C(  32), -INT8_C(  34),  INT8_C(  95),  INT8_C(   0), -INT8_C(  34) } },
       INT32_C(           9) },
    { { -INT8_C(  72), -INT8_C(  38) },
        { {  INT8_C( 108), -INT8_C(  12), -INT8_C(  16),  INT8_C(  81),  INT8_C(  91),  INT8_C( 120), -INT8_C(  58),  INT8_C(  85),
            -INT8_C(  75),  INT8_C(  38), -INT8_C(  72), -INT8_C(   8),  INT8_C(  48),  INT8_C(  56), -INT8_C(  26), -INT8_C(  43) },
          {  INT8_C(  74),  INT8_C(   2), -INT8_C( 115),  INT8_C( 116), -INT8_C( 117), -INT8_C(  74), -INT8_C(  66), -INT8_C(   7),
            -INT8_C(  94), -INT8_C( 115), -INT8_C(  38),      INT8_MIN, -INT8_C(  20), -INT8_C(  38),  INT8_C(  94),  INT8_C(  88) } },
       INT32_C(          10) },
    { { -INT8_C(  59),  INT8_C( 103) },
        { { -INT8_C(  49),  INT8_C(  78), -INT8_C(  87),  INT8_C(  42), -INT8_C(  57),  INT8_C( 111),      INT8_MAX,  INT8_C( 124),
            -INT8_C( 107),  INT8_C(  56),  INT8_C( 116), -INT8_C(  59),  INT8_C( 112),  INT8_C(  90), -INT8_C( 101), -INT8_C(  70) },
          {  INT8_C(  92),  INT8_C(  40),  INT8_C(  46), -INT8_C(  25), -INT8_C(  34), -INT8_C(  19), -INT8_C(  31),      INT8_MIN,
             INT8_C( 122), -INT8_C(  69),  INT8_C(   0),  INT8_C( 103), -INT8_C( 107),  INT8_C(  95), -INT8_C(  65),  INT8_C( 100) } },
       INT32_C(          11) },
    { { -INT8_C(  65), -INT8_C(  75) },
        { { -INT8_C(  83),  INT8_C( 105), -INT8_C( 114),  INT8_C( 116), -INT8_C(  40),  INT8_C(  14), -INT8_C(  16),  INT8_C( 110),
             INT8_C(  70),  INT8_C( 100),  INT8_C(  51), -INT8_C(  74), -INT8_C(  65), -INT8_C(  50),  INT8_C( 112),  INT8_C(  27) },
          { -INT8_C(  10), -INT8_C(  98),  INT8_C(   3), -INT8_C(  43), -INT8_C( 117), -INT8_C(  28),  INT8_C(  85),  INT8_C(   6),
            -INT8_C(  97),  INT8_C(  86),  INT8_C( 109),  INT8_C(  52), -INT8_C(  75),  INT8_C(  44), -INT8_C( 103),  INT8_C(  98) } },
       INT32_C(          12) },
    { { -INT8_C(  95),  INT8_C(  90) },
        { { -INT8_C( 107),  INT8_C(  39), -INT8_C(  41),  INT8_C( 110),  INT8_C(  53), -INT8_C(  57), -INT8_C(  36),  INT8_C( 123),
             INT8_C(  44),  INT8_C(  15),  INT8_C(  49), -INT8_C(  21), -INT8_C(  34), -INT8_C(  95),  INT8_C(   6), -INT8_C(  44) },
          {  INT8_C(  64),  INT8_C(   9), -INT8_C(  87), -INT8_C(  53), -INT8_C(  19), -INT8_C(   1), -INT8_C(  47), -INT8_C( 116),
             INT8_C(  85),  INT8_C(  62), -INT8_C(  63),  INT8_C(  10),  INT8_C( 107),  INT8_C(  90),  INT8_C( 108),  INT8_C(   0) } },
       INT32_C(          13) },
    { {  INT8_C(  12), -INT8_C( 116) },
        { { -INT8_C( 127),  INT8_C(  67),  INT8_C( 110), -INT8_C(  73),  INT8_C(  11),  INT8_C(  74),  INT8_C(  50),  INT8_C(  55),
             INT8_C(  90),  INT8_C( 100),  INT8_C(  34),  INT8_C(  56),  INT8_C(   5),  INT8_C(  40),  INT8_C(  12),  INT8_C(  69) },
          {  INT8_C(  50), -INT8_C(  74),  INT8_C(  17),  INT8_C(  31), -INT8_C(  75), -INT8_C(  30), -INT8_C(  84),  INT8_C(  10),
             INT8_C(  33),  INT8_C( 109),  INT8_C(  20), -INT8_C( 116), -INT8_C(  57),      INT8_MIN, -INT8_C( 116),  INT8_C(  72) } },
       INT32_C(          14) },
    { { -INT8_C( 126), -INT8_C(  79) },
        { { -INT8_C(  60), -INT8_C(   5), -INT8_C(   1), -INT8_C(  49),  INT8_C(  69),  INT8_C(  50),  INT8_C(   6), -INT8_C(  97),
            -INT8_C( 106),  INT8_C(  40), -INT8_C(  41), -INT8_C( 101),  INT8_C(  80), -INT8_C(  28), -INT8_C(  31), -INT8_C( 126) },
          { -INT8_C( 102), -INT8_C(  14), -INT8_C(  94),  INT8_C(  79), -INT8_C(  44),  INT8_C(  78),  INT8_C(  89), -INT8_C(  11),
            -INT8_C(  69),  INT8_C( 109), -INT8_C( 127), -INT8_C( 126), -INT8_C(  19),  INT8_C(  14), -INT8_C(  54), -INT8_C(  79) } },
       INT32_C(          15) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16x2_t val = {
        {simde_vld1q_s8(test_vec[i].val[0]), simde_vld1q_s8(test_vec[i].val[1])}};
    int8_t a[2];
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst2q_lane_s8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_i8(a[0], test_vec[i].a[0]);
    simde_assert_equal_i8(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    int8_t a[2];
    simde_int8x16x2_t val = simde_test_arm_neon_random_i8x16x2();
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst2q_lane_s8, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vi8(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[2];
    int16_t val[2][8];
    int lane;
  } test_vec[] = {
    { { -INT16_C(  1645), -INT16_C(  4793) },
        { { -INT16_C(  1645), -INT16_C( 24861),  INT16_C( 17145), -INT16_C( 11614),  INT16_C( 24268), -INT16_C( 12170),  INT16_C( 30371),  INT16_C(  2790) },
          { -INT16_C(  4793), -INT16_C(  4409),  INT16_C( 28826),  INT16_C( 10924), -INT16_C(  7998), -INT16_C( 17244), -INT16_C( 20079),  INT16_C(  9289) } },
       INT32_C(           0) },
    { { -INT16_C( 23614),  INT16_C( 31128) },
        { {  INT16_C( 11434), -INT16_C( 23614),  INT16_C( 25967),  INT16_C( 15222), -INT16_C(  4925),  INT16_C( 26123), -INT16_C(  3742), -INT16_C( 22159) },
          {  INT16_C( 14559),  INT16_C( 31128),  INT16_C( 17576),  INT16_C( 27555),  INT16_C( 18468), -INT16_C( 19161),  INT16_C( 28921), -INT16_C( 23590) } },
       INT32_C(           1) },
    { { -INT16_C( 17151),  INT16_C( 16273) },
        { { -INT16_C( 25444),  INT16_C(  2887), -INT16_C( 17151), -INT16_C( 15034),  INT16_C( 21161),  INT16_C(  2859), -INT16_C( 25533),  INT16_C(  8884) },
          {  INT16_C( 19668),  INT16_C( 32156),  INT16_C( 16273), -INT16_C( 18968),  INT16_C(  3975), -INT16_C( 32661),  INT16_C( 17791),  INT16_C(  6948) } },
       INT32_C(           2) },
    { { -INT16_C( 11864), -INT16_C( 30685) },
        { {  INT16_C( 27617), -INT16_C(  7385),  INT16_C( 27944), -INT16_C( 11864), -INT16_C( 11329),  INT16_C(   988), -INT16_C( 28560),  INT16_C( 17445) },
          { -INT16_C( 15907),  INT16_C( 28353), -INT16_C( 22271), -INT16_C( 30685), -INT16_C( 29000),  INT16_C( 14089),  INT16_C( 11731), -INT16_C( 19117) } },
       INT32_C(           3) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8x2_t val = {
        {simde_vld1q_s16(test_vec[i].val[0]), simde_vld1q_s16(test_vec[i].val[1])}};
    int16_t a[2];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2q_lane_s16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_i16(a[0], test_vec[i].a[0]);
    simde_assert_equal_i16(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    int16_t a[2];
    simde_int16x8x2_t val = simde_test_arm_neon_random_i16x8x2();
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2q_lane_s16, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vi16(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t val[2][4];
    int lane;
  } test_vec[] = {
    { { -INT32_C(  1348169051), -INT32_C(  1971061681) },
        { { -INT32_C(  1348169051), -INT32_C(   244800754), -INT32_C(  1852651014),  INT32_C(   174768526) },
          { -INT32_C(  1971061681), -INT32_C(  1694362323), -INT32_C(  1354620763), -INT32_C(   365941691) } },
       INT32_C(           0) },
    { {  INT32_C(  1908277879), -INT32_C(  1573785860) },
        { { -INT32_C(   845556546),  INT32_C(  1908277879),  INT32_C(  1493323979),  INT32_C(  1633971474) },
          { -INT32_C(  1762859159), -INT32_C(  1573785860),  INT32_C(  1414624015),  INT32_C(  1581154720) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4x2_t val = {
        {simde_vld1q_s32(test_vec[i].val[0]), simde_vld1q_s32(test_vec[i].val[1])}};
    int32_t a[2];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2q_lane_s32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_i32(a[0], test_vec[i].a[0]);
    simde_assert_equal_i32(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a[2];
    simde_int32x4x2_t val = simde_test_arm_neon_random_i32x4x2();
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2q_lane_s32, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vi32(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t val[2][2];
    int lane;
  } test_vec[] = {
    { { -INT64_C( 4913848843381478676), -INT64_C( 1461121549592715451) },
        { { -INT64_C( 4913848843381478676),  INT64_C( 8754296828128678193) },
          { -INT64_C( 1461121549592715451),  INT64_C( 8366024034782216183) } },
       INT32_C(           0) },
    { {  INT64_C( 8546650324483419789),  INT64_C( 3626080161181637461) },
        { {  INT64_C( 1566756666084320128),  INT64_C( 8546650324483419789) },
          {  INT64_C( 8865712466904774508),  INT64_C( 3626080161181637461) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2x2_t val = {
        {simde_vld1q_s64(test_vec[i].val[0]), simde_vld1q_s64(test_vec[i].val[1])}};
    int64_t a[2];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2q_lane_s64, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_i64(a[0], test_vec[i].a[0]);
    simde_assert_equal_i64(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    int64_t a[2];
    simde_int64x2x2_t val = simde_test_arm_neon_random_i64x2x2();
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2q_lane_s64, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vi64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[2];
    uint8_t val[2][16];
    int lane;
  } test_vec[] = {
    { { UINT8_C( 71), UINT8_C( 25) },
       { { UINT8_C( 71), UINT8_C( 85),    UINT8_MAX, UINT8_C(102), UINT8_C(183), UINT8_C( 90), UINT8_C(244), UINT8_C(119),
           UINT8_C( 82), UINT8_C(121), UINT8_C(170), UINT8_C( 57), UINT8_C(205), UINT8_C( 17), UINT8_C( 28), UINT8_C( 56) },
         { UINT8_C( 25), UINT8_C( 14), UINT8_C(246), UINT8_C(245), UINT8_C(205), UINT8_C( 44), UINT8_C(128), UINT8_C(197),
           UINT8_C( 51), UINT8_C( 39), UINT8_C(166), UINT8_C(238), UINT8_C(218), UINT8_C(175), UINT8_C( 52), UINT8_C( 33) } },
      INT32_C(           0) },
   { { UINT8_C( 51), UINT8_C(240) },
       { { UINT8_C(  4), UINT8_C( 51), UINT8_C(135), UINT8_C(187), UINT8_C(141), UINT8_C(123), UINT8_C( 51), UINT8_C(224),
           UINT8_C(244), UINT8_C(221), UINT8_C( 25), UINT8_C(194), UINT8_C(238), UINT8_C( 53), UINT8_C(250), UINT8_C(  7) },
         { UINT8_C( 67), UINT8_C(240), UINT8_C(252), UINT8_C( 16), UINT8_C( 28), UINT8_C(124), UINT8_C(214), UINT8_C( 80),
           UINT8_C(164), UINT8_C(124), UINT8_C( 62), UINT8_C(126), UINT8_C( 44), UINT8_C(114), UINT8_C(159), UINT8_C( 48) } },
      INT32_C(           1) },
   { { UINT8_C(236), UINT8_C(181) },
       { { UINT8_C(165), UINT8_C( 38), UINT8_C(236), UINT8_C( 51), UINT8_C(162), UINT8_C( 31), UINT8_C( 19), UINT8_C(150),
           UINT8_C(252), UINT8_C( 44), UINT8_C( 88), UINT8_C(234), UINT8_C( 97), UINT8_C( 83), UINT8_C(242), UINT8_C(165) },
         { UINT8_C( 67), UINT8_C(238), UINT8_C(181), UINT8_C( 96), UINT8_C(107), UINT8_C(139), UINT8_C(176), UINT8_C( 15),
           UINT8_C(  8), UINT8_C(238), UINT8_C(141), UINT8_C( 52), UINT8_C( 97), UINT8_C( 44), UINT8_C(100), UINT8_C(  6) } },
      INT32_C(           2) },
   { { UINT8_C(244), UINT8_C(161) },
       { { UINT8_C( 82), UINT8_C( 80), UINT8_C( 57), UINT8_C(244), UINT8_C(111), UINT8_C( 76), UINT8_C(139), UINT8_C(107),
           UINT8_C(120), UINT8_C(227), UINT8_C( 86), UINT8_C(218), UINT8_C( 54), UINT8_C( 72), UINT8_C(127), UINT8_C(122) },
         { UINT8_C( 54), UINT8_C( 52), UINT8_C(218), UINT8_C(161), UINT8_C(192), UINT8_C(138), UINT8_C(176), UINT8_C(200),
           UINT8_C(120), UINT8_C( 61), UINT8_C(252), UINT8_C(217), UINT8_C(105), UINT8_C( 96), UINT8_C(224), UINT8_C(188) } },
      INT32_C(           3) },
   { { UINT8_C(102), UINT8_C( 51) },
       { { UINT8_C(177), UINT8_C( 25), UINT8_C(176), UINT8_C( 32), UINT8_C(102), UINT8_C( 59), UINT8_C(140), UINT8_C(222),
           UINT8_C( 31), UINT8_C(226), UINT8_C(184), UINT8_C( 85), UINT8_C( 42), UINT8_C( 55), UINT8_C(207), UINT8_C( 96) },
         { UINT8_C(108), UINT8_C(169), UINT8_C(  2), UINT8_C( 44), UINT8_C( 51), UINT8_C(178), UINT8_C(244), UINT8_C(172),
           UINT8_C(240), UINT8_C(240), UINT8_C(133), UINT8_C( 89), UINT8_C( 80), UINT8_C(101), UINT8_C( 21), UINT8_C(  1) } },
      INT32_C(           4) },
   { { UINT8_C(174), UINT8_C( 63) },
       { { UINT8_C(127), UINT8_C(198), UINT8_C( 34), UINT8_C(229), UINT8_C(  1), UINT8_C(174), UINT8_C(195), UINT8_C( 32),
           UINT8_C(144), UINT8_C(124), UINT8_C(118), UINT8_C(186), UINT8_C(179), UINT8_C( 69), UINT8_C( 26), UINT8_C( 31) },
         { UINT8_C(239), UINT8_C( 28), UINT8_C( 75), UINT8_C( 34), UINT8_C(207), UINT8_C( 63), UINT8_C(206), UINT8_C(191),
           UINT8_C( 47), UINT8_C( 84), UINT8_C( 24), UINT8_C(128), UINT8_C(185), UINT8_C( 46), UINT8_C(129), UINT8_C( 56) } },
      INT32_C(           5) },
   { { UINT8_C( 22), UINT8_C( 96) },
       { { UINT8_C(244), UINT8_C(163), UINT8_C( 29), UINT8_C(245), UINT8_C( 81), UINT8_C(225), UINT8_C( 22), UINT8_C(225),
           UINT8_C( 93), UINT8_C(140), UINT8_C(155), UINT8_C( 16), UINT8_C(209), UINT8_C(182), UINT8_C( 48), UINT8_C(192) },
         { UINT8_C(210), UINT8_C(123), UINT8_C(227), UINT8_C(161), UINT8_C(187), UINT8_C(177), UINT8_C( 96), UINT8_C(234),
           UINT8_C(  5), UINT8_C(121), UINT8_C(106), UINT8_C(191), UINT8_C(167), UINT8_C(236), UINT8_C(247), UINT8_C(155) } },
      INT32_C(           6) },
   { { UINT8_C( 83), UINT8_C( 94) },
       { { UINT8_C(143), UINT8_C( 21), UINT8_C(144), UINT8_C(225), UINT8_C(246), UINT8_C(166), UINT8_C(194), UINT8_C( 83),
           UINT8_C( 50), UINT8_C( 94), UINT8_C( 99), UINT8_C(  4), UINT8_C( 20), UINT8_C(147), UINT8_C(196), UINT8_C(230) },
         { UINT8_C( 15), UINT8_C(167), UINT8_C(136), UINT8_C(202), UINT8_C( 89), UINT8_C(232), UINT8_C(180), UINT8_C( 94),
           UINT8_C( 97), UINT8_C( 31), UINT8_C( 29), UINT8_C(  8), UINT8_C( 11), UINT8_C( 21), UINT8_C(163), UINT8_C(154) } },
      INT32_C(           7) },
   { { UINT8_C(156), UINT8_C( 22) },
       { { UINT8_C( 42), UINT8_C( 52), UINT8_C(123), UINT8_C( 32), UINT8_C(218), UINT8_C( 62), UINT8_C(115), UINT8_C( 13),
           UINT8_C(156), UINT8_C(214), UINT8_C( 17), UINT8_C(176), UINT8_C(106), UINT8_C(213), UINT8_C(150), UINT8_C(121) },
         { UINT8_C(125), UINT8_C( 30), UINT8_C( 67), UINT8_C(214), UINT8_C(  7), UINT8_C(247), UINT8_C( 52), UINT8_C(104),
           UINT8_C( 22), UINT8_C( 82), UINT8_C(113), UINT8_C( 33), UINT8_C(103), UINT8_C( 20), UINT8_C(188), UINT8_C(145) } },
      INT32_C(           8) },
   { { UINT8_C( 65), UINT8_C( 87) },
       { { UINT8_C( 72), UINT8_C( 55), UINT8_C(177), UINT8_C( 35), UINT8_C(117), UINT8_C( 36), UINT8_C( 48), UINT8_C( 17),
           UINT8_C(250), UINT8_C( 65), UINT8_C(193), UINT8_C(100), UINT8_C( 22), UINT8_C( 88), UINT8_C(221), UINT8_C(147) },
         { UINT8_C(118), UINT8_C( 32), UINT8_C(105), UINT8_C(125), UINT8_C( 24), UINT8_C(158), UINT8_C(230), UINT8_C( 46),
           UINT8_C(240), UINT8_C( 87), UINT8_C( 80), UINT8_C( 87), UINT8_C(107), UINT8_C( 12), UINT8_C(232), UINT8_C(180) } },
      INT32_C(           9) },
   { { UINT8_C( 28), UINT8_C( 64) },
       { { UINT8_C( 67), UINT8_C(153), UINT8_C(215), UINT8_C(185), UINT8_C(189), UINT8_C(  7), UINT8_C(202), UINT8_C(183),
           UINT8_C( 72), UINT8_C(140), UINT8_C( 28), UINT8_C( 94), UINT8_C(228), UINT8_C(249), UINT8_C(242), UINT8_C( 90) },
         { UINT8_C( 26), UINT8_C( 91), UINT8_C(216), UINT8_C( 50), UINT8_C(249), UINT8_C(190), UINT8_C( 96), UINT8_C(233),
           UINT8_C( 21), UINT8_C(176), UINT8_C( 64), UINT8_C(128), UINT8_C(188), UINT8_C( 40), UINT8_C( 52), UINT8_C(  0) } },
      INT32_C(          10) },
   { { UINT8_C(243), UINT8_C(101) },
       { { UINT8_C(193), UINT8_C( 11), UINT8_C(185), UINT8_C(126), UINT8_C( 18), UINT8_C(131), UINT8_C( 54), UINT8_C( 90),
           UINT8_C( 15), UINT8_C( 82), UINT8_C(185), UINT8_C(243), UINT8_C( 75), UINT8_C(171), UINT8_C( 78), UINT8_C(101) },
         { UINT8_C(  6), UINT8_C( 38), UINT8_C(151), UINT8_C(  0), UINT8_C(228), UINT8_C(248), UINT8_C(233), UINT8_C(249),
           UINT8_C(168), UINT8_C( 42), UINT8_C(121), UINT8_C(101), UINT8_C( 82), UINT8_C(174), UINT8_C(101), UINT8_C( 20) } },
      INT32_C(          11) },
   { { UINT8_C(138), UINT8_C( 29) },
       { { UINT8_C(185), UINT8_C( 30), UINT8_C(146), UINT8_C(204), UINT8_C(161), UINT8_C(200), UINT8_C( 38), UINT8_C(177),
           UINT8_C( 26), UINT8_C(223), UINT8_C(164), UINT8_C(102), UINT8_C(138), UINT8_C(242), UINT8_C(203), UINT8_C(145) },
         { UINT8_C( 24), UINT8_C( 99), UINT8_C(145), UINT8_C(252), UINT8_C( 91), UINT8_C(122), UINT8_C(245), UINT8_C(  3),
           UINT8_C(164), UINT8_C(111), UINT8_C(104), UINT8_C(247), UINT8_C( 29), UINT8_C(205), UINT8_C( 11), UINT8_C(214) } },
      INT32_C(          12) },
   { { UINT8_C(178), UINT8_C(118) },
       { { UINT8_C(235), UINT8_C(157), UINT8_C(162), UINT8_C(141), UINT8_C(102), UINT8_C(201), UINT8_C( 62), UINT8_C(128),
           UINT8_C(168), UINT8_C(226), UINT8_C(230), UINT8_C( 51), UINT8_C(213), UINT8_C(178), UINT8_C(196), UINT8_C(237) },
         { UINT8_C( 21), UINT8_C( 85), UINT8_C(234), UINT8_C(112), UINT8_C(207), UINT8_C(223), UINT8_C(115), UINT8_C(116),
           UINT8_C( 78), UINT8_C(220), UINT8_C(107), UINT8_C(107), UINT8_C(169), UINT8_C(118), UINT8_C( 66), UINT8_C(149) } },
      INT32_C(          13) },
   { { UINT8_C(  5), UINT8_C(165) },
       { { UINT8_C( 19), UINT8_C(228), UINT8_C( 34), UINT8_C(121), UINT8_C(173), UINT8_C( 96), UINT8_C(250), UINT8_C( 86),
           UINT8_C( 66), UINT8_C(224), UINT8_C(137), UINT8_C( 23), UINT8_C(146), UINT8_C( 77), UINT8_C(  5), UINT8_C(167) },
         { UINT8_C(162), UINT8_C(239), UINT8_C( 23), UINT8_C(113), UINT8_C(206), UINT8_C(139), UINT8_C(229), UINT8_C( 29),
           UINT8_C(103), UINT8_C( 80), UINT8_C(136), UINT8_C( 16), UINT8_C(198), UINT8_C(202), UINT8_C(165), UINT8_C(218) } },
      INT32_C(          14) },
   { { UINT8_C( 42), UINT8_C( 99) },
       { { UINT8_C(175), UINT8_C(199), UINT8_C( 83), UINT8_C( 92), UINT8_C( 39), UINT8_C( 77), UINT8_C(178), UINT8_C(106),
           UINT8_C( 46), UINT8_C( 59), UINT8_C(129), UINT8_C(192), UINT8_C(136), UINT8_C(134), UINT8_C(104), UINT8_C( 42) },
         { UINT8_C(117), UINT8_C(127), UINT8_C(156), UINT8_C( 68), UINT8_C( 10), UINT8_C(129), UINT8_C( 97), UINT8_C(113),
           UINT8_C(210), UINT8_C(233), UINT8_C(130), UINT8_C(152), UINT8_C(180), UINT8_C( 39), UINT8_C(114), UINT8_C( 99) } },
      INT32_C(          15) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16x2_t val = {
        {simde_vld1q_u8(test_vec[i].val[0]), simde_vld1q_u8(test_vec[i].val[1])}};
    uint8_t a[2];
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst2q_lane_u8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_u8(a[0], test_vec[i].a[0]);
    simde_assert_equal_u8(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    uint8_t a[2];
    simde_uint8x16x2_t val = simde_test_arm_neon_random_u8x16x2();
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst2q_lane_u8, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vu8(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[2];
    uint16_t val[2][8];
    int lane;
  } test_vec[] = {
    { { UINT16_C( 3022), UINT16_C(12326) },
        { { UINT16_C( 3022), UINT16_C(52482), UINT16_C(55639), UINT16_C( 9568), UINT16_C(19124), UINT16_C(13154), UINT16_C(58494), UINT16_C(23527) },
          { UINT16_C(12326), UINT16_C( 8574), UINT16_C( 9703), UINT16_C( 2390), UINT16_C(29989), UINT16_C(61143), UINT16_C(40579), UINT16_C(21091) } },
       INT32_C(           0) },
    { { UINT16_C(  287), UINT16_C( 9908) },
        { { UINT16_C(26025), UINT16_C(  287), UINT16_C(32574), UINT16_C(62246), UINT16_C(35017), UINT16_C(18214), UINT16_C( 3693), UINT16_C(37794) },
          { UINT16_C( 8510), UINT16_C( 9908), UINT16_C( 2886), UINT16_C(27439), UINT16_C( 1920), UINT16_C(  857), UINT16_C(48549), UINT16_C(20053) } },
       INT32_C(           1) },
    { { UINT16_C(30195), UINT16_C( 7358) },
        { { UINT16_C(29730), UINT16_C(24911), UINT16_C(30195), UINT16_C(48212), UINT16_C(31486), UINT16_C(27396), UINT16_C(42632), UINT16_C(51198) },
          { UINT16_C(46023), UINT16_C( 3565), UINT16_C( 7358), UINT16_C(15992), UINT16_C(53795), UINT16_C(51265), UINT16_C(38799), UINT16_C(45335) } },
       INT32_C(           2) },
    { { UINT16_C(55995), UINT16_C(24050) },
        { { UINT16_C(26123), UINT16_C(65298), UINT16_C(26332), UINT16_C(55995), UINT16_C(49121), UINT16_C(26949), UINT16_C(17254), UINT16_C(11568) },
          { UINT16_C( 7670), UINT16_C(46139), UINT16_C(45882), UINT16_C(24050), UINT16_C(13445), UINT16_C( 5158), UINT16_C(15819), UINT16_C(54982) } },
       INT32_C(           3) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8x2_t val = {
        {simde_vld1q_u16(test_vec[i].val[0]), simde_vld1q_u16(test_vec[i].val[1])}};
    uint16_t a[2];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2q_lane_u16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_u16(a[0], test_vec[i].a[0]);
    simde_assert_equal_u16(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    uint16_t a[2];
    simde_uint16x8x2_t val = simde_test_arm_neon_random_u16x8x2();
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2q_lane_u16, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vu16(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t val[2][4];
    int lane;
  } test_vec[] = {
    { { UINT32_C(1779061361), UINT32_C(4187616984) },
        { { UINT32_C(1779061361), UINT32_C( 414357895), UINT32_C(1952186155), UINT32_C(2622144343) },
          { UINT32_C(4187616984), UINT32_C(1280726411), UINT32_C(1124068470), UINT32_C( 744538555) } },
       INT32_C(           0) },
    { { UINT32_C( 800213252), UINT32_C(2713449514) },
        { { UINT32_C(2593614355), UINT32_C( 800213252), UINT32_C(2695040328), UINT32_C(2772233676) },
          { UINT32_C(1872680419), UINT32_C(2713449514), UINT32_C(2632170465), UINT32_C(2412266364) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4x2_t val = {
        {simde_vld1q_u32(test_vec[i].val[0]), simde_vld1q_u32(test_vec[i].val[1])}};
    uint32_t a[2];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2q_lane_u32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_u32(a[0], test_vec[i].a[0]);
    simde_assert_equal_u32(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    uint32_t a[2];
    simde_uint32x4x2_t val = simde_test_arm_neon_random_u32x4x2();
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2q_lane_u32, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vu32(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t val[2][2];
    int lane;
  } test_vec[] = {
    { { UINT64_C(13894521957987617184), UINT64_C(12318086457696407918) },
        { { UINT64_C(13894521957987617184), UINT64_C(14873543306438438414) },
          { UINT64_C(12318086457696407918), UINT64_C(16227925491337844608) } },
       INT32_C(           0) },
    { { UINT64_C( 1514083200894252640), UINT64_C(  542743483715233381) },
        { { UINT64_C( 4436171182632332469), UINT64_C( 1514083200894252640) },
          { UINT64_C(12786720111521992555), UINT64_C(  542743483715233381) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2x2_t val = {
        {simde_vld1q_u64(test_vec[i].val[0]), simde_vld1q_u64(test_vec[i].val[1])}};
    uint64_t a[2];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2q_lane_u64, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_u64(a[0], test_vec[i].a[0]);
    simde_assert_equal_u64(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    uint64_t a[2];
    simde_uint64x2x2_t val = simde_test_arm_neon_random_u64x2x2();
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2q_lane_u64, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vu64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t val[2][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    19.08), SIMDE_FLOAT32_C(   -83.93) },
        { { SIMDE_FLOAT32_C(    19.08), SIMDE_FLOAT32_C(    22.83), SIMDE_FLOAT32_C(   -68.21), SIMDE_FLOAT32_C(    37.78) },
          { SIMDE_FLOAT32_C(   -83.93), SIMDE_FLOAT32_C(    24.97), SIMDE_FLOAT32_C(    22.40), SIMDE_FLOAT32_C(   -46.93) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT32_C(    41.83), SIMDE_FLOAT32_C(   -27.39) },
        { { SIMDE_FLOAT32_C(    22.72), SIMDE_FLOAT32_C(    41.83), SIMDE_FLOAT32_C(    38.34), SIMDE_FLOAT32_C(   -34.59) },
          { SIMDE_FLOAT32_C(   -11.12), SIMDE_FLOAT32_C(   -27.39), SIMDE_FLOAT32_C(    65.58), SIMDE_FLOAT32_C(    49.02) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4x2_t val = {
        {simde_vld1q_f32(test_vec[i].val[0]), simde_vld1q_f32(test_vec[i].val[1])}};
    simde_float32_t a[2];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2q_lane_f32, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_f32(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f32(a[1], test_vec[i].a[1], 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32_t a[2];
    simde_float32x4x2_t val = simde_test_arm_neon_random_f32x4x2(-100.0f, 100.0f);
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2q_lane_f32, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vf32(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t val[2][2];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    53.06), SIMDE_FLOAT64_C(    71.80) },
        { { SIMDE_FLOAT64_C(    53.06), SIMDE_FLOAT64_C(   -60.06) },
          { SIMDE_FLOAT64_C(    71.80), SIMDE_FLOAT64_C(   -75.03) } },
       INT32_C(           0) },
    { { SIMDE_FLOAT64_C(    29.19), SIMDE_FLOAT64_C(    37.77) },
        { { SIMDE_FLOAT64_C(   -29.33), SIMDE_FLOAT64_C(    29.19) },
          { SIMDE_FLOAT64_C(   -15.61), SIMDE_FLOAT64_C(    37.77) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2x2_t val = {
        {simde_vld1q_f64(test_vec[i].val[0]), simde_vld1q_f64(test_vec[i].val[1])}};
    simde_float64_t a[2];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2q_lane_f64, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_f64(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f64(a[1], test_vec[i].a[1], 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64_t a[2];
    simde_float64x2x2_t val = simde_test_arm_neon_random_f64x2x2(-100.0, 100.0);
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2q_lane_f64, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vf64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_f64)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
