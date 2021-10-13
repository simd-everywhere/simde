
#define SIMDE_TEST_ARM_NEON_INSN mla_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mla_lane.h"

SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

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

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_lane_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
