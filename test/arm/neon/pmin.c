#define SIMDE_TEST_ARM_NEON_INSN pmin

#include "test-neon.h"
#include "../../../simde/arm/neon/pmin.h"

static int
test_simde_vpmin_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -823.14), SIMDE_FLOAT32_C(   128.93) },
      { SIMDE_FLOAT32_C(   -79.23), SIMDE_FLOAT32_C(   181.88) },
      { SIMDE_FLOAT32_C(  -823.14), SIMDE_FLOAT32_C(   -79.23) } },
    { { SIMDE_FLOAT32_C(   342.60), SIMDE_FLOAT32_C(   371.59) },
      { SIMDE_FLOAT32_C(   649.79), SIMDE_FLOAT32_C(   595.53) },
      { SIMDE_FLOAT32_C(   342.60), SIMDE_FLOAT32_C(   595.53) } },
    { { SIMDE_FLOAT32_C(   270.06), SIMDE_FLOAT32_C(  -842.97) },
      { SIMDE_FLOAT32_C(  -961.22), SIMDE_FLOAT32_C(  -328.85) },
      { SIMDE_FLOAT32_C(  -842.97), SIMDE_FLOAT32_C(  -961.22) } },
    { { SIMDE_FLOAT32_C(  -201.57), SIMDE_FLOAT32_C(   793.30) },
      { SIMDE_FLOAT32_C(  -461.86), SIMDE_FLOAT32_C(  -809.27) },
      { SIMDE_FLOAT32_C(  -201.57), SIMDE_FLOAT32_C(  -809.27) } },
    { { SIMDE_FLOAT32_C(  -247.56), SIMDE_FLOAT32_C(  -943.60) },
      { SIMDE_FLOAT32_C(   440.83), SIMDE_FLOAT32_C(   190.31) },
      { SIMDE_FLOAT32_C(  -943.60), SIMDE_FLOAT32_C(   190.31) } },
    { { SIMDE_FLOAT32_C(  -830.78), SIMDE_FLOAT32_C(  -101.36) },
      { SIMDE_FLOAT32_C(  -658.42), SIMDE_FLOAT32_C(   551.40) },
      { SIMDE_FLOAT32_C(  -830.78), SIMDE_FLOAT32_C(  -658.42) } },
    { { SIMDE_FLOAT32_C(  -949.01), SIMDE_FLOAT32_C(  -839.90) },
      { SIMDE_FLOAT32_C(   498.39), SIMDE_FLOAT32_C(   411.31) },
      { SIMDE_FLOAT32_C(  -949.01), SIMDE_FLOAT32_C(   411.31) } },
    { { SIMDE_FLOAT32_C(   115.69), SIMDE_FLOAT32_C(  -563.88) },
      { SIMDE_FLOAT32_C(    32.11), SIMDE_FLOAT32_C(   292.55) },
      { SIMDE_FLOAT32_C(  -563.88), SIMDE_FLOAT32_C(    32.11) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vpmin_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpmin_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C( 103), -INT8_C(  58),  INT8_C( 105),  INT8_C( 115),  INT8_C(  81), -INT8_C(   1),  INT8_C(  74), -INT8_C(  20) },
      {  INT8_C(  41), -INT8_C(  51), -INT8_C(  70), -INT8_C(  85), -INT8_C(  14), -INT8_C(   5), -INT8_C(  29),  INT8_C(  70) },
      { -INT8_C(  58),  INT8_C( 105), -INT8_C(   1), -INT8_C(  20), -INT8_C(  51), -INT8_C(  85), -INT8_C(  14), -INT8_C(  29) } },
    { {  INT8_C( 124), -INT8_C(  62),  INT8_C(  84), -INT8_C(   8),  INT8_C(  27), -INT8_C(  24), -INT8_C(  25), -INT8_C( 115) },
      {  INT8_C( 118),  INT8_C(  90),  INT8_C(  46),  INT8_C(  99),  INT8_C(  51), -INT8_C(  97), -INT8_C(  55), -INT8_C( 102) },
      { -INT8_C(  62), -INT8_C(   8), -INT8_C(  24), -INT8_C( 115),  INT8_C(  90),  INT8_C(  46), -INT8_C(  97), -INT8_C( 102) } },
    { {  INT8_C( 102),  INT8_C(  50),  INT8_C(  13), -INT8_C(  73),  INT8_C(  49),  INT8_C(  88), -INT8_C(  93),  INT8_C(  90) },
      {  INT8_C(  37),  INT8_C(  93),  INT8_C(   5),  INT8_C(  23),  INT8_C(  88), -INT8_C(  23),  INT8_C(  94), -INT8_C(  44) },
      {  INT8_C(  50), -INT8_C(  73),  INT8_C(  49), -INT8_C(  93),  INT8_C(  37),  INT8_C(   5), -INT8_C(  23), -INT8_C(  44) } },
    { { -INT8_C(  85), -INT8_C(  78), -INT8_C(  51), -INT8_C(  58), -INT8_C( 101), -INT8_C(  76),  INT8_C(  84),  INT8_C(  17) },
      {  INT8_C(  14), -INT8_C( 126),  INT8_C( 116),  INT8_C(  65),  INT8_C(  33),  INT8_C(  61), -INT8_C(  36), -INT8_C( 121) },
      { -INT8_C(  85), -INT8_C(  58), -INT8_C( 101),  INT8_C(  17), -INT8_C( 126),  INT8_C(  65),  INT8_C(  33), -INT8_C( 121) } },
    { {  INT8_C( 112), -INT8_C(  23),  INT8_C(  62), -INT8_C(  95),  INT8_C(  65), -INT8_C(  31), -INT8_C(   4),  INT8_C( 103) },
      {  INT8_C(  62),  INT8_C(   1),  INT8_C( 126), -INT8_C( 105), -INT8_C(  22), -INT8_C(  36),  INT8_C( 107), -INT8_C( 106) },
      { -INT8_C(  23), -INT8_C(  95), -INT8_C(  31), -INT8_C(   4),  INT8_C(   1), -INT8_C( 105), -INT8_C(  36), -INT8_C( 106) } },
    { { -INT8_C( 113),  INT8_C(  56),  INT8_C(  92),  INT8_C(  42), -INT8_C(  20), -INT8_C(  80),  INT8_C(  59), -INT8_C(   5) },
      {  INT8_C(  50), -INT8_C(  81),  INT8_C(  60),  INT8_C(  84), -INT8_C(  20),  INT8_C(  24), -INT8_C(  37),  INT8_C(  92) },
      { -INT8_C( 113),  INT8_C(  42), -INT8_C(  80), -INT8_C(   5), -INT8_C(  81),  INT8_C(  60), -INT8_C(  20), -INT8_C(  37) } },
    { {  INT8_C(   2),  INT8_C(  26), -INT8_C(   2),  INT8_C(  67), -INT8_C(   5), -INT8_C(   6), -INT8_C(  86),  INT8_C(  58) },
      { -INT8_C(   5),  INT8_C(  41), -INT8_C(  47), -INT8_C(  26),  INT8_C(   5),  INT8_C(  60),  INT8_C( 124), -INT8_C( 108) },
      {  INT8_C(   2), -INT8_C(   2), -INT8_C(   6), -INT8_C(  86), -INT8_C(   5), -INT8_C(  47),  INT8_C(   5), -INT8_C( 108) } },
    { {  INT8_C( 117), -INT8_C(  40), -INT8_C(  66),  INT8_C(  97), -INT8_C( 119), -INT8_C(   7),  INT8_C(  92), -INT8_C(  69) },
      { -INT8_C(  88), -INT8_C( 103),  INT8_C(  15), -INT8_C( 107), -INT8_C(  79), -INT8_C(  21), -INT8_C(  15), -INT8_C(  77) },
      { -INT8_C(  40), -INT8_C(  66), -INT8_C( 119), -INT8_C(  69), -INT8_C( 103), -INT8_C( 107), -INT8_C(  79), -INT8_C(  77) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vpmin_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmin_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 14745),  INT16_C( 29545), -INT16_C(   175), -INT16_C(  5046) },
      { -INT16_C( 13015), -INT16_C( 21574), -INT16_C(  1038),  INT16_C( 18147) },
      { -INT16_C( 14745), -INT16_C(  5046), -INT16_C( 21574), -INT16_C(  1038) } },
    { { -INT16_C( 15748), -INT16_C(  1964), -INT16_C(  6117), -INT16_C( 29209) },
      {  INT16_C( 23158),  INT16_C( 25390), -INT16_C( 24781), -INT16_C( 25911) },
      { -INT16_C( 15748), -INT16_C( 29209),  INT16_C( 23158), -INT16_C( 25911) } },
    { {  INT16_C( 12902), -INT16_C( 18675),  INT16_C( 22577),  INT16_C( 23203) },
      {  INT16_C( 23845),  INT16_C(  5893), -INT16_C(  5800), -INT16_C( 11170) },
      { -INT16_C( 18675),  INT16_C( 22577),  INT16_C(  5893), -INT16_C( 11170) } },
    { { -INT16_C( 19797), -INT16_C( 14643), -INT16_C( 19301),  INT16_C(  4436) },
      { -INT16_C( 32242),  INT16_C( 16756),  INT16_C( 15649), -INT16_C( 30756) },
      { -INT16_C( 19797), -INT16_C( 19301), -INT16_C( 32242), -INT16_C( 30756) } },
    { { -INT16_C(  5776), -INT16_C( 24258), -INT16_C(  7871),  INT16_C( 26620) },
      {  INT16_C(   318), -INT16_C( 26754), -INT16_C(  8982), -INT16_C( 27029) },
      { -INT16_C( 24258), -INT16_C(  7871), -INT16_C( 26754), -INT16_C( 27029) } },
    { {  INT16_C( 14479),  INT16_C( 10844), -INT16_C( 20244), -INT16_C(  1221) },
      { -INT16_C( 20686),  INT16_C( 21564),  INT16_C(  6380),  INT16_C( 23771) },
      {  INT16_C( 10844), -INT16_C( 20244), -INT16_C( 20686),  INT16_C(  6380) } },
    { {  INT16_C(  6658),  INT16_C( 17406), -INT16_C(  1285),  INT16_C( 15018) },
      {  INT16_C( 10747), -INT16_C(  6447),  INT16_C( 15365), -INT16_C( 27524) },
      {  INT16_C(  6658), -INT16_C(  1285), -INT16_C(  6447), -INT16_C( 27524) } },
    { { -INT16_C( 10123),  INT16_C( 25022), -INT16_C(  1655), -INT16_C( 17572) },
      { -INT16_C( 26200), -INT16_C( 27377), -INT16_C(  5199), -INT16_C( 19471) },
      { -INT16_C( 10123), -INT16_C( 17572), -INT16_C( 27377), -INT16_C( 19471) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vpmin_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmin_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1936311911), -INT32_C(   330629295) },
      { -INT32_C(  1413821143),  INT32_C(  1189346290) },
      { -INT32_C(   330629295), -INT32_C(  1413821143) } },
    { { -INT32_C(   128662916), -INT32_C(  1914181605) },
      {  INT32_C(  1663982198), -INT32_C(  1698062541) },
      { -INT32_C(  1914181605), -INT32_C(  1698062541) } },
    { { -INT32_C(  1223871898),  INT32_C(  1520654385) },
      {  INT32_C(   386227493), -INT32_C(   731977384) },
      { -INT32_C(  1223871898), -INT32_C(   731977384) } },
    { { -INT32_C(   959597909),  INT32_C(   290763931) },
      {  INT32_C(  1098154510), -INT32_C(  2015609567) },
      { -INT32_C(   959597909), -INT32_C(  2015609567) } },
    { { -INT32_C(  1589712528),  INT32_C(  1744625985) },
      { -INT32_C(  1753349826), -INT32_C(  1771315990) },
      { -INT32_C(  1589712528), -INT32_C(  1771315990) } },
    { {  INT32_C(   710686863), -INT32_C(    79974164) },
      {  INT32_C(  1413263154),  INT32_C(  1557862636) },
      { -INT32_C(    79974164),  INT32_C(  1413263154) } },
    { {  INT32_C(  1140726274),  INT32_C(   984283899) },
      { -INT32_C(   422499845), -INT32_C(  1803797499) },
      {  INT32_C(   984283899), -INT32_C(  1803797499) } },
    { {  INT32_C(  1639897205), -INT32_C(  1151534711) },
      { -INT32_C(  1794139736), -INT32_C(  1275991119) },
      { -INT32_C(  1151534711), -INT32_C(  1794139736) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vpmin_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmin_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(103), UINT8_C(198), UINT8_C(105), UINT8_C(115), UINT8_C( 81),    UINT8_MAX, UINT8_C( 74), UINT8_C(236) },
      { UINT8_C( 41), UINT8_C(205), UINT8_C(186), UINT8_C(171), UINT8_C(242), UINT8_C(251), UINT8_C(227), UINT8_C( 70) },
      { UINT8_C(103), UINT8_C(105), UINT8_C( 81), UINT8_C( 74), UINT8_C( 41), UINT8_C(171), UINT8_C(242), UINT8_C( 70) } },
    { { UINT8_C(124), UINT8_C(194), UINT8_C( 84), UINT8_C(248), UINT8_C( 27), UINT8_C(232), UINT8_C(231), UINT8_C(141) },
      { UINT8_C(118), UINT8_C( 90), UINT8_C( 46), UINT8_C( 99), UINT8_C( 51), UINT8_C(159), UINT8_C(201), UINT8_C(154) },
      { UINT8_C(124), UINT8_C( 84), UINT8_C( 27), UINT8_C(141), UINT8_C( 90), UINT8_C( 46), UINT8_C( 51), UINT8_C(154) } },
    { { UINT8_C(102), UINT8_C( 50), UINT8_C( 13), UINT8_C(183), UINT8_C( 49), UINT8_C( 88), UINT8_C(163), UINT8_C( 90) },
      { UINT8_C( 37), UINT8_C( 93), UINT8_C(  5), UINT8_C( 23), UINT8_C( 88), UINT8_C(233), UINT8_C( 94), UINT8_C(212) },
      { UINT8_C( 50), UINT8_C( 13), UINT8_C( 49), UINT8_C( 90), UINT8_C( 37), UINT8_C(  5), UINT8_C( 88), UINT8_C( 94) } },
    { { UINT8_C(171), UINT8_C(178), UINT8_C(205), UINT8_C(198), UINT8_C(155), UINT8_C(180), UINT8_C( 84), UINT8_C( 17) },
      { UINT8_C( 14), UINT8_C(130), UINT8_C(116), UINT8_C( 65), UINT8_C( 33), UINT8_C( 61), UINT8_C(220), UINT8_C(135) },
      { UINT8_C(171), UINT8_C(198), UINT8_C(155), UINT8_C( 17), UINT8_C( 14), UINT8_C( 65), UINT8_C( 33), UINT8_C(135) } },
    { { UINT8_C(112), UINT8_C(233), UINT8_C( 62), UINT8_C(161), UINT8_C( 65), UINT8_C(225), UINT8_C(252), UINT8_C(103) },
      { UINT8_C( 62), UINT8_C(  1), UINT8_C(126), UINT8_C(151), UINT8_C(234), UINT8_C(220), UINT8_C(107), UINT8_C(150) },
      { UINT8_C(112), UINT8_C( 62), UINT8_C( 65), UINT8_C(103), UINT8_C(  1), UINT8_C(126), UINT8_C(220), UINT8_C(107) } },
    { { UINT8_C(143), UINT8_C( 56), UINT8_C( 92), UINT8_C( 42), UINT8_C(236), UINT8_C(176), UINT8_C( 59), UINT8_C(251) },
      { UINT8_C( 50), UINT8_C(175), UINT8_C( 60), UINT8_C( 84), UINT8_C(236), UINT8_C( 24), UINT8_C(219), UINT8_C( 92) },
      { UINT8_C( 56), UINT8_C( 42), UINT8_C(176), UINT8_C( 59), UINT8_C( 50), UINT8_C( 60), UINT8_C( 24), UINT8_C( 92) } },
    { { UINT8_C(  2), UINT8_C( 26), UINT8_C(254), UINT8_C( 67), UINT8_C(251), UINT8_C(250), UINT8_C(170), UINT8_C( 58) },
      { UINT8_C(251), UINT8_C( 41), UINT8_C(209), UINT8_C(230), UINT8_C(  5), UINT8_C( 60), UINT8_C(124), UINT8_C(148) },
      { UINT8_C(  2), UINT8_C( 67), UINT8_C(250), UINT8_C( 58), UINT8_C( 41), UINT8_C(209), UINT8_C(  5), UINT8_C(124) } },
    { { UINT8_C(117), UINT8_C(216), UINT8_C(190), UINT8_C( 97), UINT8_C(137), UINT8_C(249), UINT8_C( 92), UINT8_C(187) },
      { UINT8_C(168), UINT8_C(153), UINT8_C( 15), UINT8_C(149), UINT8_C(177), UINT8_C(235), UINT8_C(241), UINT8_C(179) },
      { UINT8_C(117), UINT8_C( 97), UINT8_C(137), UINT8_C( 92), UINT8_C(153), UINT8_C( 15), UINT8_C(177), UINT8_C(179) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vpmin_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmin_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(50791), UINT16_C(29545), UINT16_C(65361), UINT16_C(60490) },
      { UINT16_C(52521), UINT16_C(43962), UINT16_C(64498), UINT16_C(18147) },
      { UINT16_C(29545), UINT16_C(60490), UINT16_C(43962), UINT16_C(18147) } },
    { { UINT16_C(49788), UINT16_C(63572), UINT16_C(59419), UINT16_C(36327) },
      { UINT16_C(23158), UINT16_C(25390), UINT16_C(40755), UINT16_C(39625) },
      { UINT16_C(49788), UINT16_C(36327), UINT16_C(23158), UINT16_C(39625) } },
    { { UINT16_C(12902), UINT16_C(46861), UINT16_C(22577), UINT16_C(23203) },
      { UINT16_C(23845), UINT16_C( 5893), UINT16_C(59736), UINT16_C(54366) },
      { UINT16_C(12902), UINT16_C(22577), UINT16_C( 5893), UINT16_C(54366) } },
    { { UINT16_C(45739), UINT16_C(50893), UINT16_C(46235), UINT16_C( 4436) },
      { UINT16_C(33294), UINT16_C(16756), UINT16_C(15649), UINT16_C(34780) },
      { UINT16_C(45739), UINT16_C( 4436), UINT16_C(16756), UINT16_C(15649) } },
    { { UINT16_C(59760), UINT16_C(41278), UINT16_C(57665), UINT16_C(26620) },
      { UINT16_C(  318), UINT16_C(38782), UINT16_C(56554), UINT16_C(38507) },
      { UINT16_C(41278), UINT16_C(26620), UINT16_C(  318), UINT16_C(38507) } },
    { { UINT16_C(14479), UINT16_C(10844), UINT16_C(45292), UINT16_C(64315) },
      { UINT16_C(44850), UINT16_C(21564), UINT16_C( 6380), UINT16_C(23771) },
      { UINT16_C(10844), UINT16_C(45292), UINT16_C(21564), UINT16_C( 6380) } },
    { { UINT16_C( 6658), UINT16_C(17406), UINT16_C(64251), UINT16_C(15018) },
      { UINT16_C(10747), UINT16_C(59089), UINT16_C(15365), UINT16_C(38012) },
      { UINT16_C( 6658), UINT16_C(15018), UINT16_C(10747), UINT16_C(15365) } },
    { { UINT16_C(55413), UINT16_C(25022), UINT16_C(63881), UINT16_C(47964) },
      { UINT16_C(39336), UINT16_C(38159), UINT16_C(60337), UINT16_C(46065) },
      { UINT16_C(25022), UINT16_C(47964), UINT16_C(38159), UINT16_C(46065) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vpmin_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmin_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1936311911), UINT32_C(3964338001) },
      { UINT32_C(2881146153), UINT32_C(1189346290) },
      { UINT32_C(1936311911), UINT32_C(1189346290) } },
    { { UINT32_C(4166304380), UINT32_C(2380785691) },
      { UINT32_C(1663982198), UINT32_C(2596904755) },
      { UINT32_C(2380785691), UINT32_C(1663982198) } },
    { { UINT32_C(3071095398), UINT32_C(1520654385) },
      { UINT32_C( 386227493), UINT32_C(3562989912) },
      { UINT32_C(1520654385), UINT32_C( 386227493) } },
    { { UINT32_C(3335369387), UINT32_C( 290763931) },
      { UINT32_C(1098154510), UINT32_C(2279357729) },
      { UINT32_C( 290763931), UINT32_C(1098154510) } },
    { { UINT32_C(2705254768), UINT32_C(1744625985) },
      { UINT32_C(2541617470), UINT32_C(2523651306) },
      { UINT32_C(1744625985), UINT32_C(2523651306) } },
    { { UINT32_C( 710686863), UINT32_C(4214993132) },
      { UINT32_C(1413263154), UINT32_C(1557862636) },
      { UINT32_C( 710686863), UINT32_C(1413263154) } },
    { { UINT32_C(1140726274), UINT32_C( 984283899) },
      { UINT32_C(3872467451), UINT32_C(2491169797) },
      { UINT32_C( 984283899), UINT32_C(2491169797) } },
    { { UINT32_C(1639897205), UINT32_C(3143432585) },
      { UINT32_C(2500827560), UINT32_C(3018976177) },
      { UINT32_C(1639897205), UINT32_C(2500827560) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vpmin_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpminq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   680.38), SIMDE_FLOAT32_C(  -211.23), SIMDE_FLOAT32_C(   566.20), SIMDE_FLOAT32_C(   596.88) },
      { SIMDE_FLOAT32_C(   823.29), SIMDE_FLOAT32_C(  -604.90), SIMDE_FLOAT32_C(  -329.55), SIMDE_FLOAT32_C(   536.46) },
      { SIMDE_FLOAT32_C(  -211.23), SIMDE_FLOAT32_C(   566.20), SIMDE_FLOAT32_C(  -604.90), SIMDE_FLOAT32_C(  -329.55) } },
    { { SIMDE_FLOAT32_C(  -444.45), SIMDE_FLOAT32_C(   107.94), SIMDE_FLOAT32_C(   -45.21), SIMDE_FLOAT32_C(   257.74) },
      { SIMDE_FLOAT32_C(  -270.43), SIMDE_FLOAT32_C(    26.80), SIMDE_FLOAT32_C(   904.46), SIMDE_FLOAT32_C(   832.39) },
      { SIMDE_FLOAT32_C(  -444.45), SIMDE_FLOAT32_C(   -45.21), SIMDE_FLOAT32_C(  -270.43), SIMDE_FLOAT32_C(   832.39) } },
    { { SIMDE_FLOAT32_C(   271.42), SIMDE_FLOAT32_C(   434.59), SIMDE_FLOAT32_C(  -716.79), SIMDE_FLOAT32_C(   213.94) },
      { SIMDE_FLOAT32_C(  -967.40), SIMDE_FLOAT32_C(  -514.23), SIMDE_FLOAT32_C(  -725.54), SIMDE_FLOAT32_C(   608.35) },
      { SIMDE_FLOAT32_C(   271.42), SIMDE_FLOAT32_C(  -716.79), SIMDE_FLOAT32_C(  -967.40), SIMDE_FLOAT32_C(  -725.54) } },
    { { SIMDE_FLOAT32_C(  -686.64), SIMDE_FLOAT32_C(  -198.11), SIMDE_FLOAT32_C(  -740.42), SIMDE_FLOAT32_C(  -782.38) },
      { SIMDE_FLOAT32_C(   997.85), SIMDE_FLOAT32_C(  -563.49), SIMDE_FLOAT32_C(    25.86), SIMDE_FLOAT32_C(   678.22) },
      { SIMDE_FLOAT32_C(  -686.64), SIMDE_FLOAT32_C(  -782.38), SIMDE_FLOAT32_C(  -563.49), SIMDE_FLOAT32_C(    25.86) } },
    { { SIMDE_FLOAT32_C(   225.28), SIMDE_FLOAT32_C(  -407.94), SIMDE_FLOAT32_C(   275.10), SIMDE_FLOAT32_C(    48.57) },
      { SIMDE_FLOAT32_C(   -12.83), SIMDE_FLOAT32_C(   945.55), SIMDE_FLOAT32_C(  -414.97), SIMDE_FLOAT32_C(   542.72) },
      { SIMDE_FLOAT32_C(  -407.94), SIMDE_FLOAT32_C(    48.57), SIMDE_FLOAT32_C(   -12.83), SIMDE_FLOAT32_C(  -414.97) } },
    { { SIMDE_FLOAT32_C(    53.49), SIMDE_FLOAT32_C(   539.83), SIMDE_FLOAT32_C(  -199.54), SIMDE_FLOAT32_C(   783.06) },
      { SIMDE_FLOAT32_C(  -433.37), SIMDE_FLOAT32_C(  -295.08), SIMDE_FLOAT32_C(   615.45), SIMDE_FLOAT32_C(   838.05) },
      { SIMDE_FLOAT32_C(    53.49), SIMDE_FLOAT32_C(  -199.54), SIMDE_FLOAT32_C(  -433.37), SIMDE_FLOAT32_C(   615.45) } },
    { { SIMDE_FLOAT32_C(  -860.49), SIMDE_FLOAT32_C(   898.65), SIMDE_FLOAT32_C(    51.99), SIMDE_FLOAT32_C(  -827.89) },
      { SIMDE_FLOAT32_C(  -615.57), SIMDE_FLOAT32_C(   326.45), SIMDE_FLOAT32_C(   780.47), SIMDE_FLOAT32_C(  -302.21) },
      { SIMDE_FLOAT32_C(  -860.49), SIMDE_FLOAT32_C(  -827.89), SIMDE_FLOAT32_C(  -615.57), SIMDE_FLOAT32_C(  -302.21) } },
    { { SIMDE_FLOAT32_C(  -871.66), SIMDE_FLOAT32_C(  -959.95), SIMDE_FLOAT32_C(   -84.60), SIMDE_FLOAT32_C(  -873.81) },
      { SIMDE_FLOAT32_C(  -523.44), SIMDE_FLOAT32_C(   941.27), SIMDE_FLOAT32_C(   804.42), SIMDE_FLOAT32_C(   701.84) },
      { SIMDE_FLOAT32_C(  -959.95), SIMDE_FLOAT32_C(  -873.81), SIMDE_FLOAT32_C(  -523.44), SIMDE_FLOAT32_C(   701.84) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vpminq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpminq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   680.38), SIMDE_FLOAT64_C(  -211.23) },
      { SIMDE_FLOAT64_C(   566.20), SIMDE_FLOAT64_C(   596.88) },
      { SIMDE_FLOAT64_C(  -211.23), SIMDE_FLOAT64_C(   566.20) } },
    { { SIMDE_FLOAT64_C(   823.29), SIMDE_FLOAT64_C(  -604.90) },
      { SIMDE_FLOAT64_C(  -329.55), SIMDE_FLOAT64_C(   536.46) },
      { SIMDE_FLOAT64_C(  -604.90), SIMDE_FLOAT64_C(  -329.55) } },
    { { SIMDE_FLOAT64_C(  -444.45), SIMDE_FLOAT64_C(   107.94) },
      { SIMDE_FLOAT64_C(   -45.21), SIMDE_FLOAT64_C(   257.74) },
      { SIMDE_FLOAT64_C(  -444.45), SIMDE_FLOAT64_C(   -45.21) } },
    { { SIMDE_FLOAT64_C(  -270.43), SIMDE_FLOAT64_C(    26.80) },
      { SIMDE_FLOAT64_C(   904.46), SIMDE_FLOAT64_C(   832.39) },
      { SIMDE_FLOAT64_C(  -270.43), SIMDE_FLOAT64_C(   832.39) } },
    { { SIMDE_FLOAT64_C(   271.42), SIMDE_FLOAT64_C(   434.59) },
      { SIMDE_FLOAT64_C(  -716.79), SIMDE_FLOAT64_C(   213.94) },
      { SIMDE_FLOAT64_C(   271.42), SIMDE_FLOAT64_C(  -716.79) } },
    { { SIMDE_FLOAT64_C(  -967.40), SIMDE_FLOAT64_C(  -514.23) },
      { SIMDE_FLOAT64_C(  -725.54), SIMDE_FLOAT64_C(   608.35) },
      { SIMDE_FLOAT64_C(  -967.40), SIMDE_FLOAT64_C(  -725.54) } },
    { { SIMDE_FLOAT64_C(  -686.64), SIMDE_FLOAT64_C(  -198.11) },
      { SIMDE_FLOAT64_C(  -740.42), SIMDE_FLOAT64_C(  -782.38) },
      { SIMDE_FLOAT64_C(  -686.64), SIMDE_FLOAT64_C(  -782.38) } },
    { { SIMDE_FLOAT64_C(   997.85), SIMDE_FLOAT64_C(  -563.49) },
      { SIMDE_FLOAT64_C(    25.86), SIMDE_FLOAT64_C(   678.22) },
      { SIMDE_FLOAT64_C(  -563.49), SIMDE_FLOAT64_C(    25.86) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vpminq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpminq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C( 103), -INT8_C(  58),  INT8_C( 105),  INT8_C( 115),  INT8_C(  81), -INT8_C(   1),  INT8_C(  74), -INT8_C(  20),
         INT8_C(  41), -INT8_C(  51), -INT8_C(  70), -INT8_C(  85), -INT8_C(  14), -INT8_C(   5), -INT8_C(  29),  INT8_C(  70) },
      {  INT8_C( 124), -INT8_C(  62),  INT8_C(  84), -INT8_C(   8),  INT8_C(  27), -INT8_C(  24), -INT8_C(  25), -INT8_C( 115),
         INT8_C( 118),  INT8_C(  90),  INT8_C(  46),  INT8_C(  99),  INT8_C(  51), -INT8_C(  97), -INT8_C(  55), -INT8_C( 102) },
      { -INT8_C(  58),  INT8_C( 105), -INT8_C(   1), -INT8_C(  20), -INT8_C(  51), -INT8_C(  85), -INT8_C(  14), -INT8_C(  29),
        -INT8_C(  62), -INT8_C(   8), -INT8_C(  24), -INT8_C( 115),  INT8_C(  90),  INT8_C(  46), -INT8_C(  97), -INT8_C( 102) } },
    { {  INT8_C( 102),  INT8_C(  50),  INT8_C(  13), -INT8_C(  73),  INT8_C(  49),  INT8_C(  88), -INT8_C(  93),  INT8_C(  90),
         INT8_C(  37),  INT8_C(  93),  INT8_C(   5),  INT8_C(  23),  INT8_C(  88), -INT8_C(  23),  INT8_C(  94), -INT8_C(  44) },
      { -INT8_C(  85), -INT8_C(  78), -INT8_C(  51), -INT8_C(  58), -INT8_C( 101), -INT8_C(  76),  INT8_C(  84),  INT8_C(  17),
         INT8_C(  14), -INT8_C( 126),  INT8_C( 116),  INT8_C(  65),  INT8_C(  33),  INT8_C(  61), -INT8_C(  36), -INT8_C( 121) },
      {  INT8_C(  50), -INT8_C(  73),  INT8_C(  49), -INT8_C(  93),  INT8_C(  37),  INT8_C(   5), -INT8_C(  23), -INT8_C(  44),
        -INT8_C(  85), -INT8_C(  58), -INT8_C( 101),  INT8_C(  17), -INT8_C( 126),  INT8_C(  65),  INT8_C(  33), -INT8_C( 121) } },
    { {  INT8_C( 112), -INT8_C(  23),  INT8_C(  62), -INT8_C(  95),  INT8_C(  65), -INT8_C(  31), -INT8_C(   4),  INT8_C( 103),
         INT8_C(  62),  INT8_C(   1),  INT8_C( 126), -INT8_C( 105), -INT8_C(  22), -INT8_C(  36),  INT8_C( 107), -INT8_C( 106) },
      { -INT8_C( 113),  INT8_C(  56),  INT8_C(  92),  INT8_C(  42), -INT8_C(  20), -INT8_C(  80),  INT8_C(  59), -INT8_C(   5),
         INT8_C(  50), -INT8_C(  81),  INT8_C(  60),  INT8_C(  84), -INT8_C(  20),  INT8_C(  24), -INT8_C(  37),  INT8_C(  92) },
      { -INT8_C(  23), -INT8_C(  95), -INT8_C(  31), -INT8_C(   4),  INT8_C(   1), -INT8_C( 105), -INT8_C(  36), -INT8_C( 106),
        -INT8_C( 113),  INT8_C(  42), -INT8_C(  80), -INT8_C(   5), -INT8_C(  81),  INT8_C(  60), -INT8_C(  20), -INT8_C(  37) } },
    { {  INT8_C(   2),  INT8_C(  26), -INT8_C(   2),  INT8_C(  67), -INT8_C(   5), -INT8_C(   6), -INT8_C(  86),  INT8_C(  58),
        -INT8_C(   5),  INT8_C(  41), -INT8_C(  47), -INT8_C(  26),  INT8_C(   5),  INT8_C(  60),  INT8_C( 124), -INT8_C( 108) },
      {  INT8_C( 117), -INT8_C(  40), -INT8_C(  66),  INT8_C(  97), -INT8_C( 119), -INT8_C(   7),  INT8_C(  92), -INT8_C(  69),
        -INT8_C(  88), -INT8_C( 103),  INT8_C(  15), -INT8_C( 107), -INT8_C(  79), -INT8_C(  21), -INT8_C(  15), -INT8_C(  77) },
      {  INT8_C(   2), -INT8_C(   2), -INT8_C(   6), -INT8_C(  86), -INT8_C(   5), -INT8_C(  47),  INT8_C(   5), -INT8_C( 108),
        -INT8_C(  40), -INT8_C(  66), -INT8_C( 119), -INT8_C(  69), -INT8_C( 103), -INT8_C( 107), -INT8_C(  79), -INT8_C(  77) } },
    { {  INT8_C(   5), -INT8_C(  17), -INT8_C(   9),  INT8_C(   0), -INT8_C(  23), -INT8_C(  95),  INT8_C(  58), -INT8_C(  27),
        -INT8_C(  54),  INT8_C(  11), -INT8_C(  53), -INT8_C(  48),  INT8_C(  72),  INT8_C(  71),  INT8_C( 100), -INT8_C(  67) },
      {  INT8_C(  31),  INT8_C(  35),  INT8_C(  30), -INT8_C(  88),  INT8_C(  28),  INT8_C( 123),  INT8_C( 100), -INT8_C(  59),
         INT8_C(  20),  INT8_C( 115),  INT8_C(  90), -INT8_C(  59),  INT8_C(  94),  INT8_C(  75),  INT8_C( 121),  INT8_C(  99) },
      { -INT8_C(  17), -INT8_C(   9), -INT8_C(  95), -INT8_C(  27), -INT8_C(  54), -INT8_C(  53),  INT8_C(  71), -INT8_C(  67),
         INT8_C(  31), -INT8_C(  88),  INT8_C(  28), -INT8_C(  59),  INT8_C(  20), -INT8_C(  59),  INT8_C(  75),  INT8_C(  99) } },
    { {  INT8_C(  59),  INT8_C( 112),  INT8_C( 100),  INT8_C(  36),  INT8_C(  17), -INT8_C(  98),  INT8_C(   9), -INT8_C(  36),
        -INT8_C(  86), -INT8_C(  44), -INT8_C(  84), -INT8_C(  14),  INT8_C(  27),  INT8_C(  16), -INT8_C(  81),  INT8_C(  59) },
      {  INT8_C(  51), -INT8_C(  51), -INT8_C(  29),  INT8_C(  80),  INT8_C(  72),  INT8_C(  71),  INT8_C(  21),  INT8_C(  92),
        -INT8_C(  69),  INT8_C( 111),  INT8_C(  34),  INT8_C(  25), -INT8_C(  70), -INT8_C( 101),  INT8_C( 125), -INT8_C(  11) },
      {  INT8_C(  59),  INT8_C(  36), -INT8_C(  98), -INT8_C(  36), -INT8_C(  86), -INT8_C(  84),  INT8_C(  16), -INT8_C(  81),
        -INT8_C(  51), -INT8_C(  29),  INT8_C(  71),  INT8_C(  21), -INT8_C(  69),  INT8_C(  25), -INT8_C( 101), -INT8_C(  11) } },
    { {  INT8_C(  11), -INT8_C(  31),  INT8_C(  26),  INT8_C(  28),      INT8_MAX,  INT8_C(  35), -INT8_C(   8),  INT8_C(  41),
        -INT8_C(   8), -INT8_C(  92),  INT8_C(  27),  INT8_C(  19), -INT8_C(  75), -INT8_C(  54),  INT8_C(  78), -INT8_C(  24) },
      { -INT8_C( 104),  INT8_C(  50),  INT8_C(  56), -INT8_C(  32),  INT8_C( 121),  INT8_C(  77),  INT8_C(  61),  INT8_C(  52),
        -INT8_C(  68),  INT8_C(  95),  INT8_C(  78),  INT8_C( 119), -INT8_C(   6), -INT8_C(  53),  INT8_C( 108),  INT8_C(   5) },
      { -INT8_C(  31),  INT8_C(  26),  INT8_C(  35), -INT8_C(   8), -INT8_C(  92),  INT8_C(  19), -INT8_C(  75), -INT8_C(  24),
        -INT8_C( 104), -INT8_C(  32),  INT8_C(  77),  INT8_C(  52), -INT8_C(  68),  INT8_C(  78), -INT8_C(  53),  INT8_C(   5) } },
    { { -INT8_C(  84), -INT8_C( 122),  INT8_C(  33),  INT8_C(  43), -INT8_C(  86),  INT8_C(  26),  INT8_C(  85), -INT8_C(  94),
        -INT8_C(  66),  INT8_C( 112), -INT8_C(  75),  INT8_C( 115),  INT8_C(  59),  INT8_C(   4),  INT8_C(  92), -INT8_C(  45) },
      {  INT8_C(  54), -INT8_C( 108), -INT8_C(  77), -INT8_C(  81), -INT8_C(  30), -INT8_C(  16), -INT8_C(  28), -INT8_C(  98),
         INT8_C(  79),  INT8_C(  50),  INT8_C(  21),  INT8_C(  73), -INT8_C(   3), -INT8_C( 126),  INT8_C(  78), -INT8_C(  87) },
      { -INT8_C( 122),  INT8_C(  33), -INT8_C(  86), -INT8_C(  94), -INT8_C(  66), -INT8_C(  75),  INT8_C(   4), -INT8_C(  45),
        -INT8_C( 108), -INT8_C(  81), -INT8_C(  30), -INT8_C(  98),  INT8_C(  50),  INT8_C(  21), -INT8_C( 126), -INT8_C(  87) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vpminq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpminq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 14745),  INT16_C( 29545), -INT16_C(   175), -INT16_C(  5046), -INT16_C( 13015), -INT16_C( 21574), -INT16_C(  1038),  INT16_C( 18147) },
      { -INT16_C( 15748), -INT16_C(  1964), -INT16_C(  6117), -INT16_C( 29209),  INT16_C( 23158),  INT16_C( 25390), -INT16_C( 24781), -INT16_C( 25911) },
      { -INT16_C( 14745), -INT16_C(  5046), -INT16_C( 21574), -INT16_C(  1038), -INT16_C( 15748), -INT16_C( 29209),  INT16_C( 23158), -INT16_C( 25911) } },
    { {  INT16_C( 12902), -INT16_C( 18675),  INT16_C( 22577),  INT16_C( 23203),  INT16_C( 23845),  INT16_C(  5893), -INT16_C(  5800), -INT16_C( 11170) },
      { -INT16_C( 19797), -INT16_C( 14643), -INT16_C( 19301),  INT16_C(  4436), -INT16_C( 32242),  INT16_C( 16756),  INT16_C( 15649), -INT16_C( 30756) },
      { -INT16_C( 18675),  INT16_C( 22577),  INT16_C(  5893), -INT16_C( 11170), -INT16_C( 19797), -INT16_C( 19301), -INT16_C( 32242), -INT16_C( 30756) } },
    { { -INT16_C(  5776), -INT16_C( 24258), -INT16_C(  7871),  INT16_C( 26620),  INT16_C(   318), -INT16_C( 26754), -INT16_C(  8982), -INT16_C( 27029) },
      {  INT16_C( 14479),  INT16_C( 10844), -INT16_C( 20244), -INT16_C(  1221), -INT16_C( 20686),  INT16_C( 21564),  INT16_C(  6380),  INT16_C( 23771) },
      { -INT16_C( 24258), -INT16_C(  7871), -INT16_C( 26754), -INT16_C( 27029),  INT16_C( 10844), -INT16_C( 20244), -INT16_C( 20686),  INT16_C(  6380) } },
    { {  INT16_C(  6658),  INT16_C( 17406), -INT16_C(  1285),  INT16_C( 15018),  INT16_C( 10747), -INT16_C(  6447),  INT16_C( 15365), -INT16_C( 27524) },
      { -INT16_C( 10123),  INT16_C( 25022), -INT16_C(  1655), -INT16_C( 17572), -INT16_C( 26200), -INT16_C( 27377), -INT16_C(  5199), -INT16_C( 19471) },
      {  INT16_C(  6658), -INT16_C(  1285), -INT16_C(  6447), -INT16_C( 27524), -INT16_C( 10123), -INT16_C( 17572), -INT16_C( 27377), -INT16_C( 19471) } },
    { { -INT16_C(  4347),  INT16_C(   247), -INT16_C( 24087), -INT16_C(  6854),  INT16_C(  3018), -INT16_C( 12085),  INT16_C( 18248), -INT16_C( 17052) },
      {  INT16_C(  8991), -INT16_C( 22498),  INT16_C( 31516), -INT16_C( 15004),  INT16_C( 29460), -INT16_C( 15014),  INT16_C( 19294),  INT16_C( 25465) },
      { -INT16_C(  4347), -INT16_C( 24087), -INT16_C( 12085), -INT16_C( 17052), -INT16_C( 22498), -INT16_C( 15004), -INT16_C( 15014),  INT16_C( 19294) } },
    { {  INT16_C( 28731),  INT16_C(  9316), -INT16_C( 25071), -INT16_C(  9207), -INT16_C( 11094), -INT16_C(  3412),  INT16_C(  4123),  INT16_C( 15279) },
      { -INT16_C( 13005),  INT16_C( 20707),  INT16_C( 18248),  INT16_C( 23573),  INT16_C( 28603),  INT16_C(  6434), -INT16_C( 25670), -INT16_C(  2691) },
      {  INT16_C(  9316), -INT16_C( 25071), -INT16_C( 11094),  INT16_C(  4123), -INT16_C( 13005),  INT16_C( 18248),  INT16_C(  6434), -INT16_C( 25670) } },
    { { -INT16_C(  7925),  INT16_C(  7194),  INT16_C(  9087),  INT16_C( 10744), -INT16_C( 23304),  INT16_C(  4891), -INT16_C( 13643), -INT16_C(  6066) },
      {  INT16_C( 12952), -INT16_C(  8136),  INT16_C( 19833),  INT16_C( 13373),  INT16_C( 24508),  INT16_C( 30542), -INT16_C( 13318),  INT16_C(  1388) },
      { -INT16_C(  7925),  INT16_C(  9087), -INT16_C( 23304), -INT16_C( 13643), -INT16_C(  8136),  INT16_C( 13373),  INT16_C( 24508), -INT16_C( 13318) } },
    { { -INT16_C( 31060),  INT16_C( 11041),  INT16_C(  6826), -INT16_C( 23979),  INT16_C( 28862),  INT16_C( 29621),  INT16_C(  1083), -INT16_C( 11428) },
      { -INT16_C( 27594), -INT16_C( 20557), -INT16_C(  3870), -INT16_C( 24860),  INT16_C( 12879),  INT16_C( 18709), -INT16_C( 32003), -INT16_C( 22194) },
      { -INT16_C( 31060), -INT16_C( 23979),  INT16_C( 28862), -INT16_C( 11428), -INT16_C( 27594), -INT16_C( 24860),  INT16_C( 12879), -INT16_C( 32003) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vpminq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpminq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1936311911), -INT32_C(   330629295), -INT32_C(  1413821143),  INT32_C(  1189346290) },
      { -INT32_C(   128662916), -INT32_C(  1914181605),  INT32_C(  1663982198), -INT32_C(  1698062541) },
      { -INT32_C(   330629295), -INT32_C(  1413821143), -INT32_C(  1914181605), -INT32_C(  1698062541) } },
    { { -INT32_C(  1223871898),  INT32_C(  1520654385),  INT32_C(   386227493), -INT32_C(   731977384) },
      { -INT32_C(   959597909),  INT32_C(   290763931),  INT32_C(  1098154510), -INT32_C(  2015609567) },
      { -INT32_C(  1223871898), -INT32_C(   731977384), -INT32_C(   959597909), -INT32_C(  2015609567) } },
    { { -INT32_C(  1589712528),  INT32_C(  1744625985), -INT32_C(  1753349826), -INT32_C(  1771315990) },
      {  INT32_C(   710686863), -INT32_C(    79974164),  INT32_C(  1413263154),  INT32_C(  1557862636) },
      { -INT32_C(  1589712528), -INT32_C(  1771315990), -INT32_C(    79974164),  INT32_C(  1413263154) } },
    { {  INT32_C(  1140726274),  INT32_C(   984283899), -INT32_C(   422499845), -INT32_C(  1803797499) },
      {  INT32_C(  1639897205), -INT32_C(  1151534711), -INT32_C(  1794139736), -INT32_C(  1275991119) },
      {  INT32_C(   984283899), -INT32_C(  1803797499), -INT32_C(  1151534711), -INT32_C(  1794139736) } },
    { {  INT32_C(    16248581), -INT32_C(   449142295), -INT32_C(   791999542), -INT32_C(  1117501624) },
      { -INT32_C(  1474419937), -INT32_C(   983270628), -INT32_C(   983928044),  INT32_C(  1668893534) },
      { -INT32_C(   449142295), -INT32_C(  1117501624), -INT32_C(  1474419937), -INT32_C(   983928044) } },
    { {  INT32_C(   610562107), -INT32_C(   603349487), -INT32_C(   223554390),  INT32_C(  1001328667) },
      {  INT32_C(  1357106483),  INT32_C(  1544898376),  INT32_C(   421687227), -INT32_C(   176317510) },
      { -INT32_C(   603349487), -INT32_C(   223554390),  INT32_C(  1357106483), -INT32_C(   176317510) } },
    { {  INT32_C(   471523595),  INT32_C(   704127871),  INT32_C(   320578808), -INT32_C(   397489483) },
      { -INT32_C(   533187944),  INT32_C(   876432761),  INT32_C(  2001625020),  INT32_C(    91016186) },
      {  INT32_C(   471523595), -INT32_C(   397489483), -INT32_C(   533187944),  INT32_C(    91016186) } },
    { {  INT32_C(   723617452), -INT32_C(  1571480918),  INT32_C(  1941270718), -INT32_C(   748944325) },
      { -INT32_C(  1347185610), -INT32_C(  1629163294),  INT32_C(  1226125903), -INT32_C(  1454472451) },
      { -INT32_C(  1571480918), -INT32_C(   748944325), -INT32_C(  1629163294), -INT32_C(  1454472451) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vpminq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpminq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(103), UINT8_C(198), UINT8_C(105), UINT8_C(115), UINT8_C( 81),    UINT8_MAX, UINT8_C( 74), UINT8_C(236),
        UINT8_C( 41), UINT8_C(205), UINT8_C(186), UINT8_C(171), UINT8_C(242), UINT8_C(251), UINT8_C(227), UINT8_C( 70) },
      { UINT8_C(124), UINT8_C(194), UINT8_C( 84), UINT8_C(248), UINT8_C( 27), UINT8_C(232), UINT8_C(231), UINT8_C(141),
        UINT8_C(118), UINT8_C( 90), UINT8_C( 46), UINT8_C( 99), UINT8_C( 51), UINT8_C(159), UINT8_C(201), UINT8_C(154) },
      { UINT8_C(103), UINT8_C(105), UINT8_C( 81), UINT8_C( 74), UINT8_C( 41), UINT8_C(171), UINT8_C(242), UINT8_C( 70),
        UINT8_C(124), UINT8_C( 84), UINT8_C( 27), UINT8_C(141), UINT8_C( 90), UINT8_C( 46), UINT8_C( 51), UINT8_C(154) } },
    { { UINT8_C(102), UINT8_C( 50), UINT8_C( 13), UINT8_C(183), UINT8_C( 49), UINT8_C( 88), UINT8_C(163), UINT8_C( 90),
        UINT8_C( 37), UINT8_C( 93), UINT8_C(  5), UINT8_C( 23), UINT8_C( 88), UINT8_C(233), UINT8_C( 94), UINT8_C(212) },
      { UINT8_C(171), UINT8_C(178), UINT8_C(205), UINT8_C(198), UINT8_C(155), UINT8_C(180), UINT8_C( 84), UINT8_C( 17),
        UINT8_C( 14), UINT8_C(130), UINT8_C(116), UINT8_C( 65), UINT8_C( 33), UINT8_C( 61), UINT8_C(220), UINT8_C(135) },
      { UINT8_C( 50), UINT8_C( 13), UINT8_C( 49), UINT8_C( 90), UINT8_C( 37), UINT8_C(  5), UINT8_C( 88), UINT8_C( 94),
        UINT8_C(171), UINT8_C(198), UINT8_C(155), UINT8_C( 17), UINT8_C( 14), UINT8_C( 65), UINT8_C( 33), UINT8_C(135) } },
    { { UINT8_C(112), UINT8_C(233), UINT8_C( 62), UINT8_C(161), UINT8_C( 65), UINT8_C(225), UINT8_C(252), UINT8_C(103),
        UINT8_C( 62), UINT8_C(  1), UINT8_C(126), UINT8_C(151), UINT8_C(234), UINT8_C(220), UINT8_C(107), UINT8_C(150) },
      { UINT8_C(143), UINT8_C( 56), UINT8_C( 92), UINT8_C( 42), UINT8_C(236), UINT8_C(176), UINT8_C( 59), UINT8_C(251),
        UINT8_C( 50), UINT8_C(175), UINT8_C( 60), UINT8_C( 84), UINT8_C(236), UINT8_C( 24), UINT8_C(219), UINT8_C( 92) },
      { UINT8_C(112), UINT8_C( 62), UINT8_C( 65), UINT8_C(103), UINT8_C(  1), UINT8_C(126), UINT8_C(220), UINT8_C(107),
        UINT8_C( 56), UINT8_C( 42), UINT8_C(176), UINT8_C( 59), UINT8_C( 50), UINT8_C( 60), UINT8_C( 24), UINT8_C( 92) } },
    { { UINT8_C(  2), UINT8_C( 26), UINT8_C(254), UINT8_C( 67), UINT8_C(251), UINT8_C(250), UINT8_C(170), UINT8_C( 58),
        UINT8_C(251), UINT8_C( 41), UINT8_C(209), UINT8_C(230), UINT8_C(  5), UINT8_C( 60), UINT8_C(124), UINT8_C(148) },
      { UINT8_C(117), UINT8_C(216), UINT8_C(190), UINT8_C( 97), UINT8_C(137), UINT8_C(249), UINT8_C( 92), UINT8_C(187),
        UINT8_C(168), UINT8_C(153), UINT8_C( 15), UINT8_C(149), UINT8_C(177), UINT8_C(235), UINT8_C(241), UINT8_C(179) },
      { UINT8_C(  2), UINT8_C( 67), UINT8_C(250), UINT8_C( 58), UINT8_C( 41), UINT8_C(209), UINT8_C(  5), UINT8_C(124),
        UINT8_C(117), UINT8_C( 97), UINT8_C(137), UINT8_C( 92), UINT8_C(153), UINT8_C( 15), UINT8_C(177), UINT8_C(179) } },
    { { UINT8_C(  5), UINT8_C(239), UINT8_C(247), UINT8_C(  0), UINT8_C(233), UINT8_C(161), UINT8_C( 58), UINT8_C(229),
        UINT8_C(202), UINT8_C( 11), UINT8_C(203), UINT8_C(208), UINT8_C( 72), UINT8_C( 71), UINT8_C(100), UINT8_C(189) },
      { UINT8_C( 31), UINT8_C( 35), UINT8_C( 30), UINT8_C(168), UINT8_C( 28), UINT8_C(123), UINT8_C(100), UINT8_C(197),
        UINT8_C( 20), UINT8_C(115), UINT8_C( 90), UINT8_C(197), UINT8_C( 94), UINT8_C( 75), UINT8_C(121), UINT8_C( 99) },
      { UINT8_C(  5), UINT8_C(  0), UINT8_C(161), UINT8_C( 58), UINT8_C( 11), UINT8_C(203), UINT8_C( 71), UINT8_C(100),
        UINT8_C( 31), UINT8_C( 30), UINT8_C( 28), UINT8_C(100), UINT8_C( 20), UINT8_C( 90), UINT8_C( 75), UINT8_C( 99) } },
    { { UINT8_C( 59), UINT8_C(112), UINT8_C(100), UINT8_C( 36), UINT8_C( 17), UINT8_C(158), UINT8_C(  9), UINT8_C(220),
        UINT8_C(170), UINT8_C(212), UINT8_C(172), UINT8_C(242), UINT8_C( 27), UINT8_C( 16), UINT8_C(175), UINT8_C( 59) },
      { UINT8_C( 51), UINT8_C(205), UINT8_C(227), UINT8_C( 80), UINT8_C( 72), UINT8_C( 71), UINT8_C( 21), UINT8_C( 92),
        UINT8_C(187), UINT8_C(111), UINT8_C( 34), UINT8_C( 25), UINT8_C(186), UINT8_C(155), UINT8_C(125), UINT8_C(245) },
      { UINT8_C( 59), UINT8_C( 36), UINT8_C( 17), UINT8_C(  9), UINT8_C(170), UINT8_C(172), UINT8_C( 16), UINT8_C( 59),
        UINT8_C( 51), UINT8_C( 80), UINT8_C( 71), UINT8_C( 21), UINT8_C(111), UINT8_C( 25), UINT8_C(155), UINT8_C(125) } },
    { { UINT8_C( 11), UINT8_C(225), UINT8_C( 26), UINT8_C( 28), UINT8_C(127), UINT8_C( 35), UINT8_C(248), UINT8_C( 41),
        UINT8_C(248), UINT8_C(164), UINT8_C( 27), UINT8_C( 19), UINT8_C(181), UINT8_C(202), UINT8_C( 78), UINT8_C(232) },
      { UINT8_C(152), UINT8_C( 50), UINT8_C( 56), UINT8_C(224), UINT8_C(121), UINT8_C( 77), UINT8_C( 61), UINT8_C( 52),
        UINT8_C(188), UINT8_C( 95), UINT8_C( 78), UINT8_C(119), UINT8_C(250), UINT8_C(203), UINT8_C(108), UINT8_C(  5) },
      { UINT8_C( 11), UINT8_C( 26), UINT8_C( 35), UINT8_C( 41), UINT8_C(164), UINT8_C( 19), UINT8_C(181), UINT8_C( 78),
        UINT8_C( 50), UINT8_C( 56), UINT8_C( 77), UINT8_C( 52), UINT8_C( 95), UINT8_C( 78), UINT8_C(203), UINT8_C(  5) } },
    { { UINT8_C(172), UINT8_C(134), UINT8_C( 33), UINT8_C( 43), UINT8_C(170), UINT8_C( 26), UINT8_C( 85), UINT8_C(162),
        UINT8_C(190), UINT8_C(112), UINT8_C(181), UINT8_C(115), UINT8_C( 59), UINT8_C(  4), UINT8_C( 92), UINT8_C(211) },
      { UINT8_C( 54), UINT8_C(148), UINT8_C(179), UINT8_C(175), UINT8_C(226), UINT8_C(240), UINT8_C(228), UINT8_C(158),
        UINT8_C( 79), UINT8_C( 50), UINT8_C( 21), UINT8_C( 73), UINT8_C(253), UINT8_C(130), UINT8_C( 78), UINT8_C(169) },
      { UINT8_C(134), UINT8_C( 33), UINT8_C( 26), UINT8_C( 85), UINT8_C(112), UINT8_C(115), UINT8_C(  4), UINT8_C( 92),
        UINT8_C( 54), UINT8_C(175), UINT8_C(226), UINT8_C(158), UINT8_C( 50), UINT8_C( 21), UINT8_C(130), UINT8_C( 78) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vpminq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpminq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(50791), UINT16_C(29545), UINT16_C(65361), UINT16_C(60490), UINT16_C(52521), UINT16_C(43962), UINT16_C(64498), UINT16_C(18147) },
      { UINT16_C(49788), UINT16_C(63572), UINT16_C(59419), UINT16_C(36327), UINT16_C(23158), UINT16_C(25390), UINT16_C(40755), UINT16_C(39625) },
      { UINT16_C(29545), UINT16_C(60490), UINT16_C(43962), UINT16_C(18147), UINT16_C(49788), UINT16_C(36327), UINT16_C(23158), UINT16_C(39625) } },
    { { UINT16_C(12902), UINT16_C(46861), UINT16_C(22577), UINT16_C(23203), UINT16_C(23845), UINT16_C( 5893), UINT16_C(59736), UINT16_C(54366) },
      { UINT16_C(45739), UINT16_C(50893), UINT16_C(46235), UINT16_C( 4436), UINT16_C(33294), UINT16_C(16756), UINT16_C(15649), UINT16_C(34780) },
      { UINT16_C(12902), UINT16_C(22577), UINT16_C( 5893), UINT16_C(54366), UINT16_C(45739), UINT16_C( 4436), UINT16_C(16756), UINT16_C(15649) } },
    { { UINT16_C(59760), UINT16_C(41278), UINT16_C(57665), UINT16_C(26620), UINT16_C(  318), UINT16_C(38782), UINT16_C(56554), UINT16_C(38507) },
      { UINT16_C(14479), UINT16_C(10844), UINT16_C(45292), UINT16_C(64315), UINT16_C(44850), UINT16_C(21564), UINT16_C( 6380), UINT16_C(23771) },
      { UINT16_C(41278), UINT16_C(26620), UINT16_C(  318), UINT16_C(38507), UINT16_C(10844), UINT16_C(45292), UINT16_C(21564), UINT16_C( 6380) } },
    { { UINT16_C( 6658), UINT16_C(17406), UINT16_C(64251), UINT16_C(15018), UINT16_C(10747), UINT16_C(59089), UINT16_C(15365), UINT16_C(38012) },
      { UINT16_C(55413), UINT16_C(25022), UINT16_C(63881), UINT16_C(47964), UINT16_C(39336), UINT16_C(38159), UINT16_C(60337), UINT16_C(46065) },
      { UINT16_C( 6658), UINT16_C(15018), UINT16_C(10747), UINT16_C(15365), UINT16_C(25022), UINT16_C(47964), UINT16_C(38159), UINT16_C(46065) } },
    { { UINT16_C(61189), UINT16_C(  247), UINT16_C(41449), UINT16_C(58682), UINT16_C( 3018), UINT16_C(53451), UINT16_C(18248), UINT16_C(48484) },
      { UINT16_C( 8991), UINT16_C(43038), UINT16_C(31516), UINT16_C(50532), UINT16_C(29460), UINT16_C(50522), UINT16_C(19294), UINT16_C(25465) },
      { UINT16_C(  247), UINT16_C(41449), UINT16_C( 3018), UINT16_C(18248), UINT16_C( 8991), UINT16_C(31516), UINT16_C(29460), UINT16_C(19294) } },
    { { UINT16_C(28731), UINT16_C( 9316), UINT16_C(40465), UINT16_C(56329), UINT16_C(54442), UINT16_C(62124), UINT16_C( 4123), UINT16_C(15279) },
      { UINT16_C(52531), UINT16_C(20707), UINT16_C(18248), UINT16_C(23573), UINT16_C(28603), UINT16_C( 6434), UINT16_C(39866), UINT16_C(62845) },
      { UINT16_C( 9316), UINT16_C(40465), UINT16_C(54442), UINT16_C( 4123), UINT16_C(20707), UINT16_C(18248), UINT16_C( 6434), UINT16_C(39866) } },
    { { UINT16_C(57611), UINT16_C( 7194), UINT16_C( 9087), UINT16_C(10744), UINT16_C(42232), UINT16_C( 4891), UINT16_C(51893), UINT16_C(59470) },
      { UINT16_C(12952), UINT16_C(57400), UINT16_C(19833), UINT16_C(13373), UINT16_C(24508), UINT16_C(30542), UINT16_C(52218), UINT16_C( 1388) },
      { UINT16_C( 7194), UINT16_C( 9087), UINT16_C( 4891), UINT16_C(51893), UINT16_C(12952), UINT16_C(13373), UINT16_C(24508), UINT16_C( 1388) } },
    { { UINT16_C(34476), UINT16_C(11041), UINT16_C( 6826), UINT16_C(41557), UINT16_C(28862), UINT16_C(29621), UINT16_C( 1083), UINT16_C(54108) },
      { UINT16_C(37942), UINT16_C(44979), UINT16_C(61666), UINT16_C(40676), UINT16_C(12879), UINT16_C(18709), UINT16_C(33533), UINT16_C(43342) },
      { UINT16_C(11041), UINT16_C( 6826), UINT16_C(28862), UINT16_C( 1083), UINT16_C(37942), UINT16_C(40676), UINT16_C(12879), UINT16_C(33533) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vpminq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpminq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1936311911), UINT32_C(3964338001), UINT32_C(2881146153), UINT32_C(1189346290) },
      { UINT32_C(4166304380), UINT32_C(2380785691), UINT32_C(1663982198), UINT32_C(2596904755) },
      { UINT32_C(1936311911), UINT32_C(1189346290), UINT32_C(2380785691), UINT32_C(1663982198) } },
    { { UINT32_C(3071095398), UINT32_C(1520654385), UINT32_C( 386227493), UINT32_C(3562989912) },
      { UINT32_C(3335369387), UINT32_C( 290763931), UINT32_C(1098154510), UINT32_C(2279357729) },
      { UINT32_C(1520654385), UINT32_C( 386227493), UINT32_C( 290763931), UINT32_C(1098154510) } },
    { { UINT32_C(2705254768), UINT32_C(1744625985), UINT32_C(2541617470), UINT32_C(2523651306) },
      { UINT32_C( 710686863), UINT32_C(4214993132), UINT32_C(1413263154), UINT32_C(1557862636) },
      { UINT32_C(1744625985), UINT32_C(2523651306), UINT32_C( 710686863), UINT32_C(1413263154) } },
    { { UINT32_C(1140726274), UINT32_C( 984283899), UINT32_C(3872467451), UINT32_C(2491169797) },
      { UINT32_C(1639897205), UINT32_C(3143432585), UINT32_C(2500827560), UINT32_C(3018976177) },
      { UINT32_C( 984283899), UINT32_C(2491169797), UINT32_C(1639897205), UINT32_C(2500827560) } },
    { { UINT32_C(  16248581), UINT32_C(3845825001), UINT32_C(3502967754), UINT32_C(3177465672) },
      { UINT32_C(2820547359), UINT32_C(3311696668), UINT32_C(3311039252), UINT32_C(1668893534) },
      { UINT32_C(  16248581), UINT32_C(3177465672), UINT32_C(2820547359), UINT32_C(1668893534) } },
    { { UINT32_C( 610562107), UINT32_C(3691617809), UINT32_C(4071412906), UINT32_C(1001328667) },
      { UINT32_C(1357106483), UINT32_C(1544898376), UINT32_C( 421687227), UINT32_C(4118649786) },
      { UINT32_C( 610562107), UINT32_C(1001328667), UINT32_C(1357106483), UINT32_C( 421687227) } },
    { { UINT32_C( 471523595), UINT32_C( 704127871), UINT32_C( 320578808), UINT32_C(3897477813) },
      { UINT32_C(3761779352), UINT32_C( 876432761), UINT32_C(2001625020), UINT32_C(  91016186) },
      { UINT32_C( 471523595), UINT32_C( 320578808), UINT32_C( 876432761), UINT32_C(  91016186) } },
    { { UINT32_C( 723617452), UINT32_C(2723486378), UINT32_C(1941270718), UINT32_C(3546022971) },
      { UINT32_C(2947781686), UINT32_C(2665804002), UINT32_C(1226125903), UINT32_C(2840494845) },
      { UINT32_C( 723617452), UINT32_C(1941270718), UINT32_C(2665804002), UINT32_C(1226125903) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vpminq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmins_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -3.71), SIMDE_FLOAT32_C(   987.98) },
      SIMDE_FLOAT32_C(    -3.71) },
    { { SIMDE_FLOAT32_C(    71.28), SIMDE_FLOAT32_C(   -73.22) },
      SIMDE_FLOAT32_C(   -73.22) },
    { { SIMDE_FLOAT32_C(   662.47), SIMDE_FLOAT32_C(   798.12) },
      SIMDE_FLOAT32_C(   662.47) },
    { { SIMDE_FLOAT32_C(   748.29), SIMDE_FLOAT32_C(   429.24) },
      SIMDE_FLOAT32_C(   429.24) },
    { { SIMDE_FLOAT32_C(  -135.59), SIMDE_FLOAT32_C(  -818.02) },
      SIMDE_FLOAT32_C(  -818.02) },
    { { SIMDE_FLOAT32_C(  -586.79), SIMDE_FLOAT32_C(   204.77) },
      SIMDE_FLOAT32_C(  -586.79) },
    { { SIMDE_FLOAT32_C(  -567.78), SIMDE_FLOAT32_C(   738.70) },
      SIMDE_FLOAT32_C(  -567.78) },
    { { SIMDE_FLOAT32_C(   138.50), SIMDE_FLOAT32_C(   654.90) },
      SIMDE_FLOAT32_C(   138.50) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vpmins_f32(a);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vpmins_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpminqd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -817.36), SIMDE_FLOAT64_C(  -203.90) },
      SIMDE_FLOAT64_C(  -817.36) },
    { { SIMDE_FLOAT64_C(   453.34), SIMDE_FLOAT64_C(  -713.33) },
      SIMDE_FLOAT64_C(  -713.33) },
    { { SIMDE_FLOAT64_C(  -881.31), SIMDE_FLOAT64_C(   -11.11) },
      SIMDE_FLOAT64_C(  -881.31) },
    { { SIMDE_FLOAT64_C(  -205.40), SIMDE_FLOAT64_C(    31.04) },
      SIMDE_FLOAT64_C(  -205.40) },
    { { SIMDE_FLOAT64_C(   693.81), SIMDE_FLOAT64_C(  -888.36) },
      SIMDE_FLOAT64_C(  -888.36) },
    { { SIMDE_FLOAT64_C(   531.32), SIMDE_FLOAT64_C(   786.68) },
      SIMDE_FLOAT64_C(   531.32) },
    { { SIMDE_FLOAT64_C(   904.99), SIMDE_FLOAT64_C(   576.97) },
      SIMDE_FLOAT64_C(   576.97) },
    { { SIMDE_FLOAT64_C(   -71.56), SIMDE_FLOAT64_C(   548.42) },
      SIMDE_FLOAT64_C(   -71.56) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vpminqd_f64(a);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64_t r = simde_vpminqd_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpmin_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmin_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmin_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmin_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmin_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmin_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmin_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpminq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminq_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpmins_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminqd_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
