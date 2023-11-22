#define SIMDE_TEST_ARM_NEON_INSN copy_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/copy_lane.h"
#include "../../../simde/arm/neon/reinterpret.h"

static int
test_simde_vcopy_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r00[8];
    int8_t r13[8];
    int8_t r35[8];
    int8_t r67[8];
    int8_t r71[8];
  } test_vec[] = {
    { { -INT8_C(    78), -INT8_C(    72),  INT8_C(    48),  INT8_C(    97),
        -INT8_C(    62),  INT8_C(   121), -INT8_C(    59), -INT8_C(   109) },
      { -INT8_C(    56), -INT8_C(    86),  INT8_C(   123),  INT8_C(   105),
        -INT8_C(    32),  INT8_C(    96), -INT8_C(    23),  INT8_C(   105) },
      { -INT8_C(    56), -INT8_C(    72),  INT8_C(    48),  INT8_C(    97),
        -INT8_C(    62),  INT8_C(   121), -INT8_C(    59), -INT8_C(   109) },
      { -INT8_C(    78),  INT8_C(   105),  INT8_C(    48),  INT8_C(    97),
        -INT8_C(    62),  INT8_C(   121), -INT8_C(    59), -INT8_C(   109) },
      { -INT8_C(    78), -INT8_C(    72),  INT8_C(    48),  INT8_C(    96),
        -INT8_C(    62),  INT8_C(   121), -INT8_C(    59), -INT8_C(   109) },
      { -INT8_C(    78), -INT8_C(    72),  INT8_C(    48),  INT8_C(    97),
        -INT8_C(    62),  INT8_C(   121),  INT8_C(   105), -INT8_C(   109) },
      { -INT8_C(    78), -INT8_C(    72),  INT8_C(    48),  INT8_C(    97),
        -INT8_C(    62),  INT8_C(   121), -INT8_C(    59), -INT8_C(    86) } },
    { { -INT8_C(   117), -INT8_C(    45), -INT8_C(    85),  INT8_C(     8),
        -INT8_C(    53),  INT8_C(    73),  INT8_C(    39),  INT8_C(    87) },
      { -INT8_C(    93), -INT8_C(    73),  INT8_C(    58),  INT8_C(    17),
         INT8_C(    48),  INT8_C(    96), -INT8_C(   107),  INT8_C(    12) },
      { -INT8_C(    93), -INT8_C(    45), -INT8_C(    85),  INT8_C(     8),
        -INT8_C(    53),  INT8_C(    73),  INT8_C(    39),  INT8_C(    87) },
      { -INT8_C(   117),  INT8_C(    17), -INT8_C(    85),  INT8_C(     8),
        -INT8_C(    53),  INT8_C(    73),  INT8_C(    39),  INT8_C(    87) },
      { -INT8_C(   117), -INT8_C(    45), -INT8_C(    85),  INT8_C(    96),
        -INT8_C(    53),  INT8_C(    73),  INT8_C(    39),  INT8_C(    87) },
      { -INT8_C(   117), -INT8_C(    45), -INT8_C(    85),  INT8_C(     8),
        -INT8_C(    53),  INT8_C(    73),  INT8_C(    12),  INT8_C(    87) },
      { -INT8_C(   117), -INT8_C(    45), -INT8_C(    85),  INT8_C(     8),
        -INT8_C(    53),  INT8_C(    73),  INT8_C(    39), -INT8_C(    73) } },
    { {  INT8_C(   115),  INT8_C(    81), -INT8_C(    94),  INT8_C(   115),
        -INT8_C(    26),  INT8_C(    33),  INT8_C(   109), -INT8_C(   113) },
      {  INT8_C(   115), -INT8_C(     5),  INT8_C(     1),  INT8_C(     9),
         INT8_C(    47), -INT8_C(    57),  INT8_C(     3), -INT8_C(    50) },
      {  INT8_C(   115),  INT8_C(    81), -INT8_C(    94),  INT8_C(   115),
        -INT8_C(    26),  INT8_C(    33),  INT8_C(   109), -INT8_C(   113) },
      {  INT8_C(   115),  INT8_C(     9), -INT8_C(    94),  INT8_C(   115),
        -INT8_C(    26),  INT8_C(    33),  INT8_C(   109), -INT8_C(   113) },
      {  INT8_C(   115),  INT8_C(    81), -INT8_C(    94), -INT8_C(    57),
        -INT8_C(    26),  INT8_C(    33),  INT8_C(   109), -INT8_C(   113) },
      {  INT8_C(   115),  INT8_C(    81), -INT8_C(    94),  INT8_C(   115),
        -INT8_C(    26),  INT8_C(    33), -INT8_C(    50), -INT8_C(   113) },
      {  INT8_C(   115),  INT8_C(    81), -INT8_C(    94),  INT8_C(   115),
        -INT8_C(    26),  INT8_C(    33),  INT8_C(   109), -INT8_C(     5) } },
    { { -INT8_C(    90),  INT8_C(    59), -INT8_C(   106), -INT8_C(   127),
         INT8_C(     1),  INT8_C(    70),  INT8_C(    24), -INT8_C(    55) },
      { -INT8_C(    85),  INT8_C(    64), -INT8_C(    70),  INT8_C(    88),
         INT8_C(   110), -INT8_C(    17),  INT8_C(    56), -INT8_C(    81) },
      { -INT8_C(    85),  INT8_C(    59), -INT8_C(   106), -INT8_C(   127),
         INT8_C(     1),  INT8_C(    70),  INT8_C(    24), -INT8_C(    55) },
      { -INT8_C(    90),  INT8_C(    88), -INT8_C(   106), -INT8_C(   127),
         INT8_C(     1),  INT8_C(    70),  INT8_C(    24), -INT8_C(    55) },
      { -INT8_C(    90),  INT8_C(    59), -INT8_C(   106), -INT8_C(    17),
         INT8_C(     1),  INT8_C(    70),  INT8_C(    24), -INT8_C(    55) },
      { -INT8_C(    90),  INT8_C(    59), -INT8_C(   106), -INT8_C(   127),
         INT8_C(     1),  INT8_C(    70), -INT8_C(    81), -INT8_C(    55) },
      { -INT8_C(    90),  INT8_C(    59), -INT8_C(   106), -INT8_C(   127),
         INT8_C(     1),  INT8_C(    70),  INT8_C(    24),  INT8_C(    64) } },
    { { -INT8_C(    69), -INT8_C(    46), -INT8_C(   114),  INT8_C(    40),
        -INT8_C(    68),  INT8_C(    99), -INT8_C(    54),  INT8_C(    24) },
      { -INT8_C(     6),  INT8_C(    13),  INT8_C(    89), -INT8_C(   127),
         INT8_C(    11), -INT8_C(   122),  INT8_C(    51), -INT8_C(    46) },
      { -INT8_C(     6), -INT8_C(    46), -INT8_C(   114),  INT8_C(    40),
        -INT8_C(    68),  INT8_C(    99), -INT8_C(    54),  INT8_C(    24) },
      { -INT8_C(    69), -INT8_C(   127), -INT8_C(   114),  INT8_C(    40),
        -INT8_C(    68),  INT8_C(    99), -INT8_C(    54),  INT8_C(    24) },
      { -INT8_C(    69), -INT8_C(    46), -INT8_C(   114), -INT8_C(   122),
        -INT8_C(    68),  INT8_C(    99), -INT8_C(    54),  INT8_C(    24) },
      { -INT8_C(    69), -INT8_C(    46), -INT8_C(   114),  INT8_C(    40),
        -INT8_C(    68),  INT8_C(    99), -INT8_C(    46),  INT8_C(    24) },
      { -INT8_C(    69), -INT8_C(    46), -INT8_C(   114),  INT8_C(    40),
        -INT8_C(    68),  INT8_C(    99), -INT8_C(    54),  INT8_C(    13) } },
    { {  INT8_C(   118), -INT8_C(    13),  INT8_C(     7), -INT8_C(    30),
        -INT8_C(    56), -INT8_C(   127),  INT8_C(    34),  INT8_C(     6) },
      {  INT8_C(   118),  INT8_C(    56), -INT8_C(    47),  INT8_C(    71),
        -INT8_C(    67), -INT8_C(   102), -INT8_C(    49),  INT8_C(    23) },
      {  INT8_C(   118), -INT8_C(    13),  INT8_C(     7), -INT8_C(    30),
        -INT8_C(    56), -INT8_C(   127),  INT8_C(    34),  INT8_C(     6) },
      {  INT8_C(   118),  INT8_C(    71),  INT8_C(     7), -INT8_C(    30),
        -INT8_C(    56), -INT8_C(   127),  INT8_C(    34),  INT8_C(     6) },
      {  INT8_C(   118), -INT8_C(    13),  INT8_C(     7), -INT8_C(   102),
        -INT8_C(    56), -INT8_C(   127),  INT8_C(    34),  INT8_C(     6) },
      {  INT8_C(   118), -INT8_C(    13),  INT8_C(     7), -INT8_C(    30),
        -INT8_C(    56), -INT8_C(   127),  INT8_C(    23),  INT8_C(     6) },
      {  INT8_C(   118), -INT8_C(    13),  INT8_C(     7), -INT8_C(    30),
        -INT8_C(    56), -INT8_C(   127),  INT8_C(    34),  INT8_C(    56) } },
    { {  INT8_C(    23), -INT8_C(    45),  INT8_C(    85),  INT8_C(    18),
         INT8_C(   119),        INT8_MAX,  INT8_C(    70),  INT8_C(   119) },
      { -INT8_C(    13), -INT8_C(   123), -INT8_C(     4),  INT8_C(    87),
         INT8_C(    21),  INT8_C(    63),  INT8_C(   115),  INT8_C(     3) },
      { -INT8_C(    13), -INT8_C(    45),  INT8_C(    85),  INT8_C(    18),
         INT8_C(   119),        INT8_MAX,  INT8_C(    70),  INT8_C(   119) },
      {  INT8_C(    23),  INT8_C(    87),  INT8_C(    85),  INT8_C(    18),
         INT8_C(   119),        INT8_MAX,  INT8_C(    70),  INT8_C(   119) },
      {  INT8_C(    23), -INT8_C(    45),  INT8_C(    85),  INT8_C(    63),
         INT8_C(   119),        INT8_MAX,  INT8_C(    70),  INT8_C(   119) },
      {  INT8_C(    23), -INT8_C(    45),  INT8_C(    85),  INT8_C(    18),
         INT8_C(   119),        INT8_MAX,  INT8_C(     3),  INT8_C(   119) },
      {  INT8_C(    23), -INT8_C(    45),  INT8_C(    85),  INT8_C(    18),
         INT8_C(   119),        INT8_MAX,  INT8_C(    70), -INT8_C(   123) } },
    { {  INT8_C(    93), -INT8_C(   117), -INT8_C(    15),  INT8_C(    74),
        -INT8_C(    71),  INT8_C(    82),  INT8_C(    67), -INT8_C(    59) },
      { -INT8_C(    24),  INT8_C(   126),  INT8_C(    78), -INT8_C(   104),
        -INT8_C(   114), -INT8_C(    31),  INT8_C(     4),  INT8_C(     6) },
      { -INT8_C(    24), -INT8_C(   117), -INT8_C(    15),  INT8_C(    74),
        -INT8_C(    71),  INT8_C(    82),  INT8_C(    67), -INT8_C(    59) },
      {  INT8_C(    93), -INT8_C(   104), -INT8_C(    15),  INT8_C(    74),
        -INT8_C(    71),  INT8_C(    82),  INT8_C(    67), -INT8_C(    59) },
      {  INT8_C(    93), -INT8_C(   117), -INT8_C(    15), -INT8_C(    31),
        -INT8_C(    71),  INT8_C(    82),  INT8_C(    67), -INT8_C(    59) },
      {  INT8_C(    93), -INT8_C(   117), -INT8_C(    15),  INT8_C(    74),
        -INT8_C(    71),  INT8_C(    82),  INT8_C(     6), -INT8_C(    59) },
      {  INT8_C(    93), -INT8_C(   117), -INT8_C(    15),  INT8_C(    74),
        -INT8_C(    71),  INT8_C(    82),  INT8_C(    67),  INT8_C(   126) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);

    simde_int8x8_t r00 = simde_vcopy_lane_s8(a, 0, b, 0);
    simde_int8x8_t r13 = simde_vcopy_lane_s8(a, 1, b, 3);
    simde_int8x8_t r35 = simde_vcopy_lane_s8(a, 3, b, 5);
    simde_int8x8_t r67 = simde_vcopy_lane_s8(a, 6, b, 7);
    simde_int8x8_t r71 = simde_vcopy_lane_s8(a, 7, b, 1);

    simde_test_arm_neon_assert_equal_i8x8(r00, simde_vld1_s8(test_vec[i].r00));
    simde_test_arm_neon_assert_equal_i8x8(r13, simde_vld1_s8(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i8x8(r35, simde_vld1_s8(test_vec[i].r35));
    simde_test_arm_neon_assert_equal_i8x8(r67, simde_vld1_s8(test_vec[i].r67));
    simde_test_arm_neon_assert_equal_i8x8(r71, simde_vld1_s8(test_vec[i].r71));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r00 = simde_vcopy_lane_s8(a, 0, b, 0);
    simde_int8x8_t r13 = simde_vcopy_lane_s8(a, 1, b, 3);
    simde_int8x8_t r35 = simde_vcopy_lane_s8(a, 3, b, 5);
    simde_int8x8_t r67 = simde_vcopy_lane_s8(a, 6, b, 7);
    simde_int8x8_t r71 = simde_vcopy_lane_s8(a, 7, b, 1);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r35, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r67, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r71, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r00[4];
    int16_t r01[4];
    int16_t r13[4];
    int16_t r22[4];
    int16_t r33[4];
  } test_vec[] = {
    { { -INT16_C(  16325),  INT16_C(  17773), -INT16_C(  20430),  INT16_C(  27334) },
      { -INT16_C(  32517), -INT16_C(  27026),  INT16_C(  30460),  INT16_C(  14613) },
      { -INT16_C(  32517),  INT16_C(  17773), -INT16_C(  20430),  INT16_C(  27334) },
      { -INT16_C(  27026),  INT16_C(  17773), -INT16_C(  20430),  INT16_C(  27334) },
      { -INT16_C(  16325),  INT16_C(  14613), -INT16_C(  20430),  INT16_C(  27334) },
      { -INT16_C(  16325),  INT16_C(  17773),  INT16_C(  30460),  INT16_C(  27334) },
      { -INT16_C(  16325),  INT16_C(  17773), -INT16_C(  20430),  INT16_C(  14613) } },
    { {  INT16_C(  10522), -INT16_C(  20353), -INT16_C(  11907),  INT16_C(  29433) },
      {  INT16_C(  26264), -INT16_C(  19178),  INT16_C(  29217),  INT16_C(   9061) },
      {  INT16_C(  26264), -INT16_C(  20353), -INT16_C(  11907),  INT16_C(  29433) },
      { -INT16_C(  19178), -INT16_C(  20353), -INT16_C(  11907),  INT16_C(  29433) },
      {  INT16_C(  10522),  INT16_C(   9061), -INT16_C(  11907),  INT16_C(  29433) },
      {  INT16_C(  10522), -INT16_C(  20353),  INT16_C(  29217),  INT16_C(  29433) },
      {  INT16_C(  10522), -INT16_C(  20353), -INT16_C(  11907),  INT16_C(   9061) } },
    { { -INT16_C(   4995),  INT16_C(  14378), -INT16_C(   3303), -INT16_C(  17484) },
      { -INT16_C(  10776),  INT16_C(  28644), -INT16_C(  30101),  INT16_C(   2823) },
      { -INT16_C(  10776),  INT16_C(  14378), -INT16_C(   3303), -INT16_C(  17484) },
      {  INT16_C(  28644),  INT16_C(  14378), -INT16_C(   3303), -INT16_C(  17484) },
      { -INT16_C(   4995),  INT16_C(   2823), -INT16_C(   3303), -INT16_C(  17484) },
      { -INT16_C(   4995),  INT16_C(  14378), -INT16_C(  30101), -INT16_C(  17484) },
      { -INT16_C(   4995),  INT16_C(  14378), -INT16_C(   3303),  INT16_C(   2823) } },
    { {  INT16_C(   5225),  INT16_C(  28725), -INT16_C(   5626), -INT16_C(  26400) },
      { -INT16_C(   7612),  INT16_C(  17719),  INT16_C(   9923), -INT16_C(  31132) },
      { -INT16_C(   7612),  INT16_C(  28725), -INT16_C(   5626), -INT16_C(  26400) },
      {  INT16_C(  17719),  INT16_C(  28725), -INT16_C(   5626), -INT16_C(  26400) },
      {  INT16_C(   5225), -INT16_C(  31132), -INT16_C(   5626), -INT16_C(  26400) },
      {  INT16_C(   5225),  INT16_C(  28725),  INT16_C(   9923), -INT16_C(  26400) },
      {  INT16_C(   5225),  INT16_C(  28725), -INT16_C(   5626), -INT16_C(  31132) } },
    { {  INT16_C(  17703),  INT16_C(  16816), -INT16_C(  29954),  INT16_C(  20252) },
      { -INT16_C(   9088), -INT16_C(  13417), -INT16_C(   6695), -INT16_C(  24796) },
      { -INT16_C(   9088),  INT16_C(  16816), -INT16_C(  29954),  INT16_C(  20252) },
      { -INT16_C(  13417),  INT16_C(  16816), -INT16_C(  29954),  INT16_C(  20252) },
      {  INT16_C(  17703), -INT16_C(  24796), -INT16_C(  29954),  INT16_C(  20252) },
      {  INT16_C(  17703),  INT16_C(  16816), -INT16_C(   6695),  INT16_C(  20252) },
      {  INT16_C(  17703),  INT16_C(  16816), -INT16_C(  29954), -INT16_C(  24796) } },
    { {  INT16_C(    666),  INT16_C(  31820), -INT16_C(  16597), -INT16_C(  19256) },
      {  INT16_C(  22386), -INT16_C(  16949), -INT16_C(   7283), -INT16_C(  15292) },
      {  INT16_C(  22386),  INT16_C(  31820), -INT16_C(  16597), -INT16_C(  19256) },
      { -INT16_C(  16949),  INT16_C(  31820), -INT16_C(  16597), -INT16_C(  19256) },
      {  INT16_C(    666), -INT16_C(  15292), -INT16_C(  16597), -INT16_C(  19256) },
      {  INT16_C(    666),  INT16_C(  31820), -INT16_C(   7283), -INT16_C(  19256) },
      {  INT16_C(    666),  INT16_C(  31820), -INT16_C(  16597), -INT16_C(  15292) } },
    { {  INT16_C(  10439),  INT16_C(   1873),  INT16_C(   4081),  INT16_C(  17141) },
      {  INT16_C(  16281), -INT16_C(  18813),  INT16_C(    988),  INT16_C(  29177) },
      {  INT16_C(  16281),  INT16_C(   1873),  INT16_C(   4081),  INT16_C(  17141) },
      { -INT16_C(  18813),  INT16_C(   1873),  INT16_C(   4081),  INT16_C(  17141) },
      {  INT16_C(  10439),  INT16_C(  29177),  INT16_C(   4081),  INT16_C(  17141) },
      {  INT16_C(  10439),  INT16_C(   1873),  INT16_C(    988),  INT16_C(  17141) },
      {  INT16_C(  10439),  INT16_C(   1873),  INT16_C(   4081),  INT16_C(  29177) } },
    { {  INT16_C(  20517), -INT16_C(   1538),  INT16_C(   8824), -INT16_C(     86) },
      { -INT16_C(   3854), -INT16_C(  18339), -INT16_C(   7976), -INT16_C(  23518) },
      { -INT16_C(   3854), -INT16_C(   1538),  INT16_C(   8824), -INT16_C(     86) },
      { -INT16_C(  18339), -INT16_C(   1538),  INT16_C(   8824), -INT16_C(     86) },
      {  INT16_C(  20517), -INT16_C(  23518),  INT16_C(   8824), -INT16_C(     86) },
      {  INT16_C(  20517), -INT16_C(   1538), -INT16_C(   7976), -INT16_C(     86) },
      {  INT16_C(  20517), -INT16_C(   1538),  INT16_C(   8824), -INT16_C(  23518) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x4_t r00 = simde_vcopy_lane_s16(a, 0, b, 0);
    simde_int16x4_t r01 = simde_vcopy_lane_s16(a, 0, b, 1);
    simde_int16x4_t r13 = simde_vcopy_lane_s16(a, 1, b, 3);
    simde_int16x4_t r22 = simde_vcopy_lane_s16(a, 2, b, 2);
    simde_int16x4_t r33 = simde_vcopy_lane_s16(a, 3, b, 3);

    simde_test_arm_neon_assert_equal_i16x4(r00, simde_vld1_s16(test_vec[i].r00));
    simde_test_arm_neon_assert_equal_i16x4(r01, simde_vld1_s16(test_vec[i].r01));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r22, simde_vld1_s16(test_vec[i].r22));
    simde_test_arm_neon_assert_equal_i16x4(r33, simde_vld1_s16(test_vec[i].r33));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r00 = simde_vcopy_lane_s16(a, 0, b, 0);
    simde_int16x4_t r01 = simde_vcopy_lane_s16(a, 0, b, 1);
    simde_int16x4_t r13 = simde_vcopy_lane_s16(a, 1, b, 3);
    simde_int16x4_t r22 = simde_vcopy_lane_s16(a, 2, b, 2);
    simde_int16x4_t r33 = simde_vcopy_lane_s16(a, 3, b, 3);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r01, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r22, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r33, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r00[2];
    int32_t r01[2];
    int32_t r10[2];
    int32_t r11[2];
  } test_vec[] = {
    { { -INT32_C(   161600086),  INT32_C(   847429630) },
      {  INT32_C(   258110270),  INT32_C(   589323412) },
      {  INT32_C(   258110270),  INT32_C(   847429630) },
      {  INT32_C(   589323412),  INT32_C(   847429630) },
      { -INT32_C(   161600086),  INT32_C(   258110270) },
      { -INT32_C(   161600086),  INT32_C(   589323412) } },
    { {  INT32_C(  1335877463), -INT32_C(  1387277215) },
      {  INT32_C(  1261596096),  INT32_C(   118232150) },
      {  INT32_C(  1261596096), -INT32_C(  1387277215) },
      {  INT32_C(   118232150), -INT32_C(  1387277215) },
      {  INT32_C(  1335877463),  INT32_C(  1261596096) },
      {  INT32_C(  1335877463),  INT32_C(   118232150) } },
    { {  INT32_C(  1784099357),  INT32_C(  1027096747) },
      { -INT32_C(   326542255), -INT32_C(   973205552) },
      { -INT32_C(   326542255),  INT32_C(  1027096747) },
      { -INT32_C(   973205552),  INT32_C(  1027096747) },
      {  INT32_C(  1784099357), -INT32_C(   326542255) },
      {  INT32_C(  1784099357), -INT32_C(   973205552) } },
    { {  INT32_C(   587291785), -INT32_C(  2004974741) },
      { -INT32_C(  1494547193), -INT32_C(   402964197) },
      { -INT32_C(  1494547193), -INT32_C(  2004974741) },
      { -INT32_C(   402964197), -INT32_C(  2004974741) },
      {  INT32_C(   587291785), -INT32_C(  1494547193) },
      {  INT32_C(   587291785), -INT32_C(   402964197) } },
    { {  INT32_C(  1305831887),  INT32_C(   923587366) },
      {  INT32_C(  1791728394),  INT32_C(   259186719) },
      {  INT32_C(  1791728394),  INT32_C(   923587366) },
      {  INT32_C(   259186719),  INT32_C(   923587366) },
      {  INT32_C(  1305831887),  INT32_C(  1791728394) },
      {  INT32_C(  1305831887),  INT32_C(   259186719) } },
    { { -INT32_C(  2137273571),  INT32_C(  1583898736) },
      { -INT32_C(  1494663023), -INT32_C(    99880334) },
      { -INT32_C(  1494663023),  INT32_C(  1583898736) },
      { -INT32_C(    99880334),  INT32_C(  1583898736) },
      { -INT32_C(  2137273571), -INT32_C(  1494663023) },
      { -INT32_C(  2137273571), -INT32_C(    99880334) } },
    { {  INT32_C(  1186905933), -INT32_C(   783851572) },
      { -INT32_C(   589687716), -INT32_C(  1794063581) },
      { -INT32_C(   589687716), -INT32_C(   783851572) },
      { -INT32_C(  1794063581), -INT32_C(   783851572) },
      {  INT32_C(  1186905933), -INT32_C(   589687716) },
      {  INT32_C(  1186905933), -INT32_C(  1794063581) } },
    { { -INT32_C(  1701680446), -INT32_C(  1171445663) },
      {  INT32_C(   225795531), -INT32_C(  1238600191) },
      {  INT32_C(   225795531), -INT32_C(  1171445663) },
      { -INT32_C(  1238600191), -INT32_C(  1171445663) },
      { -INT32_C(  1701680446),  INT32_C(   225795531) },
      { -INT32_C(  1701680446), -INT32_C(  1238600191) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x2_t r00 = simde_vcopy_lane_s32(a, 0, b, 0);
    simde_int32x2_t r01 = simde_vcopy_lane_s32(a, 0, b, 1);
    simde_int32x2_t r10 = simde_vcopy_lane_s32(a, 1, b, 0);
    simde_int32x2_t r11 = simde_vcopy_lane_s32(a, 1, b, 1);

    simde_test_arm_neon_assert_equal_i32x2(r00, simde_vld1_s32(test_vec[i].r00));
    simde_test_arm_neon_assert_equal_i32x2(r01, simde_vld1_s32(test_vec[i].r01));
    simde_test_arm_neon_assert_equal_i32x2(r10, simde_vld1_s32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i32x2(r11, simde_vld1_s32(test_vec[i].r11));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r00 = simde_vcopy_lane_s32(a, 0, b, 0);
    simde_int32x2_t r01 = simde_vcopy_lane_s32(a, 0, b, 1);
    simde_int32x2_t r10 = simde_vcopy_lane_s32(a, 1, b, 0);
    simde_int32x2_t r11 = simde_vcopy_lane_s32(a, 1, b, 1);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r01, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r11, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r00[1];
  } test_vec[] = {
    { {  INT64_C(8113828097391158095) },
      { -INT64_C(590582389174642709) },
      { -INT64_C(590582389174642709) } },
    { { -INT64_C(139101902982008402) },
      { -INT64_C(2324368737080581745) },
      { -INT64_C(2324368737080581745) } },
    { {  INT64_C(1501602908344634063) },
      {  INT64_C(567943954333098302) },
      {  INT64_C(567943954333098302) } },
    { { -INT64_C(3453637575015359548) },
      {  INT64_C(3441876951233273467) },
      {  INT64_C(3441876951233273467) } },
    { { -INT64_C(4915331051121941957) },
      {  INT64_C(8920438462121261266) },
      {  INT64_C(8920438462121261266) } },
    { {  INT64_C(7630574466277382030) },
      { -INT64_C(7035549761693185500) },
      { -INT64_C(7035549761693185500) } },
    { { -INT64_C(8761313260935879654) },
      { -INT64_C(4811158338647994587) },
      { -INT64_C(4811158338647994587) } },
    { {  INT64_C(2316745406423380095) },
      {  INT64_C(1501791097429643221) },
      {  INT64_C(1501791097429643221) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);

    simde_int64x1_t r00 = simde_vcopy_lane_s64(a, 0, b, 0);

    simde_test_arm_neon_assert_equal_i64x1(r00, simde_vld1_s64(test_vec[i].r00));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r00 = simde_vcopy_lane_s64(a, 0, b, 0);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r00, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r00[8];
    uint8_t r13[8];
    uint8_t r35[8];
    uint8_t r67[8];
    uint8_t r71[8];
  } test_vec[] = {
    { {  UINT8_C(   28),  UINT8_C(  131),  UINT8_C(  188),  UINT8_C(   60),
         UINT8_C(  207),  UINT8_C(  214),  UINT8_C(    8),  UINT8_C(  235) },
      {  UINT8_C(   28),  UINT8_C(   32),  UINT8_C(  205),  UINT8_C(  168),
         UINT8_C(  242),  UINT8_C(  204),  UINT8_C(   93),  UINT8_C(  235) },
      {  UINT8_C(   28),  UINT8_C(  131),  UINT8_C(  188),  UINT8_C(   60),
         UINT8_C(  207),  UINT8_C(  214),  UINT8_C(    8),  UINT8_C(  235) },
      {  UINT8_C(   28),  UINT8_C(  168),  UINT8_C(  188),  UINT8_C(   60),
         UINT8_C(  207),  UINT8_C(  214),  UINT8_C(    8),  UINT8_C(  235) },
      {  UINT8_C(   28),  UINT8_C(  131),  UINT8_C(  188),  UINT8_C(  204),
         UINT8_C(  207),  UINT8_C(  214),  UINT8_C(    8),  UINT8_C(  235) },
      {  UINT8_C(   28),  UINT8_C(  131),  UINT8_C(  188),  UINT8_C(   60),
         UINT8_C(  207),  UINT8_C(  214),  UINT8_C(  235),  UINT8_C(  235) },
      {  UINT8_C(   28),  UINT8_C(  131),  UINT8_C(  188),  UINT8_C(   60),
         UINT8_C(  207),  UINT8_C(  214),  UINT8_C(    8),  UINT8_C(   32) } },
    { {  UINT8_C(  101),  UINT8_C(   32),  UINT8_C(   14),  UINT8_C(  224),
         UINT8_C(  185),  UINT8_C(  161),  UINT8_C(   63),  UINT8_C(  202) },
      {  UINT8_C(   60),  UINT8_C(  130),  UINT8_C(   95),  UINT8_C(  209),
         UINT8_C(  229),  UINT8_C(  184),  UINT8_C(  227),  UINT8_C(   12) },
      {  UINT8_C(   60),  UINT8_C(   32),  UINT8_C(   14),  UINT8_C(  224),
         UINT8_C(  185),  UINT8_C(  161),  UINT8_C(   63),  UINT8_C(  202) },
      {  UINT8_C(  101),  UINT8_C(  209),  UINT8_C(   14),  UINT8_C(  224),
         UINT8_C(  185),  UINT8_C(  161),  UINT8_C(   63),  UINT8_C(  202) },
      {  UINT8_C(  101),  UINT8_C(   32),  UINT8_C(   14),  UINT8_C(  184),
         UINT8_C(  185),  UINT8_C(  161),  UINT8_C(   63),  UINT8_C(  202) },
      {  UINT8_C(  101),  UINT8_C(   32),  UINT8_C(   14),  UINT8_C(  224),
         UINT8_C(  185),  UINT8_C(  161),  UINT8_C(   12),  UINT8_C(  202) },
      {  UINT8_C(  101),  UINT8_C(   32),  UINT8_C(   14),  UINT8_C(  224),
         UINT8_C(  185),  UINT8_C(  161),  UINT8_C(   63),  UINT8_C(  130) } },
    { {  UINT8_C(  172),  UINT8_C(   54),  UINT8_C(  173),  UINT8_C(  209),
         UINT8_C(  185),  UINT8_C(   49),  UINT8_C(   13),  UINT8_C(   59) },
      {  UINT8_C(   88),  UINT8_C(  109),  UINT8_C(  203),  UINT8_C(   38),
         UINT8_C(  153),  UINT8_C(  233),  UINT8_C(   84),  UINT8_C(   56) },
      {  UINT8_C(   88),  UINT8_C(   54),  UINT8_C(  173),  UINT8_C(  209),
         UINT8_C(  185),  UINT8_C(   49),  UINT8_C(   13),  UINT8_C(   59) },
      {  UINT8_C(  172),  UINT8_C(   38),  UINT8_C(  173),  UINT8_C(  209),
         UINT8_C(  185),  UINT8_C(   49),  UINT8_C(   13),  UINT8_C(   59) },
      {  UINT8_C(  172),  UINT8_C(   54),  UINT8_C(  173),  UINT8_C(  233),
         UINT8_C(  185),  UINT8_C(   49),  UINT8_C(   13),  UINT8_C(   59) },
      {  UINT8_C(  172),  UINT8_C(   54),  UINT8_C(  173),  UINT8_C(  209),
         UINT8_C(  185),  UINT8_C(   49),  UINT8_C(   56),  UINT8_C(   59) },
      {  UINT8_C(  172),  UINT8_C(   54),  UINT8_C(  173),  UINT8_C(  209),
         UINT8_C(  185),  UINT8_C(   49),  UINT8_C(   13),  UINT8_C(  109) } },
    { {  UINT8_C(  128),  UINT8_C(  179),  UINT8_C(  226),  UINT8_C(  249),
         UINT8_C(   55),  UINT8_C(   53),  UINT8_C(  195),  UINT8_C(  252) },
      {  UINT8_C(  137),  UINT8_C(  122),  UINT8_C(  243),  UINT8_C(   28),
         UINT8_C(  171),  UINT8_C(  202),  UINT8_C(  109),  UINT8_C(   75) },
      {  UINT8_C(  137),  UINT8_C(  179),  UINT8_C(  226),  UINT8_C(  249),
         UINT8_C(   55),  UINT8_C(   53),  UINT8_C(  195),  UINT8_C(  252) },
      {  UINT8_C(  128),  UINT8_C(   28),  UINT8_C(  226),  UINT8_C(  249),
         UINT8_C(   55),  UINT8_C(   53),  UINT8_C(  195),  UINT8_C(  252) },
      {  UINT8_C(  128),  UINT8_C(  179),  UINT8_C(  226),  UINT8_C(  202),
         UINT8_C(   55),  UINT8_C(   53),  UINT8_C(  195),  UINT8_C(  252) },
      {  UINT8_C(  128),  UINT8_C(  179),  UINT8_C(  226),  UINT8_C(  249),
         UINT8_C(   55),  UINT8_C(   53),  UINT8_C(   75),  UINT8_C(  252) },
      {  UINT8_C(  128),  UINT8_C(  179),  UINT8_C(  226),  UINT8_C(  249),
         UINT8_C(   55),  UINT8_C(   53),  UINT8_C(  195),  UINT8_C(  122) } },
    { {  UINT8_C(  197),  UINT8_C(  148),  UINT8_C(   89),  UINT8_C(  212),
         UINT8_C(  240),  UINT8_C(   71),  UINT8_C(  254),  UINT8_C(  179) },
      {  UINT8_C(   30),  UINT8_C(  170),  UINT8_C(   21),  UINT8_C(  164),
         UINT8_C(  167),  UINT8_C(   25),  UINT8_C(   80),  UINT8_C(   95) },
      {  UINT8_C(   30),  UINT8_C(  148),  UINT8_C(   89),  UINT8_C(  212),
         UINT8_C(  240),  UINT8_C(   71),  UINT8_C(  254),  UINT8_C(  179) },
      {  UINT8_C(  197),  UINT8_C(  164),  UINT8_C(   89),  UINT8_C(  212),
         UINT8_C(  240),  UINT8_C(   71),  UINT8_C(  254),  UINT8_C(  179) },
      {  UINT8_C(  197),  UINT8_C(  148),  UINT8_C(   89),  UINT8_C(   25),
         UINT8_C(  240),  UINT8_C(   71),  UINT8_C(  254),  UINT8_C(  179) },
      {  UINT8_C(  197),  UINT8_C(  148),  UINT8_C(   89),  UINT8_C(  212),
         UINT8_C(  240),  UINT8_C(   71),  UINT8_C(   95),  UINT8_C(  179) },
      {  UINT8_C(  197),  UINT8_C(  148),  UINT8_C(   89),  UINT8_C(  212),
         UINT8_C(  240),  UINT8_C(   71),  UINT8_C(  254),  UINT8_C(  170) } },
    { {  UINT8_C(    5),  UINT8_C(   43),  UINT8_C(   38),  UINT8_C(  233),
         UINT8_C(  100),  UINT8_C(  180),  UINT8_C(   31),  UINT8_C(   55) },
      {  UINT8_C(   70),  UINT8_C(  169),  UINT8_C(  168),  UINT8_C(  163),
         UINT8_C(   92),  UINT8_C(   80),  UINT8_C(   39),  UINT8_C(  246) },
      {  UINT8_C(   70),  UINT8_C(   43),  UINT8_C(   38),  UINT8_C(  233),
         UINT8_C(  100),  UINT8_C(  180),  UINT8_C(   31),  UINT8_C(   55) },
      {  UINT8_C(    5),  UINT8_C(  163),  UINT8_C(   38),  UINT8_C(  233),
         UINT8_C(  100),  UINT8_C(  180),  UINT8_C(   31),  UINT8_C(   55) },
      {  UINT8_C(    5),  UINT8_C(   43),  UINT8_C(   38),  UINT8_C(   80),
         UINT8_C(  100),  UINT8_C(  180),  UINT8_C(   31),  UINT8_C(   55) },
      {  UINT8_C(    5),  UINT8_C(   43),  UINT8_C(   38),  UINT8_C(  233),
         UINT8_C(  100),  UINT8_C(  180),  UINT8_C(  246),  UINT8_C(   55) },
      {  UINT8_C(    5),  UINT8_C(   43),  UINT8_C(   38),  UINT8_C(  233),
         UINT8_C(  100),  UINT8_C(  180),  UINT8_C(   31),  UINT8_C(  169) } },
    { {  UINT8_C(    4),  UINT8_C(  200),  UINT8_C(  242),  UINT8_C(  164),
         UINT8_C(  145),  UINT8_C(  212),  UINT8_C(   35),  UINT8_C(  159) },
      {  UINT8_C(  208),  UINT8_C(   92),  UINT8_C(   52),  UINT8_C(   62),
         UINT8_C(   71),  UINT8_C(  150),  UINT8_C(  218),  UINT8_C(  187) },
      {  UINT8_C(  208),  UINT8_C(  200),  UINT8_C(  242),  UINT8_C(  164),
         UINT8_C(  145),  UINT8_C(  212),  UINT8_C(   35),  UINT8_C(  159) },
      {  UINT8_C(    4),  UINT8_C(   62),  UINT8_C(  242),  UINT8_C(  164),
         UINT8_C(  145),  UINT8_C(  212),  UINT8_C(   35),  UINT8_C(  159) },
      {  UINT8_C(    4),  UINT8_C(  200),  UINT8_C(  242),  UINT8_C(  150),
         UINT8_C(  145),  UINT8_C(  212),  UINT8_C(   35),  UINT8_C(  159) },
      {  UINT8_C(    4),  UINT8_C(  200),  UINT8_C(  242),  UINT8_C(  164),
         UINT8_C(  145),  UINT8_C(  212),  UINT8_C(  187),  UINT8_C(  159) },
      {  UINT8_C(    4),  UINT8_C(  200),  UINT8_C(  242),  UINT8_C(  164),
         UINT8_C(  145),  UINT8_C(  212),  UINT8_C(   35),  UINT8_C(   92) } },
    { {  UINT8_C(  182),  UINT8_C(   17),  UINT8_C(  219),  UINT8_C(   25),
         UINT8_C(  214),  UINT8_C(  210),  UINT8_C(  208),  UINT8_C(   22) },
      {  UINT8_C(  183),  UINT8_C(   91),  UINT8_C(  242),  UINT8_C(   21),
         UINT8_C(  129),  UINT8_C(  215),  UINT8_C(   52),  UINT8_C(  219) },
      {  UINT8_C(  183),  UINT8_C(   17),  UINT8_C(  219),  UINT8_C(   25),
         UINT8_C(  214),  UINT8_C(  210),  UINT8_C(  208),  UINT8_C(   22) },
      {  UINT8_C(  182),  UINT8_C(   21),  UINT8_C(  219),  UINT8_C(   25),
         UINT8_C(  214),  UINT8_C(  210),  UINT8_C(  208),  UINT8_C(   22) },
      {  UINT8_C(  182),  UINT8_C(   17),  UINT8_C(  219),  UINT8_C(  215),
         UINT8_C(  214),  UINT8_C(  210),  UINT8_C(  208),  UINT8_C(   22) },
      {  UINT8_C(  182),  UINT8_C(   17),  UINT8_C(  219),  UINT8_C(   25),
         UINT8_C(  214),  UINT8_C(  210),  UINT8_C(  219),  UINT8_C(   22) },
      {  UINT8_C(  182),  UINT8_C(   17),  UINT8_C(  219),  UINT8_C(   25),
         UINT8_C(  214),  UINT8_C(  210),  UINT8_C(  208),  UINT8_C(   91) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);

    simde_uint8x8_t r00 = simde_vcopy_lane_u8(a, 0, b, 0);
    simde_uint8x8_t r13 = simde_vcopy_lane_u8(a, 1, b, 3);
    simde_uint8x8_t r35 = simde_vcopy_lane_u8(a, 3, b, 5);
    simde_uint8x8_t r67 = simde_vcopy_lane_u8(a, 6, b, 7);
    simde_uint8x8_t r71 = simde_vcopy_lane_u8(a, 7, b, 1);

    simde_test_arm_neon_assert_equal_u8x8(r00, simde_vld1_u8(test_vec[i].r00));
    simde_test_arm_neon_assert_equal_u8x8(r13, simde_vld1_u8(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u8x8(r35, simde_vld1_u8(test_vec[i].r35));
    simde_test_arm_neon_assert_equal_u8x8(r67, simde_vld1_u8(test_vec[i].r67));
    simde_test_arm_neon_assert_equal_u8x8(r71, simde_vld1_u8(test_vec[i].r71));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r00 = simde_vcopy_lane_u8(a, 0, b, 0);
    simde_uint8x8_t r13 = simde_vcopy_lane_u8(a, 1, b, 3);
    simde_uint8x8_t r35 = simde_vcopy_lane_u8(a, 3, b, 5);
    simde_uint8x8_t r67 = simde_vcopy_lane_u8(a, 6, b, 7);
    simde_uint8x8_t r71 = simde_vcopy_lane_u8(a, 7, b, 1);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r35, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r67, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r71, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r00[4];
    uint16_t r01[4];
    uint16_t r13[4];
    uint16_t r22[4];
    uint16_t r33[4];
  } test_vec[] = {
    { {  UINT16_C(   48859),  UINT16_C(   37110),  UINT16_C(   57365),  UINT16_C(   56893) },
      {  UINT16_C(   44198),  UINT16_C(   17208),  UINT16_C(   42682),  UINT16_C(   14084) },
      {  UINT16_C(   44198),  UINT16_C(   37110),  UINT16_C(   57365),  UINT16_C(   56893) },
      {  UINT16_C(   17208),  UINT16_C(   37110),  UINT16_C(   57365),  UINT16_C(   56893) },
      {  UINT16_C(   48859),  UINT16_C(   14084),  UINT16_C(   57365),  UINT16_C(   56893) },
      {  UINT16_C(   48859),  UINT16_C(   37110),  UINT16_C(   42682),  UINT16_C(   56893) },
      {  UINT16_C(   48859),  UINT16_C(   37110),  UINT16_C(   57365),  UINT16_C(   14084) } },
    { {  UINT16_C(   32518),  UINT16_C(   27430),  UINT16_C(   25434),  UINT16_C(   15734) },
      {  UINT16_C(   17681),  UINT16_C(    1758),  UINT16_C(   14425),  UINT16_C(   18152) },
      {  UINT16_C(   17681),  UINT16_C(   27430),  UINT16_C(   25434),  UINT16_C(   15734) },
      {  UINT16_C(    1758),  UINT16_C(   27430),  UINT16_C(   25434),  UINT16_C(   15734) },
      {  UINT16_C(   32518),  UINT16_C(   18152),  UINT16_C(   25434),  UINT16_C(   15734) },
      {  UINT16_C(   32518),  UINT16_C(   27430),  UINT16_C(   14425),  UINT16_C(   15734) },
      {  UINT16_C(   32518),  UINT16_C(   27430),  UINT16_C(   25434),  UINT16_C(   18152) } },
    { {  UINT16_C(   35029),  UINT16_C(   40800),  UINT16_C(   57927),  UINT16_C(   58796) },
      {  UINT16_C(   38243),  UINT16_C(   28472),  UINT16_C(   61138),  UINT16_C(   52923) },
      {  UINT16_C(   38243),  UINT16_C(   40800),  UINT16_C(   57927),  UINT16_C(   58796) },
      {  UINT16_C(   28472),  UINT16_C(   40800),  UINT16_C(   57927),  UINT16_C(   58796) },
      {  UINT16_C(   35029),  UINT16_C(   52923),  UINT16_C(   57927),  UINT16_C(   58796) },
      {  UINT16_C(   35029),  UINT16_C(   40800),  UINT16_C(   61138),  UINT16_C(   58796) },
      {  UINT16_C(   35029),  UINT16_C(   40800),  UINT16_C(   57927),  UINT16_C(   52923) } },
    { {  UINT16_C(   14462),  UINT16_C(   31329),  UINT16_C(   44021),  UINT16_C(   37135) },
      {  UINT16_C(   36643),  UINT16_C(    8499),  UINT16_C(   55329),  UINT16_C(   45901) },
      {  UINT16_C(   36643),  UINT16_C(   31329),  UINT16_C(   44021),  UINT16_C(   37135) },
      {  UINT16_C(    8499),  UINT16_C(   31329),  UINT16_C(   44021),  UINT16_C(   37135) },
      {  UINT16_C(   14462),  UINT16_C(   45901),  UINT16_C(   44021),  UINT16_C(   37135) },
      {  UINT16_C(   14462),  UINT16_C(   31329),  UINT16_C(   55329),  UINT16_C(   37135) },
      {  UINT16_C(   14462),  UINT16_C(   31329),  UINT16_C(   44021),  UINT16_C(   45901) } },
    { {  UINT16_C(   18155),  UINT16_C(   29451),  UINT16_C(    9594),  UINT16_C(   47476) },
      {  UINT16_C(   36782),  UINT16_C(   10647),  UINT16_C(   14223),  UINT16_C(    3446) },
      {  UINT16_C(   36782),  UINT16_C(   29451),  UINT16_C(    9594),  UINT16_C(   47476) },
      {  UINT16_C(   10647),  UINT16_C(   29451),  UINT16_C(    9594),  UINT16_C(   47476) },
      {  UINT16_C(   18155),  UINT16_C(    3446),  UINT16_C(    9594),  UINT16_C(   47476) },
      {  UINT16_C(   18155),  UINT16_C(   29451),  UINT16_C(   14223),  UINT16_C(   47476) },
      {  UINT16_C(   18155),  UINT16_C(   29451),  UINT16_C(    9594),  UINT16_C(    3446) } },
    { {  UINT16_C(   39055),  UINT16_C(   58824),  UINT16_C(   16709),  UINT16_C(   26292) },
      {  UINT16_C(   52894),  UINT16_C(   53794),  UINT16_C(   27364),  UINT16_C(    9410) },
      {  UINT16_C(   52894),  UINT16_C(   58824),  UINT16_C(   16709),  UINT16_C(   26292) },
      {  UINT16_C(   53794),  UINT16_C(   58824),  UINT16_C(   16709),  UINT16_C(   26292) },
      {  UINT16_C(   39055),  UINT16_C(    9410),  UINT16_C(   16709),  UINT16_C(   26292) },
      {  UINT16_C(   39055),  UINT16_C(   58824),  UINT16_C(   27364),  UINT16_C(   26292) },
      {  UINT16_C(   39055),  UINT16_C(   58824),  UINT16_C(   16709),  UINT16_C(    9410) } },
    { {  UINT16_C(    3714),  UINT16_C(   45544),  UINT16_C(   10782),  UINT16_C(   53336) },
      {  UINT16_C(   53247),  UINT16_C(   29686),  UINT16_C(   23527),  UINT16_C(   52801) },
      {  UINT16_C(   53247),  UINT16_C(   45544),  UINT16_C(   10782),  UINT16_C(   53336) },
      {  UINT16_C(   29686),  UINT16_C(   45544),  UINT16_C(   10782),  UINT16_C(   53336) },
      {  UINT16_C(    3714),  UINT16_C(   52801),  UINT16_C(   10782),  UINT16_C(   53336) },
      {  UINT16_C(    3714),  UINT16_C(   45544),  UINT16_C(   23527),  UINT16_C(   53336) },
      {  UINT16_C(    3714),  UINT16_C(   45544),  UINT16_C(   10782),  UINT16_C(   52801) } },
    { {  UINT16_C(     956),  UINT16_C(   38216),  UINT16_C(   64583),  UINT16_C(   19844) },
      {  UINT16_C(   55529),  UINT16_C(    5655),  UINT16_C(   39007),  UINT16_C(   36038) },
      {  UINT16_C(   55529),  UINT16_C(   38216),  UINT16_C(   64583),  UINT16_C(   19844) },
      {  UINT16_C(    5655),  UINT16_C(   38216),  UINT16_C(   64583),  UINT16_C(   19844) },
      {  UINT16_C(     956),  UINT16_C(   36038),  UINT16_C(   64583),  UINT16_C(   19844) },
      {  UINT16_C(     956),  UINT16_C(   38216),  UINT16_C(   39007),  UINT16_C(   19844) },
      {  UINT16_C(     956),  UINT16_C(   38216),  UINT16_C(   64583),  UINT16_C(   36038) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x4_t r00 = simde_vcopy_lane_u16(a, 0, b, 0);
    simde_uint16x4_t r01 = simde_vcopy_lane_u16(a, 0, b, 1);
    simde_uint16x4_t r13 = simde_vcopy_lane_u16(a, 1, b, 3);
    simde_uint16x4_t r22 = simde_vcopy_lane_u16(a, 2, b, 2);
    simde_uint16x4_t r33 = simde_vcopy_lane_u16(a, 3, b, 3);

    simde_test_arm_neon_assert_equal_u16x4(r00, simde_vld1_u16(test_vec[i].r00));
    simde_test_arm_neon_assert_equal_u16x4(r01, simde_vld1_u16(test_vec[i].r01));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r22, simde_vld1_u16(test_vec[i].r22));
    simde_test_arm_neon_assert_equal_u16x4(r33, simde_vld1_u16(test_vec[i].r33));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r00 = simde_vcopy_lane_u16(a, 0, b, 0);
    simde_uint16x4_t r01 = simde_vcopy_lane_u16(a, 0, b, 1);
    simde_uint16x4_t r13 = simde_vcopy_lane_u16(a, 1, b, 3);
    simde_uint16x4_t r22 = simde_vcopy_lane_u16(a, 2, b, 2);
    simde_uint16x4_t r33 = simde_vcopy_lane_u16(a, 3, b, 3);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r01, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r22, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r33, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r00[2];
    uint32_t r01[2];
    uint32_t r10[2];
    uint32_t r11[2];
  } test_vec[] = {
    { {  UINT32_C(  1845930776),  UINT32_C(  3844134345) },
      {  UINT32_C(  1849881073),  UINT32_C(  3913321945) },
      {  UINT32_C(  1849881073),  UINT32_C(  3844134345) },
      {  UINT32_C(  3913321945),  UINT32_C(  3844134345) },
      {  UINT32_C(  1845930776),  UINT32_C(  1849881073) },
      {  UINT32_C(  1845930776),  UINT32_C(  3913321945) } },
    { {  UINT32_C(  2795833089),  UINT32_C(  3073381716) },
      {  UINT32_C(  3744189582),  UINT32_C(  2223479106) },
      {  UINT32_C(  3744189582),  UINT32_C(  3073381716) },
      {  UINT32_C(  2223479106),  UINT32_C(  3073381716) },
      {  UINT32_C(  2795833089),  UINT32_C(  3744189582) },
      {  UINT32_C(  2795833089),  UINT32_C(  2223479106) } },
    { {  UINT32_C(   850448814),  UINT32_C(  3018325402) },
      {  UINT32_C(  4276357940),  UINT32_C(  1105496326) },
      {  UINT32_C(  4276357940),  UINT32_C(  3018325402) },
      {  UINT32_C(  1105496326),  UINT32_C(  3018325402) },
      {  UINT32_C(   850448814),  UINT32_C(  4276357940) },
      {  UINT32_C(   850448814),  UINT32_C(  1105496326) } },
    { {  UINT32_C(   316065699),  UINT32_C(  3151513231) },
      {  UINT32_C(   361459012),  UINT32_C(  3957792290) },
      {  UINT32_C(   361459012),  UINT32_C(  3151513231) },
      {  UINT32_C(  3957792290),  UINT32_C(  3151513231) },
      {  UINT32_C(   316065699),  UINT32_C(   361459012) },
      {  UINT32_C(   316065699),  UINT32_C(  3957792290) } },
    { {  UINT32_C(  4188653768),  UINT32_C(  4220115240) },
      {  UINT32_C(   923671752),  UINT32_C(  2829963684) },
      {  UINT32_C(   923671752),  UINT32_C(  4220115240) },
      {  UINT32_C(  2829963684),  UINT32_C(  4220115240) },
      {  UINT32_C(  4188653768),  UINT32_C(   923671752) },
      {  UINT32_C(  4188653768),  UINT32_C(  2829963684) } },
    { {  UINT32_C(  2782303633),  UINT32_C(  2680224312) },
      {  UINT32_C(  2278952676),  UINT32_C(  3042603857) },
      {  UINT32_C(  2278952676),  UINT32_C(  2680224312) },
      {  UINT32_C(  3042603857),  UINT32_C(  2680224312) },
      {  UINT32_C(  2782303633),  UINT32_C(  2278952676) },
      {  UINT32_C(  2782303633),  UINT32_C(  3042603857) } },
    { {  UINT32_C(  2497286721),  UINT32_C(  2408904758) },
      {  UINT32_C(  1300967812),  UINT32_C(  2801168690) },
      {  UINT32_C(  1300967812),  UINT32_C(  2408904758) },
      {  UINT32_C(  2801168690),  UINT32_C(  2408904758) },
      {  UINT32_C(  2497286721),  UINT32_C(  1300967812) },
      {  UINT32_C(  2497286721),  UINT32_C(  2801168690) } },
    { {  UINT32_C(  3765890668),  UINT32_C(  3157704832) },
      {  UINT32_C(  3135164014),  UINT32_C(  1487743293) },
      {  UINT32_C(  3135164014),  UINT32_C(  3157704832) },
      {  UINT32_C(  1487743293),  UINT32_C(  3157704832) },
      {  UINT32_C(  3765890668),  UINT32_C(  3135164014) },
      {  UINT32_C(  3765890668),  UINT32_C(  1487743293) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x2_t r00 = simde_vcopy_lane_u32(a, 0, b, 0);
    simde_uint32x2_t r01 = simde_vcopy_lane_u32(a, 0, b, 1);
    simde_uint32x2_t r10 = simde_vcopy_lane_u32(a, 1, b, 0);
    simde_uint32x2_t r11 = simde_vcopy_lane_u32(a, 1, b, 1);

    simde_test_arm_neon_assert_equal_u32x2(r00, simde_vld1_u32(test_vec[i].r00));
    simde_test_arm_neon_assert_equal_u32x2(r01, simde_vld1_u32(test_vec[i].r01));
    simde_test_arm_neon_assert_equal_u32x2(r10, simde_vld1_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x2(r11, simde_vld1_u32(test_vec[i].r11));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r00 = simde_vcopy_lane_u32(a, 0, b, 0);
    simde_uint32x2_t r01 = simde_vcopy_lane_u32(a, 0, b, 1);
    simde_uint32x2_t r10 = simde_vcopy_lane_u32(a, 1, b, 0);
    simde_uint32x2_t r11 = simde_vcopy_lane_u32(a, 1, b, 1);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r01, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r11, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r00[1];
  } test_vec[] = {
    { {  UINT64_C( 3055880545951251893) },
      {  UINT64_C( 4769400864024572261) },
      {  UINT64_C( 4769400864024572261) } },
    { {  UINT64_C(10022377050862213090) },
      {  UINT64_C(  709100166864470872) },
      {  UINT64_C(  709100166864470872) } },
    { {  UINT64_C(14501613329003973833) },
      {  UINT64_C( 1949783300048066942) },
      {  UINT64_C( 1949783300048066942) } },
    { {  UINT64_C( 4269142848878481025) },
      {  UINT64_C(13395296486420650805) },
      {  UINT64_C(13395296486420650805) } },
    { {  UINT64_C(16135277955010204355) },
      {  UINT64_C( 8074912141013526827) },
      {  UINT64_C( 8074912141013526827) } },
    { {  UINT64_C( 2540591871860474721) },
      {  UINT64_C( 3018004574689373093) },
      {  UINT64_C( 3018004574689373093) } },
    { {  UINT64_C( 6078212644320502818) },
      {  UINT64_C( 5640613611397537144) },
      {  UINT64_C( 5640613611397537144) } },
    { {  UINT64_C(17738531384755593185) },
      {  UINT64_C(12574375413058459129) },
      {  UINT64_C(12574375413058459129) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);

    simde_uint64x1_t r00 = simde_vcopy_lane_u64(a, 0, b, 0);

    simde_test_arm_neon_assert_equal_u64x1(r00, simde_vld1_u64(test_vec[i].r00));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r00 = simde_vcopy_lane_u64(a, 0, b, 0);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r00, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t b[2];
    simde_float32_t r00[2];
    simde_float32_t r01[2];
    simde_float32_t r10[2];
    simde_float32_t r11[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(7872.434), -SIMDE_FLOAT32_C(5331.952) },
      { -SIMDE_FLOAT32_C( 676.709),  SIMDE_FLOAT32_C(3911.896) },
      { -SIMDE_FLOAT32_C( 676.709), -SIMDE_FLOAT32_C(5331.952) },
      {  SIMDE_FLOAT32_C(3911.896), -SIMDE_FLOAT32_C(5331.952) },
      { -SIMDE_FLOAT32_C(7872.434), -SIMDE_FLOAT32_C( 676.709) },
      { -SIMDE_FLOAT32_C(7872.434),  SIMDE_FLOAT32_C(3911.896) } },
    { { -SIMDE_FLOAT32_C(7795.166),  SIMDE_FLOAT32_C(5870.333) },
      {  SIMDE_FLOAT32_C(7542.590),  SIMDE_FLOAT32_C(9623.578) },
      {  SIMDE_FLOAT32_C(7542.590),  SIMDE_FLOAT32_C(5870.333) },
      {  SIMDE_FLOAT32_C(9623.578),  SIMDE_FLOAT32_C(5870.333) },
      { -SIMDE_FLOAT32_C(7795.166),  SIMDE_FLOAT32_C(7542.590) },
      { -SIMDE_FLOAT32_C(7795.166),  SIMDE_FLOAT32_C(9623.578) } },
    { {  SIMDE_FLOAT32_C(9280.762), -SIMDE_FLOAT32_C(9574.360) },
      {  SIMDE_FLOAT32_C(1067.386),  SIMDE_FLOAT32_C(4955.505) },
      {  SIMDE_FLOAT32_C(1067.386), -SIMDE_FLOAT32_C(9574.360) },
      {  SIMDE_FLOAT32_C(4955.505), -SIMDE_FLOAT32_C(9574.360) },
      {  SIMDE_FLOAT32_C(9280.762),  SIMDE_FLOAT32_C(1067.386) },
      {  SIMDE_FLOAT32_C(9280.762),  SIMDE_FLOAT32_C(4955.505) } },
    { { -SIMDE_FLOAT32_C(5985.849),  SIMDE_FLOAT32_C(4135.134) },
      { -SIMDE_FLOAT32_C(1607.159), -SIMDE_FLOAT32_C(7509.242) },
      { -SIMDE_FLOAT32_C(1607.159),  SIMDE_FLOAT32_C(4135.134) },
      { -SIMDE_FLOAT32_C(7509.242),  SIMDE_FLOAT32_C(4135.134) },
      { -SIMDE_FLOAT32_C(5985.849), -SIMDE_FLOAT32_C(1607.159) },
      { -SIMDE_FLOAT32_C(5985.849), -SIMDE_FLOAT32_C(7509.242) } },
    { { -SIMDE_FLOAT32_C(4353.862),  SIMDE_FLOAT32_C(3343.175) },
      {  SIMDE_FLOAT32_C(6301.056),  SIMDE_FLOAT32_C(6250.665) },
      {  SIMDE_FLOAT32_C(6301.056),  SIMDE_FLOAT32_C(3343.175) },
      {  SIMDE_FLOAT32_C(6250.665),  SIMDE_FLOAT32_C(3343.175) },
      { -SIMDE_FLOAT32_C(4353.862),  SIMDE_FLOAT32_C(6301.056) },
      { -SIMDE_FLOAT32_C(4353.862),  SIMDE_FLOAT32_C(6250.665) } },
    { { -SIMDE_FLOAT32_C(2707.744), -SIMDE_FLOAT32_C(8746.154) },
      { -SIMDE_FLOAT32_C(4845.834), -SIMDE_FLOAT32_C(5771.376) },
      { -SIMDE_FLOAT32_C(4845.834), -SIMDE_FLOAT32_C(8746.154) },
      { -SIMDE_FLOAT32_C(5771.376), -SIMDE_FLOAT32_C(8746.154) },
      { -SIMDE_FLOAT32_C(2707.744), -SIMDE_FLOAT32_C(4845.834) },
      { -SIMDE_FLOAT32_C(2707.744), -SIMDE_FLOAT32_C(5771.376) } },
    { { -SIMDE_FLOAT32_C(5351.658),  SIMDE_FLOAT32_C(4436.026) },
      {  SIMDE_FLOAT32_C( 568.685),  SIMDE_FLOAT32_C(2344.722) },
      {  SIMDE_FLOAT32_C( 568.685),  SIMDE_FLOAT32_C(4436.026) },
      {  SIMDE_FLOAT32_C(2344.722),  SIMDE_FLOAT32_C(4436.026) },
      { -SIMDE_FLOAT32_C(5351.658),  SIMDE_FLOAT32_C( 568.685) },
      { -SIMDE_FLOAT32_C(5351.658),  SIMDE_FLOAT32_C(2344.722) } },
    { { -SIMDE_FLOAT32_C(4624.979), -SIMDE_FLOAT32_C(3015.579) },
      {  SIMDE_FLOAT32_C(7762.184),  SIMDE_FLOAT32_C(3041.834) },
      {  SIMDE_FLOAT32_C(7762.184), -SIMDE_FLOAT32_C(3015.579) },
      {  SIMDE_FLOAT32_C(3041.834), -SIMDE_FLOAT32_C(3015.579) },
      { -SIMDE_FLOAT32_C(4624.979),  SIMDE_FLOAT32_C(7762.184) },
      { -SIMDE_FLOAT32_C(4624.979),  SIMDE_FLOAT32_C(3041.834) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);

    simde_float32x2_t r00 = simde_vcopy_lane_f32(a, 0, b, 0);
    simde_float32x2_t r01 = simde_vcopy_lane_f32(a, 0, b, 1);
    simde_float32x2_t r10 = simde_vcopy_lane_f32(a, 1, b, 0);
    simde_float32x2_t r11 = simde_vcopy_lane_f32(a, 1, b, 1);

    simde_test_arm_neon_assert_equal_f32x2(r00, simde_vld1_f32(test_vec[i].r00), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r01, simde_vld1_f32(test_vec[i].r01), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r10, simde_vld1_f32(test_vec[i].r10), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r11, simde_vld1_f32(test_vec[i].r11), INT_MAX);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r00 = simde_vcopy_lane_f32(a, 0, b, 0);
    simde_float32x2_t r01 = simde_vcopy_lane_f32(a, 0, b, 1);
    simde_float32x2_t r10 = simde_vcopy_lane_f32(a, 1, b, 0);
    simde_float32x2_t r11 = simde_vcopy_lane_f32(a, 1, b, 1);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r01, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r11, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[1];
    simde_float64_t b[1];
    simde_float64_t r00[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C(   75436.250) },
      { -SIMDE_FLOAT64_C(  308233.375) },
      { -SIMDE_FLOAT64_C(  308233.375) } },
    { {  SIMDE_FLOAT64_C(  679840.750) },
      { -SIMDE_FLOAT64_C(  665586.875) },
      { -SIMDE_FLOAT64_C(  665586.875) } },
    { {  SIMDE_FLOAT64_C(  211015.500) },
      { -SIMDE_FLOAT64_C(  944742.812) },
      { -SIMDE_FLOAT64_C(  944742.812) } },
    { { -SIMDE_FLOAT64_C(  696791.812) },
      {  SIMDE_FLOAT64_C(  948299.000) },
      {  SIMDE_FLOAT64_C(  948299.000) } },
    { { -SIMDE_FLOAT64_C(  100363.250) },
      {  SIMDE_FLOAT64_C(  741415.125) },
      {  SIMDE_FLOAT64_C(  741415.125) } },
    { {  SIMDE_FLOAT64_C(  832180.750) },
      {  SIMDE_FLOAT64_C(  235085.625) },
      {  SIMDE_FLOAT64_C(  235085.625) } },
    { { -SIMDE_FLOAT64_C(  800552.562) },
      { -SIMDE_FLOAT64_C(  864425.500) },
      { -SIMDE_FLOAT64_C(  864425.500) } },
    { {  SIMDE_FLOAT64_C(  434821.625) },
      {  SIMDE_FLOAT64_C(  765610.500) },
      {  SIMDE_FLOAT64_C(  765610.500) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);

    simde_float64x1_t r00 = simde_vcopy_lane_f64(a, 0, b, 0);

    simde_test_arm_neon_assert_equal_f64x1(r00, simde_vld1_f64(test_vec[i].r00), INT_MAX);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r00 = simde_vcopy_lane_f64(a, 0, b, 0);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r00, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[16];
    int8_t r0_0[8];
    int8_t r1_3[8];
    int8_t r3_8[8];
    int8_t r6_12[8];
    int8_t r7_15[8];
  } test_vec[] = {
    { { -INT8_C(    35),  INT8_C(   102), -INT8_C(    10), -INT8_C(    58),
         INT8_C(    85),  INT8_C(    88),  INT8_C(     9), -INT8_C(    69) },
      { -INT8_C(    55), -INT8_C(     1), -INT8_C(    62),  INT8_C(   105),
         INT8_C(    72), -INT8_C(    82), -INT8_C(    33),  INT8_C(    53),
         INT8_C(    74), -INT8_C(    56),  INT8_C(    88),  INT8_C(    16),
        -INT8_C(    32),  INT8_C(    35),  INT8_C(    39), -INT8_C(     2) },
      { -INT8_C(    55),  INT8_C(   102), -INT8_C(    10), -INT8_C(    58),
         INT8_C(    85),  INT8_C(    88),  INT8_C(     9), -INT8_C(    69) },
      { -INT8_C(    35),  INT8_C(   105), -INT8_C(    10), -INT8_C(    58),
         INT8_C(    85),  INT8_C(    88),  INT8_C(     9), -INT8_C(    69) },
      { -INT8_C(    35),  INT8_C(   102), -INT8_C(    10),  INT8_C(    74),
         INT8_C(    85),  INT8_C(    88),  INT8_C(     9), -INT8_C(    69) },
      { -INT8_C(    35),  INT8_C(   102), -INT8_C(    10), -INT8_C(    58),
         INT8_C(    85),  INT8_C(    88), -INT8_C(    32), -INT8_C(    69) },
      { -INT8_C(    35),  INT8_C(   102), -INT8_C(    10), -INT8_C(    58),
         INT8_C(    85),  INT8_C(    88),  INT8_C(     9), -INT8_C(     2) } },
    { { -INT8_C(    65), -INT8_C(   111),  INT8_C(     3), -INT8_C(    57),
        -INT8_C(    57),        INT8_MIN, -INT8_C(   116), -INT8_C(    29) },
      { -INT8_C(   115), -INT8_C(    86), -INT8_C(    27),  INT8_C(   110),
         INT8_C(    88),  INT8_C(    80),  INT8_C(   102), -INT8_C(     9),
        -INT8_C(    78), -INT8_C(    88), -INT8_C(    17), -INT8_C(   111),
         INT8_C(   124), -INT8_C(     6),  INT8_C(    54),  INT8_C(    36) },
      { -INT8_C(   115), -INT8_C(   111),  INT8_C(     3), -INT8_C(    57),
        -INT8_C(    57),        INT8_MIN, -INT8_C(   116), -INT8_C(    29) },
      { -INT8_C(    65),  INT8_C(   110),  INT8_C(     3), -INT8_C(    57),
        -INT8_C(    57),        INT8_MIN, -INT8_C(   116), -INT8_C(    29) },
      { -INT8_C(    65), -INT8_C(   111),  INT8_C(     3), -INT8_C(    78),
        -INT8_C(    57),        INT8_MIN, -INT8_C(   116), -INT8_C(    29) },
      { -INT8_C(    65), -INT8_C(   111),  INT8_C(     3), -INT8_C(    57),
        -INT8_C(    57),        INT8_MIN,  INT8_C(   124), -INT8_C(    29) },
      { -INT8_C(    65), -INT8_C(   111),  INT8_C(     3), -INT8_C(    57),
        -INT8_C(    57),        INT8_MIN, -INT8_C(   116),  INT8_C(    36) } },
    { { -INT8_C(     1), -INT8_C(     3), -INT8_C(    46), -INT8_C(    19),
        -INT8_C(    58),  INT8_C(    65), -INT8_C(    22), -INT8_C(   118) },
      { -INT8_C(    30),  INT8_C(   120),  INT8_C(    48), -INT8_C(   112),
        -INT8_C(   117), -INT8_C(    67),  INT8_C(    61),  INT8_C(    19),
         INT8_C(    99),  INT8_C(   114),  INT8_C(   100), -INT8_C(    50),
         INT8_C(   110),  INT8_C(    89),  INT8_C(    99), -INT8_C(    65) },
      { -INT8_C(    30), -INT8_C(     3), -INT8_C(    46), -INT8_C(    19),
        -INT8_C(    58),  INT8_C(    65), -INT8_C(    22), -INT8_C(   118) },
      { -INT8_C(     1), -INT8_C(   112), -INT8_C(    46), -INT8_C(    19),
        -INT8_C(    58),  INT8_C(    65), -INT8_C(    22), -INT8_C(   118) },
      { -INT8_C(     1), -INT8_C(     3), -INT8_C(    46),  INT8_C(    99),
        -INT8_C(    58),  INT8_C(    65), -INT8_C(    22), -INT8_C(   118) },
      { -INT8_C(     1), -INT8_C(     3), -INT8_C(    46), -INT8_C(    19),
        -INT8_C(    58),  INT8_C(    65),  INT8_C(   110), -INT8_C(   118) },
      { -INT8_C(     1), -INT8_C(     3), -INT8_C(    46), -INT8_C(    19),
        -INT8_C(    58),  INT8_C(    65), -INT8_C(    22), -INT8_C(    65) } },
    { {  INT8_C(    19),  INT8_C(    70),  INT8_C(    77),  INT8_C(     8),
         INT8_C(    50), -INT8_C(   109),  INT8_C(    80),  INT8_C(    45) },
      {  INT8_C(   118), -INT8_C(    88),  INT8_C(   104),  INT8_C(    19),
        -INT8_C(   118), -INT8_C(   113), -INT8_C(    59),  INT8_C(     8),
        -INT8_C(    64), -INT8_C(    37),  INT8_C(    34), -INT8_C(    33),
        -INT8_C(   123), -INT8_C(    39),  INT8_C(     7),  INT8_C(    35) },
      {  INT8_C(   118),  INT8_C(    70),  INT8_C(    77),  INT8_C(     8),
         INT8_C(    50), -INT8_C(   109),  INT8_C(    80),  INT8_C(    45) },
      {  INT8_C(    19),  INT8_C(    19),  INT8_C(    77),  INT8_C(     8),
         INT8_C(    50), -INT8_C(   109),  INT8_C(    80),  INT8_C(    45) },
      {  INT8_C(    19),  INT8_C(    70),  INT8_C(    77), -INT8_C(    64),
         INT8_C(    50), -INT8_C(   109),  INT8_C(    80),  INT8_C(    45) },
      {  INT8_C(    19),  INT8_C(    70),  INT8_C(    77),  INT8_C(     8),
         INT8_C(    50), -INT8_C(   109), -INT8_C(   123),  INT8_C(    45) },
      {  INT8_C(    19),  INT8_C(    70),  INT8_C(    77),  INT8_C(     8),
         INT8_C(    50), -INT8_C(   109),  INT8_C(    80),  INT8_C(    35) } },
    { { -INT8_C(    20),  INT8_C(    35), -INT8_C(    98),  INT8_C(   102),
         INT8_C(   105), -INT8_C(    62), -INT8_C(    46),  INT8_C(     1) },
      { -INT8_C(    49), -INT8_C(    82),  INT8_C(   116),  INT8_C(    35),
        -INT8_C(    40), -INT8_C(   127), -INT8_C(    23), -INT8_C(    22),
         INT8_C(    94), -INT8_C(    63), -INT8_C(    77),  INT8_C(   101),
         INT8_C(   123), -INT8_C(    24), -INT8_C(    51),  INT8_C(    56) },
      { -INT8_C(    49),  INT8_C(    35), -INT8_C(    98),  INT8_C(   102),
         INT8_C(   105), -INT8_C(    62), -INT8_C(    46),  INT8_C(     1) },
      { -INT8_C(    20),  INT8_C(    35), -INT8_C(    98),  INT8_C(   102),
         INT8_C(   105), -INT8_C(    62), -INT8_C(    46),  INT8_C(     1) },
      { -INT8_C(    20),  INT8_C(    35), -INT8_C(    98),  INT8_C(    94),
         INT8_C(   105), -INT8_C(    62), -INT8_C(    46),  INT8_C(     1) },
      { -INT8_C(    20),  INT8_C(    35), -INT8_C(    98),  INT8_C(   102),
         INT8_C(   105), -INT8_C(    62),  INT8_C(   123),  INT8_C(     1) },
      { -INT8_C(    20),  INT8_C(    35), -INT8_C(    98),  INT8_C(   102),
         INT8_C(   105), -INT8_C(    62), -INT8_C(    46),  INT8_C(    56) } },
    { { -INT8_C(    83), -INT8_C(    91), -INT8_C(   122), -INT8_C(    55),
         INT8_C(    71), -INT8_C(    34),  INT8_C(     2), -INT8_C(    43) },
      {  INT8_C(    36),  INT8_C(    74),  INT8_C(    23),  INT8_C(     4),
         INT8_C(    54), -INT8_C(     8), -INT8_C(    68), -INT8_C(    46),
         INT8_C(   110),  INT8_C(     0),  INT8_C(    46), -INT8_C(   123),
         INT8_C(    54),  INT8_C(    39),  INT8_C(   121), -INT8_C(    55) },
      {  INT8_C(    36), -INT8_C(    91), -INT8_C(   122), -INT8_C(    55),
         INT8_C(    71), -INT8_C(    34),  INT8_C(     2), -INT8_C(    43) },
      { -INT8_C(    83),  INT8_C(     4), -INT8_C(   122), -INT8_C(    55),
         INT8_C(    71), -INT8_C(    34),  INT8_C(     2), -INT8_C(    43) },
      { -INT8_C(    83), -INT8_C(    91), -INT8_C(   122),  INT8_C(   110),
         INT8_C(    71), -INT8_C(    34),  INT8_C(     2), -INT8_C(    43) },
      { -INT8_C(    83), -INT8_C(    91), -INT8_C(   122), -INT8_C(    55),
         INT8_C(    71), -INT8_C(    34),  INT8_C(    54), -INT8_C(    43) },
      { -INT8_C(    83), -INT8_C(    91), -INT8_C(   122), -INT8_C(    55),
         INT8_C(    71), -INT8_C(    34),  INT8_C(     2), -INT8_C(    55) } },
    { { -INT8_C(    48), -INT8_C(    42), -INT8_C(   114), -INT8_C(   127),
         INT8_C(     2), -INT8_C(    91), -INT8_C(     1),  INT8_C(    31) },
      {  INT8_C(    72), -INT8_C(    60),  INT8_C(    68),  INT8_C(    40),
         INT8_C(   103),  INT8_C(    92), -INT8_C(   104), -INT8_C(   105),
         INT8_C(     5), -INT8_C(    10),  INT8_C(   101),  INT8_C(    15),
        -INT8_C(   100),  INT8_C(   101), -INT8_C(    12), -INT8_C(    31) },
      {  INT8_C(    72), -INT8_C(    42), -INT8_C(   114), -INT8_C(   127),
         INT8_C(     2), -INT8_C(    91), -INT8_C(     1),  INT8_C(    31) },
      { -INT8_C(    48),  INT8_C(    40), -INT8_C(   114), -INT8_C(   127),
         INT8_C(     2), -INT8_C(    91), -INT8_C(     1),  INT8_C(    31) },
      { -INT8_C(    48), -INT8_C(    42), -INT8_C(   114),  INT8_C(     5),
         INT8_C(     2), -INT8_C(    91), -INT8_C(     1),  INT8_C(    31) },
      { -INT8_C(    48), -INT8_C(    42), -INT8_C(   114), -INT8_C(   127),
         INT8_C(     2), -INT8_C(    91), -INT8_C(   100),  INT8_C(    31) },
      { -INT8_C(    48), -INT8_C(    42), -INT8_C(   114), -INT8_C(   127),
         INT8_C(     2), -INT8_C(    91), -INT8_C(     1), -INT8_C(    31) } },
    { { -INT8_C(   117), -INT8_C(    59), -INT8_C(   110), -INT8_C(   122),
         INT8_C(    97), -INT8_C(    17),  INT8_C(    15),  INT8_C(   106) },
      {  INT8_C(    81), -INT8_C(    59),  INT8_C(   121), -INT8_C(    42),
         INT8_C(    97), -INT8_C(    50), -INT8_C(   102), -INT8_C(    32),
         INT8_C(    49), -INT8_C(   103), -INT8_C(    84),  INT8_C(     2),
        -INT8_C(    33),        INT8_MIN, -INT8_C(    60),  INT8_C(    81) },
      {  INT8_C(    81), -INT8_C(    59), -INT8_C(   110), -INT8_C(   122),
         INT8_C(    97), -INT8_C(    17),  INT8_C(    15),  INT8_C(   106) },
      { -INT8_C(   117), -INT8_C(    42), -INT8_C(   110), -INT8_C(   122),
         INT8_C(    97), -INT8_C(    17),  INT8_C(    15),  INT8_C(   106) },
      { -INT8_C(   117), -INT8_C(    59), -INT8_C(   110),  INT8_C(    49),
         INT8_C(    97), -INT8_C(    17),  INT8_C(    15),  INT8_C(   106) },
      { -INT8_C(   117), -INT8_C(    59), -INT8_C(   110), -INT8_C(   122),
         INT8_C(    97), -INT8_C(    17), -INT8_C(    33),  INT8_C(   106) },
      { -INT8_C(   117), -INT8_C(    59), -INT8_C(   110), -INT8_C(   122),
         INT8_C(    97), -INT8_C(    17),  INT8_C(    15),  INT8_C(    81) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);

    simde_int8x8_t r0_0 = simde_vcopy_laneq_s8(a, 0, b, 0);
    simde_int8x8_t r1_3 = simde_vcopy_laneq_s8(a, 1, b, 3);
    simde_int8x8_t r3_8 = simde_vcopy_laneq_s8(a, 3, b, 8);
    simde_int8x8_t r6_12 = simde_vcopy_laneq_s8(a, 6, b, 12);
    simde_int8x8_t r7_15 = simde_vcopy_laneq_s8(a, 7, b, 15);

    simde_test_arm_neon_assert_equal_i8x8(r0_0, simde_vld1_s8(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_i8x8(r1_3, simde_vld1_s8(test_vec[i].r1_3));
    simde_test_arm_neon_assert_equal_i8x8(r3_8, simde_vld1_s8(test_vec[i].r3_8));
    simde_test_arm_neon_assert_equal_i8x8(r6_12, simde_vld1_s8(test_vec[i].r6_12));
    simde_test_arm_neon_assert_equal_i8x8(r7_15, simde_vld1_s8(test_vec[i].r7_15));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x8_t r0_0 = simde_vcopy_laneq_s8(a, 0, b, 0);
    simde_int8x8_t r1_3 = simde_vcopy_laneq_s8(a, 1, b, 3);
    simde_int8x8_t r3_8 = simde_vcopy_laneq_s8(a, 3, b, 8);
    simde_int8x8_t r6_12 = simde_vcopy_laneq_s8(a, 6, b, 12);
    simde_int8x8_t r7_15 = simde_vcopy_laneq_s8(a, 7, b, 15);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r1_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r3_8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r6_12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r7_15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[8];
    int16_t r0_0[4];
    int16_t r1_3[4];
    int16_t r2_5[4];
    int16_t r3_7[4];
  } test_vec[] = {
    { {  INT16_C(   11568),  INT16_C(    1189), -INT16_C(   31827), -INT16_C(   15215) },
      { -INT16_C(    7146), -INT16_C(    9374), -INT16_C(   14179),  INT16_C(   15036),
        -INT16_C(   20968),  INT16_C(   10399), -INT16_C(   25296), -INT16_C(   27806) },
      { -INT16_C(    7146),  INT16_C(    1189), -INT16_C(   31827), -INT16_C(   15215) },
      {  INT16_C(   11568),  INT16_C(   15036), -INT16_C(   31827), -INT16_C(   15215) },
      {  INT16_C(   11568),  INT16_C(    1189),  INT16_C(   10399), -INT16_C(   15215) },
      {  INT16_C(   11568),  INT16_C(    1189), -INT16_C(   31827), -INT16_C(   27806) } },
    { { -INT16_C(   29466),  INT16_C(   12540), -INT16_C(   32471),  INT16_C(   25566) },
      {  INT16_C(    3723),  INT16_C(   12785), -INT16_C(   31701), -INT16_C(   20907),
        -INT16_C(   15423),  INT16_C(    7301),  INT16_C(   23738),  INT16_C(   27813) },
      {  INT16_C(    3723),  INT16_C(   12540), -INT16_C(   32471),  INT16_C(   25566) },
      { -INT16_C(   29466), -INT16_C(   20907), -INT16_C(   32471),  INT16_C(   25566) },
      { -INT16_C(   29466),  INT16_C(   12540),  INT16_C(    7301),  INT16_C(   25566) },
      { -INT16_C(   29466),  INT16_C(   12540), -INT16_C(   32471),  INT16_C(   27813) } },
    { { -INT16_C(   26183), -INT16_C(    5597), -INT16_C(    2230), -INT16_C(   10015) },
      {  INT16_C(   26576), -INT16_C(    8824), -INT16_C(   28847),  INT16_C(    4173),
         INT16_C(   25260),  INT16_C(   12404),  INT16_C(   31395),  INT16_C(   21002) },
      {  INT16_C(   26576), -INT16_C(    5597), -INT16_C(    2230), -INT16_C(   10015) },
      { -INT16_C(   26183),  INT16_C(    4173), -INT16_C(    2230), -INT16_C(   10015) },
      { -INT16_C(   26183), -INT16_C(    5597),  INT16_C(   12404), -INT16_C(   10015) },
      { -INT16_C(   26183), -INT16_C(    5597), -INT16_C(    2230),  INT16_C(   21002) } },
    { {  INT16_C(    6672),  INT16_C(   15408), -INT16_C(    2985), -INT16_C(   17248) },
      {  INT16_C(    7532), -INT16_C(    4273),  INT16_C(   31970), -INT16_C(    3753),
         INT16_C(   17390),  INT16_C(   14312),  INT16_C(    5983), -INT16_C(   19903) },
      {  INT16_C(    7532),  INT16_C(   15408), -INT16_C(    2985), -INT16_C(   17248) },
      {  INT16_C(    6672), -INT16_C(    3753), -INT16_C(    2985), -INT16_C(   17248) },
      {  INT16_C(    6672),  INT16_C(   15408),  INT16_C(   14312), -INT16_C(   17248) },
      {  INT16_C(    6672),  INT16_C(   15408), -INT16_C(    2985), -INT16_C(   19903) } },
    { {  INT16_C(   10634),  INT16_C(   13785), -INT16_C(   21124),  INT16_C(   18819) },
      { -INT16_C(   23606), -INT16_C(   23575),  INT16_C(   23736), -INT16_C(   14515),
        -INT16_C(   28372), -INT16_C(   21675), -INT16_C(   29450), -INT16_C(    8419) },
      { -INT16_C(   23606),  INT16_C(   13785), -INT16_C(   21124),  INT16_C(   18819) },
      {  INT16_C(   10634), -INT16_C(   14515), -INT16_C(   21124),  INT16_C(   18819) },
      {  INT16_C(   10634),  INT16_C(   13785), -INT16_C(   21675),  INT16_C(   18819) },
      {  INT16_C(   10634),  INT16_C(   13785), -INT16_C(   21124), -INT16_C(    8419) } },
    { { -INT16_C(    2153),  INT16_C(   11458), -INT16_C(    5624), -INT16_C(   18131) },
      { -INT16_C(   25804), -INT16_C(   24558), -INT16_C(   10190),  INT16_C(   16869),
         INT16_C(   21833),  INT16_C(   10951), -INT16_C(    4960), -INT16_C(   24993) },
      { -INT16_C(   25804),  INT16_C(   11458), -INT16_C(    5624), -INT16_C(   18131) },
      { -INT16_C(    2153),  INT16_C(   16869), -INT16_C(    5624), -INT16_C(   18131) },
      { -INT16_C(    2153),  INT16_C(   11458),  INT16_C(   10951), -INT16_C(   18131) },
      { -INT16_C(    2153),  INT16_C(   11458), -INT16_C(    5624), -INT16_C(   24993) } },
    { { -INT16_C(   12465),  INT16_C(   11890),  INT16_C(   12124),  INT16_C(   10524) },
      {  INT16_C(   29032), -INT16_C(      41),  INT16_C(   12620),  INT16_C(   26779),
         INT16_C(   10646),  INT16_C(   12590), -INT16_C(   29637), -INT16_C(   18553) },
      {  INT16_C(   29032),  INT16_C(   11890),  INT16_C(   12124),  INT16_C(   10524) },
      { -INT16_C(   12465),  INT16_C(   26779),  INT16_C(   12124),  INT16_C(   10524) },
      { -INT16_C(   12465),  INT16_C(   11890),  INT16_C(   12590),  INT16_C(   10524) },
      { -INT16_C(   12465),  INT16_C(   11890),  INT16_C(   12124), -INT16_C(   18553) } },
    { { -INT16_C(    6289),  INT16_C(   21955), -INT16_C(   10116),  INT16_C(    9614) },
      {  INT16_C(   25780), -INT16_C(    2709), -INT16_C(   29858),  INT16_C(   17932),
         INT16_C(   27686), -INT16_C(   30566), -INT16_C(    1086), -INT16_C(   10968) },
      {  INT16_C(   25780),  INT16_C(   21955), -INT16_C(   10116),  INT16_C(    9614) },
      { -INT16_C(    6289),  INT16_C(   17932), -INT16_C(   10116),  INT16_C(    9614) },
      { -INT16_C(    6289),  INT16_C(   21955), -INT16_C(   30566),  INT16_C(    9614) },
      { -INT16_C(    6289),  INT16_C(   21955), -INT16_C(   10116), -INT16_C(   10968) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x4_t r0_0 = simde_vcopy_laneq_s16(a, 0, b, 0);
    simde_int16x4_t r1_3 = simde_vcopy_laneq_s16(a, 1, b, 3);
    simde_int16x4_t r2_5 = simde_vcopy_laneq_s16(a, 2, b, 5);
    simde_int16x4_t r3_7 = simde_vcopy_laneq_s16(a, 3, b, 7);

    simde_test_arm_neon_assert_equal_i16x4(r0_0, simde_vld1_s16(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_i16x4(r1_3, simde_vld1_s16(test_vec[i].r1_3));
    simde_test_arm_neon_assert_equal_i16x4(r2_5, simde_vld1_s16(test_vec[i].r2_5));
    simde_test_arm_neon_assert_equal_i16x4(r3_7, simde_vld1_s16(test_vec[i].r3_7));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t r0_0 = simde_vcopy_laneq_s16(a, 0, b, 0);
    simde_int16x4_t r1_3 = simde_vcopy_laneq_s16(a, 1, b, 3);
    simde_int16x4_t r2_5 = simde_vcopy_laneq_s16(a, 2, b, 5);
    simde_int16x4_t r3_7 = simde_vcopy_laneq_s16(a, 3, b, 7);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r1_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r2_5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r3_7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[4];
    int32_t r0_0[2];
    int32_t r0_2[2];
    int32_t r1_1[2];
    int32_t r1_3[2];
  } test_vec[] = {
    { {  INT32_C(  1084595629), -INT32_C(  1950361537) },
      {  INT32_C(  1443362392),  INT32_C(  1640750526),  INT32_C(   895649900),  INT32_C(  1359771437) },
      {  INT32_C(  1443362392), -INT32_C(  1950361537) },
      {  INT32_C(   895649900), -INT32_C(  1950361537) },
      {  INT32_C(  1084595629),  INT32_C(  1640750526) },
      {  INT32_C(  1084595629),  INT32_C(  1359771437) } },
    { { -INT32_C(  1748970842),  INT32_C(  2053463719) },
      {  INT32_C(    19379512), -INT32_C(  1861133592), -INT32_C(   529529470),  INT32_C(   388681637) },
      {  INT32_C(    19379512),  INT32_C(  2053463719) },
      { -INT32_C(   529529470),  INT32_C(  2053463719) },
      { -INT32_C(  1748970842), -INT32_C(  1861133592) },
      { -INT32_C(  1748970842),  INT32_C(   388681637) } },
    { {  INT32_C(  1476418479), -INT32_C(  1924452234) },
      {  INT32_C(  2070023191), -INT32_C(    53868389), -INT32_C(   266392323), -INT32_C(   474980198) },
      {  INT32_C(  2070023191), -INT32_C(  1924452234) },
      { -INT32_C(   266392323), -INT32_C(  1924452234) },
      {  INT32_C(  1476418479), -INT32_C(    53868389) },
      {  INT32_C(  1476418479), -INT32_C(   474980198) } },
    { {  INT32_C(   629708170), -INT32_C(  1981353517) },
      {  INT32_C(   376672318), -INT32_C(  1618425121),  INT32_C(    34344684), -INT32_C(  2024844639) },
      {  INT32_C(   376672318), -INT32_C(  1981353517) },
      {  INT32_C(    34344684), -INT32_C(  1981353517) },
      {  INT32_C(   629708170), -INT32_C(  1618425121) },
      {  INT32_C(   629708170), -INT32_C(  2024844639) } },
    { { -INT32_C(  1168139645), -INT32_C(  1639571907) },
      {  INT32_C(  1818508399),  INT32_C(  1912849895), -INT32_C(    81367675), -INT32_C(   933616398) },
      {  INT32_C(  1818508399), -INT32_C(  1639571907) },
      { -INT32_C(    81367675), -INT32_C(  1639571907) },
      { -INT32_C(  1168139645),  INT32_C(  1912849895) },
      { -INT32_C(  1168139645), -INT32_C(   933616398) } },
    { {  INT32_C(  1391980757),  INT32_C(    34941896) },
      { -INT32_C(   428457330),  INT32_C(   205780721), -INT32_C(   331850439),  INT32_C(  1610682246) },
      { -INT32_C(   428457330),  INT32_C(    34941896) },
      { -INT32_C(   331850439),  INT32_C(    34941896) },
      {  INT32_C(  1391980757),  INT32_C(   205780721) },
      {  INT32_C(  1391980757),  INT32_C(  1610682246) } },
    { { -INT32_C(   332770313), -INT32_C(    40080371) },
      { -INT32_C(  1900488554),  INT32_C(   497830222), -INT32_C(   522537965), -INT32_C(  1036126695) },
      { -INT32_C(  1900488554), -INT32_C(    40080371) },
      { -INT32_C(   522537965), -INT32_C(    40080371) },
      { -INT32_C(   332770313),  INT32_C(   497830222) },
      { -INT32_C(   332770313), -INT32_C(  1036126695) } },
    { { -INT32_C(  1146060113),  INT32_C(  1919349998) },
      {  INT32_C(  1840725219), -INT32_C(  1422378091), -INT32_C(  1992513290), -INT32_C(    21119508) },
      {  INT32_C(  1840725219),  INT32_C(  1919349998) },
      { -INT32_C(  1992513290),  INT32_C(  1919349998) },
      { -INT32_C(  1146060113), -INT32_C(  1422378091) },
      { -INT32_C(  1146060113), -INT32_C(    21119508) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x2_t r0_0 = simde_vcopy_laneq_s32(a, 0, b, 0);
    simde_int32x2_t r0_2 = simde_vcopy_laneq_s32(a, 0, b, 2);
    simde_int32x2_t r1_1 = simde_vcopy_laneq_s32(a, 1, b, 1);
    simde_int32x2_t r1_3 = simde_vcopy_laneq_s32(a, 1, b, 3);

    simde_test_arm_neon_assert_equal_i32x2(r0_0, simde_vld1_s32(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_i32x2(r0_2, simde_vld1_s32(test_vec[i].r0_2));
    simde_test_arm_neon_assert_equal_i32x2(r1_1, simde_vld1_s32(test_vec[i].r1_1));
    simde_test_arm_neon_assert_equal_i32x2(r1_3, simde_vld1_s32(test_vec[i].r1_3));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t r0_0 = simde_vcopy_laneq_s32(a, 0, b, 0);
    simde_int32x2_t r0_2 = simde_vcopy_laneq_s32(a, 0, b, 2);
    simde_int32x2_t r1_1 = simde_vcopy_laneq_s32(a, 1, b, 1);
    simde_int32x2_t r1_3 = simde_vcopy_laneq_s32(a, 1, b, 3);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r0_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r1_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r1_3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[2];
    int64_t r0_0[1];
    int64_t r0_1[1];
  } test_vec[] = {
    { { -INT64_C( 5524975992096568302) },
      {  INT64_C( 5928209276499224928),  INT64_C( 3570587797784554636) },
      {  INT64_C( 5928209276499224928) },
      {  INT64_C( 3570587797784554636) } },
    { { -INT64_C( 5698335035773134399) },
      {  INT64_C( 4781888000487025832),  INT64_C( 1507882669637173008) },
      {  INT64_C( 4781888000487025832) },
      {  INT64_C( 1507882669637173008) } },
    { { -INT64_C( 2144038387548032181) },
      { -INT64_C( 8135906999096004888), -INT64_C( 3560370611244798922) },
      { -INT64_C( 8135906999096004888) },
      { -INT64_C( 3560370611244798922) } },
    { { -INT64_C(  117785309047793137) },
      { -INT64_C( 1882610051046624115),  INT64_C( 7186331988604967381) },
      { -INT64_C( 1882610051046624115) },
      {  INT64_C( 7186331988604967381) } },
    { {  INT64_C( 4066640187066630269) },
      { -INT64_C( 4494233011176271376), -INT64_C( 3865763807733887293) },
      { -INT64_C( 4494233011176271376) },
      { -INT64_C( 3865763807733887293) } },
    { { -INT64_C( 6040197928986056700) },
      {  INT64_C( 1006231244329940143),  INT64_C( 2476886300863804510) },
      {  INT64_C( 1006231244329940143) },
      {  INT64_C( 2476886300863804510) } },
    { { -INT64_C( 7084452747101498475) },
      { -INT64_C( 7001274548870075067),  INT64_C( 4002777076668709871) },
      { -INT64_C( 7001274548870075067) },
      {  INT64_C( 4002777076668709871) } },
    { {  INT64_C(  163938470204546022) },
      { -INT64_C( 5694319174922918088), -INT64_C( 1823313391809624358) },
      { -INT64_C( 5694319174922918088) },
      { -INT64_C( 1823313391809624358) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);

    simde_int64x1_t r0_0 = simde_vcopy_laneq_s64(a, 0, b, 0);
    simde_int64x1_t r0_1 = simde_vcopy_laneq_s64(a, 0, b, 1);

    simde_test_arm_neon_assert_equal_i64x1(r0_0, simde_vld1_s64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_i64x1(r0_1, simde_vld1_s64(test_vec[i].r0_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x1_t r0_0 = simde_vcopy_laneq_s64(a, 0, b, 0);
    simde_int64x1_t r0_1 = simde_vcopy_laneq_s64(a, 0, b, 1);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r0_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[16];
    uint8_t r0_0[8];
    uint8_t r1_3[8];
    uint8_t r3_8[8];
    uint8_t r6_12[8];
    uint8_t r7_15[8];
  } test_vec[] = {
    { {  UINT8_C(   99),  UINT8_C(   40),  UINT8_C(   75),  UINT8_C(   35),
         UINT8_C(   30),  UINT8_C(  240),  UINT8_C(   87),  UINT8_C(  222) },
      {  UINT8_C(   52),  UINT8_C(    1),  UINT8_C(  224),  UINT8_C(  221),
         UINT8_C(  253),  UINT8_C(  198),  UINT8_C(  240),  UINT8_C(   81),
         UINT8_C(  184),  UINT8_C(  118),  UINT8_C(    1),  UINT8_C(  200),
         UINT8_C(   52),  UINT8_C(  165),  UINT8_C(  148),  UINT8_C(   99) },
      {  UINT8_C(   52),  UINT8_C(   40),  UINT8_C(   75),  UINT8_C(   35),
         UINT8_C(   30),  UINT8_C(  240),  UINT8_C(   87),  UINT8_C(  222) },
      {  UINT8_C(   99),  UINT8_C(  221),  UINT8_C(   75),  UINT8_C(   35),
         UINT8_C(   30),  UINT8_C(  240),  UINT8_C(   87),  UINT8_C(  222) },
      {  UINT8_C(   99),  UINT8_C(   40),  UINT8_C(   75),  UINT8_C(  184),
         UINT8_C(   30),  UINT8_C(  240),  UINT8_C(   87),  UINT8_C(  222) },
      {  UINT8_C(   99),  UINT8_C(   40),  UINT8_C(   75),  UINT8_C(   35),
         UINT8_C(   30),  UINT8_C(  240),  UINT8_C(   52),  UINT8_C(  222) },
      {  UINT8_C(   99),  UINT8_C(   40),  UINT8_C(   75),  UINT8_C(   35),
         UINT8_C(   30),  UINT8_C(  240),  UINT8_C(   87),  UINT8_C(   99) } },
    { {  UINT8_C(  212),  UINT8_C(   86),  UINT8_C(  230),  UINT8_C(  248),
         UINT8_C(   64),  UINT8_C(  245),  UINT8_C(  189),  UINT8_C(   69) },
      {  UINT8_C(  189),  UINT8_C(  213),  UINT8_C(   28),  UINT8_C(  243),
         UINT8_C(  192),  UINT8_C(   83),  UINT8_C(   82),  UINT8_C(   86),
         UINT8_C(  253),  UINT8_C(  168),  UINT8_C(  184),  UINT8_C(   57),
         UINT8_C(  162),  UINT8_C(  132),  UINT8_C(  109),  UINT8_C(   69) },
      {  UINT8_C(  189),  UINT8_C(   86),  UINT8_C(  230),  UINT8_C(  248),
         UINT8_C(   64),  UINT8_C(  245),  UINT8_C(  189),  UINT8_C(   69) },
      {  UINT8_C(  212),  UINT8_C(  243),  UINT8_C(  230),  UINT8_C(  248),
         UINT8_C(   64),  UINT8_C(  245),  UINT8_C(  189),  UINT8_C(   69) },
      {  UINT8_C(  212),  UINT8_C(   86),  UINT8_C(  230),  UINT8_C(  253),
         UINT8_C(   64),  UINT8_C(  245),  UINT8_C(  189),  UINT8_C(   69) },
      {  UINT8_C(  212),  UINT8_C(   86),  UINT8_C(  230),  UINT8_C(  248),
         UINT8_C(   64),  UINT8_C(  245),  UINT8_C(  162),  UINT8_C(   69) },
      {  UINT8_C(  212),  UINT8_C(   86),  UINT8_C(  230),  UINT8_C(  248),
         UINT8_C(   64),  UINT8_C(  245),  UINT8_C(  189),  UINT8_C(   69) } },
    { {  UINT8_C(   29),  UINT8_C(  103),  UINT8_C(  152),  UINT8_C(  196),
         UINT8_C(   89),  UINT8_C(   91),  UINT8_C(  206),  UINT8_C(  196) },
      {  UINT8_C(   66),  UINT8_C(  242),  UINT8_C(   97),  UINT8_C(   23),
         UINT8_C(  124),  UINT8_C(   30),  UINT8_C(  240),  UINT8_C(   31),
         UINT8_C(  105),  UINT8_C(  243),  UINT8_C(   21),  UINT8_C(  146),
         UINT8_C(    3),  UINT8_C(  218),  UINT8_C(   80),  UINT8_C(  224) },
      {  UINT8_C(   66),  UINT8_C(  103),  UINT8_C(  152),  UINT8_C(  196),
         UINT8_C(   89),  UINT8_C(   91),  UINT8_C(  206),  UINT8_C(  196) },
      {  UINT8_C(   29),  UINT8_C(   23),  UINT8_C(  152),  UINT8_C(  196),
         UINT8_C(   89),  UINT8_C(   91),  UINT8_C(  206),  UINT8_C(  196) },
      {  UINT8_C(   29),  UINT8_C(  103),  UINT8_C(  152),  UINT8_C(  105),
         UINT8_C(   89),  UINT8_C(   91),  UINT8_C(  206),  UINT8_C(  196) },
      {  UINT8_C(   29),  UINT8_C(  103),  UINT8_C(  152),  UINT8_C(  196),
         UINT8_C(   89),  UINT8_C(   91),  UINT8_C(    3),  UINT8_C(  196) },
      {  UINT8_C(   29),  UINT8_C(  103),  UINT8_C(  152),  UINT8_C(  196),
         UINT8_C(   89),  UINT8_C(   91),  UINT8_C(  206),  UINT8_C(  224) } },
    { {  UINT8_C(   21),  UINT8_C(   26),  UINT8_C(  161),  UINT8_C(   44),
         UINT8_C(  217),  UINT8_C(  170),  UINT8_C(    7),  UINT8_C(  181) },
      {  UINT8_C(   69),  UINT8_C(  115),  UINT8_C(   53),  UINT8_C(  237),
         UINT8_C(  116),  UINT8_C(  223),  UINT8_C(  252),  UINT8_C(  212),
         UINT8_C(  149),  UINT8_C(   72),  UINT8_C(  106),  UINT8_C(   27),
         UINT8_C(  249),  UINT8_C(    7),  UINT8_C(   66),  UINT8_C(  133) },
      {  UINT8_C(   69),  UINT8_C(   26),  UINT8_C(  161),  UINT8_C(   44),
         UINT8_C(  217),  UINT8_C(  170),  UINT8_C(    7),  UINT8_C(  181) },
      {  UINT8_C(   21),  UINT8_C(  237),  UINT8_C(  161),  UINT8_C(   44),
         UINT8_C(  217),  UINT8_C(  170),  UINT8_C(    7),  UINT8_C(  181) },
      {  UINT8_C(   21),  UINT8_C(   26),  UINT8_C(  161),  UINT8_C(  149),
         UINT8_C(  217),  UINT8_C(  170),  UINT8_C(    7),  UINT8_C(  181) },
      {  UINT8_C(   21),  UINT8_C(   26),  UINT8_C(  161),  UINT8_C(   44),
         UINT8_C(  217),  UINT8_C(  170),  UINT8_C(  249),  UINT8_C(  181) },
      {  UINT8_C(   21),  UINT8_C(   26),  UINT8_C(  161),  UINT8_C(   44),
         UINT8_C(  217),  UINT8_C(  170),  UINT8_C(    7),  UINT8_C(  133) } },
    { {  UINT8_C(   99),  UINT8_C(  126),  UINT8_C(    4),      UINT8_MAX,
         UINT8_C(  179),  UINT8_C(   35),  UINT8_C(  241),  UINT8_C(   40) },
      {  UINT8_C(    5),  UINT8_C(  120),  UINT8_C(  120),  UINT8_C(  177),
         UINT8_C(  245),  UINT8_C(   56),  UINT8_C(  251),  UINT8_C(  121),
         UINT8_C(  185),  UINT8_C(   18),  UINT8_C(  149),  UINT8_C(   67),
         UINT8_C(  176),  UINT8_C(    7),  UINT8_C(  139),  UINT8_C(  203) },
      {  UINT8_C(    5),  UINT8_C(  126),  UINT8_C(    4),      UINT8_MAX,
         UINT8_C(  179),  UINT8_C(   35),  UINT8_C(  241),  UINT8_C(   40) },
      {  UINT8_C(   99),  UINT8_C(  177),  UINT8_C(    4),      UINT8_MAX,
         UINT8_C(  179),  UINT8_C(   35),  UINT8_C(  241),  UINT8_C(   40) },
      {  UINT8_C(   99),  UINT8_C(  126),  UINT8_C(    4),  UINT8_C(  185),
         UINT8_C(  179),  UINT8_C(   35),  UINT8_C(  241),  UINT8_C(   40) },
      {  UINT8_C(   99),  UINT8_C(  126),  UINT8_C(    4),      UINT8_MAX,
         UINT8_C(  179),  UINT8_C(   35),  UINT8_C(  176),  UINT8_C(   40) },
      {  UINT8_C(   99),  UINT8_C(  126),  UINT8_C(    4),      UINT8_MAX,
         UINT8_C(  179),  UINT8_C(   35),  UINT8_C(  241),  UINT8_C(  203) } },
    { {  UINT8_C(  207),  UINT8_C(   15),  UINT8_C(  186),  UINT8_C(   59),
         UINT8_C(  190),  UINT8_C(  250),  UINT8_C(  169),  UINT8_C(  170) },
      {  UINT8_C(  135),  UINT8_C(   89),  UINT8_C(   92),  UINT8_C(   84),
         UINT8_C(   98),  UINT8_C(   83),  UINT8_C(   54),  UINT8_C(   70),
         UINT8_C(   74),  UINT8_C(  190),  UINT8_C(   21),  UINT8_C(  204),
         UINT8_C(  114),  UINT8_C(  121),  UINT8_C(  146),  UINT8_C(   53) },
      {  UINT8_C(  135),  UINT8_C(   15),  UINT8_C(  186),  UINT8_C(   59),
         UINT8_C(  190),  UINT8_C(  250),  UINT8_C(  169),  UINT8_C(  170) },
      {  UINT8_C(  207),  UINT8_C(   84),  UINT8_C(  186),  UINT8_C(   59),
         UINT8_C(  190),  UINT8_C(  250),  UINT8_C(  169),  UINT8_C(  170) },
      {  UINT8_C(  207),  UINT8_C(   15),  UINT8_C(  186),  UINT8_C(   74),
         UINT8_C(  190),  UINT8_C(  250),  UINT8_C(  169),  UINT8_C(  170) },
      {  UINT8_C(  207),  UINT8_C(   15),  UINT8_C(  186),  UINT8_C(   59),
         UINT8_C(  190),  UINT8_C(  250),  UINT8_C(  114),  UINT8_C(  170) },
      {  UINT8_C(  207),  UINT8_C(   15),  UINT8_C(  186),  UINT8_C(   59),
         UINT8_C(  190),  UINT8_C(  250),  UINT8_C(  169),  UINT8_C(   53) } },
    { {  UINT8_C(  212),  UINT8_C(  125),  UINT8_C(  231),  UINT8_C(  195),
         UINT8_C(  124),  UINT8_C(  208),  UINT8_C(  167),  UINT8_C(  186) },
      {  UINT8_C(    9),  UINT8_C(  138),  UINT8_C(  171),  UINT8_C(   97),
         UINT8_C(  120),  UINT8_C(   72),  UINT8_C(  155),  UINT8_C(   29),
         UINT8_C(    5),  UINT8_C(   14),  UINT8_C(   10),  UINT8_C(  220),
         UINT8_C(  253),  UINT8_C(  194),  UINT8_C(  240),  UINT8_C(  218) },
      {  UINT8_C(    9),  UINT8_C(  125),  UINT8_C(  231),  UINT8_C(  195),
         UINT8_C(  124),  UINT8_C(  208),  UINT8_C(  167),  UINT8_C(  186) },
      {  UINT8_C(  212),  UINT8_C(   97),  UINT8_C(  231),  UINT8_C(  195),
         UINT8_C(  124),  UINT8_C(  208),  UINT8_C(  167),  UINT8_C(  186) },
      {  UINT8_C(  212),  UINT8_C(  125),  UINT8_C(  231),  UINT8_C(    5),
         UINT8_C(  124),  UINT8_C(  208),  UINT8_C(  167),  UINT8_C(  186) },
      {  UINT8_C(  212),  UINT8_C(  125),  UINT8_C(  231),  UINT8_C(  195),
         UINT8_C(  124),  UINT8_C(  208),  UINT8_C(  253),  UINT8_C(  186) },
      {  UINT8_C(  212),  UINT8_C(  125),  UINT8_C(  231),  UINT8_C(  195),
         UINT8_C(  124),  UINT8_C(  208),  UINT8_C(  167),  UINT8_C(  218) } },
    { {  UINT8_C(   43),  UINT8_C(  179),  UINT8_C(    5),  UINT8_C(   62),
         UINT8_C(  203),  UINT8_C(   46),  UINT8_C(  232),  UINT8_C(  247) },
      {  UINT8_C(  190),  UINT8_C(  199),  UINT8_C(   65),  UINT8_C(  133),
         UINT8_C(  222),  UINT8_C(  218),  UINT8_C(  184),  UINT8_C(   55),
         UINT8_C(  217),  UINT8_C(   12),  UINT8_C(  216),  UINT8_C(   57),
         UINT8_C(  204),  UINT8_C(  112),  UINT8_C(   59),  UINT8_C(  253) },
      {  UINT8_C(  190),  UINT8_C(  179),  UINT8_C(    5),  UINT8_C(   62),
         UINT8_C(  203),  UINT8_C(   46),  UINT8_C(  232),  UINT8_C(  247) },
      {  UINT8_C(   43),  UINT8_C(  133),  UINT8_C(    5),  UINT8_C(   62),
         UINT8_C(  203),  UINT8_C(   46),  UINT8_C(  232),  UINT8_C(  247) },
      {  UINT8_C(   43),  UINT8_C(  179),  UINT8_C(    5),  UINT8_C(  217),
         UINT8_C(  203),  UINT8_C(   46),  UINT8_C(  232),  UINT8_C(  247) },
      {  UINT8_C(   43),  UINT8_C(  179),  UINT8_C(    5),  UINT8_C(   62),
         UINT8_C(  203),  UINT8_C(   46),  UINT8_C(  204),  UINT8_C(  247) },
      {  UINT8_C(   43),  UINT8_C(  179),  UINT8_C(    5),  UINT8_C(   62),
         UINT8_C(  203),  UINT8_C(   46),  UINT8_C(  232),  UINT8_C(  253) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);

    simde_uint8x8_t r0_0 = simde_vcopy_laneq_u8(a, 0, b, 0);
    simde_uint8x8_t r1_3 = simde_vcopy_laneq_u8(a, 1, b, 3);
    simde_uint8x8_t r3_8 = simde_vcopy_laneq_u8(a, 3, b, 8);
    simde_uint8x8_t r6_12 = simde_vcopy_laneq_u8(a, 6, b, 12);
    simde_uint8x8_t r7_15 = simde_vcopy_laneq_u8(a, 7, b, 15);

    simde_test_arm_neon_assert_equal_u8x8(r0_0, simde_vld1_u8(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_u8x8(r1_3, simde_vld1_u8(test_vec[i].r1_3));
    simde_test_arm_neon_assert_equal_u8x8(r3_8, simde_vld1_u8(test_vec[i].r3_8));
    simde_test_arm_neon_assert_equal_u8x8(r6_12, simde_vld1_u8(test_vec[i].r6_12));
    simde_test_arm_neon_assert_equal_u8x8(r7_15, simde_vld1_u8(test_vec[i].r7_15));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();

    simde_uint8x8_t r0_0 = simde_vcopy_laneq_u8(a, 0, b, 0);
    simde_uint8x8_t r1_3 = simde_vcopy_laneq_u8(a, 1, b, 3);
    simde_uint8x8_t r3_8 = simde_vcopy_laneq_u8(a, 3, b, 8);
    simde_uint8x8_t r6_12 = simde_vcopy_laneq_u8(a, 6, b, 12);
    simde_uint8x8_t r7_15 = simde_vcopy_laneq_u8(a, 7, b, 15);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r1_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r3_8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r6_12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r7_15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[8];
    uint16_t r0_0[4];
    uint16_t r1_3[4];
    uint16_t r2_5[4];
    uint16_t r3_7[4];
  } test_vec[] = {
    { {  UINT16_C(   14090),  UINT16_C(   43348),  UINT16_C(   44694),  UINT16_C(   30737) },
      {  UINT16_C(   38617),  UINT16_C(   33902),  UINT16_C(      90),  UINT16_C(   41210),
         UINT16_C(   36570),  UINT16_C(   20021),  UINT16_C(    3767),  UINT16_C(   62186) },
      {  UINT16_C(   38617),  UINT16_C(   43348),  UINT16_C(   44694),  UINT16_C(   30737) },
      {  UINT16_C(   14090),  UINT16_C(   41210),  UINT16_C(   44694),  UINT16_C(   30737) },
      {  UINT16_C(   14090),  UINT16_C(   43348),  UINT16_C(   20021),  UINT16_C(   30737) },
      {  UINT16_C(   14090),  UINT16_C(   43348),  UINT16_C(   44694),  UINT16_C(   62186) } },
    { {  UINT16_C(   61109),  UINT16_C(   30682),  UINT16_C(   62985),  UINT16_C(   21741) },
      {  UINT16_C(   19675),  UINT16_C(   47463),  UINT16_C(   48866),  UINT16_C(   48845),
         UINT16_C(   50845),  UINT16_C(   43216),  UINT16_C(    9981),  UINT16_C(   42973) },
      {  UINT16_C(   19675),  UINT16_C(   30682),  UINT16_C(   62985),  UINT16_C(   21741) },
      {  UINT16_C(   61109),  UINT16_C(   48845),  UINT16_C(   62985),  UINT16_C(   21741) },
      {  UINT16_C(   61109),  UINT16_C(   30682),  UINT16_C(   43216),  UINT16_C(   21741) },
      {  UINT16_C(   61109),  UINT16_C(   30682),  UINT16_C(   62985),  UINT16_C(   42973) } },
    { {  UINT16_C(   31349),  UINT16_C(   64794),  UINT16_C(   25390),  UINT16_C(   50931) },
      {  UINT16_C(   20875),  UINT16_C(   26295),  UINT16_C(   47031),  UINT16_C(   37393),
         UINT16_C(    8989),  UINT16_C(    1142),  UINT16_C(     891),  UINT16_C(   41568) },
      {  UINT16_C(   20875),  UINT16_C(   64794),  UINT16_C(   25390),  UINT16_C(   50931) },
      {  UINT16_C(   31349),  UINT16_C(   37393),  UINT16_C(   25390),  UINT16_C(   50931) },
      {  UINT16_C(   31349),  UINT16_C(   64794),  UINT16_C(    1142),  UINT16_C(   50931) },
      {  UINT16_C(   31349),  UINT16_C(   64794),  UINT16_C(   25390),  UINT16_C(   41568) } },
    { {  UINT16_C(   27978),  UINT16_C(   43843),  UINT16_C(   22177),  UINT16_C(   31195) },
      {  UINT16_C(   13000),  UINT16_C(   19847),  UINT16_C(   29376),  UINT16_C(   26702),
         UINT16_C(   12549),  UINT16_C(   33267),  UINT16_C(   27103),  UINT16_C(   28719) },
      {  UINT16_C(   13000),  UINT16_C(   43843),  UINT16_C(   22177),  UINT16_C(   31195) },
      {  UINT16_C(   27978),  UINT16_C(   26702),  UINT16_C(   22177),  UINT16_C(   31195) },
      {  UINT16_C(   27978),  UINT16_C(   43843),  UINT16_C(   33267),  UINT16_C(   31195) },
      {  UINT16_C(   27978),  UINT16_C(   43843),  UINT16_C(   22177),  UINT16_C(   28719) } },
    { {  UINT16_C(    1114),  UINT16_C(   44831),  UINT16_C(   23387),  UINT16_C(   26671) },
      {  UINT16_C(   62402),  UINT16_C(   40206),  UINT16_C(    5589),  UINT16_C(   46365),
         UINT16_C(   15546),  UINT16_C(   56079),  UINT16_C(   10655),  UINT16_C(   28459) },
      {  UINT16_C(   62402),  UINT16_C(   44831),  UINT16_C(   23387),  UINT16_C(   26671) },
      {  UINT16_C(    1114),  UINT16_C(   46365),  UINT16_C(   23387),  UINT16_C(   26671) },
      {  UINT16_C(    1114),  UINT16_C(   44831),  UINT16_C(   56079),  UINT16_C(   26671) },
      {  UINT16_C(    1114),  UINT16_C(   44831),  UINT16_C(   23387),  UINT16_C(   28459) } },
    { {  UINT16_C(   15907),  UINT16_C(   19190),  UINT16_C(   53939),  UINT16_C(   23137) },
      {  UINT16_C(   31842),  UINT16_C(   25173),  UINT16_C(    4547),  UINT16_C(    2456),
         UINT16_C(   47549),  UINT16_C(   26853),  UINT16_C(   42826),  UINT16_C(   39063) },
      {  UINT16_C(   31842),  UINT16_C(   19190),  UINT16_C(   53939),  UINT16_C(   23137) },
      {  UINT16_C(   15907),  UINT16_C(    2456),  UINT16_C(   53939),  UINT16_C(   23137) },
      {  UINT16_C(   15907),  UINT16_C(   19190),  UINT16_C(   26853),  UINT16_C(   23137) },
      {  UINT16_C(   15907),  UINT16_C(   19190),  UINT16_C(   53939),  UINT16_C(   39063) } },
    { {  UINT16_C(   35181),  UINT16_C(   17415),  UINT16_C(   59315),  UINT16_C(   49844) },
      {  UINT16_C(   32240),  UINT16_C(   12816),  UINT16_C(   48038),  UINT16_C(   32248),
         UINT16_C(   21982),  UINT16_C(   58359),  UINT16_C(   59704),  UINT16_C(   41823) },
      {  UINT16_C(   32240),  UINT16_C(   17415),  UINT16_C(   59315),  UINT16_C(   49844) },
      {  UINT16_C(   35181),  UINT16_C(   32248),  UINT16_C(   59315),  UINT16_C(   49844) },
      {  UINT16_C(   35181),  UINT16_C(   17415),  UINT16_C(   58359),  UINT16_C(   49844) },
      {  UINT16_C(   35181),  UINT16_C(   17415),  UINT16_C(   59315),  UINT16_C(   41823) } },
    { {  UINT16_C(   10135),  UINT16_C(    9895),  UINT16_C(   14931),  UINT16_C(    6474) },
      {  UINT16_C(   48682),  UINT16_C(    7265),  UINT16_C(    8191),  UINT16_C(   33426),
         UINT16_C(   41840),  UINT16_C(   56821),  UINT16_C(    7954),  UINT16_C(   43755) },
      {  UINT16_C(   48682),  UINT16_C(    9895),  UINT16_C(   14931),  UINT16_C(    6474) },
      {  UINT16_C(   10135),  UINT16_C(   33426),  UINT16_C(   14931),  UINT16_C(    6474) },
      {  UINT16_C(   10135),  UINT16_C(    9895),  UINT16_C(   56821),  UINT16_C(    6474) },
      {  UINT16_C(   10135),  UINT16_C(    9895),  UINT16_C(   14931),  UINT16_C(   43755) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x4_t r0_0 = simde_vcopy_laneq_u16(a, 0, b, 0);
    simde_uint16x4_t r1_3 = simde_vcopy_laneq_u16(a, 1, b, 3);
    simde_uint16x4_t r2_5 = simde_vcopy_laneq_u16(a, 2, b, 5);
    simde_uint16x4_t r3_7 = simde_vcopy_laneq_u16(a, 3, b, 7);

    simde_test_arm_neon_assert_equal_u16x4(r0_0, simde_vld1_u16(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_u16x4(r1_3, simde_vld1_u16(test_vec[i].r1_3));
    simde_test_arm_neon_assert_equal_u16x4(r2_5, simde_vld1_u16(test_vec[i].r2_5));
    simde_test_arm_neon_assert_equal_u16x4(r3_7, simde_vld1_u16(test_vec[i].r3_7));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x4_t r0_0 = simde_vcopy_laneq_u16(a, 0, b, 0);
    simde_uint16x4_t r1_3 = simde_vcopy_laneq_u16(a, 1, b, 3);
    simde_uint16x4_t r2_5 = simde_vcopy_laneq_u16(a, 2, b, 5);
    simde_uint16x4_t r3_7 = simde_vcopy_laneq_u16(a, 3, b, 7);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r1_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r2_5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r3_7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[4];
    uint32_t r0_0[2];
    uint32_t r0_2[2];
    uint32_t r1_1[2];
    uint32_t r1_3[2];
  } test_vec[] = {
    { {  UINT32_C(  1263327646),  UINT32_C(  3936930385) },
      {  UINT32_C(  1009741332),  UINT32_C(  1271791302),  UINT32_C(  2117473016),  UINT32_C(  1209805040) },
      {  UINT32_C(  1009741332),  UINT32_C(  3936930385) },
      {  UINT32_C(  2117473016),  UINT32_C(  3936930385) },
      {  UINT32_C(  1263327646),  UINT32_C(  1271791302) },
      {  UINT32_C(  1263327646),  UINT32_C(  1209805040) } },
    { {  UINT32_C(  3169852858),  UINT32_C(  4047976040) },
      {  UINT32_C(  3469589779),  UINT32_C(   319323338),  UINT32_C(  2782162475),  UINT32_C(  3540513941) },
      {  UINT32_C(  3469589779),  UINT32_C(  4047976040) },
      {  UINT32_C(  2782162475),  UINT32_C(  4047976040) },
      {  UINT32_C(  3169852858),  UINT32_C(   319323338) },
      {  UINT32_C(  3169852858),  UINT32_C(  3540513941) } },
    { {  UINT32_C(   723977372),  UINT32_C(  1213626978) },
      {  UINT32_C(  2388609191),  UINT32_C(  1459060976),  UINT32_C(  1783941758),  UINT32_C(   514486587) },
      {  UINT32_C(  2388609191),  UINT32_C(  1213626978) },
      {  UINT32_C(  1783941758),  UINT32_C(  1213626978) },
      {  UINT32_C(   723977372),  UINT32_C(  1459060976) },
      {  UINT32_C(   723977372),  UINT32_C(   514486587) } },
    { {  UINT32_C(  2520531324),  UINT32_C(  2850749730) },
      {  UINT32_C(   888192105),  UINT32_C(  1739139179),  UINT32_C(   230879930),  UINT32_C(  1965453646) },
      {  UINT32_C(   888192105),  UINT32_C(  2850749730) },
      {  UINT32_C(   230879930),  UINT32_C(  2850749730) },
      {  UINT32_C(  2520531324),  UINT32_C(  1739139179) },
      {  UINT32_C(  2520531324),  UINT32_C(  1965453646) } },
    { {  UINT32_C(  2822169713),  UINT32_C(  1803041930) },
      {  UINT32_C(  2701651503),  UINT32_C(  1720551226),  UINT32_C(  2473213009),  UINT32_C(  1517886129) },
      {  UINT32_C(  2701651503),  UINT32_C(  1803041930) },
      {  UINT32_C(  2473213009),  UINT32_C(  1803041930) },
      {  UINT32_C(  2822169713),  UINT32_C(  1720551226) },
      {  UINT32_C(  2822169713),  UINT32_C(  1517886129) } },
    { {  UINT32_C(  1141343430),  UINT32_C(  3637108750) },
      {  UINT32_C(  3503443812),  UINT32_C(  4186632742),  UINT32_C(  1721722610),  UINT32_C(  1039187286) },
      {  UINT32_C(  3503443812),  UINT32_C(  3637108750) },
      {  UINT32_C(  1721722610),  UINT32_C(  3637108750) },
      {  UINT32_C(  1141343430),  UINT32_C(  4186632742) },
      {  UINT32_C(  1141343430),  UINT32_C(  1039187286) } },
    { {  UINT32_C(   678901130),  UINT32_C(  1376760353) },
      {  UINT32_C(    56937070),  UINT32_C(  3336802856),  UINT32_C(  3559984617),  UINT32_C(  1829425083) },
      {  UINT32_C(    56937070),  UINT32_C(  1376760353) },
      {  UINT32_C(  3559984617),  UINT32_C(  1376760353) },
      {  UINT32_C(   678901130),  UINT32_C(  3336802856) },
      {  UINT32_C(   678901130),  UINT32_C(  1829425083) } },
    { {  UINT32_C(   566419176),  UINT32_C(  1835229255) },
      {  UINT32_C(  2657473149),  UINT32_C(  3998120314),  UINT32_C(  3755826214),  UINT32_C(  1740123970) },
      {  UINT32_C(  2657473149),  UINT32_C(  1835229255) },
      {  UINT32_C(  3755826214),  UINT32_C(  1835229255) },
      {  UINT32_C(   566419176),  UINT32_C(  3998120314) },
      {  UINT32_C(   566419176),  UINT32_C(  1740123970) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x2_t r0_0 = simde_vcopy_laneq_u32(a, 0, b, 0);
    simde_uint32x2_t r0_2 = simde_vcopy_laneq_u32(a, 0, b, 2);
    simde_uint32x2_t r1_1 = simde_vcopy_laneq_u32(a, 1, b, 1);
    simde_uint32x2_t r1_3 = simde_vcopy_laneq_u32(a, 1, b, 3);

    simde_test_arm_neon_assert_equal_u32x2(r0_0, simde_vld1_u32(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_u32x2(r0_2, simde_vld1_u32(test_vec[i].r0_2));
    simde_test_arm_neon_assert_equal_u32x2(r1_1, simde_vld1_u32(test_vec[i].r1_1));
    simde_test_arm_neon_assert_equal_u32x2(r1_3, simde_vld1_u32(test_vec[i].r1_3));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();

    simde_uint32x2_t r0_0 = simde_vcopy_laneq_u32(a, 0, b, 0);
    simde_uint32x2_t r0_2 = simde_vcopy_laneq_u32(a, 0, b, 2);
    simde_uint32x2_t r1_1 = simde_vcopy_laneq_u32(a, 1, b, 1);
    simde_uint32x2_t r1_3 = simde_vcopy_laneq_u32(a, 1, b, 3);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r0_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r1_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r1_3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[2];
    uint64_t r0_0[1];
    uint64_t r0_1[1];
  } test_vec[] = {
    { {  UINT64_C( 4774845596606571093) },
      {  UINT64_C( 8217638833653863154),  UINT64_C(17418031248681962729) },
      {  UINT64_C( 8217638833653863154) },
      {  UINT64_C(17418031248681962729) } },
    { {  UINT64_C(17601450605500208340) },
      {  UINT64_C( 2768201381815185750),  UINT64_C(16070785927570141580) },
      {  UINT64_C( 2768201381815185750) },
      {  UINT64_C(16070785927570141580) } },
    { {  UINT64_C( 5515676140731327920) },
      {  UINT64_C(10667193760066591791),  UINT64_C( 5614703629073485915) },
      {  UINT64_C(10667193760066591791) },
      {  UINT64_C( 5614703629073485915) } },
    { {  UINT64_C( 8834081084411742948) },
      {  UINT64_C( 9878499915507241938),  UINT64_C(12395589140738461358) },
      {  UINT64_C( 9878499915507241938) },
      {  UINT64_C(12395589140738461358) } },
    { {  UINT64_C(14076324571948981968) },
      {  UINT64_C(13707984266428261295),  UINT64_C(16651015344936509577) },
      {  UINT64_C(13707984266428261295) },
      {  UINT64_C(16651015344936509577) } },
    { {  UINT64_C( 7401032381136844628) },
      {  UINT64_C(13595471166024805103),  UINT64_C(12253610641519224975) },
      {  UINT64_C(13595471166024805103) },
      {  UINT64_C(12253610641519224975) } },
    { {  UINT64_C( 3043905301656645740) },
      {  UINT64_C(13594318462557334235),  UINT64_C(  878904381009645699) },
      {  UINT64_C(13594318462557334235) },
      {  UINT64_C(  878904381009645699) } },
    { {  UINT64_C( 7588891631142822727) },
      {  UINT64_C( 1673981919106237551),  UINT64_C(12358823236528999795) },
      {  UINT64_C( 1673981919106237551) },
      {  UINT64_C(12358823236528999795) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);

    simde_uint64x1_t r0_0 = simde_vcopy_laneq_u64(a, 0, b, 0);
    simde_uint64x1_t r0_1 = simde_vcopy_laneq_u64(a, 0, b, 1);

    simde_test_arm_neon_assert_equal_u64x1(r0_0, simde_vld1_u64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_u64x1(r0_1, simde_vld1_u64(test_vec[i].r0_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x1_t r0_0 = simde_vcopy_laneq_u64(a, 0, b, 0);
    simde_uint64x1_t r0_1 = simde_vcopy_laneq_u64(a, 0, b, 1);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r0_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t b[4];
    simde_float32_t r0_0[2];
    simde_float32_t r0_2[2];
    simde_float32_t r1_1[2];
    simde_float32_t r1_3[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(  9416.182), -SIMDE_FLOAT32_C(  8833.327) },
      { -SIMDE_FLOAT32_C(  8422.051), -SIMDE_FLOAT32_C(  1474.965),  SIMDE_FLOAT32_C(    22.255),  SIMDE_FLOAT32_C(  1862.729) },
      { -SIMDE_FLOAT32_C(  8422.051), -SIMDE_FLOAT32_C(  8833.327) },
      {  SIMDE_FLOAT32_C(    22.255), -SIMDE_FLOAT32_C(  8833.327) },
      {  SIMDE_FLOAT32_C(  9416.182), -SIMDE_FLOAT32_C(  1474.965) },
      {  SIMDE_FLOAT32_C(  9416.182),  SIMDE_FLOAT32_C(  1862.729) } },
    { { -SIMDE_FLOAT32_C(  9615.762), -SIMDE_FLOAT32_C(    14.217) },
      { -SIMDE_FLOAT32_C(  5132.670),  SIMDE_FLOAT32_C(  3844.124),  SIMDE_FLOAT32_C(  8234.064), -SIMDE_FLOAT32_C(  7859.389) },
      { -SIMDE_FLOAT32_C(  5132.670), -SIMDE_FLOAT32_C(    14.217) },
      {  SIMDE_FLOAT32_C(  8234.064), -SIMDE_FLOAT32_C(    14.217) },
      { -SIMDE_FLOAT32_C(  9615.762),  SIMDE_FLOAT32_C(  3844.124) },
      { -SIMDE_FLOAT32_C(  9615.762), -SIMDE_FLOAT32_C(  7859.389) } },
    { { -SIMDE_FLOAT32_C(  4940.350), -SIMDE_FLOAT32_C(  8895.818) },
      { -SIMDE_FLOAT32_C(  4031.934),  SIMDE_FLOAT32_C(  2112.525),  SIMDE_FLOAT32_C(  6157.536),  SIMDE_FLOAT32_C(  6249.606) },
      { -SIMDE_FLOAT32_C(  4031.934), -SIMDE_FLOAT32_C(  8895.818) },
      {  SIMDE_FLOAT32_C(  6157.536), -SIMDE_FLOAT32_C(  8895.818) },
      { -SIMDE_FLOAT32_C(  4940.350),  SIMDE_FLOAT32_C(  2112.525) },
      { -SIMDE_FLOAT32_C(  4940.350),  SIMDE_FLOAT32_C(  6249.606) } },
    { {  SIMDE_FLOAT32_C(  9344.492),  SIMDE_FLOAT32_C(  2826.421) },
      { -SIMDE_FLOAT32_C(  5138.487),  SIMDE_FLOAT32_C(  5406.190),  SIMDE_FLOAT32_C(  8334.525),  SIMDE_FLOAT32_C(  6643.959) },
      { -SIMDE_FLOAT32_C(  5138.487),  SIMDE_FLOAT32_C(  2826.421) },
      {  SIMDE_FLOAT32_C(  8334.525),  SIMDE_FLOAT32_C(  2826.421) },
      {  SIMDE_FLOAT32_C(  9344.492),  SIMDE_FLOAT32_C(  5406.190) },
      {  SIMDE_FLOAT32_C(  9344.492),  SIMDE_FLOAT32_C(  6643.959) } },
    { { -SIMDE_FLOAT32_C(  6024.062),  SIMDE_FLOAT32_C(  6388.316) },
      {  SIMDE_FLOAT32_C(  2465.654),  SIMDE_FLOAT32_C(  3539.057), -SIMDE_FLOAT32_C(  6462.303), -SIMDE_FLOAT32_C(  2503.313) },
      {  SIMDE_FLOAT32_C(  2465.654),  SIMDE_FLOAT32_C(  6388.316) },
      { -SIMDE_FLOAT32_C(  6462.303),  SIMDE_FLOAT32_C(  6388.316) },
      { -SIMDE_FLOAT32_C(  6024.062),  SIMDE_FLOAT32_C(  3539.057) },
      { -SIMDE_FLOAT32_C(  6024.062), -SIMDE_FLOAT32_C(  2503.313) } },
    { { -SIMDE_FLOAT32_C(  2609.983), -SIMDE_FLOAT32_C(  2150.719) },
      { -SIMDE_FLOAT32_C(  2105.146), -SIMDE_FLOAT32_C(  4271.761),  SIMDE_FLOAT32_C(  4775.484), -SIMDE_FLOAT32_C(  8675.755) },
      { -SIMDE_FLOAT32_C(  2105.146), -SIMDE_FLOAT32_C(  2150.719) },
      {  SIMDE_FLOAT32_C(  4775.484), -SIMDE_FLOAT32_C(  2150.719) },
      { -SIMDE_FLOAT32_C(  2609.983), -SIMDE_FLOAT32_C(  4271.761) },
      { -SIMDE_FLOAT32_C(  2609.983), -SIMDE_FLOAT32_C(  8675.755) } },
    { { -SIMDE_FLOAT32_C(  7533.391),  SIMDE_FLOAT32_C(  2646.042) },
      { -SIMDE_FLOAT32_C(  4768.051), -SIMDE_FLOAT32_C(  9232.611),  SIMDE_FLOAT32_C(  5796.161),  SIMDE_FLOAT32_C(   319.964) },
      { -SIMDE_FLOAT32_C(  4768.051),  SIMDE_FLOAT32_C(  2646.042) },
      {  SIMDE_FLOAT32_C(  5796.161),  SIMDE_FLOAT32_C(  2646.042) },
      { -SIMDE_FLOAT32_C(  7533.391), -SIMDE_FLOAT32_C(  9232.611) },
      { -SIMDE_FLOAT32_C(  7533.391),  SIMDE_FLOAT32_C(   319.964) } },
    { { -SIMDE_FLOAT32_C(  9847.213),  SIMDE_FLOAT32_C(  6520.873) },
      {  SIMDE_FLOAT32_C(  9756.117),  SIMDE_FLOAT32_C(   625.608), -SIMDE_FLOAT32_C(   979.024), -SIMDE_FLOAT32_C(   183.463) },
      {  SIMDE_FLOAT32_C(  9756.117),  SIMDE_FLOAT32_C(  6520.873) },
      { -SIMDE_FLOAT32_C(   979.024),  SIMDE_FLOAT32_C(  6520.873) },
      { -SIMDE_FLOAT32_C(  9847.213),  SIMDE_FLOAT32_C(   625.608) },
      { -SIMDE_FLOAT32_C(  9847.213), -SIMDE_FLOAT32_C(   183.463) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);

    simde_float32x2_t r0_0 = simde_vcopy_laneq_f32(a, 0, b, 0);
    simde_float32x2_t r0_2 = simde_vcopy_laneq_f32(a, 0, b, 2);
    simde_float32x2_t r1_1 = simde_vcopy_laneq_f32(a, 1, b, 1);
    simde_float32x2_t r1_3 = simde_vcopy_laneq_f32(a, 1, b, 3);

    simde_test_arm_neon_assert_equal_f32x2(r0_0, simde_vld1_f32(test_vec[i].r0_0), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r0_2, simde_vld1_f32(test_vec[i].r0_2), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r1_1, simde_vld1_f32(test_vec[i].r1_1), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r1_3, simde_vld1_f32(test_vec[i].r1_3), INT_MAX);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t r0_0 = simde_vcopy_laneq_f32(a, 0, b, 0);
    simde_float32x2_t r0_2 = simde_vcopy_laneq_f32(a, 0, b, 2);
    simde_float32x2_t r1_1 = simde_vcopy_laneq_f32(a, 1, b, 1);
    simde_float32x2_t r1_3 = simde_vcopy_laneq_f32(a, 1, b, 3);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r0_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r1_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r1_3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[1];
    simde_float64_t b[2];
    simde_float64_t r0_0[1];
    simde_float64_t r0_1[1];
  } test_vec[] = {
    { { -SIMDE_FLOAT64_C(  739568.812) },
      { -SIMDE_FLOAT64_C(  918096.188), -SIMDE_FLOAT64_C(  636033.688) },
      { -SIMDE_FLOAT64_C(  918096.188) },
      { -SIMDE_FLOAT64_C(  636033.688) } },
    { {  SIMDE_FLOAT64_C(  347996.500) },
      { -SIMDE_FLOAT64_C(  789037.625),  SIMDE_FLOAT64_C(  410753.000) },
      { -SIMDE_FLOAT64_C(  789037.625) },
      {  SIMDE_FLOAT64_C(  410753.000) } },
    { { -SIMDE_FLOAT64_C(  519933.062) },
      {  SIMDE_FLOAT64_C(  858011.500),  SIMDE_FLOAT64_C(  664039.875) },
      {  SIMDE_FLOAT64_C(  858011.500) },
      {  SIMDE_FLOAT64_C(  664039.875) } },
    { { -SIMDE_FLOAT64_C(  836484.250) },
      {  SIMDE_FLOAT64_C(  343727.500), -SIMDE_FLOAT64_C(  654913.188) },
      {  SIMDE_FLOAT64_C(  343727.500) },
      { -SIMDE_FLOAT64_C(  654913.188) } },
    { {  SIMDE_FLOAT64_C(  462913.500) },
      { -SIMDE_FLOAT64_C(  509992.406), -SIMDE_FLOAT64_C(  610779.125) },
      { -SIMDE_FLOAT64_C(  509992.406) },
      { -SIMDE_FLOAT64_C(  610779.125) } },
    { { -SIMDE_FLOAT64_C(  265341.438) },
      {  SIMDE_FLOAT64_C(  503597.625),  SIMDE_FLOAT64_C(  215071.125) },
      {  SIMDE_FLOAT64_C(  503597.625) },
      {  SIMDE_FLOAT64_C(  215071.125) } },
    { { -SIMDE_FLOAT64_C(  582044.625) },
      {  SIMDE_FLOAT64_C(  731499.250), -SIMDE_FLOAT64_C(  730278.875) },
      {  SIMDE_FLOAT64_C(  731499.250) },
      { -SIMDE_FLOAT64_C(  730278.875) } },
    { { -SIMDE_FLOAT64_C(  991497.875) },
      { -SIMDE_FLOAT64_C(  653912.188),  SIMDE_FLOAT64_C(   50960.625) },
      { -SIMDE_FLOAT64_C(  653912.188) },
      {  SIMDE_FLOAT64_C(   50960.625) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);

    simde_float64x1_t r0_0 = simde_vcopy_laneq_f64(a, 0, b, 0);
    simde_float64x1_t r0_1 = simde_vcopy_laneq_f64(a, 0, b, 1);

    simde_test_arm_neon_assert_equal_f64x1(r0_0, simde_vld1_f64(test_vec[i].r0_0), INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r0_1, simde_vld1_f64(test_vec[i].r0_1), INT_MAX);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r0_0 = simde_vcopy_laneq_f64(a, 0, b, 0);
    simde_float64x1_t r0_1 = simde_vcopy_laneq_f64(a, 0, b, 1);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r0_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[8];
    int8_t r0_7[16];
    int8_t r4_6[16];
    int8_t r8_4[16];
    int8_t r12_3[16];
    int8_t r15_1[16];
  } test_vec[] = {
    { {  INT8_C(    7), -INT8_C(  118),  INT8_C(   62), -INT8_C(   50),
        -INT8_C(  105), -INT8_C(   76), -INT8_C(   19),  INT8_C(  111),
         INT8_C(   32),  INT8_C(   20), -INT8_C(   96), -INT8_C(   77),
        -INT8_C(   83), -INT8_C(   39),  INT8_C(   22),  INT8_C(   28) },
      { -INT8_C(   93),  INT8_C(    1), -INT8_C(  111), -INT8_C(   96),
        -INT8_C(  106), -INT8_C(   86),  INT8_C(   43),  INT8_C(   48) },
      {  INT8_C(   48), -INT8_C(  118),  INT8_C(   62), -INT8_C(   50),
        -INT8_C(  105), -INT8_C(   76), -INT8_C(   19),  INT8_C(  111),
         INT8_C(   32),  INT8_C(   20), -INT8_C(   96), -INT8_C(   77),
        -INT8_C(   83), -INT8_C(   39),  INT8_C(   22),  INT8_C(   28) },
      {  INT8_C(    7), -INT8_C(  118),  INT8_C(   62), -INT8_C(   50),
         INT8_C(   43), -INT8_C(   76), -INT8_C(   19),  INT8_C(  111),
         INT8_C(   32),  INT8_C(   20), -INT8_C(   96), -INT8_C(   77),
        -INT8_C(   83), -INT8_C(   39),  INT8_C(   22),  INT8_C(   28) },
      {  INT8_C(    7), -INT8_C(  118),  INT8_C(   62), -INT8_C(   50),
        -INT8_C(  105), -INT8_C(   76), -INT8_C(   19),  INT8_C(  111),
        -INT8_C(  106),  INT8_C(   20), -INT8_C(   96), -INT8_C(   77),
        -INT8_C(   83), -INT8_C(   39),  INT8_C(   22),  INT8_C(   28) },
      {  INT8_C(    7), -INT8_C(  118),  INT8_C(   62), -INT8_C(   50),
        -INT8_C(  105), -INT8_C(   76), -INT8_C(   19),  INT8_C(  111),
         INT8_C(   32),  INT8_C(   20), -INT8_C(   96), -INT8_C(   77),
        -INT8_C(   96), -INT8_C(   39),  INT8_C(   22),  INT8_C(   28) },
      {  INT8_C(    7), -INT8_C(  118),  INT8_C(   62), -INT8_C(   50),
        -INT8_C(  105), -INT8_C(   76), -INT8_C(   19),  INT8_C(  111),
         INT8_C(   32),  INT8_C(   20), -INT8_C(   96), -INT8_C(   77),
        -INT8_C(   83), -INT8_C(   39),  INT8_C(   22),  INT8_C(    1) } },
    { {  INT8_C(   96),  INT8_C(   23),  INT8_C(  106),  INT8_C(  101),
        -INT8_C(   33), -INT8_C(   74), -INT8_C(   78),  INT8_C(   22),
        -INT8_C(   65),  INT8_C(   29), -INT8_C(    8), -INT8_C(   48),
        -INT8_C(   25), -INT8_C(  117),  INT8_C(  123), -INT8_C(   19) },
      { -INT8_C(   31),  INT8_C(  116),  INT8_C(  103), -INT8_C(  112),
         INT8_C(  118),  INT8_C(   34), -INT8_C(   70), -INT8_C(   51) },
      { -INT8_C(   51),  INT8_C(   23),  INT8_C(  106),  INT8_C(  101),
        -INT8_C(   33), -INT8_C(   74), -INT8_C(   78),  INT8_C(   22),
        -INT8_C(   65),  INT8_C(   29), -INT8_C(    8), -INT8_C(   48),
        -INT8_C(   25), -INT8_C(  117),  INT8_C(  123), -INT8_C(   19) },
      {  INT8_C(   96),  INT8_C(   23),  INT8_C(  106),  INT8_C(  101),
        -INT8_C(   70), -INT8_C(   74), -INT8_C(   78),  INT8_C(   22),
        -INT8_C(   65),  INT8_C(   29), -INT8_C(    8), -INT8_C(   48),
        -INT8_C(   25), -INT8_C(  117),  INT8_C(  123), -INT8_C(   19) },
      {  INT8_C(   96),  INT8_C(   23),  INT8_C(  106),  INT8_C(  101),
        -INT8_C(   33), -INT8_C(   74), -INT8_C(   78),  INT8_C(   22),
         INT8_C(  118),  INT8_C(   29), -INT8_C(    8), -INT8_C(   48),
        -INT8_C(   25), -INT8_C(  117),  INT8_C(  123), -INT8_C(   19) },
      {  INT8_C(   96),  INT8_C(   23),  INT8_C(  106),  INT8_C(  101),
        -INT8_C(   33), -INT8_C(   74), -INT8_C(   78),  INT8_C(   22),
        -INT8_C(   65),  INT8_C(   29), -INT8_C(    8), -INT8_C(   48),
        -INT8_C(  112), -INT8_C(  117),  INT8_C(  123), -INT8_C(   19) },
      {  INT8_C(   96),  INT8_C(   23),  INT8_C(  106),  INT8_C(  101),
        -INT8_C(   33), -INT8_C(   74), -INT8_C(   78),  INT8_C(   22),
        -INT8_C(   65),  INT8_C(   29), -INT8_C(    8), -INT8_C(   48),
        -INT8_C(   25), -INT8_C(  117),  INT8_C(  123),  INT8_C(  116) } },
    { { -INT8_C(   29), -INT8_C(    7), -INT8_C(  116), -INT8_C(   65),
        -INT8_C(   18), -INT8_C(   27), -INT8_C(   92), -INT8_C(   16),
        -INT8_C(   37),  INT8_C(  116),  INT8_C(   54), -INT8_C(   34),
        -INT8_C(   89), -INT8_C(   18), -INT8_C(   68), -INT8_C(  102) },
      {  INT8_C(   43), -INT8_C(   14), -INT8_C(   83),  INT8_C(  108),
        -INT8_C(   89),  INT8_C(   34),  INT8_C(   58),  INT8_C(    0) },
      {  INT8_C(    0), -INT8_C(    7), -INT8_C(  116), -INT8_C(   65),
        -INT8_C(   18), -INT8_C(   27), -INT8_C(   92), -INT8_C(   16),
        -INT8_C(   37),  INT8_C(  116),  INT8_C(   54), -INT8_C(   34),
        -INT8_C(   89), -INT8_C(   18), -INT8_C(   68), -INT8_C(  102) },
      { -INT8_C(   29), -INT8_C(    7), -INT8_C(  116), -INT8_C(   65),
         INT8_C(   58), -INT8_C(   27), -INT8_C(   92), -INT8_C(   16),
        -INT8_C(   37),  INT8_C(  116),  INT8_C(   54), -INT8_C(   34),
        -INT8_C(   89), -INT8_C(   18), -INT8_C(   68), -INT8_C(  102) },
      { -INT8_C(   29), -INT8_C(    7), -INT8_C(  116), -INT8_C(   65),
        -INT8_C(   18), -INT8_C(   27), -INT8_C(   92), -INT8_C(   16),
        -INT8_C(   89),  INT8_C(  116),  INT8_C(   54), -INT8_C(   34),
        -INT8_C(   89), -INT8_C(   18), -INT8_C(   68), -INT8_C(  102) },
      { -INT8_C(   29), -INT8_C(    7), -INT8_C(  116), -INT8_C(   65),
        -INT8_C(   18), -INT8_C(   27), -INT8_C(   92), -INT8_C(   16),
        -INT8_C(   37),  INT8_C(  116),  INT8_C(   54), -INT8_C(   34),
         INT8_C(  108), -INT8_C(   18), -INT8_C(   68), -INT8_C(  102) },
      { -INT8_C(   29), -INT8_C(    7), -INT8_C(  116), -INT8_C(   65),
        -INT8_C(   18), -INT8_C(   27), -INT8_C(   92), -INT8_C(   16),
        -INT8_C(   37),  INT8_C(  116),  INT8_C(   54), -INT8_C(   34),
        -INT8_C(   89), -INT8_C(   18), -INT8_C(   68), -INT8_C(   14) } },
    { { -INT8_C(   41),  INT8_C(   20),  INT8_C(   87),  INT8_C(   37),
        -INT8_C(   17), -INT8_C(   85),  INT8_C(  120), -INT8_C(   41),
         INT8_C(  124), -INT8_C(   59),  INT8_C(   63), -INT8_C(    2),
         INT8_C(   20), -INT8_C(   48), -INT8_C(    9),  INT8_C(  105) },
      {  INT8_C(   63), -INT8_C(   79), -INT8_C(  114),  INT8_C(    6),
         INT8_C(   40), -INT8_C(  108), -INT8_C(   46),  INT8_C(   54) },
      {  INT8_C(   54),  INT8_C(   20),  INT8_C(   87),  INT8_C(   37),
        -INT8_C(   17), -INT8_C(   85),  INT8_C(  120), -INT8_C(   41),
         INT8_C(  124), -INT8_C(   59),  INT8_C(   63), -INT8_C(    2),
         INT8_C(   20), -INT8_C(   48), -INT8_C(    9),  INT8_C(  105) },
      { -INT8_C(   41),  INT8_C(   20),  INT8_C(   87),  INT8_C(   37),
        -INT8_C(   46), -INT8_C(   85),  INT8_C(  120), -INT8_C(   41),
         INT8_C(  124), -INT8_C(   59),  INT8_C(   63), -INT8_C(    2),
         INT8_C(   20), -INT8_C(   48), -INT8_C(    9),  INT8_C(  105) },
      { -INT8_C(   41),  INT8_C(   20),  INT8_C(   87),  INT8_C(   37),
        -INT8_C(   17), -INT8_C(   85),  INT8_C(  120), -INT8_C(   41),
         INT8_C(   40), -INT8_C(   59),  INT8_C(   63), -INT8_C(    2),
         INT8_C(   20), -INT8_C(   48), -INT8_C(    9),  INT8_C(  105) },
      { -INT8_C(   41),  INT8_C(   20),  INT8_C(   87),  INT8_C(   37),
        -INT8_C(   17), -INT8_C(   85),  INT8_C(  120), -INT8_C(   41),
         INT8_C(  124), -INT8_C(   59),  INT8_C(   63), -INT8_C(    2),
         INT8_C(    6), -INT8_C(   48), -INT8_C(    9),  INT8_C(  105) },
      { -INT8_C(   41),  INT8_C(   20),  INT8_C(   87),  INT8_C(   37),
        -INT8_C(   17), -INT8_C(   85),  INT8_C(  120), -INT8_C(   41),
         INT8_C(  124), -INT8_C(   59),  INT8_C(   63), -INT8_C(    2),
         INT8_C(   20), -INT8_C(   48), -INT8_C(    9), -INT8_C(   79) } },
    { {  INT8_C(   48),  INT8_C(  105),  INT8_C(   63), -INT8_C(  110),
        -INT8_C(   51), -INT8_C(   88), -INT8_C(   45),  INT8_C(   22),
         INT8_C(   52),  INT8_C(   62), -INT8_C(  123),  INT8_C(   67),
         INT8_C(   85), -INT8_C(   18), -INT8_C(   25),  INT8_C(   27) },
      {  INT8_C(   30),  INT8_C(   77),  INT8_C(   53),  INT8_C(    9),
        -INT8_C(   64), -INT8_C(   87),  INT8_C(   56),  INT8_C(   58) },
      {  INT8_C(   58),  INT8_C(  105),  INT8_C(   63), -INT8_C(  110),
        -INT8_C(   51), -INT8_C(   88), -INT8_C(   45),  INT8_C(   22),
         INT8_C(   52),  INT8_C(   62), -INT8_C(  123),  INT8_C(   67),
         INT8_C(   85), -INT8_C(   18), -INT8_C(   25),  INT8_C(   27) },
      {  INT8_C(   48),  INT8_C(  105),  INT8_C(   63), -INT8_C(  110),
         INT8_C(   56), -INT8_C(   88), -INT8_C(   45),  INT8_C(   22),
         INT8_C(   52),  INT8_C(   62), -INT8_C(  123),  INT8_C(   67),
         INT8_C(   85), -INT8_C(   18), -INT8_C(   25),  INT8_C(   27) },
      {  INT8_C(   48),  INT8_C(  105),  INT8_C(   63), -INT8_C(  110),
        -INT8_C(   51), -INT8_C(   88), -INT8_C(   45),  INT8_C(   22),
        -INT8_C(   64),  INT8_C(   62), -INT8_C(  123),  INT8_C(   67),
         INT8_C(   85), -INT8_C(   18), -INT8_C(   25),  INT8_C(   27) },
      {  INT8_C(   48),  INT8_C(  105),  INT8_C(   63), -INT8_C(  110),
        -INT8_C(   51), -INT8_C(   88), -INT8_C(   45),  INT8_C(   22),
         INT8_C(   52),  INT8_C(   62), -INT8_C(  123),  INT8_C(   67),
         INT8_C(    9), -INT8_C(   18), -INT8_C(   25),  INT8_C(   27) },
      {  INT8_C(   48),  INT8_C(  105),  INT8_C(   63), -INT8_C(  110),
        -INT8_C(   51), -INT8_C(   88), -INT8_C(   45),  INT8_C(   22),
         INT8_C(   52),  INT8_C(   62), -INT8_C(  123),  INT8_C(   67),
         INT8_C(   85), -INT8_C(   18), -INT8_C(   25),  INT8_C(   77) } },
    { {  INT8_C(   96),  INT8_C(   87), -INT8_C(   47),  INT8_C(  101),
         INT8_C(  117),  INT8_C(  119),  INT8_C(   90),  INT8_C(  103),
        -INT8_C(   71),  INT8_C(   27),  INT8_C(   71),  INT8_C(   69),
         INT8_C(   58),  INT8_C(   11), -INT8_C(   68), -INT8_C(   36) },
      {  INT8_C(   10),  INT8_C(   92),  INT8_C(  122),  INT8_C(   88),
         INT8_C(   63),  INT8_C(   40), -INT8_C(   15), -INT8_C(   67) },
      { -INT8_C(   67),  INT8_C(   87), -INT8_C(   47),  INT8_C(  101),
         INT8_C(  117),  INT8_C(  119),  INT8_C(   90),  INT8_C(  103),
        -INT8_C(   71),  INT8_C(   27),  INT8_C(   71),  INT8_C(   69),
         INT8_C(   58),  INT8_C(   11), -INT8_C(   68), -INT8_C(   36) },
      {  INT8_C(   96),  INT8_C(   87), -INT8_C(   47),  INT8_C(  101),
        -INT8_C(   15),  INT8_C(  119),  INT8_C(   90),  INT8_C(  103),
        -INT8_C(   71),  INT8_C(   27),  INT8_C(   71),  INT8_C(   69),
         INT8_C(   58),  INT8_C(   11), -INT8_C(   68), -INT8_C(   36) },
      {  INT8_C(   96),  INT8_C(   87), -INT8_C(   47),  INT8_C(  101),
         INT8_C(  117),  INT8_C(  119),  INT8_C(   90),  INT8_C(  103),
         INT8_C(   63),  INT8_C(   27),  INT8_C(   71),  INT8_C(   69),
         INT8_C(   58),  INT8_C(   11), -INT8_C(   68), -INT8_C(   36) },
      {  INT8_C(   96),  INT8_C(   87), -INT8_C(   47),  INT8_C(  101),
         INT8_C(  117),  INT8_C(  119),  INT8_C(   90),  INT8_C(  103),
        -INT8_C(   71),  INT8_C(   27),  INT8_C(   71),  INT8_C(   69),
         INT8_C(   88),  INT8_C(   11), -INT8_C(   68), -INT8_C(   36) },
      {  INT8_C(   96),  INT8_C(   87), -INT8_C(   47),  INT8_C(  101),
         INT8_C(  117),  INT8_C(  119),  INT8_C(   90),  INT8_C(  103),
        -INT8_C(   71),  INT8_C(   27),  INT8_C(   71),  INT8_C(   69),
         INT8_C(   58),  INT8_C(   11), -INT8_C(   68),  INT8_C(   92) } },
    { {  INT8_C(  111), -INT8_C(   99), -INT8_C(   23),  INT8_C(  126),
         INT8_C(   72),  INT8_C(   23),  INT8_C(   57),  INT8_C(   61),
        -INT8_C(   14),  INT8_C(   97), -INT8_C(   98), -INT8_C(   84),
        -INT8_C(   80), -INT8_C(   79),  INT8_C(   93), -INT8_C(   38) },
      {  INT8_C(   73),  INT8_C(  117),  INT8_C(  112),  INT8_C(   26),
         INT8_C(   55), -INT8_C(   15),  INT8_C(   28), -INT8_C(   61) },
      { -INT8_C(   61), -INT8_C(   99), -INT8_C(   23),  INT8_C(  126),
         INT8_C(   72),  INT8_C(   23),  INT8_C(   57),  INT8_C(   61),
        -INT8_C(   14),  INT8_C(   97), -INT8_C(   98), -INT8_C(   84),
        -INT8_C(   80), -INT8_C(   79),  INT8_C(   93), -INT8_C(   38) },
      {  INT8_C(  111), -INT8_C(   99), -INT8_C(   23),  INT8_C(  126),
         INT8_C(   28),  INT8_C(   23),  INT8_C(   57),  INT8_C(   61),
        -INT8_C(   14),  INT8_C(   97), -INT8_C(   98), -INT8_C(   84),
        -INT8_C(   80), -INT8_C(   79),  INT8_C(   93), -INT8_C(   38) },
      {  INT8_C(  111), -INT8_C(   99), -INT8_C(   23),  INT8_C(  126),
         INT8_C(   72),  INT8_C(   23),  INT8_C(   57),  INT8_C(   61),
         INT8_C(   55),  INT8_C(   97), -INT8_C(   98), -INT8_C(   84),
        -INT8_C(   80), -INT8_C(   79),  INT8_C(   93), -INT8_C(   38) },
      {  INT8_C(  111), -INT8_C(   99), -INT8_C(   23),  INT8_C(  126),
         INT8_C(   72),  INT8_C(   23),  INT8_C(   57),  INT8_C(   61),
        -INT8_C(   14),  INT8_C(   97), -INT8_C(   98), -INT8_C(   84),
         INT8_C(   26), -INT8_C(   79),  INT8_C(   93), -INT8_C(   38) },
      {  INT8_C(  111), -INT8_C(   99), -INT8_C(   23),  INT8_C(  126),
         INT8_C(   72),  INT8_C(   23),  INT8_C(   57),  INT8_C(   61),
        -INT8_C(   14),  INT8_C(   97), -INT8_C(   98), -INT8_C(   84),
        -INT8_C(   80), -INT8_C(   79),  INT8_C(   93),  INT8_C(  117) } },
    { { -INT8_C(  105),  INT8_C(  101), -INT8_C(   89), -INT8_C(   90),
         INT8_C(  121), -INT8_C(   68),  INT8_C(    2), -INT8_C(    4),
        -INT8_C(   85),  INT8_C(   63), -INT8_C(   15), -INT8_C(   29),
         INT8_C(   77),  INT8_C(  121), -INT8_C(   66),  INT8_C(   74) },
      {  INT8_C(   71), -INT8_C(   82),  INT8_C(   94),  INT8_C(  107),
         INT8_C(   33),  INT8_C(  106), -INT8_C(   96), -INT8_C(   85) },
      { -INT8_C(   85),  INT8_C(  101), -INT8_C(   89), -INT8_C(   90),
         INT8_C(  121), -INT8_C(   68),  INT8_C(    2), -INT8_C(    4),
        -INT8_C(   85),  INT8_C(   63), -INT8_C(   15), -INT8_C(   29),
         INT8_C(   77),  INT8_C(  121), -INT8_C(   66),  INT8_C(   74) },
      { -INT8_C(  105),  INT8_C(  101), -INT8_C(   89), -INT8_C(   90),
        -INT8_C(   96), -INT8_C(   68),  INT8_C(    2), -INT8_C(    4),
        -INT8_C(   85),  INT8_C(   63), -INT8_C(   15), -INT8_C(   29),
         INT8_C(   77),  INT8_C(  121), -INT8_C(   66),  INT8_C(   74) },
      { -INT8_C(  105),  INT8_C(  101), -INT8_C(   89), -INT8_C(   90),
         INT8_C(  121), -INT8_C(   68),  INT8_C(    2), -INT8_C(    4),
         INT8_C(   33),  INT8_C(   63), -INT8_C(   15), -INT8_C(   29),
         INT8_C(   77),  INT8_C(  121), -INT8_C(   66),  INT8_C(   74) },
      { -INT8_C(  105),  INT8_C(  101), -INT8_C(   89), -INT8_C(   90),
         INT8_C(  121), -INT8_C(   68),  INT8_C(    2), -INT8_C(    4),
        -INT8_C(   85),  INT8_C(   63), -INT8_C(   15), -INT8_C(   29),
         INT8_C(  107),  INT8_C(  121), -INT8_C(   66),  INT8_C(   74) },
      { -INT8_C(  105),  INT8_C(  101), -INT8_C(   89), -INT8_C(   90),
         INT8_C(  121), -INT8_C(   68),  INT8_C(    2), -INT8_C(    4),
        -INT8_C(   85),  INT8_C(   63), -INT8_C(   15), -INT8_C(   29),
         INT8_C(   77),  INT8_C(  121), -INT8_C(   66), -INT8_C(   82) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);

    simde_int8x16_t r0_7 = simde_vcopyq_lane_s8(a, 0, b, 7);
    simde_int8x16_t r4_6 = simde_vcopyq_lane_s8(a, 4, b, 6);
    simde_int8x16_t r8_4 = simde_vcopyq_lane_s8(a, 8, b, 4);
    simde_int8x16_t r12_3 = simde_vcopyq_lane_s8(a, 12, b, 3);
    simde_int8x16_t r15_1 = simde_vcopyq_lane_s8(a, 15, b, 1);

    simde_test_arm_neon_assert_equal_i8x16(r0_7, simde_vld1q_s8(test_vec[i].r0_7));
    simde_test_arm_neon_assert_equal_i8x16(r4_6, simde_vld1q_s8(test_vec[i].r4_6));
    simde_test_arm_neon_assert_equal_i8x16(r8_4, simde_vld1q_s8(test_vec[i].r8_4));
    simde_test_arm_neon_assert_equal_i8x16(r12_3, simde_vld1q_s8(test_vec[i].r12_3));
    simde_test_arm_neon_assert_equal_i8x16(r15_1, simde_vld1q_s8(test_vec[i].r15_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x16_t r0_7 = simde_vcopyq_lane_s8(a, 0, b, 7);
    simde_int8x16_t r4_6 = simde_vcopyq_lane_s8(a, 4, b, 6);
    simde_int8x16_t r8_4 = simde_vcopyq_lane_s8(a, 8, b, 4);
    simde_int8x16_t r12_3 = simde_vcopyq_lane_s8(a, 12, b, 3);
    simde_int8x16_t r15_1 = simde_vcopyq_lane_s8(a, 15, b, 1);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r0_7, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r4_6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r8_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r12_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r15_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[4];
    int16_t r0_3[8];
    int16_t r3_2[8];
    int16_t r5_1[8];
    int16_t r7_0[8];
  } test_vec[] = {
    { {  INT16_C(   27029),  INT16_C(   26579),  INT16_C(   28585),  INT16_C(   25552),
         INT16_C(   16551), -INT16_C(    7338),  INT16_C(   19387),  INT16_C(   12129) },
      { -INT16_C(   17263),  INT16_C(   17994),  INT16_C(   21673),  INT16_C(   26674) },
      {  INT16_C(   26674),  INT16_C(   26579),  INT16_C(   28585),  INT16_C(   25552),
         INT16_C(   16551), -INT16_C(    7338),  INT16_C(   19387),  INT16_C(   12129) },
      {  INT16_C(   27029),  INT16_C(   26579),  INT16_C(   28585),  INT16_C(   21673),
         INT16_C(   16551), -INT16_C(    7338),  INT16_C(   19387),  INT16_C(   12129) },
      {  INT16_C(   27029),  INT16_C(   26579),  INT16_C(   28585),  INT16_C(   25552),
         INT16_C(   16551),  INT16_C(   17994),  INT16_C(   19387),  INT16_C(   12129) },
      {  INT16_C(   27029),  INT16_C(   26579),  INT16_C(   28585),  INT16_C(   25552),
         INT16_C(   16551), -INT16_C(    7338),  INT16_C(   19387), -INT16_C(   17263) } },
    { {  INT16_C(   22253), -INT16_C(   22260),  INT16_C(   32244), -INT16_C(   26177),
        -INT16_C(    8811),  INT16_C(   15417),  INT16_C(    5213), -INT16_C(   28635) },
      { -INT16_C(    7193), -INT16_C(   30400), -INT16_C(   17625), -INT16_C(   25516) },
      { -INT16_C(   25516), -INT16_C(   22260),  INT16_C(   32244), -INT16_C(   26177),
        -INT16_C(    8811),  INT16_C(   15417),  INT16_C(    5213), -INT16_C(   28635) },
      {  INT16_C(   22253), -INT16_C(   22260),  INT16_C(   32244), -INT16_C(   17625),
        -INT16_C(    8811),  INT16_C(   15417),  INT16_C(    5213), -INT16_C(   28635) },
      {  INT16_C(   22253), -INT16_C(   22260),  INT16_C(   32244), -INT16_C(   26177),
        -INT16_C(    8811), -INT16_C(   30400),  INT16_C(    5213), -INT16_C(   28635) },
      {  INT16_C(   22253), -INT16_C(   22260),  INT16_C(   32244), -INT16_C(   26177),
        -INT16_C(    8811),  INT16_C(   15417),  INT16_C(    5213), -INT16_C(    7193) } },
    { { -INT16_C(   23776),  INT16_C(    6518), -INT16_C(    6832), -INT16_C(   29422),
        -INT16_C(   28847), -INT16_C(   13217),  INT16_C(   31430), -INT16_C(    8848) },
      { -INT16_C(    3922),  INT16_C(   22802), -INT16_C(   16279), -INT16_C(   13177) },
      { -INT16_C(   13177),  INT16_C(    6518), -INT16_C(    6832), -INT16_C(   29422),
        -INT16_C(   28847), -INT16_C(   13217),  INT16_C(   31430), -INT16_C(    8848) },
      { -INT16_C(   23776),  INT16_C(    6518), -INT16_C(    6832), -INT16_C(   16279),
        -INT16_C(   28847), -INT16_C(   13217),  INT16_C(   31430), -INT16_C(    8848) },
      { -INT16_C(   23776),  INT16_C(    6518), -INT16_C(    6832), -INT16_C(   29422),
        -INT16_C(   28847),  INT16_C(   22802),  INT16_C(   31430), -INT16_C(    8848) },
      { -INT16_C(   23776),  INT16_C(    6518), -INT16_C(    6832), -INT16_C(   29422),
        -INT16_C(   28847), -INT16_C(   13217),  INT16_C(   31430), -INT16_C(    3922) } },
    { {  INT16_C(   25863),  INT16_C(   13259), -INT16_C(   30865),  INT16_C(   15801),
         INT16_C(   11683), -INT16_C(   16303),  INT16_C(   25175), -INT16_C(   21172) },
      {  INT16_C(   29037),  INT16_C(   28656),  INT16_C(    6282),  INT16_C(     198) },
      {  INT16_C(     198),  INT16_C(   13259), -INT16_C(   30865),  INT16_C(   15801),
         INT16_C(   11683), -INT16_C(   16303),  INT16_C(   25175), -INT16_C(   21172) },
      {  INT16_C(   25863),  INT16_C(   13259), -INT16_C(   30865),  INT16_C(    6282),
         INT16_C(   11683), -INT16_C(   16303),  INT16_C(   25175), -INT16_C(   21172) },
      {  INT16_C(   25863),  INT16_C(   13259), -INT16_C(   30865),  INT16_C(   15801),
         INT16_C(   11683),  INT16_C(   28656),  INT16_C(   25175), -INT16_C(   21172) },
      {  INT16_C(   25863),  INT16_C(   13259), -INT16_C(   30865),  INT16_C(   15801),
         INT16_C(   11683), -INT16_C(   16303),  INT16_C(   25175),  INT16_C(   29037) } },
    { { -INT16_C(   30988),  INT16_C(   27521), -INT16_C(    7197), -INT16_C(   13039),
        -INT16_C(   14170), -INT16_C(    2528), -INT16_C(   15234),  INT16_C(   13381) },
      { -INT16_C(   32112),  INT16_C(   31755), -INT16_C(   27872),  INT16_C(   13351) },
      {  INT16_C(   13351),  INT16_C(   27521), -INT16_C(    7197), -INT16_C(   13039),
        -INT16_C(   14170), -INT16_C(    2528), -INT16_C(   15234),  INT16_C(   13381) },
      { -INT16_C(   30988),  INT16_C(   27521), -INT16_C(    7197), -INT16_C(   27872),
        -INT16_C(   14170), -INT16_C(    2528), -INT16_C(   15234),  INT16_C(   13381) },
      { -INT16_C(   30988),  INT16_C(   27521), -INT16_C(    7197), -INT16_C(   13039),
        -INT16_C(   14170),  INT16_C(   31755), -INT16_C(   15234),  INT16_C(   13381) },
      { -INT16_C(   30988),  INT16_C(   27521), -INT16_C(    7197), -INT16_C(   13039),
        -INT16_C(   14170), -INT16_C(    2528), -INT16_C(   15234), -INT16_C(   32112) } },
    { {  INT16_C(   29081), -INT16_C(    1225),  INT16_C(   17138),  INT16_C(   12210),
        -INT16_C(   17247),  INT16_C(    2087), -INT16_C(    3722), -INT16_C(   22560) },
      {  INT16_C(    2458), -INT16_C(    5128),  INT16_C(   20732),  INT16_C(    3292) },
      {  INT16_C(    3292), -INT16_C(    1225),  INT16_C(   17138),  INT16_C(   12210),
        -INT16_C(   17247),  INT16_C(    2087), -INT16_C(    3722), -INT16_C(   22560) },
      {  INT16_C(   29081), -INT16_C(    1225),  INT16_C(   17138),  INT16_C(   20732),
        -INT16_C(   17247),  INT16_C(    2087), -INT16_C(    3722), -INT16_C(   22560) },
      {  INT16_C(   29081), -INT16_C(    1225),  INT16_C(   17138),  INT16_C(   12210),
        -INT16_C(   17247), -INT16_C(    5128), -INT16_C(    3722), -INT16_C(   22560) },
      {  INT16_C(   29081), -INT16_C(    1225),  INT16_C(   17138),  INT16_C(   12210),
        -INT16_C(   17247),  INT16_C(    2087), -INT16_C(    3722),  INT16_C(    2458) } },
    { { -INT16_C(   25013), -INT16_C(   19961), -INT16_C(   18606),  INT16_C(   11403),
        -INT16_C(   24211), -INT16_C(   32295),  INT16_C(   11289),  INT16_C(    2644) },
      { -INT16_C(   24926),  INT16_C(   13396),  INT16_C(   13926), -INT16_C(   15521) },
      { -INT16_C(   15521), -INT16_C(   19961), -INT16_C(   18606),  INT16_C(   11403),
        -INT16_C(   24211), -INT16_C(   32295),  INT16_C(   11289),  INT16_C(    2644) },
      { -INT16_C(   25013), -INT16_C(   19961), -INT16_C(   18606),  INT16_C(   13926),
        -INT16_C(   24211), -INT16_C(   32295),  INT16_C(   11289),  INT16_C(    2644) },
      { -INT16_C(   25013), -INT16_C(   19961), -INT16_C(   18606),  INT16_C(   11403),
        -INT16_C(   24211),  INT16_C(   13396),  INT16_C(   11289),  INT16_C(    2644) },
      { -INT16_C(   25013), -INT16_C(   19961), -INT16_C(   18606),  INT16_C(   11403),
        -INT16_C(   24211), -INT16_C(   32295),  INT16_C(   11289), -INT16_C(   24926) } },
    { {  INT16_C(   28225), -INT16_C(   13641),  INT16_C(   12137), -INT16_C(    2051),
        -INT16_C(   24470), -INT16_C(    8376),  INT16_C(   22272),  INT16_C(   20450) },
      {  INT16_C(   31393), -INT16_C(   20326),  INT16_C(   23241),  INT16_C(   19500) },
      {  INT16_C(   19500), -INT16_C(   13641),  INT16_C(   12137), -INT16_C(    2051),
        -INT16_C(   24470), -INT16_C(    8376),  INT16_C(   22272),  INT16_C(   20450) },
      {  INT16_C(   28225), -INT16_C(   13641),  INT16_C(   12137),  INT16_C(   23241),
        -INT16_C(   24470), -INT16_C(    8376),  INT16_C(   22272),  INT16_C(   20450) },
      {  INT16_C(   28225), -INT16_C(   13641),  INT16_C(   12137), -INT16_C(    2051),
        -INT16_C(   24470), -INT16_C(   20326),  INT16_C(   22272),  INT16_C(   20450) },
      {  INT16_C(   28225), -INT16_C(   13641),  INT16_C(   12137), -INT16_C(    2051),
        -INT16_C(   24470), -INT16_C(    8376),  INT16_C(   22272),  INT16_C(   31393) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x8_t r0_3 = simde_vcopyq_lane_s16(a, 0, b, 3);
    simde_int16x8_t r3_2 = simde_vcopyq_lane_s16(a, 3, b, 2);
    simde_int16x8_t r5_1 = simde_vcopyq_lane_s16(a, 5, b, 1);
    simde_int16x8_t r7_0 = simde_vcopyq_lane_s16(a, 7, b, 0);

    simde_test_arm_neon_assert_equal_i16x8(r0_3, simde_vld1q_s16(test_vec[i].r0_3));
    simde_test_arm_neon_assert_equal_i16x8(r3_2, simde_vld1q_s16(test_vec[i].r3_2));
    simde_test_arm_neon_assert_equal_i16x8(r5_1, simde_vld1q_s16(test_vec[i].r5_1));
    simde_test_arm_neon_assert_equal_i16x8(r7_0, simde_vld1q_s16(test_vec[i].r7_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t r0_3 = simde_vcopyq_lane_s16(a, 0, b, 3);
    simde_int16x8_t r3_2 = simde_vcopyq_lane_s16(a, 3, b, 2);
    simde_int16x8_t r5_1 = simde_vcopyq_lane_s16(a, 5, b, 1);
    simde_int16x8_t r7_0 = simde_vcopyq_lane_s16(a, 7, b, 0);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r0_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r5_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r7_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[2];
    int32_t r0_1[4];
    int32_t r1_0[4];
    int32_t r2_1[4];
    int32_t r3_0[4];
  } test_vec[] = {
    { { -INT32_C(  1076912012),  INT32_C(   618068284),  INT32_C(  1042680298), -INT32_C(  1284688742) },
      { -INT32_C(  1538444613), -INT32_C(  1251735563) },
      { -INT32_C(  1251735563),  INT32_C(   618068284),  INT32_C(  1042680298), -INT32_C(  1284688742) },
      { -INT32_C(  1076912012), -INT32_C(  1538444613),  INT32_C(  1042680298), -INT32_C(  1284688742) },
      { -INT32_C(  1076912012),  INT32_C(   618068284), -INT32_C(  1251735563), -INT32_C(  1284688742) },
      { -INT32_C(  1076912012),  INT32_C(   618068284),  INT32_C(  1042680298), -INT32_C(  1538444613) } },
    { {  INT32_C(  2026659719), -INT32_C(  1368393889),  INT32_C(   964220746), -INT32_C(  2040877007) },
      {  INT32_C(   557196735), -INT32_C(  1587131242) },
      { -INT32_C(  1587131242), -INT32_C(  1368393889),  INT32_C(   964220746), -INT32_C(  2040877007) },
      {  INT32_C(  2026659719),  INT32_C(   557196735),  INT32_C(   964220746), -INT32_C(  2040877007) },
      {  INT32_C(  2026659719), -INT32_C(  1368393889), -INT32_C(  1587131242), -INT32_C(  2040877007) },
      {  INT32_C(  2026659719), -INT32_C(  1368393889),  INT32_C(   964220746),  INT32_C(   557196735) } },
    { { -INT32_C(  1558714266), -INT32_C(  1474286938),  INT32_C(  2027944758), -INT32_C(   237725764) },
      { -INT32_C(   611299852),  INT32_C(  1233220441) },
      {  INT32_C(  1233220441), -INT32_C(  1474286938),  INT32_C(  2027944758), -INT32_C(   237725764) },
      { -INT32_C(  1558714266), -INT32_C(   611299852),  INT32_C(  2027944758), -INT32_C(   237725764) },
      { -INT32_C(  1558714266), -INT32_C(  1474286938),  INT32_C(  1233220441), -INT32_C(   237725764) },
      { -INT32_C(  1558714266), -INT32_C(  1474286938),  INT32_C(  2027944758), -INT32_C(   611299852) } },
    { {  INT32_C(   510883444),  INT32_C(    50993558),  INT32_C(   615538984), -INT32_C(  1925132709) },
      {  INT32_C(    17242711),  INT32_C(   560137033) },
      {  INT32_C(   560137033),  INT32_C(    50993558),  INT32_C(   615538984), -INT32_C(  1925132709) },
      {  INT32_C(   510883444),  INT32_C(    17242711),  INT32_C(   615538984), -INT32_C(  1925132709) },
      {  INT32_C(   510883444),  INT32_C(    50993558),  INT32_C(   560137033), -INT32_C(  1925132709) },
      {  INT32_C(   510883444),  INT32_C(    50993558),  INT32_C(   615538984),  INT32_C(    17242711) } },
    { {  INT32_C(  1386115226), -INT32_C(  1963224204),  INT32_C(   211420390), -INT32_C(  1694280984) },
      { -INT32_C(  1322169749),  INT32_C(   836919814) },
      {  INT32_C(   836919814), -INT32_C(  1963224204),  INT32_C(   211420390), -INT32_C(  1694280984) },
      {  INT32_C(  1386115226), -INT32_C(  1322169749),  INT32_C(   211420390), -INT32_C(  1694280984) },
      {  INT32_C(  1386115226), -INT32_C(  1963224204),  INT32_C(   836919814), -INT32_C(  1694280984) },
      {  INT32_C(  1386115226), -INT32_C(  1963224204),  INT32_C(   211420390), -INT32_C(  1322169749) } },
    { {  INT32_C(   958226031),  INT32_C(    93380822),  INT32_C(  1144688739), -INT32_C(   234382015) },
      {  INT32_C(  1749098987), -INT32_C(   179092004) },
      { -INT32_C(   179092004),  INT32_C(    93380822),  INT32_C(  1144688739), -INT32_C(   234382015) },
      {  INT32_C(   958226031),  INT32_C(  1749098987),  INT32_C(  1144688739), -INT32_C(   234382015) },
      {  INT32_C(   958226031),  INT32_C(    93380822), -INT32_C(   179092004), -INT32_C(   234382015) },
      {  INT32_C(   958226031),  INT32_C(    93380822),  INT32_C(  1144688739),  INT32_C(  1749098987) } },
    { { -INT32_C(   635952031), -INT32_C(  1377334988), -INT32_C(    22978719), -INT32_C(    34765681) },
      {  INT32_C(  1211106462), -INT32_C(    23115063) },
      { -INT32_C(    23115063), -INT32_C(  1377334988), -INT32_C(    22978719), -INT32_C(    34765681) },
      { -INT32_C(   635952031),  INT32_C(  1211106462), -INT32_C(    22978719), -INT32_C(    34765681) },
      { -INT32_C(   635952031), -INT32_C(  1377334988), -INT32_C(    23115063), -INT32_C(    34765681) },
      { -INT32_C(   635952031), -INT32_C(  1377334988), -INT32_C(    22978719),  INT32_C(  1211106462) } },
    { { -INT32_C(   701062361),  INT32_C(   166953805),  INT32_C(  1658614329), -INT32_C(   730083122) },
      { -INT32_C(  1322477008),  INT32_C(   858166047) },
      {  INT32_C(   858166047),  INT32_C(   166953805),  INT32_C(  1658614329), -INT32_C(   730083122) },
      { -INT32_C(   701062361), -INT32_C(  1322477008),  INT32_C(  1658614329), -INT32_C(   730083122) },
      { -INT32_C(   701062361),  INT32_C(   166953805),  INT32_C(   858166047), -INT32_C(   730083122) },
      { -INT32_C(   701062361),  INT32_C(   166953805),  INT32_C(  1658614329), -INT32_C(  1322477008) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x4_t r0_1 = simde_vcopyq_lane_s32(a, 0, b, 1);
    simde_int32x4_t r1_0 = simde_vcopyq_lane_s32(a, 1, b, 0);
    simde_int32x4_t r2_1 = simde_vcopyq_lane_s32(a, 2, b, 1);
    simde_int32x4_t r3_0 = simde_vcopyq_lane_s32(a, 3, b, 0);

    simde_test_arm_neon_assert_equal_i32x4(r0_1, simde_vld1q_s32(test_vec[i].r0_1));
    simde_test_arm_neon_assert_equal_i32x4(r1_0, simde_vld1q_s32(test_vec[i].r1_0));
    simde_test_arm_neon_assert_equal_i32x4(r2_1, simde_vld1q_s32(test_vec[i].r2_1));
    simde_test_arm_neon_assert_equal_i32x4(r3_0, simde_vld1q_s32(test_vec[i].r3_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t r0_1 = simde_vcopyq_lane_s32(a, 0, b, 1);
    simde_int32x4_t r1_0 = simde_vcopyq_lane_s32(a, 1, b, 0);
    simde_int32x4_t r2_1 = simde_vcopyq_lane_s32(a, 2, b, 1);
    simde_int32x4_t r3_0 = simde_vcopyq_lane_s32(a, 3, b, 0);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r0_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r1_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r2_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r3_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[1];
    int64_t r0_0[2];
    int64_t r1_0[2];
  } test_vec[] = {
    { {  INT64_C( 5923506011110482733), -INT64_C( 2645285737381901732) },
      { -INT64_C( 7834399894314585151) },
      { -INT64_C( 7834399894314585151), -INT64_C( 2645285737381901732) },
      {  INT64_C( 5923506011110482733), -INT64_C( 7834399894314585151) } },
    { { -INT64_C( 1016997391912317657),  INT64_C(  387471655083973654) },
      { -INT64_C( 2303427801483812271) },
      { -INT64_C( 2303427801483812271),  INT64_C(  387471655083973654) },
      { -INT64_C( 1016997391912317657), -INT64_C( 2303427801483812271) } },
    { {  INT64_C( 7341233720419624579),  INT64_C( 8440647527380018740) },
      {  INT64_C( 6296444952903933582) },
      {  INT64_C( 6296444952903933582),  INT64_C( 8440647527380018740) },
      {  INT64_C( 7341233720419624579),  INT64_C( 6296444952903933582) } },
    { { -INT64_C(  768202849149799049), -INT64_C( 4683657666914593469) },
      {  INT64_C( 5482397825823415064) },
      {  INT64_C( 5482397825823415064), -INT64_C( 4683657666914593469) },
      { -INT64_C(  768202849149799049),  INT64_C( 5482397825823415064) } },
    { {  INT64_C( 6276973598659071226),  INT64_C( 5439164051307246322) },
      {  INT64_C( 7898197828517044658) },
      {  INT64_C( 7898197828517044658),  INT64_C( 5439164051307246322) },
      {  INT64_C( 6276973598659071226),  INT64_C( 7898197828517044658) } },
    { { -INT64_C( 5573085121491680858),  INT64_C( 5680682011604371585) },
      { -INT64_C( 9149867884760669227) },
      { -INT64_C( 9149867884760669227),  INT64_C( 5680682011604371585) },
      { -INT64_C( 5573085121491680858), -INT64_C( 9149867884760669227) } },
    { {  INT64_C( 8622738552695243649), -INT64_C( 6638279232013153822) },
      { -INT64_C( 5812927542173415403) },
      { -INT64_C( 5812927542173415403), -INT64_C( 6638279232013153822) },
      {  INT64_C( 8622738552695243649), -INT64_C( 5812927542173415403) } },
    { { -INT64_C( 2025031443728201743),  INT64_C( 9148317493025265463) },
      {  INT64_C( 5207511157286457380) },
      {  INT64_C( 5207511157286457380),  INT64_C( 9148317493025265463) },
      { -INT64_C( 2025031443728201743),  INT64_C( 5207511157286457380) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);

    simde_int64x2_t r0_0 = simde_vcopyq_lane_s64(a, 0, b, 0);
    simde_int64x2_t r1_0 = simde_vcopyq_lane_s64(a, 1, b, 0);

    simde_test_arm_neon_assert_equal_i64x2(r0_0, simde_vld1q_s64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_i64x2(r1_0, simde_vld1q_s64(test_vec[i].r1_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x2_t r0_0 = simde_vcopyq_lane_s64(a, 0, b, 0);
    simde_int64x2_t r1_0 = simde_vcopyq_lane_s64(a, 1, b, 0);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r1_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[8];
    uint8_t r0_7[16];
    uint8_t r4_6[16];
    uint8_t r8_4[16];
    uint8_t r12_3[16];
    uint8_t r15_1[16];
  } test_vec[] = {
    { {  UINT8_C(    59),  UINT8_C(   146),  UINT8_C(    87),  UINT8_C(    29),
         UINT8_C(    78),  UINT8_C(    48),  UINT8_C(    79),  UINT8_C(   166),
         UINT8_C(    32),  UINT8_C(   121),  UINT8_C(   103),  UINT8_C(   178),
         UINT8_C(   206),  UINT8_C(    10),  UINT8_C(   184),  UINT8_C(   187) },
      {  UINT8_C(    70),  UINT8_C(   103),  UINT8_C(   193),  UINT8_C(    36),
         UINT8_C(    18),  UINT8_C(   128),  UINT8_C(   189),  UINT8_C(   208) },
      {  UINT8_C(   208),  UINT8_C(   146),  UINT8_C(    87),  UINT8_C(    29),
         UINT8_C(    78),  UINT8_C(    48),  UINT8_C(    79),  UINT8_C(   166),
         UINT8_C(    32),  UINT8_C(   121),  UINT8_C(   103),  UINT8_C(   178),
         UINT8_C(   206),  UINT8_C(    10),  UINT8_C(   184),  UINT8_C(   187) },
      {  UINT8_C(    59),  UINT8_C(   146),  UINT8_C(    87),  UINT8_C(    29),
         UINT8_C(   189),  UINT8_C(    48),  UINT8_C(    79),  UINT8_C(   166),
         UINT8_C(    32),  UINT8_C(   121),  UINT8_C(   103),  UINT8_C(   178),
         UINT8_C(   206),  UINT8_C(    10),  UINT8_C(   184),  UINT8_C(   187) },
      {  UINT8_C(    59),  UINT8_C(   146),  UINT8_C(    87),  UINT8_C(    29),
         UINT8_C(    78),  UINT8_C(    48),  UINT8_C(    79),  UINT8_C(   166),
         UINT8_C(    18),  UINT8_C(   121),  UINT8_C(   103),  UINT8_C(   178),
         UINT8_C(   206),  UINT8_C(    10),  UINT8_C(   184),  UINT8_C(   187) },
      {  UINT8_C(    59),  UINT8_C(   146),  UINT8_C(    87),  UINT8_C(    29),
         UINT8_C(    78),  UINT8_C(    48),  UINT8_C(    79),  UINT8_C(   166),
         UINT8_C(    32),  UINT8_C(   121),  UINT8_C(   103),  UINT8_C(   178),
         UINT8_C(    36),  UINT8_C(    10),  UINT8_C(   184),  UINT8_C(   187) },
      {  UINT8_C(    59),  UINT8_C(   146),  UINT8_C(    87),  UINT8_C(    29),
         UINT8_C(    78),  UINT8_C(    48),  UINT8_C(    79),  UINT8_C(   166),
         UINT8_C(    32),  UINT8_C(   121),  UINT8_C(   103),  UINT8_C(   178),
         UINT8_C(   206),  UINT8_C(    10),  UINT8_C(   184),  UINT8_C(   103) } },
    { {  UINT8_C(    91),  UINT8_C(   101),  UINT8_C(    84),  UINT8_C(    52),
         UINT8_C(    61),  UINT8_C(   205),  UINT8_C(    72),  UINT8_C(   179),
         UINT8_C(   111),  UINT8_C(   192),  UINT8_C(   117),  UINT8_C(   227),
         UINT8_C(   194),  UINT8_C(   125),  UINT8_C(    37),  UINT8_C(   129) },
      {  UINT8_C(   139),  UINT8_C(    50),  UINT8_C(   181),  UINT8_C(   157),
         UINT8_C(   169),  UINT8_C(   160),  UINT8_C(   180),  UINT8_C(   165) },
      {  UINT8_C(   165),  UINT8_C(   101),  UINT8_C(    84),  UINT8_C(    52),
         UINT8_C(    61),  UINT8_C(   205),  UINT8_C(    72),  UINT8_C(   179),
         UINT8_C(   111),  UINT8_C(   192),  UINT8_C(   117),  UINT8_C(   227),
         UINT8_C(   194),  UINT8_C(   125),  UINT8_C(    37),  UINT8_C(   129) },
      {  UINT8_C(    91),  UINT8_C(   101),  UINT8_C(    84),  UINT8_C(    52),
         UINT8_C(   180),  UINT8_C(   205),  UINT8_C(    72),  UINT8_C(   179),
         UINT8_C(   111),  UINT8_C(   192),  UINT8_C(   117),  UINT8_C(   227),
         UINT8_C(   194),  UINT8_C(   125),  UINT8_C(    37),  UINT8_C(   129) },
      {  UINT8_C(    91),  UINT8_C(   101),  UINT8_C(    84),  UINT8_C(    52),
         UINT8_C(    61),  UINT8_C(   205),  UINT8_C(    72),  UINT8_C(   179),
         UINT8_C(   169),  UINT8_C(   192),  UINT8_C(   117),  UINT8_C(   227),
         UINT8_C(   194),  UINT8_C(   125),  UINT8_C(    37),  UINT8_C(   129) },
      {  UINT8_C(    91),  UINT8_C(   101),  UINT8_C(    84),  UINT8_C(    52),
         UINT8_C(    61),  UINT8_C(   205),  UINT8_C(    72),  UINT8_C(   179),
         UINT8_C(   111),  UINT8_C(   192),  UINT8_C(   117),  UINT8_C(   227),
         UINT8_C(   157),  UINT8_C(   125),  UINT8_C(    37),  UINT8_C(   129) },
      {  UINT8_C(    91),  UINT8_C(   101),  UINT8_C(    84),  UINT8_C(    52),
         UINT8_C(    61),  UINT8_C(   205),  UINT8_C(    72),  UINT8_C(   179),
         UINT8_C(   111),  UINT8_C(   192),  UINT8_C(   117),  UINT8_C(   227),
         UINT8_C(   194),  UINT8_C(   125),  UINT8_C(    37),  UINT8_C(    50) } },
    { {  UINT8_C(   105),  UINT8_C(   235),  UINT8_C(   218),  UINT8_C(    67),
         UINT8_C(   196),  UINT8_C(   121),  UINT8_C(   249),  UINT8_C(   221),
         UINT8_C(   132),  UINT8_C(    75),  UINT8_C(   140),  UINT8_C(    45),
         UINT8_C(    16),  UINT8_C(    48),  UINT8_C(    49),  UINT8_C(   129) },
      {  UINT8_C(    43),  UINT8_C(   107),  UINT8_C(   122),  UINT8_C(   203),
         UINT8_C(    47),  UINT8_C(    15),  UINT8_C(   218),  UINT8_C(   173) },
      {  UINT8_C(   173),  UINT8_C(   235),  UINT8_C(   218),  UINT8_C(    67),
         UINT8_C(   196),  UINT8_C(   121),  UINT8_C(   249),  UINT8_C(   221),
         UINT8_C(   132),  UINT8_C(    75),  UINT8_C(   140),  UINT8_C(    45),
         UINT8_C(    16),  UINT8_C(    48),  UINT8_C(    49),  UINT8_C(   129) },
      {  UINT8_C(   105),  UINT8_C(   235),  UINT8_C(   218),  UINT8_C(    67),
         UINT8_C(   218),  UINT8_C(   121),  UINT8_C(   249),  UINT8_C(   221),
         UINT8_C(   132),  UINT8_C(    75),  UINT8_C(   140),  UINT8_C(    45),
         UINT8_C(    16),  UINT8_C(    48),  UINT8_C(    49),  UINT8_C(   129) },
      {  UINT8_C(   105),  UINT8_C(   235),  UINT8_C(   218),  UINT8_C(    67),
         UINT8_C(   196),  UINT8_C(   121),  UINT8_C(   249),  UINT8_C(   221),
         UINT8_C(    47),  UINT8_C(    75),  UINT8_C(   140),  UINT8_C(    45),
         UINT8_C(    16),  UINT8_C(    48),  UINT8_C(    49),  UINT8_C(   129) },
      {  UINT8_C(   105),  UINT8_C(   235),  UINT8_C(   218),  UINT8_C(    67),
         UINT8_C(   196),  UINT8_C(   121),  UINT8_C(   249),  UINT8_C(   221),
         UINT8_C(   132),  UINT8_C(    75),  UINT8_C(   140),  UINT8_C(    45),
         UINT8_C(   203),  UINT8_C(    48),  UINT8_C(    49),  UINT8_C(   129) },
      {  UINT8_C(   105),  UINT8_C(   235),  UINT8_C(   218),  UINT8_C(    67),
         UINT8_C(   196),  UINT8_C(   121),  UINT8_C(   249),  UINT8_C(   221),
         UINT8_C(   132),  UINT8_C(    75),  UINT8_C(   140),  UINT8_C(    45),
         UINT8_C(    16),  UINT8_C(    48),  UINT8_C(    49),  UINT8_C(   107) } },
    { {  UINT8_C(     7),  UINT8_C(    14),  UINT8_C(    69),  UINT8_C(   189),
         UINT8_C(   193),  UINT8_C(     0),  UINT8_C(   183),  UINT8_C(   117),
         UINT8_C(    61),  UINT8_C(   243),  UINT8_C(   125),  UINT8_C(   221),
         UINT8_C(   101),  UINT8_C(   249),  UINT8_C(   217),  UINT8_C(   254) },
      {  UINT8_C(    46),  UINT8_C(   151),  UINT8_C(   116),  UINT8_C(   149),
         UINT8_C(    92),  UINT8_C(    84),  UINT8_C(   239),  UINT8_C(   224) },
      {  UINT8_C(   224),  UINT8_C(    14),  UINT8_C(    69),  UINT8_C(   189),
         UINT8_C(   193),  UINT8_C(     0),  UINT8_C(   183),  UINT8_C(   117),
         UINT8_C(    61),  UINT8_C(   243),  UINT8_C(   125),  UINT8_C(   221),
         UINT8_C(   101),  UINT8_C(   249),  UINT8_C(   217),  UINT8_C(   254) },
      {  UINT8_C(     7),  UINT8_C(    14),  UINT8_C(    69),  UINT8_C(   189),
         UINT8_C(   239),  UINT8_C(     0),  UINT8_C(   183),  UINT8_C(   117),
         UINT8_C(    61),  UINT8_C(   243),  UINT8_C(   125),  UINT8_C(   221),
         UINT8_C(   101),  UINT8_C(   249),  UINT8_C(   217),  UINT8_C(   254) },
      {  UINT8_C(     7),  UINT8_C(    14),  UINT8_C(    69),  UINT8_C(   189),
         UINT8_C(   193),  UINT8_C(     0),  UINT8_C(   183),  UINT8_C(   117),
         UINT8_C(    92),  UINT8_C(   243),  UINT8_C(   125),  UINT8_C(   221),
         UINT8_C(   101),  UINT8_C(   249),  UINT8_C(   217),  UINT8_C(   254) },
      {  UINT8_C(     7),  UINT8_C(    14),  UINT8_C(    69),  UINT8_C(   189),
         UINT8_C(   193),  UINT8_C(     0),  UINT8_C(   183),  UINT8_C(   117),
         UINT8_C(    61),  UINT8_C(   243),  UINT8_C(   125),  UINT8_C(   221),
         UINT8_C(   149),  UINT8_C(   249),  UINT8_C(   217),  UINT8_C(   254) },
      {  UINT8_C(     7),  UINT8_C(    14),  UINT8_C(    69),  UINT8_C(   189),
         UINT8_C(   193),  UINT8_C(     0),  UINT8_C(   183),  UINT8_C(   117),
         UINT8_C(    61),  UINT8_C(   243),  UINT8_C(   125),  UINT8_C(   221),
         UINT8_C(   101),  UINT8_C(   249),  UINT8_C(   217),  UINT8_C(   151) } },
    { {  UINT8_C(   129),  UINT8_C(    32),  UINT8_C(   181),  UINT8_C(    85),
         UINT8_C(   235),  UINT8_C(   229),  UINT8_C(    36),  UINT8_C(   140),
         UINT8_C(   224),  UINT8_C(   213),  UINT8_C(   182),  UINT8_C(   144),
         UINT8_C(    39),  UINT8_C(    35),  UINT8_C(   204),  UINT8_C(   158) },
      {  UINT8_C(    61),  UINT8_C(   217),  UINT8_C(   158),  UINT8_C(    85),
         UINT8_C(    22),  UINT8_C(    54),  UINT8_C(    63),  UINT8_C(    57) },
      {  UINT8_C(    57),  UINT8_C(    32),  UINT8_C(   181),  UINT8_C(    85),
         UINT8_C(   235),  UINT8_C(   229),  UINT8_C(    36),  UINT8_C(   140),
         UINT8_C(   224),  UINT8_C(   213),  UINT8_C(   182),  UINT8_C(   144),
         UINT8_C(    39),  UINT8_C(    35),  UINT8_C(   204),  UINT8_C(   158) },
      {  UINT8_C(   129),  UINT8_C(    32),  UINT8_C(   181),  UINT8_C(    85),
         UINT8_C(    63),  UINT8_C(   229),  UINT8_C(    36),  UINT8_C(   140),
         UINT8_C(   224),  UINT8_C(   213),  UINT8_C(   182),  UINT8_C(   144),
         UINT8_C(    39),  UINT8_C(    35),  UINT8_C(   204),  UINT8_C(   158) },
      {  UINT8_C(   129),  UINT8_C(    32),  UINT8_C(   181),  UINT8_C(    85),
         UINT8_C(   235),  UINT8_C(   229),  UINT8_C(    36),  UINT8_C(   140),
         UINT8_C(    22),  UINT8_C(   213),  UINT8_C(   182),  UINT8_C(   144),
         UINT8_C(    39),  UINT8_C(    35),  UINT8_C(   204),  UINT8_C(   158) },
      {  UINT8_C(   129),  UINT8_C(    32),  UINT8_C(   181),  UINT8_C(    85),
         UINT8_C(   235),  UINT8_C(   229),  UINT8_C(    36),  UINT8_C(   140),
         UINT8_C(   224),  UINT8_C(   213),  UINT8_C(   182),  UINT8_C(   144),
         UINT8_C(    85),  UINT8_C(    35),  UINT8_C(   204),  UINT8_C(   158) },
      {  UINT8_C(   129),  UINT8_C(    32),  UINT8_C(   181),  UINT8_C(    85),
         UINT8_C(   235),  UINT8_C(   229),  UINT8_C(    36),  UINT8_C(   140),
         UINT8_C(   224),  UINT8_C(   213),  UINT8_C(   182),  UINT8_C(   144),
         UINT8_C(    39),  UINT8_C(    35),  UINT8_C(   204),  UINT8_C(   217) } },
    { {  UINT8_C(    42),  UINT8_C(    33),  UINT8_C(   152),  UINT8_C(   160),
         UINT8_C(   201),  UINT8_C(    17),  UINT8_C(   113),  UINT8_C(    21),
         UINT8_C(   152),  UINT8_C(    89),  UINT8_C(   243),  UINT8_C(   109),
         UINT8_C(   248),  UINT8_C(    92),  UINT8_C(   158),  UINT8_C(   137) },
      {  UINT8_C(   101),  UINT8_C(   207),  UINT8_C(   250),  UINT8_C(   139),
         UINT8_C(   236),  UINT8_C(    39),  UINT8_C(   230),  UINT8_C(   206) },
      {  UINT8_C(   206),  UINT8_C(    33),  UINT8_C(   152),  UINT8_C(   160),
         UINT8_C(   201),  UINT8_C(    17),  UINT8_C(   113),  UINT8_C(    21),
         UINT8_C(   152),  UINT8_C(    89),  UINT8_C(   243),  UINT8_C(   109),
         UINT8_C(   248),  UINT8_C(    92),  UINT8_C(   158),  UINT8_C(   137) },
      {  UINT8_C(    42),  UINT8_C(    33),  UINT8_C(   152),  UINT8_C(   160),
         UINT8_C(   230),  UINT8_C(    17),  UINT8_C(   113),  UINT8_C(    21),
         UINT8_C(   152),  UINT8_C(    89),  UINT8_C(   243),  UINT8_C(   109),
         UINT8_C(   248),  UINT8_C(    92),  UINT8_C(   158),  UINT8_C(   137) },
      {  UINT8_C(    42),  UINT8_C(    33),  UINT8_C(   152),  UINT8_C(   160),
         UINT8_C(   201),  UINT8_C(    17),  UINT8_C(   113),  UINT8_C(    21),
         UINT8_C(   236),  UINT8_C(    89),  UINT8_C(   243),  UINT8_C(   109),
         UINT8_C(   248),  UINT8_C(    92),  UINT8_C(   158),  UINT8_C(   137) },
      {  UINT8_C(    42),  UINT8_C(    33),  UINT8_C(   152),  UINT8_C(   160),
         UINT8_C(   201),  UINT8_C(    17),  UINT8_C(   113),  UINT8_C(    21),
         UINT8_C(   152),  UINT8_C(    89),  UINT8_C(   243),  UINT8_C(   109),
         UINT8_C(   139),  UINT8_C(    92),  UINT8_C(   158),  UINT8_C(   137) },
      {  UINT8_C(    42),  UINT8_C(    33),  UINT8_C(   152),  UINT8_C(   160),
         UINT8_C(   201),  UINT8_C(    17),  UINT8_C(   113),  UINT8_C(    21),
         UINT8_C(   152),  UINT8_C(    89),  UINT8_C(   243),  UINT8_C(   109),
         UINT8_C(   248),  UINT8_C(    92),  UINT8_C(   158),  UINT8_C(   207) } },
    { {  UINT8_C(    14),  UINT8_C(     0),  UINT8_C(   142),  UINT8_C(   110),
         UINT8_C(   120),  UINT8_C(    86),  UINT8_C(   235),  UINT8_C(    19),
         UINT8_C(    79),  UINT8_C(   222),  UINT8_C(    38),  UINT8_C(    88),
         UINT8_C(   118),  UINT8_C(    99),  UINT8_C(   223),  UINT8_C(   239) },
      {  UINT8_C(    87),  UINT8_C(   213),  UINT8_C(    68),  UINT8_C(   244),
         UINT8_C(    30),  UINT8_C(   172),  UINT8_C(     2),  UINT8_C(   136) },
      {  UINT8_C(   136),  UINT8_C(     0),  UINT8_C(   142),  UINT8_C(   110),
         UINT8_C(   120),  UINT8_C(    86),  UINT8_C(   235),  UINT8_C(    19),
         UINT8_C(    79),  UINT8_C(   222),  UINT8_C(    38),  UINT8_C(    88),
         UINT8_C(   118),  UINT8_C(    99),  UINT8_C(   223),  UINT8_C(   239) },
      {  UINT8_C(    14),  UINT8_C(     0),  UINT8_C(   142),  UINT8_C(   110),
         UINT8_C(     2),  UINT8_C(    86),  UINT8_C(   235),  UINT8_C(    19),
         UINT8_C(    79),  UINT8_C(   222),  UINT8_C(    38),  UINT8_C(    88),
         UINT8_C(   118),  UINT8_C(    99),  UINT8_C(   223),  UINT8_C(   239) },
      {  UINT8_C(    14),  UINT8_C(     0),  UINT8_C(   142),  UINT8_C(   110),
         UINT8_C(   120),  UINT8_C(    86),  UINT8_C(   235),  UINT8_C(    19),
         UINT8_C(    30),  UINT8_C(   222),  UINT8_C(    38),  UINT8_C(    88),
         UINT8_C(   118),  UINT8_C(    99),  UINT8_C(   223),  UINT8_C(   239) },
      {  UINT8_C(    14),  UINT8_C(     0),  UINT8_C(   142),  UINT8_C(   110),
         UINT8_C(   120),  UINT8_C(    86),  UINT8_C(   235),  UINT8_C(    19),
         UINT8_C(    79),  UINT8_C(   222),  UINT8_C(    38),  UINT8_C(    88),
         UINT8_C(   244),  UINT8_C(    99),  UINT8_C(   223),  UINT8_C(   239) },
      {  UINT8_C(    14),  UINT8_C(     0),  UINT8_C(   142),  UINT8_C(   110),
         UINT8_C(   120),  UINT8_C(    86),  UINT8_C(   235),  UINT8_C(    19),
         UINT8_C(    79),  UINT8_C(   222),  UINT8_C(    38),  UINT8_C(    88),
         UINT8_C(   118),  UINT8_C(    99),  UINT8_C(   223),  UINT8_C(   213) } },
    { {  UINT8_C(   155),  UINT8_C(   176),  UINT8_C(   228),  UINT8_C(    41),
         UINT8_C(   114),  UINT8_C(    45),  UINT8_C(   120),  UINT8_C(    68),
         UINT8_C(   185),  UINT8_C(   174),  UINT8_C(   129),  UINT8_C(    46),
         UINT8_C(    81),  UINT8_C(   187),  UINT8_C(     3),  UINT8_C(   123) },
      {  UINT8_C(   151),  UINT8_C(    65),  UINT8_C(    26),  UINT8_C(     1),
         UINT8_C(   212),  UINT8_C(   113),  UINT8_C(    67),  UINT8_C(    18) },
      {  UINT8_C(    18),  UINT8_C(   176),  UINT8_C(   228),  UINT8_C(    41),
         UINT8_C(   114),  UINT8_C(    45),  UINT8_C(   120),  UINT8_C(    68),
         UINT8_C(   185),  UINT8_C(   174),  UINT8_C(   129),  UINT8_C(    46),
         UINT8_C(    81),  UINT8_C(   187),  UINT8_C(     3),  UINT8_C(   123) },
      {  UINT8_C(   155),  UINT8_C(   176),  UINT8_C(   228),  UINT8_C(    41),
         UINT8_C(    67),  UINT8_C(    45),  UINT8_C(   120),  UINT8_C(    68),
         UINT8_C(   185),  UINT8_C(   174),  UINT8_C(   129),  UINT8_C(    46),
         UINT8_C(    81),  UINT8_C(   187),  UINT8_C(     3),  UINT8_C(   123) },
      {  UINT8_C(   155),  UINT8_C(   176),  UINT8_C(   228),  UINT8_C(    41),
         UINT8_C(   114),  UINT8_C(    45),  UINT8_C(   120),  UINT8_C(    68),
         UINT8_C(   212),  UINT8_C(   174),  UINT8_C(   129),  UINT8_C(    46),
         UINT8_C(    81),  UINT8_C(   187),  UINT8_C(     3),  UINT8_C(   123) },
      {  UINT8_C(   155),  UINT8_C(   176),  UINT8_C(   228),  UINT8_C(    41),
         UINT8_C(   114),  UINT8_C(    45),  UINT8_C(   120),  UINT8_C(    68),
         UINT8_C(   185),  UINT8_C(   174),  UINT8_C(   129),  UINT8_C(    46),
         UINT8_C(     1),  UINT8_C(   187),  UINT8_C(     3),  UINT8_C(   123) },
      {  UINT8_C(   155),  UINT8_C(   176),  UINT8_C(   228),  UINT8_C(    41),
         UINT8_C(   114),  UINT8_C(    45),  UINT8_C(   120),  UINT8_C(    68),
         UINT8_C(   185),  UINT8_C(   174),  UINT8_C(   129),  UINT8_C(    46),
         UINT8_C(    81),  UINT8_C(   187),  UINT8_C(     3),  UINT8_C(    65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);

    simde_uint8x16_t r0_7 = simde_vcopyq_lane_u8(a, 0, b, 7);
    simde_uint8x16_t r4_6 = simde_vcopyq_lane_u8(a, 4, b, 6);
    simde_uint8x16_t r8_4 = simde_vcopyq_lane_u8(a, 8, b, 4);
    simde_uint8x16_t r12_3 = simde_vcopyq_lane_u8(a, 12, b, 3);
    simde_uint8x16_t r15_1 = simde_vcopyq_lane_u8(a, 15, b, 1);

    simde_test_arm_neon_assert_equal_u8x16(r0_7, simde_vld1q_u8(test_vec[i].r0_7));
    simde_test_arm_neon_assert_equal_u8x16(r4_6, simde_vld1q_u8(test_vec[i].r4_6));
    simde_test_arm_neon_assert_equal_u8x16(r8_4, simde_vld1q_u8(test_vec[i].r8_4));
    simde_test_arm_neon_assert_equal_u8x16(r12_3, simde_vld1q_u8(test_vec[i].r12_3));
    simde_test_arm_neon_assert_equal_u8x16(r15_1, simde_vld1q_u8(test_vec[i].r15_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x16_t r0_7 = simde_vcopyq_lane_u8(a, 0, b, 7);
    simde_uint8x16_t r4_6 = simde_vcopyq_lane_u8(a, 4, b, 6);
    simde_uint8x16_t r8_4 = simde_vcopyq_lane_u8(a, 8, b, 4);
    simde_uint8x16_t r12_3 = simde_vcopyq_lane_u8(a, 12, b, 3);
    simde_uint8x16_t r15_1 = simde_vcopyq_lane_u8(a, 15, b, 1);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r0_7, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r4_6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r8_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r12_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r15_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[4];
    uint16_t r0_3[8];
    uint16_t r3_2[8];
    uint16_t r5_1[8];
    uint16_t r7_0[8];
  } test_vec[] = {
    { {  UINT16_C(   45106),  UINT16_C(   38241),  UINT16_C(    4836),  UINT16_C(   40111),
         UINT16_C(   37552),  UINT16_C(   53688),  UINT16_C(   17469),  UINT16_C(   24387) },
      {  UINT16_C(   47087),  UINT16_C(   53333),  UINT16_C(   17428),  UINT16_C(   45727) },
      {  UINT16_C(   45727),  UINT16_C(   38241),  UINT16_C(    4836),  UINT16_C(   40111),
         UINT16_C(   37552),  UINT16_C(   53688),  UINT16_C(   17469),  UINT16_C(   24387) },
      {  UINT16_C(   45106),  UINT16_C(   38241),  UINT16_C(    4836),  UINT16_C(   17428),
         UINT16_C(   37552),  UINT16_C(   53688),  UINT16_C(   17469),  UINT16_C(   24387) },
      {  UINT16_C(   45106),  UINT16_C(   38241),  UINT16_C(    4836),  UINT16_C(   40111),
         UINT16_C(   37552),  UINT16_C(   53333),  UINT16_C(   17469),  UINT16_C(   24387) },
      {  UINT16_C(   45106),  UINT16_C(   38241),  UINT16_C(    4836),  UINT16_C(   40111),
         UINT16_C(   37552),  UINT16_C(   53688),  UINT16_C(   17469),  UINT16_C(   47087) } },
    { {  UINT16_C(    5206),  UINT16_C(   60332),  UINT16_C(   40277),  UINT16_C(   19674),
         UINT16_C(    6622),  UINT16_C(   38757),  UINT16_C(   64251),  UINT16_C(   47386) },
      {  UINT16_C(    8478),  UINT16_C(    4749),  UINT16_C(   53363),  UINT16_C(   29869) },
      {  UINT16_C(   29869),  UINT16_C(   60332),  UINT16_C(   40277),  UINT16_C(   19674),
         UINT16_C(    6622),  UINT16_C(   38757),  UINT16_C(   64251),  UINT16_C(   47386) },
      {  UINT16_C(    5206),  UINT16_C(   60332),  UINT16_C(   40277),  UINT16_C(   53363),
         UINT16_C(    6622),  UINT16_C(   38757),  UINT16_C(   64251),  UINT16_C(   47386) },
      {  UINT16_C(    5206),  UINT16_C(   60332),  UINT16_C(   40277),  UINT16_C(   19674),
         UINT16_C(    6622),  UINT16_C(    4749),  UINT16_C(   64251),  UINT16_C(   47386) },
      {  UINT16_C(    5206),  UINT16_C(   60332),  UINT16_C(   40277),  UINT16_C(   19674),
         UINT16_C(    6622),  UINT16_C(   38757),  UINT16_C(   64251),  UINT16_C(    8478) } },
    { {  UINT16_C(   59206),  UINT16_C(   36412),  UINT16_C(   15257),  UINT16_C(   46944),
         UINT16_C(   46282),  UINT16_C(   17117),  UINT16_C(   45233),  UINT16_C(    4994) },
      {  UINT16_C(   46395),  UINT16_C(   50547),  UINT16_C(   19830),  UINT16_C(   44578) },
      {  UINT16_C(   44578),  UINT16_C(   36412),  UINT16_C(   15257),  UINT16_C(   46944),
         UINT16_C(   46282),  UINT16_C(   17117),  UINT16_C(   45233),  UINT16_C(    4994) },
      {  UINT16_C(   59206),  UINT16_C(   36412),  UINT16_C(   15257),  UINT16_C(   19830),
         UINT16_C(   46282),  UINT16_C(   17117),  UINT16_C(   45233),  UINT16_C(    4994) },
      {  UINT16_C(   59206),  UINT16_C(   36412),  UINT16_C(   15257),  UINT16_C(   46944),
         UINT16_C(   46282),  UINT16_C(   50547),  UINT16_C(   45233),  UINT16_C(    4994) },
      {  UINT16_C(   59206),  UINT16_C(   36412),  UINT16_C(   15257),  UINT16_C(   46944),
         UINT16_C(   46282),  UINT16_C(   17117),  UINT16_C(   45233),  UINT16_C(   46395) } },
    { {  UINT16_C(   13682),  UINT16_C(   54233),  UINT16_C(   15911),  UINT16_C(   26730),
         UINT16_C(     502),  UINT16_C(   64753),  UINT16_C(   30819),  UINT16_C(   45749) },
      {  UINT16_C(   24828),  UINT16_C(   29679),  UINT16_C(   21740),  UINT16_C(   34938) },
      {  UINT16_C(   34938),  UINT16_C(   54233),  UINT16_C(   15911),  UINT16_C(   26730),
         UINT16_C(     502),  UINT16_C(   64753),  UINT16_C(   30819),  UINT16_C(   45749) },
      {  UINT16_C(   13682),  UINT16_C(   54233),  UINT16_C(   15911),  UINT16_C(   21740),
         UINT16_C(     502),  UINT16_C(   64753),  UINT16_C(   30819),  UINT16_C(   45749) },
      {  UINT16_C(   13682),  UINT16_C(   54233),  UINT16_C(   15911),  UINT16_C(   26730),
         UINT16_C(     502),  UINT16_C(   29679),  UINT16_C(   30819),  UINT16_C(   45749) },
      {  UINT16_C(   13682),  UINT16_C(   54233),  UINT16_C(   15911),  UINT16_C(   26730),
         UINT16_C(     502),  UINT16_C(   64753),  UINT16_C(   30819),  UINT16_C(   24828) } },
    { {  UINT16_C(   12489),  UINT16_C(    1881),  UINT16_C(   42262),  UINT16_C(   53977),
         UINT16_C(   19091),  UINT16_C(   33756),  UINT16_C(   22902),  UINT16_C(   39968) },
      {  UINT16_C(     373),  UINT16_C(   54089),  UINT16_C(   12533),  UINT16_C(   41276) },
      {  UINT16_C(   41276),  UINT16_C(    1881),  UINT16_C(   42262),  UINT16_C(   53977),
         UINT16_C(   19091),  UINT16_C(   33756),  UINT16_C(   22902),  UINT16_C(   39968) },
      {  UINT16_C(   12489),  UINT16_C(    1881),  UINT16_C(   42262),  UINT16_C(   12533),
         UINT16_C(   19091),  UINT16_C(   33756),  UINT16_C(   22902),  UINT16_C(   39968) },
      {  UINT16_C(   12489),  UINT16_C(    1881),  UINT16_C(   42262),  UINT16_C(   53977),
         UINT16_C(   19091),  UINT16_C(   54089),  UINT16_C(   22902),  UINT16_C(   39968) },
      {  UINT16_C(   12489),  UINT16_C(    1881),  UINT16_C(   42262),  UINT16_C(   53977),
         UINT16_C(   19091),  UINT16_C(   33756),  UINT16_C(   22902),  UINT16_C(     373) } },
    { {  UINT16_C(    8219),  UINT16_C(   44521),  UINT16_C(   54001),  UINT16_C(    7888),
         UINT16_C(   57460),  UINT16_C(   14245),  UINT16_C(   48545),  UINT16_C(   24933) },
      {  UINT16_C(   62999),  UINT16_C(   52731),  UINT16_C(   45056),  UINT16_C(   13736) },
      {  UINT16_C(   13736),  UINT16_C(   44521),  UINT16_C(   54001),  UINT16_C(    7888),
         UINT16_C(   57460),  UINT16_C(   14245),  UINT16_C(   48545),  UINT16_C(   24933) },
      {  UINT16_C(    8219),  UINT16_C(   44521),  UINT16_C(   54001),  UINT16_C(   45056),
         UINT16_C(   57460),  UINT16_C(   14245),  UINT16_C(   48545),  UINT16_C(   24933) },
      {  UINT16_C(    8219),  UINT16_C(   44521),  UINT16_C(   54001),  UINT16_C(    7888),
         UINT16_C(   57460),  UINT16_C(   52731),  UINT16_C(   48545),  UINT16_C(   24933) },
      {  UINT16_C(    8219),  UINT16_C(   44521),  UINT16_C(   54001),  UINT16_C(    7888),
         UINT16_C(   57460),  UINT16_C(   14245),  UINT16_C(   48545),  UINT16_C(   62999) } },
    { {  UINT16_C(   17803),  UINT16_C(   23302),  UINT16_C(   51288),  UINT16_C(    6738),
         UINT16_C(   26381),  UINT16_C(   44920),  UINT16_C(     438),  UINT16_C(   12440) },
      {  UINT16_C(   64520),  UINT16_C(    6608),  UINT16_C(   27242),  UINT16_C(    9986) },
      {  UINT16_C(    9986),  UINT16_C(   23302),  UINT16_C(   51288),  UINT16_C(    6738),
         UINT16_C(   26381),  UINT16_C(   44920),  UINT16_C(     438),  UINT16_C(   12440) },
      {  UINT16_C(   17803),  UINT16_C(   23302),  UINT16_C(   51288),  UINT16_C(   27242),
         UINT16_C(   26381),  UINT16_C(   44920),  UINT16_C(     438),  UINT16_C(   12440) },
      {  UINT16_C(   17803),  UINT16_C(   23302),  UINT16_C(   51288),  UINT16_C(    6738),
         UINT16_C(   26381),  UINT16_C(    6608),  UINT16_C(     438),  UINT16_C(   12440) },
      {  UINT16_C(   17803),  UINT16_C(   23302),  UINT16_C(   51288),  UINT16_C(    6738),
         UINT16_C(   26381),  UINT16_C(   44920),  UINT16_C(     438),  UINT16_C(   64520) } },
    { {  UINT16_C(   40969),  UINT16_C(   63552),  UINT16_C(   36257),  UINT16_C(    5157),
         UINT16_C(   49006),  UINT16_C(    3329),  UINT16_C(   25930),  UINT16_C(   37093) },
      {  UINT16_C(   24602),  UINT16_C(   27093),  UINT16_C(   33126),  UINT16_C(   48029) },
      {  UINT16_C(   48029),  UINT16_C(   63552),  UINT16_C(   36257),  UINT16_C(    5157),
         UINT16_C(   49006),  UINT16_C(    3329),  UINT16_C(   25930),  UINT16_C(   37093) },
      {  UINT16_C(   40969),  UINT16_C(   63552),  UINT16_C(   36257),  UINT16_C(   33126),
         UINT16_C(   49006),  UINT16_C(    3329),  UINT16_C(   25930),  UINT16_C(   37093) },
      {  UINT16_C(   40969),  UINT16_C(   63552),  UINT16_C(   36257),  UINT16_C(    5157),
         UINT16_C(   49006),  UINT16_C(   27093),  UINT16_C(   25930),  UINT16_C(   37093) },
      {  UINT16_C(   40969),  UINT16_C(   63552),  UINT16_C(   36257),  UINT16_C(    5157),
         UINT16_C(   49006),  UINT16_C(    3329),  UINT16_C(   25930),  UINT16_C(   24602) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x8_t r0_3 = simde_vcopyq_lane_u16(a, 0, b, 3);
    simde_uint16x8_t r3_2 = simde_vcopyq_lane_u16(a, 3, b, 2);
    simde_uint16x8_t r5_1 = simde_vcopyq_lane_u16(a, 5, b, 1);
    simde_uint16x8_t r7_0 = simde_vcopyq_lane_u16(a, 7, b, 0);

    simde_test_arm_neon_assert_equal_u16x8(r0_3, simde_vld1q_u16(test_vec[i].r0_3));
    simde_test_arm_neon_assert_equal_u16x8(r3_2, simde_vld1q_u16(test_vec[i].r3_2));
    simde_test_arm_neon_assert_equal_u16x8(r5_1, simde_vld1q_u16(test_vec[i].r5_1));
    simde_test_arm_neon_assert_equal_u16x8(r7_0, simde_vld1q_u16(test_vec[i].r7_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t r0_3 = simde_vcopyq_lane_u16(a, 0, b, 3);
    simde_uint16x8_t r3_2 = simde_vcopyq_lane_u16(a, 3, b, 2);
    simde_uint16x8_t r5_1 = simde_vcopyq_lane_u16(a, 5, b, 1);
    simde_uint16x8_t r7_0 = simde_vcopyq_lane_u16(a, 7, b, 0);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r0_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r5_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r7_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[2];
    uint32_t r0_1[4];
    uint32_t r1_0[4];
    uint32_t r2_1[4];
    uint32_t r3_0[4];
  } test_vec[] = {
    { {  UINT32_C(   361921892),  UINT32_C(  3900928184),  UINT32_C(  3837963448),  UINT32_C(   429793356) },
      {  UINT32_C(    26373424),  UINT32_C(  3910484228) },
      {  UINT32_C(  3910484228),  UINT32_C(  3900928184),  UINT32_C(  3837963448),  UINT32_C(   429793356) },
      {  UINT32_C(   361921892),  UINT32_C(    26373424),  UINT32_C(  3837963448),  UINT32_C(   429793356) },
      {  UINT32_C(   361921892),  UINT32_C(  3900928184),  UINT32_C(  3910484228),  UINT32_C(   429793356) },
      {  UINT32_C(   361921892),  UINT32_C(  3900928184),  UINT32_C(  3837963448),  UINT32_C(    26373424) } },
    { {  UINT32_C(  1396390629),  UINT32_C(  3575792530),  UINT32_C(  3584537359),  UINT32_C(  2356347849) },
      {  UINT32_C(  3791328885),  UINT32_C(  2861189464) },
      {  UINT32_C(  2861189464),  UINT32_C(  3575792530),  UINT32_C(  3584537359),  UINT32_C(  2356347849) },
      {  UINT32_C(  1396390629),  UINT32_C(  3791328885),  UINT32_C(  3584537359),  UINT32_C(  2356347849) },
      {  UINT32_C(  1396390629),  UINT32_C(  3575792530),  UINT32_C(  2861189464),  UINT32_C(  2356347849) },
      {  UINT32_C(  1396390629),  UINT32_C(  3575792530),  UINT32_C(  3584537359),  UINT32_C(  3791328885) } },
    { {  UINT32_C(  2264455894),  UINT32_C(   772844039),  UINT32_C(  2992759396),  UINT32_C(  2614908981) },
      {  UINT32_C(   121133279),  UINT32_C(  1252193851) },
      {  UINT32_C(  1252193851),  UINT32_C(   772844039),  UINT32_C(  2992759396),  UINT32_C(  2614908981) },
      {  UINT32_C(  2264455894),  UINT32_C(   121133279),  UINT32_C(  2992759396),  UINT32_C(  2614908981) },
      {  UINT32_C(  2264455894),  UINT32_C(   772844039),  UINT32_C(  1252193851),  UINT32_C(  2614908981) },
      {  UINT32_C(  2264455894),  UINT32_C(   772844039),  UINT32_C(  2992759396),  UINT32_C(   121133279) } },
    { {  UINT32_C(  2880672670),  UINT32_C(    57847964),  UINT32_C(  4166813298),  UINT32_C(   126229096) },
      {  UINT32_C(  4065062230),  UINT32_C(  1434580494) },
      {  UINT32_C(  1434580494),  UINT32_C(    57847964),  UINT32_C(  4166813298),  UINT32_C(   126229096) },
      {  UINT32_C(  2880672670),  UINT32_C(  4065062230),  UINT32_C(  4166813298),  UINT32_C(   126229096) },
      {  UINT32_C(  2880672670),  UINT32_C(    57847964),  UINT32_C(  1434580494),  UINT32_C(   126229096) },
      {  UINT32_C(  2880672670),  UINT32_C(    57847964),  UINT32_C(  4166813298),  UINT32_C(  4065062230) } },
    { {  UINT32_C(  1340690585),  UINT32_C(   946996966),  UINT32_C(   551479920),  UINT32_C(  3629071371) },
      {  UINT32_C(   404629523),  UINT32_C(  2776260397) },
      {  UINT32_C(  2776260397),  UINT32_C(   946996966),  UINT32_C(   551479920),  UINT32_C(  3629071371) },
      {  UINT32_C(  1340690585),  UINT32_C(   404629523),  UINT32_C(   551479920),  UINT32_C(  3629071371) },
      {  UINT32_C(  1340690585),  UINT32_C(   946996966),  UINT32_C(  2776260397),  UINT32_C(  3629071371) },
      {  UINT32_C(  1340690585),  UINT32_C(   946996966),  UINT32_C(   551479920),  UINT32_C(   404629523) } },
    { {  UINT32_C(  2002654709),  UINT32_C(  1050964603),  UINT32_C(  1159950872),  UINT32_C(  2906190267) },
      {  UINT32_C(   258802985),  UINT32_C(  3426756944) },
      {  UINT32_C(  3426756944),  UINT32_C(  1050964603),  UINT32_C(  1159950872),  UINT32_C(  2906190267) },
      {  UINT32_C(  2002654709),  UINT32_C(   258802985),  UINT32_C(  1159950872),  UINT32_C(  2906190267) },
      {  UINT32_C(  2002654709),  UINT32_C(  1050964603),  UINT32_C(  3426756944),  UINT32_C(  2906190267) },
      {  UINT32_C(  2002654709),  UINT32_C(  1050964603),  UINT32_C(  1159950872),  UINT32_C(   258802985) } },
    { {  UINT32_C(  2945893748),  UINT32_C(   402372422),  UINT32_C(  2823976653),  UINT32_C(  2361987444) },
      {  UINT32_C(    73085720),  UINT32_C(  3141146066) },
      {  UINT32_C(  3141146066),  UINT32_C(   402372422),  UINT32_C(  2823976653),  UINT32_C(  2361987444) },
      {  UINT32_C(  2945893748),  UINT32_C(    73085720),  UINT32_C(  2823976653),  UINT32_C(  2361987444) },
      {  UINT32_C(  2945893748),  UINT32_C(   402372422),  UINT32_C(  3141146066),  UINT32_C(  2361987444) },
      {  UINT32_C(  2945893748),  UINT32_C(   402372422),  UINT32_C(  2823976653),  UINT32_C(    73085720) } },
    { {  UINT32_C(   703705882),  UINT32_C(  1874556398),  UINT32_C(   357072285),  UINT32_C(   989687532) },
      {  UINT32_C(  1441815222),  UINT32_C(  4271316470) },
      {  UINT32_C(  4271316470),  UINT32_C(  1874556398),  UINT32_C(   357072285),  UINT32_C(   989687532) },
      {  UINT32_C(   703705882),  UINT32_C(  1441815222),  UINT32_C(   357072285),  UINT32_C(   989687532) },
      {  UINT32_C(   703705882),  UINT32_C(  1874556398),  UINT32_C(  4271316470),  UINT32_C(   989687532) },
      {  UINT32_C(   703705882),  UINT32_C(  1874556398),  UINT32_C(   357072285),  UINT32_C(  1441815222) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x4_t r0_1 = simde_vcopyq_lane_u32(a, 0, b, 1);
    simde_uint32x4_t r1_0 = simde_vcopyq_lane_u32(a, 1, b, 0);
    simde_uint32x4_t r2_1 = simde_vcopyq_lane_u32(a, 2, b, 1);
    simde_uint32x4_t r3_0 = simde_vcopyq_lane_u32(a, 3, b, 0);

    simde_test_arm_neon_assert_equal_u32x4(r0_1, simde_vld1q_u32(test_vec[i].r0_1));
    simde_test_arm_neon_assert_equal_u32x4(r1_0, simde_vld1q_u32(test_vec[i].r1_0));
    simde_test_arm_neon_assert_equal_u32x4(r2_1, simde_vld1q_u32(test_vec[i].r2_1));
    simde_test_arm_neon_assert_equal_u32x4(r3_0, simde_vld1q_u32(test_vec[i].r3_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t r0_1 = simde_vcopyq_lane_u32(a, 0, b, 1);
    simde_uint32x4_t r1_0 = simde_vcopyq_lane_u32(a, 1, b, 0);
    simde_uint32x4_t r2_1 = simde_vcopyq_lane_u32(a, 2, b, 1);
    simde_uint32x4_t r3_0 = simde_vcopyq_lane_u32(a, 3, b, 0);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r0_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r1_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r2_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r3_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[1];
    uint64_t r0_0[2];
    uint64_t r1_0[2];
  } test_vec[] = {
    { {  UINT64_C(13088088903368892823),  UINT64_C(11535793185305623270) },
      {  UINT64_C( 5924534224249363076) },
      {  UINT64_C( 5924534224249363076),  UINT64_C(11535793185305623270) },
      {  UINT64_C(13088088903368892823),  UINT64_C( 5924534224249363076) } },
    { {  UINT64_C(18271803387774738026),  UINT64_C(  840258608695505479) },
      {  UINT64_C(18149383589595975661) },
      {  UINT64_C(18149383589595975661),  UINT64_C(  840258608695505479) },
      {  UINT64_C(18271803387774738026),  UINT64_C(18149383589595975661) } },
    { {  UINT64_C( 1426608908501472439),  UINT64_C(17579859043434713714) },
      {  UINT64_C( 3863851528950464347) },
      {  UINT64_C( 3863851528950464347),  UINT64_C(17579859043434713714) },
      {  UINT64_C( 1426608908501472439),  UINT64_C( 3863851528950464347) } },
    { {  UINT64_C( 2887535003750440669),  UINT64_C( 9706127502422434237) },
      {  UINT64_C(  585016102035113102) },
      {  UINT64_C(  585016102035113102),  UINT64_C( 9706127502422434237) },
      {  UINT64_C( 2887535003750440669),  UINT64_C(  585016102035113102) } },
    { {  UINT64_C(11767062204421784175),  UINT64_C( 6611989932014277560) },
      {  UINT64_C( 1728274990776995191) },
      {  UINT64_C( 1728274990776995191),  UINT64_C( 6611989932014277560) },
      {  UINT64_C(11767062204421784175),  UINT64_C( 1728274990776995191) } },
    { {  UINT64_C(11529019270513437728),  UINT64_C( 7695879568420221205) },
      {  UINT64_C(15611393117687386357) },
      {  UINT64_C(15611393117687386357),  UINT64_C( 7695879568420221205) },
      {  UINT64_C(11529019270513437728),  UINT64_C(15611393117687386357) } },
    { {  UINT64_C(11313965299073639025),  UINT64_C( 5304856213118510799) },
      {  UINT64_C( 4627035757479335269) },
      {  UINT64_C( 4627035757479335269),  UINT64_C( 5304856213118510799) },
      {  UINT64_C(11313965299073639025),  UINT64_C( 4627035757479335269) } },
    { {  UINT64_C(10403068332418732573),  UINT64_C(18189821306737318447) },
      {  UINT64_C(15540049615037950397) },
      {  UINT64_C(15540049615037950397),  UINT64_C(18189821306737318447) },
      {  UINT64_C(10403068332418732573),  UINT64_C(15540049615037950397) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);

    simde_uint64x2_t r0_0 = simde_vcopyq_lane_u64(a, 0, b, 0);
    simde_uint64x2_t r1_0 = simde_vcopyq_lane_u64(a, 1, b, 0);

    simde_test_arm_neon_assert_equal_u64x2(r0_0, simde_vld1q_u64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_u64x2(r1_0, simde_vld1q_u64(test_vec[i].r1_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x2_t r0_0 = simde_vcopyq_lane_u64(a, 0, b, 0);
    simde_uint64x2_t r1_0 = simde_vcopyq_lane_u64(a, 1, b, 0);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r1_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t b[2];
    simde_float32_t r0_1[4];
    simde_float32_t r1_0[4];
    simde_float32_t r2_1[4];
    simde_float32_t r3_0[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   538.654), -SIMDE_FLOAT32_C(  4708.625), -SIMDE_FLOAT32_C(  9690.416), -SIMDE_FLOAT32_C(  2113.408) },
      {  SIMDE_FLOAT32_C(  8132.408),  SIMDE_FLOAT32_C(  5050.145) },
      {  SIMDE_FLOAT32_C(  5050.145), -SIMDE_FLOAT32_C(  4708.625), -SIMDE_FLOAT32_C(  9690.416), -SIMDE_FLOAT32_C(  2113.408) },
      {  SIMDE_FLOAT32_C(   538.654),  SIMDE_FLOAT32_C(  8132.408), -SIMDE_FLOAT32_C(  9690.416), -SIMDE_FLOAT32_C(  2113.408) },
      {  SIMDE_FLOAT32_C(   538.654), -SIMDE_FLOAT32_C(  4708.625),  SIMDE_FLOAT32_C(  5050.145), -SIMDE_FLOAT32_C(  2113.408) },
      {  SIMDE_FLOAT32_C(   538.654), -SIMDE_FLOAT32_C(  4708.625), -SIMDE_FLOAT32_C(  9690.416),  SIMDE_FLOAT32_C(  8132.408) } },
    { {  SIMDE_FLOAT32_C(  5966.624),  SIMDE_FLOAT32_C(  7056.986), -SIMDE_FLOAT32_C(  1760.608), -SIMDE_FLOAT32_C(   656.592) },
      {  SIMDE_FLOAT32_C(  7371.629), -SIMDE_FLOAT32_C(   974.229) },
      { -SIMDE_FLOAT32_C(   974.229),  SIMDE_FLOAT32_C(  7056.986), -SIMDE_FLOAT32_C(  1760.608), -SIMDE_FLOAT32_C(   656.592) },
      {  SIMDE_FLOAT32_C(  5966.624),  SIMDE_FLOAT32_C(  7371.629), -SIMDE_FLOAT32_C(  1760.608), -SIMDE_FLOAT32_C(   656.592) },
      {  SIMDE_FLOAT32_C(  5966.624),  SIMDE_FLOAT32_C(  7056.986), -SIMDE_FLOAT32_C(   974.229), -SIMDE_FLOAT32_C(   656.592) },
      {  SIMDE_FLOAT32_C(  5966.624),  SIMDE_FLOAT32_C(  7056.986), -SIMDE_FLOAT32_C(  1760.608),  SIMDE_FLOAT32_C(  7371.629) } },
    { { -SIMDE_FLOAT32_C(  2332.909), -SIMDE_FLOAT32_C(    12.015),  SIMDE_FLOAT32_C(   958.198),  SIMDE_FLOAT32_C(  3179.859) },
      {  SIMDE_FLOAT32_C(   421.483), -SIMDE_FLOAT32_C(   391.272) },
      { -SIMDE_FLOAT32_C(   391.272), -SIMDE_FLOAT32_C(    12.015),  SIMDE_FLOAT32_C(   958.198),  SIMDE_FLOAT32_C(  3179.859) },
      { -SIMDE_FLOAT32_C(  2332.909),  SIMDE_FLOAT32_C(   421.483),  SIMDE_FLOAT32_C(   958.198),  SIMDE_FLOAT32_C(  3179.859) },
      { -SIMDE_FLOAT32_C(  2332.909), -SIMDE_FLOAT32_C(    12.015), -SIMDE_FLOAT32_C(   391.272),  SIMDE_FLOAT32_C(  3179.859) },
      { -SIMDE_FLOAT32_C(  2332.909), -SIMDE_FLOAT32_C(    12.015),  SIMDE_FLOAT32_C(   958.198),  SIMDE_FLOAT32_C(   421.483) } },
    { {  SIMDE_FLOAT32_C(  5751.485), -SIMDE_FLOAT32_C(  4550.866), -SIMDE_FLOAT32_C(  5492.006), -SIMDE_FLOAT32_C(  3518.459) },
      {  SIMDE_FLOAT32_C(  5851.975),  SIMDE_FLOAT32_C(  7832.057) },
      {  SIMDE_FLOAT32_C(  7832.057), -SIMDE_FLOAT32_C(  4550.866), -SIMDE_FLOAT32_C(  5492.006), -SIMDE_FLOAT32_C(  3518.459) },
      {  SIMDE_FLOAT32_C(  5751.485),  SIMDE_FLOAT32_C(  5851.975), -SIMDE_FLOAT32_C(  5492.006), -SIMDE_FLOAT32_C(  3518.459) },
      {  SIMDE_FLOAT32_C(  5751.485), -SIMDE_FLOAT32_C(  4550.866),  SIMDE_FLOAT32_C(  7832.057), -SIMDE_FLOAT32_C(  3518.459) },
      {  SIMDE_FLOAT32_C(  5751.485), -SIMDE_FLOAT32_C(  4550.866), -SIMDE_FLOAT32_C(  5492.006),  SIMDE_FLOAT32_C(  5851.975) } },
    { {  SIMDE_FLOAT32_C(  2504.024), -SIMDE_FLOAT32_C(  4086.377),  SIMDE_FLOAT32_C(  2309.051),  SIMDE_FLOAT32_C(  1842.812) },
      {  SIMDE_FLOAT32_C(  9351.285), -SIMDE_FLOAT32_C(  4461.544) },
      { -SIMDE_FLOAT32_C(  4461.544), -SIMDE_FLOAT32_C(  4086.377),  SIMDE_FLOAT32_C(  2309.051),  SIMDE_FLOAT32_C(  1842.812) },
      {  SIMDE_FLOAT32_C(  2504.024),  SIMDE_FLOAT32_C(  9351.285),  SIMDE_FLOAT32_C(  2309.051),  SIMDE_FLOAT32_C(  1842.812) },
      {  SIMDE_FLOAT32_C(  2504.024), -SIMDE_FLOAT32_C(  4086.377), -SIMDE_FLOAT32_C(  4461.544),  SIMDE_FLOAT32_C(  1842.812) },
      {  SIMDE_FLOAT32_C(  2504.024), -SIMDE_FLOAT32_C(  4086.377),  SIMDE_FLOAT32_C(  2309.051),  SIMDE_FLOAT32_C(  9351.285) } },
    { { -SIMDE_FLOAT32_C(  6719.923),  SIMDE_FLOAT32_C(  7398.066),  SIMDE_FLOAT32_C(  7624.779), -SIMDE_FLOAT32_C(  7913.260) },
      {  SIMDE_FLOAT32_C(  9228.150), -SIMDE_FLOAT32_C(  6206.421) },
      { -SIMDE_FLOAT32_C(  6206.421),  SIMDE_FLOAT32_C(  7398.066),  SIMDE_FLOAT32_C(  7624.779), -SIMDE_FLOAT32_C(  7913.260) },
      { -SIMDE_FLOAT32_C(  6719.923),  SIMDE_FLOAT32_C(  9228.150),  SIMDE_FLOAT32_C(  7624.779), -SIMDE_FLOAT32_C(  7913.260) },
      { -SIMDE_FLOAT32_C(  6719.923),  SIMDE_FLOAT32_C(  7398.066), -SIMDE_FLOAT32_C(  6206.421), -SIMDE_FLOAT32_C(  7913.260) },
      { -SIMDE_FLOAT32_C(  6719.923),  SIMDE_FLOAT32_C(  7398.066),  SIMDE_FLOAT32_C(  7624.779),  SIMDE_FLOAT32_C(  9228.150) } },
    { {  SIMDE_FLOAT32_C(  3809.922),  SIMDE_FLOAT32_C(  3800.742), -SIMDE_FLOAT32_C(  1237.310),  SIMDE_FLOAT32_C(  4963.046) },
      { -SIMDE_FLOAT32_C(  6177.402),  SIMDE_FLOAT32_C(  3679.462) },
      {  SIMDE_FLOAT32_C(  3679.462),  SIMDE_FLOAT32_C(  3800.742), -SIMDE_FLOAT32_C(  1237.310),  SIMDE_FLOAT32_C(  4963.046) },
      {  SIMDE_FLOAT32_C(  3809.922), -SIMDE_FLOAT32_C(  6177.402), -SIMDE_FLOAT32_C(  1237.310),  SIMDE_FLOAT32_C(  4963.046) },
      {  SIMDE_FLOAT32_C(  3809.922),  SIMDE_FLOAT32_C(  3800.742),  SIMDE_FLOAT32_C(  3679.462),  SIMDE_FLOAT32_C(  4963.046) },
      {  SIMDE_FLOAT32_C(  3809.922),  SIMDE_FLOAT32_C(  3800.742), -SIMDE_FLOAT32_C(  1237.310), -SIMDE_FLOAT32_C(  6177.402) } },
    { {  SIMDE_FLOAT32_C(  2821.190), -SIMDE_FLOAT32_C(  5775.095), -SIMDE_FLOAT32_C(  3892.955),  SIMDE_FLOAT32_C(  4093.751) },
      {  SIMDE_FLOAT32_C(  3420.151), -SIMDE_FLOAT32_C(  6425.996) },
      { -SIMDE_FLOAT32_C(  6425.996), -SIMDE_FLOAT32_C(  5775.095), -SIMDE_FLOAT32_C(  3892.955),  SIMDE_FLOAT32_C(  4093.751) },
      {  SIMDE_FLOAT32_C(  2821.190),  SIMDE_FLOAT32_C(  3420.151), -SIMDE_FLOAT32_C(  3892.955),  SIMDE_FLOAT32_C(  4093.751) },
      {  SIMDE_FLOAT32_C(  2821.190), -SIMDE_FLOAT32_C(  5775.095), -SIMDE_FLOAT32_C(  6425.996),  SIMDE_FLOAT32_C(  4093.751) },
      {  SIMDE_FLOAT32_C(  2821.190), -SIMDE_FLOAT32_C(  5775.095), -SIMDE_FLOAT32_C(  3892.955),  SIMDE_FLOAT32_C(  3420.151) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);

    simde_float32x4_t r0_1 = simde_vcopyq_lane_f32(a, 0, b, 1);
    simde_float32x4_t r1_0 = simde_vcopyq_lane_f32(a, 1, b, 0);
    simde_float32x4_t r2_1 = simde_vcopyq_lane_f32(a, 2, b, 1);
    simde_float32x4_t r3_0 = simde_vcopyq_lane_f32(a, 3, b, 0);

    simde_test_arm_neon_assert_equal_f32x4(r0_1, simde_vld1q_f32(test_vec[i].r0_1), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r1_0, simde_vld1q_f32(test_vec[i].r1_0), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r2_1, simde_vld1q_f32(test_vec[i].r2_1), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r3_0, simde_vld1q_f32(test_vec[i].r3_0), INT_MAX);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x4_t r0_1 = simde_vcopyq_lane_f32(a, 0, b, 1);
    simde_float32x4_t r1_0 = simde_vcopyq_lane_f32(a, 1, b, 0);
    simde_float32x4_t r2_1 = simde_vcopyq_lane_f32(a, 2, b, 1);
    simde_float32x4_t r3_0 = simde_vcopyq_lane_f32(a, 3, b, 0);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r0_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r1_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r2_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r3_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t b[1];
    simde_float64_t r0_0[2];
    simde_float64_t r1_0[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT64_C(  157594.625),  SIMDE_FLOAT64_C(  656117.375) },
      { -SIMDE_FLOAT64_C(   75540.062) },
      { -SIMDE_FLOAT64_C(   75540.062),  SIMDE_FLOAT64_C(  656117.375) },
      { -SIMDE_FLOAT64_C(  157594.625), -SIMDE_FLOAT64_C(   75540.062) } },
    { { -SIMDE_FLOAT64_C(  646085.625),  SIMDE_FLOAT64_C(  464808.125) },
      {  SIMDE_FLOAT64_C(  806328.250) },
      {  SIMDE_FLOAT64_C(  806328.250),  SIMDE_FLOAT64_C(  464808.125) },
      { -SIMDE_FLOAT64_C(  646085.625),  SIMDE_FLOAT64_C(  806328.250) } },
    { {  SIMDE_FLOAT64_C(  502781.125),  SIMDE_FLOAT64_C(  524179.125) },
      {  SIMDE_FLOAT64_C(  744040.125) },
      {  SIMDE_FLOAT64_C(  744040.125),  SIMDE_FLOAT64_C(  524179.125) },
      {  SIMDE_FLOAT64_C(  502781.125),  SIMDE_FLOAT64_C(  744040.125) } },
    { {  SIMDE_FLOAT64_C(  621060.750), -SIMDE_FLOAT64_C(  924502.875) },
      { -SIMDE_FLOAT64_C(  581503.625) },
      { -SIMDE_FLOAT64_C(  581503.625), -SIMDE_FLOAT64_C(  924502.875) },
      {  SIMDE_FLOAT64_C(  621060.750), -SIMDE_FLOAT64_C(  581503.625) } },
    { { -SIMDE_FLOAT64_C(  202743.125),  SIMDE_FLOAT64_C(   94559.250) },
      { -SIMDE_FLOAT64_C(  791547.938) },
      { -SIMDE_FLOAT64_C(  791547.938),  SIMDE_FLOAT64_C(   94559.250) },
      { -SIMDE_FLOAT64_C(  202743.125), -SIMDE_FLOAT64_C(  791547.938) } },
    { {  SIMDE_FLOAT64_C(  242598.875), -SIMDE_FLOAT64_C(  699786.875) },
      {  SIMDE_FLOAT64_C(  419738.000) },
      {  SIMDE_FLOAT64_C(  419738.000), -SIMDE_FLOAT64_C(  699786.875) },
      {  SIMDE_FLOAT64_C(  242598.875),  SIMDE_FLOAT64_C(  419738.000) } },
    { {  SIMDE_FLOAT64_C(   47666.812), -SIMDE_FLOAT64_C(  674149.875) },
      { -SIMDE_FLOAT64_C(  567563.562) },
      { -SIMDE_FLOAT64_C(  567563.562), -SIMDE_FLOAT64_C(  674149.875) },
      {  SIMDE_FLOAT64_C(   47666.812), -SIMDE_FLOAT64_C(  567563.562) } },
    { {  SIMDE_FLOAT64_C(  864337.875),  SIMDE_FLOAT64_C(  108615.000) },
      { -SIMDE_FLOAT64_C(  346185.500) },
      { -SIMDE_FLOAT64_C(  346185.500),  SIMDE_FLOAT64_C(  108615.000) },
      {  SIMDE_FLOAT64_C(  864337.875), -SIMDE_FLOAT64_C(  346185.500) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);

    simde_float64x2_t r0_0 = simde_vcopyq_lane_f64(a, 0, b, 0);
    simde_float64x2_t r1_0 = simde_vcopyq_lane_f64(a, 1, b, 0);

    simde_test_arm_neon_assert_equal_f64x2(r0_0, simde_vld1q_f64(test_vec[i].r0_0), INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r1_0, simde_vld1q_f64(test_vec[i].r1_0), INT_MAX);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r0_0 = simde_vcopyq_lane_f64(a, 0, b, 0);
    simde_float64x2_t r1_0 = simde_vcopyq_lane_f64(a, 1, b, 0);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r1_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r0_15[16];
    int8_t r3_12[16];
    int8_t r7_8[16];
    int8_t r11_4[16];
    int8_t r15_1[16];
  } test_vec[] = {
    { { -INT8_C(    86), -INT8_C(   119), -INT8_C(    89), -INT8_C(   101),
        -INT8_C(    97),  INT8_C(    71),  INT8_C(    93), -INT8_C(     3),
        -INT8_C(    57), -INT8_C(    99), -INT8_C(   121), -INT8_C(     8),
        -INT8_C(    23),  INT8_C(    60),  INT8_C(    99), -INT8_C(    65) },
      { -INT8_C(   105), -INT8_C(    43), -INT8_C(    27),  INT8_C(    85),
        -INT8_C(   127),  INT8_C(    28), -INT8_C(     6),  INT8_C(   100),
         INT8_C(    49),  INT8_C(    98),  INT8_C(   119),  INT8_C(    45),
        -INT8_C(   106),  INT8_C(    22),  INT8_C(    85),  INT8_C(    97) },
      {  INT8_C(    97), -INT8_C(   119), -INT8_C(    89), -INT8_C(   101),
        -INT8_C(    97),  INT8_C(    71),  INT8_C(    93), -INT8_C(     3),
        -INT8_C(    57), -INT8_C(    99), -INT8_C(   121), -INT8_C(     8),
        -INT8_C(    23),  INT8_C(    60),  INT8_C(    99), -INT8_C(    65) },
      { -INT8_C(    86), -INT8_C(   119), -INT8_C(    89), -INT8_C(   106),
        -INT8_C(    97),  INT8_C(    71),  INT8_C(    93), -INT8_C(     3),
        -INT8_C(    57), -INT8_C(    99), -INT8_C(   121), -INT8_C(     8),
        -INT8_C(    23),  INT8_C(    60),  INT8_C(    99), -INT8_C(    65) },
      { -INT8_C(    86), -INT8_C(   119), -INT8_C(    89), -INT8_C(   101),
        -INT8_C(    97),  INT8_C(    71),  INT8_C(    93),  INT8_C(    49),
        -INT8_C(    57), -INT8_C(    99), -INT8_C(   121), -INT8_C(     8),
        -INT8_C(    23),  INT8_C(    60),  INT8_C(    99), -INT8_C(    65) },
      { -INT8_C(    86), -INT8_C(   119), -INT8_C(    89), -INT8_C(   101),
        -INT8_C(    97),  INT8_C(    71),  INT8_C(    93), -INT8_C(     3),
        -INT8_C(    57), -INT8_C(    99), -INT8_C(   121), -INT8_C(   127),
        -INT8_C(    23),  INT8_C(    60),  INT8_C(    99), -INT8_C(    65) },
      { -INT8_C(    86), -INT8_C(   119), -INT8_C(    89), -INT8_C(   101),
        -INT8_C(    97),  INT8_C(    71),  INT8_C(    93), -INT8_C(     3),
        -INT8_C(    57), -INT8_C(    99), -INT8_C(   121), -INT8_C(     8),
        -INT8_C(    23),  INT8_C(    60),  INT8_C(    99), -INT8_C(    43) } },
    { { -INT8_C(     2), -INT8_C(    46), -INT8_C(   111),  INT8_C(    44),
        -INT8_C(   104), -INT8_C(   127),        INT8_MAX, -INT8_C(   124),
         INT8_C(   126),  INT8_C(    89), -INT8_C(    85),  INT8_C(    91),
         INT8_C(    57), -INT8_C(    44), -INT8_C(    31),  INT8_C(    88) },
      {  INT8_C(    88), -INT8_C(    33),  INT8_C(    90), -INT8_C(    33),
         INT8_C(   109),  INT8_C(    74),  INT8_C(    81),  INT8_C(   100),
         INT8_C(    39),  INT8_C(   114), -INT8_C(    29),  INT8_C(    93),
         INT8_C(    59), -INT8_C(    78),  INT8_C(    36),  INT8_C(     4) },
      {  INT8_C(     4), -INT8_C(    46), -INT8_C(   111),  INT8_C(    44),
        -INT8_C(   104), -INT8_C(   127),        INT8_MAX, -INT8_C(   124),
         INT8_C(   126),  INT8_C(    89), -INT8_C(    85),  INT8_C(    91),
         INT8_C(    57), -INT8_C(    44), -INT8_C(    31),  INT8_C(    88) },
      { -INT8_C(     2), -INT8_C(    46), -INT8_C(   111),  INT8_C(    59),
        -INT8_C(   104), -INT8_C(   127),        INT8_MAX, -INT8_C(   124),
         INT8_C(   126),  INT8_C(    89), -INT8_C(    85),  INT8_C(    91),
         INT8_C(    57), -INT8_C(    44), -INT8_C(    31),  INT8_C(    88) },
      { -INT8_C(     2), -INT8_C(    46), -INT8_C(   111),  INT8_C(    44),
        -INT8_C(   104), -INT8_C(   127),        INT8_MAX,  INT8_C(    39),
         INT8_C(   126),  INT8_C(    89), -INT8_C(    85),  INT8_C(    91),
         INT8_C(    57), -INT8_C(    44), -INT8_C(    31),  INT8_C(    88) },
      { -INT8_C(     2), -INT8_C(    46), -INT8_C(   111),  INT8_C(    44),
        -INT8_C(   104), -INT8_C(   127),        INT8_MAX, -INT8_C(   124),
         INT8_C(   126),  INT8_C(    89), -INT8_C(    85),  INT8_C(   109),
         INT8_C(    57), -INT8_C(    44), -INT8_C(    31),  INT8_C(    88) },
      { -INT8_C(     2), -INT8_C(    46), -INT8_C(   111),  INT8_C(    44),
        -INT8_C(   104), -INT8_C(   127),        INT8_MAX, -INT8_C(   124),
         INT8_C(   126),  INT8_C(    89), -INT8_C(    85),  INT8_C(    91),
         INT8_C(    57), -INT8_C(    44), -INT8_C(    31), -INT8_C(    33) } },
    { { -INT8_C(   111),  INT8_C(    42), -INT8_C(   114), -INT8_C(   100),
        -INT8_C(    58), -INT8_C(     2),  INT8_C(   107), -INT8_C(   106),
        -INT8_C(    82), -INT8_C(    67),  INT8_C(    73), -INT8_C(    39),
         INT8_C(   115), -INT8_C(    10), -INT8_C(   106),  INT8_C(   100) },
      {  INT8_C(    45), -INT8_C(    75),  INT8_C(    39),  INT8_C(   126),
         INT8_C(    74), -INT8_C(    18),  INT8_C(    80),  INT8_C(    87),
        -INT8_C(    33), -INT8_C(    86), -INT8_C(    75), -INT8_C(    14),
        -INT8_C(    61), -INT8_C(    68), -INT8_C(    38), -INT8_C(    86) },
      { -INT8_C(    86),  INT8_C(    42), -INT8_C(   114), -INT8_C(   100),
        -INT8_C(    58), -INT8_C(     2),  INT8_C(   107), -INT8_C(   106),
        -INT8_C(    82), -INT8_C(    67),  INT8_C(    73), -INT8_C(    39),
         INT8_C(   115), -INT8_C(    10), -INT8_C(   106),  INT8_C(   100) },
      { -INT8_C(   111),  INT8_C(    42), -INT8_C(   114), -INT8_C(    61),
        -INT8_C(    58), -INT8_C(     2),  INT8_C(   107), -INT8_C(   106),
        -INT8_C(    82), -INT8_C(    67),  INT8_C(    73), -INT8_C(    39),
         INT8_C(   115), -INT8_C(    10), -INT8_C(   106),  INT8_C(   100) },
      { -INT8_C(   111),  INT8_C(    42), -INT8_C(   114), -INT8_C(   100),
        -INT8_C(    58), -INT8_C(     2),  INT8_C(   107), -INT8_C(    33),
        -INT8_C(    82), -INT8_C(    67),  INT8_C(    73), -INT8_C(    39),
         INT8_C(   115), -INT8_C(    10), -INT8_C(   106),  INT8_C(   100) },
      { -INT8_C(   111),  INT8_C(    42), -INT8_C(   114), -INT8_C(   100),
        -INT8_C(    58), -INT8_C(     2),  INT8_C(   107), -INT8_C(   106),
        -INT8_C(    82), -INT8_C(    67),  INT8_C(    73),  INT8_C(    74),
         INT8_C(   115), -INT8_C(    10), -INT8_C(   106),  INT8_C(   100) },
      { -INT8_C(   111),  INT8_C(    42), -INT8_C(   114), -INT8_C(   100),
        -INT8_C(    58), -INT8_C(     2),  INT8_C(   107), -INT8_C(   106),
        -INT8_C(    82), -INT8_C(    67),  INT8_C(    73), -INT8_C(    39),
         INT8_C(   115), -INT8_C(    10), -INT8_C(   106), -INT8_C(    75) } },
    { {  INT8_C(    26),  INT8_C(    18),  INT8_C(    90),  INT8_C(    80),
        -INT8_C(   102), -INT8_C(    62),  INT8_C(   113),  INT8_C(    22),
        -INT8_C(    13),  INT8_C(   104), -INT8_C(    38),  INT8_C(   110),
        -INT8_C(    58), -INT8_C(    39), -INT8_C(    42), -INT8_C(    86) },
      { -INT8_C(    45),  INT8_C(    21), -INT8_C(    30),  INT8_C(    94),
         INT8_C(    77), -INT8_C(    94), -INT8_C(    67), -INT8_C(    43),
        -INT8_C(    75),  INT8_C(    49), -INT8_C(   118),  INT8_C(    63),
        -INT8_C(     2), -INT8_C(    73),  INT8_C(   116), -INT8_C(    29) },
      { -INT8_C(    29),  INT8_C(    18),  INT8_C(    90),  INT8_C(    80),
        -INT8_C(   102), -INT8_C(    62),  INT8_C(   113),  INT8_C(    22),
        -INT8_C(    13),  INT8_C(   104), -INT8_C(    38),  INT8_C(   110),
        -INT8_C(    58), -INT8_C(    39), -INT8_C(    42), -INT8_C(    86) },
      {  INT8_C(    26),  INT8_C(    18),  INT8_C(    90), -INT8_C(     2),
        -INT8_C(   102), -INT8_C(    62),  INT8_C(   113),  INT8_C(    22),
        -INT8_C(    13),  INT8_C(   104), -INT8_C(    38),  INT8_C(   110),
        -INT8_C(    58), -INT8_C(    39), -INT8_C(    42), -INT8_C(    86) },
      {  INT8_C(    26),  INT8_C(    18),  INT8_C(    90),  INT8_C(    80),
        -INT8_C(   102), -INT8_C(    62),  INT8_C(   113), -INT8_C(    75),
        -INT8_C(    13),  INT8_C(   104), -INT8_C(    38),  INT8_C(   110),
        -INT8_C(    58), -INT8_C(    39), -INT8_C(    42), -INT8_C(    86) },
      {  INT8_C(    26),  INT8_C(    18),  INT8_C(    90),  INT8_C(    80),
        -INT8_C(   102), -INT8_C(    62),  INT8_C(   113),  INT8_C(    22),
        -INT8_C(    13),  INT8_C(   104), -INT8_C(    38),  INT8_C(    77),
        -INT8_C(    58), -INT8_C(    39), -INT8_C(    42), -INT8_C(    86) },
      {  INT8_C(    26),  INT8_C(    18),  INT8_C(    90),  INT8_C(    80),
        -INT8_C(   102), -INT8_C(    62),  INT8_C(   113),  INT8_C(    22),
        -INT8_C(    13),  INT8_C(   104), -INT8_C(    38),  INT8_C(   110),
        -INT8_C(    58), -INT8_C(    39), -INT8_C(    42),  INT8_C(    21) } },
    { {  INT8_C(    30),  INT8_C(    53), -INT8_C(     1),  INT8_C(   113),
         INT8_C(   122), -INT8_C(    83), -INT8_C(   104),  INT8_C(    44),
         INT8_C(   117),  INT8_C(    63),  INT8_C(    33),  INT8_C(     5),
        -INT8_C(    56),  INT8_C(   100),  INT8_C(     3),  INT8_C(    48) },
      { -INT8_C(    41),  INT8_C(    25), -INT8_C(   111), -INT8_C(    24),
        -INT8_C(    18), -INT8_C(   110), -INT8_C(    38),  INT8_C(    50),
         INT8_C(    54), -INT8_C(    27),  INT8_C(   121), -INT8_C(    37),
        -INT8_C(    56),  INT8_C(    67), -INT8_C(     9), -INT8_C(    12) },
      { -INT8_C(    12),  INT8_C(    53), -INT8_C(     1),  INT8_C(   113),
         INT8_C(   122), -INT8_C(    83), -INT8_C(   104),  INT8_C(    44),
         INT8_C(   117),  INT8_C(    63),  INT8_C(    33),  INT8_C(     5),
        -INT8_C(    56),  INT8_C(   100),  INT8_C(     3),  INT8_C(    48) },
      {  INT8_C(    30),  INT8_C(    53), -INT8_C(     1), -INT8_C(    56),
         INT8_C(   122), -INT8_C(    83), -INT8_C(   104),  INT8_C(    44),
         INT8_C(   117),  INT8_C(    63),  INT8_C(    33),  INT8_C(     5),
        -INT8_C(    56),  INT8_C(   100),  INT8_C(     3),  INT8_C(    48) },
      {  INT8_C(    30),  INT8_C(    53), -INT8_C(     1),  INT8_C(   113),
         INT8_C(   122), -INT8_C(    83), -INT8_C(   104),  INT8_C(    54),
         INT8_C(   117),  INT8_C(    63),  INT8_C(    33),  INT8_C(     5),
        -INT8_C(    56),  INT8_C(   100),  INT8_C(     3),  INT8_C(    48) },
      {  INT8_C(    30),  INT8_C(    53), -INT8_C(     1),  INT8_C(   113),
         INT8_C(   122), -INT8_C(    83), -INT8_C(   104),  INT8_C(    44),
         INT8_C(   117),  INT8_C(    63),  INT8_C(    33), -INT8_C(    18),
        -INT8_C(    56),  INT8_C(   100),  INT8_C(     3),  INT8_C(    48) },
      {  INT8_C(    30),  INT8_C(    53), -INT8_C(     1),  INT8_C(   113),
         INT8_C(   122), -INT8_C(    83), -INT8_C(   104),  INT8_C(    44),
         INT8_C(   117),  INT8_C(    63),  INT8_C(    33),  INT8_C(     5),
        -INT8_C(    56),  INT8_C(   100),  INT8_C(     3),  INT8_C(    25) } },
    { { -INT8_C(    68),  INT8_C(   107), -INT8_C(    28), -INT8_C(    87),
        -INT8_C(    31), -INT8_C(    14),  INT8_C(   112), -INT8_C(    41),
         INT8_C(   106), -INT8_C(    43), -INT8_C(   101), -INT8_C(    44),
        -INT8_C(     5),  INT8_C(    73), -INT8_C(   125),        INT8_MIN },
      { -INT8_C(    79), -INT8_C(     3),  INT8_C(     1), -INT8_C(    70),
         INT8_C(    13),  INT8_C(    50), -INT8_C(   100),  INT8_C(     3),
        -INT8_C(    99),  INT8_C(    54),  INT8_C(     6),  INT8_C(   114),
        -INT8_C(    70),  INT8_C(    81), -INT8_C(    40),  INT8_C(    65) },
      {  INT8_C(    65),  INT8_C(   107), -INT8_C(    28), -INT8_C(    87),
        -INT8_C(    31), -INT8_C(    14),  INT8_C(   112), -INT8_C(    41),
         INT8_C(   106), -INT8_C(    43), -INT8_C(   101), -INT8_C(    44),
        -INT8_C(     5),  INT8_C(    73), -INT8_C(   125),        INT8_MIN },
      { -INT8_C(    68),  INT8_C(   107), -INT8_C(    28), -INT8_C(    70),
        -INT8_C(    31), -INT8_C(    14),  INT8_C(   112), -INT8_C(    41),
         INT8_C(   106), -INT8_C(    43), -INT8_C(   101), -INT8_C(    44),
        -INT8_C(     5),  INT8_C(    73), -INT8_C(   125),        INT8_MIN },
      { -INT8_C(    68),  INT8_C(   107), -INT8_C(    28), -INT8_C(    87),
        -INT8_C(    31), -INT8_C(    14),  INT8_C(   112), -INT8_C(    99),
         INT8_C(   106), -INT8_C(    43), -INT8_C(   101), -INT8_C(    44),
        -INT8_C(     5),  INT8_C(    73), -INT8_C(   125),        INT8_MIN },
      { -INT8_C(    68),  INT8_C(   107), -INT8_C(    28), -INT8_C(    87),
        -INT8_C(    31), -INT8_C(    14),  INT8_C(   112), -INT8_C(    41),
         INT8_C(   106), -INT8_C(    43), -INT8_C(   101),  INT8_C(    13),
        -INT8_C(     5),  INT8_C(    73), -INT8_C(   125),        INT8_MIN },
      { -INT8_C(    68),  INT8_C(   107), -INT8_C(    28), -INT8_C(    87),
        -INT8_C(    31), -INT8_C(    14),  INT8_C(   112), -INT8_C(    41),
         INT8_C(   106), -INT8_C(    43), -INT8_C(   101), -INT8_C(    44),
        -INT8_C(     5),  INT8_C(    73), -INT8_C(   125), -INT8_C(     3) } },
    { { -INT8_C(    77),  INT8_C(    70),  INT8_C(    64),  INT8_C(    54),
         INT8_C(    95),  INT8_C(     0),  INT8_C(    81),  INT8_C(     7),
         INT8_C(    24), -INT8_C(    47),  INT8_C(    79),  INT8_C(    68),
        -INT8_C(    40),  INT8_C(    62),  INT8_C(   119),  INT8_C(    75) },
      {  INT8_C(    34), -INT8_C(    23),  INT8_C(    73),  INT8_C(    98),
         INT8_C(    46), -INT8_C(    31),  INT8_C(    75),  INT8_C(    32),
         INT8_C(    97),  INT8_C(     6), -INT8_C(    61), -INT8_C(    33),
        -INT8_C(    99), -INT8_C(   104), -INT8_C(   103), -INT8_C(    34) },
      { -INT8_C(    34),  INT8_C(    70),  INT8_C(    64),  INT8_C(    54),
         INT8_C(    95),  INT8_C(     0),  INT8_C(    81),  INT8_C(     7),
         INT8_C(    24), -INT8_C(    47),  INT8_C(    79),  INT8_C(    68),
        -INT8_C(    40),  INT8_C(    62),  INT8_C(   119),  INT8_C(    75) },
      { -INT8_C(    77),  INT8_C(    70),  INT8_C(    64), -INT8_C(    99),
         INT8_C(    95),  INT8_C(     0),  INT8_C(    81),  INT8_C(     7),
         INT8_C(    24), -INT8_C(    47),  INT8_C(    79),  INT8_C(    68),
        -INT8_C(    40),  INT8_C(    62),  INT8_C(   119),  INT8_C(    75) },
      { -INT8_C(    77),  INT8_C(    70),  INT8_C(    64),  INT8_C(    54),
         INT8_C(    95),  INT8_C(     0),  INT8_C(    81),  INT8_C(    97),
         INT8_C(    24), -INT8_C(    47),  INT8_C(    79),  INT8_C(    68),
        -INT8_C(    40),  INT8_C(    62),  INT8_C(   119),  INT8_C(    75) },
      { -INT8_C(    77),  INT8_C(    70),  INT8_C(    64),  INT8_C(    54),
         INT8_C(    95),  INT8_C(     0),  INT8_C(    81),  INT8_C(     7),
         INT8_C(    24), -INT8_C(    47),  INT8_C(    79),  INT8_C(    46),
        -INT8_C(    40),  INT8_C(    62),  INT8_C(   119),  INT8_C(    75) },
      { -INT8_C(    77),  INT8_C(    70),  INT8_C(    64),  INT8_C(    54),
         INT8_C(    95),  INT8_C(     0),  INT8_C(    81),  INT8_C(     7),
         INT8_C(    24), -INT8_C(    47),  INT8_C(    79),  INT8_C(    68),
        -INT8_C(    40),  INT8_C(    62),  INT8_C(   119), -INT8_C(    23) } },
    { {  INT8_C(    92), -INT8_C(   112), -INT8_C(    75),  INT8_C(    88),
         INT8_C(    84), -INT8_C(    15),  INT8_C(    41), -INT8_C(    66),
         INT8_C(    45), -INT8_C(    70), -INT8_C(    35), -INT8_C(   113),
        -INT8_C(     9), -INT8_C(    89), -INT8_C(     8), -INT8_C(    15) },
      { -INT8_C(    97),  INT8_C(   123),  INT8_C(    16), -INT8_C(    91),
        -INT8_C(    99),  INT8_C(    56), -INT8_C(    45), -INT8_C(    55),
        -INT8_C(    10), -INT8_C(   123), -INT8_C(     7),  INT8_C(    80),
         INT8_C(   101),  INT8_C(    44), -INT8_C(    15),  INT8_C(    84) },
      {  INT8_C(    84), -INT8_C(   112), -INT8_C(    75),  INT8_C(    88),
         INT8_C(    84), -INT8_C(    15),  INT8_C(    41), -INT8_C(    66),
         INT8_C(    45), -INT8_C(    70), -INT8_C(    35), -INT8_C(   113),
        -INT8_C(     9), -INT8_C(    89), -INT8_C(     8), -INT8_C(    15) },
      {  INT8_C(    92), -INT8_C(   112), -INT8_C(    75),  INT8_C(   101),
         INT8_C(    84), -INT8_C(    15),  INT8_C(    41), -INT8_C(    66),
         INT8_C(    45), -INT8_C(    70), -INT8_C(    35), -INT8_C(   113),
        -INT8_C(     9), -INT8_C(    89), -INT8_C(     8), -INT8_C(    15) },
      {  INT8_C(    92), -INT8_C(   112), -INT8_C(    75),  INT8_C(    88),
         INT8_C(    84), -INT8_C(    15),  INT8_C(    41), -INT8_C(    10),
         INT8_C(    45), -INT8_C(    70), -INT8_C(    35), -INT8_C(   113),
        -INT8_C(     9), -INT8_C(    89), -INT8_C(     8), -INT8_C(    15) },
      {  INT8_C(    92), -INT8_C(   112), -INT8_C(    75),  INT8_C(    88),
         INT8_C(    84), -INT8_C(    15),  INT8_C(    41), -INT8_C(    66),
         INT8_C(    45), -INT8_C(    70), -INT8_C(    35), -INT8_C(    99),
        -INT8_C(     9), -INT8_C(    89), -INT8_C(     8), -INT8_C(    15) },
      {  INT8_C(    92), -INT8_C(   112), -INT8_C(    75),  INT8_C(    88),
         INT8_C(    84), -INT8_C(    15),  INT8_C(    41), -INT8_C(    66),
         INT8_C(    45), -INT8_C(    70), -INT8_C(    35), -INT8_C(   113),
        -INT8_C(     9), -INT8_C(    89), -INT8_C(     8),  INT8_C(   123) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);

    simde_int8x16_t r0_15 = simde_vcopyq_laneq_s8(a, 0, b, 15);
    simde_int8x16_t r3_12 = simde_vcopyq_laneq_s8(a, 3, b, 12);
    simde_int8x16_t r7_8 = simde_vcopyq_laneq_s8(a, 7, b, 8);
    simde_int8x16_t r11_4 = simde_vcopyq_laneq_s8(a, 11, b, 4);
    simde_int8x16_t r15_1 = simde_vcopyq_laneq_s8(a, 15, b, 1);

    simde_test_arm_neon_assert_equal_i8x16(r0_15, simde_vld1q_s8(test_vec[i].r0_15));
    simde_test_arm_neon_assert_equal_i8x16(r3_12, simde_vld1q_s8(test_vec[i].r3_12));
    simde_test_arm_neon_assert_equal_i8x16(r7_8, simde_vld1q_s8(test_vec[i].r7_8));
    simde_test_arm_neon_assert_equal_i8x16(r11_4, simde_vld1q_s8(test_vec[i].r11_4));
    simde_test_arm_neon_assert_equal_i8x16(r15_1, simde_vld1q_s8(test_vec[i].r15_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r0_15 = simde_vcopyq_laneq_s8(a, 0, b, 15);
    simde_int8x16_t r3_12 = simde_vcopyq_laneq_s8(a, 3, b, 12);
    simde_int8x16_t r7_8 = simde_vcopyq_laneq_s8(a, 7, b, 8);
    simde_int8x16_t r11_4 = simde_vcopyq_laneq_s8(a, 11, b, 4);
    simde_int8x16_t r15_1 = simde_vcopyq_laneq_s8(a, 15, b, 1);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r0_15, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r3_12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r7_8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r11_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r15_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcopyq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r0_7[8];
    int16_t r1_6[8];
    int16_t r3_4[8];
    int16_t r5_3[8];
    int16_t r7_1[8];
  } test_vec[] = {
    { { -INT16_C(   16276),  INT16_C(   11398), -INT16_C(   29409), -INT16_C(   27267),
        -INT16_C(    7128), -INT16_C(   21139),  INT16_C(   13269),  INT16_C(   12401) },
      {  INT16_C(    9098),  INT16_C(   20041),  INT16_C(   26801), -INT16_C(   20544),
         INT16_C(    3157),  INT16_C(   28134),  INT16_C(   11263), -INT16_C(   28347) },
      { -INT16_C(   28347),  INT16_C(   11398), -INT16_C(   29409), -INT16_C(   27267),
        -INT16_C(    7128), -INT16_C(   21139),  INT16_C(   13269),  INT16_C(   12401) },
      { -INT16_C(   16276),  INT16_C(   11263), -INT16_C(   29409), -INT16_C(   27267),
        -INT16_C(    7128), -INT16_C(   21139),  INT16_C(   13269),  INT16_C(   12401) },
      { -INT16_C(   16276),  INT16_C(   11398), -INT16_C(   29409),  INT16_C(    3157),
        -INT16_C(    7128), -INT16_C(   21139),  INT16_C(   13269),  INT16_C(   12401) },
      { -INT16_C(   16276),  INT16_C(   11398), -INT16_C(   29409), -INT16_C(   27267),
        -INT16_C(    7128), -INT16_C(   20544),  INT16_C(   13269),  INT16_C(   12401) },
      { -INT16_C(   16276),  INT16_C(   11398), -INT16_C(   29409), -INT16_C(   27267),
        -INT16_C(    7128), -INT16_C(   21139),  INT16_C(   13269),  INT16_C(   20041) } },
    { {  INT16_C(    1776),  INT16_C(   18106),  INT16_C(    3726),  INT16_C(   10406),
        -INT16_C(   25792), -INT16_C(    1873),  INT16_C(    8778), -INT16_C(   32635) },
      { -INT16_C(   22146), -INT16_C(   16595),  INT16_C(    1633),  INT16_C(   16850),
         INT16_C(     108),  INT16_C(   17026), -INT16_C(    4147), -INT16_C(   13132) },
      { -INT16_C(   13132),  INT16_C(   18106),  INT16_C(    3726),  INT16_C(   10406),
        -INT16_C(   25792), -INT16_C(    1873),  INT16_C(    8778), -INT16_C(   32635) },
      {  INT16_C(    1776), -INT16_C(    4147),  INT16_C(    3726),  INT16_C(   10406),
        -INT16_C(   25792), -INT16_C(    1873),  INT16_C(    8778), -INT16_C(   32635) },
      {  INT16_C(    1776),  INT16_C(   18106),  INT16_C(    3726),  INT16_C(     108),
        -INT16_C(   25792), -INT16_C(    1873),  INT16_C(    8778), -INT16_C(   32635) },
      {  INT16_C(    1776),  INT16_C(   18106),  INT16_C(    3726),  INT16_C(   10406),
        -INT16_C(   25792),  INT16_C(   16850),  INT16_C(    8778), -INT16_C(   32635) },
      {  INT16_C(    1776),  INT16_C(   18106),  INT16_C(    3726),  INT16_C(   10406),
        -INT16_C(   25792), -INT16_C(    1873),  INT16_C(    8778), -INT16_C(   16595) } },
    { { -INT16_C(   21426), -INT16_C(    5480),  INT16_C(   21409), -INT16_C(   32739),
         INT16_C(   19414), -INT16_C(   30534), -INT16_C(    8998), -INT16_C(   18036) },
      {  INT16_C(   19199), -INT16_C(   12691), -INT16_C(    7618),  INT16_C(   21179),
         INT16_C(    9688),  INT16_C(    5616),  INT16_C(   23519), -INT16_C(   22371) },
      { -INT16_C(   22371), -INT16_C(    5480),  INT16_C(   21409), -INT16_C(   32739),
         INT16_C(   19414), -INT16_C(   30534), -INT16_C(    8998), -INT16_C(   18036) },
      { -INT16_C(   21426),  INT16_C(   23519),  INT16_C(   21409), -INT16_C(   32739),
         INT16_C(   19414), -INT16_C(   30534), -INT16_C(    8998), -INT16_C(   18036) },
      { -INT16_C(   21426), -INT16_C(    5480),  INT16_C(   21409),  INT16_C(    9688),
         INT16_C(   19414), -INT16_C(   30534), -INT16_C(    8998), -INT16_C(   18036) },
      { -INT16_C(   21426), -INT16_C(    5480),  INT16_C(   21409), -INT16_C(   32739),
         INT16_C(   19414),  INT16_C(   21179), -INT16_C(    8998), -INT16_C(   18036) },
      { -INT16_C(   21426), -INT16_C(    5480),  INT16_C(   21409), -INT16_C(   32739),
         INT16_C(   19414), -INT16_C(   30534), -INT16_C(    8998), -INT16_C(   12691) } },
    { {  INT16_C(   11127),  INT16_C(    4281),  INT16_C(    8108), -INT16_C(   11718),
        -INT16_C(    8689), -INT16_C(   17258),  INT16_C(    2511),  INT16_C(    3672) },
      { -INT16_C(   29705),  INT16_C(   24574), -INT16_C(    8515),  INT16_C(   25788),
         INT16_C(    9031), -INT16_C(   32656),  INT16_C(   18167), -INT16_C(    3569) },
      { -INT16_C(    3569),  INT16_C(    4281),  INT16_C(    8108), -INT16_C(   11718),
        -INT16_C(    8689), -INT16_C(   17258),  INT16_C(    2511),  INT16_C(    3672) },
      {  INT16_C(   11127),  INT16_C(   18167),  INT16_C(    8108), -INT16_C(   11718),
        -INT16_C(    8689), -INT16_C(   17258),  INT16_C(    2511),  INT16_C(    3672) },
      {  INT16_C(   11127),  INT16_C(    4281),  INT16_C(    8108),  INT16_C(    9031),
        -INT16_C(    8689), -INT16_C(   17258),  INT16_C(    2511),  INT16_C(    3672) },
      {  INT16_C(   11127),  INT16_C(    4281),  INT16_C(    8108), -INT16_C(   11718),
        -INT16_C(    8689),  INT16_C(   25788),  INT16_C(    2511),  INT16_C(    3672) },
      {  INT16_C(   11127),  INT16_C(    4281),  INT16_C(    8108), -INT16_C(   11718),
        -INT16_C(    8689), -INT16_C(   17258),  INT16_C(    2511),  INT16_C(   24574) } },
    { {  INT16_C(    2598),  INT16_C(   13531),  INT16_C(   24973), -INT16_C(   27774),
        -INT16_C(   25114),  INT16_C(   10082),  INT16_C(    3018),  INT16_C(   11447) },
      { -INT16_C(   29304),  INT16_C(   22734),  INT16_C(    1386),  INT16_C(   29640),
        -INT16_C(   27220),  INT16_C(   20656),  INT16_C(   20884), -INT16_C(   29958) },
      { -INT16_C(   29958),  INT16_C(   13531),  INT16_C(   24973), -INT16_C(   27774),
        -INT16_C(   25114),  INT16_C(   10082),  INT16_C(    3018),  INT16_C(   11447) },
      {  INT16_C(    2598),  INT16_C(   20884),  INT16_C(   24973), -INT16_C(   27774),
        -INT16_C(   25114),  INT16_C(   10082),  INT16_C(    3018),  INT16_C(   11447) },
      {  INT16_C(    2598),  INT16_C(   13531),  INT16_C(   24973), -INT16_C(   27220),
        -INT16_C(   25114),  INT16_C(   10082),  INT16_C(    3018),  INT16_C(   11447) },
      {  INT16_C(    2598),  INT16_C(   13531),  INT16_C(   24973), -INT16_C(   27774),
        -INT16_C(   25114),  INT16_C(   29640),  INT16_C(    3018),  INT16_C(   11447) },
      {  INT16_C(    2598),  INT16_C(   13531),  INT16_C(   24973), -INT16_C(   27774),
        -INT16_C(   25114),  INT16_C(   10082),  INT16_C(    3018),  INT16_C(   22734) } },
    { {  INT16_C(   26821), -INT16_C(   29427), -INT16_C(   29199), -INT16_C(   23310),
         INT16_C(   19461),  INT16_C(   28471),  INT16_C(   17652),  INT16_C(    8495) },
      {  INT16_C(    1907),  INT16_C(    9481),  INT16_C(   17372),  INT16_C(   27351),
         INT16_C(   27913),  INT16_C(   15194), -INT16_C(    9916), -INT16_C(   22787) },
      { -INT16_C(   22787), -INT16_C(   29427), -INT16_C(   29199), -INT16_C(   23310),
         INT16_C(   19461),  INT16_C(   28471),  INT16_C(   17652),  INT16_C(    8495) },
      {  INT16_C(   26821), -INT16_C(    9916), -INT16_C(   29199), -INT16_C(   23310),
         INT16_C(   19461),  INT16_C(   28471),  INT16_C(   17652),  INT16_C(    8495) },
      {  INT16_C(   26821), -INT16_C(   29427), -INT16_C(   29199),  INT16_C(   27913),
         INT16_C(   19461),  INT16_C(   28471),  INT16_C(   17652),  INT16_C(    8495) },
      {  INT16_C(   26821), -INT16_C(   29427), -INT16_C(   29199), -INT16_C(   23310),
         INT16_C(   19461),  INT16_C(   27351),  INT16_C(   17652),  INT16_C(    8495) },
      {  INT16_C(   26821), -INT16_C(   29427), -INT16_C(   29199), -INT16_C(   23310),
         INT16_C(   19461),  INT16_C(   28471),  INT16_C(   17652),  INT16_C(    9481) } },
    { { -INT16_C(   22367), -INT16_C(   26006), -INT16_C(   14130),  INT16_C(   29416),
         INT16_C(    9288), -INT16_C(   19099), -INT16_C(   19470), -INT16_C(   17968) },
      { -INT16_C(   12254),  INT16_C(     844),  INT16_C(   32114),  INT16_C(    8794),
        -INT16_C(   12642), -INT16_C(   21136), -INT16_C(   16890),  INT16_C(   25350) },
      {  INT16_C(   25350), -INT16_C(   26006), -INT16_C(   14130),  INT16_C(   29416),
         INT16_C(    9288), -INT16_C(   19099), -INT16_C(   19470), -INT16_C(   17968) },
      { -INT16_C(   22367), -INT16_C(   16890), -INT16_C(   14130),  INT16_C(   29416),
         INT16_C(    9288), -INT16_C(   19099), -INT16_C(   19470), -INT16_C(   17968) },
      { -INT16_C(   22367), -INT16_C(   26006), -INT16_C(   14130), -INT16_C(   12642),
         INT16_C(    9288), -INT16_C(   19099), -INT16_C(   19470), -INT16_C(   17968) },
      { -INT16_C(   22367), -INT16_C(   26006), -INT16_C(   14130),  INT16_C(   29416),
         INT16_C(    9288),  INT16_C(    8794), -INT16_C(   19470), -INT16_C(   17968) },
      { -INT16_C(   22367), -INT16_C(   26006), -INT16_C(   14130),  INT16_C(   29416),
         INT16_C(    9288), -INT16_C(   19099), -INT16_C(   19470),  INT16_C(     844) } },
    { { -INT16_C(    4687), -INT16_C(     685),  INT16_C(   32290),  INT16_C(    8754),
        -INT16_C(    4611), -INT16_C(    6814), -INT16_C(    8711),  INT16_C(   31457) },
      {  INT16_C(   14971),  INT16_C(   27437),  INT16_C(    6885),  INT16_C(   11065),
         INT16_C(    8411), -INT16_C(   31180),  INT16_C(   29285), -INT16_C(   24834) },
      { -INT16_C(   24834), -INT16_C(     685),  INT16_C(   32290),  INT16_C(    8754),
        -INT16_C(    4611), -INT16_C(    6814), -INT16_C(    8711),  INT16_C(   31457) },
      { -INT16_C(    4687),  INT16_C(   29285),  INT16_C(   32290),  INT16_C(    8754),
        -INT16_C(    4611), -INT16_C(    6814), -INT16_C(    8711),  INT16_C(   31457) },
      { -INT16_C(    4687), -INT16_C(     685),  INT16_C(   32290),  INT16_C(    8411),
        -INT16_C(    4611), -INT16_C(    6814), -INT16_C(    8711),  INT16_C(   31457) },
      { -INT16_C(    4687), -INT16_C(     685),  INT16_C(   32290),  INT16_C(    8754),
        -INT16_C(    4611),  INT16_C(   11065), -INT16_C(    8711),  INT16_C(   31457) },
      { -INT16_C(    4687), -INT16_C(     685),  INT16_C(   32290),  INT16_C(    8754),
        -INT16_C(    4611), -INT16_C(    6814), -INT16_C(    8711),  INT16_C(   27437) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x8_t r0_7 = simde_vcopyq_laneq_s16(a, 0, b, 7);
    simde_int16x8_t r1_6 = simde_vcopyq_laneq_s16(a, 1, b, 6);
    simde_int16x8_t r3_4 = simde_vcopyq_laneq_s16(a, 3, b, 4);
    simde_int16x8_t r5_3 = simde_vcopyq_laneq_s16(a, 5, b, 3);
    simde_int16x8_t r7_1 = simde_vcopyq_laneq_s16(a, 7, b, 1);

    simde_test_arm_neon_assert_equal_i16x8(r0_7, simde_vld1q_s16(test_vec[i].r0_7));
    simde_test_arm_neon_assert_equal_i16x8(r1_6, simde_vld1q_s16(test_vec[i].r1_6));
    simde_test_arm_neon_assert_equal_i16x8(r3_4, simde_vld1q_s16(test_vec[i].r3_4));
    simde_test_arm_neon_assert_equal_i16x8(r5_3, simde_vld1q_s16(test_vec[i].r5_3));
    simde_test_arm_neon_assert_equal_i16x8(r7_1, simde_vld1q_s16(test_vec[i].r7_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r0_7 = simde_vcopyq_laneq_s16(a, 0, b, 7);
    simde_int16x8_t r1_6 = simde_vcopyq_laneq_s16(a, 1, b, 6);
    simde_int16x8_t r3_4 = simde_vcopyq_laneq_s16(a, 3, b, 4);
    simde_int16x8_t r5_3 = simde_vcopyq_laneq_s16(a, 5, b, 3);
    simde_int16x8_t r7_1 = simde_vcopyq_laneq_s16(a, 7, b, 1);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r0_7, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r1_6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r5_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r7_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r0_3[4];
    int32_t r1_2[4];
    int32_t r2_1[4];
    int32_t r3_0[4];
  } test_vec[] = {
    { { -INT32_C(  1892583197), -INT32_C(   225454004),  INT32_C(  1008306445),  INT32_C(  1245890578) },
      {  INT32_C(   731542339), -INT32_C(   857053337),  INT32_C(  1016225573),  INT32_C(  1824087776) },
      {  INT32_C(  1824087776), -INT32_C(   225454004),  INT32_C(  1008306445),  INT32_C(  1245890578) },
      { -INT32_C(  1892583197),  INT32_C(  1016225573),  INT32_C(  1008306445),  INT32_C(  1245890578) },
      { -INT32_C(  1892583197), -INT32_C(   225454004), -INT32_C(   857053337),  INT32_C(  1245890578) },
      { -INT32_C(  1892583197), -INT32_C(   225454004),  INT32_C(  1008306445),  INT32_C(   731542339) } },
    { {  INT32_C(  1600614011),  INT32_C(   240019305), -INT32_C(  2019582847), -INT32_C(   562177638) },
      { -INT32_C(    73458434),  INT32_C(   715226345), -INT32_C(  1660159717),  INT32_C(  1203496468) },
      {  INT32_C(  1203496468),  INT32_C(   240019305), -INT32_C(  2019582847), -INT32_C(   562177638) },
      {  INT32_C(  1600614011), -INT32_C(  1660159717), -INT32_C(  2019582847), -INT32_C(   562177638) },
      {  INT32_C(  1600614011),  INT32_C(   240019305),  INT32_C(   715226345), -INT32_C(   562177638) },
      {  INT32_C(  1600614011),  INT32_C(   240019305), -INT32_C(  2019582847), -INT32_C(    73458434) } },
    { {  INT32_C(  1778478051),  INT32_C(   630029678),  INT32_C(  1918387593), -INT32_C(   898166499) },
      { -INT32_C(  2070028428), -INT32_C(  1057493739), -INT32_C(  1053820267), -INT32_C(   464877709) },
      { -INT32_C(   464877709),  INT32_C(   630029678),  INT32_C(  1918387593), -INT32_C(   898166499) },
      {  INT32_C(  1778478051), -INT32_C(  1053820267),  INT32_C(  1918387593), -INT32_C(   898166499) },
      {  INT32_C(  1778478051),  INT32_C(   630029678), -INT32_C(  1057493739), -INT32_C(   898166499) },
      {  INT32_C(  1778478051),  INT32_C(   630029678),  INT32_C(  1918387593), -INT32_C(  2070028428) } },
    { { -INT32_C(  1933730243), -INT32_C(   179719064), -INT32_C(  1680784440), -INT32_C(   269744068) },
      {  INT32_C(   627798432),  INT32_C(   622441545), -INT32_C(  1933882589), -INT32_C(  1310730543) },
      { -INT32_C(  1310730543), -INT32_C(   179719064), -INT32_C(  1680784440), -INT32_C(   269744068) },
      { -INT32_C(  1933730243), -INT32_C(  1933882589), -INT32_C(  1680784440), -INT32_C(   269744068) },
      { -INT32_C(  1933730243), -INT32_C(   179719064),  INT32_C(   622441545), -INT32_C(   269744068) },
      { -INT32_C(  1933730243), -INT32_C(   179719064), -INT32_C(  1680784440),  INT32_C(   627798432) } },
    { {  INT32_C(  2089054990), -INT32_C(   800367284),  INT32_C(   604869219), -INT32_C(  1842421805) },
      { -INT32_C(  1206028316), -INT32_C(  1825846196), -INT32_C(   677690043),  INT32_C(   938506212) },
      {  INT32_C(   938506212), -INT32_C(   800367284),  INT32_C(   604869219), -INT32_C(  1842421805) },
      {  INT32_C(  2089054990), -INT32_C(   677690043),  INT32_C(   604869219), -INT32_C(  1842421805) },
      {  INT32_C(  2089054990), -INT32_C(   800367284), -INT32_C(  1825846196), -INT32_C(  1842421805) },
      {  INT32_C(  2089054990), -INT32_C(   800367284),  INT32_C(   604869219), -INT32_C(  1206028316) } },
    { {  INT32_C(  1368055385),  INT32_C(  1200632878), -INT32_C(  1243554760), -INT32_C(  1709345942) },
      { -INT32_C(  1279975680),  INT32_C(    97226001),  INT32_C(  1718562473), -INT32_C(   150019811) },
      { -INT32_C(   150019811),  INT32_C(  1200632878), -INT32_C(  1243554760), -INT32_C(  1709345942) },
      {  INT32_C(  1368055385),  INT32_C(  1718562473), -INT32_C(  1243554760), -INT32_C(  1709345942) },
      {  INT32_C(  1368055385),  INT32_C(  1200632878),  INT32_C(    97226001), -INT32_C(  1709345942) },
      {  INT32_C(  1368055385),  INT32_C(  1200632878), -INT32_C(  1243554760), -INT32_C(  1279975680) } },
    { {  INT32_C(  1816126290), -INT32_C(   227914872), -INT32_C(   964882524),  INT32_C(  1928245859) },
      { -INT32_C(   112086283),  INT32_C(   873557272), -INT32_C(   470253178), -INT32_C(   654993104) },
      { -INT32_C(   654993104), -INT32_C(   227914872), -INT32_C(   964882524),  INT32_C(  1928245859) },
      {  INT32_C(  1816126290), -INT32_C(   470253178), -INT32_C(   964882524),  INT32_C(  1928245859) },
      {  INT32_C(  1816126290), -INT32_C(   227914872),  INT32_C(   873557272),  INT32_C(  1928245859) },
      {  INT32_C(  1816126290), -INT32_C(   227914872), -INT32_C(   964882524), -INT32_C(   112086283) } },
    { {  INT32_C(   562043715), -INT32_C(   106864670), -INT32_C(  1846548877),  INT32_C(  1744408579) },
      { -INT32_C(   774102303), -INT32_C(  1452959164), -INT32_C(   490774966), -INT32_C(  2057123680) },
      { -INT32_C(  2057123680), -INT32_C(   106864670), -INT32_C(  1846548877),  INT32_C(  1744408579) },
      {  INT32_C(   562043715), -INT32_C(   490774966), -INT32_C(  1846548877),  INT32_C(  1744408579) },
      {  INT32_C(   562043715), -INT32_C(   106864670), -INT32_C(  1452959164),  INT32_C(  1744408579) },
      {  INT32_C(   562043715), -INT32_C(   106864670), -INT32_C(  1846548877), -INT32_C(   774102303) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x4_t r0_3 = simde_vcopyq_laneq_s32(a, 0, b, 3);
    simde_int32x4_t r1_2 = simde_vcopyq_laneq_s32(a, 1, b, 2);
    simde_int32x4_t r2_1 = simde_vcopyq_laneq_s32(a, 2, b, 1);
    simde_int32x4_t r3_0 = simde_vcopyq_laneq_s32(a, 3, b, 0);

    simde_test_arm_neon_assert_equal_i32x4(r0_3, simde_vld1q_s32(test_vec[i].r0_3));
    simde_test_arm_neon_assert_equal_i32x4(r1_2, simde_vld1q_s32(test_vec[i].r1_2));
    simde_test_arm_neon_assert_equal_i32x4(r2_1, simde_vld1q_s32(test_vec[i].r2_1));
    simde_test_arm_neon_assert_equal_i32x4(r3_0, simde_vld1q_s32(test_vec[i].r3_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r0_3 = simde_vcopyq_laneq_s32(a, 0, b, 3);
    simde_int32x4_t r1_2 = simde_vcopyq_laneq_s32(a, 1, b, 2);
    simde_int32x4_t r2_1 = simde_vcopyq_laneq_s32(a, 2, b, 1);
    simde_int32x4_t r3_0 = simde_vcopyq_laneq_s32(a, 3, b, 0);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r0_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r1_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r2_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r3_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r0_0[2];
    int64_t r0_1[2];
    int64_t r1_0[2];
    int64_t r1_1[2];
  } test_vec[] = {
    { { -INT64_C(  475864847648919097),  INT64_C( 8417644638487745847) },
      {  INT64_C( 9182198556432984409),  INT64_C( 6177027272280840895) },
      {  INT64_C( 9182198556432984409),  INT64_C( 8417644638487745847) },
      {  INT64_C( 6177027272280840895),  INT64_C( 8417644638487745847) },
      { -INT64_C(  475864847648919097),  INT64_C( 9182198556432984409) },
      { -INT64_C(  475864847648919097),  INT64_C( 6177027272280840895) } },
    { { -INT64_C( 8929020168002432621), -INT64_C( 4477976040726240340) },
      {  INT64_C( 5692018566259932777),  INT64_C( 4316779177536635438) },
      {  INT64_C( 5692018566259932777), -INT64_C( 4477976040726240340) },
      {  INT64_C( 4316779177536635438), -INT64_C( 4477976040726240340) },
      { -INT64_C( 8929020168002432621),  INT64_C( 5692018566259932777) },
      { -INT64_C( 8929020168002432621),  INT64_C( 4316779177536635438) } },
    { {  INT64_C( 4763414794636474503),  INT64_C(  462179614187538409) },
      {  INT64_C( 7917706878421569084), -INT64_C( 5171000984489091865) },
      {  INT64_C( 7917706878421569084),  INT64_C(  462179614187538409) },
      { -INT64_C( 5171000984489091865),  INT64_C(  462179614187538409) },
      {  INT64_C( 4763414794636474503),  INT64_C( 7917706878421569084) },
      {  INT64_C( 4763414794636474503), -INT64_C( 5171000984489091865) } },
    { { -INT64_C(  655109288458667793), -INT64_C(  337451926488198107) },
      { -INT64_C( 7854309330387571658),  INT64_C( 8420743667125891946) },
      { -INT64_C( 7854309330387571658), -INT64_C(  337451926488198107) },
      {  INT64_C( 8420743667125891946), -INT64_C(  337451926488198107) },
      { -INT64_C(  655109288458667793), -INT64_C( 7854309330387571658) },
      { -INT64_C(  655109288458667793),  INT64_C( 8420743667125891946) } },
    { { -INT64_C( 6164247547247293913),  INT64_C( 2253183027365453726) },
      { -INT64_C( 1821736987801891187), -INT64_C( 5278162077788122669) },
      { -INT64_C( 1821736987801891187),  INT64_C( 2253183027365453726) },
      { -INT64_C( 5278162077788122669),  INT64_C( 2253183027365453726) },
      { -INT64_C( 6164247547247293913), -INT64_C( 1821736987801891187) },
      { -INT64_C( 6164247547247293913), -INT64_C( 5278162077788122669) } },
    { { -INT64_C( 8639413444708581833), -INT64_C( 5606583741094413314) },
      {  INT64_C( 5140422082660112584), -INT64_C( 3884945958717385980) },
      {  INT64_C( 5140422082660112584), -INT64_C( 5606583741094413314) },
      { -INT64_C( 3884945958717385980), -INT64_C( 5606583741094413314) },
      { -INT64_C( 8639413444708581833),  INT64_C( 5140422082660112584) },
      { -INT64_C( 8639413444708581833), -INT64_C( 3884945958717385980) } },
    { {  INT64_C( 9084394517336304795), -INT64_C( 5982763725163385905) },
      { -INT64_C( 8482304762806811342),  INT64_C( 8203438312388876529) },
      { -INT64_C( 8482304762806811342), -INT64_C( 5982763725163385905) },
      {  INT64_C( 8203438312388876529), -INT64_C( 5982763725163385905) },
      {  INT64_C( 9084394517336304795), -INT64_C( 8482304762806811342) },
      {  INT64_C( 9084394517336304795),  INT64_C( 8203438312388876529) } },
    { {  INT64_C( 1616920090545660434),  INT64_C( 2830530565097296736) },
      { -INT64_C( 6774932576689688966),  INT64_C( 4252959599116308083) },
      { -INT64_C( 6774932576689688966),  INT64_C( 2830530565097296736) },
      {  INT64_C( 4252959599116308083),  INT64_C( 2830530565097296736) },
      {  INT64_C( 1616920090545660434), -INT64_C( 6774932576689688966) },
      {  INT64_C( 1616920090545660434),  INT64_C( 4252959599116308083) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);

    simde_int64x2_t r0_0 = simde_vcopyq_laneq_s64(a, 0, b, 0);
    simde_int64x2_t r0_1 = simde_vcopyq_laneq_s64(a, 0, b, 1);
    simde_int64x2_t r1_0 = simde_vcopyq_laneq_s64(a, 1, b, 0);
    simde_int64x2_t r1_1 = simde_vcopyq_laneq_s64(a, 1, b, 1);

    simde_test_arm_neon_assert_equal_i64x2(r0_0, simde_vld1q_s64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_i64x2(r0_1, simde_vld1q_s64(test_vec[i].r0_1));
    simde_test_arm_neon_assert_equal_i64x2(r1_0, simde_vld1q_s64(test_vec[i].r1_0));
    simde_test_arm_neon_assert_equal_i64x2(r1_1, simde_vld1q_s64(test_vec[i].r1_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r0_0 = simde_vcopyq_laneq_s64(a, 0, b, 0);
    simde_int64x2_t r0_1 = simde_vcopyq_laneq_s64(a, 0, b, 1);
    simde_int64x2_t r1_0 = simde_vcopyq_laneq_s64(a, 1, b, 0);
    simde_int64x2_t r1_1 = simde_vcopyq_laneq_s64(a, 1, b, 1);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r0_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r1_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r1_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r0_15[16];
    uint8_t r3_12[16];
    uint8_t r7_8[16];
    uint8_t r11_4[16];
    uint8_t r15_1[16];
  } test_vec[] = {
    { {  UINT8_C(  246),  UINT8_C(  247),  UINT8_C(  144),  UINT8_C(   17),
         UINT8_C(  184),  UINT8_C(  243),  UINT8_C(  185),  UINT8_C(  150),
         UINT8_C(   75),  UINT8_C(   48),  UINT8_C(  193),  UINT8_C(   93),
         UINT8_C(  178),  UINT8_C(  223),  UINT8_C(  110),  UINT8_C(  228) },
      {  UINT8_C(  163),  UINT8_C(  179),  UINT8_C(  104),  UINT8_C(  196),
         UINT8_C(  232),  UINT8_C(   51),  UINT8_C(  215),  UINT8_C(  174),
         UINT8_C(   37),  UINT8_C(  181),  UINT8_C(   16),  UINT8_C(  157),
         UINT8_C(   67),  UINT8_C(  118),  UINT8_C(  181),  UINT8_C(   84) },
      {  UINT8_C(   84),  UINT8_C(  247),  UINT8_C(  144),  UINT8_C(   17),
         UINT8_C(  184),  UINT8_C(  243),  UINT8_C(  185),  UINT8_C(  150),
         UINT8_C(   75),  UINT8_C(   48),  UINT8_C(  193),  UINT8_C(   93),
         UINT8_C(  178),  UINT8_C(  223),  UINT8_C(  110),  UINT8_C(  228) },
      {  UINT8_C(  246),  UINT8_C(  247),  UINT8_C(  144),  UINT8_C(   67),
         UINT8_C(  184),  UINT8_C(  243),  UINT8_C(  185),  UINT8_C(  150),
         UINT8_C(   75),  UINT8_C(   48),  UINT8_C(  193),  UINT8_C(   93),
         UINT8_C(  178),  UINT8_C(  223),  UINT8_C(  110),  UINT8_C(  228) },
      {  UINT8_C(  246),  UINT8_C(  247),  UINT8_C(  144),  UINT8_C(   17),
         UINT8_C(  184),  UINT8_C(  243),  UINT8_C(  185),  UINT8_C(   37),
         UINT8_C(   75),  UINT8_C(   48),  UINT8_C(  193),  UINT8_C(   93),
         UINT8_C(  178),  UINT8_C(  223),  UINT8_C(  110),  UINT8_C(  228) },
      {  UINT8_C(  246),  UINT8_C(  247),  UINT8_C(  144),  UINT8_C(   17),
         UINT8_C(  184),  UINT8_C(  243),  UINT8_C(  185),  UINT8_C(  150),
         UINT8_C(   75),  UINT8_C(   48),  UINT8_C(  193),  UINT8_C(  232),
         UINT8_C(  178),  UINT8_C(  223),  UINT8_C(  110),  UINT8_C(  228) },
      {  UINT8_C(  246),  UINT8_C(  247),  UINT8_C(  144),  UINT8_C(   17),
         UINT8_C(  184),  UINT8_C(  243),  UINT8_C(  185),  UINT8_C(  150),
         UINT8_C(   75),  UINT8_C(   48),  UINT8_C(  193),  UINT8_C(   93),
         UINT8_C(  178),  UINT8_C(  223),  UINT8_C(  110),  UINT8_C(  179) } },
    { {  UINT8_C(   33),  UINT8_C(  229),  UINT8_C(   20),  UINT8_C(  122),
         UINT8_C(  136),  UINT8_C(   32),  UINT8_C(  196),  UINT8_C(   45),
         UINT8_C(   56),  UINT8_C(  169),  UINT8_C(  181),  UINT8_C(  147),
         UINT8_C(  247),  UINT8_C(  103),  UINT8_C(  243),  UINT8_C(  241) },
      {  UINT8_C(   56),  UINT8_C(  173),  UINT8_C(   83),  UINT8_C(   20),
         UINT8_C(  151),  UINT8_C(  249),  UINT8_C(  195),  UINT8_C(  179),
         UINT8_C(   11),  UINT8_C(   61),  UINT8_C(   82),  UINT8_C(  120),
         UINT8_C(   20),  UINT8_C(  192),  UINT8_C(   93),  UINT8_C(  178) },
      {  UINT8_C(  178),  UINT8_C(  229),  UINT8_C(   20),  UINT8_C(  122),
         UINT8_C(  136),  UINT8_C(   32),  UINT8_C(  196),  UINT8_C(   45),
         UINT8_C(   56),  UINT8_C(  169),  UINT8_C(  181),  UINT8_C(  147),
         UINT8_C(  247),  UINT8_C(  103),  UINT8_C(  243),  UINT8_C(  241) },
      {  UINT8_C(   33),  UINT8_C(  229),  UINT8_C(   20),  UINT8_C(   20),
         UINT8_C(  136),  UINT8_C(   32),  UINT8_C(  196),  UINT8_C(   45),
         UINT8_C(   56),  UINT8_C(  169),  UINT8_C(  181),  UINT8_C(  147),
         UINT8_C(  247),  UINT8_C(  103),  UINT8_C(  243),  UINT8_C(  241) },
      {  UINT8_C(   33),  UINT8_C(  229),  UINT8_C(   20),  UINT8_C(  122),
         UINT8_C(  136),  UINT8_C(   32),  UINT8_C(  196),  UINT8_C(   11),
         UINT8_C(   56),  UINT8_C(  169),  UINT8_C(  181),  UINT8_C(  147),
         UINT8_C(  247),  UINT8_C(  103),  UINT8_C(  243),  UINT8_C(  241) },
      {  UINT8_C(   33),  UINT8_C(  229),  UINT8_C(   20),  UINT8_C(  122),
         UINT8_C(  136),  UINT8_C(   32),  UINT8_C(  196),  UINT8_C(   45),
         UINT8_C(   56),  UINT8_C(  169),  UINT8_C(  181),  UINT8_C(  151),
         UINT8_C(  247),  UINT8_C(  103),  UINT8_C(  243),  UINT8_C(  241) },
      {  UINT8_C(   33),  UINT8_C(  229),  UINT8_C(   20),  UINT8_C(  122),
         UINT8_C(  136),  UINT8_C(   32),  UINT8_C(  196),  UINT8_C(   45),
         UINT8_C(   56),  UINT8_C(  169),  UINT8_C(  181),  UINT8_C(  147),
         UINT8_C(  247),  UINT8_C(  103),  UINT8_C(  243),  UINT8_C(  173) } },
    { {  UINT8_C(   85),  UINT8_C(   42),  UINT8_C(  232),  UINT8_C(   22),
         UINT8_C(   22),  UINT8_C(  177),  UINT8_C(   19),  UINT8_C(  207),
         UINT8_C(  243),  UINT8_C(   35),  UINT8_C(  139),  UINT8_C(  196),
         UINT8_C(   97),  UINT8_C(    0),  UINT8_C(   98),  UINT8_C(  175) },
      {  UINT8_C(  167),  UINT8_C(   39),  UINT8_C(  158),  UINT8_C(  122),
         UINT8_C(   43),  UINT8_C(   90),  UINT8_C(  131),  UINT8_C(  127),
         UINT8_C(   57),  UINT8_C(  210),  UINT8_C(  100),  UINT8_C(  133),
         UINT8_C(   98),  UINT8_C(  145),  UINT8_C(   33),  UINT8_C(   80) },
      {  UINT8_C(   80),  UINT8_C(   42),  UINT8_C(  232),  UINT8_C(   22),
         UINT8_C(   22),  UINT8_C(  177),  UINT8_C(   19),  UINT8_C(  207),
         UINT8_C(  243),  UINT8_C(   35),  UINT8_C(  139),  UINT8_C(  196),
         UINT8_C(   97),  UINT8_C(    0),  UINT8_C(   98),  UINT8_C(  175) },
      {  UINT8_C(   85),  UINT8_C(   42),  UINT8_C(  232),  UINT8_C(   98),
         UINT8_C(   22),  UINT8_C(  177),  UINT8_C(   19),  UINT8_C(  207),
         UINT8_C(  243),  UINT8_C(   35),  UINT8_C(  139),  UINT8_C(  196),
         UINT8_C(   97),  UINT8_C(    0),  UINT8_C(   98),  UINT8_C(  175) },
      {  UINT8_C(   85),  UINT8_C(   42),  UINT8_C(  232),  UINT8_C(   22),
         UINT8_C(   22),  UINT8_C(  177),  UINT8_C(   19),  UINT8_C(   57),
         UINT8_C(  243),  UINT8_C(   35),  UINT8_C(  139),  UINT8_C(  196),
         UINT8_C(   97),  UINT8_C(    0),  UINT8_C(   98),  UINT8_C(  175) },
      {  UINT8_C(   85),  UINT8_C(   42),  UINT8_C(  232),  UINT8_C(   22),
         UINT8_C(   22),  UINT8_C(  177),  UINT8_C(   19),  UINT8_C(  207),
         UINT8_C(  243),  UINT8_C(   35),  UINT8_C(  139),  UINT8_C(   43),
         UINT8_C(   97),  UINT8_C(    0),  UINT8_C(   98),  UINT8_C(  175) },
      {  UINT8_C(   85),  UINT8_C(   42),  UINT8_C(  232),  UINT8_C(   22),
         UINT8_C(   22),  UINT8_C(  177),  UINT8_C(   19),  UINT8_C(  207),
         UINT8_C(  243),  UINT8_C(   35),  UINT8_C(  139),  UINT8_C(  196),
         UINT8_C(   97),  UINT8_C(    0),  UINT8_C(   98),  UINT8_C(   39) } },
    { {  UINT8_C(   83),  UINT8_C(  171),  UINT8_C(    5),  UINT8_C(  105),
         UINT8_C(  211),  UINT8_C(    1),  UINT8_C(   43),  UINT8_C(   53),
         UINT8_C(  171),  UINT8_C(   15),  UINT8_C(   83),  UINT8_C(  235),
         UINT8_C(  252),  UINT8_C(  134),  UINT8_C(  244),  UINT8_C(    1) },
      {  UINT8_C(  212),  UINT8_C(   16),  UINT8_C(  118),  UINT8_C(  213),
         UINT8_C(   68),  UINT8_C(  168),  UINT8_C(   78),  UINT8_C(   94),
         UINT8_C(   96),  UINT8_C(   68),  UINT8_C(   29),  UINT8_C(  218),
         UINT8_C(  191),  UINT8_C(  115),  UINT8_C(  146),  UINT8_C(  235) },
      {  UINT8_C(  235),  UINT8_C(  171),  UINT8_C(    5),  UINT8_C(  105),
         UINT8_C(  211),  UINT8_C(    1),  UINT8_C(   43),  UINT8_C(   53),
         UINT8_C(  171),  UINT8_C(   15),  UINT8_C(   83),  UINT8_C(  235),
         UINT8_C(  252),  UINT8_C(  134),  UINT8_C(  244),  UINT8_C(    1) },
      {  UINT8_C(   83),  UINT8_C(  171),  UINT8_C(    5),  UINT8_C(  191),
         UINT8_C(  211),  UINT8_C(    1),  UINT8_C(   43),  UINT8_C(   53),
         UINT8_C(  171),  UINT8_C(   15),  UINT8_C(   83),  UINT8_C(  235),
         UINT8_C(  252),  UINT8_C(  134),  UINT8_C(  244),  UINT8_C(    1) },
      {  UINT8_C(   83),  UINT8_C(  171),  UINT8_C(    5),  UINT8_C(  105),
         UINT8_C(  211),  UINT8_C(    1),  UINT8_C(   43),  UINT8_C(   96),
         UINT8_C(  171),  UINT8_C(   15),  UINT8_C(   83),  UINT8_C(  235),
         UINT8_C(  252),  UINT8_C(  134),  UINT8_C(  244),  UINT8_C(    1) },
      {  UINT8_C(   83),  UINT8_C(  171),  UINT8_C(    5),  UINT8_C(  105),
         UINT8_C(  211),  UINT8_C(    1),  UINT8_C(   43),  UINT8_C(   53),
         UINT8_C(  171),  UINT8_C(   15),  UINT8_C(   83),  UINT8_C(   68),
         UINT8_C(  252),  UINT8_C(  134),  UINT8_C(  244),  UINT8_C(    1) },
      {  UINT8_C(   83),  UINT8_C(  171),  UINT8_C(    5),  UINT8_C(  105),
         UINT8_C(  211),  UINT8_C(    1),  UINT8_C(   43),  UINT8_C(   53),
         UINT8_C(  171),  UINT8_C(   15),  UINT8_C(   83),  UINT8_C(  235),
         UINT8_C(  252),  UINT8_C(  134),  UINT8_C(  244),  UINT8_C(   16) } },
    { {  UINT8_C(  110),  UINT8_C(  242),  UINT8_C(   72),  UINT8_C(   45),
         UINT8_C(   85),  UINT8_C(   45),  UINT8_C(  124),  UINT8_C(   76),
         UINT8_C(  205),  UINT8_C(  127),  UINT8_C(  154),  UINT8_C(  231),
         UINT8_C(  152),  UINT8_C(   56),  UINT8_C(   62),  UINT8_C(   70) },
      {  UINT8_C(  249),  UINT8_C(  143),  UINT8_C(   98),  UINT8_C(   59),
         UINT8_C(    2),  UINT8_C(   33),  UINT8_C(   73),  UINT8_C(   97),
         UINT8_C(  161),  UINT8_C(  222),  UINT8_C(   76),  UINT8_C(   96),
         UINT8_C(  205),  UINT8_C(  112),  UINT8_C(   99),  UINT8_C(  202) },
      {  UINT8_C(  202),  UINT8_C(  242),  UINT8_C(   72),  UINT8_C(   45),
         UINT8_C(   85),  UINT8_C(   45),  UINT8_C(  124),  UINT8_C(   76),
         UINT8_C(  205),  UINT8_C(  127),  UINT8_C(  154),  UINT8_C(  231),
         UINT8_C(  152),  UINT8_C(   56),  UINT8_C(   62),  UINT8_C(   70) },
      {  UINT8_C(  110),  UINT8_C(  242),  UINT8_C(   72),  UINT8_C(  205),
         UINT8_C(   85),  UINT8_C(   45),  UINT8_C(  124),  UINT8_C(   76),
         UINT8_C(  205),  UINT8_C(  127),  UINT8_C(  154),  UINT8_C(  231),
         UINT8_C(  152),  UINT8_C(   56),  UINT8_C(   62),  UINT8_C(   70) },
      {  UINT8_C(  110),  UINT8_C(  242),  UINT8_C(   72),  UINT8_C(   45),
         UINT8_C(   85),  UINT8_C(   45),  UINT8_C(  124),  UINT8_C(  161),
         UINT8_C(  205),  UINT8_C(  127),  UINT8_C(  154),  UINT8_C(  231),
         UINT8_C(  152),  UINT8_C(   56),  UINT8_C(   62),  UINT8_C(   70) },
      {  UINT8_C(  110),  UINT8_C(  242),  UINT8_C(   72),  UINT8_C(   45),
         UINT8_C(   85),  UINT8_C(   45),  UINT8_C(  124),  UINT8_C(   76),
         UINT8_C(  205),  UINT8_C(  127),  UINT8_C(  154),  UINT8_C(    2),
         UINT8_C(  152),  UINT8_C(   56),  UINT8_C(   62),  UINT8_C(   70) },
      {  UINT8_C(  110),  UINT8_C(  242),  UINT8_C(   72),  UINT8_C(   45),
         UINT8_C(   85),  UINT8_C(   45),  UINT8_C(  124),  UINT8_C(   76),
         UINT8_C(  205),  UINT8_C(  127),  UINT8_C(  154),  UINT8_C(  231),
         UINT8_C(  152),  UINT8_C(   56),  UINT8_C(   62),  UINT8_C(  143) } },
    { {  UINT8_C(  205),  UINT8_C(  113),  UINT8_C(  133),  UINT8_C(   98),
         UINT8_C(   49),  UINT8_C(  168),  UINT8_C(  196),  UINT8_C(  243),
         UINT8_C(   48),  UINT8_C(   38),  UINT8_C(   75),  UINT8_C(    0),
         UINT8_C(  164),  UINT8_C(  135),  UINT8_C(   28),  UINT8_C(   91) },
      {  UINT8_C(  214),  UINT8_C(   25),  UINT8_C(  230),  UINT8_C(  142),
         UINT8_C(   76),  UINT8_C(   97),  UINT8_C(   57),  UINT8_C(    7),
         UINT8_C(  239),  UINT8_C(  176),  UINT8_C(    8),  UINT8_C(   43),
         UINT8_C(   54),  UINT8_C(  231),  UINT8_C(   29),  UINT8_C(   24) },
      {  UINT8_C(   24),  UINT8_C(  113),  UINT8_C(  133),  UINT8_C(   98),
         UINT8_C(   49),  UINT8_C(  168),  UINT8_C(  196),  UINT8_C(  243),
         UINT8_C(   48),  UINT8_C(   38),  UINT8_C(   75),  UINT8_C(    0),
         UINT8_C(  164),  UINT8_C(  135),  UINT8_C(   28),  UINT8_C(   91) },
      {  UINT8_C(  205),  UINT8_C(  113),  UINT8_C(  133),  UINT8_C(   54),
         UINT8_C(   49),  UINT8_C(  168),  UINT8_C(  196),  UINT8_C(  243),
         UINT8_C(   48),  UINT8_C(   38),  UINT8_C(   75),  UINT8_C(    0),
         UINT8_C(  164),  UINT8_C(  135),  UINT8_C(   28),  UINT8_C(   91) },
      {  UINT8_C(  205),  UINT8_C(  113),  UINT8_C(  133),  UINT8_C(   98),
         UINT8_C(   49),  UINT8_C(  168),  UINT8_C(  196),  UINT8_C(  239),
         UINT8_C(   48),  UINT8_C(   38),  UINT8_C(   75),  UINT8_C(    0),
         UINT8_C(  164),  UINT8_C(  135),  UINT8_C(   28),  UINT8_C(   91) },
      {  UINT8_C(  205),  UINT8_C(  113),  UINT8_C(  133),  UINT8_C(   98),
         UINT8_C(   49),  UINT8_C(  168),  UINT8_C(  196),  UINT8_C(  243),
         UINT8_C(   48),  UINT8_C(   38),  UINT8_C(   75),  UINT8_C(   76),
         UINT8_C(  164),  UINT8_C(  135),  UINT8_C(   28),  UINT8_C(   91) },
      {  UINT8_C(  205),  UINT8_C(  113),  UINT8_C(  133),  UINT8_C(   98),
         UINT8_C(   49),  UINT8_C(  168),  UINT8_C(  196),  UINT8_C(  243),
         UINT8_C(   48),  UINT8_C(   38),  UINT8_C(   75),  UINT8_C(    0),
         UINT8_C(  164),  UINT8_C(  135),  UINT8_C(   28),  UINT8_C(   25) } },
    { {  UINT8_C(   41),  UINT8_C(    0),  UINT8_C(   18),  UINT8_C(  142),
         UINT8_C(   56),  UINT8_C(  132),  UINT8_C(    1),  UINT8_C(   98),
         UINT8_C(  122),  UINT8_C(   59),  UINT8_C(   66),  UINT8_C(   46),
         UINT8_C(   71),  UINT8_C(   48),  UINT8_C(   59),  UINT8_C(  144) },
      {  UINT8_C(   28),  UINT8_C(   82),  UINT8_C(  123),  UINT8_C(  131),
         UINT8_C(  204),  UINT8_C(  199),  UINT8_C(  247),  UINT8_C(  126),
         UINT8_C(   30),  UINT8_C(  111),  UINT8_C(   48),  UINT8_C(   50),
         UINT8_C(  252),  UINT8_C(   65),  UINT8_C(   21),  UINT8_C(  254) },
      {  UINT8_C(  254),  UINT8_C(    0),  UINT8_C(   18),  UINT8_C(  142),
         UINT8_C(   56),  UINT8_C(  132),  UINT8_C(    1),  UINT8_C(   98),
         UINT8_C(  122),  UINT8_C(   59),  UINT8_C(   66),  UINT8_C(   46),
         UINT8_C(   71),  UINT8_C(   48),  UINT8_C(   59),  UINT8_C(  144) },
      {  UINT8_C(   41),  UINT8_C(    0),  UINT8_C(   18),  UINT8_C(  252),
         UINT8_C(   56),  UINT8_C(  132),  UINT8_C(    1),  UINT8_C(   98),
         UINT8_C(  122),  UINT8_C(   59),  UINT8_C(   66),  UINT8_C(   46),
         UINT8_C(   71),  UINT8_C(   48),  UINT8_C(   59),  UINT8_C(  144) },
      {  UINT8_C(   41),  UINT8_C(    0),  UINT8_C(   18),  UINT8_C(  142),
         UINT8_C(   56),  UINT8_C(  132),  UINT8_C(    1),  UINT8_C(   30),
         UINT8_C(  122),  UINT8_C(   59),  UINT8_C(   66),  UINT8_C(   46),
         UINT8_C(   71),  UINT8_C(   48),  UINT8_C(   59),  UINT8_C(  144) },
      {  UINT8_C(   41),  UINT8_C(    0),  UINT8_C(   18),  UINT8_C(  142),
         UINT8_C(   56),  UINT8_C(  132),  UINT8_C(    1),  UINT8_C(   98),
         UINT8_C(  122),  UINT8_C(   59),  UINT8_C(   66),  UINT8_C(  204),
         UINT8_C(   71),  UINT8_C(   48),  UINT8_C(   59),  UINT8_C(  144) },
      {  UINT8_C(   41),  UINT8_C(    0),  UINT8_C(   18),  UINT8_C(  142),
         UINT8_C(   56),  UINT8_C(  132),  UINT8_C(    1),  UINT8_C(   98),
         UINT8_C(  122),  UINT8_C(   59),  UINT8_C(   66),  UINT8_C(   46),
         UINT8_C(   71),  UINT8_C(   48),  UINT8_C(   59),  UINT8_C(   82) } },
    { {  UINT8_C(  214),  UINT8_C(  112),  UINT8_C(   60),  UINT8_C(  183),
         UINT8_C(  213),  UINT8_C(  143),  UINT8_C(   98),  UINT8_C(  231),
         UINT8_C(  105),  UINT8_C(   97),  UINT8_C(   76),  UINT8_C(   13),
         UINT8_C(  190),  UINT8_C(   12),  UINT8_C(  121),  UINT8_C(  167) },
      {  UINT8_C(   60),  UINT8_C(  212),  UINT8_C(  212),  UINT8_C(  225),
         UINT8_C(  136),  UINT8_C(  233),  UINT8_C(    4),  UINT8_C(   29),
         UINT8_C(  196),  UINT8_C(  145),  UINT8_C(  157),  UINT8_C(  121),
         UINT8_C(   58),  UINT8_C(   57),  UINT8_C(  166),  UINT8_C(   79) },
      {  UINT8_C(   79),  UINT8_C(  112),  UINT8_C(   60),  UINT8_C(  183),
         UINT8_C(  213),  UINT8_C(  143),  UINT8_C(   98),  UINT8_C(  231),
         UINT8_C(  105),  UINT8_C(   97),  UINT8_C(   76),  UINT8_C(   13),
         UINT8_C(  190),  UINT8_C(   12),  UINT8_C(  121),  UINT8_C(  167) },
      {  UINT8_C(  214),  UINT8_C(  112),  UINT8_C(   60),  UINT8_C(   58),
         UINT8_C(  213),  UINT8_C(  143),  UINT8_C(   98),  UINT8_C(  231),
         UINT8_C(  105),  UINT8_C(   97),  UINT8_C(   76),  UINT8_C(   13),
         UINT8_C(  190),  UINT8_C(   12),  UINT8_C(  121),  UINT8_C(  167) },
      {  UINT8_C(  214),  UINT8_C(  112),  UINT8_C(   60),  UINT8_C(  183),
         UINT8_C(  213),  UINT8_C(  143),  UINT8_C(   98),  UINT8_C(  196),
         UINT8_C(  105),  UINT8_C(   97),  UINT8_C(   76),  UINT8_C(   13),
         UINT8_C(  190),  UINT8_C(   12),  UINT8_C(  121),  UINT8_C(  167) },
      {  UINT8_C(  214),  UINT8_C(  112),  UINT8_C(   60),  UINT8_C(  183),
         UINT8_C(  213),  UINT8_C(  143),  UINT8_C(   98),  UINT8_C(  231),
         UINT8_C(  105),  UINT8_C(   97),  UINT8_C(   76),  UINT8_C(  136),
         UINT8_C(  190),  UINT8_C(   12),  UINT8_C(  121),  UINT8_C(  167) },
      {  UINT8_C(  214),  UINT8_C(  112),  UINT8_C(   60),  UINT8_C(  183),
         UINT8_C(  213),  UINT8_C(  143),  UINT8_C(   98),  UINT8_C(  231),
         UINT8_C(  105),  UINT8_C(   97),  UINT8_C(   76),  UINT8_C(   13),
         UINT8_C(  190),  UINT8_C(   12),  UINT8_C(  121),  UINT8_C(  212) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);

    simde_uint8x16_t r0_15 = simde_vcopyq_laneq_u8(a, 0, b, 15);
    simde_uint8x16_t r3_12 = simde_vcopyq_laneq_u8(a, 3, b, 12);
    simde_uint8x16_t r7_8 = simde_vcopyq_laneq_u8(a, 7, b, 8);
    simde_uint8x16_t r11_4 = simde_vcopyq_laneq_u8(a, 11, b, 4);
    simde_uint8x16_t r15_1 = simde_vcopyq_laneq_u8(a, 15, b, 1);

    simde_test_arm_neon_assert_equal_u8x16(r0_15, simde_vld1q_u8(test_vec[i].r0_15));
    simde_test_arm_neon_assert_equal_u8x16(r3_12, simde_vld1q_u8(test_vec[i].r3_12));
    simde_test_arm_neon_assert_equal_u8x16(r7_8, simde_vld1q_u8(test_vec[i].r7_8));
    simde_test_arm_neon_assert_equal_u8x16(r11_4, simde_vld1q_u8(test_vec[i].r11_4));
    simde_test_arm_neon_assert_equal_u8x16(r15_1, simde_vld1q_u8(test_vec[i].r15_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r0_15 = simde_vcopyq_laneq_u8(a, 0, b, 15);
    simde_uint8x16_t r3_12 = simde_vcopyq_laneq_u8(a, 3, b, 12);
    simde_uint8x16_t r7_8 = simde_vcopyq_laneq_u8(a, 7, b, 8);
    simde_uint8x16_t r11_4 = simde_vcopyq_laneq_u8(a, 11, b, 4);
    simde_uint8x16_t r15_1 = simde_vcopyq_laneq_u8(a, 15, b, 1);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r0_15, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r3_12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r7_8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r11_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r15_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r0_7[8];
    uint16_t r1_6[8];
    uint16_t r3_4[8];
    uint16_t r5_3[8];
    uint16_t r7_1[8];
  } test_vec[] = {
    { {  UINT16_C(   25081),  UINT16_C(   12133),  UINT16_C(   16658),  UINT16_C(   10269),
         UINT16_C(   62695),  UINT16_C(   42052),  UINT16_C(   28583),  UINT16_C(   55868) },
      {  UINT16_C(   64179),  UINT16_C(    3756),  UINT16_C(   15151),  UINT16_C(   33917),
         UINT16_C(   33797),  UINT16_C(   56243),  UINT16_C(   48168),  UINT16_C(   62591) },
      {  UINT16_C(   62591),  UINT16_C(   12133),  UINT16_C(   16658),  UINT16_C(   10269),
         UINT16_C(   62695),  UINT16_C(   42052),  UINT16_C(   28583),  UINT16_C(   55868) },
      {  UINT16_C(   25081),  UINT16_C(   48168),  UINT16_C(   16658),  UINT16_C(   10269),
         UINT16_C(   62695),  UINT16_C(   42052),  UINT16_C(   28583),  UINT16_C(   55868) },
      {  UINT16_C(   25081),  UINT16_C(   12133),  UINT16_C(   16658),  UINT16_C(   33797),
         UINT16_C(   62695),  UINT16_C(   42052),  UINT16_C(   28583),  UINT16_C(   55868) },
      {  UINT16_C(   25081),  UINT16_C(   12133),  UINT16_C(   16658),  UINT16_C(   10269),
         UINT16_C(   62695),  UINT16_C(   33917),  UINT16_C(   28583),  UINT16_C(   55868) },
      {  UINT16_C(   25081),  UINT16_C(   12133),  UINT16_C(   16658),  UINT16_C(   10269),
         UINT16_C(   62695),  UINT16_C(   42052),  UINT16_C(   28583),  UINT16_C(    3756) } },
    { {  UINT16_C(   42773),  UINT16_C(   60819),  UINT16_C(    5780),  UINT16_C(   38892),
         UINT16_C(   50295),  UINT16_C(   55830),  UINT16_C(   29603),  UINT16_C(    6234) },
      {  UINT16_C(   14631),  UINT16_C(   14975),  UINT16_C(   18813),  UINT16_C(   48357),
         UINT16_C(   43565),  UINT16_C(   52059),  UINT16_C(   49414),  UINT16_C(   62266) },
      {  UINT16_C(   62266),  UINT16_C(   60819),  UINT16_C(    5780),  UINT16_C(   38892),
         UINT16_C(   50295),  UINT16_C(   55830),  UINT16_C(   29603),  UINT16_C(    6234) },
      {  UINT16_C(   42773),  UINT16_C(   49414),  UINT16_C(    5780),  UINT16_C(   38892),
         UINT16_C(   50295),  UINT16_C(   55830),  UINT16_C(   29603),  UINT16_C(    6234) },
      {  UINT16_C(   42773),  UINT16_C(   60819),  UINT16_C(    5780),  UINT16_C(   43565),
         UINT16_C(   50295),  UINT16_C(   55830),  UINT16_C(   29603),  UINT16_C(    6234) },
      {  UINT16_C(   42773),  UINT16_C(   60819),  UINT16_C(    5780),  UINT16_C(   38892),
         UINT16_C(   50295),  UINT16_C(   48357),  UINT16_C(   29603),  UINT16_C(    6234) },
      {  UINT16_C(   42773),  UINT16_C(   60819),  UINT16_C(    5780),  UINT16_C(   38892),
         UINT16_C(   50295),  UINT16_C(   55830),  UINT16_C(   29603),  UINT16_C(   14975) } },
    { {  UINT16_C(   59618),  UINT16_C(   16122),  UINT16_C(   25506),  UINT16_C(   64566),
         UINT16_C(   25795),  UINT16_C(   55880),  UINT16_C(   14803),  UINT16_C(   20543) },
      {  UINT16_C(   40023),  UINT16_C(   25126),  UINT16_C(   26717),  UINT16_C(   35096),
         UINT16_C(   32251),  UINT16_C(   38772),  UINT16_C(    8275),  UINT16_C(   33753) },
      {  UINT16_C(   33753),  UINT16_C(   16122),  UINT16_C(   25506),  UINT16_C(   64566),
         UINT16_C(   25795),  UINT16_C(   55880),  UINT16_C(   14803),  UINT16_C(   20543) },
      {  UINT16_C(   59618),  UINT16_C(    8275),  UINT16_C(   25506),  UINT16_C(   64566),
         UINT16_C(   25795),  UINT16_C(   55880),  UINT16_C(   14803),  UINT16_C(   20543) },
      {  UINT16_C(   59618),  UINT16_C(   16122),  UINT16_C(   25506),  UINT16_C(   32251),
         UINT16_C(   25795),  UINT16_C(   55880),  UINT16_C(   14803),  UINT16_C(   20543) },
      {  UINT16_C(   59618),  UINT16_C(   16122),  UINT16_C(   25506),  UINT16_C(   64566),
         UINT16_C(   25795),  UINT16_C(   35096),  UINT16_C(   14803),  UINT16_C(   20543) },
      {  UINT16_C(   59618),  UINT16_C(   16122),  UINT16_C(   25506),  UINT16_C(   64566),
         UINT16_C(   25795),  UINT16_C(   55880),  UINT16_C(   14803),  UINT16_C(   25126) } },
    { {  UINT16_C(   43675),  UINT16_C(   35166),  UINT16_C(   34629),  UINT16_C(   36341),
         UINT16_C(   64989),  UINT16_C(    2813),  UINT16_C(   39062),  UINT16_C(   26525) },
      {  UINT16_C(   57069),  UINT16_C(   55607),  UINT16_C(   20903),  UINT16_C(   57247),
         UINT16_C(   36244),  UINT16_C(   62344),  UINT16_C(   41912),  UINT16_C(   44736) },
      {  UINT16_C(   44736),  UINT16_C(   35166),  UINT16_C(   34629),  UINT16_C(   36341),
         UINT16_C(   64989),  UINT16_C(    2813),  UINT16_C(   39062),  UINT16_C(   26525) },
      {  UINT16_C(   43675),  UINT16_C(   41912),  UINT16_C(   34629),  UINT16_C(   36341),
         UINT16_C(   64989),  UINT16_C(    2813),  UINT16_C(   39062),  UINT16_C(   26525) },
      {  UINT16_C(   43675),  UINT16_C(   35166),  UINT16_C(   34629),  UINT16_C(   36244),
         UINT16_C(   64989),  UINT16_C(    2813),  UINT16_C(   39062),  UINT16_C(   26525) },
      {  UINT16_C(   43675),  UINT16_C(   35166),  UINT16_C(   34629),  UINT16_C(   36341),
         UINT16_C(   64989),  UINT16_C(   57247),  UINT16_C(   39062),  UINT16_C(   26525) },
      {  UINT16_C(   43675),  UINT16_C(   35166),  UINT16_C(   34629),  UINT16_C(   36341),
         UINT16_C(   64989),  UINT16_C(    2813),  UINT16_C(   39062),  UINT16_C(   55607) } },
    { {  UINT16_C(   63367),  UINT16_C(   50618),  UINT16_C(   52629),  UINT16_C(   26557),
         UINT16_C(   49457),  UINT16_C(   55560),  UINT16_C(   59740),  UINT16_C(   54035) },
      {  UINT16_C(   35397),  UINT16_C(   27456),  UINT16_C(   19596),  UINT16_C(   23074),
         UINT16_C(   44230),  UINT16_C(   28458),  UINT16_C(   34027),  UINT16_C(   31882) },
      {  UINT16_C(   31882),  UINT16_C(   50618),  UINT16_C(   52629),  UINT16_C(   26557),
         UINT16_C(   49457),  UINT16_C(   55560),  UINT16_C(   59740),  UINT16_C(   54035) },
      {  UINT16_C(   63367),  UINT16_C(   34027),  UINT16_C(   52629),  UINT16_C(   26557),
         UINT16_C(   49457),  UINT16_C(   55560),  UINT16_C(   59740),  UINT16_C(   54035) },
      {  UINT16_C(   63367),  UINT16_C(   50618),  UINT16_C(   52629),  UINT16_C(   44230),
         UINT16_C(   49457),  UINT16_C(   55560),  UINT16_C(   59740),  UINT16_C(   54035) },
      {  UINT16_C(   63367),  UINT16_C(   50618),  UINT16_C(   52629),  UINT16_C(   26557),
         UINT16_C(   49457),  UINT16_C(   23074),  UINT16_C(   59740),  UINT16_C(   54035) },
      {  UINT16_C(   63367),  UINT16_C(   50618),  UINT16_C(   52629),  UINT16_C(   26557),
         UINT16_C(   49457),  UINT16_C(   55560),  UINT16_C(   59740),  UINT16_C(   27456) } },
    { {  UINT16_C(   23413),  UINT16_C(   40483),  UINT16_C(      63),  UINT16_C(   52152),
         UINT16_C(   38959),  UINT16_C(    4929),  UINT16_C(   21435),  UINT16_C(   62787) },
      {  UINT16_C(   49317),  UINT16_C(   18538),  UINT16_C(   17793),  UINT16_C(   61704),
         UINT16_C(   41671),  UINT16_C(   53824),  UINT16_C(   25678),  UINT16_C(   37125) },
      {  UINT16_C(   37125),  UINT16_C(   40483),  UINT16_C(      63),  UINT16_C(   52152),
         UINT16_C(   38959),  UINT16_C(    4929),  UINT16_C(   21435),  UINT16_C(   62787) },
      {  UINT16_C(   23413),  UINT16_C(   25678),  UINT16_C(      63),  UINT16_C(   52152),
         UINT16_C(   38959),  UINT16_C(    4929),  UINT16_C(   21435),  UINT16_C(   62787) },
      {  UINT16_C(   23413),  UINT16_C(   40483),  UINT16_C(      63),  UINT16_C(   41671),
         UINT16_C(   38959),  UINT16_C(    4929),  UINT16_C(   21435),  UINT16_C(   62787) },
      {  UINT16_C(   23413),  UINT16_C(   40483),  UINT16_C(      63),  UINT16_C(   52152),
         UINT16_C(   38959),  UINT16_C(   61704),  UINT16_C(   21435),  UINT16_C(   62787) },
      {  UINT16_C(   23413),  UINT16_C(   40483),  UINT16_C(      63),  UINT16_C(   52152),
         UINT16_C(   38959),  UINT16_C(    4929),  UINT16_C(   21435),  UINT16_C(   18538) } },
    { {  UINT16_C(   41696),  UINT16_C(    7636),  UINT16_C(   15486),  UINT16_C(     842),
         UINT16_C(   14005),  UINT16_C(   39402),  UINT16_C(   58283),  UINT16_C(    8456) },
      {  UINT16_C(   47670),  UINT16_C(    2324),  UINT16_C(   19969),  UINT16_C(   53005),
         UINT16_C(    4511),  UINT16_C(   36060),  UINT16_C(   54065),  UINT16_C(   35479) },
      {  UINT16_C(   35479),  UINT16_C(    7636),  UINT16_C(   15486),  UINT16_C(     842),
         UINT16_C(   14005),  UINT16_C(   39402),  UINT16_C(   58283),  UINT16_C(    8456) },
      {  UINT16_C(   41696),  UINT16_C(   54065),  UINT16_C(   15486),  UINT16_C(     842),
         UINT16_C(   14005),  UINT16_C(   39402),  UINT16_C(   58283),  UINT16_C(    8456) },
      {  UINT16_C(   41696),  UINT16_C(    7636),  UINT16_C(   15486),  UINT16_C(    4511),
         UINT16_C(   14005),  UINT16_C(   39402),  UINT16_C(   58283),  UINT16_C(    8456) },
      {  UINT16_C(   41696),  UINT16_C(    7636),  UINT16_C(   15486),  UINT16_C(     842),
         UINT16_C(   14005),  UINT16_C(   53005),  UINT16_C(   58283),  UINT16_C(    8456) },
      {  UINT16_C(   41696),  UINT16_C(    7636),  UINT16_C(   15486),  UINT16_C(     842),
         UINT16_C(   14005),  UINT16_C(   39402),  UINT16_C(   58283),  UINT16_C(    2324) } },
    { {  UINT16_C(   31497),  UINT16_C(    5172),  UINT16_C(   59315),  UINT16_C(    4122),
         UINT16_C(   52072),  UINT16_C(   14663),  UINT16_C(    6643),  UINT16_C(   19646) },
      {  UINT16_C(    3117),  UINT16_C(    6887),  UINT16_C(    8411),  UINT16_C(   34695),
         UINT16_C(   37761),  UINT16_C(   62501),  UINT16_C(    1235),  UINT16_C(    7430) },
      {  UINT16_C(    7430),  UINT16_C(    5172),  UINT16_C(   59315),  UINT16_C(    4122),
         UINT16_C(   52072),  UINT16_C(   14663),  UINT16_C(    6643),  UINT16_C(   19646) },
      {  UINT16_C(   31497),  UINT16_C(    1235),  UINT16_C(   59315),  UINT16_C(    4122),
         UINT16_C(   52072),  UINT16_C(   14663),  UINT16_C(    6643),  UINT16_C(   19646) },
      {  UINT16_C(   31497),  UINT16_C(    5172),  UINT16_C(   59315),  UINT16_C(   37761),
         UINT16_C(   52072),  UINT16_C(   14663),  UINT16_C(    6643),  UINT16_C(   19646) },
      {  UINT16_C(   31497),  UINT16_C(    5172),  UINT16_C(   59315),  UINT16_C(    4122),
         UINT16_C(   52072),  UINT16_C(   34695),  UINT16_C(    6643),  UINT16_C(   19646) },
      {  UINT16_C(   31497),  UINT16_C(    5172),  UINT16_C(   59315),  UINT16_C(    4122),
         UINT16_C(   52072),  UINT16_C(   14663),  UINT16_C(    6643),  UINT16_C(    6887) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x8_t r0_7 = simde_vcopyq_laneq_u16(a, 0, b, 7);
    simde_uint16x8_t r1_6 = simde_vcopyq_laneq_u16(a, 1, b, 6);
    simde_uint16x8_t r3_4 = simde_vcopyq_laneq_u16(a, 3, b, 4);
    simde_uint16x8_t r5_3 = simde_vcopyq_laneq_u16(a, 5, b, 3);
    simde_uint16x8_t r7_1 = simde_vcopyq_laneq_u16(a, 7, b, 1);

    simde_test_arm_neon_assert_equal_u16x8(r0_7, simde_vld1q_u16(test_vec[i].r0_7));
    simde_test_arm_neon_assert_equal_u16x8(r1_6, simde_vld1q_u16(test_vec[i].r1_6));
    simde_test_arm_neon_assert_equal_u16x8(r3_4, simde_vld1q_u16(test_vec[i].r3_4));
    simde_test_arm_neon_assert_equal_u16x8(r5_3, simde_vld1q_u16(test_vec[i].r5_3));
    simde_test_arm_neon_assert_equal_u16x8(r7_1, simde_vld1q_u16(test_vec[i].r7_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r0_7 = simde_vcopyq_laneq_u16(a, 0, b, 7);
    simde_uint16x8_t r1_6 = simde_vcopyq_laneq_u16(a, 1, b, 6);
    simde_uint16x8_t r3_4 = simde_vcopyq_laneq_u16(a, 3, b, 4);
    simde_uint16x8_t r5_3 = simde_vcopyq_laneq_u16(a, 5, b, 3);
    simde_uint16x8_t r7_1 = simde_vcopyq_laneq_u16(a, 7, b, 1);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r0_7, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r1_6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r5_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r7_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r0_3[4];
    uint32_t r1_2[4];
    uint32_t r2_1[4];
    uint32_t r3_0[4];
  } test_vec[] = {
    { {  UINT32_C(  2136215777),  UINT32_C(  3630933059),  UINT32_C(  2773291539),  UINT32_C(  3690985421) },
      {  UINT32_C(   892184183),  UINT32_C(   193672311),  UINT32_C(  2139275606),  UINT32_C(   136188165) },
      {  UINT32_C(   136188165),  UINT32_C(  3630933059),  UINT32_C(  2773291539),  UINT32_C(  3690985421) },
      {  UINT32_C(  2136215777),  UINT32_C(  2139275606),  UINT32_C(  2773291539),  UINT32_C(  3690985421) },
      {  UINT32_C(  2136215777),  UINT32_C(  3630933059),  UINT32_C(   193672311),  UINT32_C(  3690985421) },
      {  UINT32_C(  2136215777),  UINT32_C(  3630933059),  UINT32_C(  2773291539),  UINT32_C(   892184183) } },
    { {  UINT32_C(  2671810708),  UINT32_C(  1685919905),  UINT32_C(  2821922285),  UINT32_C(  3960114487) },
      {  UINT32_C(  3985986156),  UINT32_C(   864598811),  UINT32_C(   693528333),  UINT32_C(  3592219988) },
      {  UINT32_C(  3592219988),  UINT32_C(  1685919905),  UINT32_C(  2821922285),  UINT32_C(  3960114487) },
      {  UINT32_C(  2671810708),  UINT32_C(   693528333),  UINT32_C(  2821922285),  UINT32_C(  3960114487) },
      {  UINT32_C(  2671810708),  UINT32_C(  1685919905),  UINT32_C(   864598811),  UINT32_C(  3960114487) },
      {  UINT32_C(  2671810708),  UINT32_C(  1685919905),  UINT32_C(  2821922285),  UINT32_C(  3985986156) } },
    { {  UINT32_C(   817974392),  UINT32_C(   501550872),  UINT32_C(  1712818019),  UINT32_C(  2965256612) },
      {  UINT32_C(  1300216849),  UINT32_C(  3932298120),  UINT32_C(  3679577723),  UINT32_C(  1127937645) },
      {  UINT32_C(  1127937645),  UINT32_C(   501550872),  UINT32_C(  1712818019),  UINT32_C(  2965256612) },
      {  UINT32_C(   817974392),  UINT32_C(  3679577723),  UINT32_C(  1712818019),  UINT32_C(  2965256612) },
      {  UINT32_C(   817974392),  UINT32_C(   501550872),  UINT32_C(  3932298120),  UINT32_C(  2965256612) },
      {  UINT32_C(   817974392),  UINT32_C(   501550872),  UINT32_C(  1712818019),  UINT32_C(  1300216849) } },
    { {  UINT32_C(  2723508205),  UINT32_C(  4208862096),  UINT32_C(  2940436296),  UINT32_C(  1699082770) },
      {  UINT32_C(   906232555),  UINT32_C(   736207677),  UINT32_C(  1564834480),  UINT32_C(   634302632) },
      {  UINT32_C(   634302632),  UINT32_C(  4208862096),  UINT32_C(  2940436296),  UINT32_C(  1699082770) },
      {  UINT32_C(  2723508205),  UINT32_C(  1564834480),  UINT32_C(  2940436296),  UINT32_C(  1699082770) },
      {  UINT32_C(  2723508205),  UINT32_C(  4208862096),  UINT32_C(   736207677),  UINT32_C(  1699082770) },
      {  UINT32_C(  2723508205),  UINT32_C(  4208862096),  UINT32_C(  2940436296),  UINT32_C(   906232555) } },
    { {  UINT32_C(   379503279),  UINT32_C(  2857600816),  UINT32_C(   275459501),  UINT32_C(   304292775) },
      {  UINT32_C(  1019543097),  UINT32_C(   373140555),  UINT32_C(   909261254),  UINT32_C(  3547460328) },
      {  UINT32_C(  3547460328),  UINT32_C(  2857600816),  UINT32_C(   275459501),  UINT32_C(   304292775) },
      {  UINT32_C(   379503279),  UINT32_C(   909261254),  UINT32_C(   275459501),  UINT32_C(   304292775) },
      {  UINT32_C(   379503279),  UINT32_C(  2857600816),  UINT32_C(   373140555),  UINT32_C(   304292775) },
      {  UINT32_C(   379503279),  UINT32_C(  2857600816),  UINT32_C(   275459501),  UINT32_C(  1019543097) } },
    { {  UINT32_C(  1203434097),  UINT32_C(   114376390),  UINT32_C(   168566558),  UINT32_C(  3889127067) },
      {  UINT32_C(  2410760924),  UINT32_C(  2923650458),  UINT32_C(  3855579023),  UINT32_C(  4134326194) },
      {  UINT32_C(  4134326194),  UINT32_C(   114376390),  UINT32_C(   168566558),  UINT32_C(  3889127067) },
      {  UINT32_C(  1203434097),  UINT32_C(  3855579023),  UINT32_C(   168566558),  UINT32_C(  3889127067) },
      {  UINT32_C(  1203434097),  UINT32_C(   114376390),  UINT32_C(  2923650458),  UINT32_C(  3889127067) },
      {  UINT32_C(  1203434097),  UINT32_C(   114376390),  UINT32_C(   168566558),  UINT32_C(  2410760924) } },
    { {  UINT32_C(  3869172885),  UINT32_C(  2993434742),  UINT32_C(  2905386218),  UINT32_C(  2642883192) },
      {  UINT32_C(  2870909542),  UINT32_C(  1947325143),  UINT32_C(  2317972867),  UINT32_C(  1261263722) },
      {  UINT32_C(  1261263722),  UINT32_C(  2993434742),  UINT32_C(  2905386218),  UINT32_C(  2642883192) },
      {  UINT32_C(  3869172885),  UINT32_C(  2317972867),  UINT32_C(  2905386218),  UINT32_C(  2642883192) },
      {  UINT32_C(  3869172885),  UINT32_C(  2993434742),  UINT32_C(  1947325143),  UINT32_C(  2642883192) },
      {  UINT32_C(  3869172885),  UINT32_C(  2993434742),  UINT32_C(  2905386218),  UINT32_C(  2870909542) } },
    { {  UINT32_C(  1907398736),  UINT32_C(  1863663803),  UINT32_C(  3232279915),  UINT32_C(  2788982881) },
      {  UINT32_C(   483563107),  UINT32_C(    22560959),  UINT32_C(  3427567537),  UINT32_C(   922192707) },
      {  UINT32_C(   922192707),  UINT32_C(  1863663803),  UINT32_C(  3232279915),  UINT32_C(  2788982881) },
      {  UINT32_C(  1907398736),  UINT32_C(  3427567537),  UINT32_C(  3232279915),  UINT32_C(  2788982881) },
      {  UINT32_C(  1907398736),  UINT32_C(  1863663803),  UINT32_C(    22560959),  UINT32_C(  2788982881) },
      {  UINT32_C(  1907398736),  UINT32_C(  1863663803),  UINT32_C(  3232279915),  UINT32_C(   483563107) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x4_t r0_3 = simde_vcopyq_laneq_u32(a, 0, b, 3);
    simde_uint32x4_t r1_2 = simde_vcopyq_laneq_u32(a, 1, b, 2);
    simde_uint32x4_t r2_1 = simde_vcopyq_laneq_u32(a, 2, b, 1);
    simde_uint32x4_t r3_0 = simde_vcopyq_laneq_u32(a, 3, b, 0);

    simde_test_arm_neon_assert_equal_u32x4(r0_3, simde_vld1q_u32(test_vec[i].r0_3));
    simde_test_arm_neon_assert_equal_u32x4(r1_2, simde_vld1q_u32(test_vec[i].r1_2));
    simde_test_arm_neon_assert_equal_u32x4(r2_1, simde_vld1q_u32(test_vec[i].r2_1));
    simde_test_arm_neon_assert_equal_u32x4(r3_0, simde_vld1q_u32(test_vec[i].r3_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r0_3 = simde_vcopyq_laneq_u32(a, 0, b, 3);
    simde_uint32x4_t r1_2 = simde_vcopyq_laneq_u32(a, 1, b, 2);
    simde_uint32x4_t r2_1 = simde_vcopyq_laneq_u32(a, 2, b, 1);
    simde_uint32x4_t r3_0 = simde_vcopyq_laneq_u32(a, 3, b, 0);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r0_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r1_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r2_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r3_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r0_0[2];
    uint64_t r0_1[2];
    uint64_t r1_0[2];
    uint64_t r1_1[2];
  } test_vec[] = {
    { {  UINT64_C(13439609365108810888),  UINT64_C(15937695336418566217) },
      {  UINT64_C(11757999458065731058),  UINT64_C(17975820540431480162) },
      {  UINT64_C(11757999458065731058),  UINT64_C(15937695336418566217) },
      {  UINT64_C(17975820540431480162),  UINT64_C(15937695336418566217) },
      {  UINT64_C(13439609365108810888),  UINT64_C(11757999458065731058) },
      {  UINT64_C(13439609365108810888),  UINT64_C(17975820540431480162) } },
    { {  UINT64_C(16564546751237621820),  UINT64_C(12241248961613285278) },
      {  UINT64_C( 7641825135841022951),  UINT64_C(12315251603794302270) },
      {  UINT64_C( 7641825135841022951),  UINT64_C(12241248961613285278) },
      {  UINT64_C(12315251603794302270),  UINT64_C(12241248961613285278) },
      {  UINT64_C(16564546751237621820),  UINT64_C( 7641825135841022951) },
      {  UINT64_C(16564546751237621820),  UINT64_C(12315251603794302270) } },
    { {  UINT64_C(17704957791680247171),  UINT64_C( 9371616720984263202) },
      {  UINT64_C( 7276494259531683395),  UINT64_C( 5859910920720482327) },
      {  UINT64_C( 7276494259531683395),  UINT64_C( 9371616720984263202) },
      {  UINT64_C( 5859910920720482327),  UINT64_C( 9371616720984263202) },
      {  UINT64_C(17704957791680247171),  UINT64_C( 7276494259531683395) },
      {  UINT64_C(17704957791680247171),  UINT64_C( 5859910920720482327) } },
    { {  UINT64_C(14662575302122884717),  UINT64_C( 3176330314367196783) },
      {  UINT64_C( 7453175549508455517),  UINT64_C( 4453488503906172319) },
      {  UINT64_C( 7453175549508455517),  UINT64_C( 3176330314367196783) },
      {  UINT64_C( 4453488503906172319),  UINT64_C( 3176330314367196783) },
      {  UINT64_C(14662575302122884717),  UINT64_C( 7453175549508455517) },
      {  UINT64_C(14662575302122884717),  UINT64_C( 4453488503906172319) } },
    { {  UINT64_C(12249441119495819269),  UINT64_C(  186417079881519408) },
      {  UINT64_C(16358619248331576219),  UINT64_C(  987352505179597987) },
      {  UINT64_C(16358619248331576219),  UINT64_C(  186417079881519408) },
      {  UINT64_C(  987352505179597987),  UINT64_C(  186417079881519408) },
      {  UINT64_C(12249441119495819269),  UINT64_C(16358619248331576219) },
      {  UINT64_C(12249441119495819269),  UINT64_C(  987352505179597987) } },
    { {  UINT64_C( 3211036171106824205),  UINT64_C(17735964159800454359) },
      {  UINT64_C(14856931664874395873),  UINT64_C( 5092631228929164180) },
      {  UINT64_C(14856931664874395873),  UINT64_C(17735964159800454359) },
      {  UINT64_C( 5092631228929164180),  UINT64_C(17735964159800454359) },
      {  UINT64_C( 3211036171106824205),  UINT64_C(14856931664874395873) },
      {  UINT64_C( 3211036171106824205),  UINT64_C( 5092631228929164180) } },
    { {  UINT64_C(16290890406714175431),  UINT64_C( 7369026070235053466) },
      {  UINT64_C(14159949742399780407),  UINT64_C(12799840516808467205) },
      {  UINT64_C(14159949742399780407),  UINT64_C( 7369026070235053466) },
      {  UINT64_C(12799840516808467205),  UINT64_C( 7369026070235053466) },
      {  UINT64_C(16290890406714175431),  UINT64_C(14159949742399780407) },
      {  UINT64_C(16290890406714175431),  UINT64_C(12799840516808467205) } },
    { {  UINT64_C(11596480201225729972),  UINT64_C(15597658933811404841) },
      {  UINT64_C( 4501987111170332097),  UINT64_C(16539108248642911739) },
      {  UINT64_C( 4501987111170332097),  UINT64_C(15597658933811404841) },
      {  UINT64_C(16539108248642911739),  UINT64_C(15597658933811404841) },
      {  UINT64_C(11596480201225729972),  UINT64_C( 4501987111170332097) },
      {  UINT64_C(11596480201225729972),  UINT64_C(16539108248642911739) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);

    simde_uint64x2_t r0_0 = simde_vcopyq_laneq_u64(a, 0, b, 0);
    simde_uint64x2_t r0_1 = simde_vcopyq_laneq_u64(a, 0, b, 1);
    simde_uint64x2_t r1_0 = simde_vcopyq_laneq_u64(a, 1, b, 0);
    simde_uint64x2_t r1_1 = simde_vcopyq_laneq_u64(a, 1, b, 1);

    simde_test_arm_neon_assert_equal_u64x2(r0_0, simde_vld1q_u64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_u64x2(r0_1, simde_vld1q_u64(test_vec[i].r0_1));
    simde_test_arm_neon_assert_equal_u64x2(r1_0, simde_vld1q_u64(test_vec[i].r1_0));
    simde_test_arm_neon_assert_equal_u64x2(r1_1, simde_vld1q_u64(test_vec[i].r1_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r0_0 = simde_vcopyq_laneq_u64(a, 0, b, 0);
    simde_uint64x2_t r0_1 = simde_vcopyq_laneq_u64(a, 0, b, 1);
    simde_uint64x2_t r1_0 = simde_vcopyq_laneq_u64(a, 1, b, 0);
    simde_uint64x2_t r1_1 = simde_vcopyq_laneq_u64(a, 1, b, 1);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r0_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r1_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r1_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t b[4];
    simde_float32_t r0_3[4];
    simde_float32_t r1_2[4];
    simde_float32_t r2_1[4];
    simde_float32_t r3_0[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(  2288.813), -SIMDE_FLOAT32_C(  6828.664), -SIMDE_FLOAT32_C(  1743.203),  SIMDE_FLOAT32_C(  5142.055) },
      { -SIMDE_FLOAT32_C(  7820.406),  SIMDE_FLOAT32_C(  4065.967), -SIMDE_FLOAT32_C(  7156.866),  SIMDE_FLOAT32_C(  1483.873) },
      {  SIMDE_FLOAT32_C(  1483.873), -SIMDE_FLOAT32_C(  6828.664), -SIMDE_FLOAT32_C(  1743.203),  SIMDE_FLOAT32_C(  5142.055) },
      { -SIMDE_FLOAT32_C(  2288.813), -SIMDE_FLOAT32_C(  7156.866), -SIMDE_FLOAT32_C(  1743.203),  SIMDE_FLOAT32_C(  5142.055) },
      { -SIMDE_FLOAT32_C(  2288.813), -SIMDE_FLOAT32_C(  6828.664),  SIMDE_FLOAT32_C(  4065.967),  SIMDE_FLOAT32_C(  5142.055) },
      { -SIMDE_FLOAT32_C(  2288.813), -SIMDE_FLOAT32_C(  6828.664), -SIMDE_FLOAT32_C(  1743.203), -SIMDE_FLOAT32_C(  7820.406) } },
    { {  SIMDE_FLOAT32_C(  8992.982),  SIMDE_FLOAT32_C(  7814.275),  SIMDE_FLOAT32_C(  9353.939),  SIMDE_FLOAT32_C(  2474.339) },
      {  SIMDE_FLOAT32_C(  7863.002), -SIMDE_FLOAT32_C(   412.511),  SIMDE_FLOAT32_C(   196.362),  SIMDE_FLOAT32_C(  8459.223) },
      {  SIMDE_FLOAT32_C(  8459.223),  SIMDE_FLOAT32_C(  7814.275),  SIMDE_FLOAT32_C(  9353.939),  SIMDE_FLOAT32_C(  2474.339) },
      {  SIMDE_FLOAT32_C(  8992.982),  SIMDE_FLOAT32_C(   196.362),  SIMDE_FLOAT32_C(  9353.939),  SIMDE_FLOAT32_C(  2474.339) },
      {  SIMDE_FLOAT32_C(  8992.982),  SIMDE_FLOAT32_C(  7814.275), -SIMDE_FLOAT32_C(   412.511),  SIMDE_FLOAT32_C(  2474.339) },
      {  SIMDE_FLOAT32_C(  8992.982),  SIMDE_FLOAT32_C(  7814.275),  SIMDE_FLOAT32_C(  9353.939),  SIMDE_FLOAT32_C(  7863.002) } },
    { { -SIMDE_FLOAT32_C(  2949.494),  SIMDE_FLOAT32_C(  2614.980),  SIMDE_FLOAT32_C(  8780.445),  SIMDE_FLOAT32_C(  3656.842) },
      {  SIMDE_FLOAT32_C(  8306.215),  SIMDE_FLOAT32_C(  4706.809),  SIMDE_FLOAT32_C(  2470.985),  SIMDE_FLOAT32_C(  2624.702) },
      {  SIMDE_FLOAT32_C(  2624.702),  SIMDE_FLOAT32_C(  2614.980),  SIMDE_FLOAT32_C(  8780.445),  SIMDE_FLOAT32_C(  3656.842) },
      { -SIMDE_FLOAT32_C(  2949.494),  SIMDE_FLOAT32_C(  2470.985),  SIMDE_FLOAT32_C(  8780.445),  SIMDE_FLOAT32_C(  3656.842) },
      { -SIMDE_FLOAT32_C(  2949.494),  SIMDE_FLOAT32_C(  2614.980),  SIMDE_FLOAT32_C(  4706.809),  SIMDE_FLOAT32_C(  3656.842) },
      { -SIMDE_FLOAT32_C(  2949.494),  SIMDE_FLOAT32_C(  2614.980),  SIMDE_FLOAT32_C(  8780.445),  SIMDE_FLOAT32_C(  8306.215) } },
    { {  SIMDE_FLOAT32_C(  3479.178), -SIMDE_FLOAT32_C(  9729.815),  SIMDE_FLOAT32_C(   782.037),  SIMDE_FLOAT32_C(  1451.528) },
      { -SIMDE_FLOAT32_C(  1571.802), -SIMDE_FLOAT32_C(  8661.118), -SIMDE_FLOAT32_C(   447.722),  SIMDE_FLOAT32_C(  6319.575) },
      {  SIMDE_FLOAT32_C(  6319.575), -SIMDE_FLOAT32_C(  9729.815),  SIMDE_FLOAT32_C(   782.037),  SIMDE_FLOAT32_C(  1451.528) },
      {  SIMDE_FLOAT32_C(  3479.178), -SIMDE_FLOAT32_C(   447.722),  SIMDE_FLOAT32_C(   782.037),  SIMDE_FLOAT32_C(  1451.528) },
      {  SIMDE_FLOAT32_C(  3479.178), -SIMDE_FLOAT32_C(  9729.815), -SIMDE_FLOAT32_C(  8661.118),  SIMDE_FLOAT32_C(  1451.528) },
      {  SIMDE_FLOAT32_C(  3479.178), -SIMDE_FLOAT32_C(  9729.815),  SIMDE_FLOAT32_C(   782.037), -SIMDE_FLOAT32_C(  1571.802) } },
    { { -SIMDE_FLOAT32_C(  4819.511), -SIMDE_FLOAT32_C(  4667.547), -SIMDE_FLOAT32_C(  5410.779), -SIMDE_FLOAT32_C(  5298.958) },
      {  SIMDE_FLOAT32_C(  6992.926), -SIMDE_FLOAT32_C(  2054.155),  SIMDE_FLOAT32_C(  4552.382),  SIMDE_FLOAT32_C(  6344.732) },
      {  SIMDE_FLOAT32_C(  6344.732), -SIMDE_FLOAT32_C(  4667.547), -SIMDE_FLOAT32_C(  5410.779), -SIMDE_FLOAT32_C(  5298.958) },
      { -SIMDE_FLOAT32_C(  4819.511),  SIMDE_FLOAT32_C(  4552.382), -SIMDE_FLOAT32_C(  5410.779), -SIMDE_FLOAT32_C(  5298.958) },
      { -SIMDE_FLOAT32_C(  4819.511), -SIMDE_FLOAT32_C(  4667.547), -SIMDE_FLOAT32_C(  2054.155), -SIMDE_FLOAT32_C(  5298.958) },
      { -SIMDE_FLOAT32_C(  4819.511), -SIMDE_FLOAT32_C(  4667.547), -SIMDE_FLOAT32_C(  5410.779),  SIMDE_FLOAT32_C(  6992.926) } },
    { { -SIMDE_FLOAT32_C(  6145.318),  SIMDE_FLOAT32_C(  5380.021), -SIMDE_FLOAT32_C(  6940.736),  SIMDE_FLOAT32_C(  4362.208) },
      { -SIMDE_FLOAT32_C(  2727.117),  SIMDE_FLOAT32_C(  7132.807), -SIMDE_FLOAT32_C(  7647.750),  SIMDE_FLOAT32_C(  5286.702) },
      {  SIMDE_FLOAT32_C(  5286.702),  SIMDE_FLOAT32_C(  5380.021), -SIMDE_FLOAT32_C(  6940.736),  SIMDE_FLOAT32_C(  4362.208) },
      { -SIMDE_FLOAT32_C(  6145.318), -SIMDE_FLOAT32_C(  7647.750), -SIMDE_FLOAT32_C(  6940.736),  SIMDE_FLOAT32_C(  4362.208) },
      { -SIMDE_FLOAT32_C(  6145.318),  SIMDE_FLOAT32_C(  5380.021),  SIMDE_FLOAT32_C(  7132.807),  SIMDE_FLOAT32_C(  4362.208) },
      { -SIMDE_FLOAT32_C(  6145.318),  SIMDE_FLOAT32_C(  5380.021), -SIMDE_FLOAT32_C(  6940.736), -SIMDE_FLOAT32_C(  2727.117) } },
    { {  SIMDE_FLOAT32_C(  5009.768),  SIMDE_FLOAT32_C(  5052.221),  SIMDE_FLOAT32_C(  1795.097),  SIMDE_FLOAT32_C(  9838.342) },
      { -SIMDE_FLOAT32_C(  6042.081),  SIMDE_FLOAT32_C(   645.963),  SIMDE_FLOAT32_C(  1858.851), -SIMDE_FLOAT32_C(  8743.057) },
      { -SIMDE_FLOAT32_C(  8743.057),  SIMDE_FLOAT32_C(  5052.221),  SIMDE_FLOAT32_C(  1795.097),  SIMDE_FLOAT32_C(  9838.342) },
      {  SIMDE_FLOAT32_C(  5009.768),  SIMDE_FLOAT32_C(  1858.851),  SIMDE_FLOAT32_C(  1795.097),  SIMDE_FLOAT32_C(  9838.342) },
      {  SIMDE_FLOAT32_C(  5009.768),  SIMDE_FLOAT32_C(  5052.221),  SIMDE_FLOAT32_C(   645.963),  SIMDE_FLOAT32_C(  9838.342) },
      {  SIMDE_FLOAT32_C(  5009.768),  SIMDE_FLOAT32_C(  5052.221),  SIMDE_FLOAT32_C(  1795.097), -SIMDE_FLOAT32_C(  6042.081) } },
    { {  SIMDE_FLOAT32_C(  4248.810), -SIMDE_FLOAT32_C(  8662.274), -SIMDE_FLOAT32_C(  3328.998), -SIMDE_FLOAT32_C(  2036.577) },
      {  SIMDE_FLOAT32_C(  9358.539),  SIMDE_FLOAT32_C(  8204.385),  SIMDE_FLOAT32_C(  4985.117),  SIMDE_FLOAT32_C(   697.916) },
      {  SIMDE_FLOAT32_C(   697.916), -SIMDE_FLOAT32_C(  8662.274), -SIMDE_FLOAT32_C(  3328.998), -SIMDE_FLOAT32_C(  2036.577) },
      {  SIMDE_FLOAT32_C(  4248.810),  SIMDE_FLOAT32_C(  4985.117), -SIMDE_FLOAT32_C(  3328.998), -SIMDE_FLOAT32_C(  2036.577) },
      {  SIMDE_FLOAT32_C(  4248.810), -SIMDE_FLOAT32_C(  8662.274),  SIMDE_FLOAT32_C(  8204.385), -SIMDE_FLOAT32_C(  2036.577) },
      {  SIMDE_FLOAT32_C(  4248.810), -SIMDE_FLOAT32_C(  8662.274), -SIMDE_FLOAT32_C(  3328.998),  SIMDE_FLOAT32_C(  9358.539) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);

    simde_float32x4_t r0_3 = simde_vcopyq_laneq_f32(a, 0, b, 3);
    simde_float32x4_t r1_2 = simde_vcopyq_laneq_f32(a, 1, b, 2);
    simde_float32x4_t r2_1 = simde_vcopyq_laneq_f32(a, 2, b, 1);
    simde_float32x4_t r3_0 = simde_vcopyq_laneq_f32(a, 3, b, 0);

    simde_test_arm_neon_assert_equal_f32x4(r0_3, simde_vld1q_f32(test_vec[i].r0_3), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r1_2, simde_vld1q_f32(test_vec[i].r1_2), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r2_1, simde_vld1q_f32(test_vec[i].r2_1), INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r3_0, simde_vld1q_f32(test_vec[i].r3_0), INT_MAX);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r0_3 = simde_vcopyq_laneq_f32(a, 0, b, 3);
    simde_float32x4_t r1_2 = simde_vcopyq_laneq_f32(a, 1, b, 2);
    simde_float32x4_t r2_1 = simde_vcopyq_laneq_f32(a, 2, b, 1);
    simde_float32x4_t r3_0 = simde_vcopyq_laneq_f32(a, 3, b, 0);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r0_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r1_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r2_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r3_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t b[2];
    simde_float64_t r0_0[2];
    simde_float64_t r0_1[2];
    simde_float64_t r1_0[2];
    simde_float64_t r1_1[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT64_C(  678563.125),  SIMDE_FLOAT64_C(  194228.625) },
      {  SIMDE_FLOAT64_C(   42214.062),  SIMDE_FLOAT64_C(  747572.625) },
      {  SIMDE_FLOAT64_C(   42214.062),  SIMDE_FLOAT64_C(  194228.625) },
      {  SIMDE_FLOAT64_C(  747572.625),  SIMDE_FLOAT64_C(  194228.625) },
      { -SIMDE_FLOAT64_C(  678563.125),  SIMDE_FLOAT64_C(   42214.062) },
      { -SIMDE_FLOAT64_C(  678563.125),  SIMDE_FLOAT64_C(  747572.625) } },
    { { -SIMDE_FLOAT64_C(  672868.625),  SIMDE_FLOAT64_C(  823476.500) },
      { -SIMDE_FLOAT64_C(  249558.438),  SIMDE_FLOAT64_C(  445662.250) },
      { -SIMDE_FLOAT64_C(  249558.438),  SIMDE_FLOAT64_C(  823476.500) },
      {  SIMDE_FLOAT64_C(  445662.250),  SIMDE_FLOAT64_C(  823476.500) },
      { -SIMDE_FLOAT64_C(  672868.625), -SIMDE_FLOAT64_C(  249558.438) },
      { -SIMDE_FLOAT64_C(  672868.625),  SIMDE_FLOAT64_C(  445662.250) } },
    { { -SIMDE_FLOAT64_C(  760755.875),  SIMDE_FLOAT64_C(  382520.375) },
      {  SIMDE_FLOAT64_C(  767680.250), -SIMDE_FLOAT64_C(   74684.625) },
      {  SIMDE_FLOAT64_C(  767680.250),  SIMDE_FLOAT64_C(  382520.375) },
      { -SIMDE_FLOAT64_C(   74684.625),  SIMDE_FLOAT64_C(  382520.375) },
      { -SIMDE_FLOAT64_C(  760755.875),  SIMDE_FLOAT64_C(  767680.250) },
      { -SIMDE_FLOAT64_C(  760755.875), -SIMDE_FLOAT64_C(   74684.625) } },
    { { -SIMDE_FLOAT64_C(   34493.875),  SIMDE_FLOAT64_C(  196752.750) },
      { -SIMDE_FLOAT64_C(  164549.625),  SIMDE_FLOAT64_C(  930720.250) },
      { -SIMDE_FLOAT64_C(  164549.625),  SIMDE_FLOAT64_C(  196752.750) },
      {  SIMDE_FLOAT64_C(  930720.250),  SIMDE_FLOAT64_C(  196752.750) },
      { -SIMDE_FLOAT64_C(   34493.875), -SIMDE_FLOAT64_C(  164549.625) },
      { -SIMDE_FLOAT64_C(   34493.875),  SIMDE_FLOAT64_C(  930720.250) } },
    { { -SIMDE_FLOAT64_C(   88352.375),  SIMDE_FLOAT64_C(  286620.375) },
      { -SIMDE_FLOAT64_C(  353142.375), -SIMDE_FLOAT64_C(  187538.125) },
      { -SIMDE_FLOAT64_C(  353142.375),  SIMDE_FLOAT64_C(  286620.375) },
      { -SIMDE_FLOAT64_C(  187538.125),  SIMDE_FLOAT64_C(  286620.375) },
      { -SIMDE_FLOAT64_C(   88352.375), -SIMDE_FLOAT64_C(  353142.375) },
      { -SIMDE_FLOAT64_C(   88352.375), -SIMDE_FLOAT64_C(  187538.125) } },
    { {  SIMDE_FLOAT64_C(  896252.125), -SIMDE_FLOAT64_C(  543789.250) },
      { -SIMDE_FLOAT64_C(  384486.062),  SIMDE_FLOAT64_C(  366117.500) },
      { -SIMDE_FLOAT64_C(  384486.062), -SIMDE_FLOAT64_C(  543789.250) },
      {  SIMDE_FLOAT64_C(  366117.500), -SIMDE_FLOAT64_C(  543789.250) },
      {  SIMDE_FLOAT64_C(  896252.125), -SIMDE_FLOAT64_C(  384486.062) },
      {  SIMDE_FLOAT64_C(  896252.125),  SIMDE_FLOAT64_C(  366117.500) } },
    { {  SIMDE_FLOAT64_C(  921497.375),  SIMDE_FLOAT64_C(  126141.125) },
      { -SIMDE_FLOAT64_C(   84883.125),  SIMDE_FLOAT64_C(  833692.250) },
      { -SIMDE_FLOAT64_C(   84883.125),  SIMDE_FLOAT64_C(  126141.125) },
      {  SIMDE_FLOAT64_C(  833692.250),  SIMDE_FLOAT64_C(  126141.125) },
      {  SIMDE_FLOAT64_C(  921497.375), -SIMDE_FLOAT64_C(   84883.125) },
      {  SIMDE_FLOAT64_C(  921497.375),  SIMDE_FLOAT64_C(  833692.250) } },
    { {  SIMDE_FLOAT64_C(   63073.875), -SIMDE_FLOAT64_C(  637440.312) },
      {  SIMDE_FLOAT64_C(  955680.125),  SIMDE_FLOAT64_C(  696772.875) },
      {  SIMDE_FLOAT64_C(  955680.125), -SIMDE_FLOAT64_C(  637440.312) },
      {  SIMDE_FLOAT64_C(  696772.875), -SIMDE_FLOAT64_C(  637440.312) },
      {  SIMDE_FLOAT64_C(   63073.875),  SIMDE_FLOAT64_C(  955680.125) },
      {  SIMDE_FLOAT64_C(   63073.875),  SIMDE_FLOAT64_C(  696772.875) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);

    simde_float64x2_t r0_0 = simde_vcopyq_laneq_f64(a, 0, b, 0);
    simde_float64x2_t r0_1 = simde_vcopyq_laneq_f64(a, 0, b, 1);
    simde_float64x2_t r1_0 = simde_vcopyq_laneq_f64(a, 1, b, 0);
    simde_float64x2_t r1_1 = simde_vcopyq_laneq_f64(a, 1, b, 1);

    simde_test_arm_neon_assert_equal_f64x2(r0_0, simde_vld1q_f64(test_vec[i].r0_0), INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r0_1, simde_vld1q_f64(test_vec[i].r0_1), INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r1_0, simde_vld1q_f64(test_vec[i].r1_0), INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r1_1, simde_vld1q_f64(test_vec[i].r1_1), INT_MAX);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r0_0 = simde_vcopyq_laneq_f64(a, 0, b, 0);
    simde_float64x2_t r0_1 = simde_vcopyq_laneq_f64(a, 0, b, 1);
    simde_float64x2_t r1_0 = simde_vcopyq_laneq_f64(a, 1, b, 0);
    simde_float64x2_t r1_1 = simde_vcopyq_laneq_f64(a, 1, b, 1);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r0_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r1_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r1_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[8];
    simde_poly8_t b[8];
    simde_poly8_t r00[8];
    simde_poly8_t r13[8];
    simde_poly8_t r35[8];
    simde_poly8_t r67[8];
    simde_poly8_t r71[8];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  131),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(   60),
         SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  235) },
      {  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  168),
         SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(  204),  SIMDE_POLY8_C(   93),  SIMDE_POLY8_C(  235) },
      {  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  131),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(   60),
         SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  235) },
      {  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(   60),
         SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  235) },
      {  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  131),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(  204),
         SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  235) },
      {  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  131),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(   60),
         SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  235),  SIMDE_POLY8_C(  235) },
      {  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  131),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(   60),
         SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(   32) } },
    { {  SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(  224),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   63),  SIMDE_POLY8_C(  202) },
      {  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  130),  SIMDE_POLY8_C(   95),  SIMDE_POLY8_C(  209),
         SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  227),  SIMDE_POLY8_C(   12) },
      {  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(  224),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   63),  SIMDE_POLY8_C(  202) },
      {  SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(  209),  SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(  224),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   63),  SIMDE_POLY8_C(  202) },
      {  SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(  184),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   63),  SIMDE_POLY8_C(  202) },
      {  SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(  224),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(  202) },
      {  SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(  224),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   63),  SIMDE_POLY8_C(  130) } },
    { {  SIMDE_POLY8_C(  172),  SIMDE_POLY8_C(   54),  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(  209),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(   13),  SIMDE_POLY8_C(   59) },
      {  SIMDE_POLY8_C(   88),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(  203),  SIMDE_POLY8_C(   38),
         SIMDE_POLY8_C(  153),  SIMDE_POLY8_C(  233),  SIMDE_POLY8_C(   84),  SIMDE_POLY8_C(   56) },
      {  SIMDE_POLY8_C(   88),  SIMDE_POLY8_C(   54),  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(  209),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(   13),  SIMDE_POLY8_C(   59) },
      {  SIMDE_POLY8_C(  172),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(  209),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(   13),  SIMDE_POLY8_C(   59) },
      {  SIMDE_POLY8_C(  172),  SIMDE_POLY8_C(   54),  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(  233),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(   13),  SIMDE_POLY8_C(   59) },
      {  SIMDE_POLY8_C(  172),  SIMDE_POLY8_C(   54),  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(  209),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   59) },
      {  SIMDE_POLY8_C(  172),  SIMDE_POLY8_C(   54),  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(  209),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(   13),  SIMDE_POLY8_C(  109) } },
    { {  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  249),
         SIMDE_POLY8_C(   55),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(  195),  SIMDE_POLY8_C(  252) },
      {  SIMDE_POLY8_C(  137),  SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(   28),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(  202),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(   75) },
      {  SIMDE_POLY8_C(  137),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  249),
         SIMDE_POLY8_C(   55),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(  195),  SIMDE_POLY8_C(  252) },
      {  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  249),
         SIMDE_POLY8_C(   55),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(  195),  SIMDE_POLY8_C(  252) },
      {  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  202),
         SIMDE_POLY8_C(   55),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(  195),  SIMDE_POLY8_C(  252) },
      {  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  249),
         SIMDE_POLY8_C(   55),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(  252) },
      {  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  249),
         SIMDE_POLY8_C(   55),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(  195),  SIMDE_POLY8_C(  122) } },
    { {  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(  212),
         SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(  179) },
      {  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  170),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  164),
         SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(   25),  SIMDE_POLY8_C(   80),  SIMDE_POLY8_C(   95) },
      {  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(  212),
         SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(  179) },
      {  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(  212),
         SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(  179) },
      {  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   25),
         SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(  179) },
      {  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(  212),
         SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(   95),  SIMDE_POLY8_C(  179) },
      {  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(  212),
         SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(  170) } },
    { {  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(  233),
         SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  180),  SIMDE_POLY8_C(   31),  SIMDE_POLY8_C(   55) },
      {  SIMDE_POLY8_C(   70),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  163),
         SIMDE_POLY8_C(   92),  SIMDE_POLY8_C(   80),  SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(  246) },
      {  SIMDE_POLY8_C(   70),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(  233),
         SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  180),  SIMDE_POLY8_C(   31),  SIMDE_POLY8_C(   55) },
      {  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  163),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(  233),
         SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  180),  SIMDE_POLY8_C(   31),  SIMDE_POLY8_C(   55) },
      {  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(   80),
         SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  180),  SIMDE_POLY8_C(   31),  SIMDE_POLY8_C(   55) },
      {  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(  233),
         SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  180),  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(   55) },
      {  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(  233),
         SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  180),  SIMDE_POLY8_C(   31),  SIMDE_POLY8_C(  169) } },
    { {  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(  200),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(  164),
         SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  159) },
      {  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(   92),  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(   62),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  150),  SIMDE_POLY8_C(  218),  SIMDE_POLY8_C(  187) },
      {  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(  200),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(  164),
         SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  159) },
      {  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(  164),
         SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  159) },
      {  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(  200),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(  150),
         SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  159) },
      {  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(  200),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(  164),
         SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(  187),  SIMDE_POLY8_C(  159) },
      {  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(  200),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(  164),
         SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(   92) } },
    { {  SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(   17),  SIMDE_POLY8_C(  219),  SIMDE_POLY8_C(   25),
         SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(   22) },
      {  SIMDE_POLY8_C(  183),  SIMDE_POLY8_C(   91),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   21),
         SIMDE_POLY8_C(  129),  SIMDE_POLY8_C(  215),  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(  219) },
      {  SIMDE_POLY8_C(  183),  SIMDE_POLY8_C(   17),  SIMDE_POLY8_C(  219),  SIMDE_POLY8_C(   25),
         SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(   22) },
      {  SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  219),  SIMDE_POLY8_C(   25),
         SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(   22) },
      {  SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(   17),  SIMDE_POLY8_C(  219),  SIMDE_POLY8_C(  215),
         SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(   22) },
      {  SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(   17),  SIMDE_POLY8_C(  219),  SIMDE_POLY8_C(   25),
         SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  219),  SIMDE_POLY8_C(   22) },
      {  SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(   17),  SIMDE_POLY8_C(  219),  SIMDE_POLY8_C(   25),
         SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(   91) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);

    simde_poly8x8_t r00 = simde_vcopy_lane_p8(a, 0, b, 0);
    simde_poly8x8_t r13 = simde_vcopy_lane_p8(a, 1, b, 3);
    simde_poly8x8_t r35 = simde_vcopy_lane_p8(a, 3, b, 5);
    simde_poly8x8_t r67 = simde_vcopy_lane_p8(a, 6, b, 7);
    simde_poly8x8_t r71 = simde_vcopy_lane_p8(a, 7, b, 1);

    simde_test_arm_neon_assert_equal_p8x8(r00, simde_vld1_p8(test_vec[i].r00));
    simde_test_arm_neon_assert_equal_p8x8(r13, simde_vld1_p8(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p8x8(r35, simde_vld1_p8(test_vec[i].r35));
    simde_test_arm_neon_assert_equal_p8x8(r67, simde_vld1_p8(test_vec[i].r67));
    simde_test_arm_neon_assert_equal_p8x8(r71, simde_vld1_p8(test_vec[i].r71));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8_t a = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t b = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t r00 = simde_vcopy_lane_p8(a, 0, b, 0);
    simde_poly8x8_t r13 = simde_vcopy_lane_p8(a, 1, b, 3);
    simde_poly8x8_t r35 = simde_vcopy_lane_p8(a, 3, b, 5);
    simde_poly8x8_t r67 = simde_vcopy_lane_p8(a, 6, b, 7);
    simde_poly8x8_t r71 = simde_vcopy_lane_p8(a, 7, b, 1);

    simde_test_arm_neon_write_p8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r35, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r67, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r71, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[4];
    simde_poly16_t b[4];
    simde_poly16_t r00[4];
    simde_poly16_t r01[4];
    simde_poly16_t r13[4];
    simde_poly16_t r22[4];
    simde_poly16_t r33[4];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(   48859),  SIMDE_POLY16_C(   37110),  SIMDE_POLY16_C(   57365),  SIMDE_POLY16_C(   56893) },
      {  SIMDE_POLY16_C(   44198),  SIMDE_POLY16_C(   17208),  SIMDE_POLY16_C(   42682),  SIMDE_POLY16_C(   14084) },
      {  SIMDE_POLY16_C(   44198),  SIMDE_POLY16_C(   37110),  SIMDE_POLY16_C(   57365),  SIMDE_POLY16_C(   56893) },
      {  SIMDE_POLY16_C(   17208),  SIMDE_POLY16_C(   37110),  SIMDE_POLY16_C(   57365),  SIMDE_POLY16_C(   56893) },
      {  SIMDE_POLY16_C(   48859),  SIMDE_POLY16_C(   14084),  SIMDE_POLY16_C(   57365),  SIMDE_POLY16_C(   56893) },
      {  SIMDE_POLY16_C(   48859),  SIMDE_POLY16_C(   37110),  SIMDE_POLY16_C(   42682),  SIMDE_POLY16_C(   56893) },
      {  SIMDE_POLY16_C(   48859),  SIMDE_POLY16_C(   37110),  SIMDE_POLY16_C(   57365),  SIMDE_POLY16_C(   14084) } },
    { {  SIMDE_POLY16_C(   32518),  SIMDE_POLY16_C(   27430),  SIMDE_POLY16_C(   25434),  SIMDE_POLY16_C(   15734) },
      {  SIMDE_POLY16_C(   17681),  SIMDE_POLY16_C(    1758),  SIMDE_POLY16_C(   14425),  SIMDE_POLY16_C(   18152) },
      {  SIMDE_POLY16_C(   17681),  SIMDE_POLY16_C(   27430),  SIMDE_POLY16_C(   25434),  SIMDE_POLY16_C(   15734) },
      {  SIMDE_POLY16_C(    1758),  SIMDE_POLY16_C(   27430),  SIMDE_POLY16_C(   25434),  SIMDE_POLY16_C(   15734) },
      {  SIMDE_POLY16_C(   32518),  SIMDE_POLY16_C(   18152),  SIMDE_POLY16_C(   25434),  SIMDE_POLY16_C(   15734) },
      {  SIMDE_POLY16_C(   32518),  SIMDE_POLY16_C(   27430),  SIMDE_POLY16_C(   14425),  SIMDE_POLY16_C(   15734) },
      {  SIMDE_POLY16_C(   32518),  SIMDE_POLY16_C(   27430),  SIMDE_POLY16_C(   25434),  SIMDE_POLY16_C(   18152) } },
    { {  SIMDE_POLY16_C(   35029),  SIMDE_POLY16_C(   40800),  SIMDE_POLY16_C(   57927),  SIMDE_POLY16_C(   58796) },
      {  SIMDE_POLY16_C(   38243),  SIMDE_POLY16_C(   28472),  SIMDE_POLY16_C(   61138),  SIMDE_POLY16_C(   52923) },
      {  SIMDE_POLY16_C(   38243),  SIMDE_POLY16_C(   40800),  SIMDE_POLY16_C(   57927),  SIMDE_POLY16_C(   58796) },
      {  SIMDE_POLY16_C(   28472),  SIMDE_POLY16_C(   40800),  SIMDE_POLY16_C(   57927),  SIMDE_POLY16_C(   58796) },
      {  SIMDE_POLY16_C(   35029),  SIMDE_POLY16_C(   52923),  SIMDE_POLY16_C(   57927),  SIMDE_POLY16_C(   58796) },
      {  SIMDE_POLY16_C(   35029),  SIMDE_POLY16_C(   40800),  SIMDE_POLY16_C(   61138),  SIMDE_POLY16_C(   58796) },
      {  SIMDE_POLY16_C(   35029),  SIMDE_POLY16_C(   40800),  SIMDE_POLY16_C(   57927),  SIMDE_POLY16_C(   52923) } },
    { {  SIMDE_POLY16_C(   14462),  SIMDE_POLY16_C(   31329),  SIMDE_POLY16_C(   44021),  SIMDE_POLY16_C(   37135) },
      {  SIMDE_POLY16_C(   36643),  SIMDE_POLY16_C(    8499),  SIMDE_POLY16_C(   55329),  SIMDE_POLY16_C(   45901) },
      {  SIMDE_POLY16_C(   36643),  SIMDE_POLY16_C(   31329),  SIMDE_POLY16_C(   44021),  SIMDE_POLY16_C(   37135) },
      {  SIMDE_POLY16_C(    8499),  SIMDE_POLY16_C(   31329),  SIMDE_POLY16_C(   44021),  SIMDE_POLY16_C(   37135) },
      {  SIMDE_POLY16_C(   14462),  SIMDE_POLY16_C(   45901),  SIMDE_POLY16_C(   44021),  SIMDE_POLY16_C(   37135) },
      {  SIMDE_POLY16_C(   14462),  SIMDE_POLY16_C(   31329),  SIMDE_POLY16_C(   55329),  SIMDE_POLY16_C(   37135) },
      {  SIMDE_POLY16_C(   14462),  SIMDE_POLY16_C(   31329),  SIMDE_POLY16_C(   44021),  SIMDE_POLY16_C(   45901) } },
    { {  SIMDE_POLY16_C(   18155),  SIMDE_POLY16_C(   29451),  SIMDE_POLY16_C(    9594),  SIMDE_POLY16_C(   47476) },
      {  SIMDE_POLY16_C(   36782),  SIMDE_POLY16_C(   10647),  SIMDE_POLY16_C(   14223),  SIMDE_POLY16_C(    3446) },
      {  SIMDE_POLY16_C(   36782),  SIMDE_POLY16_C(   29451),  SIMDE_POLY16_C(    9594),  SIMDE_POLY16_C(   47476) },
      {  SIMDE_POLY16_C(   10647),  SIMDE_POLY16_C(   29451),  SIMDE_POLY16_C(    9594),  SIMDE_POLY16_C(   47476) },
      {  SIMDE_POLY16_C(   18155),  SIMDE_POLY16_C(    3446),  SIMDE_POLY16_C(    9594),  SIMDE_POLY16_C(   47476) },
      {  SIMDE_POLY16_C(   18155),  SIMDE_POLY16_C(   29451),  SIMDE_POLY16_C(   14223),  SIMDE_POLY16_C(   47476) },
      {  SIMDE_POLY16_C(   18155),  SIMDE_POLY16_C(   29451),  SIMDE_POLY16_C(    9594),  SIMDE_POLY16_C(    3446) } },
    { {  SIMDE_POLY16_C(   39055),  SIMDE_POLY16_C(   58824),  SIMDE_POLY16_C(   16709),  SIMDE_POLY16_C(   26292) },
      {  SIMDE_POLY16_C(   52894),  SIMDE_POLY16_C(   53794),  SIMDE_POLY16_C(   27364),  SIMDE_POLY16_C(    9410) },
      {  SIMDE_POLY16_C(   52894),  SIMDE_POLY16_C(   58824),  SIMDE_POLY16_C(   16709),  SIMDE_POLY16_C(   26292) },
      {  SIMDE_POLY16_C(   53794),  SIMDE_POLY16_C(   58824),  SIMDE_POLY16_C(   16709),  SIMDE_POLY16_C(   26292) },
      {  SIMDE_POLY16_C(   39055),  SIMDE_POLY16_C(    9410),  SIMDE_POLY16_C(   16709),  SIMDE_POLY16_C(   26292) },
      {  SIMDE_POLY16_C(   39055),  SIMDE_POLY16_C(   58824),  SIMDE_POLY16_C(   27364),  SIMDE_POLY16_C(   26292) },
      {  SIMDE_POLY16_C(   39055),  SIMDE_POLY16_C(   58824),  SIMDE_POLY16_C(   16709),  SIMDE_POLY16_C(    9410) } },
    { {  SIMDE_POLY16_C(    3714),  SIMDE_POLY16_C(   45544),  SIMDE_POLY16_C(   10782),  SIMDE_POLY16_C(   53336) },
      {  SIMDE_POLY16_C(   53247),  SIMDE_POLY16_C(   29686),  SIMDE_POLY16_C(   23527),  SIMDE_POLY16_C(   52801) },
      {  SIMDE_POLY16_C(   53247),  SIMDE_POLY16_C(   45544),  SIMDE_POLY16_C(   10782),  SIMDE_POLY16_C(   53336) },
      {  SIMDE_POLY16_C(   29686),  SIMDE_POLY16_C(   45544),  SIMDE_POLY16_C(   10782),  SIMDE_POLY16_C(   53336) },
      {  SIMDE_POLY16_C(    3714),  SIMDE_POLY16_C(   52801),  SIMDE_POLY16_C(   10782),  SIMDE_POLY16_C(   53336) },
      {  SIMDE_POLY16_C(    3714),  SIMDE_POLY16_C(   45544),  SIMDE_POLY16_C(   23527),  SIMDE_POLY16_C(   53336) },
      {  SIMDE_POLY16_C(    3714),  SIMDE_POLY16_C(   45544),  SIMDE_POLY16_C(   10782),  SIMDE_POLY16_C(   52801) } },
    { {  SIMDE_POLY16_C(     956),  SIMDE_POLY16_C(   38216),  SIMDE_POLY16_C(   64583),  SIMDE_POLY16_C(   19844) },
      {  SIMDE_POLY16_C(   55529),  SIMDE_POLY16_C(    5655),  SIMDE_POLY16_C(   39007),  SIMDE_POLY16_C(   36038) },
      {  SIMDE_POLY16_C(   55529),  SIMDE_POLY16_C(   38216),  SIMDE_POLY16_C(   64583),  SIMDE_POLY16_C(   19844) },
      {  SIMDE_POLY16_C(    5655),  SIMDE_POLY16_C(   38216),  SIMDE_POLY16_C(   64583),  SIMDE_POLY16_C(   19844) },
      {  SIMDE_POLY16_C(     956),  SIMDE_POLY16_C(   36038),  SIMDE_POLY16_C(   64583),  SIMDE_POLY16_C(   19844) },
      {  SIMDE_POLY16_C(     956),  SIMDE_POLY16_C(   38216),  SIMDE_POLY16_C(   39007),  SIMDE_POLY16_C(   19844) },
      {  SIMDE_POLY16_C(     956),  SIMDE_POLY16_C(   38216),  SIMDE_POLY16_C(   64583),  SIMDE_POLY16_C(   36038) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);

    simde_poly16x4_t r00 = simde_vcopy_lane_p16(a, 0, b, 0);
    simde_poly16x4_t r01 = simde_vcopy_lane_p16(a, 0, b, 1);
    simde_poly16x4_t r13 = simde_vcopy_lane_p16(a, 1, b, 3);
    simde_poly16x4_t r22 = simde_vcopy_lane_p16(a, 2, b, 2);
    simde_poly16x4_t r33 = simde_vcopy_lane_p16(a, 3, b, 3);

    simde_test_arm_neon_assert_equal_p16x4(r00, simde_vld1_p16(test_vec[i].r00));
    simde_test_arm_neon_assert_equal_p16x4(r01, simde_vld1_p16(test_vec[i].r01));
    simde_test_arm_neon_assert_equal_p16x4(r13, simde_vld1_p16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p16x4(r22, simde_vld1_p16(test_vec[i].r22));
    simde_test_arm_neon_assert_equal_p16x4(r33, simde_vld1_p16(test_vec[i].r33));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x4_t a = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t b = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t r00 = simde_vcopy_lane_p16(a, 0, b, 0);
    simde_poly16x4_t r01 = simde_vcopy_lane_p16(a, 0, b, 1);
    simde_poly16x4_t r13 = simde_vcopy_lane_p16(a, 1, b, 3);
    simde_poly16x4_t r22 = simde_vcopy_lane_p16(a, 2, b, 2);
    simde_poly16x4_t r33 = simde_vcopy_lane_p16(a, 3, b, 3);

    simde_test_arm_neon_write_p16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r01, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r22, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r33, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[1];
    simde_poly64_t b[1];
    simde_poly64_t r00[1];
  } test_vec[] = {
    { {  SIMDE_POLY64_C( 3055880545951251893) },
      {  SIMDE_POLY64_C( 4769400864024572261) },
      {  SIMDE_POLY64_C( 4769400864024572261) } },
    { {  SIMDE_POLY64_C(10022377050862213090) },
      {  SIMDE_POLY64_C(  709100166864470872) },
      {  SIMDE_POLY64_C(  709100166864470872) } },
    { {  SIMDE_POLY64_C(14501613329003973833) },
      {  SIMDE_POLY64_C( 1949783300048066942) },
      {  SIMDE_POLY64_C( 1949783300048066942) } },
    { {  SIMDE_POLY64_C( 4269142848878481025) },
      {  SIMDE_POLY64_C(13395296486420650805) },
      {  SIMDE_POLY64_C(13395296486420650805) } },
    { {  SIMDE_POLY64_C(16135277955010204355) },
      {  SIMDE_POLY64_C( 8074912141013526827) },
      {  SIMDE_POLY64_C( 8074912141013526827) } },
    { {  SIMDE_POLY64_C( 2540591871860474721) },
      {  SIMDE_POLY64_C( 3018004574689373093) },
      {  SIMDE_POLY64_C( 3018004574689373093) } },
    { {  SIMDE_POLY64_C( 6078212644320502818) },
      {  SIMDE_POLY64_C( 5640613611397537144) },
      {  SIMDE_POLY64_C( 5640613611397537144) } },
    { {  SIMDE_POLY64_C(17738531384755593185) },
      {  SIMDE_POLY64_C(12574375413058459129) },
      {  SIMDE_POLY64_C(12574375413058459129) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1_t a = simde_vld1_p64(test_vec[i].a);
    simde_poly64x1_t b = simde_vld1_p64(test_vec[i].b);

    simde_poly64x1_t r00 = simde_vcopy_lane_p64(a, 0, b, 0);

    simde_test_arm_neon_assert_equal_p64x1(r00, simde_vld1_p64(test_vec[i].r00));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x1_t a = simde_test_arm_neon_random_p64x1();
    simde_poly64x1_t b = simde_test_arm_neon_random_p64x1();
    simde_poly64x1_t r00 = simde_vcopy_lane_p64(a, 0, b, 0);

    simde_test_arm_neon_write_p64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r00, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[8];
    simde_poly8_t b[16];
    simde_poly8_t r0_0[8];
    simde_poly8_t r1_3[8];
    simde_poly8_t r3_8[8];
    simde_poly8_t r6_12[8];
    simde_poly8_t r7_15[8];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(   40),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   35),
         SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   87),  SIMDE_POLY8_C(  222) },
      {  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  221),
         SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  198),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   81),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  118),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(  200),
         SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(  165),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(   99) },
      {  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(   40),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   35),
         SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   87),  SIMDE_POLY8_C(  222) },
      {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(  221),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   35),
         SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   87),  SIMDE_POLY8_C(  222) },
      {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(   40),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(  184),
         SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   87),  SIMDE_POLY8_C(  222) },
      {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(   40),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   35),
         SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(  222) },
      {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(   40),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   35),
         SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   87),  SIMDE_POLY8_C(   99) } },
    { {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   86),  SIMDE_POLY8_C(  230),  SIMDE_POLY8_C(  248),
         SIMDE_POLY8_C(   64),  SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(   69) },
      {  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(  192),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(   82),  SIMDE_POLY8_C(   86),
         SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(   57),
         SIMDE_POLY8_C(  162),  SIMDE_POLY8_C(  132),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(   69) },
      {  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(   86),  SIMDE_POLY8_C(  230),  SIMDE_POLY8_C(  248),
         SIMDE_POLY8_C(   64),  SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(   69) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  230),  SIMDE_POLY8_C(  248),
         SIMDE_POLY8_C(   64),  SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(   69) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   86),  SIMDE_POLY8_C(  230),  SIMDE_POLY8_C(  253),
         SIMDE_POLY8_C(   64),  SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(   69) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   86),  SIMDE_POLY8_C(  230),  SIMDE_POLY8_C(  248),
         SIMDE_POLY8_C(   64),  SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(  162),  SIMDE_POLY8_C(   69) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   86),  SIMDE_POLY8_C(  230),  SIMDE_POLY8_C(  248),
         SIMDE_POLY8_C(   64),  SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(   69) } },
    { {  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   91),  SIMDE_POLY8_C(  206),  SIMDE_POLY8_C(  196) },
      {  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(   23),
         SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(   31),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  146),
         SIMDE_POLY8_C(    3),  SIMDE_POLY8_C(  218),  SIMDE_POLY8_C(   80),  SIMDE_POLY8_C(  224) },
      {  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   91),  SIMDE_POLY8_C(  206),  SIMDE_POLY8_C(  196) },
      {  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(   23),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   91),  SIMDE_POLY8_C(  206),  SIMDE_POLY8_C(  196) },
      {  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  105),
         SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   91),  SIMDE_POLY8_C(  206),  SIMDE_POLY8_C(  196) },
      {  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   91),  SIMDE_POLY8_C(    3),  SIMDE_POLY8_C(  196) },
      {  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   91),  SIMDE_POLY8_C(  206),  SIMDE_POLY8_C(  224) } },
    { {  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   44),
         SIMDE_POLY8_C(  217),  SIMDE_POLY8_C(  170),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(  181) },
      {  SIMDE_POLY8_C(   69),  SIMDE_POLY8_C(  115),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(  237),
         SIMDE_POLY8_C(  116),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  212),
         SIMDE_POLY8_C(  149),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(  106),  SIMDE_POLY8_C(   27),
         SIMDE_POLY8_C(  249),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(  133) },
      {  SIMDE_POLY8_C(   69),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   44),
         SIMDE_POLY8_C(  217),  SIMDE_POLY8_C(  170),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(  181) },
      {  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  237),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   44),
         SIMDE_POLY8_C(  217),  SIMDE_POLY8_C(  170),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(  181) },
      {  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(  149),
         SIMDE_POLY8_C(  217),  SIMDE_POLY8_C(  170),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(  181) },
      {  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   44),
         SIMDE_POLY8_C(  217),  SIMDE_POLY8_C(  170),  SIMDE_POLY8_C(  249),  SIMDE_POLY8_C(  181) },
      {  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   44),
         SIMDE_POLY8_C(  217),  SIMDE_POLY8_C(  170),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(  133) } },
    { {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(UINT8_MAX),
         SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(   40) },
      {  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  120),  SIMDE_POLY8_C(  120),  SIMDE_POLY8_C(  177),
         SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  251),  SIMDE_POLY8_C(  121),
         SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(   18),  SIMDE_POLY8_C(  149),  SIMDE_POLY8_C(   67),
         SIMDE_POLY8_C(  176),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(  139),  SIMDE_POLY8_C(  203) },
      {  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(UINT8_MAX),
         SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(   40) },
      {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(UINT8_MAX),
         SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(   40) },
      {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(  185),
         SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(   40) },
      {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(UINT8_MAX),
         SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  176),  SIMDE_POLY8_C(   40) },
      {  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(UINT8_MAX),
         SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(  203) } },
    { {  SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(   59),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  250),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  170) },
      {  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   92),  SIMDE_POLY8_C(   84),
         SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(   54),  SIMDE_POLY8_C(   70),
         SIMDE_POLY8_C(   74),  SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  204),
         SIMDE_POLY8_C(  114),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  146),  SIMDE_POLY8_C(   53) },
      {  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(   59),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  250),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  170) },
      {  SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(   84),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(   59),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  250),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  170) },
      {  SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(   74),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  250),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  170) },
      {  SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(   59),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  250),  SIMDE_POLY8_C(  114),  SIMDE_POLY8_C(  170) },
      {  SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(   59),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  250),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(   53) } },
    { {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(  195),
         SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(  186) },
      {  SIMDE_POLY8_C(    9),  SIMDE_POLY8_C(  138),  SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(   97),
         SIMDE_POLY8_C(  120),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(  155),  SIMDE_POLY8_C(   29),
         SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(   10),  SIMDE_POLY8_C(  220),
         SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  194),  SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(  218) },
      {  SIMDE_POLY8_C(    9),  SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(  195),
         SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(  186) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(  195),
         SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(  186) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(    5),
         SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(  186) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(  195),
         SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  186) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(  195),
         SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(  218) } },
    { {  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   62),
         SIMDE_POLY8_C(  203),  SIMDE_POLY8_C(   46),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(  247) },
      {  SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  199),  SIMDE_POLY8_C(   65),  SIMDE_POLY8_C(  133),
         SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(  218),  SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(   55),
         SIMDE_POLY8_C(  217),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(  216),  SIMDE_POLY8_C(   57),
         SIMDE_POLY8_C(  204),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(  253) },
      {  SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   62),
         SIMDE_POLY8_C(  203),  SIMDE_POLY8_C(   46),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(  247) },
      {  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   62),
         SIMDE_POLY8_C(  203),  SIMDE_POLY8_C(   46),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(  247) },
      {  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  217),
         SIMDE_POLY8_C(  203),  SIMDE_POLY8_C(   46),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(  247) },
      {  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   62),
         SIMDE_POLY8_C(  203),  SIMDE_POLY8_C(   46),  SIMDE_POLY8_C(  204),  SIMDE_POLY8_C(  247) },
      {  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(   62),
         SIMDE_POLY8_C(  203),  SIMDE_POLY8_C(   46),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(  253) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);

    simde_poly8x8_t r0_0 = simde_vcopy_laneq_p8(a, 0, b, 0);
    simde_poly8x8_t r1_3 = simde_vcopy_laneq_p8(a, 1, b, 3);
    simde_poly8x8_t r3_8 = simde_vcopy_laneq_p8(a, 3, b, 8);
    simde_poly8x8_t r6_12 = simde_vcopy_laneq_p8(a, 6, b, 12);
    simde_poly8x8_t r7_15 = simde_vcopy_laneq_p8(a, 7, b, 15);

    simde_test_arm_neon_assert_equal_p8x8(r0_0, simde_vld1_p8(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_p8x8(r1_3, simde_vld1_p8(test_vec[i].r1_3));
    simde_test_arm_neon_assert_equal_p8x8(r3_8, simde_vld1_p8(test_vec[i].r3_8));
    simde_test_arm_neon_assert_equal_p8x8(r6_12, simde_vld1_p8(test_vec[i].r6_12));
    simde_test_arm_neon_assert_equal_p8x8(r7_15, simde_vld1_p8(test_vec[i].r7_15));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8_t a = simde_test_arm_neon_random_p8x8();
    simde_poly8x16_t b = simde_test_arm_neon_random_p8x16();
    simde_poly8x8_t r0_0 = simde_vcopy_laneq_p8(a, 0, b, 0);
    simde_poly8x8_t r1_3 = simde_vcopy_laneq_p8(a, 1, b, 3);
    simde_poly8x8_t r3_8 = simde_vcopy_laneq_p8(a, 3, b, 8);
    simde_poly8x8_t r6_12 = simde_vcopy_laneq_p8(a, 6, b, 12);
    simde_poly8x8_t r7_15 = simde_vcopy_laneq_p8(a, 7, b, 15);

    simde_test_arm_neon_write_p8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r1_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r3_8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r6_12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r7_15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[4];
    simde_poly16_t b[8];
    simde_poly16_t r0_0[4];
    simde_poly16_t r1_3[4];
    simde_poly16_t r2_5[4];
    simde_poly16_t r3_7[4];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(   14090),  SIMDE_POLY16_C(   43348),  SIMDE_POLY16_C(   44694),  SIMDE_POLY16_C(   30737) },
      {  SIMDE_POLY16_C(   38617),  SIMDE_POLY16_C(   33902),  SIMDE_POLY16_C(      90),  SIMDE_POLY16_C(   41210),
         SIMDE_POLY16_C(   36570),  SIMDE_POLY16_C(   20021),  SIMDE_POLY16_C(    3767),  SIMDE_POLY16_C(   62186) },
      {  SIMDE_POLY16_C(   38617),  SIMDE_POLY16_C(   43348),  SIMDE_POLY16_C(   44694),  SIMDE_POLY16_C(   30737) },
      {  SIMDE_POLY16_C(   14090),  SIMDE_POLY16_C(   41210),  SIMDE_POLY16_C(   44694),  SIMDE_POLY16_C(   30737) },
      {  SIMDE_POLY16_C(   14090),  SIMDE_POLY16_C(   43348),  SIMDE_POLY16_C(   20021),  SIMDE_POLY16_C(   30737) },
      {  SIMDE_POLY16_C(   14090),  SIMDE_POLY16_C(   43348),  SIMDE_POLY16_C(   44694),  SIMDE_POLY16_C(   62186) } },
    { {  SIMDE_POLY16_C(   61109),  SIMDE_POLY16_C(   30682),  SIMDE_POLY16_C(   62985),  SIMDE_POLY16_C(   21741) },
      {  SIMDE_POLY16_C(   19675),  SIMDE_POLY16_C(   47463),  SIMDE_POLY16_C(   48866),  SIMDE_POLY16_C(   48845),
         SIMDE_POLY16_C(   50845),  SIMDE_POLY16_C(   43216),  SIMDE_POLY16_C(    9981),  SIMDE_POLY16_C(   42973) },
      {  SIMDE_POLY16_C(   19675),  SIMDE_POLY16_C(   30682),  SIMDE_POLY16_C(   62985),  SIMDE_POLY16_C(   21741) },
      {  SIMDE_POLY16_C(   61109),  SIMDE_POLY16_C(   48845),  SIMDE_POLY16_C(   62985),  SIMDE_POLY16_C(   21741) },
      {  SIMDE_POLY16_C(   61109),  SIMDE_POLY16_C(   30682),  SIMDE_POLY16_C(   43216),  SIMDE_POLY16_C(   21741) },
      {  SIMDE_POLY16_C(   61109),  SIMDE_POLY16_C(   30682),  SIMDE_POLY16_C(   62985),  SIMDE_POLY16_C(   42973) } },
    { {  SIMDE_POLY16_C(   31349),  SIMDE_POLY16_C(   64794),  SIMDE_POLY16_C(   25390),  SIMDE_POLY16_C(   50931) },
      {  SIMDE_POLY16_C(   20875),  SIMDE_POLY16_C(   26295),  SIMDE_POLY16_C(   47031),  SIMDE_POLY16_C(   37393),
         SIMDE_POLY16_C(    8989),  SIMDE_POLY16_C(    1142),  SIMDE_POLY16_C(     891),  SIMDE_POLY16_C(   41568) },
      {  SIMDE_POLY16_C(   20875),  SIMDE_POLY16_C(   64794),  SIMDE_POLY16_C(   25390),  SIMDE_POLY16_C(   50931) },
      {  SIMDE_POLY16_C(   31349),  SIMDE_POLY16_C(   37393),  SIMDE_POLY16_C(   25390),  SIMDE_POLY16_C(   50931) },
      {  SIMDE_POLY16_C(   31349),  SIMDE_POLY16_C(   64794),  SIMDE_POLY16_C(    1142),  SIMDE_POLY16_C(   50931) },
      {  SIMDE_POLY16_C(   31349),  SIMDE_POLY16_C(   64794),  SIMDE_POLY16_C(   25390),  SIMDE_POLY16_C(   41568) } },
    { {  SIMDE_POLY16_C(   27978),  SIMDE_POLY16_C(   43843),  SIMDE_POLY16_C(   22177),  SIMDE_POLY16_C(   31195) },
      {  SIMDE_POLY16_C(   13000),  SIMDE_POLY16_C(   19847),  SIMDE_POLY16_C(   29376),  SIMDE_POLY16_C(   26702),
         SIMDE_POLY16_C(   12549),  SIMDE_POLY16_C(   33267),  SIMDE_POLY16_C(   27103),  SIMDE_POLY16_C(   28719) },
      {  SIMDE_POLY16_C(   13000),  SIMDE_POLY16_C(   43843),  SIMDE_POLY16_C(   22177),  SIMDE_POLY16_C(   31195) },
      {  SIMDE_POLY16_C(   27978),  SIMDE_POLY16_C(   26702),  SIMDE_POLY16_C(   22177),  SIMDE_POLY16_C(   31195) },
      {  SIMDE_POLY16_C(   27978),  SIMDE_POLY16_C(   43843),  SIMDE_POLY16_C(   33267),  SIMDE_POLY16_C(   31195) },
      {  SIMDE_POLY16_C(   27978),  SIMDE_POLY16_C(   43843),  SIMDE_POLY16_C(   22177),  SIMDE_POLY16_C(   28719) } },
    { {  SIMDE_POLY16_C(    1114),  SIMDE_POLY16_C(   44831),  SIMDE_POLY16_C(   23387),  SIMDE_POLY16_C(   26671) },
      {  SIMDE_POLY16_C(   62402),  SIMDE_POLY16_C(   40206),  SIMDE_POLY16_C(    5589),  SIMDE_POLY16_C(   46365),
         SIMDE_POLY16_C(   15546),  SIMDE_POLY16_C(   56079),  SIMDE_POLY16_C(   10655),  SIMDE_POLY16_C(   28459) },
      {  SIMDE_POLY16_C(   62402),  SIMDE_POLY16_C(   44831),  SIMDE_POLY16_C(   23387),  SIMDE_POLY16_C(   26671) },
      {  SIMDE_POLY16_C(    1114),  SIMDE_POLY16_C(   46365),  SIMDE_POLY16_C(   23387),  SIMDE_POLY16_C(   26671) },
      {  SIMDE_POLY16_C(    1114),  SIMDE_POLY16_C(   44831),  SIMDE_POLY16_C(   56079),  SIMDE_POLY16_C(   26671) },
      {  SIMDE_POLY16_C(    1114),  SIMDE_POLY16_C(   44831),  SIMDE_POLY16_C(   23387),  SIMDE_POLY16_C(   28459) } },
    { {  SIMDE_POLY16_C(   15907),  SIMDE_POLY16_C(   19190),  SIMDE_POLY16_C(   53939),  SIMDE_POLY16_C(   23137) },
      {  SIMDE_POLY16_C(   31842),  SIMDE_POLY16_C(   25173),  SIMDE_POLY16_C(    4547),  SIMDE_POLY16_C(    2456),
         SIMDE_POLY16_C(   47549),  SIMDE_POLY16_C(   26853),  SIMDE_POLY16_C(   42826),  SIMDE_POLY16_C(   39063) },
      {  SIMDE_POLY16_C(   31842),  SIMDE_POLY16_C(   19190),  SIMDE_POLY16_C(   53939),  SIMDE_POLY16_C(   23137) },
      {  SIMDE_POLY16_C(   15907),  SIMDE_POLY16_C(    2456),  SIMDE_POLY16_C(   53939),  SIMDE_POLY16_C(   23137) },
      {  SIMDE_POLY16_C(   15907),  SIMDE_POLY16_C(   19190),  SIMDE_POLY16_C(   26853),  SIMDE_POLY16_C(   23137) },
      {  SIMDE_POLY16_C(   15907),  SIMDE_POLY16_C(   19190),  SIMDE_POLY16_C(   53939),  SIMDE_POLY16_C(   39063) } },
    { {  SIMDE_POLY16_C(   35181),  SIMDE_POLY16_C(   17415),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(   49844) },
      {  SIMDE_POLY16_C(   32240),  SIMDE_POLY16_C(   12816),  SIMDE_POLY16_C(   48038),  SIMDE_POLY16_C(   32248),
         SIMDE_POLY16_C(   21982),  SIMDE_POLY16_C(   58359),  SIMDE_POLY16_C(   59704),  SIMDE_POLY16_C(   41823) },
      {  SIMDE_POLY16_C(   32240),  SIMDE_POLY16_C(   17415),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(   49844) },
      {  SIMDE_POLY16_C(   35181),  SIMDE_POLY16_C(   32248),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(   49844) },
      {  SIMDE_POLY16_C(   35181),  SIMDE_POLY16_C(   17415),  SIMDE_POLY16_C(   58359),  SIMDE_POLY16_C(   49844) },
      {  SIMDE_POLY16_C(   35181),  SIMDE_POLY16_C(   17415),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(   41823) } },
    { {  SIMDE_POLY16_C(   10135),  SIMDE_POLY16_C(    9895),  SIMDE_POLY16_C(   14931),  SIMDE_POLY16_C(    6474) },
      {  SIMDE_POLY16_C(   48682),  SIMDE_POLY16_C(    7265),  SIMDE_POLY16_C(    8191),  SIMDE_POLY16_C(   33426),
         SIMDE_POLY16_C(   41840),  SIMDE_POLY16_C(   56821),  SIMDE_POLY16_C(    7954),  SIMDE_POLY16_C(   43755) },
      {  SIMDE_POLY16_C(   48682),  SIMDE_POLY16_C(    9895),  SIMDE_POLY16_C(   14931),  SIMDE_POLY16_C(    6474) },
      {  SIMDE_POLY16_C(   10135),  SIMDE_POLY16_C(   33426),  SIMDE_POLY16_C(   14931),  SIMDE_POLY16_C(    6474) },
      {  SIMDE_POLY16_C(   10135),  SIMDE_POLY16_C(    9895),  SIMDE_POLY16_C(   56821),  SIMDE_POLY16_C(    6474) },
      {  SIMDE_POLY16_C(   10135),  SIMDE_POLY16_C(    9895),  SIMDE_POLY16_C(   14931),  SIMDE_POLY16_C(   43755) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);

    simde_poly16x4_t r0_0 = simde_vcopy_laneq_p16(a, 0, b, 0);
    simde_poly16x4_t r1_3 = simde_vcopy_laneq_p16(a, 1, b, 3);
    simde_poly16x4_t r2_5 = simde_vcopy_laneq_p16(a, 2, b, 5);
    simde_poly16x4_t r3_7 = simde_vcopy_laneq_p16(a, 3, b, 7);

    simde_test_arm_neon_assert_equal_p16x4(r0_0, simde_vld1_p16(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_p16x4(r1_3, simde_vld1_p16(test_vec[i].r1_3));
    simde_test_arm_neon_assert_equal_p16x4(r2_5, simde_vld1_p16(test_vec[i].r2_5));
    simde_test_arm_neon_assert_equal_p16x4(r3_7, simde_vld1_p16(test_vec[i].r3_7));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x4_t a = simde_test_arm_neon_random_p16x4();
    simde_poly16x8_t b = simde_test_arm_neon_random_p16x8();
    simde_poly16x4_t r0_0 = simde_vcopy_laneq_p16(a, 0, b, 0);
    simde_poly16x4_t r1_3 = simde_vcopy_laneq_p16(a, 1, b, 3);
    simde_poly16x4_t r2_5 = simde_vcopy_laneq_p16(a, 2, b, 5);
    simde_poly16x4_t r3_7 = simde_vcopy_laneq_p16(a, 3, b, 7);

    simde_test_arm_neon_write_p16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r1_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r2_5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r3_7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[1];
    simde_poly64_t b[2];
    simde_poly64_t r0_0[1];
    simde_poly64_t r0_1[1];
  } test_vec[] = {
    { {  SIMDE_POLY64_C( 4774845596606571093) },
      {  SIMDE_POLY64_C( 8217638833653863154),  SIMDE_POLY64_C(17418031248681962729) },
      {  SIMDE_POLY64_C( 8217638833653863154) },
      {  SIMDE_POLY64_C(17418031248681962729) } },
    { {  SIMDE_POLY64_C(17601450605500208340) },
      {  SIMDE_POLY64_C( 2768201381815185750),  SIMDE_POLY64_C(16070785927570141580) },
      {  SIMDE_POLY64_C( 2768201381815185750) },
      {  SIMDE_POLY64_C(16070785927570141580) } },
    { {  SIMDE_POLY64_C( 5515676140731327920) },
      {  SIMDE_POLY64_C(10667193760066591791),  SIMDE_POLY64_C( 5614703629073485915) },
      {  SIMDE_POLY64_C(10667193760066591791) },
      {  SIMDE_POLY64_C( 5614703629073485915) } },
    { {  SIMDE_POLY64_C( 8834081084411742948) },
      {  SIMDE_POLY64_C( 9878499915507241938),  SIMDE_POLY64_C(12395589140738461358) },
      {  SIMDE_POLY64_C( 9878499915507241938) },
      {  SIMDE_POLY64_C(12395589140738461358) } },
    { {  SIMDE_POLY64_C(14076324571948981968) },
      {  SIMDE_POLY64_C(13707984266428261295),  SIMDE_POLY64_C(16651015344936509577) },
      {  SIMDE_POLY64_C(13707984266428261295) },
      {  SIMDE_POLY64_C(16651015344936509577) } },
    { {  SIMDE_POLY64_C( 7401032381136844628) },
      {  SIMDE_POLY64_C(13595471166024805103),  SIMDE_POLY64_C(12253610641519224975) },
      {  SIMDE_POLY64_C(13595471166024805103) },
      {  SIMDE_POLY64_C(12253610641519224975) } },
    { {  SIMDE_POLY64_C( 3043905301656645740) },
      {  SIMDE_POLY64_C(13594318462557334235),  SIMDE_POLY64_C(  878904381009645699) },
      {  SIMDE_POLY64_C(13594318462557334235) },
      {  SIMDE_POLY64_C(  878904381009645699) } },
    { {  SIMDE_POLY64_C( 7588891631142822727) },
      {  SIMDE_POLY64_C( 1673981919106237551),  SIMDE_POLY64_C(12358823236528999795) },
      {  SIMDE_POLY64_C( 1673981919106237551) },
      {  SIMDE_POLY64_C(12358823236528999795) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1_t a = simde_vld1_p64(test_vec[i].a);
    simde_poly64x2_t b = simde_vld1q_p64(test_vec[i].b);

    simde_poly64x1_t r0_0 = simde_vcopy_laneq_p64(a, 0, b, 0);
    simde_poly64x1_t r0_1 = simde_vcopy_laneq_p64(a, 0, b, 1);

    simde_test_arm_neon_assert_equal_p64x1(r0_0, simde_vld1_p64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_p64x1(r0_1, simde_vld1_p64(test_vec[i].r0_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x1_t a = simde_test_arm_neon_random_p64x1();
    simde_poly64x2_t b = simde_test_arm_neon_random_p64x2();
    simde_poly64x1_t r0_0 = simde_vcopy_laneq_p64(a, 0, b, 0);
    simde_poly64x1_t r0_1 = simde_vcopy_laneq_p64(a, 0, b, 1);

    simde_test_arm_neon_write_p64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r0_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[16];
    simde_poly8_t b[8];
    simde_poly8_t r0_7[16];
    simde_poly8_t r4_6[16];
    simde_poly8_t r8_4[16];
    simde_poly8_t r12_3[16];
    simde_poly8_t r15_1[16];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(    29),
         SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   166),
         SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   178),
         SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   187) },
      {  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(    36),
         SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   128),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   208) },
      {  SIMDE_POLY8_C(   208),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(    29),
         SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   166),
         SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   178),
         SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   187) },
      {  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(    29),
         SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   166),
         SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   178),
         SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   187) },
      {  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(    29),
         SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   166),
         SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   178),
         SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   187) },
      {  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(    29),
         SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   166),
         SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   178),
         SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   187) },
      {  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(    29),
         SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   166),
         SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   178),
         SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   103) } },
    { {  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    52),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   179),
         SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   227),
         SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(    50),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(   157),
         SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   165) },
      {  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    52),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   179),
         SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   227),
         SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    52),
         SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   179),
         SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   227),
         SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    52),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   179),
         SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   227),
         SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    52),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   179),
         SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   227),
         SIMDE_POLY8_C(   157),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    52),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   179),
         SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   227),
         SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(    50) } },
    { {  SIMDE_POLY8_C(   105),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    67),
         SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   140),  SIMDE_POLY8_C(    45),
         SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(   203),
         SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   173) },
      {  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    67),
         SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   140),  SIMDE_POLY8_C(    45),
         SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(   105),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    67),
         SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   140),  SIMDE_POLY8_C(    45),
         SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(   105),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    67),
         SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   140),  SIMDE_POLY8_C(    45),
         SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(   105),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    67),
         SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   140),  SIMDE_POLY8_C(    45),
         SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(   105),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    67),
         SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   140),  SIMDE_POLY8_C(    45),
         SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   107) } },
    { {  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   189),
         SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   117),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   254) },
      {  SIMDE_POLY8_C(    46),  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   149),
         SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(   224) },
      {  SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   189),
         SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   117),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   254) },
      {  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   189),
         SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   117),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   254) },
      {  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   189),
         SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   117),
         SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   254) },
      {  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   189),
         SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   117),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   254) },
      {  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   189),
         SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   117),
         SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   221),
         SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   151) } },
    { {  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    85),
         SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   144),
         SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(    35),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(   158) },
      {  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(    85),
         SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(    57) },
      {  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    85),
         SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   144),
         SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(    35),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(   158) },
      {  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    85),
         SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   144),
         SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(    35),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(   158) },
      {  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    85),
         SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   144),
         SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(    35),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(   158) },
      {  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    85),
         SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   144),
         SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    35),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(   158) },
      {  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    85),
         SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   144),
         SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(    35),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(   217) } },
    { {  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   160),
         SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    21),
         SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   109),
         SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(   137) },
      {  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   207),  SIMDE_POLY8_C(   250),  SIMDE_POLY8_C(   139),
         SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   230),  SIMDE_POLY8_C(   206) },
      {  SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   160),
         SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    21),
         SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   109),
         SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(   137) },
      {  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   160),
         SIMDE_POLY8_C(   230),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    21),
         SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   109),
         SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(   137) },
      {  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   160),
         SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    21),
         SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   109),
         SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(   137) },
      {  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   160),
         SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    21),
         SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   109),
         SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(   137) },
      {  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   160),
         SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    21),
         SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   109),
         SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(   207) } },
    { {  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   110),
         SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(    19),
         SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    88),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   239) },
      {  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   244),
         SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(   136) },
      {  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   110),
         SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(    19),
         SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    88),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   239) },
      {  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   110),
         SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(    19),
         SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    88),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   239) },
      {  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   110),
         SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(    19),
         SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    88),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   239) },
      {  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   110),
         SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(    19),
         SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    88),
         SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   239) },
      {  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   110),
         SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(    19),
         SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    88),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   213) } },
    { {  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   176),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    41),
         SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    68),
         SIMDE_POLY8_C(   185),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    46),
         SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   123) },
      {  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(    65),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(     1),
         SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    67),  SIMDE_POLY8_C(    18) },
      {  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   176),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    41),
         SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    68),
         SIMDE_POLY8_C(   185),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    46),
         SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   123) },
      {  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   176),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    41),
         SIMDE_POLY8_C(    67),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    68),
         SIMDE_POLY8_C(   185),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    46),
         SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   123) },
      {  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   176),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    41),
         SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    68),
         SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    46),
         SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   123) },
      {  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   176),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    41),
         SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    68),
         SIMDE_POLY8_C(   185),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    46),
         SIMDE_POLY8_C(     1),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   123) },
      {  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   176),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    41),
         SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    68),
         SIMDE_POLY8_C(   185),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    46),
         SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(    65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);

    simde_poly8x16_t r0_7 = simde_vcopyq_lane_p8(a, 0, b, 7);
    simde_poly8x16_t r4_6 = simde_vcopyq_lane_p8(a, 4, b, 6);
    simde_poly8x16_t r8_4 = simde_vcopyq_lane_p8(a, 8, b, 4);
    simde_poly8x16_t r12_3 = simde_vcopyq_lane_p8(a, 12, b, 3);
    simde_poly8x16_t r15_1 = simde_vcopyq_lane_p8(a, 15, b, 1);

    simde_test_arm_neon_assert_equal_p8x16(r0_7, simde_vld1q_p8(test_vec[i].r0_7));
    simde_test_arm_neon_assert_equal_p8x16(r4_6, simde_vld1q_p8(test_vec[i].r4_6));
    simde_test_arm_neon_assert_equal_p8x16(r8_4, simde_vld1q_p8(test_vec[i].r8_4));
    simde_test_arm_neon_assert_equal_p8x16(r12_3, simde_vld1q_p8(test_vec[i].r12_3));
    simde_test_arm_neon_assert_equal_p8x16(r15_1, simde_vld1q_p8(test_vec[i].r15_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x8_t b = simde_test_arm_neon_random_p8x8();
    simde_poly8x16_t r0_7 = simde_vcopyq_lane_p8(a, 0, b, 7);
    simde_poly8x16_t r4_6 = simde_vcopyq_lane_p8(a, 4, b, 6);
    simde_poly8x16_t r8_4 = simde_vcopyq_lane_p8(a, 8, b, 4);
    simde_poly8x16_t r12_3 = simde_vcopyq_lane_p8(a, 12, b, 3);
    simde_poly8x16_t r15_1 = simde_vcopyq_lane_p8(a, 15, b, 1);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r0_7, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r4_6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r8_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r12_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r15_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[8];
    simde_poly16_t b[4];
    simde_poly16_t r0_3[8];
    simde_poly16_t r3_2[8];
    simde_poly16_t r5_1[8];
    simde_poly16_t r7_0[8];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(   45106),  SIMDE_POLY16_C(   38241),  SIMDE_POLY16_C(    4836),  SIMDE_POLY16_C(   40111),
         SIMDE_POLY16_C(   37552),  SIMDE_POLY16_C(   53688),  SIMDE_POLY16_C(   17469),  SIMDE_POLY16_C(   24387) },
      {  SIMDE_POLY16_C(   47087),  SIMDE_POLY16_C(   53333),  SIMDE_POLY16_C(   17428),  SIMDE_POLY16_C(   45727) },
      {  SIMDE_POLY16_C(   45727),  SIMDE_POLY16_C(   38241),  SIMDE_POLY16_C(    4836),  SIMDE_POLY16_C(   40111),
         SIMDE_POLY16_C(   37552),  SIMDE_POLY16_C(   53688),  SIMDE_POLY16_C(   17469),  SIMDE_POLY16_C(   24387) },
      {  SIMDE_POLY16_C(   45106),  SIMDE_POLY16_C(   38241),  SIMDE_POLY16_C(    4836),  SIMDE_POLY16_C(   17428),
         SIMDE_POLY16_C(   37552),  SIMDE_POLY16_C(   53688),  SIMDE_POLY16_C(   17469),  SIMDE_POLY16_C(   24387) },
      {  SIMDE_POLY16_C(   45106),  SIMDE_POLY16_C(   38241),  SIMDE_POLY16_C(    4836),  SIMDE_POLY16_C(   40111),
         SIMDE_POLY16_C(   37552),  SIMDE_POLY16_C(   53333),  SIMDE_POLY16_C(   17469),  SIMDE_POLY16_C(   24387) },
      {  SIMDE_POLY16_C(   45106),  SIMDE_POLY16_C(   38241),  SIMDE_POLY16_C(    4836),  SIMDE_POLY16_C(   40111),
         SIMDE_POLY16_C(   37552),  SIMDE_POLY16_C(   53688),  SIMDE_POLY16_C(   17469),  SIMDE_POLY16_C(   47087) } },
    { {  SIMDE_POLY16_C(    5206),  SIMDE_POLY16_C(   60332),  SIMDE_POLY16_C(   40277),  SIMDE_POLY16_C(   19674),
         SIMDE_POLY16_C(    6622),  SIMDE_POLY16_C(   38757),  SIMDE_POLY16_C(   64251),  SIMDE_POLY16_C(   47386) },
      {  SIMDE_POLY16_C(    8478),  SIMDE_POLY16_C(    4749),  SIMDE_POLY16_C(   53363),  SIMDE_POLY16_C(   29869) },
      {  SIMDE_POLY16_C(   29869),  SIMDE_POLY16_C(   60332),  SIMDE_POLY16_C(   40277),  SIMDE_POLY16_C(   19674),
         SIMDE_POLY16_C(    6622),  SIMDE_POLY16_C(   38757),  SIMDE_POLY16_C(   64251),  SIMDE_POLY16_C(   47386) },
      {  SIMDE_POLY16_C(    5206),  SIMDE_POLY16_C(   60332),  SIMDE_POLY16_C(   40277),  SIMDE_POLY16_C(   53363),
         SIMDE_POLY16_C(    6622),  SIMDE_POLY16_C(   38757),  SIMDE_POLY16_C(   64251),  SIMDE_POLY16_C(   47386) },
      {  SIMDE_POLY16_C(    5206),  SIMDE_POLY16_C(   60332),  SIMDE_POLY16_C(   40277),  SIMDE_POLY16_C(   19674),
         SIMDE_POLY16_C(    6622),  SIMDE_POLY16_C(    4749),  SIMDE_POLY16_C(   64251),  SIMDE_POLY16_C(   47386) },
      {  SIMDE_POLY16_C(    5206),  SIMDE_POLY16_C(   60332),  SIMDE_POLY16_C(   40277),  SIMDE_POLY16_C(   19674),
         SIMDE_POLY16_C(    6622),  SIMDE_POLY16_C(   38757),  SIMDE_POLY16_C(   64251),  SIMDE_POLY16_C(    8478) } },
    { {  SIMDE_POLY16_C(   59206),  SIMDE_POLY16_C(   36412),  SIMDE_POLY16_C(   15257),  SIMDE_POLY16_C(   46944),
         SIMDE_POLY16_C(   46282),  SIMDE_POLY16_C(   17117),  SIMDE_POLY16_C(   45233),  SIMDE_POLY16_C(    4994) },
      {  SIMDE_POLY16_C(   46395),  SIMDE_POLY16_C(   50547),  SIMDE_POLY16_C(   19830),  SIMDE_POLY16_C(   44578) },
      {  SIMDE_POLY16_C(   44578),  SIMDE_POLY16_C(   36412),  SIMDE_POLY16_C(   15257),  SIMDE_POLY16_C(   46944),
         SIMDE_POLY16_C(   46282),  SIMDE_POLY16_C(   17117),  SIMDE_POLY16_C(   45233),  SIMDE_POLY16_C(    4994) },
      {  SIMDE_POLY16_C(   59206),  SIMDE_POLY16_C(   36412),  SIMDE_POLY16_C(   15257),  SIMDE_POLY16_C(   19830),
         SIMDE_POLY16_C(   46282),  SIMDE_POLY16_C(   17117),  SIMDE_POLY16_C(   45233),  SIMDE_POLY16_C(    4994) },
      {  SIMDE_POLY16_C(   59206),  SIMDE_POLY16_C(   36412),  SIMDE_POLY16_C(   15257),  SIMDE_POLY16_C(   46944),
         SIMDE_POLY16_C(   46282),  SIMDE_POLY16_C(   50547),  SIMDE_POLY16_C(   45233),  SIMDE_POLY16_C(    4994) },
      {  SIMDE_POLY16_C(   59206),  SIMDE_POLY16_C(   36412),  SIMDE_POLY16_C(   15257),  SIMDE_POLY16_C(   46944),
         SIMDE_POLY16_C(   46282),  SIMDE_POLY16_C(   17117),  SIMDE_POLY16_C(   45233),  SIMDE_POLY16_C(   46395) } },
    { {  SIMDE_POLY16_C(   13682),  SIMDE_POLY16_C(   54233),  SIMDE_POLY16_C(   15911),  SIMDE_POLY16_C(   26730),
         SIMDE_POLY16_C(     502),  SIMDE_POLY16_C(   64753),  SIMDE_POLY16_C(   30819),  SIMDE_POLY16_C(   45749) },
      {  SIMDE_POLY16_C(   24828),  SIMDE_POLY16_C(   29679),  SIMDE_POLY16_C(   21740),  SIMDE_POLY16_C(   34938) },
      {  SIMDE_POLY16_C(   34938),  SIMDE_POLY16_C(   54233),  SIMDE_POLY16_C(   15911),  SIMDE_POLY16_C(   26730),
         SIMDE_POLY16_C(     502),  SIMDE_POLY16_C(   64753),  SIMDE_POLY16_C(   30819),  SIMDE_POLY16_C(   45749) },
      {  SIMDE_POLY16_C(   13682),  SIMDE_POLY16_C(   54233),  SIMDE_POLY16_C(   15911),  SIMDE_POLY16_C(   21740),
         SIMDE_POLY16_C(     502),  SIMDE_POLY16_C(   64753),  SIMDE_POLY16_C(   30819),  SIMDE_POLY16_C(   45749) },
      {  SIMDE_POLY16_C(   13682),  SIMDE_POLY16_C(   54233),  SIMDE_POLY16_C(   15911),  SIMDE_POLY16_C(   26730),
         SIMDE_POLY16_C(     502),  SIMDE_POLY16_C(   29679),  SIMDE_POLY16_C(   30819),  SIMDE_POLY16_C(   45749) },
      {  SIMDE_POLY16_C(   13682),  SIMDE_POLY16_C(   54233),  SIMDE_POLY16_C(   15911),  SIMDE_POLY16_C(   26730),
         SIMDE_POLY16_C(     502),  SIMDE_POLY16_C(   64753),  SIMDE_POLY16_C(   30819),  SIMDE_POLY16_C(   24828) } },
    { {  SIMDE_POLY16_C(   12489),  SIMDE_POLY16_C(    1881),  SIMDE_POLY16_C(   42262),  SIMDE_POLY16_C(   53977),
         SIMDE_POLY16_C(   19091),  SIMDE_POLY16_C(   33756),  SIMDE_POLY16_C(   22902),  SIMDE_POLY16_C(   39968) },
      {  SIMDE_POLY16_C(     373),  SIMDE_POLY16_C(   54089),  SIMDE_POLY16_C(   12533),  SIMDE_POLY16_C(   41276) },
      {  SIMDE_POLY16_C(   41276),  SIMDE_POLY16_C(    1881),  SIMDE_POLY16_C(   42262),  SIMDE_POLY16_C(   53977),
         SIMDE_POLY16_C(   19091),  SIMDE_POLY16_C(   33756),  SIMDE_POLY16_C(   22902),  SIMDE_POLY16_C(   39968) },
      {  SIMDE_POLY16_C(   12489),  SIMDE_POLY16_C(    1881),  SIMDE_POLY16_C(   42262),  SIMDE_POLY16_C(   12533),
         SIMDE_POLY16_C(   19091),  SIMDE_POLY16_C(   33756),  SIMDE_POLY16_C(   22902),  SIMDE_POLY16_C(   39968) },
      {  SIMDE_POLY16_C(   12489),  SIMDE_POLY16_C(    1881),  SIMDE_POLY16_C(   42262),  SIMDE_POLY16_C(   53977),
         SIMDE_POLY16_C(   19091),  SIMDE_POLY16_C(   54089),  SIMDE_POLY16_C(   22902),  SIMDE_POLY16_C(   39968) },
      {  SIMDE_POLY16_C(   12489),  SIMDE_POLY16_C(    1881),  SIMDE_POLY16_C(   42262),  SIMDE_POLY16_C(   53977),
         SIMDE_POLY16_C(   19091),  SIMDE_POLY16_C(   33756),  SIMDE_POLY16_C(   22902),  SIMDE_POLY16_C(     373) } },
    { {  SIMDE_POLY16_C(    8219),  SIMDE_POLY16_C(   44521),  SIMDE_POLY16_C(   54001),  SIMDE_POLY16_C(    7888),
         SIMDE_POLY16_C(   57460),  SIMDE_POLY16_C(   14245),  SIMDE_POLY16_C(   48545),  SIMDE_POLY16_C(   24933) },
      {  SIMDE_POLY16_C(   62999),  SIMDE_POLY16_C(   52731),  SIMDE_POLY16_C(   45056),  SIMDE_POLY16_C(   13736) },
      {  SIMDE_POLY16_C(   13736),  SIMDE_POLY16_C(   44521),  SIMDE_POLY16_C(   54001),  SIMDE_POLY16_C(    7888),
         SIMDE_POLY16_C(   57460),  SIMDE_POLY16_C(   14245),  SIMDE_POLY16_C(   48545),  SIMDE_POLY16_C(   24933) },
      {  SIMDE_POLY16_C(    8219),  SIMDE_POLY16_C(   44521),  SIMDE_POLY16_C(   54001),  SIMDE_POLY16_C(   45056),
         SIMDE_POLY16_C(   57460),  SIMDE_POLY16_C(   14245),  SIMDE_POLY16_C(   48545),  SIMDE_POLY16_C(   24933) },
      {  SIMDE_POLY16_C(    8219),  SIMDE_POLY16_C(   44521),  SIMDE_POLY16_C(   54001),  SIMDE_POLY16_C(    7888),
         SIMDE_POLY16_C(   57460),  SIMDE_POLY16_C(   52731),  SIMDE_POLY16_C(   48545),  SIMDE_POLY16_C(   24933) },
      {  SIMDE_POLY16_C(    8219),  SIMDE_POLY16_C(   44521),  SIMDE_POLY16_C(   54001),  SIMDE_POLY16_C(    7888),
         SIMDE_POLY16_C(   57460),  SIMDE_POLY16_C(   14245),  SIMDE_POLY16_C(   48545),  SIMDE_POLY16_C(   62999) } },
    { {  SIMDE_POLY16_C(   17803),  SIMDE_POLY16_C(   23302),  SIMDE_POLY16_C(   51288),  SIMDE_POLY16_C(    6738),
         SIMDE_POLY16_C(   26381),  SIMDE_POLY16_C(   44920),  SIMDE_POLY16_C(     438),  SIMDE_POLY16_C(   12440) },
      {  SIMDE_POLY16_C(   64520),  SIMDE_POLY16_C(    6608),  SIMDE_POLY16_C(   27242),  SIMDE_POLY16_C(    9986) },
      {  SIMDE_POLY16_C(    9986),  SIMDE_POLY16_C(   23302),  SIMDE_POLY16_C(   51288),  SIMDE_POLY16_C(    6738),
         SIMDE_POLY16_C(   26381),  SIMDE_POLY16_C(   44920),  SIMDE_POLY16_C(     438),  SIMDE_POLY16_C(   12440) },
      {  SIMDE_POLY16_C(   17803),  SIMDE_POLY16_C(   23302),  SIMDE_POLY16_C(   51288),  SIMDE_POLY16_C(   27242),
         SIMDE_POLY16_C(   26381),  SIMDE_POLY16_C(   44920),  SIMDE_POLY16_C(     438),  SIMDE_POLY16_C(   12440) },
      {  SIMDE_POLY16_C(   17803),  SIMDE_POLY16_C(   23302),  SIMDE_POLY16_C(   51288),  SIMDE_POLY16_C(    6738),
         SIMDE_POLY16_C(   26381),  SIMDE_POLY16_C(    6608),  SIMDE_POLY16_C(     438),  SIMDE_POLY16_C(   12440) },
      {  SIMDE_POLY16_C(   17803),  SIMDE_POLY16_C(   23302),  SIMDE_POLY16_C(   51288),  SIMDE_POLY16_C(    6738),
         SIMDE_POLY16_C(   26381),  SIMDE_POLY16_C(   44920),  SIMDE_POLY16_C(     438),  SIMDE_POLY16_C(   64520) } },
    { {  SIMDE_POLY16_C(   40969),  SIMDE_POLY16_C(   63552),  SIMDE_POLY16_C(   36257),  SIMDE_POLY16_C(    5157),
         SIMDE_POLY16_C(   49006),  SIMDE_POLY16_C(    3329),  SIMDE_POLY16_C(   25930),  SIMDE_POLY16_C(   37093) },
      {  SIMDE_POLY16_C(   24602),  SIMDE_POLY16_C(   27093),  SIMDE_POLY16_C(   33126),  SIMDE_POLY16_C(   48029) },
      {  SIMDE_POLY16_C(   48029),  SIMDE_POLY16_C(   63552),  SIMDE_POLY16_C(   36257),  SIMDE_POLY16_C(    5157),
         SIMDE_POLY16_C(   49006),  SIMDE_POLY16_C(    3329),  SIMDE_POLY16_C(   25930),  SIMDE_POLY16_C(   37093) },
      {  SIMDE_POLY16_C(   40969),  SIMDE_POLY16_C(   63552),  SIMDE_POLY16_C(   36257),  SIMDE_POLY16_C(   33126),
         SIMDE_POLY16_C(   49006),  SIMDE_POLY16_C(    3329),  SIMDE_POLY16_C(   25930),  SIMDE_POLY16_C(   37093) },
      {  SIMDE_POLY16_C(   40969),  SIMDE_POLY16_C(   63552),  SIMDE_POLY16_C(   36257),  SIMDE_POLY16_C(    5157),
         SIMDE_POLY16_C(   49006),  SIMDE_POLY16_C(   27093),  SIMDE_POLY16_C(   25930),  SIMDE_POLY16_C(   37093) },
      {  SIMDE_POLY16_C(   40969),  SIMDE_POLY16_C(   63552),  SIMDE_POLY16_C(   36257),  SIMDE_POLY16_C(    5157),
         SIMDE_POLY16_C(   49006),  SIMDE_POLY16_C(    3329),  SIMDE_POLY16_C(   25930),  SIMDE_POLY16_C(   24602) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);

    simde_poly16x8_t r0_3 = simde_vcopyq_lane_p16(a, 0, b, 3);
    simde_poly16x8_t r3_2 = simde_vcopyq_lane_p16(a, 3, b, 2);
    simde_poly16x8_t r5_1 = simde_vcopyq_lane_p16(a, 5, b, 1);
    simde_poly16x8_t r7_0 = simde_vcopyq_lane_p16(a, 7, b, 0);

    simde_test_arm_neon_assert_equal_p16x8(r0_3, simde_vld1q_p16(test_vec[i].r0_3));
    simde_test_arm_neon_assert_equal_p16x8(r3_2, simde_vld1q_p16(test_vec[i].r3_2));
    simde_test_arm_neon_assert_equal_p16x8(r5_1, simde_vld1q_p16(test_vec[i].r5_1));
    simde_test_arm_neon_assert_equal_p16x8(r7_0, simde_vld1q_p16(test_vec[i].r7_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x4_t b = simde_test_arm_neon_random_p16x4();
    simde_poly16x8_t r0_3 = simde_vcopyq_lane_p16(a, 0, b, 3);
    simde_poly16x8_t r3_2 = simde_vcopyq_lane_p16(a, 3, b, 2);
    simde_poly16x8_t r5_1 = simde_vcopyq_lane_p16(a, 5, b, 1);
    simde_poly16x8_t r7_0 = simde_vcopyq_lane_p16(a, 7, b, 0);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r0_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r3_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r5_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r7_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[2];
    simde_poly64_t b[1];
    simde_poly64_t r0_0[2];
    simde_poly64_t r1_0[2];
  } test_vec[] = {
    { {  SIMDE_POLY64_C(13088088903368892823),  SIMDE_POLY64_C(11535793185305623270) },
      {  SIMDE_POLY64_C( 5924534224249363076) },
      {  SIMDE_POLY64_C( 5924534224249363076),  SIMDE_POLY64_C(11535793185305623270) },
      {  SIMDE_POLY64_C(13088088903368892823),  SIMDE_POLY64_C( 5924534224249363076) } },
    { {  SIMDE_POLY64_C(18271803387774738026),  SIMDE_POLY64_C(  840258608695505479) },
      {  SIMDE_POLY64_C(18149383589595975661) },
      {  SIMDE_POLY64_C(18149383589595975661),  SIMDE_POLY64_C(  840258608695505479) },
      {  SIMDE_POLY64_C(18271803387774738026),  SIMDE_POLY64_C(18149383589595975661) } },
    { {  SIMDE_POLY64_C( 1426608908501472439),  SIMDE_POLY64_C(17579859043434713714) },
      {  SIMDE_POLY64_C( 3863851528950464347) },
      {  SIMDE_POLY64_C( 3863851528950464347),  SIMDE_POLY64_C(17579859043434713714) },
      {  SIMDE_POLY64_C( 1426608908501472439),  SIMDE_POLY64_C( 3863851528950464347) } },
    { {  SIMDE_POLY64_C( 2887535003750440669),  SIMDE_POLY64_C( 9706127502422434237) },
      {  SIMDE_POLY64_C(  585016102035113102) },
      {  SIMDE_POLY64_C(  585016102035113102),  SIMDE_POLY64_C( 9706127502422434237) },
      {  SIMDE_POLY64_C( 2887535003750440669),  SIMDE_POLY64_C(  585016102035113102) } },
    { {  SIMDE_POLY64_C(11767062204421784175),  SIMDE_POLY64_C( 6611989932014277560) },
      {  SIMDE_POLY64_C( 1728274990776995191) },
      {  SIMDE_POLY64_C( 1728274990776995191),  SIMDE_POLY64_C( 6611989932014277560) },
      {  SIMDE_POLY64_C(11767062204421784175),  SIMDE_POLY64_C( 1728274990776995191) } },
    { {  SIMDE_POLY64_C(11529019270513437728),  SIMDE_POLY64_C( 7695879568420221205) },
      {  SIMDE_POLY64_C(15611393117687386357) },
      {  SIMDE_POLY64_C(15611393117687386357),  SIMDE_POLY64_C( 7695879568420221205) },
      {  SIMDE_POLY64_C(11529019270513437728),  SIMDE_POLY64_C(15611393117687386357) } },
    { {  SIMDE_POLY64_C(11313965299073639025),  SIMDE_POLY64_C( 5304856213118510799) },
      {  SIMDE_POLY64_C( 4627035757479335269) },
      {  SIMDE_POLY64_C( 4627035757479335269),  SIMDE_POLY64_C( 5304856213118510799) },
      {  SIMDE_POLY64_C(11313965299073639025),  SIMDE_POLY64_C( 4627035757479335269) } },
    { {  SIMDE_POLY64_C(10403068332418732573),  SIMDE_POLY64_C(18189821306737318447) },
      {  SIMDE_POLY64_C(15540049615037950397) },
      {  SIMDE_POLY64_C(15540049615037950397),  SIMDE_POLY64_C(18189821306737318447) },
      {  SIMDE_POLY64_C(10403068332418732573),  SIMDE_POLY64_C(15540049615037950397) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t a = simde_vld1q_p64(test_vec[i].a);
    simde_poly64x1_t b = simde_vld1_p64(test_vec[i].b);

    simde_poly64x2_t r0_0 = simde_vcopyq_lane_p64(a, 0, b, 0);
    simde_poly64x2_t r1_0 = simde_vcopyq_lane_p64(a, 1, b, 0);

    simde_test_arm_neon_assert_equal_p64x2(r0_0, simde_vld1q_p64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_p64x2(r1_0, simde_vld1q_p64(test_vec[i].r1_0));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x2_t a = simde_test_arm_neon_random_p64x2();
    simde_poly64x1_t b = simde_test_arm_neon_random_p64x1();
    simde_poly64x2_t r0_0 = simde_vcopyq_lane_p64(a, 0, b, 0);
    simde_poly64x2_t r1_0 = simde_vcopyq_lane_p64(a, 1, b, 0);

    simde_test_arm_neon_write_p64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r1_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[16];
    simde_poly8_t b[16];
    simde_poly8_t r0_15[16];
    simde_poly8_t r3_12[16];
    simde_poly8_t r7_8[16];
    simde_poly8_t r11_4[16];
    simde_poly8_t r15_1[16];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(   17),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  150),
         SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(   93),
         SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  228) },
      {  SIMDE_POLY8_C(  163),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  104),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(   51),  SIMDE_POLY8_C(  215),  SIMDE_POLY8_C(  174),
         SIMDE_POLY8_C(   37),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(   16),  SIMDE_POLY8_C(  157),
         SIMDE_POLY8_C(   67),  SIMDE_POLY8_C(  118),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(   84) },
      {  SIMDE_POLY8_C(   84),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(   17),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  150),
         SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(   93),
         SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  228) },
      {  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(   67),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  150),
         SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(   93),
         SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  228) },
      {  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(   17),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(   37),
         SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(   93),
         SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  228) },
      {  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(   17),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  150),
         SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(  232),
         SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  228) },
      {  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(   17),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  185),  SIMDE_POLY8_C(  150),
         SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(   93),
         SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  179) } },
    { {  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  122),
         SIMDE_POLY8_C(  136),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  147),
         SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  241) },
      {  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(   20),
         SIMDE_POLY8_C(  151),  SIMDE_POLY8_C(  249),  SIMDE_POLY8_C(  195),  SIMDE_POLY8_C(  179),
         SIMDE_POLY8_C(   11),  SIMDE_POLY8_C(   61),  SIMDE_POLY8_C(   82),  SIMDE_POLY8_C(  120),
         SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  192),  SIMDE_POLY8_C(   93),  SIMDE_POLY8_C(  178) },
      {  SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  122),
         SIMDE_POLY8_C(  136),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  147),
         SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  241) },
      {  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(   20),
         SIMDE_POLY8_C(  136),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  147),
         SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  241) },
      {  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  122),
         SIMDE_POLY8_C(  136),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(   11),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  147),
         SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  241) },
      {  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  122),
         SIMDE_POLY8_C(  136),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  151),
         SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  241) },
      {  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  122),
         SIMDE_POLY8_C(  136),  SIMDE_POLY8_C(   32),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  147),
         SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(  173) } },
    { {  SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(   22),
         SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(   19),  SIMDE_POLY8_C(  207),
         SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  139),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  175) },
      {  SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(  158),  SIMDE_POLY8_C(  122),
         SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   90),  SIMDE_POLY8_C(  131),  SIMDE_POLY8_C(  127),
         SIMDE_POLY8_C(   57),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  133),
         SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(   80) },
      {  SIMDE_POLY8_C(   80),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(   22),
         SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(   19),  SIMDE_POLY8_C(  207),
         SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  139),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  175) },
      {  SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(   19),  SIMDE_POLY8_C(  207),
         SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  139),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  175) },
      {  SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(   22),
         SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(   19),  SIMDE_POLY8_C(   57),
         SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  139),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  175) },
      {  SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(   22),
         SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(   19),  SIMDE_POLY8_C(  207),
         SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  139),  SIMDE_POLY8_C(   43),
         SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  175) },
      {  SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(   22),
         SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(   19),  SIMDE_POLY8_C(  207),
         SIMDE_POLY8_C(  243),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  139),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(   39) } },
    { {  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  105),
         SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   53),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  235),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  244),  SIMDE_POLY8_C(    1) },
      {  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(   16),  SIMDE_POLY8_C(  118),  SIMDE_POLY8_C(  213),
         SIMDE_POLY8_C(   68),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(   78),  SIMDE_POLY8_C(   94),
         SIMDE_POLY8_C(   96),  SIMDE_POLY8_C(   68),  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(  218),
         SIMDE_POLY8_C(  191),  SIMDE_POLY8_C(  115),  SIMDE_POLY8_C(  146),  SIMDE_POLY8_C(  235) },
      {  SIMDE_POLY8_C(  235),  SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  105),
         SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   53),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  235),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  244),  SIMDE_POLY8_C(    1) },
      {  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  191),
         SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   53),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  235),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  244),  SIMDE_POLY8_C(    1) },
      {  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  105),
         SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   96),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  235),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  244),  SIMDE_POLY8_C(    1) },
      {  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  105),
         SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   53),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(   68),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  244),  SIMDE_POLY8_C(    1) },
      {  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(    5),  SIMDE_POLY8_C(  105),
         SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(   53),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(   15),  SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  235),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  244),  SIMDE_POLY8_C(   16) } },
    { {  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   45),  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(   76),
         SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  127),  SIMDE_POLY8_C(  154),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(   70) },
      {  SIMDE_POLY8_C(  249),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(   59),
         SIMDE_POLY8_C(    2),  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(   73),  SIMDE_POLY8_C(   97),
         SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(   76),  SIMDE_POLY8_C(   96),
         SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(  202) },
      {  SIMDE_POLY8_C(  202),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   45),  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(   76),
         SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  127),  SIMDE_POLY8_C(  154),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(   70) },
      {  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(  205),
         SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   45),  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(   76),
         SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  127),  SIMDE_POLY8_C(  154),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(   70) },
      {  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   45),  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  161),
         SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  127),  SIMDE_POLY8_C(  154),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(   70) },
      {  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   45),  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(   76),
         SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  127),  SIMDE_POLY8_C(  154),  SIMDE_POLY8_C(    2),
         SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(   70) },
      {  SIMDE_POLY8_C(  110),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(   45),  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(   76),
         SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  127),  SIMDE_POLY8_C(  154),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(  143) } },
    { {  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(    0),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   91) },
      {  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(   25),  SIMDE_POLY8_C(  230),  SIMDE_POLY8_C(  142),
         SIMDE_POLY8_C(   76),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(   57),  SIMDE_POLY8_C(    7),
         SIMDE_POLY8_C(  239),  SIMDE_POLY8_C(  176),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(   43),
         SIMDE_POLY8_C(   54),  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(   24) },
      {  SIMDE_POLY8_C(   24),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(    0),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   91) },
      {  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   54),
         SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(    0),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   91) },
      {  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(  239),
         SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(    0),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   91) },
      {  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   76),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   91) },
      {  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(    0),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   25) } },
    { {  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   18),  SIMDE_POLY8_C(  142),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  132),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(   46),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(  144) },
      {  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   82),  SIMDE_POLY8_C(  123),  SIMDE_POLY8_C(  131),
         SIMDE_POLY8_C(  204),  SIMDE_POLY8_C(  199),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  126),
         SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  111),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   50),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(   65),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  254) },
      {  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   18),  SIMDE_POLY8_C(  142),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  132),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(   46),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(  144) },
      {  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   18),  SIMDE_POLY8_C(  252),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  132),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(   46),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(  144) },
      {  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   18),  SIMDE_POLY8_C(  142),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  132),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   30),
         SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(   46),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(  144) },
      {  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   18),  SIMDE_POLY8_C(  142),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  132),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(  204),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(  144) },
      {  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(    0),  SIMDE_POLY8_C(   18),  SIMDE_POLY8_C(  142),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  132),  SIMDE_POLY8_C(    1),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(   46),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(   59),  SIMDE_POLY8_C(   82) } },
    { {  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  183),
         SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(   76),  SIMDE_POLY8_C(   13),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  167) },
      {  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(  212),  SIMDE_POLY8_C(  225),
         SIMDE_POLY8_C(  136),  SIMDE_POLY8_C(  233),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(   29),
         SIMDE_POLY8_C(  196),  SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  157),  SIMDE_POLY8_C(  121),
         SIMDE_POLY8_C(   58),  SIMDE_POLY8_C(   57),  SIMDE_POLY8_C(  166),  SIMDE_POLY8_C(   79) },
      {  SIMDE_POLY8_C(   79),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  183),
         SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(   76),  SIMDE_POLY8_C(   13),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  167) },
      {  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(   58),
         SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(   76),  SIMDE_POLY8_C(   13),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  167) },
      {  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  183),
         SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(   76),  SIMDE_POLY8_C(   13),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  167) },
      {  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  183),
         SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(   76),  SIMDE_POLY8_C(  136),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  167) },
      {  SIMDE_POLY8_C(  214),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  183),
         SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(   97),  SIMDE_POLY8_C(   76),  SIMDE_POLY8_C(   13),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  212) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);

    simde_poly8x16_t r0_15 = simde_vcopyq_laneq_p8(a, 0, b, 15);
    simde_poly8x16_t r3_12 = simde_vcopyq_laneq_p8(a, 3, b, 12);
    simde_poly8x16_t r7_8 = simde_vcopyq_laneq_p8(a, 7, b, 8);
    simde_poly8x16_t r11_4 = simde_vcopyq_laneq_p8(a, 11, b, 4);
    simde_poly8x16_t r15_1 = simde_vcopyq_laneq_p8(a, 15, b, 1);

    simde_test_arm_neon_assert_equal_p8x16(r0_15, simde_vld1q_p8(test_vec[i].r0_15));
    simde_test_arm_neon_assert_equal_p8x16(r3_12, simde_vld1q_p8(test_vec[i].r3_12));
    simde_test_arm_neon_assert_equal_p8x16(r7_8, simde_vld1q_p8(test_vec[i].r7_8));
    simde_test_arm_neon_assert_equal_p8x16(r11_4, simde_vld1q_p8(test_vec[i].r11_4));
    simde_test_arm_neon_assert_equal_p8x16(r15_1, simde_vld1q_p8(test_vec[i].r15_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t b = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t r0_15 = simde_vcopyq_laneq_p8(a, 0, b, 15);
    simde_poly8x16_t r3_12 = simde_vcopyq_laneq_p8(a, 3, b, 12);
    simde_poly8x16_t r7_8 = simde_vcopyq_laneq_p8(a, 7, b, 8);
    simde_poly8x16_t r11_4 = simde_vcopyq_laneq_p8(a, 11, b, 4);
    simde_poly8x16_t r15_1 = simde_vcopyq_laneq_p8(a, 15, b, 1);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r0_15, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r3_12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r7_8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r11_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r15_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[8];
    simde_poly16_t b[8];
    simde_poly16_t r0_7[8];
    simde_poly16_t r1_6[8];
    simde_poly16_t r3_4[8];
    simde_poly16_t r5_3[8];
    simde_poly16_t r7_1[8];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(   25081),  SIMDE_POLY16_C(   12133),  SIMDE_POLY16_C(   16658),  SIMDE_POLY16_C(   10269),
         SIMDE_POLY16_C(   62695),  SIMDE_POLY16_C(   42052),  SIMDE_POLY16_C(   28583),  SIMDE_POLY16_C(   55868) },
      {  SIMDE_POLY16_C(   64179),  SIMDE_POLY16_C(    3756),  SIMDE_POLY16_C(   15151),  SIMDE_POLY16_C(   33917),
         SIMDE_POLY16_C(   33797),  SIMDE_POLY16_C(   56243),  SIMDE_POLY16_C(   48168),  SIMDE_POLY16_C(   62591) },
      {  SIMDE_POLY16_C(   62591),  SIMDE_POLY16_C(   12133),  SIMDE_POLY16_C(   16658),  SIMDE_POLY16_C(   10269),
         SIMDE_POLY16_C(   62695),  SIMDE_POLY16_C(   42052),  SIMDE_POLY16_C(   28583),  SIMDE_POLY16_C(   55868) },
      {  SIMDE_POLY16_C(   25081),  SIMDE_POLY16_C(   48168),  SIMDE_POLY16_C(   16658),  SIMDE_POLY16_C(   10269),
         SIMDE_POLY16_C(   62695),  SIMDE_POLY16_C(   42052),  SIMDE_POLY16_C(   28583),  SIMDE_POLY16_C(   55868) },
      {  SIMDE_POLY16_C(   25081),  SIMDE_POLY16_C(   12133),  SIMDE_POLY16_C(   16658),  SIMDE_POLY16_C(   33797),
         SIMDE_POLY16_C(   62695),  SIMDE_POLY16_C(   42052),  SIMDE_POLY16_C(   28583),  SIMDE_POLY16_C(   55868) },
      {  SIMDE_POLY16_C(   25081),  SIMDE_POLY16_C(   12133),  SIMDE_POLY16_C(   16658),  SIMDE_POLY16_C(   10269),
         SIMDE_POLY16_C(   62695),  SIMDE_POLY16_C(   33917),  SIMDE_POLY16_C(   28583),  SIMDE_POLY16_C(   55868) },
      {  SIMDE_POLY16_C(   25081),  SIMDE_POLY16_C(   12133),  SIMDE_POLY16_C(   16658),  SIMDE_POLY16_C(   10269),
         SIMDE_POLY16_C(   62695),  SIMDE_POLY16_C(   42052),  SIMDE_POLY16_C(   28583),  SIMDE_POLY16_C(    3756) } },
    { {  SIMDE_POLY16_C(   42773),  SIMDE_POLY16_C(   60819),  SIMDE_POLY16_C(    5780),  SIMDE_POLY16_C(   38892),
         SIMDE_POLY16_C(   50295),  SIMDE_POLY16_C(   55830),  SIMDE_POLY16_C(   29603),  SIMDE_POLY16_C(    6234) },
      {  SIMDE_POLY16_C(   14631),  SIMDE_POLY16_C(   14975),  SIMDE_POLY16_C(   18813),  SIMDE_POLY16_C(   48357),
         SIMDE_POLY16_C(   43565),  SIMDE_POLY16_C(   52059),  SIMDE_POLY16_C(   49414),  SIMDE_POLY16_C(   62266) },
      {  SIMDE_POLY16_C(   62266),  SIMDE_POLY16_C(   60819),  SIMDE_POLY16_C(    5780),  SIMDE_POLY16_C(   38892),
         SIMDE_POLY16_C(   50295),  SIMDE_POLY16_C(   55830),  SIMDE_POLY16_C(   29603),  SIMDE_POLY16_C(    6234) },
      {  SIMDE_POLY16_C(   42773),  SIMDE_POLY16_C(   49414),  SIMDE_POLY16_C(    5780),  SIMDE_POLY16_C(   38892),
         SIMDE_POLY16_C(   50295),  SIMDE_POLY16_C(   55830),  SIMDE_POLY16_C(   29603),  SIMDE_POLY16_C(    6234) },
      {  SIMDE_POLY16_C(   42773),  SIMDE_POLY16_C(   60819),  SIMDE_POLY16_C(    5780),  SIMDE_POLY16_C(   43565),
         SIMDE_POLY16_C(   50295),  SIMDE_POLY16_C(   55830),  SIMDE_POLY16_C(   29603),  SIMDE_POLY16_C(    6234) },
      {  SIMDE_POLY16_C(   42773),  SIMDE_POLY16_C(   60819),  SIMDE_POLY16_C(    5780),  SIMDE_POLY16_C(   38892),
         SIMDE_POLY16_C(   50295),  SIMDE_POLY16_C(   48357),  SIMDE_POLY16_C(   29603),  SIMDE_POLY16_C(    6234) },
      {  SIMDE_POLY16_C(   42773),  SIMDE_POLY16_C(   60819),  SIMDE_POLY16_C(    5780),  SIMDE_POLY16_C(   38892),
         SIMDE_POLY16_C(   50295),  SIMDE_POLY16_C(   55830),  SIMDE_POLY16_C(   29603),  SIMDE_POLY16_C(   14975) } },
    { {  SIMDE_POLY16_C(   59618),  SIMDE_POLY16_C(   16122),  SIMDE_POLY16_C(   25506),  SIMDE_POLY16_C(   64566),
         SIMDE_POLY16_C(   25795),  SIMDE_POLY16_C(   55880),  SIMDE_POLY16_C(   14803),  SIMDE_POLY16_C(   20543) },
      {  SIMDE_POLY16_C(   40023),  SIMDE_POLY16_C(   25126),  SIMDE_POLY16_C(   26717),  SIMDE_POLY16_C(   35096),
         SIMDE_POLY16_C(   32251),  SIMDE_POLY16_C(   38772),  SIMDE_POLY16_C(    8275),  SIMDE_POLY16_C(   33753) },
      {  SIMDE_POLY16_C(   33753),  SIMDE_POLY16_C(   16122),  SIMDE_POLY16_C(   25506),  SIMDE_POLY16_C(   64566),
         SIMDE_POLY16_C(   25795),  SIMDE_POLY16_C(   55880),  SIMDE_POLY16_C(   14803),  SIMDE_POLY16_C(   20543) },
      {  SIMDE_POLY16_C(   59618),  SIMDE_POLY16_C(    8275),  SIMDE_POLY16_C(   25506),  SIMDE_POLY16_C(   64566),
         SIMDE_POLY16_C(   25795),  SIMDE_POLY16_C(   55880),  SIMDE_POLY16_C(   14803),  SIMDE_POLY16_C(   20543) },
      {  SIMDE_POLY16_C(   59618),  SIMDE_POLY16_C(   16122),  SIMDE_POLY16_C(   25506),  SIMDE_POLY16_C(   32251),
         SIMDE_POLY16_C(   25795),  SIMDE_POLY16_C(   55880),  SIMDE_POLY16_C(   14803),  SIMDE_POLY16_C(   20543) },
      {  SIMDE_POLY16_C(   59618),  SIMDE_POLY16_C(   16122),  SIMDE_POLY16_C(   25506),  SIMDE_POLY16_C(   64566),
         SIMDE_POLY16_C(   25795),  SIMDE_POLY16_C(   35096),  SIMDE_POLY16_C(   14803),  SIMDE_POLY16_C(   20543) },
      {  SIMDE_POLY16_C(   59618),  SIMDE_POLY16_C(   16122),  SIMDE_POLY16_C(   25506),  SIMDE_POLY16_C(   64566),
         SIMDE_POLY16_C(   25795),  SIMDE_POLY16_C(   55880),  SIMDE_POLY16_C(   14803),  SIMDE_POLY16_C(   25126) } },
    { {  SIMDE_POLY16_C(   43675),  SIMDE_POLY16_C(   35166),  SIMDE_POLY16_C(   34629),  SIMDE_POLY16_C(   36341),
         SIMDE_POLY16_C(   64989),  SIMDE_POLY16_C(    2813),  SIMDE_POLY16_C(   39062),  SIMDE_POLY16_C(   26525) },
      {  SIMDE_POLY16_C(   57069),  SIMDE_POLY16_C(   55607),  SIMDE_POLY16_C(   20903),  SIMDE_POLY16_C(   57247),
         SIMDE_POLY16_C(   36244),  SIMDE_POLY16_C(   62344),  SIMDE_POLY16_C(   41912),  SIMDE_POLY16_C(   44736) },
      {  SIMDE_POLY16_C(   44736),  SIMDE_POLY16_C(   35166),  SIMDE_POLY16_C(   34629),  SIMDE_POLY16_C(   36341),
         SIMDE_POLY16_C(   64989),  SIMDE_POLY16_C(    2813),  SIMDE_POLY16_C(   39062),  SIMDE_POLY16_C(   26525) },
      {  SIMDE_POLY16_C(   43675),  SIMDE_POLY16_C(   41912),  SIMDE_POLY16_C(   34629),  SIMDE_POLY16_C(   36341),
         SIMDE_POLY16_C(   64989),  SIMDE_POLY16_C(    2813),  SIMDE_POLY16_C(   39062),  SIMDE_POLY16_C(   26525) },
      {  SIMDE_POLY16_C(   43675),  SIMDE_POLY16_C(   35166),  SIMDE_POLY16_C(   34629),  SIMDE_POLY16_C(   36244),
         SIMDE_POLY16_C(   64989),  SIMDE_POLY16_C(    2813),  SIMDE_POLY16_C(   39062),  SIMDE_POLY16_C(   26525) },
      {  SIMDE_POLY16_C(   43675),  SIMDE_POLY16_C(   35166),  SIMDE_POLY16_C(   34629),  SIMDE_POLY16_C(   36341),
         SIMDE_POLY16_C(   64989),  SIMDE_POLY16_C(   57247),  SIMDE_POLY16_C(   39062),  SIMDE_POLY16_C(   26525) },
      {  SIMDE_POLY16_C(   43675),  SIMDE_POLY16_C(   35166),  SIMDE_POLY16_C(   34629),  SIMDE_POLY16_C(   36341),
         SIMDE_POLY16_C(   64989),  SIMDE_POLY16_C(    2813),  SIMDE_POLY16_C(   39062),  SIMDE_POLY16_C(   55607) } },
    { {  SIMDE_POLY16_C(   63367),  SIMDE_POLY16_C(   50618),  SIMDE_POLY16_C(   52629),  SIMDE_POLY16_C(   26557),
         SIMDE_POLY16_C(   49457),  SIMDE_POLY16_C(   55560),  SIMDE_POLY16_C(   59740),  SIMDE_POLY16_C(   54035) },
      {  SIMDE_POLY16_C(   35397),  SIMDE_POLY16_C(   27456),  SIMDE_POLY16_C(   19596),  SIMDE_POLY16_C(   23074),
         SIMDE_POLY16_C(   44230),  SIMDE_POLY16_C(   28458),  SIMDE_POLY16_C(   34027),  SIMDE_POLY16_C(   31882) },
      {  SIMDE_POLY16_C(   31882),  SIMDE_POLY16_C(   50618),  SIMDE_POLY16_C(   52629),  SIMDE_POLY16_C(   26557),
         SIMDE_POLY16_C(   49457),  SIMDE_POLY16_C(   55560),  SIMDE_POLY16_C(   59740),  SIMDE_POLY16_C(   54035) },
      {  SIMDE_POLY16_C(   63367),  SIMDE_POLY16_C(   34027),  SIMDE_POLY16_C(   52629),  SIMDE_POLY16_C(   26557),
         SIMDE_POLY16_C(   49457),  SIMDE_POLY16_C(   55560),  SIMDE_POLY16_C(   59740),  SIMDE_POLY16_C(   54035) },
      {  SIMDE_POLY16_C(   63367),  SIMDE_POLY16_C(   50618),  SIMDE_POLY16_C(   52629),  SIMDE_POLY16_C(   44230),
         SIMDE_POLY16_C(   49457),  SIMDE_POLY16_C(   55560),  SIMDE_POLY16_C(   59740),  SIMDE_POLY16_C(   54035) },
      {  SIMDE_POLY16_C(   63367),  SIMDE_POLY16_C(   50618),  SIMDE_POLY16_C(   52629),  SIMDE_POLY16_C(   26557),
         SIMDE_POLY16_C(   49457),  SIMDE_POLY16_C(   23074),  SIMDE_POLY16_C(   59740),  SIMDE_POLY16_C(   54035) },
      {  SIMDE_POLY16_C(   63367),  SIMDE_POLY16_C(   50618),  SIMDE_POLY16_C(   52629),  SIMDE_POLY16_C(   26557),
         SIMDE_POLY16_C(   49457),  SIMDE_POLY16_C(   55560),  SIMDE_POLY16_C(   59740),  SIMDE_POLY16_C(   27456) } },
    { {  SIMDE_POLY16_C(   23413),  SIMDE_POLY16_C(   40483),  SIMDE_POLY16_C(      63),  SIMDE_POLY16_C(   52152),
         SIMDE_POLY16_C(   38959),  SIMDE_POLY16_C(    4929),  SIMDE_POLY16_C(   21435),  SIMDE_POLY16_C(   62787) },
      {  SIMDE_POLY16_C(   49317),  SIMDE_POLY16_C(   18538),  SIMDE_POLY16_C(   17793),  SIMDE_POLY16_C(   61704),
         SIMDE_POLY16_C(   41671),  SIMDE_POLY16_C(   53824),  SIMDE_POLY16_C(   25678),  SIMDE_POLY16_C(   37125) },
      {  SIMDE_POLY16_C(   37125),  SIMDE_POLY16_C(   40483),  SIMDE_POLY16_C(      63),  SIMDE_POLY16_C(   52152),
         SIMDE_POLY16_C(   38959),  SIMDE_POLY16_C(    4929),  SIMDE_POLY16_C(   21435),  SIMDE_POLY16_C(   62787) },
      {  SIMDE_POLY16_C(   23413),  SIMDE_POLY16_C(   25678),  SIMDE_POLY16_C(      63),  SIMDE_POLY16_C(   52152),
         SIMDE_POLY16_C(   38959),  SIMDE_POLY16_C(    4929),  SIMDE_POLY16_C(   21435),  SIMDE_POLY16_C(   62787) },
      {  SIMDE_POLY16_C(   23413),  SIMDE_POLY16_C(   40483),  SIMDE_POLY16_C(      63),  SIMDE_POLY16_C(   41671),
         SIMDE_POLY16_C(   38959),  SIMDE_POLY16_C(    4929),  SIMDE_POLY16_C(   21435),  SIMDE_POLY16_C(   62787) },
      {  SIMDE_POLY16_C(   23413),  SIMDE_POLY16_C(   40483),  SIMDE_POLY16_C(      63),  SIMDE_POLY16_C(   52152),
         SIMDE_POLY16_C(   38959),  SIMDE_POLY16_C(   61704),  SIMDE_POLY16_C(   21435),  SIMDE_POLY16_C(   62787) },
      {  SIMDE_POLY16_C(   23413),  SIMDE_POLY16_C(   40483),  SIMDE_POLY16_C(      63),  SIMDE_POLY16_C(   52152),
         SIMDE_POLY16_C(   38959),  SIMDE_POLY16_C(    4929),  SIMDE_POLY16_C(   21435),  SIMDE_POLY16_C(   18538) } },
    { {  SIMDE_POLY16_C(   41696),  SIMDE_POLY16_C(    7636),  SIMDE_POLY16_C(   15486),  SIMDE_POLY16_C(     842),
         SIMDE_POLY16_C(   14005),  SIMDE_POLY16_C(   39402),  SIMDE_POLY16_C(   58283),  SIMDE_POLY16_C(    8456) },
      {  SIMDE_POLY16_C(   47670),  SIMDE_POLY16_C(    2324),  SIMDE_POLY16_C(   19969),  SIMDE_POLY16_C(   53005),
         SIMDE_POLY16_C(    4511),  SIMDE_POLY16_C(   36060),  SIMDE_POLY16_C(   54065),  SIMDE_POLY16_C(   35479) },
      {  SIMDE_POLY16_C(   35479),  SIMDE_POLY16_C(    7636),  SIMDE_POLY16_C(   15486),  SIMDE_POLY16_C(     842),
         SIMDE_POLY16_C(   14005),  SIMDE_POLY16_C(   39402),  SIMDE_POLY16_C(   58283),  SIMDE_POLY16_C(    8456) },
      {  SIMDE_POLY16_C(   41696),  SIMDE_POLY16_C(   54065),  SIMDE_POLY16_C(   15486),  SIMDE_POLY16_C(     842),
         SIMDE_POLY16_C(   14005),  SIMDE_POLY16_C(   39402),  SIMDE_POLY16_C(   58283),  SIMDE_POLY16_C(    8456) },
      {  SIMDE_POLY16_C(   41696),  SIMDE_POLY16_C(    7636),  SIMDE_POLY16_C(   15486),  SIMDE_POLY16_C(    4511),
         SIMDE_POLY16_C(   14005),  SIMDE_POLY16_C(   39402),  SIMDE_POLY16_C(   58283),  SIMDE_POLY16_C(    8456) },
      {  SIMDE_POLY16_C(   41696),  SIMDE_POLY16_C(    7636),  SIMDE_POLY16_C(   15486),  SIMDE_POLY16_C(     842),
         SIMDE_POLY16_C(   14005),  SIMDE_POLY16_C(   53005),  SIMDE_POLY16_C(   58283),  SIMDE_POLY16_C(    8456) },
      {  SIMDE_POLY16_C(   41696),  SIMDE_POLY16_C(    7636),  SIMDE_POLY16_C(   15486),  SIMDE_POLY16_C(     842),
         SIMDE_POLY16_C(   14005),  SIMDE_POLY16_C(   39402),  SIMDE_POLY16_C(   58283),  SIMDE_POLY16_C(    2324) } },
    { {  SIMDE_POLY16_C(   31497),  SIMDE_POLY16_C(    5172),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(    4122),
         SIMDE_POLY16_C(   52072),  SIMDE_POLY16_C(   14663),  SIMDE_POLY16_C(    6643),  SIMDE_POLY16_C(   19646) },
      {  SIMDE_POLY16_C(    3117),  SIMDE_POLY16_C(    6887),  SIMDE_POLY16_C(    8411),  SIMDE_POLY16_C(   34695),
         SIMDE_POLY16_C(   37761),  SIMDE_POLY16_C(   62501),  SIMDE_POLY16_C(    1235),  SIMDE_POLY16_C(    7430) },
      {  SIMDE_POLY16_C(    7430),  SIMDE_POLY16_C(    5172),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(    4122),
         SIMDE_POLY16_C(   52072),  SIMDE_POLY16_C(   14663),  SIMDE_POLY16_C(    6643),  SIMDE_POLY16_C(   19646) },
      {  SIMDE_POLY16_C(   31497),  SIMDE_POLY16_C(    1235),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(    4122),
         SIMDE_POLY16_C(   52072),  SIMDE_POLY16_C(   14663),  SIMDE_POLY16_C(    6643),  SIMDE_POLY16_C(   19646) },
      {  SIMDE_POLY16_C(   31497),  SIMDE_POLY16_C(    5172),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(   37761),
         SIMDE_POLY16_C(   52072),  SIMDE_POLY16_C(   14663),  SIMDE_POLY16_C(    6643),  SIMDE_POLY16_C(   19646) },
      {  SIMDE_POLY16_C(   31497),  SIMDE_POLY16_C(    5172),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(    4122),
         SIMDE_POLY16_C(   52072),  SIMDE_POLY16_C(   34695),  SIMDE_POLY16_C(    6643),  SIMDE_POLY16_C(   19646) },
      {  SIMDE_POLY16_C(   31497),  SIMDE_POLY16_C(    5172),  SIMDE_POLY16_C(   59315),  SIMDE_POLY16_C(    4122),
         SIMDE_POLY16_C(   52072),  SIMDE_POLY16_C(   14663),  SIMDE_POLY16_C(    6643),  SIMDE_POLY16_C(    6887) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);

    simde_poly16x8_t r0_7 = simde_vcopyq_laneq_p16(a, 0, b, 7);
    simde_poly16x8_t r1_6 = simde_vcopyq_laneq_p16(a, 1, b, 6);
    simde_poly16x8_t r3_4 = simde_vcopyq_laneq_p16(a, 3, b, 4);
    simde_poly16x8_t r5_3 = simde_vcopyq_laneq_p16(a, 5, b, 3);
    simde_poly16x8_t r7_1 = simde_vcopyq_laneq_p16(a, 7, b, 1);

    simde_test_arm_neon_assert_equal_p16x8(r0_7, simde_vld1q_p16(test_vec[i].r0_7));
    simde_test_arm_neon_assert_equal_p16x8(r1_6, simde_vld1q_p16(test_vec[i].r1_6));
    simde_test_arm_neon_assert_equal_p16x8(r3_4, simde_vld1q_p16(test_vec[i].r3_4));
    simde_test_arm_neon_assert_equal_p16x8(r5_3, simde_vld1q_p16(test_vec[i].r5_3));
    simde_test_arm_neon_assert_equal_p16x8(r7_1, simde_vld1q_p16(test_vec[i].r7_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t b = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t r0_7 = simde_vcopyq_laneq_p16(a, 0, b, 7);
    simde_poly16x8_t r1_6 = simde_vcopyq_laneq_p16(a, 1, b, 6);
    simde_poly16x8_t r3_4 = simde_vcopyq_laneq_p16(a, 3, b, 4);
    simde_poly16x8_t r5_3 = simde_vcopyq_laneq_p16(a, 5, b, 3);
    simde_poly16x8_t r7_1 = simde_vcopyq_laneq_p16(a, 7, b, 1);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r0_7, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r1_6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r3_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r5_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r7_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[2];
    simde_poly64_t b[2];
    simde_poly64_t r0_0[2];
    simde_poly64_t r0_1[2];
    simde_poly64_t r1_0[2];
    simde_poly64_t r1_1[2];
  } test_vec[] = {
    { {  SIMDE_POLY64_C(13439609365108810888),  SIMDE_POLY64_C(15937695336418566217) },
      {  SIMDE_POLY64_C(11757999458065731058),  SIMDE_POLY64_C(17975820540431480162) },
      {  SIMDE_POLY64_C(11757999458065731058),  SIMDE_POLY64_C(15937695336418566217) },
      {  SIMDE_POLY64_C(17975820540431480162),  SIMDE_POLY64_C(15937695336418566217) },
      {  SIMDE_POLY64_C(13439609365108810888),  SIMDE_POLY64_C(11757999458065731058) },
      {  SIMDE_POLY64_C(13439609365108810888),  SIMDE_POLY64_C(17975820540431480162) } },
    { {  SIMDE_POLY64_C(16564546751237621820),  SIMDE_POLY64_C(12241248961613285278) },
      {  SIMDE_POLY64_C( 7641825135841022951),  SIMDE_POLY64_C(12315251603794302270) },
      {  SIMDE_POLY64_C( 7641825135841022951),  SIMDE_POLY64_C(12241248961613285278) },
      {  SIMDE_POLY64_C(12315251603794302270),  SIMDE_POLY64_C(12241248961613285278) },
      {  SIMDE_POLY64_C(16564546751237621820),  SIMDE_POLY64_C( 7641825135841022951) },
      {  SIMDE_POLY64_C(16564546751237621820),  SIMDE_POLY64_C(12315251603794302270) } },
    { {  SIMDE_POLY64_C(17704957791680247171),  SIMDE_POLY64_C( 9371616720984263202) },
      {  SIMDE_POLY64_C( 7276494259531683395),  SIMDE_POLY64_C( 5859910920720482327) },
      {  SIMDE_POLY64_C( 7276494259531683395),  SIMDE_POLY64_C( 9371616720984263202) },
      {  SIMDE_POLY64_C( 5859910920720482327),  SIMDE_POLY64_C( 9371616720984263202) },
      {  SIMDE_POLY64_C(17704957791680247171),  SIMDE_POLY64_C( 7276494259531683395) },
      {  SIMDE_POLY64_C(17704957791680247171),  SIMDE_POLY64_C( 5859910920720482327) } },
    { {  SIMDE_POLY64_C(14662575302122884717),  SIMDE_POLY64_C( 3176330314367196783) },
      {  SIMDE_POLY64_C( 7453175549508455517),  SIMDE_POLY64_C( 4453488503906172319) },
      {  SIMDE_POLY64_C( 7453175549508455517),  SIMDE_POLY64_C( 3176330314367196783) },
      {  SIMDE_POLY64_C( 4453488503906172319),  SIMDE_POLY64_C( 3176330314367196783) },
      {  SIMDE_POLY64_C(14662575302122884717),  SIMDE_POLY64_C( 7453175549508455517) },
      {  SIMDE_POLY64_C(14662575302122884717),  SIMDE_POLY64_C( 4453488503906172319) } },
    { {  SIMDE_POLY64_C(12249441119495819269),  SIMDE_POLY64_C(  186417079881519408) },
      {  SIMDE_POLY64_C(16358619248331576219),  SIMDE_POLY64_C(  987352505179597987) },
      {  SIMDE_POLY64_C(16358619248331576219),  SIMDE_POLY64_C(  186417079881519408) },
      {  SIMDE_POLY64_C(  987352505179597987),  SIMDE_POLY64_C(  186417079881519408) },
      {  SIMDE_POLY64_C(12249441119495819269),  SIMDE_POLY64_C(16358619248331576219) },
      {  SIMDE_POLY64_C(12249441119495819269),  SIMDE_POLY64_C(  987352505179597987) } },
    { {  SIMDE_POLY64_C( 3211036171106824205),  SIMDE_POLY64_C(17735964159800454359) },
      {  SIMDE_POLY64_C(14856931664874395873),  SIMDE_POLY64_C( 5092631228929164180) },
      {  SIMDE_POLY64_C(14856931664874395873),  SIMDE_POLY64_C(17735964159800454359) },
      {  SIMDE_POLY64_C( 5092631228929164180),  SIMDE_POLY64_C(17735964159800454359) },
      {  SIMDE_POLY64_C( 3211036171106824205),  SIMDE_POLY64_C(14856931664874395873) },
      {  SIMDE_POLY64_C( 3211036171106824205),  SIMDE_POLY64_C( 5092631228929164180) } },
    { {  SIMDE_POLY64_C(16290890406714175431),  SIMDE_POLY64_C( 7369026070235053466) },
      {  SIMDE_POLY64_C(14159949742399780407),  SIMDE_POLY64_C(12799840516808467205) },
      {  SIMDE_POLY64_C(14159949742399780407),  SIMDE_POLY64_C( 7369026070235053466) },
      {  SIMDE_POLY64_C(12799840516808467205),  SIMDE_POLY64_C( 7369026070235053466) },
      {  SIMDE_POLY64_C(16290890406714175431),  SIMDE_POLY64_C(14159949742399780407) },
      {  SIMDE_POLY64_C(16290890406714175431),  SIMDE_POLY64_C(12799840516808467205) } },
    { {  SIMDE_POLY64_C(11596480201225729972),  SIMDE_POLY64_C(15597658933811404841) },
      {  SIMDE_POLY64_C( 4501987111170332097),  SIMDE_POLY64_C(16539108248642911739) },
      {  SIMDE_POLY64_C( 4501987111170332097),  SIMDE_POLY64_C(15597658933811404841) },
      {  SIMDE_POLY64_C(16539108248642911739),  SIMDE_POLY64_C(15597658933811404841) },
      {  SIMDE_POLY64_C(11596480201225729972),  SIMDE_POLY64_C( 4501987111170332097) },
      {  SIMDE_POLY64_C(11596480201225729972),  SIMDE_POLY64_C(16539108248642911739) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t a = simde_vld1q_p64(test_vec[i].a);
    simde_poly64x2_t b = simde_vld1q_p64(test_vec[i].b);

    simde_poly64x2_t r0_0 = simde_vcopyq_laneq_p64(a, 0, b, 0);
    simde_poly64x2_t r0_1 = simde_vcopyq_laneq_p64(a, 0, b, 1);
    simde_poly64x2_t r1_0 = simde_vcopyq_laneq_p64(a, 1, b, 0);
    simde_poly64x2_t r1_1 = simde_vcopyq_laneq_p64(a, 1, b, 1);

    simde_test_arm_neon_assert_equal_p64x2(r0_0, simde_vld1q_p64(test_vec[i].r0_0));
    simde_test_arm_neon_assert_equal_p64x2(r0_1, simde_vld1q_p64(test_vec[i].r0_1));
    simde_test_arm_neon_assert_equal_p64x2(r1_0, simde_vld1q_p64(test_vec[i].r1_0));
    simde_test_arm_neon_assert_equal_p64x2(r1_1, simde_vld1q_p64(test_vec[i].r1_1));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x2_t a = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t b = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t r0_0 = simde_vcopyq_laneq_p64(a, 0, b, 0);
    simde_poly64x2_t r0_1 = simde_vcopyq_laneq_p64(a, 0, b, 1);
    simde_poly64x2_t r1_0 = simde_vcopyq_laneq_p64(a, 1, b, 0);
    simde_poly64x2_t r1_1 = simde_vcopyq_laneq_p64(a, 1, b, 1);

    simde_test_arm_neon_write_p64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r0_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r1_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r1_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t a[4];
    simde_bfloat16_t b[4];
    simde_bfloat16_t r00[4];
    simde_bfloat16_t r01[4];
    simde_bfloat16_t r13[4];
    simde_bfloat16_t r22[4];
    simde_bfloat16_t r33[4];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(   908.00), SIMDE_BFLOAT16_VALUE(  -852.00), SIMDE_BFLOAT16_VALUE(   788.00), SIMDE_BFLOAT16_VALUE(   880.00) },
      { SIMDE_BFLOAT16_VALUE(    15.94), SIMDE_BFLOAT16_VALUE(   964.00), SIMDE_BFLOAT16_VALUE(  -406.00), SIMDE_BFLOAT16_VALUE(   484.00) },
      { SIMDE_BFLOAT16_VALUE(    15.94), SIMDE_BFLOAT16_VALUE(  -852.00), SIMDE_BFLOAT16_VALUE(   788.00), SIMDE_BFLOAT16_VALUE(   880.00) },
      { SIMDE_BFLOAT16_VALUE(   964.00), SIMDE_BFLOAT16_VALUE(  -852.00), SIMDE_BFLOAT16_VALUE(   788.00), SIMDE_BFLOAT16_VALUE(   880.00) },
      { SIMDE_BFLOAT16_VALUE(   908.00), SIMDE_BFLOAT16_VALUE(   484.00), SIMDE_BFLOAT16_VALUE(   788.00), SIMDE_BFLOAT16_VALUE(   880.00) },
      { SIMDE_BFLOAT16_VALUE(   908.00), SIMDE_BFLOAT16_VALUE(  -852.00), SIMDE_BFLOAT16_VALUE(  -406.00), SIMDE_BFLOAT16_VALUE(   880.00) },
      { SIMDE_BFLOAT16_VALUE(   908.00), SIMDE_BFLOAT16_VALUE(  -852.00), SIMDE_BFLOAT16_VALUE(   788.00), SIMDE_BFLOAT16_VALUE(   484.00) } },
    { { SIMDE_BFLOAT16_VALUE(   -24.38), SIMDE_BFLOAT16_VALUE(  -424.00), SIMDE_BFLOAT16_VALUE(   864.00), SIMDE_BFLOAT16_VALUE(    25.25) },
      { SIMDE_BFLOAT16_VALUE(    95.00), SIMDE_BFLOAT16_VALUE(  -494.00), SIMDE_BFLOAT16_VALUE(  -340.00), SIMDE_BFLOAT16_VALUE(  -744.00) },
      { SIMDE_BFLOAT16_VALUE(    95.00), SIMDE_BFLOAT16_VALUE(  -424.00), SIMDE_BFLOAT16_VALUE(   864.00), SIMDE_BFLOAT16_VALUE(    25.25) },
      { SIMDE_BFLOAT16_VALUE(  -494.00), SIMDE_BFLOAT16_VALUE(  -424.00), SIMDE_BFLOAT16_VALUE(   864.00), SIMDE_BFLOAT16_VALUE(    25.25) },
      { SIMDE_BFLOAT16_VALUE(   -24.38), SIMDE_BFLOAT16_VALUE(  -744.00), SIMDE_BFLOAT16_VALUE(   864.00), SIMDE_BFLOAT16_VALUE(    25.25) },
      { SIMDE_BFLOAT16_VALUE(   -24.38), SIMDE_BFLOAT16_VALUE(  -424.00), SIMDE_BFLOAT16_VALUE(  -340.00), SIMDE_BFLOAT16_VALUE(    25.25) },
      { SIMDE_BFLOAT16_VALUE(   -24.38), SIMDE_BFLOAT16_VALUE(  -424.00), SIMDE_BFLOAT16_VALUE(   864.00), SIMDE_BFLOAT16_VALUE(  -744.00) } },
    { { SIMDE_BFLOAT16_VALUE(  -310.00), SIMDE_BFLOAT16_VALUE(   556.00), SIMDE_BFLOAT16_VALUE(  -434.00), SIMDE_BFLOAT16_VALUE(   884.00) },
      { SIMDE_BFLOAT16_VALUE(   430.00), SIMDE_BFLOAT16_VALUE(  -784.00), SIMDE_BFLOAT16_VALUE(  -458.00), SIMDE_BFLOAT16_VALUE(   224.00) },
      { SIMDE_BFLOAT16_VALUE(   430.00), SIMDE_BFLOAT16_VALUE(   556.00), SIMDE_BFLOAT16_VALUE(  -434.00), SIMDE_BFLOAT16_VALUE(   884.00) },
      { SIMDE_BFLOAT16_VALUE(  -784.00), SIMDE_BFLOAT16_VALUE(   556.00), SIMDE_BFLOAT16_VALUE(  -434.00), SIMDE_BFLOAT16_VALUE(   884.00) },
      { SIMDE_BFLOAT16_VALUE(  -310.00), SIMDE_BFLOAT16_VALUE(   224.00), SIMDE_BFLOAT16_VALUE(  -434.00), SIMDE_BFLOAT16_VALUE(   884.00) },
      { SIMDE_BFLOAT16_VALUE(  -310.00), SIMDE_BFLOAT16_VALUE(   556.00), SIMDE_BFLOAT16_VALUE(  -458.00), SIMDE_BFLOAT16_VALUE(   884.00) },
      { SIMDE_BFLOAT16_VALUE(  -310.00), SIMDE_BFLOAT16_VALUE(   556.00), SIMDE_BFLOAT16_VALUE(  -434.00), SIMDE_BFLOAT16_VALUE(   224.00) } },
    { { SIMDE_BFLOAT16_VALUE(  -964.00), SIMDE_BFLOAT16_VALUE(   -90.00), SIMDE_BFLOAT16_VALUE(  -940.00), SIMDE_BFLOAT16_VALUE(  -204.00) },
      { SIMDE_BFLOAT16_VALUE(  -390.00), SIMDE_BFLOAT16_VALUE(   -57.00), SIMDE_BFLOAT16_VALUE(   332.00), SIMDE_BFLOAT16_VALUE(  -480.00) },
      { SIMDE_BFLOAT16_VALUE(  -390.00), SIMDE_BFLOAT16_VALUE(   -90.00), SIMDE_BFLOAT16_VALUE(  -940.00), SIMDE_BFLOAT16_VALUE(  -204.00) },
      { SIMDE_BFLOAT16_VALUE(   -57.00), SIMDE_BFLOAT16_VALUE(   -90.00), SIMDE_BFLOAT16_VALUE(  -940.00), SIMDE_BFLOAT16_VALUE(  -204.00) },
      { SIMDE_BFLOAT16_VALUE(  -964.00), SIMDE_BFLOAT16_VALUE(  -480.00), SIMDE_BFLOAT16_VALUE(  -940.00), SIMDE_BFLOAT16_VALUE(  -204.00) },
      { SIMDE_BFLOAT16_VALUE(  -964.00), SIMDE_BFLOAT16_VALUE(   -90.00), SIMDE_BFLOAT16_VALUE(   332.00), SIMDE_BFLOAT16_VALUE(  -204.00) },
      { SIMDE_BFLOAT16_VALUE(  -964.00), SIMDE_BFLOAT16_VALUE(   -90.00), SIMDE_BFLOAT16_VALUE(  -940.00), SIMDE_BFLOAT16_VALUE(  -480.00) } },
    { { SIMDE_BFLOAT16_VALUE(    89.50), SIMDE_BFLOAT16_VALUE(   124.50), SIMDE_BFLOAT16_VALUE(  -596.00), SIMDE_BFLOAT16_VALUE(  -892.00) },
      { SIMDE_BFLOAT16_VALUE(    90.00), SIMDE_BFLOAT16_VALUE(    -6.28), SIMDE_BFLOAT16_VALUE(   588.00), SIMDE_BFLOAT16_VALUE(  -932.00) },
      { SIMDE_BFLOAT16_VALUE(    90.00), SIMDE_BFLOAT16_VALUE(   124.50), SIMDE_BFLOAT16_VALUE(  -596.00), SIMDE_BFLOAT16_VALUE(  -892.00) },
      { SIMDE_BFLOAT16_VALUE(    -6.28), SIMDE_BFLOAT16_VALUE(   124.50), SIMDE_BFLOAT16_VALUE(  -596.00), SIMDE_BFLOAT16_VALUE(  -892.00) },
      { SIMDE_BFLOAT16_VALUE(    89.50), SIMDE_BFLOAT16_VALUE(  -932.00), SIMDE_BFLOAT16_VALUE(  -596.00), SIMDE_BFLOAT16_VALUE(  -892.00) },
      { SIMDE_BFLOAT16_VALUE(    89.50), SIMDE_BFLOAT16_VALUE(   124.50), SIMDE_BFLOAT16_VALUE(   588.00), SIMDE_BFLOAT16_VALUE(  -892.00) },
      { SIMDE_BFLOAT16_VALUE(    89.50), SIMDE_BFLOAT16_VALUE(   124.50), SIMDE_BFLOAT16_VALUE(  -596.00), SIMDE_BFLOAT16_VALUE(  -932.00) } },
    { { SIMDE_BFLOAT16_VALUE(   568.00), SIMDE_BFLOAT16_VALUE(   456.00), SIMDE_BFLOAT16_VALUE(    91.00), SIMDE_BFLOAT16_VALUE(  -336.00) },
      { SIMDE_BFLOAT16_VALUE(   960.00), SIMDE_BFLOAT16_VALUE(   748.00), SIMDE_BFLOAT16_VALUE(   -81.50), SIMDE_BFLOAT16_VALUE(  -348.00) },
      { SIMDE_BFLOAT16_VALUE(   960.00), SIMDE_BFLOAT16_VALUE(   456.00), SIMDE_BFLOAT16_VALUE(    91.00), SIMDE_BFLOAT16_VALUE(  -336.00) },
      { SIMDE_BFLOAT16_VALUE(   748.00), SIMDE_BFLOAT16_VALUE(   456.00), SIMDE_BFLOAT16_VALUE(    91.00), SIMDE_BFLOAT16_VALUE(  -336.00) },
      { SIMDE_BFLOAT16_VALUE(   568.00), SIMDE_BFLOAT16_VALUE(  -348.00), SIMDE_BFLOAT16_VALUE(    91.00), SIMDE_BFLOAT16_VALUE(  -336.00) },
      { SIMDE_BFLOAT16_VALUE(   568.00), SIMDE_BFLOAT16_VALUE(   456.00), SIMDE_BFLOAT16_VALUE(   -81.50), SIMDE_BFLOAT16_VALUE(  -336.00) },
      { SIMDE_BFLOAT16_VALUE(   568.00), SIMDE_BFLOAT16_VALUE(   456.00), SIMDE_BFLOAT16_VALUE(    91.00), SIMDE_BFLOAT16_VALUE(  -348.00) } },
    { { SIMDE_BFLOAT16_VALUE(   308.00), SIMDE_BFLOAT16_VALUE(   482.00), SIMDE_BFLOAT16_VALUE(  -462.00), SIMDE_BFLOAT16_VALUE(  -260.00) },
      { SIMDE_BFLOAT16_VALUE(   692.00), SIMDE_BFLOAT16_VALUE(    78.00), SIMDE_BFLOAT16_VALUE(   960.00), SIMDE_BFLOAT16_VALUE(   728.00) },
      { SIMDE_BFLOAT16_VALUE(   692.00), SIMDE_BFLOAT16_VALUE(   482.00), SIMDE_BFLOAT16_VALUE(  -462.00), SIMDE_BFLOAT16_VALUE(  -260.00) },
      { SIMDE_BFLOAT16_VALUE(    78.00), SIMDE_BFLOAT16_VALUE(   482.00), SIMDE_BFLOAT16_VALUE(  -462.00), SIMDE_BFLOAT16_VALUE(  -260.00) },
      { SIMDE_BFLOAT16_VALUE(   308.00), SIMDE_BFLOAT16_VALUE(   728.00), SIMDE_BFLOAT16_VALUE(  -462.00), SIMDE_BFLOAT16_VALUE(  -260.00) },
      { SIMDE_BFLOAT16_VALUE(   308.00), SIMDE_BFLOAT16_VALUE(   482.00), SIMDE_BFLOAT16_VALUE(   960.00), SIMDE_BFLOAT16_VALUE(  -260.00) },
      { SIMDE_BFLOAT16_VALUE(   308.00), SIMDE_BFLOAT16_VALUE(   482.00), SIMDE_BFLOAT16_VALUE(  -462.00), SIMDE_BFLOAT16_VALUE(   728.00) } },
    { { SIMDE_BFLOAT16_VALUE(   984.00), SIMDE_BFLOAT16_VALUE(  -980.00), SIMDE_BFLOAT16_VALUE(  -472.00), SIMDE_BFLOAT16_VALUE(  -402.00) },
      { SIMDE_BFLOAT16_VALUE(   -37.25), SIMDE_BFLOAT16_VALUE(   860.00), SIMDE_BFLOAT16_VALUE(   114.50), SIMDE_BFLOAT16_VALUE(  -944.00) },
      { SIMDE_BFLOAT16_VALUE(   -37.25), SIMDE_BFLOAT16_VALUE(  -980.00), SIMDE_BFLOAT16_VALUE(  -472.00), SIMDE_BFLOAT16_VALUE(  -402.00) },
      { SIMDE_BFLOAT16_VALUE(   860.00), SIMDE_BFLOAT16_VALUE(  -980.00), SIMDE_BFLOAT16_VALUE(  -472.00), SIMDE_BFLOAT16_VALUE(  -402.00) },
      { SIMDE_BFLOAT16_VALUE(   984.00), SIMDE_BFLOAT16_VALUE(  -944.00), SIMDE_BFLOAT16_VALUE(  -472.00), SIMDE_BFLOAT16_VALUE(  -402.00) },
      { SIMDE_BFLOAT16_VALUE(   984.00), SIMDE_BFLOAT16_VALUE(  -980.00), SIMDE_BFLOAT16_VALUE(   114.50), SIMDE_BFLOAT16_VALUE(  -402.00) },
      { SIMDE_BFLOAT16_VALUE(   984.00), SIMDE_BFLOAT16_VALUE(  -980.00), SIMDE_BFLOAT16_VALUE(  -472.00), SIMDE_BFLOAT16_VALUE(  -944.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4_t a = simde_vld1_bf16(test_vec[i].a);
    simde_bfloat16x4_t b = simde_vld1_bf16(test_vec[i].b);

    simde_bfloat16x4_t r00 = simde_vcopy_lane_bf16(a, 0, b, 0);
    simde_bfloat16x4_t r01 = simde_vcopy_lane_bf16(a, 0, b, 1);
    simde_bfloat16x4_t r13 = simde_vcopy_lane_bf16(a, 1, b, 3);
    simde_bfloat16x4_t r22 = simde_vcopy_lane_bf16(a, 2, b, 2);
    simde_bfloat16x4_t r33 = simde_vcopy_lane_bf16(a, 3, b, 3);

    simde_test_arm_neon_assert_equal_bf16x4(r00, simde_vld1_bf16(test_vec[i].r00), 1);
    simde_test_arm_neon_assert_equal_bf16x4(r01, simde_vld1_bf16(test_vec[i].r01), 1);
    simde_test_arm_neon_assert_equal_bf16x4(r13, simde_vld1_bf16(test_vec[i].r13), 1);
    simde_test_arm_neon_assert_equal_bf16x4(r22, simde_vld1_bf16(test_vec[i].r22), 1);
    simde_test_arm_neon_assert_equal_bf16x4(r33, simde_vld1_bf16(test_vec[i].r33), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x4_t a = simde_test_arm_neon_random_bf16x4(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_bfloat16x4_t b = simde_test_arm_neon_random_bf16x4(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_bfloat16x4_t r00 = simde_vcopy_lane_bf16(a, 0, b, 0);
    simde_bfloat16x4_t r01 = simde_vcopy_lane_bf16(a, 0, b, 1);
    simde_bfloat16x4_t r13 = simde_vcopy_lane_bf16(a, 1, b, 3);
    simde_bfloat16x4_t r22 = simde_vcopy_lane_bf16(a, 2, b, 2);
    simde_bfloat16x4_t r33 = simde_vcopy_lane_bf16(a, 3, b, 3);

    simde_test_arm_neon_write_bf16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r00, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r01, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r22, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r33, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopy_laneq_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t a[4];
    simde_bfloat16_t b[8];
    simde_bfloat16_t r0_0[4];
    simde_bfloat16_t r1_3[4];
    simde_bfloat16_t r2_5[4];
    simde_bfloat16_t r3_7[4];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(  -536.00), SIMDE_BFLOAT16_VALUE(  -217.00), SIMDE_BFLOAT16_VALUE(  -788.00) },
      { SIMDE_BFLOAT16_VALUE(   572.00), SIMDE_BFLOAT16_VALUE(   143.00), SIMDE_BFLOAT16_VALUE(   732.00), SIMDE_BFLOAT16_VALUE(  -114.00),
        SIMDE_BFLOAT16_VALUE(  -392.00), SIMDE_BFLOAT16_VALUE(   272.00), SIMDE_BFLOAT16_VALUE(   498.00), SIMDE_BFLOAT16_VALUE(   382.00) },
      { SIMDE_BFLOAT16_VALUE(   572.00), SIMDE_BFLOAT16_VALUE(  -536.00), SIMDE_BFLOAT16_VALUE(  -217.00), SIMDE_BFLOAT16_VALUE(  -788.00) },
      { SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(  -114.00), SIMDE_BFLOAT16_VALUE(  -217.00), SIMDE_BFLOAT16_VALUE(  -788.00) },
      { SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(  -536.00), SIMDE_BFLOAT16_VALUE(   272.00), SIMDE_BFLOAT16_VALUE(  -788.00) },
      { SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(  -536.00), SIMDE_BFLOAT16_VALUE(  -217.00), SIMDE_BFLOAT16_VALUE(   382.00) } },
    { { SIMDE_BFLOAT16_VALUE(   128.00), SIMDE_BFLOAT16_VALUE(   652.00), SIMDE_BFLOAT16_VALUE(   290.00), SIMDE_BFLOAT16_VALUE(  -860.00) },
      { SIMDE_BFLOAT16_VALUE(   302.00), SIMDE_BFLOAT16_VALUE(  -672.00), SIMDE_BFLOAT16_VALUE(  -752.00), SIMDE_BFLOAT16_VALUE(   736.00),
        SIMDE_BFLOAT16_VALUE(  -106.50), SIMDE_BFLOAT16_VALUE(  -524.00), SIMDE_BFLOAT16_VALUE(  -996.00), SIMDE_BFLOAT16_VALUE(   420.00) },
      { SIMDE_BFLOAT16_VALUE(   302.00), SIMDE_BFLOAT16_VALUE(   652.00), SIMDE_BFLOAT16_VALUE(   290.00), SIMDE_BFLOAT16_VALUE(  -860.00) },
      { SIMDE_BFLOAT16_VALUE(   128.00), SIMDE_BFLOAT16_VALUE(   736.00), SIMDE_BFLOAT16_VALUE(   290.00), SIMDE_BFLOAT16_VALUE(  -860.00) },
      { SIMDE_BFLOAT16_VALUE(   128.00), SIMDE_BFLOAT16_VALUE(   652.00), SIMDE_BFLOAT16_VALUE(  -524.00), SIMDE_BFLOAT16_VALUE(  -860.00) },
      { SIMDE_BFLOAT16_VALUE(   128.00), SIMDE_BFLOAT16_VALUE(   652.00), SIMDE_BFLOAT16_VALUE(   290.00), SIMDE_BFLOAT16_VALUE(   420.00) } },
    { { SIMDE_BFLOAT16_VALUE(  -640.00), SIMDE_BFLOAT16_VALUE(  -696.00), SIMDE_BFLOAT16_VALUE(  -688.00), SIMDE_BFLOAT16_VALUE(  -632.00) },
      { SIMDE_BFLOAT16_VALUE(    86.50), SIMDE_BFLOAT16_VALUE(   428.00), SIMDE_BFLOAT16_VALUE(  -912.00), SIMDE_BFLOAT16_VALUE(   175.00),
        SIMDE_BFLOAT16_VALUE(   888.00), SIMDE_BFLOAT16_VALUE(  -131.00), SIMDE_BFLOAT16_VALUE(   382.00), SIMDE_BFLOAT16_VALUE(   462.00) },
      { SIMDE_BFLOAT16_VALUE(    86.50), SIMDE_BFLOAT16_VALUE(  -696.00), SIMDE_BFLOAT16_VALUE(  -688.00), SIMDE_BFLOAT16_VALUE(  -632.00) },
      { SIMDE_BFLOAT16_VALUE(  -640.00), SIMDE_BFLOAT16_VALUE(   175.00), SIMDE_BFLOAT16_VALUE(  -688.00), SIMDE_BFLOAT16_VALUE(  -632.00) },
      { SIMDE_BFLOAT16_VALUE(  -640.00), SIMDE_BFLOAT16_VALUE(  -696.00), SIMDE_BFLOAT16_VALUE(  -131.00), SIMDE_BFLOAT16_VALUE(  -632.00) },
      { SIMDE_BFLOAT16_VALUE(  -640.00), SIMDE_BFLOAT16_VALUE(  -696.00), SIMDE_BFLOAT16_VALUE(  -688.00), SIMDE_BFLOAT16_VALUE(   462.00) } },
    { { SIMDE_BFLOAT16_VALUE(  -988.00), SIMDE_BFLOAT16_VALUE(   118.50), SIMDE_BFLOAT16_VALUE(  -648.00), SIMDE_BFLOAT16_VALUE(  -380.00) },
      { SIMDE_BFLOAT16_VALUE(  -608.00), SIMDE_BFLOAT16_VALUE(   844.00), SIMDE_BFLOAT16_VALUE(  -996.00), SIMDE_BFLOAT16_VALUE(   520.00),
        SIMDE_BFLOAT16_VALUE(   502.00), SIMDE_BFLOAT16_VALUE(   292.00), SIMDE_BFLOAT16_VALUE(   656.00), SIMDE_BFLOAT16_VALUE(  -194.00) },
      { SIMDE_BFLOAT16_VALUE(  -608.00), SIMDE_BFLOAT16_VALUE(   118.50), SIMDE_BFLOAT16_VALUE(  -648.00), SIMDE_BFLOAT16_VALUE(  -380.00) },
      { SIMDE_BFLOAT16_VALUE(  -988.00), SIMDE_BFLOAT16_VALUE(   520.00), SIMDE_BFLOAT16_VALUE(  -648.00), SIMDE_BFLOAT16_VALUE(  -380.00) },
      { SIMDE_BFLOAT16_VALUE(  -988.00), SIMDE_BFLOAT16_VALUE(   118.50), SIMDE_BFLOAT16_VALUE(   292.00), SIMDE_BFLOAT16_VALUE(  -380.00) },
      { SIMDE_BFLOAT16_VALUE(  -988.00), SIMDE_BFLOAT16_VALUE(   118.50), SIMDE_BFLOAT16_VALUE(  -648.00), SIMDE_BFLOAT16_VALUE(  -194.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4_t a = simde_vld1_bf16(test_vec[i].a);
    simde_bfloat16x8_t b = simde_vld1q_bf16(test_vec[i].b);

    simde_bfloat16x4_t r0_0 = simde_vcopy_laneq_bf16(a, 0, b, 0);
    simde_bfloat16x4_t r1_3 = simde_vcopy_laneq_bf16(a, 1, b, 3);
    simde_bfloat16x4_t r2_5 = simde_vcopy_laneq_bf16(a, 2, b, 5);
    simde_bfloat16x4_t r3_7 = simde_vcopy_laneq_bf16(a, 3, b, 7);

    simde_test_arm_neon_assert_equal_bf16x4(r0_0, simde_vld1_bf16(test_vec[i].r0_0), 1);
    simde_test_arm_neon_assert_equal_bf16x4(r1_3, simde_vld1_bf16(test_vec[i].r1_3), 1);
    simde_test_arm_neon_assert_equal_bf16x4(r2_5, simde_vld1_bf16(test_vec[i].r2_5), 1);
    simde_test_arm_neon_assert_equal_bf16x4(r3_7, simde_vld1_bf16(test_vec[i].r3_7), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x4_t a = simde_test_arm_neon_random_bf16x4(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_bfloat16x8_t b = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_bfloat16x4_t r0_0 = simde_vcopy_laneq_bf16(a, 0, b, 0);
    simde_bfloat16x4_t r1_3 = simde_vcopy_laneq_bf16(a, 1, b, 3);
    simde_bfloat16x4_t r2_5 = simde_vcopy_laneq_bf16(a, 2, b, 5);
    simde_bfloat16x4_t r3_7 = simde_vcopy_laneq_bf16(a, 3, b, 7);

    simde_test_arm_neon_write_bf16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r0_0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r1_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r2_5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x4(2, r3_7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t a[8];
    simde_bfloat16_t b[4];
    simde_bfloat16_t r0_3[8];
    simde_bfloat16_t r3_2[8];
    simde_bfloat16_t r5_1[8];
    simde_bfloat16_t r7_0[8];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(   616.00), SIMDE_BFLOAT16_VALUE(   900.00), SIMDE_BFLOAT16_VALUE(  -454.00), SIMDE_BFLOAT16_VALUE(  -486.00),
        SIMDE_BFLOAT16_VALUE(  -620.00), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(   932.00), SIMDE_BFLOAT16_VALUE(  -262.00) },
      { SIMDE_BFLOAT16_VALUE(  -151.00), SIMDE_BFLOAT16_VALUE(  -756.00), SIMDE_BFLOAT16_VALUE(   100.50), SIMDE_BFLOAT16_VALUE(   932.00) },
      { SIMDE_BFLOAT16_VALUE(   932.00), SIMDE_BFLOAT16_VALUE(   900.00), SIMDE_BFLOAT16_VALUE(  -454.00), SIMDE_BFLOAT16_VALUE(  -486.00),
        SIMDE_BFLOAT16_VALUE(  -620.00), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(   932.00), SIMDE_BFLOAT16_VALUE(  -262.00) },
      { SIMDE_BFLOAT16_VALUE(   616.00), SIMDE_BFLOAT16_VALUE(   900.00), SIMDE_BFLOAT16_VALUE(  -454.00), SIMDE_BFLOAT16_VALUE(   100.50),
        SIMDE_BFLOAT16_VALUE(  -620.00), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(   932.00), SIMDE_BFLOAT16_VALUE(  -262.00) },
      { SIMDE_BFLOAT16_VALUE(   616.00), SIMDE_BFLOAT16_VALUE(   900.00), SIMDE_BFLOAT16_VALUE(  -454.00), SIMDE_BFLOAT16_VALUE(  -486.00),
        SIMDE_BFLOAT16_VALUE(  -620.00), SIMDE_BFLOAT16_VALUE(  -756.00), SIMDE_BFLOAT16_VALUE(   932.00), SIMDE_BFLOAT16_VALUE(  -262.00) },
      { SIMDE_BFLOAT16_VALUE(   616.00), SIMDE_BFLOAT16_VALUE(   900.00), SIMDE_BFLOAT16_VALUE(  -454.00), SIMDE_BFLOAT16_VALUE(  -486.00),
        SIMDE_BFLOAT16_VALUE(  -620.00), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(   932.00), SIMDE_BFLOAT16_VALUE(  -151.00) } },
    { { SIMDE_BFLOAT16_VALUE(   672.00), SIMDE_BFLOAT16_VALUE(   186.00), SIMDE_BFLOAT16_VALUE(   111.00), SIMDE_BFLOAT16_VALUE(   560.00),
        SIMDE_BFLOAT16_VALUE(  -944.00), SIMDE_BFLOAT16_VALUE(  -504.00), SIMDE_BFLOAT16_VALUE(    23.75), SIMDE_BFLOAT16_VALUE(  -932.00) },
      { SIMDE_BFLOAT16_VALUE(   612.00), SIMDE_BFLOAT16_VALUE(   372.00), SIMDE_BFLOAT16_VALUE(  -314.00), SIMDE_BFLOAT16_VALUE(  -992.00) },
      { SIMDE_BFLOAT16_VALUE(  -992.00), SIMDE_BFLOAT16_VALUE(   186.00), SIMDE_BFLOAT16_VALUE(   111.00), SIMDE_BFLOAT16_VALUE(   560.00),
        SIMDE_BFLOAT16_VALUE(  -944.00), SIMDE_BFLOAT16_VALUE(  -504.00), SIMDE_BFLOAT16_VALUE(    23.75), SIMDE_BFLOAT16_VALUE(  -932.00) },
      { SIMDE_BFLOAT16_VALUE(   672.00), SIMDE_BFLOAT16_VALUE(   186.00), SIMDE_BFLOAT16_VALUE(   111.00), SIMDE_BFLOAT16_VALUE(  -314.00),
        SIMDE_BFLOAT16_VALUE(  -944.00), SIMDE_BFLOAT16_VALUE(  -504.00), SIMDE_BFLOAT16_VALUE(    23.75), SIMDE_BFLOAT16_VALUE(  -932.00) },
      { SIMDE_BFLOAT16_VALUE(   672.00), SIMDE_BFLOAT16_VALUE(   186.00), SIMDE_BFLOAT16_VALUE(   111.00), SIMDE_BFLOAT16_VALUE(   560.00),
        SIMDE_BFLOAT16_VALUE(  -944.00), SIMDE_BFLOAT16_VALUE(   372.00), SIMDE_BFLOAT16_VALUE(    23.75), SIMDE_BFLOAT16_VALUE(  -932.00) },
      { SIMDE_BFLOAT16_VALUE(   672.00), SIMDE_BFLOAT16_VALUE(   186.00), SIMDE_BFLOAT16_VALUE(   111.00), SIMDE_BFLOAT16_VALUE(   560.00),
        SIMDE_BFLOAT16_VALUE(  -944.00), SIMDE_BFLOAT16_VALUE(  -504.00), SIMDE_BFLOAT16_VALUE(    23.75), SIMDE_BFLOAT16_VALUE(   612.00) } },
    { { SIMDE_BFLOAT16_VALUE(   220.00), SIMDE_BFLOAT16_VALUE(  -312.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(  -276.00),
        SIMDE_BFLOAT16_VALUE(   980.00), SIMDE_BFLOAT16_VALUE(   184.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(   596.00) },
      { SIMDE_BFLOAT16_VALUE(    87.00), SIMDE_BFLOAT16_VALUE(  -928.00), SIMDE_BFLOAT16_VALUE(  -884.00), SIMDE_BFLOAT16_VALUE(   464.00) },
      { SIMDE_BFLOAT16_VALUE(   464.00), SIMDE_BFLOAT16_VALUE(  -312.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(  -276.00),
        SIMDE_BFLOAT16_VALUE(   980.00), SIMDE_BFLOAT16_VALUE(   184.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(   596.00) },
      { SIMDE_BFLOAT16_VALUE(   220.00), SIMDE_BFLOAT16_VALUE(  -312.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(  -884.00),
        SIMDE_BFLOAT16_VALUE(   980.00), SIMDE_BFLOAT16_VALUE(   184.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(   596.00) },
      { SIMDE_BFLOAT16_VALUE(   220.00), SIMDE_BFLOAT16_VALUE(  -312.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(  -276.00),
        SIMDE_BFLOAT16_VALUE(   980.00), SIMDE_BFLOAT16_VALUE(  -928.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(   596.00) },
      { SIMDE_BFLOAT16_VALUE(   220.00), SIMDE_BFLOAT16_VALUE(  -312.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(  -276.00),
        SIMDE_BFLOAT16_VALUE(   980.00), SIMDE_BFLOAT16_VALUE(   184.00), SIMDE_BFLOAT16_VALUE(   524.00), SIMDE_BFLOAT16_VALUE(    87.00) } },
    { { SIMDE_BFLOAT16_VALUE(  -380.00), SIMDE_BFLOAT16_VALUE(  -952.00), SIMDE_BFLOAT16_VALUE(  -796.00), SIMDE_BFLOAT16_VALUE(   466.00),
        SIMDE_BFLOAT16_VALUE(  -708.00), SIMDE_BFLOAT16_VALUE(   300.00), SIMDE_BFLOAT16_VALUE(   402.00), SIMDE_BFLOAT16_VALUE(   960.00) },
      { SIMDE_BFLOAT16_VALUE(  -510.00), SIMDE_BFLOAT16_VALUE(  -484.00), SIMDE_BFLOAT16_VALUE(   520.00), SIMDE_BFLOAT16_VALUE(  -456.00) },
      { SIMDE_BFLOAT16_VALUE(  -456.00), SIMDE_BFLOAT16_VALUE(  -952.00), SIMDE_BFLOAT16_VALUE(  -796.00), SIMDE_BFLOAT16_VALUE(   466.00),
        SIMDE_BFLOAT16_VALUE(  -708.00), SIMDE_BFLOAT16_VALUE(   300.00), SIMDE_BFLOAT16_VALUE(   402.00), SIMDE_BFLOAT16_VALUE(   960.00) },
      { SIMDE_BFLOAT16_VALUE(  -380.00), SIMDE_BFLOAT16_VALUE(  -952.00), SIMDE_BFLOAT16_VALUE(  -796.00), SIMDE_BFLOAT16_VALUE(   520.00),
        SIMDE_BFLOAT16_VALUE(  -708.00), SIMDE_BFLOAT16_VALUE(   300.00), SIMDE_BFLOAT16_VALUE(   402.00), SIMDE_BFLOAT16_VALUE(   960.00) },
      { SIMDE_BFLOAT16_VALUE(  -380.00), SIMDE_BFLOAT16_VALUE(  -952.00), SIMDE_BFLOAT16_VALUE(  -796.00), SIMDE_BFLOAT16_VALUE(   466.00),
        SIMDE_BFLOAT16_VALUE(  -708.00), SIMDE_BFLOAT16_VALUE(  -484.00), SIMDE_BFLOAT16_VALUE(   402.00), SIMDE_BFLOAT16_VALUE(   960.00) },
      { SIMDE_BFLOAT16_VALUE(  -380.00), SIMDE_BFLOAT16_VALUE(  -952.00), SIMDE_BFLOAT16_VALUE(  -796.00), SIMDE_BFLOAT16_VALUE(   466.00),
        SIMDE_BFLOAT16_VALUE(  -708.00), SIMDE_BFLOAT16_VALUE(   300.00), SIMDE_BFLOAT16_VALUE(   402.00), SIMDE_BFLOAT16_VALUE(  -510.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t a = simde_vld1q_bf16(test_vec[i].a);
    simde_bfloat16x4_t b = simde_vld1_bf16(test_vec[i].b);

    simde_bfloat16x8_t r0_3 = simde_vcopyq_lane_bf16(a, 0, b, 3);
    simde_bfloat16x8_t r3_2 = simde_vcopyq_lane_bf16(a, 3, b, 2);
    simde_bfloat16x8_t r5_1 = simde_vcopyq_lane_bf16(a, 5, b, 1);
    simde_bfloat16x8_t r7_0 = simde_vcopyq_lane_bf16(a, 7, b, 0);

    simde_test_arm_neon_assert_equal_bf16x8(r0_3, simde_vld1q_bf16(test_vec[i].r0_3), 1);
    simde_test_arm_neon_assert_equal_bf16x8(r3_2, simde_vld1q_bf16(test_vec[i].r3_2), 1);
    simde_test_arm_neon_assert_equal_bf16x8(r5_1, simde_vld1q_bf16(test_vec[i].r5_1), 1);
    simde_test_arm_neon_assert_equal_bf16x8(r7_0, simde_vld1q_bf16(test_vec[i].r7_0), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x8_t a = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_bfloat16x4_t b = simde_test_arm_neon_random_bf16x4(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_bfloat16x8_t r0_3 = simde_vcopyq_lane_bf16(a, 0, b, 3);
    simde_bfloat16x8_t r3_2 = simde_vcopyq_lane_bf16(a, 3, b, 2);
    simde_bfloat16x8_t r5_1 = simde_vcopyq_lane_bf16(a, 5, b, 1);
    simde_bfloat16x8_t r7_0 = simde_vcopyq_lane_bf16(a, 7, b, 0);

    simde_test_arm_neon_write_bf16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r0_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r3_2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r5_1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r7_0, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcopyq_laneq_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t a[8];
    simde_bfloat16_t b[8];
    simde_bfloat16_t r0_7[8];
    simde_bfloat16_t r1_6[8];
    simde_bfloat16_t r3_4[8];
    simde_bfloat16_t r5_3[8];
    simde_bfloat16_t r7_1[8];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(     9.06), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(  -388.00), SIMDE_BFLOAT16_VALUE(  -376.00),
        SIMDE_BFLOAT16_VALUE(   916.00), SIMDE_BFLOAT16_VALUE(   296.00), SIMDE_BFLOAT16_VALUE(  -370.00), SIMDE_BFLOAT16_VALUE(   139.00) },
      { SIMDE_BFLOAT16_VALUE(   980.00), SIMDE_BFLOAT16_VALUE(  -844.00), SIMDE_BFLOAT16_VALUE(   860.00), SIMDE_BFLOAT16_VALUE(   964.00),
        SIMDE_BFLOAT16_VALUE(   336.00), SIMDE_BFLOAT16_VALUE(   388.00), SIMDE_BFLOAT16_VALUE(   560.00), SIMDE_BFLOAT16_VALUE(  -572.00) },
      { SIMDE_BFLOAT16_VALUE(  -572.00), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(  -388.00), SIMDE_BFLOAT16_VALUE(  -376.00),
        SIMDE_BFLOAT16_VALUE(   916.00), SIMDE_BFLOAT16_VALUE(   296.00), SIMDE_BFLOAT16_VALUE(  -370.00), SIMDE_BFLOAT16_VALUE(   139.00) },
      { SIMDE_BFLOAT16_VALUE(     9.06), SIMDE_BFLOAT16_VALUE(   560.00), SIMDE_BFLOAT16_VALUE(  -388.00), SIMDE_BFLOAT16_VALUE(  -376.00),
        SIMDE_BFLOAT16_VALUE(   916.00), SIMDE_BFLOAT16_VALUE(   296.00), SIMDE_BFLOAT16_VALUE(  -370.00), SIMDE_BFLOAT16_VALUE(   139.00) },
      { SIMDE_BFLOAT16_VALUE(     9.06), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(  -388.00), SIMDE_BFLOAT16_VALUE(   336.00),
        SIMDE_BFLOAT16_VALUE(   916.00), SIMDE_BFLOAT16_VALUE(   296.00), SIMDE_BFLOAT16_VALUE(  -370.00), SIMDE_BFLOAT16_VALUE(   139.00) },
      { SIMDE_BFLOAT16_VALUE(     9.06), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(  -388.00), SIMDE_BFLOAT16_VALUE(  -376.00),
        SIMDE_BFLOAT16_VALUE(   916.00), SIMDE_BFLOAT16_VALUE(   964.00), SIMDE_BFLOAT16_VALUE(  -370.00), SIMDE_BFLOAT16_VALUE(   139.00) },
      { SIMDE_BFLOAT16_VALUE(     9.06), SIMDE_BFLOAT16_VALUE(  -452.00), SIMDE_BFLOAT16_VALUE(  -388.00), SIMDE_BFLOAT16_VALUE(  -376.00),
        SIMDE_BFLOAT16_VALUE(   916.00), SIMDE_BFLOAT16_VALUE(   296.00), SIMDE_BFLOAT16_VALUE(  -370.00), SIMDE_BFLOAT16_VALUE(  -844.00) } },
    { { SIMDE_BFLOAT16_VALUE(   460.00), SIMDE_BFLOAT16_VALUE(   676.00), SIMDE_BFLOAT16_VALUE(   888.00), SIMDE_BFLOAT16_VALUE(  -916.00),
        SIMDE_BFLOAT16_VALUE(   720.00), SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(   544.00), SIMDE_BFLOAT16_VALUE(  -984.00) },
      { SIMDE_BFLOAT16_VALUE(   390.00), SIMDE_BFLOAT16_VALUE(   -49.25), SIMDE_BFLOAT16_VALUE(   972.00), SIMDE_BFLOAT16_VALUE(   880.00),
        SIMDE_BFLOAT16_VALUE(   464.00), SIMDE_BFLOAT16_VALUE(   496.00), SIMDE_BFLOAT16_VALUE(  -576.00), SIMDE_BFLOAT16_VALUE(  -524.00) },
      { SIMDE_BFLOAT16_VALUE(  -524.00), SIMDE_BFLOAT16_VALUE(   676.00), SIMDE_BFLOAT16_VALUE(   888.00), SIMDE_BFLOAT16_VALUE(  -916.00),
        SIMDE_BFLOAT16_VALUE(   720.00), SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(   544.00), SIMDE_BFLOAT16_VALUE(  -984.00) },
      { SIMDE_BFLOAT16_VALUE(   460.00), SIMDE_BFLOAT16_VALUE(  -576.00), SIMDE_BFLOAT16_VALUE(   888.00), SIMDE_BFLOAT16_VALUE(  -916.00),
        SIMDE_BFLOAT16_VALUE(   720.00), SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(   544.00), SIMDE_BFLOAT16_VALUE(  -984.00) },
      { SIMDE_BFLOAT16_VALUE(   460.00), SIMDE_BFLOAT16_VALUE(   676.00), SIMDE_BFLOAT16_VALUE(   888.00), SIMDE_BFLOAT16_VALUE(   464.00),
        SIMDE_BFLOAT16_VALUE(   720.00), SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(   544.00), SIMDE_BFLOAT16_VALUE(  -984.00) },
      { SIMDE_BFLOAT16_VALUE(   460.00), SIMDE_BFLOAT16_VALUE(   676.00), SIMDE_BFLOAT16_VALUE(   888.00), SIMDE_BFLOAT16_VALUE(  -916.00),
        SIMDE_BFLOAT16_VALUE(   720.00), SIMDE_BFLOAT16_VALUE(   880.00), SIMDE_BFLOAT16_VALUE(   544.00), SIMDE_BFLOAT16_VALUE(  -984.00) },
      { SIMDE_BFLOAT16_VALUE(   460.00), SIMDE_BFLOAT16_VALUE(   676.00), SIMDE_BFLOAT16_VALUE(   888.00), SIMDE_BFLOAT16_VALUE(  -916.00),
        SIMDE_BFLOAT16_VALUE(   720.00), SIMDE_BFLOAT16_VALUE(  -908.00), SIMDE_BFLOAT16_VALUE(   544.00), SIMDE_BFLOAT16_VALUE(   -49.25) } },
    { { SIMDE_BFLOAT16_VALUE(  -956.00), SIMDE_BFLOAT16_VALUE(    33.75), SIMDE_BFLOAT16_VALUE(    96.00), SIMDE_BFLOAT16_VALUE(   960.00),
        SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(   724.00), SIMDE_BFLOAT16_VALUE(   101.50), SIMDE_BFLOAT16_VALUE(  -684.00) },
      { SIMDE_BFLOAT16_VALUE(   876.00), SIMDE_BFLOAT16_VALUE(   -36.50), SIMDE_BFLOAT16_VALUE(  -720.00), SIMDE_BFLOAT16_VALUE(   216.00),
        SIMDE_BFLOAT16_VALUE(  -644.00), SIMDE_BFLOAT16_VALUE(   840.00), SIMDE_BFLOAT16_VALUE(   640.00), SIMDE_BFLOAT16_VALUE(   812.00) },
      { SIMDE_BFLOAT16_VALUE(   812.00), SIMDE_BFLOAT16_VALUE(    33.75), SIMDE_BFLOAT16_VALUE(    96.00), SIMDE_BFLOAT16_VALUE(   960.00),
        SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(   724.00), SIMDE_BFLOAT16_VALUE(   101.50), SIMDE_BFLOAT16_VALUE(  -684.00) },
      { SIMDE_BFLOAT16_VALUE(  -956.00), SIMDE_BFLOAT16_VALUE(   640.00), SIMDE_BFLOAT16_VALUE(    96.00), SIMDE_BFLOAT16_VALUE(   960.00),
        SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(   724.00), SIMDE_BFLOAT16_VALUE(   101.50), SIMDE_BFLOAT16_VALUE(  -684.00) },
      { SIMDE_BFLOAT16_VALUE(  -956.00), SIMDE_BFLOAT16_VALUE(    33.75), SIMDE_BFLOAT16_VALUE(    96.00), SIMDE_BFLOAT16_VALUE(  -644.00),
        SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(   724.00), SIMDE_BFLOAT16_VALUE(   101.50), SIMDE_BFLOAT16_VALUE(  -684.00) },
      { SIMDE_BFLOAT16_VALUE(  -956.00), SIMDE_BFLOAT16_VALUE(    33.75), SIMDE_BFLOAT16_VALUE(    96.00), SIMDE_BFLOAT16_VALUE(   960.00),
        SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(   216.00), SIMDE_BFLOAT16_VALUE(   101.50), SIMDE_BFLOAT16_VALUE(  -684.00) },
      { SIMDE_BFLOAT16_VALUE(  -956.00), SIMDE_BFLOAT16_VALUE(    33.75), SIMDE_BFLOAT16_VALUE(    96.00), SIMDE_BFLOAT16_VALUE(   960.00),
        SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(   724.00), SIMDE_BFLOAT16_VALUE(   101.50), SIMDE_BFLOAT16_VALUE(   -36.50) } },
    { { SIMDE_BFLOAT16_VALUE(   516.00), SIMDE_BFLOAT16_VALUE(   528.00), SIMDE_BFLOAT16_VALUE(   892.00), SIMDE_BFLOAT16_VALUE(   240.00),
        SIMDE_BFLOAT16_VALUE(   620.00), SIMDE_BFLOAT16_VALUE(   442.00), SIMDE_BFLOAT16_VALUE(   252.00), SIMDE_BFLOAT16_VALUE(    13.44) },
      { SIMDE_BFLOAT16_VALUE(  -604.00), SIMDE_BFLOAT16_VALUE(   226.00), SIMDE_BFLOAT16_VALUE(  -106.00), SIMDE_BFLOAT16_VALUE(   856.00),
        SIMDE_BFLOAT16_VALUE(  -276.00), SIMDE_BFLOAT16_VALUE(   316.00), SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(  -233.00) },
      { SIMDE_BFLOAT16_VALUE(  -233.00), SIMDE_BFLOAT16_VALUE(   528.00), SIMDE_BFLOAT16_VALUE(   892.00), SIMDE_BFLOAT16_VALUE(   240.00),
        SIMDE_BFLOAT16_VALUE(   620.00), SIMDE_BFLOAT16_VALUE(   442.00), SIMDE_BFLOAT16_VALUE(   252.00), SIMDE_BFLOAT16_VALUE(    13.44) },
      { SIMDE_BFLOAT16_VALUE(   516.00), SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(   892.00), SIMDE_BFLOAT16_VALUE(   240.00),
        SIMDE_BFLOAT16_VALUE(   620.00), SIMDE_BFLOAT16_VALUE(   442.00), SIMDE_BFLOAT16_VALUE(   252.00), SIMDE_BFLOAT16_VALUE(    13.44) },
      { SIMDE_BFLOAT16_VALUE(   516.00), SIMDE_BFLOAT16_VALUE(   528.00), SIMDE_BFLOAT16_VALUE(   892.00), SIMDE_BFLOAT16_VALUE(  -276.00),
        SIMDE_BFLOAT16_VALUE(   620.00), SIMDE_BFLOAT16_VALUE(   442.00), SIMDE_BFLOAT16_VALUE(   252.00), SIMDE_BFLOAT16_VALUE(    13.44) },
      { SIMDE_BFLOAT16_VALUE(   516.00), SIMDE_BFLOAT16_VALUE(   528.00), SIMDE_BFLOAT16_VALUE(   892.00), SIMDE_BFLOAT16_VALUE(   240.00),
        SIMDE_BFLOAT16_VALUE(   620.00), SIMDE_BFLOAT16_VALUE(   856.00), SIMDE_BFLOAT16_VALUE(   252.00), SIMDE_BFLOAT16_VALUE(    13.44) },
      { SIMDE_BFLOAT16_VALUE(   516.00), SIMDE_BFLOAT16_VALUE(   528.00), SIMDE_BFLOAT16_VALUE(   892.00), SIMDE_BFLOAT16_VALUE(   240.00),
        SIMDE_BFLOAT16_VALUE(   620.00), SIMDE_BFLOAT16_VALUE(   442.00), SIMDE_BFLOAT16_VALUE(   252.00), SIMDE_BFLOAT16_VALUE(   226.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t a = simde_vld1q_bf16(test_vec[i].a);
    simde_bfloat16x8_t b = simde_vld1q_bf16(test_vec[i].b);

    simde_bfloat16x8_t r0_7 = simde_vcopyq_laneq_bf16(a, 0, b, 7);
    simde_bfloat16x8_t r1_6 = simde_vcopyq_laneq_bf16(a, 1, b, 6);
    simde_bfloat16x8_t r3_4 = simde_vcopyq_laneq_bf16(a, 3, b, 4);
    simde_bfloat16x8_t r5_3 = simde_vcopyq_laneq_bf16(a, 5, b, 3);
    simde_bfloat16x8_t r7_1 = simde_vcopyq_laneq_bf16(a, 7, b, 1);

    simde_test_arm_neon_assert_equal_bf16x8(r0_7, simde_vld1q_bf16(test_vec[i].r0_7), 1);
    simde_test_arm_neon_assert_equal_bf16x8(r1_6, simde_vld1q_bf16(test_vec[i].r1_6), 1);
    simde_test_arm_neon_assert_equal_bf16x8(r3_4, simde_vld1q_bf16(test_vec[i].r3_4), 1);
    simde_test_arm_neon_assert_equal_bf16x8(r5_3, simde_vld1q_bf16(test_vec[i].r5_3), 1);
    simde_test_arm_neon_assert_equal_bf16x8(r7_1, simde_vld1q_bf16(test_vec[i].r7_1), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x8_t a = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_bfloat16x8_t b = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_bfloat16x8_t r0_7 = simde_vcopyq_laneq_bf16(a, 0, b, 7);
    simde_bfloat16x8_t r1_6 = simde_vcopyq_laneq_bf16(a, 1, b, 6);
    simde_bfloat16x8_t r3_4 = simde_vcopyq_laneq_bf16(a, 3, b, 4);
    simde_bfloat16x8_t r5_3 = simde_vcopyq_laneq_bf16(a, 5, b, 3);
    simde_bfloat16x8_t r7_1 = simde_vcopyq_laneq_bf16(a, 7, b, 1);

    simde_test_arm_neon_write_bf16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r0_7, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r1_6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r3_4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r5_3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r7_1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopy_laneq_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcopyq_laneq_bf16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
