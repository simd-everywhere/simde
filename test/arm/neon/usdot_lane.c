#define SIMDE_TEST_ARM_NEON_INSN usdot_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/usdot_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vusdot_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    uint8_t a[8];
    int8_t b[8];
    const int lane;
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1955274237), -INT32_C(  1889937468) },
      {  UINT8_C(   111),  UINT8_C(    75),  UINT8_C(   244),  UINT8_C(    11),
         UINT8_C(   198),  UINT8_C(   160),  UINT8_C(   179),  UINT8_C(   238) },
      { -INT8_C(    91), -INT8_C(     4),  INT8_C(    43), -INT8_C(    65),
         INT8_C(    83), -INT8_C(    22),  INT8_C(    99), -INT8_C(   106) },
         INT8_C(     1),
      {  INT32_C(  1955304790), -INT32_C(  1889932061) } },
    { {  INT32_C(   660565832),  INT32_C(   732341267) },
      {  UINT8_C(    38),  UINT8_C(   108),  UINT8_C(   185),  UINT8_C(   181),
         UINT8_C(   182),  UINT8_C(   128),  UINT8_C(   141),  UINT8_C(   118) },
      {  INT8_C(    52), -INT8_C(    65),  INT8_C(    44), -INT8_C(    16),
        -INT8_C(    53),  INT8_C(    93), -INT8_C(    70),  INT8_C(    70) },
         INT8_C(     1),
      {  INT32_C(   660573582),  INT32_C(   732341915) } },
    { {  INT32_C(   627007920), -INT32_C(  1660078375) },
      {  UINT8_C(   126),  UINT8_C(   208),  UINT8_C(   150),  UINT8_C(   117),
         UINT8_C(   215),  UINT8_C(    64),  UINT8_C(    79),  UINT8_C(   238) },
      { -INT8_C(    87),  INT8_C(   115),  INT8_C(    96),  INT8_C(    16),
        -INT8_C(    15),  INT8_C(    20), -INT8_C(   115),  INT8_C(    66) },
         INT8_C(     1),
      {  INT32_C(   627000662), -INT32_C(  1660073697) } },
    { { -INT32_C(   795674244),  INT32_C(  2041017937) },
      {  UINT8_C(   248),  UINT8_C(   220),  UINT8_C(   167),  UINT8_C(   246),
         UINT8_C(   237),  UINT8_C(   204),  UINT8_C(    51),  UINT8_C(     5) },
      { -INT8_C(    24),  INT8_C(    46), -INT8_C(   127), -INT8_C(    75),
         INT8_C(   120),  INT8_C(     5),  INT8_C(     7), -INT8_C(   103) },
         INT8_C(     1),
      { -INT32_C(   795667553),  INT32_C(  2041047239) } },
    { { -INT32_C(   500771884),  INT32_C(   931250387) },
      {  UINT8_C(   172),  UINT8_C(    83),  UINT8_C(    25),  UINT8_C(   186),
         UINT8_C(    51),  UINT8_C(   166),  UINT8_C(    37),  UINT8_C(   240) },
      { -INT8_C(    61),  INT8_C(    10), -INT8_C(    19), -INT8_C(   110),
        -INT8_C(    40),  INT8_C(     5), -INT8_C(    64),  INT8_C(   113) },
         INT8_C(     1),
      { -INT32_C(   500758931),  INT32_C(   931273929) } },
    { {  INT32_C(  1820140433), -INT32_C(   609988652) },
      {  UINT8_C(   177),  UINT8_C(   125),  UINT8_C(    12),  UINT8_C(     2),
         UINT8_C(   111),  UINT8_C(   228),  UINT8_C(    78),  UINT8_C(   237) },
      { -INT8_C(    41), -INT8_C(    39), -INT8_C(    41),  INT8_C(    57),
        -INT8_C(    13), -INT8_C(   125),  INT8_C(    18),  INT8_C(   102) },
         INT8_C(     0),
      {  INT32_C(  1820127923), -INT32_C(   609991784) } },
    { {  INT32_C(   292947444), -INT32_C(  1372646607) },
      {  UINT8_C(   120),  UINT8_C(   177),  UINT8_C(   140),  UINT8_C(    76),
         UINT8_C(   234),  UINT8_C(    28),  UINT8_C(   151),  UINT8_C(   213) },
      {  INT8_C(    43),  INT8_C(     7), -INT8_C(    52), -INT8_C(    57),
        -INT8_C(    66),  INT8_C(   121), -INT8_C(   124), -INT8_C(    32) },
         INT8_C(     0),
      {  INT32_C(   292942231), -INT32_C(  1372656342) } },
    { { -INT32_C(  1164280423),  INT32_C(   313457577) },
      {  UINT8_C(    29),  UINT8_C(    34),  UINT8_C(   150),  UINT8_C(   145),
         UINT8_C(   118),  UINT8_C(    95),  UINT8_C(    76),  UINT8_C(    32) },
      { -INT8_C(    75), -INT8_C(    16),  INT8_C(   109),  INT8_C(    66),
        -INT8_C(   106), -INT8_C(    57), -INT8_C(    93), -INT8_C(   127) },
         INT8_C(     0),
      { -INT32_C(  1164257222),  INT32_C(   313457603) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int32x2_t r;

    switch(test_vec[i].lane) {
      case 0: r = simde_vusdot_lane_s32(r_, a, b, 0); break;
      case 1: r = simde_vusdot_lane_s32(r_, a, b, 1); break;
      default: HEDLEY_UNREACHABLE(); r = r_; break;
    }

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    int lane = simde_test_codegen_random_i8() & 1;
    simde_int32x2_t r;

    switch(test_vec[i].lane) {
      case 0: r = simde_vusdot_lane_s32(r_, a, b, 0); break;
      case 1: r = simde_vusdot_lane_s32(r_, a, b, 1); break;
      default: HEDLEY_UNREACHABLE(); r = r_; break;
    }

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vusdot_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    uint8_t a[8];
    int8_t b[16];
    const int lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1002358686),  INT32_C(  2140546320) },
      {  UINT8_C(   194),  UINT8_C(    84),  UINT8_C(   163),  UINT8_C(   152),
         UINT8_C(   175),  UINT8_C(   103),  UINT8_C(    87),  UINT8_C(   134) },
      { -INT8_C(    69),  INT8_C(    17), -INT8_C(   115), -INT8_C(     7),
         INT8_C(    45), -INT8_C(    89),  INT8_C(    77),  INT8_C(    69),
        -INT8_C(    44),  INT8_C(    18),  INT8_C(    20), -INT8_C(   115),
         INT8_C(    34),  INT8_C(    96),  INT8_C(   121),  INT8_C(   114) },
         INT8_C(     0),
      { -INT32_C(  1002390453),  INT32_C(  2140525053) } },
    { {  INT32_C(  1591752892),  INT32_C(  1979242397) },
      {  UINT8_C(   104),  UINT8_C(   249),  UINT8_C(   101),  UINT8_C(    37),
         UINT8_C(    20),  UINT8_C(   174),  UINT8_C(   160),  UINT8_C(   214) },
      {  INT8_C(   100), -INT8_C(   105),  INT8_C(    14), -INT8_C(    62),
        -INT8_C(     8), -INT8_C(     1),  INT8_C(    34), -INT8_C(     5),
         INT8_C(   117), -INT8_C(    28),  INT8_C(    48), -INT8_C(    83),
         INT8_C(   116), -INT8_C(    35),  INT8_C(    14), -INT8_C(    55) },
         INT8_C(     1),
      {  INT32_C(  1591755060),  INT32_C(  1979246433) } },
    { {  INT32_C(  1966592036), -INT32_C(  1255552378) },
      {  UINT8_C(   214),  UINT8_C(    41),  UINT8_C(   253),  UINT8_C(    41),
         UINT8_C(   245),  UINT8_C(   211),  UINT8_C(   162),  UINT8_C(   239) },
      {  INT8_C(    23),  INT8_C(   116), -INT8_C(   112),  INT8_C(    75),
         INT8_C(   104),  INT8_C(    17), -INT8_C(    85),  INT8_C(    43),
        -INT8_C(    92), -INT8_C(    87), -INT8_C(    54),  INT8_C(    30),
        -INT8_C(    83),  INT8_C(    10),  INT8_C(     0),  INT8_C(    86) },
         INT8_C(     2),
      {  INT32_C(  1966556349), -INT32_C(  1255594853) } },
    { {  INT32_C(  1899859831),  INT32_C(  1109674313) },
      {  UINT8_C(    71),  UINT8_C(    12),  UINT8_C(   157),  UINT8_C(   171),
         UINT8_C(   170),  UINT8_C(   131),  UINT8_C(   111),  UINT8_C(   173) },
      {  INT8_C(    10), -INT8_C(    41),  INT8_C(   125),  INT8_C(    68),
        -INT8_C(    56), -INT8_C(    29), -INT8_C(    46),  INT8_C(   117),
        -INT8_C(     4),  INT8_C(    58),  INT8_C(    29),  INT8_C(    84),
        -INT8_C(     5),  INT8_C(    87),  INT8_C(    96), -INT8_C(    95) },
         INT8_C(     0),
      {  INT32_C(  1899891302),  INT32_C(  1109696281) } },
    { {  INT32_C(  1095356137),  INT32_C(  1106631433) },
      {  UINT8_C(    73),  UINT8_C(   103),  UINT8_C(   205),  UINT8_C(    56),
         UINT8_C(   111),  UINT8_C(    93),  UINT8_C(    13),  UINT8_C(   254) },
      {  INT8_C(     0),  INT8_C(   110),  INT8_C(   123),  INT8_C(     7),
        -INT8_C(    47), -INT8_C(    71), -INT8_C(    48),  INT8_C(   119),
        -INT8_C(    96), -INT8_C(   125),  INT8_C(    56), -INT8_C(   119),
         INT8_C(   123), -INT8_C(    58),  INT8_C(    62), -INT8_C(   121) },
         INT8_C(     3),
      {  INT32_C(  1095365076),  INT32_C(  1106609764) } },
    { {  INT32_C(   180153551),  INT32_C(  1106492494) },
      {  UINT8_C(   221),  UINT8_C(    95),  UINT8_C(    59),  UINT8_C(   133),
         UINT8_C(   122),  UINT8_C(   106),  UINT8_C(   255),  UINT8_C(    42) },
      {  INT8_C(   115), -INT8_C(    40),  INT8_C(    57), -INT8_C(   101),
        -INT8_C(   113), -INT8_C(   101), -INT8_C(    10),  INT8_C(    91),
         INT8_C(    13),  INT8_C(   127), -INT8_C(    27), -INT8_C(    27),
         INT8_C(    33),  INT8_C(   117),  INT8_C(     7),  INT8_C(    62) },
         INT8_C(     0),
      {  INT32_C(   180165096),  INT32_C(  1106512577) } },
    { {  INT32_C(   308136730), -INT32_C(  1314693465) },
      {  UINT8_C(   176),  UINT8_C(    38),  UINT8_C(   156),  UINT8_C(   210),
         UINT8_C(   242),  UINT8_C(   218),  UINT8_C(   227),  UINT8_C(   103) },
      {  INT8_C(   106),  INT8_C(    22), -INT8_C(    70), -INT8_C(    31),
         INT8_C(    72), -INT8_C(   111), -INT8_C(    55), -INT8_C(   119),
         INT8_C(   105), -INT8_C(    31),  INT8_C(    75), -INT8_C(    20),
        -INT8_C(    48),  INT8_C(    64),  INT8_C(    79), -INT8_C(    25) },
         INT8_C(     3),
      {  INT32_C(   308137788), -INT32_C(  1314675771) } },
    { {  INT32_C(  1753049053), -INT32_C(  1649650534) },
      {  UINT8_C(   142),  UINT8_C(   174),  UINT8_C(   245),  UINT8_C(   148),
         UINT8_C(   129),  UINT8_C(   234),  UINT8_C(   142),  UINT8_C(   241) },
      { -INT8_C(   122),  INT8_C(     0),  INT8_C(    43), -INT8_C(    62),
         INT8_C(     7), -INT8_C(   109),  INT8_C(   100), -INT8_C(     6),
        -INT8_C(    79),  INT8_C(    69), -INT8_C(    30), -INT8_C(    28),
         INT8_C(   121), -INT8_C(   122),  INT8_C(   123), -INT8_C(    99) },
         INT8_C(     1),
      {  INT32_C(  1753054693), -INT32_C(  1649662383) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int32x2_t r;

    switch(test_vec[i].lane) {
      case 0: r = simde_vusdot_laneq_s32(r_, a, b, 0); break;
      case 1: r = simde_vusdot_laneq_s32(r_, a, b, 1); break;
      case 2: r = simde_vusdot_laneq_s32(r_, a, b, 2); break;
      case 3: r = simde_vusdot_laneq_s32(r_, a, b, 3); break;
      default: HEDLEY_UNREACHABLE(); r = r_; break;
    }

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    int lane = simde_test_codegen_random_i8() & 3;
    simde_int32x2_t r;

    switch(test_vec[i].lane) {
      case 0: r = simde_vusdot_laneq_s32(r_, a, b, 0); break;
      case 1: r = simde_vusdot_laneq_s32(r_, a, b, 1); break;
      case 2: r = simde_vusdot_laneq_s32(r_, a, b, 2); break;
      case 3: r = simde_vusdot_laneq_s32(r_, a, b, 3); break;
      default: HEDLEY_UNREACHABLE(); r = r_; break;
    }

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vusdotq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[4];
    uint8_t a[16];
    int8_t b[16];
    const int lane;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1808348664), -INT32_C(   712364711), -INT32_C(  1502857295),  INT32_C(  1643789820) },
      {  UINT8_C(   192),  UINT8_C(   202),  UINT8_C(   204),  UINT8_C(   169),
         UINT8_C(   152),  UINT8_C(   130),  UINT8_C(   161),  UINT8_C(   103),
         UINT8_C(   205),  UINT8_C(   212),  UINT8_C(   174),  UINT8_C(   191),
         UINT8_C(   164),  UINT8_C(   176),  UINT8_C(   141),  UINT8_C(   243) },
      { -INT8_C(    47),  INT8_C(    43),  INT8_C(    61), -INT8_C(   121),
         INT8_C(   102),  INT8_C(    65),  INT8_C(    36), -INT8_C(    12),
         INT8_C(    18),  INT8_C(    18),  INT8_C(   125),  INT8_C(    52),
        -INT8_C(    23),  INT8_C(   105),  INT8_C(    92), -INT8_C(    38) },
         INT8_C(     0),
      { -INT32_C(  1808357007), -INT32_C(   712368907), -INT32_C(  1502870311),  INT32_C(  1643768878) } },
    { {  INT32_C(  1155571221),  INT32_C(  1964784352),  INT32_C(  1658887817),  INT32_C(   500272907) },
      {  UINT8_C(    18),  UINT8_C(    92),  UINT8_C(    73),  UINT8_C(    84),
         UINT8_C(    23),  UINT8_C(   126),  UINT8_C(   166),  UINT8_C(    34),
         UINT8_C(    92),  UINT8_C(    91),  UINT8_C(   176),  UINT8_C(    68),
         UINT8_C(   174),  UINT8_C(   226),  UINT8_C(   141),  UINT8_C(   235) },
      { -INT8_C(    73),  INT8_C(    51),  INT8_C(    23), -INT8_C(    58),
        -INT8_C(   114),  INT8_C(    87), -INT8_C(    28), -INT8_C(   126),
        -INT8_C(   114), -INT8_C(     7), -INT8_C(   125),  INT8_C(     5),
         INT8_C(   111),  INT8_C(    27), -INT8_C(    70),  INT8_C(    10) },
         INT8_C(     2),
      {  INT32_C(  1155559820),  INT32_C(  1964760268),  INT32_C(  1658855032),  INT32_C(   500235039) } },
    { { -INT32_C(   889977688),  INT32_C(  1697083557),  INT32_C(  1817103515),  INT32_C(  1243107907) },
      {  UINT8_C(     5),  UINT8_C(   113),  UINT8_C(   228),  UINT8_C(   180),
         UINT8_C(   214),  UINT8_C(   148),  UINT8_C(   116),  UINT8_C(   107),
         UINT8_C(   155),  UINT8_C(     3),  UINT8_C(    27),  UINT8_C(    22),
         UINT8_C(   233),  UINT8_C(     5),  UINT8_C(   244),  UINT8_C(   192) },
      {  INT8_C(    85),  INT8_C(   124),  INT8_C(   103), -INT8_C(    15),
        -INT8_C(   127),  INT8_C(    80),  INT8_C(    63),  INT8_C(    53),
         INT8_C(    51), -INT8_C(    69),  INT8_C(   105), -INT8_C(   126),
         INT8_C(    47), -INT8_C(    50), -INT8_C(     6),  INT8_C(    19) },
         INT8_C(     0),
      { -INT32_C(   889942467),  INT32_C(  1697130442),  INT32_C(  1817119513),  INT32_C(  1243150584) } },
    { { -INT32_C(  1099316937), -INT32_C(  1159034918), -INT32_C(   107587893), -INT32_C(  1291075881) },
      {  UINT8_C(   127),  UINT8_C(    85),  UINT8_C(   186),  UINT8_C(    99),
         UINT8_C(   100),  UINT8_C(    41),  UINT8_C(   238),  UINT8_C(   213),
         UINT8_C(    80),  UINT8_C(    98),  UINT8_C(   231),  UINT8_C(    82),
         UINT8_C(    55),  UINT8_C(    75),  UINT8_C(   109),  UINT8_C(   170) },
      { -INT8_C(     3),  INT8_C(   109), -INT8_C(    83), -INT8_C(    45),
         INT8_C(     6),  INT8_C(    81), -INT8_C(    27),  INT8_C(    92),
         INT8_C(     9),  INT8_C(    78), -INT8_C(   127), -INT8_C(     7),
         INT8_C(    23), -INT8_C(    50), -INT8_C(    23),  INT8_C(    73) },
         INT8_C(     3),
      { -INT32_C(  1099315317), -INT32_C(  1159024593), -INT32_C(   107590280), -INT32_C(  1291068463) } },
    { { -INT32_C(   605997830),  INT32_C(   343847557),  INT32_C(  1735726938), -INT32_C(   414578842) },
      {  UINT8_C(    18),  UINT8_C(   115),  UINT8_C(   100),  UINT8_C(   204),
         UINT8_C(   161),  UINT8_C(    57),  UINT8_C(   189),  UINT8_C(   100),
         UINT8_C(   204),  UINT8_C(   226),  UINT8_C(    83),  UINT8_C(   246),
         UINT8_C(   102),  UINT8_C(    66),  UINT8_C(   117),  UINT8_C(   104) },
      {  INT8_C(    63),  INT8_C(    56), -INT8_C(    39),  INT8_C(    51),
         INT8_C(    82), -INT8_C(    57), -INT8_C(   112),  INT8_C(   101),
        -INT8_C(    49), -INT8_C(    78), -INT8_C(    63),  INT8_C(   114),
        -INT8_C(   100), -INT8_C(    86),  INT8_C(    31), -INT8_C(   103) },
         INT8_C(     1),
      { -INT32_C(   605993505),  INT32_C(   343846442),  INT32_C(  1735746334), -INT32_C(   414576840) } },
    { {  INT32_C(   739050373),  INT32_C(  1773005193), -INT32_C(  1333573677),  INT32_C(  1628274532) },
      {  UINT8_C(   166),  UINT8_C(    95),  UINT8_C(   121),  UINT8_C(   126),
         UINT8_C(   214),  UINT8_C(    84),  UINT8_C(   207),  UINT8_C(    96),
         UINT8_C(   102),  UINT8_C(   221),  UINT8_C(   147),  UINT8_C(   246),
         UINT8_C(    28),  UINT8_C(    68),  UINT8_C(    67),  UINT8_C(    85) },
      { -INT8_C(   117),  INT8_C(    31),  INT8_C(     6), -INT8_C(    17),
         INT8_C(   101), -INT8_C(   124),  INT8_C(   126), -INT8_C(    57),
         INT8_C(    35),  INT8_C(    80), -INT8_C(   105),  INT8_C(     8),
        -INT8_C(    46), -INT8_C(    48),  INT8_C(   123), -INT8_C(   113) },
         INT8_C(     0),
      {  INT32_C(   739032480),  INT32_C(  1772982369), -INT32_C(  1333582060),  INT32_C(  1628272321) } },
    { { -INT32_C(   979829411),  INT32_C(    29939481),  INT32_C(  1700566664), -INT32_C(  2033748144) },
      {  UINT8_C(    93),  UINT8_C(   234),  UINT8_C(   223),  UINT8_C(   208),
         UINT8_C(   128),  UINT8_C(   235),  UINT8_C(    39),  UINT8_C(   130),
         UINT8_C(   107),  UINT8_C(   202),  UINT8_C(   231),  UINT8_C(   163),
         UINT8_C(    74),  UINT8_C(   220),  UINT8_C(    77),  UINT8_C(   103) },
      { -INT8_C(     6),  INT8_C(   116), -INT8_C(    42), -INT8_C(     5),
         INT8_C(    70),  INT8_C(     2), -INT8_C(   110),  INT8_C(    82),
        -INT8_C(    93),  INT8_C(    56), -INT8_C(    31),  INT8_C(   110),
        -INT8_C(    97),  INT8_C(    28),  INT8_C(    15),  INT8_C(    32) },
         INT8_C(     2),
      { -INT32_C(   979808989),  INT32_C(    29953828),  INT32_C(  1700578794), -INT32_C(  2033733763) } },
    { {  INT32_C(   141238293), -INT32_C(   275548335), -INT32_C(  2103112209), -INT32_C(  1174378455) },
      {  UINT8_C(   175),  UINT8_C(   133),  UINT8_C(   106),  UINT8_C(   144),
         UINT8_C(   115),  UINT8_C(   137),  UINT8_C(     4),  UINT8_C(   250),
         UINT8_C(   109),  UINT8_C(   181),  UINT8_C(   113),  UINT8_C(   145),
         UINT8_C(     6),  UINT8_C(    47),  UINT8_C(    11),  UINT8_C(    92) },
      { -INT8_C(    52),  INT8_C(    95),  INT8_C(    68),  INT8_C(    86),
        -INT8_C(   113),  INT8_C(    14),  INT8_C(     9),  INT8_C(    57),
        -INT8_C(    15), -INT8_C(    86),  INT8_C(    17),  INT8_C(    86),
        -INT8_C(    50), -INT8_C(    79),  INT8_C(    79),  INT8_C(    86) },
         INT8_C(     1),
      {  INT32_C(   141229542), -INT32_C(   275545126), -INT32_C(  2103112710), -INT32_C(  1174373132) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t r_ = simde_vld1q_s32(test_vec[i].r_);
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int32x4_t r;

    switch(test_vec[i].lane) {
      case 0: r = simde_vusdotq_laneq_s32(r_, a, b, 0); break;
      case 1: r = simde_vusdotq_laneq_s32(r_, a, b, 1); break;
      case 2: r = simde_vusdotq_laneq_s32(r_, a, b, 2); break;
      case 3: r = simde_vusdotq_laneq_s32(r_, a, b, 3); break;
      default: HEDLEY_UNREACHABLE(); r = r_; break;
    }

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t r_ = simde_test_arm_neon_random_i32x4();
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    int lane = simde_test_codegen_random_i8() & 3;
    simde_int32x4_t r;

    switch(test_vec[i].lane) {
      case 0: r = simde_vusdotq_laneq_s32(r_, a, b, 0); break;
      case 1: r = simde_vusdotq_laneq_s32(r_, a, b, 1); break;
      case 2: r = simde_vusdotq_laneq_s32(r_, a, b, 2); break;
      case 3: r = simde_vusdotq_laneq_s32(r_, a, b, 3); break;
      default: HEDLEY_UNREACHABLE(); r = r_; break;
    }

    simde_test_arm_neon_write_i32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vusdotq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[4];
    uint8_t a[16];
    int8_t b[8];
    const int lane;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1248868707),  INT32_C(  1471720578),  INT32_C(  1999970521), -INT32_C(   199398718) },
      {  UINT8_C(   191),  UINT8_C(    27),  UINT8_C(     2),  UINT8_C(    96),
         UINT8_C(   134),  UINT8_C(   145),  UINT8_C(   164),  UINT8_C(   209),
         UINT8_C(    59),  UINT8_C(    56),  UINT8_C(    12),  UINT8_C(    14),
         UINT8_C(    72),  UINT8_C(    50),  UINT8_C(   192),  UINT8_C(     1) },
      {  INT8_C(    37), -INT8_C(    99), -INT8_C(    53),  INT8_C(    39),
        -INT8_C(    81), -INT8_C(    58),  INT8_C(     7),  INT8_C(    89) },
         INT8_C(     1),
      {  INT32_C(  1248860228),  INT32_C(  1471721063),  INT32_C(  1999963824), -INT32_C(   199406017) } },
    { {  INT32_C(  1302043971), -INT32_C(  1235924853),  INT32_C(  1960335939), -INT32_C(  1860001080) },
      {  UINT8_C(   216),  UINT8_C(   155),  UINT8_C(    97),  UINT8_C(   246),
         UINT8_C(   174),  UINT8_C(    46),  UINT8_C(    30),  UINT8_C(    71),
         UINT8_C(   201),  UINT8_C(    28),  UINT8_C(    91),  UINT8_C(    99),
         UINT8_C(    58),  UINT8_C(   213),  UINT8_C(   103),  UINT8_C(   134) },
      { -INT8_C(    79),  INT8_C(    93), -INT8_C(    81),  INT8_C(    61),
         INT8_C(    64), -INT8_C(   119),  INT8_C(    98),  INT8_C(    11) },
         INT8_C(     1),
      {  INT32_C(  1302051562), -INT32_C(  1235915470),  INT32_C(  1960355478), -INT32_C(  1860011147) } },
    { { -INT32_C(  1892463965), -INT32_C(   625446338),  INT32_C(   727679099), -INT32_C(  1808884455) },
      {  UINT8_C(    82),  UINT8_C(    35),  UINT8_C(    81),  UINT8_C(   178),
         UINT8_C(    59),  UINT8_C(   172),  UINT8_C(   215),  UINT8_C(   195),
         UINT8_C(    25),  UINT8_C(   116),  UINT8_C(   197),  UINT8_C(    82),
         UINT8_C(   139),  UINT8_C(   154),  UINT8_C(   143),  UINT8_C(     4) },
      {  INT8_C(   122),  INT8_C(    56), -INT8_C(    20),  INT8_C(    50),
        -INT8_C(   115), -INT8_C(    36), -INT8_C(    39),  INT8_C(     0) },
         INT8_C(     0),
      { -INT32_C(  1892444721), -INT32_C(   625424058),  INT32_C(   727688805), -INT32_C(  1808861533) } },
    { { -INT32_C(  1285372112), -INT32_C(   636071391), -INT32_C(  1545950396), -INT32_C(   196359371) },
      {  UINT8_C(   251),  UINT8_C(    41),  UINT8_C(   220),  UINT8_C(   104),
         UINT8_C(    10),  UINT8_C(    56),  UINT8_C(    81),  UINT8_C(    11),
         UINT8_C(    77),  UINT8_C(    30),  UINT8_C(   218),  UINT8_C(    65),
         UINT8_C(    44),  UINT8_C(   158),  UINT8_C(     4),  UINT8_C(   155) },
      { -INT8_C(    35),  INT8_C(   118), -INT8_C(    53), -INT8_C(    73),
         INT8_C(   125), -INT8_C(    45), -INT8_C(   103), -INT8_C(   118) },
         INT8_C(     1),
      { -INT32_C(  1285377514), -INT32_C(   636082302), -INT32_C(  1545972245), -INT32_C(   196379683) } },
    { { -INT32_C(  1504168311), -INT32_C(  1503437355),  INT32_C(   508155423), -INT32_C(     6263594) },
      {  UINT8_C(   194),  UINT8_C(    95),  UINT8_C(    52),  UINT8_C(     9),
         UINT8_C(   212),  UINT8_C(     8),  UINT8_C(   103),  UINT8_C(    70),
         UINT8_C(    97),  UINT8_C(   186),  UINT8_C(    26),  UINT8_C(    92),
         UINT8_C(    82),  UINT8_C(     0),  UINT8_C(    31),  UINT8_C(   144) },
      {  INT8_C(    37), -INT8_C(    96), -INT8_C(    70), -INT8_C(    21),
         INT8_C(    25), -INT8_C(    32),  INT8_C(    84), -INT8_C(   128) },
         INT8_C(     0),
      { -INT32_C(  1504174082), -INT32_C(  1503438959),  INT32_C(   508137404), -INT32_C(     6265754) } },
    { { -INT32_C(  1462391466), -INT32_C(   330052889), -INT32_C(  1142375415),  INT32_C(   229405499) },
      {  UINT8_C(    24),  UINT8_C(    85),  UINT8_C(     6),  UINT8_C(     3),
         UINT8_C(   135),  UINT8_C(     1),  UINT8_C(   241),  UINT8_C(    74),
         UINT8_C(   162),  UINT8_C(     6),  UINT8_C(   125),  UINT8_C(   247),
         UINT8_C(   184),  UINT8_C(   108),  UINT8_C(   131),  UINT8_C(   140) },
      { -INT8_C(     4), -INT8_C(   121), -INT8_C(   108),  INT8_C(    43),
         INT8_C(    77), -INT8_C(    34), -INT8_C(    18),  INT8_C(    35) },
         INT8_C(     1),
      { -INT32_C(  1462392511), -INT32_C(   330044276), -INT32_C(  1142356750),  INT32_C(   229418537) } },
    { { -INT32_C(  1797891616),  INT32_C(   429237971),  INT32_C(  1462886797), -INT32_C(  1403546518) },
      {  UINT8_C(   166),  UINT8_C(    52),  UINT8_C(     1),  UINT8_C(   214),
         UINT8_C(   210),  UINT8_C(    66),  UINT8_C(   131),  UINT8_C(   136),
         UINT8_C(    64),  UINT8_C(    70),  UINT8_C(   154),  UINT8_C(   170),
         UINT8_C(   156),  UINT8_C(   141),  UINT8_C(    91),  UINT8_C(   213) },
      {  INT8_C(     5),  INT8_C(     4),  INT8_C(     1),  INT8_C(    68),
        -INT8_C(    53), -INT8_C(    26),  INT8_C(    47), -INT8_C(    81) },
         INT8_C(     1),
      { -INT32_C(  1797919053),  INT32_C(   429220266),  INT32_C(  1462875053), -INT32_C(  1403571428) } },
    { {  INT32_C(  2142921987),  INT32_C(  1602164253), -INT32_C(   826251604),  INT32_C(  1808634719) },
      {  UINT8_C(    16),  UINT8_C(    49),  UINT8_C(   195),  UINT8_C(   196),
         UINT8_C(    93),  UINT8_C(     4),  UINT8_C(   218),  UINT8_C(   126),
         UINT8_C(    82),  UINT8_C(   163),  UINT8_C(   203),  UINT8_C(    84),
         UINT8_C(   195),  UINT8_C(     5),  UINT8_C(   225),  UINT8_C(   234) },
      { -INT8_C(    88),  INT8_C(    79), -INT8_C(    98),  INT8_C(    41),
        -INT8_C(    62),  INT8_C(   101),  INT8_C(   122),  INT8_C(    64) },
         INT8_C(     0),
      {  INT32_C(  2142913376),  INT32_C(  1602140187), -INT32_C(   826262393),  INT32_C(  1808605498) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t r_ = simde_vld1q_s32(test_vec[i].r_);
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int32x4_t r;

    switch(test_vec[i].lane) {
      case 0: r = simde_vusdotq_lane_s32(r_, a, b, 0); break;
      case 1: r = simde_vusdotq_lane_s32(r_, a, b, 1); break;
      default: HEDLEY_UNREACHABLE(); r = r_; break;
    }

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t r_ = simde_test_arm_neon_random_i32x4();
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    int lane = simde_test_codegen_random_i8() & 1;
    simde_int32x4_t r;

    switch(test_vec[i].lane) {
      case 0: r = simde_vusdotq_lane_s32(r_, a, b, 0); break;
      case 1: r = simde_vusdotq_lane_s32(r_, a, b, 1); break;
      default: HEDLEY_UNREACHABLE(); r = r_; break;
    }

    simde_test_arm_neon_write_i32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vusdot_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vusdot_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vusdotq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vusdotq_lane_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
