
#define SIMDE_TEST_ARM_NEON_INSN mls_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mls_lane.h"

SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vmls_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[2];
    float b[2];
    float v[4];
    int8_t lane;
    float r[2];
  } test_vec[] = {
     { {   SIMDE_FLOAT32_C(  9460.10),  SIMDE_FLOAT32_C(  5133.15) },
       {   SIMDE_FLOAT32_C(   -46.94),  SIMDE_FLOAT32_C(     4.95) },
       {   SIMDE_FLOAT32_C(   -21.21),  SIMDE_FLOAT32_C(    95.76),  SIMDE_FLOAT32_C(   -75.66),  SIMDE_FLOAT32_C(    96.16)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C( 13955.07),  SIMDE_FLOAT32_C(  4659.14) } },
     { {   SIMDE_FLOAT32_C( -8475.37),  SIMDE_FLOAT32_C( -3344.46) },
       {   SIMDE_FLOAT32_C(   -71.00),  SIMDE_FLOAT32_C(   -74.43) },
       {   SIMDE_FLOAT32_C(   -44.49),  SIMDE_FLOAT32_C(    66.28),  SIMDE_FLOAT32_C(    82.23),  SIMDE_FLOAT32_C(   -29.17)},
           INT8_C(        3),
       {   SIMDE_FLOAT32_C(-10546.44),  SIMDE_FLOAT32_C( -5515.58) } },
     { {   SIMDE_FLOAT32_C( -8051.58),  SIMDE_FLOAT32_C( -6624.70) },
       {   SIMDE_FLOAT32_C(   -68.31),  SIMDE_FLOAT32_C(   -59.05) },
       {   SIMDE_FLOAT32_C(   -78.34),  SIMDE_FLOAT32_C(    64.95),  SIMDE_FLOAT32_C(    85.49),  SIMDE_FLOAT32_C(    74.16)},
           INT8_C(        2),
       {   SIMDE_FLOAT32_C( -2211.76),  SIMDE_FLOAT32_C( -1576.52) } },
     { {   SIMDE_FLOAT32_C( -6072.32),  SIMDE_FLOAT32_C( -9665.18) },
       {   SIMDE_FLOAT32_C(   -88.69),  SIMDE_FLOAT32_C(   -11.61) },
       {   SIMDE_FLOAT32_C(    63.00),  SIMDE_FLOAT32_C(    42.22),  SIMDE_FLOAT32_C(   -34.75),  SIMDE_FLOAT32_C(   -58.12)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(  -484.85),  SIMDE_FLOAT32_C( -8933.75) } },
     { {   SIMDE_FLOAT32_C( -5844.94),  SIMDE_FLOAT32_C(  1706.98) },
       {   SIMDE_FLOAT32_C(   -47.12),  SIMDE_FLOAT32_C(   -45.01) },
       {   SIMDE_FLOAT32_C(   -17.06),  SIMDE_FLOAT32_C(   -90.29),  SIMDE_FLOAT32_C(    67.45),  SIMDE_FLOAT32_C(   -45.84)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C( -6648.81),  SIMDE_FLOAT32_C(   939.11) } },
     { {   SIMDE_FLOAT32_C(  7278.68),  SIMDE_FLOAT32_C( -9305.98) },
       {   SIMDE_FLOAT32_C(    19.76),  SIMDE_FLOAT32_C(    52.33) },
       {   SIMDE_FLOAT32_C(   -81.30),  SIMDE_FLOAT32_C(   -80.15),  SIMDE_FLOAT32_C(   -15.48),  SIMDE_FLOAT32_C(   -31.32)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(  8862.44),  SIMDE_FLOAT32_C( -5111.73) } },
     { {   SIMDE_FLOAT32_C(  4924.02),  SIMDE_FLOAT32_C(  6091.74) },
       {   SIMDE_FLOAT32_C(   -73.42),  SIMDE_FLOAT32_C(    -6.69) },
       {   SIMDE_FLOAT32_C(   -55.97),  SIMDE_FLOAT32_C(   -71.24),  SIMDE_FLOAT32_C(    21.51),  SIMDE_FLOAT32_C(    23.98)},
           INT8_C(        2),
       {   SIMDE_FLOAT32_C(  6503.28),  SIMDE_FLOAT32_C(  6235.64) } },
     { {   SIMDE_FLOAT32_C(  2182.24),  SIMDE_FLOAT32_C(   505.13) },
       {   SIMDE_FLOAT32_C(    21.83),  SIMDE_FLOAT32_C(    45.14) },
       {   SIMDE_FLOAT32_C(   -73.69),  SIMDE_FLOAT32_C(    63.75),  SIMDE_FLOAT32_C(   -10.02),  SIMDE_FLOAT32_C(    25.19)},
           INT8_C(        3),
       {   SIMDE_FLOAT32_C(  1632.34),  SIMDE_FLOAT32_C(  -631.95) } },
  };

  simde_float32x2_t r, a, b;
  simde_float32x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    v = simde_vld1q_f32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_laneq_f32(a, b, v, 0); break;
      case 1: r = simde_vmls_laneq_f32(a, b, v, 1); break;
      case 2: r = simde_vmls_laneq_f32(a, b, v, 2); break;
      case 3: r = simde_vmls_laneq_f32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_f32(0); break;
    }
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmls_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[2];
    float b[2];
    float v[2];
    int8_t lane;
    float r[2];
  } test_vec[] = {
     { {   SIMDE_FLOAT32_C( -6873.77),  SIMDE_FLOAT32_C(  9485.11) },
       {   SIMDE_FLOAT32_C(   -68.87),  SIMDE_FLOAT32_C(    98.20) },
       {   SIMDE_FLOAT32_C(   -95.02),  SIMDE_FLOAT32_C(   -15.71)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(-13417.80),  SIMDE_FLOAT32_C( 18816.07) } },
     { {   SIMDE_FLOAT32_C( -3003.07),  SIMDE_FLOAT32_C( -8337.70) },
       {   SIMDE_FLOAT32_C(    29.64),  SIMDE_FLOAT32_C(   -12.68) },
       {   SIMDE_FLOAT32_C(   -97.40),  SIMDE_FLOAT32_C(    90.45)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(  -116.13),  SIMDE_FLOAT32_C( -9572.73) } },
     { {   SIMDE_FLOAT32_C(  3537.35),  SIMDE_FLOAT32_C(  9430.40) },
       {   SIMDE_FLOAT32_C(   -83.99),  SIMDE_FLOAT32_C(    -6.05) },
       {   SIMDE_FLOAT32_C(    -3.56),  SIMDE_FLOAT32_C(    92.42)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(  3238.35),  SIMDE_FLOAT32_C(  9408.86) } },
     { {   SIMDE_FLOAT32_C( -3238.57),  SIMDE_FLOAT32_C( -2004.28) },
       {   SIMDE_FLOAT32_C(   -50.70),  SIMDE_FLOAT32_C(   -54.85) },
       {   SIMDE_FLOAT32_C(   -98.12),  SIMDE_FLOAT32_C(    59.24)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(  -235.10),  SIMDE_FLOAT32_C(  1245.03) } },
     { {   SIMDE_FLOAT32_C(  6692.30),  SIMDE_FLOAT32_C( -8729.98) },
       {   SIMDE_FLOAT32_C(    83.68),  SIMDE_FLOAT32_C(   -94.71) },
       {   SIMDE_FLOAT32_C(    87.24),  SIMDE_FLOAT32_C(    45.14)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(  -607.94),  SIMDE_FLOAT32_C(  -467.48) } },
     { {   SIMDE_FLOAT32_C(  2413.77),  SIMDE_FLOAT32_C(    85.79) },
       {   SIMDE_FLOAT32_C(     6.51),  SIMDE_FLOAT32_C(   -90.46) },
       {   SIMDE_FLOAT32_C(   -21.94),  SIMDE_FLOAT32_C(    17.07)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(  2302.64),  SIMDE_FLOAT32_C(  1629.94) } },
     { {   SIMDE_FLOAT32_C(  6994.38),  SIMDE_FLOAT32_C(  2861.74) },
       {   SIMDE_FLOAT32_C(   -90.54),  SIMDE_FLOAT32_C(    96.29) },
       {   SIMDE_FLOAT32_C(    66.85),  SIMDE_FLOAT32_C(    12.04)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(  8084.48),  SIMDE_FLOAT32_C(  1702.41) } },
     { {   SIMDE_FLOAT32_C(  1324.60),  SIMDE_FLOAT32_C( -6880.65) },
       {   SIMDE_FLOAT32_C(   -88.42),  SIMDE_FLOAT32_C(   -18.72) },
       {   SIMDE_FLOAT32_C(    17.66),  SIMDE_FLOAT32_C(    68.18)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(  7353.08),  SIMDE_FLOAT32_C( -5604.32) } },
  };

  simde_float32x2_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    v = simde_vld1_f32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_lane_f32(a, b, v, 0); break;
      case 1: r = simde_vmls_lane_f32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_f32(0); break;
    }
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}
static int
test_simde_vmls_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t v[8];
    int8_t lane;
    int16_t r[4];
  } test_vec[] = {
     { {  -INT16_C(  7117),  INT16_C(  1424), -INT16_C(  7491), -INT16_C(  9317) },
       {   INT16_C(    51),  INT16_C(    91),  INT16_C(    74), -INT16_C(    35) },
       {  -INT16_C(    46), -INT16_C(    56), -INT16_C(     9), -INT16_C(    93),
           INT16_C(    96), -INT16_C(    68), -INT16_C(    96),  INT16_C(     0)},
           INT8_C(     2),
       {  -INT16_C(  6658),  INT16_C(  2243), -INT16_C(  6825), -INT16_C(  9632) } },
     { {  -INT16_C(  8618),  INT16_C(  2840), -INT16_C(  6126),  INT16_C(  6799) },
       {  -INT16_C(    69), -INT16_C(    94), -INT16_C(    40),  INT16_C(    44) },
       {   INT16_C(    46), -INT16_C(    35), -INT16_C(    50),  INT16_C(    50),
          -INT16_C(    19), -INT16_C(    90),  INT16_C(    49),  INT16_C(    17)},
           INT8_C(     7),
       {  -INT16_C(  7445),  INT16_C(  4438), -INT16_C(  5446),  INT16_C(  6051) } },
     { {   INT16_C(  9015), -INT16_C(  4740), -INT16_C(  4394),  INT16_C(  9290) },
       {  -INT16_C(    31),  INT16_C(    21),  INT16_C(    66),  INT16_C(    70) },
       {   INT16_C(    18), -INT16_C(    52),  INT16_C(    77), -INT16_C(    18),
           INT16_C(    68), -INT16_C(    92), -INT16_C(     9),  INT16_C(    44)},
           INT8_C(     1),
       {   INT16_C(  7403), -INT16_C(  3648), -INT16_C(   962),  INT16_C( 12930) } },
     { {   INT16_C(  4745), -INT16_C(  5011),  INT16_C(  2800), -INT16_C(  7710) },
       {  -INT16_C(    79), -INT16_C(    98),  INT16_C(    38), -INT16_C(    75) },
       {  -INT16_C(    64), -INT16_C(    52),  INT16_C(    30), -INT16_C(    33),
          -INT16_C(    34), -INT16_C(    35), -INT16_C(    89), -INT16_C(    78)},
           INT8_C(     4),
       {   INT16_C(  2059), -INT16_C(  8343),  INT16_C(  4092), -INT16_C( 10260) } },
     { {  -INT16_C(  3099),  INT16_C(   818), -INT16_C(  6722), -INT16_C(  7942) },
       {  -INT16_C(     7),  INT16_C(    84), -INT16_C(    96),  INT16_C(    29) },
       {  -INT16_C(    19),  INT16_C(    18),  INT16_C(     8),  INT16_C(    36),
           INT16_C(    98), -INT16_C(     4), -INT16_C(    85), -INT16_C(    21)},
           INT8_C(     2),
       {  -INT16_C(  3043),  INT16_C(   146), -INT16_C(  5954), -INT16_C(  8174) } },
     { {   INT16_C(    85),  INT16_C(  1723),  INT16_C(  9151), -INT16_C(  8826) },
       {  -INT16_C(     9),  INT16_C(    31),  INT16_C(    59), -INT16_C(    41) },
       {  -INT16_C(    10), -INT16_C(     9), -INT16_C(    30), -INT16_C(    22),
           INT16_C(    78), -INT16_C(    57), -INT16_C(    52), -INT16_C(    20)},
           INT8_C(     2),
       {  -INT16_C(   185),  INT16_C(  2653),  INT16_C( 10921), -INT16_C( 10056) } },
     { {  -INT16_C(  1161), -INT16_C(  7530),  INT16_C(  9859),  INT16_C(  9165) },
       {  -INT16_C(     1),  INT16_C(    66), -INT16_C(    95),  INT16_C(    93) },
       {  -INT16_C(    46),  INT16_C(    73), -INT16_C(    24),  INT16_C(    69),
           INT16_C(    73), -INT16_C(    76), -INT16_C(    99), -INT16_C(    72)},
           INT8_C(     1),
       {  -INT16_C(  1088), -INT16_C( 12348),  INT16_C( 16794),  INT16_C(  2376) } },
     { {  -INT16_C(  4474),  INT16_C(  3652), -INT16_C(    45),  INT16_C(  9361) },
       {  -INT16_C(    70),  INT16_C(    30), -INT16_C(    58),  INT16_C(    85) },
       {  -INT16_C(    88),  INT16_C(    27), -INT16_C(    27), -INT16_C(    85),
           INT16_C(    57),  INT16_C(    70), -INT16_C(     5),  INT16_C(    95)},
           INT8_C(     4),
       {  -INT16_C(   484),  INT16_C(  1942),  INT16_C(  3261),  INT16_C(  4516) } },
  };

  simde_int16x4_t r, a, b;
  simde_int16x8_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_s16(test_vec[i].a);
    b = simde_vld1_s16(test_vec[i].b);
    v = simde_vld1q_s16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vmls_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vmls_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vmls_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vmls_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vmls_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vmls_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vmls_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_s16(0); break;
    }
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmls_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t v[4];
    int8_t lane;
    int16_t r[4];
  } test_vec[] = {
     { {  -INT16_C(   844),  INT16_C(  1656), -INT16_C(  9225), -INT16_C(  3760) },
       {  -INT16_C(    57),  INT16_C(    21), -INT16_C(    70), -INT16_C(    44) },
       {  -INT16_C(    54),  INT16_C(    72), -INT16_C(    79),  INT16_C(    91)},
           INT8_C(     1),
       {   INT16_C(  3260),  INT16_C(   144), -INT16_C(  4185), -INT16_C(   592) } },
     { {  -INT16_C(  1909),  INT16_C(  5115), -INT16_C(  6686), -INT16_C(  1069) },
       {   INT16_C(    17),  INT16_C(    25),  INT16_C(    75),  INT16_C(    85) },
       {   INT16_C(     5), -INT16_C(    78),  INT16_C(    60), -INT16_C(     8)},
           INT8_C(     0),
       {  -INT16_C(  1994),  INT16_C(  4990), -INT16_C(  7061), -INT16_C(  1494) } },
     { {  -INT16_C(  4046), -INT16_C(  8146),  INT16_C(   505), -INT16_C(  1341) },
       {  -INT16_C(    12), -INT16_C(     5), -INT16_C(    28),  INT16_C(    29) },
       {  -INT16_C(    14),  INT16_C(    78), -INT16_C(    52),  INT16_C(     0)},
           INT8_C(     3),
       {  -INT16_C(  4046), -INT16_C(  8146),  INT16_C(   505), -INT16_C(  1341) } },
     { {  -INT16_C(  5833),  INT16_C(   786),  INT16_C(  5359), -INT16_C(  1361) },
       {  -INT16_C(    50), -INT16_C(    63), -INT16_C(    97), -INT16_C(    88) },
       {   INT16_C(    22), -INT16_C(     1),  INT16_C(    78), -INT16_C(    70)},
           INT8_C(     0),
       {  -INT16_C(  4733),  INT16_C(  2172),  INT16_C(  7493),  INT16_C(   575) } },
     { {  -INT16_C(   758),  INT16_C(  1090),  INT16_C(  4857),  INT16_C(  3860) },
       {   INT16_C(    65),  INT16_C(    86),  INT16_C(    64),  INT16_C(    48) },
       {  -INT16_C(    80), -INT16_C(    18),  INT16_C(    76),  INT16_C(    96)},
           INT8_C(     2),
       {  -INT16_C(  5698), -INT16_C(  5446), -INT16_C(     7),  INT16_C(   212) } },
     { {  -INT16_C(  4433), -INT16_C(  7839),  INT16_C(  4286), -INT16_C(  3346) },
       {   INT16_C(    72),  INT16_C(    88),  INT16_C(    99), -INT16_C(    11) },
       {  -INT16_C(     2), -INT16_C(    18), -INT16_C(    51),  INT16_C(    34)},
           INT8_C(     0),
       {  -INT16_C(  4289), -INT16_C(  7663),  INT16_C(  4484), -INT16_C(  3368) } },
     { {   INT16_C(   537),  INT16_C(   902),  INT16_C(  7163), -INT16_C(  6624) },
       {  -INT16_C(    69), -INT16_C(    24), -INT16_C(    65),  INT16_C(    18) },
       {  -INT16_C(    38), -INT16_C(    98), -INT16_C(     5),  INT16_C(    31)},
           INT8_C(     2),
       {   INT16_C(   192),  INT16_C(   782),  INT16_C(  6838), -INT16_C(  6534) } },
     { {  -INT16_C(  7137),  INT16_C(  4022), -INT16_C(  7194), -INT16_C(  5087) },
       {  -INT16_C(    96), -INT16_C(    10),  INT16_C(    36),  INT16_C(    26) },
       {   INT16_C(    39), -INT16_C(    28), -INT16_C(    28),  INT16_C(    24)},
           INT8_C(     3),
       {  -INT16_C(  4833),  INT16_C(  4262), -INT16_C(  8058), -INT16_C(  5711) } },
  };

  simde_int16x4_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_s16(test_vec[i].a);
    b = simde_vld1_s16(test_vec[i].b);
    v = simde_vld1_s16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vmls_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vmls_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vmls_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_s16(0); break;
    }
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmls_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t v[4];
    int8_t lane;
    int32_t r[2];
  } test_vec[] = {
     { {  -INT32_C(   4609779), -INT32_C(   6446057) },
       {  -INT32_C(        30),  INT32_C(      9280) },
       {  -INT32_C(      6491), -INT32_C(      7148), -INT32_C(      1963), -INT32_C(      7675)},
           INT8_C(         1),
       {  -INT32_C(   4824219),  INT32_C(  59887383) } },
     { {   INT32_C(   8476789),  INT32_C(   9001967) },
       {   INT32_C(      8417),  INT32_C(      9240) },
       {   INT32_C(      7274), -INT32_C(      7072),  INT32_C(      8316),  INT32_C(      1349)},
           INT8_C(         0),
       {  -INT32_C(  52748469), -INT32_C(  58209793) } },
     { {  -INT32_C(   5257596), -INT32_C(   5794779) },
       {   INT32_C(      5556), -INT32_C(      6177) },
       {   INT32_C(      5916), -INT32_C(      4267), -INT32_C(      3838), -INT32_C(      6943)},
           INT8_C(         3),
       {   INT32_C(  33317712), -INT32_C(  48681690) } },
     { {  -INT32_C(   2819565), -INT32_C(   3360540) },
       {  -INT32_C(      4591), -INT32_C(      8694) },
       {  -INT32_C(      2105),  INT32_C(      9150), -INT32_C(      1627), -INT32_C(      4269)},
           INT8_C(         2),
       {  -INT32_C(  10289122), -INT32_C(  17505678) } },
     { {  -INT32_C(   1360462),  INT32_C(   1237828) },
       {   INT32_C(      4841),  INT32_C(      5659) },
       {   INT32_C(      7557),  INT32_C(      8904), -INT32_C(      6536),  INT32_C(      2682)},
           INT8_C(         3),
       {  -INT32_C(  14344024), -INT32_C(  13939610) } },
     { {  -INT32_C(   6369807),  INT32_C(   3325182) },
       {   INT32_C(      5679),  INT32_C(      3989) },
       {   INT32_C(      6822), -INT32_C(      2039),  INT32_C(      6158), -INT32_C(      8783)},
           INT8_C(         0),
       {  -INT32_C(  45111945), -INT32_C(  23887776) } },
     { {   INT32_C(   3683666), -INT32_C(   2734501) },
       {   INT32_C(      2272), -INT32_C(      8611) },
       {  -INT32_C(      9339),  INT32_C(      7011),  INT32_C(        13), -INT32_C(      5892)},
           INT8_C(         0),
       {   INT32_C(  24901874), -INT32_C(  83152630) } },
     { {   INT32_C(   5399057), -INT32_C(   5721902) },
       {   INT32_C(      9872), -INT32_C(      9010) },
       {  -INT32_C(      6643),  INT32_C(      1460), -INT32_C(      1642), -INT32_C(      1245)},
           INT8_C(         3),
       {   INT32_C(  17689697), -INT32_C(  16939352) } },
  };

  simde_int32x2_t r, a, b;
  simde_int32x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_s32(test_vec[i].a);
    b = simde_vld1_s32(test_vec[i].b);
    v = simde_vld1q_s32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vmls_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vmls_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vmls_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_s32(0); break;
    }
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmls_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t v[2];
    int8_t lane;
    int32_t r[2];
  } test_vec[] = {
     { {  -INT32_C(   2080167),  INT32_C(   2975351) },
       {   INT32_C(      3022),  INT32_C(      7220) },
       {   INT32_C(      3092),  INT32_C(      9706)},
           INT8_C(         0),
       {  -INT32_C(  11424191), -INT32_C(  19348889) } },
     { {  -INT32_C(    465851),  INT32_C(    658061) },
       {   INT32_C(      4649),  INT32_C(      1947) },
       {   INT32_C(      2147), -INT32_C(      6341)},
           INT8_C(         1),
       {   INT32_C(  29013458),  INT32_C(  13003988) } },
     { {   INT32_C(   1705178), -INT32_C(   2538948) },
       {  -INT32_C(      9658), -INT32_C(      1207) },
       {   INT32_C(      7192),  INT32_C(      3209)},
           INT8_C(         0),
       {   INT32_C(  71165514),  INT32_C(   6141796) } },
     { {  -INT32_C(   8958043),  INT32_C(   3475949) },
       {   INT32_C(      2014),  INT32_C(      3915) },
       {   INT32_C(      6642),  INT32_C(      3411)},
           INT8_C(         1),
       {  -INT32_C(  15827797), -INT32_C(   9878116) } },
     { {  -INT32_C(   1876829),  INT32_C(   3712281) },
       {  -INT32_C(      1337),  INT32_C(      9030) },
       {  -INT32_C(      9018), -INT32_C(       310)},
           INT8_C(         1),
       {  -INT32_C(   2291299),  INT32_C(   6511581) } },
     { {   INT32_C(   4168416), -INT32_C(   4475757) },
       {  -INT32_C(      2360),  INT32_C(      7459) },
       {  -INT32_C(      1695), -INT32_C(      4793)},
           INT8_C(         0),
       {   INT32_C(    168216),  INT32_C(   8167248) } },
     { {  -INT32_C(    690697), -INT32_C(   2328289) },
       {   INT32_C(      2952),  INT32_C(      9586) },
       {  -INT32_C(      6161), -INT32_C(      2789)},
           INT8_C(         1),
       {   INT32_C(   7542431),  INT32_C(  24407065) } },
     { {  -INT32_C(   4863001),  INT32_C(   1998250) },
       {  -INT32_C(      9095),  INT32_C(      3603) },
       {  -INT32_C(       126), -INT32_C(      9930)},
           INT8_C(         1),
       {  -INT32_C(  95176351),  INT32_C(  37776040) } },
  };

  simde_int32x2_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_s32(test_vec[i].a);
    b = simde_vld1_s32(test_vec[i].b);
    v = simde_vld1_s32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vmls_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_s32(0); break;
    }
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmls_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t v[8];
    int8_t lane;
    uint16_t r[4];
  } test_vec[] = {
     { {   UINT16_C( 16158),  UINT16_C(  1489),  UINT16_C(  1476),  UINT16_C(  1624) },
       {   UINT16_C(   190),  UINT16_C(    62),  UINT16_C(    32),  UINT16_C(   196) },
       {   UINT16_C(     3),  UINT16_C(   178),  UINT16_C(    81),  UINT16_C(   183),
           UINT16_C(    15),  UINT16_C(   169),  UINT16_C(   179),  UINT16_C(     6)},
           INT8_C(     1),
       {   UINT16_C( 47874),  UINT16_C( 55989),  UINT16_C( 61316),  UINT16_C( 32272) } },
     { {   UINT16_C(  3456),  UINT16_C( 18454),  UINT16_C( 16619),  UINT16_C( 18609) },
       {   UINT16_C(    78),  UINT16_C(    11),  UINT16_C(    32),  UINT16_C(   169) },
       {   UINT16_C(    78),  UINT16_C(   190),  UINT16_C(    83),  UINT16_C(   108),
           UINT16_C(   165),  UINT16_C(     8),  UINT16_C(   139),  UINT16_C(    15)},
           INT8_C(     4),
       {   UINT16_C( 56122),  UINT16_C( 16639),  UINT16_C( 11339),  UINT16_C( 56260) } },
     { {   UINT16_C( 16140),  UINT16_C(  1449),  UINT16_C(  7340),  UINT16_C(  4164) },
       {   UINT16_C(   135),  UINT16_C(    18),  UINT16_C(   102),  UINT16_C(   163) },
       {   UINT16_C(   122),  UINT16_C(    63),  UINT16_C(    45),  UINT16_C(   138),
           UINT16_C(    90),  UINT16_C(   111),  UINT16_C(    13),  UINT16_C(     3)},
           INT8_C(     6),
       {   UINT16_C( 14385),  UINT16_C(  1215),  UINT16_C(  6014),  UINT16_C(  2045) } },
     { {   UINT16_C(  7749),  UINT16_C( 10798),  UINT16_C(  9859),  UINT16_C( 14909) },
       {   UINT16_C(   104),  UINT16_C(    76),  UINT16_C(   144),  UINT16_C(   139) },
       {   UINT16_C(   116),  UINT16_C(   190),  UINT16_C(   180),  UINT16_C(   132),
           UINT16_C(    45),  UINT16_C(    47),  UINT16_C(   132),  UINT16_C(    27)},
           INT8_C(     1),
       {   UINT16_C( 53525),  UINT16_C( 61894),  UINT16_C( 48035),  UINT16_C( 54035) } },
     { {   UINT16_C(   474),  UINT16_C(  4091),  UINT16_C( 10437),  UINT16_C(  2089) },
       {   UINT16_C(   172),  UINT16_C(    33),  UINT16_C(    87),  UINT16_C(    94) },
       {   UINT16_C(    18),  UINT16_C(   184),  UINT16_C(   158),  UINT16_C(     8),
           UINT16_C(    76),  UINT16_C(    22),  UINT16_C(    30),  UINT16_C(   122)},
           INT8_C(     3),
       {   UINT16_C( 64634),  UINT16_C(  3827),  UINT16_C(  9741),  UINT16_C(  1337) } },
     { {   UINT16_C( 13153),  UINT16_C( 16958),  UINT16_C(  1130),  UINT16_C(  7923) },
       {   UINT16_C(   121),  UINT16_C(    21),  UINT16_C(   123),  UINT16_C(     2) },
       {   UINT16_C(   131),  UINT16_C(     3),  UINT16_C(    71),  UINT16_C(    42),
           UINT16_C(   120),  UINT16_C(   190),  UINT16_C(     1),  UINT16_C(   121)},
           INT8_C(     3),
       {   UINT16_C(  8071),  UINT16_C( 16076),  UINT16_C( 61500),  UINT16_C(  7839) } },
     { {   UINT16_C( 15740),  UINT16_C( 12791),  UINT16_C( 14506),  UINT16_C(  5419) },
       {   UINT16_C(    61),  UINT16_C(   152),  UINT16_C(   123),  UINT16_C(   118) },
       {   UINT16_C(   104),  UINT16_C(   148),  UINT16_C(   151),  UINT16_C(   186),
           UINT16_C(   115),  UINT16_C(     9),  UINT16_C(    77),  UINT16_C(    27)},
           INT8_C(     2),
       {   UINT16_C(  6529),  UINT16_C( 55375),  UINT16_C( 61469),  UINT16_C( 53137) } },
     { {   UINT16_C(  1816),  UINT16_C( 10121),  UINT16_C(  4977),  UINT16_C(  7363) },
       {   UINT16_C(     6),  UINT16_C(   164),  UINT16_C(    12),  UINT16_C(    16) },
       {   UINT16_C(   146),  UINT16_C(   161),  UINT16_C(   162),  UINT16_C(    50),
           UINT16_C(    26),  UINT16_C(    54),  UINT16_C(   195),  UINT16_C(   165)},
           INT8_C(     4),
       {   UINT16_C(  1660),  UINT16_C(  5857),  UINT16_C(  4665),  UINT16_C(  6947) } },
  };

  simde_uint16x4_t r, a, b;
  simde_uint16x8_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_u16(test_vec[i].a);
    b = simde_vld1_u16(test_vec[i].b);
    v = simde_vld1q_u16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_laneq_u16(a, b, v, 0); break;
      case 1: r = simde_vmls_laneq_u16(a, b, v, 1); break;
      case 2: r = simde_vmls_laneq_u16(a, b, v, 2); break;
      case 3: r = simde_vmls_laneq_u16(a, b, v, 3); break;
      case 4: r = simde_vmls_laneq_u16(a, b, v, 4); break;
      case 5: r = simde_vmls_laneq_u16(a, b, v, 5); break;
      case 6: r = simde_vmls_laneq_u16(a, b, v, 6); break;
      case 7: r = simde_vmls_laneq_u16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_u16(0); break;
    }
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmls_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t v[4];
    int8_t lane;
    uint16_t r[4];
  } test_vec[] = {
     { {   UINT16_C( 18984),  UINT16_C( 18009),  UINT16_C( 13809),  UINT16_C( 17765) },
       {   UINT16_C(   179),  UINT16_C(    96),  UINT16_C(   129),  UINT16_C(   114) },
       {   UINT16_C(    43),  UINT16_C(    86),  UINT16_C(   106),  UINT16_C(   167)},
           INT8_C(     0),
       {   UINT16_C( 11287),  UINT16_C( 13881),  UINT16_C(  8262),  UINT16_C( 12863) } },
     { {   UINT16_C( 12258),  UINT16_C(  4109),  UINT16_C(  6281),  UINT16_C( 16020) },
       {   UINT16_C(   100),  UINT16_C(   174),  UINT16_C(    26),  UINT16_C(    75) },
       {   UINT16_C(   193),  UINT16_C(    65),  UINT16_C(     7),  UINT16_C(   123)},
           INT8_C(     3),
       {   UINT16_C( 65494),  UINT16_C( 48243),  UINT16_C(  3083),  UINT16_C(  6795) } },
     { {   UINT16_C( 11938),  UINT16_C(  2513),  UINT16_C(  9492),  UINT16_C( 13021) },
       {   UINT16_C(    19),  UINT16_C(   119),  UINT16_C(    58),  UINT16_C(   146) },
       {   UINT16_C(   193),  UINT16_C(    73),  UINT16_C(   147),  UINT16_C(   109)},
           INT8_C(     0),
       {   UINT16_C(  8271),  UINT16_C( 45082),  UINT16_C( 63834),  UINT16_C( 50379) } },
     { {   UINT16_C(  3390),  UINT16_C(  3694),  UINT16_C( 13872),  UINT16_C( 10975) },
       {   UINT16_C(    92),  UINT16_C(    33),  UINT16_C(   159),  UINT16_C(   158) },
       {   UINT16_C(    61),  UINT16_C(   156),  UINT16_C(    44),  UINT16_C(    42)},
           INT8_C(     1),
       {   UINT16_C( 54574),  UINT16_C( 64082),  UINT16_C( 54604),  UINT16_C( 51863) } },
     { {   UINT16_C(  5809),  UINT16_C(  7103),  UINT16_C( 15284),  UINT16_C(  5993) },
       {   UINT16_C(   107),  UINT16_C(    47),  UINT16_C(    90),  UINT16_C(   189) },
       {   UINT16_C(    83),  UINT16_C(    43),  UINT16_C(   122),  UINT16_C(    58)},
           INT8_C(     3),
       {   UINT16_C( 65139),  UINT16_C(  4377),  UINT16_C( 10064),  UINT16_C( 60567) } },
     { {   UINT16_C(  9094),  UINT16_C(  2904),  UINT16_C( 17008),  UINT16_C(  2752) },
       {   UINT16_C(   147),  UINT16_C(   194),  UINT16_C(   149),  UINT16_C(    28) },
       {   UINT16_C(   157),  UINT16_C(   140),  UINT16_C(   104),  UINT16_C(    96)},
           INT8_C(     2),
       {   UINT16_C( 59342),  UINT16_C( 48264),  UINT16_C(  1512),  UINT16_C( 65376) } },
     { {   UINT16_C(  6469),  UINT16_C( 19343),  UINT16_C( 12256),  UINT16_C( 15543) },
       {   UINT16_C(   129),  UINT16_C(     0),  UINT16_C(    37),  UINT16_C(    78) },
       {   UINT16_C(   186),  UINT16_C(    42),  UINT16_C(   145),  UINT16_C(    31)},
           INT8_C(     3),
       {   UINT16_C(  2470),  UINT16_C( 19343),  UINT16_C( 11109),  UINT16_C( 13125) } },
     { {   UINT16_C( 14549),  UINT16_C(  4486),  UINT16_C( 13494),  UINT16_C(  5232) },
       {   UINT16_C(   144),  UINT16_C(    10),  UINT16_C(   198),  UINT16_C(   165) },
       {   UINT16_C(    28),  UINT16_C(    10),  UINT16_C(    42),  UINT16_C(    25)},
           INT8_C(     1),
       {   UINT16_C( 13109),  UINT16_C(  4386),  UINT16_C( 11514),  UINT16_C(  3582) } },
  };

  simde_uint16x4_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_u16(test_vec[i].a);
    b = simde_vld1_u16(test_vec[i].b);
    v = simde_vld1_u16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_lane_u16(a, b, v, 0); break;
      case 1: r = simde_vmls_lane_u16(a, b, v, 1); break;
      case 2: r = simde_vmls_lane_u16(a, b, v, 2); break;
      case 3: r = simde_vmls_lane_u16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_u16(0); break;
    }
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmls_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t v[4];
    int8_t lane;
    uint32_t r[2];
  } test_vec[] = {
     { {   UINT32_C(  14144199),  UINT32_C(  13604911) },
       {   UINT32_C(     12510),  UINT32_C(      6546) },
       {   UINT32_C(     15820),  UINT32_C(      9959),  UINT32_C(      2597),  UINT32_C(      2845)},
           INT8_C(         0),
       {   UINT32_C(4111203295),  UINT32_C(4205014487) } },
     { {   UINT32_C(   3498803),  UINT32_C(  10348791) },
       {   UINT32_C(      6329),  UINT32_C(     17531) },
       {   UINT32_C(     11854),  UINT32_C(      6701),  UINT32_C(     10772),  UINT32_C(     17366)},
           INT8_C(         2),
       {   UINT32_C(4230290111),  UINT32_C(4116472155) } },
     { {   UINT32_C(   9344782),  UINT32_C(  14659312) },
       {   UINT32_C(     10437),  UINT32_C(     10420) },
       {   UINT32_C(       906),  UINT32_C(     18644),  UINT32_C(     16508),  UINT32_C(     16678)},
           INT8_C(         0),
       {   UINT32_C(4294856156),  UINT32_C(   5218792) } },
     { {   UINT32_C(  13608515),  UINT32_C(   3430158) },
       {   UINT32_C(     13755),  UINT32_C(      9868) },
       {   UINT32_C(      7174),  UINT32_C(     17760),  UINT32_C(     16856),  UINT32_C(      8296)},
           INT8_C(         0),
       {   UINT32_C(4209897441),  UINT32_C(4227604422) } },
     { {   UINT32_C(   1618132),  UINT32_C(  12547889) },
       {   UINT32_C(      8099),  UINT32_C(     18860) },
       {   UINT32_C(      1098),  UINT32_C(      5482),  UINT32_C(      8767),  UINT32_C(     15482)},
           INT8_C(         2),
       {   UINT32_C(4225581495),  UINT32_C(4142169565) } },
     { {   UINT32_C(  13224238),  UINT32_C(   6652430) },
       {   UINT32_C(      6837),  UINT32_C(     13996) },
       {   UINT32_C(       138),  UINT32_C(      4074),  UINT32_C(      5577),  UINT32_C(      9942)},
           INT8_C(         2),
       {   UINT32_C(4270061585),  UINT32_C(4223564034) } },
     { {   UINT32_C(  11742483),  UINT32_C(   9802174) },
       {   UINT32_C(     18818),  UINT32_C(      6761) },
       {   UINT32_C(      2308),  UINT32_C(     18630),  UINT32_C(      9349),  UINT32_C(     11315)},
           INT8_C(         0),
       {   UINT32_C(4263277835),  UINT32_C(4289165082) } },
     { {   UINT32_C(  16070524),  UINT32_C(  18562582) },
       {   UINT32_C(      8469),  UINT32_C(      8470) },
       {   UINT32_C(     19381),  UINT32_C(       196),  UINT32_C(      3731),  UINT32_C(     11432)},
           INT8_C(         2),
       {   UINT32_C(4279439981),  UINT32_C(4281928308) } },
  };

  simde_uint32x2_t r, a, b;
  simde_uint32x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_u32(test_vec[i].a);
    b = simde_vld1_u32(test_vec[i].b);
    v = simde_vld1q_u32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_laneq_u32(a, b, v, 0); break;
      case 1: r = simde_vmls_laneq_u32(a, b, v, 1); break;
      case 2: r = simde_vmls_laneq_u32(a, b, v, 2); break;
      case 3: r = simde_vmls_laneq_u32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_u32(0); break;
    }
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmls_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t v[2];
    int8_t lane;
    uint32_t r[2];
  } test_vec[] = {
     { {   UINT32_C(  13216612),  UINT32_C(   6916115) },
       {   UINT32_C(      3793),  UINT32_C(      5600) },
       {   UINT32_C(     12665),  UINT32_C(      1022)},
           INT8_C(         1),
       {   UINT32_C(   9340166),  UINT32_C(   1192915) } },
     { {   UINT32_C(   2375454),  UINT32_C(  18597104) },
       {   UINT32_C(        79),  UINT32_C(     19053) },
       {   UINT32_C(     13489),  UINT32_C(      1823)},
           INT8_C(         0),
       {   UINT32_C(   1309823),  UINT32_C(4056558483) } },
     { {   UINT32_C(   9769189),  UINT32_C(   5744419) },
       {   UINT32_C(      4085),  UINT32_C(      5904) },
       {   UINT32_C(     10452),  UINT32_C(      9697)},
           INT8_C(         1),
       {   UINT32_C(4265124240),  UINT32_C(4243460627) } },
     { {   UINT32_C(   7587765),  UINT32_C(  17610709) },
       {   UINT32_C(     11713),  UINT32_C(     10443) },
       {   UINT32_C(      4694),  UINT32_C(      6989)},
           INT8_C(         1),
       {   UINT32_C(4220692904),  UINT32_C(4239591878) } },
     { {   UINT32_C(  19740570),  UINT32_C(  13143896) },
       {   UINT32_C(      8559),  UINT32_C(      3531) },
       {   UINT32_C(     17972),  UINT32_C(      6011)},
           INT8_C(         0),
       {   UINT32_C(4160885518),  UINT32_C(4244652060) } },
     { {   UINT32_C(    197694),  UINT32_C(   8496100) },
       {   UINT32_C(     12350),  UINT32_C(      9487) },
       {   UINT32_C(     10478),  UINT32_C(     18312)},
           INT8_C(         1),
       {   UINT32_C(4069011790),  UINT32_C(4129737452) } },
     { {   UINT32_C(  14294595),  UINT32_C(  19729101) },
       {   UINT32_C(      9091),  UINT32_C(     17352) },
       {   UINT32_C(     14572),  UINT32_C(     16640)},
           INT8_C(         1),
       {   UINT32_C(4157987651),  UINT32_C(4025959117) } },
     { {   UINT32_C(  14216084),  UINT32_C(  10950830) },
       {   UINT32_C(     10797),  UINT32_C(     15180) },
       {   UINT32_C(      1599),  UINT32_C(     12973)},
           INT8_C(         1),
       {   UINT32_C(4169113899),  UINT32_C(4108987986) } },
  };

  simde_uint32x2_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_u32(test_vec[i].a);
    b = simde_vld1_u32(test_vec[i].b);
    v = simde_vld1_u32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmls_lane_u32(a, b, v, 0); break;
      case 1: r = simde_vmls_lane_u32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_u32(0); break;
    }
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[4];
    float b[4];
    float v[2];
    int8_t lane;
    float r[4];
  } test_vec[] = {
     { {   SIMDE_FLOAT32_C(  6491.42),  SIMDE_FLOAT32_C( -8451.97),  SIMDE_FLOAT32_C(  2635.60),  SIMDE_FLOAT32_C( -5083.51) },
       {   SIMDE_FLOAT32_C(    91.33),  SIMDE_FLOAT32_C(    59.15),  SIMDE_FLOAT32_C(   -50.14),  SIMDE_FLOAT32_C(    41.16) },
       {   SIMDE_FLOAT32_C(    15.14),  SIMDE_FLOAT32_C(     1.38)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(  5108.68),  SIMDE_FLOAT32_C( -9347.50),  SIMDE_FLOAT32_C(  3394.72),  SIMDE_FLOAT32_C( -5706.67) } },
     { {   SIMDE_FLOAT32_C( -7184.09),  SIMDE_FLOAT32_C(  -280.62),  SIMDE_FLOAT32_C(  8124.68),  SIMDE_FLOAT32_C( -6858.34) },
       {   SIMDE_FLOAT32_C(    48.46),  SIMDE_FLOAT32_C(    90.92),  SIMDE_FLOAT32_C(   -96.60),  SIMDE_FLOAT32_C(   -81.19) },
       {   SIMDE_FLOAT32_C(    67.28),  SIMDE_FLOAT32_C(   -71.80)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(-10444.48),  SIMDE_FLOAT32_C( -6397.72),  SIMDE_FLOAT32_C( 14623.93),  SIMDE_FLOAT32_C( -1395.88) } },
     { {   SIMDE_FLOAT32_C(   335.77),  SIMDE_FLOAT32_C( -4602.64),  SIMDE_FLOAT32_C(  3583.71),  SIMDE_FLOAT32_C(  6101.10) },
       {   SIMDE_FLOAT32_C(   -98.57),  SIMDE_FLOAT32_C(   -93.96),  SIMDE_FLOAT32_C(   -60.94),  SIMDE_FLOAT32_C(     8.99) },
       {   SIMDE_FLOAT32_C(    20.87),  SIMDE_FLOAT32_C(    85.47)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(  8760.55),  SIMDE_FLOAT32_C(  3428.12),  SIMDE_FLOAT32_C(  8792.25),  SIMDE_FLOAT32_C(  5332.72) } },
     { {   SIMDE_FLOAT32_C(  -125.83),  SIMDE_FLOAT32_C(  3874.30),  SIMDE_FLOAT32_C( -9217.65),  SIMDE_FLOAT32_C( -1981.56) },
       {   SIMDE_FLOAT32_C(     7.03),  SIMDE_FLOAT32_C(    22.24),  SIMDE_FLOAT32_C(    49.28),  SIMDE_FLOAT32_C(   -99.57) },
       {   SIMDE_FLOAT32_C(    40.30),  SIMDE_FLOAT32_C(    41.81)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(  -409.14),  SIMDE_FLOAT32_C(  2978.03),  SIMDE_FLOAT32_C(-11203.63),  SIMDE_FLOAT32_C(  2031.11) } },
     { {   SIMDE_FLOAT32_C( -1543.29),  SIMDE_FLOAT32_C(  7159.22),  SIMDE_FLOAT32_C(  6874.76),  SIMDE_FLOAT32_C(  5014.46) },
       {   SIMDE_FLOAT32_C(    37.12),  SIMDE_FLOAT32_C(   -51.42),  SIMDE_FLOAT32_C(    46.07),  SIMDE_FLOAT32_C(   -64.25) },
       {   SIMDE_FLOAT32_C(   -87.56),  SIMDE_FLOAT32_C(    54.83)},
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(  1706.94),  SIMDE_FLOAT32_C(  2656.88),  SIMDE_FLOAT32_C( 10908.65),  SIMDE_FLOAT32_C(  -611.27) } },
     { {   SIMDE_FLOAT32_C(  4071.42),  SIMDE_FLOAT32_C(  3296.60),  SIMDE_FLOAT32_C(  5251.51),  SIMDE_FLOAT32_C(  9515.43) },
       {   SIMDE_FLOAT32_C(   -87.49),  SIMDE_FLOAT32_C(    52.57),  SIMDE_FLOAT32_C(   -48.38),  SIMDE_FLOAT32_C(   -43.24) },
       {   SIMDE_FLOAT32_C(   -43.73),  SIMDE_FLOAT32_C(   -45.74)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(    69.63),  SIMDE_FLOAT32_C(  5701.15),  SIMDE_FLOAT32_C(  3038.61),  SIMDE_FLOAT32_C(  7537.63) } },
     { {   SIMDE_FLOAT32_C( -1979.85),  SIMDE_FLOAT32_C(  1741.08),  SIMDE_FLOAT32_C(  6060.61),  SIMDE_FLOAT32_C(  8761.64) },
       {   SIMDE_FLOAT32_C(    95.94),  SIMDE_FLOAT32_C(     6.34),  SIMDE_FLOAT32_C(    38.44),  SIMDE_FLOAT32_C(    61.53) },
       {   SIMDE_FLOAT32_C(    35.98),  SIMDE_FLOAT32_C(    82.11)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C( -9857.48),  SIMDE_FLOAT32_C(  1220.50),  SIMDE_FLOAT32_C(  2904.30),  SIMDE_FLOAT32_C(  3709.41) } },
     { {   SIMDE_FLOAT32_C( -4915.96),  SIMDE_FLOAT32_C(  8376.01),  SIMDE_FLOAT32_C( -5757.71),  SIMDE_FLOAT32_C(  4008.47) },
       {   SIMDE_FLOAT32_C(    59.56),  SIMDE_FLOAT32_C(    63.00),  SIMDE_FLOAT32_C(    22.15),  SIMDE_FLOAT32_C(   -38.60) },
       {   SIMDE_FLOAT32_C(    -8.68),  SIMDE_FLOAT32_C(    -8.36)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C( -4418.04),  SIMDE_FLOAT32_C(  8902.69),  SIMDE_FLOAT32_C( -5572.54),  SIMDE_FLOAT32_C(  3685.77) } },
  };

  simde_float32x4_t r, a, b;
  simde_float32x2_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_f32(test_vec[i].a);
    b = simde_vld1q_f32(test_vec[i].b);
    v = simde_vld1_f32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_lane_f32(a, b, v, 0); break;
      case 1: r = simde_vmlsq_lane_f32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_f32(0); break;
    }
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmlsq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t v[4];
    int8_t lane;
    int16_t r[8];
  } test_vec[] = {
     { {  -INT16_C(  5188), -INT16_C(  8438), -INT16_C(  5231),  INT16_C(  7587),
           INT16_C(  8978),  INT16_C(  5785),  INT16_C(  6040), -INT16_C(  2642) },
       {  -INT16_C(     5), -INT16_C(     8),  INT16_C(    70), -INT16_C(    19),
           INT16_C(    56), -INT16_C(    58),  INT16_C(    50),  INT16_C(    13) },
       {  -INT16_C(     1),  INT16_C(    14), -INT16_C(    33),  INT16_C(    63)},
           INT8_C(     1),
       {  -INT16_C(  5118), -INT16_C(  8326), -INT16_C(  6211),  INT16_C(  7853),
           INT16_C(  8194),  INT16_C(  6597),  INT16_C(  5340), -INT16_C(  2824) } },
     { {  -INT16_C(  3763), -INT16_C(  2628), -INT16_C(   344), -INT16_C(  6423),
           INT16_C(   756),  INT16_C(   826),  INT16_C(  6410), -INT16_C(  4702) },
       {   INT16_C(    42), -INT16_C(     4), -INT16_C(    18),  INT16_C(    78),
          -INT16_C(    93), -INT16_C(    60),  INT16_C(    76),  INT16_C(    38) },
       {  -INT16_C(    51), -INT16_C(     8), -INT16_C(    33),  INT16_C(    42)},
           INT8_C(     3),
       {  -INT16_C(  5527), -INT16_C(  2460),  INT16_C(   412), -INT16_C(  9699),
           INT16_C(  4662),  INT16_C(  3346),  INT16_C(  3218), -INT16_C(  6298) } },
     { {   INT16_C(  1804), -INT16_C(  8461),  INT16_C(  7204),  INT16_C(  4852),
           INT16_C(  2225),  INT16_C(  3888),  INT16_C(  3305), -INT16_C(  4162) },
       {   INT16_C(     6), -INT16_C(    47), -INT16_C(    39), -INT16_C(    73),
           INT16_C(    65),  INT16_C(    65),  INT16_C(     3),  INT16_C(    34) },
       {  -INT16_C(    21), -INT16_C(    62),  INT16_C(    26), -INT16_C(    99)},
           INT8_C(     2),
       {   INT16_C(  1648), -INT16_C(  7239),  INT16_C(  8218),  INT16_C(  6750),
           INT16_C(   535),  INT16_C(  2198),  INT16_C(  3227), -INT16_C(  5046) } },
     { {  -INT16_C(  7133), -INT16_C(   549), -INT16_C(   325), -INT16_C(  6686),
          -INT16_C(  1679), -INT16_C(  7506), -INT16_C(  7943),  INT16_C(  8844) },
       {  -INT16_C(    45), -INT16_C(    81),  INT16_C(    64), -INT16_C(    69),
           INT16_C(    41), -INT16_C(    13),  INT16_C(    74), -INT16_C(    73) },
       {  -INT16_C(    91),  INT16_C(    50),  INT16_C(    13), -INT16_C(    18)},
           INT8_C(     2),
       {  -INT16_C(  6548),  INT16_C(   504), -INT16_C(  1157), -INT16_C(  5789),
          -INT16_C(  2212), -INT16_C(  7337), -INT16_C(  8905),  INT16_C(  9793) } },
     { {  -INT16_C(  4878), -INT16_C(  8602), -INT16_C(  8189), -INT16_C(  2681),
           INT16_C(  7338), -INT16_C(  3498), -INT16_C(  8694), -INT16_C(   671) },
       {   INT16_C(    51), -INT16_C(    60), -INT16_C(    62),  INT16_C(    21),
           INT16_C(    75), -INT16_C(    18),  INT16_C(    30),  INT16_C(    70) },
       {   INT16_C(    83),  INT16_C(     5),  INT16_C(    98),  INT16_C(    90)},
           INT8_C(     0),
       {  -INT16_C(  9111), -INT16_C(  3622), -INT16_C(  3043), -INT16_C(  4424),
           INT16_C(  1113), -INT16_C(  2004), -INT16_C( 11184), -INT16_C(  6481) } },
     { {   INT16_C(  5619), -INT16_C(  6470),  INT16_C(  7000),  INT16_C(  5919),
          -INT16_C(  1294),  INT16_C(  8602),  INT16_C(  5031), -INT16_C(   345) },
       {   INT16_C(    54), -INT16_C(    39),  INT16_C(    73), -INT16_C(    31),
           INT16_C(    92),  INT16_C(    68),  INT16_C(    88), -INT16_C(    31) },
       {  -INT16_C(    29), -INT16_C(    82),  INT16_C(    90), -INT16_C(    54)},
           INT8_C(     1),
       {   INT16_C( 10047), -INT16_C(  9668),  INT16_C( 12986),  INT16_C(  3377),
           INT16_C(  6250),  INT16_C( 14178),  INT16_C( 12247), -INT16_C(  2887) } },
     { {  -INT16_C(  7748), -INT16_C(  1274),  INT16_C(  3421), -INT16_C(  4248),
           INT16_C(  4815),  INT16_C(  4796), -INT16_C(  1528), -INT16_C(  2191) },
       {  -INT16_C(    15),  INT16_C(    17),  INT16_C(    35), -INT16_C(    26),
           INT16_C(    16),  INT16_C(    54), -INT16_C(    24), -INT16_C(    13) },
       {  -INT16_C(    67), -INT16_C(    16),  INT16_C(    34), -INT16_C(    37)},
           INT8_C(     3),
       {  -INT16_C(  8303), -INT16_C(   645),  INT16_C(  4716), -INT16_C(  5210),
           INT16_C(  5407),  INT16_C(  6794), -INT16_C(  2416), -INT16_C(  2672) } },
     { {   INT16_C(  8579), -INT16_C(  2628), -INT16_C(  3924),  INT16_C(  7591),
          -INT16_C(  6125),  INT16_C(  1568), -INT16_C(  7313), -INT16_C(  8291) },
       {   INT16_C(    86),  INT16_C(    13), -INT16_C(    67), -INT16_C(     1),
           INT16_C(    22),  INT16_C(    30), -INT16_C(    80), -INT16_C(    69) },
       {  -INT16_C(    46), -INT16_C(    41), -INT16_C(    57), -INT16_C(    70)},
           INT8_C(     0),
       {   INT16_C( 12535), -INT16_C(  2030), -INT16_C(  7006),  INT16_C(  7545),
          -INT16_C(  5113),  INT16_C(  2948), -INT16_C( 10993), -INT16_C( 11465) } },
  };

  simde_int16x8_t r, a, b;
  simde_int16x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_s16(test_vec[i].a);
    b = simde_vld1q_s16(test_vec[i].b);
    v = simde_vld1_s16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vmlsq_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vmlsq_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vmlsq_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s16(0); break;
    }
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t v[2];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {   INT32_C(   2067537), -INT32_C(   1787354),  INT32_C(    759280),  INT32_C(    795779) },
       {  -INT32_C(      7988),  INT32_C(      2018), -INT32_C(      2719), -INT32_C(      7388) },
       {  -INT32_C(      6378),  INT32_C(      8353)},
           INT8_C(         1),
       {   INT32_C(  68791301), -INT32_C(  18643708),  INT32_C(  23471087),  INT32_C(  62507743) } },
     { {   INT32_C(   7988559), -INT32_C(   6030795),  INT32_C(   5763101),  INT32_C(   9307978) },
       {   INT32_C(      2284), -INT32_C(      2903), -INT32_C(      6517), -INT32_C(      4591) },
       {   INT32_C(      7512),  INT32_C(      2307)},
           INT8_C(         1),
       {   INT32_C(   2719371),  INT32_C(    666426),  INT32_C(  20797820),  INT32_C(  19899415) } },
     { {   INT32_C(   4554261),  INT32_C(   1170211), -INT32_C(   3300171), -INT32_C(   5880130) },
       {   INT32_C(       649),  INT32_C(      1731),  INT32_C(      1619), -INT32_C(      7917) },
       {  -INT32_C(      3541), -INT32_C(       447)},
           INT8_C(         1),
       {   INT32_C(   4844364),  INT32_C(   1943968), -INT32_C(   2576478), -INT32_C(   9419029) } },
     { {  -INT32_C(   4974825), -INT32_C(   2714283),  INT32_C(   8561422), -INT32_C(   9197423) },
       {   INT32_C(      8661), -INT32_C(      7895), -INT32_C(      9028), -INT32_C(      6302) },
       {   INT32_C(       443), -INT32_C(      8284)},
           INT8_C(         1),
       {   INT32_C(  66772899), -INT32_C(  68116463), -INT32_C(  66226530), -INT32_C(  61403191) } },
     { {  -INT32_C(   4166337), -INT32_C(   3164084), -INT32_C(   8639249), -INT32_C(   2650523) },
       {  -INT32_C(      5405),  INT32_C(      3318),  INT32_C(      9093), -INT32_C(       225) },
       {  -INT32_C(      9450),  INT32_C(      5112)},
           INT8_C(         0),
       {  -INT32_C(  55243587),  INT32_C(  28191016),  INT32_C(  77289601), -INT32_C(   4776773) } },
     { {  -INT32_C(   7102308), -INT32_C(   7309928),  INT32_C(    805822),  INT32_C(   3308797) },
       {   INT32_C(      8319),  INT32_C(      7694), -INT32_C(      6392),  INT32_C(      6437) },
       {   INT32_C(      2166), -INT32_C(      6721)},
           INT8_C(         1),
       {   INT32_C(  48809691),  INT32_C(  44401446), -INT32_C(  42154810),  INT32_C(  46571874) } },
     { {   INT32_C(   9895003), -INT32_C(   4484512), -INT32_C(   6521721),  INT32_C(   5731200) },
       {  -INT32_C(      9410),  INT32_C(      2568), -INT32_C(      9305),  INT32_C(      8401) },
       {   INT32_C(      2689),  INT32_C(       267)},
           INT8_C(         0),
       {   INT32_C(  35198493), -INT32_C(  11389864),  INT32_C(  18499424), -INT32_C(  16859089) } },
     { {   INT32_C(   4672068),  INT32_C(   1710369),  INT32_C(   3119765), -INT32_C(   5266593) },
       {   INT32_C(      2214), -INT32_C(      5836), -INT32_C(      8206), -INT32_C(       787) },
       {  -INT32_C(       841),  INT32_C(      4393)},
           INT8_C(         0),
       {   INT32_C(   6534042), -INT32_C(   3197707), -INT32_C(   3781481), -INT32_C(   5928460) } },
  };

  simde_int32x4_t r, a, b;
  simde_int32x2_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_s32(test_vec[i].a);
    b = simde_vld1q_s32(test_vec[i].b);
    v = simde_vld1_s32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vmlsq_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s32(0); break;
    }
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsq_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t v[4];
    int8_t lane;
    uint16_t r[8];
  } test_vec[] = {
     { {   UINT16_C( 17838),  UINT16_C( 13174),  UINT16_C( 11119),  UINT16_C(  8705),
           UINT16_C( 11723),  UINT16_C( 17154),  UINT16_C(  8765),  UINT16_C( 16080) },
       {   UINT16_C(   128),  UINT16_C(     5),  UINT16_C(    92),  UINT16_C(   150),
           UINT16_C(   146),  UINT16_C(   164),  UINT16_C(    83),  UINT16_C(   118) },
       {   UINT16_C(   173),  UINT16_C(   106),  UINT16_C(    70),  UINT16_C(   166)},
           INT8_C(     0),
       {   UINT16_C( 61230),  UINT16_C( 12309),  UINT16_C( 60739),  UINT16_C( 48291),
           UINT16_C( 52001),  UINT16_C( 54318),  UINT16_C( 59942),  UINT16_C( 61202) } },
     { {   UINT16_C( 16451),  UINT16_C(  4363),  UINT16_C( 18275),  UINT16_C( 16052),
           UINT16_C( 15197),  UINT16_C(  4998),  UINT16_C( 15634),  UINT16_C(   323) },
       {   UINT16_C(   146),  UINT16_C(   102),  UINT16_C(   124),  UINT16_C(    25),
           UINT16_C(   181),  UINT16_C(    21),  UINT16_C(   162),  UINT16_C(    88) },
       {   UINT16_C(    90),  UINT16_C(   149),  UINT16_C(   114),  UINT16_C(    74)},
           INT8_C(     3),
       {   UINT16_C(  5647),  UINT16_C( 62351),  UINT16_C(  9099),  UINT16_C( 14202),
           UINT16_C(  1803),  UINT16_C(  3444),  UINT16_C(  3646),  UINT16_C( 59347) } },
     { {   UINT16_C(  8467),  UINT16_C( 10164),  UINT16_C(  9025),  UINT16_C(  5585),
           UINT16_C(  3018),  UINT16_C(   456),  UINT16_C( 14551),  UINT16_C(  1080) },
       {   UINT16_C(   170),  UINT16_C(   112),  UINT16_C(   127),  UINT16_C(   129),
           UINT16_C(    32),  UINT16_C(    42),  UINT16_C(   191),  UINT16_C(   144) },
       {   UINT16_C(    18),  UINT16_C(   181),  UINT16_C(   100),  UINT16_C(     0)},
           INT8_C(     2),
       {   UINT16_C( 57003),  UINT16_C( 64500),  UINT16_C( 61861),  UINT16_C( 58221),
           UINT16_C( 65354),  UINT16_C( 61792),  UINT16_C( 60987),  UINT16_C( 52216) } },
     { {   UINT16_C( 17497),  UINT16_C(  1121),  UINT16_C(  1811),  UINT16_C( 10768),
           UINT16_C(  5152),  UINT16_C(  5731),  UINT16_C(  3815),  UINT16_C(  1174) },
       {   UINT16_C(   154),  UINT16_C(     5),  UINT16_C(   122),  UINT16_C(    97),
           UINT16_C(    55),  UINT16_C(   136),  UINT16_C(   169),  UINT16_C(   179) },
       {   UINT16_C(    48),  UINT16_C(   123),  UINT16_C(    12),  UINT16_C(   174)},
           INT8_C(     2),
       {   UINT16_C( 15649),  UINT16_C(  1061),  UINT16_C(   347),  UINT16_C(  9604),
           UINT16_C(  4492),  UINT16_C(  4099),  UINT16_C(  1787),  UINT16_C( 64562) } },
     { {   UINT16_C( 16583),  UINT16_C(  5252),  UINT16_C(  7490),  UINT16_C(  3819),
           UINT16_C(  6483),  UINT16_C(  9245),  UINT16_C(   455),  UINT16_C(  5637) },
       {   UINT16_C(    96),  UINT16_C(   184),  UINT16_C(    42),  UINT16_C(    35),
           UINT16_C(    59),  UINT16_C(   103),  UINT16_C(   163),  UINT16_C(   139) },
       {   UINT16_C(   142),  UINT16_C(   105),  UINT16_C(    37),  UINT16_C(    39)},
           INT8_C(     2),
       {   UINT16_C( 13031),  UINT16_C( 63980),  UINT16_C(  5936),  UINT16_C(  2524),
           UINT16_C(  4300),  UINT16_C(  5434),  UINT16_C( 59960),  UINT16_C(   494) } },
     { {   UINT16_C(  6473),  UINT16_C( 18112),  UINT16_C(  4323),  UINT16_C( 18260),
           UINT16_C(  3172),  UINT16_C(  7449),  UINT16_C(  4168),  UINT16_C( 15557) },
       {   UINT16_C(   130),  UINT16_C(    80),  UINT16_C(   190),  UINT16_C(     5),
           UINT16_C(    35),  UINT16_C(   197),  UINT16_C(   134),  UINT16_C(   124) },
       {   UINT16_C(    75),  UINT16_C(    56),  UINT16_C(   113),  UINT16_C(    90)},
           INT8_C(     1),
       {   UINT16_C( 64729),  UINT16_C( 13632),  UINT16_C( 59219),  UINT16_C( 17980),
           UINT16_C(  1212),  UINT16_C( 61953),  UINT16_C( 62200),  UINT16_C(  8613) } },
     { {   UINT16_C(  6128),  UINT16_C( 12118),  UINT16_C(  1671),  UINT16_C(  3331),
           UINT16_C( 10416),  UINT16_C( 13204),  UINT16_C( 12779),  UINT16_C(  9238) },
       {   UINT16_C(   176),  UINT16_C(   149),  UINT16_C(   121),  UINT16_C(    79),
           UINT16_C(   122),  UINT16_C(    96),  UINT16_C(   136),  UINT16_C(    81) },
       {   UINT16_C(   144),  UINT16_C(    74),  UINT16_C(    30),  UINT16_C(   104)},
           INT8_C(     0),
       {   UINT16_C( 46320),  UINT16_C( 56198),  UINT16_C( 49783),  UINT16_C( 57491),
           UINT16_C( 58384),  UINT16_C( 64916),  UINT16_C( 58731),  UINT16_C( 63110) } },
     { {   UINT16_C(    92),  UINT16_C(  7629),  UINT16_C( 19152),  UINT16_C(   332),
           UINT16_C(  1926),  UINT16_C(  8952),  UINT16_C(  3219),  UINT16_C( 16176) },
       {   UINT16_C(   105),  UINT16_C(    80),  UINT16_C(   192),  UINT16_C(   169),
           UINT16_C(   149),  UINT16_C(    96),  UINT16_C(   195),  UINT16_C(   135) },
       {   UINT16_C(    35),  UINT16_C(   132),  UINT16_C(    55),  UINT16_C(    80)},
           INT8_C(     0),
       {   UINT16_C( 61953),  UINT16_C(  4829),  UINT16_C( 12432),  UINT16_C( 59953),
           UINT16_C( 62247),  UINT16_C(  5592),  UINT16_C( 61930),  UINT16_C( 11451) } },
  };

  simde_uint16x8_t r, a, b;
  simde_uint16x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_u16(test_vec[i].a);
    b = simde_vld1q_u16(test_vec[i].b);
    v = simde_vld1_u16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_lane_u16(a, b, v, 0); break;
      case 1: r = simde_vmlsq_lane_u16(a, b, v, 1); break;
      case 2: r = simde_vmlsq_lane_u16(a, b, v, 2); break;
      case 3: r = simde_vmlsq_lane_u16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_u16(0); break;
    }
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsq_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t v[2];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
     { {   UINT32_C(  15791685),  UINT32_C(   5492798),  UINT32_C(  10259354),  UINT32_C(  16700343) },
       {   UINT32_C(      6663),  UINT32_C(      2022),  UINT32_C(      3324),  UINT32_C(     15952) },
       {   UINT32_C(      4043),  UINT32_C(     15374)},
           INT8_C(         0),
       {   UINT32_C(4283820472),  UINT32_C(4292285148),  UINT32_C(4291787718),  UINT32_C(4247173703) } },
     { {   UINT32_C(  15645803),  UINT32_C(   6441411),  UINT32_C(  15321628),  UINT32_C(  16904164) },
       {   UINT32_C(     18312),  UINT32_C(     14372),  UINT32_C(     15285),  UINT32_C(      2467) },
       {   UINT32_C(     17867),  UINT32_C(     14975)},
           INT8_C(         1),
       {   UINT32_C(4036390899),  UINT32_C(4086188007),  UINT32_C(4081396049),  UINT32_C(4274928135) } },
     { {   UINT32_C(   6161128),  UINT32_C(  11966727),  UINT32_C(   2995670),  UINT32_C(   9425172) },
       {   UINT32_C(     11544),  UINT32_C(      5384),  UINT32_C(     12464),  UINT32_C(     19073) },
       {   UINT32_C(     12943),  UINT32_C(      7149)},
           INT8_C(         1),
       {   UINT32_C(4218600368),  UINT32_C(4268443807),  UINT32_C(4208857830),  UINT32_C(4168039591) } },
     { {   UINT32_C(   9938231),  UINT32_C(  14165811),  UINT32_C(   9936283),  UINT32_C(   9236126) },
       {   UINT32_C(      5950),  UINT32_C(      7535),  UINT32_C(      2047),  UINT32_C(      9964) },
       {   UINT32_C(     18779),  UINT32_C(     12047)},
           INT8_C(         1),
       {   UINT32_C(4233225877),  UINT32_C(4218358962),  UINT32_C(4280243370),  UINT32_C(4184167114) } },
     { {   UINT32_C(  18599053),  UINT32_C(  19007241),  UINT32_C(  18733173),  UINT32_C(  17239616) },
       {   UINT32_C(      4951),  UINT32_C(     10742),  UINT32_C(     16153),  UINT32_C(      7316) },
       {   UINT32_C(      2694),  UINT32_C(     19335)},
           INT8_C(         0),
       {   UINT32_C(   5261059),  UINT32_C(4285035589),  UINT32_C(4270184287),  UINT32_C(4292497608) } },
     { {   UINT32_C(  10369957),  UINT32_C(  11318872),  UINT32_C(   5403206),  UINT32_C(  14029352) },
       {   UINT32_C(     12645),  UINT32_C(      7719),  UINT32_C(     12943),  UINT32_C(     11295) },
       {   UINT32_C(     17288),  UINT32_C(     16731)},
           INT8_C(         0),
       {   UINT32_C(4086730493),  UINT32_C(4172840096),  UINT32_C(4076611918),  UINT32_C(4113728688) } },
     { {   UINT32_C(   7181617),  UINT32_C(  19018654),  UINT32_C(   8564072),  UINT32_C(  12618372) },
       {   UINT32_C(      1475),  UINT32_C(      5581),  UINT32_C(     16355),  UINT32_C(      5170) },
       {   UINT32_C(     11129),  UINT32_C(      4357)},
           INT8_C(         0),
       {   UINT32_C(4285733638),  UINT32_C(4251875001),  UINT32_C(4121516573),  UINT32_C(4250048738) } },
     { {   UINT32_C(  17863140),  UINT32_C(   4138048),  UINT32_C(   5890744),  UINT32_C(   3960839) },
       {   UINT32_C(      7857),  UINT32_C(     17458),  UINT32_C(     15399),  UINT32_C(     19704) },
       {   UINT32_C(     13678),  UINT32_C(     11220)},
           INT8_C(         1),
       {   UINT32_C(4224674896),  UINT32_C(4103226584),  UINT32_C(4128081260),  UINT32_C(4077849255) } },
  };

  simde_uint32x4_t r, a, b;
  simde_uint32x2_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_u32(test_vec[i].a);
    b = simde_vld1q_u32(test_vec[i].b);
    v = simde_vld1_u32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_lane_u32(a, b, v, 0); break;
      case 1: r = simde_vmlsq_lane_u32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_u32(0); break;
    }
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[4];
    float b[4];
    float v[4];
    int8_t lane;
    float r[4];
  } test_vec[] = {
     { {   SIMDE_FLOAT32_C( -6762.79),  SIMDE_FLOAT32_C(   499.13),  SIMDE_FLOAT32_C( -6587.10),  SIMDE_FLOAT32_C(  2471.72) },
       {   SIMDE_FLOAT32_C(    28.52),  SIMDE_FLOAT32_C(    44.06),  SIMDE_FLOAT32_C(    72.56),  SIMDE_FLOAT32_C(    95.83) },
       {   SIMDE_FLOAT32_C(   -78.53),  SIMDE_FLOAT32_C(    73.13),  SIMDE_FLOAT32_C(   -59.69),  SIMDE_FLOAT32_C(     1.53)},
           INT8_C(        2),
       {   SIMDE_FLOAT32_C( -5060.43),  SIMDE_FLOAT32_C(  3129.07),  SIMDE_FLOAT32_C( -2255.99),  SIMDE_FLOAT32_C(  8191.81) } },
     { {   SIMDE_FLOAT32_C(  6887.56),  SIMDE_FLOAT32_C(  1557.40),  SIMDE_FLOAT32_C(   798.28),  SIMDE_FLOAT32_C(   411.12) },
       {   SIMDE_FLOAT32_C(   -21.25),  SIMDE_FLOAT32_C(   -33.97),  SIMDE_FLOAT32_C(    43.09),  SIMDE_FLOAT32_C(    31.89) },
       {   SIMDE_FLOAT32_C(   -84.05),  SIMDE_FLOAT32_C(    40.51),  SIMDE_FLOAT32_C(    54.72),  SIMDE_FLOAT32_C(    53.52)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(  7748.40),  SIMDE_FLOAT32_C(  2933.52),  SIMDE_FLOAT32_C(  -947.30),  SIMDE_FLOAT32_C(  -880.74) } },
     { {   SIMDE_FLOAT32_C(  2373.31),  SIMDE_FLOAT32_C(  1066.86),  SIMDE_FLOAT32_C( -1224.48),  SIMDE_FLOAT32_C(  9197.43) },
       {   SIMDE_FLOAT32_C(   -78.15),  SIMDE_FLOAT32_C(    31.82),  SIMDE_FLOAT32_C(   -19.08),  SIMDE_FLOAT32_C(    35.15) },
       {   SIMDE_FLOAT32_C(    46.27),  SIMDE_FLOAT32_C(   -65.33),  SIMDE_FLOAT32_C(     4.83),  SIMDE_FLOAT32_C(    -2.95)},
           INT8_C(        2),
       {   SIMDE_FLOAT32_C(  2750.77),  SIMDE_FLOAT32_C(   913.17),  SIMDE_FLOAT32_C( -1132.32),  SIMDE_FLOAT32_C(  9027.66) } },
     { {   SIMDE_FLOAT32_C( -1918.81),  SIMDE_FLOAT32_C(  5219.58),  SIMDE_FLOAT32_C(  2597.27),  SIMDE_FLOAT32_C(  8829.63) },
       {   SIMDE_FLOAT32_C(    65.58),  SIMDE_FLOAT32_C(   -98.35),  SIMDE_FLOAT32_C(    63.35),  SIMDE_FLOAT32_C(   -73.00) },
       {   SIMDE_FLOAT32_C(   -60.40),  SIMDE_FLOAT32_C(    78.91),  SIMDE_FLOAT32_C(   -70.88),  SIMDE_FLOAT32_C(   -96.15)},
           INT8_C(        3),
       {   SIMDE_FLOAT32_C(  4386.71),  SIMDE_FLOAT32_C( -4236.77),  SIMDE_FLOAT32_C(  8688.37),  SIMDE_FLOAT32_C(  1810.68) } },
     { {   SIMDE_FLOAT32_C(  3167.82),  SIMDE_FLOAT32_C(  7995.66),  SIMDE_FLOAT32_C(   728.04),  SIMDE_FLOAT32_C( -3484.87) },
       {   SIMDE_FLOAT32_C(   -92.09),  SIMDE_FLOAT32_C(     7.83),  SIMDE_FLOAT32_C(    -0.32),  SIMDE_FLOAT32_C(   -33.98) },
       {   SIMDE_FLOAT32_C(   -73.28),  SIMDE_FLOAT32_C(    91.58),  SIMDE_FLOAT32_C(   -70.19),  SIMDE_FLOAT32_C(    67.29)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C( 11601.42),  SIMDE_FLOAT32_C(  7278.59),  SIMDE_FLOAT32_C(   757.35),  SIMDE_FLOAT32_C(  -372.98) } },
     { {   SIMDE_FLOAT32_C(  4508.62),  SIMDE_FLOAT32_C( -9206.33),  SIMDE_FLOAT32_C(  8790.14),  SIMDE_FLOAT32_C( -3027.85) },
       {   SIMDE_FLOAT32_C(    60.34),  SIMDE_FLOAT32_C(   -64.83),  SIMDE_FLOAT32_C(    -9.37),  SIMDE_FLOAT32_C(    61.16) },
       {   SIMDE_FLOAT32_C(   -66.51),  SIMDE_FLOAT32_C(    81.52),  SIMDE_FLOAT32_C(   -64.63),  SIMDE_FLOAT32_C(   -25.06)},
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(  -410.30),  SIMDE_FLOAT32_C( -3921.39),  SIMDE_FLOAT32_C(  9553.98),  SIMDE_FLOAT32_C( -8013.61) } },
     { {   SIMDE_FLOAT32_C( -4120.81),  SIMDE_FLOAT32_C( -7964.12),  SIMDE_FLOAT32_C( -1354.29),  SIMDE_FLOAT32_C( -8729.84) },
       {   SIMDE_FLOAT32_C(   -55.62),  SIMDE_FLOAT32_C(    -2.28),  SIMDE_FLOAT32_C(    46.43),  SIMDE_FLOAT32_C(   -31.88) },
       {   SIMDE_FLOAT32_C(    70.07),  SIMDE_FLOAT32_C(     5.72),  SIMDE_FLOAT32_C(     0.95),  SIMDE_FLOAT32_C(   -61.90)},
           INT8_C(        3),
       {   SIMDE_FLOAT32_C( -7563.69),  SIMDE_FLOAT32_C( -8105.25),  SIMDE_FLOAT32_C(  1519.73),  SIMDE_FLOAT32_C(-10703.21) } },
     { {   SIMDE_FLOAT32_C( -5959.85),  SIMDE_FLOAT32_C( -9679.86),  SIMDE_FLOAT32_C( -7706.12),  SIMDE_FLOAT32_C(  3826.01) },
       {   SIMDE_FLOAT32_C(   -17.91),  SIMDE_FLOAT32_C(   -91.17),  SIMDE_FLOAT32_C(   -19.92),  SIMDE_FLOAT32_C(    53.18) },
       {   SIMDE_FLOAT32_C(   -90.02),  SIMDE_FLOAT32_C(   -37.21),  SIMDE_FLOAT32_C(    45.50),  SIMDE_FLOAT32_C(   -78.18)},
           INT8_C(        2),
       {   SIMDE_FLOAT32_C( -5144.95),  SIMDE_FLOAT32_C( -5531.63),  SIMDE_FLOAT32_C( -6799.76),  SIMDE_FLOAT32_C(  1406.32) } },
  };

  simde_float32x4_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_f32(test_vec[i].a);
    b = simde_vld1q_f32(test_vec[i].b);
    v = simde_vld1q_f32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_laneq_f32(a, b, v, 0); break;
      case 1: r = simde_vmlsq_laneq_f32(a, b, v, 1); break;
      case 2: r = simde_vmlsq_laneq_f32(a, b, v, 2); break;
      case 3: r = simde_vmlsq_laneq_f32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_f32(0); break;
    }
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmlsq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t v[8];
    int8_t lane;
    int16_t r[8];
  } test_vec[] = {
     { {  -INT16_C(  5645),  INT16_C(  6126),  INT16_C(  1606),  INT16_C(   419),
          -INT16_C(  6707),  INT16_C(  7665),  INT16_C(   938), -INT16_C(  1109) },
       {  -INT16_C(     3),  INT16_C(    84),  INT16_C(    61),  INT16_C(    65),
           INT16_C(    13), -INT16_C(    33), -INT16_C(     3), -INT16_C(    52) },
       {  -INT16_C(    38),  INT16_C(    20),  INT16_C(    21),  INT16_C(    70),
          -INT16_C(    84), -INT16_C(    76),  INT16_C(    22),  INT16_C(    21)},
           INT8_C(     1),
       {  -INT16_C(  5585),  INT16_C(  4446),  INT16_C(   386), -INT16_C(   881),
          -INT16_C(  6967),  INT16_C(  8325),  INT16_C(   998), -INT16_C(    69) } },
     { {   INT16_C(  5485), -INT16_C(  1448),  INT16_C(  4322),  INT16_C(  2394),
          -INT16_C(  8117),  INT16_C(  7330), -INT16_C(   550), -INT16_C(  6344) },
       {   INT16_C(    28), -INT16_C(     4),  INT16_C(    50),  INT16_C(    90),
           INT16_C(    82), -INT16_C(    61),  INT16_C(     7),  INT16_C(    35) },
       {  -INT16_C(    77), -INT16_C(    91),  INT16_C(    58), -INT16_C(    97),
           INT16_C(     7),  INT16_C(    38), -INT16_C(    21), -INT16_C(    86)},
           INT8_C(     5),
       {   INT16_C(  4421), -INT16_C(  1296),  INT16_C(  2422), -INT16_C(  1026),
          -INT16_C( 11233),  INT16_C(  9648), -INT16_C(   816), -INT16_C(  7674) } },
     { {   INT16_C(  7671),  INT16_C(  3232), -INT16_C(  6536), -INT16_C(  4163),
          -INT16_C(  2780),  INT16_C(  2784),  INT16_C(  2806),  INT16_C(  1950) },
       {  -INT16_C(    88), -INT16_C(    97),  INT16_C(    69), -INT16_C(    76),
          -INT16_C(    43),  INT16_C(    47),  INT16_C(    93), -INT16_C(    43) },
       {  -INT16_C(    50),  INT16_C(    30),  INT16_C(    43),  INT16_C(    22),
           INT16_C(    15), -INT16_C(    84), -INT16_C(    38), -INT16_C(    55)},
           INT8_C(     1),
       {   INT16_C( 10311),  INT16_C(  6142), -INT16_C(  8606), -INT16_C(  1883),
          -INT16_C(  1490),  INT16_C(  1374),  INT16_C(    16),  INT16_C(  3240) } },
     { {   INT16_C(  2979), -INT16_C(  2417), -INT16_C(  7237),  INT16_C(  5546),
           INT16_C(  3240), -INT16_C(  9983),  INT16_C(  2515), -INT16_C(  7398) },
       {   INT16_C(     4), -INT16_C(    71), -INT16_C(    87), -INT16_C(    85),
           INT16_C(    34),  INT16_C(    33), -INT16_C(    99),  INT16_C(    89) },
       {   INT16_C(    80), -INT16_C(    55),  INT16_C(    13),  INT16_C(    57),
          -INT16_C(    87), -INT16_C(    49), -INT16_C(    42),  INT16_C(     1)},
           INT8_C(     4),
       {   INT16_C(  3327), -INT16_C(  8594), -INT16_C( 14806), -INT16_C(  1849),
           INT16_C(  6198), -INT16_C(  7112), -INT16_C(  6098),  INT16_C(   345) } },
     { {  -INT16_C(  6353),  INT16_C(   885),  INT16_C(  8828), -INT16_C(  7651),
          -INT16_C(  9996),  INT16_C(    55), -INT16_C(  6512), -INT16_C(  8877) },
       {  -INT16_C(    54),  INT16_C(    12), -INT16_C(    76), -INT16_C(    30),
           INT16_C(    96),  INT16_C(     1), -INT16_C(    55), -INT16_C(    39) },
       {   INT16_C(    52), -INT16_C(     2), -INT16_C(    84), -INT16_C(    89),
          -INT16_C(    37), -INT16_C(    75), -INT16_C(    69), -INT16_C(    48)},
           INT8_C(     4),
       {  -INT16_C(  8351),  INT16_C(  1329),  INT16_C(  6016), -INT16_C(  8761),
          -INT16_C(  6444),  INT16_C(    92), -INT16_C(  8547), -INT16_C( 10320) } },
     { {   INT16_C(  4466), -INT16_C(  8522), -INT16_C(  5854), -INT16_C(  8678),
           INT16_C(   887), -INT16_C(   988),  INT16_C(  7415), -INT16_C(  8781) },
       {  -INT16_C(    62), -INT16_C(    93),  INT16_C(    29),  INT16_C(     6),
           INT16_C(    13), -INT16_C(    42),  INT16_C(    62), -INT16_C(    55) },
       {  -INT16_C(    45), -INT16_C(    34), -INT16_C(    92), -INT16_C(    32),
          -INT16_C(     6),  INT16_C(    20),  INT16_C(    34), -INT16_C(    60)},
           INT8_C(     4),
       {   INT16_C(  4094), -INT16_C(  9080), -INT16_C(  5680), -INT16_C(  8642),
           INT16_C(   965), -INT16_C(  1240),  INT16_C(  7787), -INT16_C(  9111) } },
     { {  -INT16_C(  7753), -INT16_C(  8668), -INT16_C(  3870),  INT16_C(  2230),
           INT16_C(  3263), -INT16_C(  5559),  INT16_C(  2354),  INT16_C(  3199) },
       {  -INT16_C(    23), -INT16_C(    88),  INT16_C(    93), -INT16_C(    81),
          -INT16_C(    53),  INT16_C(    43),  INT16_C(    23),  INT16_C(    59) },
       {  -INT16_C(    99),  INT16_C(    44), -INT16_C(    81), -INT16_C(    50),
          -INT16_C(    52),  INT16_C(    83), -INT16_C(     4),  INT16_C(    29)},
           INT8_C(     6),
       {  -INT16_C(  7845), -INT16_C(  9020), -INT16_C(  3498),  INT16_C(  1906),
           INT16_C(  3051), -INT16_C(  5387),  INT16_C(  2446),  INT16_C(  3435) } },
     { {  -INT16_C(  9513), -INT16_C(  4391),  INT16_C(  6919),  INT16_C(  1757),
           INT16_C(  9022), -INT16_C(  9450),  INT16_C(  4930), -INT16_C(  9686) },
       {   INT16_C(    51),  INT16_C(    13), -INT16_C(     8),  INT16_C(    87),
          -INT16_C(    72),  INT16_C(    14), -INT16_C(     5), -INT16_C(    29) },
       {  -INT16_C(    92),  INT16_C(    88),  INT16_C(    20), -INT16_C(    56),
          -INT16_C(    77),  INT16_C(    17),  INT16_C(    73), -INT16_C(    30)},
           INT8_C(     0),
       {  -INT16_C(  4821), -INT16_C(  3195),  INT16_C(  6183),  INT16_C(  9761),
           INT16_C(  2398), -INT16_C(  8162),  INT16_C(  4470), -INT16_C( 12354) } },
  };

  simde_int16x8_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s16(test_vec[i].a);
    b = simde_vld1q_s16(test_vec[i].b);
    v = simde_vld1q_s16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vmlsq_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vmlsq_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vmlsq_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vmlsq_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vmlsq_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vmlsq_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vmlsq_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s16(0); break;
    }
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(   7266304),  INT32_C(   8765414), -INT32_C(   7324637), -INT32_C(   3796132) },
       {   INT32_C(      2916), -INT32_C(      9685), -INT32_C(      3851),  INT32_C(      5537) },
       {   INT32_C(      6312), -INT32_C(      2907), -INT32_C(      5037),  INT32_C(       438)},
           INT8_C(         1),
       {   INT32_C(   1210508), -INT32_C(  19388881), -INT32_C(  18519494),  INT32_C(  12299927) } },
     { {  -INT32_C(   2085611),  INT32_C(   8518775), -INT32_C(   2401017), -INT32_C(   7493078) },
       {  -INT32_C(       850), -INT32_C(       102),  INT32_C(      2467),  INT32_C(      6004) },
       {  -INT32_C(      2910),  INT32_C(      4501),  INT32_C(      8068),  INT32_C(      2494)},
           INT8_C(         2),
       {   INT32_C(   4772189),  INT32_C(   9341711), -INT32_C(  22304773), -INT32_C(  55933350) } },
     { {   INT32_C(   9795531), -INT32_C(   1489691),  INT32_C(   6104423), -INT32_C(   6800355) },
       {   INT32_C(      4492),  INT32_C(      7544), -INT32_C(      3632),  INT32_C(      7019) },
       {   INT32_C(      4948),  INT32_C(      2073),  INT32_C(       258), -INT32_C(      9573)},
           INT8_C(         2),
       {   INT32_C(   8636595), -INT32_C(   3436043),  INT32_C(   7041479), -INT32_C(   8611257) } },
     { {  -INT32_C(   3176719), -INT32_C(   2766058), -INT32_C(   1515092),  INT32_C(   9841774) },
       {  -INT32_C(      5232),  INT32_C(      9968),  INT32_C(      8457),  INT32_C(      2722) },
       {  -INT32_C(      1468), -INT32_C(        90), -INT32_C(      6146),  INT32_C(      7313)},
           INT8_C(         2),
       {  -INT32_C(  35332591),  INT32_C(  58497270),  INT32_C(  50461630),  INT32_C(  26571186) } },
     { {  -INT32_C(   1959870), -INT32_C(      1993),  INT32_C(   7064633),  INT32_C(   5068070) },
       {   INT32_C(      6246), -INT32_C(      2027),  INT32_C(      1778), -INT32_C(      9217) },
       {  -INT32_C(      4519),  INT32_C(      3833), -INT32_C(      3138),  INT32_C(      1701)},
           INT8_C(         2),
       {   INT32_C(  17640078), -INT32_C(   6362719),  INT32_C(  12643997), -INT32_C(  23854876) } },
     { {   INT32_C(   8343862),  INT32_C(   6370160),  INT32_C(   5836424),  INT32_C(   2038678) },
       {   INT32_C(      1733), -INT32_C(      8869),  INT32_C(      9296), -INT32_C(      9973) },
       {  -INT32_C(      9543), -INT32_C(      7415),  INT32_C(      5411), -INT32_C(       481)},
           INT8_C(         1),
       {   INT32_C(  21194057), -INT32_C(  59393475),  INT32_C(  74766264), -INT32_C(  71911117) } },
     { {   INT32_C(   2535276), -INT32_C(   3126396), -INT32_C(   5814968),  INT32_C(   1121683) },
       {   INT32_C(      7388),  INT32_C(      2655),  INT32_C(      3990),  INT32_C(      3338) },
       {   INT32_C(      6044),  INT32_C(      8407),  INT32_C(      1220), -INT32_C(       723)},
           INT8_C(         3),
       {   INT32_C(   7876800), -INT32_C(   1206831), -INT32_C(   2930198),  INT32_C(   3535057) } },
     { {   INT32_C(   9047969), -INT32_C(   3280918),  INT32_C(   5675927),  INT32_C(   3443148) },
       {   INT32_C(      9648), -INT32_C(       860),  INT32_C(      4176), -INT32_C(      3865) },
       {   INT32_C(      4658),  INT32_C(      8440),  INT32_C(       848),  INT32_C(      8075)},
           INT8_C(         1),
       {  -INT32_C(  72381151),  INT32_C(   3977482), -INT32_C(  29569513),  INT32_C(  36063748) } },
  };

  simde_int32x4_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s32(test_vec[i].a);
    b = simde_vld1q_s32(test_vec[i].b);
    v = simde_vld1q_s32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vmlsq_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vmlsq_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vmlsq_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s32(0); break;
    }
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsq_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t v[8];
    int8_t lane;
    uint16_t r[8];
  } test_vec[] = {
     { {   UINT16_C( 18145),  UINT16_C( 14017),  UINT16_C( 15721),  UINT16_C(  7915),
           UINT16_C( 12416),  UINT16_C(  9449),  UINT16_C(  2938),  UINT16_C(  7196) },
       {   UINT16_C(    49),  UINT16_C(   187),  UINT16_C(     5),  UINT16_C(    77),
           UINT16_C(    55),  UINT16_C(    70),  UINT16_C(   135),  UINT16_C(   137) },
       {   UINT16_C(   191),  UINT16_C(   124),  UINT16_C(   162),  UINT16_C(     6),
           UINT16_C(    62),  UINT16_C(    99),  UINT16_C(   119),  UINT16_C(   172)},
           INT8_C(     6),
       {   UINT16_C( 12314),  UINT16_C( 57300),  UINT16_C( 15126),  UINT16_C( 64288),
           UINT16_C(  5871),  UINT16_C(  1119),  UINT16_C( 52409),  UINT16_C( 56429) } },
     { {   UINT16_C( 10417),  UINT16_C( 17841),  UINT16_C( 16776),  UINT16_C(  1442),
           UINT16_C(  8682),  UINT16_C(  9449),  UINT16_C( 10075),  UINT16_C( 10824) },
       {   UINT16_C(     3),  UINT16_C(   115),  UINT16_C(   118),  UINT16_C(   193),
           UINT16_C(    68),  UINT16_C(    55),  UINT16_C(    63),  UINT16_C(    49) },
       {   UINT16_C(    41),  UINT16_C(   174),  UINT16_C(   106),  UINT16_C(   117),
           UINT16_C(    72),  UINT16_C(    25),  UINT16_C(    93),  UINT16_C(    27)},
           INT8_C(     0),
       {   UINT16_C( 10294),  UINT16_C( 13126),  UINT16_C( 11938),  UINT16_C( 59065),
           UINT16_C(  5894),  UINT16_C(  7194),  UINT16_C(  7492),  UINT16_C(  8815) } },
     { {   UINT16_C(  3889),  UINT16_C( 13409),  UINT16_C( 19336),  UINT16_C( 15123),
           UINT16_C(   118),  UINT16_C(  6711),  UINT16_C( 17579),  UINT16_C(  5828) },
       {   UINT16_C(   104),  UINT16_C(    18),  UINT16_C(   116),  UINT16_C(   147),
           UINT16_C(   173),  UINT16_C(    62),  UINT16_C(    43),  UINT16_C(    77) },
       {   UINT16_C(    77),  UINT16_C(   124),  UINT16_C(   174),  UINT16_C(    73),
           UINT16_C(    65),  UINT16_C(    99),  UINT16_C(   197),  UINT16_C(    17)},
           INT8_C(     3),
       {   UINT16_C( 61833),  UINT16_C( 12095),  UINT16_C( 10868),  UINT16_C(  4392),
           UINT16_C( 53025),  UINT16_C(  2185),  UINT16_C( 14440),  UINT16_C(   207) } },
     { {   UINT16_C( 10275),  UINT16_C(   705),  UINT16_C(  9741),  UINT16_C(   869),
           UINT16_C( 10520),  UINT16_C(  8115),  UINT16_C( 17123),  UINT16_C(  1031) },
       {   UINT16_C(    20),  UINT16_C(   196),  UINT16_C(   108),  UINT16_C(    24),
           UINT16_C(   122),  UINT16_C(   167),  UINT16_C(   156),  UINT16_C(   187) },
       {   UINT16_C(    92),  UINT16_C(    74),  UINT16_C(    51),  UINT16_C(   164),
           UINT16_C(   173),  UINT16_C(   154),  UINT16_C(    51),  UINT16_C(   187)},
           INT8_C(     7),
       {   UINT16_C(  6535),  UINT16_C( 29589),  UINT16_C( 55081),  UINT16_C( 61917),
           UINT16_C( 53242),  UINT16_C( 42422),  UINT16_C( 53487),  UINT16_C( 31598) } },
     { {   UINT16_C( 16022),  UINT16_C( 17903),  UINT16_C(   206),  UINT16_C(  8835),
           UINT16_C(  8437),  UINT16_C(   185),  UINT16_C( 10376),  UINT16_C(  2785) },
       {   UINT16_C(    97),  UINT16_C(   103),  UINT16_C(    44),  UINT16_C(   130),
           UINT16_C(   115),  UINT16_C(   125),  UINT16_C(   119),  UINT16_C(    92) },
       {   UINT16_C(     4),  UINT16_C(    92),  UINT16_C(    15),  UINT16_C(    24),
           UINT16_C(     0),  UINT16_C(   174),  UINT16_C(   179),  UINT16_C(    77)},
           INT8_C(     1),
       {   UINT16_C(  7098),  UINT16_C(  8427),  UINT16_C( 61694),  UINT16_C( 62411),
           UINT16_C( 63393),  UINT16_C( 54221),  UINT16_C( 64964),  UINT16_C( 59857) } },
     { {   UINT16_C( 16280),  UINT16_C(  2025),  UINT16_C(  3456),  UINT16_C(  6751),
           UINT16_C(  7293),  UINT16_C( 15784),  UINT16_C( 14562),  UINT16_C(   568) },
       {   UINT16_C(    35),  UINT16_C(    55),  UINT16_C(   168),  UINT16_C(    79),
           UINT16_C(   106),  UINT16_C(    19),  UINT16_C(   128),  UINT16_C(   125) },
       {   UINT16_C(   102),  UINT16_C(   190),  UINT16_C(    11),  UINT16_C(   126),
           UINT16_C(    59),  UINT16_C(    79),  UINT16_C(   189),  UINT16_C(    80)},
           INT8_C(     7),
       {   UINT16_C( 13480),  UINT16_C( 63161),  UINT16_C( 55552),  UINT16_C(   431),
           UINT16_C( 64349),  UINT16_C( 14264),  UINT16_C(  4322),  UINT16_C( 56104) } },
     { {   UINT16_C(  7069),  UINT16_C( 12929),  UINT16_C( 18496),  UINT16_C(  3618),
           UINT16_C(  9857),  UINT16_C(  8094),  UINT16_C( 19162),  UINT16_C(  7233) },
       {   UINT16_C(    83),  UINT16_C(    58),  UINT16_C(    68),  UINT16_C(    92),
           UINT16_C(   180),  UINT16_C(    11),  UINT16_C(    52),  UINT16_C(   148) },
       {   UINT16_C(    70),  UINT16_C(   164),  UINT16_C(    85),  UINT16_C(    95),
           UINT16_C(   150),  UINT16_C(    86),  UINT16_C(   172),  UINT16_C(    12)},
           INT8_C(     4),
       {   UINT16_C( 60155),  UINT16_C(  4229),  UINT16_C(  8296),  UINT16_C( 55354),
           UINT16_C( 48393),  UINT16_C(  6444),  UINT16_C( 11362),  UINT16_C( 50569) } },
     { {   UINT16_C(  4142),  UINT16_C( 11558),  UINT16_C(   651),  UINT16_C( 17526),
           UINT16_C(  9861),  UINT16_C(  2214),  UINT16_C( 11903),  UINT16_C( 15590) },
       {   UINT16_C(   154),  UINT16_C(   179),  UINT16_C(    62),  UINT16_C(    90),
           UINT16_C(    75),  UINT16_C(    76),  UINT16_C(   161),  UINT16_C(   113) },
       {   UINT16_C(   176),  UINT16_C(   164),  UINT16_C(    21),  UINT16_C(    52),
           UINT16_C(    15),  UINT16_C(   165),  UINT16_C(    85),  UINT16_C(    50)},
           INT8_C(     7),
       {   UINT16_C( 61978),  UINT16_C(  2608),  UINT16_C( 63087),  UINT16_C( 13026),
           UINT16_C(  6111),  UINT16_C( 63950),  UINT16_C(  3853),  UINT16_C(  9940) } },
  };

  simde_uint16x8_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_u16(test_vec[i].a);
    b = simde_vld1q_u16(test_vec[i].b);
    v = simde_vld1q_u16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_laneq_u16(a, b, v, 0); break;
      case 1: r = simde_vmlsq_laneq_u16(a, b, v, 1); break;
      case 2: r = simde_vmlsq_laneq_u16(a, b, v, 2); break;
      case 3: r = simde_vmlsq_laneq_u16(a, b, v, 3); break;
      case 4: r = simde_vmlsq_laneq_u16(a, b, v, 4); break;
      case 5: r = simde_vmlsq_laneq_u16(a, b, v, 5); break;
      case 6: r = simde_vmlsq_laneq_u16(a, b, v, 6); break;
      case 7: r = simde_vmlsq_laneq_u16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_u16(0); break;
    }
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsq_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t v[4];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
     { {   UINT32_C(   1861053),  UINT32_C(  12637301),  UINT32_C(  15274610),  UINT32_C(   9835651) },
       {   UINT32_C(     11495),  UINT32_C(      8707),  UINT32_C(      5467),  UINT32_C(      6266) },
       {   UINT32_C(      4717),  UINT32_C(     14182),  UINT32_C(     15593),  UINT32_C(      6816)},
           INT8_C(         2),
       {   UINT32_C(4117586814),  UINT32_C(4171836346),  UINT32_C(4224994975),  UINT32_C(4207097209) } },
     { {   UINT32_C(   9489067),  UINT32_C(   8154869),  UINT32_C(   3448644),  UINT32_C(  17329986) },
       {   UINT32_C(     11917),  UINT32_C(      9564),  UINT32_C(      8828),  UINT32_C(     14785) },
       {   UINT32_C(     15402),  UINT32_C(      3072),  UINT32_C(        76),  UINT32_C(      1440)},
           INT8_C(         0),
       {   UINT32_C(4120910729),  UINT32_C(4155817437),  UINT32_C(4162447084),  UINT32_C(4084578712) } },
     { {   UINT32_C(  19581104),  UINT32_C(  17145354),  UINT32_C(   4944592),  UINT32_C(   2397841) },
       {   UINT32_C(     16374),  UINT32_C(     18528),  UINT32_C(      3954),  UINT32_C(     16844) },
       {   UINT32_C(      6018),  UINT32_C(      6617),  UINT32_C(     11914),  UINT32_C(     15796)},
           INT8_C(         0),
       {   UINT32_C(4216009668),  UINT32_C(4200611146),  UINT32_C(4276116716),  UINT32_C(4195997945) } },
     { {   UINT32_C(  13966437),  UINT32_C(   8420533),  UINT32_C(   3122956),  UINT32_C(  18154704) },
       {   UINT32_C(     17150),  UINT32_C(      7661),  UINT32_C(      7460),  UINT32_C(       577) },
       {   UINT32_C(     13649),  UINT32_C(      9057),  UINT32_C(      3959),  UINT32_C(     12619)},
           INT8_C(         1),
       {   UINT32_C(4153606183),  UINT32_C(4234002152),  UINT32_C(4230525032),  UINT32_C(  12928815) } },
     { {   UINT32_C(   3665546),  UINT32_C(   1202649),  UINT32_C(  18582276),  UINT32_C(  16796651) },
       {   UINT32_C(     14139),  UINT32_C(      7351),  UINT32_C(      1028),  UINT32_C(     13472) },
       {   UINT32_C(     16984),  UINT32_C(      8465),  UINT32_C(     10404),  UINT32_C(      9769)},
           INT8_C(         0),
       {   UINT32_C(4058496066),  UINT32_C(4171320561),  UINT32_C(   1122724),  UINT32_C(4082955499) } },
     { {   UINT32_C(   8215597),  UINT32_C(  17956728),  UINT32_C(   5061094),  UINT32_C(  14392408) },
       {   UINT32_C(      2670),  UINT32_C(      7127),  UINT32_C(      5942),  UINT32_C(     18433) },
       {   UINT32_C(      5407),  UINT32_C(     18714),  UINT32_C(     11120),  UINT32_C(      3071)},
           INT8_C(         0),
       {   UINT32_C(4288746203),  UINT32_C(4274388335),  UINT32_C(4267899996),  UINT32_C(4209692473) } },
     { {   UINT32_C(  11104270),  UINT32_C(   2711059),  UINT32_C(  11905031),  UINT32_C(   2354726) },
       {   UINT32_C(        62),  UINT32_C(     19922),  UINT32_C(     11313),  UINT32_C(     12703) },
       {   UINT32_C(      2373),  UINT32_C(     16679),  UINT32_C(     13946),  UINT32_C(     10180)},
           INT8_C(         1),
       {   UINT32_C(  10070172),  UINT32_C(3965399317),  UINT32_C(4118182800),  UINT32_C(4085448685) } },
     { {   UINT32_C(   8015728),  UINT32_C(   6058493),  UINT32_C(  18794942),  UINT32_C(  15641101) },
       {   UINT32_C(      6854),  UINT32_C(     15329),  UINT32_C(     18526),  UINT32_C(      3673) },
       {   UINT32_C(      4060),  UINT32_C(      5976),  UINT32_C(      1701),  UINT32_C(      1084)},
           INT8_C(         3),
       {   UINT32_C(    585992),  UINT32_C(4284409153),  UINT32_C(4293680054),  UINT32_C(  11659569) } },
  };

  simde_uint32x4_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_u32(test_vec[i].a);
    b = simde_vld1q_u32(test_vec[i].b);
    v = simde_vld1q_u32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlsq_laneq_u32(a, b, v, 0); break;
      case 1: r = simde_vmlsq_laneq_u32(a, b, v, 1); break;
      case 2: r = simde_vmlsq_laneq_u32(a, b, v, 2); break;
      case 3: r = simde_vmlsq_laneq_u32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_u32(0); break;
    }
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmls_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_laneq_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
