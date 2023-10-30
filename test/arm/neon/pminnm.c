#define SIMDE_TEST_ARM_NEON_INSN pminnm

#include "test-neon.h"
#include "../../../simde/arm/neon/pminnm.h"

static int
test_simde_vpminnm_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(    13.169),  SIMDE_FLOAT16_VALUE(    -5.382),  SIMDE_FLOAT16_VALUE(     0.466),  SIMDE_FLOAT16_VALUE(     3.873) },
      {  SIMDE_FLOAT16_VALUE(     1.064),  SIMDE_FLOAT16_VALUE(    -6.537),  SIMDE_FLOAT16_VALUE(   -12.388),  SIMDE_FLOAT16_VALUE(     9.822) },
      {  SIMDE_FLOAT16_VALUE(    -5.382),  SIMDE_FLOAT16_VALUE(     0.466),  SIMDE_FLOAT16_VALUE(    -6.537),  SIMDE_FLOAT16_VALUE(   -12.388) } },
    { {  SIMDE_FLOAT16_VALUE(    13.718),  SIMDE_FLOAT16_VALUE(    -4.697),  SIMDE_FLOAT16_VALUE(    28.491),  SIMDE_FLOAT16_VALUE(   -17.834) },
      {  SIMDE_FLOAT16_VALUE(   -26.034),  SIMDE_FLOAT16_VALUE(    15.190),  SIMDE_FLOAT16_VALUE(     3.410),  SIMDE_FLOAT16_VALUE(    22.200) },
      {  SIMDE_FLOAT16_VALUE(    -4.697),  SIMDE_FLOAT16_VALUE(   -17.834),  SIMDE_FLOAT16_VALUE(   -26.034),  SIMDE_FLOAT16_VALUE(     3.410) } },
    { {  SIMDE_FLOAT16_VALUE(    10.326),  SIMDE_FLOAT16_VALUE(    21.106),  SIMDE_FLOAT16_VALUE(    29.367),  SIMDE_FLOAT16_VALUE(     7.557) },
      {  SIMDE_FLOAT16_VALUE(   -27.084),  SIMDE_FLOAT16_VALUE(   -12.434),  SIMDE_FLOAT16_VALUE(   -13.678),  SIMDE_FLOAT16_VALUE(    -6.027) },
      {  SIMDE_FLOAT16_VALUE(    10.326),  SIMDE_FLOAT16_VALUE(     7.557),  SIMDE_FLOAT16_VALUE(   -27.084),  SIMDE_FLOAT16_VALUE(   -13.678) } },
    { {  SIMDE_FLOAT16_VALUE(   -15.829),  SIMDE_FLOAT16_VALUE(    -2.019),  SIMDE_FLOAT16_VALUE(    24.550),  SIMDE_FLOAT16_VALUE(     0.023) },
      {  SIMDE_FLOAT16_VALUE(    19.285),  SIMDE_FLOAT16_VALUE(     1.609),  SIMDE_FLOAT16_VALUE(    20.296),  SIMDE_FLOAT16_VALUE(   -27.403) },
      {  SIMDE_FLOAT16_VALUE(   -15.829),  SIMDE_FLOAT16_VALUE(     0.023),  SIMDE_FLOAT16_VALUE(     1.609),  SIMDE_FLOAT16_VALUE(   -27.403) } },
    { {  SIMDE_FLOAT16_VALUE(   -16.761),  SIMDE_FLOAT16_VALUE(    17.096),  SIMDE_FLOAT16_VALUE(     7.539),  SIMDE_FLOAT16_VALUE(   -19.542) },
      {  SIMDE_FLOAT16_VALUE(   -12.561),  SIMDE_FLOAT16_VALUE(    10.747),  SIMDE_FLOAT16_VALUE(    -2.499),  SIMDE_FLOAT16_VALUE(   -25.387) },
      {  SIMDE_FLOAT16_VALUE(   -16.761),  SIMDE_FLOAT16_VALUE(   -19.542),  SIMDE_FLOAT16_VALUE(   -12.561),  SIMDE_FLOAT16_VALUE(   -25.387) } },
    { {  SIMDE_FLOAT16_VALUE(    15.620),  SIMDE_FLOAT16_VALUE(    10.699),  SIMDE_FLOAT16_VALUE(    20.140),  SIMDE_FLOAT16_VALUE(   -29.036) },
      {  SIMDE_FLOAT16_VALUE(   -29.857),  SIMDE_FLOAT16_VALUE(   -14.651),  SIMDE_FLOAT16_VALUE(    -7.932),  SIMDE_FLOAT16_VALUE(    16.315) },
      {  SIMDE_FLOAT16_VALUE(    10.699),  SIMDE_FLOAT16_VALUE(   -29.036),  SIMDE_FLOAT16_VALUE(   -29.857),  SIMDE_FLOAT16_VALUE(    -7.932) } },
    { {  SIMDE_FLOAT16_VALUE(   -15.220),  SIMDE_FLOAT16_VALUE(    26.006),  SIMDE_FLOAT16_VALUE(    -8.258),  SIMDE_FLOAT16_VALUE(    -6.292) },
      {  SIMDE_FLOAT16_VALUE(     9.642),  SIMDE_FLOAT16_VALUE(   -21.581),  SIMDE_FLOAT16_VALUE(    25.778),  SIMDE_FLOAT16_VALUE(   -23.076) },
      {  SIMDE_FLOAT16_VALUE(   -15.220),  SIMDE_FLOAT16_VALUE(    -8.258),  SIMDE_FLOAT16_VALUE(   -21.581),  SIMDE_FLOAT16_VALUE(   -23.076) } },
    { {  SIMDE_FLOAT16_VALUE(     4.380),  SIMDE_FLOAT16_VALUE(   -17.359),  SIMDE_FLOAT16_VALUE(    12.558),  SIMDE_FLOAT16_VALUE(     5.577) },
      {  SIMDE_FLOAT16_VALUE(    -8.179),  SIMDE_FLOAT16_VALUE(   -29.585),  SIMDE_FLOAT16_VALUE(    10.716),  SIMDE_FLOAT16_VALUE(   -28.758) },
      {  SIMDE_FLOAT16_VALUE(   -17.359),  SIMDE_FLOAT16_VALUE(     5.577),  SIMDE_FLOAT16_VALUE(   -29.585),  SIMDE_FLOAT16_VALUE(   -28.758) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a, b, r;

    a = simde_vld1_f16(test_vec[i].a);
    b = simde_vld1_f16(test_vec[i].b);
    r = simde_vpminnm_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vpminnm_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpminnm_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -823.14), SIMDE_FLOAT32_C(   128.93) },
      { SIMDE_FLOAT32_C(   -79.23), SIMDE_FLOAT32_C(   181.88) },
      { SIMDE_FLOAT32_C(  -823.14), SIMDE_FLOAT32_C(   -79.23) } },
    { { SIMDE_FLOAT32_C(   342.60), SIMDE_FLOAT32_C(   371.59) },
      { SIMDE_FLOAT32_C(   649.79), SIMDE_FLOAT32_C(   595.53) },
      { SIMDE_FLOAT32_C(   342.60), SIMDE_FLOAT32_C(   595.53) } },
    { { SIMDE_FLOAT32_C(   270.06), SIMDE_FLOAT32_C(  -842.97) },
      { SIMDE_FLOAT32_C(  -961.22), SIMDE_FLOAT32_C(  -328.85) },
      { SIMDE_FLOAT32_C(  -842.97), SIMDE_FLOAT32_C(  -961.22) } },
    { { SIMDE_FLOAT32_C(  -201.57), SIMDE_FLOAT32_C(   793.30) },
      { SIMDE_FLOAT32_C(  -461.86), SIMDE_FLOAT32_C(  -809.27) },
      { SIMDE_FLOAT32_C(  -201.57), SIMDE_FLOAT32_C(  -809.27) } },
    { { SIMDE_FLOAT32_C(  -247.56), SIMDE_FLOAT32_C(  -943.60) },
      { SIMDE_FLOAT32_C(   440.83), SIMDE_FLOAT32_C(   190.31) },
      { SIMDE_FLOAT32_C(  -943.60), SIMDE_FLOAT32_C(   190.31) } },
    { { SIMDE_FLOAT32_C(  -830.78), SIMDE_FLOAT32_C(  -101.36) },
      { SIMDE_FLOAT32_C(  -658.42), SIMDE_FLOAT32_C(   551.40) },
      { SIMDE_FLOAT32_C(  -830.78), SIMDE_FLOAT32_C(  -658.42) } },
    { { SIMDE_FLOAT32_C(  -949.01), SIMDE_FLOAT32_C(  -839.90) },
      { SIMDE_FLOAT32_C(   498.39), SIMDE_FLOAT32_C(   411.31) },
      { SIMDE_FLOAT32_C(  -949.01), SIMDE_FLOAT32_C(   411.31) } },
    { { SIMDE_FLOAT32_C(   115.69), SIMDE_FLOAT32_C(  -563.88) },
      { SIMDE_FLOAT32_C(    32.11), SIMDE_FLOAT32_C(   292.55) },
      { SIMDE_FLOAT32_C(  -563.88), SIMDE_FLOAT32_C(    32.11) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vpminnm_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vpminnm_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpminnmq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   -23.985),  SIMDE_FLOAT16_VALUE(    21.728),  SIMDE_FLOAT16_VALUE(    19.395),  SIMDE_FLOAT16_VALUE(   -12.402),
         SIMDE_FLOAT16_VALUE(   -10.357),  SIMDE_FLOAT16_VALUE(   -15.900),  SIMDE_FLOAT16_VALUE(    22.373),  SIMDE_FLOAT16_VALUE(    12.074) },
      {  SIMDE_FLOAT16_VALUE(    25.919),  SIMDE_FLOAT16_VALUE(    -6.119),  SIMDE_FLOAT16_VALUE(    29.408),  SIMDE_FLOAT16_VALUE(    12.779),
         SIMDE_FLOAT16_VALUE(     5.224),  SIMDE_FLOAT16_VALUE(   -19.106),  SIMDE_FLOAT16_VALUE(   -14.508),  SIMDE_FLOAT16_VALUE(     4.713) },
      {  SIMDE_FLOAT16_VALUE(   -23.985),  SIMDE_FLOAT16_VALUE(   -12.402),  SIMDE_FLOAT16_VALUE(   -15.900),  SIMDE_FLOAT16_VALUE(    12.074),
         SIMDE_FLOAT16_VALUE(    -6.119),  SIMDE_FLOAT16_VALUE(    12.779),  SIMDE_FLOAT16_VALUE(   -19.106),  SIMDE_FLOAT16_VALUE(   -14.508) } },
    { {  SIMDE_FLOAT16_VALUE(    22.222),  SIMDE_FLOAT16_VALUE(    29.360),  SIMDE_FLOAT16_VALUE(     7.575),  SIMDE_FLOAT16_VALUE(    -2.926),
         SIMDE_FLOAT16_VALUE(   -22.328),  SIMDE_FLOAT16_VALUE(    -4.285),  SIMDE_FLOAT16_VALUE(   -26.063),  SIMDE_FLOAT16_VALUE(    16.711) },
      {  SIMDE_FLOAT16_VALUE(    10.849),  SIMDE_FLOAT16_VALUE(   -24.017),  SIMDE_FLOAT16_VALUE(    -9.818),  SIMDE_FLOAT16_VALUE(     5.659),
         SIMDE_FLOAT16_VALUE(     4.838),  SIMDE_FLOAT16_VALUE(    13.243),  SIMDE_FLOAT16_VALUE(   -28.408),  SIMDE_FLOAT16_VALUE(    29.452) },
      {  SIMDE_FLOAT16_VALUE(    22.222),  SIMDE_FLOAT16_VALUE(    -2.926),  SIMDE_FLOAT16_VALUE(   -22.328),  SIMDE_FLOAT16_VALUE(   -26.063),
         SIMDE_FLOAT16_VALUE(   -24.017),  SIMDE_FLOAT16_VALUE(    -9.818),  SIMDE_FLOAT16_VALUE(     4.838),  SIMDE_FLOAT16_VALUE(   -28.408) } },
    { {  SIMDE_FLOAT16_VALUE(    21.158),  SIMDE_FLOAT16_VALUE(    13.185),  SIMDE_FLOAT16_VALUE(     2.797),  SIMDE_FLOAT16_VALUE(   -25.373),
         SIMDE_FLOAT16_VALUE(   -27.050),  SIMDE_FLOAT16_VALUE(    28.620),  SIMDE_FLOAT16_VALUE(     6.974),  SIMDE_FLOAT16_VALUE(   -27.484) },
      {  SIMDE_FLOAT16_VALUE(   -10.337),  SIMDE_FLOAT16_VALUE(   -15.368),  SIMDE_FLOAT16_VALUE(    14.068),  SIMDE_FLOAT16_VALUE(     3.896),
         SIMDE_FLOAT16_VALUE(   -19.481),  SIMDE_FLOAT16_VALUE(   -23.876),  SIMDE_FLOAT16_VALUE(    21.495),  SIMDE_FLOAT16_VALUE(   -16.594) },
      {  SIMDE_FLOAT16_VALUE(    13.185),  SIMDE_FLOAT16_VALUE(   -25.373),  SIMDE_FLOAT16_VALUE(   -27.050),  SIMDE_FLOAT16_VALUE(   -27.484),
         SIMDE_FLOAT16_VALUE(   -15.368),  SIMDE_FLOAT16_VALUE(     3.896),  SIMDE_FLOAT16_VALUE(   -23.876),  SIMDE_FLOAT16_VALUE(   -16.594) } },
    { {  SIMDE_FLOAT16_VALUE(    11.309),  SIMDE_FLOAT16_VALUE(    17.395),  SIMDE_FLOAT16_VALUE(    10.407),  SIMDE_FLOAT16_VALUE(     7.376),
         SIMDE_FLOAT16_VALUE(     2.511),  SIMDE_FLOAT16_VALUE(    -3.557),  SIMDE_FLOAT16_VALUE(    27.356),  SIMDE_FLOAT16_VALUE(   -14.333) },
      {  SIMDE_FLOAT16_VALUE(   -16.334),  SIMDE_FLOAT16_VALUE(   -25.126),  SIMDE_FLOAT16_VALUE(    25.621),  SIMDE_FLOAT16_VALUE(   -25.149),
         SIMDE_FLOAT16_VALUE(    -4.951),  SIMDE_FLOAT16_VALUE(   -20.067),  SIMDE_FLOAT16_VALUE(   -15.839),  SIMDE_FLOAT16_VALUE(    28.179) },
      {  SIMDE_FLOAT16_VALUE(    11.309),  SIMDE_FLOAT16_VALUE(     7.376),  SIMDE_FLOAT16_VALUE(    -3.557),  SIMDE_FLOAT16_VALUE(   -14.333),
         SIMDE_FLOAT16_VALUE(   -25.126),  SIMDE_FLOAT16_VALUE(   -25.149),  SIMDE_FLOAT16_VALUE(   -20.067),  SIMDE_FLOAT16_VALUE(   -15.839) } },
    { {  SIMDE_FLOAT16_VALUE(     1.942),  SIMDE_FLOAT16_VALUE(     3.211),  SIMDE_FLOAT16_VALUE(    26.796),  SIMDE_FLOAT16_VALUE(    -2.509),
         SIMDE_FLOAT16_VALUE(     4.898),  SIMDE_FLOAT16_VALUE(     5.004),  SIMDE_FLOAT16_VALUE(    20.031),  SIMDE_FLOAT16_VALUE(   -28.658) },
      {  SIMDE_FLOAT16_VALUE(   -28.570),  SIMDE_FLOAT16_VALUE(    -1.500),  SIMDE_FLOAT16_VALUE(    19.427),  SIMDE_FLOAT16_VALUE(   -14.060),
         SIMDE_FLOAT16_VALUE(    -6.201),  SIMDE_FLOAT16_VALUE(    28.899),  SIMDE_FLOAT16_VALUE(    11.602),  SIMDE_FLOAT16_VALUE(   -19.559) },
      {  SIMDE_FLOAT16_VALUE(     1.942),  SIMDE_FLOAT16_VALUE(    -2.509),  SIMDE_FLOAT16_VALUE(     4.898),  SIMDE_FLOAT16_VALUE(   -28.658),
         SIMDE_FLOAT16_VALUE(   -28.570),  SIMDE_FLOAT16_VALUE(   -14.060),  SIMDE_FLOAT16_VALUE(    -6.201),  SIMDE_FLOAT16_VALUE(   -19.559) } },
    { {  SIMDE_FLOAT16_VALUE(   -21.599),  SIMDE_FLOAT16_VALUE(   -17.832),  SIMDE_FLOAT16_VALUE(     7.916),  SIMDE_FLOAT16_VALUE(    12.083),
         SIMDE_FLOAT16_VALUE(    23.794),  SIMDE_FLOAT16_VALUE(   -19.141),  SIMDE_FLOAT16_VALUE(     0.891),  SIMDE_FLOAT16_VALUE(    -8.443) },
      {  SIMDE_FLOAT16_VALUE(    16.811),  SIMDE_FLOAT16_VALUE(    16.231),  SIMDE_FLOAT16_VALUE(     1.757),  SIMDE_FLOAT16_VALUE(    -7.156),
         SIMDE_FLOAT16_VALUE(    27.852),  SIMDE_FLOAT16_VALUE(   -10.258),  SIMDE_FLOAT16_VALUE(   -15.540),  SIMDE_FLOAT16_VALUE(    26.888) },
      {  SIMDE_FLOAT16_VALUE(   -21.599),  SIMDE_FLOAT16_VALUE(     7.916),  SIMDE_FLOAT16_VALUE(   -19.141),  SIMDE_FLOAT16_VALUE(    -8.443),
         SIMDE_FLOAT16_VALUE(    16.231),  SIMDE_FLOAT16_VALUE(    -7.156),  SIMDE_FLOAT16_VALUE(   -10.258),  SIMDE_FLOAT16_VALUE(   -15.540) } },
    { {  SIMDE_FLOAT16_VALUE(     5.540),  SIMDE_FLOAT16_VALUE(    -0.559),  SIMDE_FLOAT16_VALUE(   -27.866),  SIMDE_FLOAT16_VALUE(    28.209),
         SIMDE_FLOAT16_VALUE(    28.118),  SIMDE_FLOAT16_VALUE(    -8.269),  SIMDE_FLOAT16_VALUE(    10.353),  SIMDE_FLOAT16_VALUE(   -12.633) },
      {  SIMDE_FLOAT16_VALUE(    22.343),  SIMDE_FLOAT16_VALUE(   -15.007),  SIMDE_FLOAT16_VALUE(    15.680),  SIMDE_FLOAT16_VALUE(    13.351),
         SIMDE_FLOAT16_VALUE(    16.688),  SIMDE_FLOAT16_VALUE(    18.146),  SIMDE_FLOAT16_VALUE(    21.875),  SIMDE_FLOAT16_VALUE(   -28.330) },
      {  SIMDE_FLOAT16_VALUE(    -0.559),  SIMDE_FLOAT16_VALUE(   -27.866),  SIMDE_FLOAT16_VALUE(    -8.269),  SIMDE_FLOAT16_VALUE(   -12.633),
         SIMDE_FLOAT16_VALUE(   -15.007),  SIMDE_FLOAT16_VALUE(    13.351),  SIMDE_FLOAT16_VALUE(    16.688),  SIMDE_FLOAT16_VALUE(   -28.330) } },
    { {  SIMDE_FLOAT16_VALUE(    11.142),  SIMDE_FLOAT16_VALUE(   -24.899),  SIMDE_FLOAT16_VALUE(    16.815),  SIMDE_FLOAT16_VALUE(    -8.303),
         SIMDE_FLOAT16_VALUE(    23.458),  SIMDE_FLOAT16_VALUE(    -0.210),  SIMDE_FLOAT16_VALUE(    26.797),  SIMDE_FLOAT16_VALUE(    13.831) },
      {  SIMDE_FLOAT16_VALUE(     3.682),  SIMDE_FLOAT16_VALUE(    17.924),  SIMDE_FLOAT16_VALUE(    28.047),  SIMDE_FLOAT16_VALUE(    21.592),
         SIMDE_FLOAT16_VALUE(    15.767),  SIMDE_FLOAT16_VALUE(   -23.667),  SIMDE_FLOAT16_VALUE(    -6.954),  SIMDE_FLOAT16_VALUE(   -26.626) },
      {  SIMDE_FLOAT16_VALUE(   -24.899),  SIMDE_FLOAT16_VALUE(    -8.303),  SIMDE_FLOAT16_VALUE(    -0.210),  SIMDE_FLOAT16_VALUE(    13.831),
         SIMDE_FLOAT16_VALUE(     3.682),  SIMDE_FLOAT16_VALUE(    21.592),  SIMDE_FLOAT16_VALUE(   -23.667),  SIMDE_FLOAT16_VALUE(   -26.626) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vpminnmq_f16(a, b);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vpminnmq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpminnmq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   680.38), SIMDE_FLOAT32_C(  -211.23), SIMDE_FLOAT32_C(   566.20), SIMDE_FLOAT32_C(   596.88) },
      { SIMDE_FLOAT32_C(   823.29), SIMDE_FLOAT32_C(  -604.90), SIMDE_FLOAT32_C(  -329.55), SIMDE_FLOAT32_C(   536.46) },
      { SIMDE_FLOAT32_C(  -211.23), SIMDE_FLOAT32_C(   566.20), SIMDE_FLOAT32_C(  -604.90), SIMDE_FLOAT32_C(  -329.55) } },
    { { SIMDE_FLOAT32_C(  -444.45), SIMDE_FLOAT32_C(   107.94), SIMDE_FLOAT32_C(   -45.21), SIMDE_FLOAT32_C(   257.74) },
      { SIMDE_FLOAT32_C(  -270.43), SIMDE_FLOAT32_C(    26.80), SIMDE_FLOAT32_C(   904.46), SIMDE_FLOAT32_C(   832.39) },
      { SIMDE_FLOAT32_C(  -444.45), SIMDE_FLOAT32_C(   -45.21), SIMDE_FLOAT32_C(  -270.43), SIMDE_FLOAT32_C(   832.39) } },
    { { SIMDE_FLOAT32_C(   271.42), SIMDE_FLOAT32_C(   434.59), SIMDE_FLOAT32_C(  -716.79), SIMDE_FLOAT32_C(   213.94) },
      { SIMDE_FLOAT32_C(  -967.40), SIMDE_FLOAT32_C(  -514.23), SIMDE_FLOAT32_C(  -725.54), SIMDE_FLOAT32_C(   608.35) },
      { SIMDE_FLOAT32_C(   271.42), SIMDE_FLOAT32_C(  -716.79), SIMDE_FLOAT32_C(  -967.40), SIMDE_FLOAT32_C(  -725.54) } },
    { { SIMDE_FLOAT32_C(  -686.64), SIMDE_FLOAT32_C(  -198.11), SIMDE_FLOAT32_C(  -740.42), SIMDE_FLOAT32_C(  -782.38) },
      { SIMDE_FLOAT32_C(   997.85), SIMDE_FLOAT32_C(  -563.49), SIMDE_FLOAT32_C(    25.86), SIMDE_FLOAT32_C(   678.22) },
      { SIMDE_FLOAT32_C(  -686.64), SIMDE_FLOAT32_C(  -782.38), SIMDE_FLOAT32_C(  -563.49), SIMDE_FLOAT32_C(    25.86) } },
    { { SIMDE_FLOAT32_C(   225.28), SIMDE_FLOAT32_C(  -407.94), SIMDE_FLOAT32_C(   275.10), SIMDE_FLOAT32_C(    48.57) },
      { SIMDE_FLOAT32_C(   -12.83), SIMDE_FLOAT32_C(   945.55), SIMDE_FLOAT32_C(  -414.97), SIMDE_FLOAT32_C(   542.72) },
      { SIMDE_FLOAT32_C(  -407.94), SIMDE_FLOAT32_C(    48.57), SIMDE_FLOAT32_C(   -12.83), SIMDE_FLOAT32_C(  -414.97) } },
    { { SIMDE_FLOAT32_C(    53.49), SIMDE_FLOAT32_C(   539.83), SIMDE_FLOAT32_C(  -199.54), SIMDE_FLOAT32_C(   783.06) },
      { SIMDE_FLOAT32_C(  -433.37), SIMDE_FLOAT32_C(  -295.08), SIMDE_FLOAT32_C(   615.45), SIMDE_FLOAT32_C(   838.05) },
      { SIMDE_FLOAT32_C(    53.49), SIMDE_FLOAT32_C(  -199.54), SIMDE_FLOAT32_C(  -433.37), SIMDE_FLOAT32_C(   615.45) } },
    { { SIMDE_FLOAT32_C(  -860.49), SIMDE_FLOAT32_C(   898.65), SIMDE_FLOAT32_C(    51.99), SIMDE_FLOAT32_C(  -827.89) },
      { SIMDE_FLOAT32_C(  -615.57), SIMDE_FLOAT32_C(   326.45), SIMDE_FLOAT32_C(   780.47), SIMDE_FLOAT32_C(  -302.21) },
      { SIMDE_FLOAT32_C(  -860.49), SIMDE_FLOAT32_C(  -827.89), SIMDE_FLOAT32_C(  -615.57), SIMDE_FLOAT32_C(  -302.21) } },
    { { SIMDE_FLOAT32_C(  -871.66), SIMDE_FLOAT32_C(  -959.95), SIMDE_FLOAT32_C(   -84.60), SIMDE_FLOAT32_C(  -873.81) },
      { SIMDE_FLOAT32_C(  -523.44), SIMDE_FLOAT32_C(   941.27), SIMDE_FLOAT32_C(   804.42), SIMDE_FLOAT32_C(   701.84) },
      { SIMDE_FLOAT32_C(  -959.95), SIMDE_FLOAT32_C(  -873.81), SIMDE_FLOAT32_C(  -523.44), SIMDE_FLOAT32_C(   701.84) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vpminnmq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vpminnmq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpminnmq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   680.38), SIMDE_FLOAT64_C(  -211.23) },
      { SIMDE_FLOAT64_C(   566.20), SIMDE_FLOAT64_C(   596.88) },
      { SIMDE_FLOAT64_C(  -211.23), SIMDE_FLOAT64_C(   566.20) } },
    { { SIMDE_FLOAT64_C(   823.29), SIMDE_FLOAT64_C(  -604.90) },
      { SIMDE_FLOAT64_C(  -329.55), SIMDE_FLOAT64_C(   536.46) },
      { SIMDE_FLOAT64_C(  -604.90), SIMDE_FLOAT64_C(  -329.55) } },
    { { SIMDE_FLOAT64_C(  -444.45), SIMDE_FLOAT64_C(   107.94) },
      { SIMDE_FLOAT64_C(   -45.21), SIMDE_FLOAT64_C(   257.74) },
      { SIMDE_FLOAT64_C(  -444.45), SIMDE_FLOAT64_C(   -45.21) } },
    { { SIMDE_FLOAT64_C(  -270.43), SIMDE_FLOAT64_C(    26.80) },
      { SIMDE_FLOAT64_C(   904.46), SIMDE_FLOAT64_C(   832.39) },
      { SIMDE_FLOAT64_C(  -270.43), SIMDE_FLOAT64_C(   832.39) } },
    { { SIMDE_FLOAT64_C(   271.42), SIMDE_FLOAT64_C(   434.59) },
      { SIMDE_FLOAT64_C(  -716.79), SIMDE_FLOAT64_C(   213.94) },
      { SIMDE_FLOAT64_C(   271.42), SIMDE_FLOAT64_C(  -716.79) } },
    { { SIMDE_FLOAT64_C(  -967.40), SIMDE_FLOAT64_C(  -514.23) },
      { SIMDE_FLOAT64_C(  -725.54), SIMDE_FLOAT64_C(   608.35) },
      { SIMDE_FLOAT64_C(  -967.40), SIMDE_FLOAT64_C(  -725.54) } },
    { { SIMDE_FLOAT64_C(  -686.64), SIMDE_FLOAT64_C(  -198.11) },
      { SIMDE_FLOAT64_C(  -740.42), SIMDE_FLOAT64_C(  -782.38) },
      { SIMDE_FLOAT64_C(  -686.64), SIMDE_FLOAT64_C(  -782.38) } },
    { { SIMDE_FLOAT64_C(   997.85), SIMDE_FLOAT64_C(  -563.49) },
      { SIMDE_FLOAT64_C(    25.86), SIMDE_FLOAT64_C(   678.22) },
      { SIMDE_FLOAT64_C(  -563.49), SIMDE_FLOAT64_C(    25.86) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vpminnmq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vpminnmq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpminnms_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -3.71), SIMDE_FLOAT32_C(   987.98) },
      SIMDE_FLOAT32_C(    -3.71) },
    { { SIMDE_FLOAT32_C(    71.28), SIMDE_FLOAT32_C(   -73.22) },
      SIMDE_FLOAT32_C(   -73.22) },
    { { SIMDE_FLOAT32_C(   662.47), SIMDE_FLOAT32_C(   798.12) },
      SIMDE_FLOAT32_C(   662.47) },
    { { SIMDE_FLOAT32_C(   748.29), SIMDE_FLOAT32_C(   429.24) },
      SIMDE_FLOAT32_C(   429.24) },
    { { SIMDE_FLOAT32_C(  -135.59), SIMDE_FLOAT32_C(  -818.02) },
      SIMDE_FLOAT32_C(  -818.02) },
    { { SIMDE_FLOAT32_C(  -586.79), SIMDE_FLOAT32_C(   204.77) },
      SIMDE_FLOAT32_C(  -586.79) },
    { { SIMDE_FLOAT32_C(  -567.78), SIMDE_FLOAT32_C(   738.70) },
      SIMDE_FLOAT32_C(  -567.78) },
    { { SIMDE_FLOAT32_C(   138.50), SIMDE_FLOAT32_C(   654.90) },
      SIMDE_FLOAT32_C(   138.50) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vpminnms_f32(a);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vpminnms_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpminnmqd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -817.36), SIMDE_FLOAT64_C(  -203.90) },
      SIMDE_FLOAT64_C(  -817.36) },
    { { SIMDE_FLOAT64_C(   453.34), SIMDE_FLOAT64_C(  -713.33) },
      SIMDE_FLOAT64_C(  -713.33) },
    { { SIMDE_FLOAT64_C(  -881.31), SIMDE_FLOAT64_C(   -11.11) },
      SIMDE_FLOAT64_C(  -881.31) },
    { { SIMDE_FLOAT64_C(  -205.40), SIMDE_FLOAT64_C(    31.04) },
      SIMDE_FLOAT64_C(  -205.40) },
    { { SIMDE_FLOAT64_C(   693.81), SIMDE_FLOAT64_C(  -888.36) },
      SIMDE_FLOAT64_C(  -888.36) },
    { { SIMDE_FLOAT64_C(   531.32), SIMDE_FLOAT64_C(   786.68) },
      SIMDE_FLOAT64_C(   531.32) },
    { { SIMDE_FLOAT64_C(   904.99), SIMDE_FLOAT64_C(   576.97) },
      SIMDE_FLOAT64_C(   576.97) },
    { { SIMDE_FLOAT64_C(   -71.56), SIMDE_FLOAT64_C(   548.42) },
      SIMDE_FLOAT64_C(   -71.56) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vpminnmqd_f64(a);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64_t r = simde_vpminnmqd_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpminnm_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminnm_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpminnmq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminnmq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminnmq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vpminnms_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpminnmqd_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
