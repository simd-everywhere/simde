#define SIMDE_TEST_ARM_NEON_INSN zip1

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/zip1.h>

static int
test_simde_vzip1_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -594.82), SIMDE_FLOAT32_C(   -36.31) },
      { SIMDE_FLOAT32_C(   -44.16), SIMDE_FLOAT32_C(  -416.70) },
      { SIMDE_FLOAT32_C(  -594.82), SIMDE_FLOAT32_C(   -44.16) } },
    { { SIMDE_FLOAT32_C(  -546.79), SIMDE_FLOAT32_C(   545.60) },
      { SIMDE_FLOAT32_C(  -407.46), SIMDE_FLOAT32_C(   803.36) },
      { SIMDE_FLOAT32_C(  -546.79), SIMDE_FLOAT32_C(  -407.46) } },
    { { SIMDE_FLOAT32_C(  -396.25), SIMDE_FLOAT32_C(  -289.22) },
      { SIMDE_FLOAT32_C(   158.83), SIMDE_FLOAT32_C(   797.31) },
      { SIMDE_FLOAT32_C(  -396.25), SIMDE_FLOAT32_C(   158.83) } },
    { { SIMDE_FLOAT32_C(   984.23), SIMDE_FLOAT32_C(   -68.91) },
      { SIMDE_FLOAT32_C(   830.88), SIMDE_FLOAT32_C(  -995.28) },
      { SIMDE_FLOAT32_C(   984.23), SIMDE_FLOAT32_C(   830.88) } },
    { { SIMDE_FLOAT32_C(  -188.76), SIMDE_FLOAT32_C(   262.91) },
      { SIMDE_FLOAT32_C(   778.87), SIMDE_FLOAT32_C(  -450.18) },
      { SIMDE_FLOAT32_C(  -188.76), SIMDE_FLOAT32_C(   778.87) } },
    { { SIMDE_FLOAT32_C(   915.01), SIMDE_FLOAT32_C(   593.75) },
      { SIMDE_FLOAT32_C(   831.12), SIMDE_FLOAT32_C(  -136.74) },
      { SIMDE_FLOAT32_C(   915.01), SIMDE_FLOAT32_C(   831.12) } },
    { { SIMDE_FLOAT32_C(   353.93), SIMDE_FLOAT32_C(   120.70) },
      { SIMDE_FLOAT32_C(  -711.16), SIMDE_FLOAT32_C(  -974.32) },
      { SIMDE_FLOAT32_C(   353.93), SIMDE_FLOAT32_C(  -711.16) } },
    { { SIMDE_FLOAT32_C(  -502.47), SIMDE_FLOAT32_C(   570.22) },
      { SIMDE_FLOAT32_C(   392.65), SIMDE_FLOAT32_C(   -97.29) },
      { SIMDE_FLOAT32_C(  -502.47), SIMDE_FLOAT32_C(   392.65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vzip1_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vzip1_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  75),  INT8_C(  64),  INT8_C(  23), -INT8_C(  70), -INT8_C(  20), -INT8_C(  62), -INT8_C( 104),  INT8_C(   0) },
      {  INT8_C(  77), -INT8_C(  69), -INT8_C( 118),  INT8_C(  40), -INT8_C(  21),  INT8_C(  81),  INT8_C(  79), -INT8_C(  43) },
      {  INT8_C(  75),  INT8_C(  77),  INT8_C(  64), -INT8_C(  69),  INT8_C(  23), -INT8_C( 118), -INT8_C(  70),  INT8_C(  40) } },
    { { -INT8_C(  10),  INT8_C(  47), -INT8_C(  91), -INT8_C(  90),  INT8_C(  57), -INT8_C(  23), -INT8_C(  71), -INT8_C(   7) },
      { -INT8_C(  83),  INT8_C( 112),  INT8_C(  83), -INT8_C(  15),  INT8_C(  26), -INT8_C(  11), -INT8_C( 125),  INT8_C( 101) },
      { -INT8_C(  10), -INT8_C(  83),  INT8_C(  47),  INT8_C( 112), -INT8_C(  91),  INT8_C(  83), -INT8_C(  90), -INT8_C(  15) } },
    { {  INT8_C(  53), -INT8_C( 102),  INT8_C(  32),  INT8_C(  33),  INT8_C(  93), -INT8_C(  72),  INT8_C(  33), -INT8_C(  86) },
      {  INT8_C( 115), -INT8_C(  84), -INT8_C(  46),  INT8_C(  95), -INT8_C(   3),  INT8_C(  33),  INT8_C(  52), -INT8_C(  13) },
      {  INT8_C(  53),  INT8_C( 115), -INT8_C( 102), -INT8_C(  84),  INT8_C(  32), -INT8_C(  46),  INT8_C(  33),  INT8_C(  95) } },
    { {  INT8_C(  81), -INT8_C(  39), -INT8_C( 103), -INT8_C( 118), -INT8_C(  62),  INT8_C(  82), -INT8_C( 125),  INT8_C( 111) },
      { -INT8_C(  61), -INT8_C(  42),  INT8_C(  97), -INT8_C(  35), -INT8_C(  53), -INT8_C(  28),  INT8_C(  67),  INT8_C(   1) },
      {  INT8_C(  81), -INT8_C(  61), -INT8_C(  39), -INT8_C(  42), -INT8_C( 103),  INT8_C(  97), -INT8_C( 118), -INT8_C(  35) } },
    { {      INT8_MAX,  INT8_C(  99),  INT8_C(  34), -INT8_C(  36),  INT8_C(  27),  INT8_C(  68), -INT8_C( 122), -INT8_C( 114) },
      { -INT8_C(  16),  INT8_C(  88), -INT8_C(  19), -INT8_C(  19),  INT8_C( 122),  INT8_C(  33), -INT8_C(  31), -INT8_C(  53) },
      {      INT8_MAX, -INT8_C(  16),  INT8_C(  99),  INT8_C(  88),  INT8_C(  34), -INT8_C(  19), -INT8_C(  36), -INT8_C(  19) } },
    { { -INT8_C(   5),  INT8_C( 122),  INT8_C(  85), -INT8_C(  67), -INT8_C(  51), -INT8_C(  40),  INT8_C(  45), -INT8_C( 112) },
      { -INT8_C(  82), -INT8_C( 114),  INT8_C( 109),  INT8_C( 121),  INT8_C( 114), -INT8_C(  80),  INT8_C( 122), -INT8_C(  15) },
      { -INT8_C(   5), -INT8_C(  82),  INT8_C( 122), -INT8_C( 114),  INT8_C(  85),  INT8_C( 109), -INT8_C(  67),  INT8_C( 121) } },
    { {  INT8_C(  19), -INT8_C(  99), -INT8_C(  51),  INT8_C(  46), -INT8_C(  31),  INT8_C(  83), -INT8_C(  67), -INT8_C(  47) },
      { -INT8_C(  84), -INT8_C(  86), -INT8_C(  66),  INT8_C(  38), -INT8_C(  52), -INT8_C(  97), -INT8_C(  15), -INT8_C(  57) },
      {  INT8_C(  19), -INT8_C(  84), -INT8_C(  99), -INT8_C(  86), -INT8_C(  51), -INT8_C(  66),  INT8_C(  46),  INT8_C(  38) } },
    { {  INT8_C(  26),  INT8_C(  70), -INT8_C( 124), -INT8_C(  25),  INT8_C(  30), -INT8_C(  79),  INT8_C( 119), -INT8_C(  52) },
      {  INT8_C(  63), -INT8_C(  28),  INT8_C(  69), -INT8_C(  78), -INT8_C( 107), -INT8_C(  64), -INT8_C(  93), -INT8_C(  88) },
      {  INT8_C(  26),  INT8_C(  63),  INT8_C(  70), -INT8_C(  28), -INT8_C( 124),  INT8_C(  69), -INT8_C(  25), -INT8_C(  78) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vzip1_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(  6394), -INT16_C(  7304),  INT16_C(  4761), -INT16_C( 23200) },
      {  INT16_C( 27245),  INT16_C(  9875), -INT16_C( 24091), -INT16_C( 25797) },
      {  INT16_C(  6394),  INT16_C( 27245), -INT16_C(  7304),  INT16_C(  9875) } },
    { { -INT16_C(   916), -INT16_C( 24207), -INT16_C(  2865), -INT16_C( 14036) },
      { -INT16_C( 31945),  INT16_C( 23444), -INT16_C( 22348), -INT16_C( 20771) },
      { -INT16_C(   916), -INT16_C( 31945), -INT16_C( 24207),  INT16_C( 23444) } },
    { {  INT16_C( 21953),  INT16_C( 23185), -INT16_C(  3736), -INT16_C( 10753) },
      { -INT16_C( 27812),  INT16_C( 16891),  INT16_C( 14132), -INT16_C( 24355) },
      {  INT16_C( 21953), -INT16_C( 27812),  INT16_C( 23185),  INT16_C( 16891) } },
    { {  INT16_C( 20019),  INT16_C(   834),  INT16_C( 28226),  INT16_C( 31436) },
      {  INT16_C( 24817), -INT16_C( 23083), -INT16_C( 19959), -INT16_C( 13741) },
      {  INT16_C( 20019),  INT16_C( 24817),  INT16_C(   834), -INT16_C( 23083) } },
    { { -INT16_C(  6905),  INT16_C( 28452),  INT16_C(  9174),  INT16_C( 12868) },
      {  INT16_C( 16566), -INT16_C(  5260),  INT16_C( 20855), -INT16_C( 21877) },
      { -INT16_C(  6905),  INT16_C( 16566),  INT16_C( 28452), -INT16_C(  5260) } },
    { { -INT16_C( 12897), -INT16_C(  7763),  INT16_C( 31036),  INT16_C( 11611) },
      {  INT16_C( 12506), -INT16_C(  7213),  INT16_C(  9954), -INT16_C(  5459) },
      { -INT16_C( 12897),  INT16_C( 12506), -INT16_C(  7763), -INT16_C(  7213) } },
    { { -INT16_C( 12021), -INT16_C(  7591), -INT16_C( 24844), -INT16_C( 21740) },
      { -INT16_C( 30498),  INT16_C( 21910),  INT16_C(  8665),  INT16_C( 30975) },
      { -INT16_C( 12021), -INT16_C( 30498), -INT16_C(  7591),  INT16_C( 21910) } },
    { { -INT16_C( 21009),  INT16_C( 11098), -INT16_C( 19162),  INT16_C(    88) },
      {  INT16_C( 11238), -INT16_C( 14109), -INT16_C( 28590),  INT16_C( 23986) },
      { -INT16_C( 21009),  INT16_C( 11238),  INT16_C( 11098), -INT16_C( 14109) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vzip1_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1426738482),  INT32_C(    30050468) },
      { -INT32_C(   404588153), -INT32_C(   112205881) },
      {  INT32_C(  1426738482), -INT32_C(   404588153) } },
    { { -INT32_C(  1485126862), -INT32_C(   789445372) },
      { -INT32_C(   141244937),  INT32_C(  1236357399) },
      { -INT32_C(  1485126862), -INT32_C(   141244937) } },
    { {  INT32_C(  1117699230), -INT32_C(   884774844) },
      { -INT32_C(  1447942686),  INT32_C(   916586756) },
      {  INT32_C(  1117699230), -INT32_C(  1447942686) } },
    { { -INT32_C(   908255803),  INT32_C(   429510690) },
      { -INT32_C(  1408225899),  INT32_C(   485868158) },
      { -INT32_C(   908255803), -INT32_C(  1408225899) } },
    { { -INT32_C(  1033988994), -INT32_C(   561143300) },
      { -INT32_C(   897105978),  INT32_C(    83962432) },
      { -INT32_C(  1033988994), -INT32_C(   897105978) } },
    { {  INT32_C(  1775164999),  INT32_C(  1132685230) },
      {  INT32_C(   317690772), -INT32_C(   751901355) },
      {  INT32_C(  1775164999),  INT32_C(   317690772) } },
    { {  INT32_C(  1972735097), -INT32_C(   212590035) },
      { -INT32_C(  1564550303),  INT32_C(  1286061829) },
      {  INT32_C(  1972735097), -INT32_C(  1564550303) } },
    { {  INT32_C(  1287026333),  INT32_C(  1921989085) },
      {  INT32_C(   579108812), -INT32_C(   571100316) },
      {  INT32_C(  1287026333),  INT32_C(   579108812) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vzip1_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(207), UINT8_C(175), UINT8_C( 76), UINT8_C(120), UINT8_C(200), UINT8_C(106), UINT8_C(207), UINT8_C(167) },
      { UINT8_C(  5), UINT8_C( 22), UINT8_C(155), UINT8_C( 62), UINT8_C(249), UINT8_C(184), UINT8_C(197), UINT8_C(224) },
      { UINT8_C(207), UINT8_C(  5), UINT8_C(175), UINT8_C( 22), UINT8_C( 76), UINT8_C(155), UINT8_C(120), UINT8_C( 62) } },
    { { UINT8_C( 52), UINT8_C(  5), UINT8_C( 80), UINT8_C( 18), UINT8_C(180), UINT8_C(  4), UINT8_C(  6), UINT8_C(243) },
      { UINT8_C(213), UINT8_C( 60), UINT8_C(131), UINT8_C(  8), UINT8_C(202), UINT8_C( 69), UINT8_C( 73), UINT8_C(154) },
      { UINT8_C( 52), UINT8_C(213), UINT8_C(  5), UINT8_C( 60), UINT8_C( 80), UINT8_C(131), UINT8_C( 18), UINT8_C(  8) } },
    { { UINT8_C(244), UINT8_C(149), UINT8_C( 18), UINT8_C(188), UINT8_C(  0), UINT8_C(225), UINT8_C(100), UINT8_C(  5) },
      { UINT8_C(248),    UINT8_MAX, UINT8_C( 68), UINT8_C(241), UINT8_C(183), UINT8_C(  9), UINT8_C(209), UINT8_C(235) },
      { UINT8_C(244), UINT8_C(248), UINT8_C(149),    UINT8_MAX, UINT8_C( 18), UINT8_C( 68), UINT8_C(188), UINT8_C(241) } },
    { { UINT8_C( 14), UINT8_C( 33), UINT8_C(254), UINT8_C(195), UINT8_C( 37), UINT8_C(  4), UINT8_C(182), UINT8_C(250) },
      { UINT8_C( 65), UINT8_C( 57), UINT8_C(  3), UINT8_C( 11), UINT8_C(126), UINT8_C( 76), UINT8_C(165), UINT8_C(114) },
      { UINT8_C( 14), UINT8_C( 65), UINT8_C( 33), UINT8_C( 57), UINT8_C(254), UINT8_C(  3), UINT8_C(195), UINT8_C( 11) } },
    { { UINT8_C(225), UINT8_C(184), UINT8_C( 47), UINT8_C(225), UINT8_C(153), UINT8_C(147), UINT8_C(231), UINT8_C(145) },
      { UINT8_C(146), UINT8_C( 43), UINT8_C(131), UINT8_C( 73), UINT8_C( 52), UINT8_C( 84), UINT8_C( 52), UINT8_C( 67) },
      { UINT8_C(225), UINT8_C(146), UINT8_C(184), UINT8_C( 43), UINT8_C( 47), UINT8_C(131), UINT8_C(225), UINT8_C( 73) } },
    { { UINT8_C(118), UINT8_C( 50), UINT8_C(  6), UINT8_C(155), UINT8_C( 55), UINT8_C(188), UINT8_C(150), UINT8_C(120) },
      { UINT8_C(245), UINT8_C(153), UINT8_C(131), UINT8_C(116), UINT8_C(229), UINT8_C( 41), UINT8_C(230), UINT8_C(198) },
      { UINT8_C(118), UINT8_C(245), UINT8_C( 50), UINT8_C(153), UINT8_C(  6), UINT8_C(131), UINT8_C(155), UINT8_C(116) } },
    { { UINT8_C(225), UINT8_C( 21), UINT8_C(168), UINT8_C(122), UINT8_C(168), UINT8_C(143), UINT8_C( 12), UINT8_C( 58) },
      { UINT8_C(186), UINT8_C(143), UINT8_C(131), UINT8_C(238), UINT8_C(227), UINT8_C(184), UINT8_C( 49), UINT8_C( 89) },
      { UINT8_C(225), UINT8_C(186), UINT8_C( 21), UINT8_C(143), UINT8_C(168), UINT8_C(131), UINT8_C(122), UINT8_C(238) } },
    { { UINT8_C(234), UINT8_C( 55), UINT8_C(245), UINT8_C( 33), UINT8_C(243), UINT8_C(139), UINT8_C(153), UINT8_C(233) },
      { UINT8_C( 36), UINT8_C( 29), UINT8_C( 93), UINT8_C(  9), UINT8_C( 70), UINT8_C( 67), UINT8_C(207), UINT8_C( 39) },
      { UINT8_C(234), UINT8_C( 36), UINT8_C( 55), UINT8_C( 29), UINT8_C(245), UINT8_C( 93), UINT8_C( 33), UINT8_C(  9) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vzip1_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(54503), UINT16_C(20876), UINT16_C(27990), UINT16_C( 1388) },
      { UINT16_C( 5134), UINT16_C(61930), UINT16_C(11315), UINT16_C(24246) },
      { UINT16_C(54503), UINT16_C( 5134), UINT16_C(20876), UINT16_C(61930) } },
    { { UINT16_C(54834), UINT16_C(28009), UINT16_C( 5311), UINT16_C(11808) },
      { UINT16_C(44084), UINT16_C(65289), UINT16_C(  886), UINT16_C(24131) },
      { UINT16_C(54834), UINT16_C(44084), UINT16_C(28009), UINT16_C(65289) } },
    { { UINT16_C(53207), UINT16_C(11951), UINT16_C( 6972), UINT16_C(18995) },
      { UINT16_C( 7471), UINT16_C(25147), UINT16_C(61770), UINT16_C(31937) },
      { UINT16_C(53207), UINT16_C( 7471), UINT16_C(11951), UINT16_C(25147) } },
    { { UINT16_C(10951), UINT16_C(34537), UINT16_C( 2622), UINT16_C(29364) },
      { UINT16_C(48822), UINT16_C(11377), UINT16_C(46273), UINT16_C(39050) },
      { UINT16_C(10951), UINT16_C(48822), UINT16_C(34537), UINT16_C(11377) } },
    { { UINT16_C(14723), UINT16_C(49094), UINT16_C(63828), UINT16_C(33545) },
      { UINT16_C(17431), UINT16_C(25062), UINT16_C(42805), UINT16_C(64989) },
      { UINT16_C(14723), UINT16_C(17431), UINT16_C(49094), UINT16_C(25062) } },
    { { UINT16_C(51153), UINT16_C( 3971), UINT16_C(14545), UINT16_C(34689) },
      { UINT16_C(62198), UINT16_C(47027), UINT16_C(16039), UINT16_C(10831) },
      { UINT16_C(51153), UINT16_C(62198), UINT16_C( 3971), UINT16_C(47027) } },
    { { UINT16_C( 5751), UINT16_C(52458), UINT16_C(62223), UINT16_C( 9807) },
      { UINT16_C(13624), UINT16_C(28039), UINT16_C(26076), UINT16_C(44394) },
      { UINT16_C( 5751), UINT16_C(13624), UINT16_C(52458), UINT16_C(28039) } },
    { { UINT16_C(60972), UINT16_C(64956), UINT16_C(15654), UINT16_C( 7300) },
      { UINT16_C(14128), UINT16_C(55251), UINT16_C( 8821), UINT16_C(60673) },
      { UINT16_C(60972), UINT16_C(14128), UINT16_C(64956), UINT16_C(55251) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vzip1_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 509442038), UINT32_C(1705505599) },
      { UINT32_C(1361533953), UINT32_C(2713165570) },
      { UINT32_C( 509442038), UINT32_C(1361533953) } },
    { { UINT32_C(1841080646), UINT32_C(1488848664) },
      { UINT32_C(1673216874), UINT32_C(1840895607) },
      { UINT32_C(1841080646), UINT32_C(1673216874) } },
    { { UINT32_C(2357990989), UINT32_C( 183644937) },
      { UINT32_C(2455443855), UINT32_C(4281537464) },
      { UINT32_C(2357990989), UINT32_C(2455443855) } },
    { { UINT32_C(3563909052), UINT32_C(1630350070) },
      { UINT32_C(3854887021), UINT32_C( 206732735) },
      { UINT32_C(3563909052), UINT32_C(3854887021) } },
    { { UINT32_C(2627329683), UINT32_C(2712046353) },
      { UINT32_C(1563624100), UINT32_C(3512493589) },
      { UINT32_C(2627329683), UINT32_C(1563624100) } },
    { { UINT32_C(1269221461), UINT32_C(1621939186) },
      { UINT32_C(2051371195), UINT32_C(2156369901) },
      { UINT32_C(1269221461), UINT32_C(2051371195) } },
    { { UINT32_C(2266767478), UINT32_C(1328071595) },
      { UINT32_C(3668728773), UINT32_C( 380307649) },
      { UINT32_C(2266767478), UINT32_C(3668728773) } },
    { { UINT32_C(3278000592), UINT32_C(3760393764) },
      { UINT32_C(1817864319), UINT32_C(1978524159) },
      { UINT32_C(3278000592), UINT32_C(1817864319) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vzip1_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1q_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   269.04), SIMDE_FLOAT32_C(   671.35), SIMDE_FLOAT32_C(   766.94), SIMDE_FLOAT32_C(  -408.87) },
      { SIMDE_FLOAT32_C(  -755.43), SIMDE_FLOAT32_C(  -620.83), SIMDE_FLOAT32_C(  -105.18), SIMDE_FLOAT32_C(   580.87) },
      { SIMDE_FLOAT32_C(   269.04), SIMDE_FLOAT32_C(  -755.43), SIMDE_FLOAT32_C(   671.35), SIMDE_FLOAT32_C(  -620.83) } },
    { { SIMDE_FLOAT32_C(    -7.35), SIMDE_FLOAT32_C(  -641.39), SIMDE_FLOAT32_C(  -306.86), SIMDE_FLOAT32_C(  -476.86) },
      { SIMDE_FLOAT32_C(   983.02), SIMDE_FLOAT32_C(   145.77), SIMDE_FLOAT32_C(  -393.28), SIMDE_FLOAT32_C(  -514.11) },
      { SIMDE_FLOAT32_C(    -7.35), SIMDE_FLOAT32_C(   983.02), SIMDE_FLOAT32_C(  -641.39), SIMDE_FLOAT32_C(   145.77) } },
    { { SIMDE_FLOAT32_C(   201.77), SIMDE_FLOAT32_C(   778.35), SIMDE_FLOAT32_C(   479.04), SIMDE_FLOAT32_C(  -404.39) },
      { SIMDE_FLOAT32_C(   748.07), SIMDE_FLOAT32_C(  -591.33), SIMDE_FLOAT32_C(   845.51), SIMDE_FLOAT32_C(  -130.39) },
      { SIMDE_FLOAT32_C(   201.77), SIMDE_FLOAT32_C(   748.07), SIMDE_FLOAT32_C(   778.35), SIMDE_FLOAT32_C(  -591.33) } },
    { { SIMDE_FLOAT32_C(   187.46), SIMDE_FLOAT32_C(   563.12), SIMDE_FLOAT32_C(  -567.04), SIMDE_FLOAT32_C(    46.32) },
      { SIMDE_FLOAT32_C(   549.79), SIMDE_FLOAT32_C(  -703.64), SIMDE_FLOAT32_C(   919.82), SIMDE_FLOAT32_C(  -181.17) },
      { SIMDE_FLOAT32_C(   187.46), SIMDE_FLOAT32_C(   549.79), SIMDE_FLOAT32_C(   563.12), SIMDE_FLOAT32_C(  -703.64) } },
    { { SIMDE_FLOAT32_C(   967.71), SIMDE_FLOAT32_C(   686.76), SIMDE_FLOAT32_C(   409.96), SIMDE_FLOAT32_C(  -787.73) },
      { SIMDE_FLOAT32_C(  -934.07), SIMDE_FLOAT32_C(  -695.22), SIMDE_FLOAT32_C(   793.14), SIMDE_FLOAT32_C(    58.59) },
      { SIMDE_FLOAT32_C(   967.71), SIMDE_FLOAT32_C(  -934.07), SIMDE_FLOAT32_C(   686.76), SIMDE_FLOAT32_C(  -695.22) } },
    { { SIMDE_FLOAT32_C(  -336.61), SIMDE_FLOAT32_C(  -513.72), SIMDE_FLOAT32_C(   581.73), SIMDE_FLOAT32_C(  -353.60) },
      { SIMDE_FLOAT32_C(   632.05), SIMDE_FLOAT32_C(  -811.55), SIMDE_FLOAT32_C(   132.29), SIMDE_FLOAT32_C(  -166.18) },
      { SIMDE_FLOAT32_C(  -336.61), SIMDE_FLOAT32_C(   632.05), SIMDE_FLOAT32_C(  -513.72), SIMDE_FLOAT32_C(  -811.55) } },
    { { SIMDE_FLOAT32_C(   966.80), SIMDE_FLOAT32_C(  -388.67), SIMDE_FLOAT32_C(   429.43), SIMDE_FLOAT32_C(   714.87) },
      { SIMDE_FLOAT32_C(    20.00), SIMDE_FLOAT32_C(   274.94), SIMDE_FLOAT32_C(  -415.52), SIMDE_FLOAT32_C(  -792.53) },
      { SIMDE_FLOAT32_C(   966.80), SIMDE_FLOAT32_C(    20.00), SIMDE_FLOAT32_C(  -388.67), SIMDE_FLOAT32_C(   274.94) } },
    { { SIMDE_FLOAT32_C(  -161.95), SIMDE_FLOAT32_C(    17.44), SIMDE_FLOAT32_C(   253.79), SIMDE_FLOAT32_C(  -612.15) },
      { SIMDE_FLOAT32_C(   313.79), SIMDE_FLOAT32_C(   173.61), SIMDE_FLOAT32_C(   206.68), SIMDE_FLOAT32_C(   281.50) },
      { SIMDE_FLOAT32_C(  -161.95), SIMDE_FLOAT32_C(   313.79), SIMDE_FLOAT32_C(    17.44), SIMDE_FLOAT32_C(   173.61) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vzip1q_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vzip1q_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  70), -INT8_C(  22), -INT8_C(  88),  INT8_C(  42), -INT8_C(   9), -INT8_C(   4), -INT8_C( 126),  INT8_C(  11),
        -INT8_C(  37), -INT8_C( 127),  INT8_C(   7), -INT8_C( 109),  INT8_C( 119), -INT8_C(  90), -INT8_C(  99),  INT8_C(   0) },
      { -INT8_C(  41),  INT8_C(  47),  INT8_C(  38),  INT8_C(   5),  INT8_C( 103), -INT8_C(  61), -INT8_C(  45), -INT8_C(  22),
         INT8_C(  43), -INT8_C(  92),  INT8_C(  19),  INT8_C( 114),  INT8_C( 110), -INT8_C(  85),  INT8_C(  62),  INT8_C(  41) },
      { -INT8_C(  70), -INT8_C(  41), -INT8_C(  22),  INT8_C(  47), -INT8_C(  88),  INT8_C(  38),  INT8_C(  42),  INT8_C(   5),
        -INT8_C(   9),  INT8_C( 103), -INT8_C(   4), -INT8_C(  61), -INT8_C( 126), -INT8_C(  45),  INT8_C(  11), -INT8_C(  22) } },
    { { -INT8_C( 107), -INT8_C(  26),  INT8_C(  83), -INT8_C( 116), -INT8_C(  30), -INT8_C(  43), -INT8_C( 104), -INT8_C(  66),
         INT8_C(  87), -INT8_C(  97),  INT8_C(  81), -INT8_C(  50),  INT8_C(  69), -INT8_C(  18), -INT8_C(  50),  INT8_C(  28) },
      {  INT8_C(  30), -INT8_C(  11),  INT8_C(  34), -INT8_C( 123), -INT8_C(  72), -INT8_C(  11),  INT8_C( 111), -INT8_C(  29),
        -INT8_C( 103), -INT8_C( 125),  INT8_C(  85),  INT8_C(   7),  INT8_C(  46), -INT8_C( 108),  INT8_C(  48), -INT8_C(  61) },
      { -INT8_C( 107),  INT8_C(  30), -INT8_C(  26), -INT8_C(  11),  INT8_C(  83),  INT8_C(  34), -INT8_C( 116), -INT8_C( 123),
        -INT8_C(  30), -INT8_C(  72), -INT8_C(  43), -INT8_C(  11), -INT8_C( 104),  INT8_C( 111), -INT8_C(  66), -INT8_C(  29) } },
    { {  INT8_C( 122), -INT8_C( 124),  INT8_C(  79),  INT8_C(  93),  INT8_C(  89), -INT8_C(  25),  INT8_C(  27), -INT8_C(  80),
        -INT8_C( 122),  INT8_C( 108),  INT8_C( 126), -INT8_C(  53),  INT8_C(  90),  INT8_C(  77), -INT8_C(  24),  INT8_C( 120) },
      {  INT8_C(  66),  INT8_C(  10), -INT8_C(   2), -INT8_C(   6), -INT8_C(   1),  INT8_C( 109), -INT8_C(  35), -INT8_C( 104),
        -INT8_C(  16),  INT8_C(  51), -INT8_C(  97),  INT8_C(  30), -INT8_C(  57), -INT8_C(  48), -INT8_C(  31),  INT8_C(  65) },
      {  INT8_C( 122),  INT8_C(  66), -INT8_C( 124),  INT8_C(  10),  INT8_C(  79), -INT8_C(   2),  INT8_C(  93), -INT8_C(   6),
         INT8_C(  89), -INT8_C(   1), -INT8_C(  25),  INT8_C( 109),  INT8_C(  27), -INT8_C(  35), -INT8_C(  80), -INT8_C( 104) } },
    { {  INT8_C(  84),  INT8_C(  49), -INT8_C(  98), -INT8_C(  83),  INT8_C(  24), -INT8_C(  71),  INT8_C(  94), -INT8_C(  97),
         INT8_C(  37), -INT8_C(  36),  INT8_C( 106),      INT8_MIN,  INT8_C(  41),  INT8_C(  82), -INT8_C(   8),  INT8_C( 107) },
      {  INT8_C(  92), -INT8_C(  10),  INT8_C( 101),  INT8_C(  91),  INT8_C( 100),  INT8_C(  67), -INT8_C(  13),  INT8_C(  84),
         INT8_C( 118), -INT8_C( 109),  INT8_C( 115),  INT8_C(  61),  INT8_C(  99),  INT8_C(  84),  INT8_C( 126), -INT8_C(  73) },
      {  INT8_C(  84),  INT8_C(  92),  INT8_C(  49), -INT8_C(  10), -INT8_C(  98),  INT8_C( 101), -INT8_C(  83),  INT8_C(  91),
         INT8_C(  24),  INT8_C( 100), -INT8_C(  71),  INT8_C(  67),  INT8_C(  94), -INT8_C(  13), -INT8_C(  97),  INT8_C(  84) } },
    { { -INT8_C( 123),  INT8_C(  29),  INT8_C( 100), -INT8_C(  98), -INT8_C(  42), -INT8_C(  62),  INT8_C(  61), -INT8_C(   4),
        -INT8_C(  97), -INT8_C(  89),  INT8_C( 124), -INT8_C(  56), -INT8_C(   6),  INT8_C( 116),  INT8_C(  52),  INT8_C(  86) },
      {  INT8_C( 107), -INT8_C( 103), -INT8_C(  78), -INT8_C(  49), -INT8_C(  36), -INT8_C(  91),  INT8_C(  35),  INT8_C(  82),
         INT8_C(  56), -INT8_C( 106), -INT8_C( 113), -INT8_C( 101), -INT8_C(  21),  INT8_C(  14),  INT8_C(  82),  INT8_C( 112) },
      { -INT8_C( 123),  INT8_C( 107),  INT8_C(  29), -INT8_C( 103),  INT8_C( 100), -INT8_C(  78), -INT8_C(  98), -INT8_C(  49),
        -INT8_C(  42), -INT8_C(  36), -INT8_C(  62), -INT8_C(  91),  INT8_C(  61),  INT8_C(  35), -INT8_C(   4),  INT8_C(  82) } },
    { {  INT8_C(  43), -INT8_C(  73),  INT8_C(  14),  INT8_C(   1),  INT8_C( 121),  INT8_C(  75), -INT8_C(   3),  INT8_C(  24),
        -INT8_C(  13),  INT8_C( 121), -INT8_C(  31), -INT8_C(  19), -INT8_C(  18),  INT8_C(  21),  INT8_C(  67),  INT8_C(  89) },
      { -INT8_C(  82), -INT8_C(  11),  INT8_C(  40), -INT8_C( 117), -INT8_C( 101),  INT8_C(  75), -INT8_C(  35), -INT8_C(  45),
        -INT8_C(  30),  INT8_C( 109),  INT8_C( 111), -INT8_C(  51),  INT8_C( 123), -INT8_C(  63),  INT8_C(  61), -INT8_C(  90) },
      {  INT8_C(  43), -INT8_C(  82), -INT8_C(  73), -INT8_C(  11),  INT8_C(  14),  INT8_C(  40),  INT8_C(   1), -INT8_C( 117),
         INT8_C( 121), -INT8_C( 101),  INT8_C(  75),  INT8_C(  75), -INT8_C(   3), -INT8_C(  35),  INT8_C(  24), -INT8_C(  45) } },
    { {  INT8_C( 120),  INT8_C(  76), -INT8_C(  89), -INT8_C(  14), -INT8_C( 105), -INT8_C(  91),  INT8_C(  10), -INT8_C( 118),
         INT8_C(  30), -INT8_C(  21),  INT8_C( 119),  INT8_C(  12),  INT8_C(   0), -INT8_C(  69),  INT8_C( 101), -INT8_C(  81) },
      { -INT8_C(  80), -INT8_C( 115),  INT8_C(  58),  INT8_C(  75), -INT8_C(  39),  INT8_C(  23),  INT8_C(  31), -INT8_C(  69),
        -INT8_C( 124), -INT8_C( 114), -INT8_C( 120), -INT8_C(   1),  INT8_C(  79), -INT8_C(  59), -INT8_C(  91), -INT8_C(  56) },
      {  INT8_C( 120), -INT8_C(  80),  INT8_C(  76), -INT8_C( 115), -INT8_C(  89),  INT8_C(  58), -INT8_C(  14),  INT8_C(  75),
        -INT8_C( 105), -INT8_C(  39), -INT8_C(  91),  INT8_C(  23),  INT8_C(  10),  INT8_C(  31), -INT8_C( 118), -INT8_C(  69) } },
    { {  INT8_C(  17),  INT8_C(  77), -INT8_C(  70), -INT8_C(  87), -INT8_C(  14), -INT8_C(  60),  INT8_C(  51),  INT8_C(  16),
        -INT8_C(  80), -INT8_C(  85),  INT8_C(  29), -INT8_C(  80),  INT8_C( 102), -INT8_C( 126),  INT8_C(  95),  INT8_C(  22) },
      {  INT8_C(  16), -INT8_C( 103),  INT8_C(  98), -INT8_C(  23), -INT8_C(  79), -INT8_C( 127), -INT8_C(  92),  INT8_C(  53),
         INT8_C(  15),  INT8_C(  44),  INT8_C(  53),  INT8_C(  94), -INT8_C(  15), -INT8_C(  38),  INT8_C(  38),  INT8_C(   3) },
      {  INT8_C(  17),  INT8_C(  16),  INT8_C(  77), -INT8_C( 103), -INT8_C(  70),  INT8_C(  98), -INT8_C(  87), -INT8_C(  23),
        -INT8_C(  14), -INT8_C(  79), -INT8_C(  60), -INT8_C( 127),  INT8_C(  51), -INT8_C(  92),  INT8_C(  16),  INT8_C(  53) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vzip1q_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1q_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 28283), -INT16_C(  8974), -INT16_C( 22113),  INT16_C( 11484), -INT16_C( 30181), -INT16_C( 20779), -INT16_C( 25603),  INT16_C( 17370) },
      {  INT16_C( 31538), -INT16_C( 31974),  INT16_C(  9962), -INT16_C( 13557),  INT16_C(  1664),  INT16_C( 31891), -INT16_C(  5649),  INT16_C( 27379) },
      {  INT16_C( 28283),  INT16_C( 31538), -INT16_C(  8974), -INT16_C( 31974), -INT16_C( 22113),  INT16_C(  9962),  INT16_C( 11484), -INT16_C( 13557) } },
    { { -INT16_C(  6568), -INT16_C(  2234),  INT16_C(  8847), -INT16_C( 21981), -INT16_C(  1620), -INT16_C( 21927),  INT16_C( 13204), -INT16_C( 14611) },
      {  INT16_C(  1966), -INT16_C( 26551),  INT16_C( 21806), -INT16_C( 20893), -INT16_C(  2213),  INT16_C( 18986),  INT16_C(  7904),  INT16_C( 14516) },
      { -INT16_C(  6568),  INT16_C(  1966), -INT16_C(  2234), -INT16_C( 26551),  INT16_C(  8847),  INT16_C( 21806), -INT16_C( 21981), -INT16_C( 20893) } },
    { { -INT16_C(  1276), -INT16_C( 27857),  INT16_C( 21277), -INT16_C( 13762), -INT16_C( 26804), -INT16_C(  8076),  INT16_C( 25034),  INT16_C( 30886) },
      { -INT16_C(  3992), -INT16_C( 27119),  INT16_C( 29765), -INT16_C( 24507),  INT16_C( 28523),  INT16_C( 19690), -INT16_C( 24947), -INT16_C( 28284) },
      { -INT16_C(  1276), -INT16_C(  3992), -INT16_C( 27857), -INT16_C( 27119),  INT16_C( 21277),  INT16_C( 29765), -INT16_C( 13762), -INT16_C( 24507) } },
    { { -INT16_C( 19303), -INT16_C( 18651),  INT16_C( 25351),  INT16_C( 21377), -INT16_C(  2566), -INT16_C( 15309), -INT16_C(  9898), -INT16_C( 16836) },
      {  INT16_C( 19913),  INT16_C(  3669), -INT16_C( 25918),  INT16_C( 11694), -INT16_C( 26615), -INT16_C( 26759), -INT16_C(   457), -INT16_C( 12248) },
      { -INT16_C( 19303),  INT16_C( 19913), -INT16_C( 18651),  INT16_C(  3669),  INT16_C( 25351), -INT16_C( 25918),  INT16_C( 21377),  INT16_C( 11694) } },
    { {  INT16_C( 19890), -INT16_C( 18041),  INT16_C(  2224), -INT16_C( 22004),  INT16_C( 16381),  INT16_C( 21358), -INT16_C( 21736), -INT16_C(  7662) },
      {  INT16_C( 26616), -INT16_C( 17680), -INT16_C( 24831),  INT16_C(  2792),  INT16_C( 24887),  INT16_C( 28321), -INT16_C( 13729),  INT16_C(  4415) },
      {  INT16_C( 19890),  INT16_C( 26616), -INT16_C( 18041), -INT16_C( 17680),  INT16_C(  2224), -INT16_C( 24831), -INT16_C( 22004),  INT16_C(  2792) } },
    { { -INT16_C( 14825), -INT16_C( 14134), -INT16_C( 10545), -INT16_C( 13198), -INT16_C(  7915),  INT16_C( 11808),  INT16_C( 12940), -INT16_C( 31728) },
      {  INT16_C(   153), -INT16_C( 26049),  INT16_C( 10143), -INT16_C( 10332),  INT16_C( 18056), -INT16_C(  6075), -INT16_C( 31728),  INT16_C( 10233) },
      { -INT16_C( 14825),  INT16_C(   153), -INT16_C( 14134), -INT16_C( 26049), -INT16_C( 10545),  INT16_C( 10143), -INT16_C( 13198), -INT16_C( 10332) } },
    { { -INT16_C( 15285),  INT16_C(  6895),  INT16_C( 25242), -INT16_C( 20250),  INT16_C(  1603), -INT16_C( 12322), -INT16_C(  4552), -INT16_C( 11949) },
      { -INT16_C( 27922), -INT16_C( 29077),  INT16_C(  4281),  INT16_C( 16997), -INT16_C( 21930),  INT16_C( 26154),  INT16_C(  9007),  INT16_C( 31373) },
      { -INT16_C( 15285), -INT16_C( 27922),  INT16_C(  6895), -INT16_C( 29077),  INT16_C( 25242),  INT16_C(  4281), -INT16_C( 20250),  INT16_C( 16997) } },
    { {  INT16_C( 32231), -INT16_C( 32108),  INT16_C( 31455),  INT16_C(  8754),  INT16_C(  4225), -INT16_C( 17935),  INT16_C( 17662), -INT16_C(  4981) },
      { -INT16_C(  2345), -INT16_C( 28550), -INT16_C(  8442),  INT16_C( 23762), -INT16_C(   886), -INT16_C( 17982),  INT16_C( 20512),  INT16_C(  1843) },
      {  INT16_C( 32231), -INT16_C(  2345), -INT16_C( 32108), -INT16_C( 28550),  INT16_C( 31455), -INT16_C(  8442),  INT16_C(  8754),  INT16_C( 23762) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vzip1q_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1q_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1675320975), -INT32_C(  1896477137),  INT32_C(  1084998411), -INT32_C(  1861441150) },
      { -INT32_C(    22335743), -INT32_C(  1566060132),  INT32_C(   509923909),  INT32_C(    28916624) },
      { -INT32_C(  1675320975), -INT32_C(    22335743), -INT32_C(  1896477137), -INT32_C(  1566060132) } },
    { {  INT32_C(   211672541), -INT32_C(   157641493), -INT32_C(   650689193), -INT32_C(   261471250) },
      {  INT32_C(   267261299),  INT32_C(   733058534), -INT32_C(   146205337),  INT32_C(   788005457) },
      {  INT32_C(   211672541),  INT32_C(   267261299), -INT32_C(   157641493),  INT32_C(   733058534) } },
    { { -INT32_C(   902130209), -INT32_C(  2134780631),  INT32_C(   156956698), -INT32_C(  1359363013) },
      { -INT32_C(  1061230630), -INT32_C(   471044228), -INT32_C(   690342523),  INT32_C(   386191928) },
      { -INT32_C(   902130209), -INT32_C(  1061230630), -INT32_C(  2134780631), -INT32_C(   471044228) } },
    { { -INT32_C(  1847443865),  INT32_C(   772907795), -INT32_C(   701011045),  INT32_C(   176500784) },
      { -INT32_C(  1815461097),  INT32_C(   930526898),  INT32_C(   604852460), -INT32_C(  1992617694) },
      { -INT32_C(  1847443865), -INT32_C(  1815461097),  INT32_C(   772907795),  INT32_C(   930526898) } },
    { {  INT32_C(  1662655824),  INT32_C(  1536240832), -INT32_C(   952973161),  INT32_C(   265402360) },
      { -INT32_C(  1398629126),  INT32_C(  1055135826), -INT32_C(  1973227160),  INT32_C(  1393860099) },
      {  INT32_C(  1662655824), -INT32_C(  1398629126),  INT32_C(  1536240832),  INT32_C(  1055135826) } },
    { {  INT32_C(  2092314299), -INT32_C(   220772262),  INT32_C(   163121424), -INT32_C(  1172796480) },
      {  INT32_C(  2036841255),  INT32_C(  1018710995),  INT32_C(  1069947452),  INT32_C(  1955781304) },
      {  INT32_C(  2092314299),  INT32_C(  2036841255), -INT32_C(   220772262),  INT32_C(  1018710995) } },
    { {  INT32_C(  1676691721), -INT32_C(  1588213871), -INT32_C(  1851125807), -INT32_C(  1051933798) },
      {  INT32_C(  1362801534),  INT32_C(   982381310), -INT32_C(   981838835),  INT32_C(   926485550) },
      {  INT32_C(  1676691721),  INT32_C(  1362801534), -INT32_C(  1588213871),  INT32_C(   982381310) } },
    { { -INT32_C(   426038955), -INT32_C(  1031212815), -INT32_C(  1722600705),  INT32_C(  1935319029) },
      {  INT32_C(  1355126098), -INT32_C(  1802808697), -INT32_C(   715520602),  INT32_C(  1728877329) },
      { -INT32_C(   426038955),  INT32_C(  1355126098), -INT32_C(  1031212815), -INT32_C(  1802808697) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vzip1q_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1q_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(  448570424052926050), -INT64_C( 8985443691791153961) },
      { -INT64_C( 8040865633061995433), -INT64_C( 4704410991765481408) },
      { -INT64_C(  448570424052926050), -INT64_C( 8040865633061995433) } },
    { {  INT64_C( 9032521722090244812),  INT64_C( 9119651969885461627) },
      { -INT64_C( 7142984589955546880), -INT64_C( 6918627632000909283) },
      {  INT64_C( 9032521722090244812), -INT64_C( 7142984589955546880) } },
    { { -INT64_C( 7096168734649275294),  INT64_C( 4600489963625823284) },
      { -INT64_C( 7461780158734764678),  INT64_C( 5701787941971809454) },
      { -INT64_C( 7096168734649275294), -INT64_C( 7461780158734764678) } },
    { { -INT64_C( 6071453218912133123),  INT64_C( 1952555225160509337) },
      { -INT64_C( 4438750342192912813),  INT64_C(  753337045300230969) },
      { -INT64_C( 6071453218912133123), -INT64_C( 4438750342192912813) } },
    { {  INT64_C( 4802781869398215811), -INT64_C( 2446524920958899121) },
      { -INT64_C( 7228257185826013479), -INT64_C( 2637643357437693106) },
      {  INT64_C( 4802781869398215811), -INT64_C( 7228257185826013479) } },
    { { -INT64_C( 4040717907954069503),  INT64_C( 1338347791406597929) },
      { -INT64_C( 6935349563607728190), -INT64_C( 5127804786686918237) },
      { -INT64_C( 4040717907954069503), -INT64_C( 6935349563607728190) } },
    { {  INT64_C( 5849981475946147056),  INT64_C( 7900044558967629654) },
      { -INT64_C(  736248026253581609),  INT64_C( 1315550417814340307) },
      {  INT64_C( 5849981475946147056), -INT64_C(  736248026253581609) } },
    { {  INT64_C( 5326820422534734962),  INT64_C( 7037572101881524881) },
      {  INT64_C( 7017823791531768860), -INT64_C( 8266027145664703468) },
      {  INT64_C( 5326820422534734962),  INT64_C( 7017823791531768860) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vzip1q_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1q_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(100), UINT8_C(203), UINT8_C(215), UINT8_C(200), UINT8_C(136), UINT8_C(145), UINT8_C(227), UINT8_C(166),
        UINT8_C( 22), UINT8_C(195), UINT8_C(118), UINT8_C(159), UINT8_C(105), UINT8_C(241), UINT8_C(107), UINT8_C(158) },
      { UINT8_C( 53), UINT8_C( 73), UINT8_C(155), UINT8_C(249), UINT8_C(100), UINT8_C( 88), UINT8_C(190), UINT8_C( 51),
        UINT8_C( 43), UINT8_C(242), UINT8_C(209), UINT8_C(  1), UINT8_C(234), UINT8_C(166), UINT8_C( 44), UINT8_C( 78) },
      { UINT8_C(100), UINT8_C( 53), UINT8_C(203), UINT8_C( 73), UINT8_C(215), UINT8_C(155), UINT8_C(200), UINT8_C(249),
        UINT8_C(136), UINT8_C(100), UINT8_C(145), UINT8_C( 88), UINT8_C(227), UINT8_C(190), UINT8_C(166), UINT8_C( 51) } },
    { { UINT8_C(113), UINT8_C(  4), UINT8_C( 22), UINT8_C(250), UINT8_C(149), UINT8_C(249), UINT8_C(160), UINT8_C(171),
        UINT8_C(188), UINT8_C( 22), UINT8_C( 75), UINT8_C( 38), UINT8_C(  7), UINT8_C(182), UINT8_C(196), UINT8_C( 60) },
      {    UINT8_MAX, UINT8_C( 95), UINT8_C( 54), UINT8_C( 99), UINT8_C(184), UINT8_C(244), UINT8_C(151), UINT8_C(227),
        UINT8_C(230), UINT8_C(104), UINT8_C(229), UINT8_C(208), UINT8_C( 14), UINT8_C( 17), UINT8_C( 30), UINT8_C(128) },
      { UINT8_C(113),    UINT8_MAX, UINT8_C(  4), UINT8_C( 95), UINT8_C( 22), UINT8_C( 54), UINT8_C(250), UINT8_C( 99),
        UINT8_C(149), UINT8_C(184), UINT8_C(249), UINT8_C(244), UINT8_C(160), UINT8_C(151), UINT8_C(171), UINT8_C(227) } },
    { { UINT8_C( 21), UINT8_C( 53), UINT8_C(122), UINT8_C(171), UINT8_C( 46), UINT8_C( 26), UINT8_C( 86), UINT8_C(235),
        UINT8_C( 48), UINT8_C(161), UINT8_C( 17), UINT8_C( 56), UINT8_C( 87), UINT8_C(213), UINT8_C(116), UINT8_C( 86) },
      { UINT8_C( 53), UINT8_C(170), UINT8_C(186), UINT8_C(237), UINT8_C(158), UINT8_C( 81), UINT8_C(208), UINT8_C(132),
        UINT8_C(185), UINT8_C(181), UINT8_C( 84), UINT8_C(199), UINT8_C(199), UINT8_C(115), UINT8_C( 71), UINT8_C(220) },
      { UINT8_C( 21), UINT8_C( 53), UINT8_C( 53), UINT8_C(170), UINT8_C(122), UINT8_C(186), UINT8_C(171), UINT8_C(237),
        UINT8_C( 46), UINT8_C(158), UINT8_C( 26), UINT8_C( 81), UINT8_C( 86), UINT8_C(208), UINT8_C(235), UINT8_C(132) } },
    { { UINT8_C(168), UINT8_C(193), UINT8_C(135), UINT8_C(214), UINT8_C(219), UINT8_C(222), UINT8_C(193), UINT8_C( 12),
        UINT8_C(127), UINT8_C(210), UINT8_C( 68), UINT8_C(215), UINT8_C(168), UINT8_C(184), UINT8_C( 45), UINT8_C(221) },
      { UINT8_C( 99), UINT8_C(231), UINT8_C(202), UINT8_C(  1), UINT8_C( 56), UINT8_C(154), UINT8_C(134), UINT8_C(241),
        UINT8_C( 80), UINT8_C(218), UINT8_C(185), UINT8_C( 23), UINT8_C( 77), UINT8_C(  0), UINT8_C(243), UINT8_C(245) },
      { UINT8_C(168), UINT8_C( 99), UINT8_C(193), UINT8_C(231), UINT8_C(135), UINT8_C(202), UINT8_C(214), UINT8_C(  1),
        UINT8_C(219), UINT8_C( 56), UINT8_C(222), UINT8_C(154), UINT8_C(193), UINT8_C(134), UINT8_C( 12), UINT8_C(241) } },
    { { UINT8_C(194), UINT8_C(123), UINT8_C(204), UINT8_C(157), UINT8_C( 89), UINT8_C(141), UINT8_C(169), UINT8_C(216),
        UINT8_C( 96), UINT8_C(237), UINT8_C(175), UINT8_C(  8), UINT8_C(166), UINT8_C(221), UINT8_C(229), UINT8_C(  9) },
      { UINT8_C(196), UINT8_C(175), UINT8_C( 10), UINT8_C(253), UINT8_C( 73), UINT8_C(144), UINT8_C(238), UINT8_C(153),
        UINT8_C(107), UINT8_C(167), UINT8_C(176), UINT8_C(184), UINT8_C(168), UINT8_C(164), UINT8_C(174), UINT8_C(106) },
      { UINT8_C(194), UINT8_C(196), UINT8_C(123), UINT8_C(175), UINT8_C(204), UINT8_C( 10), UINT8_C(157), UINT8_C(253),
        UINT8_C( 89), UINT8_C( 73), UINT8_C(141), UINT8_C(144), UINT8_C(169), UINT8_C(238), UINT8_C(216), UINT8_C(153) } },
    { { UINT8_C( 31), UINT8_C(122), UINT8_C(  7), UINT8_C(120), UINT8_C(  7), UINT8_C(177), UINT8_C( 80), UINT8_C(103),
        UINT8_C(158), UINT8_C(  0), UINT8_C(111), UINT8_C( 68), UINT8_C(221), UINT8_C( 84), UINT8_C( 77), UINT8_C(161) },
      { UINT8_C(  3), UINT8_C( 88), UINT8_C(158), UINT8_C( 77), UINT8_C(232), UINT8_C(141), UINT8_C(230), UINT8_C( 83),
        UINT8_C( 52), UINT8_C(151), UINT8_C( 12), UINT8_C(220), UINT8_C( 59), UINT8_C(186), UINT8_C( 70), UINT8_C( 90) },
      { UINT8_C( 31), UINT8_C(  3), UINT8_C(122), UINT8_C( 88), UINT8_C(  7), UINT8_C(158), UINT8_C(120), UINT8_C( 77),
        UINT8_C(  7), UINT8_C(232), UINT8_C(177), UINT8_C(141), UINT8_C( 80), UINT8_C(230), UINT8_C(103), UINT8_C( 83) } },
    { { UINT8_C( 52), UINT8_C( 78), UINT8_C(210), UINT8_C( 59),    UINT8_MAX, UINT8_C( 34), UINT8_C(163), UINT8_C(157),
        UINT8_C( 34), UINT8_C( 18), UINT8_C(226),    UINT8_MAX, UINT8_C(103), UINT8_C( 47), UINT8_C(161), UINT8_C(106) },
      { UINT8_C(135), UINT8_C( 63), UINT8_C(183), UINT8_C(112), UINT8_C(204), UINT8_C(158), UINT8_C(195), UINT8_C(  1),
        UINT8_C( 53), UINT8_C(207), UINT8_C(221), UINT8_C(112), UINT8_C(137), UINT8_C( 36), UINT8_C(202), UINT8_C(189) },
      { UINT8_C( 52), UINT8_C(135), UINT8_C( 78), UINT8_C( 63), UINT8_C(210), UINT8_C(183), UINT8_C( 59), UINT8_C(112),
           UINT8_MAX, UINT8_C(204), UINT8_C( 34), UINT8_C(158), UINT8_C(163), UINT8_C(195), UINT8_C(157), UINT8_C(  1) } },
    { { UINT8_C(114), UINT8_C(156), UINT8_C(249), UINT8_C(113), UINT8_C(190), UINT8_C(156), UINT8_C( 14), UINT8_C(225),
        UINT8_C(174), UINT8_C(240), UINT8_C(224), UINT8_C( 21), UINT8_C( 32), UINT8_C(129), UINT8_C(128), UINT8_C(167) },
      { UINT8_C(193), UINT8_C( 55), UINT8_C( 23), UINT8_C(141), UINT8_C(213), UINT8_C(219), UINT8_C(142), UINT8_C( 10),
        UINT8_C(170), UINT8_C(108), UINT8_C(122), UINT8_C( 52), UINT8_C(144), UINT8_C( 68), UINT8_C(241), UINT8_C(  2) },
      { UINT8_C(114), UINT8_C(193), UINT8_C(156), UINT8_C( 55), UINT8_C(249), UINT8_C( 23), UINT8_C(113), UINT8_C(141),
        UINT8_C(190), UINT8_C(213), UINT8_C(156), UINT8_C(219), UINT8_C( 14), UINT8_C(142), UINT8_C(225), UINT8_C( 10) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vzip1q_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1q_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(30177), UINT16_C(25079), UINT16_C(19204), UINT16_C( 1663), UINT16_C(38129), UINT16_C(42655), UINT16_C( 5776), UINT16_C( 1946) },
      { UINT16_C( 7669), UINT16_C(25887), UINT16_C(18190), UINT16_C(29117), UINT16_C(38689), UINT16_C(11637), UINT16_C(17900), UINT16_C(52555) },
      { UINT16_C(30177), UINT16_C( 7669), UINT16_C(25079), UINT16_C(25887), UINT16_C(19204), UINT16_C(18190), UINT16_C( 1663), UINT16_C(29117) } },
    { { UINT16_C(17082), UINT16_C(48686), UINT16_C(44686), UINT16_C(32709), UINT16_C(25666), UINT16_C(53797), UINT16_C(49275), UINT16_C(28889) },
      { UINT16_C(63709), UINT16_C(60374), UINT16_C(37696), UINT16_C(24924), UINT16_C(53802), UINT16_C( 6030), UINT16_C(55575), UINT16_C(53732) },
      { UINT16_C(17082), UINT16_C(63709), UINT16_C(48686), UINT16_C(60374), UINT16_C(44686), UINT16_C(37696), UINT16_C(32709), UINT16_C(24924) } },
    { { UINT16_C( 4892), UINT16_C(43663), UINT16_C(21697), UINT16_C(  809), UINT16_C(20409), UINT16_C(13526), UINT16_C(44815), UINT16_C(60580) },
      { UINT16_C(31400), UINT16_C(59607), UINT16_C(13325), UINT16_C(14409), UINT16_C(55302), UINT16_C( 7503), UINT16_C(13233), UINT16_C(52718) },
      { UINT16_C( 4892), UINT16_C(31400), UINT16_C(43663), UINT16_C(59607), UINT16_C(21697), UINT16_C(13325), UINT16_C(  809), UINT16_C(14409) } },
    { { UINT16_C(32070), UINT16_C( 1911), UINT16_C(41426), UINT16_C(35595), UINT16_C(57840), UINT16_C(65471), UINT16_C(25488), UINT16_C(14571) },
      { UINT16_C(49886), UINT16_C(60192), UINT16_C(27382), UINT16_C(64547), UINT16_C(29250), UINT16_C(62233), UINT16_C( 1958), UINT16_C(60609) },
      { UINT16_C(32070), UINT16_C(49886), UINT16_C( 1911), UINT16_C(60192), UINT16_C(41426), UINT16_C(27382), UINT16_C(35595), UINT16_C(64547) } },
    { { UINT16_C(14469), UINT16_C(22516), UINT16_C(65497), UINT16_C(51682), UINT16_C(41440), UINT16_C(28872), UINT16_C(45828), UINT16_C(58025) },
      { UINT16_C(51574), UINT16_C(27854), UINT16_C(61747), UINT16_C(30057), UINT16_C(33380), UINT16_C( 2665), UINT16_C(10890), UINT16_C( 4086) },
      { UINT16_C(14469), UINT16_C(51574), UINT16_C(22516), UINT16_C(27854), UINT16_C(65497), UINT16_C(61747), UINT16_C(51682), UINT16_C(30057) } },
    { { UINT16_C(60002), UINT16_C(15462), UINT16_C(18665), UINT16_C(51461), UINT16_C(52969), UINT16_C(60730), UINT16_C(58241), UINT16_C(63440) },
      { UINT16_C(40620), UINT16_C(57444), UINT16_C(52623), UINT16_C(62293), UINT16_C(48719), UINT16_C(55805), UINT16_C(62696), UINT16_C(19432) },
      { UINT16_C(60002), UINT16_C(40620), UINT16_C(15462), UINT16_C(57444), UINT16_C(18665), UINT16_C(52623), UINT16_C(51461), UINT16_C(62293) } },
    { { UINT16_C(20190), UINT16_C(51335), UINT16_C(35990), UINT16_C(32657), UINT16_C(52058), UINT16_C(56429), UINT16_C(15790), UINT16_C(23507) },
      { UINT16_C(14299), UINT16_C(27195), UINT16_C(36868), UINT16_C(21598), UINT16_C(23375), UINT16_C(14125), UINT16_C( 5711), UINT16_C(11906) },
      { UINT16_C(20190), UINT16_C(14299), UINT16_C(51335), UINT16_C(27195), UINT16_C(35990), UINT16_C(36868), UINT16_C(32657), UINT16_C(21598) } },
    { { UINT16_C( 2404), UINT16_C(64502), UINT16_C(34710), UINT16_C(61562), UINT16_C(59219), UINT16_C(  460), UINT16_C(40996), UINT16_C(65372) },
      { UINT16_C(38871), UINT16_C(56426), UINT16_C(51240), UINT16_C(30512), UINT16_C(23843), UINT16_C(29614), UINT16_C(12659), UINT16_C(55457) },
      { UINT16_C( 2404), UINT16_C(38871), UINT16_C(64502), UINT16_C(56426), UINT16_C(34710), UINT16_C(51240), UINT16_C(61562), UINT16_C(30512) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vzip1q_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1q_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2065304680), UINT32_C(   4706323), UINT32_C(  57610732), UINT32_C(1886136178) },
      { UINT32_C(1747746222), UINT32_C(2734993287), UINT32_C(2980376650), UINT32_C(4253478037) },
      { UINT32_C(2065304680), UINT32_C(1747746222), UINT32_C(   4706323), UINT32_C(2734993287) } },
    { { UINT32_C( 192454904), UINT32_C(1561116784), UINT32_C(1130396625), UINT32_C(1370737826) },
      { UINT32_C(3501842249), UINT32_C(3648306575), UINT32_C(1116412077), UINT32_C(4231991556) },
      { UINT32_C( 192454904), UINT32_C(3501842249), UINT32_C(1561116784), UINT32_C(3648306575) } },
    { { UINT32_C( 570996914), UINT32_C(1233065080), UINT32_C( 848158607), UINT32_C(4119019692) },
      { UINT32_C(2949004320), UINT32_C(2793945849), UINT32_C(1458049874), UINT32_C(3612485413) },
      { UINT32_C( 570996914), UINT32_C(2949004320), UINT32_C(1233065080), UINT32_C(2793945849) } },
    { { UINT32_C(1475959519), UINT32_C(4271995246), UINT32_C(  70266456), UINT32_C(2398794606) },
      { UINT32_C(3896361199), UINT32_C(1284425466), UINT32_C(4272060121), UINT32_C(2111173789) },
      { UINT32_C(1475959519), UINT32_C(3896361199), UINT32_C(4271995246), UINT32_C(1284425466) } },
    { { UINT32_C(3184840527), UINT32_C(2696639816), UINT32_C( 312863651), UINT32_C(2376114078) },
      { UINT32_C(1500896863), UINT32_C(2107966372), UINT32_C( 394020729), UINT32_C(2324975931) },
      { UINT32_C(3184840527), UINT32_C(1500896863), UINT32_C(2696639816), UINT32_C(2107966372) } },
    { { UINT32_C(1749575712), UINT32_C(2164851678), UINT32_C(2375266031), UINT32_C(2887464013) },
      { UINT32_C(3053817874), UINT32_C( 221489812), UINT32_C( 740601841), UINT32_C( 565688321) },
      { UINT32_C(1749575712), UINT32_C(3053817874), UINT32_C(2164851678), UINT32_C( 221489812) } },
    { { UINT32_C(4287299361), UINT32_C(4051735298), UINT32_C(2390692929), UINT32_C(1513790024) },
      { UINT32_C(3188735786), UINT32_C(3670819817), UINT32_C(4094095603), UINT32_C(3390422441) },
      { UINT32_C(4287299361), UINT32_C(3188735786), UINT32_C(4051735298), UINT32_C(3670819817) } },
    { { UINT32_C(3217661884), UINT32_C(1940932914), UINT32_C(2768318301), UINT32_C(4110367689) },
      { UINT32_C(1672613754), UINT32_C(1178435155), UINT32_C( 406471791), UINT32_C(3202502401) },
      { UINT32_C(3217661884), UINT32_C(1672613754), UINT32_C(1940932914), UINT32_C(1178435155) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vzip1q_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip1q_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 7183801971137112578), UINT64_C(16626255232757114459) },
      { UINT64_C( 8131359811310929053), UINT64_C(16147889417916265065) },
      { UINT64_C( 7183801971137112578), UINT64_C( 8131359811310929053) } },
    { { UINT64_C(15057051385318308029), UINT64_C( 6700214673640614922) },
      { UINT64_C(15803371279345651253), UINT64_C( 1282336582655705100) },
      { UINT64_C(15057051385318308029), UINT64_C(15803371279345651253) } },
    { { UINT64_C(17115254058352082495), UINT64_C(16221964400771381764) },
      { UINT64_C(  529755678047281420), UINT64_C( 1077977485933676945) },
      { UINT64_C(17115254058352082495), UINT64_C(  529755678047281420) } },
    { { UINT64_C( 3750451961221322812), UINT64_C( 1841996491325378050) },
      { UINT64_C(17526587403435266359), UINT64_C( 2871552645751319803) },
      { UINT64_C( 3750451961221322812), UINT64_C(17526587403435266359) } },
    { { UINT64_C(16702253309784136805), UINT64_C( 1190680762967769696) },
      { UINT64_C(  921966960516931190), UINT64_C(15400815873310041001) },
      { UINT64_C(16702253309784136805), UINT64_C(  921966960516931190) } },
    { { UINT64_C(12905124458874470477), UINT64_C( 5395495782249967352) },
      { UINT64_C( 5251459535740216260), UINT64_C(13102825539333044113) },
      { UINT64_C(12905124458874470477), UINT64_C( 5251459535740216260) } },
    { { UINT64_C( 8114641523400131223), UINT64_C( 2795083225679051949) },
      { UINT64_C( 7794846792540745028), UINT64_C( 3868666430013376659) },
      { UINT64_C( 8114641523400131223), UINT64_C( 7794846792540745028) } },
    { { UINT64_C( 4786688231835932293), UINT64_C( 1369531685565345400) },
      { UINT64_C( 7692467946781080698), UINT64_C(17869743954202013226) },
      { UINT64_C( 4786688231835932293), UINT64_C( 7692467946781080698) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vzip1q_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip1q_u64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
