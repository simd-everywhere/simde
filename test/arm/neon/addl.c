#define SIMDE_TEST_ARM_NEON_INSN addl

#include "test-neon.h"
#include <simde/arm/neon/addl.h>

static int
test_simde_vaddl_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT8_C( 101),  INT8_C(  70),  INT8_C(  78),  INT8_C(  35),  INT8_C(  52), -INT8_C( 115), -INT8_C(  75),  INT8_C(   9) },
      { -INT8_C(   7), -INT8_C(  86),  INT8_C(  92),  INT8_C( 121),  INT8_C( 108),  INT8_C( 119),  INT8_C(  71), -INT8_C(  69) },
      { -INT16_C(   108), -INT16_C(    16),  INT16_C(   170),  INT16_C(   156),  INT16_C(   160),  INT16_C(     4), -INT16_C(     4), -INT16_C(    60) } },
    { {  INT8_C(  84), -INT8_C(  56),  INT8_C(  30),  INT8_C(  53),  INT8_C(  70),  INT8_C(  95),  INT8_C( 116),  INT8_C(  23) },
      {  INT8_C( 117),  INT8_C(  73),  INT8_C( 119), -INT8_C(   6), -INT8_C(  59), -INT8_C(  46),  INT8_C( 109),  INT8_C(  96) },
      {  INT16_C(   201),  INT16_C(    17),  INT16_C(   149),  INT16_C(    47),  INT16_C(    11),  INT16_C(    49),  INT16_C(   225),  INT16_C(   119) } },
    { {  INT8_C(  24), -INT8_C(  69), -INT8_C( 124),  INT8_C(  76),  INT8_C(  72),  INT8_C(  57),  INT8_C(  86),  INT8_C(  65) },
      { -INT8_C(  28), -INT8_C(  78), -INT8_C(  70),  INT8_C(  80),  INT8_C(  42),  INT8_C(   2),  INT8_C(  11),  INT8_C( 126) },
      { -INT16_C(     4), -INT16_C(   147), -INT16_C(   194),  INT16_C(   156),  INT16_C(   114),  INT16_C(    59),  INT16_C(    97),  INT16_C(   191) } },
    { { -INT8_C(  54),  INT8_C(  42), -INT8_C(  77),  INT8_C(  16), -INT8_C( 119),  INT8_C(  40),  INT8_C(  39), -INT8_C(   2) },
      {  INT8_C( 113), -INT8_C(  97), -INT8_C(   8),  INT8_C(  55),  INT8_C( 113),  INT8_C( 101), -INT8_C( 105), -INT8_C( 119) },
      {  INT16_C(    59), -INT16_C(    55), -INT16_C(    85),  INT16_C(    71), -INT16_C(     6),  INT16_C(   141), -INT16_C(    66), -INT16_C(   121) } },
    { {  INT8_C(  32),  INT8_C(  27), -INT8_C(  42),  INT8_C( 105),  INT8_C(  85),  INT8_C(  44), -INT8_C(  86),  INT8_C(  57) },
      { -INT8_C(  34),  INT8_C( 101), -INT8_C( 119),  INT8_C(   8),  INT8_C( 103), -INT8_C( 108), -INT8_C( 122),  INT8_C(  49) },
      { -INT16_C(     2),  INT16_C(   128), -INT16_C(   161),  INT16_C(   113),  INT16_C(   188), -INT16_C(    64), -INT16_C(   208),  INT16_C(   106) } },
    { { -INT8_C(  66),  INT8_C(  58),  INT8_C(  65),  INT8_C(  71),  INT8_C(  98),  INT8_C( 105),  INT8_C(  69), -INT8_C(  45) },
      {  INT8_C(   8),  INT8_C(  62),  INT8_C(  10),  INT8_C( 121), -INT8_C(  93), -INT8_C(  94),  INT8_C(   2), -INT8_C(  60) },
      { -INT16_C(    58),  INT16_C(   120),  INT16_C(    75),  INT16_C(   192),  INT16_C(     5),  INT16_C(    11),  INT16_C(    71), -INT16_C(   105) } },
    { { -INT8_C(  67), -INT8_C(  40),  INT8_C(  45),  INT8_C(  18),  INT8_C(   4), -INT8_C(  41),  INT8_C(  75), -INT8_C(  29) },
      {  INT8_C(  60), -INT8_C(  44), -INT8_C(  21), -INT8_C(  93),  INT8_C( 105),  INT8_C( 114), -INT8_C(  44),  INT8_C(  39) },
      { -INT16_C(     7), -INT16_C(    84),  INT16_C(    24), -INT16_C(    75),  INT16_C(   109),  INT16_C(    73),  INT16_C(    31),  INT16_C(    10) } },
    { { -INT8_C(  84),  INT8_C(  22),  INT8_C( 111),  INT8_C(  14),      INT8_MAX, -INT8_C(  76), -INT8_C(  31), -INT8_C( 121) },
      { -INT8_C(  14), -INT8_C(  20),  INT8_C(   0), -INT8_C( 106), -INT8_C( 114),  INT8_C(   2),  INT8_C(  90),  INT8_C(  75) },
      { -INT16_C(    98),  INT16_C(     2),  INT16_C(   111), -INT16_C(    92),  INT16_C(    13), -INT16_C(    74),  INT16_C(    59), -INT16_C(    46) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vaddl_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C(  6959), -INT16_C( 24020),  INT16_C( 30648),  INT16_C( 17726) },
      { -INT16_C(  1768), -INT16_C(  3483),  INT16_C( 13258), -INT16_C(  4684) },
      {  INT32_C(        5191), -INT32_C(       27503),  INT32_C(       43906),  INT32_C(       13042) } },
    { { -INT16_C( 22668),  INT16_C( 32106), -INT16_C( 15225), -INT16_C( 12164) },
      { -INT16_C( 18961), -INT16_C( 23688), -INT16_C( 23438), -INT16_C( 24172) },
      { -INT32_C(       41629),  INT32_C(        8418), -INT32_C(       38663), -INT32_C(       36336) } },
    { { -INT16_C( 16193),  INT16_C( 30532), -INT16_C( 32200),  INT16_C( 20669) },
      {  INT16_C(  8828),  INT16_C( 17987), -INT16_C(  2219), -INT16_C( 14029) },
      { -INT32_C(        7365),  INT32_C(       48519), -INT32_C(       34419),  INT32_C(        6640) } },
    { { -INT16_C( 25186),  INT16_C(  9543), -INT16_C( 15519),  INT16_C( 20981) },
      {  INT16_C( 28280), -INT16_C(  5388), -INT16_C( 30702), -INT16_C( 11893) },
      {  INT32_C(        3094),  INT32_C(        4155), -INT32_C(       46221),  INT32_C(        9088) } },
    { { -INT16_C( 12471), -INT16_C( 32440),  INT16_C(  1362), -INT16_C( 12591) },
      {  INT16_C(  5160),  INT16_C( 32020),  INT16_C( 18188), -INT16_C( 21945) },
      { -INT32_C(        7311), -INT32_C(         420),  INT32_C(       19550), -INT32_C(       34536) } },
    { { -INT16_C( 28956),  INT16_C( 18128), -INT16_C( 15023), -INT16_C( 13929) },
      { -INT16_C( 29901),  INT16_C( 17843),  INT16_C( 15891),  INT16_C( 23574) },
      { -INT32_C(       58857),  INT32_C(       35971),  INT32_C(         868),  INT32_C(        9645) } },
    { {  INT16_C( 24334),  INT16_C( 24797), -INT16_C( 20636), -INT16_C( 29650) },
      {  INT16_C( 17091), -INT16_C( 12534),  INT16_C( 20873),  INT16_C( 28026) },
      {  INT32_C(       41425),  INT32_C(       12263),  INT32_C(         237), -INT32_C(        1624) } },
    { {  INT16_C( 19167),  INT16_C( 12467),  INT16_C( 18959),  INT16_C( 17401) },
      { -INT16_C( 21291), -INT16_C(  5752), -INT16_C( 24598), -INT16_C(  1979) },
      { -INT32_C(        2124),  INT32_C(        6715), -INT32_C(        5639),  INT32_C(       15422) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vaddl_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1494235381), -INT32_C(  1219392167) },
      {  INT32_C(  1829530619),  INT32_C(  1470485446) },
      {  INT64_C(          3323766000),  INT64_C(           251093279) } },
    { { -INT32_C(   366091336),  INT32_C(  1956650092) },
      {  INT32_C(  1470883480), -INT32_C(  2032977263) },
      {  INT64_C(          1104792144), -INT64_C(            76327171) } },
    { { -INT32_C(   874519694),  INT32_C(  1803694192) },
      {  INT32_C(  1658359452),  INT32_C(   448364130) },
      {  INT64_C(           783839758),  INT64_C(          2252058322) } },
    { { -INT32_C(   855316895), -INT32_C(  1690196733) },
      {  INT32_C(   485682315), -INT32_C(  1717385689) },
      { -INT64_C(           369634580), -INT64_C(          3407582422) } },
    { {  INT32_C(   442860201),  INT32_C(  1317398450) },
      { -INT32_C(   659530122),  INT32_C(  1039296988) },
      { -INT64_C(           216669921),  INT64_C(          2356695438) } },
    { {  INT32_C(  1393292880),  INT32_C(   669928603) },
      {  INT32_C(  1615061049),  INT32_C(  1358554790) },
      {  INT64_C(          3008353929),  INT64_C(          2028483393) } },
    { {  INT32_C(   443178600), -INT32_C(  1133908154) },
      {  INT32_C(   697571661), -INT32_C(   748190077) },
      {  INT64_C(          1140750261), -INT64_C(          1882098231) } },
    { {  INT32_C(   405172860), -INT32_C(   146860866) },
      { -INT32_C(  1688763660), -INT32_C(   789884568) },
      { -INT64_C(          1283590800), -INT64_C(           936745434) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vaddl_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C(240), UINT8_C(249), UINT8_C( 84), UINT8_C(134), UINT8_C( 92), UINT8_C( 31), UINT8_C(197), UINT8_C( 42) },
      { UINT8_C(120), UINT8_C(138), UINT8_C(245), UINT8_C( 38), UINT8_C(147), UINT8_C(110), UINT8_C(210), UINT8_C(229) },
      { UINT16_C(  360), UINT16_C(  387), UINT16_C(  329), UINT16_C(  172), UINT16_C(  239), UINT16_C(  141), UINT16_C(  407), UINT16_C(  271) } },
    { { UINT8_C(239), UINT8_C(203), UINT8_C( 21), UINT8_C( 81), UINT8_C(116), UINT8_C( 90), UINT8_C( 56), UINT8_C(221) },
      { UINT8_C( 68), UINT8_C(222), UINT8_C( 15), UINT8_C(211), UINT8_C(100), UINT8_C(  8), UINT8_C(220), UINT8_C( 85) },
      { UINT16_C(  307), UINT16_C(  425), UINT16_C(   36), UINT16_C(  292), UINT16_C(  216), UINT16_C(   98), UINT16_C(  276), UINT16_C(  306) } },
    { { UINT8_C(  2), UINT8_C( 48), UINT8_C(219), UINT8_C( 94), UINT8_C( 79), UINT8_C(161), UINT8_C(137), UINT8_C(199) },
      { UINT8_C( 43), UINT8_C(126), UINT8_C(237), UINT8_C(190), UINT8_C(237), UINT8_C(192), UINT8_C(163), UINT8_C(220) },
      { UINT16_C(   45), UINT16_C(  174), UINT16_C(  456), UINT16_C(  284), UINT16_C(  316), UINT16_C(  353), UINT16_C(  300), UINT16_C(  419) } },
    { { UINT8_C(139), UINT8_C(184), UINT8_C( 45),    UINT8_MAX, UINT8_C( 18), UINT8_C(102), UINT8_C(220), UINT8_C( 86) },
      { UINT8_C( 68), UINT8_C(236), UINT8_C( 41), UINT8_C(168), UINT8_C(244), UINT8_C(  5), UINT8_C(253), UINT8_C(246) },
      { UINT16_C(  207), UINT16_C(  420), UINT16_C(   86), UINT16_C(  423), UINT16_C(  262), UINT16_C(  107), UINT16_C(  473), UINT16_C(  332) } },
    { { UINT8_C( 54), UINT8_C(217), UINT8_C( 85), UINT8_C(133), UINT8_C(122), UINT8_C(222), UINT8_C( 77), UINT8_C(165) },
      { UINT8_C( 92), UINT8_C( 58), UINT8_C(100), UINT8_C( 73), UINT8_C(250), UINT8_C(  7), UINT8_C( 38), UINT8_C(133) },
      { UINT16_C(  146), UINT16_C(  275), UINT16_C(  185), UINT16_C(  206), UINT16_C(  372), UINT16_C(  229), UINT16_C(  115), UINT16_C(  298) } },
    { { UINT8_C(192), UINT8_C( 83), UINT8_C(132), UINT8_C(210), UINT8_C(185), UINT8_C( 97), UINT8_C( 41), UINT8_C(253) },
      { UINT8_C( 77), UINT8_C( 82), UINT8_C(166), UINT8_C( 65), UINT8_C( 88), UINT8_C(163), UINT8_C( 56), UINT8_C(142) },
      { UINT16_C(  269), UINT16_C(  165), UINT16_C(  298), UINT16_C(  275), UINT16_C(  273), UINT16_C(  260), UINT16_C(   97), UINT16_C(  395) } },
    { { UINT8_C(124), UINT8_C(141), UINT8_C( 19), UINT8_C(246), UINT8_C(107), UINT8_C( 96), UINT8_C(156), UINT8_C(199) },
      { UINT8_C(155), UINT8_C(  0), UINT8_C( 17), UINT8_C(149), UINT8_C(  7), UINT8_C( 55), UINT8_C( 27), UINT8_C(199) },
      { UINT16_C(  279), UINT16_C(  141), UINT16_C(   36), UINT16_C(  395), UINT16_C(  114), UINT16_C(  151), UINT16_C(  183), UINT16_C(  398) } },
    { { UINT8_C(138), UINT8_C(159), UINT8_C(154), UINT8_C( 68), UINT8_C(  0), UINT8_C(195), UINT8_C( 65), UINT8_C( 77) },
      { UINT8_C( 21), UINT8_C(231), UINT8_C(143), UINT8_C(109), UINT8_C(139), UINT8_C(199), UINT8_C(251), UINT8_C(  7) },
      { UINT16_C(  159), UINT16_C(  390), UINT16_C(  297), UINT16_C(  177), UINT16_C(  139), UINT16_C(  394), UINT16_C(  316), UINT16_C(   84) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vaddl_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(57527), UINT16_C(64774), UINT16_C(46352), UINT16_C(39096) },
      { UINT16_C(39401), UINT16_C(22114), UINT16_C(21871), UINT16_C(51426) },
      { UINT32_C(     96928), UINT32_C(     86888), UINT32_C(     68223), UINT32_C(     90522) } },
    { { UINT16_C( 1994), UINT16_C(58923), UINT16_C(31609), UINT16_C(59535) },
      { UINT16_C(58560), UINT16_C( 5121), UINT16_C(47672), UINT16_C(61477) },
      { UINT32_C(     60554), UINT32_C(     64044), UINT32_C(     79281), UINT32_C(    121012) } },
    { { UINT16_C(11418), UINT16_C(43757), UINT16_C(42721), UINT16_C(52034) },
      { UINT16_C(42047), UINT16_C(44833), UINT16_C( 1017), UINT16_C(50295) },
      { UINT32_C(     53465), UINT32_C(     88590), UINT32_C(     43738), UINT32_C(    102329) } },
    { { UINT16_C(41482), UINT16_C(33706), UINT16_C(14621), UINT16_C(56684) },
      { UINT16_C(27933), UINT16_C(22002), UINT16_C( 5927), UINT16_C(49477) },
      { UINT32_C(     69415), UINT32_C(     55708), UINT32_C(     20548), UINT32_C(    106161) } },
    { { UINT16_C(13123), UINT16_C( 9579), UINT16_C(44505), UINT16_C( 6384) },
      { UINT16_C( 4434), UINT16_C(19399), UINT16_C(16149), UINT16_C( 7951) },
      { UINT32_C(     17557), UINT32_C(     28978), UINT32_C(     60654), UINT32_C(     14335) } },
    { { UINT16_C(47585), UINT16_C(65443), UINT16_C( 4082), UINT16_C( 4060) },
      { UINT16_C(52860), UINT16_C(41829), UINT16_C(43750), UINT16_C(10596) },
      { UINT32_C(    100445), UINT32_C(    107272), UINT32_C(     47832), UINT32_C(     14656) } },
    { { UINT16_C(53213), UINT16_C(46670), UINT16_C(15996), UINT16_C(52943) },
      { UINT16_C(38480), UINT16_C(25882), UINT16_C(10709), UINT16_C(46980) },
      { UINT32_C(     91693), UINT32_C(     72552), UINT32_C(     26705), UINT32_C(     99923) } },
    { { UINT16_C(10211), UINT16_C(54710), UINT16_C(37430), UINT16_C(45797) },
      { UINT16_C(19041), UINT16_C(18261), UINT16_C(47604), UINT16_C(53872) },
      { UINT32_C(     29252), UINT32_C(     72971), UINT32_C(     85034), UINT32_C(     99669) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vaddl_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(2652809081), UINT32_C(1638988185) },
      { UINT32_C(3786702705), UINT32_C(4014799475) },
      { UINT64_C(          6439511786), UINT64_C(          5653787660) } },
    { { UINT32_C( 549286435), UINT32_C(3132943308) },
      { UINT32_C(4193740714), UINT32_C( 171232401) },
      { UINT64_C(          4743027149), UINT64_C(          3304175709) } },
    { { UINT32_C( 229134963), UINT32_C(3161348171) },
      { UINT32_C(1268589271), UINT32_C(1060825628) },
      { UINT64_C(          1497724234), UINT64_C(          4222173799) } },
    { { UINT32_C( 677443676), UINT32_C(2397183203) },
      { UINT32_C( 344447363), UINT32_C( 421444518) },
      { UINT64_C(          1021891039), UINT64_C(          2818627721) } },
    { { UINT32_C(1478936333), UINT32_C(4145386783) },
      { UINT32_C(3561140919), UINT32_C(4162026652) },
      { UINT64_C(          5040077252), UINT64_C(          8307413435) } },
    { { UINT32_C(1478587252), UINT32_C( 317064079) },
      { UINT32_C(2200333789), UINT32_C( 916210985) },
      { UINT64_C(          3678921041), UINT64_C(          1233275064) } },
    { { UINT32_C( 730841868), UINT32_C( 253928536) },
      { UINT32_C(4091765846), UINT32_C(1441527777) },
      { UINT64_C(          4822607714), UINT64_C(          1695456313) } },
    { { UINT32_C(4205644906), UINT32_C(3977024272) },
      { UINT32_C( 711996161), UINT32_C(2220887160) },
      { UINT64_C(          4917641067), UINT64_C(          6197911432) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vaddl_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_u32)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
