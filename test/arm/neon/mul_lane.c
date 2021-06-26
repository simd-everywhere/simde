#define SIMDE_TEST_ARM_NEON_INSN mul_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mul_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vmul_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    int lane;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -773.99), SIMDE_FLOAT32_C(   962.49) },
      { SIMDE_FLOAT32_C(  -531.26), SIMDE_FLOAT32_C(   540.16) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-418078.41), SIMDE_FLOAT32_C(519898.56) } },
    { { SIMDE_FLOAT32_C(  -409.93), SIMDE_FLOAT32_C(   510.04) },
      { SIMDE_FLOAT32_C(  -659.02), SIMDE_FLOAT32_C(   102.89) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-42177.70), SIMDE_FLOAT32_C( 52478.02) } },
    { { SIMDE_FLOAT32_C(  -999.99), SIMDE_FLOAT32_C(  -702.78) },
      { SIMDE_FLOAT32_C(  -114.76), SIMDE_FLOAT32_C(   327.24) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-327236.72), SIMDE_FLOAT32_C(-229977.73) } },
    { { SIMDE_FLOAT32_C(   302.70), SIMDE_FLOAT32_C(  -977.40) },
      { SIMDE_FLOAT32_C(    45.80), SIMDE_FLOAT32_C(   892.47) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(270150.66), SIMDE_FLOAT32_C(-872300.19) } },
    { { SIMDE_FLOAT32_C(   306.93), SIMDE_FLOAT32_C(   371.14) },
      { SIMDE_FLOAT32_C(   546.46), SIMDE_FLOAT32_C(   323.18) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( 99193.63), SIMDE_FLOAT32_C(119945.02) } },
    { { SIMDE_FLOAT32_C(   148.94), SIMDE_FLOAT32_C(   -38.81) },
      { SIMDE_FLOAT32_C(  -107.93), SIMDE_FLOAT32_C(  -920.00) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-16075.09), SIMDE_FLOAT32_C(  4188.76) } },
    { { SIMDE_FLOAT32_C(  -268.22), SIMDE_FLOAT32_C(  -693.98) },
      { SIMDE_FLOAT32_C(  -987.79), SIMDE_FLOAT32_C(   200.52) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-53783.48), SIMDE_FLOAT32_C(-139156.88) } },
    { { SIMDE_FLOAT32_C(   646.59), SIMDE_FLOAT32_C(   790.59) },
      { SIMDE_FLOAT32_C(   356.21), SIMDE_FLOAT32_C(   987.57) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(230321.83), SIMDE_FLOAT32_C(281616.06) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);

    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmul_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmul_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   361.11) },
      { SIMDE_FLOAT64_C(  -650.09) },
      { SIMDE_FLOAT64_C(-234754.00) } },
    { { SIMDE_FLOAT64_C(    96.20) },
      { SIMDE_FLOAT64_C(   967.05) },
      { SIMDE_FLOAT64_C( 93030.21) } },
    { { SIMDE_FLOAT64_C(   -44.02) },
      { SIMDE_FLOAT64_C(   966.32) },
      { SIMDE_FLOAT64_C(-42537.41) } },
    { { SIMDE_FLOAT64_C(   207.91) },
      { SIMDE_FLOAT64_C(   922.18) },
      { SIMDE_FLOAT64_C(191730.44) } },
    { { SIMDE_FLOAT64_C(   263.40) },
      { SIMDE_FLOAT64_C(  -535.20) },
      { SIMDE_FLOAT64_C(-140971.68) } },
    { { SIMDE_FLOAT64_C(  -474.15) },
      { SIMDE_FLOAT64_C(   105.73) },
      { SIMDE_FLOAT64_C(-50131.88) } },
    { { SIMDE_FLOAT64_C(  -684.09) },
      { SIMDE_FLOAT64_C(  -137.80) },
      { SIMDE_FLOAT64_C( 94267.60) } },
    { { SIMDE_FLOAT64_C(   842.76) },
      { SIMDE_FLOAT64_C(  -239.29) },
      { SIMDE_FLOAT64_C(-201664.04) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vmul_lane_f64(a, b, 0);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vmul_lane_f64(a, b, 0);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int lane;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  3489), -INT16_C(  7576), -INT16_C( 15092), -INT16_C( 26073) },
      { -INT16_C(  7744),  INT16_C( 19101),  INT16_C( 14511),  INT16_C(  9522) },
       INT8_C(   1),
      {  INT16_C(  6723), -INT16_C(  5688),  INT16_C( 20572), -INT16_C( 12309) } },
    { {  INT16_C( 23915), -INT16_C( 31301), -INT16_C( 15588),  INT16_C(  8786) },
      { -INT16_C( 30436),  INT16_C(   797), -INT16_C( 13115), -INT16_C( 18589) },
       INT8_C(   0),
      {  INT16_C( 31412), -INT16_C( 19596),  INT16_C( 21264), -INT16_C( 23816) } },
    { { -INT16_C( 15291),  INT16_C( 28153), -INT16_C( 18082), -INT16_C(  1202) },
      { -INT16_C(   765),  INT16_C( 13875), -INT16_C( 11998),  INT16_C( 32673) },
       INT8_C(   0),
      {  INT16_C( 32207),  INT16_C( 24299),  INT16_C(  4634),  INT16_C(  2026) } },
    { { -INT16_C( 25562),  INT16_C( 30800),  INT16_C( 27838), -INT16_C(  9215) },
      { -INT16_C( 14481), -INT16_C( 11608), -INT16_C(  8834),  INT16_C( 16920) },
       INT8_C(   2),
      { -INT16_C( 22348),  INT16_C( 18272), -INT16_C( 29820),  INT16_C(  9598) } },
    { { -INT16_C( 24187), -INT16_C( 11376), -INT16_C( 27748), -INT16_C( 12079) },
      { -INT16_C(  3127),  INT16_C( 27297),  INT16_C( 11635),  INT16_C(  3984) },
       INT8_C(   1),
      { -INT16_C( 22875), -INT16_C( 21104),  INT16_C( 27932), -INT16_C(  8847) } },
    { { -INT16_C( 13048),  INT16_C(  2793),  INT16_C( 22953),  INT16_C( 21201) },
      {  INT16_C( 20267),  INT16_C( 17199),  INT16_C(  1426),  INT16_C( 13256) },
       INT8_C(   1),
      { -INT16_C( 17288), -INT16_C(  1081), -INT16_C( 20217), -INT16_C(  6305) } },
    { { -INT16_C( 12388),  INT16_C( 27945), -INT16_C(  3425),  INT16_C( 16480) },
      { -INT16_C( 11427), -INT16_C(  4754), -INT16_C(  5150), -INT16_C( 20234) },
       INT8_C(   1),
      { -INT16_C( 24312), -INT16_C(  9058),  INT16_C( 29522), -INT16_C( 30400) } },
    { {  INT16_C( 22784), -INT16_C( 11986),  INT16_C( 22955), -INT16_C(  9696) },
      { -INT16_C( 19811),  INT16_C( 26080),  INT16_C( 30181), -INT16_C( 19199) },
       INT8_C(   2),
      { -INT16_C( 25344),  INT16_C(  9254),  INT16_C( 23799), -INT16_C( 16736) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(INT16_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(INT16_C(0))), lane, a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   812559250),  INT32_C(    61009557) },
      { -INT32_C(   772897317), -INT32_C(  1898855627) },
       INT8_C(   1),
      { -INT32_C(  1640741690),  INT32_C(  1243341785) } },
    { { -INT32_C(  1018479966), -INT32_C(   193599468) },
      {  INT32_C(  1332370253),  INT32_C(  1690109968) },
       INT8_C(   1),
      {  INT32_C(   539146784),  INT32_C(   493035840) } },
    { {  INT32_C(   797440396), -INT32_C(   340499460) },
      {  INT32_C(   112126260), -INT32_C(  1314348937) },
       INT8_C(   1),
      { -INT32_C(  1542684652),  INT32_C(   683145764) } },
    { { -INT32_C(   506214805),  INT32_C(   607920314) },
      {  INT32_C(   757943407), -INT32_C(  1430665552) },
       INT8_C(   0),
      {  INT32_C(  2039073893),  INT32_C(    41642150) } },
    { { -INT32_C(  1666079000),  INT32_C(  1082516881) },
      { -INT32_C(  1797194261),  INT32_C(  1962920878) },
       INT8_C(   0),
      { -INT32_C(  1811448072),  INT32_C(  1101662491) } },
    { {  INT32_C(   482226144), -INT32_C(  2140656045) },
      {  INT32_C(   340203867),  INT32_C(  1778226627) },
       INT8_C(   0),
      { -INT32_C(  1855462240),  INT32_C(   647205505) } },
    { {  INT32_C(   522976153),  INT32_C(   454825787) },
      { -INT32_C(  1427715413),  INT32_C(  1854637119) },
       INT8_C(   0),
      {  INT32_C(   744343859),  INT32_C(  1394217577) } },
    { {  INT32_C(   275825063), -INT32_C(  1993749694) },
      { -INT32_C(   585175840),  INT32_C(  1349936213) },
       INT8_C(   1),
      { -INT32_C(   200308621),  INT32_C(   783434986) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmul_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_int32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmul_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), lane, a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    int lane;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(56255), UINT16_C(10796), UINT16_C(17520), UINT16_C( 1280) },
      { UINT16_C(42772), UINT16_C(28649), UINT16_C(61065), UINT16_C(17278) },
       INT8_C(   2),
      { UINT16_C(11063), UINT16_C(31116), UINT16_C(49136), UINT16_C(44288) } },
    { { UINT16_C(14034), UINT16_C(28449), UINT16_C( 1540), UINT16_C(20273) },
      { UINT16_C( 7493), UINT16_C(63190), UINT16_C(54710), UINT16_C(37301) },
       INT8_C(   2),
      { UINT16_C(45900), UINT16_C(30326), UINT16_C(39640), UINT16_C( 4566) } },
    { { UINT16_C(  479), UINT16_C(57158), UINT16_C(23046), UINT16_C(61574) },
      { UINT16_C( 4297), UINT16_C(18398), UINT16_C(58707), UINT16_C(35353) },
       INT8_C(   2),
      { UINT16_C( 5709), UINT16_C(  434), UINT16_C(36338), UINT16_C(55666) } },
    { { UINT16_C(36488), UINT16_C(47628), UINT16_C(20958), UINT16_C(46295) },
      { UINT16_C(36167), UINT16_C(64650), UINT16_C(35871), UINT16_C( 8411) },
       INT8_C(   2),
      { UINT16_C(41592), UINT16_C( 6004), UINT16_C(20962), UINT16_C(31241) } },
    { { UINT16_C(10170), UINT16_C(16684), UINT16_C(62743), UINT16_C(62801) },
      { UINT16_C(42045), UINT16_C(22234), UINT16_C(57390), UINT16_C(48607) },
       INT8_C(   1),
      { UINT16_C(20580), UINT16_C(18296), UINT16_C(28566), UINT16_C( 7418) } },
    { { UINT16_C(39833), UINT16_C(28734), UINT16_C(34383), UINT16_C(55806) },
      { UINT16_C( 7554), UINT16_C(24165), UINT16_C(14141), UINT16_C(25624) },
       INT8_C(   3),
      { UINT16_C(23128), UINT16_C(48592), UINT16_C(29544), UINT16_C(42960) } },
    { { UINT16_C(31577), UINT16_C(43609), UINT16_C(38513), UINT16_C(19279) },
      { UINT16_C(32236), UINT16_C(52012), UINT16_C( 6458), UINT16_C(54628) },
       INT8_C(   3),
      { UINT16_C(15300), UINT16_C(38852), UINT16_C(51492), UINT16_C( 9692) } },
    { { UINT16_C( 9685), UINT16_C(54237), UINT16_C(24830), UINT16_C(25840) },
      { UINT16_C(11710), UINT16_C(54939), UINT16_C(65426), UINT16_C( 3376) },
       INT8_C(   0),
      { UINT16_C(34070), UINT16_C( 5894), UINT16_C(41604), UINT16_C( 6688) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(INT16_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_uint16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(UINT16_C(0))), lane, a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    int lane;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3751696772), UINT32_C(  92944092) },
      { UINT32_C(  95534389), UINT32_C( 347736448) },
       INT8_C(   1),
      { UINT32_C(3124389376), UINT32_C(2900437504) } },
    { { UINT32_C(2311291488), UINT32_C(2163324479) },
      { UINT32_C(2637368739), UINT32_C(1965198108) },
       INT8_C(   0),
      { UINT32_C(2117788448), UINT32_C(1370832157) } },
    { { UINT32_C(2338345473), UINT32_C( 155751767) },
      { UINT32_C(1427294362), UINT32_C(1605700573) },
       INT8_C(   1),
      { UINT32_C(3479295453), UINT32_C(  26650907) } },
    { { UINT32_C( 797286206), UINT32_C(1379739679) },
      { UINT32_C(3890108869), UINT32_C( 552077518) },
       INT8_C(   0),
      { UINT32_C( 267655350), UINT32_C(1340384987) } },
    { { UINT32_C(3170728052), UINT32_C(2475005825) },
      { UINT32_C(2728354540), UINT32_C(1625321153) },
       INT8_C(   1),
      { UINT32_C(1247389556), UINT32_C(2410718785) } },
    { { UINT32_C(1293647632), UINT32_C(2963726546) },
      { UINT32_C(2964878536), UINT32_C( 220471445) },
       INT8_C(   1),
      { UINT32_C(4280480848), UINT32_C(4106426938) } },
    { { UINT32_C(1723109089), UINT32_C(3234373921) },
      { UINT32_C( 590252355), UINT32_C(1764958698) },
       INT8_C(   0),
      { UINT32_C(4045786595), UINT32_C(1235932323) } },
    { { UINT32_C( 639449984), UINT32_C(2744903147) },
      { UINT32_C(3133354133), UINT32_C(3415990333) },
       INT8_C(   1),
      { UINT32_C( 797388160), UINT32_C(4087113983) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmul_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(UINT32_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_uint32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmul_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(UINT32_C(0))), lane, a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[8];
    int lane;
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 29679),  INT16_C( 23726), -INT16_C( 18708),  INT16_C(  4148) },
      { -INT16_C( 26928),  INT16_C( 16626), -INT16_C( 26452),  INT16_C( 15460),  INT16_C( 29248), -INT16_C( 20578),  INT16_C( 13332), -INT16_C(  5537) },
       INT8_C(   0),
      {  INT16_C( 15408),  INT16_C( 16736), -INT16_C(  6208), -INT16_C( 24000) } },
    { { -INT16_C( 11646), -INT16_C( 16687), -INT16_C(  5157),  INT16_C( 20141) },
      {  INT16_C(  2458),  INT16_C( 20539),  INT16_C( 19261), -INT16_C( 11488),  INT16_C( 24893), -INT16_C( 10880), -INT16_C( 17211),  INT16_C( 14102) },
       INT8_C(   2),
      {  INT16_C( 16122), -INT16_C( 19763),  INT16_C( 23599),  INT16_C( 28217) } },
    { {  INT16_C( 19397),  INT16_C(  9614),  INT16_C(  3893),  INT16_C(  1959) },
      {  INT16_C( 26080), -INT16_C( 13341),  INT16_C( 12562),  INT16_C(  7013), -INT16_C( 18836), -INT16_C( 18343),  INT16_C( 11478),  INT16_C( 14325) },
       INT8_C(   4),
      {  INT16_C(  1308), -INT16_C( 13336),  INT16_C(  6236), -INT16_C(  2956) } },
    { { -INT16_C(   821), -INT16_C(  7832), -INT16_C( 15565),  INT16_C( 32678) },
      { -INT16_C( 13487),  INT16_C( 24756), -INT16_C( 17294), -INT16_C( 10432),  INT16_C(  3231), -INT16_C( 12055),  INT16_C(  1393),  INT16_C( 10045) },
       INT8_C(   6),
      { -INT16_C( 29541), -INT16_C( 31000),  INT16_C( 10371), -INT16_C( 27066) } },
    { { -INT16_C(   267), -INT16_C(  5494),  INT16_C( 14133),  INT16_C( 12981) },
      { -INT16_C( 26977),  INT16_C( 25189), -INT16_C(  7107),  INT16_C(  2228),  INT16_C(  5273),  INT16_C( 21883),  INT16_C( 21077),  INT16_C( 25076) },
       INT8_C(   4),
      { -INT16_C( 31635), -INT16_C(  2950),  INT16_C(  8877),  INT16_C( 29229) } },
    { { -INT16_C( 11580),  INT16_C(   321), -INT16_C( 24582), -INT16_C(  1802) },
      { -INT16_C(  7895),  INT16_C( 24621),  INT16_C( 24470),  INT16_C( 11520),  INT16_C( 25285), -INT16_C( 22166),  INT16_C( 29206),  INT16_C( 11074) },
       INT8_C(   5),
      { -INT16_C( 22232),  INT16_C( 28138),  INT16_C( 18308),  INT16_C( 31708) } },
    { { -INT16_C( 32617), -INT16_C( 29888),  INT16_C( 31969), -INT16_C( 19632) },
      {  INT16_C( 20925),  INT16_C( 23725), -INT16_C( 23224),  INT16_C( 10629), -INT16_C(  6445),  INT16_C( 12991), -INT16_C(  4890),  INT16_C( 18679) },
       INT8_C(   6),
      { -INT16_C( 17494),  INT16_C(  7040), -INT16_C( 25050), -INT16_C(  9760) } },
    { {  INT16_C( 24481), -INT16_C(  7223), -INT16_C( 18806),  INT16_C(  2683) },
      {  INT16_C(  1782),  INT16_C( 29419), -INT16_C( 25002), -INT16_C( 22481), -INT16_C( 29876), -INT16_C(  3600),  INT16_C(  6417), -INT16_C(  2108) },
       INT8_C(   0),
      { -INT16_C( 21834), -INT16_C( 26330), -INT16_C( 23396), -INT16_C(  3022) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmul_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(INT16_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_int16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmul_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(INT16_C(0))), lane, a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[4];
    int lane;
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   134455319),  INT32_C(  1531630983) },
      {  INT32_C(   480645313), -INT32_C(  1790804458), -INT32_C(  1570324603), -INT32_C(   409939960) },
       INT8_C(   3),
      {  INT32_C(     2076856), -INT32_C(  1799070664) } },
    { {  INT32_C(   924604500), -INT32_C(  2142245920) },
      { -INT32_C(  1022928914), -INT32_C(  1299881310), -INT32_C(  2016829176), -INT32_C(  1576247581) },
       INT8_C(   1),
      {  INT32_C(    90443048),  INT32_C(   373228480) } },
    { {  INT32_C(  1049996206), -INT32_C(   359501422) },
      {  INT32_C(  2026555789),  INT32_C(  1885817368), -INT32_C(  1273877934),  INT32_C(  1371391151) },
       INT8_C(   1),
      {  INT32_C(  1420452944), -INT32_C(   464725584) } },
    { {  INT32_C(  1357657156), -INT32_C(  2097237545) },
      { -INT32_C(  1223410618), -INT32_C(  1757086002),  INT32_C(   313572808),  INT32_C(  1315184676) },
       INT8_C(   2),
      {  INT32_C(  1373571360), -INT32_C(  1038701832) } },
    { { -INT32_C(   688456167), -INT32_C(  2095414193) },
      {  INT32_C(   559573616), -INT32_C(  1536697240), -INT32_C(   294510608),  INT32_C(   548800867) },
       INT8_C(   1),
      { -INT32_C(   691816920), -INT32_C(   465394664) } },
    { {  INT32_C(   769213641), -INT32_C(  1857680493) },
      { -INT32_C(  2032133118), -INT32_C(  1594465482), -INT32_C(  1710745666), -INT32_C(  1651790722) },
       INT8_C(   2),
      { -INT32_C(  1665721298), -INT32_C(   409023462) } },
    { {  INT32_C(   807928185),  INT32_C(  1727652129) },
      { -INT32_C(   956750149), -INT32_C(  1983346067), -INT32_C(   843035030),  INT32_C(  1535860804) },
       INT8_C(   1),
      { -INT32_C(   111420795),  INT32_C(   378053901) } },
    { { -INT32_C(  1323967962),  INT32_C(  2016031863) },
      {  INT32_C(  1033525852),  INT32_C(  2063073363), -INT32_C(  2081964039), -INT32_C(   689082233) },
       INT8_C(   0),
      { -INT32_C(  1687699032), -INT32_C(   265113404) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), lane, a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[8];
    int lane;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(52948), UINT16_C( 6195), UINT16_C(29421), UINT16_C(28183) },
      { UINT16_C(63102), UINT16_C(28477), UINT16_C(21749), UINT16_C(36414), UINT16_C(30420), UINT16_C( 9044), UINT16_C(19198), UINT16_C(31066) },
       INT8_C(   3),
      { UINT16_C(44888), UINT16_C( 9818), UINT16_C(19302), UINT16_C(27538) } },
    { { UINT16_C(18807), UINT16_C(22650), UINT16_C(11997), UINT16_C(43820) },
      { UINT16_C(17505), UINT16_C(54424), UINT16_C( 1627), UINT16_C(20818), UINT16_C(49475), UINT16_C(38983), UINT16_C(54528), UINT16_C(30316) },
       INT8_C(   2),
      { UINT16_C(59213), UINT16_C(20318), UINT16_C(54927), UINT16_C(57508) } },
    { { UINT16_C(29840), UINT16_C(60020), UINT16_C(53229), UINT16_C(13921) },
      { UINT16_C(47433), UINT16_C(30483), UINT16_C(48869), UINT16_C(10969), UINT16_C(44374), UINT16_C(23685), UINT16_C(55295), UINT16_C(49568) },
       INT8_C(   6),
      { UINT16_C( 2928), UINT16_C(62860), UINT16_C(10259), UINT16_C(41375) } },
    { { UINT16_C(49464), UINT16_C(42227), UINT16_C( 7479), UINT16_C(43828) },
      { UINT16_C( 7825), UINT16_C(24728), UINT16_C(52864), UINT16_C(14762), UINT16_C( 8674), UINT16_C(40991), UINT16_C(18938), UINT16_C(42999) },
       INT8_C(   6),
      { UINT16_C(43184), UINT16_C(24654), UINT16_C(14006), UINT16_C( 1224) } },
    { { UINT16_C(42835), UINT16_C(62373), UINT16_C(50024), UINT16_C(10539) },
      { UINT16_C(53431), UINT16_C(54368), UINT16_C( 2820), UINT16_C( 9062), UINT16_C(50851), UINT16_C(29091), UINT16_C(56432), UINT16_C(37459) },
       INT8_C(   3),
      { UINT16_C( 1042), UINT16_C(41662), UINT16_C( 4976), UINT16_C(18466) } },
    { { UINT16_C(36084), UINT16_C(60228), UINT16_C( 4916), UINT16_C(56126) },
      { UINT16_C(12984), UINT16_C(31811), UINT16_C(27741), UINT16_C(11571), UINT16_C( 1996), UINT16_C(55090), UINT16_C(21869), UINT16_C(13434) },
       INT8_C(   0),
      { UINT16_C(63328), UINT16_C(24800), UINT16_C(62816), UINT16_C(45200) } },
    { { UINT16_C(42219), UINT16_C(16340), UINT16_C(53302), UINT16_C(49971) },
      { UINT16_C( 7700), UINT16_C(10231), UINT16_C(53852), UINT16_C(36576), UINT16_C(23573), UINT16_C(33260), UINT16_C( 6543), UINT16_C(38477) },
       INT8_C(   3),
      { UINT16_C(42912), UINT16_C(29056), UINT16_C( 9024), UINT16_C( 5792) } },
    { { UINT16_C( 1060), UINT16_C(40608), UINT16_C(38968), UINT16_C(56457) },
      { UINT16_C(51309), UINT16_C(15635), UINT16_C(55035), UINT16_C( 6481), UINT16_C(31181), UINT16_C(40822), UINT16_C( 1113), UINT16_C(46516) },
       INT8_C(   0),
      { UINT16_C(58196), UINT16_C(35360), UINT16_C(36824), UINT16_C(61013) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmul_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(INT16_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_uint16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmul_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(UINT16_C(0))), lane, a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[4];
    int lane;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3450459403), UINT32_C(3957622860) },
      { UINT32_C(2498677658), UINT32_C(3863553438), UINT32_C( 177779406), UINT32_C(2584336350) },
       INT8_C(   0),
      { UINT32_C(3495158174), UINT32_C(3325444536) } },
    { { UINT32_C(1176483947), UINT32_C(3243325932) },
      { UINT32_C(1779245026), UINT32_C(3456432131), UINT32_C( 191731942), UINT32_C(2497270753) },
       INT8_C(   3),
      { UINT32_C( 425641739), UINT32_C(3342298220) } },
    { { UINT32_C(3972231907), UINT32_C(3310901005) },
      { UINT32_C(2947653238), UINT32_C( 244413167), UINT32_C(2014444415), UINT32_C(2539577599) },
       INT8_C(   1),
      { UINT32_C(2419349485), UINT32_C(2560233251) } },
    { { UINT32_C(1134590314), UINT32_C(2133297933) },
      { UINT32_C(2777420622), UINT32_C( 152785515), UINT32_C(1996081667), UINT32_C(1458898779) },
       INT8_C(   1),
      { UINT32_C( 858043214), UINT32_C(4017113199) } },
    { { UINT32_C(3438892397), UINT32_C(1714833133) },
      { UINT32_C(1903393254), UINT32_C(3032543904), UINT32_C(3508495743), UINT32_C(1272195457) },
       INT8_C(   2),
      { UINT32_C(1670930963), UINT32_C( 849064083) } },
    { { UINT32_C(1076471626), UINT32_C(1403863805) },
      { UINT32_C(2168486203), UINT32_C( 694658735), UINT32_C( 197777689), UINT32_C(4270488985) },
       INT8_C(   1),
      { UINT32_C( 129587094), UINT32_C(  95148275) } },
    { { UINT32_C( 818315099), UINT32_C(1920657611) },
      { UINT32_C(1416608273), UINT32_C(3784295016), UINT32_C(2828079362), UINT32_C(1371650680) },
       INT8_C(   3),
      { UINT32_C(3828273320), UINT32_C(2999688488) } },
    { { UINT32_C(1459743437), UINT32_C(1756602089) },
      { UINT32_C(1278468964), UINT32_C( 408790365), UINT32_C(3615535381), UINT32_C(1390043457) },
       INT8_C(   2),
      { UINT32_C( 134217681), UINT32_C(3944423965) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(UINT32_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_uint32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(UINT32_C(0))), lane, a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[2];
    int lane;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   213.13), SIMDE_FLOAT32_C(   981.87), SIMDE_FLOAT32_C(   831.27), SIMDE_FLOAT32_C(   118.60) },
      { SIMDE_FLOAT32_C(  -324.54), SIMDE_FLOAT32_C(   912.98) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-69169.21), SIMDE_FLOAT32_C(-318656.09), SIMDE_FLOAT32_C(-269780.38), SIMDE_FLOAT32_C(-38490.45) } },
    { { SIMDE_FLOAT32_C(   398.02), SIMDE_FLOAT32_C(    -7.67), SIMDE_FLOAT32_C(   260.87), SIMDE_FLOAT32_C(   702.83) },
      { SIMDE_FLOAT32_C(   333.84), SIMDE_FLOAT32_C(   873.07) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(347499.31), SIMDE_FLOAT32_C( -6696.45), SIMDE_FLOAT32_C(227757.77), SIMDE_FLOAT32_C(613619.81) } },
    { { SIMDE_FLOAT32_C(  -354.62), SIMDE_FLOAT32_C(   438.98), SIMDE_FLOAT32_C(    27.69), SIMDE_FLOAT32_C(  -892.52) },
      { SIMDE_FLOAT32_C(   356.02), SIMDE_FLOAT32_C(  -450.46) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-126251.80), SIMDE_FLOAT32_C(156285.66), SIMDE_FLOAT32_C(  9858.19), SIMDE_FLOAT32_C(-317754.97) } },
    { { SIMDE_FLOAT32_C(  -796.85), SIMDE_FLOAT32_C(   254.52), SIMDE_FLOAT32_C(   640.39), SIMDE_FLOAT32_C(   497.52) },
      { SIMDE_FLOAT32_C(   257.72), SIMDE_FLOAT32_C(    -9.95) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  7928.66), SIMDE_FLOAT32_C( -2532.47), SIMDE_FLOAT32_C( -6371.88), SIMDE_FLOAT32_C( -4950.32) } },
    { { SIMDE_FLOAT32_C(  -951.01), SIMDE_FLOAT32_C(  -981.56), SIMDE_FLOAT32_C(    34.30), SIMDE_FLOAT32_C(   262.12) },
      { SIMDE_FLOAT32_C(  -999.70), SIMDE_FLOAT32_C(  -134.44) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(950724.69), SIMDE_FLOAT32_C(981265.56), SIMDE_FLOAT32_C(-34289.71), SIMDE_FLOAT32_C(-262041.36) } },
    { { SIMDE_FLOAT32_C(  -324.23), SIMDE_FLOAT32_C(  -221.45), SIMDE_FLOAT32_C(   748.19), SIMDE_FLOAT32_C(  -926.22) },
      { SIMDE_FLOAT32_C(   770.88), SIMDE_FLOAT32_C(     9.06) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( -2937.52), SIMDE_FLOAT32_C( -2006.34), SIMDE_FLOAT32_C(  6778.60), SIMDE_FLOAT32_C( -8391.55) } },
    { { SIMDE_FLOAT32_C(   104.72), SIMDE_FLOAT32_C(  -117.86), SIMDE_FLOAT32_C(  -296.55), SIMDE_FLOAT32_C(   750.10) },
      { SIMDE_FLOAT32_C(  -678.89), SIMDE_FLOAT32_C(   731.14) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( 76564.98), SIMDE_FLOAT32_C(-86172.16), SIMDE_FLOAT32_C(-216819.56), SIMDE_FLOAT32_C(548428.12) } },
    { { SIMDE_FLOAT32_C(   677.13), SIMDE_FLOAT32_C(  -719.32), SIMDE_FLOAT32_C(  -444.57), SIMDE_FLOAT32_C(   880.28) },
      { SIMDE_FLOAT32_C(   535.19), SIMDE_FLOAT32_C(  -804.18) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(362393.22), SIMDE_FLOAT32_C(-384972.88), SIMDE_FLOAT32_C(-237929.42), SIMDE_FLOAT32_C(471117.06) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);

    simde_float32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vmulq_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vmulq_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[1];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -207.09), SIMDE_FLOAT64_C(   185.86) },
      { SIMDE_FLOAT64_C(   705.49) },
      { SIMDE_FLOAT64_C(-146099.92), SIMDE_FLOAT64_C(131122.37) } },
    { { SIMDE_FLOAT64_C(  -158.10), SIMDE_FLOAT64_C(   204.30) },
      { SIMDE_FLOAT64_C(  -260.21) },
      { SIMDE_FLOAT64_C( 41139.20), SIMDE_FLOAT64_C(-53160.90) } },
    { { SIMDE_FLOAT64_C(  -895.97), SIMDE_FLOAT64_C(   204.60) },
      { SIMDE_FLOAT64_C(   605.35) },
      { SIMDE_FLOAT64_C(-542375.44), SIMDE_FLOAT64_C(123854.61) } },
    { { SIMDE_FLOAT64_C(  -515.25), SIMDE_FLOAT64_C(   880.37) },
      { SIMDE_FLOAT64_C(  -616.10) },
      { SIMDE_FLOAT64_C(317445.53), SIMDE_FLOAT64_C(-542395.96) } },
    { { SIMDE_FLOAT64_C(  -767.06), SIMDE_FLOAT64_C(   954.16) },
      { SIMDE_FLOAT64_C(  -845.22) },
      { SIMDE_FLOAT64_C(648334.45), SIMDE_FLOAT64_C(-806475.12) } },
    { { SIMDE_FLOAT64_C(   242.00), SIMDE_FLOAT64_C(   730.77) },
      { SIMDE_FLOAT64_C(   259.50) },
      { SIMDE_FLOAT64_C( 62799.00), SIMDE_FLOAT64_C(189634.82) } },
    { { SIMDE_FLOAT64_C(  -875.86), SIMDE_FLOAT64_C(  -565.78) },
      { SIMDE_FLOAT64_C(     9.60) },
      { SIMDE_FLOAT64_C( -8408.26), SIMDE_FLOAT64_C( -5431.49) } },
    { { SIMDE_FLOAT64_C(  -554.75), SIMDE_FLOAT64_C(  -834.64) },
      { SIMDE_FLOAT64_C(  -132.82) },
      { SIMDE_FLOAT64_C( 73681.89), SIMDE_FLOAT64_C(110856.88) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vmulq_lane_f64(a, b, 0);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);

    simde_float64x2_t r = simde_vmulq_lane_f64(a, b, 0);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[4];
    int lane;
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 30459), -INT16_C( 14985),  INT16_C(  2555),  INT16_C(  2281), -INT16_C( 19504),  INT16_C( 11036),  INT16_C( 25139), -INT16_C( 29002) },
      { -INT16_C(  3894),  INT16_C( 24172),  INT16_C( 15210),  INT16_C( 12261) },
       INT8_C(   2),
      {  INT16_C(  7406),  INT16_C( 12358), -INT16_C(  1298),  INT16_C( 25466),  INT16_C( 25632),  INT16_C( 19864),  INT16_C( 27166),  INT16_C(  2396) } },
    { { -INT16_C( 17676),  INT16_C( 26584), -INT16_C(  1959), -INT16_C( 12446),  INT16_C( 10095),  INT16_C( 30922), -INT16_C( 11760), -INT16_C( 15288) },
      {  INT16_C( 29678),  INT16_C( 20727), -INT16_C( 31446),  INT16_C(  6682) },
       INT8_C(   2),
      {  INT16_C( 28680),  INT16_C( 16752), -INT16_C(  1126), -INT16_C(  4076),  INT16_C(  9014), -INT16_C( 15580), -INT16_C( 14688), -INT16_C( 25648) } },
    { { -INT16_C( 31624),  INT16_C( 23853),  INT16_C(  2995),  INT16_C( 27985), -INT16_C( 18205), -INT16_C(  9273), -INT16_C( 27110),  INT16_C( 16714) },
      { -INT16_C( 15775),  INT16_C( 13138),  INT16_C(  5642),  INT16_C( 32290) },
       INT8_C(   1),
      {  INT16_C( 22128), -INT16_C( 12438),  INT16_C( 26710),  INT16_C(  9970),  INT16_C( 29110),  INT16_C(  2750),  INT16_C( 16980), -INT16_C( 22604) } },
    { { -INT16_C( 22414), -INT16_C( 29294), -INT16_C( 31550),  INT16_C( 17925),  INT16_C( 25521), -INT16_C( 17159),  INT16_C( 26548),  INT16_C( 28064) },
      {  INT16_C( 31534), -INT16_C( 15225), -INT16_C( 13882), -INT16_C( 30683) },
       INT8_C(   3),
      { -INT16_C(  6022),  INT16_C(  1562),  INT16_C( 16394), -INT16_C( 14663),  INT16_C( 28821), -INT16_C( 26627), -INT16_C( 25340), -INT16_C( 10208) } },
    { { -INT16_C( 27815),  INT16_C( 31537),  INT16_C( 15889), -INT16_C( 17939),  INT16_C( 31440),  INT16_C( 21883), -INT16_C( 16000), -INT16_C(  7418) },
      { -INT16_C( 15430),  INT16_C(  8599),  INT16_C(  1123), -INT16_C(  8625) },
       INT8_C(   0),
      { -INT16_C(  9814), -INT16_C( 11110),  INT16_C(  2906), -INT16_C( 25294), -INT16_C( 21728), -INT16_C( 13218),  INT16_C(  5888), -INT16_C( 31652) } },
    { { -INT16_C( 23532),  INT16_C( 14677),  INT16_C( 28717), -INT16_C( 16238),  INT16_C(  3489), -INT16_C(  8239), -INT16_C( 29957),  INT16_C( 30127) },
      {  INT16_C(  1029), -INT16_C( 14603), -INT16_C( 10229), -INT16_C( 12672) },
       INT8_C(   0),
      { -INT16_C( 31644),  INT16_C( 29353), -INT16_C(  6943),  INT16_C(  2778), -INT16_C( 14299), -INT16_C( 23787), -INT16_C( 23833),  INT16_C(  2155) } },
    { {  INT16_C( 12706), -INT16_C(  3724),  INT16_C(    15), -INT16_C( 19451),  INT16_C( 16213), -INT16_C( 14879), -INT16_C( 24111), -INT16_C(  8346) },
      {  INT16_C( 17778), -INT16_C(   806),  INT16_C( 20469), -INT16_C(  1791) },
       INT8_C(   1),
      { -INT16_C( 17420), -INT16_C( 13112), -INT16_C( 12090),  INT16_C( 14402), -INT16_C( 26014), -INT16_C(   614), -INT16_C( 30726), -INT16_C( 23332) } },
    { {  INT16_C(  1223),  INT16_C( 18205), -INT16_C( 29230),  INT16_C(  1001), -INT16_C(  9470),  INT16_C(   531), -INT16_C( 14368),  INT16_C(  8024) },
      {  INT16_C(  7592),  INT16_C( 18929), -INT16_C( 12156), -INT16_C( 13893) },
       INT8_C(   2),
      {  INT16_C(  9884),  INT16_C( 15092), -INT16_C( 16312),  INT16_C( 21540), -INT16_C( 29432), -INT16_C( 32308),  INT16_C(  3968), -INT16_C( 22176) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x8_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(INT16_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int16x8_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(INT16_C(0))), lane, a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[2];
    int lane;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   568356878), -INT32_C(  2094014030), -INT32_C(  1281537859),  INT32_C(   987407471) },
      {  INT32_C(   136707343),  INT32_C(   800378846) },
       INT8_C(   0),
      {  INT32_C(  1827301074),  INT32_C(   815080302),  INT32_C(  1651182611), -INT32_C(  1017358975) } },
    { {  INT32_C(   682706454), -INT32_C(  1992917223),  INT32_C(  1094408031), -INT32_C(   805388666) },
      {  INT32_C(     4108892), -INT32_C(  1995409012) },
       INT8_C(   0),
      { -INT32_C(   607880216), -INT32_C(    66908420), -INT32_C(   585796572),  INT32_C(    75080744) } },
    { { -INT32_C(   865245416), -INT32_C(   572270441),  INT32_C(   150342537), -INT32_C(  1721204670) },
      {  INT32_C(  2048960955),  INT32_C(  1507258279) },
       INT8_C(   1),
      {  INT32_C(    78489768),  INT32_C(    68240257), -INT32_C(   758354593), -INT32_C(   871020274) } },
    { { -INT32_C(   425269802), -INT32_C(   687913617), -INT32_C(  1972515918), -INT32_C(  1173075026) },
      { -INT32_C(  1040442303),  INT32_C(   763204996) },
       INT8_C(   1),
      { -INT32_C(   380497832), -INT32_C(   650352580),  INT32_C(   135635400),  INT32_C(  1283017656) } },
    { { -INT32_C(   844835337),  INT32_C(   346280494), -INT32_C(  1115452808),  INT32_C(  1416649097) },
      {  INT32_C(   302250695),  INT32_C(   726908174) },
       INT8_C(   1),
      { -INT32_C(   854585726), -INT32_C(   234130300), -INT32_C(  2024527216), -INT32_C(  1700132226) } },
    { { -INT32_C(  1840337131), -INT32_C(  1299643171),  INT32_C(  2061522600), -INT32_C(  2081164039) },
      { -INT32_C(   787697545),  INT32_C(   462971168) },
       INT8_C(   0),
      {  INT32_C(  1961743043), -INT32_C(   664456517), -INT32_C(  1849964520), -INT32_C(   746713153) } },
    { { -INT32_C(    48158294),  INT32_C(    68344404),  INT32_C(   752985128), -INT32_C(  2083155155) },
      {  INT32_C(  1753042803), -INT32_C(   203489214) },
       INT8_C(   1),
      { -INT32_C(   341656108), -INT32_C(   133674584), -INT32_C(  1996205488), -INT32_C(   398265958) } },
    { {  INT32_C(  1215173552),  INT32_C(  1492308526), -INT32_C(   844304141), -INT32_C(  1477070846) },
      {  INT32_C(   617882257),  INT32_C(  1184389367) },
       INT8_C(   1),
      { -INT32_C(  1988526384), -INT32_C(  1445422494),  INT32_C(  1727529589), -INT32_C(  1883405842) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vmulq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_int32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vmulq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), lane, a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[4];
    int lane;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(36602), UINT16_C(26614), UINT16_C(29299), UINT16_C(24022), UINT16_C(34078), UINT16_C(58723), UINT16_C(45747), UINT16_C(62564) },
      { UINT16_C( 7589), UINT16_C( 1166), UINT16_C(56009), UINT16_C(61188) },
       INT8_C(   3),
      { UINT16_C(41448), UINT16_C(18904), UINT16_C( 9932), UINT16_C(16728), UINT16_C( 5752), UINT16_C(  652), UINT16_C(59340), UINT16_C(11664) } },
    { { UINT16_C(64917), UINT16_C(25813), UINT16_C(51482), UINT16_C(43102), UINT16_C(50623), UINT16_C(12827), UINT16_C(31132), UINT16_C( 8528) },
      { UINT16_C(14044), UINT16_C(36565), UINT16_C(51610), UINT16_C(46900) },
       INT8_C(   3),
      { UINT16_C( 1348), UINT16_C(48708), UINT16_C(28488), UINT16_C(25880), UINT16_C(46028), UINT16_C(31356), UINT16_C(14256), UINT16_C(62528) } },
    { { UINT16_C(32824), UINT16_C(15409), UINT16_C(50287), UINT16_C(27858), UINT16_C(13977), UINT16_C(25223), UINT16_C(12180), UINT16_C(22818) },
      { UINT16_C(21579), UINT16_C(50421), UINT16_C( 6052), UINT16_C(55968) },
       INT8_C(   0),
      { UINT16_C(61544), UINT16_C(46683), UINT16_C(63621), UINT16_C(51590), UINT16_C(13011), UINT16_C(10637), UINT16_C(32860), UINT16_C(17654) } },
    { { UINT16_C(29743), UINT16_C(25525), UINT16_C( 3116), UINT16_C(44187), UINT16_C(55101), UINT16_C(  284), UINT16_C(34985), UINT16_C(57243) },
      { UINT16_C(64783), UINT16_C(16243), UINT16_C(52511), UINT16_C(29578) },
       INT8_C(   2),
      { UINT16_C(46257), UINT16_C( 1003), UINT16_C(46420), UINT16_C( 1477), UINT16_C(59747), UINT16_C(36452), UINT16_C(57719), UINT16_C(12997) } },
    { { UINT16_C( 6222), UINT16_C(61145), UINT16_C(50674), UINT16_C(26397), UINT16_C(32890), UINT16_C(34451), UINT16_C(16155), UINT16_C(62403) },
      { UINT16_C(50523), UINT16_C(58524), UINT16_C(31840), UINT16_C(24051) },
       INT8_C(   3),
      { UINT16_C(26634), UINT16_C(36091), UINT16_C(52918), UINT16_C(27015), UINT16_C(17870), UINT16_C( 9353), UINT16_C(46497), UINT16_C(14617) } },
    { { UINT16_C(32050), UINT16_C(48316), UINT16_C(32752), UINT16_C( 2058), UINT16_C(63832), UINT16_C( 7931), UINT16_C(25110), UINT16_C(38808) },
      { UINT16_C( 8181), UINT16_C(13490), UINT16_C(42466), UINT16_C(42896) },
       INT8_C(   2),
      { UINT16_C(49188), UINT16_C(51704), UINT16_C(41440), UINT16_C(35540), UINT16_C(55216), UINT16_C( 8342), UINT16_C(50540), UINT16_C(52272) } },
    { { UINT16_C( 1908), UINT16_C(26558), UINT16_C(44389), UINT16_C(58010), UINT16_C(22122), UINT16_C(59858), UINT16_C(56161), UINT16_C(23105) },
      { UINT16_C(24534), UINT16_C(14448), UINT16_C( 2040), UINT16_C( 5933) },
       INT8_C(   2),
      { UINT16_C(25696), UINT16_C(45584), UINT16_C(48344), UINT16_C(47920), UINT16_C(40112), UINT16_C(16752), UINT16_C(11512), UINT16_C(13816) } },
    { { UINT16_C(63841), UINT16_C(61791), UINT16_C(41377), UINT16_C(43109), UINT16_C(52575), UINT16_C( 3341), UINT16_C(61287), UINT16_C(48503) },
      { UINT16_C(24770), UINT16_C(40222), UINT16_C(30881), UINT16_C(  371) },
       INT8_C(   1),
      { UINT16_C(46686), UINT16_C(35874), UINT16_C(44510), UINT16_C(44246), UINT16_C(21538), UINT16_C(32902), UINT16_C(14610), UINT16_C(12018) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x8_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(INT16_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_uint16x8_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(UINT16_C(0))), lane, a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[2];
    int lane;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1755766840), UINT32_C(1721742792), UINT32_C( 366368309), UINT32_C(3851638648) },
      { UINT32_C(3317088559), UINT32_C(3000942253) },
       INT8_C(   0),
      { UINT32_C(2239586888), UINT32_C(1670260664), UINT32_C(2886060219), UINT32_C(3259926280) } },
    { { UINT32_C(4256160835), UINT32_C(4181021976), UINT32_C(2982256380), UINT32_C(2498111549) },
      { UINT32_C(1426914302), UINT32_C(1334112910) },
       INT8_C(   0),
      { UINT32_C(3012967290), UINT32_C(2188965328), UINT32_C(1422709256), UINT32_C(2309733254) } },
    { { UINT32_C( 677837897), UINT32_C(2322283438), UINT32_C(1067674090), UINT32_C(1010539678) },
      { UINT32_C(2239425629), UINT32_C(3447918290) },
       INT8_C(   0),
      { UINT32_C(3318149765), UINT32_C(4209317430), UINT32_C(3481612802), UINT32_C(2404748646) } },
    { { UINT32_C(1544313816), UINT32_C(2812720555), UINT32_C(1448529435), UINT32_C(2722160697) },
      { UINT32_C( 524386435), UINT32_C(2826796475) },
       INT8_C(   1),
      { UINT32_C(3730280136), UINT32_C(3388617449), UINT32_C(3476733113), UINT32_C( 380935843) } },
    { { UINT32_C(2248505858), UINT32_C(2740854856), UINT32_C(3780033324), UINT32_C( 805172833) },
      { UINT32_C( 745034572), UINT32_C( 347081620) },
       INT8_C(   0),
      { UINT32_C(2029969048), UINT32_C(2175331680), UINT32_C(  65983760), UINT32_C(1504614348) } },
    { { UINT32_C(1288294351), UINT32_C(4065313143), UINT32_C(3862615494), UINT32_C(3994279219) },
      { UINT32_C( 575665196), UINT32_C(1164869361) },
       INT8_C(   1),
      { UINT32_C(3023471583), UINT32_C(2456793863), UINT32_C(3954094950), UINT32_C(2994493187) } },
    { { UINT32_C(1257429402), UINT32_C(3155836653), UINT32_C(3358877191), UINT32_C(2324637365) },
      { UINT32_C(1035892064), UINT32_C(2104077448) },
       INT8_C(   0),
      { UINT32_C(1255209920), UINT32_C(3045059040), UINT32_C(1786344864), UINT32_C(1035287776) } },
    { { UINT32_C(4185550475), UINT32_C(2358534579), UINT32_C(2440683091), UINT32_C(1603876600) },
      { UINT32_C(2417254762), UINT32_C(1727045616) },
       INT8_C(   1),
      { UINT32_C(4055889744), UINT32_C(3717842128), UINT32_C(2468739792), UINT32_C( 558338176) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vmulq_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_uint32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vmulq_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), lane, a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    int lane;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -483.10), SIMDE_FLOAT32_C(   841.64), SIMDE_FLOAT32_C(   832.87), SIMDE_FLOAT32_C(   478.63) },
      { SIMDE_FLOAT32_C(   684.27), SIMDE_FLOAT32_C(  -437.87), SIMDE_FLOAT32_C(   138.75), SIMDE_FLOAT32_C(   -36.57) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-330570.84), SIMDE_FLOAT32_C(575909.00), SIMDE_FLOAT32_C(569907.94), SIMDE_FLOAT32_C(327512.16) } },
    { { SIMDE_FLOAT32_C(   141.10), SIMDE_FLOAT32_C(   936.51), SIMDE_FLOAT32_C(  -996.31), SIMDE_FLOAT32_C(   809.04) },
      { SIMDE_FLOAT32_C(  -520.77), SIMDE_FLOAT32_C(  -383.63), SIMDE_FLOAT32_C(   396.57), SIMDE_FLOAT32_C(  -505.39) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-73480.66), SIMDE_FLOAT32_C(-487706.34), SIMDE_FLOAT32_C(518848.38), SIMDE_FLOAT32_C(-421323.75) } },
    { { SIMDE_FLOAT32_C(   757.82), SIMDE_FLOAT32_C(  -769.31), SIMDE_FLOAT32_C(   479.87), SIMDE_FLOAT32_C(    27.24) },
      { SIMDE_FLOAT32_C(    87.58), SIMDE_FLOAT32_C(  -325.93), SIMDE_FLOAT32_C(  -147.19), SIMDE_FLOAT32_C(   630.99) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-246996.27), SIMDE_FLOAT32_C(250741.20), SIMDE_FLOAT32_C(-156404.03), SIMDE_FLOAT32_C( -8878.33) } },
    { { SIMDE_FLOAT32_C(   921.82), SIMDE_FLOAT32_C(    48.37), SIMDE_FLOAT32_C(  -130.34), SIMDE_FLOAT32_C(   806.30) },
      { SIMDE_FLOAT32_C(   565.26), SIMDE_FLOAT32_C(  -288.70), SIMDE_FLOAT32_C(   639.18), SIMDE_FLOAT32_C(    43.89) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C( 40458.68), SIMDE_FLOAT32_C(  2122.96), SIMDE_FLOAT32_C( -5720.62), SIMDE_FLOAT32_C( 35388.51) } },
    { { SIMDE_FLOAT32_C(  -798.70), SIMDE_FLOAT32_C(  -817.36), SIMDE_FLOAT32_C(   359.00), SIMDE_FLOAT32_C(   117.01) },
      { SIMDE_FLOAT32_C(   323.75), SIMDE_FLOAT32_C(   295.51), SIMDE_FLOAT32_C(   120.71), SIMDE_FLOAT32_C(   132.79) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(-106059.37), SIMDE_FLOAT32_C(-108537.23), SIMDE_FLOAT32_C( 47671.61), SIMDE_FLOAT32_C( 15537.76) } },
    { { SIMDE_FLOAT32_C(   737.08), SIMDE_FLOAT32_C(  -470.63), SIMDE_FLOAT32_C(  -730.64), SIMDE_FLOAT32_C(    79.42) },
      { SIMDE_FLOAT32_C(  -712.82), SIMDE_FLOAT32_C(  -499.95), SIMDE_FLOAT32_C(  -440.71), SIMDE_FLOAT32_C(   314.43) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-368503.16), SIMDE_FLOAT32_C(235291.48), SIMDE_FLOAT32_C(365283.47), SIMDE_FLOAT32_C(-39706.03) } },
    { { SIMDE_FLOAT32_C(   233.36), SIMDE_FLOAT32_C(  -832.76), SIMDE_FLOAT32_C(   218.62), SIMDE_FLOAT32_C(   442.88) },
      { SIMDE_FLOAT32_C(  -910.95), SIMDE_FLOAT32_C(  -733.02), SIMDE_FLOAT32_C(  -687.47), SIMDE_FLOAT32_C(   895.36) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-171057.55), SIMDE_FLOAT32_C(610429.75), SIMDE_FLOAT32_C(-160252.83), SIMDE_FLOAT32_C(-324639.91) } },
    { { SIMDE_FLOAT32_C(    23.84), SIMDE_FLOAT32_C(   534.54), SIMDE_FLOAT32_C(  -123.86), SIMDE_FLOAT32_C(   419.41) },
      { SIMDE_FLOAT32_C(   735.84), SIMDE_FLOAT32_C(    58.79), SIMDE_FLOAT32_C(  -221.60), SIMDE_FLOAT32_C(  -147.15) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  1401.55), SIMDE_FLOAT32_C( 31425.61), SIMDE_FLOAT32_C( -7281.73), SIMDE_FLOAT32_C( 24657.12) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);

    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 3;

    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    int lane;
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    -8.30), SIMDE_FLOAT64_C(    39.42) },
      { SIMDE_FLOAT64_C(  -145.93), SIMDE_FLOAT64_C(  -489.21) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  1211.22), SIMDE_FLOAT64_C( -5752.56) } },
    { { SIMDE_FLOAT64_C(  -947.61), SIMDE_FLOAT64_C(   662.96) },
      { SIMDE_FLOAT64_C(   341.51), SIMDE_FLOAT64_C(   581.12) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-550675.12), SIMDE_FLOAT64_C(385259.32) } },
    { { SIMDE_FLOAT64_C(   777.29), SIMDE_FLOAT64_C(   252.16) },
      { SIMDE_FLOAT64_C(   955.20), SIMDE_FLOAT64_C(  -332.93) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-258783.16), SIMDE_FLOAT64_C(-83951.63) } },
    { { SIMDE_FLOAT64_C(   446.81), SIMDE_FLOAT64_C(  -501.58) },
      { SIMDE_FLOAT64_C(  -807.53), SIMDE_FLOAT64_C(  -797.54) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-360812.48), SIMDE_FLOAT64_C(405040.90) } },
    { { SIMDE_FLOAT64_C(   357.00), SIMDE_FLOAT64_C(  -144.04) },
      { SIMDE_FLOAT64_C(   968.23), SIMDE_FLOAT64_C(  -970.92) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(345658.11), SIMDE_FLOAT64_C(-139463.85) } },
    { { SIMDE_FLOAT64_C(   974.60), SIMDE_FLOAT64_C(    51.96) },
      { SIMDE_FLOAT64_C(   988.71), SIMDE_FLOAT64_C(   292.59) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(963596.77), SIMDE_FLOAT64_C( 51373.37) } },
    { { SIMDE_FLOAT64_C(  -177.10), SIMDE_FLOAT64_C(  -715.71) },
      { SIMDE_FLOAT64_C(  -172.78), SIMDE_FLOAT64_C(   676.97) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-119891.39), SIMDE_FLOAT64_C(-484514.20) } },
    { { SIMDE_FLOAT64_C(  -585.24), SIMDE_FLOAT64_C(   729.36) },
      { SIMDE_FLOAT64_C(  -541.96), SIMDE_FLOAT64_C(   756.27) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-442599.45), SIMDE_FLOAT64_C(551593.09) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);

    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmulq_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f64(SIMDE_FLOAT64_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmulq_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f64(SIMDE_FLOAT64_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int lane;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 15106), -INT16_C( 11576),  INT16_C( 21525), -INT16_C( 22481),  INT16_C(  8396),  INT16_C(  4855),  INT16_C(  6473), -INT16_C( 18119) },
      { -INT16_C( 22892),  INT16_C( 18029), -INT16_C( 30073),  INT16_C(  4981),  INT16_C( 31143), -INT16_C( 17613),  INT16_C( 25903),  INT16_C( 11615) },
       INT8_C(   1),
      {  INT16_C( 21542),  INT16_C( 28456), -INT16_C( 29967),  INT16_C( 30211), -INT16_C( 16676), -INT16_C( 25301), -INT16_C( 17899),  INT16_C( 29509) } },
    { { -INT16_C(   217),  INT16_C( 31806), -INT16_C(  6354),  INT16_C( 20040),  INT16_C( 23262), -INT16_C(  2153),  INT16_C( 20627),  INT16_C( 14732) },
      { -INT16_C( 11586),  INT16_C( 18624), -INT16_C( 11449), -INT16_C( 15888), -INT16_C( 21754),  INT16_C( 27632),  INT16_C(  7434),  INT16_C( 12948) },
       INT8_C(   5),
      { -INT16_C( 32368),  INT16_C( 25632), -INT16_C(  2784),  INT16_C( 31616), -INT16_C(  1504),  INT16_C( 14992), -INT16_C(  1328),  INT16_C( 30528) } },
    { { -INT16_C( 20781), -INT16_C( 17845), -INT16_C( 25866),  INT16_C( 20632), -INT16_C( 28879), -INT16_C( 32029),  INT16_C(  7195), -INT16_C(  4800) },
      { -INT16_C( 30500), -INT16_C( 20683), -INT16_C(  2440),  INT16_C(  9398),  INT16_C(  8678),  INT16_C(   814),  INT16_C( 24758), -INT16_C( 30432) },
       INT8_C(   6),
      {  INT16_C( 27138), -INT16_C( 28334),  INT16_C( 27364),  INT16_C( 19472),  INT16_C( 11478),  INT16_C( 11618),  INT16_C(  6962), -INT16_C( 21632) } },
    { {  INT16_C( 17260),  INT16_C(  1540),  INT16_C( 21723),  INT16_C( 27191), -INT16_C( 18121),  INT16_C( 21382),  INT16_C( 29689), -INT16_C( 32209) },
      { -INT16_C(  8280), -INT16_C( 24838),  INT16_C(  7829), -INT16_C( 18812), -INT16_C( 30643), -INT16_C( 21140), -INT16_C(  2648),  INT16_C(  5308) },
       INT8_C(   0),
      {  INT16_C( 21216),  INT16_C( 28320),  INT16_C( 29880), -INT16_C( 25320),  INT16_C( 29976), -INT16_C( 30224),  INT16_C(   616),  INT16_C( 24536) } },
    { {  INT16_C(  6848),  INT16_C(  5395),  INT16_C( 32338),  INT16_C(  2892), -INT16_C( 24572),  INT16_C( 30469), -INT16_C( 30769), -INT16_C( 20960) },
      { -INT16_C( 16767), -INT16_C( 24509), -INT16_C(  1469), -INT16_C( 13331), -INT16_C( 26010),  INT16_C( 23667), -INT16_C( 30634),  INT16_C(  6036) },
       INT8_C(   2),
      { -INT16_C( 32704),  INT16_C(  4601),  INT16_C(  9078),  INT16_C( 11492), -INT16_C( 14068),  INT16_C(  2127), -INT16_C( 20179), -INT16_C( 11680) } },
    { {  INT16_C( 11432),  INT16_C(  9972),  INT16_C(   120),  INT16_C(  6186), -INT16_C( 24315), -INT16_C( 29464), -INT16_C( 26943), -INT16_C( 32755) },
      { -INT16_C( 21030), -INT16_C( 11069), -INT16_C( 29030),  INT16_C( 13626), -INT16_C( 27135), -INT16_C( 30325), -INT16_C( 24021), -INT16_C( 11476) },
       INT8_C(   6),
      { -INT16_C( 12232), -INT16_C(  3332),  INT16_C(  1064), -INT16_C( 23794),  INT16_C( 13783),  INT16_C( 31480),  INT16_C( 29803), -INT16_C( 17361) } },
    { { -INT16_C(  1760),  INT16_C(  8263),  INT16_C( 24355), -INT16_C( 15323), -INT16_C( 20153), -INT16_C(  8570),  INT16_C(  1727),  INT16_C( 27832) },
      { -INT16_C( 29495),  INT16_C( 22279),  INT16_C( 15558),  INT16_C( 23896), -INT16_C(  7481),  INT16_C( 27272),  INT16_C( 23310),  INT16_C( 11832) },
       INT8_C(   4),
      { -INT16_C(  6176), -INT16_C( 15055), -INT16_C(  9675),  INT16_C(  8899),  INT16_C( 31793),  INT16_C( 17962), -INT16_C(  9095), -INT16_C(  3320) } },
    { {  INT16_C( 20351), -INT16_C(  8329),  INT16_C( 15220),  INT16_C(  9766),  INT16_C(  1217), -INT16_C( 14363),  INT16_C( 20924),  INT16_C( 18576) },
      { -INT16_C(  6312), -INT16_C( 27633),  INT16_C( 27712),  INT16_C(  8796), -INT16_C( 14604),  INT16_C( 20272),  INT16_C( 24318),  INT16_C( 32419) },
       INT8_C(   5),
      {  INT16_C(  6352), -INT16_C( 24752), -INT16_C(  3648), -INT16_C(  7904),  INT16_C( 29488),  INT16_C(  9712),  INT16_C( 22336),  INT16_C(  2816) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vmulq_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(INT16_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_int16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vmulq_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(INT16_C(0))), lane, a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int lane;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1428315418), -INT32_C(  2011740029),  INT32_C(  2118442541),  INT32_C(  1456967023) },
      {  INT32_C(   144075676), -INT32_C(  1912817465),  INT32_C(  1200376808),  INT32_C(   150211310) },
       INT8_C(   3),
      {  INT32_C(   173904428), -INT32_C(  1554610230),  INT32_C(  1066946518),  INT32_C(  1840763698) } },
    { {  INT32_C(  1592417558),  INT32_C(  1401647732),  INT32_C(  1153567415),  INT32_C(  1289754849) },
      {  INT32_C(  1729423535),  INT32_C(   793813476),  INT32_C(   924686125), -INT32_C(  1566694005) },
       INT8_C(   2),
      {  INT32_C(   832067294), -INT32_C(   752252316),  INT32_C(   304665387), -INT32_C(   628222323) } },
    { { -INT32_C(    67698551), -INT32_C(  1766700404),  INT32_C(   611841548), -INT32_C(  1093418026) },
      {  INT32_C(  2040675287),  INT32_C(   581357963),  INT32_C(   330161902),  INT32_C(    93736828) },
       INT8_C(   0),
      { -INT32_C(  1589443057), -INT32_C(     8200300), -INT32_C(  1509136364),  INT32_C(   627559098) } },
    { { -INT32_C(   673447539), -INT32_C(  1427934541), -INT32_C(  1400895511),  INT32_C(   377765851) },
      { -INT32_C(  1281229343), -INT32_C(  2120105053), -INT32_C(  1057049232), -INT32_C(   670039221) },
       INT8_C(   0),
      { -INT32_C(  1231899155),  INT32_C(  1171633747),  INT32_C(   148977865), -INT32_C(   955085189) } },
    { {  INT32_C(  1589161964), -INT32_C(  1723374958),  INT32_C(   561312738),  INT32_C(  1946389111) },
      { -INT32_C(   300370389),  INT32_C(   207591767), -INT32_C(  1688789097),  INT32_C(   463417135) },
       INT8_C(   2),
      { -INT32_C(   378447820), -INT32_C(   207039970), -INT32_C(  1655556018), -INT32_C(   146008783) } },
    { { -INT32_C(  1183811241), -INT32_C(  1281619264),  INT32_C(   153861502),  INT32_C(  1983160256) },
      {  INT32_C(  1372464055), -INT32_C(  1578575230),  INT32_C(  1641055026),  INT32_C(  2051074851) },
       INT8_C(   0),
      {  INT32_C(   452960817),  INT32_C(   545517376), -INT32_C(   493834478), -INT32_C(    34246080) } },
    { { -INT32_C(  1172032336), -INT32_C(  1925589040), -INT32_C(  1571929598), -INT32_C(  1722170250) },
      {  INT32_C(  1830529682),  INT32_C(   379567251),  INT32_C(  2000224396), -INT32_C(   237259712) },
       INT8_C(   0),
      { -INT32_C(  1305285536),  INT32_C(  1195193504),  INT32_C(  1487730980),  INT32_C(   135948108) } },
    { { -INT32_C(   675763201),  INT32_C(   651773412),  INT32_C(  1486715795),  INT32_C(  2146055893) },
      {  INT32_C(   236083026), -INT32_C(   140826122),  INT32_C(   372707938), -INT32_C(   302110482) },
       INT8_C(   0),
      { -INT32_C(   444022610), -INT32_C(  1436492024), -INT32_C(  1580824042),  INT32_C(   312603450) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), lane, a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    int lane;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(50358), UINT16_C(64696), UINT16_C(57246), UINT16_C( 6543), UINT16_C(59260), UINT16_C(45806), UINT16_C(28370), UINT16_C(10500) },
      { UINT16_C( 4992), UINT16_C(43296), UINT16_C( 6062), UINT16_C(49164), UINT16_C( 8782), UINT16_C(30638), UINT16_C(39969), UINT16_C(55115) },
       INT8_C(   0),
      { UINT16_C(56576), UINT16_C( 1024), UINT16_C(35072), UINT16_C(25728), UINT16_C(61952), UINT16_C( 8448), UINT16_C(65280), UINT16_C(52736) } },
    { { UINT16_C(54019), UINT16_C(58110), UINT16_C( 6243), UINT16_C(19038), UINT16_C( 4358), UINT16_C(29724), UINT16_C(17941), UINT16_C(10485) },
      { UINT16_C(40550), UINT16_C(32214), UINT16_C(38826), UINT16_C(52683), UINT16_C(16965), UINT16_C(57838), UINT16_C(50573), UINT16_C(37186) },
       INT8_C(   1),
      { UINT16_C(56194), UINT16_C(50772), UINT16_C(47554), UINT16_C( 4244), UINT16_C(10500), UINT16_C(47976), UINT16_C(54926), UINT16_C(56782) } },
    { { UINT16_C(29504), UINT16_C(22780), UINT16_C(18130), UINT16_C(58207), UINT16_C(54115), UINT16_C(43512), UINT16_C( 8648), UINT16_C(26383) },
      { UINT16_C(36087), UINT16_C(36369), UINT16_C(56919), UINT16_C(39636), UINT16_C(46540), UINT16_C(37415), UINT16_C(47351), UINT16_C(14379) },
       INT8_C(   4),
      { UINT16_C( 5888), UINT16_C( 5328), UINT16_C(59736), UINT16_C(23220), UINT16_C(29156), UINT16_C(51616), UINT16_C(21344), UINT16_C(47860) } },
    { { UINT16_C(36903), UINT16_C(28158), UINT16_C(57839), UINT16_C(50128), UINT16_C(31193), UINT16_C(64139), UINT16_C(62088), UINT16_C( 5362) },
      { UINT16_C(32772), UINT16_C(57964), UINT16_C( 1620), UINT16_C( 2735), UINT16_C(16685), UINT16_C(58881), UINT16_C(14700), UINT16_C(37650) },
       INT8_C(   2),
      { UINT16_C(14028), UINT16_C( 2904), UINT16_C(48236), UINT16_C( 8256), UINT16_C( 4404), UINT16_C(30620), UINT16_C(50336), UINT16_C(35688) } },
    { { UINT16_C(   16), UINT16_C(61881), UINT16_C(31953), UINT16_C(19146), UINT16_C(50440), UINT16_C(64211), UINT16_C(59319), UINT16_C(14334) },
      { UINT16_C(57683), UINT16_C(22924), UINT16_C(38544), UINT16_C(53639), UINT16_C(28055), UINT16_C(53565), UINT16_C(53375), UINT16_C(36763) },
       INT8_C(   0),
      { UINT16_C( 5424), UINT16_C(63483), UINT16_C(10435), UINT16_C(51582), UINT16_C(59800), UINT16_C(50537), UINT16_C(63317), UINT16_C(25946) } },
    { { UINT16_C(32852), UINT16_C(53665), UINT16_C(60490), UINT16_C( 4057), UINT16_C(54207), UINT16_C(42694), UINT16_C(65234), UINT16_C(46074) },
      { UINT16_C(21386), UINT16_C( 8259), UINT16_C( 5338), UINT16_C(18359), UINT16_C(34897), UINT16_C( 8646), UINT16_C(21795), UINT16_C(30961) },
       INT8_C(   5),
      { UINT16_C( 5368), UINT16_C(58246), UINT16_C(19260), UINT16_C(15062), UINT16_C(25786), UINT16_C(33572), UINT16_C(10348), UINT16_C(27996) } },
    { { UINT16_C(18835), UINT16_C(32544), UINT16_C(12066), UINT16_C(62782), UINT16_C(58614), UINT16_C(62663), UINT16_C(31454), UINT16_C(12926) },
      { UINT16_C(40637), UINT16_C(53516), UINT16_C(21589), UINT16_C(56866), UINT16_C(17178), UINT16_C(28673), UINT16_C(31029), UINT16_C(51269) },
       INT8_C(   2),
      { UINT16_C(43471), UINT16_C(46496), UINT16_C(52810), UINT16_C(50582), UINT16_C(48558), UINT16_C(37395), UINT16_C(41910), UINT16_C( 7126) } },
    { { UINT16_C(18277), UINT16_C(38372), UINT16_C(55941), UINT16_C(27019), UINT16_C(32673), UINT16_C( 7240), UINT16_C(31485), UINT16_C(39897) },
      { UINT16_C(43910), UINT16_C(56048), UINT16_C(52941), UINT16_C( 4597), UINT16_C(26064), UINT16_C(18758), UINT16_C( 3754), UINT16_C( 4108) },
       INT8_C(   5),
      { UINT16_C(21150), UINT16_C(   88), UINT16_C(44382), UINT16_C(32514), UINT16_C(52998), UINT16_C(17328), UINT16_C(50734), UINT16_C(32342) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vmulq_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(INT16_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_uint16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vmulq_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(UINT16_C(0))), lane, a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    int lane;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 133424210), UINT32_C(3567681185), UINT32_C( 168554144), UINT32_C(2467885481) },
      { UINT32_C(3585083847), UINT32_C(2741717858), UINT32_C(2755662601), UINT32_C(1393839105) },
       INT8_C(   0),
      { UINT32_C(4093468094), UINT32_C( 730863655), UINT32_C(1755979360), UINT32_C(4195535711) } },
    { { UINT32_C(2261932808), UINT32_C(4012287489), UINT32_C(2744660401), UINT32_C(1382689609) },
      { UINT32_C( 666189788), UINT32_C(3190839467), UINT32_C(3854554265), UINT32_C(4027978728) },
       INT8_C(   2),
      { UINT32_C(3658680264), UINT32_C(2941323929), UINT32_C( 925583049), UINT32_C(3317912225) } },
    { { UINT32_C(2389669864), UINT32_C(3460325021), UINT32_C( 572056566), UINT32_C(2382260813) },
      { UINT32_C(2016945439), UINT32_C( 689043029), UINT32_C(3373397686), UINT32_C(4097245708) },
       INT8_C(   1),
      { UINT32_C(2258878472), UINT32_C(3283568673), UINT32_C(3332904110), UINT32_C(  62671249) } },
    { { UINT32_C(  68584358), UINT32_C(2801460675), UINT32_C(1743985917), UINT32_C(1065844762) },
      { UINT32_C(2945777592), UINT32_C( 107330832), UINT32_C(3507695311), UINT32_C( 189400933) },
       INT8_C(   2),
      { UINT32_C(2771273530), UINT32_C(1520554669), UINT32_C(1888544403), UINT32_C(1937981702) } },
    { { UINT32_C(1162678112), UINT32_C( 641921801), UINT32_C(1732291303), UINT32_C( 807436337) },
      { UINT32_C(3527462676), UINT32_C(1654736436), UINT32_C(1640460889), UINT32_C( 485216956) },
       INT8_C(   1),
      { UINT32_C(2436587392), UINT32_C(1589040084), UINT32_C(2435113196), UINT32_C( 175665140) } },
    { { UINT32_C( 753558073), UINT32_C(1309872292), UINT32_C(3514792785), UINT32_C(1793437595) },
      { UINT32_C( 916371439), UINT32_C(3398369368), UINT32_C(2575757511), UINT32_C( 360358876) },
       INT8_C(   1),
      { UINT32_C(1214825368), UINT32_C(2317989984), UINT32_C(3490800600), UINT32_C( 612982088) } },
    { { UINT32_C(1974026596), UINT32_C(3502700629), UINT32_C( 661362551), UINT32_C( 873911676) },
      { UINT32_C(1938574451), UINT32_C(3426375644), UINT32_C(2158547933), UINT32_C(2978331981) },
       INT8_C(   3),
      { UINT32_C(1982037780), UINT32_C(2052616849), UINT32_C(1107454411), UINT32_C( 736543308) } },
    { { UINT32_C( 659826223), UINT32_C(2208179436), UINT32_C(1677772175), UINT32_C( 685192412) },
      { UINT32_C( 386157248), UINT32_C(1475727748), UINT32_C( 933524857), UINT32_C( 708204027) },
       INT8_C(   0),
      { UINT32_C(2749512000), UINT32_C( 888662272), UINT32_C( 686522688), UINT32_C(1847540992) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulq_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), lane, a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmuld_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b[1];
    simde_float64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   701.55),
      { SIMDE_FLOAT64_C(   763.69) },
      SIMDE_FLOAT64_C(535766.72) },
    { SIMDE_FLOAT64_C(  -207.75),
      { SIMDE_FLOAT64_C(  -252.26) },
      SIMDE_FLOAT64_C( 52407.01) },
    { SIMDE_FLOAT64_C(   258.78),
      { SIMDE_FLOAT64_C(   426.42) },
      SIMDE_FLOAT64_C(110348.97) },
    { SIMDE_FLOAT64_C(  -228.36),
      { SIMDE_FLOAT64_C(   601.45) },
      SIMDE_FLOAT64_C(-137347.12) },
    { SIMDE_FLOAT64_C(   257.18),
      { SIMDE_FLOAT64_C(   100.91) },
      SIMDE_FLOAT64_C( 25952.03) },
    { SIMDE_FLOAT64_C(  -786.84),
      { SIMDE_FLOAT64_C(  -162.95) },
      SIMDE_FLOAT64_C(128215.58) },
    { SIMDE_FLOAT64_C(  -602.83),
      { SIMDE_FLOAT64_C(   531.21) },
      SIMDE_FLOAT64_C(-320229.32) },
    { SIMDE_FLOAT64_C(   286.53),
      { SIMDE_FLOAT64_C(   607.95) },
      SIMDE_FLOAT64_C(174195.91) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r = simde_vmuld_lane_f64(test_vec[i].a, simde_vld1_f64(test_vec[i].b), 0);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000, 1000);
    simde_float64_t r = simde_vmuld_lane_f64(a, b, 0);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmuld_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b[2];
    int lane;
    simde_float64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -966.64),
      { SIMDE_FLOAT64_C(   703.89), SIMDE_FLOAT64_C(  -629.15) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(-680408.23) },
    { SIMDE_FLOAT64_C(  -363.33),
      { SIMDE_FLOAT64_C(  -559.71), SIMDE_FLOAT64_C(  -456.98) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(166034.54) },
    { SIMDE_FLOAT64_C(  -605.56),
      { SIMDE_FLOAT64_C(  -750.10), SIMDE_FLOAT64_C(     3.29) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(454230.56) },
    { SIMDE_FLOAT64_C(  -653.37),
      { SIMDE_FLOAT64_C(  -480.38), SIMDE_FLOAT64_C(   279.75) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(-182780.26) },
    { SIMDE_FLOAT64_C(  -832.94),
      { SIMDE_FLOAT64_C(   271.64), SIMDE_FLOAT64_C(  -658.01) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(-226259.82) },
    { SIMDE_FLOAT64_C(  -530.95),
      { SIMDE_FLOAT64_C(   366.84), SIMDE_FLOAT64_C(   230.32) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(-122288.40) },
    { SIMDE_FLOAT64_C(   710.66),
      { SIMDE_FLOAT64_C(   453.17), SIMDE_FLOAT64_C(   153.31) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(322049.79) },
    { SIMDE_FLOAT64_C(   325.93),
      { SIMDE_FLOAT64_C(   880.39), SIMDE_FLOAT64_C(   -35.41) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(-11541.18) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r;
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    SIMDE_CONSTIFY_2_(simde_vmuld_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, b);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000, 1000);
    simde_float64_t r;
    SIMDE_CONSTIFY_2_(simde_vmuld_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmuls_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b[2];
    int lane;
    simde_float32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   114.36),
      { SIMDE_FLOAT32_C(   411.22), SIMDE_FLOAT32_C(   916.69) },
       INT8_C(   0),
      SIMDE_FLOAT32_C( 47027.12) },
    { SIMDE_FLOAT32_C(   700.21),
      { SIMDE_FLOAT32_C(  -898.84), SIMDE_FLOAT32_C(  -718.55) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-503135.91) },
    { SIMDE_FLOAT32_C(  -369.32),
      { SIMDE_FLOAT32_C(  -865.48), SIMDE_FLOAT32_C(   985.34) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(319639.06) },
    { SIMDE_FLOAT32_C(     1.52),
      { SIMDE_FLOAT32_C(  -228.81), SIMDE_FLOAT32_C(  -574.37) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(  -873.04) },
    { SIMDE_FLOAT32_C(   544.55),
      { SIMDE_FLOAT32_C(   165.63), SIMDE_FLOAT32_C(  -324.47) },
       INT8_C(   0),
      SIMDE_FLOAT32_C( 90193.82) },
    { SIMDE_FLOAT32_C(  -452.16),
      { SIMDE_FLOAT32_C(   512.26), SIMDE_FLOAT32_C(   195.14) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-88234.50) },
    { SIMDE_FLOAT32_C(   827.58),
      { SIMDE_FLOAT32_C(   679.32), SIMDE_FLOAT32_C(  -533.22) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(562191.69) },
    { SIMDE_FLOAT32_C(  -830.42),
      { SIMDE_FLOAT32_C(  -851.63), SIMDE_FLOAT32_C(   833.63) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-692263.00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32_t r;
    SIMDE_CONSTIFY_2_(simde_vmuls_lane_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, b);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1};
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000, 1000);
    simde_float32_t r;
    SIMDE_CONSTIFY_2_(simde_vmuls_lane_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmuls_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b[4];
    int lane;
    simde_float32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   399.90),
      { SIMDE_FLOAT32_C(   859.03), SIMDE_FLOAT32_C(   286.79), SIMDE_FLOAT32_C(  -446.80), SIMDE_FLOAT32_C(   184.96) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(343526.09) },
    { SIMDE_FLOAT32_C(   167.18),
      { SIMDE_FLOAT32_C(   517.79), SIMDE_FLOAT32_C(  -700.69), SIMDE_FLOAT32_C(  -421.60), SIMDE_FLOAT32_C(   434.49) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-117141.35) },
    { SIMDE_FLOAT32_C(   999.53),
      { SIMDE_FLOAT32_C(  -320.44), SIMDE_FLOAT32_C(   715.94), SIMDE_FLOAT32_C(  -369.79), SIMDE_FLOAT32_C(  -185.93) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(-320289.41) },
    { SIMDE_FLOAT32_C(   701.28),
      { SIMDE_FLOAT32_C(   631.73), SIMDE_FLOAT32_C(   585.26), SIMDE_FLOAT32_C(  -873.09), SIMDE_FLOAT32_C(   176.28) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(410431.16) },
    { SIMDE_FLOAT32_C(  -249.11),
      { SIMDE_FLOAT32_C(  -197.56), SIMDE_FLOAT32_C(   724.11), SIMDE_FLOAT32_C(  -736.85), SIMDE_FLOAT32_C(   997.59) },
       INT8_C(   0),
      SIMDE_FLOAT32_C( 49214.17) },
    { SIMDE_FLOAT32_C(   551.70),
      { SIMDE_FLOAT32_C(   942.47), SIMDE_FLOAT32_C(  -535.63), SIMDE_FLOAT32_C(   721.27), SIMDE_FLOAT32_C(  -909.16) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-295507.09) },
    { SIMDE_FLOAT32_C(  -702.00),
      { SIMDE_FLOAT32_C(   121.17), SIMDE_FLOAT32_C(   949.86), SIMDE_FLOAT32_C(   584.79), SIMDE_FLOAT32_C(   674.37) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(-85061.34) },
    { SIMDE_FLOAT32_C(   134.82),
      { SIMDE_FLOAT32_C(  -248.03), SIMDE_FLOAT32_C(   192.17), SIMDE_FLOAT32_C(   434.13), SIMDE_FLOAT32_C(   330.37) },
       INT8_C(   1),
      SIMDE_FLOAT32_C( 25908.36) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32_t r;
    SIMDE_CONSTIFY_4_(simde_vmuls_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, b);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1};
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000, 1000);
    simde_float32_t r;
    SIMDE_CONSTIFY_4_(simde_vmuls_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]) , SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[4];
    int lane;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -450.23), SIMDE_FLOAT32_C(   250.17) },
      { SIMDE_FLOAT32_C(  -637.45), SIMDE_FLOAT32_C(  -230.90), SIMDE_FLOAT32_C(   241.82), SIMDE_FLOAT32_C(   684.35) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-108874.62), SIMDE_FLOAT32_C( 60496.11) } },
    { { SIMDE_FLOAT32_C(  -527.99), SIMDE_FLOAT32_C(   169.94) },
      { SIMDE_FLOAT32_C(  -242.42), SIMDE_FLOAT32_C(   315.71), SIMDE_FLOAT32_C(   591.47), SIMDE_FLOAT32_C(   461.07) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-312290.22), SIMDE_FLOAT32_C(100514.41) } },
    { { SIMDE_FLOAT32_C(   282.28), SIMDE_FLOAT32_C(  -679.21) },
      { SIMDE_FLOAT32_C(    -7.25), SIMDE_FLOAT32_C(   965.48), SIMDE_FLOAT32_C(  -996.40), SIMDE_FLOAT32_C(   494.36) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-281263.81), SIMDE_FLOAT32_C(676764.88) } },
    { { SIMDE_FLOAT32_C(  -776.91), SIMDE_FLOAT32_C(   857.04) },
      { SIMDE_FLOAT32_C(   724.13), SIMDE_FLOAT32_C(  -786.43), SIMDE_FLOAT32_C(  -311.62), SIMDE_FLOAT32_C(  -105.35) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(610985.31), SIMDE_FLOAT32_C(-674001.94) } },
    { { SIMDE_FLOAT32_C(   551.51), SIMDE_FLOAT32_C(   956.48) },
      { SIMDE_FLOAT32_C(    44.53), SIMDE_FLOAT32_C(  -898.71), SIMDE_FLOAT32_C(   206.65), SIMDE_FLOAT32_C(   407.07) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-495647.56), SIMDE_FLOAT32_C(-859598.12) } },
    { { SIMDE_FLOAT32_C(  -551.53), SIMDE_FLOAT32_C(    91.43) },
      { SIMDE_FLOAT32_C(  -422.60), SIMDE_FLOAT32_C(   -79.51), SIMDE_FLOAT32_C(  -738.63), SIMDE_FLOAT32_C(   334.98) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( 43852.15), SIMDE_FLOAT32_C( -7269.60) } },
    { { SIMDE_FLOAT32_C(   852.83), SIMDE_FLOAT32_C(  -203.95) },
      { SIMDE_FLOAT32_C(   817.55), SIMDE_FLOAT32_C(   135.11), SIMDE_FLOAT32_C(   116.84), SIMDE_FLOAT32_C(  -189.70) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(115225.87), SIMDE_FLOAT32_C(-27555.68) } },
    { { SIMDE_FLOAT32_C(   120.44), SIMDE_FLOAT32_C(  -695.35) },
      { SIMDE_FLOAT32_C(   723.25), SIMDE_FLOAT32_C(   343.53), SIMDE_FLOAT32_C(  -838.30), SIMDE_FLOAT32_C(   447.37) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-100964.85), SIMDE_FLOAT32_C(582911.88) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);

    simde_float32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 3;

    simde_float32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmul_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[2];
    int lane;
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -149.93) },
      { SIMDE_FLOAT64_C(  -657.97), SIMDE_FLOAT64_C(  -689.39) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(103360.24) } },
    { { SIMDE_FLOAT64_C(  -701.49) },
      { SIMDE_FLOAT64_C(   355.13), SIMDE_FLOAT64_C(  -497.12) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-249120.14) } },
    { { SIMDE_FLOAT64_C(  -237.80) },
      { SIMDE_FLOAT64_C(   373.27), SIMDE_FLOAT64_C(   953.64) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-226775.59) } },
    { { SIMDE_FLOAT64_C(   950.67) },
      { SIMDE_FLOAT64_C(  -125.88), SIMDE_FLOAT64_C(  -885.00) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-119670.34) } },
    { { SIMDE_FLOAT64_C(   110.32) },
      { SIMDE_FLOAT64_C(   967.83), SIMDE_FLOAT64_C(  -918.30) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(106771.01) } },
    { { SIMDE_FLOAT64_C(   102.94) },
      { SIMDE_FLOAT64_C(   198.54), SIMDE_FLOAT64_C(   738.16) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C( 20437.71) } },
    { { SIMDE_FLOAT64_C(  -681.01) },
      { SIMDE_FLOAT64_C(  -957.18), SIMDE_FLOAT64_C(   926.77) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(651849.15) } },
    { { SIMDE_FLOAT64_C(  -795.48) },
      { SIMDE_FLOAT64_C(   374.15), SIMDE_FLOAT64_C(   219.63) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-297628.84) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);

    simde_float64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vmul_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f64(SIMDE_FLOAT64_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vmul_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f64(SIMDE_FLOAT64_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmul_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_laneq_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_laneq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_laneq_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmuld_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmuld_laneq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmuls_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmuls_laneq_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmul_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_laneq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
