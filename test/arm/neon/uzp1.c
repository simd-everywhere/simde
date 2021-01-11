#define SIMDE_TEST_ARM_NEON_INSN uzp1

#include "test-neon.h"
#include "../../../simde/arm/neon/uzp1.h"

static int
test_simde_vuzp1_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   188.14), SIMDE_FLOAT32_C(   -87.23) },
      { SIMDE_FLOAT32_C(  -966.94), SIMDE_FLOAT32_C(  -341.57) },
      { SIMDE_FLOAT32_C(   188.14), SIMDE_FLOAT32_C(  -966.94) } },
    { { SIMDE_FLOAT32_C(   682.15), SIMDE_FLOAT32_C(  -964.96) },
      { SIMDE_FLOAT32_C(   256.02), SIMDE_FLOAT32_C(   570.89) },
      { SIMDE_FLOAT32_C(   682.15), SIMDE_FLOAT32_C(   256.02) } },
    { { SIMDE_FLOAT32_C(  -610.16), SIMDE_FLOAT32_C(  -498.24) },
      { SIMDE_FLOAT32_C(  -566.43), SIMDE_FLOAT32_C(  -742.76) },
      { SIMDE_FLOAT32_C(  -610.16), SIMDE_FLOAT32_C(  -566.43) } },
    { { SIMDE_FLOAT32_C(   804.69), SIMDE_FLOAT32_C(  -146.31) },
      { SIMDE_FLOAT32_C(  -114.26), SIMDE_FLOAT32_C(   461.82) },
      { SIMDE_FLOAT32_C(   804.69), SIMDE_FLOAT32_C(  -114.26) } },
    { { SIMDE_FLOAT32_C(  -520.26), SIMDE_FLOAT32_C(   290.59) },
      { SIMDE_FLOAT32_C(   275.50), SIMDE_FLOAT32_C(  -573.98) },
      { SIMDE_FLOAT32_C(  -520.26), SIMDE_FLOAT32_C(   275.50) } },
    { { SIMDE_FLOAT32_C(   376.60), SIMDE_FLOAT32_C(   324.13) },
      { SIMDE_FLOAT32_C(   478.86), SIMDE_FLOAT32_C(   385.76) },
      { SIMDE_FLOAT32_C(   376.60), SIMDE_FLOAT32_C(   478.86) } },
    { { SIMDE_FLOAT32_C(  -299.73), SIMDE_FLOAT32_C(   292.94) },
      { SIMDE_FLOAT32_C(  -120.55), SIMDE_FLOAT32_C(   448.35) },
      { SIMDE_FLOAT32_C(  -299.73), SIMDE_FLOAT32_C(  -120.55) } },
    { { SIMDE_FLOAT32_C(   411.84), SIMDE_FLOAT32_C(   757.01) },
      { SIMDE_FLOAT32_C(  -355.19), SIMDE_FLOAT32_C(  -400.02) },
      { SIMDE_FLOAT32_C(   411.84), SIMDE_FLOAT32_C(  -355.19) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vuzp1_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vuzp1_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 118), -INT8_C(  36),  INT8_C(  91), -INT8_C( 109), -INT8_C(  14),  INT8_C(  74), -INT8_C(  81),  INT8_C(  58) },
      { -INT8_C(  10),      INT8_MIN, -INT8_C(  52), -INT8_C(  53), -INT8_C(  80),  INT8_C(  35), -INT8_C( 119),  INT8_C(  69) },
      { -INT8_C( 118),  INT8_C(  91), -INT8_C(  14), -INT8_C(  81), -INT8_C(  10), -INT8_C(  52), -INT8_C(  80), -INT8_C( 119) } },
    { { -INT8_C(  37),  INT8_C( 112), -INT8_C(  36),  INT8_C(  99),  INT8_C(  49), -INT8_C( 105),  INT8_C(  96),  INT8_C(  97) },
      {  INT8_C(  79), -INT8_C( 113), -INT8_C(  17),  INT8_C(  16), -INT8_C( 104),  INT8_C(  44), -INT8_C( 121),  INT8_C(  35) },
      { -INT8_C(  37), -INT8_C(  36),  INT8_C(  49),  INT8_C(  96),  INT8_C(  79), -INT8_C(  17), -INT8_C( 104), -INT8_C( 121) } },
    { {  INT8_C(   8), -INT8_C(  30), -INT8_C(  74), -INT8_C(   5),  INT8_C(  45),  INT8_C( 101),  INT8_C(  53),  INT8_C(  35) },
      { -INT8_C(  27),  INT8_C(   1), -INT8_C(  18), -INT8_C( 107),  INT8_C(  36),  INT8_C( 119), -INT8_C(  37), -INT8_C(   1) },
      {  INT8_C(   8), -INT8_C(  74),  INT8_C(  45),  INT8_C(  53), -INT8_C(  27), -INT8_C(  18),  INT8_C(  36), -INT8_C(  37) } },
    { { -INT8_C(  25), -INT8_C(  73),  INT8_C(  99),  INT8_C(  25),  INT8_C(  79), -INT8_C(  61),  INT8_C( 122), -INT8_C(  98) },
      {  INT8_C(  83),  INT8_C( 106), -INT8_C(  82), -INT8_C(  21), -INT8_C( 106),  INT8_C(  53),  INT8_C(  14), -INT8_C(  98) },
      { -INT8_C(  25),  INT8_C(  99),  INT8_C(  79),  INT8_C( 122),  INT8_C(  83), -INT8_C(  82), -INT8_C( 106),  INT8_C(  14) } },
    { {  INT8_C(  24), -INT8_C(  60), -INT8_C( 103),  INT8_C(  69),  INT8_C(  41), -INT8_C(  50),  INT8_C( 104),  INT8_C(  15) },
      { -INT8_C(  49),  INT8_C(  86), -INT8_C(  92), -INT8_C(  12), -INT8_C(  50),      INT8_MAX, -INT8_C(  13), -INT8_C(  75) },
      {  INT8_C(  24), -INT8_C( 103),  INT8_C(  41),  INT8_C( 104), -INT8_C(  49), -INT8_C(  92), -INT8_C(  50), -INT8_C(  13) } },
    { {  INT8_C(  55),  INT8_C(  86), -INT8_C(  50), -INT8_C( 122),  INT8_C(  26),  INT8_C(  73),  INT8_C(  36),  INT8_C( 109) },
      { -INT8_C(  77), -INT8_C(  46),  INT8_C(  88),  INT8_C(  73),  INT8_C(   7),  INT8_C( 103), -INT8_C(  25),  INT8_C(  31) },
      {  INT8_C(  55), -INT8_C(  50),  INT8_C(  26),  INT8_C(  36), -INT8_C(  77),  INT8_C(  88),  INT8_C(   7), -INT8_C(  25) } },
    { {  INT8_C(  43), -INT8_C( 127),  INT8_C( 100),  INT8_C(  85),  INT8_C(  79), -INT8_C(  52),  INT8_C( 100),  INT8_C(  31) },
      {  INT8_C(  35),  INT8_C(   8),  INT8_C(  19), -INT8_C(  15), -INT8_C( 120),  INT8_C(   6), -INT8_C(  90), -INT8_C(  65) },
      {  INT8_C(  43),  INT8_C( 100),  INT8_C(  79),  INT8_C( 100),  INT8_C(  35),  INT8_C(  19), -INT8_C( 120), -INT8_C(  90) } },
    { {  INT8_C(  93),  INT8_C( 117),  INT8_C(  69),  INT8_C( 119), -INT8_C(  66),  INT8_C( 105), -INT8_C(  28),  INT8_C( 113) },
      {  INT8_C(  59),  INT8_C(  60), -INT8_C(  70),  INT8_C(  66), -INT8_C(  93), -INT8_C(  95),  INT8_C(  98), -INT8_C(  49) },
      {  INT8_C(  93),  INT8_C(  69), -INT8_C(  66), -INT8_C(  28),  INT8_C(  59), -INT8_C(  70), -INT8_C(  93),  INT8_C(  98) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vuzp1_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  4834), -INT16_C( 29643), -INT16_C(   562),  INT16_C(  6247) },
      { -INT16_C( 31539), -INT16_C( 23021), -INT16_C( 19325),  INT16_C(  7646) },
      { -INT16_C(  4834), -INT16_C(   562), -INT16_C( 31539), -INT16_C( 19325) } },
    { { -INT16_C( 24760), -INT16_C( 30696), -INT16_C( 19537),  INT16_C( 32224) },
      {  INT16_C( 30005), -INT16_C( 11182), -INT16_C( 21755),  INT16_C(  9051) },
      { -INT16_C( 24760), -INT16_C( 19537),  INT16_C( 30005), -INT16_C( 21755) } },
    { { -INT16_C( 28520),  INT16_C( 26287),  INT16_C(  5773),  INT16_C( 23422) },
      { -INT16_C( 28262),  INT16_C(  7681), -INT16_C(  8379), -INT16_C( 29381) },
      { -INT16_C( 28520),  INT16_C(  5773), -INT16_C( 28262), -INT16_C(  8379) } },
    { {  INT16_C( 21375),  INT16_C( 11798), -INT16_C(  2553),  INT16_C( 15531) },
      { -INT16_C(   404),  INT16_C( 28944),  INT16_C( 27561),  INT16_C( 16788) },
      {  INT16_C( 21375), -INT16_C(  2553), -INT16_C(   404),  INT16_C( 27561) } },
    { {  INT16_C( 17404), -INT16_C( 30297),  INT16_C(  9561), -INT16_C(  3100) },
      { -INT16_C(  6474), -INT16_C(  1263),  INT16_C( 19909),  INT16_C( 17544) },
      {  INT16_C( 17404),  INT16_C(  9561), -INT16_C(  6474),  INT16_C( 19909) } },
    { { -INT16_C( 24928), -INT16_C( 22670),  INT16_C(  7829),  INT16_C(   484) },
      { -INT16_C(  3044), -INT16_C( 14990),  INT16_C(  1632),  INT16_C( 23558) },
      { -INT16_C( 24928),  INT16_C(  7829), -INT16_C(  3044),  INT16_C(  1632) } },
    { { -INT16_C( 21175), -INT16_C( 23835), -INT16_C( 13614), -INT16_C( 30571) },
      { -INT16_C( 22608),  INT16_C( 30083),  INT16_C(  3060), -INT16_C( 27462) },
      { -INT16_C( 21175), -INT16_C( 13614), -INT16_C( 22608),  INT16_C(  3060) } },
    { {  INT16_C( 11434),  INT16_C( 16188),  INT16_C(  8266),  INT16_C( 26176) },
      { -INT16_C( 19948),  INT16_C( 29739),  INT16_C( 12728),  INT16_C(   464) },
      {  INT16_C( 11434),  INT16_C(  8266), -INT16_C( 19948),  INT16_C( 12728) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vuzp1_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1869944670), -INT32_C(  1067514177) },
      { -INT32_C(   648958507),  INT32_C(   857291726) },
      { -INT32_C(  1869944670), -INT32_C(   648958507) } },
    { {  INT32_C(  1021903255),  INT32_C(  2109018270) },
      { -INT32_C(  1188524118), -INT32_C(   636618440) },
      {  INT32_C(  1021903255), -INT32_C(  1188524118) } },
    { { -INT32_C(  1603627039),  INT32_C(  1918945949) },
      {  INT32_C(  1162588535), -INT32_C(  2072484371) },
      { -INT32_C(  1603627039),  INT32_C(  1162588535) } },
    { {  INT32_C(    96493926),  INT32_C(   478311794) },
      {  INT32_C(  1020635652), -INT32_C(  2062032221) },
      {  INT32_C(    96493926),  INT32_C(  1020635652) } },
    { {  INT32_C(   371556729), -INT32_C(  1031240117) },
      {  INT32_C(   604492855), -INT32_C(  1616347335) },
      {  INT32_C(   371556729),  INT32_C(   604492855) } },
    { {  INT32_C(  1403283681), -INT32_C(   496032034) },
      {  INT32_C(  1948206289), -INT32_C(  1611057626) },
      {  INT32_C(  1403283681),  INT32_C(  1948206289) } },
    { {  INT32_C(    62201783), -INT32_C(   591053403) },
      {  INT32_C(  1241632017),  INT32_C(   770353484) },
      {  INT32_C(    62201783),  INT32_C(  1241632017) } },
    { { -INT32_C(   260010478), -INT32_C(  2032996427) },
      {  INT32_C(  1509617971), -INT32_C(   537332697) },
      { -INT32_C(   260010478),  INT32_C(  1509617971) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vuzp1_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(224), UINT8_C(140), UINT8_C(245), UINT8_C( 77), UINT8_C(190), UINT8_C( 25), UINT8_C(105), UINT8_C(180) },
      { UINT8_C( 70), UINT8_C( 19), UINT8_C(231), UINT8_C(216), UINT8_C(120), UINT8_C( 45), UINT8_C(243), UINT8_C(217) },
      { UINT8_C(224), UINT8_C(245), UINT8_C(190), UINT8_C(105), UINT8_C( 70), UINT8_C(231), UINT8_C(120), UINT8_C(243) } },
    { { UINT8_C( 46), UINT8_C(188), UINT8_C(216), UINT8_C( 61), UINT8_C( 60), UINT8_C(108), UINT8_C(192), UINT8_C(214) },
      { UINT8_C(216), UINT8_C( 93), UINT8_C( 95), UINT8_C( 31), UINT8_C( 37), UINT8_C(155), UINT8_C(131), UINT8_C(  6) },
      { UINT8_C( 46), UINT8_C(216), UINT8_C( 60), UINT8_C(192), UINT8_C(216), UINT8_C( 95), UINT8_C( 37), UINT8_C(131) } },
    { { UINT8_C( 39), UINT8_C(120), UINT8_C( 83), UINT8_C(229), UINT8_C(145), UINT8_C(188), UINT8_C(154), UINT8_C(216) },
      { UINT8_C(207), UINT8_C(129), UINT8_C(176), UINT8_C( 71), UINT8_C(174), UINT8_C(164), UINT8_C( 32), UINT8_C(220) },
      { UINT8_C( 39), UINT8_C( 83), UINT8_C(145), UINT8_C(154), UINT8_C(207), UINT8_C(176), UINT8_C(174), UINT8_C( 32) } },
    { { UINT8_C( 96), UINT8_C(248), UINT8_C( 25), UINT8_C(157), UINT8_C(100), UINT8_C(217), UINT8_C(115), UINT8_C( 60) },
      { UINT8_C( 54), UINT8_C(210), UINT8_C( 92), UINT8_C( 92), UINT8_C(109), UINT8_C(223), UINT8_C( 98), UINT8_C(149) },
      { UINT8_C( 96), UINT8_C( 25), UINT8_C(100), UINT8_C(115), UINT8_C( 54), UINT8_C( 92), UINT8_C(109), UINT8_C( 98) } },
    { { UINT8_C( 87), UINT8_C(181), UINT8_C(122), UINT8_C(232), UINT8_C(113), UINT8_C( 20), UINT8_C(192), UINT8_C( 64) },
      { UINT8_C(149), UINT8_C(113), UINT8_C(135), UINT8_C( 68), UINT8_C( 21), UINT8_C(167), UINT8_C( 32), UINT8_C(117) },
      { UINT8_C( 87), UINT8_C(122), UINT8_C(113), UINT8_C(192), UINT8_C(149), UINT8_C(135), UINT8_C( 21), UINT8_C( 32) } },
    { { UINT8_C(159), UINT8_C( 58), UINT8_C( 18), UINT8_C(  3), UINT8_C( 19), UINT8_C(133), UINT8_C( 63), UINT8_C( 74) },
      { UINT8_C( 88), UINT8_C(155), UINT8_C(166), UINT8_C(197), UINT8_C(122), UINT8_C(  8), UINT8_C( 90), UINT8_C(209) },
      { UINT8_C(159), UINT8_C( 18), UINT8_C( 19), UINT8_C( 63), UINT8_C( 88), UINT8_C(166), UINT8_C(122), UINT8_C( 90) } },
    { { UINT8_C(189), UINT8_C(213), UINT8_C(186), UINT8_C( 46), UINT8_C(233), UINT8_C(122), UINT8_C(110), UINT8_C(127) },
      { UINT8_C(235), UINT8_C(245), UINT8_C(195), UINT8_C(  0), UINT8_C(156), UINT8_C(227), UINT8_C(118), UINT8_C( 59) },
      { UINT8_C(189), UINT8_C(186), UINT8_C(233), UINT8_C(110), UINT8_C(235), UINT8_C(195), UINT8_C(156), UINT8_C(118) } },
    { { UINT8_C( 29), UINT8_C(136), UINT8_C( 62), UINT8_C( 49), UINT8_C( 14), UINT8_C(125), UINT8_C(123), UINT8_C(102) },
      { UINT8_C( 25), UINT8_C( 33), UINT8_C( 43), UINT8_C(147), UINT8_C( 41), UINT8_C(134), UINT8_C(101), UINT8_C(230) },
      { UINT8_C( 29), UINT8_C( 62), UINT8_C( 14), UINT8_C(123), UINT8_C( 25), UINT8_C( 43), UINT8_C( 41), UINT8_C(101) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vuzp1_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(38227), UINT16_C(36183), UINT16_C(19486), UINT16_C(49723) },
      { UINT16_C(36067), UINT16_C(18109), UINT16_C( 2364), UINT16_C(26479) },
      { UINT16_C(38227), UINT16_C(19486), UINT16_C(36067), UINT16_C( 2364) } },
    { { UINT16_C(43498), UINT16_C(28068), UINT16_C(33746), UINT16_C(12344) },
      { UINT16_C(23108), UINT16_C( 9831), UINT16_C(27483), UINT16_C(44840) },
      { UINT16_C(43498), UINT16_C(33746), UINT16_C(23108), UINT16_C(27483) } },
    { { UINT16_C(32512), UINT16_C( 7740), UINT16_C(30668), UINT16_C(45024) },
      { UINT16_C(40195), UINT16_C(16629), UINT16_C(26022), UINT16_C(37031) },
      { UINT16_C(32512), UINT16_C(30668), UINT16_C(40195), UINT16_C(26022) } },
    { { UINT16_C(19470), UINT16_C(57598), UINT16_C(14031), UINT16_C( 4881) },
      { UINT16_C(30864), UINT16_C(60217), UINT16_C(25059), UINT16_C(58266) },
      { UINT16_C(19470), UINT16_C(14031), UINT16_C(30864), UINT16_C(25059) } },
    { { UINT16_C(55265), UINT16_C(44289), UINT16_C(57934), UINT16_C(21084) },
      { UINT16_C(20863), UINT16_C( 9874), UINT16_C(14774), UINT16_C(50358) },
      { UINT16_C(55265), UINT16_C(57934), UINT16_C(20863), UINT16_C(14774) } },
    { { UINT16_C(46213), UINT16_C(21669), UINT16_C(46826), UINT16_C(31335) },
      { UINT16_C(41262), UINT16_C( 4454), UINT16_C(    2), UINT16_C(58356) },
      { UINT16_C(46213), UINT16_C(46826), UINT16_C(41262), UINT16_C(    2) } },
    { { UINT16_C(62935), UINT16_C( 9872), UINT16_C(60631), UINT16_C(22392) },
      { UINT16_C( 2622), UINT16_C(62589), UINT16_C(13123), UINT16_C(51641) },
      { UINT16_C(62935), UINT16_C(60631), UINT16_C( 2622), UINT16_C(13123) } },
    { { UINT16_C(24296), UINT16_C(53789), UINT16_C(34068), UINT16_C(16973) },
      { UINT16_C(45862), UINT16_C(10323), UINT16_C(18355), UINT16_C(35596) },
      { UINT16_C(24296), UINT16_C(34068), UINT16_C(45862), UINT16_C(18355) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vuzp1_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1701003685), UINT32_C(3515233496) },
      { UINT32_C(2993134067), UINT32_C(4134691062) },
      { UINT32_C(1701003685), UINT32_C(2993134067) } },
    { { UINT32_C(2824142393), UINT32_C(2314310222) },
      { UINT32_C(3987908417), UINT32_C(2842669572) },
      { UINT32_C(2824142393), UINT32_C(3987908417) } },
    { { UINT32_C(3406811891), UINT32_C(4204565766) },
      { UINT32_C( 615252782), UINT32_C(2619022947) },
      { UINT32_C(3406811891), UINT32_C( 615252782) } },
    { { UINT32_C(1782935324), UINT32_C(1123235329) },
      { UINT32_C(3794839006), UINT32_C(1250729815) },
      { UINT32_C(1782935324), UINT32_C(3794839006) } },
    { { UINT32_C(2014681970), UINT32_C(1601352240) },
      { UINT32_C( 428023477), UINT32_C(1488297532) },
      { UINT32_C(2014681970), UINT32_C( 428023477) } },
    { { UINT32_C( 264436237), UINT32_C( 257013041) },
      { UINT32_C(2985394522), UINT32_C(2482732321) },
      { UINT32_C( 264436237), UINT32_C(2985394522) } },
    { { UINT32_C(1225462040), UINT32_C(2024308419) },
      { UINT32_C(3650169756), UINT32_C(3610331082) },
      { UINT32_C(1225462040), UINT32_C(3650169756) } },
    { { UINT32_C(1927738433), UINT32_C(  75577513) },
      { UINT32_C(3669324729), UINT32_C( 158183920) },
      { UINT32_C(1927738433), UINT32_C(3669324729) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vuzp1_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1q_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    44.64), SIMDE_FLOAT32_C(  -905.59), SIMDE_FLOAT32_C(  -768.48), SIMDE_FLOAT32_C(  -818.27) },
      { SIMDE_FLOAT32_C(   904.80), SIMDE_FLOAT32_C(  -408.01), SIMDE_FLOAT32_C(   720.84), SIMDE_FLOAT32_C(   882.26) },
      { SIMDE_FLOAT32_C(    44.64), SIMDE_FLOAT32_C(  -768.48), SIMDE_FLOAT32_C(   904.80), SIMDE_FLOAT32_C(   720.84) } },
    { { SIMDE_FLOAT32_C(  -100.34), SIMDE_FLOAT32_C(  -322.81), SIMDE_FLOAT32_C(   486.25), SIMDE_FLOAT32_C(  -834.82) },
      { SIMDE_FLOAT32_C(   981.41), SIMDE_FLOAT32_C(  -245.05), SIMDE_FLOAT32_C(  -204.05), SIMDE_FLOAT32_C(  -317.62) },
      { SIMDE_FLOAT32_C(  -100.34), SIMDE_FLOAT32_C(   486.25), SIMDE_FLOAT32_C(   981.41), SIMDE_FLOAT32_C(  -204.05) } },
    { { SIMDE_FLOAT32_C(   -41.99), SIMDE_FLOAT32_C(   859.14), SIMDE_FLOAT32_C(  -108.92), SIMDE_FLOAT32_C(   737.09) },
      { SIMDE_FLOAT32_C(   401.23), SIMDE_FLOAT32_C(    -9.98), SIMDE_FLOAT32_C(  -396.63), SIMDE_FLOAT32_C(   925.63) },
      { SIMDE_FLOAT32_C(   -41.99), SIMDE_FLOAT32_C(  -108.92), SIMDE_FLOAT32_C(   401.23), SIMDE_FLOAT32_C(  -396.63) } },
    { { SIMDE_FLOAT32_C(  -768.54), SIMDE_FLOAT32_C(   832.74), SIMDE_FLOAT32_C(   920.95), SIMDE_FLOAT32_C(  -472.96) },
      { SIMDE_FLOAT32_C(  -329.25), SIMDE_FLOAT32_C(  -890.65), SIMDE_FLOAT32_C(  -956.60), SIMDE_FLOAT32_C(   715.39) },
      { SIMDE_FLOAT32_C(  -768.54), SIMDE_FLOAT32_C(   920.95), SIMDE_FLOAT32_C(  -329.25), SIMDE_FLOAT32_C(  -956.60) } },
    { { SIMDE_FLOAT32_C(  -796.25), SIMDE_FLOAT32_C(  -725.08), SIMDE_FLOAT32_C(   897.12), SIMDE_FLOAT32_C(  -891.44) },
      { SIMDE_FLOAT32_C(  -133.09), SIMDE_FLOAT32_C(   617.96), SIMDE_FLOAT32_C(   990.81), SIMDE_FLOAT32_C(   766.56) },
      { SIMDE_FLOAT32_C(  -796.25), SIMDE_FLOAT32_C(   897.12), SIMDE_FLOAT32_C(  -133.09), SIMDE_FLOAT32_C(   990.81) } },
    { { SIMDE_FLOAT32_C(  -704.85), SIMDE_FLOAT32_C(   477.06), SIMDE_FLOAT32_C(   931.74), SIMDE_FLOAT32_C(  -723.44) },
      { SIMDE_FLOAT32_C(  -767.99), SIMDE_FLOAT32_C(  -272.30), SIMDE_FLOAT32_C(   -41.06), SIMDE_FLOAT32_C(   190.02) },
      { SIMDE_FLOAT32_C(  -704.85), SIMDE_FLOAT32_C(   931.74), SIMDE_FLOAT32_C(  -767.99), SIMDE_FLOAT32_C(   -41.06) } },
    { { SIMDE_FLOAT32_C(  -413.17), SIMDE_FLOAT32_C(   850.02), SIMDE_FLOAT32_C(   -72.89), SIMDE_FLOAT32_C(   988.07) },
      { SIMDE_FLOAT32_C(  -159.95), SIMDE_FLOAT32_C(   530.48), SIMDE_FLOAT32_C(   913.70), SIMDE_FLOAT32_C(    71.51) },
      { SIMDE_FLOAT32_C(  -413.17), SIMDE_FLOAT32_C(   -72.89), SIMDE_FLOAT32_C(  -159.95), SIMDE_FLOAT32_C(   913.70) } },
    { { SIMDE_FLOAT32_C(   363.22), SIMDE_FLOAT32_C(   834.65), SIMDE_FLOAT32_C(   598.55), SIMDE_FLOAT32_C(  -966.03) },
      { SIMDE_FLOAT32_C(   943.99), SIMDE_FLOAT32_C(   641.95), SIMDE_FLOAT32_C(   749.36), SIMDE_FLOAT32_C(  -852.25) },
      { SIMDE_FLOAT32_C(   363.22), SIMDE_FLOAT32_C(   598.55), SIMDE_FLOAT32_C(   943.99), SIMDE_FLOAT32_C(   749.36) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vuzp1q_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vuzp1q_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   322.53), SIMDE_FLOAT64_C(   856.49) },
      { SIMDE_FLOAT64_C(   802.23), SIMDE_FLOAT64_C(   452.91) },
      { SIMDE_FLOAT64_C(   322.53), SIMDE_FLOAT64_C(   802.23) } },
    { { SIMDE_FLOAT64_C(   459.71), SIMDE_FLOAT64_C(  -770.97) },
      { SIMDE_FLOAT64_C(   594.98), SIMDE_FLOAT64_C(   107.24) },
      { SIMDE_FLOAT64_C(   459.71), SIMDE_FLOAT64_C(   594.98) } },
    { { SIMDE_FLOAT64_C(   374.90), SIMDE_FLOAT64_C(   400.47) },
      { SIMDE_FLOAT64_C(   344.98), SIMDE_FLOAT64_C(  -972.39) },
      { SIMDE_FLOAT64_C(   374.90), SIMDE_FLOAT64_C(   344.98) } },
    { { SIMDE_FLOAT64_C(  -625.14), SIMDE_FLOAT64_C(     7.91) },
      { SIMDE_FLOAT64_C(    75.57), SIMDE_FLOAT64_C(   770.62) },
      { SIMDE_FLOAT64_C(  -625.14), SIMDE_FLOAT64_C(    75.57) } },
    { { SIMDE_FLOAT64_C(   809.69), SIMDE_FLOAT64_C(  -906.73) },
      { SIMDE_FLOAT64_C(   321.38), SIMDE_FLOAT64_C(  -635.84) },
      { SIMDE_FLOAT64_C(   809.69), SIMDE_FLOAT64_C(   321.38) } },
    { { SIMDE_FLOAT64_C(   759.95), SIMDE_FLOAT64_C(   514.69) },
      { SIMDE_FLOAT64_C(  -113.83), SIMDE_FLOAT64_C(   699.68) },
      { SIMDE_FLOAT64_C(   759.95), SIMDE_FLOAT64_C(  -113.83) } },
    { { SIMDE_FLOAT64_C(   226.46), SIMDE_FLOAT64_C(    68.20) },
      { SIMDE_FLOAT64_C(   -55.03), SIMDE_FLOAT64_C(  -667.20) },
      { SIMDE_FLOAT64_C(   226.46), SIMDE_FLOAT64_C(   -55.03) } },
    { { SIMDE_FLOAT64_C(   435.49), SIMDE_FLOAT64_C(  -654.23) },
      { SIMDE_FLOAT64_C(  -732.44), SIMDE_FLOAT64_C(  -241.98) },
      { SIMDE_FLOAT64_C(   435.49), SIMDE_FLOAT64_C(  -732.44) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vuzp1q_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vuzp1q_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  38),  INT8_C( 121), -INT8_C(  35), -INT8_C(   2),  INT8_C(  99), -INT8_C(  33),  INT8_C(  12),  INT8_C(  51),
         INT8_C(  33), -INT8_C(  30), -INT8_C(  74), -INT8_C( 115), -INT8_C(  20),  INT8_C(  79),  INT8_C( 110),  INT8_C(  93) },
      {  INT8_C(  31),  INT8_C(  91), -INT8_C(   6),  INT8_C(  32),  INT8_C(  27), -INT8_C(  14), -INT8_C(  75), -INT8_C(  53),
        -INT8_C(   8),  INT8_C(  39), -INT8_C( 107), -INT8_C(  36), -INT8_C(  81), -INT8_C(  19), -INT8_C(  26), -INT8_C(  43) },
      {  INT8_C(  38), -INT8_C(  35),  INT8_C(  99),  INT8_C(  12),  INT8_C(  33), -INT8_C(  74), -INT8_C(  20),  INT8_C( 110),
         INT8_C(  31), -INT8_C(   6),  INT8_C(  27), -INT8_C(  75), -INT8_C(   8), -INT8_C( 107), -INT8_C(  81), -INT8_C(  26) } },
    { {  INT8_C( 102), -INT8_C(  61), -INT8_C(  45), -INT8_C(  55), -INT8_C(  94), -INT8_C(  33), -INT8_C(   4), -INT8_C(  61),
        -INT8_C(  62), -INT8_C(  78),  INT8_C(  80), -INT8_C(  82),  INT8_C(   1), -INT8_C(  66),  INT8_C(  11),  INT8_C(  33) },
      {  INT8_C(  26),  INT8_C(   5),  INT8_C(  65),  INT8_C(  53), -INT8_C(   9), -INT8_C(  10),  INT8_C(   0), -INT8_C(  16),
         INT8_C(  30), -INT8_C( 107), -INT8_C(  52), -INT8_C(  51), -INT8_C( 126), -INT8_C(  78), -INT8_C(  94), -INT8_C(  24) },
      {  INT8_C( 102), -INT8_C(  45), -INT8_C(  94), -INT8_C(   4), -INT8_C(  62),  INT8_C(  80),  INT8_C(   1),  INT8_C(  11),
         INT8_C(  26),  INT8_C(  65), -INT8_C(   9),  INT8_C(   0),  INT8_C(  30), -INT8_C(  52), -INT8_C( 126), -INT8_C(  94) } },
    { {  INT8_C( 117),  INT8_C( 117), -INT8_C(  79),  INT8_C(  23),  INT8_C(  84), -INT8_C(  83), -INT8_C(  37),  INT8_C(  22),
         INT8_C(  96),  INT8_C(  43), -INT8_C(  59),  INT8_C(  97), -INT8_C(  22), -INT8_C(  48), -INT8_C( 126),  INT8_C(   4) },
      { -INT8_C(  42), -INT8_C(  60),  INT8_C(  57), -INT8_C(  51), -INT8_C(  70),  INT8_C(  57), -INT8_C(  67), -INT8_C(  40),
        -INT8_C(  50), -INT8_C( 119), -INT8_C(  91),  INT8_C(  81),  INT8_C(  59),  INT8_C(  71),  INT8_C(  57), -INT8_C(  80) },
      {  INT8_C( 117), -INT8_C(  79),  INT8_C(  84), -INT8_C(  37),  INT8_C(  96), -INT8_C(  59), -INT8_C(  22), -INT8_C( 126),
        -INT8_C(  42),  INT8_C(  57), -INT8_C(  70), -INT8_C(  67), -INT8_C(  50), -INT8_C(  91),  INT8_C(  59),  INT8_C(  57) } },
    { { -INT8_C(  68), -INT8_C(  21), -INT8_C(  56),  INT8_C(  17), -INT8_C( 104), -INT8_C(  93),  INT8_C(  39), -INT8_C(   8),
        -INT8_C(  50), -INT8_C(  20),  INT8_C(  90), -INT8_C(  72), -INT8_C(  67), -INT8_C(  36), -INT8_C(  68), -INT8_C( 109) },
      { -INT8_C(  96), -INT8_C(  11),  INT8_C(  96),  INT8_C(  91),  INT8_C(  46),  INT8_C(  30),  INT8_C(  51), -INT8_C(   3),
        -INT8_C(  89), -INT8_C(  39),  INT8_C(  78), -INT8_C(  29),  INT8_C(  32), -INT8_C( 121), -INT8_C( 109), -INT8_C(  35) },
      { -INT8_C(  68), -INT8_C(  56), -INT8_C( 104),  INT8_C(  39), -INT8_C(  50),  INT8_C(  90), -INT8_C(  67), -INT8_C(  68),
        -INT8_C(  96),  INT8_C(  96),  INT8_C(  46),  INT8_C(  51), -INT8_C(  89),  INT8_C(  78),  INT8_C(  32), -INT8_C( 109) } },
    { {  INT8_C( 114),  INT8_C(  91), -INT8_C(  18),  INT8_C(  11), -INT8_C(   2),  INT8_C(  21),  INT8_C(   3), -INT8_C(  51),
         INT8_C(   2),  INT8_C(  93), -INT8_C( 123), -INT8_C(  65),  INT8_C(  58),  INT8_C(  66),  INT8_C(  82), -INT8_C(  38) },
      {  INT8_C(  55), -INT8_C(  78),  INT8_C(  53),  INT8_C( 102), -INT8_C(  48),  INT8_C( 105),  INT8_C(  99),  INT8_C( 120),
         INT8_C(  66), -INT8_C(  79),  INT8_C(  91),  INT8_C(  98),  INT8_C(  56), -INT8_C(  18),  INT8_C(  63), -INT8_C(  85) },
      {  INT8_C( 114), -INT8_C(  18), -INT8_C(   2),  INT8_C(   3),  INT8_C(   2), -INT8_C( 123),  INT8_C(  58),  INT8_C(  82),
         INT8_C(  55),  INT8_C(  53), -INT8_C(  48),  INT8_C(  99),  INT8_C(  66),  INT8_C(  91),  INT8_C(  56),  INT8_C(  63) } },
    { {  INT8_C(  74),  INT8_C(  45), -INT8_C(  74),  INT8_C(  72),  INT8_C(  67), -INT8_C(  71),  INT8_C(  21),  INT8_C(  69),
         INT8_C(  23), -INT8_C( 101),  INT8_C(   4),  INT8_C(  81), -INT8_C(  35),  INT8_C(  86),  INT8_C(  43),  INT8_C(  20) },
      {  INT8_C(   8),  INT8_C(  97),  INT8_C( 122), -INT8_C(  39), -INT8_C(  54), -INT8_C(  35),  INT8_C(  81),  INT8_C(  12),
        -INT8_C( 114), -INT8_C(  84),  INT8_C( 110), -INT8_C(  57), -INT8_C( 102), -INT8_C(  82),  INT8_C( 114), -INT8_C(  28) },
      {  INT8_C(  74), -INT8_C(  74),  INT8_C(  67),  INT8_C(  21),  INT8_C(  23),  INT8_C(   4), -INT8_C(  35),  INT8_C(  43),
         INT8_C(   8),  INT8_C( 122), -INT8_C(  54),  INT8_C(  81), -INT8_C( 114),  INT8_C( 110), -INT8_C( 102),  INT8_C( 114) } },
    { { -INT8_C(  37),  INT8_C(  40),  INT8_C(  45),  INT8_C(  30), -INT8_C(  31),  INT8_C(  66),  INT8_C(  99), -INT8_C(   8),
        -INT8_C(  35),  INT8_C( 103),  INT8_C(  73), -INT8_C(  70), -INT8_C(  67),  INT8_C( 117), -INT8_C(  49), -INT8_C(  58) },
      { -INT8_C(  42),  INT8_C(  73), -INT8_C(  97), -INT8_C(  96),  INT8_C(  39), -INT8_C(  16), -INT8_C(  84), -INT8_C(  75),
        -INT8_C( 100),  INT8_C(  26),  INT8_C( 124),  INT8_C(  54), -INT8_C(  56), -INT8_C(  18),  INT8_C(  27), -INT8_C(  92) },
      { -INT8_C(  37),  INT8_C(  45), -INT8_C(  31),  INT8_C(  99), -INT8_C(  35),  INT8_C(  73), -INT8_C(  67), -INT8_C(  49),
        -INT8_C(  42), -INT8_C(  97),  INT8_C(  39), -INT8_C(  84), -INT8_C( 100),  INT8_C( 124), -INT8_C(  56),  INT8_C(  27) } },
    { {  INT8_C(  22),  INT8_C(  72), -INT8_C(  62), -INT8_C(   8), -INT8_C( 118),  INT8_C(  38), -INT8_C(  16),  INT8_C( 104),
        -INT8_C( 115),  INT8_C(  58),  INT8_C(  34),  INT8_C(  75), -INT8_C(  81), -INT8_C(  15),  INT8_C(  17), -INT8_C( 123) },
      {  INT8_C(  59), -INT8_C(  80),  INT8_C(  37),  INT8_C(  98), -INT8_C(  96), -INT8_C(  47),  INT8_C(  23),  INT8_C(  60),
        -INT8_C(  21), -INT8_C( 108),  INT8_C( 114), -INT8_C(  76), -INT8_C( 126), -INT8_C( 115),  INT8_C(  88), -INT8_C( 103) },
      {  INT8_C(  22), -INT8_C(  62), -INT8_C( 118), -INT8_C(  16), -INT8_C( 115),  INT8_C(  34), -INT8_C(  81),  INT8_C(  17),
         INT8_C(  59),  INT8_C(  37), -INT8_C(  96),  INT8_C(  23), -INT8_C(  21),  INT8_C( 114), -INT8_C( 126),  INT8_C(  88) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vuzp1q_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1q_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 28802), -INT16_C(  8035), -INT16_C( 32633), -INT16_C( 25299), -INT16_C( 17451), -INT16_C( 23212), -INT16_C( 14430), -INT16_C( 10436) },
      {  INT16_C(   120), -INT16_C(   141), -INT16_C( 24402),  INT16_C( 14459),  INT16_C(  3588), -INT16_C( 13077),  INT16_C( 29855),  INT16_C(  8734) },
      {  INT16_C( 28802), -INT16_C( 32633), -INT16_C( 17451), -INT16_C( 14430),  INT16_C(   120), -INT16_C( 24402),  INT16_C(  3588),  INT16_C( 29855) } },
    { { -INT16_C( 17179),  INT16_C( 27650),  INT16_C( 12092),  INT16_C(  4362),  INT16_C( 24298), -INT16_C( 29514), -INT16_C(  3546), -INT16_C( 24989) },
      { -INT16_C( 10254), -INT16_C( 24419),  INT16_C(  6263),  INT16_C( 31704), -INT16_C( 15322), -INT16_C( 14777),  INT16_C( 25912),  INT16_C(  7656) },
      { -INT16_C( 17179),  INT16_C( 12092),  INT16_C( 24298), -INT16_C(  3546), -INT16_C( 10254),  INT16_C(  6263), -INT16_C( 15322),  INT16_C( 25912) } },
    { { -INT16_C(  5599),  INT16_C( 23946), -INT16_C( 27623),  INT16_C(   878),  INT16_C(  9458),  INT16_C(  6287), -INT16_C(  3561),  INT16_C(  2486) },
      {  INT16_C( 21449),  INT16_C( 16554), -INT16_C( 32149), -INT16_C( 27973),  INT16_C(   582),  INT16_C( 32600),  INT16_C( 16488), -INT16_C( 30308) },
      { -INT16_C(  5599), -INT16_C( 27623),  INT16_C(  9458), -INT16_C(  3561),  INT16_C( 21449), -INT16_C( 32149),  INT16_C(   582),  INT16_C( 16488) } },
    { {  INT16_C(  9770),  INT16_C( 17383),  INT16_C( 21946), -INT16_C( 21178), -INT16_C( 10886), -INT16_C( 28219),  INT16_C( 31943), -INT16_C( 28262) },
      {  INT16_C( 17615),  INT16_C( 15313), -INT16_C( 29241),  INT16_C(  3533),  INT16_C(  9615), -INT16_C(  2164),  INT16_C( 10597), -INT16_C( 28799) },
      {  INT16_C(  9770),  INT16_C( 21946), -INT16_C( 10886),  INT16_C( 31943),  INT16_C( 17615), -INT16_C( 29241),  INT16_C(  9615),  INT16_C( 10597) } },
    { {  INT16_C( 26703),  INT16_C(  2770),  INT16_C(  6333),  INT16_C( 14263),  INT16_C( 31981), -INT16_C( 19256),  INT16_C( 25592), -INT16_C( 14267) },
      {  INT16_C(  6055),  INT16_C( 28163), -INT16_C( 12124),  INT16_C( 13180),  INT16_C(  2293),  INT16_C( 23083), -INT16_C( 21455), -INT16_C( 32279) },
      {  INT16_C( 26703),  INT16_C(  6333),  INT16_C( 31981),  INT16_C( 25592),  INT16_C(  6055), -INT16_C( 12124),  INT16_C(  2293), -INT16_C( 21455) } },
    { { -INT16_C( 17644), -INT16_C( 11893),  INT16_C( 17107), -INT16_C( 16375), -INT16_C( 11842), -INT16_C( 18572), -INT16_C( 17868), -INT16_C(  9089) },
      { -INT16_C( 32047),  INT16_C( 30026), -INT16_C( 14766),  INT16_C( 18344), -INT16_C( 11313),  INT16_C(   161), -INT16_C( 30081), -INT16_C( 27775) },
      { -INT16_C( 17644),  INT16_C( 17107), -INT16_C( 11842), -INT16_C( 17868), -INT16_C( 32047), -INT16_C( 14766), -INT16_C( 11313), -INT16_C( 30081) } },
    { {  INT16_C(  3141),  INT16_C(  6245),  INT16_C( 28238),  INT16_C(  3544),  INT16_C( 19519),  INT16_C( 29892),  INT16_C( 17158), -INT16_C( 10416) },
      { -INT16_C( 25915),  INT16_C(  5964), -INT16_C(  2719),  INT16_C( 12382), -INT16_C(    56),  INT16_C( 18480), -INT16_C( 19831), -INT16_C( 12581) },
      {  INT16_C(  3141),  INT16_C( 28238),  INT16_C( 19519),  INT16_C( 17158), -INT16_C( 25915), -INT16_C(  2719), -INT16_C(    56), -INT16_C( 19831) } },
    { {  INT16_C( 16574),  INT16_C(  3558), -INT16_C( 16722), -INT16_C(  4582), -INT16_C(  8694),  INT16_C(  4450), -INT16_C( 19935), -INT16_C(  6424) },
      {  INT16_C( 13644), -INT16_C( 20995),  INT16_C( 23338), -INT16_C(  3363),  INT16_C(  3674), -INT16_C(  7366),  INT16_C(  5824),  INT16_C( 32433) },
      {  INT16_C( 16574), -INT16_C( 16722), -INT16_C(  8694), -INT16_C( 19935),  INT16_C( 13644),  INT16_C( 23338),  INT16_C(  3674),  INT16_C(  5824) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vuzp1q_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1q_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1658835482),  INT32_C(  1386526692),  INT32_C(   457295551), -INT32_C(  1136371809) },
      { -INT32_C(   238751028), -INT32_C(   509259920), -INT32_C(  1935223641),  INT32_C(  1865224840) },
      { -INT32_C(  1658835482),  INT32_C(   457295551), -INT32_C(   238751028), -INT32_C(  1935223641) } },
    { {  INT32_C(   604785983), -INT32_C(   998854652),  INT32_C(   383760502), -INT32_C(   606985457) },
      { -INT32_C(  2033412330), -INT32_C(  1905823258), -INT32_C(   837153467),  INT32_C(  1597851424) },
      {  INT32_C(   604785983),  INT32_C(   383760502), -INT32_C(  2033412330), -INT32_C(   837153467) } },
    { { -INT32_C(  1719449195),  INT32_C(  1885207289), -INT32_C(  1048166990),  INT32_C(  1989957728) },
      { -INT32_C(   688035601),  INT32_C(   526673113), -INT32_C(  1829929358),  INT32_C(  1525754565) },
      { -INT32_C(  1719449195), -INT32_C(  1048166990), -INT32_C(   688035601), -INT32_C(  1829929358) } },
    { {  INT32_C(  1827960179),  INT32_C(   568086895), -INT32_C(   270376306), -INT32_C(  1436188997) },
      { -INT32_C(  1082105114),  INT32_C(   970908871),  INT32_C(   684444514),  INT32_C(  1753398517) },
      {  INT32_C(  1827960179), -INT32_C(   270376306), -INT32_C(  1082105114),  INT32_C(   684444514) } },
    { { -INT32_C(  1596623311),  INT32_C(  1455534536), -INT32_C(   817519852),  INT32_C(   125414177) },
      { -INT32_C(   725091827),  INT32_C(  1091413470),  INT32_C(  1718212721), -INT32_C(   959452267) },
      { -INT32_C(  1596623311), -INT32_C(   817519852), -INT32_C(   725091827),  INT32_C(  1718212721) } },
    { {  INT32_C(   711435362),  INT32_C(  1770006613), -INT32_C(   315046196),  INT32_C(  2130031217) },
      { -INT32_C(  1974223700), -INT32_C(   758423455), -INT32_C(   835111879), -INT32_C(  2104227808) },
      {  INT32_C(   711435362), -INT32_C(   315046196), -INT32_C(  1974223700), -INT32_C(   835111879) } },
    { {  INT32_C(    28113836), -INT32_C(   261411804),  INT32_C(  1675469810),  INT32_C(    31642197) },
      { -INT32_C(   259246706), -INT32_C(   826124395), -INT32_C(  1398998132), -INT32_C(  1355927293) },
      {  INT32_C(    28113836),  INT32_C(  1675469810), -INT32_C(   259246706), -INT32_C(  1398998132) } },
    { {  INT32_C(  1353833004), -INT32_C(   113239034),  INT32_C(   358358719),  INT32_C(  2132164336) },
      {  INT32_C(   158311027), -INT32_C(  2032717318),  INT32_C(   808612909), -INT32_C(   773824347) },
      {  INT32_C(  1353833004),  INT32_C(   358358719),  INT32_C(   158311027),  INT32_C(   808612909) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vuzp1q_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1q_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 5827239787330973229),  INT64_C( 2915356885086758845) },
      {  INT64_C( 5814266470607118820), -INT64_C( 6457386186900046585) },
      {  INT64_C( 5827239787330973229),  INT64_C( 5814266470607118820) } },
    { { -INT64_C( 8901666173858462609), -INT64_C( 2476975425049424684) },
      {  INT64_C( 1531584572990988644), -INT64_C( 4655526498762125499) },
      { -INT64_C( 8901666173858462609),  INT64_C( 1531584572990988644) } },
    { {  INT64_C( 3805361778811302787), -INT64_C( 4197832719869321752) },
      { -INT64_C( 2012555291946232082), -INT64_C( 5650602259715461498) },
      {  INT64_C( 3805361778811302787), -INT64_C( 2012555291946232082) } },
    { { -INT64_C( 4679296260350641286), -INT64_C(  553839359093064663) },
      { -INT64_C( 8991430070435051851),  INT64_C( 6761010124897770483) },
      { -INT64_C( 4679296260350641286), -INT64_C( 8991430070435051851) } },
    { { -INT64_C( 4179543197053563031), -INT64_C( 5547132927536554237) },
      { -INT64_C( 1070378977852917595), -INT64_C( 3000552466135482853) },
      { -INT64_C( 4179543197053563031), -INT64_C( 1070378977852917595) } },
    { { -INT64_C( 2516079689914149963), -INT64_C( 6167699460678064714) },
      { -INT64_C( 3975145004899471641), -INT64_C( 9064581884553008912) },
      { -INT64_C( 2516079689914149963), -INT64_C( 3975145004899471641) } },
    { {  INT64_C( 1688260941073042357),  INT64_C( 3313578703455999821) },
      { -INT64_C( 6118448256376551264), -INT64_C( 5467584354072338993) },
      {  INT64_C( 1688260941073042357), -INT64_C( 6118448256376551264) } },
    { {  INT64_C( 2882500414803341959), -INT64_C( 6954552889939670007) },
      {  INT64_C( 4910053296832351934), -INT64_C( 1110982377861010208) },
      {  INT64_C( 2882500414803341959),  INT64_C( 4910053296832351934) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vuzp1q_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1q_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 13), UINT8_C( 30), UINT8_C(195), UINT8_C(224), UINT8_C(  7), UINT8_C( 80), UINT8_C(120), UINT8_C( 64),
        UINT8_C(227), UINT8_C( 90), UINT8_C(198), UINT8_C( 93), UINT8_C( 80), UINT8_C( 77), UINT8_C( 92), UINT8_C( 51) },
      { UINT8_C(139), UINT8_C( 36), UINT8_C(  9), UINT8_C( 63), UINT8_C(133), UINT8_C( 65), UINT8_C( 27), UINT8_C(182),
        UINT8_C(157), UINT8_C(178), UINT8_C(119), UINT8_C(192), UINT8_C(218), UINT8_C(  9), UINT8_C(107), UINT8_C(231) },
      { UINT8_C( 13), UINT8_C(195), UINT8_C(  7), UINT8_C(120), UINT8_C(227), UINT8_C(198), UINT8_C( 80), UINT8_C( 92),
        UINT8_C(139), UINT8_C(  9), UINT8_C(133), UINT8_C( 27), UINT8_C(157), UINT8_C(119), UINT8_C(218), UINT8_C(107) } },
    { { UINT8_C( 39), UINT8_C( 46), UINT8_C(199), UINT8_C( 46), UINT8_C(127), UINT8_C( 64), UINT8_C(110), UINT8_C( 98),
        UINT8_C(154), UINT8_C( 53), UINT8_C(191), UINT8_C(234), UINT8_C(130), UINT8_C( 27), UINT8_C( 29), UINT8_C( 14) },
      { UINT8_C( 63), UINT8_C( 38), UINT8_C( 77), UINT8_C(197), UINT8_C(104), UINT8_C(104), UINT8_C(123), UINT8_C(  5),
        UINT8_C( 26), UINT8_C(242), UINT8_C(197), UINT8_C(244), UINT8_C(251), UINT8_C( 48), UINT8_C(220), UINT8_C( 35) },
      { UINT8_C( 39), UINT8_C(199), UINT8_C(127), UINT8_C(110), UINT8_C(154), UINT8_C(191), UINT8_C(130), UINT8_C( 29),
        UINT8_C( 63), UINT8_C( 77), UINT8_C(104), UINT8_C(123), UINT8_C( 26), UINT8_C(197), UINT8_C(251), UINT8_C(220) } },
    { { UINT8_C( 95), UINT8_C(163), UINT8_C( 81), UINT8_C(222), UINT8_C(227), UINT8_C(192), UINT8_C( 64), UINT8_C(126),
        UINT8_C(245),    UINT8_MAX, UINT8_C(104), UINT8_C(119), UINT8_C( 26), UINT8_C(134), UINT8_C(133), UINT8_C( 89) },
      { UINT8_C(172), UINT8_C(210), UINT8_C( 30), UINT8_C( 20), UINT8_C( 58), UINT8_C(153), UINT8_C( 26), UINT8_C( 85),
        UINT8_C(139), UINT8_C(223), UINT8_C( 73), UINT8_C(135), UINT8_C( 16), UINT8_C( 37), UINT8_C(170), UINT8_C(111) },
      { UINT8_C( 95), UINT8_C( 81), UINT8_C(227), UINT8_C( 64), UINT8_C(245), UINT8_C(104), UINT8_C( 26), UINT8_C(133),
        UINT8_C(172), UINT8_C( 30), UINT8_C( 58), UINT8_C( 26), UINT8_C(139), UINT8_C( 73), UINT8_C( 16), UINT8_C(170) } },
    { { UINT8_C(201), UINT8_C(251), UINT8_C( 77), UINT8_C(172), UINT8_C(187), UINT8_C(141), UINT8_C( 42), UINT8_C(176),
        UINT8_C(140), UINT8_C(147), UINT8_C( 40), UINT8_C(166), UINT8_C( 25), UINT8_C(173),    UINT8_MAX, UINT8_C(197) },
      { UINT8_C(128), UINT8_C( 30), UINT8_C(218), UINT8_C(186), UINT8_C(183), UINT8_C(244), UINT8_C( 15), UINT8_C( 67),
        UINT8_C(211), UINT8_C( 89), UINT8_C(202), UINT8_C(227), UINT8_C(126), UINT8_C(116), UINT8_C( 82), UINT8_C( 71) },
      { UINT8_C(201), UINT8_C( 77), UINT8_C(187), UINT8_C( 42), UINT8_C(140), UINT8_C( 40), UINT8_C( 25),    UINT8_MAX,
        UINT8_C(128), UINT8_C(218), UINT8_C(183), UINT8_C( 15), UINT8_C(211), UINT8_C(202), UINT8_C(126), UINT8_C( 82) } },
    { { UINT8_C(111), UINT8_C(159), UINT8_C(244), UINT8_C( 43), UINT8_C( 44), UINT8_C( 30), UINT8_C(219), UINT8_C(184),
        UINT8_C(177), UINT8_C(  3), UINT8_C( 94), UINT8_C(202), UINT8_C(177), UINT8_C( 94), UINT8_C(144), UINT8_C( 49) },
      { UINT8_C(124), UINT8_C(106), UINT8_C(235), UINT8_C( 51), UINT8_C( 94), UINT8_C(251), UINT8_C(118), UINT8_C( 49),
        UINT8_C( 84), UINT8_C( 64), UINT8_C( 21), UINT8_C(210), UINT8_C(180), UINT8_C(103), UINT8_C( 26), UINT8_C( 36) },
      { UINT8_C(111), UINT8_C(244), UINT8_C( 44), UINT8_C(219), UINT8_C(177), UINT8_C( 94), UINT8_C(177), UINT8_C(144),
        UINT8_C(124), UINT8_C(235), UINT8_C( 94), UINT8_C(118), UINT8_C( 84), UINT8_C( 21), UINT8_C(180), UINT8_C( 26) } },
    { { UINT8_C(  7), UINT8_C( 14), UINT8_C( 79), UINT8_C( 51), UINT8_C( 44), UINT8_C( 42), UINT8_C(236), UINT8_C(222),
        UINT8_C( 46), UINT8_C( 74), UINT8_C(168), UINT8_C(223), UINT8_C(168), UINT8_C( 56), UINT8_C( 16), UINT8_C( 36) },
      { UINT8_C(162), UINT8_C(251), UINT8_C( 88), UINT8_C(  0), UINT8_C(246), UINT8_C(206), UINT8_C( 50), UINT8_C( 74),
        UINT8_C( 15), UINT8_C( 71), UINT8_C( 29), UINT8_C(195), UINT8_C(174), UINT8_C( 55), UINT8_C(231), UINT8_C(181) },
      { UINT8_C(  7), UINT8_C( 79), UINT8_C( 44), UINT8_C(236), UINT8_C( 46), UINT8_C(168), UINT8_C(168), UINT8_C( 16),
        UINT8_C(162), UINT8_C( 88), UINT8_C(246), UINT8_C( 50), UINT8_C( 15), UINT8_C( 29), UINT8_C(174), UINT8_C(231) } },
    { { UINT8_C( 69), UINT8_C( 54), UINT8_C(233), UINT8_C(113), UINT8_C( 97), UINT8_C(213), UINT8_C( 79), UINT8_C(143),
        UINT8_C( 31), UINT8_C(248), UINT8_C(110), UINT8_C(200), UINT8_C( 48), UINT8_C(126), UINT8_C(236), UINT8_C(211) },
      { UINT8_C(121), UINT8_C( 68), UINT8_C(211), UINT8_C(112), UINT8_C( 19), UINT8_C(  5), UINT8_C(186), UINT8_C( 34),
        UINT8_C( 76), UINT8_C(215), UINT8_C(229), UINT8_C(251), UINT8_C( 14), UINT8_C(205), UINT8_C(176), UINT8_C( 83) },
      { UINT8_C( 69), UINT8_C(233), UINT8_C( 97), UINT8_C( 79), UINT8_C( 31), UINT8_C(110), UINT8_C( 48), UINT8_C(236),
        UINT8_C(121), UINT8_C(211), UINT8_C( 19), UINT8_C(186), UINT8_C( 76), UINT8_C(229), UINT8_C( 14), UINT8_C(176) } },
    { { UINT8_C(  3), UINT8_C(153), UINT8_C(197), UINT8_C(100), UINT8_C(110), UINT8_C( 20), UINT8_C(243), UINT8_C(142),
        UINT8_C( 12), UINT8_C( 97), UINT8_C( 86), UINT8_C( 61), UINT8_C(223), UINT8_C( 66), UINT8_C( 16), UINT8_C( 89) },
      { UINT8_C(135), UINT8_C(227), UINT8_C(201), UINT8_C(154), UINT8_C(233), UINT8_C(131), UINT8_C(188), UINT8_C( 53),
        UINT8_C( 91), UINT8_C(161), UINT8_C( 48), UINT8_C(105), UINT8_C(110), UINT8_C(225), UINT8_C(189), UINT8_C(114) },
      { UINT8_C(  3), UINT8_C(197), UINT8_C(110), UINT8_C(243), UINT8_C( 12), UINT8_C( 86), UINT8_C(223), UINT8_C( 16),
        UINT8_C(135), UINT8_C(201), UINT8_C(233), UINT8_C(188), UINT8_C( 91), UINT8_C( 48), UINT8_C(110), UINT8_C(189) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vuzp1q_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1q_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 5468), UINT16_C(62275), UINT16_C(44648), UINT16_C(16027), UINT16_C(21390), UINT16_C( 3408), UINT16_C(46720), UINT16_C(12823) },
      { UINT16_C(55771), UINT16_C(60892), UINT16_C(60923), UINT16_C(16505), UINT16_C(32383), UINT16_C(21278), UINT16_C(52886), UINT16_C(62044) },
      { UINT16_C( 5468), UINT16_C(44648), UINT16_C(21390), UINT16_C(46720), UINT16_C(55771), UINT16_C(60923), UINT16_C(32383), UINT16_C(52886) } },
    { { UINT16_C(40931), UINT16_C(19429), UINT16_C(33101), UINT16_C(56457), UINT16_C(55764), UINT16_C(21737), UINT16_C(  143), UINT16_C(27270) },
      { UINT16_C(25306), UINT16_C(54615), UINT16_C(53327), UINT16_C(52757), UINT16_C(13390), UINT16_C(58402), UINT16_C(32258), UINT16_C(58839) },
      { UINT16_C(40931), UINT16_C(33101), UINT16_C(55764), UINT16_C(  143), UINT16_C(25306), UINT16_C(53327), UINT16_C(13390), UINT16_C(32258) } },
    { { UINT16_C(48157), UINT16_C(27441), UINT16_C(47677), UINT16_C( 4423), UINT16_C(12436), UINT16_C( 9061), UINT16_C(60209), UINT16_C( 2958) },
      { UINT16_C(58702), UINT16_C(40416), UINT16_C(63158), UINT16_C( 1132), UINT16_C(36394), UINT16_C(11497), UINT16_C(49164), UINT16_C(10513) },
      { UINT16_C(48157), UINT16_C(47677), UINT16_C(12436), UINT16_C(60209), UINT16_C(58702), UINT16_C(63158), UINT16_C(36394), UINT16_C(49164) } },
    { { UINT16_C(17020), UINT16_C(47764), UINT16_C(56317), UINT16_C(37323), UINT16_C(12556), UINT16_C(15796), UINT16_C(16924), UINT16_C(27208) },
      { UINT16_C(10280), UINT16_C(56840), UINT16_C(29726), UINT16_C(18658), UINT16_C(51970), UINT16_C( 3700), UINT16_C(34443), UINT16_C( 2103) },
      { UINT16_C(17020), UINT16_C(56317), UINT16_C(12556), UINT16_C(16924), UINT16_C(10280), UINT16_C(29726), UINT16_C(51970), UINT16_C(34443) } },
    { { UINT16_C(52424), UINT16_C(50626), UINT16_C(36263), UINT16_C(45910), UINT16_C( 3006), UINT16_C(56304), UINT16_C(14413), UINT16_C(30021) },
      { UINT16_C(19809), UINT16_C(32595), UINT16_C(14017), UINT16_C(50120), UINT16_C(15361), UINT16_C(36305), UINT16_C( 2498), UINT16_C(35733) },
      { UINT16_C(52424), UINT16_C(36263), UINT16_C( 3006), UINT16_C(14413), UINT16_C(19809), UINT16_C(14017), UINT16_C(15361), UINT16_C( 2498) } },
    { { UINT16_C(22485), UINT16_C(31824), UINT16_C(42980), UINT16_C(41776), UINT16_C( 8370), UINT16_C(65406), UINT16_C(50009), UINT16_C(47733) },
      { UINT16_C(51217), UINT16_C(53817), UINT16_C(  510), UINT16_C(  150), UINT16_C(26430), UINT16_C(  141), UINT16_C( 8816), UINT16_C(17803) },
      { UINT16_C(22485), UINT16_C(42980), UINT16_C( 8370), UINT16_C(50009), UINT16_C(51217), UINT16_C(  510), UINT16_C(26430), UINT16_C( 8816) } },
    { { UINT16_C(56441), UINT16_C(24002), UINT16_C(62083), UINT16_C(13568), UINT16_C(32274), UINT16_C(27444), UINT16_C(43330), UINT16_C(21285) },
      { UINT16_C(24434), UINT16_C(28709), UINT16_C(47968), UINT16_C(40560), UINT16_C(64803), UINT16_C(37791), UINT16_C(10783), UINT16_C(39129) },
      { UINT16_C(56441), UINT16_C(62083), UINT16_C(32274), UINT16_C(43330), UINT16_C(24434), UINT16_C(47968), UINT16_C(64803), UINT16_C(10783) } },
    { { UINT16_C(39686), UINT16_C(35318), UINT16_C(63117), UINT16_C(40894), UINT16_C(62325), UINT16_C(46859), UINT16_C(12444), UINT16_C( 3594) },
      { UINT16_C(12175), UINT16_C(61567), UINT16_C(61419), UINT16_C( 3726), UINT16_C(11757), UINT16_C( 3233), UINT16_C(31320), UINT16_C(24229) },
      { UINT16_C(39686), UINT16_C(63117), UINT16_C(62325), UINT16_C(12444), UINT16_C(12175), UINT16_C(61419), UINT16_C(11757), UINT16_C(31320) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vuzp1q_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1q_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 676667838), UINT32_C(2715607902), UINT32_C(2426014406), UINT32_C(3446879341) },
      { UINT32_C(3643743832), UINT32_C(2346026890), UINT32_C( 842992455), UINT32_C(2599884251) },
      { UINT32_C( 676667838), UINT32_C(2426014406), UINT32_C(3643743832), UINT32_C( 842992455) } },
    { { UINT32_C(2495761462), UINT32_C(4130709040), UINT32_C( 361156776), UINT32_C(1575221508) },
      { UINT32_C(2721452568), UINT32_C(3761048729), UINT32_C(4061293591), UINT32_C(3096185217) },
      { UINT32_C(2495761462), UINT32_C( 361156776), UINT32_C(2721452568), UINT32_C(4061293591) } },
    { { UINT32_C(2253147734), UINT32_C(2507965164), UINT32_C(1453982546), UINT32_C( 347311612) },
      { UINT32_C( 951577247), UINT32_C( 219735286), UINT32_C(3539937873), UINT32_C(2324335668) },
      { UINT32_C(2253147734), UINT32_C(1453982546), UINT32_C( 951577247), UINT32_C(3539937873) } },
    { { UINT32_C(3339769818), UINT32_C(2874969177), UINT32_C(2348877455), UINT32_C( 866170260) },
      { UINT32_C(2506905503), UINT32_C(2376238140), UINT32_C(3814695343), UINT32_C( 141421101) },
      { UINT32_C(3339769818), UINT32_C(2348877455), UINT32_C(2506905503), UINT32_C(3814695343) } },
    { { UINT32_C( 449805761), UINT32_C(2579835657), UINT32_C(3307587121), UINT32_C( 452576635) },
      { UINT32_C(1504666909), UINT32_C(2565231081), UINT32_C( 544949747), UINT32_C(4029212719) },
      { UINT32_C( 449805761), UINT32_C(3307587121), UINT32_C(1504666909), UINT32_C( 544949747) } },
    { { UINT32_C(1862989669), UINT32_C(1409863458), UINT32_C( 286862742), UINT32_C( 254546674) },
      { UINT32_C(1634261879), UINT32_C( 553209389), UINT32_C(3275781524), UINT32_C(3283380573) },
      { UINT32_C(1862989669), UINT32_C( 286862742), UINT32_C(1634261879), UINT32_C(3275781524) } },
    { { UINT32_C(2201140832), UINT32_C( 618085006), UINT32_C(1496707175), UINT32_C(2053726467) },
      { UINT32_C(1792790845), UINT32_C(3028997408), UINT32_C(2809645642), UINT32_C(2489985843) },
      { UINT32_C(2201140832), UINT32_C(1496707175), UINT32_C(1792790845), UINT32_C(2809645642) } },
    { { UINT32_C(2014813418), UINT32_C(1033694934), UINT32_C(3784823262), UINT32_C(1885077555) },
      { UINT32_C(4057610193), UINT32_C(1453679628), UINT32_C(1660820782), UINT32_C( 855009352) },
      { UINT32_C(2014813418), UINT32_C(3784823262), UINT32_C(4057610193), UINT32_C(1660820782) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vuzp1q_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vuzp1q_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(16117741059595622227), UINT64_C( 2565286127910827920) },
      { UINT64_C(  500143091789421190), UINT64_C(10628186432806376979) },
      { UINT64_C(16117741059595622227), UINT64_C(  500143091789421190) } },
    { { UINT64_C(12950214132161407935), UINT64_C( 6153497975068038174) },
      { UINT64_C( 5727240880030441463), UINT64_C( 3380185094979684373) },
      { UINT64_C(12950214132161407935), UINT64_C( 5727240880030441463) } },
    { { UINT64_C( 2816367189010391615), UINT64_C(12679549088990567123) },
      { UINT64_C(11149117747892602157), UINT64_C( 2505647239719816999) },
      { UINT64_C( 2816367189010391615), UINT64_C(11149117747892602157) } },
    { { UINT64_C( 6821433410092059770), UINT64_C( 1088453712281605043) },
      { UINT64_C(  385959220597046844), UINT64_C(11405191389216787266) },
      { UINT64_C( 6821433410092059770), UINT64_C(  385959220597046844) } },
    { { UINT64_C( 1736362389326187310), UINT64_C( 5391262915657668832) },
      { UINT64_C(13888370619831765979), UINT64_C(16822401168388217266) },
      { UINT64_C( 1736362389326187310), UINT64_C(13888370619831765979) } },
    { { UINT64_C( 4860433358764808183), UINT64_C( 7938675798306059986) },
      { UINT64_C( 5791880490741348130), UINT64_C( 7557775138006451518) },
      { UINT64_C( 4860433358764808183), UINT64_C( 5791880490741348130) } },
    { { UINT64_C( 1286401389819561011), UINT64_C(15577703406384635693) },
      { UINT64_C( 8738065454028314197), UINT64_C( 4176618091569113629) },
      { UINT64_C( 1286401389819561011), UINT64_C( 8738065454028314197) } },
    { { UINT64_C( 2173456247646370520), UINT64_C(10238950491402738569) },
      { UINT64_C( 9735029126993121637), UINT64_C(13289855178218244911) },
      { UINT64_C( 2173456247646370520), UINT64_C( 9735029126993121637) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vuzp1q_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp1q_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
