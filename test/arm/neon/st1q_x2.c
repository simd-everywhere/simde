#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN st1q_x2
#include "test-neon.h"
#include "../../../simde/arm/neon/st1q_x2.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst1q_f16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t val[2][8];
    simde_float16_t r[16];
  } test_vec[] = {
  { { { SIMDE_FLOAT16_VALUE( - 20.956), SIMDE_FLOAT16_VALUE( - 58.964), SIMDE_FLOAT16_VALUE( - 74.395), SIMDE_FLOAT16_VALUE( - 58.069),
        SIMDE_FLOAT16_VALUE( - 73.918), SIMDE_FLOAT16_VALUE( - 88.889), SIMDE_FLOAT16_VALUE( - 89.387),  SIMDE_FLOAT16_VALUE( 26.229)  },
      {  SIMDE_FLOAT16_VALUE( 67.698),  SIMDE_FLOAT16_VALUE( 18.105),  SIMDE_FLOAT16_VALUE( 25.021),  SIMDE_FLOAT16_VALUE( 34.669),
        SIMDE_FLOAT16_VALUE( - 49.404), SIMDE_FLOAT16_VALUE( - 56.913),  SIMDE_FLOAT16_VALUE( 84.184),  SIMDE_FLOAT16_VALUE( 59.094)  } },
      { SIMDE_FLOAT16_VALUE( - 20.956), SIMDE_FLOAT16_VALUE( - 58.964), SIMDE_FLOAT16_VALUE( - 74.395), SIMDE_FLOAT16_VALUE( - 58.069),
        SIMDE_FLOAT16_VALUE( - 73.918), SIMDE_FLOAT16_VALUE( - 88.889), SIMDE_FLOAT16_VALUE( - 89.387),  SIMDE_FLOAT16_VALUE( 26.229),
         SIMDE_FLOAT16_VALUE( 67.698),  SIMDE_FLOAT16_VALUE( 18.105),  SIMDE_FLOAT16_VALUE( 25.021),  SIMDE_FLOAT16_VALUE( 34.669),
        SIMDE_FLOAT16_VALUE( - 49.404), SIMDE_FLOAT16_VALUE( - 56.913),  SIMDE_FLOAT16_VALUE( 84.184),  SIMDE_FLOAT16_VALUE( 59.094) } },
  { { {  SIMDE_FLOAT16_VALUE(  2.598), SIMDE_FLOAT16_VALUE( - 70.000),  SIMDE_FLOAT16_VALUE( 41.157), SIMDE_FLOAT16_VALUE( - 83.059),
        SIMDE_FLOAT16_VALUE( - 90.002),  SIMDE_FLOAT16_VALUE( 21.783),  SIMDE_FLOAT16_VALUE( 70.489),  SIMDE_FLOAT16_VALUE( 17.433)  },
      { SIMDE_FLOAT16_VALUE( - 86.074),  SIMDE_FLOAT16_VALUE( 41.189),  SIMDE_FLOAT16_VALUE( 63.234),  SIMDE_FLOAT16_VALUE( 12.204),
         SIMDE_FLOAT16_VALUE(  7.910), SIMDE_FLOAT16_VALUE( - 15.107), SIMDE_FLOAT16_VALUE( - 16.136),  SIMDE_FLOAT16_VALUE( 13.310)  } },
      {  SIMDE_FLOAT16_VALUE(  2.598), SIMDE_FLOAT16_VALUE( - 70.000),  SIMDE_FLOAT16_VALUE( 41.157), SIMDE_FLOAT16_VALUE( - 83.059),
        SIMDE_FLOAT16_VALUE( - 90.002),  SIMDE_FLOAT16_VALUE( 21.783),  SIMDE_FLOAT16_VALUE( 70.489),  SIMDE_FLOAT16_VALUE( 17.433),
        SIMDE_FLOAT16_VALUE( - 86.074),  SIMDE_FLOAT16_VALUE( 41.189),  SIMDE_FLOAT16_VALUE( 63.234),  SIMDE_FLOAT16_VALUE( 12.204),
         SIMDE_FLOAT16_VALUE(  7.910), SIMDE_FLOAT16_VALUE( - 15.107), SIMDE_FLOAT16_VALUE( - 16.136),  SIMDE_FLOAT16_VALUE( 13.310) } },
  { { { SIMDE_FLOAT16_VALUE( - 58.406), SIMDE_FLOAT16_VALUE( - 64.859), SIMDE_FLOAT16_VALUE( - 31.395),  SIMDE_FLOAT16_VALUE( 12.432),
        SIMDE_FLOAT16_VALUE( - 14.707),  SIMDE_FLOAT16_VALUE( 84.786), SIMDE_FLOAT16_VALUE( - 39.961),  SIMDE_FLOAT16_VALUE( 98.967)  },
      {  SIMDE_FLOAT16_VALUE( 28.677),  SIMDE_FLOAT16_VALUE( 63.490),  SIMDE_FLOAT16_VALUE( 74.828),  SIMDE_FLOAT16_VALUE( 21.706),
         SIMDE_FLOAT16_VALUE( 22.304),  SIMDE_FLOAT16_VALUE( 71.547),  SIMDE_FLOAT16_VALUE( 80.978),  SIMDE_FLOAT16_VALUE( 16.394)  } },
      { SIMDE_FLOAT16_VALUE( - 58.406), SIMDE_FLOAT16_VALUE( - 64.859), SIMDE_FLOAT16_VALUE( - 31.395),  SIMDE_FLOAT16_VALUE( 12.432),
        SIMDE_FLOAT16_VALUE( - 14.707),  SIMDE_FLOAT16_VALUE( 84.786), SIMDE_FLOAT16_VALUE( - 39.961),  SIMDE_FLOAT16_VALUE( 98.967),
         SIMDE_FLOAT16_VALUE( 28.677),  SIMDE_FLOAT16_VALUE( 63.490),  SIMDE_FLOAT16_VALUE( 74.828),  SIMDE_FLOAT16_VALUE( 21.706),
         SIMDE_FLOAT16_VALUE( 22.304),  SIMDE_FLOAT16_VALUE( 71.547),  SIMDE_FLOAT16_VALUE( 80.978),  SIMDE_FLOAT16_VALUE( 16.394) } },
  { { {  SIMDE_FLOAT16_VALUE( 97.804),  SIMDE_FLOAT16_VALUE( 73.823), SIMDE_FLOAT16_VALUE( -  8.059),  SIMDE_FLOAT16_VALUE( 93.096),
         SIMDE_FLOAT16_VALUE( 90.504), SIMDE_FLOAT16_VALUE( -  2.398),  SIMDE_FLOAT16_VALUE( 30.759), SIMDE_FLOAT16_VALUE( - 94.855)  },
      { SIMDE_FLOAT16_VALUE( -  5.801), SIMDE_FLOAT16_VALUE( - 68.562), SIMDE_FLOAT16_VALUE( - 54.678),  SIMDE_FLOAT16_VALUE( 22.048),
        SIMDE_FLOAT16_VALUE( - 71.055), SIMDE_FLOAT16_VALUE( - 30.977),  SIMDE_FLOAT16_VALUE( 18.382),  SIMDE_FLOAT16_VALUE( 11.761)  } },
      {  SIMDE_FLOAT16_VALUE( 97.804),  SIMDE_FLOAT16_VALUE( 73.823), SIMDE_FLOAT16_VALUE( -  8.059),  SIMDE_FLOAT16_VALUE( 93.096),
         SIMDE_FLOAT16_VALUE( 90.504), SIMDE_FLOAT16_VALUE( -  2.398),  SIMDE_FLOAT16_VALUE( 30.759), SIMDE_FLOAT16_VALUE( - 94.855),
        SIMDE_FLOAT16_VALUE( -  5.801), SIMDE_FLOAT16_VALUE( - 68.562), SIMDE_FLOAT16_VALUE( - 54.678),  SIMDE_FLOAT16_VALUE( 22.048),
        SIMDE_FLOAT16_VALUE( - 71.055), SIMDE_FLOAT16_VALUE( - 30.977),  SIMDE_FLOAT16_VALUE( 18.382),  SIMDE_FLOAT16_VALUE( 11.761) } },
  { { {  SIMDE_FLOAT16_VALUE( 55.035),  SIMDE_FLOAT16_VALUE( 94.504),  SIMDE_FLOAT16_VALUE( 21.867),  SIMDE_FLOAT16_VALUE( 60.556),
        SIMDE_FLOAT16_VALUE( - 21.374),  SIMDE_FLOAT16_VALUE( 82.466),  SIMDE_FLOAT16_VALUE( 84.824),  SIMDE_FLOAT16_VALUE( 31.885)  },
      {  SIMDE_FLOAT16_VALUE( 17.599), SIMDE_FLOAT16_VALUE( - 18.858), SIMDE_FLOAT16_VALUE( - 97.376), SIMDE_FLOAT16_VALUE( - 85.414),
        SIMDE_FLOAT16_VALUE( - 37.173),  SIMDE_FLOAT16_VALUE( 36.083),  SIMDE_FLOAT16_VALUE( 51.414),  SIMDE_FLOAT16_VALUE( 42.445)  } },
      {  SIMDE_FLOAT16_VALUE( 55.035),  SIMDE_FLOAT16_VALUE( 94.504),  SIMDE_FLOAT16_VALUE( 21.867),  SIMDE_FLOAT16_VALUE( 60.556),
        SIMDE_FLOAT16_VALUE( - 21.374),  SIMDE_FLOAT16_VALUE( 82.466),  SIMDE_FLOAT16_VALUE( 84.824),  SIMDE_FLOAT16_VALUE( 31.885),
         SIMDE_FLOAT16_VALUE( 17.599), SIMDE_FLOAT16_VALUE( - 18.858), SIMDE_FLOAT16_VALUE( - 97.376), SIMDE_FLOAT16_VALUE( - 85.414),
        SIMDE_FLOAT16_VALUE( - 37.173),  SIMDE_FLOAT16_VALUE( 36.083),  SIMDE_FLOAT16_VALUE( 51.414),  SIMDE_FLOAT16_VALUE( 42.445) } },
  { { { SIMDE_FLOAT16_VALUE( - 58.353),  SIMDE_FLOAT16_VALUE( 94.351), SIMDE_FLOAT16_VALUE( - 72.718),  SIMDE_FLOAT16_VALUE( 44.738),
         SIMDE_FLOAT16_VALUE( 88.331),  SIMDE_FLOAT16_VALUE( 93.544),  SIMDE_FLOAT16_VALUE( 79.940), SIMDE_FLOAT16_VALUE( - 29.844)  },
      { SIMDE_FLOAT16_VALUE( - 64.679), SIMDE_FLOAT16_VALUE( - 31.234),  SIMDE_FLOAT16_VALUE( 25.402),  SIMDE_FLOAT16_VALUE( 61.429),
        SIMDE_FLOAT16_VALUE( - 80.532),  SIMDE_FLOAT16_VALUE( 19.659), SIMDE_FLOAT16_VALUE( - 67.325),  SIMDE_FLOAT16_VALUE( 54.634)  } },
      { SIMDE_FLOAT16_VALUE( - 58.353),  SIMDE_FLOAT16_VALUE( 94.351), SIMDE_FLOAT16_VALUE( - 72.718),  SIMDE_FLOAT16_VALUE( 44.738),
         SIMDE_FLOAT16_VALUE( 88.331),  SIMDE_FLOAT16_VALUE( 93.544),  SIMDE_FLOAT16_VALUE( 79.940), SIMDE_FLOAT16_VALUE( - 29.844),
        SIMDE_FLOAT16_VALUE( - 64.679), SIMDE_FLOAT16_VALUE( - 31.234),  SIMDE_FLOAT16_VALUE( 25.402),  SIMDE_FLOAT16_VALUE( 61.429),
        SIMDE_FLOAT16_VALUE( - 80.532),  SIMDE_FLOAT16_VALUE( 19.659), SIMDE_FLOAT16_VALUE( - 67.325),  SIMDE_FLOAT16_VALUE( 54.634) } },
  { { { SIMDE_FLOAT16_VALUE( - 99.773),  SIMDE_FLOAT16_VALUE( 27.004),  SIMDE_FLOAT16_VALUE( 53.708),  SIMDE_FLOAT16_VALUE( 12.664),
         SIMDE_FLOAT16_VALUE( 66.275), SIMDE_FLOAT16_VALUE( -  0.836), SIMDE_FLOAT16_VALUE( - 22.661),  SIMDE_FLOAT16_VALUE( 72.602)  },
      {  SIMDE_FLOAT16_VALUE( 25.260), SIMDE_FLOAT16_VALUE( - 83.782), SIMDE_FLOAT16_VALUE( - 61.087), SIMDE_FLOAT16_VALUE( - 38.948),
        SIMDE_FLOAT16_VALUE( - 78.380),  SIMDE_FLOAT16_VALUE(  6.817), SIMDE_FLOAT16_VALUE( - 82.373), SIMDE_FLOAT16_VALUE( - 60.011)  } },
      { SIMDE_FLOAT16_VALUE( - 99.773),  SIMDE_FLOAT16_VALUE( 27.004),  SIMDE_FLOAT16_VALUE( 53.708),  SIMDE_FLOAT16_VALUE( 12.664),
         SIMDE_FLOAT16_VALUE( 66.275), SIMDE_FLOAT16_VALUE( -  0.836), SIMDE_FLOAT16_VALUE( - 22.661),  SIMDE_FLOAT16_VALUE( 72.602),
         SIMDE_FLOAT16_VALUE( 25.260), SIMDE_FLOAT16_VALUE( - 83.782), SIMDE_FLOAT16_VALUE( - 61.087), SIMDE_FLOAT16_VALUE( - 38.948),
        SIMDE_FLOAT16_VALUE( - 78.380),  SIMDE_FLOAT16_VALUE(  6.817), SIMDE_FLOAT16_VALUE( - 82.373), SIMDE_FLOAT16_VALUE( - 60.011) } },
  { { { SIMDE_FLOAT16_VALUE( - 53.476),  SIMDE_FLOAT16_VALUE(  8.724), SIMDE_FLOAT16_VALUE( - 88.674), SIMDE_FLOAT16_VALUE( - 48.309),
        SIMDE_FLOAT16_VALUE( -  3.562),  SIMDE_FLOAT16_VALUE( 14.309), SIMDE_FLOAT16_VALUE( - 99.801), SIMDE_FLOAT16_VALUE( - 11.703)  },
      { SIMDE_FLOAT16_VALUE( - 62.913), SIMDE_FLOAT16_VALUE( - 43.056), SIMDE_FLOAT16_VALUE( - 65.766),  SIMDE_FLOAT16_VALUE( 92.099),
         SIMDE_FLOAT16_VALUE( 73.066),  SIMDE_FLOAT16_VALUE( 29.509), SIMDE_FLOAT16_VALUE( - 77.995), SIMDE_FLOAT16_VALUE( - 81.816)  } },
      { SIMDE_FLOAT16_VALUE( - 53.476),  SIMDE_FLOAT16_VALUE(  8.724), SIMDE_FLOAT16_VALUE( - 88.674), SIMDE_FLOAT16_VALUE( - 48.309),
        SIMDE_FLOAT16_VALUE( -  3.562),  SIMDE_FLOAT16_VALUE( 14.309), SIMDE_FLOAT16_VALUE( - 99.801), SIMDE_FLOAT16_VALUE( - 11.703),
        SIMDE_FLOAT16_VALUE( - 62.913), SIMDE_FLOAT16_VALUE( - 43.056), SIMDE_FLOAT16_VALUE( - 65.766),  SIMDE_FLOAT16_VALUE( 92.099),
         SIMDE_FLOAT16_VALUE( 73.066),  SIMDE_FLOAT16_VALUE( 29.509), SIMDE_FLOAT16_VALUE( - 77.995), SIMDE_FLOAT16_VALUE( - 81.816) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float16x8x2_t val = {{
        simde_vld1q_f16(test_vec[i].val[0]),
        simde_vld1q_f16(test_vec[i].val[1]),
    }};
    simde_float16_t r_[16];
    simde_vst1q_f16_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x2_t val[2] = simde_test_arm_neon_random_f16x2(-100.0f, 100.0f);
    simde_float16x16_t r = simde_vst1q_f16_x2(val[2]);

    simde_test_arm_neon_write_f16x2(2, val[2], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_f32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[2][4];
    simde_float32 a[8];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(  -814.14), SIMDE_FLOAT32_C(   -94.07), SIMDE_FLOAT32_C(   948.70), SIMDE_FLOAT32_C(  -406.94) },
          { SIMDE_FLOAT32_C(   726.28), SIMDE_FLOAT32_C(   949.91), SIMDE_FLOAT32_C(  -352.52), SIMDE_FLOAT32_C(   185.24) } },
      { SIMDE_FLOAT32_C(  -814.14), SIMDE_FLOAT32_C(   -94.07), SIMDE_FLOAT32_C(   948.70), SIMDE_FLOAT32_C(  -406.94),
        SIMDE_FLOAT32_C(   726.28), SIMDE_FLOAT32_C(   949.91), SIMDE_FLOAT32_C(  -352.52), SIMDE_FLOAT32_C(   185.24) } },
    {
        { { SIMDE_FLOAT32_C(   286.92), SIMDE_FLOAT32_C(   764.27), SIMDE_FLOAT32_C(  -522.50), SIMDE_FLOAT32_C(    86.44) },
          { SIMDE_FLOAT32_C(   133.06), SIMDE_FLOAT32_C(   598.10), SIMDE_FLOAT32_C(   639.80), SIMDE_FLOAT32_C(   910.39) } },
      { SIMDE_FLOAT32_C(   286.92), SIMDE_FLOAT32_C(   764.27), SIMDE_FLOAT32_C(  -522.50), SIMDE_FLOAT32_C(    86.44),
        SIMDE_FLOAT32_C(   133.06), SIMDE_FLOAT32_C(   598.10), SIMDE_FLOAT32_C(   639.80), SIMDE_FLOAT32_C(   910.39) } },
    {
        { { SIMDE_FLOAT32_C(  -462.75), SIMDE_FLOAT32_C(  -168.94), SIMDE_FLOAT32_C(   654.57), SIMDE_FLOAT32_C(  -619.06) },
          { SIMDE_FLOAT32_C(  -663.52), SIMDE_FLOAT32_C(  -730.61), SIMDE_FLOAT32_C(   624.00), SIMDE_FLOAT32_C(   502.46) } },
      { SIMDE_FLOAT32_C(  -462.75), SIMDE_FLOAT32_C(  -168.94), SIMDE_FLOAT32_C(   654.57), SIMDE_FLOAT32_C(  -619.06),
        SIMDE_FLOAT32_C(  -663.52), SIMDE_FLOAT32_C(  -730.61), SIMDE_FLOAT32_C(   624.00), SIMDE_FLOAT32_C(   502.46) } },
    {
        { { SIMDE_FLOAT32_C(   356.79), SIMDE_FLOAT32_C(  -915.72), SIMDE_FLOAT32_C(   439.28), SIMDE_FLOAT32_C(   204.87) },
          { SIMDE_FLOAT32_C(  -612.34), SIMDE_FLOAT32_C(   -70.37), SIMDE_FLOAT32_C(    33.68), SIMDE_FLOAT32_C(  -426.49) } },
      { SIMDE_FLOAT32_C(   356.79), SIMDE_FLOAT32_C(  -915.72), SIMDE_FLOAT32_C(   439.28), SIMDE_FLOAT32_C(   204.87),
        SIMDE_FLOAT32_C(  -612.34), SIMDE_FLOAT32_C(   -70.37), SIMDE_FLOAT32_C(    33.68), SIMDE_FLOAT32_C(  -426.49) } },
    {
        { { SIMDE_FLOAT32_C(   835.56), SIMDE_FLOAT32_C(   -17.62), SIMDE_FLOAT32_C(   166.58), SIMDE_FLOAT32_C(   561.84) },
          { SIMDE_FLOAT32_C(   -67.72), SIMDE_FLOAT32_C(   814.06), SIMDE_FLOAT32_C(  -252.91), SIMDE_FLOAT32_C(  -780.80) } },
      { SIMDE_FLOAT32_C(   835.56), SIMDE_FLOAT32_C(   -17.62), SIMDE_FLOAT32_C(   166.58), SIMDE_FLOAT32_C(   561.84),
        SIMDE_FLOAT32_C(   -67.72), SIMDE_FLOAT32_C(   814.06), SIMDE_FLOAT32_C(  -252.91), SIMDE_FLOAT32_C(  -780.80) } },
    {
        { { SIMDE_FLOAT32_C(   578.33), SIMDE_FLOAT32_C(   224.58), SIMDE_FLOAT32_C(   305.65), SIMDE_FLOAT32_C(  -288.61) },
          { SIMDE_FLOAT32_C(  -177.32), SIMDE_FLOAT32_C(   -54.55), SIMDE_FLOAT32_C(  -378.22), SIMDE_FLOAT32_C(   359.94) } },
      { SIMDE_FLOAT32_C(   578.33), SIMDE_FLOAT32_C(   224.58), SIMDE_FLOAT32_C(   305.65), SIMDE_FLOAT32_C(  -288.61),
        SIMDE_FLOAT32_C(  -177.32), SIMDE_FLOAT32_C(   -54.55), SIMDE_FLOAT32_C(  -378.22), SIMDE_FLOAT32_C(   359.94) } },
    {
        { { SIMDE_FLOAT32_C(   776.51), SIMDE_FLOAT32_C(  -723.65), SIMDE_FLOAT32_C(   740.87), SIMDE_FLOAT32_C(  -887.01) },
          { SIMDE_FLOAT32_C(  -454.26), SIMDE_FLOAT32_C(   364.87), SIMDE_FLOAT32_C(   615.45), SIMDE_FLOAT32_C(   902.53) } },
      { SIMDE_FLOAT32_C(   776.51), SIMDE_FLOAT32_C(  -723.65), SIMDE_FLOAT32_C(   740.87), SIMDE_FLOAT32_C(  -887.01),
        SIMDE_FLOAT32_C(  -454.26), SIMDE_FLOAT32_C(   364.87), SIMDE_FLOAT32_C(   615.45), SIMDE_FLOAT32_C(   902.53) } },
    {
        { { SIMDE_FLOAT32_C(   449.16), SIMDE_FLOAT32_C(    54.72), SIMDE_FLOAT32_C(   107.41), SIMDE_FLOAT32_C(   836.82) },
          { SIMDE_FLOAT32_C(   984.35), SIMDE_FLOAT32_C(  -858.92), SIMDE_FLOAT32_C(  -589.67), SIMDE_FLOAT32_C(   819.91) } },
      { SIMDE_FLOAT32_C(   449.16), SIMDE_FLOAT32_C(    54.72), SIMDE_FLOAT32_C(   107.41), SIMDE_FLOAT32_C(   836.82),
        SIMDE_FLOAT32_C(   984.35), SIMDE_FLOAT32_C(  -858.92), SIMDE_FLOAT32_C(  -589.67), SIMDE_FLOAT32_C(   819.91) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x2_t r_ = { { simde_vld1q_f32(test_vec[i].r[0]),
                                 simde_vld1q_f32(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 simde_float32 a_[8];
    simde_vst1q_f32_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_f32x4x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32 buf[8];
    simde_vst1q_f32_x2(buf, c);

    simde_test_codegen_write_vf32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_f64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[2][2];
    simde_float64 a[4];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(   123.46), SIMDE_FLOAT64_C(   576.90) },
          { SIMDE_FLOAT64_C(   381.75), SIMDE_FLOAT64_C(  -944.26) } },
      { SIMDE_FLOAT64_C(   123.46), SIMDE_FLOAT64_C(   576.90), SIMDE_FLOAT64_C(   381.75), SIMDE_FLOAT64_C(  -944.26) } },
    {
        { { SIMDE_FLOAT64_C(   390.96), SIMDE_FLOAT64_C(  -871.16) },
          { SIMDE_FLOAT64_C(  -725.05), SIMDE_FLOAT64_C(   -30.71) } },
      { SIMDE_FLOAT64_C(   390.96), SIMDE_FLOAT64_C(  -871.16), SIMDE_FLOAT64_C(  -725.05), SIMDE_FLOAT64_C(   -30.71) } },
    {
        { { SIMDE_FLOAT64_C(   353.42), SIMDE_FLOAT64_C(   580.59) },
          { SIMDE_FLOAT64_C(   680.68), SIMDE_FLOAT64_C(  -823.89) } },
      { SIMDE_FLOAT64_C(   353.42), SIMDE_FLOAT64_C(   580.59), SIMDE_FLOAT64_C(   680.68), SIMDE_FLOAT64_C(  -823.89) } },
    {
        { { SIMDE_FLOAT64_C(  -473.96), SIMDE_FLOAT64_C(  -697.54) },
          { SIMDE_FLOAT64_C(   536.04), SIMDE_FLOAT64_C(  -697.45) } },
      { SIMDE_FLOAT64_C(  -473.96), SIMDE_FLOAT64_C(  -697.54), SIMDE_FLOAT64_C(   536.04), SIMDE_FLOAT64_C(  -697.45) } },
    {
        { { SIMDE_FLOAT64_C(  -421.19), SIMDE_FLOAT64_C(   276.92) },
          { SIMDE_FLOAT64_C(  -584.46), SIMDE_FLOAT64_C(   124.55) } },
      { SIMDE_FLOAT64_C(  -421.19), SIMDE_FLOAT64_C(   276.92), SIMDE_FLOAT64_C(  -584.46), SIMDE_FLOAT64_C(   124.55) } },
    {
        { { SIMDE_FLOAT64_C(  -358.21), SIMDE_FLOAT64_C(  -969.01) },
          { SIMDE_FLOAT64_C(    27.09), SIMDE_FLOAT64_C(  -909.05) } },
      { SIMDE_FLOAT64_C(  -358.21), SIMDE_FLOAT64_C(  -969.01), SIMDE_FLOAT64_C(    27.09), SIMDE_FLOAT64_C(  -909.05) } },
    {
        { { SIMDE_FLOAT64_C(    85.71), SIMDE_FLOAT64_C(  -865.51) },
          { SIMDE_FLOAT64_C(   927.77), SIMDE_FLOAT64_C(    70.06) } },
      { SIMDE_FLOAT64_C(    85.71), SIMDE_FLOAT64_C(  -865.51), SIMDE_FLOAT64_C(   927.77), SIMDE_FLOAT64_C(    70.06) } },
    {
        { { SIMDE_FLOAT64_C(  -724.43), SIMDE_FLOAT64_C(  -661.90) },
          { SIMDE_FLOAT64_C(  -110.03), SIMDE_FLOAT64_C(   399.03) } },
      { SIMDE_FLOAT64_C(  -724.43), SIMDE_FLOAT64_C(  -661.90), SIMDE_FLOAT64_C(  -110.03), SIMDE_FLOAT64_C(   399.03) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x2_t r_ = { { simde_vld1q_f64(test_vec[i].r[0]),
                                 simde_vld1q_f64(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 simde_float64 a_[4];
    simde_vst1q_f64_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_f64x2x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64 buf[4];
    simde_vst1q_f64_x2(buf, c);

    simde_test_codegen_write_vf64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[2][16];
    int8_t a[32];
  } test_vec[] = {
    {
        { {  INT8_C(  96),  INT8_C(   3), -INT8_C(  74),  INT8_C( 109), -INT8_C(  64), -INT8_C( 106),  INT8_C(  64), -INT8_C( 117),
             INT8_C(  56),  INT8_C(  41),  INT8_C(  41),  INT8_C( 117), -INT8_C(  27),  INT8_C( 101), -INT8_C(  63),  INT8_C(  97) },
          { -INT8_C(  39), -INT8_C(  25), -INT8_C(  81),  INT8_C(  85),  INT8_C(  34), -INT8_C(   5), -INT8_C(  58), -INT8_C( 114),
            -INT8_C( 121), -INT8_C(  34),  INT8_C(  23), -INT8_C( 116), -INT8_C(  57),  INT8_C(  82),  INT8_C(  68),  INT8_C(  39) } },
      {  INT8_C(  96),  INT8_C(   3), -INT8_C(  74),  INT8_C( 109), -INT8_C(  64), -INT8_C( 106),  INT8_C(  64), -INT8_C( 117),
         INT8_C(  56),  INT8_C(  41),  INT8_C(  41),  INT8_C( 117), -INT8_C(  27),  INT8_C( 101), -INT8_C(  63),  INT8_C(  97),
        -INT8_C(  39), -INT8_C(  25), -INT8_C(  81),  INT8_C(  85),  INT8_C(  34), -INT8_C(   5), -INT8_C(  58), -INT8_C( 114),
        -INT8_C( 121), -INT8_C(  34),  INT8_C(  23), -INT8_C( 116), -INT8_C(  57),  INT8_C(  82),  INT8_C(  68),  INT8_C(  39) } },
    {
        { {  INT8_C(  86), -INT8_C(   6), -INT8_C( 107),  INT8_C(  22), -INT8_C( 112), -INT8_C(  43), -INT8_C(  95), -INT8_C(  56),
            -INT8_C(   2), -INT8_C(  54),  INT8_C(  62), -INT8_C(  29),  INT8_C(  48), -INT8_C(   1),  INT8_C(  68),  INT8_C(   9) },
          { -INT8_C(  26), -INT8_C(  13),  INT8_C(  94),  INT8_C(   8), -INT8_C(  17),  INT8_C(  37), -INT8_C( 105),  INT8_C( 118),
             INT8_C(   3), -INT8_C(  82),  INT8_C(   2), -INT8_C(  54),  INT8_C(   1),  INT8_C(  70), -INT8_C(  15),  INT8_C(  87) } },
      {  INT8_C(  86), -INT8_C(   6), -INT8_C( 107),  INT8_C(  22), -INT8_C( 112), -INT8_C(  43), -INT8_C(  95), -INT8_C(  56),
        -INT8_C(   2), -INT8_C(  54),  INT8_C(  62), -INT8_C(  29),  INT8_C(  48), -INT8_C(   1),  INT8_C(  68),  INT8_C(   9),
        -INT8_C(  26), -INT8_C(  13),  INT8_C(  94),  INT8_C(   8), -INT8_C(  17),  INT8_C(  37), -INT8_C( 105),  INT8_C( 118),
         INT8_C(   3), -INT8_C(  82),  INT8_C(   2), -INT8_C(  54),  INT8_C(   1),  INT8_C(  70), -INT8_C(  15),  INT8_C(  87) } },
    {
        { {  INT8_C(  64), -INT8_C( 122),  INT8_C( 109), -INT8_C(  48),  INT8_C(  91),  INT8_C(  14), -INT8_C( 103),  INT8_C(  89),
            -INT8_C(  39), -INT8_C(  41),  INT8_C(  61),  INT8_C(   9), -INT8_C(  42), -INT8_C( 127),  INT8_C(  18), -INT8_C(  67) },
          {  INT8_C( 117),  INT8_C( 113), -INT8_C(  59),  INT8_C( 100), -INT8_C( 106),  INT8_C(  92), -INT8_C(  38), -INT8_C( 103),
             INT8_C(  11), -INT8_C(  35),  INT8_C(  99),  INT8_C(  12),  INT8_C(  35),  INT8_C(  84),  INT8_C(  99),  INT8_C( 100) } },
      {  INT8_C(  64), -INT8_C( 122),  INT8_C( 109), -INT8_C(  48),  INT8_C(  91),  INT8_C(  14), -INT8_C( 103),  INT8_C(  89),
        -INT8_C(  39), -INT8_C(  41),  INT8_C(  61),  INT8_C(   9), -INT8_C(  42), -INT8_C( 127),  INT8_C(  18), -INT8_C(  67),
         INT8_C( 117),  INT8_C( 113), -INT8_C(  59),  INT8_C( 100), -INT8_C( 106),  INT8_C(  92), -INT8_C(  38), -INT8_C( 103),
         INT8_C(  11), -INT8_C(  35),  INT8_C(  99),  INT8_C(  12),  INT8_C(  35),  INT8_C(  84),  INT8_C(  99),  INT8_C( 100) } },
    {
        { { -INT8_C(  37), -INT8_C(  48),  INT8_C(  52),  INT8_C(  54), -INT8_C(  34), -INT8_C(  51), -INT8_C( 112), -INT8_C(  73),
            -INT8_C(  92), -INT8_C(  51), -INT8_C(  64),  INT8_C( 123),  INT8_C(  78), -INT8_C(  45),  INT8_C(  56), -INT8_C(  61) },
          {  INT8_C(  68), -INT8_C(   3),  INT8_C(  39), -INT8_C(  38),  INT8_C(  90),  INT8_C(   2),  INT8_C( 115),  INT8_C( 101),
            -INT8_C(  33), -INT8_C(  42),  INT8_C( 113),  INT8_C(   2),  INT8_C(  42), -INT8_C(  44),  INT8_C( 102),  INT8_C(   5) } },
      { -INT8_C(  37), -INT8_C(  48),  INT8_C(  52),  INT8_C(  54), -INT8_C(  34), -INT8_C(  51), -INT8_C( 112), -INT8_C(  73),
        -INT8_C(  92), -INT8_C(  51), -INT8_C(  64),  INT8_C( 123),  INT8_C(  78), -INT8_C(  45),  INT8_C(  56), -INT8_C(  61),
         INT8_C(  68), -INT8_C(   3),  INT8_C(  39), -INT8_C(  38),  INT8_C(  90),  INT8_C(   2),  INT8_C( 115),  INT8_C( 101),
        -INT8_C(  33), -INT8_C(  42),  INT8_C( 113),  INT8_C(   2),  INT8_C(  42), -INT8_C(  44),  INT8_C( 102),  INT8_C(   5) } },
    {
        { { -INT8_C(  92), -INT8_C( 101),  INT8_C(  60), -INT8_C( 126),  INT8_C( 104), -INT8_C(  52),  INT8_C(  58),  INT8_C(  13),
            -INT8_C( 103), -INT8_C(   6), -INT8_C( 120), -INT8_C(  25), -INT8_C(  51), -INT8_C(  64), -INT8_C(  85),  INT8_C(  17) },
          { -INT8_C(  67), -INT8_C(  46), -INT8_C(  21),  INT8_C(  23), -INT8_C(  44),  INT8_C(  94),  INT8_C( 124), -INT8_C(  77),
             INT8_C(  52), -INT8_C(  19), -INT8_C(  74),  INT8_C(  95), -INT8_C(  63),  INT8_C(  28),  INT8_C( 100),  INT8_C( 101) } },
      { -INT8_C(  92), -INT8_C( 101),  INT8_C(  60), -INT8_C( 126),  INT8_C( 104), -INT8_C(  52),  INT8_C(  58),  INT8_C(  13),
        -INT8_C( 103), -INT8_C(   6), -INT8_C( 120), -INT8_C(  25), -INT8_C(  51), -INT8_C(  64), -INT8_C(  85),  INT8_C(  17),
        -INT8_C(  67), -INT8_C(  46), -INT8_C(  21),  INT8_C(  23), -INT8_C(  44),  INT8_C(  94),  INT8_C( 124), -INT8_C(  77),
         INT8_C(  52), -INT8_C(  19), -INT8_C(  74),  INT8_C(  95), -INT8_C(  63),  INT8_C(  28),  INT8_C( 100),  INT8_C( 101) } },
    {
        { { -INT8_C(  73), -INT8_C(  96), -INT8_C(  24),  INT8_C(  32),  INT8_C( 108),  INT8_C(  34),  INT8_C(  45),  INT8_C(   5),
             INT8_C(  28), -INT8_C(  75), -INT8_C(  19), -INT8_C(  22),  INT8_C( 117), -INT8_C( 104), -INT8_C(   5),  INT8_C(  50) },
          {  INT8_C( 106), -INT8_C(  25),  INT8_C(  74),  INT8_C(  63),  INT8_C(  69), -INT8_C(  58), -INT8_C(  14),  INT8_C( 122),
            -INT8_C(  76), -INT8_C(  88), -INT8_C(  39),  INT8_C( 117), -INT8_C(  59),  INT8_C(  61), -INT8_C(  37),  INT8_C( 124) } },
      { -INT8_C(  73), -INT8_C(  96), -INT8_C(  24),  INT8_C(  32),  INT8_C( 108),  INT8_C(  34),  INT8_C(  45),  INT8_C(   5),
         INT8_C(  28), -INT8_C(  75), -INT8_C(  19), -INT8_C(  22),  INT8_C( 117), -INT8_C( 104), -INT8_C(   5),  INT8_C(  50),
         INT8_C( 106), -INT8_C(  25),  INT8_C(  74),  INT8_C(  63),  INT8_C(  69), -INT8_C(  58), -INT8_C(  14),  INT8_C( 122),
        -INT8_C(  76), -INT8_C(  88), -INT8_C(  39),  INT8_C( 117), -INT8_C(  59),  INT8_C(  61), -INT8_C(  37),  INT8_C( 124) } },
    {
        { { -INT8_C(  34), -INT8_C(  61), -INT8_C( 100),  INT8_C(  74), -INT8_C(  27), -INT8_C(  55),  INT8_C(  80),  INT8_C(   1),
             INT8_C( 126),  INT8_C(  61), -INT8_C(  21), -INT8_C(  13), -INT8_C(  43), -INT8_C(  25),  INT8_C(  38),  INT8_C(  63) },
          { -INT8_C(  50),  INT8_C( 112),  INT8_C( 126),  INT8_C(  19),  INT8_C(  54),  INT8_C( 113), -INT8_C( 115), -INT8_C(  22),
             INT8_C(  25),  INT8_C( 102),  INT8_C(  96), -INT8_C(  34), -INT8_C(  92),  INT8_C(  59),  INT8_C(  91), -INT8_C( 126) } },
      { -INT8_C(  34), -INT8_C(  61), -INT8_C( 100),  INT8_C(  74), -INT8_C(  27), -INT8_C(  55),  INT8_C(  80),  INT8_C(   1),
         INT8_C( 126),  INT8_C(  61), -INT8_C(  21), -INT8_C(  13), -INT8_C(  43), -INT8_C(  25),  INT8_C(  38),  INT8_C(  63),
        -INT8_C(  50),  INT8_C( 112),  INT8_C( 126),  INT8_C(  19),  INT8_C(  54),  INT8_C( 113), -INT8_C( 115), -INT8_C(  22),
         INT8_C(  25),  INT8_C( 102),  INT8_C(  96), -INT8_C(  34), -INT8_C(  92),  INT8_C(  59),  INT8_C(  91), -INT8_C( 126) } },
    {
        { { -INT8_C(   2), -INT8_C(   9), -INT8_C(  52), -INT8_C(  29), -INT8_C(  63),  INT8_C(  28), -INT8_C(  28),  INT8_C(  63),
             INT8_C(  89), -INT8_C(  48),  INT8_C(  51),  INT8_C(  46), -INT8_C(  73),  INT8_C(  89),  INT8_C( 110), -INT8_C( 123) },
          { -INT8_C(  55), -INT8_C(  20), -INT8_C( 104), -INT8_C(   1),  INT8_C(  93),  INT8_C(  38), -INT8_C(  22),  INT8_C( 119),
            -INT8_C( 116),  INT8_C(  74),  INT8_C(  85),  INT8_C(  48), -INT8_C( 123), -INT8_C(  80), -INT8_C(  78), -INT8_C( 125) } },
      { -INT8_C(   2), -INT8_C(   9), -INT8_C(  52), -INT8_C(  29), -INT8_C(  63),  INT8_C(  28), -INT8_C(  28),  INT8_C(  63),
         INT8_C(  89), -INT8_C(  48),  INT8_C(  51),  INT8_C(  46), -INT8_C(  73),  INT8_C(  89),  INT8_C( 110), -INT8_C( 123),
        -INT8_C(  55), -INT8_C(  20), -INT8_C( 104), -INT8_C(   1),  INT8_C(  93),  INT8_C(  38), -INT8_C(  22),  INT8_C( 119),
        -INT8_C( 116),  INT8_C(  74),  INT8_C(  85),  INT8_C(  48), -INT8_C( 123), -INT8_C(  80), -INT8_C(  78), -INT8_C( 125) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x2_t r_ = { { simde_vld1q_s8(test_vec[i].r[0]),
                               simde_vld1q_s8(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 int8_t a_[32];
    simde_vst1q_s8_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16x2_t c = {{a, b}};

    simde_test_arm_neon_write_i8x16x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    int8_t buf[32];
    simde_vst1q_s8_x2(buf, c);

    simde_test_codegen_write_vi8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[2][8];
    int16_t a[16];
  } test_vec[] = {
    {
        { {  INT16_C( 32680),  INT16_C( 26982),  INT16_C( 19099), -INT16_C(  2648), -INT16_C(  9446), -INT16_C( 11997), -INT16_C( 28364), -INT16_C(   682) },
          { -INT16_C(  4226), -INT16_C(  9219), -INT16_C(  6379), -INT16_C( 24238), -INT16_C( 22479), -INT16_C( 18734), -INT16_C( 31656),  INT16_C(    57) } },
      {  INT16_C( 32680),  INT16_C( 26982),  INT16_C( 19099), -INT16_C(  2648), -INT16_C(  9446), -INT16_C( 11997), -INT16_C( 28364), -INT16_C(   682),
        -INT16_C(  4226), -INT16_C(  9219), -INT16_C(  6379), -INT16_C( 24238), -INT16_C( 22479), -INT16_C( 18734), -INT16_C( 31656),  INT16_C(    57) } },
    {
        { { -INT16_C( 24829), -INT16_C( 24727),  INT16_C(  4841),  INT16_C(  1172), -INT16_C( 18451),  INT16_C(  8917),  INT16_C( 11337), -INT16_C( 14561) },
          {  INT16_C(  7195),  INT16_C( 12450), -INT16_C(  2813),  INT16_C( 13521), -INT16_C( 23651), -INT16_C(  2582),  INT16_C(  9000),  INT16_C( 11254) } },
      { -INT16_C( 24829), -INT16_C( 24727),  INT16_C(  4841),  INT16_C(  1172), -INT16_C( 18451),  INT16_C(  8917),  INT16_C( 11337), -INT16_C( 14561),
         INT16_C(  7195),  INT16_C( 12450), -INT16_C(  2813),  INT16_C( 13521), -INT16_C( 23651), -INT16_C(  2582),  INT16_C(  9000),  INT16_C( 11254) } },
    {
        { {  INT16_C( 24514), -INT16_C( 21302),  INT16_C( 24177),  INT16_C( 24496), -INT16_C( 31466),  INT16_C( 24449), -INT16_C( 24399), -INT16_C( 13274) },
          { -INT16_C( 14147), -INT16_C( 16132), -INT16_C( 12611),  INT16_C( 23285), -INT16_C(  8335), -INT16_C( 26288),  INT16_C( 17923), -INT16_C( 14907) } },
      {  INT16_C( 24514), -INT16_C( 21302),  INT16_C( 24177),  INT16_C( 24496), -INT16_C( 31466),  INT16_C( 24449), -INT16_C( 24399), -INT16_C( 13274),
        -INT16_C( 14147), -INT16_C( 16132), -INT16_C( 12611),  INT16_C( 23285), -INT16_C(  8335), -INT16_C( 26288),  INT16_C( 17923), -INT16_C( 14907) } },
    {
        { { -INT16_C( 28763),  INT16_C(  6001),  INT16_C(  8686),  INT16_C(  1142), -INT16_C(  2137),  INT16_C( 22627), -INT16_C( 30313),  INT16_C( 21541) },
          {  INT16_C(  8529),  INT16_C(  3861),  INT16_C(  2799),  INT16_C( 24937), -INT16_C( 17943), -INT16_C(  4870), -INT16_C( 16385), -INT16_C( 23118) } },
      { -INT16_C( 28763),  INT16_C(  6001),  INT16_C(  8686),  INT16_C(  1142), -INT16_C(  2137),  INT16_C( 22627), -INT16_C( 30313),  INT16_C( 21541),
         INT16_C(  8529),  INT16_C(  3861),  INT16_C(  2799),  INT16_C( 24937), -INT16_C( 17943), -INT16_C(  4870), -INT16_C( 16385), -INT16_C( 23118) } },
    {
        { {  INT16_C(  9039),  INT16_C( 15804),  INT16_C( 12869), -INT16_C(  5055), -INT16_C( 23511), -INT16_C( 16316),  INT16_C( 26925),  INT16_C( 32277) },
          {  INT16_C( 10891),  INT16_C( 31373), -INT16_C(  2252),  INT16_C(  7643), -INT16_C( 10576), -INT16_C( 20470), -INT16_C( 17259), -INT16_C(  7083) } },
      {  INT16_C(  9039),  INT16_C( 15804),  INT16_C( 12869), -INT16_C(  5055), -INT16_C( 23511), -INT16_C( 16316),  INT16_C( 26925),  INT16_C( 32277),
         INT16_C( 10891),  INT16_C( 31373), -INT16_C(  2252),  INT16_C(  7643), -INT16_C( 10576), -INT16_C( 20470), -INT16_C( 17259), -INT16_C(  7083) } },
    {
        { {  INT16_C(  4575),  INT16_C(  9249),  INT16_C( 25155),  INT16_C( 27664),  INT16_C( 21766),  INT16_C( 13100),  INT16_C( 16830),  INT16_C( 18866) },
          {  INT16_C( 16235), -INT16_C( 24636), -INT16_C( 24778), -INT16_C(  6211), -INT16_C( 14475),  INT16_C(  2967), -INT16_C(  4989),  INT16_C( 25327) } },
      {  INT16_C(  4575),  INT16_C(  9249),  INT16_C( 25155),  INT16_C( 27664),  INT16_C( 21766),  INT16_C( 13100),  INT16_C( 16830),  INT16_C( 18866),
         INT16_C( 16235), -INT16_C( 24636), -INT16_C( 24778), -INT16_C(  6211), -INT16_C( 14475),  INT16_C(  2967), -INT16_C(  4989),  INT16_C( 25327) } },
    {
        { {  INT16_C(  4605),  INT16_C( 16519), -INT16_C( 26765),  INT16_C( 31404), -INT16_C( 10004), -INT16_C( 21587),  INT16_C( 24346), -INT16_C( 31244) },
          { -INT16_C( 18273), -INT16_C( 10971), -INT16_C(  7592), -INT16_C( 12868),  INT16_C( 21417),  INT16_C( 11480), -INT16_C( 14273),  INT16_C( 15502) } },
      {  INT16_C(  4605),  INT16_C( 16519), -INT16_C( 26765),  INT16_C( 31404), -INT16_C( 10004), -INT16_C( 21587),  INT16_C( 24346), -INT16_C( 31244),
        -INT16_C( 18273), -INT16_C( 10971), -INT16_C(  7592), -INT16_C( 12868),  INT16_C( 21417),  INT16_C( 11480), -INT16_C( 14273),  INT16_C( 15502) } },
    {
        { {  INT16_C(  5593),  INT16_C( 19580),  INT16_C( 10413), -INT16_C( 26170),  INT16_C( 29697),  INT16_C(  6980),  INT16_C( 14803),  INT16_C( 29344) },
          { -INT16_C( 14863),  INT16_C( 18760),  INT16_C(  1191),  INT16_C( 20503), -INT16_C(  4264), -INT16_C( 26756),  INT16_C(  2999), -INT16_C( 28460) } },
      {  INT16_C(  5593),  INT16_C( 19580),  INT16_C( 10413), -INT16_C( 26170),  INT16_C( 29697),  INT16_C(  6980),  INT16_C( 14803),  INT16_C( 29344),
        -INT16_C( 14863),  INT16_C( 18760),  INT16_C(  1191),  INT16_C( 20503), -INT16_C(  4264), -INT16_C( 26756),  INT16_C(  2999), -INT16_C( 28460) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x2_t r_ = { { simde_vld1q_s16(test_vec[i].r[0]),
                               simde_vld1q_s16(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 int16_t a_[16];
    simde_vst1q_s16_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_i16x8x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    int16_t buf[16];
    simde_vst1q_s16_x2(buf, c);

    simde_test_codegen_write_vi16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[2][4];
    int32_t a[8];
  } test_vec[] = {
    {
        { { -INT32_C(   841134048),  INT32_C(  2053612409), -INT32_C(   342512873), -INT32_C(   698534428) },
          { -INT32_C(  1574984197),  INT32_C(    49493674), -INT32_C(   577147098), -INT32_C(  1687261830) } },
      { -INT32_C(   841134048),  INT32_C(  2053612409), -INT32_C(   342512873), -INT32_C(   698534428), -INT32_C(  1574984197),  INT32_C(    49493674), -INT32_C(   577147098), -INT32_C(  1687261830) } },
    {
        { {  INT32_C(   929582014),  INT32_C(   112316398),  INT32_C(  1609647739),  INT32_C(  1983204987) },
          { -INT32_C(  1642506764), -INT32_C(  1314911093), -INT32_C(   158385797),  INT32_C(  1704066471) } },
      {  INT32_C(   929582014),  INT32_C(   112316398),  INT32_C(  1609647739),  INT32_C(  1983204987), -INT32_C(  1642506764), -INT32_C(  1314911093), -INT32_C(   158385797),  INT32_C(  1704066471) } },
    {
        { {  INT32_C(   916257096),  INT32_C(  1144802761),  INT32_C(   245575059),  INT32_C(  1887820156) },
          { -INT32_C(  1190224338),  INT32_C(   627814058), -INT32_C(  1910768921),  INT32_C(  1072934135) } },
      {  INT32_C(   916257096),  INT32_C(  1144802761),  INT32_C(   245575059),  INT32_C(  1887820156), -INT32_C(  1190224338),  INT32_C(   627814058), -INT32_C(  1910768921),  INT32_C(  1072934135) } },
    {
        { {  INT32_C(  1869975462),  INT32_C(  1874047708),  INT32_C(  1535006431),  INT32_C(  1573585711) },
          {  INT32_C(  1259854241),  INT32_C(  1869644423),  INT32_C(  1945996412), -INT32_C(   558698184) } },
      {  INT32_C(  1869975462),  INT32_C(  1874047708),  INT32_C(  1535006431),  INT32_C(  1573585711),  INT32_C(  1259854241),  INT32_C(  1869644423),  INT32_C(  1945996412), -INT32_C(   558698184) } },
    {
        { {  INT32_C(  1565337472), -INT32_C(  1177812775), -INT32_C(  2045490601), -INT32_C(   286990259) },
          {  INT32_C(  1094319033), -INT32_C(   105862531),  INT32_C(  1852615990),  INT32_C(   525147806) } },
      {  INT32_C(  1565337472), -INT32_C(  1177812775), -INT32_C(  2045490601), -INT32_C(   286990259),  INT32_C(  1094319033), -INT32_C(   105862531),  INT32_C(  1852615990),  INT32_C(   525147806) } },
    {
        { {  INT32_C(   528259653), -INT32_C(   220706661), -INT32_C(   528946029), -INT32_C(  2033230644) },
          { -INT32_C(   725153705), -INT32_C(   389187662), -INT32_C(  1017693916), -INT32_C(  1646091177) } },
      {  INT32_C(   528259653), -INT32_C(   220706661), -INT32_C(   528946029), -INT32_C(  2033230644), -INT32_C(   725153705), -INT32_C(   389187662), -INT32_C(  1017693916), -INT32_C(  1646091177) } },
    {
        { { -INT32_C(   641966530),  INT32_C(   969643174),  INT32_C(  1293567104), -INT32_C(   120329824) },
          { -INT32_C(  1530094863),  INT32_C(   898406929),  INT32_C(   737731539), -INT32_C(   959915385) } },
      { -INT32_C(   641966530),  INT32_C(   969643174),  INT32_C(  1293567104), -INT32_C(   120329824), -INT32_C(  1530094863),  INT32_C(   898406929),  INT32_C(   737731539), -INT32_C(   959915385) } },
    {
        { { -INT32_C(   543194056), -INT32_C(  1743230184),  INT32_C(  1340420783),  INT32_C(   222803995) },
          {  INT32_C(  1672549458), -INT32_C(  2120663634), -INT32_C(  1465085663), -INT32_C(  1536265108) } },
      { -INT32_C(   543194056), -INT32_C(  1743230184),  INT32_C(  1340420783),  INT32_C(   222803995),  INT32_C(  1672549458), -INT32_C(  2120663634), -INT32_C(  1465085663), -INT32_C(  1536265108) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x2_t r_ = { { simde_vld1q_s32(test_vec[i].r[0]),
                               simde_vld1q_s32(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 int32_t a_[8];
    simde_vst1q_s32_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_i32x4x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    int32_t buf[8];
    simde_vst1q_s32_x2(buf, c);

    simde_test_codegen_write_vi32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[2][2];
    int64_t a[4];
  } test_vec[] = {
    {
        { {  INT64_C( 2930045076363218680), -INT64_C( 7352197551061758258) },
          {  INT64_C(  433074426653550803),  INT64_C( 2033407270396604199) } },
      {  INT64_C( 2930045076363218680), -INT64_C( 7352197551061758258),  INT64_C(  433074426653550803),  INT64_C( 2033407270396604199) } },
    {
        { {  INT64_C( 2795844041083501355), -INT64_C( 3007270938840382364) },
          { -INT64_C(   28330190206189137), -INT64_C( 7833789007332750840) } },
      {  INT64_C( 2795844041083501355), -INT64_C( 3007270938840382364), -INT64_C(   28330190206189137), -INT64_C( 7833789007332750840) } },
    {
        { { -INT64_C( 5907873566594468730), -INT64_C( 3953706261595745464) },
          { -INT64_C( 2686966923553507105), -INT64_C( 7476733964296239037) } },
      { -INT64_C( 5907873566594468730), -INT64_C( 3953706261595745464), -INT64_C( 2686966923553507105), -INT64_C( 7476733964296239037) } },
    {
        { { -INT64_C( 4487140517914184254), -INT64_C( 8038593618844576883) },
          {  INT64_C(  815429470462070693),  INT64_C( 7489472592495334980) } },
      { -INT64_C( 4487140517914184254), -INT64_C( 8038593618844576883),  INT64_C(  815429470462070693),  INT64_C( 7489472592495334980) } },
    {
        { {  INT64_C( 7755813043085469032), -INT64_C( 9186634209688310207) },
          {  INT64_C(  659293307359643987),  INT64_C( 3938765996896017309) } },
      {  INT64_C( 7755813043085469032), -INT64_C( 9186634209688310207),  INT64_C(  659293307359643987),  INT64_C( 3938765996896017309) } },
    {
        { { -INT64_C( 8287264009362137933), -INT64_C( 1746831969183985561) },
          { -INT64_C( 7090873630430414390), -INT64_C(  501720045708118268) } },
      { -INT64_C( 8287264009362137933), -INT64_C( 1746831969183985561), -INT64_C( 7090873630430414390), -INT64_C(  501720045708118268) } },
    {
        { {  INT64_C( 4718516608015474853), -INT64_C( 4245409029095621991) },
          {  INT64_C( 4944367729828436223), -INT64_C( 6187066256540599069) } },
      {  INT64_C( 4718516608015474853), -INT64_C( 4245409029095621991),  INT64_C( 4944367729828436223), -INT64_C( 6187066256540599069) } },
    {
        { { -INT64_C( 3360787895511568832),  INT64_C( 2796476047246221327) },
          { -INT64_C(  958771874141756628),  INT64_C( 3021422666819881023) } },
      { -INT64_C( 3360787895511568832),  INT64_C( 2796476047246221327), -INT64_C(  958771874141756628),  INT64_C( 3021422666819881023) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x2_t r_ = { { simde_vld1q_s64(test_vec[i].r[0]),
                               simde_vld1q_s64(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 int64_t a_[4];
    simde_vst1q_s64_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_i64x2x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    int64_t buf[4];
    simde_vst1q_s64_x2(buf, c);

    simde_test_codegen_write_vi64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[2][16];
    uint8_t a[32];
  } test_vec[] = {
    {
        { { UINT8_C(237), UINT8_C(135), UINT8_C( 67), UINT8_C( 37), UINT8_C(156), UINT8_C(159), UINT8_C(246), UINT8_C(171),
            UINT8_C(127), UINT8_C(245), UINT8_C(181), UINT8_C(166), UINT8_C(  9), UINT8_C(132), UINT8_C(204), UINT8_C( 54) },
          { UINT8_C(167), UINT8_C(241), UINT8_C(163), UINT8_C(182), UINT8_C(180), UINT8_C( 84), UINT8_C(169), UINT8_C(243),
            UINT8_C( 29), UINT8_C(197), UINT8_C( 55), UINT8_C(  5), UINT8_C(  4), UINT8_C( 37), UINT8_C( 46), UINT8_C(241) } },
      { UINT8_C(237), UINT8_C(135), UINT8_C( 67), UINT8_C( 37), UINT8_C(156), UINT8_C(159), UINT8_C(246), UINT8_C(171),
        UINT8_C(127), UINT8_C(245), UINT8_C(181), UINT8_C(166), UINT8_C(  9), UINT8_C(132), UINT8_C(204), UINT8_C( 54),
        UINT8_C(167), UINT8_C(241), UINT8_C(163), UINT8_C(182), UINT8_C(180), UINT8_C( 84), UINT8_C(169), UINT8_C(243),
        UINT8_C( 29), UINT8_C(197), UINT8_C( 55), UINT8_C(  5), UINT8_C(  4), UINT8_C( 37), UINT8_C( 46), UINT8_C(241) } },
    {
        { { UINT8_C(172), UINT8_C(114), UINT8_C( 22), UINT8_C( 73), UINT8_C( 17), UINT8_C( 12), UINT8_C(244), UINT8_C(145),
            UINT8_C(  1), UINT8_C(170), UINT8_C( 55), UINT8_C( 11), UINT8_C( 46), UINT8_C(  3), UINT8_C( 65), UINT8_C(214) },
          { UINT8_C(244), UINT8_C(228), UINT8_C(140), UINT8_C(168), UINT8_C( 56), UINT8_C( 53), UINT8_C(155), UINT8_C( 85),
            UINT8_C(250), UINT8_C(210), UINT8_C( 91), UINT8_C(254), UINT8_C(247), UINT8_C(137), UINT8_C(240), UINT8_C(164) } },
      { UINT8_C(172), UINT8_C(114), UINT8_C( 22), UINT8_C( 73), UINT8_C( 17), UINT8_C( 12), UINT8_C(244), UINT8_C(145),
        UINT8_C(  1), UINT8_C(170), UINT8_C( 55), UINT8_C( 11), UINT8_C( 46), UINT8_C(  3), UINT8_C( 65), UINT8_C(214),
        UINT8_C(244), UINT8_C(228), UINT8_C(140), UINT8_C(168), UINT8_C( 56), UINT8_C( 53), UINT8_C(155), UINT8_C( 85),
        UINT8_C(250), UINT8_C(210), UINT8_C( 91), UINT8_C(254), UINT8_C(247), UINT8_C(137), UINT8_C(240), UINT8_C(164) } },
    {
        { { UINT8_C(251), UINT8_C(  6), UINT8_C(237), UINT8_C( 13), UINT8_C( 19), UINT8_C(225), UINT8_C(158), UINT8_C( 20),
            UINT8_C(139), UINT8_C(213), UINT8_C( 31), UINT8_C(186), UINT8_C(216), UINT8_C( 96), UINT8_C(144), UINT8_C(204) },
          { UINT8_C( 68), UINT8_C( 28), UINT8_C(117), UINT8_C(125), UINT8_C( 82), UINT8_C( 16), UINT8_C(210), UINT8_C( 76),
            UINT8_C(227), UINT8_C( 45), UINT8_C( 75), UINT8_C(218), UINT8_C(183), UINT8_C( 59), UINT8_C(126), UINT8_C(178) } },
      { UINT8_C(251), UINT8_C(  6), UINT8_C(237), UINT8_C( 13), UINT8_C( 19), UINT8_C(225), UINT8_C(158), UINT8_C( 20),
        UINT8_C(139), UINT8_C(213), UINT8_C( 31), UINT8_C(186), UINT8_C(216), UINT8_C( 96), UINT8_C(144), UINT8_C(204),
        UINT8_C( 68), UINT8_C( 28), UINT8_C(117), UINT8_C(125), UINT8_C( 82), UINT8_C( 16), UINT8_C(210), UINT8_C( 76),
        UINT8_C(227), UINT8_C( 45), UINT8_C( 75), UINT8_C(218), UINT8_C(183), UINT8_C( 59), UINT8_C(126), UINT8_C(178) } },
    {
        { { UINT8_C( 65), UINT8_C(107), UINT8_C(191), UINT8_C( 84), UINT8_C( 77), UINT8_C( 93), UINT8_C(105), UINT8_C(216),
            UINT8_C( 50), UINT8_C(136), UINT8_C(146), UINT8_C( 10), UINT8_C(233), UINT8_C( 34), UINT8_C(215), UINT8_C( 45) },
          { UINT8_C( 63), UINT8_C( 76), UINT8_C(170), UINT8_C(145), UINT8_C( 92), UINT8_C(125), UINT8_C(221), UINT8_C( 63),
            UINT8_C(170), UINT8_C( 40), UINT8_C( 26), UINT8_C( 97), UINT8_C( 99), UINT8_C(152), UINT8_C( 20), UINT8_C(165) } },
      { UINT8_C( 65), UINT8_C(107), UINT8_C(191), UINT8_C( 84), UINT8_C( 77), UINT8_C( 93), UINT8_C(105), UINT8_C(216),
        UINT8_C( 50), UINT8_C(136), UINT8_C(146), UINT8_C( 10), UINT8_C(233), UINT8_C( 34), UINT8_C(215), UINT8_C( 45),
        UINT8_C( 63), UINT8_C( 76), UINT8_C(170), UINT8_C(145), UINT8_C( 92), UINT8_C(125), UINT8_C(221), UINT8_C( 63),
        UINT8_C(170), UINT8_C( 40), UINT8_C( 26), UINT8_C( 97), UINT8_C( 99), UINT8_C(152), UINT8_C( 20), UINT8_C(165) } },
    {
        { { UINT8_C(  4), UINT8_C(211), UINT8_C(249), UINT8_C( 81), UINT8_C( 49), UINT8_C( 98), UINT8_C( 41), UINT8_C( 99),
            UINT8_C(235), UINT8_C(188), UINT8_C(110), UINT8_C(212), UINT8_C(222), UINT8_C( 69), UINT8_C(  1), UINT8_C( 29) },
          { UINT8_C(145), UINT8_C(172), UINT8_C(174), UINT8_C(237), UINT8_C( 41), UINT8_C(140), UINT8_C( 45), UINT8_C(211),
            UINT8_C(180), UINT8_C( 71), UINT8_C( 53), UINT8_C( 24), UINT8_C(223), UINT8_C( 73), UINT8_C(189), UINT8_C(227) } },
      { UINT8_C(  4), UINT8_C(211), UINT8_C(249), UINT8_C( 81), UINT8_C( 49), UINT8_C( 98), UINT8_C( 41), UINT8_C( 99),
        UINT8_C(235), UINT8_C(188), UINT8_C(110), UINT8_C(212), UINT8_C(222), UINT8_C( 69), UINT8_C(  1), UINT8_C( 29),
        UINT8_C(145), UINT8_C(172), UINT8_C(174), UINT8_C(237), UINT8_C( 41), UINT8_C(140), UINT8_C( 45), UINT8_C(211),
        UINT8_C(180), UINT8_C( 71), UINT8_C( 53), UINT8_C( 24), UINT8_C(223), UINT8_C( 73), UINT8_C(189), UINT8_C(227) } },
    {
        { { UINT8_C( 28), UINT8_C(182), UINT8_C( 52), UINT8_C( 77), UINT8_C( 25), UINT8_C( 94), UINT8_C(177), UINT8_C(  4),
            UINT8_C( 26), UINT8_C( 31), UINT8_C(216), UINT8_C(248), UINT8_C(100), UINT8_C(217), UINT8_C( 22), UINT8_C(245) },
          { UINT8_C(133), UINT8_C(196), UINT8_C(226), UINT8_C(174), UINT8_C( 80), UINT8_C( 15), UINT8_C(130), UINT8_C(  5),
            UINT8_C( 86), UINT8_C(183), UINT8_C( 29), UINT8_C( 54), UINT8_C(  0), UINT8_C(218), UINT8_C( 25), UINT8_C( 28) } },
      { UINT8_C( 28), UINT8_C(182), UINT8_C( 52), UINT8_C( 77), UINT8_C( 25), UINT8_C( 94), UINT8_C(177), UINT8_C(  4),
        UINT8_C( 26), UINT8_C( 31), UINT8_C(216), UINT8_C(248), UINT8_C(100), UINT8_C(217), UINT8_C( 22), UINT8_C(245),
        UINT8_C(133), UINT8_C(196), UINT8_C(226), UINT8_C(174), UINT8_C( 80), UINT8_C( 15), UINT8_C(130), UINT8_C(  5),
        UINT8_C( 86), UINT8_C(183), UINT8_C( 29), UINT8_C( 54), UINT8_C(  0), UINT8_C(218), UINT8_C( 25), UINT8_C( 28) } },
    {
        { { UINT8_C(144), UINT8_C( 78), UINT8_C(106), UINT8_C(169), UINT8_C(172), UINT8_C( 27), UINT8_C(173), UINT8_C(198),
            UINT8_C( 58), UINT8_C(133), UINT8_C(190), UINT8_C(158), UINT8_C( 95), UINT8_C(212), UINT8_C(147), UINT8_C(228) },
          { UINT8_C(153), UINT8_C(117), UINT8_C(147), UINT8_C(233), UINT8_C(133), UINT8_C( 21), UINT8_C(238), UINT8_C(219),
            UINT8_C(204), UINT8_C( 11), UINT8_C( 17), UINT8_C(204), UINT8_C(229), UINT8_C( 43), UINT8_C(232), UINT8_C(118) } },
      { UINT8_C(144), UINT8_C( 78), UINT8_C(106), UINT8_C(169), UINT8_C(172), UINT8_C( 27), UINT8_C(173), UINT8_C(198),
        UINT8_C( 58), UINT8_C(133), UINT8_C(190), UINT8_C(158), UINT8_C( 95), UINT8_C(212), UINT8_C(147), UINT8_C(228),
        UINT8_C(153), UINT8_C(117), UINT8_C(147), UINT8_C(233), UINT8_C(133), UINT8_C( 21), UINT8_C(238), UINT8_C(219),
        UINT8_C(204), UINT8_C( 11), UINT8_C( 17), UINT8_C(204), UINT8_C(229), UINT8_C( 43), UINT8_C(232), UINT8_C(118) } },
    {
        { { UINT8_C(121), UINT8_C( 82), UINT8_C( 31), UINT8_C( 37), UINT8_C(109), UINT8_C(205), UINT8_C(235), UINT8_C(167),
            UINT8_C( 82), UINT8_C(169), UINT8_C( 69), UINT8_C(177), UINT8_C(126), UINT8_C(216), UINT8_C(150), UINT8_C( 23) },
          { UINT8_C( 78), UINT8_C( 41), UINT8_C(  0), UINT8_C(211), UINT8_C( 62), UINT8_C(239), UINT8_C(174), UINT8_C( 10),
            UINT8_C(250), UINT8_C(192), UINT8_C(214), UINT8_C(224), UINT8_C(235), UINT8_C(190), UINT8_C( 86), UINT8_C(100) } },
      { UINT8_C(121), UINT8_C( 82), UINT8_C( 31), UINT8_C( 37), UINT8_C(109), UINT8_C(205), UINT8_C(235), UINT8_C(167),
        UINT8_C( 82), UINT8_C(169), UINT8_C( 69), UINT8_C(177), UINT8_C(126), UINT8_C(216), UINT8_C(150), UINT8_C( 23),
        UINT8_C( 78), UINT8_C( 41), UINT8_C(  0), UINT8_C(211), UINT8_C( 62), UINT8_C(239), UINT8_C(174), UINT8_C( 10),
        UINT8_C(250), UINT8_C(192), UINT8_C(214), UINT8_C(224), UINT8_C(235), UINT8_C(190), UINT8_C( 86), UINT8_C(100) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x2_t r_ = { { simde_vld1q_u8(test_vec[i].r[0]),
                                simde_vld1q_u8(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 uint8_t a_[32];
    simde_vst1q_u8_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x16x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    uint8_t buf[32];
    simde_vst1q_u8_x2(buf, c);

    simde_test_codegen_write_vu8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[2][8];
    uint16_t a[16];
  } test_vec[] = {
    {
        { { UINT16_C(29969), UINT16_C(32393), UINT16_C(29762), UINT16_C(38182), UINT16_C(27421), UINT16_C(39750), UINT16_C(56388), UINT16_C(37554) },
          { UINT16_C(45829), UINT16_C(17253), UINT16_C( 5026), UINT16_C(40013), UINT16_C( 9171), UINT16_C(48764), UINT16_C(53986), UINT16_C(62242) } },
      { UINT16_C(29969), UINT16_C(32393), UINT16_C(29762), UINT16_C(38182), UINT16_C(27421), UINT16_C(39750), UINT16_C(56388), UINT16_C(37554),
        UINT16_C(45829), UINT16_C(17253), UINT16_C( 5026), UINT16_C(40013), UINT16_C( 9171), UINT16_C(48764), UINT16_C(53986), UINT16_C(62242) } },
    {
        { { UINT16_C(43848), UINT16_C(35441), UINT16_C(38687), UINT16_C(15647), UINT16_C(26115), UINT16_C(18392), UINT16_C(35650), UINT16_C(18649) },
          { UINT16_C(15934), UINT16_C(57483), UINT16_C(55633), UINT16_C( 9596), UINT16_C(63996), UINT16_C(57059), UINT16_C( 1739), UINT16_C( 5073) } },
      { UINT16_C(43848), UINT16_C(35441), UINT16_C(38687), UINT16_C(15647), UINT16_C(26115), UINT16_C(18392), UINT16_C(35650), UINT16_C(18649),
        UINT16_C(15934), UINT16_C(57483), UINT16_C(55633), UINT16_C( 9596), UINT16_C(63996), UINT16_C(57059), UINT16_C( 1739), UINT16_C( 5073) } },
    {
        { { UINT16_C(17329), UINT16_C(53662), UINT16_C(48602), UINT16_C(56590), UINT16_C(58915), UINT16_C(26148), UINT16_C(64881), UINT16_C(44974) },
          { UINT16_C(14651), UINT16_C(36239), UINT16_C( 3090), UINT16_C( 4018), UINT16_C(38149), UINT16_C(53485), UINT16_C(49051), UINT16_C(19940) } },
      { UINT16_C(17329), UINT16_C(53662), UINT16_C(48602), UINT16_C(56590), UINT16_C(58915), UINT16_C(26148), UINT16_C(64881), UINT16_C(44974),
        UINT16_C(14651), UINT16_C(36239), UINT16_C( 3090), UINT16_C( 4018), UINT16_C(38149), UINT16_C(53485), UINT16_C(49051), UINT16_C(19940) } },
    {
        { { UINT16_C(33282), UINT16_C(56350), UINT16_C(11327), UINT16_C(25530), UINT16_C(56850), UINT16_C(33993), UINT16_C(30684), UINT16_C( 5939) },
          { UINT16_C(50096), UINT16_C(50084), UINT16_C(22223), UINT16_C(54482), UINT16_C(49132), UINT16_C(34724), UINT16_C(34942), UINT16_C(32980) } },
      { UINT16_C(33282), UINT16_C(56350), UINT16_C(11327), UINT16_C(25530), UINT16_C(56850), UINT16_C(33993), UINT16_C(30684), UINT16_C( 5939),
        UINT16_C(50096), UINT16_C(50084), UINT16_C(22223), UINT16_C(54482), UINT16_C(49132), UINT16_C(34724), UINT16_C(34942), UINT16_C(32980) } },
    {
        { { UINT16_C(61962), UINT16_C(19037), UINT16_C( 5918), UINT16_C(12717), UINT16_C(30453), UINT16_C(53685), UINT16_C(59629), UINT16_C(40425) },
          { UINT16_C(36267), UINT16_C(31328), UINT16_C(13028), UINT16_C(53326), UINT16_C(62450), UINT16_C(28759), UINT16_C(11387), UINT16_C(34545) } },
      { UINT16_C(61962), UINT16_C(19037), UINT16_C( 5918), UINT16_C(12717), UINT16_C(30453), UINT16_C(53685), UINT16_C(59629), UINT16_C(40425),
        UINT16_C(36267), UINT16_C(31328), UINT16_C(13028), UINT16_C(53326), UINT16_C(62450), UINT16_C(28759), UINT16_C(11387), UINT16_C(34545) } },
    {
        { { UINT16_C(19998), UINT16_C(15824), UINT16_C(32101), UINT16_C(23150), UINT16_C( 9203), UINT16_C(57388), UINT16_C( 5387), UINT16_C(46973) },
          { UINT16_C(56994), UINT16_C(34353), UINT16_C(32784), UINT16_C(  598), UINT16_C(44659), UINT16_C(61043), UINT16_C(25818), UINT16_C(63604) } },
      { UINT16_C(19998), UINT16_C(15824), UINT16_C(32101), UINT16_C(23150), UINT16_C( 9203), UINT16_C(57388), UINT16_C( 5387), UINT16_C(46973),
        UINT16_C(56994), UINT16_C(34353), UINT16_C(32784), UINT16_C(  598), UINT16_C(44659), UINT16_C(61043), UINT16_C(25818), UINT16_C(63604) } },
    {
        { { UINT16_C(17586), UINT16_C( 5941), UINT16_C(41921), UINT16_C(46193), UINT16_C(40390), UINT16_C(53908), UINT16_C( 4786), UINT16_C(21897) },
          { UINT16_C(47856), UINT16_C(  219), UINT16_C(12858), UINT16_C(44291), UINT16_C(30432), UINT16_C(47772), UINT16_C( 4314), UINT16_C(36018) } },
      { UINT16_C(17586), UINT16_C( 5941), UINT16_C(41921), UINT16_C(46193), UINT16_C(40390), UINT16_C(53908), UINT16_C( 4786), UINT16_C(21897),
        UINT16_C(47856), UINT16_C(  219), UINT16_C(12858), UINT16_C(44291), UINT16_C(30432), UINT16_C(47772), UINT16_C( 4314), UINT16_C(36018) } },
    {
        { { UINT16_C(59477), UINT16_C( 5795), UINT16_C( 5259), UINT16_C(21195), UINT16_C(24498), UINT16_C(25636), UINT16_C(44401), UINT16_C(25017) },
          { UINT16_C(38247), UINT16_C(41570), UINT16_C(26055), UINT16_C(42831), UINT16_C(60379), UINT16_C(46433), UINT16_C( 5116), UINT16_C(20801) } },
      { UINT16_C(59477), UINT16_C( 5795), UINT16_C( 5259), UINT16_C(21195), UINT16_C(24498), UINT16_C(25636), UINT16_C(44401), UINT16_C(25017),
        UINT16_C(38247), UINT16_C(41570), UINT16_C(26055), UINT16_C(42831), UINT16_C(60379), UINT16_C(46433), UINT16_C( 5116), UINT16_C(20801) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x2_t r_ = { { simde_vld1q_u16(test_vec[i].r[0]),
                                simde_vld1q_u16(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 uint16_t a_[16];
    simde_vst1q_u16_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u16x8x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    uint16_t buf[16];
    simde_vst1q_u16_x2(buf, c);

    simde_test_codegen_write_vu16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[2][4];
    uint32_t a[8];
  } test_vec[] = {
    {
        { { UINT32_C(2271732987), UINT32_C(2866361080), UINT32_C(  51379602), UINT32_C( 291883178) },
          { UINT32_C( 615761757), UINT32_C( 130745132), UINT32_C(3938200814), UINT32_C( 993787200) } },
      { UINT32_C(2271732987), UINT32_C(2866361080), UINT32_C(  51379602), UINT32_C( 291883178), UINT32_C( 615761757), UINT32_C( 130745132), UINT32_C(3938200814), UINT32_C( 993787200) } },
    {
        { { UINT32_C(3653411809), UINT32_C(1736743893), UINT32_C(1114346392), UINT32_C(3109343323) },
          { UINT32_C(3286042519), UINT32_C(4190808330), UINT32_C( 367232725), UINT32_C(1683038083) } },
      { UINT32_C(3653411809), UINT32_C(1736743893), UINT32_C(1114346392), UINT32_C(3109343323), UINT32_C(3286042519), UINT32_C(4190808330), UINT32_C( 367232725), UINT32_C(1683038083) } },
    {
        { { UINT32_C(2537362370), UINT32_C(1207943599), UINT32_C(2961861204), UINT32_C(3513376314) },
          { UINT32_C(4036249317), UINT32_C(3320405743), UINT32_C(1742392548), UINT32_C(2915773419) } },
      { UINT32_C(2537362370), UINT32_C(1207943599), UINT32_C(2961861204), UINT32_C(3513376314), UINT32_C(4036249317), UINT32_C(3320405743), UINT32_C(1742392548), UINT32_C(2915773419) } },
    {
        { { UINT32_C(3997501503), UINT32_C( 506807498), UINT32_C(3905863598), UINT32_C(2209953693) },
          { UINT32_C(1836273022), UINT32_C(2402442411), UINT32_C( 351669544), UINT32_C(2009186616) } },
      { UINT32_C(3997501503), UINT32_C( 506807498), UINT32_C(3905863598), UINT32_C(2209953693), UINT32_C(1836273022), UINT32_C(2402442411), UINT32_C( 351669544), UINT32_C(2009186616) } },
    {
        { { UINT32_C(2472871625), UINT32_C(4172454730), UINT32_C(4175462490), UINT32_C( 914069944) },
          { UINT32_C(2443439846), UINT32_C(1914754634), UINT32_C( 461772515), UINT32_C(2710784215) } },
      { UINT32_C(2472871625), UINT32_C(4172454730), UINT32_C(4175462490), UINT32_C( 914069944), UINT32_C(2443439846), UINT32_C(1914754634), UINT32_C( 461772515), UINT32_C(2710784215) } },
    {
        { { UINT32_C(2570385486), UINT32_C(4002539155), UINT32_C( 535196263), UINT32_C(4065681675) },
          { UINT32_C(2575562831), UINT32_C(2970330318), UINT32_C(2462945978), UINT32_C( 674455770) } },
      { UINT32_C(2570385486), UINT32_C(4002539155), UINT32_C( 535196263), UINT32_C(4065681675), UINT32_C(2575562831), UINT32_C(2970330318), UINT32_C(2462945978), UINT32_C( 674455770) } },
    {
        { { UINT32_C(3972097880), UINT32_C(3050984270), UINT32_C(3503603909), UINT32_C(1891772705) },
          { UINT32_C(4027139617), UINT32_C(2762020074), UINT32_C(2151050918), UINT32_C( 665414094) } },
      { UINT32_C(3972097880), UINT32_C(3050984270), UINT32_C(3503603909), UINT32_C(1891772705), UINT32_C(4027139617), UINT32_C(2762020074), UINT32_C(2151050918), UINT32_C( 665414094) } },
    {
        { { UINT32_C( 521366225), UINT32_C(2194992573), UINT32_C(3461589165), UINT32_C(4064155089) },
          { UINT32_C(1172457307), UINT32_C(  48923739), UINT32_C(3246530802), UINT32_C(1541942154) } },
      { UINT32_C( 521366225), UINT32_C(2194992573), UINT32_C(3461589165), UINT32_C(4064155089), UINT32_C(1172457307), UINT32_C(  48923739), UINT32_C(3246530802), UINT32_C(1541942154) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x2_t r_ = { { simde_vld1q_u32(test_vec[i].r[0]),
                                simde_vld1q_u32(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 uint32_t a_[8];
    simde_vst1q_u32_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_u32x4x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    uint32_t buf[8];
    simde_vst1q_u32_x2(buf, c);

    simde_test_codegen_write_vu32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[2][2];
    uint64_t a[4];
  } test_vec[] = {
    {
        { { UINT64_C(10796903916407290774), UINT64_C(11149119643537582582) },
          { UINT64_C( 1316679606490602728), UINT64_C( 9930362357686716650) } },
      { UINT64_C(10796903916407290774), UINT64_C(11149119643537582582), UINT64_C( 1316679606490602728), UINT64_C( 9930362357686716650) } },
    {
        { { UINT64_C(10174673446946818486), UINT64_C( 2284465441299797724) },
          { UINT64_C( 5178198792333399209), UINT64_C( 2444762366588202864) } },
      { UINT64_C(10174673446946818486), UINT64_C( 2284465441299797724), UINT64_C( 5178198792333399209), UINT64_C( 2444762366588202864) } },
    {
        { { UINT64_C( 6482917908610599635), UINT64_C(  207491423798578058) },
          { UINT64_C( 6728845050283574460), UINT64_C( 8927452396905373015) } },
      { UINT64_C( 6482917908610599635), UINT64_C(  207491423798578058), UINT64_C( 6728845050283574460), UINT64_C( 8927452396905373015) } },
    {
        { { UINT64_C( 2400662246140519545), UINT64_C(12215104609406141480) },
          { UINT64_C( 5715390053786800136), UINT64_C( 4207759264570282561) } },
      { UINT64_C( 2400662246140519545), UINT64_C(12215104609406141480), UINT64_C( 5715390053786800136), UINT64_C( 4207759264570282561) } },
    {
        { { UINT64_C( 5716053253585652122), UINT64_C(  205570166553065028) },
          { UINT64_C(  282680873016794532), UINT64_C(10256192735776931418) } },
      { UINT64_C( 5716053253585652122), UINT64_C(  205570166553065028), UINT64_C(  282680873016794532), UINT64_C(10256192735776931418) } },
    {
        { { UINT64_C( 5408561497708136089), UINT64_C(15583675393062526792) },
          { UINT64_C(15976345421416315891), UINT64_C(10223539436100625247) } },
      { UINT64_C( 5408561497708136089), UINT64_C(15583675393062526792), UINT64_C(15976345421416315891), UINT64_C(10223539436100625247) } },
    {
        { { UINT64_C(18097254080183115988), UINT64_C(16953944800766108219) },
          { UINT64_C( 9015739291487157693), UINT64_C( 4214156927691659258) } },
      { UINT64_C(18097254080183115988), UINT64_C(16953944800766108219), UINT64_C( 9015739291487157693), UINT64_C( 4214156927691659258) } },
    {
        { { UINT64_C( 6845536459476551761), UINT64_C( 9133326161295654621) },
          { UINT64_C(12785680545442848724), UINT64_C( 4725150053639864307) } },
      { UINT64_C( 6845536459476551761), UINT64_C( 9133326161295654621), UINT64_C(12785680545442848724), UINT64_C( 4725150053639864307) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x2_t r_ = { { simde_vld1q_u64(test_vec[i].r[0]),
                                simde_vld1q_u64(test_vec[i].r[1]) } };

    SIMDE_ALIGN_TO_16 uint64_t a_[4];
    simde_vst1q_u64_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_u64x2x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    uint64_t buf[4];
    simde_vst1q_u64_x2(buf, c);

    simde_test_codegen_write_vu64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_p8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_TO_16 simde_poly8_t val[2][16];
    SIMDE_ALIGN_TO_16 simde_poly8_t r[32];
  } test_vec[] = {
  { { {  SIMDE_POLY8_C( 229),  SIMDE_POLY8_C( 251),  SIMDE_POLY8_C( 226),  SIMDE_POLY8_C(  25),
         SIMDE_POLY8_C( 128),  SIMDE_POLY8_C( 234),  SIMDE_POLY8_C( 174),  SIMDE_POLY8_C( 245),
         SIMDE_POLY8_C(  50),  SIMDE_POLY8_C(  43),  SIMDE_POLY8_C( 222),  SIMDE_POLY8_C(  15),
         SIMDE_POLY8_C(  98),  SIMDE_POLY8_C( 159),  SIMDE_POLY8_C( 224),  SIMDE_POLY8_C(  97)  },
      {  SIMDE_POLY8_C( 254),  SIMDE_POLY8_C(  94),  SIMDE_POLY8_C(  11),  SIMDE_POLY8_C( 240),
         SIMDE_POLY8_C( 156),  SIMDE_POLY8_C( 231),  SIMDE_POLY8_C( 200),  SIMDE_POLY8_C( 178),
         SIMDE_POLY8_C( 215),  SIMDE_POLY8_C(  20),  SIMDE_POLY8_C( 232),  SIMDE_POLY8_C( 197),
         SIMDE_POLY8_C( 141),  SIMDE_POLY8_C(  50),  SIMDE_POLY8_C( 191),  SIMDE_POLY8_C( 242)  } },
      {  SIMDE_POLY8_C( 229),  SIMDE_POLY8_C( 251),  SIMDE_POLY8_C( 226),  SIMDE_POLY8_C(  25),
         SIMDE_POLY8_C( 128),  SIMDE_POLY8_C( 234),  SIMDE_POLY8_C( 174),  SIMDE_POLY8_C( 245),
         SIMDE_POLY8_C(  50),  SIMDE_POLY8_C(  43),  SIMDE_POLY8_C( 222),  SIMDE_POLY8_C(  15),
         SIMDE_POLY8_C(  98),  SIMDE_POLY8_C( 159),  SIMDE_POLY8_C( 224),  SIMDE_POLY8_C(  97),
         SIMDE_POLY8_C( 254),  SIMDE_POLY8_C(  94),  SIMDE_POLY8_C(  11),  SIMDE_POLY8_C( 240),
         SIMDE_POLY8_C( 156),  SIMDE_POLY8_C( 231),  SIMDE_POLY8_C( 200),  SIMDE_POLY8_C( 178),
         SIMDE_POLY8_C( 215),  SIMDE_POLY8_C(  20),  SIMDE_POLY8_C( 232),  SIMDE_POLY8_C( 197),
         SIMDE_POLY8_C( 141),  SIMDE_POLY8_C(  50),  SIMDE_POLY8_C( 191),  SIMDE_POLY8_C( 242) } },
  { { {  SIMDE_POLY8_C( 194),  SIMDE_POLY8_C(  82),  SIMDE_POLY8_C( 230),  SIMDE_POLY8_C(  67),
         SIMDE_POLY8_C( 129),  SIMDE_POLY8_C( 126),  SIMDE_POLY8_C(  50),  SIMDE_POLY8_C( 125),
         SIMDE_POLY8_C( 160),  SIMDE_POLY8_C( 181),  SIMDE_POLY8_C(  11),  SIMDE_POLY8_C(  41),
         SIMDE_POLY8_C( 151),  SIMDE_POLY8_C(  11),  SIMDE_POLY8_C( 202),  SIMDE_POLY8_C( 243)  },
      {  SIMDE_POLY8_C(  93),  SIMDE_POLY8_C( 200),  SIMDE_POLY8_C(  14),  SIMDE_POLY8_C( 178),
         SIMDE_POLY8_C( 154),  SIMDE_POLY8_C(  86),  SIMDE_POLY8_C(  88),  SIMDE_POLY8_C( 154),
         SIMDE_POLY8_C(  15),  SIMDE_POLY8_C(  26),  SIMDE_POLY8_C( 199),  SIMDE_POLY8_C(  93),
         SIMDE_POLY8_C( 111),  SIMDE_POLY8_C(  90),  SIMDE_POLY8_C(   4),  SIMDE_POLY8_C( 133)  } },
      {  SIMDE_POLY8_C( 194),  SIMDE_POLY8_C(  82),  SIMDE_POLY8_C( 230),  SIMDE_POLY8_C(  67),
         SIMDE_POLY8_C( 129),  SIMDE_POLY8_C( 126),  SIMDE_POLY8_C(  50),  SIMDE_POLY8_C( 125),
         SIMDE_POLY8_C( 160),  SIMDE_POLY8_C( 181),  SIMDE_POLY8_C(  11),  SIMDE_POLY8_C(  41),
         SIMDE_POLY8_C( 151),  SIMDE_POLY8_C(  11),  SIMDE_POLY8_C( 202),  SIMDE_POLY8_C( 243),
         SIMDE_POLY8_C(  93),  SIMDE_POLY8_C( 200),  SIMDE_POLY8_C(  14),  SIMDE_POLY8_C( 178),
         SIMDE_POLY8_C( 154),  SIMDE_POLY8_C(  86),  SIMDE_POLY8_C(  88),  SIMDE_POLY8_C( 154),
         SIMDE_POLY8_C(  15),  SIMDE_POLY8_C(  26),  SIMDE_POLY8_C( 199),  SIMDE_POLY8_C(  93),
         SIMDE_POLY8_C( 111),  SIMDE_POLY8_C(  90),  SIMDE_POLY8_C(   4),  SIMDE_POLY8_C( 133) } },
  { { {  SIMDE_POLY8_C( 227),  SIMDE_POLY8_C(  30),  SIMDE_POLY8_C( 219),  SIMDE_POLY8_C(  78),
         SIMDE_POLY8_C( 246),  SIMDE_POLY8_C( 177),  SIMDE_POLY8_C( 105),  SIMDE_POLY8_C(  37),
         SIMDE_POLY8_C( 149),  SIMDE_POLY8_C(  85),  SIMDE_POLY8_C( 209),  SIMDE_POLY8_C(  46),
         SIMDE_POLY8_C( 137),  SIMDE_POLY8_C( 122),  SIMDE_POLY8_C( 106),  SIMDE_POLY8_C( 151)  },
      {  SIMDE_POLY8_C( 188),  SIMDE_POLY8_C(  79),  SIMDE_POLY8_C( 242),  SIMDE_POLY8_C(   4),
         SIMDE_POLY8_C( 216),  SIMDE_POLY8_C( 214),  SIMDE_POLY8_C( 193),  SIMDE_POLY8_C(  38),
         SIMDE_POLY8_C(  51),  SIMDE_POLY8_C(  54),  SIMDE_POLY8_C( 174),  SIMDE_POLY8_C(  30),
         SIMDE_POLY8_C(  27),  SIMDE_POLY8_C( 142),  SIMDE_POLY8_C( 168),  SIMDE_POLY8_C(  68)  } },
      {  SIMDE_POLY8_C( 227),  SIMDE_POLY8_C(  30),  SIMDE_POLY8_C( 219),  SIMDE_POLY8_C(  78),
         SIMDE_POLY8_C( 246),  SIMDE_POLY8_C( 177),  SIMDE_POLY8_C( 105),  SIMDE_POLY8_C(  37),
         SIMDE_POLY8_C( 149),  SIMDE_POLY8_C(  85),  SIMDE_POLY8_C( 209),  SIMDE_POLY8_C(  46),
         SIMDE_POLY8_C( 137),  SIMDE_POLY8_C( 122),  SIMDE_POLY8_C( 106),  SIMDE_POLY8_C( 151),
         SIMDE_POLY8_C( 188),  SIMDE_POLY8_C(  79),  SIMDE_POLY8_C( 242),  SIMDE_POLY8_C(   4),
         SIMDE_POLY8_C( 216),  SIMDE_POLY8_C( 214),  SIMDE_POLY8_C( 193),  SIMDE_POLY8_C(  38),
         SIMDE_POLY8_C(  51),  SIMDE_POLY8_C(  54),  SIMDE_POLY8_C( 174),  SIMDE_POLY8_C(  30),
         SIMDE_POLY8_C(  27),  SIMDE_POLY8_C( 142),  SIMDE_POLY8_C( 168),  SIMDE_POLY8_C(  68) } },
  { { {  SIMDE_POLY8_C( 186),  SIMDE_POLY8_C( 122),  SIMDE_POLY8_C( 214),  SIMDE_POLY8_C( 112),
         SIMDE_POLY8_C( 221),  SIMDE_POLY8_C( 198),  SIMDE_POLY8_C( 166),  SIMDE_POLY8_C( 205),
         SIMDE_POLY8_C(  30),  SIMDE_POLY8_C(  93),  SIMDE_POLY8_C(   7),  SIMDE_POLY8_C(  27),
         SIMDE_POLY8_C(  49),  SIMDE_POLY8_C( 204),  SIMDE_POLY8_C( 135),  SIMDE_POLY8_C( 245)  },
      {  SIMDE_POLY8_C( 216),  SIMDE_POLY8_C(  55),  SIMDE_POLY8_C(  55),  SIMDE_POLY8_C( 191),
         SIMDE_POLY8_C( 139),  SIMDE_POLY8_C(  76),  SIMDE_POLY8_C(  67),  SIMDE_POLY8_C( 225),
         SIMDE_POLY8_C(  45),  SIMDE_POLY8_C( 143),  SIMDE_POLY8_C(  93),  SIMDE_POLY8_C( 215),
         SIMDE_POLY8_C( 147),  SIMDE_POLY8_C( 148),  SIMDE_POLY8_C( 195),  SIMDE_POLY8_C( 222)  } },
      {  SIMDE_POLY8_C( 186),  SIMDE_POLY8_C( 122),  SIMDE_POLY8_C( 214),  SIMDE_POLY8_C( 112),
         SIMDE_POLY8_C( 221),  SIMDE_POLY8_C( 198),  SIMDE_POLY8_C( 166),  SIMDE_POLY8_C( 205),
         SIMDE_POLY8_C(  30),  SIMDE_POLY8_C(  93),  SIMDE_POLY8_C(   7),  SIMDE_POLY8_C(  27),
         SIMDE_POLY8_C(  49),  SIMDE_POLY8_C( 204),  SIMDE_POLY8_C( 135),  SIMDE_POLY8_C( 245),
         SIMDE_POLY8_C( 216),  SIMDE_POLY8_C(  55),  SIMDE_POLY8_C(  55),  SIMDE_POLY8_C( 191),
         SIMDE_POLY8_C( 139),  SIMDE_POLY8_C(  76),  SIMDE_POLY8_C(  67),  SIMDE_POLY8_C( 225),
         SIMDE_POLY8_C(  45),  SIMDE_POLY8_C( 143),  SIMDE_POLY8_C(  93),  SIMDE_POLY8_C( 215),
         SIMDE_POLY8_C( 147),  SIMDE_POLY8_C( 148),  SIMDE_POLY8_C( 195),  SIMDE_POLY8_C( 222) } },
  { { {  SIMDE_POLY8_C( 199),  SIMDE_POLY8_C( 123),  SIMDE_POLY8_C( 132),  SIMDE_POLY8_C( 176),
         SIMDE_POLY8_C(  52),  SIMDE_POLY8_C(  83),  SIMDE_POLY8_C(  53),  SIMDE_POLY8_C(  78),
         SIMDE_POLY8_C( 152),  SIMDE_POLY8_C(  99),  SIMDE_POLY8_C(   2),  SIMDE_POLY8_C( 190),
         SIMDE_POLY8_C( 198),  SIMDE_POLY8_C( 188),  SIMDE_POLY8_C( 102),  SIMDE_POLY8_C(  19)  },
      {  SIMDE_POLY8_C( 152),  SIMDE_POLY8_C( 217),  SIMDE_POLY8_C( 187),  SIMDE_POLY8_C( 104),
         SIMDE_POLY8_C(  98),  SIMDE_POLY8_C(  39),  SIMDE_POLY8_C( 130),  SIMDE_POLY8_C(  82),
         SIMDE_POLY8_C( 138),  SIMDE_POLY8_C(  27),  SIMDE_POLY8_C( 218),  SIMDE_POLY8_C( 217),
         SIMDE_POLY8_C( 186),  SIMDE_POLY8_C( 136),  SIMDE_POLY8_C(  50),  SIMDE_POLY8_C(  30)  } },
      {  SIMDE_POLY8_C( 199),  SIMDE_POLY8_C( 123),  SIMDE_POLY8_C( 132),  SIMDE_POLY8_C( 176),
         SIMDE_POLY8_C(  52),  SIMDE_POLY8_C(  83),  SIMDE_POLY8_C(  53),  SIMDE_POLY8_C(  78),
         SIMDE_POLY8_C( 152),  SIMDE_POLY8_C(  99),  SIMDE_POLY8_C(   2),  SIMDE_POLY8_C( 190),
         SIMDE_POLY8_C( 198),  SIMDE_POLY8_C( 188),  SIMDE_POLY8_C( 102),  SIMDE_POLY8_C(  19),
         SIMDE_POLY8_C( 152),  SIMDE_POLY8_C( 217),  SIMDE_POLY8_C( 187),  SIMDE_POLY8_C( 104),
         SIMDE_POLY8_C(  98),  SIMDE_POLY8_C(  39),  SIMDE_POLY8_C( 130),  SIMDE_POLY8_C(  82),
         SIMDE_POLY8_C( 138),  SIMDE_POLY8_C(  27),  SIMDE_POLY8_C( 218),  SIMDE_POLY8_C( 217),
         SIMDE_POLY8_C( 186),  SIMDE_POLY8_C( 136),  SIMDE_POLY8_C(  50),  SIMDE_POLY8_C(  30) } },
  { { {  SIMDE_POLY8_C( 142),  SIMDE_POLY8_C(  82),  SIMDE_POLY8_C( 116),  SIMDE_POLY8_C( 197),
         SIMDE_POLY8_C( 222),  SIMDE_POLY8_C(  35),  SIMDE_POLY8_C( 184),  SIMDE_POLY8_C(  94),
         SIMDE_POLY8_C(  57),  SIMDE_POLY8_C( 183),  SIMDE_POLY8_C( 229),  SIMDE_POLY8_C( 185),
         SIMDE_POLY8_C( 136),  SIMDE_POLY8_C( 171),  SIMDE_POLY8_C( 243),  SIMDE_POLY8_C( 253)  },
      {  SIMDE_POLY8_C( 157),  SIMDE_POLY8_C(  71),  SIMDE_POLY8_C( 147),  SIMDE_POLY8_C(  31),
         SIMDE_POLY8_C(  19),  SIMDE_POLY8_C( 134),  SIMDE_POLY8_C(  95),  SIMDE_POLY8_C(  78),
         SIMDE_POLY8_C( 231),  SIMDE_POLY8_C(   9),  SIMDE_POLY8_C(   0),  SIMDE_POLY8_C(  49),
         SIMDE_POLY8_C( 128),  SIMDE_POLY8_C(   4),  SIMDE_POLY8_C( 225),  SIMDE_POLY8_C( 172)  } },
      {  SIMDE_POLY8_C( 142),  SIMDE_POLY8_C(  82),  SIMDE_POLY8_C( 116),  SIMDE_POLY8_C( 197),
         SIMDE_POLY8_C( 222),  SIMDE_POLY8_C(  35),  SIMDE_POLY8_C( 184),  SIMDE_POLY8_C(  94),
         SIMDE_POLY8_C(  57),  SIMDE_POLY8_C( 183),  SIMDE_POLY8_C( 229),  SIMDE_POLY8_C( 185),
         SIMDE_POLY8_C( 136),  SIMDE_POLY8_C( 171),  SIMDE_POLY8_C( 243),  SIMDE_POLY8_C( 253),
         SIMDE_POLY8_C( 157),  SIMDE_POLY8_C(  71),  SIMDE_POLY8_C( 147),  SIMDE_POLY8_C(  31),
         SIMDE_POLY8_C(  19),  SIMDE_POLY8_C( 134),  SIMDE_POLY8_C(  95),  SIMDE_POLY8_C(  78),
         SIMDE_POLY8_C( 231),  SIMDE_POLY8_C(   9),  SIMDE_POLY8_C(   0),  SIMDE_POLY8_C(  49),
         SIMDE_POLY8_C( 128),  SIMDE_POLY8_C(   4),  SIMDE_POLY8_C( 225),  SIMDE_POLY8_C( 172) } },
  { { {  SIMDE_POLY8_C(  46),  SIMDE_POLY8_C(  41),  SIMDE_POLY8_C( 202),  SIMDE_POLY8_C( 176),
         SIMDE_POLY8_C( 108),  SIMDE_POLY8_C(  25),  SIMDE_POLY8_C( 169),  SIMDE_POLY8_C( 224),
         SIMDE_POLY8_C( 211),  SIMDE_POLY8_C( 198),  SIMDE_POLY8_C( 180),  SIMDE_POLY8_C( 186),
         SIMDE_POLY8_C(  94),  SIMDE_POLY8_C(  90),  SIMDE_POLY8_C(  38),  SIMDE_POLY8_C( 204)  },
      {  SIMDE_POLY8_C(  93),  SIMDE_POLY8_C( 114),  SIMDE_POLY8_C( 222),  SIMDE_POLY8_C( 219),
         SIMDE_POLY8_C(  45),  SIMDE_POLY8_C(  65),  SIMDE_POLY8_C(  69),  SIMDE_POLY8_C( 177),
         SIMDE_POLY8_C( 201),  SIMDE_POLY8_C( 254),  SIMDE_POLY8_C( 254),  SIMDE_POLY8_C( 172),
         SIMDE_POLY8_C(  44),  SIMDE_POLY8_C(  41),  SIMDE_POLY8_C( 173),  SIMDE_POLY8_C( 126)  } },
      {  SIMDE_POLY8_C(  46),  SIMDE_POLY8_C(  41),  SIMDE_POLY8_C( 202),  SIMDE_POLY8_C( 176),
         SIMDE_POLY8_C( 108),  SIMDE_POLY8_C(  25),  SIMDE_POLY8_C( 169),  SIMDE_POLY8_C( 224),
         SIMDE_POLY8_C( 211),  SIMDE_POLY8_C( 198),  SIMDE_POLY8_C( 180),  SIMDE_POLY8_C( 186),
         SIMDE_POLY8_C(  94),  SIMDE_POLY8_C(  90),  SIMDE_POLY8_C(  38),  SIMDE_POLY8_C( 204),
         SIMDE_POLY8_C(  93),  SIMDE_POLY8_C( 114),  SIMDE_POLY8_C( 222),  SIMDE_POLY8_C( 219),
         SIMDE_POLY8_C(  45),  SIMDE_POLY8_C(  65),  SIMDE_POLY8_C(  69),  SIMDE_POLY8_C( 177),
         SIMDE_POLY8_C( 201),  SIMDE_POLY8_C( 254),  SIMDE_POLY8_C( 254),  SIMDE_POLY8_C( 172),
         SIMDE_POLY8_C(  44),  SIMDE_POLY8_C(  41),  SIMDE_POLY8_C( 173),  SIMDE_POLY8_C( 126) } },
  { { {  SIMDE_POLY8_C( 115),  SIMDE_POLY8_C( 181),  SIMDE_POLY8_C(  32),  SIMDE_POLY8_C( 147),
         SIMDE_POLY8_C(  57),  SIMDE_POLY8_C(  99),  SIMDE_POLY8_C( 148),  SIMDE_POLY8_C(  31),
         SIMDE_POLY8_C(  36),  SIMDE_POLY8_C( 180),  SIMDE_POLY8_C( 144),  SIMDE_POLY8_C( 247),
         SIMDE_POLY8_C( 215),  SIMDE_POLY8_C( 220),  SIMDE_POLY8_C( 110),  SIMDE_POLY8_C( 155)  },
      {  SIMDE_POLY8_C(  20),  SIMDE_POLY8_C(  10),  SIMDE_POLY8_C(  68),  SIMDE_POLY8_C(  84),
         SIMDE_POLY8_C( 208),  SIMDE_POLY8_C(  56),  SIMDE_POLY8_C( 236),  SIMDE_POLY8_C( 217),
         SIMDE_POLY8_C(  86),  SIMDE_POLY8_C(  91),  SIMDE_POLY8_C( 202),  SIMDE_POLY8_C( 155),
         SIMDE_POLY8_C(  55),  SIMDE_POLY8_C( 241),  SIMDE_POLY8_C( 247),  SIMDE_POLY8_C( 103)  } },
      {  SIMDE_POLY8_C( 115),  SIMDE_POLY8_C( 181),  SIMDE_POLY8_C(  32),  SIMDE_POLY8_C( 147),
         SIMDE_POLY8_C(  57),  SIMDE_POLY8_C(  99),  SIMDE_POLY8_C( 148),  SIMDE_POLY8_C(  31),
         SIMDE_POLY8_C(  36),  SIMDE_POLY8_C( 180),  SIMDE_POLY8_C( 144),  SIMDE_POLY8_C( 247),
         SIMDE_POLY8_C( 215),  SIMDE_POLY8_C( 220),  SIMDE_POLY8_C( 110),  SIMDE_POLY8_C( 155),
         SIMDE_POLY8_C(  20),  SIMDE_POLY8_C(  10),  SIMDE_POLY8_C(  68),  SIMDE_POLY8_C(  84),
         SIMDE_POLY8_C( 208),  SIMDE_POLY8_C(  56),  SIMDE_POLY8_C( 236),  SIMDE_POLY8_C( 217),
         SIMDE_POLY8_C(  86),  SIMDE_POLY8_C(  91),  SIMDE_POLY8_C( 202),  SIMDE_POLY8_C( 155),
         SIMDE_POLY8_C(  55),  SIMDE_POLY8_C( 241),  SIMDE_POLY8_C( 247),  SIMDE_POLY8_C( 103) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN_TO_16 simde_poly8x16x2_t val = {{
        simde_vld1q_p8(test_vec[i].val[0]),
        simde_vld1q_p8(test_vec[i].val[1]),
    }};
    SIMDE_ALIGN_TO_16 simde_poly8_t r_[32];
    simde_vst1q_p8_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x2_t val[2] = simde_test_arm_neon_random_p8x2();
    simde_poly8x32_t r = simde_vst1q_p8_x2(val[2]);

    simde_test_arm_neon_write_p8x2(2, val[2], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_p16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_TO_16 simde_poly16_t val[2][8];
    SIMDE_ALIGN_TO_16 simde_poly16_t r[16];
  } test_vec[] = {
  { { {  SIMDE_POLY16_C( 10266),  SIMDE_POLY16_C(   453),  SIMDE_POLY16_C( 24339),  SIMDE_POLY16_C( 55409),
         SIMDE_POLY16_C( 33804),  SIMDE_POLY16_C( 36793),  SIMDE_POLY16_C( 23404),  SIMDE_POLY16_C( 22760)  },
      {  SIMDE_POLY16_C( 14339),  SIMDE_POLY16_C( 13914),  SIMDE_POLY16_C( 34554),  SIMDE_POLY16_C( 13800),
         SIMDE_POLY16_C( 31941),  SIMDE_POLY16_C( 14692),  SIMDE_POLY16_C( 43057),  SIMDE_POLY16_C( 48622)  } },
      {  SIMDE_POLY16_C( 10266),  SIMDE_POLY16_C(   453),  SIMDE_POLY16_C( 24339),  SIMDE_POLY16_C( 55409),
         SIMDE_POLY16_C( 33804),  SIMDE_POLY16_C( 36793),  SIMDE_POLY16_C( 23404),  SIMDE_POLY16_C( 22760),
         SIMDE_POLY16_C( 14339),  SIMDE_POLY16_C( 13914),  SIMDE_POLY16_C( 34554),  SIMDE_POLY16_C( 13800),
         SIMDE_POLY16_C( 31941),  SIMDE_POLY16_C( 14692),  SIMDE_POLY16_C( 43057),  SIMDE_POLY16_C( 48622) } },
  { { {  SIMDE_POLY16_C( 36997),  SIMDE_POLY16_C( 43819),  SIMDE_POLY16_C( 63661),  SIMDE_POLY16_C( 28276),
         SIMDE_POLY16_C( 19812),  SIMDE_POLY16_C( 10362),  SIMDE_POLY16_C( 49094),  SIMDE_POLY16_C( 39537)  },
      {  SIMDE_POLY16_C( 48222),  SIMDE_POLY16_C( 20868),  SIMDE_POLY16_C( 32518),  SIMDE_POLY16_C( 14810),
         SIMDE_POLY16_C( 22343),  SIMDE_POLY16_C( 24159),  SIMDE_POLY16_C( 41580),  SIMDE_POLY16_C( 40523)  } },
      {  SIMDE_POLY16_C( 36997),  SIMDE_POLY16_C( 43819),  SIMDE_POLY16_C( 63661),  SIMDE_POLY16_C( 28276),
         SIMDE_POLY16_C( 19812),  SIMDE_POLY16_C( 10362),  SIMDE_POLY16_C( 49094),  SIMDE_POLY16_C( 39537),
         SIMDE_POLY16_C( 48222),  SIMDE_POLY16_C( 20868),  SIMDE_POLY16_C( 32518),  SIMDE_POLY16_C( 14810),
         SIMDE_POLY16_C( 22343),  SIMDE_POLY16_C( 24159),  SIMDE_POLY16_C( 41580),  SIMDE_POLY16_C( 40523) } },
  { { {  SIMDE_POLY16_C( 13423),  SIMDE_POLY16_C( 16869),  SIMDE_POLY16_C(  2310),  SIMDE_POLY16_C( 19537),
         SIMDE_POLY16_C( 53651),  SIMDE_POLY16_C(  6703),  SIMDE_POLY16_C( 18895),  SIMDE_POLY16_C( 52177)  },
      {  SIMDE_POLY16_C( 65195),  SIMDE_POLY16_C( 52281),  SIMDE_POLY16_C( 27504),  SIMDE_POLY16_C( 37625),
         SIMDE_POLY16_C( 49675),  SIMDE_POLY16_C( 44146),  SIMDE_POLY16_C( 22769),  SIMDE_POLY16_C( 49088)  } },
      {  SIMDE_POLY16_C( 13423),  SIMDE_POLY16_C( 16869),  SIMDE_POLY16_C(  2310),  SIMDE_POLY16_C( 19537),
         SIMDE_POLY16_C( 53651),  SIMDE_POLY16_C(  6703),  SIMDE_POLY16_C( 18895),  SIMDE_POLY16_C( 52177),
         SIMDE_POLY16_C( 65195),  SIMDE_POLY16_C( 52281),  SIMDE_POLY16_C( 27504),  SIMDE_POLY16_C( 37625),
         SIMDE_POLY16_C( 49675),  SIMDE_POLY16_C( 44146),  SIMDE_POLY16_C( 22769),  SIMDE_POLY16_C( 49088) } },
  { { {  SIMDE_POLY16_C( 36618),  SIMDE_POLY16_C(  5368),  SIMDE_POLY16_C( 61199),  SIMDE_POLY16_C( 17023),
         SIMDE_POLY16_C( 65443),  SIMDE_POLY16_C( 47723),  SIMDE_POLY16_C( 22555),  SIMDE_POLY16_C(  9975)  },
      {  SIMDE_POLY16_C( 45356),  SIMDE_POLY16_C(  2319),  SIMDE_POLY16_C(  2088),  SIMDE_POLY16_C( 41915),
         SIMDE_POLY16_C( 42255),  SIMDE_POLY16_C( 61260),  SIMDE_POLY16_C( 19719),  SIMDE_POLY16_C( 53780)  } },
      {  SIMDE_POLY16_C( 36618),  SIMDE_POLY16_C(  5368),  SIMDE_POLY16_C( 61199),  SIMDE_POLY16_C( 17023),
         SIMDE_POLY16_C( 65443),  SIMDE_POLY16_C( 47723),  SIMDE_POLY16_C( 22555),  SIMDE_POLY16_C(  9975),
         SIMDE_POLY16_C( 45356),  SIMDE_POLY16_C(  2319),  SIMDE_POLY16_C(  2088),  SIMDE_POLY16_C( 41915),
         SIMDE_POLY16_C( 42255),  SIMDE_POLY16_C( 61260),  SIMDE_POLY16_C( 19719),  SIMDE_POLY16_C( 53780) } },
  { { {  SIMDE_POLY16_C( 49273),  SIMDE_POLY16_C( 18037),  SIMDE_POLY16_C( 35452),  SIMDE_POLY16_C( 23038),
         SIMDE_POLY16_C( 50227),  SIMDE_POLY16_C( 11203),  SIMDE_POLY16_C( 56981),  SIMDE_POLY16_C( 30351)  },
      {  SIMDE_POLY16_C( 40051),  SIMDE_POLY16_C( 23559),  SIMDE_POLY16_C( 26348),  SIMDE_POLY16_C( 64612),
         SIMDE_POLY16_C( 49796),  SIMDE_POLY16_C( 15465),  SIMDE_POLY16_C( 59847),  SIMDE_POLY16_C( 64578)  } },
      {  SIMDE_POLY16_C( 49273),  SIMDE_POLY16_C( 18037),  SIMDE_POLY16_C( 35452),  SIMDE_POLY16_C( 23038),
         SIMDE_POLY16_C( 50227),  SIMDE_POLY16_C( 11203),  SIMDE_POLY16_C( 56981),  SIMDE_POLY16_C( 30351),
         SIMDE_POLY16_C( 40051),  SIMDE_POLY16_C( 23559),  SIMDE_POLY16_C( 26348),  SIMDE_POLY16_C( 64612),
         SIMDE_POLY16_C( 49796),  SIMDE_POLY16_C( 15465),  SIMDE_POLY16_C( 59847),  SIMDE_POLY16_C( 64578) } },
  { { {  SIMDE_POLY16_C( 19710),  SIMDE_POLY16_C( 35587),  SIMDE_POLY16_C( 64958),  SIMDE_POLY16_C( 26447),
         SIMDE_POLY16_C( 28262),  SIMDE_POLY16_C( 63131),  SIMDE_POLY16_C( 53382),  SIMDE_POLY16_C( 63921)  },
      {  SIMDE_POLY16_C( 18688),  SIMDE_POLY16_C( 11158),  SIMDE_POLY16_C( 47961),  SIMDE_POLY16_C( 16205),
         SIMDE_POLY16_C( 37522),  SIMDE_POLY16_C( 10230),  SIMDE_POLY16_C( 52131),  SIMDE_POLY16_C( 43624)  } },
      {  SIMDE_POLY16_C( 19710),  SIMDE_POLY16_C( 35587),  SIMDE_POLY16_C( 64958),  SIMDE_POLY16_C( 26447),
         SIMDE_POLY16_C( 28262),  SIMDE_POLY16_C( 63131),  SIMDE_POLY16_C( 53382),  SIMDE_POLY16_C( 63921),
         SIMDE_POLY16_C( 18688),  SIMDE_POLY16_C( 11158),  SIMDE_POLY16_C( 47961),  SIMDE_POLY16_C( 16205),
         SIMDE_POLY16_C( 37522),  SIMDE_POLY16_C( 10230),  SIMDE_POLY16_C( 52131),  SIMDE_POLY16_C( 43624) } },
  { { {  SIMDE_POLY16_C( 29666),  SIMDE_POLY16_C( 20751),  SIMDE_POLY16_C( 28968),  SIMDE_POLY16_C( 11065),
         SIMDE_POLY16_C( 17103),  SIMDE_POLY16_C( 20450),  SIMDE_POLY16_C( 30042),  SIMDE_POLY16_C( 41586)  },
      {  SIMDE_POLY16_C( 54163),  SIMDE_POLY16_C( 33517),  SIMDE_POLY16_C( 28639),  SIMDE_POLY16_C( 61278),
         SIMDE_POLY16_C( 11001),  SIMDE_POLY16_C( 32424),  SIMDE_POLY16_C( 25560),  SIMDE_POLY16_C( 31242)  } },
      {  SIMDE_POLY16_C( 29666),  SIMDE_POLY16_C( 20751),  SIMDE_POLY16_C( 28968),  SIMDE_POLY16_C( 11065),
         SIMDE_POLY16_C( 17103),  SIMDE_POLY16_C( 20450),  SIMDE_POLY16_C( 30042),  SIMDE_POLY16_C( 41586),
         SIMDE_POLY16_C( 54163),  SIMDE_POLY16_C( 33517),  SIMDE_POLY16_C( 28639),  SIMDE_POLY16_C( 61278),
         SIMDE_POLY16_C( 11001),  SIMDE_POLY16_C( 32424),  SIMDE_POLY16_C( 25560),  SIMDE_POLY16_C( 31242) } },
  { { {  SIMDE_POLY16_C( 38435),  SIMDE_POLY16_C( 53213),  SIMDE_POLY16_C( 53834),  SIMDE_POLY16_C( 45438),
         SIMDE_POLY16_C( 61595),  SIMDE_POLY16_C( 46068),  SIMDE_POLY16_C( 60730),  SIMDE_POLY16_C( 23648)  },
      {  SIMDE_POLY16_C(  1142),  SIMDE_POLY16_C( 19819),  SIMDE_POLY16_C( 12655),  SIMDE_POLY16_C( 31261),
         SIMDE_POLY16_C( 59326),  SIMDE_POLY16_C( 37223),  SIMDE_POLY16_C( 36074),  SIMDE_POLY16_C( 54268)  } },
      {  SIMDE_POLY16_C( 38435),  SIMDE_POLY16_C( 53213),  SIMDE_POLY16_C( 53834),  SIMDE_POLY16_C( 45438),
         SIMDE_POLY16_C( 61595),  SIMDE_POLY16_C( 46068),  SIMDE_POLY16_C( 60730),  SIMDE_POLY16_C( 23648),
         SIMDE_POLY16_C(  1142),  SIMDE_POLY16_C( 19819),  SIMDE_POLY16_C( 12655),  SIMDE_POLY16_C( 31261),
         SIMDE_POLY16_C( 59326),  SIMDE_POLY16_C( 37223),  SIMDE_POLY16_C( 36074),  SIMDE_POLY16_C( 54268) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN_TO_16 simde_poly16x8x2_t val = {{
        simde_vld1q_p16(test_vec[i].val[0]),
        simde_vld1q_p16(test_vec[i].val[1]),
    }};
    SIMDE_ALIGN_TO_16 simde_poly16_t r_[16];
    simde_vst1q_p16_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x2_t val[2] = simde_test_arm_neon_random_p16x2();
    simde_poly16x16_t r = simde_vst1q_p16_x2(val[2]);

    simde_test_arm_neon_write_p16x2(2, val[2], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_p64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t val[2][2];
    simde_poly64_t r[4];
  } test_vec[] = {
  { { {  SIMDE_POLY64_C(18137341211300896017),  SIMDE_POLY64_C(18129070660849794614)  },
      {  SIMDE_POLY64_C(15548630917253218626),  SIMDE_POLY64_C(  384653869528540473)  } },
      {  SIMDE_POLY64_C(18137341211300896017),  SIMDE_POLY64_C(18129070660849794614),  SIMDE_POLY64_C(15548630917253218626),  SIMDE_POLY64_C(  384653869528540473) } },
  { { {  SIMDE_POLY64_C( 5106885978315313316),  SIMDE_POLY64_C( 2584464812228293252)  },
      {  SIMDE_POLY64_C(16082191628870594949),  SIMDE_POLY64_C(16693895109160151600)  } },
      {  SIMDE_POLY64_C( 5106885978315313316),  SIMDE_POLY64_C( 2584464812228293252),  SIMDE_POLY64_C(16082191628870594949),  SIMDE_POLY64_C(16693895109160151600) } },
  { { {  SIMDE_POLY64_C(17170701338533115132),  SIMDE_POLY64_C( 9155352405127413893)  },
      {  SIMDE_POLY64_C(10809410590974935409),  SIMDE_POLY64_C( 3579400702953445711)  } },
      {  SIMDE_POLY64_C(17170701338533115132),  SIMDE_POLY64_C( 9155352405127413893),  SIMDE_POLY64_C(10809410590974935409),  SIMDE_POLY64_C( 3579400702953445711) } },
  { { {  SIMDE_POLY64_C( 3301881110653363432),  SIMDE_POLY64_C(17590622306059800943)  },
      {  SIMDE_POLY64_C( 9783394590388186442),  SIMDE_POLY64_C( 1496411401747424419)  } },
      {  SIMDE_POLY64_C( 3301881110653363432),  SIMDE_POLY64_C(17590622306059800943),  SIMDE_POLY64_C( 9783394590388186442),  SIMDE_POLY64_C( 1496411401747424419) } },
  { { {  SIMDE_POLY64_C( 1346564172340821730),  SIMDE_POLY64_C(15229765525577822955)  },
      {  SIMDE_POLY64_C( 1775198335512810016),  SIMDE_POLY64_C( 8038637536701673989)  } },
      {  SIMDE_POLY64_C( 1346564172340821730),  SIMDE_POLY64_C(15229765525577822955),  SIMDE_POLY64_C( 1775198335512810016),  SIMDE_POLY64_C( 8038637536701673989) } },
  { { {  SIMDE_POLY64_C(16683385406791156880),  SIMDE_POLY64_C( 1230718406569210931)  },
      {  SIMDE_POLY64_C(15372084538358915777),  SIMDE_POLY64_C( 1662489998024694966)  } },
      {  SIMDE_POLY64_C(16683385406791156880),  SIMDE_POLY64_C( 1230718406569210931),  SIMDE_POLY64_C(15372084538358915777),  SIMDE_POLY64_C( 1662489998024694966) } },
  { { {  SIMDE_POLY64_C(15376693268482518763),  SIMDE_POLY64_C(14869684423898231152)  },
      {  SIMDE_POLY64_C(14255114737246682918),  SIMDE_POLY64_C(16718250131693707977)  } },
      {  SIMDE_POLY64_C(15376693268482518763),  SIMDE_POLY64_C(14869684423898231152),  SIMDE_POLY64_C(14255114737246682918),  SIMDE_POLY64_C(16718250131693707977) } },
  { { {  SIMDE_POLY64_C( 1903623655786240591),  SIMDE_POLY64_C(18204096181602736409)  },
      {  SIMDE_POLY64_C(14087104026220872489),  SIMDE_POLY64_C(18108425052063750849)  } },
      {  SIMDE_POLY64_C( 1903623655786240591),  SIMDE_POLY64_C(18204096181602736409),  SIMDE_POLY64_C(14087104026220872489),  SIMDE_POLY64_C(18108425052063750849) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly64x2x2_t val = {{
        simde_vld1q_p64(test_vec[i].val[0]),
        simde_vld1q_p64(test_vec[i].val[1]),
    }};
    simde_poly64_t r_[4];
    simde_vst1q_p64_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x2_t val[2] = simde_test_arm_neon_random_p64x2();
    simde_poly64x4_t r = simde_vst1q_p64_x2(val[2]);

    simde_test_arm_neon_write_p64x2(2, val[2], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_bf16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16 val[2][8];
    simde_bfloat16 r[16];
  } test_vec[] = {
  { { { SIMDE_BFLOAT16_VALUE( - 20.956), SIMDE_BFLOAT16_VALUE( - 58.964), SIMDE_BFLOAT16_VALUE( - 74.395), SIMDE_BFLOAT16_VALUE( - 58.069),
        SIMDE_BFLOAT16_VALUE( - 73.918), SIMDE_BFLOAT16_VALUE( - 88.889), SIMDE_BFLOAT16_VALUE( - 89.387),  SIMDE_BFLOAT16_VALUE( 26.229)  },
      {  SIMDE_BFLOAT16_VALUE( 67.698),  SIMDE_BFLOAT16_VALUE( 18.105),  SIMDE_BFLOAT16_VALUE( 25.021),  SIMDE_BFLOAT16_VALUE( 34.669),
        SIMDE_BFLOAT16_VALUE( - 49.404), SIMDE_BFLOAT16_VALUE( - 56.913),  SIMDE_BFLOAT16_VALUE( 84.184),  SIMDE_BFLOAT16_VALUE( 59.094)  } },
      { SIMDE_BFLOAT16_VALUE( - 20.956), SIMDE_BFLOAT16_VALUE( - 58.964), SIMDE_BFLOAT16_VALUE( - 74.395), SIMDE_BFLOAT16_VALUE( - 58.069),
        SIMDE_BFLOAT16_VALUE( - 73.918), SIMDE_BFLOAT16_VALUE( - 88.889), SIMDE_BFLOAT16_VALUE( - 89.387),  SIMDE_BFLOAT16_VALUE( 26.229),
         SIMDE_BFLOAT16_VALUE( 67.698),  SIMDE_BFLOAT16_VALUE( 18.105),  SIMDE_BFLOAT16_VALUE( 25.021),  SIMDE_BFLOAT16_VALUE( 34.669),
        SIMDE_BFLOAT16_VALUE( - 49.404), SIMDE_BFLOAT16_VALUE( - 56.913),  SIMDE_BFLOAT16_VALUE( 84.184),  SIMDE_BFLOAT16_VALUE( 59.094) } },
  { { {  SIMDE_BFLOAT16_VALUE(  2.598), SIMDE_BFLOAT16_VALUE( - 70.000),  SIMDE_BFLOAT16_VALUE( 41.157), SIMDE_BFLOAT16_VALUE( - 83.059),
        SIMDE_BFLOAT16_VALUE( - 90.002),  SIMDE_BFLOAT16_VALUE( 21.783),  SIMDE_BFLOAT16_VALUE( 70.489),  SIMDE_BFLOAT16_VALUE( 17.433)  },
      { SIMDE_BFLOAT16_VALUE( - 86.074),  SIMDE_BFLOAT16_VALUE( 41.189),  SIMDE_BFLOAT16_VALUE( 63.234),  SIMDE_BFLOAT16_VALUE( 12.204),
         SIMDE_BFLOAT16_VALUE(  7.910), SIMDE_BFLOAT16_VALUE( - 15.107), SIMDE_BFLOAT16_VALUE( - 16.136),  SIMDE_BFLOAT16_VALUE( 13.310)  } },
      {  SIMDE_BFLOAT16_VALUE(  2.598), SIMDE_BFLOAT16_VALUE( - 70.000),  SIMDE_BFLOAT16_VALUE( 41.157), SIMDE_BFLOAT16_VALUE( - 83.059),
        SIMDE_BFLOAT16_VALUE( - 90.002),  SIMDE_BFLOAT16_VALUE( 21.783),  SIMDE_BFLOAT16_VALUE( 70.489),  SIMDE_BFLOAT16_VALUE( 17.433),
        SIMDE_BFLOAT16_VALUE( - 86.074),  SIMDE_BFLOAT16_VALUE( 41.189),  SIMDE_BFLOAT16_VALUE( 63.234),  SIMDE_BFLOAT16_VALUE( 12.204),
         SIMDE_BFLOAT16_VALUE(  7.910), SIMDE_BFLOAT16_VALUE( - 15.107), SIMDE_BFLOAT16_VALUE( - 16.136),  SIMDE_BFLOAT16_VALUE( 13.310) } },
  { { { SIMDE_BFLOAT16_VALUE( - 58.406), SIMDE_BFLOAT16_VALUE( - 64.859), SIMDE_BFLOAT16_VALUE( - 31.395),  SIMDE_BFLOAT16_VALUE( 12.432),
        SIMDE_BFLOAT16_VALUE( - 14.707),  SIMDE_BFLOAT16_VALUE( 84.786), SIMDE_BFLOAT16_VALUE( - 39.961),  SIMDE_BFLOAT16_VALUE( 98.967)  },
      {  SIMDE_BFLOAT16_VALUE( 28.677),  SIMDE_BFLOAT16_VALUE( 63.490),  SIMDE_BFLOAT16_VALUE( 74.828),  SIMDE_BFLOAT16_VALUE( 21.706),
         SIMDE_BFLOAT16_VALUE( 22.304),  SIMDE_BFLOAT16_VALUE( 71.547),  SIMDE_BFLOAT16_VALUE( 80.978),  SIMDE_BFLOAT16_VALUE( 16.394)  } },
      { SIMDE_BFLOAT16_VALUE( - 58.406), SIMDE_BFLOAT16_VALUE( - 64.859), SIMDE_BFLOAT16_VALUE( - 31.395),  SIMDE_BFLOAT16_VALUE( 12.432),
        SIMDE_BFLOAT16_VALUE( - 14.707),  SIMDE_BFLOAT16_VALUE( 84.786), SIMDE_BFLOAT16_VALUE( - 39.961),  SIMDE_BFLOAT16_VALUE( 98.967),
         SIMDE_BFLOAT16_VALUE( 28.677),  SIMDE_BFLOAT16_VALUE( 63.490),  SIMDE_BFLOAT16_VALUE( 74.828),  SIMDE_BFLOAT16_VALUE( 21.706),
         SIMDE_BFLOAT16_VALUE( 22.304),  SIMDE_BFLOAT16_VALUE( 71.547),  SIMDE_BFLOAT16_VALUE( 80.978),  SIMDE_BFLOAT16_VALUE( 16.394) } },
  { { {  SIMDE_BFLOAT16_VALUE( 97.804),  SIMDE_BFLOAT16_VALUE( 73.823), SIMDE_BFLOAT16_VALUE( -  8.059),  SIMDE_BFLOAT16_VALUE( 93.096),
         SIMDE_BFLOAT16_VALUE( 90.504), SIMDE_BFLOAT16_VALUE( -  2.398),  SIMDE_BFLOAT16_VALUE( 30.759), SIMDE_BFLOAT16_VALUE( - 94.855)  },
      { SIMDE_BFLOAT16_VALUE( -  5.801), SIMDE_BFLOAT16_VALUE( - 68.562), SIMDE_BFLOAT16_VALUE( - 54.678),  SIMDE_BFLOAT16_VALUE( 22.048),
        SIMDE_BFLOAT16_VALUE( - 71.055), SIMDE_BFLOAT16_VALUE( - 30.977),  SIMDE_BFLOAT16_VALUE( 18.382),  SIMDE_BFLOAT16_VALUE( 11.761)  } },
      {  SIMDE_BFLOAT16_VALUE( 97.804),  SIMDE_BFLOAT16_VALUE( 73.823), SIMDE_BFLOAT16_VALUE( -  8.059),  SIMDE_BFLOAT16_VALUE( 93.096),
         SIMDE_BFLOAT16_VALUE( 90.504), SIMDE_BFLOAT16_VALUE( -  2.398),  SIMDE_BFLOAT16_VALUE( 30.759), SIMDE_BFLOAT16_VALUE( - 94.855),
        SIMDE_BFLOAT16_VALUE( -  5.801), SIMDE_BFLOAT16_VALUE( - 68.562), SIMDE_BFLOAT16_VALUE( - 54.678),  SIMDE_BFLOAT16_VALUE( 22.048),
        SIMDE_BFLOAT16_VALUE( - 71.055), SIMDE_BFLOAT16_VALUE( - 30.977),  SIMDE_BFLOAT16_VALUE( 18.382),  SIMDE_BFLOAT16_VALUE( 11.761) } },
  { { {  SIMDE_BFLOAT16_VALUE( 55.035),  SIMDE_BFLOAT16_VALUE( 94.504),  SIMDE_BFLOAT16_VALUE( 21.867),  SIMDE_BFLOAT16_VALUE( 60.556),
        SIMDE_BFLOAT16_VALUE( - 21.374),  SIMDE_BFLOAT16_VALUE( 82.466),  SIMDE_BFLOAT16_VALUE( 84.824),  SIMDE_BFLOAT16_VALUE( 31.885)  },
      {  SIMDE_BFLOAT16_VALUE( 17.599), SIMDE_BFLOAT16_VALUE( - 18.858), SIMDE_BFLOAT16_VALUE( - 97.376), SIMDE_BFLOAT16_VALUE( - 85.414),
        SIMDE_BFLOAT16_VALUE( - 37.173),  SIMDE_BFLOAT16_VALUE( 36.083),  SIMDE_BFLOAT16_VALUE( 51.414),  SIMDE_BFLOAT16_VALUE( 42.445)  } },
      {  SIMDE_BFLOAT16_VALUE( 55.035),  SIMDE_BFLOAT16_VALUE( 94.504),  SIMDE_BFLOAT16_VALUE( 21.867),  SIMDE_BFLOAT16_VALUE( 60.556),
        SIMDE_BFLOAT16_VALUE( - 21.374),  SIMDE_BFLOAT16_VALUE( 82.466),  SIMDE_BFLOAT16_VALUE( 84.824),  SIMDE_BFLOAT16_VALUE( 31.885),
         SIMDE_BFLOAT16_VALUE( 17.599), SIMDE_BFLOAT16_VALUE( - 18.858), SIMDE_BFLOAT16_VALUE( - 97.376), SIMDE_BFLOAT16_VALUE( - 85.414),
        SIMDE_BFLOAT16_VALUE( - 37.173),  SIMDE_BFLOAT16_VALUE( 36.083),  SIMDE_BFLOAT16_VALUE( 51.414),  SIMDE_BFLOAT16_VALUE( 42.445) } },
  { { { SIMDE_BFLOAT16_VALUE( - 58.353),  SIMDE_BFLOAT16_VALUE( 94.351), SIMDE_BFLOAT16_VALUE( - 72.718),  SIMDE_BFLOAT16_VALUE( 44.738),
         SIMDE_BFLOAT16_VALUE( 88.331),  SIMDE_BFLOAT16_VALUE( 93.544),  SIMDE_BFLOAT16_VALUE( 79.940), SIMDE_BFLOAT16_VALUE( - 29.844)  },
      { SIMDE_BFLOAT16_VALUE( - 64.679), SIMDE_BFLOAT16_VALUE( - 31.234),  SIMDE_BFLOAT16_VALUE( 25.402),  SIMDE_BFLOAT16_VALUE( 61.429),
        SIMDE_BFLOAT16_VALUE( - 80.532),  SIMDE_BFLOAT16_VALUE( 19.659), SIMDE_BFLOAT16_VALUE( - 67.325),  SIMDE_BFLOAT16_VALUE( 54.634)  } },
      { SIMDE_BFLOAT16_VALUE( - 58.353),  SIMDE_BFLOAT16_VALUE( 94.351), SIMDE_BFLOAT16_VALUE( - 72.718),  SIMDE_BFLOAT16_VALUE( 44.738),
         SIMDE_BFLOAT16_VALUE( 88.331),  SIMDE_BFLOAT16_VALUE( 93.544),  SIMDE_BFLOAT16_VALUE( 79.940), SIMDE_BFLOAT16_VALUE( - 29.844),
        SIMDE_BFLOAT16_VALUE( - 64.679), SIMDE_BFLOAT16_VALUE( - 31.234),  SIMDE_BFLOAT16_VALUE( 25.402),  SIMDE_BFLOAT16_VALUE( 61.429),
        SIMDE_BFLOAT16_VALUE( - 80.532),  SIMDE_BFLOAT16_VALUE( 19.659), SIMDE_BFLOAT16_VALUE( - 67.325),  SIMDE_BFLOAT16_VALUE( 54.634) } },
  { { { SIMDE_BFLOAT16_VALUE( - 99.773),  SIMDE_BFLOAT16_VALUE( 27.004),  SIMDE_BFLOAT16_VALUE( 53.708),  SIMDE_BFLOAT16_VALUE( 12.664),
         SIMDE_BFLOAT16_VALUE( 66.275), SIMDE_BFLOAT16_VALUE( -  0.836), SIMDE_BFLOAT16_VALUE( - 22.661),  SIMDE_BFLOAT16_VALUE( 72.602)  },
      {  SIMDE_BFLOAT16_VALUE( 25.260), SIMDE_BFLOAT16_VALUE( - 83.782), SIMDE_BFLOAT16_VALUE( - 61.087), SIMDE_BFLOAT16_VALUE( - 38.948),
        SIMDE_BFLOAT16_VALUE( - 78.380),  SIMDE_BFLOAT16_VALUE(  6.817), SIMDE_BFLOAT16_VALUE( - 82.373), SIMDE_BFLOAT16_VALUE( - 60.011)  } },
      { SIMDE_BFLOAT16_VALUE( - 99.773),  SIMDE_BFLOAT16_VALUE( 27.004),  SIMDE_BFLOAT16_VALUE( 53.708),  SIMDE_BFLOAT16_VALUE( 12.664),
         SIMDE_BFLOAT16_VALUE( 66.275), SIMDE_BFLOAT16_VALUE( -  0.836), SIMDE_BFLOAT16_VALUE( - 22.661),  SIMDE_BFLOAT16_VALUE( 72.602),
         SIMDE_BFLOAT16_VALUE( 25.260), SIMDE_BFLOAT16_VALUE( - 83.782), SIMDE_BFLOAT16_VALUE( - 61.087), SIMDE_BFLOAT16_VALUE( - 38.948),
        SIMDE_BFLOAT16_VALUE( - 78.380),  SIMDE_BFLOAT16_VALUE(  6.817), SIMDE_BFLOAT16_VALUE( - 82.373), SIMDE_BFLOAT16_VALUE( - 60.011) } },
  { { { SIMDE_BFLOAT16_VALUE( - 53.476),  SIMDE_BFLOAT16_VALUE(  8.724), SIMDE_BFLOAT16_VALUE( - 88.674), SIMDE_BFLOAT16_VALUE( - 48.309),
        SIMDE_BFLOAT16_VALUE( -  3.562),  SIMDE_BFLOAT16_VALUE( 14.309), SIMDE_BFLOAT16_VALUE( - 99.801), SIMDE_BFLOAT16_VALUE( - 11.703)  },
      { SIMDE_BFLOAT16_VALUE( - 62.913), SIMDE_BFLOAT16_VALUE( - 43.056), SIMDE_BFLOAT16_VALUE( - 65.766),  SIMDE_BFLOAT16_VALUE( 92.099),
         SIMDE_BFLOAT16_VALUE( 73.066),  SIMDE_BFLOAT16_VALUE( 29.509), SIMDE_BFLOAT16_VALUE( - 77.995), SIMDE_BFLOAT16_VALUE( - 81.816)  } },
      { SIMDE_BFLOAT16_VALUE( - 53.476),  SIMDE_BFLOAT16_VALUE(  8.724), SIMDE_BFLOAT16_VALUE( - 88.674), SIMDE_BFLOAT16_VALUE( - 48.309),
        SIMDE_BFLOAT16_VALUE( -  3.562),  SIMDE_BFLOAT16_VALUE( 14.309), SIMDE_BFLOAT16_VALUE( - 99.801), SIMDE_BFLOAT16_VALUE( - 11.703),
        SIMDE_BFLOAT16_VALUE( - 62.913), SIMDE_BFLOAT16_VALUE( - 43.056), SIMDE_BFLOAT16_VALUE( - 65.766),  SIMDE_BFLOAT16_VALUE( 92.099),
         SIMDE_BFLOAT16_VALUE( 73.066),  SIMDE_BFLOAT16_VALUE( 29.509), SIMDE_BFLOAT16_VALUE( - 77.995), SIMDE_BFLOAT16_VALUE( - 81.816) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_bfloat16x8x2_t val = {{
        simde_vld1q_bf16(test_vec[i].val[0]),
        simde_vld1q_bf16(test_vec[i].val[1]),
    }};
    simde_bfloat16 r_[16];
    simde_vst1q_bf16_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_bfloat16x2_t val[2] = simde_test_arm_neon_random_bf16x2(-100.0f, 100.0f);
    simde_bfloat16x16_t r = simde_vst1q_bf16_x2(val[2]);

    simde_test_arm_neon_write_bf16x2(2, val[2], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_f16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_f32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_f64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_p8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_p16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_p64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_bf16_x2)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
