#define SIMDE_TEST_ARM_NEON_INSN minv

#include "test-neon.h"
#include "../../../simde/arm/neon/minv.h"

static int
test_simde_vminv_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   534.24) },
                 SIMDE_MATH_NANF },
    { { SIMDE_FLOAT32_C(  -385.00),            SIMDE_MATH_NANF },
                 SIMDE_MATH_NANF },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF },
                 SIMDE_MATH_NANF },
    #endif
    { { SIMDE_FLOAT32_C(   453.38), SIMDE_FLOAT32_C(   453.38) },
      SIMDE_FLOAT32_C(   453.38) },
    { { SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(  -125.43) },
      SIMDE_FLOAT32_C(  -282.45) },
    { { SIMDE_FLOAT32_C(   -15.54), SIMDE_FLOAT32_C(  -221.82) },
      SIMDE_FLOAT32_C(  -221.82) },
    { { SIMDE_FLOAT32_C(  -502.94), SIMDE_FLOAT32_C(  -155.47) },
      SIMDE_FLOAT32_C(  -502.94) },
    { { SIMDE_FLOAT32_C(  -806.84), SIMDE_FLOAT32_C(   615.87) },
      SIMDE_FLOAT32_C(  -806.84) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vminv_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32_t values[8 * 1 * sizeof(simde_float32x2_t)];
  simde_test_arm_neon_random_f32x2_full(8, 1, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL | SIMDE_TEST_VEC_FLOAT_PAIR);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_extract_f32x2(i, 1, 0, values);
    simde_float32_t r = simde_vminv_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminv_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r;
  } test_vec[] = {
    { { -INT8_C(  61), -INT8_C( 120), -INT8_C( 117), -INT8_C(  49),  INT8_C(  83),  INT8_C(  68),  INT8_C(  67), -INT8_C(  74) },
      -INT8_C( 120) },
    { { -INT8_C(  45),  INT8_C(  42),  INT8_C(  86),  INT8_C(  69), -INT8_C(  15), -INT8_C(  70), -INT8_C(  75), -INT8_C(  48) },
      -INT8_C(  75) },
    { {  INT8_C( 101), -INT8_C( 113), -INT8_C(  30), -INT8_C(  58),  INT8_C( 115),  INT8_C(   6), -INT8_C(   6), -INT8_C(  54) },
      -INT8_C( 113) },
    { {  INT8_C( 121),  INT8_C( 121), -INT8_C( 119), -INT8_C(  59), -INT8_C(  44), -INT8_C( 105), -INT8_C(  56), -INT8_C( 105) },
      -INT8_C( 119) },
    { {  INT8_C(  31),  INT8_C(  83),  INT8_C( 102),  INT8_C( 114), -INT8_C( 105), -INT8_C(  87),  INT8_C(  40),  INT8_C( 107) },
      -INT8_C( 105) },
    { { -INT8_C(  45),      INT8_MAX, -INT8_C(  80), -INT8_C(  59),  INT8_C(  57),  INT8_C( 101), -INT8_C( 107), -INT8_C(  98) },
      -INT8_C( 107) },
    { { -INT8_C(  12),  INT8_C( 119),  INT8_C( 101),  INT8_C( 103),  INT8_C( 125),  INT8_C(  95),  INT8_C(  49), -INT8_C(  10) },
      -INT8_C(  12) },
    { { -INT8_C(  40), -INT8_C(  70), -INT8_C(  69), -INT8_C(  84),  INT8_C(  81), -INT8_C( 125),  INT8_C(  67),  INT8_C( 112) },
      -INT8_C( 125) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    int8_t r = simde_vminv_s8(a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    int8_t r = simde_vminv_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminv_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r;
  } test_vec[] = {
    { { -INT16_C( 22057),  INT16_C( 28386),  INT16_C(  2899),  INT16_C(  9945) },
      -INT16_C( 22057) },
    { { -INT16_C( 30326), -INT16_C( 15381), -INT16_C( 32530), -INT16_C(  7327) },
      -INT16_C( 32530) },
    { { -INT16_C( 14601),  INT16_C( 30026),  INT16_C( 31781), -INT16_C(   661) },
      -INT16_C( 14601) },
    { {  INT16_C( 10038), -INT16_C( 30551), -INT16_C(  4950), -INT16_C( 32264) },
      -INT16_C( 32264) },
    { { -INT16_C(  9322), -INT16_C(  5648), -INT16_C( 13850),  INT16_C( 28687) },
      -INT16_C( 13850) },
    { { -INT16_C(  1197),  INT16_C( 16691), -INT16_C( 27525),  INT16_C( 29476) },
      -INT16_C( 27525) },
    { {  INT16_C( 28507), -INT16_C( 32536),  INT16_C( 21483),  INT16_C(  8574) },
      -INT16_C( 32536) },
    { {  INT16_C( 10106),  INT16_C(  9641), -INT16_C( 24044), -INT16_C( 21850) },
      -INT16_C( 24044) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int16_t r = simde_vminv_s16(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    int16_t r = simde_vminv_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminv_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r;
  } test_vec[] = {
    { {  INT32_C(  1670616701), -INT32_C(  1277975968) },
      -INT32_C(  1277975968) },
    { {  INT32_C(   435422877), -INT32_C(   175367782) },
      -INT32_C(   175367782) },
    { {  INT32_C(  1937142920),  INT32_C(  1117058247) },
       INT32_C(  1117058247) },
    { {  INT32_C(   795295259),  INT32_C(  1574505952) },
       INT32_C(   795295259) },
    { {  INT32_C(    79719588), -INT32_C(  1397255409) },
      -INT32_C(  1397255409) },
    { {  INT32_C(   868592537),  INT32_C(  1277776324) },
       INT32_C(   868592537) },
    { { -INT32_C(  1916821563), -INT32_C(  1362144109) },
      -INT32_C(  1916821563) },
    { {  INT32_C(  1927165586), -INT32_C(   405817533) },
      -INT32_C(   405817533) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int32_t r = simde_vminv_s32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    int32_t r = simde_vminv_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminv_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t r;
  } test_vec[] = {
    { { UINT8_C(134), UINT8_C( 85), UINT8_C( 72), UINT8_C(183), UINT8_C(145), UINT8_C(178), UINT8_C( 35), UINT8_C( 42) },
      UINT8_C( 35) },
    { { UINT8_C(142), UINT8_C(244), UINT8_C(166), UINT8_C(237), UINT8_C( 33), UINT8_C(229), UINT8_C(169), UINT8_C( 85) },
      UINT8_C( 33) },
    { { UINT8_C(239), UINT8_C( 28), UINT8_C(117), UINT8_C(120), UINT8_C(247), UINT8_C(132), UINT8_C( 35), UINT8_C(222) },
      UINT8_C( 28) },
    { { UINT8_C(222), UINT8_C( 36), UINT8_C( 57), UINT8_C(238), UINT8_C(241), UINT8_C( 64), UINT8_C(  3), UINT8_C(119) },
      UINT8_C(  3) },
    { { UINT8_C(149), UINT8_C( 76), UINT8_C( 46), UINT8_C( 38), UINT8_C(254), UINT8_C( 81), UINT8_C( 80), UINT8_C(141) },
      UINT8_C( 38) },
    { { UINT8_C( 70), UINT8_C(246), UINT8_C(122), UINT8_C(103), UINT8_C(219), UINT8_C( 36), UINT8_C(188), UINT8_C(202) },
      UINT8_C( 36) },
    { { UINT8_C( 64), UINT8_C( 49), UINT8_C( 66), UINT8_C( 55), UINT8_C(181), UINT8_C(101), UINT8_C( 22), UINT8_C(148) },
      UINT8_C( 22) },
    { { UINT8_C(138), UINT8_C( 79), UINT8_C(130), UINT8_C(123), UINT8_C(143), UINT8_C(133), UINT8_C(242), UINT8_C( 36) },
      UINT8_C( 36) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    uint8_t r = simde_vminv_u8(a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    uint8_t r = simde_vminv_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminv_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t r;
  } test_vec[] = {
    { { UINT16_C( 8401), UINT16_C(53322), UINT16_C(39537), UINT16_C(46941) },
      UINT16_C( 8401) },
    { { UINT16_C(55184), UINT16_C(27422), UINT16_C(56059), UINT16_C(15158) },
      UINT16_C(15158) },
    { { UINT16_C(30731), UINT16_C(49523), UINT16_C(35294), UINT16_C(26709) },
      UINT16_C(26709) },
    { { UINT16_C(55256), UINT16_C(26851), UINT16_C(54620), UINT16_C(11916) },
      UINT16_C(11916) },
    { { UINT16_C(55285), UINT16_C(26366), UINT16_C(23409), UINT16_C(  542) },
      UINT16_C(  542) },
    { { UINT16_C(15410), UINT16_C(11885), UINT16_C(41751), UINT16_C( 8809) },
      UINT16_C( 8809) },
    { { UINT16_C(56348), UINT16_C(64227), UINT16_C(14437), UINT16_C(15970) },
      UINT16_C(14437) },
    { { UINT16_C(17679), UINT16_C(27814), UINT16_C(12826), UINT16_C( 3994) },
      UINT16_C( 3994) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    uint16_t r = simde_vminv_u16(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    uint16_t r = simde_vminv_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminv_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r;
  } test_vec[] = {
    { { UINT32_C(2071304201), UINT32_C( 628986867) },
      UINT32_C( 628986867) },
    { { UINT32_C(3881036496), UINT32_C(2852765070) },
      UINT32_C(2852765070) },
    { { UINT32_C(4288998809), UINT32_C( 893191717) },
      UINT32_C( 893191717) },
    { { UINT32_C(1705108299), UINT32_C( 527710997) },
      UINT32_C( 527710997) },
    { { UINT32_C(3332041171), UINT32_C(1307252605) },
      UINT32_C(1307252605) },
    { { UINT32_C(2402565889), UINT32_C(2503556604) },
      UINT32_C(2402565889) },
    { { UINT32_C(1351933226), UINT32_C( 780521955) },
      UINT32_C( 780521955) },
    { { UINT32_C(3398641332), UINT32_C( 887687009) },
      UINT32_C( 887687009) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    uint32_t r = simde_vminv_u32(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    uint32_t r = simde_vminv_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminvq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -701.57), SIMDE_FLOAT32_C(   406.22),            SIMDE_MATH_NANF },
                 SIMDE_MATH_NANF },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -103.16), SIMDE_FLOAT32_C(  -103.16) },
                 SIMDE_MATH_NANF },
    #endif
    { { SIMDE_FLOAT32_C(   696.89), SIMDE_FLOAT32_C(  -458.92), SIMDE_FLOAT32_C(   883.35), SIMDE_FLOAT32_C(   910.86) },
      SIMDE_FLOAT32_C(  -458.92) },
    { { SIMDE_FLOAT32_C(   257.45), SIMDE_FLOAT32_C(   520.20), SIMDE_FLOAT32_C(  -905.06), SIMDE_FLOAT32_C(  -593.51) },
      SIMDE_FLOAT32_C(  -905.06) },
    { { SIMDE_FLOAT32_C(  -269.91), SIMDE_FLOAT32_C(  -858.01), SIMDE_FLOAT32_C(   -48.94), SIMDE_FLOAT32_C(  -616.54) },
      SIMDE_FLOAT32_C(  -858.01) },
    { { SIMDE_FLOAT32_C(   719.99), SIMDE_FLOAT32_C(  -168.74), SIMDE_FLOAT32_C(   719.60), SIMDE_FLOAT32_C(  -623.28) },
      SIMDE_FLOAT32_C(  -623.28) },
    { { SIMDE_FLOAT32_C(   759.29), SIMDE_FLOAT32_C(   309.98), SIMDE_FLOAT32_C(    52.00), SIMDE_FLOAT32_C(   647.84) },
      SIMDE_FLOAT32_C(    52.00) },
    { { SIMDE_FLOAT32_C(   117.95), SIMDE_FLOAT32_C(  -401.59), SIMDE_FLOAT32_C(   805.20), SIMDE_FLOAT32_C(   531.01) },
      SIMDE_FLOAT32_C(  -401.59) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32_t r = simde_vminvq_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32_t values[8 * 1 * sizeof(simde_float32x2_t)];
  simde_test_arm_neon_random_f32x4_full(8, 1, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL | SIMDE_TEST_VEC_FLOAT_PAIR);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_extract_f32x4(i, 1, 0, values);
    simde_float32_t r = simde_vminvq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminvq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[4];
    simde_float64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   916.26) },
                  SIMDE_MATH_NAN },
    { { SIMDE_FLOAT64_C(   280.88),             SIMDE_MATH_NAN },
                  SIMDE_MATH_NAN },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN },
                  SIMDE_MATH_NAN },
    #endif
    { { SIMDE_FLOAT64_C(  -759.17), SIMDE_FLOAT64_C(  -759.17) },
      SIMDE_FLOAT64_C(  -759.17) },
    { { SIMDE_FLOAT64_C(  -235.01), SIMDE_FLOAT64_C(   213.31) },
      SIMDE_FLOAT64_C(  -235.01) },
    { { SIMDE_FLOAT64_C(  -536.29), SIMDE_FLOAT64_C(  -137.31) },
      SIMDE_FLOAT64_C(  -536.29) },
    { { SIMDE_FLOAT64_C(  -353.98), SIMDE_FLOAT64_C(   948.71) },
      SIMDE_FLOAT64_C(  -353.98) },
    { { SIMDE_FLOAT64_C(   575.38), SIMDE_FLOAT64_C(  -153.95) },
      SIMDE_FLOAT64_C(  -153.95) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vminvq_f64(a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64_t values[8 * 1 * sizeof(simde_float64x2_t)];
  simde_test_arm_neon_random_f64x2_full(8, 1, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL | SIMDE_TEST_VEC_FLOAT_PAIR);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_extract_f64x2(i, 1, 0, values);
    simde_float64_t r = simde_vminvq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminvq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r;
  } test_vec[] = {
    { {  INT8_C(  12),  INT8_C(  34),  INT8_C(  51),  INT8_C(  40),  INT8_C(  78), -INT8_C( 121), -INT8_C(   8), -INT8_C(  96),
         INT8_C( 110), -INT8_C( 109),  INT8_C(  83),  INT8_C(  93),  INT8_C(  22),  INT8_C(  58),  INT8_C(  61),  INT8_C(  29) },
      -INT8_C( 121) },
    { {  INT8_C(  27), -INT8_C( 117), -INT8_C(  67), -INT8_C(  30), -INT8_C( 108), -INT8_C(   7), -INT8_C(  51), -INT8_C( 116),
         INT8_C(  96), -INT8_C(  40), -INT8_C(  79),  INT8_C(  44), -INT8_C( 102),  INT8_C(  44),  INT8_C(  57), -INT8_C(  90) },
      -INT8_C( 117) },
    { {  INT8_C(  79),  INT8_C( 108), -INT8_C(  50), -INT8_C(  99), -INT8_C(  13), -INT8_C(  58),  INT8_C(  62),  INT8_C(  98),
         INT8_C(  89), -INT8_C( 111), -INT8_C(  65),  INT8_C( 112), -INT8_C(  52), -INT8_C(   3), -INT8_C( 115), -INT8_C(  25) },
      -INT8_C( 115) },
    { { -INT8_C( 120),  INT8_C(  74), -INT8_C(  55),  INT8_C(  29),  INT8_C(  68), -INT8_C( 106), -INT8_C(  87), -INT8_C(  92),
         INT8_C( 111),  INT8_C(  90), -INT8_C(  48),  INT8_C(   9), -INT8_C( 121),  INT8_C(  10), -INT8_C(  81), -INT8_C(  42) },
      -INT8_C( 121) },
    { {  INT8_C( 118),  INT8_C( 125),  INT8_C( 115),  INT8_C( 106),  INT8_C(  67), -INT8_C(  79), -INT8_C(  52), -INT8_C(  99),
         INT8_C(  67), -INT8_C( 117),  INT8_C(  13),  INT8_C(  15), -INT8_C( 120), -INT8_C( 102), -INT8_C(  10),  INT8_C(  17) },
      -INT8_C( 120) },
    { { -INT8_C(  28), -INT8_C(  64),  INT8_C(  46),  INT8_C(  40),  INT8_C(  86), -INT8_C(  41), -INT8_C(  51), -INT8_C(  59),
         INT8_C(  50), -INT8_C(  99), -INT8_C(  50), -INT8_C(  71), -INT8_C(  89),  INT8_C( 125), -INT8_C( 113),  INT8_C(  30) },
      -INT8_C( 113) },
    { { -INT8_C(   6),  INT8_C(   2), -INT8_C( 120),  INT8_C(  62), -INT8_C(  76),  INT8_C(  84), -INT8_C(  37), -INT8_C(   9),
        -INT8_C(  33), -INT8_C(  24),  INT8_C(   6),  INT8_C( 104), -INT8_C( 126), -INT8_C(   4),  INT8_C( 121),  INT8_C( 102) },
      -INT8_C( 126) },
    { { -INT8_C(  68), -INT8_C(  89), -INT8_C( 113),  INT8_C(  19),  INT8_C( 126),  INT8_C(  92), -INT8_C(  40), -INT8_C(  80),
        -INT8_C(   7), -INT8_C(  89),  INT8_C( 105), -INT8_C(  95),  INT8_C(  36), -INT8_C(   8), -INT8_C(  65),  INT8_C(  31) },
      -INT8_C( 113) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    int8_t r = simde_vminvq_s8(a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    int8_t r = simde_vminvq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminvq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r;
  } test_vec[] = {
    { {  INT16_C( 18427), -INT16_C( 20643),  INT16_C( 14491),  INT16_C( 31398), -INT16_C( 21472), -INT16_C( 23838),  INT16_C( 23464),  INT16_C( 25864) },
      -INT16_C( 23838) },
    { { -INT16_C( 26878), -INT16_C( 32392),  INT16_C( 20723), -INT16_C(  4815), -INT16_C( 25609),  INT16_C(  7310),  INT16_C( 19859), -INT16_C( 29125) },
      -INT16_C( 32392) },
    { { -INT16_C( 26476),  INT16_C( 12093), -INT16_C(  7216), -INT16_C(  3927), -INT16_C( 29553),  INT16_C( 14482), -INT16_C( 25881), -INT16_C(  5475) },
      -INT16_C( 29553) },
    { {  INT16_C(  5426),  INT16_C(  9579), -INT16_C( 25499),  INT16_C( 23826), -INT16_C( 24521), -INT16_C( 13447), -INT16_C( 19219), -INT16_C( 32423) },
      -INT16_C( 32423) },
    { { -INT16_C( 26804),  INT16_C(  7344),  INT16_C( 23162),  INT16_C(  2572), -INT16_C( 24858), -INT16_C( 12990), -INT16_C(  8392),  INT16_C( 27319) },
      -INT16_C( 26804) },
    { {  INT16_C(  8948),  INT16_C( 22928), -INT16_C( 23873), -INT16_C(  2378),  INT16_C( 12099),  INT16_C( 12481),  INT16_C(  7139),  INT16_C( 12210) },
      -INT16_C( 23873) },
    { {  INT16_C( 25266),  INT16_C( 11339),  INT16_C( 22460), -INT16_C( 24010),  INT16_C( 30965),  INT16_C( 11888),  INT16_C( 10071),  INT16_C( 19352) },
      -INT16_C( 24010) },
    { {  INT16_C( 10314),  INT16_C(  2469),  INT16_C( 23499),  INT16_C(  3839), -INT16_C( 15989),  INT16_C( 28222), -INT16_C(  3876), -INT16_C( 29026) },
      -INT16_C( 29026) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t r = simde_vminvq_s16(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    int16_t r = simde_vminvq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminvq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r;
  } test_vec[] = {
    { {  INT32_C(   263907667),  INT32_C(   917696833), -INT32_C(  1050402199), -INT32_C(  1827865271) },
      -INT32_C(  1827865271) },
    { { -INT32_C(   258166491), -INT32_C(  1728144371),  INT32_C(   956710237), -INT32_C(  2134399955) },
      -INT32_C(  2134399955) },
    { { -INT32_C(   812613234), -INT32_C(   603635086), -INT32_C(  1382192540), -INT32_C(  1941853849) },
      -INT32_C(  1941853849) },
    { {  INT32_C(  1753079131), -INT32_C(   704611463), -INT32_C(   435222856),  INT32_C(   963040939) },
      -INT32_C(   704611463) },
    { { -INT32_C(   905382312), -INT32_C(  1666839240), -INT32_C(   565558409),  INT32_C(  1215007725) },
      -INT32_C(  1666839240) },
    { { -INT32_C(   491722648),  INT32_C(   481865827),  INT32_C(  1627572406), -INT32_C(   157652834) },
      -INT32_C(   491722648) },
    { { -INT32_C(  1748917665),  INT32_C(   657745840), -INT32_C(  1744404821),  INT32_C(  1910534409) },
      -INT32_C(  1748917665) },
    { { -INT32_C(  1135374247), -INT32_C(   153613248),  INT32_C(  1918425812), -INT32_C(  1570115005) },
      -INT32_C(  1570115005) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t r = simde_vminvq_s32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    int32_t r = simde_vminvq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminvq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r;
  } test_vec[] = {
    { { UINT8_C(127), UINT8_C( 63), UINT8_C(172), UINT8_C( 73), UINT8_C(120), UINT8_C(238), UINT8_C( 41), UINT8_C(213),
        UINT8_C(108), UINT8_C( 80), UINT8_C( 33), UINT8_C(  3), UINT8_C(225), UINT8_C(  6), UINT8_C( 42), UINT8_C(209) },
      UINT8_C(  3) },
    { { UINT8_C(235), UINT8_C(134), UINT8_C(207), UINT8_C(198), UINT8_C(210), UINT8_C(234), UINT8_C(130), UINT8_C(179),
        UINT8_C(125), UINT8_C(148), UINT8_C( 50), UINT8_C(225), UINT8_C(137), UINT8_C(148), UINT8_C(106), UINT8_C(  8) },
      UINT8_C(  8) },
    { { UINT8_C(211), UINT8_C( 22), UINT8_C( 81), UINT8_C( 76), UINT8_C(  5), UINT8_C(123), UINT8_C( 33), UINT8_C(113),
        UINT8_C(203), UINT8_C( 67), UINT8_C(116), UINT8_C(172), UINT8_C( 73), UINT8_C(159), UINT8_C(126), UINT8_C( 52) },
      UINT8_C(  5) },
    { { UINT8_C( 37), UINT8_C( 77), UINT8_C(250), UINT8_C(248), UINT8_C( 55), UINT8_C(124), UINT8_C(171), UINT8_C(181),
        UINT8_C( 17), UINT8_C(221), UINT8_C(150), UINT8_C(154), UINT8_C(113), UINT8_C(  0), UINT8_C(162), UINT8_C( 69) },
      UINT8_C(  0) },
    { { UINT8_C( 23), UINT8_C(244), UINT8_C(145), UINT8_C( 28), UINT8_C(111), UINT8_C(178), UINT8_C(141), UINT8_C( 58),
        UINT8_C(245), UINT8_C(  2), UINT8_C(230), UINT8_C( 62), UINT8_C(161), UINT8_C(100), UINT8_C(114), UINT8_C(198) },
      UINT8_C(  2) },
    { { UINT8_C(177), UINT8_C(108), UINT8_C(190), UINT8_C(233), UINT8_C(233), UINT8_C(105), UINT8_C(158), UINT8_C(250),
        UINT8_C( 71), UINT8_C( 52), UINT8_C(148), UINT8_C(184), UINT8_C( 52), UINT8_C( 54), UINT8_C(253), UINT8_C( 75) },
      UINT8_C( 52) },
    { { UINT8_C( 42), UINT8_C(142), UINT8_C(103), UINT8_C(153), UINT8_C( 65), UINT8_C(245), UINT8_C(211), UINT8_C( 54),
        UINT8_C(247), UINT8_C(186), UINT8_C(117), UINT8_C(152), UINT8_C( 30), UINT8_C(231), UINT8_C( 94), UINT8_C(208) },
      UINT8_C( 30) },
    { { UINT8_C( 84), UINT8_C( 29), UINT8_C(185), UINT8_C( 61), UINT8_C(134), UINT8_C( 87), UINT8_C( 55), UINT8_C(205),
        UINT8_C(139), UINT8_C(203), UINT8_C(134), UINT8_C(191), UINT8_C(  1), UINT8_C(131), UINT8_C( 11), UINT8_C( 44) },
      UINT8_C(  1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    uint8_t r = simde_vminvq_u8(a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    uint8_t r = simde_vminvq_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminvq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r;
  } test_vec[] = {
    { { UINT16_C(26010), UINT16_C(25137), UINT16_C(63517), UINT16_C(43199), UINT16_C(42873), UINT16_C(20868), UINT16_C(59734), UINT16_C(35096) },
      UINT16_C(20868) },
    { { UINT16_C(14291), UINT16_C(55676), UINT16_C(15043), UINT16_C(49309), UINT16_C(14487), UINT16_C(49347), UINT16_C(11103), UINT16_C(63872) },
      UINT16_C(11103) },
    { { UINT16_C(45457), UINT16_C(44635), UINT16_C( 6826), UINT16_C( 9047), UINT16_C(56258), UINT16_C( 6260), UINT16_C(36036), UINT16_C(38817) },
      UINT16_C( 6260) },
    { { UINT16_C( 7619), UINT16_C(34416), UINT16_C( 3672), UINT16_C(61254), UINT16_C( 2374), UINT16_C(42415), UINT16_C(12340), UINT16_C(50590) },
      UINT16_C( 2374) },
    { { UINT16_C(64225), UINT16_C(35700), UINT16_C(51988), UINT16_C(54958), UINT16_C( 8870), UINT16_C(27630), UINT16_C(37038), UINT16_C(28930) },
      UINT16_C( 8870) },
    { { UINT16_C(29613), UINT16_C( 1527), UINT16_C(15745), UINT16_C(51189), UINT16_C(42054), UINT16_C(31596), UINT16_C( 2772), UINT16_C(46656) },
      UINT16_C( 1527) },
    { { UINT16_C(46084), UINT16_C( 6465), UINT16_C(61567), UINT16_C( 9967), UINT16_C(56850), UINT16_C(49553), UINT16_C(37742), UINT16_C( 6962) },
      UINT16_C( 6465) },
    { { UINT16_C(10758), UINT16_C(34593), UINT16_C( 5735), UINT16_C(44622), UINT16_C(47802), UINT16_C(36649), UINT16_C(27077), UINT16_C(51525) },
      UINT16_C( 5735) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    uint16_t r = simde_vminvq_u16(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    uint16_t r = simde_vminvq_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminvq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r;
  } test_vec[] = {
    { { UINT32_C(2648868382), UINT32_C(2311311990), UINT32_C( 508187824), UINT32_C(3996744936) },
      UINT32_C( 508187824) },
    { { UINT32_C( 242637478), UINT32_C( 733791344), UINT32_C(1153099135), UINT32_C(1812856654) },
      UINT32_C( 242637478) },
    { { UINT32_C(4228575365), UINT32_C(1921371586), UINT32_C( 177262370), UINT32_C(4076390731) },
      UINT32_C( 177262370) },
    { { UINT32_C(2483056164), UINT32_C(2998910003), UINT32_C(4025907617), UINT32_C(4267443064) },
      UINT32_C(2483056164) },
    { { UINT32_C(3053086451), UINT32_C(1428651827), UINT32_C(2573186894), UINT32_C(2777372801) },
      UINT32_C(1428651827) },
    { { UINT32_C(4181298118), UINT32_C(3903584583), UINT32_C(3956842866), UINT32_C(2565420197) },
      UINT32_C(2565420197) },
    { { UINT32_C(3444499354), UINT32_C(2955113826), UINT32_C(2924053037), UINT32_C(2706626010) },
      UINT32_C(2706626010) },
    { { UINT32_C(2828700768), UINT32_C(4170204805), UINT32_C(2363713767), UINT32_C( 908446876) },
      UINT32_C( 908446876) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint32_t r = simde_vminvq_u32(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    uint32_t r = simde_vminvq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vminv_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminv_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vminv_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminv_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminv_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vminv_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminv_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vminvq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminvq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vminvq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vminvq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminvq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminvq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vminvq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminvq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
