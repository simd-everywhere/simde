#define SIMDE_TEST_ARM_NEON_INSN cmla

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla.h"

static int
test_simde_vcmla_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
    simde_float16 r_[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(  14.580),  SIMDE_FLOAT16_C(   2.381),  SIMDE_FLOAT16_C(   6.429), -SIMDE_FLOAT16_C(   5.674) },
      { -SIMDE_FLOAT16_C(   9.705),  SIMDE_FLOAT16_C(   9.555), -SIMDE_FLOAT16_C(   6.899),  SIMDE_FLOAT16_C(  11.776) },
      {  SIMDE_FLOAT16_C(   3.272),  SIMDE_FLOAT16_C(   6.858),  SIMDE_FLOAT16_C(   7.996),  SIMDE_FLOAT16_C(  14.266) },
      {  SIMDE_FLOAT16_C( 144.771), -SIMDE_FLOAT16_C( 132.375), -SIMDE_FLOAT16_C(  36.358),  SIMDE_FLOAT16_C(  89.974) } },
    { {  SIMDE_FLOAT16_C(   6.479), -SIMDE_FLOAT16_C(  10.551),  SIMDE_FLOAT16_C(   5.370),  SIMDE_FLOAT16_C(   7.647) },
      {  SIMDE_FLOAT16_C(   7.155), -SIMDE_FLOAT16_C(   8.084), -SIMDE_FLOAT16_C(   7.527),  SIMDE_FLOAT16_C(  14.352) },
      { -SIMDE_FLOAT16_C(   9.566), -SIMDE_FLOAT16_C(   2.051), -SIMDE_FLOAT16_C(   0.646),  SIMDE_FLOAT16_C(  14.658) },
      {  SIMDE_FLOAT16_C(  36.791), -SIMDE_FLOAT16_C(  54.427), -SIMDE_FLOAT16_C(  41.066),  SIMDE_FLOAT16_C(  91.728) } },
    { {  SIMDE_FLOAT16_C(  14.902),  SIMDE_FLOAT16_C(   5.583), -SIMDE_FLOAT16_C(   0.964), -SIMDE_FLOAT16_C(   3.595) },
      {  SIMDE_FLOAT16_C(   8.258), -SIMDE_FLOAT16_C(   8.017), -SIMDE_FLOAT16_C(   0.371),  SIMDE_FLOAT16_C(  11.306) },
      {  SIMDE_FLOAT16_C(   1.689),  SIMDE_FLOAT16_C(   3.958),  SIMDE_FLOAT16_C(   4.635),  SIMDE_FLOAT16_C(   5.936) },
      {  SIMDE_FLOAT16_C( 124.750), -SIMDE_FLOAT16_C( 115.511),  SIMDE_FLOAT16_C(   4.993), -SIMDE_FLOAT16_C(   4.963) } },
    { {  SIMDE_FLOAT16_C(  12.690), -SIMDE_FLOAT16_C(   5.992),  SIMDE_FLOAT16_C(  13.634),  SIMDE_FLOAT16_C(  10.995) },
      {  SIMDE_FLOAT16_C(   9.694), -SIMDE_FLOAT16_C(   4.324), -SIMDE_FLOAT16_C(  13.875), -SIMDE_FLOAT16_C(  10.074) },
      { -SIMDE_FLOAT16_C(   8.517),  SIMDE_FLOAT16_C(   0.071),  SIMDE_FLOAT16_C(  14.890), -SIMDE_FLOAT16_C(   6.765) },
      {  SIMDE_FLOAT16_C( 114.500), -SIMDE_FLOAT16_C(  54.801), -SIMDE_FLOAT16_C( 174.282), -SIMDE_FLOAT16_C( 144.000) } },
    { { -SIMDE_FLOAT16_C(   2.913),  SIMDE_FLOAT16_C(   1.285), -SIMDE_FLOAT16_C(   5.910), -SIMDE_FLOAT16_C(   7.043) },
      {  SIMDE_FLOAT16_C(   6.508), -SIMDE_FLOAT16_C(   0.206),  SIMDE_FLOAT16_C(   8.282), -SIMDE_FLOAT16_C(   5.635) },
      {  SIMDE_FLOAT16_C(   4.193),  SIMDE_FLOAT16_C(   8.883),  SIMDE_FLOAT16_C(   1.038),  SIMDE_FLOAT16_C(   2.650) },
      { -SIMDE_FLOAT16_C(  14.765),  SIMDE_FLOAT16_C(   9.483), -SIMDE_FLOAT16_C(  47.909),  SIMDE_FLOAT16_C(  35.953) } },
    { { -SIMDE_FLOAT16_C(   8.667), -SIMDE_FLOAT16_C(   9.058),  SIMDE_FLOAT16_C(   0.413), -SIMDE_FLOAT16_C(   6.915) },
      { -SIMDE_FLOAT16_C(   9.594), -SIMDE_FLOAT16_C(   4.142), -SIMDE_FLOAT16_C(  13.624),  SIMDE_FLOAT16_C(   3.616) },
      {  SIMDE_FLOAT16_C(   9.875),  SIMDE_FLOAT16_C(  13.498), -SIMDE_FLOAT16_C(  10.113), -SIMDE_FLOAT16_C(   8.469) },
      {  SIMDE_FLOAT16_C(  93.026),  SIMDE_FLOAT16_C(  49.397), -SIMDE_FLOAT16_C(  15.740), -SIMDE_FLOAT16_C(   6.976) } },
    { {  SIMDE_FLOAT16_C(  10.926),  SIMDE_FLOAT16_C(   9.739),  SIMDE_FLOAT16_C(   1.593),  SIMDE_FLOAT16_C(   9.358) },
      { -SIMDE_FLOAT16_C(   9.690), -SIMDE_FLOAT16_C(  14.054), -SIMDE_FLOAT16_C(  11.425), -SIMDE_FLOAT16_C(   9.229) },
      { -SIMDE_FLOAT16_C(  12.442),  SIMDE_FLOAT16_C(   9.777),  SIMDE_FLOAT16_C(   7.931), -SIMDE_FLOAT16_C(   0.352) },
      { -SIMDE_FLOAT16_C( 118.315), -SIMDE_FLOAT16_C( 143.875), -SIMDE_FLOAT16_C(  10.269), -SIMDE_FLOAT16_C(  15.054) } },
    { { -SIMDE_FLOAT16_C(   4.708), -SIMDE_FLOAT16_C(   9.401),  SIMDE_FLOAT16_C(  10.464), -SIMDE_FLOAT16_C(   2.625) },
      {  SIMDE_FLOAT16_C(  10.591), -SIMDE_FLOAT16_C(   9.143), -SIMDE_FLOAT16_C(  10.033), -SIMDE_FLOAT16_C(  14.441) },
      {  SIMDE_FLOAT16_C(  14.550),  SIMDE_FLOAT16_C(  12.138),  SIMDE_FLOAT16_C(   5.496), -SIMDE_FLOAT16_C(   3.696) },
      { -SIMDE_FLOAT16_C(  35.312),  SIMDE_FLOAT16_C(  55.183), -SIMDE_FLOAT16_C(  99.489), -SIMDE_FLOAT16_C( 154.807) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r = simde_vld1_f16(test_vec[i].r);
    simde_float16x4_t r_ = simde_vcmla_f16(r, a, b);

    simde_test_arm_neon_assert_equal_f16x4(r_, simde_vld1_f16(test_vec[i].r_), 1);
  }

  return 0;
}

static int
test_simde_vcmla_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   212.87), SIMDE_FLOAT32_C(    70.46) },
      { SIMDE_FLOAT32_C(  -900.86), SIMDE_FLOAT32_C(  -975.82) },
      { SIMDE_FLOAT32_C(  -978.80), SIMDE_FLOAT32_C(   764.65) },
      { SIMDE_FLOAT32_C(-192744.86), SIMDE_FLOAT32_C(-206958.16) } },
    { { SIMDE_FLOAT32_C(  -187.99), SIMDE_FLOAT32_C(    49.57) },
      { SIMDE_FLOAT32_C(  -750.73), SIMDE_FLOAT32_C(   590.72) },
      { SIMDE_FLOAT32_C(   251.58), SIMDE_FLOAT32_C(   997.06) },
      { SIMDE_FLOAT32_C(141381.31), SIMDE_FLOAT32_C(-110052.39) } },
    { { SIMDE_FLOAT32_C(  -131.09), SIMDE_FLOAT32_C(  -878.84) },
      { SIMDE_FLOAT32_C(   800.24), SIMDE_FLOAT32_C(   223.42) },
      { SIMDE_FLOAT32_C(  -487.42), SIMDE_FLOAT32_C(  -464.44) },
      { SIMDE_FLOAT32_C(-105390.88), SIMDE_FLOAT32_C(-29752.57) } },
    { { SIMDE_FLOAT32_C(   669.97), SIMDE_FLOAT32_C(  -863.16) },
      { SIMDE_FLOAT32_C(   580.78), SIMDE_FLOAT32_C(  -195.58) },
      { SIMDE_FLOAT32_C(  -125.02), SIMDE_FLOAT32_C(  -125.29) },
      { SIMDE_FLOAT32_C(388980.16), SIMDE_FLOAT32_C(-131158.02) } },
    { { SIMDE_FLOAT32_C(    11.00), SIMDE_FLOAT32_C(  -886.22) },
      { SIMDE_FLOAT32_C(  -210.36), SIMDE_FLOAT32_C(  -525.26) },
      { SIMDE_FLOAT32_C(  -275.11), SIMDE_FLOAT32_C(  -377.71) },
      { SIMDE_FLOAT32_C( -2589.07), SIMDE_FLOAT32_C( -6155.57) } },
    { { SIMDE_FLOAT32_C(   383.29), SIMDE_FLOAT32_C(   937.75) },
      { SIMDE_FLOAT32_C(   692.75), SIMDE_FLOAT32_C(   482.42) },
      { SIMDE_FLOAT32_C(   961.94), SIMDE_FLOAT32_C(   713.95) },
      { SIMDE_FLOAT32_C(266486.09), SIMDE_FLOAT32_C(185620.72) } },
    { { SIMDE_FLOAT32_C(   247.08), SIMDE_FLOAT32_C(  -226.05) },
      { SIMDE_FLOAT32_C(  -236.48), SIMDE_FLOAT32_C(   496.35) },
      { SIMDE_FLOAT32_C(  -635.33), SIMDE_FLOAT32_C(  -984.90) },
      { SIMDE_FLOAT32_C(-59064.81), SIMDE_FLOAT32_C(121653.26) } },
    { { SIMDE_FLOAT32_C(   493.40), SIMDE_FLOAT32_C(   233.58) },
      { SIMDE_FLOAT32_C(  -863.74), SIMDE_FLOAT32_C(   293.64) },
      { SIMDE_FLOAT32_C(  -543.00), SIMDE_FLOAT32_C(  -351.16) },
      { SIMDE_FLOAT32_C(-426712.31), SIMDE_FLOAT32_C(144530.83) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vld1_f32(test_vec[i].r);
    simde_float32x2_t r_ = simde_vcmla_f32(r, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r_, simde_vld1_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r_ = simde_vcmla_f32(r, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
    simde_float16 r_[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(   2.660), -SIMDE_FLOAT16_C(   0.125), -SIMDE_FLOAT16_C(  11.136),  SIMDE_FLOAT16_C(  13.855),
         SIMDE_FLOAT16_C(   8.555), -SIMDE_FLOAT16_C(   9.847), -SIMDE_FLOAT16_C(   5.094),  SIMDE_FLOAT16_C(  13.275) },
      {  SIMDE_FLOAT16_C(   9.062),  SIMDE_FLOAT16_C(  12.419),  SIMDE_FLOAT16_C(  14.777), -SIMDE_FLOAT16_C(  11.186),
         SIMDE_FLOAT16_C(   2.568),  SIMDE_FLOAT16_C(  11.524), -SIMDE_FLOAT16_C(   5.565),  SIMDE_FLOAT16_C(   8.693) },
      { -SIMDE_FLOAT16_C(  14.151),  SIMDE_FLOAT16_C(  13.346),  SIMDE_FLOAT16_C(   7.830),  SIMDE_FLOAT16_C(  12.618),
        -SIMDE_FLOAT16_C(  14.338), -SIMDE_FLOAT16_C(   7.896), -SIMDE_FLOAT16_C(   4.686), -SIMDE_FLOAT16_C(   8.748) },
      {  SIMDE_FLOAT16_C(   9.954),  SIMDE_FLOAT16_C(  46.381), -SIMDE_FLOAT16_C( 156.625),  SIMDE_FLOAT16_C( 137.185),
         SIMDE_FLOAT16_C(   7.631),  SIMDE_FLOAT16_C(  90.692),  SIMDE_FLOAT16_C(  23.662), -SIMDE_FLOAT16_C(  53.030) } },
    { { -SIMDE_FLOAT16_C(  12.047), -SIMDE_FLOAT16_C(   1.499),  SIMDE_FLOAT16_C(  10.278), -SIMDE_FLOAT16_C(   7.319),
        -SIMDE_FLOAT16_C(  14.738),  SIMDE_FLOAT16_C(   3.708), -SIMDE_FLOAT16_C(   5.660),  SIMDE_FLOAT16_C(  13.023) },
      {  SIMDE_FLOAT16_C(  11.315),  SIMDE_FLOAT16_C(  10.815), -SIMDE_FLOAT16_C(  13.083), -SIMDE_FLOAT16_C(   7.453),
        -SIMDE_FLOAT16_C(   8.416),  SIMDE_FLOAT16_C(  12.161), -SIMDE_FLOAT16_C(  13.028),  SIMDE_FLOAT16_C(  13.979) },
      { -SIMDE_FLOAT16_C(  10.629), -SIMDE_FLOAT16_C(  11.813),  SIMDE_FLOAT16_C(   2.147), -SIMDE_FLOAT16_C(   1.617),
        -SIMDE_FLOAT16_C(  14.156),  SIMDE_FLOAT16_C(   0.763), -SIMDE_FLOAT16_C(  10.355), -SIMDE_FLOAT16_C(   8.688) },
      { -SIMDE_FLOAT16_C( 146.875), -SIMDE_FLOAT16_C( 142.101), -SIMDE_FLOAT16_C( 132.320), -SIMDE_FLOAT16_C(  78.219),
         SIMDE_FLOAT16_C( 109.879), -SIMDE_FLOAT16_C( 178.466),  SIMDE_FLOAT16_C(  63.383), -SIMDE_FLOAT16_C(  87.809) } },
    { {  SIMDE_FLOAT16_C(  13.462),  SIMDE_FLOAT16_C(  13.564),  SIMDE_FLOAT16_C(   0.387), -SIMDE_FLOAT16_C(   5.852),
        -SIMDE_FLOAT16_C(   6.617),  SIMDE_FLOAT16_C(   6.807),  SIMDE_FLOAT16_C(   6.317),  SIMDE_FLOAT16_C(   5.651) },
      { -SIMDE_FLOAT16_C(  14.262), -SIMDE_FLOAT16_C(   1.927), -SIMDE_FLOAT16_C(   2.843), -SIMDE_FLOAT16_C(   1.056),
         SIMDE_FLOAT16_C(  13.280), -SIMDE_FLOAT16_C(  10.463), -SIMDE_FLOAT16_C(   2.439),  SIMDE_FLOAT16_C(   9.177) },
      { -SIMDE_FLOAT16_C(  10.779),  SIMDE_FLOAT16_C(   3.828), -SIMDE_FLOAT16_C(  10.057),  SIMDE_FLOAT16_C(  11.249),
         SIMDE_FLOAT16_C(   3.804),  SIMDE_FLOAT16_C(  12.748), -SIMDE_FLOAT16_C(   4.565), -SIMDE_FLOAT16_C(   1.800) },
      { -SIMDE_FLOAT16_C( 202.774), -SIMDE_FLOAT16_C(  22.113), -SIMDE_FLOAT16_C(  11.157),  SIMDE_FLOAT16_C(  10.840),
        -SIMDE_FLOAT16_C(  84.070),  SIMDE_FLOAT16_C(  81.982), -SIMDE_FLOAT16_C(  19.972),  SIMDE_FLOAT16_C(  56.171) } },
    { { -SIMDE_FLOAT16_C(   0.769),  SIMDE_FLOAT16_C(   5.730), -SIMDE_FLOAT16_C(  10.003), -SIMDE_FLOAT16_C(   9.301),
         SIMDE_FLOAT16_C(  10.283),  SIMDE_FLOAT16_C(  11.235),  SIMDE_FLOAT16_C(   0.729),  SIMDE_FLOAT16_C(   9.599) },
      {  SIMDE_FLOAT16_C(   7.422), -SIMDE_FLOAT16_C(   1.447),  SIMDE_FLOAT16_C(  11.320), -SIMDE_FLOAT16_C(   9.983),
         SIMDE_FLOAT16_C(   6.695),  SIMDE_FLOAT16_C(   9.049), -SIMDE_FLOAT16_C(  14.700), -SIMDE_FLOAT16_C(   4.056) },
      {  SIMDE_FLOAT16_C(  11.993), -SIMDE_FLOAT16_C(   6.320), -SIMDE_FLOAT16_C(   1.870),  SIMDE_FLOAT16_C(   5.734),
         SIMDE_FLOAT16_C(  13.703),  SIMDE_FLOAT16_C(   1.444),  SIMDE_FLOAT16_C(   3.544),  SIMDE_FLOAT16_C(  10.590) },
      {  SIMDE_FLOAT16_C(   6.285), -SIMDE_FLOAT16_C(   5.207), -SIMDE_FLOAT16_C( 115.104),  SIMDE_FLOAT16_C( 105.594),
         SIMDE_FLOAT16_C(  82.548),  SIMDE_FLOAT16_C(  94.495), -SIMDE_FLOAT16_C(   7.172),  SIMDE_FLOAT16_C(   7.633) } },
    { { -SIMDE_FLOAT16_C(  14.819), -SIMDE_FLOAT16_C(  13.424), -SIMDE_FLOAT16_C(  14.285), -SIMDE_FLOAT16_C(   1.952),
        -SIMDE_FLOAT16_C(  12.797),  SIMDE_FLOAT16_C(   2.774),  SIMDE_FLOAT16_C(  12.656),  SIMDE_FLOAT16_C(  14.733) },
      {  SIMDE_FLOAT16_C(  11.577), -SIMDE_FLOAT16_C(   5.697), -SIMDE_FLOAT16_C(  14.071),  SIMDE_FLOAT16_C(   5.989),
        -SIMDE_FLOAT16_C(   0.981),  SIMDE_FLOAT16_C(  14.537),  SIMDE_FLOAT16_C(   0.749), -SIMDE_FLOAT16_C(  13.564) },
      {  SIMDE_FLOAT16_C(  10.165),  SIMDE_FLOAT16_C(   2.393), -SIMDE_FLOAT16_C(   4.059), -SIMDE_FLOAT16_C(  12.754),
        -SIMDE_FLOAT16_C(   5.329), -SIMDE_FLOAT16_C(   5.615),  SIMDE_FLOAT16_C(   4.648),  SIMDE_FLOAT16_C(   3.512) },
      { -SIMDE_FLOAT16_C( 161.395),  SIMDE_FLOAT16_C(  86.817),  SIMDE_FLOAT16_C( 196.875), -SIMDE_FLOAT16_C(  98.307),
         SIMDE_FLOAT16_C(   7.225), -SIMDE_FLOAT16_C( 191.645),  SIMDE_FLOAT16_C(  14.127), -SIMDE_FLOAT16_C( 168.154) } },
    { {  SIMDE_FLOAT16_C(  12.104),  SIMDE_FLOAT16_C(  14.127), -SIMDE_FLOAT16_C(  12.810),  SIMDE_FLOAT16_C(  13.261),
         SIMDE_FLOAT16_C(   0.594),  SIMDE_FLOAT16_C(  13.117),  SIMDE_FLOAT16_C(  14.321), -SIMDE_FLOAT16_C(   8.977) },
      {  SIMDE_FLOAT16_C(   6.318), -SIMDE_FLOAT16_C(   6.941), -SIMDE_FLOAT16_C(   1.574),  SIMDE_FLOAT16_C(   9.272),
         SIMDE_FLOAT16_C(   5.292), -SIMDE_FLOAT16_C(   3.907),  SIMDE_FLOAT16_C(   2.096), -SIMDE_FLOAT16_C(   2.906) },
      { -SIMDE_FLOAT16_C(   9.903),  SIMDE_FLOAT16_C(  14.229), -SIMDE_FLOAT16_C(  13.996), -SIMDE_FLOAT16_C(   1.765),
        -SIMDE_FLOAT16_C(  10.959), -SIMDE_FLOAT16_C(   4.766),  SIMDE_FLOAT16_C(   7.253), -SIMDE_FLOAT16_C(  12.000) },
      {  SIMDE_FLOAT16_C(  66.570), -SIMDE_FLOAT16_C(  69.785),  SIMDE_FLOAT16_C(   6.167), -SIMDE_FLOAT16_C( 120.539),
        -SIMDE_FLOAT16_C(   7.816), -SIMDE_FLOAT16_C(   7.087),  SIMDE_FLOAT16_C(  37.270), -SIMDE_FLOAT16_C(  53.617) } },
    { { -SIMDE_FLOAT16_C(   9.081), -SIMDE_FLOAT16_C(   6.627),  SIMDE_FLOAT16_C(   9.325),  SIMDE_FLOAT16_C(  12.985),
         SIMDE_FLOAT16_C(  10.502), -SIMDE_FLOAT16_C(   2.384), -SIMDE_FLOAT16_C(   1.044),  SIMDE_FLOAT16_C(   7.203) },
      {  SIMDE_FLOAT16_C(   1.061), -SIMDE_FLOAT16_C(   4.808), -SIMDE_FLOAT16_C(   3.896),  SIMDE_FLOAT16_C(  13.617),
         SIMDE_FLOAT16_C(   1.253),  SIMDE_FLOAT16_C(   1.269),  SIMDE_FLOAT16_C(  12.637),  SIMDE_FLOAT16_C(   7.841) },
      { -SIMDE_FLOAT16_C(  13.392),  SIMDE_FLOAT16_C(   2.028),  SIMDE_FLOAT16_C(   9.657),  SIMDE_FLOAT16_C(   8.654),
         SIMDE_FLOAT16_C(   5.011),  SIMDE_FLOAT16_C(  11.006),  SIMDE_FLOAT16_C(   6.390), -SIMDE_FLOAT16_C(   5.339) },
      { -SIMDE_FLOAT16_C(  23.027),  SIMDE_FLOAT16_C(  45.689), -SIMDE_FLOAT16_C(  26.673),  SIMDE_FLOAT16_C( 135.633),
         SIMDE_FLOAT16_C(  18.170),  SIMDE_FLOAT16_C(  24.333), -SIMDE_FLOAT16_C(   6.803), -SIMDE_FLOAT16_C(  13.525) } },
    { { -SIMDE_FLOAT16_C(   9.044),  SIMDE_FLOAT16_C(   4.997), -SIMDE_FLOAT16_C(   3.491),  SIMDE_FLOAT16_C(   8.835),
         SIMDE_FLOAT16_C(   6.493), -SIMDE_FLOAT16_C(  14.148), -SIMDE_FLOAT16_C(   9.377),  SIMDE_FLOAT16_C(   0.898) },
      { -SIMDE_FLOAT16_C(   1.146), -SIMDE_FLOAT16_C(   8.006),  SIMDE_FLOAT16_C(   2.743), -SIMDE_FLOAT16_C(   4.727),
         SIMDE_FLOAT16_C(   4.020), -SIMDE_FLOAT16_C(  14.476), -SIMDE_FLOAT16_C(   4.336),  SIMDE_FLOAT16_C(   0.841) },
      {  SIMDE_FLOAT16_C(  10.704),  SIMDE_FLOAT16_C(   5.885), -SIMDE_FLOAT16_C(   2.906),  SIMDE_FLOAT16_C(   2.583),
        -SIMDE_FLOAT16_C(  10.201), -SIMDE_FLOAT16_C(  12.433),  SIMDE_FLOAT16_C(   3.257),  SIMDE_FLOAT16_C(   4.737) },
      {  SIMDE_FLOAT16_C(  21.068),  SIMDE_FLOAT16_C(  78.291), -SIMDE_FLOAT16_C(  12.482),  SIMDE_FLOAT16_C(  19.085),
         SIMDE_FLOAT16_C(  15.901), -SIMDE_FLOAT16_C( 106.426),  SIMDE_FLOAT16_C(  43.916), -SIMDE_FLOAT16_C(   3.149) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vld1q_f16(test_vec[i].r);
    simde_float16x8_t r_ = simde_vcmlaq_f16(r, a, b);
    simde_test_arm_neon_assert_equal_f16x8(r_, simde_vld1q_f16(test_vec[i].r_), 1);
  }

  return 0;
}

static int
test_simde_vcmlaq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -44.15), SIMDE_FLOAT32_C(   162.35), SIMDE_FLOAT32_C(  -263.81), SIMDE_FLOAT32_C(  -419.51) },
      { SIMDE_FLOAT32_C(   557.47), SIMDE_FLOAT32_C(   231.31), SIMDE_FLOAT32_C(  -146.84), SIMDE_FLOAT32_C(  -373.27) },
      { SIMDE_FLOAT32_C(   890.34), SIMDE_FLOAT32_C(   811.38), SIMDE_FLOAT32_C(  -300.85), SIMDE_FLOAT32_C(   -15.80) },
      { SIMDE_FLOAT32_C(-23721.96), SIMDE_FLOAT32_C( -9400.96), SIMDE_FLOAT32_C( 38437.01), SIMDE_FLOAT32_C( 98456.55) } },
    { { SIMDE_FLOAT32_C(  -992.19), SIMDE_FLOAT32_C(   519.83), SIMDE_FLOAT32_C(  -699.21), SIMDE_FLOAT32_C(   988.58) },
      { SIMDE_FLOAT32_C(   744.14), SIMDE_FLOAT32_C(  -947.63), SIMDE_FLOAT32_C(   992.55), SIMDE_FLOAT32_C(   654.06) },
      { SIMDE_FLOAT32_C(  -430.76), SIMDE_FLOAT32_C(  -498.64), SIMDE_FLOAT32_C(  -584.99), SIMDE_FLOAT32_C(   338.77) },
      { SIMDE_FLOAT32_C(-738759.06), SIMDE_FLOAT32_C(939730.38), SIMDE_FLOAT32_C(-694585.88), SIMDE_FLOAT32_C(-456986.53) } },
    { { SIMDE_FLOAT32_C(  -355.89), SIMDE_FLOAT32_C(  -589.60), SIMDE_FLOAT32_C(   579.00), SIMDE_FLOAT32_C(  -954.28) },
      { SIMDE_FLOAT32_C(  -272.65), SIMDE_FLOAT32_C(   977.05), SIMDE_FLOAT32_C(  -572.00), SIMDE_FLOAT32_C(   683.20) },
      { SIMDE_FLOAT32_C(   139.40), SIMDE_FLOAT32_C(   164.19), SIMDE_FLOAT32_C(  -736.30), SIMDE_FLOAT32_C(  -303.12) },
      { SIMDE_FLOAT32_C( 97172.81), SIMDE_FLOAT32_C(-347558.16), SIMDE_FLOAT32_C(-331924.31), SIMDE_FLOAT32_C(395269.69) } },
    { { SIMDE_FLOAT32_C(  -604.50), SIMDE_FLOAT32_C(   116.85), SIMDE_FLOAT32_C(   323.61), SIMDE_FLOAT32_C(  -714.16) },
      { SIMDE_FLOAT32_C(   -71.76), SIMDE_FLOAT32_C(  -977.24), SIMDE_FLOAT32_C(   270.05), SIMDE_FLOAT32_C(   -63.95) },
      { SIMDE_FLOAT32_C(   542.59), SIMDE_FLOAT32_C(   570.84), SIMDE_FLOAT32_C(   -75.38), SIMDE_FLOAT32_C(   286.73) },
      { SIMDE_FLOAT32_C( 43921.51), SIMDE_FLOAT32_C(591312.44), SIMDE_FLOAT32_C( 87315.49), SIMDE_FLOAT32_C(-20408.13) } },
    { { SIMDE_FLOAT32_C(   623.21), SIMDE_FLOAT32_C(   -82.82), SIMDE_FLOAT32_C(   -59.21), SIMDE_FLOAT32_C(  -807.55) },
      { SIMDE_FLOAT32_C(   418.54), SIMDE_FLOAT32_C(   355.80), SIMDE_FLOAT32_C(   531.22), SIMDE_FLOAT32_C(  -937.34) },
      { SIMDE_FLOAT32_C(   766.20), SIMDE_FLOAT32_C(   110.21), SIMDE_FLOAT32_C(  -891.63), SIMDE_FLOAT32_C(  -506.46) },
      { SIMDE_FLOAT32_C(261604.53), SIMDE_FLOAT32_C(221848.33), SIMDE_FLOAT32_C(-32345.16), SIMDE_FLOAT32_C( 54993.44) } },
    { { SIMDE_FLOAT32_C(    87.27), SIMDE_FLOAT32_C(  -463.63), SIMDE_FLOAT32_C(  -823.25), SIMDE_FLOAT32_C(  -773.33) },
      { SIMDE_FLOAT32_C(   700.56), SIMDE_FLOAT32_C(  -559.56), SIMDE_FLOAT32_C(   -76.45), SIMDE_FLOAT32_C(  -903.93) },
      { SIMDE_FLOAT32_C(   557.30), SIMDE_FLOAT32_C(  -752.84), SIMDE_FLOAT32_C(  -618.09), SIMDE_FLOAT32_C(  -514.46) },
      { SIMDE_FLOAT32_C( 61695.17), SIMDE_FLOAT32_C(-49585.64), SIMDE_FLOAT32_C( 62319.37), SIMDE_FLOAT32_C(743645.94) } },
    { { SIMDE_FLOAT32_C(  -730.08), SIMDE_FLOAT32_C(   651.96), SIMDE_FLOAT32_C(   421.58), SIMDE_FLOAT32_C(   812.51) },
      { SIMDE_FLOAT32_C(   222.80), SIMDE_FLOAT32_C(  -653.79), SIMDE_FLOAT32_C(    99.24), SIMDE_FLOAT32_C(  -153.99) },
      { SIMDE_FLOAT32_C(   263.39), SIMDE_FLOAT32_C(  -959.97), SIMDE_FLOAT32_C(    38.46), SIMDE_FLOAT32_C(  -318.07) },
      { SIMDE_FLOAT32_C(-162398.44), SIMDE_FLOAT32_C(476359.03), SIMDE_FLOAT32_C( 41876.06), SIMDE_FLOAT32_C(-65237.18) } },
    { { SIMDE_FLOAT32_C(   395.83), SIMDE_FLOAT32_C(  -430.33), SIMDE_FLOAT32_C(  -255.42), SIMDE_FLOAT32_C(   162.03) },
      { SIMDE_FLOAT32_C(   679.89), SIMDE_FLOAT32_C(  -147.05), SIMDE_FLOAT32_C(   655.57), SIMDE_FLOAT32_C(  -232.84) },
      { SIMDE_FLOAT32_C(   389.33), SIMDE_FLOAT32_C(   832.32), SIMDE_FLOAT32_C(    -6.17), SIMDE_FLOAT32_C(    89.89) },
      { SIMDE_FLOAT32_C(269510.19), SIMDE_FLOAT32_C(-57374.48), SIMDE_FLOAT32_C(-167451.86), SIMDE_FLOAT32_C( 59561.88) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vld1q_f32(test_vec[i].r);
    simde_float32x4_t r_ = simde_vcmlaq_f32(r, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r_, simde_vld1q_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r_ = simde_vcmlaq_f32(r, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
    simde_float64 r_[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -57.99), SIMDE_FLOAT64_C(   135.55) },
      { SIMDE_FLOAT64_C(  -596.04), SIMDE_FLOAT64_C(  -782.75) },
      { SIMDE_FLOAT64_C(  -359.68), SIMDE_FLOAT64_C(   599.02) },
      { SIMDE_FLOAT64_C( 34204.68), SIMDE_FLOAT64_C( 45990.69) } },
    { { SIMDE_FLOAT64_C(  -264.72), SIMDE_FLOAT64_C(  -256.75) },
      { SIMDE_FLOAT64_C(   447.46), SIMDE_FLOAT64_C(  -783.75) },
      { SIMDE_FLOAT64_C(   191.17), SIMDE_FLOAT64_C(  -558.46) },
      { SIMDE_FLOAT64_C(-118260.44), SIMDE_FLOAT64_C(206915.84) } },
    { { SIMDE_FLOAT64_C(  -770.71), SIMDE_FLOAT64_C(  -784.24) },
      { SIMDE_FLOAT64_C(  -699.41), SIMDE_FLOAT64_C(   563.40) },
      { SIMDE_FLOAT64_C(   833.00), SIMDE_FLOAT64_C(   587.87) },
      { SIMDE_FLOAT64_C(539875.28), SIMDE_FLOAT64_C(-433630.14) } },
    { { SIMDE_FLOAT64_C(  -937.25), SIMDE_FLOAT64_C(  -903.59) },
      { SIMDE_FLOAT64_C(  -150.40), SIMDE_FLOAT64_C(  -333.08) },
      { SIMDE_FLOAT64_C(  -232.36), SIMDE_FLOAT64_C(   783.49) },
      { SIMDE_FLOAT64_C(140730.04), SIMDE_FLOAT64_C(312962.72) } },
    { { SIMDE_FLOAT64_C(   694.12), SIMDE_FLOAT64_C(   454.67) },
      { SIMDE_FLOAT64_C(   921.25), SIMDE_FLOAT64_C(  -888.91) },
      { SIMDE_FLOAT64_C(  -246.87), SIMDE_FLOAT64_C(  -960.96) },
      { SIMDE_FLOAT64_C(639211.18), SIMDE_FLOAT64_C(-617971.17) } },
    { { SIMDE_FLOAT64_C(    69.74), SIMDE_FLOAT64_C(   695.13) },
      { SIMDE_FLOAT64_C(   174.59), SIMDE_FLOAT64_C(   473.70) },
      { SIMDE_FLOAT64_C(   912.38), SIMDE_FLOAT64_C(   814.91) },
      { SIMDE_FLOAT64_C( 13088.29), SIMDE_FLOAT64_C( 33850.75) } },
    { { SIMDE_FLOAT64_C(    72.72), SIMDE_FLOAT64_C(  -352.34) },
      { SIMDE_FLOAT64_C(  -441.84), SIMDE_FLOAT64_C(  -479.82) },
      { SIMDE_FLOAT64_C(  -136.09), SIMDE_FLOAT64_C(   749.33) },
      { SIMDE_FLOAT64_C(-32266.69), SIMDE_FLOAT64_C(-34143.18) } },
    { { SIMDE_FLOAT64_C(   -38.28), SIMDE_FLOAT64_C(    93.20) },
      { SIMDE_FLOAT64_C(   965.09), SIMDE_FLOAT64_C(   262.31) },
      { SIMDE_FLOAT64_C(  -343.40), SIMDE_FLOAT64_C(   798.09) },
      { SIMDE_FLOAT64_C(-37287.05), SIMDE_FLOAT64_C( -9243.14) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vld1q_f64(test_vec[i].r);
    simde_float64x2_t r_ = simde_vcmlaq_f64(r, a, b);
    simde_test_arm_neon_assert_equal_f64x2(r_, simde_vld1q_f64(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r_ = simde_vcmlaq_f64(r, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
