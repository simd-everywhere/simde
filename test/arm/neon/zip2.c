#define SIMDE_TEST_ARM_NEON_INSN zip2

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/zip2.h>

static int
test_simde_vzip2_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -56.55), SIMDE_FLOAT32_C(   618.01) },
      { SIMDE_FLOAT32_C(   834.26), SIMDE_FLOAT32_C(  -509.20) },
      { SIMDE_FLOAT32_C(   618.01), SIMDE_FLOAT32_C(  -509.20) } },
    { { SIMDE_FLOAT32_C(   293.29), SIMDE_FLOAT32_C(  -837.93) },
      { SIMDE_FLOAT32_C(  -408.68), SIMDE_FLOAT32_C(   430.47) },
      { SIMDE_FLOAT32_C(  -837.93), SIMDE_FLOAT32_C(   430.47) } },
    { { SIMDE_FLOAT32_C(   222.04), SIMDE_FLOAT32_C(  -192.86) },
      { SIMDE_FLOAT32_C(   566.42), SIMDE_FLOAT32_C(   826.36) },
      { SIMDE_FLOAT32_C(  -192.86), SIMDE_FLOAT32_C(   826.36) } },
    { { SIMDE_FLOAT32_C(  -395.53), SIMDE_FLOAT32_C(   599.03) },
      { SIMDE_FLOAT32_C(  -555.41), SIMDE_FLOAT32_C(    22.87) },
      { SIMDE_FLOAT32_C(   599.03), SIMDE_FLOAT32_C(    22.87) } },
    { { SIMDE_FLOAT32_C(   968.44), SIMDE_FLOAT32_C(    95.81) },
      { SIMDE_FLOAT32_C(  -638.58), SIMDE_FLOAT32_C(   816.26) },
      { SIMDE_FLOAT32_C(    95.81), SIMDE_FLOAT32_C(   816.26) } },
    { { SIMDE_FLOAT32_C(  -762.51), SIMDE_FLOAT32_C(   946.71) },
      { SIMDE_FLOAT32_C(  -370.92), SIMDE_FLOAT32_C(   887.37) },
      { SIMDE_FLOAT32_C(   946.71), SIMDE_FLOAT32_C(   887.37) } },
    { { SIMDE_FLOAT32_C(  -457.71), SIMDE_FLOAT32_C(  -445.84) },
      { SIMDE_FLOAT32_C(  -147.78), SIMDE_FLOAT32_C(  -754.97) },
      { SIMDE_FLOAT32_C(  -445.84), SIMDE_FLOAT32_C(  -754.97) } },
    { { SIMDE_FLOAT32_C(   814.41), SIMDE_FLOAT32_C(   434.23) },
      { SIMDE_FLOAT32_C(   418.66), SIMDE_FLOAT32_C(  -242.14) },
      { SIMDE_FLOAT32_C(   434.23), SIMDE_FLOAT32_C(  -242.14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vzip2_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vzip2_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  70), -INT8_C(  80), -INT8_C(  52),  INT8_C(  94),  INT8_C(  33),  INT8_C(  70), -INT8_C(   2),  INT8_C(  95) },
      { -INT8_C(  15),  INT8_C(  85),      INT8_MAX,  INT8_C(  75), -INT8_C( 126),  INT8_C(  59),  INT8_C(  49), -INT8_C(  48) },
      {  INT8_C(  33), -INT8_C( 126),  INT8_C(  70),  INT8_C(  59), -INT8_C(   2),  INT8_C(  49),  INT8_C(  95), -INT8_C(  48) } },
    { {  INT8_C(  95),  INT8_C(  87),  INT8_C(  16),  INT8_C(  40),  INT8_C( 102), -INT8_C(   8),  INT8_C(  74), -INT8_C( 100) },
      { -INT8_C( 117), -INT8_C(  49),  INT8_C(  35), -INT8_C( 122), -INT8_C(  72), -INT8_C(  81), -INT8_C(  87), -INT8_C(   2) },
      {  INT8_C( 102), -INT8_C(  72), -INT8_C(   8), -INT8_C(  81),  INT8_C(  74), -INT8_C(  87), -INT8_C( 100), -INT8_C(   2) } },
    { {  INT8_C(  95),  INT8_C( 117),  INT8_C(  93), -INT8_C( 127), -INT8_C(  68),  INT8_C(  91), -INT8_C(  32), -INT8_C(  83) },
      { -INT8_C(  80),  INT8_C(  96), -INT8_C(   8),  INT8_C(  50), -INT8_C( 101),  INT8_C(  42),  INT8_C(   3), -INT8_C(   6) },
      { -INT8_C(  68), -INT8_C( 101),  INT8_C(  91),  INT8_C(  42), -INT8_C(  32),  INT8_C(   3), -INT8_C(  83), -INT8_C(   6) } },
    { { -INT8_C( 127),  INT8_C(  19),  INT8_C(  34), -INT8_C(  25),  INT8_C(  11),  INT8_C( 109), -INT8_C( 125), -INT8_C( 106) },
      {  INT8_C(  60), -INT8_C(  89),  INT8_C(  28), -INT8_C(  12),  INT8_C(  86), -INT8_C(  59), -INT8_C(  13), -INT8_C(  75) },
      {  INT8_C(  11),  INT8_C(  86),  INT8_C( 109), -INT8_C(  59), -INT8_C( 125), -INT8_C(  13), -INT8_C( 106), -INT8_C(  75) } },
    { {  INT8_C(  59),  INT8_C(  80),  INT8_C(  54), -INT8_C(   9), -INT8_C(  85),  INT8_C(  23), -INT8_C(  92),  INT8_C(  91) },
      {  INT8_C( 119), -INT8_C( 100), -INT8_C( 114),  INT8_C(  18), -INT8_C(  58), -INT8_C( 111),  INT8_C(  12),  INT8_C(  72) },
      { -INT8_C(  85), -INT8_C(  58),  INT8_C(  23), -INT8_C( 111), -INT8_C(  92),  INT8_C(  12),  INT8_C(  91),  INT8_C(  72) } },
    { { -INT8_C(  92),  INT8_C(  47),  INT8_C(  47), -INT8_C(  81), -INT8_C( 100), -INT8_C(  77),  INT8_C(  69), -INT8_C(  40) },
      {  INT8_C(  90),  INT8_C(  97), -INT8_C(  51), -INT8_C(  80),  INT8_C(  38), -INT8_C(  64),  INT8_C( 101),  INT8_C(  97) },
      { -INT8_C( 100),  INT8_C(  38), -INT8_C(  77), -INT8_C(  64),  INT8_C(  69),  INT8_C( 101), -INT8_C(  40),  INT8_C(  97) } },
    { {  INT8_C(  16), -INT8_C( 100),  INT8_C(  88), -INT8_C(  69), -INT8_C(  77), -INT8_C(   4),  INT8_C(  22),  INT8_C(  42) },
      { -INT8_C( 103), -INT8_C(  92),  INT8_C(  60),  INT8_C(  95),  INT8_C(  53),  INT8_C(  72), -INT8_C(  89), -INT8_C(  39) },
      { -INT8_C(  77),  INT8_C(  53), -INT8_C(   4),  INT8_C(  72),  INT8_C(  22), -INT8_C(  89),  INT8_C(  42), -INT8_C(  39) } },
    { {  INT8_C( 119), -INT8_C(  41), -INT8_C( 120),  INT8_C(  19), -INT8_C( 118), -INT8_C(  51), -INT8_C(  20), -INT8_C(  28) },
      {  INT8_C(  46), -INT8_C(  71), -INT8_C( 108),  INT8_C(  85),  INT8_C( 121), -INT8_C(   7), -INT8_C(  74), -INT8_C( 119) },
      { -INT8_C( 118),  INT8_C( 121), -INT8_C(  51), -INT8_C(   7), -INT8_C(  20), -INT8_C(  74), -INT8_C(  28), -INT8_C( 119) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vzip2_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 31586), -INT16_C( 31027),  INT16_C(  5600), -INT16_C(  5698) },
      {  INT16_C( 32317),  INT16_C( 13734),  INT16_C( 18228), -INT16_C( 31524) },
      {  INT16_C(  5600),  INT16_C( 18228), -INT16_C(  5698), -INT16_C( 31524) } },
    { {  INT16_C( 11907),  INT16_C( 17733),  INT16_C( 12727), -INT16_C( 17795) },
      {  INT16_C( 19182), -INT16_C( 25509),  INT16_C( 32649), -INT16_C(  5297) },
      {  INT16_C( 12727),  INT16_C( 32649), -INT16_C( 17795), -INT16_C(  5297) } },
    { {  INT16_C(  7419), -INT16_C(  9359),  INT16_C( 12082),  INT16_C( 28612) },
      {  INT16_C( 27310), -INT16_C(  7516), -INT16_C( 32590),  INT16_C( 13671) },
      {  INT16_C( 12082), -INT16_C( 32590),  INT16_C( 28612),  INT16_C( 13671) } },
    { { -INT16_C( 21329),  INT16_C( 26234), -INT16_C(  2083), -INT16_C( 13280) },
      {  INT16_C( 31553), -INT16_C( 13464), -INT16_C( 18438), -INT16_C(  2634) },
      { -INT16_C(  2083), -INT16_C( 18438), -INT16_C( 13280), -INT16_C(  2634) } },
    { {  INT16_C( 10452),  INT16_C(  1744), -INT16_C( 27561),  INT16_C(  1397) },
      {  INT16_C(  6655), -INT16_C( 19992),  INT16_C( 20378),  INT16_C( 18918) },
      { -INT16_C( 27561),  INT16_C( 20378),  INT16_C(  1397),  INT16_C( 18918) } },
    { {  INT16_C( 24827), -INT16_C(  9809), -INT16_C( 12457), -INT16_C( 26459) },
      {  INT16_C(  3402),  INT16_C( 17507),  INT16_C(  6853), -INT16_C( 26310) },
      { -INT16_C( 12457),  INT16_C(  6853), -INT16_C( 26459), -INT16_C( 26310) } },
    { {  INT16_C(  2626), -INT16_C( 26209),  INT16_C(  5279), -INT16_C( 24929) },
      { -INT16_C( 30931), -INT16_C( 14513),  INT16_C( 13782), -INT16_C( 12016) },
      {  INT16_C(  5279),  INT16_C( 13782), -INT16_C( 24929), -INT16_C( 12016) } },
    { { -INT16_C( 16491), -INT16_C(  4950),  INT16_C( 20366), -INT16_C( 10108) },
      { -INT16_C(  6051),  INT16_C(  8733),  INT16_C( 22274),  INT16_C( 17595) },
      {  INT16_C( 20366),  INT16_C( 22274), -INT16_C( 10108),  INT16_C( 17595) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vzip2_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1128440363),  INT32_C(   500102932) },
      { -INT32_C(   826084822),  INT32_C(  2023511124) },
      {  INT32_C(   500102932),  INT32_C(  2023511124) } },
    { {  INT32_C(  1458785856), -INT32_C(   835584527) },
      { -INT32_C(   586230260),  INT32_C(  2044523428) },
      { -INT32_C(   835584527),  INT32_C(  2044523428) } },
    { {  INT32_C(  1681234256), -INT32_C(  1149172847) },
      {  INT32_C(  1250510070), -INT32_C(   658365032) },
      { -INT32_C(  1149172847), -INT32_C(   658365032) } },
    { {  INT32_C(  1697559923), -INT32_C(  1087152205) },
      { -INT32_C(   644070859), -INT32_C(  2058127307) },
      { -INT32_C(  1087152205), -INT32_C(  2058127307) } },
    { { -INT32_C(  1561753583), -INT32_C(  2107807092) },
      {  INT32_C(  1187833774), -INT32_C(  2145415668) },
      { -INT32_C(  2107807092), -INT32_C(  2145415668) } },
    { { -INT32_C(   152744637), -INT32_C(   491448147) },
      { -INT32_C(  1883483814), -INT32_C(   619442231) },
      { -INT32_C(   491448147), -INT32_C(   619442231) } },
    { {  INT32_C(   595459479),  INT32_C(   379968360) },
      { -INT32_C(   832736830),  INT32_C(  1129217279) },
      {  INT32_C(   379968360),  INT32_C(  1129217279) } },
    { {  INT32_C(  1983460297), -INT32_C(  1504055476) },
      {  INT32_C(   171316544), -INT32_C(  1142601180) },
      { -INT32_C(  1504055476), -INT32_C(  1142601180) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vzip2_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 92), UINT8_C( 83), UINT8_C( 54), UINT8_C(128), UINT8_C(189), UINT8_C(177), UINT8_C(148), UINT8_C(204) },
      { UINT8_C(  3), UINT8_C(  8), UINT8_C( 33), UINT8_C( 35), UINT8_C( 77), UINT8_C(187), UINT8_C(189), UINT8_C(155) },
      { UINT8_C(189), UINT8_C( 77), UINT8_C(177), UINT8_C(187), UINT8_C(148), UINT8_C(189), UINT8_C(204), UINT8_C(155) } },
    { { UINT8_C(183), UINT8_C( 14), UINT8_C( 96), UINT8_C(141), UINT8_C( 14), UINT8_C(153), UINT8_C(229), UINT8_C(  0) },
      { UINT8_C(117), UINT8_C(187), UINT8_C(126), UINT8_C(177), UINT8_C(175), UINT8_C(115), UINT8_C(204), UINT8_C( 11) },
      { UINT8_C( 14), UINT8_C(175), UINT8_C(153), UINT8_C(115), UINT8_C(229), UINT8_C(204), UINT8_C(  0), UINT8_C( 11) } },
    { { UINT8_C(198), UINT8_C(  2), UINT8_C(139), UINT8_C(131), UINT8_C(179), UINT8_C( 31), UINT8_C( 80), UINT8_C(182) },
      { UINT8_C( 40), UINT8_C(113), UINT8_C(218), UINT8_C(117), UINT8_C( 44), UINT8_C(151), UINT8_C( 16), UINT8_C(228) },
      { UINT8_C(179), UINT8_C( 44), UINT8_C( 31), UINT8_C(151), UINT8_C( 80), UINT8_C( 16), UINT8_C(182), UINT8_C(228) } },
    { { UINT8_C(166), UINT8_C(112), UINT8_C(113), UINT8_C(180), UINT8_C(  9), UINT8_C( 86), UINT8_C(181), UINT8_C(126) },
      { UINT8_C( 17), UINT8_C( 51), UINT8_C( 47), UINT8_C(192), UINT8_C(166), UINT8_C(251), UINT8_C(203), UINT8_C(108) },
      { UINT8_C(  9), UINT8_C(166), UINT8_C( 86), UINT8_C(251), UINT8_C(181), UINT8_C(203), UINT8_C(126), UINT8_C(108) } },
    { { UINT8_C(254), UINT8_C( 86), UINT8_C(239), UINT8_C(177), UINT8_C(118), UINT8_C( 63), UINT8_C(104), UINT8_C(158) },
      { UINT8_C(177), UINT8_C( 66), UINT8_C( 19), UINT8_C(221), UINT8_C(217), UINT8_C( 35), UINT8_C(193), UINT8_C(127) },
      { UINT8_C(118), UINT8_C(217), UINT8_C( 63), UINT8_C( 35), UINT8_C(104), UINT8_C(193), UINT8_C(158), UINT8_C(127) } },
    { { UINT8_C(147), UINT8_C( 50), UINT8_C( 52), UINT8_C(156), UINT8_C(136), UINT8_C(233), UINT8_C( 27), UINT8_C(154) },
      { UINT8_C( 28), UINT8_C( 74), UINT8_C( 90), UINT8_C(194), UINT8_C( 70), UINT8_C( 38), UINT8_C( 46), UINT8_C( 68) },
      { UINT8_C(136), UINT8_C( 70), UINT8_C(233), UINT8_C( 38), UINT8_C( 27), UINT8_C( 46), UINT8_C(154), UINT8_C( 68) } },
    { { UINT8_C(124), UINT8_C( 29), UINT8_C(245), UINT8_C(242), UINT8_C( 93), UINT8_C( 93), UINT8_C(144), UINT8_C( 14) },
      { UINT8_C(159), UINT8_C(163), UINT8_C(235), UINT8_C(121), UINT8_C(198), UINT8_C(173), UINT8_C(248), UINT8_C( 89) },
      { UINT8_C( 93), UINT8_C(198), UINT8_C( 93), UINT8_C(173), UINT8_C(144), UINT8_C(248), UINT8_C( 14), UINT8_C( 89) } },
    { { UINT8_C(223), UINT8_C( 44), UINT8_C(246), UINT8_C(104), UINT8_C( 21), UINT8_C( 17), UINT8_C(  2), UINT8_C( 49) },
      { UINT8_C( 91), UINT8_C( 92), UINT8_C(243), UINT8_C(161), UINT8_C(130), UINT8_C( 33), UINT8_C(229),    UINT8_MAX },
      { UINT8_C( 21), UINT8_C(130), UINT8_C( 17), UINT8_C( 33), UINT8_C(  2), UINT8_C(229), UINT8_C( 49),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vzip2_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(17902), UINT16_C(53967), UINT16_C(20983), UINT16_C(42835) },
      { UINT16_C(47613), UINT16_C(55873), UINT16_C(16028), UINT16_C(21060) },
      { UINT16_C(20983), UINT16_C(16028), UINT16_C(42835), UINT16_C(21060) } },
    { { UINT16_C(47255), UINT16_C(46865), UINT16_C(60625), UINT16_C(64413) },
      { UINT16_C(53844), UINT16_C(24480), UINT16_C(58718), UINT16_C(19663) },
      { UINT16_C(60625), UINT16_C(58718), UINT16_C(64413), UINT16_C(19663) } },
    { { UINT16_C(40490), UINT16_C( 8478), UINT16_C(29168), UINT16_C(60872) },
      { UINT16_C( 2346), UINT16_C(51143), UINT16_C( 3144), UINT16_C(57113) },
      { UINT16_C(29168), UINT16_C( 3144), UINT16_C(60872), UINT16_C(57113) } },
    { { UINT16_C(10948), UINT16_C(38295), UINT16_C(13334), UINT16_C(27536) },
      { UINT16_C(12550), UINT16_C(25802), UINT16_C(39190), UINT16_C(16560) },
      { UINT16_C(13334), UINT16_C(39190), UINT16_C(27536), UINT16_C(16560) } },
    { { UINT16_C(52792), UINT16_C(10337), UINT16_C(10559), UINT16_C(27157) },
      { UINT16_C(56626), UINT16_C(31281), UINT16_C(19177), UINT16_C(44378) },
      { UINT16_C(10559), UINT16_C(19177), UINT16_C(27157), UINT16_C(44378) } },
    { { UINT16_C(61813), UINT16_C(35650), UINT16_C(54053), UINT16_C(11254) },
      { UINT16_C(49156), UINT16_C( 6800), UINT16_C(16474), UINT16_C(37466) },
      { UINT16_C(54053), UINT16_C(16474), UINT16_C(11254), UINT16_C(37466) } },
    { { UINT16_C(47887), UINT16_C(20154), UINT16_C(53220), UINT16_C( 5816) },
      { UINT16_C(59820), UINT16_C(38289), UINT16_C(60212), UINT16_C(43330) },
      { UINT16_C(53220), UINT16_C(60212), UINT16_C( 5816), UINT16_C(43330) } },
    { { UINT16_C(34268), UINT16_C(  308), UINT16_C(11096), UINT16_C(23596) },
      { UINT16_C(48363), UINT16_C(17782), UINT16_C(53501), UINT16_C( 3287) },
      { UINT16_C(11096), UINT16_C(53501), UINT16_C(23596), UINT16_C( 3287) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vzip2_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 711269039), UINT32_C(1500404369) },
      { UINT32_C( 481603462), UINT32_C(3826687848) },
      { UINT32_C(1500404369), UINT32_C(3826687848) } },
    { { UINT32_C(2274796837), UINT32_C(1676736426) },
      { UINT32_C(1950206382), UINT32_C(1098409105) },
      { UINT32_C(1676736426), UINT32_C(1098409105) } },
    { { UINT32_C( 275504510), UINT32_C(3194608184) },
      { UINT32_C(4057603465), UINT32_C(3805671612) },
      { UINT32_C(3194608184), UINT32_C(3805671612) } },
    { { UINT32_C(1080650902), UINT32_C( 295917923) },
      { UINT32_C(3028672803), UINT32_C(3287678277) },
      { UINT32_C( 295917923), UINT32_C(3287678277) } },
    { { UINT32_C( 332620251), UINT32_C(3302046779) },
      { UINT32_C( 381070169), UINT32_C( 855149468) },
      { UINT32_C(3302046779), UINT32_C( 855149468) } },
    { { UINT32_C(1517445623), UINT32_C(3714848186) },
      { UINT32_C( 999485942), UINT32_C(3405744111) },
      { UINT32_C(3714848186), UINT32_C(3405744111) } },
    { { UINT32_C( 601740008), UINT32_C(1760079375) },
      { UINT32_C(4118715993), UINT32_C( 556234281) },
      { UINT32_C(1760079375), UINT32_C( 556234281) } },
    { { UINT32_C(2457573847), UINT32_C(2775574447) },
      { UINT32_C(3370189273), UINT32_C(1905451145) },
      { UINT32_C(2775574447), UINT32_C(1905451145) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vzip2_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2q_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   991.39), SIMDE_FLOAT32_C(  -819.33), SIMDE_FLOAT32_C(  -284.09), SIMDE_FLOAT32_C(  -188.89) },
      { SIMDE_FLOAT32_C(  -984.89), SIMDE_FLOAT32_C(  -117.35), SIMDE_FLOAT32_C(   890.93), SIMDE_FLOAT32_C(   277.64) },
      { SIMDE_FLOAT32_C(  -284.09), SIMDE_FLOAT32_C(   890.93), SIMDE_FLOAT32_C(  -188.89), SIMDE_FLOAT32_C(   277.64) } },
    { { SIMDE_FLOAT32_C(   299.93), SIMDE_FLOAT32_C(   132.15), SIMDE_FLOAT32_C(  -176.04), SIMDE_FLOAT32_C(   602.01) },
      { SIMDE_FLOAT32_C(   395.84), SIMDE_FLOAT32_C(   482.13), SIMDE_FLOAT32_C(   505.78), SIMDE_FLOAT32_C(  -624.38) },
      { SIMDE_FLOAT32_C(  -176.04), SIMDE_FLOAT32_C(   505.78), SIMDE_FLOAT32_C(   602.01), SIMDE_FLOAT32_C(  -624.38) } },
    { { SIMDE_FLOAT32_C(  -485.02), SIMDE_FLOAT32_C(   246.12), SIMDE_FLOAT32_C(  -226.41), SIMDE_FLOAT32_C(  -660.41) },
      { SIMDE_FLOAT32_C(   304.88), SIMDE_FLOAT32_C(   546.13), SIMDE_FLOAT32_C(   742.69), SIMDE_FLOAT32_C(  -648.05) },
      { SIMDE_FLOAT32_C(  -226.41), SIMDE_FLOAT32_C(   742.69), SIMDE_FLOAT32_C(  -660.41), SIMDE_FLOAT32_C(  -648.05) } },
    { { SIMDE_FLOAT32_C(  -973.16), SIMDE_FLOAT32_C(   350.44), SIMDE_FLOAT32_C(   651.48), SIMDE_FLOAT32_C(  -776.37) },
      { SIMDE_FLOAT32_C(  -169.18), SIMDE_FLOAT32_C(   445.04), SIMDE_FLOAT32_C(  -966.52), SIMDE_FLOAT32_C(  -177.79) },
      { SIMDE_FLOAT32_C(   651.48), SIMDE_FLOAT32_C(  -966.52), SIMDE_FLOAT32_C(  -776.37), SIMDE_FLOAT32_C(  -177.79) } },
    { { SIMDE_FLOAT32_C(   625.71), SIMDE_FLOAT32_C(  -250.61), SIMDE_FLOAT32_C(   633.32), SIMDE_FLOAT32_C(   640.82) },
      { SIMDE_FLOAT32_C(   632.04), SIMDE_FLOAT32_C(   524.25), SIMDE_FLOAT32_C(   -81.55), SIMDE_FLOAT32_C(   -68.03) },
      { SIMDE_FLOAT32_C(   633.32), SIMDE_FLOAT32_C(   -81.55), SIMDE_FLOAT32_C(   640.82), SIMDE_FLOAT32_C(   -68.03) } },
    { { SIMDE_FLOAT32_C(  -343.59), SIMDE_FLOAT32_C(   742.42), SIMDE_FLOAT32_C(  -466.02), SIMDE_FLOAT32_C(  -947.75) },
      { SIMDE_FLOAT32_C(   224.55), SIMDE_FLOAT32_C(  -960.24), SIMDE_FLOAT32_C(  -572.13), SIMDE_FLOAT32_C(   739.52) },
      { SIMDE_FLOAT32_C(  -466.02), SIMDE_FLOAT32_C(  -572.13), SIMDE_FLOAT32_C(  -947.75), SIMDE_FLOAT32_C(   739.52) } },
    { { SIMDE_FLOAT32_C(   285.88), SIMDE_FLOAT32_C(   201.46), SIMDE_FLOAT32_C(  -920.88), SIMDE_FLOAT32_C(  -409.24) },
      { SIMDE_FLOAT32_C(  -252.40), SIMDE_FLOAT32_C(   821.81), SIMDE_FLOAT32_C(   -57.30), SIMDE_FLOAT32_C(  -225.56) },
      { SIMDE_FLOAT32_C(  -920.88), SIMDE_FLOAT32_C(   -57.30), SIMDE_FLOAT32_C(  -409.24), SIMDE_FLOAT32_C(  -225.56) } },
    { { SIMDE_FLOAT32_C(   172.25), SIMDE_FLOAT32_C(  -405.81), SIMDE_FLOAT32_C(    -1.92), SIMDE_FLOAT32_C(  -996.93) },
      { SIMDE_FLOAT32_C(  -960.77), SIMDE_FLOAT32_C(    31.56), SIMDE_FLOAT32_C(  -174.72), SIMDE_FLOAT32_C(   664.94) },
      { SIMDE_FLOAT32_C(    -1.92), SIMDE_FLOAT32_C(  -174.72), SIMDE_FLOAT32_C(  -996.93), SIMDE_FLOAT32_C(   664.94) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vzip2q_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vzip2q_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  85),  INT8_C(  12),  INT8_C(  36),  INT8_C(  28),  INT8_C( 122),  INT8_C( 111),  INT8_C(  64), -INT8_C(  98),
        -INT8_C(  65),  INT8_C(  75),  INT8_C(  48), -INT8_C(  66),  INT8_C(  91), -INT8_C(  17), -INT8_C(  68), -INT8_C(  84) },
      {  INT8_C(  66), -INT8_C( 115), -INT8_C(  31), -INT8_C(  33),  INT8_C(  20),      INT8_MIN,  INT8_C(   7), -INT8_C(  96),
        -INT8_C(  89), -INT8_C(  66), -INT8_C(  35),  INT8_C(   3),      INT8_MAX,  INT8_C(  12),  INT8_C(  18), -INT8_C(  44) },
      { -INT8_C(  65), -INT8_C(  89),  INT8_C(  75), -INT8_C(  66),  INT8_C(  48), -INT8_C(  35), -INT8_C(  66),  INT8_C(   3),
         INT8_C(  91),      INT8_MAX, -INT8_C(  17),  INT8_C(  12), -INT8_C(  68),  INT8_C(  18), -INT8_C(  84), -INT8_C(  44) } },
    { {  INT8_C(  25),  INT8_C(  54), -INT8_C(  15), -INT8_C( 109), -INT8_C(  90),  INT8_C(  49),  INT8_C(  49),  INT8_C( 101),
         INT8_C( 124),  INT8_C(  97),  INT8_C(  35), -INT8_C(  41),  INT8_C(  80), -INT8_C(  32), -INT8_C( 125), -INT8_C( 109) },
      {  INT8_C( 109),  INT8_C( 100),  INT8_C( 114), -INT8_C( 126), -INT8_C(  28),  INT8_C( 121),  INT8_C(  34), -INT8_C( 116),
         INT8_C(  56), -INT8_C(   1), -INT8_C( 113), -INT8_C(  73),  INT8_C(  12), -INT8_C(  94), -INT8_C( 117),  INT8_C(  37) },
      {  INT8_C( 124),  INT8_C(  56),  INT8_C(  97), -INT8_C(   1),  INT8_C(  35), -INT8_C( 113), -INT8_C(  41), -INT8_C(  73),
         INT8_C(  80),  INT8_C(  12), -INT8_C(  32), -INT8_C(  94), -INT8_C( 125), -INT8_C( 117), -INT8_C( 109),  INT8_C(  37) } },
    { { -INT8_C(  40),  INT8_C( 124), -INT8_C(  72),  INT8_C( 126), -INT8_C(  83), -INT8_C(  23), -INT8_C(  28),  INT8_C(  41),
         INT8_C(  74),  INT8_C(   7),  INT8_C(   0), -INT8_C( 102), -INT8_C(  25), -INT8_C( 125),  INT8_C(  45),  INT8_C(  85) },
      { -INT8_C(  25), -INT8_C(  97), -INT8_C(  41), -INT8_C(  52),  INT8_C(  25), -INT8_C(   7),  INT8_C(  88),  INT8_C(  81),
        -INT8_C(   7), -INT8_C(  25),  INT8_C(   8),  INT8_C(   5), -INT8_C( 119), -INT8_C( 109),  INT8_C(  42),  INT8_C(  98) },
      {  INT8_C(  74), -INT8_C(   7),  INT8_C(   7), -INT8_C(  25),  INT8_C(   0),  INT8_C(   8), -INT8_C( 102),  INT8_C(   5),
        -INT8_C(  25), -INT8_C( 119), -INT8_C( 125), -INT8_C( 109),  INT8_C(  45),  INT8_C(  42),  INT8_C(  85),  INT8_C(  98) } },
    { {  INT8_C(  16), -INT8_C(  30), -INT8_C(  32), -INT8_C(  67), -INT8_C(  53), -INT8_C(  60), -INT8_C(  25),  INT8_C(  21),
        -INT8_C(  52), -INT8_C(  25), -INT8_C(  81), -INT8_C(  77),  INT8_C( 107), -INT8_C(  35),  INT8_C(   8),  INT8_C(  82) },
      {  INT8_C( 124), -INT8_C(  33),  INT8_C(  30), -INT8_C( 107), -INT8_C(  39),  INT8_C( 118), -INT8_C(  26), -INT8_C(  46),
         INT8_C(  94), -INT8_C(  18), -INT8_C(  41), -INT8_C(  25), -INT8_C( 126),  INT8_C(   1),  INT8_C(  73), -INT8_C( 110) },
      { -INT8_C(  52),  INT8_C(  94), -INT8_C(  25), -INT8_C(  18), -INT8_C(  81), -INT8_C(  41), -INT8_C(  77), -INT8_C(  25),
         INT8_C( 107), -INT8_C( 126), -INT8_C(  35),  INT8_C(   1),  INT8_C(   8),  INT8_C(  73),  INT8_C(  82), -INT8_C( 110) } },
    { { -INT8_C(  29),  INT8_C(  42),  INT8_C(  79), -INT8_C(  82), -INT8_C(  18),  INT8_C(  54), -INT8_C(  61), -INT8_C(  70),
         INT8_C(  30),  INT8_C( 114),  INT8_C( 110), -INT8_C( 119),  INT8_C(  79),  INT8_C( 118), -INT8_C(  37), -INT8_C(  52) },
      {  INT8_C(  86), -INT8_C(   6),  INT8_C(  97),  INT8_C(  47),  INT8_C( 112),  INT8_C(  72),  INT8_C(   1), -INT8_C(  50),
         INT8_C(  54), -INT8_C(  40), -INT8_C(  74), -INT8_C(  72), -INT8_C(  39), -INT8_C(   1),  INT8_C(  74), -INT8_C(  68) },
      {  INT8_C(  30),  INT8_C(  54),  INT8_C( 114), -INT8_C(  40),  INT8_C( 110), -INT8_C(  74), -INT8_C( 119), -INT8_C(  72),
         INT8_C(  79), -INT8_C(  39),  INT8_C( 118), -INT8_C(   1), -INT8_C(  37),  INT8_C(  74), -INT8_C(  52), -INT8_C(  68) } },
    { {  INT8_C(  41), -INT8_C( 102),  INT8_C( 106),  INT8_C(  24), -INT8_C(  48),  INT8_C(  45), -INT8_C(  46), -INT8_C(  18),
        -INT8_C(  97),  INT8_C(  64),  INT8_C( 119), -INT8_C(  17), -INT8_C(  73),  INT8_C(  83), -INT8_C(  69),  INT8_C(  13) },
      {  INT8_C(  77),  INT8_C(  28),  INT8_C(  60), -INT8_C(  67),  INT8_C( 100),  INT8_C(  61), -INT8_C( 116), -INT8_C( 101),
         INT8_C(  21),  INT8_C(  66),  INT8_C(  83), -INT8_C(  18),  INT8_C(  65), -INT8_C(  98), -INT8_C(  86),  INT8_C( 107) },
      { -INT8_C(  97),  INT8_C(  21),  INT8_C(  64),  INT8_C(  66),  INT8_C( 119),  INT8_C(  83), -INT8_C(  17), -INT8_C(  18),
        -INT8_C(  73),  INT8_C(  65),  INT8_C(  83), -INT8_C(  98), -INT8_C(  69), -INT8_C(  86),  INT8_C(  13),  INT8_C( 107) } },
    { {  INT8_C(  56),  INT8_C(  20), -INT8_C( 125),  INT8_C(   8),  INT8_C(  65),  INT8_C(  85), -INT8_C(   9), -INT8_C(  32),
        -INT8_C( 106),  INT8_C( 110), -INT8_C(  49),  INT8_C(  77), -INT8_C(  63), -INT8_C( 118),  INT8_C(  90),  INT8_C(  14) },
      { -INT8_C(  89), -INT8_C( 106), -INT8_C(  52),  INT8_C(  11), -INT8_C(  45),  INT8_C(  88), -INT8_C(  90), -INT8_C(  24),
        -INT8_C( 102), -INT8_C(   6), -INT8_C(  42), -INT8_C(  37), -INT8_C( 104),      INT8_MIN,  INT8_C(  70), -INT8_C(  48) },
      { -INT8_C( 106), -INT8_C( 102),  INT8_C( 110), -INT8_C(   6), -INT8_C(  49), -INT8_C(  42),  INT8_C(  77), -INT8_C(  37),
        -INT8_C(  63), -INT8_C( 104), -INT8_C( 118),      INT8_MIN,  INT8_C(  90),  INT8_C(  70),  INT8_C(  14), -INT8_C(  48) } },
    { { -INT8_C( 108), -INT8_C(  55), -INT8_C(  40), -INT8_C(  43),  INT8_C(  31), -INT8_C(  49), -INT8_C(  75), -INT8_C(  75),
         INT8_C(  62), -INT8_C( 123),  INT8_C(   2), -INT8_C(   1),  INT8_C(  15),  INT8_C(  92),  INT8_C(  14), -INT8_C(  74) },
      { -INT8_C(  14), -INT8_C(  38), -INT8_C(  62), -INT8_C(  59),  INT8_C(  50),  INT8_C( 104), -INT8_C(  83), -INT8_C(  52),
         INT8_C(  98), -INT8_C( 125), -INT8_C(  89), -INT8_C(   6),  INT8_C(   3), -INT8_C(  18), -INT8_C(  54), -INT8_C( 105) },
      {  INT8_C(  62),  INT8_C(  98), -INT8_C( 123), -INT8_C( 125),  INT8_C(   2), -INT8_C(  89), -INT8_C(   1), -INT8_C(   6),
         INT8_C(  15),  INT8_C(   3),  INT8_C(  92), -INT8_C(  18),  INT8_C(  14), -INT8_C(  54), -INT8_C(  74), -INT8_C( 105) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vzip2q_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2q_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 29172),  INT16_C(  1064), -INT16_C( 10040), -INT16_C( 22031),  INT16_C( 23069),  INT16_C( 25595),  INT16_C( 31505), -INT16_C(  6235) },
      { -INT16_C( 20461), -INT16_C( 29355),  INT16_C( 11474), -INT16_C( 31606),  INT16_C(  1073), -INT16_C( 19233), -INT16_C( 22064), -INT16_C( 15219) },
      {  INT16_C( 23069),  INT16_C(  1073),  INT16_C( 25595), -INT16_C( 19233),  INT16_C( 31505), -INT16_C( 22064), -INT16_C(  6235), -INT16_C( 15219) } },
    { { -INT16_C( 19174), -INT16_C(  7224), -INT16_C( 18034), -INT16_C( 21620), -INT16_C( 30957),  INT16_C(  9231), -INT16_C( 19454),  INT16_C(  5644) },
      {  INT16_C( 24932),  INT16_C( 13987),  INT16_C( 11661), -INT16_C( 16710), -INT16_C( 26319),  INT16_C(   370),  INT16_C(    67),  INT16_C( 24006) },
      { -INT16_C( 30957), -INT16_C( 26319),  INT16_C(  9231),  INT16_C(   370), -INT16_C( 19454),  INT16_C(    67),  INT16_C(  5644),  INT16_C( 24006) } },
    { { -INT16_C( 29003),  INT16_C( 17216), -INT16_C( 13240),  INT16_C( 23535), -INT16_C(   428),  INT16_C( 22144), -INT16_C( 29518),  INT16_C(  5740) },
      {  INT16_C(  4077),  INT16_C( 31308),  INT16_C(  1852),  INT16_C( 27960), -INT16_C( 21856), -INT16_C(  7313),  INT16_C( 13738),  INT16_C( 24641) },
      { -INT16_C(   428), -INT16_C( 21856),  INT16_C( 22144), -INT16_C(  7313), -INT16_C( 29518),  INT16_C( 13738),  INT16_C(  5740),  INT16_C( 24641) } },
    { { -INT16_C( 32317),  INT16_C(  2979), -INT16_C( 28082), -INT16_C( 23961), -INT16_C(  6256),  INT16_C( 17144),  INT16_C( 25971),  INT16_C( 24664) },
      { -INT16_C( 23180), -INT16_C( 20006),  INT16_C(  4780),  INT16_C( 19486), -INT16_C( 29252),  INT16_C( 26416),  INT16_C( 29122), -INT16_C( 31033) },
      { -INT16_C(  6256), -INT16_C( 29252),  INT16_C( 17144),  INT16_C( 26416),  INT16_C( 25971),  INT16_C( 29122),  INT16_C( 24664), -INT16_C( 31033) } },
    { {  INT16_C( 27378),  INT16_C( 16529), -INT16_C(  1795), -INT16_C( 29214), -INT16_C(  9249),  INT16_C( 21200),  INT16_C( 10304), -INT16_C( 19278) },
      { -INT16_C( 29491),  INT16_C( 31077), -INT16_C( 31586),  INT16_C( 23494), -INT16_C(  2543), -INT16_C( 11070), -INT16_C( 30361),  INT16_C( 22874) },
      { -INT16_C(  9249), -INT16_C(  2543),  INT16_C( 21200), -INT16_C( 11070),  INT16_C( 10304), -INT16_C( 30361), -INT16_C( 19278),  INT16_C( 22874) } },
    { { -INT16_C(  5133), -INT16_C(  3942),  INT16_C( 31972), -INT16_C( 15490),  INT16_C( 20055), -INT16_C( 26858), -INT16_C( 14218),  INT16_C( 17484) },
      { -INT16_C( 20139), -INT16_C(  3139), -INT16_C( 31947),  INT16_C( 18254),  INT16_C(  4217), -INT16_C(  8165),  INT16_C( 30105), -INT16_C( 29382) },
      {  INT16_C( 20055),  INT16_C(  4217), -INT16_C( 26858), -INT16_C(  8165), -INT16_C( 14218),  INT16_C( 30105),  INT16_C( 17484), -INT16_C( 29382) } },
    { { -INT16_C( 11168),  INT16_C( 17533), -INT16_C(  1200), -INT16_C( 22520),  INT16_C(  7753), -INT16_C( 16321), -INT16_C( 29722),  INT16_C( 15108) },
      { -INT16_C( 16067),  INT16_C( 29231),  INT16_C( 32069), -INT16_C( 16711), -INT16_C( 11122),  INT16_C( 10143), -INT16_C(  9911), -INT16_C( 21836) },
      {  INT16_C(  7753), -INT16_C( 11122), -INT16_C( 16321),  INT16_C( 10143), -INT16_C( 29722), -INT16_C(  9911),  INT16_C( 15108), -INT16_C( 21836) } },
    { {  INT16_C( 12973), -INT16_C(   530), -INT16_C(  2515),  INT16_C( 30629), -INT16_C(  6892), -INT16_C(  1225),  INT16_C( 15216), -INT16_C( 21194) },
      {  INT16_C( 26108),  INT16_C( 16672), -INT16_C(  9757),  INT16_C( 28928), -INT16_C( 24658), -INT16_C(  2152),  INT16_C( 19832),  INT16_C(  9633) },
      { -INT16_C(  6892), -INT16_C( 24658), -INT16_C(  1225), -INT16_C(  2152),  INT16_C( 15216),  INT16_C( 19832), -INT16_C( 21194),  INT16_C(  9633) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vzip2q_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2q_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   447870806),  INT32_C(  1960556641),  INT32_C(  1546653011), -INT32_C(   295568563) },
      { -INT32_C(   145715186),  INT32_C(  1570097258), -INT32_C(  1928396662), -INT32_C(   810854875) },
      {  INT32_C(  1546653011), -INT32_C(  1928396662), -INT32_C(   295568563), -INT32_C(   810854875) } },
    { { -INT32_C(  1078593186),  INT32_C(    70553777), -INT32_C(   345938787),  INT32_C(  1842987615) },
      { -INT32_C(  1134220974),  INT32_C(  2065300209),  INT32_C(   537471482), -INT32_C(   554716033) },
      { -INT32_C(   345938787),  INT32_C(   537471482),  INT32_C(  1842987615), -INT32_C(   554716033) } },
    { {  INT32_C(  1604166829), -INT32_C(   765210316), -INT32_C(  1782725579), -INT32_C(   654141818) },
      { -INT32_C(  1332385857),  INT32_C(  1546366817),  INT32_C(  1467757784), -INT32_C(  1774883864) },
      { -INT32_C(  1782725579),  INT32_C(  1467757784), -INT32_C(   654141818), -INT32_C(  1774883864) } },
    { {  INT32_C(  1156961040), -INT32_C(   636069724), -INT32_C(  1552952547),  INT32_C(   679244137) },
      {  INT32_C(   987239129), -INT32_C(  1718221631),  INT32_C(   569381432), -INT32_C(  1900599682) },
      { -INT32_C(  1552952547),  INT32_C(   569381432),  INT32_C(   679244137), -INT32_C(  1900599682) } },
    { { -INT32_C(  1647137543),  INT32_C(   561506564),  INT32_C(   650503868),  INT32_C(   827212120) },
      {  INT32_C(   342566739),  INT32_C(  1672282667), -INT32_C(  1836802540), -INT32_C(  1121961020) },
      {  INT32_C(   650503868), -INT32_C(  1836802540),  INT32_C(   827212120), -INT32_C(  1121961020) } },
    { { -INT32_C(   329583641), -INT32_C(  1743924516),  INT32_C(   280941240),  INT32_C(  1732316436) },
      {  INT32_C(  1602006324), -INT32_C(  1010685521), -INT32_C(  1957279801),  INT32_C(  1783133826) },
      {  INT32_C(   280941240), -INT32_C(  1957279801),  INT32_C(  1732316436),  INT32_C(  1783133826) } },
    { {  INT32_C(  1163305833),  INT32_C(   769549173),  INT32_C(  1245617206), -INT32_C(   575570007) },
      { -INT32_C(   616813268),  INT32_C(   513802071), -INT32_C(   928320186), -INT32_C(   718081429) },
      {  INT32_C(  1245617206), -INT32_C(   928320186), -INT32_C(   575570007), -INT32_C(   718081429) } },
    { {  INT32_C(   169511061),  INT32_C(   574159084),  INT32_C(  1047295637),  INT32_C(   572268021) },
      { -INT32_C(  1560455093), -INT32_C(  1648321449), -INT32_C(    43619695), -INT32_C(   221079459) },
      {  INT32_C(  1047295637), -INT32_C(    43619695),  INT32_C(   572268021), -INT32_C(   221079459) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vzip2q_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2q_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 3389154455161181546),  INT64_C( 7789600881989832426) },
      { -INT64_C( 6216138325886961127),  INT64_C( 8128889602060271500) },
      {  INT64_C( 7789600881989832426),  INT64_C( 8128889602060271500) } },
    { {  INT64_C( 4280588231775133491), -INT64_C( 3843400407768008318) },
      { -INT64_C( 2503139029515142790),  INT64_C( 4595617808483249743) },
      { -INT64_C( 3843400407768008318),  INT64_C( 4595617808483249743) } },
    { { -INT64_C( 6190516375007038583),  INT64_C( 8490571704889211736) },
      { -INT64_C( 8558999586011666166), -INT64_C( 4175499598915218751) },
      {  INT64_C( 8490571704889211736), -INT64_C( 4175499598915218751) } },
    { { -INT64_C( 4905907207152761576),  INT64_C( 7900326818308542771) },
      { -INT64_C( 4070128137537015102),  INT64_C( 2402004138219365202) },
      {  INT64_C( 7900326818308542771),  INT64_C( 2402004138219365202) } },
    { { -INT64_C( 2286056552104069593),  INT64_C( 7416498006436743965) },
      {  INT64_C(  518167619684185188), -INT64_C( 8109598195675904694) },
      {  INT64_C( 7416498006436743965), -INT64_C( 8109598195675904694) } },
    { {  INT64_C( 4498921349512353505), -INT64_C( 7820595108767695508) },
      {  INT64_C(  727944592766064991),  INT64_C( 9001237270419583218) },
      { -INT64_C( 7820595108767695508),  INT64_C( 9001237270419583218) } },
    { { -INT64_C( 3312544423324482393), -INT64_C( 3478649799431698953) },
      { -INT64_C( 3026702744038492620), -INT64_C( 3115054789748040787) },
      { -INT64_C( 3478649799431698953), -INT64_C( 3115054789748040787) } },
    { {  INT64_C( 4780188694459830302), -INT64_C( 4059675570677991062) },
      {  INT64_C( 3931846471610764248), -INT64_C(  498416479562121196) },
      { -INT64_C( 4059675570677991062), -INT64_C(  498416479562121196) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vzip2q_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2q_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(127), UINT8_C( 19), UINT8_C(254), UINT8_C( 88), UINT8_C( 56), UINT8_C( 15), UINT8_C( 99), UINT8_C( 77),
        UINT8_C( 51), UINT8_C(112), UINT8_C( 89), UINT8_C(110), UINT8_C(170), UINT8_C( 43), UINT8_C( 97), UINT8_C( 38) },
      { UINT8_C(185), UINT8_C(103), UINT8_C( 79), UINT8_C(147), UINT8_C(  2), UINT8_C( 18), UINT8_C(242), UINT8_C(119),
        UINT8_C( 51), UINT8_C( 19), UINT8_C( 24), UINT8_C( 45), UINT8_C(135), UINT8_C(119), UINT8_C(  0), UINT8_C(  6) },
      { UINT8_C( 51), UINT8_C( 51), UINT8_C(112), UINT8_C( 19), UINT8_C( 89), UINT8_C( 24), UINT8_C(110), UINT8_C( 45),
        UINT8_C(170), UINT8_C(135), UINT8_C( 43), UINT8_C(119), UINT8_C( 97), UINT8_C(  0), UINT8_C( 38), UINT8_C(  6) } },
    { { UINT8_C(139), UINT8_C(254), UINT8_C( 95), UINT8_C(195), UINT8_C( 14), UINT8_C(194), UINT8_C( 16), UINT8_C( 65),
        UINT8_C( 50), UINT8_C(105), UINT8_C(175), UINT8_C(220), UINT8_C(148), UINT8_C( 16), UINT8_C(  3), UINT8_C( 78) },
      { UINT8_C(120), UINT8_C( 82), UINT8_C(225), UINT8_C(122), UINT8_C(100), UINT8_C(211), UINT8_C(241), UINT8_C(151),
        UINT8_C(230), UINT8_C( 10), UINT8_C(196), UINT8_C(109), UINT8_C(129), UINT8_C(196), UINT8_C(116), UINT8_C( 12) },
      { UINT8_C( 50), UINT8_C(230), UINT8_C(105), UINT8_C( 10), UINT8_C(175), UINT8_C(196), UINT8_C(220), UINT8_C(109),
        UINT8_C(148), UINT8_C(129), UINT8_C( 16), UINT8_C(196), UINT8_C(  3), UINT8_C(116), UINT8_C( 78), UINT8_C( 12) } },
    { { UINT8_C(195), UINT8_C(211), UINT8_C(207), UINT8_C(209), UINT8_C(149), UINT8_C(223), UINT8_C( 18), UINT8_C(199),
        UINT8_C( 72), UINT8_C(193), UINT8_C(163), UINT8_C(221), UINT8_C(210), UINT8_C(166), UINT8_C( 43), UINT8_C( 74) },
      { UINT8_C(248), UINT8_C( 12), UINT8_C(196), UINT8_C( 93), UINT8_C(223), UINT8_C(182), UINT8_C(244), UINT8_C(197),
        UINT8_C(192), UINT8_C(185), UINT8_C( 51), UINT8_C( 65), UINT8_C(125), UINT8_C(167), UINT8_C( 78), UINT8_C( 64) },
      { UINT8_C( 72), UINT8_C(192), UINT8_C(193), UINT8_C(185), UINT8_C(163), UINT8_C( 51), UINT8_C(221), UINT8_C( 65),
        UINT8_C(210), UINT8_C(125), UINT8_C(166), UINT8_C(167), UINT8_C( 43), UINT8_C( 78), UINT8_C( 74), UINT8_C( 64) } },
    { { UINT8_C(122), UINT8_C( 29), UINT8_C( 17), UINT8_C( 15), UINT8_C(253), UINT8_C( 35), UINT8_C(214), UINT8_C( 69),
        UINT8_C(229), UINT8_C(121), UINT8_C( 34), UINT8_C(183), UINT8_C( 32), UINT8_C( 77), UINT8_C(  1), UINT8_C( 24) },
      { UINT8_C( 89), UINT8_C(197), UINT8_C(117), UINT8_C( 56), UINT8_C(123), UINT8_C(106), UINT8_C(254), UINT8_C( 59),
        UINT8_C( 35), UINT8_C( 49), UINT8_C(125), UINT8_C(160), UINT8_C(216), UINT8_C(203), UINT8_C(225), UINT8_C( 82) },
      { UINT8_C(229), UINT8_C( 35), UINT8_C(121), UINT8_C( 49), UINT8_C( 34), UINT8_C(125), UINT8_C(183), UINT8_C(160),
        UINT8_C( 32), UINT8_C(216), UINT8_C( 77), UINT8_C(203), UINT8_C(  1), UINT8_C(225), UINT8_C( 24), UINT8_C( 82) } },
    { { UINT8_C(232), UINT8_C(242), UINT8_C( 97), UINT8_C(229), UINT8_C( 22), UINT8_C( 55), UINT8_C( 43), UINT8_C(251),
        UINT8_C(176), UINT8_C( 77), UINT8_C(178), UINT8_C(208), UINT8_C(155), UINT8_C(179), UINT8_C(233), UINT8_C(244) },
      { UINT8_C(120), UINT8_C( 94), UINT8_C( 45), UINT8_C(244), UINT8_C(200), UINT8_C( 43), UINT8_C( 47), UINT8_C(235),
        UINT8_C( 92), UINT8_C(172), UINT8_C(140), UINT8_C( 52), UINT8_C(119), UINT8_C(109), UINT8_C(134), UINT8_C( 96) },
      { UINT8_C(176), UINT8_C( 92), UINT8_C( 77), UINT8_C(172), UINT8_C(178), UINT8_C(140), UINT8_C(208), UINT8_C( 52),
        UINT8_C(155), UINT8_C(119), UINT8_C(179), UINT8_C(109), UINT8_C(233), UINT8_C(134), UINT8_C(244), UINT8_C( 96) } },
    { { UINT8_C( 95), UINT8_C(231), UINT8_C( 69), UINT8_C(117), UINT8_C( 30), UINT8_C(112), UINT8_C(112), UINT8_C(206),
        UINT8_C(190), UINT8_C( 34), UINT8_C(159), UINT8_C( 89), UINT8_C(213), UINT8_C(136), UINT8_C( 77), UINT8_C( 78) },
      { UINT8_C(230), UINT8_C(122), UINT8_C( 66), UINT8_C(175), UINT8_C(165), UINT8_C(113), UINT8_C(154), UINT8_C(  1),
        UINT8_C( 30), UINT8_C( 38), UINT8_C( 53), UINT8_C(149), UINT8_C(147), UINT8_C(187), UINT8_C(245), UINT8_C(243) },
      { UINT8_C(190), UINT8_C( 30), UINT8_C( 34), UINT8_C( 38), UINT8_C(159), UINT8_C( 53), UINT8_C( 89), UINT8_C(149),
        UINT8_C(213), UINT8_C(147), UINT8_C(136), UINT8_C(187), UINT8_C( 77), UINT8_C(245), UINT8_C( 78), UINT8_C(243) } },
    { { UINT8_C(162), UINT8_C( 59), UINT8_C(104), UINT8_C(192), UINT8_C(171), UINT8_C(217), UINT8_C(143), UINT8_C(105),
        UINT8_C(251), UINT8_C( 46), UINT8_C(194), UINT8_C(209), UINT8_C(182), UINT8_C( 16), UINT8_C( 31), UINT8_C(156) },
      { UINT8_C(138), UINT8_C( 97), UINT8_C( 75), UINT8_C( 48), UINT8_C(210), UINT8_C(230), UINT8_C( 49), UINT8_C(240),
        UINT8_C( 12), UINT8_C(103), UINT8_C(134), UINT8_C(160), UINT8_C( 34), UINT8_C(123), UINT8_C(147), UINT8_C(197) },
      { UINT8_C(251), UINT8_C( 12), UINT8_C( 46), UINT8_C(103), UINT8_C(194), UINT8_C(134), UINT8_C(209), UINT8_C(160),
        UINT8_C(182), UINT8_C( 34), UINT8_C( 16), UINT8_C(123), UINT8_C( 31), UINT8_C(147), UINT8_C(156), UINT8_C(197) } },
    { { UINT8_C(182), UINT8_C(251), UINT8_C(133), UINT8_C( 98), UINT8_C(212), UINT8_C( 20), UINT8_C(203), UINT8_C(208),
        UINT8_C( 66), UINT8_C(142), UINT8_C(161), UINT8_C(248), UINT8_C(158), UINT8_C(192), UINT8_C(149), UINT8_C( 40) },
      { UINT8_C( 33), UINT8_C(224), UINT8_C( 88), UINT8_C(243), UINT8_C(198), UINT8_C(138), UINT8_C(228), UINT8_C(211),
        UINT8_C(241), UINT8_C(106), UINT8_C(115), UINT8_C( 19), UINT8_C(229), UINT8_C(  6), UINT8_C(216), UINT8_C(156) },
      { UINT8_C( 66), UINT8_C(241), UINT8_C(142), UINT8_C(106), UINT8_C(161), UINT8_C(115), UINT8_C(248), UINT8_C( 19),
        UINT8_C(158), UINT8_C(229), UINT8_C(192), UINT8_C(  6), UINT8_C(149), UINT8_C(216), UINT8_C( 40), UINT8_C(156) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vzip2q_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2q_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(56843), UINT16_C(48859), UINT16_C(62267), UINT16_C(16307), UINT16_C(14313), UINT16_C(51328), UINT16_C(63506), UINT16_C(34614) },
      { UINT16_C(29688), UINT16_C(53182), UINT16_C(19541), UINT16_C(62702), UINT16_C(38625), UINT16_C( 4081), UINT16_C(60683), UINT16_C( 5668) },
      { UINT16_C(14313), UINT16_C(38625), UINT16_C(51328), UINT16_C( 4081), UINT16_C(63506), UINT16_C(60683), UINT16_C(34614), UINT16_C( 5668) } },
    { { UINT16_C(65484), UINT16_C( 2005), UINT16_C(35058), UINT16_C(56390), UINT16_C(51135), UINT16_C(53668), UINT16_C(55999), UINT16_C(46936) },
      { UINT16_C( 5965), UINT16_C(41607), UINT16_C(30051), UINT16_C(17814), UINT16_C(34571), UINT16_C( 5716), UINT16_C(31093), UINT16_C(16685) },
      { UINT16_C(51135), UINT16_C(34571), UINT16_C(53668), UINT16_C( 5716), UINT16_C(55999), UINT16_C(31093), UINT16_C(46936), UINT16_C(16685) } },
    { { UINT16_C(  632), UINT16_C(27464), UINT16_C(36490), UINT16_C(19015), UINT16_C(60245), UINT16_C( 5403), UINT16_C(29893), UINT16_C( 5068) },
      { UINT16_C(21387), UINT16_C(61109), UINT16_C(19657), UINT16_C(54323), UINT16_C(35027), UINT16_C(18667), UINT16_C( 6145), UINT16_C(31113) },
      { UINT16_C(60245), UINT16_C(35027), UINT16_C( 5403), UINT16_C(18667), UINT16_C(29893), UINT16_C( 6145), UINT16_C( 5068), UINT16_C(31113) } },
    { { UINT16_C(53530), UINT16_C(42212), UINT16_C(11104), UINT16_C(46574), UINT16_C( 2582), UINT16_C(56522), UINT16_C(38782), UINT16_C( 2543) },
      { UINT16_C(42218), UINT16_C(46071), UINT16_C(11248), UINT16_C(50312), UINT16_C(29619), UINT16_C(46092), UINT16_C(38539), UINT16_C(42285) },
      { UINT16_C( 2582), UINT16_C(29619), UINT16_C(56522), UINT16_C(46092), UINT16_C(38782), UINT16_C(38539), UINT16_C( 2543), UINT16_C(42285) } },
    { { UINT16_C( 4711), UINT16_C(51017), UINT16_C(14397), UINT16_C(21629), UINT16_C(18242), UINT16_C(49200), UINT16_C( 8158), UINT16_C(51657) },
      { UINT16_C(49347), UINT16_C(46204), UINT16_C( 1259), UINT16_C(40568), UINT16_C(33911), UINT16_C(  594), UINT16_C(32794), UINT16_C(33447) },
      { UINT16_C(18242), UINT16_C(33911), UINT16_C(49200), UINT16_C(  594), UINT16_C( 8158), UINT16_C(32794), UINT16_C(51657), UINT16_C(33447) } },
    { { UINT16_C(61842), UINT16_C(53065), UINT16_C(50729), UINT16_C(27427), UINT16_C(21262), UINT16_C(60459), UINT16_C(62578), UINT16_C(14005) },
      { UINT16_C(12980), UINT16_C(41194), UINT16_C(25142), UINT16_C(44606), UINT16_C(37350), UINT16_C(  432), UINT16_C(22545), UINT16_C(41859) },
      { UINT16_C(21262), UINT16_C(37350), UINT16_C(60459), UINT16_C(  432), UINT16_C(62578), UINT16_C(22545), UINT16_C(14005), UINT16_C(41859) } },
    { { UINT16_C(52297), UINT16_C(29298), UINT16_C(38547), UINT16_C(41437), UINT16_C( 2281), UINT16_C(23693), UINT16_C(17404), UINT16_C(45202) },
      { UINT16_C(31861), UINT16_C(43856), UINT16_C(36830), UINT16_C(50265), UINT16_C( 2592), UINT16_C(12741), UINT16_C(18530), UINT16_C(43988) },
      { UINT16_C( 2281), UINT16_C( 2592), UINT16_C(23693), UINT16_C(12741), UINT16_C(17404), UINT16_C(18530), UINT16_C(45202), UINT16_C(43988) } },
    { { UINT16_C(17941), UINT16_C(43037), UINT16_C(64220), UINT16_C(50761), UINT16_C(54786), UINT16_C(65058), UINT16_C(46105), UINT16_C(36526) },
      { UINT16_C(65328), UINT16_C( 3642), UINT16_C(37774), UINT16_C(44754), UINT16_C(39069), UINT16_C(65503), UINT16_C(46048), UINT16_C(62890) },
      { UINT16_C(54786), UINT16_C(39069), UINT16_C(65058), UINT16_C(65503), UINT16_C(46105), UINT16_C(46048), UINT16_C(36526), UINT16_C(62890) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vzip2q_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2q_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 478890778), UINT32_C(1273886894), UINT32_C( 298449113), UINT32_C(1553786033) },
      { UINT32_C(3000604583), UINT32_C(2965413592), UINT32_C(2252713574), UINT32_C(1703353163) },
      { UINT32_C( 298449113), UINT32_C(2252713574), UINT32_C(1553786033), UINT32_C(1703353163) } },
    { { UINT32_C( 360780391), UINT32_C(3831524875), UINT32_C( 418720102), UINT32_C(3027538189) },
      { UINT32_C(   6769960), UINT32_C(1387341804), UINT32_C( 551089877), UINT32_C(2038849298) },
      { UINT32_C( 418720102), UINT32_C( 551089877), UINT32_C(3027538189), UINT32_C(2038849298) } },
    { { UINT32_C(2106460018), UINT32_C(3697405814), UINT32_C( 653547032), UINT32_C( 265972199) },
      { UINT32_C(2718974390), UINT32_C(1056227688), UINT32_C(3378433207), UINT32_C(2655183916) },
      { UINT32_C( 653547032), UINT32_C(3378433207), UINT32_C( 265972199), UINT32_C(2655183916) } },
    { { UINT32_C(1645990380), UINT32_C(3627973824), UINT32_C(3120444370), UINT32_C(1388894620) },
      { UINT32_C(2213926938), UINT32_C(1371662745), UINT32_C(3793362870), UINT32_C(4034944260) },
      { UINT32_C(3120444370), UINT32_C(3793362870), UINT32_C(1388894620), UINT32_C(4034944260) } },
    { { UINT32_C(3998391086), UINT32_C(3922104343), UINT32_C(1604502979), UINT32_C(3098700446) },
      { UINT32_C(3694896963), UINT32_C(1177418896), UINT32_C( 539510812), UINT32_C(3541084325) },
      { UINT32_C(1604502979), UINT32_C( 539510812), UINT32_C(3098700446), UINT32_C(3541084325) } },
    { { UINT32_C(1522623043), UINT32_C(3057879026), UINT32_C(3927303500), UINT32_C(2476984144) },
      { UINT32_C(4285521518), UINT32_C(4148534747), UINT32_C(2316791525), UINT32_C(1516054294) },
      { UINT32_C(3927303500), UINT32_C(2316791525), UINT32_C(2476984144), UINT32_C(1516054294) } },
    { { UINT32_C(2075401865), UINT32_C(4063361189), UINT32_C( 769411037), UINT32_C(2109767438) },
      { UINT32_C( 964440158), UINT32_C(2989539789), UINT32_C(1178355503), UINT32_C(4154497390) },
      { UINT32_C( 769411037), UINT32_C(1178355503), UINT32_C(2109767438), UINT32_C(4154497390) } },
    { { UINT32_C(1550996663), UINT32_C( 709796940), UINT32_C(4183239659), UINT32_C( 141957290) },
      { UINT32_C( 356643400), UINT32_C(3821498804), UINT32_C( 640222136), UINT32_C(1394461084) },
      { UINT32_C(4183239659), UINT32_C( 640222136), UINT32_C( 141957290), UINT32_C(1394461084) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vzip2q_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vzip2q_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 4280958701235489246), UINT64_C(11535681782777318835) },
      { UINT64_C( 6878166422813626130), UINT64_C(12381793737624657829) },
      { UINT64_C(11535681782777318835), UINT64_C(12381793737624657829) } },
    { { UINT64_C(14969386940695648064), UINT64_C( 3104490981576679679) },
      { UINT64_C(13112230382089857197), UINT64_C( 8545878496494894880) },
      { UINT64_C( 3104490981576679679), UINT64_C( 8545878496494894880) } },
    { { UINT64_C( 1374078459952243238), UINT64_C( 7285027289849944533) },
      { UINT64_C(14288505062639445382), UINT64_C(13466410036153779510) },
      { UINT64_C( 7285027289849944533), UINT64_C(13466410036153779510) } },
    { { UINT64_C( 7247714085351774830), UINT64_C( 4721016760819653991) },
      { UINT64_C(12717357733718164241), UINT64_C(17002494307029758118) },
      { UINT64_C( 4721016760819653991), UINT64_C(17002494307029758118) } },
    { { UINT64_C( 7263466160932188377), UINT64_C(11249156841034424097) },
      { UINT64_C(13453888246246536075), UINT64_C(12135486648795582720) },
      { UINT64_C(11249156841034424097), UINT64_C(12135486648795582720) } },
    { { UINT64_C(18103026683644860376), UINT64_C( 5847067349770288893) },
      { UINT64_C( 5239669095272970216), UINT64_C( 7805915270211808220) },
      { UINT64_C( 5847067349770288893), UINT64_C( 7805915270211808220) } },
    { { UINT64_C( 4673466768805750021), UINT64_C(10327578197059285819) },
      { UINT64_C(10372990280714201189), UINT64_C(17217137029729139438) },
      { UINT64_C(10327578197059285819), UINT64_C(17217137029729139438) } },
    { { UINT64_C(16823101498774663667), UINT64_C(10561851715167600732) },
      { UINT64_C( 5847417664724475876), UINT64_C(16412457277402079725) },
      { UINT64_C(10561851715167600732), UINT64_C(16412457277402079725) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vzip2q_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vzip2q_u64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
