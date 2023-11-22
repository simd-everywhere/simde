
#define SIMDE_TEST_ARM_NEON_INSN mla_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mla_lane.h"

SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vmla_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[2];
    float b[2];
    float v[4];
    int8_t lane;
    float r[2];
  } test_vec[] = {
     { {   SIMDE_FLOAT32_C(    -73.46),  SIMDE_FLOAT32_C(    513.31) },
       {   SIMDE_FLOAT32_C(    859.54),  SIMDE_FLOAT32_C(    351.95) },
       {   SIMDE_FLOAT32_C(    623.37),  SIMDE_FLOAT32_C(   -773.90),  SIMDE_FLOAT32_C(    -85.33),  SIMDE_FLOAT32_C(   -870.53) },
           INT8_C(         1),
       {   SIMDE_FLOAT32_C(-665271.47),  SIMDE_FLOAT32_C(-271860.79) } },
     { {   SIMDE_FLOAT32_C(   -274.57),  SIMDE_FLOAT32_C(    808.41) },
       {   SIMDE_FLOAT32_C(    -90.97),  SIMDE_FLOAT32_C(   -714.05) },
       {   SIMDE_FLOAT32_C(   -922.73),  SIMDE_FLOAT32_C(   -411.88),  SIMDE_FLOAT32_C(    281.90),  SIMDE_FLOAT32_C(    -63.90) },
           INT8_C(         2),
       {   SIMDE_FLOAT32_C( -25919.01),  SIMDE_FLOAT32_C(-200482.28) } },
     { {   SIMDE_FLOAT32_C(   -741.09),  SIMDE_FLOAT32_C(    445.38) },
       {   SIMDE_FLOAT32_C(   -398.05),  SIMDE_FLOAT32_C(   -855.86) },
       {   SIMDE_FLOAT32_C(   -570.81),  SIMDE_FLOAT32_C(   -970.95),  SIMDE_FLOAT32_C(   -485.13),  SIMDE_FLOAT32_C(   -172.61) },
           INT8_C(         3),
       {   SIMDE_FLOAT32_C(  67966.32),  SIMDE_FLOAT32_C( 148175.37) } },
     { {   SIMDE_FLOAT32_C(     33.94),  SIMDE_FLOAT32_C(    293.45) },
       {   SIMDE_FLOAT32_C(   -588.66),  SIMDE_FLOAT32_C(    519.96) },
       {   SIMDE_FLOAT32_C(   -139.60),  SIMDE_FLOAT32_C(    433.70),  SIMDE_FLOAT32_C(    837.57),  SIMDE_FLOAT32_C(   -714.84) },
           INT8_C(         3),
       {   SIMDE_FLOAT32_C( 420831.65),  SIMDE_FLOAT32_C(-371394.76) } },
     { {   SIMDE_FLOAT32_C(   -795.09),  SIMDE_FLOAT32_C(     16.24) },
       {   SIMDE_FLOAT32_C(   -182.80),  SIMDE_FLOAT32_C(    647.98) },
       {   SIMDE_FLOAT32_C(    196.21),  SIMDE_FLOAT32_C(    269.55),  SIMDE_FLOAT32_C(    855.47),  SIMDE_FLOAT32_C(   -864.67) },
           INT8_C(         2),
       {   SIMDE_FLOAT32_C(-157175.01),  SIMDE_FLOAT32_C( 554343.69) } },
     { {   SIMDE_FLOAT32_C(   -464.62),  SIMDE_FLOAT32_C(    878.96) },
       {   SIMDE_FLOAT32_C(    482.06),  SIMDE_FLOAT32_C(   -189.13) },
       {   SIMDE_FLOAT32_C(    998.51),  SIMDE_FLOAT32_C(    249.98),  SIMDE_FLOAT32_C(   -423.89),  SIMDE_FLOAT32_C(    412.87) },
           INT8_C(         2),
       {   SIMDE_FLOAT32_C(-204805.03),  SIMDE_FLOAT32_C(  81049.28) } },
     { {   SIMDE_FLOAT32_C(   -949.96),  SIMDE_FLOAT32_C(    459.88) },
       {   SIMDE_FLOAT32_C(   -612.87),  SIMDE_FLOAT32_C(    624.30) },
       {   SIMDE_FLOAT32_C(    216.59),  SIMDE_FLOAT32_C(    639.02),  SIMDE_FLOAT32_C(   -234.22),  SIMDE_FLOAT32_C(   -127.73) },
           INT8_C(         3),
       {   SIMDE_FLOAT32_C(  77331.93),  SIMDE_FLOAT32_C( -79281.96) } },
     { {   SIMDE_FLOAT32_C(   -495.83),  SIMDE_FLOAT32_C(   -373.57) },
       {   SIMDE_FLOAT32_C(   -270.56),  SIMDE_FLOAT32_C(   -712.92) },
       {   SIMDE_FLOAT32_C(    565.27),  SIMDE_FLOAT32_C(    939.53),  SIMDE_FLOAT32_C(    228.62),  SIMDE_FLOAT32_C(   -248.99) },
           INT8_C(         1),
       {   SIMDE_FLOAT32_C(-254695.07),  SIMDE_FLOAT32_C(-670183.30) } },
  };

  simde_float32x2_t r, a, b;
  simde_float32x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    v = simde_vld1q_f32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_laneq_f32(a, b, v, 0); break;
      case 1: r = simde_vmla_laneq_f32(a, b, v, 1); break;
      case 2: r = simde_vmla_laneq_f32(a, b, v, 2); break;
      case 3: r = simde_vmla_laneq_f32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_f32(0); break;
    }
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmla_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    float a[2];
    float b[2];
    float v[2];
    int8_t lane;
    float r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -816.78), SIMDE_FLOAT32_C(  -682.00) },
      { SIMDE_FLOAT32_C(  -795.28), SIMDE_FLOAT32_C(    90.29) },
      { SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -447.42) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(102792.30), SIMDE_FLOAT32_C(-12444.98) } },
    { { SIMDE_FLOAT32_C(  -476.32), SIMDE_FLOAT32_C(   185.93) },
      { SIMDE_FLOAT32_C(   161.27), SIMDE_FLOAT32_C(   -62.08) },
      { SIMDE_FLOAT32_C(  -608.20), SIMDE_FLOAT32_C(   443.90) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-98560.74), SIMDE_FLOAT32_C( 37942.99) } },
    { { SIMDE_FLOAT32_C(   620.34), SIMDE_FLOAT32_C(   537.90) },
      { SIMDE_FLOAT32_C(  -324.75), SIMDE_FLOAT32_C(  -532.78) },
      { SIMDE_FLOAT32_C(  -706.05), SIMDE_FLOAT32_C(   656.04) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(229910.08), SIMDE_FLOAT32_C(376707.25) } },
    { { SIMDE_FLOAT32_C(   211.34), SIMDE_FLOAT32_C(   292.01) },
      { SIMDE_FLOAT32_C(   391.18), SIMDE_FLOAT32_C(  -470.30) },
      { SIMDE_FLOAT32_C(  -654.28), SIMDE_FLOAT32_C(    25.97) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( 10370.28), SIMDE_FLOAT32_C(-11921.68) } },
    { { SIMDE_FLOAT32_C(  -405.66), SIMDE_FLOAT32_C(  -583.58) },
      { SIMDE_FLOAT32_C(   -51.80), SIMDE_FLOAT32_C(  -222.44) },
      { SIMDE_FLOAT32_C(  -265.59), SIMDE_FLOAT32_C(   152.92) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( -8326.92), SIMDE_FLOAT32_C(-34599.10) } },
    { { SIMDE_FLOAT32_C(   604.13), SIMDE_FLOAT32_C(   705.50) },
      { SIMDE_FLOAT32_C(    -6.67), SIMDE_FLOAT32_C(  -872.19) },
      { SIMDE_FLOAT32_C(  -108.57), SIMDE_FLOAT32_C(  -845.39) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  6242.88), SIMDE_FLOAT32_C(738046.25) } },
    { { SIMDE_FLOAT32_C(   283.23), SIMDE_FLOAT32_C(   598.51) },
      { SIMDE_FLOAT32_C(  -945.20), SIMDE_FLOAT32_C(   -96.43) },
      { SIMDE_FLOAT32_C(   136.41), SIMDE_FLOAT32_C(  -269.94) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-128651.51), SIMDE_FLOAT32_C(-12555.51) } },
    { { SIMDE_FLOAT32_C(   430.36), SIMDE_FLOAT32_C(  -613.90) },
      { SIMDE_FLOAT32_C(   413.02), SIMDE_FLOAT32_C(  -358.30) },
      { SIMDE_FLOAT32_C(   678.10), SIMDE_FLOAT32_C(  -195.80) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(280499.22), SIMDE_FLOAT32_C(-243577.12) } },
  };

  simde_float32x2_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    v = simde_vld1_f32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_lane_f32(a, b, v, 0); break;
      case 1: r = simde_vmla_lane_f32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_f32(0); break;
    }
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t v = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_float32x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmla_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(0)), lane, a, b, v);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmla_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t v[8];
    int8_t lane;
    int16_t r[4];
  } test_vec[] = {
     { {  -INT16_C(    81), -INT16_C(    48),  INT16_C(    94),  INT16_C(    69) },
       {   INT16_C(    40), -INT16_C(    89), -INT16_C(    92),  INT16_C(    90) },
       {   INT16_C(    94),  INT16_C(    38), -INT16_C(    15), -INT16_C(    13),
          -INT16_C(    79), -INT16_C(    41), -INT16_C(    66),  INT16_C(     0) },
           INT8_C(     0),
       {   INT16_C(  3679), -INT16_C(  8414), -INT16_C(  8554),  INT16_C(  8529) } },
     { {  -INT16_C(    14), -INT16_C(    78), -INT16_C(    58), -INT16_C(    39) },
       {  -INT16_C(    85), -INT16_C(    52),  INT16_C(    85),  INT16_C(    77) },
       {   INT16_C(    76), -INT16_C(    10),  INT16_C(    26),  INT16_C(    82),
          -INT16_C(    46),  INT16_C(    48), -INT16_C(    40),  INT16_C(    93) },
           INT8_C(     6),
       {   INT16_C(  3386),  INT16_C(  2002), -INT16_C(  3458), -INT16_C(  3119) } },
     { {   INT16_C(    82), -INT16_C(    97),  INT16_C(    61),  INT16_C(    86) },
       {   INT16_C(    78), -INT16_C(    66),  INT16_C(    69), -INT16_C(    34) },
       {   INT16_C(    79), -INT16_C(    74),  INT16_C(     4), -INT16_C(    49),
           INT16_C(    22), -INT16_C(    87), -INT16_C(    48), -INT16_C(    37) },
           INT8_C(     0),
       {   INT16_C(  6244), -INT16_C(  5311),  INT16_C(  5512), -INT16_C(  2600) } },
     { {  -INT16_C(     3), -INT16_C(    26),  INT16_C(    68),  INT16_C(    10) },
       {   INT16_C(     9), -INT16_C(    39),  INT16_C(    24), -INT16_C(    13) },
       {  -INT16_C(    39), -INT16_C(    87), -INT16_C(    79),  INT16_C(    42),
          -INT16_C(    23),  INT16_C(    56), -INT16_C(    22), -INT16_C(    41) },
           INT8_C(     7),
       {  -INT16_C(   372),  INT16_C(  1573), -INT16_C(   916),  INT16_C(   543) } },
     { {   INT16_C(     0), -INT16_C(    60), -INT16_C(    14), -INT16_C(    40) },
       {  -INT16_C(    46), -INT16_C(    13),  INT16_C(    45), -INT16_C(     6) },
       {  -INT16_C(    39),  INT16_C(    97),  INT16_C(    59), -INT16_C(    65),
          -INT16_C(    22), -INT16_C(    35), -INT16_C(    62),  INT16_C(    51) },
           INT8_C(     0),
       {   INT16_C(  1794),  INT16_C(   447), -INT16_C(  1769),  INT16_C(   194) } },
     { {  -INT16_C(    72),  INT16_C(    43),  INT16_C(     0), -INT16_C(    15) },
       {  -INT16_C(    96),  INT16_C(    98), -INT16_C(     5),  INT16_C(    88) },
       {   INT16_C(    70),  INT16_C(    21), -INT16_C(    54), -INT16_C(    29),
           INT16_C(    83),  INT16_C(    62),  INT16_C(     7), -INT16_C(     7) },
           INT8_C(     7),
       {   INT16_C(   600), -INT16_C(   643),  INT16_C(    35), -INT16_C(   631) } },
     { {  -INT16_C(    57), -INT16_C(    65),  INT16_C(    87),  INT16_C(    11) },
       {  -INT16_C(    36), -INT16_C(    26),  INT16_C(    46),  INT16_C(    29) },
       {  -INT16_C(    82),  INT16_C(    96),  INT16_C(    14),  INT16_C(    54),
          -INT16_C(    42),  INT16_C(     5), -INT16_C(    47), -INT16_C(    37) },
           INT8_C(     5),
       {  -INT16_C(   237), -INT16_C(   195),  INT16_C(   317),  INT16_C(   156) } },
     { {   INT16_C(    46), -INT16_C(    88), -INT16_C(    14), -INT16_C(    73) },
       {  -INT16_C(    12),  INT16_C(    31),  INT16_C(     0), -INT16_C(    48) },
       {  -INT16_C(    96), -INT16_C(    87), -INT16_C(    55), -INT16_C(    93),
          -INT16_C(    55), -INT16_C(    34),  INT16_C(    63),  INT16_C(    65) },
           INT8_C(     1),
       {   INT16_C(  1090), -INT16_C(  2785), -INT16_C(    14),  INT16_C(  4103) } },
  };

  simde_int16x4_t r, a, b;
  simde_int16x8_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_s16(test_vec[i].a);
    b = simde_vld1_s16(test_vec[i].b);
    v = simde_vld1q_s16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vmla_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vmla_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vmla_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vmla_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vmla_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vmla_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vmla_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_s16(0); break;
    }
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t v[4];
    int8_t lane;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  8363),  INT16_C( 18244),  INT16_C(  7549), -INT16_C( 29838) },
      { -INT16_C(  3227),  INT16_C( 11543), -INT16_C( 29487),  INT16_C(  4163) },
      {  INT16_C( 10620),  INT16_C( 22760), -INT16_C( 28728),  INT16_C( 11437) },
      INT8_C(   2),
      {  INT16_C( 28989),  INT16_C( 23100), -INT16_C(  8251), -INT16_C( 21302) } },
    { {  INT16_C( 22862),  INT16_C( 28944),  INT16_C( 22233), -INT16_C( 17978) },
      {  INT16_C(  3739), -INT16_C( 18378), -INT16_C( 16000),  INT16_C( 29469) },
      {  INT16_C( 19160),  INT16_C( 25668),  INT16_C( 21646), -INT16_C( 18463) },
      INT8_C(   0),
      {  INT16_C( 31254),  INT16_C( 31392), -INT16_C( 25895),  INT16_C( 15422) } },
    { {  INT16_C( 32569), -INT16_C(  6453),  INT16_C( 24235),  INT16_C(  1076) },
      { -INT16_C( 22930), -INT16_C( 15138), -INT16_C( 26772),  INT16_C( 31327) },
      {  INT16_C(  6093), -INT16_C( 28934),  INT16_C( 27956),  INT16_C( 32615) },
      INT8_C(   1),
      {  INT16_C(  2725),  INT16_C( 19351),  INT16_C(  9763),  INT16_C( 14074) } },
    { {  INT16_C(  3531), -INT16_C( 21498),  INT16_C( 17092),  INT16_C( 17382) },
      { -INT16_C( 13298),  INT16_C( 27886), -INT16_C(  3327), -INT16_C( 22566) },
      { -INT16_C( 24879),  INT16_C( 26643), -INT16_C( 28930),  INT16_C(  5429) },
      INT8_C(   0),
      {  INT16_C( 18745),  INT16_C( 32340),  INT16_C( 17557), -INT16_C( 10016) } },
    { {  INT16_C( 19139),  INT16_C( 10998), -INT16_C( 22583), -INT16_C( 10506) },
      { -INT16_C( 23891), -INT16_C(  3942), -INT16_C(  8824),  INT16_C( 22014) },
      {  INT16_C( 27339), -INT16_C( 16810), -INT16_C(   700), -INT16_C(  7537) },
      INT8_C(   0),
      { -INT16_C(  5134), -INT16_C( 18156), -INT16_C( 23903),  INT16_C( 13152) } },
    { { -INT16_C(  7945),  INT16_C( 11422),  INT16_C( 10230),  INT16_C( 16624) },
      {  INT16_C(  6685), -INT16_C( 15351), -INT16_C(  8432), -INT16_C( 19598) },
      {  INT16_C( 25209),  INT16_C( 22075), -INT16_C( 28576), -INT16_C( 13791) },
      INT8_C(   2),
      { -INT16_C(  1065), -INT16_C( 16386), -INT16_C( 12810), -INT16_C( 21584) } },
    { {  INT16_C(  3808),  INT16_C( 28643), -INT16_C(  2832), -INT16_C( 11929) },
      { -INT16_C( 27758), -INT16_C( 17977),  INT16_C(  1923), -INT16_C( 24874) },
      { -INT16_C( 25840), -INT16_C(  4178),  INT16_C( 24845),  INT16_C( 28520) },
      INT8_C(   1),
      { -INT16_C( 21988),  INT16_C( 32293),  INT16_C( 23802), -INT16_C( 28453) } },
    { { -INT16_C( 12354), -INT16_C(  8403),  INT16_C(  5273), -INT16_C( 22593) },
      {  INT16_C( 12279), -INT16_C(  5225),  INT16_C( 26774),  INT16_C( 10622) },
      {  INT16_C( 14127),  INT16_C( 13997),  INT16_C( 19214), -INT16_C( 22202) },
      INT8_C(   1),
      {  INT16_C( 21417), -INT16_C(  4552),  INT16_C( 26103),  INT16_C( 17893) } },
  };

  simde_int16x4_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_s16(test_vec[i].a);
    b = simde_vld1_s16(test_vec[i].b);
    v = simde_vld1_s16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vmla_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vmla_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vmla_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_s16(0); break;
    }
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_int16x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmla_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(0)), lane, a, b, v);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmla_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t v[4];
    int8_t lane;
    int32_t r[2];
  } test_vec[] = {
     { {   INT32_C(     3861),  INT32_C(     5159) },
       {   INT32_C(     9760), -INT32_C(     3715) },
       {  -INT32_C(     9595), -INT32_C(     2488),  INT32_C(     4866), -INT32_C(     5704) },
           INT8_C(        2),
       {   INT32_C( 47496021), -INT32_C( 18072031) } },
     { {   INT32_C(     5007), -INT32_C(     7329) },
       {  -INT32_C(     6236),  INT32_C(     6988) },
       {  -INT32_C(      612),  INT32_C(     5079), -INT32_C(     8538), -INT32_C(     3459) },
           INT8_C(        1),
       {  -INT32_C( 31667637),  INT32_C( 35484723) } },
     { {   INT32_C(     1305), -INT32_C(       87) },
       {  -INT32_C(     3936),  INT32_C(     9528) },
       {   INT32_C(     7150), -INT32_C(      961),  INT32_C(     3279), -INT32_C(     1449) },
           INT8_C(        1),
       {   INT32_C(  3783801), -INT32_C(  9156495) } },
     { {  -INT32_C(     1929), -INT32_C(     1565) },
       {   INT32_C(     3306), -INT32_C(     8150) },
       {  -INT32_C(     4113), -INT32_C(     7811), -INT32_C(     7275),  INT32_C(     2429) },
           INT8_C(        2),
       {  -INT32_C( 24053079),  INT32_C( 59289685) } },
     { {   INT32_C(     3468),  INT32_C(     5295) },
       {   INT32_C(     1666), -INT32_C(     3947) },
       {   INT32_C(     6721), -INT32_C(     1160),  INT32_C(     6628),  INT32_C(     2152) },
           INT8_C(        0),
       {   INT32_C( 11200654), -INT32_C( 26522492) } },
     { {   INT32_C(     4696),  INT32_C(      717) },
       {  -INT32_C(     7531), -INT32_C(     1614) },
       {   INT32_C(      129), -INT32_C(     7076), -INT32_C(     1025), -INT32_C(     5723) },
           INT8_C(        3),
       {   INT32_C( 43104609),  INT32_C(  9237639) } },
     { {  -INT32_C(      764),  INT32_C(      296) },
       {  -INT32_C(     8065),  INT32_C(     1700) },
       {   INT32_C(     8396), -INT32_C(       25),  INT32_C(     6189),  INT32_C(     6350) },
           INT8_C(        3),
       {  -INT32_C( 51213514),  INT32_C( 10795296) } },
     { {  -INT32_C(     9807), -INT32_C(     6609) },
       {  -INT32_C(     9863),  INT32_C(     1251) },
       {   INT32_C(     5518),  INT32_C(     9557), -INT32_C(     3314), -INT32_C(     1340) },
           INT8_C(        1),
       {  -INT32_C( 94270498),  INT32_C( 11949198) } },
  };

  simde_int32x2_t r, a, b;
  simde_int32x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_s32(test_vec[i].a);
    b = simde_vld1_s32(test_vec[i].b);
    v = simde_vld1q_s32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vmla_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vmla_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vmla_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_s32(0); break;
    }
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t v[2];
    int8_t lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1677892667), -INT32_C(   731162875) },
      {  INT32_C(  1367126076), -INT32_C(   980313240) },
      {  INT32_C(  1778607037),  INT32_C(  1770572205) },
       INT8_C(   1),
      { -INT32_C(   813721519), -INT32_C(   501873587) } },
    { { -INT32_C(   513060676),  INT32_C(   681990085) },
      { -INT32_C(  1423097516),  INT32_C(  1575485869) },
      {  INT32_C(   432355710),  INT32_C(   785877963) },
       INT8_C(   0),
      { -INT32_C(  1360974828),  INT32_C(   945270763) } },
    { { -INT32_C(   916923583), -INT32_C(  1803214012) },
      { -INT32_C(   447125618),  INT32_C(  1329168909) },
      { -INT32_C(  1308826193),  INT32_C(   103766477) },
       INT8_C(   0),
      { -INT32_C(  1461671085),  INT32_C(   804694823) } },
    { {  INT32_C(   531222856), -INT32_C(   614450945) },
      { -INT32_C(  1289803120),  INT32_C(   373470383) },
      { -INT32_C(  1893456115),  INT32_C(  1178563425) },
       INT8_C(   1),
      { -INT32_C(   670588456), -INT32_C(  1830663090) } },
    { {  INT32_C(   533206000), -INT32_C(   345512423) },
      { -INT32_C(   924153968),  INT32_C(   291030503) },
      { -INT32_C(  1715401755),  INT32_C(  1973868365) },
       INT8_C(   1),
      {  INT32_C(  1032636992), -INT32_C(  1743098476) } },
    { {  INT32_C(  1970198070),  INT32_C(   795204892) },
      { -INT32_C(  1941404507),  INT32_C(  1914450923) },
      { -INT32_C(   480582626),  INT32_C(  1204316988) },
       INT8_C(   0),
      {  INT32_C(  1829983628),  INT32_C(  1318010534) } },
    { {  INT32_C(   134518113), -INT32_C(   532742390) },
      {  INT32_C(  1274852206), -INT32_C(  1661916392) },
      { -INT32_C(  1484292749),  INT32_C(  2110126745) },
       INT8_C(   0),
      { -INT32_C(   282597941), -INT32_C(  2075651374) } },
    { {  INT32_C(  1908390312), -INT32_C(  1781339136) },
      { -INT32_C(   274736400), -INT32_C(   883065064) },
      { -INT32_C(  1495029381),  INT32_C(   387612570) },
       INT8_C(   1),
      { -INT32_C(  1310294520),  INT32_C(  1586382960) } },

  };

  simde_int32x2_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_s32(test_vec[i].a);
    b = simde_vld1_s32(test_vec[i].b);
    v = simde_vld1_s32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vmla_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_s32(0); break;
    }
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_int32x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmla_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(0)), lane, a, b, v);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmla_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t v[8];
    int8_t lane;
    uint16_t r[4];
  } test_vec[] = {
     { {   UINT16_C(   144),  UINT16_C(    34),  UINT16_C(    24),  UINT16_C(    53) },
       {   UINT16_C(   114),  UINT16_C(   151),  UINT16_C(   196),  UINT16_C(   168) },
       {   UINT16_C(     9),  UINT16_C(   121),  UINT16_C(    98),  UINT16_C(    37),
           UINT16_C(    85),  UINT16_C(   143),  UINT16_C(   114),  UINT16_C(    77) },
           INT8_C(     7),
       {   UINT16_C(  8922),  UINT16_C( 11661),  UINT16_C( 15116),  UINT16_C( 12989) } },
     { {   UINT16_C(    46),  UINT16_C(    26),  UINT16_C(   172),  UINT16_C(   157) },
       {   UINT16_C(   130),  UINT16_C(    10),  UINT16_C(    72),  UINT16_C(   144) },
       {   UINT16_C(    79),  UINT16_C(    48),  UINT16_C(    31),  UINT16_C(    47),
           UINT16_C(   141),  UINT16_C(    75),  UINT16_C(    11),  UINT16_C(     0) },
           INT8_C(     4),
       {   UINT16_C( 18376),  UINT16_C(  1436),  UINT16_C( 10324),  UINT16_C( 20461) } },
     { {   UINT16_C(    66),  UINT16_C(   115),  UINT16_C(    17),  UINT16_C(   182) },
       {   UINT16_C(   171),  UINT16_C(    62),  UINT16_C(    79),  UINT16_C(   160) },
       {   UINT16_C(   149),  UINT16_C(   107),  UINT16_C(    55),  UINT16_C(   109),
           UINT16_C(   135),  UINT16_C(   105),  UINT16_C(   116),  UINT16_C(    12) },
           INT8_C(     6),
       {   UINT16_C( 19902),  UINT16_C(  7307),  UINT16_C(  9181),  UINT16_C( 18742) } },
     { {   UINT16_C(   162),  UINT16_C(    21),  UINT16_C(   179),  UINT16_C(   140) },
       {   UINT16_C(   116),  UINT16_C(   164),  UINT16_C(   124),  UINT16_C(   121) },
       {   UINT16_C(    70),  UINT16_C(     9),  UINT16_C(   107),  UINT16_C(   156),
           UINT16_C(   122),  UINT16_C(   174),  UINT16_C(    56),  UINT16_C(   136) },
           INT8_C(     4),
       {   UINT16_C( 14314),  UINT16_C( 20029),  UINT16_C( 15307),  UINT16_C( 14902) } },
     { {   UINT16_C(   156),  UINT16_C(    33),  UINT16_C(   163),  UINT16_C(   127) },
       {   UINT16_C(    32),  UINT16_C(    12),  UINT16_C(    90),  UINT16_C(    82) },
       {   UINT16_C(    97),  UINT16_C(   190),  UINT16_C(     0),  UINT16_C(    43),
           UINT16_C(    37),  UINT16_C(    42),  UINT16_C(    81),  UINT16_C(   151) },
           INT8_C(     6),
       {   UINT16_C(  2748),  UINT16_C(  1005),  UINT16_C(  7453),  UINT16_C(  6769) } },
     { {   UINT16_C(    86),  UINT16_C(    68),  UINT16_C(   183),  UINT16_C(   186) },
       {   UINT16_C(     7),  UINT16_C(   118),  UINT16_C(   191),  UINT16_C(    83) },
       {   UINT16_C(   139),  UINT16_C(   109),  UINT16_C(   165),  UINT16_C(   138),
           UINT16_C(    63),  UINT16_C(   145),  UINT16_C(   122),  UINT16_C(   104) },
           INT8_C(     5),
       {   UINT16_C(  1101),  UINT16_C( 17178),  UINT16_C( 27878),  UINT16_C( 12221) } },
     { {   UINT16_C(    66),  UINT16_C(   140),  UINT16_C(   133),  UINT16_C(   129) },
       {   UINT16_C(   164),  UINT16_C(    44),  UINT16_C(    50),  UINT16_C(     9) },
       {   UINT16_C(     4),  UINT16_C(    13),  UINT16_C(   156),  UINT16_C(   115),
           UINT16_C(    28),  UINT16_C(     5),  UINT16_C(    57),  UINT16_C(   186) },
           INT8_C(     5),
       {   UINT16_C(   886),  UINT16_C(   360),  UINT16_C(   383),  UINT16_C(   174) } },
     { {   UINT16_C(   147),  UINT16_C(     6),  UINT16_C(    29),  UINT16_C(    23) },
       {   UINT16_C(   196),  UINT16_C(   120),  UINT16_C(    91),  UINT16_C(   101) },
       {   UINT16_C(   183),  UINT16_C(   144),  UINT16_C(    66),  UINT16_C(    70),
           UINT16_C(   187),  UINT16_C(   197),  UINT16_C(   140),  UINT16_C(   144) },
           INT8_C(     6),
       {   UINT16_C( 27587),  UINT16_C( 16806),  UINT16_C( 12769),  UINT16_C( 14163) } },
  };

  simde_uint16x4_t r, a, b;
  simde_uint16x8_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_u16(test_vec[i].a);
    b = simde_vld1_u16(test_vec[i].b);
    v = simde_vld1q_u16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_laneq_u16(a, b, v, 0); break;
      case 1: r = simde_vmla_laneq_u16(a, b, v, 1); break;
      case 2: r = simde_vmla_laneq_u16(a, b, v, 2); break;
      case 3: r = simde_vmla_laneq_u16(a, b, v, 3); break;
      case 4: r = simde_vmla_laneq_u16(a, b, v, 4); break;
      case 5: r = simde_vmla_laneq_u16(a, b, v, 5); break;
      case 6: r = simde_vmla_laneq_u16(a, b, v, 6); break;
      case 7: r = simde_vmla_laneq_u16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_u16(0); break;
    }
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t v[4];
    int8_t lane;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(24938), UINT16_C(12997), UINT16_C(36716), UINT16_C(45604) },
      { UINT16_C(53368), UINT16_C(42594), UINT16_C(35304), UINT16_C(54457) },
      { UINT16_C(16938), UINT16_C(21817), UINT16_C(27865), UINT16_C( 3610) },
       INT8_C(   0),
      { UINT16_C(34074), UINT16_C(49881), UINT16_C(65404), UINT16_C(19070) } },
    { { UINT16_C(12202), UINT16_C(60429), UINT16_C(63791), UINT16_C(36950) },
      { UINT16_C(35006), UINT16_C(19964), UINT16_C(44972), UINT16_C(31941) },
      { UINT16_C(27409), UINT16_C(39524), UINT16_C(14628), UINT16_C(26564) },
       INT8_C(   2),
      { UINT16_C(47202), UINT16_C(65405), UINT16_C(63839), UINT16_C(63754) } },
    { { UINT16_C(16409), UINT16_C(13535), UINT16_C( 8014), UINT16_C(32222) },
      { UINT16_C(51756), UINT16_C( 9644), UINT16_C(15392), UINT16_C(43491) },
      { UINT16_C(12345), UINT16_C(59477), UINT16_C(54005), UINT16_C(24825) },
       INT8_C(   2),
      { UINT16_C(54325), UINT16_C(23163), UINT16_C(59886), UINT16_C(18973) } },
    { { UINT16_C(34195), UINT16_C(22383), UINT16_C(58092), UINT16_C(11377) },
      { UINT16_C(42433), UINT16_C(57467), UINT16_C(63619), UINT16_C(19725) },
      { UINT16_C(12965), UINT16_C(57709), UINT16_C( 5654), UINT16_C(17946) },
       INT8_C(   0),
      { UINT16_C( 3320), UINT16_C( 3254), UINT16_C(42331), UINT16_C(24530) } },
    { { UINT16_C(15362), UINT16_C(64318), UINT16_C(29852), UINT16_C( 8590) },
      { UINT16_C(59108), UINT16_C(50701), UINT16_C(14935), UINT16_C(64647) },
      { UINT16_C(26549), UINT16_C(44415), UINT16_C(52340), UINT16_C(42834) },
       INT8_C(   1),
      { UINT16_C(56094), UINT16_C( 1201), UINT16_C(12485), UINT16_C(41863) } },
    { { UINT16_C(48436), UINT16_C(20048), UINT16_C(48131), UINT16_C(16209) },
      { UINT16_C(19706), UINT16_C(28380), UINT16_C(64987), UINT16_C(49490) },
      { UINT16_C( 6155), UINT16_C(17688), UINT16_C( 5279), UINT16_C( 2042) },
       INT8_C(   3),
      { UINT16_C(48984), UINT16_C(38184), UINT16_C(41185), UINT16_C(18277) } },
    { { UINT16_C(31655), UINT16_C(64095), UINT16_C(38946), UINT16_C(57134) },
      { UINT16_C(31976), UINT16_C(42211), UINT16_C( 8909), UINT16_C( 6814) },
      { UINT16_C( 3582), UINT16_C(64757), UINT16_C(46687), UINT16_C(30727) },
       INT8_C(   2),
      { UINT16_C(50623), UINT16_C(35996), UINT16_C(16437), UINT16_C( 5072) } },
    { { UINT16_C( 5964), UINT16_C(18146), UINT16_C(29982), UINT16_C(39661) },
      { UINT16_C(59348), UINT16_C(27836), UINT16_C(39957), UINT16_C(37461) },
      { UINT16_C(63871), UINT16_C(41311), UINT16_C(31128), UINT16_C(42400) },
       INT8_C(   2),
      { UINT16_C(61740), UINT16_C(45698), UINT16_C( 3734), UINT16_C(43621) } },
  };

  simde_uint16x4_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_u16(test_vec[i].a);
    b = simde_vld1_u16(test_vec[i].b);
    v = simde_vld1_u16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_lane_u16(a, b, v, 0); break;
      case 1: r = simde_vmla_lane_u16(a, b, v, 1); break;
      case 2: r = simde_vmla_lane_u16(a, b, v, 2); break;
      case 3: r = simde_vmla_lane_u16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_u16(0); break;
    }
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t v = simde_test_arm_neon_random_u16x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_uint16x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmla_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(0)), lane, a, b, v);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmla_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t v[4];
    int8_t lane;
    uint32_t r[2];
  } test_vec[] = {
     { {   UINT32_C(      779),  UINT32_C(     9897) },
       {   UINT32_C(    19930),  UINT32_C(     9507) },
       {   UINT32_C(     6030),  UINT32_C(    14920),  UINT32_C(      631),  UINT32_C(     3218) },
           INT8_C(        0),
       {   UINT32_C(120178679),  UINT32_C( 57337107) } },
     { {   UINT32_C(     7008),  UINT32_C(    13810) },
       {   UINT32_C(     4541),  UINT32_C(     1104) },
       {   UINT32_C(    14960),  UINT32_C(     1169),  UINT32_C(    14367),  UINT32_C(    15281) },
           INT8_C(        1),
       {   UINT32_C(  5315437),  UINT32_C(  1304386) } },
     { {   UINT32_C(    19257),  UINT32_C(     3056) },
       {   UINT32_C(     3291),  UINT32_C(     3783) },
       {   UINT32_C(     7597),  UINT32_C(    18771),  UINT32_C(     5171),  UINT32_C(     7806) },
           INT8_C(        0),
       {   UINT32_C( 25020984),  UINT32_C( 28742507) } },
     { {   UINT32_C(    14218),  UINT32_C(    15283) },
       {   UINT32_C(    17057),  UINT32_C(    19454) },
       {   UINT32_C(    18483),  UINT32_C(    19832),  UINT32_C(    11066),  UINT32_C(     2085) },
           INT8_C(        3),
       {   UINT32_C( 35578063),  UINT32_C( 40576873) } },
     { {   UINT32_C(    19077),  UINT32_C(      672) },
       {   UINT32_C(    13358),  UINT32_C(     7702) },
       {   UINT32_C(      305),  UINT32_C(    13216),  UINT32_C(    15048),  UINT32_C(    13974) },
           INT8_C(        0),
       {   UINT32_C(  4093267),  UINT32_C(  2349782) } },
     { {   UINT32_C(    12243),  UINT32_C(     2054) },
       {   UINT32_C(    15731),  UINT32_C(    15822) },
       {   UINT32_C(    13246),  UINT32_C(     4996),  UINT32_C(    14773),  UINT32_C(    18150) },
           INT8_C(        1),
       {   UINT32_C( 78604319),  UINT32_C( 79048766) } },
     { {   UINT32_C(    16357),  UINT32_C(    12567) },
       {   UINT32_C(    10743),  UINT32_C(      126) },
       {   UINT32_C(    14907),  UINT32_C(     9502),  UINT32_C(     2633),  UINT32_C(     4175) },
           INT8_C(        2),
       {   UINT32_C( 28302676),  UINT32_C(   344325) } },
     { {   UINT32_C(    18517),  UINT32_C(    19015) },
       {   UINT32_C(    12624),  UINT32_C(     4257) },
       {   UINT32_C(    17459),  UINT32_C(    18980),  UINT32_C(    11775),  UINT32_C(    17522) },
           INT8_C(        3),
       {   UINT32_C(221216245),  UINT32_C( 74610169) } },
  };

  simde_uint32x2_t r, a, b;
  simde_uint32x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_u32(test_vec[i].a);
    b = simde_vld1_u32(test_vec[i].b);
    v = simde_vld1q_u32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_laneq_u32(a, b, v, 0); break;
      case 1: r = simde_vmla_laneq_u32(a, b, v, 1); break;
      case 2: r = simde_vmla_laneq_u32(a, b, v, 2); break;
      case 3: r = simde_vmla_laneq_u32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_u32(0); break;
    }
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t v[2];
    int8_t lane;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2312484602), UINT32_C(3397139468) },
      { UINT32_C( 730399489), UINT32_C(3125101749) },
      { UINT32_C(2008462712), UINT32_C(2806817902) },
       INT8_C(   1),
      { UINT32_C(2414716264), UINT32_C(2902439378) } },
    { { UINT32_C(1555760104), UINT32_C(2975213307) },
      { UINT32_C( 952033531), UINT32_C(1597605980) },
      { UINT32_C(1444176914), UINT32_C(1607388842) },
       INT8_C(   1),
      { UINT32_C(3548406934), UINT32_C( 390904851) } },
    { { UINT32_C(2435435845), UINT32_C(2004534388) },
      { UINT32_C(2792543872), UINT32_C( 228664365) },
      { UINT32_C(1785321954), UINT32_C(2004666643) },
       INT8_C(   1),
      { UINT32_C(2082093253), UINT32_C(1889781963) } },
    { { UINT32_C(2695635410), UINT32_C(1306866048) },
      { UINT32_C( 532772698), UINT32_C(3349101041) },
      { UINT32_C(3488892331), UINT32_C(3232825830) },
       INT8_C(   1),
      { UINT32_C(4012816046), UINT32_C( 365834502) } },
    { { UINT32_C(2553598748), UINT32_C(1818956106) },
      { UINT32_C(4008446909), UINT32_C(1749629681) },
      { UINT32_C( 878274811), UINT32_C(1289756679) },
       INT8_C(   1),
      { UINT32_C(  58770759), UINT32_C(2359938529) } },
    { { UINT32_C(1628844719), UINT32_C(3313336818) },
      { UINT32_C(3339720117), UINT32_C(2357492864) },
      { UINT32_C(2726130536), UINT32_C( 614393276) },
       INT8_C(   0),
      { UINT32_C(2629849911), UINT32_C( 700290546) } },
    { { UINT32_C(2992516050), UINT32_C(2841801591) },
      { UINT32_C( 194823050), UINT32_C(1438736704) },
      { UINT32_C(3990259825), UINT32_C(2136367628) },
       INT8_C(   1),
      { UINT32_C(1726884426), UINT32_C( 556630647) } },
    { { UINT32_C(2529442808), UINT32_C(2322137695) },
      { UINT32_C(3556842336), UINT32_C(1079946109) },
      { UINT32_C(2826987847), UINT32_C(2988103210) },
       INT8_C(   0),
      { UINT32_C(2269983640), UINT32_C(4286633738) } },
  };

  simde_uint32x2_t r, a, b, v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1_u32(test_vec[i].a);
    b = simde_vld1_u32(test_vec[i].b);
    v = simde_vld1_u32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmla_lane_u32(a, b, v, 0); break;
      case 1: r = simde_vmla_lane_u32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdup_n_u32(0); break;
    }
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t v = simde_test_arm_neon_random_u32x2();
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_uint32x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmla_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(0)), lane, a, b, v);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    float a[4];
    float b[4];
    float v[2];
    int8_t lane;
    float r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   648.31), SIMDE_FLOAT32_C(   897.29), SIMDE_FLOAT32_C(  -773.49), SIMDE_FLOAT32_C(   917.71) },
      { SIMDE_FLOAT32_C(  -138.23), SIMDE_FLOAT32_C(  -297.76), SIMDE_FLOAT32_C(   935.07), SIMDE_FLOAT32_C(  -483.60) },
      { SIMDE_FLOAT32_C(  -953.66), SIMDE_FLOAT32_C(   360.53) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(132472.72), SIMDE_FLOAT32_C(284859.09), SIMDE_FLOAT32_C(-892512.31), SIMDE_FLOAT32_C(462107.69) } },
    { { SIMDE_FLOAT32_C(  -713.70), SIMDE_FLOAT32_C(    72.02), SIMDE_FLOAT32_C(   505.39), SIMDE_FLOAT32_C(  -410.47) },
      { SIMDE_FLOAT32_C(   842.08), SIMDE_FLOAT32_C(   986.12), SIMDE_FLOAT32_C(  -506.67), SIMDE_FLOAT32_C(  -516.98) },
      { SIMDE_FLOAT32_C(   668.61), SIMDE_FLOAT32_C(   247.66) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(562309.44), SIMDE_FLOAT32_C(659401.69), SIMDE_FLOAT32_C(-338259.25), SIMDE_FLOAT32_C(-346068.44) } },
    { { SIMDE_FLOAT32_C(  -476.42), SIMDE_FLOAT32_C(  -326.08), SIMDE_FLOAT32_C(  -377.79), SIMDE_FLOAT32_C(   139.47) },
      { SIMDE_FLOAT32_C(  -585.78), SIMDE_FLOAT32_C(   724.87), SIMDE_FLOAT32_C(   305.39), SIMDE_FLOAT32_C(  -586.36) },
      { SIMDE_FLOAT32_C(   533.91), SIMDE_FLOAT32_C(   -46.30) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-313230.22), SIMDE_FLOAT32_C(386689.22), SIMDE_FLOAT32_C(162672.98), SIMDE_FLOAT32_C(-312923.97) } },
    { { SIMDE_FLOAT32_C(   760.42), SIMDE_FLOAT32_C(  -128.59), SIMDE_FLOAT32_C(   172.70), SIMDE_FLOAT32_C(  -537.34) },
      { SIMDE_FLOAT32_C(  -193.52), SIMDE_FLOAT32_C(   689.10), SIMDE_FLOAT32_C(  -491.00), SIMDE_FLOAT32_C(  -832.99) },
      { SIMDE_FLOAT32_C(   327.17), SIMDE_FLOAT32_C(  -204.71) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( 40375.90), SIMDE_FLOAT32_C(-141194.25), SIMDE_FLOAT32_C(100685.32), SIMDE_FLOAT32_C(169984.05) } },
    { { SIMDE_FLOAT32_C(  -167.44), SIMDE_FLOAT32_C(   384.82), SIMDE_FLOAT32_C(    81.12), SIMDE_FLOAT32_C(  -181.32) },
      { SIMDE_FLOAT32_C(   878.15), SIMDE_FLOAT32_C(   564.14), SIMDE_FLOAT32_C(  -512.72), SIMDE_FLOAT32_C(   125.81) },
      { SIMDE_FLOAT32_C(  -390.39), SIMDE_FLOAT32_C(    10.87) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-342988.44), SIMDE_FLOAT32_C(-219849.81), SIMDE_FLOAT32_C(200241.88), SIMDE_FLOAT32_C(-49296.29) } },
    { { SIMDE_FLOAT32_C(   231.82), SIMDE_FLOAT32_C(  -849.67), SIMDE_FLOAT32_C(  -786.05), SIMDE_FLOAT32_C(   -43.32) },
      { SIMDE_FLOAT32_C(   455.72), SIMDE_FLOAT32_C(  -372.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -590.58) },
      { SIMDE_FLOAT32_C(   -61.48), SIMDE_FLOAT32_C(  -748.99) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-27785.85), SIMDE_FLOAT32_C( 22046.10), SIMDE_FLOAT32_C( 30532.48), SIMDE_FLOAT32_C( 36265.54) } },
    { { SIMDE_FLOAT32_C(  -888.78), SIMDE_FLOAT32_C(  -286.33), SIMDE_FLOAT32_C(  -912.68), SIMDE_FLOAT32_C(   800.32) },
      { SIMDE_FLOAT32_C(   222.67), SIMDE_FLOAT32_C(  -745.67), SIMDE_FLOAT32_C(   127.49), SIMDE_FLOAT32_C(  -982.04) },
      { SIMDE_FLOAT32_C(   493.37), SIMDE_FLOAT32_C(   960.04) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(108969.91), SIMDE_FLOAT32_C(-368177.53), SIMDE_FLOAT32_C( 61987.06), SIMDE_FLOAT32_C(-483708.75) } },
    { { SIMDE_FLOAT32_C(  -425.51), SIMDE_FLOAT32_C(  -221.28), SIMDE_FLOAT32_C(   280.93), SIMDE_FLOAT32_C(  -861.37) },
      { SIMDE_FLOAT32_C(   266.00), SIMDE_FLOAT32_C(  -593.26), SIMDE_FLOAT32_C(  -251.76), SIMDE_FLOAT32_C(  -723.13) },
      { SIMDE_FLOAT32_C(  -793.53), SIMDE_FLOAT32_C(   980.05) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(260267.78), SIMDE_FLOAT32_C(-581645.69), SIMDE_FLOAT32_C(-246456.44), SIMDE_FLOAT32_C(-709564.94) } },
  };

  simde_float32x4_t r, a, b;
  simde_float32x2_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_f32(test_vec[i].a);
    b = simde_vld1q_f32(test_vec[i].b);
    v = simde_vld1_f32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_lane_f32(a, b, v, 0); break;
      case 1: r = simde_vmlaq_lane_f32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_f32(0); break;
    }
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t v = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_float32x4_t r;

    SIMDE_CONSTIFY_2_(simde_vmlaq_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(0)), lane, a, b, v);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t v[4];
    int8_t lane;
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 28467), -INT16_C(  7305), -INT16_C( 26990), -INT16_C( 25666), -INT16_C( 14573), -INT16_C( 10172),  INT16_C( 16657),  INT16_C( 13285) },
      {  INT16_C( 31301),  INT16_C( 32005), -INT16_C( 17012), -INT16_C( 28293),  INT16_C( 23125), -INT16_C( 32259),  INT16_C( 14073),  INT16_C( 11642) },
      { -INT16_C(  3675),  INT16_C( 14352), -INT16_C( 12665), -INT16_C( 25901) },
       INT8_C(   2),
      {  INT16_C( 28566), -INT16_C( 10470),  INT16_C( 13158),  INT16_C( 19867), -INT16_C( 12314), -INT16_C(  1361), -INT16_C( 25504),  INT16_C( 23355) } },
    { {  INT16_C( 29207),  INT16_C( 22695), -INT16_C(  9385), -INT16_C( 11875),  INT16_C(  7136), -INT16_C( 25250), -INT16_C(  4202), -INT16_C(  3597) },
      {  INT16_C( 29932),  INT16_C(  8938),  INT16_C(  6126), -INT16_C(  8248),  INT16_C(    40), -INT16_C(  2458),  INT16_C(   211), -INT16_C(  5492) },
      {  INT16_C( 13426), -INT16_C( 14014), -INT16_C(  8177), -INT16_C(  4198) },
       INT8_C(   3),
      {  INT16_C(  7183), -INT16_C( 12437),  INT16_C( 29315),  INT16_C( 10221), -INT16_C( 29712),  INT16_C(  4282),  INT16_C( 27524), -INT16_C( 16853) } },
    { { -INT16_C( 29448), -INT16_C(  5999), -INT16_C( 32129), -INT16_C(  3116), -INT16_C(  2195), -INT16_C( 31519), -INT16_C( 16193), -INT16_C( 16468) },
      { -INT16_C( 23770),  INT16_C(  9874),  INT16_C( 31791),  INT16_C( 25496),  INT16_C( 25022), -INT16_C( 24974),  INT16_C( 25084), -INT16_C(  2919) },
      {  INT16_C( 11246),  INT16_C( 28124), -INT16_C( 20051),  INT16_C(  6753) },
       INT8_C(   0),
      { -INT16_C( 25524),  INT16_C( 19021), -INT16_C(  9423),  INT16_C(  4900), -INT16_C( 16367), -INT16_C(  1827),  INT16_C( 11527), -INT16_C( 10006) } },
    { { -INT16_C( 24766),  INT16_C(   871),  INT16_C(  9803), -INT16_C(  4567),  INT16_C( 20664),  INT16_C( 13342), -INT16_C( 32280),  INT16_C( 19186) },
      { -INT16_C( 28172),  INT16_C( 21830),  INT16_C( 14890),  INT16_C( 21827), -INT16_C( 20201), -INT16_C( 14333),  INT16_C(  7442),  INT16_C( 21616) },
      { -INT16_C( 10308),  INT16_C(  2135), -INT16_C( 32259), -INT16_C( 18954) },
       INT8_C(   1),
      { -INT16_C(  9938),  INT16_C( 11825),  INT16_C( 14993), -INT16_C(    18),  INT16_C( 14217),  INT16_C( 17699), -INT16_C(  3322),  INT16_C( 32002) } },
    { { -INT16_C(  5868), -INT16_C( 26951),  INT16_C(   987),  INT16_C( 27786), -INT16_C(  8375), -INT16_C( 31593), -INT16_C(  5085), -INT16_C( 11109) },
      {  INT16_C( 25583),  INT16_C(  3558),  INT16_C( 15059), -INT16_C( 21815), -INT16_C( 11886),  INT16_C(  5031),  INT16_C( 23752), -INT16_C(  8988) },
      { -INT16_C( 25275),  INT16_C(  8306), -INT16_C(   863), -INT16_C(  5491) },
       INT8_C(   0),
      {  INT16_C( 27519),  INT16_C( 25527),  INT16_C( 17850), -INT16_C( 17993), -INT16_C(  6749),  INT16_C( 15258), -INT16_C( 27125),  INT16_C( 12815) } },
    { {  INT16_C( 28196),  INT16_C(  4351), -INT16_C( 11511),  INT16_C( 27648),  INT16_C(  3513), -INT16_C(  3265), -INT16_C(  5674), -INT16_C( 22395) },
      { -INT16_C( 26480), -INT16_C(  5008),  INT16_C( 19580),  INT16_C(  6705),  INT16_C( 21183), -INT16_C( 17477), -INT16_C( 23073),  INT16_C(   919) },
      { -INT16_C( 27116),  INT16_C(  7443),  INT16_C(  4969),  INT16_C(  8842) },
       INT8_C(   0),
      { -INT16_C( 18076),  INT16_C( 10687),  INT16_C( 29881),  INT16_C( 11732),  INT16_C( 28325),  INT16_C( 12251), -INT16_C( 30398),  INT16_C( 27217) } },
    { {  INT16_C(  5833), -INT16_C( 19465), -INT16_C( 24677),  INT16_C( 13379),  INT16_C( 12303),  INT16_C( 23472), -INT16_C( 13727), -INT16_C( 19686) },
      { -INT16_C( 10619),  INT16_C( 11154), -INT16_C( 27283),  INT16_C(  1087),  INT16_C( 23721), -INT16_C( 17299), -INT16_C( 28442), -INT16_C( 20259) },
      { -INT16_C( 11098),  INT16_C( 16739), -INT16_C( 22925), -INT16_C( 32139) },
       INT8_C(   2),
      { -INT16_C( 19832), -INT16_C(  3443),  INT16_C( 28050), -INT16_C(  2416),  INT16_C( 26106), -INT16_C( 20825),  INT16_C(  1459),  INT16_C( 29793) } },
    { { -INT16_C(  8922), -INT16_C(  4040), -INT16_C(  5128), -INT16_C( 12682), -INT16_C( 24194),  INT16_C(  4923),  INT16_C( 16352),  INT16_C( 15548) },
      {  INT16_C( 31149),  INT16_C( 15651), -INT16_C( 11434),  INT16_C( 10979),  INT16_C(  9270), -INT16_C(  9059),  INT16_C(  8090), -INT16_C( 16205) },
      { -INT16_C(  5124), -INT16_C(  2896),  INT16_C(  9942),  INT16_C( 21698) },
       INT8_C(   3),
      { -INT16_C( 10688), -INT16_C( 16194),  INT16_C( 19236), -INT16_C( 13700), -INT16_C( 13718), -INT16_C( 14795), -INT16_C( 17772),  INT16_C(    98) } },
  };

  simde_int16x8_t r, a, b;
  simde_int16x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_s16(test_vec[i].a);
    b = simde_vld1q_s16(test_vec[i].b);
    v = simde_vld1_s16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vmlaq_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vmlaq_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vmlaq_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s16(0); break;
    }
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_int16x8_t r;

    SIMDE_CONSTIFY_4_(simde_vmlaq_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(0)), lane, a, b, v);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t v[2];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1901227562),  INT32_C(  1506304066),  INT32_C(    10101458), -INT32_C(   929349876) },
      { -INT32_C(   724051569),  INT32_C(   111411401),  INT32_C(   372195801),  INT32_C(  1276217462) },
      {  INT32_C(  1541127961), -INT32_C(   239820001) },
       INT8_C(   1),
      {  INT32_C(  1541601063),  INT32_C(  1517843353),  INT32_C(  1557415705),  INT32_C(   831907670) } },
    { { -INT32_C(  1915555250),  INT32_C(  1713216141),  INT32_C(  1915744626), -INT32_C(   682936938) },
      { -INT32_C(   313695643),  INT32_C(   839293555),  INT32_C(   407986549),  INT32_C(  1692222229) },
      { -INT32_C(  1024348363), -INT32_C(  1138225590) },
       INT8_C(   0),
      { -INT32_C(  1070572489), -INT32_C(   783077028), -INT32_C(  2050156117),  INT32_C(   179991535) } },
    { { -INT32_C(  1936314793), -INT32_C(   604934791),  INT32_C(  1431297723),  INT32_C(  1170899428) },
      {  INT32_C(   375120595),  INT32_C(  1867235263), -INT32_C(  1078391376), -INT32_C(  1933609675) },
      {  INT32_C(   471356835),  INT32_C(  2113407682) },
       INT8_C(   0),
      { -INT32_C(  1557157456), -INT32_C(  1111560426),  INT32_C(  1647248843),  INT32_C(  1049934755) } },
    { { -INT32_C(   926035385),  INT32_C(  2124092060),  INT32_C(   742306157),  INT32_C(   165522940) },
      { -INT32_C(   616653722), -INT32_C(  1333867941), -INT32_C(   311256349), -INT32_C(   640290670) },
      {  INT32_C(  1604494018),  INT32_C(   584924597) },
       INT8_C(   1),
      {  INT32_C(  1197782117),  INT32_C(  1158075379),  INT32_C(   958745324),  INT32_C(   444436278) } },
    { { -INT32_C(   924102885), -INT32_C(   936446676), -INT32_C(    31258317),  INT32_C(   585225095) },
      {  INT32_C(   901041733),  INT32_C(  1190694563),  INT32_C(  1845188400),  INT32_C(  1348214068) },
      { -INT32_C(  1743239060),  INT32_C(  1885357885) },
       INT8_C(   0),
      { -INT32_C(  1716667337), -INT32_C(   932120080), -INT32_C(  1053732493), -INT32_C(  1898658441) } },
    { {  INT32_C(  1457024643),  INT32_C(   496826959),  INT32_C(  1019335086),  INT32_C(   543950793) },
      {  INT32_C(   525720066),  INT32_C(  2123146550),  INT32_C(    79373501),  INT32_C(   139799685) },
      { -INT32_C(   362861158), -INT32_C(   720897241) },
       INT8_C(   0),
      {  INT32_C(    42855863), -INT32_C(  1572021557),  INT32_C(  1592665184),  INT32_C(   869740747) } },
    { { -INT32_C(   812248376),  INT32_C(  1490138750), -INT32_C(  1332743925), -INT32_C(  1586623107) },
      { -INT32_C(   182029623), -INT32_C(   191942713), -INT32_C(  1994688114),  INT32_C(  1230369153) },
      { -INT32_C(  2129007869), -INT32_C(  1378162014) },
       INT8_C(   1),
      { -INT32_C(  1426034694),  INT32_C(   663738476),  INT32_C(   167422183),  INT32_C(  1835715359) } },
    { {  INT32_C(  1985502825),  INT32_C(  1044380364),  INT32_C(  1325806624),  INT32_C(  1037957828) },
      {  INT32_C(   129918486), -INT32_C(  1492514628),  INT32_C(   189369121), -INT32_C(   823658651) },
      {  INT32_C(   558186325),  INT32_C(  1516209209) },
       INT8_C(   1),
      { -INT32_C(    91590321), -INT32_C(   239018840), -INT32_C(   111005063),  INT32_C(   999236673) } },
  };

  simde_int32x4_t r, a, b;
  simde_int32x2_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_s32(test_vec[i].a);
    b = simde_vld1q_s32(test_vec[i].b);
    v = simde_vld1_s32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vmlaq_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s32(0); break;
    }
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_2_(simde_vmlaq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), lane, a, b, v);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t v[4];
    int8_t lane;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(42664), UINT16_C(43275), UINT16_C(38735), UINT16_C(35292), UINT16_C( 8900), UINT16_C(58767), UINT16_C(34556), UINT16_C(44209) },
      { UINT16_C(30267), UINT16_C(58512), UINT16_C(42143), UINT16_C(34235), UINT16_C(18555), UINT16_C(23535), UINT16_C(64588), UINT16_C(62794) },
      { UINT16_C(21922), UINT16_C(61854), UINT16_C(31724), UINT16_C(45178) },
       INT8_C(   1),
      { UINT16_C(10770), UINT16_C(18923), UINT16_C(57457), UINT16_C( 7750), UINT16_C(43438), UINT16_C(41489), UINT16_C(51684), UINT16_C(47709) } },
    { { UINT16_C(38410), UINT16_C(37017), UINT16_C(17735), UINT16_C(48587), UINT16_C(45270), UINT16_C(31325), UINT16_C(57963), UINT16_C(46069) },
      { UINT16_C(20690), UINT16_C(52991), UINT16_C(62618), UINT16_C(61297), UINT16_C(25235), UINT16_C( 3804), UINT16_C(36061), UINT16_C(59307) },
      { UINT16_C(17442), UINT16_C(27255), UINT16_C(17289), UINT16_C(24359) },
       INT8_C(   3),
      { UINT16_C(54280), UINT16_C(47730), UINT16_C(44733), UINT16_C( 9986), UINT16_C(16955), UINT16_C(25057), UINT16_C(23318), UINT16_C(29698) } },
    { { UINT16_C(55940), UINT16_C(26462), UINT16_C( 4559), UINT16_C( 8249), UINT16_C( 1808), UINT16_C( 1466), UINT16_C(43640), UINT16_C(56216) },
      { UINT16_C(42630), UINT16_C( 4792), UINT16_C(40785), UINT16_C(38197), UINT16_C(40726), UINT16_C(22814), UINT16_C(32454), UINT16_C(19276) },
      { UINT16_C(43608), UINT16_C(10162), UINT16_C(60347), UINT16_C(52295) },
       INT8_C(   2),
      { UINT16_C(32870), UINT16_C(64454), UINT16_C(52474), UINT16_C(50416), UINT16_C(28194), UINT16_C(43172), UINT16_C( 1818), UINT16_C(40988) } },
    { { UINT16_C(53506), UINT16_C(44139), UINT16_C(18025), UINT16_C( 3890), UINT16_C(17662), UINT16_C(40288), UINT16_C(62841), UINT16_C( 6323) },
      { UINT16_C( 3347), UINT16_C(37343), UINT16_C(10841), UINT16_C( 1257), UINT16_C( 4572), UINT16_C(51135), UINT16_C(35672), UINT16_C(23225) },
      { UINT16_C( 9308), UINT16_C(50438), UINT16_C(14442), UINT16_C(26836) },
       INT8_C(   1),
      { UINT16_C(48756), UINT16_C(45733), UINT16_C(49535), UINT16_C(31144), UINT16_C(64550), UINT16_C(18138), UINT16_C(61833), UINT16_C(38409) } },
    { { UINT16_C( 1332), UINT16_C(10742), UINT16_C( 4025), UINT16_C(50749), UINT16_C(52974), UINT16_C( 6175), UINT16_C( 9144), UINT16_C(51700) },
      { UINT16_C(48099), UINT16_C(28193), UINT16_C(31860), UINT16_C(39371), UINT16_C(36994), UINT16_C(47875), UINT16_C(27749), UINT16_C(39224) },
      { UINT16_C(11889), UINT16_C(10947), UINT16_C(   61), UINT16_C(11248) },
       INT8_C(   2),
      { UINT16_C(51787), UINT16_C(26579), UINT16_C(46941), UINT16_C(27548), UINT16_C(15848), UINT16_C(42966), UINT16_C(63433), UINT16_C(19532) } },
    { { UINT16_C(17168), UINT16_C(13190), UINT16_C(20279), UINT16_C(61974), UINT16_C(34161), UINT16_C(60775), UINT16_C(   80), UINT16_C(57455) },
      { UINT16_C(10755), UINT16_C(28485), UINT16_C(57186), UINT16_C(37345), UINT16_C( 2978), UINT16_C(41678), UINT16_C(64252), UINT16_C( 3184) },
      { UINT16_C(63293), UINT16_C(30015), UINT16_C(22086), UINT16_C(46951) },
       INT8_C(   3),
      { UINT16_C(20293), UINT16_C(19273), UINT16_C(15781), UINT16_C(31389), UINT16_C(  415), UINT16_C(45129), UINT16_C( 8116), UINT16_C(61823) } },
    { { UINT16_C(42190), UINT16_C(52779), UINT16_C( 2836), UINT16_C(16082), UINT16_C(16721), UINT16_C(12449), UINT16_C(12834), UINT16_C(11986) },
      { UINT16_C(29696), UINT16_C(64042), UINT16_C(14052), UINT16_C(56120), UINT16_C(44405), UINT16_C(52002), UINT16_C(55572), UINT16_C(58278) },
      { UINT16_C(53630), UINT16_C(37553), UINT16_C(33757), UINT16_C(11984) },
       INT8_C(   1),
      { UINT16_C(55502), UINT16_C(47413), UINT16_C( 1720), UINT16_C(49290), UINT16_C(59702), UINT16_C( 1827), UINT16_C(45302), UINT16_C(16536) } },
    { { UINT16_C(24177), UINT16_C(41959), UINT16_C( 5424), UINT16_C(42148), UINT16_C(40511), UINT16_C(30088), UINT16_C(25814), UINT16_C(33771) },
      { UINT16_C(46726), UINT16_C(24472), UINT16_C(31581), UINT16_C(11997), UINT16_C(28460), UINT16_C(45067), UINT16_C(14656), UINT16_C(45429) },
      { UINT16_C(23703), UINT16_C(51029), UINT16_C(63858), UINT16_C(45419) },
       INT8_C(   3),
      { UINT16_C(20083), UINT16_C(45167), UINT16_C(61967), UINT16_C( 2051), UINT16_C(33187), UINT16_C(42273), UINT16_C(37526), UINT16_C(38098) } },
  };

  simde_uint16x8_t r, a, b;
  simde_uint16x4_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_u16(test_vec[i].a);
    b = simde_vld1q_u16(test_vec[i].b);
    v = simde_vld1_u16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_lane_u16(a, b, v, 0); break;
      case 1: r = simde_vmlaq_lane_u16(a, b, v, 1); break;
      case 2: r = simde_vmlaq_lane_u16(a, b, v, 2); break;
      case 3: r = simde_vmlaq_lane_u16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_u16(0); break;
    }
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x4_t v = simde_test_arm_neon_random_u16x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_uint16x8_t r;

    SIMDE_CONSTIFY_4_(simde_vmlaq_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(0)), lane, a, b, v);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t v[2];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(4049857574), UINT32_C(4004185250), UINT32_C(3183129877), UINT32_C(2494230254) },
      { UINT32_C(3135721086), UINT32_C(1529636560), UINT32_C(3772764706), UINT32_C( 295409387) },
      { UINT32_C( 620953475), UINT32_C( 403942915) },
       INT8_C(   1),
      { UINT32_C(4241324960), UINT32_C(1333893394), UINT32_C(1236486011), UINT32_C(3313659311) } },
    { { UINT32_C(3159545293), UINT32_C(3443189375), UINT32_C( 882767310), UINT32_C(4082628897) },
      { UINT32_C(1876899800), UINT32_C(3522359506), UINT32_C(2715097075), UINT32_C(4144295210) },
      { UINT32_C(1119049411), UINT32_C( 185658941) },
       INT8_C(   1),
      { UINT32_C(2951607365), UINT32_C(3273753737), UINT32_C(3503854773), UINT32_C(  77695011) } },
    { { UINT32_C(2785296301), UINT32_C(3447715734), UINT32_C(3349212886), UINT32_C(4156191200) },
      { UINT32_C( 874601286), UINT32_C(3069646943), UINT32_C(3136502220), UINT32_C(4154326601) },
      { UINT32_C(3567100221), UINT32_C(1872829592) },
       INT8_C(   0),
      { UINT32_C(4266394971), UINT32_C(1794606393), UINT32_C(2903179378), UINT32_C(3155227205) } },
    { { UINT32_C(3018470977), UINT32_C(1274667504), UINT32_C( 464137474), UINT32_C(1592221732) },
      { UINT32_C(1369940307), UINT32_C(3750731326), UINT32_C(1484219196), UINT32_C(1180952068) },
      { UINT32_C( 217664796), UINT32_C( 827847215) },
       INT8_C(   0),
      { UINT32_C(3682652757), UINT32_C(3298154168), UINT32_C( 116265874), UINT32_C( 132627604) } },
    { { UINT32_C(1648643074), UINT32_C(3568738867), UINT32_C(3893495626), UINT32_C(4179947926) },
      { UINT32_C(1342078313), UINT32_C( 762070240), UINT32_C( 794589245), UINT32_C(3528429264) },
      { UINT32_C( 238327002), UINT32_C(2162354742) },
       INT8_C(   0),
      { UINT32_C(3637496684), UINT32_C(1480247539), UINT32_C(1958195004), UINT32_C(1907674806) } },
    { { UINT32_C(3867699701), UINT32_C( 172982925), UINT32_C(3303710592), UINT32_C(2197886987) },
      { UINT32_C(  39006324), UINT32_C( 350037376), UINT32_C(1145760602), UINT32_C(3258371021) },
      { UINT32_C(3249127220), UINT32_C(3251435585) },
       INT8_C(   1),
      { UINT32_C( 621287273), UINT32_C(4106881037), UINT32_C( 363303258), UINT32_C(3702877976) } },
    { { UINT32_C(3466757558), UINT32_C(3057854086), UINT32_C(2671134073), UINT32_C( 234441250) },
      { UINT32_C(1624980885), UINT32_C( 865377652), UINT32_C(1064588614), UINT32_C(3637916961) },
      { UINT32_C(1084651962), UINT32_C( 418834847) },
       INT8_C(   1),
      { UINT32_C(2802344513), UINT32_C( 811042194), UINT32_C(1800925683), UINT32_C(3608498849) } },
    { { UINT32_C(2001844013), UINT32_C(3993788336), UINT32_C(3613551674), UINT32_C(1444844800) },
      { UINT32_C(1048009993), UINT32_C(2901954355), UINT32_C(3746248950), UINT32_C(1527669806) },
      { UINT32_C(3436404763), UINT32_C(4189773759) },
       INT8_C(   0),
      { UINT32_C(2872502048), UINT32_C( 888723985), UINT32_C(2490347052), UINT32_C(2417911258) } },
  };

  simde_uint32x4_t r, a, b;
  simde_uint32x2_t v;

  for (int i = 0 ; i < 8 ; i++) {
    a = simde_vld1q_u32(test_vec[i].a);
    b = simde_vld1q_u32(test_vec[i].b);
    v = simde_vld1_u32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_lane_u32(a, b, v, 0); break;
      case 1: r = simde_vmlaq_lane_u32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_u32(0); break;
    }
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x2_t v = simde_test_arm_neon_random_u32x2();
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_2_(simde_vmlaq_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), lane, a, b, v);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[4];
    float b[4];
    float v[4];
    int8_t lane;
    float r[4];
  } test_vec[] = {
     { {   SIMDE_FLOAT32_C(  8442.05),  SIMDE_FLOAT32_C( -1389.69),  SIMDE_FLOAT32_C( -7758.59),  SIMDE_FLOAT32_C(  9540.76) },
       {   SIMDE_FLOAT32_C(  6942.28),  SIMDE_FLOAT32_C(  8460.25),  SIMDE_FLOAT32_C( -6145.94),  SIMDE_FLOAT32_C( -5237.55) },
       {   SIMDE_FLOAT32_C(     6.77),  SIMDE_FLOAT32_C(   -67.83),  SIMDE_FLOAT32_C(  8178.24),  SIMDE_FLOAT32_C(  8618.63) },
           INT8_C(        0),
       {   SIMDE_FLOAT32_C( 55441.29),  SIMDE_FLOAT32_C( 55886.20),  SIMDE_FLOAT32_C(-49366.60),  SIMDE_FLOAT32_C(-25917.45) } },
     { {   SIMDE_FLOAT32_C(  5329.09),  SIMDE_FLOAT32_C( -8842.70),  SIMDE_FLOAT32_C(  1083.15),  SIMDE_FLOAT32_C(  2779.22) },
       {   SIMDE_FLOAT32_C( -5037.14),  SIMDE_FLOAT32_C( -4543.60),  SIMDE_FLOAT32_C( -1131.52),  SIMDE_FLOAT32_C(  4145.12) },
       {   SIMDE_FLOAT32_C(  4928.14),  SIMDE_FLOAT32_C( -3195.41),  SIMDE_FLOAT32_C(  9422.83),  SIMDE_FLOAT32_C(   529.15) },
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(16101056.62),  SIMDE_FLOAT32_C(14509822.18),  SIMDE_FLOAT32_C(3616753.47),  SIMDE_FLOAT32_C(-13242578.68) } },
     { {   SIMDE_FLOAT32_C(  3210.16),  SIMDE_FLOAT32_C( -8073.64),  SIMDE_FLOAT32_C( -1871.73),  SIMDE_FLOAT32_C(  7766.76) },
       {   SIMDE_FLOAT32_C(  8132.39),  SIMDE_FLOAT32_C( -6406.75),  SIMDE_FLOAT32_C( -1445.99),  SIMDE_FLOAT32_C(  9952.74) },
       {   SIMDE_FLOAT32_C( -5644.48),  SIMDE_FLOAT32_C(   639.33),  SIMDE_FLOAT32_C( -1095.59),  SIMDE_FLOAT32_C(  -658.50) },
           INT8_C(        0),
       {   SIMDE_FLOAT32_C(-45899902.55),  SIMDE_FLOAT32_C(36154698.60),  SIMDE_FLOAT32_C(8159989.91),  SIMDE_FLOAT32_C(-56170275.12) } },
     { {   SIMDE_FLOAT32_C(  9159.77),  SIMDE_FLOAT32_C( -4542.00),  SIMDE_FLOAT32_C(  9445.80),  SIMDE_FLOAT32_C( -2110.99) },
       {   SIMDE_FLOAT32_C( -9801.74),  SIMDE_FLOAT32_C(  1886.98),  SIMDE_FLOAT32_C(    75.78),  SIMDE_FLOAT32_C( -3125.09) },
       {   SIMDE_FLOAT32_C(   637.73),  SIMDE_FLOAT32_C( -6924.14),  SIMDE_FLOAT32_C(  4915.85),  SIMDE_FLOAT32_C( -4312.70) },
           INT8_C(        2),
       {   SIMDE_FLOAT32_C(-48174723.81),  SIMDE_FLOAT32_C(9271568.63),  SIMDE_FLOAT32_C(381968.91),  SIMDE_FLOAT32_C(-15364584.67) } },
     { {   SIMDE_FLOAT32_C(  8169.70),  SIMDE_FLOAT32_C( -7479.28),  SIMDE_FLOAT32_C(  3348.22),  SIMDE_FLOAT32_C(  9587.11) },
       {   SIMDE_FLOAT32_C(  8706.77),  SIMDE_FLOAT32_C(  3214.14),  SIMDE_FLOAT32_C(  4481.19),  SIMDE_FLOAT32_C(  2317.74) },
       {   SIMDE_FLOAT32_C(  6486.86),  SIMDE_FLOAT32_C( -4651.54),  SIMDE_FLOAT32_C( -6489.10),  SIMDE_FLOAT32_C( -2517.83) },
           INT8_C(        3),
       {   SIMDE_FLOAT32_C(-21913997.01),  SIMDE_FLOAT32_C(-8100137.40),  SIMDE_FLOAT32_C(-11279526.40),  SIMDE_FLOAT32_C(-5826088.19) } },
     { {   SIMDE_FLOAT32_C(  3469.51),  SIMDE_FLOAT32_C(  2478.92),  SIMDE_FLOAT32_C(  3545.43),  SIMDE_FLOAT32_C(  7751.36) },
       {   SIMDE_FLOAT32_C( -6649.73),  SIMDE_FLOAT32_C( -7867.38),  SIMDE_FLOAT32_C(   615.31),  SIMDE_FLOAT32_C(  7194.09) },
       {   SIMDE_FLOAT32_C(   -94.57),  SIMDE_FLOAT32_C(  6945.08),  SIMDE_FLOAT32_C( -3326.00),  SIMDE_FLOAT32_C(  9571.16) },
           INT8_C(        1),
       {   SIMDE_FLOAT32_C(-46179437.32),  SIMDE_FLOAT32_C(-54637104.57),  SIMDE_FLOAT32_C(4276922.60),  SIMDE_FLOAT32_C(49971281.94) } },
     { {   SIMDE_FLOAT32_C(  -114.66),  SIMDE_FLOAT32_C(  -857.24),  SIMDE_FLOAT32_C(  5238.98),  SIMDE_FLOAT32_C(  8989.32) },
       {   SIMDE_FLOAT32_C(   414.11),  SIMDE_FLOAT32_C( -4411.42),  SIMDE_FLOAT32_C( -3370.65),  SIMDE_FLOAT32_C(  -285.04) },
       {   SIMDE_FLOAT32_C(  9685.87),  SIMDE_FLOAT32_C( -5631.83),  SIMDE_FLOAT32_C(  6655.15),  SIMDE_FLOAT32_C( -1696.69) },
           INT8_C(        2),
       {   SIMDE_FLOAT32_C(2755849.51),  SIMDE_FLOAT32_C(-29359519.05),  SIMDE_FLOAT32_C(-22426942.37),  SIMDE_FLOAT32_C(-1887994.64) } },
     { {   SIMDE_FLOAT32_C( -7938.21),  SIMDE_FLOAT32_C(  4723.86),  SIMDE_FLOAT32_C(  4094.72),  SIMDE_FLOAT32_C(  8367.37) },
       {   SIMDE_FLOAT32_C( -2636.63),  SIMDE_FLOAT32_C( -3127.64),  SIMDE_FLOAT32_C(  8864.91),  SIMDE_FLOAT32_C(  2740.01) },
       {   SIMDE_FLOAT32_C( -8938.37),  SIMDE_FLOAT32_C( -1798.64),  SIMDE_FLOAT32_C( -8001.07),  SIMDE_FLOAT32_C(  9705.11) },
           INT8_C(        2),
       {   SIMDE_FLOAT32_C(21087922.98),  SIMDE_FLOAT32_C(25029190.43),  SIMDE_FLOAT32_C(-70924670.73),  SIMDE_FLOAT32_C(-21914644.44) } },
  };

  simde_float32x4_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_f32(test_vec[i].a);
    b = simde_vld1q_f32(test_vec[i].b);
    v = simde_vld1q_f32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_laneq_f32(a, b, v, 0); break;
      case 1: r = simde_vmlaq_laneq_f32(a, b, v, 1); break;
      case 2: r = simde_vmlaq_laneq_f32(a, b, v, 2); break;
      case 3: r = simde_vmlaq_laneq_f32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_f32(0); break;
    }
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmlaq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t v[8];
    int8_t lane;
    int16_t r[8];
  } test_vec[] = {
     { {   INT16_C(   27), -INT16_C(   14),  INT16_C(   80), -INT16_C(   68),
          -INT16_C(   60),  INT16_C(   13), -INT16_C(   19),  INT16_C(   58) },
       {  -INT16_C(   62),  INT16_C(   96),  INT16_C(   88), -INT16_C(   24),
          -INT16_C(   69),  INT16_C(   66), -INT16_C(   11), -INT16_C(   43) },
       {  -INT16_C(    5), -INT16_C(    2), -INT16_C(    9), -INT16_C(   77),
          -INT16_C(   68),  INT16_C(   65), -INT16_C(   81),  INT16_C(   39) },
           INT8_C(    4),
       {   INT16_C( 4243), -INT16_C( 6542), -INT16_C( 5904),  INT16_C( 1564),
           INT16_C( 4632), -INT16_C( 4475),  INT16_C(  729),  INT16_C( 2982) } },
     { {   INT16_C(   86), -INT16_C(   77), -INT16_C(   26), -INT16_C(   24),
           INT16_C(   84), -INT16_C(   17), -INT16_C(   35),  INT16_C(   34) },
       {  -INT16_C(   72), -INT16_C(   12), -INT16_C(   48),  INT16_C(   50),
           INT16_C(   17),  INT16_C(   41), -INT16_C(   78), -INT16_C(   73) },
       {   INT16_C(   42),  INT16_C(   24),  INT16_C(   40), -INT16_C(   89),
          -INT16_C(   28),  INT16_C(   60), -INT16_C(    2),  INT16_C(   52) },
           INT8_C(    2),
       {  -INT16_C( 2794), -INT16_C(  557), -INT16_C( 1946),  INT16_C( 1976),
           INT16_C(  764),  INT16_C( 1623), -INT16_C( 3155), -INT16_C( 2886) } },
     { {   INT16_C(   70),  INT16_C(    1),  INT16_C(   23), -INT16_C(   44),
          -INT16_C(    5),  INT16_C(   65), -INT16_C(   27),  INT16_C(   23) },
       {   INT16_C(   92), -INT16_C(   88), -INT16_C(   41), -INT16_C(   89),
          -INT16_C(   37),  INT16_C(   63), -INT16_C(   44), -INT16_C(   77) },
       {  -INT16_C(   74),  INT16_C(   29), -INT16_C(   58), -INT16_C(   38),
          -INT16_C(   71),  INT16_C(   98),  INT16_C(   26),  INT16_C(    3) },
           INT8_C(    5),
       {   INT16_C( 9086), -INT16_C( 8623), -INT16_C( 3995), -INT16_C( 8766),
          -INT16_C( 3631),  INT16_C( 6239), -INT16_C( 4339), -INT16_C( 7523) } },
     { {  -INT16_C(    1), -INT16_C(   60), -INT16_C(   20),  INT16_C(   28),
           INT16_C(   36), -INT16_C(   98),  INT16_C(   95),  INT16_C(   19) },
       {  -INT16_C(   43), -INT16_C(   59),  INT16_C(   41), -INT16_C(   12),
          -INT16_C(   73), -INT16_C(   34),  INT16_C(   76), -INT16_C(   31) },
       {   INT16_C(    0), -INT16_C(   92), -INT16_C(   26), -INT16_C(   76),
          -INT16_C(   39),  INT16_C(   62),  INT16_C(   29),  INT16_C(   22) },
           INT8_C(    2),
       {   INT16_C( 1117),  INT16_C( 1474), -INT16_C( 1086),  INT16_C(  340),
           INT16_C( 1934),  INT16_C(  786), -INT16_C( 1881),  INT16_C(  825) } },
     { {   INT16_C(   76),  INT16_C(   78), -INT16_C(   52),  INT16_C(   59),
           INT16_C(   75), -INT16_C(   12),  INT16_C(   26), -INT16_C(   48) },
       {  -INT16_C(    7),  INT16_C(   21),  INT16_C(    1), -INT16_C(    9),
           INT16_C(   71),  INT16_C(   57), -INT16_C(   36), -INT16_C(   12) },
       {  -INT16_C(   23),  INT16_C(    6), -INT16_C(   38),  INT16_C(   79),
          -INT16_C(   62), -INT16_C(   58), -INT16_C(    3), -INT16_C(    5) },
           INT8_C(    7),
       {   INT16_C(  111), -INT16_C(   27), -INT16_C(   57),  INT16_C(  104),
          -INT16_C(  280), -INT16_C(  297),  INT16_C(  206),  INT16_C(   12) } },
     { {   INT16_C(    3), -INT16_C(   47), -INT16_C(   89),  INT16_C(   58),
          -INT16_C(   22),  INT16_C(   26), -INT16_C(   49),  INT16_C(    6) },
       {   INT16_C(   72),  INT16_C(   78), -INT16_C(   54),  INT16_C(    0),
           INT16_C(   12), -INT16_C(   22), -INT16_C(   87),  INT16_C(    4) },
       {  -INT16_C(   89), -INT16_C(   84),  INT16_C(   65),  INT16_C(   20),
          -INT16_C(   27), -INT16_C(   19),  INT16_C(   47), -INT16_C(   12) },
           INT8_C(    6),
       {   INT16_C( 3387),  INT16_C( 3619), -INT16_C( 2627),  INT16_C(   58),
           INT16_C(  542), -INT16_C( 1008), -INT16_C( 4138),  INT16_C(  194) } },
     { {   INT16_C(   97), -INT16_C(    3), -INT16_C(   86),  INT16_C(   62),
          -INT16_C(    5), -INT16_C(   50), -INT16_C(   91),  INT16_C(   81) },
       {   INT16_C(   47),  INT16_C(   49),  INT16_C(    4),  INT16_C(    4),
          -INT16_C(   40),  INT16_C(   55), -INT16_C(   34),  INT16_C(   85) },
       {   INT16_C(   56),  INT16_C(   35), -INT16_C(   72),  INT16_C(   64),
           INT16_C(   52),  INT16_C(   80),  INT16_C(   12),  INT16_C(   48) },
           INT8_C(    4),
       {   INT16_C( 2541),  INT16_C( 2545),  INT16_C(  122),  INT16_C(  270),
          -INT16_C( 2085),  INT16_C( 2810), -INT16_C( 1859),  INT16_C( 4501) } },
     { {   INT16_C(   10),  INT16_C(   42), -INT16_C(   53), -INT16_C(   66),
           INT16_C(   95), -INT16_C(   34), -INT16_C(   15), -INT16_C(   84) },
       {  -INT16_C(   19),  INT16_C(   87), -INT16_C(   77), -INT16_C(   65),
          -INT16_C(   80),  INT16_C(    4),  INT16_C(   74),  INT16_C(   63) },
       {  -INT16_C(   70), -INT16_C(   67),  INT16_C(   63), -INT16_C(   62),
          -INT16_C(   20),  INT16_C(   44),  INT16_C(   15),  INT16_C(   79) },
           INT8_C(    7),
       {  -INT16_C( 1491),  INT16_C( 6915), -INT16_C( 6136), -INT16_C( 5201),
          -INT16_C( 6225),  INT16_C(  282),  INT16_C( 5831),  INT16_C( 4893) } },
  };

  simde_int16x8_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s16(test_vec[i].a);
    b = simde_vld1q_s16(test_vec[i].b);
    v = simde_vld1q_s16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vmlaq_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vmlaq_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vmlaq_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vmlaq_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vmlaq_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vmlaq_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vmlaq_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s16(0); break;
    }
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(    6136),  INT32_C(    1298), -INT32_C(    4397), -INT32_C(    2313) },
       {  -INT32_C(    2459),  INT32_C(    5639),  INT32_C(     944),  INT32_C(    7600) },
       {  -INT32_C(    5378),  INT32_C(    8852), -INT32_C(    9600),  INT32_C(    9935) },
           INT8_C(       1),
       {  -INT32_C(21773204),  INT32_C(49917726),  INT32_C( 8351891),  INT32_C(67272887) } },
     { {  -INT32_C(    9404),  INT32_C(     567), -INT32_C(    6346), -INT32_C(    3906) },
       {   INT32_C(    6125),  INT32_C(    4990),  INT32_C(    5704),  INT32_C(    3511) },
       {   INT32_C(    7787),  INT32_C(    7196),  INT32_C(    1911),  INT32_C(    9234) },
           INT8_C(       3),
       {   INT32_C(56548846),  INT32_C(46078227),  INT32_C(52664390),  INT32_C(32416668) } },
     { {   INT32_C(     124),  INT32_C(    1315), -INT32_C(     398), -INT32_C(    8335) },
       {   INT32_C(    4856), -INT32_C(     218),  INT32_C(    9898),  INT32_C(    5450) },
       {   INT32_C(    3364), -INT32_C(    8289), -INT32_C(    5348), -INT32_C(    4660) },
           INT8_C(       2),
       {  -INT32_C(25969764),  INT32_C( 1167179), -INT32_C(52934902), -INT32_C(29154935) } },
     { {  -INT32_C(    7741), -INT32_C(    5638), -INT32_C(    1216), -INT32_C(    4399) },
       {  -INT32_C(    7004), -INT32_C(    7954), -INT32_C(    5842), -INT32_C(    4473) },
       {   INT32_C(    4738), -INT32_C(    4541),  INT32_C(    3190),  INT32_C(    5887) },
           INT8_C(       3),
       {  -INT32_C(41240289), -INT32_C(46830836), -INT32_C(34393070), -INT32_C(26336950) } },
     { {  -INT32_C(    4228),  INT32_C(    9643), -INT32_C(    6720),  INT32_C(    2725) },
       {   INT32_C(    8556), -INT32_C(    5884), -INT32_C(    3313),  INT32_C(    3496) },
       {  -INT32_C(    9409), -INT32_C(    9792),  INT32_C(     284), -INT32_C(    1614) },
           INT8_C(       0),
       {  -INT32_C(80507632),  INT32_C(55372199),  INT32_C(31165297), -INT32_C(32891139) } },
     { {   INT32_C(    1341), -INT32_C(     617), -INT32_C(    8745), -INT32_C(    4860) },
       {   INT32_C(    4084), -INT32_C(    5463), -INT32_C(    1722), -INT32_C(    9232) },
       {   INT32_C(    5013), -INT32_C(    9923),  INT32_C(    4345), -INT32_C(    7885) },
           INT8_C(       2),
       {   INT32_C(17746321), -INT32_C(23737352), -INT32_C( 7490835), -INT32_C(40117900) } },
     { {  -INT32_C(    4259), -INT32_C(    3605), -INT32_C(    5933), -INT32_C(    2164) },
       {   INT32_C(    4526),  INT32_C(    5427), -INT32_C(    8312),  INT32_C(    6713) },
       {   INT32_C(     108),  INT32_C(    2835),  INT32_C(    3642), -INT32_C(    9015) },
           INT8_C(       3),
       {  -INT32_C(40806149), -INT32_C(48928010),  INT32_C(74926747), -INT32_C(60519859) } },
     { {   INT32_C(    8687),  INT32_C(    3316),  INT32_C(    4039),  INT32_C(    4869) },
       {   INT32_C(    1050),  INT32_C(    4513), -INT32_C(    1617), -INT32_C(    4470) },
       {   INT32_C(    1370), -INT32_C(    1457), -INT32_C(    7408), -INT32_C(    7365) },
           INT8_C(       3),
       {  -INT32_C( 7724563), -INT32_C(33234929),  INT32_C(11913244),  INT32_C(32926419) } },
  };

  simde_int32x4_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s32(test_vec[i].a);
    b = simde_vld1q_s32(test_vec[i].b);
    v = simde_vld1q_s32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vmlaq_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vmlaq_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vmlaq_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s32(0); break;
    }
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t v[8];
    int8_t lane;
    uint16_t r[8];
  } test_vec[] = {
     { {   UINT16_C(    34),  UINT16_C(    55),  UINT16_C(    53),  UINT16_C(    65),
           UINT16_C(     8),  UINT16_C(   110),  UINT16_C(   158),  UINT16_C(   151) },
       {   UINT16_C(   173),  UINT16_C(    56),  UINT16_C(   100),  UINT16_C(   187),
           UINT16_C(    53),  UINT16_C(   174),  UINT16_C(   100),  UINT16_C(   199) },
       {   UINT16_C(   143),  UINT16_C(   106),  UINT16_C(    85),  UINT16_C(   161),
           UINT16_C(   154),  UINT16_C(   119),  UINT16_C(    79),  UINT16_C(    80) },
           INT8_C(     1),
       {   UINT16_C( 18372),  UINT16_C(  5991),  UINT16_C( 10653),  UINT16_C( 19887),
           UINT16_C(  5626),  UINT16_C( 18554),  UINT16_C( 10758),  UINT16_C( 21245) } },
     { {   UINT16_C(    60),  UINT16_C(   195),  UINT16_C(    16),  UINT16_C(    37),
           UINT16_C(   149),  UINT16_C(   107),  UINT16_C(   153),  UINT16_C(   113) },
       {   UINT16_C(   164),  UINT16_C(   111),  UINT16_C(   177),  UINT16_C(    35),
           UINT16_C(    15),  UINT16_C(    27),  UINT16_C(   192),  UINT16_C(    69) },
       {   UINT16_C(    35),  UINT16_C(   136),  UINT16_C(    42),  UINT16_C(    13),
           UINT16_C(   121),  UINT16_C(   151),  UINT16_C(   152),  UINT16_C(   185) },
           INT8_C(     2),
       {   UINT16_C(  6948),  UINT16_C(  4857),  UINT16_C(  7450),  UINT16_C(  1507),
           UINT16_C(   779),  UINT16_C(  1241),  UINT16_C(  8217),  UINT16_C(  3011) } },
     { {   UINT16_C(    76),  UINT16_C(   110),  UINT16_C(   183),  UINT16_C(   176),
           UINT16_C(    10),  UINT16_C(    39),  UINT16_C(   127),  UINT16_C(    64) },
       {   UINT16_C(    71),  UINT16_C(   190),  UINT16_C(    18),  UINT16_C(   165),
           UINT16_C(   189),  UINT16_C(   156),  UINT16_C(   101),  UINT16_C(   164) },
       {   UINT16_C(    19),  UINT16_C(    88),  UINT16_C(   194),  UINT16_C(    90),
           UINT16_C(   177),  UINT16_C(    34),  UINT16_C(   165),  UINT16_C(    63) },
           INT8_C(     3),
       {   UINT16_C(  6466),  UINT16_C( 17210),  UINT16_C(  1803),  UINT16_C( 15026),
           UINT16_C( 17020),  UINT16_C( 14079),  UINT16_C(  9217),  UINT16_C( 14824) } },
     { {   UINT16_C(   192),  UINT16_C(     2),  UINT16_C(   111),  UINT16_C(   133),
           UINT16_C(     8),  UINT16_C(    69),  UINT16_C(   147),  UINT16_C(    41) },
       {   UINT16_C(     7),  UINT16_C(   183),  UINT16_C(   162),  UINT16_C(    21),
           UINT16_C(    61),  UINT16_C(   125),  UINT16_C(    33),  UINT16_C(   127) },
       {   UINT16_C(    29),  UINT16_C(   195),  UINT16_C(    86),  UINT16_C(     0),
           UINT16_C(    59),  UINT16_C(    89),  UINT16_C(    99),  UINT16_C(     9) },
           INT8_C(     0),
       {   UINT16_C(   395),  UINT16_C(  5309),  UINT16_C(  4809),  UINT16_C(   742),
           UINT16_C(  1777),  UINT16_C(  3694),  UINT16_C(  1104),  UINT16_C(  3724) } },
     { {   UINT16_C(    95),  UINT16_C(    15),  UINT16_C(     0),  UINT16_C(   138),
           UINT16_C(   174),  UINT16_C(   104),  UINT16_C(   186),  UINT16_C(   105) },
       {   UINT16_C(    66),  UINT16_C(   149),  UINT16_C(    50),  UINT16_C(    79),
           UINT16_C(   177),  UINT16_C(   169),  UINT16_C(    40),  UINT16_C(   125) },
       {   UINT16_C(    67),  UINT16_C(   103),  UINT16_C(    80),  UINT16_C(   199),
           UINT16_C(   172),  UINT16_C(    94),  UINT16_C(    82),  UINT16_C(   142) },
           INT8_C(     1),
       {   UINT16_C(  6893),  UINT16_C( 15362),  UINT16_C(  5150),  UINT16_C(  8275),
           UINT16_C( 18405),  UINT16_C( 17511),  UINT16_C(  4306),  UINT16_C( 12980) } },
     { {   UINT16_C(   123),  UINT16_C(   187),  UINT16_C(    45),  UINT16_C(   103),
           UINT16_C(    65),  UINT16_C(   124),  UINT16_C(    98),  UINT16_C(    75) },
       {   UINT16_C(   169),  UINT16_C(   102),  UINT16_C(   113),  UINT16_C(   164),
           UINT16_C(    59),  UINT16_C(   171),  UINT16_C(    72),  UINT16_C(    38) },
       {   UINT16_C(   174),  UINT16_C(   143),  UINT16_C(   134),  UINT16_C(    24),
           UINT16_C(    81),  UINT16_C(   150),  UINT16_C(   186),  UINT16_C(   119) },
           INT8_C(     0),
       {   UINT16_C( 29529),  UINT16_C( 17935),  UINT16_C( 19707),  UINT16_C( 28639),
           UINT16_C( 10331),  UINT16_C( 29878),  UINT16_C( 12626),  UINT16_C(  6687) } },
     { {   UINT16_C(   185),  UINT16_C(    79),  UINT16_C(   109),  UINT16_C(    44),
           UINT16_C(   147),  UINT16_C(     9),  UINT16_C(    91),  UINT16_C(    66) },
       {   UINT16_C(    28),  UINT16_C(   160),  UINT16_C(    34),  UINT16_C(    60),
           UINT16_C(   182),  UINT16_C(     5),  UINT16_C(    85),  UINT16_C(   164) },
       {   UINT16_C(   132),  UINT16_C(   144),  UINT16_C(    59),  UINT16_C(    73),
           UINT16_C(     4),  UINT16_C(    50),  UINT16_C(   128),  UINT16_C(   152) },
           INT8_C(     0),
       {   UINT16_C(  3881),  UINT16_C( 21199),  UINT16_C(  4597),  UINT16_C(  7964),
           UINT16_C( 24171),  UINT16_C(   669),  UINT16_C( 11311),  UINT16_C( 21714) } },
     { {   UINT16_C(    46),  UINT16_C(    41),  UINT16_C(   184),  UINT16_C(   128),
           UINT16_C(    76),  UINT16_C(   168),  UINT16_C(   192),  UINT16_C(   166) },
       {   UINT16_C(    10),  UINT16_C(   186),  UINT16_C(    84),  UINT16_C(    64),
           UINT16_C(   186),  UINT16_C(    53),  UINT16_C(    70),  UINT16_C(   100) },
       {   UINT16_C(    89),  UINT16_C(    87),  UINT16_C(    23),  UINT16_C(    67),
           UINT16_C(    27),  UINT16_C(   149),  UINT16_C(   191),  UINT16_C(   113) },
           INT8_C(     0),
       {   UINT16_C(   936),  UINT16_C( 16595),  UINT16_C(  7660),  UINT16_C(  5824),
           UINT16_C( 16630),  UINT16_C(  4885),  UINT16_C(  6422),  UINT16_C(  9066) } },
  };

  simde_uint16x8_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_u16(test_vec[i].a);
    b = simde_vld1q_u16(test_vec[i].b);
    v = simde_vld1q_u16(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_laneq_u16(a, b, v, 0); break;
      case 1: r = simde_vmlaq_laneq_u16(a, b, v, 1); break;
      case 2: r = simde_vmlaq_laneq_u16(a, b, v, 2); break;
      case 3: r = simde_vmlaq_laneq_u16(a, b, v, 3); break;
      case 4: r = simde_vmlaq_laneq_u16(a, b, v, 4); break;
      case 5: r = simde_vmlaq_laneq_u16(a, b, v, 5); break;
      case 6: r = simde_vmlaq_laneq_u16(a, b, v, 6); break;
      case 7: r = simde_vmlaq_laneq_u16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_u16(0); break;
    }
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t v[4];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
     { {   UINT32_C(     17966),  UINT32_C(      9668),  UINT32_C(      3899),  UINT32_C(      1740) },
       {   UINT32_C(      9644),  UINT32_C(      8215),  UINT32_C(     11766),  UINT32_C(      5182) },
       {   UINT32_C(      8131),  UINT32_C(      6197),  UINT32_C(     18142),  UINT32_C(      5160) },
           INT8_C(         1),
       {   UINT32_C(  59781834),  UINT32_C(  50918023),  UINT32_C(  72917801),  UINT32_C(  32114594) } },
     { {   UINT32_C(     14022),  UINT32_C(      5194),  UINT32_C(     11502),  UINT32_C(      5635) },
       {   UINT32_C(       877),  UINT32_C(     10991),  UINT32_C(      5463),  UINT32_C(       659) },
       {   UINT32_C(      5178),  UINT32_C(      1188),  UINT32_C(      9464),  UINT32_C(      1436) },
           INT8_C(         1),
       {   UINT32_C(   1055898),  UINT32_C(  13062502),  UINT32_C(   6501546),  UINT32_C(    788527) } },
     { {   UINT32_C(     18302),  UINT32_C(      8019),  UINT32_C(      7939),  UINT32_C(     15138) },
       {   UINT32_C(     13816),  UINT32_C(      3641),  UINT32_C(     16263),  UINT32_C(      7916) },
       {   UINT32_C(      3757),  UINT32_C(     13705),  UINT32_C(     13542),  UINT32_C(      4003) },
           INT8_C(         0),
       {   UINT32_C(  51925014),  UINT32_C(  13687256),  UINT32_C(  61108030),  UINT32_C(  29755550) } },
     { {   UINT32_C(     19118),  UINT32_C(      5278),  UINT32_C(     12843),  UINT32_C(      9921) },
       {   UINT32_C(     14624),  UINT32_C(      9994),  UINT32_C(      2130),  UINT32_C(      2980) },
       {   UINT32_C(     11531),  UINT32_C(      2465),  UINT32_C(      7359),  UINT32_C(     14489) },
           INT8_C(         2),
       {   UINT32_C( 107637134),  UINT32_C(  73551124),  UINT32_C(  15687513),  UINT32_C(  21939741) } },
     { {   UINT32_C(      6232),  UINT32_C(      4537),  UINT32_C(      1814),  UINT32_C(      3971) },
       {   UINT32_C(     12752),  UINT32_C(     14106),  UINT32_C(     17693),  UINT32_C(      1938) },
       {   UINT32_C(        44),  UINT32_C(       178),  UINT32_C(      1791),  UINT32_C(     12350) },
           INT8_C(         3),
       {   UINT32_C( 157493432),  UINT32_C( 174213637),  UINT32_C( 218510364),  UINT32_C(  23938271) } },
     { {   UINT32_C(      8462),  UINT32_C(      4455),  UINT32_C(     11958),  UINT32_C(     11866) },
       {   UINT32_C(      5206),  UINT32_C(     11522),  UINT32_C(      9962),  UINT32_C(     11203) },
       {   UINT32_C(      9268),  UINT32_C(     17392),  UINT32_C(     13804),  UINT32_C(     10799) },
           INT8_C(         2),
       {   UINT32_C(  71872086),  UINT32_C( 159054143),  UINT32_C( 137527406),  UINT32_C( 154658078) } },
     { {   UINT32_C(     15528),  UINT32_C(      7021),  UINT32_C(     16870),  UINT32_C(     13050) },
       {   UINT32_C(     10135),  UINT32_C(     12640),  UINT32_C(     13287),  UINT32_C(     19824) },
       {   UINT32_C(     19598),  UINT32_C(      1381),  UINT32_C(      6284),  UINT32_C(      6134) },
           INT8_C(         3),
       {   UINT32_C(  62183618),  UINT32_C(  77540781),  UINT32_C(  81519328),  UINT32_C( 121613466) } },
     { {   UINT32_C(     10824),  UINT32_C(     10467),  UINT32_C(     17351),  UINT32_C(      9295) },
       {   UINT32_C(     19858),  UINT32_C(     16339),  UINT32_C(     10310),  UINT32_C(      9300) },
       {   UINT32_C(     13406),  UINT32_C(      3924),  UINT32_C(     16158),  UINT32_C(     10460) },
           INT8_C(         2),
       {   UINT32_C( 320876388),  UINT32_C( 264016029),  UINT32_C( 166606331),  UINT32_C( 150278695) } },
  };

  simde_uint32x4_t r, a, b, v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_u32(test_vec[i].a);
    b = simde_vld1q_u32(test_vec[i].b);
    v = simde_vld1q_u32(test_vec[i].v);
    switch(test_vec[i].lane) {
      case 0: r = simde_vmlaq_laneq_u32(a, b, v, 0); break;
      case 1: r = simde_vmlaq_laneq_u32(a, b, v, 1); break;
      case 2: r = simde_vmlaq_laneq_u32(a, b, v, 2); break;
      case 3: r = simde_vmlaq_laneq_u32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_u32(0); break;
    }
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmla_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_laneq_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
