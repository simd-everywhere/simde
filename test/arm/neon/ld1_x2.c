#define SIMDE_TEST_ARM_NEON_INSN ld1_x2
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/ld1_x2.h"
#include "../../../simde/arm/neon/ld1_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld1_f32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 buf[4];
    simde_float32 expected[2][2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   197.09), SIMDE_FLOAT32_C(   617.56), SIMDE_FLOAT32_C(  -185.34), SIMDE_FLOAT32_C(   848.26) },
        { { SIMDE_FLOAT32_C(   197.09), SIMDE_FLOAT32_C(   617.56) },
          { SIMDE_FLOAT32_C(  -185.34), SIMDE_FLOAT32_C(   848.26) } },
    },
    { { SIMDE_FLOAT32_C(  -121.84), SIMDE_FLOAT32_C(  -881.47), SIMDE_FLOAT32_C(  -314.89), SIMDE_FLOAT32_C(  -745.82) },
        { { SIMDE_FLOAT32_C(  -121.84), SIMDE_FLOAT32_C(  -881.47) },
          { SIMDE_FLOAT32_C(  -314.89), SIMDE_FLOAT32_C(  -745.82) } },
    },
    { { SIMDE_FLOAT32_C(  -116.62), SIMDE_FLOAT32_C(  -241.19), SIMDE_FLOAT32_C(  -402.52), SIMDE_FLOAT32_C(  -544.47) },
        { { SIMDE_FLOAT32_C(  -116.62), SIMDE_FLOAT32_C(  -241.19) },
          { SIMDE_FLOAT32_C(  -402.52), SIMDE_FLOAT32_C(  -544.47) } },
    },
    { { SIMDE_FLOAT32_C(  -227.18), SIMDE_FLOAT32_C(  -931.95), SIMDE_FLOAT32_C(  -606.48), SIMDE_FLOAT32_C(   949.91) },
        { { SIMDE_FLOAT32_C(  -227.18), SIMDE_FLOAT32_C(  -931.95) },
          { SIMDE_FLOAT32_C(  -606.48), SIMDE_FLOAT32_C(   949.91) } },
    },
    { { SIMDE_FLOAT32_C(  -713.99), SIMDE_FLOAT32_C(   -67.97), SIMDE_FLOAT32_C(  -370.90), SIMDE_FLOAT32_C(   -89.96) },
        { { SIMDE_FLOAT32_C(  -713.99), SIMDE_FLOAT32_C(   -67.97) },
          { SIMDE_FLOAT32_C(  -370.90), SIMDE_FLOAT32_C(   -89.96) } },
    },
    { { SIMDE_FLOAT32_C(   748.69), SIMDE_FLOAT32_C(  -169.37), SIMDE_FLOAT32_C(   290.34), SIMDE_FLOAT32_C(     1.41) },
        { { SIMDE_FLOAT32_C(   748.69), SIMDE_FLOAT32_C(  -169.37) },
          { SIMDE_FLOAT32_C(   290.34), SIMDE_FLOAT32_C(     1.41) } },
    },
    { { SIMDE_FLOAT32_C(   548.32), SIMDE_FLOAT32_C(   741.32), SIMDE_FLOAT32_C(   278.03), SIMDE_FLOAT32_C(   214.47) },
        { { SIMDE_FLOAT32_C(   548.32), SIMDE_FLOAT32_C(   741.32) },
          { SIMDE_FLOAT32_C(   278.03), SIMDE_FLOAT32_C(   214.47) } },
    },
    { { SIMDE_FLOAT32_C(   492.29), SIMDE_FLOAT32_C(   177.54), SIMDE_FLOAT32_C(   327.71), SIMDE_FLOAT32_C(  -310.62) },
        { { SIMDE_FLOAT32_C(   492.29), SIMDE_FLOAT32_C(   177.54) },
          { SIMDE_FLOAT32_C(   327.71), SIMDE_FLOAT32_C(  -310.62) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2x2_t r = simde_vld1_f32_x2(test_vec[i].buf);
    simde_float32x2x2_t expected = {{
        simde_vld1_f32(test_vec[i].expected[0]),
        simde_vld1_f32(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_f32x2x2(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 buf[4];
    for (int j = 0 ; j < 4 ; j++) {
      buf[j] = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    }
    simde_test_codegen_write_vf32(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32x2x2_t val = simde_vld1_f32_x2(buf);
    simde_test_arm_neon_write_f32x2x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_f64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 buf[2];
    simde_float64 expected[2][1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   879.75), SIMDE_FLOAT64_C(   290.17) },
        { { SIMDE_FLOAT64_C(   879.75) },
          { SIMDE_FLOAT64_C(   290.17) } },
    },
    { { SIMDE_FLOAT64_C(    -4.96), SIMDE_FLOAT64_C(   145.64) },
        { { SIMDE_FLOAT64_C(    -4.96) },
          { SIMDE_FLOAT64_C(   145.64) } },
    },
    { { SIMDE_FLOAT64_C(   -66.16), SIMDE_FLOAT64_C(    41.21) },
        { { SIMDE_FLOAT64_C(   -66.16) },
          { SIMDE_FLOAT64_C(    41.21) } },
    },
    { { SIMDE_FLOAT64_C(   954.73), SIMDE_FLOAT64_C(  -300.26) },
        { { SIMDE_FLOAT64_C(   954.73) },
          { SIMDE_FLOAT64_C(  -300.26) } },
    },
    { { SIMDE_FLOAT64_C(  -913.71), SIMDE_FLOAT64_C(   233.26) },
        { { SIMDE_FLOAT64_C(  -913.71) },
          { SIMDE_FLOAT64_C(   233.26) } },
    },
    { { SIMDE_FLOAT64_C(  -156.20), SIMDE_FLOAT64_C(   112.89) },
        { { SIMDE_FLOAT64_C(  -156.20) },
          { SIMDE_FLOAT64_C(   112.89) } },
    },
    { { SIMDE_FLOAT64_C(  -163.99), SIMDE_FLOAT64_C(  -784.84) },
        { { SIMDE_FLOAT64_C(  -163.99) },
          { SIMDE_FLOAT64_C(  -784.84) } },
    },
    { { SIMDE_FLOAT64_C(   260.71), SIMDE_FLOAT64_C(   302.29) },
        { { SIMDE_FLOAT64_C(   260.71) },
          { SIMDE_FLOAT64_C(   302.29) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1x2_t r = simde_vld1_f64_x2(test_vec[i].buf);
    simde_float64x1x2_t expected = {{
        simde_vld1_f64(test_vec[i].expected[0]),
        simde_vld1_f64(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_f64x1x2(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 buf[2];
    for (int j = 0 ; j < 2 ; j++) {
      buf[j] = simde_test_codegen_random_f64(-1000.0, 1000.0);
    }
    simde_test_codegen_write_vf64(2, 2, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64x1x2_t val = simde_vld1_f64_x2(buf);
    simde_test_arm_neon_write_f64x1x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t buf[16];
    int8_t expected[2][8];
  } test_vec[] = {
    { { -INT8_C(  27), -INT8_C(  97),  INT8_C(  84),  INT8_C(  47),  INT8_C(  25),  INT8_C(  54), -INT8_C(  34), -INT8_C(  54),
        -INT8_C(  12),  INT8_C( 111),  INT8_C( 102), -INT8_C(  37), -INT8_C(  81), -INT8_C(  81),  INT8_C(  38),  INT8_C( 124) },
        { { -INT8_C(  27), -INT8_C(  97),  INT8_C(  84),  INT8_C(  47),  INT8_C(  25),  INT8_C(  54), -INT8_C(  34), -INT8_C(  54) },
          { -INT8_C(  12),  INT8_C( 111),  INT8_C( 102), -INT8_C(  37), -INT8_C(  81), -INT8_C(  81),  INT8_C(  38),  INT8_C( 124) } },
    },
    { { -INT8_C(  49), -INT8_C( 126), -INT8_C(  57),  INT8_C(  53),  INT8_C(  36), -INT8_C(  34),  INT8_C(  82), -INT8_C( 107),
        -INT8_C(  75),  INT8_C(   6),  INT8_C(  51), -INT8_C(  21), -INT8_C(  51),  INT8_C( 110),  INT8_C( 126), -INT8_C(  78) },
        { { -INT8_C(  49), -INT8_C( 126), -INT8_C(  57),  INT8_C(  53),  INT8_C(  36), -INT8_C(  34),  INT8_C(  82), -INT8_C( 107) },
          { -INT8_C(  75),  INT8_C(   6),  INT8_C(  51), -INT8_C(  21), -INT8_C(  51),  INT8_C( 110),  INT8_C( 126), -INT8_C(  78) } },
    },
    { {  INT8_C(  13), -INT8_C(  45), -INT8_C(  30),  INT8_C(  38),  INT8_C(   9), -INT8_C(  64), -INT8_C(  16), -INT8_C(   2),
         INT8_C(  47),  INT8_C(  87), -INT8_C(  39), -INT8_C(  34),  INT8_C(   6), -INT8_C(   1),  INT8_C(  91), -INT8_C(  43) },
        { {  INT8_C(  13), -INT8_C(  45), -INT8_C(  30),  INT8_C(  38),  INT8_C(   9), -INT8_C(  64), -INT8_C(  16), -INT8_C(   2) },
          {  INT8_C(  47),  INT8_C(  87), -INT8_C(  39), -INT8_C(  34),  INT8_C(   6), -INT8_C(   1),  INT8_C(  91), -INT8_C(  43) } },
    },
    { { -INT8_C( 126),  INT8_C(  34),  INT8_C(  10), -INT8_C(  90),  INT8_C(   0),  INT8_C(  93),  INT8_C(  59), -INT8_C(  75),
         INT8_C(  99),  INT8_C( 110), -INT8_C(  96),  INT8_C(  48), -INT8_C(  36),  INT8_C(  31), -INT8_C(  29), -INT8_C(  23) },
        { { -INT8_C( 126),  INT8_C(  34),  INT8_C(  10), -INT8_C(  90),  INT8_C(   0),  INT8_C(  93),  INT8_C(  59), -INT8_C(  75) },
          {  INT8_C(  99),  INT8_C( 110), -INT8_C(  96),  INT8_C(  48), -INT8_C(  36),  INT8_C(  31), -INT8_C(  29), -INT8_C(  23) } },
    },
    { { -INT8_C(  14), -INT8_C(  59),  INT8_C(  16), -INT8_C(   5), -INT8_C( 123),  INT8_C(   0), -INT8_C(   7), -INT8_C(  76),
         INT8_C(  87), -INT8_C(  45), -INT8_C( 109),  INT8_C(  93), -INT8_C(  46), -INT8_C(  18),  INT8_C(  51),  INT8_C(  84) },
        { { -INT8_C(  14), -INT8_C(  59),  INT8_C(  16), -INT8_C(   5), -INT8_C( 123),  INT8_C(   0), -INT8_C(   7), -INT8_C(  76) },
          {  INT8_C(  87), -INT8_C(  45), -INT8_C( 109),  INT8_C(  93), -INT8_C(  46), -INT8_C(  18),  INT8_C(  51),  INT8_C(  84) } },
    },
    { {  INT8_C(  16),  INT8_C(  61), -INT8_C(   5),  INT8_C(  16), -INT8_C( 102),  INT8_C(  54), -INT8_C(  59), -INT8_C(   3),
        -INT8_C(  91),  INT8_C( 102),  INT8_C(  46), -INT8_C( 127), -INT8_C( 123),  INT8_C(  17),  INT8_C( 107),  INT8_C( 119) },
        { {  INT8_C(  16),  INT8_C(  61), -INT8_C(   5),  INT8_C(  16), -INT8_C( 102),  INT8_C(  54), -INT8_C(  59), -INT8_C(   3) },
          { -INT8_C(  91),  INT8_C( 102),  INT8_C(  46), -INT8_C( 127), -INT8_C( 123),  INT8_C(  17),  INT8_C( 107),  INT8_C( 119) } },
    },
    { { -INT8_C(  42),  INT8_C( 123),  INT8_C( 114),  INT8_C(  91),  INT8_C( 123),  INT8_C( 108),  INT8_C(  15), -INT8_C(  45),
         INT8_C(  63), -INT8_C(  94),  INT8_C(  48),  INT8_C(  17), -INT8_C( 112),  INT8_C(  99),  INT8_C( 102), -INT8_C(  96) },
        { { -INT8_C(  42),  INT8_C( 123),  INT8_C( 114),  INT8_C(  91),  INT8_C( 123),  INT8_C( 108),  INT8_C(  15), -INT8_C(  45) },
          {  INT8_C(  63), -INT8_C(  94),  INT8_C(  48),  INT8_C(  17), -INT8_C( 112),  INT8_C(  99),  INT8_C( 102), -INT8_C(  96) } },
    },
    { { -INT8_C(  95),  INT8_C(  97), -INT8_C(  80),  INT8_C(  59), -INT8_C( 105),  INT8_C( 118),  INT8_C(  57),  INT8_C(  60),
        -INT8_C(  36),  INT8_C( 103), -INT8_C(  66),  INT8_C(  97),  INT8_C( 120),  INT8_C(  41), -INT8_C(  40),  INT8_C(  78) },
        { { -INT8_C(  95),  INT8_C(  97), -INT8_C(  80),  INT8_C(  59), -INT8_C( 105),  INT8_C( 118),  INT8_C(  57),  INT8_C(  60) },
          { -INT8_C(  36),  INT8_C( 103), -INT8_C(  66),  INT8_C(  97),  INT8_C( 120),  INT8_C(  41), -INT8_C(  40),  INT8_C(  78) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8x2_t r = simde_vld1_s8_x2(test_vec[i].buf);
    simde_int8x8x2_t expected = {{
        simde_vld1_s8(test_vec[i].expected[0]),
        simde_vld1_s8(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_i8x8x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int8_t buf[16];
    simde_test_codegen_random_memory(16, (uint8_t*)buf);
    simde_test_codegen_write_vi8(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int8x8x2_t val = simde_vld1_s8_x2(buf);
    simde_test_arm_neon_write_i8x8x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t buf[8];
    int16_t expected[2][4];
  } test_vec[] = {
    { { -INT16_C( 27549), -INT16_C( 32256), -INT16_C(  5795),  INT16_C( 29015), -INT16_C(  8651), -INT16_C(  5523), -INT16_C(  3639),  INT16_C( 23998) },
        { { -INT16_C( 27549), -INT16_C( 32256), -INT16_C(  5795),  INT16_C( 29015) },
          { -INT16_C(  8651), -INT16_C(  5523), -INT16_C(  3639),  INT16_C( 23998) } },
    },
    { {  INT16_C( 11224),  INT16_C( 30567),  INT16_C( 23963),  INT16_C( 31362),  INT16_C( 13192),  INT16_C(  4122), -INT16_C( 31086), -INT16_C(  2677) },
        { {  INT16_C( 11224),  INT16_C( 30567),  INT16_C( 23963),  INT16_C( 31362) },
          {  INT16_C( 13192),  INT16_C(  4122), -INT16_C( 31086), -INT16_C(  2677) } },
    },
    { { -INT16_C( 29926),  INT16_C( 30583), -INT16_C( 12684), -INT16_C( 22040),  INT16_C( 22188),  INT16_C( 30356),  INT16_C( 21063),  INT16_C(  8147) },
        { { -INT16_C( 29926),  INT16_C( 30583), -INT16_C( 12684), -INT16_C( 22040) },
          {  INT16_C( 22188),  INT16_C( 30356),  INT16_C( 21063),  INT16_C(  8147) } },
    },
    { {  INT16_C( 15229),  INT16_C(  6294),  INT16_C(  6296),  INT16_C(  8594), -INT16_C( 21429), -INT16_C(  8911), -INT16_C( 17357),  INT16_C( 19922) },
        { {  INT16_C( 15229),  INT16_C(  6294),  INT16_C(  6296),  INT16_C(  8594) },
          { -INT16_C( 21429), -INT16_C(  8911), -INT16_C( 17357),  INT16_C( 19922) } },
    },
    { {  INT16_C( 18759), -INT16_C( 17467), -INT16_C( 21225), -INT16_C( 15259), -INT16_C(  1789),  INT16_C( 19002),  INT16_C(  3403), -INT16_C( 14231) },
        { {  INT16_C( 18759), -INT16_C( 17467), -INT16_C( 21225), -INT16_C( 15259) },
          { -INT16_C(  1789),  INT16_C( 19002),  INT16_C(  3403), -INT16_C( 14231) } },
    },
    { {  INT16_C(    72), -INT16_C(  7711),  INT16_C( 29464),  INT16_C( 25602),  INT16_C( 13088),  INT16_C( 21313),  INT16_C(  5359),  INT16_C( 13984) },
        { {  INT16_C(    72), -INT16_C(  7711),  INT16_C( 29464),  INT16_C( 25602) },
          {  INT16_C( 13088),  INT16_C( 21313),  INT16_C(  5359),  INT16_C( 13984) } },
    },
    { {  INT16_C( 25949),  INT16_C( 30193),  INT16_C( 22035),  INT16_C(  5689),  INT16_C( 29519), -INT16_C( 26015), -INT16_C( 13696), -INT16_C( 13981) },
        { {  INT16_C( 25949),  INT16_C( 30193),  INT16_C( 22035),  INT16_C(  5689) },
          {  INT16_C( 29519), -INT16_C( 26015), -INT16_C( 13696), -INT16_C( 13981) } },
    },
    { {  INT16_C( 17610), -INT16_C(  7254), -INT16_C( 21321), -INT16_C( 10425), -INT16_C( 30497), -INT16_C( 12758), -INT16_C( 13412), -INT16_C(  1532) },
        { {  INT16_C( 17610), -INT16_C(  7254), -INT16_C( 21321), -INT16_C( 10425) },
          { -INT16_C( 30497), -INT16_C( 12758), -INT16_C( 13412), -INT16_C(  1532) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4x2_t r = simde_vld1_s16_x2(test_vec[i].buf);
    simde_int16x4x2_t expected = {{
        simde_vld1_s16(test_vec[i].expected[0]),
        simde_vld1_s16(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_i16x4x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int16_t buf[8];
    simde_test_codegen_random_memory(16, (uint8_t*)buf);
    simde_test_codegen_write_vi16(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int16x4x2_t val = simde_vld1_s16_x2(buf);
    simde_test_arm_neon_write_i16x4x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t buf[4];
    int32_t expected[2][2];
  } test_vec[] = {
    { {  INT32_C(  1131410736), -INT32_C(  1688557492), -INT32_C(  1690911973),  INT32_C(  1348770181) },
        { {  INT32_C(  1131410736), -INT32_C(  1688557492) },
          { -INT32_C(  1690911973),  INT32_C(  1348770181) } },
    },
    { { -INT32_C(  1808593187), -INT32_C(  1720943942), -INT32_C(  1620601342), -INT32_C(  1835439263) },
        { { -INT32_C(  1808593187), -INT32_C(  1720943942) },
          { -INT32_C(  1620601342), -INT32_C(  1835439263) } },
    },
    { { -INT32_C(  1378547615), -INT32_C(   884461648),  INT32_C(  1885765354), -INT32_C(   188691689) },
        { { -INT32_C(  1378547615), -INT32_C(   884461648) },
          {  INT32_C(  1885765354), -INT32_C(   188691689) } },
    },
    { { -INT32_C(  1802898471),  INT32_C(  1865282925), -INT32_C(   317811317),  INT32_C(  1635755776) },
        { { -INT32_C(  1802898471),  INT32_C(  1865282925) },
          { -INT32_C(   317811317),  INT32_C(  1635755776) } },
    },
    { {  INT32_C(  1594774703),  INT32_C(  1848268676), -INT32_C(   304180779),  INT32_C(   903978588) },
        { {  INT32_C(  1594774703),  INT32_C(  1848268676) },
          { -INT32_C(   304180779),  INT32_C(   903978588) } },
    },
    { { -INT32_C(    20354415), -INT32_C(   345049249), -INT32_C(  1931969396), -INT32_C(   739354844) },
        { { -INT32_C(    20354415), -INT32_C(   345049249) },
          { -INT32_C(  1931969396), -INT32_C(   739354844) } },
    },
    { {  INT32_C(   791936171),  INT32_C(   698244435),  INT32_C(  1242987758), -INT32_C(  1400834277) },
        { {  INT32_C(   791936171),  INT32_C(   698244435) },
          {  INT32_C(  1242987758), -INT32_C(  1400834277) } },
    },
    { { -INT32_C(  1045739166), -INT32_C(   861136576), -INT32_C(  1185315691), -INT32_C(  2020784165) },
        { { -INT32_C(  1045739166), -INT32_C(   861136576) },
          { -INT32_C(  1185315691), -INT32_C(  2020784165) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2x2_t r = simde_vld1_s32_x2(test_vec[i].buf);
    simde_int32x2x2_t expected = {{
        simde_vld1_s32(test_vec[i].expected[0]),
        simde_vld1_s32(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_i32x2x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t buf[4];
    simde_test_codegen_random_memory(16, (uint8_t*)buf);
    simde_test_codegen_write_vi32(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int32x2x2_t val = simde_vld1_s32_x2(buf);
    simde_test_arm_neon_write_i32x2x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t buf[2];
    int64_t expected[2][1];
  } test_vec[] = {
    { {  INT64_C(  918826810059702339),  INT64_C( 3429727296164386513) },
        { {  INT64_C(  918826810059702339) },
          {  INT64_C( 3429727296164386513) } },
    },
    { { -INT64_C(  995966922490035424),  INT64_C( 1190138658907981346) },
        { { -INT64_C(  995966922490035424) },
          {  INT64_C( 1190138658907981346) } },
    },
    { {  INT64_C( 6927213041107287032),  INT64_C( 8014970614513956925) },
        { {  INT64_C( 6927213041107287032) },
          {  INT64_C( 8014970614513956925) } },
    },
    { { -INT64_C( 1479436010104345816),  INT64_C( 6007922141862306434) },
        { { -INT64_C( 1479436010104345816) },
          {  INT64_C( 6007922141862306434) } },
    },
    { { -INT64_C( 6009900392938666072), -INT64_C(  953933224542215164) },
        { { -INT64_C( 6009900392938666072) },
          { -INT64_C(  953933224542215164) } },
    },
    { {  INT64_C( 1212012072258736413), -INT64_C( 3476849111768974832) },
        { {  INT64_C( 1212012072258736413) },
          { -INT64_C( 3476849111768974832) } },
    },
    { { -INT64_C( 5124077454179817273), -INT64_C( 6179275636250797437) },
        { { -INT64_C( 5124077454179817273) },
          { -INT64_C( 6179275636250797437) } },
    },
    { { -INT64_C( 5405055521586629282), -INT64_C( 2012301866219643620) },
        { { -INT64_C( 5405055521586629282) },
          { -INT64_C( 2012301866219643620) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1x2_t r = simde_vld1_s64_x2(test_vec[i].buf);
    simde_int64x1x2_t expected = {{
        simde_vld1_s64(test_vec[i].expected[0]),
        simde_vld1_s64(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_i64x1x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t buf[2];
    simde_test_codegen_random_memory(16, (uint8_t*)buf);
    simde_test_codegen_write_vi64(2, 2, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int64x1x2_t val = simde_vld1_s64_x2(buf);
    simde_test_arm_neon_write_i64x1x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t buf[16];
    uint8_t expected[2][8];
  } test_vec[] = {
    { { UINT8_C(  5), UINT8_C(165), UINT8_C(134), UINT8_C( 59), UINT8_C(165), UINT8_C( 58), UINT8_C( 85), UINT8_C(119),
        UINT8_C(193), UINT8_C( 47), UINT8_C(192), UINT8_C(188), UINT8_C(253), UINT8_C( 56), UINT8_C( 74), UINT8_C(100) },
        { { UINT8_C(  5), UINT8_C(165), UINT8_C(134), UINT8_C( 59), UINT8_C(165), UINT8_C( 58), UINT8_C( 85), UINT8_C(119) },
          { UINT8_C(193), UINT8_C( 47), UINT8_C(192), UINT8_C(188), UINT8_C(253), UINT8_C( 56), UINT8_C( 74), UINT8_C(100) } },
    },
    { { UINT8_C(250), UINT8_C(133), UINT8_C( 24), UINT8_C(253), UINT8_C(205), UINT8_C(173), UINT8_C(198), UINT8_C(109),
        UINT8_C(124), UINT8_C( 15), UINT8_C(120), UINT8_C(159), UINT8_C( 86), UINT8_C( 42), UINT8_C(227), UINT8_C( 91) },
        { { UINT8_C(250), UINT8_C(133), UINT8_C( 24), UINT8_C(253), UINT8_C(205), UINT8_C(173), UINT8_C(198), UINT8_C(109) },
          { UINT8_C(124), UINT8_C( 15), UINT8_C(120), UINT8_C(159), UINT8_C( 86), UINT8_C( 42), UINT8_C(227), UINT8_C( 91) } },
    },
    { { UINT8_C(207), UINT8_C(105), UINT8_C(151), UINT8_C(116), UINT8_C(164), UINT8_C(236), UINT8_C(236), UINT8_C(101),
        UINT8_C( 27), UINT8_C(172), UINT8_C( 33), UINT8_C( 24), UINT8_C(229), UINT8_C(108), UINT8_C(125), UINT8_C(223) },
        { { UINT8_C(207), UINT8_C(105), UINT8_C(151), UINT8_C(116), UINT8_C(164), UINT8_C(236), UINT8_C(236), UINT8_C(101) },
          { UINT8_C( 27), UINT8_C(172), UINT8_C( 33), UINT8_C( 24), UINT8_C(229), UINT8_C(108), UINT8_C(125), UINT8_C(223) } },
    },
    { { UINT8_C(241), UINT8_C(149), UINT8_C(220), UINT8_C(190), UINT8_C( 67), UINT8_C(163), UINT8_C( 44), UINT8_C(191),
        UINT8_C(178), UINT8_C(164), UINT8_C( 94), UINT8_C(  8), UINT8_C(206), UINT8_C( 65), UINT8_C( 99), UINT8_C(157) },
        { { UINT8_C(241), UINT8_C(149), UINT8_C(220), UINT8_C(190), UINT8_C( 67), UINT8_C(163), UINT8_C( 44), UINT8_C(191) },
          { UINT8_C(178), UINT8_C(164), UINT8_C( 94), UINT8_C(  8), UINT8_C(206), UINT8_C( 65), UINT8_C( 99), UINT8_C(157) } },
    },
    { { UINT8_C(171), UINT8_C(250), UINT8_C( 18), UINT8_C( 79), UINT8_C(230), UINT8_C(254), UINT8_C(180), UINT8_C(  2),
        UINT8_C(170), UINT8_C(214), UINT8_C( 26), UINT8_C(143), UINT8_C( 66), UINT8_C(151), UINT8_C(111), UINT8_C( 51) },
        { { UINT8_C(171), UINT8_C(250), UINT8_C( 18), UINT8_C( 79), UINT8_C(230), UINT8_C(254), UINT8_C(180), UINT8_C(  2) },
          { UINT8_C(170), UINT8_C(214), UINT8_C( 26), UINT8_C(143), UINT8_C( 66), UINT8_C(151), UINT8_C(111), UINT8_C( 51) } },
    },
    { { UINT8_C( 45), UINT8_C( 75), UINT8_C(241), UINT8_C(112), UINT8_C(238), UINT8_C( 29), UINT8_C( 47), UINT8_C(160),
        UINT8_C(194), UINT8_C(141), UINT8_C(168), UINT8_C(144), UINT8_C(207), UINT8_C( 12), UINT8_C( 46), UINT8_C(122) },
        { { UINT8_C( 45), UINT8_C( 75), UINT8_C(241), UINT8_C(112), UINT8_C(238), UINT8_C( 29), UINT8_C( 47), UINT8_C(160) },
          { UINT8_C(194), UINT8_C(141), UINT8_C(168), UINT8_C(144), UINT8_C(207), UINT8_C( 12), UINT8_C( 46), UINT8_C(122) } },
    },
    { { UINT8_C(  6), UINT8_C( 64), UINT8_C(201), UINT8_C(237), UINT8_C( 62), UINT8_C(125), UINT8_C(239), UINT8_C(232),
        UINT8_C( 83), UINT8_C(  9), UINT8_C(120), UINT8_C(149), UINT8_C(161), UINT8_C(231), UINT8_C(200), UINT8_C(206) },
        { { UINT8_C(  6), UINT8_C( 64), UINT8_C(201), UINT8_C(237), UINT8_C( 62), UINT8_C(125), UINT8_C(239), UINT8_C(232) },
          { UINT8_C( 83), UINT8_C(  9), UINT8_C(120), UINT8_C(149), UINT8_C(161), UINT8_C(231), UINT8_C(200), UINT8_C(206) } },
    },
    { { UINT8_C( 50), UINT8_C(186), UINT8_C( 62), UINT8_C( 33), UINT8_C(215), UINT8_C(109), UINT8_C(193), UINT8_C(153),
        UINT8_C(250), UINT8_C(106), UINT8_C( 42), UINT8_C(201), UINT8_C(118), UINT8_C( 88), UINT8_C( 67), UINT8_C(124) },
        { { UINT8_C( 50), UINT8_C(186), UINT8_C( 62), UINT8_C( 33), UINT8_C(215), UINT8_C(109), UINT8_C(193), UINT8_C(153) },
          { UINT8_C(250), UINT8_C(106), UINT8_C( 42), UINT8_C(201), UINT8_C(118), UINT8_C( 88), UINT8_C( 67), UINT8_C(124) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8x2_t r = simde_vld1_u8_x2(test_vec[i].buf);
    simde_uint8x8x2_t expected = {{
        simde_vld1_u8(test_vec[i].expected[0]),
        simde_vld1_u8(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_u8x8x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t buf[16];
    simde_test_codegen_random_memory(16, buf);
    simde_test_codegen_write_vu8(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint8x8x2_t val = simde_vld1_u8_x2(buf);
    simde_test_arm_neon_write_u8x8x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t buf[8];
    uint16_t expected[2][4];
  } test_vec[] = {
    { { UINT16_C(47551), UINT16_C(54317), UINT16_C(62044), UINT16_C(29084), UINT16_C(18544), UINT16_C(61747), UINT16_C( 8675), UINT16_C(57916) },
        { { UINT16_C(47551), UINT16_C(54317), UINT16_C(62044), UINT16_C(29084) },
          { UINT16_C(18544), UINT16_C(61747), UINT16_C( 8675), UINT16_C(57916) } },
    },
    { { UINT16_C(24947), UINT16_C(45001), UINT16_C(23930), UINT16_C(20630), UINT16_C(16303), UINT16_C(46453), UINT16_C(32937), UINT16_C(26751) },
        { { UINT16_C(24947), UINT16_C(45001), UINT16_C(23930), UINT16_C(20630) },
          { UINT16_C(16303), UINT16_C(46453), UINT16_C(32937), UINT16_C(26751) } },
    },
    { { UINT16_C(44089), UINT16_C(38204), UINT16_C(55454), UINT16_C( 3846), UINT16_C(14624), UINT16_C(  768), UINT16_C(15706), UINT16_C(52709) },
        { { UINT16_C(44089), UINT16_C(38204), UINT16_C(55454), UINT16_C( 3846) },
          { UINT16_C(14624), UINT16_C(  768), UINT16_C(15706), UINT16_C(52709) } },
    },
    { { UINT16_C(44958), UINT16_C( 6524), UINT16_C( 4876), UINT16_C(48233), UINT16_C(57170), UINT16_C(64625), UINT16_C(61535), UINT16_C(39268) },
        { { UINT16_C(44958), UINT16_C( 6524), UINT16_C( 4876), UINT16_C(48233) },
          { UINT16_C(57170), UINT16_C(64625), UINT16_C(61535), UINT16_C(39268) } },
    },
    { { UINT16_C(41372), UINT16_C(15150), UINT16_C(13689), UINT16_C(39498), UINT16_C(19054), UINT16_C(51613), UINT16_C(33671), UINT16_C( 9878) },
        { { UINT16_C(41372), UINT16_C(15150), UINT16_C(13689), UINT16_C(39498) },
          { UINT16_C(19054), UINT16_C(51613), UINT16_C(33671), UINT16_C( 9878) } },
    },
    { { UINT16_C( 4914), UINT16_C(15935), UINT16_C(43046), UINT16_C(30970), UINT16_C(27783), UINT16_C(59252), UINT16_C(55644), UINT16_C(63872) },
        { { UINT16_C( 4914), UINT16_C(15935), UINT16_C(43046), UINT16_C(30970) },
          { UINT16_C(27783), UINT16_C(59252), UINT16_C(55644), UINT16_C(63872) } },
    },
    { { UINT16_C(44666), UINT16_C(62260), UINT16_C(32483), UINT16_C(21133), UINT16_C(11208), UINT16_C(20507), UINT16_C(45486), UINT16_C(57462) },
        { { UINT16_C(44666), UINT16_C(62260), UINT16_C(32483), UINT16_C(21133) },
          { UINT16_C(11208), UINT16_C(20507), UINT16_C(45486), UINT16_C(57462) } },
    },
    { { UINT16_C(46532), UINT16_C(59934), UINT16_C( 6493), UINT16_C(58723), UINT16_C(55173), UINT16_C(57804), UINT16_C(19632), UINT16_C(10970) },
        { { UINT16_C(46532), UINT16_C(59934), UINT16_C( 6493), UINT16_C(58723) },
          { UINT16_C(55173), UINT16_C(57804), UINT16_C(19632), UINT16_C(10970) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4x2_t r = simde_vld1_u16_x2(test_vec[i].buf);
    simde_uint16x4x2_t expected = {{
        simde_vld1_u16(test_vec[i].expected[0]),
        simde_vld1_u16(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_u16x4x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t buf[8];
    simde_test_codegen_random_memory(16, (uint8_t*)buf);
    simde_test_codegen_write_vu16(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint16x4x2_t val = simde_vld1_u16_x2(buf);
    simde_test_arm_neon_write_u16x4x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t buf[4];
    uint32_t expected[2][2];
  } test_vec[] = {
    { { UINT32_C(3726511866), UINT32_C(1429253004), UINT32_C(2225425366), UINT32_C(3244563452) },
        { { UINT32_C(3726511866), UINT32_C(1429253004) },
          { UINT32_C(2225425366), UINT32_C(3244563452) } },
    },
    { { UINT32_C( 766215120), UINT32_C( 554831516), UINT32_C(2516770534), UINT32_C( 633462058) },
        { { UINT32_C( 766215120), UINT32_C( 554831516) },
          { UINT32_C(2516770534), UINT32_C( 633462058) } },
    },
    { { UINT32_C(2013519851), UINT32_C(1640838026), UINT32_C(2061857406), UINT32_C(1564166797) },
        { { UINT32_C(2013519851), UINT32_C(1640838026) },
          { UINT32_C(2061857406), UINT32_C(1564166797) } },
    },
    { { UINT32_C(1770710989), UINT32_C(3683294709), UINT32_C(2792524923), UINT32_C(1439380329) },
        { { UINT32_C(1770710989), UINT32_C(3683294709) },
          { UINT32_C(2792524923), UINT32_C(1439380329) } },
    },
    { { UINT32_C(2630733330), UINT32_C(2147326465), UINT32_C(2583290636), UINT32_C(4210439469) },
        { { UINT32_C(2630733330), UINT32_C(2147326465) },
          { UINT32_C(2583290636), UINT32_C(4210439469) } },
    },
    { { UINT32_C( 291733532), UINT32_C(2582506781), UINT32_C(3812581241), UINT32_C(2755136146) },
        { { UINT32_C( 291733532), UINT32_C(2582506781) },
          { UINT32_C(3812581241), UINT32_C(2755136146) } },
    },
    { { UINT32_C(3644851672), UINT32_C(2874687135), UINT32_C(1313100065), UINT32_C(2722642566) },
        { { UINT32_C(3644851672), UINT32_C(2874687135) },
          { UINT32_C(1313100065), UINT32_C(2722642566) } },
    },
    { { UINT32_C(3635719098), UINT32_C( 292659608), UINT32_C(2465509376), UINT32_C(2453023930) },
        { { UINT32_C(3635719098), UINT32_C( 292659608) },
          { UINT32_C(2465509376), UINT32_C(2453023930) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2x2_t r = simde_vld1_u32_x2(test_vec[i].buf);
    simde_uint32x2x2_t expected = {{
        simde_vld1_u32(test_vec[i].expected[0]),
        simde_vld1_u32(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_u32x2x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t buf[4];
    simde_test_codegen_random_memory(16, (uint8_t*)buf);
    simde_test_codegen_write_vu32(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint32x2x2_t val = simde_vld1_u32_x2(buf);
    simde_test_arm_neon_write_u32x2x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t buf[2];
    uint64_t expected[2][1];
  } test_vec[] = {
    { { UINT64_C(15383104133572294193), UINT64_C(12987655620200218388) },
        { { UINT64_C(15383104133572294193) },
          { UINT64_C(12987655620200218388) } },
    },
    { { UINT64_C(10574730731501449494), UINT64_C( 1367223886028256429) },
        { { UINT64_C(10574730731501449494) },
          { UINT64_C( 1367223886028256429) } },
    },
    { { UINT64_C( 4277115794961425617), UINT64_C(   57162415927098910) },
        { { UINT64_C( 4277115794961425617) },
          { UINT64_C(   57162415927098910) } },
    },
    { { UINT64_C(   84001952189339397), UINT64_C( 8797607775642865443) },
        { { UINT64_C(   84001952189339397) },
          { UINT64_C( 8797607775642865443) } },
    },
    { { UINT64_C( 8514155533018659525), UINT64_C( 1784649289470770905) },
        { { UINT64_C( 8514155533018659525) },
          { UINT64_C( 1784649289470770905) } },
    },
    { { UINT64_C(  362498959319528369), UINT64_C(10830349863968468777) },
        { { UINT64_C(  362498959319528369) },
          { UINT64_C(10830349863968468777) } },
    },
    { { UINT64_C( 9433541109461765403), UINT64_C( 9427170716404775081) },
        { { UINT64_C( 9433541109461765403) },
          { UINT64_C( 9427170716404775081) } },
    },
    { { UINT64_C( 9828137922304967804), UINT64_C(12278686769684901630) },
        { { UINT64_C( 9828137922304967804) },
          { UINT64_C(12278686769684901630) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1x2_t r = simde_vld1_u64_x2(test_vec[i].buf);
    simde_uint64x1x2_t expected = {{
        simde_vld1_u64(test_vec[i].expected[0]),
        simde_vld1_u64(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_u64x1x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t buf[2];
    simde_test_codegen_random_memory(16, (uint8_t*)buf);
    simde_test_codegen_write_vu64(2, 2, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint64x1x2_t val = simde_vld1_u64_x2(buf);
    simde_test_arm_neon_write_u64x1x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_f32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_f64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u64_x2)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
