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

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_lane_u32)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
