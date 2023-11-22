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
test_simde_vst2_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[2];
    simde_float16_t val[2][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( - 96.699),  SIMDE_FLOAT16_VALUE( 96.081) },
    { { SIMDE_FLOAT16_VALUE( - 86.059),  SIMDE_FLOAT16_VALUE( 10.093), SIMDE_FLOAT16_VALUE( - 96.699),  SIMDE_FLOAT16_VALUE( 92.682)  },
      {  SIMDE_FLOAT16_VALUE( 94.074), SIMDE_FLOAT16_VALUE( - 25.535),  SIMDE_FLOAT16_VALUE( 96.081),  SIMDE_FLOAT16_VALUE( 79.156)  } },
         INT8_C(      2) },
    { {  SIMDE_FLOAT16_VALUE( 24.214),  SIMDE_FLOAT16_VALUE( 72.416) },
    { {  SIMDE_FLOAT16_VALUE( 56.403), SIMDE_FLOAT16_VALUE( - 41.539),  SIMDE_FLOAT16_VALUE( 24.214),  SIMDE_FLOAT16_VALUE(  0.721)  },
      {  SIMDE_FLOAT16_VALUE( 11.102),  SIMDE_FLOAT16_VALUE( 82.747),  SIMDE_FLOAT16_VALUE( 72.416),  SIMDE_FLOAT16_VALUE( 25.862)  } },
         INT8_C(      2) },
    { { SIMDE_FLOAT16_VALUE( - 41.215), SIMDE_FLOAT16_VALUE( - 10.097) },
    { {  SIMDE_FLOAT16_VALUE(  8.693), SIMDE_FLOAT16_VALUE( - 45.955), SIMDE_FLOAT16_VALUE( - 41.215),  SIMDE_FLOAT16_VALUE( 47.533)  },
      {  SIMDE_FLOAT16_VALUE( 26.757), SIMDE_FLOAT16_VALUE( - 10.266), SIMDE_FLOAT16_VALUE( - 10.097), SIMDE_FLOAT16_VALUE( - 73.201)  } },
         INT8_C(      2) },
    { { SIMDE_FLOAT16_VALUE( - 14.688),  SIMDE_FLOAT16_VALUE( 26.052) },
    { { SIMDE_FLOAT16_VALUE( - 13.883),  SIMDE_FLOAT16_VALUE( 25.378),  SIMDE_FLOAT16_VALUE( 82.439), SIMDE_FLOAT16_VALUE( - 14.688)  },
      {  SIMDE_FLOAT16_VALUE( 75.364), SIMDE_FLOAT16_VALUE( - 98.234),  SIMDE_FLOAT16_VALUE( 21.632),  SIMDE_FLOAT16_VALUE( 26.052)  } },
         INT8_C(      3) },
    { { SIMDE_FLOAT16_VALUE( - 56.396), SIMDE_FLOAT16_VALUE( - 13.528) },
    { {  SIMDE_FLOAT16_VALUE( 53.363),  SIMDE_FLOAT16_VALUE( 54.407), SIMDE_FLOAT16_VALUE( - 56.396), SIMDE_FLOAT16_VALUE( - 23.778)  },
      {  SIMDE_FLOAT16_VALUE( 46.186), SIMDE_FLOAT16_VALUE( - 25.159), SIMDE_FLOAT16_VALUE( - 13.528), SIMDE_FLOAT16_VALUE( - 47.334)  } },
         INT8_C(      2) },
    { { SIMDE_FLOAT16_VALUE( - 68.946), SIMDE_FLOAT16_VALUE( - 82.937) },
    { {  SIMDE_FLOAT16_VALUE( 30.751),  SIMDE_FLOAT16_VALUE( 12.829), SIMDE_FLOAT16_VALUE( - 68.946),  SIMDE_FLOAT16_VALUE( 10.480)  },
      {  SIMDE_FLOAT16_VALUE( 58.238),  SIMDE_FLOAT16_VALUE(  3.858), SIMDE_FLOAT16_VALUE( - 82.937), SIMDE_FLOAT16_VALUE( -  2.434)  } },
         INT8_C(      2) },
    { {  SIMDE_FLOAT16_VALUE(  4.407), SIMDE_FLOAT16_VALUE( - 66.972) },
    { { SIMDE_FLOAT16_VALUE( - 94.165),  SIMDE_FLOAT16_VALUE(  4.407), SIMDE_FLOAT16_VALUE( - 78.247),  SIMDE_FLOAT16_VALUE(  4.932)  },
      {  SIMDE_FLOAT16_VALUE( 57.296), SIMDE_FLOAT16_VALUE( - 66.972), SIMDE_FLOAT16_VALUE( - 76.884), SIMDE_FLOAT16_VALUE( -  1.070)  } },
         INT8_C(      1) },
    { { SIMDE_FLOAT16_VALUE( - 49.253), SIMDE_FLOAT16_VALUE( - 68.363) },
    { { SIMDE_FLOAT16_VALUE( - 42.453),  SIMDE_FLOAT16_VALUE( 76.770), SIMDE_FLOAT16_VALUE( - 49.253),  SIMDE_FLOAT16_VALUE( 42.268)  },
      { SIMDE_FLOAT16_VALUE( - 25.787), SIMDE_FLOAT16_VALUE( - 28.102), SIMDE_FLOAT16_VALUE( - 68.363), SIMDE_FLOAT16_VALUE( - 67.189)  } },
         INT8_C(      2) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float16x4x2_t val = {
        {simde_vld1_f16(test_vec[i].val[0]), simde_vld1_f16(test_vec[i].val[1])}};
    simde_float16_t a[2];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2_lane_f16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_f16(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f16(a[1], test_vec[i].a[1], 1);
  }

  return 0;
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
test_simde_vst2q_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[2];
    simde_float16_t val[2][8];
    int lane;
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( - 90.393),  SIMDE_FLOAT16_VALUE( 63.104) },
    { { SIMDE_FLOAT16_VALUE( - 38.257), SIMDE_FLOAT16_VALUE( - 31.638), SIMDE_FLOAT16_VALUE( - 97.258), SIMDE_FLOAT16_VALUE( - 70.618),
        SIMDE_FLOAT16_VALUE( - 11.335), SIMDE_FLOAT16_VALUE( -  8.280),  SIMDE_FLOAT16_VALUE( 23.083), SIMDE_FLOAT16_VALUE( - 90.393)  },
      {  SIMDE_FLOAT16_VALUE( 74.360),  SIMDE_FLOAT16_VALUE( 51.715), SIMDE_FLOAT16_VALUE( - 79.402),  SIMDE_FLOAT16_VALUE( 71.628),
         SIMDE_FLOAT16_VALUE( 50.051), SIMDE_FLOAT16_VALUE( - 51.089), SIMDE_FLOAT16_VALUE( - 33.431),  SIMDE_FLOAT16_VALUE( 63.104)  } },
         INT8_C(      7) },
    { {  SIMDE_FLOAT16_VALUE( 64.040), SIMDE_FLOAT16_VALUE( - 67.280) },
    { {  SIMDE_FLOAT16_VALUE( 41.175),  SIMDE_FLOAT16_VALUE( 72.644),  SIMDE_FLOAT16_VALUE( 64.040), SIMDE_FLOAT16_VALUE( - 54.404),
         SIMDE_FLOAT16_VALUE( 97.772),  SIMDE_FLOAT16_VALUE( 58.590), SIMDE_FLOAT16_VALUE( - 28.472), SIMDE_FLOAT16_VALUE( - 67.625)  },
      { SIMDE_FLOAT16_VALUE( - 80.611),  SIMDE_FLOAT16_VALUE( 99.705), SIMDE_FLOAT16_VALUE( - 67.280),  SIMDE_FLOAT16_VALUE(  5.574),
        SIMDE_FLOAT16_VALUE( - 20.029), SIMDE_FLOAT16_VALUE( - 35.226), SIMDE_FLOAT16_VALUE( -  1.819), SIMDE_FLOAT16_VALUE( - 62.990)  } },
         INT8_C(      2) },
    { {  SIMDE_FLOAT16_VALUE( 23.024), SIMDE_FLOAT16_VALUE( - 77.316) },
    { {  SIMDE_FLOAT16_VALUE( 94.862), SIMDE_FLOAT16_VALUE( - 53.113),  SIMDE_FLOAT16_VALUE( 76.880), SIMDE_FLOAT16_VALUE( - 24.592),
         SIMDE_FLOAT16_VALUE( 23.024), SIMDE_FLOAT16_VALUE( - 86.319), SIMDE_FLOAT16_VALUE( - 49.922),  SIMDE_FLOAT16_VALUE( 74.371)  },
      { SIMDE_FLOAT16_VALUE( - 35.182),  SIMDE_FLOAT16_VALUE( 91.375), SIMDE_FLOAT16_VALUE( - 30.442),  SIMDE_FLOAT16_VALUE( 62.763),
        SIMDE_FLOAT16_VALUE( - 77.316), SIMDE_FLOAT16_VALUE( - 98.725),  SIMDE_FLOAT16_VALUE( 77.730), SIMDE_FLOAT16_VALUE( -  6.752)  } },
         INT8_C(      4) },
    { { SIMDE_FLOAT16_VALUE( - 89.098), SIMDE_FLOAT16_VALUE( - 47.386) },
    { { SIMDE_FLOAT16_VALUE( - 37.183), SIMDE_FLOAT16_VALUE( - 99.478), SIMDE_FLOAT16_VALUE( - 72.315),  SIMDE_FLOAT16_VALUE( 60.865),
         SIMDE_FLOAT16_VALUE( 90.711),  SIMDE_FLOAT16_VALUE( 33.609),  SIMDE_FLOAT16_VALUE( 22.229), SIMDE_FLOAT16_VALUE( - 89.098)  },
      {  SIMDE_FLOAT16_VALUE( 18.834), SIMDE_FLOAT16_VALUE( - 38.890),  SIMDE_FLOAT16_VALUE(  1.151), SIMDE_FLOAT16_VALUE( - 50.932),
         SIMDE_FLOAT16_VALUE( 16.869),  SIMDE_FLOAT16_VALUE( 72.770),  SIMDE_FLOAT16_VALUE( 43.215), SIMDE_FLOAT16_VALUE( - 47.386)  } },
         INT8_C(      7) },
    { { SIMDE_FLOAT16_VALUE( - 74.604),  SIMDE_FLOAT16_VALUE( 83.519) },
    { { SIMDE_FLOAT16_VALUE( - 87.245), SIMDE_FLOAT16_VALUE( - 66.241), SIMDE_FLOAT16_VALUE( - 49.725), SIMDE_FLOAT16_VALUE( - 74.604),
         SIMDE_FLOAT16_VALUE( 52.094), SIMDE_FLOAT16_VALUE( - 95.107),  SIMDE_FLOAT16_VALUE( 95.169),  SIMDE_FLOAT16_VALUE( 80.442)  },
      {  SIMDE_FLOAT16_VALUE(  4.494),  SIMDE_FLOAT16_VALUE( 93.210),  SIMDE_FLOAT16_VALUE( 18.867),  SIMDE_FLOAT16_VALUE( 83.519),
        SIMDE_FLOAT16_VALUE( - 54.371), SIMDE_FLOAT16_VALUE( - 96.968),  SIMDE_FLOAT16_VALUE( 31.350),  SIMDE_FLOAT16_VALUE( 84.978)  } },
         INT8_C(      3) },
    { {  SIMDE_FLOAT16_VALUE( 11.757), SIMDE_FLOAT16_VALUE( - 92.199) },
    { {  SIMDE_FLOAT16_VALUE( 11.757),  SIMDE_FLOAT16_VALUE( 28.988), SIMDE_FLOAT16_VALUE( - 67.095), SIMDE_FLOAT16_VALUE( - 58.193),
         SIMDE_FLOAT16_VALUE( 45.038), SIMDE_FLOAT16_VALUE( - 42.819), SIMDE_FLOAT16_VALUE( - 88.284),  SIMDE_FLOAT16_VALUE( 53.437)  },
      { SIMDE_FLOAT16_VALUE( - 92.199),  SIMDE_FLOAT16_VALUE( 12.165),  SIMDE_FLOAT16_VALUE(  3.097),  SIMDE_FLOAT16_VALUE( 69.414),
        SIMDE_FLOAT16_VALUE( - 22.656),  SIMDE_FLOAT16_VALUE(  5.711), SIMDE_FLOAT16_VALUE( - 39.886),  SIMDE_FLOAT16_VALUE( 37.784)  } },
         INT8_C(      0) },
    { {  SIMDE_FLOAT16_VALUE( 19.626),  SIMDE_FLOAT16_VALUE( 24.723) },
    { { SIMDE_FLOAT16_VALUE( -  4.744),  SIMDE_FLOAT16_VALUE( 15.391),  SIMDE_FLOAT16_VALUE( 19.626),  SIMDE_FLOAT16_VALUE( 64.213),
         SIMDE_FLOAT16_VALUE( 92.541),  SIMDE_FLOAT16_VALUE( 24.957),  SIMDE_FLOAT16_VALUE( 42.707), SIMDE_FLOAT16_VALUE( - 42.789)  },
      { SIMDE_FLOAT16_VALUE( - 35.790),  SIMDE_FLOAT16_VALUE( 98.414),  SIMDE_FLOAT16_VALUE( 24.723), SIMDE_FLOAT16_VALUE( -  2.908),
         SIMDE_FLOAT16_VALUE(  8.083), SIMDE_FLOAT16_VALUE( - 46.904), SIMDE_FLOAT16_VALUE( - 37.831), SIMDE_FLOAT16_VALUE( - 59.362)  } },
         INT8_C(      2) },
    { {  SIMDE_FLOAT16_VALUE( 64.222), SIMDE_FLOAT16_VALUE( - 33.836) },
    { { SIMDE_FLOAT16_VALUE( - 31.643), SIMDE_FLOAT16_VALUE( - 36.586),  SIMDE_FLOAT16_VALUE( 64.222), SIMDE_FLOAT16_VALUE( - 73.531),
        SIMDE_FLOAT16_VALUE( - 64.852),  SIMDE_FLOAT16_VALUE( 22.974), SIMDE_FLOAT16_VALUE( - 27.821), SIMDE_FLOAT16_VALUE( - 62.560)  },
      { SIMDE_FLOAT16_VALUE( - 78.721),  SIMDE_FLOAT16_VALUE( 35.577), SIMDE_FLOAT16_VALUE( - 33.836),  SIMDE_FLOAT16_VALUE( 54.532),
        SIMDE_FLOAT16_VALUE( - 39.138), SIMDE_FLOAT16_VALUE( - 98.477), SIMDE_FLOAT16_VALUE( - 49.646), SIMDE_FLOAT16_VALUE( - 72.783)  } },
         INT8_C(      2) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float16x8x2_t val = {
        {simde_vld1q_f16(test_vec[i].val[0]), simde_vld1q_f16(test_vec[i].val[1])}};
    simde_float16_t a[2];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2q_lane_f16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_f16(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_f16(a[1], test_vec[i].a[1], 1);
  }

  return 0;
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

static int
test_simde_vst2_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[2];
    simde_poly8_t val[2][8];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY8_C( 86), SIMDE_POLY8_C(248) },
        { { SIMDE_POLY8_C( 86), SIMDE_POLY8_C(213), SIMDE_POLY8_C(226), SIMDE_POLY8_C( 35), SIMDE_POLY8_C(160), SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(143) },
          { SIMDE_POLY8_C(248), SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(206), SIMDE_POLY8_C(106), SIMDE_POLY8_C(162), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(239) } },
       INT32_C(           0) },
    { { SIMDE_POLY8_C(212), SIMDE_POLY8_C( 97) },
        { { SIMDE_POLY8_C( 47), SIMDE_POLY8_C(212), SIMDE_POLY8_C(160), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(236), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(159), SIMDE_POLY8_C(251) },
          { SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 97), SIMDE_POLY8_C( 95), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(222), SIMDE_POLY8_C(120), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 52) } },
       INT32_C(           1) },
    { { SIMDE_POLY8_C( 87), SIMDE_POLY8_C(114) },
        { { SIMDE_POLY8_C( 77), SIMDE_POLY8_C(100), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(237), SIMDE_POLY8_C(172), SIMDE_POLY8_C(125), SIMDE_POLY8_C(124), SIMDE_POLY8_C(164) },
          { SIMDE_POLY8_C(158), SIMDE_POLY8_C(183), SIMDE_POLY8_C(114), SIMDE_POLY8_C(  8), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(203), SIMDE_POLY8_C(247), SIMDE_POLY8_C(137) } },
       INT32_C(           2) },
    { { SIMDE_POLY8_C(140), SIMDE_POLY8_C(110) },
        { { SIMDE_POLY8_C(160), SIMDE_POLY8_C(151), SIMDE_POLY8_C(144), SIMDE_POLY8_C(140), SIMDE_POLY8_C(170), SIMDE_POLY8_C( 47), SIMDE_POLY8_C(136), SIMDE_POLY8_C(236) },
          { SIMDE_POLY8_C(144), SIMDE_POLY8_C(231), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(209), SIMDE_POLY8_C(162), SIMDE_POLY8_C(172) } },
       INT32_C(           3) },
    { { SIMDE_POLY8_C(119), SIMDE_POLY8_C(195) },
        { { SIMDE_POLY8_C( 53), SIMDE_POLY8_C(250), SIMDE_POLY8_C(153), SIMDE_POLY8_C(225), SIMDE_POLY8_C(119), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(133), SIMDE_POLY8_C( 21) },
          { SIMDE_POLY8_C(205), SIMDE_POLY8_C(247), SIMDE_POLY8_C( 29), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(195), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(177), SIMDE_POLY8_C( 99) } },
       INT32_C(           4) },
    { { SIMDE_POLY8_C(119), SIMDE_POLY8_C( 17) },
        { { SIMDE_POLY8_C(172), SIMDE_POLY8_C( 65), SIMDE_POLY8_C(239), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(112), SIMDE_POLY8_C(119), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(  0) },
          { SIMDE_POLY8_C( 94), SIMDE_POLY8_C(145), SIMDE_POLY8_C(111), SIMDE_POLY8_C(189), SIMDE_POLY8_C( 98), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(105), SIMDE_POLY8_C(152) } },
       INT32_C(           5) },
    { { SIMDE_POLY8_C(151), SIMDE_POLY8_C( 28) },
        { { SIMDE_POLY8_C( 11), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(121), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 25),    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C(151), SIMDE_POLY8_C(230) },
          { SIMDE_POLY8_C(246), SIMDE_POLY8_C(181), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(185), SIMDE_POLY8_C(202), SIMDE_POLY8_C(191), SIMDE_POLY8_C( 28), SIMDE_POLY8_C(118) } },
       INT32_C(           6) },
    { { SIMDE_POLY8_C(226), SIMDE_POLY8_C(252) },
        { { SIMDE_POLY8_C(  0), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(205), SIMDE_POLY8_C(112), SIMDE_POLY8_C(131), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(112), SIMDE_POLY8_C(226) },
          { SIMDE_POLY8_C(161), SIMDE_POLY8_C(223), SIMDE_POLY8_C(159), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(241), SIMDE_POLY8_C(  9), SIMDE_POLY8_C(156), SIMDE_POLY8_C(252) } },
       INT32_C(           7) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly8x8x2_t val = {
        {simde_vld1_p8(test_vec[i].val[0]), simde_vld1_p8(test_vec[i].val[1])}};
    simde_poly8_t a[2];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2_lane_p8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_p8(a[0], test_vec[i].a[0]);
    simde_assert_equal_p8(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8_t a[2];
    simde_poly8x8x2_t val = simde_test_arm_neon_random_p8x8x2();
    const int lane = lanes[i];
    simde_vst2_lane_p8(a, val, lane);

    simde_test_codegen_write_vp8(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_p32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[2];
    simde_poly16_t val[2][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY16_C(62176), SIMDE_POLY16_C(46222) },
        { { SIMDE_POLY16_C(62176), SIMDE_POLY16_C(53589), SIMDE_POLY16_C(49850), SIMDE_POLY16_C(10054) },
          { SIMDE_POLY16_C(46222), SIMDE_POLY16_C(51489), SIMDE_POLY16_C( 9024), SIMDE_POLY16_C(42418) } },
       INT32_C(           0) },
    { { SIMDE_POLY16_C(23344), SIMDE_POLY16_C(57272) },
        { { SIMDE_POLY16_C(45667), SIMDE_POLY16_C(23344), SIMDE_POLY16_C(28231), SIMDE_POLY16_C(44285) },
          { SIMDE_POLY16_C( 4067), SIMDE_POLY16_C(57272), SIMDE_POLY16_C(29494), SIMDE_POLY16_C( 5829) } },
       INT32_C(           1) },
    { { SIMDE_POLY16_C(11997), SIMDE_POLY16_C(59276) },
        { { SIMDE_POLY16_C( 6758), SIMDE_POLY16_C( 8423), SIMDE_POLY16_C(11997), SIMDE_POLY16_C(27463) },
          { SIMDE_POLY16_C(26850), SIMDE_POLY16_C( 8757), SIMDE_POLY16_C(59276), SIMDE_POLY16_C(61383) } },
       INT32_C(           2) },
    { { SIMDE_POLY16_C(18828), SIMDE_POLY16_C( 7843) },
        { { SIMDE_POLY16_C(63385), SIMDE_POLY16_C(57419), SIMDE_POLY16_C(18533), SIMDE_POLY16_C(18828) },
          { SIMDE_POLY16_C(17495), SIMDE_POLY16_C(36136), SIMDE_POLY16_C(60856), SIMDE_POLY16_C( 7843) } },
       INT32_C(           3) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly16x4x2_t val = {
        {simde_vld1_p16(test_vec[i].val[0]), simde_vld1_p16(test_vec[i].val[1])}};
    simde_poly16_t a[2];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2_lane_p16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_p16(a[0], test_vec[i].a[0]);
    simde_assert_equal_p16(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16_t a[2];
    simde_poly16x4x2_t val = simde_test_arm_neon_random_p16x4x2();
    const int lane = lanes[i];
    simde_vst2_lane_p16(a, val, lane);

    simde_test_codegen_write_vp16(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[2];
    simde_poly64_t val[2][1];
  } test_vec[] = {
    { { SIMDE_POLY64_C( 4671586217597814761), SIMDE_POLY64_C( 9221507607604285949) },
        { { SIMDE_POLY64_C( 4671586217597814761) },
          { SIMDE_POLY64_C( 9221507607604285949) } },
    },
    { { SIMDE_POLY64_C(16667829075929106599), SIMDE_POLY64_C(  647665260169911972) },
        { { SIMDE_POLY64_C(16667829075929106599) },
          { SIMDE_POLY64_C(  647665260169911972) } },
    }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly64x1x2_t val = {
        {simde_vld1_p64(test_vec[i].val[0]), simde_vld1_p64(test_vec[i].val[1])}};
    simde_poly64_t a[2];
    simde_vst2_lane_p64(a, val, 0);
    simde_assert_equal_p64(a[0], test_vec[i].a[0]);
    simde_assert_equal_p64(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64_t a[2];
    simde_poly64x1x2_t val = simde_test_arm_neon_random_p64x1x2();
    simde_vst2_lane_p64(a, val, 0);

    simde_test_codegen_write_vp64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x4x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[2];
    simde_poly8_t val[2][16];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 25) },
       { { SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 85),    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C(102), SIMDE_POLY8_C(183), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(244), SIMDE_POLY8_C(119),
           SIMDE_POLY8_C( 82), SIMDE_POLY8_C(121), SIMDE_POLY8_C(170), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(205), SIMDE_POLY8_C( 17), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 56) },
         { SIMDE_POLY8_C( 25), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(246), SIMDE_POLY8_C(245), SIMDE_POLY8_C(205), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(128), SIMDE_POLY8_C(197),
           SIMDE_POLY8_C( 51), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(166), SIMDE_POLY8_C(238), SIMDE_POLY8_C(218), SIMDE_POLY8_C(175), SIMDE_POLY8_C( 52), SIMDE_POLY8_C( 33) } },
      INT32_C(           0) },
   { { SIMDE_POLY8_C( 51), SIMDE_POLY8_C(240) },
       { { SIMDE_POLY8_C(  4), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(135), SIMDE_POLY8_C(187), SIMDE_POLY8_C(141), SIMDE_POLY8_C(123), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(224),
           SIMDE_POLY8_C(244), SIMDE_POLY8_C(221), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(194), SIMDE_POLY8_C(238), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(250), SIMDE_POLY8_C(  7) },
         { SIMDE_POLY8_C( 67), SIMDE_POLY8_C(240), SIMDE_POLY8_C(252), SIMDE_POLY8_C( 16), SIMDE_POLY8_C( 28), SIMDE_POLY8_C(124), SIMDE_POLY8_C(214), SIMDE_POLY8_C( 80),
           SIMDE_POLY8_C(164), SIMDE_POLY8_C(124), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(126), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(114), SIMDE_POLY8_C(159), SIMDE_POLY8_C( 48) } },
      INT32_C(           1) },
   { { SIMDE_POLY8_C(236), SIMDE_POLY8_C(181) },
       { { SIMDE_POLY8_C(165), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(236), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(162), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(150),
           SIMDE_POLY8_C(252), SIMDE_POLY8_C( 44), SIMDE_POLY8_C( 88), SIMDE_POLY8_C(234), SIMDE_POLY8_C( 97), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(242), SIMDE_POLY8_C(165) },
         { SIMDE_POLY8_C( 67), SIMDE_POLY8_C(238), SIMDE_POLY8_C(181), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(107), SIMDE_POLY8_C(139), SIMDE_POLY8_C(176), SIMDE_POLY8_C( 15),
           SIMDE_POLY8_C(  8), SIMDE_POLY8_C(238), SIMDE_POLY8_C(141), SIMDE_POLY8_C( 52), SIMDE_POLY8_C( 97), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(100), SIMDE_POLY8_C(  6) } },
      INT32_C(           2) },
   { { SIMDE_POLY8_C(244), SIMDE_POLY8_C(161) },
       { { SIMDE_POLY8_C( 82), SIMDE_POLY8_C( 80), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(244), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(139), SIMDE_POLY8_C(107),
           SIMDE_POLY8_C(120), SIMDE_POLY8_C(227), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(127), SIMDE_POLY8_C(122) },
         { SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(218), SIMDE_POLY8_C(161), SIMDE_POLY8_C(192), SIMDE_POLY8_C(138), SIMDE_POLY8_C(176), SIMDE_POLY8_C(200),
           SIMDE_POLY8_C(120), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(252), SIMDE_POLY8_C(217), SIMDE_POLY8_C(105), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(224), SIMDE_POLY8_C(188) } },
      INT32_C(           3) },
   { { SIMDE_POLY8_C(102), SIMDE_POLY8_C( 51) },
       { { SIMDE_POLY8_C(177), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(176), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(102), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(140), SIMDE_POLY8_C(222),
           SIMDE_POLY8_C( 31), SIMDE_POLY8_C(226), SIMDE_POLY8_C(184), SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 42), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(207), SIMDE_POLY8_C( 96) },
         { SIMDE_POLY8_C(108), SIMDE_POLY8_C(169), SIMDE_POLY8_C(  2), SIMDE_POLY8_C( 44), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(178), SIMDE_POLY8_C(244), SIMDE_POLY8_C(172),
           SIMDE_POLY8_C(240), SIMDE_POLY8_C(240), SIMDE_POLY8_C(133), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(101), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(  1) } },
      INT32_C(           4) },
   { { SIMDE_POLY8_C(174), SIMDE_POLY8_C( 63) },
       { { SIMDE_POLY8_C(127), SIMDE_POLY8_C(198), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(229), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(174), SIMDE_POLY8_C(195), SIMDE_POLY8_C( 32),
           SIMDE_POLY8_C(144), SIMDE_POLY8_C(124), SIMDE_POLY8_C(118), SIMDE_POLY8_C(186), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 69), SIMDE_POLY8_C( 26), SIMDE_POLY8_C( 31) },
         { SIMDE_POLY8_C(239), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(207), SIMDE_POLY8_C( 63), SIMDE_POLY8_C(206), SIMDE_POLY8_C(191),
           SIMDE_POLY8_C( 47), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(128), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 56) } },
      INT32_C(           5) },
   { { SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 96) },
       { { SIMDE_POLY8_C(244), SIMDE_POLY8_C(163), SIMDE_POLY8_C( 29), SIMDE_POLY8_C(245), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(225), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(225),
           SIMDE_POLY8_C( 93), SIMDE_POLY8_C(140), SIMDE_POLY8_C(155), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(209), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 48), SIMDE_POLY8_C(192) },
         { SIMDE_POLY8_C(210), SIMDE_POLY8_C(123), SIMDE_POLY8_C(227), SIMDE_POLY8_C(161), SIMDE_POLY8_C(187), SIMDE_POLY8_C(177), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(234),
           SIMDE_POLY8_C(  5), SIMDE_POLY8_C(121), SIMDE_POLY8_C(106), SIMDE_POLY8_C(191), SIMDE_POLY8_C(167), SIMDE_POLY8_C(236), SIMDE_POLY8_C(247), SIMDE_POLY8_C(155) } },
      INT32_C(           6) },
   { { SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 94) },
       { { SIMDE_POLY8_C(143), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(144), SIMDE_POLY8_C(225), SIMDE_POLY8_C(246), SIMDE_POLY8_C(166), SIMDE_POLY8_C(194), SIMDE_POLY8_C( 83),
           SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 94), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(  4), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(147), SIMDE_POLY8_C(196), SIMDE_POLY8_C(230) },
         { SIMDE_POLY8_C( 15), SIMDE_POLY8_C(167), SIMDE_POLY8_C(136), SIMDE_POLY8_C(202), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(232), SIMDE_POLY8_C(180), SIMDE_POLY8_C( 94),
           SIMDE_POLY8_C( 97), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 29), SIMDE_POLY8_C(  8), SIMDE_POLY8_C( 11), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(163), SIMDE_POLY8_C(154) } },
      INT32_C(           7) },
   { { SIMDE_POLY8_C(156), SIMDE_POLY8_C( 22) },
       { { SIMDE_POLY8_C( 42), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(123), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 13),
           SIMDE_POLY8_C(156), SIMDE_POLY8_C(214), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(176), SIMDE_POLY8_C(106), SIMDE_POLY8_C(213), SIMDE_POLY8_C(150), SIMDE_POLY8_C(121) },
         { SIMDE_POLY8_C(125), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(214), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(247), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(104),
           SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(103), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(188), SIMDE_POLY8_C(145) } },
      INT32_C(           8) },
   { { SIMDE_POLY8_C( 65), SIMDE_POLY8_C( 87) },
       { { SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(177), SIMDE_POLY8_C( 35), SIMDE_POLY8_C(117), SIMDE_POLY8_C( 36), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 17),
           SIMDE_POLY8_C(250), SIMDE_POLY8_C( 65), SIMDE_POLY8_C(193), SIMDE_POLY8_C(100), SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 88), SIMDE_POLY8_C(221), SIMDE_POLY8_C(147) },
         { SIMDE_POLY8_C(118), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(105), SIMDE_POLY8_C(125), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(158), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 46),
           SIMDE_POLY8_C(240), SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 80), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(232), SIMDE_POLY8_C(180) } },
      INT32_C(           9) },
   { { SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 64) },
       { { SIMDE_POLY8_C( 67), SIMDE_POLY8_C(153), SIMDE_POLY8_C(215), SIMDE_POLY8_C(185), SIMDE_POLY8_C(189), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(202), SIMDE_POLY8_C(183),
           SIMDE_POLY8_C( 72), SIMDE_POLY8_C(140), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(228), SIMDE_POLY8_C(249), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 90) },
         { SIMDE_POLY8_C( 26), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(216), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(249), SIMDE_POLY8_C(190), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(233),
           SIMDE_POLY8_C( 21), SIMDE_POLY8_C(176), SIMDE_POLY8_C( 64), SIMDE_POLY8_C(128), SIMDE_POLY8_C(188), SIMDE_POLY8_C( 40), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(  0) } },
      INT32_C(          10) },
   { { SIMDE_POLY8_C(243), SIMDE_POLY8_C(101) },
       { { SIMDE_POLY8_C(193), SIMDE_POLY8_C( 11), SIMDE_POLY8_C(185), SIMDE_POLY8_C(126), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(131), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 90),
           SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(185), SIMDE_POLY8_C(243), SIMDE_POLY8_C( 75), SIMDE_POLY8_C(171), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(101) },
         { SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(151), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(228), SIMDE_POLY8_C(248), SIMDE_POLY8_C(233), SIMDE_POLY8_C(249),
           SIMDE_POLY8_C(168), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(121), SIMDE_POLY8_C(101), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(174), SIMDE_POLY8_C(101), SIMDE_POLY8_C( 20) } },
      INT32_C(          11) },
   { { SIMDE_POLY8_C(138), SIMDE_POLY8_C( 29) },
       { { SIMDE_POLY8_C(185), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(146), SIMDE_POLY8_C(204), SIMDE_POLY8_C(161), SIMDE_POLY8_C(200), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(177),
           SIMDE_POLY8_C( 26), SIMDE_POLY8_C(223), SIMDE_POLY8_C(164), SIMDE_POLY8_C(102), SIMDE_POLY8_C(138), SIMDE_POLY8_C(242), SIMDE_POLY8_C(203), SIMDE_POLY8_C(145) },
         { SIMDE_POLY8_C( 24), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(145), SIMDE_POLY8_C(252), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(122), SIMDE_POLY8_C(245), SIMDE_POLY8_C(  3),
           SIMDE_POLY8_C(164), SIMDE_POLY8_C(111), SIMDE_POLY8_C(104), SIMDE_POLY8_C(247), SIMDE_POLY8_C( 29), SIMDE_POLY8_C(205), SIMDE_POLY8_C( 11), SIMDE_POLY8_C(214) } },
      INT32_C(          12) },
   { { SIMDE_POLY8_C(178), SIMDE_POLY8_C(118) },
       { { SIMDE_POLY8_C(235), SIMDE_POLY8_C(157), SIMDE_POLY8_C(162), SIMDE_POLY8_C(141), SIMDE_POLY8_C(102), SIMDE_POLY8_C(201), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(128),
           SIMDE_POLY8_C(168), SIMDE_POLY8_C(226), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(213), SIMDE_POLY8_C(178), SIMDE_POLY8_C(196), SIMDE_POLY8_C(237) },
         { SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(234), SIMDE_POLY8_C(112), SIMDE_POLY8_C(207), SIMDE_POLY8_C(223), SIMDE_POLY8_C(115), SIMDE_POLY8_C(116),
           SIMDE_POLY8_C( 78), SIMDE_POLY8_C(220), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(169), SIMDE_POLY8_C(118), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(149) } },
      INT32_C(          13) },
   { { SIMDE_POLY8_C(  5), SIMDE_POLY8_C(165) },
       { { SIMDE_POLY8_C( 19), SIMDE_POLY8_C(228), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(121), SIMDE_POLY8_C(173), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 86),
           SIMDE_POLY8_C( 66), SIMDE_POLY8_C(224), SIMDE_POLY8_C(137), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(146), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(167) },
         { SIMDE_POLY8_C(162), SIMDE_POLY8_C(239), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(113), SIMDE_POLY8_C(206), SIMDE_POLY8_C(139), SIMDE_POLY8_C(229), SIMDE_POLY8_C( 29),
           SIMDE_POLY8_C(103), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(198), SIMDE_POLY8_C(202), SIMDE_POLY8_C(165), SIMDE_POLY8_C(218) } },
      INT32_C(          14) },
   { { SIMDE_POLY8_C( 42), SIMDE_POLY8_C( 99) },
       { { SIMDE_POLY8_C(175), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 39), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(178), SIMDE_POLY8_C(106),
           SIMDE_POLY8_C( 46), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(129), SIMDE_POLY8_C(192), SIMDE_POLY8_C(136), SIMDE_POLY8_C(134), SIMDE_POLY8_C(104), SIMDE_POLY8_C( 42) },
         { SIMDE_POLY8_C(117), SIMDE_POLY8_C(127), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 68), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 97), SIMDE_POLY8_C(113),
           SIMDE_POLY8_C(210), SIMDE_POLY8_C(233), SIMDE_POLY8_C(130), SIMDE_POLY8_C(152), SIMDE_POLY8_C(180), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(114), SIMDE_POLY8_C( 99) } },
      INT32_C(          15) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly8x16x2_t val = {
        {simde_vld1q_p8(test_vec[i].val[0]), simde_vld1q_p8(test_vec[i].val[1])}};
    simde_poly8_t a[2];
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst2q_lane_p8, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_p8(a[0], test_vec[i].a[0]);
    simde_assert_equal_p8(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_poly8_t a[2];
    simde_poly8x16x2_t val = simde_test_arm_neon_random_p8x16x2();
    SIMDE_CONSTIFY_16_NO_RESULT_(simde_vst2q_lane_p8, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vp8(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[2];
    simde_poly16_t val[2][8];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY16_C( 3022), SIMDE_POLY16_C(12326) },
        { { SIMDE_POLY16_C( 3022), SIMDE_POLY16_C(52482), SIMDE_POLY16_C(55639), SIMDE_POLY16_C( 9568), SIMDE_POLY16_C(19124), SIMDE_POLY16_C(13154), SIMDE_POLY16_C(58494), SIMDE_POLY16_C(23527) },
          { SIMDE_POLY16_C(12326), SIMDE_POLY16_C( 8574), SIMDE_POLY16_C( 9703), SIMDE_POLY16_C( 2390), SIMDE_POLY16_C(29989), SIMDE_POLY16_C(61143), SIMDE_POLY16_C(40579), SIMDE_POLY16_C(21091) } },
       INT32_C(           0) },
    { { SIMDE_POLY16_C(  287), SIMDE_POLY16_C( 9908) },
        { { SIMDE_POLY16_C(26025), SIMDE_POLY16_C(  287), SIMDE_POLY16_C(32574), SIMDE_POLY16_C(62246), SIMDE_POLY16_C(35017), SIMDE_POLY16_C(18214), SIMDE_POLY16_C( 3693), SIMDE_POLY16_C(37794) },
          { SIMDE_POLY16_C( 8510), SIMDE_POLY16_C( 9908), SIMDE_POLY16_C( 2886), SIMDE_POLY16_C(27439), SIMDE_POLY16_C( 1920), SIMDE_POLY16_C(  857), SIMDE_POLY16_C(48549), SIMDE_POLY16_C(20053) } },
       INT32_C(           1) },
    { { SIMDE_POLY16_C(30195), SIMDE_POLY16_C( 7358) },
        { { SIMDE_POLY16_C(29730), SIMDE_POLY16_C(24911), SIMDE_POLY16_C(30195), SIMDE_POLY16_C(48212), SIMDE_POLY16_C(31486), SIMDE_POLY16_C(27396), SIMDE_POLY16_C(42632), SIMDE_POLY16_C(51198) },
          { SIMDE_POLY16_C(46023), SIMDE_POLY16_C( 3565), SIMDE_POLY16_C( 7358), SIMDE_POLY16_C(15992), SIMDE_POLY16_C(53795), SIMDE_POLY16_C(51265), SIMDE_POLY16_C(38799), SIMDE_POLY16_C(45335) } },
       INT32_C(           2) },
    { { SIMDE_POLY16_C(55995), SIMDE_POLY16_C(24050) },
        { { SIMDE_POLY16_C(26123), SIMDE_POLY16_C(65298), SIMDE_POLY16_C(26332), SIMDE_POLY16_C(55995), SIMDE_POLY16_C(49121), SIMDE_POLY16_C(26949), SIMDE_POLY16_C(17254), SIMDE_POLY16_C(11568) },
          { SIMDE_POLY16_C( 7670), SIMDE_POLY16_C(46139), SIMDE_POLY16_C(45882), SIMDE_POLY16_C(24050), SIMDE_POLY16_C(13445), SIMDE_POLY16_C( 5158), SIMDE_POLY16_C(15819), SIMDE_POLY16_C(54982) } },
       INT32_C(           3) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly16x8x2_t val = {
        {simde_vld1q_p16(test_vec[i].val[0]), simde_vld1q_p16(test_vec[i].val[1])}};
    simde_poly16_t a[2];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2q_lane_p16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_p16(a[0], test_vec[i].a[0]);
    simde_assert_equal_p16(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16_t a[2];
    simde_poly16x8x2_t val = simde_test_arm_neon_random_p16x8x2();
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2q_lane_p16, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vp16(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[2];
    simde_poly64_t val[2][2];
    int lane;
  } test_vec[] = {
    { { SIMDE_POLY64_C(13894521957987617184), SIMDE_POLY64_C(12318086457696407918) },
        { { SIMDE_POLY64_C(13894521957987617184), SIMDE_POLY64_C(14873543306438438414) },
          { SIMDE_POLY64_C(12318086457696407918), SIMDE_POLY64_C(16227925491337844608) } },
       INT32_C(           0) },
    { { SIMDE_POLY64_C( 1514083200894252640), SIMDE_POLY64_C(  542743483715233381) },
        { { SIMDE_POLY64_C( 4436171182632332469), SIMDE_POLY64_C( 1514083200894252640) },
          { SIMDE_POLY64_C(12786720111521992555), SIMDE_POLY64_C(  542743483715233381) } },
       INT32_C(           1) }
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly64x2x2_t val = {
        {simde_vld1q_p64(test_vec[i].val[0]), simde_vld1q_p64(test_vec[i].val[1])}};
    simde_poly64_t a[2];
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2q_lane_p64, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_p64(a[0], test_vec[i].a[0]);
    simde_assert_equal_p64(a[1], test_vec[i].a[1]);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 2 ; i++) {
    simde_poly64_t a[2];
    simde_poly64x2x2_t val = simde_test_arm_neon_random_p64x2x2();
    SIMDE_CONSTIFY_2_NO_RESULT_(simde_vst2q_lane_p64, HEDLEY_UNREACHABLE(),
                                i, a, val);

    simde_test_codegen_write_vp64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2x2(2, val, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[2];
    simde_bfloat16_t val[2][4];
    int lane;
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE( - 96.699),  SIMDE_BFLOAT16_VALUE( 96.081) },
    { { SIMDE_BFLOAT16_VALUE( - 86.059),  SIMDE_BFLOAT16_VALUE( 10.093), SIMDE_BFLOAT16_VALUE( - 96.699),  SIMDE_BFLOAT16_VALUE( 92.682)  },
      {  SIMDE_BFLOAT16_VALUE( 94.074), SIMDE_BFLOAT16_VALUE( - 25.535),  SIMDE_BFLOAT16_VALUE( 96.081),  SIMDE_BFLOAT16_VALUE( 79.156)  } },
         INT8_C(      2) },
    { {  SIMDE_BFLOAT16_VALUE( 24.214),  SIMDE_BFLOAT16_VALUE( 72.416) },
    { {  SIMDE_BFLOAT16_VALUE( 56.403), SIMDE_BFLOAT16_VALUE( - 41.539),  SIMDE_BFLOAT16_VALUE( 24.214),  SIMDE_BFLOAT16_VALUE(  0.721)  },
      {  SIMDE_BFLOAT16_VALUE( 11.102),  SIMDE_BFLOAT16_VALUE( 82.747),  SIMDE_BFLOAT16_VALUE( 72.416),  SIMDE_BFLOAT16_VALUE( 25.862)  } },
         INT8_C(      2) },
    { { SIMDE_BFLOAT16_VALUE( - 41.215), SIMDE_BFLOAT16_VALUE( - 10.097) },
    { {  SIMDE_BFLOAT16_VALUE(  8.693), SIMDE_BFLOAT16_VALUE( - 45.955), SIMDE_BFLOAT16_VALUE( - 41.215),  SIMDE_BFLOAT16_VALUE( 47.533)  },
      {  SIMDE_BFLOAT16_VALUE( 26.757), SIMDE_BFLOAT16_VALUE( - 10.266), SIMDE_BFLOAT16_VALUE( - 10.097), SIMDE_BFLOAT16_VALUE( - 73.201)  } },
         INT8_C(      2) },
    { { SIMDE_BFLOAT16_VALUE( - 14.688),  SIMDE_BFLOAT16_VALUE( 26.052) },
    { { SIMDE_BFLOAT16_VALUE( - 13.883),  SIMDE_BFLOAT16_VALUE( 25.378),  SIMDE_BFLOAT16_VALUE( 82.439), SIMDE_BFLOAT16_VALUE( - 14.688)  },
      {  SIMDE_BFLOAT16_VALUE( 75.364), SIMDE_BFLOAT16_VALUE( - 98.234),  SIMDE_BFLOAT16_VALUE( 21.632),  SIMDE_BFLOAT16_VALUE( 26.052)  } },
         INT8_C(      3) },
    { { SIMDE_BFLOAT16_VALUE( - 56.396), SIMDE_BFLOAT16_VALUE( - 13.528) },
    { {  SIMDE_BFLOAT16_VALUE( 53.363),  SIMDE_BFLOAT16_VALUE( 54.407), SIMDE_BFLOAT16_VALUE( - 56.396), SIMDE_BFLOAT16_VALUE( - 23.778)  },
      {  SIMDE_BFLOAT16_VALUE( 46.186), SIMDE_BFLOAT16_VALUE( - 25.159), SIMDE_BFLOAT16_VALUE( - 13.528), SIMDE_BFLOAT16_VALUE( - 47.334)  } },
         INT8_C(      2) },
    { { SIMDE_BFLOAT16_VALUE( - 68.946), SIMDE_BFLOAT16_VALUE( - 82.937) },
    { {  SIMDE_BFLOAT16_VALUE( 30.751),  SIMDE_BFLOAT16_VALUE( 12.829), SIMDE_BFLOAT16_VALUE( - 68.946),  SIMDE_BFLOAT16_VALUE( 10.480)  },
      {  SIMDE_BFLOAT16_VALUE( 58.238),  SIMDE_BFLOAT16_VALUE(  3.858), SIMDE_BFLOAT16_VALUE( - 82.937), SIMDE_BFLOAT16_VALUE( -  2.434)  } },
         INT8_C(      2) },
    { {  SIMDE_BFLOAT16_VALUE(  4.407), SIMDE_BFLOAT16_VALUE( - 66.972) },
    { { SIMDE_BFLOAT16_VALUE( - 94.165),  SIMDE_BFLOAT16_VALUE(  4.407), SIMDE_BFLOAT16_VALUE( - 78.247),  SIMDE_BFLOAT16_VALUE(  4.932)  },
      {  SIMDE_BFLOAT16_VALUE( 57.296), SIMDE_BFLOAT16_VALUE( - 66.972), SIMDE_BFLOAT16_VALUE( - 76.884), SIMDE_BFLOAT16_VALUE( -  1.070)  } },
         INT8_C(      1) },
    { { SIMDE_BFLOAT16_VALUE( - 49.253), SIMDE_BFLOAT16_VALUE( - 68.363) },
    { { SIMDE_BFLOAT16_VALUE( - 42.453),  SIMDE_BFLOAT16_VALUE( 76.770), SIMDE_BFLOAT16_VALUE( - 49.253),  SIMDE_BFLOAT16_VALUE( 42.268)  },
      { SIMDE_BFLOAT16_VALUE( - 25.787), SIMDE_BFLOAT16_VALUE( - 28.102), SIMDE_BFLOAT16_VALUE( - 68.363), SIMDE_BFLOAT16_VALUE( - 67.189)  } },
         INT8_C(      2) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_bfloat16x4x2_t val = {
        {simde_vld1_bf16(test_vec[i].val[0]), simde_vld1_bf16(test_vec[i].val[1])}};
    simde_bfloat16_t a[2];
    SIMDE_CONSTIFY_4_NO_RESULT_(simde_vst2_lane_bf16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_bf16(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_bf16(a[1], test_vec[i].a[1], 1);
  }

  return 0;
}

static int
test_simde_vst2q_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[2];
    simde_bfloat16_t val[2][8];
    int lane;
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE( - 90.393),  SIMDE_BFLOAT16_VALUE( 63.104) },
    { { SIMDE_BFLOAT16_VALUE( - 38.257), SIMDE_BFLOAT16_VALUE( - 31.638), SIMDE_BFLOAT16_VALUE( - 97.258), SIMDE_BFLOAT16_VALUE( - 70.618),
        SIMDE_BFLOAT16_VALUE( - 11.335), SIMDE_BFLOAT16_VALUE( -  8.280),  SIMDE_BFLOAT16_VALUE( 23.083), SIMDE_BFLOAT16_VALUE( - 90.393)  },
      {  SIMDE_BFLOAT16_VALUE( 74.360),  SIMDE_BFLOAT16_VALUE( 51.715), SIMDE_BFLOAT16_VALUE( - 79.402),  SIMDE_BFLOAT16_VALUE( 71.628),
         SIMDE_BFLOAT16_VALUE( 50.051), SIMDE_BFLOAT16_VALUE( - 51.089), SIMDE_BFLOAT16_VALUE( - 33.431),  SIMDE_BFLOAT16_VALUE( 63.104)  } },
         INT8_C(      7) },
    { {  SIMDE_BFLOAT16_VALUE( 64.040), SIMDE_BFLOAT16_VALUE( - 67.280) },
    { {  SIMDE_BFLOAT16_VALUE( 41.175),  SIMDE_BFLOAT16_VALUE( 72.644),  SIMDE_BFLOAT16_VALUE( 64.040), SIMDE_BFLOAT16_VALUE( - 54.404),
         SIMDE_BFLOAT16_VALUE( 97.772),  SIMDE_BFLOAT16_VALUE( 58.590), SIMDE_BFLOAT16_VALUE( - 28.472), SIMDE_BFLOAT16_VALUE( - 67.625)  },
      { SIMDE_BFLOAT16_VALUE( - 80.611),  SIMDE_BFLOAT16_VALUE( 99.705), SIMDE_BFLOAT16_VALUE( - 67.280),  SIMDE_BFLOAT16_VALUE(  5.574),
        SIMDE_BFLOAT16_VALUE( - 20.029), SIMDE_BFLOAT16_VALUE( - 35.226), SIMDE_BFLOAT16_VALUE( -  1.819), SIMDE_BFLOAT16_VALUE( - 62.990)  } },
         INT8_C(      2) },
    { {  SIMDE_BFLOAT16_VALUE( 23.024), SIMDE_BFLOAT16_VALUE( - 77.316) },
    { {  SIMDE_BFLOAT16_VALUE( 94.862), SIMDE_BFLOAT16_VALUE( - 53.113),  SIMDE_BFLOAT16_VALUE( 76.880), SIMDE_BFLOAT16_VALUE( - 24.592),
         SIMDE_BFLOAT16_VALUE( 23.024), SIMDE_BFLOAT16_VALUE( - 86.319), SIMDE_BFLOAT16_VALUE( - 49.922),  SIMDE_BFLOAT16_VALUE( 74.371)  },
      { SIMDE_BFLOAT16_VALUE( - 35.182),  SIMDE_BFLOAT16_VALUE( 91.375), SIMDE_BFLOAT16_VALUE( - 30.442),  SIMDE_BFLOAT16_VALUE( 62.763),
        SIMDE_BFLOAT16_VALUE( - 77.316), SIMDE_BFLOAT16_VALUE( - 98.725),  SIMDE_BFLOAT16_VALUE( 77.730), SIMDE_BFLOAT16_VALUE( -  6.752)  } },
         INT8_C(      4) },
    { { SIMDE_BFLOAT16_VALUE( - 89.098), SIMDE_BFLOAT16_VALUE( - 47.386) },
    { { SIMDE_BFLOAT16_VALUE( - 37.183), SIMDE_BFLOAT16_VALUE( - 99.478), SIMDE_BFLOAT16_VALUE( - 72.315),  SIMDE_BFLOAT16_VALUE( 60.865),
         SIMDE_BFLOAT16_VALUE( 90.711),  SIMDE_BFLOAT16_VALUE( 33.609),  SIMDE_BFLOAT16_VALUE( 22.229), SIMDE_BFLOAT16_VALUE( - 89.098)  },
      {  SIMDE_BFLOAT16_VALUE( 18.834), SIMDE_BFLOAT16_VALUE( - 38.890),  SIMDE_BFLOAT16_VALUE(  1.151), SIMDE_BFLOAT16_VALUE( - 50.932),
         SIMDE_BFLOAT16_VALUE( 16.869),  SIMDE_BFLOAT16_VALUE( 72.770),  SIMDE_BFLOAT16_VALUE( 43.215), SIMDE_BFLOAT16_VALUE( - 47.386)  } },
         INT8_C(      7) },
    { { SIMDE_BFLOAT16_VALUE( - 74.604),  SIMDE_BFLOAT16_VALUE( 83.519) },
    { { SIMDE_BFLOAT16_VALUE( - 87.245), SIMDE_BFLOAT16_VALUE( - 66.241), SIMDE_BFLOAT16_VALUE( - 49.725), SIMDE_BFLOAT16_VALUE( - 74.604),
         SIMDE_BFLOAT16_VALUE( 52.094), SIMDE_BFLOAT16_VALUE( - 95.107),  SIMDE_BFLOAT16_VALUE( 95.169),  SIMDE_BFLOAT16_VALUE( 80.442)  },
      {  SIMDE_BFLOAT16_VALUE(  4.494),  SIMDE_BFLOAT16_VALUE( 93.210),  SIMDE_BFLOAT16_VALUE( 18.867),  SIMDE_BFLOAT16_VALUE( 83.519),
        SIMDE_BFLOAT16_VALUE( - 54.371), SIMDE_BFLOAT16_VALUE( - 96.968),  SIMDE_BFLOAT16_VALUE( 31.350),  SIMDE_BFLOAT16_VALUE( 84.978)  } },
         INT8_C(      3) },
    { {  SIMDE_BFLOAT16_VALUE( 11.757), SIMDE_BFLOAT16_VALUE( - 92.199) },
    { {  SIMDE_BFLOAT16_VALUE( 11.757),  SIMDE_BFLOAT16_VALUE( 28.988), SIMDE_BFLOAT16_VALUE( - 67.095), SIMDE_BFLOAT16_VALUE( - 58.193),
         SIMDE_BFLOAT16_VALUE( 45.038), SIMDE_BFLOAT16_VALUE( - 42.819), SIMDE_BFLOAT16_VALUE( - 88.284),  SIMDE_BFLOAT16_VALUE( 53.437)  },
      { SIMDE_BFLOAT16_VALUE( - 92.199),  SIMDE_BFLOAT16_VALUE( 12.165),  SIMDE_BFLOAT16_VALUE(  3.097),  SIMDE_BFLOAT16_VALUE( 69.414),
        SIMDE_BFLOAT16_VALUE( - 22.656),  SIMDE_BFLOAT16_VALUE(  5.711), SIMDE_BFLOAT16_VALUE( - 39.886),  SIMDE_BFLOAT16_VALUE( 37.784)  } },
         INT8_C(      0) },
    { {  SIMDE_BFLOAT16_VALUE( 19.626),  SIMDE_BFLOAT16_VALUE( 24.723) },
    { { SIMDE_BFLOAT16_VALUE( -  4.744),  SIMDE_BFLOAT16_VALUE( 15.391),  SIMDE_BFLOAT16_VALUE( 19.626),  SIMDE_BFLOAT16_VALUE( 64.213),
         SIMDE_BFLOAT16_VALUE( 92.541),  SIMDE_BFLOAT16_VALUE( 24.957),  SIMDE_BFLOAT16_VALUE( 42.707), SIMDE_BFLOAT16_VALUE( - 42.789)  },
      { SIMDE_BFLOAT16_VALUE( - 35.790),  SIMDE_BFLOAT16_VALUE( 98.414),  SIMDE_BFLOAT16_VALUE( 24.723), SIMDE_BFLOAT16_VALUE( -  2.908),
         SIMDE_BFLOAT16_VALUE(  8.083), SIMDE_BFLOAT16_VALUE( - 46.904), SIMDE_BFLOAT16_VALUE( - 37.831), SIMDE_BFLOAT16_VALUE( - 59.362)  } },
         INT8_C(      2) },
    { {  SIMDE_BFLOAT16_VALUE( 64.222), SIMDE_BFLOAT16_VALUE( - 33.836) },
    { { SIMDE_BFLOAT16_VALUE( - 31.643), SIMDE_BFLOAT16_VALUE( - 36.586),  SIMDE_BFLOAT16_VALUE( 64.222), SIMDE_BFLOAT16_VALUE( - 73.531),
        SIMDE_BFLOAT16_VALUE( - 64.852),  SIMDE_BFLOAT16_VALUE( 22.974), SIMDE_BFLOAT16_VALUE( - 27.821), SIMDE_BFLOAT16_VALUE( - 62.560)  },
      { SIMDE_BFLOAT16_VALUE( - 78.721),  SIMDE_BFLOAT16_VALUE( 35.577), SIMDE_BFLOAT16_VALUE( - 33.836),  SIMDE_BFLOAT16_VALUE( 54.532),
        SIMDE_BFLOAT16_VALUE( - 39.138), SIMDE_BFLOAT16_VALUE( - 98.477), SIMDE_BFLOAT16_VALUE( - 49.646), SIMDE_BFLOAT16_VALUE( - 72.783)  } },
         INT8_C(      2) },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_bfloat16x8x2_t val = {
        {simde_vld1q_bf16(test_vec[i].val[0]), simde_vld1q_bf16(test_vec[i].val[1])}};
    simde_bfloat16_t a[2];
    SIMDE_CONSTIFY_8_NO_RESULT_(simde_vst2q_lane_bf16, HEDLEY_UNREACHABLE(),
                                test_vec[i].lane, a, val);
    simde_assert_equal_bf16(a[0], test_vec[i].a[0], 1);
    simde_assert_equal_bf16(a[1], test_vec[i].a[1], 1);
  }

  return 0;
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
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_f16)
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
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_lane_bf16)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
