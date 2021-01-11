#define SIMDE_TEST_ARM_NEON_INSN trn1

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/trn1.h>

static int
test_simde_vtrn1_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -734.98), SIMDE_FLOAT32_C(   365.45) },
      { SIMDE_FLOAT32_C(  -158.72), SIMDE_FLOAT32_C(   801.49) },
      { SIMDE_FLOAT32_C(  -734.98), SIMDE_FLOAT32_C(  -158.72) } },
    { { SIMDE_FLOAT32_C(  -244.32), SIMDE_FLOAT32_C(   246.47) },
      { SIMDE_FLOAT32_C(  -998.98), SIMDE_FLOAT32_C(  -876.14) },
      { SIMDE_FLOAT32_C(  -244.32), SIMDE_FLOAT32_C(  -998.98) } },
    { { SIMDE_FLOAT32_C(   821.58), SIMDE_FLOAT32_C(   188.36) },
      { SIMDE_FLOAT32_C(   526.46), SIMDE_FLOAT32_C(   806.12) },
      { SIMDE_FLOAT32_C(   821.58), SIMDE_FLOAT32_C(   526.46) } },
    { { SIMDE_FLOAT32_C(   231.60), SIMDE_FLOAT32_C(  -192.02) },
      { SIMDE_FLOAT32_C(  -230.26), SIMDE_FLOAT32_C(  -950.64) },
      { SIMDE_FLOAT32_C(   231.60), SIMDE_FLOAT32_C(  -230.26) } },
    { { SIMDE_FLOAT32_C(   514.95), SIMDE_FLOAT32_C(  -326.95) },
      { SIMDE_FLOAT32_C(  -930.10), SIMDE_FLOAT32_C(   113.30) },
      { SIMDE_FLOAT32_C(   514.95), SIMDE_FLOAT32_C(  -930.10) } },
    { { SIMDE_FLOAT32_C(   562.02), SIMDE_FLOAT32_C(  -958.09) },
      { SIMDE_FLOAT32_C(   753.36), SIMDE_FLOAT32_C(  -955.88) },
      { SIMDE_FLOAT32_C(   562.02), SIMDE_FLOAT32_C(   753.36) } },
    { { SIMDE_FLOAT32_C(   690.44), SIMDE_FLOAT32_C(  -991.78) },
      { SIMDE_FLOAT32_C(   276.78), SIMDE_FLOAT32_C(   537.69) },
      { SIMDE_FLOAT32_C(   690.44), SIMDE_FLOAT32_C(   276.78) } },
    { { SIMDE_FLOAT32_C(   -86.37), SIMDE_FLOAT32_C(  -105.16) },
      { SIMDE_FLOAT32_C(   319.11), SIMDE_FLOAT32_C(   178.65) },
      { SIMDE_FLOAT32_C(   -86.37), SIMDE_FLOAT32_C(   319.11) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vtrn1_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vtrn1_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  60), -INT8_C(  45), -INT8_C(  88), -INT8_C(  68), -INT8_C(  80),  INT8_C(  32),  INT8_C(  27), -INT8_C(  59) },
      {  INT8_C(   0),  INT8_C(  78), -INT8_C(  30), -INT8_C(  82), -INT8_C( 119),  INT8_C(  46),  INT8_C(  17),  INT8_C(  49) },
      { -INT8_C(  60),  INT8_C(   0), -INT8_C(  88), -INT8_C(  30), -INT8_C(  80), -INT8_C( 119),  INT8_C(  27),  INT8_C(  17) } },
    { {  INT8_C( 101),  INT8_C(  29),  INT8_C(  88),  INT8_C( 118), -INT8_C( 106), -INT8_C(  13), -INT8_C(  99),  INT8_C( 125) },
      {  INT8_C(  71), -INT8_C(  38),  INT8_C( 116), -INT8_C(  26), -INT8_C(  54), -INT8_C( 111),  INT8_C(  13), -INT8_C( 114) },
      {  INT8_C( 101),  INT8_C(  71),  INT8_C(  88),  INT8_C( 116), -INT8_C( 106), -INT8_C(  54), -INT8_C(  99),  INT8_C(  13) } },
    { {  INT8_C( 101), -INT8_C(  75),  INT8_C(  75),  INT8_C(  21), -INT8_C(  43),  INT8_C( 102), -INT8_C(  37), -INT8_C(  42) },
      { -INT8_C(  75), -INT8_C(  67), -INT8_C( 124),  INT8_C(  62), -INT8_C(  20), -INT8_C( 107),  INT8_C( 112),  INT8_C(  81) },
      {  INT8_C( 101), -INT8_C(  75),  INT8_C(  75), -INT8_C( 124), -INT8_C(  43), -INT8_C(  20), -INT8_C(  37),  INT8_C( 112) } },
    { { -INT8_C(  77), -INT8_C(  56), -INT8_C(  57),  INT8_C(  73), -INT8_C(  69),  INT8_C( 100), -INT8_C(  58),  INT8_C(   2) },
      {  INT8_C(  62),  INT8_C(  58), -INT8_C(  23),  INT8_C(   8), -INT8_C(  52), -INT8_C(  10), -INT8_C( 105),  INT8_C(  49) },
      { -INT8_C(  77),  INT8_C(  62), -INT8_C(  57), -INT8_C(  23), -INT8_C(  69), -INT8_C(  52), -INT8_C(  58), -INT8_C( 105) } },
    { { -INT8_C(  84), -INT8_C(  30),  INT8_C(  70), -INT8_C( 127),  INT8_C(  72),  INT8_C(  33),  INT8_C(  87), -INT8_C(   3) },
      { -INT8_C(  33), -INT8_C(  37),  INT8_C(  60), -INT8_C(  53),  INT8_C( 113), -INT8_C(  84),  INT8_C(  28),  INT8_C(  36) },
      { -INT8_C(  84), -INT8_C(  33),  INT8_C(  70),  INT8_C(  60),  INT8_C(  72),  INT8_C( 113),  INT8_C(  87),  INT8_C(  28) } },
    { {  INT8_C( 116), -INT8_C(  29),  INT8_C( 109),  INT8_C(  47),  INT8_C(  71),  INT8_C(  51),  INT8_C(  50), -INT8_C( 123) },
      {  INT8_C( 110),  INT8_C(  27), -INT8_C( 115),  INT8_C(  58),  INT8_C(  17),  INT8_C(  36),  INT8_C( 107), -INT8_C(  67) },
      {  INT8_C( 116),  INT8_C( 110),  INT8_C( 109), -INT8_C( 115),  INT8_C(  71),  INT8_C(  17),  INT8_C(  50),  INT8_C( 107) } },
    { {  INT8_C(   6), -INT8_C(  79),  INT8_C(  63),  INT8_C(  79), -INT8_C(  45), -INT8_C( 106),  INT8_C(  76), -INT8_C(  78) },
      {  INT8_C( 114), -INT8_C( 120),  INT8_C( 125), -INT8_C(  29),  INT8_C(  52), -INT8_C( 103),  INT8_C(   7), -INT8_C(  88) },
      {  INT8_C(   6),  INT8_C( 114),  INT8_C(  63),  INT8_C( 125), -INT8_C(  45),  INT8_C(  52),  INT8_C(  76),  INT8_C(   7) } },
    { {  INT8_C( 124),  INT8_C( 116), -INT8_C(  40), -INT8_C(  61), -INT8_C(  89),  INT8_C(  10),  INT8_C(  72),  INT8_C(  21) },
      {  INT8_C(  37), -INT8_C(  43),  INT8_C(  79),  INT8_C(  54), -INT8_C(   6), -INT8_C(  70), -INT8_C(  12),  INT8_C(   0) },
      {  INT8_C( 124),  INT8_C(  37), -INT8_C(  40),  INT8_C(  79), -INT8_C(  89), -INT8_C(   6),  INT8_C(  72), -INT8_C(  12) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vtrn1_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 12600),  INT16_C( 17726),  INT16_C( 25964), -INT16_C( 31246) },
      {  INT16_C( 29446),  INT16_C( 19730),  INT16_C(  5918),  INT16_C( 11654) },
      { -INT16_C( 12600),  INT16_C( 29446),  INT16_C( 25964),  INT16_C(  5918) } },
    { {  INT16_C( 20514),  INT16_C( 22734), -INT16_C(  2490), -INT16_C( 23811) },
      { -INT16_C( 13108),  INT16_C( 28476), -INT16_C( 13288), -INT16_C(  8175) },
      {  INT16_C( 20514), -INT16_C( 13108), -INT16_C(  2490), -INT16_C( 13288) } },
    { {  INT16_C( 20378),  INT16_C(  1574),  INT16_C(  6324), -INT16_C( 17781) },
      { -INT16_C( 24948), -INT16_C( 22008), -INT16_C( 29003), -INT16_C( 10280) },
      {  INT16_C( 20378), -INT16_C( 24948),  INT16_C(  6324), -INT16_C( 29003) } },
    { { -INT16_C( 22817),  INT16_C(  9519),  INT16_C( 11676),  INT16_C( 26823) },
      {  INT16_C(  1273),  INT16_C(  4823), -INT16_C(  5936),  INT16_C( 27378) },
      { -INT16_C( 22817),  INT16_C(  1273),  INT16_C( 11676), -INT16_C(  5936) } },
    { {  INT16_C(  6199), -INT16_C(  5264), -INT16_C(   975), -INT16_C( 16986) },
      { -INT16_C( 20838),  INT16_C( 20327),  INT16_C( 16188),  INT16_C(  6951) },
      {  INT16_C(  6199), -INT16_C( 20838), -INT16_C(   975),  INT16_C( 16188) } },
    { {  INT16_C( 22245), -INT16_C( 32447),  INT16_C(  2179),  INT16_C( 32233) },
      { -INT16_C( 16372), -INT16_C(  9073), -INT16_C( 32344), -INT16_C(  8378) },
      {  INT16_C( 22245), -INT16_C( 16372),  INT16_C(  2179), -INT16_C( 32344) } },
    { { -INT16_C( 18534), -INT16_C( 13365),  INT16_C( 29107),  INT16_C( 19848) },
      { -INT16_C(  4321),  INT16_C( 23452), -INT16_C( 15569),  INT16_C(  5239) },
      { -INT16_C( 18534), -INT16_C(  4321),  INT16_C( 29107), -INT16_C( 15569) } },
    { { -INT16_C( 18406), -INT16_C( 25194),  INT16_C( 32704), -INT16_C( 13030) },
      { -INT16_C( 22208), -INT16_C(  5975), -INT16_C(  4053), -INT16_C( 14904) },
      { -INT16_C( 18406), -INT16_C( 22208),  INT16_C( 32704), -INT16_C(  4053) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vtrn1_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  2113992025),  INT32_C(  1335496731) },
      { -INT32_C(   441354692), -INT32_C(   150353327) },
      { -INT32_C(  2113992025), -INT32_C(   441354692) } },
    { {  INT32_C(   131230526), -INT32_C(  1810676118) },
      {  INT32_C(     2093845), -INT32_C(  1520903682) },
      {  INT32_C(   131230526),  INT32_C(     2093845) } },
    { { -INT32_C(    14264092), -INT32_C(  1538342552) },
      { -INT32_C(  2004287433),  INT32_C(   159421386) },
      { -INT32_C(    14264092), -INT32_C(  2004287433) } },
    { {  INT32_C(  1762677502), -INT32_C(  1375919208) },
      {  INT32_C(   363666710), -INT32_C(   625342986) },
      {  INT32_C(  1762677502),  INT32_C(   363666710) } },
    { { -INT32_C(   975511203), -INT32_C(   647419742) },
      { -INT32_C(   211684568), -INT32_C(  2063801978) },
      { -INT32_C(   975511203), -INT32_C(   211684568) } },
    { { -INT32_C(   873657293),  INT32_C(  1182329647) },
      { -INT32_C(    27581176), -INT32_C(  1999039189) },
      { -INT32_C(   873657293), -INT32_C(    27581176) } },
    { { -INT32_C(  1739672586),  INT32_C(    74561499) },
      {  INT32_C(   821547946), -INT32_C(   390728780) },
      { -INT32_C(  1739672586),  INT32_C(   821547946) } },
    { {  INT32_C(   783524607), -INT32_C(  1787548531) },
      {  INT32_C(  2090127185), -INT32_C(   620401179) },
      {  INT32_C(   783524607),  INT32_C(  2090127185) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vtrn1_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(180), UINT8_C(234), UINT8_C( 38), UINT8_C(184), UINT8_C(112), UINT8_C( 40), UINT8_C(124), UINT8_C( 20) },
      { UINT8_C( 30), UINT8_C(250), UINT8_C( 91), UINT8_C( 78), UINT8_C(166), UINT8_C(229), UINT8_C(128), UINT8_C(117) },
      { UINT8_C(180), UINT8_C( 30), UINT8_C( 38), UINT8_C( 91), UINT8_C(112), UINT8_C(166), UINT8_C(124), UINT8_C(128) } },
    { { UINT8_C( 51), UINT8_C(233), UINT8_C(232), UINT8_C( 60), UINT8_C(220), UINT8_C( 27), UINT8_C(182), UINT8_C(252) },
      { UINT8_C( 75), UINT8_C( 64), UINT8_C(212), UINT8_C(237), UINT8_C( 88), UINT8_C( 50), UINT8_C( 94), UINT8_C( 12) },
      { UINT8_C( 51), UINT8_C( 75), UINT8_C(232), UINT8_C(212), UINT8_C(220), UINT8_C( 88), UINT8_C(182), UINT8_C( 94) } },
    { { UINT8_C( 28), UINT8_C(133), UINT8_C(196), UINT8_C(140), UINT8_C(173), UINT8_C( 64), UINT8_C(161), UINT8_C(204) },
      { UINT8_C( 59), UINT8_C(252), UINT8_C( 26), UINT8_C(225), UINT8_C(225), UINT8_C(154), UINT8_C( 86), UINT8_C( 21) },
      { UINT8_C( 28), UINT8_C( 59), UINT8_C(196), UINT8_C( 26), UINT8_C(173), UINT8_C(225), UINT8_C(161), UINT8_C( 86) } },
    { { UINT8_C(132), UINT8_C( 62), UINT8_C( 81), UINT8_C( 96), UINT8_C( 89), UINT8_C(  7), UINT8_C( 92), UINT8_C(164) },
      { UINT8_C( 71), UINT8_C( 49), UINT8_C(145), UINT8_C(159), UINT8_C( 99), UINT8_C(240), UINT8_C(171), UINT8_C(127) },
      { UINT8_C(132), UINT8_C( 71), UINT8_C( 81), UINT8_C(145), UINT8_C( 89), UINT8_C( 99), UINT8_C( 92), UINT8_C(171) } },
    { { UINT8_C(117), UINT8_C(111), UINT8_C( 12), UINT8_C( 34), UINT8_C(176), UINT8_C(173), UINT8_C(238), UINT8_C(235) },
      { UINT8_C(169), UINT8_C(  9), UINT8_C(204), UINT8_C(138), UINT8_C(163), UINT8_C( 34), UINT8_C(159), UINT8_C( 39) },
      { UINT8_C(117), UINT8_C(169), UINT8_C( 12), UINT8_C(204), UINT8_C(176), UINT8_C(163), UINT8_C(238), UINT8_C(159) } },
    { { UINT8_C( 97), UINT8_C(240), UINT8_C(136), UINT8_C(186), UINT8_C(247), UINT8_C(228), UINT8_C( 95), UINT8_C( 62) },
      { UINT8_C( 21), UINT8_C(240), UINT8_C(221), UINT8_C(120), UINT8_C(224), UINT8_C(136), UINT8_C(248), UINT8_C( 85) },
      { UINT8_C( 97), UINT8_C( 21), UINT8_C(136), UINT8_C(221), UINT8_C(247), UINT8_C(224), UINT8_C( 95), UINT8_C(248) } },
    { { UINT8_C(248), UINT8_C(  4), UINT8_C(120), UINT8_C(168), UINT8_C(177), UINT8_C(102), UINT8_C(147), UINT8_C( 90) },
      { UINT8_C(111), UINT8_C( 95), UINT8_C(228), UINT8_C( 19), UINT8_C(129), UINT8_C(132), UINT8_C( 58), UINT8_C(226) },
      { UINT8_C(248), UINT8_C(111), UINT8_C(120), UINT8_C(228), UINT8_C(177), UINT8_C(129), UINT8_C(147), UINT8_C( 58) } },
    { { UINT8_C(116), UINT8_C(194), UINT8_C(157), UINT8_C(108), UINT8_C(167), UINT8_C(252), UINT8_C(170), UINT8_C(188) },
      { UINT8_C(236), UINT8_C(136), UINT8_C( 53), UINT8_C(205), UINT8_C( 16), UINT8_C( 45), UINT8_C( 34), UINT8_C(  8) },
      { UINT8_C(116), UINT8_C(236), UINT8_C(157), UINT8_C( 53), UINT8_C(167), UINT8_C( 16), UINT8_C(170), UINT8_C( 34) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vtrn1_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(60788), UINT16_C(40466), UINT16_C(30557), UINT16_C(47308) },
      { UINT16_C(27512), UINT16_C( 3061), UINT16_C(41915), UINT16_C(15633) },
      { UINT16_C(60788), UINT16_C(27512), UINT16_C(30557), UINT16_C(41915) } },
    { { UINT16_C(31826), UINT16_C(40911), UINT16_C(11794), UINT16_C( 5983) },
      { UINT16_C(15515), UINT16_C(15720), UINT16_C(44460), UINT16_C( 8198) },
      { UINT16_C(31826), UINT16_C(15515), UINT16_C(11794), UINT16_C(44460) } },
    { { UINT16_C( 6298), UINT16_C(63678), UINT16_C(35471), UINT16_C( 1968) },
      { UINT16_C(42485), UINT16_C(45331), UINT16_C( 9289), UINT16_C(39918) },
      { UINT16_C( 6298), UINT16_C(42485), UINT16_C(35471), UINT16_C( 9289) } },
    { { UINT16_C(48544), UINT16_C(45627), UINT16_C(39659), UINT16_C(34762) },
      { UINT16_C(13015), UINT16_C(33732), UINT16_C(51936), UINT16_C(31395) },
      { UINT16_C(48544), UINT16_C(13015), UINT16_C(39659), UINT16_C(51936) } },
    { { UINT16_C(25058), UINT16_C(29298), UINT16_C( 8940), UINT16_C(57721) },
      { UINT16_C(36040), UINT16_C( 4498), UINT16_C(32944), UINT16_C(20908) },
      { UINT16_C(25058), UINT16_C(36040), UINT16_C( 8940), UINT16_C(32944) } },
    { { UINT16_C(59197), UINT16_C(10499), UINT16_C(52610), UINT16_C(22960) },
      { UINT16_C(29696), UINT16_C(57564), UINT16_C(32575), UINT16_C( 8538) },
      { UINT16_C(59197), UINT16_C(29696), UINT16_C(52610), UINT16_C(32575) } },
    { { UINT16_C(52704), UINT16_C(52371), UINT16_C( 3567), UINT16_C(47022) },
      { UINT16_C(16537), UINT16_C(19144), UINT16_C(30145), UINT16_C(65179) },
      { UINT16_C(52704), UINT16_C(16537), UINT16_C( 3567), UINT16_C(30145) } },
    { { UINT16_C(40540), UINT16_C(56871), UINT16_C(55148), UINT16_C(27703) },
      { UINT16_C( 4940), UINT16_C(35660), UINT16_C(42642), UINT16_C(29612) },
      { UINT16_C(40540), UINT16_C( 4940), UINT16_C(55148), UINT16_C(42642) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vtrn1_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 434122982), UINT32_C(2452681820) },
      { UINT32_C(2633101907), UINT32_C(3594086343) },
      { UINT32_C( 434122982), UINT32_C(2633101907) } },
    { { UINT32_C(3976061469), UINT32_C(1299237744) },
      { UINT32_C(3511335039), UINT32_C(2688013498) },
      { UINT32_C(3976061469), UINT32_C(3511335039) } },
    { { UINT32_C(1622808580), UINT32_C(1626532364) },
      { UINT32_C(2768036828), UINT32_C(1736062282) },
      { UINT32_C(1622808580), UINT32_C(2768036828) } },
    { { UINT32_C(2270394135), UINT32_C(3251946562) },
      { UINT32_C( 915545980), UINT32_C(4158049011) },
      { UINT32_C(2270394135), UINT32_C( 915545980) } },
    { { UINT32_C(3998716130), UINT32_C(1464748410) },
      { UINT32_C(1996180012), UINT32_C(2547873151) },
      { UINT32_C(3998716130), UINT32_C(1996180012) } },
    { { UINT32_C( 773730540), UINT32_C(1894773748) },
      { UINT32_C(  94798354), UINT32_C( 788299084) },
      { UINT32_C( 773730540), UINT32_C(  94798354) } },
    { { UINT32_C(2283557645), UINT32_C(3370085276) },
      { UINT32_C( 893311669), UINT32_C(1003232079) },
      { UINT32_C(2283557645), UINT32_C( 893311669) } },
    { { UINT32_C(1080683083), UINT32_C(4021311709) },
      { UINT32_C( 653547482), UINT32_C(3780440276) },
      { UINT32_C(1080683083), UINT32_C( 653547482) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vtrn1_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1q_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -522.18), SIMDE_FLOAT32_C(   365.36), SIMDE_FLOAT32_C(  -879.25), SIMDE_FLOAT32_C(  -911.32) },
      { SIMDE_FLOAT32_C(   508.26), SIMDE_FLOAT32_C(   535.56), SIMDE_FLOAT32_C(  -927.14), SIMDE_FLOAT32_C(  -145.00) },
      { SIMDE_FLOAT32_C(  -522.18), SIMDE_FLOAT32_C(   508.26), SIMDE_FLOAT32_C(  -879.25), SIMDE_FLOAT32_C(  -927.14) } },
    { { SIMDE_FLOAT32_C(  -644.24), SIMDE_FLOAT32_C(   758.58), SIMDE_FLOAT32_C(   592.05), SIMDE_FLOAT32_C(   670.85) },
      { SIMDE_FLOAT32_C(   408.23), SIMDE_FLOAT32_C(  -493.59), SIMDE_FLOAT32_C(  -660.12), SIMDE_FLOAT32_C(   163.68) },
      { SIMDE_FLOAT32_C(  -644.24), SIMDE_FLOAT32_C(   408.23), SIMDE_FLOAT32_C(   592.05), SIMDE_FLOAT32_C(  -660.12) } },
    { { SIMDE_FLOAT32_C(  -787.94), SIMDE_FLOAT32_C(  -882.32), SIMDE_FLOAT32_C(   367.24), SIMDE_FLOAT32_C(   -16.83) },
      { SIMDE_FLOAT32_C(  -482.56), SIMDE_FLOAT32_C(   -96.42), SIMDE_FLOAT32_C(  -722.75), SIMDE_FLOAT32_C(  -446.06) },
      { SIMDE_FLOAT32_C(  -787.94), SIMDE_FLOAT32_C(  -482.56), SIMDE_FLOAT32_C(   367.24), SIMDE_FLOAT32_C(  -722.75) } },
    { { SIMDE_FLOAT32_C(   -23.04), SIMDE_FLOAT32_C(   914.12), SIMDE_FLOAT32_C(   495.70), SIMDE_FLOAT32_C(   665.01) },
      { SIMDE_FLOAT32_C(   292.03), SIMDE_FLOAT32_C(  -265.04), SIMDE_FLOAT32_C(   537.61), SIMDE_FLOAT32_C(   769.84) },
      { SIMDE_FLOAT32_C(   -23.04), SIMDE_FLOAT32_C(   292.03), SIMDE_FLOAT32_C(   495.70), SIMDE_FLOAT32_C(   537.61) } },
    { { SIMDE_FLOAT32_C(  -899.68), SIMDE_FLOAT32_C(   658.36), SIMDE_FLOAT32_C(   858.52), SIMDE_FLOAT32_C(   608.58) },
      { SIMDE_FLOAT32_C(   193.92), SIMDE_FLOAT32_C(   931.38), SIMDE_FLOAT32_C(  -536.43), SIMDE_FLOAT32_C(   549.69) },
      { SIMDE_FLOAT32_C(  -899.68), SIMDE_FLOAT32_C(   193.92), SIMDE_FLOAT32_C(   858.52), SIMDE_FLOAT32_C(  -536.43) } },
    { { SIMDE_FLOAT32_C(   689.97), SIMDE_FLOAT32_C(  -944.37), SIMDE_FLOAT32_C(   220.54), SIMDE_FLOAT32_C(    98.20) },
      { SIMDE_FLOAT32_C(  -437.96), SIMDE_FLOAT32_C(   560.42), SIMDE_FLOAT32_C(  -738.12), SIMDE_FLOAT32_C(  -225.90) },
      { SIMDE_FLOAT32_C(   689.97), SIMDE_FLOAT32_C(  -437.96), SIMDE_FLOAT32_C(   220.54), SIMDE_FLOAT32_C(  -738.12) } },
    { { SIMDE_FLOAT32_C(   678.09), SIMDE_FLOAT32_C(   629.12), SIMDE_FLOAT32_C(   757.27), SIMDE_FLOAT32_C(  -804.46) },
      { SIMDE_FLOAT32_C(  -467.30), SIMDE_FLOAT32_C(  -965.48), SIMDE_FLOAT32_C(  -250.52), SIMDE_FLOAT32_C(   509.67) },
      { SIMDE_FLOAT32_C(   678.09), SIMDE_FLOAT32_C(  -467.30), SIMDE_FLOAT32_C(   757.27), SIMDE_FLOAT32_C(  -250.52) } },
    { { SIMDE_FLOAT32_C(   948.64), SIMDE_FLOAT32_C(  -754.82), SIMDE_FLOAT32_C(   174.67), SIMDE_FLOAT32_C(   240.67) },
      { SIMDE_FLOAT32_C(   -19.85), SIMDE_FLOAT32_C(  -287.72), SIMDE_FLOAT32_C(    10.52), SIMDE_FLOAT32_C(    80.47) },
      { SIMDE_FLOAT32_C(   948.64), SIMDE_FLOAT32_C(   -19.85), SIMDE_FLOAT32_C(   174.67), SIMDE_FLOAT32_C(    10.52) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vtrn1q_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vtrn1q_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -499.12), SIMDE_FLOAT64_C(  -611.84) },
      { SIMDE_FLOAT64_C(   618.92), SIMDE_FLOAT64_C(  -353.88) },
      { SIMDE_FLOAT64_C(  -499.12), SIMDE_FLOAT64_C(   618.92) } },
    { { SIMDE_FLOAT64_C(   542.91), SIMDE_FLOAT64_C(   443.42) },
      { SIMDE_FLOAT64_C(  -774.93), SIMDE_FLOAT64_C(   219.66) },
      { SIMDE_FLOAT64_C(   542.91), SIMDE_FLOAT64_C(  -774.93) } },
    { { SIMDE_FLOAT64_C(    43.30), SIMDE_FLOAT64_C(   437.28) },
      { SIMDE_FLOAT64_C(   412.68), SIMDE_FLOAT64_C(  -401.41) },
      { SIMDE_FLOAT64_C(    43.30), SIMDE_FLOAT64_C(   412.68) } },
    { { SIMDE_FLOAT64_C(   823.43), SIMDE_FLOAT64_C(   254.13) },
      { SIMDE_FLOAT64_C(  -356.45), SIMDE_FLOAT64_C(   862.90) },
      { SIMDE_FLOAT64_C(   823.43), SIMDE_FLOAT64_C(  -356.45) } },
    { { SIMDE_FLOAT64_C(   -30.73), SIMDE_FLOAT64_C(   631.32) },
      { SIMDE_FLOAT64_C(   321.40), SIMDE_FLOAT64_C(   984.72) },
      { SIMDE_FLOAT64_C(   -30.73), SIMDE_FLOAT64_C(   321.40) } },
    { { SIMDE_FLOAT64_C(   283.84), SIMDE_FLOAT64_C(  -391.31) },
      { SIMDE_FLOAT64_C(   957.98), SIMDE_FLOAT64_C(   515.26) },
      { SIMDE_FLOAT64_C(   283.84), SIMDE_FLOAT64_C(   957.98) } },
    { { SIMDE_FLOAT64_C(  -327.25), SIMDE_FLOAT64_C(  -666.99) },
      { SIMDE_FLOAT64_C(  -844.37), SIMDE_FLOAT64_C(  -877.10) },
      { SIMDE_FLOAT64_C(  -327.25), SIMDE_FLOAT64_C(  -844.37) } },
    { { SIMDE_FLOAT64_C(   397.41), SIMDE_FLOAT64_C(  -596.55) },
      { SIMDE_FLOAT64_C(   732.55), SIMDE_FLOAT64_C(   898.29) },
      { SIMDE_FLOAT64_C(   397.41), SIMDE_FLOAT64_C(   732.55) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vtrn1q_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vtrn1q_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(   5),  INT8_C(  91), -INT8_C(  64), -INT8_C(  51), -INT8_C(  31), -INT8_C( 105), -INT8_C(  45),  INT8_C(  96),
         INT8_C(   5), -INT8_C( 120),  INT8_C(  11),  INT8_C(  81), -INT8_C(  40),  INT8_C(  33),  INT8_C( 126), -INT8_C(  48) },
      { -INT8_C(   4), -INT8_C(  12),  INT8_C(  64), -INT8_C(  88),  INT8_C(  17),  INT8_C(  67), -INT8_C(  83),  INT8_C( 106),
         INT8_C(  71), -INT8_C( 114),  INT8_C(   1),  INT8_C(  60),  INT8_C(  54),  INT8_C(  81),  INT8_C( 123),  INT8_C(  49) },
      { -INT8_C(   5), -INT8_C(   4), -INT8_C(  64),  INT8_C(  64), -INT8_C(  31),  INT8_C(  17), -INT8_C(  45), -INT8_C(  83),
         INT8_C(   5),  INT8_C(  71),  INT8_C(  11),  INT8_C(   1), -INT8_C(  40),  INT8_C(  54),  INT8_C( 126),  INT8_C( 123) } },
    { { -INT8_C(  84),  INT8_C(  59), -INT8_C(   2), -INT8_C( 115), -INT8_C(  46), -INT8_C(  47), -INT8_C(  19), -INT8_C(  40),
         INT8_C(  89), -INT8_C(   8),  INT8_C(  41),  INT8_C(  50),  INT8_C(  25), -INT8_C(  89),  INT8_C(   2),  INT8_C(  21) },
      { -INT8_C( 101),  INT8_C(  67), -INT8_C(  67), -INT8_C(  83), -INT8_C( 122),  INT8_C( 107),  INT8_C(  23), -INT8_C(  50),
        -INT8_C(   7),  INT8_C(  25),  INT8_C(  10),  INT8_C(  47),  INT8_C( 106), -INT8_C( 123),  INT8_C(  97),  INT8_C(  22) },
      { -INT8_C(  84), -INT8_C( 101), -INT8_C(   2), -INT8_C(  67), -INT8_C(  46), -INT8_C( 122), -INT8_C(  19),  INT8_C(  23),
         INT8_C(  89), -INT8_C(   7),  INT8_C(  41),  INT8_C(  10),  INT8_C(  25),  INT8_C( 106),  INT8_C(   2),  INT8_C(  97) } },
    { { -INT8_C(  64),  INT8_C(  95), -INT8_C(  93), -INT8_C( 110),  INT8_C(  49), -INT8_C( 111),  INT8_C( 106), -INT8_C( 118),
        -INT8_C( 119), -INT8_C( 109), -INT8_C(  68), -INT8_C(  93),  INT8_C(  59), -INT8_C(  65), -INT8_C(  72), -INT8_C(  42) },
      {  INT8_C(   2),  INT8_C( 118), -INT8_C( 125), -INT8_C( 120), -INT8_C(  31), -INT8_C( 101),  INT8_C(  86), -INT8_C(  38),
        -INT8_C(  76),  INT8_C(  96),  INT8_C(   9),  INT8_C(  30), -INT8_C(  27),  INT8_C( 106),  INT8_C(  52), -INT8_C(  91) },
      { -INT8_C(  64),  INT8_C(   2), -INT8_C(  93), -INT8_C( 125),  INT8_C(  49), -INT8_C(  31),  INT8_C( 106),  INT8_C(  86),
        -INT8_C( 119), -INT8_C(  76), -INT8_C(  68),  INT8_C(   9),  INT8_C(  59), -INT8_C(  27), -INT8_C(  72),  INT8_C(  52) } },
    { { -INT8_C(  54), -INT8_C(  41),  INT8_C(  56), -INT8_C(   5),  INT8_C( 104), -INT8_C(  94), -INT8_C( 123), -INT8_C(  14),
         INT8_C(  54),  INT8_C(  66), -INT8_C( 107),  INT8_C( 113),  INT8_C(   1),  INT8_C(  77),  INT8_C(  71),  INT8_C(   3) },
      { -INT8_C(  61), -INT8_C(  53), -INT8_C( 117), -INT8_C(  92),  INT8_C( 102), -INT8_C(  30),  INT8_C( 126),  INT8_C(  26),
         INT8_C(  66), -INT8_C( 120),  INT8_C(  56),  INT8_C(  40), -INT8_C(  14),  INT8_C( 108), -INT8_C(  51), -INT8_C(  68) },
      { -INT8_C(  54), -INT8_C(  61),  INT8_C(  56), -INT8_C( 117),  INT8_C( 104),  INT8_C( 102), -INT8_C( 123),  INT8_C( 126),
         INT8_C(  54),  INT8_C(  66), -INT8_C( 107),  INT8_C(  56),  INT8_C(   1), -INT8_C(  14),  INT8_C(  71), -INT8_C(  51) } },
    { {  INT8_C(  67),  INT8_C(   5), -INT8_C(  73), -INT8_C(  84), -INT8_C(  88),  INT8_C(  61), -INT8_C(  98), -INT8_C(  34),
             INT8_MAX,  INT8_C(  51),  INT8_C(  79),      INT8_MIN,      INT8_MIN, -INT8_C( 106), -INT8_C( 125),  INT8_C(  68) },
      {  INT8_C(  97),  INT8_C(  14), -INT8_C(  24), -INT8_C(  57), -INT8_C(  16),  INT8_C( 103), -INT8_C(  31),  INT8_C(  51),
        -INT8_C(  17),  INT8_C(  25),  INT8_C(  91), -INT8_C(  31), -INT8_C( 123),  INT8_C(  40), -INT8_C(  98), -INT8_C(  55) },
      {  INT8_C(  67),  INT8_C(  97), -INT8_C(  73), -INT8_C(  24), -INT8_C(  88), -INT8_C(  16), -INT8_C(  98), -INT8_C(  31),
             INT8_MAX, -INT8_C(  17),  INT8_C(  79),  INT8_C(  91),      INT8_MIN, -INT8_C( 123), -INT8_C( 125), -INT8_C(  98) } },
    { {  INT8_C(  46),  INT8_C(  85),  INT8_C( 117), -INT8_C(  42), -INT8_C( 110),  INT8_C(  19), -INT8_C(  76),  INT8_C(  17),
         INT8_C(  70),  INT8_C(   3), -INT8_C( 111), -INT8_C(  58), -INT8_C( 103),  INT8_C(  20),  INT8_C(  10), -INT8_C(   5) },
      {  INT8_C(  35), -INT8_C(  13), -INT8_C(  62),  INT8_C(  19),  INT8_C(  90), -INT8_C(  92),  INT8_C(  70),  INT8_C(  73),
        -INT8_C(  67), -INT8_C(  95),  INT8_C(  42),  INT8_C(  67), -INT8_C(  54), -INT8_C(  56),  INT8_C(  12), -INT8_C(   8) },
      {  INT8_C(  46),  INT8_C(  35),  INT8_C( 117), -INT8_C(  62), -INT8_C( 110),  INT8_C(  90), -INT8_C(  76),  INT8_C(  70),
         INT8_C(  70), -INT8_C(  67), -INT8_C( 111),  INT8_C(  42), -INT8_C( 103), -INT8_C(  54),  INT8_C(  10),  INT8_C(  12) } },
    { {  INT8_C(  30), -INT8_C( 127), -INT8_C(  50), -INT8_C(  80), -INT8_C( 108), -INT8_C( 126), -INT8_C(  62), -INT8_C(  38),
        -INT8_C( 123),  INT8_C(  83), -INT8_C(  96),  INT8_C(  30),  INT8_C( 104), -INT8_C(  85),  INT8_C(  25), -INT8_C( 117) },
      { -INT8_C(  98), -INT8_C(  36), -INT8_C(  98), -INT8_C(   8),      INT8_MIN, -INT8_C(  27),  INT8_C(  65),  INT8_C(  61),
        -INT8_C( 122),  INT8_C( 107),      INT8_MIN,  INT8_C(  80),  INT8_C(  52), -INT8_C( 116),  INT8_C(  72),  INT8_C(  82) },
      {  INT8_C(  30), -INT8_C(  98), -INT8_C(  50), -INT8_C(  98), -INT8_C( 108),      INT8_MIN, -INT8_C(  62),  INT8_C(  65),
        -INT8_C( 123), -INT8_C( 122), -INT8_C(  96),      INT8_MIN,  INT8_C( 104),  INT8_C(  52),  INT8_C(  25),  INT8_C(  72) } },
    { {  INT8_C(  13),  INT8_C(  22),  INT8_C(   2), -INT8_C(  95), -INT8_C( 104), -INT8_C(  60),  INT8_C( 123),  INT8_C(  29),
         INT8_C(  24),  INT8_C(  28),  INT8_C(  60),      INT8_MIN, -INT8_C(  57),  INT8_C(  85),  INT8_C(  11),  INT8_C( 101) },
      {  INT8_C(  49), -INT8_C(  87),  INT8_C(  93), -INT8_C(  79), -INT8_C( 114), -INT8_C(  98), -INT8_C(  17),  INT8_C(  21),
         INT8_C(   9),  INT8_C( 111),  INT8_C( 101),  INT8_C(  61), -INT8_C(   4), -INT8_C(  82), -INT8_C( 113),  INT8_C(   9) },
      {  INT8_C(  13),  INT8_C(  49),  INT8_C(   2),  INT8_C(  93), -INT8_C( 104), -INT8_C( 114),  INT8_C( 123), -INT8_C(  17),
         INT8_C(  24),  INT8_C(   9),  INT8_C(  60),  INT8_C( 101), -INT8_C(  57), -INT8_C(   4),  INT8_C(  11), -INT8_C( 113) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vtrn1q_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1q_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 14817), -INT16_C( 15912),  INT16_C(  6827), -INT16_C( 16841), -INT16_C( 15885),  INT16_C(  6412),  INT16_C( 12676),  INT16_C( 26747) },
      {  INT16_C( 31336),  INT16_C( 23842),  INT16_C( 32211), -INT16_C( 23641),  INT16_C( 22041), -INT16_C( 28634), -INT16_C(  6631), -INT16_C(  1058) },
      {  INT16_C( 14817),  INT16_C( 31336),  INT16_C(  6827),  INT16_C( 32211), -INT16_C( 15885),  INT16_C( 22041),  INT16_C( 12676), -INT16_C(  6631) } },
    { { -INT16_C( 18913), -INT16_C( 13636), -INT16_C(  3119), -INT16_C( 15224), -INT16_C( 27468),  INT16_C( 14558),  INT16_C( 22981),  INT16_C( 11680) },
      { -INT16_C( 15405), -INT16_C( 22902),  INT16_C( 12864),  INT16_C( 22857),  INT16_C( 28552), -INT16_C( 24086), -INT16_C( 14251),  INT16_C( 29852) },
      { -INT16_C( 18913), -INT16_C( 15405), -INT16_C(  3119),  INT16_C( 12864), -INT16_C( 27468),  INT16_C( 28552),  INT16_C( 22981), -INT16_C( 14251) } },
    { {  INT16_C( 22655),  INT16_C( 20543), -INT16_C( 14517),  INT16_C(    20), -INT16_C(  3492),  INT16_C(  8504), -INT16_C(  9908),  INT16_C(  8015) },
      { -INT16_C(  9828), -INT16_C(  9018),  INT16_C(  3851), -INT16_C( 27850),  INT16_C(  8319), -INT16_C( 11211), -INT16_C( 11800),  INT16_C( 26441) },
      {  INT16_C( 22655), -INT16_C(  9828), -INT16_C( 14517),  INT16_C(  3851), -INT16_C(  3492),  INT16_C(  8319), -INT16_C(  9908), -INT16_C( 11800) } },
    { { -INT16_C( 30678),  INT16_C( 30135), -INT16_C( 13233), -INT16_C( 21643), -INT16_C( 20802),  INT16_C(  2765),  INT16_C(  7303),  INT16_C(  9002) },
      { -INT16_C(  3851),  INT16_C(   511),  INT16_C( 13823),  INT16_C( 32404), -INT16_C( 13995),  INT16_C( 15955), -INT16_C( 25445), -INT16_C( 14939) },
      { -INT16_C( 30678), -INT16_C(  3851), -INT16_C( 13233),  INT16_C( 13823), -INT16_C( 20802), -INT16_C( 13995),  INT16_C(  7303), -INT16_C( 25445) } },
    { {  INT16_C( 23844),  INT16_C( 29498), -INT16_C( 20439), -INT16_C(  6369), -INT16_C(  5026), -INT16_C(  6670),  INT16_C(  7176), -INT16_C(   760) },
      {  INT16_C(  1804),  INT16_C(  3070), -INT16_C( 27843), -INT16_C( 28022), -INT16_C(  8868), -INT16_C(  2096),  INT16_C( 30329), -INT16_C( 25156) },
      {  INT16_C( 23844),  INT16_C(  1804), -INT16_C( 20439), -INT16_C( 27843), -INT16_C(  5026), -INT16_C(  8868),  INT16_C(  7176),  INT16_C( 30329) } },
    { { -INT16_C(  2093), -INT16_C(  1008),  INT16_C( 12199),  INT16_C(  1507), -INT16_C( 10981),  INT16_C(  9194), -INT16_C(  3343), -INT16_C(   735) },
      {  INT16_C(  8185),  INT16_C( 13833), -INT16_C( 27726),  INT16_C(  4041), -INT16_C( 26256), -INT16_C(  5882), -INT16_C( 15601), -INT16_C(  7546) },
      { -INT16_C(  2093),  INT16_C(  8185),  INT16_C( 12199), -INT16_C( 27726), -INT16_C( 10981), -INT16_C( 26256), -INT16_C(  3343), -INT16_C( 15601) } },
    { { -INT16_C( 26950),  INT16_C( 25054), -INT16_C( 15674), -INT16_C(  7834),  INT16_C( 20631), -INT16_C( 30459),  INT16_C(  9794),  INT16_C( 15238) },
      { -INT16_C( 28859), -INT16_C(  1934),  INT16_C( 15138), -INT16_C( 28153),  INT16_C(  3540), -INT16_C(  7045),  INT16_C(   464), -INT16_C( 30010) },
      { -INT16_C( 26950), -INT16_C( 28859), -INT16_C( 15674),  INT16_C( 15138),  INT16_C( 20631),  INT16_C(  3540),  INT16_C(  9794),  INT16_C(   464) } },
    { { -INT16_C( 23144),  INT16_C( 24299),  INT16_C( 20839), -INT16_C(   449),  INT16_C( 17569), -INT16_C(  7289),  INT16_C(  3690), -INT16_C( 20449) },
      { -INT16_C( 28259), -INT16_C( 16216), -INT16_C( 20532), -INT16_C( 24494), -INT16_C( 12612), -INT16_C( 29308),  INT16_C( 19407),  INT16_C( 26391) },
      { -INT16_C( 23144), -INT16_C( 28259),  INT16_C( 20839), -INT16_C( 20532),  INT16_C( 17569), -INT16_C( 12612),  INT16_C(  3690),  INT16_C( 19407) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vtrn1q_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1q_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1341418916),  INT32_C(   777003733), -INT32_C(  1026009579),  INT32_C(  1018759377) },
      { -INT32_C(   587710840), -INT32_C(  1130803257),  INT32_C(   296467978),  INT32_C(   730158286) },
      { -INT32_C(  1341418916), -INT32_C(   587710840), -INT32_C(  1026009579),  INT32_C(   296467978) } },
    { { -INT32_C(  1126461209), -INT32_C(   924111949),  INT32_C(  1401668482),  INT32_C(  1418675403) },
      {  INT32_C(  1227917186), -INT32_C(   536426026),  INT32_C(  1441902983), -INT32_C(   310348026) },
      { -INT32_C(  1126461209),  INT32_C(  1227917186),  INT32_C(  1401668482),  INT32_C(  1441902983) } },
    { { -INT32_C(  1163306233),  INT32_C(   159618183),  INT32_C(   593235544), -INT32_C(   730338478) },
      {  INT32_C(  1209968498), -INT32_C(   148364176), -INT32_C(   615704107), -INT32_C(  1731670640) },
      { -INT32_C(  1163306233),  INT32_C(  1209968498),  INT32_C(   593235544), -INT32_C(   615704107) } },
    { { -INT32_C(  1336774103),  INT32_C(  1589236998),  INT32_C(   897717731),  INT32_C(  1913321728) },
      {  INT32_C(   297412769),  INT32_C(   554295884), -INT32_C(  1929554181),  INT32_C(  1277478179) },
      { -INT32_C(  1336774103),  INT32_C(   297412769),  INT32_C(   897717731), -INT32_C(  1929554181) } },
    { {  INT32_C(  1056732727),  INT32_C(   798799180), -INT32_C(   899342646), -INT32_C(  1187221736) },
      { -INT32_C(   473237865), -INT32_C(   737881128),  INT32_C(  1298137385), -INT32_C(    23493433) },
      {  INT32_C(  1056732727), -INT32_C(   473237865), -INT32_C(   899342646),  INT32_C(  1298137385) } },
    { {  INT32_C(  1178375930),  INT32_C(   376887627),  INT32_C(   266394615), -INT32_C(   506978998) },
      { -INT32_C(   322661613), -INT32_C(  1866413978), -INT32_C(  1847779126), -INT32_C(  1634765148) },
      {  INT32_C(  1178375930), -INT32_C(   322661613),  INT32_C(   266394615), -INT32_C(  1847779126) } },
    { {  INT32_C(  1491454988), -INT32_C(  1670489179), -INT32_C(  2136191434),  INT32_C(  2137093227) },
      {  INT32_C(  1852515591), -INT32_C(  1208079379), -INT32_C(   280437941),  INT32_C(  1586354257) },
      {  INT32_C(  1491454988),  INT32_C(  1852515591), -INT32_C(  2136191434), -INT32_C(   280437941) } },
    { {  INT32_C(  1236693668),  INT32_C(    65348813), -INT32_C(   561802894),  INT32_C(   224257030) },
      { -INT32_C(   142882807),  INT32_C(  1051621875), -INT32_C(  1506937004),  INT32_C(  1929689807) },
      {  INT32_C(  1236693668), -INT32_C(   142882807), -INT32_C(   561802894), -INT32_C(  1506937004) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vtrn1q_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1q_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 2370942768217045703),  INT64_C( 3834060604335488599) },
      {  INT64_C( 5962793575161641133),  INT64_C( 2451362664542500656) },
      {  INT64_C( 2370942768217045703),  INT64_C( 5962793575161641133) } },
    { { -INT64_C(   91528125595492425),  INT64_C( 8454808771016685138) },
      {  INT64_C( 1997428809620116027),  INT64_C( 2503757759122402625) },
      { -INT64_C(   91528125595492425),  INT64_C( 1997428809620116027) } },
    { { -INT64_C( 3375599107157742718),  INT64_C( 3758894877307401709) },
      {  INT64_C( 4548726874596619289), -INT64_C( 2068388762230178113) },
      { -INT64_C( 3375599107157742718),  INT64_C( 4548726874596619289) } },
    { {  INT64_C( 7752440428129683270), -INT64_C( 1741121954605135960) },
      { -INT64_C( 9134413012119359234), -INT64_C(  464162460032952246) },
      {  INT64_C( 7752440428129683270), -INT64_C( 9134413012119359234) } },
    { {  INT64_C( 8495572088113830653),  INT64_C( 5733906210614609629) },
      { -INT64_C( 3197405612916048547),  INT64_C( 4488976398999767712) },
      {  INT64_C( 8495572088113830653), -INT64_C( 3197405612916048547) } },
    { {  INT64_C( 4533049365362183078),  INT64_C( 5280325345817001894) },
      { -INT64_C( 4948321176345078792), -INT64_C( 8876213478574075309) },
      {  INT64_C( 4533049365362183078), -INT64_C( 4948321176345078792) } },
    { { -INT64_C( 3385053066255955098),  INT64_C( 6995515642783330015) },
      { -INT64_C( 2776126643429474653),  INT64_C( 5146839089142400778) },
      { -INT64_C( 3385053066255955098), -INT64_C( 2776126643429474653) } },
    { {  INT64_C( 2649826617627403465),  INT64_C( 4813228284004306689) },
      { -INT64_C( 1088892655976271997),  INT64_C( 6352686333166178304) },
      {  INT64_C( 2649826617627403465), -INT64_C( 1088892655976271997) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vtrn1q_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1q_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 32), UINT8_C(105), UINT8_C( 60), UINT8_C( 17), UINT8_C(121), UINT8_C(145), UINT8_C( 45), UINT8_C(135),
        UINT8_C(225), UINT8_C( 38), UINT8_C(228), UINT8_C( 88), UINT8_C(200), UINT8_C(213), UINT8_C(147), UINT8_C(151) },
      { UINT8_C(177), UINT8_C(122), UINT8_C(147), UINT8_C( 63), UINT8_C(245), UINT8_C(244), UINT8_C(140), UINT8_C(165),
        UINT8_C(180), UINT8_C( 76), UINT8_C( 77), UINT8_C(249), UINT8_C( 12), UINT8_C( 91), UINT8_C( 53), UINT8_C( 45) },
      { UINT8_C( 32), UINT8_C(177), UINT8_C( 60), UINT8_C(147), UINT8_C(121), UINT8_C(245), UINT8_C( 45), UINT8_C(140),
        UINT8_C(225), UINT8_C(180), UINT8_C(228), UINT8_C( 77), UINT8_C(200), UINT8_C( 12), UINT8_C(147), UINT8_C( 53) } },
    { { UINT8_C(196), UINT8_C(113), UINT8_C( 62), UINT8_C( 61), UINT8_C(  2), UINT8_C(108), UINT8_C(196), UINT8_C(228),
        UINT8_C(146), UINT8_C(168), UINT8_C( 60), UINT8_C( 90), UINT8_C(126), UINT8_C(207), UINT8_C(241), UINT8_C( 47) },
      { UINT8_C( 73), UINT8_C(133), UINT8_C(110), UINT8_C( 62), UINT8_C(121), UINT8_C(251), UINT8_C(227), UINT8_C( 45),
        UINT8_C( 71), UINT8_C( 49), UINT8_C( 38), UINT8_C( 83), UINT8_C(140), UINT8_C( 91), UINT8_C(128), UINT8_C( 80) },
      { UINT8_C(196), UINT8_C( 73), UINT8_C( 62), UINT8_C(110), UINT8_C(  2), UINT8_C(121), UINT8_C(196), UINT8_C(227),
        UINT8_C(146), UINT8_C( 71), UINT8_C( 60), UINT8_C( 38), UINT8_C(126), UINT8_C(140), UINT8_C(241), UINT8_C(128) } },
    { { UINT8_C(204), UINT8_C(191), UINT8_C(141), UINT8_C(206), UINT8_C( 43), UINT8_C( 81), UINT8_C(178), UINT8_C(189),
        UINT8_C(250), UINT8_C(238), UINT8_C( 23), UINT8_C(120), UINT8_C(189), UINT8_C(  9), UINT8_C(167), UINT8_C(  7) },
      { UINT8_C(142), UINT8_C( 21), UINT8_C( 69), UINT8_C(  7), UINT8_C( 16), UINT8_C( 41), UINT8_C( 52), UINT8_C( 87),
        UINT8_C( 90), UINT8_C( 90), UINT8_C(171), UINT8_C(230), UINT8_C(181), UINT8_C( 43), UINT8_C( 54), UINT8_C(129) },
      { UINT8_C(204), UINT8_C(142), UINT8_C(141), UINT8_C( 69), UINT8_C( 43), UINT8_C( 16), UINT8_C(178), UINT8_C( 52),
        UINT8_C(250), UINT8_C( 90), UINT8_C( 23), UINT8_C(171), UINT8_C(189), UINT8_C(181), UINT8_C(167), UINT8_C( 54) } },
    { { UINT8_C(234), UINT8_C(195), UINT8_C( 79), UINT8_C( 21), UINT8_C( 20), UINT8_C(  2), UINT8_C(210), UINT8_C( 14),
        UINT8_C(240), UINT8_C(234), UINT8_C(134), UINT8_C(174), UINT8_C(243), UINT8_C( 45), UINT8_C(181), UINT8_C(129) },
      { UINT8_C( 67), UINT8_C(250), UINT8_C(136), UINT8_C( 83), UINT8_C( 35), UINT8_C(188), UINT8_C(171), UINT8_C(125),
        UINT8_C( 22), UINT8_C( 86), UINT8_C( 99), UINT8_C(203), UINT8_C(129), UINT8_C(153), UINT8_C( 76), UINT8_C(108) },
      { UINT8_C(234), UINT8_C( 67), UINT8_C( 79), UINT8_C(136), UINT8_C( 20), UINT8_C( 35), UINT8_C(210), UINT8_C(171),
        UINT8_C(240), UINT8_C( 22), UINT8_C(134), UINT8_C( 99), UINT8_C(243), UINT8_C(129), UINT8_C(181), UINT8_C( 76) } },
    { { UINT8_C( 92), UINT8_C(155), UINT8_C(129), UINT8_C(113), UINT8_C(157), UINT8_C( 84), UINT8_C(127), UINT8_C(142),
        UINT8_C( 62), UINT8_C(  6), UINT8_C( 60), UINT8_C( 49), UINT8_C( 51), UINT8_C(241), UINT8_C(178), UINT8_C(118) },
      { UINT8_C(235), UINT8_C( 58), UINT8_C(202), UINT8_C( 15), UINT8_C(246), UINT8_C(117), UINT8_C(140), UINT8_C( 12),
        UINT8_C(203), UINT8_C(240), UINT8_C(215), UINT8_C( 76), UINT8_C(137), UINT8_C( 35), UINT8_C(184), UINT8_C(230) },
      { UINT8_C( 92), UINT8_C(235), UINT8_C(129), UINT8_C(202), UINT8_C(157), UINT8_C(246), UINT8_C(127), UINT8_C(140),
        UINT8_C( 62), UINT8_C(203), UINT8_C( 60), UINT8_C(215), UINT8_C( 51), UINT8_C(137), UINT8_C(178), UINT8_C(184) } },
    { { UINT8_C(190), UINT8_C( 58), UINT8_C( 87), UINT8_C( 92), UINT8_C(142), UINT8_C(214), UINT8_C(234), UINT8_C(204),
        UINT8_C(220), UINT8_C( 38), UINT8_C(253), UINT8_C( 16), UINT8_C( 23), UINT8_C(175), UINT8_C(134), UINT8_C(  2) },
      { UINT8_C(233), UINT8_C( 80), UINT8_C( 17), UINT8_C(223), UINT8_C(197), UINT8_C(158), UINT8_C(235), UINT8_C(144),
        UINT8_C(142), UINT8_C(194), UINT8_C(221), UINT8_C( 23), UINT8_C(229), UINT8_C(149), UINT8_C(253), UINT8_C(163) },
      { UINT8_C(190), UINT8_C(233), UINT8_C( 87), UINT8_C( 17), UINT8_C(142), UINT8_C(197), UINT8_C(234), UINT8_C(235),
        UINT8_C(220), UINT8_C(142), UINT8_C(253), UINT8_C(221), UINT8_C( 23), UINT8_C(229), UINT8_C(134), UINT8_C(253) } },
    { { UINT8_C(207), UINT8_C( 84),    UINT8_MAX, UINT8_C( 93), UINT8_C( 43), UINT8_C(233), UINT8_C( 41), UINT8_C(  7),
        UINT8_C( 15), UINT8_C( 38), UINT8_C( 23), UINT8_C( 38), UINT8_C(213), UINT8_C(158), UINT8_C( 41), UINT8_C(190) },
      { UINT8_C(238), UINT8_C( 58), UINT8_C(157), UINT8_C(180), UINT8_C(216), UINT8_C(136), UINT8_C( 68), UINT8_C(102),
        UINT8_C( 74), UINT8_C( 33), UINT8_C(126), UINT8_C( 47), UINT8_C(183), UINT8_C(123), UINT8_C(211), UINT8_C(134) },
      { UINT8_C(207), UINT8_C(238),    UINT8_MAX, UINT8_C(157), UINT8_C( 43), UINT8_C(216), UINT8_C( 41), UINT8_C( 68),
        UINT8_C( 15), UINT8_C( 74), UINT8_C( 23), UINT8_C(126), UINT8_C(213), UINT8_C(183), UINT8_C( 41), UINT8_C(211) } },
    { { UINT8_C(208), UINT8_C(210), UINT8_C(228), UINT8_C(251), UINT8_C(188), UINT8_C( 13), UINT8_C(  2), UINT8_C(203),
        UINT8_C( 52), UINT8_C( 26), UINT8_C(242), UINT8_C(  9), UINT8_C(184), UINT8_C( 27), UINT8_C(200), UINT8_C(166) },
      { UINT8_C( 85), UINT8_C(101), UINT8_C( 90), UINT8_C( 46), UINT8_C(238), UINT8_C(159), UINT8_C(148), UINT8_C( 56),
        UINT8_C(192), UINT8_C( 18), UINT8_C(104), UINT8_C(119), UINT8_C(142), UINT8_C( 59), UINT8_C(254), UINT8_C( 94) },
      { UINT8_C(208), UINT8_C( 85), UINT8_C(228), UINT8_C( 90), UINT8_C(188), UINT8_C(238), UINT8_C(  2), UINT8_C(148),
        UINT8_C( 52), UINT8_C(192), UINT8_C(242), UINT8_C(104), UINT8_C(184), UINT8_C(142), UINT8_C(200), UINT8_C(254) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vtrn1q_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1q_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(14167), UINT16_C(21279), UINT16_C(48551), UINT16_C(14943), UINT16_C(56959), UINT16_C( 3699), UINT16_C(63440), UINT16_C(55030) },
      { UINT16_C(40429), UINT16_C(42656), UINT16_C(10703), UINT16_C(50757), UINT16_C(39485), UINT16_C(24810), UINT16_C(45053), UINT16_C(22004) },
      { UINT16_C(14167), UINT16_C(40429), UINT16_C(48551), UINT16_C(10703), UINT16_C(56959), UINT16_C(39485), UINT16_C(63440), UINT16_C(45053) } },
    { { UINT16_C( 5094), UINT16_C(36264), UINT16_C( 2001), UINT16_C(20680), UINT16_C(15333), UINT16_C(46430), UINT16_C(21555), UINT16_C( 8331) },
      { UINT16_C(11505), UINT16_C(49351), UINT16_C( 3157), UINT16_C(37510), UINT16_C(28839), UINT16_C(42226), UINT16_C(59167), UINT16_C( 1785) },
      { UINT16_C( 5094), UINT16_C(11505), UINT16_C( 2001), UINT16_C( 3157), UINT16_C(15333), UINT16_C(28839), UINT16_C(21555), UINT16_C(59167) } },
    { { UINT16_C(41466), UINT16_C(52115), UINT16_C(23464), UINT16_C(36124), UINT16_C(31383), UINT16_C(51778), UINT16_C(52943), UINT16_C(49386) },
      { UINT16_C(45562), UINT16_C(20353), UINT16_C( 1982), UINT16_C(26082), UINT16_C(54392), UINT16_C(38665), UINT16_C(  955), UINT16_C(46749) },
      { UINT16_C(41466), UINT16_C(45562), UINT16_C(23464), UINT16_C( 1982), UINT16_C(31383), UINT16_C(54392), UINT16_C(52943), UINT16_C(  955) } },
    { { UINT16_C(12708), UINT16_C(19841), UINT16_C(40332), UINT16_C( 9178), UINT16_C( 7448), UINT16_C(59373), UINT16_C(55531), UINT16_C(58791) },
      { UINT16_C(10377), UINT16_C(18228), UINT16_C( 5680), UINT16_C(43180), UINT16_C(46827), UINT16_C(42559), UINT16_C(56761), UINT16_C(23900) },
      { UINT16_C(12708), UINT16_C(10377), UINT16_C(40332), UINT16_C( 5680), UINT16_C( 7448), UINT16_C(46827), UINT16_C(55531), UINT16_C(56761) } },
    { { UINT16_C(56846), UINT16_C(39594), UINT16_C(34171), UINT16_C(37822), UINT16_C(43938), UINT16_C(36218), UINT16_C( 8835), UINT16_C( 3442) },
      { UINT16_C(42570), UINT16_C(31316), UINT16_C(  445), UINT16_C(43042), UINT16_C(25271), UINT16_C(28750), UINT16_C(43839), UINT16_C(19917) },
      { UINT16_C(56846), UINT16_C(42570), UINT16_C(34171), UINT16_C(  445), UINT16_C(43938), UINT16_C(25271), UINT16_C( 8835), UINT16_C(43839) } },
    { { UINT16_C(30857), UINT16_C( 1255), UINT16_C(42493), UINT16_C(40856), UINT16_C( 4689), UINT16_C(54316), UINT16_C(40500), UINT16_C(32737) },
      { UINT16_C(13892), UINT16_C(  505), UINT16_C( 7223), UINT16_C(61097), UINT16_C(63614), UINT16_C(48478), UINT16_C(11171), UINT16_C(11274) },
      { UINT16_C(30857), UINT16_C(13892), UINT16_C(42493), UINT16_C( 7223), UINT16_C( 4689), UINT16_C(63614), UINT16_C(40500), UINT16_C(11171) } },
    { { UINT16_C(61859), UINT16_C(41008), UINT16_C(51351), UINT16_C(59455), UINT16_C(27611), UINT16_C( 4028), UINT16_C(40457), UINT16_C(20110) },
      { UINT16_C(35028), UINT16_C( 2895), UINT16_C(63908), UINT16_C( 8953), UINT16_C(22513), UINT16_C(38111), UINT16_C(59778), UINT16_C( 9920) },
      { UINT16_C(61859), UINT16_C(35028), UINT16_C(51351), UINT16_C(63908), UINT16_C(27611), UINT16_C(22513), UINT16_C(40457), UINT16_C(59778) } },
    { { UINT16_C(61658), UINT16_C(29126), UINT16_C( 1721), UINT16_C(37977), UINT16_C( 5745), UINT16_C(31651), UINT16_C(12980), UINT16_C(35017) },
      { UINT16_C( 6330), UINT16_C(24211), UINT16_C(35857), UINT16_C(  640), UINT16_C(24547), UINT16_C(26006), UINT16_C(22088), UINT16_C( 8843) },
      { UINT16_C(61658), UINT16_C( 6330), UINT16_C( 1721), UINT16_C(35857), UINT16_C( 5745), UINT16_C(24547), UINT16_C(12980), UINT16_C(22088) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vtrn1q_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1q_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 497895404), UINT32_C(1842434419), UINT32_C(2057525496), UINT32_C(2082404662) },
      { UINT32_C( 744362374), UINT32_C(1722726623), UINT32_C(2688313178), UINT32_C(3645033197) },
      { UINT32_C( 497895404), UINT32_C( 744362374), UINT32_C(2057525496), UINT32_C(2688313178) } },
    { { UINT32_C(2230775569), UINT32_C( 955369280), UINT32_C(1454544160), UINT32_C( 366203278) },
      { UINT32_C(3242275298), UINT32_C(1143468009), UINT32_C(1155818583), UINT32_C(1058874926) },
      { UINT32_C(2230775569), UINT32_C(3242275298), UINT32_C(1454544160), UINT32_C(1155818583) } },
    { { UINT32_C(1438848021), UINT32_C(4220433883), UINT32_C(3629269066), UINT32_C(4092405009) },
      { UINT32_C(1068772950), UINT32_C(1971575838), UINT32_C(1857644608), UINT32_C(2762856078) },
      { UINT32_C(1438848021), UINT32_C(1068772950), UINT32_C(3629269066), UINT32_C(1857644608) } },
    { { UINT32_C(3338236138), UINT32_C(1874954021), UINT32_C(3645379528), UINT32_C(2395813176) },
      { UINT32_C(2194571620), UINT32_C(2650231133), UINT32_C(1208725689), UINT32_C(1911339142) },
      { UINT32_C(3338236138), UINT32_C(2194571620), UINT32_C(3645379528), UINT32_C(1208725689) } },
    { { UINT32_C(1312285993), UINT32_C( 901707885), UINT32_C(1141769740), UINT32_C(2681461563) },
      { UINT32_C(3122766173), UINT32_C(2891454706), UINT32_C(1341416392), UINT32_C(1170268188) },
      { UINT32_C(1312285993), UINT32_C(3122766173), UINT32_C(1141769740), UINT32_C(1341416392) } },
    { { UINT32_C( 848558021), UINT32_C(4217852399), UINT32_C(2470475351), UINT32_C(2922517329) },
      { UINT32_C(2791920820), UINT32_C( 894615916), UINT32_C(1082410532), UINT32_C(3968156710) },
      { UINT32_C( 848558021), UINT32_C(2791920820), UINT32_C(2470475351), UINT32_C(1082410532) } },
    { { UINT32_C( 706615611), UINT32_C(3257304682), UINT32_C(1297442556), UINT32_C( 771524473) },
      { UINT32_C(1221813723), UINT32_C(1249715750), UINT32_C(2475360620), UINT32_C(2155810885) },
      { UINT32_C( 706615611), UINT32_C(1221813723), UINT32_C(1297442556), UINT32_C(2475360620) } },
    { { UINT32_C(2494209321), UINT32_C( 525783075), UINT32_C(2943200054), UINT32_C( 249325874) },
      { UINT32_C(4099322062), UINT32_C(1111413718), UINT32_C( 433441236), UINT32_C(  60380378) },
      { UINT32_C(2494209321), UINT32_C(4099322062), UINT32_C(2943200054), UINT32_C( 433441236) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vtrn1q_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vtrn1q_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 4815427970974768462), UINT64_C( 6946629186605919678) },
      { UINT64_C(17577554379567712573), UINT64_C( 9507926976227586244) },
      { UINT64_C( 4815427970974768462), UINT64_C(17577554379567712573) } },
    { { UINT64_C(17783107680982229326), UINT64_C( 7694430944701500407) },
      { UINT64_C(14946435657532704485), UINT64_C( 1392019949421056920) },
      { UINT64_C(17783107680982229326), UINT64_C(14946435657532704485) } },
    { { UINT64_C(  720685969029384403), UINT64_C(13170277731653498159) },
      { UINT64_C( 4546836441613680191), UINT64_C(15944534928651032686) },
      { UINT64_C(  720685969029384403), UINT64_C( 4546836441613680191) } },
    { { UINT64_C( 8377513640867717158), UINT64_C( 3252891876890621085) },
      { UINT64_C( 6754432899425457110), UINT64_C( 5553173804405016872) },
      { UINT64_C( 8377513640867717158), UINT64_C( 6754432899425457110) } },
    { { UINT64_C( 9111002919100414135), UINT64_C(12652601303620206972) },
      { UINT64_C(14317480457102167653), UINT64_C(14926910591795282610) },
      { UINT64_C( 9111002919100414135), UINT64_C(14317480457102167653) } },
    { { UINT64_C(17465588781926821122), UINT64_C(14197020995446656893) },
      { UINT64_C(14728401471583891713), UINT64_C( 7779348683327627021) },
      { UINT64_C(17465588781926821122), UINT64_C(14728401471583891713) } },
    { { UINT64_C( 8854554042291961977), UINT64_C( 3541753660244507904) },
      { UINT64_C( 1724092549986008839), UINT64_C(15666108166636934036) },
      { UINT64_C( 8854554042291961977), UINT64_C( 1724092549986008839) } },
    { { UINT64_C( 7595788518996621554), UINT64_C( 1677572234304633318) },
      { UINT64_C(16235800240466695983), UINT64_C(12894166098514972345) },
      { UINT64_C( 7595788518996621554), UINT64_C(16235800240466695983) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vtrn1q_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn1q_u64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
