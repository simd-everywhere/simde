#define SIMDE_TEST_ARM_NEON_INSN and

#include "test-neon.h"
#include "../../../simde/arm/neon/and.h"

static int
test_simde_vand_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  20), -INT8_C(  27), -INT8_C( 113),  INT8_C(  29),  INT8_C( 103),  INT8_C(   9), -INT8_C( 114),  INT8_C(  56) },
      { -INT8_C(  67),  INT8_C(  79),  INT8_C( 119), -INT8_C(  97),  INT8_C(  47),  INT8_C(  81), -INT8_C(  48),  INT8_C(  83) },
      {  INT8_C(  20),  INT8_C(  69),  INT8_C(   7),  INT8_C(  29),  INT8_C(  39),  INT8_C(   1),      INT8_MIN,  INT8_C(  16) } },
    { {  INT8_C(  49),  INT8_C(   9), -INT8_C(  33),  INT8_C(  41), -INT8_C(  35),  INT8_C( 105), -INT8_C(  38),  INT8_C(  92) },
      { -INT8_C(  11), -INT8_C(  35), -INT8_C(  64), -INT8_C(  71),  INT8_C(  47), -INT8_C(  42), -INT8_C(  74),  INT8_C(  67) },
      {  INT8_C(  49),  INT8_C(   9), -INT8_C(  64),  INT8_C(  41),  INT8_C(  13),  INT8_C(  64), -INT8_C( 110),  INT8_C(  64) } },
    { { -INT8_C(  69),  INT8_C(  69),  INT8_C(  96),  INT8_C(  34),  INT8_C(  78), -INT8_C(  18),  INT8_C(  90),  INT8_C(  11) },
      {  INT8_C(  61), -INT8_C(  46), -INT8_C(  86),  INT8_C( 108),  INT8_C(  35),  INT8_C( 123), -INT8_C(  64),  INT8_C(  84) },
      {  INT8_C(  57),  INT8_C(  64),  INT8_C(  32),  INT8_C(  32),  INT8_C(   2),  INT8_C( 106),  INT8_C(  64),  INT8_C(   0) } },
    { { -INT8_C( 124), -INT8_C(  97),  INT8_C( 126),  INT8_C(  97),  INT8_C(   8),  INT8_C(  88), -INT8_C(  67), -INT8_C(   3) },
      {  INT8_C(  53),  INT8_C( 125), -INT8_C(  73),  INT8_C( 101),  INT8_C(  83),  INT8_C( 109), -INT8_C(  88),  INT8_C(  15) },
      {  INT8_C(   4),  INT8_C(  29),  INT8_C(  54),  INT8_C(  97),  INT8_C(   0),  INT8_C(  72), -INT8_C(  88),  INT8_C(  13) } },
    { { -INT8_C(  78),  INT8_C(   9),  INT8_C(  49),  INT8_C(   1), -INT8_C(   9), -INT8_C( 116),  INT8_C(  12),  INT8_C(  53) },
      {  INT8_C(  94), -INT8_C(  73), -INT8_C(  95), -INT8_C( 127),  INT8_C(  50),  INT8_C(  97), -INT8_C(  42), -INT8_C(  74) },
      {  INT8_C(  18),  INT8_C(   1),  INT8_C(  33),  INT8_C(   1),  INT8_C(  50),  INT8_C(   0),  INT8_C(   4),  INT8_C(  52) } },
    { {  INT8_C(   1),  INT8_C(  84),  INT8_C(  23),  INT8_C(   9), -INT8_C(  84), -INT8_C(  44),  INT8_C(   7), -INT8_C(  31) },
      {  INT8_C(  82), -INT8_C(  66),  INT8_C(  70), -INT8_C(  91),  INT8_C(  43), -INT8_C(  17), -INT8_C(  76), -INT8_C(  35) },
      {  INT8_C(   0),  INT8_C(  20),  INT8_C(   6),  INT8_C(   1),  INT8_C(  40), -INT8_C(  60),  INT8_C(   4), -INT8_C(  63) } },
    { { -INT8_C(   8), -INT8_C(  26), -INT8_C(  34), -INT8_C(  17),  INT8_C( 114), -INT8_C(  21),  INT8_C(  36), -INT8_C(  48) },
      { -INT8_C(  94), -INT8_C(  58),  INT8_C(  81), -INT8_C(  44),  INT8_C(  39),  INT8_C(  39), -INT8_C( 118),  INT8_C(  40) },
      { -INT8_C(  96), -INT8_C(  58),  INT8_C(  80), -INT8_C(  60),  INT8_C(  34),  INT8_C(  35),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 123), -INT8_C(  95),  INT8_C(  50),  INT8_C(  39),  INT8_C( 117),  INT8_C(  57),  INT8_C(   9), -INT8_C(  57) },
      { -INT8_C(   9),  INT8_C(  79),  INT8_C( 109),  INT8_C(  34),  INT8_C(  62),  INT8_C(  33), -INT8_C(   1),  INT8_C(  54) },
      {  INT8_C( 115),  INT8_C(   1),  INT8_C(  32),  INT8_C(  34),  INT8_C(  52),  INT8_C(  33),  INT8_C(   9),  INT8_C(   6) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vand_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vand_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  8050),  INT16_C( 12298),  INT16_C(  9128), -INT16_C( 13417) },
      {  INT16_C( 29717),  INT16_C(  1908),  INT16_C( 23523), -INT16_C( 22120) },
      {  INT16_C( 24580),  INT16_C(     0),  INT16_C(   928), -INT16_C( 30320) } },
    { { -INT16_C( 24520),  INT16_C( 23713),  INT16_C(  7198), -INT16_C( 10071) },
      { -INT16_C(  5627), -INT16_C(  9529), -INT16_C( 12877),  INT16_C( 17102) },
      { -INT16_C( 24576),  INT16_C( 22657),  INT16_C(  3090),  INT16_C( 16520) } },
    { { -INT16_C(  9811),  INT16_C( 22130),  INT16_C(  2556),  INT16_C(  4385) },
      { -INT16_C( 27010),  INT16_C( 24856), -INT16_C( 19983),  INT16_C( 10507) },
      { -INT16_C( 28628),  INT16_C( 16400),  INT16_C(   496),  INT16_C(   257) } },
    { { -INT16_C( 21423),  INT16_C( 28550),  INT16_C( 12233), -INT16_C( 12729) },
      {  INT16_C(  3609), -INT16_C( 12888),  INT16_C( 30427), -INT16_C( 30449) },
      {  INT16_C(  3089),  INT16_C( 19840),  INT16_C(  9929), -INT16_C( 30713) } },
    { { -INT16_C( 32433),  INT16_C( 19679),  INT16_C(   138),  INT16_C(  2141) },
      {  INT16_C( 30358), -INT16_C( 30614),  INT16_C( 29991),  INT16_C( 30897) },
      {  INT16_C(     6),  INT16_C(  2122),  INT16_C(     2),  INT16_C(  2065) } },
    { {  INT16_C( 14113), -INT16_C(  5401),  INT16_C( 12134), -INT16_C( 32584) },
      {  INT16_C( 24637),  INT16_C(  6477),  INT16_C( 23767),  INT16_C(  9890) },
      {  INT16_C(  8225),  INT16_C(  2117),  INT16_C(  3142),  INT16_C(   160) } },
    { { -INT16_C( 32291),  INT16_C( 26482), -INT16_C( 12159),  INT16_C(  6256) },
      { -INT16_C(  9658),  INT16_C( 28064),  INT16_C( 20815),  INT16_C( 28901) },
      { -INT16_C( 32700),  INT16_C( 25888),  INT16_C( 20481),  INT16_C(  4192) } },
    { { -INT16_C( 13175), -INT16_C(  4261),  INT16_C(  5115),  INT16_C( 14703) },
      { -INT16_C( 17292),  INT16_C( 19282), -INT16_C(  3048), -INT16_C(  2703) },
      { -INT16_C( 29696),  INT16_C( 19282),  INT16_C(  4120),  INT16_C( 12641) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vand_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vand_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  2141526501), -INT32_C(  1272924119) },
      {  INT32_C(   780249120), -INT32_C(  1757745507) },
      {  INT32_C(       40960), -INT32_C(  1809799159) } },
    { { -INT32_C(  2127995682),  INT32_C(   770592686) },
      { -INT32_C(  1719305170), -INT32_C(   698477125) },
      { -INT32_C(  2130617330),  INT32_C(    72222122) } },
    { {  INT32_C(   626505980), -INT32_C(  1864796304) },
      { -INT32_C(  1111598304),  INT32_C(   659880265) },
      {  INT32_C(   622204960),  INT32_C(     5271872) } },
    { {  INT32_C(    78151253), -INT32_C(    63858739) },
      { -INT32_C(   829049325), -INT32_C(   928648244) },
      {  INT32_C(    75511313), -INT32_C(   937323572) } },
    { {  INT32_C(   485358764), -INT32_C(  1817328013) },
      {  INT32_C(  1800497953), -INT32_C(  1164794524) },
      {  INT32_C(   138504224), -INT32_C(  1837071264) } },
    { { -INT32_C(   239191261), -INT32_C(   437391406) },
      {  INT32_C(  1907589797),  INT32_C(   574183542) },
      {  INT32_C(  1907491361),  INT32_C(   539576402) } },
    { { -INT32_C(   935451052),  INT32_C(   240905197) },
      { -INT32_C(  1149653929),  INT32_C(  1970605138) },
      { -INT32_C(  2009586604),  INT32_C(    72419392) } },
    { {  INT32_C(   426128199), -INT32_C(   922856670) },
      {  INT32_C(  1278849494),  INT32_C(  1584296714) },
      {  INT32_C(   136327494),  INT32_C(  1215189762) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vand_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vand_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C(  807394475972528543) },
      {  INT64_C(  594141505336878048) },
      {  INT64_C(  591186017644478848) } },
    { { -INT64_C( 8372368850300909537) },
      { -INT64_C( 8736313779588373280) },
      { -INT64_C( 9024579357292576768) } },
    { {  INT64_C(  572871018235541225) },
      { -INT64_C( 3568996398074241053) },
      {  INT64_C(  463906115105756897) } },
    { { -INT64_C(  317422293695611863) },
      {  INT64_C( 2998068317509771310) },
      {  INT64_C( 2997218119849713704) } },
    { { -INT64_C( 3950776287104948483) },
      { -INT64_C( 2854522746623668508) },
      { -INT64_C( 4026217353836493084) } },
    { {  INT64_C( 6306583366756261486) },
      {  INT64_C( 5676233526956788316) },
      {  INT64_C( 5081195077962041932) } },
    { { -INT64_C( 4441217883490232146) },
      { -INT64_C( 5227350641175259155) },
      { -INT64_C( 9055445508946751316) } },
    { {  INT64_C( 3609290772723095958) },
      {  INT64_C( 4138689903570354896) },
      {  INT64_C( 3460599049529327760) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vand_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vand_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(133), UINT8_C( 80), UINT8_C( 15), UINT8_C( 44), UINT8_C( 61), UINT8_C(139), UINT8_C(144), UINT8_C( 96) },
      { UINT8_C(132), UINT8_C( 43), UINT8_C( 20), UINT8_C(  6), UINT8_C(133), UINT8_C( 67), UINT8_C( 89), UINT8_C(197) },
      { UINT8_C(132), UINT8_C(  0), UINT8_C(  4), UINT8_C(  4), UINT8_C(  5), UINT8_C(  3), UINT8_C( 16), UINT8_C( 64) } },
    { { UINT8_C(139), UINT8_C(204), UINT8_C(203), UINT8_C( 81), UINT8_C(207), UINT8_C(212), UINT8_C( 98), UINT8_C( 41) },
      { UINT8_C(237), UINT8_C(207), UINT8_C( 36), UINT8_C(127), UINT8_C(146), UINT8_C(155), UINT8_C(180), UINT8_C( 24) },
      { UINT8_C(137), UINT8_C(204), UINT8_C(  0), UINT8_C( 81), UINT8_C(130), UINT8_C(144), UINT8_C( 32), UINT8_C(  8) } },
    { { UINT8_C(236), UINT8_C(195), UINT8_C( 68), UINT8_C( 41), UINT8_C( 78), UINT8_C(213), UINT8_C(138), UINT8_C(211) },
      { UINT8_C(  0), UINT8_C(158), UINT8_C(217), UINT8_C(133), UINT8_C(225), UINT8_C( 51), UINT8_C( 74), UINT8_C(108) },
      { UINT8_C(  0), UINT8_C(130), UINT8_C( 64), UINT8_C(  1), UINT8_C( 64), UINT8_C( 17), UINT8_C( 10), UINT8_C( 64) } },
    { {    UINT8_MAX, UINT8_C( 21), UINT8_C(189), UINT8_C(206), UINT8_C(234), UINT8_C( 31), UINT8_C(247), UINT8_C(215) },
      { UINT8_C(239), UINT8_C( 28), UINT8_C( 86), UINT8_C(129), UINT8_C(183), UINT8_C( 10), UINT8_C(153), UINT8_C(163) },
      { UINT8_C(239), UINT8_C( 20), UINT8_C( 20), UINT8_C(128), UINT8_C(162), UINT8_C( 10), UINT8_C(145), UINT8_C(131) } },
    { { UINT8_C(205), UINT8_C(222), UINT8_C(205), UINT8_C( 27), UINT8_C(179), UINT8_C( 87), UINT8_C(238), UINT8_C(179) },
      { UINT8_C(245), UINT8_C(200), UINT8_C( 56), UINT8_C(214), UINT8_C(251), UINT8_C(130), UINT8_C( 66), UINT8_C(250) },
      { UINT8_C(197), UINT8_C(200), UINT8_C(  8), UINT8_C( 18), UINT8_C(179), UINT8_C(  2), UINT8_C( 66), UINT8_C(178) } },
    { { UINT8_C(152), UINT8_C(  0), UINT8_C(200), UINT8_C(130), UINT8_C( 31), UINT8_C(192), UINT8_C( 89), UINT8_C( 14) },
      { UINT8_C(220), UINT8_C(175), UINT8_C(144), UINT8_C(147), UINT8_C(185), UINT8_C( 41), UINT8_C( 55), UINT8_C(134) },
      { UINT8_C(152), UINT8_C(  0), UINT8_C(128), UINT8_C(130), UINT8_C( 25), UINT8_C(  0), UINT8_C( 17), UINT8_C(  6) } },
    { { UINT8_C(  7), UINT8_C(  4), UINT8_C(161), UINT8_C(186), UINT8_C( 91), UINT8_C(144), UINT8_C(109), UINT8_C( 80) },
      { UINT8_C( 88), UINT8_C(165), UINT8_C( 38), UINT8_C( 83), UINT8_C( 40), UINT8_C(104), UINT8_C( 77), UINT8_C(192) },
      { UINT8_C(  0), UINT8_C(  4), UINT8_C( 32), UINT8_C( 18), UINT8_C(  8), UINT8_C(  0), UINT8_C( 77), UINT8_C( 64) } },
    { { UINT8_C(104), UINT8_C( 21), UINT8_C( 66), UINT8_C(136), UINT8_C(213), UINT8_C(155), UINT8_C(150), UINT8_C(177) },
      { UINT8_C( 74), UINT8_C( 38), UINT8_C( 69), UINT8_C(  3), UINT8_C( 80), UINT8_C(124), UINT8_C(137), UINT8_C( 87) },
      { UINT8_C( 72), UINT8_C(  4), UINT8_C( 64), UINT8_C(  0), UINT8_C( 80), UINT8_C( 24), UINT8_C(128), UINT8_C( 17) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vand_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vand_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(50812), UINT16_C(16903), UINT16_C(62815), UINT16_C(20680) },
      { UINT16_C(26826), UINT16_C(61270), UINT16_C(43655), UINT16_C(46605) },
      { UINT16_C(16456), UINT16_C(16902), UINT16_C(40967), UINT16_C( 4104) } },
    { { UINT16_C(38137), UINT16_C( 8365), UINT16_C( 5439), UINT16_C(24413) },
      { UINT16_C(56762), UINT16_C(34220), UINT16_C(16109), UINT16_C(27019) },
      { UINT16_C(38072), UINT16_C(  172), UINT16_C( 5165), UINT16_C(18697) } },
    { { UINT16_C(37380), UINT16_C(25515), UINT16_C(29831), UINT16_C(20916) },
      { UINT16_C( 2780), UINT16_C(25408), UINT16_C(20148), UINT16_C(44569) },
      { UINT16_C(  516), UINT16_C(25344), UINT16_C(17540), UINT16_C(   16) } },
    { { UINT16_C(50914), UINT16_C( 8654), UINT16_C(11228), UINT16_C(38528) },
      { UINT16_C(11528), UINT16_C(62747), UINT16_C(42603), UINT16_C(28511) },
      { UINT16_C( 1024), UINT16_C( 8458), UINT16_C( 8776), UINT16_C( 1536) } },
    { { UINT16_C( 2616), UINT16_C(49107), UINT16_C(34686), UINT16_C(23057) },
      { UINT16_C(20881), UINT16_C(18110), UINT16_C(55199), UINT16_C(33268) },
      { UINT16_C(   16), UINT16_C( 1682), UINT16_C(34590), UINT16_C(   16) } },
    { { UINT16_C(49822), UINT16_C(31394), UINT16_C( 9197), UINT16_C(62736) },
      { UINT16_C(11088), UINT16_C(48106), UINT16_C(18898), UINT16_C( 2602) },
      { UINT16_C(  528), UINT16_C(15010), UINT16_C(  448), UINT16_C(    0) } },
    { { UINT16_C(64852), UINT16_C(53962), UINT16_C(56196), UINT16_C( 5677) },
      { UINT16_C(60204), UINT16_C(52316), UINT16_C(20674), UINT16_C(24653) },
      { UINT16_C(59652), UINT16_C(49224), UINT16_C(20608), UINT16_C(   13) } },
    { { UINT16_C(61458), UINT16_C(65498), UINT16_C(59923), UINT16_C(25588) },
      { UINT16_C(56854), UINT16_C(59422), UINT16_C(18472), UINT16_C(31986) },
      { UINT16_C(53266), UINT16_C(59418), UINT16_C(18432), UINT16_C(24816) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vand_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vand_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2917061730), UINT32_C(2148387771) },
      { UINT32_C(2754112333), UINT32_C( 761295916) },
      { UINT32_C(2752004160), UINT32_C(     16424) } },
    { { UINT32_C(1254698587), UINT32_C(1646806080) },
      { UINT32_C( 516581298), UINT32_C( 271576749) },
      { UINT32_C( 180889106), UINT32_C(   2638848) } },
    { { UINT32_C(2109541826), UINT32_C( 654232281) },
      { UINT32_C(1657415222), UINT32_C(4136577691) },
      { UINT32_C(1619526658), UINT32_C( 646843033) } },
    { { UINT32_C(2571130969), UINT32_C(1341876637) },
      { UINT32_C(2104411600), UINT32_C(1972215219) },
      { UINT32_C( 423641168), UINT32_C(1166608785) } },
    { { UINT32_C(2230536875), UINT32_C(1269494037) },
      { UINT32_C(2997712151), UINT32_C(4171840671) },
      { UINT32_C(2158051331), UINT32_C(1218981909) } },
    { { UINT32_C( 831646100), UINT32_C( 578915410) },
      { UINT32_C(  77655889), UINT32_C( 930753932) },
      { UINT32_C(   8448272), UINT32_C( 570428416) } },
    { { UINT32_C(2377870712), UINT32_C(1977116254) },
      { UINT32_C(2049476059), UINT32_C(1433653697) },
      { UINT32_C( 136840536), UINT32_C(1431322688) } },
    { { UINT32_C( 226952378), UINT32_C(3794733201) },
      { UINT32_C(2213007351), UINT32_C(1975214589) },
      { UINT32_C(  25625778), UINT32_C(1613430929) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vand_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vand_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 8703332882612638225) },
      { UINT64_C( 2245985253790906599) },
      { UINT64_C( 1731725454804013057) } },
    { { UINT64_C( 3669248827220894596) },
      { UINT64_C(16650248547897175472) },
      { UINT64_C( 2450380779709342080) } },
    { { UINT64_C( 9619316748342078434) },
      { UINT64_C( 5941927748976735909) },
      { UINT64_C(   32833126715695776) } },
    { { UINT64_C(17630300909072185882) },
      { UINT64_C( 8940891669190675030) },
      { UINT64_C( 8358796357797677586) } },
    { { UINT64_C( 5601634229709634201) },
      { UINT64_C(11067341544177764470) },
      { UINT64_C(  690458285450627088) } },
    { { UINT64_C(15405333827829241234) },
      { UINT64_C( 3304822528098313927) },
      { UINT64_C(  416605042737546370) } },
    { { UINT64_C(15349711599961399056) },
      { UINT64_C( 5963805770450118826) },
      { UINT64_C( 5764925557443659776) } },
    { { UINT64_C( 6420429453816026566) },
      { UINT64_C( 4817328995344980761) },
      { UINT64_C( 4618602023945244928) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vand_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vandq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  30),  INT8_C(   5), -INT8_C(  37), -INT8_C(  20), -INT8_C(  83),  INT8_C(  25), -INT8_C(  80),  INT8_C(  43),
        -INT8_C(  60),  INT8_C(  67),  INT8_C(  86), -INT8_C(  68), -INT8_C(  54), -INT8_C(  75), -INT8_C( 102), -INT8_C(  53) },
      { -INT8_C(  21),  INT8_C(  69),  INT8_C(  71),  INT8_C( 118),  INT8_C(  38), -INT8_C(  95), -INT8_C(  19), -INT8_C(  73),
        -INT8_C(  66),  INT8_C(  41),  INT8_C(  44),  INT8_C(  65), -INT8_C(  73),  INT8_C(  82), -INT8_C(  18), -INT8_C( 103) },
      { -INT8_C(  30),  INT8_C(   5),  INT8_C(  67),  INT8_C( 100),  INT8_C(  36),  INT8_C(   1), -INT8_C(  96),  INT8_C(  35),
        -INT8_C( 124),  INT8_C(   1),  INT8_C(   4),  INT8_C(   0), -INT8_C( 126),  INT8_C(  16), -INT8_C( 118), -INT8_C( 119) } },
    { {  INT8_C(  87), -INT8_C(  54), -INT8_C( 122),  INT8_C(   4), -INT8_C(  29),  INT8_C(  54),  INT8_C(  48), -INT8_C(  89),
         INT8_C( 121), -INT8_C( 122),  INT8_C(  99),  INT8_C(  67),  INT8_C(  60), -INT8_C(   3),  INT8_C(  15),  INT8_C(  39) },
      {  INT8_C(  66),  INT8_C(  86), -INT8_C(  99),  INT8_C( 105), -INT8_C(   9), -INT8_C( 117),  INT8_C(  32), -INT8_C(  75),
        -INT8_C(  76),  INT8_C(  76), -INT8_C(  10),  INT8_C( 107), -INT8_C(  98), -INT8_C(  27),  INT8_C(   5), -INT8_C(  10) },
      {  INT8_C(  66),  INT8_C(  66), -INT8_C( 124),  INT8_C(   0), -INT8_C(  29),  INT8_C(   2),  INT8_C(  32), -INT8_C(  91),
         INT8_C(  48),  INT8_C(   4),  INT8_C(  98),  INT8_C(  67),  INT8_C(  28), -INT8_C(  27),  INT8_C(   5),  INT8_C(  38) } },
    { { -INT8_C(  81), -INT8_C( 117), -INT8_C(   6), -INT8_C( 110), -INT8_C(  63),  INT8_C(  42),  INT8_C(  57),  INT8_C(  58),
        -INT8_C(  79), -INT8_C(  99),  INT8_C( 126), -INT8_C(  19), -INT8_C( 102), -INT8_C( 115),  INT8_C(  20), -INT8_C(  35) },
      { -INT8_C(  29), -INT8_C(  78),  INT8_C(  70), -INT8_C(  38),  INT8_C(  61),  INT8_C( 102), -INT8_C( 113), -INT8_C(  15),
        -INT8_C(  78), -INT8_C( 122),  INT8_C(  93),  INT8_C(  80),  INT8_C( 107),  INT8_C(  98),  INT8_C(  70),  INT8_C(  26) },
      { -INT8_C(  93), -INT8_C( 126),  INT8_C(  66), -INT8_C( 110),  INT8_C(   1),  INT8_C(  34),  INT8_C(   9),  INT8_C(  48),
        -INT8_C(  80), -INT8_C( 124),  INT8_C(  92),  INT8_C(  64),  INT8_C(  10),  INT8_C(   0),  INT8_C(   4),  INT8_C(  24) } },
    { { -INT8_C(  19),  INT8_C(  65), -INT8_C(  84), -INT8_C(  82),  INT8_C( 107), -INT8_C(  27), -INT8_C(  24),  INT8_C(  28),
        -INT8_C( 126),  INT8_C( 102),  INT8_C(   9),  INT8_C(  29), -INT8_C(  13),  INT8_C(  30), -INT8_C(   6), -INT8_C(  42) },
      { -INT8_C(  48),  INT8_C(  64), -INT8_C(  80),  INT8_C(  13), -INT8_C(  90),  INT8_C(  64), -INT8_C(   2),  INT8_C(  88),
        -INT8_C(  58),  INT8_C(  91), -INT8_C(  88),  INT8_C(  49), -INT8_C(  67), -INT8_C(  17),  INT8_C(  75), -INT8_C(  86) },
      { -INT8_C(  64),  INT8_C(  64), -INT8_C(  96),  INT8_C(  12),  INT8_C(  34),  INT8_C(  64), -INT8_C(  24),  INT8_C(  24),
        -INT8_C( 126),  INT8_C(  66),  INT8_C(   8),  INT8_C(  17), -INT8_C(  79),  INT8_C(  14),  INT8_C(  74), -INT8_C( 126) } },
    { {  INT8_C(  48), -INT8_C(   9),  INT8_C(  88), -INT8_C( 101), -INT8_C(  36),  INT8_C(  65), -INT8_C(  72),  INT8_C(  95),
        -INT8_C(  89), -INT8_C(  63),  INT8_C( 124), -INT8_C( 101), -INT8_C(  33),  INT8_C( 118),  INT8_C( 113), -INT8_C(  81) },
      { -INT8_C(  74),  INT8_C(  34), -INT8_C(  68),  INT8_C(  92),  INT8_C(  98), -INT8_C(  69), -INT8_C(  76),  INT8_C(  40),
         INT8_C(  22),  INT8_C(  92),  INT8_C(  89), -INT8_C(  44),  INT8_C(  75), -INT8_C(  92),  INT8_C( 126),  INT8_C( 123) },
      {  INT8_C(  48),  INT8_C(  34),  INT8_C(  24),  INT8_C(  24),  INT8_C(  64),  INT8_C(   1), -INT8_C(  80),  INT8_C(   8),
         INT8_C(   6),  INT8_C(  64),  INT8_C(  88), -INT8_C( 112),  INT8_C(  75),  INT8_C(  36),  INT8_C( 112),  INT8_C(  43) } },
    { { -INT8_C( 101), -INT8_C(  41),  INT8_C(  23),  INT8_C( 119),  INT8_C(  24), -INT8_C(  49), -INT8_C(  42), -INT8_C(  65),
        -INT8_C( 112),  INT8_C(  82),  INT8_C(  90),  INT8_C( 112), -INT8_C(  56), -INT8_C(  52),  INT8_C(  31),  INT8_C( 126) },
      { -INT8_C(  18), -INT8_C(  36), -INT8_C(  38),  INT8_C(  80), -INT8_C( 105), -INT8_C( 114),  INT8_C( 120), -INT8_C(  83),
        -INT8_C(  21), -INT8_C(  47), -INT8_C( 127),  INT8_C(  54),  INT8_C( 117),  INT8_C(   0), -INT8_C(  78),  INT8_C(  16) },
      { -INT8_C( 118), -INT8_C(  44),  INT8_C(  18),  INT8_C(  80),  INT8_C(  16), -INT8_C( 114),  INT8_C(  80), -INT8_C(  83),
             INT8_MIN,  INT8_C(  80),  INT8_C(   0),  INT8_C(  48),  INT8_C(  64),  INT8_C(   0),  INT8_C(  18),  INT8_C(  16) } },
    { { -INT8_C(  41), -INT8_C(  55), -INT8_C( 121), -INT8_C(  17), -INT8_C( 104),  INT8_C(  94), -INT8_C(  82),  INT8_C(  40),
        -INT8_C(  80),  INT8_C(   9), -INT8_C( 104),  INT8_C( 121), -INT8_C(  43), -INT8_C(  72), -INT8_C(   9), -INT8_C(  61) },
      { -INT8_C( 108), -INT8_C(  46),  INT8_C(  19),  INT8_C(  43),  INT8_C(  96), -INT8_C( 117), -INT8_C(  40),  INT8_C(  75),
         INT8_C(  92),  INT8_C(  90), -INT8_C( 126), -INT8_C(  47),  INT8_C(  90),  INT8_C(  52), -INT8_C(  31),  INT8_C(  49) },
      { -INT8_C( 108), -INT8_C(  64),  INT8_C(   3),  INT8_C(  43),  INT8_C(   0),  INT8_C(  10), -INT8_C( 120),  INT8_C(   8),
         INT8_C(  16),  INT8_C(   8),      INT8_MIN,  INT8_C(  81),  INT8_C(  80),  INT8_C(  48), -INT8_C(  31),  INT8_C(   1) } },
    { { -INT8_C(   3),  INT8_C( 104),  INT8_C(  32), -INT8_C( 107), -INT8_C(  58), -INT8_C(  50), -INT8_C(  67),  INT8_C( 119),
        -INT8_C(  41),  INT8_C(  86), -INT8_C(  16), -INT8_C(  84),  INT8_C(  14), -INT8_C(  25),  INT8_C( 111), -INT8_C(  94) },
      { -INT8_C(  71), -INT8_C( 126), -INT8_C(  51),  INT8_C(  26),  INT8_C(  13), -INT8_C(  91),  INT8_C( 101),  INT8_C( 105),
        -INT8_C(   1), -INT8_C(  25),  INT8_C(  58),  INT8_C(  89),  INT8_C(  27),  INT8_C(  27), -INT8_C( 118),  INT8_C(  24) },
      { -INT8_C(  71),  INT8_C(   0),  INT8_C(   0),  INT8_C(  16),  INT8_C(   4), -INT8_C( 124),  INT8_C(  37),  INT8_C(  97),
        -INT8_C(  41),  INT8_C(  70),  INT8_C(  48),  INT8_C(   8),  INT8_C(  10),  INT8_C(   3),  INT8_C(  10),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vandq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vandq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 26169), -INT16_C(  7830),  INT16_C(  2962), -INT16_C(  1871),  INT16_C(  6073),  INT16_C( 16182), -INT16_C(  5833),  INT16_C( 22880) },
      { -INT16_C( 13541),  INT16_C( 27717),  INT16_C( 26998),  INT16_C( 17851), -INT16_C( 12177), -INT16_C( 18011), -INT16_C(  6035),  INT16_C( 13323) },
      { -INT16_C( 30461),  INT16_C( 24640),  INT16_C(  2322),  INT16_C( 16561),  INT16_C(  4137),  INT16_C( 14628), -INT16_C(  6107),  INT16_C(  4096) } },
    { {  INT16_C( 30081),  INT16_C(  4886), -INT16_C( 14463),  INT16_C( 14859),  INT16_C( 17118),  INT16_C(  5498), -INT16_C(  9685),  INT16_C( 18031) },
      { -INT16_C( 19291),  INT16_C(  7090),  INT16_C( 28190), -INT16_C( 29343),  INT16_C(  1598), -INT16_C( 21690),  INT16_C( 21231),  INT16_C( 28896) },
      {  INT16_C( 13441),  INT16_C(  4882),  INT16_C( 17920),  INT16_C(  2049),  INT16_C(   542),  INT16_C(   322),  INT16_C( 21035),  INT16_C( 16480) } },
    { { -INT16_C(  2361),  INT16_C( 18564), -INT16_C( 28739), -INT16_C( 25469), -INT16_C(   559), -INT16_C(   847),  INT16_C(  8407),  INT16_C( 32067) },
      { -INT16_C(  2603), -INT16_C(  3176), -INT16_C(  1693), -INT16_C( 23936), -INT16_C( 14848), -INT16_C(  4275),  INT16_C( 11544), -INT16_C(  8097) },
      { -INT16_C(  2875),  INT16_C( 16512), -INT16_C( 30431), -INT16_C( 32640), -INT16_C( 15360), -INT16_C(  5119),  INT16_C(  8208),  INT16_C( 24643) } },
    { { -INT16_C(  7389), -INT16_C(  7896), -INT16_C( 21645),  INT16_C( 17533),  INT16_C( 11944), -INT16_C( 32703), -INT16_C( 31665),  INT16_C(  9469) },
      { -INT16_C( 27271), -INT16_C(  8937), -INT16_C( 26737), -INT16_C( 28801), -INT16_C( 13219),  INT16_C( 30334), -INT16_C(  8710),  INT16_C(  7510) },
      { -INT16_C( 32479), -INT16_C( 16128), -INT16_C( 31997),  INT16_C(  1149),  INT16_C(  3080),  INT16_C(    64), -INT16_C( 31670),  INT16_C(  1108) } },
    { {  INT16_C( 32449),  INT16_C( 13566),  INT16_C( 31530), -INT16_C( 11656), -INT16_C( 18006), -INT16_C(  1710),  INT16_C( 20285), -INT16_C( 18659) },
      {  INT16_C( 13541),  INT16_C( 29844),  INT16_C(  5067),  INT16_C( 10243), -INT16_C( 32289), -INT16_C(  9826), -INT16_C(  2978),  INT16_C(  8183) },
      {  INT16_C( 13505),  INT16_C( 13460),  INT16_C(  4874),  INT16_C(     0), -INT16_C( 32374), -INT16_C(  9966),  INT16_C( 17436),  INT16_C(  5909) } },
    { { -INT16_C(  2701), -INT16_C( 25261), -INT16_C( 13199),  INT16_C(  7023), -INT16_C( 15739), -INT16_C( 15596),  INT16_C( 12561), -INT16_C(  2438) },
      {  INT16_C(  3685),  INT16_C( 12394),  INT16_C( 27937),  INT16_C(    88), -INT16_C(  2066),  INT16_C( 19930), -INT16_C( 11797),  INT16_C( 24172) },
      {  INT16_C(  1121),  INT16_C(  4162),  INT16_C( 19489),  INT16_C(    72), -INT16_C( 15740),  INT16_C( 16656),  INT16_C(  4353),  INT16_C( 22120) } },
    { { -INT16_C( 16186),  INT16_C( 14331),  INT16_C( 27532),  INT16_C(  4434),  INT16_C( 26157),  INT16_C( 16084),  INT16_C( 20119), -INT16_C(   971) },
      { -INT16_C( 24740),  INT16_C( 32044), -INT16_C( 31475), -INT16_C(  1154),  INT16_C( 22652),  INT16_C( 26440), -INT16_C( 19159), -INT16_C(  4154) },
      { -INT16_C( 32700),  INT16_C( 13608),  INT16_C(   268),  INT16_C(  4434),  INT16_C( 16428),  INT16_C(  9792),  INT16_C(  1025), -INT16_C(  5116) } },
    { { -INT16_C( 16011),  INT16_C(   295),  INT16_C( 31020),  INT16_C( 22802), -INT16_C(  6176),  INT16_C( 30616), -INT16_C( 13003), -INT16_C( 28044) },
      { -INT16_C( 24468),  INT16_C( 30991), -INT16_C( 29403), -INT16_C( 24203), -INT16_C( 16923),  INT16_C(  3593), -INT16_C( 12430), -INT16_C(  6146) },
      { -INT16_C( 32668),  INT16_C(   263),  INT16_C(  2340),  INT16_C(   272), -INT16_C( 23072),  INT16_C(  1544), -INT16_C( 13008), -INT16_C( 32140) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vandq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vandq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1875313777),  INT32_C(    55691321),  INT32_C(  2069893365),  INT32_C(  1333800119) },
      {  INT32_C(  1559786409),  INT32_C(   423268261),  INT32_C(    17750977),  INT32_C(  1330314944) },
      {  INT32_C(   272135049),  INT32_C(    17860641),  INT32_C(    16781505),  INT32_C(  1325411456) } },
    { {  INT32_C(   870286073),  INT32_C(  1077293130), -INT32_C(   138701248),  INT32_C(  1816542147) },
      {  INT32_C(  1422475182), -INT32_C(  1871903794), -INT32_C(  1617855521),  INT32_C(  1928256633) },
      {  INT32_C(   281608872),  INT32_C(     2359370), -INT32_C(  1752100288),  INT32_C(  1615206465) } },
    { { -INT32_C(  1448751778),  INT32_C(  1038736637),  INT32_C(   892642418), -INT32_C(  1901954081) },
      { -INT32_C(  1998427206),  INT32_C(  1293438830),  INT32_C(  1139583690), -INT32_C(   457844090) },
      { -INT32_C(  2002761446),  INT32_C(   218647660),  INT32_C(    19177538), -INT32_C(  2069865850) } },
    { { -INT32_C(  1534239833), -INT32_C(  1444841929), -INT32_C(    86043110),  INT32_C(  1267237265) },
      {  INT32_C(  1523804908), -INT32_C(  2086081351),  INT32_C(   482776214),  INT32_C(   369130351) },
      {  INT32_C(     8473252), -INT32_C(  2120195023),  INT32_C(   415634450),  INT32_C(    33554689) } },
    { {  INT32_C(   230395606),  INT32_C(   532126724),  INT32_C(  1125750450),  INT32_C(    59678999) },
      { -INT32_C(  1000513013), -INT32_C(   465107634),  INT32_C(   150998426),  INT32_C(  1595867272) },
      {  INT32_C(    68747778),  INT32_C(    67568644),  INT32_C(    16778386),  INT32_C(    51249152) } },
    { { -INT32_C(  1821582706),  INT32_C(   699540343), -INT32_C(   798110791),  INT32_C(  2010381164) },
      { -INT32_C(  1422184099), -INT32_C(   795901386),  INT32_C(   400134031),  INT32_C(   511113616) },
      { -INT32_C(  2094526452),  INT32_C(     8520246),  INT32_C(   273255305),  INT32_C(   374536448) } },
    { {  INT32_C(  1253172179), -INT32_C(  1066114298), -INT32_C(  1701781202),  INT32_C(   974218460) },
      { -INT32_C(   874165099),  INT32_C(  1570534862), -INT32_C(  1804241660),  INT32_C(  1119087470) },
      {  INT32_C(  1252081809),  INT32_C(  1075077382), -INT32_C(  1877974780),  INT32_C(    34693196) } },
    { { -INT32_C(   712219442), -INT32_C(   158007096), -INT32_C(  1097783839),  INT32_C(   519611017) },
      { -INT32_C(  1108681233),  INT32_C(  1461421650),  INT32_C(  1793822971),  INT32_C(  1252826747) },
      { -INT32_C(  1786231602),  INT32_C(  1443954752),  INT32_C(   713097441),  INT32_C(   178815497) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vandq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vandq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 4303703866289850050), -INT64_C( 2671035006846493008) },
      {  INT64_C( 2708714866595918025),  INT64_C(  718144693475718264) },
      {  INT64_C(  289928024609026056),  INT64_C(  641218414341264432) } },
    { {  INT64_C( 2646998879941183701),  INT64_C( 7047910868629455909) },
      { -INT64_C( 3090360644743064795),  INT64_C( 4638148425744650121) },
      {  INT64_C(  296117537962196997),  INT64_C( 4633642180416898049) } },
    { {  INT64_C( 5396988171449278028), -INT64_C( 8795513164860019720) },
      { -INT64_C( 8190754677193953502), -INT64_C( 5741174301392740185) },
      {  INT64_C(  739874586727288320), -INT64_C( 9200853626348494688) } },
    { {  INT64_C( 8633213016863705951),  INT64_C( 4640949648730033793) },
      {  INT64_C( 2502053587228549926),  INT64_C( 4289830226683599732) },
      {  INT64_C( 2488542787615621894),  INT64_C(     141960480623104) } },
    { { -INT64_C( 3527569414960449260),  INT64_C( 3529159692359111325) },
      {  INT64_C( 4798608279944805115),  INT64_C( 7766355678831824560) },
      {  INT64_C( 4758057739708250128),  INT64_C( 2360449165568311952) } },
    { { -INT64_C( 5568125800508586340),  INT64_C( 9104140459729251101) },
      {  INT64_C( 8660859452568941345), -INT64_C( 8350293899435815845) },
      {  INT64_C( 3472285212265972224),  INT64_C(  871520745501771801) } },
    { {  INT64_C( 4978784537157246289),  INT64_C(  981720861753836957) },
      {  INT64_C( 8986982677265290360), -INT64_C( 2740920278234252166) },
      {  INT64_C( 4906707116912546896),  INT64_C(  690811628579226648) } },
    { {  INT64_C( 4455846327967772264), -INT64_C( 9162857078147103779) },
      {  INT64_C( 8732332341634126482),  INT64_C( 1267440763426528566) },
      {  INT64_C( 4109069156656169472),  INT64_C(   42460976704012564) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vandq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vandq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(149), UINT8_C(208), UINT8_C(159), UINT8_C( 24), UINT8_C(108), UINT8_C(171), UINT8_C( 77), UINT8_C(141),
        UINT8_C(144), UINT8_C( 49), UINT8_C(185), UINT8_C(125), UINT8_C( 75), UINT8_C(155), UINT8_C( 87), UINT8_C( 62) },
      { UINT8_C(235), UINT8_C(237), UINT8_C( 83), UINT8_C(165), UINT8_C( 95), UINT8_C( 71), UINT8_C(165), UINT8_C(241),
        UINT8_C(229), UINT8_C( 46), UINT8_C(171), UINT8_C(216), UINT8_C( 35), UINT8_C( 53), UINT8_C(145), UINT8_C(185) },
      { UINT8_C(129), UINT8_C(192), UINT8_C( 19), UINT8_C(  0), UINT8_C( 76), UINT8_C(  3), UINT8_C(  5), UINT8_C(129),
        UINT8_C(128), UINT8_C( 32), UINT8_C(169), UINT8_C( 88), UINT8_C(  3), UINT8_C( 17), UINT8_C( 17), UINT8_C( 56) } },
    { { UINT8_C(  5), UINT8_C( 48), UINT8_C(209), UINT8_C(114), UINT8_C(219), UINT8_C( 31),    UINT8_MAX, UINT8_C(107),
        UINT8_C( 80), UINT8_C(184), UINT8_C(232), UINT8_C(156), UINT8_C( 83), UINT8_C( 63), UINT8_C(218), UINT8_C( 63) },
      { UINT8_C( 45), UINT8_C( 45), UINT8_C(228), UINT8_C(140), UINT8_C(116), UINT8_C(138), UINT8_C(125), UINT8_C( 89),
        UINT8_C(184), UINT8_C( 41), UINT8_C( 49), UINT8_C(219), UINT8_C( 94), UINT8_C(194), UINT8_C(148), UINT8_C( 99) },
      { UINT8_C(  5), UINT8_C( 32), UINT8_C(192), UINT8_C(  0), UINT8_C( 80), UINT8_C( 10), UINT8_C(125), UINT8_C( 73),
        UINT8_C( 16), UINT8_C( 40), UINT8_C( 32), UINT8_C(152), UINT8_C( 82), UINT8_C(  2), UINT8_C(144), UINT8_C( 35) } },
    { { UINT8_C(242), UINT8_C(102), UINT8_C(213), UINT8_C(205), UINT8_C(133), UINT8_C(213), UINT8_C( 56), UINT8_C(213),
        UINT8_C(141), UINT8_C( 32), UINT8_C(113), UINT8_C(225), UINT8_C( 95), UINT8_C( 75), UINT8_C( 32), UINT8_C(140) },
      { UINT8_C(120), UINT8_C(  4), UINT8_C( 24), UINT8_C(236), UINT8_C(142), UINT8_C(150), UINT8_C( 69), UINT8_C( 70),
        UINT8_C(191), UINT8_C(118), UINT8_C( 34), UINT8_C( 29), UINT8_C( 56), UINT8_C(182), UINT8_C(128), UINT8_C( 42) },
      { UINT8_C(112), UINT8_C(  4), UINT8_C( 16), UINT8_C(204), UINT8_C(132), UINT8_C(148), UINT8_C(  0), UINT8_C( 68),
        UINT8_C(141), UINT8_C( 32), UINT8_C( 32), UINT8_C(  1), UINT8_C( 24), UINT8_C(  2), UINT8_C(  0), UINT8_C(  8) } },
    { { UINT8_C( 28), UINT8_C( 86), UINT8_C(247), UINT8_C(161), UINT8_C( 43), UINT8_C( 47), UINT8_C(119), UINT8_C(184),
        UINT8_C( 79), UINT8_C(232), UINT8_C(153), UINT8_C(175), UINT8_C( 52), UINT8_C(185), UINT8_C( 59), UINT8_C(172) },
      { UINT8_C(190), UINT8_C( 84), UINT8_C(153), UINT8_C( 76), UINT8_C(234), UINT8_C(222), UINT8_C(147), UINT8_C(169),
        UINT8_C( 85), UINT8_C(181), UINT8_C(198), UINT8_C(141), UINT8_C(107), UINT8_C( 70), UINT8_C(184), UINT8_C(136) },
      { UINT8_C( 28), UINT8_C( 84), UINT8_C(145), UINT8_C(  0), UINT8_C( 42), UINT8_C( 14), UINT8_C( 19), UINT8_C(168),
        UINT8_C( 69), UINT8_C(160), UINT8_C(128), UINT8_C(141), UINT8_C( 32), UINT8_C(  0), UINT8_C( 56), UINT8_C(136) } },
    { { UINT8_C(156), UINT8_C(175), UINT8_C( 41), UINT8_C(199), UINT8_C(223), UINT8_C(160), UINT8_C(128), UINT8_C( 46),
        UINT8_C(137), UINT8_C( 25), UINT8_C(221), UINT8_C(189), UINT8_C(211), UINT8_C( 25), UINT8_C(105), UINT8_C(145) },
      { UINT8_C(109), UINT8_C(  2), UINT8_C(221), UINT8_C( 87), UINT8_C(225), UINT8_C(112), UINT8_C(  0), UINT8_C( 54),
        UINT8_C( 37), UINT8_C(198), UINT8_C(195), UINT8_C(145), UINT8_C( 12), UINT8_C(123), UINT8_C( 25), UINT8_C(169) },
      { UINT8_C( 12), UINT8_C(  2), UINT8_C(  9), UINT8_C( 71), UINT8_C(193), UINT8_C( 32), UINT8_C(  0), UINT8_C( 38),
        UINT8_C(  1), UINT8_C(  0), UINT8_C(193), UINT8_C(145), UINT8_C(  0), UINT8_C( 25), UINT8_C(  9), UINT8_C(129) } },
    { { UINT8_C( 43), UINT8_C( 66), UINT8_C(112), UINT8_C( 10), UINT8_C(227), UINT8_C(240), UINT8_C( 56), UINT8_C(108),
        UINT8_C( 10), UINT8_C( 22), UINT8_C( 41), UINT8_C(221), UINT8_C( 47), UINT8_C(146), UINT8_C(110), UINT8_C(156) },
      { UINT8_C(149), UINT8_C( 75), UINT8_C(243), UINT8_C(118), UINT8_C(188), UINT8_C(243), UINT8_C(172), UINT8_C(225),
        UINT8_C(185), UINT8_C(111), UINT8_C(114), UINT8_C(197), UINT8_C(235), UINT8_C(139), UINT8_C(110), UINT8_C( 22) },
      { UINT8_C(  1), UINT8_C( 66), UINT8_C(112), UINT8_C(  2), UINT8_C(160), UINT8_C(240), UINT8_C( 40), UINT8_C( 96),
        UINT8_C(  8), UINT8_C(  6), UINT8_C( 32), UINT8_C(197), UINT8_C( 43), UINT8_C(130), UINT8_C(110), UINT8_C( 20) } },
    { { UINT8_C(206), UINT8_C(223), UINT8_C( 32), UINT8_C(177), UINT8_C(207), UINT8_C( 88), UINT8_C( 29), UINT8_C(217),
        UINT8_C(110), UINT8_C( 70), UINT8_C(182), UINT8_C(157), UINT8_C(216), UINT8_C( 36), UINT8_C( 57), UINT8_C(109) },
      { UINT8_C(112), UINT8_C( 44), UINT8_C(227), UINT8_C( 44), UINT8_C( 31), UINT8_C(143), UINT8_C( 13), UINT8_C(216),
           UINT8_MAX, UINT8_C(128), UINT8_C(158), UINT8_C(234), UINT8_C( 11), UINT8_C( 12), UINT8_C(  0), UINT8_C(217) },
      { UINT8_C( 64), UINT8_C( 12), UINT8_C( 32), UINT8_C( 32), UINT8_C( 15), UINT8_C(  8), UINT8_C( 13), UINT8_C(216),
        UINT8_C(110), UINT8_C(  0), UINT8_C(150), UINT8_C(136), UINT8_C(  8), UINT8_C(  4), UINT8_C(  0), UINT8_C( 73) } },
    { { UINT8_C(235), UINT8_C( 32), UINT8_C(138), UINT8_C(187), UINT8_C(120), UINT8_C(167), UINT8_C(148), UINT8_C(231),
        UINT8_C(237), UINT8_C( 75), UINT8_C(132), UINT8_C(198), UINT8_C(111), UINT8_C(190), UINT8_C( 51), UINT8_C(223) },
      { UINT8_C(234), UINT8_C( 23), UINT8_C( 11), UINT8_C( 10), UINT8_C(166), UINT8_C( 25), UINT8_C(226), UINT8_C(165),
        UINT8_C(153), UINT8_C(128), UINT8_C(143), UINT8_C(164), UINT8_C(141), UINT8_C(143), UINT8_C(126), UINT8_C(120) },
      { UINT8_C(234), UINT8_C(  0), UINT8_C( 10), UINT8_C( 10), UINT8_C( 32), UINT8_C(  1), UINT8_C(128), UINT8_C(165),
        UINT8_C(137), UINT8_C(  0), UINT8_C(132), UINT8_C(132), UINT8_C( 13), UINT8_C(142), UINT8_C( 50), UINT8_C( 88) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vandq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vandq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(14144), UINT16_C(21032), UINT16_C(65343), UINT16_C(36385), UINT16_C(62489), UINT16_C(21831), UINT16_C(29758), UINT16_C(19117) },
      { UINT16_C( 7953), UINT16_C(17828), UINT16_C(15693), UINT16_C(42403), UINT16_C(51393), UINT16_C(33131), UINT16_C(22501), UINT16_C( 9567) },
      { UINT16_C( 5888), UINT16_C(16416), UINT16_C(15629), UINT16_C(33825), UINT16_C(49153), UINT16_C(  323), UINT16_C(21540), UINT16_C(   13) } },
    { { UINT16_C(34703), UINT16_C(52855), UINT16_C(39047), UINT16_C(41053), UINT16_C(42125), UINT16_C(52214), UINT16_C(41753), UINT16_C(10773) },
      { UINT16_C(47554), UINT16_C( 3952), UINT16_C( 5111), UINT16_C(47284), UINT16_C( 8412), UINT16_C(49465), UINT16_C(39287), UINT16_C( 1766) },
      { UINT16_C(33154), UINT16_C( 3696), UINT16_C( 4231), UINT16_C(40980), UINT16_C( 8332), UINT16_C(49456), UINT16_C(33041), UINT16_C(  516) } },
    { { UINT16_C(24096), UINT16_C(42965), UINT16_C(13046), UINT16_C(33608), UINT16_C(16086), UINT16_C(61262), UINT16_C(25825), UINT16_C(41754) },
      { UINT16_C(35357), UINT16_C( 5298), UINT16_C(26269), UINT16_C(31180), UINT16_C( 1670), UINT16_C(65082), UINT16_C( 8607), UINT16_C(48900) },
      { UINT16_C( 2560), UINT16_C( 1168), UINT16_C( 8852), UINT16_C(  328), UINT16_C( 1670), UINT16_C(60938), UINT16_C( 8321), UINT16_C(41728) } },
    { { UINT16_C(55679), UINT16_C(30055), UINT16_C(44811), UINT16_C(58105), UINT16_C(18413), UINT16_C(52945), UINT16_C(60331), UINT16_C(51569) },
      { UINT16_C( 9077), UINT16_C( 5085), UINT16_C(43657), UINT16_C( 4236), UINT16_C(51120), UINT16_C(20238), UINT16_C( 4840), UINT16_C(26382) },
      { UINT16_C(  373), UINT16_C( 4421), UINT16_C(43529), UINT16_C(  136), UINT16_C(18336), UINT16_C(19968), UINT16_C(  680), UINT16_C(16640) } },
    { { UINT16_C(30188), UINT16_C(63452), UINT16_C(54564), UINT16_C( 4569), UINT16_C(43805), UINT16_C(51423), UINT16_C(20630), UINT16_C( 3217) },
      { UINT16_C(28531), UINT16_C(64799), UINT16_C(43801), UINT16_C(51469), UINT16_C( 7026), UINT16_C(23064), UINT16_C( 9773), UINT16_C( 6593) },
      { UINT16_C(25952), UINT16_C(62748), UINT16_C(33024), UINT16_C(  265), UINT16_C( 2832), UINT16_C(18456), UINT16_C(    4), UINT16_C( 2177) } },
    { { UINT16_C(40604), UINT16_C(49169), UINT16_C(60019), UINT16_C(37074), UINT16_C(45461), UINT16_C(11353), UINT16_C(59906), UINT16_C(30008) },
      { UINT16_C(22361), UINT16_C(29298), UINT16_C(32514), UINT16_C(30011), UINT16_C(21402), UINT16_C(51407), UINT16_C(37242), UINT16_C( 5857) },
      { UINT16_C( 5656), UINT16_C(16400), UINT16_C(27138), UINT16_C( 4114), UINT16_C( 4496), UINT16_C( 2121), UINT16_C(32770), UINT16_C( 5152) } },
    { { UINT16_C(61999), UINT16_C(41686), UINT16_C(43229), UINT16_C(29235), UINT16_C(35930), UINT16_C(23710), UINT16_C(54902), UINT16_C(53457) },
      { UINT16_C(17453), UINT16_C(12354), UINT16_C(32451), UINT16_C(24229), UINT16_C(29905), UINT16_C(19238), UINT16_C( 1797), UINT16_C(13409) },
      { UINT16_C(16429), UINT16_C( 8258), UINT16_C(10433), UINT16_C(21025), UINT16_C( 1104), UINT16_C(18438), UINT16_C( 1540), UINT16_C( 4161) } },
    { { UINT16_C(14586), UINT16_C(55255), UINT16_C( 2784), UINT16_C(14921), UINT16_C(59542), UINT16_C( 3222), UINT16_C(26814), UINT16_C(60636) },
      { UINT16_C( 8108), UINT16_C(28444), UINT16_C(49565), UINT16_C(28365), UINT16_C(62261), UINT16_C(15290), UINT16_C( 7163), UINT16_C(62831) },
      { UINT16_C( 6312), UINT16_C(18196), UINT16_C(  128), UINT16_C(10825), UINT16_C(57364), UINT16_C( 2194), UINT16_C( 2234), UINT16_C(58444) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vandq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vandq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(4293273589), UINT32_C(3685031970), UINT32_C( 352705382), UINT32_C(3156153161) },
      { UINT32_C(4180779521), UINT32_C(1424260668), UINT32_C(3210431843), UINT32_C(2472031390) },
      { UINT32_C(4179632641), UINT32_C(1352933408), UINT32_C( 352405858), UINT32_C(2417496072) } },
    { { UINT32_C(2106736475), UINT32_C(3310893151), UINT32_C(1574657299), UINT32_C(1897527920) },
      { UINT32_C(3647622045), UINT32_C( 741232329), UINT32_C( 988514716), UINT32_C( 416171197) },
      { UINT32_C(1493306137), UINT32_C(  67635273), UINT32_C( 415959312), UINT32_C( 268976176) } },
    { { UINT32_C(3801440387), UINT32_C(2896686744), UINT32_C(3154739787), UINT32_C( 439165565) },
      { UINT32_C( 938711149), UINT32_C(2187534822), UINT32_C(1740459946), UINT32_C( 377457555) },
      { UINT32_C( 579928065), UINT32_C(2149785728), UINT32_C( 604570122), UINT32_C( 304939537) } },
    { { UINT32_C(2230851051), UINT32_C(1311809283), UINT32_C(2668247330), UINT32_C(3384359003) },
      { UINT32_C(3053497552), UINT32_C(2017027022), UINT32_C(1172371122), UINT32_C(1817927553) },
      { UINT32_C(2214593728), UINT32_C(1211106050), UINT32_C(  83898402), UINT32_C(1209604097) } },
    { { UINT32_C(2012238708), UINT32_C( 365306099), UINT32_C(3048525913), UINT32_C(3632164104) },
      { UINT32_C(3884940825), UINT32_C(2489370849), UINT32_C(1071202494), UINT32_C( 346764703) },
      { UINT32_C(1736462864), UINT32_C( 339738849), UINT32_C( 898646040), UINT32_C( 271197448) } },
    { { UINT32_C(2072747144), UINT32_C( 378556860), UINT32_C( 717964322), UINT32_C(3405990321) },
      { UINT32_C(2830275271), UINT32_C( 406590042), UINT32_C(4065793618), UINT32_C(3540386379) },
      { UINT32_C( 679645312), UINT32_C( 269488152), UINT32_C( 574817282), UINT32_C(3271688193) } },
    { { UINT32_C(1531941278), UINT32_C(  91348963), UINT32_C(3576642596), UINT32_C(1285567109) },
      { UINT32_C( 519328708), UINT32_C(3090559333), UINT32_C(2460650823), UINT32_C( 778416272) },
      { UINT32_C( 440668548), UINT32_C(   3150177), UINT32_C(2418674692), UINT32_C( 203436160) } },
    { { UINT32_C( 613004353), UINT32_C(3089758868), UINT32_C(3146602806), UINT32_C(1342647947) },
      { UINT32_C(3866033281), UINT32_C(1956554029), UINT32_C(3255191602), UINT32_C( 988900344) },
      { UINT32_C( 604550145), UINT32_C( 805871620), UINT32_C(2181318706), UINT32_C( 268511880) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vandq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vandq_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 7109514916206232913), UINT64_C(10343282227606388255) },
      { UINT64_C(13806481744594689539), UINT64_C( 1434929476295376452) },
      { UINT64_C( 2488819499475682305), UINT64_C(  254629577833496068) } },
    { { UINT64_C(16983846929493703209), UINT64_C( 9560580713027717308) },
      { UINT64_C(16581777337322056031), UINT64_C( 9142413165197685004) },
      { UINT64_C(16290098746414606345), UINT64_C(  333266376929460236) } },
    { { UINT64_C( 8129420312540280090), UINT64_C(12271812326554749257) },
      { UINT64_C( 6696332920632181349), UINT64_C(16099254613146428824) },
      { UINT64_C( 5818650787282681856), UINT64_C( 9965349149790978312) } },
    { { UINT64_C(  297966258262194943), UINT64_C( 6040484805161693663) },
      { UINT64_C(11369980492630449438), UINT64_C(18181866214073758638) },
      { UINT64_C(  288793326679824414), UINT64_C( 5787148529890406798) } },
    { { UINT64_C(10227905302983808817), UINT64_C(17925324712174927490) },
      { UINT64_C( 1588135039376694888), UINT64_C(13555232943576290339) },
      { UINT64_C(  288248133360948768), UINT64_C(13259028904787678210) } },
    { { UINT64_C( 2319240140203543795), UINT64_C(15719906249242895958) },
      { UINT64_C(16280321058098613873), UINT64_C( 5200848691728120038) },
      { UINT64_C( 2319090606074268785), UINT64_C( 5199406114201952326) } },
    { { UINT64_C(14099389917174552044), UINT64_C(   21140926159338495) },
      { UINT64_C(14576121077305021353), UINT64_C( 6331331462427265857) },
      { UINT64_C(13981434268808221096), UINT64_C(   20556516926098241) } },
    { { UINT64_C(16027622640665675581), UINT64_C( 2619014137364046024) },
      { UINT64_C( 4313838188608827694), UINT64_C(13754466608369113119) },
      { UINT64_C( 1895317090072658220), UINT64_C( 2612239520812236808) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vandq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vand_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vand_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vand_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vand_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vand_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vand_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vand_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vand_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vandq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vandq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vandq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vandq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vandq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vandq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vandq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vandq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
