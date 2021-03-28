#define SIMDE_TEST_X86_AVX512_INSN compress

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/compress.h>
#include <simde/x86/avx512/setzero.h>

static int
test_simde_mm256_mask_compress_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -916.88), SIMDE_FLOAT64_C(   158.93), SIMDE_FLOAT64_C(   599.76), SIMDE_FLOAT64_C(  -225.52) },
      UINT8_C(135),
      { SIMDE_FLOAT64_C(    24.01), SIMDE_FLOAT64_C(  -663.66), SIMDE_FLOAT64_C(    69.28), SIMDE_FLOAT64_C(    30.05) },
      { SIMDE_FLOAT64_C(    24.01), SIMDE_FLOAT64_C(  -663.66), SIMDE_FLOAT64_C(    69.28), SIMDE_FLOAT64_C(  -225.52) } },
    { { SIMDE_FLOAT64_C(     9.75), SIMDE_FLOAT64_C(   882.66), SIMDE_FLOAT64_C(  -167.25), SIMDE_FLOAT64_C(   860.77) },
      UINT8_C( 45),
      { SIMDE_FLOAT64_C(    48.55), SIMDE_FLOAT64_C(  -497.33), SIMDE_FLOAT64_C(  -222.19), SIMDE_FLOAT64_C(  -116.25) },
      { SIMDE_FLOAT64_C(    48.55), SIMDE_FLOAT64_C(  -222.19), SIMDE_FLOAT64_C(  -116.25), SIMDE_FLOAT64_C(   860.77) } },
    { { SIMDE_FLOAT64_C(   -34.97), SIMDE_FLOAT64_C(     7.96), SIMDE_FLOAT64_C(    25.58), SIMDE_FLOAT64_C(   154.70) },
      UINT8_C(133),
      { SIMDE_FLOAT64_C(  -239.22), SIMDE_FLOAT64_C(  -582.95), SIMDE_FLOAT64_C(  -691.11), SIMDE_FLOAT64_C(  -357.68) },
      { SIMDE_FLOAT64_C(  -239.22), SIMDE_FLOAT64_C(  -691.11), SIMDE_FLOAT64_C(    25.58), SIMDE_FLOAT64_C(   154.70) } },
    { { SIMDE_FLOAT64_C(    78.69), SIMDE_FLOAT64_C(    76.28), SIMDE_FLOAT64_C(   427.40), SIMDE_FLOAT64_C(   915.51) },
      UINT8_C(168),
      { SIMDE_FLOAT64_C(  -413.68), SIMDE_FLOAT64_C(   515.28), SIMDE_FLOAT64_C(   933.88), SIMDE_FLOAT64_C(   249.02) },
      { SIMDE_FLOAT64_C(   249.02), SIMDE_FLOAT64_C(    76.28), SIMDE_FLOAT64_C(   427.40), SIMDE_FLOAT64_C(   915.51) } },
    { { SIMDE_FLOAT64_C(  -460.72), SIMDE_FLOAT64_C(  -729.78), SIMDE_FLOAT64_C(  -681.70), SIMDE_FLOAT64_C(   569.34) },
      UINT8_C( 77),
      { SIMDE_FLOAT64_C(  -799.04), SIMDE_FLOAT64_C(  -597.91), SIMDE_FLOAT64_C(   140.73), SIMDE_FLOAT64_C(  -863.38) },
      { SIMDE_FLOAT64_C(  -799.04), SIMDE_FLOAT64_C(   140.73), SIMDE_FLOAT64_C(  -863.38), SIMDE_FLOAT64_C(   569.34) } },
    { { SIMDE_FLOAT64_C(   450.64), SIMDE_FLOAT64_C(   643.40), SIMDE_FLOAT64_C(   -85.57), SIMDE_FLOAT64_C(  -665.61) },
      UINT8_C( 40),
      { SIMDE_FLOAT64_C(   922.40), SIMDE_FLOAT64_C(   359.97), SIMDE_FLOAT64_C(   763.14), SIMDE_FLOAT64_C(  -890.42) },
      { SIMDE_FLOAT64_C(  -890.42), SIMDE_FLOAT64_C(   643.40), SIMDE_FLOAT64_C(   -85.57), SIMDE_FLOAT64_C(  -665.61) } },
    { { SIMDE_FLOAT64_C(  -879.25), SIMDE_FLOAT64_C(  -819.81), SIMDE_FLOAT64_C(  -581.53), SIMDE_FLOAT64_C(  -236.94) },
      UINT8_C( 98),
      { SIMDE_FLOAT64_C(   494.75), SIMDE_FLOAT64_C(  -809.54), SIMDE_FLOAT64_C(   174.40), SIMDE_FLOAT64_C(  -345.85) },
      { SIMDE_FLOAT64_C(  -809.54), SIMDE_FLOAT64_C(  -819.81), SIMDE_FLOAT64_C(  -581.53), SIMDE_FLOAT64_C(  -236.94) } },
    { { SIMDE_FLOAT64_C(  -223.22), SIMDE_FLOAT64_C(  -310.32), SIMDE_FLOAT64_C(  -411.98), SIMDE_FLOAT64_C(  -974.20) },
      UINT8_C(248),
      { SIMDE_FLOAT64_C(  -141.76), SIMDE_FLOAT64_C(  -655.90), SIMDE_FLOAT64_C(  -201.70), SIMDE_FLOAT64_C(  -861.80) },
      { SIMDE_FLOAT64_C(  -861.80), SIMDE_FLOAT64_C(  -310.32), SIMDE_FLOAT64_C(  -411.98), SIMDE_FLOAT64_C(  -974.20) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d src = simde_mm256_loadu_pd(test_vec[i].src);
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d r = simde_mm256_mask_compress_pd(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d src = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_mask_compress_pd(src, k, a);

    simde_test_x86_write_f64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_compressstoreu_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(143),
      { SIMDE_FLOAT64_C(   833.37), SIMDE_FLOAT64_C(  -888.29), SIMDE_FLOAT64_C(   806.37), SIMDE_FLOAT64_C(  -275.77) },
      { SIMDE_FLOAT64_C(   833.37), SIMDE_FLOAT64_C(  -888.29), SIMDE_FLOAT64_C(   806.37), SIMDE_FLOAT64_C(  -275.77) } },
    { UINT8_C(144),
      { SIMDE_FLOAT64_C(   703.03), SIMDE_FLOAT64_C(   -55.57), SIMDE_FLOAT64_C(   461.75), SIMDE_FLOAT64_C(  -153.04) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(210),
      { SIMDE_FLOAT64_C(   626.02), SIMDE_FLOAT64_C(  -231.03), SIMDE_FLOAT64_C(   500.12), SIMDE_FLOAT64_C(  -542.32) },
      { SIMDE_FLOAT64_C(  -231.03), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 68),
      { SIMDE_FLOAT64_C(  -855.25), SIMDE_FLOAT64_C(   133.56), SIMDE_FLOAT64_C(   213.48), SIMDE_FLOAT64_C(   374.80) },
      { SIMDE_FLOAT64_C(   213.48), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(184),
      { SIMDE_FLOAT64_C(   870.56), SIMDE_FLOAT64_C(   345.82), SIMDE_FLOAT64_C(   211.23), SIMDE_FLOAT64_C(   -25.92) },
      { SIMDE_FLOAT64_C(   -25.92), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 73),
      { SIMDE_FLOAT64_C(   783.89), SIMDE_FLOAT64_C(   128.90), SIMDE_FLOAT64_C(  -989.70), SIMDE_FLOAT64_C(   604.83) },
      { SIMDE_FLOAT64_C(   783.89), SIMDE_FLOAT64_C(   604.83), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 48),
      { SIMDE_FLOAT64_C(   933.37), SIMDE_FLOAT64_C(   438.20), SIMDE_FLOAT64_C(   256.41), SIMDE_FLOAT64_C(   739.75) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(161),
      { SIMDE_FLOAT64_C(  -908.70), SIMDE_FLOAT64_C(   442.77), SIMDE_FLOAT64_C(   106.87), SIMDE_FLOAT64_C(   553.06) },
      { SIMDE_FLOAT64_C(  -908.70), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d r = simde_mm256_setzero_pd();
    simde_mm256_mask_compressstoreu_pd(&r, test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_setzero_pd();
    simde_mm256_mask_compressstoreu_pd(&r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_compress_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(222),
      { SIMDE_FLOAT64_C(   454.86), SIMDE_FLOAT64_C(  -204.25), SIMDE_FLOAT64_C(  -306.36), SIMDE_FLOAT64_C(   668.22) },
      { SIMDE_FLOAT64_C(  -204.25), SIMDE_FLOAT64_C(  -306.36), SIMDE_FLOAT64_C(   668.22), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 29),
      { SIMDE_FLOAT64_C(    89.35), SIMDE_FLOAT64_C(  -374.29), SIMDE_FLOAT64_C(  -314.80), SIMDE_FLOAT64_C(   634.87) },
      { SIMDE_FLOAT64_C(    89.35), SIMDE_FLOAT64_C(  -314.80), SIMDE_FLOAT64_C(   634.87), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(197),
      { SIMDE_FLOAT64_C(   148.20), SIMDE_FLOAT64_C(   361.22), SIMDE_FLOAT64_C(  -402.19), SIMDE_FLOAT64_C(  -243.24) },
      { SIMDE_FLOAT64_C(   148.20), SIMDE_FLOAT64_C(  -402.19), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(202),
      { SIMDE_FLOAT64_C(    41.34), SIMDE_FLOAT64_C(    81.39), SIMDE_FLOAT64_C(    98.60), SIMDE_FLOAT64_C(   848.27) },
      { SIMDE_FLOAT64_C(    81.39), SIMDE_FLOAT64_C(   848.27), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 91),
      { SIMDE_FLOAT64_C(  -865.17), SIMDE_FLOAT64_C(  -457.62), SIMDE_FLOAT64_C(   502.15), SIMDE_FLOAT64_C(  -670.39) },
      { SIMDE_FLOAT64_C(  -865.17), SIMDE_FLOAT64_C(  -457.62), SIMDE_FLOAT64_C(  -670.39), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(149),
      { SIMDE_FLOAT64_C(   595.46), SIMDE_FLOAT64_C(   824.97), SIMDE_FLOAT64_C(  -124.29), SIMDE_FLOAT64_C(  -820.11) },
      { SIMDE_FLOAT64_C(   595.46), SIMDE_FLOAT64_C(  -124.29), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(158),
      { SIMDE_FLOAT64_C(  -680.42), SIMDE_FLOAT64_C(   634.76), SIMDE_FLOAT64_C(  -768.22), SIMDE_FLOAT64_C(    13.22) },
      { SIMDE_FLOAT64_C(   634.76), SIMDE_FLOAT64_C(  -768.22), SIMDE_FLOAT64_C(    13.22), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(239),
      { SIMDE_FLOAT64_C(   939.17), SIMDE_FLOAT64_C(  -897.42), SIMDE_FLOAT64_C(   928.68), SIMDE_FLOAT64_C(  -375.63) },
      { SIMDE_FLOAT64_C(   939.17), SIMDE_FLOAT64_C(  -897.42), SIMDE_FLOAT64_C(   928.68), SIMDE_FLOAT64_C(  -375.63) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d r = simde_mm256_maskz_compress_pd(test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_maskz_compress_pd(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_compress_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   536.52), SIMDE_FLOAT32_C(   844.87), SIMDE_FLOAT32_C(   935.60), SIMDE_FLOAT32_C(  -131.73),
        SIMDE_FLOAT32_C(   128.41), SIMDE_FLOAT32_C(   759.61), SIMDE_FLOAT32_C(  -808.07), SIMDE_FLOAT32_C(   529.60) },
      UINT8_C(166),
      { SIMDE_FLOAT32_C(  -953.49), SIMDE_FLOAT32_C(   656.19), SIMDE_FLOAT32_C(   585.52), SIMDE_FLOAT32_C(  -924.28),
        SIMDE_FLOAT32_C(   634.20), SIMDE_FLOAT32_C(  -481.63), SIMDE_FLOAT32_C(   558.16), SIMDE_FLOAT32_C(   850.77) },
      { SIMDE_FLOAT32_C(   656.19), SIMDE_FLOAT32_C(   585.52), SIMDE_FLOAT32_C(  -481.63), SIMDE_FLOAT32_C(   850.77),
        SIMDE_FLOAT32_C(   128.41), SIMDE_FLOAT32_C(   759.61), SIMDE_FLOAT32_C(  -808.07), SIMDE_FLOAT32_C(   529.60) } },
    { { SIMDE_FLOAT32_C(   812.17), SIMDE_FLOAT32_C(  -152.72), SIMDE_FLOAT32_C(   -51.75), SIMDE_FLOAT32_C(   514.62),
        SIMDE_FLOAT32_C(  -735.53), SIMDE_FLOAT32_C(  -717.80), SIMDE_FLOAT32_C(   246.36), SIMDE_FLOAT32_C(   898.70) },
      UINT8_C( 45),
      { SIMDE_FLOAT32_C(   329.63), SIMDE_FLOAT32_C(   950.05), SIMDE_FLOAT32_C(   342.90), SIMDE_FLOAT32_C(   494.75),
        SIMDE_FLOAT32_C(   726.00), SIMDE_FLOAT32_C(  -120.58), SIMDE_FLOAT32_C(   339.63), SIMDE_FLOAT32_C(   661.60) },
      { SIMDE_FLOAT32_C(   329.63), SIMDE_FLOAT32_C(   342.90), SIMDE_FLOAT32_C(   494.75), SIMDE_FLOAT32_C(  -120.58),
        SIMDE_FLOAT32_C(  -735.53), SIMDE_FLOAT32_C(  -717.80), SIMDE_FLOAT32_C(   246.36), SIMDE_FLOAT32_C(   898.70) } },
    { { SIMDE_FLOAT32_C(   747.69), SIMDE_FLOAT32_C(  -531.96), SIMDE_FLOAT32_C(   421.21), SIMDE_FLOAT32_C(   939.62),
        SIMDE_FLOAT32_C(   997.64), SIMDE_FLOAT32_C(  -300.74), SIMDE_FLOAT32_C(   986.13), SIMDE_FLOAT32_C(   653.83) },
      UINT8_C( 65),
      { SIMDE_FLOAT32_C(  -938.15), SIMDE_FLOAT32_C(   288.03), SIMDE_FLOAT32_C(  -196.85), SIMDE_FLOAT32_C(   620.00),
        SIMDE_FLOAT32_C(   138.80), SIMDE_FLOAT32_C(  -384.68), SIMDE_FLOAT32_C(  -532.72), SIMDE_FLOAT32_C(  -912.95) },
      { SIMDE_FLOAT32_C(  -938.15), SIMDE_FLOAT32_C(  -532.72), SIMDE_FLOAT32_C(   421.21), SIMDE_FLOAT32_C(   939.62),
        SIMDE_FLOAT32_C(   997.64), SIMDE_FLOAT32_C(  -300.74), SIMDE_FLOAT32_C(   986.13), SIMDE_FLOAT32_C(   653.83) } },
    { { SIMDE_FLOAT32_C(  -870.06), SIMDE_FLOAT32_C(  -268.25), SIMDE_FLOAT32_C(  -630.74), SIMDE_FLOAT32_C(   376.30),
        SIMDE_FLOAT32_C(  -369.54), SIMDE_FLOAT32_C(  -396.64), SIMDE_FLOAT32_C(  -294.07), SIMDE_FLOAT32_C(  -419.50) },
      UINT8_C( 40),
      { SIMDE_FLOAT32_C(  -799.31), SIMDE_FLOAT32_C(  -693.50), SIMDE_FLOAT32_C(  -174.33), SIMDE_FLOAT32_C(   540.31),
        SIMDE_FLOAT32_C(   968.10), SIMDE_FLOAT32_C(  -426.64), SIMDE_FLOAT32_C(  -991.65), SIMDE_FLOAT32_C(   389.32) },
      { SIMDE_FLOAT32_C(   540.31), SIMDE_FLOAT32_C(  -426.64), SIMDE_FLOAT32_C(  -630.74), SIMDE_FLOAT32_C(   376.30),
        SIMDE_FLOAT32_C(  -369.54), SIMDE_FLOAT32_C(  -396.64), SIMDE_FLOAT32_C(  -294.07), SIMDE_FLOAT32_C(  -419.50) } },
    { { SIMDE_FLOAT32_C(  -487.02), SIMDE_FLOAT32_C(  -994.01), SIMDE_FLOAT32_C(  -911.42), SIMDE_FLOAT32_C(  -500.88),
        SIMDE_FLOAT32_C(   659.82), SIMDE_FLOAT32_C(  -626.64), SIMDE_FLOAT32_C(  -439.04), SIMDE_FLOAT32_C(   -52.16) },
      UINT8_C( 57),
      { SIMDE_FLOAT32_C(  -819.03), SIMDE_FLOAT32_C(  -913.35), SIMDE_FLOAT32_C(   791.83), SIMDE_FLOAT32_C(  -351.75),
        SIMDE_FLOAT32_C(  -826.30), SIMDE_FLOAT32_C(   921.77), SIMDE_FLOAT32_C(   380.00), SIMDE_FLOAT32_C(  -457.04) },
      { SIMDE_FLOAT32_C(  -819.03), SIMDE_FLOAT32_C(  -351.75), SIMDE_FLOAT32_C(  -826.30), SIMDE_FLOAT32_C(   921.77),
        SIMDE_FLOAT32_C(   659.82), SIMDE_FLOAT32_C(  -626.64), SIMDE_FLOAT32_C(  -439.04), SIMDE_FLOAT32_C(   -52.16) } },
    { { SIMDE_FLOAT32_C(   298.07), SIMDE_FLOAT32_C(  -989.54), SIMDE_FLOAT32_C(   146.31), SIMDE_FLOAT32_C(  -996.00),
        SIMDE_FLOAT32_C(  -409.04), SIMDE_FLOAT32_C(    92.57), SIMDE_FLOAT32_C(  -795.31), SIMDE_FLOAT32_C(  -102.54) },
      UINT8_C(107),
      { SIMDE_FLOAT32_C(   745.00), SIMDE_FLOAT32_C(  -134.43), SIMDE_FLOAT32_C(  -508.40), SIMDE_FLOAT32_C(   753.35),
        SIMDE_FLOAT32_C(  -745.12), SIMDE_FLOAT32_C(     4.59), SIMDE_FLOAT32_C(   759.34), SIMDE_FLOAT32_C(  -656.54) },
      { SIMDE_FLOAT32_C(   745.00), SIMDE_FLOAT32_C(  -134.43), SIMDE_FLOAT32_C(   753.35), SIMDE_FLOAT32_C(     4.59),
        SIMDE_FLOAT32_C(   759.34), SIMDE_FLOAT32_C(    92.57), SIMDE_FLOAT32_C(  -795.31), SIMDE_FLOAT32_C(  -102.54) } },
    { { SIMDE_FLOAT32_C(   503.70), SIMDE_FLOAT32_C(   419.16), SIMDE_FLOAT32_C(  -283.18), SIMDE_FLOAT32_C(  -935.33),
        SIMDE_FLOAT32_C(  -632.99), SIMDE_FLOAT32_C(   893.33), SIMDE_FLOAT32_C(  -754.36), SIMDE_FLOAT32_C(  -546.35) },
      UINT8_C( 36),
      { SIMDE_FLOAT32_C(  -106.11), SIMDE_FLOAT32_C(  -372.65), SIMDE_FLOAT32_C(   606.93), SIMDE_FLOAT32_C(  -726.11),
        SIMDE_FLOAT32_C(   170.31), SIMDE_FLOAT32_C(   -95.00), SIMDE_FLOAT32_C(  -715.65), SIMDE_FLOAT32_C(  -683.38) },
      { SIMDE_FLOAT32_C(   606.93), SIMDE_FLOAT32_C(   -95.00), SIMDE_FLOAT32_C(  -283.18), SIMDE_FLOAT32_C(  -935.33),
        SIMDE_FLOAT32_C(  -632.99), SIMDE_FLOAT32_C(   893.33), SIMDE_FLOAT32_C(  -754.36), SIMDE_FLOAT32_C(  -546.35) } },
    { { SIMDE_FLOAT32_C(   -91.00), SIMDE_FLOAT32_C(  -124.69), SIMDE_FLOAT32_C(   409.19), SIMDE_FLOAT32_C(   113.69),
        SIMDE_FLOAT32_C(   772.77), SIMDE_FLOAT32_C(   327.43), SIMDE_FLOAT32_C(  -141.31), SIMDE_FLOAT32_C(  -361.66) },
      UINT8_C(173),
      { SIMDE_FLOAT32_C(  -387.95), SIMDE_FLOAT32_C(  -106.78), SIMDE_FLOAT32_C(  -176.38), SIMDE_FLOAT32_C(  -628.61),
        SIMDE_FLOAT32_C(   236.68), SIMDE_FLOAT32_C(  -672.68), SIMDE_FLOAT32_C(   790.55), SIMDE_FLOAT32_C(   953.50) },
      { SIMDE_FLOAT32_C(  -387.95), SIMDE_FLOAT32_C(  -176.38), SIMDE_FLOAT32_C(  -628.61), SIMDE_FLOAT32_C(  -672.68),
        SIMDE_FLOAT32_C(   953.50), SIMDE_FLOAT32_C(   327.43), SIMDE_FLOAT32_C(  -141.31), SIMDE_FLOAT32_C(  -361.66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_mask_compress_ps(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_mask_compress_ps(src, k, a);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_compressstoreu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(216),
      { SIMDE_FLOAT32_C(   247.37), SIMDE_FLOAT32_C(   840.09), SIMDE_FLOAT32_C(   -74.24), SIMDE_FLOAT32_C(  -529.81),
        SIMDE_FLOAT32_C(   608.60), SIMDE_FLOAT32_C(   163.18), SIMDE_FLOAT32_C(   245.12), SIMDE_FLOAT32_C(   708.02) },
      { SIMDE_FLOAT32_C(  -529.81), SIMDE_FLOAT32_C(   608.60), SIMDE_FLOAT32_C(   245.12), SIMDE_FLOAT32_C(   708.02),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(161),
      { SIMDE_FLOAT32_C(   711.05), SIMDE_FLOAT32_C(   338.99), SIMDE_FLOAT32_C(   253.22), SIMDE_FLOAT32_C(   677.86),
        SIMDE_FLOAT32_C(  -759.87), SIMDE_FLOAT32_C(   320.76), SIMDE_FLOAT32_C(  -635.42), SIMDE_FLOAT32_C(   702.17) },
      { SIMDE_FLOAT32_C(   711.05), SIMDE_FLOAT32_C(   320.76), SIMDE_FLOAT32_C(   702.17), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(199),
      { SIMDE_FLOAT32_C(  -344.60), SIMDE_FLOAT32_C(  -867.77), SIMDE_FLOAT32_C(  -891.09), SIMDE_FLOAT32_C(  -148.12),
        SIMDE_FLOAT32_C(   192.35), SIMDE_FLOAT32_C(  -147.15), SIMDE_FLOAT32_C(   238.27), SIMDE_FLOAT32_C(   172.27) },
      { SIMDE_FLOAT32_C(  -344.60), SIMDE_FLOAT32_C(  -867.77), SIMDE_FLOAT32_C(  -891.09), SIMDE_FLOAT32_C(   238.27),
        SIMDE_FLOAT32_C(   172.27), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 19),
      { SIMDE_FLOAT32_C(   997.87), SIMDE_FLOAT32_C(  -203.53), SIMDE_FLOAT32_C(   430.93), SIMDE_FLOAT32_C(   197.44),
        SIMDE_FLOAT32_C(  -956.16), SIMDE_FLOAT32_C(   271.02), SIMDE_FLOAT32_C(  -876.80), SIMDE_FLOAT32_C(  -485.97) },
      { SIMDE_FLOAT32_C(   997.87), SIMDE_FLOAT32_C(  -203.53), SIMDE_FLOAT32_C(  -956.16), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 98),
      { SIMDE_FLOAT32_C(   286.38), SIMDE_FLOAT32_C(   759.15), SIMDE_FLOAT32_C(  -412.36), SIMDE_FLOAT32_C(   498.68),
        SIMDE_FLOAT32_C(   470.20), SIMDE_FLOAT32_C(   926.63), SIMDE_FLOAT32_C(  -248.10), SIMDE_FLOAT32_C(   148.06) },
      { SIMDE_FLOAT32_C(   759.15), SIMDE_FLOAT32_C(   926.63), SIMDE_FLOAT32_C(  -248.10), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 22),
      { SIMDE_FLOAT32_C(  -927.34), SIMDE_FLOAT32_C(   512.64), SIMDE_FLOAT32_C(   868.93), SIMDE_FLOAT32_C(  -727.10),
        SIMDE_FLOAT32_C(  -831.96), SIMDE_FLOAT32_C(  -998.84), SIMDE_FLOAT32_C(  -618.19), SIMDE_FLOAT32_C(    19.91) },
      { SIMDE_FLOAT32_C(   512.64), SIMDE_FLOAT32_C(   868.93), SIMDE_FLOAT32_C(  -831.96), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 46),
      { SIMDE_FLOAT32_C(   234.66), SIMDE_FLOAT32_C(  -741.81), SIMDE_FLOAT32_C(  -634.22), SIMDE_FLOAT32_C(  -460.80),
        SIMDE_FLOAT32_C(  -743.94), SIMDE_FLOAT32_C(   162.25), SIMDE_FLOAT32_C(   970.13), SIMDE_FLOAT32_C(   453.50) },
      { SIMDE_FLOAT32_C(  -741.81), SIMDE_FLOAT32_C(  -634.22), SIMDE_FLOAT32_C(  -460.80), SIMDE_FLOAT32_C(   162.25),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(239),
      { SIMDE_FLOAT32_C(   241.15), SIMDE_FLOAT32_C(   576.70), SIMDE_FLOAT32_C(   720.12), SIMDE_FLOAT32_C(  -879.23),
        SIMDE_FLOAT32_C(  -136.92), SIMDE_FLOAT32_C(   479.27), SIMDE_FLOAT32_C(  -291.59), SIMDE_FLOAT32_C(  -638.25) },
      { SIMDE_FLOAT32_C(   241.15), SIMDE_FLOAT32_C(   576.70), SIMDE_FLOAT32_C(   720.12), SIMDE_FLOAT32_C(  -879.23),
        SIMDE_FLOAT32_C(   479.27), SIMDE_FLOAT32_C(  -291.59), SIMDE_FLOAT32_C(  -638.25), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_setzero_ps();
    simde_mm256_mask_compressstoreu_ps(&r, test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r = simde_mm256_setzero_ps();
    simde_mm256_mask_compressstoreu_ps(&r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_compress_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 r[8];
  } test_vec[] = {
    {    UINT8_MAX,
      { SIMDE_FLOAT32_C(   532.40), SIMDE_FLOAT32_C(  -834.00), SIMDE_FLOAT32_C(   387.34), SIMDE_FLOAT32_C(   492.79),
        SIMDE_FLOAT32_C(   459.48), SIMDE_FLOAT32_C(  -870.39), SIMDE_FLOAT32_C(  -927.17), SIMDE_FLOAT32_C(   931.24) },
      { SIMDE_FLOAT32_C(   532.40), SIMDE_FLOAT32_C(  -834.00), SIMDE_FLOAT32_C(   387.34), SIMDE_FLOAT32_C(   492.79),
        SIMDE_FLOAT32_C(   459.48), SIMDE_FLOAT32_C(  -870.39), SIMDE_FLOAT32_C(  -927.17), SIMDE_FLOAT32_C(   931.24) } },
    { UINT8_C(128),
      { SIMDE_FLOAT32_C(   380.95), SIMDE_FLOAT32_C(   579.76), SIMDE_FLOAT32_C(   949.12), SIMDE_FLOAT32_C(   731.43),
        SIMDE_FLOAT32_C(   864.60), SIMDE_FLOAT32_C(   444.57), SIMDE_FLOAT32_C(    80.80), SIMDE_FLOAT32_C(    66.37) },
      { SIMDE_FLOAT32_C(    66.37), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(115),
      { SIMDE_FLOAT32_C(   166.89), SIMDE_FLOAT32_C(  -347.44), SIMDE_FLOAT32_C(  -778.97), SIMDE_FLOAT32_C(   316.38),
        SIMDE_FLOAT32_C(  -404.22), SIMDE_FLOAT32_C(  -349.24), SIMDE_FLOAT32_C(   440.53), SIMDE_FLOAT32_C(   558.84) },
      { SIMDE_FLOAT32_C(   166.89), SIMDE_FLOAT32_C(  -347.44), SIMDE_FLOAT32_C(  -404.22), SIMDE_FLOAT32_C(  -349.24),
        SIMDE_FLOAT32_C(   440.53), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(192),
      { SIMDE_FLOAT32_C(   599.02), SIMDE_FLOAT32_C(   822.52), SIMDE_FLOAT32_C(   608.41), SIMDE_FLOAT32_C(  -830.64),
        SIMDE_FLOAT32_C(   354.92), SIMDE_FLOAT32_C(   774.41), SIMDE_FLOAT32_C(   556.70), SIMDE_FLOAT32_C(  -152.29) },
      { SIMDE_FLOAT32_C(   556.70), SIMDE_FLOAT32_C(  -152.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(120),
      { SIMDE_FLOAT32_C(   686.32), SIMDE_FLOAT32_C(   -79.46), SIMDE_FLOAT32_C(   165.13), SIMDE_FLOAT32_C(  -640.10),
        SIMDE_FLOAT32_C(  -698.51), SIMDE_FLOAT32_C(  -255.11), SIMDE_FLOAT32_C(  -690.98), SIMDE_FLOAT32_C(  -967.08) },
      { SIMDE_FLOAT32_C(  -640.10), SIMDE_FLOAT32_C(  -698.51), SIMDE_FLOAT32_C(  -255.11), SIMDE_FLOAT32_C(  -690.98),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(185),
      { SIMDE_FLOAT32_C(   753.59), SIMDE_FLOAT32_C(   113.72), SIMDE_FLOAT32_C(   675.86), SIMDE_FLOAT32_C(   215.13),
        SIMDE_FLOAT32_C(  -719.39), SIMDE_FLOAT32_C(  -671.58), SIMDE_FLOAT32_C(   436.16), SIMDE_FLOAT32_C(   596.99) },
      { SIMDE_FLOAT32_C(   753.59), SIMDE_FLOAT32_C(   215.13), SIMDE_FLOAT32_C(  -719.39), SIMDE_FLOAT32_C(  -671.58),
        SIMDE_FLOAT32_C(   596.99), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(  8),
      { SIMDE_FLOAT32_C(  -913.07), SIMDE_FLOAT32_C(    37.52), SIMDE_FLOAT32_C(  -516.96), SIMDE_FLOAT32_C(    95.24),
        SIMDE_FLOAT32_C(  -363.45), SIMDE_FLOAT32_C(  -694.44), SIMDE_FLOAT32_C(  -296.36), SIMDE_FLOAT32_C(  -194.10) },
      { SIMDE_FLOAT32_C(    95.24), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(200),
      { SIMDE_FLOAT32_C(  -521.95), SIMDE_FLOAT32_C(  -637.39), SIMDE_FLOAT32_C(  -491.80), SIMDE_FLOAT32_C(   711.93),
        SIMDE_FLOAT32_C(  -951.08), SIMDE_FLOAT32_C(   428.73), SIMDE_FLOAT32_C(  -122.94), SIMDE_FLOAT32_C(  -591.18) },
      { SIMDE_FLOAT32_C(   711.93), SIMDE_FLOAT32_C(  -122.94), SIMDE_FLOAT32_C(  -591.18), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 r = simde_mm256_maskz_compress_ps(test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_maskz_compress_ps(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compress_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compressstoreu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_compress_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compress_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compressstoreu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_compress_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
