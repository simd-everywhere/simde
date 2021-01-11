#define SIMDE_TEST_ARM_NEON_INSN mul

#include "test-neon.h"
#include "../../../simde/arm/neon/mul.h"

static int
test_simde_vmul_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -984.85), SIMDE_FLOAT32_C(   239.90) },
      { SIMDE_FLOAT32_C(  -108.56), SIMDE_FLOAT32_C(   891.83) },
      { SIMDE_FLOAT32_C(106915.31), SIMDE_FLOAT32_C(213950.02) } },
    { { SIMDE_FLOAT32_C(   288.24), SIMDE_FLOAT32_C(  -869.25) },
      { SIMDE_FLOAT32_C(  -156.82), SIMDE_FLOAT32_C(   921.87) },
      { SIMDE_FLOAT32_C(-45201.80), SIMDE_FLOAT32_C(-801335.50) } },
    { { SIMDE_FLOAT32_C(  -879.78), SIMDE_FLOAT32_C(  -268.41) },
      { SIMDE_FLOAT32_C(  -165.21), SIMDE_FLOAT32_C(  -936.42) },
      { SIMDE_FLOAT32_C(145348.47), SIMDE_FLOAT32_C(251344.48) } },
    { { SIMDE_FLOAT32_C(   385.59), SIMDE_FLOAT32_C(  -229.84) },
      { SIMDE_FLOAT32_C(   996.35), SIMDE_FLOAT32_C(  -804.89) },
      { SIMDE_FLOAT32_C(384182.59), SIMDE_FLOAT32_C(184995.92) } },
    { { SIMDE_FLOAT32_C(   339.75), SIMDE_FLOAT32_C(  -605.97) },
      { SIMDE_FLOAT32_C(   882.89), SIMDE_FLOAT32_C(   300.48) },
      { SIMDE_FLOAT32_C(299961.88), SIMDE_FLOAT32_C(-182081.86) } },
    { { SIMDE_FLOAT32_C(  -227.17), SIMDE_FLOAT32_C(   998.92) },
      { SIMDE_FLOAT32_C(  -867.68), SIMDE_FLOAT32_C(   668.07) },
      { SIMDE_FLOAT32_C(197110.86), SIMDE_FLOAT32_C(667348.50) } },
    { { SIMDE_FLOAT32_C(   105.88), SIMDE_FLOAT32_C(  -369.44) },
      { SIMDE_FLOAT32_C(   748.88), SIMDE_FLOAT32_C(   812.67) },
      { SIMDE_FLOAT32_C( 79291.41), SIMDE_FLOAT32_C(-300232.81) } },
    { { SIMDE_FLOAT32_C(  -814.69), SIMDE_FLOAT32_C(   -31.04) },
      { SIMDE_FLOAT32_C(  -710.62), SIMDE_FLOAT32_C(  -799.54) },
      { SIMDE_FLOAT32_C(578935.00), SIMDE_FLOAT32_C( 24817.72) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vmul_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmul_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(-859.012888) },
      { SIMDE_FLOAT64_C(808.899130) },
      { SIMDE_FLOAT64_C(-694854.777259) } },
    { { SIMDE_FLOAT64_C(-512.686665) },
      { SIMDE_FLOAT64_C(364.360016) },
      { SIMDE_FLOAT64_C(-186802.521685) } },
    { { SIMDE_FLOAT64_C(429.047777) },
      { SIMDE_FLOAT64_C(643.143308) },
      { SIMDE_FLOAT64_C(275939.206701) } },
    { { SIMDE_FLOAT64_C(515.485107) },
      { SIMDE_FLOAT64_C(158.472572) },
      { SIMDE_FLOAT64_C(81690.250725) } },
    { { SIMDE_FLOAT64_C(-433.956881) },
      { SIMDE_FLOAT64_C(78.045774) },
      { SIMDE_FLOAT64_C(-33868.500567) } },
    { { SIMDE_FLOAT64_C(-998.339714) },
      { SIMDE_FLOAT64_C(751.053657) },
      { SIMDE_FLOAT64_C(-749806.693756) } },
    { { SIMDE_FLOAT64_C(735.460464) },
      { SIMDE_FLOAT64_C(670.199813) },
      { SIMDE_FLOAT64_C(492905.465423) } },
    { { SIMDE_FLOAT64_C(190.192630) },
      { SIMDE_FLOAT64_C(-439.362447) },
      { SIMDE_FLOAT64_C(-83563.499287) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vmul_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmul_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C( 106),  INT8_C(  59),  INT8_C(  38),  INT8_C(  92),  INT8_C( 101), -INT8_C(  69),  INT8_C(  33), -INT8_C( 125) },
      {  INT8_C( 116),  INT8_C(   9),  INT8_C( 111), -INT8_C(  27), -INT8_C(  82), -INT8_C(  53), -INT8_C(  72), -INT8_C(  89) },
      {  INT8_C(   8),  INT8_C(  19),  INT8_C( 122),  INT8_C(  76), -INT8_C(  90),  INT8_C(  73), -INT8_C(  72),  INT8_C( 117) } },
    { { -INT8_C(  49),  INT8_C( 114), -INT8_C( 110), -INT8_C(  77),  INT8_C(  44), -INT8_C( 114), -INT8_C(  19), -INT8_C(  70) },
      { -INT8_C( 124),  INT8_C( 116), -INT8_C(  15), -INT8_C(  94),  INT8_C( 118),  INT8_C( 102),  INT8_C(  35), -INT8_C(  31) },
      { -INT8_C(  68), -INT8_C(  88),  INT8_C( 114),  INT8_C(  70),  INT8_C(  72), -INT8_C( 108),  INT8_C( 103),  INT8_C( 122) } },
    { { -INT8_C(  95),  INT8_C(  73),  INT8_C(  61),  INT8_C(   7),  INT8_C(   4),  INT8_C(  94), -INT8_C( 118),  INT8_C( 120) },
      {  INT8_C( 104), -INT8_C(   6),  INT8_C(  93),  INT8_C(  22), -INT8_C(  59),  INT8_C(  21), -INT8_C(  67), -INT8_C( 108) },
      {  INT8_C( 104),  INT8_C(  74),  INT8_C(  41), -INT8_C( 102),  INT8_C(  20), -INT8_C(  74), -INT8_C(  30),  INT8_C(  96) } },
    { { -INT8_C( 121),  INT8_C(  80),  INT8_C(  71), -INT8_C(  76), -INT8_C(  34),  INT8_C(  52),  INT8_C( 110),  INT8_C(  99) },
      { -INT8_C(  88),  INT8_C(  96),  INT8_C(   5),  INT8_C(  31), -INT8_C(  58),  INT8_C(  40),  INT8_C(   0),  INT8_C( 104) },
      { -INT8_C( 104),  INT8_C(   0),  INT8_C(  99), -INT8_C(  52), -INT8_C(  76),  INT8_C(  32),  INT8_C(   0),  INT8_C(  56) } },
    { {  INT8_C( 113),  INT8_C(  61),  INT8_C( 111),  INT8_C( 117), -INT8_C( 101), -INT8_C(   7), -INT8_C(  19),  INT8_C(   3) },
      { -INT8_C(  13),  INT8_C(  75),  INT8_C(  25), -INT8_C(  72),  INT8_C(  96), -INT8_C(  41),  INT8_C(  76), -INT8_C(  24) },
      {  INT8_C(  67), -INT8_C(  33), -INT8_C(  41),  INT8_C(  24),  INT8_C(  32),  INT8_C(  31),  INT8_C(  92), -INT8_C(  72) } },
    { {  INT8_C(  39), -INT8_C( 109), -INT8_C( 100),  INT8_C(   5), -INT8_C(  56),  INT8_C(  10),  INT8_C( 104),  INT8_C( 112) },
      {  INT8_C( 106),  INT8_C( 109), -INT8_C( 113),  INT8_C(  49), -INT8_C( 107), -INT8_C( 113), -INT8_C( 103),  INT8_C(   6) },
      {  INT8_C(  38), -INT8_C( 105),  INT8_C(  36), -INT8_C(  11),  INT8_C( 104), -INT8_C( 106),  INT8_C(  40), -INT8_C(  96) } },
    { { -INT8_C(  52),  INT8_C(   8),  INT8_C( 123),  INT8_C( 104),  INT8_C(   1),  INT8_C( 105),  INT8_C( 107), -INT8_C(  11) },
      { -INT8_C(  76), -INT8_C( 123), -INT8_C(  83),  INT8_C(  20),  INT8_C(  92), -INT8_C(   6), -INT8_C(   4), -INT8_C( 125) },
      {  INT8_C( 112),  INT8_C(  40),  INT8_C(  31),  INT8_C(  32),  INT8_C(  92), -INT8_C( 118),  INT8_C(  84),  INT8_C(  95) } },
    { { -INT8_C( 115), -INT8_C( 104), -INT8_C( 120),  INT8_C(  85), -INT8_C(  93), -INT8_C(  15), -INT8_C(  58),  INT8_C(  13) },
      {  INT8_C(  94),  INT8_C(  85),  INT8_C(  62), -INT8_C(  12), -INT8_C(  27), -INT8_C(  41), -INT8_C(   6), -INT8_C(  79) },
      { -INT8_C(  58),  INT8_C( 120), -INT8_C(  16),  INT8_C(   4), -INT8_C(  49),  INT8_C( 103),  INT8_C(  92), -INT8_C(   3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vmul_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmul_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  1153),  INT16_C(  9267),  INT16_C( 13091), -INT16_C( 11549) },
      {  INT16_C( 16786),  INT16_C( 22839), -INT16_C( 14400),  INT16_C( 22119) },
      { -INT16_C( 21138), -INT16_C( 32267), -INT16_C( 28864),  INT16_C(  6997) } },
    { {  INT16_C(  1251),  INT16_C( 20541), -INT16_C( 32133),  INT16_C( 24648) },
      { -INT16_C( 27063),  INT16_C( 19566), -INT16_C( 16105), -INT16_C( 27036) },
      {  INT16_C( 26299), -INT16_C( 27082),  INT16_C( 29709), -INT16_C( 13280) } },
    { { -INT16_C( 26692), -INT16_C(  8262), -INT16_C( 25142),  INT16_C( 23730) },
      { -INT16_C(  5666), -INT16_C( 24907),  INT16_C(  7345), -INT16_C( 27404) },
      { -INT16_C( 20216), -INT16_C(  1406),  INT16_C( 12458),  INT16_C( 16808) } },
    { {  INT16_C( 12577), -INT16_C( 25372),  INT16_C( 11444), -INT16_C(   516) },
      {  INT16_C( 27331), -INT16_C(  9655), -INT16_C( 21204), -INT16_C(  6032) },
      {  INT16_C(  5667), -INT16_C(  6908),  INT16_C( 21232),  INT16_C( 32320) } },
    { {  INT16_C( 10820),  INT16_C(  3784),  INT16_C( 31431), -INT16_C( 23190) },
      {  INT16_C(  8035),  INT16_C(  5187),  INT16_C( 14139),  INT16_C( 23721) },
      { -INT16_C( 27572),  INT16_C( 32344),  INT16_C(  3293),  INT16_C( 19194) } },
    { { -INT16_C( 29336),  INT16_C(  7417), -INT16_C(  2630),  INT16_C( 32025) },
      {  INT16_C( 25184), -INT16_C( 29609), -INT16_C( 14577),  INT16_C( 21364) },
      { -INT16_C( 10496),  INT16_C(  1183), -INT16_C(  1050), -INT16_C( 13740) } },
    { {  INT16_C( 15601), -INT16_C( 18335), -INT16_C( 13386),  INT16_C(  6749) },
      { -INT16_C( 24342),  INT16_C(  9774), -INT16_C( 10281),  INT16_C( 16258) },
      {  INT16_C( 21578), -INT16_C( 30866), -INT16_C(  4134),  INT16_C( 17978) } },
    { {  INT16_C( 31589),  INT16_C(  8028),  INT16_C( 30065), -INT16_C( 11876) },
      { -INT16_C(  3112), -INT16_C(  6307), -INT16_C( 11846), -INT16_C( 21701) },
      { -INT16_C(   968),  INT16_C( 26732), -INT16_C( 27366), -INT16_C( 32012) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vmul_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmul_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1902437050), -INT32_C(  1986881182) },
      { -INT32_C(   584919357),  INT32_C(   952226700) },
      {  INT32_C(  1679044526),  INT32_C(   595175320) } },
    { { -INT32_C(  1394667052), -INT32_C(  1073928011) },
      { -INT32_C(   106226047), -INT32_C(   865115374) },
      {  INT32_C(  1562039252),  INT32_C(  1225120698) } },
    { { -INT32_C(  1489120443),  INT32_C(   791727980) },
      {  INT32_C(   839668390), -INT32_C(   110441179) },
      { -INT32_C(  1593894722), -INT32_C(   689998180) } },
    { { -INT32_C(  1817883938), -INT32_C(   212622478) },
      { -INT32_C(   739377471), -INT32_C(  1499505567) },
      { -INT32_C(  1720994466), -INT32_C(  1321474510) } },
    { { -INT32_C(  1689396177),  INT32_C(  1372224939) },
      { -INT32_C(   192686129), -INT32_C(  2081493340) },
      {  INT32_C(  1877836545), -INT32_C(    58229876) } },
    { { -INT32_C(  1441361096), -INT32_C(   140678858) },
      { -INT32_C(   926250393),  INT32_C(   359557606) },
      { -INT32_C(  2069795960), -INT32_C(  1429754748) } },
    { { -INT32_C(   240075963),  INT32_C(   121797432) },
      { -INT32_C(   151206318), -INT32_C(   327554380) },
      { -INT32_C(  1050715622), -INT32_C(  1126706336) } },
    { { -INT32_C(  1265201027),  INT32_C(  1638609913) },
      { -INT32_C(  1540786498),  INT32_C(   632985823) },
      { -INT32_C(  1503798586),  INT32_C(  2062032359) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vmul_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_vmul_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 6852233445081966377) },
      {  INT64_C(  949766532573427103) },
      {  INT64_C( 3051662338158473353) } },
    { {  INT64_C( 4361299594231041259) },
      { -INT64_C( 4420890052168132134) },
      {  INT64_C( 4739764582358168350) } },
    { {  INT64_C( 1444579558535101295) },
      { -INT64_C( 3616007996289735901) },
      { -INT64_C( 1463454656528282323) } },
    { {  INT64_C( 5747443551797445544) },
      { -INT64_C( 9184083115752015394) },
      {  INT64_C( 6787112144328823728) } },
    { {  INT64_C( 2493297645073518865) },
      { -INT64_C( 3869798096008984677) },
      { -INT64_C( 2727157459429045173) } },
    { { -INT64_C( 5945009003509396806) },
      {  INT64_C( 1648038210740580174) },
      {  INT64_C(  970083354321644204) } },
    { {  INT64_C( 6842152849050946515) },
      {  INT64_C( 5469947826171337468) },
      { -INT64_C( 8410656588808695372) } },
    { { -INT64_C( 6958067674496943118) },
      { -INT64_C( 4934575301326870935) },
      {  INT64_C( 6969990240459227714) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_x_vmul_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_x_vmul_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 24), UINT8_C(211), UINT8_C(229), UINT8_C( 35), UINT8_C(121), UINT8_C(154), UINT8_C(180), UINT8_C( 84) },
      { UINT8_C(  5), UINT8_C(153), UINT8_C(140), UINT8_C( 32), UINT8_C( 16), UINT8_C(217), UINT8_C(232), UINT8_C(155) },
      { UINT8_C(120), UINT8_C( 27), UINT8_C( 60), UINT8_C( 96), UINT8_C(144), UINT8_C(138), UINT8_C( 32), UINT8_C(220) } },
    { { UINT8_C( 45), UINT8_C(107), UINT8_C( 56), UINT8_C(203), UINT8_C(110), UINT8_C(126), UINT8_C(239), UINT8_C(144) },
      { UINT8_C( 35), UINT8_C(237), UINT8_C(204), UINT8_C(112), UINT8_C( 65), UINT8_C( 80), UINT8_C(228), UINT8_C( 89) },
      { UINT8_C( 39), UINT8_C( 15), UINT8_C(160), UINT8_C(208), UINT8_C(238), UINT8_C( 96), UINT8_C(220), UINT8_C( 16) } },
    { { UINT8_C( 35), UINT8_C(201), UINT8_C(124), UINT8_C(156), UINT8_C( 99), UINT8_C( 48), UINT8_C(240), UINT8_C(105) },
      { UINT8_C(202), UINT8_C(124), UINT8_C(137), UINT8_C(218), UINT8_C( 86), UINT8_C(113), UINT8_C(117), UINT8_C(131) },
      { UINT8_C(158), UINT8_C( 92), UINT8_C( 92), UINT8_C(216), UINT8_C( 66), UINT8_C( 48), UINT8_C(176), UINT8_C(187) } },
    { { UINT8_C(220), UINT8_C(173), UINT8_C( 78), UINT8_C( 75), UINT8_C( 44), UINT8_C( 62), UINT8_C(219), UINT8_C( 79) },
      { UINT8_C( 43), UINT8_C(167), UINT8_C(191), UINT8_C(108), UINT8_C(248), UINT8_C(164), UINT8_C(197), UINT8_C( 27) },
      { UINT8_C(244), UINT8_C(219), UINT8_C( 50), UINT8_C(164), UINT8_C(160), UINT8_C(184), UINT8_C(135), UINT8_C( 85) } },
    { { UINT8_C(109), UINT8_C( 65), UINT8_C(184), UINT8_C(209), UINT8_C(113), UINT8_C(168), UINT8_C( 58), UINT8_C( 59) },
      { UINT8_C( 37), UINT8_C(195), UINT8_C( 21), UINT8_C(123), UINT8_C( 53), UINT8_C(138), UINT8_C(254), UINT8_C( 17) },
      { UINT8_C(193), UINT8_C(131), UINT8_C( 24), UINT8_C(107), UINT8_C(101), UINT8_C(144), UINT8_C(140), UINT8_C(235) } },
    { { UINT8_C( 56), UINT8_C( 76), UINT8_C( 92), UINT8_C(100), UINT8_C(138), UINT8_C( 55), UINT8_C(179), UINT8_C(181) },
      { UINT8_C(223), UINT8_C(115), UINT8_C( 33), UINT8_C(215), UINT8_C( 23), UINT8_C(230), UINT8_C(242), UINT8_C(132) },
      { UINT8_C(200), UINT8_C( 36), UINT8_C(220), UINT8_C(252), UINT8_C(102), UINT8_C(106), UINT8_C( 54), UINT8_C( 84) } },
    { { UINT8_C( 39), UINT8_C(170), UINT8_C( 85), UINT8_C(153), UINT8_C( 83), UINT8_C(143), UINT8_C(212), UINT8_C(120) },
      { UINT8_C( 83), UINT8_C(234), UINT8_C(243), UINT8_C(136), UINT8_C(116), UINT8_C(241), UINT8_C(153), UINT8_C(172) },
      { UINT8_C(165), UINT8_C(100), UINT8_C(175), UINT8_C( 72), UINT8_C(156), UINT8_C(159), UINT8_C(180), UINT8_C(160) } },
    { { UINT8_C( 61), UINT8_C(246), UINT8_C( 16), UINT8_C(200), UINT8_C( 45), UINT8_C(196), UINT8_C(125), UINT8_C( 12) },
      { UINT8_C( 55), UINT8_C(159), UINT8_C(227), UINT8_C( 78), UINT8_C(133), UINT8_C(214), UINT8_C(210), UINT8_C(173) },
      { UINT8_C( 27), UINT8_C(202), UINT8_C( 48), UINT8_C(240), UINT8_C( 97), UINT8_C(216), UINT8_C(138), UINT8_C( 28) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vmul_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmul_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(26526), UINT16_C( 3086), UINT16_C(48363), UINT16_C( 5470) },
      { UINT16_C(17470), UINT16_C(33907), UINT16_C(19149), UINT16_C(42742) },
      { UINT16_C( 4164), UINT16_C(41546), UINT16_C(13871), UINT16_C(31828) } },
    { { UINT16_C(19501), UINT16_C(28414), UINT16_C( 6061), UINT16_C(12929) },
      { UINT16_C(38218), UINT16_C( 4045), UINT16_C(45293), UINT16_C(35808) },
      { UINT16_C(13826), UINT16_C(50022), UINT16_C(56105), UINT16_C(15328) } },
    { { UINT16_C(61207), UINT16_C(  664), UINT16_C(63147), UINT16_C(59672) },
      { UINT16_C(35642), UINT16_C( 1902), UINT16_C(25813), UINT16_C(  942) },
      { UINT16_C(43062), UINT16_C(17744), UINT16_C( 2119), UINT16_C(46672) } },
    { { UINT16_C(44209), UINT16_C(24177), UINT16_C(62147), UINT16_C( 3472) },
      { UINT16_C(23944), UINT16_C(29980), UINT16_C(64781), UINT16_C( 9472) },
      { UINT16_C( 2824), UINT16_C(63836), UINT16_C( 2791), UINT16_C(53248) } },
    { { UINT16_C(39148), UINT16_C(38695), UINT16_C(16270), UINT16_C(51585) },
      { UINT16_C(61387), UINT16_C(41168), UINT16_C(32339), UINT16_C( 1187) },
      { UINT16_C(38692), UINT16_C(12208), UINT16_C(32522), UINT16_C(20771) } },
    { { UINT16_C( 5163), UINT16_C(61026), UINT16_C(61959), UINT16_C(36860) },
      { UINT16_C( 6223), UINT16_C(23812), UINT16_C( 1045), UINT16_C(  386) },
      { UINT16_C(16709), UINT16_C(21384), UINT16_C(63123), UINT16_C( 6648) } },
    { { UINT16_C(43421), UINT16_C(11161), UINT16_C( 6889), UINT16_C(46324) },
      { UINT16_C(50441), UINT16_C(23636), UINT16_C(63555), UINT16_C(28257) },
      { UINT16_C(51077), UINT16_C(18996), UINT16_C(49915), UINT16_C(26740) } },
    { { UINT16_C(49932), UINT16_C( 4957), UINT16_C(22966), UINT16_C( 1442) },
      { UINT16_C(42609), UINT16_C(34658), UINT16_C(58539), UINT16_C(18568) },
      { UINT16_C(57420), UINT16_C(29850), UINT16_C( 1170), UINT16_C(36368) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vmul_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmul_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3631289062), UINT32_C(1255180013) },
      { UINT32_C(3711528889), UINT32_C(4134291800) },
      { UINT32_C( 874406454), UINT32_C(3626235512) } },
    { { UINT32_C(2370034702), UINT32_C(1186131006) },
      { UINT32_C(2414703895), UINT32_C(4202144275) },
      { UINT32_C(1067526978), UINT32_C(3583558810) } },
    { { UINT32_C(2731731124), UINT32_C( 686596719) },
      { UINT32_C(1778787601), UINT32_C(2103472751) },
      { UINT32_C(1205565428), UINT32_C( 999283745) } },
    { { UINT32_C(2349507406), UINT32_C(2815671695) },
      { UINT32_C(1177993266), UINT32_C( 390114658) },
      { UINT32_C( 453141820), UINT32_C(2464691134) } },
    { { UINT32_C(  79237781), UINT32_C(3308103092) },
      { UINT32_C( 976171979), UINT32_C(4088893605) },
      { UINT32_C(3369102119), UINT32_C( 323816708) } },
    { { UINT32_C(3279929651), UINT32_C(2976535166) },
      { UINT32_C(1979162643), UINT32_C(3800840013) },
      { UINT32_C( 309343945), UINT32_C(2375803366) } },
    { { UINT32_C(4259792201), UINT32_C(3066172651) },
      { UINT32_C(3975213639), UINT32_C(3051333506) },
      { UINT32_C(1259551039), UINT32_C(3387485270) } },
    { { UINT32_C(3883425384), UINT32_C(3298353841) },
      { UINT32_C(3476656002), UINT32_C( 263374534) },
      { UINT32_C(3842246864), UINT32_C(1269185254) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vmul_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_vmul_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 9501235154748714381) },
      { UINT64_C( 6872502071409485626) },
      { UINT64_C( 5840718951435488498) } },
    { { UINT64_C(16836630811398367501) },
      { UINT64_C( 1040243009521352130) },
      { UINT64_C( 3736209579242157274) } },
    { { UINT64_C( 1542624550018396125) },
      { UINT64_C(18212347914471204647) },
      { UINT64_C(  150701147483813291) } },
    { { UINT64_C(  475528078903446059) },
      { UINT64_C(13868812939453805543) },
      { UINT64_C(13365877717431238093) } },
    { { UINT64_C(14090089345526864794) },
      { UINT64_C(15627738843931896820) },
      { UINT64_C( 8057496985447148744) } },
    { { UINT64_C(17705374232516993899) },
      { UINT64_C(13400413542018855764) },
      { UINT64_C( 6886449617527500828) } },
    { { UINT64_C(11335481825455676656) },
      { UINT64_C(13738336576390328611) },
      { UINT64_C(15315597398385190096) } },
    { { UINT64_C(11819456772893978628) },
      { UINT64_C( 3111937016080328024) },
      { UINT64_C( 1531824312858580320) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_x_vmul_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_x_vmul_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(-875.908447), SIMDE_FLOAT32_C(-952.067810), SIMDE_FLOAT32_C(-835.896851), SIMDE_FLOAT32_C(-332.003418) },
      { SIMDE_FLOAT32_C(-353.433044), SIMDE_FLOAT32_C(411.022461), SIMDE_FLOAT32_C(-878.854858), SIMDE_FLOAT32_C(965.658569) },
      { SIMDE_FLOAT32_C(309575.000000), SIMDE_FLOAT32_C(-391321.250000), SIMDE_FLOAT32_C(734632.000000), SIMDE_FLOAT32_C(-320601.937500) } },
    { { SIMDE_FLOAT32_C(-818.029663), SIMDE_FLOAT32_C(-58.492615), SIMDE_FLOAT32_C(-314.083435), SIMDE_FLOAT32_C(-471.082703) },
      { SIMDE_FLOAT32_C(100.064087), SIMDE_FLOAT32_C(-957.928711), SIMDE_FLOAT32_C(680.392578), SIMDE_FLOAT32_C(301.457642) },
      { SIMDE_FLOAT32_C(-81855.390625), SIMDE_FLOAT32_C(56031.753906), SIMDE_FLOAT32_C(-213700.031250), SIMDE_FLOAT32_C(-142011.484375) } },
    { { SIMDE_FLOAT32_C(143.138428), SIMDE_FLOAT32_C(-445.185791), SIMDE_FLOAT32_C(108.660034), SIMDE_FLOAT32_C(-105.336975) },
      { SIMDE_FLOAT32_C(-543.193237), SIMDE_FLOAT32_C(437.742188), SIMDE_FLOAT32_C(569.496582), SIMDE_FLOAT32_C(-743.131836) },
      { SIMDE_FLOAT32_C(-77751.828125), SIMDE_FLOAT32_C(-194876.609375), SIMDE_FLOAT32_C(61881.519531), SIMDE_FLOAT32_C(78279.257812) } },
    { { SIMDE_FLOAT32_C(-259.595825), SIMDE_FLOAT32_C(409.617432), SIMDE_FLOAT32_C(718.381958), SIMDE_FLOAT32_C(310.151978) },
      { SIMDE_FLOAT32_C(521.223389), SIMDE_FLOAT32_C(-42.746582), SIMDE_FLOAT32_C(-267.409790), SIMDE_FLOAT32_C(645.314941) },
      { SIMDE_FLOAT32_C(-135307.421875), SIMDE_FLOAT32_C(-17509.746094), SIMDE_FLOAT32_C(-192102.375000), SIMDE_FLOAT32_C(200145.703125) } },
    { { SIMDE_FLOAT32_C(5.185669), SIMDE_FLOAT32_C(-103.306641), SIMDE_FLOAT32_C(-686.688354), SIMDE_FLOAT32_C(651.752686) },
      { SIMDE_FLOAT32_C(-692.284058), SIMDE_FLOAT32_C(-565.543213), SIMDE_FLOAT32_C(617.411255), SIMDE_FLOAT32_C(-510.313782) },
      { SIMDE_FLOAT32_C(-3589.956055), SIMDE_FLOAT32_C(58424.371094), SIMDE_FLOAT32_C(-423969.125000), SIMDE_FLOAT32_C(-332598.375000) } },
    { { SIMDE_FLOAT32_C(375.964233), SIMDE_FLOAT32_C(-696.671997), SIMDE_FLOAT32_C(18.603516), SIMDE_FLOAT32_C(-523.971558) },
      { SIMDE_FLOAT32_C(-654.600769), SIMDE_FLOAT32_C(-301.003845), SIMDE_FLOAT32_C(777.486084), SIMDE_FLOAT32_C(488.537720) },
      { SIMDE_FLOAT32_C(-246106.468750), SIMDE_FLOAT32_C(209700.953125), SIMDE_FLOAT32_C(14463.974609), SIMDE_FLOAT32_C(-255979.875000) } },
    { { SIMDE_FLOAT32_C(253.810303), SIMDE_FLOAT32_C(-113.853699), SIMDE_FLOAT32_C(-616.799194), SIMDE_FLOAT32_C(710.617065) },
      { SIMDE_FLOAT32_C(-676.111450), SIMDE_FLOAT32_C(952.697266), SIMDE_FLOAT32_C(967.485229), SIMDE_FLOAT32_C(64.292725) },
      { SIMDE_FLOAT32_C(-171604.046875), SIMDE_FLOAT32_C(-108468.109375), SIMDE_FLOAT32_C(-596744.125000), SIMDE_FLOAT32_C(45687.507812) } },
    { { SIMDE_FLOAT32_C(362.314941), SIMDE_FLOAT32_C(685.867310), SIMDE_FLOAT32_C(-625.555176), SIMDE_FLOAT32_C(-116.461548) },
      { SIMDE_FLOAT32_C(-356.879150), SIMDE_FLOAT32_C(107.035034), SIMDE_FLOAT32_C(-471.146545), SIMDE_FLOAT32_C(648.306519) },
      { SIMDE_FLOAT32_C(-129302.648438), SIMDE_FLOAT32_C(73411.828125), SIMDE_FLOAT32_C(294728.156250), SIMDE_FLOAT32_C(-75502.781250) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vmulq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmulq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(-110.548430), SIMDE_FLOAT64_C(608.512841) },
      { SIMDE_FLOAT64_C(736.040173), SIMDE_FLOAT64_C(-280.442189) },
      { SIMDE_FLOAT64_C(-81368.085325), SIMDE_FLOAT64_C(-170652.673215) } },
    { { SIMDE_FLOAT64_C(-149.158503), SIMDE_FLOAT64_C(-505.167299) },
      { SIMDE_FLOAT64_C(-802.637817), SIMDE_FLOAT64_C(-512.437647) },
      { SIMDE_FLOAT64_C(119720.254897), SIMDE_FLOAT64_C(258866.741888) } },
    { { SIMDE_FLOAT64_C(-15.761167), SIMDE_FLOAT64_C(-532.799363) },
      { SIMDE_FLOAT64_C(-516.739889), SIMDE_FLOAT64_C(-825.864527) },
      { SIMDE_FLOAT64_C(8144.423830), SIMDE_FLOAT64_C(440020.093999) } },
    { { SIMDE_FLOAT64_C(-142.146788), SIMDE_FLOAT64_C(-460.594133) },
      { SIMDE_FLOAT64_C(887.546627), SIMDE_FLOAT64_C(-409.867550) },
      { SIMDE_FLOAT64_C(-126161.902322), SIMDE_FLOAT64_C(188782.588915) } },
    { { SIMDE_FLOAT64_C(-230.600942), SIMDE_FLOAT64_C(-52.274368) },
      { SIMDE_FLOAT64_C(150.986619), SIMDE_FLOAT64_C(67.500747) },
      { SIMDE_FLOAT64_C(-34817.656482), SIMDE_FLOAT64_C(-3528.558923) } },
    { { SIMDE_FLOAT64_C(389.471275), SIMDE_FLOAT64_C(-747.723748) },
      { SIMDE_FLOAT64_C(-950.827661), SIMDE_FLOAT64_C(917.085530) },
      { SIMDE_FLOAT64_C(-370320.061840), SIMDE_FLOAT64_C(-685726.629746) } },
    { { SIMDE_FLOAT64_C(352.081057), SIMDE_FLOAT64_C(409.278147) },
      { SIMDE_FLOAT64_C(684.852159), SIMDE_FLOAT64_C(-854.134726) },
      { SIMDE_FLOAT64_C(241123.472398), SIMDE_FLOAT64_C(-349578.677755) } },
    { { SIMDE_FLOAT64_C(-169.233569), SIMDE_FLOAT64_C(-633.363110) },
      { SIMDE_FLOAT64_C(-43.526636), SIMDE_FLOAT64_C(720.218002) },
      { SIMDE_FLOAT64_C(7366.167936), SIMDE_FLOAT64_C(-456159.513343) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vmulq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmulq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  74),  INT8_C(  14),  INT8_C(  98), -INT8_C(  34),  INT8_C( 126),  INT8_C(  71), -INT8_C( 106), -INT8_C( 123),
        -INT8_C(  76),  INT8_C(  59), -INT8_C(  35),  INT8_C(  50),  INT8_C( 118), -INT8_C(  17),  INT8_C(  52),  INT8_C(  99) },
      {  INT8_C(  90),  INT8_C( 106), -INT8_C(  48), -INT8_C(  89),  INT8_C(   6), -INT8_C(  49),  INT8_C( 117), -INT8_C( 108),
        -INT8_C(  71),  INT8_C(  79),  INT8_C( 109), -INT8_C(  80), -INT8_C(  40),  INT8_C(  27),  INT8_C( 105), -INT8_C( 114) },
      { -INT8_C(   4), -INT8_C(  52), -INT8_C(  96), -INT8_C(  46), -INT8_C(  12),  INT8_C( 105), -INT8_C( 114), -INT8_C(  28),
         INT8_C(  20),  INT8_C(  53),  INT8_C(  25),  INT8_C(  96), -INT8_C( 112),  INT8_C(  53),  INT8_C(  84), -INT8_C(  22) } },
    { {  INT8_C(  41), -INT8_C(  53),  INT8_C( 108), -INT8_C(  89),  INT8_C(  18),  INT8_C(   3),  INT8_C(  44), -INT8_C(  58),
         INT8_C(  62),  INT8_C(  10), -INT8_C(   8), -INT8_C(  76), -INT8_C(   7),  INT8_C(  44),  INT8_C(  23),  INT8_C(  84) },
      { -INT8_C( 106), -INT8_C(  25), -INT8_C(   5), -INT8_C( 100), -INT8_C(  74),  INT8_C( 112),  INT8_C(  48),  INT8_C( 111),
        -INT8_C(  64), -INT8_C(  99),  INT8_C(  32), -INT8_C( 104), -INT8_C(  72), -INT8_C( 119),  INT8_C(  38), -INT8_C(  31) },
      {  INT8_C(   6),  INT8_C(  45), -INT8_C(  28), -INT8_C(  60), -INT8_C(  52),  INT8_C(  80),  INT8_C(  64), -INT8_C(  38),
             INT8_MIN,  INT8_C(  34),  INT8_C(   0), -INT8_C(  32), -INT8_C(   8), -INT8_C( 116),  INT8_C( 106), -INT8_C(  44) } },
    { {  INT8_C(  84), -INT8_C( 109), -INT8_C( 120),  INT8_C( 102), -INT8_C( 106), -INT8_C(  76),  INT8_C(  44), -INT8_C(  44),
        -INT8_C(  66),  INT8_C(  36), -INT8_C( 120), -INT8_C(  72),  INT8_C(  80), -INT8_C(  97),  INT8_C(  12), -INT8_C(  26) },
      { -INT8_C( 122),  INT8_C(   7), -INT8_C( 126),  INT8_C(  61),  INT8_C( 119), -INT8_C(  78), -INT8_C(  84),  INT8_C(  55),
         INT8_C(  79), -INT8_C(  52), -INT8_C(  49),  INT8_C(   7),  INT8_C(  85), -INT8_C(  10), -INT8_C(  24), -INT8_C(  87) },
      { -INT8_C(   8),  INT8_C(   5),  INT8_C(  16),  INT8_C(  78), -INT8_C(  70),  INT8_C(  40), -INT8_C( 112), -INT8_C( 116),
        -INT8_C(  94), -INT8_C(  80), -INT8_C(   8),  INT8_C(   8), -INT8_C( 112), -INT8_C(  54), -INT8_C(  32), -INT8_C(  42) } },
    { { -INT8_C( 119),  INT8_C( 112),  INT8_C(  15),  INT8_C(  31),  INT8_C(  36),  INT8_C(  59), -INT8_C(  13), -INT8_C(  29),
         INT8_C(  95),  INT8_C( 123), -INT8_C( 101), -INT8_C(  81),  INT8_C(  26), -INT8_C(  89), -INT8_C( 107), -INT8_C(  96) },
      { -INT8_C(  82),  INT8_C(  23), -INT8_C(  35),  INT8_C(  37), -INT8_C(  55), -INT8_C( 118),  INT8_C(  93),  INT8_C(  24),
         INT8_C(  86),  INT8_C(  44),  INT8_C(  31), -INT8_C(  84),  INT8_C(  34),  INT8_C(   7),  INT8_C(  85), -INT8_C(  85) },
      {  INT8_C(  30),  INT8_C(  16), -INT8_C(  13),  INT8_C( 123),  INT8_C(  68), -INT8_C(  50),  INT8_C(  71),  INT8_C(  72),
        -INT8_C(  22),  INT8_C(  36), -INT8_C(  59), -INT8_C( 108),  INT8_C( 116), -INT8_C( 111),  INT8_C( 121), -INT8_C(  32) } },
    { {  INT8_C( 119),  INT8_C( 101), -INT8_C(  54), -INT8_C( 100), -INT8_C(  96), -INT8_C(  67),      INT8_MAX,  INT8_C(   0),
         INT8_C(  56),  INT8_C(  26), -INT8_C(  81),  INT8_C(  82), -INT8_C(  63),  INT8_C(  69), -INT8_C(  13),  INT8_C( 111) },
      {  INT8_C(  92), -INT8_C(  48), -INT8_C( 108),  INT8_C(  38),  INT8_C(  90), -INT8_C(  15),  INT8_C(  62), -INT8_C(  79),
         INT8_C(  30),  INT8_C(  94),  INT8_C(  93),  INT8_C(  64),  INT8_C( 101), -INT8_C(  78), -INT8_C(  20), -INT8_C(  35) },
      { -INT8_C(  60),  INT8_C(  16), -INT8_C(  56),  INT8_C(  40),  INT8_C(  64), -INT8_C(  19), -INT8_C(  62),  INT8_C(   0),
        -INT8_C( 112), -INT8_C( 116), -INT8_C( 109),      INT8_MIN,  INT8_C(  37), -INT8_C(   6),  INT8_C(   4), -INT8_C(  45) } },
    { {  INT8_C(  23), -INT8_C(  74),  INT8_C( 121), -INT8_C(  72),  INT8_C( 116), -INT8_C(   8), -INT8_C(  72), -INT8_C(  84),
         INT8_C(  18),  INT8_C( 103), -INT8_C(   1), -INT8_C(  45), -INT8_C(  84), -INT8_C(  14),  INT8_C(  66),  INT8_C(   9) },
      { -INT8_C(  62), -INT8_C(  42),  INT8_C(  47),  INT8_C(  29), -INT8_C(  56),  INT8_C( 109), -INT8_C(  50), -INT8_C(  26),
        -INT8_C(  53),  INT8_C(  43),  INT8_C(  38),  INT8_C(  49), -INT8_C(  35),  INT8_C(  18),  INT8_C(  14), -INT8_C(  11) },
      {  INT8_C( 110),  INT8_C(  36),  INT8_C(  55), -INT8_C(  40), -INT8_C(  96), -INT8_C( 104),  INT8_C(  16), -INT8_C( 120),
         INT8_C(  70),  INT8_C(  77), -INT8_C(  38),  INT8_C(  99),  INT8_C( 124),  INT8_C(   4), -INT8_C( 100), -INT8_C(  99) } },
    { { -INT8_C(  55), -INT8_C( 121), -INT8_C(  83),  INT8_C(  61),      INT8_MAX,  INT8_C( 101), -INT8_C(  23), -INT8_C( 111),
        -INT8_C(  52), -INT8_C(  24),  INT8_C( 100),  INT8_C( 121), -INT8_C(  38), -INT8_C(  90), -INT8_C( 126), -INT8_C(  99) },
      {  INT8_C( 124), -INT8_C(  79), -INT8_C(  70),  INT8_C(  68),  INT8_C(  30), -INT8_C( 120),  INT8_C(  42), -INT8_C(  22),
        -INT8_C(  77),  INT8_C(  81),  INT8_C(  27), -INT8_C( 112),  INT8_C(  99),  INT8_C(  41), -INT8_C( 123),  INT8_C(  44) },
      {  INT8_C(  92),  INT8_C(  87), -INT8_C(  78),  INT8_C(  52), -INT8_C(  30), -INT8_C(  88),  INT8_C(  58), -INT8_C( 118),
        -INT8_C(  92),  INT8_C( 104), -INT8_C( 116),  INT8_C(  16),  INT8_C(  78), -INT8_C( 106), -INT8_C( 118), -INT8_C(   4) } },
    { { -INT8_C(  80),  INT8_C(  50),  INT8_C( 105),  INT8_C(  47), -INT8_C( 105),  INT8_C(  83), -INT8_C(  64),  INT8_C( 100),
         INT8_C(  59),  INT8_C(  36), -INT8_C(  35),  INT8_C(  22), -INT8_C(  54),  INT8_C(  95), -INT8_C(  77),  INT8_C(  70) },
      {  INT8_C(  16),  INT8_C( 109), -INT8_C( 117),  INT8_C(  46), -INT8_C(  11), -INT8_C(  75),  INT8_C(  24), -INT8_C(  88),
         INT8_C(   6),  INT8_C(  51),  INT8_C(  56),  INT8_C( 106),  INT8_C(  92), -INT8_C(  66), -INT8_C( 106),  INT8_C(  12) },
      {  INT8_C(   0),  INT8_C(  74),  INT8_C(   3),  INT8_C( 114), -INT8_C( 125), -INT8_C(  81),  INT8_C(   0), -INT8_C(  96),
         INT8_C(  98),  INT8_C(  44),  INT8_C(  88),  INT8_C(  28), -INT8_C( 104), -INT8_C( 126), -INT8_C(  30),  INT8_C(  72) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vmulq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmulq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  1714),  INT16_C(  1643),  INT16_C(  5800), -INT16_C( 15471),  INT16_C(  4030),  INT16_C( 12348), -INT16_C(  9553), -INT16_C(  3871) },
      {  INT16_C( 21671), -INT16_C( 12413), -INT16_C(  3351), -INT16_C( 30479), -INT16_C(  2270), -INT16_C( 20651),  INT16_C( 13282), -INT16_C( 27277) },
      { -INT16_C( 14818), -INT16_C( 12863),  INT16_C( 28392),  INT16_C(  9089),  INT16_C( 26940),  INT16_C(  2028), -INT16_C(  5250),  INT16_C( 10771) } },
    { { -INT16_C(  8647), -INT16_C(  7525),  INT16_C( 11508), -INT16_C( 19803), -INT16_C(  7877), -INT16_C(  5150), -INT16_C( 15172),  INT16_C( 25563) },
      {  INT16_C( 24088),  INT16_C(   306),  INT16_C(  9041),  INT16_C( 29577), -INT16_C(  8422), -INT16_C(   734), -INT16_C( 27374),  INT16_C( 19602) },
      { -INT16_C( 15528), -INT16_C(  8890), -INT16_C( 27340), -INT16_C( 18099),  INT16_C( 17662), -INT16_C( 20988),  INT16_C( 16696), -INT16_C(  2330) } },
    { {  INT16_C( 11635),  INT16_C( 26670), -INT16_C( 11431), -INT16_C( 27622), -INT16_C(   588),  INT16_C( 28799),  INT16_C( 23233), -INT16_C(  9773) },
      {  INT16_C(  1465),  INT16_C(  2778),  INT16_C( 25385),  INT16_C( 17277), -INT16_C( 24766),  INT16_C( 21824), -INT16_C( 11724), -INT16_C( 22623) },
      {  INT16_C(  5915), -INT16_C( 31956),  INT16_C( 17473),  INT16_C(  7858),  INT16_C( 13416),  INT16_C( 19136), -INT16_C( 16076), -INT16_C( 23885) } },
    { { -INT16_C( 12289),  INT16_C( 22543),  INT16_C( 10914),  INT16_C( 22253),  INT16_C( 27687), -INT16_C(  5945), -INT16_C( 25913), -INT16_C( 32575) },
      { -INT16_C( 25696), -INT16_C( 13942),  INT16_C(  2046),  INT16_C( 16652),  INT16_C( 19878), -INT16_C(  9578),  INT16_C( 14111),  INT16_C(  8065) },
      {  INT16_C( 25696),  INT16_C( 16150), -INT16_C( 17732),  INT16_C( 16412), -INT16_C(  9142), -INT16_C(  9574),  INT16_C( 32537),  INT16_C( 16449) } },
    { { -INT16_C( 28410), -INT16_C( 22409),  INT16_C( 25787), -INT16_C(  7426), -INT16_C( 14895), -INT16_C( 26422), -INT16_C( 29856),  INT16_C(    24) },
      { -INT16_C( 24026),  INT16_C(  9417), -INT16_C( 10839),  INT16_C( 20325), -INT16_C(  1246),  INT16_C( 16937), -INT16_C( 21966),  INT16_C( 14433) },
      {  INT16_C( 21220),  INT16_C(   367),  INT16_C(  5747), -INT16_C(  4042),  INT16_C( 12482), -INT16_C( 29606), -INT16_C(  1856),  INT16_C( 18712) } },
    { { -INT16_C( 10181), -INT16_C(  2336), -INT16_C(  8387),  INT16_C(  3800), -INT16_C( 23900),  INT16_C(  1190), -INT16_C( 16851),  INT16_C( 21252) },
      { -INT16_C( 12960),  INT16_C(  2424), -INT16_C(  8797), -INT16_C( 15016), -INT16_C( 32295),  INT16_C(  2823),  INT16_C( 26667),  INT16_C( 26436) },
      {  INT16_C( 21792), -INT16_C( 26368), -INT16_C( 13097),  INT16_C( 21056), -INT16_C( 32508),  INT16_C( 17034),  INT16_C( 14735), -INT16_C( 22256) } },
    { {  INT16_C(  9281),  INT16_C( 32349),  INT16_C( 13827), -INT16_C( 22388),  INT16_C( 13016),  INT16_C(  1708), -INT16_C( 19984),  INT16_C( 20569) },
      { -INT16_C( 11906),  INT16_C(  8537), -INT16_C( 20049), -INT16_C( 30489), -INT16_C(  4558),  INT16_C( 23955), -INT16_C( 10409), -INT16_C( 26428) },
      { -INT16_C(  5890), -INT16_C(  5291), -INT16_C(   243),  INT16_C( 30292), -INT16_C( 16848),  INT16_C( 20676),  INT16_C(  2192),  INT16_C( 23588) } },
    { {  INT16_C(  8956), -INT16_C(   234), -INT16_C( 23976),  INT16_C( 12455),  INT16_C( 21716), -INT16_C( 15306), -INT16_C( 28667), -INT16_C( 31980) },
      {  INT16_C( 28001),  INT16_C(  4261), -INT16_C( 29666),  INT16_C( 20632),  INT16_C( 11386), -INT16_C( 11859),  INT16_C( 29187), -INT16_C(   151) },
      { -INT16_C( 29316), -INT16_C( 14034),  INT16_C(  9808),  INT16_C(  4904), -INT16_C(  8952), -INT16_C( 20866), -INT16_C(  5617), -INT16_C( 20684) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vmulq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmulq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   855182333),  INT32_C(  1421648751), -INT32_C(  1233362429), -INT32_C(  1733602626) },
      {  INT32_C(   128839327),  INT32_C(  1231820222),  INT32_C(   118527701),  INT32_C(  1271697230) },
      {  INT32_C(   919382051), -INT32_C(   146970782), -INT32_C(   333754753), -INT32_C(   791455772) } },
    { {  INT32_C(   176014747),  INT32_C(  1818114408),  INT32_C(  1495456411), -INT32_C(   873345748) },
      {  INT32_C(  2060623547), -INT32_C(  1983692877),  INT32_C(   596693973), -INT32_C(    43099038) },
      {  INT32_C(  1090191929),  INT32_C(  1480244152),  INT32_C(   207463415), -INT32_C(  1657513256) } },
    { { -INT32_C(  1995969759), -INT32_C(  1074436828),  INT32_C(  1813518144), -INT32_C(  1606940188) },
      {  INT32_C(  1528433320),  INT32_C(   535092553),  INT32_C(   306345136), -INT32_C(   250564144) },
      { -INT32_C(   658794584),  INT32_C(    89779012), -INT32_C(  1181156352),  INT32_C(   782150976) } },
    { { -INT32_C(  1048897636), -INT32_C(  1115656067),  INT32_C(  1814665608),  INT32_C(  1242325410) },
      { -INT32_C(  1247402388), -INT32_C(  1277916669), -INT32_C(   809101313),  INT32_C(  1690425032) },
      { -INT32_C(  2137580080),  INT32_C(    61387639),  INT32_C(   829105784),  INT32_C(   376156816) } },
    { {  INT32_C(  1780825325),  INT32_C(   875013804), -INT32_C(   509521601),  INT32_C(   506244530) },
      { -INT32_C(   673918252),  INT32_C(  1535879260), -INT32_C(  2027204161),  INT32_C(   351071271) },
      { -INT32_C(   233513404),  INT32_C(  1728366032),  INT32_C(  1084591361), -INT32_C(   788099554) } },
    { { -INT32_C(   729870040), -INT32_C(   167139657), -INT32_C(  1428641033),  INT32_C(   734528599) },
      {  INT32_C(   839097558),  INT32_C(    76451397),  INT32_C(   109885919), -INT32_C(   853903195) },
      {  INT32_C(   337950576),  INT32_C(     9793875), -INT32_C(  1352831959),  INT32_C(   365532179) } },
    { {  INT32_C(  1101109641),  INT32_C(   926394944), -INT32_C(  1394536620), -INT32_C(   371742189) },
      { -INT32_C(  1961043386),  INT32_C(  1200663144),  INT32_C(   139271267),  INT32_C(   500525204) },
      { -INT32_C(  1125472906), -INT32_C(   374625792), -INT32_C(  1258676868),  INT32_C(  1989479164) } },
    { {  INT32_C(  1096709633),  INT32_C(  1970902561), -INT32_C(  1188996443),  INT32_C(  1268971780) },
      {  INT32_C(  1020706515), -INT32_C(   880581016),  INT32_C(   382980482),  INT32_C(   976529465) },
      { -INT32_C(   582614829),  INT32_C(   689513320),  INT32_C(   569359562),  INT32_C(  1199837668) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vmulq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_vmulq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4157955043631783278), -INT64_C( 7383173757687745161) },
      {  INT64_C( 8419394962083018722), -INT64_C(  901253715486592488) },
      { -INT64_C( 1204569672834376420), -INT64_C( 3540053461434973912) } },
    { { -INT64_C( 5564550027079371400),  INT64_C( 7215618185716682996) },
      { -INT64_C( 7309784739616468995),  INT64_C(  907593611098290464) },
      { -INT64_C( 5023435711355822184),  INT64_C( 7243084518534509184) } },
    { {  INT64_C( 6309086109994951584),  INT64_C( 1015004339592301360) },
      {  INT64_C( 4247095772352916692), -INT64_C( 1526589114959274448) },
      { -INT64_C( 8242478513497898880),  INT64_C( 5279603848098724096) } },
    { { -INT64_C(  372299265012831717), -INT64_C( 8034770570599155874) },
      { -INT64_C( 8159723877624797586),  INT64_C( 3812335679117107636) },
      {  INT64_C( 7937087198466349466),  INT64_C( 8278271605044349976) } },
    { {  INT64_C( 6868419346552761741),  INT64_C( 3281520765434854718) },
      { -INT64_C(  297386802674241293), -INT64_C( 2204545740809096934) },
      {  INT64_C( 1000600319430126807),  INT64_C( 8314945196091938380) } },
    { { -INT64_C( 2310476761110406769), -INT64_C(   39577972136886650) },
      { -INT64_C( 4965447695158203948), -INT64_C( 9108998695387525024) },
      { -INT64_C( 9106841149599051412),  INT64_C( 8719168335463567936) } },
    { { -INT64_C( 2310909180584538258),  INT64_C(   56742684649637823) },
      { -INT64_C( 6260792620510144064), -INT64_C( 3407267369714840509) },
      { -INT64_C( 4282053819573514112),  INT64_C( 1360702996582710013) } },
    { { -INT64_C( 8720149998406219837),  INT64_C( 8628926262549749652) },
      {  INT64_C( 5847351332806712116),  INT64_C( 4266101234806981379) },
      { -INT64_C( 4315554267887606628),  INT64_C( 2862090052451965628) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_x_vmulq_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_x_vmulq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 12), UINT8_C( 29), UINT8_C(140), UINT8_C(196), UINT8_C( 70), UINT8_C(147), UINT8_C( 49), UINT8_C(155),
        UINT8_C(180), UINT8_C(  1), UINT8_C(121), UINT8_C(185), UINT8_C(238), UINT8_C( 11), UINT8_C( 89), UINT8_C(169) },
      { UINT8_C(107), UINT8_C(145), UINT8_C(239), UINT8_C(122), UINT8_C( 68), UINT8_C(239), UINT8_C( 49), UINT8_C( 64),
        UINT8_C(185), UINT8_C(223), UINT8_C(191), UINT8_C(183), UINT8_C(253), UINT8_C(154), UINT8_C(179), UINT8_C( 10) },
      { UINT8_C(  4), UINT8_C(109), UINT8_C(180), UINT8_C(104), UINT8_C(152), UINT8_C( 61), UINT8_C( 97), UINT8_C(192),
        UINT8_C( 20), UINT8_C(223), UINT8_C( 71), UINT8_C( 63), UINT8_C( 54), UINT8_C(158), UINT8_C( 59), UINT8_C(154) } },
    { { UINT8_C(184), UINT8_C( 64), UINT8_C(206), UINT8_C(254), UINT8_C(211), UINT8_C(  0), UINT8_C(153), UINT8_C(136),
        UINT8_C(  1), UINT8_C( 19), UINT8_C( 65), UINT8_C(239), UINT8_C( 30), UINT8_C(154), UINT8_C(153), UINT8_C(137) },
      { UINT8_C( 44), UINT8_C(136), UINT8_C(  3), UINT8_C(112), UINT8_C(119), UINT8_C( 52), UINT8_C(176), UINT8_C( 49),
        UINT8_C( 19), UINT8_C(111), UINT8_C(232), UINT8_C( 17), UINT8_C( 10), UINT8_C(156), UINT8_C( 27), UINT8_C(194) },
      { UINT8_C(160), UINT8_C(  0), UINT8_C(106), UINT8_C( 32), UINT8_C( 21), UINT8_C(  0), UINT8_C( 48), UINT8_C(  8),
        UINT8_C( 19), UINT8_C( 61), UINT8_C(232), UINT8_C(223), UINT8_C( 44), UINT8_C(216), UINT8_C( 35), UINT8_C(210) } },
    { { UINT8_C(220), UINT8_C(233), UINT8_C(192), UINT8_C(175), UINT8_C(233), UINT8_C( 89), UINT8_C( 55), UINT8_C(235),
        UINT8_C(108), UINT8_C(120), UINT8_C(218), UINT8_C(139), UINT8_C( 19), UINT8_C(115), UINT8_C( 20), UINT8_C( 63) },
      { UINT8_C(251), UINT8_C( 24), UINT8_C(175), UINT8_C(115), UINT8_C( 76), UINT8_C( 95), UINT8_C(164), UINT8_C( 96),
        UINT8_C(206), UINT8_C(140), UINT8_C(113), UINT8_C(216), UINT8_C( 40), UINT8_C(140), UINT8_C(154), UINT8_C(  4) },
      { UINT8_C(180), UINT8_C(216), UINT8_C( 64), UINT8_C(157), UINT8_C( 44), UINT8_C(  7), UINT8_C( 60), UINT8_C( 32),
        UINT8_C(232), UINT8_C(160), UINT8_C( 58), UINT8_C( 72), UINT8_C(248), UINT8_C(228), UINT8_C(  8), UINT8_C(252) } },
    { { UINT8_C(117), UINT8_C( 90), UINT8_C(180), UINT8_C( 95), UINT8_C(180), UINT8_C(235), UINT8_C( 74), UINT8_C( 32),
        UINT8_C(100), UINT8_C( 36), UINT8_C(171), UINT8_C(119), UINT8_C(152), UINT8_C(192), UINT8_C(182), UINT8_C(147) },
      { UINT8_C(216), UINT8_C(101), UINT8_C(  6), UINT8_C( 36), UINT8_C(196), UINT8_C(170), UINT8_C(132), UINT8_C(146),
        UINT8_C( 55), UINT8_C(245), UINT8_C(107), UINT8_C( 95), UINT8_C(129), UINT8_C(  5), UINT8_C(100), UINT8_C(247) },
      { UINT8_C(184), UINT8_C(130), UINT8_C( 56), UINT8_C( 92), UINT8_C(208), UINT8_C( 14), UINT8_C( 40), UINT8_C( 64),
        UINT8_C(124), UINT8_C(116), UINT8_C(121), UINT8_C( 41), UINT8_C(152), UINT8_C(192), UINT8_C( 24), UINT8_C(213) } },
    { { UINT8_C( 96), UINT8_C( 24), UINT8_C( 86), UINT8_C( 20), UINT8_C(  3), UINT8_C(160), UINT8_C( 52), UINT8_C(103),
        UINT8_C(196), UINT8_C(224), UINT8_C(222), UINT8_C( 92), UINT8_C(160), UINT8_C(148), UINT8_C(240), UINT8_C(120) },
      { UINT8_C(249), UINT8_C(246), UINT8_C(156), UINT8_C(189), UINT8_C(161), UINT8_C( 33), UINT8_C( 80), UINT8_C(216),
        UINT8_C( 22), UINT8_C(187), UINT8_C( 55), UINT8_C(152), UINT8_C(192), UINT8_C(155), UINT8_C(143), UINT8_C( 32) },
      { UINT8_C( 96), UINT8_C( 16), UINT8_C(104), UINT8_C(196), UINT8_C(227), UINT8_C(160), UINT8_C( 64), UINT8_C(232),
        UINT8_C(216), UINT8_C(160), UINT8_C(178), UINT8_C(160), UINT8_C(  0), UINT8_C(156), UINT8_C( 16), UINT8_C(  0) } },
    { { UINT8_C(179), UINT8_C(229), UINT8_C( 52), UINT8_C(183), UINT8_C(133), UINT8_C(105), UINT8_C( 30), UINT8_C( 73),
        UINT8_C( 73), UINT8_C(253), UINT8_C(166), UINT8_C(233), UINT8_C(145), UINT8_C(150), UINT8_C( 97), UINT8_C(139) },
      { UINT8_C(140), UINT8_C(253), UINT8_C( 72), UINT8_C( 45), UINT8_C( 30), UINT8_C(152), UINT8_C(  5), UINT8_C( 53),
        UINT8_C( 83), UINT8_C( 61), UINT8_C(205), UINT8_C( 20), UINT8_C(216), UINT8_C( 92), UINT8_C( 52), UINT8_C(140) },
      { UINT8_C(228), UINT8_C( 81), UINT8_C(160), UINT8_C( 43), UINT8_C(150), UINT8_C( 88), UINT8_C(150), UINT8_C( 29),
        UINT8_C(171), UINT8_C( 73), UINT8_C(238), UINT8_C( 52), UINT8_C( 88), UINT8_C(232), UINT8_C(180), UINT8_C(  4) } },
    { { UINT8_C( 65), UINT8_C(105), UINT8_C( 67), UINT8_C(198), UINT8_C(210), UINT8_C( 97), UINT8_C( 15), UINT8_C( 27),
        UINT8_C( 94), UINT8_C(181), UINT8_C(  4), UINT8_C(240), UINT8_C( 75), UINT8_C(101), UINT8_C(123), UINT8_C(216) },
      { UINT8_C( 98), UINT8_C(195), UINT8_C(  5), UINT8_C(129), UINT8_C( 92), UINT8_C( 11), UINT8_C(182), UINT8_C(175),
        UINT8_C( 72), UINT8_C(131), UINT8_C(195), UINT8_C( 32), UINT8_C(223), UINT8_C(248), UINT8_C(172), UINT8_C( 32) },
      { UINT8_C(226), UINT8_C(251), UINT8_C( 79), UINT8_C(198), UINT8_C(120), UINT8_C( 43), UINT8_C(170), UINT8_C(117),
        UINT8_C(112), UINT8_C(159), UINT8_C( 12), UINT8_C(  0), UINT8_C( 85), UINT8_C(216), UINT8_C(164), UINT8_C(  0) } },
    { { UINT8_C( 97), UINT8_C(239), UINT8_C(230), UINT8_C( 51), UINT8_C( 81), UINT8_C(245), UINT8_C( 78), UINT8_C(175),
        UINT8_C(171), UINT8_C( 82), UINT8_C(159), UINT8_C(246), UINT8_C(183), UINT8_C( 26), UINT8_C(206), UINT8_C( 25) },
      { UINT8_C(222), UINT8_C(212), UINT8_C(154), UINT8_C( 58), UINT8_C(223), UINT8_C( 80), UINT8_C(233), UINT8_C( 39),
        UINT8_C(211), UINT8_C(173), UINT8_C( 71), UINT8_C(178), UINT8_C(165), UINT8_C(244), UINT8_C(210), UINT8_C(  6) },
      { UINT8_C( 30), UINT8_C(236), UINT8_C( 92), UINT8_C(142), UINT8_C(143), UINT8_C(144), UINT8_C(254), UINT8_C(169),
        UINT8_C(241), UINT8_C(106), UINT8_C( 25), UINT8_C( 12), UINT8_C(243), UINT8_C(200), UINT8_C(252), UINT8_C(150) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vmulq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmulq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(64522), UINT16_C(40150), UINT16_C(18908), UINT16_C(26142), UINT16_C(30372), UINT16_C(42082), UINT16_C(17414), UINT16_C(42550) },
      { UINT16_C(35252), UINT16_C( 5631), UINT16_C(23381), UINT16_C(46234), UINT16_C(30698), UINT16_C(  807), UINT16_C(48695), UINT16_C(16921) },
      { UINT16_C(37128), UINT16_C(50986), UINT16_C(47628), UINT16_C(34316), UINT16_C(44520), UINT16_C(12526), UINT16_C( 4426), UINT16_C(10054) } },
    { { UINT16_C(61370), UINT16_C(38622), UINT16_C(64568), UINT16_C(56572), UINT16_C(24179), UINT16_C(31104), UINT16_C(47010), UINT16_C(22304) },
      { UINT16_C( 8000), UINT16_C(38252), UINT16_C( 1658), UINT16_C(25674), UINT16_C(29053), UINT16_C(46184), UINT16_C(33072), UINT16_C(60150) },
      { UINT16_C(29824), UINT16_C(56232), UINT16_C(33456), UINT16_C(20696), UINT16_C(57639), UINT16_C(23552), UINT16_C( 4192), UINT16_C(63680) } },
    { { UINT16_C(54384), UINT16_C(43137), UINT16_C(32209), UINT16_C(17540), UINT16_C( 1244), UINT16_C(32445), UINT16_C(56763), UINT16_C(64725) },
      { UINT16_C(16892), UINT16_C(30353), UINT16_C(56135), UINT16_C(50395), UINT16_C(17229), UINT16_C(32121), UINT16_C(28612), UINT16_C(13415) },
      { UINT16_C(36416), UINT16_C(59153), UINT16_C(45047), UINT16_C(44268), UINT16_C( 2604), UINT16_C(12373), UINT16_C(55340), UINT16_C(64947) } },
    { { UINT16_C(59460), UINT16_C( 5596), UINT16_C(24678), UINT16_C(16985), UINT16_C( 5732), UINT16_C( 8384), UINT16_C(38644), UINT16_C(61468) },
      { UINT16_C(44503), UINT16_C( 8039), UINT16_C(17033), UINT16_C(55011), UINT16_C(23685), UINT16_C(18771), UINT16_C(47820), UINT16_C( 4221) },
      { UINT16_C( 1308), UINT16_C(28548), UINT16_C(58006), UINT16_C(15083), UINT16_C(37364), UINT16_C(24128), UINT16_C(37488), UINT16_C(64940) } },
    { { UINT16_C(22947), UINT16_C( 2341), UINT16_C(32441), UINT16_C( 7499), UINT16_C( 2964), UINT16_C(34877), UINT16_C(22945), UINT16_C(31097) },
      { UINT16_C(57351), UINT16_C(37016), UINT16_C(31522), UINT16_C(42854), UINT16_C(47576), UINT16_C(42224), UINT16_C(28019), UINT16_C( 5812) },
      { UINT16_C( 4981), UINT16_C(15864), UINT16_C(46994), UINT16_C(39138), UINT16_C(47328), UINT16_C(52528), UINT16_C(53331), UINT16_C(53012) } },
    { { UINT16_C(55750), UINT16_C(32543), UINT16_C(27223), UINT16_C(60316), UINT16_C(55926), UINT16_C( 6004), UINT16_C(60723), UINT16_C(14992) },
      { UINT16_C(10445), UINT16_C(61386), UINT16_C(12452), UINT16_C(31894), UINT16_C(34537), UINT16_C(23840), UINT16_C(54515), UINT16_C(47475) },
      { UINT16_C(21390), UINT16_C(16246), UINT16_C(28604), UINT16_C(40296), UINT16_C(39270), UINT16_C( 4736), UINT16_C(25449), UINT16_C(24240) } },
    { { UINT16_C(37805), UINT16_C( 1080), UINT16_C(54525), UINT16_C(29679), UINT16_C(25518), UINT16_C(57995), UINT16_C( 6992), UINT16_C( 7452) },
      { UINT16_C(59204), UINT16_C(59404), UINT16_C(41495), UINT16_C(  356), UINT16_C(33832), UINT16_C( 7006), UINT16_C(53592), UINT16_C( 1492) },
      { UINT16_C(21748), UINT16_C(62112), UINT16_C(15547), UINT16_C(14428), UINT16_C(19248), UINT16_C(55306), UINT16_C(45952), UINT16_C(42800) } },
    { { UINT16_C( 3172), UINT16_C(25097), UINT16_C(63713), UINT16_C(36821), UINT16_C(24668), UINT16_C(44145), UINT16_C(36476), UINT16_C(49354) },
      { UINT16_C(54901), UINT16_C(36008), UINT16_C( 3193), UINT16_C(41357), UINT16_C(60304), UINT16_C(59581), UINT16_C(37309), UINT16_C( 8685) },
      { UINT16_C(16820), UINT16_C(16872), UINT16_C(11865), UINT16_C(11601), UINT16_C(42944), UINT16_C(46957), UINT16_C(28044), UINT16_C(34050) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vmulq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmulq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 838207622), UINT32_C(3405383108), UINT32_C(2377386269), UINT32_C(4159190503) },
      { UINT32_C(2224025479), UINT32_C(3989376773), UINT32_C(3953058906), UINT32_C(1658203612) },
      { UINT32_C(3851262122), UINT32_C(2552010964), UINT32_C(1750009906), UINT32_C(1512172932) } },
    { { UINT32_C(4187212853), UINT32_C(4005793489), UINT32_C(2138863511), UINT32_C( 880174253) },
      { UINT32_C(1505297747), UINT32_C(1850114580), UINT32_C(1113187430), UINT32_C(1185165073) },
      { UINT32_C(3442818607), UINT32_C(3505605204), UINT32_C( 664347178), UINT32_C(  86798973) } },
    { { UINT32_C(3426695163), UINT32_C(1572537029), UINT32_C( 668743546), UINT32_C(4015739547) },
      { UINT32_C(1799885911), UINT32_C(4242116246), UINT32_C(2201891698), UINT32_C(1590288994) },
      { UINT32_C(  24355405), UINT32_C(3961120110), UINT32_C(2091516500), UINT32_C(  93680982) } },
    { { UINT32_C(3744073754), UINT32_C(2218583306), UINT32_C(3098220572), UINT32_C(3248949098) },
      { UINT32_C(2989289243), UINT32_C(4021159549), UINT32_C(2608000313), UINT32_C(3925425103) },
      { UINT32_C(1064771774), UINT32_C(  31855074), UINT32_C( 870468156), UINT32_C(3302911158) } },
    { { UINT32_C(1305027651), UINT32_C( 651298057), UINT32_C(2296282398), UINT32_C(2689238404) },
      { UINT32_C(4048713332), UINT32_C(3051356284), UINT32_C(3176223469), UINT32_C(3500558989) },
      { UINT32_C(2790346844), UINT32_C(2459594844), UINT32_C(3062591686), UINT32_C(2805707188) } },
    { { UINT32_C(2015194990), UINT32_C(2476666741), UINT32_C(4045110381), UINT32_C(1972462849) },
      { UINT32_C(1483138012), UINT32_C(3507373796), UINT32_C( 630087576), UINT32_C( 418723241) },
      { UINT32_C(2297318536), UINT32_C(2355970612), UINT32_C( 552883128), UINT32_C(2027545257) } },
    { { UINT32_C( 428872356), UINT32_C(1873554946), UINT32_C(2875246762), UINT32_C( 153154093) },
      { UINT32_C(3110242005), UINT32_C(1686859980), UINT32_C(2022250959), UINT32_C(4086333006) },
      { UINT32_C(1432967796), UINT32_C( 342591896), UINT32_C( 433380214), UINT32_C(4018925494) } },
    { { UINT32_C(2450268304), UINT32_C(4160862542), UINT32_C(2929943169), UINT32_C( 699974484) },
      { UINT32_C( 367204937), UINT32_C(1501130378), UINT32_C(3604021895), UINT32_C( 298410624) },
      { UINT32_C(2423515408), UINT32_C( 577464332), UINT32_C(2688480263), UINT32_C(2283524608) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vmulq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_vmulq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 8453629100971987715), UINT64_C(17339128753870447218) },
      { UINT64_C( 8372071250065717968), UINT64_C(17638644746708104470) },
      { UINT64_C( 2275508533926944880), UINT64_C(16821336020454117324) } },
    { { UINT64_C(16534421168073941280), UINT64_C( 8097383758611524530) },
      { UINT64_C( 8362760502854536233), UINT64_C( 1448695574823102004) },
      { UINT64_C( 2146727699645845024), UINT64_C(15795703185322069032) } },
    { { UINT64_C(11188784158704261613), UINT64_C( 3190351751723701302) },
      { UINT64_C( 5190350280411485492), UINT64_C(14105986338996947643) },
      { UINT64_C(  727445559653512484), UINT64_C(14320173044861542258) } },
    { { UINT64_C(11017046459309872992), UINT64_C(10083195999946206910) },
      { UINT64_C( 4946682512632886346), UINT64_C(18215008370324280367) },
      { UINT64_C(13190602949145641408), UINT64_C(10245401748418112738) } },
    { { UINT64_C( 1407139957151493260), UINT64_C(17724412949559637528) },
      { UINT64_C( 7801635594418001783), UINT64_C( 8693700918831625998) },
      { UINT64_C( 5669749077729970452), UINT64_C(10463065914885709136) } },
    { { UINT64_C( 3283105528936917798), UINT64_C(11494757621095490789) },
      { UINT64_C(16309474703689374125), UINT64_C( 2990163666190256155) },
      { UINT64_C(  882033643506572974), UINT64_C(14869171963549289511) } },
    { { UINT64_C(13502132351939241758), UINT64_C( 4566879350880468377) },
      { UINT64_C(18329792197960531882), UINT64_C( 4428592178037910856) },
      { UINT64_C( 9138642147534199788), UINT64_C(14173604868775933960) } },
    { { UINT64_C(16860863817803962988), UINT64_C(14024501814442477775) },
      { UINT64_C(10658790286282508809), UINT64_C(16351254641287033230) },
      { UINT64_C( 1271651353639462348), UINT64_C(11031284440050516434) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_x_vmulq_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_x_vmulq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vmul_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vmul_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vmulq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vmulq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
