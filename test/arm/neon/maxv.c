#define SIMDE_TEST_ARM_NEON_INSN maxv

#include "test-neon.h"
#include "../../../simde/arm/neon/maxv.h"

static int
test_simde_vmaxv_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   498.24), SIMDE_FLOAT32_C(   700.18) },
      SIMDE_FLOAT32_C(   700.18) },
    { { SIMDE_FLOAT32_C(  -550.14), SIMDE_FLOAT32_C(  -372.82) },
      SIMDE_FLOAT32_C(  -372.82) },
    { { SIMDE_FLOAT32_C(  -184.85), SIMDE_FLOAT32_C(   347.23) },
      SIMDE_FLOAT32_C(   347.23) },
    { { SIMDE_FLOAT32_C(  -183.13), SIMDE_FLOAT32_C(   910.25) },
      SIMDE_FLOAT32_C(   910.25) },
    { { SIMDE_FLOAT32_C(   995.08), SIMDE_FLOAT32_C(   458.35) },
      SIMDE_FLOAT32_C(   995.08) },
    { { SIMDE_FLOAT32_C(   954.33), SIMDE_FLOAT32_C(   629.96) },
      SIMDE_FLOAT32_C(   954.33) },
    { { SIMDE_FLOAT32_C(   -93.64), SIMDE_FLOAT32_C(   684.43) },
      SIMDE_FLOAT32_C(   684.43) },
    { { SIMDE_FLOAT32_C(   -76.95), SIMDE_FLOAT32_C(  -360.35) },
      SIMDE_FLOAT32_C(   -76.95) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vmaxv_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vmaxv_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxv_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r;
  } test_vec[] = {
    { { -INT8_C( 119),  INT8_C(  14),  INT8_C( 112),  INT8_C(   4),  INT8_C(  39),  INT8_C( 117),  INT8_C(  71), -INT8_C(  89) },
       INT8_C( 117) },
    { {  INT8_C(  81), -INT8_C(  12), -INT8_C(  30),  INT8_C(   0), -INT8_C(  49),  INT8_C(  49), -INT8_C(  49),  INT8_C(  50) },
       INT8_C(  81) },
    { { -INT8_C(  34), -INT8_C(  73), -INT8_C(   1), -INT8_C(  27),  INT8_C( 106), -INT8_C(  54),  INT8_C(  19), -INT8_C(  81) },
       INT8_C( 106) },
    { {  INT8_C(  59), -INT8_C(  99), -INT8_C(  13),  INT8_C(  90), -INT8_C( 105), -INT8_C( 108), -INT8_C(  64),  INT8_C(  32) },
       INT8_C(  90) },
    { { -INT8_C(  94),  INT8_C(  48),  INT8_C(  36), -INT8_C(  55), -INT8_C(  91),  INT8_C( 108),  INT8_C( 112), -INT8_C(  10) },
       INT8_C( 112) },
    { {  INT8_C(  96),  INT8_C(  83), -INT8_C(  10),  INT8_C(  47), -INT8_C( 124), -INT8_C(  58),  INT8_C(  97),  INT8_C(  98) },
       INT8_C(  98) },
    { {  INT8_C( 125),  INT8_C(  96),  INT8_C(  71), -INT8_C(  24),  INT8_C(  42),  INT8_C(  90), -INT8_C( 105),  INT8_C( 101) },
       INT8_C( 125) },
    { { -INT8_C(   8), -INT8_C( 117), -INT8_C(  65), -INT8_C( 113),  INT8_C(  31),      INT8_MAX, -INT8_C(  80), -INT8_C(  63) },
           INT8_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    int8_t r = simde_vmaxv_s8(a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    int8_t r = simde_vmaxv_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxv_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r;
  } test_vec[] = {
    { { -INT16_C( 11089),  INT16_C( 21642), -INT16_C(  1216), -INT16_C( 24501) },
       INT16_C( 21642) },
    { {  INT16_C( 16718), -INT16_C( 11569),  INT16_C( 12295), -INT16_C( 31436) },
       INT16_C( 16718) },
    { {  INT16_C( 31888), -INT16_C( 17811),  INT16_C(  1238), -INT16_C( 12769) },
       INT16_C( 31888) },
    { { -INT16_C(  8561), -INT16_C( 20898),  INT16_C(  3677),  INT16_C(  3183) },
       INT16_C(  3677) },
    { { -INT16_C(  1310),  INT16_C(  9057), -INT16_C( 21259),  INT16_C( 17347) },
       INT16_C( 17347) },
    { { -INT16_C( 27667), -INT16_C(  2795),  INT16_C( 18883),  INT16_C( 21626) },
       INT16_C( 21626) },
    { { -INT16_C(  6203), -INT16_C( 25586),  INT16_C( 12011),  INT16_C( 31594) },
       INT16_C( 31594) },
    { { -INT16_C( 14324),  INT16_C( 27177), -INT16_C( 26154), -INT16_C( 18058) },
       INT16_C( 27177) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int16_t r = simde_vmaxv_s16(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    int16_t r = simde_vmaxv_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxv_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r;
  } test_vec[] = {
    { { -INT32_C(  1998792813),  INT32_C(  1909170051) },
       INT32_C(  1909170051) },
    { { -INT32_C(   161030094), -INT32_C(   280305623) },
      -INT32_C(   161030094) },
    { { -INT32_C(  1299490617), -INT32_C(  1825704570) },
      -INT32_C(  1299490617) },
    { { -INT32_C(  1795336258), -INT32_C(  2092076048) },
      -INT32_C(  1795336258) },
    { { -INT32_C(   838129333), -INT32_C(    79702327) },
      -INT32_C(    79702327) },
    { { -INT32_C(   537811530),  INT32_C(  1288584069) },
       INT32_C(  1288584069) },
    { {  INT32_C(   452942228),  INT32_C(   229452879) },
       INT32_C(   452942228) },
    { {  INT32_C(  1939974787),  INT32_C(  1777790750) },
       INT32_C(  1939974787) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int32_t r = simde_vmaxv_s32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    int32_t r = simde_vmaxv_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxv_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t r;
  } test_vec[] = {
    { { UINT8_C( 24), UINT8_C(  1), UINT8_C( 55), UINT8_C(225), UINT8_C(215), UINT8_C(119), UINT8_C(221), UINT8_C(141) },
      UINT8_C(225) },
    { { UINT8_C( 28), UINT8_C(206), UINT8_C(109), UINT8_C(162), UINT8_C( 10), UINT8_C( 59), UINT8_C(238), UINT8_C(158) },
      UINT8_C(238) },
    { { UINT8_C(149), UINT8_C(237), UINT8_C(184), UINT8_C(228), UINT8_C( 26), UINT8_C(102), UINT8_C(241), UINT8_C(157) },
      UINT8_C(241) },
    { { UINT8_C( 16), UINT8_C(146), UINT8_C( 17), UINT8_C( 46), UINT8_C(129), UINT8_C(  7), UINT8_C(151), UINT8_C(154) },
      UINT8_C(154) },
    { { UINT8_C(  9), UINT8_C(207), UINT8_C(123), UINT8_C(224), UINT8_C( 70), UINT8_C( 88), UINT8_C(110), UINT8_C( 98) },
      UINT8_C(224) },
    { { UINT8_C( 39), UINT8_C(219), UINT8_C(  4), UINT8_C( 49), UINT8_C( 22), UINT8_C(243), UINT8_C(207), UINT8_C(171) },
      UINT8_C(243) },
    { { UINT8_C(224), UINT8_C(135), UINT8_C(143), UINT8_C(250), UINT8_C(237), UINT8_C(128), UINT8_C(152), UINT8_C(254) },
      UINT8_C(254) },
    { { UINT8_C( 19), UINT8_C(169), UINT8_C( 44), UINT8_C(148), UINT8_C(176), UINT8_C(196), UINT8_C( 46), UINT8_C(185) },
      UINT8_C(196) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    uint8_t r = simde_vmaxv_u8(a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    uint8_t r = simde_vmaxv_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxv_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t r;
  } test_vec[] = {
    { { UINT16_C(43667), UINT16_C(55706), UINT16_C( 2050), UINT16_C(10555) },
      UINT16_C(55706) },
    { { UINT16_C(16611), UINT16_C(63834), UINT16_C(10547), UINT16_C( 5029) },
      UINT16_C(63834) },
    { { UINT16_C(13489), UINT16_C(40462), UINT16_C(42677), UINT16_C(51356) },
      UINT16_C(51356) },
    { { UINT16_C(51535), UINT16_C(65372), UINT16_C(35725), UINT16_C( 8377) },
      UINT16_C(65372) },
    { { UINT16_C(21301), UINT16_C(14329), UINT16_C(13403), UINT16_C(15969) },
      UINT16_C(21301) },
    { { UINT16_C(47988), UINT16_C(42807), UINT16_C(56549), UINT16_C(38587) },
      UINT16_C(56549) },
    { { UINT16_C(51473), UINT16_C(50740), UINT16_C(53615), UINT16_C(48782) },
      UINT16_C(53615) },
    { { UINT16_C(60058), UINT16_C(10173), UINT16_C(30325), UINT16_C(43591) },
      UINT16_C(60058) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    uint16_t r = simde_vmaxv_u16(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    uint16_t r = simde_vmaxv_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxv_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r;
  } test_vec[] = {
    { { UINT32_C( 618807497), UINT32_C(3915531124) },
      UINT32_C(3915531124) },
    { { UINT32_C(3817904894), UINT32_C(2272873334) },
      UINT32_C(3817904894) },
    { { UINT32_C(2202906132), UINT32_C( 423746431) },
      UINT32_C(2202906132) },
    { { UINT32_C( 994115526), UINT32_C(1072072565) },
      UINT32_C(1072072565) },
    { { UINT32_C( 996395207), UINT32_C( 153404939) },
      UINT32_C( 996395207) },
    { { UINT32_C(3605902688), UINT32_C( 358508032) },
      UINT32_C(3605902688) },
    { { UINT32_C(2476256020), UINT32_C(1303173767) },
      UINT32_C(2476256020) },
    { { UINT32_C(1317596377), UINT32_C( 982347379) },
      UINT32_C(1317596377) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    uint32_t r = simde_vmaxv_u32(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    uint32_t r = simde_vmaxv_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxvq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -913.17), SIMDE_FLOAT32_C(  -110.66), SIMDE_FLOAT32_C(   975.06), SIMDE_FLOAT32_C(   216.37) },
      SIMDE_FLOAT32_C(   975.06) },
    { { SIMDE_FLOAT32_C(   803.46), SIMDE_FLOAT32_C(   420.85), SIMDE_FLOAT32_C(  -602.65), SIMDE_FLOAT32_C(  -768.35) },
      SIMDE_FLOAT32_C(   803.46) },
    { { SIMDE_FLOAT32_C(   208.72), SIMDE_FLOAT32_C(   938.55), SIMDE_FLOAT32_C(  -166.98), SIMDE_FLOAT32_C(  -194.96) },
      SIMDE_FLOAT32_C(   938.55) },
    { { SIMDE_FLOAT32_C(   658.71), SIMDE_FLOAT32_C(  -102.67), SIMDE_FLOAT32_C(  -344.04), SIMDE_FLOAT32_C(   -91.55) },
      SIMDE_FLOAT32_C(   658.71) },
    { { SIMDE_FLOAT32_C(  -612.74), SIMDE_FLOAT32_C(  -313.43), SIMDE_FLOAT32_C(   -63.59), SIMDE_FLOAT32_C(   951.39) },
      SIMDE_FLOAT32_C(   951.39) },
    { { SIMDE_FLOAT32_C(   -79.23), SIMDE_FLOAT32_C(   283.94), SIMDE_FLOAT32_C(   381.77), SIMDE_FLOAT32_C(   496.29) },
      SIMDE_FLOAT32_C(   496.29) },
    { { SIMDE_FLOAT32_C(   588.86), SIMDE_FLOAT32_C(  -488.36), SIMDE_FLOAT32_C(   652.93), SIMDE_FLOAT32_C(  -868.04) },
      SIMDE_FLOAT32_C(   652.93) },
    { { SIMDE_FLOAT32_C(  -913.85), SIMDE_FLOAT32_C(  -606.06), SIMDE_FLOAT32_C(  -892.31), SIMDE_FLOAT32_C(  -827.02) },
      SIMDE_FLOAT32_C(  -606.06) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32_t r = simde_vmaxvq_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vmaxvq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxvq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[4];
    simde_float64_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   283.28), SIMDE_FLOAT64_C(  -917.25) },
      SIMDE_FLOAT64_C(   283.28) },
    { { SIMDE_FLOAT64_C(   389.34), SIMDE_FLOAT64_C(    86.75) },
      SIMDE_FLOAT64_C(   389.34) },
    { { SIMDE_FLOAT64_C(   503.60), SIMDE_FLOAT64_C(   786.70) },
      SIMDE_FLOAT64_C(   786.70) },
    { { SIMDE_FLOAT64_C(   318.40), SIMDE_FLOAT64_C(  -287.68) },
      SIMDE_FLOAT64_C(   318.40) },
    { { SIMDE_FLOAT64_C(   725.25), SIMDE_FLOAT64_C(  -848.58) },
      SIMDE_FLOAT64_C(   725.25) },
    { { SIMDE_FLOAT64_C(   517.36), SIMDE_FLOAT64_C(   383.96) },
      SIMDE_FLOAT64_C(   517.36) },
    { { SIMDE_FLOAT64_C(    48.75), SIMDE_FLOAT64_C(  -826.68) },
      SIMDE_FLOAT64_C(    48.75) },
    { { SIMDE_FLOAT64_C(  -707.59), SIMDE_FLOAT64_C(   436.01) },
      SIMDE_FLOAT64_C(   436.01) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vmaxvq_f64(a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64_t r = simde_vmaxvq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxvq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r;
  } test_vec[] = {
    { { -INT8_C(  96),  INT8_C(  85), -INT8_C(   7),  INT8_C( 119),  INT8_C(  72), -INT8_C(  60),  INT8_C(  40),  INT8_C(  39),
         INT8_C(  24),  INT8_C(  39),  INT8_C( 122), -INT8_C(  38), -INT8_C(  77),  INT8_C(   8), -INT8_C(  46),  INT8_C(  49) },
       INT8_C( 122) },
    { {  INT8_C(  11),  INT8_C(  12),  INT8_C( 101), -INT8_C(  87), -INT8_C( 111), -INT8_C(  79), -INT8_C( 105),  INT8_C(  78),
        -INT8_C(  22), -INT8_C(  44), -INT8_C(  86),  INT8_C( 110),  INT8_C( 119), -INT8_C(  72), -INT8_C(  22),  INT8_C(  23) },
       INT8_C( 119) },
    { {  INT8_C(  13), -INT8_C(  29), -INT8_C( 114),  INT8_C(  85), -INT8_C(  88), -INT8_C(  74),  INT8_C( 125), -INT8_C(  64),
        -INT8_C(  35), -INT8_C(   9), -INT8_C( 102), -INT8_C( 111), -INT8_C(   1),  INT8_C( 108), -INT8_C(  62),  INT8_C(  11) },
       INT8_C( 125) },
    { {  INT8_C( 121),  INT8_C(  39), -INT8_C(  76),  INT8_C(  10), -INT8_C(  40),  INT8_C(  75),  INT8_C(  89), -INT8_C(  62),
         INT8_C(  32),  INT8_C(   3),  INT8_C(  49), -INT8_C( 105), -INT8_C(  69),  INT8_C(  27), -INT8_C(  82), -INT8_C(  55) },
       INT8_C( 121) },
    { { -INT8_C(   2),  INT8_C(  60),  INT8_C(  30), -INT8_C(  90), -INT8_C(  13), -INT8_C( 101),  INT8_C( 102), -INT8_C(  48),
        -INT8_C( 109),  INT8_C(   0),  INT8_C(  97), -INT8_C( 110),  INT8_C( 109),  INT8_C(  35), -INT8_C(  99), -INT8_C(  26) },
       INT8_C( 109) },
    { {  INT8_C(  75),  INT8_C(  82), -INT8_C(  16),  INT8_C(  35), -INT8_C(  99),  INT8_C(  73), -INT8_C(  26), -INT8_C(  67),
         INT8_C(  76),  INT8_C(  23),  INT8_C(  84),  INT8_C(   8),  INT8_C(  50),  INT8_C(   2), -INT8_C(  47),  INT8_C(  48) },
       INT8_C(  84) },
    { {  INT8_C(  63), -INT8_C(  17), -INT8_C(  41),  INT8_C(  50), -INT8_C( 117),  INT8_C(  61),  INT8_C(   2),  INT8_C(  30),
         INT8_C(  62),  INT8_C( 100), -INT8_C(  80), -INT8_C(  85), -INT8_C( 121),  INT8_C(  78), -INT8_C( 111), -INT8_C(  46) },
       INT8_C( 100) },
    { { -INT8_C(  96), -INT8_C( 127), -INT8_C(  10),  INT8_C(  61), -INT8_C(  53), -INT8_C(  36), -INT8_C(   5),  INT8_C(  23),
        -INT8_C(  13),  INT8_C(  79),  INT8_C(  31),  INT8_C(  37),  INT8_C(  82), -INT8_C(  16),  INT8_C(  85), -INT8_C( 111) },
       INT8_C(  85) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    int8_t r = simde_vmaxvq_s8(a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    int8_t r = simde_vmaxvq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxvq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r;
  } test_vec[] = {
    { {  INT16_C( 11488),  INT16_C( 27587), -INT16_C( 14998), -INT16_C( 22391),  INT16_C( 14633), -INT16_C( 20141), -INT16_C(  7033),  INT16_C( 10115) },
       INT16_C( 27587) },
    { {  INT16_C( 31077),  INT16_C( 12389),  INT16_C( 24661),  INT16_C( 18504),  INT16_C( 26543),  INT16_C(   365), -INT16_C( 15528),  INT16_C( 14482) },
       INT16_C( 31077) },
    { {  INT16_C( 21999),  INT16_C( 22947),  INT16_C( 11291),  INT16_C( 17409),  INT16_C( 21605), -INT16_C(  4619),  INT16_C( 31032), -INT16_C( 25068) },
       INT16_C( 31032) },
    { {  INT16_C( 31218),  INT16_C( 18638),  INT16_C(  5849), -INT16_C( 30320), -INT16_C(   386), -INT16_C( 10614),  INT16_C(  7617), -INT16_C( 20466) },
       INT16_C( 31218) },
    { { -INT16_C( 20110), -INT16_C( 29430),  INT16_C(  3037),  INT16_C( 17106), -INT16_C( 14496), -INT16_C( 26577),  INT16_C( 17472),  INT16_C( 13110) },
       INT16_C( 17472) },
    { {  INT16_C(  1469), -INT16_C( 26757),  INT16_C(  2843), -INT16_C( 26336), -INT16_C( 22007), -INT16_C( 13713),  INT16_C( 32199),  INT16_C( 14971) },
       INT16_C( 32199) },
    { { -INT16_C( 31442),  INT16_C(  3015), -INT16_C( 26224), -INT16_C(  4018),  INT16_C( 32097), -INT16_C( 24183), -INT16_C( 16447),  INT16_C( 32724) },
       INT16_C( 32724) },
    { {  INT16_C( 20420), -INT16_C(  8170),  INT16_C( 13915),  INT16_C( 25721), -INT16_C(  5664), -INT16_C( 22481), -INT16_C( 21914), -INT16_C( 27166) },
       INT16_C( 25721) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t r = simde_vmaxvq_s16(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    int16_t r = simde_vmaxvq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxvq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r;
  } test_vec[] = {
    { { -INT32_C(  1079989969), -INT32_C(  1531908541),  INT32_C(   759511404), -INT32_C(  1112794376) },
       INT32_C(   759511404) },
    { { -INT32_C(   996294039), -INT32_C(   651618568),  INT32_C(  1719752959),  INT32_C(   838558466) },
       INT32_C(  1719752959) },
    { {  INT32_C(  1341168396), -INT32_C(   151805814), -INT32_C(   769443367), -INT32_C(  1131425709) },
       INT32_C(  1341168396) },
    { { -INT32_C(  1954468718),  INT32_C(  1113893442),  INT32_C(    78177538),  INT32_C(  1412801352) },
       INT32_C(  1412801352) },
    { { -INT32_C(   928766658), -INT32_C(  1614899258),  INT32_C(   594666192),  INT32_C(  1155530930) },
       INT32_C(  1155530930) },
    { {  INT32_C(  1875861804),  INT32_C(   229716747),  INT32_C(  1611749656),  INT32_C(   984958716) },
       INT32_C(  1875861804) },
    { {  INT32_C(   822303083), -INT32_C(  1043217936),  INT32_C(  1441022627),  INT32_C(  1872413763) },
       INT32_C(  1872413763) },
    { {  INT32_C(   819882277), -INT32_C(  1254256739), -INT32_C(   468300056),  INT32_C(     2083732) },
       INT32_C(   819882277) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t r = simde_vmaxvq_s32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    int32_t r = simde_vmaxvq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxvq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r;
  } test_vec[] = {
    { { UINT8_C( 36), UINT8_C( 34), UINT8_C( 49), UINT8_C( 20), UINT8_C(227), UINT8_C(  2), UINT8_C(213), UINT8_C(135),
        UINT8_C( 69), UINT8_C(186), UINT8_C(220), UINT8_C(136), UINT8_C(126), UINT8_C(118), UINT8_C(247), UINT8_C(164) },
      UINT8_C(247) },
    { { UINT8_C(224), UINT8_C(214), UINT8_C(212), UINT8_C(125), UINT8_C(101), UINT8_C( 18), UINT8_C( 50), UINT8_C( 78),
        UINT8_C( 96), UINT8_C( 72), UINT8_C( 50), UINT8_C(245), UINT8_C( 19), UINT8_C( 81), UINT8_C(245), UINT8_C( 55) },
      UINT8_C(245) },
    { { UINT8_C(115), UINT8_C( 38), UINT8_C( 76), UINT8_C( 87), UINT8_C( 41), UINT8_C( 33), UINT8_C(222), UINT8_C(110),
        UINT8_C(219), UINT8_C(186), UINT8_C(246), UINT8_C( 90), UINT8_C( 49), UINT8_C(237), UINT8_C(254), UINT8_C( 17) },
      UINT8_C(254) },
    { { UINT8_C(195), UINT8_C(210), UINT8_C(142), UINT8_C( 41), UINT8_C(228), UINT8_C(192), UINT8_C(119), UINT8_C( 69),
        UINT8_C(  9), UINT8_C(169), UINT8_C( 58), UINT8_C( 28), UINT8_C(251), UINT8_C( 47), UINT8_C( 84), UINT8_C(110) },
      UINT8_C(251) },
    { { UINT8_C( 85), UINT8_C(160), UINT8_C(197), UINT8_C(126), UINT8_C(193), UINT8_C(163), UINT8_C(236), UINT8_C(157),
        UINT8_C( 94), UINT8_C(226), UINT8_C(247), UINT8_C(143), UINT8_C(208), UINT8_C(245), UINT8_C(160), UINT8_C(147) },
      UINT8_C(247) },
    { { UINT8_C(199), UINT8_C( 46), UINT8_C(188), UINT8_C(172), UINT8_C(238), UINT8_C( 51), UINT8_C(241), UINT8_C(247),
        UINT8_C(221), UINT8_C( 43), UINT8_C( 20), UINT8_C(216), UINT8_C( 90), UINT8_C(104), UINT8_C( 70), UINT8_C(175) },
      UINT8_C(247) },
    { { UINT8_C(  8), UINT8_C( 12), UINT8_C( 46), UINT8_C(201), UINT8_C(175), UINT8_C( 26), UINT8_C(102), UINT8_C( 13),
        UINT8_C(253), UINT8_C( 93), UINT8_C(156), UINT8_C(205), UINT8_C( 82), UINT8_C( 60), UINT8_C( 96), UINT8_C( 26) },
      UINT8_C(253) },
    { { UINT8_C(106), UINT8_C( 29), UINT8_C(198), UINT8_C( 89), UINT8_C( 80), UINT8_C(183), UINT8_C( 80), UINT8_C( 45),
        UINT8_C(226), UINT8_C(100), UINT8_C(  5), UINT8_C( 60), UINT8_C(204), UINT8_C( 76), UINT8_C(235), UINT8_C(212) },
      UINT8_C(235) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    uint8_t r = simde_vmaxvq_u8(a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    uint8_t r = simde_vmaxvq_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxvq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r;
  } test_vec[] = {
    { { UINT16_C( 6488), UINT16_C( 1950), UINT16_C( 1076), UINT16_C(12565), UINT16_C(45410), UINT16_C(46334), UINT16_C(24302), UINT16_C(22734) },
      UINT16_C(46334) },
    { { UINT16_C(38011), UINT16_C(52401), UINT16_C(  587), UINT16_C(11769), UINT16_C(65382), UINT16_C(13161), UINT16_C(21835), UINT16_C(41735) },
      UINT16_C(65382) },
    { { UINT16_C(42350), UINT16_C(41642), UINT16_C(49066), UINT16_C( 3283), UINT16_C(53617), UINT16_C(24512), UINT16_C(36656), UINT16_C(43959) },
      UINT16_C(53617) },
    { { UINT16_C(26915), UINT16_C(28535), UINT16_C(29035), UINT16_C(53660), UINT16_C( 1648), UINT16_C(47876), UINT16_C( 3163), UINT16_C(51550) },
      UINT16_C(53660) },
    { { UINT16_C( 2225), UINT16_C(23404), UINT16_C(16328), UINT16_C(14695), UINT16_C(10257), UINT16_C(16792), UINT16_C(20407), UINT16_C(56044) },
      UINT16_C(56044) },
    { { UINT16_C(25784), UINT16_C( 9033), UINT16_C(59093), UINT16_C(17909), UINT16_C(63980), UINT16_C(18176), UINT16_C(24069), UINT16_C(46864) },
      UINT16_C(63980) },
    { { UINT16_C(31846), UINT16_C(11794), UINT16_C(31420), UINT16_C(52583), UINT16_C(65442), UINT16_C(22798), UINT16_C(64079), UINT16_C( 1843) },
      UINT16_C(65442) },
    { { UINT16_C(32094), UINT16_C(13099), UINT16_C( 8291), UINT16_C(20344), UINT16_C(30745), UINT16_C( 8086), UINT16_C(42710), UINT16_C(15830) },
      UINT16_C(42710) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    uint16_t r = simde_vmaxvq_u16(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    uint16_t r = simde_vmaxvq_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxvq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r;
  } test_vec[] = {
    { { UINT32_C(3748390947), UINT32_C(  78435170), UINT32_C( 559790802), UINT32_C( 321491380) },
      UINT32_C(3748390947) },
    { { UINT32_C(1900434446), UINT32_C(2378219380), UINT32_C( 246175287), UINT32_C( 525042428) },
      UINT32_C(2378219380) },
    { { UINT32_C(3456022123), UINT32_C(1557310089), UINT32_C( 427634532), UINT32_C(3459032768) },
      UINT32_C(3459032768) },
    { { UINT32_C(1849651962), UINT32_C(1778188081), UINT32_C(1383573589), UINT32_C(2524037675) },
      UINT32_C(2524037675) },
    { { UINT32_C(  40071288), UINT32_C(2136880410), UINT32_C( 630774629), UINT32_C(2096415874) },
      UINT32_C(2136880410) },
    { { UINT32_C(1760244534), UINT32_C(2295457587), UINT32_C(3134867599), UINT32_C(2186300426) },
      UINT32_C(3134867599) },
    { { UINT32_C(3599021244), UINT32_C(1314251497), UINT32_C(1081404862), UINT32_C(3904661681) },
      UINT32_C(3904661681) },
    { { UINT32_C(3461392283), UINT32_C( 509026702), UINT32_C(1943548265), UINT32_C( 972368253) },
      UINT32_C(3461392283) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint32_t r = simde_vmaxvq_u32(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    uint32_t r = simde_vmaxvq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxv_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxv_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxv_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxv_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxv_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxv_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxv_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmaxvq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxvq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxvq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxvq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxvq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxvq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxvq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxvq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
