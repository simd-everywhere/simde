#define SIMDE_TEST_ARM_NEON_INSN movl_high

#include "test-neon.h"
#include <simde/arm/neon/movl_high.h>

static int
test_simde_vmovl_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int16_t r[8];
  } test_vec[] = {
    { {  INT8_C(  14),  INT8_C(  54), -INT8_C(   9), -INT8_C(  31), -INT8_C(  54), -INT8_C(  22),  INT8_C(  44),  INT8_C(  62),
         INT8_C(  23),  INT8_C( 107), -INT8_C(  40),  INT8_C(  21), -INT8_C(   6), -INT8_C(  80),  INT8_C(  20), -INT8_C(  87) },
      {  INT16_C(    23),  INT16_C(   107), -INT16_C(    40),  INT16_C(    21), -INT16_C(     6), -INT16_C(    80),  INT16_C(    20), -INT16_C(    87) } },
    { { -INT8_C(  84),  INT8_C(  95), -INT8_C( 109), -INT8_C(  90), -INT8_C( 111),  INT8_C(  97),  INT8_C(  80), -INT8_C( 111),
         INT8_C(  69),  INT8_C(   2),  INT8_C(  28), -INT8_C(  73), -INT8_C(  74),  INT8_C(  26),  INT8_C(  48), -INT8_C(  59) },
      {  INT16_C(    69),  INT16_C(     2),  INT16_C(    28), -INT16_C(    73), -INT16_C(    74),  INT16_C(    26),  INT16_C(    48), -INT16_C(    59) } },
    { {  INT8_C(  80),  INT8_C(  39), -INT8_C(  90),  INT8_C(  27),  INT8_C(  18), -INT8_C(  46),  INT8_C(  89),  INT8_C(  41),
         INT8_C(  62),  INT8_C(  49),  INT8_C(  63),  INT8_C(  56), -INT8_C(  30),  INT8_C(  83), -INT8_C(  30), -INT8_C( 114) },
      {  INT16_C(    62),  INT16_C(    49),  INT16_C(    63),  INT16_C(    56), -INT16_C(    30),  INT16_C(    83), -INT16_C(    30), -INT16_C(   114) } },
    { { -INT8_C(  77),  INT8_C( 117),  INT8_C(  52),  INT8_C(  68), -INT8_C(  42), -INT8_C( 124), -INT8_C(  43),  INT8_C(  28),
        -INT8_C( 122), -INT8_C(  15), -INT8_C(  45),  INT8_C(  61),  INT8_C(  12),  INT8_C(   3),  INT8_C(   2),  INT8_C(  92) },
      { -INT16_C(   122), -INT16_C(    15), -INT16_C(    45),  INT16_C(    61),  INT16_C(    12),  INT16_C(     3),  INT16_C(     2),  INT16_C(    92) } },
    { {  INT8_C(  43), -INT8_C(  88),  INT8_C( 119),  INT8_C(  61),  INT8_C( 122), -INT8_C(  47),  INT8_C( 102), -INT8_C(  72),
         INT8_C(   2), -INT8_C(  91), -INT8_C(  15), -INT8_C(  28), -INT8_C(   7), -INT8_C(  45),  INT8_C( 115), -INT8_C(  84) },
      {  INT16_C(     2), -INT16_C(    91), -INT16_C(    15), -INT16_C(    28), -INT16_C(     7), -INT16_C(    45),  INT16_C(   115), -INT16_C(    84) } },
    { {  INT8_C(  72), -INT8_C(  89), -INT8_C(  16),  INT8_C(  31),  INT8_C(  44), -INT8_C(  59),  INT8_C(  59), -INT8_C(  78),
        -INT8_C(  73),  INT8_C(  14), -INT8_C(  17), -INT8_C(  61),  INT8_C(  18), -INT8_C(  15),  INT8_C(  31),  INT8_C(  61) },
      { -INT16_C(    73),  INT16_C(    14), -INT16_C(    17), -INT16_C(    61),  INT16_C(    18), -INT16_C(    15),  INT16_C(    31),  INT16_C(    61) } },
    { { -INT8_C( 103), -INT8_C( 105),  INT8_C( 122),  INT8_C(  20),  INT8_C( 104), -INT8_C(  32), -INT8_C(  52),  INT8_C( 106),
        -INT8_C( 122), -INT8_C(  67),  INT8_C(  79),      INT8_MAX, -INT8_C( 112), -INT8_C(  62),  INT8_C(  43), -INT8_C(  39) },
      { -INT16_C(   122), -INT16_C(    67),  INT16_C(    79),  INT16_C(   127), -INT16_C(   112), -INT16_C(    62),  INT16_C(    43), -INT16_C(    39) } },
    { {  INT8_C( 105),  INT8_C(  27), -INT8_C(   8), -INT8_C( 107), -INT8_C(  32),  INT8_C(  51),  INT8_C(  72), -INT8_C( 105),
         INT8_C(  65),  INT8_C(  55),  INT8_C(  90),  INT8_C(  83),  INT8_C(  41),  INT8_C( 122), -INT8_C( 112), -INT8_C(  62) },
      {  INT16_C(    65),  INT16_C(    55),  INT16_C(    90),  INT16_C(    83),  INT16_C(    41),  INT16_C(   122), -INT16_C(   112), -INT16_C(    62) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int16x8_t r = simde_vmovl_high_s8(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmovl_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C( 28578),  INT16_C( 30752),  INT16_C( 25600), -INT16_C(  9764),  INT16_C( 32653),  INT16_C( 10732),  INT16_C( 12215), -INT16_C( 28369) },
      {  INT32_C(       32653),  INT32_C(       10732),  INT32_C(       12215), -INT32_C(       28369) } },
    { {  INT16_C( 28571),  INT16_C( 25725), -INT16_C( 29640),  INT16_C( 24270), -INT16_C(  7947), -INT16_C(   838), -INT16_C( 32612),  INT16_C( 16238) },
      { -INT32_C(        7947), -INT32_C(         838), -INT32_C(       32612),  INT32_C(       16238) } },
    { { -INT16_C( 28945), -INT16_C(  3913), -INT16_C( 27662), -INT16_C( 32567), -INT16_C( 19181), -INT16_C( 13655), -INT16_C(  9756),  INT16_C( 32604) },
      { -INT32_C(       19181), -INT32_C(       13655), -INT32_C(        9756),  INT32_C(       32604) } },
    { { -INT16_C(  9912), -INT16_C( 32540), -INT16_C( 19867),  INT16_C( 23262), -INT16_C( 26478),  INT16_C( 12119), -INT16_C( 15080),  INT16_C(  2158) },
      { -INT32_C(       26478),  INT32_C(       12119), -INT32_C(       15080),  INT32_C(        2158) } },
    { {  INT16_C(  9555),  INT16_C( 17912), -INT16_C( 15943), -INT16_C( 13115),  INT16_C( 28534),  INT16_C( 23446), -INT16_C(  3512), -INT16_C( 28454) },
      {  INT32_C(       28534),  INT32_C(       23446), -INT32_C(        3512), -INT32_C(       28454) } },
    { { -INT16_C( 16693),  INT16_C( 12560), -INT16_C(  4240),  INT16_C(   907), -INT16_C(  7545), -INT16_C( 24526), -INT16_C( 24409), -INT16_C(  1368) },
      { -INT32_C(        7545), -INT32_C(       24526), -INT32_C(       24409), -INT32_C(        1368) } },
    { { -INT16_C( 24379),  INT16_C( 32320),  INT16_C(  1377), -INT16_C( 10422), -INT16_C(  7820), -INT16_C( 17358),  INT16_C(  3539), -INT16_C( 24756) },
      { -INT32_C(        7820), -INT32_C(       17358),  INT32_C(        3539), -INT32_C(       24756) } },
    { {  INT16_C( 24011),  INT16_C( 15568),  INT16_C( 23372), -INT16_C( 11457),  INT16_C( 28990), -INT16_C(  6797),  INT16_C(  6929), -INT16_C( 10528) },
      {  INT32_C(       28990), -INT32_C(        6797),  INT32_C(        6929), -INT32_C(       10528) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int32x4_t r = simde_vmovl_high_s16(a);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmovl_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1027561528),  INT32_C(  1181141318), -INT32_C(  1215125691), -INT32_C(   634196092) },
      { -INT64_C(               22715), -INT64_C(                4220) } },
    { { -INT32_C(   747304023), -INT32_C(   457571204), -INT32_C(   553072336),  INT32_C(  2007993663) },
      { -INT64_C(               14032), -INT64_C(               29377) } },
    { {  INT32_C(   733278181), -INT32_C(    42919240),  INT32_C(  1186202817), -INT32_C(  1675565325) },
      {  INT64_C(                1217), -INT64_C(                6413) } },
    { {  INT32_C(  1836094961), -INT32_C(   900584807),  INT32_C(   849959667), -INT32_C(   861316633) },
      {  INT64_C(               23283),  INT64_C(               23015) } },
    { {  INT32_C(    16211272),  INT32_C(   972908663),  INT32_C(  1618981484), -INT32_C(  1963155560) },
      { -INT64_C(               19860), -INT64_C(               24680) } },
    { { -INT32_C(   839422924), -INT32_C(  1969796714), -INT32_C(  1967373917), -INT32_C(   497654118) },
      {  INT64_C(               16803),  INT64_C(               26266) } },
    { {  INT32_C(  1004686787),  INT32_C(   578084790),  INT32_C(   713225105), -INT32_C(   961249390) },
      { -INT64_C(                3183),  INT64_C(               32658) } },
    { { -INT32_C(  2104251413), -INT32_C(  1744032779),  INT32_C(   103008364), -INT32_C(   219645650) },
      { -INT64_C(               14228),  INT64_C(               31022) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int64x2_t r = simde_vmovl_high_s32(a);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static uint
test_simde_vmovl_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C( 28), UINT8_C(149), UINT8_C( 21), UINT8_C( 41), UINT8_C( 25), UINT8_C(124), UINT8_C( 35), UINT8_C( 26),
        UINT8_C(131), UINT8_C(127), UINT8_C( 78), UINT8_C(210), UINT8_C(128), UINT8_C( 54), UINT8_C(221), UINT8_C(127) },
      { UINT16_C(  131), UINT16_C(  127), UINT16_C(   78), UINT16_C(  210), UINT16_C(  128), UINT16_C(   54), UINT16_C(  221), UINT16_C(  127) } },
    { { UINT8_C(225), UINT8_C(206), UINT8_C(118), UINT8_C( 15), UINT8_C(119), UINT8_C(173), UINT8_C( 76), UINT8_C(125),
        UINT8_C( 27), UINT8_C( 72), UINT8_C( 81), UINT8_C(180), UINT8_C( 91), UINT8_C(242), UINT8_C( 74), UINT8_C(119) },
      { UINT16_C(   27), UINT16_C(   72), UINT16_C(   81), UINT16_C(  180), UINT16_C(   91), UINT16_C(  242), UINT16_C(   74), UINT16_C(  119) } },
    { { UINT8_C(135), UINT8_C( 95), UINT8_C(160), UINT8_C(160), UINT8_C(219), UINT8_C(195), UINT8_C(186), UINT8_C( 94),
        UINT8_C( 66), UINT8_C(  9), UINT8_C( 48), UINT8_C(194), UINT8_C( 63), UINT8_C( 13), UINT8_C( 66), UINT8_C( 33) },
      { UINT16_C(   66), UINT16_C(    9), UINT16_C(   48), UINT16_C(  194), UINT16_C(   63), UINT16_C(   13), UINT16_C(   66), UINT16_C(   33) } },
    { { UINT8_C(219), UINT8_C(184), UINT8_C( 48), UINT8_C( 82), UINT8_C(101), UINT8_C(124), UINT8_C(208), UINT8_C(128),
        UINT8_C(197), UINT8_C( 33), UINT8_C( 52), UINT8_C( 32), UINT8_C( 20), UINT8_C(126), UINT8_C(151), UINT8_C(155) },
      { UINT16_C(  197), UINT16_C(   33), UINT16_C(   52), UINT16_C(   32), UINT16_C(   20), UINT16_C(  126), UINT16_C(  151), UINT16_C(  155) } },
    { { UINT8_C(221), UINT8_C( 55), UINT8_C( 60), UINT8_C(184), UINT8_C(250), UINT8_C(246), UINT8_C( 22), UINT8_C( 60),
           UINT8_MAX, UINT8_C( 70),    UINT8_MAX, UINT8_C( 63), UINT8_C( 84), UINT8_C( 65), UINT8_C( 96), UINT8_C( 47) },
      { UINT16_C(  255), UINT16_C(   70), UINT16_C(  255), UINT16_C(   63), UINT16_C(   84), UINT16_C(   65), UINT16_C(   96), UINT16_C(   47) } },
    { { UINT8_C(249), UINT8_C(144), UINT8_C(130), UINT8_C( 95), UINT8_C( 12), UINT8_C( 82), UINT8_C(223), UINT8_C(209),
        UINT8_C(115), UINT8_C( 20), UINT8_C(241), UINT8_C(135), UINT8_C(146), UINT8_C(136), UINT8_C( 35), UINT8_C(112) },
      { UINT16_C(  115), UINT16_C(   20), UINT16_C(  241), UINT16_C(  135), UINT16_C(  146), UINT16_C(  136), UINT16_C(   35), UINT16_C(  112) } },
    { { UINT8_C(191), UINT8_C( 95), UINT8_C( 40), UINT8_C(185), UINT8_C( 85), UINT8_C( 63), UINT8_C(246), UINT8_C( 85),
        UINT8_C(133), UINT8_C(245), UINT8_C(148), UINT8_C(217), UINT8_C( 54), UINT8_C(244), UINT8_C(  9), UINT8_C( 47) },
      { UINT16_C(  133), UINT16_C(  245), UINT16_C(  148), UINT16_C(  217), UINT16_C(   54), UINT16_C(  244), UINT16_C(    9), UINT16_C(   47) } },
    { { UINT8_C(132), UINT8_C(139), UINT8_C(142), UINT8_C(144), UINT8_C(221), UINT8_C(110), UINT8_C( 98), UINT8_C( 80),
        UINT8_C(130), UINT8_C( 83), UINT8_C(216), UINT8_C( 20), UINT8_C(220), UINT8_C(251), UINT8_C(132), UINT8_C(155) },
      { UINT16_C(  130), UINT16_C(   83), UINT16_C(  216), UINT16_C(   20), UINT16_C(  220), UINT16_C(  251), UINT16_C(  132), UINT16_C(  155) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint16x8_t r = simde_vmovl_high_u8(a);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static uint
test_simde_vmovl_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(58484), UINT16_C(36526), UINT16_C(59088), UINT16_C(59663), UINT16_C(13104), UINT16_C(58816), UINT16_C( 7227), UINT16_C(16049) },
      { UINT32_C(     13104), UINT32_C(4294960576), UINT32_C(      7227), UINT32_C(     16049) } },
    { { UINT16_C(  801), UINT16_C(49276), UINT16_C(53902), UINT16_C( 2480), UINT16_C(10790), UINT16_C(20909), UINT16_C(48710), UINT16_C(48016) },
      { UINT32_C(     10790), UINT32_C(     20909), UINT32_C(4294950470), UINT32_C(4294949776) } },
    { { UINT16_C(16035), UINT16_C(29513), UINT16_C(22820), UINT16_C(21596), UINT16_C( 7308), UINT16_C(51001), UINT16_C(59961), UINT16_C(23045) },
      { UINT32_C(      7308), UINT32_C(4294952761), UINT32_C(4294961721), UINT32_C(     23045) } },
    { { UINT16_C(33261), UINT16_C(31770), UINT16_C(51795), UINT16_C(31109), UINT16_C(13301), UINT16_C(15306), UINT16_C(23281), UINT16_C(38134) },
      { UINT32_C(     13301), UINT32_C(     15306), UINT32_C(     23281), UINT32_C(4294939894) } },
    { { UINT16_C(16536), UINT16_C(48136), UINT16_C(25753), UINT16_C( 9488), UINT16_C(18817), UINT16_C(47852), UINT16_C(61747), UINT16_C( 8468) },
      { UINT32_C(     18817), UINT32_C(4294949612), UINT32_C(4294963507), UINT32_C(      8468) } },
    { { UINT16_C(12146), UINT16_C(50589), UINT16_C( 8953), UINT16_C(60990), UINT16_C( 2133), UINT16_C(18218), UINT16_C( 8291), UINT16_C(64475) },
      { UINT32_C(      2133), UINT32_C(     18218), UINT32_C(      8291), UINT32_C(4294966235) } },
    { { UINT16_C(58208), UINT16_C(63928), UINT16_C(51272), UINT16_C(51486), UINT16_C( 2578), UINT16_C(17795), UINT16_C(38907), UINT16_C(28006) },
      { UINT32_C(      2578), UINT32_C(     17795), UINT32_C(4294940667), UINT32_C(     28006) } },
    { { UINT16_C(  966), UINT16_C(49202), UINT16_C(28710), UINT16_C(31662), UINT16_C(55417), UINT16_C(56514), UINT16_C(40697), UINT16_C(22999) },
      { UINT32_C(4294957177), UINT32_C(4294958274), UINT32_C(4294942457), UINT32_C(     22999) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint32x4_t r = simde_vmovl_high_u16(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static uint
test_simde_vmovl_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(1221869277), UINT32_C(1440846704), UINT32_C(3184403440), UINT32_C(1402958121) },
      { UINT64_C(                9200), UINT64_C(               28969) } },
    { { UINT32_C( 150597098), UINT32_C( 471248804), UINT32_C(2750094758), UINT32_C(4258452768) },
      { UINT64_C(                7590), UINT64_C(18446744073709540640) } },
    { { UINT32_C(2202445331), UINT32_C( 718808889), UINT32_C(1961338699), UINT32_C(  63473176) },
      { UINT64_C(18446744073709528907), UINT64_C(18446744073709520408) } },
    { { UINT32_C( 403423604), UINT32_C( 372580976), UINT32_C(1605967935), UINT32_C( 157060085) },
      { UINT64_C(                8255), UINT64_C(18446744073709521909) } },
    { { UINT32_C(1804378674), UINT32_C( 362112458), UINT32_C( 612990220), UINT32_C(1999065347) },
      { UINT64_C(               32012), UINT64_C(               20739) } },
    { { UINT32_C(2190488338), UINT32_C(2493039957), UINT32_C(3673379557), UINT32_C( 266555357) },
      { UINT64_C(               21221), UINT64_C(               20445) } },
    { { UINT32_C(3162206450), UINT32_C(3788574933), UINT32_C(2433047181), UINT32_C(3188207020) },
      { UINT64_C(               23181), UINT64_C(               11692) } },
    { { UINT32_C(3040974944), UINT32_C(1112136029), UINT32_C( 152910891), UINT32_C(2098725003) },
      { UINT64_C(               15403), UINT64_C(                 139) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint64x2_t r = simde_vmovl_high_u32(a);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_high_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
