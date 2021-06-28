
#define SIMDE_TEST_ARM_NEON_INSN recps

#include "test-neon.h"
#include "../../../simde/arm/neon/recps.h"

static int
test_simde_vrecpss_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 b;
    simde_float32 r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -748.53),
      SIMDE_FLOAT32_C(  -323.44),
      SIMDE_FLOAT32_C(-242102.55) },
    { SIMDE_FLOAT32_C(  -863.84),
      SIMDE_FLOAT32_C(  -111.67),
      SIMDE_FLOAT32_C(-96463.02) },
    { SIMDE_FLOAT32_C(  -771.32),
      SIMDE_FLOAT32_C(  -741.55),
      SIMDE_FLOAT32_C(-571970.31) },
    { SIMDE_FLOAT32_C(  -342.64),
      SIMDE_FLOAT32_C(   444.85),
      SIMDE_FLOAT32_C(152425.41) },
    { SIMDE_FLOAT32_C(  -655.40),
      SIMDE_FLOAT32_C(  -879.55),
      SIMDE_FLOAT32_C(-576455.06) },
    { SIMDE_FLOAT32_C(  -372.59),
      SIMDE_FLOAT32_C(  -918.90),
      SIMDE_FLOAT32_C(-342370.97) },
    { SIMDE_FLOAT32_C(   213.91),
      SIMDE_FLOAT32_C(  -931.13),
      SIMDE_FLOAT32_C(199180.02) },
    { SIMDE_FLOAT32_C(    10.43),
      SIMDE_FLOAT32_C(   956.65),
      SIMDE_FLOAT32_C( -9975.86) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t a = test_vec[i].a;
    simde_float32_t b = test_vec[i].b;
    simde_float32_t r = simde_vrecpss_f32(a, b);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t b = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vrecpss_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecpsd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 b;
    simde_float64 r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -162.57),
      SIMDE_FLOAT64_C(   -74.56),
      SIMDE_FLOAT64_C(-12119.22) },
    { SIMDE_FLOAT64_C(  -728.37),
      SIMDE_FLOAT64_C(  -444.51),
      SIMDE_FLOAT64_C(-323765.75) },
    { SIMDE_FLOAT64_C(  -661.56),
      SIMDE_FLOAT64_C(  -963.04),
      SIMDE_FLOAT64_C(-637106.74) },
    { SIMDE_FLOAT64_C(    94.90),
      SIMDE_FLOAT64_C(  -441.19),
      SIMDE_FLOAT64_C( 41870.93) },
    { SIMDE_FLOAT64_C(   695.96),
      SIMDE_FLOAT64_C(   222.69),
      SIMDE_FLOAT64_C(-154981.33) },
    { SIMDE_FLOAT64_C(  -265.05),
      SIMDE_FLOAT64_C(   704.53),
      SIMDE_FLOAT64_C(186737.68) },
    { SIMDE_FLOAT64_C(   740.69),
      SIMDE_FLOAT64_C(    -6.61),
      SIMDE_FLOAT64_C(  4897.96) },
    { SIMDE_FLOAT64_C(   225.75),
      SIMDE_FLOAT64_C(   454.29),
      SIMDE_FLOAT64_C(-102553.97) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t a = test_vec[i].a;
    simde_float64_t b = test_vec[i].b;
    simde_float64_t r = simde_vrecpsd_f64(a, b);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64_t b = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64_t r = simde_vrecpsd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecps_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -543.91) },
      { SIMDE_FLOAT64_C(  -340.35) },
      { SIMDE_FLOAT64_C(-185117.77) } },
    { { SIMDE_FLOAT64_C(    33.22) },
      { SIMDE_FLOAT64_C(  -459.68) },
      { SIMDE_FLOAT64_C( 15272.57) } },
    { { SIMDE_FLOAT64_C(    33.15) },
      { SIMDE_FLOAT64_C(   387.38) },
      { SIMDE_FLOAT64_C(-12839.65) } },
    { { SIMDE_FLOAT64_C(  -549.95) },
      { SIMDE_FLOAT64_C(   836.96) },
      { SIMDE_FLOAT64_C(460288.15) } },
    { { SIMDE_FLOAT64_C(  -329.05) },
      { SIMDE_FLOAT64_C(  -483.44) },
      { SIMDE_FLOAT64_C(-159073.93) } },
    { { SIMDE_FLOAT64_C(  -667.77) },
      { SIMDE_FLOAT64_C(  -367.80) },
      { SIMDE_FLOAT64_C(-245603.81) } },
    { { SIMDE_FLOAT64_C(  -347.20) },
      { SIMDE_FLOAT64_C(   672.37) },
      { SIMDE_FLOAT64_C(233448.86) } },
    { { SIMDE_FLOAT64_C(  -463.31) },
      { SIMDE_FLOAT64_C(  -856.45) },
      { SIMDE_FLOAT64_C(-396799.85) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vrecps_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vrecps_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecps_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    47.87), SIMDE_FLOAT32_C(   269.61) },
      { SIMDE_FLOAT32_C(    96.45), SIMDE_FLOAT32_C(  -250.23) },
      { SIMDE_FLOAT32_C( -4615.06), SIMDE_FLOAT32_C( 67466.51) } },
    { { SIMDE_FLOAT32_C(  -555.90), SIMDE_FLOAT32_C(  -609.45) },
      { SIMDE_FLOAT32_C(   322.74), SIMDE_FLOAT32_C(  -176.70) },
      { SIMDE_FLOAT32_C(179413.17), SIMDE_FLOAT32_C(-107687.81) } },
    { { SIMDE_FLOAT32_C(  -980.02), SIMDE_FLOAT32_C(   183.49) },
      { SIMDE_FLOAT32_C(  -974.10), SIMDE_FLOAT32_C(   331.54) },
      { SIMDE_FLOAT32_C(-954635.50), SIMDE_FLOAT32_C(-60832.28) } },
    { { SIMDE_FLOAT32_C(   388.02), SIMDE_FLOAT32_C(  -288.08) },
      { SIMDE_FLOAT32_C(  -277.25), SIMDE_FLOAT32_C(   632.81) },
      { SIMDE_FLOAT32_C(107580.54), SIMDE_FLOAT32_C(182301.89) } },
    { { SIMDE_FLOAT32_C(  -326.10), SIMDE_FLOAT32_C(   760.56) },
      { SIMDE_FLOAT32_C(  -335.74), SIMDE_FLOAT32_C(  -532.85) },
      { SIMDE_FLOAT32_C(-109482.81), SIMDE_FLOAT32_C(405266.38) } },
    { { SIMDE_FLOAT32_C(  -255.56), SIMDE_FLOAT32_C(   505.21) },
      { SIMDE_FLOAT32_C(   -48.40), SIMDE_FLOAT32_C(   933.85) },
      { SIMDE_FLOAT32_C(-12367.10), SIMDE_FLOAT32_C(-471788.34) } },
    { { SIMDE_FLOAT32_C(   785.46), SIMDE_FLOAT32_C(   215.93) },
      { SIMDE_FLOAT32_C(   289.25), SIMDE_FLOAT32_C(   644.14) },
      { SIMDE_FLOAT32_C(-227192.31), SIMDE_FLOAT32_C(-139087.16) } },
    { { SIMDE_FLOAT32_C(   763.47), SIMDE_FLOAT32_C(   586.70) },
      { SIMDE_FLOAT32_C(    40.67), SIMDE_FLOAT32_C(  -188.67) },
      { SIMDE_FLOAT32_C(-31048.32), SIMDE_FLOAT32_C(110694.69) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vrecps_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrecps_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecpsq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   385.11), SIMDE_FLOAT64_C(   -71.96) },
      { SIMDE_FLOAT64_C(  -168.56), SIMDE_FLOAT64_C(   809.26) },
      { SIMDE_FLOAT64_C( 64916.14), SIMDE_FLOAT64_C( 58236.35) } },
    { { SIMDE_FLOAT64_C(  -902.27), SIMDE_FLOAT64_C(    27.68) },
      { SIMDE_FLOAT64_C(   106.94), SIMDE_FLOAT64_C(   161.22) },
      { SIMDE_FLOAT64_C( 96490.75), SIMDE_FLOAT64_C( -4460.57) } },
    { { SIMDE_FLOAT64_C(   596.08), SIMDE_FLOAT64_C(   896.02) },
      { SIMDE_FLOAT64_C(    -2.55), SIMDE_FLOAT64_C(  -787.75) },
      { SIMDE_FLOAT64_C(  1522.00), SIMDE_FLOAT64_C(705841.76) } },
    { { SIMDE_FLOAT64_C(   890.31), SIMDE_FLOAT64_C(  -665.19) },
      { SIMDE_FLOAT64_C(   419.11), SIMDE_FLOAT64_C(   384.44) },
      { SIMDE_FLOAT64_C(-373135.82), SIMDE_FLOAT64_C(255727.64) } },
    { { SIMDE_FLOAT64_C(  -973.24), SIMDE_FLOAT64_C(  -191.28) },
      { SIMDE_FLOAT64_C(   845.80), SIMDE_FLOAT64_C(  -594.55) },
      { SIMDE_FLOAT64_C(823168.39), SIMDE_FLOAT64_C(-113723.52) } },
    { { SIMDE_FLOAT64_C(   -12.90), SIMDE_FLOAT64_C(    90.72) },
      { SIMDE_FLOAT64_C(   573.26), SIMDE_FLOAT64_C(  -769.29) },
      { SIMDE_FLOAT64_C(  7397.05), SIMDE_FLOAT64_C( 69791.99) } },
    { { SIMDE_FLOAT64_C(   663.06), SIMDE_FLOAT64_C(   783.64) },
      { SIMDE_FLOAT64_C(   791.80), SIMDE_FLOAT64_C(  -184.17) },
      { SIMDE_FLOAT64_C(-525008.91), SIMDE_FLOAT64_C(144324.98) } },
    { { SIMDE_FLOAT64_C(  -853.09), SIMDE_FLOAT64_C(   -31.87) },
      { SIMDE_FLOAT64_C(   169.12), SIMDE_FLOAT64_C(   532.02) },
      { SIMDE_FLOAT64_C(144276.58), SIMDE_FLOAT64_C( 16957.48) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vrecpsq_f64(a, b);
    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vrecpsq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecpsq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -143.68), SIMDE_FLOAT32_C(  -862.89), SIMDE_FLOAT32_C(   561.10), SIMDE_FLOAT32_C(   300.42) },
      { SIMDE_FLOAT32_C(  -472.33), SIMDE_FLOAT32_C(  -116.16), SIMDE_FLOAT32_C(  -876.28), SIMDE_FLOAT32_C(  -452.35) },
      { SIMDE_FLOAT32_C(-67862.37), SIMDE_FLOAT32_C(-100231.30), SIMDE_FLOAT32_C(491682.69), SIMDE_FLOAT32_C(135897.00) } },
    { { SIMDE_FLOAT32_C(  -932.67), SIMDE_FLOAT32_C(  -850.38), SIMDE_FLOAT32_C(   879.19), SIMDE_FLOAT32_C(   455.35) },
      { SIMDE_FLOAT32_C(  -138.46), SIMDE_FLOAT32_C(  -398.06), SIMDE_FLOAT32_C(    88.15), SIMDE_FLOAT32_C(   535.43) },
      { SIMDE_FLOAT32_C(-129135.49), SIMDE_FLOAT32_C(-338500.25), SIMDE_FLOAT32_C(-77498.60), SIMDE_FLOAT32_C(-243806.05) } },
    { { SIMDE_FLOAT32_C(  -637.51), SIMDE_FLOAT32_C(   752.41), SIMDE_FLOAT32_C(  -997.42), SIMDE_FLOAT32_C(   106.94) },
      { SIMDE_FLOAT32_C(   257.62), SIMDE_FLOAT32_C(   -45.82), SIMDE_FLOAT32_C(    40.79), SIMDE_FLOAT32_C(    43.09) },
      { SIMDE_FLOAT32_C(164237.33), SIMDE_FLOAT32_C( 34477.43), SIMDE_FLOAT32_C( 40686.76), SIMDE_FLOAT32_C( -4606.04) } },
    { { SIMDE_FLOAT32_C(  -829.89), SIMDE_FLOAT32_C(  -669.96), SIMDE_FLOAT32_C(  -312.77), SIMDE_FLOAT32_C(   933.58) },
      { SIMDE_FLOAT32_C(   916.74), SIMDE_FLOAT32_C(   727.89), SIMDE_FLOAT32_C(  -255.09), SIMDE_FLOAT32_C(  -226.94) },
      { SIMDE_FLOAT32_C(760795.38), SIMDE_FLOAT32_C(487659.22), SIMDE_FLOAT32_C(-79782.49), SIMDE_FLOAT32_C(211868.66) } },
    { { SIMDE_FLOAT32_C(   865.00), SIMDE_FLOAT32_C(  -693.98), SIMDE_FLOAT32_C(  -926.52), SIMDE_FLOAT32_C(  -607.33) },
      { SIMDE_FLOAT32_C(   189.86), SIMDE_FLOAT32_C(  -802.81), SIMDE_FLOAT32_C(   -59.68), SIMDE_FLOAT32_C(   257.19) },
      { SIMDE_FLOAT32_C(-164226.91), SIMDE_FLOAT32_C(-557132.06), SIMDE_FLOAT32_C(-55292.71), SIMDE_FLOAT32_C(156201.20) } },
    { { SIMDE_FLOAT32_C(  -653.19), SIMDE_FLOAT32_C(  -180.49), SIMDE_FLOAT32_C(  -287.46), SIMDE_FLOAT32_C(   208.35) },
      { SIMDE_FLOAT32_C(   421.45), SIMDE_FLOAT32_C(   800.69), SIMDE_FLOAT32_C(  -256.22), SIMDE_FLOAT32_C(   783.94) },
      { SIMDE_FLOAT32_C(275288.94), SIMDE_FLOAT32_C(144518.55), SIMDE_FLOAT32_C(-73651.00), SIMDE_FLOAT32_C(-163331.91) } },
    { { SIMDE_FLOAT32_C(   553.11), SIMDE_FLOAT32_C(  -253.63), SIMDE_FLOAT32_C(  -109.12), SIMDE_FLOAT32_C(  -189.27) },
      { SIMDE_FLOAT32_C(   700.55), SIMDE_FLOAT32_C(   931.66), SIMDE_FLOAT32_C(   853.81), SIMDE_FLOAT32_C(   870.66) },
      { SIMDE_FLOAT32_C(-387479.19), SIMDE_FLOAT32_C(236298.92), SIMDE_FLOAT32_C( 93169.75), SIMDE_FLOAT32_C(164791.81) } },
    { { SIMDE_FLOAT32_C(  -738.30), SIMDE_FLOAT32_C(  -458.96), SIMDE_FLOAT32_C(   804.24), SIMDE_FLOAT32_C(  -821.55) },
      { SIMDE_FLOAT32_C(  -731.07), SIMDE_FLOAT32_C(  -450.84), SIMDE_FLOAT32_C(   -48.49), SIMDE_FLOAT32_C(  -866.06) },
      { SIMDE_FLOAT32_C(-539747.00), SIMDE_FLOAT32_C(-206915.52), SIMDE_FLOAT32_C( 38999.60), SIMDE_FLOAT32_C(-711509.56) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vrecpsq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrecpsq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpss_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpsd_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrecps_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecps_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vrecpsq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpsq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
