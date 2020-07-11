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
    { { -INT32_C(   572680233), -INT32_C(  1924933718),  INT32_C(   500354625),  INT32_C(   962586996) },
      {  INT64_C(           500354625),  INT64_C(           962586996) } },
    { { -INT32_C(  1764297356),  INT32_C(  1350824687),  INT32_C(   205890779), -INT32_C(  1241391649) },
      {  INT64_C(           205890779), -INT64_C(          1241391649) } },
    { {  INT32_C(   513007220), -INT32_C(   156510283),  INT32_C(   420708005), -INT32_C(   598576537) },
      {  INT64_C(           420708005), -INT64_C(           598576537) } },
    { {  INT32_C(  1467099496), -INT32_C(   156764901),  INT32_C(  2013457561),  INT32_C(  1043268554) },
      {  INT64_C(          2013457561),  INT64_C(          1043268554) } },
    { { -INT32_C(  1755462942),  INT32_C(  1066272921), -INT32_C(   296181370),  INT32_C(  2093656852) },
      { -INT64_C(           296181370),  INT64_C(          2093656852) } },
    { { -INT32_C(   271369004), -INT32_C(   890930639),  INT32_C(   826533735), -INT32_C(   865111318) },
      {  INT64_C(           826533735), -INT64_C(           865111318) } },
    { { -INT32_C(   832254924),  INT32_C(  1527640789), -INT32_C(  1488362093), -INT32_C(   467463408) },
      { -INT64_C(          1488362093), -INT64_C(           467463408) } },
    { { -INT32_C(  2133592497), -INT32_C(   666126223), -INT32_C(  1979085153),  INT32_C(   878082048) },
      { -INT64_C(          1979085153),  INT64_C(           878082048) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int64x2_t r = simde_vmovl_high_s32(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
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

static int
test_simde_vmovl_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(56414), UINT16_C(14753), UINT16_C(11227), UINT16_C( 1697), UINT16_C(52363), UINT16_C(39448), UINT16_C(21201), UINT16_C(23081) },
      { UINT32_C(     52363), UINT32_C(     39448), UINT32_C(     21201), UINT32_C(     23081) } },
    { { UINT16_C(26292), UINT16_C(28020), UINT16_C(49104), UINT16_C(22614), UINT16_C( 3192), UINT16_C(23245), UINT16_C(44189), UINT16_C(64321) },
      { UINT32_C(      3192), UINT32_C(     23245), UINT32_C(     44189), UINT32_C(     64321) } },
    { { UINT16_C(57992), UINT16_C(25396), UINT16_C(54541), UINT16_C(39273), UINT16_C(33441), UINT16_C(29235), UINT16_C(23764), UINT16_C(35021) },
      { UINT32_C(     33441), UINT32_C(     29235), UINT32_C(     23764), UINT32_C(     35021) } },
    { { UINT16_C(16834), UINT16_C(37622), UINT16_C(19456), UINT16_C(30955), UINT16_C(47192), UINT16_C(62930), UINT16_C( 4964), UINT16_C(60657) },
      { UINT32_C(     47192), UINT32_C(     62930), UINT32_C(      4964), UINT32_C(     60657) } },
    { { UINT16_C( 9718), UINT16_C(  847), UINT16_C(47355), UINT16_C(40092), UINT16_C(53050), UINT16_C( 3855), UINT16_C(56363), UINT16_C(61079) },
      { UINT32_C(     53050), UINT32_C(      3855), UINT32_C(     56363), UINT32_C(     61079) } },
    { { UINT16_C(36125), UINT16_C( 7552), UINT16_C(27610), UINT16_C(12949), UINT16_C(26403), UINT16_C(34600), UINT16_C( 6523), UINT16_C(29043) },
      { UINT32_C(     26403), UINT32_C(     34600), UINT32_C(      6523), UINT32_C(     29043) } },
    { { UINT16_C(49726), UINT16_C(14708), UINT16_C( 4475), UINT16_C(46550), UINT16_C(58848), UINT16_C( 3268), UINT16_C(23745), UINT16_C(57082) },
      { UINT32_C(     58848), UINT32_C(      3268), UINT32_C(     23745), UINT32_C(     57082) } },
    { { UINT16_C(31465), UINT16_C(50171), UINT16_C(37094), UINT16_C( 2550), UINT16_C( 7927), UINT16_C(29329), UINT16_C( 1079), UINT16_C(30179) },
      { UINT32_C(      7927), UINT32_C(     29329), UINT32_C(      1079), UINT32_C(     30179) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint32x4_t r = simde_vmovl_high_u16(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmovl_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(1326137435), UINT32_C( 923094607), UINT32_C(1667697370), UINT32_C(4033731226) },
      { UINT64_C(          1667697370), UINT64_C(          4033731226) } },
    { { UINT32_C(1959824374), UINT32_C( 951202124), UINT32_C(3418443039), UINT32_C(1852570643) },
      { UINT64_C(          3418443039), UINT64_C(          1852570643) } },
    { { UINT32_C(2344449596), UINT32_C(2680341188), UINT32_C(1711417804), UINT32_C(4183256835) },
      { UINT64_C(          1711417804), UINT64_C(          4183256835) } },
    { { UINT32_C(1198335995), UINT32_C(2021662553), UINT32_C(2151891309), UINT32_C(2045685565) },
      { UINT64_C(          2151891309), UINT64_C(          2045685565) } },
    { { UINT32_C(3926174501), UINT32_C( 982107757), UINT32_C(4087385072), UINT32_C(4142790651) },
      { UINT64_C(          4087385072), UINT64_C(          4142790651) } },
    { { UINT32_C(2017286687), UINT32_C(3891314042), UINT32_C(1013396735), UINT32_C( 146167267) },
      { UINT64_C(          1013396735), UINT64_C(           146167267) } },
    { { UINT32_C(1844623872), UINT32_C(1906801537), UINT32_C(  40126471), UINT32_C(1593332031) },
      { UINT64_C(            40126471), UINT64_C(          1593332031) } },
    { { UINT32_C( 651572652), UINT32_C(4060989427), UINT32_C(3727586555), UINT32_C(3387352265) },
      { UINT64_C(          3727586555), UINT64_C(          3387352265) } }
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
