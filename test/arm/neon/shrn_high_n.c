#define SIMDE_TEST_ARM_NEON_INSN shrn_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/shrn_high_n.h"

static int
test_simde_vshrn_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t buf[8];
    int16_t a[8];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { {  INT8_C(     4),  INT8_C(     4), -INT8_C(    52),  INT8_C(    85),
        -INT8_C(    50),  INT8_C(    57), -INT8_C(   119),  INT8_C(    91) },
      { -INT16_C( 21391), -INT16_C( 23946), -INT16_C( 22087), -INT16_C( 25730),
         INT16_C(   498), -INT16_C( 31053),  INT16_C( 19870),  INT16_C( 16708) },
      {  INT8_C(     4),  INT8_C(     4), -INT8_C(    52),  INT8_C(    85),
        -INT8_C(    50),  INT8_C(    57), -INT8_C(   119),  INT8_C(    91),
         INT8_C(    56),  INT8_C(    59), -INT8_C(    36), -INT8_C(    65),
        -INT8_C(     7),  INT8_C(    89), -INT8_C(    49), -INT8_C(    94) },
      {  INT8_C(     4),  INT8_C(     4), -INT8_C(    52),  INT8_C(    85),
        -INT8_C(    50),  INT8_C(    57), -INT8_C(   119),  INT8_C(    91),
        -INT8_C(   114),  INT8_C(    78),  INT8_C(    55),  INT8_C(   111),
         INT8_C(    62), -INT8_C(    42), -INT8_C(    77),  INT8_C(    40) },
      {  INT8_C(     4),  INT8_C(     4), -INT8_C(    52),  INT8_C(    85),
        -INT8_C(    50),  INT8_C(    57), -INT8_C(   119),  INT8_C(    91),
         INT8_C(    99),  INT8_C(    19),  INT8_C(    77), -INT8_C(    37),
         INT8_C(    15),  INT8_C(    53),  INT8_C(   108),  INT8_C(    10) },
      {  INT8_C(     4),  INT8_C(     4), -INT8_C(    52),  INT8_C(    85),
        -INT8_C(    50),  INT8_C(    57), -INT8_C(   119),  INT8_C(    91),
        -INT8_C(    79), -INT8_C(   119), -INT8_C(    90),  INT8_C(   109),
         INT8_C(     7),  INT8_C(    26),  INT8_C(    54),  INT8_C(     5) },
      {  INT8_C(     4),  INT8_C(     4), -INT8_C(    52),  INT8_C(    85),
        -INT8_C(    50),  INT8_C(    57), -INT8_C(   119),  INT8_C(    91),
        -INT8_C(    84), -INT8_C(    94), -INT8_C(    87), -INT8_C(   101),
         INT8_C(     1), -INT8_C(   122),  INT8_C(    77),  INT8_C(    65) } },
    { { -INT8_C(     7),  INT8_C(    73), -INT8_C(    96),  INT8_C(   102),
         INT8_C(     6), -INT8_C(    98),  INT8_C(    92), -INT8_C(    75) },
      { -INT16_C( 26860),  INT16_C( 21526), -INT16_C( 27229), -INT16_C( 21570),
         INT16_C(  2118), -INT16_C(  9299),  INT16_C( 19231), -INT16_C(  5294) },
      { -INT8_C(     7),  INT8_C(    73), -INT8_C(    96),  INT8_C(   102),
         INT8_C(     6), -INT8_C(    98),  INT8_C(    92), -INT8_C(    75),
        -INT8_C(   118),  INT8_C(    11), -INT8_C(    47), -INT8_C(    33),
         INT8_C(    35), -INT8_C(    42), -INT8_C(   113), -INT8_C(    87) },
      { -INT8_C(     7),  INT8_C(    73), -INT8_C(    96),  INT8_C(   102),
         INT8_C(     6), -INT8_C(    98),  INT8_C(    92), -INT8_C(    75),
        -INT8_C(    30), -INT8_C(   126), -INT8_C(    76),  INT8_C(   119),
         INT8_C(     8),  INT8_C(   117),  INT8_C(    99),  INT8_C(   106) },
      { -INT8_C(     7),  INT8_C(    73), -INT8_C(    96),  INT8_C(   102),
         INT8_C(     6), -INT8_C(    98),  INT8_C(    92), -INT8_C(    75),
        -INT8_C(    72), -INT8_C(    96), -INT8_C(    83),  INT8_C(    93),
         INT8_C(    66), -INT8_C(    35),  INT8_C(    88),  INT8_C(    90) },
      { -INT8_C(     7),  INT8_C(    73), -INT8_C(    96),  INT8_C(   102),
         INT8_C(     6), -INT8_C(    98),  INT8_C(    92), -INT8_C(    75),
         INT8_C(    92),  INT8_C(    80),  INT8_C(    86), -INT8_C(    82),
         INT8_C(    33),  INT8_C(   110),  INT8_C(    44), -INT8_C(    83) },
      { -INT8_C(     7),  INT8_C(    73), -INT8_C(    96),  INT8_C(   102),
         INT8_C(     6), -INT8_C(    98),  INT8_C(    92), -INT8_C(    75),
        -INT8_C(   105),  INT8_C(    84), -INT8_C(   107), -INT8_C(    85),
         INT8_C(     8), -INT8_C(    37),  INT8_C(    75), -INT8_C(    21) } },
    { { -INT8_C(    52),  INT8_C(    13), -INT8_C(   100), -INT8_C(    38),
        -INT8_C(    11), -INT8_C(    30), -INT8_C(    42),  INT8_C(    42) },
      { -INT16_C( 22379),  INT16_C( 16993),  INT16_C( 28434),  INT16_C( 15331),
        -INT16_C( 15593), -INT16_C( 31168),  INT16_C( 27542),  INT16_C( 14238) },
      { -INT8_C(    52),  INT8_C(    13), -INT8_C(   100), -INT8_C(    38),
        -INT8_C(    11), -INT8_C(    30), -INT8_C(    42),  INT8_C(    42),
         INT8_C(    74),  INT8_C(    48), -INT8_C(   119), -INT8_C(    15),
        -INT8_C(   117),  INT8_C(    32), -INT8_C(    53), -INT8_C(    49) },
      { -INT8_C(    52),  INT8_C(    13), -INT8_C(   100), -INT8_C(    38),
        -INT8_C(    11), -INT8_C(    30), -INT8_C(    42),  INT8_C(    42),
         INT8_C(    18),  INT8_C(    76), -INT8_C(    30),  INT8_C(   124),
         INT8_C(    98), -INT8_C(    56),  INT8_C(   114), -INT8_C(    13) },
      { -INT8_C(    52),  INT8_C(    13), -INT8_C(   100), -INT8_C(    38),
        -INT8_C(    11), -INT8_C(    30), -INT8_C(    42),  INT8_C(    42),
         INT8_C(    68),  INT8_C(    19),  INT8_C(   120), -INT8_C(    33),
         INT8_C(    24),  INT8_C(    50),  INT8_C(    92), -INT8_C(    68) },
      { -INT8_C(    52),  INT8_C(    13), -INT8_C(   100), -INT8_C(    38),
        -INT8_C(    11), -INT8_C(    30), -INT8_C(    42),  INT8_C(    42),
        -INT8_C(    94),  INT8_C(     9), -INT8_C(    68), -INT8_C(    17),
         INT8_C(    12),  INT8_C(    25), -INT8_C(    82), -INT8_C(    34) },
      { -INT8_C(    52),  INT8_C(    13), -INT8_C(   100), -INT8_C(    38),
        -INT8_C(    11), -INT8_C(    30), -INT8_C(    42),  INT8_C(    42),
        -INT8_C(    88),  INT8_C(    66),  INT8_C(   111),  INT8_C(    59),
        -INT8_C(    61), -INT8_C(   122),  INT8_C(   107),  INT8_C(    55) } },
    { {  INT8_C(    80),          INT8_MIN, -INT8_C(    84),  INT8_C(    74),
         INT8_C(    31),  INT8_C(    50),  INT8_C(     4), -INT8_C(    64) },
      { -INT16_C(  5104),  INT16_C(   255), -INT16_C(  5125), -INT16_C(  2103),
        -INT16_C( 16458), -INT16_C( 19995),  INT16_C( 21784), -INT16_C( 21905) },
      {  INT8_C(    80),          INT8_MIN, -INT8_C(    84),  INT8_C(    74),
         INT8_C(    31),  INT8_C(    50),  INT8_C(     4), -INT8_C(    64),
         INT8_C(     8),          INT8_MAX, -INT8_C(     3), -INT8_C(    28),
        -INT8_C(    37), -INT8_C(    14), -INT8_C(   116),  INT8_C(    55) },
      {  INT8_C(    80),          INT8_MIN, -INT8_C(    84),  INT8_C(    74),
         INT8_C(    31),  INT8_C(    50),  INT8_C(     4), -INT8_C(    64),
        -INT8_C(   126),  INT8_C(    31),          INT8_MAX, -INT8_C(     7),
        -INT8_C(    10),  INT8_C(    60), -INT8_C(    93),  INT8_C(    77) },
      {  INT8_C(    80),          INT8_MIN, -INT8_C(    84),  INT8_C(    74),
         INT8_C(    31),  INT8_C(    50),  INT8_C(     4), -INT8_C(    64),
         INT8_C(    96),  INT8_C(     7),  INT8_C(    95), -INT8_C(    66),
        -INT8_C(     3), -INT8_C(   113), -INT8_C(    88),  INT8_C(    83) },
      {  INT8_C(    80),          INT8_MIN, -INT8_C(    84),  INT8_C(    74),
         INT8_C(    31),  INT8_C(    50),  INT8_C(     4), -INT8_C(    64),
        -INT8_C(    80),  INT8_C(     3), -INT8_C(    81), -INT8_C(    33),
        -INT8_C(     2), -INT8_C(    57),  INT8_C(    84), -INT8_C(    87) },
      {  INT8_C(    80),          INT8_MIN, -INT8_C(    84),  INT8_C(    74),
         INT8_C(    31),  INT8_C(    50),  INT8_C(     4), -INT8_C(    64),
        -INT8_C(    20),  INT8_C(     0), -INT8_C(    21), -INT8_C(     9),
        -INT8_C(    65), -INT8_C(    79),  INT8_C(    85), -INT8_C(    86) } },
    { {  INT8_C(    54),  INT8_C(    29), -INT8_C(    27), -INT8_C(    33),
         INT8_C(    85),  INT8_C(    48), -INT8_C(   121), -INT8_C(    42) },
      {  INT16_C( 23251),  INT16_C(  4749),  INT16_C( 17750),  INT16_C(  9704),
        -INT16_C(  9616), -INT16_C( 11101),  INT16_C( 10812),  INT16_C(  3568) },
      {  INT8_C(    54),  INT8_C(    29), -INT8_C(    27), -INT8_C(    33),
         INT8_C(    85),  INT8_C(    48), -INT8_C(   121), -INT8_C(    42),
         INT8_C(   105),  INT8_C(    70), -INT8_C(    85), -INT8_C(    12),
         INT8_C(    56),  INT8_C(    81),  INT8_C(    30), -INT8_C(     8) },
      {  INT8_C(    54),  INT8_C(    29), -INT8_C(    27), -INT8_C(    33),
         INT8_C(    85),  INT8_C(    48), -INT8_C(   121), -INT8_C(    42),
         INT8_C(    90),  INT8_C(    81), -INT8_C(    86), -INT8_C(    67),
         INT8_C(    78), -INT8_C(   108),  INT8_C(    71), -INT8_C(    66) },
      {  INT8_C(    54),  INT8_C(    29), -INT8_C(    27), -INT8_C(    33),
         INT8_C(    85),  INT8_C(    48), -INT8_C(   121), -INT8_C(    42),
        -INT8_C(    42), -INT8_C(   108),  INT8_C(    42),  INT8_C(    47),
        -INT8_C(    45), -INT8_C(    91),  INT8_C(    81),  INT8_C(   111) },
      {  INT8_C(    54),  INT8_C(    29), -INT8_C(    27), -INT8_C(    33),
         INT8_C(    85),  INT8_C(    48), -INT8_C(   121), -INT8_C(    42),
         INT8_C(   107),  INT8_C(    74),  INT8_C(    21), -INT8_C(   105),
         INT8_C(   105),  INT8_C(    82), -INT8_C(    88),  INT8_C(    55) },
      {  INT8_C(    54),  INT8_C(    29), -INT8_C(    27), -INT8_C(    33),
         INT8_C(    85),  INT8_C(    48), -INT8_C(   121), -INT8_C(    42),
         INT8_C(    90),  INT8_C(    18),  INT8_C(    69),  INT8_C(    37),
        -INT8_C(    38), -INT8_C(    44),  INT8_C(    42),  INT8_C(    13) } },
    { {  INT8_C(   106),  INT8_C(    76), -INT8_C(    98),  INT8_C(    81),
        -INT8_C(    61), -INT8_C(    47),  INT8_C(    33), -INT8_C(    92) },
      {  INT16_C( 28089),  INT16_C( 22423), -INT16_C(  5586),  INT16_C( 11303),
         INT16_C( 31895),  INT16_C(  5979), -INT16_C( 18596), -INT16_C( 17573) },
      {  INT8_C(   106),  INT8_C(    76), -INT8_C(    98),  INT8_C(    81),
        -INT8_C(    61), -INT8_C(    47),  INT8_C(    33), -INT8_C(    92),
        -INT8_C(    36), -INT8_C(    53),  INT8_C(    23),  INT8_C(    19),
         INT8_C(    75), -INT8_C(    83), -INT8_C(    82), -INT8_C(    83) },
      {  INT8_C(   106),  INT8_C(    76), -INT8_C(    98),  INT8_C(    81),
        -INT8_C(    61), -INT8_C(    47),  INT8_C(    33), -INT8_C(    92),
        -INT8_C(    73), -INT8_C(    14),  INT8_C(    69), -INT8_C(   124),
        -INT8_C(   110), -INT8_C(    21), -INT8_C(    21),  INT8_C(   107) },
      {  INT8_C(   106),  INT8_C(    76), -INT8_C(    98),  INT8_C(    81),
        -INT8_C(    61), -INT8_C(    47),  INT8_C(    33), -INT8_C(    92),
         INT8_C(   109), -INT8_C(    68),  INT8_C(    81),  INT8_C(    97),
        -INT8_C(    28), -INT8_C(    70), -INT8_C(    70), -INT8_C(    38) },
      {  INT8_C(   106),  INT8_C(    76), -INT8_C(    98),  INT8_C(    81),
        -INT8_C(    61), -INT8_C(    47),  INT8_C(    33), -INT8_C(    92),
        -INT8_C(    74),  INT8_C(    94), -INT8_C(    88), -INT8_C(    80),
        -INT8_C(    14),  INT8_C(    93), -INT8_C(    35), -INT8_C(    19) },
      {  INT8_C(   106),  INT8_C(    76), -INT8_C(    98),  INT8_C(    81),
        -INT8_C(    61), -INT8_C(    47),  INT8_C(    33), -INT8_C(    92),
         INT8_C(   109),  INT8_C(    87), -INT8_C(    22),  INT8_C(    44),
         INT8_C(   124),  INT8_C(    23), -INT8_C(    73), -INT8_C(    69) } },
    { { -INT8_C(    68),  INT8_C(    16), -INT8_C(   115),  INT8_C(    37),
         INT8_C(   124), -INT8_C(    68), -INT8_C(    86), -INT8_C(   109) },
      { -INT16_C( 28940),  INT16_C( 10438),  INT16_C(  7456), -INT16_C( 26170),
         INT16_C( 24715),  INT16_C(   484), -INT16_C( 21976), -INT16_C( 17844) },
      { -INT8_C(    68),  INT8_C(    16), -INT8_C(   115),  INT8_C(    37),
         INT8_C(   124), -INT8_C(    68), -INT8_C(    86), -INT8_C(   109),
         INT8_C(   122),  INT8_C(    99), -INT8_C(   112), -INT8_C(    29),
         INT8_C(    69), -INT8_C(    14),  INT8_C(    20),  INT8_C(    38) },
      { -INT8_C(    68),  INT8_C(    16), -INT8_C(   115),  INT8_C(    37),
         INT8_C(   124), -INT8_C(    68), -INT8_C(    86), -INT8_C(   109),
        -INT8_C(    34),  INT8_C(    24), -INT8_C(    92),  INT8_C(    56),
         INT8_C(    17),  INT8_C(    60),  INT8_C(    69),  INT8_C(    73) },
      { -INT8_C(    68),  INT8_C(    16), -INT8_C(   115),  INT8_C(    37),
         INT8_C(   124), -INT8_C(    68), -INT8_C(    86), -INT8_C(   109),
         INT8_C(   119),  INT8_C(    70), -INT8_C(    23), -INT8_C(    50),
         INT8_C(     4),  INT8_C(    15),  INT8_C(    81), -INT8_C(    46) },
      { -INT8_C(    68),  INT8_C(    16), -INT8_C(   115),  INT8_C(    37),
         INT8_C(   124), -INT8_C(    68), -INT8_C(    86), -INT8_C(   109),
         INT8_C(    59), -INT8_C(    93),  INT8_C(   116),  INT8_C(   103),
        -INT8_C(   126),  INT8_C(     7), -INT8_C(    88), -INT8_C(    23) },
      { -INT8_C(    68),  INT8_C(    16), -INT8_C(   115),  INT8_C(    37),
         INT8_C(   124), -INT8_C(    68), -INT8_C(    86), -INT8_C(   109),
        -INT8_C(   114),  INT8_C(    40),  INT8_C(    29), -INT8_C(   103),
         INT8_C(    96),  INT8_C(     1), -INT8_C(    86), -INT8_C(    70) } },
    { { -INT8_C(   118), -INT8_C(    89),          INT8_MAX, -INT8_C(    54),
         INT8_C(    86),  INT8_C(     4), -INT8_C(    67),  INT8_C(    43) },
      {  INT16_C( 30356), -INT16_C(  7766), -INT16_C( 27871), -INT16_C( 22195),
        -INT16_C(  6310),  INT16_C(  4197),  INT16_C(  5611), -INT16_C( 23638) },
      { -INT8_C(   118), -INT8_C(    89),          INT8_MAX, -INT8_C(    54),
         INT8_C(    86),  INT8_C(     4), -INT8_C(    67),  INT8_C(    43),
         INT8_C(    74), -INT8_C(    43), -INT8_C(   112), -INT8_C(    90),
        -INT8_C(    83),  INT8_C(    50), -INT8_C(    11), -INT8_C(    43) },
      { -INT8_C(   118), -INT8_C(    89),          INT8_MAX, -INT8_C(    54),
         INT8_C(    86),  INT8_C(     4), -INT8_C(    67),  INT8_C(    43),
        -INT8_C(    46),  INT8_C(    53),  INT8_C(   100),  INT8_C(    41),
        -INT8_C(    21),  INT8_C(    12), -INT8_C(    67),  INT8_C(   117) },
      { -INT8_C(   118), -INT8_C(    89),          INT8_MAX, -INT8_C(    54),
         INT8_C(    86),  INT8_C(     4), -INT8_C(    67),  INT8_C(    43),
        -INT8_C(    76),  INT8_C(    13), -INT8_C(   103),  INT8_C(    74),
         INT8_C(    58), -INT8_C(   125), -INT8_C(    81),  INT8_C(    29) },
      { -INT8_C(   118), -INT8_C(    89),          INT8_MAX, -INT8_C(    54),
         INT8_C(    86),  INT8_C(     4), -INT8_C(    67),  INT8_C(    43),
        -INT8_C(    38), -INT8_C(   122),  INT8_C(    76), -INT8_C(    91),
        -INT8_C(    99),  INT8_C(    65),  INT8_C(    87), -INT8_C(   114) },
      { -INT8_C(   118), -INT8_C(    89),          INT8_MAX, -INT8_C(    54),
         INT8_C(    86),  INT8_C(     4), -INT8_C(    67),  INT8_C(    43),
         INT8_C(   118), -INT8_C(    31), -INT8_C(   109), -INT8_C(    87),
        -INT8_C(    25),  INT8_C(    16),  INT8_C(    21), -INT8_C(    93) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t buf = simde_vld1_s8(test_vec[i].buf);
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int8x16_t r1 = simde_vshrn_high_n_s16(buf, a, 1);
    simde_int8x16_t r3 = simde_vshrn_high_n_s16(buf, a, 3);
    simde_int8x16_t r5 = simde_vshrn_high_n_s16(buf, a, 5);
    simde_int8x16_t r6 = simde_vshrn_high_n_s16(buf, a, 6);
    simde_int8x16_t r8 = simde_vshrn_high_n_s16(buf, a, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t buf = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t r1 = simde_vshrn_high_n_s16(buf, a, 1);
    simde_int8x16_t r3 = simde_vshrn_high_n_s16(buf, a, 3);
    simde_int8x16_t r5 = simde_vshrn_high_n_s16(buf, a, 5);
    simde_int8x16_t r6 = simde_vshrn_high_n_s16(buf, a, 6);
    simde_int8x16_t r8 = simde_vshrn_high_n_s16(buf, a, 8);

    simde_test_arm_neon_write_i8x8(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshrn_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t buf[4];
    int32_t a[4];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { { -INT16_C(      48), -INT16_C(    7945),  INT16_C(   14173), -INT16_C(    8823) },
      {  INT32_C(649728449),  INT32_C(187908990), -INT32_C(860677280), -INT32_C(1466532669) },
      { -INT16_C(      48), -INT16_C(    7945),  INT16_C(   14173), -INT16_C(    8823),
         INT16_C(   16952),  INT16_C(   26735),  INT16_C(   25452), -INT16_C(   12392) },
      { -INT16_C(      48), -INT16_C(    7945),  INT16_C(   14173), -INT16_C(    8823),
        -INT16_C(    6073), -INT16_C(   13043), -INT16_C(   13203),  INT16_C(   23027) },
      { -INT16_C(      48), -INT16_C(    7945),  INT16_C(   14173), -INT16_C(    8823),
        -INT16_C(   20860), -INT16_C(   13104),  INT16_C(   11462),  INT16_C(    9631) },
      { -INT16_C(      48), -INT16_C(    7945),  INT16_C(   14173), -INT16_C(    8823),
         INT16_C(   13776),  INT16_C(   22938),  INT16_C(   26008),  INT16_C(   17587) },
      { -INT16_C(      48), -INT16_C(    7945),  INT16_C(   14173), -INT16_C(    8823),
         INT16_C(    9914),  INT16_C(    2867), -INT16_C(   13133), -INT16_C(   22378) } },
    { {  INT16_C(   32599),  INT16_C(    1930),  INT16_C(    7233),  INT16_C(   12791) },
      { -INT32_C(117986509), -INT32_C(1407057442),  INT32_C(1842877402),  INT32_C(317679098) },
      {  INT16_C(   32599),  INT16_C(    1930),  INT16_C(    7233),  INT16_C(   12791),
        -INT16_C(    2714),  INT16_C(   16443),  INT16_C(     635), -INT16_C(    4929) },
      {  INT16_C(   32599),  INT16_C(    1930),  INT16_C(    7233),  INT16_C(   12791),
        -INT16_C(    8532), -INT16_C(   30713),  INT16_C(   24655), -INT16_C(   17001) },
      {  INT16_C(   32599),  INT16_C(    1930),  INT16_C(    7233),  INT16_C(   12791),
         INT16_C(   15850),  INT16_C(    2176),  INT16_C(   30212), -INT16_C(   17447) },
      {  INT16_C(   32599),  INT16_C(    1930),  INT16_C(    7233),  INT16_C(   12791),
        -INT16_C(   14403),  INT16_C(   24848),  INT16_C(   28352), -INT16_C(   26757) },
      {  INT16_C(   32599),  INT16_C(    1930),  INT16_C(    7233),  INT16_C(   12791),
        -INT16_C(    1801), -INT16_C(   21470),  INT16_C(   28120),  INT16_C(    4847) } },
    { {  INT16_C(   18808),  INT16_C(    5150), -INT16_C(    2766), -INT16_C(    6088) },
      { -INT32_C(915682702), -INT32_C(1306333468),  INT32_C(193063199),  INT32_C(1625931947) },
      {  INT16_C(   18808),  INT16_C(    5150), -INT16_C(    2766), -INT16_C(    6088),
         INT16_C(   31054),  INT16_C(   24028),  INT16_C(   15651),  INT16_C(   14357) },
      {  INT16_C(   18808),  INT16_C(    5150), -INT16_C(    2766), -INT16_C(    6088),
        -INT16_C(   20695), -INT16_C(   29765),  INT16_C(    1956), -INT16_C(   22782) },
      {  INT16_C(   18808),  INT16_C(    5150), -INT16_C(    2766), -INT16_C(    6088),
         INT16_C(   23282), -INT16_C(   30533), -INT16_C(    8070),  INT16_C(   14960) },
      {  INT16_C(   18808),  INT16_C(    5150), -INT16_C(    2766), -INT16_C(    6088),
         INT16_C(   19294), -INT16_C(   28393),  INT16_C(   23567),  INT16_C(    1870) },
      {  INT16_C(   18808),  INT16_C(    5150), -INT16_C(    2766), -INT16_C(    6088),
        -INT16_C(   13973), -INT16_C(   19934),  INT16_C(    2945),  INT16_C(   24809) } },
    { { -INT16_C(    3711), -INT16_C(    2351), -INT16_C(   15123), -INT16_C(    1005) },
      { -INT32_C(381159154), -INT32_C(1703985404), -INT32_C(1982873473),  INT32_C(2075672613) },
      { -INT16_C(    3711), -INT16_C(    2351), -INT16_C(   15123), -INT16_C(    1005),
        -INT16_C(     223), -INT16_C(    6176), -INT16_C(    2033),  INT16_C(    2052) },
      { -INT16_C(    3711), -INT16_C(    2351), -INT16_C(   15123), -INT16_C(    1005),
         INT16_C(    8164), -INT16_C(   17156),  INT16_C(   16129), -INT16_C(    7936) },
      { -INT16_C(    3711), -INT16_C(    2351), -INT16_C(   15123), -INT16_C(    1005),
         INT16_C(   20990), -INT16_C(   25649),  INT16_C(   29680), -INT16_C(    4592) },
      { -INT16_C(    3711), -INT16_C(    2351), -INT16_C(   15123), -INT16_C(    1005),
         INT16_C(   19007), -INT16_C(   11399),  INT16_C(   20094), -INT16_C(    8766) },
      { -INT16_C(    3711), -INT16_C(    2351), -INT16_C(   15123), -INT16_C(    1005),
        -INT16_C(    5817), -INT16_C(   26001), -INT16_C(   30257),  INT16_C(   31672) } },
    { { -INT16_C(   25014),  INT16_C(   18775), -INT16_C(   23395),  INT16_C(   29476) },
      {  INT32_C(2109500016),  INT32_C(975966207), -INT32_C(1098282935), -INT32_C(1897126880) },
      { -INT16_C(   25014),  INT16_C(   18775), -INT16_C(   23395),  INT16_C(   29476),
        -INT16_C(   29362), -INT16_C(   32257),  INT16_C(   12553), -INT16_C(   31612) },
      { -INT16_C(   25014),  INT16_C(   18775), -INT16_C(   23395),  INT16_C(   29476),
        -INT16_C(    3671), -INT16_C(   20417),  INT16_C(    9761), -INT16_C(   20336) },
      { -INT16_C(   25014),  INT16_C(   18775), -INT16_C(   23395),  INT16_C(   29476),
         INT16_C(   28442), -INT16_C(   29949), -INT16_C(   23966), -INT16_C(   17655) },
      { -INT16_C(   25014),  INT16_C(   18775), -INT16_C(   23395),  INT16_C(   29476),
        -INT16_C(    4637), -INT16_C(   11936), -INT16_C(    2996),  INT16_C(   30561) },
      { -INT16_C(   25014),  INT16_C(   18775), -INT16_C(   23395),  INT16_C(   29476),
         INT16_C(   32188),  INT16_C(   14892), -INT16_C(   16759), -INT16_C(   28948) } },
    { {  INT16_C(   29520),  INT16_C(    8468), -INT16_C(   25117),  INT16_C(      18) },
      { -INT32_C(278251920),  INT32_C(1652530519),  INT32_C(31863375),  INT32_C(1380598969) },
      {  INT16_C(   29520),  INT16_C(    8468), -INT16_C(   25117),  INT16_C(      18),
         INT16_C(   18126), -INT16_C(    3158), -INT16_C(   14775),  INT16_C(   18583) },
      {  INT16_C(   29520),  INT16_C(    8468), -INT16_C(   25117),  INT16_C(      18),
        -INT16_C(   22311), -INT16_C(     395), -INT16_C(   26423),  INT16_C(   10514) },
      {  INT16_C(   29520),  INT16_C(    8468), -INT16_C(   25117),  INT16_C(      18),
        -INT16_C(    9587), -INT16_C(   24601),  INT16_C(   31116), -INT16_C(   28015) },
      {  INT16_C(   29520),  INT16_C(    8468), -INT16_C(   25117),  INT16_C(      18),
         INT16_C(   31569),  INT16_C(    5116),  INT16_C(    3889), -INT16_C(   28078) },
      {  INT16_C(   29520),  INT16_C(    8468), -INT16_C(   25117),  INT16_C(      18),
        -INT16_C(    4246),  INT16_C(   25215),  INT16_C(     486),  INT16_C(   21066) } },
    { { -INT16_C(    5195), -INT16_C(   26115), -INT16_C(   24650), -INT16_C(     245) },
      { -INT32_C(1486019498), -INT32_C(696822790),  INT32_C(233311932),  INT32_C(784741266) },
      { -INT16_C(    5195), -INT16_C(   26115), -INT16_C(   24650), -INT16_C(     245),
        -INT16_C(   23414), -INT16_C(    5505),  INT16_C(     471), -INT16_C(   14734) },
      { -INT16_C(    5195), -INT16_C(   26115), -INT16_C(   24650), -INT16_C(     245),
        -INT16_C(   19311), -INT16_C(    8881), -INT16_C(   24518),  INT16_C(    6350) },
      { -INT16_C(    5195), -INT16_C(   26115), -INT16_C(   24650), -INT16_C(     245),
        -INT16_C(    9399), -INT16_C(   25132),  INT16_C(   31235), -INT16_C(   20084) },
      { -INT16_C(    5195), -INT16_C(   26115), -INT16_C(   24650), -INT16_C(     245),
         INT16_C(   15209), -INT16_C(   19526),  INT16_C(   28480),  INT16_C(   30257) },
      { -INT16_C(    5195), -INT16_C(   26115), -INT16_C(   24650), -INT16_C(     245),
        -INT16_C(   22675), -INT16_C(   10633),  INT16_C(    3560),  INT16_C(   11974) } },
    { {  INT16_C(   21295),  INT16_C(   21992),  INT16_C(   25898),  INT16_C(   10692) },
      {  INT32_C(1605177114), -INT32_C(1518801172),  INT32_C(414021998),  INT32_C(394545542) },
      {  INT16_C(   21295),  INT16_C(   21992),  INT16_C(   25898),  INT16_C(   10692),
        -INT16_C(   24093),  INT16_C(    7645), -INT16_C(   20691), -INT16_C(   30416) },
      {  INT16_C(   21295),  INT16_C(   21992),  INT16_C(   25898),  INT16_C(   10692),
        -INT16_C(   19396), -INT16_C(    7237), -INT16_C(   18971),  INT16_C(    4390) },
      {  INT16_C(   21295),  INT16_C(   21992),  INT16_C(   25898),  INT16_C(   10692),
        -INT16_C(    5309),  INT16_C(   24123),  INT16_C(   11102), -INT16_C(    7918) },
      {  INT16_C(   21295),  INT16_C(   21992),  INT16_C(   25898),  INT16_C(   10692),
        -INT16_C(     664),  INT16_C(   11207), -INT16_C(   14997), -INT16_C(   17374) },
      {  INT16_C(   21295),  INT16_C(   21992),  INT16_C(   25898),  INT16_C(   10692),
         INT16_C(   24493), -INT16_C(   23176),  INT16_C(    6317),  INT16_C(    6020) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t buf = simde_vld1_s16(test_vec[i].buf);
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int16x8_t r3 = simde_vshrn_high_n_s32(buf, a, 3);
    simde_int16x8_t r6 = simde_vshrn_high_n_s32(buf, a, 6);
    simde_int16x8_t r10 = simde_vshrn_high_n_s32(buf, a, 10);
    simde_int16x8_t r13 = simde_vshrn_high_n_s32(buf, a, 13);
    simde_int16x8_t r16 = simde_vshrn_high_n_s32(buf, a, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t buf = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t r3 = simde_vshrn_high_n_s32(buf, a, 3);
    simde_int16x8_t r6 = simde_vshrn_high_n_s32(buf, a, 6);
    simde_int16x8_t r10 = simde_vshrn_high_n_s32(buf, a, 10);
    simde_int16x8_t r13 = simde_vshrn_high_n_s32(buf, a, 13);
    simde_int16x8_t r16 = simde_vshrn_high_n_s32(buf, a, 16);

    simde_test_arm_neon_write_i16x4(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshrn_high_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t buf[2];
    int64_t a[2];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { {  INT32_C(  1831811615),  INT32_C(  1909993683) },
      {  INT64_C(3848900880038201545),  INT64_C(980726150430347609) },
      {  INT32_C(  1831811615),  INT32_C(  1909993683), -INT32_C(   720800221), -INT32_C(   211199675) },
      {  INT32_C(  1831811615),  INT32_C(  1909993683),  INT32_C(  1470763756), -INT32_C(   370748750) },
      {  INT32_C(  1831811615),  INT32_C(  1909993683),  INT32_C(  1096722507), -INT32_C(  2019058870) },
      {  INT32_C(  1831811615),  INT32_C(  1909993683),  INT32_C(  1518517584),  INT32_C(  1729056566) },
      {  INT32_C(  1831811615),  INT32_C(  1909993683),  INT32_C(   896142069),  INT32_C(   228343100) } },
    { {  INT32_C(  1482402525), -INT32_C(   801014428) },
      { -INT64_C(4550218625910016639), -INT64_C(3222766049638850449) },
      {  INT32_C(  1482402525), -INT32_C(   801014428),  INT32_C(   306254294),  INT32_C(  1766087041) },
      {  INT32_C(  1482402525), -INT32_C(   801014428),  INT32_C(    35947043),  INT32_C(  2060617907) },
      {  INT32_C(  1482402525), -INT32_C(   801014428),  INT32_C(  1275630088), -INT32_C(   840218078) },
      {  INT32_C(  1482402525), -INT32_C(   801014428),  INT32_C(   915935524), -INT32_C(   778316140) },
      {  INT32_C(  1482402525), -INT32_C(   801014428), -INT32_C(  1059430332), -INT32_C(   750358694) } },
    { {  INT32_C(   711607607), -INT32_C(   160990569) },
      { -INT64_C(6410064084774018944), -INT64_C(1633492799541629751) },
      {  INT32_C(   711607607), -INT32_C(   160990569), -INT32_C(  1256310654), -INT32_C(   800020813) },
      {  INT32_C(   711607607), -INT32_C(   160990569),  INT32_C(    90848369),  INT32_C(  1470144845) },
      {  INT32_C(   711607607), -INT32_C(   160990569),  INT32_C(  1544923377), -INT32_C(  1788968315) },
      {  INT32_C(   711607607), -INT32_C(   160990569), -INT32_C(  1028117679),  INT32_C(  1428864261) },
      {  INT32_C(   711607607), -INT32_C(   160990569), -INT32_C(  1492459347), -INT32_C(   380327180) } },
    { { -INT32_C(   422073418), -INT32_C(  2071753080) },
      {  INT64_C(1849436684767047534),  INT64_C(3046959061727464262) },
      { -INT32_C(   422073418), -INT32_C(  2071753080),  INT32_C(  1993897661),  INT32_C(  2115875117) },
      { -INT32_C(   422073418), -INT32_C(  2071753080),  INT32_C(   653111533), -INT32_C(   922993822) },
      { -INT32_C(   422073418), -INT32_C(  2071753080),  INT32_C(  1352382147),  INT32_C(   522449133) },
      { -INT32_C(   422073418), -INT32_C(  2071753080),  INT32_C(  1788950381), -INT32_C(  1841412127) },
      { -INT32_C(   422073418), -INT32_C(  2071753080),  INT32_C(   430605533),  INT32_C(   709425439) } },
    { { -INT32_C(  1184439398), -INT32_C(  1653441787) },
      { -INT64_C(4954884085295485795), -INT64_C(6135092310840383808) },
      { -INT32_C(  1184439398), -INT32_C(  1653441787), -INT32_C(  1262295118),  INT32_C(   831554459) },
      { -INT32_C(  1184439398), -INT32_C(  1653441787), -INT32_C(  1184266801),  INT32_C(   811802887) },
      { -INT32_C(  1184439398), -INT32_C(  1653441787), -INT32_C(  1763334633),  INT32_C(  2025950340) },
      { -INT32_C(  1184439398), -INT32_C(  1653441787), -INT32_C(   819082420), -INT32_C(  1225686247) },
      { -INT32_C(  1184439398), -INT32_C(  1653441787), -INT32_C(  1153648851), -INT32_C(  1428437492) } },
    { { -INT32_C(  1846622157),  INT32_C(  2132573496) },
      { -INT64_C(8927100867917365759),  INT64_C(2738560408581552852) },
      { -INT32_C(  1846622157),  INT32_C(  2132573496),  INT32_C(  1003933944), -INT32_C(  1166684437) },
      { -INT32_C(  1846622157),  INT32_C(  2132573496), -INT32_C(  2005422687), -INT32_C(  1854608483) },
      { -INT32_C(  1846622157),  INT32_C(  2132573496), -INT32_C(  1843274058),  INT32_C(   709219246) },
      { -INT32_C(  1846622157),  INT32_C(  2132573496),  INT32_C(   119817149), -INT32_C(  2141942873) },
      { -INT32_C(  1846622157),  INT32_C(  2132573496), -INT32_C(  2078502642),  INT32_C(   637620782) } },
    { {  INT32_C(  2092918304), -INT32_C(  1978749922) },
      { -INT64_C(7321436896795428317), -INT64_C(804570278585527854) },
      {  INT32_C(  2092918304), -INT32_C(  1978749922), -INT32_C(  1151055896),  INT32_C(  1622166087) },
      {  INT32_C(  2092918304), -INT32_C(  1978749922),  INT32_C(  1064749199), -INT32_C(  1128177516) },
      {  INT32_C(  2092918304), -INT32_C(  1978749922), -INT32_C(  1593976030), -INT32_C(  1292696190) },
      {  INT32_C(  2092918304), -INT32_C(  1978749922), -INT32_C(  1723728970),  INT32_C(   895870475) },
      {  INT32_C(  2092918304), -INT32_C(  1978749922), -INT32_C(  1704654866), -INT32_C(   187328616) } },
    { {  INT32_C(  2046053710), -INT32_C(     5503424) },
      { -INT64_C(4105113832410876988), -INT64_C(3371315775392703809) },
      {  INT32_C(  2046053710), -INT32_C(     5503424), -INT32_C(   528323121), -INT32_C(  1472712598) },
      {  INT32_C(  2046053710), -INT32_C(     5503424), -INT32_C(  1514076965),  INT32_C(  1901097056) },
      {  INT32_C(  2046053710), -INT32_C(     5503424), -INT32_C(   157875181), -INT32_C(   708492863) },
      {  INT32_C(  2046053710), -INT32_C(     5503424), -INT32_C(  1041420792),  INT32_C(  1303087747) },
      {  INT32_C(  2046053710), -INT32_C(     5503424), -INT32_C(   955796296), -INT32_C(   784945622) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t buf = simde_vld1_s32(test_vec[i].buf);
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int32x4_t r6 = simde_vshrn_high_n_s64(buf, a, 6);
    simde_int32x4_t r13 = simde_vshrn_high_n_s64(buf, a, 13);
    simde_int32x4_t r19 = simde_vshrn_high_n_s64(buf, a, 19);
    simde_int32x4_t r26 = simde_vshrn_high_n_s64(buf, a, 26);
    simde_int32x4_t r32 = simde_vshrn_high_n_s64(buf, a, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t buf = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t r6 = simde_vshrn_high_n_s64(buf, a, 6);
    simde_int32x4_t r13 = simde_vshrn_high_n_s64(buf, a, 13);
    simde_int32x4_t r19 = simde_vshrn_high_n_s64(buf, a, 19);
    simde_int32x4_t r26 = simde_vshrn_high_n_s64(buf, a, 26);
    simde_int32x4_t r32 = simde_vshrn_high_n_s64(buf, a, 32);

    simde_test_arm_neon_write_i32x2(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshrn_high_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t buf[8];
    uint16_t a[8];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { {  UINT8_C(   164),  UINT8_C(   226),  UINT8_C(    50),  UINT8_C(   166),
         UINT8_C(   138),  UINT8_C(    42),  UINT8_C(    73),  UINT8_C(   124) },
      {  UINT16_C( 29220),  UINT16_C( 64872),  UINT16_C(  9164),  UINT16_C(  4092),
         UINT16_C( 28272),  UINT16_C( 38593),  UINT16_C( 16408),  UINT16_C( 56986) },
      {  UINT8_C(   164),  UINT8_C(   226),  UINT8_C(    50),  UINT8_C(   166),
         UINT8_C(   138),  UINT8_C(    42),  UINT8_C(    73),  UINT8_C(   124),
         UINT8_C(    18),  UINT8_C(   180),  UINT8_C(   230),  UINT8_C(   254),
         UINT8_C(    56),  UINT8_C(    96),  UINT8_C(    12),  UINT8_C(    77) },
      {  UINT8_C(   164),  UINT8_C(   226),  UINT8_C(    50),  UINT8_C(   166),
         UINT8_C(   138),  UINT8_C(    42),  UINT8_C(    73),  UINT8_C(   124),
         UINT8_C(    68),  UINT8_C(   173),  UINT8_C(   121),         UINT8_MAX,
         UINT8_C(   206),  UINT8_C(   216),  UINT8_C(     3),  UINT8_C(   211) },
      {  UINT8_C(   164),  UINT8_C(   226),  UINT8_C(    50),  UINT8_C(   166),
         UINT8_C(   138),  UINT8_C(    42),  UINT8_C(    73),  UINT8_C(   124),
         UINT8_C(   145),  UINT8_C(   235),  UINT8_C(    30),  UINT8_C(   127),
         UINT8_C(   115),  UINT8_C(   182),  UINT8_C(     0),  UINT8_C(   244) },
      {  UINT8_C(   164),  UINT8_C(   226),  UINT8_C(    50),  UINT8_C(   166),
         UINT8_C(   138),  UINT8_C(    42),  UINT8_C(    73),  UINT8_C(   124),
         UINT8_C(   200),  UINT8_C(   245),  UINT8_C(   143),  UINT8_C(    63),
         UINT8_C(   185),  UINT8_C(    91),  UINT8_C(     0),  UINT8_C(   122) },
      {  UINT8_C(   164),  UINT8_C(   226),  UINT8_C(    50),  UINT8_C(   166),
         UINT8_C(   138),  UINT8_C(    42),  UINT8_C(    73),  UINT8_C(   124),
         UINT8_C(   114),  UINT8_C(   253),  UINT8_C(    35),  UINT8_C(    15),
         UINT8_C(   110),  UINT8_C(   150),  UINT8_C(    64),  UINT8_C(   222) } },
    { {  UINT8_C(   222),  UINT8_C(   242),  UINT8_C(    50),  UINT8_C(   181),
         UINT8_C(   191),  UINT8_C(   126),  UINT8_C(   182),  UINT8_C(    10) },
      {  UINT16_C( 61757),  UINT16_C( 38396),  UINT16_C( 33166),  UINT16_C(  1449),
         UINT16_C( 23269),  UINT16_C( 11440),  UINT16_C( 50587),  UINT16_C( 51786) },
      {  UINT8_C(   222),  UINT8_C(   242),  UINT8_C(    50),  UINT8_C(   181),
         UINT8_C(   191),  UINT8_C(   126),  UINT8_C(   182),  UINT8_C(    10),
         UINT8_C(   158),  UINT8_C(   254),  UINT8_C(   199),  UINT8_C(   212),
         UINT8_C(   114),  UINT8_C(    88),  UINT8_C(   205),  UINT8_C(    37) },
      {  UINT8_C(   222),  UINT8_C(   242),  UINT8_C(    50),  UINT8_C(   181),
         UINT8_C(   191),  UINT8_C(   126),  UINT8_C(   182),  UINT8_C(    10),
         UINT8_C(    39),  UINT8_C(   191),  UINT8_C(    49),  UINT8_C(   181),
         UINT8_C(    92),  UINT8_C(   150),  UINT8_C(   179),  UINT8_C(    73) },
      {  UINT8_C(   222),  UINT8_C(   242),  UINT8_C(    50),  UINT8_C(   181),
         UINT8_C(   191),  UINT8_C(   126),  UINT8_C(   182),  UINT8_C(    10),
         UINT8_C(   137),  UINT8_C(   175),  UINT8_C(    12),  UINT8_C(    45),
         UINT8_C(   215),  UINT8_C(   101),  UINT8_C(    44),  UINT8_C(    82) },
      {  UINT8_C(   222),  UINT8_C(   242),  UINT8_C(    50),  UINT8_C(   181),
         UINT8_C(   191),  UINT8_C(   126),  UINT8_C(   182),  UINT8_C(    10),
         UINT8_C(   196),  UINT8_C(    87),  UINT8_C(     6),  UINT8_C(    22),
         UINT8_C(   107),  UINT8_C(   178),  UINT8_C(    22),  UINT8_C(    41) },
      {  UINT8_C(   222),  UINT8_C(   242),  UINT8_C(    50),  UINT8_C(   181),
         UINT8_C(   191),  UINT8_C(   126),  UINT8_C(   182),  UINT8_C(    10),
         UINT8_C(   241),  UINT8_C(   149),  UINT8_C(   129),  UINT8_C(     5),
         UINT8_C(    90),  UINT8_C(    44),  UINT8_C(   197),  UINT8_C(   202) } },
    { {  UINT8_C(   194),  UINT8_C(   221),  UINT8_C(   227),  UINT8_C(    20),
         UINT8_C(   120),  UINT8_C(   207),  UINT8_C(   101),  UINT8_C(    93) },
      {  UINT16_C( 50751),  UINT16_C( 12331),  UINT16_C( 61856),  UINT16_C( 43029),
         UINT16_C( 17246),  UINT16_C( 54951),  UINT16_C( 28426),  UINT16_C( 23982) },
      {  UINT8_C(   194),  UINT8_C(   221),  UINT8_C(   227),  UINT8_C(    20),
         UINT8_C(   120),  UINT8_C(   207),  UINT8_C(   101),  UINT8_C(    93),
         UINT8_C(    31),  UINT8_C(    21),  UINT8_C(   208),  UINT8_C(    10),
         UINT8_C(   175),  UINT8_C(    83),  UINT8_C(   133),  UINT8_C(   215) },
      {  UINT8_C(   194),  UINT8_C(   221),  UINT8_C(   227),  UINT8_C(    20),
         UINT8_C(   120),  UINT8_C(   207),  UINT8_C(   101),  UINT8_C(    93),
         UINT8_C(   199),  UINT8_C(     5),  UINT8_C(    52),  UINT8_C(     2),
         UINT8_C(   107),  UINT8_C(   212),  UINT8_C(   225),  UINT8_C(   181) },
      {  UINT8_C(   194),  UINT8_C(   221),  UINT8_C(   227),  UINT8_C(    20),
         UINT8_C(   120),  UINT8_C(   207),  UINT8_C(   101),  UINT8_C(    93),
         UINT8_C(    49),  UINT8_C(   129),  UINT8_C(   141),  UINT8_C(    64),
         UINT8_C(    26),  UINT8_C(   181),  UINT8_C(   120),  UINT8_C(   237) },
      {  UINT8_C(   194),  UINT8_C(   221),  UINT8_C(   227),  UINT8_C(    20),
         UINT8_C(   120),  UINT8_C(   207),  UINT8_C(   101),  UINT8_C(    93),
         UINT8_C(    24),  UINT8_C(   192),  UINT8_C(   198),  UINT8_C(   160),
         UINT8_C(    13),  UINT8_C(    90),  UINT8_C(   188),  UINT8_C(   118) },
      {  UINT8_C(   194),  UINT8_C(   221),  UINT8_C(   227),  UINT8_C(    20),
         UINT8_C(   120),  UINT8_C(   207),  UINT8_C(   101),  UINT8_C(    93),
         UINT8_C(   198),  UINT8_C(    48),  UINT8_C(   241),  UINT8_C(   168),
         UINT8_C(    67),  UINT8_C(   214),  UINT8_C(   111),  UINT8_C(    93) } },
    { {  UINT8_C(   125),  UINT8_C(    58),  UINT8_C(   193),  UINT8_C(     2),
         UINT8_C(   183),  UINT8_C(   157),  UINT8_C(   207),  UINT8_C(   174) },
      {  UINT16_C( 20393),  UINT16_C( 38827),  UINT16_C( 32065),  UINT16_C( 23882),
         UINT16_C( 63778),  UINT16_C( 36652),  UINT16_C( 64754),  UINT16_C(  6301) },
      {  UINT8_C(   125),  UINT8_C(    58),  UINT8_C(   193),  UINT8_C(     2),
         UINT8_C(   183),  UINT8_C(   157),  UINT8_C(   207),  UINT8_C(   174),
         UINT8_C(   212),  UINT8_C(   213),  UINT8_C(   160),  UINT8_C(   165),
         UINT8_C(   145),  UINT8_C(   150),  UINT8_C(   121),  UINT8_C(    78) },
      {  UINT8_C(   125),  UINT8_C(    58),  UINT8_C(   193),  UINT8_C(     2),
         UINT8_C(   183),  UINT8_C(   157),  UINT8_C(   207),  UINT8_C(   174),
         UINT8_C(   245),  UINT8_C(   245),  UINT8_C(   168),  UINT8_C(   169),
         UINT8_C(    36),  UINT8_C(   229),  UINT8_C(   158),  UINT8_C(    19) },
      {  UINT8_C(   125),  UINT8_C(    58),  UINT8_C(   193),  UINT8_C(     2),
         UINT8_C(   183),  UINT8_C(   157),  UINT8_C(   207),  UINT8_C(   174),
         UINT8_C(   125),  UINT8_C(   189),  UINT8_C(   234),  UINT8_C(   234),
         UINT8_C(   201),  UINT8_C(   121),  UINT8_C(   231),  UINT8_C(   196) },
      {  UINT8_C(   125),  UINT8_C(    58),  UINT8_C(   193),  UINT8_C(     2),
         UINT8_C(   183),  UINT8_C(   157),  UINT8_C(   207),  UINT8_C(   174),
         UINT8_C(    62),  UINT8_C(    94),  UINT8_C(   245),  UINT8_C(   117),
         UINT8_C(   228),  UINT8_C(    60),  UINT8_C(   243),  UINT8_C(    98) },
      {  UINT8_C(   125),  UINT8_C(    58),  UINT8_C(   193),  UINT8_C(     2),
         UINT8_C(   183),  UINT8_C(   157),  UINT8_C(   207),  UINT8_C(   174),
         UINT8_C(    79),  UINT8_C(   151),  UINT8_C(   125),  UINT8_C(    93),
         UINT8_C(   249),  UINT8_C(   143),  UINT8_C(   252),  UINT8_C(    24) } },
    { {  UINT8_C(     7),  UINT8_C(   207),  UINT8_C(   175),  UINT8_C(   160),
         UINT8_C(    48),  UINT8_C(     2),  UINT8_C(    42),  UINT8_C(   103) },
      {  UINT16_C( 44059),  UINT16_C( 51201),  UINT16_C( 17211),  UINT16_C(  7477),
         UINT16_C( 37362),  UINT16_C( 30215),  UINT16_C( 41476),  UINT16_C( 44824) },
      {  UINT8_C(     7),  UINT8_C(   207),  UINT8_C(   175),  UINT8_C(   160),
         UINT8_C(    48),  UINT8_C(     2),  UINT8_C(    42),  UINT8_C(   103),
         UINT8_C(    13),  UINT8_C(     0),  UINT8_C(   157),  UINT8_C(   154),
         UINT8_C(   249),  UINT8_C(     3),  UINT8_C(     2),  UINT8_C(   140) },
      {  UINT8_C(     7),  UINT8_C(   207),  UINT8_C(   175),  UINT8_C(   160),
         UINT8_C(    48),  UINT8_C(     2),  UINT8_C(    42),  UINT8_C(   103),
         UINT8_C(   131),  UINT8_C(     0),  UINT8_C(   103),  UINT8_C(   166),
         UINT8_C(    62),  UINT8_C(   192),  UINT8_C(    64),  UINT8_C(   227) },
      {  UINT8_C(     7),  UINT8_C(   207),  UINT8_C(   175),  UINT8_C(   160),
         UINT8_C(    48),  UINT8_C(     2),  UINT8_C(    42),  UINT8_C(   103),
         UINT8_C(    96),  UINT8_C(    64),  UINT8_C(    25),  UINT8_C(   233),
         UINT8_C(   143),  UINT8_C(   176),  UINT8_C(    16),  UINT8_C(   120) },
      {  UINT8_C(     7),  UINT8_C(   207),  UINT8_C(   175),  UINT8_C(   160),
         UINT8_C(    48),  UINT8_C(     2),  UINT8_C(    42),  UINT8_C(   103),
         UINT8_C(   176),  UINT8_C(    32),  UINT8_C(    12),  UINT8_C(   116),
         UINT8_C(    71),  UINT8_C(   216),  UINT8_C(   136),  UINT8_C(   188) },
      {  UINT8_C(     7),  UINT8_C(   207),  UINT8_C(   175),  UINT8_C(   160),
         UINT8_C(    48),  UINT8_C(     2),  UINT8_C(    42),  UINT8_C(   103),
         UINT8_C(   172),  UINT8_C(   200),  UINT8_C(    67),  UINT8_C(    29),
         UINT8_C(   145),  UINT8_C(   118),  UINT8_C(   162),  UINT8_C(   175) } },
    { {  UINT8_C(   162),  UINT8_C(    89),  UINT8_C(    33),  UINT8_C(   171),
         UINT8_C(    66),  UINT8_C(   149),  UINT8_C(    40),  UINT8_C(   220) },
      {  UINT16_C(  8331),  UINT16_C( 26863),  UINT16_C( 62973),  UINT16_C( 61971),
         UINT16_C( 10410),  UINT16_C( 15803),  UINT16_C(  7039),  UINT16_C( 19471) },
      {  UINT8_C(   162),  UINT8_C(    89),  UINT8_C(    33),  UINT8_C(   171),
         UINT8_C(    66),  UINT8_C(   149),  UINT8_C(    40),  UINT8_C(   220),
         UINT8_C(    69),  UINT8_C(   119),  UINT8_C(   254),  UINT8_C(     9),
         UINT8_C(    85),  UINT8_C(   221),  UINT8_C(   191),  UINT8_C(     7) },
      {  UINT8_C(   162),  UINT8_C(    89),  UINT8_C(    33),  UINT8_C(   171),
         UINT8_C(    66),  UINT8_C(   149),  UINT8_C(    40),  UINT8_C(   220),
         UINT8_C(    17),  UINT8_C(    29),  UINT8_C(   191),  UINT8_C(    66),
         UINT8_C(    21),  UINT8_C(   183),  UINT8_C(   111),  UINT8_C(   129) },
      {  UINT8_C(   162),  UINT8_C(    89),  UINT8_C(    33),  UINT8_C(   171),
         UINT8_C(    66),  UINT8_C(   149),  UINT8_C(    40),  UINT8_C(   220),
         UINT8_C(     4),  UINT8_C(    71),  UINT8_C(   175),  UINT8_C(   144),
         UINT8_C(    69),  UINT8_C(   237),  UINT8_C(   219),  UINT8_C(    96) },
      {  UINT8_C(   162),  UINT8_C(    89),  UINT8_C(    33),  UINT8_C(   171),
         UINT8_C(    66),  UINT8_C(   149),  UINT8_C(    40),  UINT8_C(   220),
         UINT8_C(   130),  UINT8_C(   163),  UINT8_C(   215),  UINT8_C(   200),
         UINT8_C(   162),  UINT8_C(   246),  UINT8_C(   109),  UINT8_C(    48) },
      {  UINT8_C(   162),  UINT8_C(    89),  UINT8_C(    33),  UINT8_C(   171),
         UINT8_C(    66),  UINT8_C(   149),  UINT8_C(    40),  UINT8_C(   220),
         UINT8_C(    32),  UINT8_C(   104),  UINT8_C(   245),  UINT8_C(   242),
         UINT8_C(    40),  UINT8_C(    61),  UINT8_C(    27),  UINT8_C(    76) } },
    { {  UINT8_C(   240),  UINT8_C(    88),  UINT8_C(    71),  UINT8_C(    91),
         UINT8_C(    94),  UINT8_C(   150),  UINT8_C(    62),  UINT8_C(   252) },
      {  UINT16_C( 11303),  UINT16_C(  6529),  UINT16_C( 34188),  UINT16_C( 43886),
         UINT16_C( 20544),  UINT16_C( 18905),  UINT16_C(  2306),  UINT16_C( 27402) },
      {  UINT8_C(   240),  UINT8_C(    88),  UINT8_C(    71),  UINT8_C(    91),
         UINT8_C(    94),  UINT8_C(   150),  UINT8_C(    62),  UINT8_C(   252),
         UINT8_C(    19),  UINT8_C(   192),  UINT8_C(   198),  UINT8_C(   183),
         UINT8_C(    32),  UINT8_C(   236),  UINT8_C(   129),  UINT8_C(   133) },
      {  UINT8_C(   240),  UINT8_C(    88),  UINT8_C(    71),  UINT8_C(    91),
         UINT8_C(    94),  UINT8_C(   150),  UINT8_C(    62),  UINT8_C(   252),
         UINT8_C(   132),  UINT8_C(    48),  UINT8_C(   177),  UINT8_C(   109),
         UINT8_C(     8),  UINT8_C(    59),  UINT8_C(    32),  UINT8_C(    97) },
      {  UINT8_C(   240),  UINT8_C(    88),  UINT8_C(    71),  UINT8_C(    91),
         UINT8_C(    94),  UINT8_C(   150),  UINT8_C(    62),  UINT8_C(   252),
         UINT8_C(    97),  UINT8_C(   204),  UINT8_C(    44),  UINT8_C(    91),
         UINT8_C(   130),  UINT8_C(    78),  UINT8_C(    72),  UINT8_C(    88) },
      {  UINT8_C(   240),  UINT8_C(    88),  UINT8_C(    71),  UINT8_C(    91),
         UINT8_C(    94),  UINT8_C(   150),  UINT8_C(    62),  UINT8_C(   252),
         UINT8_C(   176),  UINT8_C(   102),  UINT8_C(    22),  UINT8_C(   173),
         UINT8_C(    65),  UINT8_C(    39),  UINT8_C(    36),  UINT8_C(   172) },
      {  UINT8_C(   240),  UINT8_C(    88),  UINT8_C(    71),  UINT8_C(    91),
         UINT8_C(    94),  UINT8_C(   150),  UINT8_C(    62),  UINT8_C(   252),
         UINT8_C(    44),  UINT8_C(    25),  UINT8_C(   133),  UINT8_C(   171),
         UINT8_C(    80),  UINT8_C(    73),  UINT8_C(     9),  UINT8_C(   107) } },
    { {  UINT8_C(   141),  UINT8_C(   127),  UINT8_C(   249),  UINT8_C(   123),
         UINT8_C(    22),  UINT8_C(   137),  UINT8_C(   229),  UINT8_C(    67) },
      {  UINT16_C(  5000),  UINT16_C( 35905),  UINT16_C( 41323),  UINT16_C( 42284),
         UINT16_C(   765),  UINT16_C( 47799),  UINT16_C( 10446),  UINT16_C( 52113) },
      {  UINT8_C(   141),  UINT8_C(   127),  UINT8_C(   249),  UINT8_C(   123),
         UINT8_C(    22),  UINT8_C(   137),  UINT8_C(   229),  UINT8_C(    67),
         UINT8_C(   196),  UINT8_C(    32),  UINT8_C(   181),  UINT8_C(   150),
         UINT8_C(   126),  UINT8_C(    91),  UINT8_C(   103),  UINT8_C(   200) },
      {  UINT8_C(   141),  UINT8_C(   127),  UINT8_C(   249),  UINT8_C(   123),
         UINT8_C(    22),  UINT8_C(   137),  UINT8_C(   229),  UINT8_C(    67),
         UINT8_C(   113),  UINT8_C(   136),  UINT8_C(    45),  UINT8_C(   165),
         UINT8_C(    95),  UINT8_C(    86),  UINT8_C(    25),  UINT8_C(   114) },
      {  UINT8_C(   141),  UINT8_C(   127),  UINT8_C(   249),  UINT8_C(   123),
         UINT8_C(    22),  UINT8_C(   137),  UINT8_C(   229),  UINT8_C(    67),
         UINT8_C(   156),  UINT8_C(    98),  UINT8_C(    11),  UINT8_C(    41),
         UINT8_C(    23),  UINT8_C(   213),  UINT8_C(    70),  UINT8_C(    92) },
      {  UINT8_C(   141),  UINT8_C(   127),  UINT8_C(   249),  UINT8_C(   123),
         UINT8_C(    22),  UINT8_C(   137),  UINT8_C(   229),  UINT8_C(    67),
         UINT8_C(    78),  UINT8_C(    49),  UINT8_C(   133),  UINT8_C(   148),
         UINT8_C(    11),  UINT8_C(   234),  UINT8_C(   163),  UINT8_C(    46) },
      {  UINT8_C(   141),  UINT8_C(   127),  UINT8_C(   249),  UINT8_C(   123),
         UINT8_C(    22),  UINT8_C(   137),  UINT8_C(   229),  UINT8_C(    67),
         UINT8_C(    19),  UINT8_C(   140),  UINT8_C(   161),  UINT8_C(   165),
         UINT8_C(     2),  UINT8_C(   186),  UINT8_C(    40),  UINT8_C(   203) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t buf = simde_vld1_u8(test_vec[i].buf);
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint8x16_t r1 = simde_vshrn_high_n_u16(buf, a, 1);
    simde_uint8x16_t r3 = simde_vshrn_high_n_u16(buf, a, 3);
    simde_uint8x16_t r5 = simde_vshrn_high_n_u16(buf, a, 5);
    simde_uint8x16_t r6 = simde_vshrn_high_n_u16(buf, a, 6);
    simde_uint8x16_t r8 = simde_vshrn_high_n_u16(buf, a, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t buf = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t r1 = simde_vshrn_high_n_u16(buf, a, 1);
    simde_uint8x16_t r3 = simde_vshrn_high_n_u16(buf, a, 3);
    simde_uint8x16_t r5 = simde_vshrn_high_n_u16(buf, a, 5);
    simde_uint8x16_t r6 = simde_vshrn_high_n_u16(buf, a, 6);
    simde_uint8x16_t r8 = simde_vshrn_high_n_u16(buf, a, 8);

    simde_test_arm_neon_write_u8x8(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshrn_high_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t buf[4];
    uint32_t a[4];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { {  UINT16_C(   20136),  UINT16_C(   20557),  UINT16_C(    2044),  UINT16_C(   43802) },
      {  UINT32_C(3936497226),  UINT32_C(1178363942),  UINT32_C(1040372135),  UINT32_C(1143939397) },
      {  UINT16_C(   20136),  UINT16_C(   20557),  UINT16_C(    2044),  UINT16_C(   43802),
         UINT16_C(   17865),  UINT16_C(   36100),  UINT16_C(   23092),  UINT16_C(   58408) },
      {  UINT16_C(   20136),  UINT16_C(   20557),  UINT16_C(    2044),  UINT16_C(   43802),
         UINT16_C(   35001),  UINT16_C(   61856),  UINT16_C(    2886),  UINT16_C(   48261) },
      {  UINT16_C(   20136),  UINT16_C(   20557),  UINT16_C(    2044),  UINT16_C(   43802),
         UINT16_C(   43147),  UINT16_C(   36634),  UINT16_C(   32948),  UINT16_C(    3016) },
      {  UINT16_C(   20136),  UINT16_C(   20557),  UINT16_C(    2044),  UINT16_C(   43802),
         UINT16_C(   21777),  UINT16_C(   12771),  UINT16_C(   61462),  UINT16_C(    8569) },
      {  UINT16_C(   20136),  UINT16_C(   20557),  UINT16_C(    2044),  UINT16_C(   43802),
         UINT16_C(   60066),  UINT16_C(   17980),  UINT16_C(   15874),  UINT16_C(   17455) } },
    { {  UINT16_C(   64656),  UINT16_C(   53949),  UINT16_C(    1919),  UINT16_C(    4852) },
      {  UINT32_C(96266276),  UINT32_C(3020897537),  UINT32_C(796372666),  UINT32_C(3409933160) },
      {  UINT16_C(   64656),  UINT16_C(   53949),  UINT16_C(    1919),  UINT16_C(    4852),
         UINT16_C(   40196),  UINT16_C(   59296),  UINT16_C(   62935),  UINT16_C(   61037) },
      {  UINT16_C(   64656),  UINT16_C(   53949),  UINT16_C(    1919),  UINT16_C(    4852),
         UINT16_C(   62368),  UINT16_C(   15604),  UINT16_C(   57018),  UINT16_C(   64973) },
      {  UINT16_C(   64656),  UINT16_C(   53949),  UINT16_C(    1919),  UINT16_C(    4852),
         UINT16_C(   28474),  UINT16_C(     975),  UINT16_C(   56811),  UINT16_C(   53212) },
      {  UINT16_C(   64656),  UINT16_C(   53949),  UINT16_C(    1919),  UINT16_C(    4852),
         UINT16_C(   11751),  UINT16_C(   41081),  UINT16_C(   31677),  UINT16_C(   23035) },
      {  UINT16_C(   64656),  UINT16_C(   53949),  UINT16_C(    1919),  UINT16_C(    4852),
         UINT16_C(    1468),  UINT16_C(   46095),  UINT16_C(   12151),  UINT16_C(   52031) } },
    { {  UINT16_C(   34932),  UINT16_C(   51999),  UINT16_C(   38417),  UINT16_C(   36202) },
      {  UINT32_C(3922182960),  UINT32_C(2662908635),  UINT32_C(3461480843),  UINT32_C(3929155663) },
      {  UINT16_C(   34932),  UINT16_C(   51999),  UINT16_C(   38417),  UINT16_C(   36202),
         UINT16_C(   63590),  UINT16_C(    6235),  UINT16_C(   16433),  UINT16_C(   17673) },
      {  UINT16_C(   34932),  UINT16_C(   51999),  UINT16_C(   38417),  UINT16_C(   36202),
         UINT16_C(    7948),  UINT16_C(   58123),  UINT16_C(   18438),  UINT16_C(   51361) },
      {  UINT16_C(   34932),  UINT16_C(   51999),  UINT16_C(   38417),  UINT16_C(   36202),
         UINT16_C(   29168),  UINT16_C(   44592),  UINT16_C(   38016),  UINT16_C(   35978) },
      {  UINT16_C(   34932),  UINT16_C(   51999),  UINT16_C(   38417),  UINT16_C(   36202),
         UINT16_C(   20030),  UINT16_C(   62918),  UINT16_C(   29328),  UINT16_C(   20881) },
      {  UINT16_C(   34932),  UINT16_C(   51999),  UINT16_C(   38417),  UINT16_C(   36202),
         UINT16_C(   59847),  UINT16_C(   40632),  UINT16_C(   52818),  UINT16_C(   59954) } },
    { {  UINT16_C(   61560),  UINT16_C(    2508),  UINT16_C(   51001),  UINT16_C(   31396) },
      {  UINT32_C(2454220114),  UINT32_C(370362194),  UINT32_C(2227791538),  UINT32_C(1375512886) },
      {  UINT16_C(   61560),  UINT16_C(    2508),  UINT16_C(   51001),  UINT16_C(   31396),
         UINT16_C(    3498),  UINT16_C(   26858),  UINT16_C(   11478),  UINT16_C(   38182) },
      {  UINT16_C(   61560),  UINT16_C(    2508),  UINT16_C(   51001),  UINT16_C(   31396),
         UINT16_C(    8629),  UINT16_C(   19741),  UINT16_C(    9626),  UINT16_C(   62116) },
      {  UINT16_C(   61560),  UINT16_C(    2508),  UINT16_C(   51001),  UINT16_C(   31396),
         UINT16_C(   37403),  UINT16_C(   34001),  UINT16_C(   12889),  UINT16_C(   32554) },
      {  UINT16_C(   61560),  UINT16_C(    2508),  UINT16_C(   51001),  UINT16_C(   31396),
         UINT16_C(   37443),  UINT16_C(   45210),  UINT16_C(    9803),  UINT16_C(   36837) },
      {  UINT16_C(   61560),  UINT16_C(    2508),  UINT16_C(   51001),  UINT16_C(   31396),
         UINT16_C(   37448),  UINT16_C(    5651),  UINT16_C(   33993),  UINT16_C(   20988) } },
    { {  UINT16_C(   27723),  UINT16_C(   52704),  UINT16_C(   26290),  UINT16_C(   64965) },
      {  UINT32_C(3388923342),  UINT32_C(2010326826),  UINT32_C(514544606),  UINT32_C(2124101270) },
      {  UINT16_C(   27723),  UINT16_C(   52704),  UINT16_C(   26290),  UINT16_C(   64965),
         UINT16_C(   56249),  UINT16_C(   25829),  UINT16_C(   27259),  UINT16_C(   26322) },
      {  UINT16_C(   27723),  UINT16_C(   52704),  UINT16_C(   26290),  UINT16_C(   64965),
         UINT16_C(   64375),  UINT16_C(   19612),  UINT16_C(   44367),  UINT16_C(   27866) },
      {  UINT16_C(   27723),  UINT16_C(   52704),  UINT16_C(   26290),  UINT16_C(   64965),
         UINT16_C(   32695),  UINT16_C(   62665),  UINT16_C(   43732),  UINT16_C(   42701) },
      {  UINT16_C(   27723),  UINT16_C(   52704),  UINT16_C(   26290),  UINT16_C(   64965),
         UINT16_C(   20470),  UINT16_C(   48793),  UINT16_C(   62810),  UINT16_C(   62681) },
      {  UINT16_C(   27723),  UINT16_C(   52704),  UINT16_C(   26290),  UINT16_C(   64965),
         UINT16_C(   51710),  UINT16_C(   30675),  UINT16_C(    7851),  UINT16_C(   32411) } },
    { {  UINT16_C(   28141),  UINT16_C(   21498),  UINT16_C(   24931),  UINT16_C(   63978) },
      {  UINT32_C(1787751446),  UINT32_C(1892593082),  UINT32_C(2381834115),  UINT32_C(189076089) },
      {  UINT16_C(   28141),  UINT16_C(   21498),  UINT16_C(   24931),  UINT16_C(   63978),
         UINT16_C(   56706),  UINT16_C(   54711),  UINT16_C(   64752),  UINT16_C(   41551) },
      {  UINT16_C(   28141),  UINT16_C(   21498),  UINT16_C(   24931),  UINT16_C(   63978),
         UINT16_C(   15280),  UINT16_C(   15030),  UINT16_C(   57246),  UINT16_C(    5193) },
      {  UINT16_C(   28141),  UINT16_C(   21498),  UINT16_C(   24931),  UINT16_C(   63978),
         UINT16_C(   41915),  UINT16_C(   13227),  UINT16_C(   32249),  UINT16_C(   53572) },
      {  UINT16_C(   28141),  UINT16_C(   21498),  UINT16_C(   24931),  UINT16_C(   63978),
         UINT16_C(   21623),  UINT16_C(   34421),  UINT16_C(   28607),  UINT16_C(   23080) },
      {  UINT16_C(   28141),  UINT16_C(   21498),  UINT16_C(   24931),  UINT16_C(   63978),
         UINT16_C(   27278),  UINT16_C(   28878),  UINT16_C(   36343),  UINT16_C(    2885) } },
    { {  UINT16_C(   61132),  UINT16_C(   40628),  UINT16_C(   57608),  UINT16_C(    1070) },
      {  UINT32_C(1241322886),  UINT32_C(2710839943),  UINT32_C(1172787125),  UINT32_C(1628430714) },
      {  UINT16_C(   61132),  UINT16_C(   40628),  UINT16_C(   57608),  UINT16_C(    1070),
         UINT16_C(   41648),  UINT16_C(   33872),  UINT16_C(   59894),  UINT16_C(   64559) },
      {  UINT16_C(   61132),  UINT16_C(   40628),  UINT16_C(   57608),  UINT16_C(    1070),
         UINT16_C(   62550),  UINT16_C(   20618),  UINT16_C(   40254),  UINT16_C(   16261) },
      {  UINT16_C(   61132),  UINT16_C(   40628),  UINT16_C(   57608),  UINT16_C(    1070),
         UINT16_C(   32581),  UINT16_C(   25864),  UINT16_C(   31187),  UINT16_C(   17400) },
      {  UINT16_C(   61132),  UINT16_C(   40628),  UINT16_C(   57608),  UINT16_C(    1070),
         UINT16_C(   20456),  UINT16_C(    3233),  UINT16_C(   12090),  UINT16_C(    2175) },
      {  UINT16_C(   61132),  UINT16_C(   40628),  UINT16_C(   57608),  UINT16_C(    1070),
         UINT16_C(   18941),  UINT16_C(   41364),  UINT16_C(   17895),  UINT16_C(   24847) } },
    { {  UINT16_C(   28352),  UINT16_C(   18699),  UINT16_C(     569),  UINT16_C(   15781) },
      {  UINT32_C(1746114431),  UINT32_C(2355388098),  UINT32_C(4194998734),  UINT32_C(2662040450) },
      {  UINT16_C(   28352),  UINT16_C(   18699),  UINT16_C(     569),  UINT16_C(   15781),
         UINT16_C(   29423),  UINT16_C(   35800),  UINT16_C(   21305),  UINT16_C(   28784) },
      {  UINT16_C(   28352),  UINT16_C(   18699),  UINT16_C(     569),  UINT16_C(   15781),
         UINT16_C(   20061),  UINT16_C(   37243),  UINT16_C(   10855),  UINT16_C(   44558) },
      {  UINT16_C(   28352),  UINT16_C(   18699),  UINT16_C(     569),  UINT16_C(   15781),
         UINT16_C(    1253),  UINT16_C(    6423),  UINT16_C(   33446),  UINT16_C(   43744) },
      {  UINT16_C(   28352),  UINT16_C(   18699),  UINT16_C(     569),  UINT16_C(   15781),
         UINT16_C(   16540),  UINT16_C(   25378),  UINT16_C(   53332),  UINT16_C(   62812) },
      {  UINT16_C(   28352),  UINT16_C(   18699),  UINT16_C(     569),  UINT16_C(   15781),
         UINT16_C(   26643),  UINT16_C(   35940),  UINT16_C(   64010),  UINT16_C(   40619) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t buf = simde_vld1_u16(test_vec[i].buf);
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint16x8_t r3 = simde_vshrn_high_n_u32(buf, a, 3);
    simde_uint16x8_t r6 = simde_vshrn_high_n_u32(buf, a, 6);
    simde_uint16x8_t r10 = simde_vshrn_high_n_u32(buf, a, 10);
    simde_uint16x8_t r13 = simde_vshrn_high_n_u32(buf, a, 13);
    simde_uint16x8_t r16 = simde_vshrn_high_n_u32(buf, a, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t buf = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t r3 = simde_vshrn_high_n_u32(buf, a, 3);
    simde_uint16x8_t r6 = simde_vshrn_high_n_u32(buf, a, 6);
    simde_uint16x8_t r10 = simde_vshrn_high_n_u32(buf, a, 10);
    simde_uint16x8_t r13 = simde_vshrn_high_n_u32(buf, a, 13);
    simde_uint16x8_t r16 = simde_vshrn_high_n_u32(buf, a, 16);

    simde_test_arm_neon_write_u16x4(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshrn_high_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t buf[2];
    uint64_t a[2];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { {  UINT32_C(   708137213),  UINT32_C(   306486960) },
      {  UINT64_C(13733860301588238750),  UINT64_C(11834712775710873610) },
      {  UINT32_C(   708137213),  UINT32_C(   306486960),  UINT32_C(  3078358598),  UINT32_C(  1142691936) },
      {  UINT32_C(   708137213),  UINT32_C(   306486960),  UINT32_C(  3379492876),  UINT32_C(  3297261616) },
      {  UINT32_C(   708137213),  UINT32_C(   306486960),  UINT32_C(   254131168),  UINT32_C(  2870092000) },
      {  UINT32_C(   708137213),  UINT32_C(   306486960),  UINT32_C(  2787003255),  UINT32_C(   257303617) },
      {  UINT32_C(   708137213),  UINT32_C(   306486960),  UINT32_C(  3197663533),  UINT32_C(  2755483793) } },
    { {  UINT32_C(  2685021336),  UINT32_C(  1226966506) },
      {  UINT64_C(14173040155328260938),  UINT64_C(5387321708733863128) },
      {  UINT32_C(  2685021336),  UINT32_C(  1226966506),  UINT32_C(  3080110253),  UINT32_C(   873419859) },
      {  UINT32_C(  2685021336),  UINT32_C(  1226966506),  UINT32_C(   124726657),  UINT32_C(  3832028840) },
      {  UINT32_C(  2685021336),  UINT32_C(  1226966506),  UINT32_C(   404602038),  UINT32_C(  1938923642) },
      {  UINT32_C(  2685021336),  UINT32_C(  1226966506),  UINT32_C(   741358457),  UINT32_C(  2967937856) },
      {  UINT32_C(  2685021336),  UINT32_C(  1226966506),  UINT32_C(  3299918061),  UINT32_C(  1254333581) } },
    { {  UINT32_C(  3805576920),  UINT32_C(  1516761409) },
      {  UINT64_C(10934555098164680140),  UINT64_C(12767994493624307686) },
      {  UINT32_C(  3805576920),  UINT32_C(  1516761409),  UINT32_C(  3058445143),  UINT32_C(  1618639679) },
      {  UINT32_C(  3805576920),  UINT32_C(  1516761409),  UINT32_C(  3211565142),  UINT32_C(   985724150) },
      {  UINT32_C(  3805576920),  UINT32_C(  1516761409),  UINT32_C(  3942494817),  UINT32_C(   552272851) },
      {  UINT32_C(  3805576920),  UINT32_C(  1516761409),  UINT32_C(  4023778148),  UINT32_C(  1279383047) },
      {  UINT32_C(  3805576920),  UINT32_C(  1516761409),  UINT32_C(  2545899501),  UINT32_C(  2972780376) } },
    { {  UINT32_C(   187217084),  UINT32_C(  2953381155) },
      {  UINT64_C(2084855005440816427),  UINT64_C(16785133456325973557) },
      {  UINT32_C(   187217084),  UINT32_C(  2953381155),  UINT32_C(  1398667988),  UINT32_C(  3385808472) },
      {  UINT32_C(   187217084),  UINT32_C(  2953381155),  UINT32_C(   614906869),  UINT32_C(   798203564) },
      {  UINT32_C(   187217084),  UINT32_C(  2953381155),  UINT32_C(  3700595439),  UINT32_C(   415125114) },
      {  UINT32_C(   187217084),  UINT32_C(  2953381155),  UINT32_C(  1001989429),  UINT32_C(  1009876124) },
      {  UINT32_C(   187217084),  UINT32_C(  2953381155),  UINT32_C(   485418132),  UINT32_C(  3908093426) } },
    { {  UINT32_C(  2232947645),  UINT32_C(   272450408) },
      {  UINT64_C(4996552312586505851),  UINT64_C(15962247863150178446) },
      {  UINT32_C(  2232947645),  UINT32_C(   272450408),  UINT32_C(  1811251257),  UINT32_C(  1888434114) },
      {  UINT32_C(  2232947645),  UINT32_C(   272450408),  UINT32_C(  2396515072),  UINT32_C(  1591811695) },
      {  UINT32_C(  2232947645),  UINT32_C(   272450408),  UINT32_C(  3929759660),  UINT32_C(  2843444345) },
      {  UINT32_C(  2232947645),  UINT32_C(   272450408),  UINT32_C(  1439987391),  UINT32_C(  1632827144) },
      {  UINT32_C(  2232947645),  UINT32_C(   272450408),  UINT32_C(  1163350490),  UINT32_C(  3716500444) } },
    { {  UINT32_C(  3379878061),  UINT32_C(  2066304178) },
      {  UINT64_C(11565604421878607337),  UINT64_C(5640457283446428192) },
      {  UINT32_C(  3379878061),  UINT32_C(  2066304178),  UINT32_C(  3341487031),  UINT32_C(   255482696) },
      {  UINT32_C(  3379878061),  UINT32_C(  2066304178),  UINT32_C(  1066292759),  UINT32_C(  1881044150) },
      {  UINT32_C(  3379878061),  UINT32_C(  2066304178),  UINT32_C(   687749464),  UINT32_C(  3720378834) },
      {  UINT32_C(  3379878061),  UINT32_C(  2066304178),  UINT32_C(   542243954),  UINT32_C(  2444984563) },
      {  UINT32_C(  3379878061),  UINT32_C(  2066304178),  UINT32_C(  2692827121),  UINT32_C(  1313271299) } },
    { {  UINT32_C(  4207845743),  UINT32_C(  1544292987) },
      {  UINT64_C(1956611213733848356),  UINT64_C(16704487939898595817) },
      {  UINT32_C(  4207845743),  UINT32_C(  1544292987),  UINT32_C(   555260820),  UINT32_C(   466734951) },
      {  UINT32_C(  4207845743),  UINT32_C(  1544292987),  UINT32_C(  1010970935),  UINT32_C(   439853982) },
      {  UINT32_C(  4207845743),  UINT32_C(  1544292987),  UINT32_C(  3908110532),  UINT32_C(  1214832270) },
      {  UINT32_C(  4207845743),  UINT32_C(  1544292987),  UINT32_C(  3385975313),  UINT32_C(  4103131581) },
      {  UINT32_C(  4207845743),  UINT32_C(  1544292987),  UINT32_C(   455559048),  UINT32_C(  3889316678) } },
    { {  UINT32_C(  1144240121),  UINT32_C(  1247940771) },
      {  UINT64_C(12032533489835312609),  UINT64_C(13079546953436532977) },
      {  UINT32_C(  1144240121),  UINT32_C(  1247940771),  UINT32_C(  3571875863),  UINT32_C(  2675606083) },
      {  UINT32_C(  1144240121),  UINT32_C(  1247940771),  UINT32_C(   732548352),  UINT32_C(   356447492) },
      {  UINT32_C(  1144240121),  UINT32_C(  1247940771),  UINT32_C(  2226038580),  UINT32_C(  2085944276) },
      {  UINT32_C(  1144240121),  UINT32_C(  1247940771),  UINT32_C(  3205061966),  UINT32_C(  1626909175) },
      {  UINT32_C(  1144240121),  UINT32_C(  1247940771),  UINT32_C(  2801542517),  UINT32_C(  3045319335) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t buf = simde_vld1_u32(test_vec[i].buf);
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint32x4_t r6 = simde_vshrn_high_n_u64(buf, a, 6);
    simde_uint32x4_t r13 = simde_vshrn_high_n_u64(buf, a, 13);
    simde_uint32x4_t r19 = simde_vshrn_high_n_u64(buf, a, 19);
    simde_uint32x4_t r26 = simde_vshrn_high_n_u64(buf, a, 26);
    simde_uint32x4_t r32 = simde_vshrn_high_n_u64(buf, a, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t buf = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t r6 = simde_vshrn_high_n_u64(buf, a, 6);
    simde_uint32x4_t r13 = simde_vshrn_high_n_u64(buf, a, 13);
    simde_uint32x4_t r19 = simde_vshrn_high_n_u64(buf, a, 19);
    simde_uint32x4_t r26 = simde_vshrn_high_n_u64(buf, a, 26);
    simde_uint32x4_t r32 = simde_vshrn_high_n_u64(buf, a, 32);

    simde_test_arm_neon_write_u32x2(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_high_n_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_high_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_high_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_high_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
