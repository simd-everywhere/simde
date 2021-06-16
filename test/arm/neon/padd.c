#define SIMDE_TEST_ARM_NEON_INSN padd

#include "test-neon.h"
#include "../../../simde/arm/neon/padd.h"

static int
test_simde_vpadd_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   364.07), SIMDE_FLOAT32_C(  -805.98) },
      { SIMDE_FLOAT32_C(   541.55), SIMDE_FLOAT32_C(  -507.67) },
      { SIMDE_FLOAT32_C(  -441.91), SIMDE_FLOAT32_C(    33.88) } },
    { { SIMDE_FLOAT32_C(  -210.05), SIMDE_FLOAT32_C(   950.23) },
      { SIMDE_FLOAT32_C(   -73.21), SIMDE_FLOAT32_C(  -858.69) },
      { SIMDE_FLOAT32_C(   740.18), SIMDE_FLOAT32_C(  -931.90) } },
    { { SIMDE_FLOAT32_C(   289.47), SIMDE_FLOAT32_C(   222.50) },
      { SIMDE_FLOAT32_C(  -617.39), SIMDE_FLOAT32_C(    38.06) },
      { SIMDE_FLOAT32_C(   511.98), SIMDE_FLOAT32_C(  -579.33) } },
    { { SIMDE_FLOAT32_C(  -385.12), SIMDE_FLOAT32_C(  -947.12) },
      { SIMDE_FLOAT32_C(  -383.15), SIMDE_FLOAT32_C(  -390.83) },
      { SIMDE_FLOAT32_C( -1332.24), SIMDE_FLOAT32_C(  -773.98) } },
    { { SIMDE_FLOAT32_C(   787.35), SIMDE_FLOAT32_C(   150.74) },
      { SIMDE_FLOAT32_C(   -44.15), SIMDE_FLOAT32_C(   -31.92) },
      { SIMDE_FLOAT32_C(   938.08), SIMDE_FLOAT32_C(   -76.07) } },
    { { SIMDE_FLOAT32_C(   608.96), SIMDE_FLOAT32_C(  -994.50) },
      { SIMDE_FLOAT32_C(  -198.21), SIMDE_FLOAT32_C(  -284.71) },
      { SIMDE_FLOAT32_C(  -385.53), SIMDE_FLOAT32_C(  -482.92) } },
    { { SIMDE_FLOAT32_C(   116.75), SIMDE_FLOAT32_C(   296.49) },
      { SIMDE_FLOAT32_C(  -579.72), SIMDE_FLOAT32_C(  -346.53) },
      { SIMDE_FLOAT32_C(   413.24), SIMDE_FLOAT32_C(  -926.24) } },
    { { SIMDE_FLOAT32_C(  -405.05), SIMDE_FLOAT32_C(   579.35) },
      { SIMDE_FLOAT32_C(   172.94), SIMDE_FLOAT32_C(   959.02) },
      { SIMDE_FLOAT32_C(   174.30), SIMDE_FLOAT32_C(  1131.96) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vpadd_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpadd_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  42), -INT8_C(  32), -INT8_C(  64),  INT8_C( 117),  INT8_C(  61),  INT8_C(  45), -INT8_C(  26),  INT8_C(  96) },
      { -INT8_C(  49),  INT8_C(  76), -INT8_C(  77), -INT8_C(  78),  INT8_C(  47), -INT8_C( 116),  INT8_C(  78), -INT8_C( 108) },
      { -INT8_C(  74),  INT8_C(  53),  INT8_C( 106),  INT8_C(  70),  INT8_C(  27),  INT8_C( 101), -INT8_C(  69), -INT8_C(  30) } },
    { {  INT8_C(   3), -INT8_C(  93), -INT8_C(  22),  INT8_C(  89),  INT8_C(  69),  INT8_C( 121), -INT8_C(  64),  INT8_C( 110) },
      { -INT8_C(  10), -INT8_C(  63), -INT8_C( 118),  INT8_C(  71),  INT8_C(  28), -INT8_C(  42), -INT8_C(  14), -INT8_C(  14) },
      { -INT8_C(  90),  INT8_C(  67), -INT8_C(  66),  INT8_C(  46), -INT8_C(  73), -INT8_C(  47), -INT8_C(  14), -INT8_C(  28) } },
    { { -INT8_C(  74), -INT8_C(  78),  INT8_C( 103), -INT8_C(  13), -INT8_C(  33),  INT8_C(  77),  INT8_C(  83), -INT8_C(  82) },
      { -INT8_C( 103),  INT8_C(   6),  INT8_C(  96), -INT8_C(  56), -INT8_C( 110), -INT8_C(  82),  INT8_C(  92), -INT8_C( 106) },
      {  INT8_C( 104),  INT8_C(  90),  INT8_C(  44),  INT8_C(   1), -INT8_C(  97),  INT8_C(  40),  INT8_C(  64), -INT8_C(  14) } },
    { {  INT8_C(  82),  INT8_C(  71), -INT8_C(  17), -INT8_C( 105), -INT8_C(  64), -INT8_C(  80),  INT8_C(   5), -INT8_C(  74) },
      {  INT8_C( 113), -INT8_C( 112), -INT8_C(   2), -INT8_C( 115),  INT8_C( 102), -INT8_C(  16),      INT8_MAX,  INT8_C(  28) },
      { -INT8_C( 103), -INT8_C( 122),  INT8_C( 112), -INT8_C(  69),  INT8_C(   1), -INT8_C( 117),  INT8_C(  86), -INT8_C( 101) } },
    { { -INT8_C(  94), -INT8_C(  26),  INT8_C(  15), -INT8_C( 127),  INT8_C(  51),  INT8_C(  98),  INT8_C(  47), -INT8_C(  52) },
      {  INT8_C( 104), -INT8_C( 112), -INT8_C( 108), -INT8_C(   6),  INT8_C(  62), -INT8_C(  15), -INT8_C( 112), -INT8_C( 112) },
      { -INT8_C( 120), -INT8_C( 112), -INT8_C( 107), -INT8_C(   5), -INT8_C(   8), -INT8_C( 114),  INT8_C(  47),  INT8_C(  32) } },
    { {  INT8_C(  56),      INT8_MIN,  INT8_C(  39), -INT8_C(   8),  INT8_C(  48),  INT8_C(  45), -INT8_C(  81), -INT8_C(  95) },
      { -INT8_C(  67), -INT8_C(  83),  INT8_C(  47),  INT8_C(  35), -INT8_C(  99), -INT8_C(  82),  INT8_C(  63),  INT8_C(  63) },
      { -INT8_C(  72),  INT8_C(  31),  INT8_C(  93),  INT8_C(  80),  INT8_C( 106),  INT8_C(  82),  INT8_C(  75),  INT8_C( 126) } },
    { { -INT8_C( 107),  INT8_C(  78), -INT8_C(  64), -INT8_C(  56), -INT8_C(  80), -INT8_C(  17), -INT8_C( 107),  INT8_C(  24) },
      {      INT8_MAX,  INT8_C(  41),  INT8_C(  18), -INT8_C(  66),  INT8_C(  26), -INT8_C(  93),  INT8_C(  78),  INT8_C(  82) },
      { -INT8_C(  29), -INT8_C( 120), -INT8_C(  97), -INT8_C(  83), -INT8_C(  88), -INT8_C(  48), -INT8_C(  67), -INT8_C(  96) } },
    { {  INT8_C(  35),  INT8_C( 118),  INT8_C(  75),  INT8_C(  83), -INT8_C(  93), -INT8_C(   6), -INT8_C(  12),  INT8_C(  96) },
      { -INT8_C(  89),  INT8_C(  35), -INT8_C( 125),  INT8_C(  68), -INT8_C(  46), -INT8_C(  62), -INT8_C( 125),  INT8_C( 103) },
      { -INT8_C( 103), -INT8_C(  98), -INT8_C(  99),  INT8_C(  84), -INT8_C(  54), -INT8_C(  57), -INT8_C( 108), -INT8_C(  22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vpadd_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpadd_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 12301), -INT16_C( 30280),  INT16_C(  1981), -INT16_C(  8183) },
      {  INT16_C(  2606),  INT16_C(   142), -INT16_C(  1330), -INT16_C(  1866) },
      { -INT16_C( 17979), -INT16_C(  6202),  INT16_C(  2748), -INT16_C(  3196) } },
    { {  INT16_C( 18011), -INT16_C(  2555), -INT16_C( 26024),  INT16_C(  8774) },
      {  INT16_C(  7111),  INT16_C( 25679),  INT16_C( 19345), -INT16_C( 25081) },
      {  INT16_C( 15456), -INT16_C( 17250), -INT16_C( 32746), -INT16_C(  5736) } },
    { { -INT16_C( 16516),  INT16_C( 14631),  INT16_C( 12486), -INT16_C(  3047) },
      { -INT16_C( 22470),  INT16_C(  2548), -INT16_C( 21598), -INT16_C(   511) },
      { -INT16_C(  1885),  INT16_C(  9439), -INT16_C( 19922), -INT16_C( 22109) } },
    { {  INT16_C(  2033),  INT16_C( 18932),  INT16_C( 15009),  INT16_C( 26987) },
      { -INT16_C( 17834), -INT16_C(  6195), -INT16_C( 11259), -INT16_C( 32379) },
      {  INT16_C( 20965), -INT16_C( 23540), -INT16_C( 24029),  INT16_C( 21898) } },
    { { -INT16_C( 21101),  INT16_C( 23226), -INT16_C( 11043),  INT16_C(  6222) },
      {  INT16_C( 17276),  INT16_C(  7713),  INT16_C(  8942), -INT16_C(  8420) },
      {  INT16_C(  2125), -INT16_C(  4821),  INT16_C( 24989),  INT16_C(   522) } },
    { {  INT16_C(  4137), -INT16_C( 13528), -INT16_C( 27829), -INT16_C( 24268) },
      {  INT16_C(   333),  INT16_C( 21128),  INT16_C(  3541),  INT16_C( 26836) },
      { -INT16_C(  9391),  INT16_C( 13439),  INT16_C( 21461),  INT16_C( 30377) } },
    { { -INT16_C( 28998), -INT16_C( 26430),  INT16_C(  4450), -INT16_C(  8528) },
      { -INT16_C( 11948),  INT16_C( 17149),  INT16_C(  6643),  INT16_C(  7457) },
      {  INT16_C( 10108), -INT16_C(  4078),  INT16_C(  5201),  INT16_C( 14100) } },
    { {  INT16_C( 18730),  INT16_C( 30184),  INT16_C(  7388),  INT16_C( 10518) },
      { -INT16_C( 25059), -INT16_C(  3461),  INT16_C( 20395),  INT16_C( 26202) },
      { -INT16_C( 16622),  INT16_C( 17906), -INT16_C( 28520), -INT16_C( 18939) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vpadd_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpadd_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1699479832), -INT32_C(   412031930) },
      { -INT32_C(     2482844), -INT32_C(    51361615) },
      {  INT32_C(  1287447902), -INT32_C(    53844459) } },
    { { -INT32_C(   538447692),  INT32_C(  1324757574) },
      { -INT32_C(   268960219),  INT32_C(  1571947844) },
      {  INT32_C(   786309882),  INT32_C(  1302987625) } },
    { {  INT32_C(  1287847686),  INT32_C(  1211380451) },
      {  INT32_C(    21433936),  INT32_C(   201144407) },
      { -INT32_C(  1795739159),  INT32_C(   222578343) } },
    { {  INT32_C(  1860887592),  INT32_C(  1002234134) },
      {  INT32_C(   590001119), -INT32_C(  1082073671) },
      { -INT32_C(  1431845570), -INT32_C(   492072552) } },
    { { -INT32_C(  1089715236), -INT32_C(   989380491) },
      { -INT32_C(  1513730226), -INT32_C(  1347370105) },
      { -INT32_C(  2079095727),  INT32_C(  1433866965) } },
    { { -INT32_C(  1105355864),  INT32_C(  1543166332) },
      {  INT32_C(  1182672013), -INT32_C(   586809599) },
      {  INT32_C(   437810468),  INT32_C(   595862414) } },
    { { -INT32_C(  1214443198), -INT32_C(  1602378671) },
      {  INT32_C(  2051359731), -INT32_C(  1356204537) },
      {  INT32_C(  1478145427),  INT32_C(   695155194) } },
    { {  INT32_C(   225265297), -INT32_C(  1385666784) },
      { -INT32_C(  1913395572),  INT32_C(   661387493) },
      { -INT32_C(  1160401487), -INT32_C(  1252008079) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vpadd_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpadd_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(243), UINT8_C( 66), UINT8_C( 33), UINT8_C( 59), UINT8_C(231), UINT8_C(109), UINT8_C(213), UINT8_C(120) },
      { UINT8_C(224), UINT8_C(152), UINT8_C( 89), UINT8_C(119), UINT8_C(114), UINT8_C( 12), UINT8_C(242), UINT8_C(158) },
      { UINT8_C( 53), UINT8_C( 92), UINT8_C( 84), UINT8_C( 77), UINT8_C(120), UINT8_C(208), UINT8_C(126), UINT8_C(144) } },
    { { UINT8_C( 36), UINT8_C( 52), UINT8_C(243), UINT8_C(110), UINT8_C(177), UINT8_C(236), UINT8_C(243), UINT8_C(140) },
      { UINT8_C(169), UINT8_C(251), UINT8_C(254), UINT8_C(243), UINT8_C(133), UINT8_C( 91), UINT8_C( 89), UINT8_C(120) },
      { UINT8_C( 88), UINT8_C( 97), UINT8_C(157), UINT8_C(127), UINT8_C(164), UINT8_C(241), UINT8_C(224), UINT8_C(209) } },
    { { UINT8_C(157), UINT8_C(122), UINT8_C(179), UINT8_C(133), UINT8_C(232), UINT8_C(136), UINT8_C(253), UINT8_C(200) },
      { UINT8_C( 32), UINT8_C( 87), UINT8_C( 63), UINT8_C(146), UINT8_C( 99), UINT8_C( 50), UINT8_C( 48), UINT8_C(135) },
      { UINT8_C( 23), UINT8_C( 56), UINT8_C(112), UINT8_C(197), UINT8_C(119), UINT8_C(209), UINT8_C(149), UINT8_C(183) } },
    { { UINT8_C(102), UINT8_C( 35), UINT8_C(245), UINT8_C( 23), UINT8_C( 16), UINT8_C(232), UINT8_C(163), UINT8_C(185) },
      { UINT8_C(227), UINT8_C(162), UINT8_C(173), UINT8_C(104), UINT8_C(253), UINT8_C(  6), UINT8_C(224), UINT8_C(154) },
      { UINT8_C(137), UINT8_C( 12), UINT8_C(248), UINT8_C( 92), UINT8_C(133), UINT8_C( 21), UINT8_C(  3), UINT8_C(122) } },
    { { UINT8_C(128), UINT8_C(147), UINT8_C( 31), UINT8_C(104), UINT8_C( 27), UINT8_C( 29), UINT8_C( 49), UINT8_C( 60) },
      { UINT8_C(116), UINT8_C(112), UINT8_C(206), UINT8_C(215), UINT8_C(162),    UINT8_MAX, UINT8_C( 94), UINT8_C(  8) },
      { UINT8_C( 19), UINT8_C(135), UINT8_C( 56), UINT8_C(109), UINT8_C(228), UINT8_C(165), UINT8_C(161), UINT8_C(102) } },
    { { UINT8_C( 34), UINT8_C( 83), UINT8_C( 31), UINT8_C( 50), UINT8_C( 60), UINT8_C(195), UINT8_C(236), UINT8_C( 31) },
      { UINT8_C(101), UINT8_C(153), UINT8_C(136), UINT8_C( 98), UINT8_C(159), UINT8_C(104), UINT8_C(252), UINT8_C( 31) },
      { UINT8_C(117), UINT8_C( 81),    UINT8_MAX, UINT8_C( 11), UINT8_C(254), UINT8_C(234), UINT8_C(  7), UINT8_C( 27) } },
    { { UINT8_C(252), UINT8_C( 28), UINT8_C(136), UINT8_C( 23), UINT8_C( 57), UINT8_C(185), UINT8_C( 83), UINT8_C(173) },
      { UINT8_C( 41), UINT8_C( 34), UINT8_C(132), UINT8_C(204), UINT8_C( 33), UINT8_C(226), UINT8_C(212), UINT8_C( 67) },
      { UINT8_C( 24), UINT8_C(159), UINT8_C(242), UINT8_C(  0), UINT8_C( 75), UINT8_C( 80), UINT8_C(  3), UINT8_C( 23) } },
    { { UINT8_C( 53), UINT8_C(244), UINT8_C(118), UINT8_C(113), UINT8_C(183), UINT8_C( 98), UINT8_C(145), UINT8_C( 28) },
      { UINT8_C(251), UINT8_C( 25), UINT8_C(126), UINT8_C(154), UINT8_C(129), UINT8_C(122), UINT8_C(185), UINT8_C(125) },
      { UINT8_C( 41), UINT8_C(231), UINT8_C( 25), UINT8_C(173), UINT8_C( 20), UINT8_C( 24), UINT8_C(251), UINT8_C( 54) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vpadd_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpadd_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(21226), UINT16_C(34183), UINT16_C(22510), UINT16_C(15812) },
      { UINT16_C( 9063), UINT16_C(27641), UINT16_C(59469), UINT16_C(64332) },
      { UINT16_C(55409), UINT16_C(38322), UINT16_C(36704), UINT16_C(58265) } },
    { { UINT16_C(31569), UINT16_C(54281), UINT16_C(16377), UINT16_C( 5882) },
      { UINT16_C(15455), UINT16_C(11970), UINT16_C(43165), UINT16_C(34802) },
      { UINT16_C(20314), UINT16_C(22259), UINT16_C(27425), UINT16_C(12431) } },
    { { UINT16_C(31227), UINT16_C(59660), UINT16_C(53457), UINT16_C(14374) },
      { UINT16_C( 8435), UINT16_C(16548), UINT16_C(61448), UINT16_C(22843) },
      { UINT16_C(25351), UINT16_C( 2295), UINT16_C(24983), UINT16_C(18755) } },
    { { UINT16_C(17515), UINT16_C(25901), UINT16_C(10116), UINT16_C(58235) },
      { UINT16_C(15715), UINT16_C(   17), UINT16_C(  998), UINT16_C(57735) },
      { UINT16_C(43416), UINT16_C( 2815), UINT16_C(15732), UINT16_C(58733) } },
    { { UINT16_C(37757), UINT16_C(20170), UINT16_C(61796), UINT16_C(22406) },
      { UINT16_C(10769), UINT16_C( 6552), UINT16_C(54042), UINT16_C(34418) },
      { UINT16_C(57927), UINT16_C(18666), UINT16_C(17321), UINT16_C(22924) } },
    { { UINT16_C(40728), UINT16_C(40171), UINT16_C(26310), UINT16_C(10623) },
      { UINT16_C(37027), UINT16_C(35114), UINT16_C(45460), UINT16_C( 4458) },
      { UINT16_C(15363), UINT16_C(36933), UINT16_C( 6605), UINT16_C(49918) } },
    { { UINT16_C(13637), UINT16_C(43359), UINT16_C(58662), UINT16_C(14080) },
      { UINT16_C(38928), UINT16_C(10832), UINT16_C(49772), UINT16_C(33968) },
      { UINT16_C(56996), UINT16_C( 7206), UINT16_C(49760), UINT16_C(18204) } },
    { { UINT16_C(39777), UINT16_C(10016), UINT16_C(40705), UINT16_C(42320) },
      { UINT16_C(31279), UINT16_C(49966), UINT16_C(39212), UINT16_C(29140) },
      { UINT16_C(49793), UINT16_C(17489), UINT16_C(15709), UINT16_C( 2816) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vpadd_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpadd_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3709109624), UINT32_C(4040697517) },
      { UINT32_C( 609191128), UINT32_C(2173632669) },
      { UINT32_C(3454839845), UINT32_C(2782823797) } },
    { { UINT32_C( 887164280), UINT32_C(2941533126) },
      { UINT32_C( 856155564), UINT32_C(2881345843) },
      { UINT32_C(3828697406), UINT32_C(3737501407) } },
    { { UINT32_C( 193516126), UINT32_C(3506135544) },
      { UINT32_C(2197113829), UINT32_C(3288564811) },
      { UINT32_C(3699651670), UINT32_C(1190711344) } },
    { { UINT32_C(1492706449), UINT32_C(3406253087) },
      { UINT32_C(1694371377), UINT32_C(1158724839) },
      { UINT32_C( 603992240), UINT32_C(2853096216) } },
    { { UINT32_C(2253494414), UINT32_C(3730263289) },
      { UINT32_C(3814739095), UINT32_C(1638360016) },
      { UINT32_C(1688790407), UINT32_C(1158131815) } },
    { { UINT32_C(1723440967), UINT32_C( 473088491) },
      { UINT32_C(3078631631), UINT32_C(2063372524) },
      { UINT32_C(2196529458), UINT32_C( 847036859) } },
    { { UINT32_C( 570510633), UINT32_C( 822171802) },
      { UINT32_C(1947492772), UINT32_C( 215333829) },
      { UINT32_C(1392682435), UINT32_C(2162826601) } },
    { { UINT32_C(1165201242), UINT32_C( 526493008) },
      { UINT32_C(3268862677), UINT32_C(2604454770) },
      { UINT32_C(1691694250), UINT32_C(1578350151) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vpadd_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   288.42), SIMDE_FLOAT32_C(   -21.02), SIMDE_FLOAT32_C(  -974.95), SIMDE_FLOAT32_C(  -192.40) },
      { SIMDE_FLOAT32_C(  -577.52), SIMDE_FLOAT32_C(   442.97), SIMDE_FLOAT32_C(  -440.24), SIMDE_FLOAT32_C(   115.18) },
      { SIMDE_FLOAT32_C(   267.40), SIMDE_FLOAT32_C( -1167.35), SIMDE_FLOAT32_C(  -134.54), SIMDE_FLOAT32_C(  -325.05) } },
    { { SIMDE_FLOAT32_C(     7.02), SIMDE_FLOAT32_C(  -617.77), SIMDE_FLOAT32_C(   477.82), SIMDE_FLOAT32_C(   908.71) },
      { SIMDE_FLOAT32_C(  -987.94), SIMDE_FLOAT32_C(  -606.22), SIMDE_FLOAT32_C(  -272.93), SIMDE_FLOAT32_C(  -275.00) },
      { SIMDE_FLOAT32_C(  -610.74), SIMDE_FLOAT32_C(  1386.53), SIMDE_FLOAT32_C( -1594.16), SIMDE_FLOAT32_C(  -547.94) } },
    { { SIMDE_FLOAT32_C(   -93.25), SIMDE_FLOAT32_C(   892.97), SIMDE_FLOAT32_C(  -408.68), SIMDE_FLOAT32_C(   -20.37) },
      { SIMDE_FLOAT32_C(  -622.02), SIMDE_FLOAT32_C(  -239.70), SIMDE_FLOAT32_C(   793.71), SIMDE_FLOAT32_C(  -983.86) },
      { SIMDE_FLOAT32_C(   799.72), SIMDE_FLOAT32_C(  -429.06), SIMDE_FLOAT32_C(  -861.72), SIMDE_FLOAT32_C(  -190.15) } },
    { { SIMDE_FLOAT32_C(  -339.96), SIMDE_FLOAT32_C(   415.18), SIMDE_FLOAT32_C(   196.04), SIMDE_FLOAT32_C(  -159.70) },
      { SIMDE_FLOAT32_C(   128.82), SIMDE_FLOAT32_C(   843.81), SIMDE_FLOAT32_C(   217.86), SIMDE_FLOAT32_C(  -582.76) },
      { SIMDE_FLOAT32_C(    75.21), SIMDE_FLOAT32_C(    36.34), SIMDE_FLOAT32_C(   972.63), SIMDE_FLOAT32_C(  -364.90) } },
    { { SIMDE_FLOAT32_C(  -177.21), SIMDE_FLOAT32_C(   242.90), SIMDE_FLOAT32_C(   224.84), SIMDE_FLOAT32_C(   245.28) },
      { SIMDE_FLOAT32_C(  -314.13), SIMDE_FLOAT32_C(   784.61), SIMDE_FLOAT32_C(  -639.54), SIMDE_FLOAT32_C(   692.90) },
      { SIMDE_FLOAT32_C(    65.70), SIMDE_FLOAT32_C(   470.12), SIMDE_FLOAT32_C(   470.48), SIMDE_FLOAT32_C(    53.36) } },
    { { SIMDE_FLOAT32_C(  -833.16), SIMDE_FLOAT32_C(   838.28), SIMDE_FLOAT32_C(   601.61), SIMDE_FLOAT32_C(  -821.10) },
      { SIMDE_FLOAT32_C(  -767.94), SIMDE_FLOAT32_C(  -671.32), SIMDE_FLOAT32_C(   -96.10), SIMDE_FLOAT32_C(   138.81) },
      { SIMDE_FLOAT32_C(     5.12), SIMDE_FLOAT32_C(  -219.49), SIMDE_FLOAT32_C( -1439.26), SIMDE_FLOAT32_C(    42.71) } },
    { { SIMDE_FLOAT32_C(  -778.36), SIMDE_FLOAT32_C(   495.21), SIMDE_FLOAT32_C(  -881.56), SIMDE_FLOAT32_C(  -400.38) },
      { SIMDE_FLOAT32_C(  -744.48), SIMDE_FLOAT32_C(   912.15), SIMDE_FLOAT32_C(  -384.24), SIMDE_FLOAT32_C(   -84.44) },
      { SIMDE_FLOAT32_C(  -283.14), SIMDE_FLOAT32_C( -1281.94), SIMDE_FLOAT32_C(   167.67), SIMDE_FLOAT32_C(  -468.68) } },
    { { SIMDE_FLOAT32_C(   327.32), SIMDE_FLOAT32_C(   811.80), SIMDE_FLOAT32_C(   755.86), SIMDE_FLOAT32_C(  -543.86) },
      { SIMDE_FLOAT32_C(   655.62), SIMDE_FLOAT32_C(   -26.28), SIMDE_FLOAT32_C(  -126.62), SIMDE_FLOAT32_C(  -521.59) },
      { SIMDE_FLOAT32_C(  1139.13), SIMDE_FLOAT32_C(   212.00), SIMDE_FLOAT32_C(   629.33), SIMDE_FLOAT32_C(  -648.21) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vpaddq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpaddq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -304.59), SIMDE_FLOAT64_C(   738.24) },
      { SIMDE_FLOAT64_C(  -491.10), SIMDE_FLOAT64_C(    20.25) },
      { SIMDE_FLOAT64_C(   433.66), SIMDE_FLOAT64_C(  -470.85) } },
    { { SIMDE_FLOAT64_C(    46.86), SIMDE_FLOAT64_C(  -650.53) },
      { SIMDE_FLOAT64_C(   209.27), SIMDE_FLOAT64_C(   722.54) },
      { SIMDE_FLOAT64_C(  -603.67), SIMDE_FLOAT64_C(   931.81) } },
    { { SIMDE_FLOAT64_C(  -507.52), SIMDE_FLOAT64_C(    40.12) },
      { SIMDE_FLOAT64_C(   676.59), SIMDE_FLOAT64_C(   843.37) },
      { SIMDE_FLOAT64_C(  -467.40), SIMDE_FLOAT64_C(  1519.96) } },
    { { SIMDE_FLOAT64_C(  -613.61), SIMDE_FLOAT64_C(   272.81) },
      { SIMDE_FLOAT64_C(   650.30), SIMDE_FLOAT64_C(   222.96) },
      { SIMDE_FLOAT64_C(  -340.80), SIMDE_FLOAT64_C(   873.26) } },
    { { SIMDE_FLOAT64_C(   615.20), SIMDE_FLOAT64_C(  -394.78) },
      { SIMDE_FLOAT64_C(   469.07), SIMDE_FLOAT64_C(    54.35) },
      { SIMDE_FLOAT64_C(   220.41), SIMDE_FLOAT64_C(   523.42) } },
    { { SIMDE_FLOAT64_C(  -172.64), SIMDE_FLOAT64_C(   682.30) },
      { SIMDE_FLOAT64_C(  -786.74), SIMDE_FLOAT64_C(   236.37) },
      { SIMDE_FLOAT64_C(   509.66), SIMDE_FLOAT64_C(  -550.37) } },
    { { SIMDE_FLOAT64_C(   915.30), SIMDE_FLOAT64_C(   782.55) },
      { SIMDE_FLOAT64_C(   199.30), SIMDE_FLOAT64_C(  -594.15) },
      { SIMDE_FLOAT64_C(  1697.85), SIMDE_FLOAT64_C(  -394.85) } },
    { { SIMDE_FLOAT64_C(   264.00), SIMDE_FLOAT64_C(  -410.11) },
      { SIMDE_FLOAT64_C(  -427.51), SIMDE_FLOAT64_C(   959.41) },
      { SIMDE_FLOAT64_C(  -146.12), SIMDE_FLOAT64_C(   531.90) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vpaddq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpaddq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C( 120),  INT8_C( 124), -INT8_C( 100), -INT8_C(  34), -INT8_C( 111),  INT8_C(  99),  INT8_C(   2),  INT8_C(  11),
         INT8_C(  41),  INT8_C(  86),  INT8_C( 126), -INT8_C(  10), -INT8_C(   4),  INT8_C(  80), -INT8_C( 113), -INT8_C(  35) },
      { -INT8_C(  85), -INT8_C(  62), -INT8_C(  41),  INT8_C( 122),  INT8_C( 100),  INT8_C(  10),  INT8_C( 105), -INT8_C( 112),
        -INT8_C(  97),  INT8_C( 104), -INT8_C( 126), -INT8_C( 104), -INT8_C(  97), -INT8_C(  30), -INT8_C(  82),  INT8_C(  23) },
      { -INT8_C(  12),  INT8_C( 122), -INT8_C(  12),  INT8_C(  13),      INT8_MAX,  INT8_C( 116),  INT8_C(  76),  INT8_C( 108),
         INT8_C( 109),  INT8_C(  81),  INT8_C( 110), -INT8_C(   7),  INT8_C(   7),  INT8_C(  26), -INT8_C( 127), -INT8_C(  59) } },
    { {  INT8_C(  94),  INT8_C(  74), -INT8_C(  11), -INT8_C(  17), -INT8_C(  83), -INT8_C(   8), -INT8_C(   6), -INT8_C(  42),
         INT8_C(  78),  INT8_C( 120), -INT8_C(  52),  INT8_C(  75), -INT8_C(  56),  INT8_C(  92),  INT8_C(  40),  INT8_C( 115) },
      {  INT8_C(  30), -INT8_C(   1), -INT8_C(  19), -INT8_C( 125),  INT8_C(  10),  INT8_C(  86),  INT8_C(  19), -INT8_C(  87),
        -INT8_C(  66), -INT8_C( 107),  INT8_C(  65),  INT8_C(  93),  INT8_C( 119), -INT8_C(  17),  INT8_C( 117), -INT8_C(  43) },
      { -INT8_C(  88), -INT8_C(  28), -INT8_C(  91), -INT8_C(  48), -INT8_C(  58),  INT8_C(  23),  INT8_C(  36), -INT8_C( 101),
         INT8_C(  29),  INT8_C( 112),  INT8_C(  96), -INT8_C(  68),  INT8_C(  83), -INT8_C(  98),  INT8_C( 102),  INT8_C(  74) } },
    { {  INT8_C(  57),  INT8_C( 106), -INT8_C(  60), -INT8_C(  25),  INT8_C(  98), -INT8_C(  66), -INT8_C(  67), -INT8_C(  79),
         INT8_C(  54), -INT8_C( 118), -INT8_C(   4), -INT8_C(   2), -INT8_C(  26),  INT8_C(  36),  INT8_C( 113),  INT8_C(   4) },
      {  INT8_C(  35),  INT8_C(  95), -INT8_C( 121),  INT8_C(  45), -INT8_C(  75), -INT8_C( 102), -INT8_C(  41),  INT8_C( 116),
         INT8_C(  47),  INT8_C(  24), -INT8_C(  47), -INT8_C(  90),  INT8_C(   8),  INT8_C(  70),  INT8_C( 123),  INT8_C(  65) },
      { -INT8_C(  93), -INT8_C(  85),  INT8_C(  32),  INT8_C( 110), -INT8_C(  64), -INT8_C(   6),  INT8_C(  10),  INT8_C( 117),
        -INT8_C( 126), -INT8_C(  76),  INT8_C(  79),  INT8_C(  75),  INT8_C(  71),  INT8_C( 119),  INT8_C(  78), -INT8_C(  68) } },
    { { -INT8_C(  79),  INT8_C(  63),  INT8_C(  40),  INT8_C(  19), -INT8_C(   3), -INT8_C(  26), -INT8_C(  60),  INT8_C(  51),
         INT8_C( 112), -INT8_C(  64),  INT8_C(  49),  INT8_C(  86), -INT8_C(  28), -INT8_C(  93),  INT8_C(  90),  INT8_C(   8) },
      {  INT8_C(   2), -INT8_C(  30),  INT8_C(  53), -INT8_C(  73),  INT8_C( 124),  INT8_C(  12),  INT8_C(  43), -INT8_C(  84),
         INT8_C(  37), -INT8_C(   3),  INT8_C(  82),  INT8_C(  45),  INT8_C(  67), -INT8_C(  50),  INT8_C( 110), -INT8_C(  12) },
      { -INT8_C(  16),  INT8_C(  59), -INT8_C(  29), -INT8_C(   9),  INT8_C(  48), -INT8_C( 121), -INT8_C( 121),  INT8_C(  98),
        -INT8_C(  28), -INT8_C(  20), -INT8_C( 120), -INT8_C(  41),  INT8_C(  34),      INT8_MAX,  INT8_C(  17),  INT8_C(  98) } },
    { {  INT8_C(  13), -INT8_C( 105),  INT8_C(   8),  INT8_C(  11),  INT8_C( 125), -INT8_C(  52),  INT8_C(  62), -INT8_C(  19),
        -INT8_C( 115),  INT8_C( 112),  INT8_C(  67),  INT8_C( 113),  INT8_C(  19), -INT8_C(  99),  INT8_C( 121),  INT8_C(  21) },
      {      INT8_MAX, -INT8_C(  81), -INT8_C(  52), -INT8_C(   4), -INT8_C(  69), -INT8_C(   8), -INT8_C(  88), -INT8_C(  32),
        -INT8_C(  11), -INT8_C(   6),  INT8_C(  13),  INT8_C(  56), -INT8_C(  56),  INT8_C( 124),  INT8_C(  45), -INT8_C(  42) },
      { -INT8_C(  92),  INT8_C(  19),  INT8_C(  73),  INT8_C(  43), -INT8_C(   3), -INT8_C(  76), -INT8_C(  80), -INT8_C( 114),
         INT8_C(  46), -INT8_C(  56), -INT8_C(  77), -INT8_C( 120), -INT8_C(  17),  INT8_C(  69),  INT8_C(  68),  INT8_C(   3) } },
    { {  INT8_C(  19),  INT8_C(  53), -INT8_C(  31), -INT8_C( 112),  INT8_C(   1),  INT8_C(  31),  INT8_C( 125), -INT8_C( 114),
        -INT8_C( 113), -INT8_C(  64),  INT8_C(   0), -INT8_C(  94),  INT8_C(  93),  INT8_C( 121), -INT8_C(  73), -INT8_C(  35) },
      {  INT8_C(  40), -INT8_C( 124), -INT8_C(  39), -INT8_C(  28),  INT8_C( 124), -INT8_C( 127), -INT8_C(  60),  INT8_C( 113),
         INT8_C( 123), -INT8_C(  46), -INT8_C(  87),  INT8_C(  68),  INT8_C(  78), -INT8_C(  42),  INT8_C(  26),  INT8_C(  97) },
      {  INT8_C(  72),  INT8_C( 113),  INT8_C(  32),  INT8_C(  11),  INT8_C(  79), -INT8_C(  94), -INT8_C(  42), -INT8_C( 108),
        -INT8_C(  84), -INT8_C(  67), -INT8_C(   3),  INT8_C(  53),  INT8_C(  77), -INT8_C(  19),  INT8_C(  36),  INT8_C( 123) } },
    { {  INT8_C(  11), -INT8_C(   5), -INT8_C(  15),  INT8_C(  13),  INT8_C(  26),  INT8_C( 110), -INT8_C( 101), -INT8_C(  86),
         INT8_C(  46), -INT8_C( 101),  INT8_C(  76), -INT8_C( 117),  INT8_C(  21),  INT8_C(   4),  INT8_C( 104),  INT8_C(  61) },
      { -INT8_C( 120),  INT8_C(  65),  INT8_C(  33),  INT8_C(   4), -INT8_C(  62), -INT8_C(  26),  INT8_C( 117),  INT8_C(  62),
        -INT8_C(  72),  INT8_C(  30), -INT8_C( 126),  INT8_C(   6), -INT8_C(  11), -INT8_C( 100),  INT8_C( 103),  INT8_C(   0) },
      {  INT8_C(   6), -INT8_C(   2), -INT8_C( 120),  INT8_C(  69), -INT8_C(  55), -INT8_C(  41),  INT8_C(  25), -INT8_C(  91),
        -INT8_C(  55),  INT8_C(  37), -INT8_C(  88), -INT8_C(  77), -INT8_C(  42), -INT8_C( 120), -INT8_C( 111),  INT8_C( 103) } },
    { { -INT8_C( 105),  INT8_C(  88),  INT8_C(  13), -INT8_C(  79), -INT8_C(  58), -INT8_C(  87),  INT8_C(  91), -INT8_C(  12),
         INT8_C(  68), -INT8_C(  88),      INT8_MAX,  INT8_C(  89), -INT8_C(  84), -INT8_C(  24), -INT8_C( 105),  INT8_C(  52) },
      {  INT8_C(  41), -INT8_C(  72),  INT8_C(  56), -INT8_C(  20), -INT8_C(  98), -INT8_C(  83),  INT8_C(  42),  INT8_C(  86),
        -INT8_C(  53), -INT8_C(  84),  INT8_C(  92), -INT8_C(  64),  INT8_C(  72), -INT8_C(  61), -INT8_C(  63), -INT8_C(  33) },
      { -INT8_C(  17), -INT8_C(  66),  INT8_C( 111),  INT8_C(  79), -INT8_C(  20), -INT8_C(  40), -INT8_C( 108), -INT8_C(  53),
        -INT8_C(  31),  INT8_C(  36),  INT8_C(  75),      INT8_MIN,  INT8_C( 119),  INT8_C(  28),  INT8_C(  11), -INT8_C(  96) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vpaddq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 29696),  INT16_C( 13750),  INT16_C( 24319),  INT16_C( 26400),  INT16_C(  9764),  INT16_C( 24428), -INT16_C( 10546),  INT16_C( 14168) },
      { -INT16_C( 17422),  INT16_C(  6892),  INT16_C( 26568),  INT16_C(  6610),  INT16_C(  2432), -INT16_C( 27244),  INT16_C( 19912), -INT16_C( 13860) },
      { -INT16_C( 15946), -INT16_C( 14817), -INT16_C( 31344),  INT16_C(  3622), -INT16_C( 10530), -INT16_C( 32358), -INT16_C( 24812),  INT16_C(  6052) } },
    { { -INT16_C( 27943), -INT16_C(  9986),  INT16_C(  7920),  INT16_C(  5439), -INT16_C( 21692),  INT16_C(  4724), -INT16_C( 12927),  INT16_C( 29769) },
      {  INT16_C( 13704),  INT16_C( 20622),  INT16_C( 24733),  INT16_C(  7529), -INT16_C(   407),  INT16_C( 12979), -INT16_C( 28853),  INT16_C(  9467) },
      {  INT16_C( 27607),  INT16_C( 13359), -INT16_C( 16968),  INT16_C( 16842), -INT16_C( 31210),  INT16_C( 32262),  INT16_C( 12572), -INT16_C( 19386) } },
    { { -INT16_C(  1759),  INT16_C(  4604),  INT16_C( 15128),  INT16_C( 23590), -INT16_C( 25625),  INT16_C( 26735), -INT16_C( 18328), -INT16_C(  3876) },
      {  INT16_C( 27374), -INT16_C( 29888), -INT16_C( 21814),  INT16_C( 13480),  INT16_C( 23464), -INT16_C(  3226),  INT16_C( 25066),  INT16_C(  2839) },
      {  INT16_C(  2845), -INT16_C( 26818),  INT16_C(  1110), -INT16_C( 22204), -INT16_C(  2514), -INT16_C(  8334),  INT16_C( 20238),  INT16_C( 27905) } },
    { {  INT16_C(  4954),  INT16_C( 29213),  INT16_C( 17230),  INT16_C( 13775),  INT16_C( 16094),  INT16_C( 18078),  INT16_C( 31478), -INT16_C(  7114) },
      {  INT16_C( 30693), -INT16_C( 20625),  INT16_C(  6177), -INT16_C( 13853),  INT16_C( 18803),  INT16_C( 24252), -INT16_C( 11350),  INT16_C(  1385) },
      { -INT16_C( 31369),  INT16_C( 31005), -INT16_C( 31364),  INT16_C( 24364),  INT16_C( 10068), -INT16_C(  7676), -INT16_C( 22481), -INT16_C(  9965) } },
    { { -INT16_C( 31002),  INT16_C( 13431),  INT16_C( 18122), -INT16_C( 22422),  INT16_C(  2180),  INT16_C( 31727),  INT16_C(  9602),  INT16_C( 26463) },
      { -INT16_C( 12388), -INT16_C( 17129), -INT16_C(  1305),  INT16_C( 23174),  INT16_C( 16964), -INT16_C(  4424),  INT16_C(  8725), -INT16_C(  1037) },
      { -INT16_C( 17571), -INT16_C(  4300), -INT16_C( 31629), -INT16_C( 29471), -INT16_C( 29517),  INT16_C( 21869),  INT16_C( 12540),  INT16_C(  7688) } },
    { {  INT16_C( 27560),  INT16_C( 29232), -INT16_C( 25935),  INT16_C( 13851),  INT16_C(  2722),  INT16_C(  9393),  INT16_C(  4143), -INT16_C( 13172) },
      { -INT16_C( 23585), -INT16_C( 14711),  INT16_C(  4253), -INT16_C(  7903), -INT16_C(  9902),  INT16_C( 26832), -INT16_C( 15365), -INT16_C( 23453) },
      { -INT16_C(  8744), -INT16_C( 12084),  INT16_C( 12115), -INT16_C(  9029),  INT16_C( 27240), -INT16_C(  3650),  INT16_C( 16930),  INT16_C( 26718) } },
    { { -INT16_C( 27858), -INT16_C(  8170),  INT16_C( 12589), -INT16_C( 12522), -INT16_C( 14533),  INT16_C( 27636), -INT16_C( 32553), -INT16_C( 18633) },
      { -INT16_C( 16349), -INT16_C( 16259), -INT16_C( 24880),  INT16_C(  9122),  INT16_C( 29304),  INT16_C( 29579), -INT16_C(  4555),  INT16_C( 25623) },
      {  INT16_C( 29508),  INT16_C(    67),  INT16_C( 13103),  INT16_C( 14350), -INT16_C( 32608), -INT16_C( 15758), -INT16_C(  6653),  INT16_C( 21068) } },
    { {  INT16_C( 11906), -INT16_C( 20668),  INT16_C( 23135), -INT16_C( 25729),  INT16_C( 29473), -INT16_C(  2042),  INT16_C( 15859),  INT16_C(  5807) },
      {  INT16_C( 11773), -INT16_C( 12586),  INT16_C( 30923),  INT16_C( 17393),  INT16_C( 31978),  INT16_C(  8375), -INT16_C( 12694), -INT16_C(  4988) },
      { -INT16_C(  8762), -INT16_C(  2594),  INT16_C( 27431),  INT16_C( 21666), -INT16_C(   813), -INT16_C( 17220), -INT16_C( 25183), -INT16_C( 17682) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vpaddq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   630741622),  INT32_C(   504305028), -INT32_C(   187880710),  INT32_C(   867999092) },
      {  INT32_C(   824916310), -INT32_C(  1005749701),  INT32_C(  1610912158),  INT32_C(   723032501) },
      {  INT32_C(  1135046650),  INT32_C(   680118382), -INT32_C(   180833391), -INT32_C(  1961022637) } },
    { {  INT32_C(  2018619635), -INT32_C(  1080663867), -INT32_C(     5020790),  INT32_C(  1462923264) },
      { -INT32_C(   460825175),  INT32_C(  1973982679), -INT32_C(   589976538),  INT32_C(   956820806) },
      {  INT32_C(   937955768),  INT32_C(  1457902474),  INT32_C(  1513157504),  INT32_C(   366844268) } },
    { {  INT32_C(  1655789725),  INT32_C(  1126254520), -INT32_C(  1421683285), -INT32_C(   301829051) },
      { -INT32_C(  1462531375),  INT32_C(  1176337183),  INT32_C(  1847783976),  INT32_C(  2091330015) },
      { -INT32_C(  1512923051), -INT32_C(  1723512336), -INT32_C(   286194192), -INT32_C(   355853305) } },
    { {  INT32_C(   987650434),  INT32_C(  1266548640),  INT32_C(   435666900),  INT32_C(    67696947) },
      { -INT32_C(  1548952700),  INT32_C(  2129250646), -INT32_C(  1695806533), -INT32_C(  1223257035) },
      { -INT32_C(  2040768222),  INT32_C(   503363847),  INT32_C(   580297946),  INT32_C(  1375903728) } },
    { { -INT32_C(  1913522963), -INT32_C(   925274124),  INT32_C(  1659031598),  INT32_C(  1298590409) },
      {  INT32_C(   468784069), -INT32_C(  1734681892),  INT32_C(   456296166),  INT32_C(   131221786) },
      {  INT32_C(  1456170209), -INT32_C(  1337345289), -INT32_C(  1265897823),  INT32_C(   587517952) } },
    { {  INT32_C(   831898429),  INT32_C(  1643802162),  INT32_C(   130276414), -INT32_C(  1957353018) },
      {  INT32_C(   430327356),  INT32_C(   112279584), -INT32_C(   517872697),  INT32_C(  1793717036) },
      { -INT32_C(  1819266705), -INT32_C(  1827076604),  INT32_C(   542606940),  INT32_C(  1275844339) } },
    { { -INT32_C(   375685449),  INT32_C(   709531116),  INT32_C(   925961585),  INT32_C(  1942128183) },
      { -INT32_C(   309564980),  INT32_C(  1894989225),  INT32_C(  1297224993), -INT32_C(  1078510840) },
      {  INT32_C(   333845667), -INT32_C(  1426877528),  INT32_C(  1585424245),  INT32_C(   218714153) } },
    { { -INT32_C(  1515629639),  INT32_C(  1523577832),  INT32_C(   949026817),  INT32_C(  1403737223) },
      {  INT32_C(  1715484861), -INT32_C(  1764281227),  INT32_C(  1373907273),  INT32_C(   487693156) },
      {  INT32_C(     7948193), -INT32_C(  1942203256), -INT32_C(    48796366),  INT32_C(  1861600429) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vpaddq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4896844547604500339),  INT64_C( 8765501941374251448) },
      { -INT64_C( 7785191802955445040),  INT64_C( 1730198806973093673) },
      { -INT64_C( 4784397584730799829), -INT64_C( 6054992995982351367) } },
    { {  INT64_C( 1703751951021001014),  INT64_C( 7056773999644983266) },
      {  INT64_C( 1684314300911287422), -INT64_C( 1497452695245042055) },
      {  INT64_C( 8760525950665984280),  INT64_C(  186861605666245367) } },
    { {  INT64_C(  629079142398964803), -INT64_C(  639111501445216464) },
      {  INT64_C( 7776910553607507943),  INT64_C( 2418646161902200048) },
      { -INT64_C(   10032359046251661), -INT64_C( 8251187358199843625) } },
    { { -INT64_C(  206181738529628939), -INT64_C(  957614104208629691) },
      { -INT64_C( 8409709677376931602), -INT64_C( 8387459978995116903) },
      { -INT64_C( 1163795842738258630),  INT64_C( 1649574417337503111) } },
    { {  INT64_C( 2335056876039200157), -INT64_C(  979651647068297879) },
      {  INT64_C( 9021304771970150156), -INT64_C( 4534404492057812240) },
      {  INT64_C( 1355405228970902278),  INT64_C( 4486900279912337916) } },
    { { -INT64_C( 1447745090286274324),  INT64_C( 7471128028670642104) },
      { -INT64_C( 8334121547303321610), -INT64_C( 3997185613633532509) },
      {  INT64_C( 6023382938384367780),  INT64_C( 6115436912772697497) } },
    { { -INT64_C(  123152696641276963),  INT64_C( 7422609973013293632) },
      { -INT64_C(  860300428430994969),  INT64_C( 2560932209795736038) },
      {  INT64_C( 7299457276372016669),  INT64_C( 1700631781364741069) } },
    { { -INT64_C( 3154265126970713099),  INT64_C( 4850501438233637751) },
      {  INT64_C( 1209450879884104066), -INT64_C( 4945130759824178186) },
      {  INT64_C( 1696236311262924652), -INT64_C( 3735679879940074120) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vpaddq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(204), UINT8_C( 23), UINT8_C(182), UINT8_C(158), UINT8_C(247), UINT8_C(226), UINT8_C(226), UINT8_C(178),
        UINT8_C(171), UINT8_C(144), UINT8_C( 17), UINT8_C( 54), UINT8_C(172), UINT8_C(220), UINT8_C(208), UINT8_C( 28) },
      { UINT8_C(134), UINT8_C(190), UINT8_C(132), UINT8_C(101), UINT8_C(198), UINT8_C(195), UINT8_C(108), UINT8_C( 76),
        UINT8_C(138), UINT8_C( 36), UINT8_C(  2), UINT8_C(216), UINT8_C( 42), UINT8_C( 49), UINT8_C(  3), UINT8_C(246) },
      { UINT8_C(227), UINT8_C( 84), UINT8_C(217), UINT8_C(148), UINT8_C( 59), UINT8_C( 71), UINT8_C(136), UINT8_C(236),
        UINT8_C( 68), UINT8_C(233), UINT8_C(137), UINT8_C(184), UINT8_C(174), UINT8_C(218), UINT8_C( 91), UINT8_C(249) } },
    { { UINT8_C( 72), UINT8_C(185), UINT8_C(148), UINT8_C( 64), UINT8_C(155), UINT8_C(118), UINT8_C(242), UINT8_C( 70),
        UINT8_C(  6), UINT8_C(  3), UINT8_C(124), UINT8_C(179), UINT8_C(223), UINT8_C( 77), UINT8_C(207), UINT8_C(101) },
      { UINT8_C( 11), UINT8_C( 84), UINT8_C(202), UINT8_C(209), UINT8_C( 23), UINT8_C( 54), UINT8_C( 30), UINT8_C(162),
        UINT8_C( 91), UINT8_C( 32), UINT8_C(122), UINT8_C(133), UINT8_C( 82), UINT8_C(125), UINT8_C(123), UINT8_C(154) },
      { UINT8_C(  1), UINT8_C(212), UINT8_C( 17), UINT8_C( 56), UINT8_C(  9), UINT8_C( 47), UINT8_C( 44), UINT8_C( 52),
        UINT8_C( 95), UINT8_C(155), UINT8_C( 77), UINT8_C(192), UINT8_C(123),    UINT8_MAX, UINT8_C(207), UINT8_C( 21) } },
    { { UINT8_C( 54), UINT8_C( 15), UINT8_C(218), UINT8_C(209), UINT8_C(133), UINT8_C(204), UINT8_C( 24), UINT8_C(140),
        UINT8_C(207), UINT8_C(148), UINT8_C( 63), UINT8_C(174), UINT8_C(225), UINT8_C( 14), UINT8_C( 19), UINT8_C(237) },
      { UINT8_C( 98), UINT8_C(222), UINT8_C(190), UINT8_C(122), UINT8_C( 20), UINT8_C(220), UINT8_C( 28), UINT8_C(111),
        UINT8_C(253), UINT8_C(150), UINT8_C(244), UINT8_C( 79), UINT8_C( 19), UINT8_C(111), UINT8_C(233), UINT8_C( 73) },
      { UINT8_C( 69), UINT8_C(171), UINT8_C( 81), UINT8_C(164), UINT8_C( 99), UINT8_C(237), UINT8_C(239), UINT8_C(  0),
        UINT8_C( 64), UINT8_C( 56), UINT8_C(240), UINT8_C(139), UINT8_C(147), UINT8_C( 67), UINT8_C(130), UINT8_C( 50) } },
    { { UINT8_C(126), UINT8_C(196), UINT8_C( 26), UINT8_C(  4), UINT8_C(144), UINT8_C( 50), UINT8_C(144), UINT8_C( 96),
        UINT8_C(199), UINT8_C(207), UINT8_C( 14), UINT8_C(168), UINT8_C(221), UINT8_C( 34), UINT8_C(149), UINT8_C( 64) },
      { UINT8_C(  0), UINT8_C( 84), UINT8_C(186), UINT8_C( 20), UINT8_C( 48), UINT8_C(214), UINT8_C(132), UINT8_C( 45),
        UINT8_C(108), UINT8_C(120), UINT8_C(124), UINT8_C(127), UINT8_C(232), UINT8_C(102), UINT8_C(200), UINT8_C(102) },
      { UINT8_C( 66), UINT8_C( 30), UINT8_C(194), UINT8_C(240), UINT8_C(150), UINT8_C(182),    UINT8_MAX, UINT8_C(213),
        UINT8_C( 84), UINT8_C(206), UINT8_C(  6), UINT8_C(177), UINT8_C(228), UINT8_C(251), UINT8_C( 78), UINT8_C( 46) } },
    { { UINT8_C( 42), UINT8_C(226), UINT8_C(106), UINT8_C(186), UINT8_C( 21), UINT8_C(250), UINT8_C( 26), UINT8_C(220),
        UINT8_C(201), UINT8_C( 41), UINT8_C(132), UINT8_C(167), UINT8_C( 75), UINT8_C( 26), UINT8_C(231), UINT8_C( 75) },
      { UINT8_C(110), UINT8_C(161), UINT8_C( 95), UINT8_C(158), UINT8_C(119), UINT8_C(227), UINT8_C(204), UINT8_C(227),
        UINT8_C( 92), UINT8_C( 72), UINT8_C( 98), UINT8_C( 68), UINT8_C(174), UINT8_C( 42), UINT8_C(170), UINT8_C(216) },
      { UINT8_C( 12), UINT8_C( 36), UINT8_C( 15), UINT8_C(246), UINT8_C(242), UINT8_C( 43), UINT8_C(101), UINT8_C( 50),
        UINT8_C( 15), UINT8_C(253), UINT8_C( 90), UINT8_C(175), UINT8_C(164), UINT8_C(166), UINT8_C(216), UINT8_C(130) } },
    { { UINT8_C( 12), UINT8_C( 21), UINT8_C(147), UINT8_C( 33), UINT8_C( 15), UINT8_C(173), UINT8_C(253), UINT8_C(217),
        UINT8_C(214), UINT8_C(130), UINT8_C(128), UINT8_C( 33), UINT8_C(156), UINT8_C(103), UINT8_C(108), UINT8_C( 10) },
      { UINT8_C(  8), UINT8_C(204), UINT8_C(168), UINT8_C(127), UINT8_C(175), UINT8_C(116), UINT8_C( 98), UINT8_C( 11),
        UINT8_C(189), UINT8_C(196), UINT8_C( 79), UINT8_C(107), UINT8_C(238), UINT8_C(250), UINT8_C( 68), UINT8_C(250) },
      { UINT8_C( 33), UINT8_C(180), UINT8_C(188), UINT8_C(214), UINT8_C( 88), UINT8_C(161), UINT8_C(  3), UINT8_C(118),
        UINT8_C(212), UINT8_C( 39), UINT8_C( 35), UINT8_C(109), UINT8_C(129), UINT8_C(186), UINT8_C(232), UINT8_C( 62) } },
    { { UINT8_C( 15), UINT8_C(215), UINT8_C( 28), UINT8_C( 30), UINT8_C(132), UINT8_C( 25), UINT8_C(247), UINT8_C( 91),
        UINT8_C(155), UINT8_C(119), UINT8_C(124), UINT8_C( 55), UINT8_C(222), UINT8_C(233), UINT8_C( 65), UINT8_C(230) },
      { UINT8_C(181), UINT8_C(234), UINT8_C(101), UINT8_C(100), UINT8_C( 94), UINT8_C(199), UINT8_C(112), UINT8_C( 27),
        UINT8_C(139), UINT8_C(191), UINT8_C(135), UINT8_C(121), UINT8_C(185), UINT8_C(203), UINT8_C(116), UINT8_C(200) },
      { UINT8_C(230), UINT8_C( 58), UINT8_C(157), UINT8_C( 82), UINT8_C( 18), UINT8_C(179), UINT8_C(199), UINT8_C( 39),
        UINT8_C(159), UINT8_C(201), UINT8_C( 37), UINT8_C(139), UINT8_C( 74), UINT8_C(  0), UINT8_C(132), UINT8_C( 60) } },
    { { UINT8_C(162), UINT8_C(144), UINT8_C(231), UINT8_C( 38), UINT8_C(169), UINT8_C(222), UINT8_C(129), UINT8_C( 69),
        UINT8_C( 86), UINT8_C(254), UINT8_C(124), UINT8_C( 52), UINT8_C(231), UINT8_C(190), UINT8_C( 27), UINT8_C(156) },
      { UINT8_C(168), UINT8_C(128), UINT8_C(  0), UINT8_C(  6), UINT8_C( 72), UINT8_C(112), UINT8_C( 34), UINT8_C(211),
        UINT8_C( 48), UINT8_C(169), UINT8_C( 77), UINT8_C(233), UINT8_C(116), UINT8_C(193), UINT8_C(178), UINT8_C( 22) },
      { UINT8_C( 50), UINT8_C( 13), UINT8_C(135), UINT8_C(198), UINT8_C( 84), UINT8_C(176), UINT8_C(165), UINT8_C(183),
        UINT8_C( 40), UINT8_C(  6), UINT8_C(184), UINT8_C(245), UINT8_C(217), UINT8_C( 54), UINT8_C( 53), UINT8_C(200) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vpaddq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 9349), UINT16_C(24087), UINT16_C(49567), UINT16_C( 4999), UINT16_C( 2307), UINT16_C(62434), UINT16_C(18810), UINT16_C(11356) },
      { UINT16_C(14700), UINT16_C(56484), UINT16_C(45907), UINT16_C(11347), UINT16_C(51476), UINT16_C(16753), UINT16_C( 2394), UINT16_C(57376) },
      { UINT16_C(33436), UINT16_C(54566), UINT16_C(64741), UINT16_C(30166), UINT16_C( 5648), UINT16_C(57254), UINT16_C( 2693), UINT16_C(59770) } },
    { { UINT16_C(14125), UINT16_C(52542), UINT16_C(50680), UINT16_C(64736), UINT16_C(49871), UINT16_C(18927), UINT16_C(19211), UINT16_C(30837) },
      { UINT16_C( 6532), UINT16_C(55124), UINT16_C(42957), UINT16_C(57604), UINT16_C(30064), UINT16_C(52002), UINT16_C(17022), UINT16_C(43947) },
      { UINT16_C( 1131), UINT16_C(49880), UINT16_C( 3262), UINT16_C(50048), UINT16_C(61656), UINT16_C(35025), UINT16_C(16530), UINT16_C(60969) } },
    { { UINT16_C(59770), UINT16_C(29304), UINT16_C(22702), UINT16_C(32110), UINT16_C(23835), UINT16_C( 9926), UINT16_C(15272), UINT16_C(11678) },
      { UINT16_C(62293), UINT16_C( 8708), UINT16_C( 2202), UINT16_C( 2819), UINT16_C( 9597), UINT16_C(64470), UINT16_C(33128), UINT16_C(58023) },
      { UINT16_C(23538), UINT16_C(54812), UINT16_C(33761), UINT16_C(26950), UINT16_C( 5465), UINT16_C( 5021), UINT16_C( 8531), UINT16_C(25615) } },
    { { UINT16_C( 8042), UINT16_C( 6228), UINT16_C(50040), UINT16_C(37782), UINT16_C(23584), UINT16_C(51641), UINT16_C(22680), UINT16_C(60918) },
      { UINT16_C(64075), UINT16_C(58639), UINT16_C( 4611), UINT16_C(33008), UINT16_C(50743), UINT16_C(40828), UINT16_C( 9031), UINT16_C(45441) },
      { UINT16_C(14270), UINT16_C(22286), UINT16_C( 9689), UINT16_C(18062), UINT16_C(57178), UINT16_C(37619), UINT16_C(26035), UINT16_C(54472) } },
    { { UINT16_C(54850), UINT16_C(47818), UINT16_C(24729), UINT16_C(47437), UINT16_C( 1980), UINT16_C(21634), UINT16_C(30815), UINT16_C(43585) },
      { UINT16_C(20595), UINT16_C(30351), UINT16_C(32866), UINT16_C(39670), UINT16_C(29254), UINT16_C(36409), UINT16_C(48021), UINT16_C(55359) },
      { UINT16_C(37132), UINT16_C( 6630), UINT16_C(23614), UINT16_C( 8864), UINT16_C(50946), UINT16_C( 7000), UINT16_C(  127), UINT16_C(37844) } },
    { { UINT16_C( 2449), UINT16_C(10898), UINT16_C(57449), UINT16_C( 9955), UINT16_C(26343), UINT16_C(18042), UINT16_C(48350), UINT16_C(20976) },
      { UINT16_C(32524), UINT16_C(28615), UINT16_C(48895), UINT16_C(17929), UINT16_C(16944), UINT16_C(50900), UINT16_C( 5117), UINT16_C(36510) },
      { UINT16_C(13347), UINT16_C( 1868), UINT16_C(44385), UINT16_C( 3790), UINT16_C(61139), UINT16_C( 1288), UINT16_C( 2308), UINT16_C(41627) } },
    { { UINT16_C(12317), UINT16_C(34488), UINT16_C(39952), UINT16_C(63404), UINT16_C( 9986), UINT16_C(57405), UINT16_C(11747), UINT16_C(61234) },
      { UINT16_C(63917), UINT16_C(44126), UINT16_C(26551), UINT16_C(59634), UINT16_C(50858), UINT16_C(42926), UINT16_C(19674), UINT16_C(63286) },
      { UINT16_C(46805), UINT16_C(37820), UINT16_C( 1855), UINT16_C( 7445), UINT16_C(42507), UINT16_C(20649), UINT16_C(28248), UINT16_C(17424) } },
    { { UINT16_C(61052), UINT16_C(36221), UINT16_C(10890), UINT16_C(35972), UINT16_C(49745), UINT16_C(13421), UINT16_C(40943), UINT16_C(39971) },
      { UINT16_C(33432), UINT16_C(20553), UINT16_C(15337), UINT16_C(37688), UINT16_C(58882), UINT16_C(56379), UINT16_C(28978), UINT16_C(44755) },
      { UINT16_C(31737), UINT16_C(46862), UINT16_C(63166), UINT16_C(15378), UINT16_C(53985), UINT16_C(53025), UINT16_C(49725), UINT16_C( 8197) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vpaddq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3816938315), UINT32_C(2809583990), UINT32_C(3278927444), UINT32_C(3055051205) },
      { UINT32_C(1596983728), UINT32_C( 356509708), UINT32_C(2588010953), UINT32_C( 637551579) },
      { UINT32_C(2331555009), UINT32_C(2039011353), UINT32_C(1953493436), UINT32_C(3225562532) } },
    { { UINT32_C(2500428063), UINT32_C(2939977819), UINT32_C(3144854774), UINT32_C(3195112206) },
      { UINT32_C(2686362004), UINT32_C(1404394889), UINT32_C( 569243206), UINT32_C(1497951802) },
      { UINT32_C(1145438586), UINT32_C(2044999684), UINT32_C(4090756893), UINT32_C(2067195008) } },
    { { UINT32_C(3404616047), UINT32_C(3346672337), UINT32_C(3833785558), UINT32_C( 195294071) },
      { UINT32_C( 514572693), UINT32_C(1685152030), UINT32_C(2441502551), UINT32_C(3169504845) },
      { UINT32_C(2456321088), UINT32_C(4029079629), UINT32_C(2199724723), UINT32_C(1316040100) } },
    { { UINT32_C(4052211743), UINT32_C(3652714754), UINT32_C(1706900461), UINT32_C(3278921774) },
      { UINT32_C(1071782945), UINT32_C(3567539069), UINT32_C(4284885682), UINT32_C( 398217464) },
      { UINT32_C(3409959201), UINT32_C( 690854939), UINT32_C( 344354718), UINT32_C( 388135850) } },
    { { UINT32_C( 721961769), UINT32_C( 822395204), UINT32_C( 714523388), UINT32_C(1156450082) },
      { UINT32_C(2692993059), UINT32_C(3597936419), UINT32_C(1238751825), UINT32_C(1415680299) },
      { UINT32_C(1544356973), UINT32_C(1870973470), UINT32_C(1995962182), UINT32_C(2654432124) } },
    { { UINT32_C( 411003348), UINT32_C( 642417706), UINT32_C(1750196294), UINT32_C( 179060711) },
      { UINT32_C( 850014223), UINT32_C(2835881815), UINT32_C( 619896569), UINT32_C(1148736367) },
      { UINT32_C(1053421054), UINT32_C(1929257005), UINT32_C(3685896038), UINT32_C(1768632936) } },
    { { UINT32_C(3881629885), UINT32_C(3255740028), UINT32_C(1848270727), UINT32_C(2910443422) },
      { UINT32_C(1591681799), UINT32_C(1007151170), UINT32_C( 895548102), UINT32_C( 175757645) },
      { UINT32_C(2842402617), UINT32_C( 463746853), UINT32_C(2598832969), UINT32_C(1071305747) } },
    { { UINT32_C(1307760337), UINT32_C(  51314812), UINT32_C(4252121439), UINT32_C( 397077264) },
      { UINT32_C(1366722830), UINT32_C( 932019569), UINT32_C(3312315767), UINT32_C(2546984646) },
      { UINT32_C(1359075149), UINT32_C( 354231407), UINT32_C(2298742399), UINT32_C(1564333117) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vpaddq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddq_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(15513978132590441720), UINT64_C(18412383231435127934) },
      { UINT64_C(15173798401319091866), UINT64_C( 7554486488907008214) },
      { UINT64_C(15479617290316018038), UINT64_C( 4281540816516548464) } },
    { { UINT64_C( 5179969466727272737), UINT64_C( 8407314346400738990) },
      { UINT64_C(12652720048107532165), UINT64_C( 8114699618393940678) },
      { UINT64_C(13587283813128011727), UINT64_C( 2320675592791921227) } },
    { { UINT64_C(16381383177064366917), UINT64_C(16472263491434092619) },
      { UINT64_C(14299563238393217771), UINT64_C( 5432072351392715171) },
      { UINT64_C(14406902594788907920), UINT64_C( 1284891516076381326) } },
    { { UINT64_C( 9652814040289369564), UINT64_C(12432824220313617735) },
      { UINT64_C( 1769037749118055622), UINT64_C(18231816079301838771) },
      { UINT64_C( 3638894186893435683), UINT64_C( 1554109754710342777) } },
    { { UINT64_C( 6055094155079540041), UINT64_C(13544723167905034890) },
      { UINT64_C(18322346746262415545), UINT64_C(  410596935221072021) },
      { UINT64_C( 1153073249275023315), UINT64_C(  286199607773935950) } },
    { { UINT64_C( 5799106650900578584), UINT64_C(13038928049068537154) },
      { UINT64_C( 1676510600800400891), UINT64_C(14860611816019327865) },
      { UINT64_C(  391290626259564122), UINT64_C(16537122416819728756) } },
    { { UINT64_C(10905306329890735169), UINT64_C( 9336457387018547939) },
      { UINT64_C( 1644108111038346295), UINT64_C( 6884746120955469318) },
      { UINT64_C( 1795019643199731492), UINT64_C( 8528854231993815613) } },
    { { UINT64_C(15003669511904067404), UINT64_C(   51580054159558319) },
      { UINT64_C(10405158514773884595), UINT64_C( 9775019265358672682) },
      { UINT64_C(15055249566063625723), UINT64_C( 1733433706423005661) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vpaddq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t r;
  } test_vec[] = {
    { {  INT64_C( 7807378621338587649),  INT64_C( 1979464258218010472) },
      -INT64_C( 8659901194152953495) },
    { { -INT64_C(  469042846506888056),  INT64_C( 3526121899697758237) },
       INT64_C( 3057079053190870181) },
    { { -INT64_C( 7509699402956026401),  INT64_C( 8229030801227608791) },
       INT64_C(  719331398271582390) },
    { {  INT64_C( 8445680144921179959), -INT64_C( 7542148702153512203) },
       INT64_C(  903531442767667756) },
    { {  INT64_C( 3637145276914019252), -INT64_C(   32793178687249362) },
       INT64_C( 3604352098226769890) },
    { {  INT64_C( 3315617138864759605), -INT64_C( 7698437500748760357) },
      -INT64_C( 4382820361884000752) },
    { {  INT64_C(  531690671119539666),  INT64_C( 6781484431495441238) },
       INT64_C( 7313175102614980904) },
    { { -INT64_C( 6685892954362718257),  INT64_C(  171241444717463785) },
      -INT64_C( 6514651509645254472) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    int64_t r = simde_vpaddd_s64(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    int64_t r = simde_vpaddd_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpaddd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t r;
  } test_vec[] = {
    { { UINT64_C( 4499407304093009580), UINT64_C(16703389208686402028) },
      UINT64_C( 2756052439069859992) },
    { { UINT64_C( 4283292125784539984), UINT64_C(16039886950525023914) },
      UINT64_C( 1876435002600012282) },
    { { UINT64_C(16392817832545147942), UINT64_C(  178272279460533909) },
      UINT64_C(16571090112005681851) },
    { { UINT64_C( 1195157480093259484), UINT64_C( 6112647135401021123) },
      UINT64_C( 7307804615494280607) },
    { { UINT64_C(17307917600836312920), UINT64_C(17518434202205470057) },
      UINT64_C(16379607729332231361) },
    { { UINT64_C( 9982199743952894226), UINT64_C( 4500597849519581939) },
      UINT64_C(14482797593472476165) },
    { { UINT64_C( 9727703847384451508), UINT64_C(10342444515853435517) },
      UINT64_C( 1623404289528335409) },
    { { UINT64_C(12594754767769032311), UINT64_C( 5917242409561836025) },
      UINT64_C(   65253103621316720) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    uint64_t r = simde_vpaddd_u64(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    uint64_t r = simde_vpaddd_u64(a);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpaddd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   734.68), SIMDE_FLOAT64_C(     0.95) },
      SIMDE_FLOAT64_C(   735.63) },
    { { SIMDE_FLOAT64_C(  -409.20), SIMDE_FLOAT64_C(  -823.56) },
      SIMDE_FLOAT64_C( -1232.76) },
    { { SIMDE_FLOAT64_C(   816.17), SIMDE_FLOAT64_C(   848.79) },
      SIMDE_FLOAT64_C(  1664.96) },
    { { SIMDE_FLOAT64_C(  -343.37), SIMDE_FLOAT64_C(   338.43) },
      SIMDE_FLOAT64_C(    -4.94) },
    { { SIMDE_FLOAT64_C(   575.98), SIMDE_FLOAT64_C(   110.52) },
      SIMDE_FLOAT64_C(   686.50) },
    { { SIMDE_FLOAT64_C(  -137.98), SIMDE_FLOAT64_C(   461.14) },
      SIMDE_FLOAT64_C(   323.16) },
    { { SIMDE_FLOAT64_C(   222.72), SIMDE_FLOAT64_C(   206.53) },
      SIMDE_FLOAT64_C(   429.25) },
    { { SIMDE_FLOAT64_C(   495.96), SIMDE_FLOAT64_C(   343.99) },
      SIMDE_FLOAT64_C(   839.95) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vpaddd_f64(a);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64_t r = simde_vpaddd_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadds_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -699.29), SIMDE_FLOAT32_C(   413.96) },
     SIMDE_FLOAT32_C(  -285.33) },
   { { SIMDE_FLOAT32_C(  -422.06), SIMDE_FLOAT32_C(   994.22) },
     SIMDE_FLOAT32_C(   572.16) },
   { { SIMDE_FLOAT32_C(  -850.43), SIMDE_FLOAT32_C(   944.36) },
     SIMDE_FLOAT32_C(    93.93) },
   { { SIMDE_FLOAT32_C(   451.20), SIMDE_FLOAT32_C(   627.33) },
     SIMDE_FLOAT32_C(  1078.53) },
   { { SIMDE_FLOAT32_C(   638.52), SIMDE_FLOAT32_C(   775.57) },
     SIMDE_FLOAT32_C(  1414.09) },
   { { SIMDE_FLOAT32_C(   409.26), SIMDE_FLOAT32_C(   998.59) },
     SIMDE_FLOAT32_C(  1407.85) },
   { { SIMDE_FLOAT32_C(    -9.19), SIMDE_FLOAT32_C(  -725.56) },
     SIMDE_FLOAT32_C(  -734.75) },
   { { SIMDE_FLOAT32_C(   224.23), SIMDE_FLOAT32_C(  -650.86) },
     SIMDE_FLOAT32_C(  -426.63) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vpadds_f32(a);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vpadds_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpadd_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadd_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadd_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadd_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadd_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vpaddd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddd_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadds_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
