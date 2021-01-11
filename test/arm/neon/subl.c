#define SIMDE_TEST_ARM_NEON_INSN subl

#include "test-neon.h"
#include "../../../simde/arm/neon/subl.h"

static int
test_simde_vsubl_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT8_C(  73),  INT8_C(  90),  INT8_C(  68),  INT8_C(  85), -INT8_C(   7),  INT8_C(  13),  INT8_C(  88),  INT8_C(   3) },
      {  INT8_C(  50),  INT8_C(  45),  INT8_C(   6), -INT8_C(   8), -INT8_C(  12),  INT8_C( 115),  INT8_C(  13), -INT8_C(  98) },
      {  INT16_C(    23),  INT16_C(    45),  INT16_C(    62),  INT16_C(    93),  INT16_C(     5), -INT16_C(   102),  INT16_C(    75),  INT16_C(   101) } },
    { {  INT8_C( 105), -INT8_C(  61),  INT8_C( 109),  INT8_C(  79), -INT8_C(  55),  INT8_C( 109),  INT8_C( 100),  INT8_C(  54) },
      { -INT8_C(  24),  INT8_C(  73), -INT8_C(  65),  INT8_C(  38),  INT8_C(  60), -INT8_C(  21), -INT8_C(  75), -INT8_C( 123) },
      {  INT16_C(   129), -INT16_C(   134),  INT16_C(   174),  INT16_C(    41), -INT16_C(   115),  INT16_C(   130),  INT16_C(   175),  INT16_C(   177) } },
    { {  INT8_C(  69), -INT8_C(   6), -INT8_C(  38),  INT8_C(  62),  INT8_C(   7),  INT8_C(  50),  INT8_C(  65),  INT8_C(  58) },
      {  INT8_C(  96),  INT8_C(  71),  INT8_C(  50),  INT8_C(  84), -INT8_C(  70),  INT8_C(  63), -INT8_C(  14),  INT8_C(  36) },
      { -INT16_C(    27), -INT16_C(    77), -INT16_C(    88), -INT16_C(    22),  INT16_C(    77), -INT16_C(    13),  INT16_C(    79),  INT16_C(    22) } },
    { {  INT8_C(   2),  INT8_C(  95),  INT8_C( 115), -INT8_C(  53), -INT8_C(  51), -INT8_C(  41),  INT8_C(   2), -INT8_C(  75) },
      {  INT8_C(  32), -INT8_C(  63), -INT8_C(  37),  INT8_C(  92), -INT8_C(  84), -INT8_C( 111), -INT8_C(  31), -INT8_C(  15) },
      { -INT16_C(    30),  INT16_C(   158),  INT16_C(   152), -INT16_C(   145),  INT16_C(    33),  INT16_C(    70),  INT16_C(    33), -INT16_C(    60) } },
    { { -INT8_C( 117), -INT8_C(  68),  INT8_C(  47), -INT8_C( 110), -INT8_C(  18),  INT8_C( 112), -INT8_C(  52),  INT8_C(  78) },
      { -INT8_C(  73), -INT8_C(   2), -INT8_C(  94),  INT8_C( 113),  INT8_C(  61), -INT8_C( 107), -INT8_C( 107),  INT8_C(  63) },
      { -INT16_C(    44), -INT16_C(    66),  INT16_C(   141), -INT16_C(   223), -INT16_C(    79),  INT16_C(   219),  INT16_C(    55),  INT16_C(    15) } },
    { { -INT8_C(  12),  INT8_C(   8),  INT8_C(  11), -INT8_C(  63), -INT8_C(  33),  INT8_C(  13),  INT8_C( 118), -INT8_C(   1) },
      { -INT8_C(  50),  INT8_C(  82),  INT8_C(  91),  INT8_C( 122), -INT8_C(  29),  INT8_C(  61),  INT8_C( 107),  INT8_C( 110) },
      {  INT16_C(    38), -INT16_C(    74), -INT16_C(    80), -INT16_C(   185), -INT16_C(     4), -INT16_C(    48),  INT16_C(    11), -INT16_C(   111) } },
    { { -INT8_C(   7), -INT8_C( 102),  INT8_C(   0), -INT8_C(  25),  INT8_C(  10), -INT8_C(  51),  INT8_C(  54), -INT8_C(  63) },
      { -INT8_C(  53), -INT8_C(  40),  INT8_C(  50),  INT8_C(   9),  INT8_C( 109), -INT8_C(  56),  INT8_C(  72),  INT8_C(  98) },
      {  INT16_C(    46), -INT16_C(    62), -INT16_C(    50), -INT16_C(    34), -INT16_C(    99),  INT16_C(     5), -INT16_C(    18), -INT16_C(   161) } },
    { { -INT8_C(  48),  INT8_C(  83),  INT8_C(  35), -INT8_C(  80),  INT8_C(  96), -INT8_C( 102), -INT8_C(  81),  INT8_C(  46) },
      { -INT8_C(  20),  INT8_C(  11), -INT8_C(  88), -INT8_C(  49),  INT8_C(  72),  INT8_C(  19),  INT8_C(  61),  INT8_C(  65) },
      { -INT16_C(    28),  INT16_C(    72),  INT16_C(   123), -INT16_C(    31),  INT16_C(    24), -INT16_C(   121), -INT16_C(   142), -INT16_C(    19) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vsubl_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t r = simde_vsubl_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT16_C(  9069),  INT16_C( 13208),  INT16_C(  2333),  INT16_C(   207) },
      {  INT16_C( 11583), -INT16_C( 25535), -INT16_C(  7178), -INT16_C( 12996) },
      { -INT32_C(       20652),  INT32_C(       38743),  INT32_C(        9511),  INT32_C(       13203) } },
    { {  INT16_C( 18526), -INT16_C( 21718),  INT16_C( 19358), -INT16_C( 20790) },
      {  INT16_C( 23289), -INT16_C( 25899), -INT16_C(  6854), -INT16_C( 12968) },
      { -INT32_C(        4763),  INT32_C(        4181),  INT32_C(       26212), -INT32_C(        7822) } },
    { { -INT16_C(  3647), -INT16_C(  8703), -INT16_C( 12038),  INT16_C( 14815) },
      {  INT16_C(  8445), -INT16_C(  2859),  INT16_C(  4611),  INT16_C( 25025) },
      { -INT32_C(       12092), -INT32_C(        5844), -INT32_C(       16649), -INT32_C(       10210) } },
    { { -INT16_C(  5286), -INT16_C(  2035), -INT16_C( 10442),  INT16_C( 12198) },
      {  INT16_C( 31537),  INT16_C( 27593),  INT16_C(  8545),  INT16_C(  8761) },
      { -INT32_C(       36823), -INT32_C(       29628), -INT32_C(       18987),  INT32_C(        3437) } },
    { {  INT16_C( 14866),  INT16_C(  3329), -INT16_C(  8182),  INT16_C(  2118) },
      {  INT16_C(  7168),  INT16_C(  1276), -INT16_C( 17106), -INT16_C( 30619) },
      {  INT32_C(        7698),  INT32_C(        2053),  INT32_C(        8924),  INT32_C(       32737) } },
    { {  INT16_C( 29352), -INT16_C(  8575),  INT16_C( 10057),  INT16_C( 31245) },
      { -INT16_C( 10589),  INT16_C(  1254),  INT16_C(  8183),  INT16_C(  2598) },
      {  INT32_C(       39941), -INT32_C(        9829),  INT32_C(        1874),  INT32_C(       28647) } },
    { {  INT16_C( 10073),  INT16_C( 25367),  INT16_C( 23815),  INT16_C(  2155) },
      {  INT16_C( 26489), -INT16_C( 22772),  INT16_C( 28964), -INT16_C( 13264) },
      { -INT32_C(       16416),  INT32_C(       48139), -INT32_C(        5149),  INT32_C(       15419) } },
    { { -INT16_C( 19996),  INT16_C( 11690), -INT16_C( 18472),  INT16_C( 31656) },
      { -INT16_C( 29043), -INT16_C( 31361), -INT16_C( 22867),  INT16_C(  1679) },
      {  INT32_C(        9047),  INT32_C(       43051),  INT32_C(        4395),  INT32_C(       29977) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vsubl_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t r = simde_vsubl_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1313200066),  INT32_C(   576591193) },
      {  INT32_C(  2041640284),  INT32_C(  1738130097) },
      { -INT64_C(          3354840350), -INT64_C(          1161538904) } },
    { {  INT32_C(   120563334), -INT32_C(   648305082) },
      { -INT32_C(   104614879), -INT32_C(   998726778) },
      {  INT64_C(           225178213),  INT64_C(           350421696) } },
    { {  INT32_C(   611660747), -INT32_C(  1538862008) },
      {  INT32_C(  2048849609),  INT32_C(  1071757241) },
      { -INT64_C(          1437188862), -INT64_C(          2610619249) } },
    { { -INT32_C(  1538911906), -INT32_C(   662854985) },
      { -INT32_C(   590266282), -INT32_C(  1348449564) },
      { -INT64_C(           948645624),  INT64_C(           685594579) } },
    { { -INT32_C(   975956611), -INT32_C(  1301669143) },
      { -INT32_C(   902985711), -INT32_C(  1660350913) },
      { -INT64_C(            72970900),  INT64_C(           358681770) } },
    { { -INT32_C(   683585761),  INT32_C(  1202700017) },
      { -INT32_C(   484212225),  INT32_C(  1217577931) },
      { -INT64_C(           199373536), -INT64_C(            14877914) } },
    { { -INT32_C(  1039309095), -INT32_C(  1837795455) },
      {  INT32_C(  1063035647), -INT32_C(   790862416) },
      { -INT64_C(          2102344742), -INT64_C(          1046933039) } },
    { { -INT32_C(  1498997068), -INT32_C(   605202724) },
      { -INT32_C(  1564601897), -INT32_C(  1377152556) },
      {  INT64_C(            65604829),  INT64_C(           771949832) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vsubl_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t r = simde_vsubl_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C(183), UINT8_C(248), UINT8_C(112), UINT8_C( 56), UINT8_C(111), UINT8_C(229), UINT8_C(202), UINT8_C(111) },
      { UINT8_C(135), UINT8_C( 38), UINT8_C(174), UINT8_C( 55), UINT8_C(139), UINT8_C(138), UINT8_C(  7), UINT8_C( 64) },
      { UINT16_C(   48), UINT16_C(  210), UINT16_C(65474), UINT16_C(    1), UINT16_C(65508), UINT16_C(   91), UINT16_C(  195), UINT16_C(   47) } },
    { { UINT8_C(168), UINT8_C(174), UINT8_C(230), UINT8_C(133), UINT8_C(  5), UINT8_C(211), UINT8_C( 96), UINT8_C(220) },
      { UINT8_C(228), UINT8_C( 31), UINT8_C(127), UINT8_C(185), UINT8_C(112), UINT8_C(105), UINT8_C(102), UINT8_C( 39) },
      { UINT16_C(65476), UINT16_C(  143), UINT16_C(  103), UINT16_C(65484), UINT16_C(65429), UINT16_C(  106), UINT16_C(65530), UINT16_C(  181) } },
    { { UINT8_C( 97), UINT8_C(214), UINT8_C( 96), UINT8_C(209), UINT8_C(187), UINT8_C( 42), UINT8_C( 64), UINT8_C( 66) },
      { UINT8_C( 81), UINT8_C(238), UINT8_C(122), UINT8_C(220), UINT8_C(120), UINT8_C(129), UINT8_C( 28), UINT8_C( 33) },
      { UINT16_C(   16), UINT16_C(65512), UINT16_C(65510), UINT16_C(65525), UINT16_C(   67), UINT16_C(65449), UINT16_C(   36), UINT16_C(   33) } },
    { { UINT8_C( 48), UINT8_C(  2), UINT8_C(166), UINT8_C( 53), UINT8_C(214), UINT8_C(  6), UINT8_C( 17), UINT8_C(186) },
      { UINT8_C( 37), UINT8_C(144), UINT8_C(115), UINT8_C(149), UINT8_C(250), UINT8_C(218), UINT8_C(189), UINT8_C( 91) },
      { UINT16_C(   11), UINT16_C(65394), UINT16_C(   51), UINT16_C(65440), UINT16_C(65500), UINT16_C(65324), UINT16_C(65364), UINT16_C(   95) } },
    { { UINT8_C(176), UINT8_C( 29), UINT8_C( 44), UINT8_C(108), UINT8_C( 71), UINT8_C(108), UINT8_C(174), UINT8_C(152) },
      { UINT8_C( 90), UINT8_C( 40), UINT8_C(117), UINT8_C(211), UINT8_C(170), UINT8_C(145), UINT8_C(244), UINT8_C(218) },
      { UINT16_C(   86), UINT16_C(65525), UINT16_C(65463), UINT16_C(65433), UINT16_C(65437), UINT16_C(65499), UINT16_C(65466), UINT16_C(65470) } },
    { { UINT8_C(148), UINT8_C(154), UINT8_C( 15), UINT8_C(106), UINT8_C(160), UINT8_C( 32), UINT8_C( 36), UINT8_C(198) },
      { UINT8_C(177), UINT8_C(152), UINT8_C( 91), UINT8_C(171), UINT8_C(114), UINT8_C( 24), UINT8_C(  6), UINT8_C( 34) },
      { UINT16_C(65507), UINT16_C(    2), UINT16_C(65460), UINT16_C(65471), UINT16_C(   46), UINT16_C(    8), UINT16_C(   30), UINT16_C(  164) } },
    { { UINT8_C( 53), UINT8_C( 51), UINT8_C(142), UINT8_C(125), UINT8_C(159), UINT8_C( 61), UINT8_C( 21), UINT8_C(250) },
      { UINT8_C(101), UINT8_C(138), UINT8_C(205), UINT8_C( 15), UINT8_C( 28), UINT8_C(193), UINT8_C(233), UINT8_C(176) },
      { UINT16_C(65488), UINT16_C(65449), UINT16_C(65473), UINT16_C(  110), UINT16_C(  131), UINT16_C(65404), UINT16_C(65324), UINT16_C(   74) } },
    { { UINT8_C( 91), UINT8_C(248), UINT8_C( 26), UINT8_C(251), UINT8_C( 25), UINT8_C( 62), UINT8_C(193), UINT8_C(202) },
      { UINT8_C(214), UINT8_C( 29), UINT8_C(117), UINT8_C( 72), UINT8_C( 53), UINT8_C(123), UINT8_C(107), UINT8_C(107) },
      { UINT16_C(65413), UINT16_C(  219), UINT16_C(65445), UINT16_C(  179), UINT16_C(65508), UINT16_C(65475), UINT16_C(   86), UINT16_C(   95) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vsubl_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t r = simde_vsubl_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(63918), UINT16_C(20200), UINT16_C(64822), UINT16_C(40008) },
      { UINT16_C( 5512), UINT16_C(42155), UINT16_C(38358), UINT16_C(12628) },
      { UINT32_C(     58406), UINT32_C(4294945341), UINT32_C(     26464), UINT32_C(     27380) } },
    { { UINT16_C(28301), UINT16_C(42540), UINT16_C(61100), UINT16_C(33648) },
      { UINT16_C(58635), UINT16_C(16587), UINT16_C(13921), UINT16_C( 4011) },
      { UINT32_C(4294936962), UINT32_C(     25953), UINT32_C(     47179), UINT32_C(     29637) } },
    { { UINT16_C(37680), UINT16_C(26205), UINT16_C(42385), UINT16_C( 6402) },
      { UINT16_C(44730), UINT16_C(37053), UINT16_C( 4419), UINT16_C(53441) },
      { UINT32_C(4294960246), UINT32_C(4294956448), UINT32_C(     37966), UINT32_C(4294920257) } },
    { { UINT16_C(61055), UINT16_C(11127), UINT16_C(59356), UINT16_C(59310) },
      { UINT16_C(31437), UINT16_C(11815), UINT16_C(54192), UINT16_C(57405) },
      { UINT32_C(     29618), UINT32_C(4294966608), UINT32_C(      5164), UINT32_C(      1905) } },
    { { UINT16_C(39782), UINT16_C(63303), UINT16_C(18752), UINT16_C(64272) },
      { UINT16_C(52727), UINT16_C(14987), UINT16_C(19934), UINT16_C(23819) },
      { UINT32_C(4294954351), UINT32_C(     48316), UINT32_C(4294966114), UINT32_C(     40453) } },
    { { UINT16_C(33339), UINT16_C( 6025), UINT16_C(14185), UINT16_C(14078) },
      { UINT16_C( 9649), UINT16_C(25188), UINT16_C(41720), UINT16_C(24386) },
      { UINT32_C(     23690), UINT32_C(4294948133), UINT32_C(4294939761), UINT32_C(4294956988) } },
    { { UINT16_C(35133), UINT16_C(32086), UINT16_C(26579), UINT16_C(51832) },
      { UINT16_C( 1076), UINT16_C( 4869), UINT16_C( 4177), UINT16_C(35952) },
      { UINT32_C(     34057), UINT32_C(     27217), UINT32_C(     22402), UINT32_C(     15880) } },
    { { UINT16_C(63890), UINT16_C(64419), UINT16_C(41265), UINT16_C(57906) },
      { UINT16_C(38598), UINT16_C(48964), UINT16_C(34616), UINT16_C(29982) },
      { UINT32_C(     25292), UINT32_C(     15455), UINT32_C(      6649), UINT32_C(     27924) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vsubl_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t r = simde_vsubl_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubl_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(3824382992), UINT32_C( 279866331) },
      { UINT32_C(3223565167), UINT32_C(1431081923) },
      { UINT64_C(           600817825), UINT64_C(18446744072558336024) } },
    { { UINT32_C(3192975245), UINT32_C(1470136976) },
      { UINT32_C(1360454937), UINT32_C(2093429868) },
      { UINT64_C(          1832520308), UINT64_C(18446744073086258724) } },
    { { UINT32_C(2220931752), UINT32_C(2509508133) },
      { UINT32_C(2220210113), UINT32_C(3621364298) },
      { UINT64_C(              721639), UINT64_C(18446744072597695451) } },
    { { UINT32_C( 580200849), UINT32_C(3313055404) },
      { UINT32_C(2266402587), UINT32_C(1795415491) },
      { UINT64_C(18446744072023349878), UINT64_C(          1517639913) } },
    { { UINT32_C(3186582423), UINT32_C( 844268401) },
      { UINT32_C(2243340090), UINT32_C(3680276297) },
      { UINT64_C(           943242333), UINT64_C(18446744070873543720) } },
    { { UINT32_C(1711141561), UINT32_C(1126856232) },
      { UINT32_C(3368697861), UINT32_C(3040070942) },
      { UINT64_C(18446744072051995316), UINT64_C(18446744071796336906) } },
    { { UINT32_C(2725389105), UINT32_C(3788883110) },
      { UINT32_C(3043396460), UINT32_C(3566256667) },
      { UINT64_C(18446744073391544261), UINT64_C(           222626443) } },
    { { UINT32_C(3694759348), UINT32_C( 136274691) },
      { UINT32_C(3251693987), UINT32_C(3900114103) },
      { UINT64_C(           443065361), UINT64_C(18446744069945712204) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vsubl_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t r = simde_vsubl_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubl_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
