#define SIMDE_TEST_ARM_NEON_INSN neg

#include "test-neon.h"
#include "../../../simde/arm/neon/neg.h"

static int
test_simde_vneg_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   716.64), SIMDE_FLOAT32_C(  -987.31) },
      { SIMDE_FLOAT32_C(  -716.64), SIMDE_FLOAT32_C(   987.31) } },
    { { SIMDE_FLOAT32_C(   -83.05), SIMDE_FLOAT32_C(  -486.69) },
      { SIMDE_FLOAT32_C(    83.05), SIMDE_FLOAT32_C(   486.69) } },
    { { SIMDE_FLOAT32_C(    36.35), SIMDE_FLOAT32_C(   515.69) },
      { SIMDE_FLOAT32_C(   -36.35), SIMDE_FLOAT32_C(  -515.69) } },
    { { SIMDE_FLOAT32_C(  -864.35), SIMDE_FLOAT32_C(   418.22) },
      { SIMDE_FLOAT32_C(   864.35), SIMDE_FLOAT32_C(  -418.22) } },
    { { SIMDE_FLOAT32_C(  -825.75), SIMDE_FLOAT32_C(  -563.01) },
      { SIMDE_FLOAT32_C(   825.75), SIMDE_FLOAT32_C(   563.01) } },
    { { SIMDE_FLOAT32_C(  -635.51), SIMDE_FLOAT32_C(  -778.46) },
      { SIMDE_FLOAT32_C(   635.51), SIMDE_FLOAT32_C(   778.46) } },
    { { SIMDE_FLOAT32_C(   755.42), SIMDE_FLOAT32_C(   443.43) },
      { SIMDE_FLOAT32_C(  -755.42), SIMDE_FLOAT32_C(  -443.43) } },
    { { SIMDE_FLOAT32_C(  -286.48), SIMDE_FLOAT32_C(  -693.77) },
      { SIMDE_FLOAT32_C(   286.48), SIMDE_FLOAT32_C(   693.77) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vneg_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vneg_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vneg_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -67.79) },
      { SIMDE_FLOAT64_C(    67.79) } },
    { { SIMDE_FLOAT64_C(  -759.84) },
      { SIMDE_FLOAT64_C(   759.84) } },
    { { SIMDE_FLOAT64_C(   497.94) },
      { SIMDE_FLOAT64_C(  -497.94) } },
    { { SIMDE_FLOAT64_C(   813.37) },
      { SIMDE_FLOAT64_C(  -813.37) } },
    { { SIMDE_FLOAT64_C(  -277.49) },
      { SIMDE_FLOAT64_C(   277.49) } },
    { { SIMDE_FLOAT64_C(   513.19) },
      { SIMDE_FLOAT64_C(  -513.19) } },
    { { SIMDE_FLOAT64_C(  -893.67) },
      { SIMDE_FLOAT64_C(   893.67) } },
    { { SIMDE_FLOAT64_C(   120.57) },
      { SIMDE_FLOAT64_C(  -120.57) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vneg_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vneg_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vneg_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 126),  INT8_C(  53), -INT8_C(   7),  INT8_C(   9), -INT8_C(   2),  INT8_C(  28),  INT8_C(  18),  INT8_C(  47) },
      {  INT8_C( 126), -INT8_C(  53),  INT8_C(   7), -INT8_C(   9),  INT8_C(   2), -INT8_C(  28), -INT8_C(  18), -INT8_C(  47) } },
    { {  INT8_C(   2),  INT8_C(  90), -INT8_C(  75), -INT8_C(  54),  INT8_C( 108),  INT8_C(  22), -INT8_C( 115),  INT8_C(  23) },
      { -INT8_C(   2), -INT8_C(  90),  INT8_C(  75),  INT8_C(  54), -INT8_C( 108), -INT8_C(  22),  INT8_C( 115), -INT8_C(  23) } },
    { {  INT8_C(  76), -INT8_C(  50), -INT8_C(  98), -INT8_C( 115),  INT8_C(  78),  INT8_C(  40), -INT8_C(  89), -INT8_C(  13) },
      { -INT8_C(  76),  INT8_C(  50),  INT8_C(  98),  INT8_C( 115), -INT8_C(  78), -INT8_C(  40),  INT8_C(  89),  INT8_C(  13) } },
    { { -INT8_C(  61),      INT8_MAX,  INT8_C(  55),  INT8_C( 119),  INT8_C( 116), -INT8_C(  71),  INT8_C(  60), -INT8_C(   9) },
      {  INT8_C(  61), -INT8_C( 127), -INT8_C(  55), -INT8_C( 119), -INT8_C( 116),  INT8_C(  71), -INT8_C(  60),  INT8_C(   9) } },
    { { -INT8_C(  18),  INT8_C(  53),  INT8_C(   0), -INT8_C(  19),  INT8_C(  81),  INT8_C(  18),  INT8_C(  28),  INT8_C(  84) },
      {  INT8_C(  18), -INT8_C(  53),  INT8_C(   0),  INT8_C(  19), -INT8_C(  81), -INT8_C(  18), -INT8_C(  28), -INT8_C(  84) } },
    { {  INT8_C( 108), -INT8_C(  46),  INT8_C(  30), -INT8_C(  40), -INT8_C(  24), -INT8_C(  85), -INT8_C(  17),  INT8_C(  53) },
      { -INT8_C( 108),  INT8_C(  46), -INT8_C(  30),  INT8_C(  40),  INT8_C(  24),  INT8_C(  85),  INT8_C(  17), -INT8_C(  53) } },
    { {  INT8_C( 121), -INT8_C( 115), -INT8_C(  62), -INT8_C(  57), -INT8_C(  75),  INT8_C( 105), -INT8_C(  70),  INT8_C( 121) },
      { -INT8_C( 121),  INT8_C( 115),  INT8_C(  62),  INT8_C(  57),  INT8_C(  75), -INT8_C( 105),  INT8_C(  70), -INT8_C( 121) } },
    { { -INT8_C(  24), -INT8_C(  14), -INT8_C(  16),  INT8_C(  92), -INT8_C(  85),  INT8_C(  44),  INT8_C(  83), -INT8_C( 103) },
      {  INT8_C(  24),  INT8_C(  14),  INT8_C(  16), -INT8_C(  92),  INT8_C(  85), -INT8_C(  44), -INT8_C(  83),  INT8_C( 103) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vneg_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vneg_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vneg_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 16602), -INT16_C( 23072),  INT16_C(  1303), -INT16_C( 18923) },
      {  INT16_C( 16602),  INT16_C( 23072), -INT16_C(  1303),  INT16_C( 18923) } },
    { {  INT16_C( 27322),  INT16_C( 20477), -INT16_C(  2392), -INT16_C( 16976) },
      { -INT16_C( 27322), -INT16_C( 20477),  INT16_C(  2392),  INT16_C( 16976) } },
    { {  INT16_C(  6729), -INT16_C( 21704), -INT16_C( 14531), -INT16_C(  3275) },
      { -INT16_C(  6729),  INT16_C( 21704),  INT16_C( 14531),  INT16_C(  3275) } },
    { { -INT16_C( 20184),  INT16_C(  9579), -INT16_C( 26844),  INT16_C( 19022) },
      {  INT16_C( 20184), -INT16_C(  9579),  INT16_C( 26844), -INT16_C( 19022) } },
    { {  INT16_C( 11862),  INT16_C( 28143),  INT16_C(  1075), -INT16_C(  4572) },
      { -INT16_C( 11862), -INT16_C( 28143), -INT16_C(  1075),  INT16_C(  4572) } },
    { {  INT16_C(  8559),  INT16_C(  5949), -INT16_C(  4584),  INT16_C( 25044) },
      { -INT16_C(  8559), -INT16_C(  5949),  INT16_C(  4584), -INT16_C( 25044) } },
    { {  INT16_C(  3336),  INT16_C( 17676),  INT16_C( 16852), -INT16_C(   712) },
      { -INT16_C(  3336), -INT16_C( 17676), -INT16_C( 16852),  INT16_C(   712) } },
    { { -INT16_C( 23565),  INT16_C(  5922),  INT16_C( 28730), -INT16_C( 28319) },
      {  INT16_C( 23565), -INT16_C(  5922), -INT16_C( 28730),  INT16_C( 28319) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vneg_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vneg_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vneg_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1514105162), -INT32_C(  1586606905) },
      {  INT32_C(  1514105162),  INT32_C(  1586606905) } },
    { {  INT32_C(   302620279), -INT32_C(   491707108) },
      { -INT32_C(   302620279),  INT32_C(   491707108) } },
    { { -INT32_C(   876535401), -INT32_C(  2036143544) },
      {  INT32_C(   876535401),  INT32_C(  2036143544) } },
    { { -INT32_C(   731879282), -INT32_C(   456778194) },
      {  INT32_C(   731879282),  INT32_C(   456778194) } },
    { {  INT32_C(  2089387701),  INT32_C(  1243477971) },
      { -INT32_C(  2089387701), -INT32_C(  1243477971) } },
    { { -INT32_C(  1319360619), -INT32_C(   476901812) },
      {  INT32_C(  1319360619),  INT32_C(   476901812) } },
    { {  INT32_C(  2007913775), -INT32_C(   838971329) },
      { -INT32_C(  2007913775),  INT32_C(   838971329) } },
    { { -INT32_C(   408789319),  INT32_C(   852191357) },
      {  INT32_C(   408789319), -INT32_C(   852191357) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vneg_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vneg_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vneg_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C(  876024735620259410) },
      {  INT64_C(  876024735620259410) } },
    { { -INT64_C( 5592594344589837578) },
      {  INT64_C( 5592594344589837578) } },
    { { -INT64_C( 8278041931419543793) },
      {  INT64_C( 8278041931419543793) } },
    { {  INT64_C(  604013801299550026) },
      { -INT64_C(  604013801299550026) } },
    { { -INT64_C(  424514824547121404) },
      {  INT64_C(  424514824547121404) } },
    { {  INT64_C( 2653581244415604749) },
      { -INT64_C( 2653581244415604749) } },
    { { -INT64_C( 8302618725080709503) },
      {  INT64_C( 8302618725080709503) } },
    { { -INT64_C( 7913371491563099189) },
      {  INT64_C( 7913371491563099189) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t r = simde_vneg_s64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_vneg_s64(a);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vnegq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   804.42), SIMDE_FLOAT32_C(  -601.06), SIMDE_FLOAT32_C(  -462.25), SIMDE_FLOAT32_C(  -337.95) },
      { SIMDE_FLOAT32_C(  -804.42), SIMDE_FLOAT32_C(   601.06), SIMDE_FLOAT32_C(   462.25), SIMDE_FLOAT32_C(   337.95) } },
    { { SIMDE_FLOAT32_C(  -866.80), SIMDE_FLOAT32_C(  -244.09), SIMDE_FLOAT32_C(   711.44), SIMDE_FLOAT32_C(   906.78) },
      { SIMDE_FLOAT32_C(   866.80), SIMDE_FLOAT32_C(   244.09), SIMDE_FLOAT32_C(  -711.44), SIMDE_FLOAT32_C(  -906.78) } },
    { { SIMDE_FLOAT32_C(  -339.26), SIMDE_FLOAT32_C(  -922.22), SIMDE_FLOAT32_C(  -188.81), SIMDE_FLOAT32_C(   579.99) },
      { SIMDE_FLOAT32_C(   339.26), SIMDE_FLOAT32_C(   922.22), SIMDE_FLOAT32_C(   188.81), SIMDE_FLOAT32_C(  -579.99) } },
    { { SIMDE_FLOAT32_C(  -134.89), SIMDE_FLOAT32_C(  -740.85), SIMDE_FLOAT32_C(  -696.51), SIMDE_FLOAT32_C(   -24.34) },
      { SIMDE_FLOAT32_C(   134.89), SIMDE_FLOAT32_C(   740.85), SIMDE_FLOAT32_C(   696.51), SIMDE_FLOAT32_C(    24.34) } },
    { { SIMDE_FLOAT32_C(   818.56), SIMDE_FLOAT32_C(   209.57), SIMDE_FLOAT32_C(   842.16), SIMDE_FLOAT32_C(   742.03) },
      { SIMDE_FLOAT32_C(  -818.56), SIMDE_FLOAT32_C(  -209.57), SIMDE_FLOAT32_C(  -842.16), SIMDE_FLOAT32_C(  -742.03) } },
    { { SIMDE_FLOAT32_C(    92.41), SIMDE_FLOAT32_C(  -593.00), SIMDE_FLOAT32_C(   705.50), SIMDE_FLOAT32_C(  -603.00) },
      { SIMDE_FLOAT32_C(   -92.41), SIMDE_FLOAT32_C(   593.00), SIMDE_FLOAT32_C(  -705.50), SIMDE_FLOAT32_C(   603.00) } },
    { { SIMDE_FLOAT32_C(  -438.51), SIMDE_FLOAT32_C(   671.01), SIMDE_FLOAT32_C(  -393.07), SIMDE_FLOAT32_C(   195.29) },
      { SIMDE_FLOAT32_C(   438.51), SIMDE_FLOAT32_C(  -671.01), SIMDE_FLOAT32_C(   393.07), SIMDE_FLOAT32_C(  -195.29) } },
    { { SIMDE_FLOAT32_C(   829.18), SIMDE_FLOAT32_C(   342.47), SIMDE_FLOAT32_C(   267.28), SIMDE_FLOAT32_C(   633.59) },
      { SIMDE_FLOAT32_C(  -829.18), SIMDE_FLOAT32_C(  -342.47), SIMDE_FLOAT32_C(  -267.28), SIMDE_FLOAT32_C(  -633.59) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vnegq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vnegq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vnegq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    29.13), SIMDE_FLOAT64_C(  -879.83) },
      { SIMDE_FLOAT64_C(   -29.13), SIMDE_FLOAT64_C(   879.83) } },
    { { SIMDE_FLOAT64_C(   870.39), SIMDE_FLOAT64_C(  -154.06) },
      { SIMDE_FLOAT64_C(  -870.39), SIMDE_FLOAT64_C(   154.06) } },
    { { SIMDE_FLOAT64_C(  -918.42), SIMDE_FLOAT64_C(   809.31) },
      { SIMDE_FLOAT64_C(   918.42), SIMDE_FLOAT64_C(  -809.31) } },
    { { SIMDE_FLOAT64_C(   998.46), SIMDE_FLOAT64_C(   -21.80) },
      { SIMDE_FLOAT64_C(  -998.46), SIMDE_FLOAT64_C(    21.80) } },
    { { SIMDE_FLOAT64_C(  -937.13), SIMDE_FLOAT64_C(  -287.08) },
      { SIMDE_FLOAT64_C(   937.13), SIMDE_FLOAT64_C(   287.08) } },
    { { SIMDE_FLOAT64_C(   803.74), SIMDE_FLOAT64_C(  -923.43) },
      { SIMDE_FLOAT64_C(  -803.74), SIMDE_FLOAT64_C(   923.43) } },
    { { SIMDE_FLOAT64_C(  -658.03), SIMDE_FLOAT64_C(   943.52) },
      { SIMDE_FLOAT64_C(   658.03), SIMDE_FLOAT64_C(  -943.52) } },
    { { SIMDE_FLOAT64_C(   715.86), SIMDE_FLOAT64_C(  -973.82) },
      { SIMDE_FLOAT64_C(  -715.86), SIMDE_FLOAT64_C(   973.82) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vnegq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vnegq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vnegq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  33), -INT8_C( 124),  INT8_C(  14), -INT8_C(  53), -INT8_C(  28), -INT8_C(  98), -INT8_C(  12),  INT8_C(  95),
        -INT8_C(  17),  INT8_C(  54),  INT8_C(  88),  INT8_C(  35),  INT8_C(  84),  INT8_C(  68),  INT8_C(  14), -INT8_C(  64) },
      { -INT8_C(  33),  INT8_C( 124), -INT8_C(  14),  INT8_C(  53),  INT8_C(  28),  INT8_C(  98),  INT8_C(  12), -INT8_C(  95),
         INT8_C(  17), -INT8_C(  54), -INT8_C(  88), -INT8_C(  35), -INT8_C(  84), -INT8_C(  68), -INT8_C(  14),  INT8_C(  64) } },
    { {  INT8_C(  93),  INT8_C( 100),      INT8_MIN, -INT8_C(  18), -INT8_C(  20),  INT8_C(  22), -INT8_C(  77), -INT8_C(  95),
         INT8_C(  14),  INT8_C(  36),  INT8_C( 106),  INT8_C(  50), -INT8_C( 110),  INT8_C(  71), -INT8_C(  18), -INT8_C(  77) },
      { -INT8_C(  93), -INT8_C( 100),      INT8_MIN,  INT8_C(  18),  INT8_C(  20), -INT8_C(  22),  INT8_C(  77),  INT8_C(  95),
        -INT8_C(  14), -INT8_C(  36), -INT8_C( 106), -INT8_C(  50),  INT8_C( 110), -INT8_C(  71),  INT8_C(  18),  INT8_C(  77) } },
    { { -INT8_C(  53), -INT8_C(   4),      INT8_MAX, -INT8_C(  81), -INT8_C( 101),  INT8_C( 115),  INT8_C(  14), -INT8_C( 118),
        -INT8_C(  86),  INT8_C( 103), -INT8_C(  82), -INT8_C(   2), -INT8_C(  85), -INT8_C(  68), -INT8_C(  66),  INT8_C(   9) },
      {  INT8_C(  53),  INT8_C(   4), -INT8_C( 127),  INT8_C(  81),  INT8_C( 101), -INT8_C( 115), -INT8_C(  14),  INT8_C( 118),
         INT8_C(  86), -INT8_C( 103),  INT8_C(  82),  INT8_C(   2),  INT8_C(  85),  INT8_C(  68),  INT8_C(  66), -INT8_C(   9) } },
    { {  INT8_C(  32),  INT8_C(  63), -INT8_C(   9),  INT8_C(  13),  INT8_C(  85), -INT8_C(  86), -INT8_C(  82),  INT8_C(  99),
        -INT8_C(  49),  INT8_C(  24), -INT8_C( 106),  INT8_C(  97),  INT8_C(  95), -INT8_C( 124),  INT8_C(  20),  INT8_C(  43) },
      { -INT8_C(  32), -INT8_C(  63),  INT8_C(   9), -INT8_C(  13), -INT8_C(  85),  INT8_C(  86),  INT8_C(  82), -INT8_C(  99),
         INT8_C(  49), -INT8_C(  24),  INT8_C( 106), -INT8_C(  97), -INT8_C(  95),  INT8_C( 124), -INT8_C(  20), -INT8_C(  43) } },
    { { -INT8_C( 127), -INT8_C( 109), -INT8_C(  38),  INT8_C(  28),  INT8_C(   7), -INT8_C(  23), -INT8_C(  90), -INT8_C(  79),
         INT8_C(  80),  INT8_C(  84), -INT8_C(  81), -INT8_C(   5),  INT8_C(  16),  INT8_C( 110),  INT8_C(   4),  INT8_C(  49) },
      {      INT8_MAX,  INT8_C( 109),  INT8_C(  38), -INT8_C(  28), -INT8_C(   7),  INT8_C(  23),  INT8_C(  90),  INT8_C(  79),
        -INT8_C(  80), -INT8_C(  84),  INT8_C(  81),  INT8_C(   5), -INT8_C(  16), -INT8_C( 110), -INT8_C(   4), -INT8_C(  49) } },
    { { -INT8_C(  83), -INT8_C(   5),  INT8_C(  62),  INT8_C(   2), -INT8_C(  90), -INT8_C(  20),  INT8_C( 102),  INT8_C( 117),
         INT8_C(   4), -INT8_C(   4), -INT8_C(  42),  INT8_C( 100),      INT8_MIN, -INT8_C(  22), -INT8_C( 113),  INT8_C(   1) },
      {  INT8_C(  83),  INT8_C(   5), -INT8_C(  62), -INT8_C(   2),  INT8_C(  90),  INT8_C(  20), -INT8_C( 102), -INT8_C( 117),
        -INT8_C(   4),  INT8_C(   4),  INT8_C(  42), -INT8_C( 100),      INT8_MIN,  INT8_C(  22),  INT8_C( 113), -INT8_C(   1) } },
    { {  INT8_C( 126),  INT8_C( 105),  INT8_C(  29), -INT8_C( 123),  INT8_C(  82), -INT8_C(  60),  INT8_C(  54), -INT8_C(  94),
         INT8_C(  24), -INT8_C(  27), -INT8_C(  98),  INT8_C(  41),  INT8_C(  83), -INT8_C(  94),  INT8_C(  90),  INT8_C(   0) },
      { -INT8_C( 126), -INT8_C( 105), -INT8_C(  29),  INT8_C( 123), -INT8_C(  82),  INT8_C(  60), -INT8_C(  54),  INT8_C(  94),
        -INT8_C(  24),  INT8_C(  27),  INT8_C(  98), -INT8_C(  41), -INT8_C(  83),  INT8_C(  94), -INT8_C(  90),  INT8_C(   0) } },
    { { -INT8_C(  98), -INT8_C( 104),  INT8_C(   3),  INT8_C(  68), -INT8_C( 124),  INT8_C( 105), -INT8_C(  71), -INT8_C( 120),
         INT8_C( 101), -INT8_C( 113), -INT8_C(  20), -INT8_C(  27),  INT8_C( 121),  INT8_C( 123), -INT8_C(  25), -INT8_C(   9) },
      {  INT8_C(  98),  INT8_C( 104), -INT8_C(   3), -INT8_C(  68),  INT8_C( 124), -INT8_C( 105),  INT8_C(  71),  INT8_C( 120),
        -INT8_C( 101),  INT8_C( 113),  INT8_C(  20),  INT8_C(  27), -INT8_C( 121), -INT8_C( 123),  INT8_C(  25),  INT8_C(   9) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vnegq_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vnegq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vnegq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 15787), -INT16_C( 29057), -INT16_C( 19375), -INT16_C( 11784),  INT16_C(  4515), -INT16_C(  7027), -INT16_C( 20562),  INT16_C( 28379) },
      {  INT16_C( 15787),  INT16_C( 29057),  INT16_C( 19375),  INT16_C( 11784), -INT16_C(  4515),  INT16_C(  7027),  INT16_C( 20562), -INT16_C( 28379) } },
    { {  INT16_C(  7291), -INT16_C(  3670), -INT16_C( 13367), -INT16_C( 28161), -INT16_C(  8143),  INT16_C( 25681), -INT16_C(  8439),  INT16_C( 24356) },
      { -INT16_C(  7291),  INT16_C(  3670),  INT16_C( 13367),  INT16_C( 28161),  INT16_C(  8143), -INT16_C( 25681),  INT16_C(  8439), -INT16_C( 24356) } },
    { { -INT16_C( 23646), -INT16_C(  3091), -INT16_C(  6825), -INT16_C(  1340),  INT16_C( 20982), -INT16_C( 23073), -INT16_C( 17919),  INT16_C( 31763) },
      {  INT16_C( 23646),  INT16_C(  3091),  INT16_C(  6825),  INT16_C(  1340), -INT16_C( 20982),  INT16_C( 23073),  INT16_C( 17919), -INT16_C( 31763) } },
    { { -INT16_C( 16682), -INT16_C( 24723),  INT16_C( 27785), -INT16_C( 17615), -INT16_C( 32180),  INT16_C( 22047),  INT16_C( 17250),  INT16_C(  1205) },
      {  INT16_C( 16682),  INT16_C( 24723), -INT16_C( 27785),  INT16_C( 17615),  INT16_C( 32180), -INT16_C( 22047), -INT16_C( 17250), -INT16_C(  1205) } },
    { { -INT16_C( 23834),  INT16_C( 15863), -INT16_C( 17528),  INT16_C( 32311),  INT16_C(  5644),  INT16_C(  3363),  INT16_C( 14288), -INT16_C( 22646) },
      {  INT16_C( 23834), -INT16_C( 15863),  INT16_C( 17528), -INT16_C( 32311), -INT16_C(  5644), -INT16_C(  3363), -INT16_C( 14288),  INT16_C( 22646) } },
    { { -INT16_C(  2059),  INT16_C( 32326),  INT16_C( 30564), -INT16_C( 20423),  INT16_C( 22778),  INT16_C( 23558), -INT16_C( 17509), -INT16_C( 32416) },
      {  INT16_C(  2059), -INT16_C( 32326), -INT16_C( 30564),  INT16_C( 20423), -INT16_C( 22778), -INT16_C( 23558),  INT16_C( 17509),  INT16_C( 32416) } },
    { {  INT16_C( 22366), -INT16_C(  6466), -INT16_C(  2542),  INT16_C(  7780), -INT16_C( 30708), -INT16_C(  8916), -INT16_C( 18753), -INT16_C( 19324) },
      { -INT16_C( 22366),  INT16_C(  6466),  INT16_C(  2542), -INT16_C(  7780),  INT16_C( 30708),  INT16_C(  8916),  INT16_C( 18753),  INT16_C( 19324) } },
    { { -INT16_C( 13651),  INT16_C(  4402),  INT16_C( 27714),  INT16_C( 15554), -INT16_C( 14140),  INT16_C( 24728), -INT16_C(  1916), -INT16_C(  7455) },
      {  INT16_C( 13651), -INT16_C(  4402), -INT16_C( 27714), -INT16_C( 15554),  INT16_C( 14140), -INT16_C( 24728),  INT16_C(  1916),  INT16_C(  7455) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vnegq_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vnegq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vnegq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1274343554), -INT32_C(  1647935950),  INT32_C(   941518839), -INT32_C(   809119283) },
      { -INT32_C(  1274343554),  INT32_C(  1647935950), -INT32_C(   941518839),  INT32_C(   809119283) } },
    { {  INT32_C(  2018801436), -INT32_C(  1506414198),  INT32_C(  1466099323), -INT32_C(   356289944) },
      { -INT32_C(  2018801436),  INT32_C(  1506414198), -INT32_C(  1466099323),  INT32_C(   356289944) } },
    { { -INT32_C(  1791576221),  INT32_C(   758316085),  INT32_C(   946163819),  INT32_C(  1023879713) },
      {  INT32_C(  1791576221), -INT32_C(   758316085), -INT32_C(   946163819), -INT32_C(  1023879713) } },
    { {  INT32_C(   733371297), -INT32_C(   925766835),  INT32_C(   958411985),  INT32_C(   153412518) },
      { -INT32_C(   733371297),  INT32_C(   925766835), -INT32_C(   958411985), -INT32_C(   153412518) } },
    { { -INT32_C(   794928485), -INT32_C(  1040330666),  INT32_C(  1106862624),  INT32_C(   763297932) },
      {  INT32_C(   794928485),  INT32_C(  1040330666), -INT32_C(  1106862624), -INT32_C(   763297932) } },
    { { -INT32_C(  1470614181), -INT32_C(   244241888),  INT32_C(    69964126),  INT32_C(   252596084) },
      {  INT32_C(  1470614181),  INT32_C(   244241888), -INT32_C(    69964126), -INT32_C(   252596084) } },
    { { -INT32_C(     2052951), -INT32_C(  1648304771), -INT32_C(   857753280),  INT32_C(   351952569) },
      {  INT32_C(     2052951),  INT32_C(  1648304771),  INT32_C(   857753280), -INT32_C(   351952569) } },
    { { -INT32_C(  1279438189), -INT32_C(   626774404),  INT32_C(   870305727), -INT32_C(   951849698) },
      {  INT32_C(  1279438189),  INT32_C(   626774404), -INT32_C(   870305727),  INT32_C(   951849698) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t r = simde_vnegq_s32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vnegq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vnegq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 1379776353572449913),  INT64_C( 8647865240165635373) },
      { -INT64_C( 1379776353572449913), -INT64_C( 8647865240165635373) } },
    { { -INT64_C( 3642568412225199825),  INT64_C( 3250626639892679639) },
      {  INT64_C( 3642568412225199825), -INT64_C( 3250626639892679639) } },
    { {  INT64_C( 7446088706595571705),  INT64_C( 7799815905998854696) },
      { -INT64_C( 7446088706595571705), -INT64_C( 7799815905998854696) } },
    { {  INT64_C( 6324714693310316964), -INT64_C( 8983753774972534927) },
      { -INT64_C( 6324714693310316964),  INT64_C( 8983753774972534927) } },
    { { -INT64_C(  345903249401511790), -INT64_C( 2549318626993654539) },
      {  INT64_C(  345903249401511790),  INT64_C( 2549318626993654539) } },
    { {  INT64_C( 7735102754277036929),  INT64_C( 7252734741606074265) },
      { -INT64_C( 7735102754277036929), -INT64_C( 7252734741606074265) } },
    { {  INT64_C( 8913296042769804516), -INT64_C(  852502546803166441) },
      { -INT64_C( 8913296042769804516),  INT64_C(  852502546803166441) } },
    { {  INT64_C( 3658134118366314336),  INT64_C( 2020704703068067284) },
      { -INT64_C( 3658134118366314336), -INT64_C( 2020704703068067284) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t r = simde_vnegq_s64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vnegq_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vneg_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vneg_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vneg_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vneg_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vneg_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vneg_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vnegq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vnegq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vnegq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vnegq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vnegq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vnegq_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
