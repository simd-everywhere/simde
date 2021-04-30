
#define SIMDE_TEST_ARM_NEON_INSN recps

#include "test-neon.h"
#include "../../../simde/arm/neon/recps.h"

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
SIMDE_TEST_FUNC_LIST_ENTRY(vrecps_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vrecpsq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
