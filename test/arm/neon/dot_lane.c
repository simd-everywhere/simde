#define SIMDE_TEST_ARM_NEON_INSN dot_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/dot_lane.h"

static int
test_simde_vdot_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    int8_t a[8];
    int8_t b[8];
    const int lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   253147047), -INT32_C(  1800313358) },
      {  INT8_C(   3),  INT8_C(  41), -INT8_C(  81), -INT8_C(  37), -INT8_C(  11), -INT8_C( 115), -INT8_C( 125), -INT8_C(   7) },
      { -INT8_C(  94),  INT8_C(  14), -INT8_C(  74), -INT8_C(  94), -INT8_C(  39), -INT8_C( 125), -INT8_C(  38),  INT8_C(  93) },
       INT32_C(           0),
      { -INT32_C(   253137283), -INT32_C(  1800313358) } },
    { {  INT32_C(   732178250),  INT32_C(   154436016) },
      { -INT8_C(  55),  INT8_C(  29), -INT8_C(   7), -INT8_C(  69), -INT8_C( 126), -INT8_C(  86),  INT8_C(  80), -INT8_C( 122) },
      { -INT8_C(  45), -INT8_C(   1),  INT8_C(  97), -INT8_C(  56), -INT8_C( 116), -INT8_C(  28), -INT8_C(  63),  INT8_C(  47) },
       INT32_C(           1),
      {  INT32_C(   732178250),  INT32_C(   154442266) } },
    { { -INT32_C(   858687501),  INT32_C(  1160358906) },
      { -INT8_C(  46), -INT8_C(  51),  INT8_C( 112), -INT8_C( 126),  INT8_C(  78), -INT8_C(  92), -INT8_C( 116),  INT8_C(  24) },
      { -INT8_C(  63), -INT8_C( 123), -INT8_C(  45),  INT8_C(  68),  INT8_C(  48),  INT8_C(  35), -INT8_C(  54),  INT8_C(   3) },
       INT32_C(           0),
      { -INT32_C(   858691938),  INT32_C(  1160358906) } },
    { { -INT32_C(  1345574110),  INT32_C(    64916752) },
      {  INT8_C(   5), -INT8_C(  81), -INT8_C(  49), -INT8_C(   1),  INT8_C(  90), -INT8_C(   8),  INT8_C(  68),  INT8_C(  44) },
      { -INT8_C(  59), -INT8_C(  76), -INT8_C(  82),  INT8_C(  19),  INT8_C(  88),  INT8_C(  58),  INT8_C(  43),  INT8_C(  26) },
       INT32_C(           1),
      { -INT32_C(  1345574110),  INT32_C(    64928276) } },
    { { -INT32_C(   262209600),  INT32_C(  1173563426) },
      {  INT8_C(  83), -INT8_C(  65), -INT8_C(  12),  INT8_C(  99),  INT8_C(  77), -INT8_C(  46),  INT8_C( 102),  INT8_C(  82) },
      { -INT8_C( 127),  INT8_C(  53),  INT8_C(  81), -INT8_C(  37),  INT8_C(  45), -INT8_C( 106),  INT8_C(   7), -INT8_C(  14) },
       INT32_C(           0),
      { -INT32_C(   262228221),  INT32_C(  1173563426) } },
    { { -INT32_C(  1559841462), -INT32_C(  1329778192) },
      {  INT8_C(  48),  INT8_C(  27), -INT8_C(  96),  INT8_C(  83),  INT8_C(  67), -INT8_C( 109), -INT8_C( 104), -INT8_C( 106) },
      {  INT8_C(  83), -INT8_C( 116), -INT8_C(   6), -INT8_C(  96),  INT8_C(  94),  INT8_C(  96), -INT8_C(  14), -INT8_C(  33) },
       INT32_C(           1),
      { -INT32_C(  1559841462), -INT32_C(  1329777404) } },
    { { -INT32_C(  1011203178),  INT32_C(   615956953) },
      {  INT8_C( 118), -INT8_C(  68), -INT8_C(  57),  INT8_C( 102), -INT8_C(  19), -INT8_C( 124),  INT8_C(  22),  INT8_C(  30) },
      { -INT8_C(  97), -INT8_C(  74),  INT8_C( 113), -INT8_C(  30),  INT8_C(  74),  INT8_C(   9),  INT8_C( 120), -INT8_C(  99) },
       INT32_C(           0),
      { -INT32_C(  1011219093),  INT32_C(   615956953) } },
    { { -INT32_C(   214076779),  INT32_C(  1775382483) },
      {  INT8_C( 114), -INT8_C( 116),  INT8_C(  44),  INT8_C(  76),  INT8_C(  77), -INT8_C(  30),  INT8_C( 112), -INT8_C(  61) },
      { -INT8_C(  98),  INT8_C(  55),  INT8_C(  42), -INT8_C( 116), -INT8_C(  69),  INT8_C(  64), -INT8_C(  86),  INT8_C(  90) },
       INT32_C(           1),
      { -INT32_C(   214076779),  INT32_C(  1775360128) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int32x2_t r = simde_vdot_lane_s32(r_, a, b, test_vec[i].lane);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int32x2_t r = simde_vdot_lane_s32(r_, a, b, lanes[i]);

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdot_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r_[2];
    uint8_t a[8];
    uint8_t b[8];
    const int lane;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2273751440), UINT32_C(3884166093) },
      { UINT8_C(198), UINT8_C(167), UINT8_C( 73), UINT8_C(199), UINT8_C(230), UINT8_C(240), UINT8_C(  5), UINT8_C( 49) },
      { UINT8_C(237), UINT8_C(126), UINT8_C( 64), UINT8_C( 41), UINT8_C(234), UINT8_C( 92), UINT8_C(119), UINT8_C(208) },
       INT32_C(           0),
      { UINT32_C(2273832239), UINT32_C(3884166093) } },
    { { UINT32_C(3927977934), UINT32_C(1271200699) },
      { UINT8_C(172), UINT8_C( 74), UINT8_C(210), UINT8_C(122), UINT8_C(245), UINT8_C( 86), UINT8_C( 97), UINT8_C(187) },
      { UINT8_C(253), UINT8_C(170), UINT8_C(130), UINT8_C(227), UINT8_C(155), UINT8_C(135), UINT8_C( 20), UINT8_C(136) },
       INT32_C(           1),
      { UINT32_C(3927977934), UINT32_C(1271277656) } },
    { { UINT32_C(4038153478), UINT32_C(2143300017) },
      { UINT8_C( 88), UINT8_C(224), UINT8_C(105), UINT8_C( 19), UINT8_C(219), UINT8_C( 45), UINT8_C( 94), UINT8_C(136) },
      { UINT8_C(119), UINT8_C( 48), UINT8_C(  2), UINT8_C(109), UINT8_C(134), UINT8_C( 99), UINT8_C( 40), UINT8_C(131) },
       INT32_C(           0),
      { UINT32_C(4038176983), UINT32_C(2143300017) } },
    { { UINT32_C(2842143502), UINT32_C( 942766898) },
      { UINT8_C(208), UINT8_C(227), UINT8_C( 40), UINT8_C(130), UINT8_C( 12), UINT8_C(233), UINT8_C(  1), UINT8_C(100) },
      { UINT8_C(201), UINT8_C(107), UINT8_C(119), UINT8_C(165), UINT8_C(152), UINT8_C(213), UINT8_C( 45), UINT8_C( 16) },
       INT32_C(           1),
      { UINT32_C(2842143502), UINT32_C( 942819996) } },
    { { UINT32_C(2357014277), UINT32_C(2685379986) },
      { UINT8_C( 80), UINT8_C(118), UINT8_C( 73), UINT8_C(131), UINT8_C(242), UINT8_C(123), UINT8_C(187), UINT8_C(194) },
      { UINT8_C( 94), UINT8_C(228), UINT8_C( 68), UINT8_C(106), UINT8_C(205), UINT8_C( 70), UINT8_C(206), UINT8_C(150) },
       INT32_C(           0),
      { UINT32_C(2357067551), UINT32_C(2685379986) } },
    { { UINT32_C(1228621233), UINT32_C( 525953050) },
      { UINT8_C(151), UINT8_C(214), UINT8_C(171), UINT8_C( 42), UINT8_C(124), UINT8_C(187), UINT8_C(202), UINT8_C(204) },
      { UINT8_C( 49), UINT8_C( 20), UINT8_C( 79), UINT8_C( 35), UINT8_C(143), UINT8_C( 11), UINT8_C(230), UINT8_C(237) },
       INT32_C(           1),
      { UINT32_C(1228621233), UINT32_C( 526067647) } },
    { { UINT32_C(3159829231), UINT32_C( 559031664) },
      { UINT8_C(106), UINT8_C(142), UINT8_C(107), UINT8_C(132), UINT8_C(246), UINT8_C(196), UINT8_C(163), UINT8_C(142) },
      { UINT8_C(155), UINT8_C( 79), UINT8_C(184), UINT8_C( 23), UINT8_C( 10), UINT8_C(130), UINT8_C(227), UINT8_C( 59) },
       INT32_C(           0),
      { UINT32_C(3159879603), UINT32_C( 559031664) } },
    { { UINT32_C( 626996118), UINT32_C( 756172094) },
      { UINT8_C(111), UINT8_C(105), UINT8_C(233), UINT8_C(224), UINT8_C(142), UINT8_C( 59), UINT8_C(  1), UINT8_C(248) },
      { UINT8_C(201), UINT8_C(108), UINT8_C(124), UINT8_C(192), UINT8_C( 49), UINT8_C( 32), UINT8_C( 78), UINT8_C(204) },
       INT32_C(           1),
      { UINT32_C( 626996118), UINT32_C( 756231610) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r_ = simde_vld1_u32(test_vec[i].r_);
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint32x2_t r = simde_vdot_lane_u32(r_, a, b, test_vec[i].lane);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r_ = simde_test_arm_neon_random_u32x2();
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint32x2_t r = simde_vdot_lane_u32(r_, a, b, lanes[i]);

    simde_test_arm_neon_write_u32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdot_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[4];
    int8_t a[16];
    int8_t b[16];
    const int lane;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1560176901), -INT32_C(   161233256), -INT32_C(   535959529), -INT32_C(  1508750539) },
      { -INT8_C( 123),  INT8_C(  76),  INT8_C(   7),  INT8_C(  87),  INT8_C(  63), -INT8_C( 119), -INT8_C(  16), -INT8_C(  85),
        -INT8_C( 127), -INT8_C( 126), -INT8_C(  28),  INT8_C(  81), -INT8_C( 117),  INT8_C(  86),  INT8_C( 102), -INT8_C( 112) },
      { -INT8_C(  64),  INT8_C( 100), -INT8_C(  19),  INT8_C(  88),  INT8_C(  42),  INT8_C(  80),  INT8_C(  79),  INT8_C(  65),
         INT8_C(  56),  INT8_C(  92),  INT8_C(  33),  INT8_C( 109), -INT8_C(  89),  INT8_C(  51),  INT8_C(  20),  INT8_C(  44) },
       INT32_C(           0),
      {  INT32_C(  1560199896), -INT32_C(   161233256), -INT32_C(   535959529), -INT32_C(  1508750539) } },
    { { -INT32_C(  1098638465),  INT32_C(   644445349), -INT32_C(  2106110218),  INT32_C(  1678957988) },
      {  INT8_C(  65), -INT8_C(   1), -INT8_C(  67),  INT8_C( 107),  INT8_C(  79),  INT8_C(  12), -INT8_C(  83), -INT8_C( 121),
         INT8_C( 104), -INT8_C(  50), -INT8_C(  11),  INT8_C(  15),  INT8_C(   2),  INT8_C(   9),  INT8_C(  60), -INT8_C( 127) },
      {  INT8_C(  36), -INT8_C(  64),  INT8_C(  64), -INT8_C(  55),  INT8_C(  52), -INT8_C(  87), -INT8_C(  17),  INT8_C(  43),
        -INT8_C(   9),  INT8_C( 103), -INT8_C(  83), -INT8_C( 100),  INT8_C(  68), -INT8_C(  65),  INT8_C(   0), -INT8_C( 122) },
       INT32_C(           1),
      { -INT32_C(  1098638465),  INT32_C(   644444621), -INT32_C(  2106110218),  INT32_C(  1678957988) } },
    { {  INT32_C(   250723775),  INT32_C(   831954633),  INT32_C(  1866566509), -INT32_C(  1192198764) },
      {  INT8_C(  61),  INT8_C(  48), -INT8_C( 126),  INT8_C( 113), -INT8_C(  38),  INT8_C( 113), -INT8_C( 100), -INT8_C(  47),
        -INT8_C(  40),  INT8_C(  73),  INT8_C( 109),  INT8_C(  29),  INT8_C(   9),  INT8_C( 110), -INT8_C(  93), -INT8_C(  56) },
      {  INT8_C(  43), -INT8_C( 108), -INT8_C(  42), -INT8_C(  11),  INT8_C(  51),  INT8_C( 108),  INT8_C(  38), -INT8_C(  96),
        -INT8_C(   9),  INT8_C( 103),  INT8_C(  15), -INT8_C( 117), -INT8_C(  28), -INT8_C(   1),  INT8_C(  68),  INT8_C(  33) },
       INT32_C(           2),
      {  INT32_C(   250723775),  INT32_C(   831954633),  INT32_C(  1866572630), -INT32_C(  1192198764) } },
    { {  INT32_C(   177456688),  INT32_C(   282799927), -INT32_C(  2110961287), -INT32_C(   498413385) },
      {  INT8_C( 100),  INT8_C(  32), -INT8_C(  41), -INT8_C( 105), -INT8_C( 115), -INT8_C(   2),  INT8_C(  55), -INT8_C( 124),
         INT8_C( 101),  INT8_C(  70),  INT8_C(  16),  INT8_C(  74),  INT8_C(  70),  INT8_C(  84),  INT8_C( 107),  INT8_C( 118) },
      {  INT8_C(  26), -INT8_C(   2),      INT8_MIN,  INT8_C(  81),  INT8_C(  46),  INT8_C(  91),  INT8_C(  97), -INT8_C(  89),
        -INT8_C(  92), -INT8_C( 114),  INT8_C(  41),  INT8_C(  91),  INT8_C(  94),  INT8_C( 115),  INT8_C(  62), -INT8_C(  61) },
       INT32_C(           3),
      {  INT32_C(   177456688),  INT32_C(   282799927), -INT32_C(  2110961287), -INT32_C(   498397709) } },
    { {  INT32_C(   542774675),  INT32_C(  2040893971),  INT32_C(   516142552),  INT32_C(   596913673) },
      {  INT8_C(  45),  INT8_C(  20),  INT8_C( 116),  INT8_C(  91),  INT8_C( 112), -INT8_C(  42),  INT8_C(   2),  INT8_C(  20),
         INT8_C( 100),  INT8_C(  43),  INT8_C( 112), -INT8_C(  61), -INT8_C(  98), -INT8_C(  82), -INT8_C( 122),  INT8_C(  49) },
      { -INT8_C(  61), -INT8_C(  32),  INT8_C(  82), -INT8_C(  41),  INT8_C( 114), -INT8_C(   9),  INT8_C(  80),  INT8_C(  75),
        -INT8_C(  84),  INT8_C(  19),  INT8_C( 105), -INT8_C(  75),  INT8_C(  65), -INT8_C(   2), -INT8_C(  40),  INT8_C( 110) },
       INT32_C(           0),
      {  INT32_C(   542777071),  INT32_C(  2040893971),  INT32_C(   516142552),  INT32_C(   596913673) } },
    { { -INT32_C(  2100737006), -INT32_C(  2020095198), -INT32_C(  1807087626),  INT32_C(  2026295477) },
      { -INT8_C(  80),  INT8_C(  24),  INT8_C(  79),  INT8_C(  35),  INT8_C(  15), -INT8_C(  97),  INT8_C( 110), -INT8_C(  69),
        -INT8_C(  78), -INT8_C(  41),  INT8_C( 112), -INT8_C(  12), -INT8_C(  43),  INT8_C(  72),  INT8_C(  98), -INT8_C(  24) },
      { -INT8_C( 108),  INT8_C(  44),  INT8_C( 106), -INT8_C(  73), -INT8_C(   9),  INT8_C(   1),  INT8_C(  62), -INT8_C(  18),
         INT8_C(   8), -INT8_C( 120), -INT8_C( 126), -INT8_C(  67),  INT8_C(  88),  INT8_C(  72),  INT8_C(  54),  INT8_C(   8) },
       INT32_C(           1),
      { -INT32_C(  2100737006), -INT32_C(  2020087368), -INT32_C(  1807087626),  INT32_C(  2026295477) } },
    { {  INT32_C(  1865123168), -INT32_C(   685074139),  INT32_C(  1187748465),  INT32_C(  1999515362) },
      {  INT8_C(  90), -INT8_C( 103),  INT8_C(  46),  INT8_C(  81), -INT8_C( 102),  INT8_C( 108),  INT8_C(  63), -INT8_C(  93),
        -INT8_C(  12), -INT8_C(  62),  INT8_C(  96),  INT8_C(  76),  INT8_C(  10), -INT8_C( 106),  INT8_C(  84),  INT8_C( 107) },
      {  INT8_C(  28),      INT8_MIN, -INT8_C(  38),  INT8_C(  65),  INT8_C(  25),  INT8_C(   5),  INT8_C(  24), -INT8_C( 118),
        -INT8_C(  97), -INT8_C(  28), -INT8_C(  47), -INT8_C( 126),  INT8_C(  18), -INT8_C(   1), -INT8_C(   7),  INT8_C( 108) },
       INT32_C(           2),
      {  INT32_C(  1865123168), -INT32_C(   685074139),  INT32_C(  1187737277),  INT32_C(  1999515362) } },
    { {  INT32_C(   868034456), -INT32_C(  2015953517), -INT32_C(   908904769), -INT32_C(   382457907) },
      { -INT8_C(  89),  INT8_C(  15),  INT8_C(  42), -INT8_C(  63),  INT8_C(  20),  INT8_C(  66),  INT8_C(  75), -INT8_C(  77),
         INT8_C(  38),  INT8_C(  28),  INT8_C(  53),  INT8_C(  56),  INT8_C(  28),  INT8_C(  46), -INT8_C(  92), -INT8_C(  76) },
      {  INT8_C(  85),  INT8_C(  98), -INT8_C(  25), -INT8_C(  24),  INT8_C(  95), -INT8_C(  67),  INT8_C( 111),  INT8_C(  30),
        -INT8_C(  12),  INT8_C(  66), -INT8_C(  25), -INT8_C(  63),  INT8_C( 106),  INT8_C(  28), -INT8_C(  86),  INT8_C(  17) },
       INT32_C(           3),
      {  INT32_C(   868034456), -INT32_C(  2015953517), -INT32_C(   908904769), -INT32_C(   382447031) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t r_ = simde_vld1q_s32(test_vec[i].r_);
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int32x4_t r = simde_vdot_laneq_s32(r_, a, b, test_vec[i].lane);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t r_ = simde_test_arm_neon_random_i32x4();
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int32x4_t r = simde_vdot_laneq_s32(r_, a, b, lanes[i]);

    simde_test_arm_neon_write_i32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdot_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r_[4];
    uint8_t a[16];
    uint8_t b[16];
    const int lane;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1243008842), UINT32_C(2042260212), UINT32_C(4021263272), UINT32_C( 707897681) },
      { UINT8_C(214), UINT8_C(  0), UINT8_C(102), UINT8_C(248), UINT8_C(105), UINT8_C(136), UINT8_C(248), UINT8_C(231),
        UINT8_C( 35), UINT8_C(235), UINT8_C( 87), UINT8_C( 56), UINT8_C(130), UINT8_C(122), UINT8_C(173), UINT8_C(204) },
      { UINT8_C( 73), UINT8_C(196), UINT8_C( 22), UINT8_C( 61), UINT8_C( 46), UINT8_C(209), UINT8_C(183), UINT8_C(215),
        UINT8_C(108), UINT8_C(102), UINT8_C(198), UINT8_C(189), UINT8_C( 16), UINT8_C(247), UINT8_C(231), UINT8_C(230) },
       INT32_C(           0),
      { UINT32_C(1243041836), UINT32_C(2042260212), UINT32_C(4021263272), UINT32_C( 707897681) } },
    { { UINT32_C(1625247223), UINT32_C(4165457877), UINT32_C(1144037058), UINT32_C(1628495384) },
      { UINT8_C(162), UINT8_C( 39), UINT8_C(159), UINT8_C(208), UINT8_C(248), UINT8_C( 86), UINT8_C(167), UINT8_C(100),
        UINT8_C(188), UINT8_C(109), UINT8_C( 33), UINT8_C(204), UINT8_C(100), UINT8_C(  9), UINT8_C(179), UINT8_C( 91) },
      { UINT8_C( 86), UINT8_C(146), UINT8_C(188), UINT8_C( 44), UINT8_C(105), UINT8_C(  3), UINT8_C( 36), UINT8_C( 43),
        UINT8_C(162), UINT8_C( 85), UINT8_C(111), UINT8_C(186), UINT8_C( 51), UINT8_C(127), UINT8_C( 28), UINT8_C(213) },
       INT32_C(           1),
      { UINT32_C(1625247223), UINT32_C(4165494487), UINT32_C(1144037058), UINT32_C(1628495384) } },
    { { UINT32_C(2661661606), UINT32_C(3439480081), UINT32_C( 530195642), UINT32_C(2205830445) },
      { UINT8_C(223), UINT8_C( 54), UINT8_C(175), UINT8_C( 72), UINT8_C( 58), UINT8_C(212), UINT8_C(115), UINT8_C(220),
        UINT8_C( 41), UINT8_C(226), UINT8_C(150), UINT8_C( 92), UINT8_C( 97), UINT8_C(178), UINT8_C( 49), UINT8_C(  8) },
      { UINT8_C(109), UINT8_C(214), UINT8_C(166), UINT8_C(126), UINT8_C( 35), UINT8_C(169), UINT8_C( 76), UINT8_C(222),
        UINT8_C(205), UINT8_C(230), UINT8_C(253), UINT8_C(250), UINT8_C( 51), UINT8_C(119), UINT8_C(125), UINT8_C( 18) },
       INT32_C(           2),
      { UINT32_C(2661661606), UINT32_C(3439480081), UINT32_C( 530316977), UINT32_C(2205830445) } },
    { { UINT32_C(3898224046), UINT32_C( 717540609), UINT32_C( 277240495), UINT32_C(2048440077) },
      { UINT8_C(141), UINT8_C(191), UINT8_C(249), UINT8_C(177), UINT8_C(104), UINT8_C( 69), UINT8_C(143), UINT8_C( 53),
        UINT8_C( 43), UINT8_C(140), UINT8_C( 47), UINT8_C( 94), UINT8_C(  3), UINT8_C(172), UINT8_C(112), UINT8_C(177) },
      { UINT8_C(217), UINT8_C(202), UINT8_C(153), UINT8_C(218), UINT8_C(151), UINT8_C( 93), UINT8_C(  4), UINT8_C( 70),
        UINT8_C(184), UINT8_C(138), UINT8_C( 86), UINT8_C(197), UINT8_C( 65), UINT8_C(111), UINT8_C( 63), UINT8_C(207) },
       INT32_C(           3),
      { UINT32_C(3898224046), UINT32_C( 717540609), UINT32_C( 277240495), UINT32_C(2048503059) } },
    { { UINT32_C(2524985390), UINT32_C(2831880061), UINT32_C(2651257499), UINT32_C(2152756902) },
      { UINT8_C( 64), UINT8_C(233), UINT8_C( 90), UINT8_C(215), UINT8_C( 71), UINT8_C( 95), UINT8_C( 29),    UINT8_MAX,
        UINT8_C(233), UINT8_C(116), UINT8_C(196), UINT8_C( 43), UINT8_C(227), UINT8_C(  3), UINT8_C(250), UINT8_C( 17) },
      { UINT8_C( 60), UINT8_C(122), UINT8_C(167), UINT8_C(185), UINT8_C(137), UINT8_C(114), UINT8_C( 98), UINT8_C( 36),
        UINT8_C(108), UINT8_C(104), UINT8_C(194), UINT8_C( 18), UINT8_C(223), UINT8_C( 18), UINT8_C(146), UINT8_C( 31) },
       INT32_C(           0),
      { UINT32_C(2525072461), UINT32_C(2831880061), UINT32_C(2651257499), UINT32_C(2152756902) } },
    { { UINT32_C(1140321788), UINT32_C( 893523020), UINT32_C(1801455240), UINT32_C(1165777417) },
      { UINT8_C(212), UINT8_C( 35),    UINT8_MAX, UINT8_C( 93), UINT8_C(149), UINT8_C( 97), UINT8_C(129), UINT8_C(  1),
        UINT8_C(201), UINT8_C( 68), UINT8_C( 20), UINT8_C(168), UINT8_C( 86), UINT8_C(166), UINT8_C(200), UINT8_C( 82) },
      { UINT8_C(147), UINT8_C(191), UINT8_C(149), UINT8_C(223), UINT8_C(211), UINT8_C(215), UINT8_C( 21), UINT8_C( 92),
        UINT8_C(221), UINT8_C(117), UINT8_C(199), UINT8_C(231), UINT8_C(208), UINT8_C( 68), UINT8_C( 44), UINT8_C(164) },
       INT32_C(           1),
      { UINT32_C(1140321788), UINT32_C( 893578115), UINT32_C(1801455240), UINT32_C(1165777417) } },
    { { UINT32_C(4244777831), UINT32_C(1459520396), UINT32_C( 519967431), UINT32_C(1282459321) },
      { UINT8_C(133), UINT8_C(  6), UINT8_C( 44), UINT8_C( 89), UINT8_C(221), UINT8_C( 65), UINT8_C(181), UINT8_C(187),
        UINT8_C(182), UINT8_C(124), UINT8_C(162), UINT8_C(134), UINT8_C(192), UINT8_C(206), UINT8_C( 43), UINT8_C( 40) },
      { UINT8_C(250), UINT8_C( 45), UINT8_C( 37), UINT8_C(134), UINT8_C(176), UINT8_C( 35), UINT8_C(220), UINT8_C(120),
        UINT8_C( 54), UINT8_C(219), UINT8_C(150), UINT8_C(239), UINT8_C(161), UINT8_C(  6), UINT8_C( 59), UINT8_C( 39) },
       INT32_C(           2),
      { UINT32_C(4244777831), UINT32_C(1459520396), UINT32_C( 520060741), UINT32_C(1282459321) } },
    { { UINT32_C(3934283532), UINT32_C(1604662696), UINT32_C(1927628721), UINT32_C( 261754901) },
      { UINT8_C( 61), UINT8_C(191), UINT8_C(150), UINT8_C(238), UINT8_C(226), UINT8_C(114), UINT8_C(102), UINT8_C( 24),
        UINT8_C( 77), UINT8_C(252), UINT8_C(  7), UINT8_C(239), UINT8_C(  2), UINT8_C( 67), UINT8_C( 22), UINT8_C( 15) },
      { UINT8_C(170), UINT8_C(150), UINT8_C(249), UINT8_C( 83), UINT8_C(203), UINT8_C(158), UINT8_C(178), UINT8_C(124),
        UINT8_C(229), UINT8_C(151), UINT8_C(238), UINT8_C(250), UINT8_C(168), UINT8_C(136), UINT8_C( 10), UINT8_C(229) },
       INT32_C(           3),
      { UINT32_C(3934283532), UINT32_C(1604662696), UINT32_C(1927628721), UINT32_C( 261768004) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t r_ = simde_vld1q_u32(test_vec[i].r_);
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint32x4_t r = simde_vdot_laneq_u32(r_, a, b, test_vec[i].lane);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t r_ = simde_test_arm_neon_random_u32x4();
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint32x4_t r = simde_vdot_laneq_u32(r_, a, b, lanes[i]);

    simde_test_arm_neon_write_u32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vdot_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdot_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vdot_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdot_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
