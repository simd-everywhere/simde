#define SIMDE_TEST_ARM_NEON_INSN shl

#include "test-neon.h"
#include "../../../simde/arm/neon/shl.h"

static int
test_simde_vshl_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  50), -INT8_C(  52), -INT8_C(   3), -INT8_C(  40),  INT8_C(  58), -INT8_C(   5),  INT8_C(  35),  INT8_C(  63) },
      {  INT8_C(   4),  INT8_C(   6), -INT8_C(  40), -INT8_C(  26),  INT8_C(   8), -INT8_C(   8),  INT8_C(   1), -INT8_C(   6) },
      { -INT8_C(  32),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(  70),  INT8_C(   0) } },
    { {  INT8_C(  97),  INT8_C(  31),  INT8_C(  25),  INT8_C(  62), -INT8_C(  88),  INT8_C(  87), -INT8_C(  43),  INT8_C( 118) },
      {  INT8_C(  35), -INT8_C(   6),  INT8_C(  78),  INT8_C(   5), -INT8_C(  51),  INT8_C(   7), -INT8_C(   7), -INT8_C(   6) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64), -INT8_C(   1),      INT8_MIN, -INT8_C(   1),  INT8_C(   1) } },
    { {  INT8_C( 100), -INT8_C(  89), -INT8_C( 100),  INT8_C(  15), -INT8_C(  42), -INT8_C(  88),  INT8_C( 101),  INT8_C(  56) },
      { -INT8_C(   8),  INT8_C(   7),  INT8_C(   7),  INT8_C(   6), -INT8_C(   6),  INT8_C(   4), -INT8_C(   7), -INT8_C(   7) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0), -INT8_C(  64), -INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 104),  INT8_C( 126), -INT8_C( 112), -INT8_C(  51),  INT8_C(  61), -INT8_C( 110),  INT8_C( 116), -INT8_C(  95) },
      {  INT8_C(   7),  INT8_C(   8), -INT8_C(  80),  INT8_C(   7), -INT8_C(   5),  INT8_C(   5),  INT8_C(   8),  INT8_C(   7) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),      INT8_MIN,  INT8_C(   1),  INT8_C(  64),  INT8_C(   0),      INT8_MIN } },
    { {  INT8_C(   9), -INT8_C(  69),  INT8_C(  17), -INT8_C(  81), -INT8_C(  82), -INT8_C(  46),  INT8_C(  39),  INT8_C(  22) },
      {  INT8_C(  81), -INT8_C(   5), -INT8_C(   8), -INT8_C(   8),  INT8_C(  73),  INT8_C(   5),  INT8_C(  47), -INT8_C(   8) },
      {  INT8_C(   0), -INT8_C(   3),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 105), -INT8_C( 113), -INT8_C(  13), -INT8_C(  97),  INT8_C( 100),  INT8_C(  87), -INT8_C(  59),  INT8_C( 110) },
      {  INT8_C(   4), -INT8_C(   6),  INT8_C(   7), -INT8_C(   8), -INT8_C(   6),  INT8_C(   8), -INT8_C(  41), -INT8_C(   6) },
      {  INT8_C( 112), -INT8_C(   2),      INT8_MIN, -INT8_C(   1),  INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   1) } },
    { { -INT8_C( 106),  INT8_C(  90), -INT8_C( 100), -INT8_C( 118),  INT8_C(  52),  INT8_C(  61),  INT8_C(  19), -INT8_C(  53) },
      { -INT8_C(   7),  INT8_C(   7),  INT8_C(   6),  INT8_C(   6),  INT8_C(   5),  INT8_C(   6), -INT8_C(   7),  INT8_C(   7) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(  64),  INT8_C(   0),      INT8_MIN } },
    { { -INT8_C(  60),  INT8_C(  49),  INT8_C(  68), -INT8_C(  41), -INT8_C(  24),  INT8_C(  12),  INT8_C(  83),  INT8_C( 126) },
      {  INT8_C(   6), -INT8_C(   5),  INT8_C(   4), -INT8_C(   7),  INT8_C(  44),  INT8_C(   7),  INT8_C( 102), -INT8_C(   7) },
      {  INT8_C(   0),  INT8_C(   1),  INT8_C(  64), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vshl_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshl_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 22332), -INT16_C(  2389), -INT16_C(  6176),  INT16_C( 24298) },
      { -INT16_C(    11), -INT16_C(    12),  INT16_C(   535),  INT16_C(    14) },
      {  INT16_C(    10), -INT16_C(     1),  INT16_C(     0),       INT16_MIN } },
    { { -INT16_C( 30833), -INT16_C(  3392),  INT16_C(  7263),  INT16_C(  1769) },
      {  INT16_C(    15), -INT16_C( 10006), -INT16_C( 26926), -INT16_C( 19506) },
      {       INT16_MIN, -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 24162),  INT16_C( 31020), -INT16_C( 13216), -INT16_C( 28236) },
      {  INT16_C(     9),  INT16_C(    11),  INT16_C(    16),  INT16_C(  2895) },
      { -INT16_C( 15360),  INT16_C( 24576),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(   844), -INT16_C( 30766), -INT16_C( 24430),  INT16_C(  3898) },
      {  INT16_C(     9), -INT16_C(     9), -INT16_C(    16),  INT16_C(  2356) },
      {  INT16_C( 26624), -INT16_C(    61), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C(  7438), -INT16_C( 17736),  INT16_C(  2143), -INT16_C( 16698) },
      { -INT16_C(    10), -INT16_C(    11), -INT16_C(    15),  INT16_C(    12) },
      {  INT16_C(     7), -INT16_C(     9),  INT16_C(     0),  INT16_C( 24576) } },
    { {  INT16_C(  2818), -INT16_C( 21698),  INT16_C( 29388),  INT16_C( 22965) },
      {  INT16_C(    10),  INT16_C( 27061),  INT16_C(    13), -INT16_C( 13277) },
      {  INT16_C(  2048), -INT16_C(     1),       INT16_MIN,  INT16_C(     0) } },
    { {  INT16_C( 17345), -INT16_C( 26964),  INT16_C( 10446), -INT16_C(  1539) },
      {  INT16_C(    14), -INT16_C(  7811), -INT16_C(     9),  INT16_C( 19084) },
      {  INT16_C( 16384),  INT16_C(     0),  INT16_C(    20), -INT16_C(     1) } },
    { {  INT16_C( 22929), -INT16_C(   270),  INT16_C(  5830),  INT16_C( 15563) },
      {  INT16_C(    10), -INT16_C( 15886), -INT16_C(    13),  INT16_C(    12) },
      {  INT16_C( 17408), -INT16_C(     1),  INT16_C(     0), -INT16_C( 20480) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vshl_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshl_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1402414275), -INT32_C(  1645897146) },
      { -INT32_C(  2041372483),  INT32_C(          27) },
      {  INT32_C(           0),  INT32_C(   805306368) } },
    { { -INT32_C(   337674635),  INT32_C(  1447925697) },
      { -INT32_C(          22),  INT32_C(          24) },
      { -INT32_C(          81), -INT32_C(  1056964608) } },
    { { -INT32_C(  1179497220),  INT32_C(  2067727725) },
      {  INT32_C(   464721261), -INT32_C(   409327608) },
      {  INT32_C(           0),  INT32_C(  1057320192) } },
    { {  INT32_C(  1773232254), -INT32_C(  1441594400) },
      {  INT32_C(          31), -INT32_C(          23) },
      {  INT32_C(           0), -INT32_C(         172) } },
    { {  INT32_C(   448004524),  INT32_C(   506816278) },
      { -INT32_C(          24), -INT32_C(          18) },
      {  INT32_C(          26),  INT32_C(        1933) } },
    { { -INT32_C(   141688609), -INT32_C(   680092959) },
      {  INT32_C(          24),  INT32_C(          23) },
      { -INT32_C(   553648128),  INT32_C(  1887436800) } },
    { {  INT32_C(   614038165),  INT32_C(  1976016714) },
      {  INT32_C(          32),  INT32_C(          30) },
      {  INT32_C(           0),            INT32_MIN } },
    { {  INT32_C(  2026479318),  INT32_C(  1507608799) },
      { -INT32_C(          18),  INT32_C(          21) },
      {  INT32_C(        7730),  INT32_C(   467664896) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vshl_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshl_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 4131760704340726406) },
      { -INT64_C(                  51) },
      { -INT64_C(                1835) } },
    { {  INT64_C( 4795347804945835666) },
      { -INT64_C( 8617733424538507080) },
      {  INT64_C(                   0) } },
    { { -INT64_C( 2987477723010756817) },
      { -INT64_C(                  49) },
      { -INT64_C(                5307) } },
    { { -INT64_C(  834069088546172233) },
      {  INT64_C(                  62) },
      { -INT64_C( 4611686018427387904) } },
    { { -INT64_C( 3249651920531950297) },
      {  INT64_C( 2418075451758470935) },
      {  INT64_C( 7338760155284111360) } },
    { {  INT64_C( 5243402359250859729) },
      { -INT64_C(                  47) },
      {  INT64_C(               37256) } },
    { { -INT64_C( 5953442574285360237) },
      {  INT64_C(                  33) },
      { -INT64_C( 1003907829020491776) } },
    { {  INT64_C( 7218011237552599699) },
      { -INT64_C(                  36) },
      {  INT64_C(           105035887) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vshl_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshl_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(175), UINT8_C(152), UINT8_C(126), UINT8_C(  1), UINT8_C(164), UINT8_C( 17), UINT8_C(164), UINT8_C( 72) },
      { -INT8_C(   8),  INT8_C(   7), -INT8_C(   8), -INT8_C(   7), -INT8_C(   7), -INT8_C(   8),  INT8_C(   7),  INT8_C(   6) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(189), UINT8_C(130), UINT8_C(234), UINT8_C(197), UINT8_C(247), UINT8_C( 15), UINT8_C( 90), UINT8_C(166) },
      { -INT8_C(   6), -INT8_C(  40), -INT8_C(  89),  INT8_C(   4), -INT8_C(   6),  INT8_C(   4), -INT8_C(   7), -INT8_C(   5) },
      { UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C( 80), UINT8_C(  3), UINT8_C(240), UINT8_C(  0), UINT8_C(  5) } },
    { { UINT8_C(173), UINT8_C(  5), UINT8_C(173), UINT8_C(224), UINT8_C( 34), UINT8_C(193), UINT8_C(253), UINT8_C(223) },
      {  INT8_C(  68), -INT8_C(   6), -INT8_C(   6),  INT8_C(   7), -INT8_C(   5), -INT8_C(   1), -INT8_C(  30), -INT8_C(   7) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  1), UINT8_C( 96), UINT8_C(  0), UINT8_C(  1) } },
    { { UINT8_C(149), UINT8_C( 67), UINT8_C(249), UINT8_C( 57), UINT8_C( 39), UINT8_C(110), UINT8_C( 16), UINT8_C(213) },
      {  INT8_C(   7), -INT8_C(   5), -INT8_C(  75), -INT8_C(   7),      INT8_MAX, -INT8_C(   5),  INT8_C(   7), -INT8_C(  61) },
      { UINT8_C(128), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(106), UINT8_C( 26), UINT8_C(178), UINT8_C( 63), UINT8_C(152), UINT8_C( 78), UINT8_C(222), UINT8_C( 45) },
      { -INT8_C(   7), -INT8_C(   5),  INT8_C(   6), -INT8_C(   5),  INT8_C(  70),  INT8_C( 119), -INT8_C(   8), -INT8_C(   5) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1) } },
    { { UINT8_C(225), UINT8_C(119), UINT8_C( 36), UINT8_C(251), UINT8_C( 88), UINT8_C( 84), UINT8_C(236), UINT8_C(195) },
      {  INT8_C(   6), -INT8_C(   7),  INT8_C(   2),  INT8_C(   7), -INT8_C(   5), -INT8_C(   8),  INT8_C(  52),  INT8_C(   7) },
      { UINT8_C( 64), UINT8_C(  0), UINT8_C(144), UINT8_C(128), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(128) } },
    { { UINT8_C( 11), UINT8_C( 11), UINT8_C(253), UINT8_C(  2), UINT8_C(210), UINT8_C(118), UINT8_C(148), UINT8_C(179) },
      { -INT8_C(  19), -INT8_C(   5), -INT8_C(  82),  INT8_C(   8),  INT8_C(  12), -INT8_C(   7),  INT8_C(   4),  INT8_C(   7) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(128) } },
    { { UINT8_C( 82), UINT8_C(221), UINT8_C(165), UINT8_C(101), UINT8_C(164), UINT8_C( 95), UINT8_C(174), UINT8_C(175) },
      {  INT8_C( 106), -INT8_C(   6), -INT8_C(   5),  INT8_C(  60),  INT8_C(   8),  INT8_C(   8), -INT8_C(   5),  INT8_C(   7) },
      { UINT8_C(  0), UINT8_C(  3), UINT8_C(  5), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  5), UINT8_C(128) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vshl_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshl_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(56931), UINT16_C(23193), UINT16_C( 9883), UINT16_C(43704) },
      { -INT16_C(  3137),  INT16_C(    14),  INT16_C(    13), -INT16_C(    15) },
      { UINT16_C(    0), UINT16_C(16384), UINT16_C(24576), UINT16_C(    1) } },
    { { UINT16_C(29266), UINT16_C(21354), UINT16_C(31280), UINT16_C(41289) },
      { -INT16_C(     9),  INT16_C(    13),  INT16_C(    16),  INT16_C(    10) },
      { UINT16_C(   57), UINT16_C(16384), UINT16_C(    0), UINT16_C( 9216) } },
    { { UINT16_C(37644), UINT16_C( 2112), UINT16_C(22945), UINT16_C(21910) },
      {  INT16_C(    16),  INT16_C( 21362), -INT16_C(  9070), -INT16_C(    16) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(60364), UINT16_C(34815), UINT16_C(24588), UINT16_C(21725) },
      { -INT16_C(     9), -INT16_C( 31142), -INT16_C(    13),  INT16_C(     8) },
      { UINT16_C(  117), UINT16_C(    0), UINT16_C(    3), UINT16_C(56576) } },
    { { UINT16_C(55365), UINT16_C(55369), UINT16_C(61620), UINT16_C( 2714) },
      { -INT16_C(    10), -INT16_C(    11),  INT16_C(    15), -INT16_C(    10) },
      { UINT16_C(   54), UINT16_C(   27), UINT16_C(    0), UINT16_C(    2) } },
    { { UINT16_C(42220), UINT16_C(23908), UINT16_C(62271), UINT16_C(13422) },
      { -INT16_C(    11),  INT16_C( 23850),  INT16_C( 29613),  INT16_C(    12) },
      { UINT16_C(   20), UINT16_C(    0), UINT16_C(    0), UINT16_C(57344) } },
    { { UINT16_C(28878), UINT16_C(47086), UINT16_C( 8563), UINT16_C(54957) },
      { -INT16_C(     9),  INT16_C(    14),  INT16_C(    12), -INT16_C(    10) },
      { UINT16_C(   56), UINT16_C(32768), UINT16_C(12288), UINT16_C(   53) } },
    { { UINT16_C(14781), UINT16_C(27520), UINT16_C(46765), UINT16_C( 4301) },
      {  INT16_C(    14),  INT16_C(    10),  INT16_C(    16),  INT16_C(    14) },
      { UINT16_C(16384), UINT16_C(    0), UINT16_C(    0), UINT16_C(16384) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vshl_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshl_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(4031652633), UINT32_C( 311972277) },
      { -INT32_C(  1862162264), -INT32_C(          27) },
      { UINT32_C(         0), UINT32_C(         2) } },
    { { UINT32_C(1875928802), UINT32_C(1012393445) },
      {  INT32_C(          22),  INT32_C(   458250701) },
      { UINT32_C(3095396352), UINT32_C(         0) } },
    { { UINT32_C( 337109612), UINT32_C( 631576714) },
      { -INT32_C(          22), -INT32_C(          28) },
      { UINT32_C(        80), UINT32_C(         2) } },
    { { UINT32_C(1865639127), UINT32_C(3265033205) },
      {  INT32_C(   400420045),  INT32_C(          17) },
      { UINT32_C(         0), UINT32_C(3890872320) } },
    { { UINT32_C(2728985120), UINT32_C(3863832004) },
      {  INT32_C(   282615555), -INT32_C(  1988841386) },
      { UINT32_C( 357044480), UINT32_C(         0) } },
    { { UINT32_C(3391863805), UINT32_C(2564884647) },
      { -INT32_C(          21),  INT32_C(          17) },
      { UINT32_C(      1617), UINT32_C( 290324480) } },
    { { UINT32_C(1885057389), UINT32_C(1719677712) },
      {  INT32_C(          31), -INT32_C(          30) },
      { UINT32_C(2147483648), UINT32_C(         1) } },
    { { UINT32_C(3825112978), UINT32_C(3499270002) },
      { -INT32_C(          31),  INT32_C(          19) },
      { UINT32_C(         1), UINT32_C(4220518400) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vshl_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshl_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(11696413056005045141) },
      { -INT64_C(                  44) },
      { UINT64_C(              664864) } },
    { { UINT64_C( 3547630782645285736) },
      {  INT64_C(                  53) },
      { UINT64_C( 7854277750134145024) } },
    { { UINT64_C( 4095866130771274042) },
      {  INT64_C(                  51) },
      { UINT64_C( 5318751159924555776) } },
    { { UINT64_C( 8075566222472937271) },
      {  INT64_C( 7690559925448101003) },
      { UINT64_C(                   0) } },
    { { UINT64_C(15518374271611565638) },
      { -INT64_C(                  37) },
      { UINT64_C(           112911033) } },
    { { UINT64_C( 3189460018293476581) },
      {  INT64_C( 2719345347016508604) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 2268110154784134107) },
      {  INT64_C(                  59) },
      { UINT64_C(15564440312192434176) } },
    { { UINT64_C(16898964182742939517) },
      {  INT64_C(                  44) },
      { UINT64_C( 1402818507367776256) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vshl_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshlq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  77), -INT8_C( 116),  INT8_C(  46), -INT8_C( 111), -INT8_C(  34),  INT8_C( 122),  INT8_C(  15), -INT8_C(  95),
        -INT8_C(  37), -INT8_C(  96), -INT8_C(  54), -INT8_C(  88), -INT8_C(  94),  INT8_C( 117), -INT8_C(  66), -INT8_C(  40) },
      { -INT8_C(   8), -INT8_C(   7), -INT8_C(   5), -INT8_C( 111), -INT8_C(   7),  INT8_C(   6),  INT8_C(  11), -INT8_C(  92),
         INT8_C(   7), -INT8_C(   8),  INT8_C( 126),  INT8_C(   5), -INT8_C(   5),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   1), -INT8_C(   1), -INT8_C(   1),      INT8_MIN,  INT8_C(   0), -INT8_C(   1),
             INT8_MIN, -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   3), -INT8_C(  96),      INT8_MIN,  INT8_C(   0) } },
    { { -INT8_C(  29), -INT8_C(  92), -INT8_C( 119), -INT8_C(  77),  INT8_C(  17), -INT8_C( 108),  INT8_C(  87), -INT8_C( 119),
         INT8_C(  26), -INT8_C(  43), -INT8_C(  97), -INT8_C(   7),  INT8_C(   2),  INT8_C(   3),  INT8_C(  37), -INT8_C(  69) },
      { -INT8_C(   7), -INT8_C(   8),  INT8_C(   5), -INT8_C(   6), -INT8_C(   5), -INT8_C(   8), -INT8_C(   8),  INT8_C(   7),
        -INT8_C(   8),  INT8_C(   6),  INT8_C(  47),  INT8_C(   6),  INT8_C( 103),  INT8_C(   5), -INT8_C(   2),  INT8_C(   4) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(  32), -INT8_C(   2),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),      INT8_MIN,
         INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(  96),  INT8_C(   9), -INT8_C(  80) } },
    { {  INT8_C(  56),  INT8_C(  59),  INT8_C(  49), -INT8_C(  23), -INT8_C(  57), -INT8_C(  69),  INT8_C(   8),  INT8_C(  85),
        -INT8_C(  44),  INT8_C(  55),  INT8_C(  92),  INT8_C(  60),  INT8_C(  79),  INT8_C(  90), -INT8_C( 121),  INT8_C(  10) },
      { -INT8_C(   8), -INT8_C( 123), -INT8_C(   6), -INT8_C(   1), -INT8_C(   5),  INT8_C(   5),  INT8_C(  53),  INT8_C(   4),
         INT8_C(   8),  INT8_C( 101),  INT8_C(   6),  INT8_C(   6), -INT8_C(   5),  INT8_C(   6), -INT8_C(   6), -INT8_C(   7) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  12), -INT8_C(   2),  INT8_C(  96),  INT8_C(   0),  INT8_C(  80),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),      INT8_MIN, -INT8_C(   2),  INT8_C(   0) } },
    { { -INT8_C(  78),  INT8_C(  77),  INT8_C(  10), -INT8_C( 116),  INT8_C( 122),  INT8_C(  63), -INT8_C( 112), -INT8_C(  99),
        -INT8_C(  92), -INT8_C(  62), -INT8_C(  72),  INT8_C(  94), -INT8_C(  36),  INT8_C(  97),  INT8_C(  81),  INT8_C(  49) },
      {  INT8_C(  60),  INT8_C(  45),  INT8_C(   4), -INT8_C(   6),  INT8_C(  17), -INT8_C(   8),  INT8_C(   7),  INT8_C(   5),
        -INT8_C(   8), -INT8_C(  31), -INT8_C(   7), -INT8_C(   5),  INT8_C(   7),  INT8_C(   7), -INT8_C(  63), -INT8_C(   8) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  96), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  96),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   2),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 116), -INT8_C(   6), -INT8_C( 103), -INT8_C(  99), -INT8_C(  70), -INT8_C(  43), -INT8_C(  53),  INT8_C(  72),
        -INT8_C(  74),  INT8_C(  99), -INT8_C(   1), -INT8_C(  59),  INT8_C( 113), -INT8_C(  64), -INT8_C( 123), -INT8_C(  52) },
      { -INT8_C(   8), -INT8_C(   6), -INT8_C(  94), -INT8_C(   7), -INT8_C(   6),  INT8_C(   5),  INT8_C(   8),  INT8_C(   4),
         INT8_C(   7),  INT8_C(   5), -INT8_C(   7), -INT8_C(   7), -INT8_C(   5),  INT8_C(   7), -INT8_C(   7),  INT8_C(   7) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   2), -INT8_C(  96),  INT8_C(   0),      INT8_MIN,
         INT8_C(   0),  INT8_C(  96), -INT8_C(   1), -INT8_C(   1),  INT8_C(   3),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C(  44), -INT8_C(  21),  INT8_C(  85), -INT8_C( 125),  INT8_C(   0), -INT8_C( 100), -INT8_C(  47),  INT8_C(  63),
        -INT8_C(  16), -INT8_C( 102),  INT8_C(  10), -INT8_C(  92),  INT8_C(  16), -INT8_C(  99), -INT8_C(  29),      INT8_MIN },
      { -INT8_C(   7), -INT8_C(   8), -INT8_C(   6), -INT8_C(   7),  INT8_C(   6),  INT8_C(   7), -INT8_C( 125),  INT8_C(   7),
        -INT8_C( 113),  INT8_C(   0), -INT8_C(   8), -INT8_C(   8),  INT8_C(   2),  INT8_C(   7), -INT8_C(   8), -INT8_C(   6) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),      INT8_MIN,
        -INT8_C(   1), -INT8_C( 102),  INT8_C(   0), -INT8_C(   1),  INT8_C(  64),      INT8_MIN, -INT8_C(   1), -INT8_C(   2) } },
    { { -INT8_C(  86),  INT8_C(   1), -INT8_C(  96),  INT8_C(  19),  INT8_C(  30),  INT8_C(  35), -INT8_C( 121), -INT8_C(  82),
         INT8_C(  35),  INT8_C( 120),  INT8_C( 112),  INT8_C(  38), -INT8_C(  78), -INT8_C(  16), -INT8_C(   3), -INT8_C(  40) },
      { -INT8_C(   8),  INT8_C(   5), -INT8_C(   2),  INT8_C(   7), -INT8_C(   8),  INT8_C(   6), -INT8_C(   7),  INT8_C(   4),
        -INT8_C(   6), -INT8_C(   6),  INT8_C(   8), -INT8_C(   5), -INT8_C(   8),  INT8_C(   7), -INT8_C(   5),  INT8_C(   6) },
      { -INT8_C(   1),  INT8_C(  32), -INT8_C(  24),      INT8_MIN,  INT8_C(   0), -INT8_C(  64), -INT8_C(   1), -INT8_C(  32),
         INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  22), -INT8_C(  47), -INT8_C(  92), -INT8_C( 103),  INT8_C(  53),  INT8_C(  63), -INT8_C(  29),  INT8_C(   7),
        -INT8_C(  32),  INT8_C(   4), -INT8_C(  26),  INT8_C( 108),  INT8_C( 123), -INT8_C( 102), -INT8_C(  94), -INT8_C(  13) },
      { -INT8_C(  18), -INT8_C(   6), -INT8_C(   8),  INT8_C( 102), -INT8_C(   5), -INT8_C(  50),  INT8_C(   2),  INT8_C(   3),
        -INT8_C( 126), -INT8_C(  61), -INT8_C(   3),  INT8_C(   4), -INT8_C(   8), -INT8_C(  48), -INT8_C(   7), -INT8_C(   7) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0), -INT8_C( 116),  INT8_C(  56),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   4), -INT8_C(  64),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vshlq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshlq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 20268),  INT16_C( 24220),  INT16_C( 20072), -INT16_C( 27645),  INT16_C(  1744),  INT16_C( 22176), -INT16_C( 26671),  INT16_C( 22566) },
      {  INT16_C(    11), -INT16_C(    13), -INT16_C(    14), -INT16_C(    13), -INT16_C(    14),  INT16_C(    16),  INT16_C(    10),  INT16_C(  4205) },
      {  INT16_C( 24576),  INT16_C(     2),  INT16_C(     1), -INT16_C(     4),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17408),  INT16_C(     0) } },
    { { -INT16_C(   136),  INT16_C( 18814), -INT16_C( 23402),  INT16_C( 17825), -INT16_C( 12846),  INT16_C( 12767),  INT16_C( 24470),  INT16_C( 16845) },
      { -INT16_C(    12),  INT16_C(    11), -INT16_C(    13),  INT16_C(    12), -INT16_C(    15),  INT16_C(    12),  INT16_C(     8),  INT16_C(    14) },
      { -INT16_C(     1), -INT16_C(  4096), -INT16_C(     3),  INT16_C(  4096), -INT16_C(     1), -INT16_C(  4096), -INT16_C( 27136),  INT16_C( 16384) } },
    { { -INT16_C(   469), -INT16_C( 16002),  INT16_C( 19293), -INT16_C( 31486),  INT16_C( 26094), -INT16_C( 23408), -INT16_C( 21452),  INT16_C(  3518) },
      { -INT16_C(    12),  INT16_C(    12), -INT16_C( 26906),  INT16_C(    10),  INT16_C(    12), -INT16_C(  6652),  INT16_C(     8), -INT16_C(  5838) },
      { -INT16_C(     1), -INT16_C(  8192),  INT16_C(     0),  INT16_C(  2048), -INT16_C(  8192),  INT16_C( 18688),  INT16_C( 13312),  INT16_C(     0) } },
    { { -INT16_C( 27631),  INT16_C( 18062),  INT16_C( 19520),  INT16_C( 30035), -INT16_C( 28177), -INT16_C( 10842),  INT16_C( 18727), -INT16_C( 27649) },
      {  INT16_C(   937),  INT16_C(    12), -INT16_C(    11),  INT16_C(     8), -INT16_C(    12),  INT16_C( 22726), -INT16_C( 13913), -INT16_C(     9) },
      { -INT16_C(     1), -INT16_C(  8192),  INT16_C(     9),  INT16_C( 21248), -INT16_C(     7), -INT16_C(     1),  INT16_C(     0), -INT16_C(    55) } },
    { { -INT16_C( 17949),  INT16_C(  3042), -INT16_C(  7934), -INT16_C( 21346),  INT16_C(  6373),  INT16_C(  2835),  INT16_C( 25796),  INT16_C(  8275) },
      {  INT16_C(    12),  INT16_C(    10), -INT16_C(     9),  INT16_C( 16574), -INT16_C( 17268), -INT16_C( 21795), -INT16_C(    16), -INT16_C(  3402) },
      {  INT16_C( 12288), -INT16_C( 30720), -INT16_C(    16), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 27571),  INT16_C( 30570), -INT16_C( 16945),  INT16_C( 11928),  INT16_C(  4566), -INT16_C( 18125), -INT16_C(  3636),  INT16_C( 23033) },
      { -INT16_C(    11), -INT16_C( 17405), -INT16_C(     9),  INT16_C(    14), -INT16_C(    11), -INT16_C(    13),  INT16_C(    14), -INT16_C(    12) },
      {  INT16_C(    13), -INT16_C( 17584), -INT16_C(    34),  INT16_C(     0),  INT16_C(     2), -INT16_C(     3),  INT16_C(     0),  INT16_C(     5) } },
    { {  INT16_C(  4379), -INT16_C(  6174), -INT16_C(  9470), -INT16_C( 20416),  INT16_C( 17330),  INT16_C( 31085),  INT16_C(  7165),  INT16_C( 20457) },
      {  INT16_C(    13),  INT16_C(    14),  INT16_C(     8),  INT16_C(    11),  INT16_C( 31451),  INT16_C(    11), -INT16_C(    13), -INT16_C(    13) },
      {  INT16_C( 24576),       INT16_MIN,  INT16_C(   512),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26624),  INT16_C(     0),  INT16_C(     2) } },
    { {  INT16_C(  6155),  INT16_C(  2113),  INT16_C( 10804), -INT16_C(  1193),  INT16_C( 29232), -INT16_C( 21751),  INT16_C(  4536), -INT16_C( 27899) },
      {  INT16_C(    15),  INT16_C(    16),  INT16_C(  6903), -INT16_C(     9),  INT16_C(    13),  INT16_C( 27370), -INT16_C(    14),  INT16_C(  2354) },
      {       INT16_MIN,  INT16_C(     0),  INT16_C(    21), -INT16_C(     3),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vshlq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshlq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  2041763791), -INT32_C(  1618428475),  INT32_C(   828034002),  INT32_C(  1472186433) },
      { -INT32_C(          20), -INT32_C(          27),  INT32_C(          19), -INT32_C(          23) },
      { -INT32_C(        1948), -INT32_C(          13),  INT32_C(  1586495488),  INT32_C(         175) } },
    { {  INT32_C(  1298576763), -INT32_C(  1031880575), -INT32_C(   719766135), -INT32_C(   561639655) },
      {  INT32_C(          25),  INT32_C(          28), -INT32_C(   639565865),  INT32_C(          28) },
      { -INT32_C(   167772160),  INT32_C(   268435456), -INT32_C(           1), -INT32_C(  1879048192) } },
    { {  INT32_C(  1325794246),  INT32_C(  1512382273), -INT32_C(   633820370),  INT32_C(    71426368) },
      { -INT32_C(          19), -INT32_C(          29), -INT32_C(   272289748), -INT32_C(          23) },
      {  INT32_C(        2528),  INT32_C(           2),  INT32_C(           0),  INT32_C(           8) } },
    { { -INT32_C(  1997967014),  INT32_C(  1566712093), -INT32_C(   496917758),  INT32_C(  1117429619) },
      { -INT32_C(          23), -INT32_C(          28),  INT32_C(          22), -INT32_C(          24) },
      { -INT32_C(         239),  INT32_C(           5), -INT32_C(  1065353216),  INT32_C(          66) } },
    { { -INT32_C(   943223611), -INT32_C(  1565906897), -INT32_C(  2065414969), -INT32_C(   915557522) },
      {  INT32_C(          18), -INT32_C(          26),  INT32_C(   289016772),  INT32_C(          29) },
      {  INT32_C(   856948736), -INT32_C(          24), -INT32_C(           1), -INT32_C(  1073741824) } },
    { {  INT32_C(   834856554), -INT32_C(  1732860374), -INT32_C(  1604181159), -INT32_C(  1127957143) },
      {  INT32_C(          26), -INT32_C(          24), -INT32_C(          28), -INT32_C(          24) },
      { -INT32_C(  1476395008), -INT32_C(         104), -INT32_C(           6), -INT32_C(          68) } },
    { { -INT32_C(   987133588),  INT32_C(   375753645), -INT32_C(   288216504),  INT32_C(  1599678527) },
      { -INT32_C(          21),  INT32_C(          18),  INT32_C(          22), -INT32_C(   974423719) },
      { -INT32_C(         471),  INT32_C(   783548416), -INT32_C(  1845493760),  INT32_C(           0) } },
    { { -INT32_C(   406392673),  INT32_C(  1507236122),  INT32_C(  2042113985), -INT32_C(   786044923) },
      {  INT32_C(          20), -INT32_C(          24), -INT32_C(          18),  INT32_C(  1269297579) },
      {  INT32_C(   166723584),  INT32_C(          89),  INT32_C(        7790), -INT32_C(           1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vshlq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshlq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8363743883797716341),  INT64_C( 8779737833653395887) },
      { -INT64_C(                  63),  INT64_C(  246405564730123878) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 8126799927234921685), -INT64_C( 6485624037076249828) },
      { -INT64_C(                  58), -INT64_C( 7250353646116027793) },
      {  INT64_C(                  28),  INT64_C(                   0) } },
    { { -INT64_C( 3234373439391986046), -INT64_C( 2587179382443185883) },
      { -INT64_C(                  33),  INT64_C(                  50) },
      { -INT64_C(           376530625), -INT64_C( 6587640354936193024) } },
    { { -INT64_C( 8631416662590524752),  INT64_C( 3592062853739595312) },
      {  INT64_C(                  45),  INT64_C(                  46) },
      { -INT64_C( 1272829844685586432), -INT64_C( 7958986441470509056) } },
    { {  INT64_C( 8962794885418511845),  INT64_C( 7398396818986337414) },
      {  INT64_C(                  42), -INT64_C( 4848071295825756004) },
      {  INT64_C( 4303070696696709120),  INT64_C(                   0) } },
    { {  INT64_C( 2287417463048279256),  INT64_C( 5354139880492463338) },
      {  INT64_C(                  61), -INT64_C(                  54) },
      {  INT64_C(                   0),  INT64_C(                 297) } },
    { { -INT64_C( 3385921522485940017), -INT64_C( 6409014629278950304) },
      {  INT64_C(                  55),  INT64_C(                  38) },
      {  INT64_C( 7457960982925541376),  INT64_C( 7131194923243536384) } },
    { { -INT64_C(  596211911612917029),  INT64_C( 5427564910413537154) },
      { -INT64_C(                  35),  INT64_C(                  61) },
      { -INT64_C(            17352051),  INT64_C( 4611686018427387904) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vshlq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshlq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(227), UINT8_C( 82), UINT8_C( 19), UINT8_C( 82), UINT8_C(244), UINT8_C(233), UINT8_C(145), UINT8_C(146),
        UINT8_C(188), UINT8_C(114), UINT8_C( 73), UINT8_C(201), UINT8_C(134), UINT8_C(245), UINT8_C(132), UINT8_C(232) },
      {  INT8_C( 120), -INT8_C(   6), -INT8_C(   7), -INT8_C(   4), -INT8_C(   7),  INT8_C(   5),  INT8_C(   7), -INT8_C(   8),
         INT8_C(   7),  INT8_C(   7), -INT8_C(   5), -INT8_C(   8), -INT8_C(   8),  INT8_C(   6),  INT8_C(   8), -INT8_C(  88) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  5), UINT8_C(  1), UINT8_C( 32), UINT8_C(128), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(207), UINT8_C( 84), UINT8_C(242), UINT8_C(158), UINT8_C(178), UINT8_C(112), UINT8_C(127), UINT8_C(239),
        UINT8_C(142), UINT8_C(110), UINT8_C(232), UINT8_C( 84), UINT8_C(213), UINT8_C(  8), UINT8_C(252), UINT8_C(142) },
      {  INT8_C(   7), -INT8_C(   5),  INT8_C(   7),  INT8_C(   5), -INT8_C(   8),  INT8_C(   7),  INT8_C(   6), -INT8_C(   8),
         INT8_C(   3), -INT8_C(   6),  INT8_C(   4), -INT8_C(   8), -INT8_C(   1),  INT8_C(   7),  INT8_C( 118), -INT8_C(   7) },
      { UINT8_C(128), UINT8_C(  2), UINT8_C(  0), UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C(192), UINT8_C(  0),
        UINT8_C(112), UINT8_C(  1), UINT8_C(128), UINT8_C(  0), UINT8_C(106), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1) } },
    { { UINT8_C(175), UINT8_C(247), UINT8_C(237), UINT8_C( 49), UINT8_C(113), UINT8_C( 33), UINT8_C(178), UINT8_C(116),
        UINT8_C(249), UINT8_C(182), UINT8_C(245), UINT8_C(248), UINT8_C( 39), UINT8_C(107), UINT8_C(198), UINT8_C(236) },
      { -INT8_C(   6),  INT8_C(   6),  INT8_C(   6), -INT8_C(   6),  INT8_C(   7), -INT8_C(   7),  INT8_C(   5),  INT8_C(   7),
         INT8_C(  24), -INT8_C(   6), -INT8_C(   6),  INT8_C(   6), -INT8_C(   8),  INT8_C(   6),  INT8_C(   3),  INT8_C(   6) },
      { UINT8_C(  2), UINT8_C(192), UINT8_C( 64), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C( 64), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0), UINT8_C(192), UINT8_C( 48), UINT8_C(  0) } },
    { { UINT8_C(251), UINT8_C( 72), UINT8_C( 30), UINT8_C( 24), UINT8_C( 18), UINT8_C( 51), UINT8_C(142), UINT8_C( 43),
        UINT8_C(  3), UINT8_C( 50), UINT8_C(154), UINT8_C(139), UINT8_C(146), UINT8_C(157), UINT8_C(194), UINT8_C(233) },
      { -INT8_C(   8),  INT8_C(   5), -INT8_C(   5), -INT8_C(   6),  INT8_C(   8), -INT8_C(   5), -INT8_C(   6),  INT8_C(   5),
         INT8_C(   8), -INT8_C(  82),  INT8_C(   7), -INT8_C(   5),  INT8_C(   7), -INT8_C(   7),  INT8_C(   5),  INT8_C(   7) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  2), UINT8_C( 96),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0), UINT8_C(  1), UINT8_C( 64), UINT8_C(128) } },
    { { UINT8_C(251), UINT8_C(118), UINT8_C(223), UINT8_C( 64), UINT8_C(101), UINT8_C(138), UINT8_C( 86), UINT8_C(133),
        UINT8_C( 56), UINT8_C(101), UINT8_C( 67), UINT8_C(175), UINT8_C( 88), UINT8_C(115), UINT8_C( 33), UINT8_C(148) },
      { -INT8_C(   8), -INT8_C(   6), -INT8_C(   8),  INT8_C(   8), -INT8_C(   8),  INT8_C(  92), -INT8_C(   8),  INT8_C(   6),
         INT8_C(   7), -INT8_C(  43), -INT8_C(  23),  INT8_C(   8), -INT8_C(   6), -INT8_C(   6),  INT8_C(   6), -INT8_C(   6) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C( 64), UINT8_C(  2) } },
    { { UINT8_C(128), UINT8_C(109), UINT8_C(201), UINT8_C( 68), UINT8_C(202), UINT8_C(143), UINT8_C( 81), UINT8_C( 58),
        UINT8_C(100), UINT8_C( 59), UINT8_C( 92), UINT8_C( 10), UINT8_C(233), UINT8_C(190), UINT8_C(171), UINT8_C( 14) },
      { -INT8_C(   1), -INT8_C(   8), -INT8_C(   7), -INT8_C(   7), -INT8_C(  58), -INT8_C(   6), -INT8_C(   7),  INT8_C(   6),
        -INT8_C(   5), -INT8_C(   8),  INT8_C(   5), -INT8_C(   8),  INT8_C(   5), -INT8_C(   7),  INT8_C(   4), -INT8_C(   6) },
      { UINT8_C( 64), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(128),
        UINT8_C(  3), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C( 32), UINT8_C(  1), UINT8_C(176), UINT8_C(  0) } },
    { { UINT8_C( 71), UINT8_C( 56), UINT8_C( 58), UINT8_C( 13), UINT8_C(224), UINT8_C(  8), UINT8_C(112), UINT8_C(219),
        UINT8_C(138), UINT8_C(202), UINT8_C(156), UINT8_C(225), UINT8_C(174), UINT8_C(228), UINT8_C(185),    UINT8_MAX },
      { -INT8_C(   6), -INT8_C(   6),  INT8_C(   6), -INT8_C(   7),  INT8_C(   8),  INT8_C( 113), -INT8_C(   7), -INT8_C(  23),
         INT8_C(  35), -INT8_C(   6),  INT8_C(   7), -INT8_C(   7),  INT8_C(   6),  INT8_C(   6),  INT8_C(   3), -INT8_C(   6) },
      { UINT8_C(  1), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(  0), UINT8_C(200), UINT8_C(  3) } },
    { { UINT8_C( 63), UINT8_C(184), UINT8_C( 27), UINT8_C(129), UINT8_C( 41), UINT8_C(181), UINT8_C(106), UINT8_C( 76),
        UINT8_C( 92), UINT8_C(229), UINT8_C(224), UINT8_C(189), UINT8_C(  0), UINT8_C(228), UINT8_C(101), UINT8_C( 84) },
      {  INT8_C(  33),  INT8_C(   6), -INT8_C(   8),  INT8_C(   6),  INT8_C(   8), -INT8_C(   7),  INT8_C(   7),  INT8_C(   5),
         INT8_C(   8), -INT8_C(   6), -INT8_C(   7), -INT8_C(   6),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5), -INT8_C(   7) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(128),
        UINT8_C(  0), UINT8_C(  3), UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(160), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vshlq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshlq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(26316), UINT16_C(46829), UINT16_C(17801), UINT16_C( 9381), UINT16_C(58471), UINT16_C(14280), UINT16_C(43915), UINT16_C(18443) },
      { -INT16_C(    13), -INT16_C(    15),  INT16_C(     8),  INT16_C( 28360),  INT16_C(    14), -INT16_C( 31360),  INT16_C(    10), -INT16_C( 31767) },
      { UINT16_C(    3), UINT16_C(    1), UINT16_C(35072), UINT16_C(    0), UINT16_C(49152), UINT16_C(    0), UINT16_C(11264), UINT16_C(    0) } },
    { { UINT16_C(12995), UINT16_C(20154), UINT16_C(50653), UINT16_C(13207), UINT16_C(34146), UINT16_C(19137), UINT16_C(35274), UINT16_C(49848) },
      {  INT16_C( 14589), -INT16_C(    10),  INT16_C(    12),  INT16_C( 19512),  INT16_C(    14),  INT16_C(     9), -INT16_C(    11),  INT16_C(  5031) },
      { UINT16_C( 1624), UINT16_C(   19), UINT16_C(53248), UINT16_C(    0), UINT16_C(32768), UINT16_C(33280), UINT16_C(   17), UINT16_C(    0) } },
    { { UINT16_C(  638), UINT16_C(18898), UINT16_C(35467), UINT16_C(35083), UINT16_C(21186), UINT16_C(20798), UINT16_C(30339), UINT16_C(35741) },
      {  INT16_C( 12520),  INT16_C(    14),  INT16_C(    10),  INT16_C(    11), -INT16_C(    11), -INT16_C(     9), -INT16_C(    11),  INT16_C(  9829) },
      { UINT16_C(    0), UINT16_C(32768), UINT16_C(11264), UINT16_C(22528), UINT16_C(   10), UINT16_C(   40), UINT16_C(   14), UINT16_C(    0) } },
    { { UINT16_C(  204), UINT16_C(20692), UINT16_C(29303), UINT16_C(24539), UINT16_C(35746), UINT16_C(53400), UINT16_C(58849), UINT16_C(39214) },
      { -INT16_C(    13),  INT16_C(    14), -INT16_C(     9), -INT16_C(    12), -INT16_C( 12269), -INT16_C(    11), -INT16_C(    16),  INT16_C(  5720) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(   57), UINT16_C(    5), UINT16_C(    0), UINT16_C(   26), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(24525), UINT16_C(44562), UINT16_C(16452), UINT16_C(55367), UINT16_C(48858), UINT16_C( 8211), UINT16_C(29850), UINT16_C(44308) },
      {  INT16_C(    16), -INT16_C(    15), -INT16_C(  9422),  INT16_C(  8868),  INT16_C(    11), -INT16_C(    12),  INT16_C(    10),  INT16_C(  6888) },
      { UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(53248), UINT16_C(    2), UINT16_C(26624), UINT16_C(    0) } },
    { { UINT16_C(57550), UINT16_C(26678), UINT16_C(19028), UINT16_C(38933), UINT16_C(39052), UINT16_C(48678), UINT16_C(51827), UINT16_C(31713) },
      {  INT16_C( 27605),  INT16_C(  8738),  INT16_C(    10),  INT16_C(    13),  INT16_C(  1285),  INT16_C( 16481),  INT16_C( 11797), -INT16_C(    15) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(20480), UINT16_C(40960), UINT16_C( 4480), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 8440), UINT16_C(27425), UINT16_C(  747), UINT16_C(49382), UINT16_C( 2157), UINT16_C(10723), UINT16_C( 7955), UINT16_C( 6293) },
      { -INT16_C(     9),  INT16_C(    14), -INT16_C(    11),  INT16_C( 13340),  INT16_C(    12),  INT16_C(    15), -INT16_C(    14), -INT16_C(    16) },
      { UINT16_C(   16), UINT16_C(16384), UINT16_C(    0), UINT16_C(    0), UINT16_C(53248), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(16411), UINT16_C(11818), UINT16_C(49247), UINT16_C(33862), UINT16_C(40631), UINT16_C(56509), UINT16_C(55883), UINT16_C(33808) },
      { -INT16_C(    12),  INT16_C(     9),  INT16_C(  1336), -INT16_C(    12), -INT16_C(    10),  INT16_C(    11), -INT16_C(    15),  INT16_C(     8) },
      { UINT16_C(    4), UINT16_C(21504), UINT16_C(    0), UINT16_C(    8), UINT16_C(   39), UINT16_C(59392), UINT16_C(    1), UINT16_C( 4096) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vshlq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshlq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3874822276), UINT32_C( 973838889), UINT32_C(1360305370), UINT32_C(2317166544) },
      { -INT32_C(  1429912463), -INT32_C(          22),  INT32_C(          24),  INT32_C(          32) },
      { UINT32_C(         0), UINT32_C(       232), UINT32_C(3657433088), UINT32_C(         0) } },
    { { UINT32_C(1926759064), UINT32_C(1875176862), UINT32_C(2247745812), UINT32_C(4079992614) },
      { -INT32_C(  1633882781),  INT32_C(          26), -INT32_C(          28), -INT32_C(          24) },
      { UINT32_C(         0), UINT32_C(2013265920), UINT32_C(         8), UINT32_C(       243) } },
    { { UINT32_C( 176216566), UINT32_C(3767499194), UINT32_C(2631188024), UINT32_C(2268754091) },
      {  INT32_C(          19),  INT32_C(          20),  INT32_C(          19),  INT32_C(          26) },
      { UINT32_C(3484418048), UINT32_C(2610954240), UINT32_C(4055891968), UINT32_C(2885681152) } },
    { { UINT32_C(2424153687), UINT32_C( 254562660), UINT32_C(4053231298), UINT32_C(3946678179) },
      { -INT32_C(          26),  INT32_C(  1092170026),  INT32_C(          29), -INT32_C(          21) },
      { UINT32_C(        36), UINT32_C(         0), UINT32_C(1073741824), UINT32_C(      1881) } },
    { { UINT32_C(1266772105), UINT32_C(1916606671), UINT32_C(2438822559), UINT32_C(3227359894) },
      {  INT32_C(          24),  INT32_C(          16), -INT32_C(          30), -INT32_C(          24) },
      { UINT32_C(2298478592), UINT32_C( 416219136), UINT32_C(         2), UINT32_C(       192) } },
    { { UINT32_C(1859397838), UINT32_C( 973025699), UINT32_C(2549701835), UINT32_C(3214801618) },
      {  INT32_C(          32), -INT32_C(  1228476512), -INT32_C(  1370031334), -INT32_C(          32) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C( 738197504), UINT32_C(         0) } },
    { { UINT32_C(3796299030), UINT32_C( 460930889), UINT32_C(2245662266), UINT32_C(2022169560) },
      { -INT32_C(          27), -INT32_C(          22),  INT32_C(          24), -INT32_C(          25) },
      { UINT32_C(        28), UINT32_C(       109), UINT32_C( 973078528), UINT32_C(        60) } },
    { { UINT32_C(4290575045), UINT32_C(3917780497), UINT32_C(1029770098), UINT32_C(2686619480) },
      { -INT32_C(          19), -INT32_C(          29), -INT32_C(          21), -INT32_C(          27) },
      { UINT32_C(      8183), UINT32_C(         7), UINT32_C(       491), UINT32_C(        20) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vshlq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vshlq_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 4829422187629488727), UINT64_C( 2605387542525908668) },
      { -INT64_C( 1643974313470714674),  INT64_C(                  44) },
      { UINT64_C(                4289), UINT64_C(13937444578060664832) } },
    { { UINT64_C(13970315877439767237), UINT64_C(16522513161567537670) },
      { -INT64_C(                  58),  INT64_C(                  61) },
      { UINT64_C(                  48), UINT64_C(13835058055282163712) } },
    { { UINT64_C( 1925351683289998797), UINT64_C( 2238587861661968232) },
      { -INT64_C(                  58),  INT64_C(                  38) },
      { UINT64_C(                   6), UINT64_C( 3979451439293399040) } },
    { { UINT64_C(11860546040509214202), UINT64_C( 4340667968086369747) },
      {  INT64_C(                  41), -INT64_C(                  60) },
      { UINT64_C( 8024275441927847936), UINT64_C(                   3) } },
    { { UINT64_C( 8910991743644541611), UINT64_C(14516822791415737880) },
      { -INT64_C(                  45),  INT64_C(                  47) },
      { UINT64_C(              253265), UINT64_C(10884074399447646208) } },
    { { UINT64_C(12933258487992063907), UINT64_C(11128579057712752255) },
      { -INT64_C(                  44), -INT64_C(                  61) },
      { UINT64_C(              735170), UINT64_C(                   4) } },
    { { UINT64_C(10921609281154912814), UINT64_C( 2427142075779531086) },
      { -INT64_C(                  57), -INT64_C(                  38) },
      { UINT64_C(                  75), UINT64_C(             8829891) } },
    { { UINT64_C(15939054506333309024), UINT64_C( 5590987143679708579) },
      { -INT64_C( 4843971537307842889),  INT64_C(                  49) },
      { UINT64_C(                   0), UINT64_C( 1965258287393800192) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vshlq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
