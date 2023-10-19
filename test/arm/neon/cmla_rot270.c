#define SIMDE_TEST_ARM_NEON_INSN cmla_rot270

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot270.h"

static int
test_simde_vcmla_rot270_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
    simde_float16 r_[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(  14.317), -SIMDE_FLOAT16_C(   5.199),  SIMDE_FLOAT16_C(   8.312),  SIMDE_FLOAT16_C(  14.285) },
      {  SIMDE_FLOAT16_C(  11.834), -SIMDE_FLOAT16_C(   4.190),  SIMDE_FLOAT16_C(   9.832),  SIMDE_FLOAT16_C(   5.399) },
      {  SIMDE_FLOAT16_C(  14.530),  SIMDE_FLOAT16_C(  14.919), -SIMDE_FLOAT16_C(  11.627), -SIMDE_FLOAT16_C(  10.592) },
      {  SIMDE_FLOAT16_C(  36.314),  SIMDE_FLOAT16_C(  76.444),  SIMDE_FLOAT16_C(  65.498), -SIMDE_FLOAT16_C( 151.042) } },
    { {  SIMDE_FLOAT16_C(   1.244), -SIMDE_FLOAT16_C(   5.154), -SIMDE_FLOAT16_C(  14.694),  SIMDE_FLOAT16_C(   6.864) },
      {  SIMDE_FLOAT16_C(  14.229), -SIMDE_FLOAT16_C(   4.812), -SIMDE_FLOAT16_C(  13.332),  SIMDE_FLOAT16_C(  11.771) },
      { -SIMDE_FLOAT16_C(   2.838),  SIMDE_FLOAT16_C(   7.614),  SIMDE_FLOAT16_C(   5.140), -SIMDE_FLOAT16_C(  10.514) },
      {  SIMDE_FLOAT16_C(  21.963),  SIMDE_FLOAT16_C(  80.950),  SIMDE_FLOAT16_C(  85.936),  SIMDE_FLOAT16_C(  80.997) } },
    { { -SIMDE_FLOAT16_C(   9.788), -SIMDE_FLOAT16_C(   1.556), -SIMDE_FLOAT16_C(   6.414), -SIMDE_FLOAT16_C(  14.446) },
      { -SIMDE_FLOAT16_C(  13.086), -SIMDE_FLOAT16_C(   6.366),  SIMDE_FLOAT16_C(  14.551), -SIMDE_FLOAT16_C(   6.804) },
      { -SIMDE_FLOAT16_C(   7.215), -SIMDE_FLOAT16_C(  11.668),  SIMDE_FLOAT16_C(   9.720),  SIMDE_FLOAT16_C(   6.214) },
      {  SIMDE_FLOAT16_C(   2.690), -SIMDE_FLOAT16_C(  32.030),  SIMDE_FLOAT16_C( 108.011),  SIMDE_FLOAT16_C( 216.500) } },
    { { -SIMDE_FLOAT16_C(  13.324), -SIMDE_FLOAT16_C(   6.533),  SIMDE_FLOAT16_C(  10.359),  SIMDE_FLOAT16_C(   5.365) },
      {  SIMDE_FLOAT16_C(  14.807), -SIMDE_FLOAT16_C(  11.312), -SIMDE_FLOAT16_C(   4.750), -SIMDE_FLOAT16_C(   3.475) },
      {  SIMDE_FLOAT16_C(  11.634),  SIMDE_FLOAT16_C(  12.197),  SIMDE_FLOAT16_C(   2.925),  SIMDE_FLOAT16_C(  13.960) },
      {  SIMDE_FLOAT16_C(  85.535),  SIMDE_FLOAT16_C( 108.931), -SIMDE_FLOAT16_C(  15.718),  SIMDE_FLOAT16_C(  39.444) } },
    { { -SIMDE_FLOAT16_C(  10.789),  SIMDE_FLOAT16_C(  13.419),  SIMDE_FLOAT16_C(  11.020),  SIMDE_FLOAT16_C(   6.510) },
      { -SIMDE_FLOAT16_C(   3.191),  SIMDE_FLOAT16_C(   8.870), -SIMDE_FLOAT16_C(  11.872),  SIMDE_FLOAT16_C(   7.492) },
      {  SIMDE_FLOAT16_C(  12.924), -SIMDE_FLOAT16_C(   7.734), -SIMDE_FLOAT16_C(   1.877), -SIMDE_FLOAT16_C(  14.023) },
      {  SIMDE_FLOAT16_C( 131.875),  SIMDE_FLOAT16_C(  35.086),  SIMDE_FLOAT16_C(  46.896),  SIMDE_FLOAT16_C(  63.264) } },
    { { -SIMDE_FLOAT16_C(  11.245), -SIMDE_FLOAT16_C(  13.091), -SIMDE_FLOAT16_C(   8.428),  SIMDE_FLOAT16_C(   0.794) },
      { -SIMDE_FLOAT16_C(   6.250), -SIMDE_FLOAT16_C(   2.007), -SIMDE_FLOAT16_C(   2.227), -SIMDE_FLOAT16_C(  13.728) },
      {  SIMDE_FLOAT16_C(   5.443),  SIMDE_FLOAT16_C(   5.694),  SIMDE_FLOAT16_C(  10.309), -SIMDE_FLOAT16_C(   6.647) },
      {  SIMDE_FLOAT16_C(  31.717), -SIMDE_FLOAT16_C(  76.125), -SIMDE_FLOAT16_C(   0.591), -SIMDE_FLOAT16_C(   4.879) } },
    { {  SIMDE_FLOAT16_C(   8.499), -SIMDE_FLOAT16_C(   4.425),  SIMDE_FLOAT16_C(  13.238),  SIMDE_FLOAT16_C(  13.506) },
      {  SIMDE_FLOAT16_C(   5.012), -SIMDE_FLOAT16_C(   8.268),  SIMDE_FLOAT16_C(   0.013), -SIMDE_FLOAT16_C(   0.851) },
      { -SIMDE_FLOAT16_C(   0.162), -SIMDE_FLOAT16_C(  12.425), -SIMDE_FLOAT16_C(  13.388), -SIMDE_FLOAT16_C(   9.498) },
      {  SIMDE_FLOAT16_C(  36.424),  SIMDE_FLOAT16_C(   9.753), -SIMDE_FLOAT16_C(  24.882), -SIMDE_FLOAT16_C(   9.674) } },
    { { -SIMDE_FLOAT16_C(   9.310),  SIMDE_FLOAT16_C(  10.283),  SIMDE_FLOAT16_C(   1.625),  SIMDE_FLOAT16_C(  10.867) },
      { -SIMDE_FLOAT16_C(   2.257),  SIMDE_FLOAT16_C(  13.683),  SIMDE_FLOAT16_C(   2.874), -SIMDE_FLOAT16_C(  11.409) },
      { -SIMDE_FLOAT16_C(   3.524), -SIMDE_FLOAT16_C(   5.018),  SIMDE_FLOAT16_C(  13.170), -SIMDE_FLOAT16_C(  10.560) },
      {  SIMDE_FLOAT16_C( 137.178),  SIMDE_FLOAT16_C(  18.191), -SIMDE_FLOAT16_C( 110.812), -SIMDE_FLOAT16_C(  41.792) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r = simde_vld1_f16(test_vec[i].r);
    simde_float16x4_t r_ = simde_vcmla_rot270_f16(r, a, b);

    simde_test_arm_neon_assert_equal_f16x4(r_, simde_vld1_f16(test_vec[i].r_), 1);
  }

  return 0;
}

static int
test_simde_vcmlaq_rot270_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
    simde_float16 r_[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(  13.623),  SIMDE_FLOAT16_C(   4.120),  SIMDE_FLOAT16_C(  13.875), -SIMDE_FLOAT16_C(   9.445),
        -SIMDE_FLOAT16_C(   4.267), -SIMDE_FLOAT16_C(   8.207),  SIMDE_FLOAT16_C(   3.307),  SIMDE_FLOAT16_C(   2.096) },
      { -SIMDE_FLOAT16_C(   9.948),  SIMDE_FLOAT16_C(  10.516), -SIMDE_FLOAT16_C(  10.230),  SIMDE_FLOAT16_C(   8.231),
         SIMDE_FLOAT16_C(   4.520), -SIMDE_FLOAT16_C(  12.639), -SIMDE_FLOAT16_C(   0.727),  SIMDE_FLOAT16_C(   4.512) },
      {  SIMDE_FLOAT16_C(  12.434),  SIMDE_FLOAT16_C(  11.682),  SIMDE_FLOAT16_C(  12.083),  SIMDE_FLOAT16_C(   3.186),
        -SIMDE_FLOAT16_C(   1.436), -SIMDE_FLOAT16_C(  13.380),  SIMDE_FLOAT16_C(  12.726),  SIMDE_FLOAT16_C(  12.882) },
      {  SIMDE_FLOAT16_C(  55.760),  SIMDE_FLOAT16_C(  52.668), -SIMDE_FLOAT16_C(  65.659), -SIMDE_FLOAT16_C(  93.436),
         SIMDE_FLOAT16_C( 102.292),  SIMDE_FLOAT16_C(  23.716),  SIMDE_FLOAT16_C(  22.183),  SIMDE_FLOAT16_C(  14.406) } },
    { {  SIMDE_FLOAT16_C(   9.988), -SIMDE_FLOAT16_C(  14.412), -SIMDE_FLOAT16_C(   3.477),  SIMDE_FLOAT16_C(  14.547),
        -SIMDE_FLOAT16_C(  13.915), -SIMDE_FLOAT16_C(  13.058),  SIMDE_FLOAT16_C(   2.627), -SIMDE_FLOAT16_C(   5.823) },
      { -SIMDE_FLOAT16_C(   0.689),  SIMDE_FLOAT16_C(   1.276), -SIMDE_FLOAT16_C(  12.021), -SIMDE_FLOAT16_C(   0.516),
        -SIMDE_FLOAT16_C(   3.607), -SIMDE_FLOAT16_C(   2.932),  SIMDE_FLOAT16_C(  12.171), -SIMDE_FLOAT16_C(   3.619) },
      { -SIMDE_FLOAT16_C(  13.903), -SIMDE_FLOAT16_C(   1.887), -SIMDE_FLOAT16_C(   1.107), -SIMDE_FLOAT16_C(   8.997),
        -SIMDE_FLOAT16_C(   6.419), -SIMDE_FLOAT16_C(   0.942),  SIMDE_FLOAT16_C(  11.348), -SIMDE_FLOAT16_C(   8.123) },
      { -SIMDE_FLOAT16_C(  32.293), -SIMDE_FLOAT16_C(  11.817), -SIMDE_FLOAT16_C(   8.613),  SIMDE_FLOAT16_C( 165.872),
         SIMDE_FLOAT16_C(  31.867), -SIMDE_FLOAT16_C(  48.042),  SIMDE_FLOAT16_C(  32.421),  SIMDE_FLOAT16_C(  62.749) } },
    { { -SIMDE_FLOAT16_C(  12.982),  SIMDE_FLOAT16_C(   9.637),  SIMDE_FLOAT16_C(   1.935), -SIMDE_FLOAT16_C(   2.294),
        -SIMDE_FLOAT16_C(   0.379),  SIMDE_FLOAT16_C(   4.350), -SIMDE_FLOAT16_C(   9.731), -SIMDE_FLOAT16_C(   2.410) },
      { -SIMDE_FLOAT16_C(   8.187),  SIMDE_FLOAT16_C(   2.922),  SIMDE_FLOAT16_C(   0.632),  SIMDE_FLOAT16_C(   0.395),
        -SIMDE_FLOAT16_C(   9.626), -SIMDE_FLOAT16_C(   5.573), -SIMDE_FLOAT16_C(   9.382),  SIMDE_FLOAT16_C(  11.978) },
      { -SIMDE_FLOAT16_C(  14.453), -SIMDE_FLOAT16_C(  11.938), -SIMDE_FLOAT16_C(   0.710), -SIMDE_FLOAT16_C(  10.129),
        -SIMDE_FLOAT16_C(  12.266), -SIMDE_FLOAT16_C(   5.999),  SIMDE_FLOAT16_C(   9.135),  SIMDE_FLOAT16_C(   6.563) },
      {  SIMDE_FLOAT16_C(  13.706),  SIMDE_FLOAT16_C(  66.960), -SIMDE_FLOAT16_C(   1.616), -SIMDE_FLOAT16_C(   8.679),
        -SIMDE_FLOAT16_C(  36.509),  SIMDE_FLOAT16_C(  35.874), -SIMDE_FLOAT16_C(  19.732), -SIMDE_FLOAT16_C(  16.048) } },
    { {  SIMDE_FLOAT16_C(   3.520), -SIMDE_FLOAT16_C(   7.325),  SIMDE_FLOAT16_C(   2.132), -SIMDE_FLOAT16_C(  10.139),
         SIMDE_FLOAT16_C(  10.532), -SIMDE_FLOAT16_C(  13.703),  SIMDE_FLOAT16_C(  12.814),  SIMDE_FLOAT16_C(   8.609) },
      {  SIMDE_FLOAT16_C(  13.624),  SIMDE_FLOAT16_C(  13.624),  SIMDE_FLOAT16_C(   0.059), -SIMDE_FLOAT16_C(   7.519),
        -SIMDE_FLOAT16_C(   8.207), -SIMDE_FLOAT16_C(   5.044), -SIMDE_FLOAT16_C(   1.774), -SIMDE_FLOAT16_C(   3.925) },
      {  SIMDE_FLOAT16_C(   9.285),  SIMDE_FLOAT16_C(   6.141), -SIMDE_FLOAT16_C(   2.162),  SIMDE_FLOAT16_C(  13.757),
        -SIMDE_FLOAT16_C(   7.557),  SIMDE_FLOAT16_C(   3.167), -SIMDE_FLOAT16_C(   6.688),  SIMDE_FLOAT16_C(   0.752) },
      { -SIMDE_FLOAT16_C(  90.511),  SIMDE_FLOAT16_C( 105.937),  SIMDE_FLOAT16_C(  74.073),  SIMDE_FLOAT16_C(  14.355),
         SIMDE_FLOAT16_C(  61.561), -SIMDE_FLOAT16_C( 109.294), -SIMDE_FLOAT16_C(  40.478),  SIMDE_FLOAT16_C(  16.024) } },
    { { -SIMDE_FLOAT16_C(   4.514), -SIMDE_FLOAT16_C(   9.156),  SIMDE_FLOAT16_C(   0.416),  SIMDE_FLOAT16_C(   5.447),
        -SIMDE_FLOAT16_C(  12.228), -SIMDE_FLOAT16_C(   5.009), -SIMDE_FLOAT16_C(   7.766),  SIMDE_FLOAT16_C(  10.945) },
      {  SIMDE_FLOAT16_C(   7.411),  SIMDE_FLOAT16_C(   8.790),  SIMDE_FLOAT16_C(  12.635),  SIMDE_FLOAT16_C(   7.756),
         SIMDE_FLOAT16_C(  13.366),  SIMDE_FLOAT16_C(   5.483), -SIMDE_FLOAT16_C(  10.091), -SIMDE_FLOAT16_C(   0.161) },
      {  SIMDE_FLOAT16_C(   0.620), -SIMDE_FLOAT16_C(   8.567), -SIMDE_FLOAT16_C(  12.415),  SIMDE_FLOAT16_C(   2.204),
         SIMDE_FLOAT16_C(   1.114),  SIMDE_FLOAT16_C(   7.729), -SIMDE_FLOAT16_C(   4.641),  SIMDE_FLOAT16_C(  14.227) },
      { -SIMDE_FLOAT16_C(  79.861),  SIMDE_FLOAT16_C(  59.288),  SIMDE_FLOAT16_C(  29.832), -SIMDE_FLOAT16_C(  66.619),
        -SIMDE_FLOAT16_C(  26.350),  SIMDE_FLOAT16_C(  74.679), -SIMDE_FLOAT16_C(   6.403),  SIMDE_FLOAT16_C( 124.673) } },
    { {  SIMDE_FLOAT16_C(   6.461),  SIMDE_FLOAT16_C(   1.109),  SIMDE_FLOAT16_C(   5.959),  SIMDE_FLOAT16_C(   2.609),
         SIMDE_FLOAT16_C(  12.442),  SIMDE_FLOAT16_C(  10.345), -SIMDE_FLOAT16_C(   0.602),  SIMDE_FLOAT16_C(   1.541) },
      {  SIMDE_FLOAT16_C(  11.674), -SIMDE_FLOAT16_C(   4.574), -SIMDE_FLOAT16_C(   9.239), -SIMDE_FLOAT16_C(   8.444),
         SIMDE_FLOAT16_C(  10.338), -SIMDE_FLOAT16_C(  11.683),  SIMDE_FLOAT16_C(   4.882),  SIMDE_FLOAT16_C(   5.109) },
      {  SIMDE_FLOAT16_C(   8.183),  SIMDE_FLOAT16_C(   6.173), -SIMDE_FLOAT16_C(   7.598),  SIMDE_FLOAT16_C(   5.817),
         SIMDE_FLOAT16_C(   4.348),  SIMDE_FLOAT16_C(   7.105),  SIMDE_FLOAT16_C(   3.205),  SIMDE_FLOAT16_C(   7.831) },
      {  SIMDE_FLOAT16_C(   3.110), -SIMDE_FLOAT16_C(   6.773), -SIMDE_FLOAT16_C(  29.628),  SIMDE_FLOAT16_C(  29.922),
        -SIMDE_FLOAT16_C( 116.513), -SIMDE_FLOAT16_C(  99.842),  SIMDE_FLOAT16_C(  11.078),  SIMDE_FLOAT16_C(   0.308) } },
    { { -SIMDE_FLOAT16_C(  14.478), -SIMDE_FLOAT16_C(   9.733), -SIMDE_FLOAT16_C(   4.053), -SIMDE_FLOAT16_C(  11.648),
         SIMDE_FLOAT16_C(  12.374),  SIMDE_FLOAT16_C(   7.437), -SIMDE_FLOAT16_C(  11.911),  SIMDE_FLOAT16_C(   6.692) },
      { -SIMDE_FLOAT16_C(  11.245),  SIMDE_FLOAT16_C(   4.430),  SIMDE_FLOAT16_C(   9.097),  SIMDE_FLOAT16_C(  14.219),
         SIMDE_FLOAT16_C(   8.086), -SIMDE_FLOAT16_C(   6.536),  SIMDE_FLOAT16_C(  10.525), -SIMDE_FLOAT16_C(   5.436) },
      {  SIMDE_FLOAT16_C(  10.659), -SIMDE_FLOAT16_C(  10.646), -SIMDE_FLOAT16_C(   4.555), -SIMDE_FLOAT16_C(  11.024),
         SIMDE_FLOAT16_C(   1.124), -SIMDE_FLOAT16_C(   9.575), -SIMDE_FLOAT16_C(  14.516),  SIMDE_FLOAT16_C(   1.361) },
      { -SIMDE_FLOAT16_C(  32.458), -SIMDE_FLOAT16_C( 120.094), -SIMDE_FLOAT16_C( 170.178),  SIMDE_FLOAT16_C(  94.938),
        -SIMDE_FLOAT16_C(  47.484), -SIMDE_FLOAT16_C(  69.711), -SIMDE_FLOAT16_C(  50.894), -SIMDE_FLOAT16_C(  69.072) } },
    { {  SIMDE_FLOAT16_C(   0.309),  SIMDE_FLOAT16_C(  12.714), -SIMDE_FLOAT16_C(  10.372), -SIMDE_FLOAT16_C(  10.982),
         SIMDE_FLOAT16_C(   4.693),  SIMDE_FLOAT16_C(   3.301), -SIMDE_FLOAT16_C(  13.101), -SIMDE_FLOAT16_C(   7.517) },
      {  SIMDE_FLOAT16_C(  13.425), -SIMDE_FLOAT16_C(  10.586), -SIMDE_FLOAT16_C(  10.615), -SIMDE_FLOAT16_C(  14.475),
        -SIMDE_FLOAT16_C(   0.537),  SIMDE_FLOAT16_C(  12.995),  SIMDE_FLOAT16_C(  11.317),  SIMDE_FLOAT16_C(   8.693) },
      { -SIMDE_FLOAT16_C(   2.615),  SIMDE_FLOAT16_C(   9.039),  SIMDE_FLOAT16_C(   2.823), -SIMDE_FLOAT16_C(   4.982),
         SIMDE_FLOAT16_C(   4.859), -SIMDE_FLOAT16_C(  12.280),  SIMDE_FLOAT16_C(   8.366),  SIMDE_FLOAT16_C(   4.229) },
      { -SIMDE_FLOAT16_C( 137.125), -SIMDE_FLOAT16_C( 161.646),  SIMDE_FLOAT16_C( 161.875), -SIMDE_FLOAT16_C( 121.556),
         SIMDE_FLOAT16_C(  47.755), -SIMDE_FLOAT16_C(  10.507), -SIMDE_FLOAT16_C(  56.979),  SIMDE_FLOAT16_C(  89.299) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vld1q_f16(test_vec[i].r);
    simde_float16x8_t r_ = simde_vcmlaq_rot270_f16(r, a, b);
    simde_test_arm_neon_assert_equal_f16x8(r_, simde_vld1q_f16(test_vec[i].r_), 1);
  }

  return 0;
}

static int
test_simde_vcmla_rot270_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -50.23), SIMDE_FLOAT32_C(   -93.80) },
      { SIMDE_FLOAT32_C(   167.59), SIMDE_FLOAT32_C(    54.72) },
      { SIMDE_FLOAT32_C(   889.39), SIMDE_FLOAT32_C(   -46.05) },
      { SIMDE_FLOAT32_C( -4243.35), SIMDE_FLOAT32_C( 15673.89) } },
    { { SIMDE_FLOAT32_C(  -703.48), SIMDE_FLOAT32_C(   367.81) },
      { SIMDE_FLOAT32_C(   743.72), SIMDE_FLOAT32_C(    47.92) },
      { SIMDE_FLOAT32_C(   999.37), SIMDE_FLOAT32_C(   -87.94) },
      { SIMDE_FLOAT32_C( 18624.82), SIMDE_FLOAT32_C(-273635.59) } },
    { { SIMDE_FLOAT32_C(  -326.37), SIMDE_FLOAT32_C(   604.88) },
      { SIMDE_FLOAT32_C(   224.18), SIMDE_FLOAT32_C(  -994.49) },
      { SIMDE_FLOAT32_C(  -175.46), SIMDE_FLOAT32_C(  -858.15) },
      { SIMDE_FLOAT32_C(-601722.56), SIMDE_FLOAT32_C(-136460.14) } },
    { { SIMDE_FLOAT32_C(  -942.56), SIMDE_FLOAT32_C(    45.37) },
      { SIMDE_FLOAT32_C(   163.87), SIMDE_FLOAT32_C(   969.32) },
      { SIMDE_FLOAT32_C(   778.80), SIMDE_FLOAT32_C(   918.99) },
      { SIMDE_FLOAT32_C( 44756.85), SIMDE_FLOAT32_C( -6515.79) } },
    { { SIMDE_FLOAT32_C(   909.88), SIMDE_FLOAT32_C(   955.41) },
      { SIMDE_FLOAT32_C(   975.43), SIMDE_FLOAT32_C(   253.10) },
      { SIMDE_FLOAT32_C(  -261.19), SIMDE_FLOAT32_C(   233.33) },
      { SIMDE_FLOAT32_C(241553.08), SIMDE_FLOAT32_C(-931702.19) } },
    { { SIMDE_FLOAT32_C(  -953.37), SIMDE_FLOAT32_C(   688.58) },
      { SIMDE_FLOAT32_C(  -860.47), SIMDE_FLOAT32_C(   214.22) },
      { SIMDE_FLOAT32_C(  -256.70), SIMDE_FLOAT32_C(  -971.08) },
      { SIMDE_FLOAT32_C(147250.91), SIMDE_FLOAT32_C(591531.38) } },
    { { SIMDE_FLOAT32_C(  -831.83), SIMDE_FLOAT32_C(    39.82) },
      { SIMDE_FLOAT32_C(   396.73), SIMDE_FLOAT32_C(   911.89) },
      { SIMDE_FLOAT32_C(  -912.26), SIMDE_FLOAT32_C(   396.10) },
      { SIMDE_FLOAT32_C( 35399.20), SIMDE_FLOAT32_C(-15401.69) } },
    { { SIMDE_FLOAT32_C(  -176.06), SIMDE_FLOAT32_C(  -238.62) },
      { SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(  -951.87) },
      { SIMDE_FLOAT32_C(  -233.12), SIMDE_FLOAT32_C(   825.53) },
      { SIMDE_FLOAT32_C(226902.09), SIMDE_FLOAT32_C(  1061.76) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vld1_f32(test_vec[i].r);
    simde_float32x2_t r_ = simde_vcmla_rot270_f32(r, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r_, simde_vld1_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r_ = simde_vcmla_rot270_f32(r, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot270_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   126.46), SIMDE_FLOAT32_C(  -102.84), SIMDE_FLOAT32_C(  -564.92), SIMDE_FLOAT32_C(  -510.64) },
      { SIMDE_FLOAT32_C(   175.98), SIMDE_FLOAT32_C(  -552.56), SIMDE_FLOAT32_C(  -211.73), SIMDE_FLOAT32_C(  -777.22) },
      { SIMDE_FLOAT32_C(   582.03), SIMDE_FLOAT32_C(   874.49), SIMDE_FLOAT32_C(  -164.75), SIMDE_FLOAT32_C(  -792.98) },
      { SIMDE_FLOAT32_C( 57407.30), SIMDE_FLOAT32_C( 18972.27), SIMDE_FLOAT32_C(396714.88), SIMDE_FLOAT32_C(-108910.79) } },
    { { SIMDE_FLOAT32_C(   596.49), SIMDE_FLOAT32_C(  -138.97), SIMDE_FLOAT32_C(   939.08), SIMDE_FLOAT32_C(  -705.25) },
      { SIMDE_FLOAT32_C(   449.34), SIMDE_FLOAT32_C(  -193.80), SIMDE_FLOAT32_C(   928.27), SIMDE_FLOAT32_C(  -625.06) },
      { SIMDE_FLOAT32_C(  -301.19), SIMDE_FLOAT32_C(  -563.73), SIMDE_FLOAT32_C(  -710.46), SIMDE_FLOAT32_C(  -738.46) },
      { SIMDE_FLOAT32_C( 26631.20), SIMDE_FLOAT32_C( 61881.05), SIMDE_FLOAT32_C(440113.09), SIMDE_FLOAT32_C(653924.00) } },
    { { SIMDE_FLOAT32_C(   489.04), SIMDE_FLOAT32_C(   298.23), SIMDE_FLOAT32_C(  -122.18), SIMDE_FLOAT32_C(   614.08) },
      { SIMDE_FLOAT32_C(   157.80), SIMDE_FLOAT32_C(  -378.12), SIMDE_FLOAT32_C(   654.24), SIMDE_FLOAT32_C(  -715.73) },
      { SIMDE_FLOAT32_C(   519.04), SIMDE_FLOAT32_C(  -910.68), SIMDE_FLOAT32_C(  -226.37), SIMDE_FLOAT32_C(  -304.98) },
      { SIMDE_FLOAT32_C(-112247.69), SIMDE_FLOAT32_C(-47971.38), SIMDE_FLOAT32_C(-439741.84), SIMDE_FLOAT32_C(-402060.69) } },
    { { SIMDE_FLOAT32_C(  -463.25), SIMDE_FLOAT32_C(   561.90), SIMDE_FLOAT32_C(   -82.20), SIMDE_FLOAT32_C(  -881.22) },
      { SIMDE_FLOAT32_C(   436.39), SIMDE_FLOAT32_C(   753.06), SIMDE_FLOAT32_C(  -674.20), SIMDE_FLOAT32_C(    32.88) },
      { SIMDE_FLOAT32_C(  -385.92), SIMDE_FLOAT32_C(  -735.12), SIMDE_FLOAT32_C(   327.63), SIMDE_FLOAT32_C(  -936.58) },
      { SIMDE_FLOAT32_C(422758.50), SIMDE_FLOAT32_C(-245942.69), SIMDE_FLOAT32_C(-28646.88), SIMDE_FLOAT32_C(-595055.12) } },
    { { SIMDE_FLOAT32_C(    71.08), SIMDE_FLOAT32_C(   255.90), SIMDE_FLOAT32_C(  -561.64), SIMDE_FLOAT32_C(   769.89) },
      { SIMDE_FLOAT32_C(   692.17), SIMDE_FLOAT32_C(  -272.09), SIMDE_FLOAT32_C(  -968.57), SIMDE_FLOAT32_C(   181.21) },
      { SIMDE_FLOAT32_C(  -973.86), SIMDE_FLOAT32_C(   -90.75), SIMDE_FLOAT32_C(  -204.71), SIMDE_FLOAT32_C(   183.94) },
      { SIMDE_FLOAT32_C(-70601.69), SIMDE_FLOAT32_C(-177217.05), SIMDE_FLOAT32_C(139307.06), SIMDE_FLOAT32_C(745876.31) } },
    { { SIMDE_FLOAT32_C(   531.13), SIMDE_FLOAT32_C(  -550.47), SIMDE_FLOAT32_C(   468.21), SIMDE_FLOAT32_C(    50.17) },
      { SIMDE_FLOAT32_C(  -461.15), SIMDE_FLOAT32_C(  -758.16), SIMDE_FLOAT32_C(   745.19), SIMDE_FLOAT32_C(    75.60) },
      { SIMDE_FLOAT32_C(   803.74), SIMDE_FLOAT32_C(  -337.01), SIMDE_FLOAT32_C(   194.38), SIMDE_FLOAT32_C(   240.13) },
      { SIMDE_FLOAT32_C(418148.03), SIMDE_FLOAT32_C(-254186.23), SIMDE_FLOAT32_C(  3987.23), SIMDE_FLOAT32_C(-37146.05) } },
    { { SIMDE_FLOAT32_C(  -583.95), SIMDE_FLOAT32_C(   520.18), SIMDE_FLOAT32_C(  -726.99), SIMDE_FLOAT32_C(    30.13) },
      { SIMDE_FLOAT32_C(   785.06), SIMDE_FLOAT32_C(   600.64), SIMDE_FLOAT32_C(    93.55), SIMDE_FLOAT32_C(  -143.86) },
      { SIMDE_FLOAT32_C(  -143.46), SIMDE_FLOAT32_C(   531.91), SIMDE_FLOAT32_C(  -373.97), SIMDE_FLOAT32_C(  -451.29) },
      { SIMDE_FLOAT32_C(312297.47), SIMDE_FLOAT32_C(-407840.59), SIMDE_FLOAT32_C( -4708.47), SIMDE_FLOAT32_C( -3269.95) } },
    { { SIMDE_FLOAT32_C(  -740.18), SIMDE_FLOAT32_C(  -342.54), SIMDE_FLOAT32_C(   729.92), SIMDE_FLOAT32_C(  -714.05) },
      { SIMDE_FLOAT32_C(   566.71), SIMDE_FLOAT32_C(  -474.78), SIMDE_FLOAT32_C(   469.90), SIMDE_FLOAT32_C(    97.84) },
      { SIMDE_FLOAT32_C(   -25.25), SIMDE_FLOAT32_C(   -61.89), SIMDE_FLOAT32_C(  -851.99), SIMDE_FLOAT32_C(   513.60) },
      { SIMDE_FLOAT32_C(162605.89), SIMDE_FLOAT32_C(194058.97), SIMDE_FLOAT32_C(-70714.64), SIMDE_FLOAT32_C(336045.69) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vld1q_f32(test_vec[i].r);
    simde_float32x4_t r_ = simde_vcmlaq_rot270_f32(r, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r_, simde_vld1q_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r_ = simde_vcmlaq_rot270_f32(r, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot270_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
    simde_float64 r_[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -772.20), SIMDE_FLOAT64_C(  -289.07) },
      { SIMDE_FLOAT64_C(  -254.86), SIMDE_FLOAT64_C(   875.19) },
      { SIMDE_FLOAT64_C(  -291.25), SIMDE_FLOAT64_C(  -386.54) },
      { SIMDE_FLOAT64_C(-253282.42), SIMDE_FLOAT64_C(-74058.92) } },
    { { SIMDE_FLOAT64_C(   901.93), SIMDE_FLOAT64_C(  -182.45) },
      { SIMDE_FLOAT64_C(  -401.46), SIMDE_FLOAT64_C(   570.66) },
      { SIMDE_FLOAT64_C(  -805.46), SIMDE_FLOAT64_C(   495.43) },
      { SIMDE_FLOAT64_C(-104922.38), SIMDE_FLOAT64_C(-72750.95) } },
    { { SIMDE_FLOAT64_C(   735.86), SIMDE_FLOAT64_C(   696.07) },
      { SIMDE_FLOAT64_C(    67.50), SIMDE_FLOAT64_C(  -993.11) },
      { SIMDE_FLOAT64_C(  -328.56), SIMDE_FLOAT64_C(  -238.82) },
      { SIMDE_FLOAT64_C(-691602.64), SIMDE_FLOAT64_C(-47223.55) } },
    { { SIMDE_FLOAT64_C(  -528.21), SIMDE_FLOAT64_C(   -73.41) },
      { SIMDE_FLOAT64_C(    25.60), SIMDE_FLOAT64_C(  -492.76) },
      { SIMDE_FLOAT64_C(  -996.44), SIMDE_FLOAT64_C(  -171.25) },
      { SIMDE_FLOAT64_C( 35177.07), SIMDE_FLOAT64_C(  1708.05) } },
    { { SIMDE_FLOAT64_C(   532.55), SIMDE_FLOAT64_C(    64.30) },
      { SIMDE_FLOAT64_C(  -451.87), SIMDE_FLOAT64_C(  -697.40) },
      { SIMDE_FLOAT64_C(  -232.31), SIMDE_FLOAT64_C(  -793.59) },
      { SIMDE_FLOAT64_C(-45075.13), SIMDE_FLOAT64_C( 28261.65) } },
    { { SIMDE_FLOAT64_C(    99.38), SIMDE_FLOAT64_C(    -4.51) },
      { SIMDE_FLOAT64_C(   -82.66), SIMDE_FLOAT64_C(   844.53) },
      { SIMDE_FLOAT64_C(  -129.32), SIMDE_FLOAT64_C(   626.09) },
      { SIMDE_FLOAT64_C( -3938.15), SIMDE_FLOAT64_C(   253.29) } },
    { { SIMDE_FLOAT64_C(  -542.02), SIMDE_FLOAT64_C(  -227.39) },
      { SIMDE_FLOAT64_C(  -556.35), SIMDE_FLOAT64_C(    56.52) },
      { SIMDE_FLOAT64_C(  -656.73), SIMDE_FLOAT64_C(  -361.81) },
      { SIMDE_FLOAT64_C(-13508.81), SIMDE_FLOAT64_C(-126870.24) } },
    { { SIMDE_FLOAT64_C(  -448.05), SIMDE_FLOAT64_C(  -920.87) },
      { SIMDE_FLOAT64_C(  -665.74), SIMDE_FLOAT64_C(   619.45) },
      { SIMDE_FLOAT64_C(  -913.98), SIMDE_FLOAT64_C(     5.70) },
      { SIMDE_FLOAT64_C(-571346.90), SIMDE_FLOAT64_C(-613054.29) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vld1q_f64(test_vec[i].r);
    simde_float64x2_t r_ = simde_vcmlaq_rot270_f64(r, a, b);
    simde_test_arm_neon_assert_equal_f64x2(r_, simde_vld1q_f64(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r_ = simde_vcmlaq_rot270_f64(r, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot270_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot270_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
