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
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
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
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r = simde_mm256_maskz_compress_ps(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_compress_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(   444754205), -INT32_C(  1005866912), -INT32_C(  2078740289), -INT32_C(  1121153110), -INT32_C(   207394434),  INT32_C(   176802718), -INT32_C(   875437932), -INT32_C(  1303358769) },
      UINT8_C(232),
      {  INT32_C(  2101909709), -INT32_C(  1824715613), -INT32_C(  1270955739),  INT32_C(  1446247405),  INT32_C(  1777608350), -INT32_C(  1879113809),  INT32_C(   576637392), -INT32_C(   418770663) },
      {  INT32_C(  1446247405), -INT32_C(  1879113809),  INT32_C(   576637392), -INT32_C(   418770663), -INT32_C(   207394434),  INT32_C(   176802718), -INT32_C(   875437932), -INT32_C(  1303358769) } },
    { {  INT32_C(  1281643177), -INT32_C(  2065718945),  INT32_C(  1329077602), -INT32_C(  1213830376),  INT32_C(  1092655762),  INT32_C(  1792089753),  INT32_C(    25964519), -INT32_C(   370632896) },
      UINT8_C(233),
      { -INT32_C(   297257652),  INT32_C(   844155925),  INT32_C(  1884004357), -INT32_C(   536739258),  INT32_C(  1098531874),  INT32_C(  1143530517),  INT32_C(   126167408),  INT32_C(  1592880657) },
      { -INT32_C(   297257652), -INT32_C(   536739258),  INT32_C(  1143530517),  INT32_C(   126167408),  INT32_C(  1592880657),  INT32_C(  1792089753),  INT32_C(    25964519), -INT32_C(   370632896) } },
    { { -INT32_C(  1186186844),  INT32_C(   199990278), -INT32_C(  2105854404),  INT32_C(  1533247032), -INT32_C(   677585470),  INT32_C(   823903425), -INT32_C(    13000466), -INT32_C(  1285740017) },
      UINT8_C( 99),
      {  INT32_C(  1181314217), -INT32_C(  1904053161),  INT32_C(  1858471408),  INT32_C(  1160782184), -INT32_C(  2113534019), -INT32_C(  1016056030), -INT32_C(  1697484944),  INT32_C(  1996391885) },
      {  INT32_C(  1181314217), -INT32_C(  1904053161), -INT32_C(  1016056030), -INT32_C(  1697484944), -INT32_C(   677585470),  INT32_C(   823903425), -INT32_C(    13000466), -INT32_C(  1285740017) } },
    { {  INT32_C(  1220306929), -INT32_C(   858374180), -INT32_C(  1405444796),  INT32_C(  2096196286), -INT32_C(  1812007055), -INT32_C(  1621725650), -INT32_C(  1439094563), -INT32_C(  1641990227) },
      UINT8_C(159),
      {  INT32_C(   477882333),  INT32_C(  1516259261), -INT32_C(   350679935), -INT32_C(   195258883),  INT32_C(    19132307),  INT32_C(  1860092486),  INT32_C(   857508347), -INT32_C(  2016232790) },
      {  INT32_C(   477882333),  INT32_C(  1516259261), -INT32_C(   350679935), -INT32_C(   195258883),  INT32_C(    19132307), -INT32_C(  2016232790), -INT32_C(  1439094563), -INT32_C(  1641990227) } },
    { {  INT32_C(  1604603297),  INT32_C(   364446868),  INT32_C(   234934801), -INT32_C(   100443033), -INT32_C(  1845811637), -INT32_C(   486483224),  INT32_C(   219552867),  INT32_C(  2023024854) },
      UINT8_C( 53),
      {  INT32_C(  1036638008),  INT32_C(  1666113168),  INT32_C(   986340574), -INT32_C(  2054765217), -INT32_C(  1704126528),  INT32_C(   872239383),  INT32_C(  1342835303), -INT32_C(   679116129) },
      {  INT32_C(  1036638008),  INT32_C(   986340574), -INT32_C(  1704126528),  INT32_C(   872239383), -INT32_C(  1845811637), -INT32_C(   486483224),  INT32_C(   219552867),  INT32_C(  2023024854) } },
    { { -INT32_C(   384544935),  INT32_C(   206332461),  INT32_C(   507910079), -INT32_C(  1666921252), -INT32_C(    80277020), -INT32_C(   902876062), -INT32_C(   568706753),  INT32_C(   347447227) },
      UINT8_C(238),
      {  INT32_C(   740097482),  INT32_C(  1642801226),  INT32_C(   993856110), -INT32_C(  1088431698),  INT32_C(  1159862800), -INT32_C(  2105217975), -INT32_C(  1522703866), -INT32_C(   510373609) },
      {  INT32_C(  1642801226),  INT32_C(   993856110), -INT32_C(  1088431698), -INT32_C(  2105217975), -INT32_C(  1522703866), -INT32_C(   510373609), -INT32_C(   568706753),  INT32_C(   347447227) } },
    { { -INT32_C(  1727090609),  INT32_C(  1190853080), -INT32_C(  1316931837),  INT32_C(   561094672),  INT32_C(    73831355), -INT32_C(  2054690177),  INT32_C(  1663747148),  INT32_C(  1699069462) },
      UINT8_C(110),
      {  INT32_C(  1279721043),  INT32_C(   793808376), -INT32_C(  1354825458),  INT32_C(    90857586), -INT32_C(  1333498170), -INT32_C(  1157887499), -INT32_C(   221224908), -INT32_C(   127847003) },
      {  INT32_C(   793808376), -INT32_C(  1354825458),  INT32_C(    90857586), -INT32_C(  1157887499), -INT32_C(   221224908), -INT32_C(  2054690177),  INT32_C(  1663747148),  INT32_C(  1699069462) } },
    { {  INT32_C(   725919539),  INT32_C(  1130009652),  INT32_C(   150116758), -INT32_C(  1072800518), -INT32_C(  1066298678), -INT32_C(   797282916),  INT32_C(  1925335757), -INT32_C(  1301666945) },
      UINT8_C(203),
      {  INT32_C(  1140841903), -INT32_C(   791068105), -INT32_C(  1865752012), -INT32_C(  2107929616),  INT32_C(  1763580924), -INT32_C(   549982571), -INT32_C(   731993679), -INT32_C(  1012985836) },
      {  INT32_C(  1140841903), -INT32_C(   791068105), -INT32_C(  2107929616), -INT32_C(   731993679), -INT32_C(  1012985836), -INT32_C(   797282916),  INT32_C(  1925335757), -INT32_C(  1301666945) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_compress_epi32(src, test_vec[i].k, a);
    simde_assert_m256i_i32(r, ==, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_compress_epi32(src, k, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_compressstoreu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(110),
      {  INT32_C(  1086756100),  INT32_C(  1486619975),  INT32_C(  1395503843),  INT32_C(  1998802610),  INT32_C(   105875332), -INT32_C(  1981672726),  INT32_C(  1153608334),  INT32_C(  2142432123) },
      {  INT32_C(  1486619975),  INT32_C(  1395503843),  INT32_C(  1998802610), -INT32_C(  1981672726),  INT32_C(  1153608334),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(128),
      {  INT32_C(  2127019897),  INT32_C(   241311836), -INT32_C(  1681869491),  INT32_C(  1612658648), -INT32_C(  1723193977), -INT32_C(  1306012920), -INT32_C(  2144506731), -INT32_C(  1761498082) },
      { -INT32_C(  1761498082),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(107),
      { -INT32_C(   389605688),  INT32_C(   758502776), -INT32_C(   855256683),  INT32_C(   374629872), -INT32_C(  2111902289), -INT32_C(  2129145835), -INT32_C(  1449158403),  INT32_C(  1628714905) },
      { -INT32_C(   389605688),  INT32_C(   758502776),  INT32_C(   374629872), -INT32_C(  2129145835), -INT32_C(  1449158403),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 77),
      { -INT32_C(  1312470308),  INT32_C(  1346892415),  INT32_C(  1564546295),  INT32_C(  1426872168),  INT32_C(  1164611445),  INT32_C(  1044573094), -INT32_C(  1026036853), -INT32_C(   619759105) },
      { -INT32_C(  1312470308),  INT32_C(  1564546295),  INT32_C(  1426872168), -INT32_C(  1026036853),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(131),
      { -INT32_C(   972911148), -INT32_C(   390245420), -INT32_C(   347071852), -INT32_C(  1235180249), -INT32_C(    77814512), -INT32_C(   762930201), -INT32_C(  1412347790),  INT32_C(   724479319) },
      { -INT32_C(   972911148), -INT32_C(   390245420),  INT32_C(   724479319),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 58),
      { -INT32_C(  2079395535), -INT32_C(   921110865), -INT32_C(   336592058),  INT32_C(   150709859), -INT32_C(  1628440829), -INT32_C(   971980419),  INT32_C(  1058913426),  INT32_C(   460933610) },
      { -INT32_C(   921110865),  INT32_C(   150709859), -INT32_C(  1628440829), -INT32_C(   971980419),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 58),
      {  INT32_C(  2112462727), -INT32_C(  1161579593),  INT32_C(  1243459491), -INT32_C(  1588779606), -INT32_C(   719328492), -INT32_C(  1217862149),  INT32_C(  1268950786), -INT32_C(  1467564767) },
      { -INT32_C(  1161579593), -INT32_C(  1588779606), -INT32_C(   719328492), -INT32_C(  1217862149),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 93),
      {  INT32_C(   571745903), -INT32_C(  1731801111),  INT32_C(   306385132),  INT32_C(  1210508381), -INT32_C(   398197757),  INT32_C(   200014692),  INT32_C(  1512847005),  INT32_C(   750245308) },
      {  INT32_C(   571745903),  INT32_C(   306385132),  INT32_C(  1210508381), -INT32_C(   398197757),  INT32_C(  1512847005),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_setzero_si256();
    simde_mm256_mask_compressstoreu_epi32(&r, test_vec[i].k, a);
    simde_assert_m256i_i32(r, ==, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_setzero_si256();
    simde_mm256_mask_compressstoreu_epi32(&r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_compress_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C( 24),
      {  INT32_C(  1353263940),  INT32_C(   589667632), -INT32_C(   805266136),  INT32_C(  1630665167), -INT32_C(    73121872), -INT32_C(  1148550684),  INT32_C(   370041675),  INT32_C(  1546625816) },
      {  INT32_C(  1630665167), -INT32_C(    73121872),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(206),
      {  INT32_C(  1979624920),  INT32_C(  1872569042),  INT32_C(   457141538), -INT32_C(   557014882), -INT32_C(   977090748), -INT32_C(  1257210287),  INT32_C(   801974156),  INT32_C(   788408918) },
      {  INT32_C(  1872569042),  INT32_C(   457141538), -INT32_C(   557014882),  INT32_C(   801974156),  INT32_C(   788408918),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(215),
      {  INT32_C(   514434044), -INT32_C(  1371531199), -INT32_C(   145925033), -INT32_C(   281335000),  INT32_C(  1799356653),  INT32_C(   955774225), -INT32_C(   309450813),  INT32_C(   566541349) },
      {  INT32_C(   514434044), -INT32_C(  1371531199), -INT32_C(   145925033),  INT32_C(  1799356653), -INT32_C(   309450813),  INT32_C(   566541349),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 95),
      { -INT32_C(  2053095315), -INT32_C(   589475968), -INT32_C(   955984740),  INT32_C(   280294160),  INT32_C(   690036788),  INT32_C(  1055676695), -INT32_C(  1553737241),  INT32_C(   168002973) },
      { -INT32_C(  2053095315), -INT32_C(   589475968), -INT32_C(   955984740),  INT32_C(   280294160),  INT32_C(   690036788), -INT32_C(  1553737241),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(197),
      { -INT32_C(   230322013),  INT32_C(  1099833965),  INT32_C(   441537830),  INT32_C(   709779978), -INT32_C(   582912125),  INT32_C(  1036288100),  INT32_C(  1759209699),  INT32_C(   237888875) },
      { -INT32_C(   230322013),  INT32_C(   441537830),  INT32_C(  1759209699),  INT32_C(   237888875),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(117),
      { -INT32_C(  1780350605), -INT32_C(   440720241), -INT32_C(   672148107), -INT32_C(  1688528605), -INT32_C(   620808102),  INT32_C(  1690189052), -INT32_C(    36755945), -INT32_C(   948773292) },
      { -INT32_C(  1780350605), -INT32_C(   672148107), -INT32_C(   620808102),  INT32_C(  1690189052), -INT32_C(    36755945),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(223),
      {  INT32_C(  2037275733), -INT32_C(   303148265),  INT32_C(  1527825986),  INT32_C(  1505143585), -INT32_C(   413822806),  INT32_C(  1979628110),  INT32_C(  1741290377), -INT32_C(  1018785682) },
      {  INT32_C(  2037275733), -INT32_C(   303148265),  INT32_C(  1527825986),  INT32_C(  1505143585), -INT32_C(   413822806),  INT32_C(  1741290377), -INT32_C(  1018785682),  INT32_C(           0) } },
    { UINT8_C(236),
      {  INT32_C(   134429877), -INT32_C(   263458774), -INT32_C(  1408129535), -INT32_C(   313038244),  INT32_C(  2050703040),  INT32_C(   939765820),  INT32_C(   161901433),  INT32_C(  1727359409) },
      { -INT32_C(  1408129535), -INT32_C(   313038244),  INT32_C(   939765820),  INT32_C(   161901433),  INT32_C(  1727359409),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_compress_epi32(test_vec[i].k, a);
    simde_assert_m256i_i32(r, ==, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_compress_epi32(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_compress_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 7752667682494757062),  INT64_C( 5352404564057810300), -INT64_C( 4539107796754977185), -INT64_C( 7759120728795472805) },
      UINT8_C( 72),
      {  INT64_C( 2130732279473250578),  INT64_C( 5019542809946181817),  INT64_C( 6298997365836069173),  INT64_C( 6100049014523555919) },
      {  INT64_C( 6100049014523555919),  INT64_C( 5352404564057810300), -INT64_C( 4539107796754977185), -INT64_C( 7759120728795472805) } },
    { { -INT64_C( 5065991030706725157), -INT64_C( 7338709713216706997), -INT64_C( 4146105004594696604),  INT64_C( 3502336326838360835) },
      UINT8_C(234),
      { -INT64_C( 2645403578920156157),  INT64_C( 4734367680348302245), -INT64_C( 1973845161423613308),  INT64_C( 9104706670767497379) },
      {  INT64_C( 4734367680348302245),  INT64_C( 9104706670767497379), -INT64_C( 4146105004594696604),  INT64_C( 3502336326838360835) } },
    { { -INT64_C( 8322996363151522770),  INT64_C( 2055206689117552369),  INT64_C( 6813470953699556705),  INT64_C( 6856773526944073519) },
      UINT8_C(107),
      {  INT64_C( 4493711171329852068),  INT64_C( 7109762303235956922), -INT64_C( 6186120823424854873), -INT64_C( 7144050445661777848) },
      {  INT64_C( 4493711171329852068),  INT64_C( 7109762303235956922), -INT64_C( 7144050445661777848),  INT64_C( 6856773526944073519) } },
    { { -INT64_C( 4108299853689835971),  INT64_C( 7965384255491527427),  INT64_C( 7681886571605632782), -INT64_C( 1157505706478635429) },
      UINT8_C(228),
      {  INT64_C( 9033296890584673782), -INT64_C( 5363872855823711034), -INT64_C( 7927107082638622697),  INT64_C( 3942393777796370460) },
      { -INT64_C( 7927107082638622697),  INT64_C( 7965384255491527427),  INT64_C( 7681886571605632782), -INT64_C( 1157505706478635429) } },
    { {  INT64_C( 2595740651011221471),  INT64_C( 1384070719564237169),  INT64_C( 7737381310896147636), -INT64_C( 5441768002913721596) },
      UINT8_C(155),
      { -INT64_C( 8329375337356378870),  INT64_C( 3002382650293413826),  INT64_C( 9009981955553851729), -INT64_C( 3265382653199430368) },
      { -INT64_C( 8329375337356378870),  INT64_C( 3002382650293413826), -INT64_C( 3265382653199430368), -INT64_C( 5441768002913721596) } },
    { { -INT64_C( 8641508535537391548), -INT64_C( 8620407323938088168), -INT64_C( 2811769298231634526), -INT64_C( 7386858500847284765) },
      UINT8_C( 67),
      { -INT64_C( 3562470229528797115), -INT64_C(  587002722821815281), -INT64_C( 7020400084207577319), -INT64_C(   49104493988397709) },
      { -INT64_C( 3562470229528797115), -INT64_C(  587002722821815281), -INT64_C( 2811769298231634526), -INT64_C( 7386858500847284765) } },
    { { -INT64_C(  455984055470171477),  INT64_C( 6332637486098002376), -INT64_C( 8335431624635805341),  INT64_C( 8903313893864719574) },
      UINT8_C( 70),
      { -INT64_C( 5201329889240589820),  INT64_C( 3443930579009387356),  INT64_C( 1567768143362293586), -INT64_C( 2043963668908650129) },
      {  INT64_C( 3443930579009387356),  INT64_C( 1567768143362293586), -INT64_C( 8335431624635805341),  INT64_C( 8903313893864719574) } },
    { {  INT64_C( 6519450837468369851),  INT64_C(  884268732233444984), -INT64_C( 3318386145431614196), -INT64_C(  806760910580492278) },
      UINT8_C(163),
      { -INT64_C( 7138210707381570119), -INT64_C( 2930045336832047683), -INT64_C(  207437002978086053), -INT64_C( 8022834162468255434) },
      { -INT64_C( 7138210707381570119), -INT64_C( 2930045336832047683), -INT64_C( 3318386145431614196), -INT64_C(  806760910580492278) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_compress_epi64(src, test_vec[i].k, a);
    simde_assert_m256i_i64(r, ==, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_compress_epi64(src, k, a);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_compressstoreu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(245),
      { -INT64_C( 3704009241857391289),  INT64_C(  844004499105526930), -INT64_C( 3059452695861390400), -INT64_C( 1570762709827708293) },
      { -INT64_C( 3704009241857391289), -INT64_C( 3059452695861390400),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 12),
      { -INT64_C( 3111967962575861626),  INT64_C( 6941874743044904469), -INT64_C( 7805247807075651696), -INT64_C( 6481206392396452742) },
      { -INT64_C( 7805247807075651696), -INT64_C( 6481206392396452742),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 42),
      {  INT64_C( 5438835101432210515),  INT64_C( 6205951935214260241), -INT64_C( 1297772263750282669),  INT64_C( 6910126070529130138) },
      {  INT64_C( 6205951935214260241),  INT64_C( 6910126070529130138),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(152),
      {  INT64_C( 5647681326108492976),  INT64_C( 7096277797587775536), -INT64_C(  371459028756005157),  INT64_C( 3001761821788377948) },
      {  INT64_C( 3001761821788377948),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 42),
      { -INT64_C( 3981543979347314443),  INT64_C( 6940674170323265132), -INT64_C(  267869169186467684), -INT64_C(  726031713813833636) },
      {  INT64_C( 6940674170323265132), -INT64_C(  726031713813833636),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 22),
      {  INT64_C( 2843943179708695380), -INT64_C( 3358020378859802993), -INT64_C(  938940484632817338), -INT64_C(  261234448166306901) },
      { -INT64_C( 3358020378859802993), -INT64_C(  938940484632817338),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(107),
      {  INT64_C( 7823830615382034253),  INT64_C( 1408922730839759965), -INT64_C( 2478492573003601479), -INT64_C( 8077346383637191789) },
      {  INT64_C( 7823830615382034253),  INT64_C( 1408922730839759965), -INT64_C( 8077346383637191789),  INT64_C(                   0) } },
    { UINT8_C(135),
      { -INT64_C( 8879565576733354861), -INT64_C( 4370926392724550625), -INT64_C( 4378973417519102457),  INT64_C( 3481165537567159623) },
      { -INT64_C( 8879565576733354861), -INT64_C( 4370926392724550625), -INT64_C( 4378973417519102457),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_setzero_si256();
    simde_mm256_mask_compressstoreu_epi64(&r, test_vec[i].k, a);
    simde_assert_m256i_i64(r, ==, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_setzero_si256();
    simde_mm256_mask_compressstoreu_epi64(&r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_compress_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(201),
      {  INT64_C(   39523489099383952), -INT64_C( 2113514892668969908), -INT64_C( 9067195570661046204), -INT64_C( 4883996374866910044) },
      {  INT64_C(   39523489099383952), -INT64_C( 4883996374866910044),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 20),
      { -INT64_C( 8215835992612199099), -INT64_C( 7421413415111547533),  INT64_C( 8436867530026657431),  INT64_C(   84828129966785674) },
      {  INT64_C( 8436867530026657431),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(131),
      { -INT64_C( 3343709778219847511),  INT64_C( 8945622572987471030),  INT64_C( 3373550894993741184), -INT64_C( 4484200839536514333) },
      { -INT64_C( 3343709778219847511),  INT64_C( 8945622572987471030),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(156),
      { -INT64_C( 3283096096271177992), -INT64_C( 5154189299131285828),  INT64_C( 8905465363842711409), -INT64_C( 7709225106398783364) },
      {  INT64_C( 8905465363842711409), -INT64_C( 7709225106398783364),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 58),
      { -INT64_C( 4818417571659755701),  INT64_C( 5892847486944418226), -INT64_C( 1654690157617382660), -INT64_C( 4576472559687208465) },
      {  INT64_C( 5892847486944418226), -INT64_C( 4576472559687208465),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(105),
      {  INT64_C( 6877812772494189877),  INT64_C(  818601320632076743),  INT64_C( 7237009669575469347),  INT64_C( 7281924982212965002) },
      {  INT64_C( 6877812772494189877),  INT64_C( 7281924982212965002),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(189),
      {  INT64_C( 7054152796823823671), -INT64_C( 8451008404818672301),  INT64_C( 6388604175000614680), -INT64_C( 7849512074512675398) },
      {  INT64_C( 7054152796823823671),  INT64_C( 6388604175000614680), -INT64_C( 7849512074512675398),  INT64_C(                   0) } },
    { UINT8_C( 19),
      { -INT64_C( 2609540668708900589),  INT64_C( 5481731862906559998),  INT64_C( 2674938996965126276), -INT64_C( 7650467315170839853) },
      { -INT64_C( 2609540668708900589),  INT64_C( 5481731862906559998),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_compress_epi64(test_vec[i].k, a);
    simde_assert_m256i_i64(r, ==, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_compress_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compress_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -447.17), SIMDE_FLOAT64_C(  -260.48), SIMDE_FLOAT64_C(   495.12), SIMDE_FLOAT64_C(   721.09),
        SIMDE_FLOAT64_C(   161.83), SIMDE_FLOAT64_C(   560.84), SIMDE_FLOAT64_C(   729.72), SIMDE_FLOAT64_C(  -826.53) },
      UINT8_C( 19),
      { SIMDE_FLOAT64_C(   235.20), SIMDE_FLOAT64_C(   412.82), SIMDE_FLOAT64_C(   675.87), SIMDE_FLOAT64_C(  -772.94),
        SIMDE_FLOAT64_C(   995.34), SIMDE_FLOAT64_C(   960.28), SIMDE_FLOAT64_C(  -657.89), SIMDE_FLOAT64_C(  -347.82) },
      { SIMDE_FLOAT64_C(   235.20), SIMDE_FLOAT64_C(   412.82), SIMDE_FLOAT64_C(   995.34), SIMDE_FLOAT64_C(   721.09),
        SIMDE_FLOAT64_C(   161.83), SIMDE_FLOAT64_C(   560.84), SIMDE_FLOAT64_C(   729.72), SIMDE_FLOAT64_C(  -826.53) } },
    { { SIMDE_FLOAT64_C(   524.62), SIMDE_FLOAT64_C(   321.42), SIMDE_FLOAT64_C(  -352.93), SIMDE_FLOAT64_C(  -518.27),
        SIMDE_FLOAT64_C(   212.62), SIMDE_FLOAT64_C(   610.23), SIMDE_FLOAT64_C(   567.94), SIMDE_FLOAT64_C(  -420.78) },
      UINT8_C(204),
      { SIMDE_FLOAT64_C(  -170.25), SIMDE_FLOAT64_C(  -111.68), SIMDE_FLOAT64_C(  -794.91), SIMDE_FLOAT64_C(   856.21),
        SIMDE_FLOAT64_C(  -758.54), SIMDE_FLOAT64_C(  -242.07), SIMDE_FLOAT64_C(  -404.28), SIMDE_FLOAT64_C(   736.58) },
      { SIMDE_FLOAT64_C(  -794.91), SIMDE_FLOAT64_C(   856.21), SIMDE_FLOAT64_C(  -404.28), SIMDE_FLOAT64_C(   736.58),
        SIMDE_FLOAT64_C(   212.62), SIMDE_FLOAT64_C(   610.23), SIMDE_FLOAT64_C(   567.94), SIMDE_FLOAT64_C(  -420.78) } },
    { { SIMDE_FLOAT64_C(  -520.98), SIMDE_FLOAT64_C(   757.55), SIMDE_FLOAT64_C(   297.42), SIMDE_FLOAT64_C(  -791.26),
        SIMDE_FLOAT64_C(   931.03), SIMDE_FLOAT64_C(   874.44), SIMDE_FLOAT64_C(   443.94), SIMDE_FLOAT64_C(   343.84) },
      UINT8_C( 51),
      { SIMDE_FLOAT64_C(   671.01), SIMDE_FLOAT64_C(   339.19), SIMDE_FLOAT64_C(   510.59), SIMDE_FLOAT64_C(  -986.88),
        SIMDE_FLOAT64_C(   991.37), SIMDE_FLOAT64_C(    35.22), SIMDE_FLOAT64_C(   334.54), SIMDE_FLOAT64_C(  -361.56) },
      { SIMDE_FLOAT64_C(   671.01), SIMDE_FLOAT64_C(   339.19), SIMDE_FLOAT64_C(   991.37), SIMDE_FLOAT64_C(    35.22),
        SIMDE_FLOAT64_C(   931.03), SIMDE_FLOAT64_C(   874.44), SIMDE_FLOAT64_C(   443.94), SIMDE_FLOAT64_C(   343.84) } },
    { { SIMDE_FLOAT64_C(   516.95), SIMDE_FLOAT64_C(  -452.83), SIMDE_FLOAT64_C(  -751.33), SIMDE_FLOAT64_C(    84.89),
        SIMDE_FLOAT64_C(   126.39), SIMDE_FLOAT64_C(  -900.10), SIMDE_FLOAT64_C(   914.64), SIMDE_FLOAT64_C(  -985.30) },
      UINT8_C(104),
      { SIMDE_FLOAT64_C(   770.85), SIMDE_FLOAT64_C(  -743.84), SIMDE_FLOAT64_C(    62.92), SIMDE_FLOAT64_C(  -633.43),
        SIMDE_FLOAT64_C(   992.73), SIMDE_FLOAT64_C(   541.94), SIMDE_FLOAT64_C(  -875.88), SIMDE_FLOAT64_C(   290.15) },
      { SIMDE_FLOAT64_C(  -633.43), SIMDE_FLOAT64_C(   541.94), SIMDE_FLOAT64_C(  -875.88), SIMDE_FLOAT64_C(    84.89),
        SIMDE_FLOAT64_C(   126.39), SIMDE_FLOAT64_C(  -900.10), SIMDE_FLOAT64_C(   914.64), SIMDE_FLOAT64_C(  -985.30) } },
    { { SIMDE_FLOAT64_C(   750.68), SIMDE_FLOAT64_C(  -944.85), SIMDE_FLOAT64_C(   164.59), SIMDE_FLOAT64_C(   194.63),
        SIMDE_FLOAT64_C(   398.99), SIMDE_FLOAT64_C(  -285.09), SIMDE_FLOAT64_C(  -134.36), SIMDE_FLOAT64_C(  -261.82) },
      UINT8_C( 66),
      { SIMDE_FLOAT64_C(  -121.24), SIMDE_FLOAT64_C(  -270.45), SIMDE_FLOAT64_C(   260.72), SIMDE_FLOAT64_C(  -786.70),
        SIMDE_FLOAT64_C(   367.99), SIMDE_FLOAT64_C(  -222.33), SIMDE_FLOAT64_C(  -239.54), SIMDE_FLOAT64_C(   616.65) },
      { SIMDE_FLOAT64_C(  -270.45), SIMDE_FLOAT64_C(  -239.54), SIMDE_FLOAT64_C(   164.59), SIMDE_FLOAT64_C(   194.63),
        SIMDE_FLOAT64_C(   398.99), SIMDE_FLOAT64_C(  -285.09), SIMDE_FLOAT64_C(  -134.36), SIMDE_FLOAT64_C(  -261.82) } },
    { { SIMDE_FLOAT64_C(   862.56), SIMDE_FLOAT64_C(   886.85), SIMDE_FLOAT64_C(   716.56), SIMDE_FLOAT64_C(   777.20),
        SIMDE_FLOAT64_C(   901.55), SIMDE_FLOAT64_C(  -978.44), SIMDE_FLOAT64_C(   548.05), SIMDE_FLOAT64_C(  -842.29) },
      UINT8_C( 91),
      { SIMDE_FLOAT64_C(   914.62), SIMDE_FLOAT64_C(  -849.55), SIMDE_FLOAT64_C(  -373.58), SIMDE_FLOAT64_C(  -961.26),
        SIMDE_FLOAT64_C(   440.60), SIMDE_FLOAT64_C(  -622.89), SIMDE_FLOAT64_C(  -906.11), SIMDE_FLOAT64_C(  -394.81) },
      { SIMDE_FLOAT64_C(   914.62), SIMDE_FLOAT64_C(  -849.55), SIMDE_FLOAT64_C(  -961.26), SIMDE_FLOAT64_C(   440.60),
        SIMDE_FLOAT64_C(  -906.11), SIMDE_FLOAT64_C(  -978.44), SIMDE_FLOAT64_C(   548.05), SIMDE_FLOAT64_C(  -842.29) } },
    { { SIMDE_FLOAT64_C(   571.74), SIMDE_FLOAT64_C(   492.88), SIMDE_FLOAT64_C(   320.10), SIMDE_FLOAT64_C(  -562.63),
        SIMDE_FLOAT64_C(  -768.94), SIMDE_FLOAT64_C(   545.60), SIMDE_FLOAT64_C(   316.13), SIMDE_FLOAT64_C(   -39.40) },
      UINT8_C( 92),
      { SIMDE_FLOAT64_C(   529.43), SIMDE_FLOAT64_C(  -671.41), SIMDE_FLOAT64_C(   584.00), SIMDE_FLOAT64_C(  -710.11),
        SIMDE_FLOAT64_C(   945.24), SIMDE_FLOAT64_C(   446.56), SIMDE_FLOAT64_C(  -823.26), SIMDE_FLOAT64_C(   661.80) },
      { SIMDE_FLOAT64_C(   584.00), SIMDE_FLOAT64_C(  -710.11), SIMDE_FLOAT64_C(   945.24), SIMDE_FLOAT64_C(  -823.26),
        SIMDE_FLOAT64_C(  -768.94), SIMDE_FLOAT64_C(   545.60), SIMDE_FLOAT64_C(   316.13), SIMDE_FLOAT64_C(   -39.40) } },
    { { SIMDE_FLOAT64_C(   223.76), SIMDE_FLOAT64_C(  -921.71), SIMDE_FLOAT64_C(   683.36), SIMDE_FLOAT64_C(  -228.19),
        SIMDE_FLOAT64_C(  -763.99), SIMDE_FLOAT64_C(  -232.16), SIMDE_FLOAT64_C(  -313.58), SIMDE_FLOAT64_C(  -613.55) },
      UINT8_C( 36),
      { SIMDE_FLOAT64_C(  -274.84), SIMDE_FLOAT64_C(   827.05), SIMDE_FLOAT64_C(   771.37), SIMDE_FLOAT64_C(  -180.95),
        SIMDE_FLOAT64_C(  -567.76), SIMDE_FLOAT64_C(   343.11), SIMDE_FLOAT64_C(  -688.07), SIMDE_FLOAT64_C(   752.35) },
      { SIMDE_FLOAT64_C(   771.37), SIMDE_FLOAT64_C(   343.11), SIMDE_FLOAT64_C(   683.36), SIMDE_FLOAT64_C(  -228.19),
        SIMDE_FLOAT64_C(  -763.99), SIMDE_FLOAT64_C(  -232.16), SIMDE_FLOAT64_C(  -313.58), SIMDE_FLOAT64_C(  -613.55) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_loadu_pd(test_vec[i].src);
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d r = simde_mm512_mask_compress_pd(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_mm512_mask_compress_pd(src, k, a);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compressstoreu_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C( 33),
      { SIMDE_FLOAT64_C(  -294.18), SIMDE_FLOAT64_C(  -232.59), SIMDE_FLOAT64_C(    -3.64), SIMDE_FLOAT64_C(   350.96),
        SIMDE_FLOAT64_C(   399.28), SIMDE_FLOAT64_C(   635.11), SIMDE_FLOAT64_C(  -645.08), SIMDE_FLOAT64_C(  -526.07) },
      { SIMDE_FLOAT64_C(  -294.18), SIMDE_FLOAT64_C(   635.11), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(130),
      { SIMDE_FLOAT64_C(   301.21), SIMDE_FLOAT64_C(   -74.18), SIMDE_FLOAT64_C(  -493.30), SIMDE_FLOAT64_C(   526.02),
        SIMDE_FLOAT64_C(  -710.21), SIMDE_FLOAT64_C(   691.03), SIMDE_FLOAT64_C(   902.79), SIMDE_FLOAT64_C(  -490.23) },
      { SIMDE_FLOAT64_C(   -74.18), SIMDE_FLOAT64_C(  -490.23), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(189),
      { SIMDE_FLOAT64_C(  -733.74), SIMDE_FLOAT64_C(   206.83), SIMDE_FLOAT64_C(   166.69), SIMDE_FLOAT64_C(  -484.91),
        SIMDE_FLOAT64_C(  -922.75), SIMDE_FLOAT64_C(  -399.67), SIMDE_FLOAT64_C(   941.43), SIMDE_FLOAT64_C(  -820.74) },
      { SIMDE_FLOAT64_C(  -733.74), SIMDE_FLOAT64_C(   166.69), SIMDE_FLOAT64_C(  -484.91), SIMDE_FLOAT64_C(  -922.75),
        SIMDE_FLOAT64_C(  -399.67), SIMDE_FLOAT64_C(  -820.74), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(146),
      { SIMDE_FLOAT64_C(   782.51), SIMDE_FLOAT64_C(   443.18), SIMDE_FLOAT64_C(  -107.16), SIMDE_FLOAT64_C(   177.87),
        SIMDE_FLOAT64_C(  -851.01), SIMDE_FLOAT64_C(   660.25), SIMDE_FLOAT64_C(  -825.77), SIMDE_FLOAT64_C(   499.95) },
      { SIMDE_FLOAT64_C(   443.18), SIMDE_FLOAT64_C(  -851.01), SIMDE_FLOAT64_C(   499.95), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 15),
      { SIMDE_FLOAT64_C(   809.34), SIMDE_FLOAT64_C(   854.87), SIMDE_FLOAT64_C(   533.46), SIMDE_FLOAT64_C(  -409.28),
        SIMDE_FLOAT64_C(   156.09), SIMDE_FLOAT64_C(  -540.72), SIMDE_FLOAT64_C(    97.41), SIMDE_FLOAT64_C(  -317.90) },
      { SIMDE_FLOAT64_C(   809.34), SIMDE_FLOAT64_C(   854.87), SIMDE_FLOAT64_C(   533.46), SIMDE_FLOAT64_C(  -409.28),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 52),
      { SIMDE_FLOAT64_C(  -211.56), SIMDE_FLOAT64_C(  -415.11), SIMDE_FLOAT64_C(   258.84), SIMDE_FLOAT64_C(   527.09),
        SIMDE_FLOAT64_C(  -148.85), SIMDE_FLOAT64_C(  -534.33), SIMDE_FLOAT64_C(  -306.22), SIMDE_FLOAT64_C(   366.24) },
      { SIMDE_FLOAT64_C(   258.84), SIMDE_FLOAT64_C(  -148.85), SIMDE_FLOAT64_C(  -534.33), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(148),
      { SIMDE_FLOAT64_C(   294.11), SIMDE_FLOAT64_C(   307.67), SIMDE_FLOAT64_C(  -277.82), SIMDE_FLOAT64_C(  -460.66),
        SIMDE_FLOAT64_C(    90.19), SIMDE_FLOAT64_C(  -834.64), SIMDE_FLOAT64_C(   432.18), SIMDE_FLOAT64_C(  -731.94) },
      { SIMDE_FLOAT64_C(  -277.82), SIMDE_FLOAT64_C(    90.19), SIMDE_FLOAT64_C(  -731.94), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(135),
      { SIMDE_FLOAT64_C(    92.43), SIMDE_FLOAT64_C(  -557.71), SIMDE_FLOAT64_C(   814.30), SIMDE_FLOAT64_C(  -848.04),
        SIMDE_FLOAT64_C(  -748.37), SIMDE_FLOAT64_C(   669.17), SIMDE_FLOAT64_C(   685.42), SIMDE_FLOAT64_C(  -157.65) },
      { SIMDE_FLOAT64_C(    92.43), SIMDE_FLOAT64_C(  -557.71), SIMDE_FLOAT64_C(   814.30), SIMDE_FLOAT64_C(  -157.65),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d r = simde_mm512_setzero_pd();
    simde_mm512_mask_compressstoreu_pd(&r, test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_mm512_setzero_pd();
    simde_mm512_mask_compressstoreu_pd(&r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_compress_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(105),
      { SIMDE_FLOAT64_C(   933.56), SIMDE_FLOAT64_C(  -433.68), SIMDE_FLOAT64_C(  -293.23), SIMDE_FLOAT64_C(  -347.07),
        SIMDE_FLOAT64_C(   584.35), SIMDE_FLOAT64_C(  -753.61), SIMDE_FLOAT64_C(   603.74), SIMDE_FLOAT64_C(   116.50) },
      { SIMDE_FLOAT64_C(   933.56), SIMDE_FLOAT64_C(  -347.07), SIMDE_FLOAT64_C(  -753.61), SIMDE_FLOAT64_C(   603.74),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(125),
      { SIMDE_FLOAT64_C(    20.79), SIMDE_FLOAT64_C(  -277.29), SIMDE_FLOAT64_C(    90.28), SIMDE_FLOAT64_C(   276.49),
        SIMDE_FLOAT64_C(   849.06), SIMDE_FLOAT64_C(   708.07), SIMDE_FLOAT64_C(  -822.32), SIMDE_FLOAT64_C(    47.75) },
      { SIMDE_FLOAT64_C(    20.79), SIMDE_FLOAT64_C(    90.28), SIMDE_FLOAT64_C(   276.49), SIMDE_FLOAT64_C(   849.06),
        SIMDE_FLOAT64_C(   708.07), SIMDE_FLOAT64_C(  -822.32), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(189),
      { SIMDE_FLOAT64_C(   548.02), SIMDE_FLOAT64_C(   503.84), SIMDE_FLOAT64_C(   693.16), SIMDE_FLOAT64_C(  -475.09),
        SIMDE_FLOAT64_C(  -523.78), SIMDE_FLOAT64_C(  -219.94), SIMDE_FLOAT64_C(   613.55), SIMDE_FLOAT64_C(  -361.76) },
      { SIMDE_FLOAT64_C(   548.02), SIMDE_FLOAT64_C(   693.16), SIMDE_FLOAT64_C(  -475.09), SIMDE_FLOAT64_C(  -523.78),
        SIMDE_FLOAT64_C(  -219.94), SIMDE_FLOAT64_C(  -361.76), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(117),
      { SIMDE_FLOAT64_C(   486.64), SIMDE_FLOAT64_C(  -148.33), SIMDE_FLOAT64_C(  -126.75), SIMDE_FLOAT64_C(   735.45),
        SIMDE_FLOAT64_C(  -214.78), SIMDE_FLOAT64_C(   439.57), SIMDE_FLOAT64_C(  -557.79), SIMDE_FLOAT64_C(   438.16) },
      { SIMDE_FLOAT64_C(   486.64), SIMDE_FLOAT64_C(  -126.75), SIMDE_FLOAT64_C(  -214.78), SIMDE_FLOAT64_C(   439.57),
        SIMDE_FLOAT64_C(  -557.79), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(222),
      { SIMDE_FLOAT64_C(  -311.39), SIMDE_FLOAT64_C(    41.90), SIMDE_FLOAT64_C(  -859.58), SIMDE_FLOAT64_C(  -571.89),
        SIMDE_FLOAT64_C(  -937.32), SIMDE_FLOAT64_C(  -136.87), SIMDE_FLOAT64_C(   518.40), SIMDE_FLOAT64_C(   339.18) },
      { SIMDE_FLOAT64_C(    41.90), SIMDE_FLOAT64_C(  -859.58), SIMDE_FLOAT64_C(  -571.89), SIMDE_FLOAT64_C(  -937.32),
        SIMDE_FLOAT64_C(   518.40), SIMDE_FLOAT64_C(   339.18), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 60),
      { SIMDE_FLOAT64_C(   226.46), SIMDE_FLOAT64_C(   516.86), SIMDE_FLOAT64_C(   759.94), SIMDE_FLOAT64_C(   994.69),
        SIMDE_FLOAT64_C(    64.88), SIMDE_FLOAT64_C(   263.78), SIMDE_FLOAT64_C(   687.84), SIMDE_FLOAT64_C(   589.79) },
      { SIMDE_FLOAT64_C(   759.94), SIMDE_FLOAT64_C(   994.69), SIMDE_FLOAT64_C(    64.88), SIMDE_FLOAT64_C(   263.78),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(240),
      { SIMDE_FLOAT64_C(  -532.10), SIMDE_FLOAT64_C(   203.34), SIMDE_FLOAT64_C(  -621.76), SIMDE_FLOAT64_C(  -287.41),
        SIMDE_FLOAT64_C(  -310.03), SIMDE_FLOAT64_C(   229.91), SIMDE_FLOAT64_C(   585.84), SIMDE_FLOAT64_C(  -574.58) },
      { SIMDE_FLOAT64_C(  -310.03), SIMDE_FLOAT64_C(   229.91), SIMDE_FLOAT64_C(   585.84), SIMDE_FLOAT64_C(  -574.58),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(225),
      { SIMDE_FLOAT64_C(    25.41), SIMDE_FLOAT64_C(  -132.37), SIMDE_FLOAT64_C(   453.29), SIMDE_FLOAT64_C(  -950.67),
        SIMDE_FLOAT64_C(   556.24), SIMDE_FLOAT64_C(  -504.81), SIMDE_FLOAT64_C(  -810.25), SIMDE_FLOAT64_C(   984.35) },
      { SIMDE_FLOAT64_C(    25.41), SIMDE_FLOAT64_C(  -504.81), SIMDE_FLOAT64_C(  -810.25), SIMDE_FLOAT64_C(   984.35),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d r = simde_mm512_maskz_compress_pd(test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_mm512_maskz_compress_pd(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compress_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   867.67), SIMDE_FLOAT32_C(  -936.59), SIMDE_FLOAT32_C(   552.20), SIMDE_FLOAT32_C(    17.20),
        SIMDE_FLOAT32_C(     1.62), SIMDE_FLOAT32_C(   729.26), SIMDE_FLOAT32_C(  -297.03), SIMDE_FLOAT32_C(  -375.07),
        SIMDE_FLOAT32_C(   321.49), SIMDE_FLOAT32_C(  -850.77), SIMDE_FLOAT32_C(  -821.44), SIMDE_FLOAT32_C(   559.48),
        SIMDE_FLOAT32_C(  -267.22), SIMDE_FLOAT32_C(  -841.16), SIMDE_FLOAT32_C(   123.72), SIMDE_FLOAT32_C(   853.93) },
      UINT16_C(41743),
      { SIMDE_FLOAT32_C(    55.89), SIMDE_FLOAT32_C(   465.99), SIMDE_FLOAT32_C(   396.45), SIMDE_FLOAT32_C(   -62.15),
        SIMDE_FLOAT32_C(   516.04), SIMDE_FLOAT32_C(   767.23), SIMDE_FLOAT32_C(  -362.08), SIMDE_FLOAT32_C(  -309.52),
        SIMDE_FLOAT32_C(  -363.94), SIMDE_FLOAT32_C(  -306.11), SIMDE_FLOAT32_C(   725.95), SIMDE_FLOAT32_C(  -359.83),
        SIMDE_FLOAT32_C(    57.67), SIMDE_FLOAT32_C(   593.63), SIMDE_FLOAT32_C(  -296.41), SIMDE_FLOAT32_C(  -390.12) },
      { SIMDE_FLOAT32_C(    55.89), SIMDE_FLOAT32_C(   465.99), SIMDE_FLOAT32_C(   396.45), SIMDE_FLOAT32_C(   -62.15),
        SIMDE_FLOAT32_C(  -363.94), SIMDE_FLOAT32_C(  -306.11), SIMDE_FLOAT32_C(   593.63), SIMDE_FLOAT32_C(  -390.12),
        SIMDE_FLOAT32_C(   321.49), SIMDE_FLOAT32_C(  -850.77), SIMDE_FLOAT32_C(  -821.44), SIMDE_FLOAT32_C(   559.48),
        SIMDE_FLOAT32_C(  -267.22), SIMDE_FLOAT32_C(  -841.16), SIMDE_FLOAT32_C(   123.72), SIMDE_FLOAT32_C(   853.93) } },
    { { SIMDE_FLOAT32_C(  -389.18), SIMDE_FLOAT32_C(   705.20), SIMDE_FLOAT32_C(  -660.86), SIMDE_FLOAT32_C(   313.80),
        SIMDE_FLOAT32_C(  -669.86), SIMDE_FLOAT32_C(   660.63), SIMDE_FLOAT32_C(   463.03), SIMDE_FLOAT32_C(  -491.31),
        SIMDE_FLOAT32_C(   220.10), SIMDE_FLOAT32_C(  -804.20), SIMDE_FLOAT32_C(  -332.46), SIMDE_FLOAT32_C(  -656.17),
        SIMDE_FLOAT32_C(  -950.27), SIMDE_FLOAT32_C(  -103.70), SIMDE_FLOAT32_C(   715.07), SIMDE_FLOAT32_C(   105.62) },
      UINT16_C(40891),
      { SIMDE_FLOAT32_C(  -956.53), SIMDE_FLOAT32_C(   878.33), SIMDE_FLOAT32_C(  -121.25), SIMDE_FLOAT32_C(  -318.61),
        SIMDE_FLOAT32_C(  -431.19), SIMDE_FLOAT32_C(   514.81), SIMDE_FLOAT32_C(   375.29), SIMDE_FLOAT32_C(  -705.24),
        SIMDE_FLOAT32_C(  -845.02), SIMDE_FLOAT32_C(  -567.04), SIMDE_FLOAT32_C(   888.39), SIMDE_FLOAT32_C(  -141.43),
        SIMDE_FLOAT32_C(    42.83), SIMDE_FLOAT32_C(  -500.79), SIMDE_FLOAT32_C(  -436.23), SIMDE_FLOAT32_C(   381.97) },
      { SIMDE_FLOAT32_C(  -956.53), SIMDE_FLOAT32_C(   878.33), SIMDE_FLOAT32_C(  -318.61), SIMDE_FLOAT32_C(  -431.19),
        SIMDE_FLOAT32_C(   514.81), SIMDE_FLOAT32_C(  -705.24), SIMDE_FLOAT32_C(  -845.02), SIMDE_FLOAT32_C(  -567.04),
        SIMDE_FLOAT32_C(   888.39), SIMDE_FLOAT32_C(  -141.43), SIMDE_FLOAT32_C(    42.83), SIMDE_FLOAT32_C(   381.97),
        SIMDE_FLOAT32_C(  -950.27), SIMDE_FLOAT32_C(  -103.70), SIMDE_FLOAT32_C(   715.07), SIMDE_FLOAT32_C(   105.62) } },
    { { SIMDE_FLOAT32_C(   813.01), SIMDE_FLOAT32_C(  -106.09), SIMDE_FLOAT32_C(    42.60), SIMDE_FLOAT32_C(   276.03),
        SIMDE_FLOAT32_C(   402.60), SIMDE_FLOAT32_C(  -737.30), SIMDE_FLOAT32_C(   471.84), SIMDE_FLOAT32_C(  -929.86),
        SIMDE_FLOAT32_C(  -393.47), SIMDE_FLOAT32_C(   521.57), SIMDE_FLOAT32_C(   -33.56), SIMDE_FLOAT32_C(  -678.40),
        SIMDE_FLOAT32_C(  -372.81), SIMDE_FLOAT32_C(   328.73), SIMDE_FLOAT32_C(   433.13), SIMDE_FLOAT32_C(  -329.34) },
      UINT16_C(48098),
      { SIMDE_FLOAT32_C(   352.05), SIMDE_FLOAT32_C(   775.87), SIMDE_FLOAT32_C(   826.69), SIMDE_FLOAT32_C(  -272.66),
        SIMDE_FLOAT32_C(  -929.36), SIMDE_FLOAT32_C(   981.66), SIMDE_FLOAT32_C(   160.30), SIMDE_FLOAT32_C(   959.03),
        SIMDE_FLOAT32_C(  -159.77), SIMDE_FLOAT32_C(  -796.86), SIMDE_FLOAT32_C(  -541.76), SIMDE_FLOAT32_C(   404.00),
        SIMDE_FLOAT32_C(   585.11), SIMDE_FLOAT32_C(  -728.75), SIMDE_FLOAT32_C(  -702.09), SIMDE_FLOAT32_C(  -372.29) },
      { SIMDE_FLOAT32_C(   775.87), SIMDE_FLOAT32_C(   981.66), SIMDE_FLOAT32_C(   160.30), SIMDE_FLOAT32_C(   959.03),
        SIMDE_FLOAT32_C(  -159.77), SIMDE_FLOAT32_C(  -796.86), SIMDE_FLOAT32_C(   404.00), SIMDE_FLOAT32_C(   585.11),
        SIMDE_FLOAT32_C(  -728.75), SIMDE_FLOAT32_C(  -372.29), SIMDE_FLOAT32_C(   -33.56), SIMDE_FLOAT32_C(  -678.40),
        SIMDE_FLOAT32_C(  -372.81), SIMDE_FLOAT32_C(   328.73), SIMDE_FLOAT32_C(   433.13), SIMDE_FLOAT32_C(  -329.34) } },
    { { SIMDE_FLOAT32_C(   547.28), SIMDE_FLOAT32_C(   700.51), SIMDE_FLOAT32_C(  -109.59), SIMDE_FLOAT32_C(    19.12),
        SIMDE_FLOAT32_C(   770.64), SIMDE_FLOAT32_C(   496.94), SIMDE_FLOAT32_C(  -459.31), SIMDE_FLOAT32_C(  -262.92),
        SIMDE_FLOAT32_C(   818.55), SIMDE_FLOAT32_C(   167.88), SIMDE_FLOAT32_C(  -934.19), SIMDE_FLOAT32_C(   251.68),
        SIMDE_FLOAT32_C(   838.54), SIMDE_FLOAT32_C(   272.87), SIMDE_FLOAT32_C(   563.56), SIMDE_FLOAT32_C(   190.59) },
      UINT16_C(26126),
      { SIMDE_FLOAT32_C(   917.93), SIMDE_FLOAT32_C(   119.38), SIMDE_FLOAT32_C(   371.91), SIMDE_FLOAT32_C(    78.24),
        SIMDE_FLOAT32_C(    78.41), SIMDE_FLOAT32_C(  -787.86), SIMDE_FLOAT32_C(   281.37), SIMDE_FLOAT32_C(   536.64),
        SIMDE_FLOAT32_C(   616.14), SIMDE_FLOAT32_C(  -133.52), SIMDE_FLOAT32_C(   807.89), SIMDE_FLOAT32_C(   914.04),
        SIMDE_FLOAT32_C(   494.19), SIMDE_FLOAT32_C(   355.17), SIMDE_FLOAT32_C(   614.55), SIMDE_FLOAT32_C(  -615.40) },
      { SIMDE_FLOAT32_C(   119.38), SIMDE_FLOAT32_C(   371.91), SIMDE_FLOAT32_C(    78.24), SIMDE_FLOAT32_C(  -133.52),
        SIMDE_FLOAT32_C(   807.89), SIMDE_FLOAT32_C(   355.17), SIMDE_FLOAT32_C(   614.55), SIMDE_FLOAT32_C(  -262.92),
        SIMDE_FLOAT32_C(   818.55), SIMDE_FLOAT32_C(   167.88), SIMDE_FLOAT32_C(  -934.19), SIMDE_FLOAT32_C(   251.68),
        SIMDE_FLOAT32_C(   838.54), SIMDE_FLOAT32_C(   272.87), SIMDE_FLOAT32_C(   563.56), SIMDE_FLOAT32_C(   190.59) } },
    { { SIMDE_FLOAT32_C(  -625.71), SIMDE_FLOAT32_C(   385.20), SIMDE_FLOAT32_C(   881.55), SIMDE_FLOAT32_C(   -85.02),
        SIMDE_FLOAT32_C(  -877.72), SIMDE_FLOAT32_C(   700.10), SIMDE_FLOAT32_C(  -917.14), SIMDE_FLOAT32_C(  -811.91),
        SIMDE_FLOAT32_C(   -48.22), SIMDE_FLOAT32_C(   921.39), SIMDE_FLOAT32_C(   460.96), SIMDE_FLOAT32_C(  -484.67),
        SIMDE_FLOAT32_C(   111.98), SIMDE_FLOAT32_C(  -490.30), SIMDE_FLOAT32_C(   905.58), SIMDE_FLOAT32_C(    29.92) },
      UINT16_C(36860),
      { SIMDE_FLOAT32_C(  -891.84), SIMDE_FLOAT32_C(  -292.52), SIMDE_FLOAT32_C(   489.62), SIMDE_FLOAT32_C(   389.53),
        SIMDE_FLOAT32_C(  -755.87), SIMDE_FLOAT32_C(   105.76), SIMDE_FLOAT32_C(  -743.99), SIMDE_FLOAT32_C(  -947.98),
        SIMDE_FLOAT32_C(    19.80), SIMDE_FLOAT32_C(   750.20), SIMDE_FLOAT32_C(   407.20), SIMDE_FLOAT32_C(  -365.65),
        SIMDE_FLOAT32_C(  -865.20), SIMDE_FLOAT32_C(   781.49), SIMDE_FLOAT32_C(  -980.45), SIMDE_FLOAT32_C(  -983.65) },
      { SIMDE_FLOAT32_C(   489.62), SIMDE_FLOAT32_C(   389.53), SIMDE_FLOAT32_C(  -755.87), SIMDE_FLOAT32_C(   105.76),
        SIMDE_FLOAT32_C(  -743.99), SIMDE_FLOAT32_C(  -947.98), SIMDE_FLOAT32_C(    19.80), SIMDE_FLOAT32_C(   750.20),
        SIMDE_FLOAT32_C(   407.20), SIMDE_FLOAT32_C(  -365.65), SIMDE_FLOAT32_C(  -983.65), SIMDE_FLOAT32_C(  -484.67),
        SIMDE_FLOAT32_C(   111.98), SIMDE_FLOAT32_C(  -490.30), SIMDE_FLOAT32_C(   905.58), SIMDE_FLOAT32_C(    29.92) } },
    { { SIMDE_FLOAT32_C(  -303.53), SIMDE_FLOAT32_C(  -858.17), SIMDE_FLOAT32_C(   716.45), SIMDE_FLOAT32_C(  -220.68),
        SIMDE_FLOAT32_C(  -670.09), SIMDE_FLOAT32_C(  -331.77), SIMDE_FLOAT32_C(  -299.28), SIMDE_FLOAT32_C(   790.87),
        SIMDE_FLOAT32_C(   183.56), SIMDE_FLOAT32_C(   812.70), SIMDE_FLOAT32_C(  -699.43), SIMDE_FLOAT32_C(    89.14),
        SIMDE_FLOAT32_C(  -157.38), SIMDE_FLOAT32_C(   929.65), SIMDE_FLOAT32_C(  -633.38), SIMDE_FLOAT32_C(   -49.22) },
      UINT16_C(15181),
      { SIMDE_FLOAT32_C(  -659.70), SIMDE_FLOAT32_C(  -118.74), SIMDE_FLOAT32_C(   -38.00), SIMDE_FLOAT32_C(  -403.69),
        SIMDE_FLOAT32_C(   -66.72), SIMDE_FLOAT32_C(   981.80), SIMDE_FLOAT32_C(  -653.49), SIMDE_FLOAT32_C(  -659.52),
        SIMDE_FLOAT32_C(  -383.85), SIMDE_FLOAT32_C(  -518.68), SIMDE_FLOAT32_C(  -878.04), SIMDE_FLOAT32_C(  -364.30),
        SIMDE_FLOAT32_C(  -502.33), SIMDE_FLOAT32_C(  -181.57), SIMDE_FLOAT32_C(  -222.47), SIMDE_FLOAT32_C(  -785.88) },
      { SIMDE_FLOAT32_C(  -659.70), SIMDE_FLOAT32_C(   -38.00), SIMDE_FLOAT32_C(  -403.69), SIMDE_FLOAT32_C(  -653.49),
        SIMDE_FLOAT32_C(  -383.85), SIMDE_FLOAT32_C(  -518.68), SIMDE_FLOAT32_C(  -364.30), SIMDE_FLOAT32_C(  -502.33),
        SIMDE_FLOAT32_C(  -181.57), SIMDE_FLOAT32_C(   812.70), SIMDE_FLOAT32_C(  -699.43), SIMDE_FLOAT32_C(    89.14),
        SIMDE_FLOAT32_C(  -157.38), SIMDE_FLOAT32_C(   929.65), SIMDE_FLOAT32_C(  -633.38), SIMDE_FLOAT32_C(   -49.22) } },
    { { SIMDE_FLOAT32_C(   597.75), SIMDE_FLOAT32_C(   107.44), SIMDE_FLOAT32_C(  -117.65), SIMDE_FLOAT32_C(  -701.53),
        SIMDE_FLOAT32_C(  -101.69), SIMDE_FLOAT32_C(  -934.09), SIMDE_FLOAT32_C(  -888.83), SIMDE_FLOAT32_C(   198.88),
        SIMDE_FLOAT32_C(   155.05), SIMDE_FLOAT32_C(   -46.21), SIMDE_FLOAT32_C(   128.53), SIMDE_FLOAT32_C(   521.67),
        SIMDE_FLOAT32_C(   904.57), SIMDE_FLOAT32_C(   765.66), SIMDE_FLOAT32_C(   377.91), SIMDE_FLOAT32_C(  -755.13) },
      UINT16_C(10299),
      { SIMDE_FLOAT32_C(  -158.82), SIMDE_FLOAT32_C(   580.20), SIMDE_FLOAT32_C(  -678.29), SIMDE_FLOAT32_C(   187.70),
        SIMDE_FLOAT32_C(   920.67), SIMDE_FLOAT32_C(   -62.14), SIMDE_FLOAT32_C(   669.01), SIMDE_FLOAT32_C(  -957.36),
        SIMDE_FLOAT32_C(   573.56), SIMDE_FLOAT32_C(  -833.32), SIMDE_FLOAT32_C(  -138.93), SIMDE_FLOAT32_C(  -648.91),
        SIMDE_FLOAT32_C(  -619.19), SIMDE_FLOAT32_C(  -541.18), SIMDE_FLOAT32_C(   458.53), SIMDE_FLOAT32_C(   263.16) },
      { SIMDE_FLOAT32_C(  -158.82), SIMDE_FLOAT32_C(   580.20), SIMDE_FLOAT32_C(   187.70), SIMDE_FLOAT32_C(   920.67),
        SIMDE_FLOAT32_C(   -62.14), SIMDE_FLOAT32_C(  -648.91), SIMDE_FLOAT32_C(  -541.18), SIMDE_FLOAT32_C(   198.88),
        SIMDE_FLOAT32_C(   155.05), SIMDE_FLOAT32_C(   -46.21), SIMDE_FLOAT32_C(   128.53), SIMDE_FLOAT32_C(   521.67),
        SIMDE_FLOAT32_C(   904.57), SIMDE_FLOAT32_C(   765.66), SIMDE_FLOAT32_C(   377.91), SIMDE_FLOAT32_C(  -755.13) } },
    { { SIMDE_FLOAT32_C(  -242.71), SIMDE_FLOAT32_C(  -643.16), SIMDE_FLOAT32_C(   329.07), SIMDE_FLOAT32_C(  -131.53),
        SIMDE_FLOAT32_C(   555.72), SIMDE_FLOAT32_C(  -515.88), SIMDE_FLOAT32_C(   822.26), SIMDE_FLOAT32_C(  -315.75),
        SIMDE_FLOAT32_C(  -994.20), SIMDE_FLOAT32_C(   726.83), SIMDE_FLOAT32_C(  -550.09), SIMDE_FLOAT32_C(   383.71),
        SIMDE_FLOAT32_C(   971.70), SIMDE_FLOAT32_C(    96.83), SIMDE_FLOAT32_C(   723.62), SIMDE_FLOAT32_C(  -187.12) },
      UINT16_C(57073),
      { SIMDE_FLOAT32_C(  -999.42), SIMDE_FLOAT32_C(  -402.30), SIMDE_FLOAT32_C(   -16.81), SIMDE_FLOAT32_C(   669.59),
        SIMDE_FLOAT32_C(  -359.66), SIMDE_FLOAT32_C(  -443.24), SIMDE_FLOAT32_C(   836.27), SIMDE_FLOAT32_C(   501.41),
        SIMDE_FLOAT32_C(   -92.15), SIMDE_FLOAT32_C(  -782.92), SIMDE_FLOAT32_C(   960.23), SIMDE_FLOAT32_C(  -633.62),
        SIMDE_FLOAT32_C(   480.24), SIMDE_FLOAT32_C(  -282.47), SIMDE_FLOAT32_C(  -276.78), SIMDE_FLOAT32_C(  -190.69) },
      { SIMDE_FLOAT32_C(  -999.42), SIMDE_FLOAT32_C(  -359.66), SIMDE_FLOAT32_C(  -443.24), SIMDE_FLOAT32_C(   836.27),
        SIMDE_FLOAT32_C(   501.41), SIMDE_FLOAT32_C(  -782.92), SIMDE_FLOAT32_C(   960.23), SIMDE_FLOAT32_C(  -633.62),
        SIMDE_FLOAT32_C(   480.24), SIMDE_FLOAT32_C(  -276.78), SIMDE_FLOAT32_C(  -190.69), SIMDE_FLOAT32_C(   383.71),
        SIMDE_FLOAT32_C(   971.70), SIMDE_FLOAT32_C(    96.83), SIMDE_FLOAT32_C(   723.62), SIMDE_FLOAT32_C(  -187.12) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_mask_compress_ps(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_mask_compress_ps(src, k, a);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compressstoreu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C(  181),
      { SIMDE_FLOAT32_C(   498.16), SIMDE_FLOAT32_C(   840.84), SIMDE_FLOAT32_C(   139.45), SIMDE_FLOAT32_C(   850.72),
        SIMDE_FLOAT32_C(  -890.54), SIMDE_FLOAT32_C(   117.00), SIMDE_FLOAT32_C(   345.16), SIMDE_FLOAT32_C(  -812.30),
        SIMDE_FLOAT32_C(   694.09), SIMDE_FLOAT32_C(  -301.68), SIMDE_FLOAT32_C(   711.66), SIMDE_FLOAT32_C(   609.38),
        SIMDE_FLOAT32_C(    58.31), SIMDE_FLOAT32_C(  -410.97), SIMDE_FLOAT32_C(  -468.67), SIMDE_FLOAT32_C(  -633.73) },
      { SIMDE_FLOAT32_C(   498.16), SIMDE_FLOAT32_C(   139.45), SIMDE_FLOAT32_C(  -890.54), SIMDE_FLOAT32_C(   117.00),
        SIMDE_FLOAT32_C(  -812.30), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(   66),
      { SIMDE_FLOAT32_C(  -885.01), SIMDE_FLOAT32_C(   582.30), SIMDE_FLOAT32_C(   239.69), SIMDE_FLOAT32_C(   144.25),
        SIMDE_FLOAT32_C(  -348.14), SIMDE_FLOAT32_C(    90.15), SIMDE_FLOAT32_C(   632.19), SIMDE_FLOAT32_C(   668.99),
        SIMDE_FLOAT32_C(   139.38), SIMDE_FLOAT32_C(   278.90), SIMDE_FLOAT32_C(  -654.00), SIMDE_FLOAT32_C(  -781.98),
        SIMDE_FLOAT32_C(  -787.74), SIMDE_FLOAT32_C(   747.91), SIMDE_FLOAT32_C(   716.18), SIMDE_FLOAT32_C(  -946.90) },
      { SIMDE_FLOAT32_C(   582.30), SIMDE_FLOAT32_C(   632.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(  109),
      { SIMDE_FLOAT32_C(   566.90), SIMDE_FLOAT32_C(  -837.44), SIMDE_FLOAT32_C(  -995.64), SIMDE_FLOAT32_C(   -87.94),
        SIMDE_FLOAT32_C(  -649.74), SIMDE_FLOAT32_C(   698.46), SIMDE_FLOAT32_C(   610.37), SIMDE_FLOAT32_C(  -938.08),
        SIMDE_FLOAT32_C(   307.84), SIMDE_FLOAT32_C(  -331.32), SIMDE_FLOAT32_C(  -349.06), SIMDE_FLOAT32_C(   839.16),
        SIMDE_FLOAT32_C(    34.95), SIMDE_FLOAT32_C(  -393.49), SIMDE_FLOAT32_C(   954.15), SIMDE_FLOAT32_C(  -382.75) },
      { SIMDE_FLOAT32_C(   566.90), SIMDE_FLOAT32_C(  -995.64), SIMDE_FLOAT32_C(   -87.94), SIMDE_FLOAT32_C(   698.46),
        SIMDE_FLOAT32_C(   610.37), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(  168),
      { SIMDE_FLOAT32_C(    98.40), SIMDE_FLOAT32_C(   269.11), SIMDE_FLOAT32_C(   -63.65), SIMDE_FLOAT32_C(  -269.40),
        SIMDE_FLOAT32_C(   -61.90), SIMDE_FLOAT32_C(  -924.27), SIMDE_FLOAT32_C(  -990.50), SIMDE_FLOAT32_C(   284.10),
        SIMDE_FLOAT32_C(  -706.25), SIMDE_FLOAT32_C(  -778.24), SIMDE_FLOAT32_C(    32.01), SIMDE_FLOAT32_C(  -990.07),
        SIMDE_FLOAT32_C(  -725.14), SIMDE_FLOAT32_C(   919.38), SIMDE_FLOAT32_C(   576.83), SIMDE_FLOAT32_C(  -562.58) },
      { SIMDE_FLOAT32_C(  -269.40), SIMDE_FLOAT32_C(  -924.27), SIMDE_FLOAT32_C(   284.10), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(    6),
      { SIMDE_FLOAT32_C(  -511.12), SIMDE_FLOAT32_C(  -212.32), SIMDE_FLOAT32_C(   622.20), SIMDE_FLOAT32_C(  -900.74),
        SIMDE_FLOAT32_C(  -150.40), SIMDE_FLOAT32_C(   -69.96), SIMDE_FLOAT32_C(  -232.06), SIMDE_FLOAT32_C(   500.54),
        SIMDE_FLOAT32_C(  -230.80), SIMDE_FLOAT32_C(   802.89), SIMDE_FLOAT32_C(  -892.95), SIMDE_FLOAT32_C(  -276.65),
        SIMDE_FLOAT32_C(  -579.87), SIMDE_FLOAT32_C(   953.25), SIMDE_FLOAT32_C(   821.76), SIMDE_FLOAT32_C(   689.24) },
      { SIMDE_FLOAT32_C(  -212.32), SIMDE_FLOAT32_C(   622.20), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(  222),
      { SIMDE_FLOAT32_C(  -447.65), SIMDE_FLOAT32_C(  -372.66), SIMDE_FLOAT32_C(   -34.68), SIMDE_FLOAT32_C(  -438.15),
        SIMDE_FLOAT32_C(   911.44), SIMDE_FLOAT32_C(   259.07), SIMDE_FLOAT32_C(  -216.39), SIMDE_FLOAT32_C(   -56.55),
        SIMDE_FLOAT32_C(   268.99), SIMDE_FLOAT32_C(    58.47), SIMDE_FLOAT32_C(  -137.17), SIMDE_FLOAT32_C(  -154.18),
        SIMDE_FLOAT32_C(   495.89), SIMDE_FLOAT32_C(  -213.42), SIMDE_FLOAT32_C(   334.70), SIMDE_FLOAT32_C(  -716.43) },
      { SIMDE_FLOAT32_C(  -372.66), SIMDE_FLOAT32_C(   -34.68), SIMDE_FLOAT32_C(  -438.15), SIMDE_FLOAT32_C(   911.44),
        SIMDE_FLOAT32_C(  -216.39), SIMDE_FLOAT32_C(   -56.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(  246),
      { SIMDE_FLOAT32_C(   433.96), SIMDE_FLOAT32_C(   133.17), SIMDE_FLOAT32_C(   338.81), SIMDE_FLOAT32_C(  -798.10),
        SIMDE_FLOAT32_C(  -366.29), SIMDE_FLOAT32_C(  -891.99), SIMDE_FLOAT32_C(  -995.22), SIMDE_FLOAT32_C(  -259.24),
        SIMDE_FLOAT32_C(  -168.63), SIMDE_FLOAT32_C(  -575.09), SIMDE_FLOAT32_C(  -306.00), SIMDE_FLOAT32_C(  -346.88),
        SIMDE_FLOAT32_C(  -885.84), SIMDE_FLOAT32_C(   583.60), SIMDE_FLOAT32_C(   205.47), SIMDE_FLOAT32_C(  -258.50) },
      { SIMDE_FLOAT32_C(   133.17), SIMDE_FLOAT32_C(   338.81), SIMDE_FLOAT32_C(  -366.29), SIMDE_FLOAT32_C(  -891.99),
        SIMDE_FLOAT32_C(  -995.22), SIMDE_FLOAT32_C(  -259.24), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(  180),
      { SIMDE_FLOAT32_C(   767.32), SIMDE_FLOAT32_C(  -347.06), SIMDE_FLOAT32_C(   807.98), SIMDE_FLOAT32_C(  -449.07),
        SIMDE_FLOAT32_C(   596.39), SIMDE_FLOAT32_C(    76.98), SIMDE_FLOAT32_C(   609.41), SIMDE_FLOAT32_C(  -540.77),
        SIMDE_FLOAT32_C(   922.80), SIMDE_FLOAT32_C(   105.30), SIMDE_FLOAT32_C(   245.80), SIMDE_FLOAT32_C(   257.50),
        SIMDE_FLOAT32_C(   388.87), SIMDE_FLOAT32_C(   654.58), SIMDE_FLOAT32_C(  -308.54), SIMDE_FLOAT32_C(  -477.96) },
      { SIMDE_FLOAT32_C(   807.98), SIMDE_FLOAT32_C(   596.39), SIMDE_FLOAT32_C(    76.98), SIMDE_FLOAT32_C(  -540.77),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_setzero_ps();
    simde_mm512_mask_compressstoreu_ps(&r, test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask8();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_setzero_ps();
    simde_mm512_mask_compressstoreu_ps(&r, k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_compress_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C(52249),
      { SIMDE_FLOAT32_C(   289.18), SIMDE_FLOAT32_C(   469.51), SIMDE_FLOAT32_C(  -663.54), SIMDE_FLOAT32_C(   283.51),
        SIMDE_FLOAT32_C(   710.78), SIMDE_FLOAT32_C(   831.64), SIMDE_FLOAT32_C(   592.35), SIMDE_FLOAT32_C(   -25.99),
        SIMDE_FLOAT32_C(  -994.70), SIMDE_FLOAT32_C(   507.63), SIMDE_FLOAT32_C(   310.84), SIMDE_FLOAT32_C(    72.09),
        SIMDE_FLOAT32_C(  -470.16), SIMDE_FLOAT32_C(   130.87), SIMDE_FLOAT32_C(   997.55), SIMDE_FLOAT32_C(   391.56) },
      { SIMDE_FLOAT32_C(   289.18), SIMDE_FLOAT32_C(   283.51), SIMDE_FLOAT32_C(   710.78), SIMDE_FLOAT32_C(   310.84),
        SIMDE_FLOAT32_C(    72.09), SIMDE_FLOAT32_C(   997.55), SIMDE_FLOAT32_C(   391.56), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(15461),
      { SIMDE_FLOAT32_C(   552.93), SIMDE_FLOAT32_C(   374.54), SIMDE_FLOAT32_C(   566.26), SIMDE_FLOAT32_C(   -67.60),
        SIMDE_FLOAT32_C(  -127.43), SIMDE_FLOAT32_C(   954.47), SIMDE_FLOAT32_C(  -694.02), SIMDE_FLOAT32_C(  -795.80),
        SIMDE_FLOAT32_C(   479.19), SIMDE_FLOAT32_C(  -309.51), SIMDE_FLOAT32_C(  -879.73), SIMDE_FLOAT32_C(   782.01),
        SIMDE_FLOAT32_C(  -728.57), SIMDE_FLOAT32_C(   409.44), SIMDE_FLOAT32_C(   251.51), SIMDE_FLOAT32_C(  -392.11) },
      { SIMDE_FLOAT32_C(   552.93), SIMDE_FLOAT32_C(   566.26), SIMDE_FLOAT32_C(   954.47), SIMDE_FLOAT32_C(  -694.02),
        SIMDE_FLOAT32_C(  -879.73), SIMDE_FLOAT32_C(   782.01), SIMDE_FLOAT32_C(  -728.57), SIMDE_FLOAT32_C(   409.44),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(27386),
      { SIMDE_FLOAT32_C(  -560.47), SIMDE_FLOAT32_C(  -714.70), SIMDE_FLOAT32_C(   936.31), SIMDE_FLOAT32_C(  -555.17),
        SIMDE_FLOAT32_C(   792.93), SIMDE_FLOAT32_C(   247.15), SIMDE_FLOAT32_C(   516.92), SIMDE_FLOAT32_C(  -677.23),
        SIMDE_FLOAT32_C(  -621.98), SIMDE_FLOAT32_C(   514.47), SIMDE_FLOAT32_C(   714.33), SIMDE_FLOAT32_C(  -325.09),
        SIMDE_FLOAT32_C(   723.96), SIMDE_FLOAT32_C(   267.26), SIMDE_FLOAT32_C(  -950.55), SIMDE_FLOAT32_C(   290.22) },
      { SIMDE_FLOAT32_C(  -714.70), SIMDE_FLOAT32_C(  -555.17), SIMDE_FLOAT32_C(   792.93), SIMDE_FLOAT32_C(   247.15),
        SIMDE_FLOAT32_C(   516.92), SIMDE_FLOAT32_C(  -677.23), SIMDE_FLOAT32_C(   514.47), SIMDE_FLOAT32_C(  -325.09),
        SIMDE_FLOAT32_C(   267.26), SIMDE_FLOAT32_C(  -950.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(64711),
      { SIMDE_FLOAT32_C(   244.69), SIMDE_FLOAT32_C(  -494.36), SIMDE_FLOAT32_C(   126.22), SIMDE_FLOAT32_C(  -276.12),
        SIMDE_FLOAT32_C(   196.13), SIMDE_FLOAT32_C(   246.48), SIMDE_FLOAT32_C(  -494.12), SIMDE_FLOAT32_C(   467.56),
        SIMDE_FLOAT32_C(  -344.08), SIMDE_FLOAT32_C(   757.40), SIMDE_FLOAT32_C(  -924.54), SIMDE_FLOAT32_C(   348.88),
        SIMDE_FLOAT32_C(  -280.30), SIMDE_FLOAT32_C(  -485.01), SIMDE_FLOAT32_C(   634.18), SIMDE_FLOAT32_C(  -343.99) },
      { SIMDE_FLOAT32_C(   244.69), SIMDE_FLOAT32_C(  -494.36), SIMDE_FLOAT32_C(   126.22), SIMDE_FLOAT32_C(  -494.12),
        SIMDE_FLOAT32_C(   467.56), SIMDE_FLOAT32_C(  -924.54), SIMDE_FLOAT32_C(   348.88), SIMDE_FLOAT32_C(  -280.30),
        SIMDE_FLOAT32_C(  -485.01), SIMDE_FLOAT32_C(   634.18), SIMDE_FLOAT32_C(  -343.99), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(26589),
      { SIMDE_FLOAT32_C(   903.16), SIMDE_FLOAT32_C(  -523.27), SIMDE_FLOAT32_C(   749.88), SIMDE_FLOAT32_C(  -718.82),
        SIMDE_FLOAT32_C(   991.20), SIMDE_FLOAT32_C(   464.21), SIMDE_FLOAT32_C(   -43.91), SIMDE_FLOAT32_C(   715.16),
        SIMDE_FLOAT32_C(  -268.53), SIMDE_FLOAT32_C(     5.54), SIMDE_FLOAT32_C(     5.38), SIMDE_FLOAT32_C(   -68.87),
        SIMDE_FLOAT32_C(   927.55), SIMDE_FLOAT32_C(  -749.93), SIMDE_FLOAT32_C(   436.76), SIMDE_FLOAT32_C(    53.77) },
      { SIMDE_FLOAT32_C(   903.16), SIMDE_FLOAT32_C(   749.88), SIMDE_FLOAT32_C(  -718.82), SIMDE_FLOAT32_C(   991.20),
        SIMDE_FLOAT32_C(   -43.91), SIMDE_FLOAT32_C(   715.16), SIMDE_FLOAT32_C(  -268.53), SIMDE_FLOAT32_C(     5.54),
        SIMDE_FLOAT32_C(     5.38), SIMDE_FLOAT32_C(  -749.93), SIMDE_FLOAT32_C(   436.76), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(11444),
      { SIMDE_FLOAT32_C(  -699.75), SIMDE_FLOAT32_C(   479.83), SIMDE_FLOAT32_C(  -899.54), SIMDE_FLOAT32_C(   -43.82),
        SIMDE_FLOAT32_C(   237.23), SIMDE_FLOAT32_C(  -824.09), SIMDE_FLOAT32_C(  -694.94), SIMDE_FLOAT32_C(   956.93),
        SIMDE_FLOAT32_C(  -309.10), SIMDE_FLOAT32_C(   939.24), SIMDE_FLOAT32_C(  -387.07), SIMDE_FLOAT32_C(   650.72),
        SIMDE_FLOAT32_C(   366.35), SIMDE_FLOAT32_C(  -483.91), SIMDE_FLOAT32_C(  -872.55), SIMDE_FLOAT32_C(   116.23) },
      { SIMDE_FLOAT32_C(  -899.54), SIMDE_FLOAT32_C(   237.23), SIMDE_FLOAT32_C(  -824.09), SIMDE_FLOAT32_C(   956.93),
        SIMDE_FLOAT32_C(  -387.07), SIMDE_FLOAT32_C(   650.72), SIMDE_FLOAT32_C(  -483.91), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(11021),
      { SIMDE_FLOAT32_C(  -419.56), SIMDE_FLOAT32_C(   753.36), SIMDE_FLOAT32_C(   833.82), SIMDE_FLOAT32_C(   311.91),
        SIMDE_FLOAT32_C(  -241.10), SIMDE_FLOAT32_C(  -160.80), SIMDE_FLOAT32_C(  -756.97), SIMDE_FLOAT32_C(  -313.55),
        SIMDE_FLOAT32_C(    89.27), SIMDE_FLOAT32_C(   679.80), SIMDE_FLOAT32_C(   740.22), SIMDE_FLOAT32_C(  -936.78),
        SIMDE_FLOAT32_C(  -687.31), SIMDE_FLOAT32_C(  -959.53), SIMDE_FLOAT32_C(   543.05), SIMDE_FLOAT32_C(  -586.85) },
      { SIMDE_FLOAT32_C(  -419.56), SIMDE_FLOAT32_C(   833.82), SIMDE_FLOAT32_C(   311.91), SIMDE_FLOAT32_C(    89.27),
        SIMDE_FLOAT32_C(   679.80), SIMDE_FLOAT32_C(  -936.78), SIMDE_FLOAT32_C(  -959.53), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(59788),
      { SIMDE_FLOAT32_C(  -410.94), SIMDE_FLOAT32_C(   301.71), SIMDE_FLOAT32_C(  -262.79), SIMDE_FLOAT32_C(   279.97),
        SIMDE_FLOAT32_C(   240.94), SIMDE_FLOAT32_C(   350.15), SIMDE_FLOAT32_C(   -69.32), SIMDE_FLOAT32_C(  -392.71),
        SIMDE_FLOAT32_C(   866.24), SIMDE_FLOAT32_C(    58.13), SIMDE_FLOAT32_C(   723.51), SIMDE_FLOAT32_C(  -336.49),
        SIMDE_FLOAT32_C(   176.79), SIMDE_FLOAT32_C(  -696.05), SIMDE_FLOAT32_C(  -583.13), SIMDE_FLOAT32_C(    10.60) },
      { SIMDE_FLOAT32_C(  -262.79), SIMDE_FLOAT32_C(   279.97), SIMDE_FLOAT32_C(  -392.71), SIMDE_FLOAT32_C(   866.24),
        SIMDE_FLOAT32_C(  -336.49), SIMDE_FLOAT32_C(  -696.05), SIMDE_FLOAT32_C(  -583.13), SIMDE_FLOAT32_C(    10.60),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_maskz_compress_ps(test_vec[i].k, a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_maskz_compress_ps(k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compressstoreu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(3294332254),
      {  INT16_C(  3308),  INT16_C(  3388), -INT16_C(  5688),  INT16_C( 20582),  INT16_C( 20128),  INT16_C( 12949),  INT16_C( 31670), -INT16_C( 19522),
         INT16_C(  4048), -INT16_C( 31842), -INT16_C(  1740), -INT16_C( 30794),  INT16_C(  1097), -INT16_C( 22667), -INT16_C( 12151),  INT16_C( 30060),
        -INT16_C( 22308), -INT16_C( 23422), -INT16_C(  5742),  INT16_C( 13044), -INT16_C( 30409), -INT16_C(  4508),  INT16_C(  8708), -INT16_C( 11103),
         INT16_C( 16177),  INT16_C( 25943),  INT16_C(  3640), -INT16_C( 32020),  INT16_C( 24850), -INT16_C( 25815), -INT16_C( 27343),  INT16_C(  3344) },
      {  INT16_C(  3388), -INT16_C(  5688),  INT16_C( 20582),  INT16_C( 20128),  INT16_C( 31670),  INT16_C(  4048), -INT16_C(  1740),  INT16_C( 30060),
        -INT16_C( 22308), -INT16_C( 23422),  INT16_C( 13044), -INT16_C( 30409),  INT16_C(  8708),  INT16_C(  3640), -INT16_C( 27343),  INT16_C(  3344),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(3501298238),
      { -INT16_C( 22917), -INT16_C( 19710),  INT16_C( 26159),  INT16_C( 13473),  INT16_C( 17032), -INT16_C( 18168),  INT16_C( 24705), -INT16_C( 17890),
         INT16_C(  2926), -INT16_C( 32708),  INT16_C( 25964), -INT16_C( 25061),  INT16_C( 11259),  INT16_C( 14763),  INT16_C( 23997),  INT16_C( 14601),
         INT16_C(  2819),  INT16_C( 13036), -INT16_C( 29327), -INT16_C(  1690),  INT16_C( 28623),  INT16_C( 20658), -INT16_C( 12081),  INT16_C( 15626),
         INT16_C( 18139),  INT16_C( 18621), -INT16_C( 10068), -INT16_C( 22554), -INT16_C( 28413), -INT16_C( 16160), -INT16_C(  5650), -INT16_C(  3591) },
      { -INT16_C( 19710),  INT16_C( 26159),  INT16_C( 13473),  INT16_C( 17032), -INT16_C( 18168), -INT16_C( 32708),  INT16_C( 11259),  INT16_C( 14601),
         INT16_C(  2819),  INT16_C( 28623),  INT16_C( 20658),  INT16_C( 15626), -INT16_C( 28413), -INT16_C(  5650), -INT16_C(  3591),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1696916980),
      { -INT16_C( 30094),  INT16_C( 16734),  INT16_C(  4345), -INT16_C( 14190), -INT16_C( 25376), -INT16_C( 17403), -INT16_C( 15645), -INT16_C( 28924),
        -INT16_C(  5478), -INT16_C( 25290),  INT16_C(  5755),  INT16_C( 27230),  INT16_C( 22527), -INT16_C(  3237),  INT16_C( 32573), -INT16_C( 20648),
        -INT16_C( 18934),  INT16_C(  1009), -INT16_C( 31802), -INT16_C( 22836), -INT16_C( 12001),  INT16_C(   610),  INT16_C( 26260),  INT16_C( 11921),
        -INT16_C( 14512), -INT16_C( 13108),  INT16_C( 10973), -INT16_C(  9162), -INT16_C( 28287), -INT16_C( 16689),  INT16_C( 10001),  INT16_C(  7022) },
      {  INT16_C(  4345), -INT16_C( 25376), -INT16_C( 17403), -INT16_C( 15645), -INT16_C( 28924), -INT16_C(  5478),  INT16_C(  5755), -INT16_C(  3237),
         INT16_C( 32573), -INT16_C( 20648), -INT16_C( 31802),  INT16_C(   610), -INT16_C( 14512),  INT16_C( 10973), -INT16_C( 16689),  INT16_C( 10001),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(2736676829),
      { -INT16_C(  5406),  INT16_C(   330), -INT16_C( 21316),  INT16_C( 20484), -INT16_C( 27373),  INT16_C( 25470),  INT16_C( 19037),  INT16_C( 14895),
         INT16_C( 25972), -INT16_C(  2537), -INT16_C(  6409),  INT16_C(  2228),  INT16_C(  8718), -INT16_C(  5341),  INT16_C( 16769),  INT16_C( 25487),
        -INT16_C(  9940), -INT16_C(  6043),  INT16_C( 27013), -INT16_C( 26568), -INT16_C( 18690),  INT16_C( 23548),  INT16_C( 11009),  INT16_C( 30102),
        -INT16_C( 21103), -INT16_C( 30613),  INT16_C(  8339), -INT16_C( 24176), -INT16_C( 19646), -INT16_C( 15219),  INT16_C(  7412),  INT16_C(  8231) },
      { -INT16_C(  5406), -INT16_C( 21316),  INT16_C( 20484), -INT16_C( 27373),  INT16_C( 19037),  INT16_C( 14895),  INT16_C( 25972), -INT16_C(  2537),
        -INT16_C(  6409),  INT16_C(  2228),  INT16_C(  8718),  INT16_C( 16769), -INT16_C(  6043),  INT16_C( 27013), -INT16_C( 26568), -INT16_C( 18690),
        -INT16_C( 21103), -INT16_C( 30613), -INT16_C( 15219),  INT16_C(  8231),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(2047380725),
      {  INT16_C( 16629), -INT16_C(  3053),  INT16_C(  4087), -INT16_C(  1969), -INT16_C(  6854), -INT16_C( 13459), -INT16_C(  9838),  INT16_C(  9811),
        -INT16_C(  7175),  INT16_C( 15303),  INT16_C( 21654), -INT16_C( 29697),  INT16_C( 10096),  INT16_C( 26027), -INT16_C( 19277), -INT16_C( 22048),
        -INT16_C(  3084), -INT16_C(  5219), -INT16_C(  5118),  INT16_C( 15587),  INT16_C( 20946),  INT16_C( 25608),  INT16_C( 23338),  INT16_C(  9098),
         INT16_C( 21055), -INT16_C( 10914),  INT16_C( 24230),  INT16_C(  5984),  INT16_C(  3205),  INT16_C( 14460),  INT16_C( 23744), -INT16_C( 19231) },
      {  INT16_C( 16629),  INT16_C(  4087), -INT16_C(  6854), -INT16_C( 13459), -INT16_C(  9838),  INT16_C(  9811),  INT16_C( 21654), -INT16_C( 29697),
        -INT16_C( 22048),  INT16_C( 15587), -INT16_C( 10914),  INT16_C(  5984),  INT16_C(  3205),  INT16_C( 14460),  INT16_C( 23744),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1369472591),
      { -INT16_C( 31893),  INT16_C( 15758), -INT16_C( 26924), -INT16_C(   351),  INT16_C( 11505),  INT16_C( 12321), -INT16_C( 32642),  INT16_C(  9222),
         INT16_C( 26334),  INT16_C( 25403), -INT16_C( 18318),  INT16_C( 12955),  INT16_C( 32020),  INT16_C( 25831), -INT16_C( 30725),  INT16_C( 26293),
         INT16_C( 17162), -INT16_C(  8285),  INT16_C( 17881), -INT16_C( 13347), -INT16_C(   143), -INT16_C(  4101),  INT16_C(   383),  INT16_C( 23827),
         INT16_C( 20328), -INT16_C(  9536),  INT16_C( 23303),  INT16_C(  6925), -INT16_C(  2856), -INT16_C( 11137),  INT16_C( 13691), -INT16_C( 31430) },
      { -INT16_C( 31893),  INT16_C( 15758), -INT16_C( 26924), -INT16_C(   351), -INT16_C( 32642),  INT16_C( 25403), -INT16_C( 18318),  INT16_C( 12955),
         INT16_C( 32020),  INT16_C( 25831), -INT16_C( 30725), -INT16_C(  4101),  INT16_C( 23827),  INT16_C( 20328), -INT16_C(  2856),  INT16_C( 13691),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1382342264),
      {  INT16_C( 16931), -INT16_C( 27619),  INT16_C(  6209), -INT16_C( 16253), -INT16_C( 27110), -INT16_C( 32227), -INT16_C(  8731), -INT16_C(  5028),
         INT16_C( 26936),  INT16_C(  4360), -INT16_C( 30883), -INT16_C( 10011),  INT16_C(  8124),  INT16_C( 13662), -INT16_C( 15619),  INT16_C(  8327),
        -INT16_C( 23548),  INT16_C( 17844),  INT16_C( 14268), -INT16_C( 10747),  INT16_C(  8910), -INT16_C( 19624), -INT16_C( 18945),  INT16_C( 14496),
        -INT16_C( 22498),  INT16_C( 31817),  INT16_C( 11823), -INT16_C(  5036), -INT16_C( 19891),  INT16_C( 19233), -INT16_C( 22411),  INT16_C( 31083) },
      { -INT16_C( 16253), -INT16_C( 27110), -INT16_C( 32227), -INT16_C(  8731),  INT16_C(  4360), -INT16_C( 30883), -INT16_C( 10011),  INT16_C(  8124),
        -INT16_C( 15619),  INT16_C(  8327),  INT16_C( 14268), -INT16_C( 19624), -INT16_C( 18945),  INT16_C( 31817), -INT16_C( 19891), -INT16_C( 22411),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C( 146743372),
      { -INT16_C( 15273),  INT16_C(  9695),  INT16_C( 14311), -INT16_C(  6439),  INT16_C( 31212),  INT16_C(  2846),  INT16_C( 26401),  INT16_C( 20615),
        -INT16_C(  9323), -INT16_C(  7364),  INT16_C( 23950),  INT16_C(   814), -INT16_C( 26363),  INT16_C( 20860),  INT16_C( 15289),  INT16_C(  4442),
         INT16_C( 14592), -INT16_C(  6346),  INT16_C(  3952),  INT16_C( 24013), -INT16_C(  4984), -INT16_C( 22168), -INT16_C(  4269), -INT16_C(  5638),
         INT16_C( 14026),  INT16_C( 22732), -INT16_C(  1388), -INT16_C( 26277), -INT16_C( 10093),  INT16_C( 19947),  INT16_C( 17683),  INT16_C(  4958) },
      {  INT16_C( 14311), -INT16_C(  6439),  INT16_C( 26401),  INT16_C( 20860),  INT16_C( 14592), -INT16_C(  6346),  INT16_C(  3952),  INT16_C( 24013),
        -INT16_C(  4984), -INT16_C( 22168), -INT16_C(  5638), -INT16_C( 26277),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_setzero_si512();
    simde_mm512_mask_compressstoreu_epi16(&r, test_vec[i].k, a);
    simde_assert_m512i_i16(r, ==, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_setzero_si512();
    simde_mm512_mask_compressstoreu_epi16(&r, k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compress_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  1535523698),  INT32_C(  1203263158), -INT32_C(  1696923993),  INT32_C(  1386006227), -INT32_C(   641092084), -INT32_C(  1924624932),  INT32_C(  1198967697),  INT32_C(  1951062530),
        -INT32_C(   858796010), -INT32_C(   854292442),  INT32_C(  1500049030), -INT32_C(  1045756748), -INT32_C(  1751485254), -INT32_C(  1843076607), -INT32_C(  1327916370), -INT32_C(  1960565643) },
      UINT16_C(62708),
      {  INT32_C(  1803295575),  INT32_C(  1348076264),  INT32_C(   123014747),  INT32_C(  1769672655), -INT32_C(   900956762), -INT32_C(   379192817), -INT32_C(   837952854), -INT32_C(  1128136347),
         INT32_C(    86523420), -INT32_C(  1672117696),  INT32_C(  1621338768),  INT32_C(  1623793338), -INT32_C(  1423239781), -INT32_C(  1181446129), -INT32_C(   813129366), -INT32_C(  1081390430) },
      {  INT32_C(   123014747), -INT32_C(   900956762), -INT32_C(   379192817), -INT32_C(   837952854), -INT32_C(  1128136347),  INT32_C(  1621338768), -INT32_C(  1423239781), -INT32_C(  1181446129),
        -INT32_C(   813129366), -INT32_C(  1081390430),  INT32_C(  1500049030), -INT32_C(  1045756748), -INT32_C(  1751485254), -INT32_C(  1843076607), -INT32_C(  1327916370), -INT32_C(  1960565643) } },
    { { -INT32_C(   909855863), -INT32_C(   966452939),  INT32_C(  2116421828), -INT32_C(  1025577177),  INT32_C(   342690053),  INT32_C(    63832473),  INT32_C(  1171412642),  INT32_C(   688152224),
         INT32_C(  1207158801), -INT32_C(  1525851935), -INT32_C(  2010959007),  INT32_C(   659161634), -INT32_C(  1522747381),  INT32_C(  1554516665),  INT32_C(    10582880), -INT32_C(   366303783) },
      UINT16_C( 7533),
      {  INT32_C(  1047875121),  INT32_C(   393336564), -INT32_C(  1457941410), -INT32_C(   144628293),  INT32_C(  1912675018),  INT32_C(   401432950), -INT32_C(  1933785502), -INT32_C(   492230223),
         INT32_C(  1814109816),  INT32_C(  1401131765), -INT32_C(   486761178), -INT32_C(  1931911742), -INT32_C(   285287560), -INT32_C(  1643713476),  INT32_C(  1663746738),  INT32_C(  1682363372) },
      {  INT32_C(  1047875121), -INT32_C(  1457941410), -INT32_C(   144628293),  INT32_C(   401432950), -INT32_C(  1933785502),  INT32_C(  1814109816), -INT32_C(   486761178), -INT32_C(  1931911742),
        -INT32_C(   285287560), -INT32_C(  1525851935), -INT32_C(  2010959007),  INT32_C(   659161634), -INT32_C(  1522747381),  INT32_C(  1554516665),  INT32_C(    10582880), -INT32_C(   366303783) } },
    { { -INT32_C(   405772302),  INT32_C(   540693497), -INT32_C(  1308477456),  INT32_C(   205446036), -INT32_C(   201638474), -INT32_C(   611253975), -INT32_C(  1354777405), -INT32_C(  2129427057),
        -INT32_C(   446110740),  INT32_C(   654680887),  INT32_C(  1859782618), -INT32_C(  1719985949),  INT32_C(  2123134549),  INT32_C(   978984567),  INT32_C(  1776982490),  INT32_C(   183237918) },
      UINT16_C(21473),
      { -INT32_C(   168421137),  INT32_C(   435998783), -INT32_C(  1171071169),  INT32_C(    87066489),  INT32_C(  1612949254), -INT32_C(   872808991),  INT32_C(  1388910439),  INT32_C(   279292449),
         INT32_C(    17145026), -INT32_C(  1424293268),  INT32_C(  1516588513), -INT32_C(   631204396),  INT32_C(   507151164), -INT32_C(   387370111),  INT32_C(  1799008842),  INT32_C(   511500124) },
      { -INT32_C(   168421137), -INT32_C(   872808991),  INT32_C(  1388910439),  INT32_C(   279292449),  INT32_C(    17145026), -INT32_C(  1424293268),  INT32_C(   507151164),  INT32_C(  1799008842),
        -INT32_C(   446110740),  INT32_C(   654680887),  INT32_C(  1859782618), -INT32_C(  1719985949),  INT32_C(  2123134549),  INT32_C(   978984567),  INT32_C(  1776982490),  INT32_C(   183237918) } },
    { { -INT32_C(   400522885),  INT32_C(  1704147843),  INT32_C(  1556085128), -INT32_C(   885579890),  INT32_C(   619278755), -INT32_C(   284372315), -INT32_C(   514111867), -INT32_C(  1593780443),
        -INT32_C(   594993064), -INT32_C(   482272165), -INT32_C(  1539375083), -INT32_C(  1016105440), -INT32_C(  1914218264), -INT32_C(  1350765782),  INT32_C(  1586616121),  INT32_C(   134189486) },
      UINT16_C(34993),
      {  INT32_C(   614796515),  INT32_C(   774159087), -INT32_C(   844807074), -INT32_C(   299528953), -INT32_C(  1763618790), -INT32_C(  1871832321),  INT32_C(  2015435897),  INT32_C(   100782627),
        -INT32_C(   852842786), -INT32_C(  1073983648), -INT32_C(  1685282413),  INT32_C(  1216983598),  INT32_C(    31353602), -INT32_C(    23966587), -INT32_C(  1938312343),  INT32_C(  1687386246) },
      {  INT32_C(   614796515), -INT32_C(  1763618790), -INT32_C(  1871832321),  INT32_C(   100782627),  INT32_C(  1216983598),  INT32_C(  1687386246), -INT32_C(   514111867), -INT32_C(  1593780443),
        -INT32_C(   594993064), -INT32_C(   482272165), -INT32_C(  1539375083), -INT32_C(  1016105440), -INT32_C(  1914218264), -INT32_C(  1350765782),  INT32_C(  1586616121),  INT32_C(   134189486) } },
    { {  INT32_C(  2117254430), -INT32_C(  1606603252), -INT32_C(    46413105),  INT32_C(  2118501500), -INT32_C(  1249959121), -INT32_C(   642576016),  INT32_C(  1264921285), -INT32_C(  1062209374),
        -INT32_C(  1036000842), -INT32_C(   563971057), -INT32_C(  1025794746), -INT32_C(  1858068382), -INT32_C(  1270431676), -INT32_C(  1769080111), -INT32_C(   941493724), -INT32_C(  1584950805) },
      UINT16_C(50802),
      { -INT32_C(   968654237),  INT32_C(  1013156192), -INT32_C(  1940077236), -INT32_C(  1655922601), -INT32_C(   510189996), -INT32_C(  1764442956),  INT32_C(   170377091), -INT32_C(  1009673888),
         INT32_C(  2089358363), -INT32_C(   373756515),  INT32_C(   158733490),  INT32_C(   161989301), -INT32_C(  1779745056),  INT32_C(  2100019194), -INT32_C(   561491330),  INT32_C(   128014827) },
      {  INT32_C(  1013156192), -INT32_C(   510189996), -INT32_C(  1764442956),  INT32_C(   170377091), -INT32_C(   373756515),  INT32_C(   158733490), -INT32_C(   561491330),  INT32_C(   128014827),
        -INT32_C(  1036000842), -INT32_C(   563971057), -INT32_C(  1025794746), -INT32_C(  1858068382), -INT32_C(  1270431676), -INT32_C(  1769080111), -INT32_C(   941493724), -INT32_C(  1584950805) } },
    { {  INT32_C(   176368493), -INT32_C(   889963752),  INT32_C(    81029711),  INT32_C(   219052844), -INT32_C(  1264387655),  INT32_C(   909233592),  INT32_C(   169130271),  INT32_C(  2131866898),
        -INT32_C(   125135648),  INT32_C(   532905679),  INT32_C(   337876968), -INT32_C(   887017198), -INT32_C(   494943446), -INT32_C(  1357336176),  INT32_C(  2109353066), -INT32_C(  1023620126) },
      UINT16_C(34400),
      {  INT32_C(  2114203579),  INT32_C(  1914039374),  INT32_C(   581117697),  INT32_C(  1927728882), -INT32_C(   920422736), -INT32_C(   520778458),  INT32_C(   128702218),  INT32_C(  1435306906),
        -INT32_C(  1982623173),  INT32_C(  2147215486),  INT32_C(    27434767),  INT32_C(   494110829),  INT32_C(   619091710),  INT32_C(   772070436),  INT32_C(  1295364275), -INT32_C(   157105221) },
      { -INT32_C(   520778458),  INT32_C(   128702218),  INT32_C(  2147215486),  INT32_C(    27434767), -INT32_C(   157105221),  INT32_C(   909233592),  INT32_C(   169130271),  INT32_C(  2131866898),
        -INT32_C(   125135648),  INT32_C(   532905679),  INT32_C(   337876968), -INT32_C(   887017198), -INT32_C(   494943446), -INT32_C(  1357336176),  INT32_C(  2109353066), -INT32_C(  1023620126) } },
    { { -INT32_C(   746556075),  INT32_C(  1817410397), -INT32_C(  2022771430),  INT32_C(  2074468733), -INT32_C(  1667200136),  INT32_C(   466265191),  INT32_C(   275251284),  INT32_C(   403049411),
        -INT32_C(   554989952),  INT32_C(   474627586), -INT32_C(  1331382221),  INT32_C(   304892314),  INT32_C(  1018088660), -INT32_C(   984123280),  INT32_C(  1003863928),  INT32_C(  1263786954) },
      UINT16_C(16226),
      {  INT32_C(  1937597481),  INT32_C(   606908800), -INT32_C(  1922185631), -INT32_C(  2040970536), -INT32_C(   704722306),  INT32_C(  1687451535),  INT32_C(   104816562), -INT32_C(   750411350),
        -INT32_C(  2042183163), -INT32_C(   710249869),  INT32_C(   274864184), -INT32_C(   661210022),  INT32_C(   363697542), -INT32_C(  1099349748),  INT32_C(  1254406304),  INT32_C(  1595738458) },
      {  INT32_C(   606908800),  INT32_C(  1687451535),  INT32_C(   104816562), -INT32_C(  2042183163), -INT32_C(   710249869),  INT32_C(   274864184), -INT32_C(   661210022),  INT32_C(   363697542),
        -INT32_C(  1099349748),  INT32_C(   474627586), -INT32_C(  1331382221),  INT32_C(   304892314),  INT32_C(  1018088660), -INT32_C(   984123280),  INT32_C(  1003863928),  INT32_C(  1263786954) } },
    { {  INT32_C(  1071998156),  INT32_C(   253006038),  INT32_C(    35616680), -INT32_C(  1176848845),  INT32_C(  1473152843),  INT32_C(  1763002312),  INT32_C(  1504959231), -INT32_C(  1346776605),
         INT32_C(   200252981), -INT32_C(   702938322), -INT32_C(  1378338182),  INT32_C(   996586224),  INT32_C(    43136057),  INT32_C(  2070652795),  INT32_C(  1708400257),  INT32_C(   605326831) },
      UINT16_C(  812),
      {  INT32_C(  1241995824),  INT32_C(   159678769), -INT32_C(  1782811601),  INT32_C(  1103820207),  INT32_C(  1659454967), -INT32_C(  1786680640), -INT32_C(   467504945), -INT32_C(   974696811),
        -INT32_C(   636490071), -INT32_C(  1612475280), -INT32_C(  1204510968), -INT32_C(  1929773419),  INT32_C(    82829892),  INT32_C(   479817805),  INT32_C(  1962982624), -INT32_C(  1287985142) },
      { -INT32_C(  1782811601),  INT32_C(  1103820207), -INT32_C(  1786680640), -INT32_C(   636490071), -INT32_C(  1612475280),  INT32_C(  1763002312),  INT32_C(  1504959231), -INT32_C(  1346776605),
         INT32_C(   200252981), -INT32_C(   702938322), -INT32_C(  1378338182),  INT32_C(   996586224),  INT32_C(    43136057),  INT32_C(  2070652795),  INT32_C(  1708400257),  INT32_C(   605326831) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_compress_epi32(src, test_vec[i].k, a);
    simde_assert_m512i_i32(r, ==, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_mask_compress_epi32(src, k, a);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compressstoreu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C( 2633),
      { -INT32_C(  1286591627),  INT32_C(   944668175), -INT32_C(  1741530641), -INT32_C(  1438426263),  INT32_C(   338501723), -INT32_C(   875174946),  INT32_C(   461872452),  INT32_C(   321310878),
         INT32_C(   180844283), -INT32_C(   482142732), -INT32_C(   679709330),  INT32_C(   746700752), -INT32_C(  1103057184), -INT32_C(   695658862),  INT32_C(  1374818483), -INT32_C(   597354272) },
      { -INT32_C(  1286591627), -INT32_C(  1438426263),  INT32_C(   461872452), -INT32_C(   482142732),  INT32_C(   746700752),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(11406),
      {  INT32_C(   692159206), -INT32_C(   509694107),  INT32_C(   128020358), -INT32_C(   608796261), -INT32_C(   906934209),  INT32_C(   282699038),  INT32_C(  1529395958),  INT32_C(  2089268886),
        -INT32_C(  1633236936), -INT32_C(    41991049),  INT32_C(  1308958899), -INT32_C(   517293151),  INT32_C(   564796163), -INT32_C(  1221426240), -INT32_C(   753771971),  INT32_C(  1230019089) },
      { -INT32_C(   509694107),  INT32_C(   128020358), -INT32_C(   608796261),  INT32_C(  2089268886),  INT32_C(  1308958899), -INT32_C(   517293151), -INT32_C(  1221426240),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(63074),
      {  INT32_C(  1731910375), -INT32_C(   595071273),  INT32_C(  1721182524), -INT32_C(  1266509302), -INT32_C(   298368324),  INT32_C(   206075385), -INT32_C(  1733928632), -INT32_C(  1970403165),
        -INT32_C(  1158559262), -INT32_C(   208242249), -INT32_C(  1403375966), -INT32_C(  2074026808),  INT32_C(   410162974),  INT32_C(  1428470540), -INT32_C(  1209153004), -INT32_C(  1253933870) },
      { -INT32_C(   595071273),  INT32_C(   206075385), -INT32_C(  1733928632), -INT32_C(   208242249), -INT32_C(  1403375966),  INT32_C(   410162974),  INT32_C(  1428470540), -INT32_C(  1209153004),
        -INT32_C(  1253933870),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(13125),
      {  INT32_C(    95222895),  INT32_C(  1228099311),  INT32_C(  1512439034), -INT32_C(   202226560), -INT32_C(  2136015268),  INT32_C(  1095418451), -INT32_C(  1128457094),  INT32_C(  1089405649),
        -INT32_C(   314139394), -INT32_C(   449349142), -INT32_C(   163619723), -INT32_C(    51826272), -INT32_C(  2088986832), -INT32_C(   742078887), -INT32_C(  1265663517), -INT32_C(  2114617469) },
      {  INT32_C(    95222895),  INT32_C(  1512439034), -INT32_C(  1128457094), -INT32_C(   314139394), -INT32_C(   449349142), -INT32_C(  2088986832), -INT32_C(   742078887),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(15131),
      { -INT32_C(  1498151569),  INT32_C(   704785130),  INT32_C(   157000480),  INT32_C(   480283551), -INT32_C(   740099825),  INT32_C(  1549125069),  INT32_C(  1876678778), -INT32_C(   911542694),
        -INT32_C(   428908804), -INT32_C(  1475317368), -INT32_C(  1263440876),  INT32_C(   114315767),  INT32_C(   416985675), -INT32_C(   227266696),  INT32_C(  1633767431),  INT32_C(  1110051654) },
      { -INT32_C(  1498151569),  INT32_C(   704785130),  INT32_C(   480283551), -INT32_C(   740099825), -INT32_C(   428908804), -INT32_C(  1475317368),  INT32_C(   114315767),  INT32_C(   416985675),
        -INT32_C(   227266696),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(39273),
      {  INT32_C(   957084201),  INT32_C(  1285889946), -INT32_C(  1549951533),  INT32_C(  2102847651),  INT32_C(  1974259200),  INT32_C(   566604992),  INT32_C(  1076628245),  INT32_C(  2010748238),
         INT32_C(   582018183), -INT32_C(   680634876), -INT32_C(  1770320909), -INT32_C(   199962124),  INT32_C(  1600766111), -INT32_C(  1971310988), -INT32_C(  1999983558), -INT32_C(   905993407) },
      {  INT32_C(   957084201),  INT32_C(  2102847651),  INT32_C(   566604992),  INT32_C(  1076628245),  INT32_C(   582018183), -INT32_C(   199962124),  INT32_C(  1600766111), -INT32_C(   905993407),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(44936),
      {  INT32_C(  1493535979), -INT32_C(   563808157), -INT32_C(  1548789617), -INT32_C(  1235005875),  INT32_C(   770037933),  INT32_C(   752426850), -INT32_C(  1496376409), -INT32_C(   816490524),
         INT32_C(  1193827299), -INT32_C(   500855725),  INT32_C(   847631845), -INT32_C(   773265117),  INT32_C(   603901377), -INT32_C(  1823483668), -INT32_C(   684122381),  INT32_C(  1504087926) },
      { -INT32_C(  1235005875), -INT32_C(   816490524),  INT32_C(  1193827299), -INT32_C(   500855725),  INT32_C(   847631845), -INT32_C(   773265117), -INT32_C(  1823483668),  INT32_C(  1504087926),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(52970),
      { -INT32_C(   967164512), -INT32_C(  1516552416),  INT32_C(  1519304305), -INT32_C(  1910026353), -INT32_C(  1050274702), -INT32_C(   505390681), -INT32_C(   697280976),  INT32_C(  1352948399),
        -INT32_C(  1223229801), -INT32_C(  1352814274), -INT32_C(    16127121), -INT32_C(  1383255749), -INT32_C(   328207547),  INT32_C(  2093829964),  INT32_C(  1414675877),  INT32_C(   799340183) },
      { -INT32_C(  1516552416), -INT32_C(  1910026353), -INT32_C(   505390681), -INT32_C(   697280976),  INT32_C(  1352948399), -INT32_C(  1352814274), -INT32_C(    16127121), -INT32_C(  1383255749),
         INT32_C(  1414675877),  INT32_C(   799340183),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_setzero_si512();
    simde_mm512_mask_compressstoreu_epi32(&r, test_vec[i].k, a);
    simde_assert_m512i_i32(r, ==, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_setzero_si512();
    simde_mm512_mask_compressstoreu_epi32(&r, k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_compress_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(12755),
      {  INT32_C(   307496291),  INT32_C(  2104745105),  INT32_C(   848181261),  INT32_C(   336392925),  INT32_C(   333495349), -INT32_C(  1553727522),  INT32_C(  2118242508), -INT32_C(  1985014746),
        -INT32_C(  1415838695), -INT32_C(   299364384),  INT32_C(   622900808), -INT32_C(   566678359), -INT32_C(   957277720), -INT32_C(   446082023),  INT32_C(  1248045860), -INT32_C(   640412993) },
      {  INT32_C(   307496291),  INT32_C(  2104745105),  INT32_C(   333495349),  INT32_C(  2118242508), -INT32_C(  1985014746), -INT32_C(  1415838695), -INT32_C(   957277720), -INT32_C(   446082023),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(28694),
      { -INT32_C(  1400899708),  INT32_C(    90425317),  INT32_C(   640748780), -INT32_C(   616621590),  INT32_C(  1227839712), -INT32_C(  1594600643),  INT32_C(  1907602589),  INT32_C(   300009869),
        -INT32_C(  1514315328),  INT32_C(   363470888),  INT32_C(   373021484), -INT32_C(   705594635),  INT32_C(   270409939),  INT32_C(   296817523),  INT32_C(  1417831623), -INT32_C(   295345107) },
      {  INT32_C(    90425317),  INT32_C(   640748780),  INT32_C(  1227839712),  INT32_C(   270409939),  INT32_C(   296817523),  INT32_C(  1417831623),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C( 8901),
      {  INT32_C(  1044639123),  INT32_C(  1025076994),  INT32_C(  2008551046),  INT32_C(    43551715),  INT32_C(  1276447643), -INT32_C(  1615799268), -INT32_C(  1794908624),  INT32_C(  1605880012),
        -INT32_C(  1197606219), -INT32_C(   252332182), -INT32_C(  1452823099), -INT32_C(   726925512),  INT32_C(   656457739), -INT32_C(   859385444),  INT32_C(  2070006191),  INT32_C(  1205475473) },
      {  INT32_C(  1044639123),  INT32_C(  2008551046), -INT32_C(  1794908624),  INT32_C(  1605880012), -INT32_C(   252332182), -INT32_C(   859385444),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(30739),
      { -INT32_C(   198214145), -INT32_C(   727518099),  INT32_C(  1221909149), -INT32_C(   821502034), -INT32_C(   845110266), -INT32_C(   778678416), -INT32_C(  1528158006),  INT32_C(  1847393647),
        -INT32_C(   412988550), -INT32_C(   574946240), -INT32_C(  1926852641),  INT32_C(  1968975470),  INT32_C(  1128463571),  INT32_C(   353753163),  INT32_C(  1874525952),  INT32_C(  1994249980) },
      { -INT32_C(   198214145), -INT32_C(   727518099), -INT32_C(   845110266),  INT32_C(  1968975470),  INT32_C(  1128463571),  INT32_C(   353753163),  INT32_C(  1874525952),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(16418),
      {  INT32_C(   407134813),  INT32_C(  1705517887),  INT32_C(   227808945), -INT32_C(   854956149), -INT32_C(  1079618134),  INT32_C(   633251435), -INT32_C(   201606634), -INT32_C(  1926030032),
        -INT32_C(  1079609217),  INT32_C(  1277447835), -INT32_C(   262490012), -INT32_C(   893557729),  INT32_C(   612983737),  INT32_C(   541673482),  INT32_C(   856900866), -INT32_C(   490715294) },
      {  INT32_C(  1705517887),  INT32_C(   633251435),  INT32_C(   856900866),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(26303),
      { -INT32_C(   978036063),  INT32_C(    25041319), -INT32_C(   966419191), -INT32_C(   248897945), -INT32_C(  1942408125),  INT32_C(  1741765460),  INT32_C(   799945838), -INT32_C(  1214943978),
         INT32_C(  1870416584),  INT32_C(  1819343459), -INT32_C(    13445736),  INT32_C(   921722099), -INT32_C(   456971888), -INT32_C(   749955995), -INT32_C(   570230072),  INT32_C(   815110248) },
      { -INT32_C(   978036063),  INT32_C(    25041319), -INT32_C(   966419191), -INT32_C(   248897945), -INT32_C(  1942408125),  INT32_C(  1741765460), -INT32_C(  1214943978),  INT32_C(  1819343459),
        -INT32_C(    13445736), -INT32_C(   749955995), -INT32_C(   570230072),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C( 4834),
      {  INT32_C(   252462495), -INT32_C(   471554895), -INT32_C(  1807689820), -INT32_C(   776024050),  INT32_C(    23405493), -INT32_C(   100978954), -INT32_C(  1567530228),  INT32_C(   850686867),
         INT32_C(  1765916856),  INT32_C(   155985253),  INT32_C(   194874621),  INT32_C(   316431197),  INT32_C(  1964196222),  INT32_C(  2087587439),  INT32_C(    85917554),  INT32_C(   708366962) },
      { -INT32_C(   471554895), -INT32_C(   100978954), -INT32_C(  1567530228),  INT32_C(   850686867),  INT32_C(   155985253),  INT32_C(  1964196222),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(31122),
      { -INT32_C(   543164525), -INT32_C(  1637049344), -INT32_C(  2080781913), -INT32_C(   289113893),  INT32_C(  1543255277), -INT32_C(   832934224), -INT32_C(  1398748044), -INT32_C(  1994050826),
         INT32_C(   711509034),  INT32_C(   130602080),  INT32_C(  2022359709),  INT32_C(   661016378),  INT32_C(   864183171),  INT32_C(  1157749969), -INT32_C(  1628331608), -INT32_C(    47769645) },
      { -INT32_C(  1637049344),  INT32_C(  1543255277), -INT32_C(  1994050826),  INT32_C(   711509034),  INT32_C(   661016378),  INT32_C(   864183171),  INT32_C(  1157749969), -INT32_C(  1628331608),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_compress_epi32(test_vec[i].k, a);
    simde_assert_m512i_i32(r, ==, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_maskz_compress_epi32(k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compress_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 2493108884459479503),  INT64_C( 2745697586699650133),  INT64_C( 5962118592029881287),  INT64_C( 6675285231627136678),
        -INT64_C( 2831012078458751423),  INT64_C(  796104988546537341),  INT64_C( 1684375333511216585), -INT64_C( 8218286143030564087) },
         UINT8_MAX,
      {  INT64_C( 8019041593917055378), -INT64_C(  453245923385725034),  INT64_C( 1099020301626950428),  INT64_C( 6516401658411079334),
        -INT64_C( 2139367826792189943), -INT64_C( 2390140629292285025),  INT64_C( 7384308819634241094), -INT64_C( 4157310922897631957) },
      {  INT64_C( 8019041593917055378), -INT64_C(  453245923385725034),  INT64_C( 1099020301626950428),  INT64_C( 6516401658411079334),
        -INT64_C( 2139367826792189943), -INT64_C( 2390140629292285025),  INT64_C( 7384308819634241094), -INT64_C( 4157310922897631957) } },
    { { -INT64_C( 8907567126707538893), -INT64_C(  533338238125920263),  INT64_C( 3501228770388586353), -INT64_C( 2146684653369332814),
        -INT64_C( 3868940823565313050),  INT64_C( 5880328788138896881), -INT64_C( 8286033031999586610),  INT64_C( 9012883279740413572) },
      UINT8_C( 13),
      {  INT64_C( 4911361856295028853),  INT64_C( 7285547008249875246),  INT64_C( 1627152895847821048),  INT64_C( 5839246615699703755),
        -INT64_C( 4661593327776765837), -INT64_C( 2285250355206983044),  INT64_C( 2530325178788973078),  INT64_C( 7672209581709249356) },
      {  INT64_C( 4911361856295028853),  INT64_C( 1627152895847821048),  INT64_C( 5839246615699703755), -INT64_C( 2146684653369332814),
        -INT64_C( 3868940823565313050),  INT64_C( 5880328788138896881), -INT64_C( 8286033031999586610),  INT64_C( 9012883279740413572) } },
    { {  INT64_C( 3414505539985735953), -INT64_C( 5837127362439647435), -INT64_C( 4512093954938376219), -INT64_C( 4828031786423844450),
         INT64_C( 7729796773499073635), -INT64_C( 7460908001452796112), -INT64_C( 7229622113595413898),  INT64_C( 6494524872934331577) },
      UINT8_C(163),
      {  INT64_C(  896574445619671168), -INT64_C( 2825066835458705202), -INT64_C(  711445177485117906),  INT64_C( 2698578279713768608),
         INT64_C( 7023600647046319542), -INT64_C( 4713436406105032944),  INT64_C( 9047807365656898616),  INT64_C( 8760839120744185033) },
      {  INT64_C(  896574445619671168), -INT64_C( 2825066835458705202), -INT64_C( 4713436406105032944),  INT64_C( 8760839120744185033),
         INT64_C( 7729796773499073635), -INT64_C( 7460908001452796112), -INT64_C( 7229622113595413898),  INT64_C( 6494524872934331577) } },
    { { -INT64_C( 2161061711943697906),  INT64_C( 8422353885076699540),  INT64_C( 1512257621981005474),  INT64_C( 1681837217489766683),
         INT64_C( 3370306165781576721),  INT64_C( 4478043247772591476), -INT64_C( 1325824301445860550),  INT64_C( 4837748023067614210) },
      UINT8_C( 95),
      {  INT64_C( 5767746541070067419),  INT64_C( 1506219744840956792),  INT64_C( 2495789168939396327), -INT64_C( 6043944152560521826),
        -INT64_C( 5189750689051305794), -INT64_C(  577223740737985015),  INT64_C( 6115670276020102071), -INT64_C( 8474872024226515993) },
      {  INT64_C( 5767746541070067419),  INT64_C( 1506219744840956792),  INT64_C( 2495789168939396327), -INT64_C( 6043944152560521826),
        -INT64_C( 5189750689051305794),  INT64_C( 6115670276020102071), -INT64_C( 1325824301445860550),  INT64_C( 4837748023067614210) } },
    { { -INT64_C(  269601404141394356), -INT64_C( 6404712474483448555), -INT64_C( 3039292106936634169),  INT64_C( 7551674675064792950),
         INT64_C( 4865634921419571350),  INT64_C( 1617221418459163866), -INT64_C( 8071182703231969990),  INT64_C( 1211641448832797261) },
      UINT8_C(157),
      { -INT64_C( 8371330652359124541), -INT64_C( 2001584983363576456), -INT64_C( 1713465318900407931),  INT64_C( 3861681039351128413),
        -INT64_C( 1605814256078593524),  INT64_C(  689367967894835870),  INT64_C( 8631198279305301633), -INT64_C( 6236350112534025522) },
      { -INT64_C( 8371330652359124541), -INT64_C( 1713465318900407931),  INT64_C( 3861681039351128413), -INT64_C( 1605814256078593524),
        -INT64_C( 6236350112534025522),  INT64_C( 1617221418459163866), -INT64_C( 8071182703231969990),  INT64_C( 1211641448832797261) } },
    { {  INT64_C( 4667571595421983339),  INT64_C( 5668483602160921885), -INT64_C( 7376906312196645363), -INT64_C( 8906346440123936480),
        -INT64_C( 1958459154139890705),  INT64_C( 5543983091649200340),  INT64_C( 3833148311552138957),  INT64_C( 5243132631032400677) },
      UINT8_C(148),
      {  INT64_C( 7863072388426684964), -INT64_C( 3404447870832819773), -INT64_C( 7519293341366396563), -INT64_C( 3748902923188247540),
         INT64_C( 6209679465129595923),  INT64_C( 4501920474091543031), -INT64_C( 8825817795385139359), -INT64_C( 4630293410422754230) },
      { -INT64_C( 7519293341366396563),  INT64_C( 6209679465129595923), -INT64_C( 4630293410422754230), -INT64_C( 8906346440123936480),
        -INT64_C( 1958459154139890705),  INT64_C( 5543983091649200340),  INT64_C( 3833148311552138957),  INT64_C( 5243132631032400677) } },
    { {  INT64_C(   81535426338214712), -INT64_C( 3200611886661211771),  INT64_C(  324897693019166083), -INT64_C( 8492465835129541192),
        -INT64_C( 2985474989578935162), -INT64_C( 2079041934027047969), -INT64_C( 2101384240055655145),  INT64_C(  480315603526601935) },
      UINT8_C( 16),
      {  INT64_C( 7085629131838232319), -INT64_C( 5675196563958094237), -INT64_C( 5568773614773530746), -INT64_C( 9114942037925112059),
         INT64_C( 8887656059728552398),  INT64_C( 5075521323994782450),  INT64_C(  902942072098409198), -INT64_C( 4629420104847869508) },
      {  INT64_C( 8887656059728552398), -INT64_C( 3200611886661211771),  INT64_C(  324897693019166083), -INT64_C( 8492465835129541192),
        -INT64_C( 2985474989578935162), -INT64_C( 2079041934027047969), -INT64_C( 2101384240055655145),  INT64_C(  480315603526601935) } },
    { { -INT64_C(  760251800410081312), -INT64_C( 2149585961918196443), -INT64_C(  324190735203608212), -INT64_C( 2546792199631536393),
        -INT64_C( 8311032031394636880), -INT64_C( 1498681080831452067),  INT64_C( 2247542677356669686),  INT64_C( 1420795951341595102) },
      UINT8_C(  9),
      { -INT64_C( 3733206529576220789), -INT64_C( 6989243896000970387), -INT64_C( 3506923782549260650),  INT64_C( 8189592403690270703),
        -INT64_C( 9202695636988389619),  INT64_C( 7082909649666282999), -INT64_C( 1515692192841526334),  INT64_C( 9057915810236279388) },
      { -INT64_C( 3733206529576220789),  INT64_C( 8189592403690270703), -INT64_C(  324190735203608212), -INT64_C( 2546792199631536393),
        -INT64_C( 8311032031394636880), -INT64_C( 1498681080831452067),  INT64_C( 2247542677356669686),  INT64_C( 1420795951341595102) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_compress_epi64(src, test_vec[i].k, a);
    simde_assert_m512i_i64(r, ==, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_mask_compress_epi64(src, k, a);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_compressstoreu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C( 77),
      { -INT64_C( 5012569581454320313),  INT64_C( 9109225874129246176),  INT64_C( 7068125608572302728),  INT64_C( 1311169591362908783),
         INT64_C( 6130102184769990354),  INT64_C( 6269070946163513302),  INT64_C( 4654554676328778603),  INT64_C( 1881475806470214206) },
      { -INT64_C( 5012569581454320313),  INT64_C( 7068125608572302728),  INT64_C( 1311169591362908783),  INT64_C( 4654554676328778603),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(  7),
      { -INT64_C( 2629590339664711124), -INT64_C( 3585145662399183971),  INT64_C( 2288074959334962486),  INT64_C( 1397947565083183622),
         INT64_C( 5859816105203131123),  INT64_C( 3680677834418158658), -INT64_C( 7275717390590692134), -INT64_C( 2145295692204446144) },
      { -INT64_C( 2629590339664711124), -INT64_C( 3585145662399183971),  INT64_C( 2288074959334962486),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 66),
      { -INT64_C( 6378708221024708104), -INT64_C( 8670880827809939605),  INT64_C(  450843301195321740), -INT64_C( 7326275077715695439),
        -INT64_C(  395669636503156688), -INT64_C( 8546014609158822389), -INT64_C( 1538599149832011258), -INT64_C( 6741239437063382475) },
      { -INT64_C( 8670880827809939605), -INT64_C( 1538599149832011258),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(151),
      {  INT64_C( 2853909975659871812),  INT64_C( 7162323065389742827),  INT64_C( 4844333509203788857), -INT64_C( 4005854541068823933),
        -INT64_C( 7278393486219899178),  INT64_C(  698726240495411822),  INT64_C( 6507501174542716771),  INT64_C( 3722106747942012251) },
      {  INT64_C( 2853909975659871812),  INT64_C( 7162323065389742827),  INT64_C( 4844333509203788857), -INT64_C( 7278393486219899178),
         INT64_C( 3722106747942012251),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 34),
      {  INT64_C( 2981500635201997311), -INT64_C( 5681569781669843099), -INT64_C( 8668054333305638128),  INT64_C( 4162477496205611790),
         INT64_C( 7372828001579079201),  INT64_C( 6651624564162447932), -INT64_C( 3995138472205166460), -INT64_C( 6092755075180366850) },
      { -INT64_C( 5681569781669843099),  INT64_C( 6651624564162447932),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(197),
      {  INT64_C( 7955095425156305822),  INT64_C( 3183226164013040727),  INT64_C( 3906221504805090509),  INT64_C( 9083035734025203225),
         INT64_C( 6400194519105066047),  INT64_C( 8183937331011620115),  INT64_C( 4781941172684225123), -INT64_C( 3987206805157896884) },
      {  INT64_C( 7955095425156305822),  INT64_C( 3906221504805090509),  INT64_C( 4781941172684225123), -INT64_C( 3987206805157896884),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(108),
      { -INT64_C( 8325529535970988974), -INT64_C( 1559756814391649081), -INT64_C(  399881533574119351), -INT64_C( 7141218855182688288),
        -INT64_C( 2304873130570722440),  INT64_C( 2137294287985390415), -INT64_C(  970323334157452111), -INT64_C( 3513563796978594984) },
      { -INT64_C(  399881533574119351), -INT64_C( 7141218855182688288),  INT64_C( 2137294287985390415), -INT64_C(  970323334157452111),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(163),
      {  INT64_C( 9006246294607119931),  INT64_C( 2330170136248499060),  INT64_C( 8773896551416391090), -INT64_C( 2484967047489887089),
         INT64_C( 5812607648818413541),  INT64_C( 1929594973434804802), -INT64_C( 6046284682670769871),  INT64_C( 7722283055574738860) },
      {  INT64_C( 9006246294607119931),  INT64_C( 2330170136248499060),  INT64_C( 1929594973434804802),  INT64_C( 7722283055574738860),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_setzero_si512();
    simde_mm512_mask_compressstoreu_epi64(&r, test_vec[i].k, a);
    simde_assert_m512i_i64(r, ==, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_setzero_si512();
    simde_mm512_mask_compressstoreu_epi64(&r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_compress_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C( 32),
      {  INT64_C( 4280119270275027110), -INT64_C(  663774599397355031), -INT64_C( 4062177414580736333), -INT64_C( 3489396729738070519),
        -INT64_C( 7906962322811477956), -INT64_C( 4494835357231463900),  INT64_C( 3675587288679508753), -INT64_C(  522917027386060859) },
      { -INT64_C( 4494835357231463900),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(217),
      { -INT64_C( 8781432937347153877),  INT64_C( 6098813331820628591),  INT64_C( 8005625389676158469), -INT64_C(  978930628958681001),
         INT64_C( 8209518972302847267), -INT64_C( 2334370000430464036),  INT64_C( 2509715324500384132),  INT64_C( 4975946670638628693) },
      { -INT64_C( 8781432937347153877), -INT64_C(  978930628958681001),  INT64_C( 8209518972302847267),  INT64_C( 2509715324500384132),
         INT64_C( 4975946670638628693),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 10),
      {  INT64_C( 2300351618917117438), -INT64_C( 1825126848318066048), -INT64_C( 2040743177946656757), -INT64_C( 3049699082646468219),
        -INT64_C( 5137532713248113928), -INT64_C( 7946730710115570428), -INT64_C( 4656275361742887014), -INT64_C( 6265896103248239009) },
      { -INT64_C( 1825126848318066048), -INT64_C( 3049699082646468219),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(202),
      { -INT64_C( 7078046795661492752), -INT64_C( 5350922538851264872),  INT64_C(  329517712955882653), -INT64_C( 4329262355889928175),
         INT64_C( 4479193383562439835), -INT64_C( 7069772904402957088), -INT64_C( 7927352938009144741), -INT64_C( 6142737199726939862) },
      { -INT64_C( 5350922538851264872), -INT64_C( 4329262355889928175), -INT64_C( 7927352938009144741), -INT64_C( 6142737199726939862),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(138),
      { -INT64_C( 6093530414122518972),  INT64_C( 5929631578000694736), -INT64_C( 1106649384619982312), -INT64_C( 6539602272286891754),
        -INT64_C( 5986792588287119648), -INT64_C(  787314244254460608),  INT64_C( 6869980958270940200), -INT64_C( 2109002931107571788) },
      {  INT64_C( 5929631578000694736), -INT64_C( 6539602272286891754), -INT64_C( 2109002931107571788),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(191),
      { -INT64_C( 6714224875619540241), -INT64_C( 8578946464548416797),  INT64_C(  552870386611607780),  INT64_C( 7805841503750308419),
         INT64_C( 1926643671407455757), -INT64_C( 7669959262870488222), -INT64_C( 3250972690981494996), -INT64_C( 1953232003282834437) },
      { -INT64_C( 6714224875619540241), -INT64_C( 8578946464548416797),  INT64_C(  552870386611607780),  INT64_C( 7805841503750308419),
         INT64_C( 1926643671407455757), -INT64_C( 7669959262870488222), -INT64_C( 1953232003282834437),  INT64_C(                   0) } },
    { UINT8_C(168),
      { -INT64_C(  714672960096502046),  INT64_C(  638169372185467611), -INT64_C( 8791753692151236664),  INT64_C( 4409657742761686737),
        -INT64_C( 1878278078695796417), -INT64_C( 7291203750413953506), -INT64_C( 6681765341680605145),  INT64_C( 2425013449922617615) },
      {  INT64_C( 4409657742761686737), -INT64_C( 7291203750413953506),  INT64_C( 2425013449922617615),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(113),
      { -INT64_C( 6865350558291912042), -INT64_C( 5149009309057580812),  INT64_C( 3697506495475960999), -INT64_C(  563453109962687908),
        -INT64_C(   73663940351841968),  INT64_C( 2294001780559867084), -INT64_C( 1441520703368044486), -INT64_C( 7294469883978837141) },
      { -INT64_C( 6865350558291912042), -INT64_C(   73663940351841968),  INT64_C( 2294001780559867084), -INT64_C( 1441520703368044486),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_compress_epi64(test_vec[i].k, a);
    simde_assert_m512i_i64(r, ==, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_maskz_compress_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
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
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compress_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compressstoreu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_compress_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compress_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compressstoreu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_compress_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compress_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compressstoreu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_compress_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compress_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compressstoreu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_compress_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compressstoreu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compress_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compressstoreu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_compress_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compress_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_compressstoreu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_compress_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
