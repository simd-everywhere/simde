#define SIMDE_TEST_ARM_NEON_INSN ld4_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/ld4_lane.h"
#include "../../../simde/arm/neon/ld1.h"

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

    SIMDE_CONSTIFY_8_(simde_vld4_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_int8x8x4_t expected = {
        {simde_vld1_s8(test_vec[i].r[0]), simde_vld1_s8(test_vec[i].r[1]),
         simde_vld1_s8(test_vec[i].r[2]), simde_vld1_s8(test_vec[i].r[3])}};

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

    SIMDE_CONSTIFY_4_(simde_vld4_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_int16x4x4_t expected = {
        {simde_vld1_s16(test_vec[i].r[0]), simde_vld1_s16(test_vec[i].r[1]),
         simde_vld1_s16(test_vec[i].r[2]), simde_vld1_s16(test_vec[i].r[3])}};

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

    SIMDE_CONSTIFY_2_(simde_vld4_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_int32x2x4_t expected = {
        {simde_vld1_s32(test_vec[i].r[0]), simde_vld1_s32(test_vec[i].r[1]),
         simde_vld1_s32(test_vec[i].r[2]), simde_vld1_s32(test_vec[i].r[3])}};

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

    SIMDE_CONSTIFY_8_(simde_vld4_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_uint8x8x4_t expected = {
        {simde_vld1_u8(test_vec[i].r[0]), simde_vld1_u8(test_vec[i].r[1]),
         simde_vld1_u8(test_vec[i].r[2]), simde_vld1_u8(test_vec[i].r[3])}};

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

    SIMDE_CONSTIFY_4_(simde_vld4_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_uint16x4x4_t expected = {
        {simde_vld1_u16(test_vec[i].r[0]), simde_vld1_u16(test_vec[i].r[1]),
         simde_vld1_u16(test_vec[i].r[2]), simde_vld1_u16(test_vec[i].r[3])}};

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

    SIMDE_CONSTIFY_2_(simde_vld4_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    simde_uint32x2x4_t expected = {
        {simde_vld1_u32(test_vec[i].r[0]), simde_vld1_u32(test_vec[i].r[1]),
         simde_vld1_u32(test_vec[i].r[2]), simde_vld1_u32(test_vec[i].r[3])}};

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


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_lane_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
