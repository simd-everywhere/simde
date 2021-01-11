#define SIMDE_TEST_ARM_NEON_INSN paddl

#include "test-neon.h"
#include <simde/arm/neon/paddl.h>

static int
test_simde_vpaddl_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int16_t r[4];
  } test_vec[] = {
    { {  INT8_C(  37),  INT8_C(  75), -INT8_C(  87), -INT8_C(  55), -INT8_C(  42),  INT8_C( 118),  INT8_C(  42),  INT8_C(  29) },
      {  INT16_C(   112), -INT16_C(   142),  INT16_C(    76),  INT16_C(    71) } },
    { { -INT8_C( 107),  INT8_C( 110),  INT8_C(  20),  INT8_C(   7),  INT8_C(  86), -INT8_C(  94), -INT8_C( 118), -INT8_C(  25) },
      {  INT16_C(     3),  INT16_C(    27), -INT16_C(     8), -INT16_C(   143) } },
    { {  INT8_C(  39), -INT8_C(  93), -INT8_C(  18),  INT8_C(  40),  INT8_C(  38),  INT8_C(  46),  INT8_C(  10),  INT8_C(  77) },
      { -INT16_C(    54),  INT16_C(    22),  INT16_C(    84),  INT16_C(    87) } },
    { {  INT8_C(  36), -INT8_C(  29), -INT8_C(   5),  INT8_C(  78), -INT8_C( 115), -INT8_C(  27), -INT8_C(  88), -INT8_C(  78) },
      {  INT16_C(     7),  INT16_C(    73), -INT16_C(   142), -INT16_C(   166) } },
    { {  INT8_C(  48),  INT8_C(  82),  INT8_C( 123),  INT8_C(   7), -INT8_C(  56), -INT8_C(  90),  INT8_C(  36),  INT8_C(  93) },
      {  INT16_C(   130),  INT16_C(   130), -INT16_C(   146),  INT16_C(   129) } },
    { {  INT8_C(  20),  INT8_C(  57),  INT8_C( 100),  INT8_C( 106), -INT8_C(  37), -INT8_C(  17),  INT8_C(  81),  INT8_C(   2) },
      {  INT16_C(    77),  INT16_C(   206), -INT16_C(    54),  INT16_C(    83) } },
    { { -INT8_C( 110),  INT8_C(  63),  INT8_C(  43), -INT8_C(  71),  INT8_C( 110),  INT8_C(  53),  INT8_C(   6), -INT8_C( 110) },
      { -INT16_C(    47), -INT16_C(    28),  INT16_C(   163), -INT16_C(   104) } },
    { {  INT8_C(  25),  INT8_C(   1), -INT8_C(  32), -INT8_C(  90), -INT8_C(  26), -INT8_C( 119),  INT8_C(  89),  INT8_C(  23) },
      {  INT16_C(    26), -INT16_C(   122), -INT16_C(   145),  INT16_C(   112) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int16x4_t r = simde_vpaddl_s8(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddl_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int32_t r[2];
  } test_vec[] = {
    { { -INT16_C( 28169),  INT16_C( 12604),  INT16_C( 18912),  INT16_C( 16948) },
      { -INT32_C(       15565),  INT32_C(       35860) } },
    { { -INT16_C( 23339),  INT16_C(  4117), -INT16_C(  5015),  INT16_C( 18679) },
      { -INT32_C(       19222),  INT32_C(       13664) } },
    { { -INT16_C( 21626),  INT16_C( 28835), -INT16_C(  8629), -INT16_C( 31563) },
      {  INT32_C(        7209), -INT32_C(       40192) } },
    { { -INT16_C( 13057), -INT16_C( 10221), -INT16_C(  5231), -INT16_C( 30631) },
      { -INT32_C(       23278), -INT32_C(       35862) } },
    { { -INT16_C( 27011),  INT16_C( 23994), -INT16_C(  4385), -INT16_C( 19297) },
      { -INT32_C(        3017), -INT32_C(       23682) } },
    { { -INT16_C( 19054), -INT16_C(   828), -INT16_C( 17247),  INT16_C( 10052) },
      { -INT32_C(       19882), -INT32_C(        7195) } },
    { { -INT16_C(  6297), -INT16_C( 19560),  INT16_C( 19909), -INT16_C( 15305) },
      { -INT32_C(       25857),  INT32_C(        4604) } },
    { {  INT16_C( 18970), -INT16_C( 21604), -INT16_C(  2506), -INT16_C( 19660) },
      { -INT32_C(        2634), -INT32_C(       22166) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int32x2_t r = simde_vpaddl_s16(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddl_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int64_t r[1];
  } test_vec[] = {
    { { -INT32_C(  1059767371), -INT32_C(     8047219) },
      { -INT64_C(          1067814590) } },
    { {  INT32_C(   656763255), -INT32_C(   226202987) },
      {  INT64_C(           430560268) } },
    { { -INT32_C(  2065914833),  INT32_C(   230074665) },
      { -INT64_C(          1835840168) } },
    { { -INT32_C(  2040001686), -INT32_C(   611631322) },
      { -INT64_C(          2651633008) } },
    { {  INT32_C(   127623290),  INT32_C(   218505621) },
      {  INT64_C(           346128911) } },
    { {  INT32_C(   523512714), -INT32_C(   988694379) },
      { -INT64_C(           465181665) } },
    { { -INT32_C(  2058752676),  INT32_C(     9699222) },
      { -INT64_C(          2049053454) } },
    { {  INT32_C(   814152458), -INT32_C(  1274343110) },
      { -INT64_C(           460190652) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int64x1_t r = simde_vpaddl_s32(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddl_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT8_C( 70), UINT8_C(221), UINT8_C(124), UINT8_C(147), UINT8_C(112), UINT8_C(157), UINT8_C(115), UINT8_C( 88) },
      { UINT16_C(  291), UINT16_C(  271), UINT16_C(  269), UINT16_C(  203) } },
    { { UINT8_C(174), UINT8_C( 77), UINT8_C(253), UINT8_C(160), UINT8_C(176), UINT8_C(227), UINT8_C(112), UINT8_C(129) },
      { UINT16_C(  251), UINT16_C(  413), UINT16_C(  403), UINT16_C(  241) } },
    { { UINT8_C(169), UINT8_C(158), UINT8_C(189), UINT8_C(216), UINT8_C(189), UINT8_C( 90), UINT8_C(193), UINT8_C(141) },
      { UINT16_C(  327), UINT16_C(  405), UINT16_C(  279), UINT16_C(  334) } },
    { { UINT8_C( 21), UINT8_C(153), UINT8_C(  3), UINT8_C( 46), UINT8_C( 35), UINT8_C(  5), UINT8_C(  6), UINT8_C(106) },
      { UINT16_C(  174), UINT16_C(   49), UINT16_C(   40), UINT16_C(  112) } },
    { { UINT8_C(227), UINT8_C(130), UINT8_C(253), UINT8_C( 83), UINT8_C( 32), UINT8_C(112), UINT8_C(172), UINT8_C(206) },
      { UINT16_C(  357), UINT16_C(  336), UINT16_C(  144), UINT16_C(  378) } },
    { { UINT8_C(189), UINT8_C(169), UINT8_C(111), UINT8_C(109), UINT8_C(141), UINT8_C(223), UINT8_C(239), UINT8_C( 54) },
      { UINT16_C(  358), UINT16_C(  220), UINT16_C(  364), UINT16_C(  293) } },
    { { UINT8_C(125), UINT8_C(172), UINT8_C( 14), UINT8_C( 59), UINT8_C(  6), UINT8_C(207), UINT8_C(200), UINT8_C( 27) },
      { UINT16_C(  297), UINT16_C(   73), UINT16_C(  213), UINT16_C(  227) } },
    { { UINT8_C(104), UINT8_C(203), UINT8_C( 73), UINT8_C(140), UINT8_C(209), UINT8_C( 80), UINT8_C(246), UINT8_C(180) },
      { UINT16_C(  307), UINT16_C(  213), UINT16_C(  289), UINT16_C(  426) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint16x4_t r = simde_vpaddl_u8(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddl_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT16_C(44535), UINT16_C(20080), UINT16_C( 7327), UINT16_C(  723) },
      { UINT32_C(     64615), UINT32_C(      8050) } },
    { { UINT16_C(26434), UINT16_C(28458), UINT16_C(59172), UINT16_C( 7820) },
      { UINT32_C(     54892), UINT32_C(     66992) } },
    { { UINT16_C(24764), UINT16_C(43747), UINT16_C(19848), UINT16_C(37555) },
      { UINT32_C(     68511), UINT32_C(     57403) } },
    { { UINT16_C(24368), UINT16_C(46049), UINT16_C( 4980), UINT16_C(27626) },
      { UINT32_C(     70417), UINT32_C(     32606) } },
    { { UINT16_C(23233), UINT16_C(24762), UINT16_C(36215), UINT16_C(47458) },
      { UINT32_C(     47995), UINT32_C(     83673) } },
    { { UINT16_C(36340), UINT16_C( 6184), UINT16_C(46196), UINT16_C(12342) },
      { UINT32_C(     42524), UINT32_C(     58538) } },
    { { UINT16_C( 6421), UINT16_C(40411), UINT16_C(36455), UINT16_C(38703) },
      { UINT32_C(     46832), UINT32_C(     75158) } },
    { { UINT16_C( 4333), UINT16_C(24906), UINT16_C(13348), UINT16_C(58828) },
      { UINT32_C(     29239), UINT32_C(     72176) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint32x2_t r = simde_vpaddl_u16(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddl_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT32_C(3644053684), UINT32_C(4206572357) },
      { UINT64_C(          7850626041) } },
    { { UINT32_C( 281834052), UINT32_C(1790485039) },
      { UINT64_C(          2072319091) } },
    { { UINT32_C( 645429519), UINT32_C(1131238590) },
      { UINT64_C(          1776668109) } },
    { { UINT32_C(2329321534), UINT32_C( 551106155) },
      { UINT64_C(          2880427689) } },
    { { UINT32_C(1425607950), UINT32_C(2236527936) },
      { UINT64_C(          3662135886) } },
    { { UINT32_C(1452612135), UINT32_C(3435155132) },
      { UINT64_C(          4887767267) } },
    { { UINT32_C(2247243975), UINT32_C(3418906509) },
      { UINT64_C(          5666150484) } },
    { { UINT32_C(1800838656), UINT32_C(3817549780) },
      { UINT64_C(          5618388436) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint64x1_t r = simde_vpaddl_u32(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddlq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int16_t r[8];
  } test_vec[] = {
    { { -INT8_C(  28),  INT8_C(  34), -INT8_C( 114),  INT8_C( 121), -INT8_C(  18), -INT8_C( 116),  INT8_C(   4),  INT8_C( 105),
         INT8_C(  15),  INT8_C(   2), -INT8_C(  99),  INT8_C(  37),  INT8_C(  35),  INT8_C(  11),  INT8_C( 104), -INT8_C(  83) },
      {  INT16_C(     6),  INT16_C(     7), -INT16_C(   134),  INT16_C(   109),  INT16_C(    17), -INT16_C(    62),  INT16_C(    46),  INT16_C(    21) } },
    { { -INT8_C(   4), -INT8_C(  12),  INT8_C(  98), -INT8_C(  51), -INT8_C(  63),  INT8_C(  25), -INT8_C(  83),  INT8_C(  12),
        -INT8_C(  79),  INT8_C(  69), -INT8_C( 116), -INT8_C(   7), -INT8_C(  32),  INT8_C( 114),  INT8_C(  30), -INT8_C(  60) },
      { -INT16_C(    16),  INT16_C(    47), -INT16_C(    38), -INT16_C(    71), -INT16_C(    10), -INT16_C(   123),  INT16_C(    82), -INT16_C(    30) } },
    { { -INT8_C( 108), -INT8_C(  83),  INT8_C(  62), -INT8_C( 125),  INT8_C(  57),  INT8_C(  66), -INT8_C(  20),  INT8_C(  72),
         INT8_C(  68), -INT8_C( 119),  INT8_C( 110),  INT8_C( 103), -INT8_C( 108), -INT8_C(  42),  INT8_C(  21), -INT8_C( 112) },
      { -INT16_C(   191), -INT16_C(    63),  INT16_C(   123),  INT16_C(    52), -INT16_C(    51),  INT16_C(   213), -INT16_C(   150), -INT16_C(    91) } },
    { { -INT8_C(  53),  INT8_C( 119),  INT8_C(  93), -INT8_C( 116), -INT8_C( 112),  INT8_C(  10), -INT8_C( 103),  INT8_C(  65),
         INT8_C(  80),  INT8_C(  37),  INT8_C(  59),  INT8_C(  48), -INT8_C( 105),  INT8_C(  89), -INT8_C(  12),  INT8_C(  43) },
      {  INT16_C(    66), -INT16_C(    23), -INT16_C(   102), -INT16_C(    38),  INT16_C(   117),  INT16_C(   107), -INT16_C(    16),  INT16_C(    31) } },
    { {  INT8_C(   6),  INT8_C(  50), -INT8_C(  82),  INT8_C(  64),  INT8_C( 116), -INT8_C( 102), -INT8_C( 120), -INT8_C(  72),
         INT8_C(  35), -INT8_C(  10),  INT8_C(  32), -INT8_C(  73), -INT8_C(  51),  INT8_C(  53),  INT8_C(  71), -INT8_C( 104) },
      {  INT16_C(    56), -INT16_C(    18),  INT16_C(    14), -INT16_C(   192),  INT16_C(    25), -INT16_C(    41),  INT16_C(     2), -INT16_C(    33) } },
    { { -INT8_C(  84), -INT8_C(  92),  INT8_C(  36),  INT8_C(  60), -INT8_C(  81), -INT8_C(  67),  INT8_C( 126), -INT8_C(   1),
        -INT8_C(  30), -INT8_C(  71),  INT8_C(  47),  INT8_C( 121),  INT8_C(  18),  INT8_C(  35), -INT8_C(  91),  INT8_C(  25) },
      { -INT16_C(   176),  INT16_C(    96), -INT16_C(   148),  INT16_C(   125), -INT16_C(   101),  INT16_C(   168),  INT16_C(    53), -INT16_C(    66) } },
    { {  INT8_C(  86),  INT8_C(  83),  INT8_C(  89), -INT8_C(  54), -INT8_C(  18), -INT8_C(  31), -INT8_C( 125),  INT8_C(  17),
        -INT8_C(  40), -INT8_C(  93), -INT8_C(  55), -INT8_C(  91), -INT8_C(  40),  INT8_C(  16),  INT8_C(  61), -INT8_C( 124) },
      {  INT16_C(   169),  INT16_C(    35), -INT16_C(    49), -INT16_C(   108), -INT16_C(   133), -INT16_C(   146), -INT16_C(    24), -INT16_C(    63) } },
    { { -INT8_C(  75),  INT8_C(  97), -INT8_C(  64),  INT8_C( 100),  INT8_C(  31),  INT8_C(  62),  INT8_C(  99),  INT8_C(   1),
        -INT8_C(   9), -INT8_C( 110),  INT8_C( 123),  INT8_C(  10), -INT8_C(  75),  INT8_C(  32),  INT8_C(  35),  INT8_C(  11) },
      {  INT16_C(    22),  INT16_C(    36),  INT16_C(    93),  INT16_C(   100), -INT16_C(   119),  INT16_C(   133), -INT16_C(    43),  INT16_C(    46) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int16x8_t r = simde_vpaddlq_s8(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddlq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int32_t r[4];
  } test_vec[] = {
    { { -INT16_C( 31604), -INT16_C( 11562),  INT16_C( 27564), -INT16_C( 22459), -INT16_C( 21679), -INT16_C(  5440),  INT16_C(  8433),  INT16_C( 11191) },
      { -INT32_C(       43166),  INT32_C(        5105), -INT32_C(       27119),  INT32_C(       19624) } },
    { { -INT16_C( 22772), -INT16_C( 17814),  INT16_C( 14348),  INT16_C(  5693), -INT16_C( 20501),  INT16_C( 16667),  INT16_C(  4751),  INT16_C(  6915) },
      { -INT32_C(       40586),  INT32_C(       20041), -INT32_C(        3834),  INT32_C(       11666) } },
    { { -INT16_C(  9578),  INT16_C( 17133),  INT16_C( 12869), -INT16_C( 26901), -INT16_C( 21539), -INT16_C( 12672),  INT16_C( 14283), -INT16_C(  9991) },
      {  INT32_C(        7555), -INT32_C(       14032), -INT32_C(       34211),  INT32_C(        4292) } },
    { {  INT16_C( 25822), -INT16_C(  5230), -INT16_C( 12388), -INT16_C( 30975),  INT16_C(  7294),  INT16_C(  3529), -INT16_C( 13266), -INT16_C( 15320) },
      {  INT32_C(       20592), -INT32_C(       43363),  INT32_C(       10823), -INT32_C(       28586) } },
    { {  INT16_C(  5798), -INT16_C(  5369), -INT16_C(  3512),  INT16_C(  9857),  INT16_C(   669),  INT16_C( 27124), -INT16_C(  4551),  INT16_C(  6209) },
      {  INT32_C(         429),  INT32_C(        6345),  INT32_C(       27793),  INT32_C(        1658) } },
    { { -INT16_C( 11438), -INT16_C(  4605),  INT16_C(  1186),  INT16_C(  8309),  INT16_C( 15905),  INT16_C( 20270),  INT16_C( 22027), -INT16_C( 20204) },
      { -INT32_C(       16043),  INT32_C(        9495),  INT32_C(       36175),  INT32_C(        1823) } },
    { {  INT16_C(  7020), -INT16_C( 19043),  INT16_C(  7693), -INT16_C( 21797), -INT16_C( 12512),  INT16_C( 23059),  INT16_C( 21693),  INT16_C(  3954) },
      { -INT32_C(       12023), -INT32_C(       14104),  INT32_C(       10547),  INT32_C(       25647) } },
    { {  INT16_C( 29991), -INT16_C( 13827),  INT16_C( 29561), -INT16_C( 25878),  INT16_C(  6321), -INT16_C( 17174), -INT16_C(   402), -INT16_C(  9362) },
      {  INT32_C(       16164),  INT32_C(        3683), -INT32_C(       10853), -INT32_C(        9764) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int32x4_t r = simde_vpaddlq_s16(a);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddlq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(   179405244), -INT32_C(  1105081452), -INT32_C(  1366598320), -INT32_C(   141294459) },
      { -INT64_C(          1284486696), -INT64_C(          1507892779) } },
    { {  INT32_C(  1123194590), -INT32_C(   163436825), -INT32_C(   140019302), -INT32_C(    70761545) },
      {  INT64_C(           959757765), -INT64_C(           210780847) } },
    { {  INT32_C(  1441863361),  INT32_C(   840176353), -INT32_C(   186605713), -INT32_C(  2115210077) },
      {  INT64_C(          2282039714), -INT64_C(          2301815790) } },
    { { -INT32_C(   222044661), -INT32_C(  1628961276),  INT32_C(   915771263), -INT32_C(  1808638254) },
      { -INT64_C(          1851005937), -INT64_C(           892866991) } },
    { {  INT32_C(  1458119540), -INT32_C(  1517748939),  INT32_C(  1083795613), -INT32_C(   389904931) },
      { -INT64_C(            59629399),  INT64_C(           693890682) } },
    { {  INT32_C(  1759151460),  INT32_C(   185057931),  INT32_C(   591502417),  INT32_C(  1874293754) },
      {  INT64_C(          1944209391),  INT64_C(          2465796171) } },
    { { -INT32_C(   859463274),  INT32_C(   997281182), -INT32_C(  1837364555), -INT32_C(   193315184) },
      {  INT64_C(           137817908), -INT64_C(          2030679739) } },
    { {  INT32_C(  1331451075),  INT32_C(  1733976854), -INT32_C(    91514112), -INT32_C(  1519828465) },
      {  INT64_C(          3065427929), -INT64_C(          1611342577) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int64x2_t r = simde_vpaddlq_s32(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddlq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C( 15), UINT8_C(158), UINT8_C(165), UINT8_C( 64), UINT8_C(119), UINT8_C(178), UINT8_C(200), UINT8_C(231),
        UINT8_C( 24), UINT8_C(237), UINT8_C( 46), UINT8_C(127), UINT8_C(140), UINT8_C(113), UINT8_C(193), UINT8_C(161) },
      { UINT16_C(  173), UINT16_C(  229), UINT16_C(  297), UINT16_C(  431), UINT16_C(  261), UINT16_C(  173), UINT16_C(  253), UINT16_C(  354) } },
    { { UINT8_C(221), UINT8_C( 70), UINT8_C(171), UINT8_C(120), UINT8_C(167), UINT8_C(165), UINT8_C(178), UINT8_C(  1),
        UINT8_C(226), UINT8_C( 25), UINT8_C( 93), UINT8_C(232), UINT8_C( 92), UINT8_C(136), UINT8_C( 14), UINT8_C(108) },
      { UINT16_C(  291), UINT16_C(  291), UINT16_C(  332), UINT16_C(  179), UINT16_C(  251), UINT16_C(  325), UINT16_C(  228), UINT16_C(  122) } },
    { { UINT8_C( 38), UINT8_C(180), UINT8_C(172), UINT8_C(157), UINT8_C(102), UINT8_C(117), UINT8_C(133), UINT8_C(127),
        UINT8_C( 98), UINT8_C(179), UINT8_C(254), UINT8_C(238), UINT8_C( 36), UINT8_C(191), UINT8_C(144), UINT8_C(  1) },
      { UINT16_C(  218), UINT16_C(  329), UINT16_C(  219), UINT16_C(  260), UINT16_C(  277), UINT16_C(  492), UINT16_C(  227), UINT16_C(  145) } },
    { { UINT8_C(  6), UINT8_C( 59), UINT8_C(121), UINT8_C(173), UINT8_C(225), UINT8_C( 44), UINT8_C(174), UINT8_C(195),
        UINT8_C( 69), UINT8_C( 11), UINT8_C(171), UINT8_C(162), UINT8_C(147), UINT8_C(186), UINT8_C( 14), UINT8_C(186) },
      { UINT16_C(   65), UINT16_C(  294), UINT16_C(  269), UINT16_C(  369), UINT16_C(   80), UINT16_C(  333), UINT16_C(  333), UINT16_C(  200) } },
    { { UINT8_C(110), UINT8_C(186), UINT8_C( 87), UINT8_C(212), UINT8_C( 47), UINT8_C(220), UINT8_C( 83), UINT8_C(145),
        UINT8_C(143), UINT8_C( 82), UINT8_C(128), UINT8_C(180), UINT8_C( 17), UINT8_C( 16), UINT8_C(181), UINT8_C( 23) },
      { UINT16_C(  296), UINT16_C(  299), UINT16_C(  267), UINT16_C(  228), UINT16_C(  225), UINT16_C(  308), UINT16_C(   33), UINT16_C(  204) } },
    { { UINT8_C( 75), UINT8_C( 47), UINT8_C(196), UINT8_C( 44), UINT8_C( 91), UINT8_C(114), UINT8_C(239), UINT8_C(160),
        UINT8_C(126), UINT8_C(155), UINT8_C( 66), UINT8_C( 17), UINT8_C( 85), UINT8_C( 80), UINT8_C(203), UINT8_C(195) },
      { UINT16_C(  122), UINT16_C(  240), UINT16_C(  205), UINT16_C(  399), UINT16_C(  281), UINT16_C(   83), UINT16_C(  165), UINT16_C(  398) } },
    { { UINT8_C( 11), UINT8_C( 35), UINT8_C(151), UINT8_C( 58),    UINT8_MAX, UINT8_C(235), UINT8_C(204), UINT8_C(143),
        UINT8_C( 61), UINT8_C( 76), UINT8_C( 67), UINT8_C( 78), UINT8_C( 92), UINT8_C(248), UINT8_C(102), UINT8_C(167) },
      { UINT16_C(   46), UINT16_C(  209), UINT16_C(  490), UINT16_C(  347), UINT16_C(  137), UINT16_C(  145), UINT16_C(  340), UINT16_C(  269) } },
    { { UINT8_C( 39), UINT8_C( 42), UINT8_C(212), UINT8_C(130), UINT8_C(157), UINT8_C(195), UINT8_C( 35), UINT8_C( 27),
        UINT8_C( 94), UINT8_C(101), UINT8_C( 44), UINT8_C(179), UINT8_C(182), UINT8_C(248), UINT8_C(118), UINT8_C(193) },
      { UINT16_C(   81), UINT16_C(  342), UINT16_C(  352), UINT16_C(   62), UINT16_C(  195), UINT16_C(  223), UINT16_C(  430), UINT16_C(  311) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint16x8_t r = simde_vpaddlq_u8(a);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddlq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(45646), UINT16_C(37940), UINT16_C(24613), UINT16_C( 4010), UINT16_C(40572), UINT16_C(35232), UINT16_C(47266), UINT16_C(32358) },
      { UINT32_C(     83586), UINT32_C(     28623), UINT32_C(     75804), UINT32_C(     79624) } },
    { { UINT16_C(56173), UINT16_C(35384), UINT16_C(13142), UINT16_C(63375), UINT16_C(22379), UINT16_C(33653), UINT16_C(11990), UINT16_C( 9253) },
      { UINT32_C(     91557), UINT32_C(     76517), UINT32_C(     56032), UINT32_C(     21243) } },
    { { UINT16_C(23008), UINT16_C( 1720), UINT16_C(25273), UINT16_C(13845), UINT16_C(46592), UINT16_C(41663), UINT16_C( 9582), UINT16_C(56097) },
      { UINT32_C(     24728), UINT32_C(     39118), UINT32_C(     88255), UINT32_C(     65679) } },
    { { UINT16_C(22784), UINT16_C(22117), UINT16_C(62860), UINT16_C(63309), UINT16_C(49996), UINT16_C( 8826), UINT16_C(40945), UINT16_C(53831) },
      { UINT32_C(     44901), UINT32_C(    126169), UINT32_C(     58822), UINT32_C(     94776) } },
    { { UINT16_C(65528), UINT16_C(45784), UINT16_C(60770), UINT16_C(25320), UINT16_C(42915), UINT16_C( 4613), UINT16_C( 9932), UINT16_C(52461) },
      { UINT32_C(    111312), UINT32_C(     86090), UINT32_C(     47528), UINT32_C(     62393) } },
    { { UINT16_C(21375), UINT16_C( 2850), UINT16_C(28744), UINT16_C(37890), UINT16_C(31795), UINT16_C( 9399), UINT16_C(65052), UINT16_C( 5366) },
      { UINT32_C(     24225), UINT32_C(     66634), UINT32_C(     41194), UINT32_C(     70418) } },
    { { UINT16_C(52989), UINT16_C(24518), UINT16_C(44732), UINT16_C(24514), UINT16_C(51029), UINT16_C( 8561), UINT16_C(24557), UINT16_C(27885) },
      { UINT32_C(     77507), UINT32_C(     69246), UINT32_C(     59590), UINT32_C(     52442) } },
    { { UINT16_C( 4274), UINT16_C(64119), UINT16_C(31104), UINT16_C(45966), UINT16_C(17909), UINT16_C( 4567), UINT16_C(52803), UINT16_C(16678) },
      { UINT32_C(     68393), UINT32_C(     77070), UINT32_C(     22476), UINT32_C(     69481) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint32x4_t r = simde_vpaddlq_u16(a);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vpaddlq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C( 555135081), UINT32_C(1421955818), UINT32_C(2255016604), UINT32_C(2023953240) },
      { UINT64_C(          1977090899), UINT64_C(          4278969844) } },
    { { UINT32_C(1200506322), UINT32_C(1076302833), UINT32_C(1855454778), UINT32_C(2018949391) },
      { UINT64_C(          2276809155), UINT64_C(          3874404169) } },
    { { UINT32_C(1419340905), UINT32_C(1520982718), UINT32_C(2246119725), UINT32_C(4143809572) },
      { UINT64_C(          2940323623), UINT64_C(          6389929297) } },
    { { UINT32_C(3124595657), UINT32_C(3657065886), UINT32_C(1917293155), UINT32_C(3035274571) },
      { UINT64_C(          6781661543), UINT64_C(          4952567726) } },
    { { UINT32_C(3339223817), UINT32_C( 170045917), UINT32_C(3868132290), UINT32_C(1356631175) },
      { UINT64_C(          3509269734), UINT64_C(          5224763465) } },
    { { UINT32_C(3054115096), UINT32_C(3784246398), UINT32_C(3780368278), UINT32_C(2123775348) },
      { UINT64_C(          6838361494), UINT64_C(          5904143626) } },
    { { UINT32_C(2655362752), UINT32_C( 296249167), UINT32_C(4059510890), UINT32_C(3695301572) },
      { UINT64_C(          2951611919), UINT64_C(          7754812462) } },
    { { UINT32_C(1804815341), UINT32_C(3863814736), UINT32_C(1858642169), UINT32_C(2666290910) },
      { UINT64_C(          5668630077), UINT64_C(          4524933079) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint64x2_t r = simde_vpaddlq_u32(a);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddl_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpaddlq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddlq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddlq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddlq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddlq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpaddlq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
