#define SIMDE_TEST_ARM_NEON_INSN pmaxnm

#include "test-neon.h"
#include "../../../simde/arm/neon/pmaxnm.h"

static int
test_simde_vpmaxnm_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   441.00), SIMDE_FLOAT16_VALUE(   684.00), SIMDE_FLOAT16_VALUE(   861.50), SIMDE_FLOAT16_VALUE(   563.00) },
      { SIMDE_FLOAT16_VALUE(    98.06), SIMDE_FLOAT16_VALUE(    15.31), SIMDE_FLOAT16_VALUE(   896.00), SIMDE_FLOAT16_VALUE(  -786.50) },
      { SIMDE_FLOAT16_VALUE(   684.00), SIMDE_FLOAT16_VALUE(   861.50), SIMDE_FLOAT16_VALUE(    98.06), SIMDE_FLOAT16_VALUE(  896.00) } },
    { { SIMDE_FLOAT16_VALUE(    -6.45), SIMDE_FLOAT16_VALUE(  -848.00), SIMDE_FLOAT16_VALUE(    29.20), SIMDE_FLOAT16_VALUE(   815.50) },
      { SIMDE_FLOAT16_VALUE(  -856.00), SIMDE_FLOAT16_VALUE(  -672.50), SIMDE_FLOAT16_VALUE(   267.25), SIMDE_FLOAT16_VALUE(   274.50) },
      { SIMDE_FLOAT16_VALUE(    -6.45), SIMDE_FLOAT16_VALUE(   815.50), SIMDE_FLOAT16_VALUE(  -672.50), SIMDE_FLOAT16_VALUE(   274.50) } },
    { { SIMDE_FLOAT16_VALUE(   909.00), SIMDE_FLOAT16_VALUE(     9.56), SIMDE_FLOAT16_VALUE(  -475.75), SIMDE_FLOAT16_VALUE(   425.25) },
      { SIMDE_FLOAT16_VALUE(   269.75), SIMDE_FLOAT16_VALUE(  -294.75), SIMDE_FLOAT16_VALUE(   991.00), SIMDE_FLOAT16_VALUE(   -99.19) },
      { SIMDE_FLOAT16_VALUE(   909.00), SIMDE_FLOAT16_VALUE(   425.25), SIMDE_FLOAT16_VALUE(   269.75), SIMDE_FLOAT16_VALUE(   991.00) } },
    { { SIMDE_FLOAT16_VALUE(   121.69), SIMDE_FLOAT16_VALUE(    73.81), SIMDE_FLOAT16_VALUE(    14.28), SIMDE_FLOAT16_VALUE(   132.25) },
      { SIMDE_FLOAT16_VALUE(   545.00), SIMDE_FLOAT16_VALUE(   967.50), SIMDE_FLOAT16_VALUE(   819.50), SIMDE_FLOAT16_VALUE(     6.60) },
      { SIMDE_FLOAT16_VALUE(   121.69), SIMDE_FLOAT16_VALUE(   132.25), SIMDE_FLOAT16_VALUE(   967.50), SIMDE_FLOAT16_VALUE(   819.50) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r = simde_vpmaxnm_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vpmaxnm_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpmaxnm_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   316.14), SIMDE_FLOAT32_C(  -317.76) },
      { SIMDE_FLOAT32_C(  -999.28), SIMDE_FLOAT32_C(  -769.83) },
      { SIMDE_FLOAT32_C(   316.14), SIMDE_FLOAT32_C(  -769.83) } },
    { { SIMDE_FLOAT32_C(   563.53), SIMDE_FLOAT32_C(   317.30) },
      { SIMDE_FLOAT32_C(   849.20), SIMDE_FLOAT32_C(  -796.72) },
      { SIMDE_FLOAT32_C(   563.53), SIMDE_FLOAT32_C(   849.20) } },
    { { SIMDE_FLOAT32_C(   615.10), SIMDE_FLOAT32_C(   119.52) },
      { SIMDE_FLOAT32_C(   458.60), SIMDE_FLOAT32_C(   696.42) },
      { SIMDE_FLOAT32_C(   615.10), SIMDE_FLOAT32_C(   696.42) } },
    { { SIMDE_FLOAT32_C(  -342.74), SIMDE_FLOAT32_C(    78.42) },
      { SIMDE_FLOAT32_C(   362.08), SIMDE_FLOAT32_C(  -518.00) },
      { SIMDE_FLOAT32_C(    78.42), SIMDE_FLOAT32_C(   362.08) } },
    { { SIMDE_FLOAT32_C(  -470.51), SIMDE_FLOAT32_C(  -628.98) },
      { SIMDE_FLOAT32_C(   627.75), SIMDE_FLOAT32_C(  -933.75) },
      { SIMDE_FLOAT32_C(  -470.51), SIMDE_FLOAT32_C(   627.75) } },
    { { SIMDE_FLOAT32_C(  -180.94), SIMDE_FLOAT32_C(   801.21) },
      { SIMDE_FLOAT32_C(   206.11), SIMDE_FLOAT32_C(  -537.70) },
      { SIMDE_FLOAT32_C(   801.21), SIMDE_FLOAT32_C(   206.11) } },
    { { SIMDE_FLOAT32_C(  -275.82), SIMDE_FLOAT32_C(  -533.06) },
      { SIMDE_FLOAT32_C(    77.91), SIMDE_FLOAT32_C(   887.40) },
      { SIMDE_FLOAT32_C(  -275.82), SIMDE_FLOAT32_C(   887.40) } },
    { { SIMDE_FLOAT32_C(   896.99), SIMDE_FLOAT32_C(  -718.48) },
      { SIMDE_FLOAT32_C(  -622.01), SIMDE_FLOAT32_C(   213.13) },
      { SIMDE_FLOAT32_C(   896.99), SIMDE_FLOAT32_C(   213.13) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vpmaxnm_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vpmaxnm_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpmaxnmq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(    29.303),  SIMDE_FLOAT16_VALUE(   -15.473),  SIMDE_FLOAT16_VALUE(     1.006),  SIMDE_FLOAT16_VALUE(   -21.583),
         SIMDE_FLOAT16_VALUE(    22.970),  SIMDE_FLOAT16_VALUE(    -5.299),  SIMDE_FLOAT16_VALUE(   -14.205),  SIMDE_FLOAT16_VALUE(   -15.176) },
      {  SIMDE_FLOAT16_VALUE(    17.990),  SIMDE_FLOAT16_VALUE(    11.602),  SIMDE_FLOAT16_VALUE(   -20.495),  SIMDE_FLOAT16_VALUE(    -8.082),
         SIMDE_FLOAT16_VALUE(   -27.004),  SIMDE_FLOAT16_VALUE(   -11.946),  SIMDE_FLOAT16_VALUE(    25.843),  SIMDE_FLOAT16_VALUE(     6.779) },
      {  SIMDE_FLOAT16_VALUE(    29.303),  SIMDE_FLOAT16_VALUE(     1.006),  SIMDE_FLOAT16_VALUE(    22.970),  SIMDE_FLOAT16_VALUE(   -14.205),
         SIMDE_FLOAT16_VALUE(    17.990),  SIMDE_FLOAT16_VALUE(    -8.082),  SIMDE_FLOAT16_VALUE(   -11.946),  SIMDE_FLOAT16_VALUE(    25.843) } },
    { {  SIMDE_FLOAT16_VALUE(   -25.501),  SIMDE_FLOAT16_VALUE(   -24.669),  SIMDE_FLOAT16_VALUE(   -29.118),  SIMDE_FLOAT16_VALUE(    -5.219),
         SIMDE_FLOAT16_VALUE(    28.104),  SIMDE_FLOAT16_VALUE(     0.654),  SIMDE_FLOAT16_VALUE(   -27.808),  SIMDE_FLOAT16_VALUE(   -18.743) },
      {  SIMDE_FLOAT16_VALUE(   -20.813),  SIMDE_FLOAT16_VALUE(   -26.402),  SIMDE_FLOAT16_VALUE(    13.606),  SIMDE_FLOAT16_VALUE(    10.476),
         SIMDE_FLOAT16_VALUE(    29.613),  SIMDE_FLOAT16_VALUE(    19.062),  SIMDE_FLOAT16_VALUE(    27.849),  SIMDE_FLOAT16_VALUE(     9.536) },
      {  SIMDE_FLOAT16_VALUE(   -24.669),  SIMDE_FLOAT16_VALUE(    -5.219),  SIMDE_FLOAT16_VALUE(    28.104),  SIMDE_FLOAT16_VALUE(   -18.743),
         SIMDE_FLOAT16_VALUE(   -20.813),  SIMDE_FLOAT16_VALUE(    13.606),  SIMDE_FLOAT16_VALUE(    29.613),  SIMDE_FLOAT16_VALUE(    27.849) } },
    { {  SIMDE_FLOAT16_VALUE(    16.289),  SIMDE_FLOAT16_VALUE(   -19.184),  SIMDE_FLOAT16_VALUE(   -22.617),  SIMDE_FLOAT16_VALUE(   -15.017),
         SIMDE_FLOAT16_VALUE(   -27.645),  SIMDE_FLOAT16_VALUE(    29.031),  SIMDE_FLOAT16_VALUE(    26.470),  SIMDE_FLOAT16_VALUE(   -26.000) },
      {  SIMDE_FLOAT16_VALUE(   -12.853),  SIMDE_FLOAT16_VALUE(    -3.232),  SIMDE_FLOAT16_VALUE(     4.567),  SIMDE_FLOAT16_VALUE(   -26.692),
         SIMDE_FLOAT16_VALUE(    24.562),  SIMDE_FLOAT16_VALUE(   -29.933),  SIMDE_FLOAT16_VALUE(    21.969),  SIMDE_FLOAT16_VALUE(     7.783) },
      {  SIMDE_FLOAT16_VALUE(    16.289),  SIMDE_FLOAT16_VALUE(   -15.017),  SIMDE_FLOAT16_VALUE(    29.031),  SIMDE_FLOAT16_VALUE(    26.470),
         SIMDE_FLOAT16_VALUE(    -3.232),  SIMDE_FLOAT16_VALUE(     4.567),  SIMDE_FLOAT16_VALUE(    24.562),  SIMDE_FLOAT16_VALUE(    21.969) } },
    { {  SIMDE_FLOAT16_VALUE(     0.999),  SIMDE_FLOAT16_VALUE(   -29.129),  SIMDE_FLOAT16_VALUE(    27.988),  SIMDE_FLOAT16_VALUE(   -19.096),
         SIMDE_FLOAT16_VALUE(    13.789),  SIMDE_FLOAT16_VALUE(     8.234),  SIMDE_FLOAT16_VALUE(    24.437),  SIMDE_FLOAT16_VALUE(    21.721) },
      {  SIMDE_FLOAT16_VALUE(    26.278),  SIMDE_FLOAT16_VALUE(    16.547),  SIMDE_FLOAT16_VALUE(    10.034),  SIMDE_FLOAT16_VALUE(   -25.632),
         SIMDE_FLOAT16_VALUE(   -21.337),  SIMDE_FLOAT16_VALUE(    22.587),  SIMDE_FLOAT16_VALUE(     2.778),  SIMDE_FLOAT16_VALUE(     4.957) },
      {  SIMDE_FLOAT16_VALUE(     0.999),  SIMDE_FLOAT16_VALUE(    27.988),  SIMDE_FLOAT16_VALUE(    13.789),  SIMDE_FLOAT16_VALUE(    24.437),
         SIMDE_FLOAT16_VALUE(    26.278),  SIMDE_FLOAT16_VALUE(    10.034),  SIMDE_FLOAT16_VALUE(    22.587),  SIMDE_FLOAT16_VALUE(     4.957) } },
    { {  SIMDE_FLOAT16_VALUE(   -13.860),  SIMDE_FLOAT16_VALUE(    26.535),  SIMDE_FLOAT16_VALUE(     8.539),  SIMDE_FLOAT16_VALUE(    12.470),
         SIMDE_FLOAT16_VALUE(   -24.032),  SIMDE_FLOAT16_VALUE(    21.137),  SIMDE_FLOAT16_VALUE(    14.371),  SIMDE_FLOAT16_VALUE(     5.670) },
      {  SIMDE_FLOAT16_VALUE(    26.851),  SIMDE_FLOAT16_VALUE(   -13.040),  SIMDE_FLOAT16_VALUE(     3.688),  SIMDE_FLOAT16_VALUE(    -9.966),
         SIMDE_FLOAT16_VALUE(     6.679),  SIMDE_FLOAT16_VALUE(   -25.728),  SIMDE_FLOAT16_VALUE(   -16.073),  SIMDE_FLOAT16_VALUE(     1.650) },
      {  SIMDE_FLOAT16_VALUE(    26.535),  SIMDE_FLOAT16_VALUE(    12.470),  SIMDE_FLOAT16_VALUE(    21.137),  SIMDE_FLOAT16_VALUE(    14.371),
         SIMDE_FLOAT16_VALUE(    26.851),  SIMDE_FLOAT16_VALUE(     3.688),  SIMDE_FLOAT16_VALUE(     6.679),  SIMDE_FLOAT16_VALUE(     1.650) } },
    { {  SIMDE_FLOAT16_VALUE(   -19.296),  SIMDE_FLOAT16_VALUE(   -18.339),  SIMDE_FLOAT16_VALUE(   -13.951),  SIMDE_FLOAT16_VALUE(    23.736),
         SIMDE_FLOAT16_VALUE(    21.581),  SIMDE_FLOAT16_VALUE(     4.304),  SIMDE_FLOAT16_VALUE(     1.910),  SIMDE_FLOAT16_VALUE(    10.399) },
      {  SIMDE_FLOAT16_VALUE(    25.274),  SIMDE_FLOAT16_VALUE(   -28.803),  SIMDE_FLOAT16_VALUE(   -20.109),  SIMDE_FLOAT16_VALUE(   -22.088),
         SIMDE_FLOAT16_VALUE(    20.071),  SIMDE_FLOAT16_VALUE(    15.667),  SIMDE_FLOAT16_VALUE(   -24.469),  SIMDE_FLOAT16_VALUE(    18.492) },
      {  SIMDE_FLOAT16_VALUE(   -18.339),  SIMDE_FLOAT16_VALUE(    23.736),  SIMDE_FLOAT16_VALUE(    21.581),  SIMDE_FLOAT16_VALUE(    10.399),
         SIMDE_FLOAT16_VALUE(    25.274),  SIMDE_FLOAT16_VALUE(   -20.109),  SIMDE_FLOAT16_VALUE(    20.071),  SIMDE_FLOAT16_VALUE(    18.492) } },
    { {  SIMDE_FLOAT16_VALUE(    -3.637),  SIMDE_FLOAT16_VALUE(     3.472),  SIMDE_FLOAT16_VALUE(    14.644),  SIMDE_FLOAT16_VALUE(   -16.247),
         SIMDE_FLOAT16_VALUE(     1.467),  SIMDE_FLOAT16_VALUE(    -9.306),  SIMDE_FLOAT16_VALUE(     9.252),  SIMDE_FLOAT16_VALUE(    18.437) },
      {  SIMDE_FLOAT16_VALUE(    -2.944),  SIMDE_FLOAT16_VALUE(    -1.079),  SIMDE_FLOAT16_VALUE(   -18.689),  SIMDE_FLOAT16_VALUE(    24.492),
         SIMDE_FLOAT16_VALUE(   -25.720),  SIMDE_FLOAT16_VALUE(    26.654),  SIMDE_FLOAT16_VALUE(    12.162),  SIMDE_FLOAT16_VALUE(   -11.528) },
      {  SIMDE_FLOAT16_VALUE(     3.472),  SIMDE_FLOAT16_VALUE(    14.644),  SIMDE_FLOAT16_VALUE(     1.467),  SIMDE_FLOAT16_VALUE(    18.437),
         SIMDE_FLOAT16_VALUE(    -1.079),  SIMDE_FLOAT16_VALUE(    24.492),  SIMDE_FLOAT16_VALUE(    26.654),  SIMDE_FLOAT16_VALUE(    12.162) } },
    { {  SIMDE_FLOAT16_VALUE(     7.740),  SIMDE_FLOAT16_VALUE(    19.127),  SIMDE_FLOAT16_VALUE(    11.877),  SIMDE_FLOAT16_VALUE(   -25.942),
         SIMDE_FLOAT16_VALUE(     7.124),  SIMDE_FLOAT16_VALUE(    12.554),  SIMDE_FLOAT16_VALUE(    28.406),  SIMDE_FLOAT16_VALUE(    -5.830) },
      {  SIMDE_FLOAT16_VALUE(   -22.509),  SIMDE_FLOAT16_VALUE(   -22.856),  SIMDE_FLOAT16_VALUE(     9.728),  SIMDE_FLOAT16_VALUE(   -17.513),
         SIMDE_FLOAT16_VALUE(     0.430),  SIMDE_FLOAT16_VALUE(    18.796),  SIMDE_FLOAT16_VALUE(   -17.154),  SIMDE_FLOAT16_VALUE(    -2.826) },
      {  SIMDE_FLOAT16_VALUE(    19.127),  SIMDE_FLOAT16_VALUE(    11.877),  SIMDE_FLOAT16_VALUE(    12.554),  SIMDE_FLOAT16_VALUE(    28.406),
         SIMDE_FLOAT16_VALUE(   -22.509),  SIMDE_FLOAT16_VALUE(     9.728),  SIMDE_FLOAT16_VALUE(    18.796),  SIMDE_FLOAT16_VALUE(    -2.826) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vpmaxnmq_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vpmaxnmq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpmaxnmq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -402.07), SIMDE_FLOAT32_C(  -666.37), SIMDE_FLOAT32_C(   362.68), SIMDE_FLOAT32_C(  -326.71) },
      { SIMDE_FLOAT32_C(   454.85), SIMDE_FLOAT32_C(  -121.62), SIMDE_FLOAT32_C(   430.43), SIMDE_FLOAT32_C(   746.87) },
      { SIMDE_FLOAT32_C(  -402.07), SIMDE_FLOAT32_C(   362.68), SIMDE_FLOAT32_C(   454.85), SIMDE_FLOAT32_C(   746.87) } },
    { { SIMDE_FLOAT32_C(    33.52), SIMDE_FLOAT32_C(  -284.09), SIMDE_FLOAT32_C(  -166.25), SIMDE_FLOAT32_C(   480.19) },
      { SIMDE_FLOAT32_C(   -49.24), SIMDE_FLOAT32_C(   564.50), SIMDE_FLOAT32_C(   852.14), SIMDE_FLOAT32_C(  -390.08) },
      { SIMDE_FLOAT32_C(    33.52), SIMDE_FLOAT32_C(   480.19), SIMDE_FLOAT32_C(   564.50), SIMDE_FLOAT32_C(   852.14) } },
    { { SIMDE_FLOAT32_C(  -339.81), SIMDE_FLOAT32_C(   223.10), SIMDE_FLOAT32_C(  -267.43), SIMDE_FLOAT32_C(   -98.08) },
      { SIMDE_FLOAT32_C(   315.18), SIMDE_FLOAT32_C(  -621.58), SIMDE_FLOAT32_C(  -833.21), SIMDE_FLOAT32_C(     0.90) },
      { SIMDE_FLOAT32_C(   223.10), SIMDE_FLOAT32_C(   -98.08), SIMDE_FLOAT32_C(   315.18), SIMDE_FLOAT32_C(     0.90) } },
    { { SIMDE_FLOAT32_C(   737.95), SIMDE_FLOAT32_C(   329.19), SIMDE_FLOAT32_C(   372.64), SIMDE_FLOAT32_C(   555.32) },
      { SIMDE_FLOAT32_C(   563.00), SIMDE_FLOAT32_C(  -123.50), SIMDE_FLOAT32_C(  -962.40), SIMDE_FLOAT32_C(  -839.07) },
      { SIMDE_FLOAT32_C(   737.95), SIMDE_FLOAT32_C(   555.32), SIMDE_FLOAT32_C(   563.00), SIMDE_FLOAT32_C(  -839.07) } },
    { { SIMDE_FLOAT32_C(   210.13), SIMDE_FLOAT32_C(   400.28), SIMDE_FLOAT32_C(  -165.78), SIMDE_FLOAT32_C(  -335.02) },
      { SIMDE_FLOAT32_C(  -721.33), SIMDE_FLOAT32_C(  -735.34), SIMDE_FLOAT32_C(  -588.15), SIMDE_FLOAT32_C(   312.18) },
      { SIMDE_FLOAT32_C(   400.28), SIMDE_FLOAT32_C(  -165.78), SIMDE_FLOAT32_C(  -721.33), SIMDE_FLOAT32_C(   312.18) } },
    { { SIMDE_FLOAT32_C(   -19.43), SIMDE_FLOAT32_C(   245.59), SIMDE_FLOAT32_C(  -207.63), SIMDE_FLOAT32_C(   931.34) },
      { SIMDE_FLOAT32_C(  -189.91), SIMDE_FLOAT32_C(  -355.49), SIMDE_FLOAT32_C(  -458.75), SIMDE_FLOAT32_C(   470.28) },
      { SIMDE_FLOAT32_C(   245.59), SIMDE_FLOAT32_C(   931.34), SIMDE_FLOAT32_C(  -189.91), SIMDE_FLOAT32_C(   470.28) } },
    { { SIMDE_FLOAT32_C(   867.60), SIMDE_FLOAT32_C(   273.82), SIMDE_FLOAT32_C(  -627.81), SIMDE_FLOAT32_C(   182.78) },
      { SIMDE_FLOAT32_C(   652.24), SIMDE_FLOAT32_C(  -461.02), SIMDE_FLOAT32_C(  -816.31), SIMDE_FLOAT32_C(   390.19) },
      { SIMDE_FLOAT32_C(   867.60), SIMDE_FLOAT32_C(   182.78), SIMDE_FLOAT32_C(   652.24), SIMDE_FLOAT32_C(   390.19) } },
    { { SIMDE_FLOAT32_C(   868.17), SIMDE_FLOAT32_C(   556.33), SIMDE_FLOAT32_C(   -54.49), SIMDE_FLOAT32_C(   431.18) },
      { SIMDE_FLOAT32_C(  -567.17), SIMDE_FLOAT32_C(   -16.88), SIMDE_FLOAT32_C(   592.11), SIMDE_FLOAT32_C(   642.95) },
      { SIMDE_FLOAT32_C(   868.17), SIMDE_FLOAT32_C(   431.18), SIMDE_FLOAT32_C(   -16.88), SIMDE_FLOAT32_C(   642.95) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vpmaxnmq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vpmaxnmq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpmaxnmq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   521.70), SIMDE_FLOAT64_C(   828.15) },
      { SIMDE_FLOAT64_C(   535.14), SIMDE_FLOAT64_C(   480.15) },
      { SIMDE_FLOAT64_C(   828.15), SIMDE_FLOAT64_C(   535.14) } },
    { { SIMDE_FLOAT64_C(  -518.98), SIMDE_FLOAT64_C(  -210.96) },
      { SIMDE_FLOAT64_C(  -930.38), SIMDE_FLOAT64_C(   215.97) },
      { SIMDE_FLOAT64_C(  -210.96), SIMDE_FLOAT64_C(   215.97) } },
    { { SIMDE_FLOAT64_C(    91.20), SIMDE_FLOAT64_C(   348.64) },
      { SIMDE_FLOAT64_C(  -290.21), SIMDE_FLOAT64_C(    54.45) },
      { SIMDE_FLOAT64_C(   348.64), SIMDE_FLOAT64_C(    54.45) } },
    { { SIMDE_FLOAT64_C(  -405.44), SIMDE_FLOAT64_C(  -790.85) },
      { SIMDE_FLOAT64_C(   151.68), SIMDE_FLOAT64_C(    31.01) },
      { SIMDE_FLOAT64_C(  -405.44), SIMDE_FLOAT64_C(   151.68) } },
    { { SIMDE_FLOAT64_C(  -850.04), SIMDE_FLOAT64_C(  -183.10) },
      { SIMDE_FLOAT64_C(   893.21), SIMDE_FLOAT64_C(   481.08) },
      { SIMDE_FLOAT64_C(  -183.10), SIMDE_FLOAT64_C(   893.21) } },
    { { SIMDE_FLOAT64_C(  -361.59), SIMDE_FLOAT64_C(     9.07) },
      { SIMDE_FLOAT64_C(   399.01), SIMDE_FLOAT64_C(  -896.67) },
      { SIMDE_FLOAT64_C(     9.07), SIMDE_FLOAT64_C(   399.01) } },
    { { SIMDE_FLOAT64_C(  -108.96), SIMDE_FLOAT64_C(   271.20) },
      { SIMDE_FLOAT64_C(   839.25), SIMDE_FLOAT64_C(   679.65) },
      { SIMDE_FLOAT64_C(   271.20), SIMDE_FLOAT64_C(   839.25) } },
    { { SIMDE_FLOAT64_C(   406.65), SIMDE_FLOAT64_C(  -664.11) },
      { SIMDE_FLOAT64_C(   733.62), SIMDE_FLOAT64_C(   -71.65) },
      { SIMDE_FLOAT64_C(   406.65), SIMDE_FLOAT64_C(   733.62) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vpmaxnmq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vpmaxnmq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpmaxnms_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -687.34), SIMDE_FLOAT32_C(   938.41) },
      SIMDE_FLOAT32_C(   938.41) },
    { { SIMDE_FLOAT32_C(   -90.80), SIMDE_FLOAT32_C(  -528.65) },
      SIMDE_FLOAT32_C(   -90.80) },
    { { SIMDE_FLOAT32_C(    11.38), SIMDE_FLOAT32_C(  -376.09) },
      SIMDE_FLOAT32_C(    11.38) },
    { { SIMDE_FLOAT32_C(  -136.34), SIMDE_FLOAT32_C(  -804.70) },
      SIMDE_FLOAT32_C(  -136.34) },
    { { SIMDE_FLOAT32_C(  -475.42), SIMDE_FLOAT32_C(   955.92) },
      SIMDE_FLOAT32_C(   955.92) },
    { { SIMDE_FLOAT32_C(   141.16), SIMDE_FLOAT32_C(   -77.29) },
      SIMDE_FLOAT32_C(   141.16) },
    { { SIMDE_FLOAT32_C(    47.83), SIMDE_FLOAT32_C(  -559.34) },
      SIMDE_FLOAT32_C(    47.83) },
    { { SIMDE_FLOAT32_C(  -732.12), SIMDE_FLOAT32_C(   -31.68) },
      SIMDE_FLOAT32_C(   -31.68) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vpmaxnms_f32(a);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vpmaxnms_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpmaxnmqd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -940.00), SIMDE_FLOAT64_C(  -494.34) },
     SIMDE_FLOAT64_C(  -494.34) },
   { { SIMDE_FLOAT64_C(   -57.78), SIMDE_FLOAT64_C(   832.21) },
     SIMDE_FLOAT64_C(   832.21) },
   { { SIMDE_FLOAT64_C(  -973.99), SIMDE_FLOAT64_C(   101.27) },
     SIMDE_FLOAT64_C(   101.27) },
   { { SIMDE_FLOAT64_C(   184.50), SIMDE_FLOAT64_C(  -100.67) },
     SIMDE_FLOAT64_C(   184.50) },
   { { SIMDE_FLOAT64_C(  -792.79), SIMDE_FLOAT64_C(  -153.04) },
     SIMDE_FLOAT64_C(  -153.04) },
   { { SIMDE_FLOAT64_C(   317.69), SIMDE_FLOAT64_C(   455.59) },
     SIMDE_FLOAT64_C(   455.59) },
   { { SIMDE_FLOAT64_C(   152.31), SIMDE_FLOAT64_C(   547.52) },
     SIMDE_FLOAT64_C(   547.52) },
   { { SIMDE_FLOAT64_C(  -519.99), SIMDE_FLOAT64_C(   948.41) },
     SIMDE_FLOAT64_C(   948.41) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vpmaxnmqd_f64(a);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64_t r = simde_vpmaxnmqd_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxnm_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxnm_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxnmq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxnmq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxnmq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxnms_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpmaxnmqd_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
