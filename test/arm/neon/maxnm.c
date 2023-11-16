#define SIMDE_TEST_ARM_NEON_INSN maxnm

#include "test-neon.h"
#include "../../../simde/arm/neon/maxnm.h"

static int
test_simde_vmaxnmh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 b;
    simde_float16 r;
  } test_vec[] = {
    {    SIMDE_FLOAT16_VALUE(    22.669),
         SIMDE_FLOAT16_VALUE(    -3.636),
         SIMDE_FLOAT16_VALUE(    22.669) },
    {    SIMDE_FLOAT16_VALUE(    24.081),
         SIMDE_FLOAT16_VALUE(   -20.730),
         SIMDE_FLOAT16_VALUE(    24.081) },
    {    SIMDE_FLOAT16_VALUE(    29.054),
         SIMDE_FLOAT16_VALUE(    -1.342),
         SIMDE_FLOAT16_VALUE(    29.054) },
    {    SIMDE_FLOAT16_VALUE(    -9.109),
         SIMDE_FLOAT16_VALUE(   -21.666),
         SIMDE_FLOAT16_VALUE(    -9.109) },
    {    SIMDE_FLOAT16_VALUE(    13.811),
         SIMDE_FLOAT16_VALUE(    29.651),
         SIMDE_FLOAT16_VALUE(    29.651) },
    {    SIMDE_FLOAT16_VALUE(    17.987),
         SIMDE_FLOAT16_VALUE(     5.485),
         SIMDE_FLOAT16_VALUE(    17.987) },
    {    SIMDE_FLOAT16_VALUE(    16.726),
         SIMDE_FLOAT16_VALUE(   -11.194),
         SIMDE_FLOAT16_VALUE(    16.726) },
    {    SIMDE_FLOAT16_VALUE(   -29.003),
         SIMDE_FLOAT16_VALUE(    10.718),
         SIMDE_FLOAT16_VALUE(    10.718) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    simde_float16_t b = test_vec[i].b;
    simde_float16_t r = simde_vmaxnmh_f16(a, b);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t b = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vmaxnmh_f16(a, b);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnm_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   656.90),            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   116.96) },
      { SIMDE_FLOAT16_VALUE(   427.79),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -999.94) },
      { SIMDE_FLOAT16_VALUE(   427.79), SIMDE_FLOAT16_VALUE(   656.90),            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   116.96) } },
    #endif
    { {  SIMDE_FLOAT16_VALUE(   -25.980),  SIMDE_FLOAT16_VALUE(    16.740),  SIMDE_FLOAT16_VALUE(    -6.454),  SIMDE_FLOAT16_VALUE(    -6.025) },
      {  SIMDE_FLOAT16_VALUE(    17.454),  SIMDE_FLOAT16_VALUE(     9.186),  SIMDE_FLOAT16_VALUE(   -29.222),  SIMDE_FLOAT16_VALUE(    -8.154) },
      {  SIMDE_FLOAT16_VALUE(    17.454),  SIMDE_FLOAT16_VALUE(    16.740),  SIMDE_FLOAT16_VALUE(    -6.454),  SIMDE_FLOAT16_VALUE(    -6.025) } },
    { {  SIMDE_FLOAT16_VALUE(   -15.257),  SIMDE_FLOAT16_VALUE(    29.005),  SIMDE_FLOAT16_VALUE(    -1.773),  SIMDE_FLOAT16_VALUE(   -11.960) },
      {  SIMDE_FLOAT16_VALUE(   -17.232),  SIMDE_FLOAT16_VALUE(    -7.328),  SIMDE_FLOAT16_VALUE(    27.941),  SIMDE_FLOAT16_VALUE(   -14.552) },
      {  SIMDE_FLOAT16_VALUE(   -15.257),  SIMDE_FLOAT16_VALUE(    29.005),  SIMDE_FLOAT16_VALUE(    27.941),  SIMDE_FLOAT16_VALUE(   -11.960) } },
    { {  SIMDE_FLOAT16_VALUE(   -13.227),  SIMDE_FLOAT16_VALUE(    22.102),  SIMDE_FLOAT16_VALUE(    21.166),  SIMDE_FLOAT16_VALUE(    -1.941) },
      {  SIMDE_FLOAT16_VALUE(     2.455),  SIMDE_FLOAT16_VALUE(    -5.662),  SIMDE_FLOAT16_VALUE(     5.438),  SIMDE_FLOAT16_VALUE(     5.248) },
      {  SIMDE_FLOAT16_VALUE(     2.455),  SIMDE_FLOAT16_VALUE(    22.102),  SIMDE_FLOAT16_VALUE(    21.166),  SIMDE_FLOAT16_VALUE(     5.248) } },
    { {  SIMDE_FLOAT16_VALUE(    11.724),  SIMDE_FLOAT16_VALUE(     7.377),  SIMDE_FLOAT16_VALUE(     8.682),  SIMDE_FLOAT16_VALUE(   -13.420) },
      {  SIMDE_FLOAT16_VALUE(    14.385),  SIMDE_FLOAT16_VALUE(   -25.913),  SIMDE_FLOAT16_VALUE(   -17.065),  SIMDE_FLOAT16_VALUE(     7.632) },
      {  SIMDE_FLOAT16_VALUE(    14.385),  SIMDE_FLOAT16_VALUE(     7.377),  SIMDE_FLOAT16_VALUE(     8.682),  SIMDE_FLOAT16_VALUE(     7.632) } },
    { {  SIMDE_FLOAT16_VALUE(   -16.400),  SIMDE_FLOAT16_VALUE(   -15.337),  SIMDE_FLOAT16_VALUE(     7.331),  SIMDE_FLOAT16_VALUE(    25.952) },
      {  SIMDE_FLOAT16_VALUE(     4.175),  SIMDE_FLOAT16_VALUE(    13.138),  SIMDE_FLOAT16_VALUE(    -6.213),  SIMDE_FLOAT16_VALUE(   -16.438) },
      {  SIMDE_FLOAT16_VALUE(     4.175),  SIMDE_FLOAT16_VALUE(    13.138),  SIMDE_FLOAT16_VALUE(     7.331),  SIMDE_FLOAT16_VALUE(    25.952) } },
    { {  SIMDE_FLOAT16_VALUE(     2.486),  SIMDE_FLOAT16_VALUE(   -13.489),  SIMDE_FLOAT16_VALUE(   -13.585),  SIMDE_FLOAT16_VALUE(   -20.019) },
      {  SIMDE_FLOAT16_VALUE(    -6.497),  SIMDE_FLOAT16_VALUE(    15.926),  SIMDE_FLOAT16_VALUE(   -12.326),  SIMDE_FLOAT16_VALUE(   -14.726) },
      {  SIMDE_FLOAT16_VALUE(     2.486),  SIMDE_FLOAT16_VALUE(    15.926),  SIMDE_FLOAT16_VALUE(   -12.326),  SIMDE_FLOAT16_VALUE(   -14.726) } },
    { {  SIMDE_FLOAT16_VALUE(    -3.541),  SIMDE_FLOAT16_VALUE(   -14.921),  SIMDE_FLOAT16_VALUE(   -22.262),  SIMDE_FLOAT16_VALUE(    -5.039) },
      {  SIMDE_FLOAT16_VALUE(    18.439),  SIMDE_FLOAT16_VALUE(    17.130),  SIMDE_FLOAT16_VALUE(     2.910),  SIMDE_FLOAT16_VALUE(   -16.599) },
      {  SIMDE_FLOAT16_VALUE(    18.439),  SIMDE_FLOAT16_VALUE(    17.130),  SIMDE_FLOAT16_VALUE(     2.910),  SIMDE_FLOAT16_VALUE(    -5.039) } },
    { {  SIMDE_FLOAT16_VALUE(   -17.337),  SIMDE_FLOAT16_VALUE(   -26.677),  SIMDE_FLOAT16_VALUE(     4.324),  SIMDE_FLOAT16_VALUE(    -6.462) },
      {  SIMDE_FLOAT16_VALUE(    22.846),  SIMDE_FLOAT16_VALUE(   -27.356),  SIMDE_FLOAT16_VALUE(     4.101),  SIMDE_FLOAT16_VALUE(     2.145) },
      {  SIMDE_FLOAT16_VALUE(    22.846),  SIMDE_FLOAT16_VALUE(   -26.677),  SIMDE_FLOAT16_VALUE(     4.324),  SIMDE_FLOAT16_VALUE(     2.145) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r = simde_vmaxnm_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vmaxnm_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   -21.583),  SIMDE_FLOAT16_VALUE(    -7.138),  SIMDE_FLOAT16_VALUE(   -20.999),  SIMDE_FLOAT16_VALUE(     0.588),
         SIMDE_FLOAT16_VALUE(     8.861),  SIMDE_FLOAT16_VALUE(    -8.186),  SIMDE_FLOAT16_VALUE(   -18.751),  SIMDE_FLOAT16_VALUE(    21.034) },
      {  SIMDE_FLOAT16_VALUE(   -23.071),  SIMDE_FLOAT16_VALUE(   -18.719),  SIMDE_FLOAT16_VALUE(   -17.361),  SIMDE_FLOAT16_VALUE(    24.630),
         SIMDE_FLOAT16_VALUE(    25.766),  SIMDE_FLOAT16_VALUE(   -12.480),  SIMDE_FLOAT16_VALUE(   -28.125),  SIMDE_FLOAT16_VALUE(     2.947) },
      {  SIMDE_FLOAT16_VALUE(   -21.583),  SIMDE_FLOAT16_VALUE(    -7.138),  SIMDE_FLOAT16_VALUE(   -17.361),  SIMDE_FLOAT16_VALUE(    24.630),
         SIMDE_FLOAT16_VALUE(    25.766),  SIMDE_FLOAT16_VALUE(    -8.186),  SIMDE_FLOAT16_VALUE(   -18.751),  SIMDE_FLOAT16_VALUE(    21.034) } },
    { {  SIMDE_FLOAT16_VALUE(   -12.403),  SIMDE_FLOAT16_VALUE(   -17.901),  SIMDE_FLOAT16_VALUE(    28.717),  SIMDE_FLOAT16_VALUE(    12.424),
         SIMDE_FLOAT16_VALUE(    -7.521),  SIMDE_FLOAT16_VALUE(     6.656),  SIMDE_FLOAT16_VALUE(    24.788),  SIMDE_FLOAT16_VALUE(    29.846) },
      {  SIMDE_FLOAT16_VALUE(    20.282),  SIMDE_FLOAT16_VALUE(     7.360),  SIMDE_FLOAT16_VALUE(    24.370),  SIMDE_FLOAT16_VALUE(   -13.416),
         SIMDE_FLOAT16_VALUE(    19.501),  SIMDE_FLOAT16_VALUE(    21.305),  SIMDE_FLOAT16_VALUE(   -11.023),  SIMDE_FLOAT16_VALUE(   -23.836) },
      {  SIMDE_FLOAT16_VALUE(    20.282),  SIMDE_FLOAT16_VALUE(     7.360),  SIMDE_FLOAT16_VALUE(    28.717),  SIMDE_FLOAT16_VALUE(    12.424),
         SIMDE_FLOAT16_VALUE(    19.501),  SIMDE_FLOAT16_VALUE(    21.305),  SIMDE_FLOAT16_VALUE(    24.788),  SIMDE_FLOAT16_VALUE(    29.846) } },
    { {  SIMDE_FLOAT16_VALUE(    -0.327),  SIMDE_FLOAT16_VALUE(    11.486),  SIMDE_FLOAT16_VALUE(    16.909),  SIMDE_FLOAT16_VALUE(   -27.110),
         SIMDE_FLOAT16_VALUE(    -7.040),  SIMDE_FLOAT16_VALUE(    29.224),  SIMDE_FLOAT16_VALUE(    24.408),  SIMDE_FLOAT16_VALUE(     7.439) },
      {  SIMDE_FLOAT16_VALUE(    24.096),  SIMDE_FLOAT16_VALUE(    19.131),  SIMDE_FLOAT16_VALUE(   -24.124),  SIMDE_FLOAT16_VALUE(    -5.706),
         SIMDE_FLOAT16_VALUE(    23.210),  SIMDE_FLOAT16_VALUE(     8.063),  SIMDE_FLOAT16_VALUE(    19.255),  SIMDE_FLOAT16_VALUE(   -29.353) },
      {  SIMDE_FLOAT16_VALUE(    24.096),  SIMDE_FLOAT16_VALUE(    19.131),  SIMDE_FLOAT16_VALUE(    16.909),  SIMDE_FLOAT16_VALUE(    -5.706),
         SIMDE_FLOAT16_VALUE(    23.210),  SIMDE_FLOAT16_VALUE(    29.224),  SIMDE_FLOAT16_VALUE(    24.408),  SIMDE_FLOAT16_VALUE(     7.439) } },
    { {  SIMDE_FLOAT16_VALUE(   -26.012),  SIMDE_FLOAT16_VALUE(     3.671),  SIMDE_FLOAT16_VALUE(    -3.289),  SIMDE_FLOAT16_VALUE(    27.279),
         SIMDE_FLOAT16_VALUE(     4.971),  SIMDE_FLOAT16_VALUE(    11.384),  SIMDE_FLOAT16_VALUE(   -17.676),  SIMDE_FLOAT16_VALUE(    22.100) },
      {  SIMDE_FLOAT16_VALUE(    -4.031),  SIMDE_FLOAT16_VALUE(    -9.020),  SIMDE_FLOAT16_VALUE(   -21.682),  SIMDE_FLOAT16_VALUE(    14.454),
         SIMDE_FLOAT16_VALUE(     9.557),  SIMDE_FLOAT16_VALUE(    24.593),  SIMDE_FLOAT16_VALUE(     5.929),  SIMDE_FLOAT16_VALUE(     9.477) },
      {  SIMDE_FLOAT16_VALUE(    -4.031),  SIMDE_FLOAT16_VALUE(     3.671),  SIMDE_FLOAT16_VALUE(    -3.289),  SIMDE_FLOAT16_VALUE(    27.279),
         SIMDE_FLOAT16_VALUE(     9.557),  SIMDE_FLOAT16_VALUE(    24.593),  SIMDE_FLOAT16_VALUE(     5.929),  SIMDE_FLOAT16_VALUE(    22.100) } },
    { {  SIMDE_FLOAT16_VALUE(     8.640),  SIMDE_FLOAT16_VALUE(    28.599),  SIMDE_FLOAT16_VALUE(    27.486),  SIMDE_FLOAT16_VALUE(   -14.189),
         SIMDE_FLOAT16_VALUE(     1.968),  SIMDE_FLOAT16_VALUE(   -28.490),  SIMDE_FLOAT16_VALUE(    14.838),  SIMDE_FLOAT16_VALUE(   -10.444) },
      {  SIMDE_FLOAT16_VALUE(    25.445),  SIMDE_FLOAT16_VALUE(     9.395),  SIMDE_FLOAT16_VALUE(   -27.952),  SIMDE_FLOAT16_VALUE(   -28.338),
         SIMDE_FLOAT16_VALUE(   -15.183),  SIMDE_FLOAT16_VALUE(   -12.439),  SIMDE_FLOAT16_VALUE(   -20.308),  SIMDE_FLOAT16_VALUE(     8.934) },
      {  SIMDE_FLOAT16_VALUE(    25.445),  SIMDE_FLOAT16_VALUE(    28.599),  SIMDE_FLOAT16_VALUE(    27.486),  SIMDE_FLOAT16_VALUE(   -14.189),
         SIMDE_FLOAT16_VALUE(     1.968),  SIMDE_FLOAT16_VALUE(   -12.439),  SIMDE_FLOAT16_VALUE(    14.838),  SIMDE_FLOAT16_VALUE(     8.934) } },
    { {  SIMDE_FLOAT16_VALUE(    11.626),  SIMDE_FLOAT16_VALUE(    13.984),  SIMDE_FLOAT16_VALUE(   -11.526),  SIMDE_FLOAT16_VALUE(    -0.656),
         SIMDE_FLOAT16_VALUE(   -29.714),  SIMDE_FLOAT16_VALUE(     5.498),  SIMDE_FLOAT16_VALUE(    -8.856),  SIMDE_FLOAT16_VALUE(     3.067) },
      {  SIMDE_FLOAT16_VALUE(    28.682),  SIMDE_FLOAT16_VALUE(    -4.338),  SIMDE_FLOAT16_VALUE(    29.561),  SIMDE_FLOAT16_VALUE(   -15.500),
         SIMDE_FLOAT16_VALUE(    -9.637),  SIMDE_FLOAT16_VALUE(   -12.277),  SIMDE_FLOAT16_VALUE(   -13.303),  SIMDE_FLOAT16_VALUE(    24.029) },
      {  SIMDE_FLOAT16_VALUE(    28.682),  SIMDE_FLOAT16_VALUE(    13.984),  SIMDE_FLOAT16_VALUE(    29.561),  SIMDE_FLOAT16_VALUE(    -0.656),
         SIMDE_FLOAT16_VALUE(    -9.637),  SIMDE_FLOAT16_VALUE(     5.498),  SIMDE_FLOAT16_VALUE(    -8.856),  SIMDE_FLOAT16_VALUE(    24.029) } },
    { {  SIMDE_FLOAT16_VALUE(    22.917),  SIMDE_FLOAT16_VALUE(     6.279),  SIMDE_FLOAT16_VALUE(   -27.167),  SIMDE_FLOAT16_VALUE(    28.499),
         SIMDE_FLOAT16_VALUE(   -11.519),  SIMDE_FLOAT16_VALUE(    21.428),  SIMDE_FLOAT16_VALUE(    10.977),  SIMDE_FLOAT16_VALUE(    28.875) },
      {  SIMDE_FLOAT16_VALUE(   -18.118),  SIMDE_FLOAT16_VALUE(   -15.512),  SIMDE_FLOAT16_VALUE(    24.351),  SIMDE_FLOAT16_VALUE(   -22.064),
         SIMDE_FLOAT16_VALUE(     3.656),  SIMDE_FLOAT16_VALUE(    25.202),  SIMDE_FLOAT16_VALUE(    14.732),  SIMDE_FLOAT16_VALUE(    14.168) },
      {  SIMDE_FLOAT16_VALUE(    22.917),  SIMDE_FLOAT16_VALUE(     6.279),  SIMDE_FLOAT16_VALUE(    24.351),  SIMDE_FLOAT16_VALUE(    28.499),
         SIMDE_FLOAT16_VALUE(     3.656),  SIMDE_FLOAT16_VALUE(    25.202),  SIMDE_FLOAT16_VALUE(    14.732),  SIMDE_FLOAT16_VALUE(    28.875) } },
    { {  SIMDE_FLOAT16_VALUE(    21.878),  SIMDE_FLOAT16_VALUE(    16.761),  SIMDE_FLOAT16_VALUE(    19.498),  SIMDE_FLOAT16_VALUE(   -19.451),
         SIMDE_FLOAT16_VALUE(    19.336),  SIMDE_FLOAT16_VALUE(    24.491),  SIMDE_FLOAT16_VALUE(    -4.276),  SIMDE_FLOAT16_VALUE(   -15.531) },
      {  SIMDE_FLOAT16_VALUE(     1.810),  SIMDE_FLOAT16_VALUE(   -28.532),  SIMDE_FLOAT16_VALUE(    10.612),  SIMDE_FLOAT16_VALUE(    -8.930),
         SIMDE_FLOAT16_VALUE(   -19.062),  SIMDE_FLOAT16_VALUE(   -21.009),  SIMDE_FLOAT16_VALUE(   -10.135),  SIMDE_FLOAT16_VALUE(   -10.459) },
      {  SIMDE_FLOAT16_VALUE(    21.878),  SIMDE_FLOAT16_VALUE(    16.761),  SIMDE_FLOAT16_VALUE(    19.498),  SIMDE_FLOAT16_VALUE(    -8.930),
         SIMDE_FLOAT16_VALUE(    19.336),  SIMDE_FLOAT16_VALUE(    24.491),  SIMDE_FLOAT16_VALUE(    -4.276),  SIMDE_FLOAT16_VALUE(   -10.459) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vmaxnmq_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vmaxnmq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnm_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   656.90) },
      { SIMDE_FLOAT32_C(   427.79),            SIMDE_MATH_NANF },
      { SIMDE_FLOAT32_C(   427.79), SIMDE_FLOAT32_C(   656.90) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   116.96) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -999.94) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   116.96) } },
    #endif
    { { SIMDE_FLOAT32_C(  -619.20), SIMDE_FLOAT32_C(  -413.47) },
      { SIMDE_FLOAT32_C(   871.28), SIMDE_FLOAT32_C(  -660.33) },
      { SIMDE_FLOAT32_C(   871.28), SIMDE_FLOAT32_C(  -413.47) } },
    { { SIMDE_FLOAT32_C(   422.55), SIMDE_FLOAT32_C(   160.51) },
      { SIMDE_FLOAT32_C(   148.88), SIMDE_FLOAT32_C(   905.13) },
      { SIMDE_FLOAT32_C(   422.55), SIMDE_FLOAT32_C(   905.13) } },
    { { SIMDE_FLOAT32_C(  -605.53), SIMDE_FLOAT32_C(  -971.47) },
      { SIMDE_FLOAT32_C(   182.75), SIMDE_FLOAT32_C(  -737.07) },
      { SIMDE_FLOAT32_C(   182.75), SIMDE_FLOAT32_C(  -737.07) } },
    { { SIMDE_FLOAT32_C(  -182.06), SIMDE_FLOAT32_C(  -678.54) },
      { SIMDE_FLOAT32_C(   165.68), SIMDE_FLOAT32_C(   413.12) },
      { SIMDE_FLOAT32_C(   165.68), SIMDE_FLOAT32_C(   413.12) } },
    { { SIMDE_FLOAT32_C(    20.28), SIMDE_FLOAT32_C(  -770.49) },
      { SIMDE_FLOAT32_C(   647.00), SIMDE_FLOAT32_C(  -632.40) },
      { SIMDE_FLOAT32_C(   647.00), SIMDE_FLOAT32_C(  -632.40) } },
    { { SIMDE_FLOAT32_C(   949.17), SIMDE_FLOAT32_C(   616.00) },
      { SIMDE_FLOAT32_C(  -967.88), SIMDE_FLOAT32_C(  -301.85) },
      { SIMDE_FLOAT32_C(   949.17), SIMDE_FLOAT32_C(   616.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vmaxnm_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32_t values[8 * 2 * sizeof(simde_float32x2_t)];
  simde_test_arm_neon_random_f32x2_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_extract_f32x2(i, 2, 0, values);
    simde_float32x2_t b = simde_test_arm_neon_random_extract_f32x2(i, 2, 1, values);
    simde_float32x2_t r = simde_vmaxnm_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnm_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(   169.64) },
      { SIMDE_FLOAT64_C(   169.64) } },
    { { SIMDE_FLOAT64_C(  -986.47) },
      {             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(  -986.47) } },
    { {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN } },
    #endif
    { { SIMDE_FLOAT64_C(   827.71) },
      { SIMDE_FLOAT64_C(   191.90) },
      { SIMDE_FLOAT64_C(   827.71) } },
    { { SIMDE_FLOAT64_C(  -275.70) },
      { SIMDE_FLOAT64_C(   295.23) },
      { SIMDE_FLOAT64_C(   295.23) } },
    { { SIMDE_FLOAT64_C(   188.72) },
      { SIMDE_FLOAT64_C(   429.15) },
      { SIMDE_FLOAT64_C(   429.15) } },
    { { SIMDE_FLOAT64_C(  -147.66) },
      { SIMDE_FLOAT64_C(   487.54) },
      { SIMDE_FLOAT64_C(   487.54) } },
    { { SIMDE_FLOAT64_C(  -528.84) },
      { SIMDE_FLOAT64_C(  -797.49) },
      { SIMDE_FLOAT64_C(  -528.84) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vmaxnm_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64_t values[8 * 2 * sizeof(simde_float64x1_t)];
  simde_test_arm_neon_random_f64x1_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_extract_f64x1(i, 2, 0, values);
    simde_float64x1_t b = simde_test_arm_neon_random_extract_f64x1(i, 2, 1, values);
    simde_float64x1_t r = simde_vmaxnm_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -830.15),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   116.42) },
      { SIMDE_FLOAT32_C(  -786.61),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   704.38) },
      { SIMDE_FLOAT32_C(  -786.61), SIMDE_FLOAT32_C(  -830.15),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   704.38) } },
    #endif
    { { SIMDE_FLOAT32_C(    42.56), SIMDE_FLOAT32_C(  -762.07), SIMDE_FLOAT32_C(   243.80), SIMDE_FLOAT32_C(   127.20) },
      { SIMDE_FLOAT32_C(  -554.99), SIMDE_FLOAT32_C(   818.92), SIMDE_FLOAT32_C(  -693.45), SIMDE_FLOAT32_C(   417.65) },
      { SIMDE_FLOAT32_C(    42.56), SIMDE_FLOAT32_C(   818.92), SIMDE_FLOAT32_C(   243.80), SIMDE_FLOAT32_C(   417.65) } },
    { { SIMDE_FLOAT32_C(   -84.44), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(   451.21), SIMDE_FLOAT32_C(    71.41) },
      { SIMDE_FLOAT32_C(  -104.53), SIMDE_FLOAT32_C(   615.74), SIMDE_FLOAT32_C(  -465.38), SIMDE_FLOAT32_C(    92.29) },
      { SIMDE_FLOAT32_C(   -84.44), SIMDE_FLOAT32_C(   615.74), SIMDE_FLOAT32_C(   451.21), SIMDE_FLOAT32_C(    92.29) } },
    { { SIMDE_FLOAT32_C(  -599.78), SIMDE_FLOAT32_C(   592.36), SIMDE_FLOAT32_C(  -378.07), SIMDE_FLOAT32_C(  -109.06) },
      { SIMDE_FLOAT32_C(   386.28), SIMDE_FLOAT32_C(  -742.91), SIMDE_FLOAT32_C(   270.77), SIMDE_FLOAT32_C(   106.07) },
      { SIMDE_FLOAT32_C(   386.28), SIMDE_FLOAT32_C(   592.36), SIMDE_FLOAT32_C(   270.77), SIMDE_FLOAT32_C(   106.07) } },
    { { SIMDE_FLOAT32_C(  -573.06), SIMDE_FLOAT32_C(   931.15), SIMDE_FLOAT32_C(  -777.52), SIMDE_FLOAT32_C(  -359.67) },
      { SIMDE_FLOAT32_C(  -618.04), SIMDE_FLOAT32_C(  -590.04), SIMDE_FLOAT32_C(  -655.29), SIMDE_FLOAT32_C(   424.52) },
      { SIMDE_FLOAT32_C(  -573.06), SIMDE_FLOAT32_C(   931.15), SIMDE_FLOAT32_C(  -655.29), SIMDE_FLOAT32_C(   424.52) } },
    { { SIMDE_FLOAT32_C(  -352.11), SIMDE_FLOAT32_C(   588.52), SIMDE_FLOAT32_C(  -448.29), SIMDE_FLOAT32_C(    92.89) },
      { SIMDE_FLOAT32_C(   407.44), SIMDE_FLOAT32_C(  -141.74), SIMDE_FLOAT32_C(  -489.46), SIMDE_FLOAT32_C(  -677.00) },
      { SIMDE_FLOAT32_C(   407.44), SIMDE_FLOAT32_C(   588.52), SIMDE_FLOAT32_C(  -448.29), SIMDE_FLOAT32_C(    92.89) } },
    { { SIMDE_FLOAT32_C(  -821.73), SIMDE_FLOAT32_C(   961.75), SIMDE_FLOAT32_C(   394.41), SIMDE_FLOAT32_C(    73.73) },
      { SIMDE_FLOAT32_C(   577.49), SIMDE_FLOAT32_C(   929.03), SIMDE_FLOAT32_C(  -833.98), SIMDE_FLOAT32_C(   977.71) },
      { SIMDE_FLOAT32_C(   577.49), SIMDE_FLOAT32_C(   961.75), SIMDE_FLOAT32_C(   394.41), SIMDE_FLOAT32_C(   977.71) } },
    { { SIMDE_FLOAT32_C(   521.39), SIMDE_FLOAT32_C(  -212.06), SIMDE_FLOAT32_C(  -131.35), SIMDE_FLOAT32_C(   -92.34) },
      { SIMDE_FLOAT32_C(    45.03), SIMDE_FLOAT32_C(  -860.58), SIMDE_FLOAT32_C(  -986.27), SIMDE_FLOAT32_C(   471.98) },
      { SIMDE_FLOAT32_C(   521.39), SIMDE_FLOAT32_C(  -212.06), SIMDE_FLOAT32_C(  -131.35), SIMDE_FLOAT32_C(   471.98) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vmaxnmq_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32_t values[8 * 2 * sizeof(simde_float32x4_t)];
  simde_test_arm_neon_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_extract_f32x4(i, 2, 0, values);
    simde_float32x4_t b = simde_test_arm_neon_random_extract_f32x4(i, 2, 1, values);
    simde_float32x4_t r = simde_vmaxnmq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
        { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -182.58) },
      { SIMDE_FLOAT64_C(   743.82),             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(   743.82), SIMDE_FLOAT64_C(  -182.58) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   493.92) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   934.94) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   934.94) } },
    #endif
    { { SIMDE_FLOAT64_C(  -559.75), SIMDE_FLOAT64_C(  -168.42) },
      { SIMDE_FLOAT64_C(   193.83), SIMDE_FLOAT64_C(  -311.43) },
      { SIMDE_FLOAT64_C(   193.83), SIMDE_FLOAT64_C(  -168.42) } },
    { { SIMDE_FLOAT64_C(   685.60), SIMDE_FLOAT64_C(   642.39) },
      { SIMDE_FLOAT64_C(  -129.77), SIMDE_FLOAT64_C(  -575.43) },
      { SIMDE_FLOAT64_C(   685.60), SIMDE_FLOAT64_C(   642.39) } },
    { { SIMDE_FLOAT64_C(   166.90), SIMDE_FLOAT64_C(  -869.88) },
      { SIMDE_FLOAT64_C(    87.77), SIMDE_FLOAT64_C(  -554.15) },
      { SIMDE_FLOAT64_C(   166.90), SIMDE_FLOAT64_C(  -554.15) } },
    { { SIMDE_FLOAT64_C(  -667.35), SIMDE_FLOAT64_C(  -294.71) },
      { SIMDE_FLOAT64_C(   134.11), SIMDE_FLOAT64_C(   615.74) },
      { SIMDE_FLOAT64_C(   134.11), SIMDE_FLOAT64_C(   615.74) } },
    { { SIMDE_FLOAT64_C(   -85.63), SIMDE_FLOAT64_C(  -649.42) },
      { SIMDE_FLOAT64_C(  -536.78), SIMDE_FLOAT64_C(   843.96) },
      { SIMDE_FLOAT64_C(   -85.63), SIMDE_FLOAT64_C(   843.96) } },
    { { SIMDE_FLOAT64_C(   349.79), SIMDE_FLOAT64_C(   234.11) },
      { SIMDE_FLOAT64_C(  -713.81), SIMDE_FLOAT64_C(   557.65) },
      { SIMDE_FLOAT64_C(   349.79), SIMDE_FLOAT64_C(   557.65) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vmaxnmq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64_t values[8 * 2 * sizeof(simde_float64x2_t)];
  simde_test_arm_neon_random_f64x2_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_extract_f64x2(i, 2, 0, values);
    simde_float64x2_t b = simde_test_arm_neon_random_extract_f64x2(i, 2, 1, values);
    simde_float64x2_t r = simde_vmaxnmq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnm_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnm_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnm_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
