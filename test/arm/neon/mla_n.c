#define SIMDE_TEST_ARM_NEON_INSN mla_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mla_n.h"

static int
test_simde_vmla_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 c;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -680.78), SIMDE_FLOAT32_C(  -597.80) },
      { SIMDE_FLOAT32_C(   774.13), SIMDE_FLOAT32_C(  -444.02) },
      SIMDE_FLOAT32_C(  -818.28),
      { SIMDE_FLOAT32_C(-634135.88), SIMDE_FLOAT32_C(362734.88) } },
    { { SIMDE_FLOAT32_C(  -946.16), SIMDE_FLOAT32_C(   309.30) },
      { SIMDE_FLOAT32_C(  -303.37), SIMDE_FLOAT32_C(  -304.24) },
      SIMDE_FLOAT32_C(  -769.24),
      { SIMDE_FLOAT32_C(232418.17), SIMDE_FLOAT32_C(234342.86) } },
    { { SIMDE_FLOAT32_C(  -293.93), SIMDE_FLOAT32_C(   460.64) },
      { SIMDE_FLOAT32_C(  -114.31), SIMDE_FLOAT32_C(   164.95) },
      SIMDE_FLOAT32_C(   732.21),
      { SIMDE_FLOAT32_C(-83992.86), SIMDE_FLOAT32_C(121238.68) } },
    { { SIMDE_FLOAT32_C(  -513.27), SIMDE_FLOAT32_C(  -298.77) },
      { SIMDE_FLOAT32_C(    31.87), SIMDE_FLOAT32_C(   -63.24) },
      SIMDE_FLOAT32_C(   777.71),
      { SIMDE_FLOAT32_C( 24272.35), SIMDE_FLOAT32_C(-49481.15) } },
    { { SIMDE_FLOAT32_C(   -30.10), SIMDE_FLOAT32_C(  -408.99) },
      { SIMDE_FLOAT32_C(  -446.43), SIMDE_FLOAT32_C(   878.35) },
      SIMDE_FLOAT32_C(   581.74),
      { SIMDE_FLOAT32_C(-259736.27), SIMDE_FLOAT32_C(510562.31) } },
    { { SIMDE_FLOAT32_C(   861.55), SIMDE_FLOAT32_C(  -880.45) },
      { SIMDE_FLOAT32_C(  -856.08), SIMDE_FLOAT32_C(  -537.88) },
      SIMDE_FLOAT32_C(   393.17),
      { SIMDE_FLOAT32_C(-335723.44), SIMDE_FLOAT32_C(-212358.73) } },
    { { SIMDE_FLOAT32_C(   174.89), SIMDE_FLOAT32_C(  -218.67) },
      { SIMDE_FLOAT32_C(   795.36), SIMDE_FLOAT32_C(   -50.98) },
      SIMDE_FLOAT32_C(   337.31),
      { SIMDE_FLOAT32_C(268457.75), SIMDE_FLOAT32_C(-17414.73) } },
    { { SIMDE_FLOAT32_C(   977.08), SIMDE_FLOAT32_C(     2.85) },
      { SIMDE_FLOAT32_C(  -353.39), SIMDE_FLOAT32_C(  -326.28) },
      SIMDE_FLOAT32_C(   698.61),
      { SIMDE_FLOAT32_C(-245904.72), SIMDE_FLOAT32_C(-227939.62) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32 c = test_vec[i].c;
    simde_float32x2_t r = simde_vmla_n_f32(a, b, c);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32 c = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vmla_n_f32(a, b, c);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmla_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t c;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 13008), -INT16_C(  2885),  INT16_C( 19861), -INT16_C( 19732) },
      {  INT16_C( 11119), -INT16_C( 14555),  INT16_C( 25759), -INT16_C(  6163) },
       INT16_C( 28428),
      { -INT16_C(  2204),  INT16_C( 21879), -INT16_C(  2551),  INT16_C( 21768) } },
    { {  INT16_C(  7463),  INT16_C( 31302), -INT16_C( 21059), -INT16_C( 30252) },
      {  INT16_C(  4259), -INT16_C( 12863), -INT16_C(  3762),  INT16_C(  2458) },
       INT16_C( 12262),
      { -INT16_C(   871), -INT16_C( 15188), -INT16_C( 13359),  INT16_C( 28720) } },
    { { -INT16_C( 11689), -INT16_C( 14623),  INT16_C(  1789), -INT16_C( 25459) },
      {  INT16_C( 31594),  INT16_C( 30595), -INT16_C( 21782),  INT16_C( 12436) },
       INT16_C( 20772),
      { -INT16_C( 18625),  INT16_C(  2125),  INT16_C(  6629),  INT16_C( 17757) } },
    { { -INT16_C(  1826), -INT16_C( 32294), -INT16_C( 25591),  INT16_C( 22350) },
      { -INT16_C(  6003),  INT16_C( 29536), -INT16_C( 18665), -INT16_C(  1979) },
       INT16_C( 17277),
      {  INT16_C( 27831), -INT16_C(  2118),  INT16_C(  1860), -INT16_C( 24577) } },
    { {  INT16_C(  3070),  INT16_C( 27103),  INT16_C( 25478),  INT16_C( 28896) },
      {  INT16_C( 29709),  INT16_C( 12960),  INT16_C( 32454), -INT16_C( 24534) },
       INT16_C( 13311),
      {  INT16_C( 15345), -INT16_C( 18625),  INT16_C(  7360),  INT16_C( 22710) } },
    { {  INT16_C( 19772), -INT16_C( 13686), -INT16_C(  5323),  INT16_C( 19517) },
      { -INT16_C( 31838),  INT16_C(  8260),  INT16_C( 17350), -INT16_C( 23253) },
      -INT16_C( 20052),
      { -INT16_C( 16364),  INT16_C( 31802),  INT16_C( 23101),  INT16_C(    33) } },
    { { -INT16_C( 29688),  INT16_C(  5665), -INT16_C( 16128), -INT16_C( 14776) },
      {  INT16_C( 29248),  INT16_C( 16231), -INT16_C( 23642),  INT16_C( 12429) },
      -INT16_C( 15763),
      { -INT16_C( 20152),  INT16_C(  8956),  INT16_C( 15022),  INT16_C( 19537) } },
    { { -INT16_C( 21733), -INT16_C( 16881),  INT16_C( 21294), -INT16_C(  2850) },
      {  INT16_C(  2454),  INT16_C( 17049), -INT16_C( 23878), -INT16_C(  9266) },
      -INT16_C( 12360),
      { -INT16_C( 10005),  INT16_C( 21255), -INT16_C( 20770), -INT16_C( 32018) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int16x4_t r = simde_vmla_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    int16_t c = simde_test_codegen_random_i16();
    simde_int16x4_t r = simde_vmla_n_s16(a, b, c);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmla_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t c;
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   888615576), -INT32_C(  1946370236) },
      {  INT32_C(   491560011), -INT32_C(  1001757691) },
       INT32_C(   554369550),
      { -INT32_C(   895920974), -INT32_C(   837992054) } },
    { {  INT32_C(  1129433576),  INT32_C(   377974658) },
      {  INT32_C(   352551805), -INT32_C(    95749450) },
       INT32_C(    75843257),
      { -INT32_C(  1396638403), -INT32_C(  1882038008) } },
    { { -INT32_C(   400436766),  INT32_C(  1152150326) },
      {  INT32_C(  1449572206),  INT32_C(    43628416) },
      -INT32_C(  1558699994),
      { -INT32_C(   828453834), -INT32_C(  1838307274) } },
    { {  INT32_C(  1522080676), -INT32_C(   833354987) },
      {  INT32_C(   752015689), -INT32_C(   518720597) },
      -INT32_C(   853163937),
      { -INT32_C(    59015749),  INT32_C(   848408458) } },
    { { -INT32_C(   131888264),  INT32_C(  1778105410) },
      { -INT32_C(  2129914915),  INT32_C(  1155253551) },
       INT32_C(   303247304),
      {  INT32_C(    77570848),  INT32_C(  2136893946) } },
    { { -INT32_C(  1287723768),  INT32_C(   949244633) },
      { -INT32_C(  1979336174), -INT32_C(  2004670395) },
      -INT32_C(  1041137948),
      {  INT32_C(   786397456),  INT32_C(  1227564621) } },
    { { -INT32_C(  1069351535), -INT32_C(  1962598973) },
      {  INT32_C(  1436358732), -INT32_C(   704062467) },
       INT32_C(  1074699565),
      {  INT32_C(  2028920557), -INT32_C(   514592196) } },
    { { -INT32_C(  1664478377),  INT32_C(   539249979) },
      {  INT32_C(  1575032267), -INT32_C(   702733293) },
      -INT32_C(  1906236863),
      {  INT32_C(   868258274), -INT32_C(  1853359090) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int32x2_t r = simde_vmla_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    int32_t c = simde_test_codegen_random_i32();
    simde_int32x2_t r = simde_vmla_n_s32(a, b, c);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmla_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t c;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C( 2400), UINT16_C(15509), UINT16_C( 4372), UINT16_C(40051) },
      { UINT16_C(61882), UINT16_C(59067), UINT16_C(47693), UINT16_C(62182) },
      UINT16_C(35322),
      { UINT16_C(41732), UINT16_C(41523), UINT16_C(13638), UINT16_C(59151) } },
    { { UINT16_C(16620), UINT16_C(40433), UINT16_C(62418), UINT16_C( 5903) },
      { UINT16_C(46428), UINT16_C( 4731), UINT16_C(56078), UINT16_C(42011) },
      UINT16_C(12055),
      { UINT16_C(28720), UINT16_C(56318), UINT16_C(13332), UINT16_C(51836) } },
    { { UINT16_C(35509), UINT16_C(28875), UINT16_C(34684), UINT16_C(51542) },
      { UINT16_C(15681), UINT16_C(15292), UINT16_C(43206), UINT16_C(46971) },
      UINT16_C(19781),
      { UINT16_C(39482), UINT16_C( 5751), UINT16_C(37594), UINT16_C(15485) } },
    { { UINT16_C(21675), UINT16_C( 1892), UINT16_C(57098), UINT16_C( 6169) },
      { UINT16_C(13499), UINT16_C(53948), UINT16_C(29284), UINT16_C(12125) },
      UINT16_C(55778),
      { UINT16_C(25793), UINT16_C(27996), UINT16_C(40786), UINT16_C(48435) } },
    { { UINT16_C(14518), UINT16_C(63394), UINT16_C(24181), UINT16_C(15411) },
      { UINT16_C(44550), UINT16_C(19699), UINT16_C(40700), UINT16_C(24736) },
      UINT16_C(43685),
      { UINT16_C(24212), UINT16_C(60993), UINT16_C(12001), UINT16_C(50003) } },
    { { UINT16_C(48704), UINT16_C(64451), UINT16_C(32755), UINT16_C(22477) },
      { UINT16_C(10993), UINT16_C(54150), UINT16_C(15619), UINT16_C(42508) },
      UINT16_C(33076),
      { UINT16_C(59444), UINT16_C(30971), UINT16_C(26511), UINT16_C( 7741) } },
    { { UINT16_C(26372), UINT16_C( 3005), UINT16_C(45334), UINT16_C( 4695) },
      { UINT16_C(63311), UINT16_C(62834), UINT16_C(45730), UINT16_C(26035) },
      UINT16_C(42669),
      { UINT16_C(49511), UINT16_C(54727), UINT16_C(29840), UINT16_C(56910) } },
    { { UINT16_C(31716), UINT16_C(55037), UINT16_C(33957), UINT16_C(43433) },
      { UINT16_C(46529), UINT16_C(62799), UINT16_C(21303), UINT16_C(62557) },
      UINT16_C(29534),
      { UINT16_C(60354), UINT16_C(26367), UINT16_C(51159), UINT16_C(10959) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    uint16_t c = test_vec[i].c;
    simde_uint16x4_t r = simde_vmla_n_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    uint16_t c = simde_test_codegen_random_u16();
    simde_uint16x4_t r = simde_vmla_n_u16(a, b, c);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmla_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t c;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2305842287), UINT32_C(1514417662) },
      { UINT32_C(3213067177), UINT32_C(3633736064) },
      UINT32_C( 679518645),
      { UINT32_C(3820600300), UINT32_C(3572909438) } },
    { { UINT32_C(2905213946), UINT32_C(4090384713) },
      { UINT32_C(1057534927), UINT32_C( 248018959) },
      UINT32_C(1332219045),
      { UINT32_C(2739643493), UINT32_C(1203529460) } },
    { { UINT32_C( 269413519), UINT32_C( 183018581) },
      { UINT32_C(1060333637), UINT32_C(3169607027) },
      UINT32_C(2125446062),
      { UINT32_C(3478467189), UINT32_C(2540710271) } },
    { { UINT32_C(2109585262), UINT32_C(3582690608) },
      { UINT32_C( 556070033), UINT32_C( 892416736) },
      UINT32_C( 473962967),
      { UINT32_C(4025042485), UINT32_C(2278891344) } },
    { { UINT32_C(4099699585), UINT32_C(2125482192) },
      { UINT32_C(1912364803), UINT32_C(1206892823) },
      UINT32_C(3491527230),
      { UINT32_C(2836849723), UINT32_C( 393744994) } },
    { { UINT32_C(1324433774), UINT32_C(1250173555) },
      { UINT32_C(3160917051), UINT32_C( 129024823) },
      UINT32_C( 260399115),
      { UINT32_C(3097743351), UINT32_C(2363762128) } },
    { { UINT32_C(3598746303), UINT32_C(2048749371) },
      { UINT32_C(1481259754), UINT32_C(4003937147) },
      UINT32_C(2553883485),
      { UINT32_C(1870084033), UINT32_C(2319365098) } },
    { { UINT32_C( 643080431), UINT32_C(1848444003) },
      { UINT32_C( 595440228), UINT32_C(1895497268) },
      UINT32_C(1474959213),
      { UINT32_C(2571669891), UINT32_C( 493481095) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    uint32_t c = test_vec[i].c;
    simde_uint32x2_t r = simde_vmla_n_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    uint32_t c = simde_test_codegen_random_u32();
    simde_uint32x2_t r = simde_vmla_n_u32(a, b, c);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 c;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -565.27), SIMDE_FLOAT32_C(  -578.48), SIMDE_FLOAT32_C(   923.27), SIMDE_FLOAT32_C(  -735.63) },
      { SIMDE_FLOAT32_C(  -721.39), SIMDE_FLOAT32_C(   999.71), SIMDE_FLOAT32_C(  -670.81), SIMDE_FLOAT32_C(  -721.24) },
      SIMDE_FLOAT32_C(   987.68),
      { SIMDE_FLOAT32_C(-713067.75), SIMDE_FLOAT32_C(986815.06), SIMDE_FLOAT32_C(-661622.38), SIMDE_FLOAT32_C(-713089.94) } },
    { { SIMDE_FLOAT32_C(  -575.56), SIMDE_FLOAT32_C(   755.06), SIMDE_FLOAT32_C(  -177.83), SIMDE_FLOAT32_C(  -498.94) },
      { SIMDE_FLOAT32_C(  -117.24), SIMDE_FLOAT32_C(   -43.95), SIMDE_FLOAT32_C(   115.50), SIMDE_FLOAT32_C(   776.41) },
      SIMDE_FLOAT32_C(  -808.82),
      { SIMDE_FLOAT32_C( 94250.49), SIMDE_FLOAT32_C( 36302.70), SIMDE_FLOAT32_C(-93596.54), SIMDE_FLOAT32_C(-628474.88) } },
    { { SIMDE_FLOAT32_C(   -35.98), SIMDE_FLOAT32_C(   -41.82), SIMDE_FLOAT32_C(   249.53), SIMDE_FLOAT32_C(  -482.80) },
      { SIMDE_FLOAT32_C(   691.32), SIMDE_FLOAT32_C(   488.86), SIMDE_FLOAT32_C(   795.66), SIMDE_FLOAT32_C(   785.88) },
      SIMDE_FLOAT32_C(    36.60),
      { SIMDE_FLOAT32_C( 25266.33), SIMDE_FLOAT32_C( 17850.46), SIMDE_FLOAT32_C( 29370.68), SIMDE_FLOAT32_C( 28280.41) } },
    { { SIMDE_FLOAT32_C(   325.74), SIMDE_FLOAT32_C(  -867.74), SIMDE_FLOAT32_C(  -719.43), SIMDE_FLOAT32_C(   295.15) },
      { SIMDE_FLOAT32_C(  -433.01), SIMDE_FLOAT32_C(  -297.91), SIMDE_FLOAT32_C(   218.42), SIMDE_FLOAT32_C(  -168.64) },
      SIMDE_FLOAT32_C(   -19.30),
      { SIMDE_FLOAT32_C(  8682.83), SIMDE_FLOAT32_C(  4881.92), SIMDE_FLOAT32_C( -4934.94), SIMDE_FLOAT32_C(  3549.90) } },
    { { SIMDE_FLOAT32_C(   218.13), SIMDE_FLOAT32_C(   160.55), SIMDE_FLOAT32_C(   259.47), SIMDE_FLOAT32_C(   205.82) },
      { SIMDE_FLOAT32_C(   585.00), SIMDE_FLOAT32_C(    14.53), SIMDE_FLOAT32_C(  -972.01), SIMDE_FLOAT32_C(  -913.95) },
      SIMDE_FLOAT32_C(   897.29),
      { SIMDE_FLOAT32_C(525132.75), SIMDE_FLOAT32_C( 13198.17), SIMDE_FLOAT32_C(-871915.31), SIMDE_FLOAT32_C(-819872.38) } },
    { { SIMDE_FLOAT32_C(   -15.96), SIMDE_FLOAT32_C(   201.56), SIMDE_FLOAT32_C(   673.70), SIMDE_FLOAT32_C(   175.22) },
      { SIMDE_FLOAT32_C(  -834.43), SIMDE_FLOAT32_C(  -368.13), SIMDE_FLOAT32_C(  -575.24), SIMDE_FLOAT32_C(  -317.23) },
      SIMDE_FLOAT32_C(  -676.81),
      { SIMDE_FLOAT32_C(564734.62), SIMDE_FLOAT32_C(249355.62), SIMDE_FLOAT32_C(390001.88), SIMDE_FLOAT32_C(214879.66) } },
    { { SIMDE_FLOAT32_C(   913.62), SIMDE_FLOAT32_C(  -521.58), SIMDE_FLOAT32_C(  -890.93), SIMDE_FLOAT32_C(   -49.78) },
      { SIMDE_FLOAT32_C(   804.17), SIMDE_FLOAT32_C(  -758.67), SIMDE_FLOAT32_C(   230.79), SIMDE_FLOAT32_C(    99.32) },
      SIMDE_FLOAT32_C(  -191.67),
      { SIMDE_FLOAT32_C(-153221.64), SIMDE_FLOAT32_C(144892.70), SIMDE_FLOAT32_C(-45126.45), SIMDE_FLOAT32_C(-19086.44) } },
    { { SIMDE_FLOAT32_C(   932.88), SIMDE_FLOAT32_C(  -682.26), SIMDE_FLOAT32_C(   639.69), SIMDE_FLOAT32_C(   -86.42) },
      { SIMDE_FLOAT32_C(   535.88), SIMDE_FLOAT32_C(  -199.76), SIMDE_FLOAT32_C(  -826.95), SIMDE_FLOAT32_C(  -258.30) },
      SIMDE_FLOAT32_C(  -614.76),
      { SIMDE_FLOAT32_C(-328504.72), SIMDE_FLOAT32_C(122122.20), SIMDE_FLOAT32_C(509015.50), SIMDE_FLOAT32_C(158706.08) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32 c = test_vec[i].c;
    simde_float32x4_t r = simde_vmlaq_n_f32(a, b, c);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32 c = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vmlaq_n_f32(a, b, c);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 29756), -INT16_C( 21306),  INT16_C( 18193), -INT16_C( 21743),  INT16_C( 15788),  INT16_C( 22404),  INT16_C( 28557), -INT16_C( 29072) },
      {  INT16_C( 13465), -INT16_C(  9565),  INT16_C( 29280),  INT16_C(  7895), -INT16_C( 31066),  INT16_C( 32613), -INT16_C( 30322),  INT16_C( 21186) },
      -INT16_C( 30700),
      { -INT16_C(  4168),  INT16_C( 22914),  INT16_C( 13969),  INT16_C( 19421), -INT16_C(  3420), -INT16_C(  3224), -INT16_C( 24923),  INT16_C(  5528) } },
    { {  INT16_C(  9983),  INT16_C(  4304),  INT16_C( 31953),  INT16_C( 21837), -INT16_C(  9517),  INT16_C( 17349),  INT16_C( 24168),  INT16_C(  3191) },
      { -INT16_C( 10440),  INT16_C(  4222),  INT16_C(  9718),  INT16_C( 23446),  INT16_C(  9380),  INT16_C( 26340), -INT16_C(  1673),  INT16_C( 30447) },
      -INT16_C( 16609),
      { -INT16_C(   313),  INT16_C(  4626), -INT16_C( 24677),  INT16_C( 22135), -INT16_C( 22865), -INT16_C( 10911),  INT16_C( 23761), -INT16_C( 15256) } },
    { { -INT16_C(  3962), -INT16_C( 11205),  INT16_C(  3654),  INT16_C(  2990),  INT16_C(  5970), -INT16_C( 13975), -INT16_C( 24029), -INT16_C( 24159) },
      { -INT16_C( 26702),  INT16_C( 18630),  INT16_C( 27378), -INT16_C( 10387), -INT16_C(  6959), -INT16_C( 16176), -INT16_C(  4262), -INT16_C(  8065) },
      -INT16_C( 17697),
      {  INT16_C( 26772),  INT16_C(  5301),  INT16_C(  2836), -INT16_C(  6751),  INT16_C( 17249), -INT16_C(  8551), -INT16_C( 31351),  INT16_C( 30274) } },
    { {  INT16_C(  9652),  INT16_C( 25544),  INT16_C(  6704), -INT16_C( 25990), -INT16_C( 25116), -INT16_C( 31428), -INT16_C(  4546),  INT16_C(  1308) },
      {  INT16_C(  3638), -INT16_C( 23697),  INT16_C( 16613), -INT16_C( 19065), -INT16_C(  7936),  INT16_C( 32676), -INT16_C( 31550),  INT16_C( 30265) },
       INT16_C(   681),
      { -INT16_C(  3238),  INT16_C(  9743), -INT16_C( 17571),  INT16_C( 32409),  INT16_C(  9956),  INT16_C(  4224),  INT16_C(  5712), -INT16_C( 32067) } },
    { { -INT16_C(  9511),  INT16_C( 21276),  INT16_C(   116), -INT16_C( 20240),  INT16_C( 12165), -INT16_C( 24162), -INT16_C( 11212), -INT16_C( 23632) },
      { -INT16_C( 27272), -INT16_C(    28), -INT16_C(  7093), -INT16_C(  4127), -INT16_C( 23708), -INT16_C( 25229),  INT16_C(  7449), -INT16_C(  3169) },
      -INT16_C( 17161),
      {  INT16_C( 12705), -INT16_C( 22504),  INT16_C( 22737),  INT16_C( 24327),  INT16_C( 17665), -INT16_C(   109),  INT16_C( 17235),  INT16_C( 30233) } },
    { {  INT16_C( 27462),  INT16_C( 14268),  INT16_C( 16923), -INT16_C( 18074), -INT16_C( 25885), -INT16_C( 27763),  INT16_C(  1341),  INT16_C(  8489) },
      {  INT16_C( 29701), -INT16_C(  6650),  INT16_C( 27235), -INT16_C( 10359), -INT16_C( 24057), -INT16_C( 22540), -INT16_C(  5227), -INT16_C(  9117) },
       INT16_C(  8022),
      { -INT16_C(    12),  INT16_C( 14272), -INT16_C(   931), -INT16_C( 18324), -INT16_C(  7619), -INT16_C( 29819),  INT16_C( 13387),  INT16_C( 10091) } },
    { {  INT16_C( 28947),  INT16_C( 31073),  INT16_C( 17706), -INT16_C( 18669),  INT16_C( 20696),  INT16_C(   445), -INT16_C( 15758),  INT16_C( 30837) },
      { -INT16_C(  9816),  INT16_C( 12770), -INT16_C(  5712), -INT16_C( 23341),  INT16_C( 27024), -INT16_C(  3185), -INT16_C(  6843),  INT16_C( 22547) },
       INT16_C( 29782),
      { -INT16_C( 20605), -INT16_C( 23731), -INT16_C( 31158), -INT16_C( 19979),  INT16_C(  1848), -INT16_C( 24633),  INT16_C(  2976), -INT16_C( 21801) } },
    { { -INT16_C( 32559), -INT16_C(  6983), -INT16_C( 28105), -INT16_C(  3020), -INT16_C( 22893),  INT16_C(  2486),  INT16_C( 24094),  INT16_C(   226) },
      { -INT16_C( 28017),  INT16_C( 25578),  INT16_C( 31286), -INT16_C( 14900),  INT16_C(  4462), -INT16_C( 32342),  INT16_C(   105),  INT16_C( 15093) },
      -INT16_C( 20608),
      { -INT16_C( 30383), -INT16_C( 12359), -INT16_C( 26825),  INT16_C( 20020), -INT16_C( 28781),  INT16_C(  5302),  INT16_C( 22942), -INT16_C(  2462) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int16x8_t r = simde_vmlaq_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    int16_t c = simde_test_codegen_random_i16();
    simde_int16x8_t r = simde_vmlaq_n_s16(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1499344216),  INT32_C(  1524728521),  INT32_C(  1303864302), -INT32_C(  1288989303) },
      { -INT32_C(  1898069034), -INT32_C(   637691134),  INT32_C(  1260153992), -INT32_C(  1453578159) },
       INT32_C(   503495253),
      { -INT32_C(  2064273562),  INT32_C(  1891200627), -INT32_C(  1374536426), -INT32_C(  1296969106) } },
    { {  INT32_C(   712631356), -INT32_C(   797429689), -INT32_C(  1669094459),  INT32_C(  1747607654) },
      { -INT32_C(  2092881925), -INT32_C(   439460204), -INT32_C(   594597242),  INT32_C(   570069477) },
      -INT32_C(  1135840395),
      { -INT32_C(  1631917325),  INT32_C(  1345709547), -INT32_C(  1043053309), -INT32_C(    80417521) } },
    { {  INT32_C(  1770833060), -INT32_C(   855306393),  INT32_C(  1798713456), -INT32_C(   336627881) },
      {  INT32_C(  1557249493), -INT32_C(   851943192),  INT32_C(  1743663857),  INT32_C(  1243822758) },
       INT32_C(  1706275070),
      {  INT32_C(  2031652346),  INT32_C(  2009904535),  INT32_C(     1403790),  INT32_C(   860342283) } },
    { {  INT32_C(   791919039),  INT32_C(  1083927017), -INT32_C(  1238594848),  INT32_C(   789773639) },
      {  INT32_C(  1325156957),  INT32_C(   582347644),  INT32_C(   611113253),  INT32_C(  1216946313) },
      -INT32_C(  1032274727),
      { -INT32_C(  1086124396), -INT32_C(  1612769787),  INT32_C(  1497351997),  INT32_C(  1902914920) } },
    { {  INT32_C(   100799269), -INT32_C(   457429347), -INT32_C(  2011902421), -INT32_C(  1797844968) },
      {  INT32_C(   565677307), -INT32_C(   297458843),  INT32_C(   473419331), -INT32_C(  1327583349) },
       INT32_C(  1605820866),
      {  INT32_C(  1165329499), -INT32_C(   569719257),  INT32_C(  2001338353), -INT32_C(  1212988818) } },
    { {  INT32_C(   994275855),  INT32_C(  1489196864),  INT32_C(  1676515944), -INT32_C(  1937464281) },
      {  INT32_C(   192661959),  INT32_C(   589804184),  INT32_C(   601032289), -INT32_C(   159216921) },
       INT32_C(  1026672124),
      { -INT32_C(   713345805), -INT32_C(   413262624),  INT32_C(  1629587172),  INT32_C(  1260397195) } },
    { { -INT32_C(  2053769955), -INT32_C(  1226276209), -INT32_C(   297571034), -INT32_C(   822493642) },
      { -INT32_C(   772726672),  INT32_C(   234145062),  INT32_C(  1258583631),  INT32_C(  1485321531) },
      -INT32_C(  1159913942),
      { -INT32_C(  1717409923),  INT32_C(  2113490635),  INT32_C(  1259280412),  INT32_C(   494822372) } },
    { { -INT32_C(   948910432),  INT32_C(  1773515571), -INT32_C(   516379023), -INT32_C(   172873266) },
      {  INT32_C(  1023583982),  INT32_C(  1485375004),  INT32_C(  1722814780), -INT32_C(   803172817) },
      -INT32_C(  2020109996),
      {  INT32_C(  1161714360),  INT32_C(  1906675811),  INT32_C(   455430689),  INT32_C(  1470263354) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vmlaq_n_s32(a, b, c);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    int32_t c = simde_test_codegen_random_i32();
    simde_int32x4_t r = simde_vmlaq_n_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vmlaq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t c;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(32955), UINT16_C(48081), UINT16_C(31759), UINT16_C(16199), UINT16_C(32480), UINT16_C(10241), UINT16_C(21846), UINT16_C(11889) },
      { UINT16_C(60208), UINT16_C( 2393), UINT16_C(43679), UINT16_C(54796), UINT16_C(44510), UINT16_C(46318), UINT16_C( 9561), UINT16_C( 5250) },
      UINT16_C(21413),
      { UINT16_C(42667), UINT16_C(40238), UINT16_C(  394), UINT16_C( 6403), UINT16_C(35062), UINT16_C(61287), UINT16_C(17075), UINT16_C(35899) } },
    { { UINT16_C(46543), UINT16_C( 5839), UINT16_C(45044), UINT16_C(62869), UINT16_C(60376), UINT16_C(18763), UINT16_C(31514), UINT16_C(29492) },
      { UINT16_C(54149), UINT16_C(37150), UINT16_C(64682), UINT16_C(38974), UINT16_C(38832), UINT16_C(12989), UINT16_C(25516), UINT16_C(31621) },
      UINT16_C(21528),
      { UINT16_C(11847), UINT16_C(35231), UINT16_C(10212), UINT16_C(37733), UINT16_C(58456), UINT16_C( 3843), UINT16_C(17210), UINT16_C(43948) } },
    { { UINT16_C( 3218), UINT16_C( 9988), UINT16_C(56321), UINT16_C(19474), UINT16_C(11301), UINT16_C(23240), UINT16_C(19872), UINT16_C(48685) },
      { UINT16_C(55262), UINT16_C( 7354), UINT16_C(27248), UINT16_C(11699), UINT16_C(24476), UINT16_C( 8592), UINT16_C(43227), UINT16_C(28021) },
      UINT16_C(31156),
      { UINT16_C(49834), UINT16_C(17356), UINT16_C(41665), UINT16_C( 2286), UINT16_C( 8661), UINT16_C( 1032), UINT16_C(35484), UINT16_C(  369) } },
    { { UINT16_C(46740), UINT16_C(42581), UINT16_C(31490), UINT16_C(51923), UINT16_C(29653), UINT16_C(  535), UINT16_C(62769), UINT16_C(60378) },
      { UINT16_C(18961), UINT16_C(50517), UINT16_C(61815), UINT16_C( 2084), UINT16_C(65298), UINT16_C(34736), UINT16_C(25964), UINT16_C(    1) },
      UINT16_C(22043),
      { UINT16_C(15455), UINT16_C( 1100), UINT16_C(60559), UINT16_C(48799), UINT16_C(26299), UINT16_C(29095), UINT16_C(61333), UINT16_C(16885) } },
    { { UINT16_C( 7591), UINT16_C(31441), UINT16_C(42728), UINT16_C(65517), UINT16_C( 7849), UINT16_C(33781), UINT16_C( 1545), UINT16_C(24269) },
      { UINT16_C(17611), UINT16_C(61519), UINT16_C(24908), UINT16_C(65007), UINT16_C(23784), UINT16_C(59746), UINT16_C(32092), UINT16_C(  832) },
      UINT16_C( 4506),
      { UINT16_C(64197), UINT16_C(18775), UINT16_C(15008), UINT16_C(41139), UINT16_C(27193), UINT16_C(27369), UINT16_C(35681), UINT16_C(37709) } },
    { { UINT16_C(33405), UINT16_C(27320), UINT16_C(24962), UINT16_C(30600), UINT16_C(37348), UINT16_C(45437), UINT16_C(18927), UINT16_C(16117) },
      { UINT16_C(16953), UINT16_C(10399), UINT16_C(34879), UINT16_C(41348), UINT16_C(57713), UINT16_C(45342), UINT16_C(47332), UINT16_C(25283) },
      UINT16_C(31547),
      { UINT16_C(10400), UINT16_C(11357), UINT16_C( 3335), UINT16_C( 7412), UINT16_C(53743), UINT16_C(60775), UINT16_C(29307), UINT16_C(45798) } },
    { { UINT16_C(48588), UINT16_C(21980), UINT16_C(49204), UINT16_C(45542), UINT16_C(54897), UINT16_C(26362), UINT16_C(13076), UINT16_C(46248) },
      { UINT16_C(59228), UINT16_C(57404), UINT16_C(44424), UINT16_C(42689), UINT16_C(42591), UINT16_C( 8799), UINT16_C(39432), UINT16_C(54429) },
      UINT16_C(31063),
      { UINT16_C(55824), UINT16_C(58944), UINT16_C(  364), UINT16_C(38525), UINT16_C(18362), UINT16_C(64579), UINT16_C(21452), UINT16_C(11011) } },
    { { UINT16_C(35625), UINT16_C( 4153), UINT16_C(43580), UINT16_C(14310), UINT16_C(64016), UINT16_C(47466), UINT16_C(50862), UINT16_C(60064) },
      { UINT16_C(10663), UINT16_C(26776), UINT16_C(63439), UINT16_C(11790), UINT16_C( 5657), UINT16_C(46792), UINT16_C( 8171), UINT16_C( 5167) },
      UINT16_C(26794),
      { UINT16_C( 3087), UINT16_C(17705), UINT16_C(20914), UINT16_C(32050), UINT16_C(52906), UINT16_C(23098), UINT16_C(28860), UINT16_C(27094) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    uint16_t c = test_vec[i].c;
    simde_uint16x8_t r = simde_vmlaq_n_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    uint16_t c = simde_test_codegen_random_u16();
    simde_uint16x8_t r = simde_vmlaq_n_u16(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlaq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1359494925), UINT32_C(3654459894), UINT32_C(3061381284), UINT32_C(2780043972) },
      { UINT32_C(1309599344), UINT32_C(1081949128), UINT32_C(2658471569), UINT32_C(2189969525) },
      UINT32_C(2127794567),
      { UINT32_C(4189664285), UINT32_C(2157015150), UINT32_C(4076259355), UINT32_C(4211840375) } },
    { { UINT32_C(3596068402), UINT32_C(1653395358), UINT32_C(1510490345), UINT32_C(4020770343) },
      { UINT32_C(3794740561), UINT32_C(2827002931), UINT32_C(1948912108), UINT32_C(3438476954) },
      UINT32_C(1117931940),
      { UINT32_C(2909906710), UINT32_C( 302943050), UINT32_C(3777161241), UINT32_C(1465981647) } },
    { { UINT32_C(  27536920), UINT32_C(2505813102), UINT32_C( 344196291), UINT32_C(1576514345) },
      { UINT32_C(1141208919), UINT32_C( 448278656), UINT32_C(3538332206), UINT32_C( 185895155) },
      UINT32_C( 621590710),
      { UINT32_C(1986104818), UINT32_C(3173656430), UINT32_C(1861882231), UINT32_C(2338568171) } },
    { { UINT32_C( 683305061), UINT32_C(2503753580), UINT32_C(1257386994), UINT32_C( 730790059) },
      { UINT32_C(1447446056), UINT32_C(3811060976), UINT32_C(1810775221), UINT32_C(1502673652) },
      UINT32_C(3464579938),
      { UINT32_C(1347877813), UINT32_C( 347587404), UINT32_C(2770565180), UINT32_C(3146286611) } },
    { { UINT32_C(2086977162), UINT32_C(2630244081), UINT32_C(1992840270), UINT32_C(2328628890) },
      { UINT32_C(4016960570), UINT32_C( 626744112), UINT32_C(3095325526), UINT32_C(3230072886) },
      UINT32_C(2940070846),
      { UINT32_C(4144185238), UINT32_C(3183023249), UINT32_C(3296784418), UINT32_C(1393412270) } },
    { { UINT32_C(2420900673), UINT32_C(4060484696), UINT32_C(1551749922), UINT32_C(4165790407) },
      { UINT32_C(2619189062), UINT32_C(3377765266), UINT32_C(1502206875), UINT32_C( 134858438) },
      UINT32_C( 580408778),
      { UINT32_C( 902577789), UINT32_C(2837467020), UINT32_C(3275199088), UINT32_C(3767763203) } },
    { { UINT32_C(2333384297), UINT32_C( 971477361), UINT32_C(3258004348), UINT32_C(1834897114) },
      { UINT32_C(2234954473), UINT32_C(1423884174), UINT32_C(1348265862), UINT32_C(2775774268) },
      UINT32_C(  70289043),
      { UINT32_C(3671281716), UINT32_C(2964579323), UINT32_C( 165300590), UINT32_C(1433924942) } },
    { { UINT32_C(2487031832), UINT32_C( 643198539), UINT32_C(2794697916), UINT32_C(4096510310) },
      { UINT32_C( 239667592), UINT32_C( 761177585), UINT32_C( 768856218), UINT32_C(1865483095) },
      UINT32_C(1728278299),
      { UINT32_C(2511016304), UINT32_C(3793251766), UINT32_C(3140188922), UINT32_C(4191083667) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    uint32_t c = test_vec[i].c;
    simde_uint32x4_t r = simde_vmlaq_n_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    uint32_t c = simde_test_codegen_random_u32();
    simde_uint32x4_t r = simde_vmlaq_n_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_n_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
