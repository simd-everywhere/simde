#define SIMDE_TEST_ARM_NEON_INSN div

#include "test-neon.h"
#include "../../../simde/arm/neon/div.h"

static int
test_simde_vdivh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 b;
    simde_float16 r;
  } test_vec[] = {
    {    SIMDE_FLOAT16_VALUE(     2.325),
         SIMDE_FLOAT16_VALUE(   -10.769),
         SIMDE_FLOAT16_VALUE(    -0.216) },
    {    SIMDE_FLOAT16_VALUE(     4.607),
         SIMDE_FLOAT16_VALUE(    29.715),
         SIMDE_FLOAT16_VALUE(     0.155) },
    {    SIMDE_FLOAT16_VALUE(    18.117),
         SIMDE_FLOAT16_VALUE(   -14.474),
         SIMDE_FLOAT16_VALUE(    -1.252) },
    {    SIMDE_FLOAT16_VALUE(    -1.468),
         SIMDE_FLOAT16_VALUE(    -3.245),
         SIMDE_FLOAT16_VALUE(     0.452) },
    {    SIMDE_FLOAT16_VALUE(    12.201),
         SIMDE_FLOAT16_VALUE(   -11.846),
         SIMDE_FLOAT16_VALUE(    -1.030) },
    {    SIMDE_FLOAT16_VALUE(    -4.982),
         SIMDE_FLOAT16_VALUE(   -16.137),
         SIMDE_FLOAT16_VALUE(     0.309) },
    {    SIMDE_FLOAT16_VALUE(   -15.350),
         SIMDE_FLOAT16_VALUE(     6.717),
         SIMDE_FLOAT16_VALUE(    -2.285) },
    {    SIMDE_FLOAT16_VALUE(    -2.674),
         SIMDE_FLOAT16_VALUE(    -9.996),
         SIMDE_FLOAT16_VALUE(     0.268) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a, b, r;

    a = test_vec[i].a;
    b = test_vec[i].b;
    r = simde_vdivh_f16(a, b);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t b = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vdivh_f16(a, b);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdiv_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   -25.796),  SIMDE_FLOAT16_VALUE(    -5.577),  SIMDE_FLOAT16_VALUE(     4.367),  SIMDE_FLOAT16_VALUE(    26.182) },
      {  SIMDE_FLOAT16_VALUE(    -9.883),  SIMDE_FLOAT16_VALUE(    23.736),  SIMDE_FLOAT16_VALUE(    24.238),  SIMDE_FLOAT16_VALUE(    -2.954) },
      {  SIMDE_FLOAT16_VALUE(     2.610),  SIMDE_FLOAT16_VALUE(    -0.235),  SIMDE_FLOAT16_VALUE(     0.180),  SIMDE_FLOAT16_VALUE(    -8.863) } },
    { {  SIMDE_FLOAT16_VALUE(   -13.354),  SIMDE_FLOAT16_VALUE(    12.363),  SIMDE_FLOAT16_VALUE(   -21.668),  SIMDE_FLOAT16_VALUE(    10.893) },
      {  SIMDE_FLOAT16_VALUE(    23.322),  SIMDE_FLOAT16_VALUE(    29.794),  SIMDE_FLOAT16_VALUE(    -0.049),  SIMDE_FLOAT16_VALUE(   -19.513) },
      {  SIMDE_FLOAT16_VALUE(    -0.573),  SIMDE_FLOAT16_VALUE(     0.415),  SIMDE_FLOAT16_VALUE(   442.204),  SIMDE_FLOAT16_VALUE(    -0.558) } },
    { {  SIMDE_FLOAT16_VALUE(    -4.088),  SIMDE_FLOAT16_VALUE(   -19.813),  SIMDE_FLOAT16_VALUE(    10.338),  SIMDE_FLOAT16_VALUE(   -15.387) },
      {  SIMDE_FLOAT16_VALUE(   -11.592),  SIMDE_FLOAT16_VALUE(    24.689),  SIMDE_FLOAT16_VALUE(   -13.897),  SIMDE_FLOAT16_VALUE(   -25.961) },
      {  SIMDE_FLOAT16_VALUE(     0.353),  SIMDE_FLOAT16_VALUE(    -0.803),  SIMDE_FLOAT16_VALUE(    -0.744),  SIMDE_FLOAT16_VALUE(     0.593) } },
    { {  SIMDE_FLOAT16_VALUE(   -21.157),  SIMDE_FLOAT16_VALUE(     4.425),  SIMDE_FLOAT16_VALUE(    15.670),  SIMDE_FLOAT16_VALUE(     9.132) },
      {  SIMDE_FLOAT16_VALUE(   -29.194),  SIMDE_FLOAT16_VALUE(    -6.628),  SIMDE_FLOAT16_VALUE(    29.265),  SIMDE_FLOAT16_VALUE(    29.184) },
      {  SIMDE_FLOAT16_VALUE(     0.725),  SIMDE_FLOAT16_VALUE(    -0.668),  SIMDE_FLOAT16_VALUE(     0.535),  SIMDE_FLOAT16_VALUE(     0.313) } },
    { {  SIMDE_FLOAT16_VALUE(     6.199),  SIMDE_FLOAT16_VALUE(    -1.003),  SIMDE_FLOAT16_VALUE(    21.753),  SIMDE_FLOAT16_VALUE(    -7.614) },
      {  SIMDE_FLOAT16_VALUE(    29.801),  SIMDE_FLOAT16_VALUE(   -15.757),  SIMDE_FLOAT16_VALUE(    26.257),  SIMDE_FLOAT16_VALUE(   -17.038) },
      {  SIMDE_FLOAT16_VALUE(     0.208),  SIMDE_FLOAT16_VALUE(     0.064),  SIMDE_FLOAT16_VALUE(     0.828),  SIMDE_FLOAT16_VALUE(     0.447) } },
    { {  SIMDE_FLOAT16_VALUE(    13.140),  SIMDE_FLOAT16_VALUE(     1.756),  SIMDE_FLOAT16_VALUE(    15.279),  SIMDE_FLOAT16_VALUE(    23.870) },
      {  SIMDE_FLOAT16_VALUE(   -11.891),  SIMDE_FLOAT16_VALUE(   -19.548),  SIMDE_FLOAT16_VALUE(    25.540),  SIMDE_FLOAT16_VALUE(    29.138) },
      {  SIMDE_FLOAT16_VALUE(    -1.105),  SIMDE_FLOAT16_VALUE(    -0.090),  SIMDE_FLOAT16_VALUE(     0.598),  SIMDE_FLOAT16_VALUE(     0.819) } },
    { {  SIMDE_FLOAT16_VALUE(    27.730),  SIMDE_FLOAT16_VALUE(    27.137),  SIMDE_FLOAT16_VALUE(    -5.911),  SIMDE_FLOAT16_VALUE(     1.868) },
      {  SIMDE_FLOAT16_VALUE(    13.164),  SIMDE_FLOAT16_VALUE(     8.517),  SIMDE_FLOAT16_VALUE(   -29.852),  SIMDE_FLOAT16_VALUE(    18.934) },
      {  SIMDE_FLOAT16_VALUE(     2.107),  SIMDE_FLOAT16_VALUE(     3.186),  SIMDE_FLOAT16_VALUE(     0.198),  SIMDE_FLOAT16_VALUE(     0.099) } },
    { {  SIMDE_FLOAT16_VALUE(   -29.781),  SIMDE_FLOAT16_VALUE(    20.062),  SIMDE_FLOAT16_VALUE(     0.013),  SIMDE_FLOAT16_VALUE(     7.100) },
      {  SIMDE_FLOAT16_VALUE(   -18.202),  SIMDE_FLOAT16_VALUE(     3.081),  SIMDE_FLOAT16_VALUE(     6.529),  SIMDE_FLOAT16_VALUE(   -10.242) },
      {  SIMDE_FLOAT16_VALUE(     1.636),  SIMDE_FLOAT16_VALUE(     6.512),  SIMDE_FLOAT16_VALUE(     0.002),  SIMDE_FLOAT16_VALUE(    -0.693) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a, b, r;

    a = simde_vld1_f16(test_vec[i].a);
    b = simde_vld1_f16(test_vec[i].b);
    r = simde_vdiv_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vdiv_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdivq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   -10.771),  SIMDE_FLOAT16_VALUE(    29.577),  SIMDE_FLOAT16_VALUE(   -11.789),  SIMDE_FLOAT16_VALUE(    28.945),
         SIMDE_FLOAT16_VALUE(    16.818),  SIMDE_FLOAT16_VALUE(    14.737),  SIMDE_FLOAT16_VALUE(     8.955),  SIMDE_FLOAT16_VALUE(   -13.722) },
      {  SIMDE_FLOAT16_VALUE(   -20.296),  SIMDE_FLOAT16_VALUE(    20.686),  SIMDE_FLOAT16_VALUE(    26.861),  SIMDE_FLOAT16_VALUE(     1.961),
         SIMDE_FLOAT16_VALUE(   -15.637),  SIMDE_FLOAT16_VALUE(    12.771),  SIMDE_FLOAT16_VALUE(   -24.164),  SIMDE_FLOAT16_VALUE(    -1.471) },
      {  SIMDE_FLOAT16_VALUE(     0.531),  SIMDE_FLOAT16_VALUE(     1.430),  SIMDE_FLOAT16_VALUE(    -0.439),  SIMDE_FLOAT16_VALUE(    14.760),
         SIMDE_FLOAT16_VALUE(    -1.076),  SIMDE_FLOAT16_VALUE(     1.154),  SIMDE_FLOAT16_VALUE(    -0.371),  SIMDE_FLOAT16_VALUE(     9.328) } },
    { {  SIMDE_FLOAT16_VALUE(   -17.873),  SIMDE_FLOAT16_VALUE(   -19.710),  SIMDE_FLOAT16_VALUE(   -10.353),  SIMDE_FLOAT16_VALUE(    -9.794),
         SIMDE_FLOAT16_VALUE(    -8.429),  SIMDE_FLOAT16_VALUE(   -19.159),  SIMDE_FLOAT16_VALUE(   -21.437),  SIMDE_FLOAT16_VALUE(    24.324) },
      {  SIMDE_FLOAT16_VALUE(    11.639),  SIMDE_FLOAT16_VALUE(   -13.685),  SIMDE_FLOAT16_VALUE(    29.216),  SIMDE_FLOAT16_VALUE(    -4.616),
         SIMDE_FLOAT16_VALUE(    -5.940),  SIMDE_FLOAT16_VALUE(   -10.249),  SIMDE_FLOAT16_VALUE(    -6.361),  SIMDE_FLOAT16_VALUE(    -6.127) },
      {  SIMDE_FLOAT16_VALUE(    -1.536),  SIMDE_FLOAT16_VALUE(     1.440),  SIMDE_FLOAT16_VALUE(    -0.354),  SIMDE_FLOAT16_VALUE(     2.122),
         SIMDE_FLOAT16_VALUE(     1.419),  SIMDE_FLOAT16_VALUE(     1.869),  SIMDE_FLOAT16_VALUE(     3.370),  SIMDE_FLOAT16_VALUE(    -3.970) } },
    { {  SIMDE_FLOAT16_VALUE(   -26.296),  SIMDE_FLOAT16_VALUE(    22.274),  SIMDE_FLOAT16_VALUE(     9.647),  SIMDE_FLOAT16_VALUE(   -16.240),
         SIMDE_FLOAT16_VALUE(    17.853),  SIMDE_FLOAT16_VALUE(    22.267),  SIMDE_FLOAT16_VALUE(    -6.719),  SIMDE_FLOAT16_VALUE(    25.249) },
      {  SIMDE_FLOAT16_VALUE(     5.829),  SIMDE_FLOAT16_VALUE(   -25.912),  SIMDE_FLOAT16_VALUE(    -9.577),  SIMDE_FLOAT16_VALUE(    23.777),
         SIMDE_FLOAT16_VALUE(    22.199),  SIMDE_FLOAT16_VALUE(    21.992),  SIMDE_FLOAT16_VALUE(   -28.785),  SIMDE_FLOAT16_VALUE(   -23.879) },
      {  SIMDE_FLOAT16_VALUE(    -4.511),  SIMDE_FLOAT16_VALUE(    -0.860),  SIMDE_FLOAT16_VALUE(    -1.007),  SIMDE_FLOAT16_VALUE(    -0.683),
         SIMDE_FLOAT16_VALUE(     0.804),  SIMDE_FLOAT16_VALUE(     1.013),  SIMDE_FLOAT16_VALUE(     0.233),  SIMDE_FLOAT16_VALUE(    -1.057) } },
    { {  SIMDE_FLOAT16_VALUE(    20.507),  SIMDE_FLOAT16_VALUE(     8.237),  SIMDE_FLOAT16_VALUE(     8.339),  SIMDE_FLOAT16_VALUE(     4.350),
         SIMDE_FLOAT16_VALUE(    10.615),  SIMDE_FLOAT16_VALUE(   -11.169),  SIMDE_FLOAT16_VALUE(   -24.609),  SIMDE_FLOAT16_VALUE(     9.759) },
      {  SIMDE_FLOAT16_VALUE(   -15.463),  SIMDE_FLOAT16_VALUE(     8.417),  SIMDE_FLOAT16_VALUE(     8.515),  SIMDE_FLOAT16_VALUE(    16.866),
         SIMDE_FLOAT16_VALUE(   -16.079),  SIMDE_FLOAT16_VALUE(     1.601),  SIMDE_FLOAT16_VALUE(   -27.621),  SIMDE_FLOAT16_VALUE(   -21.471) },
      {  SIMDE_FLOAT16_VALUE(    -1.326),  SIMDE_FLOAT16_VALUE(     0.979),  SIMDE_FLOAT16_VALUE(     0.979),  SIMDE_FLOAT16_VALUE(     0.258),
         SIMDE_FLOAT16_VALUE(    -0.660),  SIMDE_FLOAT16_VALUE(    -6.976),  SIMDE_FLOAT16_VALUE(     0.891),  SIMDE_FLOAT16_VALUE(    -0.455) } },
    { {  SIMDE_FLOAT16_VALUE(    21.463),  SIMDE_FLOAT16_VALUE(    28.423),  SIMDE_FLOAT16_VALUE(   -17.557),  SIMDE_FLOAT16_VALUE(    -1.800),
         SIMDE_FLOAT16_VALUE(    11.392),  SIMDE_FLOAT16_VALUE(   -15.848),  SIMDE_FLOAT16_VALUE(   -24.661),  SIMDE_FLOAT16_VALUE(    25.693) },
      {  SIMDE_FLOAT16_VALUE(    26.380),  SIMDE_FLOAT16_VALUE(   -15.389),  SIMDE_FLOAT16_VALUE(   -23.449),  SIMDE_FLOAT16_VALUE(    29.712),
         SIMDE_FLOAT16_VALUE(    -8.215),  SIMDE_FLOAT16_VALUE(    19.848),  SIMDE_FLOAT16_VALUE(   -20.141),  SIMDE_FLOAT16_VALUE(   -20.490) },
      {  SIMDE_FLOAT16_VALUE(     0.814),  SIMDE_FLOAT16_VALUE(    -1.847),  SIMDE_FLOAT16_VALUE(     0.749),  SIMDE_FLOAT16_VALUE(    -0.061),
         SIMDE_FLOAT16_VALUE(    -1.387),  SIMDE_FLOAT16_VALUE(    -0.798),  SIMDE_FLOAT16_VALUE(     1.224),  SIMDE_FLOAT16_VALUE(    -1.254) } },
    { {  SIMDE_FLOAT16_VALUE(    28.796),  SIMDE_FLOAT16_VALUE(    29.699),  SIMDE_FLOAT16_VALUE(    10.712),  SIMDE_FLOAT16_VALUE(   -21.599),
         SIMDE_FLOAT16_VALUE(    24.006),  SIMDE_FLOAT16_VALUE(   -17.961),  SIMDE_FLOAT16_VALUE(    28.615),  SIMDE_FLOAT16_VALUE(    28.905) },
      {  SIMDE_FLOAT16_VALUE(    11.412),  SIMDE_FLOAT16_VALUE(    -0.976),  SIMDE_FLOAT16_VALUE(   -29.468),  SIMDE_FLOAT16_VALUE(    21.878),
         SIMDE_FLOAT16_VALUE(    -3.274),  SIMDE_FLOAT16_VALUE(    22.713),  SIMDE_FLOAT16_VALUE(   -14.330),  SIMDE_FLOAT16_VALUE(   -28.881) },
      {  SIMDE_FLOAT16_VALUE(     2.523),  SIMDE_FLOAT16_VALUE(   -30.429),  SIMDE_FLOAT16_VALUE(    -0.364),  SIMDE_FLOAT16_VALUE(    -0.987),
         SIMDE_FLOAT16_VALUE(    -7.332),  SIMDE_FLOAT16_VALUE(    -0.791),  SIMDE_FLOAT16_VALUE(    -1.997),  SIMDE_FLOAT16_VALUE(    -1.001) } },
    { {  SIMDE_FLOAT16_VALUE(     9.977),  SIMDE_FLOAT16_VALUE(     7.707),  SIMDE_FLOAT16_VALUE(   -17.612),  SIMDE_FLOAT16_VALUE(    26.273),
         SIMDE_FLOAT16_VALUE(    26.672),  SIMDE_FLOAT16_VALUE(    -4.934),  SIMDE_FLOAT16_VALUE(     5.232),  SIMDE_FLOAT16_VALUE(    -0.476) },
      {  SIMDE_FLOAT16_VALUE(   -25.013),  SIMDE_FLOAT16_VALUE(   -12.429),  SIMDE_FLOAT16_VALUE(   -21.633),  SIMDE_FLOAT16_VALUE(   -17.840),
         SIMDE_FLOAT16_VALUE(    -4.619),  SIMDE_FLOAT16_VALUE(    24.689),  SIMDE_FLOAT16_VALUE(   -15.646),  SIMDE_FLOAT16_VALUE(     4.657) },
      {  SIMDE_FLOAT16_VALUE(    -0.399),  SIMDE_FLOAT16_VALUE(    -0.620),  SIMDE_FLOAT16_VALUE(     0.814),  SIMDE_FLOAT16_VALUE(    -1.473),
         SIMDE_FLOAT16_VALUE(    -5.774),  SIMDE_FLOAT16_VALUE(    -0.200),  SIMDE_FLOAT16_VALUE(    -0.334),  SIMDE_FLOAT16_VALUE(    -0.102) } },
    { {  SIMDE_FLOAT16_VALUE(    -3.758),  SIMDE_FLOAT16_VALUE(     8.661),  SIMDE_FLOAT16_VALUE(   -28.292),  SIMDE_FLOAT16_VALUE(    16.774),
         SIMDE_FLOAT16_VALUE(    18.376),  SIMDE_FLOAT16_VALUE(   -29.201),  SIMDE_FLOAT16_VALUE(    27.825),  SIMDE_FLOAT16_VALUE(    16.898) },
      {  SIMDE_FLOAT16_VALUE(     1.920),  SIMDE_FLOAT16_VALUE(   -28.272),  SIMDE_FLOAT16_VALUE(    25.083),  SIMDE_FLOAT16_VALUE(    22.725),
         SIMDE_FLOAT16_VALUE(     4.974),  SIMDE_FLOAT16_VALUE(   -17.596),  SIMDE_FLOAT16_VALUE(    23.174),  SIMDE_FLOAT16_VALUE(   -17.812) },
      {  SIMDE_FLOAT16_VALUE(    -1.957),  SIMDE_FLOAT16_VALUE(    -0.306),  SIMDE_FLOAT16_VALUE(    -1.128),  SIMDE_FLOAT16_VALUE(     0.738),
         SIMDE_FLOAT16_VALUE(     3.694),  SIMDE_FLOAT16_VALUE(     1.660),  SIMDE_FLOAT16_VALUE(     1.201),  SIMDE_FLOAT16_VALUE(    -0.949) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a, b, r;

    a = simde_vld1q_f16(test_vec[i].a);
    b = simde_vld1q_f16(test_vec[i].b);
    r = simde_vdivq_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vdivq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vdiv_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(-246.61), SIMDE_FLOAT32_C(-792.20) },
      { SIMDE_FLOAT32_C(747.10), SIMDE_FLOAT32_C(-128.92) },
      { SIMDE_FLOAT32_C(-0.33), SIMDE_FLOAT32_C(6.14) } },
    { { SIMDE_FLOAT32_C(424.59), SIMDE_FLOAT32_C(-797.13) },
      { SIMDE_FLOAT32_C(-210.37), SIMDE_FLOAT32_C(-738.57) },
      { SIMDE_FLOAT32_C(-2.02), SIMDE_FLOAT32_C(1.08) } },
    { { SIMDE_FLOAT32_C(-681.72), SIMDE_FLOAT32_C(541.25) },
      { SIMDE_FLOAT32_C(568.84), SIMDE_FLOAT32_C(-919.64) },
      { SIMDE_FLOAT32_C(-1.20), SIMDE_FLOAT32_C(-0.59) } },
    { { SIMDE_FLOAT32_C(880.97), SIMDE_FLOAT32_C(457.69) },
      { SIMDE_FLOAT32_C(-25.21), SIMDE_FLOAT32_C(-20.82) },
      { SIMDE_FLOAT32_C(-34.95), SIMDE_FLOAT32_C(-21.98) } },
    { { SIMDE_FLOAT32_C(709.87), SIMDE_FLOAT32_C(-254.84) },
      { SIMDE_FLOAT32_C(202.11), SIMDE_FLOAT32_C(-932.42) },
      { SIMDE_FLOAT32_C(3.51), SIMDE_FLOAT32_C(0.27) } },
    { { SIMDE_FLOAT32_C(-421.37), SIMDE_FLOAT32_C(-299.43) },
      { SIMDE_FLOAT32_C(260.81), SIMDE_FLOAT32_C(497.12) },
      { SIMDE_FLOAT32_C(-1.62), SIMDE_FLOAT32_C(-0.60) } },
    { { SIMDE_FLOAT32_C(495.09), SIMDE_FLOAT32_C(-18.59) },
      { SIMDE_FLOAT32_C(-972.83), SIMDE_FLOAT32_C(973.15) },
      { SIMDE_FLOAT32_C(-0.51), SIMDE_FLOAT32_C(-0.02) } },
    { { SIMDE_FLOAT32_C(-968.48), SIMDE_FLOAT32_C(-739.00) },
      { SIMDE_FLOAT32_C(224.68), SIMDE_FLOAT32_C(-500.16) },
      { SIMDE_FLOAT32_C(-4.31), SIMDE_FLOAT32_C(1.48) } },
    { { SIMDE_FLOAT32_C(706.64), SIMDE_FLOAT32_C(440.83) },
      { SIMDE_FLOAT32_C(-697.78), SIMDE_FLOAT32_C(784.30) },
      { SIMDE_FLOAT32_C(-1.01), SIMDE_FLOAT32_C(0.56) } },
    { { SIMDE_FLOAT32_C(171.08), SIMDE_FLOAT32_C(-82.45) },
      { SIMDE_FLOAT32_C(-948.90), SIMDE_FLOAT32_C(-438.40) },
      { SIMDE_FLOAT32_C(-0.18), SIMDE_FLOAT32_C(0.19) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vdiv_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vdiv_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdivq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(690.14), SIMDE_FLOAT32_C(72.00), SIMDE_FLOAT32_C(-847.46), SIMDE_FLOAT32_C(224.05) },
      { SIMDE_FLOAT32_C(-16.25), SIMDE_FLOAT32_C(-468.95), SIMDE_FLOAT32_C(219.70), SIMDE_FLOAT32_C(-994.83) },
      { SIMDE_FLOAT32_C(-42.46), SIMDE_FLOAT32_C(-0.15), SIMDE_FLOAT32_C(-3.86), SIMDE_FLOAT32_C(-0.23) } },
    { { SIMDE_FLOAT32_C(15.11), SIMDE_FLOAT32_C(-51.64), SIMDE_FLOAT32_C(-267.55), SIMDE_FLOAT32_C(-349.21) },
      { SIMDE_FLOAT32_C(566.36), SIMDE_FLOAT32_C(187.53), SIMDE_FLOAT32_C(-201.93), SIMDE_FLOAT32_C(69.88) },
      { SIMDE_FLOAT32_C(0.03), SIMDE_FLOAT32_C(-0.28), SIMDE_FLOAT32_C(1.32), SIMDE_FLOAT32_C(-5.00) } },
    { { SIMDE_FLOAT32_C(-421.47), SIMDE_FLOAT32_C(252.11), SIMDE_FLOAT32_C(-360.83), SIMDE_FLOAT32_C(201.92) },
      { SIMDE_FLOAT32_C(666.79), SIMDE_FLOAT32_C(-509.75), SIMDE_FLOAT32_C(-218.04), SIMDE_FLOAT32_C(759.52) },
      { SIMDE_FLOAT32_C(-0.63), SIMDE_FLOAT32_C(-0.49), SIMDE_FLOAT32_C(1.65), SIMDE_FLOAT32_C(0.27) } },
    { { SIMDE_FLOAT32_C(-613.29), SIMDE_FLOAT32_C(-320.60), SIMDE_FLOAT32_C(854.70), SIMDE_FLOAT32_C(623.67) },
      { SIMDE_FLOAT32_C(150.20), SIMDE_FLOAT32_C(965.65), SIMDE_FLOAT32_C(-80.16), SIMDE_FLOAT32_C(-415.88) },
      { SIMDE_FLOAT32_C(-4.08), SIMDE_FLOAT32_C(-0.33), SIMDE_FLOAT32_C(-10.66), SIMDE_FLOAT32_C(-1.50) } },
    { { SIMDE_FLOAT32_C(-251.13), SIMDE_FLOAT32_C(405.25), SIMDE_FLOAT32_C(-400.23), SIMDE_FLOAT32_C(772.23) },
      { SIMDE_FLOAT32_C(-781.87), SIMDE_FLOAT32_C(724.61), SIMDE_FLOAT32_C(517.90), SIMDE_FLOAT32_C(245.11) },
      { SIMDE_FLOAT32_C(0.32), SIMDE_FLOAT32_C(0.56), SIMDE_FLOAT32_C(-0.77), SIMDE_FLOAT32_C(3.15) } },
    { { SIMDE_FLOAT32_C(-107.85), SIMDE_FLOAT32_C(-479.61), SIMDE_FLOAT32_C(-32.07), SIMDE_FLOAT32_C(-586.53) },
      { SIMDE_FLOAT32_C(421.93), SIMDE_FLOAT32_C(-304.44), SIMDE_FLOAT32_C(327.16), SIMDE_FLOAT32_C(559.89) },
      { SIMDE_FLOAT32_C(-0.26), SIMDE_FLOAT32_C(1.58), SIMDE_FLOAT32_C(-0.10), SIMDE_FLOAT32_C(-1.05) } },
    { { SIMDE_FLOAT32_C(-209.46), SIMDE_FLOAT32_C(4.97), SIMDE_FLOAT32_C(904.66), SIMDE_FLOAT32_C(-360.68) },
      { SIMDE_FLOAT32_C(61.47), SIMDE_FLOAT32_C(-621.09), SIMDE_FLOAT32_C(221.91), SIMDE_FLOAT32_C(745.82) },
      { SIMDE_FLOAT32_C(-3.41), SIMDE_FLOAT32_C(-0.01), SIMDE_FLOAT32_C(4.08), SIMDE_FLOAT32_C(-0.48) } },
    { { SIMDE_FLOAT32_C(-816.44), SIMDE_FLOAT32_C(-202.10), SIMDE_FLOAT32_C(-276.32), SIMDE_FLOAT32_C(-588.56) },
      { SIMDE_FLOAT32_C(-218.16), SIMDE_FLOAT32_C(-289.94), SIMDE_FLOAT32_C(-932.73), SIMDE_FLOAT32_C(498.04) },
      { SIMDE_FLOAT32_C(3.74), SIMDE_FLOAT32_C(0.70), SIMDE_FLOAT32_C(0.30), SIMDE_FLOAT32_C(-1.18) } },
    { { SIMDE_FLOAT32_C(231.50), SIMDE_FLOAT32_C(9.60), SIMDE_FLOAT32_C(-307.81), SIMDE_FLOAT32_C(581.74) },
      { SIMDE_FLOAT32_C(-886.78), SIMDE_FLOAT32_C(-210.27), SIMDE_FLOAT32_C(-522.74), SIMDE_FLOAT32_C(-495.13) },
      { SIMDE_FLOAT32_C(-0.26), SIMDE_FLOAT32_C(-0.05), SIMDE_FLOAT32_C(0.59), SIMDE_FLOAT32_C(-1.17) } },
    { { SIMDE_FLOAT32_C(-173.84), SIMDE_FLOAT32_C(980.62), SIMDE_FLOAT32_C(-409.94), SIMDE_FLOAT32_C(616.98) },
      { SIMDE_FLOAT32_C(152.98), SIMDE_FLOAT32_C(820.61), SIMDE_FLOAT32_C(-490.46), SIMDE_FLOAT32_C(539.45) },
      { SIMDE_FLOAT32_C(-1.14), SIMDE_FLOAT32_C(1.19), SIMDE_FLOAT32_C(0.84), SIMDE_FLOAT32_C(1.14) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a, b, r;

    a = simde_vld1q_f32(test_vec[i].a);
    b = simde_vld1q_f32(test_vec[i].b);
    r = simde_vdivq_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vdivq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdiv_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 31140.906) },
      {  SIMDE_FLOAT64_C( 44624.688) },
      {  SIMDE_FLOAT64_C(     0.698) } },
    { {  SIMDE_FLOAT64_C( 96808.047) },
      { -SIMDE_FLOAT64_C( 41966.070) },
      { -SIMDE_FLOAT64_C(     2.307) } },
    { { -SIMDE_FLOAT64_C( 50078.270) },
      { -SIMDE_FLOAT64_C( 52321.352) },
      {  SIMDE_FLOAT64_C(     0.957) } },
    { { -SIMDE_FLOAT64_C( 58032.668) },
      {  SIMDE_FLOAT64_C(  6769.766) },
      { -SIMDE_FLOAT64_C(     8.572) } },
    { {  SIMDE_FLOAT64_C( 93381.875) },
      { -SIMDE_FLOAT64_C( 17989.930) },
      { -SIMDE_FLOAT64_C(     5.191) } },
    { {  SIMDE_FLOAT64_C( 11662.852) },
      {  SIMDE_FLOAT64_C( 33482.797) },
      {  SIMDE_FLOAT64_C(     0.348) } },
    { {  SIMDE_FLOAT64_C( 93732.734) },
      { -SIMDE_FLOAT64_C( 21767.930) },
      { -SIMDE_FLOAT64_C(     4.306) } },
    { {  SIMDE_FLOAT64_C( 84095.406) },
      {  SIMDE_FLOAT64_C(  6344.000) },
      {  SIMDE_FLOAT64_C(    13.256) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a, b, r;

    a = simde_vld1_f64(test_vec[i].a);
    b = simde_vld1_f64(test_vec[i].b);
    r = simde_vdiv_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r = simde_vdiv_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdivq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 93316.563),  SIMDE_FLOAT64_C( 68028.891) },
      {  SIMDE_FLOAT64_C( 48809.250), -SIMDE_FLOAT64_C( 48195.434) },
      {  SIMDE_FLOAT64_C(     1.912), -SIMDE_FLOAT64_C(     1.412) } },
    { { -SIMDE_FLOAT64_C( 19135.016),  SIMDE_FLOAT64_C( 85371.516) },
      {  SIMDE_FLOAT64_C( 42916.328),  SIMDE_FLOAT64_C( 21989.750) },
      { -SIMDE_FLOAT64_C(     0.446),  SIMDE_FLOAT64_C(     3.882) } },
    { {  SIMDE_FLOAT64_C( 18867.875), -SIMDE_FLOAT64_C( 64623.633) },
      {  SIMDE_FLOAT64_C( 62294.531), -SIMDE_FLOAT64_C( 69296.297) },
      {  SIMDE_FLOAT64_C(     0.303),  SIMDE_FLOAT64_C(     0.933) } },
    { { -SIMDE_FLOAT64_C( 65094.203), -SIMDE_FLOAT64_C( 82590.305) },
      { -SIMDE_FLOAT64_C( 35304.488),  SIMDE_FLOAT64_C( 59267.406) },
      {  SIMDE_FLOAT64_C(     1.844), -SIMDE_FLOAT64_C(     1.394) } },
    { {  SIMDE_FLOAT64_C( 98460.609),  SIMDE_FLOAT64_C( 89953.734) },
      {  SIMDE_FLOAT64_C( 98933.125),  SIMDE_FLOAT64_C( 44279.922) },
      {  SIMDE_FLOAT64_C(     0.995),  SIMDE_FLOAT64_C(     2.031) } },
    { { -SIMDE_FLOAT64_C(  6041.109),  SIMDE_FLOAT64_C( 92952.578) },
      { -SIMDE_FLOAT64_C( 42609.590),  SIMDE_FLOAT64_C( 65224.828) },
      {  SIMDE_FLOAT64_C(     0.142),  SIMDE_FLOAT64_C(     1.425) } },
    { {  SIMDE_FLOAT64_C(  6979.672), -SIMDE_FLOAT64_C( 20641.891) },
      { -SIMDE_FLOAT64_C( 78074.266), -SIMDE_FLOAT64_C( 30796.594) },
      { -SIMDE_FLOAT64_C(     0.089),  SIMDE_FLOAT64_C(     0.670) } },
    { {  SIMDE_FLOAT64_C( 75624.313), -SIMDE_FLOAT64_C(  9035.328) },
      {  SIMDE_FLOAT64_C( 91349.641),  SIMDE_FLOAT64_C( 23437.461) },
      {  SIMDE_FLOAT64_C(     0.828), -SIMDE_FLOAT64_C(     0.386) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a, b, r;

    a = simde_vld1q_f64(test_vec[i].a);
    b = simde_vld1q_f64(test_vec[i].b);
    r = simde_vdivq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vdivq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vdivh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdiv_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdivq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdiv_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdivq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdiv_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdivq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdiv_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdivq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
