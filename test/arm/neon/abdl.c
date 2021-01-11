#define SIMDE_TEST_ARM_NEON_INSN abdl

#include "test-neon.h"
#include "../../../simde/arm/neon/abdl.h"

static int
test_simde_vabdl_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT8_C(  21), -INT8_C(  78), -INT8_C( 101),  INT8_C(  60), -INT8_C(  91), -INT8_C( 107),  INT8_C(  51), -INT8_C(  56) },
      {  INT8_C(  53), -INT8_C( 119), -INT8_C(  75),  INT8_C(  20), -INT8_C(  57),  INT8_C( 101),  INT8_C(  65), -INT8_C(  75) },
      {  INT16_C(    74),  INT16_C(    41),  INT16_C(    26),  INT16_C(    40),  INT16_C(    34),  INT16_C(   208),  INT16_C(    14),  INT16_C(    19) } },
    { { -INT8_C(  94),  INT8_C(  96), -INT8_C(  70),  INT8_C(  27), -INT8_C(  76),  INT8_C(  78), -INT8_C(  11),  INT8_C(  12) },
      { -INT8_C(   6),  INT8_C( 118),  INT8_C( 100),  INT8_C(  92), -INT8_C( 108),  INT8_C( 120), -INT8_C(  37),      INT8_MAX },
      {  INT16_C(    88),  INT16_C(    22),  INT16_C(   170),  INT16_C(    65),  INT16_C(    32),  INT16_C(    42),  INT16_C(    26),  INT16_C(   115) } },
    { {  INT8_C(  43),  INT8_C( 118), -INT8_C(  69), -INT8_C(  48),  INT8_C(  11), -INT8_C(  17), -INT8_C( 103),  INT8_C(  65) },
      {  INT8_C( 120),  INT8_C(  78),  INT8_C(  85),  INT8_C(  64), -INT8_C(  76), -INT8_C( 106), -INT8_C(  11),  INT8_C(  86) },
      {  INT16_C(    77),  INT16_C(    40),  INT16_C(   154),  INT16_C(   112),  INT16_C(    87),  INT16_C(    89),  INT16_C(    92),  INT16_C(    21) } },
    { { -INT8_C(  10), -INT8_C(  81),  INT8_C( 113), -INT8_C(  86), -INT8_C(   3),  INT8_C( 102), -INT8_C(  74), -INT8_C(   9) },
      { -INT8_C(  35),  INT8_C(  26),  INT8_C(  83),  INT8_C( 113), -INT8_C( 109),  INT8_C(  46), -INT8_C(  16), -INT8_C(  66) },
      {  INT16_C(    25),  INT16_C(   107),  INT16_C(    30),  INT16_C(   199),  INT16_C(   106),  INT16_C(    56),  INT16_C(    58),  INT16_C(    57) } },
    { { -INT8_C(  92), -INT8_C(  85), -INT8_C( 114), -INT8_C(  80), -INT8_C( 102),  INT8_C(  39), -INT8_C(  15),  INT8_C(  19) },
      {  INT8_C( 118),  INT8_C(  70),  INT8_C(  83),  INT8_C(  42), -INT8_C(  35),  INT8_C(  72),      INT8_MIN, -INT8_C(  45) },
      {  INT16_C(   210),  INT16_C(   155),  INT16_C(   197),  INT16_C(   122),  INT16_C(    67),  INT16_C(    33),  INT16_C(   113),  INT16_C(    64) } },
    { { -INT8_C(   8), -INT8_C(  14),  INT8_C( 126), -INT8_C(  11),  INT8_C(  88),  INT8_C(  52), -INT8_C(  19),  INT8_C(  53) },
      {  INT8_C(  79),  INT8_C(  64), -INT8_C(  90), -INT8_C(  30),  INT8_C( 111), -INT8_C( 106), -INT8_C(  96),  INT8_C(  19) },
      {  INT16_C(    87),  INT16_C(    78),  INT16_C(   216),  INT16_C(    19),  INT16_C(    23),  INT16_C(   158),  INT16_C(    77),  INT16_C(    34) } },
    { {  INT8_C(  66),  INT8_C(  46), -INT8_C(  61), -INT8_C(  36),  INT8_C(  86), -INT8_C(  76), -INT8_C(  17), -INT8_C(  52) },
      { -INT8_C(   5),  INT8_C(  66), -INT8_C(  10), -INT8_C(  40), -INT8_C( 117),  INT8_C( 118), -INT8_C(  85), -INT8_C( 125) },
      {  INT16_C(    71),  INT16_C(    20),  INT16_C(    51),  INT16_C(     4),  INT16_C(   203),  INT16_C(   194),  INT16_C(    68),  INT16_C(    73) } },
    { {  INT8_C( 104),  INT8_C(  41),  INT8_C( 120), -INT8_C(  63),  INT8_C(  94),  INT8_C( 101), -INT8_C(  10), -INT8_C(  83) },
      { -INT8_C(  90), -INT8_C(  99), -INT8_C( 113),  INT8_C(  21),  INT8_C(  51),  INT8_C(  47),  INT8_C(  40),  INT8_C( 117) },
      {  INT16_C(   194),  INT16_C(   140),  INT16_C(   233),  INT16_C(    84),  INT16_C(    43),  INT16_C(    54),  INT16_C(    50),  INT16_C(   200) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vabdl_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t r = simde_vabdl_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int32_t r[8];
  } test_vec[] = {
    { { -INT16_C( 21822), -INT16_C(  5449), -INT16_C( 14106), -INT16_C( 17373) },
      { -INT16_C( 20174), -INT16_C( 26812),  INT16_C(  3323),  INT16_C( 12091) },
      {  INT32_C(        1648),  INT32_C(       21363),  INT32_C(       17429),  INT32_C(       29464) } },
    { { -INT16_C( 29016), -INT16_C( 25436),  INT16_C( 32702),  INT16_C(  7743) },
      {  INT16_C( 18778), -INT16_C( 10383), -INT16_C( 21633),  INT16_C( 16951) },
      {  INT32_C(       47794),  INT32_C(       15053),  INT32_C(       54335),  INT32_C(        9208) } },
    { { -INT16_C(  4522),  INT16_C( 15404),  INT16_C( 20406), -INT16_C(  5639) },
      {  INT16_C( 15617), -INT16_C(   896), -INT16_C( 17591), -INT16_C(  3797) },
      {  INT32_C(       20139),  INT32_C(       16300),  INT32_C(       37997),  INT32_C(        1842) } },
    { { -INT16_C( 12470),  INT16_C(  2189), -INT16_C( 13234), -INT16_C( 22234) },
      { -INT16_C( 26859), -INT16_C( 27264), -INT16_C( 18621), -INT16_C( 26153) },
      {  INT32_C(       14389),  INT32_C(       29453),  INT32_C(        5387),  INT32_C(        3919) } },
    { {  INT16_C(   933),  INT16_C( 23509), -INT16_C( 12717),  INT16_C( 21572) },
      { -INT16_C( 15093),  INT16_C( 21584),  INT16_C( 31616), -INT16_C( 13755) },
      {  INT32_C(       16026),  INT32_C(        1925),  INT32_C(       44333),  INT32_C(       35327) } },
    { { -INT16_C( 11702), -INT16_C( 26157), -INT16_C(  1634), -INT16_C( 19390) },
      { -INT16_C( 15727), -INT16_C( 11191),  INT16_C(  8313),  INT16_C(  7789) },
      {  INT32_C(        4025),  INT32_C(       14966),  INT32_C(        9947),  INT32_C(       27179) } },
    { {  INT16_C( 16931),  INT16_C( 30329), -INT16_C( 16879),  INT16_C(  7370) },
      {  INT16_C(  6787),  INT16_C(   881), -INT16_C( 18795), -INT16_C(  7986) },
      {  INT32_C(       10144),  INT32_C(       29448),  INT32_C(        1916),  INT32_C(       15356) } },
    { { -INT16_C( 24183),  INT16_C( 10105), -INT16_C( 17510),  INT16_C( 11227) },
      {  INT16_C(  9341), -INT16_C(  2305),  INT16_C( 27716),  INT16_C( 26644) },
      {  INT32_C(       33524),  INT32_C(       12410),  INT32_C(       45226),  INT32_C(       15417) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vabdl_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t r = simde_vabdl_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[8];
    int32_t b[8];
    int64_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1059156561), -INT32_C(   824399541) },
      {  INT32_C(  1506954691), -INT32_C(  1925603324) },
      {  INT64_C(          2566111252),  INT64_C(          1101203783) } },
    { { -INT32_C(   608914879), -INT32_C(   368603027) },
      { -INT32_C(   102758732),  INT32_C(   576844915) },
      {  INT64_C(           506156147),  INT64_C(           945447942) } },
    { { -INT32_C(   840810623), -INT32_C(  1399079192) },
      {  INT32_C(   268791052),  INT32_C(  1318927885) },
      {  INT64_C(          1109601675),  INT64_C(          2718007077) } },
    { {  INT32_C(  1563054576), -INT32_C(  1773719071) },
      { -INT32_C(  1433458889), -INT32_C(  1664290789) },
      {  INT64_C(          2996513465),  INT64_C(           109428282) } },
    { {  INT32_C(   409579055),  INT32_C(  2042889581) },
      { -INT32_C(  2138453646), -INT32_C(   137484793) },
      {  INT64_C(          2548032701),  INT64_C(          2180374374) } },
    { {  INT32_C(  1498740855),  INT32_C(  1643092777) },
      { -INT32_C(   586449214), -INT32_C(  1652959122) },
      {  INT64_C(          2085190069),  INT64_C(          3296051899) } },
    { { -INT32_C(   206183546),  INT32_C(  1517058536) },
      {  INT32_C(  1239086402), -INT32_C(  1824478949) },
      {  INT64_C(          1445269948),  INT64_C(          3341537485) } },
    { { -INT32_C(   873687903), -INT32_C(   248718545) },
      { -INT32_C(   942786727), -INT32_C(  1771812849) },
      {  INT64_C(            69098824),  INT64_C(          1523094304) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vabdl_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t r = simde_vabdl_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C(114), UINT8_C(157), UINT8_C(216), UINT8_C( 82), UINT8_C(129), UINT8_C( 62), UINT8_C(248), UINT8_C(156) },
      { UINT8_C(177), UINT8_C( 48), UINT8_C( 68), UINT8_C(194), UINT8_C( 65), UINT8_C( 76), UINT8_C(174), UINT8_C(178) },
      { UINT16_C(   63), UINT16_C(  109), UINT16_C(  148), UINT16_C(  112), UINT16_C(   64), UINT16_C(   14), UINT16_C(   74), UINT16_C(   22) } },
    { { UINT8_C(191), UINT8_C(212), UINT8_C(174), UINT8_C(236), UINT8_C( 55), UINT8_C(141), UINT8_C( 55), UINT8_C(218) },
      { UINT8_C( 20), UINT8_C( 68), UINT8_C( 19), UINT8_C(122), UINT8_C( 38), UINT8_C( 29), UINT8_C(194), UINT8_C(152) },
      { UINT16_C(  171), UINT16_C(  144), UINT16_C(  155), UINT16_C(  114), UINT16_C(   17), UINT16_C(  112), UINT16_C(  139), UINT16_C(   66) } },
    { { UINT8_C(187), UINT8_C(155), UINT8_C(234), UINT8_C( 60), UINT8_C(217), UINT8_C(226), UINT8_C(216), UINT8_C(139) },
      { UINT8_C( 18), UINT8_C( 28), UINT8_C( 77), UINT8_C( 84), UINT8_C(104), UINT8_C(251), UINT8_C(  6), UINT8_C( 39) },
      { UINT16_C(  169), UINT16_C(  127), UINT16_C(  157), UINT16_C(   24), UINT16_C(  113), UINT16_C(   25), UINT16_C(  210), UINT16_C(  100) } },
    { { UINT8_C(207), UINT8_C(181), UINT8_C( 20), UINT8_C(  6), UINT8_C( 66), UINT8_C( 75), UINT8_C(224), UINT8_C( 87) },
      { UINT8_C(143), UINT8_C(243), UINT8_C(209), UINT8_C(181), UINT8_C( 17), UINT8_C(147), UINT8_C( 77), UINT8_C(204) },
      { UINT16_C(   64), UINT16_C(   62), UINT16_C(  189), UINT16_C(  175), UINT16_C(   49), UINT16_C(   72), UINT16_C(  147), UINT16_C(  117) } },
    { { UINT8_C( 46), UINT8_C( 56), UINT8_C(  8), UINT8_C(  8), UINT8_C( 26), UINT8_C(225), UINT8_C(147), UINT8_C( 45) },
      { UINT8_C(253), UINT8_C(224), UINT8_C(129), UINT8_C(102), UINT8_C(220), UINT8_C(135), UINT8_C(141), UINT8_C(171) },
      { UINT16_C(  207), UINT16_C(  168), UINT16_C(  121), UINT16_C(   94), UINT16_C(  194), UINT16_C(   90), UINT16_C(    6), UINT16_C(  126) } },
    { { UINT8_C( 60), UINT8_C(161), UINT8_C(178), UINT8_C(127), UINT8_C(236), UINT8_C(146), UINT8_C(214), UINT8_C(123) },
      { UINT8_C(134), UINT8_C(167), UINT8_C( 48), UINT8_C(151), UINT8_C( 58), UINT8_C(126), UINT8_C( 99), UINT8_C(105) },
      { UINT16_C(   74), UINT16_C(    6), UINT16_C(  130), UINT16_C(   24), UINT16_C(  178), UINT16_C(   20), UINT16_C(  115), UINT16_C(   18) } },
    { { UINT8_C(182), UINT8_C(107), UINT8_C(113), UINT8_C(208), UINT8_C( 76), UINT8_C(  4), UINT8_C(253), UINT8_C( 74) },
      { UINT8_C(228), UINT8_C(126), UINT8_C(176), UINT8_C(192), UINT8_C(  6), UINT8_C( 61), UINT8_C(108), UINT8_C( 66) },
      { UINT16_C(   46), UINT16_C(   19), UINT16_C(   63), UINT16_C(   16), UINT16_C(   70), UINT16_C(   57), UINT16_C(  145), UINT16_C(    8) } },
    { { UINT8_C(223), UINT8_C( 30), UINT8_C(193), UINT8_C(203), UINT8_C(176), UINT8_C(151), UINT8_C( 71), UINT8_C( 54) },
      { UINT8_C( 62), UINT8_C(119), UINT8_C(205), UINT8_C(121), UINT8_C(245), UINT8_C( 48), UINT8_C(226), UINT8_C(171) },
      { UINT16_C(  161), UINT16_C(   89), UINT16_C(   12), UINT16_C(   82), UINT16_C(   69), UINT16_C(  103), UINT16_C(  155), UINT16_C(  117) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vabdl_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t r = simde_vabdl_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint32_t r[8];
  } test_vec[] = {
    { { UINT16_C(23875), UINT16_C(19232), UINT16_C(54709), UINT16_C(16394) },
      { UINT16_C(53548), UINT16_C(54723), UINT16_C( 9886), UINT16_C(53583) },
      { UINT32_C(     29673), UINT32_C(     35491), UINT32_C(     44823), UINT32_C(     37189) } },
    { { UINT16_C( 3348), UINT16_C(14900), UINT16_C(47184), UINT16_C(20429) },
      { UINT16_C(29100), UINT16_C(28740), UINT16_C(20361), UINT16_C(52445) },
      { UINT32_C(     25752), UINT32_C(     13840), UINT32_C(     26823), UINT32_C(     32016) } },
    { { UINT16_C(64940), UINT16_C(24856), UINT16_C( 8914), UINT16_C(65185) },
      { UINT16_C(25843), UINT16_C(37331), UINT16_C( 9099), UINT16_C(40803) },
      { UINT32_C(     39097), UINT32_C(     12475), UINT32_C(       185), UINT32_C(     24382) } },
    { { UINT16_C(38704), UINT16_C(32985), UINT16_C(42832), UINT16_C(64719) },
      { UINT16_C( 5144), UINT16_C(41580), UINT16_C(18787), UINT16_C( 3950) },
      { UINT32_C(     33560), UINT32_C(      8595), UINT32_C(     24045), UINT32_C(     60769) } },
    { { UINT16_C(34374), UINT16_C( 6512), UINT16_C( 4520), UINT16_C(39703) },
      { UINT16_C(60278), UINT16_C(  301), UINT16_C(36878), UINT16_C(16032) },
      { UINT32_C(     25904), UINT32_C(      6211), UINT32_C(     32358), UINT32_C(     23671) } },
    { { UINT16_C(31015), UINT16_C(30655), UINT16_C(36384), UINT16_C(14707) },
      { UINT16_C(57506), UINT16_C( 1499), UINT16_C(18729), UINT16_C(28692) },
      { UINT32_C(     26491), UINT32_C(     29156), UINT32_C(     17655), UINT32_C(     13985) } },
    { { UINT16_C(34000), UINT16_C(30857), UINT16_C(41110), UINT16_C( 3092) },
      { UINT16_C(16779), UINT16_C(39181), UINT16_C(44497), UINT16_C(63704) },
      { UINT32_C(     17221), UINT32_C(      8324), UINT32_C(      3387), UINT32_C(     60612) } },
    { { UINT16_C(38694), UINT16_C(18288), UINT16_C(58149), UINT16_C(51328) },
      { UINT16_C(23491), UINT16_C(60877), UINT16_C(58020), UINT16_C(29789) },
      { UINT32_C(     15203), UINT32_C(     42589), UINT32_C(       129), UINT32_C(     21539) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vabdl_u16(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t r = simde_vabdl_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[8];
    uint32_t b[8];
    uint64_t r[8];
  } test_vec[] = {
    { { UINT32_C(4243449446), UINT32_C( 302514566) },
      { UINT32_C( 329979202), UINT32_C(3909845954) },
      { UINT64_C(          3913470244), UINT64_C(          3607331388) } },
    { { UINT32_C(1076919066), UINT32_C( 570994783) },
      { UINT32_C(2937050379), UINT32_C( 505703607) },
      { UINT64_C(          1860131313), UINT64_C(            65291176) } },
    { { UINT32_C(3642364242), UINT32_C(1424696082) },
      { UINT32_C(4217869880), UINT32_C( 887386650) },
      { UINT64_C(           575505638), UINT64_C(           537309432) } },
    { { UINT32_C(1299453166), UINT32_C(3480190148) },
      { UINT32_C( 159285074), UINT32_C(1042785003) },
      { UINT64_C(          1140168092), UINT64_C(          2437405145) } },
    { { UINT32_C(3306635955), UINT32_C(2635661925) },
      { UINT32_C(2996338840), UINT32_C(3790044403) },
      { UINT64_C(           310297115), UINT64_C(          1154382478) } },
    { { UINT32_C(1412324240), UINT32_C( 706977240) },
      { UINT32_C( 137601564), UINT32_C(4165360452) },
      { UINT64_C(          1274722676), UINT64_C(          3458383212) } },
    { { UINT32_C(  45964701), UINT32_C(4154447711) },
      { UINT32_C(1252669527), UINT32_C(1160483252) },
      { UINT64_C(          1206704826), UINT64_C(          2993964459) } },
    { { UINT32_C(3298384364), UINT32_C( 334413303) },
      { UINT32_C(2736464479), UINT32_C( 446390653) },
      { UINT64_C(           561919885), UINT64_C(           111977350) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vabdl_u32(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t r = simde_vabdl_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
