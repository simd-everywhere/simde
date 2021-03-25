#define SIMDE_TEST_X86_AVX512_INSN compress

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/compress.h>

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

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_compress_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
