#define SIMDE_TEST_ARM_NEON_INSN cmla_rot180

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot180.h"

static int
test_simde_vcmla_rot180_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
    simde_float16 r_[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(  11.396),  SIMDE_FLOAT16_C(   3.830), -SIMDE_FLOAT16_C(   2.864),  SIMDE_FLOAT16_C(   0.625) },
      { -SIMDE_FLOAT16_C(   7.675), -SIMDE_FLOAT16_C(   1.980), -SIMDE_FLOAT16_C(   2.440), -SIMDE_FLOAT16_C(   1.022) },
      {  SIMDE_FLOAT16_C(  13.529), -SIMDE_FLOAT16_C(   5.068),  SIMDE_FLOAT16_C(   2.220), -SIMDE_FLOAT16_C(   1.901) },
      { -SIMDE_FLOAT16_C(  73.935), -SIMDE_FLOAT16_C(  27.632), -SIMDE_FLOAT16_C(   4.768), -SIMDE_FLOAT16_C(   4.828) } },
    { {  SIMDE_FLOAT16_C(   7.489),  SIMDE_FLOAT16_C(   4.859),  SIMDE_FLOAT16_C(   0.539), -SIMDE_FLOAT16_C(   6.369) },
      {  SIMDE_FLOAT16_C(   6.281),  SIMDE_FLOAT16_C(  13.456), -SIMDE_FLOAT16_C(   6.765), -SIMDE_FLOAT16_C(  13.375) },
      {  SIMDE_FLOAT16_C(   7.797), -SIMDE_FLOAT16_C(  14.724),  SIMDE_FLOAT16_C(  12.825), -SIMDE_FLOAT16_C(   6.567) },
      { -SIMDE_FLOAT16_C(  39.241), -SIMDE_FLOAT16_C( 115.496),  SIMDE_FLOAT16_C(  16.471),  SIMDE_FLOAT16_C(   0.642) } },
    { { -SIMDE_FLOAT16_C(   6.528),  SIMDE_FLOAT16_C(   3.288),  SIMDE_FLOAT16_C(   0.693),  SIMDE_FLOAT16_C(   1.548) },
      {  SIMDE_FLOAT16_C(   2.786),  SIMDE_FLOAT16_C(   5.880),  SIMDE_FLOAT16_C(  11.154),  SIMDE_FLOAT16_C(   0.430) },
      { -SIMDE_FLOAT16_C(   5.686), -SIMDE_FLOAT16_C(   9.866),  SIMDE_FLOAT16_C(   3.599),  SIMDE_FLOAT16_C(   5.741) },
      {  SIMDE_FLOAT16_C(  12.501),  SIMDE_FLOAT16_C(  28.519), -SIMDE_FLOAT16_C(   4.131),  SIMDE_FLOAT16_C(   5.443) } },
    { { -SIMDE_FLOAT16_C(  12.984), -SIMDE_FLOAT16_C(   7.157), -SIMDE_FLOAT16_C(  12.338),  SIMDE_FLOAT16_C(   3.823) },
      { -SIMDE_FLOAT16_C(   6.892), -SIMDE_FLOAT16_C(   3.328), -SIMDE_FLOAT16_C(   2.653),  SIMDE_FLOAT16_C(   9.296) },
      { -SIMDE_FLOAT16_C(   8.700),  SIMDE_FLOAT16_C(   1.540),  SIMDE_FLOAT16_C(   1.554), -SIMDE_FLOAT16_C(   6.410) },
      { -SIMDE_FLOAT16_C(  98.186), -SIMDE_FLOAT16_C(  41.671), -SIMDE_FLOAT16_C(  31.179),  SIMDE_FLOAT16_C( 108.284) } },
    { {  SIMDE_FLOAT16_C(  10.855),  SIMDE_FLOAT16_C(   6.805),  SIMDE_FLOAT16_C(   4.572),  SIMDE_FLOAT16_C(   9.435) },
      {  SIMDE_FLOAT16_C(  11.959), -SIMDE_FLOAT16_C(   1.534), -SIMDE_FLOAT16_C(   4.085), -SIMDE_FLOAT16_C(  14.600) },
      { -SIMDE_FLOAT16_C(   1.878),  SIMDE_FLOAT16_C(   1.441), -SIMDE_FLOAT16_C(   5.145), -SIMDE_FLOAT16_C(  11.174) },
      { -SIMDE_FLOAT16_C( 131.625),  SIMDE_FLOAT16_C(  18.093),  SIMDE_FLOAT16_C(  13.532),  SIMDE_FLOAT16_C(  55.577) } },
    { {  SIMDE_FLOAT16_C(  11.102), -SIMDE_FLOAT16_C(  14.483), -SIMDE_FLOAT16_C(  13.296), -SIMDE_FLOAT16_C(  14.105) },
      {  SIMDE_FLOAT16_C(   0.561), -SIMDE_FLOAT16_C(   4.904), -SIMDE_FLOAT16_C(   7.471), -SIMDE_FLOAT16_C(   1.404) },
      { -SIMDE_FLOAT16_C(   9.479),  SIMDE_FLOAT16_C(  11.914),  SIMDE_FLOAT16_C(   5.957), -SIMDE_FLOAT16_C(   6.213) },
      { -SIMDE_FLOAT16_C(  15.707),  SIMDE_FLOAT16_C(  66.358), -SIMDE_FLOAT16_C(  93.377), -SIMDE_FLOAT16_C(  24.881) } },
    { {  SIMDE_FLOAT16_C(   9.512), -SIMDE_FLOAT16_C(   8.894),  SIMDE_FLOAT16_C(   8.363),  SIMDE_FLOAT16_C(   5.147) },
      {  SIMDE_FLOAT16_C(  13.997),  SIMDE_FLOAT16_C(  14.199),  SIMDE_FLOAT16_C(   3.699), -SIMDE_FLOAT16_C(   9.996) },
      { -SIMDE_FLOAT16_C(   3.432),  SIMDE_FLOAT16_C(  12.704), -SIMDE_FLOAT16_C(  11.378),  SIMDE_FLOAT16_C(  13.764) },
      { -SIMDE_FLOAT16_C( 136.571), -SIMDE_FLOAT16_C( 122.357), -SIMDE_FLOAT16_C(  42.313),  SIMDE_FLOAT16_C(  97.361) } },
    { {  SIMDE_FLOAT16_C(  10.602), -SIMDE_FLOAT16_C(   6.758),  SIMDE_FLOAT16_C(   0.868), -SIMDE_FLOAT16_C(  14.571) },
      { -SIMDE_FLOAT16_C(  14.312), -SIMDE_FLOAT16_C(   8.213),  SIMDE_FLOAT16_C(   0.377),  SIMDE_FLOAT16_C(   4.310) },
      { -SIMDE_FLOAT16_C(   5.056), -SIMDE_FLOAT16_C(   8.097), -SIMDE_FLOAT16_C(   2.158), -SIMDE_FLOAT16_C(   4.342) },
      {  SIMDE_FLOAT16_C( 146.680),  SIMDE_FLOAT16_C(  78.977), -SIMDE_FLOAT16_C(   2.485), -SIMDE_FLOAT16_C(   8.083) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r = simde_vld1_f16(test_vec[i].r);
    simde_float16x4_t r_ = simde_vcmla_rot180_f16(r, a, b);

    simde_test_arm_neon_assert_equal_f16x4(r_, simde_vld1_f16(test_vec[i].r_), 1);
  }

  return 0;
}

static int
test_simde_vcmlaq_rot180_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
    simde_float16 r_[8];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(   6.753),  SIMDE_FLOAT16_C(  11.219),  SIMDE_FLOAT16_C(  10.062), -SIMDE_FLOAT16_C(  10.133),
         SIMDE_FLOAT16_C(   7.611), -SIMDE_FLOAT16_C(   9.450),  SIMDE_FLOAT16_C(  12.915), -SIMDE_FLOAT16_C(   5.042) },
      {  SIMDE_FLOAT16_C(   8.865),  SIMDE_FLOAT16_C(  14.719), -SIMDE_FLOAT16_C(   4.059), -SIMDE_FLOAT16_C(   4.147),
        -SIMDE_FLOAT16_C(   6.459),  SIMDE_FLOAT16_C(  13.437),  SIMDE_FLOAT16_C(   0.170),  SIMDE_FLOAT16_C(   8.962) },
      {  SIMDE_FLOAT16_C(   3.841),  SIMDE_FLOAT16_C(  13.067),  SIMDE_FLOAT16_C(  12.146),  SIMDE_FLOAT16_C(   4.765),
        -SIMDE_FLOAT16_C(   7.184), -SIMDE_FLOAT16_C(  11.845),  SIMDE_FLOAT16_C(   8.443),  SIMDE_FLOAT16_C(   8.187) },
      {  SIMDE_FLOAT16_C(  63.706),  SIMDE_FLOAT16_C( 112.464),  SIMDE_FLOAT16_C(  52.988),  SIMDE_FLOAT16_C(  46.492),
         SIMDE_FLOAT16_C(  41.975), -SIMDE_FLOAT16_C( 114.114),  SIMDE_FLOAT16_C(   6.247), -SIMDE_FLOAT16_C( 107.557) } },
    { { -SIMDE_FLOAT16_C(  11.080), -SIMDE_FLOAT16_C(   7.319),  SIMDE_FLOAT16_C(   2.762), -SIMDE_FLOAT16_C(   6.714),
         SIMDE_FLOAT16_C(   3.980),  SIMDE_FLOAT16_C(   8.999), -SIMDE_FLOAT16_C(  12.284), -SIMDE_FLOAT16_C(   6.555) },
      {  SIMDE_FLOAT16_C(   3.119), -SIMDE_FLOAT16_C(   2.695),  SIMDE_FLOAT16_C(  13.294),  SIMDE_FLOAT16_C(   6.223),
         SIMDE_FLOAT16_C(   2.860), -SIMDE_FLOAT16_C(   9.602),  SIMDE_FLOAT16_C(  14.815), -SIMDE_FLOAT16_C(   8.597) },
      {  SIMDE_FLOAT16_C(   1.509),  SIMDE_FLOAT16_C(   6.124), -SIMDE_FLOAT16_C(   8.404),  SIMDE_FLOAT16_C(  14.277),
         SIMDE_FLOAT16_C(  13.340), -SIMDE_FLOAT16_C(  11.030),  SIMDE_FLOAT16_C(   6.713),  SIMDE_FLOAT16_C(   1.953) },
      {  SIMDE_FLOAT16_C(  36.068), -SIMDE_FLOAT16_C(  23.737), -SIMDE_FLOAT16_C(  45.122), -SIMDE_FLOAT16_C(   2.911),
         SIMDE_FLOAT16_C(   1.957),  SIMDE_FLOAT16_C(  27.186),  SIMDE_FLOAT16_C( 188.625), -SIMDE_FLOAT16_C( 103.653) } },
    { { -SIMDE_FLOAT16_C(   0.078), -SIMDE_FLOAT16_C(  12.408),  SIMDE_FLOAT16_C(   7.641), -SIMDE_FLOAT16_C(   7.814),
         SIMDE_FLOAT16_C(  13.607), -SIMDE_FLOAT16_C(   5.230), -SIMDE_FLOAT16_C(  13.056),  SIMDE_FLOAT16_C(   4.161) },
      {  SIMDE_FLOAT16_C(   7.172), -SIMDE_FLOAT16_C(   5.173), -SIMDE_FLOAT16_C(  11.814),  SIMDE_FLOAT16_C(  10.380),
         SIMDE_FLOAT16_C(   4.781),  SIMDE_FLOAT16_C(  13.258),  SIMDE_FLOAT16_C(  13.741), -SIMDE_FLOAT16_C(   4.665) },
      { -SIMDE_FLOAT16_C(  10.997), -SIMDE_FLOAT16_C(   5.960), -SIMDE_FLOAT16_C(   9.588), -SIMDE_FLOAT16_C(   1.759),
         SIMDE_FLOAT16_C(   8.294),  SIMDE_FLOAT16_C(  13.224), -SIMDE_FLOAT16_C(   9.482),  SIMDE_FLOAT16_C(   3.062) },
      { -SIMDE_FLOAT16_C(  10.438), -SIMDE_FLOAT16_C(   6.363),  SIMDE_FLOAT16_C(  80.683), -SIMDE_FLOAT16_C(  81.073),
        -SIMDE_FLOAT16_C(  56.761), -SIMDE_FLOAT16_C( 167.250),  SIMDE_FLOAT16_C( 169.920), -SIMDE_FLOAT16_C(  57.844) } },
    { { -SIMDE_FLOAT16_C(   1.969), -SIMDE_FLOAT16_C(   5.976),  SIMDE_FLOAT16_C(   4.592),  SIMDE_FLOAT16_C(   0.634),
        -SIMDE_FLOAT16_C(  11.236),  SIMDE_FLOAT16_C(  10.877), -SIMDE_FLOAT16_C(  12.075), -SIMDE_FLOAT16_C(  13.769) },
      { -SIMDE_FLOAT16_C(   1.006),  SIMDE_FLOAT16_C(   0.331),  SIMDE_FLOAT16_C(   2.265), -SIMDE_FLOAT16_C(   0.991),
        -SIMDE_FLOAT16_C(  10.447), -SIMDE_FLOAT16_C(  13.499), -SIMDE_FLOAT16_C(  12.402), -SIMDE_FLOAT16_C(   6.290) },
      { -SIMDE_FLOAT16_C(   0.691), -SIMDE_FLOAT16_C(   0.728), -SIMDE_FLOAT16_C(   1.302), -SIMDE_FLOAT16_C(   7.720),
         SIMDE_FLOAT16_C(  10.352), -SIMDE_FLOAT16_C(  12.754), -SIMDE_FLOAT16_C(  11.287),  SIMDE_FLOAT16_C(  14.010) },
      { -SIMDE_FLOAT16_C(   2.672), -SIMDE_FLOAT16_C(   0.076), -SIMDE_FLOAT16_C(  11.703), -SIMDE_FLOAT16_C(   3.169),
        -SIMDE_FLOAT16_C( 107.030), -SIMDE_FLOAT16_C( 164.429), -SIMDE_FLOAT16_C( 161.041), -SIMDE_FLOAT16_C(  61.942) } },
    { {  SIMDE_FLOAT16_C(   0.246),  SIMDE_FLOAT16_C(  10.443),  SIMDE_FLOAT16_C(  10.207),  SIMDE_FLOAT16_C(   8.720),
        -SIMDE_FLOAT16_C(   3.758), -SIMDE_FLOAT16_C(   7.488), -SIMDE_FLOAT16_C(   1.097), -SIMDE_FLOAT16_C(  14.239) },
      { -SIMDE_FLOAT16_C(  14.405), -SIMDE_FLOAT16_C(   1.256),  SIMDE_FLOAT16_C(   7.062),  SIMDE_FLOAT16_C(   2.007),
        -SIMDE_FLOAT16_C(  11.928),  SIMDE_FLOAT16_C(   1.105), -SIMDE_FLOAT16_C(   4.364),  SIMDE_FLOAT16_C(  13.366) },
      { -SIMDE_FLOAT16_C(   2.337),  SIMDE_FLOAT16_C(   3.351), -SIMDE_FLOAT16_C(   8.948),  SIMDE_FLOAT16_C(  12.943),
         SIMDE_FLOAT16_C(   2.576),  SIMDE_FLOAT16_C(   3.692),  SIMDE_FLOAT16_C(  14.970), -SIMDE_FLOAT16_C(   1.998) },
      {  SIMDE_FLOAT16_C(   1.207),  SIMDE_FLOAT16_C(   3.660), -SIMDE_FLOAT16_C(  81.030), -SIMDE_FLOAT16_C(   7.542),
        -SIMDE_FLOAT16_C(  42.249),  SIMDE_FLOAT16_C(   7.845),  SIMDE_FLOAT16_C(  10.183),  SIMDE_FLOAT16_C(  12.665) } },
    { {  SIMDE_FLOAT16_C(  14.167), -SIMDE_FLOAT16_C(   7.239), -SIMDE_FLOAT16_C(  12.150), -SIMDE_FLOAT16_C(   8.042),
         SIMDE_FLOAT16_C(   8.696),  SIMDE_FLOAT16_C(  13.285),  SIMDE_FLOAT16_C(  13.621), -SIMDE_FLOAT16_C(   2.146) },
      {  SIMDE_FLOAT16_C(   2.698),  SIMDE_FLOAT16_C(   5.461),  SIMDE_FLOAT16_C(   6.314),  SIMDE_FLOAT16_C(   0.454),
         SIMDE_FLOAT16_C(   4.428), -SIMDE_FLOAT16_C(   7.870), -SIMDE_FLOAT16_C(   7.286),  SIMDE_FLOAT16_C(   8.563) },
      { -SIMDE_FLOAT16_C(   1.626), -SIMDE_FLOAT16_C(   2.786), -SIMDE_FLOAT16_C(   6.103), -SIMDE_FLOAT16_C(  13.174),
        -SIMDE_FLOAT16_C(  11.809),  SIMDE_FLOAT16_C(   0.431),  SIMDE_FLOAT16_C(   8.495),  SIMDE_FLOAT16_C(  14.522) },
      { -SIMDE_FLOAT16_C(  39.849), -SIMDE_FLOAT16_C(  80.152),  SIMDE_FLOAT16_C(  70.612), -SIMDE_FLOAT16_C(   7.658),
        -SIMDE_FLOAT16_C(  50.315),  SIMDE_FLOAT16_C(  68.869),  SIMDE_FLOAT16_C( 107.738), -SIMDE_FLOAT16_C( 102.115) } },
    { { -SIMDE_FLOAT16_C(   9.051),  SIMDE_FLOAT16_C(   7.717),  SIMDE_FLOAT16_C(   9.362), -SIMDE_FLOAT16_C(  14.906),
         SIMDE_FLOAT16_C(   5.268), -SIMDE_FLOAT16_C(   5.634), -SIMDE_FLOAT16_C(   3.031), -SIMDE_FLOAT16_C(   4.130) },
      {  SIMDE_FLOAT16_C(  11.087),  SIMDE_FLOAT16_C(   0.504),  SIMDE_FLOAT16_C(   1.109),  SIMDE_FLOAT16_C(  13.220),
         SIMDE_FLOAT16_C(   3.465), -SIMDE_FLOAT16_C(  13.310), -SIMDE_FLOAT16_C(   8.852),  SIMDE_FLOAT16_C(  10.333) },
      { -SIMDE_FLOAT16_C(   7.241), -SIMDE_FLOAT16_C(   5.445),  SIMDE_FLOAT16_C(  14.185), -SIMDE_FLOAT16_C(  10.127),
        -SIMDE_FLOAT16_C(   2.264),  SIMDE_FLOAT16_C(   1.727),  SIMDE_FLOAT16_C(  12.597), -SIMDE_FLOAT16_C(  10.640) },
      {  SIMDE_FLOAT16_C(  93.107), -SIMDE_FLOAT16_C(   0.883),  SIMDE_FLOAT16_C(   3.803), -SIMDE_FLOAT16_C( 133.893),
        -SIMDE_FLOAT16_C(  20.518),  SIMDE_FLOAT16_C(  71.844), -SIMDE_FLOAT16_C(  14.233),  SIMDE_FLOAT16_C(  20.679) } },
    { {  SIMDE_FLOAT16_C(  14.462),  SIMDE_FLOAT16_C(   6.706), -SIMDE_FLOAT16_C(   7.724),  SIMDE_FLOAT16_C(   6.898),
        -SIMDE_FLOAT16_C(  11.155),  SIMDE_FLOAT16_C(  14.450), -SIMDE_FLOAT16_C(   5.627),  SIMDE_FLOAT16_C(   8.663) },
      { -SIMDE_FLOAT16_C(   7.586),  SIMDE_FLOAT16_C(   3.371), -SIMDE_FLOAT16_C(   8.783), -SIMDE_FLOAT16_C(  14.662),
         SIMDE_FLOAT16_C(   0.555), -SIMDE_FLOAT16_C(   6.251),  SIMDE_FLOAT16_C(   2.234),  SIMDE_FLOAT16_C(  12.595) },
      {  SIMDE_FLOAT16_C(  10.779),  SIMDE_FLOAT16_C(   2.969), -SIMDE_FLOAT16_C(  14.772), -SIMDE_FLOAT16_C(   3.106),
        -SIMDE_FLOAT16_C(   1.377), -SIMDE_FLOAT16_C(   0.521),  SIMDE_FLOAT16_C(   6.493), -SIMDE_FLOAT16_C(   8.415) },
      {  SIMDE_FLOAT16_C( 120.488), -SIMDE_FLOAT16_C(  45.782), -SIMDE_FLOAT16_C(  82.612), -SIMDE_FLOAT16_C( 116.355),
         SIMDE_FLOAT16_C(   4.814), -SIMDE_FLOAT16_C(  70.251),  SIMDE_FLOAT16_C(  19.064),  SIMDE_FLOAT16_C(  62.457) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vld1q_f16(test_vec[i].r);
    simde_float16x8_t r_ = simde_vcmlaq_rot180_f16(r, a, b);
    simde_test_arm_neon_assert_equal_f16x8(r_, simde_vld1q_f16(test_vec[i].r_), 1);
  }

  return 0;
}

static int
test_simde_vcmla_rot180_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   452.95), SIMDE_FLOAT32_C(   195.89) },
      { SIMDE_FLOAT32_C(   444.91), SIMDE_FLOAT32_C(    53.65) },
      { SIMDE_FLOAT32_C(  -340.35), SIMDE_FLOAT32_C(  -889.91) },
      { SIMDE_FLOAT32_C(-201862.34), SIMDE_FLOAT32_C(-25190.68) } },
    { { SIMDE_FLOAT32_C(   306.65), SIMDE_FLOAT32_C(  -419.57) },
      { SIMDE_FLOAT32_C(  -861.69), SIMDE_FLOAT32_C(   727.62) },
      { SIMDE_FLOAT32_C(  -997.28), SIMDE_FLOAT32_C(   144.31) },
      { SIMDE_FLOAT32_C(263239.97), SIMDE_FLOAT32_C(-222980.36) } },
    { { SIMDE_FLOAT32_C(   196.29), SIMDE_FLOAT32_C(   798.44) },
      { SIMDE_FLOAT32_C(  -778.96), SIMDE_FLOAT32_C(   915.31) },
      { SIMDE_FLOAT32_C(   222.88), SIMDE_FLOAT32_C(   691.69) },
      { SIMDE_FLOAT32_C(153124.94), SIMDE_FLOAT32_C(-178974.50) } },
    { { SIMDE_FLOAT32_C(   -68.29), SIMDE_FLOAT32_C(   627.45) },
      { SIMDE_FLOAT32_C(  -373.33), SIMDE_FLOAT32_C(   724.33) },
      { SIMDE_FLOAT32_C(   133.16), SIMDE_FLOAT32_C(   234.76) },
      { SIMDE_FLOAT32_C(-25361.54), SIMDE_FLOAT32_C( 49699.26) } },
    { { SIMDE_FLOAT32_C(   964.74), SIMDE_FLOAT32_C(   624.02) },
      { SIMDE_FLOAT32_C(  -835.66), SIMDE_FLOAT32_C(   908.14) },
      { SIMDE_FLOAT32_C(   913.15), SIMDE_FLOAT32_C(   697.78) },
      { SIMDE_FLOAT32_C(807107.75), SIMDE_FLOAT32_C(-875421.19) } },
    { { SIMDE_FLOAT32_C(   162.44), SIMDE_FLOAT32_C(   366.10) },
      { SIMDE_FLOAT32_C(  -106.33), SIMDE_FLOAT32_C(  -392.64) },
      { SIMDE_FLOAT32_C(  -580.25), SIMDE_FLOAT32_C(   553.32) },
      { SIMDE_FLOAT32_C( 16692.00), SIMDE_FLOAT32_C( 64333.77) } },
    { { SIMDE_FLOAT32_C(  -282.55), SIMDE_FLOAT32_C(   726.40) },
      { SIMDE_FLOAT32_C(  -866.24), SIMDE_FLOAT32_C(  -144.24) },
      { SIMDE_FLOAT32_C(   454.02), SIMDE_FLOAT32_C(  -863.52) },
      { SIMDE_FLOAT32_C(-244302.08), SIMDE_FLOAT32_C(-41618.53) } },
    { { SIMDE_FLOAT32_C(  -999.93), SIMDE_FLOAT32_C(  -349.69) },
      { SIMDE_FLOAT32_C(   934.92), SIMDE_FLOAT32_C(  -778.90) },
      { SIMDE_FLOAT32_C(  -434.38), SIMDE_FLOAT32_C(   157.80) },
      { SIMDE_FLOAT32_C(934420.12), SIMDE_FLOAT32_C(-778687.69) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vld1_f32(test_vec[i].r);
    simde_float32x2_t r_ = simde_vcmla_rot180_f32(r, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r_, simde_vld1_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r_ = simde_vcmla_rot180_f32(r, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot180_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   581.15), SIMDE_FLOAT32_C(  -956.71), SIMDE_FLOAT32_C(   565.79), SIMDE_FLOAT32_C(  -665.78) },
      { SIMDE_FLOAT32_C(   634.03), SIMDE_FLOAT32_C(  -372.68), SIMDE_FLOAT32_C(  -843.04), SIMDE_FLOAT32_C(  -573.31) },
      { SIMDE_FLOAT32_C(   743.16), SIMDE_FLOAT32_C(   262.51), SIMDE_FLOAT32_C(   315.71), SIMDE_FLOAT32_C(   643.97) },
      { SIMDE_FLOAT32_C(-367723.41), SIMDE_FLOAT32_C(216845.50), SIMDE_FLOAT32_C(477299.28), SIMDE_FLOAT32_C(325017.03) } },
    { { SIMDE_FLOAT32_C(   -14.23), SIMDE_FLOAT32_C(   146.05), SIMDE_FLOAT32_C(  -713.83), SIMDE_FLOAT32_C(   -20.06) },
      { SIMDE_FLOAT32_C(   104.47), SIMDE_FLOAT32_C(   216.28), SIMDE_FLOAT32_C(  -177.08), SIMDE_FLOAT32_C(    12.18) },
      { SIMDE_FLOAT32_C(  -643.47), SIMDE_FLOAT32_C(   708.88), SIMDE_FLOAT32_C(   686.41), SIMDE_FLOAT32_C(   709.88) },
      { SIMDE_FLOAT32_C(   843.14), SIMDE_FLOAT32_C(  3786.54), SIMDE_FLOAT32_C(-125718.61), SIMDE_FLOAT32_C(  9404.33) } },
    { { SIMDE_FLOAT32_C(  -814.88), SIMDE_FLOAT32_C(  -711.88), SIMDE_FLOAT32_C(  -748.81), SIMDE_FLOAT32_C(   858.53) },
      { SIMDE_FLOAT32_C(   737.87), SIMDE_FLOAT32_C(  -589.28), SIMDE_FLOAT32_C(  -895.36), SIMDE_FLOAT32_C(   319.02) },
      { SIMDE_FLOAT32_C(  -546.00), SIMDE_FLOAT32_C(   670.42), SIMDE_FLOAT32_C(   653.24), SIMDE_FLOAT32_C(  -911.97) },
      { SIMDE_FLOAT32_C(600729.50), SIMDE_FLOAT32_C(-479522.09), SIMDE_FLOAT32_C(-669801.25), SIMDE_FLOAT32_C(237973.39) } },
    { { SIMDE_FLOAT32_C(  -702.25), SIMDE_FLOAT32_C(   810.19), SIMDE_FLOAT32_C(  -485.28), SIMDE_FLOAT32_C(  -959.09) },
      { SIMDE_FLOAT32_C(    72.70), SIMDE_FLOAT32_C(   830.43), SIMDE_FLOAT32_C(   684.88), SIMDE_FLOAT32_C(  -941.53) },
      { SIMDE_FLOAT32_C(   -23.52), SIMDE_FLOAT32_C(   971.04), SIMDE_FLOAT32_C(    38.42), SIMDE_FLOAT32_C(  -919.05) },
      { SIMDE_FLOAT32_C( 51030.05), SIMDE_FLOAT32_C(584140.50), SIMDE_FLOAT32_C(332397.00), SIMDE_FLOAT32_C(-457824.75) } },
    { { SIMDE_FLOAT32_C(   187.33), SIMDE_FLOAT32_C(   861.34), SIMDE_FLOAT32_C(    93.13), SIMDE_FLOAT32_C(   543.85) },
      { SIMDE_FLOAT32_C(   570.21), SIMDE_FLOAT32_C(  -220.46), SIMDE_FLOAT32_C(   253.73), SIMDE_FLOAT32_C(   755.33) },
      { SIMDE_FLOAT32_C(    67.66), SIMDE_FLOAT32_C(   504.92), SIMDE_FLOAT32_C(   613.86), SIMDE_FLOAT32_C(  -194.47) },
      { SIMDE_FLOAT32_C(-106749.78), SIMDE_FLOAT32_C( 41803.70), SIMDE_FLOAT32_C(-23016.01), SIMDE_FLOAT32_C(-70538.35) } },
    { { SIMDE_FLOAT32_C(   915.64), SIMDE_FLOAT32_C(   718.50), SIMDE_FLOAT32_C(  -875.45), SIMDE_FLOAT32_C(  -630.36) },
      { SIMDE_FLOAT32_C(   388.92), SIMDE_FLOAT32_C(   777.79), SIMDE_FLOAT32_C(  -542.33), SIMDE_FLOAT32_C(   686.66) },
      { SIMDE_FLOAT32_C(   587.98), SIMDE_FLOAT32_C(   -27.61), SIMDE_FLOAT32_C(   727.57), SIMDE_FLOAT32_C(  -339.32) },
      { SIMDE_FLOAT32_C(-355522.75), SIMDE_FLOAT32_C(-712203.25), SIMDE_FLOAT32_C(-474055.25), SIMDE_FLOAT32_C(600797.19) } },
    { { SIMDE_FLOAT32_C(  -197.18), SIMDE_FLOAT32_C(   412.45), SIMDE_FLOAT32_C(  -280.84), SIMDE_FLOAT32_C(   779.30) },
      { SIMDE_FLOAT32_C(   383.50), SIMDE_FLOAT32_C(   757.57), SIMDE_FLOAT32_C(   860.25), SIMDE_FLOAT32_C(  -429.18) },
      { SIMDE_FLOAT32_C(   618.91), SIMDE_FLOAT32_C(   -46.62), SIMDE_FLOAT32_C(  -885.33), SIMDE_FLOAT32_C(   189.12) },
      { SIMDE_FLOAT32_C( 76237.44), SIMDE_FLOAT32_C(149331.03), SIMDE_FLOAT32_C(240707.28), SIMDE_FLOAT32_C(-120341.79) } },
    { { SIMDE_FLOAT32_C(   732.92), SIMDE_FLOAT32_C(   368.40), SIMDE_FLOAT32_C(   -55.55), SIMDE_FLOAT32_C(  -199.42) },
      { SIMDE_FLOAT32_C(  -126.68), SIMDE_FLOAT32_C(  -441.69), SIMDE_FLOAT32_C(   606.11), SIMDE_FLOAT32_C(  -211.04) },
      { SIMDE_FLOAT32_C(  -723.20), SIMDE_FLOAT32_C(   730.66), SIMDE_FLOAT32_C(   158.60), SIMDE_FLOAT32_C(   665.72) },
      { SIMDE_FLOAT32_C( 92123.10), SIMDE_FLOAT32_C(324454.09), SIMDE_FLOAT32_C( 33828.01), SIMDE_FLOAT32_C(-11057.55) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vld1q_f32(test_vec[i].r);
    simde_float32x4_t r_ = simde_vcmlaq_rot180_f32(r, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r_, simde_vld1q_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r_ = simde_vcmlaq_rot180_f32(r, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot180_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
    simde_float64 r_[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   262.77), SIMDE_FLOAT64_C(  -594.87) },
      { SIMDE_FLOAT64_C(  -382.77), SIMDE_FLOAT64_C(   813.86) },
      { SIMDE_FLOAT64_C(   154.31), SIMDE_FLOAT64_C(   621.90) },
      { SIMDE_FLOAT64_C(100734.78), SIMDE_FLOAT64_C(-213236.09) } },
    { { SIMDE_FLOAT64_C(   972.42), SIMDE_FLOAT64_C(  -414.89) },
      { SIMDE_FLOAT64_C(   356.78), SIMDE_FLOAT64_C(   498.91) },
      { SIMDE_FLOAT64_C(   960.93), SIMDE_FLOAT64_C(  -942.16) },
      { SIMDE_FLOAT64_C(-345979.08), SIMDE_FLOAT64_C(-486092.22) } },
    { { SIMDE_FLOAT64_C(   920.42), SIMDE_FLOAT64_C(  -123.39) },
      { SIMDE_FLOAT64_C(  -106.64), SIMDE_FLOAT64_C(   660.02) },
      { SIMDE_FLOAT64_C(   429.81), SIMDE_FLOAT64_C(   808.37) },
      { SIMDE_FLOAT64_C( 98583.40), SIMDE_FLOAT64_C(-606687.24) } },
    { { SIMDE_FLOAT64_C(   -29.61), SIMDE_FLOAT64_C(    98.57) },
      { SIMDE_FLOAT64_C(   828.43), SIMDE_FLOAT64_C(  -489.72) },
      { SIMDE_FLOAT64_C(   575.48), SIMDE_FLOAT64_C(   187.12) },
      { SIMDE_FLOAT64_C( 25105.29), SIMDE_FLOAT64_C(-14313.49) } },
    { { SIMDE_FLOAT64_C(  -389.68), SIMDE_FLOAT64_C(  -827.75) },
      { SIMDE_FLOAT64_C(    15.22), SIMDE_FLOAT64_C(   408.31) },
      { SIMDE_FLOAT64_C(   -24.59), SIMDE_FLOAT64_C(   768.89) },
      { SIMDE_FLOAT64_C(  5906.34), SIMDE_FLOAT64_C(159879.13) } },
    { { SIMDE_FLOAT64_C(  -685.93), SIMDE_FLOAT64_C(  -761.82) },
      { SIMDE_FLOAT64_C(  -825.99), SIMDE_FLOAT64_C(   -68.70) },
      { SIMDE_FLOAT64_C(  -947.96), SIMDE_FLOAT64_C(   328.32) },
      { SIMDE_FLOAT64_C(-567519.28), SIMDE_FLOAT64_C(-46795.07) } },
    { { SIMDE_FLOAT64_C(  -446.80), SIMDE_FLOAT64_C(  -975.54) },
      { SIMDE_FLOAT64_C(   913.43), SIMDE_FLOAT64_C(   909.98) },
      { SIMDE_FLOAT64_C(   523.37), SIMDE_FLOAT64_C(   874.37) },
      { SIMDE_FLOAT64_C(408643.89), SIMDE_FLOAT64_C(407453.43) } },
    { { SIMDE_FLOAT64_C(   967.82), SIMDE_FLOAT64_C(   443.78) },
      { SIMDE_FLOAT64_C(  -249.02), SIMDE_FLOAT64_C(  -138.82) },
      { SIMDE_FLOAT64_C(   103.81), SIMDE_FLOAT64_C(  -819.21) },
      { SIMDE_FLOAT64_C(241110.35), SIMDE_FLOAT64_C(133533.56) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vld1q_f64(test_vec[i].r);
    simde_float64x2_t r_ = simde_vcmlaq_rot180_f64(r, a, b);
    simde_test_arm_neon_assert_equal_f64x2(r_, simde_vld1q_f64(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r_ = simde_vcmlaq_rot180_f64(r, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
