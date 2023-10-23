#define SIMDE_TEST_ARM_NEON_INSN addhn_high

#include "test-neon.h"
#include "../../../simde/arm/neon/addhn_high.h"

static int
test_simde_vaddhn_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t origin_r[8];
    int16_t a[8];
    int16_t b[8];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(    61), -INT8_C(    36),  INT8_C(   101),  INT8_C(   118),
         INT8_C(     5),  INT8_C(    38),  INT8_C(    90), -INT8_C(    48) },
      { -INT16_C(  8244), -INT16_C(   939),  INT16_C(  7799),  INT16_C( 10369),
         INT16_C( 10076),  INT16_C( 15809), -INT16_C( 15725),  INT16_C( 16407) },
      {  INT16_C( 19796), -INT16_C(  5464), -INT16_C( 28478),  INT16_C( 11563),
        -INT16_C( 10609), -INT16_C( 21211), -INT16_C( 28058),  INT16_C( 14771) },
      { -INT8_C(    61), -INT8_C(    36),  INT8_C(   101),  INT8_C(   118),
         INT8_C(     5),  INT8_C(    38),  INT8_C(    90), -INT8_C(    48),
         INT8_C(    45), -INT8_C(    26), -INT8_C(    81),  INT8_C(    85),
        -INT8_C(     3), -INT8_C(    22),  INT8_C(    84),  INT8_C(   121) } },
    { { -INT8_C(    97), -INT8_C(    63), -INT8_C(    29),  INT8_C(    38),
         INT8_C(    64), -INT8_C(    66), -INT8_C(    24), -INT8_C(    43) },
      {  INT16_C( 24705),  INT16_C( 30976),  INT16_C(   631), -INT16_C( 31504),
         INT16_C(  9667),  INT16_C(  2488),  INT16_C(  8715), -INT16_C(   199) },
      { -INT16_C( 24960),  INT16_C( 20198),  INT16_C( 22009), -INT16_C(   409),
         INT16_C(  5277),  INT16_C( 12713),  INT16_C( 14944),  INT16_C( 32237) },
      { -INT8_C(    97), -INT8_C(    63), -INT8_C(    29),  INT8_C(    38),
         INT8_C(    64), -INT8_C(    66), -INT8_C(    24), -INT8_C(    43),
        -INT8_C(     1), -INT8_C(    57),  INT8_C(    88), -INT8_C(   125),
         INT8_C(    58),  INT8_C(    59),  INT8_C(    92),  INT8_C(   125) } },
    { {  INT8_C(    72),  INT8_C(    73), -INT8_C(   107), -INT8_C(    96),
        -INT8_C(    30),  INT8_C(    39), -INT8_C(   123),  INT8_C(    21) },
      { -INT16_C( 21549),  INT16_C( 21299), -INT16_C( 11846), -INT16_C( 11763),
        -INT16_C( 17359),  INT16_C( 23796), -INT16_C( 27921),  INT16_C(  7298) },
      { -INT16_C( 17251),  INT16_C( 29846), -INT16_C( 19967), -INT16_C(  6977),
        -INT16_C( 14403),  INT16_C( 20581), -INT16_C( 21783),  INT16_C(  8203) },
      {  INT8_C(    72),  INT8_C(    73), -INT8_C(   107), -INT8_C(    96),
        -INT8_C(    30),  INT8_C(    39), -INT8_C(   123),  INT8_C(    21),
         INT8_C(   104), -INT8_C(    57), -INT8_C(   125), -INT8_C(    74),
        -INT8_C(   125), -INT8_C(    83),  INT8_C(    61),  INT8_C(    60) } },
    { {  INT8_C(    52),  INT8_C(    56), -INT8_C(     1), -INT8_C(    32),
         INT8_C(    88), -INT8_C(    36), -INT8_C(    98), -INT8_C(    75) },
      { -INT16_C(  1503),  INT16_C( 11183), -INT16_C( 26958), -INT16_C( 23638),
        -INT16_C( 27007), -INT16_C(  4796),  INT16_C(  1261), -INT16_C( 18964) },
      { -INT16_C( 15248),  INT16_C( 13875),  INT16_C( 18453),  INT16_C( 26114),
         INT16_C( 13003), -INT16_C( 24538), -INT16_C( 11457),  INT16_C(  2464) },
      {  INT8_C(    52),  INT8_C(    56), -INT8_C(     1), -INT8_C(    32),
         INT8_C(    88), -INT8_C(    36), -INT8_C(    98), -INT8_C(    75),
        -INT8_C(    66),  INT8_C(    97), -INT8_C(    34),  INT8_C(     9),
        -INT8_C(    55), -INT8_C(   115), -INT8_C(    40), -INT8_C(    65) } },
    { { -INT8_C(    84), -INT8_C(     1),  INT8_C(    50), -INT8_C(    44),
         INT8_C(    83), -INT8_C(    31),  INT8_C(     8),  INT8_C(    71) },
      { -INT16_C(  6417), -INT16_C( 17538),  INT16_C( 29763),  INT16_C(  1214),
        -INT16_C( 28461),  INT16_C(  1968), -INT16_C(  9702), -INT16_C( 26363) },
      {  INT16_C( 31827), -INT16_C( 14828), -INT16_C( 28361), -INT16_C( 24697),
        -INT16_C( 25550),  INT16_C( 18231), -INT16_C( 19362),  INT16_C( 19659) },
      { -INT8_C(    84), -INT8_C(     1),  INT8_C(    50), -INT8_C(    44),
         INT8_C(    83), -INT8_C(    31),  INT8_C(     8),  INT8_C(    71),
         INT8_C(    99), -INT8_C(   127),  INT8_C(     5), -INT8_C(    92),
         INT8_C(    45),  INT8_C(    78), -INT8_C(   114), -INT8_C(    27) } },
    { { -INT8_C(    41), -INT8_C(     7), -INT8_C(   118),  INT8_C(    82),
         INT8_C(    21),  INT8_C(    79),  INT8_C(    37),  INT8_C(    96) },
      { -INT16_C( 14532), -INT16_C(  2875),  INT16_C( 27061), -INT16_C(  4795),
         INT16_C(  9795),  INT16_C(  8274),  INT16_C(  3770), -INT16_C( 15366) },
      {  INT16_C( 15622),  INT16_C( 26195),  INT16_C( 32415),  INT16_C( 30676),
         INT16_C(  5556),  INT16_C( 16742), -INT16_C(  3588),  INT16_C( 24022) },
      { -INT8_C(    41), -INT8_C(     7), -INT8_C(   118),  INT8_C(    82),
         INT8_C(    21),  INT8_C(    79),  INT8_C(    37),  INT8_C(    96),
         INT8_C(     4),  INT8_C(    91), -INT8_C(    24),  INT8_C(   101),
         INT8_C(    59),  INT8_C(    97),  INT8_C(     0),  INT8_C(    33) } },
    { { -INT8_C(    59), -INT8_C(     2),  INT8_C(     9),  INT8_C(   108),
        -INT8_C(    99), -INT8_C(    43), -INT8_C(    16),  INT8_C(    89) },
      {  INT16_C( 13559), -INT16_C(   904),  INT16_C(  6886),  INT16_C( 19984),
         INT16_C( 18666), -INT16_C(  8533),  INT16_C( 22436), -INT16_C( 15261) },
      {  INT16_C(  7691),  INT16_C( 13814),  INT16_C( 14534),  INT16_C( 23813),
         INT16_C( 23486),  INT16_C(  5908), -INT16_C( 20988), -INT16_C( 25417) },
      { -INT8_C(    59), -INT8_C(     2),  INT8_C(     9),  INT8_C(   108),
        -INT8_C(    99), -INT8_C(    43), -INT8_C(    16),  INT8_C(    89),
         INT8_C(    83),  INT8_C(    50),  INT8_C(    83), -INT8_C(    85),
        -INT8_C(    92), -INT8_C(    11),  INT8_C(     5),  INT8_C(    97) } },
    { { -INT8_C(    57), -INT8_C(    64), -INT8_C(    98),  INT8_C(    99),
         INT8_C(     4), -INT8_C(    85), -INT8_C(    15),  INT8_C(    26) },
      { -INT16_C( 28861),  INT16_C(  4168), -INT16_C(  2113),  INT16_C( 23408),
         INT16_C(  2195), -INT16_C( 25357),  INT16_C(  4606), -INT16_C(  5610) },
      { -INT16_C( 29669), -INT16_C(   957),  INT16_C( 20282),  INT16_C( 18151),
        -INT16_C( 29362),  INT16_C( 18807), -INT16_C( 20997),  INT16_C( 24015) },
      { -INT8_C(    57), -INT8_C(    64), -INT8_C(    98),  INT8_C(    99),
         INT8_C(     4), -INT8_C(    85), -INT8_C(    15),  INT8_C(    26),
         INT8_C(    27),  INT8_C(    12),  INT8_C(    70), -INT8_C(    94),
        -INT8_C(   107), -INT8_C(    26), -INT8_C(    65),  INT8_C(    71) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t origin_r = simde_vld1_s8(test_vec[i].origin_r);
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int8x16_t r = simde_vaddhn_high_s16(origin_r, a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t origin_r = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t r = simde_vaddhn_high_s16(origin_r, a, b);

    simde_test_arm_neon_write_i8x8(2, origin_r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t origin_r[4];
    int32_t a[4];
    int32_t b[4];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(       24669),  INT16_C(       18457),  INT16_C(       18918), -INT16_C(       14001) },
      {  INT32_C(  1483207355), -INT32_C(   456511157),  INT32_C(  1424887713),  INT32_C(    94302488) },
      { -INT32_C(  1132458979), -INT32_C(  2126257994),  INT32_C(  1514575984), -INT32_C(  1335835137) },
      { -INT16_C(       24669),  INT16_C(       18457),  INT16_C(       18918), -INT16_C(       14001),
         INT16_C(        5351),  INT16_C(       26126), -INT16_C(       20684), -INT16_C(       18945) } },
    { {  INT16_C(       31189), -INT16_C(       11485),  INT16_C(        4407), -INT16_C(       16586) },
      {  INT32_C(   215140660), -INT32_C(  1171538740),  INT32_C(  1718439732),  INT32_C(   815282501) },
      {  INT32_C(   404107251),  INT32_C(   914811459),  INT32_C(   251170030), -INT32_C(   360609987) },
      {  INT16_C(       31189), -INT16_C(       11485),  INT16_C(        4407), -INT16_C(       16586),
         INT16_C(        9448), -INT16_C(        3918),  INT16_C(       30053),  INT16_C(        6937) } },
    { {  INT16_C(       15685),  INT16_C(       30826), -INT16_C(       24755),  INT16_C(       25262) },
      {  INT32_C(   613112243), -INT32_C(   284779600), -INT32_C(   515248826),  INT32_C(   642309127) },
      { -INT32_C(  1339990145),  INT32_C(   576195649), -INT32_C(  1767316590), -INT32_C(  2037097214) },
      {  INT16_C(       15685),  INT16_C(       30826), -INT16_C(       24755),  INT16_C(       25262),
        -INT16_C(       11092),  INT16_C(        4446),  INT16_C(       30706), -INT16_C(       21283) } },
    { {  INT16_C(        6325), -INT16_C(       19117),  INT16_C(       24681),  INT16_C(       21422) },
      { -INT32_C(  2066760783), -INT32_C(  1270926266), -INT32_C(  1737064360),  INT32_C(  1326893499) },
      { -INT32_C(  1770139956),  INT32_C(   303972981), -INT32_C(  1658815640),  INT32_C(    67382087) },
      {  INT16_C(        6325), -INT16_C(       19117),  INT16_C(       24681),  INT16_C(       21422),
         INT16_C(        6989), -INT16_C(       14755),  INT16_C(       13718),  INT16_C(       21274) } },
    { {  INT16_C(        9569), -INT16_C(       13533), -INT16_C(          53), -INT16_C(       24443) },
      { -INT32_C(   856343336),  INT32_C(   490191900), -INT32_C(   795751106), -INT32_C(  1123832281) },
      { -INT32_C(   526858630), -INT32_C(  2098625289), -INT32_C(  1069818864), -INT32_C(  1888359905) },
      {  INT16_C(        9569), -INT16_C(       13533), -INT16_C(          53), -INT16_C(       24443),
        -INT16_C(       21106), -INT16_C(       24543), -INT16_C(       28467),  INT16_C(       19573) } },
    { { -INT16_C(        9906),  INT16_C(        2769), -INT16_C(       32487),  INT16_C(       28195) },
      { -INT32_C(   358150056),  INT32_C(   610719560), -INT32_C(  1263704656),  INT32_C(   414821454) },
      {  INT32_C(  2109161422),  INT32_C(   705138128), -INT32_C(  1263227665), -INT32_C(  1697222027) },
      { -INT16_C(        9906),  INT16_C(        2769), -INT16_C(       32487),  INT16_C(       28195),
         INT16_C(       26718),  INT16_C(       20078),  INT16_C(       26978), -INT16_C(       19568) } },
    { {  INT16_C(        5638), -INT16_C(       20590), -INT16_C(       15113), -INT16_C(       16728) },
      {  INT32_C(  1222471517), -INT32_C(   703191341), -INT32_C(   837435852),  INT32_C(  1063583750) },
      {  INT32_C(   125790875),  INT32_C(   433330324),  INT32_C(  1232993791), -INT32_C(   602419856) },
      {  INT16_C(        5638), -INT16_C(       20590), -INT16_C(       15113), -INT16_C(       16728),
         INT16_C(       20572), -INT16_C(        4118),  INT16_C(        6035),  INT16_C(        7036) } },
    { {  INT16_C(       22367), -INT16_C(        9818),  INT16_C(       19398),  INT16_C(        5711) },
      {  INT32_C(   959448246), -INT32_C(  1653704784),  INT32_C(  1771944911), -INT32_C(  1736697356) },
      {  INT32_C(   204323872),  INT32_C(  1921740113),  INT32_C(   183457932), -INT32_C(  1347390424) },
      {  INT16_C(       22367), -INT16_C(        9818),  INT16_C(       19398),  INT16_C(        5711),
         INT16_C(       17757),  INT16_C(        4089),  INT16_C(       29837),  INT16_C(       18476) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t origin_r = simde_vld1_s16(test_vec[i].origin_r);
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int16x8_t r = simde_vaddhn_high_s32(origin_r, a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t origin_r = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t r = simde_vaddhn_high_s32(origin_r, a, b);

    simde_test_arm_neon_write_i16x4(2, origin_r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_high_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t origin_r[2];
    int64_t a[2];
    int64_t b[2];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(           875919724), -INT32_C(           611701371) },
      { -INT64_C( 5363233495659755355), -INT64_C( 2481988998786220685) },
      {  INT64_C( 7239945546212710468), -INT64_C( 5153377132087920374) },
      { -INT32_C(           875919724), -INT32_C(           611701371),  INT32_C(           436956074), -INT32_C(          1777747211) } },
    { {  INT32_C(          1546325407),  INT32_C(            25514132) },
      {  INT64_C( 2045254645663010519), -INT64_C( 2356451622031062525) },
      { -INT64_C( 1683308634378662434),  INT64_C( 1426644783803511503) },
      {  INT32_C(          1546325407),  INT32_C(            25514132),  INT32_C(            84272122), -INT32_C(           216487525) } },
    { { -INT32_C(          1877683093),  INT32_C(          1644070792) },
      {  INT64_C( 7916377094681146216),  INT64_C( 5937992222963267175) },
      { -INT64_C(  242985364762285855), -INT64_C( 1604448757119539491) },
      { -INT32_C(          1877683093),  INT32_C(          1644070792),  INT32_C(          1786600735),  INT32_C(          1008981714) } },
    { { -INT32_C(           208383898), -INT32_C(           341136280) },
      { -INT64_C( 8252129662742766661),  INT64_C( 1604094474450927037) },
      {  INT64_C( 4050857789190689228), -INT64_C( 1684910522907015914) },
      { -INT32_C(           208383898), -INT32_C(           341136280), -INT32_C(           978184835), -INT32_C(            18816453) } },
    { { -INT32_C(          1817703838),  INT32_C(          1140769713) },
      { -INT64_C( 1055906823835588567),  INT64_C( 1204751403051979576) },
      { -INT64_C(  290103604780850678),  INT64_C( 7712064513047616751) },
      { -INT32_C(          1817703838),  INT32_C(          1140769713), -INT32_C(           313392475),  INT32_C(          2076107989) } },
    { { -INT32_C(           486477035), -INT32_C(            23379121) },
      { -INT64_C( 1523463849335043181), -INT64_C( 5118519349782276590) },
      {  INT64_C( 2340765730881937810), -INT64_C( 5575603933151014689) },
      { -INT32_C(           486477035), -INT32_C(            23379121),  INT32_C(           190292923),  INT32_C(          1805047688) } },
    { { -INT32_C(          1828626319), -INT32_C(           574613224) },
      { -INT64_C(  451861104164026903),  INT64_C( 3418646987013530109) },
      {  INT64_C( 2607517827968759110), -INT64_C( 6646145769758301701) },
      { -INT32_C(          1828626319), -INT32_C(           574613224),  INT32_C(           501902942), -INT32_C(           751460619) } },
    { {  INT32_C(           284641515),  INT32_C(           291374305) },
      {  INT64_C( 1991838246836783916), -INT64_C( 3225070997924962494) },
      {  INT64_C(  989020284874251523), -INT64_C( 2365308517439811907) },
      {  INT32_C(           284641515),  INT32_C(           291374305),  INT32_C(           694035210), -INT32_C(          1301611661) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t origin_r = simde_vld1_s32(test_vec[i].origin_r);
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int32x4_t r = simde_vaddhn_high_s64(origin_r, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t origin_r = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t r = simde_vaddhn_high_s64(origin_r, a, b);

    simde_test_arm_neon_write_i32x2(2, origin_r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t origin_r[8];
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[16];
  } test_vec[] = {
    { {  UINT8_C(    235),  UINT8_C(    148),  UINT8_C(     52),  UINT8_C(    228),
         UINT8_C(    229),  UINT8_C(     76),  UINT8_C(     37),  UINT8_C(     43) },
      {  UINT16_C(  59991),  UINT16_C(  10679),  UINT16_C(  58806),  UINT16_C(  11644),
         UINT16_C(  59568),  UINT16_C(   4439),  UINT16_C(  62018),  UINT16_C(   6926) },
      {  UINT16_C(  32490),  UINT16_C(  54533),  UINT16_C(  28256),  UINT16_C(  61377),
         UINT16_C(  56063),  UINT16_C(  58874),  UINT16_C(  47058),  UINT16_C(  41345) },
      {  UINT8_C(    235),  UINT8_C(    148),  UINT8_C(     52),  UINT8_C(    228),
         UINT8_C(    229),  UINT8_C(     76),  UINT8_C(     37),  UINT8_C(     43),
         UINT8_C(    105),  UINT8_C(    254),  UINT8_C(     84),  UINT8_C(     29),
         UINT8_C(    195),  UINT8_C(    247),  UINT8_C(    170),  UINT8_C(    188) } },
    { {  UINT8_C(    154),  UINT8_C(     69),  UINT8_C(    254),  UINT8_C(    158),
         UINT8_C(    171),  UINT8_C(      8),  UINT8_C(     83),  UINT8_C(    247) },
      {  UINT16_C(  39091),  UINT16_C(     96),  UINT16_C(  16665),  UINT16_C(  61050),
         UINT16_C(  63106),  UINT16_C(   5836),  UINT16_C(  58088),  UINT16_C(  41694) },
      {  UINT16_C(  10893),  UINT16_C(  21538),  UINT16_C(   1339),  UINT16_C(  25269),
         UINT16_C(  29881),  UINT16_C(  25995),  UINT16_C(  57072),  UINT16_C(   1949) },
      {  UINT8_C(    154),  UINT8_C(     69),  UINT8_C(    254),  UINT8_C(    158),
         UINT8_C(    171),  UINT8_C(      8),  UINT8_C(     83),  UINT8_C(    247),
         UINT8_C(    195),  UINT8_C(     84),  UINT8_C(     70),  UINT8_C(     81),
         UINT8_C(    107),  UINT8_C(    124),  UINT8_C(    193),  UINT8_C(    170) } },
    { {  UINT8_C(    229),  UINT8_C(     66),  UINT8_C(    141),  UINT8_C(    174),
         UINT8_C(    106),  UINT8_C(    214),  UINT8_C(    238),  UINT8_C(    221) },
      {  UINT16_C(  14687),  UINT16_C(  16815),  UINT16_C(  25086),  UINT16_C(   7268),
         UINT16_C(  64446),  UINT16_C(  39053),  UINT16_C(   6226),  UINT16_C(  52078) },
      {  UINT16_C(  48646),  UINT16_C(  53755),  UINT16_C(  16387),  UINT16_C(    857),
         UINT16_C(  11253),  UINT16_C(  59544),  UINT16_C(  42058),  UINT16_C(  56009) },
      {  UINT8_C(    229),  UINT8_C(     66),  UINT8_C(    141),  UINT8_C(    174),
         UINT8_C(    106),  UINT8_C(    214),  UINT8_C(    238),  UINT8_C(    221),
         UINT8_C(    247),  UINT8_C(     19),  UINT8_C(    162),  UINT8_C(     31),
         UINT8_C(     39),  UINT8_C(    129),  UINT8_C(    188),  UINT8_C(    166) } },
    { {  UINT8_C(    145),  UINT8_C(    112),  UINT8_C(     93),  UINT8_C(    126),
         UINT8_C(    170),  UINT8_C(    107),  UINT8_C(    141),  UINT8_C(    241) },
      {  UINT16_C(  55228),  UINT16_C(  54638),  UINT16_C(   8684),  UINT16_C(  64081),
         UINT16_C(  24013),  UINT16_C(  61659),  UINT16_C(  37575),  UINT16_C(  55057) },
      {  UINT16_C(  16933),  UINT16_C(  18833),  UINT16_C(  16187),  UINT16_C(  23898),
         UINT16_C(  13390),  UINT16_C(   4974),  UINT16_C(  51021),  UINT16_C(  17832) },
      {  UINT8_C(    145),  UINT8_C(    112),  UINT8_C(     93),  UINT8_C(    126),
         UINT8_C(    170),  UINT8_C(    107),  UINT8_C(    141),  UINT8_C(    241),
         UINT8_C(     25),  UINT8_C(     30),  UINT8_C(     97),  UINT8_C(     87),
         UINT8_C(    146),  UINT8_C(      4),  UINT8_C(     90),  UINT8_C(     28) } },
    { {  UINT8_C(    220),  UINT8_C(     44),  UINT8_C(     37),  UINT8_C(     53),
         UINT8_C(    136),  UINT8_C(    114),  UINT8_C(     33),  UINT8_C(     93) },
      {  UINT16_C(  18411),  UINT16_C(  57288),  UINT16_C(  61228),  UINT16_C(  10173),
         UINT16_C(  18310),  UINT16_C(  59072),  UINT16_C(  43164),  UINT16_C(  56049) },
      {  UINT16_C(  40950),  UINT16_C(  60464),  UINT16_C(  61096),  UINT16_C(  61247),
         UINT16_C(  22991),  UINT16_C(  41963),  UINT16_C(  30287),  UINT16_C(  15373) },
      {  UINT8_C(    220),  UINT8_C(     44),  UINT8_C(     37),  UINT8_C(     53),
         UINT8_C(    136),  UINT8_C(    114),  UINT8_C(     33),  UINT8_C(     93),
         UINT8_C(    231),  UINT8_C(    203),  UINT8_C(    221),  UINT8_C(     22),
         UINT8_C(    161),  UINT8_C(    138),  UINT8_C(     30),  UINT8_C(     22) } },
    { {  UINT8_C(    101),  UINT8_C(    113),  UINT8_C(      9),  UINT8_C(    195),
         UINT8_C(    242),  UINT8_C(    223),  UINT8_C(    120),  UINT8_C(     29) },
      {  UINT16_C(  45990),  UINT16_C(  17262),  UINT16_C(  20427),  UINT16_C(   9484),
         UINT16_C(   6727),  UINT16_C(  63330),  UINT16_C(   1127),  UINT16_C(  21155) },
      {  UINT16_C(  35209),  UINT16_C(  55926),  UINT16_C(  60255),  UINT16_C(  36713),
         UINT16_C(  58877),  UINT16_C(   4044),  UINT16_C(  33835),  UINT16_C(  25741) },
      {  UINT8_C(    101),  UINT8_C(    113),  UINT8_C(      9),  UINT8_C(    195),
         UINT8_C(    242),  UINT8_C(    223),  UINT8_C(    120),  UINT8_C(     29),
         UINT8_C(     61),  UINT8_C(     29),  UINT8_C(     59),  UINT8_C(    180),
         UINT8_C(      0),  UINT8_C(      7),  UINT8_C(    136),  UINT8_C(    183) } },
    { {  UINT8_C(    251),  UINT8_C(    182),  UINT8_C(    137),  UINT8_C(    181),
         UINT8_C(    102),  UINT8_C(    216),  UINT8_C(     34),  UINT8_C(    214) },
      {  UINT16_C(  59002),  UINT16_C(  42857),  UINT16_C(  34543),  UINT16_C(  12998),
         UINT16_C(  17765),  UINT16_C(  18315),  UINT16_C(  55739),  UINT16_C(  54044) },
      {  UINT16_C(  50115),  UINT16_C(  53343),  UINT16_C(  37227),  UINT16_C(  38681),
         UINT16_C(  51396),  UINT16_C(  65434),  UINT16_C(  14319),  UINT16_C(  37063) },
      {  UINT8_C(    251),  UINT8_C(    182),  UINT8_C(    137),  UINT8_C(    181),
         UINT8_C(    102),  UINT8_C(    216),  UINT8_C(     34),  UINT8_C(    214),
         UINT8_C(    170),  UINT8_C(    119),  UINT8_C(     24),  UINT8_C(    201),
         UINT8_C(     14),  UINT8_C(     71),  UINT8_C(     17),  UINT8_C(     99) } },
    { {  UINT8_C(     59),  UINT8_C(    235),  UINT8_C(     41),  UINT8_C(    151),
         UINT8_C(    200),  UINT8_C(    100),  UINT8_C(     90),  UINT8_C(     81) },
      {  UINT16_C(    496),  UINT16_C(  28246),  UINT16_C(  17686),  UINT16_C(   6514),
         UINT16_C(   2532),  UINT16_C(  19169),  UINT16_C(  55181),  UINT16_C(  51073) },
      {  UINT16_C(  48042),  UINT16_C(  49131),  UINT16_C(  26293),  UINT16_C(  36384),
         UINT16_C(  32401),  UINT16_C(  16635),  UINT16_C(  62305),  UINT16_C(  48077) },
      {  UINT8_C(     59),  UINT8_C(    235),  UINT8_C(     41),  UINT8_C(    151),
         UINT8_C(    200),  UINT8_C(    100),  UINT8_C(     90),  UINT8_C(     81),
         UINT8_C(    189),  UINT8_C(     46),  UINT8_C(    171),  UINT8_C(    167),
         UINT8_C(    136),  UINT8_C(    139),  UINT8_C(    202),  UINT8_C(    131) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t origin_r = simde_vld1_u8(test_vec[i].origin_r);
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint8x16_t r = simde_vaddhn_high_u16(origin_r, a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t origin_r = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t r = simde_vaddhn_high_u16(origin_r, a, b);

    simde_test_arm_neon_write_u8x8(2, origin_r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t origin_r[4];
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[8];
  } test_vec[] = {
    { {  UINT16_C(       22402),  UINT16_C(       19447),  UINT16_C(       29079),  UINT16_C(       14209) },
      {  UINT32_C(  1929567810),  UINT32_C(  1266888035),  UINT32_C(  1849623859),  UINT32_C(  3726673809) },
      {  UINT32_C(  2519677390),  UINT32_C(  2059703146),  UINT32_C(  2573172414),  UINT32_C(  1595598271) },
      {  UINT16_C(       22402),  UINT16_C(       19447),  UINT16_C(       29079),  UINT16_C(       14209),
         UINT16_C(        2354),  UINT16_C(       50759),  UINT16_C(        1950),  UINT16_C(       15675) } },
    { {  UINT16_C(         618),  UINT16_C(       51138),  UINT16_C(       65366),  UINT16_C(       31419) },
      {  UINT32_C(  1868195489),  UINT32_C(  1420069982),  UINT32_C(  4044850792),  UINT32_C(  3232126363) },
      {  UINT32_C(   948569143),  UINT32_C(  2414434135),  UINT32_C(  3377393960),  UINT32_C(  3007343278) },
      {  UINT16_C(         618),  UINT16_C(       51138),  UINT16_C(       65366),  UINT16_C(       31419),
         UINT16_C(       42980),  UINT16_C(       58509),  UINT16_C(       47718),  UINT16_C(       29670) } },
    { {  UINT16_C(       29712),  UINT16_C(       62413),  UINT16_C(        3556),  UINT16_C(       12336) },
      {  UINT32_C(  3579194679),  UINT32_C(  3597667256),  UINT32_C(  3534168561),  UINT32_C(   586088586) },
      {  UINT32_C(  3730139011),  UINT32_C(  4072807016),  UINT32_C(  1665138045),  UINT32_C(  2345160034) },
      {  UINT16_C(       29712),  UINT16_C(       62413),  UINT16_C(        3556),  UINT16_C(       12336),
         UINT16_C(       45995),  UINT16_C(       51506),  UINT16_C(       13799),  UINT16_C(       44727) } },
    { {  UINT16_C(       47199),  UINT16_C(        8365),  UINT16_C(       17491),  UINT16_C(       36856) },
      {  UINT32_C(  3633156783),  UINT32_C(  4249061138),  UINT32_C(  2972923334),  UINT32_C(  2067160322) },
      {  UINT32_C(   924301717),  UINT32_C(  4091983461),  UINT32_C(  2873169028),  UINT32_C(  3375663598) },
      {  UINT16_C(       47199),  UINT16_C(        8365),  UINT16_C(       17491),  UINT16_C(       36856),
         UINT16_C(        4005),  UINT16_C(       61738),  UINT16_C(       23668),  UINT16_C(       17514) } },
    { {  UINT16_C(       49769),  UINT16_C(       33766),  UINT16_C(       57708),  UINT16_C(       57639) },
      {  UINT32_C(  2701853101),  UINT32_C(  1016519639),  UINT32_C(   360812144),  UINT32_C(    61524080) },
      {  UINT32_C(  3779201450),  UINT32_C(  3717588777),  UINT32_C(  3560643117),  UINT32_C(  1620040156) },
      {  UINT16_C(       49769),  UINT16_C(       33766),  UINT16_C(       57708),  UINT16_C(       57639),
         UINT16_C(       33357),  UINT16_C(        6700),  UINT16_C(       59836),  UINT16_C(       25658) } },
    { {  UINT16_C(       17387),  UINT16_C(       23001),  UINT16_C(       18935),  UINT16_C(       33412) },
      {  UINT32_C(  1640049796),  UINT32_C(   669756688),  UINT32_C(   966637419),  UINT32_C(   131869858) },
      {  UINT32_C(   857685405),  UINT32_C(  1691950446),  UINT32_C(   977461260),  UINT32_C(  1655627858) },
      {  UINT16_C(       17387),  UINT16_C(       23001),  UINT16_C(       18935),  UINT16_C(       33412),
         UINT16_C(       38112),  UINT16_C(       36036),  UINT16_C(       29664),  UINT16_C(       27275) } },
    { {  UINT16_C(       59350),  UINT16_C(       33131),  UINT16_C(       29709),  UINT16_C(       15264) },
      {  UINT32_C(   331712893),  UINT32_C(   307801489),  UINT32_C(  3795005980),  UINT32_C(  1037830267) },
      {  UINT32_C(  1418078308),  UINT32_C(  4288944375),  UINT32_C(  1176888264),  UINT32_C(  2500393476) },
      {  UINT16_C(       59350),  UINT16_C(       33131),  UINT16_C(       29709),  UINT16_C(       15264),
         UINT16_C(       26699),  UINT16_C(        4604),  UINT16_C(       10329),  UINT16_C(       53989) } },
    { {  UINT16_C(       42489),  UINT16_C(       62752),  UINT16_C(       12059),  UINT16_C(        6768) },
      {  UINT32_C(  3028104468),  UINT32_C(  3015341958),  UINT32_C(  1166329203),  UINT32_C(  2318732010) },
      {  UINT32_C(   968805234),  UINT32_C(  3483825356),  UINT32_C(  1767838217),  UINT32_C(  1323995871) },
      {  UINT16_C(       42489),  UINT16_C(       62752),  UINT16_C(       12059),  UINT16_C(        6768),
         UINT16_C(       60988),  UINT16_C(       33633),  UINT16_C(       44771),  UINT16_C(       55583) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t origin_r = simde_vld1_u16(test_vec[i].origin_r);
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint16x8_t r = simde_vaddhn_high_u32(origin_r, a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t origin_r = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t r = simde_vaddhn_high_u32(origin_r, a, b);

    simde_test_arm_neon_write_u16x4(2, origin_r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_high_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t origin_r[2];
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(          1614372443),  UINT32_C(          3760914029) },
      {  UINT64_C(14111524090166271938),  UINT64_C(11987192328408582711) },
      {  UINT64_C( 1979811475086130307),  UINT64_C( 5079953232012328519) },
      {  UINT32_C(          1614372443),  UINT32_C(          3760914029),  UINT32_C(          3746556016),  UINT32_C(          3973754486) } },
    { {  UINT32_C(          1671544856),  UINT32_C(           621225568) },
      {  UINT64_C( 2454814551482193407),  UINT64_C(15126065627233573393) },
      {  UINT64_C(13389663609935176150),  UINT64_C( 5067323661827478264) },
      {  UINT32_C(          1671544856),  UINT32_C(           621225568),  UINT32_C(          3689080048),  UINT32_C(           406672529) } },
    { {  UINT32_C(          4157953561),  UINT32_C(          3598934380) },
      {  UINT64_C(13862906695549580271),  UINT64_C( 1364886238029594751) },
      {  UINT64_C( 9277431902693012927),  UINT64_C( 5665327731565945524) },
      {  UINT32_C(          4157953561),  UINT32_C(          3598934380),  UINT32_C(          1092812634),  UINT32_C(          1636849243) } },
    { {  UINT32_C(           598455139),  UINT32_C(          1760953140) },
      {  UINT64_C(11137287007818636556),  UINT64_C(16646019750688770140) },
      {  UINT64_C(15703041268694317777),  UINT64_C( 9055302360228056339) },
      {  UINT32_C(           598455139),  UINT32_C(          1760953140),  UINT32_C(          1954283612),  UINT32_C(          1689088073) } },
    { {  UINT32_C(          4035395122),  UINT32_C(          1344874899) },
      {  UINT64_C(16349648078972151750),  UINT64_C(13793035675891121759) },
      {  UINT64_C(18200340564669114955),  UINT64_C(11322608606770847581) },
      {  UINT32_C(          4035395122),  UINT32_C(          1344874899),  UINT32_C(          3749328798),  UINT32_C(          1552724328) } },
    { {  UINT32_C(          3563821591),  UINT32_C(          2566264915) },
      {  UINT64_C(  517198210232281093),  UINT64_C(13450896300641508922) },
      {  UINT64_C(15869387284253798122),  UINT64_C( 8980549949703342540) },
      {  UINT32_C(          3563821591),  UINT32_C(          2566264915),  UINT32_C(          3815299247),  UINT32_C(           927760772) } },
    { {  UINT32_C(          3561202493),  UINT32_C(          1572226616) },
      {  UINT64_C( 2151790066031981522),  UINT64_C(14801720919763243321) },
      {  UINT64_C(14397953553210680038),  UINT64_C(10049855790183662030) },
      {  UINT32_C(          3561202493),  UINT32_C(          1572226616),  UINT32_C(          3853287459),  UINT32_C(          1491241305) } },
    { {  UINT32_C(          1863803273),  UINT32_C(          3450561043) },
      {  UINT64_C(10341098681536271081),  UINT64_C( 8356083269093513182) },
      {  UINT64_C( 6589842696213060292),  UINT64_C(12490602975102226734) },
      {  UINT32_C(          1863803273),  UINT32_C(          3450561043),  UINT32_C(          3942041978),  UINT32_C(           558780080) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t origin_r = simde_vld1_u32(test_vec[i].origin_r);
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint32x4_t r = simde_vaddhn_high_u64(origin_r, a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t origin_r = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t r = simde_vaddhn_high_u64(origin_r, a, b);

    simde_test_arm_neon_write_u32x2(2, origin_r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_high_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_high_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_high_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
