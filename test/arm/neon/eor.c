#define SIMDE_TEST_ARM_NEON_INSN eor

#include "test-neon.h"
#include "../../../simde/arm/neon/eor.h"

static int
test_simde_veor_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  57),  INT8_C(  76),  INT8_C( 112),  INT8_C( 126),  INT8_C(  46), -INT8_C(  66), -INT8_C(   3),  INT8_C(  47) },
      {  INT8_C(   8), -INT8_C( 105), -INT8_C(  32), -INT8_C(  33),  INT8_C( 118),  INT8_C(  37),  INT8_C(  95),  INT8_C(  95) },
      { -INT8_C(  49), -INT8_C(  37), -INT8_C( 112), -INT8_C(  95),  INT8_C(  88), -INT8_C( 101), -INT8_C(  94),  INT8_C( 112) } },
    { { -INT8_C(  52), -INT8_C(  65),  INT8_C(  78), -INT8_C(  24),  INT8_C(  60), -INT8_C(  59), -INT8_C( 102), -INT8_C(  44) },
      { -INT8_C(  22), -INT8_C(   3),  INT8_C( 118), -INT8_C(   6),  INT8_C(  21), -INT8_C( 127),  INT8_C(  40), -INT8_C(  36) },
      {  INT8_C(  38),  INT8_C(  66),  INT8_C(  56),  INT8_C(  18),  INT8_C(  41),  INT8_C(  68), -INT8_C(  78),  INT8_C(   8) } },
    { { -INT8_C(  50), -INT8_C( 104),  INT8_C(  90), -INT8_C(   4),  INT8_C(  86),  INT8_C(  88),  INT8_C(  43),  INT8_C(  94) },
      { -INT8_C(  17),  INT8_C(  11),  INT8_C(  62),  INT8_C( 101),  INT8_C(  48), -INT8_C(  99), -INT8_C(  60), -INT8_C(   3) },
      {  INT8_C(  33), -INT8_C( 109),  INT8_C( 100), -INT8_C( 103),  INT8_C( 102), -INT8_C(  59), -INT8_C(  17), -INT8_C(  93) } },
    { {  INT8_C(  92),  INT8_C(  19), -INT8_C(  27), -INT8_C( 103), -INT8_C(  40),      INT8_MAX,  INT8_C( 109), -INT8_C(  61) },
      {  INT8_C( 124), -INT8_C(  28), -INT8_C(  67), -INT8_C( 110),  INT8_C( 101), -INT8_C(  26),  INT8_C( 110),  INT8_C(  51) },
      {  INT8_C(  32), -INT8_C(   9),  INT8_C(  88),  INT8_C(  11), -INT8_C(  67), -INT8_C( 103),  INT8_C(   3), -INT8_C(  16) } },
    { {  INT8_C( 126), -INT8_C(  55),  INT8_C(  48), -INT8_C(  43),  INT8_C(  33),  INT8_C(  91),  INT8_C(  51),  INT8_C(  16) },
      {  INT8_C( 103),  INT8_C( 113),  INT8_C( 117), -INT8_C( 105),  INT8_C(  14),  INT8_C(  58), -INT8_C( 108),  INT8_C( 107) },
      {  INT8_C(  25), -INT8_C(  72),  INT8_C(  69),  INT8_C(  66),  INT8_C(  47),  INT8_C(  97), -INT8_C(  89),  INT8_C( 123) } },
    { {  INT8_C(  77),  INT8_C( 122),  INT8_C(   4),  INT8_C(  37), -INT8_C(   7),  INT8_C( 113), -INT8_C(  24),  INT8_C( 118) },
      {  INT8_C(  85), -INT8_C(  90),  INT8_C(   8), -INT8_C(  69), -INT8_C( 116),  INT8_C( 118), -INT8_C(  18),  INT8_C(  10) },
      {  INT8_C(  24), -INT8_C(  36),  INT8_C(  12), -INT8_C(  98),  INT8_C( 117),  INT8_C(   7),  INT8_C(   6),  INT8_C( 124) } },
    { {  INT8_C(  63),  INT8_C(  30), -INT8_C(  33),  INT8_C(  96),  INT8_C( 122),  INT8_C(  19),  INT8_C( 112), -INT8_C(  31) },
      { -INT8_C( 124), -INT8_C(  26),  INT8_C( 120), -INT8_C( 109),  INT8_C(  32),  INT8_C(  13), -INT8_C(   2),  INT8_C( 109) },
      { -INT8_C(  69), -INT8_C(   8), -INT8_C(  89), -INT8_C(  13),  INT8_C(  90),  INT8_C(  30), -INT8_C( 114), -INT8_C( 116) } },
    { { -INT8_C( 121),  INT8_C(   2), -INT8_C( 110),      INT8_MIN,  INT8_C( 115),  INT8_C( 123), -INT8_C(  10), -INT8_C(  55) },
      {  INT8_C(  33), -INT8_C(   2), -INT8_C( 124), -INT8_C(  83),  INT8_C( 117),  INT8_C( 114), -INT8_C(  73), -INT8_C(  76) },
      { -INT8_C(  90), -INT8_C(   4),  INT8_C(  22),  INT8_C(  45),  INT8_C(   6),  INT8_C(   9),  INT8_C(  65),  INT8_C( 125) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_veor_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_veor_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(  7761), -INT16_C(  3055),  INT16_C( 13277),  INT16_C( 25055) },
      {  INT16_C( 10106), -INT16_C( 30479), -INT16_C( 20937),  INT16_C( 24721) },
      {  INT16_C( 14635),  INT16_C( 31968), -INT16_C( 25110),  INT16_C(   334) } },
    { {  INT16_C( 10700),  INT16_C( 30148), -INT16_C( 17695),  INT16_C( 25566) },
      {  INT16_C( 15382), -INT16_C(  3115), -INT16_C( 27357),  INT16_C( 29773) },
      {  INT16_C(  5594), -INT16_C( 31215),  INT16_C( 12226),  INT16_C(  6035) } },
    { {  INT16_C( 24499), -INT16_C( 28311),  INT16_C( 18578),  INT16_C(  3314) },
      { -INT16_C(  7312), -INT16_C( 22635),  INT16_C(  9874),  INT16_C( 24071) },
      { -INT16_C( 17213),  INT16_C( 14076),  INT16_C( 28160),  INT16_C( 21237) } },
    { { -INT16_C( 13489),  INT16_C( 12755), -INT16_C( 20090), -INT16_C( 25452) },
      {  INT16_C( 27117),  INT16_C(  4239), -INT16_C(  8705), -INT16_C( 19835) },
      { -INT16_C( 23902),  INT16_C(  8540),  INT16_C( 27769),  INT16_C( 11793) } },
    { { -INT16_C(  4548), -INT16_C( 12733),  INT16_C( 13878), -INT16_C( 22822) },
      {  INT16_C( 28441), -INT16_C( 21683),  INT16_C( 21654), -INT16_C(  6903) },
      { -INT16_C( 32475),  INT16_C( 25870),  INT16_C( 25248),  INT16_C( 17363) } },
    { { -INT16_C(  8928), -INT16_C( 23018), -INT16_C( 21618),  INT16_C( 31810) },
      { -INT16_C( 11756),  INT16_C(  5004),  INT16_C(  4527), -INT16_C(  5178) },
      {  INT16_C(  3892), -INT16_C( 19046), -INT16_C( 17887), -INT16_C( 26748) } },
    { {  INT16_C(  2559),  INT16_C( 14009), -INT16_C( 27841),  INT16_C( 23004) },
      {  INT16_C( 10755), -INT16_C( 26364),  INT16_C(  3710), -INT16_C( 24962) },
      {  INT16_C(  9212), -INT16_C( 20547), -INT16_C( 25279), -INT16_C( 14430) } },
    { { -INT16_C( 27157),  INT16_C( 31044), -INT16_C( 30912),  INT16_C( 21749) },
      { -INT16_C( 32167),  INT16_C(  2152),  INT16_C( 11923), -INT16_C( 27661) },
      {  INT16_C(  6066),  INT16_C( 28972), -INT16_C( 22061), -INT16_C( 14586) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_veor_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_veor_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   223173885), -INT32_C(  1105528766) },
      { -INT32_C(   647648370),  INT32_C(   936515285) },
      {  INT32_C(   735512717), -INT32_C(  1983320425) } },
    { {  INT32_C(   307579213),  INT32_C(  1903436113) },
      {  INT32_C(   777768489), -INT32_C(   910509627) },
      {  INT32_C(  1007585124), -INT32_C(  1194420076) } },
    { { -INT32_C(  1615106980), -INT32_C(   211954331) },
      {  INT32_C(  1439482496),  INT32_C(   646749913) },
      { -INT32_C(   898126116), -INT32_C(   707703876) } },
    { {  INT32_C(   960029159),  INT32_C(   749382659) },
      {  INT32_C(  1079641467),  INT32_C(   453579966) },
      {  INT32_C(  2036524188),  INT32_C(   933476541) } },
    { { -INT32_C(   440744832),  INT32_C(   433592217) },
      { -INT32_C(  1284594214),  INT32_C(   735705923) },
      {  INT32_C(  1456759130),  INT32_C(   838986970) } },
    { { -INT32_C(   547089700),  INT32_C(   957025982) },
      { -INT32_C(   763730668), -INT32_C(    85097607) },
      {  INT32_C(   220100552), -INT32_C(  1008300601) } },
    { { -INT32_C(   505436344), -INT32_C(  1711556417) },
      { -INT32_C(  1605605027),  INT32_C(  1103832420) },
      {  INT32_C(  1100205589), -INT32_C(   667902501) } },
    { { -INT32_C(   165662921),  INT32_C(  1378823230) },
      {  INT32_C(   186952081),  INT32_C(  1963266605) },
      { -INT32_C(    50035034),  INT32_C(   657079827) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_veor_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_veor_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 4828891895394799279) },
      { -INT64_C(  978485463844695772) },
      {  INT64_C( 5663255367859937397) } },
    { { -INT64_C( 2340679889570635955) },
      {  INT64_C( 3561912863977746482) },
      { -INT64_C( 1231091376201633921) } },
    { {  INT64_C( 2416474760244209765) },
      {  INT64_C( 3960126324202680667) },
      {  INT64_C( 1692292520539298110) } },
    { { -INT64_C( 6847313742192954864) },
      {  INT64_C( 2033041761997308452) },
      { -INT64_C( 4841469826250411980) } },
    { { -INT64_C( 6226382278488406919) },
      { -INT64_C( 7006577862129197661) },
      {  INT64_C( 3987041097380862426) } },
    { {  INT64_C( 5540466748793861076) },
      { -INT64_C( 8086909024474151181) },
      { -INT64_C( 4384757599176100569) } },
    { { -INT64_C( 4268396355849441589) },
      { -INT64_C( 1863060805330571271) },
      {  INT64_C( 2514847184329163058) } },
    { { -INT64_C( 9134975086147019321) },
      { -INT64_C( 2379888436905800878) },
      {  INT64_C( 6900355332590163605) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_veor_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_veor_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(158), UINT8_C(246), UINT8_C(  5), UINT8_C(215), UINT8_C( 79), UINT8_C( 59), UINT8_C( 70), UINT8_C( 65) },
      { UINT8_C(121), UINT8_C( 69), UINT8_C( 69), UINT8_C(120), UINT8_C( 84), UINT8_C(102), UINT8_C( 65), UINT8_C( 73) },
      { UINT8_C(231), UINT8_C(179), UINT8_C( 64), UINT8_C(175), UINT8_C( 27), UINT8_C( 93), UINT8_C(  7), UINT8_C(  8) } },
    { { UINT8_C(124), UINT8_C( 81), UINT8_C( 15), UINT8_C(239), UINT8_C(130), UINT8_C(246), UINT8_C( 22), UINT8_C( 98) },
      { UINT8_C(136), UINT8_C(214), UINT8_C(239), UINT8_C(250), UINT8_C(198), UINT8_C( 97), UINT8_C( 56), UINT8_C(100) },
      { UINT8_C(244), UINT8_C(135), UINT8_C(224), UINT8_C( 21), UINT8_C( 68), UINT8_C(151), UINT8_C( 46), UINT8_C(  6) } },
    { { UINT8_C( 87), UINT8_C( 62), UINT8_C( 60), UINT8_C(166), UINT8_C(121), UINT8_C(130), UINT8_C(232), UINT8_C(242) },
      { UINT8_C(199), UINT8_C( 45), UINT8_C(106), UINT8_C( 27), UINT8_C(147), UINT8_C(171), UINT8_C(101), UINT8_C( 15) },
      { UINT8_C(144), UINT8_C( 19), UINT8_C( 86), UINT8_C(189), UINT8_C(234), UINT8_C( 41), UINT8_C(141), UINT8_C(253) } },
    { { UINT8_C(253), UINT8_C(116),    UINT8_MAX, UINT8_C(127), UINT8_C(106), UINT8_C( 21), UINT8_C(225), UINT8_C(243) },
      { UINT8_C(235), UINT8_C(208), UINT8_C(237), UINT8_C(178), UINT8_C( 50), UINT8_C( 37), UINT8_C( 22), UINT8_C(137) },
      { UINT8_C( 22), UINT8_C(164), UINT8_C( 18), UINT8_C(205), UINT8_C( 88), UINT8_C( 48), UINT8_C(247), UINT8_C(122) } },
    { { UINT8_C( 99), UINT8_C( 82), UINT8_C( 48), UINT8_C(220), UINT8_C(212), UINT8_C( 24), UINT8_C(207), UINT8_C(156) },
      { UINT8_C( 69), UINT8_C( 57), UINT8_C(183), UINT8_C(216), UINT8_C(229), UINT8_C( 28), UINT8_C(232), UINT8_C(226) },
      { UINT8_C( 38), UINT8_C(107), UINT8_C(135), UINT8_C(  4), UINT8_C( 49), UINT8_C(  4), UINT8_C( 39), UINT8_C(126) } },
    { { UINT8_C(145), UINT8_C(231), UINT8_C( 97), UINT8_C(251), UINT8_C(252), UINT8_C( 66), UINT8_C(238), UINT8_C(231) },
      { UINT8_C( 19), UINT8_C(219), UINT8_C(153), UINT8_C( 69), UINT8_C(  1), UINT8_C(176), UINT8_C(206), UINT8_C(100) },
      { UINT8_C(130), UINT8_C( 60), UINT8_C(248), UINT8_C(190), UINT8_C(253), UINT8_C(242), UINT8_C( 32), UINT8_C(131) } },
    { { UINT8_C(  2), UINT8_C(254), UINT8_C( 65), UINT8_C(215), UINT8_C( 22), UINT8_C( 16), UINT8_C(115), UINT8_C( 91) },
      { UINT8_C( 73), UINT8_C( 42), UINT8_C( 52), UINT8_C( 46), UINT8_C( 71), UINT8_C( 28), UINT8_C( 16), UINT8_C(216) },
      { UINT8_C( 75), UINT8_C(212), UINT8_C(117), UINT8_C(249), UINT8_C( 81), UINT8_C( 12), UINT8_C( 99), UINT8_C(131) } },
    { { UINT8_C(  3), UINT8_C(113), UINT8_C(211),    UINT8_MAX, UINT8_C(180), UINT8_C(194), UINT8_C(230), UINT8_C(199) },
      { UINT8_C(157), UINT8_C(128), UINT8_C( 12), UINT8_C(158), UINT8_C( 48), UINT8_C(218), UINT8_C(  3), UINT8_C( 50) },
      { UINT8_C(158), UINT8_C(241), UINT8_C(223), UINT8_C( 97), UINT8_C(132), UINT8_C( 24), UINT8_C(229), UINT8_C(245) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_veor_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_veor_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
     { { UINT16_C(44341), UINT16_C(23492), UINT16_C(26475), UINT16_C(49752) },
      { UINT16_C( 6246), UINT16_C( 3973), UINT16_C(21664), UINT16_C(43892) },
      { UINT16_C(46419), UINT16_C(21569), UINT16_C(13259), UINT16_C(26924) } },
    { { UINT16_C(18060), UINT16_C(35603), UINT16_C(17216), UINT16_C(50117) },
      { UINT16_C(54080), UINT16_C(21475), UINT16_C( 1737), UINT16_C(65206) },
      { UINT16_C(38348), UINT16_C(55536), UINT16_C(17801), UINT16_C(15731) } },
    { { UINT16_C(31412), UINT16_C( 8025), UINT16_C(45793), UINT16_C(18657) },
      { UINT16_C(26314), UINT16_C(27223), UINT16_C(52155), UINT16_C(18198) },
      { UINT16_C( 7294), UINT16_C(29966), UINT16_C(31066), UINT16_C( 4087) } },
    { { UINT16_C(10513), UINT16_C(21202), UINT16_C(38764), UINT16_C(44053) },
      { UINT16_C(63594), UINT16_C(13312), UINT16_C(46847), UINT16_C(45874) },
      { UINT16_C(53627), UINT16_C(26322), UINT16_C( 8595), UINT16_C( 7975) } },
    { { UINT16_C(35889), UINT16_C( 4818), UINT16_C(46142), UINT16_C( 2138) },
      { UINT16_C(45338), UINT16_C(54643), UINT16_C(35196), UINT16_C(36381) },
      { UINT16_C(15659), UINT16_C(51105), UINT16_C(15682), UINT16_C(34375) } },
    { { UINT16_C(61362), UINT16_C( 7904), UINT16_C(62855), UINT16_C(61898) },
      { UINT16_C(51950), UINT16_C(60709), UINT16_C(22657), UINT16_C(45728) },
      { UINT16_C( 9564), UINT16_C(62405), UINT16_C(44294), UINT16_C(17258) } },
    { { UINT16_C(29412), UINT16_C( 8900), UINT16_C( 7974), UINT16_C(16682) },
      { UINT16_C(40400), UINT16_C(19734), UINT16_C(13094), UINT16_C(55515) },
      { UINT16_C(61236), UINT16_C(28626), UINT16_C(11264), UINT16_C(39409) } },
    { { UINT16_C(47907), UINT16_C(43766), UINT16_C(49584), UINT16_C(40603) },
      { UINT16_C(49547), UINT16_C( 3211), UINT16_C(11033), UINT16_C(64958) },
      { UINT16_C(31400), UINT16_C(42621), UINT16_C(60073), UINT16_C(25381) } },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_veor_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_veor_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 475910642), UINT32_C(2198092259) },
      { UINT32_C(1779073253), UINT32_C( 710440248) },
      { UINT32_C(1985433879), UINT32_C(2841398491) } },
    { { UINT32_C(2529940306), UINT32_C(1981044553) },
      { UINT32_C(4205813484), UINT32_C( 565923630) },
      { UINT32_C(1818512830), UINT32_C(1471092839) } },
    { { UINT32_C(  54335520), UINT32_C( 914833745) },
      { UINT32_C(4204827074), UINT32_C(1478818054) },
      { UINT32_C(4187851234), UINT32_C(1856223319) } },
    { { UINT32_C( 384823244), UINT32_C( 864813894) },
      { UINT32_C(3492625314), UINT32_C(2884757642) },
      { UINT32_C(3334657134), UINT32_C(2558389196) } },
    { { UINT32_C(1387146752), UINT32_C( 847787376) },
      { UINT32_C(3442223558), UINT32_C(3995423010) },
      { UINT32_C(2676099014), UINT32_C(3702350930) } },
    { { UINT32_C(2265191488), UINT32_C(3132789016) },
      { UINT32_C(1468721100), UINT32_C(3473046735) },
      { UINT32_C(3499029388), UINT32_C(1975053783) } },
    { { UINT32_C( 438415530), UINT32_C(2890705638) },
      { UINT32_C(4118378963), UINT32_C( 182689738) },
      { UINT32_C(4015573369), UINT32_C(2796500268) } },
    { { UINT32_C(3415337139), UINT32_C(1166363513) },
      { UINT32_C(  27004978), UINT32_C( 919707276) },
      { UINT32_C(3389913217), UINT32_C(1934939637) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_veor_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_veor_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
     { { UINT64_C(12398498631144494080) },
      { UINT64_C(12830720206572806384) },
      { UINT64_C( 2170648006984611056) } },
    { { UINT64_C(14503918927718196209) },
      { UINT64_C(11943777821855590383) },
      { UINT64_C( 7820667666536924190) } },
    { { UINT64_C( 9809779626162407590) },
      { UINT64_C( 2879441961520354615) },
      { UINT64_C(12670459381603638673) } },
    { { UINT64_C(16081757167494409208) },
      { UINT64_C(10038957759141646855) },
      { UINT64_C( 6087857433790822911) } },
    { { UINT64_C( 2734570005143328978) },
      { UINT64_C( 9788114807057594746) },
      { UINT64_C(11683879364330070440) } },
    { { UINT64_C( 6186002290649558537) },
      { UINT64_C(   43438603698807594) },
      { UINT64_C( 6143837196495015203) } },
    { { UINT64_C( 4251220755635477483) },
      { UINT64_C(14856461225913050903) },
      { UINT64_C(17641617911741349116) } },
    { { UINT64_C( 6544470438163519278) },
      { UINT64_C( 1329409782962574404) },
      { UINT64_C( 5233642461911434090) } },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_veor_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_veor_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veorq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
     { {  INT8_C(   7),  INT8_C(  33), -INT8_C(  55), -INT8_C(  62), -INT8_C(  87),  INT8_C(  96), -INT8_C(  63), -INT8_C( 107),
        -INT8_C( 112), -INT8_C( 109),  INT8_C(  45),  INT8_C(  65),  INT8_C(  62),  INT8_C(   1), -INT8_C(  77),  INT8_C(  15) },
      {  INT8_C( 105), -INT8_C(  96), -INT8_C(  51),  INT8_C(  40), -INT8_C(  44),  INT8_C( 104),  INT8_C(  89),  INT8_C(  64),
         INT8_C( 119), -INT8_C(  33),  INT8_C(  15), -INT8_C(  57), -INT8_C( 109), -INT8_C(  96), -INT8_C(  73), -INT8_C( 101) },
      {  INT8_C( 110), -INT8_C( 127),  INT8_C(   4), -INT8_C(  22),  INT8_C( 125),  INT8_C(   8), -INT8_C( 104), -INT8_C(  43),
        -INT8_C(  25),  INT8_C(  76),  INT8_C(  34), -INT8_C( 122), -INT8_C(  83), -INT8_C(  95),  INT8_C(   4), -INT8_C( 108) } },
    { { -INT8_C(  63),      INT8_MIN,  INT8_C(  93),  INT8_C( 106), -INT8_C(  31),  INT8_C(  30), -INT8_C(   1),  INT8_C( 113),
        -INT8_C(  78),  INT8_C(  45), -INT8_C(  78), -INT8_C(  16),  INT8_C(  46),  INT8_C( 101), -INT8_C(   1), -INT8_C( 105) },
      {  INT8_C(   5), -INT8_C(  51), -INT8_C(  65), -INT8_C(  38),  INT8_C(  53),  INT8_C(  24),  INT8_C(  26), -INT8_C(  84),
        -INT8_C(   8),  INT8_C(  42),  INT8_C( 115), -INT8_C( 117), -INT8_C(  54),  INT8_C(  43),  INT8_C(  38), -INT8_C( 117) },
      { -INT8_C(  60),  INT8_C(  77), -INT8_C(  30), -INT8_C(  80), -INT8_C(  44),  INT8_C(   6), -INT8_C(  27), -INT8_C(  35),
         INT8_C(  74),  INT8_C(   7), -INT8_C(  63),  INT8_C( 123), -INT8_C(  28),  INT8_C(  78), -INT8_C(  39),  INT8_C(  28) } },
    { { -INT8_C(  85), -INT8_C( 124), -INT8_C(  10), -INT8_C( 116), -INT8_C(  94), -INT8_C(  11), -INT8_C(   2),  INT8_C(  84),
         INT8_C(  34), -INT8_C(  80),  INT8_C(  68),  INT8_C(  80),  INT8_C(  22),  INT8_C(  68), -INT8_C(  25),  INT8_C(  27) },
      {  INT8_C(  17), -INT8_C(  90), -INT8_C(  11),  INT8_C(  70), -INT8_C(  65),  INT8_C(  16), -INT8_C(  14), -INT8_C(  73),
         INT8_C(  58),  INT8_C( 101),  INT8_C(  66),  INT8_C(   4), -INT8_C( 112),  INT8_C( 105), -INT8_C( 113),  INT8_C(  60) },
      { -INT8_C(  70),  INT8_C(  34),  INT8_C(   3), -INT8_C(  54),  INT8_C(  29), -INT8_C(  27),  INT8_C(  12), -INT8_C(  29),
         INT8_C(  24), -INT8_C(  43),  INT8_C(   6),  INT8_C(  84), -INT8_C( 122),  INT8_C(  45),  INT8_C( 104),  INT8_C(  39) } },
    { { -INT8_C(  19), -INT8_C( 123), -INT8_C(  56), -INT8_C( 113),  INT8_C( 123), -INT8_C(  58), -INT8_C(  28), -INT8_C(  99),
         INT8_C( 119),  INT8_C(  40), -INT8_C(  18), -INT8_C( 115),  INT8_C( 108), -INT8_C(  43), -INT8_C(  88),  INT8_C( 125) },
      {  INT8_C( 124), -INT8_C(  98), -INT8_C(  61),  INT8_C(  59), -INT8_C(  82), -INT8_C(  75), -INT8_C(  14), -INT8_C(  24),
         INT8_C(  27),  INT8_C(  52), -INT8_C(  20), -INT8_C(  85), -INT8_C(  99),  INT8_C( 123), -INT8_C(  25), -INT8_C( 118) },
      { -INT8_C( 111),  INT8_C(  27),  INT8_C(  11), -INT8_C(  76), -INT8_C(  43),  INT8_C( 115),  INT8_C(  22),  INT8_C( 117),
         INT8_C( 108),  INT8_C(  28),  INT8_C(   2),  INT8_C(  38), -INT8_C(  15), -INT8_C(  82),  INT8_C(  79), -INT8_C(   9) } },
    { {  INT8_C(   1), -INT8_C(  80),  INT8_C(  26),  INT8_C( 124),  INT8_C( 118), -INT8_C(   2),  INT8_C(  25), -INT8_C(  19),
         INT8_C(  38),  INT8_C(   7),  INT8_C( 122), -INT8_C( 109), -INT8_C(  35),  INT8_C(  35),  INT8_C(  16),  INT8_C(  89) },
      { -INT8_C(  63), -INT8_C(  44), -INT8_C( 108),  INT8_C( 111), -INT8_C( 119), -INT8_C( 122),  INT8_C(  87), -INT8_C(  92),
        -INT8_C(  70),  INT8_C(  67),  INT8_C(  80),  INT8_C(  88), -INT8_C(  66),  INT8_C(  55), -INT8_C(  30), -INT8_C(  65) },
      { -INT8_C(  64),  INT8_C( 100), -INT8_C( 114),  INT8_C(  19), -INT8_C(   1),  INT8_C( 120),  INT8_C(  78),  INT8_C(  73),
        -INT8_C( 100),  INT8_C(  68),  INT8_C(  42), -INT8_C(  53),  INT8_C(  99),  INT8_C(  20), -INT8_C(  14), -INT8_C(  26) } },
    { { -INT8_C(  25), -INT8_C(   4),  INT8_C(  59),  INT8_C(  94), -INT8_C(   6),  INT8_C(  85),  INT8_C(  75),  INT8_C(  33),
         INT8_C(  92), -INT8_C(  58), -INT8_C(  76),  INT8_C(  57), -INT8_C(  23), -INT8_C(  60), -INT8_C( 110), -INT8_C(  86) },
      { -INT8_C( 104),  INT8_C(  38),  INT8_C(  25),  INT8_C(  34), -INT8_C(  84),  INT8_C( 112), -INT8_C(  58),  INT8_C( 103),
        -INT8_C(  77),  INT8_C(  22), -INT8_C(  65),  INT8_C( 113),  INT8_C(  78), -INT8_C(  95),  INT8_C(  49),  INT8_C(  53) },
      {      INT8_MAX, -INT8_C(  38),  INT8_C(  34),  INT8_C( 124),  INT8_C(  86),  INT8_C(  37), -INT8_C( 115),  INT8_C(  70),
        -INT8_C(  17), -INT8_C(  48),  INT8_C(  11),  INT8_C(  72), -INT8_C(  89),  INT8_C( 101), -INT8_C(  93), -INT8_C(  97) } },
    { { -INT8_C(  98),  INT8_C( 108), -INT8_C( 109), -INT8_C( 104), -INT8_C(  63), -INT8_C(  33), -INT8_C(  71),  INT8_C(  30),
        -INT8_C(  91),  INT8_C( 109),  INT8_C(  87), -INT8_C( 114),  INT8_C(  50), -INT8_C(  22),  INT8_C(  56), -INT8_C(  54) },
      {  INT8_C(  16),  INT8_C(  81), -INT8_C(  20), -INT8_C(  67), -INT8_C(  63), -INT8_C(  77),  INT8_C(  36),  INT8_C( 116),
        -INT8_C(  55), -INT8_C(  29), -INT8_C(  27),  INT8_C(  23), -INT8_C( 124),  INT8_C(  22),  INT8_C(  77),  INT8_C(  34) },
      { -INT8_C( 114),  INT8_C(  61),      INT8_MAX,  INT8_C(  37),  INT8_C(   0),  INT8_C( 108), -INT8_C(  99),  INT8_C( 106),
         INT8_C( 108), -INT8_C( 114), -INT8_C(  78), -INT8_C( 103), -INT8_C(  74), -INT8_C(   4),  INT8_C( 117), -INT8_C(  24) } },
    { { -INT8_C( 125), -INT8_C(  32), -INT8_C(  69),  INT8_C(  68), -INT8_C(  65),  INT8_C( 116),  INT8_C(  98),  INT8_C( 100),
        -INT8_C(  30), -INT8_C(  70), -INT8_C(  14),  INT8_C(  20), -INT8_C(  92),  INT8_C(  42), -INT8_C(  34), -INT8_C(  76) },
      {  INT8_C( 123), -INT8_C(  53),  INT8_C( 113),  INT8_C(  60),  INT8_C( 126), -INT8_C( 107), -INT8_C(  80),  INT8_C(  71),
         INT8_C( 120), -INT8_C( 106),  INT8_C(  95), -INT8_C(   3), -INT8_C(  84), -INT8_C(  84),  INT8_C(  31),  INT8_C(  47) },
      { -INT8_C(   8),  INT8_C(  43), -INT8_C(  54),  INT8_C( 120), -INT8_C(  63), -INT8_C(  31), -INT8_C(  46),  INT8_C(  35),
        -INT8_C( 102),  INT8_C(  44), -INT8_C(  83), -INT8_C(  23),  INT8_C(   8), -INT8_C( 122), -INT8_C(  63), -INT8_C( 101) } },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_veorq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_veorq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veorq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 22070), -INT16_C( 27902),  INT16_C( 20197), -INT16_C(  6856),  INT16_C( 29980), -INT16_C( 23942), -INT16_C( 27791),  INT16_C(  8437) },
      { -INT16_C( 27754),  INT16_C(  5134), -INT16_C(  9605),  INT16_C( 10935), -INT16_C(  4606),  INT16_C(  3542),  INT16_C( 29604),  INT16_C( 28643) },
      {  INT16_C( 14940), -INT16_C( 30964), -INT16_C( 27490), -INT16_C( 12401), -INT16_C( 25826), -INT16_C( 20564), -INT16_C(  7979),  INT16_C( 20246) } },
    { { -INT16_C(  6884),  INT16_C(   514),  INT16_C( 14900),  INT16_C( 20711),  INT16_C( 25007),  INT16_C(  8690), -INT16_C(  6156), -INT16_C( 30143) },
      {  INT16_C( 20346), -INT16_C(  2657),  INT16_C( 22057),  INT16_C( 11039), -INT16_C(  2748), -INT16_C(  5832),  INT16_C(  7016), -INT16_C( 31400) },
      { -INT16_C( 21914), -INT16_C(  2147),  INT16_C( 27677),  INT16_C( 31736), -INT16_C( 27413), -INT16_C( 14134), -INT16_C(   868),  INT16_C(  3865) } },
    { {  INT16_C( 23041),  INT16_C( 13703),  INT16_C( 28309),  INT16_C( 17541),  INT16_C( 30671), -INT16_C( 15515), -INT16_C( 22946), -INT16_C( 10163) },
      { -INT16_C(  4874),  INT16_C(  8141), -INT16_C(  4797), -INT16_C( 30901), -INT16_C( 31774),  INT16_C( 19312), -INT16_C( 14177), -INT16_C( 24368) },
      { -INT16_C( 18697),  INT16_C( 10826), -INT16_C( 31786), -INT16_C( 15410), -INT16_C(  3027), -INT16_C( 30699),  INT16_C( 28353),  INT16_C( 30877) } },
    { {  INT16_C( 22307), -INT16_C( 18219),  INT16_C( 23237), -INT16_C( 27396),  INT16_C( 25297),  INT16_C( 12119), -INT16_C( 23544), -INT16_C(   505) },
      { -INT16_C( 11119), -INT16_C( 11234),  INT16_C( 27073), -INT16_C( 23461), -INT16_C( 13076), -INT16_C( 29713), -INT16_C( 16492), -INT16_C( 18645) },
      { -INT16_C( 31822),  INT16_C( 27851),  INT16_C( 13060),  INT16_C( 12455), -INT16_C( 20931), -INT16_C( 23368),  INT16_C(  7068),  INT16_C( 18732) } },
    { {  INT16_C(    22), -INT16_C(  9361),  INT16_C( 27738),  INT16_C( 11119), -INT16_C( 14642), -INT16_C( 10662),  INT16_C( 24938), -INT16_C(  1067) },
      { -INT16_C(  3274), -INT16_C(  2097),  INT16_C( 11100),  INT16_C( 18587), -INT16_C( 29961), -INT16_C( 29740), -INT16_C(   183),  INT16_C( 24387) },
      { -INT16_C(  3296),  INT16_C( 11424),  INT16_C( 18182),  INT16_C( 25588),  INT16_C( 19513),  INT16_C( 23950), -INT16_C( 25053), -INT16_C( 23402) } },
    { { -INT16_C( 19968),  INT16_C( 23098), -INT16_C( 22242), -INT16_C(  4986), -INT16_C(  8081), -INT16_C(  9533), -INT16_C( 26558),  INT16_C( 30933) },
      { -INT16_C( 23157), -INT16_C(  6289),  INT16_C(  3024), -INT16_C( 14545),  INT16_C(   917), -INT16_C(  8366), -INT16_C( 27389),  INT16_C(   830) },
      {  INT16_C(  6027), -INT16_C( 17067), -INT16_C( 23858),  INT16_C( 11177), -INT16_C(  7174),  INT16_C(  1425),  INT16_C(  3393),  INT16_C( 31723) } },
    { {  INT16_C( 31048),  INT16_C( 26205), -INT16_C(  7390), -INT16_C( 28077),  INT16_C(  5828),  INT16_C(  1644),  INT16_C( 16814),  INT16_C( 14718) },
      { -INT16_C(  4634), -INT16_C( 18912),  INT16_C( 20472), -INT16_C( 29059), -INT16_C( 12205),  INT16_C( 22125), -INT16_C( 21659), -INT16_C( 21159) },
      { -INT16_C( 27474), -INT16_C( 12163), -INT16_C( 21286),  INT16_C(  7214), -INT16_C( 14697),  INT16_C( 20481), -INT16_C(  5429), -INT16_C( 27609) } },
    { { -INT16_C( 18908),  INT16_C( 18196),  INT16_C( 26522),  INT16_C( 24281),  INT16_C( 17789),  INT16_C( 11108), -INT16_C(  7546),  INT16_C( 28004) },
      { -INT16_C( 31537), -INT16_C( 14301), -INT16_C( 24109),  INT16_C(  9814), -INT16_C( 15503), -INT16_C( 10628), -INT16_C( 10898), -INT16_C( 27772) },
      {  INT16_C( 13035), -INT16_C( 28873), -INT16_C( 14775),  INT16_C( 30863), -INT16_C( 31220), -INT16_C(   744),  INT16_C( 14312), -INT16_C(   288) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_veorq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_veorq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veorq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  2023602252), -INT32_C(  1635477608),  INT32_C(  1571456524), -INT32_C(  1631778536) },
      { -INT32_C(   771340562), -INT32_C(  1375991329), -INT32_C(  1944584857),  INT32_C(   248442050) },
      { -INT32_C(  1432617310),  INT32_C(   863542855), -INT32_C(   776111253), -INT32_C(  1871452710) } },
    { {  INT32_C(  1032219556),  INT32_C(   266013443), -INT32_C(  1452505711),  INT32_C(  2085038734) },
      {  INT32_C(  1330531952), -INT32_C(  1090762153),  INT32_C(   172692296), -INT32_C(  1541924353) },
      {  INT32_C(  1925719508), -INT32_C(  1322827436), -INT32_C(  1557686567), -INT32_C(   664849551) } },
    { { -INT32_C(  1998479739),  INT32_C(   983022761), -INT32_C(   790428863), -INT32_C(  1655952595) },
      { -INT32_C(   789800071),  INT32_C(   764406245), -INT32_C(    63448324),  INT32_C(  2023772147) },
      {  INT32_C(  1477248508),  INT32_C(   387470668),  INT32_C(   752146877), -INT32_C(   437492514) } },
    { { -INT32_C(  1761574418),  INT32_C(  2127730493), -INT32_C(   934365797),  INT32_C(  1499896800) },
      {  INT32_C(   455758390),  INT32_C(   944355643), -INT32_C(  2043379565), -INT32_C(  1090530096) },
      { -INT32_C(  1943350312),  INT32_C(  1184574982),  INT32_C(  1316631816), -INT32_C(   409383120) } },
    { { -INT32_C(  1839857835),  INT32_C(   839919511), -INT32_C(  1107664931),  INT32_C(   806838522) },
      { -INT32_C(   297057869), -INT32_C(  1926851334), -INT32_C(   451716587), -INT32_C(  2086464978) },
      {  INT32_C(  2082389734), -INT32_C(  1086934163),  INT32_C(  1491666376), -INT32_C(  1280019756) } },
    { { -INT32_C(  1458178030), -INT32_C(    35969504),  INT32_C(  2142950789), -INT32_C(   374353610) },
      {  INT32_C(   215480850), -INT32_C(  1533411697), -INT32_C(  2021020328), -INT32_C(   787862337) },
      { -INT32_C(  1514012160),  INT32_C(  1497553071), -INT32_C(   130844451),  INT32_C(   950402441) } },
    { {  INT32_C(  1148854308), -INT32_C(   884910778),  INT32_C(  1632304171), -INT32_C(   531957299) },
      { -INT32_C(  2098454029),  INT32_C(  2015790623), -INT32_C(   218124493),  INT32_C(    12847579) },
      { -INT32_C(   963247657), -INT32_C(  1285041319), -INT32_C(  1816833256), -INT32_C(   527503338) } },
    { {  INT32_C(  1866743337), -INT32_C(  1086683500),  INT32_C(  1327531138),  INT32_C(  1898932861) },
      { -INT32_C(  1410130805), -INT32_C(   719119710), -INT32_C(  1513676087),  INT32_C(  1436912427) },
      { -INT32_C(   994631006),  INT32_C(  1780063286), -INT32_C(   353917365),  INT32_C(   613081430) } },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_veorq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_veorq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veorq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 7838966427958002848), -INT64_C( 8261242307613928860) },
      { -INT64_C( 7431965701611751289), -INT64_C( 7407344992410839652) },
      { -INT64_C(  858567960746443737),  INT64_C( 1470980658505123832) } },
    { { -INT64_C( 2886416538353870570), -INT64_C( 2150656445132361547) },
      { -INT64_C( 6271031530521972019),  INT64_C( 8555292687707573543) },
      {  INT64_C( 9154042880290745307), -INT64_C( 7737795467991990894) } },
    { {  INT64_C( 7829206375937561691), -INT64_C( 4369848476834029283) },
      {  INT64_C( 5445726219798794719), -INT64_C( 4720293152652729688) },
      {  INT64_C( 2825435453100393860),  INT64_C( 9017626565343331253) } },
    { { -INT64_C( 8962951169386382982), -INT64_C( 5796880591085591596) },
      {  INT64_C( 8365487760686624936),  INT64_C( 2608422744189862928) },
      { -INT64_C(  611049541326091822), -INT64_C( 8376786039276034108) } },
    { { -INT64_C( 4152896156506669197),  INT64_C( 6419350962335406486) },
      { -INT64_C( 1293309491724046130), -INT64_C(  608104132508481087) },
      {  INT64_C( 2905049548670898109), -INT64_C( 5865506187303006121) } },
    { {  INT64_C( 7857425477002191955), -INT64_C( 8749955623567516792) },
      { -INT64_C( 5303219508194789478), -INT64_C( 5750620235210045001) },
      { -INT64_C( 2635728232020618295),  INT64_C( 3936243814942003775) } },
    { { -INT64_C( 5055008894465277291),  INT64_C( 3520270740420144539) },
      { -INT64_C( 2385764142126859718),  INT64_C( 5541198542273054425) },
      {  INT64_C( 7439119847274641583),  INT64_C( 8952251304586554178) } },
    { {  INT64_C( 8518438691616185165), -INT64_C( 1943686230725547969) },
      { -INT64_C( 7447835856211759203),  INT64_C( 6053598794347363582) },
      { -INT64_C( 1255261415251544880), -INT64_C( 5691397999926209343) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_veorq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_veorq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veorq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(163), UINT8_C(170), UINT8_C(155), UINT8_C(223), UINT8_C(123), UINT8_C( 66), UINT8_C( 74), UINT8_C(148),
        UINT8_C(241), UINT8_C(216), UINT8_C(221), UINT8_C( 81), UINT8_C(250), UINT8_C(209), UINT8_C(216), UINT8_C(238) },
      { UINT8_C(131), UINT8_C(191), UINT8_C(180), UINT8_C( 39), UINT8_C(251), UINT8_C(201), UINT8_C(227), UINT8_C(246),
        UINT8_C( 77), UINT8_C(182), UINT8_C(108), UINT8_C( 73), UINT8_C(249), UINT8_C(179), UINT8_C(147), UINT8_C(156) },
      { UINT8_C( 32), UINT8_C( 21), UINT8_C( 47), UINT8_C(248), UINT8_C(128), UINT8_C(139), UINT8_C(169), UINT8_C( 98),
        UINT8_C(188), UINT8_C(110), UINT8_C(177), UINT8_C( 24), UINT8_C(  3), UINT8_C( 98), UINT8_C( 75), UINT8_C(114) } },
    { { UINT8_C( 93), UINT8_C( 46), UINT8_C(124), UINT8_C(217), UINT8_C(112), UINT8_C(198), UINT8_C(109), UINT8_C( 98),
        UINT8_C(159), UINT8_C( 74), UINT8_C(179), UINT8_C(153), UINT8_C( 27), UINT8_C(139), UINT8_C(135), UINT8_C(159) },
      { UINT8_C( 75), UINT8_C( 60), UINT8_C(198), UINT8_C( 70), UINT8_C(  5), UINT8_C(169), UINT8_C( 60), UINT8_C( 82),
        UINT8_C( 95), UINT8_C(168), UINT8_C(156), UINT8_C( 89), UINT8_C( 92), UINT8_C( 47), UINT8_C(245), UINT8_C(185) },
      { UINT8_C( 22), UINT8_C( 18), UINT8_C(186), UINT8_C(159), UINT8_C(117), UINT8_C(111), UINT8_C( 81), UINT8_C( 48),
        UINT8_C(192), UINT8_C(226), UINT8_C( 47), UINT8_C(192), UINT8_C( 71), UINT8_C(164), UINT8_C(114), UINT8_C( 38) } },
    { { UINT8_C( 93), UINT8_C(113), UINT8_C(146), UINT8_C(205), UINT8_C( 56),    UINT8_MAX, UINT8_C( 47), UINT8_C(215),
        UINT8_C( 73), UINT8_C(226), UINT8_C(112), UINT8_C(101), UINT8_C(110), UINT8_C(248), UINT8_C(  4), UINT8_C(185) },
      { UINT8_C( 52), UINT8_C(202),    UINT8_MAX, UINT8_C( 57), UINT8_C(116), UINT8_C( 59), UINT8_C(140), UINT8_C(211),
        UINT8_C(228), UINT8_C( 40), UINT8_C( 44), UINT8_C( 64), UINT8_C( 87), UINT8_C( 34), UINT8_C(249), UINT8_C(180) },
      { UINT8_C(105), UINT8_C(187), UINT8_C(109), UINT8_C(244), UINT8_C( 76), UINT8_C(196), UINT8_C(163), UINT8_C(  4),
        UINT8_C(173), UINT8_C(202), UINT8_C( 92), UINT8_C( 37), UINT8_C( 57), UINT8_C(218), UINT8_C(253), UINT8_C( 13) } },
    { { UINT8_C(147), UINT8_C(140), UINT8_C(129), UINT8_C(203), UINT8_C(139), UINT8_C(177), UINT8_C(162), UINT8_C(213),
        UINT8_C(147), UINT8_C( 19), UINT8_C( 58), UINT8_C(  1), UINT8_C( 11), UINT8_C( 62), UINT8_C(186), UINT8_C( 63) },
      { UINT8_C(  8), UINT8_C(185), UINT8_C(120), UINT8_C(124), UINT8_C(245), UINT8_C(  4), UINT8_C( 80), UINT8_C(217),
        UINT8_C( 44), UINT8_C(124), UINT8_C( 25), UINT8_C(131), UINT8_C(158), UINT8_C( 18), UINT8_C( 55), UINT8_C( 50) },
      { UINT8_C(155), UINT8_C( 53), UINT8_C(249), UINT8_C(183), UINT8_C(126), UINT8_C(181), UINT8_C(242), UINT8_C( 12),
        UINT8_C(191), UINT8_C(111), UINT8_C( 35), UINT8_C(130), UINT8_C(149), UINT8_C( 44), UINT8_C(141), UINT8_C( 13) } },
    { { UINT8_C(158), UINT8_C(185), UINT8_C(253), UINT8_C( 42), UINT8_C(106), UINT8_C(160),    UINT8_MAX, UINT8_C(253),
        UINT8_C(179), UINT8_C( 57),    UINT8_MAX, UINT8_C(190), UINT8_C(119), UINT8_C(185), UINT8_C(253), UINT8_C(127) },
      { UINT8_C(115), UINT8_C(117), UINT8_C(252), UINT8_C(104), UINT8_C(122), UINT8_C( 76), UINT8_C( 65), UINT8_C(166),
        UINT8_C(200), UINT8_C( 90), UINT8_C( 42), UINT8_C(103), UINT8_C(108), UINT8_C( 97), UINT8_C(153), UINT8_C( 11) },
      { UINT8_C(237), UINT8_C(204), UINT8_C(  1), UINT8_C( 66), UINT8_C( 16), UINT8_C(236), UINT8_C(190), UINT8_C( 91),
        UINT8_C(123), UINT8_C( 99), UINT8_C(213), UINT8_C(217), UINT8_C( 27), UINT8_C(216), UINT8_C(100), UINT8_C(116) } },
    { { UINT8_C( 26), UINT8_C(150), UINT8_C( 53), UINT8_C(132), UINT8_C( 54), UINT8_C( 52), UINT8_C(130), UINT8_C(233),
        UINT8_C(109), UINT8_C(129), UINT8_C(167), UINT8_C(228), UINT8_C( 58), UINT8_C(164), UINT8_C( 99), UINT8_C(173) },
      { UINT8_C( 26), UINT8_C( 95), UINT8_C( 21), UINT8_C(148), UINT8_C(171), UINT8_C( 86), UINT8_C( 58), UINT8_C(116),
        UINT8_C(176), UINT8_C(100), UINT8_C(219), UINT8_C( 29), UINT8_C(198), UINT8_C(116), UINT8_C( 40), UINT8_C(224) },
      { UINT8_C(  0), UINT8_C(201), UINT8_C( 32), UINT8_C( 16), UINT8_C(157), UINT8_C( 98), UINT8_C(184), UINT8_C(157),
        UINT8_C(221), UINT8_C(229), UINT8_C(124), UINT8_C(249), UINT8_C(252), UINT8_C(208), UINT8_C( 75), UINT8_C( 77) } },
    { { UINT8_C( 10), UINT8_C( 93), UINT8_C(101), UINT8_C( 65), UINT8_C(145), UINT8_C(231), UINT8_C( 42), UINT8_C(254),
        UINT8_C(104), UINT8_C(210), UINT8_C(226), UINT8_C(162), UINT8_C(118), UINT8_C( 69), UINT8_C( 80), UINT8_C(144) },
      { UINT8_C(165), UINT8_C(101), UINT8_C( 36), UINT8_C( 80), UINT8_C(188), UINT8_C( 95), UINT8_C(196), UINT8_C(108),
        UINT8_C(195), UINT8_C(159), UINT8_C(137), UINT8_C(137), UINT8_C( 19), UINT8_C(177), UINT8_C(106), UINT8_C( 30) },
      { UINT8_C(175), UINT8_C( 56), UINT8_C( 65), UINT8_C( 17), UINT8_C( 45), UINT8_C(184), UINT8_C(238), UINT8_C(146),
        UINT8_C(171), UINT8_C( 77), UINT8_C(107), UINT8_C( 43), UINT8_C(101), UINT8_C(244), UINT8_C( 58), UINT8_C(142) } },
    { { UINT8_C( 14), UINT8_C(207), UINT8_C( 95), UINT8_C(159), UINT8_C(182), UINT8_C(137), UINT8_C(157), UINT8_C( 30),
        UINT8_C( 91), UINT8_C(127), UINT8_C(192), UINT8_C(210), UINT8_C(197), UINT8_C( 16), UINT8_C( 98), UINT8_C(106) },
      { UINT8_C(118), UINT8_C(135), UINT8_C(186), UINT8_C( 50), UINT8_C(230), UINT8_C(127), UINT8_C(158), UINT8_C(169),
        UINT8_C( 30), UINT8_C( 40), UINT8_C( 51), UINT8_C( 50), UINT8_C(217), UINT8_C(157), UINT8_C( 80), UINT8_C(232) },
      { UINT8_C(120), UINT8_C( 72), UINT8_C(229), UINT8_C(173), UINT8_C( 80), UINT8_C(246), UINT8_C(  3), UINT8_C(183),
        UINT8_C( 69), UINT8_C( 87), UINT8_C(243), UINT8_C(224), UINT8_C( 28), UINT8_C(141), UINT8_C( 50), UINT8_C(130) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_veorq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_veorq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veorq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(40817), UINT16_C(53417), UINT16_C(32015), UINT16_C(44806), UINT16_C( 9027), UINT16_C(13174), UINT16_C(64941), UINT16_C(39222) },
      { UINT16_C(48960), UINT16_C(16190), UINT16_C(49883), UINT16_C(20177), UINT16_C(31404), UINT16_C(58163), UINT16_C(36172), UINT16_C(48412) },
      { UINT16_C( 8241), UINT16_C(61335), UINT16_C(49108), UINT16_C(57815), UINT16_C(23023), UINT16_C(53317), UINT16_C(28897), UINT16_C( 9258) } },
    { { UINT16_C(50477), UINT16_C(15501), UINT16_C(37954), UINT16_C(34283), UINT16_C(25015), UINT16_C(26041), UINT16_C(61278), UINT16_C(40958) },
      { UINT16_C(15534), UINT16_C(35294), UINT16_C(45055), UINT16_C(43991), UINT16_C( 2857), UINT16_C(30094), UINT16_C(43672), UINT16_C(50483) },
      { UINT16_C(63875), UINT16_C(46419), UINT16_C(15293), UINT16_C(11836), UINT16_C(27294), UINT16_C( 4151), UINT16_C(17862), UINT16_C(23245) } },
    { { UINT16_C(49264), UINT16_C(45569), UINT16_C(60756), UINT16_C( 3128), UINT16_C(61774), UINT16_C(44401), UINT16_C(28640), UINT16_C(36684) },
      { UINT16_C(10924), UINT16_C(43800), UINT16_C(61657), UINT16_C(  598), UINT16_C(58619), UINT16_C(37751), UINT16_C(43663), UINT16_C(65369) },
      { UINT16_C(60124), UINT16_C( 6425), UINT16_C( 7565), UINT16_C( 3694), UINT16_C( 5557), UINT16_C(15878), UINT16_C(50543), UINT16_C(28693) } },
    { { UINT16_C(23147), UINT16_C(49073), UINT16_C(59719), UINT16_C(38603), UINT16_C(15578), UINT16_C(47939), UINT16_C(36780), UINT16_C(22602) },
      { UINT16_C(25273), UINT16_C(37379), UINT16_C(22866), UINT16_C(19860), UINT16_C( 2877), UINT16_C(52449), UINT16_C(15030), UINT16_C( 8651) },
      { UINT16_C(14546), UINT16_C(11698), UINT16_C(45077), UINT16_C(56159), UINT16_C(14311), UINT16_C(30626), UINT16_C(46362), UINT16_C(31105) } },
    { { UINT16_C(32148), UINT16_C(56544), UINT16_C(44134), UINT16_C(16754), UINT16_C(46568), UINT16_C(38140), UINT16_C(17988), UINT16_C(65004) },
      { UINT16_C(61352), UINT16_C(64399), UINT16_C( 9032), UINT16_C(34376), UINT16_C(10542), UINT16_C(58450), UINT16_C( 7779), UINT16_C(63493) },
      { UINT16_C(37436), UINT16_C(10095), UINT16_C(36654), UINT16_C(51002), UINT16_C(40134), UINT16_C(28846), UINT16_C(22567), UINT16_C( 1513) } },
    { { UINT16_C(59035), UINT16_C(  468), UINT16_C(18066), UINT16_C(31298), UINT16_C(16123), UINT16_C(16143), UINT16_C(64388), UINT16_C(11580) },
      { UINT16_C(52203), UINT16_C(13096), UINT16_C(28910), UINT16_C( 7353), UINT16_C( 3226), UINT16_C(64769), UINT16_C( 1578), UINT16_C(50677) },
      { UINT16_C(11632), UINT16_C(13052), UINT16_C(13948), UINT16_C(26363), UINT16_C(12897), UINT16_C(49678), UINT16_C(64942), UINT16_C(59593) } },
    { { UINT16_C(51692), UINT16_C(32454), UINT16_C( 2319), UINT16_C( 2809), UINT16_C( 2119), UINT16_C(52297), UINT16_C(34051), UINT16_C(61177) },
      { UINT16_C( 8528), UINT16_C(15906), UINT16_C(56209), UINT16_C(11099), UINT16_C(23783), UINT16_C( 4393), UINT16_C( 7778), UINT16_C(20438) },
      { UINT16_C(59580), UINT16_C(16612), UINT16_C(53918), UINT16_C( 8610), UINT16_C(21664), UINT16_C(56672), UINT16_C(39777), UINT16_C(41263) } },
    { { UINT16_C(40424), UINT16_C(63437), UINT16_C(50854), UINT16_C(60674), UINT16_C(19406), UINT16_C(53945), UINT16_C(45777), UINT16_C( 8640) },
      { UINT16_C(58067), UINT16_C(25952), UINT16_C(48062), UINT16_C(42384), UINT16_C(47383), UINT16_C(31159), UINT16_C(36312), UINT16_C(49352) },
      { UINT16_C(32571), UINT16_C(37549), UINT16_C(32024), UINT16_C(18578), UINT16_C(62169), UINT16_C(43790), UINT16_C(16137), UINT16_C(57608) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_veorq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_veorq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veorq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
     { { UINT32_C(1830076854), UINT32_C(2624093226), UINT32_C(4093110100), UINT32_C( 698167114) },
      { UINT32_C( 927289064), UINT32_C(1414399674), UINT32_C(4078960399), UINT32_C( 302114395) },
      { UINT32_C(1515294558), UINT32_C(3357964944), UINT32_C(  15210587), UINT32_C(1000130833) } },
    { { UINT32_C(3531544232), UINT32_C(3866027922), UINT32_C( 433677774), UINT32_C(2084730516) },
      { UINT32_C(2142537924), UINT32_C(2647851662), UINT32_C(1553003009), UINT32_C(2171507417) },
      { UINT32_C(2915802732), UINT32_C(2076042524), UINT32_C(1162450895), UINT32_C(4247577677) } },
    { { UINT32_C( 978579112), UINT32_C(2753610453), UINT32_C(3166566695), UINT32_C( 859373423) },
      { UINT32_C( 364047495), UINT32_C(4021454574), UINT32_C(1363952504), UINT32_C(2110962389) },
      { UINT32_C( 803275311), UINT32_C(1267876923), UINT32_C(3992042079), UINT32_C(1323976122) } },
    { { UINT32_C(2125932200), UINT32_C( 253941736), UINT32_C(1070325712), UINT32_C(1718748382) },
      { UINT32_C(3749389808), UINT32_C( 600714923), UINT32_C(1182079601), UINT32_C(2109949909) },
      { UINT32_C(2714501976), UINT32_C( 753727811), UINT32_C(2042545569), UINT32_C( 464601867) } },
    { { UINT32_C(1442544237), UINT32_C( 560274769), UINT32_C(3680514300), UINT32_C( 625070644) },
      { UINT32_C(2718219511), UINT32_C(1539756778), UINT32_C(3265346541), UINT32_C(4030686338) },
      { UINT32_C(4160734874), UINT32_C(2057555899), UINT32_C( 432081681), UINT32_C(3581851318) } },
    { { UINT32_C( 793066462), UINT32_C(1431349848), UINT32_C( 254849243), UINT32_C(2050257283) },
      { UINT32_C( 404568109), UINT32_C(4168344331), UINT32_C(2696549662), UINT32_C(1485896057) },
      { UINT32_C( 928515059), UINT32_C(2904770899), UINT32_C(2945099205), UINT32_C( 581208314) } },
    { { UINT32_C(2374489652), UINT32_C(1541593216), UINT32_C( 191566472), UINT32_C(2961612675) },
      { UINT32_C(3821577176), UINT32_C(2765831302), UINT32_C(3393492305), UINT32_C(3273840014) },
      { UINT32_C(1850701292), UINT32_C(4281984006), UINT32_C(3241117657), UINT32_C(1940146701) } },
    { { UINT32_C( 726706859), UINT32_C( 176632450), UINT32_C(3340169796), UINT32_C(1769446545) },
      { UINT32_C(3310108735), UINT32_C(3446220668), UINT32_C(1268231612), UINT32_C( 755939970) },
      { UINT32_C(3994872468), UINT32_C(3354269182), UINT32_C(2357288952), UINT32_C(1148790291) } },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_veorq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_veorq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veorq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 8527705653078384895), UINT64_C(10179607844703931613) },
      { UINT64_C(10192410360933839086), UINT64_C( 2403911898190977636) },
      { UINT64_C(18098498112181702673), UINT64_C(12401033501679916729) } },
    { { UINT64_C(10149867462929755977), UINT64_C( 6922438834607896094) },
      { UINT64_C(11828856431356447074), UINT64_C(15918126349759228581) },
      { UINT64_C( 2950729595619485227), UINT64_C(13617190798025235643) } },
    { { UINT64_C(15129031179623276987), UINT64_C(17664637898287554899) },
      { UINT64_C( 7842376392276655600), UINT64_C( 5427430808190387426) },
      { UINT64_C(13628079889122729035), UINT64_C(13724575844232734129) } },
    { { UINT64_C(  343024198562911037), UINT64_C( 7949959993762584523) },
      { UINT64_C( 8962008892823233323), UINT64_C(16956972536245162616) },
      { UINT64_C( 8691341630343114774), UINT64_C( 9583847818821076403) } },
    { { UINT64_C( 9046779137311311831), UINT64_C( 7971704781101815221) },
      { UINT64_C( 3110227796088078098), UINT64_C( 3957404440158477138) },
      { UINT64_C( 6243433851020589253), UINT64_C( 6362083362209287911) } },
    { { UINT64_C( 1854438940996454029), UINT64_C(15587219748785264543) },
      { UINT64_C(13982179792934777132), UINT64_C( 5863314818597010889) },
      { UINT64_C(15832092318380029857), UINT64_C( 9875901426487437910) } },
    { { UINT64_C(  572322636551429492), UINT64_C( 6233608789164637667) },
      { UINT64_C( 9087772245743765483), UINT64_C(  185216643220562046) },
      { UINT64_C( 8786255496314493599), UINT64_C( 6057411476368383389) } },
    { { UINT64_C( 5949478783376040482), UINT64_C(11495577361277811208) },
      { UINT64_C( 9059581084911189638), UINT64_C( 9766426763440578809) },
      { UINT64_C( 3398761491516660900), UINT64_C( 1729716309622659825) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_veorq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_veorq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor3q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t c[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(    21), -INT8_C(    85), -INT8_C(   120),  INT8_C(    20),
         INT8_C(    47), -INT8_C(    45), -INT8_C(    93), -INT8_C(    88),
        -INT8_C(   104), -INT8_C(    51),  INT8_C(    10),  INT8_C(    80),
         INT8_C(     9),  INT8_C(   110), -INT8_C(   118), -INT8_C(     7) },
      {  INT8_C(    28),  INT8_C(   122), -INT8_C(   112), -INT8_C(    28),
        -INT8_C(    45), -INT8_C(   124),  INT8_C(   110), -INT8_C(    84),
         INT8_C(     6),  INT8_C(    43), -INT8_C(    17), -INT8_C(    30),
         INT8_C(   100), -INT8_C(    39),  INT8_C(     4),  INT8_C(    16) },
      {  INT8_C(    84),  INT8_C(    57), -INT8_C(     1), -INT8_C(   115),
         INT8_C(   115),  INT8_C(   119),  INT8_C(    74),  INT8_C(    66),
         INT8_C(    25), -INT8_C(    20), -INT8_C(   127),  INT8_C(    94),
         INT8_C(    99), -INT8_C(     6), -INT8_C(    63),  INT8_C(   108) },
      {  INT8_C(    93), -INT8_C(    24), -INT8_C(    25),  INT8_C(   125),
        -INT8_C(   113),  INT8_C(    32), -INT8_C(   121),  INT8_C(    70),
        -INT8_C(   121),  INT8_C(    10),  INT8_C(   100), -INT8_C(    20),
         INT8_C(    14),  INT8_C(    77),  INT8_C(    79), -INT8_C(   123) } },
    { {  INT8_C(   121), -INT8_C(    79),  INT8_C(   112),  INT8_C(    54),
        -INT8_C(    15), -INT8_C(     6), -INT8_C(    85), -INT8_C(   105),
         INT8_C(   117),  INT8_C(    22),  INT8_C(   121),  INT8_C(   105),
        -INT8_C(    43), -INT8_C(    71),  INT8_C(    42),  INT8_C(   112) },
      {  INT8_C(    73),  INT8_C(    56),  INT8_C(    70),  INT8_C(     8),
        -INT8_C(   113),  INT8_C(     1),  INT8_C(    40),  INT8_C(    49),
         INT8_C(    62),  INT8_C(    52), -INT8_C(   121), -INT8_C(    16),
        -INT8_C(   121),  INT8_C(    63),  INT8_C(    24), -INT8_C(    75) },
      {  INT8_C(    77),  INT8_C(    35),  INT8_C(   115), -INT8_C(    72),
         INT8_C(   123), -INT8_C(    95),  INT8_C(   113), -INT8_C(   110),
         INT8_C(    26), -INT8_C(    22),  INT8_C(    46), -INT8_C(   125),
         INT8_C(    52), -INT8_C(    83), -INT8_C(     6), -INT8_C(    59) },
      {  INT8_C(   125), -INT8_C(    86),  INT8_C(    69), -INT8_C(   122),
         INT8_C(     5),  INT8_C(    90), -INT8_C(    14),  INT8_C(    52),
         INT8_C(    81), -INT8_C(    56), -INT8_C(    48),  INT8_C(    26),
         INT8_C(   102),  INT8_C(    43), -INT8_C(    56),  INT8_C(     0) } },
    { {  INT8_C(    86), -INT8_C(    15), -INT8_C(   122), -INT8_C(    22),
        -INT8_C(   102), -INT8_C(    10),  INT8_C(    96), -INT8_C(    62),
        -INT8_C(    22),  INT8_C(    15), -INT8_C(    50), -INT8_C(    37),
         INT8_C(    15),  INT8_C(    56), -INT8_C(   103), -INT8_C(    28) },
      { -INT8_C(    27), -INT8_C(    30), -INT8_C(    35),  INT8_C(   100),
         INT8_C(    95), -INT8_C(    18),  INT8_C(    65), -INT8_C(   119),
         INT8_C(   119), -INT8_C(     3), -INT8_C(    14),  INT8_C(    97),
         INT8_C(    92), -INT8_C(    68), -INT8_C(   112),  INT8_C(    64) },
      {  INT8_C(    78),  INT8_C(    90),  INT8_C(    41), -INT8_C(    79),
         INT8_C(   102),  INT8_C(   126),  INT8_C(    75), -INT8_C(    98),
         INT8_C(   109),  INT8_C(   103), -INT8_C(     5),  INT8_C(   110),
        -INT8_C(   124),  INT8_C(    23),  INT8_C(     8), -INT8_C(   104) },
      { -INT8_C(     3),  INT8_C(    73),  INT8_C(   114),  INT8_C(    63),
        -INT8_C(    93),  INT8_C(   102),  INT8_C(   106), -INT8_C(    43),
        -INT8_C(    16), -INT8_C(   107), -INT8_C(    57), -INT8_C(    44),
        -INT8_C(    41), -INT8_C(   109),  INT8_C(     1),  INT8_C(    60) } },
    { { -INT8_C(    30),  INT8_C(    38), -INT8_C(   105),  INT8_C(    59),
        -INT8_C(    97),  INT8_C(     4), -INT8_C(    41), -INT8_C(    83),
        -INT8_C(    36), -INT8_C(    93),  INT8_C(     0),  INT8_C(   109),
         INT8_C(   125), -INT8_C(    34), -INT8_C(    22),  INT8_C(    92) },
      {  INT8_C(    59),  INT8_C(    17), -INT8_C(    43), -INT8_C(    30),
        -INT8_C(    85), -INT8_C(    63),  INT8_C(   123),  INT8_C(    64),
         INT8_C(    88),  INT8_C(    78),  INT8_C(    86), -INT8_C(    31),
        -INT8_C(    50), -INT8_C(   114), -INT8_C(   111),  INT8_C(    91) },
      {  INT8_C(    20), -INT8_C(    80),  INT8_C(    82),  INT8_C(    15),
         INT8_C(    64),  INT8_C(    82), -INT8_C(    56), -INT8_C(   105),
         INT8_C(    36),  INT8_C(    42),  INT8_C(    51), -INT8_C(    91),
        -INT8_C(    46),  INT8_C(     3), -INT8_C(   100),  INT8_C(    14) },
      { -INT8_C(    51), -INT8_C(   121),  INT8_C(    16), -INT8_C(    42),
         INT8_C(   116), -INT8_C(   105),  INT8_C(   100),  INT8_C(   122),
        -INT8_C(    96), -INT8_C(    57),  INT8_C(   101),  INT8_C(    41),
         INT8_C(    97),  INT8_C(    83), -INT8_C(    25),  INT8_C(     9) } },
    { { -INT8_C(    77),  INT8_C(    23),  INT8_C(    48), -INT8_C(     8),
        -INT8_C(   116),  INT8_C(    53),  INT8_C(    36),        INT8_MAX,
        -INT8_C(    58),  INT8_C(    51),  INT8_C(    53),  INT8_C(    21),
         INT8_C(    66), -INT8_C(    55), -INT8_C(   125),  INT8_C(    58) },
      {  INT8_C(    82),  INT8_C(   110), -INT8_C(   117),  INT8_C(    80),
         INT8_C(   105),  INT8_C(    46),  INT8_C(    18),  INT8_C(     0),
        -INT8_C(    74), -INT8_C(    55), -INT8_C(    48),  INT8_C(    59),
         INT8_C(    82),  INT8_C(    28),  INT8_C(    80), -INT8_C(   120) },
      {  INT8_C(   125),  INT8_C(    16),  INT8_C(   126),  INT8_C(    16),
        -INT8_C(    27), -INT8_C(    14), -INT8_C(    36), -INT8_C(   127),
         INT8_C(    93),  INT8_C(     3),  INT8_C(    44),  INT8_C(    47),
         INT8_C(    12),  INT8_C(    92),  INT8_C(     4),  INT8_C(    61) },
      { -INT8_C(   100),  INT8_C(   105), -INT8_C(    59), -INT8_C(    72),
         INT8_C(     0), -INT8_C(    23), -INT8_C(    22), -INT8_C(     2),
         INT8_C(    45), -INT8_C(     7), -INT8_C(    55),  INT8_C(     1),
         INT8_C(    28), -INT8_C(   119), -INT8_C(    41), -INT8_C(   113) } },
    { { -INT8_C(   105), -INT8_C(    86),  INT8_C(    95),  INT8_C(    34),
         INT8_C(    44), -INT8_C(    23), -INT8_C(    19), -INT8_C(     7),
         INT8_C(    72), -INT8_C(    94),  INT8_C(    30),  INT8_C(     5),
        -INT8_C(    38),  INT8_C(    46),  INT8_C(    29), -INT8_C(    55) },
      {  INT8_C(    95),  INT8_C(    58),  INT8_C(   111), -INT8_C(    88),
         INT8_C(    73), -INT8_C(   115), -INT8_C(    20), -INT8_C(    45),
        -INT8_C(    95),  INT8_C(   103), -INT8_C(    61),  INT8_C(    70),
        -INT8_C(    39),  INT8_C(   122),  INT8_C(    52),  INT8_C(     4) },
      { -INT8_C(    75), -INT8_C(   102), -INT8_C(    64),  INT8_C(    68),
        -INT8_C(    35),  INT8_C(   110), -INT8_C(    23), -INT8_C(     2),
        -INT8_C(    28), -INT8_C(    21), -INT8_C(    94), -INT8_C(    28),
         INT8_C(    11),  INT8_C(   103),  INT8_C(    10), -INT8_C(    62) },
      {  INT8_C(   125),  INT8_C(    10), -INT8_C(    16), -INT8_C(    50),
        -INT8_C(    72),  INT8_C(    10), -INT8_C(    24), -INT8_C(    44),
         INT8_C(    13),  INT8_C(    46),        INT8_MAX, -INT8_C(    89),
         INT8_C(     8),  INT8_C(    51),  INT8_C(    35),  INT8_C(    15) } },
    { { -INT8_C(    45),        INT8_MAX,  INT8_C(    55),  INT8_C(   116),
        -INT8_C(    68), -INT8_C(    63), -INT8_C(   116), -INT8_C(    69),
        -INT8_C(    13),  INT8_C(     9),  INT8_C(   124),  INT8_C(    47),
        -INT8_C(   111),  INT8_C(    93),  INT8_C(    45), -INT8_C(    72) },
      { -INT8_C(    21),  INT8_C(    48), -INT8_C(    31), -INT8_C(    51),
        -INT8_C(   103),  INT8_C(   110), -INT8_C(    79),  INT8_C(    66),
        -INT8_C(    52), -INT8_C(   121), -INT8_C(    45),  INT8_C(    24),
         INT8_C(    81), -INT8_C(    43),  INT8_C(   106), -INT8_C(    17) },
      { -INT8_C(    51), -INT8_C(   126), -INT8_C(   111),  INT8_C(   109),
        -INT8_C(   113),  INT8_C(    20),  INT8_C(    53), -INT8_C(    97),
         INT8_C(    30),  INT8_C(   111), -INT8_C(    76),  INT8_C(    19),
        -INT8_C(    53), -INT8_C(    52),  INT8_C(    50),  INT8_C(   103) },
      { -INT8_C(    11), -INT8_C(    51),  INT8_C(    71), -INT8_C(    44),
        -INT8_C(    86), -INT8_C(    69),  INT8_C(     8),  INT8_C(   102),
         INT8_C(    33), -INT8_C(    31),  INT8_C(    27),  INT8_C(    36),
         INT8_C(    11),  INT8_C(    68),  INT8_C(   117),  INT8_C(    48) } },
    { { -INT8_C(    20), -INT8_C(   120), -INT8_C(   102),  INT8_C(    48),
        -INT8_C(    27), -INT8_C(    81),  INT8_C(     9),  INT8_C(    43),
        -INT8_C(    57),  INT8_C(   120),  INT8_C(    75), -INT8_C(    34),
        -INT8_C(    50), -INT8_C(    17), -INT8_C(   127),  INT8_C(    62) },
      { -INT8_C(    85), -INT8_C(    61), -INT8_C(    20), -INT8_C(    25),
        -INT8_C(    66), -INT8_C(    92),  INT8_C(    45),  INT8_C(    99),
        -INT8_C(    60), -INT8_C(    87),  INT8_C(    56), -INT8_C(     5),
         INT8_C(    88), -INT8_C(    31),  INT8_C(    84), -INT8_C(    88) },
      {  INT8_C(    33),  INT8_C(    23), -INT8_C(    12),  INT8_C(    41),
         INT8_C(     5), -INT8_C(    65),  INT8_C(     3), -INT8_C(    50),
         INT8_C(    45), -INT8_C(    93),  INT8_C(    33),  INT8_C(    78),
        -INT8_C(     3),  INT8_C(   100), -INT8_C(    68),  INT8_C(    99) },
      {  INT8_C(   102),  INT8_C(    92), -INT8_C(   126), -INT8_C(     2),
         INT8_C(    94), -INT8_C(    76),  INT8_C(    39), -INT8_C(   122),
         INT8_C(    46),  INT8_C(   114),  INT8_C(    82),  INT8_C(   107),
         INT8_C(   107),  INT8_C(   106),  INT8_C(   105), -INT8_C(    11) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int8x16_t r = simde_veor3q_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_veor3q_s8(a, b, c);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor3q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 10152), -INT16_C( 18881),  INT16_C( 23613), -INT16_C( 31718),
        -INT16_C( 20680),  INT16_C( 22055),  INT16_C(  4071),  INT16_C( 12310) },
      { -INT16_C( 14313),  INT16_C( 15814),  INT16_C(  3771),  INT16_C(  6855),
        -INT16_C( 26474), -INT16_C( 25313),  INT16_C( 31681), -INT16_C(  1381) },
      { -INT16_C( 26993),  INT16_C( 19703),  INT16_C(  6139),  INT16_C( 16207),
        -INT16_C( 14764),  INT16_C( 17764),  INT16_C(  4791),  INT16_C( 18837) },
      { -INT16_C( 31040), -INT16_C( 14578),  INT16_C( 17789), -INT16_C( 24174),
        -INT16_C(  3590), -INT16_C( 29092),  INT16_C( 26257), -INT16_C( 31976) } },
    { { -INT16_C( 21154),  INT16_C( 19965), -INT16_C( 17686),  INT16_C( 17544),
         INT16_C(  8224), -INT16_C(   308), -INT16_C(  7229),  INT16_C( 15907) },
      { -INT16_C( 30715), -INT16_C(  9827),  INT16_C( 13414),  INT16_C( 14303),
        -INT16_C( 28460), -INT16_C( 15495),  INT16_C( 18103),  INT16_C( 17218) },
      {  INT16_C( 15881), -INT16_C( 13212), -INT16_C( 21305),  INT16_C( 26708),
        -INT16_C( 10453), -INT16_C( 13212),  INT16_C(  9679), -INT16_C(  6568) },
      {  INT16_C(  6994),  INT16_C( 22532),  INT16_C(  8779),  INT16_C(  6915),
         INT16_C( 26591), -INT16_C(  3631), -INT16_C( 32581), -INT16_C( 25799) } },
    { {  INT16_C( 23233),  INT16_C( 17917), -INT16_C( 18179), -INT16_C(   454),
         INT16_C( 24388), -INT16_C( 22383),  INT16_C(   626),  INT16_C( 30167) },
      { -INT16_C(   890), -INT16_C( 20525),  INT16_C(  5437), -INT16_C( 11894),
        -INT16_C( 26936), -INT16_C( 13025), -INT16_C(  6295),  INT16_C( 18536) },
      { -INT16_C(  4592), -INT16_C(  7558), -INT16_C( 31386), -INT16_C( 24188),
         INT16_C( 32006),  INT16_C( 19467), -INT16_C(  9199),  INT16_C( 16613) },
      {  INT16_C( 18519),  INT16_C(  2132),  INT16_C( 10406), -INT16_C( 29132),
        -INT16_C( 19318),  INT16_C( 10629),  INT16_C( 14602),  INT16_C( 32090) } },
    { { -INT16_C( 27598),  INT16_C( 32331), -INT16_C(  4378),  INT16_C( 28582),
         INT16_C( 30096),  INT16_C( 23148), -INT16_C( 17069),  INT16_C(    85) },
      {  INT16_C(  2860),  INT16_C(    60), -INT16_C( 21175), -INT16_C( 31424),
        -INT16_C( 15314),  INT16_C( 31484),  INT16_C( 13159),  INT16_C( 18382) },
      {  INT16_C( 23663), -INT16_C(  6354), -INT16_C( 18204),  INT16_C( 13058),
        -INT16_C( 24715), -INT16_C( 28782), -INT16_C( 23633),  INT16_C(  2889) },
      { -INT16_C( 15503), -INT16_C( 26279), -INT16_C(  1205), -INT16_C(  9756),
         INT16_C( 11979), -INT16_C( 20734),  INT16_C( 11675),  INT16_C( 19666) } },
    { {  INT16_C( 17129), -INT16_C( 24710), -INT16_C( 28138), -INT16_C( 17405),
         INT16_C(  7609),  INT16_C( 21217),  INT16_C( 21654), -INT16_C( 26052) },
      { -INT16_C(  8987), -INT16_C( 19455),  INT16_C( 25265), -INT16_C(   547),
         INT16_C(  6800),  INT16_C( 14869),  INT16_C( 13362), -INT16_C( 30374) },
      {  INT16_C(  7866), -INT16_C( 22175), -INT16_C(  4884),  INT16_C( 27008),
        -INT16_C( 23243),  INT16_C( 29319), -INT16_C(   971),  INT16_C( 20545) },
      { -INT16_C( 32586), -INT16_C( 32230),  INT16_C(  7243),  INT16_C( 10334),
        -INT16_C( 24036),  INT16_C(  6771), -INT16_C( 25455),  INT16_C( 17191) } },
    { {  INT16_C( 28185),  INT16_C( 11357), -INT16_C(  9592), -INT16_C( 11823),
        -INT16_C( 13174), -INT16_C(  6194), -INT16_C(   101), -INT16_C(   878) },
      {  INT16_C(  5451),  INT16_C( 26474), -INT16_C( 25378), -INT16_C( 11351),
        -INT16_C( 18552),  INT16_C( 27432),  INT16_C( 20703), -INT16_C( 26121) },
      { -INT16_C( 19983), -INT16_C( 20281),  INT16_C(  5674),  INT16_C( 20585),
         INT16_C( 17419), -INT16_C(  7113), -INT16_C(  3411),  INT16_C( 27851) },
      { -INT16_C( 13661), -INT16_C(  1040),  INT16_C( 20604),  INT16_C( 21009),
         INT16_C( 16137),  INT16_C( 26833),  INT16_C( 24041),  INT16_C(  2478) } },
    { { -INT16_C( 14782),  INT16_C( 10856),  INT16_C( 18358), -INT16_C(  4380),
         INT16_C( 30158), -INT16_C( 15366), -INT16_C( 10541), -INT16_C( 31565) },
      { -INT16_C(   492),  INT16_C(  3206),  INT16_C( 15309),  INT16_C( 26752),
         INT16_C( 25281),  INT16_C( 17996),  INT16_C(  6855), -INT16_C(  9066) },
      {  INT16_C(  5970),  INT16_C( 24909),  INT16_C( 30672),  INT16_C(  3251),
         INT16_C(  4118), -INT16_C( 32617), -INT16_C( 25379), -INT16_C(   482) },
      {  INT16_C( 12036),  INT16_C( 18339),  INT16_C(  2987), -INT16_C( 29993),
         INT16_C(  1817),  INT16_C(  1313),  INT16_C( 20681), -INT16_C( 22981) } },
    { { -INT16_C( 28671),  INT16_C(  2254), -INT16_C( 23292), -INT16_C( 32538),
         INT16_C(  6117),  INT16_C( 26019),  INT16_C( 17737), -INT16_C( 18082) },
      { -INT16_C( 18002), -INT16_C( 13215),  INT16_C( 18871),  INT16_C(  7103),
         INT16_C( 22198),  INT16_C( 15527),  INT16_C( 18142),  INT16_C( 26734) },
      { -INT16_C( 12647),  INT16_C( 28533),  INT16_C( 16602), -INT16_C( 11417),
         INT16_C( 18747),  INT16_C( 14605), -INT16_C( 16966), -INT16_C(   806) },
      { -INT16_C(  6346), -INT16_C( 21542), -INT16_C( 21399),  INT16_C( 18494),
         INT16_C(  2152),  INT16_C( 24585), -INT16_C( 16851),  INT16_C( 11754) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int16x8_t r = simde_veor3q_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_veor3q_s16(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor3q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   323892648),  INT32_C(  1384106019),  INT32_C(   726284660), -INT32_C(   684489895) },
      { -INT32_C(  1833203426), -INT32_C(  1907364298),  INT32_C(   923238645), -INT32_C(   779219040) },
      {  INT32_C(   822735784), -INT32_C(   867048651),  INT32_C(  1444634564), -INT32_C(  2114189109) },
      { -INT32_C(  1325641954),  INT32_C(   274842912),  INT32_C(  1247209029), -INT32_C(  2025749454) } },
    { {  INT32_C(   949653720),  INT32_C(  1425062306),  INT32_C(   935547485), -INT32_C(   539192833) },
      {  INT32_C(  1579535376), -INT32_C(   675242411), -INT32_C(   649056824),  INT32_C(  1196551640) },
      { -INT32_C(  1500366936), -INT32_C(  1949237307), -INT32_C(   551874139), -INT32_C(  1976423524) },
      { -INT32_C(  1070765216),  INT32_C(   148953138),  INT32_C(   831024688),  INT32_C(   314529723) } },
    { {  INT32_C(  1486669346),  INT32_C(   985627485),  INT32_C(   590713274),  INT32_C(   165540318) },
      {  INT32_C(   473075282), -INT32_C(   624990180), -INT32_C(  1587348065),  INT32_C(  1777688907) },
      { -INT32_C(   647940127),  INT32_C(  1869342062),  INT32_C(  1047384588), -INT32_C(   130742674) },
      { -INT32_C(  1647345775), -INT32_C(  1888750033), -INT32_C(  1137000919), -INT32_C(  1742891269) } },
    { {  INT32_C(   659267439), -INT32_C(  1826167827),  INT32_C(   956934931),  INT32_C(  1504852371) },
      {  INT32_C(  1918963925), -INT32_C(  1680064133), -INT32_C(  2086228144), -INT32_C(  1343864141) },
      {  INT32_C(   504282103),  INT32_C(  1826875618), -INT32_C(   552797636), -INT32_C(  1678021347) },
      {  INT32_C(  1260663885),  INT32_C(  1679379060),  INT32_C(  1705246335),  INT32_C(  1840191037) } },
    { { -INT32_C(   976966371),  INT32_C(   981534845),  INT32_C(   459350662), -INT32_C(  1780862014) },
      {  INT32_C(   258547271),  INT32_C(  2087451895),  INT32_C(  1530505414),  INT32_C(   268055248) },
      {  INT32_C(  1838233334), -INT32_C(  1334738312),  INT32_C(  1767823457),  INT32_C(   874173814) },
      { -INT32_C(  1489205844), -INT32_C(   157583630),  INT32_C(   688280097), -INT32_C(  1371876252) } },
    { { -INT32_C(  1782873799),  INT32_C(   674258504),  INT32_C(   658824466), -INT32_C(  2115685397) },
      { -INT32_C(  1583592374), -INT32_C(  1066983185),  INT32_C(   907547291),  INT32_C(   842094460) },
      {  INT32_C(  1186107422), -INT32_C(   382751531), -INT32_C(  1349092461), -INT32_C(   595525210) },
      {  INT32_C(  1922391405),  INT32_C(    24695410), -INT32_C(  1094011878),  INT32_C(  1867867441) } },
    { { -INT32_C(  1286290710), -INT32_C(  2051218083),  INT32_C(  1617208424), -INT32_C(   162210271) },
      { -INT32_C(   483120062),  INT32_C(   850323275),  INT32_C(   983693536), -INT32_C(  1896703319) },
      {  INT32_C(  1369535000),  INT32_C(   158476132),  INT32_C(   870543198),  INT32_C(  1748734278) },
      {  INT32_C(    29465776), -INT32_C(  1100995214),  INT32_C(  1764111318),  INT32_C(   278779342) } },
    { { -INT32_C(    24905673),  INT32_C(  2056083159),  INT32_C(  1655348419),  INT32_C(  1234933598) },
      { -INT32_C(    96046328), -INT32_C(  1698315470), -INT32_C(   368219511),  INT32_C(  2071136001) },
      { -INT32_C(   722495201),  INT32_C(  1971221709), -INT32_C(  1807152701),  INT32_C(   533362735) },
      { -INT32_C(   802549216), -INT32_C(  1791565528),  INT32_C(   485425033),  INT32_C(   757262448) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int32x4_t r = simde_veor3q_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_veor3q_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor3q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t c[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4638774013553819909), -INT64_C( 8884888074014547475) },
      {  INT64_C( 1404847390354270100), -INT64_C( 6120382300383496189) },
      {  INT64_C(  510586128564140066), -INT64_C( 4669346189943332271) },
      {  INT64_C( 6055879429715762867), -INT64_C( 8029452465309664321) } },
    { { -INT64_C( 4518067150824540513),  INT64_C( 4957142466715566025) },
      {  INT64_C( 8043924324338415103), -INT64_C( 4981648619678475813) },
      {  INT64_C(  699843771172600371),  INT64_C( 1793229598566719259) },
      { -INT64_C( 6387507920863594157), -INT64_C( 1804752782580549367) } },
    { { -INT64_C( 4125870250540529181),  INT64_C( 6930310998737411263) },
      { -INT64_C( 8860981326991971048), -INT64_C( 7926835076461364725) },
      { -INT64_C( 7312533027160091330), -INT64_C( 3395442555678374122) },
      { -INT64_C( 2792751531422142011),  INT64_C( 2392439040862052770) } },
    { {  INT64_C( 1494485982448689874), -INT64_C( 7626629299547756048) },
      {  INT64_C(  376407177239137712), -INT64_C( 7227618134522587779) },
      {  INT64_C( 7206243324629525647), -INT64_C( 2370852749664172260) },
      {  INT64_C( 8468323520626691053), -INT64_C( 3277605221395530863) } },
    { { -INT64_C( 7730145936594419556), -INT64_C( 3995021948061466444) },
      { -INT64_C(  800155454130307119), -INT64_C( 9126700936700617985) },
      { -INT64_C( 3933470342349232941), -INT64_C( 8132518178441869717) },
      { -INT64_C( 6253874319007835234), -INT64_C( 4108733511408247776) } },
    { {  INT64_C( 9114455685161166175),  INT64_C( 6809867769459327414) },
      {  INT64_C( 2768376652175377559), -INT64_C( 7862651902585466538) },
      { -INT64_C( 7500417362199905687),  INT64_C( 5526814338319531008) },
      { -INT64_C( 3459018605888087135), -INT64_C( 9164669948687323936) } },
    { { -INT64_C( 8544532457137223072),  INT64_C( 4234122779848705376) },
      { -INT64_C( 3582284983839223568), -INT64_C( 8449568412402443350) },
      { -INT64_C( 1919064366516748650),  INT64_C( 5508044684798505028) },
      { -INT64_C( 6738353809293122554), -INT64_C(  283943367811453298) } },
    { {  INT64_C(  963541064439025994), -INT64_C(  826915855778475689) },
      { -INT64_C( 5247048313372008024),  INT64_C( 3506867262503041046) },
      { -INT64_C( 4712020193258616527), -INT64_C( 6798448011845967150) },
      {  INT64_C(  354122719322683859),  INT64_C( 7317187027867978643) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t c = simde_vld1q_s64(test_vec[i].c);
    simde_int64x2_t r = simde_veor3q_s64(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t c = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_veor3q_s64(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor3q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t c[16];
    uint8_t r[16];
  } test_vec[] = {
    { {  UINT8_C(  223),  UINT8_C(  129),  UINT8_C(   95),  UINT8_C(   37),
         UINT8_C(  123),  UINT8_C(  122),  UINT8_C(  216),  UINT8_C(  192),
         UINT8_C(  246),  UINT8_C(  114),  UINT8_C(  220),  UINT8_C(  189),
         UINT8_C(    0),  UINT8_C(  252),  UINT8_C(   15),  UINT8_C(  143) },
      {  UINT8_C(  174),  UINT8_C(  199),  UINT8_C(  119),  UINT8_C(   26),
         UINT8_C(  176),  UINT8_C(   79),  UINT8_C(  105),  UINT8_C(   44),
         UINT8_C(   33),  UINT8_C(  164),  UINT8_C(  226),  UINT8_C(    6),
         UINT8_C(  108),  UINT8_C(  152),  UINT8_C(  245),  UINT8_C(   99) },
      {  UINT8_C(  106),  UINT8_C(  192),  UINT8_C(  162),  UINT8_C(  249),
         UINT8_C(  111),  UINT8_C(   86),  UINT8_C(  228),  UINT8_C(   82),
         UINT8_C(   32),  UINT8_C(   55),  UINT8_C(  154),  UINT8_C(  196),
         UINT8_C(   30),  UINT8_C(  128),  UINT8_C(  184),  UINT8_C(  178) },
      {  UINT8_C(   27),  UINT8_C(  134),  UINT8_C(  138),  UINT8_C(  198),
         UINT8_C(  164),  UINT8_C(   99),  UINT8_C(   85),  UINT8_C(  190),
         UINT8_C(  247),  UINT8_C(  225),  UINT8_C(  164),  UINT8_C(  127),
         UINT8_C(  114),  UINT8_C(  228),  UINT8_C(   66),  UINT8_C(   94) } },
    { {  UINT8_C(  239),  UINT8_C(   50),  UINT8_C(   49),  UINT8_C(   55),
         UINT8_C(   51),  UINT8_C(  207),  UINT8_C(  217),  UINT8_C(  230),
         UINT8_C(   88),  UINT8_C(   45),  UINT8_C(  183),  UINT8_C(   79),
         UINT8_C(  178),  UINT8_C(  202),  UINT8_C(   42),  UINT8_C(   27) },
      {  UINT8_C(  251),  UINT8_C(  157),  UINT8_C(   22),  UINT8_C(  103),
         UINT8_C(  166),  UINT8_C(   37),  UINT8_C(   50),  UINT8_C(   80),
         UINT8_C(  112),  UINT8_C(  178),  UINT8_C(   52),  UINT8_C(  234),
         UINT8_C(  102),  UINT8_C(   66),  UINT8_C(  177),  UINT8_C(   26) },
      {  UINT8_C(  115),  UINT8_C(  233),  UINT8_C(    7),  UINT8_C(    2),
         UINT8_C(  189),  UINT8_C(   79),  UINT8_C(  152),  UINT8_C(   50),
         UINT8_C(    8),  UINT8_C(  193),  UINT8_C(   93),  UINT8_C(  228),
         UINT8_C(   78),  UINT8_C(   54),  UINT8_C(  254),  UINT8_C(   50) },
      {  UINT8_C(  103),  UINT8_C(   70),  UINT8_C(   32),  UINT8_C(   82),
         UINT8_C(   40),  UINT8_C(  165),  UINT8_C(  115),  UINT8_C(  132),
         UINT8_C(   32),  UINT8_C(   94),  UINT8_C(  222),  UINT8_C(   65),
         UINT8_C(  154),  UINT8_C(  190),  UINT8_C(  101),  UINT8_C(   51) } },
    { {  UINT8_C(  168),  UINT8_C(   75),  UINT8_C(  104),  UINT8_C(   96),
         UINT8_C(  190),  UINT8_C(  171),  UINT8_C(  129),  UINT8_C(   96),
         UINT8_C(  237),  UINT8_C(  101),  UINT8_C(  216),  UINT8_C(   98),
         UINT8_C(  103),  UINT8_C(  140),  UINT8_C(  248),  UINT8_C(  144) },
      {  UINT8_C(  122),  UINT8_C(  175),  UINT8_C(  243),  UINT8_C(  168),
         UINT8_C(  190),  UINT8_C(  121),  UINT8_C(   84),  UINT8_C(  134),
         UINT8_C(  162),  UINT8_C(  236),  UINT8_C(   53),  UINT8_C(  158),
         UINT8_C(   63),  UINT8_C(  136),  UINT8_C(   55),  UINT8_C(   21) },
      {  UINT8_C(  179),  UINT8_C(  159),  UINT8_C(  140),  UINT8_C(  250),
         UINT8_C(   75),  UINT8_C(  209),  UINT8_C(  214),  UINT8_C(   30),
         UINT8_C(  207),  UINT8_C(  224),  UINT8_C(  103),  UINT8_C(   29),
         UINT8_C(   36),  UINT8_C(  185),  UINT8_C(   24),  UINT8_C(  142) },
      {  UINT8_C(   97),  UINT8_C(  123),  UINT8_C(   23),  UINT8_C(   50),
         UINT8_C(   75),  UINT8_C(    3),  UINT8_C(    3),  UINT8_C(  248),
         UINT8_C(  128),  UINT8_C(  105),  UINT8_C(  138),  UINT8_C(  225),
         UINT8_C(  124),  UINT8_C(  189),  UINT8_C(  215),  UINT8_C(   11) } },
    { {  UINT8_C(   38),  UINT8_C(  126),  UINT8_C(  239),  UINT8_C(  114),
         UINT8_C(    6),  UINT8_C(   35),  UINT8_C(  220),  UINT8_C(  169),
         UINT8_C(   48),  UINT8_C(   80),  UINT8_C(  254),  UINT8_C(   10),
         UINT8_C(   20),  UINT8_C(  107),  UINT8_C(   80),  UINT8_C(  200) },
      {  UINT8_C(  140),  UINT8_C(  211),  UINT8_C(   77),  UINT8_C(  122),
         UINT8_C(   30),  UINT8_C(  107),  UINT8_C(   31),  UINT8_C(   16),
         UINT8_C(   69),  UINT8_C(  139),  UINT8_C(  158),  UINT8_C(   11),
         UINT8_C(  194),  UINT8_C(  205),  UINT8_C(  160),  UINT8_C(  241) },
      {  UINT8_C(  208),  UINT8_C(  110),  UINT8_C(  175),  UINT8_C(  166),
         UINT8_C(   65),  UINT8_C(  121),  UINT8_C(   48),  UINT8_C(  252),
         UINT8_C(   49),  UINT8_C(  198),  UINT8_C(   85),  UINT8_C(  181),
         UINT8_C(   43),  UINT8_C(  107),  UINT8_C(  251),  UINT8_C(  113) },
      {  UINT8_C(  122),  UINT8_C(  195),  UINT8_C(   13),  UINT8_C(  174),
         UINT8_C(   89),  UINT8_C(   49),  UINT8_C(  243),  UINT8_C(   69),
         UINT8_C(   68),  UINT8_C(   29),  UINT8_C(   53),  UINT8_C(  180),
         UINT8_C(  253),  UINT8_C(  205),  UINT8_C(   11),  UINT8_C(   72) } },
    { {  UINT8_C(   68),  UINT8_C(   51),  UINT8_C(   87),  UINT8_C(  153),
         UINT8_C(   87),  UINT8_C(  180),  UINT8_C(  115),  UINT8_C(  243),
         UINT8_C(   24),  UINT8_C(   51),  UINT8_C(  200),  UINT8_C(  191),
         UINT8_C(   10),  UINT8_C(  233),  UINT8_C(  217),  UINT8_C(  110) },
      {  UINT8_C(  189),  UINT8_C(  252),  UINT8_C(   34),  UINT8_C(  146),
         UINT8_C(  139),  UINT8_C(  210),  UINT8_C(  247),  UINT8_C(  164),
         UINT8_C(  187),  UINT8_C(   18),  UINT8_C(   92),  UINT8_C(  231),
         UINT8_C(   72),  UINT8_C(  211),  UINT8_C(  190),  UINT8_C(   10) },
      {  UINT8_C(   92),  UINT8_C(   80),  UINT8_C(  221),  UINT8_C(    7),
         UINT8_C(    4),  UINT8_C(  216),  UINT8_C(   34),  UINT8_C(  185),
         UINT8_C(  172),  UINT8_C(   35),  UINT8_C(    4),  UINT8_C(  204),
         UINT8_C(  253),  UINT8_C(  177),  UINT8_C(   88),  UINT8_C(  150) },
      {  UINT8_C(  165),  UINT8_C(  159),  UINT8_C(  168),  UINT8_C(   12),
         UINT8_C(  216),  UINT8_C(  190),  UINT8_C(  166),  UINT8_C(  238),
         UINT8_C(   15),  UINT8_C(    2),  UINT8_C(  144),  UINT8_C(  148),
         UINT8_C(  191),  UINT8_C(  139),  UINT8_C(   63),  UINT8_C(  242) } },
    { {  UINT8_C(   35),  UINT8_C(  186),  UINT8_C(   21),  UINT8_C(  154),
         UINT8_C(  181),  UINT8_C(   82),  UINT8_C(   15),  UINT8_C(   21),
         UINT8_C(   28),  UINT8_C(  154),  UINT8_C(  191),  UINT8_C(   78),
         UINT8_C(  192),  UINT8_C(   19),  UINT8_C(  119),  UINT8_C(  220) },
      {  UINT8_C(   96),  UINT8_C(  134),  UINT8_C(  160),  UINT8_C(  212),
         UINT8_C(  166),  UINT8_C(  180),  UINT8_C(  127),  UINT8_C(   75),
         UINT8_C(  175),  UINT8_C(  245),  UINT8_C(   72),  UINT8_C(  239),
         UINT8_C(  182),  UINT8_C(  232),  UINT8_C(   98),  UINT8_C(  226) },
      {  UINT8_C(  169),  UINT8_C(  244),  UINT8_C(   93),  UINT8_C(  111),
         UINT8_C(  239),  UINT8_C(  214),  UINT8_C(  244),  UINT8_C(   70),
         UINT8_C(  198),  UINT8_C(   70),  UINT8_C(    3),  UINT8_C(  124),
         UINT8_C(  223),  UINT8_C(  140),  UINT8_C(  147),  UINT8_C(  136) },
      {  UINT8_C(  234),  UINT8_C(  200),  UINT8_C(  232),  UINT8_C(   33),
         UINT8_C(  252),  UINT8_C(   48),  UINT8_C(  132),  UINT8_C(   24),
         UINT8_C(  117),  UINT8_C(   41),  UINT8_C(  244),  UINT8_C(  221),
         UINT8_C(  169),  UINT8_C(  119),  UINT8_C(  134),  UINT8_C(  182) } },
    { {  UINT8_C(  209),  UINT8_C(  205),  UINT8_C(  207),  UINT8_C(   97),
         UINT8_C(   54),  UINT8_C(  155),  UINT8_C(   65),  UINT8_C(  237),
         UINT8_C(  155),  UINT8_C(    8),  UINT8_C(  235),  UINT8_C(   63),
         UINT8_C(  187),  UINT8_C(  162),  UINT8_C(  156),  UINT8_C(   20) },
      {  UINT8_C(  210),  UINT8_C(  224),  UINT8_C(   86),  UINT8_C(   25),
         UINT8_C(  165),  UINT8_C(   87),  UINT8_C(   56),  UINT8_C(  212),
         UINT8_C(  101),  UINT8_C(  114),  UINT8_C(  129),  UINT8_C(    2),
         UINT8_C(  126),  UINT8_C(  135),  UINT8_C(  170),  UINT8_C(  100) },
      {  UINT8_C(  178),  UINT8_C(  251),  UINT8_C(  173),  UINT8_C(  219),
         UINT8_C(  164),  UINT8_C(   14),  UINT8_C(   65),  UINT8_C(  103),
         UINT8_C(  168),  UINT8_C(  131),  UINT8_C(   71),  UINT8_C(  101),
         UINT8_C(   91),  UINT8_C(   93),  UINT8_C(  211),  UINT8_C(  157) },
      {  UINT8_C(  177),  UINT8_C(  214),  UINT8_C(   52),  UINT8_C(  163),
         UINT8_C(   55),  UINT8_C(  194),  UINT8_C(   56),  UINT8_C(   94),
         UINT8_C(   86),  UINT8_C(  249),  UINT8_C(   45),  UINT8_C(   88),
         UINT8_C(  158),  UINT8_C(  120),  UINT8_C(  229),  UINT8_C(  237) } },
    { {  UINT8_C(  115),  UINT8_C(   96),      UINT8_MAX,  UINT8_C(  252),
         UINT8_C(   67),  UINT8_C(   91),  UINT8_C(  127),  UINT8_C(  133),
         UINT8_C(  128),  UINT8_C(  214),  UINT8_C(  131),  UINT8_C(   25),
         UINT8_C(   96),  UINT8_C(  169),  UINT8_C(   41),  UINT8_C(  224) },
      {  UINT8_C(   45),  UINT8_C(   94),  UINT8_C(  170),  UINT8_C(  103),
         UINT8_C(   80),  UINT8_C(   71),  UINT8_C(  129),  UINT8_C(  176),
         UINT8_C(  170),  UINT8_C(  111),  UINT8_C(   25),  UINT8_C(   15),
         UINT8_C(   24),  UINT8_C(  183),  UINT8_C(   50),  UINT8_C(  203) },
      {  UINT8_C(  131),  UINT8_C(  126),  UINT8_C(  215),  UINT8_C(  111),
         UINT8_C(  206),  UINT8_C(   70),  UINT8_C(   11),  UINT8_C(  141),
         UINT8_C(   10),  UINT8_C(  185),  UINT8_C(  242),  UINT8_C(  143),
         UINT8_C(  114),  UINT8_C(   78),  UINT8_C(   25),  UINT8_C(  103) },
      {  UINT8_C(  221),  UINT8_C(   64),  UINT8_C(  130),  UINT8_C(  244),
         UINT8_C(  221),  UINT8_C(   90),  UINT8_C(  245),  UINT8_C(  184),
         UINT8_C(   32),  UINT8_C(    0),  UINT8_C(  104),  UINT8_C(  153),
         UINT8_C(   10),  UINT8_C(   80),  UINT8_C(    2),  UINT8_C(   76) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint8x16_t r = simde_veor3q_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_veor3q_u8(a, b, c);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor3q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  UINT16_C( 17897),  UINT16_C( 32778),  UINT16_C( 57807),  UINT16_C( 59602),
         UINT16_C( 11591),  UINT16_C( 49563),  UINT16_C( 39736),  UINT16_C( 38794) },
      {  UINT16_C( 44336),  UINT16_C( 42705),  UINT16_C( 15031),  UINT16_C( 26610),
         UINT16_C( 47639),  UINT16_C( 54555),  UINT16_C(  5365),  UINT16_C( 51881) },
      {  UINT16_C( 39074),  UINT16_C( 18956),  UINT16_C( 45959),  UINT16_C( 63674),
         UINT16_C( 40022),  UINT16_C( 48649),  UINT16_C( 60918),  UINT16_C(  5255) },
      {  UINT16_C( 28795),  UINT16_C( 27863),  UINT16_C( 26879),  UINT16_C( 30618),
         UINT16_C(  2822),  UINT16_C( 43657),  UINT16_C( 25147),  UINT16_C( 18852) } },
    { {  UINT16_C(  3615),  UINT16_C( 53809),  UINT16_C( 22169),  UINT16_C(  6289),
         UINT16_C( 30597),  UINT16_C( 40547),  UINT16_C( 27772),  UINT16_C( 50373) },
      {  UINT16_C( 53918),  UINT16_C( 25920),  UINT16_C( 43535),  UINT16_C( 38485),
         UINT16_C( 21339),  UINT16_C( 58112),  UINT16_C( 47496),  UINT16_C( 53150) },
      {  UINT16_C( 58563),  UINT16_C( 31429),  UINT16_C( 53003),  UINT16_C( 61157),
         UINT16_C( 50656),  UINT16_C( 18065),  UINT16_C(  3847),  UINT16_C(  1950) },
      {  UINT16_C( 14402),  UINT16_C( 52660),  UINT16_C( 13213),  UINT16_C( 24609),
         UINT16_C( 57662),  UINT16_C( 15346),  UINT16_C( 56051),  UINT16_C(  3269) } },
    { {  UINT16_C( 17360),  UINT16_C( 31100),  UINT16_C( 40246),  UINT16_C( 38559),
         UINT16_C( 21928),  UINT16_C( 51987),  UINT16_C( 40526),  UINT16_C( 32116) },
      {  UINT16_C( 52210),  UINT16_C( 21516),  UINT16_C( 30758),  UINT16_C( 57615),
         UINT16_C( 36401),  UINT16_C( 44927),  UINT16_C( 39623),  UINT16_C( 56608) },
      {  UINT16_C( 23095),  UINT16_C( 63953),  UINT16_C( 19713),  UINT16_C( 39738),
         UINT16_C( 12301),  UINT16_C(  3660),  UINT16_C( 15520),  UINT16_C( 60827) },
      {  UINT16_C( 53781),  UINT16_C( 54433),  UINT16_C( 43025),  UINT16_C( 60586),
         UINT16_C( 60308),  UINT16_C( 27168),  UINT16_C( 14377),  UINT16_C( 19919) } },
    { {  UINT16_C( 42713),  UINT16_C( 34202),  UINT16_C(  2639),  UINT16_C( 12237),
         UINT16_C( 22945),  UINT16_C( 29804),  UINT16_C( 62363),  UINT16_C( 44411) },
      {  UINT16_C( 53740),  UINT16_C( 29554),  UINT16_C( 29414),  UINT16_C( 26259),
         UINT16_C( 23381),  UINT16_C( 64944),  UINT16_C( 22945),  UINT16_C( 55015) },
      {  UINT16_C(  9644),  UINT16_C( 26259),  UINT16_C( 19230),  UINT16_C( 21447),
         UINT16_C( 30177),  UINT16_C(  1795),  UINT16_C( 18038),  UINT16_C(   970) },
      {  UINT16_C( 21145),  UINT16_C( 36987),  UINT16_C( 13239),  UINT16_C(  6809),
         UINT16_C( 30485),  UINT16_C( 36575),  UINT16_C( 60492),  UINT16_C( 30806) } },
    { {  UINT16_C( 15490),  UINT16_C( 18352),  UINT16_C( 42881),  UINT16_C( 48158),
         UINT16_C( 31245),  UINT16_C( 39114),  UINT16_C( 62940),  UINT16_C( 34994) },
      {  UINT16_C( 50329),  UINT16_C( 17974),  UINT16_C( 51507),  UINT16_C( 48961),
         UINT16_C(  5125),  UINT16_C( 27467),  UINT16_C( 14619),  UINT16_C( 34523) },
      {  UINT16_C( 59894),  UINT16_C( 37888),  UINT16_C( 24617),  UINT16_C( 10162),
         UINT16_C(  9149),  UINT16_C( 53682),  UINT16_C(  8403),  UINT16_C( 42540) },
      {  UINT16_C(  4589),  UINT16_C( 38278),  UINT16_C(  3739),  UINT16_C(  9453),
         UINT16_C( 19893),  UINT16_C(  8755),  UINT16_C( 60436),  UINT16_C( 43077) } },
    { {  UINT16_C( 53263),  UINT16_C( 18285),  UINT16_C( 62427),  UINT16_C( 19451),
         UINT16_C( 24240),  UINT16_C( 21045),  UINT16_C( 46605),  UINT16_C( 18144) },
      {  UINT16_C(  9679),  UINT16_C( 62998),  UINT16_C( 57275),  UINT16_C( 12636),
         UINT16_C( 27053),  UINT16_C( 54896),  UINT16_C( 30187),  UINT16_C( 62037) },
      {  UINT16_C( 55281),  UINT16_C( 36612),  UINT16_C( 50508),  UINT16_C( 52758),
         UINT16_C(  7094),  UINT16_C( 41624),  UINT16_C( 39592),  UINT16_C( 34930) },
      {  UINT16_C(  8753),  UINT16_C( 15999),  UINT16_C( 59692),  UINT16_C( 46257),
         UINT16_C( 11435),  UINT16_C(  9949),  UINT16_C( 22862),  UINT16_C( 15559) } },
    { {  UINT16_C( 20292),  UINT16_C( 28381),  UINT16_C( 46857),  UINT16_C( 15125),
         UINT16_C( 49563),  UINT16_C( 45103),  UINT16_C( 15357),  UINT16_C(  5330) },
      {  UINT16_C( 12283),  UINT16_C( 50104),  UINT16_C( 37154),  UINT16_C( 26627),
         UINT16_C( 44117),  UINT16_C( 54642),  UINT16_C( 25189),  UINT16_C( 30440) },
      {  UINT16_C(  5858),  UINT16_C(  4305),  UINT16_C( 15199),  UINT16_C( 57383),
         UINT16_C( 43760),  UINT16_C( 39917),  UINT16_C( 25683),  UINT16_C( 21377) },
      {  UINT16_C( 30301),  UINT16_C( 48564),  UINT16_C(  7540),  UINT16_C( 45873),
         UINT16_C( 51006),  UINT16_C( 65200),  UINT16_C( 15819),  UINT16_C( 12731) } },
    { {  UINT16_C( 11747),  UINT16_C( 54897),  UINT16_C( 52487),  UINT16_C( 56943),
         UINT16_C( 55056),  UINT16_C(  9940),  UINT16_C( 26317),  UINT16_C( 39722) },
      {  UINT16_C( 46519),  UINT16_C( 42905),  UINT16_C(  2403),  UINT16_C( 49785),
         UINT16_C( 34447),  UINT16_C( 61906),  UINT16_C( 38767),  UINT16_C( 53921) },
      {  UINT16_C( 36373),  UINT16_C( 43329),  UINT16_C( 14660),  UINT16_C( 23356),
         UINT16_C( 49448),  UINT16_C( 51062),  UINT16_C( 24622),  UINT16_C( 57759) },
      {  UINT16_C(  5697),  UINT16_C( 55465),  UINT16_C( 64800),  UINT16_C( 18218),
         UINT16_C( 37047),  UINT16_C(  4208),  UINT16_C( 37260),  UINT16_C( 43028) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t c = simde_vld1q_u16(test_vec[i].c);
    simde_uint16x8_t r = simde_veor3q_u16(a, b, c);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t c = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_veor3q_u16(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor3q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(   843215131),  UINT32_C(  3866566428),  UINT32_C(  1947840367),  UINT32_C(  3786488939) },
      {  UINT32_C(  3719147548),  UINT32_C(  1760167158),  UINT32_C(  1580913685),  UINT32_C(  3332806574) },
      {  UINT32_C(  3819024858),  UINT32_C(  2656503815),  UINT32_C(  4284316936),  UINT32_C(  3976602288) },
      {  UINT32_C(   206467293),  UINT32_C(   281678829),  UINT32_C(  3581806194),  UINT32_C(  3390146933) } },
    { {  UINT32_C(  4139040200),  UINT32_C(   201161944),  UINT32_C(  2117222144),  UINT32_C(   472410148) },
      {  UINT32_C(  2125024737),  UINT32_C(  2961454310),  UINT32_C(  3828503515),  UINT32_C(  1140365072) },
      {  UINT32_C(  1274885815),  UINT32_C(  2731153068),  UINT32_C(  2784912189),  UINT32_C(  2670567068) },
      {  UINT32_C(  3286288030),  UINT32_C(   431185554),  UINT32_C(  1073614822),  UINT32_C(  3237831080) } },
    { {  UINT32_C(  2458769212),  UINT32_C(  4145112773),  UINT32_C(  2874380209),  UINT32_C(  2642481746) },
      {  UINT32_C(  1699889681),  UINT32_C(   144747563),  UINT32_C(  3920565408),  UINT32_C(  3221343758) },
      {  UINT32_C(  1137217253),  UINT32_C(  2556645741),  UINT32_C(  1860056769),  UINT32_C(   698065330) },
      {  UINT32_C(  3021413320),  UINT32_C(  1741855619),  UINT32_C(   740470224),  UINT32_C(  1947958766) } },
    { {  UINT32_C(  4265621147),  UINT32_C(  1825155554),  UINT32_C(  3243365392),  UINT32_C(  3803216035) },
      {  UINT32_C(  1403767697),  UINT32_C(   755186630),  UINT32_C(  1861156221),  UINT32_C(  1262355872) },
      {  UINT32_C(  2473817220),  UINT32_C(  1524966613),  UINT32_C(  1923417143),  UINT32_C(   202780399) },
      {  UINT32_C(  1050184078),  UINT32_C(   456111857),  UINT32_C(  3709480282),  UINT32_C(  2778223596) } },
    { {  UINT32_C(  2881671318),  UINT32_C(  4075981168),  UINT32_C(   231097434),  UINT32_C(   612384700) },
      {  UINT32_C(  3774108151),  UINT32_C(   798316839),  UINT32_C(  1758588895),  UINT32_C(  3689237095) },
      {  UINT32_C(  3761064862),  UINT32_C(  3041285703),  UINT32_C(   310076088),  UINT32_C(  2498838969) },
      {  UINT32_C(  2870725375),  UINT32_C(  1747027472),  UINT32_C(  2003618109),  UINT32_C(  1804874850) } },
    { {  UINT32_C(  1311728570),  UINT32_C(   618062396),  UINT32_C(  2361764169),  UINT32_C(  3834962668) },
      {  UINT32_C(  4138716304),  UINT32_C(  2648050455),  UINT32_C(  3179013165),  UINT32_C(  4228871820) },
      {  UINT32_C(  3627719815),  UINT32_C(  2072104149),  UINT32_C(   801826790),  UINT32_C(  2006361875) },
      {  UINT32_C(  1622815661),  UINT32_C(  3263243774),  UINT32_C(   510962306),  UINT32_C(  1863136115) } },
    { {  UINT32_C(  3230346926),  UINT32_C(  3145464103),  UINT32_C(  1195212378),  UINT32_C(  4032328089) },
      {  UINT32_C(  3593267955),  UINT32_C(  1099568454),  UINT32_C(  1089498356),  UINT32_C(  1355351951) },
      {  UINT32_C(  1373049958),  UINT32_C(  1767135056),  UINT32_C(  4184788386),  UINT32_C(  3198051800) },
      {  UINT32_C(  1198575675),  UINT32_C(  2477112113),  UINT32_C(  4272152332),  UINT32_C(   504304590) } },
    { {  UINT32_C(  1323413943),  UINT32_C(  4268972056),  UINT32_C(  1305045526),  UINT32_C(  1569930076) },
      {  UINT32_C(  4074440169),  UINT32_C(  2321224011),  UINT32_C(  3450441520),  UINT32_C(   963251849) },
      {  UINT32_C(   260632415),  UINT32_C(  3254914257),  UINT32_C(  3838826570),  UINT32_C(  1770468022) },
      {  UINT32_C(  3014810369),  UINT32_C(  3056223618),  UINT32_C(  1689206124),  UINT32_C(   226363235) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_veor3q_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_veor3q_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_veor3q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t c[2];
    uint64_t r[2];
  } test_vec[] = {
    { {  UINT64_C(11274400154395273125),  UINT64_C(10066731318148799308) },
      {  UINT64_C(15655661589405857949),  UINT64_C( 8126377322109459558) },
      {  UINT64_C(15514808597378472621),  UINT64_C( 7889212627966398467) },
      {  UINT64_C(10555608802265007509),  UINT64_C(10812749922636814121) } },
    { {  UINT64_C( 2050954254440496548),  UINT64_C(16526205598513905590) },
      {  UINT64_C( 8190378367000459362),  UINT64_C( 7903450250757221969) },
      {  UINT64_C( 5769619313858873395),  UINT64_C( 5893042116476814603) },
      {  UINT64_C( 4453404239964786165),  UINT64_C(15653976685259347180) } },
    { {  UINT64_C( 8517163725900308201),  UINT64_C(16443544518475974090) },
      {  UINT64_C(  209233032144328434),  UINT64_C(11459034547188453965) },
      {  UINT64_C(16332694737289659590),  UINT64_C( 5974940278266169019) },
      {  UINT64_C(10843876570772671709),  UINT64_C( 3017094187942629692) } },
    { {  UINT64_C(10073013071816028672),  UINT64_C(12774299964861192426) },
      {  UINT64_C(  296402288183862113),  UINT64_C(10343739885431255320) },
      {  UINT64_C(  691382421363176968),  UINT64_C( 2051549301639670901) },
      {  UINT64_C( 9678175043132532585),  UINT64_C( 2500526404447470983) } },
    { {  UINT64_C(17116407731590111933),  UINT64_C( 8854743651944930102) },
      {  UINT64_C( 2883069968479473436),  UINT64_C(10897014261805898310) },
      {  UINT64_C(14509020297920463556),  UINT64_C( 7720009187724093977) },
      {  UINT64_C(  923642473115692901),  UINT64_C( 9725907844625541993) } },
    { {  UINT64_C( 6639078557697559187),  UINT64_C( 2182235150926090867) },
      {  UINT64_C(11114575925570722654),  UINT64_C( 6254092249140698816) },
      {  UINT64_C( 4549221190652162050),  UINT64_C(12765473632657876503) },
      {  UINT64_C(17959877845026726351),  UINT64_C(17990251238820424356) } },
    { {  UINT64_C(12128286942776665957),  UINT64_C( 1733154577086051428) },
      {  UINT64_C( 2301194843692634189),  UINT64_C( 3812904174298061595) },
      {  UINT64_C(17776711066627978110),  UINT64_C( 7645970699668967330) },
      {  UINT64_C( 4687324397003408470),  UINT64_C( 5115173377853481181) } },
    { {  UINT64_C(11147170235343580474),  UINT64_C( 3050478870791150299) },
      {  UINT64_C( 1622743165434529846),  UINT64_C( 8624814652361837615) },
      {  UINT64_C(14213277097369472583),  UINT64_C(12709132088678418812) },
      {  UINT64_C( 5262496006376401739),  UINT64_C(17130546365483048840) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t c = simde_vld1q_u64(test_vec[i].c);
    simde_uint64x2_t r = simde_veor3q_u64(a, b, c);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t c = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_veor3q_u64(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(veor_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(veor_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(veor_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(veor_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(veor_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(veor_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(veor_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(veor_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(veorq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(veorq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(veorq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(veorq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(veorq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(veorq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(veorq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(veorq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(veor3q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(veor3q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(veor3q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(veor3q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(veor3q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(veor3q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(veor3q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(veor3q_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
