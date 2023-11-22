#define SIMDE_TEST_ARM_NEON_INSN sudot_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/sudot_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vsudot_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    int8_t a[8];
    uint8_t b[8];
    const int lane;
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1746427822), -INT32_C(   172883253) },
      { -INT8_C(    32), -INT8_C(    42), -INT8_C(    91),  INT8_C(    36),
         INT8_C(   109),  INT8_C(    47),  INT8_C(   113), -INT8_C(     1) },
      {  UINT8_C(    26),  UINT8_C(   160),  UINT8_C(   179),  UINT8_C(   237),
         UINT8_C(   127),  UINT8_C(   151),  UINT8_C(   233),  UINT8_C(   226) },
         INT8_C(     1),
      {  INT32_C(  1746404349), -INT32_C(   172836210) } },
    { { -INT32_C(   412304248),  INT32_C(  1699310448) },
      {  INT8_C(    37), -INT8_C(     4),  INT8_C(   105), -INT8_C(   101),
        -INT8_C(    76),  INT8_C(   121),  INT8_C(    49),  INT8_C(   115) },
      {  UINT8_C(   242),  UINT8_C(   209),  UINT8_C(    36),  UINT8_C(   162),
         UINT8_C(   229),  UINT8_C(    33),  UINT8_C(   131),  UINT8_C(    23) },
         INT8_C(     0),
      { -INT32_C(   412308712),  INT32_C(  1699337739) } },
    { { -INT32_C(  1019130706),  INT32_C(   588302628) },
      { -INT8_C(    34),  INT8_C(    54),  INT8_C(    48), -INT8_C(    59),
        -INT8_C(    38),  INT8_C(    62),  INT8_C(    79), -INT8_C(    46) },
      {  UINT8_C(   188),  UINT8_C(   227),  UINT8_C(    27),  UINT8_C(    43),
         UINT8_C(   122),  UINT8_C(   183),  UINT8_C(   216),  UINT8_C(    80) },
         INT8_C(     0),
      { -INT32_C(  1019126081),  INT32_C(   588309713) } },
    { { -INT32_C(   592997691),  INT32_C(  1166358799) },
      { -INT8_C(   100),  INT8_C(   122),  INT8_C(   121), -INT8_C(   109),
         INT8_C(    54),  INT8_C(   104), -INT8_C(    41), -INT8_C(    65) },
      {  UINT8_C(    11),  UINT8_C(   146),  UINT8_C(     5),  UINT8_C(   226),
         UINT8_C(    85),  UINT8_C(   215),  UINT8_C(   110),  UINT8_C(   200) },
         INT8_C(     0),
      { -INT32_C(   593005008),  INT32_C(  1166359682) } },
    { {  INT32_C(   699507785),  INT32_C(   952849856) },
      {  INT8_C(    91), -INT8_C(    73),  INT8_C(    67),  INT8_C(   118),
         INT8_C(    38), -INT8_C(    67), -INT8_C(    49),  INT8_C(    30) },
      {  UINT8_C(    40),  UINT8_C(    55),  UINT8_C(    26),  UINT8_C(    68),
         UINT8_C(   231),  UINT8_C(   252),  UINT8_C(    37),  UINT8_C(   130) },
         INT8_C(     0),
      {  INT32_C(   699517176),  INT32_C(   952848457) } },
    { { -INT32_C(  1255660459),  INT32_C(   864512625) },
      {  INT8_C(   109), -INT8_C(    26),  INT8_C(     8), -INT8_C(    82),
         INT8_C(    91),  INT8_C(    31),  INT8_C(   123),  INT8_C(   114) },
      {  UINT8_C(    70),  UINT8_C(   218),  UINT8_C(   195),  UINT8_C(    13),
         UINT8_C(   122),  UINT8_C(   173),  UINT8_C(   221),  UINT8_C(    23) },
         INT8_C(     0),
      { -INT32_C(  1255658003),  INT32_C(   864551220) } },
    { {  INT32_C(    91962329), -INT32_C(     1299036) },
      {  INT8_C(   120), -INT8_C(    19),  INT8_C(    81), -INT8_C(    95),
         INT8_C(    22),  INT8_C(    83), -INT8_C(   113),  INT8_C(    44) },
      {  UINT8_C(    19),  UINT8_C(   162),  UINT8_C(   236),  UINT8_C(   213),
         UINT8_C(   255),  UINT8_C(    29),  UINT8_C(   242),  UINT8_C(     4) },
         INT8_C(     1),
      {  INT32_C(    92011600), -INT32_C(     1318189) } },
    { { -INT32_C(  1455506535),  INT32_C(  1434314182) },
      {  INT8_C(     8), -INT8_C(    55),  INT8_C(    23), -INT8_C(    93),
        -INT8_C(    89), -INT8_C(     8), -INT8_C(    89),  INT8_C(   122) },
      {  UINT8_C(    93),  UINT8_C(   247),  UINT8_C(   108),  UINT8_C(    87),
         UINT8_C(   213),  UINT8_C(   185),  UINT8_C(    56),  UINT8_C(   160) },
         INT8_C(     0),
      { -INT32_C(  1455524983),  INT32_C(  1434304931) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_int32x2_t r;

    SIMDE_CONSTIFY_2_(simde_vsudot_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), test_vec[i].lane, r_, a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    int lane = simde_test_codegen_random_i8() & 1;
    simde_int32x2_t r;

    SIMDE_CONSTIFY_2_(simde_vsudot_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), lane, r_, a, b);

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsudot_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    int8_t a[8];
    uint8_t b[16];
    const int lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1569711044),  INT32_C(   897345290) },
      { -INT8_C(    98),  INT8_C(   121), -INT8_C(    33),  INT8_C(     1),
         INT8_C(    53),  INT8_C(   105),  INT8_C(   100),  INT8_C(    42) },
      {  UINT8_C(    46),  UINT8_C(    32),  UINT8_C(   128),  UINT8_C(    65),
         UINT8_C(   166),  UINT8_C(   202),  UINT8_C(   223),  UINT8_C(    29),
         UINT8_C(     5),  UINT8_C(   239),  UINT8_C(   180),  UINT8_C(    37),
         UINT8_C(   116),  UINT8_C(    93),  UINT8_C(    57),  UINT8_C(    34) },
         INT8_C(     0),
      { -INT32_C(  1569715839),  INT32_C(   897366618) } },
    { {  INT32_C(   455271069), -INT32_C(   207819113) },
      {  INT8_C(     4),  INT8_C(    80),  INT8_C(    78), -INT8_C(   113),
        -INT8_C(    57), -INT8_C(   105), -INT8_C(     1),  INT8_C(    86) },
      {  UINT8_C(   141),  UINT8_C(    18),  UINT8_C(     5),  UINT8_C(    79),
         UINT8_C(    50),  UINT8_C(   159),  UINT8_C(   196),  UINT8_C(   163),
         UINT8_C(   237),  UINT8_C(   147),  UINT8_C(    44),  UINT8_C(    37),
         UINT8_C(   100),  UINT8_C(   163),  UINT8_C(   249),  UINT8_C(   207) },
         INT8_C(     1),
      {  INT32_C(   455280858), -INT32_C(   207824836) } },
    { { -INT32_C(  2079094342), -INT32_C(    55380981) },
      { -INT8_C(    94), -INT8_C(    20),  INT8_C(   107), -INT8_C(   103),
         INT8_C(    52),  INT8_C(    11), -INT8_C(   100),  INT8_C(     3) },
      {  UINT8_C(    33),  UINT8_C(   250),  UINT8_C(    20),  UINT8_C(    24),
         UINT8_C(    89),  UINT8_C(    86),  UINT8_C(   235),  UINT8_C(   190),
         UINT8_C(    11),  UINT8_C(   176),  UINT8_C(   251),  UINT8_C(    29),
         UINT8_C(   199),  UINT8_C(    70),  UINT8_C(   193),  UINT8_C(   122) },
         INT8_C(     3),
      { -INT32_C(  2079106363), -INT32_C(    55388797) } },
    { { -INT32_C(   856076632), -INT32_C(    75215751) },
      {  INT8_C(    27),  INT8_C(    62),  INT8_C(    84),  INT8_C(   118),
         INT8_C(    55),  INT8_C(   121),  INT8_C(   108), -INT8_C(    89) },
      {  UINT8_C(    40),  UINT8_C(   196),  UINT8_C(   205),  UINT8_C(   174),
         UINT8_C(   228),  UINT8_C(   122),  UINT8_C(    68),  UINT8_C(   113),
         UINT8_C(   175),  UINT8_C(   181),  UINT8_C(    43),  UINT8_C(   147),
         UINT8_C(    31),  UINT8_C(   103),  UINT8_C(   222),  UINT8_C(   250) },
         INT8_C(     0),
      { -INT32_C(   856025648), -INT32_C(    75183181) } },
    { {  INT32_C(  1151904917), -INT32_C(  1747265605) },
      {  INT8_C(    58),  INT8_C(    28),  INT8_C(     9), -INT8_C(   112),
         INT8_C(   114), -INT8_C(   104), -INT8_C(    66),  INT8_C(    10) },
      {  UINT8_C(   223),  UINT8_C(    82),  UINT8_C(    59),  UINT8_C(   151),
         UINT8_C(    30),  UINT8_C(   160),  UINT8_C(   133),  UINT8_C(    44),
         UINT8_C(   233),  UINT8_C(   100),  UINT8_C(   239),  UINT8_C(   242),
         UINT8_C(   253),  UINT8_C(   239),  UINT8_C(    52),  UINT8_C(   146) },
         INT8_C(     1),
      {  INT32_C(  1151907406), -INT32_C(  1747287163) } },
    { { -INT32_C(  1872162850), -INT32_C(  1272912446) },
      { -INT8_C(    91),  INT8_C(    83), -INT8_C(   112), -INT8_C(     2),
         INT8_C(    44),  INT8_C(    77),  INT8_C(    27), -INT8_C(    27) },
      {  UINT8_C(   235),  UINT8_C(    22),  UINT8_C(    23),  UINT8_C(    78),
         UINT8_C(   153),  UINT8_C(   109),  UINT8_C(   238),  UINT8_C(   176),
         UINT8_C(    66),  UINT8_C(   197),  UINT8_C(    38),  UINT8_C(   161),
         UINT8_C(    63),  UINT8_C(   156),  UINT8_C(     1),  UINT8_C(   190) },
         INT8_C(     3),
      { -INT32_C(  1872156127), -INT32_C(  1272902765) } },
    { {  INT32_C(   825642097), -INT32_C(   119632602) },
      {  INT8_C(    46), -INT8_C(    74), -INT8_C(   107),  INT8_C(    16),
         INT8_C(   125), -INT8_C(    69),  INT8_C(    63),  INT8_C(   106) },
      {  UINT8_C(   179),  UINT8_C(   200),  UINT8_C(   113),  UINT8_C(    71),
         UINT8_C(    13),  UINT8_C(   101),  UINT8_C(   111),  UINT8_C(    72),
         UINT8_C(   111),  UINT8_C(   137),  UINT8_C(   176),  UINT8_C(    71),
         UINT8_C(    19),  UINT8_C(   243),  UINT8_C(    66),  UINT8_C(   124) },
         INT8_C(     0),
      {  INT32_C(   825624576), -INT32_C(   119609382) } },
    { {  INT32_C(   461060612), -INT32_C(  1844979001) },
      { -INT8_C(   115),  INT8_C(   109), -INT8_C(    80),  INT8_C(    89),
        -INT8_C(    47),  INT8_C(    38),  INT8_C(   108),  INT8_C(    25) },
      {  UINT8_C(    83),  UINT8_C(    13),  UINT8_C(   243),  UINT8_C(   113),
         UINT8_C(    45),  UINT8_C(   200),  UINT8_C(    45),  UINT8_C(    82),
         UINT8_C(   253),  UINT8_C(   112),  UINT8_C(   241),  UINT8_C(    21),
         UINT8_C(    90),  UINT8_C(   180),  UINT8_C(   239),  UINT8_C(   106) },
         INT8_C(     0),
      {  INT32_C(   461043101), -INT32_C(  1844953339) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_int32x2_t r;

    SIMDE_CONSTIFY_4_(simde_vsudot_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), test_vec[i].lane, r_, a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    int lane = simde_test_codegen_random_i8() & 3;
    simde_int32x2_t r;

    SIMDE_CONSTIFY_4_(simde_vsudot_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), lane, r_, a, b);

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsudotq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[4];
    int8_t a[16];
    uint8_t b[16];
    const int lane;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   691840164),  INT32_C(  1325118926), -INT32_C(   392642501),  INT32_C(   270766250) },
      {  INT8_C(    17),  INT8_C(    72),  INT8_C(    11),  INT8_C(    46),
         INT8_C(    40), -INT8_C(    22), -INT8_C(     2), -INT8_C(    80),
        -INT8_C(     9),  INT8_C(   101), -INT8_C(     7),  INT8_C(    59),
        -INT8_C(    12), -INT8_C(    58), -INT8_C(    51),  INT8_C(    60) },
      {  UINT8_C(    67),  UINT8_C(   206),  UINT8_C(   115),  UINT8_C(   205),
         UINT8_C(   246),  UINT8_C(   128),  UINT8_C(   232),  UINT8_C(    73),
         UINT8_C(   221),  UINT8_C(    82),  UINT8_C(   186),  UINT8_C(   185),
         UINT8_C(     4),  UINT8_C(    42),  UINT8_C(   234),  UINT8_C(     7) },
         INT8_C(     0),
      { -INT32_C(   691813498),  INT32_C(  1325100444), -INT32_C(   392611008),  INT32_C(   270759933) } },
    { {  INT32_C(  2076536573),  INT32_C(  2072162487), -INT32_C(  2002829541), -INT32_C(   302800064) },
      { -INT8_C(    11),  INT8_C(    78),  INT8_C(    73),  INT8_C(    41),
        -INT8_C(    34),  INT8_C(   107), -INT8_C(    67),  INT8_C(    94),
         INT8_C(     4), -INT8_C(    71),  INT8_C(    87), -INT8_C(    11),
         INT8_C(    25), -INT8_C(    19),  INT8_C(    48),  INT8_C(     7) },
      {  UINT8_C(   183),  UINT8_C(   147),  UINT8_C(   234),  UINT8_C(   118),
         UINT8_C(   128),  UINT8_C(   104),  UINT8_C(    21),  UINT8_C(   220),
         UINT8_C(   208),  UINT8_C(     6),  UINT8_C(   189),  UINT8_C(    81),
         UINT8_C(   243),  UINT8_C(    16),  UINT8_C(   240),  UINT8_C(   208) },
         INT8_C(     0),
      {  INT32_C(  2076567946),  INT32_C(  2072167408), -INT32_C(  2002820186), -INT32_C(   302786224) } },
    { { -INT32_C(  1803361707),  INT32_C(   256526537), -INT32_C(   497753491), -INT32_C(  1981432674) },
      { -INT8_C(    79),  INT8_C(    57),  INT8_C(    72), -INT8_C(    55),
         INT8_C(    20), -INT8_C(    35),  INT8_C(    81), -INT8_C(   105),
        -INT8_C(   108), -INT8_C(    77), -INT8_C(   110),  INT8_C(    66),
         INT8_C(   119), -INT8_C(    20), -INT8_C(    40), -INT8_C(    56) },
      {  UINT8_C(   202),  UINT8_C(   178),  UINT8_C(    70),  UINT8_C(    44),
         UINT8_C(    30),  UINT8_C(   153),  UINT8_C(   185),  UINT8_C(   168),
         UINT8_C(   186),  UINT8_C(    59),  UINT8_C(   239),  UINT8_C(   106),
         UINT8_C(    47),  UINT8_C(     7),  UINT8_C(   253),  UINT8_C(    96) },
         INT8_C(     3),
      { -INT32_C(  1803352085),  INT32_C(   256537645), -INT32_C(   497780600), -INT32_C(  1981442717) } },
    { {  INT32_C(   297330475),  INT32_C(  1785621871),  INT32_C(  1264214942), -INT32_C(  1159146274) },
      {  INT8_C(    77), -INT8_C(    26),  INT8_C(    31),  INT8_C(    52),
        -INT8_C(    45), -INT8_C(    74), -INT8_C(    75),  INT8_C(     3),
        -INT8_C(   120),  INT8_C(    83), -INT8_C(    21), -INT8_C(    89),
         INT8_C(    83), -INT8_C(    95), -INT8_C(    54), -INT8_C(    79) },
      {  UINT8_C(     7),  UINT8_C(   253),  UINT8_C(    18),  UINT8_C(    49),
         UINT8_C(   223),  UINT8_C(   251),  UINT8_C(   154),  UINT8_C(   129),
         UINT8_C(   106),  UINT8_C(   124),  UINT8_C(   102),  UINT8_C(    39),
         UINT8_C(   238),  UINT8_C(    29),  UINT8_C(    75),  UINT8_C(   124) },
         INT8_C(     0),
      {  INT32_C(   297327542),  INT32_C(  1785601631),  INT32_C(  1264230362), -INT32_C(  1159174571) } },
    { { -INT32_C(  2118003248),  INT32_C(   276908175),  INT32_C(   844208131),  INT32_C(  1494786231) },
      { -INT8_C(    42),  INT8_C(    60),  INT8_C(   127),  INT8_C(    79),
        -INT8_C(    99),  INT8_C(    30),  INT8_C(    65), -INT8_C(    39),
         INT8_C(   114), -INT8_C(   127), -INT8_C(     9), -INT8_C(    56),
         INT8_C(     4), -INT8_C(    24), -INT8_C(    60),  INT8_C(    70) },
      {  UINT8_C(    72),  UINT8_C(    29),  UINT8_C(   184),  UINT8_C(   106),
         UINT8_C(     3),  UINT8_C(    97),  UINT8_C(    14),  UINT8_C(   205),
         UINT8_C(   201),  UINT8_C(    18),  UINT8_C(    76),  UINT8_C(    75),
         UINT8_C(   107),  UINT8_C(    73),  UINT8_C(   100),  UINT8_C(   175) },
         INT8_C(     2),
      { -INT32_C(  2117995033),  INT32_C(   276890831),  INT32_C(   844223875),  INT32_C(  1494787293) } },
    { { -INT32_C(   704566123),  INT32_C(  1867452691), -INT32_C(   439812216), -INT32_C(  1670017577) },
      {  INT8_C(    18), -INT8_C(    34),  INT8_C(     9), -INT8_C(     7),
        -INT8_C(    17), -INT8_C(    59), -INT8_C(    48), -INT8_C(    76),
         INT8_C(    69),  INT8_C(    88),  INT8_C(    70),  INT8_C(    31),
        -INT8_C(    11),  INT8_C(   104), -INT8_C(   122), -INT8_C(    90) },
      {  UINT8_C(    55),  UINT8_C(   184),  UINT8_C(   219),  UINT8_C(   195),
         UINT8_C(    50),  UINT8_C(    24),  UINT8_C(   230),  UINT8_C(   210),
         UINT8_C(   226),  UINT8_C(    79),  UINT8_C(    21),  UINT8_C(    51),
         UINT8_C(   254),  UINT8_C(   244),  UINT8_C(   190),  UINT8_C(   121) },
         INT8_C(     3),
      { -INT32_C(   704568984),  INT32_C(  1867415661), -INT32_C(   439756167), -INT32_C(  1670029065) } },
    { { -INT32_C(  1414281767),  INT32_C(   989802752),  INT32_C(  2031826256), -INT32_C(  1413877270) },
      { -INT8_C(    23), -INT8_C(    85), -INT8_C(    69), -INT8_C(    29),
        -INT8_C(    31), -INT8_C(    67),  INT8_C(    97), -INT8_C(   115),
        -INT8_C(    35), -INT8_C(   114),  INT8_C(    93), -INT8_C(   104),
        -INT8_C(    75), -INT8_C(    60), -INT8_C(    29), -INT8_C(    18) },
      {  UINT8_C(     9),  UINT8_C(    47),  UINT8_C(    97),  UINT8_C(    71),
         UINT8_C(    84),  UINT8_C(    86),  UINT8_C(    38),  UINT8_C(   239),
         UINT8_C(    92),  UINT8_C(   221),  UINT8_C(   120),  UINT8_C(    44),
         UINT8_C(   239),  UINT8_C(     5),  UINT8_C(    28),  UINT8_C(   188) },
         INT8_C(     1),
      { -INT32_C(  1414300562),  INT32_C(   989770587),  INT32_C(  2031792190), -INT32_C(  1413894134) } },
    { { -INT32_C(   122901847), -INT32_C(  1420641059),  INT32_C(  1582279753),  INT32_C(  1983240061) },
      { -INT8_C(    33), -INT8_C(    37), -INT8_C(    76),  INT8_C(   117),
        -INT8_C(   124),  INT8_C(     4), -INT8_C(     2), -INT8_C(    83),
         INT8_C(    81),  INT8_C(   108),  INT8_C(    48), -INT8_C(    84),
        -INT8_C(   122), -INT8_C(   106),  INT8_C(   117),  INT8_C(     7) },
      {  UINT8_C(   143),  UINT8_C(    41),  UINT8_C(   223),  UINT8_C(    63),
         UINT8_C(   196),  UINT8_C(   233),  UINT8_C(    55),  UINT8_C(   135),
         UINT8_C(   180),  UINT8_C(    75),  UINT8_C(     1),  UINT8_C(   170),
         UINT8_C(   144),  UINT8_C(    37),  UINT8_C(   176),  UINT8_C(   106) },
         INT8_C(     1),
      { -INT32_C(   122905321), -INT32_C(  1420675746),  INT32_C(  1582312093),  INT32_C(  1983198831) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t r_ = simde_vld1q_s32(test_vec[i].r_);
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_int32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vsudotq_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), test_vec[i].lane, r_, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t r_ = simde_test_arm_neon_random_i32x4();
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    int lane = simde_test_codegen_random_i8() & 3;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vsudotq_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), lane, r_, a, b);

    simde_test_arm_neon_write_i32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsudotq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[4];
    int8_t a[16];
    uint8_t b[8];
    const int lane;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1251913835),  INT32_C(  1423537763), -INT32_C(   208893737),  INT32_C(  1741144842) },
      {  INT8_C(     4),  INT8_C(    35), -INT8_C(   104), -INT8_C(    16),
         INT8_C(   114),  INT8_C(    61), -INT8_C(    91), -INT8_C(     9),
        -INT8_C(    74), -INT8_C(    73), -INT8_C(     7), -INT8_C(     9),
        -INT8_C(    52),  INT8_C(    97), -INT8_C(    99), -INT8_C(    25) },
      {  UINT8_C(    90),  UINT8_C(   134),  UINT8_C(   181),  UINT8_C(   107),
         UINT8_C(    22),  UINT8_C(   175),  UINT8_C(   222),  UINT8_C(   160) },
         INT8_C(     1),
      {  INT32_C(  1251894400),  INT32_C(  1423529304), -INT32_C(   208911134),  INT32_C(  1741134695) } },
    { { -INT32_C(   696783334), -INT32_C(   575493786), -INT32_C(  1709839296),  INT32_C(   385553589) },
      { -INT8_C(    85), -INT8_C(    27),  INT8_C(   111),  INT8_C(    88),
        -INT8_C(    24), -INT8_C(    40), -INT8_C(    31),  INT8_C(    27),
        -INT8_C(     2), -INT8_C(    24), -INT8_C(   116),  INT8_C(    94),
         INT8_C(   119), -INT8_C(     1),  INT8_C(    22), -INT8_C(    11) },
      {  UINT8_C(    29),  UINT8_C(   227),  UINT8_C(    80),  UINT8_C(   252),
         UINT8_C(     1),  UINT8_C(   110),  UINT8_C(   103),  UINT8_C(   239) },
         INT8_C(     0),
      { -INT32_C(   696760872), -INT32_C(   575499238), -INT32_C(  1709830394),  INT32_C(   385555801) } },
    { {  INT32_C(   179817799), -INT32_C(  1388957514),  INT32_C(  1778987653), -INT32_C(   708523362) },
      {  INT8_C(    41), -INT8_C(   103),  INT8_C(    78),  INT8_C(   113),
         INT8_C(    73),  INT8_C(    33), -INT8_C(    38),  INT8_C(    86),
         INT8_C(    78),  INT8_C(    34),  INT8_C(   124), -INT8_C(   107),
         INT8_C(    12), -INT8_C(    92), -INT8_C(     1), -INT8_C(    66) },
      {  UINT8_C(   215),  UINT8_C(   172),  UINT8_C(    15),  UINT8_C(   206),
         UINT8_C(     7),  UINT8_C(   118),  UINT8_C(   226),  UINT8_C(   221) },
         INT8_C(     0),
      {  INT32_C(   179833346), -INT32_C(  1388918997),  INT32_C(  1778990089), -INT32_C(   708550217) } },
    { { -INT32_C(   377826279),  INT32_C(   640633655), -INT32_C(  1571571179),  INT32_C(    86291244) },
      { -INT8_C(    31),  INT8_C(   115), -INT8_C(   105), -INT8_C(   117),
        -INT8_C(    37), -INT8_C(    80), -INT8_C(    98),  INT8_C(    81),
        -INT8_C(    57),  INT8_C(    92), -INT8_C(     7), -INT8_C(     4),
         INT8_C(    63),  INT8_C(    33), -INT8_C(     2), -INT8_C(   109) },
      {  UINT8_C(    40),  UINT8_C(   189),  UINT8_C(    76),  UINT8_C(   218),
         UINT8_C(    82),  UINT8_C(    91),  UINT8_C(   178),  UINT8_C(     7) },
         INT8_C(     0),
      { -INT32_C(   377839270),  INT32_C(   640627265), -INT32_C(  1571557475),  INT32_C(    86276087) } },
    { {  INT32_C(  1209123261), -INT32_C(  1317675986), -INT32_C(  1863977560),  INT32_C(  1270976176) },
      {  INT8_C(    20),  INT8_C(    43), -INT8_C(   122), -INT8_C(     8),
        -INT8_C(    57), -INT8_C(    64), -INT8_C(    40), -INT8_C(    88),
         INT8_C(    60), -INT8_C(   124), -INT8_C(    60),  INT8_C(   112),
        -INT8_C(    37),  INT8_C(    98), -INT8_C(    76), -INT8_C(   107) },
      {  UINT8_C(   181),  UINT8_C(    62),  UINT8_C(   244),  UINT8_C(    76),
         UINT8_C(   132),  UINT8_C(    15),  UINT8_C(   117),  UINT8_C(   238) },
         INT8_C(     0),
      {  INT32_C(  1209099171), -INT32_C(  1317706719), -INT32_C(  1863980516),  INT32_C(  1270948879) } },
    { {  INT32_C(  2060670316), -INT32_C(  1798601057), -INT32_C(  1620050932),  INT32_C(   846837852) },
      { -INT8_C(    40), -INT8_C(    94),  INT8_C(   125), -INT8_C(    57),
         INT8_C(    10), -INT8_C(   101), -INT8_C(    87), -INT8_C(    50),
        -INT8_C(    89), -INT8_C(     3), -INT8_C(    73), -INT8_C(    98),
         INT8_C(    59),  INT8_C(    20), -INT8_C(     6), -INT8_C(     2) },
      {  UINT8_C(   211),  UINT8_C(    43),  UINT8_C(    35),  UINT8_C(    84),
         UINT8_C(   156),  UINT8_C(    19),  UINT8_C(   206),  UINT8_C(   192) },
         INT8_C(     1),
      {  INT32_C(  2060677096), -INT32_C(  1798628938), -INT32_C(  1620098727),  INT32_C(   846845816) } },
    { { -INT32_C(  2045494305),  INT32_C(    65173318),  INT32_C(   772731482),  INT32_C(  1212156289) },
      { -INT8_C(    18), -INT8_C(    86),  INT8_C(    49),  INT8_C(    20),
         INT8_C(    83), -INT8_C(    91),  INT8_C(   114),  INT8_C(   105),
        -INT8_C(   125),  INT8_C(     5),  INT8_C(   123),  INT8_C(     6),
         INT8_C(    51),  INT8_C(    76),  INT8_C(    47), -INT8_C(   116) },
      {  UINT8_C(   169),  UINT8_C(   104),  UINT8_C(   139),  UINT8_C(   168),
         UINT8_C(    16),  UINT8_C(    96),  UINT8_C(    14),  UINT8_C(    51) },
         INT8_C(     1),
      { -INT32_C(  2045501143),  INT32_C(    65172861),  INT32_C(   772731990),  INT32_C(  1212159143) } },
    { {  INT32_C(   550170217),  INT32_C(   424218482), -INT32_C(  1171945609),  INT32_C(  1596319325) },
      {  INT8_C(     0),  INT8_C(    21), -INT8_C(    33), -INT8_C(    79),
        -INT8_C(    61), -INT8_C(    85),  INT8_C(    70),  INT8_C(    73),
         INT8_C(    59),  INT8_C(     6),  INT8_C(   117), -INT8_C(    91),
         INT8_C(    56), -INT8_C(    94),  INT8_C(    27), -INT8_C(    69) },
      {  UINT8_C(    12),  UINT8_C(   125),  UINT8_C(    58),  UINT8_C(   128),
         UINT8_C(   130),  UINT8_C(   113),  UINT8_C(    47),  UINT8_C(   188) },
         INT8_C(     0),
      {  INT32_C(   550160816),  INT32_C(   424220529), -INT32_C(  1171949013),  INT32_C(  1596300981) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t r_ = simde_vld1q_s32(test_vec[i].r_);
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_int32x4_t r;

    SIMDE_CONSTIFY_2_(simde_vsudotq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), test_vec[i].lane, r_, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t r_ = simde_test_arm_neon_random_i32x4();
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    int lane = simde_test_codegen_random_i8() & 1;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_2_(simde_vsudotq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), lane, r_, a, b);

    simde_test_arm_neon_write_i32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsudot_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsudot_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsudotq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsudotq_lane_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
