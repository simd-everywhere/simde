#define SIMDE_TEST_ARM_NEON_INSN ld4_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/ld4_lane.h"
#include "../../../simde/arm/neon/ld1.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld4_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t src[4][8];
    int8_t buf[4];
    int8_t r[4][8];
  } test_vec[] = {
    {
        { {  INT8_C(   6), -INT8_C(  79),  INT8_C(  63),  INT8_C(  82), -INT8_C(  98), -INT8_C( 121), -INT8_C(  69), -INT8_C( 122) },
          { -INT8_C(  38), -INT8_C(  97),  INT8_C(  91),  INT8_C( 123), -INT8_C( 112),  INT8_C( 117),  INT8_C(  78),  INT8_C(  80) },
          { -INT8_C( 106), -INT8_C(  55), -INT8_C(  36), -INT8_C(  71),  INT8_C(   6),  INT8_C( 116), -INT8_C(  45), -INT8_C(  83) },
          { -INT8_C(  43),  INT8_C(  17), -INT8_C(  42), -INT8_C(  12),  INT8_C(   7), -INT8_C(  50),  INT8_C(   6),  INT8_C(  13) } },
      {      INT8_MAX,  INT8_C(  69),  INT8_C(  95),  INT8_C(  29) },
        { {      INT8_MAX, -INT8_C(  79),  INT8_C(  63),  INT8_C(  82), -INT8_C(  98), -INT8_C( 121), -INT8_C(  69), -INT8_C( 122) },
          {  INT8_C(  69), -INT8_C(  97),  INT8_C(  91),  INT8_C( 123), -INT8_C( 112),  INT8_C( 117),  INT8_C(  78),  INT8_C(  80) },
          {  INT8_C(  95), -INT8_C(  55), -INT8_C(  36), -INT8_C(  71),  INT8_C(   6),  INT8_C( 116), -INT8_C(  45), -INT8_C(  83) },
          {  INT8_C(  29),  INT8_C(  17), -INT8_C(  42), -INT8_C(  12),  INT8_C(   7), -INT8_C(  50),  INT8_C(   6),  INT8_C(  13) } },
    },
    {
        { { -INT8_C(  51),  INT8_C(  26), -INT8_C(  93), -INT8_C(  89), -INT8_C(  70), -INT8_C(   2),  INT8_C(  34),  INT8_C(  74) },
          {  INT8_C( 116),  INT8_C( 112), -INT8_C( 102),  INT8_C(  10),  INT8_C(  57),  INT8_C( 118), -INT8_C(  61),  INT8_C(  63) },
          { -INT8_C(  22), -INT8_C( 106), -INT8_C(  20), -INT8_C(  64), -INT8_C(  88), -INT8_C(  62), -INT8_C(  76), -INT8_C(  81) },
          { -INT8_C( 112), -INT8_C(  70), -INT8_C(  68),  INT8_C(  16),  INT8_C(   0),  INT8_C(  27),  INT8_C(  45), -INT8_C(  51) } },
      {  INT8_C(  53), -INT8_C(  47),  INT8_C( 116), -INT8_C(  17) },
        { { -INT8_C(  51),  INT8_C(  53), -INT8_C(  93), -INT8_C(  89), -INT8_C(  70), -INT8_C(   2),  INT8_C(  34),  INT8_C(  74) },
          {  INT8_C( 116), -INT8_C(  47), -INT8_C( 102),  INT8_C(  10),  INT8_C(  57),  INT8_C( 118), -INT8_C(  61),  INT8_C(  63) },
          { -INT8_C(  22),  INT8_C( 116), -INT8_C(  20), -INT8_C(  64), -INT8_C(  88), -INT8_C(  62), -INT8_C(  76), -INT8_C(  81) },
          { -INT8_C( 112), -INT8_C(  17), -INT8_C(  68),  INT8_C(  16),  INT8_C(   0),  INT8_C(  27),  INT8_C(  45), -INT8_C(  51) } },
    },
    {
        { { -INT8_C(  49), -INT8_C( 105),  INT8_C(  57),  INT8_C(  67),  INT8_C(   7), -INT8_C(  45),  INT8_C(  77),  INT8_C(  65) },
          {  INT8_C(  74),  INT8_C(  17),      INT8_MIN,  INT8_C(  52), -INT8_C(  89),  INT8_C( 109), -INT8_C(  12),  INT8_C(  79) },
          {  INT8_C(  47), -INT8_C(  87), -INT8_C(   2), -INT8_C(  64),  INT8_C(  99), -INT8_C(  70), -INT8_C(  48),  INT8_C(  99) },
          { -INT8_C(  43), -INT8_C(   3),  INT8_C(  48),  INT8_C(  11), -INT8_C(  50), -INT8_C(  91), -INT8_C(   6), -INT8_C(  98) } },
      {  INT8_C(  60),  INT8_C(  52), -INT8_C(  31),  INT8_C(  67) },
        { { -INT8_C(  49), -INT8_C( 105),  INT8_C(  60),  INT8_C(  67),  INT8_C(   7), -INT8_C(  45),  INT8_C(  77),  INT8_C(  65) },
          {  INT8_C(  74),  INT8_C(  17),  INT8_C(  52),  INT8_C(  52), -INT8_C(  89),  INT8_C( 109), -INT8_C(  12),  INT8_C(  79) },
          {  INT8_C(  47), -INT8_C(  87), -INT8_C(  31), -INT8_C(  64),  INT8_C(  99), -INT8_C(  70), -INT8_C(  48),  INT8_C(  99) },
          { -INT8_C(  43), -INT8_C(   3),  INT8_C(  67),  INT8_C(  11), -INT8_C(  50), -INT8_C(  91), -INT8_C(   6), -INT8_C(  98) } },
    },
    {
        { {  INT8_C(   7),  INT8_C(  47), -INT8_C( 124),  INT8_C(  81),  INT8_C(  64),  INT8_C(   5), -INT8_C( 122), -INT8_C(  25) },
          {  INT8_C( 114),  INT8_C( 122),  INT8_C(  55), -INT8_C(  95),  INT8_C(  35),  INT8_C(  53),  INT8_C(  97), -INT8_C( 121) },
          { -INT8_C(  16),  INT8_C(  49), -INT8_C(  22), -INT8_C(  59),  INT8_C(  47),  INT8_C(  27), -INT8_C(  48), -INT8_C(   3) },
          { -INT8_C(  64), -INT8_C(  53), -INT8_C( 101), -INT8_C(   4), -INT8_C(   1),  INT8_C( 125),  INT8_C(  63),  INT8_C(   6) } },
      { -INT8_C(  84), -INT8_C(  60),  INT8_C(  88), -INT8_C(  20) },
        { {  INT8_C(   7),  INT8_C(  47), -INT8_C( 124), -INT8_C(  84),  INT8_C(  64),  INT8_C(   5), -INT8_C( 122), -INT8_C(  25) },
          {  INT8_C( 114),  INT8_C( 122),  INT8_C(  55), -INT8_C(  60),  INT8_C(  35),  INT8_C(  53),  INT8_C(  97), -INT8_C( 121) },
          { -INT8_C(  16),  INT8_C(  49), -INT8_C(  22),  INT8_C(  88),  INT8_C(  47),  INT8_C(  27), -INT8_C(  48), -INT8_C(   3) },
          { -INT8_C(  64), -INT8_C(  53), -INT8_C( 101), -INT8_C(  20), -INT8_C(   1),  INT8_C( 125),  INT8_C(  63),  INT8_C(   6) } },
    },
    {
        { { -INT8_C(  55), -INT8_C(  34), -INT8_C(  45),  INT8_C(  59),  INT8_C(  88),  INT8_C(  10), -INT8_C(  36),  INT8_C( 124) },
          {  INT8_C(  64),  INT8_C(  62),  INT8_C(   3),  INT8_C(  48),  INT8_C( 111), -INT8_C(  19), -INT8_C(  11), -INT8_C(  98) },
          {  INT8_C(   8), -INT8_C(  58), -INT8_C( 100), -INT8_C(  56), -INT8_C( 111),  INT8_C(  55), -INT8_C(  60), -INT8_C( 112) },
          { -INT8_C(  76),  INT8_C(   4), -INT8_C( 106),  INT8_C(  96), -INT8_C(  56), -INT8_C(  18),  INT8_C(  76), -INT8_C( 111) } },
      { -INT8_C(  52),  INT8_C(  32), -INT8_C(  52),  INT8_C(  37) },
        { { -INT8_C(  55), -INT8_C(  34), -INT8_C(  45),  INT8_C(  59), -INT8_C(  52),  INT8_C(  10), -INT8_C(  36),  INT8_C( 124) },
          {  INT8_C(  64),  INT8_C(  62),  INT8_C(   3),  INT8_C(  48),  INT8_C(  32), -INT8_C(  19), -INT8_C(  11), -INT8_C(  98) },
          {  INT8_C(   8), -INT8_C(  58), -INT8_C( 100), -INT8_C(  56), -INT8_C(  52),  INT8_C(  55), -INT8_C(  60), -INT8_C( 112) },
          { -INT8_C(  76),  INT8_C(   4), -INT8_C( 106),  INT8_C(  96),  INT8_C(  37), -INT8_C(  18),  INT8_C(  76), -INT8_C( 111) } },
    },
    {
        { {  INT8_C(  42), -INT8_C(  88), -INT8_C(  95),  INT8_C( 106), -INT8_C(  26), -INT8_C(  92), -INT8_C( 102),  INT8_C(  86) },
          { -INT8_C( 111), -INT8_C( 112), -INT8_C(  12), -INT8_C( 102),  INT8_C(  86), -INT8_C( 112),  INT8_C(  98), -INT8_C(  25) },
          { -INT8_C(  56),  INT8_C(  39),  INT8_C( 119),  INT8_C( 124),  INT8_C(  43),  INT8_C(  13), -INT8_C(  35), -INT8_C(  13) },
          { -INT8_C(   4),  INT8_C(  41), -INT8_C( 124), -INT8_C(  56),  INT8_C(  73),  INT8_C(  80), -INT8_C(  19),  INT8_C( 116) } },
      { -INT8_C(   8), -INT8_C( 114), -INT8_C(  34), -INT8_C(  33) },
        { {  INT8_C(  42), -INT8_C(  88), -INT8_C(  95),  INT8_C( 106), -INT8_C(  26), -INT8_C(   8), -INT8_C( 102),  INT8_C(  86) },
          { -INT8_C( 111), -INT8_C( 112), -INT8_C(  12), -INT8_C( 102),  INT8_C(  86), -INT8_C( 114),  INT8_C(  98), -INT8_C(  25) },
          { -INT8_C(  56),  INT8_C(  39),  INT8_C( 119),  INT8_C( 124),  INT8_C(  43), -INT8_C(  34), -INT8_C(  35), -INT8_C(  13) },
          { -INT8_C(   4),  INT8_C(  41), -INT8_C( 124), -INT8_C(  56),  INT8_C(  73), -INT8_C(  33), -INT8_C(  19),  INT8_C( 116) } },
    },
    {
        { {  INT8_C(  50),  INT8_C( 121),  INT8_C(  53), -INT8_C(  60),  INT8_C(   9),  INT8_C(  41),  INT8_C(  94),  INT8_C(  95) },
          { -INT8_C(  70), -INT8_C(  64),  INT8_C(  70), -INT8_C( 126), -INT8_C(  25), -INT8_C(  67), -INT8_C(   2),  INT8_C(  18) },
          { -INT8_C(  54), -INT8_C(  37),  INT8_C(   5), -INT8_C(  58),  INT8_C(   5), -INT8_C( 119), -INT8_C( 113),  INT8_C(  78) },
          { -INT8_C(  39),  INT8_C( 124), -INT8_C(  62), -INT8_C(  46),  INT8_C(  11), -INT8_C(  95), -INT8_C(  79),  INT8_C(  61) } },
      {  INT8_C(  26), -INT8_C(  26),  INT8_C(   1),  INT8_C(  35) },
        { {  INT8_C(  50),  INT8_C( 121),  INT8_C(  53), -INT8_C(  60),  INT8_C(   9),  INT8_C(  41),  INT8_C(  26),  INT8_C(  95) },
          { -INT8_C(  70), -INT8_C(  64),  INT8_C(  70), -INT8_C( 126), -INT8_C(  25), -INT8_C(  67), -INT8_C(  26),  INT8_C(  18) },
          { -INT8_C(  54), -INT8_C(  37),  INT8_C(   5), -INT8_C(  58),  INT8_C(   5), -INT8_C( 119),  INT8_C(   1),  INT8_C(  78) },
          { -INT8_C(  39),  INT8_C( 124), -INT8_C(  62), -INT8_C(  46),  INT8_C(  11), -INT8_C(  95),  INT8_C(  35),  INT8_C(  61) } },
    },
    {
        { {  INT8_C(  15),  INT8_C(  95), -INT8_C( 126), -INT8_C(  55),  INT8_C(  32), -INT8_C(  56),  INT8_C(  75),  INT8_C(   7) },
          { -INT8_C( 123),  INT8_C(  74),  INT8_C(  26),  INT8_C(  79),  INT8_C(  37),  INT8_C(  31),  INT8_C(  22),  INT8_C(  42) },
          { -INT8_C(  87), -INT8_C(  91),  INT8_C( 121), -INT8_C( 126),  INT8_C(  33),  INT8_C(  59),  INT8_C(  84),  INT8_C(  44) },
          { -INT8_C(  36),  INT8_C(   5),  INT8_C( 106), -INT8_C(  10), -INT8_C(  21),  INT8_C( 107),  INT8_C(  25), -INT8_C(   5) } },
      { -INT8_C(  53), -INT8_C( 101), -INT8_C(  60), -INT8_C(  21) },
        { {  INT8_C(  15),  INT8_C(  95), -INT8_C( 126), -INT8_C(  55),  INT8_C(  32), -INT8_C(  56),  INT8_C(  75), -INT8_C(  53) },
          { -INT8_C( 123),  INT8_C(  74),  INT8_C(  26),  INT8_C(  79),  INT8_C(  37),  INT8_C(  31),  INT8_C(  22), -INT8_C( 101) },
          { -INT8_C(  87), -INT8_C(  91),  INT8_C( 121), -INT8_C( 126),  INT8_C(  33),  INT8_C(  59),  INT8_C(  84), -INT8_C(  60) },
          { -INT8_C(  36),  INT8_C(   5),  INT8_C( 106), -INT8_C(  10), -INT8_C(  21),  INT8_C( 107),  INT8_C(  25), -INT8_C(  21) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x4_t r;
    simde_int8x8x4_t src = {
        {simde_vld1_s8(test_vec[i].src[0]), simde_vld1_s8(test_vec[i].src[1]),
         simde_vld1_s8(test_vec[i].src[2]), simde_vld1_s8(test_vec[i].src[3])}};
    simde_int8x8x4_t expected = {
        {simde_vld1_s8(test_vec[i].r[0]), simde_vld1_s8(test_vec[i].r[1]),
         simde_vld1_s8(test_vec[i].r[2]), simde_vld1_s8(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_8_(simde_vld4_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8x4_t src = simde_test_arm_neon_random_i8x8x4();
    simde_test_arm_neon_write_i8x8x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int8_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vi8(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int8x8x4_t r;
    SIMDE_CONSTIFY_8_(simde_vld4_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_i8x8x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t src[4][4];
    int16_t buf[4];
    int16_t r[4][4];
  } test_vec[] = {
    {
        { { -INT16_C( 18424),  INT16_C( 22298), -INT16_C(  9407),  INT16_C( 10821) },
          {  INT16_C(  1649),  INT16_C( 28692), -INT16_C( 29690),  INT16_C(  4079) },
          {  INT16_C(  5162),  INT16_C( 10635),  INT16_C( 21625),  INT16_C( 24093) },
          { -INT16_C(  4458), -INT16_C( 23250),  INT16_C(  1945), -INT16_C( 24312) } },
      {  INT16_C(  8895),  INT16_C(   504),  INT16_C(     0),  INT16_C(     0) },
        { {  INT16_C(  8895),  INT16_C( 22298), -INT16_C(  9407),  INT16_C( 10821) },
          {  INT16_C(   504),  INT16_C( 28692), -INT16_C( 29690),  INT16_C(  4079) },
          {  INT16_C(     0),  INT16_C( 10635),  INT16_C( 21625),  INT16_C( 24093) },
          {  INT16_C(     0), -INT16_C( 23250),  INT16_C(  1945), -INT16_C( 24312) } },
    },
    {
        { {  INT16_C( 16125),  INT16_C( 28203),  INT16_C( 16196),  INT16_C( 19166) },
          { -INT16_C( 12853), -INT16_C(  2727), -INT16_C(  6687),  INT16_C( 23326) },
          {  INT16_C( 15417), -INT16_C( 12359), -INT16_C(  6358), -INT16_C( 15244) },
          {  INT16_C( 31983), -INT16_C( 20891),  INT16_C( 24222), -INT16_C( 25425) } },
      { -INT16_C(  9316), -INT16_C(  8182),  INT16_C(     0),  INT16_C(     0) },
        { {  INT16_C( 16125), -INT16_C(  9316),  INT16_C( 16196),  INT16_C( 19166) },
          { -INT16_C( 12853), -INT16_C(  8182), -INT16_C(  6687),  INT16_C( 23326) },
          {  INT16_C( 15417),  INT16_C(     0), -INT16_C(  6358), -INT16_C( 15244) },
          {  INT16_C( 31983),  INT16_C(     0),  INT16_C( 24222), -INT16_C( 25425) } },
    },
    {
        { { -INT16_C(  5862), -INT16_C(  6613), -INT16_C( 31562), -INT16_C( 26405) },
          { -INT16_C(  1431), -INT16_C( 23821), -INT16_C( 21450),  INT16_C( 24689) },
          { -INT16_C(  6765), -INT16_C( 32220), -INT16_C( 30111),  INT16_C(    49) },
          { -INT16_C(  7960), -INT16_C( 31588), -INT16_C( 22853), -INT16_C( 10652) } },
      { -INT16_C( 28785),  INT16_C( 18108),  INT16_C(     0),  INT16_C(     0) },
        { { -INT16_C(  5862), -INT16_C(  6613), -INT16_C( 28785), -INT16_C( 26405) },
          { -INT16_C(  1431), -INT16_C( 23821),  INT16_C( 18108),  INT16_C( 24689) },
          { -INT16_C(  6765), -INT16_C( 32220),  INT16_C(     0),  INT16_C(    49) },
          { -INT16_C(  7960), -INT16_C( 31588),  INT16_C(     0), -INT16_C( 10652) } },
    },
    {
        { { -INT16_C( 26860),  INT16_C( 32222), -INT16_C( 11887), -INT16_C( 14560) },
          { -INT16_C( 28291),  INT16_C(  4136),  INT16_C( 19575), -INT16_C( 10093) },
          { -INT16_C( 15146), -INT16_C( 16680),  INT16_C( 29860),  INT16_C( 24642) },
          { -INT16_C( 22757), -INT16_C( 21962), -INT16_C(  3530),  INT16_C( 19184) } },
      { -INT16_C( 12663),  INT16_C(  7112),  INT16_C(     0),  INT16_C(     0) },
        { { -INT16_C( 26860),  INT16_C( 32222), -INT16_C( 11887), -INT16_C( 12663) },
          { -INT16_C( 28291),  INT16_C(  4136),  INT16_C( 19575),  INT16_C(  7112) },
          { -INT16_C( 15146), -INT16_C( 16680),  INT16_C( 29860),  INT16_C(     0) },
          { -INT16_C( 22757), -INT16_C( 21962), -INT16_C(  3530),  INT16_C(     0) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x4_t r;
    simde_int16x4x4_t src = {
        {simde_vld1_s16(test_vec[i].src[0]), simde_vld1_s16(test_vec[i].src[1]),
         simde_vld1_s16(test_vec[i].src[2]), simde_vld1_s16(test_vec[i].src[3])}};
    simde_int16x4x4_t expected = {
        {simde_vld1_s16(test_vec[i].r[0]), simde_vld1_s16(test_vec[i].r[1]),
         simde_vld1_s16(test_vec[i].r[2]), simde_vld1_s16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_4_(simde_vld4_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_int16x4x4_t src = simde_test_arm_neon_random_i16x4x4();
    simde_test_arm_neon_write_i16x4x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int16_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vi16(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int16x4x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld4_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_i16x4x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t src[4][8];
    int32_t buf[4];
    int32_t r[4][8];
  } test_vec[] = {
    {
        { {  INT32_C(  1600659140), -INT32_C(   869507461) },
          { -INT32_C(   257181748),  INT32_C(   970225014) },
          {  INT32_C(  1880013894),  INT32_C(  1806348973) },
          { -INT32_C(  1085848577), -INT32_C(  1482812702) } },
      { -INT32_C(  1408891343),  INT32_C(           0),  INT32_C(  1063663797),  INT32_C(  1073734480) },
        { { -INT32_C(  1408891343), -INT32_C(   869507461) },
          {  INT32_C(           0),  INT32_C(   970225014) },
          {  INT32_C(  1063663797),  INT32_C(  1806348973) },
          {  INT32_C(  1073734480), -INT32_C(  1482812702) } },
    },
    {
        { {  INT32_C(   813183844),  INT32_C(  1612719082) },
          { -INT32_C(   543492968),  INT32_C(  1565501616) },
          {  INT32_C(  1506343514),  INT32_C(   538447677) },
          {  INT32_C(  1405597474),  INT32_C(   587189693) } },
      { -INT32_C(   363694336),  INT32_C(           0),  INT32_C(  1063663797),  INT32_C(  1073734480) },
        { {  INT32_C(   813183844), -INT32_C(   363694336) },
          { -INT32_C(   543492968),  INT32_C(           0) },
          {  INT32_C(  1506343514),  INT32_C(  1063663797) },
          {  INT32_C(  1405597474),  INT32_C(  1073734480) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x4_t r;
    simde_int32x2x4_t src = {
        {simde_vld1_s32(test_vec[i].src[0]), simde_vld1_s32(test_vec[i].src[1]),
         simde_vld1_s32(test_vec[i].src[2]), simde_vld1_s32(test_vec[i].src[3])}};
    simde_int32x2x4_t expected = {
        {simde_vld1_s32(test_vec[i].r[0]), simde_vld1_s32(test_vec[i].r[1]),
         simde_vld1_s32(test_vec[i].r[2]), simde_vld1_s32(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_2_(simde_vld4_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_int32x2x4_t src = simde_test_arm_neon_random_i32x2x4();
    simde_test_arm_neon_write_i32x2x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int32_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vi32(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int32x2x4_t r;
    SIMDE_CONSTIFY_2_(simde_vld4_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_i32x2x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t src[4][8];
    int64_t buf[4];
    int64_t r[4][8];
  } test_vec[] = {
    {
        { {  INT64_C( 5642904371545280401) },
          { -INT64_C(  711416625901707609) },
          {  INT64_C( 8299642698000536885) },
          {  INT64_C( 3817005894186430286) } },
      {  INT64_C( 4611654480098454601),  INT64_C(                   0),  INT64_C(          4294967296),  INT64_C( 4616194021471028225) },
        { {  INT64_C( 4611654480098454601) },
          {  INT64_C(                   0) },
          {  INT64_C(          4294967296) },
          {  INT64_C( 4616194021471028225) } },
    },
    {
        { {  INT64_C( 2506546529019849484) },
          { -INT64_C( 8268304906103232108) },
          {  INT64_C(  202818524639424341) },
          {  INT64_C( 4646397826290927688) } },
      {  INT64_C( 4611654478451749565),  INT64_C(                   0),  INT64_C(          4294967296),  INT64_C( 4616194021471028225) },
        { {  INT64_C( 4611654478451749565) },
          {  INT64_C(                   0) },
          {  INT64_C(          4294967296) },
          {  INT64_C( 4616194021471028225) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x4_t src = {
        {simde_vld1_s64(test_vec[i].src[0]), simde_vld1_s64(test_vec[i].src[1]),
         simde_vld1_s64(test_vec[i].src[2]), simde_vld1_s64(test_vec[i].src[3])}};
    simde_int64x1x4_t r = simde_vld4_lane_s64(test_vec[i].buf, src, 0);

    simde_int64x1x4_t expected = {
        {simde_vld1_s64(test_vec[i].r[0]), simde_vld1_s64(test_vec[i].r[1]),
         simde_vld1_s64(test_vec[i].r[2]), simde_vld1_s64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_int64x1x4_t src = simde_test_arm_neon_random_i64x1x4();
    simde_test_arm_neon_write_i64x1x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int64_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vi64(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int64x1x4_t r = simde_vld4_lane_s64(buf, src, 0);
    simde_test_arm_neon_write_i64x1x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t src[4][8];
    uint8_t buf[4];
    uint8_t r[4][8];
  } test_vec[] = {
    {
        { { UINT8_C(117), UINT8_C( 19), UINT8_C(134), UINT8_C(112), UINT8_C(144), UINT8_C(147), UINT8_C( 77), UINT8_C( 69) },
          { UINT8_C( 36), UINT8_C(194), UINT8_C( 23), UINT8_C(228), UINT8_C(  1), UINT8_C( 38), UINT8_C( 18), UINT8_C(146) },
          { UINT8_C(113), UINT8_C(220), UINT8_C(108), UINT8_C( 23), UINT8_C(208), UINT8_C(110), UINT8_C(202), UINT8_C(158) },
          { UINT8_C( 71), UINT8_C( 69), UINT8_C(247), UINT8_C(164), UINT8_C( 87), UINT8_C( 73), UINT8_C(196), UINT8_C(204) } },
      { UINT8_C( 92), UINT8_C( 74), UINT8_C( 60), UINT8_C(236) },
        { { UINT8_C( 92), UINT8_C( 19), UINT8_C(134), UINT8_C(112), UINT8_C(144), UINT8_C(147), UINT8_C( 77), UINT8_C( 69) },
          { UINT8_C( 74), UINT8_C(194), UINT8_C( 23), UINT8_C(228), UINT8_C(  1), UINT8_C( 38), UINT8_C( 18), UINT8_C(146) },
          { UINT8_C( 60), UINT8_C(220), UINT8_C(108), UINT8_C( 23), UINT8_C(208), UINT8_C(110), UINT8_C(202), UINT8_C(158) },
          { UINT8_C(236), UINT8_C( 69), UINT8_C(247), UINT8_C(164), UINT8_C( 87), UINT8_C( 73), UINT8_C(196), UINT8_C(204) } },
    },
    {
        { { UINT8_C(221), UINT8_C(138), UINT8_C( 50), UINT8_C(  1), UINT8_C( 76), UINT8_C( 73), UINT8_C(230), UINT8_C( 77) },
          { UINT8_C(111), UINT8_C(248), UINT8_C(223), UINT8_C(225), UINT8_C(212), UINT8_C( 76), UINT8_C(248), UINT8_C(164) },
          { UINT8_C(186), UINT8_C(194), UINT8_C( 66), UINT8_C(  1), UINT8_C(  7), UINT8_C( 57), UINT8_C(165), UINT8_C( 94) },
          { UINT8_C(130), UINT8_C(106), UINT8_C( 43), UINT8_C(223), UINT8_C(180), UINT8_C(103), UINT8_C(203), UINT8_C(146) } },
      { UINT8_C(241), UINT8_C(253), UINT8_C(147), UINT8_C( 61) },
        { { UINT8_C(221), UINT8_C(241), UINT8_C( 50), UINT8_C(  1), UINT8_C( 76), UINT8_C( 73), UINT8_C(230), UINT8_C( 77) },
          { UINT8_C(111), UINT8_C(253), UINT8_C(223), UINT8_C(225), UINT8_C(212), UINT8_C( 76), UINT8_C(248), UINT8_C(164) },
          { UINT8_C(186), UINT8_C(147), UINT8_C( 66), UINT8_C(  1), UINT8_C(  7), UINT8_C( 57), UINT8_C(165), UINT8_C( 94) },
          { UINT8_C(130), UINT8_C( 61), UINT8_C( 43), UINT8_C(223), UINT8_C(180), UINT8_C(103), UINT8_C(203), UINT8_C(146) } },
    },
    {
        { { UINT8_C( 71), UINT8_C(121), UINT8_C(139), UINT8_C(182), UINT8_C(114), UINT8_C(106), UINT8_C(151), UINT8_C( 70) },
          { UINT8_C(182), UINT8_C(143), UINT8_C(235), UINT8_C(112), UINT8_C( 81), UINT8_C( 45), UINT8_C(113), UINT8_C( 88) },
          { UINT8_C(103), UINT8_C( 23), UINT8_C(183), UINT8_C(233), UINT8_C(129), UINT8_C(226), UINT8_C(200), UINT8_C( 53) },
          { UINT8_C( 73), UINT8_C(148), UINT8_C(199), UINT8_C( 59), UINT8_C(145), UINT8_C( 91), UINT8_C(120), UINT8_C(216) } },
      { UINT8_C(212), UINT8_C(  3), UINT8_C(143), UINT8_C( 70) },
        { { UINT8_C( 71), UINT8_C(121), UINT8_C(212), UINT8_C(182), UINT8_C(114), UINT8_C(106), UINT8_C(151), UINT8_C( 70) },
          { UINT8_C(182), UINT8_C(143), UINT8_C(  3), UINT8_C(112), UINT8_C( 81), UINT8_C( 45), UINT8_C(113), UINT8_C( 88) },
          { UINT8_C(103), UINT8_C( 23), UINT8_C(143), UINT8_C(233), UINT8_C(129), UINT8_C(226), UINT8_C(200), UINT8_C( 53) },
          { UINT8_C( 73), UINT8_C(148), UINT8_C( 70), UINT8_C( 59), UINT8_C(145), UINT8_C( 91), UINT8_C(120), UINT8_C(216) } },
    },
    {
        { { UINT8_C(110), UINT8_C( 38), UINT8_C(141), UINT8_C( 36), UINT8_C(182), UINT8_C(120), UINT8_C(149), UINT8_C(  7) },
          { UINT8_C(165), UINT8_C(  6), UINT8_C( 96), UINT8_C( 12), UINT8_C( 29), UINT8_C( 23), UINT8_C(246), UINT8_C(158) },
          { UINT8_C(249), UINT8_C(190), UINT8_C(212), UINT8_C( 66), UINT8_C( 82), UINT8_C(155), UINT8_C(125), UINT8_C(228) },
          { UINT8_C(246), UINT8_C(246), UINT8_C(188), UINT8_C(203), UINT8_C(249), UINT8_C( 75), UINT8_C( 17), UINT8_C(103) } },
      { UINT8_C(114), UINT8_C(158), UINT8_C(140), UINT8_C( 40) },
        { { UINT8_C(110), UINT8_C( 38), UINT8_C(141), UINT8_C(114), UINT8_C(182), UINT8_C(120), UINT8_C(149), UINT8_C(  7) },
          { UINT8_C(165), UINT8_C(  6), UINT8_C( 96), UINT8_C(158), UINT8_C( 29), UINT8_C( 23), UINT8_C(246), UINT8_C(158) },
          { UINT8_C(249), UINT8_C(190), UINT8_C(212), UINT8_C(140), UINT8_C( 82), UINT8_C(155), UINT8_C(125), UINT8_C(228) },
          { UINT8_C(246), UINT8_C(246), UINT8_C(188), UINT8_C( 40), UINT8_C(249), UINT8_C( 75), UINT8_C( 17), UINT8_C(103) } },
    },
    {
        { { UINT8_C( 22), UINT8_C( 33), UINT8_C( 47), UINT8_C(188), UINT8_C( 39), UINT8_C(143), UINT8_C(200), UINT8_C( 69) },
          { UINT8_C(166), UINT8_C(190), UINT8_C(227), UINT8_C(159), UINT8_C(125), UINT8_C(183), UINT8_C(226), UINT8_C(207) },
          { UINT8_C( 83), UINT8_C( 95), UINT8_C(179), UINT8_C( 73), UINT8_C( 85), UINT8_C(112), UINT8_C( 20), UINT8_C( 79) },
          { UINT8_C(187), UINT8_C( 38), UINT8_C(182), UINT8_C( 45), UINT8_C(196), UINT8_C( 66), UINT8_C( 85), UINT8_C(219) } },
      { UINT8_C( 99), UINT8_C(133), UINT8_C(151), UINT8_C(139) },
        { { UINT8_C( 22), UINT8_C( 33), UINT8_C( 47), UINT8_C(188), UINT8_C( 99), UINT8_C(143), UINT8_C(200), UINT8_C( 69) },
          { UINT8_C(166), UINT8_C(190), UINT8_C(227), UINT8_C(159), UINT8_C(133), UINT8_C(183), UINT8_C(226), UINT8_C(207) },
          { UINT8_C( 83), UINT8_C( 95), UINT8_C(179), UINT8_C( 73), UINT8_C(151), UINT8_C(112), UINT8_C( 20), UINT8_C( 79) },
          { UINT8_C(187), UINT8_C( 38), UINT8_C(182), UINT8_C( 45), UINT8_C(139), UINT8_C( 66), UINT8_C( 85), UINT8_C(219) } },
    },
    {
        { { UINT8_C( 20), UINT8_C( 95), UINT8_C(208), UINT8_C(187), UINT8_C( 30), UINT8_C(179), UINT8_C( 90), UINT8_C(155) },
          { UINT8_C(107), UINT8_C( 60), UINT8_C(106), UINT8_C(190), UINT8_C(156), UINT8_C( 30), UINT8_C(  7), UINT8_C(241) },
          { UINT8_C(142), UINT8_C( 28), UINT8_C( 64), UINT8_C( 73), UINT8_C( 66), UINT8_C(247), UINT8_C(119), UINT8_C(  6) },
          { UINT8_C( 57), UINT8_C(204), UINT8_C(225), UINT8_C(157), UINT8_C( 81), UINT8_C(120), UINT8_C( 40), UINT8_C(102) } },
      { UINT8_C(216), UINT8_C(248), UINT8_C( 33), UINT8_C(246) },
        { { UINT8_C( 20), UINT8_C( 95), UINT8_C(208), UINT8_C(187), UINT8_C( 30), UINT8_C(216), UINT8_C( 90), UINT8_C(155) },
          { UINT8_C(107), UINT8_C( 60), UINT8_C(106), UINT8_C(190), UINT8_C(156), UINT8_C(248), UINT8_C(  7), UINT8_C(241) },
          { UINT8_C(142), UINT8_C( 28), UINT8_C( 64), UINT8_C( 73), UINT8_C( 66), UINT8_C( 33), UINT8_C(119), UINT8_C(  6) },
          { UINT8_C( 57), UINT8_C(204), UINT8_C(225), UINT8_C(157), UINT8_C( 81), UINT8_C(246), UINT8_C( 40), UINT8_C(102) } },
    },
    {
        { { UINT8_C(171), UINT8_C(123), UINT8_C(145), UINT8_C( 22), UINT8_C(184), UINT8_C(251), UINT8_C(212), UINT8_C( 84) },
          { UINT8_C( 25), UINT8_C(220), UINT8_C( 69), UINT8_C(167), UINT8_C(248), UINT8_C(134), UINT8_C(241), UINT8_C( 58) },
          { UINT8_C(125), UINT8_C(104), UINT8_C( 64), UINT8_C(182), UINT8_C( 52), UINT8_C( 34), UINT8_C( 83), UINT8_C(134) },
          { UINT8_C(154), UINT8_C(123), UINT8_C(236), UINT8_C(114), UINT8_C(115), UINT8_C( 13), UINT8_C(104), UINT8_C( 31) } },
      { UINT8_C(136), UINT8_C(249), UINT8_C( 53), UINT8_C( 64) },
        { { UINT8_C(171), UINT8_C(123), UINT8_C(145), UINT8_C( 22), UINT8_C(184), UINT8_C(251), UINT8_C(136), UINT8_C( 84) },
          { UINT8_C( 25), UINT8_C(220), UINT8_C( 69), UINT8_C(167), UINT8_C(248), UINT8_C(134), UINT8_C(249), UINT8_C( 58) },
          { UINT8_C(125), UINT8_C(104), UINT8_C( 64), UINT8_C(182), UINT8_C( 52), UINT8_C( 34), UINT8_C( 53), UINT8_C(134) },
          { UINT8_C(154), UINT8_C(123), UINT8_C(236), UINT8_C(114), UINT8_C(115), UINT8_C( 13), UINT8_C( 64), UINT8_C( 31) } },
    },
    {
        { { UINT8_C(245), UINT8_C( 10), UINT8_C(148), UINT8_C( 14), UINT8_C(230), UINT8_C(218), UINT8_C(182), UINT8_C(222) },
          { UINT8_C( 96), UINT8_C(167), UINT8_C( 24), UINT8_C(221), UINT8_C( 15), UINT8_C( 88), UINT8_C(147), UINT8_C( 67) },
          { UINT8_C(122), UINT8_C(231), UINT8_C(201), UINT8_C( 21), UINT8_C( 98), UINT8_C(181), UINT8_C(135), UINT8_C(214) },
          { UINT8_C(194), UINT8_C(240), UINT8_C(245), UINT8_C( 75), UINT8_C(233), UINT8_C( 42), UINT8_C(139), UINT8_C(222) } },
      { UINT8_C( 52), UINT8_C( 32), UINT8_C(237), UINT8_C( 26) },
        { { UINT8_C(245), UINT8_C( 10), UINT8_C(148), UINT8_C( 14), UINT8_C(230), UINT8_C(218), UINT8_C(182), UINT8_C( 52) },
          { UINT8_C( 96), UINT8_C(167), UINT8_C( 24), UINT8_C(221), UINT8_C( 15), UINT8_C( 88), UINT8_C(147), UINT8_C( 32) },
          { UINT8_C(122), UINT8_C(231), UINT8_C(201), UINT8_C( 21), UINT8_C( 98), UINT8_C(181), UINT8_C(135), UINT8_C(237) },
          { UINT8_C(194), UINT8_C(240), UINT8_C(245), UINT8_C( 75), UINT8_C(233), UINT8_C( 42), UINT8_C(139), UINT8_C( 26) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x4_t r;
    simde_uint8x8x4_t src = {
        {simde_vld1_u8(test_vec[i].src[0]), simde_vld1_u8(test_vec[i].src[1]),
         simde_vld1_u8(test_vec[i].src[2]), simde_vld1_u8(test_vec[i].src[3])}};
    simde_uint8x8x4_t expected = {
        {simde_vld1_u8(test_vec[i].r[0]), simde_vld1_u8(test_vec[i].r[1]),
         simde_vld1_u8(test_vec[i].r[2]), simde_vld1_u8(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_8_(simde_vld4_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);


    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8x4_t src = simde_test_arm_neon_random_u8x8x4();
    simde_test_arm_neon_write_u8x8x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint8_t buf[4];
    simde_test_codegen_random_memory(4, buf);
    simde_test_codegen_write_vu8(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint8x8x4_t r;
    SIMDE_CONSTIFY_8_(simde_vld4_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_u8x8x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t src[4][4];
    uint16_t buf[4];
    uint16_t r[4][4];
  } test_vec[] = {
    {
        { { UINT16_C(51978), UINT16_C(  842), UINT16_C(19122), UINT16_C( 1111) },
          { UINT16_C(64538), UINT16_C(59508), UINT16_C(24002), UINT16_C(17590) },
          { UINT16_C(39624), UINT16_C(38972), UINT16_C(26313), UINT16_C(24858) },
          { UINT16_C(58101), UINT16_C(29864), UINT16_C( 4542), UINT16_C(51367) } },
      { UINT16_C(61917), UINT16_C(36812), UINT16_C(63644), UINT16_C(61703) },
        { { UINT16_C(61917), UINT16_C(  842), UINT16_C(19122), UINT16_C( 1111) },
          { UINT16_C(36812), UINT16_C(59508), UINT16_C(24002), UINT16_C(17590) },
          { UINT16_C(63644), UINT16_C(38972), UINT16_C(26313), UINT16_C(24858) },
          { UINT16_C(61703), UINT16_C(29864), UINT16_C( 4542), UINT16_C(51367) } },
    },
    {
        { { UINT16_C( 9019), UINT16_C(21908), UINT16_C( 2079), UINT16_C(57917) },
          { UINT16_C(62565), UINT16_C(11558), UINT16_C(25230), UINT16_C(22469) },
          { UINT16_C(57288), UINT16_C(48824), UINT16_C(24769), UINT16_C(32818) },
          { UINT16_C(55666), UINT16_C(20296), UINT16_C( 5323), UINT16_C( 1758) } },
      { UINT16_C(29240), UINT16_C(22364), UINT16_C(63644), UINT16_C(61703) },
        { { UINT16_C( 9019), UINT16_C(29240), UINT16_C( 2079), UINT16_C(57917) },
          { UINT16_C(62565), UINT16_C(22364), UINT16_C(25230), UINT16_C(22469) },
          { UINT16_C(57288), UINT16_C(63644), UINT16_C(24769), UINT16_C(32818) },
          { UINT16_C(55666), UINT16_C(61703), UINT16_C( 5323), UINT16_C( 1758) } },
    },
    {
        { { UINT16_C(39290), UINT16_C(57145), UINT16_C(24461), UINT16_C( 6925) },
          { UINT16_C(53954), UINT16_C(35443), UINT16_C(11186), UINT16_C(29512) },
          { UINT16_C(31628), UINT16_C(65267), UINT16_C(15444), UINT16_C( 8013) },
          { UINT16_C(11088), UINT16_C(34854), UINT16_C(33438), UINT16_C( 6368) } },
      { UINT16_C( 6427), UINT16_C(43512), UINT16_C(63644), UINT16_C(61703) },
        { { UINT16_C(39290), UINT16_C(57145), UINT16_C( 6427), UINT16_C( 6925) },
          { UINT16_C(53954), UINT16_C(35443), UINT16_C(43512), UINT16_C(29512) },
          { UINT16_C(31628), UINT16_C(65267), UINT16_C(63644), UINT16_C( 8013) },
          { UINT16_C(11088), UINT16_C(34854), UINT16_C(61703), UINT16_C( 6368) } },
    },
    {
        { { UINT16_C( 1401), UINT16_C(15300), UINT16_C(14295), UINT16_C(35269) },
          { UINT16_C( 3683), UINT16_C(61437), UINT16_C(61577), UINT16_C(56813) },
          { UINT16_C(14892), UINT16_C(32253), UINT16_C( 9061), UINT16_C(  773) },
          { UINT16_C(58789), UINT16_C(49180), UINT16_C( 5375), UINT16_C(30825) } },
      { UINT16_C(11801), UINT16_C(61619), UINT16_C(63644), UINT16_C(61703) },
        { { UINT16_C( 1401), UINT16_C(15300), UINT16_C(14295), UINT16_C(11801) },
          { UINT16_C( 3683), UINT16_C(61437), UINT16_C(61577), UINT16_C(61619) },
          { UINT16_C(14892), UINT16_C(32253), UINT16_C( 9061), UINT16_C(63644) },
          { UINT16_C(58789), UINT16_C(49180), UINT16_C( 5375), UINT16_C(61703) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x4_t r;
    simde_uint16x4x4_t src = {
        {simde_vld1_u16(test_vec[i].src[0]), simde_vld1_u16(test_vec[i].src[1]),
         simde_vld1_u16(test_vec[i].src[2]), simde_vld1_u16(test_vec[i].src[3])}};
    simde_uint16x4x4_t expected = {
        {simde_vld1_u16(test_vec[i].r[0]), simde_vld1_u16(test_vec[i].r[1]),
         simde_vld1_u16(test_vec[i].r[2]), simde_vld1_u16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_4_(simde_vld4_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_u16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint16x4x4_t src = simde_test_arm_neon_random_u16x4x4();
    simde_test_arm_neon_write_u16x4x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint16_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vu16(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint16x4x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld4_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_u16x4x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t src[4][8];
    uint32_t buf[4];
    uint32_t r[4][8];
  } test_vec[] = {
    {
        { { UINT32_C( 185984536), UINT32_C(2412175842) },
          { UINT32_C( 538607448), UINT32_C(1935848728) },
          { UINT32_C(4135226430), UINT32_C( 537512028) },
          { UINT32_C( 995058037), UINT32_C(2893705363) } },
      { UINT32_C( 951553878), UINT32_C(         0), UINT32_C(1063663797), UINT32_C(1073734480) },
        { { UINT32_C( 951553878), UINT32_C(2412175842) },
          { UINT32_C(         0), UINT32_C(1935848728) },
          { UINT32_C(1063663797), UINT32_C( 537512028) },
          { UINT32_C(1073734480), UINT32_C(2893705363) } },
    },
    {
        { { UINT32_C(3368582768), UINT32_C( 367649533) },
          { UINT32_C(3599256472), UINT32_C( 885785303) },
          { UINT32_C(1079301578), UINT32_C(3397100342) },
          { UINT32_C(1769403667), UINT32_C(4120980869) } },
      { UINT32_C(2831051179), UINT32_C(         0), UINT32_C(1063663797), UINT32_C(1073734480) },
        { { UINT32_C(3368582768), UINT32_C(2831051179) },
          { UINT32_C(3599256472), UINT32_C(         0) },
          { UINT32_C(1079301578), UINT32_C(1063663797) },
          { UINT32_C(1769403667), UINT32_C(1073734480) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x4_t r;
    simde_uint32x2x4_t src = {
        {simde_vld1_u32(test_vec[i].src[0]), simde_vld1_u32(test_vec[i].src[1]),
         simde_vld1_u32(test_vec[i].src[2]), simde_vld1_u32(test_vec[i].src[3])}};
    simde_uint32x2x4_t expected = {
        {simde_vld1_u32(test_vec[i].r[0]), simde_vld1_u32(test_vec[i].r[1]),
         simde_vld1_u32(test_vec[i].r[2]), simde_vld1_u32(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_2_(simde_vld4_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_u32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_uint32x2x4_t src = simde_test_arm_neon_random_u32x2x4();
    simde_test_arm_neon_write_u32x2x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint32_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vu32(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint32x2x4_t r;
    SIMDE_CONSTIFY_2_(simde_vld4_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_u32x2x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t src[4][8];
    uint64_t buf[4];
    uint64_t r[4][8];
  } test_vec[] = {
    {
        { { UINT64_C(15683032258095195276) },
          { UINT64_C( 7553468336959036474) },
          { UINT64_C(13125156628617814216) },
          { UINT64_C( 6195188131824092394) } },
      { UINT64_C( 4611654476681296478), UINT64_C(                   0), UINT64_C( 4611686022722355200), UINT64_C( 4616194021471028225) },
        { { UINT64_C( 4611654476681296478) },
          { UINT64_C(                   0) },
          { UINT64_C( 4611686022722355200) },
          { UINT64_C( 4616194021471028225) } },
    },
    {
        { { UINT64_C( 2088703405382308364) },
          { UINT64_C( 1841591475801215200) },
          { UINT64_C(13963102749140759697) },
          { UINT64_C( 9663743460424204193) } },
      { UINT64_C( 4611654477341791126), UINT64_C(                   0), UINT64_C( 4611686022722355200), UINT64_C( 4616194021471028225) },
        { { UINT64_C( 4611654477341791126) },
          { UINT64_C(                   0) },
          { UINT64_C( 4611686022722355200) },
          { UINT64_C( 4616194021471028225) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x4_t src = {
        {simde_vld1_u64(test_vec[i].src[0]), simde_vld1_u64(test_vec[i].src[1]),
         simde_vld1_u64(test_vec[i].src[2]), simde_vld1_u64(test_vec[i].src[3])}};

    simde_uint64x1x4_t r = simde_vld4_lane_u64(test_vec[i].buf, src, 0);

    simde_uint64x1x4_t expected = {
        {simde_vld1_u64(test_vec[i].r[0]), simde_vld1_u64(test_vec[i].r[1]),
         simde_vld1_u64(test_vec[i].r[2]), simde_vld1_u64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_uint64x1x4_t src = simde_test_arm_neon_random_u64x1x4();
    simde_test_arm_neon_write_u64x1x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint64_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vu64(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint64x1x4_t r = simde_vld4_lane_u64(buf, src, 0);
    simde_test_arm_neon_write_u64x1x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t src[4][4];
    simde_float16_t buf[4];
    simde_float16_t r[4][4];
  } test_vec[] = {
   { { {  SIMDE_FLOAT16_VALUE(-23.48), SIMDE_FLOAT16_VALUE(-23.67), SIMDE_FLOAT16_VALUE(44.71), SIMDE_FLOAT16_VALUE(-48.89) },
       {  SIMDE_FLOAT16_VALUE(46.07), SIMDE_FLOAT16_VALUE(-4.26), SIMDE_FLOAT16_VALUE(-33.58), SIMDE_FLOAT16_VALUE(-23.36) },
       {  SIMDE_FLOAT16_VALUE(45.79), SIMDE_FLOAT16_VALUE(8.17), SIMDE_FLOAT16_VALUE(41.11), SIMDE_FLOAT16_VALUE(24.71) },
       {  SIMDE_FLOAT16_VALUE(-6.19), SIMDE_FLOAT16_VALUE(-19.02), SIMDE_FLOAT16_VALUE(4.14), SIMDE_FLOAT16_VALUE(9.43) } },
       {  SIMDE_FLOAT16_VALUE(-1.12), SIMDE_FLOAT16_VALUE(-28.65), SIMDE_FLOAT16_VALUE(-39.28), SIMDE_FLOAT16_VALUE(-49.01)},
     { {  SIMDE_FLOAT16_VALUE(-1.12), SIMDE_FLOAT16_VALUE(-23.67), SIMDE_FLOAT16_VALUE(44.71), SIMDE_FLOAT16_VALUE(-48.89) },
       {  SIMDE_FLOAT16_VALUE(-28.65), SIMDE_FLOAT16_VALUE(-4.26), SIMDE_FLOAT16_VALUE(-33.58), SIMDE_FLOAT16_VALUE(-23.36) },
       {  SIMDE_FLOAT16_VALUE(-39.28), SIMDE_FLOAT16_VALUE(8.17), SIMDE_FLOAT16_VALUE(41.11), SIMDE_FLOAT16_VALUE(24.71) },
       {  SIMDE_FLOAT16_VALUE(-49.01), SIMDE_FLOAT16_VALUE(-19.02), SIMDE_FLOAT16_VALUE(4.14), SIMDE_FLOAT16_VALUE(9.43) } } },
   { { {  SIMDE_FLOAT16_VALUE(-14.34), SIMDE_FLOAT16_VALUE(23.49), SIMDE_FLOAT16_VALUE(-10.62), SIMDE_FLOAT16_VALUE(39.64) },
       {  SIMDE_FLOAT16_VALUE(-31.94), SIMDE_FLOAT16_VALUE(-41.05), SIMDE_FLOAT16_VALUE(20.30), SIMDE_FLOAT16_VALUE(-28.08) },
       {  SIMDE_FLOAT16_VALUE(-46.77), SIMDE_FLOAT16_VALUE(-6.97), SIMDE_FLOAT16_VALUE(10.38), SIMDE_FLOAT16_VALUE(12.19) },
       {  SIMDE_FLOAT16_VALUE(41.44), SIMDE_FLOAT16_VALUE(-47.57), SIMDE_FLOAT16_VALUE(-43.76), SIMDE_FLOAT16_VALUE(26.14) } },
       {  SIMDE_FLOAT16_VALUE(-20.20), SIMDE_FLOAT16_VALUE(43.64), SIMDE_FLOAT16_VALUE(11.06), SIMDE_FLOAT16_VALUE(-41.55)},
     { {  SIMDE_FLOAT16_VALUE(-14.34), SIMDE_FLOAT16_VALUE(-20.20), SIMDE_FLOAT16_VALUE(-10.62), SIMDE_FLOAT16_VALUE(39.64) },
       {  SIMDE_FLOAT16_VALUE(-31.94), SIMDE_FLOAT16_VALUE(43.64), SIMDE_FLOAT16_VALUE(20.30), SIMDE_FLOAT16_VALUE(-28.08) },
       {  SIMDE_FLOAT16_VALUE(-46.77), SIMDE_FLOAT16_VALUE(11.06), SIMDE_FLOAT16_VALUE(10.38), SIMDE_FLOAT16_VALUE(12.19) },
       {  SIMDE_FLOAT16_VALUE(41.44), SIMDE_FLOAT16_VALUE(-41.55), SIMDE_FLOAT16_VALUE(-43.76), SIMDE_FLOAT16_VALUE(26.14) } } },
   { { {  SIMDE_FLOAT16_VALUE(-49.94), SIMDE_FLOAT16_VALUE(-3.45), SIMDE_FLOAT16_VALUE(-18.16), SIMDE_FLOAT16_VALUE(-35.32) },
       {  SIMDE_FLOAT16_VALUE(-39.02), SIMDE_FLOAT16_VALUE(20.10), SIMDE_FLOAT16_VALUE(9.41), SIMDE_FLOAT16_VALUE(-12.84) },
       {  SIMDE_FLOAT16_VALUE(-20.30), SIMDE_FLOAT16_VALUE(18.38), SIMDE_FLOAT16_VALUE(36.37), SIMDE_FLOAT16_VALUE(-15.62) },
       {  SIMDE_FLOAT16_VALUE(27.10), SIMDE_FLOAT16_VALUE(-38.20), SIMDE_FLOAT16_VALUE(-15.40), SIMDE_FLOAT16_VALUE(-20.21) } },
       {  SIMDE_FLOAT16_VALUE(-9.89), SIMDE_FLOAT16_VALUE(-2.32), SIMDE_FLOAT16_VALUE(-33.75), SIMDE_FLOAT16_VALUE(25.64)},
     { {  SIMDE_FLOAT16_VALUE(-49.94), SIMDE_FLOAT16_VALUE(-3.45), SIMDE_FLOAT16_VALUE(-9.89), SIMDE_FLOAT16_VALUE(-35.32) },
       {  SIMDE_FLOAT16_VALUE(-39.02), SIMDE_FLOAT16_VALUE(20.10), SIMDE_FLOAT16_VALUE(-2.32), SIMDE_FLOAT16_VALUE(-12.84) },
       {  SIMDE_FLOAT16_VALUE(-20.30), SIMDE_FLOAT16_VALUE(18.38), SIMDE_FLOAT16_VALUE(-33.75), SIMDE_FLOAT16_VALUE(-15.62) },
       {  SIMDE_FLOAT16_VALUE(27.10), SIMDE_FLOAT16_VALUE(-38.20), SIMDE_FLOAT16_VALUE(25.64), SIMDE_FLOAT16_VALUE(-20.21) } } },
   { { {  SIMDE_FLOAT16_VALUE(28.09), SIMDE_FLOAT16_VALUE(-29.96), SIMDE_FLOAT16_VALUE(28.29), SIMDE_FLOAT16_VALUE(-15.35) },
       {  SIMDE_FLOAT16_VALUE(15.14), SIMDE_FLOAT16_VALUE(-42.36), SIMDE_FLOAT16_VALUE(-3.50), SIMDE_FLOAT16_VALUE(11.41) },
       {  SIMDE_FLOAT16_VALUE(-2.75), SIMDE_FLOAT16_VALUE(20.25), SIMDE_FLOAT16_VALUE(29.83), SIMDE_FLOAT16_VALUE(45.27) },
       {  SIMDE_FLOAT16_VALUE(22.78), SIMDE_FLOAT16_VALUE(10.89), SIMDE_FLOAT16_VALUE(42.55), SIMDE_FLOAT16_VALUE(-45.91) } },
       {  SIMDE_FLOAT16_VALUE(-8.61), SIMDE_FLOAT16_VALUE(-39.93), SIMDE_FLOAT16_VALUE(-16.44), SIMDE_FLOAT16_VALUE(43.00)},
     { {  SIMDE_FLOAT16_VALUE(28.09), SIMDE_FLOAT16_VALUE(-29.96), SIMDE_FLOAT16_VALUE(28.29), SIMDE_FLOAT16_VALUE(-8.61) },
       {  SIMDE_FLOAT16_VALUE(15.14), SIMDE_FLOAT16_VALUE(-42.36), SIMDE_FLOAT16_VALUE(-3.50), SIMDE_FLOAT16_VALUE(-39.93) },
       {  SIMDE_FLOAT16_VALUE(-2.75), SIMDE_FLOAT16_VALUE(20.25), SIMDE_FLOAT16_VALUE(29.83), SIMDE_FLOAT16_VALUE(-16.44) },
       {  SIMDE_FLOAT16_VALUE(22.78), SIMDE_FLOAT16_VALUE(10.89), SIMDE_FLOAT16_VALUE(42.55), SIMDE_FLOAT16_VALUE(43.00) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4x4_t r;
    simde_float16x4x4_t src = {
        {simde_vld1_f16(test_vec[i].src[0]), simde_vld1_f16(test_vec[i].src[1]),
         simde_vld1_f16(test_vec[i].src[2]), simde_vld1_f16(test_vec[i].src[3])}};
    simde_float16x4x4_t expected = {
        {simde_vld1_f16(test_vec[i].r[0]), simde_vld1_f16(test_vec[i].r[1]),
         simde_vld1_f16(test_vec[i].r[2]), simde_vld1_f16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_4_(simde_vld4_lane_f16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_f16x4(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f16x4(r.val[1], expected.val[1], 1);
    simde_test_arm_neon_assert_equal_f16x4(r.val[2], expected.val[2], 1);
    simde_test_arm_neon_assert_equal_f16x4(r.val[3], expected.val[3], 1);
  }

  return 0;
}

static int
test_simde_vld4_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t src[4][8];
    simde_float32_t buf[4];
    simde_float32_t r[4][8];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(    -4.66), SIMDE_FLOAT32_C(   -18.00) },
          { SIMDE_FLOAT32_C(    54.81), SIMDE_FLOAT32_C(   -21.07) },
          { SIMDE_FLOAT32_C(    94.81), SIMDE_FLOAT32_C(    81.11) },
          { SIMDE_FLOAT32_C(   -83.82), SIMDE_FLOAT32_C(    74.22) } },
      { SIMDE_FLOAT32_C(    33.78), SIMDE_FLOAT32_C(    14.41), SIMDE_FLOAT32_C(    79.56), SIMDE_FLOAT32_C(   -37.96) },
        { { SIMDE_FLOAT32_C(    33.78), SIMDE_FLOAT32_C(   -18.00) },
          { SIMDE_FLOAT32_C(    14.41), SIMDE_FLOAT32_C(   -21.07) },
          { SIMDE_FLOAT32_C(    79.56), SIMDE_FLOAT32_C(    81.11) },
          { SIMDE_FLOAT32_C(   -37.96), SIMDE_FLOAT32_C(    74.22) } },
    },
    {
        { { SIMDE_FLOAT32_C(    18.96), SIMDE_FLOAT32_C(   -48.04) },
          { SIMDE_FLOAT32_C(   -15.72), SIMDE_FLOAT32_C(   -52.18) },
          { SIMDE_FLOAT32_C(    73.37), SIMDE_FLOAT32_C(   -29.70) },
          { SIMDE_FLOAT32_C(    40.56), SIMDE_FLOAT32_C(   -24.15) } },
      { SIMDE_FLOAT32_C(   -10.02), SIMDE_FLOAT32_C(    72.45), SIMDE_FLOAT32_C(    50.76), SIMDE_FLOAT32_C(   -87.18) },
        { { SIMDE_FLOAT32_C(    18.96), SIMDE_FLOAT32_C(   -10.02) },
          { SIMDE_FLOAT32_C(   -15.72), SIMDE_FLOAT32_C(    72.45) },
          { SIMDE_FLOAT32_C(    73.37), SIMDE_FLOAT32_C(    50.76) },
          { SIMDE_FLOAT32_C(    40.56), SIMDE_FLOAT32_C(   -87.18) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x4_t r;
    simde_float32x2x4_t src = {
        {simde_vld1_f32(test_vec[i].src[0]), simde_vld1_f32(test_vec[i].src[1]),
         simde_vld1_f32(test_vec[i].src[2]), simde_vld1_f32(test_vec[i].src[3])}};
    simde_float32x2x4_t expected = {
        {simde_vld1_f32(test_vec[i].r[0]), simde_vld1_f32(test_vec[i].r[1]),
         simde_vld1_f32(test_vec[i].r[2]), simde_vld1_f32(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_2_(simde_vld4_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], expected.val[1], 1);
    simde_test_arm_neon_assert_equal_f32x2(r.val[2], expected.val[2], 1);
    simde_test_arm_neon_assert_equal_f32x2(r.val[3], expected.val[3], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32x2x4_t src = simde_test_arm_neon_random_f32x2x4(-100.0f, 100.0f);
    simde_test_arm_neon_write_f32x2x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_float32_t buf[4];
    simde_test_codegen_random_vf32(4, buf, -100.0f, 100.0f);
    simde_test_codegen_write_vf32(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float32x2x4_t r;
    SIMDE_CONSTIFY_2_(simde_vld4_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_f32x2x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t src[4][8];
    simde_float64_t buf[4];
    simde_float64_t r[4][8];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(    62.84) },
          { SIMDE_FLOAT64_C(   -97.22) },
          { SIMDE_FLOAT64_C(    17.10) },
          { SIMDE_FLOAT64_C(    83.43) } },
      { SIMDE_FLOAT64_C(    17.28), SIMDE_FLOAT64_C(    -9.03), SIMDE_FLOAT64_C(   -57.78), SIMDE_FLOAT64_C(   -87.37) },
        { { SIMDE_FLOAT64_C(    17.28) },
          { SIMDE_FLOAT64_C(    -9.03) },
          { SIMDE_FLOAT64_C(   -57.78) },
          { SIMDE_FLOAT64_C(   -87.37) } },
    },
    {
        { { SIMDE_FLOAT64_C(    72.97) },
          { SIMDE_FLOAT64_C(    97.03) },
          { SIMDE_FLOAT64_C(    -8.44) },
          { SIMDE_FLOAT64_C(    67.78) } },
      { SIMDE_FLOAT64_C(    78.14), SIMDE_FLOAT64_C(     7.74), SIMDE_FLOAT64_C(    42.00), SIMDE_FLOAT64_C(    11.92) },
        { { SIMDE_FLOAT64_C(    78.14) },
          { SIMDE_FLOAT64_C(     7.74) },
          { SIMDE_FLOAT64_C(    42.00) },
          { SIMDE_FLOAT64_C(    11.92) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x4_t src = {
        {simde_vld1_f64(test_vec[i].src[0]), simde_vld1_f64(test_vec[i].src[1]),
         simde_vld1_f64(test_vec[i].src[2]), simde_vld1_f64(test_vec[i].src[3])}};
    simde_float64x1x4_t r = simde_vld4_lane_f64(test_vec[i].buf, src, 0);

    simde_float64x1x4_t expected = {
        {simde_vld1_f64(test_vec[i].r[0]), simde_vld1_f64(test_vec[i].r[1]),
         simde_vld1_f64(test_vec[i].r[2]), simde_vld1_f64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_f64x1(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f64x1(r.val[1], expected.val[1], 1);
    simde_test_arm_neon_assert_equal_f64x1(r.val[2], expected.val[2], 1);
    simde_test_arm_neon_assert_equal_f64x1(r.val[3], expected.val[3], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64x1x4_t src = simde_test_arm_neon_random_f64x1x4(-100.0, 100.0);
    simde_test_arm_neon_write_f64x1x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_float64_t buf[4];
    simde_test_codegen_random_vf64(4, buf, -100.0, 100.0);
    simde_test_codegen_write_vf64(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float64x1x4_t r = simde_vld4_lane_f64(buf, src, 0);
    simde_test_arm_neon_write_f64x1x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t src[4][16];
    int8_t buf[4];
    int8_t r[4][16];
  } test_vec[] = {
    {
        { {  INT8_C(  34),  INT8_C(  46), -INT8_C(  43), -INT8_C(  75), -INT8_C(  44), -INT8_C( 111), -INT8_C( 121),  INT8_C(  12),
             INT8_C(  83), -INT8_C(  65), -INT8_C(  93), -INT8_C(  97),  INT8_C(  53), -INT8_C( 107), -INT8_C( 126), -INT8_C(   2) },
          {  INT8_C(  95),  INT8_C(  81), -INT8_C(  56),  INT8_C(  69),  INT8_C(  17),  INT8_C(  57),  INT8_C(  22), -INT8_C(  45),
            -INT8_C( 104), -INT8_C( 118),  INT8_C(  72), -INT8_C(  88),  INT8_C(  70),  INT8_C(  27), -INT8_C( 108),  INT8_C( 104) },
          {  INT8_C(  73),  INT8_C( 105),  INT8_C(  29),  INT8_C(  29), -INT8_C(   6), -INT8_C(  92),  INT8_C(  41),  INT8_C(  77),
             INT8_C(  99), -INT8_C(  52), -INT8_C(  19), -INT8_C( 103),  INT8_C(  97),  INT8_C( 111), -INT8_C( 105), -INT8_C(  63) },
          { -INT8_C(  64),  INT8_C(  96),  INT8_C(   6), -INT8_C(  47), -INT8_C( 103),  INT8_C(  28), -INT8_C(  92),  INT8_C(  49),
            -INT8_C(  89), -INT8_C(  20), -INT8_C(  38), -INT8_C(  19),  INT8_C(   7),  INT8_C( 110),  INT8_C(  86),  INT8_C(  80) } },
      { -INT8_C(  41),  INT8_C( 115),  INT8_C( 110), -INT8_C(  47) },
        { { -INT8_C(  41),  INT8_C(  46), -INT8_C(  43), -INT8_C(  75), -INT8_C(  44), -INT8_C( 111), -INT8_C( 121),  INT8_C(  12),
             INT8_C(  83), -INT8_C(  65), -INT8_C(  93), -INT8_C(  97),  INT8_C(  53), -INT8_C( 107), -INT8_C( 126), -INT8_C(   2) },
          {  INT8_C( 115),  INT8_C(  81), -INT8_C(  56),  INT8_C(  69),  INT8_C(  17),  INT8_C(  57),  INT8_C(  22), -INT8_C(  45),
            -INT8_C( 104), -INT8_C( 118),  INT8_C(  72), -INT8_C(  88),  INT8_C(  70),  INT8_C(  27), -INT8_C( 108),  INT8_C( 104) },
          {  INT8_C( 110),  INT8_C( 105),  INT8_C(  29),  INT8_C(  29), -INT8_C(   6), -INT8_C(  92),  INT8_C(  41),  INT8_C(  77),
             INT8_C(  99), -INT8_C(  52), -INT8_C(  19), -INT8_C( 103),  INT8_C(  97),  INT8_C( 111), -INT8_C( 105), -INT8_C(  63) },
          { -INT8_C(  47),  INT8_C(  96),  INT8_C(   6), -INT8_C(  47), -INT8_C( 103),  INT8_C(  28), -INT8_C(  92),  INT8_C(  49),
            -INT8_C(  89), -INT8_C(  20), -INT8_C(  38), -INT8_C(  19),  INT8_C(   7),  INT8_C( 110),  INT8_C(  86),  INT8_C(  80) } },
    },
    {
        { {  INT8_C(  24), -INT8_C( 105),  INT8_C(  31),  INT8_C( 123),  INT8_C( 100),  INT8_C(  12),  INT8_C(  20), -INT8_C(  59),
             INT8_C( 123), -INT8_C(  84), -INT8_C( 122),  INT8_C(  59),  INT8_C(  12), -INT8_C( 115),  INT8_C(  12), -INT8_C(  91) },
          { -INT8_C(  87), -INT8_C(  80), -INT8_C(  42),  INT8_C(  80), -INT8_C(  99), -INT8_C(  80),  INT8_C(  62), -INT8_C(  92),
             INT8_C(  30), -INT8_C( 108), -INT8_C(  11), -INT8_C(  11),  INT8_C(   7),  INT8_C(  99), -INT8_C(  57),  INT8_C(  31) },
          { -INT8_C(   6), -INT8_C(  26), -INT8_C( 101),  INT8_C(  94), -INT8_C(  14), -INT8_C(  81),  INT8_C(  36),  INT8_C( 109),
             INT8_C(  91), -INT8_C(  86), -INT8_C(  88),  INT8_C( 103),  INT8_C(  55), -INT8_C(  76),  INT8_C(  12), -INT8_C(  31) },
          {  INT8_C( 100), -INT8_C(  29),  INT8_C(  49),  INT8_C(   1), -INT8_C( 109),  INT8_C( 111), -INT8_C(  90), -INT8_C(  78),
             INT8_C(   3), -INT8_C( 101), -INT8_C(  89),  INT8_C(  11), -INT8_C(   2),  INT8_C( 110),  INT8_C(  42), -INT8_C(   8) } },
      {  INT8_C(  84), -INT8_C(  59),  INT8_C(  87),  INT8_C(  70) },
        { {  INT8_C(  24),  INT8_C(  84),  INT8_C(  31),  INT8_C( 123),  INT8_C( 100),  INT8_C(  12),  INT8_C(  20), -INT8_C(  59),
             INT8_C( 123), -INT8_C(  84), -INT8_C( 122),  INT8_C(  59),  INT8_C(  12), -INT8_C( 115),  INT8_C(  12), -INT8_C(  91) },
          { -INT8_C(  87), -INT8_C(  59), -INT8_C(  42),  INT8_C(  80), -INT8_C(  99), -INT8_C(  80),  INT8_C(  62), -INT8_C(  92),
             INT8_C(  30), -INT8_C( 108), -INT8_C(  11), -INT8_C(  11),  INT8_C(   7),  INT8_C(  99), -INT8_C(  57),  INT8_C(  31) },
          { -INT8_C(   6),  INT8_C(  87), -INT8_C( 101),  INT8_C(  94), -INT8_C(  14), -INT8_C(  81),  INT8_C(  36),  INT8_C( 109),
             INT8_C(  91), -INT8_C(  86), -INT8_C(  88),  INT8_C( 103),  INT8_C(  55), -INT8_C(  76),  INT8_C(  12), -INT8_C(  31) },
          {  INT8_C( 100),  INT8_C(  70),  INT8_C(  49),  INT8_C(   1), -INT8_C( 109),  INT8_C( 111), -INT8_C(  90), -INT8_C(  78),
             INT8_C(   3), -INT8_C( 101), -INT8_C(  89),  INT8_C(  11), -INT8_C(   2),  INT8_C( 110),  INT8_C(  42), -INT8_C(   8) } },
    },
    {
        { {  INT8_C( 117),  INT8_C( 123), -INT8_C(  77), -INT8_C(  48),  INT8_C(  37),  INT8_C(  91),  INT8_C(  56),  INT8_C(  93),
             INT8_C(  15),  INT8_C(  68),  INT8_C(  62),  INT8_C( 116),  INT8_C(  39),  INT8_C( 111),  INT8_C( 117), -INT8_C(  69) },
          { -INT8_C(  33),  INT8_C(  27),  INT8_C( 109), -INT8_C(  30), -INT8_C(  74),  INT8_C(  20), -INT8_C(  19), -INT8_C(  76),
            -INT8_C( 125),  INT8_C(  24), -INT8_C(  83), -INT8_C(  41), -INT8_C(  35),  INT8_C(   4),  INT8_C(  30),  INT8_C(  82) },
          {      INT8_MAX, -INT8_C(  47),  INT8_C(  35), -INT8_C(  92),  INT8_C(  45),  INT8_C(  91),  INT8_C(   1),  INT8_C(  60),
            -INT8_C(  97),  INT8_C(  63), -INT8_C(  80), -INT8_C(  57), -INT8_C(  81),  INT8_C(  38), -INT8_C( 126), -INT8_C( 114) },
          {  INT8_C(  65), -INT8_C(  17),  INT8_C( 112), -INT8_C(   8),  INT8_C(   3),  INT8_C(  94), -INT8_C(  84), -INT8_C( 122),
             INT8_C( 118),  INT8_C(  89),  INT8_C(  94),  INT8_C(  83),  INT8_C(  93),  INT8_C( 124), -INT8_C(  90), -INT8_C(  36) } },
      {  INT8_C(  77), -INT8_C(  55), -INT8_C( 127),  INT8_C( 122) },
        { {  INT8_C( 117),  INT8_C( 123),  INT8_C(  77), -INT8_C(  48),  INT8_C(  37),  INT8_C(  91),  INT8_C(  56),  INT8_C(  93),
             INT8_C(  15),  INT8_C(  68),  INT8_C(  62),  INT8_C( 116),  INT8_C(  39),  INT8_C( 111),  INT8_C( 117), -INT8_C(  69) },
          { -INT8_C(  33),  INT8_C(  27), -INT8_C(  55), -INT8_C(  30), -INT8_C(  74),  INT8_C(  20), -INT8_C(  19), -INT8_C(  76),
            -INT8_C( 125),  INT8_C(  24), -INT8_C(  83), -INT8_C(  41), -INT8_C(  35),  INT8_C(   4),  INT8_C(  30),  INT8_C(  82) },
          {      INT8_MAX, -INT8_C(  47), -INT8_C( 127), -INT8_C(  92),  INT8_C(  45),  INT8_C(  91),  INT8_C(   1),  INT8_C(  60),
            -INT8_C(  97),  INT8_C(  63), -INT8_C(  80), -INT8_C(  57), -INT8_C(  81),  INT8_C(  38), -INT8_C( 126), -INT8_C( 114) },
          {  INT8_C(  65), -INT8_C(  17),  INT8_C( 122), -INT8_C(   8),  INT8_C(   3),  INT8_C(  94), -INT8_C(  84), -INT8_C( 122),
             INT8_C( 118),  INT8_C(  89),  INT8_C(  94),  INT8_C(  83),  INT8_C(  93),  INT8_C( 124), -INT8_C(  90), -INT8_C(  36) } },
    },
    {
        { {  INT8_C(  36), -INT8_C( 126), -INT8_C(  73), -INT8_C(  61), -INT8_C(  62),  INT8_C( 103), -INT8_C( 118),  INT8_C( 113),
            -INT8_C( 115),  INT8_C(  12), -INT8_C(   1), -INT8_C(  49), -INT8_C(   5),  INT8_C( 111), -INT8_C(  57), -INT8_C(   1) },
          { -INT8_C(  51),  INT8_C( 115), -INT8_C( 123),  INT8_C(  67), -INT8_C(  51), -INT8_C(  29), -INT8_C( 105),  INT8_C(  42),
             INT8_C(  95),  INT8_C(  61),  INT8_C(   7), -INT8_C(  83),  INT8_C(   6), -INT8_C( 120),  INT8_C(  39),  INT8_C(  42) },
          {  INT8_C(  10), -INT8_C(  34), -INT8_C(  19), -INT8_C(  52),  INT8_C(  70),  INT8_C( 120),  INT8_C(  61), -INT8_C(  45),
            -INT8_C( 124),  INT8_C(  60), -INT8_C(  94),      INT8_MIN, -INT8_C(  84),  INT8_C( 105),      INT8_MAX,  INT8_C( 121) },
          { -INT8_C(  35),  INT8_C(   4), -INT8_C(  67), -INT8_C(  86), -INT8_C(  24),  INT8_C(  84), -INT8_C(  44),  INT8_C(  71),
            -INT8_C( 111), -INT8_C(  37), -INT8_C(  12), -INT8_C( 105),  INT8_C(  99),  INT8_C(  28), -INT8_C(  63),  INT8_C( 110) } },
      { -INT8_C(   6), -INT8_C(  82),  INT8_C(  58),  INT8_C(  64) },
        { {  INT8_C(  36), -INT8_C( 126), -INT8_C(  73), -INT8_C(   6), -INT8_C(  62),  INT8_C( 103), -INT8_C( 118),  INT8_C( 113),
            -INT8_C( 115),  INT8_C(  12), -INT8_C(   1), -INT8_C(  49), -INT8_C(   5),  INT8_C( 111), -INT8_C(  57), -INT8_C(   1) },
          { -INT8_C(  51),  INT8_C( 115), -INT8_C( 123), -INT8_C(  82), -INT8_C(  51), -INT8_C(  29), -INT8_C( 105),  INT8_C(  42),
             INT8_C(  95),  INT8_C(  61),  INT8_C(   7), -INT8_C(  83),  INT8_C(   6), -INT8_C( 120),  INT8_C(  39),  INT8_C(  42) },
          {  INT8_C(  10), -INT8_C(  34), -INT8_C(  19),  INT8_C(  58),  INT8_C(  70),  INT8_C( 120),  INT8_C(  61), -INT8_C(  45),
            -INT8_C( 124),  INT8_C(  60), -INT8_C(  94),      INT8_MIN, -INT8_C(  84),  INT8_C( 105),      INT8_MAX,  INT8_C( 121) },
          { -INT8_C(  35),  INT8_C(   4), -INT8_C(  67),  INT8_C(  64), -INT8_C(  24),  INT8_C(  84), -INT8_C(  44),  INT8_C(  71),
            -INT8_C( 111), -INT8_C(  37), -INT8_C(  12), -INT8_C( 105),  INT8_C(  99),  INT8_C(  28), -INT8_C(  63),  INT8_C( 110) } },
    },
    {
        { {  INT8_C(  38),  INT8_C( 120),  INT8_C(  20), -INT8_C(  85), -INT8_C(  76), -INT8_C(  74),  INT8_C(  43),  INT8_C(  96),
             INT8_C(  32), -INT8_C(  86), -INT8_C(  38), -INT8_C(   3), -INT8_C(  82), -INT8_C( 105), -INT8_C(  89), -INT8_C( 106) },
          { -INT8_C(  21),  INT8_C( 123), -INT8_C(  34),  INT8_C( 124),  INT8_C(  87), -INT8_C(  46),  INT8_C(  19), -INT8_C(  70),
            -INT8_C(  18), -INT8_C(  44),  INT8_C(  40), -INT8_C(  23), -INT8_C( 126),  INT8_C(  99),  INT8_C(  41), -INT8_C(  87) },
          { -INT8_C(  37),  INT8_C(  61),  INT8_C(  84), -INT8_C( 113), -INT8_C(  12),      INT8_MAX, -INT8_C(  16),  INT8_C(  20),
             INT8_C(  41), -INT8_C(  54),  INT8_C(  17), -INT8_C(  41),  INT8_C(  97), -INT8_C(  72),  INT8_C( 110),  INT8_C(  76) },
          {  INT8_C(  51),  INT8_C(  76), -INT8_C(  56), -INT8_C( 118),  INT8_C(  30), -INT8_C(  37),  INT8_C(  69),  INT8_C(  13),
            -INT8_C(  81),  INT8_C( 109), -INT8_C(  10),  INT8_C(  49), -INT8_C(  48),  INT8_C(  31), -INT8_C(  38), -INT8_C(  85) } },
      {  INT8_C(  93),  INT8_C(  46),  INT8_C(  59),  INT8_C(  81) },
        { {  INT8_C(  38),  INT8_C( 120),  INT8_C(  20), -INT8_C(  85),  INT8_C(  93), -INT8_C(  74),  INT8_C(  43),  INT8_C(  96),
             INT8_C(  32), -INT8_C(  86), -INT8_C(  38), -INT8_C(   3), -INT8_C(  82), -INT8_C( 105), -INT8_C(  89), -INT8_C( 106) },
          { -INT8_C(  21),  INT8_C( 123), -INT8_C(  34),  INT8_C( 124),  INT8_C(  46), -INT8_C(  46),  INT8_C(  19), -INT8_C(  70),
            -INT8_C(  18), -INT8_C(  44),  INT8_C(  40), -INT8_C(  23), -INT8_C( 126),  INT8_C(  99),  INT8_C(  41), -INT8_C(  87) },
          { -INT8_C(  37),  INT8_C(  61),  INT8_C(  84), -INT8_C( 113),  INT8_C(  59),      INT8_MAX, -INT8_C(  16),  INT8_C(  20),
             INT8_C(  41), -INT8_C(  54),  INT8_C(  17), -INT8_C(  41),  INT8_C(  97), -INT8_C(  72),  INT8_C( 110),  INT8_C(  76) },
          {  INT8_C(  51),  INT8_C(  76), -INT8_C(  56), -INT8_C( 118),  INT8_C(  81), -INT8_C(  37),  INT8_C(  69),  INT8_C(  13),
            -INT8_C(  81),  INT8_C( 109), -INT8_C(  10),  INT8_C(  49), -INT8_C(  48),  INT8_C(  31), -INT8_C(  38), -INT8_C(  85) } },
    },
    {
        { { -INT8_C(  83),  INT8_C(  43),  INT8_C( 101), -INT8_C(  42), -INT8_C(  11),  INT8_C( 118), -INT8_C(  82),  INT8_C(  86),
             INT8_C(  46),  INT8_C(  28), -INT8_C(  94),  INT8_C(  97),  INT8_C( 104),  INT8_C( 106), -INT8_C(  20), -INT8_C( 122) },
          {  INT8_C(  69),  INT8_C(  49), -INT8_C( 109), -INT8_C(  12), -INT8_C(  98), -INT8_C( 119),  INT8_C(  37),  INT8_C( 111),
            -INT8_C(  87),  INT8_C(   0),  INT8_C(  26),  INT8_C(   6),  INT8_C(  46),  INT8_C(  85),  INT8_C(  87), -INT8_C(  36) },
          {      INT8_MIN, -INT8_C(  68), -INT8_C(  78),  INT8_C( 117),  INT8_C(  50),  INT8_C(  96), -INT8_C(  53),  INT8_C(  96),
             INT8_C( 124),  INT8_C( 109), -INT8_C(  63), -INT8_C(  28), -INT8_C(  41), -INT8_C(  83),  INT8_C( 107),  INT8_C(  28) },
          { -INT8_C(  34), -INT8_C(   2),  INT8_C(  16),  INT8_C( 125), -INT8_C( 120),  INT8_C(  54), -INT8_C(  20),  INT8_C(  49),
             INT8_C(  54),  INT8_C(   6),  INT8_C(  55),  INT8_C( 100),  INT8_C(  92), -INT8_C( 114),  INT8_C(  64), -INT8_C(  36) } },
      {  INT8_C(  74), -INT8_C(  13),  INT8_C(  82),  INT8_C( 124) },
        { { -INT8_C(  83),  INT8_C(  43),  INT8_C( 101), -INT8_C(  42), -INT8_C(  11),  INT8_C(  74), -INT8_C(  82),  INT8_C(  86),
             INT8_C(  46),  INT8_C(  28), -INT8_C(  94),  INT8_C(  97),  INT8_C( 104),  INT8_C( 106), -INT8_C(  20), -INT8_C( 122) },
          {  INT8_C(  69),  INT8_C(  49), -INT8_C( 109), -INT8_C(  12), -INT8_C(  98), -INT8_C(  13),  INT8_C(  37),  INT8_C( 111),
            -INT8_C(  87),  INT8_C(   0),  INT8_C(  26),  INT8_C(   6),  INT8_C(  46),  INT8_C(  85),  INT8_C(  87), -INT8_C(  36) },
          {      INT8_MIN, -INT8_C(  68), -INT8_C(  78),  INT8_C( 117),  INT8_C(  50),  INT8_C(  82), -INT8_C(  53),  INT8_C(  96),
             INT8_C( 124),  INT8_C( 109), -INT8_C(  63), -INT8_C(  28), -INT8_C(  41), -INT8_C(  83),  INT8_C( 107),  INT8_C(  28) },
          { -INT8_C(  34), -INT8_C(   2),  INT8_C(  16),  INT8_C( 125), -INT8_C( 120),  INT8_C( 124), -INT8_C(  20),  INT8_C(  49),
             INT8_C(  54),  INT8_C(   6),  INT8_C(  55),  INT8_C( 100),  INT8_C(  92), -INT8_C( 114),  INT8_C(  64), -INT8_C(  36) } },
    },
    {
        { {  INT8_C(  83),  INT8_C(  29), -INT8_C(  36), -INT8_C(  48), -INT8_C( 117), -INT8_C(  99), -INT8_C(  76),  INT8_C(  98),
             INT8_C(  75),  INT8_C(  31),      INT8_MAX,  INT8_C(  41),  INT8_C(  30), -INT8_C( 113), -INT8_C(  90), -INT8_C(  90) },
          { -INT8_C(  59), -INT8_C( 110), -INT8_C(  41), -INT8_C(   5), -INT8_C( 103),  INT8_C(  14),  INT8_C(  96), -INT8_C(  11),
            -INT8_C( 100), -INT8_C(  96), -INT8_C(  47), -INT8_C(  26), -INT8_C( 109),  INT8_C(  35),  INT8_C(  98), -INT8_C(  25) },
          {  INT8_C(  65),  INT8_C(  62), -INT8_C(  73), -INT8_C(  52), -INT8_C(  37),  INT8_C( 107),  INT8_C(  46),  INT8_C(  38),
            -INT8_C( 117), -INT8_C(  83),  INT8_C(  80), -INT8_C(  87),  INT8_C(  61), -INT8_C(  10),  INT8_C(  79),  INT8_C(   2) },
          { -INT8_C( 119),  INT8_C(  38), -INT8_C(   2),  INT8_C(  34),  INT8_C(  52),  INT8_C(  94),  INT8_C(  23), -INT8_C(  48),
            -INT8_C(   2), -INT8_C(  24), -INT8_C(  74), -INT8_C( 110),  INT8_C(  12),  INT8_C(  24),  INT8_C( 121),  INT8_C(  77) } },
      {  INT8_C(  86),  INT8_C(  48),  INT8_C(  25),  INT8_C(  49) },
        { {  INT8_C(  83),  INT8_C(  29), -INT8_C(  36), -INT8_C(  48), -INT8_C( 117), -INT8_C(  99),  INT8_C(  86),  INT8_C(  98),
             INT8_C(  75),  INT8_C(  31),      INT8_MAX,  INT8_C(  41),  INT8_C(  30), -INT8_C( 113), -INT8_C(  90), -INT8_C(  90) },
          { -INT8_C(  59), -INT8_C( 110), -INT8_C(  41), -INT8_C(   5), -INT8_C( 103),  INT8_C(  14),  INT8_C(  48), -INT8_C(  11),
            -INT8_C( 100), -INT8_C(  96), -INT8_C(  47), -INT8_C(  26), -INT8_C( 109),  INT8_C(  35),  INT8_C(  98), -INT8_C(  25) },
          {  INT8_C(  65),  INT8_C(  62), -INT8_C(  73), -INT8_C(  52), -INT8_C(  37),  INT8_C( 107),  INT8_C(  25),  INT8_C(  38),
            -INT8_C( 117), -INT8_C(  83),  INT8_C(  80), -INT8_C(  87),  INT8_C(  61), -INT8_C(  10),  INT8_C(  79),  INT8_C(   2) },
          { -INT8_C( 119),  INT8_C(  38), -INT8_C(   2),  INT8_C(  34),  INT8_C(  52),  INT8_C(  94),  INT8_C(  49), -INT8_C(  48),
            -INT8_C(   2), -INT8_C(  24), -INT8_C(  74), -INT8_C( 110),  INT8_C(  12),  INT8_C(  24),  INT8_C( 121),  INT8_C(  77) } },
    },
    {
        { { -INT8_C( 101),  INT8_C(  71),  INT8_C(  88),  INT8_C(  38), -INT8_C(  11), -INT8_C(  88), -INT8_C(  49),  INT8_C(  50),
            -INT8_C(  98),  INT8_C(  30),  INT8_C(  52),  INT8_C(  39),  INT8_C(  68),  INT8_C(  50),  INT8_C(  73),  INT8_C( 120) },
          { -INT8_C( 112),  INT8_C(  96),  INT8_C(  72), -INT8_C( 113),  INT8_C(  73), -INT8_C(   2),  INT8_C(  33),  INT8_C(  85),
             INT8_C(  22), -INT8_C( 102), -INT8_C(  94),  INT8_C( 108), -INT8_C(  54), -INT8_C(  69), -INT8_C(  98),  INT8_C( 101) },
          {  INT8_C(   2), -INT8_C(  10), -INT8_C( 116), -INT8_C(   9), -INT8_C(  98),  INT8_C(  91),  INT8_C(  41),  INT8_C(  60),
             INT8_C( 122),  INT8_C(  94),  INT8_C( 100), -INT8_C(  66), -INT8_C( 112), -INT8_C(  83),  INT8_C(  55),  INT8_C(  33) },
          {  INT8_C(  14),      INT8_MAX, -INT8_C(  80),  INT8_C(  87),  INT8_C( 126), -INT8_C(  47), -INT8_C(  84), -INT8_C( 108),
             INT8_C( 107),  INT8_C(  78),  INT8_C(   1),  INT8_C(  53),  INT8_C(   9), -INT8_C(  97), -INT8_C( 102),  INT8_C(  11) } },
      { -INT8_C( 107),  INT8_C(  38),  INT8_C(   3),  INT8_C(  51) },
        { { -INT8_C( 101),  INT8_C(  71),  INT8_C(  88),  INT8_C(  38), -INT8_C(  11), -INT8_C(  88), -INT8_C(  49), -INT8_C( 107),
            -INT8_C(  98),  INT8_C(  30),  INT8_C(  52),  INT8_C(  39),  INT8_C(  68),  INT8_C(  50),  INT8_C(  73),  INT8_C( 120) },
          { -INT8_C( 112),  INT8_C(  96),  INT8_C(  72), -INT8_C( 113),  INT8_C(  73), -INT8_C(   2),  INT8_C(  33),  INT8_C(  38),
             INT8_C(  22), -INT8_C( 102), -INT8_C(  94),  INT8_C( 108), -INT8_C(  54), -INT8_C(  69), -INT8_C(  98),  INT8_C( 101) },
          {  INT8_C(   2), -INT8_C(  10), -INT8_C( 116), -INT8_C(   9), -INT8_C(  98),  INT8_C(  91),  INT8_C(  41),  INT8_C(   3),
             INT8_C( 122),  INT8_C(  94),  INT8_C( 100), -INT8_C(  66), -INT8_C( 112), -INT8_C(  83),  INT8_C(  55),  INT8_C(  33) },
          {  INT8_C(  14),      INT8_MAX, -INT8_C(  80),  INT8_C(  87),  INT8_C( 126), -INT8_C(  47), -INT8_C(  84),  INT8_C(  51),
             INT8_C( 107),  INT8_C(  78),  INT8_C(   1),  INT8_C(  53),  INT8_C(   9), -INT8_C(  97), -INT8_C( 102),  INT8_C(  11) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x4_t r;
    simde_int8x16x4_t src = {
        {simde_vld1q_s8(test_vec[i].src[0]), simde_vld1q_s8(test_vec[i].src[1]),
         simde_vld1q_s8(test_vec[i].src[2]), simde_vld1q_s8(test_vec[i].src[3])}};
    simde_int8x16x4_t expected = {
        {simde_vld1q_s8(test_vec[i].r[0]), simde_vld1q_s8(test_vec[i].r[1]),
         simde_vld1q_s8(test_vec[i].r[2]), simde_vld1q_s8(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_8_(simde_vld4q_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x4_t src = simde_test_arm_neon_random_i8x16x4();
    simde_test_arm_neon_write_i8x16x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int8_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vi8(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int8x16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vld4q_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_i8x16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t src[4][8];
    int16_t buf[4];
    int16_t r[4][8];
  } test_vec[] = {
    {
        { { -INT16_C( 15691), -INT16_C( 12452),  INT16_C( 17302),  INT16_C( 29639),  INT16_C( 22774), -INT16_C( 21390), -INT16_C( 25435),  INT16_C( 11620) },
          {  INT16_C(  4496), -INT16_C( 29400),  INT16_C( 26862),  INT16_C(  1624),  INT16_C( 29133), -INT16_C(  6847), -INT16_C( 32260), -INT16_C( 20170) },
          { -INT16_C( 28093), -INT16_C(  9856),  INT16_C( 18646), -INT16_C( 13236), -INT16_C( 16736),  INT16_C( 17785), -INT16_C(  8870), -INT16_C(  5518) },
          { -INT16_C( 25874), -INT16_C(  9097), -INT16_C( 12286), -INT16_C( 12318),  INT16_C(  9281),  INT16_C( 15797), -INT16_C(  5211), -INT16_C(  5905) } },
      {  INT16_C( 28542),  INT16_C( 21697), -INT16_C( 24823),  INT16_C(  2970) },
        { {  INT16_C( 28542), -INT16_C( 12452),  INT16_C( 17302),  INT16_C( 29639),  INT16_C( 22774), -INT16_C( 21390), -INT16_C( 25435),  INT16_C( 11620) },
          {  INT16_C( 21697), -INT16_C( 29400),  INT16_C( 26862),  INT16_C(  1624),  INT16_C( 29133), -INT16_C(  6847), -INT16_C( 32260), -INT16_C( 20170) },
          { -INT16_C( 24823), -INT16_C(  9856),  INT16_C( 18646), -INT16_C( 13236), -INT16_C( 16736),  INT16_C( 17785), -INT16_C(  8870), -INT16_C(  5518) },
          {  INT16_C(  2970), -INT16_C(  9097), -INT16_C( 12286), -INT16_C( 12318),  INT16_C(  9281),  INT16_C( 15797), -INT16_C(  5211), -INT16_C(  5905) } },
    },
    {
        { {  INT16_C(  3511),  INT16_C( 22304), -INT16_C( 26164),  INT16_C(  9885),  INT16_C(  3958),  INT16_C( 25617), -INT16_C( 30550), -INT16_C( 21440) },
          {  INT16_C(  9048), -INT16_C( 25988),  INT16_C( 12615), -INT16_C(  4905), -INT16_C( 14820), -INT16_C( 25900), -INT16_C( 27338), -INT16_C(  4626) },
          {  INT16_C(  4002),  INT16_C( 28229), -INT16_C(  7512),  INT16_C(  8085), -INT16_C( 22799), -INT16_C( 25725), -INT16_C( 15314), -INT16_C( 30904) },
          { -INT16_C( 15129),  INT16_C( 11809), -INT16_C(  1803),  INT16_C(  4378), -INT16_C(  4417), -INT16_C(  2644), -INT16_C( 25981),  INT16_C(  9698) } },
      {  INT16_C( 10153),  INT16_C( 21140), -INT16_C( 24823),  INT16_C(  2970) },
        { {  INT16_C(  3511),  INT16_C( 10153), -INT16_C( 26164),  INT16_C(  9885),  INT16_C(  3958),  INT16_C( 25617), -INT16_C( 30550), -INT16_C( 21440) },
          {  INT16_C(  9048),  INT16_C( 21140),  INT16_C( 12615), -INT16_C(  4905), -INT16_C( 14820), -INT16_C( 25900), -INT16_C( 27338), -INT16_C(  4626) },
          {  INT16_C(  4002), -INT16_C( 24823), -INT16_C(  7512),  INT16_C(  8085), -INT16_C( 22799), -INT16_C( 25725), -INT16_C( 15314), -INT16_C( 30904) },
          { -INT16_C( 15129),  INT16_C(  2970), -INT16_C(  1803),  INT16_C(  4378), -INT16_C(  4417), -INT16_C(  2644), -INT16_C( 25981),  INT16_C(  9698) } },
    },
    {
        { {  INT16_C( 10505), -INT16_C(  1167), -INT16_C(  2865), -INT16_C(   618), -INT16_C(  8520), -INT16_C( 24700), -INT16_C( 23134), -INT16_C( 26675) },
          { -INT16_C(  6242),  INT16_C( 23977),  INT16_C( 21973),  INT16_C( 22610),  INT16_C( 13551), -INT16_C( 26242),  INT16_C(  4700),  INT16_C( 26091) },
          {  INT16_C( 23611),  INT16_C(  2656), -INT16_C(  2224),  INT16_C(  2311), -INT16_C( 29483),  INT16_C( 30888),  INT16_C( 30257), -INT16_C( 12529) },
          { -INT16_C( 18339),  INT16_C( 13100),  INT16_C( 32269), -INT16_C(   629),  INT16_C(  2483),  INT16_C(  3990), -INT16_C( 32485),  INT16_C( 22132) } },
      { -INT16_C( 10787),  INT16_C( 11616), -INT16_C( 24823),  INT16_C(  2970) },
        { {  INT16_C( 10505), -INT16_C(  1167), -INT16_C( 10787), -INT16_C(   618), -INT16_C(  8520), -INT16_C( 24700), -INT16_C( 23134), -INT16_C( 26675) },
          { -INT16_C(  6242),  INT16_C( 23977),  INT16_C( 11616),  INT16_C( 22610),  INT16_C( 13551), -INT16_C( 26242),  INT16_C(  4700),  INT16_C( 26091) },
          {  INT16_C( 23611),  INT16_C(  2656), -INT16_C( 24823),  INT16_C(  2311), -INT16_C( 29483),  INT16_C( 30888),  INT16_C( 30257), -INT16_C( 12529) },
          { -INT16_C( 18339),  INT16_C( 13100),  INT16_C(  2970), -INT16_C(   629),  INT16_C(  2483),  INT16_C(  3990), -INT16_C( 32485),  INT16_C( 22132) } },
    },
    {
        { {  INT16_C( 26828), -INT16_C( 24266), -INT16_C(  8204),  INT16_C(  9497),  INT16_C( 10581), -INT16_C( 19723),  INT16_C(  8673), -INT16_C(  4123) },
          {  INT16_C( 29088),  INT16_C( 21484), -INT16_C( 32134), -INT16_C( 27038), -INT16_C( 10749), -INT16_C(  7956),  INT16_C( 19883),  INT16_C( 30477) },
          {  INT16_C( 17589), -INT16_C( 22247),  INT16_C( 12835),  INT16_C( 30926), -INT16_C( 15525),  INT16_C( 15658),  INT16_C(  4325), -INT16_C( 31444) },
          {  INT16_C(  6273), -INT16_C(  1064),  INT16_C( 15002), -INT16_C( 25199),  INT16_C( 32272), -INT16_C( 17283), -INT16_C( 30005), -INT16_C( 32717) } },
      {  INT16_C( 19662), -INT16_C(  3799), -INT16_C( 24823),  INT16_C(  2970) },
        { {  INT16_C( 26828), -INT16_C( 24266), -INT16_C(  8204),  INT16_C( 19662),  INT16_C( 10581), -INT16_C( 19723),  INT16_C(  8673), -INT16_C(  4123) },
          {  INT16_C( 29088),  INT16_C( 21484), -INT16_C( 32134), -INT16_C(  3799), -INT16_C( 10749), -INT16_C(  7956),  INT16_C( 19883),  INT16_C( 30477) },
          {  INT16_C( 17589), -INT16_C( 22247),  INT16_C( 12835), -INT16_C( 24823), -INT16_C( 15525),  INT16_C( 15658),  INT16_C(  4325), -INT16_C( 31444) },
          {  INT16_C(  6273), -INT16_C(  1064),  INT16_C( 15002),  INT16_C(  2970),  INT16_C( 32272), -INT16_C( 17283), -INT16_C( 30005), -INT16_C( 32717) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x4_t r;
    simde_int16x8x4_t src = {
        {simde_vld1q_s16(test_vec[i].src[0]), simde_vld1q_s16(test_vec[i].src[1]),
         simde_vld1q_s16(test_vec[i].src[2]), simde_vld1q_s16(test_vec[i].src[3])}};
    simde_int16x8x4_t expected = {
        {simde_vld1q_s16(test_vec[i].r[0]), simde_vld1q_s16(test_vec[i].r[1]),
         simde_vld1q_s16(test_vec[i].r[2]), simde_vld1q_s16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_4_(simde_vld4q_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_int16x8x4_t src = simde_test_arm_neon_random_i16x8x4();
    simde_test_arm_neon_write_i16x8x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int16_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vi16(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int16x8x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld4q_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_i16x8x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t src[4][8];
    int32_t buf[4];
    int32_t r[4][8];
  } test_vec[] = {
    {
        { { -INT32_C(  1996279874),  INT32_C(  1240898987), -INT32_C(   590337144),  INT32_C(  1989965766) },
          {  INT32_C(  1598264903),  INT32_C(   475947013), -INT32_C(  1533578857),  INT32_C(   116830792) },
          { -INT32_C(  1919878430),  INT32_C(   534152855),  INT32_C(  2012980913),  INT32_C(  1710135325) },
          {  INT32_C(   868495662),  INT32_C(   693052049), -INT32_C(   590485868),  INT32_C(  2061681560) } },
      {  INT32_C(  1426551485),  INT32_C(   194656922), -INT32_C(  1132626416), -INT32_C(  2144105781) },
        { {  INT32_C(  1426551485),  INT32_C(  1240898987), -INT32_C(   590337144),  INT32_C(  1989965766) },
          {  INT32_C(   194656922),  INT32_C(   475947013), -INT32_C(  1533578857),  INT32_C(   116830792) },
          { -INT32_C(  1132626416),  INT32_C(   534152855),  INT32_C(  2012980913),  INT32_C(  1710135325) },
          { -INT32_C(  2144105781),  INT32_C(   693052049), -INT32_C(   590485868),  INT32_C(  2061681560) } },
    },
    {
        { { -INT32_C(  1451958536), -INT32_C(  1574866812),  INT32_C(   906432264), -INT32_C(   781595840) },
          { -INT32_C(  2114275091),  INT32_C(   912115614),  INT32_C(  1219575947), -INT32_C(  1415726926) },
          {  INT32_C(   458494614), -INT32_C(  1967295102), -INT32_C(   993999740),  INT32_C(  2090215823) },
          {  INT32_C(  2147389665), -INT32_C(   474653864),  INT32_C(  1311467163), -INT32_C(  1241921249) } },
      {  INT32_C(  1573932507),  INT32_C(   194656922), -INT32_C(  1132626416), -INT32_C(  2144105781) },
        { { -INT32_C(  1451958536),  INT32_C(  1573932507),  INT32_C(   906432264), -INT32_C(   781595840) },
          { -INT32_C(  2114275091),  INT32_C(   194656922),  INT32_C(  1219575947), -INT32_C(  1415726926) },
          {  INT32_C(   458494614), -INT32_C(  1132626416), -INT32_C(   993999740),  INT32_C(  2090215823) },
          {  INT32_C(  2147389665), -INT32_C(  2144105781),  INT32_C(  1311467163), -INT32_C(  1241921249) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x4_t r;
    simde_int32x4x4_t src = {
        {simde_vld1q_s32(test_vec[i].src[0]), simde_vld1q_s32(test_vec[i].src[1]),
         simde_vld1q_s32(test_vec[i].src[2]), simde_vld1q_s32(test_vec[i].src[3])}};
    simde_int32x4x4_t expected = {
        {simde_vld1q_s32(test_vec[i].r[0]), simde_vld1q_s32(test_vec[i].r[1]),
         simde_vld1q_s32(test_vec[i].r[2]), simde_vld1q_s32(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_2_(simde_vld4q_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_i32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_int32x4x4_t src = simde_test_arm_neon_random_i32x4x4();
    simde_test_arm_neon_write_i32x4x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int32_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vi32(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int32x4x4_t r;
    SIMDE_CONSTIFY_2_(simde_vld4q_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_i32x4x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t src[4][8];
    int64_t buf[4];
    int64_t r[4][8];
  } test_vec[] = {
    {
        { {  INT64_C( 1201193502836202517), -INT64_C( 7076678200476845845) },
          { -INT64_C(  449206202697917849), -INT64_C( 2746241653780591351) },
          {  INT64_C( 6750877642029069183), -INT64_C( 9155309959305198680) },
          {  INT64_C( 6771432880358963880), -INT64_C( 2278715439448260925) } },
      { -INT64_C( 4864593411992148909),  INT64_C( 8977408604667692164), -INT64_C( 9208864206412148511), -INT64_C( 5334011147351005541) },
        { { -INT64_C( 4864593411992148909), -INT64_C( 7076678200476845845) },
          {  INT64_C( 8977408604667692164), -INT64_C( 2746241653780591351) },
          { -INT64_C( 9208864206412148511), -INT64_C( 9155309959305198680) },
          { -INT64_C( 5334011147351005541), -INT64_C( 2278715439448260925) } },
    },
    {
        { { -INT64_C( 3778757915873955948),  INT64_C( 1052574282184163573) },
          { -INT64_C(  882731287248661644),  INT64_C( 6368183076506574664) },
          { -INT64_C( 6989265932735183997),  INT64_C( 4570547564838669732) },
          {  INT64_C(  716414022537697643), -INT64_C( 7173948225573567147) } },
      { -INT64_C( 4864593414453066360),  INT64_C( 8977408604667692164), -INT64_C( 9208864206412148511), -INT64_C( 5334011147351005541) },
        { { -INT64_C( 4864593414453066360),  INT64_C( 1052574282184163573) },
          {  INT64_C( 8977408604667692164),  INT64_C( 6368183076506574664) },
          { -INT64_C( 9208864206412148511),  INT64_C( 4570547564838669732) },
          { -INT64_C( 5334011147351005541), -INT64_C( 7173948225573567147) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x4_t src = {
        {simde_vld1q_s64(test_vec[i].src[0]), simde_vld1q_s64(test_vec[i].src[1]),
         simde_vld1q_s64(test_vec[i].src[2]), simde_vld1q_s64(test_vec[i].src[3])}};
    simde_int64x2x4_t r = simde_vld4q_lane_s64(test_vec[i].buf, src, 0);

    simde_int64x2x4_t expected = {
        {simde_vld1q_s64(test_vec[i].r[0]), simde_vld1q_s64(test_vec[i].r[1]),
         simde_vld1q_s64(test_vec[i].r[2]), simde_vld1q_s64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_int64x2x4_t src = simde_test_arm_neon_random_i64x2x4();
    simde_test_arm_neon_write_i64x2x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int64_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vi64(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int64x2x4_t r = simde_vld4q_lane_s64(buf, src, 0);
    simde_test_arm_neon_write_i64x2x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t src[4][16];
    uint8_t buf[4];
    uint8_t r[4][16];
  } test_vec[] = {
    {
        { { UINT8_C(159), UINT8_C(159), UINT8_C( 51), UINT8_C(154), UINT8_C( 93), UINT8_C(239), UINT8_C(101), UINT8_C( 91),
            UINT8_C(160), UINT8_C(136), UINT8_C( 62), UINT8_C(197), UINT8_C( 36), UINT8_C( 72), UINT8_C( 13), UINT8_C(190) },
          { UINT8_C(123), UINT8_C( 44), UINT8_C( 67), UINT8_C(130), UINT8_C(173), UINT8_C(  2), UINT8_C(187), UINT8_C(  5),
            UINT8_C(248), UINT8_C( 87), UINT8_C(155), UINT8_C(221), UINT8_C( 89), UINT8_C(145), UINT8_C(  0), UINT8_C(248) },
          { UINT8_C( 48), UINT8_C( 51), UINT8_C(146), UINT8_C(141), UINT8_C( 35), UINT8_C(248), UINT8_C(233), UINT8_C(195),
            UINT8_C(128), UINT8_C( 39), UINT8_C(137), UINT8_C(164), UINT8_C(112), UINT8_C(150), UINT8_C( 99), UINT8_C(235) },
          { UINT8_C(194), UINT8_C(166), UINT8_C(109), UINT8_C(111), UINT8_C(168), UINT8_C( 40), UINT8_C(116), UINT8_C(161),
            UINT8_C(128), UINT8_C( 16), UINT8_C(126), UINT8_C(217), UINT8_C(161), UINT8_C(127), UINT8_C(209), UINT8_C(209) } },
      { UINT8_C(178), UINT8_C(100), UINT8_C( 94), UINT8_C(213) },
        { { UINT8_C(178), UINT8_C(159), UINT8_C( 51), UINT8_C(154), UINT8_C( 93), UINT8_C(239), UINT8_C(101), UINT8_C( 91),
            UINT8_C(160), UINT8_C(136), UINT8_C( 62), UINT8_C(197), UINT8_C( 36), UINT8_C( 72), UINT8_C( 13), UINT8_C(190) },
          { UINT8_C(100), UINT8_C( 44), UINT8_C( 67), UINT8_C(130), UINT8_C(173), UINT8_C(  2), UINT8_C(187), UINT8_C(  5),
            UINT8_C(248), UINT8_C( 87), UINT8_C(155), UINT8_C(221), UINT8_C( 89), UINT8_C(145), UINT8_C(  0), UINT8_C(248) },
          { UINT8_C( 94), UINT8_C( 51), UINT8_C(146), UINT8_C(141), UINT8_C( 35), UINT8_C(248), UINT8_C(233), UINT8_C(195),
            UINT8_C(128), UINT8_C( 39), UINT8_C(137), UINT8_C(164), UINT8_C(112), UINT8_C(150), UINT8_C( 99), UINT8_C(235) },
          { UINT8_C(213), UINT8_C(166), UINT8_C(109), UINT8_C(111), UINT8_C(168), UINT8_C( 40), UINT8_C(116), UINT8_C(161),
            UINT8_C(128), UINT8_C( 16), UINT8_C(126), UINT8_C(217), UINT8_C(161), UINT8_C(127), UINT8_C(209), UINT8_C(209) } },
    },
    {
        { { UINT8_C( 92), UINT8_C( 71), UINT8_C(153), UINT8_C(220), UINT8_C(111), UINT8_C( 34), UINT8_C(128), UINT8_C(223),
            UINT8_C(184), UINT8_C(227), UINT8_C(202), UINT8_C(122), UINT8_C(138), UINT8_C( 56), UINT8_C(233), UINT8_C( 50) },
          { UINT8_C( 96), UINT8_C( 94), UINT8_C(211), UINT8_C(224), UINT8_C(110), UINT8_C( 82), UINT8_C(185), UINT8_C( 15),
            UINT8_C(209), UINT8_C(139), UINT8_C(224), UINT8_C(131), UINT8_C(239), UINT8_C( 62), UINT8_C( 89), UINT8_C( 75) },
          { UINT8_C(134), UINT8_C(242), UINT8_C( 39), UINT8_C(245), UINT8_C( 20), UINT8_C(167), UINT8_C(212), UINT8_C(204),
            UINT8_C(139), UINT8_C(158), UINT8_C( 70), UINT8_C( 21), UINT8_C(214), UINT8_C( 47), UINT8_C( 71), UINT8_C( 55) },
          { UINT8_C(141), UINT8_C( 27), UINT8_C( 23), UINT8_C(251), UINT8_C(109), UINT8_C(209), UINT8_C( 10), UINT8_C( 62),
            UINT8_C( 92), UINT8_C(234), UINT8_C(193), UINT8_C( 75), UINT8_C( 41), UINT8_C( 26), UINT8_C(150), UINT8_C(175) } },
      { UINT8_C( 12), UINT8_C(189), UINT8_C(164), UINT8_C( 32) },
        { { UINT8_C( 92), UINT8_C( 12), UINT8_C(153), UINT8_C(220), UINT8_C(111), UINT8_C( 34), UINT8_C(128), UINT8_C(223),
            UINT8_C(184), UINT8_C(227), UINT8_C(202), UINT8_C(122), UINT8_C(138), UINT8_C( 56), UINT8_C(233), UINT8_C( 50) },
          { UINT8_C( 96), UINT8_C(189), UINT8_C(211), UINT8_C(224), UINT8_C(110), UINT8_C( 82), UINT8_C(185), UINT8_C( 15),
            UINT8_C(209), UINT8_C(139), UINT8_C(224), UINT8_C(131), UINT8_C(239), UINT8_C( 62), UINT8_C( 89), UINT8_C( 75) },
          { UINT8_C(134), UINT8_C(164), UINT8_C( 39), UINT8_C(245), UINT8_C( 20), UINT8_C(167), UINT8_C(212), UINT8_C(204),
            UINT8_C(139), UINT8_C(158), UINT8_C( 70), UINT8_C( 21), UINT8_C(214), UINT8_C( 47), UINT8_C( 71), UINT8_C( 55) },
          { UINT8_C(141), UINT8_C( 32), UINT8_C( 23), UINT8_C(251), UINT8_C(109), UINT8_C(209), UINT8_C( 10), UINT8_C( 62),
            UINT8_C( 92), UINT8_C(234), UINT8_C(193), UINT8_C( 75), UINT8_C( 41), UINT8_C( 26), UINT8_C(150), UINT8_C(175) } },
    },
    {
        { { UINT8_C(100), UINT8_C(120), UINT8_C(236), UINT8_C(239), UINT8_C( 22), UINT8_C( 50), UINT8_C(  4), UINT8_C(237),
            UINT8_C( 98), UINT8_C( 76), UINT8_C( 36), UINT8_C(239), UINT8_C(103), UINT8_C( 59), UINT8_C(235), UINT8_C(212) },
          { UINT8_C( 12), UINT8_C(245), UINT8_C( 18), UINT8_C(104), UINT8_C(224), UINT8_C(211), UINT8_C(179), UINT8_C(  9),
            UINT8_C(238), UINT8_C( 73), UINT8_C(184), UINT8_C(250), UINT8_C(  6), UINT8_C( 92), UINT8_C( 27), UINT8_C(107) },
          { UINT8_C(212), UINT8_C(  7), UINT8_C( 90), UINT8_C(234), UINT8_C( 58), UINT8_C( 95), UINT8_C(215), UINT8_C(156),
            UINT8_C(171), UINT8_C(251), UINT8_C(139), UINT8_C( 18), UINT8_C( 55), UINT8_C(118), UINT8_C(230), UINT8_C( 67) },
          { UINT8_C(108), UINT8_C(248), UINT8_C(172), UINT8_C( 76), UINT8_C(203), UINT8_C( 95), UINT8_C( 85), UINT8_C(185),
            UINT8_C(169), UINT8_C( 13), UINT8_C(180), UINT8_C(175), UINT8_C(105), UINT8_C(207), UINT8_C( 26), UINT8_C( 61) } },
      { UINT8_C(214), UINT8_C(117), UINT8_C( 39), UINT8_C( 16) },
        { { UINT8_C(100), UINT8_C(120), UINT8_C(214), UINT8_C(239), UINT8_C( 22), UINT8_C( 50), UINT8_C(  4), UINT8_C(237),
            UINT8_C( 98), UINT8_C( 76), UINT8_C( 36), UINT8_C(239), UINT8_C(103), UINT8_C( 59), UINT8_C(235), UINT8_C(212) },
          { UINT8_C( 12), UINT8_C(245), UINT8_C(117), UINT8_C(104), UINT8_C(224), UINT8_C(211), UINT8_C(179), UINT8_C(  9),
            UINT8_C(238), UINT8_C( 73), UINT8_C(184), UINT8_C(250), UINT8_C(  6), UINT8_C( 92), UINT8_C( 27), UINT8_C(107) },
          { UINT8_C(212), UINT8_C(  7), UINT8_C( 39), UINT8_C(234), UINT8_C( 58), UINT8_C( 95), UINT8_C(215), UINT8_C(156),
            UINT8_C(171), UINT8_C(251), UINT8_C(139), UINT8_C( 18), UINT8_C( 55), UINT8_C(118), UINT8_C(230), UINT8_C( 67) },
          { UINT8_C(108), UINT8_C(248), UINT8_C( 16), UINT8_C( 76), UINT8_C(203), UINT8_C( 95), UINT8_C( 85), UINT8_C(185),
            UINT8_C(169), UINT8_C( 13), UINT8_C(180), UINT8_C(175), UINT8_C(105), UINT8_C(207), UINT8_C( 26), UINT8_C( 61) } },
    },
    {
        { { UINT8_C(212),    UINT8_MAX, UINT8_C(172), UINT8_C(127), UINT8_C(250), UINT8_C( 56), UINT8_C(145), UINT8_C( 49),
            UINT8_C(174), UINT8_C(119), UINT8_C(117), UINT8_C( 26), UINT8_C(111), UINT8_C( 33), UINT8_C(102), UINT8_C( 58) },
          { UINT8_C(128), UINT8_C(187), UINT8_C(244), UINT8_C( 41), UINT8_C(200), UINT8_C(168), UINT8_C(217), UINT8_C( 49),
            UINT8_C(119), UINT8_C(243), UINT8_C(110), UINT8_C( 77), UINT8_C(104), UINT8_C(150), UINT8_C( 94), UINT8_C( 60) },
          { UINT8_C(149), UINT8_C( 10), UINT8_C(187), UINT8_C(143), UINT8_C( 66), UINT8_C( 76), UINT8_C(193), UINT8_C(241),
            UINT8_C(195), UINT8_C( 54), UINT8_C( 11), UINT8_C( 50), UINT8_C( 87), UINT8_C(114), UINT8_C(109), UINT8_C(215) },
          { UINT8_C( 45), UINT8_C( 97), UINT8_C(  1), UINT8_C(246), UINT8_C(  9), UINT8_C(218), UINT8_C( 39), UINT8_C(128),
            UINT8_C(205), UINT8_C(150), UINT8_C(205), UINT8_C( 54), UINT8_C( 44), UINT8_C( 43), UINT8_C(114), UINT8_C(193) } },
      { UINT8_C( 54), UINT8_C( 46), UINT8_C( 80), UINT8_C(120) },
        { { UINT8_C(212),    UINT8_MAX, UINT8_C(172), UINT8_C( 54), UINT8_C(250), UINT8_C( 56), UINT8_C(145), UINT8_C( 49),
            UINT8_C(174), UINT8_C(119), UINT8_C(117), UINT8_C( 26), UINT8_C(111), UINT8_C( 33), UINT8_C(102), UINT8_C( 58) },
          { UINT8_C(128), UINT8_C(187), UINT8_C(244), UINT8_C( 46), UINT8_C(200), UINT8_C(168), UINT8_C(217), UINT8_C( 49),
            UINT8_C(119), UINT8_C(243), UINT8_C(110), UINT8_C( 77), UINT8_C(104), UINT8_C(150), UINT8_C( 94), UINT8_C( 60) },
          { UINT8_C(149), UINT8_C( 10), UINT8_C(187), UINT8_C( 80), UINT8_C( 66), UINT8_C( 76), UINT8_C(193), UINT8_C(241),
            UINT8_C(195), UINT8_C( 54), UINT8_C( 11), UINT8_C( 50), UINT8_C( 87), UINT8_C(114), UINT8_C(109), UINT8_C(215) },
          { UINT8_C( 45), UINT8_C( 97), UINT8_C(  1), UINT8_C(120), UINT8_C(  9), UINT8_C(218), UINT8_C( 39), UINT8_C(128),
            UINT8_C(205), UINT8_C(150), UINT8_C(205), UINT8_C( 54), UINT8_C( 44), UINT8_C( 43), UINT8_C(114), UINT8_C(193) } },
    },
    {
        { { UINT8_C(122), UINT8_C( 17), UINT8_C(105), UINT8_C( 62), UINT8_C( 71), UINT8_C(117), UINT8_C(112), UINT8_C(158),
            UINT8_C(231), UINT8_C(221), UINT8_C(118), UINT8_C( 20), UINT8_C( 62), UINT8_C(119), UINT8_C( 10), UINT8_C( 71) },
          { UINT8_C( 81), UINT8_C( 50), UINT8_C(199), UINT8_C( 30), UINT8_C(200), UINT8_C(149), UINT8_C( 84), UINT8_C(244),
            UINT8_C(192), UINT8_C(199), UINT8_C(181), UINT8_C(246), UINT8_C(245), UINT8_C(  5), UINT8_C(111), UINT8_C(111) },
          { UINT8_C( 23), UINT8_C(216), UINT8_C(173), UINT8_C( 94), UINT8_C( 77), UINT8_C( 30), UINT8_C(253), UINT8_C( 52),
            UINT8_C(251), UINT8_C(115), UINT8_C( 73), UINT8_C( 58), UINT8_C(234), UINT8_C( 83), UINT8_C(129), UINT8_C( 59) },
          { UINT8_C(133), UINT8_C( 73), UINT8_C( 89), UINT8_C( 77), UINT8_C(222), UINT8_C(174), UINT8_C( 65), UINT8_C(158),
            UINT8_C(117), UINT8_C(246), UINT8_C(149), UINT8_C(106), UINT8_C(252), UINT8_C(  4), UINT8_C(217), UINT8_C( 19) } },
      { UINT8_C(220), UINT8_C(135), UINT8_C(113), UINT8_C( 42) },
        { { UINT8_C(122), UINT8_C( 17), UINT8_C(105), UINT8_C( 62), UINT8_C(220), UINT8_C(117), UINT8_C(112), UINT8_C(158),
            UINT8_C(231), UINT8_C(221), UINT8_C(118), UINT8_C( 20), UINT8_C( 62), UINT8_C(119), UINT8_C( 10), UINT8_C( 71) },
          { UINT8_C( 81), UINT8_C( 50), UINT8_C(199), UINT8_C( 30), UINT8_C(135), UINT8_C(149), UINT8_C( 84), UINT8_C(244),
            UINT8_C(192), UINT8_C(199), UINT8_C(181), UINT8_C(246), UINT8_C(245), UINT8_C(  5), UINT8_C(111), UINT8_C(111) },
          { UINT8_C( 23), UINT8_C(216), UINT8_C(173), UINT8_C( 94), UINT8_C(113), UINT8_C( 30), UINT8_C(253), UINT8_C( 52),
            UINT8_C(251), UINT8_C(115), UINT8_C( 73), UINT8_C( 58), UINT8_C(234), UINT8_C( 83), UINT8_C(129), UINT8_C( 59) },
          { UINT8_C(133), UINT8_C( 73), UINT8_C( 89), UINT8_C( 77), UINT8_C( 42), UINT8_C(174), UINT8_C( 65), UINT8_C(158),
            UINT8_C(117), UINT8_C(246), UINT8_C(149), UINT8_C(106), UINT8_C(252), UINT8_C(  4), UINT8_C(217), UINT8_C( 19) } },
    },
    {
        { { UINT8_C(165), UINT8_C(110), UINT8_C( 94), UINT8_C(160), UINT8_C(225), UINT8_C(167), UINT8_C(218), UINT8_C(203),
            UINT8_C(251), UINT8_C( 92), UINT8_C(  6), UINT8_C(128), UINT8_C(165), UINT8_C( 96), UINT8_C(206), UINT8_C(131) },
          { UINT8_C( 14), UINT8_C( 15), UINT8_C( 33), UINT8_C(131), UINT8_C(  6), UINT8_C(182), UINT8_C(237), UINT8_C(  2),
            UINT8_C(186), UINT8_C(198), UINT8_C( 21), UINT8_C(151), UINT8_C( 77), UINT8_C(134), UINT8_C(193), UINT8_C(242) },
          { UINT8_C(245), UINT8_C( 31), UINT8_C(147), UINT8_C(214), UINT8_C(199), UINT8_C(109), UINT8_C(162), UINT8_C(194),
            UINT8_C(201), UINT8_C(168), UINT8_C( 66), UINT8_C(110), UINT8_C(  8), UINT8_C( 16), UINT8_C(241), UINT8_C( 22) },
          { UINT8_C( 32), UINT8_C( 19), UINT8_C(153), UINT8_C( 38), UINT8_C(201), UINT8_C(134), UINT8_C( 40), UINT8_C(132),
            UINT8_C( 77), UINT8_C( 61), UINT8_C( 27), UINT8_C(154), UINT8_C(195), UINT8_C(220), UINT8_C(141), UINT8_C(184) } },
      { UINT8_C(251), UINT8_C( 32), UINT8_C(143), UINT8_C(194) },
        { { UINT8_C(165), UINT8_C(110), UINT8_C( 94), UINT8_C(160), UINT8_C(225), UINT8_C(251), UINT8_C(218), UINT8_C(203),
            UINT8_C(251), UINT8_C( 92), UINT8_C(  6), UINT8_C(128), UINT8_C(165), UINT8_C( 96), UINT8_C(206), UINT8_C(131) },
          { UINT8_C( 14), UINT8_C( 15), UINT8_C( 33), UINT8_C(131), UINT8_C(  6), UINT8_C( 32), UINT8_C(237), UINT8_C(  2),
            UINT8_C(186), UINT8_C(198), UINT8_C( 21), UINT8_C(151), UINT8_C( 77), UINT8_C(134), UINT8_C(193), UINT8_C(242) },
          { UINT8_C(245), UINT8_C( 31), UINT8_C(147), UINT8_C(214), UINT8_C(199), UINT8_C(143), UINT8_C(162), UINT8_C(194),
            UINT8_C(201), UINT8_C(168), UINT8_C( 66), UINT8_C(110), UINT8_C(  8), UINT8_C( 16), UINT8_C(241), UINT8_C( 22) },
          { UINT8_C( 32), UINT8_C( 19), UINT8_C(153), UINT8_C( 38), UINT8_C(201), UINT8_C(194), UINT8_C( 40), UINT8_C(132),
            UINT8_C( 77), UINT8_C( 61), UINT8_C( 27), UINT8_C(154), UINT8_C(195), UINT8_C(220), UINT8_C(141), UINT8_C(184) } },
    },
    {
        { { UINT8_C(141), UINT8_C( 49), UINT8_C(132), UINT8_C( 87), UINT8_C(217), UINT8_C(199), UINT8_C(197), UINT8_C(226),
            UINT8_C(215), UINT8_C(183), UINT8_C(248), UINT8_C(247), UINT8_C(202), UINT8_C(146), UINT8_C( 29), UINT8_C(147) },
          { UINT8_C( 24), UINT8_C( 69), UINT8_C( 23), UINT8_C(101), UINT8_C(130), UINT8_C( 50), UINT8_C(  0), UINT8_C( 70),
            UINT8_C( 14), UINT8_C(141), UINT8_C(254), UINT8_C( 10), UINT8_C(173), UINT8_C(141), UINT8_C(204), UINT8_C( 58) },
          { UINT8_C(190), UINT8_C( 81), UINT8_C(145), UINT8_C(152), UINT8_C( 24), UINT8_C( 87), UINT8_C(122), UINT8_C(239),
            UINT8_C( 14), UINT8_C(114), UINT8_C(231), UINT8_C(216), UINT8_C(  4), UINT8_C(  4), UINT8_C(107), UINT8_C( 29) },
          { UINT8_C( 74), UINT8_C(131), UINT8_C(130), UINT8_C(204), UINT8_C(181), UINT8_C(130), UINT8_C( 18), UINT8_C(196),
            UINT8_C( 15), UINT8_C( 17), UINT8_C(206), UINT8_C(188), UINT8_C(158), UINT8_C(154), UINT8_C(247), UINT8_C( 93) } },
      { UINT8_C(235), UINT8_C(136), UINT8_C(245), UINT8_C(  3) },
        { { UINT8_C(141), UINT8_C( 49), UINT8_C(132), UINT8_C( 87), UINT8_C(217), UINT8_C(199), UINT8_C(235), UINT8_C(226),
            UINT8_C(215), UINT8_C(183), UINT8_C(248), UINT8_C(247), UINT8_C(202), UINT8_C(146), UINT8_C( 29), UINT8_C(147) },
          { UINT8_C( 24), UINT8_C( 69), UINT8_C( 23), UINT8_C(101), UINT8_C(130), UINT8_C( 50), UINT8_C(136), UINT8_C( 70),
            UINT8_C( 14), UINT8_C(141), UINT8_C(254), UINT8_C( 10), UINT8_C(173), UINT8_C(141), UINT8_C(204), UINT8_C( 58) },
          { UINT8_C(190), UINT8_C( 81), UINT8_C(145), UINT8_C(152), UINT8_C( 24), UINT8_C( 87), UINT8_C(245), UINT8_C(239),
            UINT8_C( 14), UINT8_C(114), UINT8_C(231), UINT8_C(216), UINT8_C(  4), UINT8_C(  4), UINT8_C(107), UINT8_C( 29) },
          { UINT8_C( 74), UINT8_C(131), UINT8_C(130), UINT8_C(204), UINT8_C(181), UINT8_C(130), UINT8_C(  3), UINT8_C(196),
            UINT8_C( 15), UINT8_C( 17), UINT8_C(206), UINT8_C(188), UINT8_C(158), UINT8_C(154), UINT8_C(247), UINT8_C( 93) } },
    },
    {
        { { UINT8_C(223), UINT8_C(111), UINT8_C(243), UINT8_C(237), UINT8_C(225), UINT8_C(218), UINT8_C(197), UINT8_C(230),
            UINT8_C(222), UINT8_C( 49), UINT8_C(  3), UINT8_C( 40), UINT8_C(180), UINT8_C(133), UINT8_C(245), UINT8_C(105) },
          { UINT8_C(  8), UINT8_C(  7), UINT8_C( 45), UINT8_C( 23), UINT8_C( 24), UINT8_C(251), UINT8_C(212), UINT8_C(183),
            UINT8_C(150), UINT8_C(203), UINT8_C( 20), UINT8_C(129), UINT8_C( 83), UINT8_C(  9), UINT8_C(133), UINT8_C( 51) },
          { UINT8_C(120), UINT8_C(120), UINT8_C( 32), UINT8_C( 89), UINT8_C( 82), UINT8_C(230), UINT8_C( 63), UINT8_C( 48),
            UINT8_C( 23), UINT8_C( 66), UINT8_C( 89), UINT8_C(203), UINT8_C(200), UINT8_C( 78), UINT8_C( 52), UINT8_C(208) },
          { UINT8_C( 85), UINT8_C( 98), UINT8_C(231), UINT8_C(110), UINT8_C( 93), UINT8_C(187), UINT8_C( 37), UINT8_C(243),
            UINT8_C(134), UINT8_C( 57), UINT8_C(117), UINT8_C(218), UINT8_C( 66), UINT8_C(250), UINT8_C( 13), UINT8_C(186) } },
      { UINT8_C(114), UINT8_C( 45), UINT8_C( 19), UINT8_C(196) },
        { { UINT8_C(223), UINT8_C(111), UINT8_C(243), UINT8_C(237), UINT8_C(225), UINT8_C(218), UINT8_C(197), UINT8_C(114),
            UINT8_C(222), UINT8_C( 49), UINT8_C(  3), UINT8_C( 40), UINT8_C(180), UINT8_C(133), UINT8_C(245), UINT8_C(105) },
          { UINT8_C(  8), UINT8_C(  7), UINT8_C( 45), UINT8_C( 23), UINT8_C( 24), UINT8_C(251), UINT8_C(212), UINT8_C( 45),
            UINT8_C(150), UINT8_C(203), UINT8_C( 20), UINT8_C(129), UINT8_C( 83), UINT8_C(  9), UINT8_C(133), UINT8_C( 51) },
          { UINT8_C(120), UINT8_C(120), UINT8_C( 32), UINT8_C( 89), UINT8_C( 82), UINT8_C(230), UINT8_C( 63), UINT8_C( 19),
            UINT8_C( 23), UINT8_C( 66), UINT8_C( 89), UINT8_C(203), UINT8_C(200), UINT8_C( 78), UINT8_C( 52), UINT8_C(208) },
          { UINT8_C( 85), UINT8_C( 98), UINT8_C(231), UINT8_C(110), UINT8_C( 93), UINT8_C(187), UINT8_C( 37), UINT8_C(196),
            UINT8_C(134), UINT8_C( 57), UINT8_C(117), UINT8_C(218), UINT8_C( 66), UINT8_C(250), UINT8_C( 13), UINT8_C(186) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x4_t r;
    simde_uint8x16x4_t src = {
        {simde_vld1q_u8(test_vec[i].src[0]), simde_vld1q_u8(test_vec[i].src[1]),
         simde_vld1q_u8(test_vec[i].src[2]), simde_vld1q_u8(test_vec[i].src[3])}};
    simde_uint8x16x4_t expected = {
        {simde_vld1q_u8(test_vec[i].r[0]), simde_vld1q_u8(test_vec[i].r[1]),
         simde_vld1q_u8(test_vec[i].r[2]), simde_vld1q_u8(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_16_(simde_vld4q_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x4_t src = simde_test_arm_neon_random_u8x16x4();
    simde_test_arm_neon_write_u8x16x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint8_t buf[4];
    simde_test_codegen_random_memory(4, buf);
    simde_test_codegen_write_vu8(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint8x16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vld4q_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_u8x16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t src[4][8];
    uint16_t buf[4];
    uint16_t r[4][8];
  } test_vec[] = {
    {
        { { UINT16_C(36561), UINT16_C(27412), UINT16_C(49068), UINT16_C(10101), UINT16_C(56899), UINT16_C(25642), UINT16_C(61901), UINT16_C(17642) },
          { UINT16_C(29177), UINT16_C(52241), UINT16_C(33043), UINT16_C(57000), UINT16_C(34377), UINT16_C(24689), UINT16_C(48063), UINT16_C(37050) },
          { UINT16_C(53065), UINT16_C(62971), UINT16_C(28814), UINT16_C(53532), UINT16_C(17998), UINT16_C( 6966), UINT16_C( 8247), UINT16_C(12383) },
          { UINT16_C(28817), UINT16_C(42237), UINT16_C(42481), UINT16_C(15234), UINT16_C(62507), UINT16_C(60059), UINT16_C(21935), UINT16_C(63610) } },
      { UINT16_C(29988), UINT16_C(46061), UINT16_C(62106), UINT16_C(50158) },
        { { UINT16_C(29988), UINT16_C(27412), UINT16_C(49068), UINT16_C(10101), UINT16_C(56899), UINT16_C(25642), UINT16_C(61901), UINT16_C(17642) },
          { UINT16_C(46061), UINT16_C(52241), UINT16_C(33043), UINT16_C(57000), UINT16_C(34377), UINT16_C(24689), UINT16_C(48063), UINT16_C(37050) },
          { UINT16_C(62106), UINT16_C(62971), UINT16_C(28814), UINT16_C(53532), UINT16_C(17998), UINT16_C( 6966), UINT16_C( 8247), UINT16_C(12383) },
          { UINT16_C(50158), UINT16_C(42237), UINT16_C(42481), UINT16_C(15234), UINT16_C(62507), UINT16_C(60059), UINT16_C(21935), UINT16_C(63610) } },
    },
    {
        { { UINT16_C( 2533), UINT16_C(13188), UINT16_C(47696), UINT16_C(34638), UINT16_C(44506), UINT16_C(27576), UINT16_C(46365), UINT16_C( 3856) },
          { UINT16_C(37466), UINT16_C(34122), UINT16_C(58758), UINT16_C(13679), UINT16_C(59706), UINT16_C(24365), UINT16_C( 6750), UINT16_C(17170) },
          { UINT16_C(38436), UINT16_C(29814), UINT16_C(50257), UINT16_C(11259), UINT16_C(45937), UINT16_C(36503), UINT16_C(42856), UINT16_C(49821) },
          { UINT16_C(59193), UINT16_C(49223), UINT16_C(46796), UINT16_C( 2037), UINT16_C( 9119), UINT16_C(64870), UINT16_C(30781), UINT16_C(24896) } },
      { UINT16_C(46606), UINT16_C(24533), UINT16_C(62106), UINT16_C(50158) },
        { { UINT16_C( 2533), UINT16_C(46606), UINT16_C(47696), UINT16_C(34638), UINT16_C(44506), UINT16_C(27576), UINT16_C(46365), UINT16_C( 3856) },
          { UINT16_C(37466), UINT16_C(24533), UINT16_C(58758), UINT16_C(13679), UINT16_C(59706), UINT16_C(24365), UINT16_C( 6750), UINT16_C(17170) },
          { UINT16_C(38436), UINT16_C(62106), UINT16_C(50257), UINT16_C(11259), UINT16_C(45937), UINT16_C(36503), UINT16_C(42856), UINT16_C(49821) },
          { UINT16_C(59193), UINT16_C(50158), UINT16_C(46796), UINT16_C( 2037), UINT16_C( 9119), UINT16_C(64870), UINT16_C(30781), UINT16_C(24896) } },
    },
    {
        { { UINT16_C(53626), UINT16_C(60299), UINT16_C( 8836), UINT16_C(60794), UINT16_C( 6089), UINT16_C(  687), UINT16_C(63487), UINT16_C(52162) },
          { UINT16_C(47277), UINT16_C(19922), UINT16_C(14555), UINT16_C( 6218), UINT16_C(35760), UINT16_C(49018), UINT16_C(20289), UINT16_C(48158) },
          { UINT16_C(43296), UINT16_C(42407), UINT16_C( 8651), UINT16_C(38034), UINT16_C(16697), UINT16_C(14487), UINT16_C(22840), UINT16_C(58883) },
          { UINT16_C(54801), UINT16_C(60467), UINT16_C(32014), UINT16_C(48901), UINT16_C(32520), UINT16_C(19070), UINT16_C(40142), UINT16_C(61190) } },
      { UINT16_C(44358), UINT16_C( 4500), UINT16_C(62106), UINT16_C(50158) },
        { { UINT16_C(53626), UINT16_C(60299), UINT16_C(44358), UINT16_C(60794), UINT16_C( 6089), UINT16_C(  687), UINT16_C(63487), UINT16_C(52162) },
          { UINT16_C(47277), UINT16_C(19922), UINT16_C( 4500), UINT16_C( 6218), UINT16_C(35760), UINT16_C(49018), UINT16_C(20289), UINT16_C(48158) },
          { UINT16_C(43296), UINT16_C(42407), UINT16_C(62106), UINT16_C(38034), UINT16_C(16697), UINT16_C(14487), UINT16_C(22840), UINT16_C(58883) },
          { UINT16_C(54801), UINT16_C(60467), UINT16_C(50158), UINT16_C(48901), UINT16_C(32520), UINT16_C(19070), UINT16_C(40142), UINT16_C(61190) } },
    },
    {
        { { UINT16_C( 9935), UINT16_C( 2214), UINT16_C(15719), UINT16_C(41024), UINT16_C(17302), UINT16_C(43142), UINT16_C(47385), UINT16_C(10388) },
          { UINT16_C(39222), UINT16_C(16359), UINT16_C(25880), UINT16_C(59273), UINT16_C(36609), UINT16_C(18390), UINT16_C(27196), UINT16_C( 2905) },
          { UINT16_C(65424), UINT16_C(63251), UINT16_C(21308), UINT16_C(53911), UINT16_C( 7575), UINT16_C(45178), UINT16_C( 4054), UINT16_C( 3544) },
          { UINT16_C(49064), UINT16_C(49484), UINT16_C(54564), UINT16_C( 9896), UINT16_C(32356), UINT16_C(41069), UINT16_C(50920), UINT16_C(30892) } },
      { UINT16_C(49093), UINT16_C(  367), UINT16_C(62106), UINT16_C(50158) },
        { { UINT16_C( 9935), UINT16_C( 2214), UINT16_C(15719), UINT16_C(49093), UINT16_C(17302), UINT16_C(43142), UINT16_C(47385), UINT16_C(10388) },
          { UINT16_C(39222), UINT16_C(16359), UINT16_C(25880), UINT16_C(  367), UINT16_C(36609), UINT16_C(18390), UINT16_C(27196), UINT16_C( 2905) },
          { UINT16_C(65424), UINT16_C(63251), UINT16_C(21308), UINT16_C(62106), UINT16_C( 7575), UINT16_C(45178), UINT16_C( 4054), UINT16_C( 3544) },
          { UINT16_C(49064), UINT16_C(49484), UINT16_C(54564), UINT16_C(50158), UINT16_C(32356), UINT16_C(41069), UINT16_C(50920), UINT16_C(30892) } },
    },
    {
        { { UINT16_C( 1811), UINT16_C(43732), UINT16_C(20004), UINT16_C(64346), UINT16_C(13149), UINT16_C( 1544), UINT16_C(21746), UINT16_C( 6087) },
          { UINT16_C(28457), UINT16_C(36157), UINT16_C(43757), UINT16_C(54573), UINT16_C(55665), UINT16_C(13901), UINT16_C(48281), UINT16_C(44088) },
          { UINT16_C( 3267), UINT16_C(59478), UINT16_C(45146), UINT16_C(47331), UINT16_C(60387), UINT16_C(54974), UINT16_C(34111), UINT16_C(26861) },
          { UINT16_C(10996), UINT16_C(57845), UINT16_C( 8916), UINT16_C(17846), UINT16_C( 1020), UINT16_C(38268), UINT16_C(46271), UINT16_C(33601) } },
      { UINT16_C(38848), UINT16_C( 6763), UINT16_C(62106), UINT16_C(50158) },
        { { UINT16_C( 1811), UINT16_C(43732), UINT16_C(20004), UINT16_C(64346), UINT16_C(38848), UINT16_C( 1544), UINT16_C(21746), UINT16_C( 6087) },
          { UINT16_C(28457), UINT16_C(36157), UINT16_C(43757), UINT16_C(54573), UINT16_C( 6763), UINT16_C(13901), UINT16_C(48281), UINT16_C(44088) },
          { UINT16_C( 3267), UINT16_C(59478), UINT16_C(45146), UINT16_C(47331), UINT16_C(62106), UINT16_C(54974), UINT16_C(34111), UINT16_C(26861) },
          { UINT16_C(10996), UINT16_C(57845), UINT16_C( 8916), UINT16_C(17846), UINT16_C(50158), UINT16_C(38268), UINT16_C(46271), UINT16_C(33601) } },
    },
    {
        { { UINT16_C(20039), UINT16_C(11218), UINT16_C(36921), UINT16_C(30721), UINT16_C(60949), UINT16_C( 2528), UINT16_C(54552), UINT16_C(60650) },
          { UINT16_C(41207), UINT16_C(62258), UINT16_C(44707), UINT16_C(25480), UINT16_C(51554), UINT16_C( 8934), UINT16_C(20832), UINT16_C(43068) },
          { UINT16_C( 3999), UINT16_C(55507), UINT16_C(54431), UINT16_C(46416), UINT16_C(12482), UINT16_C(55998), UINT16_C(43269), UINT16_C(64710) },
          { UINT16_C(63561), UINT16_C(60912), UINT16_C(30886), UINT16_C( 2128), UINT16_C(13890), UINT16_C(41514), UINT16_C(26503), UINT16_C( 9802) } },
      { UINT16_C( 7542), UINT16_C( 5630), UINT16_C(62106), UINT16_C(50158) },
        { { UINT16_C(20039), UINT16_C(11218), UINT16_C(36921), UINT16_C(30721), UINT16_C(60949), UINT16_C( 7542), UINT16_C(54552), UINT16_C(60650) },
          { UINT16_C(41207), UINT16_C(62258), UINT16_C(44707), UINT16_C(25480), UINT16_C(51554), UINT16_C( 5630), UINT16_C(20832), UINT16_C(43068) },
          { UINT16_C( 3999), UINT16_C(55507), UINT16_C(54431), UINT16_C(46416), UINT16_C(12482), UINT16_C(62106), UINT16_C(43269), UINT16_C(64710) },
          { UINT16_C(63561), UINT16_C(60912), UINT16_C(30886), UINT16_C( 2128), UINT16_C(13890), UINT16_C(50158), UINT16_C(26503), UINT16_C( 9802) } },
    },
    {
        { { UINT16_C(20209), UINT16_C(46026), UINT16_C(35198), UINT16_C(33677), UINT16_C(21554), UINT16_C(31615), UINT16_C(28492), UINT16_C(62312) },
          { UINT16_C(47336), UINT16_C(11003), UINT16_C( 9966), UINT16_C(30156), UINT16_C( 6029), UINT16_C(  923), UINT16_C(39220), UINT16_C( 9752) },
          { UINT16_C(58343), UINT16_C(26073), UINT16_C(26476), UINT16_C(40680), UINT16_C(26811), UINT16_C( 1817), UINT16_C(33495), UINT16_C(49146) },
          { UINT16_C(63034), UINT16_C(10729), UINT16_C(46620), UINT16_C(43422), UINT16_C(15053), UINT16_C(  428), UINT16_C(50387), UINT16_C(47911) } },
      { UINT16_C(  423), UINT16_C( 4896), UINT16_C(62106), UINT16_C(50158) },
        { { UINT16_C(20209), UINT16_C(46026), UINT16_C(35198), UINT16_C(33677), UINT16_C(21554), UINT16_C(31615), UINT16_C(  423), UINT16_C(62312) },
          { UINT16_C(47336), UINT16_C(11003), UINT16_C( 9966), UINT16_C(30156), UINT16_C( 6029), UINT16_C(  923), UINT16_C( 4896), UINT16_C( 9752) },
          { UINT16_C(58343), UINT16_C(26073), UINT16_C(26476), UINT16_C(40680), UINT16_C(26811), UINT16_C( 1817), UINT16_C(62106), UINT16_C(49146) },
          { UINT16_C(63034), UINT16_C(10729), UINT16_C(46620), UINT16_C(43422), UINT16_C(15053), UINT16_C(  428), UINT16_C(50158), UINT16_C(47911) } },
    },
    {
        { { UINT16_C( 2408), UINT16_C( 9137), UINT16_C(52081), UINT16_C(18474), UINT16_C( 9549), UINT16_C(34568), UINT16_C(61723), UINT16_C(14256) },
          { UINT16_C(20391), UINT16_C(29920), UINT16_C(35977), UINT16_C(23670), UINT16_C(40272), UINT16_C(63511), UINT16_C(14494), UINT16_C( 1547) },
          { UINT16_C(48449), UINT16_C(45609), UINT16_C(21640), UINT16_C(54778), UINT16_C(  633), UINT16_C(37980), UINT16_C( 3572), UINT16_C(39883) },
          { UINT16_C(43868), UINT16_C(58640), UINT16_C(34359), UINT16_C(34625), UINT16_C(22819), UINT16_C(49791), UINT16_C(35729), UINT16_C(53960) } },
      { UINT16_C(62024), UINT16_C(53380), UINT16_C(62106), UINT16_C(50158) },
        { { UINT16_C( 2408), UINT16_C( 9137), UINT16_C(52081), UINT16_C(18474), UINT16_C( 9549), UINT16_C(34568), UINT16_C(61723), UINT16_C(62024) },
          { UINT16_C(20391), UINT16_C(29920), UINT16_C(35977), UINT16_C(23670), UINT16_C(40272), UINT16_C(63511), UINT16_C(14494), UINT16_C(53380) },
          { UINT16_C(48449), UINT16_C(45609), UINT16_C(21640), UINT16_C(54778), UINT16_C(  633), UINT16_C(37980), UINT16_C( 3572), UINT16_C(62106) },
          { UINT16_C(43868), UINT16_C(58640), UINT16_C(34359), UINT16_C(34625), UINT16_C(22819), UINT16_C(49791), UINT16_C(35729), UINT16_C(50158) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x4_t r;
    simde_uint16x8x4_t src = {
        {simde_vld1q_u16(test_vec[i].src[0]), simde_vld1q_u16(test_vec[i].src[1]),
         simde_vld1q_u16(test_vec[i].src[2]), simde_vld1q_u16(test_vec[i].src[3])}};
    simde_uint16x8x4_t expected = {
        {simde_vld1q_u16(test_vec[i].r[0]), simde_vld1q_u16(test_vec[i].r[1]),
         simde_vld1q_u16(test_vec[i].r[2]), simde_vld1q_u16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_8_(simde_vld4q_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_u16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8x4_t src = simde_test_arm_neon_random_u16x8x4();
    simde_test_arm_neon_write_u16x8x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint16_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vu16(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint16x8x4_t r;
    SIMDE_CONSTIFY_8_(simde_vld4q_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_u16x8x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t src[4][4];
    uint32_t buf[4];
    uint32_t r[4][4];
  } test_vec[] = {
    {
        { { UINT32_C(1205893189), UINT32_C( 891332804), UINT32_C(2249248723), UINT32_C( 928282505) },
          { UINT32_C(  85412513), UINT32_C(2207258482), UINT32_C(3967496535), UINT32_C(1957615663) },
          { UINT32_C( 364678737), UINT32_C( 155900982), UINT32_C( 881875883), UINT32_C(1936516306) },
          { UINT32_C(2709095214), UINT32_C(4045670810), UINT32_C(1776197434), UINT32_C(3370028151) } },
      { UINT32_C(1373542938), UINT32_C(2269218359), UINT32_C(3263125795), UINT32_C(3287190417) },
        { { UINT32_C(1373542938), UINT32_C( 891332804), UINT32_C(2249248723), UINT32_C( 928282505) },
          { UINT32_C(2269218359), UINT32_C(2207258482), UINT32_C(3967496535), UINT32_C(1957615663) },
          { UINT32_C(3263125795), UINT32_C( 155900982), UINT32_C( 881875883), UINT32_C(1936516306) },
          { UINT32_C(3287190417), UINT32_C(4045670810), UINT32_C(1776197434), UINT32_C(3370028151) } },
    },
    {
        { { UINT32_C( 576333942), UINT32_C(1448536707), UINT32_C(4257858255), UINT32_C(3768468038) },
          { UINT32_C(2261959244), UINT32_C(3656429665), UINT32_C(1453444668), UINT32_C(3735519080) },
          { UINT32_C( 721420968), UINT32_C(3145816044), UINT32_C(1605978905), UINT32_C(3644872589) },
          { UINT32_C(2069893658), UINT32_C(4266938562), UINT32_C(2253714974), UINT32_C( 493157493) } },
      { UINT32_C(3930678782), UINT32_C(2269218359), UINT32_C(3263125795), UINT32_C(3287190417) },
        { { UINT32_C( 576333942), UINT32_C(3930678782), UINT32_C(4257858255), UINT32_C(3768468038) },
          { UINT32_C(2261959244), UINT32_C(2269218359), UINT32_C(1453444668), UINT32_C(3735519080) },
          { UINT32_C( 721420968), UINT32_C(3263125795), UINT32_C(1605978905), UINT32_C(3644872589) },
          { UINT32_C(2069893658), UINT32_C(3287190417), UINT32_C(2253714974), UINT32_C( 493157493) } },
    },
    {
        { { UINT32_C(3584477884), UINT32_C(2738183957), UINT32_C(3497817526), UINT32_C(1229773959) },
          { UINT32_C(1246208044), UINT32_C( 214997910), UINT32_C(2502505879), UINT32_C(1451258522) },
          { UINT32_C(1378559549), UINT32_C(1005936773), UINT32_C(1544319701), UINT32_C(2074433614) },
          { UINT32_C(2412113144), UINT32_C( 530290312), UINT32_C(1706411211), UINT32_C(1958425911) } },
      { UINT32_C(3771131483), UINT32_C(2269218359), UINT32_C(3263125795), UINT32_C(3287190417) },
        { { UINT32_C(3584477884), UINT32_C(2738183957), UINT32_C(3771131483), UINT32_C(1229773959) },
          { UINT32_C(1246208044), UINT32_C( 214997910), UINT32_C(2269218359), UINT32_C(1451258522) },
          { UINT32_C(1378559549), UINT32_C(1005936773), UINT32_C(3263125795), UINT32_C(2074433614) },
          { UINT32_C(2412113144), UINT32_C( 530290312), UINT32_C(3287190417), UINT32_C(1958425911) } },
    },
    {
        { { UINT32_C( 471579719), UINT32_C(2088314670), UINT32_C(2029461119), UINT32_C(2466757899) },
          { UINT32_C( 515023443), UINT32_C(2642634598), UINT32_C(4145102492), UINT32_C(1809307684) },
          { UINT32_C(3263755156), UINT32_C(2587754778), UINT32_C( 705836575), UINT32_C(1186798067) },
          { UINT32_C( 560230587), UINT32_C(1958733783), UINT32_C(1231802405), UINT32_C(1018512296) } },
      { UINT32_C(1358839094), UINT32_C(2269218359), UINT32_C(3263125795), UINT32_C(3287190417) },
        { { UINT32_C( 471579719), UINT32_C(2088314670), UINT32_C(2029461119), UINT32_C(1358839094) },
          { UINT32_C( 515023443), UINT32_C(2642634598), UINT32_C(4145102492), UINT32_C(2269218359) },
          { UINT32_C(3263755156), UINT32_C(2587754778), UINT32_C( 705836575), UINT32_C(3263125795) },
          { UINT32_C( 560230587), UINT32_C(1958733783), UINT32_C(1231802405), UINT32_C(3287190417) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x4_t r;
    simde_uint32x4x4_t src = {
        {simde_vld1q_u32(test_vec[i].src[0]), simde_vld1q_u32(test_vec[i].src[1]),
         simde_vld1q_u32(test_vec[i].src[2]), simde_vld1q_u32(test_vec[i].src[3])}};
    simde_uint32x4x4_t expected = {
        {simde_vld1q_u32(test_vec[i].r[0]), simde_vld1q_u32(test_vec[i].r[1]),
         simde_vld1q_u32(test_vec[i].r[2]), simde_vld1q_u32(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_4_(simde_vld4q_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint32x4x4_t src = simde_test_arm_neon_random_u32x4x4();
    simde_test_arm_neon_write_u32x4x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint32_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vu32(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint32x4x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld4q_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_u32x4x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t src[4][2];
    uint64_t buf[4];
    uint64_t r[4][2];
  } test_vec[] = {
    {
        { { UINT64_C( 3250796473744199931), UINT64_C(10767859826275018628) },
          { UINT64_C(15112678336494193727), UINT64_C( 6754449887704585981) },
          { UINT64_C(  255255469939710257), UINT64_C( 4272671385087892544) },
          { UINT64_C(14380382604302403039), UINT64_C( 3546131711415312503) } },
      { UINT64_C(11114322142593741501), UINT64_C(14015018572964836895), UINT64_C( 8412697540115591355), UINT64_C(14118375337971404837) },
        { { UINT64_C(11114322142593741501), UINT64_C(10767859826275018628) },
          { UINT64_C(14015018572964836895), UINT64_C( 6754449887704585981) },
          { UINT64_C( 8412697540115591355), UINT64_C( 4272671385087892544) },
          { UINT64_C(14118375337971404837), UINT64_C( 3546131711415312503) } },
    },
    {
        { { UINT64_C(17348538614396426443), UINT64_C(11282874773726301686) },
          { UINT64_C( 9693166441718818100), UINT64_C( 8676261292211157871) },
          { UINT64_C(   90711956943841373), UINT64_C( 8485742950953152083) },
          { UINT64_C(11645082896017925776), UINT64_C(17764227281897542497) } },
      { UINT64_C(11114322145491553246), UINT64_C(14015018572964836895), UINT64_C( 8412697540115591355), UINT64_C(14118375337971404837) },
        { { UINT64_C(11114322145491553246), UINT64_C(11282874773726301686) },
          { UINT64_C(14015018572964836895), UINT64_C( 8676261292211157871) },
          { UINT64_C( 8412697540115591355), UINT64_C( 8485742950953152083) },
          { UINT64_C(14118375337971404837), UINT64_C(17764227281897542497) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x4_t src = {
        {simde_vld1q_u64(test_vec[i].src[0]), simde_vld1q_u64(test_vec[i].src[1]),
         simde_vld1q_u64(test_vec[i].src[2]), simde_vld1q_u64(test_vec[i].src[3])}};
    simde_uint64x2x4_t r = simde_vld4q_lane_u64(test_vec[i].buf, src, 0);

    simde_uint64x2x4_t expected = {
        {simde_vld1q_u64(test_vec[i].r[0]), simde_vld1q_u64(test_vec[i].r[1]),
         simde_vld1q_u64(test_vec[i].r[2]), simde_vld1q_u64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_uint64x2x4_t src = simde_test_arm_neon_random_u64x2x4();
    simde_test_arm_neon_write_u64x2x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint64_t buf[4];
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vu64(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint64x2x4_t r = simde_vld4q_lane_u64(buf, src, 0);
    simde_test_arm_neon_write_u64x2x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t src[4][8];
    simde_float16_t buf[4];
    simde_float16_t r[4][8];
  } test_vec[] = {
   { { {  SIMDE_FLOAT16_VALUE(6.33), SIMDE_FLOAT16_VALUE(-26.33), SIMDE_FLOAT16_VALUE(-42.22), SIMDE_FLOAT16_VALUE(-34.31),
        SIMDE_FLOAT16_VALUE(-14.99), SIMDE_FLOAT16_VALUE(-21.27), SIMDE_FLOAT16_VALUE(2.75), SIMDE_FLOAT16_VALUE(47.13) },
       {  SIMDE_FLOAT16_VALUE(-43.49), SIMDE_FLOAT16_VALUE(17.65), SIMDE_FLOAT16_VALUE(39.50), SIMDE_FLOAT16_VALUE(-42.60),
        SIMDE_FLOAT16_VALUE(36.05), SIMDE_FLOAT16_VALUE(-8.32), SIMDE_FLOAT16_VALUE(-40.92), SIMDE_FLOAT16_VALUE(18.06) },
       {  SIMDE_FLOAT16_VALUE(-42.88), SIMDE_FLOAT16_VALUE(4.14), SIMDE_FLOAT16_VALUE(45.09), SIMDE_FLOAT16_VALUE(20.35),
        SIMDE_FLOAT16_VALUE(-37.99), SIMDE_FLOAT16_VALUE(6.50), SIMDE_FLOAT16_VALUE(-31.38), SIMDE_FLOAT16_VALUE(7.92) },
       {  SIMDE_FLOAT16_VALUE(-39.25), SIMDE_FLOAT16_VALUE(-28.22), SIMDE_FLOAT16_VALUE(-2.20), SIMDE_FLOAT16_VALUE(-44.73),
        SIMDE_FLOAT16_VALUE(-39.75), SIMDE_FLOAT16_VALUE(48.64), SIMDE_FLOAT16_VALUE(-28.85), SIMDE_FLOAT16_VALUE(-41.84) } },
       {  SIMDE_FLOAT16_VALUE(28.80), SIMDE_FLOAT16_VALUE(25.22), SIMDE_FLOAT16_VALUE(20.66), SIMDE_FLOAT16_VALUE(48.85)},
     { {  SIMDE_FLOAT16_VALUE(28.80), SIMDE_FLOAT16_VALUE(-26.33), SIMDE_FLOAT16_VALUE(-42.22), SIMDE_FLOAT16_VALUE(-34.31),
        SIMDE_FLOAT16_VALUE(-14.99), SIMDE_FLOAT16_VALUE(-21.27), SIMDE_FLOAT16_VALUE(2.75), SIMDE_FLOAT16_VALUE(47.13) },
       {  SIMDE_FLOAT16_VALUE(25.22), SIMDE_FLOAT16_VALUE(17.65), SIMDE_FLOAT16_VALUE(39.50), SIMDE_FLOAT16_VALUE(-42.60),
        SIMDE_FLOAT16_VALUE(36.05), SIMDE_FLOAT16_VALUE(-8.32), SIMDE_FLOAT16_VALUE(-40.92), SIMDE_FLOAT16_VALUE(18.06) },
       {  SIMDE_FLOAT16_VALUE(20.66), SIMDE_FLOAT16_VALUE(4.14), SIMDE_FLOAT16_VALUE(45.09), SIMDE_FLOAT16_VALUE(20.35),
        SIMDE_FLOAT16_VALUE(-37.99), SIMDE_FLOAT16_VALUE(6.50), SIMDE_FLOAT16_VALUE(-31.38), SIMDE_FLOAT16_VALUE(7.92) },
       {  SIMDE_FLOAT16_VALUE(48.85), SIMDE_FLOAT16_VALUE(-28.22), SIMDE_FLOAT16_VALUE(-2.20), SIMDE_FLOAT16_VALUE(-44.73),
        SIMDE_FLOAT16_VALUE(-39.75), SIMDE_FLOAT16_VALUE(48.64), SIMDE_FLOAT16_VALUE(-28.85), SIMDE_FLOAT16_VALUE(-41.84) } } },
   { { {  SIMDE_FLOAT16_VALUE(42.30), SIMDE_FLOAT16_VALUE(4.65), SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-43.56),
        SIMDE_FLOAT16_VALUE(46.24), SIMDE_FLOAT16_VALUE(23.63), SIMDE_FLOAT16_VALUE(-33.71), SIMDE_FLOAT16_VALUE(-41.85) },
       {  SIMDE_FLOAT16_VALUE(46.94), SIMDE_FLOAT16_VALUE(30.22), SIMDE_FLOAT16_VALUE(3.71), SIMDE_FLOAT16_VALUE(1.50),
        SIMDE_FLOAT16_VALUE(-25.07), SIMDE_FLOAT16_VALUE(42.19), SIMDE_FLOAT16_VALUE(-19.27), SIMDE_FLOAT16_VALUE(-23.97) },
       {  SIMDE_FLOAT16_VALUE(-27.49), SIMDE_FLOAT16_VALUE(41.45), SIMDE_FLOAT16_VALUE(43.62), SIMDE_FLOAT16_VALUE(28.98),
        SIMDE_FLOAT16_VALUE(-2.13), SIMDE_FLOAT16_VALUE(24.85), SIMDE_FLOAT16_VALUE(-34.40), SIMDE_FLOAT16_VALUE(-36.80) },
       {  SIMDE_FLOAT16_VALUE(9.29), SIMDE_FLOAT16_VALUE(19.68), SIMDE_FLOAT16_VALUE(-47.75), SIMDE_FLOAT16_VALUE(7.71),
        SIMDE_FLOAT16_VALUE(-15.37), SIMDE_FLOAT16_VALUE(-22.42), SIMDE_FLOAT16_VALUE(-24.53), SIMDE_FLOAT16_VALUE(-31.46) } },
       {  SIMDE_FLOAT16_VALUE(6.38), SIMDE_FLOAT16_VALUE(-5.55), SIMDE_FLOAT16_VALUE(14.51), SIMDE_FLOAT16_VALUE(22.81)},
     { {  SIMDE_FLOAT16_VALUE(42.30), SIMDE_FLOAT16_VALUE(6.38), SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-43.56),
        SIMDE_FLOAT16_VALUE(46.24), SIMDE_FLOAT16_VALUE(23.63), SIMDE_FLOAT16_VALUE(-33.71), SIMDE_FLOAT16_VALUE(-41.85) },
       {  SIMDE_FLOAT16_VALUE(46.94), SIMDE_FLOAT16_VALUE(-5.55), SIMDE_FLOAT16_VALUE(3.71), SIMDE_FLOAT16_VALUE(1.50),
        SIMDE_FLOAT16_VALUE(-25.07), SIMDE_FLOAT16_VALUE(42.19), SIMDE_FLOAT16_VALUE(-19.27), SIMDE_FLOAT16_VALUE(-23.97) },
       {  SIMDE_FLOAT16_VALUE(-27.49), SIMDE_FLOAT16_VALUE(14.51), SIMDE_FLOAT16_VALUE(43.62), SIMDE_FLOAT16_VALUE(28.98),
        SIMDE_FLOAT16_VALUE(-2.13), SIMDE_FLOAT16_VALUE(24.85), SIMDE_FLOAT16_VALUE(-34.40), SIMDE_FLOAT16_VALUE(-36.80) },
       {  SIMDE_FLOAT16_VALUE(9.29), SIMDE_FLOAT16_VALUE(22.81), SIMDE_FLOAT16_VALUE(-47.75), SIMDE_FLOAT16_VALUE(7.71),
        SIMDE_FLOAT16_VALUE(-15.37), SIMDE_FLOAT16_VALUE(-22.42), SIMDE_FLOAT16_VALUE(-24.53), SIMDE_FLOAT16_VALUE(-31.46) } } },
   { { {  SIMDE_FLOAT16_VALUE(4.77), SIMDE_FLOAT16_VALUE(19.23), SIMDE_FLOAT16_VALUE(19.73), SIMDE_FLOAT16_VALUE(-7.18),
        SIMDE_FLOAT16_VALUE(-27.37), SIMDE_FLOAT16_VALUE(-20.24), SIMDE_FLOAT16_VALUE(49.18), SIMDE_FLOAT16_VALUE(-24.81) },
       {  SIMDE_FLOAT16_VALUE(-11.08), SIMDE_FLOAT16_VALUE(-46.49), SIMDE_FLOAT16_VALUE(2.52), SIMDE_FLOAT16_VALUE(26.02),
        SIMDE_FLOAT16_VALUE(24.04), SIMDE_FLOAT16_VALUE(47.33), SIMDE_FLOAT16_VALUE(-44.39), SIMDE_FLOAT16_VALUE(12.98) },
       {  SIMDE_FLOAT16_VALUE(-31.55), SIMDE_FLOAT16_VALUE(14.16), SIMDE_FLOAT16_VALUE(-20.43), SIMDE_FLOAT16_VALUE(-34.07),
        SIMDE_FLOAT16_VALUE(-49.98), SIMDE_FLOAT16_VALUE(10.50), SIMDE_FLOAT16_VALUE(15.65), SIMDE_FLOAT16_VALUE(-48.67) },
       {  SIMDE_FLOAT16_VALUE(-11.29), SIMDE_FLOAT16_VALUE(1.88), SIMDE_FLOAT16_VALUE(-32.68), SIMDE_FLOAT16_VALUE(-24.01),
        SIMDE_FLOAT16_VALUE(-1.11), SIMDE_FLOAT16_VALUE(3.86), SIMDE_FLOAT16_VALUE(27.69), SIMDE_FLOAT16_VALUE(26.05) } },
       {  SIMDE_FLOAT16_VALUE(10.65), SIMDE_FLOAT16_VALUE(-21.85), SIMDE_FLOAT16_VALUE(14.55), SIMDE_FLOAT16_VALUE(6.24)},
     { {  SIMDE_FLOAT16_VALUE(4.77), SIMDE_FLOAT16_VALUE(19.23), SIMDE_FLOAT16_VALUE(10.65), SIMDE_FLOAT16_VALUE(-7.18),
        SIMDE_FLOAT16_VALUE(-27.37), SIMDE_FLOAT16_VALUE(-20.24), SIMDE_FLOAT16_VALUE(49.18), SIMDE_FLOAT16_VALUE(-24.81) },
       {  SIMDE_FLOAT16_VALUE(-11.08), SIMDE_FLOAT16_VALUE(-46.49), SIMDE_FLOAT16_VALUE(-21.85), SIMDE_FLOAT16_VALUE(26.02),
        SIMDE_FLOAT16_VALUE(24.04), SIMDE_FLOAT16_VALUE(47.33), SIMDE_FLOAT16_VALUE(-44.39), SIMDE_FLOAT16_VALUE(12.98) },
       {  SIMDE_FLOAT16_VALUE(-31.55), SIMDE_FLOAT16_VALUE(14.16), SIMDE_FLOAT16_VALUE(14.55), SIMDE_FLOAT16_VALUE(-34.07),
        SIMDE_FLOAT16_VALUE(-49.98), SIMDE_FLOAT16_VALUE(10.50), SIMDE_FLOAT16_VALUE(15.65), SIMDE_FLOAT16_VALUE(-48.67) },
       {  SIMDE_FLOAT16_VALUE(-11.29), SIMDE_FLOAT16_VALUE(1.88), SIMDE_FLOAT16_VALUE(6.24), SIMDE_FLOAT16_VALUE(-24.01),
        SIMDE_FLOAT16_VALUE(-1.11), SIMDE_FLOAT16_VALUE(3.86), SIMDE_FLOAT16_VALUE(27.69), SIMDE_FLOAT16_VALUE(26.05) } } },
   { { {  SIMDE_FLOAT16_VALUE(-39.56), SIMDE_FLOAT16_VALUE(46.56), SIMDE_FLOAT16_VALUE(37.88), SIMDE_FLOAT16_VALUE(-34.85),
        SIMDE_FLOAT16_VALUE(-42.50), SIMDE_FLOAT16_VALUE(47.33), SIMDE_FLOAT16_VALUE(30.39), SIMDE_FLOAT16_VALUE(26.97) },
       {  SIMDE_FLOAT16_VALUE(12.13), SIMDE_FLOAT16_VALUE(13.90), SIMDE_FLOAT16_VALUE(-11.09), SIMDE_FLOAT16_VALUE(-46.55),
        SIMDE_FLOAT16_VALUE(-25.60), SIMDE_FLOAT16_VALUE(36.32), SIMDE_FLOAT16_VALUE(38.43), SIMDE_FLOAT16_VALUE(-15.44) },
       {  SIMDE_FLOAT16_VALUE(14.57), SIMDE_FLOAT16_VALUE(-33.72), SIMDE_FLOAT16_VALUE(17.48), SIMDE_FLOAT16_VALUE(-41.97),
        SIMDE_FLOAT16_VALUE(39.90), SIMDE_FLOAT16_VALUE(12.95), SIMDE_FLOAT16_VALUE(-24.90), SIMDE_FLOAT16_VALUE(22.89) },
       {  SIMDE_FLOAT16_VALUE(33.49), SIMDE_FLOAT16_VALUE(-29.52), SIMDE_FLOAT16_VALUE(-42.35), SIMDE_FLOAT16_VALUE(11.54),
        SIMDE_FLOAT16_VALUE(-19.29), SIMDE_FLOAT16_VALUE(-3.97), SIMDE_FLOAT16_VALUE(39.49), SIMDE_FLOAT16_VALUE(34.87) } },
       {  SIMDE_FLOAT16_VALUE(22.68), SIMDE_FLOAT16_VALUE(-10.73), SIMDE_FLOAT16_VALUE(1.03), SIMDE_FLOAT16_VALUE(9.92)},
     { {  SIMDE_FLOAT16_VALUE(-39.56), SIMDE_FLOAT16_VALUE(46.56), SIMDE_FLOAT16_VALUE(37.88), SIMDE_FLOAT16_VALUE(22.68),
        SIMDE_FLOAT16_VALUE(-42.50), SIMDE_FLOAT16_VALUE(47.33), SIMDE_FLOAT16_VALUE(30.39), SIMDE_FLOAT16_VALUE(26.97) },
       {  SIMDE_FLOAT16_VALUE(12.13), SIMDE_FLOAT16_VALUE(13.90), SIMDE_FLOAT16_VALUE(-11.09), SIMDE_FLOAT16_VALUE(-10.73),
        SIMDE_FLOAT16_VALUE(-25.60), SIMDE_FLOAT16_VALUE(36.32), SIMDE_FLOAT16_VALUE(38.43), SIMDE_FLOAT16_VALUE(-15.44) },
       {  SIMDE_FLOAT16_VALUE(14.57), SIMDE_FLOAT16_VALUE(-33.72), SIMDE_FLOAT16_VALUE(17.48), SIMDE_FLOAT16_VALUE(1.03),
        SIMDE_FLOAT16_VALUE(39.90), SIMDE_FLOAT16_VALUE(12.95), SIMDE_FLOAT16_VALUE(-24.90), SIMDE_FLOAT16_VALUE(22.89) },
       {  SIMDE_FLOAT16_VALUE(33.49), SIMDE_FLOAT16_VALUE(-29.52), SIMDE_FLOAT16_VALUE(-42.35), SIMDE_FLOAT16_VALUE(9.92),
        SIMDE_FLOAT16_VALUE(-19.29), SIMDE_FLOAT16_VALUE(-3.97), SIMDE_FLOAT16_VALUE(39.49), SIMDE_FLOAT16_VALUE(34.87) } } },
   { { {  SIMDE_FLOAT16_VALUE(-8.17), SIMDE_FLOAT16_VALUE(20.98), SIMDE_FLOAT16_VALUE(-36.48), SIMDE_FLOAT16_VALUE(-2.58),
        SIMDE_FLOAT16_VALUE(45.57), SIMDE_FLOAT16_VALUE(1.57), SIMDE_FLOAT16_VALUE(-6.19), SIMDE_FLOAT16_VALUE(-12.44) },
       {  SIMDE_FLOAT16_VALUE(45.85), SIMDE_FLOAT16_VALUE(24.95), SIMDE_FLOAT16_VALUE(28.89), SIMDE_FLOAT16_VALUE(49.69),
        SIMDE_FLOAT16_VALUE(1.21), SIMDE_FLOAT16_VALUE(-33.38), SIMDE_FLOAT16_VALUE(-40.61), SIMDE_FLOAT16_VALUE(21.68) },
       {  SIMDE_FLOAT16_VALUE(46.23), SIMDE_FLOAT16_VALUE(-16.19), SIMDE_FLOAT16_VALUE(-35.91), SIMDE_FLOAT16_VALUE(43.87),
        SIMDE_FLOAT16_VALUE(30.36), SIMDE_FLOAT16_VALUE(-1.03), SIMDE_FLOAT16_VALUE(19.56), SIMDE_FLOAT16_VALUE(33.86) },
       {  SIMDE_FLOAT16_VALUE(-24.84), SIMDE_FLOAT16_VALUE(13.50), SIMDE_FLOAT16_VALUE(29.52), SIMDE_FLOAT16_VALUE(41.09),
        SIMDE_FLOAT16_VALUE(-18.40), SIMDE_FLOAT16_VALUE(40.70), SIMDE_FLOAT16_VALUE(0.08), SIMDE_FLOAT16_VALUE(19.83) } },
       {  SIMDE_FLOAT16_VALUE(38.14), SIMDE_FLOAT16_VALUE(-31.15), SIMDE_FLOAT16_VALUE(18.94), SIMDE_FLOAT16_VALUE(21.21)},
     { {  SIMDE_FLOAT16_VALUE(-8.17), SIMDE_FLOAT16_VALUE(20.98), SIMDE_FLOAT16_VALUE(-36.48), SIMDE_FLOAT16_VALUE(-2.58),
        SIMDE_FLOAT16_VALUE(38.14), SIMDE_FLOAT16_VALUE(1.57), SIMDE_FLOAT16_VALUE(-6.19), SIMDE_FLOAT16_VALUE(-12.44) },
       {  SIMDE_FLOAT16_VALUE(45.85), SIMDE_FLOAT16_VALUE(24.95), SIMDE_FLOAT16_VALUE(28.89), SIMDE_FLOAT16_VALUE(49.69),
        SIMDE_FLOAT16_VALUE(-31.15), SIMDE_FLOAT16_VALUE(-33.38), SIMDE_FLOAT16_VALUE(-40.61), SIMDE_FLOAT16_VALUE(21.68) },
       {  SIMDE_FLOAT16_VALUE(46.23), SIMDE_FLOAT16_VALUE(-16.19), SIMDE_FLOAT16_VALUE(-35.91), SIMDE_FLOAT16_VALUE(43.87),
        SIMDE_FLOAT16_VALUE(18.94), SIMDE_FLOAT16_VALUE(-1.03), SIMDE_FLOAT16_VALUE(19.56), SIMDE_FLOAT16_VALUE(33.86) },
       {  SIMDE_FLOAT16_VALUE(-24.84), SIMDE_FLOAT16_VALUE(13.50), SIMDE_FLOAT16_VALUE(29.52), SIMDE_FLOAT16_VALUE(41.09),
        SIMDE_FLOAT16_VALUE(21.21), SIMDE_FLOAT16_VALUE(40.70), SIMDE_FLOAT16_VALUE(0.08), SIMDE_FLOAT16_VALUE(19.83) } } },
   { { {  SIMDE_FLOAT16_VALUE(32.92), SIMDE_FLOAT16_VALUE(-0.80), SIMDE_FLOAT16_VALUE(-42.65), SIMDE_FLOAT16_VALUE(-15.22),
        SIMDE_FLOAT16_VALUE(-16.39), SIMDE_FLOAT16_VALUE(11.52), SIMDE_FLOAT16_VALUE(-4.14), SIMDE_FLOAT16_VALUE(8.87) },
       {  SIMDE_FLOAT16_VALUE(-35.81), SIMDE_FLOAT16_VALUE(12.74), SIMDE_FLOAT16_VALUE(-12.60), SIMDE_FLOAT16_VALUE(21.59),
        SIMDE_FLOAT16_VALUE(-11.53), SIMDE_FLOAT16_VALUE(44.02), SIMDE_FLOAT16_VALUE(30.30), SIMDE_FLOAT16_VALUE(43.42) },
       {  SIMDE_FLOAT16_VALUE(16.67), SIMDE_FLOAT16_VALUE(0.23), SIMDE_FLOAT16_VALUE(-4.88), SIMDE_FLOAT16_VALUE(-5.00),
        SIMDE_FLOAT16_VALUE(36.67), SIMDE_FLOAT16_VALUE(43.56), SIMDE_FLOAT16_VALUE(-15.15), SIMDE_FLOAT16_VALUE(-34.82) },
       {  SIMDE_FLOAT16_VALUE(-22.22), SIMDE_FLOAT16_VALUE(-41.78), SIMDE_FLOAT16_VALUE(-15.90), SIMDE_FLOAT16_VALUE(-36.65),
        SIMDE_FLOAT16_VALUE(34.10), SIMDE_FLOAT16_VALUE(22.36), SIMDE_FLOAT16_VALUE(-4.57), SIMDE_FLOAT16_VALUE(-42.90) } },
       {  SIMDE_FLOAT16_VALUE(-30.23), SIMDE_FLOAT16_VALUE(-33.22), SIMDE_FLOAT16_VALUE(14.26), SIMDE_FLOAT16_VALUE(-48.15)},
     { {  SIMDE_FLOAT16_VALUE(32.92), SIMDE_FLOAT16_VALUE(-0.80), SIMDE_FLOAT16_VALUE(-42.65), SIMDE_FLOAT16_VALUE(-15.22),
        SIMDE_FLOAT16_VALUE(-16.39), SIMDE_FLOAT16_VALUE(-30.23), SIMDE_FLOAT16_VALUE(-4.14), SIMDE_FLOAT16_VALUE(8.87) },
       {  SIMDE_FLOAT16_VALUE(-35.81), SIMDE_FLOAT16_VALUE(12.74), SIMDE_FLOAT16_VALUE(-12.60), SIMDE_FLOAT16_VALUE(21.59),
        SIMDE_FLOAT16_VALUE(-11.53), SIMDE_FLOAT16_VALUE(-33.22), SIMDE_FLOAT16_VALUE(30.30), SIMDE_FLOAT16_VALUE(43.42) },
       {  SIMDE_FLOAT16_VALUE(16.67), SIMDE_FLOAT16_VALUE(0.23), SIMDE_FLOAT16_VALUE(-4.88), SIMDE_FLOAT16_VALUE(-5.00),
        SIMDE_FLOAT16_VALUE(36.67), SIMDE_FLOAT16_VALUE(14.26), SIMDE_FLOAT16_VALUE(-15.15), SIMDE_FLOAT16_VALUE(-34.82) },
       {  SIMDE_FLOAT16_VALUE(-22.22), SIMDE_FLOAT16_VALUE(-41.78), SIMDE_FLOAT16_VALUE(-15.90), SIMDE_FLOAT16_VALUE(-36.65),
        SIMDE_FLOAT16_VALUE(34.10), SIMDE_FLOAT16_VALUE(-48.15), SIMDE_FLOAT16_VALUE(-4.57), SIMDE_FLOAT16_VALUE(-42.90) } } },
   { { {  SIMDE_FLOAT16_VALUE(30.57), SIMDE_FLOAT16_VALUE(-2.63), SIMDE_FLOAT16_VALUE(-44.63), SIMDE_FLOAT16_VALUE(15.88),
        SIMDE_FLOAT16_VALUE(10.45), SIMDE_FLOAT16_VALUE(45.63), SIMDE_FLOAT16_VALUE(9.06), SIMDE_FLOAT16_VALUE(-38.74) },
       {  SIMDE_FLOAT16_VALUE(-26.14), SIMDE_FLOAT16_VALUE(24.78), SIMDE_FLOAT16_VALUE(19.94), SIMDE_FLOAT16_VALUE(-27.09),
        SIMDE_FLOAT16_VALUE(42.67), SIMDE_FLOAT16_VALUE(1.81), SIMDE_FLOAT16_VALUE(16.33), SIMDE_FLOAT16_VALUE(-11.55) },
       {  SIMDE_FLOAT16_VALUE(-48.80), SIMDE_FLOAT16_VALUE(16.42), SIMDE_FLOAT16_VALUE(-47.87), SIMDE_FLOAT16_VALUE(-31.96),
        SIMDE_FLOAT16_VALUE(22.97), SIMDE_FLOAT16_VALUE(-48.97), SIMDE_FLOAT16_VALUE(-19.78), SIMDE_FLOAT16_VALUE(-5.38) },
       {  SIMDE_FLOAT16_VALUE(-15.38), SIMDE_FLOAT16_VALUE(21.21), SIMDE_FLOAT16_VALUE(23.35), SIMDE_FLOAT16_VALUE(0.40),
        SIMDE_FLOAT16_VALUE(25.56), SIMDE_FLOAT16_VALUE(31.88), SIMDE_FLOAT16_VALUE(34.93), SIMDE_FLOAT16_VALUE(30.41) } },
       {  SIMDE_FLOAT16_VALUE(-17.21), SIMDE_FLOAT16_VALUE(-48.48), SIMDE_FLOAT16_VALUE(-7.06), SIMDE_FLOAT16_VALUE(-26.40)},
     { {  SIMDE_FLOAT16_VALUE(30.57), SIMDE_FLOAT16_VALUE(-2.63), SIMDE_FLOAT16_VALUE(-44.63), SIMDE_FLOAT16_VALUE(15.88),
        SIMDE_FLOAT16_VALUE(10.45), SIMDE_FLOAT16_VALUE(45.63), SIMDE_FLOAT16_VALUE(-17.21), SIMDE_FLOAT16_VALUE(-38.74) },
       {  SIMDE_FLOAT16_VALUE(-26.14), SIMDE_FLOAT16_VALUE(24.78), SIMDE_FLOAT16_VALUE(19.94), SIMDE_FLOAT16_VALUE(-27.09),
        SIMDE_FLOAT16_VALUE(42.67), SIMDE_FLOAT16_VALUE(1.81), SIMDE_FLOAT16_VALUE(-48.48), SIMDE_FLOAT16_VALUE(-11.55) },
       {  SIMDE_FLOAT16_VALUE(-48.80), SIMDE_FLOAT16_VALUE(16.42), SIMDE_FLOAT16_VALUE(-47.87), SIMDE_FLOAT16_VALUE(-31.96),
        SIMDE_FLOAT16_VALUE(22.97), SIMDE_FLOAT16_VALUE(-48.97), SIMDE_FLOAT16_VALUE(-7.06), SIMDE_FLOAT16_VALUE(-5.38) },
       {  SIMDE_FLOAT16_VALUE(-15.38), SIMDE_FLOAT16_VALUE(21.21), SIMDE_FLOAT16_VALUE(23.35), SIMDE_FLOAT16_VALUE(0.40),
        SIMDE_FLOAT16_VALUE(25.56), SIMDE_FLOAT16_VALUE(31.88), SIMDE_FLOAT16_VALUE(-26.40), SIMDE_FLOAT16_VALUE(30.41) } } },
   { { {  SIMDE_FLOAT16_VALUE(9.17), SIMDE_FLOAT16_VALUE(21.02), SIMDE_FLOAT16_VALUE(-31.99), SIMDE_FLOAT16_VALUE(40.72),
        SIMDE_FLOAT16_VALUE(-48.40), SIMDE_FLOAT16_VALUE(-16.85), SIMDE_FLOAT16_VALUE(-28.29), SIMDE_FLOAT16_VALUE(-25.87) },
       {  SIMDE_FLOAT16_VALUE(10.04), SIMDE_FLOAT16_VALUE(11.19), SIMDE_FLOAT16_VALUE(-9.39), SIMDE_FLOAT16_VALUE(43.50),
        SIMDE_FLOAT16_VALUE(20.72), SIMDE_FLOAT16_VALUE(16.81), SIMDE_FLOAT16_VALUE(31.83), SIMDE_FLOAT16_VALUE(24.46) },
       {  SIMDE_FLOAT16_VALUE(-6.31), SIMDE_FLOAT16_VALUE(-39.46), SIMDE_FLOAT16_VALUE(-33.35), SIMDE_FLOAT16_VALUE(11.15),
        SIMDE_FLOAT16_VALUE(-7.05), SIMDE_FLOAT16_VALUE(26.22), SIMDE_FLOAT16_VALUE(-36.64), SIMDE_FLOAT16_VALUE(37.19) },
       {  SIMDE_FLOAT16_VALUE(13.89), SIMDE_FLOAT16_VALUE(26.04), SIMDE_FLOAT16_VALUE(-44.10), SIMDE_FLOAT16_VALUE(37.22),
        SIMDE_FLOAT16_VALUE(10.55), SIMDE_FLOAT16_VALUE(-21.52), SIMDE_FLOAT16_VALUE(-10.01), SIMDE_FLOAT16_VALUE(16.56) } },
       {  SIMDE_FLOAT16_VALUE(-30.72), SIMDE_FLOAT16_VALUE(-43.73), SIMDE_FLOAT16_VALUE(28.26), SIMDE_FLOAT16_VALUE(-33.82)},
     { {  SIMDE_FLOAT16_VALUE(9.17), SIMDE_FLOAT16_VALUE(21.02), SIMDE_FLOAT16_VALUE(-31.99), SIMDE_FLOAT16_VALUE(40.72),
        SIMDE_FLOAT16_VALUE(-48.40), SIMDE_FLOAT16_VALUE(-16.85), SIMDE_FLOAT16_VALUE(-28.29), SIMDE_FLOAT16_VALUE(-30.72) },
       {  SIMDE_FLOAT16_VALUE(10.04), SIMDE_FLOAT16_VALUE(11.19), SIMDE_FLOAT16_VALUE(-9.39), SIMDE_FLOAT16_VALUE(43.50),
        SIMDE_FLOAT16_VALUE(20.72), SIMDE_FLOAT16_VALUE(16.81), SIMDE_FLOAT16_VALUE(31.83), SIMDE_FLOAT16_VALUE(-43.73) },
       {  SIMDE_FLOAT16_VALUE(-6.31), SIMDE_FLOAT16_VALUE(-39.46), SIMDE_FLOAT16_VALUE(-33.35), SIMDE_FLOAT16_VALUE(11.15),
        SIMDE_FLOAT16_VALUE(-7.05), SIMDE_FLOAT16_VALUE(26.22), SIMDE_FLOAT16_VALUE(-36.64), SIMDE_FLOAT16_VALUE(28.26) },
       {  SIMDE_FLOAT16_VALUE(13.89), SIMDE_FLOAT16_VALUE(26.04), SIMDE_FLOAT16_VALUE(-44.10), SIMDE_FLOAT16_VALUE(37.22),
        SIMDE_FLOAT16_VALUE(10.55), SIMDE_FLOAT16_VALUE(-21.52), SIMDE_FLOAT16_VALUE(-10.01), SIMDE_FLOAT16_VALUE(-33.82) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8x4_t r;
    simde_float16x8x4_t src = {
        {simde_vld1q_f16(test_vec[i].src[0]), simde_vld1q_f16(test_vec[i].src[1]),
         simde_vld1q_f16(test_vec[i].src[2]), simde_vld1q_f16(test_vec[i].src[3])}};
    simde_float16x8x4_t expected = {
        {simde_vld1q_f16(test_vec[i].r[0]), simde_vld1q_f16(test_vec[i].r[1]),
         simde_vld1q_f16(test_vec[i].r[2]), simde_vld1q_f16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_8_(simde_vld4q_lane_f16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_f16x8(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f16x8(r.val[1], expected.val[1], 1);
    simde_test_arm_neon_assert_equal_f16x8(r.val[2], expected.val[2], 1);
    simde_test_arm_neon_assert_equal_f16x8(r.val[3], expected.val[3], 1);
  }

  return 0;
}

static int
test_simde_vld4q_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t src[4][4];
    simde_float32_t buf[4];
    simde_float32_t r[4][4];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(    19.27), SIMDE_FLOAT32_C(    11.72), SIMDE_FLOAT32_C(   -12.20), SIMDE_FLOAT32_C(   -36.38) },
          { SIMDE_FLOAT32_C(   -37.63), SIMDE_FLOAT32_C(   -45.48), SIMDE_FLOAT32_C(   -45.93), SIMDE_FLOAT32_C(    47.64) },
          { SIMDE_FLOAT32_C(   -32.47), SIMDE_FLOAT32_C(    33.82), SIMDE_FLOAT32_C(    49.51), SIMDE_FLOAT32_C(   -22.89) },
          { SIMDE_FLOAT32_C(   -39.76), SIMDE_FLOAT32_C(    33.96), SIMDE_FLOAT32_C(    29.59), SIMDE_FLOAT32_C(   -38.64) } },
      { SIMDE_FLOAT32_C(   -24.64), SIMDE_FLOAT32_C(   -43.67), SIMDE_FLOAT32_C(    96.38), SIMDE_FLOAT32_C(    53.18) },
        { { SIMDE_FLOAT32_C(   -24.64), SIMDE_FLOAT32_C(    11.72), SIMDE_FLOAT32_C(   -12.20), SIMDE_FLOAT32_C(   -36.38) },
          { SIMDE_FLOAT32_C(   -43.67), SIMDE_FLOAT32_C(   -45.48), SIMDE_FLOAT32_C(   -45.93), SIMDE_FLOAT32_C(    47.64) },
          { SIMDE_FLOAT32_C(    96.38), SIMDE_FLOAT32_C(    33.82), SIMDE_FLOAT32_C(    49.51), SIMDE_FLOAT32_C(   -22.89) },
          { SIMDE_FLOAT32_C(    53.18), SIMDE_FLOAT32_C(    33.96), SIMDE_FLOAT32_C(    29.59), SIMDE_FLOAT32_C(   -38.64) } },
    },
    {
        { { SIMDE_FLOAT32_C(    27.35), SIMDE_FLOAT32_C(   -28.81), SIMDE_FLOAT32_C(    36.44), SIMDE_FLOAT32_C(   -23.07) },
          { SIMDE_FLOAT32_C(    41.76), SIMDE_FLOAT32_C(    -5.78), SIMDE_FLOAT32_C(    33.86), SIMDE_FLOAT32_C(   -14.17) },
          { SIMDE_FLOAT32_C(   -18.89), SIMDE_FLOAT32_C(    13.92), SIMDE_FLOAT32_C(    18.17), SIMDE_FLOAT32_C(   -49.62) },
          { SIMDE_FLOAT32_C(   -24.36), SIMDE_FLOAT32_C(   -44.03), SIMDE_FLOAT32_C(   -35.99), SIMDE_FLOAT32_C(   -11.98) } },
      { SIMDE_FLOAT32_C(   -79.03), SIMDE_FLOAT32_C(   -63.84), SIMDE_FLOAT32_C(   -28.69), SIMDE_FLOAT32_C(   -43.97) },
        { { SIMDE_FLOAT32_C(    27.35), SIMDE_FLOAT32_C(   -79.03), SIMDE_FLOAT32_C(    36.44), SIMDE_FLOAT32_C(   -23.07) },
          { SIMDE_FLOAT32_C(    41.76), SIMDE_FLOAT32_C(   -63.84), SIMDE_FLOAT32_C(    33.86), SIMDE_FLOAT32_C(   -14.17) },
          { SIMDE_FLOAT32_C(   -18.89), SIMDE_FLOAT32_C(   -28.69), SIMDE_FLOAT32_C(    18.17), SIMDE_FLOAT32_C(   -49.62) },
          { SIMDE_FLOAT32_C(   -24.36), SIMDE_FLOAT32_C(   -43.97), SIMDE_FLOAT32_C(   -35.99), SIMDE_FLOAT32_C(   -11.98) } },
    },
    {
        { { SIMDE_FLOAT32_C(   -48.10), SIMDE_FLOAT32_C(   -14.83), SIMDE_FLOAT32_C(     5.13), SIMDE_FLOAT32_C(   -37.86) },
          { SIMDE_FLOAT32_C(   -30.87), SIMDE_FLOAT32_C(   -15.28), SIMDE_FLOAT32_C(   -26.50), SIMDE_FLOAT32_C(     6.81) },
          { SIMDE_FLOAT32_C(    12.88), SIMDE_FLOAT32_C(   -28.31), SIMDE_FLOAT32_C(   -16.60), SIMDE_FLOAT32_C(    -9.77) },
          { SIMDE_FLOAT32_C(    -7.12), SIMDE_FLOAT32_C(   -30.16), SIMDE_FLOAT32_C(    17.17), SIMDE_FLOAT32_C(   -15.36) } },
      { SIMDE_FLOAT32_C(    28.12), SIMDE_FLOAT32_C(     2.05), SIMDE_FLOAT32_C(    40.94), SIMDE_FLOAT32_C(    90.35) },
        { { SIMDE_FLOAT32_C(   -48.10), SIMDE_FLOAT32_C(   -14.83), SIMDE_FLOAT32_C(    28.12), SIMDE_FLOAT32_C(   -37.86) },
          { SIMDE_FLOAT32_C(   -30.87), SIMDE_FLOAT32_C(   -15.28), SIMDE_FLOAT32_C(     2.05), SIMDE_FLOAT32_C(     6.81) },
          { SIMDE_FLOAT32_C(    12.88), SIMDE_FLOAT32_C(   -28.31), SIMDE_FLOAT32_C(    40.94), SIMDE_FLOAT32_C(    -9.77) },
          { SIMDE_FLOAT32_C(    -7.12), SIMDE_FLOAT32_C(   -30.16), SIMDE_FLOAT32_C(    90.35), SIMDE_FLOAT32_C(   -15.36) } },
    },
    {
        { { SIMDE_FLOAT32_C(   -35.05), SIMDE_FLOAT32_C(   -11.36), SIMDE_FLOAT32_C(    45.56), SIMDE_FLOAT32_C(    -9.41) },
          { SIMDE_FLOAT32_C(    -5.39), SIMDE_FLOAT32_C(   -40.44), SIMDE_FLOAT32_C(    28.61), SIMDE_FLOAT32_C(     5.10) },
          { SIMDE_FLOAT32_C(   -22.36), SIMDE_FLOAT32_C(   -35.74), SIMDE_FLOAT32_C(    33.11), SIMDE_FLOAT32_C(   -20.46) },
          { SIMDE_FLOAT32_C(    -0.57), SIMDE_FLOAT32_C(   -11.76), SIMDE_FLOAT32_C(    -8.32), SIMDE_FLOAT32_C(    18.56) } },
      { SIMDE_FLOAT32_C(    45.92), SIMDE_FLOAT32_C(    30.37), SIMDE_FLOAT32_C(   -49.27), SIMDE_FLOAT32_C(   -28.32) },
        { { SIMDE_FLOAT32_C(   -35.05), SIMDE_FLOAT32_C(   -11.36), SIMDE_FLOAT32_C(    45.56), SIMDE_FLOAT32_C(    45.92) },
          { SIMDE_FLOAT32_C(    -5.39), SIMDE_FLOAT32_C(   -40.44), SIMDE_FLOAT32_C(    28.61), SIMDE_FLOAT32_C(    30.37) },
          { SIMDE_FLOAT32_C(   -22.36), SIMDE_FLOAT32_C(   -35.74), SIMDE_FLOAT32_C(    33.11), SIMDE_FLOAT32_C(   -49.27) },
          { SIMDE_FLOAT32_C(    -0.57), SIMDE_FLOAT32_C(   -11.76), SIMDE_FLOAT32_C(    -8.32), SIMDE_FLOAT32_C(   -28.32) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x4_t r;
    simde_float32x4x4_t src = {
        {simde_vld1q_f32(test_vec[i].src[0]), simde_vld1q_f32(test_vec[i].src[1]),
         simde_vld1q_f32(test_vec[i].src[2]), simde_vld1q_f32(test_vec[i].src[3])}};
    simde_float32x4x4_t expected = {
        {simde_vld1q_f32(test_vec[i].r[0]), simde_vld1q_f32(test_vec[i].r[1]),
         simde_vld1q_f32(test_vec[i].r[2]), simde_vld1q_f32(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_4_(simde_vld4q_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_f32x4(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], expected.val[1], 1);
    simde_test_arm_neon_assert_equal_f32x4(r.val[2], expected.val[2], 1);
    simde_test_arm_neon_assert_equal_f32x4(r.val[3], expected.val[3], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_float32x4x4_t src = simde_test_arm_neon_random_f32x4x4(-50.0f, 50.0f);
    simde_test_arm_neon_write_f32x4x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_float32_t buf[4];
    simde_test_codegen_random_vf32(4, buf, -100.0f, 100.0f);
    simde_test_codegen_write_vf32(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float32x4x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld4q_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_f32x4x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t src[4][2];
    simde_float64_t buf[4];
    simde_float64_t r[4][2];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(   -10.58), SIMDE_FLOAT64_C(   -17.83) },
          { SIMDE_FLOAT64_C(    59.36), SIMDE_FLOAT64_C(    53.26) },
          { SIMDE_FLOAT64_C(   -32.00), SIMDE_FLOAT64_C(   -72.88) },
          { SIMDE_FLOAT64_C(    -8.63), SIMDE_FLOAT64_C(   -98.94) } },
      { SIMDE_FLOAT64_C(   -55.98), SIMDE_FLOAT64_C(   -22.55), SIMDE_FLOAT64_C(    21.40), SIMDE_FLOAT64_C(     2.22) },
        { { SIMDE_FLOAT64_C(   -55.98), SIMDE_FLOAT64_C(   -17.83) },
          { SIMDE_FLOAT64_C(   -22.55), SIMDE_FLOAT64_C(    53.26) },
          { SIMDE_FLOAT64_C(    21.40), SIMDE_FLOAT64_C(   -72.88) },
          { SIMDE_FLOAT64_C(     2.22), SIMDE_FLOAT64_C(   -98.94) } },
    },
    {
        { { SIMDE_FLOAT64_C(    60.29), SIMDE_FLOAT64_C(    60.20) },
          { SIMDE_FLOAT64_C(   -69.98), SIMDE_FLOAT64_C(    34.61) },
          { SIMDE_FLOAT64_C(    66.90), SIMDE_FLOAT64_C(   -35.54) },
          { SIMDE_FLOAT64_C(    19.63), SIMDE_FLOAT64_C(    63.63) } },
      { SIMDE_FLOAT64_C(   -21.98), SIMDE_FLOAT64_C(    98.64), SIMDE_FLOAT64_C(   -95.62), SIMDE_FLOAT64_C(    54.86) },
        { { SIMDE_FLOAT64_C(   -21.98), SIMDE_FLOAT64_C(    60.20) },
          { SIMDE_FLOAT64_C(    98.64), SIMDE_FLOAT64_C(    34.61) },
          { SIMDE_FLOAT64_C(   -95.62), SIMDE_FLOAT64_C(   -35.54) },
          { SIMDE_FLOAT64_C(    54.86), SIMDE_FLOAT64_C(    63.63) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x4_t src = {
        {simde_vld1q_f64(test_vec[i].src[0]), simde_vld1q_f64(test_vec[i].src[1]),
         simde_vld1q_f64(test_vec[i].src[2]), simde_vld1q_f64(test_vec[i].src[3])}};
    simde_float64x2x4_t r = simde_vld4q_lane_f64(test_vec[i].buf, src, 0);

    simde_float64x2x4_t expected = {
        {simde_vld1q_f64(test_vec[i].r[0]), simde_vld1q_f64(test_vec[i].r[1]),
         simde_vld1q_f64(test_vec[i].r[2]), simde_vld1q_f64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_f64x2(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f64x2(r.val[1], expected.val[1], 1);
    simde_test_arm_neon_assert_equal_f64x2(r.val[2], expected.val[2], 1);
    simde_test_arm_neon_assert_equal_f64x2(r.val[3], expected.val[3], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64x2x4_t src = simde_test_arm_neon_random_f64x2x4(-100.0, 100.0);
    simde_test_arm_neon_write_f64x2x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_float64_t buf[4];
    simde_test_codegen_random_vf64(4, buf, -100.0, 100.0);
    simde_test_codegen_write_vf64(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float64x2x4_t r = simde_vld4q_lane_f64(buf, src, 0);
    simde_test_arm_neon_write_f64x2x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t src[4][8];
    simde_poly8_t buf[4];
    simde_poly8_t r[4][8];
  } test_vec[] = {
    {
        { { SIMDE_POLY8_C(117), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(134), SIMDE_POLY8_C(112), SIMDE_POLY8_C(144), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 69) },
          { SIMDE_POLY8_C( 36), SIMDE_POLY8_C(194), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(228), SIMDE_POLY8_C(  1), SIMDE_POLY8_C( 38), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(146) },
          { SIMDE_POLY8_C(113), SIMDE_POLY8_C(220), SIMDE_POLY8_C(108), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(208), SIMDE_POLY8_C(110), SIMDE_POLY8_C(202), SIMDE_POLY8_C(158) },
          { SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(247), SIMDE_POLY8_C(164), SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(196), SIMDE_POLY8_C(204) } },
      { SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 74), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(236) },
        { { SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(134), SIMDE_POLY8_C(112), SIMDE_POLY8_C(144), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 69) },
          { SIMDE_POLY8_C( 74), SIMDE_POLY8_C(194), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(228), SIMDE_POLY8_C(  1), SIMDE_POLY8_C( 38), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(146) },
          { SIMDE_POLY8_C( 60), SIMDE_POLY8_C(220), SIMDE_POLY8_C(108), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(208), SIMDE_POLY8_C(110), SIMDE_POLY8_C(202), SIMDE_POLY8_C(158) },
          { SIMDE_POLY8_C(236), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(247), SIMDE_POLY8_C(164), SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(196), SIMDE_POLY8_C(204) } },
    },
    {
        { { SIMDE_POLY8_C(221), SIMDE_POLY8_C(138), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(  1), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 77) },
          { SIMDE_POLY8_C(111), SIMDE_POLY8_C(248), SIMDE_POLY8_C(223), SIMDE_POLY8_C(225), SIMDE_POLY8_C(212), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(248), SIMDE_POLY8_C(164) },
          { SIMDE_POLY8_C(186), SIMDE_POLY8_C(194), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(  7), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(165), SIMDE_POLY8_C( 94) },
          { SIMDE_POLY8_C(130), SIMDE_POLY8_C(106), SIMDE_POLY8_C( 43), SIMDE_POLY8_C(223), SIMDE_POLY8_C(180), SIMDE_POLY8_C(103), SIMDE_POLY8_C(203), SIMDE_POLY8_C(146) } },
      { SIMDE_POLY8_C(241), SIMDE_POLY8_C(253), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 61) },
        { { SIMDE_POLY8_C(221), SIMDE_POLY8_C(241), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(  1), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 77) },
          { SIMDE_POLY8_C(111), SIMDE_POLY8_C(253), SIMDE_POLY8_C(223), SIMDE_POLY8_C(225), SIMDE_POLY8_C(212), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(248), SIMDE_POLY8_C(164) },
          { SIMDE_POLY8_C(186), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(  7), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(165), SIMDE_POLY8_C( 94) },
          { SIMDE_POLY8_C(130), SIMDE_POLY8_C( 61), SIMDE_POLY8_C( 43), SIMDE_POLY8_C(223), SIMDE_POLY8_C(180), SIMDE_POLY8_C(103), SIMDE_POLY8_C(203), SIMDE_POLY8_C(146) } },
    },
    {
        { { SIMDE_POLY8_C( 71), SIMDE_POLY8_C(121), SIMDE_POLY8_C(139), SIMDE_POLY8_C(182), SIMDE_POLY8_C(114), SIMDE_POLY8_C(106), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 70) },
          { SIMDE_POLY8_C(182), SIMDE_POLY8_C(143), SIMDE_POLY8_C(235), SIMDE_POLY8_C(112), SIMDE_POLY8_C( 81), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 88) },
          { SIMDE_POLY8_C(103), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(183), SIMDE_POLY8_C(233), SIMDE_POLY8_C(129), SIMDE_POLY8_C(226), SIMDE_POLY8_C(200), SIMDE_POLY8_C( 53) },
          { SIMDE_POLY8_C( 73), SIMDE_POLY8_C(148), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(120), SIMDE_POLY8_C(216) } },
      { SIMDE_POLY8_C(212), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(143), SIMDE_POLY8_C( 70) },
        { { SIMDE_POLY8_C( 71), SIMDE_POLY8_C(121), SIMDE_POLY8_C(212), SIMDE_POLY8_C(182), SIMDE_POLY8_C(114), SIMDE_POLY8_C(106), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 70) },
          { SIMDE_POLY8_C(182), SIMDE_POLY8_C(143), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(112), SIMDE_POLY8_C( 81), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 88) },
          { SIMDE_POLY8_C(103), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(143), SIMDE_POLY8_C(233), SIMDE_POLY8_C(129), SIMDE_POLY8_C(226), SIMDE_POLY8_C(200), SIMDE_POLY8_C( 53) },
          { SIMDE_POLY8_C( 73), SIMDE_POLY8_C(148), SIMDE_POLY8_C( 70), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(120), SIMDE_POLY8_C(216) } },
    },
    {
        { { SIMDE_POLY8_C(110), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(141), SIMDE_POLY8_C( 36), SIMDE_POLY8_C(182), SIMDE_POLY8_C(120), SIMDE_POLY8_C(149), SIMDE_POLY8_C(  7) },
          { SIMDE_POLY8_C(165), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 96), SIMDE_POLY8_C( 12), SIMDE_POLY8_C( 29), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(246), SIMDE_POLY8_C(158) },
          { SIMDE_POLY8_C(249), SIMDE_POLY8_C(190), SIMDE_POLY8_C(212), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(155), SIMDE_POLY8_C(125), SIMDE_POLY8_C(228) },
          { SIMDE_POLY8_C(246), SIMDE_POLY8_C(246), SIMDE_POLY8_C(188), SIMDE_POLY8_C(203), SIMDE_POLY8_C(249), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(103) } },
      { SIMDE_POLY8_C(114), SIMDE_POLY8_C(158), SIMDE_POLY8_C(140), SIMDE_POLY8_C( 40) },
        { { SIMDE_POLY8_C(110), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(141), SIMDE_POLY8_C(114), SIMDE_POLY8_C(182), SIMDE_POLY8_C(120), SIMDE_POLY8_C(149), SIMDE_POLY8_C(  7) },
          { SIMDE_POLY8_C(165), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(158), SIMDE_POLY8_C( 29), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(246), SIMDE_POLY8_C(158) },
          { SIMDE_POLY8_C(249), SIMDE_POLY8_C(190), SIMDE_POLY8_C(212), SIMDE_POLY8_C(140), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(155), SIMDE_POLY8_C(125), SIMDE_POLY8_C(228) },
          { SIMDE_POLY8_C(246), SIMDE_POLY8_C(246), SIMDE_POLY8_C(188), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(249), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(103) } },
    },
    {
        { { SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 47), SIMDE_POLY8_C(188), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(143), SIMDE_POLY8_C(200), SIMDE_POLY8_C( 69) },
          { SIMDE_POLY8_C(166), SIMDE_POLY8_C(190), SIMDE_POLY8_C(227), SIMDE_POLY8_C(159), SIMDE_POLY8_C(125), SIMDE_POLY8_C(183), SIMDE_POLY8_C(226), SIMDE_POLY8_C(207) },
          { SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(112), SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 79) },
          { SIMDE_POLY8_C(187), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(196), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(219) } },
      { SIMDE_POLY8_C( 99), SIMDE_POLY8_C(133), SIMDE_POLY8_C(151), SIMDE_POLY8_C(139) },
        { { SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 47), SIMDE_POLY8_C(188), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(143), SIMDE_POLY8_C(200), SIMDE_POLY8_C( 69) },
          { SIMDE_POLY8_C(166), SIMDE_POLY8_C(190), SIMDE_POLY8_C(227), SIMDE_POLY8_C(159), SIMDE_POLY8_C(133), SIMDE_POLY8_C(183), SIMDE_POLY8_C(226), SIMDE_POLY8_C(207) },
          { SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(151), SIMDE_POLY8_C(112), SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 79) },
          { SIMDE_POLY8_C(187), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(219) } },
    },
    {
        { { SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(208), SIMDE_POLY8_C(187), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(155) },
          { SIMDE_POLY8_C(107), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(106), SIMDE_POLY8_C(190), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(241) },
          { SIMDE_POLY8_C(142), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 64), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(247), SIMDE_POLY8_C(119), SIMDE_POLY8_C(  6) },
          { SIMDE_POLY8_C( 57), SIMDE_POLY8_C(204), SIMDE_POLY8_C(225), SIMDE_POLY8_C(157), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(120), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(102) } },
      { SIMDE_POLY8_C(216), SIMDE_POLY8_C(248), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(246) },
        { { SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(208), SIMDE_POLY8_C(187), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(216), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(155) },
          { SIMDE_POLY8_C(107), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(106), SIMDE_POLY8_C(190), SIMDE_POLY8_C(156), SIMDE_POLY8_C(248), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(241) },
          { SIMDE_POLY8_C(142), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 64), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(119), SIMDE_POLY8_C(  6) },
          { SIMDE_POLY8_C( 57), SIMDE_POLY8_C(204), SIMDE_POLY8_C(225), SIMDE_POLY8_C(157), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(246), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(102) } },
    },
    {
        { { SIMDE_POLY8_C(171), SIMDE_POLY8_C(123), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(184), SIMDE_POLY8_C(251), SIMDE_POLY8_C(212), SIMDE_POLY8_C( 84) },
          { SIMDE_POLY8_C( 25), SIMDE_POLY8_C(220), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(167), SIMDE_POLY8_C(248), SIMDE_POLY8_C(134), SIMDE_POLY8_C(241), SIMDE_POLY8_C( 58) },
          { SIMDE_POLY8_C(125), SIMDE_POLY8_C(104), SIMDE_POLY8_C( 64), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 52), SIMDE_POLY8_C( 34), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(134) },
          { SIMDE_POLY8_C(154), SIMDE_POLY8_C(123), SIMDE_POLY8_C(236), SIMDE_POLY8_C(114), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(104), SIMDE_POLY8_C( 31) } },
      { SIMDE_POLY8_C(136), SIMDE_POLY8_C(249), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 64) },
        { { SIMDE_POLY8_C(171), SIMDE_POLY8_C(123), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(184), SIMDE_POLY8_C(251), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 84) },
          { SIMDE_POLY8_C( 25), SIMDE_POLY8_C(220), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(167), SIMDE_POLY8_C(248), SIMDE_POLY8_C(134), SIMDE_POLY8_C(249), SIMDE_POLY8_C( 58) },
          { SIMDE_POLY8_C(125), SIMDE_POLY8_C(104), SIMDE_POLY8_C( 64), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 52), SIMDE_POLY8_C( 34), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(134) },
          { SIMDE_POLY8_C(154), SIMDE_POLY8_C(123), SIMDE_POLY8_C(236), SIMDE_POLY8_C(114), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 64), SIMDE_POLY8_C( 31) } },
    },
    {
        { { SIMDE_POLY8_C(245), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(148), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(230), SIMDE_POLY8_C(218), SIMDE_POLY8_C(182), SIMDE_POLY8_C(222) },
          { SIMDE_POLY8_C( 96), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(221), SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 88), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 67) },
          { SIMDE_POLY8_C(122), SIMDE_POLY8_C(231), SIMDE_POLY8_C(201), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(181), SIMDE_POLY8_C(135), SIMDE_POLY8_C(214) },
          { SIMDE_POLY8_C(194), SIMDE_POLY8_C(240), SIMDE_POLY8_C(245), SIMDE_POLY8_C( 75), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(139), SIMDE_POLY8_C(222) } },
      { SIMDE_POLY8_C( 52), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(237), SIMDE_POLY8_C( 26) },
        { { SIMDE_POLY8_C(245), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(148), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(230), SIMDE_POLY8_C(218), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 52) },
          { SIMDE_POLY8_C( 96), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(221), SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 88), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 32) },
          { SIMDE_POLY8_C(122), SIMDE_POLY8_C(231), SIMDE_POLY8_C(201), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(181), SIMDE_POLY8_C(135), SIMDE_POLY8_C(237) },
          { SIMDE_POLY8_C(194), SIMDE_POLY8_C(240), SIMDE_POLY8_C(245), SIMDE_POLY8_C( 75), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 26) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8x4_t r;
    simde_poly8x8x4_t src = {
        {simde_vld1_p8(test_vec[i].src[0]), simde_vld1_p8(test_vec[i].src[1]),
         simde_vld1_p8(test_vec[i].src[2]), simde_vld1_p8(test_vec[i].src[3])}};
    simde_poly8x8x4_t expected = {
        {simde_vld1_p8(test_vec[i].r[0]), simde_vld1_p8(test_vec[i].r[1]),
         simde_vld1_p8(test_vec[i].r[2]), simde_vld1_p8(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_8_(simde_vld4_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);


    simde_test_arm_neon_assert_equal_p8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8x4_t src = simde_test_arm_neon_random_p8x8x4();
    simde_poly8_t buf[4];
    simde_poly8x8x4_t r;
    simde_test_arm_neon_write_p8x8x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp8(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_8_(simde_vld4_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p8x8x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t src[4][4];
    simde_poly16_t buf[4];
    simde_poly16_t r[4][4];
  } test_vec[] = {
    {
        { { SIMDE_POLY16_C(51978), SIMDE_POLY16_C(  842), SIMDE_POLY16_C(19122), SIMDE_POLY16_C( 1111) },
          { SIMDE_POLY16_C(64538), SIMDE_POLY16_C(59508), SIMDE_POLY16_C(24002), SIMDE_POLY16_C(17590) },
          { SIMDE_POLY16_C(39624), SIMDE_POLY16_C(38972), SIMDE_POLY16_C(26313), SIMDE_POLY16_C(24858) },
          { SIMDE_POLY16_C(58101), SIMDE_POLY16_C(29864), SIMDE_POLY16_C( 4542), SIMDE_POLY16_C(51367) } },
      { SIMDE_POLY16_C(61917), SIMDE_POLY16_C(36812), SIMDE_POLY16_C(63644), SIMDE_POLY16_C(61703) },
        { { SIMDE_POLY16_C(61917), SIMDE_POLY16_C(  842), SIMDE_POLY16_C(19122), SIMDE_POLY16_C( 1111) },
          { SIMDE_POLY16_C(36812), SIMDE_POLY16_C(59508), SIMDE_POLY16_C(24002), SIMDE_POLY16_C(17590) },
          { SIMDE_POLY16_C(63644), SIMDE_POLY16_C(38972), SIMDE_POLY16_C(26313), SIMDE_POLY16_C(24858) },
          { SIMDE_POLY16_C(61703), SIMDE_POLY16_C(29864), SIMDE_POLY16_C( 4542), SIMDE_POLY16_C(51367) } },
    },
    {
        { { SIMDE_POLY16_C( 9019), SIMDE_POLY16_C(21908), SIMDE_POLY16_C( 2079), SIMDE_POLY16_C(57917) },
          { SIMDE_POLY16_C(62565), SIMDE_POLY16_C(11558), SIMDE_POLY16_C(25230), SIMDE_POLY16_C(22469) },
          { SIMDE_POLY16_C(57288), SIMDE_POLY16_C(48824), SIMDE_POLY16_C(24769), SIMDE_POLY16_C(32818) },
          { SIMDE_POLY16_C(55666), SIMDE_POLY16_C(20296), SIMDE_POLY16_C( 5323), SIMDE_POLY16_C( 1758) } },
      { SIMDE_POLY16_C(29240), SIMDE_POLY16_C(22364), SIMDE_POLY16_C(63644), SIMDE_POLY16_C(61703) },
        { { SIMDE_POLY16_C( 9019), SIMDE_POLY16_C(29240), SIMDE_POLY16_C( 2079), SIMDE_POLY16_C(57917) },
          { SIMDE_POLY16_C(62565), SIMDE_POLY16_C(22364), SIMDE_POLY16_C(25230), SIMDE_POLY16_C(22469) },
          { SIMDE_POLY16_C(57288), SIMDE_POLY16_C(63644), SIMDE_POLY16_C(24769), SIMDE_POLY16_C(32818) },
          { SIMDE_POLY16_C(55666), SIMDE_POLY16_C(61703), SIMDE_POLY16_C( 5323), SIMDE_POLY16_C( 1758) } },
    },
    {
        { { SIMDE_POLY16_C(39290), SIMDE_POLY16_C(57145), SIMDE_POLY16_C(24461), SIMDE_POLY16_C( 6925) },
          { SIMDE_POLY16_C(53954), SIMDE_POLY16_C(35443), SIMDE_POLY16_C(11186), SIMDE_POLY16_C(29512) },
          { SIMDE_POLY16_C(31628), SIMDE_POLY16_C(65267), SIMDE_POLY16_C(15444), SIMDE_POLY16_C( 8013) },
          { SIMDE_POLY16_C(11088), SIMDE_POLY16_C(34854), SIMDE_POLY16_C(33438), SIMDE_POLY16_C( 6368) } },
      { SIMDE_POLY16_C( 6427), SIMDE_POLY16_C(43512), SIMDE_POLY16_C(63644), SIMDE_POLY16_C(61703) },
        { { SIMDE_POLY16_C(39290), SIMDE_POLY16_C(57145), SIMDE_POLY16_C( 6427), SIMDE_POLY16_C( 6925) },
          { SIMDE_POLY16_C(53954), SIMDE_POLY16_C(35443), SIMDE_POLY16_C(43512), SIMDE_POLY16_C(29512) },
          { SIMDE_POLY16_C(31628), SIMDE_POLY16_C(65267), SIMDE_POLY16_C(63644), SIMDE_POLY16_C( 8013) },
          { SIMDE_POLY16_C(11088), SIMDE_POLY16_C(34854), SIMDE_POLY16_C(61703), SIMDE_POLY16_C( 6368) } },
    },
    {
        { { SIMDE_POLY16_C( 1401), SIMDE_POLY16_C(15300), SIMDE_POLY16_C(14295), SIMDE_POLY16_C(35269) },
          { SIMDE_POLY16_C( 3683), SIMDE_POLY16_C(61437), SIMDE_POLY16_C(61577), SIMDE_POLY16_C(56813) },
          { SIMDE_POLY16_C(14892), SIMDE_POLY16_C(32253), SIMDE_POLY16_C( 9061), SIMDE_POLY16_C(  773) },
          { SIMDE_POLY16_C(58789), SIMDE_POLY16_C(49180), SIMDE_POLY16_C( 5375), SIMDE_POLY16_C(30825) } },
      { SIMDE_POLY16_C(11801), SIMDE_POLY16_C(61619), SIMDE_POLY16_C(63644), SIMDE_POLY16_C(61703) },
        { { SIMDE_POLY16_C( 1401), SIMDE_POLY16_C(15300), SIMDE_POLY16_C(14295), SIMDE_POLY16_C(11801) },
          { SIMDE_POLY16_C( 3683), SIMDE_POLY16_C(61437), SIMDE_POLY16_C(61577), SIMDE_POLY16_C(61619) },
          { SIMDE_POLY16_C(14892), SIMDE_POLY16_C(32253), SIMDE_POLY16_C( 9061), SIMDE_POLY16_C(63644) },
          { SIMDE_POLY16_C(58789), SIMDE_POLY16_C(49180), SIMDE_POLY16_C( 5375), SIMDE_POLY16_C(61703) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4x4_t r;
    simde_poly16x4x4_t src = {
        {simde_vld1_p16(test_vec[i].src[0]), simde_vld1_p16(test_vec[i].src[1]),
         simde_vld1_p16(test_vec[i].src[2]), simde_vld1_p16(test_vec[i].src[3])}};
    simde_poly16x4x4_t expected = {
        {simde_vld1_p16(test_vec[i].r[0]), simde_vld1_p16(test_vec[i].r[1]),
         simde_vld1_p16(test_vec[i].r[2]), simde_vld1_p16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_4_(simde_vld4_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_p16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16x4x4_t src = simde_test_arm_neon_random_p16x4x4();
    simde_poly16_t buf[4];
    simde_poly16x4x4_t r;
    simde_test_arm_neon_write_p16x4x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(8, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp16(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_4_(simde_vld4_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p16x4x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t src[4][8];
    simde_poly64_t buf[4];
    simde_poly64_t r[4][8];
  } test_vec[] = {
    {
        { { SIMDE_POLY64_C(15683032258095195276) },
          { SIMDE_POLY64_C( 7553468336959036474) },
          { SIMDE_POLY64_C(13125156628617814216) },
          { SIMDE_POLY64_C( 6195188131824092394) } },
      { SIMDE_POLY64_C( 4611654476681296478), SIMDE_POLY64_C(                   0), SIMDE_POLY64_C( 4611686022722355200), SIMDE_POLY64_C( 4616194021471028225) },
        { { SIMDE_POLY64_C( 4611654476681296478) },
          { SIMDE_POLY64_C(                   0) },
          { SIMDE_POLY64_C( 4611686022722355200) },
          { SIMDE_POLY64_C( 4616194021471028225) } },
    },
    {
        { { SIMDE_POLY64_C( 2088703405382308364) },
          { SIMDE_POLY64_C( 1841591475801215200) },
          { SIMDE_POLY64_C(13963102749140759697) },
          { SIMDE_POLY64_C( 9663743460424204193) } },
      { SIMDE_POLY64_C( 4611654477341791126), SIMDE_POLY64_C(                   0), SIMDE_POLY64_C( 4611686022722355200), SIMDE_POLY64_C( 4616194021471028225) },
        { { SIMDE_POLY64_C( 4611654477341791126) },
          { SIMDE_POLY64_C(                   0) },
          { SIMDE_POLY64_C( 4611686022722355200) },
          { SIMDE_POLY64_C( 4616194021471028225) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1x4_t src = {
        {simde_vld1_p64(test_vec[i].src[0]), simde_vld1_p64(test_vec[i].src[1]),
         simde_vld1_p64(test_vec[i].src[2]), simde_vld1_p64(test_vec[i].src[3])}};

    simde_poly64x1x4_t r = simde_vld4_lane_p64(test_vec[i].buf, src, 0);

    simde_poly64x1x4_t expected = {
        {simde_vld1_p64(test_vec[i].r[0]), simde_vld1_p64(test_vec[i].r[1]),
         simde_vld1_p64(test_vec[i].r[2]), simde_vld1_p64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_p64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x1x4_t src = simde_test_arm_neon_random_p64x1x4();
    simde_poly64_t buf[4];
    simde_poly64x1x4_t r;
    simde_test_arm_neon_write_p64x1x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(32, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp64(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    r = simde_vld4_lane_p64(buf, src, 0);
    simde_test_arm_neon_write_p64x1x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t src[4][16];
    simde_poly8_t buf[4];
    simde_poly8_t r[4][16];
  } test_vec[] = {
    {
        { { SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(154), SIMDE_POLY8_C( 93), SIMDE_POLY8_C(239), SIMDE_POLY8_C(101), SIMDE_POLY8_C( 91),
            SIMDE_POLY8_C(160), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(197), SIMDE_POLY8_C( 36), SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(190) },
          { SIMDE_POLY8_C(123), SIMDE_POLY8_C( 44), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(130), SIMDE_POLY8_C(173), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(187), SIMDE_POLY8_C(  5),
            SIMDE_POLY8_C(248), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(155), SIMDE_POLY8_C(221), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(145), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(248) },
          { SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(146), SIMDE_POLY8_C(141), SIMDE_POLY8_C( 35), SIMDE_POLY8_C(248), SIMDE_POLY8_C(233), SIMDE_POLY8_C(195),
            SIMDE_POLY8_C(128), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(137), SIMDE_POLY8_C(164), SIMDE_POLY8_C(112), SIMDE_POLY8_C(150), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(235) },
          { SIMDE_POLY8_C(194), SIMDE_POLY8_C(166), SIMDE_POLY8_C(109), SIMDE_POLY8_C(111), SIMDE_POLY8_C(168), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(116), SIMDE_POLY8_C(161),
            SIMDE_POLY8_C(128), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(126), SIMDE_POLY8_C(217), SIMDE_POLY8_C(161), SIMDE_POLY8_C(127), SIMDE_POLY8_C(209), SIMDE_POLY8_C(209) } },
      { SIMDE_POLY8_C(178), SIMDE_POLY8_C(100), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(213) },
        { { SIMDE_POLY8_C(178), SIMDE_POLY8_C(159), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(154), SIMDE_POLY8_C( 93), SIMDE_POLY8_C(239), SIMDE_POLY8_C(101), SIMDE_POLY8_C( 91),
            SIMDE_POLY8_C(160), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(197), SIMDE_POLY8_C( 36), SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(190) },
          { SIMDE_POLY8_C(100), SIMDE_POLY8_C( 44), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(130), SIMDE_POLY8_C(173), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(187), SIMDE_POLY8_C(  5),
            SIMDE_POLY8_C(248), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(155), SIMDE_POLY8_C(221), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(145), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(248) },
          { SIMDE_POLY8_C( 94), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(146), SIMDE_POLY8_C(141), SIMDE_POLY8_C( 35), SIMDE_POLY8_C(248), SIMDE_POLY8_C(233), SIMDE_POLY8_C(195),
            SIMDE_POLY8_C(128), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(137), SIMDE_POLY8_C(164), SIMDE_POLY8_C(112), SIMDE_POLY8_C(150), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(235) },
          { SIMDE_POLY8_C(213), SIMDE_POLY8_C(166), SIMDE_POLY8_C(109), SIMDE_POLY8_C(111), SIMDE_POLY8_C(168), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(116), SIMDE_POLY8_C(161),
            SIMDE_POLY8_C(128), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(126), SIMDE_POLY8_C(217), SIMDE_POLY8_C(161), SIMDE_POLY8_C(127), SIMDE_POLY8_C(209), SIMDE_POLY8_C(209) } },
    },
    {
        { { SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 71), SIMDE_POLY8_C(153), SIMDE_POLY8_C(220), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(128), SIMDE_POLY8_C(223),
            SIMDE_POLY8_C(184), SIMDE_POLY8_C(227), SIMDE_POLY8_C(202), SIMDE_POLY8_C(122), SIMDE_POLY8_C(138), SIMDE_POLY8_C( 56), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 50) },
          { SIMDE_POLY8_C( 96), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(211), SIMDE_POLY8_C(224), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 15),
            SIMDE_POLY8_C(209), SIMDE_POLY8_C(139), SIMDE_POLY8_C(224), SIMDE_POLY8_C(131), SIMDE_POLY8_C(239), SIMDE_POLY8_C( 62), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 75) },
          { SIMDE_POLY8_C(134), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(245), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(167), SIMDE_POLY8_C(212), SIMDE_POLY8_C(204),
            SIMDE_POLY8_C(139), SIMDE_POLY8_C(158), SIMDE_POLY8_C( 70), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(214), SIMDE_POLY8_C( 47), SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 55) },
          { SIMDE_POLY8_C(141), SIMDE_POLY8_C( 27), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(251), SIMDE_POLY8_C(109), SIMDE_POLY8_C(209), SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 62),
            SIMDE_POLY8_C( 92), SIMDE_POLY8_C(234), SIMDE_POLY8_C(193), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 41), SIMDE_POLY8_C( 26), SIMDE_POLY8_C(150), SIMDE_POLY8_C(175) } },
      { SIMDE_POLY8_C( 12), SIMDE_POLY8_C(189), SIMDE_POLY8_C(164), SIMDE_POLY8_C( 32) },
        { { SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(153), SIMDE_POLY8_C(220), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(128), SIMDE_POLY8_C(223),
            SIMDE_POLY8_C(184), SIMDE_POLY8_C(227), SIMDE_POLY8_C(202), SIMDE_POLY8_C(122), SIMDE_POLY8_C(138), SIMDE_POLY8_C( 56), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 50) },
          { SIMDE_POLY8_C( 96), SIMDE_POLY8_C(189), SIMDE_POLY8_C(211), SIMDE_POLY8_C(224), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 15),
            SIMDE_POLY8_C(209), SIMDE_POLY8_C(139), SIMDE_POLY8_C(224), SIMDE_POLY8_C(131), SIMDE_POLY8_C(239), SIMDE_POLY8_C( 62), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 75) },
          { SIMDE_POLY8_C(134), SIMDE_POLY8_C(164), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(245), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(167), SIMDE_POLY8_C(212), SIMDE_POLY8_C(204),
            SIMDE_POLY8_C(139), SIMDE_POLY8_C(158), SIMDE_POLY8_C( 70), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(214), SIMDE_POLY8_C( 47), SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 55) },
          { SIMDE_POLY8_C(141), SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(251), SIMDE_POLY8_C(109), SIMDE_POLY8_C(209), SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 62),
            SIMDE_POLY8_C( 92), SIMDE_POLY8_C(234), SIMDE_POLY8_C(193), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 41), SIMDE_POLY8_C( 26), SIMDE_POLY8_C(150), SIMDE_POLY8_C(175) } },
    },
    {
        { { SIMDE_POLY8_C(100), SIMDE_POLY8_C(120), SIMDE_POLY8_C(236), SIMDE_POLY8_C(239), SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(237),
            SIMDE_POLY8_C( 98), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 36), SIMDE_POLY8_C(239), SIMDE_POLY8_C(103), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(235), SIMDE_POLY8_C(212) },
          { SIMDE_POLY8_C( 12), SIMDE_POLY8_C(245), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(104), SIMDE_POLY8_C(224), SIMDE_POLY8_C(211), SIMDE_POLY8_C(179), SIMDE_POLY8_C(  9),
            SIMDE_POLY8_C(238), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(184), SIMDE_POLY8_C(250), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(107) },
          { SIMDE_POLY8_C(212), SIMDE_POLY8_C(  7), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(234), SIMDE_POLY8_C( 58), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(215), SIMDE_POLY8_C(156),
            SIMDE_POLY8_C(171), SIMDE_POLY8_C(251), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 18), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(118), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 67) },
          { SIMDE_POLY8_C(108), SIMDE_POLY8_C(248), SIMDE_POLY8_C(172), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(203), SIMDE_POLY8_C( 95), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(185),
            SIMDE_POLY8_C(169), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(180), SIMDE_POLY8_C(175), SIMDE_POLY8_C(105), SIMDE_POLY8_C(207), SIMDE_POLY8_C( 26), SIMDE_POLY8_C( 61) } },
      { SIMDE_POLY8_C(214), SIMDE_POLY8_C(117), SIMDE_POLY8_C( 39), SIMDE_POLY8_C( 16) },
        { { SIMDE_POLY8_C(100), SIMDE_POLY8_C(120), SIMDE_POLY8_C(214), SIMDE_POLY8_C(239), SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(237),
            SIMDE_POLY8_C( 98), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 36), SIMDE_POLY8_C(239), SIMDE_POLY8_C(103), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(235), SIMDE_POLY8_C(212) },
          { SIMDE_POLY8_C( 12), SIMDE_POLY8_C(245), SIMDE_POLY8_C(117), SIMDE_POLY8_C(104), SIMDE_POLY8_C(224), SIMDE_POLY8_C(211), SIMDE_POLY8_C(179), SIMDE_POLY8_C(  9),
            SIMDE_POLY8_C(238), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(184), SIMDE_POLY8_C(250), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(107) },
          { SIMDE_POLY8_C(212), SIMDE_POLY8_C(  7), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(234), SIMDE_POLY8_C( 58), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(215), SIMDE_POLY8_C(156),
            SIMDE_POLY8_C(171), SIMDE_POLY8_C(251), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 18), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(118), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 67) },
          { SIMDE_POLY8_C(108), SIMDE_POLY8_C(248), SIMDE_POLY8_C( 16), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(203), SIMDE_POLY8_C( 95), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(185),
            SIMDE_POLY8_C(169), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(180), SIMDE_POLY8_C(175), SIMDE_POLY8_C(105), SIMDE_POLY8_C(207), SIMDE_POLY8_C( 26), SIMDE_POLY8_C( 61) } },
    },
    {
        { { SIMDE_POLY8_C(212),    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C(172), SIMDE_POLY8_C(127), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 56), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 49),
            SIMDE_POLY8_C(174), SIMDE_POLY8_C(119), SIMDE_POLY8_C(117), SIMDE_POLY8_C( 26), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(102), SIMDE_POLY8_C( 58) },
          { SIMDE_POLY8_C(128), SIMDE_POLY8_C(187), SIMDE_POLY8_C(244), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(200), SIMDE_POLY8_C(168), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 49),
            SIMDE_POLY8_C(119), SIMDE_POLY8_C(243), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(104), SIMDE_POLY8_C(150), SIMDE_POLY8_C( 94), SIMDE_POLY8_C( 60) },
          { SIMDE_POLY8_C(149), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(187), SIMDE_POLY8_C(143), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(193), SIMDE_POLY8_C(241),
            SIMDE_POLY8_C(195), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 11), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(114), SIMDE_POLY8_C(109), SIMDE_POLY8_C(215) },
          { SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 97), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(246), SIMDE_POLY8_C(  9), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(128),
            SIMDE_POLY8_C(205), SIMDE_POLY8_C(150), SIMDE_POLY8_C(205), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 44), SIMDE_POLY8_C( 43), SIMDE_POLY8_C(114), SIMDE_POLY8_C(193) } },
      { SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 46), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(120) },
        { { SIMDE_POLY8_C(212),    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C(172), SIMDE_POLY8_C( 54), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 56), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 49),
            SIMDE_POLY8_C(174), SIMDE_POLY8_C(119), SIMDE_POLY8_C(117), SIMDE_POLY8_C( 26), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(102), SIMDE_POLY8_C( 58) },
          { SIMDE_POLY8_C(128), SIMDE_POLY8_C(187), SIMDE_POLY8_C(244), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(200), SIMDE_POLY8_C(168), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 49),
            SIMDE_POLY8_C(119), SIMDE_POLY8_C(243), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(104), SIMDE_POLY8_C(150), SIMDE_POLY8_C( 94), SIMDE_POLY8_C( 60) },
          { SIMDE_POLY8_C(149), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(187), SIMDE_POLY8_C( 80), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(193), SIMDE_POLY8_C(241),
            SIMDE_POLY8_C(195), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 11), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(114), SIMDE_POLY8_C(109), SIMDE_POLY8_C(215) },
          { SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 97), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(120), SIMDE_POLY8_C(  9), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(128),
            SIMDE_POLY8_C(205), SIMDE_POLY8_C(150), SIMDE_POLY8_C(205), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 44), SIMDE_POLY8_C( 43), SIMDE_POLY8_C(114), SIMDE_POLY8_C(193) } },
    },
    {
        { { SIMDE_POLY8_C(122), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(105), SIMDE_POLY8_C( 62), SIMDE_POLY8_C( 71), SIMDE_POLY8_C(117), SIMDE_POLY8_C(112), SIMDE_POLY8_C(158),
            SIMDE_POLY8_C(231), SIMDE_POLY8_C(221), SIMDE_POLY8_C(118), SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(119), SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 71) },
          { SIMDE_POLY8_C( 81), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(200), SIMDE_POLY8_C(149), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(244),
            SIMDE_POLY8_C(192), SIMDE_POLY8_C(199), SIMDE_POLY8_C(181), SIMDE_POLY8_C(246), SIMDE_POLY8_C(245), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111) },
          { SIMDE_POLY8_C( 23), SIMDE_POLY8_C(216), SIMDE_POLY8_C(173), SIMDE_POLY8_C( 94), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(253), SIMDE_POLY8_C( 52),
            SIMDE_POLY8_C(251), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(234), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 59) },
          { SIMDE_POLY8_C(133), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(222), SIMDE_POLY8_C(174), SIMDE_POLY8_C( 65), SIMDE_POLY8_C(158),
            SIMDE_POLY8_C(117), SIMDE_POLY8_C(246), SIMDE_POLY8_C(149), SIMDE_POLY8_C(106), SIMDE_POLY8_C(252), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 19) } },
      { SIMDE_POLY8_C(220), SIMDE_POLY8_C(135), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 42) },
        { { SIMDE_POLY8_C(122), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(105), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(220), SIMDE_POLY8_C(117), SIMDE_POLY8_C(112), SIMDE_POLY8_C(158),
            SIMDE_POLY8_C(231), SIMDE_POLY8_C(221), SIMDE_POLY8_C(118), SIMDE_POLY8_C( 20), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(119), SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 71) },
          { SIMDE_POLY8_C( 81), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(135), SIMDE_POLY8_C(149), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(244),
            SIMDE_POLY8_C(192), SIMDE_POLY8_C(199), SIMDE_POLY8_C(181), SIMDE_POLY8_C(246), SIMDE_POLY8_C(245), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111) },
          { SIMDE_POLY8_C( 23), SIMDE_POLY8_C(216), SIMDE_POLY8_C(173), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(253), SIMDE_POLY8_C( 52),
            SIMDE_POLY8_C(251), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(234), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 59) },
          { SIMDE_POLY8_C(133), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(174), SIMDE_POLY8_C( 65), SIMDE_POLY8_C(158),
            SIMDE_POLY8_C(117), SIMDE_POLY8_C(246), SIMDE_POLY8_C(149), SIMDE_POLY8_C(106), SIMDE_POLY8_C(252), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 19) } },
    },
    {
        { { SIMDE_POLY8_C(165), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(160), SIMDE_POLY8_C(225), SIMDE_POLY8_C(167), SIMDE_POLY8_C(218), SIMDE_POLY8_C(203),
            SIMDE_POLY8_C(251), SIMDE_POLY8_C( 92), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(128), SIMDE_POLY8_C(165), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(206), SIMDE_POLY8_C(131) },
          { SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(131), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(182), SIMDE_POLY8_C(237), SIMDE_POLY8_C(  2),
            SIMDE_POLY8_C(186), SIMDE_POLY8_C(198), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(134), SIMDE_POLY8_C(193), SIMDE_POLY8_C(242) },
          { SIMDE_POLY8_C(245), SIMDE_POLY8_C( 31), SIMDE_POLY8_C(147), SIMDE_POLY8_C(214), SIMDE_POLY8_C(199), SIMDE_POLY8_C(109), SIMDE_POLY8_C(162), SIMDE_POLY8_C(194),
            SIMDE_POLY8_C(201), SIMDE_POLY8_C(168), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(110), SIMDE_POLY8_C(  8), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(241), SIMDE_POLY8_C( 22) },
          { SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(153), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(201), SIMDE_POLY8_C(134), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(132),
            SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 61), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(154), SIMDE_POLY8_C(195), SIMDE_POLY8_C(220), SIMDE_POLY8_C(141), SIMDE_POLY8_C(184) } },
      { SIMDE_POLY8_C(251), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(143), SIMDE_POLY8_C(194) },
        { { SIMDE_POLY8_C(165), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(160), SIMDE_POLY8_C(225), SIMDE_POLY8_C(251), SIMDE_POLY8_C(218), SIMDE_POLY8_C(203),
            SIMDE_POLY8_C(251), SIMDE_POLY8_C( 92), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(128), SIMDE_POLY8_C(165), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(206), SIMDE_POLY8_C(131) },
          { SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(131), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(237), SIMDE_POLY8_C(  2),
            SIMDE_POLY8_C(186), SIMDE_POLY8_C(198), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(134), SIMDE_POLY8_C(193), SIMDE_POLY8_C(242) },
          { SIMDE_POLY8_C(245), SIMDE_POLY8_C( 31), SIMDE_POLY8_C(147), SIMDE_POLY8_C(214), SIMDE_POLY8_C(199), SIMDE_POLY8_C(143), SIMDE_POLY8_C(162), SIMDE_POLY8_C(194),
            SIMDE_POLY8_C(201), SIMDE_POLY8_C(168), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(110), SIMDE_POLY8_C(  8), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(241), SIMDE_POLY8_C( 22) },
          { SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(153), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(201), SIMDE_POLY8_C(194), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(132),
            SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 61), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(154), SIMDE_POLY8_C(195), SIMDE_POLY8_C(220), SIMDE_POLY8_C(141), SIMDE_POLY8_C(184) } },
    },
    {
        { { SIMDE_POLY8_C(141), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(132), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(217), SIMDE_POLY8_C(199), SIMDE_POLY8_C(197), SIMDE_POLY8_C(226),
            SIMDE_POLY8_C(215), SIMDE_POLY8_C(183), SIMDE_POLY8_C(248), SIMDE_POLY8_C(247), SIMDE_POLY8_C(202), SIMDE_POLY8_C(146), SIMDE_POLY8_C( 29), SIMDE_POLY8_C(147) },
          { SIMDE_POLY8_C( 24), SIMDE_POLY8_C( 69), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(101), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(  0), SIMDE_POLY8_C( 70),
            SIMDE_POLY8_C( 14), SIMDE_POLY8_C(141), SIMDE_POLY8_C(254), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(173), SIMDE_POLY8_C(141), SIMDE_POLY8_C(204), SIMDE_POLY8_C( 58) },
          { SIMDE_POLY8_C(190), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(145), SIMDE_POLY8_C(152), SIMDE_POLY8_C( 24), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(122), SIMDE_POLY8_C(239),
            SIMDE_POLY8_C( 14), SIMDE_POLY8_C(114), SIMDE_POLY8_C(231), SIMDE_POLY8_C(216), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 29) },
          { SIMDE_POLY8_C( 74), SIMDE_POLY8_C(131), SIMDE_POLY8_C(130), SIMDE_POLY8_C(204), SIMDE_POLY8_C(181), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(196),
            SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(206), SIMDE_POLY8_C(188), SIMDE_POLY8_C(158), SIMDE_POLY8_C(154), SIMDE_POLY8_C(247), SIMDE_POLY8_C( 93) } },
      { SIMDE_POLY8_C(235), SIMDE_POLY8_C(136), SIMDE_POLY8_C(245), SIMDE_POLY8_C(  3) },
        { { SIMDE_POLY8_C(141), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(132), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(217), SIMDE_POLY8_C(199), SIMDE_POLY8_C(235), SIMDE_POLY8_C(226),
            SIMDE_POLY8_C(215), SIMDE_POLY8_C(183), SIMDE_POLY8_C(248), SIMDE_POLY8_C(247), SIMDE_POLY8_C(202), SIMDE_POLY8_C(146), SIMDE_POLY8_C( 29), SIMDE_POLY8_C(147) },
          { SIMDE_POLY8_C( 24), SIMDE_POLY8_C( 69), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(101), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(136), SIMDE_POLY8_C( 70),
            SIMDE_POLY8_C( 14), SIMDE_POLY8_C(141), SIMDE_POLY8_C(254), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(173), SIMDE_POLY8_C(141), SIMDE_POLY8_C(204), SIMDE_POLY8_C( 58) },
          { SIMDE_POLY8_C(190), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(145), SIMDE_POLY8_C(152), SIMDE_POLY8_C( 24), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(245), SIMDE_POLY8_C(239),
            SIMDE_POLY8_C( 14), SIMDE_POLY8_C(114), SIMDE_POLY8_C(231), SIMDE_POLY8_C(216), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 29) },
          { SIMDE_POLY8_C( 74), SIMDE_POLY8_C(131), SIMDE_POLY8_C(130), SIMDE_POLY8_C(204), SIMDE_POLY8_C(181), SIMDE_POLY8_C(130), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(196),
            SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(206), SIMDE_POLY8_C(188), SIMDE_POLY8_C(158), SIMDE_POLY8_C(154), SIMDE_POLY8_C(247), SIMDE_POLY8_C( 93) } },
    },
    {
        { { SIMDE_POLY8_C(223), SIMDE_POLY8_C(111), SIMDE_POLY8_C(243), SIMDE_POLY8_C(237), SIMDE_POLY8_C(225), SIMDE_POLY8_C(218), SIMDE_POLY8_C(197), SIMDE_POLY8_C(230),
            SIMDE_POLY8_C(222), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(  3), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(180), SIMDE_POLY8_C(133), SIMDE_POLY8_C(245), SIMDE_POLY8_C(105) },
          { SIMDE_POLY8_C(  8), SIMDE_POLY8_C(  7), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(251), SIMDE_POLY8_C(212), SIMDE_POLY8_C(183),
            SIMDE_POLY8_C(150), SIMDE_POLY8_C(203), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(  9), SIMDE_POLY8_C(133), SIMDE_POLY8_C( 51) },
          { SIMDE_POLY8_C(120), SIMDE_POLY8_C(120), SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 63), SIMDE_POLY8_C( 48),
            SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(203), SIMDE_POLY8_C(200), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(208) },
          { SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(231), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 93), SIMDE_POLY8_C(187), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(243),
            SIMDE_POLY8_C(134), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(117), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(186) } },
      { SIMDE_POLY8_C(114), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(196) },
        { { SIMDE_POLY8_C(223), SIMDE_POLY8_C(111), SIMDE_POLY8_C(243), SIMDE_POLY8_C(237), SIMDE_POLY8_C(225), SIMDE_POLY8_C(218), SIMDE_POLY8_C(197), SIMDE_POLY8_C(114),
            SIMDE_POLY8_C(222), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(  3), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(180), SIMDE_POLY8_C(133), SIMDE_POLY8_C(245), SIMDE_POLY8_C(105) },
          { SIMDE_POLY8_C(  8), SIMDE_POLY8_C(  7), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(251), SIMDE_POLY8_C(212), SIMDE_POLY8_C( 45),
            SIMDE_POLY8_C(150), SIMDE_POLY8_C(203), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(  9), SIMDE_POLY8_C(133), SIMDE_POLY8_C( 51) },
          { SIMDE_POLY8_C(120), SIMDE_POLY8_C(120), SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 63), SIMDE_POLY8_C( 19),
            SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(203), SIMDE_POLY8_C(200), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(208) },
          { SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(231), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 93), SIMDE_POLY8_C(187), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(196),
            SIMDE_POLY8_C(134), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(117), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 13), SIMDE_POLY8_C(186) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16x4_t r;
    simde_poly8x16x4_t src = {
        {simde_vld1q_p8(test_vec[i].src[0]), simde_vld1q_p8(test_vec[i].src[1]),
         simde_vld1q_p8(test_vec[i].src[2]), simde_vld1q_p8(test_vec[i].src[3])}};
    simde_poly8x16x4_t expected = {
        {simde_vld1q_p8(test_vec[i].r[0]), simde_vld1q_p8(test_vec[i].r[1]),
         simde_vld1q_p8(test_vec[i].r[2]), simde_vld1q_p8(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_16_(simde_vld4q_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_p8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 16 ; i++) {
    simde_poly8x16x4_t src = simde_test_arm_neon_random_p8x16x4();
    simde_poly8_t buf[4];
    simde_poly8x16x4_t r;
    simde_test_arm_neon_write_p8x16x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp8(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_16_(simde_vld4q_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p8x16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t src[4][8];
    simde_poly16_t buf[4];
    simde_poly16_t r[4][8];
  } test_vec[] = {
    {
        { { SIMDE_POLY16_C(36561), SIMDE_POLY16_C(27412), SIMDE_POLY16_C(49068), SIMDE_POLY16_C(10101), SIMDE_POLY16_C(56899), SIMDE_POLY16_C(25642), SIMDE_POLY16_C(61901), SIMDE_POLY16_C(17642) },
          { SIMDE_POLY16_C(29177), SIMDE_POLY16_C(52241), SIMDE_POLY16_C(33043), SIMDE_POLY16_C(57000), SIMDE_POLY16_C(34377), SIMDE_POLY16_C(24689), SIMDE_POLY16_C(48063), SIMDE_POLY16_C(37050) },
          { SIMDE_POLY16_C(53065), SIMDE_POLY16_C(62971), SIMDE_POLY16_C(28814), SIMDE_POLY16_C(53532), SIMDE_POLY16_C(17998), SIMDE_POLY16_C( 6966), SIMDE_POLY16_C( 8247), SIMDE_POLY16_C(12383) },
          { SIMDE_POLY16_C(28817), SIMDE_POLY16_C(42237), SIMDE_POLY16_C(42481), SIMDE_POLY16_C(15234), SIMDE_POLY16_C(62507), SIMDE_POLY16_C(60059), SIMDE_POLY16_C(21935), SIMDE_POLY16_C(63610) } },
      { SIMDE_POLY16_C(29988), SIMDE_POLY16_C(46061), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50158) },
        { { SIMDE_POLY16_C(29988), SIMDE_POLY16_C(27412), SIMDE_POLY16_C(49068), SIMDE_POLY16_C(10101), SIMDE_POLY16_C(56899), SIMDE_POLY16_C(25642), SIMDE_POLY16_C(61901), SIMDE_POLY16_C(17642) },
          { SIMDE_POLY16_C(46061), SIMDE_POLY16_C(52241), SIMDE_POLY16_C(33043), SIMDE_POLY16_C(57000), SIMDE_POLY16_C(34377), SIMDE_POLY16_C(24689), SIMDE_POLY16_C(48063), SIMDE_POLY16_C(37050) },
          { SIMDE_POLY16_C(62106), SIMDE_POLY16_C(62971), SIMDE_POLY16_C(28814), SIMDE_POLY16_C(53532), SIMDE_POLY16_C(17998), SIMDE_POLY16_C( 6966), SIMDE_POLY16_C( 8247), SIMDE_POLY16_C(12383) },
          { SIMDE_POLY16_C(50158), SIMDE_POLY16_C(42237), SIMDE_POLY16_C(42481), SIMDE_POLY16_C(15234), SIMDE_POLY16_C(62507), SIMDE_POLY16_C(60059), SIMDE_POLY16_C(21935), SIMDE_POLY16_C(63610) } },
    },
    {
        { { SIMDE_POLY16_C( 2533), SIMDE_POLY16_C(13188), SIMDE_POLY16_C(47696), SIMDE_POLY16_C(34638), SIMDE_POLY16_C(44506), SIMDE_POLY16_C(27576), SIMDE_POLY16_C(46365), SIMDE_POLY16_C( 3856) },
          { SIMDE_POLY16_C(37466), SIMDE_POLY16_C(34122), SIMDE_POLY16_C(58758), SIMDE_POLY16_C(13679), SIMDE_POLY16_C(59706), SIMDE_POLY16_C(24365), SIMDE_POLY16_C( 6750), SIMDE_POLY16_C(17170) },
          { SIMDE_POLY16_C(38436), SIMDE_POLY16_C(29814), SIMDE_POLY16_C(50257), SIMDE_POLY16_C(11259), SIMDE_POLY16_C(45937), SIMDE_POLY16_C(36503), SIMDE_POLY16_C(42856), SIMDE_POLY16_C(49821) },
          { SIMDE_POLY16_C(59193), SIMDE_POLY16_C(49223), SIMDE_POLY16_C(46796), SIMDE_POLY16_C( 2037), SIMDE_POLY16_C( 9119), SIMDE_POLY16_C(64870), SIMDE_POLY16_C(30781), SIMDE_POLY16_C(24896) } },
      { SIMDE_POLY16_C(46606), SIMDE_POLY16_C(24533), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50158) },
        { { SIMDE_POLY16_C( 2533), SIMDE_POLY16_C(46606), SIMDE_POLY16_C(47696), SIMDE_POLY16_C(34638), SIMDE_POLY16_C(44506), SIMDE_POLY16_C(27576), SIMDE_POLY16_C(46365), SIMDE_POLY16_C( 3856) },
          { SIMDE_POLY16_C(37466), SIMDE_POLY16_C(24533), SIMDE_POLY16_C(58758), SIMDE_POLY16_C(13679), SIMDE_POLY16_C(59706), SIMDE_POLY16_C(24365), SIMDE_POLY16_C( 6750), SIMDE_POLY16_C(17170) },
          { SIMDE_POLY16_C(38436), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50257), SIMDE_POLY16_C(11259), SIMDE_POLY16_C(45937), SIMDE_POLY16_C(36503), SIMDE_POLY16_C(42856), SIMDE_POLY16_C(49821) },
          { SIMDE_POLY16_C(59193), SIMDE_POLY16_C(50158), SIMDE_POLY16_C(46796), SIMDE_POLY16_C( 2037), SIMDE_POLY16_C( 9119), SIMDE_POLY16_C(64870), SIMDE_POLY16_C(30781), SIMDE_POLY16_C(24896) } },
    },
    {
        { { SIMDE_POLY16_C(53626), SIMDE_POLY16_C(60299), SIMDE_POLY16_C( 8836), SIMDE_POLY16_C(60794), SIMDE_POLY16_C( 6089), SIMDE_POLY16_C(  687), SIMDE_POLY16_C(63487), SIMDE_POLY16_C(52162) },
          { SIMDE_POLY16_C(47277), SIMDE_POLY16_C(19922), SIMDE_POLY16_C(14555), SIMDE_POLY16_C( 6218), SIMDE_POLY16_C(35760), SIMDE_POLY16_C(49018), SIMDE_POLY16_C(20289), SIMDE_POLY16_C(48158) },
          { SIMDE_POLY16_C(43296), SIMDE_POLY16_C(42407), SIMDE_POLY16_C( 8651), SIMDE_POLY16_C(38034), SIMDE_POLY16_C(16697), SIMDE_POLY16_C(14487), SIMDE_POLY16_C(22840), SIMDE_POLY16_C(58883) },
          { SIMDE_POLY16_C(54801), SIMDE_POLY16_C(60467), SIMDE_POLY16_C(32014), SIMDE_POLY16_C(48901), SIMDE_POLY16_C(32520), SIMDE_POLY16_C(19070), SIMDE_POLY16_C(40142), SIMDE_POLY16_C(61190) } },
      { SIMDE_POLY16_C(44358), SIMDE_POLY16_C( 4500), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50158) },
        { { SIMDE_POLY16_C(53626), SIMDE_POLY16_C(60299), SIMDE_POLY16_C(44358), SIMDE_POLY16_C(60794), SIMDE_POLY16_C( 6089), SIMDE_POLY16_C(  687), SIMDE_POLY16_C(63487), SIMDE_POLY16_C(52162) },
          { SIMDE_POLY16_C(47277), SIMDE_POLY16_C(19922), SIMDE_POLY16_C( 4500), SIMDE_POLY16_C( 6218), SIMDE_POLY16_C(35760), SIMDE_POLY16_C(49018), SIMDE_POLY16_C(20289), SIMDE_POLY16_C(48158) },
          { SIMDE_POLY16_C(43296), SIMDE_POLY16_C(42407), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(38034), SIMDE_POLY16_C(16697), SIMDE_POLY16_C(14487), SIMDE_POLY16_C(22840), SIMDE_POLY16_C(58883) },
          { SIMDE_POLY16_C(54801), SIMDE_POLY16_C(60467), SIMDE_POLY16_C(50158), SIMDE_POLY16_C(48901), SIMDE_POLY16_C(32520), SIMDE_POLY16_C(19070), SIMDE_POLY16_C(40142), SIMDE_POLY16_C(61190) } },
    },
    {
        { { SIMDE_POLY16_C( 9935), SIMDE_POLY16_C( 2214), SIMDE_POLY16_C(15719), SIMDE_POLY16_C(41024), SIMDE_POLY16_C(17302), SIMDE_POLY16_C(43142), SIMDE_POLY16_C(47385), SIMDE_POLY16_C(10388) },
          { SIMDE_POLY16_C(39222), SIMDE_POLY16_C(16359), SIMDE_POLY16_C(25880), SIMDE_POLY16_C(59273), SIMDE_POLY16_C(36609), SIMDE_POLY16_C(18390), SIMDE_POLY16_C(27196), SIMDE_POLY16_C( 2905) },
          { SIMDE_POLY16_C(65424), SIMDE_POLY16_C(63251), SIMDE_POLY16_C(21308), SIMDE_POLY16_C(53911), SIMDE_POLY16_C( 7575), SIMDE_POLY16_C(45178), SIMDE_POLY16_C( 4054), SIMDE_POLY16_C( 3544) },
          { SIMDE_POLY16_C(49064), SIMDE_POLY16_C(49484), SIMDE_POLY16_C(54564), SIMDE_POLY16_C( 9896), SIMDE_POLY16_C(32356), SIMDE_POLY16_C(41069), SIMDE_POLY16_C(50920), SIMDE_POLY16_C(30892) } },
      { SIMDE_POLY16_C(49093), SIMDE_POLY16_C(  367), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50158) },
        { { SIMDE_POLY16_C( 9935), SIMDE_POLY16_C( 2214), SIMDE_POLY16_C(15719), SIMDE_POLY16_C(49093), SIMDE_POLY16_C(17302), SIMDE_POLY16_C(43142), SIMDE_POLY16_C(47385), SIMDE_POLY16_C(10388) },
          { SIMDE_POLY16_C(39222), SIMDE_POLY16_C(16359), SIMDE_POLY16_C(25880), SIMDE_POLY16_C(  367), SIMDE_POLY16_C(36609), SIMDE_POLY16_C(18390), SIMDE_POLY16_C(27196), SIMDE_POLY16_C( 2905) },
          { SIMDE_POLY16_C(65424), SIMDE_POLY16_C(63251), SIMDE_POLY16_C(21308), SIMDE_POLY16_C(62106), SIMDE_POLY16_C( 7575), SIMDE_POLY16_C(45178), SIMDE_POLY16_C( 4054), SIMDE_POLY16_C( 3544) },
          { SIMDE_POLY16_C(49064), SIMDE_POLY16_C(49484), SIMDE_POLY16_C(54564), SIMDE_POLY16_C(50158), SIMDE_POLY16_C(32356), SIMDE_POLY16_C(41069), SIMDE_POLY16_C(50920), SIMDE_POLY16_C(30892) } },
    },
    {
        { { SIMDE_POLY16_C( 1811), SIMDE_POLY16_C(43732), SIMDE_POLY16_C(20004), SIMDE_POLY16_C(64346), SIMDE_POLY16_C(13149), SIMDE_POLY16_C( 1544), SIMDE_POLY16_C(21746), SIMDE_POLY16_C( 6087) },
          { SIMDE_POLY16_C(28457), SIMDE_POLY16_C(36157), SIMDE_POLY16_C(43757), SIMDE_POLY16_C(54573), SIMDE_POLY16_C(55665), SIMDE_POLY16_C(13901), SIMDE_POLY16_C(48281), SIMDE_POLY16_C(44088) },
          { SIMDE_POLY16_C( 3267), SIMDE_POLY16_C(59478), SIMDE_POLY16_C(45146), SIMDE_POLY16_C(47331), SIMDE_POLY16_C(60387), SIMDE_POLY16_C(54974), SIMDE_POLY16_C(34111), SIMDE_POLY16_C(26861) },
          { SIMDE_POLY16_C(10996), SIMDE_POLY16_C(57845), SIMDE_POLY16_C( 8916), SIMDE_POLY16_C(17846), SIMDE_POLY16_C( 1020), SIMDE_POLY16_C(38268), SIMDE_POLY16_C(46271), SIMDE_POLY16_C(33601) } },
      { SIMDE_POLY16_C(38848), SIMDE_POLY16_C( 6763), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50158) },
        { { SIMDE_POLY16_C( 1811), SIMDE_POLY16_C(43732), SIMDE_POLY16_C(20004), SIMDE_POLY16_C(64346), SIMDE_POLY16_C(38848), SIMDE_POLY16_C( 1544), SIMDE_POLY16_C(21746), SIMDE_POLY16_C( 6087) },
          { SIMDE_POLY16_C(28457), SIMDE_POLY16_C(36157), SIMDE_POLY16_C(43757), SIMDE_POLY16_C(54573), SIMDE_POLY16_C( 6763), SIMDE_POLY16_C(13901), SIMDE_POLY16_C(48281), SIMDE_POLY16_C(44088) },
          { SIMDE_POLY16_C( 3267), SIMDE_POLY16_C(59478), SIMDE_POLY16_C(45146), SIMDE_POLY16_C(47331), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(54974), SIMDE_POLY16_C(34111), SIMDE_POLY16_C(26861) },
          { SIMDE_POLY16_C(10996), SIMDE_POLY16_C(57845), SIMDE_POLY16_C( 8916), SIMDE_POLY16_C(17846), SIMDE_POLY16_C(50158), SIMDE_POLY16_C(38268), SIMDE_POLY16_C(46271), SIMDE_POLY16_C(33601) } },
    },
    {
        { { SIMDE_POLY16_C(20039), SIMDE_POLY16_C(11218), SIMDE_POLY16_C(36921), SIMDE_POLY16_C(30721), SIMDE_POLY16_C(60949), SIMDE_POLY16_C( 2528), SIMDE_POLY16_C(54552), SIMDE_POLY16_C(60650) },
          { SIMDE_POLY16_C(41207), SIMDE_POLY16_C(62258), SIMDE_POLY16_C(44707), SIMDE_POLY16_C(25480), SIMDE_POLY16_C(51554), SIMDE_POLY16_C( 8934), SIMDE_POLY16_C(20832), SIMDE_POLY16_C(43068) },
          { SIMDE_POLY16_C( 3999), SIMDE_POLY16_C(55507), SIMDE_POLY16_C(54431), SIMDE_POLY16_C(46416), SIMDE_POLY16_C(12482), SIMDE_POLY16_C(55998), SIMDE_POLY16_C(43269), SIMDE_POLY16_C(64710) },
          { SIMDE_POLY16_C(63561), SIMDE_POLY16_C(60912), SIMDE_POLY16_C(30886), SIMDE_POLY16_C( 2128), SIMDE_POLY16_C(13890), SIMDE_POLY16_C(41514), SIMDE_POLY16_C(26503), SIMDE_POLY16_C( 9802) } },
      { SIMDE_POLY16_C( 7542), SIMDE_POLY16_C( 5630), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50158) },
        { { SIMDE_POLY16_C(20039), SIMDE_POLY16_C(11218), SIMDE_POLY16_C(36921), SIMDE_POLY16_C(30721), SIMDE_POLY16_C(60949), SIMDE_POLY16_C( 7542), SIMDE_POLY16_C(54552), SIMDE_POLY16_C(60650) },
          { SIMDE_POLY16_C(41207), SIMDE_POLY16_C(62258), SIMDE_POLY16_C(44707), SIMDE_POLY16_C(25480), SIMDE_POLY16_C(51554), SIMDE_POLY16_C( 5630), SIMDE_POLY16_C(20832), SIMDE_POLY16_C(43068) },
          { SIMDE_POLY16_C( 3999), SIMDE_POLY16_C(55507), SIMDE_POLY16_C(54431), SIMDE_POLY16_C(46416), SIMDE_POLY16_C(12482), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(43269), SIMDE_POLY16_C(64710) },
          { SIMDE_POLY16_C(63561), SIMDE_POLY16_C(60912), SIMDE_POLY16_C(30886), SIMDE_POLY16_C( 2128), SIMDE_POLY16_C(13890), SIMDE_POLY16_C(50158), SIMDE_POLY16_C(26503), SIMDE_POLY16_C( 9802) } },
    },
    {
        { { SIMDE_POLY16_C(20209), SIMDE_POLY16_C(46026), SIMDE_POLY16_C(35198), SIMDE_POLY16_C(33677), SIMDE_POLY16_C(21554), SIMDE_POLY16_C(31615), SIMDE_POLY16_C(28492), SIMDE_POLY16_C(62312) },
          { SIMDE_POLY16_C(47336), SIMDE_POLY16_C(11003), SIMDE_POLY16_C( 9966), SIMDE_POLY16_C(30156), SIMDE_POLY16_C( 6029), SIMDE_POLY16_C(  923), SIMDE_POLY16_C(39220), SIMDE_POLY16_C( 9752) },
          { SIMDE_POLY16_C(58343), SIMDE_POLY16_C(26073), SIMDE_POLY16_C(26476), SIMDE_POLY16_C(40680), SIMDE_POLY16_C(26811), SIMDE_POLY16_C( 1817), SIMDE_POLY16_C(33495), SIMDE_POLY16_C(49146) },
          { SIMDE_POLY16_C(63034), SIMDE_POLY16_C(10729), SIMDE_POLY16_C(46620), SIMDE_POLY16_C(43422), SIMDE_POLY16_C(15053), SIMDE_POLY16_C(  428), SIMDE_POLY16_C(50387), SIMDE_POLY16_C(47911) } },
      { SIMDE_POLY16_C(  423), SIMDE_POLY16_C( 4896), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50158) },
        { { SIMDE_POLY16_C(20209), SIMDE_POLY16_C(46026), SIMDE_POLY16_C(35198), SIMDE_POLY16_C(33677), SIMDE_POLY16_C(21554), SIMDE_POLY16_C(31615), SIMDE_POLY16_C(  423), SIMDE_POLY16_C(62312) },
          { SIMDE_POLY16_C(47336), SIMDE_POLY16_C(11003), SIMDE_POLY16_C( 9966), SIMDE_POLY16_C(30156), SIMDE_POLY16_C( 6029), SIMDE_POLY16_C(  923), SIMDE_POLY16_C( 4896), SIMDE_POLY16_C( 9752) },
          { SIMDE_POLY16_C(58343), SIMDE_POLY16_C(26073), SIMDE_POLY16_C(26476), SIMDE_POLY16_C(40680), SIMDE_POLY16_C(26811), SIMDE_POLY16_C( 1817), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(49146) },
          { SIMDE_POLY16_C(63034), SIMDE_POLY16_C(10729), SIMDE_POLY16_C(46620), SIMDE_POLY16_C(43422), SIMDE_POLY16_C(15053), SIMDE_POLY16_C(  428), SIMDE_POLY16_C(50158), SIMDE_POLY16_C(47911) } },
    },
    {
        { { SIMDE_POLY16_C( 2408), SIMDE_POLY16_C( 9137), SIMDE_POLY16_C(52081), SIMDE_POLY16_C(18474), SIMDE_POLY16_C( 9549), SIMDE_POLY16_C(34568), SIMDE_POLY16_C(61723), SIMDE_POLY16_C(14256) },
          { SIMDE_POLY16_C(20391), SIMDE_POLY16_C(29920), SIMDE_POLY16_C(35977), SIMDE_POLY16_C(23670), SIMDE_POLY16_C(40272), SIMDE_POLY16_C(63511), SIMDE_POLY16_C(14494), SIMDE_POLY16_C( 1547) },
          { SIMDE_POLY16_C(48449), SIMDE_POLY16_C(45609), SIMDE_POLY16_C(21640), SIMDE_POLY16_C(54778), SIMDE_POLY16_C(  633), SIMDE_POLY16_C(37980), SIMDE_POLY16_C( 3572), SIMDE_POLY16_C(39883) },
          { SIMDE_POLY16_C(43868), SIMDE_POLY16_C(58640), SIMDE_POLY16_C(34359), SIMDE_POLY16_C(34625), SIMDE_POLY16_C(22819), SIMDE_POLY16_C(49791), SIMDE_POLY16_C(35729), SIMDE_POLY16_C(53960) } },
      { SIMDE_POLY16_C(62024), SIMDE_POLY16_C(53380), SIMDE_POLY16_C(62106), SIMDE_POLY16_C(50158) },
        { { SIMDE_POLY16_C( 2408), SIMDE_POLY16_C( 9137), SIMDE_POLY16_C(52081), SIMDE_POLY16_C(18474), SIMDE_POLY16_C( 9549), SIMDE_POLY16_C(34568), SIMDE_POLY16_C(61723), SIMDE_POLY16_C(62024) },
          { SIMDE_POLY16_C(20391), SIMDE_POLY16_C(29920), SIMDE_POLY16_C(35977), SIMDE_POLY16_C(23670), SIMDE_POLY16_C(40272), SIMDE_POLY16_C(63511), SIMDE_POLY16_C(14494), SIMDE_POLY16_C(53380) },
          { SIMDE_POLY16_C(48449), SIMDE_POLY16_C(45609), SIMDE_POLY16_C(21640), SIMDE_POLY16_C(54778), SIMDE_POLY16_C(  633), SIMDE_POLY16_C(37980), SIMDE_POLY16_C( 3572), SIMDE_POLY16_C(62106) },
          { SIMDE_POLY16_C(43868), SIMDE_POLY16_C(58640), SIMDE_POLY16_C(34359), SIMDE_POLY16_C(34625), SIMDE_POLY16_C(22819), SIMDE_POLY16_C(49791), SIMDE_POLY16_C(35729), SIMDE_POLY16_C(50158) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8x4_t r;
    simde_poly16x8x4_t src = {
        {simde_vld1q_p16(test_vec[i].src[0]), simde_vld1q_p16(test_vec[i].src[1]),
         simde_vld1q_p16(test_vec[i].src[2]), simde_vld1q_p16(test_vec[i].src[3])}};
    simde_poly16x8x4_t expected = {
        {simde_vld1q_p16(test_vec[i].r[0]), simde_vld1q_p16(test_vec[i].r[1]),
         simde_vld1q_p16(test_vec[i].r[2]), simde_vld1q_p16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_8_(simde_vld4q_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_p16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8x4_t src = simde_test_arm_neon_random_p16x8x4();
    simde_poly16_t buf[4];
    simde_poly16x8x4_t r;
    simde_test_arm_neon_write_p16x8x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(8, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp16(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_8_(simde_vld4q_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p16x8x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t src[4][2];
    simde_poly64_t buf[4];
    simde_poly64_t r[4][2];
  } test_vec[] = {
    {
        { { SIMDE_POLY64_C(17121197771361529538), SIMDE_POLY64_C(12559884741173414735) },
          { SIMDE_POLY64_C(18136334143755149311), SIMDE_POLY64_C(12604904566085579545) },
          { SIMDE_POLY64_C( 3018120776255087435), SIMDE_POLY64_C(  747306217770737423) },
          { SIMDE_POLY64_C(18096011830869733206), SIMDE_POLY64_C( 4935728556959095781) } },
      { SIMDE_POLY64_C(18185565996674803805), SIMDE_POLY64_C( 6381611677932849786), SIMDE_POLY64_C(12148073806866403769), SIMDE_POLY64_C( 8807061878862373884) },
        { { SIMDE_POLY64_C(18185565996674803805), SIMDE_POLY64_C(12559884741173414735) },
          { SIMDE_POLY64_C( 6381611677932849786), SIMDE_POLY64_C(12604904566085579545) },
          { SIMDE_POLY64_C(12148073806866403769), SIMDE_POLY64_C(  747306217770737423) },
          { SIMDE_POLY64_C( 8807061878862373884), SIMDE_POLY64_C( 4935728556959095781) } },
    },
    {
        { { SIMDE_POLY64_C(  452913631335706977), SIMDE_POLY64_C(13364181206100145437) },
          { SIMDE_POLY64_C(10617495158256957165), SIMDE_POLY64_C( 3127398969022862030) },
          { SIMDE_POLY64_C( 5171471760968194097), SIMDE_POLY64_C( 6445177100275437752) },
          { SIMDE_POLY64_C( 9294975199378786004), SIMDE_POLY64_C( 8586906841893340724) } },
      { SIMDE_POLY64_C( 2115841236994991082), SIMDE_POLY64_C( 8435320857669517898), SIMDE_POLY64_C(12700396676072872461), SIMDE_POLY64_C( 7503797967710497893) },
        { { SIMDE_POLY64_C(  452913631335706977), SIMDE_POLY64_C( 2115841236994991082) },
          { SIMDE_POLY64_C(10617495158256957165), SIMDE_POLY64_C( 8435320857669517898) },
          { SIMDE_POLY64_C( 5171471760968194097), SIMDE_POLY64_C(12700396676072872461) },
          { SIMDE_POLY64_C( 9294975199378786004), SIMDE_POLY64_C( 7503797967710497893) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2x4_t r;
    simde_poly64x2x4_t src = {
        {simde_vld1q_p64(test_vec[i].src[0]), simde_vld1q_p64(test_vec[i].src[1]),
         simde_vld1q_p64(test_vec[i].src[2]), simde_vld1q_p64(test_vec[i].src[3])}};

    simde_poly64x2x4_t expected = {
        {simde_vld1q_p64(test_vec[i].r[0]), simde_vld1q_p64(test_vec[i].r[1]),
         simde_vld1q_p64(test_vec[i].r[2]), simde_vld1q_p64(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_2_(simde_vld4q_lane_p64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_p64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_poly64x2x4_t src = simde_test_arm_neon_random_p64x2x4();
    simde_poly64_t buf[4];
    simde_poly64x2x4_t r;
    simde_test_arm_neon_write_p64x2x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(32, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp64(2, 4, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_2_(simde_vld4q_lane_p64, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p64x2x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t src[4][4];
    simde_bfloat16_t buf[4];
    simde_bfloat16_t r[4][4];
  } test_vec[] = {
   { { {  SIMDE_BFLOAT16_VALUE(-23.48), SIMDE_BFLOAT16_VALUE(-23.67), SIMDE_BFLOAT16_VALUE(44.71), SIMDE_BFLOAT16_VALUE(-48.89) },
       {  SIMDE_BFLOAT16_VALUE(46.07), SIMDE_BFLOAT16_VALUE(-4.26), SIMDE_BFLOAT16_VALUE(-33.58), SIMDE_BFLOAT16_VALUE(-23.36) },
       {  SIMDE_BFLOAT16_VALUE(45.79), SIMDE_BFLOAT16_VALUE(8.17), SIMDE_BFLOAT16_VALUE(41.11), SIMDE_BFLOAT16_VALUE(24.71) },
       {  SIMDE_BFLOAT16_VALUE(-6.19), SIMDE_BFLOAT16_VALUE(-19.02), SIMDE_BFLOAT16_VALUE(4.14), SIMDE_BFLOAT16_VALUE(9.43) } },
       {  SIMDE_BFLOAT16_VALUE(-1.12), SIMDE_BFLOAT16_VALUE(-28.65), SIMDE_BFLOAT16_VALUE(-39.28), SIMDE_BFLOAT16_VALUE(-49.01)},
     { {  SIMDE_BFLOAT16_VALUE(-1.12), SIMDE_BFLOAT16_VALUE(-23.67), SIMDE_BFLOAT16_VALUE(44.71), SIMDE_BFLOAT16_VALUE(-48.89) },
       {  SIMDE_BFLOAT16_VALUE(-28.65), SIMDE_BFLOAT16_VALUE(-4.26), SIMDE_BFLOAT16_VALUE(-33.58), SIMDE_BFLOAT16_VALUE(-23.36) },
       {  SIMDE_BFLOAT16_VALUE(-39.28), SIMDE_BFLOAT16_VALUE(8.17), SIMDE_BFLOAT16_VALUE(41.11), SIMDE_BFLOAT16_VALUE(24.71) },
       {  SIMDE_BFLOAT16_VALUE(-49.01), SIMDE_BFLOAT16_VALUE(-19.02), SIMDE_BFLOAT16_VALUE(4.14), SIMDE_BFLOAT16_VALUE(9.43) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-14.34), SIMDE_BFLOAT16_VALUE(23.49), SIMDE_BFLOAT16_VALUE(-10.62), SIMDE_BFLOAT16_VALUE(39.64) },
       {  SIMDE_BFLOAT16_VALUE(-31.94), SIMDE_BFLOAT16_VALUE(-41.05), SIMDE_BFLOAT16_VALUE(20.30), SIMDE_BFLOAT16_VALUE(-28.08) },
       {  SIMDE_BFLOAT16_VALUE(-46.77), SIMDE_BFLOAT16_VALUE(-6.97), SIMDE_BFLOAT16_VALUE(10.38), SIMDE_BFLOAT16_VALUE(12.19) },
       {  SIMDE_BFLOAT16_VALUE(41.44), SIMDE_BFLOAT16_VALUE(-47.57), SIMDE_BFLOAT16_VALUE(-43.76), SIMDE_BFLOAT16_VALUE(26.14) } },
       {  SIMDE_BFLOAT16_VALUE(-20.20), SIMDE_BFLOAT16_VALUE(43.64), SIMDE_BFLOAT16_VALUE(11.06), SIMDE_BFLOAT16_VALUE(-41.55)},
     { {  SIMDE_BFLOAT16_VALUE(-14.34), SIMDE_BFLOAT16_VALUE(-20.20), SIMDE_BFLOAT16_VALUE(-10.62), SIMDE_BFLOAT16_VALUE(39.64) },
       {  SIMDE_BFLOAT16_VALUE(-31.94), SIMDE_BFLOAT16_VALUE(43.64), SIMDE_BFLOAT16_VALUE(20.30), SIMDE_BFLOAT16_VALUE(-28.08) },
       {  SIMDE_BFLOAT16_VALUE(-46.77), SIMDE_BFLOAT16_VALUE(11.06), SIMDE_BFLOAT16_VALUE(10.38), SIMDE_BFLOAT16_VALUE(12.19) },
       {  SIMDE_BFLOAT16_VALUE(41.44), SIMDE_BFLOAT16_VALUE(-41.55), SIMDE_BFLOAT16_VALUE(-43.76), SIMDE_BFLOAT16_VALUE(26.14) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-49.94), SIMDE_BFLOAT16_VALUE(-3.45), SIMDE_BFLOAT16_VALUE(-18.16), SIMDE_BFLOAT16_VALUE(-35.32) },
       {  SIMDE_BFLOAT16_VALUE(-39.02), SIMDE_BFLOAT16_VALUE(20.10), SIMDE_BFLOAT16_VALUE(9.41), SIMDE_BFLOAT16_VALUE(-12.84) },
       {  SIMDE_BFLOAT16_VALUE(-20.30), SIMDE_BFLOAT16_VALUE(18.38), SIMDE_BFLOAT16_VALUE(36.37), SIMDE_BFLOAT16_VALUE(-15.62) },
       {  SIMDE_BFLOAT16_VALUE(27.10), SIMDE_BFLOAT16_VALUE(-38.20), SIMDE_BFLOAT16_VALUE(-15.40), SIMDE_BFLOAT16_VALUE(-20.21) } },
       {  SIMDE_BFLOAT16_VALUE(-9.89), SIMDE_BFLOAT16_VALUE(-2.32), SIMDE_BFLOAT16_VALUE(-33.75), SIMDE_BFLOAT16_VALUE(25.64)},
     { {  SIMDE_BFLOAT16_VALUE(-49.94), SIMDE_BFLOAT16_VALUE(-3.45), SIMDE_BFLOAT16_VALUE(-9.89), SIMDE_BFLOAT16_VALUE(-35.32) },
       {  SIMDE_BFLOAT16_VALUE(-39.02), SIMDE_BFLOAT16_VALUE(20.10), SIMDE_BFLOAT16_VALUE(-2.32), SIMDE_BFLOAT16_VALUE(-12.84) },
       {  SIMDE_BFLOAT16_VALUE(-20.30), SIMDE_BFLOAT16_VALUE(18.38), SIMDE_BFLOAT16_VALUE(-33.75), SIMDE_BFLOAT16_VALUE(-15.62) },
       {  SIMDE_BFLOAT16_VALUE(27.10), SIMDE_BFLOAT16_VALUE(-38.20), SIMDE_BFLOAT16_VALUE(25.64), SIMDE_BFLOAT16_VALUE(-20.21) } } },
   { { {  SIMDE_BFLOAT16_VALUE(28.09), SIMDE_BFLOAT16_VALUE(-29.96), SIMDE_BFLOAT16_VALUE(28.29), SIMDE_BFLOAT16_VALUE(-15.35) },
       {  SIMDE_BFLOAT16_VALUE(15.14), SIMDE_BFLOAT16_VALUE(-42.36), SIMDE_BFLOAT16_VALUE(-3.50), SIMDE_BFLOAT16_VALUE(11.41) },
       {  SIMDE_BFLOAT16_VALUE(-2.75), SIMDE_BFLOAT16_VALUE(20.25), SIMDE_BFLOAT16_VALUE(29.83), SIMDE_BFLOAT16_VALUE(45.27) },
       {  SIMDE_BFLOAT16_VALUE(22.78), SIMDE_BFLOAT16_VALUE(10.89), SIMDE_BFLOAT16_VALUE(42.55), SIMDE_BFLOAT16_VALUE(-45.91) } },
       {  SIMDE_BFLOAT16_VALUE(-8.61), SIMDE_BFLOAT16_VALUE(-39.93), SIMDE_BFLOAT16_VALUE(-16.44), SIMDE_BFLOAT16_VALUE(43.00)},
     { {  SIMDE_BFLOAT16_VALUE(28.09), SIMDE_BFLOAT16_VALUE(-29.96), SIMDE_BFLOAT16_VALUE(28.29), SIMDE_BFLOAT16_VALUE(-8.61) },
       {  SIMDE_BFLOAT16_VALUE(15.14), SIMDE_BFLOAT16_VALUE(-42.36), SIMDE_BFLOAT16_VALUE(-3.50), SIMDE_BFLOAT16_VALUE(-39.93) },
       {  SIMDE_BFLOAT16_VALUE(-2.75), SIMDE_BFLOAT16_VALUE(20.25), SIMDE_BFLOAT16_VALUE(29.83), SIMDE_BFLOAT16_VALUE(-16.44) },
       {  SIMDE_BFLOAT16_VALUE(22.78), SIMDE_BFLOAT16_VALUE(10.89), SIMDE_BFLOAT16_VALUE(42.55), SIMDE_BFLOAT16_VALUE(43.00) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4x4_t r;
    simde_bfloat16x4x4_t src = {
        {simde_vld1_bf16(test_vec[i].src[0]), simde_vld1_bf16(test_vec[i].src[1]),
         simde_vld1_bf16(test_vec[i].src[2]), simde_vld1_bf16(test_vec[i].src[3])}};
    simde_bfloat16x4x4_t expected = {
        {simde_vld1_bf16(test_vec[i].r[0]), simde_vld1_bf16(test_vec[i].r[1]),
         simde_vld1_bf16(test_vec[i].r[2]), simde_vld1_bf16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_4_(simde_vld4_lane_bf16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_bf16x4(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[1], expected.val[1], 1);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[2], expected.val[2], 1);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[3], expected.val[3], 1);
  }

  return 0;
}

static int
test_simde_vld4q_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t src[4][8];
    simde_bfloat16_t buf[4];
    simde_bfloat16_t r[4][8];
  } test_vec[] = {
   { { {  SIMDE_BFLOAT16_VALUE(6.33), SIMDE_BFLOAT16_VALUE(-26.33), SIMDE_BFLOAT16_VALUE(-42.22), SIMDE_BFLOAT16_VALUE(-34.31),
        SIMDE_BFLOAT16_VALUE(-14.99), SIMDE_BFLOAT16_VALUE(-21.27), SIMDE_BFLOAT16_VALUE(2.75), SIMDE_BFLOAT16_VALUE(47.13) },
       {  SIMDE_BFLOAT16_VALUE(-43.49), SIMDE_BFLOAT16_VALUE(17.65), SIMDE_BFLOAT16_VALUE(39.50), SIMDE_BFLOAT16_VALUE(-42.60),
        SIMDE_BFLOAT16_VALUE(36.05), SIMDE_BFLOAT16_VALUE(-8.32), SIMDE_BFLOAT16_VALUE(-40.92), SIMDE_BFLOAT16_VALUE(18.06) },
       {  SIMDE_BFLOAT16_VALUE(-42.88), SIMDE_BFLOAT16_VALUE(4.14), SIMDE_BFLOAT16_VALUE(45.09), SIMDE_BFLOAT16_VALUE(20.35),
        SIMDE_BFLOAT16_VALUE(-37.99), SIMDE_BFLOAT16_VALUE(6.50), SIMDE_BFLOAT16_VALUE(-31.38), SIMDE_BFLOAT16_VALUE(7.92) },
       {  SIMDE_BFLOAT16_VALUE(-39.25), SIMDE_BFLOAT16_VALUE(-28.22), SIMDE_BFLOAT16_VALUE(-2.20), SIMDE_BFLOAT16_VALUE(-44.73),
        SIMDE_BFLOAT16_VALUE(-39.75), SIMDE_BFLOAT16_VALUE(48.64), SIMDE_BFLOAT16_VALUE(-28.85), SIMDE_BFLOAT16_VALUE(-41.84) } },
       {  SIMDE_BFLOAT16_VALUE(28.80), SIMDE_BFLOAT16_VALUE(25.22), SIMDE_BFLOAT16_VALUE(20.66), SIMDE_BFLOAT16_VALUE(48.85)},
     { {  SIMDE_BFLOAT16_VALUE(28.80), SIMDE_BFLOAT16_VALUE(-26.33), SIMDE_BFLOAT16_VALUE(-42.22), SIMDE_BFLOAT16_VALUE(-34.31),
        SIMDE_BFLOAT16_VALUE(-14.99), SIMDE_BFLOAT16_VALUE(-21.27), SIMDE_BFLOAT16_VALUE(2.75), SIMDE_BFLOAT16_VALUE(47.13) },
       {  SIMDE_BFLOAT16_VALUE(25.22), SIMDE_BFLOAT16_VALUE(17.65), SIMDE_BFLOAT16_VALUE(39.50), SIMDE_BFLOAT16_VALUE(-42.60),
        SIMDE_BFLOAT16_VALUE(36.05), SIMDE_BFLOAT16_VALUE(-8.32), SIMDE_BFLOAT16_VALUE(-40.92), SIMDE_BFLOAT16_VALUE(18.06) },
       {  SIMDE_BFLOAT16_VALUE(20.66), SIMDE_BFLOAT16_VALUE(4.14), SIMDE_BFLOAT16_VALUE(45.09), SIMDE_BFLOAT16_VALUE(20.35),
        SIMDE_BFLOAT16_VALUE(-37.99), SIMDE_BFLOAT16_VALUE(6.50), SIMDE_BFLOAT16_VALUE(-31.38), SIMDE_BFLOAT16_VALUE(7.92) },
       {  SIMDE_BFLOAT16_VALUE(48.85), SIMDE_BFLOAT16_VALUE(-28.22), SIMDE_BFLOAT16_VALUE(-2.20), SIMDE_BFLOAT16_VALUE(-44.73),
        SIMDE_BFLOAT16_VALUE(-39.75), SIMDE_BFLOAT16_VALUE(48.64), SIMDE_BFLOAT16_VALUE(-28.85), SIMDE_BFLOAT16_VALUE(-41.84) } } },
   { { {  SIMDE_BFLOAT16_VALUE(42.30), SIMDE_BFLOAT16_VALUE(4.65), SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-43.56),
        SIMDE_BFLOAT16_VALUE(46.24), SIMDE_BFLOAT16_VALUE(23.63), SIMDE_BFLOAT16_VALUE(-33.71), SIMDE_BFLOAT16_VALUE(-41.85) },
       {  SIMDE_BFLOAT16_VALUE(46.94), SIMDE_BFLOAT16_VALUE(30.22), SIMDE_BFLOAT16_VALUE(3.71), SIMDE_BFLOAT16_VALUE(1.50),
        SIMDE_BFLOAT16_VALUE(-25.07), SIMDE_BFLOAT16_VALUE(42.19), SIMDE_BFLOAT16_VALUE(-19.27), SIMDE_BFLOAT16_VALUE(-23.97) },
       {  SIMDE_BFLOAT16_VALUE(-27.49), SIMDE_BFLOAT16_VALUE(41.45), SIMDE_BFLOAT16_VALUE(43.62), SIMDE_BFLOAT16_VALUE(28.98),
        SIMDE_BFLOAT16_VALUE(-2.13), SIMDE_BFLOAT16_VALUE(24.85), SIMDE_BFLOAT16_VALUE(-34.40), SIMDE_BFLOAT16_VALUE(-36.80) },
       {  SIMDE_BFLOAT16_VALUE(9.29), SIMDE_BFLOAT16_VALUE(19.68), SIMDE_BFLOAT16_VALUE(-47.75), SIMDE_BFLOAT16_VALUE(7.71),
        SIMDE_BFLOAT16_VALUE(-15.37), SIMDE_BFLOAT16_VALUE(-22.42), SIMDE_BFLOAT16_VALUE(-24.53), SIMDE_BFLOAT16_VALUE(-31.46) } },
       {  SIMDE_BFLOAT16_VALUE(6.38), SIMDE_BFLOAT16_VALUE(-5.55), SIMDE_BFLOAT16_VALUE(14.51), SIMDE_BFLOAT16_VALUE(22.81)},
     { {  SIMDE_BFLOAT16_VALUE(42.30), SIMDE_BFLOAT16_VALUE(6.38), SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-43.56),
        SIMDE_BFLOAT16_VALUE(46.24), SIMDE_BFLOAT16_VALUE(23.63), SIMDE_BFLOAT16_VALUE(-33.71), SIMDE_BFLOAT16_VALUE(-41.85) },
       {  SIMDE_BFLOAT16_VALUE(46.94), SIMDE_BFLOAT16_VALUE(-5.55), SIMDE_BFLOAT16_VALUE(3.71), SIMDE_BFLOAT16_VALUE(1.50),
        SIMDE_BFLOAT16_VALUE(-25.07), SIMDE_BFLOAT16_VALUE(42.19), SIMDE_BFLOAT16_VALUE(-19.27), SIMDE_BFLOAT16_VALUE(-23.97) },
       {  SIMDE_BFLOAT16_VALUE(-27.49), SIMDE_BFLOAT16_VALUE(14.51), SIMDE_BFLOAT16_VALUE(43.62), SIMDE_BFLOAT16_VALUE(28.98),
        SIMDE_BFLOAT16_VALUE(-2.13), SIMDE_BFLOAT16_VALUE(24.85), SIMDE_BFLOAT16_VALUE(-34.40), SIMDE_BFLOAT16_VALUE(-36.80) },
       {  SIMDE_BFLOAT16_VALUE(9.29), SIMDE_BFLOAT16_VALUE(22.81), SIMDE_BFLOAT16_VALUE(-47.75), SIMDE_BFLOAT16_VALUE(7.71),
        SIMDE_BFLOAT16_VALUE(-15.37), SIMDE_BFLOAT16_VALUE(-22.42), SIMDE_BFLOAT16_VALUE(-24.53), SIMDE_BFLOAT16_VALUE(-31.46) } } },
   { { {  SIMDE_BFLOAT16_VALUE(4.77), SIMDE_BFLOAT16_VALUE(19.23), SIMDE_BFLOAT16_VALUE(19.73), SIMDE_BFLOAT16_VALUE(-7.18),
        SIMDE_BFLOAT16_VALUE(-27.37), SIMDE_BFLOAT16_VALUE(-20.24), SIMDE_BFLOAT16_VALUE(49.18), SIMDE_BFLOAT16_VALUE(-24.81) },
       {  SIMDE_BFLOAT16_VALUE(-11.08), SIMDE_BFLOAT16_VALUE(-46.49), SIMDE_BFLOAT16_VALUE(2.52), SIMDE_BFLOAT16_VALUE(26.02),
        SIMDE_BFLOAT16_VALUE(24.04), SIMDE_BFLOAT16_VALUE(47.33), SIMDE_BFLOAT16_VALUE(-44.39), SIMDE_BFLOAT16_VALUE(12.98) },
       {  SIMDE_BFLOAT16_VALUE(-31.55), SIMDE_BFLOAT16_VALUE(14.16), SIMDE_BFLOAT16_VALUE(-20.43), SIMDE_BFLOAT16_VALUE(-34.07),
        SIMDE_BFLOAT16_VALUE(-49.98), SIMDE_BFLOAT16_VALUE(10.50), SIMDE_BFLOAT16_VALUE(15.65), SIMDE_BFLOAT16_VALUE(-48.67) },
       {  SIMDE_BFLOAT16_VALUE(-11.29), SIMDE_BFLOAT16_VALUE(1.88), SIMDE_BFLOAT16_VALUE(-32.68), SIMDE_BFLOAT16_VALUE(-24.01),
        SIMDE_BFLOAT16_VALUE(-1.11), SIMDE_BFLOAT16_VALUE(3.86), SIMDE_BFLOAT16_VALUE(27.69), SIMDE_BFLOAT16_VALUE(26.05) } },
       {  SIMDE_BFLOAT16_VALUE(10.65), SIMDE_BFLOAT16_VALUE(-21.85), SIMDE_BFLOAT16_VALUE(14.55), SIMDE_BFLOAT16_VALUE(6.24)},
     { {  SIMDE_BFLOAT16_VALUE(4.77), SIMDE_BFLOAT16_VALUE(19.23), SIMDE_BFLOAT16_VALUE(10.65), SIMDE_BFLOAT16_VALUE(-7.18),
        SIMDE_BFLOAT16_VALUE(-27.37), SIMDE_BFLOAT16_VALUE(-20.24), SIMDE_BFLOAT16_VALUE(49.18), SIMDE_BFLOAT16_VALUE(-24.81) },
       {  SIMDE_BFLOAT16_VALUE(-11.08), SIMDE_BFLOAT16_VALUE(-46.49), SIMDE_BFLOAT16_VALUE(-21.85), SIMDE_BFLOAT16_VALUE(26.02),
        SIMDE_BFLOAT16_VALUE(24.04), SIMDE_BFLOAT16_VALUE(47.33), SIMDE_BFLOAT16_VALUE(-44.39), SIMDE_BFLOAT16_VALUE(12.98) },
       {  SIMDE_BFLOAT16_VALUE(-31.55), SIMDE_BFLOAT16_VALUE(14.16), SIMDE_BFLOAT16_VALUE(14.55), SIMDE_BFLOAT16_VALUE(-34.07),
        SIMDE_BFLOAT16_VALUE(-49.98), SIMDE_BFLOAT16_VALUE(10.50), SIMDE_BFLOAT16_VALUE(15.65), SIMDE_BFLOAT16_VALUE(-48.67) },
       {  SIMDE_BFLOAT16_VALUE(-11.29), SIMDE_BFLOAT16_VALUE(1.88), SIMDE_BFLOAT16_VALUE(6.24), SIMDE_BFLOAT16_VALUE(-24.01),
        SIMDE_BFLOAT16_VALUE(-1.11), SIMDE_BFLOAT16_VALUE(3.86), SIMDE_BFLOAT16_VALUE(27.69), SIMDE_BFLOAT16_VALUE(26.05) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-39.56), SIMDE_BFLOAT16_VALUE(46.56), SIMDE_BFLOAT16_VALUE(37.88), SIMDE_BFLOAT16_VALUE(-34.85),
        SIMDE_BFLOAT16_VALUE(-42.50), SIMDE_BFLOAT16_VALUE(47.33), SIMDE_BFLOAT16_VALUE(30.39), SIMDE_BFLOAT16_VALUE(26.97) },
       {  SIMDE_BFLOAT16_VALUE(12.13), SIMDE_BFLOAT16_VALUE(13.90), SIMDE_BFLOAT16_VALUE(-11.09), SIMDE_BFLOAT16_VALUE(-46.55),
        SIMDE_BFLOAT16_VALUE(-25.60), SIMDE_BFLOAT16_VALUE(36.32), SIMDE_BFLOAT16_VALUE(38.43), SIMDE_BFLOAT16_VALUE(-15.44) },
       {  SIMDE_BFLOAT16_VALUE(14.57), SIMDE_BFLOAT16_VALUE(-33.72), SIMDE_BFLOAT16_VALUE(17.48), SIMDE_BFLOAT16_VALUE(-41.97),
        SIMDE_BFLOAT16_VALUE(39.90), SIMDE_BFLOAT16_VALUE(12.95), SIMDE_BFLOAT16_VALUE(-24.90), SIMDE_BFLOAT16_VALUE(22.89) },
       {  SIMDE_BFLOAT16_VALUE(33.49), SIMDE_BFLOAT16_VALUE(-29.52), SIMDE_BFLOAT16_VALUE(-42.35), SIMDE_BFLOAT16_VALUE(11.54),
        SIMDE_BFLOAT16_VALUE(-19.29), SIMDE_BFLOAT16_VALUE(-3.97), SIMDE_BFLOAT16_VALUE(39.49), SIMDE_BFLOAT16_VALUE(34.87) } },
       {  SIMDE_BFLOAT16_VALUE(22.68), SIMDE_BFLOAT16_VALUE(-10.73), SIMDE_BFLOAT16_VALUE(1.03), SIMDE_BFLOAT16_VALUE(9.92)},
     { {  SIMDE_BFLOAT16_VALUE(-39.56), SIMDE_BFLOAT16_VALUE(46.56), SIMDE_BFLOAT16_VALUE(37.88), SIMDE_BFLOAT16_VALUE(22.68),
        SIMDE_BFLOAT16_VALUE(-42.50), SIMDE_BFLOAT16_VALUE(47.33), SIMDE_BFLOAT16_VALUE(30.39), SIMDE_BFLOAT16_VALUE(26.97) },
       {  SIMDE_BFLOAT16_VALUE(12.13), SIMDE_BFLOAT16_VALUE(13.90), SIMDE_BFLOAT16_VALUE(-11.09), SIMDE_BFLOAT16_VALUE(-10.73),
        SIMDE_BFLOAT16_VALUE(-25.60), SIMDE_BFLOAT16_VALUE(36.32), SIMDE_BFLOAT16_VALUE(38.43), SIMDE_BFLOAT16_VALUE(-15.44) },
       {  SIMDE_BFLOAT16_VALUE(14.57), SIMDE_BFLOAT16_VALUE(-33.72), SIMDE_BFLOAT16_VALUE(17.48), SIMDE_BFLOAT16_VALUE(1.03),
        SIMDE_BFLOAT16_VALUE(39.90), SIMDE_BFLOAT16_VALUE(12.95), SIMDE_BFLOAT16_VALUE(-24.90), SIMDE_BFLOAT16_VALUE(22.89) },
       {  SIMDE_BFLOAT16_VALUE(33.49), SIMDE_BFLOAT16_VALUE(-29.52), SIMDE_BFLOAT16_VALUE(-42.35), SIMDE_BFLOAT16_VALUE(9.92),
        SIMDE_BFLOAT16_VALUE(-19.29), SIMDE_BFLOAT16_VALUE(-3.97), SIMDE_BFLOAT16_VALUE(39.49), SIMDE_BFLOAT16_VALUE(34.87) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-8.17), SIMDE_BFLOAT16_VALUE(20.98), SIMDE_BFLOAT16_VALUE(-36.48), SIMDE_BFLOAT16_VALUE(-2.58),
        SIMDE_BFLOAT16_VALUE(45.57), SIMDE_BFLOAT16_VALUE(1.57), SIMDE_BFLOAT16_VALUE(-6.19), SIMDE_BFLOAT16_VALUE(-12.44) },
       {  SIMDE_BFLOAT16_VALUE(45.85), SIMDE_BFLOAT16_VALUE(24.95), SIMDE_BFLOAT16_VALUE(28.89), SIMDE_BFLOAT16_VALUE(49.69),
        SIMDE_BFLOAT16_VALUE(1.21), SIMDE_BFLOAT16_VALUE(-33.38), SIMDE_BFLOAT16_VALUE(-40.61), SIMDE_BFLOAT16_VALUE(21.68) },
       {  SIMDE_BFLOAT16_VALUE(46.23), SIMDE_BFLOAT16_VALUE(-16.19), SIMDE_BFLOAT16_VALUE(-35.91), SIMDE_BFLOAT16_VALUE(43.87),
        SIMDE_BFLOAT16_VALUE(30.36), SIMDE_BFLOAT16_VALUE(-1.03), SIMDE_BFLOAT16_VALUE(19.56), SIMDE_BFLOAT16_VALUE(33.86) },
       {  SIMDE_BFLOAT16_VALUE(-24.84), SIMDE_BFLOAT16_VALUE(13.50), SIMDE_BFLOAT16_VALUE(29.52), SIMDE_BFLOAT16_VALUE(41.09),
        SIMDE_BFLOAT16_VALUE(-18.40), SIMDE_BFLOAT16_VALUE(40.70), SIMDE_BFLOAT16_VALUE(0.08), SIMDE_BFLOAT16_VALUE(19.83) } },
       {  SIMDE_BFLOAT16_VALUE(38.14), SIMDE_BFLOAT16_VALUE(-31.15), SIMDE_BFLOAT16_VALUE(18.94), SIMDE_BFLOAT16_VALUE(21.21)},
     { {  SIMDE_BFLOAT16_VALUE(-8.17), SIMDE_BFLOAT16_VALUE(20.98), SIMDE_BFLOAT16_VALUE(-36.48), SIMDE_BFLOAT16_VALUE(-2.58),
        SIMDE_BFLOAT16_VALUE(38.14), SIMDE_BFLOAT16_VALUE(1.57), SIMDE_BFLOAT16_VALUE(-6.19), SIMDE_BFLOAT16_VALUE(-12.44) },
       {  SIMDE_BFLOAT16_VALUE(45.85), SIMDE_BFLOAT16_VALUE(24.95), SIMDE_BFLOAT16_VALUE(28.89), SIMDE_BFLOAT16_VALUE(49.69),
        SIMDE_BFLOAT16_VALUE(-31.15), SIMDE_BFLOAT16_VALUE(-33.38), SIMDE_BFLOAT16_VALUE(-40.61), SIMDE_BFLOAT16_VALUE(21.68) },
       {  SIMDE_BFLOAT16_VALUE(46.23), SIMDE_BFLOAT16_VALUE(-16.19), SIMDE_BFLOAT16_VALUE(-35.91), SIMDE_BFLOAT16_VALUE(43.87),
        SIMDE_BFLOAT16_VALUE(18.94), SIMDE_BFLOAT16_VALUE(-1.03), SIMDE_BFLOAT16_VALUE(19.56), SIMDE_BFLOAT16_VALUE(33.86) },
       {  SIMDE_BFLOAT16_VALUE(-24.84), SIMDE_BFLOAT16_VALUE(13.50), SIMDE_BFLOAT16_VALUE(29.52), SIMDE_BFLOAT16_VALUE(41.09),
        SIMDE_BFLOAT16_VALUE(21.21), SIMDE_BFLOAT16_VALUE(40.70), SIMDE_BFLOAT16_VALUE(0.08), SIMDE_BFLOAT16_VALUE(19.83) } } },
   { { {  SIMDE_BFLOAT16_VALUE(32.92), SIMDE_BFLOAT16_VALUE(-0.80), SIMDE_BFLOAT16_VALUE(-42.65), SIMDE_BFLOAT16_VALUE(-15.22),
        SIMDE_BFLOAT16_VALUE(-16.39), SIMDE_BFLOAT16_VALUE(11.52), SIMDE_BFLOAT16_VALUE(-4.14), SIMDE_BFLOAT16_VALUE(8.87) },
       {  SIMDE_BFLOAT16_VALUE(-35.81), SIMDE_BFLOAT16_VALUE(12.74), SIMDE_BFLOAT16_VALUE(-12.60), SIMDE_BFLOAT16_VALUE(21.59),
        SIMDE_BFLOAT16_VALUE(-11.53), SIMDE_BFLOAT16_VALUE(44.02), SIMDE_BFLOAT16_VALUE(30.30), SIMDE_BFLOAT16_VALUE(43.42) },
       {  SIMDE_BFLOAT16_VALUE(16.67), SIMDE_BFLOAT16_VALUE(0.23), SIMDE_BFLOAT16_VALUE(-4.88), SIMDE_BFLOAT16_VALUE(-5.00),
        SIMDE_BFLOAT16_VALUE(36.67), SIMDE_BFLOAT16_VALUE(43.56), SIMDE_BFLOAT16_VALUE(-15.15), SIMDE_BFLOAT16_VALUE(-34.82) },
       {  SIMDE_BFLOAT16_VALUE(-22.22), SIMDE_BFLOAT16_VALUE(-41.78), SIMDE_BFLOAT16_VALUE(-15.90), SIMDE_BFLOAT16_VALUE(-36.65),
        SIMDE_BFLOAT16_VALUE(34.10), SIMDE_BFLOAT16_VALUE(22.36), SIMDE_BFLOAT16_VALUE(-4.57), SIMDE_BFLOAT16_VALUE(-42.90) } },
       {  SIMDE_BFLOAT16_VALUE(-30.23), SIMDE_BFLOAT16_VALUE(-33.22), SIMDE_BFLOAT16_VALUE(14.26), SIMDE_BFLOAT16_VALUE(-48.15)},
     { {  SIMDE_BFLOAT16_VALUE(32.92), SIMDE_BFLOAT16_VALUE(-0.80), SIMDE_BFLOAT16_VALUE(-42.65), SIMDE_BFLOAT16_VALUE(-15.22),
        SIMDE_BFLOAT16_VALUE(-16.39), SIMDE_BFLOAT16_VALUE(-30.23), SIMDE_BFLOAT16_VALUE(-4.14), SIMDE_BFLOAT16_VALUE(8.87) },
       {  SIMDE_BFLOAT16_VALUE(-35.81), SIMDE_BFLOAT16_VALUE(12.74), SIMDE_BFLOAT16_VALUE(-12.60), SIMDE_BFLOAT16_VALUE(21.59),
        SIMDE_BFLOAT16_VALUE(-11.53), SIMDE_BFLOAT16_VALUE(-33.22), SIMDE_BFLOAT16_VALUE(30.30), SIMDE_BFLOAT16_VALUE(43.42) },
       {  SIMDE_BFLOAT16_VALUE(16.67), SIMDE_BFLOAT16_VALUE(0.23), SIMDE_BFLOAT16_VALUE(-4.88), SIMDE_BFLOAT16_VALUE(-5.00),
        SIMDE_BFLOAT16_VALUE(36.67), SIMDE_BFLOAT16_VALUE(14.26), SIMDE_BFLOAT16_VALUE(-15.15), SIMDE_BFLOAT16_VALUE(-34.82) },
       {  SIMDE_BFLOAT16_VALUE(-22.22), SIMDE_BFLOAT16_VALUE(-41.78), SIMDE_BFLOAT16_VALUE(-15.90), SIMDE_BFLOAT16_VALUE(-36.65),
        SIMDE_BFLOAT16_VALUE(34.10), SIMDE_BFLOAT16_VALUE(-48.15), SIMDE_BFLOAT16_VALUE(-4.57), SIMDE_BFLOAT16_VALUE(-42.90) } } },
   { { {  SIMDE_BFLOAT16_VALUE(30.57), SIMDE_BFLOAT16_VALUE(-2.63), SIMDE_BFLOAT16_VALUE(-44.63), SIMDE_BFLOAT16_VALUE(15.88),
        SIMDE_BFLOAT16_VALUE(10.45), SIMDE_BFLOAT16_VALUE(45.63), SIMDE_BFLOAT16_VALUE(9.06), SIMDE_BFLOAT16_VALUE(-38.74) },
       {  SIMDE_BFLOAT16_VALUE(-26.14), SIMDE_BFLOAT16_VALUE(24.78), SIMDE_BFLOAT16_VALUE(19.94), SIMDE_BFLOAT16_VALUE(-27.09),
        SIMDE_BFLOAT16_VALUE(42.67), SIMDE_BFLOAT16_VALUE(1.81), SIMDE_BFLOAT16_VALUE(16.33), SIMDE_BFLOAT16_VALUE(-11.55) },
       {  SIMDE_BFLOAT16_VALUE(-48.80), SIMDE_BFLOAT16_VALUE(16.42), SIMDE_BFLOAT16_VALUE(-47.87), SIMDE_BFLOAT16_VALUE(-31.96),
        SIMDE_BFLOAT16_VALUE(22.97), SIMDE_BFLOAT16_VALUE(-48.97), SIMDE_BFLOAT16_VALUE(-19.78), SIMDE_BFLOAT16_VALUE(-5.38) },
       {  SIMDE_BFLOAT16_VALUE(-15.38), SIMDE_BFLOAT16_VALUE(21.21), SIMDE_BFLOAT16_VALUE(23.35), SIMDE_BFLOAT16_VALUE(0.40),
        SIMDE_BFLOAT16_VALUE(25.56), SIMDE_BFLOAT16_VALUE(31.88), SIMDE_BFLOAT16_VALUE(34.93), SIMDE_BFLOAT16_VALUE(30.41) } },
       {  SIMDE_BFLOAT16_VALUE(-17.21), SIMDE_BFLOAT16_VALUE(-48.48), SIMDE_BFLOAT16_VALUE(-7.06), SIMDE_BFLOAT16_VALUE(-26.40)},
     { {  SIMDE_BFLOAT16_VALUE(30.57), SIMDE_BFLOAT16_VALUE(-2.63), SIMDE_BFLOAT16_VALUE(-44.63), SIMDE_BFLOAT16_VALUE(15.88),
        SIMDE_BFLOAT16_VALUE(10.45), SIMDE_BFLOAT16_VALUE(45.63), SIMDE_BFLOAT16_VALUE(-17.21), SIMDE_BFLOAT16_VALUE(-38.74) },
       {  SIMDE_BFLOAT16_VALUE(-26.14), SIMDE_BFLOAT16_VALUE(24.78), SIMDE_BFLOAT16_VALUE(19.94), SIMDE_BFLOAT16_VALUE(-27.09),
        SIMDE_BFLOAT16_VALUE(42.67), SIMDE_BFLOAT16_VALUE(1.81), SIMDE_BFLOAT16_VALUE(-48.48), SIMDE_BFLOAT16_VALUE(-11.55) },
       {  SIMDE_BFLOAT16_VALUE(-48.80), SIMDE_BFLOAT16_VALUE(16.42), SIMDE_BFLOAT16_VALUE(-47.87), SIMDE_BFLOAT16_VALUE(-31.96),
        SIMDE_BFLOAT16_VALUE(22.97), SIMDE_BFLOAT16_VALUE(-48.97), SIMDE_BFLOAT16_VALUE(-7.06), SIMDE_BFLOAT16_VALUE(-5.38) },
       {  SIMDE_BFLOAT16_VALUE(-15.38), SIMDE_BFLOAT16_VALUE(21.21), SIMDE_BFLOAT16_VALUE(23.35), SIMDE_BFLOAT16_VALUE(0.40),
        SIMDE_BFLOAT16_VALUE(25.56), SIMDE_BFLOAT16_VALUE(31.88), SIMDE_BFLOAT16_VALUE(-26.40), SIMDE_BFLOAT16_VALUE(30.41) } } },
   { { {  SIMDE_BFLOAT16_VALUE(9.17), SIMDE_BFLOAT16_VALUE(21.02), SIMDE_BFLOAT16_VALUE(-31.99), SIMDE_BFLOAT16_VALUE(40.72),
        SIMDE_BFLOAT16_VALUE(-48.40), SIMDE_BFLOAT16_VALUE(-16.85), SIMDE_BFLOAT16_VALUE(-28.29), SIMDE_BFLOAT16_VALUE(-25.87) },
       {  SIMDE_BFLOAT16_VALUE(10.04), SIMDE_BFLOAT16_VALUE(11.19), SIMDE_BFLOAT16_VALUE(-9.39), SIMDE_BFLOAT16_VALUE(43.50),
        SIMDE_BFLOAT16_VALUE(20.72), SIMDE_BFLOAT16_VALUE(16.81), SIMDE_BFLOAT16_VALUE(31.83), SIMDE_BFLOAT16_VALUE(24.46) },
       {  SIMDE_BFLOAT16_VALUE(-6.31), SIMDE_BFLOAT16_VALUE(-39.46), SIMDE_BFLOAT16_VALUE(-33.35), SIMDE_BFLOAT16_VALUE(11.15),
        SIMDE_BFLOAT16_VALUE(-7.05), SIMDE_BFLOAT16_VALUE(26.22), SIMDE_BFLOAT16_VALUE(-36.64), SIMDE_BFLOAT16_VALUE(37.19) },
       {  SIMDE_BFLOAT16_VALUE(13.89), SIMDE_BFLOAT16_VALUE(26.04), SIMDE_BFLOAT16_VALUE(-44.10), SIMDE_BFLOAT16_VALUE(37.22),
        SIMDE_BFLOAT16_VALUE(10.55), SIMDE_BFLOAT16_VALUE(-21.52), SIMDE_BFLOAT16_VALUE(-10.01), SIMDE_BFLOAT16_VALUE(16.56) } },
       {  SIMDE_BFLOAT16_VALUE(-30.72), SIMDE_BFLOAT16_VALUE(-43.73), SIMDE_BFLOAT16_VALUE(28.26), SIMDE_BFLOAT16_VALUE(-33.82)},
     { {  SIMDE_BFLOAT16_VALUE(9.17), SIMDE_BFLOAT16_VALUE(21.02), SIMDE_BFLOAT16_VALUE(-31.99), SIMDE_BFLOAT16_VALUE(40.72),
        SIMDE_BFLOAT16_VALUE(-48.40), SIMDE_BFLOAT16_VALUE(-16.85), SIMDE_BFLOAT16_VALUE(-28.29), SIMDE_BFLOAT16_VALUE(-30.72) },
       {  SIMDE_BFLOAT16_VALUE(10.04), SIMDE_BFLOAT16_VALUE(11.19), SIMDE_BFLOAT16_VALUE(-9.39), SIMDE_BFLOAT16_VALUE(43.50),
        SIMDE_BFLOAT16_VALUE(20.72), SIMDE_BFLOAT16_VALUE(16.81), SIMDE_BFLOAT16_VALUE(31.83), SIMDE_BFLOAT16_VALUE(-43.73) },
       {  SIMDE_BFLOAT16_VALUE(-6.31), SIMDE_BFLOAT16_VALUE(-39.46), SIMDE_BFLOAT16_VALUE(-33.35), SIMDE_BFLOAT16_VALUE(11.15),
        SIMDE_BFLOAT16_VALUE(-7.05), SIMDE_BFLOAT16_VALUE(26.22), SIMDE_BFLOAT16_VALUE(-36.64), SIMDE_BFLOAT16_VALUE(28.26) },
       {  SIMDE_BFLOAT16_VALUE(13.89), SIMDE_BFLOAT16_VALUE(26.04), SIMDE_BFLOAT16_VALUE(-44.10), SIMDE_BFLOAT16_VALUE(37.22),
        SIMDE_BFLOAT16_VALUE(10.55), SIMDE_BFLOAT16_VALUE(-21.52), SIMDE_BFLOAT16_VALUE(-10.01), SIMDE_BFLOAT16_VALUE(-33.82) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8x4_t r;
    simde_bfloat16x8x4_t src = {
        {simde_vld1q_bf16(test_vec[i].src[0]), simde_vld1q_bf16(test_vec[i].src[1]),
         simde_vld1q_bf16(test_vec[i].src[2]), simde_vld1q_bf16(test_vec[i].src[3])}};
    simde_bfloat16x8x4_t expected = {
        {simde_vld1q_bf16(test_vec[i].r[0]), simde_vld1q_bf16(test_vec[i].r[1]),
         simde_vld1q_bf16(test_vec[i].r[2]), simde_vld1q_bf16(test_vec[i].r[3])}};

    SIMDE_CONSTIFY_8_(simde_vld4q_lane_bf16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_test_arm_neon_assert_equal_bf16x8(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[1], expected.val[1], 1);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[2], expected.val[2], 1);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[3], expected.val[3], 1);
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */


SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_lane_bf16)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
