#define SIMDE_TEST_ARM_NEON_INSN addv

#include "test-neon.h"
#include "../../../simde/arm/neon/addv.h"

static int
test_simde_vaddv_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -235.05), SIMDE_FLOAT32_C(  -904.04) },
      SIMDE_FLOAT32_C( -1139.09) },
    { { SIMDE_FLOAT32_C(   272.68), SIMDE_FLOAT32_C(   622.28) },
      SIMDE_FLOAT32_C(   894.96) },
    { { SIMDE_FLOAT32_C(  -525.30), SIMDE_FLOAT32_C(  -528.82) },
      SIMDE_FLOAT32_C( -1054.12) },
    { { SIMDE_FLOAT32_C(    29.65), SIMDE_FLOAT32_C(  -351.94) },
      SIMDE_FLOAT32_C(  -322.29) },
    { { SIMDE_FLOAT32_C(   961.57), SIMDE_FLOAT32_C(   223.98) },
      SIMDE_FLOAT32_C(  1185.55) },
    { { SIMDE_FLOAT32_C(  -664.36), SIMDE_FLOAT32_C(   112.82) },
      SIMDE_FLOAT32_C(  -551.54) },
    { { SIMDE_FLOAT32_C(  -605.37), SIMDE_FLOAT32_C(  -434.90) },
      SIMDE_FLOAT32_C( -1040.27) },
    { { SIMDE_FLOAT32_C(  -227.61), SIMDE_FLOAT32_C(  -769.47) },
      SIMDE_FLOAT32_C(  -997.08) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vaddv_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vaddv_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddv_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r;
  } test_vec[] = {
    { { -INT8_C(  38), -INT8_C( 113), -INT8_C(  89),  INT8_C( 100),  INT8_C( 121),  INT8_C(  62),  INT8_C(  96),  INT8_C( 114) },
      -INT8_C(   3) },
    { {  INT8_C(  54),  INT8_C(  22),  INT8_C( 118),  INT8_C(  46),  INT8_C(  72),  INT8_C(  40),  INT8_C( 123), -INT8_C(  76) },
      -INT8_C( 113) },
    { { -INT8_C(  45),  INT8_C(  36),  INT8_C(  32), -INT8_C(  99),  INT8_C(  35),  INT8_C(  22), -INT8_C(  20),  INT8_C(  18) },
      -INT8_C(  21) },
    { {  INT8_C(  24),  INT8_C( 119),  INT8_C(  80), -INT8_C(  27),  INT8_C(  57),  INT8_C(  66),  INT8_C( 123),  INT8_C(  20) },
      -INT8_C(  50) },
    { { -INT8_C(  46),  INT8_C(  35),  INT8_C( 120),  INT8_C(  75),  INT8_C(  97), -INT8_C(  40), -INT8_C(  67), -INT8_C( 104) },
       INT8_C(  70) },
    { { -INT8_C(  17),  INT8_C(  51), -INT8_C(  58),  INT8_C(  55),  INT8_C(  91),  INT8_C(  65), -INT8_C(  20),  INT8_C(  46) },
      -INT8_C(  43) },
    { {  INT8_C( 102),  INT8_C(  12), -INT8_C(  52), -INT8_C( 119),  INT8_C(  34), -INT8_C(  72), -INT8_C( 100),  INT8_C(  58) },
       INT8_C( 119) },
    { {  INT8_C(  48), -INT8_C(  20),  INT8_C(  31),  INT8_C( 105),  INT8_C(  47), -INT8_C( 101),  INT8_C( 125),  INT8_C(   1) },
      -INT8_C(  20) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    int8_t r = simde_vaddv_s8(a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    int8_t r = simde_vaddv_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddv_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r;
  } test_vec[] = {
    { { -INT16_C(  2626),  INT16_C(  8012),  INT16_C(  2510), -INT16_C( 16969) },
      -INT16_C(  9073) },
    { {  INT16_C( 32060), -INT16_C( 26380), -INT16_C(  8001),  INT16_C(  9670) },
       INT16_C(  7349) },
    { { -INT16_C( 27923),  INT16_C(  4014),  INT16_C( 19019),  INT16_C( 31562) },
       INT16_C( 26672) },
    { {  INT16_C( 26935),  INT16_C( 26340),  INT16_C( 25092), -INT16_C( 15769) },
      -INT16_C(  2938) },
    { { -INT16_C( 19625),  INT16_C(  9698), -INT16_C( 26180), -INT16_C(  1822) },
       INT16_C( 27607) },
    { { -INT16_C( 10473), -INT16_C( 10608),  INT16_C( 22455), -INT16_C( 23301) },
      -INT16_C( 21927) },
    { { -INT16_C( 22039),  INT16_C( 13492), -INT16_C(   268),  INT16_C( 11183) },
       INT16_C(  2368) },
    { { -INT16_C( 27545),  INT16_C( 27793), -INT16_C(  1802),  INT16_C( 19758) },
       INT16_C( 18204) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int16_t r = simde_vaddv_s16(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    int16_t r = simde_vaddv_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddv_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r;
  } test_vec[] = {
    { {  INT32_C(  1735594155), -INT32_C(  1050716758) },
       INT32_C(   684877397) },
    { { -INT32_C(   459804628),  INT32_C(   814256711) },
       INT32_C(   354452083) },
    { {  INT32_C(   795163707), -INT32_C(  1571154886) },
      -INT32_C(   775991179) },
    { { -INT32_C(  1643189336), -INT32_C(  1897120541) },
       INT32_C(   754657419) },
    { { -INT32_C(   134914227), -INT32_C(   508013132) },
      -INT32_C(   642927359) },
    { { -INT32_C(  1933226171),  INT32_C(   482102753) },
      -INT32_C(  1451123418) },
    { { -INT32_C(  1001643638), -INT32_C(   563698122) },
      -INT32_C(  1565341760) },
    { {  INT32_C(  1971156114), -INT32_C(    33265231) },
       INT32_C(  1937890883) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int32_t r = simde_vaddv_s32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    int32_t r = simde_vaddv_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddv_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t r;
  } test_vec[] = {
    { { UINT8_C(200), UINT8_C(249), UINT8_C(245), UINT8_C(124), UINT8_C( 78), UINT8_C(173), UINT8_C( 93), UINT8_C(147) },
      UINT8_C( 29) },
    { { UINT8_C(252), UINT8_C( 34), UINT8_C( 31), UINT8_C(221), UINT8_C(112), UINT8_C(220), UINT8_C(249), UINT8_C(250) },
      UINT8_C( 89) },
    { { UINT8_C(253), UINT8_C( 69), UINT8_C(190), UINT8_C( 51), UINT8_C(236), UINT8_C( 37), UINT8_C( 18), UINT8_C(126) },
      UINT8_C(212) },
    { { UINT8_C(153), UINT8_C(143), UINT8_C(243), UINT8_C( 74), UINT8_C(248), UINT8_C(247), UINT8_C( 72), UINT8_C(192) },
      UINT8_C( 92) },
    { { UINT8_C(241), UINT8_C( 61), UINT8_C( 60), UINT8_C( 63), UINT8_C(234), UINT8_C(154), UINT8_C(211), UINT8_C(230) },
      UINT8_C(230) },
    { { UINT8_C(188), UINT8_C(242), UINT8_C(195), UINT8_C( 44), UINT8_C(206), UINT8_C(189), UINT8_C( 38), UINT8_C(204) },
      UINT8_C( 26) },
    { { UINT8_C(  2), UINT8_C(229),    UINT8_MAX, UINT8_C(238), UINT8_C( 10), UINT8_C( 17), UINT8_C(108), UINT8_C(163) },
      UINT8_C(254) },
    { { UINT8_C(160), UINT8_C( 96), UINT8_C(238), UINT8_C(152), UINT8_C( 87), UINT8_C( 54), UINT8_C( 88), UINT8_C( 72) },
      UINT8_C(179) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    uint8_t r = simde_vaddv_u8(a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    uint8_t r = simde_vaddv_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddv_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t r;
  } test_vec[] = {
    { { UINT16_C(38260), UINT16_C(24200), UINT16_C(23343), UINT16_C(60229) },
      UINT16_C(14960) },
    { { UINT16_C( 2125), UINT16_C( 7192), UINT16_C(16069), UINT16_C(51432) },
      UINT16_C(11282) },
    { { UINT16_C(59171), UINT16_C(11702), UINT16_C( 9209), UINT16_C(39377) },
      UINT16_C(53923) },
    { { UINT16_C(49027), UINT16_C(55858), UINT16_C(35573), UINT16_C(26915) },
      UINT16_C(36301) },
    { { UINT16_C(43807), UINT16_C(20168), UINT16_C( 3334), UINT16_C(21306) },
      UINT16_C(23079) },
    { { UINT16_C(21013), UINT16_C(56175), UINT16_C(22416), UINT16_C(46243) },
      UINT16_C(14775) },
    { { UINT16_C(22847), UINT16_C(14561), UINT16_C(45692), UINT16_C(65489) },
      UINT16_C(17517) },
    { { UINT16_C(  881), UINT16_C(26586), UINT16_C(64910), UINT16_C(44496) },
      UINT16_C( 5801) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    uint16_t r = simde_vaddv_u16(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    uint16_t r = simde_vaddv_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddv_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r;
  } test_vec[] = {
    { { UINT32_C(2935789736), UINT32_C(3137418917) },
      UINT32_C(1778241357) },
    { { UINT32_C( 412512648), UINT32_C( 130824648) },
      UINT32_C( 543337296) },
    { { UINT32_C( 255831698), UINT32_C(3524137312) },
      UINT32_C(3779969010) },
    { { UINT32_C(2721703956), UINT32_C(2370832869) },
      UINT32_C( 797569529) },
    { { UINT32_C(1195068578), UINT32_C( 167918978) },
      UINT32_C(1362987556) },
    { { UINT32_C(1981978798), UINT32_C(1686040529) },
      UINT32_C(3668019327) },
    { { UINT32_C(4252220829), UINT32_C(3822027214) },
      UINT32_C(3779280747) },
    { { UINT32_C(1334118506), UINT32_C(3034436882) },
      UINT32_C(  73588092) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    uint32_t r = simde_vaddv_u32(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    uint32_t r = simde_vaddv_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -654.47), SIMDE_FLOAT32_C(  -946.98), SIMDE_FLOAT32_C(  -606.16), SIMDE_FLOAT32_C(   426.64) },
      SIMDE_FLOAT32_C( -1780.97) },
    { { SIMDE_FLOAT32_C(   868.73), SIMDE_FLOAT32_C(  -655.12), SIMDE_FLOAT32_C(   -15.45), SIMDE_FLOAT32_C(   495.29) },
      SIMDE_FLOAT32_C(   693.45) },
    { { SIMDE_FLOAT32_C(  -337.86), SIMDE_FLOAT32_C(  -244.89), SIMDE_FLOAT32_C(    98.86), SIMDE_FLOAT32_C(   743.11) },
      SIMDE_FLOAT32_C(   259.22) },
    { { SIMDE_FLOAT32_C(  -546.07), SIMDE_FLOAT32_C(   748.90), SIMDE_FLOAT32_C(  -734.79), SIMDE_FLOAT32_C(   726.97) },
      SIMDE_FLOAT32_C(   195.01) },
    { { SIMDE_FLOAT32_C(  -248.73), SIMDE_FLOAT32_C(   463.88), SIMDE_FLOAT32_C(   495.61), SIMDE_FLOAT32_C(  -608.95) },
      SIMDE_FLOAT32_C(   101.81) },
    { { SIMDE_FLOAT32_C(   490.96), SIMDE_FLOAT32_C(    76.01), SIMDE_FLOAT32_C(  -900.59), SIMDE_FLOAT32_C(    34.68) },
      SIMDE_FLOAT32_C(  -298.94) },
    { { SIMDE_FLOAT32_C(   663.94), SIMDE_FLOAT32_C(   660.23), SIMDE_FLOAT32_C(   682.64), SIMDE_FLOAT32_C(  -644.47) },
      SIMDE_FLOAT32_C(  1362.34) },
    { { SIMDE_FLOAT32_C(  -909.10), SIMDE_FLOAT32_C(    23.60), SIMDE_FLOAT32_C(  -382.13), SIMDE_FLOAT32_C(  -563.57) },
      SIMDE_FLOAT32_C( -1831.20) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32_t r = simde_vaddvq_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vaddvq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[4];
    simde_float64_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -439.88), SIMDE_FLOAT64_C(   593.77) },
      SIMDE_FLOAT64_C(   153.89) },
    { { SIMDE_FLOAT64_C(   555.36), SIMDE_FLOAT64_C(   -41.81) },
      SIMDE_FLOAT64_C(   513.55) },
    { { SIMDE_FLOAT64_C(  -578.35), SIMDE_FLOAT64_C(  -756.91) },
      SIMDE_FLOAT64_C( -1335.26) },
    { { SIMDE_FLOAT64_C(   564.48), SIMDE_FLOAT64_C(  -445.40) },
      SIMDE_FLOAT64_C(   119.08) },
    { { SIMDE_FLOAT64_C(   762.82), SIMDE_FLOAT64_C(  -204.54) },
      SIMDE_FLOAT64_C(   558.28) },
    { { SIMDE_FLOAT64_C(   674.09), SIMDE_FLOAT64_C(   291.13) },
      SIMDE_FLOAT64_C(   965.22) },
    { { SIMDE_FLOAT64_C(  -929.06), SIMDE_FLOAT64_C(   684.47) },
      SIMDE_FLOAT64_C(  -244.59) },
    { { SIMDE_FLOAT64_C(   -72.52), SIMDE_FLOAT64_C(   177.81) },
      SIMDE_FLOAT64_C(   105.29) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vaddvq_f64(a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64_t r = simde_vaddvq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r;
  } test_vec[] = {
    { {  INT8_C(  16),  INT8_C(  76),  INT8_C(  79),  INT8_C(   9), -INT8_C(  28),  INT8_C(   2), -INT8_C(  67), -INT8_C(  45),
         INT8_C(  62), -INT8_C(  12),  INT8_C(  22), -INT8_C(  28),  INT8_C( 114), -INT8_C(  59),      INT8_MIN, -INT8_C(  11) },
       INT8_C(   2) },
    { {  INT8_C(  88),  INT8_C(  56), -INT8_C( 101), -INT8_C( 108), -INT8_C( 120), -INT8_C(  73),  INT8_C( 121),  INT8_C(   8),
        -INT8_C( 108),  INT8_C(  83), -INT8_C(  27),  INT8_C( 113),  INT8_C( 120), -INT8_C(  59), -INT8_C(  31), -INT8_C( 120) },
       INT8_C(  98) },
    { {  INT8_C(  17),  INT8_C(  48), -INT8_C( 111), -INT8_C(  11),  INT8_C(  50),  INT8_C(  79), -INT8_C(  55),  INT8_C( 112),
         INT8_C(  67), -INT8_C(  33),  INT8_C(  84), -INT8_C(  75), -INT8_C(  92), -INT8_C(  44), -INT8_C(  85), -INT8_C(   3) },
      -INT8_C(  52) },
    { {  INT8_C(  13),  INT8_C(  70), -INT8_C( 111), -INT8_C( 107), -INT8_C(   3),  INT8_C(  11), -INT8_C(  99), -INT8_C( 111),
         INT8_C(  94), -INT8_C( 125),  INT8_C(   2), -INT8_C(  42),  INT8_C(  72), -INT8_C(  29),  INT8_C(  94),  INT8_C(  89) },
       INT8_C(  74) },
    { {  INT8_C(  20), -INT8_C(  17),  INT8_C(  79),  INT8_C(  70),  INT8_C(  62),  INT8_C(  24), -INT8_C(  73), -INT8_C( 126),
        -INT8_C(   9),  INT8_C(  11),  INT8_C(  55), -INT8_C( 101), -INT8_C(  32), -INT8_C(  30), -INT8_C( 104), -INT8_C(  19) },
       INT8_C(  66) },
    { {  INT8_C(  40),  INT8_C(  42), -INT8_C( 126),  INT8_C(  37),  INT8_C(  53),  INT8_C(  32), -INT8_C(  74), -INT8_C( 109),
        -INT8_C(  93), -INT8_C(  72),  INT8_C( 105), -INT8_C(  21), -INT8_C( 100), -INT8_C(  57),  INT8_C(  68), -INT8_C(  80) },
      -INT8_C(  99) },
    { { -INT8_C(  74), -INT8_C( 109), -INT8_C(  10), -INT8_C(  11), -INT8_C(  85), -INT8_C(  83),  INT8_C( 119), -INT8_C(  94),
        -INT8_C(  71), -INT8_C(  82),  INT8_C(  62), -INT8_C( 103), -INT8_C( 111), -INT8_C(  42), -INT8_C( 122), -INT8_C(  71) },
      -INT8_C( 119) },
    { {  INT8_C(   0),  INT8_C(   8), -INT8_C(  33),  INT8_C(  53),  INT8_C(  40), -INT8_C( 107), -INT8_C(  56), -INT8_C(  53),
         INT8_C(  78),  INT8_C(  49), -INT8_C(  74), -INT8_C(  22), -INT8_C(   8), -INT8_C(   5), -INT8_C( 102), -INT8_C(  81) },
      -INT8_C(  57) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    int8_t r = simde_vaddvq_s8(a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    int8_t r = simde_vaddvq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r;
  } test_vec[] = {
    { { -INT16_C(  3794), -INT16_C( 24556),  INT16_C( 21790),  INT16_C( 24512),  INT16_C( 18139),  INT16_C( 27136),  INT16_C( 20420), -INT16_C( 27241) },
      -INT16_C(  9130) },
    { { -INT16_C( 10776), -INT16_C( 29256),  INT16_C( 21382),  INT16_C(  1930),  INT16_C( 27942),  INT16_C( 13973), -INT16_C( 28904),  INT16_C( 17957) },
       INT16_C( 14248) },
    { {  INT16_C( 14720), -INT16_C( 24858), -INT16_C( 22898),  INT16_C( 27134), -INT16_C(   275), -INT16_C( 20013),  INT16_C( 27214),  INT16_C( 13894) },
       INT16_C( 14918) },
    { { -INT16_C(   448), -INT16_C( 14652),  INT16_C( 20049),  INT16_C( 30669),  INT16_C( 25275), -INT16_C( 11091), -INT16_C( 11535),  INT16_C( 28954) },
       INT16_C(  1685) },
    { {  INT16_C(   268), -INT16_C( 26097),  INT16_C(  3495), -INT16_C( 27644), -INT16_C( 10484),  INT16_C( 23109), -INT16_C( 29886), -INT16_C( 32112) },
       INT16_C( 31721) },
    { {  INT16_C( 21642), -INT16_C(  9400),  INT16_C(  5538),  INT16_C( 24147),  INT16_C(   119),  INT16_C( 26674),  INT16_C( 19667), -INT16_C(  8231) },
       INT16_C( 14620) },
    { { -INT16_C(  6067), -INT16_C(  2695),  INT16_C( 32246),  INT16_C(   649), -INT16_C( 12459), -INT16_C( 26788), -INT16_C(  5030), -INT16_C(  7143) },
      -INT16_C( 27287) },
    { {  INT16_C( 24897), -INT16_C(  7232),  INT16_C(  4982), -INT16_C(  4799),  INT16_C( 29459), -INT16_C(  6571),  INT16_C( 11968),  INT16_C(  3525) },
      -INT16_C(  9307) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t r = simde_vaddvq_s16(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    int16_t r = simde_vaddvq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r;
  } test_vec[] = {
    { {  INT32_C(   409309617),  INT32_C(   703009121),  INT32_C(  1805496451),  INT32_C(   168549695) },
      -INT32_C(  1208602412) },
    { { -INT32_C(  1162156857),  INT32_C(   605475000), -INT32_C(  1732960282), -INT32_C(   349401798) },
       INT32_C(  1655923359) },
    { {  INT32_C(  2130940190),  INT32_C(   631827106), -INT32_C(   644856422), -INT32_C(   354116829) },
       INT32_C(  1763794045) },
    { {  INT32_C(   950312575),  INT32_C(  1432140399),  INT32_C(   334303705), -INT32_C(  1107420770) },
       INT32_C(  1609335909) },
    { {  INT32_C(  1279001002), -INT32_C(  2039290389),  INT32_C(  1298072106),  INT32_C(   490161054) },
       INT32_C(  1027943773) },
    { {  INT32_C(  1364581346),  INT32_C(  1873195414),  INT32_C(  1636013250),  INT32_C(  1478394285) },
       INT32_C(  2057216999) },
    { {  INT32_C(  1856264835),  INT32_C(  1794381375), -INT32_C(  1212722151),  INT32_C(  2043998103) },
       INT32_C(   186954866) },
    { {  INT32_C(  1623861962), -INT32_C(  1630506533), -INT32_C(  1291889915),  INT32_C(  1460280788) },
       INT32_C(   161746302) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t r = simde_vaddvq_s32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    int32_t r = simde_vaddvq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[8];
    int64_t r;
  } test_vec[] = {
    { { -INT64_C( 3175282498865185383), -INT64_C( 6685163521795333907) },
       INT64_C( 8586298053049032326) },
    { {  INT64_C( 4743869010420501684),  INT64_C( 3259920673574755233) },
       INT64_C( 8003789683995256917) },
    { { -INT64_C( 1439710424467513906),  INT64_C( 4491054795359323006) },
       INT64_C( 3051344370891809100) },
    { { -INT64_C( 6235463451047990149),  INT64_C( 3894372779454748490) },
      -INT64_C( 2341090671593241659) },
    { { -INT64_C( 2927499906595145100),  INT64_C( 9095823207579489649) },
       INT64_C( 6168323300984344549) },
    { {  INT64_C( 1006603734084785223),  INT64_C( 6746945194881143043) },
       INT64_C( 7753548928965928266) },
    { { -INT64_C( 1630249770841798095),  INT64_C(  740594489963636933) },
      -INT64_C(  889655280878161162) },
    { {  INT64_C( 3135157520517692338), -INT64_C( 7644798362971640413) },
      -INT64_C( 4509640842453948075) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    int64_t r = simde_vaddvq_s64(a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    int64_t r = simde_vaddvq_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r;
  } test_vec[] = {
    { { UINT8_C( 32), UINT8_C( 30), UINT8_C(162), UINT8_C(114), UINT8_C( 14), UINT8_C(107), UINT8_C(223), UINT8_C(214),
        UINT8_C(123), UINT8_C(157), UINT8_C(124), UINT8_C( 64), UINT8_C(165), UINT8_C( 90), UINT8_C( 91), UINT8_C( 44) },
      UINT8_C(218) },
    { { UINT8_C( 60), UINT8_C( 50), UINT8_C(179), UINT8_C(217), UINT8_C( 36), UINT8_C( 73), UINT8_C(187), UINT8_C(120),
        UINT8_C(132), UINT8_C(216), UINT8_C( 31), UINT8_C(214), UINT8_C( 17), UINT8_C( 72), UINT8_C(168), UINT8_C( 49) },
      UINT8_C( 29) },
    { { UINT8_C(102), UINT8_C( 74), UINT8_C(163), UINT8_C(116), UINT8_C(181), UINT8_C(131), UINT8_C( 74), UINT8_C( 48),
        UINT8_C( 32), UINT8_C(198), UINT8_C(113), UINT8_C(197), UINT8_C( 33), UINT8_C(204), UINT8_C(242), UINT8_C( 93) },
      UINT8_C(209) },
    { {    UINT8_MAX, UINT8_C(165), UINT8_C( 54), UINT8_C( 35), UINT8_C(238), UINT8_C(241), UINT8_C(155), UINT8_C(115),
        UINT8_C(201), UINT8_C(186), UINT8_C( 73), UINT8_C(218), UINT8_C(  2), UINT8_C(242), UINT8_C( 12), UINT8_C(105) },
      UINT8_C(249) },
    { { UINT8_C( 60), UINT8_C(175), UINT8_C(221), UINT8_C(242), UINT8_C( 50), UINT8_C( 40), UINT8_C( 34), UINT8_C( 82),
        UINT8_C(238), UINT8_C(147), UINT8_C( 24), UINT8_C( 15), UINT8_C( 96), UINT8_C( 10), UINT8_C(109), UINT8_C( 95) },
      UINT8_C(102) },
    { { UINT8_C(175), UINT8_C(163), UINT8_C(130), UINT8_C(157), UINT8_C(149), UINT8_C( 29), UINT8_C( 16), UINT8_C( 94),
        UINT8_C(215), UINT8_C( 90), UINT8_C( 57), UINT8_C(217), UINT8_C( 76), UINT8_C( 69), UINT8_C( 66), UINT8_C(136) },
      UINT8_C( 47) },
    { { UINT8_C(244), UINT8_C( 32), UINT8_C(122), UINT8_C( 39), UINT8_C( 72), UINT8_C(157), UINT8_C(121), UINT8_C( 54),
        UINT8_C( 48), UINT8_C(145), UINT8_C( 70), UINT8_C(144), UINT8_C(155), UINT8_C(179), UINT8_C(239), UINT8_C( 74) },
      UINT8_C(103) },
    { { UINT8_C( 86), UINT8_C(113), UINT8_C(232), UINT8_C(235), UINT8_C(142), UINT8_C(248), UINT8_C( 74), UINT8_C(101),
        UINT8_C( 82), UINT8_C(131), UINT8_C( 63), UINT8_C(158), UINT8_C(200), UINT8_C(129), UINT8_C( 39), UINT8_C(188) },
      UINT8_C(173) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    uint8_t r = simde_vaddvq_u8(a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    uint8_t r = simde_vaddvq_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r;
  } test_vec[] = {
    { { UINT16_C(41377), UINT16_C(59875), UINT16_C(23870), UINT16_C(28448), UINT16_C(26350), UINT16_C(35583), UINT16_C(61209), UINT16_C(28628) },
      UINT16_C(43196) },
    { { UINT16_C(48224), UINT16_C(61275), UINT16_C(42421), UINT16_C( 1876), UINT16_C(37672), UINT16_C(61606), UINT16_C(52501), UINT16_C(46764) },
      UINT16_C(24659) },
    { { UINT16_C(36974), UINT16_C(44448), UINT16_C(49389), UINT16_C(56092), UINT16_C( 6950), UINT16_C(16229), UINT16_C(14858), UINT16_C(27566) },
      UINT16_C(55898) },
    { { UINT16_C( 2550), UINT16_C(43866), UINT16_C(44718), UINT16_C(54963), UINT16_C(22850), UINT16_C(22470), UINT16_C(29478), UINT16_C(37901) },
      UINT16_C(62188) },
    { { UINT16_C(44291), UINT16_C(61505), UINT16_C(23917), UINT16_C(37835), UINT16_C(12665), UINT16_C(33746), UINT16_C(33131), UINT16_C(25070) },
      UINT16_C(10016) },
    { { UINT16_C(18570), UINT16_C(14605), UINT16_C(49399), UINT16_C(14607), UINT16_C(54809), UINT16_C(16272), UINT16_C(40265), UINT16_C(19667) },
      UINT16_C(31586) },
    { { UINT16_C( 5451), UINT16_C(47164), UINT16_C( 1906), UINT16_C(60236), UINT16_C( 7736), UINT16_C(41839), UINT16_C(23967), UINT16_C(10757) },
      UINT16_C( 2448) },
    { { UINT16_C( 4774), UINT16_C(40291), UINT16_C(29394), UINT16_C(60374), UINT16_C(26184), UINT16_C(37162), UINT16_C(64771), UINT16_C(20189) },
      UINT16_C(20995) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    uint16_t r = simde_vaddvq_u16(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    uint16_t r = simde_vaddvq_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r;
  } test_vec[] = {
    { { UINT32_C(2231834898), UINT32_C(1500533537), UINT32_C( 301850481), UINT32_C(3812295229) },
      UINT32_C(3551546849) },
    { { UINT32_C(3867188756), UINT32_C(1506891280), UINT32_C(3219848124), UINT32_C( 185518328) },
      UINT32_C( 189511896) },
    { { UINT32_C(  42997217), UINT32_C(3646685288), UINT32_C( 501897696), UINT32_C(1862280539) },
      UINT32_C(1758893444) },
    { { UINT32_C(3562373315), UINT32_C(2452432598), UINT32_C( 424744737), UINT32_C(3240386527) },
      UINT32_C(1090002585) },
    { { UINT32_C(3703813236), UINT32_C(2511740853), UINT32_C(3551699064), UINT32_C(2302849734) },
      UINT32_C(3480168295) },
    { { UINT32_C( 140351282), UINT32_C(3734670013), UINT32_C(2180574114), UINT32_C(3208780875) },
      UINT32_C( 674441692) },
    { { UINT32_C(2258372305), UINT32_C(2652590629), UINT32_C(3094466034), UINT32_C(2973938815) },
      UINT32_C(2389433191) },
    { { UINT32_C( 163159883), UINT32_C(3437712170), UINT32_C(2303582014), UINT32_C(3444150524) },
      UINT32_C( 758669999) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint32_t r = simde_vaddvq_u32(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    uint32_t r = simde_vaddvq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddvq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[8];
    uint64_t r;
  } test_vec[] = {
    { { UINT64_C( 2979533814127388054), UINT64_C(14585791949184355131) },
      UINT64_C(17565325763311743185) },
    { { UINT64_C(13094703515321967811), UINT64_C( 3270607939043264410) },
      UINT64_C(16365311454365232221) },
    { { UINT64_C( 6903246528981808749), UINT64_C(10905049591847694093) },
      UINT64_C(17808296120829502842) },
    { { UINT64_C( 9211337766653405864), UINT64_C(  651185335746040901) },
      UINT64_C( 9862523102399446765) },
    { { UINT64_C( 4662485875117912368), UINT64_C(18056095645387509034) },
      UINT64_C( 4271837446795869786) },
    { { UINT64_C(11291068898576308557), UINT64_C( 8189938041221596931) },
      UINT64_C( 1034262866088353872) },
    { { UINT64_C(18007214092850648434), UINT64_C( 2563546366726353735) },
      UINT64_C( 2124016385867450553) },
    { { UINT64_C(11499667444815211940), UINT64_C(  252455085538152398) },
      UINT64_C(11752122530353364338) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    uint64_t r = simde_vaddvq_u64(a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    uint64_t r = simde_vaddvq_u64(a);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddv_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddv_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddv_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddv_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddv_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddv_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddv_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddvq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
