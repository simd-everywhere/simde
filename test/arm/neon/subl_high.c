#define SIMDE_TEST_ARM_NEON_INSN subl_high

#include "test-neon.h"
#include "../../../simde/arm/neon/subl_high.h"

static int
test_simde_vsubl_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int16_t r[8];
  } test_vec[] = {
    { {  INT8_C(  84), -INT8_C(  23),  INT8_C(  97),  INT8_C(  86), -INT8_C(  84), -INT8_C(  54), -INT8_C( 117),  INT8_C( 103),
        -INT8_C(  25), -INT8_C(  76), -INT8_C( 125), -INT8_C(  70),  INT8_C(  44), -INT8_C(  76),  INT8_C(  93), -INT8_C(  79) },
      {  INT8_C(  56),  INT8_C(  30),  INT8_C( 112),  INT8_C(  63),  INT8_C(   2), -INT8_C(  94),  INT8_C(  97),  INT8_C(  96),
        -INT8_C(  68),  INT8_C( 112), -INT8_C( 107), -INT8_C(  27),  INT8_C( 105), -INT8_C(   1), -INT8_C( 124), -INT8_C(  67) },
      {  INT16_C(    43), -INT16_C(   188), -INT16_C(    18), -INT16_C(    43), -INT16_C(    61), -INT16_C(    75),  INT16_C(   217), -INT16_C(    12) } },
    { { -INT8_C(  23), -INT8_C(  27),  INT8_C(  20), -INT8_C( 107), -INT8_C(  81), -INT8_C(  97), -INT8_C(   4), -INT8_C( 106),
         INT8_C(  83),      INT8_MIN,  INT8_C(  80),      INT8_MAX,  INT8_C(  52), -INT8_C(  83),  INT8_C(  48),  INT8_C( 108) },
      { -INT8_C(  52), -INT8_C(  95), -INT8_C(  84), -INT8_C(  50),  INT8_C(  67),  INT8_C(  13),  INT8_C(  47),  INT8_C(   0),
         INT8_C( 126), -INT8_C(  60), -INT8_C(  27), -INT8_C(  25), -INT8_C(  61),  INT8_C( 105), -INT8_C(  92), -INT8_C(  84) },
      { -INT16_C(    43), -INT16_C(    68),  INT16_C(   107),  INT16_C(   152),  INT16_C(   113), -INT16_C(   188),  INT16_C(   140),  INT16_C(   192) } },
    { {  INT8_C(  78), -INT8_C(  72),  INT8_C(  66), -INT8_C(   3),  INT8_C(  87),  INT8_C(  62), -INT8_C( 109), -INT8_C(  85),
        -INT8_C(  66), -INT8_C(  28),  INT8_C(  42), -INT8_C(  13), -INT8_C( 111),  INT8_C(  91),  INT8_C(  95),  INT8_C(  93) },
      { -INT8_C(   4),  INT8_C(  11),  INT8_C(  44),  INT8_C(  63),  INT8_C(  25),  INT8_C(  91),  INT8_C(  63), -INT8_C( 105),
         INT8_C(  31),  INT8_C(  37),  INT8_C( 126), -INT8_C(  30), -INT8_C( 114),  INT8_C(  34), -INT8_C( 113), -INT8_C(  35) },
      { -INT16_C(    97), -INT16_C(    65), -INT16_C(    84),  INT16_C(    17),  INT16_C(     3),  INT16_C(    57),  INT16_C(   208),  INT16_C(   128) } },
    { { -INT8_C(  37), -INT8_C(  47), -INT8_C(  38),  INT8_C(  50),  INT8_C(  15),  INT8_C( 110), -INT8_C(  35), -INT8_C(  50),
         INT8_C(  82),  INT8_C(   8), -INT8_C(  63), -INT8_C(  29),  INT8_C(  99),  INT8_C(  32),  INT8_C(  65),  INT8_C(  95) },
      {  INT8_C(  44),  INT8_C( 109), -INT8_C(  98),  INT8_C(  69), -INT8_C(  56), -INT8_C(  34), -INT8_C(  36), -INT8_C(  25),
         INT8_C(   3),  INT8_C(  90), -INT8_C(  55), -INT8_C( 111),  INT8_C( 124),  INT8_C(  88),  INT8_C( 110),  INT8_C(  87) },
      {  INT16_C(    79), -INT16_C(    82), -INT16_C(     8),  INT16_C(    82), -INT16_C(    25), -INT16_C(    56), -INT16_C(    45),  INT16_C(     8) } },
    { {  INT8_C(  41),  INT8_C(  73), -INT8_C( 118),  INT8_C(  57), -INT8_C(  73),  INT8_C( 103),  INT8_C(   7),  INT8_C(   9),
         INT8_C( 111), -INT8_C(  56), -INT8_C(  20), -INT8_C(  46), -INT8_C(  24),  INT8_C(  45),  INT8_C(  49),  INT8_C(  20) },
      { -INT8_C( 102), -INT8_C(  48),  INT8_C(  89),  INT8_C(  98), -INT8_C(  82),  INT8_C(  53),  INT8_C(  73), -INT8_C(  79),
        -INT8_C( 113),  INT8_C(  19),  INT8_C(  66),  INT8_C(  12),  INT8_C( 107), -INT8_C(  79),  INT8_C(  99), -INT8_C( 107) },
      {  INT16_C(   224), -INT16_C(    75), -INT16_C(    86), -INT16_C(    58), -INT16_C(   131),  INT16_C(   124), -INT16_C(    50),  INT16_C(   127) } },
    { { -INT8_C(   6), -INT8_C(  19), -INT8_C(  50), -INT8_C(  79),  INT8_C(  85), -INT8_C(  43), -INT8_C(  70), -INT8_C(  60),
        -INT8_C(  99), -INT8_C(  90), -INT8_C( 105), -INT8_C( 123), -INT8_C(  44), -INT8_C(  56), -INT8_C( 102),  INT8_C( 110) },
      { -INT8_C( 104), -INT8_C(  13), -INT8_C(  47),  INT8_C(  70),  INT8_C(  41),  INT8_C(  26), -INT8_C(   9), -INT8_C(  72),
         INT8_C(  45),  INT8_C(  58), -INT8_C(  60), -INT8_C( 103), -INT8_C(  21),  INT8_C(  40),  INT8_C(  46), -INT8_C(  27) },
      { -INT16_C(   144), -INT16_C(   148), -INT16_C(    45), -INT16_C(    20), -INT16_C(    23), -INT16_C(    96), -INT16_C(   148),  INT16_C(   137) } },
    { {  INT8_C(  21), -INT8_C(   4), -INT8_C( 106),  INT8_C( 106), -INT8_C(  47),  INT8_C(  80),  INT8_C(  47),  INT8_C( 110),
        -INT8_C(  10), -INT8_C(  58), -INT8_C(  13), -INT8_C(  54), -INT8_C( 114), -INT8_C( 115),  INT8_C(  57),  INT8_C(  39) },
      { -INT8_C( 127),  INT8_C(  10),  INT8_C( 109), -INT8_C(  86),  INT8_C(  36),  INT8_C( 101),  INT8_C(  98),  INT8_C(  82),
        -INT8_C(  97),  INT8_C(  39), -INT8_C(  21), -INT8_C( 118),  INT8_C(  79),  INT8_C(  25),  INT8_C( 111),  INT8_C( 100) },
      {  INT16_C(    87), -INT16_C(    97),  INT16_C(     8),  INT16_C(    64), -INT16_C(   193), -INT16_C(   140), -INT16_C(    54), -INT16_C(    61) } },
    { {  INT8_C(  21),  INT8_C(   5), -INT8_C(  49), -INT8_C(  26),  INT8_C(  85), -INT8_C(   2),  INT8_C(  84),  INT8_C(  75),
        -INT8_C(  60),  INT8_C(  71),  INT8_C(  22),  INT8_C(  82), -INT8_C(  43),  INT8_C(  79),  INT8_C( 121),  INT8_C(  86) },
      {  INT8_C(  89), -INT8_C(  25),  INT8_C(   0),  INT8_C( 125),  INT8_C(  76),  INT8_C(  98), -INT8_C(  49), -INT8_C(  21),
        -INT8_C( 119), -INT8_C(  70),  INT8_C( 117), -INT8_C(  40), -INT8_C(  45), -INT8_C(  28),  INT8_C(  61), -INT8_C(  24) },
      {  INT16_C(    59),  INT16_C(   141), -INT16_C(    95),  INT16_C(   122),  INT16_C(     2),  INT16_C(   107),  INT16_C(    60),  INT16_C(   110) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vsubl_high_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r = simde_vsubl_high_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C(  3305),  INT16_C( 16078),  INT16_C(  8714), -INT16_C( 12663), -INT16_C( 24726),  INT16_C( 16160), -INT16_C( 25874),  INT16_C( 18325) },
      { -INT16_C( 27263), -INT16_C( 12859), -INT16_C( 27401), -INT16_C( 32328),  INT16_C( 11599),  INT16_C(  8793), -INT16_C( 27119), -INT16_C(  1525) },
      { -INT32_C(       36325),  INT32_C(        7367),  INT32_C(        1245),  INT32_C(       19850) } },
    { { -INT16_C(  9822), -INT16_C( 21448), -INT16_C( 15876),  INT16_C( 26234), -INT16_C( 25759),  INT16_C( 20389),  INT16_C( 14901), -INT16_C( 18793) },
      {  INT16_C( 23759), -INT16_C( 14717),  INT16_C( 15344),  INT16_C( 16199), -INT16_C( 24216),  INT16_C( 31074),  INT16_C( 27959), -INT16_C(  9613) },
      { -INT32_C(        1543), -INT32_C(       10685), -INT32_C(       13058), -INT32_C(        9180) } },
    { { -INT16_C( 21690),  INT16_C( 17030),  INT16_C(   364), -INT16_C( 12888),  INT16_C( 19868), -INT16_C( 12003), -INT16_C( 19321),  INT16_C( 22151) },
      {  INT16_C(  2576),  INT16_C(    29),  INT16_C( 25669), -INT16_C( 21184), -INT16_C( 24059),  INT16_C( 15654), -INT16_C( 26353),  INT16_C( 21783) },
      {  INT32_C(       43927), -INT32_C(       27657),  INT32_C(        7032),  INT32_C(         368) } },
    { { -INT16_C( 25276), -INT16_C( 20328),  INT16_C( 16542),  INT16_C( 14974), -INT16_C( 25714),  INT16_C(  5387), -INT16_C( 28081),  INT16_C( 24428) },
      { -INT16_C( 30308), -INT16_C(  7841), -INT16_C( 24595), -INT16_C(  3186), -INT16_C( 19391),  INT16_C( 20528),  INT16_C( 18253), -INT16_C( 28250) },
      { -INT32_C(        6323), -INT32_C(       15141), -INT32_C(       46334),  INT32_C(       52678) } },
    { {  INT16_C( 16100), -INT16_C( 31934), -INT16_C( 16258),  INT16_C(  3261), -INT16_C( 13989), -INT16_C( 21982), -INT16_C( 29093), -INT16_C(  2039) },
      {  INT16_C( 26647),  INT16_C(  1241),  INT16_C( 26632),  INT16_C( 18935),  INT16_C( 10012),  INT16_C( 27290),  INT16_C( 16494),  INT16_C( 21499) },
      { -INT32_C(       24001), -INT32_C(       49272), -INT32_C(       45587), -INT32_C(       23538) } },
    { {  INT16_C( 15742), -INT16_C(   810), -INT16_C( 27651),  INT16_C( 22537),  INT16_C( 11100), -INT16_C( 18430),  INT16_C(  3001), -INT16_C( 12112) },
      { -INT16_C( 30348),  INT16_C( 31956), -INT16_C( 13071),  INT16_C(  3781),  INT16_C( 24563),  INT16_C( 25208),  INT16_C( 29599),  INT16_C(  7605) },
      { -INT32_C(       13463), -INT32_C(       43638), -INT32_C(       26598), -INT32_C(       19717) } },
    { { -INT16_C( 29775), -INT16_C( 20966),  INT16_C(  8990),  INT16_C( 31495),  INT16_C(  2382),  INT16_C(  1843), -INT16_C(  7403), -INT16_C( 30249) },
      { -INT16_C( 21652),  INT16_C( 24069), -INT16_C( 13705),  INT16_C( 27500), -INT16_C(  7126), -INT16_C( 13875), -INT16_C( 32169),  INT16_C(  2279) },
      {  INT32_C(        9508),  INT32_C(       15718),  INT32_C(       24766), -INT32_C(       32528) } },
    { {  INT16_C(   269),  INT16_C( 11191), -INT16_C( 16860),  INT16_C( 29350), -INT16_C(  9785), -INT16_C(  9095),  INT16_C( 20668),  INT16_C( 10597) },
      {  INT16_C( 27387),  INT16_C( 29575), -INT16_C(  3275),  INT16_C( 24542), -INT16_C( 21545),  INT16_C( 11816),  INT16_C(  3885),  INT16_C( 14903) },
      {  INT32_C(       11760), -INT32_C(       20911),  INT32_C(       16783), -INT32_C(        4306) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vsubl_high_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r = simde_vsubl_high_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(   879095312),  INT32_C(  1940262060), -INT32_C(  1571807259),  INT32_C(  1808512367) },
      {  INT32_C(  1440633376),  INT32_C(   481606725), -INT32_C(  1807033241), -INT32_C(    53575188) },
      {  INT64_C(           235225982),  INT64_C(          1862087555) } },
    { {  INT32_C(   456209263),  INT32_C(   630183743),  INT32_C(  1724375031), -INT32_C(  1261333868) },
      {  INT32_C(   688500708), -INT32_C(   767181461), -INT32_C(  2040098918), -INT32_C(  2138950639) },
      {  INT64_C(          3764473949),  INT64_C(           877616771) } },
    { { -INT32_C(  1482902680), -INT32_C(  2100548725), -INT32_C(  1628925174),  INT32_C(   156482085) },
      { -INT32_C(   718119831), -INT32_C(  1264093414),  INT32_C(   406457863), -INT32_C(  1432830910) },
      { -INT64_C(          2035383037),  INT64_C(          1589312995) } },
    { { -INT32_C(    78498704),  INT32_C(  1769807455), -INT32_C(   687315534), -INT32_C(  1981719777) },
      { -INT32_C(   782363721), -INT32_C(  1836776053),  INT32_C(  1454030611), -INT32_C(   335527300) },
      { -INT64_C(          2141346145), -INT64_C(          1646192477) } },
    { { -INT32_C(   689483145),  INT32_C(   591422577), -INT32_C(   369473335),  INT32_C(  1517476771) },
      {  INT32_C(  2049757423), -INT32_C(   385044011), -INT32_C(   314591631),  INT32_C(  1876508664) },
      { -INT64_C(            54881704), -INT64_C(           359031893) } },
    { {  INT32_C(    54968466), -INT32_C(   316242396),  INT32_C(  1909858510), -INT32_C(   338999044) },
      { -INT32_C(   295307496),  INT32_C(   450326953),  INT32_C(   520558119), -INT32_C(   410001323) },
      {  INT64_C(          1389300391),  INT64_C(            71002279) } },
    { { -INT32_C(   991242848),  INT32_C(   699469915),  INT32_C(   765102129), -INT32_C(   384277040) },
      {  INT32_C(   114785629),  INT32_C(   354463470),  INT32_C(   422848452), -INT32_C(  1493056761) },
      {  INT64_C(           342253677),  INT64_C(          1108779721) } },
    { { -INT32_C(   211031144),  INT32_C(   756817148),  INT32_C(  1968879268),  INT32_C(  2036232732) },
      { -INT32_C(   578865681), -INT32_C(  1477271581), -INT32_C(   843045178), -INT32_C(  2106277398) },
      {  INT64_C(          2811924446),  INT64_C(          4142510130) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vsubl_high_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r = simde_vsubl_high_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C( 62), UINT8_C(164), UINT8_C(240), UINT8_C( 49), UINT8_C( 68), UINT8_C(185), UINT8_C(125), UINT8_C(244),
        UINT8_C(143), UINT8_C( 26), UINT8_C(170), UINT8_C(252), UINT8_C( 63), UINT8_C( 10), UINT8_C(153), UINT8_C(193) },
      { UINT8_C( 53), UINT8_C(185), UINT8_C( 60), UINT8_C( 17), UINT8_C(167), UINT8_C(244), UINT8_C(107), UINT8_C(175),
        UINT8_C( 78), UINT8_C( 73), UINT8_C(106), UINT8_C( 34), UINT8_C(120), UINT8_C(243), UINT8_C(112), UINT8_C(182) },
      { UINT16_C(   65), UINT16_C(65489), UINT16_C(   64), UINT16_C(  218), UINT16_C(65479), UINT16_C(65303), UINT16_C(   41), UINT16_C(   11) } },
    { { UINT8_C(152), UINT8_C( 96), UINT8_C(231), UINT8_C(220), UINT8_C( 26), UINT8_C(101), UINT8_C(208), UINT8_C(169),
        UINT8_C(127), UINT8_C(122), UINT8_C(166), UINT8_C(190), UINT8_C(133), UINT8_C( 63), UINT8_C(127), UINT8_C(186) },
      { UINT8_C(248), UINT8_C(187), UINT8_C(203), UINT8_C(160), UINT8_C(176), UINT8_C( 54), UINT8_C( 79), UINT8_C(254),
        UINT8_C(127), UINT8_C(185), UINT8_C( 32), UINT8_C(247), UINT8_C(173), UINT8_C(145), UINT8_C(174), UINT8_C( 69) },
      { UINT16_C(    0), UINT16_C(65473), UINT16_C(  134), UINT16_C(65479), UINT16_C(65496), UINT16_C(65454), UINT16_C(65489), UINT16_C(  117) } },
    { { UINT8_C(241), UINT8_C(149), UINT8_C( 33), UINT8_C( 11), UINT8_C(250), UINT8_C(241), UINT8_C(181), UINT8_C(121),
        UINT8_C(108), UINT8_C( 91), UINT8_C( 56), UINT8_C(241), UINT8_C(154), UINT8_C(183), UINT8_C(171), UINT8_C(146) },
      { UINT8_C(115), UINT8_C(118), UINT8_C( 50), UINT8_C( 35), UINT8_C(173), UINT8_C(130), UINT8_C( 33), UINT8_C( 44),
        UINT8_C( 59), UINT8_C( 65), UINT8_C( 36), UINT8_C(232), UINT8_C(210), UINT8_C(210), UINT8_C( 45), UINT8_C(196) },
      { UINT16_C(   49), UINT16_C(   26), UINT16_C(   20), UINT16_C(    9), UINT16_C(65480), UINT16_C(65509), UINT16_C(  126), UINT16_C(65486) } },
    { { UINT8_C(103), UINT8_C( 78), UINT8_C(207), UINT8_C( 98), UINT8_C( 64), UINT8_C(132), UINT8_C(219), UINT8_C(172),
        UINT8_C(223), UINT8_C( 19), UINT8_C(157), UINT8_C(121), UINT8_C(203), UINT8_C( 72), UINT8_C( 12), UINT8_C( 62) },
      { UINT8_C(190), UINT8_C( 62), UINT8_C( 97), UINT8_C(107), UINT8_C(192), UINT8_C(130), UINT8_C(152), UINT8_C(252),
        UINT8_C(195), UINT8_C(188), UINT8_C(228), UINT8_C(150), UINT8_C(142), UINT8_C( 18), UINT8_C( 90), UINT8_C(245) },
      { UINT16_C(   28), UINT16_C(65367), UINT16_C(65465), UINT16_C(65507), UINT16_C(   61), UINT16_C(   54), UINT16_C(65458), UINT16_C(65353) } },
    { { UINT8_C( 96), UINT8_C( 41), UINT8_C( 87), UINT8_C(160), UINT8_C(174), UINT8_C( 51), UINT8_C( 76), UINT8_C(141),
        UINT8_C( 70), UINT8_C(233), UINT8_C(  7), UINT8_C( 17), UINT8_C( 49), UINT8_C( 19), UINT8_C( 79), UINT8_C(240) },
      { UINT8_C( 81), UINT8_C(176), UINT8_C( 91), UINT8_C( 18), UINT8_C( 50), UINT8_C(243), UINT8_C( 14), UINT8_C(246),
        UINT8_C(175), UINT8_C(242), UINT8_C(140), UINT8_C( 61), UINT8_C(  4), UINT8_C(230), UINT8_C( 51), UINT8_C(101) },
      { UINT16_C(65431), UINT16_C(65527), UINT16_C(65403), UINT16_C(65492), UINT16_C(   45), UINT16_C(65325), UINT16_C(   28), UINT16_C(  139) } },
    { { UINT8_C( 15), UINT8_C(138), UINT8_C(  5), UINT8_C(189), UINT8_C(189), UINT8_C( 82), UINT8_C( 75), UINT8_C(  4),
        UINT8_C( 59), UINT8_C( 82), UINT8_C( 21), UINT8_C(109), UINT8_C(101), UINT8_C(101), UINT8_C( 93), UINT8_C(182) },
      { UINT8_C( 21), UINT8_C(184), UINT8_C(200), UINT8_C( 72), UINT8_C(172), UINT8_C(214), UINT8_C( 62), UINT8_C( 91),
        UINT8_C(201), UINT8_C(202), UINT8_C(153), UINT8_C(205), UINT8_C(176), UINT8_C(204), UINT8_C( 50), UINT8_C(191) },
      { UINT16_C(65394), UINT16_C(65416), UINT16_C(65404), UINT16_C(65440), UINT16_C(65461), UINT16_C(65433), UINT16_C(   43), UINT16_C(65527) } },
    { { UINT8_C( 86), UINT8_C( 56), UINT8_C(125), UINT8_C( 20), UINT8_C(138), UINT8_C(200), UINT8_C( 24), UINT8_C(197),
        UINT8_C( 26), UINT8_C( 45), UINT8_C( 50), UINT8_C(127), UINT8_C(146), UINT8_C(143), UINT8_C( 53), UINT8_C(168) },
      { UINT8_C( 72), UINT8_C(254), UINT8_C(240), UINT8_C(244), UINT8_C(212), UINT8_C( 46), UINT8_C( 79), UINT8_C(157),
        UINT8_C(248), UINT8_C(232), UINT8_C(107), UINT8_C(168), UINT8_C(180), UINT8_C(157), UINT8_C(103), UINT8_C( 11) },
      { UINT16_C(65314), UINT16_C(65349), UINT16_C(65479), UINT16_C(65495), UINT16_C(65502), UINT16_C(65522), UINT16_C(65486), UINT16_C(  157) } },
    { { UINT8_C(213), UINT8_C(228), UINT8_C( 31), UINT8_C( 95), UINT8_C(172), UINT8_C( 55), UINT8_C( 37), UINT8_C(198),
        UINT8_C(100), UINT8_C( 87), UINT8_C( 69), UINT8_C(247), UINT8_C(231), UINT8_C(123), UINT8_C(159), UINT8_C( 47) },
      { UINT8_C(121), UINT8_C(143), UINT8_C( 35), UINT8_C( 77), UINT8_C(189), UINT8_C(114), UINT8_C(235), UINT8_C(181),
        UINT8_C( 91), UINT8_C( 86), UINT8_C( 93), UINT8_C( 15), UINT8_C(243), UINT8_C(196), UINT8_C( 26), UINT8_C(201) },
      { UINT16_C(    9), UINT16_C(    1), UINT16_C(65512), UINT16_C(  232), UINT16_C(65524), UINT16_C(65463), UINT16_C(  133), UINT16_C(65382) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vsubl_high_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r = simde_vsubl_high_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(57261), UINT16_C(43382), UINT16_C(37627), UINT16_C(41174), UINT16_C(12361), UINT16_C(25877), UINT16_C(29602), UINT16_C(37342) },
      { UINT16_C(23976), UINT16_C(35694), UINT16_C(24828), UINT16_C(49714), UINT16_C(62086), UINT16_C(28815), UINT16_C(  948), UINT16_C(25075) },
      { UINT32_C(4294917571), UINT32_C(4294964358), UINT32_C(     28654), UINT32_C(     12267) } },
    { { UINT16_C(27106), UINT16_C(56586), UINT16_C(57595), UINT16_C(17533), UINT16_C(37392), UINT16_C(45737), UINT16_C(34565), UINT16_C(44355) },
      { UINT16_C(45540), UINT16_C(57400), UINT16_C(27153), UINT16_C(38818), UINT16_C(12637), UINT16_C( 4360), UINT16_C(64308), UINT16_C( 5746) },
      { UINT32_C(     24755), UINT32_C(     41377), UINT32_C(4294937553), UINT32_C(     38609) } },
    { { UINT16_C(31844), UINT16_C(24564), UINT16_C(29020), UINT16_C(27812), UINT16_C(19716), UINT16_C( 2334), UINT16_C(25045), UINT16_C(47543) },
      { UINT16_C(61202), UINT16_C( 9114), UINT16_C(15450), UINT16_C(47034), UINT16_C(49774), UINT16_C(41672), UINT16_C(15037), UINT16_C( 8633) },
      { UINT32_C(4294937238), UINT32_C(4294927958), UINT32_C(     10008), UINT32_C(     38910) } },
    { { UINT16_C(44470), UINT16_C( 4737), UINT16_C( 9502), UINT16_C( 8830), UINT16_C(40050), UINT16_C(18220), UINT16_C(58365), UINT16_C( 3841) },
      { UINT16_C(39890), UINT16_C(11314), UINT16_C(60631), UINT16_C(17891), UINT16_C(43951), UINT16_C(27880), UINT16_C(41445), UINT16_C(39822) },
      { UINT32_C(4294963395), UINT32_C(4294957636), UINT32_C(     16920), UINT32_C(4294931315) } },
    { { UINT16_C( 3918), UINT16_C(27821), UINT16_C(11060), UINT16_C(42639), UINT16_C(48071), UINT16_C(50414), UINT16_C(61342), UINT16_C(28883) },
      { UINT16_C( 1418), UINT16_C(24989), UINT16_C(33010), UINT16_C(41383), UINT16_C(36652), UINT16_C( 4365), UINT16_C(39728), UINT16_C(32429) },
      { UINT32_C(     11419), UINT32_C(     46049), UINT32_C(     21614), UINT32_C(4294963750) } },
    { { UINT16_C(23210), UINT16_C(57066), UINT16_C(31110), UINT16_C(19845), UINT16_C(29492), UINT16_C(53778), UINT16_C(58722), UINT16_C(60483) },
      { UINT16_C(57579), UINT16_C(56653), UINT16_C(62560), UINT16_C(35966), UINT16_C(35715), UINT16_C(45982), UINT16_C(19239), UINT16_C(53553) },
      { UINT32_C(4294961073), UINT32_C(      7796), UINT32_C(     39483), UINT32_C(      6930) } },
    { { UINT16_C( 7333), UINT16_C(11184), UINT16_C(13717), UINT16_C(51833), UINT16_C(35752), UINT16_C( 2716), UINT16_C(57200), UINT16_C(23542) },
      { UINT16_C(17343), UINT16_C( 8248), UINT16_C(46648), UINT16_C(48044), UINT16_C(19010), UINT16_C(26991), UINT16_C(41109), UINT16_C(15162) },
      { UINT32_C(     16742), UINT32_C(4294943021), UINT32_C(     16091), UINT32_C(      8380) } },
    { { UINT16_C(60092), UINT16_C(21094), UINT16_C(57119), UINT16_C(50972), UINT16_C(47210), UINT16_C(56273), UINT16_C(51096), UINT16_C(22326) },
      { UINT16_C(28427), UINT16_C(17271), UINT16_C( 9253), UINT16_C(26622), UINT16_C(28014), UINT16_C( 1232), UINT16_C( 2830), UINT16_C(51775) },
      { UINT32_C(     19196), UINT32_C(     55041), UINT32_C(     48266), UINT32_C(4294937847) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vsubl_high_u16(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r = simde_vsubl_high_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C( 354199029), UINT32_C(4024187013), UINT32_C(2311761649), UINT32_C(2162164085) },
      { UINT32_C(2512607344), UINT32_C(3942498940), UINT32_C(1039060271), UINT32_C(3456642520) },
      { UINT64_C(          1272701378), UINT64_C(18446744072415073181) } },
    { { UINT32_C(1491281107), UINT32_C(1313324893), UINT32_C(3822522989), UINT32_C(2204350227) },
      { UINT32_C(2333615887), UINT32_C( 410392041), UINT32_C(3143001315), UINT32_C(1703501458) },
      { UINT64_C(           679521674), UINT64_C(           500848769) } },
    { { UINT32_C(3753733250), UINT32_C(2569864236), UINT32_C( 695993366), UINT32_C(3417104572) },
      { UINT32_C(4032283911), UINT32_C(3171470810), UINT32_C(3279511089), UINT32_C(1059586748) },
      { UINT64_C(18446744071126033893), UINT64_C(          2357517824) } },
    { { UINT32_C(2602493295), UINT32_C(   3427562), UINT32_C( 204124496), UINT32_C(2564347537) },
      { UINT32_C(1988636571), UINT32_C( 758354172), UINT32_C(2884742383), UINT32_C( 518658479) },
      { UINT64_C(18446744071028933729), UINT64_C(          2045689058) } },
    { { UINT32_C(3921218047), UINT32_C(2783571285), UINT32_C( 800199582), UINT32_C(2244446954) },
      { UINT32_C(3053146041), UINT32_C(3487707104), UINT32_C(2323305435), UINT32_C(3970459117) },
      { UINT64_C(18446744072186445763), UINT64_C(18446744071983539453) } },
    { { UINT32_C(3285541230), UINT32_C(3983064655), UINT32_C(3156024018), UINT32_C(1564599460) },
      { UINT32_C( 336739636), UINT32_C(1206121836), UINT32_C(3050462664), UINT32_C( 815889090) },
      { UINT64_C(           105561354), UINT64_C(           748710370) } },
    { { UINT32_C( 737375964), UINT32_C( 119036981), UINT32_C( 465778038), UINT32_C(1316488218) },
      { UINT32_C(2908916545), UINT32_C(1224033664), UINT32_C(1711196066), UINT32_C( 496344897) },
      { UINT64_C(18446744072464133588), UINT64_C(           820143321) } },
    { { UINT32_C(1263044886), UINT32_C(1532125669), UINT32_C(2960528790), UINT32_C(1543434009) },
      { UINT32_C(4194852986), UINT32_C(1212349861), UINT32_C( 112017604), UINT32_C(4129506016) },
      { UINT64_C(          2848511186), UINT64_C(18446744071123479609) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vsubl_high_u32(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r = simde_vsubl_high_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_high_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
