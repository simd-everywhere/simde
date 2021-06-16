#define SIMDE_TEST_ARM_NEON_INSN pmax

#include "test-neon.h"
#include "../../../simde/arm/neon/pmax.h"

static int
test_simde_vpmax_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   316.14), SIMDE_FLOAT32_C(  -317.76) },
      { SIMDE_FLOAT32_C(  -999.28), SIMDE_FLOAT32_C(  -769.83) },
      { SIMDE_FLOAT32_C(   316.14), SIMDE_FLOAT32_C(  -769.83) } },
    { { SIMDE_FLOAT32_C(   563.53), SIMDE_FLOAT32_C(   317.30) },
      { SIMDE_FLOAT32_C(   849.20), SIMDE_FLOAT32_C(  -796.72) },
      { SIMDE_FLOAT32_C(   563.53), SIMDE_FLOAT32_C(   849.20) } },
    { { SIMDE_FLOAT32_C(   615.10), SIMDE_FLOAT32_C(   119.52) },
      { SIMDE_FLOAT32_C(   458.60), SIMDE_FLOAT32_C(   696.42) },
      { SIMDE_FLOAT32_C(   615.10), SIMDE_FLOAT32_C(   696.42) } },
    { { SIMDE_FLOAT32_C(  -342.74), SIMDE_FLOAT32_C(    78.42) },
      { SIMDE_FLOAT32_C(   362.08), SIMDE_FLOAT32_C(  -518.00) },
      { SIMDE_FLOAT32_C(    78.42), SIMDE_FLOAT32_C(   362.08) } },
    { { SIMDE_FLOAT32_C(  -470.51), SIMDE_FLOAT32_C(  -628.98) },
      { SIMDE_FLOAT32_C(   627.75), SIMDE_FLOAT32_C(  -933.75) },
      { SIMDE_FLOAT32_C(  -470.51), SIMDE_FLOAT32_C(   627.75) } },
    { { SIMDE_FLOAT32_C(  -180.94), SIMDE_FLOAT32_C(   801.21) },
      { SIMDE_FLOAT32_C(   206.11), SIMDE_FLOAT32_C(  -537.70) },
      { SIMDE_FLOAT32_C(   801.21), SIMDE_FLOAT32_C(   206.11) } },
    { { SIMDE_FLOAT32_C(  -275.82), SIMDE_FLOAT32_C(  -533.06) },
      { SIMDE_FLOAT32_C(    77.91), SIMDE_FLOAT32_C(   887.40) },
      { SIMDE_FLOAT32_C(  -275.82), SIMDE_FLOAT32_C(   887.40) } },
    { { SIMDE_FLOAT32_C(   896.99), SIMDE_FLOAT32_C(  -718.48) },
      { SIMDE_FLOAT32_C(  -622.01), SIMDE_FLOAT32_C(   213.13) },
      { SIMDE_FLOAT32_C(   896.99), SIMDE_FLOAT32_C(   213.13) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vpmax_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpmax_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  54),  INT8_C(  72),  INT8_C(  21),  INT8_C(   4), -INT8_C(  44), -INT8_C(  85), -INT8_C(  47),  INT8_C(  48) },
      { -INT8_C(  97),  INT8_C( 124), -INT8_C(  89), -INT8_C( 115),  INT8_C(  72), -INT8_C(  78),  INT8_C(  21),  INT8_C(   9) },
      {  INT8_C(  72),  INT8_C(  21), -INT8_C(  44),  INT8_C(  48),  INT8_C( 124), -INT8_C(  89),  INT8_C(  72),  INT8_C(  21) } },
    { {  INT8_C(  47),  INT8_C(  79),  INT8_C(  36), -INT8_C( 113),  INT8_C(  55), -INT8_C(  81),  INT8_C(  42),  INT8_C(  63) },
      {  INT8_C(  81), -INT8_C(  48),  INT8_C(  68), -INT8_C(  24), -INT8_C(  31), -INT8_C( 126), -INT8_C( 127),  INT8_C(  23) },
      {  INT8_C(  79),  INT8_C(  36),  INT8_C(  55),  INT8_C(  63),  INT8_C(  81),  INT8_C(  68), -INT8_C(  31),  INT8_C(  23) } },
    { { -INT8_C(  54), -INT8_C( 106),  INT8_C(  28), -INT8_C(  98),  INT8_C(  66), -INT8_C(  19), -INT8_C(  49), -INT8_C(  31) },
      {  INT8_C( 105),  INT8_C( 118),  INT8_C( 111), -INT8_C(  78),  INT8_C(  41), -INT8_C( 124), -INT8_C(  69),  INT8_C(  88) },
      { -INT8_C(  54),  INT8_C(  28),  INT8_C(  66), -INT8_C(  31),  INT8_C( 118),  INT8_C( 111),  INT8_C(  41),  INT8_C(  88) } },
    { { -INT8_C(  45), -INT8_C(  33), -INT8_C(  25),  INT8_C(  10), -INT8_C( 113),  INT8_C(  17),  INT8_C(  73), -INT8_C(  32) },
      { -INT8_C(  31), -INT8_C( 115), -INT8_C(  56), -INT8_C(  62),  INT8_C(  15),  INT8_C(  73), -INT8_C(  38), -INT8_C(  38) },
      { -INT8_C(  33),  INT8_C(  10),  INT8_C(  17),  INT8_C(  73), -INT8_C(  31), -INT8_C(  56),  INT8_C(  73), -INT8_C(  38) } },
    { { -INT8_C(  33), -INT8_C(  10),  INT8_C( 120),  INT8_C(  33), -INT8_C(  29),  INT8_C(  71),  INT8_C(   3),  INT8_C(  76) },
      { -INT8_C(  66),  INT8_C( 114), -INT8_C(   2), -INT8_C(  25), -INT8_C(  10), -INT8_C(  70),  INT8_C(  63), -INT8_C(  55) },
      { -INT8_C(  10),  INT8_C( 120),  INT8_C(  71),  INT8_C(  76),  INT8_C( 114), -INT8_C(   2), -INT8_C(  10),  INT8_C(  63) } },
    { { -INT8_C( 103),  INT8_C(  38), -INT8_C(  45),  INT8_C(  40),  INT8_C(  55),  INT8_C(  28),  INT8_C(   8),  INT8_C(  24) },
      { -INT8_C(  87), -INT8_C(  48), -INT8_C(  37), -INT8_C(  71),  INT8_C(  25), -INT8_C(  75), -INT8_C( 109), -INT8_C(   7) },
      {  INT8_C(  38),  INT8_C(  40),  INT8_C(  55),  INT8_C(  24), -INT8_C(  48), -INT8_C(  37),  INT8_C(  25), -INT8_C(   7) } },
    { { -INT8_C(  85),  INT8_C(  11),  INT8_C(  26), -INT8_C( 114),  INT8_C(  83),  INT8_C(  29), -INT8_C(  38),  INT8_C(  17) },
      { -INT8_C( 113), -INT8_C(  39), -INT8_C(   8), -INT8_C( 123), -INT8_C( 109),  INT8_C(  55),  INT8_C(  78),  INT8_C(  44) },
      {  INT8_C(  11),  INT8_C(  26),  INT8_C(  83),  INT8_C(  17), -INT8_C(  39), -INT8_C(   8),  INT8_C(  55),  INT8_C(  78) } },
    { {  INT8_C(  93),  INT8_C(  33),  INT8_C(  85), -INT8_C( 108),  INT8_C(  61),  INT8_C(  93), -INT8_C(  84), -INT8_C(  25) },
      {  INT8_C(  46), -INT8_C( 121), -INT8_C(  96),  INT8_C(  71),  INT8_C(  60),  INT8_C(  51),  INT8_C(  64), -INT8_C(  25) },
      {  INT8_C(  93),  INT8_C(  85),  INT8_C(  93), -INT8_C(  25),  INT8_C(  46),  INT8_C(  71),  INT8_C(  60),  INT8_C(  64) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vpmax_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmax_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 21767),  INT16_C( 30835), -INT16_C( 27635),  INT16_C(  2734) },
      { -INT16_C(  6484), -INT16_C( 29161),  INT16_C( 17540),  INT16_C( 14326) },
      {  INT16_C( 30835),  INT16_C(  2734), -INT16_C(  6484),  INT16_C( 17540) } },
    { {  INT16_C( 21571),  INT16_C(   768),  INT16_C( 17210), -INT16_C( 13076) },
      { -INT16_C( 12895),  INT16_C( 10560),  INT16_C( 16348), -INT16_C( 10827) },
      {  INT16_C( 21571),  INT16_C( 17210),  INT16_C( 10560),  INT16_C( 16348) } },
    { {  INT16_C( 10474), -INT16_C(  2226), -INT16_C(   836),  INT16_C( 26625) },
      {  INT16_C(  6626),  INT16_C( 26359), -INT16_C(  4771), -INT16_C( 24419) },
      {  INT16_C( 10474),  INT16_C( 26625),  INT16_C( 26359), -INT16_C(  4771) } },
    { { -INT16_C( 25023),  INT16_C( 31651), -INT16_C( 28447), -INT16_C( 32184) },
      { -INT16_C( 30627),  INT16_C( 15020),  INT16_C( 25032), -INT16_C( 19953) },
      {  INT16_C( 31651), -INT16_C( 28447),  INT16_C( 15020),  INT16_C( 25032) } },
    { {  INT16_C( 23945),  INT16_C( 17833), -INT16_C( 21926),  INT16_C( 15534) },
      { -INT16_C( 23101),  INT16_C(  8355),  INT16_C( 16530), -INT16_C( 11072) },
      {  INT16_C( 23945),  INT16_C( 15534),  INT16_C(  8355),  INT16_C( 16530) } },
    { {  INT16_C( 25822), -INT16_C( 16305), -INT16_C( 26636),  INT16_C( 20802) },
      { -INT16_C(  4576), -INT16_C(  6005), -INT16_C( 25777), -INT16_C( 10086) },
      {  INT16_C( 25822),  INT16_C( 20802), -INT16_C(  4576), -INT16_C( 10086) } },
    { {  INT16_C( 17400),  INT16_C( 21022), -INT16_C( 13075), -INT16_C( 20081) },
      {  INT16_C( 12913),  INT16_C(   977), -INT16_C( 28046),  INT16_C( 20951) },
      {  INT16_C( 21022), -INT16_C( 13075),  INT16_C( 12913),  INT16_C( 20951) } },
    { {  INT16_C( 10230), -INT16_C(  5615),  INT16_C( 21438), -INT16_C(  8645) },
      { -INT16_C( 14526), -INT16_C( 28218),  INT16_C( 24674),  INT16_C( 23146) },
      {  INT16_C( 10230),  INT16_C( 21438), -INT16_C( 14526),  INT16_C( 24674) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vpmax_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmax_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1806003294),  INT32_C(  1534340244) },
      { -INT32_C(   191415557),  INT32_C(  1758153183) },
      {  INT32_C(  1534340244),  INT32_C(  1758153183) } },
    { {  INT32_C(  2009572098),  INT32_C(   834509304) },
      {  INT32_C(  1970830255),  INT32_C(   642974083) },
      {  INT32_C(  2009572098),  INT32_C(  1970830255) } },
    { {  INT32_C(   683322772), -INT32_C(   712823079) },
      {  INT32_C(  1204361832),  INT32_C(  1722782819) },
      {  INT32_C(   683322772),  INT32_C(  1722782819) } },
    { {  INT32_C(   819820088), -INT32_C(  1100899825) },
      { -INT32_C(  1741367019),  INT32_C(  1874757594) },
      {  INT32_C(   819820088),  INT32_C(  1874757594) } },
    { {  INT32_C(   244807733),  INT32_C(   249764774) },
      { -INT32_C(  1722438603),  INT32_C(  2046755905) },
      {  INT32_C(   249764774),  INT32_C(  2046755905) } },
    { { -INT32_C(  1985356678), -INT32_C(  1958212746) },
      { -INT32_C(  1088193308),  INT32_C(   942596611) },
      { -INT32_C(  1958212746),  INT32_C(   942596611) } },
    { {  INT32_C(    21480794),  INT32_C(   370092768) },
      {  INT32_C(   414148055), -INT32_C(   460214679) },
      {  INT32_C(   370092768),  INT32_C(   414148055) } },
    { {  INT32_C(     7158410),  INT32_C(   713798981) },
      {  INT32_C(   904506929), -INT32_C(   345172080) },
      {  INT32_C(   713798981),  INT32_C(   904506929) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vpmax_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmax_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(190), UINT8_C(197), UINT8_C( 74), UINT8_C(131), UINT8_C(236), UINT8_C(219), UINT8_C(181), UINT8_C( 31) },
      { UINT8_C( 23), UINT8_C( 93), UINT8_C( 64), UINT8_C(225), UINT8_C(244), UINT8_C(226), UINT8_C(137), UINT8_C(241) },
      { UINT8_C(197), UINT8_C(131), UINT8_C(236), UINT8_C(181), UINT8_C( 93), UINT8_C(225), UINT8_C(244), UINT8_C(241) } },
    { { UINT8_C( 33), UINT8_C( 75), UINT8_C(214), UINT8_C(  8), UINT8_C( 10), UINT8_C(126), UINT8_C(228), UINT8_C(193) },
      { UINT8_C( 62), UINT8_C(252), UINT8_C(231), UINT8_C(120), UINT8_C( 49), UINT8_C(141), UINT8_C(136), UINT8_C(240) },
      { UINT8_C( 75), UINT8_C(214), UINT8_C(126), UINT8_C(228), UINT8_C(252), UINT8_C(231), UINT8_C(141), UINT8_C(240) } },
    { { UINT8_C( 82), UINT8_C(210), UINT8_C(115), UINT8_C( 62), UINT8_C(173), UINT8_C( 40), UINT8_C( 93), UINT8_C(196) },
      { UINT8_C(133), UINT8_C(157), UINT8_C(165), UINT8_C(121), UINT8_C(128), UINT8_C( 46), UINT8_C(106), UINT8_C(161) },
      { UINT8_C(210), UINT8_C(115), UINT8_C(173), UINT8_C(196), UINT8_C(157), UINT8_C(165), UINT8_C(128), UINT8_C(161) } },
    { { UINT8_C(122), UINT8_C( 64), UINT8_C(169), UINT8_C(132), UINT8_C(190), UINT8_C(141), UINT8_C( 69), UINT8_C(253) },
      { UINT8_C(137), UINT8_C( 45), UINT8_C(117), UINT8_C(187), UINT8_C(186), UINT8_C(253), UINT8_C(171), UINT8_C( 12) },
      { UINT8_C(122), UINT8_C(169), UINT8_C(190), UINT8_C(253), UINT8_C(137), UINT8_C(187), UINT8_C(253), UINT8_C(171) } },
    { { UINT8_C(207), UINT8_C( 30), UINT8_C( 75), UINT8_C(124), UINT8_C( 70), UINT8_C(168), UINT8_C( 64), UINT8_C(203) },
      { UINT8_C( 70), UINT8_C(229), UINT8_C( 68), UINT8_C(198), UINT8_C( 20), UINT8_C(174), UINT8_C(103), UINT8_C(142) },
      { UINT8_C(207), UINT8_C(124), UINT8_C(168), UINT8_C(203), UINT8_C(229), UINT8_C(198), UINT8_C(174), UINT8_C(142) } },
    { { UINT8_C(238), UINT8_C( 16), UINT8_C( 18), UINT8_C(173), UINT8_C(158), UINT8_C( 88), UINT8_C(170), UINT8_C( 39) },
      { UINT8_C(133), UINT8_C( 31), UINT8_C(226), UINT8_C( 63), UINT8_C( 29), UINT8_C(141), UINT8_C( 75), UINT8_C(236) },
      { UINT8_C(238), UINT8_C(173), UINT8_C(158), UINT8_C(170), UINT8_C(133), UINT8_C(226), UINT8_C(141), UINT8_C(236) } },
    { { UINT8_C(171), UINT8_C(150), UINT8_C(105), UINT8_C(241), UINT8_C( 63), UINT8_C(169), UINT8_C(188), UINT8_C(133) },
      { UINT8_C(143), UINT8_C(  0), UINT8_C( 75), UINT8_C(163), UINT8_C(174), UINT8_C(178), UINT8_C( 49), UINT8_C(157) },
      { UINT8_C(171), UINT8_C(241), UINT8_C(169), UINT8_C(188), UINT8_C(143), UINT8_C(163), UINT8_C(178), UINT8_C(157) } },
    { { UINT8_C(194), UINT8_C( 67), UINT8_C( 74), UINT8_C( 96), UINT8_C(155), UINT8_C(244), UINT8_C(136), UINT8_C( 32) },
      { UINT8_C( 19), UINT8_C(106), UINT8_C( 95), UINT8_C( 48), UINT8_C(248), UINT8_C(171), UINT8_C( 29), UINT8_C(163) },
      { UINT8_C(194), UINT8_C( 96), UINT8_C(244), UINT8_C(136), UINT8_C(106), UINT8_C( 95), UINT8_C(248), UINT8_C(163) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vpmax_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmax_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(17905), UINT16_C(30463), UINT16_C(10779), UINT16_C(40437) },
      { UINT16_C(54218), UINT16_C(63146), UINT16_C(19060), UINT16_C(61787) },
      { UINT16_C(30463), UINT16_C(40437), UINT16_C(63146), UINT16_C(61787) } },
    { { UINT16_C(47398), UINT16_C(43390), UINT16_C(13086), UINT16_C(17157) },
      { UINT16_C(33597), UINT16_C( 4258), UINT16_C(62124), UINT16_C(40446) },
      { UINT16_C(47398), UINT16_C(17157), UINT16_C(33597), UINT16_C(62124) } },
    { { UINT16_C(65080), UINT16_C(21267), UINT16_C( 2088), UINT16_C(62192) },
      { UINT16_C(39644), UINT16_C(20713), UINT16_C(17636), UINT16_C( 2881) },
      { UINT16_C(65080), UINT16_C(62192), UINT16_C(39644), UINT16_C(17636) } },
    { { UINT16_C(49405), UINT16_C( 7092), UINT16_C(47603), UINT16_C(12383) },
      { UINT16_C(  316), UINT16_C(59456), UINT16_C(16115), UINT16_C(11142) },
      { UINT16_C(49405), UINT16_C(47603), UINT16_C(59456), UINT16_C(16115) } },
    { { UINT16_C(39228), UINT16_C(25983), UINT16_C(28578), UINT16_C(32343) },
      { UINT16_C(16394), UINT16_C(61134), UINT16_C( 3973), UINT16_C(33529) },
      { UINT16_C(39228), UINT16_C(32343), UINT16_C(61134), UINT16_C(33529) } },
    { { UINT16_C(44751), UINT16_C(49822), UINT16_C(64871), UINT16_C(42226) },
      { UINT16_C(13054), UINT16_C(61836), UINT16_C( 4721), UINT16_C(44317) },
      { UINT16_C(49822), UINT16_C(64871), UINT16_C(61836), UINT16_C(44317) } },
    { { UINT16_C(40108), UINT16_C(19986), UINT16_C(27147), UINT16_C( 5580) },
      { UINT16_C(39594), UINT16_C(12036), UINT16_C(64937), UINT16_C(31154) },
      { UINT16_C(40108), UINT16_C(27147), UINT16_C(39594), UINT16_C(64937) } },
    { { UINT16_C(20651), UINT16_C( 4923), UINT16_C(11853), UINT16_C(19383) },
      { UINT16_C(17248), UINT16_C(53564), UINT16_C(22870), UINT16_C(  639) },
      { UINT16_C(20651), UINT16_C(19383), UINT16_C(53564), UINT16_C(22870) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vpmax_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmax_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2640987649), UINT32_C( 568799812) },
      { UINT32_C(2065880842), UINT32_C(1160985759) },
      { UINT32_C(2640987649), UINT32_C(2065880842) } },
    { { UINT32_C(3408914299), UINT32_C( 786561845) },
      { UINT32_C(2780205411), UINT32_C(1474653014) },
      { UINT32_C(3408914299), UINT32_C(2780205411) } },
    { { UINT32_C(4143206321), UINT32_C(2350373761) },
      { UINT32_C(1359428018), UINT32_C(4036377461) },
      { UINT32_C(4143206321), UINT32_C(4036377461) } },
    { { UINT32_C(1471989282), UINT32_C( 629513665) },
      { UINT32_C(2227846190), UINT32_C(1507569575) },
      { UINT32_C(1471989282), UINT32_C(2227846190) } },
    { { UINT32_C(2152714238), UINT32_C(1544316586) },
      { UINT32_C( 346887071), UINT32_C(1879327822) },
      { UINT32_C(2152714238), UINT32_C(1879327822) } },
    { { UINT32_C(3418931210), UINT32_C(2364558685) },
      { UINT32_C( 823180169), UINT32_C(1770712170) },
      { UINT32_C(3418931210), UINT32_C(1770712170) } },
    { { UINT32_C(1726601659), UINT32_C(3737318719) },
      { UINT32_C(1475506184), UINT32_C(3200775860) },
      { UINT32_C(3737318719), UINT32_C(3200775860) } },
    { { UINT32_C( 344559543), UINT32_C(1721793245) },
      { UINT32_C(2677518645), UINT32_C(1476927901) },
      { UINT32_C(1721793245), UINT32_C(2677518645) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vpmax_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmaxq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -402.07), SIMDE_FLOAT32_C(  -666.37), SIMDE_FLOAT32_C(   362.68), SIMDE_FLOAT32_C(  -326.71) },
      { SIMDE_FLOAT32_C(   454.85), SIMDE_FLOAT32_C(  -121.62), SIMDE_FLOAT32_C(   430.43), SIMDE_FLOAT32_C(   746.87) },
      { SIMDE_FLOAT32_C(  -402.07), SIMDE_FLOAT32_C(   362.68), SIMDE_FLOAT32_C(   454.85), SIMDE_FLOAT32_C(   746.87) } },
    { { SIMDE_FLOAT32_C(    33.52), SIMDE_FLOAT32_C(  -284.09), SIMDE_FLOAT32_C(  -166.25), SIMDE_FLOAT32_C(   480.19) },
      { SIMDE_FLOAT32_C(   -49.24), SIMDE_FLOAT32_C(   564.50), SIMDE_FLOAT32_C(   852.14), SIMDE_FLOAT32_C(  -390.08) },
      { SIMDE_FLOAT32_C(    33.52), SIMDE_FLOAT32_C(   480.19), SIMDE_FLOAT32_C(   564.50), SIMDE_FLOAT32_C(   852.14) } },
    { { SIMDE_FLOAT32_C(  -339.81), SIMDE_FLOAT32_C(   223.10), SIMDE_FLOAT32_C(  -267.43), SIMDE_FLOAT32_C(   -98.08) },
      { SIMDE_FLOAT32_C(   315.18), SIMDE_FLOAT32_C(  -621.58), SIMDE_FLOAT32_C(  -833.21), SIMDE_FLOAT32_C(     0.90) },
      { SIMDE_FLOAT32_C(   223.10), SIMDE_FLOAT32_C(   -98.08), SIMDE_FLOAT32_C(   315.18), SIMDE_FLOAT32_C(     0.90) } },
    { { SIMDE_FLOAT32_C(   737.95), SIMDE_FLOAT32_C(   329.19), SIMDE_FLOAT32_C(   372.64), SIMDE_FLOAT32_C(   555.32) },
      { SIMDE_FLOAT32_C(   563.00), SIMDE_FLOAT32_C(  -123.50), SIMDE_FLOAT32_C(  -962.40), SIMDE_FLOAT32_C(  -839.07) },
      { SIMDE_FLOAT32_C(   737.95), SIMDE_FLOAT32_C(   555.32), SIMDE_FLOAT32_C(   563.00), SIMDE_FLOAT32_C(  -839.07) } },
    { { SIMDE_FLOAT32_C(   210.13), SIMDE_FLOAT32_C(   400.28), SIMDE_FLOAT32_C(  -165.78), SIMDE_FLOAT32_C(  -335.02) },
      { SIMDE_FLOAT32_C(  -721.33), SIMDE_FLOAT32_C(  -735.34), SIMDE_FLOAT32_C(  -588.15), SIMDE_FLOAT32_C(   312.18) },
      { SIMDE_FLOAT32_C(   400.28), SIMDE_FLOAT32_C(  -165.78), SIMDE_FLOAT32_C(  -721.33), SIMDE_FLOAT32_C(   312.18) } },
    { { SIMDE_FLOAT32_C(   -19.43), SIMDE_FLOAT32_C(   245.59), SIMDE_FLOAT32_C(  -207.63), SIMDE_FLOAT32_C(   931.34) },
      { SIMDE_FLOAT32_C(  -189.91), SIMDE_FLOAT32_C(  -355.49), SIMDE_FLOAT32_C(  -458.75), SIMDE_FLOAT32_C(   470.28) },
      { SIMDE_FLOAT32_C(   245.59), SIMDE_FLOAT32_C(   931.34), SIMDE_FLOAT32_C(  -189.91), SIMDE_FLOAT32_C(   470.28) } },
    { { SIMDE_FLOAT32_C(   867.60), SIMDE_FLOAT32_C(   273.82), SIMDE_FLOAT32_C(  -627.81), SIMDE_FLOAT32_C(   182.78) },
      { SIMDE_FLOAT32_C(   652.24), SIMDE_FLOAT32_C(  -461.02), SIMDE_FLOAT32_C(  -816.31), SIMDE_FLOAT32_C(   390.19) },
      { SIMDE_FLOAT32_C(   867.60), SIMDE_FLOAT32_C(   182.78), SIMDE_FLOAT32_C(   652.24), SIMDE_FLOAT32_C(   390.19) } },
    { { SIMDE_FLOAT32_C(   868.17), SIMDE_FLOAT32_C(   556.33), SIMDE_FLOAT32_C(   -54.49), SIMDE_FLOAT32_C(   431.18) },
      { SIMDE_FLOAT32_C(  -567.17), SIMDE_FLOAT32_C(   -16.88), SIMDE_FLOAT32_C(   592.11), SIMDE_FLOAT32_C(   642.95) },
      { SIMDE_FLOAT32_C(   868.17), SIMDE_FLOAT32_C(   431.18), SIMDE_FLOAT32_C(   -16.88), SIMDE_FLOAT32_C(   642.95) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vpmaxq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpmaxq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   521.70), SIMDE_FLOAT64_C(   828.15) },
      { SIMDE_FLOAT64_C(   535.14), SIMDE_FLOAT64_C(   480.15) },
      { SIMDE_FLOAT64_C(   828.15), SIMDE_FLOAT64_C(   535.14) } },
    { { SIMDE_FLOAT64_C(  -518.98), SIMDE_FLOAT64_C(  -210.96) },
      { SIMDE_FLOAT64_C(  -930.38), SIMDE_FLOAT64_C(   215.97) },
      { SIMDE_FLOAT64_C(  -210.96), SIMDE_FLOAT64_C(   215.97) } },
    { { SIMDE_FLOAT64_C(    91.20), SIMDE_FLOAT64_C(   348.64) },
      { SIMDE_FLOAT64_C(  -290.21), SIMDE_FLOAT64_C(    54.45) },
      { SIMDE_FLOAT64_C(   348.64), SIMDE_FLOAT64_C(    54.45) } },
    { { SIMDE_FLOAT64_C(  -405.44), SIMDE_FLOAT64_C(  -790.85) },
      { SIMDE_FLOAT64_C(   151.68), SIMDE_FLOAT64_C(    31.01) },
      { SIMDE_FLOAT64_C(  -405.44), SIMDE_FLOAT64_C(   151.68) } },
    { { SIMDE_FLOAT64_C(  -850.04), SIMDE_FLOAT64_C(  -183.10) },
      { SIMDE_FLOAT64_C(   893.21), SIMDE_FLOAT64_C(   481.08) },
      { SIMDE_FLOAT64_C(  -183.10), SIMDE_FLOAT64_C(   893.21) } },
    { { SIMDE_FLOAT64_C(  -361.59), SIMDE_FLOAT64_C(     9.07) },
      { SIMDE_FLOAT64_C(   399.01), SIMDE_FLOAT64_C(  -896.67) },
      { SIMDE_FLOAT64_C(     9.07), SIMDE_FLOAT64_C(   399.01) } },
    { { SIMDE_FLOAT64_C(  -108.96), SIMDE_FLOAT64_C(   271.20) },
      { SIMDE_FLOAT64_C(   839.25), SIMDE_FLOAT64_C(   679.65) },
      { SIMDE_FLOAT64_C(   271.20), SIMDE_FLOAT64_C(   839.25) } },
    { { SIMDE_FLOAT64_C(   406.65), SIMDE_FLOAT64_C(  -664.11) },
      { SIMDE_FLOAT64_C(   733.62), SIMDE_FLOAT64_C(   -71.65) },
      { SIMDE_FLOAT64_C(   406.65), SIMDE_FLOAT64_C(   733.62) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vpmaxq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vpmaxq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  11),  INT8_C( 113), -INT8_C(  40), -INT8_C(  42), -INT8_C(  25), -INT8_C( 127),  INT8_C(  23), -INT8_C(  82),
        -INT8_C(  54),  INT8_C(  39),  INT8_C(  20), -INT8_C(   7),  INT8_C(  58),  INT8_C(  80), -INT8_C(  61), -INT8_C(   6) },
      {  INT8_C(  52), -INT8_C(   3), -INT8_C(  24), -INT8_C( 102),  INT8_C(  42), -INT8_C(  37), -INT8_C( 105), -INT8_C( 107),
        -INT8_C(  31), -INT8_C(  46),  INT8_C(  13),  INT8_C(  68), -INT8_C( 114), -INT8_C(  94), -INT8_C(  10), -INT8_C( 102) },
      {  INT8_C( 113), -INT8_C(  40), -INT8_C(  25),  INT8_C(  23),  INT8_C(  39),  INT8_C(  20),  INT8_C(  80), -INT8_C(   6),
         INT8_C(  52), -INT8_C(  24),  INT8_C(  42), -INT8_C( 105), -INT8_C(  31),  INT8_C(  68), -INT8_C(  94), -INT8_C(  10) } },
    { {  INT8_C(  19), -INT8_C(  50),  INT8_C( 112), -INT8_C(   6),  INT8_C(  80), -INT8_C( 121), -INT8_C(  88),  INT8_C(  26),
        -INT8_C(  81), -INT8_C(  67),  INT8_C(  19), -INT8_C(  23),  INT8_C(  13), -INT8_C(  42), -INT8_C(  28),  INT8_C(  66) },
      { -INT8_C(  45), -INT8_C(  52), -INT8_C(  36), -INT8_C(   3), -INT8_C(  88),  INT8_C( 115), -INT8_C( 109), -INT8_C( 119),
         INT8_C(  69), -INT8_C(  96), -INT8_C(  50), -INT8_C(  45),  INT8_C(  66), -INT8_C(  60),  INT8_C( 109),  INT8_C(  85) },
      {  INT8_C(  19),  INT8_C( 112),  INT8_C(  80),  INT8_C(  26), -INT8_C(  67),  INT8_C(  19),  INT8_C(  13),  INT8_C(  66),
        -INT8_C(  45), -INT8_C(   3),  INT8_C( 115), -INT8_C( 109),  INT8_C(  69), -INT8_C(  45),  INT8_C(  66),  INT8_C( 109) } },
    { { -INT8_C( 109), -INT8_C(  35),  INT8_C(  79), -INT8_C(  29),  INT8_C( 101), -INT8_C(   9), -INT8_C(   3),  INT8_C(  20),
        -INT8_C(  76),  INT8_C(  17), -INT8_C(   3), -INT8_C(  62), -INT8_C(  25), -INT8_C(  31),  INT8_C(   4), -INT8_C(  69) },
      { -INT8_C(  82), -INT8_C(  32), -INT8_C(  72),  INT8_C(  86),  INT8_C(  83),  INT8_C(  75), -INT8_C(  33), -INT8_C( 104),
        -INT8_C(  21), -INT8_C(  83),  INT8_C( 107),  INT8_C(  45),  INT8_C( 114), -INT8_C(  39), -INT8_C( 126),  INT8_C(   5) },
      { -INT8_C(  35),  INT8_C(  79),  INT8_C( 101),  INT8_C(  20),  INT8_C(  17), -INT8_C(   3), -INT8_C(  25),  INT8_C(   4),
        -INT8_C(  32),  INT8_C(  86),  INT8_C(  83), -INT8_C(  33), -INT8_C(  21),  INT8_C( 107),  INT8_C( 114),  INT8_C(   5) } },
    { { -INT8_C(  74), -INT8_C(  47), -INT8_C(  24),  INT8_C(  27), -INT8_C(  55), -INT8_C(  27),  INT8_C(  47),  INT8_C( 125),
        -INT8_C(  10),  INT8_C(  45),  INT8_C(  63), -INT8_C(  34),  INT8_C(  14),  INT8_C(  67), -INT8_C( 103), -INT8_C(  68) },
      {  INT8_C(  35),  INT8_C(  81),  INT8_C(  18),  INT8_C( 118), -INT8_C(  99), -INT8_C(  14),  INT8_C(  14), -INT8_C( 120),
        -INT8_C(  97),  INT8_C( 122), -INT8_C(  74),  INT8_C(  17),  INT8_C(  83),  INT8_C(  56),  INT8_C(  22),  INT8_C(   9) },
      { -INT8_C(  47),  INT8_C(  27), -INT8_C(  27),  INT8_C( 125),  INT8_C(  45),  INT8_C(  63),  INT8_C(  67), -INT8_C(  68),
         INT8_C(  81),  INT8_C( 118), -INT8_C(  14),  INT8_C(  14),  INT8_C( 122),  INT8_C(  17),  INT8_C(  83),  INT8_C(  22) } },
    { {  INT8_C(  10), -INT8_C(   2),  INT8_C(  37), -INT8_C(  45), -INT8_C(  28),  INT8_C(  84),  INT8_C(  80), -INT8_C(  38),
        -INT8_C( 127), -INT8_C( 112), -INT8_C(  72), -INT8_C( 112), -INT8_C(  45),  INT8_C(  81),  INT8_C(  76), -INT8_C(   9) },
      { -INT8_C(  93),  INT8_C(  95),  INT8_C( 109),  INT8_C(  64),  INT8_C(  81),  INT8_C( 124), -INT8_C(  56), -INT8_C(  16),
        -INT8_C(  10),  INT8_C( 126),  INT8_C(   2),  INT8_C(  73), -INT8_C(  73),  INT8_C(  24),  INT8_C(  82), -INT8_C(  63) },
      {  INT8_C(  10),  INT8_C(  37),  INT8_C(  84),  INT8_C(  80), -INT8_C( 112), -INT8_C(  72),  INT8_C(  81),  INT8_C(  76),
         INT8_C(  95),  INT8_C( 109),  INT8_C( 124), -INT8_C(  16),  INT8_C( 126),  INT8_C(  73),  INT8_C(  24),  INT8_C(  82) } },
    { {  INT8_C(  23),  INT8_C( 119), -INT8_C( 108), -INT8_C(   5), -INT8_C(  52), -INT8_C(  28), -INT8_C(  43),  INT8_C(  77),
         INT8_C( 116), -INT8_C( 114), -INT8_C(  35),  INT8_C(  72), -INT8_C(  33),  INT8_C(  42),  INT8_C(  63), -INT8_C( 126) },
      { -INT8_C( 119), -INT8_C(  84), -INT8_C(  62), -INT8_C(  38),  INT8_C(  40), -INT8_C( 117), -INT8_C(  54),  INT8_C(  30),
         INT8_C(   9), -INT8_C(  52),  INT8_C( 103), -INT8_C(  64), -INT8_C(  27), -INT8_C(  70), -INT8_C( 127), -INT8_C(   4) },
      {  INT8_C( 119), -INT8_C(   5), -INT8_C(  28),  INT8_C(  77),  INT8_C( 116),  INT8_C(  72),  INT8_C(  42),  INT8_C(  63),
        -INT8_C(  84), -INT8_C(  38),  INT8_C(  40),  INT8_C(  30),  INT8_C(   9),  INT8_C( 103), -INT8_C(  27), -INT8_C(   4) } },
    { {  INT8_C(  49),  INT8_C(  21), -INT8_C(   9), -INT8_C(   3), -INT8_C(   6), -INT8_C(  52),  INT8_C(  75),  INT8_C( 110),
         INT8_C(  90),  INT8_C(  40), -INT8_C(  74),  INT8_C(  58),  INT8_C(  82), -INT8_C(  11), -INT8_C(  68), -INT8_C(  37) },
      { -INT8_C(  94),      INT8_MAX, -INT8_C(  75), -INT8_C(  54),  INT8_C(  10),      INT8_MIN, -INT8_C(  23),  INT8_C(  19),
         INT8_C(  76),  INT8_C(  80), -INT8_C(  44),  INT8_C(  49),  INT8_C(  10),  INT8_C(  85),  INT8_C(  45),  INT8_C(  60) },
      {  INT8_C(  49), -INT8_C(   3), -INT8_C(   6),  INT8_C( 110),  INT8_C(  90),  INT8_C(  58),  INT8_C(  82), -INT8_C(  37),
             INT8_MAX, -INT8_C(  54),  INT8_C(  10),  INT8_C(  19),  INT8_C(  80),  INT8_C(  49),  INT8_C(  85),  INT8_C(  60) } },
    { {  INT8_C( 107),  INT8_C(  36),  INT8_C(  57),  INT8_C( 101), -INT8_C(  15), -INT8_C( 124), -INT8_C(  45),  INT8_C(  75),
        -INT8_C(  83), -INT8_C( 118), -INT8_C( 123), -INT8_C(   1),      INT8_MAX,  INT8_C(  66), -INT8_C(  37),  INT8_C(  33) },
      { -INT8_C(  63), -INT8_C( 112), -INT8_C(  20), -INT8_C(  53),  INT8_C(  16), -INT8_C(  43), -INT8_C(  34),  INT8_C(  93),
         INT8_C(  37), -INT8_C(  78), -INT8_C( 114),  INT8_C(  48),  INT8_C(   8), -INT8_C(  68),  INT8_C( 108),  INT8_C( 115) },
      {  INT8_C( 107),  INT8_C( 101), -INT8_C(  15),  INT8_C(  75), -INT8_C(  83), -INT8_C(   1),      INT8_MAX,  INT8_C(  33),
        -INT8_C(  63), -INT8_C(  20),  INT8_C(  16),  INT8_C(  93),  INT8_C(  37),  INT8_C(  48),  INT8_C(   8),  INT8_C( 115) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vpmaxq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmaxq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 13831), -INT16_C( 19466),  INT16_C( 25467),  INT16_C(  4969), -INT16_C( 11147),  INT16_C( 11223), -INT16_C(  7596),  INT16_C(  5877) },
      { -INT16_C( 12676),  INT16_C( 18011), -INT16_C( 29303), -INT16_C( 19656), -INT16_C(  6414), -INT16_C( 13803),  INT16_C( 15467),  INT16_C( 29189) },
      {  INT16_C( 13831),  INT16_C( 25467),  INT16_C( 11223),  INT16_C(  5877),  INT16_C( 18011), -INT16_C( 19656), -INT16_C(  6414),  INT16_C( 29189) } },
    { { -INT16_C(  1166), -INT16_C(  4570), -INT16_C( 28834), -INT16_C( 11519), -INT16_C( 10141), -INT16_C( 18433), -INT16_C(  2886),  INT16_C( 14285) },
      {  INT16_C( 10434),  INT16_C( 19581), -INT16_C( 19019), -INT16_C( 22273),  INT16_C(  5275),  INT16_C(  1650),  INT16_C( 30544), -INT16_C( 15751) },
      { -INT16_C(  1166), -INT16_C( 11519), -INT16_C( 10141),  INT16_C( 14285),  INT16_C( 19581), -INT16_C( 19019),  INT16_C(  5275),  INT16_C( 30544) } },
    { { -INT16_C( 24717), -INT16_C( 11856), -INT16_C( 20178), -INT16_C( 28251), -INT16_C( 23414),  INT16_C( 17480),  INT16_C(  5528),  INT16_C( 23163) },
      { -INT16_C(  1730), -INT16_C(  3162), -INT16_C( 23122),  INT16_C( 19099),  INT16_C(  3769),  INT16_C(  2384), -INT16_C( 13947), -INT16_C(  1844) },
      { -INT16_C( 11856), -INT16_C( 20178),  INT16_C( 17480),  INT16_C( 23163), -INT16_C(  1730),  INT16_C( 19099),  INT16_C(  3769), -INT16_C(  1844) } },
    { {  INT16_C( 31848), -INT16_C( 26934),  INT16_C( 28462), -INT16_C( 18393),  INT16_C( 28435), -INT16_C( 21508),  INT16_C( 30853), -INT16_C( 15611) },
      { -INT16_C( 21391),  INT16_C(  8118),  INT16_C( 21073),  INT16_C(  2921), -INT16_C( 17824), -INT16_C(  6892), -INT16_C(  8061), -INT16_C(  4898) },
      {  INT16_C( 31848),  INT16_C( 28462),  INT16_C( 28435),  INT16_C( 30853),  INT16_C(  8118),  INT16_C( 21073), -INT16_C(  6892), -INT16_C(  4898) } },
    { { -INT16_C( 22435), -INT16_C( 29822), -INT16_C( 21993),  INT16_C( 10819),  INT16_C( 16153), -INT16_C( 24875), -INT16_C(  9545),  INT16_C( 10337) },
      {  INT16_C(  6278), -INT16_C( 10168), -INT16_C( 20118), -INT16_C( 13597), -INT16_C(  2197), -INT16_C(  4177), -INT16_C( 29224),  INT16_C( 13787) },
      { -INT16_C( 22435),  INT16_C( 10819),  INT16_C( 16153),  INT16_C( 10337),  INT16_C(  6278), -INT16_C( 13597), -INT16_C(  2197),  INT16_C( 13787) } },
    { {  INT16_C( 23861),  INT16_C( 19648),  INT16_C(   775),  INT16_C(  8566),  INT16_C( 19266), -INT16_C(  1345),  INT16_C(  8486), -INT16_C( 21470) },
      {  INT16_C( 27193), -INT16_C( 23676),  INT16_C( 26396), -INT16_C( 30867),  INT16_C(  7263),  INT16_C( 14198),  INT16_C( 20906), -INT16_C(  8340) },
      {  INT16_C( 23861),  INT16_C(  8566),  INT16_C( 19266),  INT16_C(  8486),  INT16_C( 27193),  INT16_C( 26396),  INT16_C( 14198),  INT16_C( 20906) } },
    { {  INT16_C( 11439), -INT16_C( 18900), -INT16_C( 24017),  INT16_C( 29143), -INT16_C( 26642),  INT16_C(  5227), -INT16_C( 29000), -INT16_C(  3648) },
      {  INT16_C( 17912),  INT16_C(  5268),  INT16_C(   428),  INT16_C(  2972),  INT16_C(  4637), -INT16_C( 14526), -INT16_C( 20892),  INT16_C(  5031) },
      {  INT16_C( 11439),  INT16_C( 29143),  INT16_C(  5227), -INT16_C(  3648),  INT16_C( 17912),  INT16_C(  2972),  INT16_C(  4637),  INT16_C(  5031) } },
    { { -INT16_C( 11302),  INT16_C(  2505), -INT16_C( 24203),  INT16_C( 25467), -INT16_C(  6600), -INT16_C(  3977),  INT16_C( 14452),  INT16_C( 28129) },
      {  INT16_C( 30077),  INT16_C( 10625),  INT16_C(  7542), -INT16_C( 27851),  INT16_C( 30512), -INT16_C( 27557),  INT16_C(   550),  INT16_C(   167) },
      {  INT16_C(  2505),  INT16_C( 25467), -INT16_C(  3977),  INT16_C( 28129),  INT16_C( 30077),  INT16_C(  7542),  INT16_C( 30512),  INT16_C(   550) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vpmaxq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmaxq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1235350443),  INT32_C(  1495786913),  INT32_C(  1460006431), -INT32_C(  1555314335) },
      {  INT32_C(  1196301238),  INT32_C(  1914049203),  INT32_C(   734461602),  INT32_C(  1447843073) },
      {  INT32_C(  1495786913),  INT32_C(  1460006431),  INT32_C(  1914049203),  INT32_C(  1447843073) } },
    { {  INT32_C(    51161698), -INT32_C(  1352911728), -INT32_C(  2096733918), -INT32_C(   517582550) },
      {  INT32_C(   539522413),  INT32_C(   697450119),  INT32_C(  1045780541),  INT32_C(   278176174) },
      {  INT32_C(    51161698), -INT32_C(   517582550),  INT32_C(   697450119),  INT32_C(  1045780541) } },
    { { -INT32_C(   602693300), -INT32_C(   141856555), -INT32_C(    59075887),  INT32_C(  1356702179) },
      { -INT32_C(  1653537514), -INT32_C(  2134506685),  INT32_C(   180231004),  INT32_C(   152720317) },
      { -INT32_C(   141856555),  INT32_C(  1356702179), -INT32_C(  1653537514),  INT32_C(   180231004) } },
    { { -INT32_C(   907727372),  INT32_C(  1874882717), -INT32_C(   429180414), -INT32_C(   248100645) },
      { -INT32_C(  1869699251),  INT32_C(   118576555),  INT32_C(   756141936),  INT32_C(   372648738) },
      {  INT32_C(  1874882717), -INT32_C(   248100645),  INT32_C(   118576555),  INT32_C(   756141936) } },
    { { -INT32_C(   153150632), -INT32_C(  1905942644), -INT32_C(  1250635558),  INT32_C(  1705487128) },
      { -INT32_C(    34261678), -INT32_C(    83622262), -INT32_C(   131590698), -INT32_C(  1727045824) },
      { -INT32_C(   153150632),  INT32_C(  1705487128), -INT32_C(    34261678), -INT32_C(   131590698) } },
    { {  INT32_C(   110095994),  INT32_C(  1754657934), -INT32_C(   602076732),  INT32_C(   121750708) },
      { -INT32_C(  2080098566),  INT32_C(   327092541),  INT32_C(  1594599454), -INT32_C(  2114446841) },
      {  INT32_C(  1754657934),  INT32_C(   121750708),  INT32_C(   327092541),  INT32_C(  1594599454) } },
    { { -INT32_C(  1752660215),  INT32_C(  1073683835), -INT32_C(   618980314), -INT32_C(   605922079) },
      { -INT32_C(   815798638),  INT32_C(   249749487), -INT32_C(  1905398137),  INT32_C(   286221576) },
      {  INT32_C(  1073683835), -INT32_C(   605922079),  INT32_C(   249749487),  INT32_C(   286221576) } },
    { {  INT32_C(  1739102188), -INT32_C(   609835084), -INT32_C(  1514749500), -INT32_C(  1350526947) },
      {  INT32_C(  1853874046),  INT32_C(  1165779390),  INT32_C(  1490282831),  INT32_C(   980017998) },
      {  INT32_C(  1739102188), -INT32_C(  1350526947),  INT32_C(  1853874046),  INT32_C(  1490282831) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vpmaxq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmaxq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(194), UINT8_C(204), UINT8_C(147), UINT8_C( 27), UINT8_C(126), UINT8_C( 49), UINT8_C( 55), UINT8_C(152),
        UINT8_C(245), UINT8_C( 93), UINT8_C( 69), UINT8_C(214), UINT8_C(114), UINT8_C( 39), UINT8_C(222), UINT8_C( 45) },
      { UINT8_C(147), UINT8_C(174), UINT8_C( 82), UINT8_C(252), UINT8_C( 42), UINT8_C( 38), UINT8_C(161), UINT8_C( 37),
        UINT8_C(211), UINT8_C(101), UINT8_C( 54), UINT8_C(212), UINT8_C( 23), UINT8_C(109), UINT8_C(232), UINT8_C(218) },
      { UINT8_C(204), UINT8_C(147), UINT8_C(126), UINT8_C(152), UINT8_C(245), UINT8_C(214), UINT8_C(114), UINT8_C(222),
        UINT8_C(174), UINT8_C(252), UINT8_C( 42), UINT8_C(161), UINT8_C(211), UINT8_C(212), UINT8_C(109), UINT8_C(232) } },
    { { UINT8_C( 57), UINT8_C(123), UINT8_C(245), UINT8_C(183), UINT8_C(172), UINT8_C( 44), UINT8_C( 80), UINT8_C(161),
        UINT8_C(138), UINT8_C(149), UINT8_C(119), UINT8_C(252), UINT8_C(188), UINT8_C( 85), UINT8_C( 41), UINT8_C( 80) },
      { UINT8_C(  4), UINT8_C(123), UINT8_C( 76), UINT8_C( 46), UINT8_C(161), UINT8_C(237), UINT8_C( 83), UINT8_C(117),
        UINT8_C( 82), UINT8_C(137), UINT8_C( 73), UINT8_C(105), UINT8_C(246), UINT8_C( 49), UINT8_C( 67), UINT8_C( 47) },
      { UINT8_C(123), UINT8_C(245), UINT8_C(172), UINT8_C(161), UINT8_C(149), UINT8_C(252), UINT8_C(188), UINT8_C( 80),
        UINT8_C(123), UINT8_C( 76), UINT8_C(237), UINT8_C(117), UINT8_C(137), UINT8_C(105), UINT8_C(246), UINT8_C( 67) } },
    { { UINT8_C(172), UINT8_C( 56), UINT8_C(231), UINT8_C( 88), UINT8_C(101), UINT8_C( 55), UINT8_C(249), UINT8_C(239),
        UINT8_C(204), UINT8_C(113), UINT8_C(235), UINT8_C(137), UINT8_C(198), UINT8_C( 21), UINT8_C(217), UINT8_C(202) },
      { UINT8_C(144), UINT8_C( 37), UINT8_C(248), UINT8_C( 50), UINT8_C( 18), UINT8_C( 76), UINT8_C(167), UINT8_C(100),
        UINT8_C(213), UINT8_C(240), UINT8_C(205), UINT8_C(204), UINT8_C( 33), UINT8_C( 17), UINT8_C(251), UINT8_C(205) },
      { UINT8_C(172), UINT8_C(231), UINT8_C(101), UINT8_C(249), UINT8_C(204), UINT8_C(235), UINT8_C(198), UINT8_C(217),
        UINT8_C(144), UINT8_C(248), UINT8_C( 76), UINT8_C(167), UINT8_C(240), UINT8_C(205), UINT8_C( 33), UINT8_C(251) } },
    { { UINT8_C( 73), UINT8_C(226), UINT8_C( 37), UINT8_C(174), UINT8_C( 25), UINT8_C( 30), UINT8_C(157), UINT8_C(230),
        UINT8_C(143), UINT8_C(137), UINT8_C(111), UINT8_C( 86), UINT8_C(158), UINT8_C( 72), UINT8_C( 32), UINT8_C( 46) },
      { UINT8_C(109), UINT8_C( 25), UINT8_C( 96), UINT8_C(127), UINT8_C(101), UINT8_C(  7), UINT8_C(227), UINT8_C( 58),
        UINT8_C(247), UINT8_C(176), UINT8_C(  6), UINT8_C( 24), UINT8_C(193), UINT8_C(  2), UINT8_C(229), UINT8_C( 11) },
      { UINT8_C(226), UINT8_C(174), UINT8_C( 30), UINT8_C(230), UINT8_C(143), UINT8_C(111), UINT8_C(158), UINT8_C( 46),
        UINT8_C(109), UINT8_C(127), UINT8_C(101), UINT8_C(227), UINT8_C(247), UINT8_C( 24), UINT8_C(193), UINT8_C(229) } },
    { { UINT8_C(228), UINT8_C( 10), UINT8_C(185), UINT8_C(254), UINT8_C( 41), UINT8_C( 87), UINT8_C(228), UINT8_C(184),
        UINT8_C(224), UINT8_C( 83), UINT8_C( 14), UINT8_C(126), UINT8_C(155), UINT8_C( 47), UINT8_C(172), UINT8_C(  8) },
      { UINT8_C( 72), UINT8_C( 13), UINT8_C(135), UINT8_C(173), UINT8_C( 20), UINT8_C(106), UINT8_C(231), UINT8_C( 12),
        UINT8_C( 26), UINT8_C(238), UINT8_C( 36), UINT8_C(220), UINT8_C(240), UINT8_C( 10), UINT8_C(231), UINT8_C(212) },
      { UINT8_C(228), UINT8_C(254), UINT8_C( 87), UINT8_C(228), UINT8_C(224), UINT8_C(126), UINT8_C(155), UINT8_C(172),
        UINT8_C( 72), UINT8_C(173), UINT8_C(106), UINT8_C(231), UINT8_C(238), UINT8_C(220), UINT8_C(240), UINT8_C(231) } },
    { { UINT8_C( 20), UINT8_C(160), UINT8_C(210), UINT8_C( 61), UINT8_C(247), UINT8_C(182), UINT8_C(246), UINT8_C(215),
        UINT8_C(  9), UINT8_C(  4), UINT8_C( 85), UINT8_C(164), UINT8_C( 51), UINT8_C(  2), UINT8_C(172), UINT8_C(123) },
      { UINT8_C( 15), UINT8_C( 51), UINT8_C( 40), UINT8_C( 35), UINT8_C(157), UINT8_C( 16), UINT8_C( 47), UINT8_C(184),
        UINT8_C(254), UINT8_C( 84), UINT8_C(148), UINT8_C(238), UINT8_C( 94), UINT8_C(123), UINT8_C(194), UINT8_C(114) },
      { UINT8_C(160), UINT8_C(210), UINT8_C(247), UINT8_C(246), UINT8_C(  9), UINT8_C(164), UINT8_C( 51), UINT8_C(172),
        UINT8_C( 51), UINT8_C( 40), UINT8_C(157), UINT8_C(184), UINT8_C(254), UINT8_C(238), UINT8_C(123), UINT8_C(194) } },
    { { UINT8_C( 27), UINT8_C(149), UINT8_C(176), UINT8_C( 19), UINT8_C( 75), UINT8_C(166), UINT8_C(234), UINT8_C( 85),
        UINT8_C(170), UINT8_C( 64), UINT8_C(249), UINT8_C(222), UINT8_C( 66), UINT8_C(166), UINT8_C( 89), UINT8_C( 81) },
      { UINT8_C(217), UINT8_C(130), UINT8_C(116), UINT8_C(119), UINT8_C(146), UINT8_C(164), UINT8_C( 47), UINT8_C(144),
        UINT8_C(248), UINT8_C(195), UINT8_C(126), UINT8_C( 86), UINT8_C( 62), UINT8_C( 64), UINT8_C(200), UINT8_C( 89) },
      { UINT8_C(149), UINT8_C(176), UINT8_C(166), UINT8_C(234), UINT8_C(170), UINT8_C(249), UINT8_C(166), UINT8_C( 89),
        UINT8_C(217), UINT8_C(119), UINT8_C(164), UINT8_C(144), UINT8_C(248), UINT8_C(126), UINT8_C( 64), UINT8_C(200) } },
    { { UINT8_C(213), UINT8_C(120), UINT8_C(108), UINT8_C( 33), UINT8_C( 30), UINT8_C( 87), UINT8_C(118), UINT8_C(201),
        UINT8_C(151), UINT8_C(111), UINT8_C(167), UINT8_C(217), UINT8_C( 21), UINT8_C(  0), UINT8_C( 42), UINT8_C(239) },
      { UINT8_C(130), UINT8_C(158), UINT8_C(102), UINT8_C( 20), UINT8_C( 66), UINT8_C(149), UINT8_C(164), UINT8_C( 58),
        UINT8_C( 88), UINT8_C( 34), UINT8_C(144), UINT8_C(150), UINT8_C( 99), UINT8_C( 89), UINT8_C(239), UINT8_C( 56) },
      { UINT8_C(213), UINT8_C(108), UINT8_C( 87), UINT8_C(201), UINT8_C(151), UINT8_C(217), UINT8_C( 21), UINT8_C(239),
        UINT8_C(158), UINT8_C(102), UINT8_C(149), UINT8_C(164), UINT8_C( 88), UINT8_C(150), UINT8_C( 99), UINT8_C(239) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vpmaxq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmaxq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(59667), UINT16_C(15725), UINT16_C(57980), UINT16_C(10476), UINT16_C(19235), UINT16_C(46700), UINT16_C(45532), UINT16_C( 5614) },
      { UINT16_C(15278), UINT16_C(65483), UINT16_C(21580), UINT16_C(37597), UINT16_C(56993), UINT16_C(15917), UINT16_C(40954), UINT16_C( 3652) },
      { UINT16_C(59667), UINT16_C(57980), UINT16_C(46700), UINT16_C(45532), UINT16_C(65483), UINT16_C(37597), UINT16_C(56993), UINT16_C(40954) } },
    { { UINT16_C(45448), UINT16_C( 1099), UINT16_C(14228), UINT16_C(46893), UINT16_C(39299), UINT16_C(24429), UINT16_C(23370), UINT16_C(63604) },
      { UINT16_C(16278), UINT16_C(58103), UINT16_C(54419), UINT16_C(13428), UINT16_C(41650), UINT16_C(44403), UINT16_C(46913), UINT16_C(51643) },
      { UINT16_C(45448), UINT16_C(46893), UINT16_C(39299), UINT16_C(63604), UINT16_C(58103), UINT16_C(54419), UINT16_C(44403), UINT16_C(51643) } },
    { { UINT16_C( 1640), UINT16_C(64718), UINT16_C(64318), UINT16_C(49588), UINT16_C( 8596), UINT16_C(56864), UINT16_C(38013), UINT16_C( 5078) },
      { UINT16_C(52947), UINT16_C(26358), UINT16_C(27298), UINT16_C(21915), UINT16_C( 3596), UINT16_C(19714), UINT16_C(48581), UINT16_C(11543) },
      { UINT16_C(64718), UINT16_C(64318), UINT16_C(56864), UINT16_C(38013), UINT16_C(52947), UINT16_C(27298), UINT16_C(19714), UINT16_C(48581) } },
    { { UINT16_C(58819), UINT16_C(  298), UINT16_C(57056), UINT16_C(29890), UINT16_C(58111), UINT16_C(31826), UINT16_C(10358), UINT16_C(18832) },
      { UINT16_C(34550), UINT16_C(39344), UINT16_C(19440), UINT16_C(65006), UINT16_C(61529), UINT16_C( 7754), UINT16_C(25005), UINT16_C(28747) },
      { UINT16_C(58819), UINT16_C(57056), UINT16_C(58111), UINT16_C(18832), UINT16_C(39344), UINT16_C(65006), UINT16_C(61529), UINT16_C(28747) } },
    { { UINT16_C(30022), UINT16_C( 9842), UINT16_C(13395), UINT16_C(21402), UINT16_C(60439), UINT16_C(36303), UINT16_C(24341), UINT16_C( 3031) },
      { UINT16_C(34789), UINT16_C(54948), UINT16_C(37586), UINT16_C(11219), UINT16_C( 7554), UINT16_C(12105), UINT16_C(38015), UINT16_C(50592) },
      { UINT16_C(30022), UINT16_C(21402), UINT16_C(60439), UINT16_C(24341), UINT16_C(54948), UINT16_C(37586), UINT16_C(12105), UINT16_C(50592) } },
    { { UINT16_C( 4618), UINT16_C(24044), UINT16_C(34374), UINT16_C(23984), UINT16_C(32883), UINT16_C(35051), UINT16_C(49887), UINT16_C(50579) },
      { UINT16_C(14409), UINT16_C( 7067), UINT16_C(28362), UINT16_C(19782), UINT16_C(36747), UINT16_C( 2684), UINT16_C( 7203), UINT16_C(11728) },
      { UINT16_C(24044), UINT16_C(34374), UINT16_C(35051), UINT16_C(50579), UINT16_C(14409), UINT16_C(28362), UINT16_C(36747), UINT16_C(11728) } },
    { { UINT16_C(48174), UINT16_C(30091), UINT16_C(15170), UINT16_C(46546), UINT16_C(48571), UINT16_C(39741), UINT16_C(53631), UINT16_C(51296) },
      { UINT16_C(64265), UINT16_C(54243), UINT16_C(10601), UINT16_C(62496), UINT16_C(40376), UINT16_C(56575), UINT16_C(53177), UINT16_C(59401) },
      { UINT16_C(48174), UINT16_C(46546), UINT16_C(48571), UINT16_C(53631), UINT16_C(64265), UINT16_C(62496), UINT16_C(56575), UINT16_C(59401) } },
    { { UINT16_C(38027), UINT16_C(52573), UINT16_C(12240), UINT16_C(35715), UINT16_C(49389), UINT16_C(27686), UINT16_C(34449), UINT16_C(39477) },
      { UINT16_C( 6273), UINT16_C(60014), UINT16_C(36418), UINT16_C(64223), UINT16_C(56875), UINT16_C(58838), UINT16_C(57517), UINT16_C(14541) },
      { UINT16_C(52573), UINT16_C(35715), UINT16_C(49389), UINT16_C(39477), UINT16_C(60014), UINT16_C(64223), UINT16_C(58838), UINT16_C(57517) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vpmaxq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmaxq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 492066321), UINT32_C(2750383310), UINT32_C(2709160739), UINT32_C(4140404091) },
      { UINT32_C( 156087931), UINT32_C(2899083535), UINT32_C(1023047402), UINT32_C( 834825504) },
      { UINT32_C(2750383310), UINT32_C(4140404091), UINT32_C(2899083535), UINT32_C(1023047402) } },
    { { UINT32_C(2454656707), UINT32_C(3174383258), UINT32_C(1029681090), UINT32_C(3073583164) },
      { UINT32_C(4005593311), UINT32_C(3969616897), UINT32_C( 589862146), UINT32_C(3327453699) },
      { UINT32_C(3174383258), UINT32_C(3073583164), UINT32_C(4005593311), UINT32_C(3327453699) } },
    { { UINT32_C(2606277376), UINT32_C(2757266914), UINT32_C(2044835645), UINT32_C(3207664864) },
      { UINT32_C(2527981973), UINT32_C(2156021886), UINT32_C(3785599966), UINT32_C(2527590549) },
      { UINT32_C(2757266914), UINT32_C(3207664864), UINT32_C(2527981973), UINT32_C(3785599966) } },
    { { UINT32_C(2100363419), UINT32_C(3391195533), UINT32_C( 558105153), UINT32_C(2900391191) },
      { UINT32_C(3829566822), UINT32_C(3026568662), UINT32_C(  93653104), UINT32_C(2627419136) },
      { UINT32_C(3391195533), UINT32_C(2900391191), UINT32_C(3829566822), UINT32_C(2627419136) } },
    { { UINT32_C(3390688316), UINT32_C(2543074134), UINT32_C(1421400125), UINT32_C(3019937869) },
      { UINT32_C(4221059877), UINT32_C(2024799496), UINT32_C( 108872710), UINT32_C(3181517185) },
      { UINT32_C(3390688316), UINT32_C(3019937869), UINT32_C(4221059877), UINT32_C(3181517185) } },
    { { UINT32_C( 998751461), UINT32_C( 886185207), UINT32_C(1116310260), UINT32_C(1224116514) },
      { UINT32_C(3561197260), UINT32_C(2454516620), UINT32_C(3097020983), UINT32_C(3363191779) },
      { UINT32_C( 998751461), UINT32_C(1224116514), UINT32_C(3561197260), UINT32_C(3363191779) } },
    { { UINT32_C(3993304567), UINT32_C( 237164057), UINT32_C(2203102049), UINT32_C(  30098997) },
      { UINT32_C(1624641492), UINT32_C( 972169730), UINT32_C(3488779244), UINT32_C(3180882118) },
      { UINT32_C(3993304567), UINT32_C(2203102049), UINT32_C(1624641492), UINT32_C(3488779244) } },
    { { UINT32_C(2141953125), UINT32_C(3549285746), UINT32_C(2924993913), UINT32_C(4155449891) },
      { UINT32_C( 861439281), UINT32_C(2490190504), UINT32_C(2607046613), UINT32_C( 744029383) },
      { UINT32_C(3549285746), UINT32_C(4155449891), UINT32_C(2490190504), UINT32_C(2607046613) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vpmaxq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpmaxs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -687.34), SIMDE_FLOAT32_C(   938.41) },
      SIMDE_FLOAT32_C(   938.41) },
    { { SIMDE_FLOAT32_C(   -90.80), SIMDE_FLOAT32_C(  -528.65) },
      SIMDE_FLOAT32_C(   -90.80) },
    { { SIMDE_FLOAT32_C(    11.38), SIMDE_FLOAT32_C(  -376.09) },
      SIMDE_FLOAT32_C(    11.38) },
    { { SIMDE_FLOAT32_C(  -136.34), SIMDE_FLOAT32_C(  -804.70) },
      SIMDE_FLOAT32_C(  -136.34) },
    { { SIMDE_FLOAT32_C(  -475.42), SIMDE_FLOAT32_C(   955.92) },
      SIMDE_FLOAT32_C(   955.92) },
    { { SIMDE_FLOAT32_C(   141.16), SIMDE_FLOAT32_C(   -77.29) },
      SIMDE_FLOAT32_C(   141.16) },
    { { SIMDE_FLOAT32_C(    47.83), SIMDE_FLOAT32_C(  -559.34) },
      SIMDE_FLOAT32_C(    47.83) },
    { { SIMDE_FLOAT32_C(  -732.12), SIMDE_FLOAT32_C(   -31.68) },
      SIMDE_FLOAT32_C(   -31.68) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vpmaxs_f32(a);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vpmaxs_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpmaxqd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -940.00), SIMDE_FLOAT64_C(  -494.34) },
     SIMDE_FLOAT64_C(  -494.34) },
   { { SIMDE_FLOAT64_C(   -57.78), SIMDE_FLOAT64_C(   832.21) },
     SIMDE_FLOAT64_C(   832.21) },
   { { SIMDE_FLOAT64_C(  -973.99), SIMDE_FLOAT64_C(   101.27) },
     SIMDE_FLOAT64_C(   101.27) },
   { { SIMDE_FLOAT64_C(   184.50), SIMDE_FLOAT64_C(  -100.67) },
     SIMDE_FLOAT64_C(   184.50) },
   { { SIMDE_FLOAT64_C(  -792.79), SIMDE_FLOAT64_C(  -153.04) },
     SIMDE_FLOAT64_C(  -153.04) },
   { { SIMDE_FLOAT64_C(   317.69), SIMDE_FLOAT64_C(   455.59) },
     SIMDE_FLOAT64_C(   455.59) },
   { { SIMDE_FLOAT64_C(   152.31), SIMDE_FLOAT64_C(   547.52) },
     SIMDE_FLOAT64_C(   547.52) },
   { { SIMDE_FLOAT64_C(  -519.99), SIMDE_FLOAT64_C(   948.41) },
     SIMDE_FLOAT64_C(   948.41) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vpmaxqd_f64(a);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64_t r = simde_vpmaxqd_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpmax_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmax_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmax_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmax_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmax_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmax_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmax_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxq_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxs_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxqd_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
