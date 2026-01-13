/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN and

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/and.h>

static int
test_simde_mm_mask_and_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    double src[2];
    simde__mmask8 k;
    double a[2];
    double b[2];
    double r[2];
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C(    14.60), SIMDE_FLOAT64_C(   887.30) },
      UINT8_C( 28),
      { SIMDE_FLOAT64_C(  -240.39), SIMDE_FLOAT64_C(   885.45) },
      { SIMDE_FLOAT64_C(   595.79), SIMDE_FLOAT64_C(  -642.76) },
      { SIMDE_FLOAT64_C(    14.60), SIMDE_FLOAT64_C(   887.30) } },
    { { SIMDE_FLOAT64_C(  -436.91), SIMDE_FLOAT64_C(   106.50) },
      UINT8_C( 52),
      { SIMDE_FLOAT64_C(  -630.01), SIMDE_FLOAT64_C(   329.06) },
      { SIMDE_FLOAT64_C(  -552.53), SIMDE_FLOAT64_C(  -718.32) },
      { SIMDE_FLOAT64_C(  -436.91), SIMDE_FLOAT64_C(   106.50) } },
    { { SIMDE_FLOAT64_C(  -987.43), SIMDE_FLOAT64_C(   330.01) },
      UINT8_C( 32),
      { SIMDE_FLOAT64_C(  -931.70), SIMDE_FLOAT64_C(   238.43) },
      { SIMDE_FLOAT64_C(   169.23), SIMDE_FLOAT64_C(   617.74) },
      { SIMDE_FLOAT64_C(  -987.43), SIMDE_FLOAT64_C(   330.01) } },
    { { SIMDE_FLOAT64_C(  -965.26), SIMDE_FLOAT64_C(  -623.36) },
      UINT8_C(180),
      { SIMDE_FLOAT64_C(   475.50), SIMDE_FLOAT64_C(  -766.68) },
      { SIMDE_FLOAT64_C(  -801.80), SIMDE_FLOAT64_C(   976.67) },
      { SIMDE_FLOAT64_C(  -965.26), SIMDE_FLOAT64_C(  -623.36) } },
    { { SIMDE_FLOAT64_C(  -927.77), SIMDE_FLOAT64_C(  -775.05) },
      UINT8_C( 19),
      { SIMDE_FLOAT64_C(    86.83), SIMDE_FLOAT64_C(  -887.75) },
      { SIMDE_FLOAT64_C(   208.71), SIMDE_FLOAT64_C(   846.44) },
      { SIMDE_FLOAT64_C(    32.16), SIMDE_FLOAT64_C(   838.25) } },
    { { SIMDE_FLOAT64_C(   997.70), SIMDE_FLOAT64_C(  -195.50) },
      UINT8_C( 50),
      { SIMDE_FLOAT64_C(  -439.21), SIMDE_FLOAT64_C(   911.00) },
      { SIMDE_FLOAT64_C(  -465.71), SIMDE_FLOAT64_C(   -69.22) },
      { SIMDE_FLOAT64_C(   997.70), SIMDE_FLOAT64_C(     2.04) } },
    { { SIMDE_FLOAT64_C(   240.07), SIMDE_FLOAT64_C(   -18.24) },
      UINT8_C( 54),
      { SIMDE_FLOAT64_C(   252.64), SIMDE_FLOAT64_C(  -688.24) },
      { SIMDE_FLOAT64_C(  -484.85), SIMDE_FLOAT64_C(   320.93) },
      { SIMDE_FLOAT64_C(   240.07), SIMDE_FLOAT64_C(     2.50) } },
    { { SIMDE_FLOAT64_C(   550.19), SIMDE_FLOAT64_C(   684.38) },
      UINT8_C(  3),
      { SIMDE_FLOAT64_C(   584.93), SIMDE_FLOAT64_C(  -938.98) },
      { SIMDE_FLOAT64_C(   452.50), SIMDE_FLOAT64_C(    60.43) },
      { SIMDE_FLOAT64_C(     2.03), SIMDE_FLOAT64_C(     3.51) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[i])); i++) {
    simde__m128d src = simde_mm_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_loadu_pd(test_vec[i].r);
    simde_assert_m128d_close(simde_mm_mask_and_pd(src, k, a, b), r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(-1000.0, 1000.0);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(-1000.0, 1000.0);
    simde__m128d b = simde_test_x86_random_f64x2(-1000.0, 1000.0);
    simde__m128d r = simde_mm_mask_and_pd(src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_and_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde__mmask8 k;
    double a[2];
    double b[2];
    double r[2];
  } test_vec[8] = {
    { UINT8_C(189),
      { SIMDE_FLOAT64_C(  -141.90), SIMDE_FLOAT64_C(  -734.49) },
      { SIMDE_FLOAT64_C(  -266.16), SIMDE_FLOAT64_C(  -256.18) },
      { SIMDE_FLOAT64_C(  -133.02), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(  1),
      { SIMDE_FLOAT64_C(  -408.86), SIMDE_FLOAT64_C(    52.27) },
      { SIMDE_FLOAT64_C(  -796.35), SIMDE_FLOAT64_C(  -663.50) },
      { SIMDE_FLOAT64_C(    -3.06), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 64),
      { SIMDE_FLOAT64_C(  -650.48), SIMDE_FLOAT64_C(   295.04) },
      { SIMDE_FLOAT64_C(   177.64), SIMDE_FLOAT64_C(  -124.42) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(225),
      { SIMDE_FLOAT64_C(  -109.45), SIMDE_FLOAT64_C(   536.01) },
      { SIMDE_FLOAT64_C(   299.14), SIMDE_FLOAT64_C(  -836.49) },
      { SIMDE_FLOAT64_C(    72.25), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(236),
      { SIMDE_FLOAT64_C(  -584.27), SIMDE_FLOAT64_C(   437.41) },
      { SIMDE_FLOAT64_C(  -100.77), SIMDE_FLOAT64_C(    18.38) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(177),
      { SIMDE_FLOAT64_C(   945.20), SIMDE_FLOAT64_C(  -772.77) },
      { SIMDE_FLOAT64_C(  -732.81), SIMDE_FLOAT64_C(  -137.40) },
      { SIMDE_FLOAT64_C(   656.01), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(140),
      { SIMDE_FLOAT64_C(  -892.37), SIMDE_FLOAT64_C(   720.69) },
      { SIMDE_FLOAT64_C(   384.96), SIMDE_FLOAT64_C(  -158.53) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 37),
      { SIMDE_FLOAT64_C(   427.98), SIMDE_FLOAT64_C(   432.61) },
      { SIMDE_FLOAT64_C(   516.78), SIMDE_FLOAT64_C(   631.63) },
      { SIMDE_FLOAT64_C(     2.02), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[i])); i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_loadu_pd(test_vec[i].r);
    simde_assert_m128d_close(simde_mm_maskz_and_pd(k, a, b), r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(-1000.0, 1000.0);
    simde__m128d b = simde_test_x86_random_f64x2(-1000.0, 1000.0);
    simde__m128d r = simde_mm_maskz_and_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_and_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    float src[4];
    simde__mmask8 k;
    float a[4];
    float b[4];
    float r[4];
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(   612.90), SIMDE_FLOAT32_C(   793.60), SIMDE_FLOAT32_C(  -889.01), SIMDE_FLOAT32_C(   777.70) },
      UINT8_C(238),
      { SIMDE_FLOAT32_C(   409.34), SIMDE_FLOAT32_C(   -58.56), SIMDE_FLOAT32_C(  -267.77), SIMDE_FLOAT32_C(   704.74) },
      { SIMDE_FLOAT32_C(  -614.47), SIMDE_FLOAT32_C(  -923.23), SIMDE_FLOAT32_C(   -17.47), SIMDE_FLOAT32_C(   674.70) },
      { SIMDE_FLOAT32_C(   612.90), SIMDE_FLOAT32_C(    -3.53), SIMDE_FLOAT32_C(   -16.22), SIMDE_FLOAT32_C(   640.69) } },
    { { SIMDE_FLOAT32_C(   428.43), SIMDE_FLOAT32_C(   -34.55), SIMDE_FLOAT32_C(    22.57), SIMDE_FLOAT32_C(  -617.57) },
      UINT8_C(149),
      { SIMDE_FLOAT32_C(   -59.17), SIMDE_FLOAT32_C(  -140.18), SIMDE_FLOAT32_C(  -821.43), SIMDE_FLOAT32_C(  -594.26) },
      { SIMDE_FLOAT32_C(  -841.32), SIMDE_FLOAT32_C(    72.80), SIMDE_FLOAT32_C(  -115.14), SIMDE_FLOAT32_C(  -518.24) },
      { SIMDE_FLOAT32_C(    -3.00), SIMDE_FLOAT32_C(   -34.55), SIMDE_FLOAT32_C(    -3.07), SIMDE_FLOAT32_C(  -617.57) } },
    { { SIMDE_FLOAT32_C(   563.99), SIMDE_FLOAT32_C(  -962.72), SIMDE_FLOAT32_C(  -185.21), SIMDE_FLOAT32_C(   571.53) },
      UINT8_C( 39),
      { SIMDE_FLOAT32_C(  -572.31), SIMDE_FLOAT32_C(   365.13), SIMDE_FLOAT32_C(   338.38), SIMDE_FLOAT32_C(  -794.62) },
      { SIMDE_FLOAT32_C(  -807.57), SIMDE_FLOAT32_C(  -252.28), SIMDE_FLOAT32_C(   146.82), SIMDE_FLOAT32_C(   -75.34) },
      { SIMDE_FLOAT32_C(  -548.01), SIMDE_FLOAT32_C(   180.00), SIMDE_FLOAT32_C(   128.07), SIMDE_FLOAT32_C(   571.53) } },
    { { SIMDE_FLOAT32_C(  -547.54), SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(     1.43), SIMDE_FLOAT32_C(   434.99) },
      UINT8_C(157),
      { SIMDE_FLOAT32_C(  -570.14), SIMDE_FLOAT32_C(  -599.56), SIMDE_FLOAT32_C(  -770.37), SIMDE_FLOAT32_C(  -187.71) },
      { SIMDE_FLOAT32_C(   571.46), SIMDE_FLOAT32_C(   170.46), SIMDE_FLOAT32_C(   672.11), SIMDE_FLOAT32_C(   750.04) },
      { SIMDE_FLOAT32_C(   570.13), SIMDE_FLOAT32_C(   532.35), SIMDE_FLOAT32_C(   512.11), SIMDE_FLOAT32_C(     2.93) } },
    { { SIMDE_FLOAT32_C(   576.20), SIMDE_FLOAT32_C(   830.79), SIMDE_FLOAT32_C(  -177.17), SIMDE_FLOAT32_C(  -538.95) },
      UINT8_C(167),
      { SIMDE_FLOAT32_C(  -613.18), SIMDE_FLOAT32_C(  -501.66), SIMDE_FLOAT32_C(   127.34), SIMDE_FLOAT32_C(   958.35) },
      { SIMDE_FLOAT32_C(   725.73), SIMDE_FLOAT32_C(   555.03), SIMDE_FLOAT32_C(   323.49), SIMDE_FLOAT32_C(    64.11) },
      { SIMDE_FLOAT32_C(   581.16), SIMDE_FLOAT32_C(     2.17), SIMDE_FLOAT32_C(    80.34), SIMDE_FLOAT32_C(  -538.95) } },
    { { SIMDE_FLOAT32_C(   760.41), SIMDE_FLOAT32_C(   515.92), SIMDE_FLOAT32_C(   811.83), SIMDE_FLOAT32_C(   -92.77) },
      UINT8_C(155),
      { SIMDE_FLOAT32_C(  -735.71), SIMDE_FLOAT32_C(  -560.42), SIMDE_FLOAT32_C(   442.00), SIMDE_FLOAT32_C(   699.28) },
      { SIMDE_FLOAT32_C(   646.64), SIMDE_FLOAT32_C(   871.87), SIMDE_FLOAT32_C(  -900.28), SIMDE_FLOAT32_C(   876.26) },
      { SIMDE_FLOAT32_C(   646.63), SIMDE_FLOAT32_C(   544.29), SIMDE_FLOAT32_C(   811.83), SIMDE_FLOAT32_C(   552.26) } },
    { { SIMDE_FLOAT32_C(  -315.84), SIMDE_FLOAT32_C(   671.19), SIMDE_FLOAT32_C(    46.72), SIMDE_FLOAT32_C(  -643.73) },
      UINT8_C(140),
      { SIMDE_FLOAT32_C(  -377.08), SIMDE_FLOAT32_C(  -812.94), SIMDE_FLOAT32_C(  -755.94), SIMDE_FLOAT32_C(    83.97) },
      { SIMDE_FLOAT32_C(  -500.38), SIMDE_FLOAT32_C(  -369.12), SIMDE_FLOAT32_C(   582.31), SIMDE_FLOAT32_C(   626.96) },
      { SIMDE_FLOAT32_C(  -315.84), SIMDE_FLOAT32_C(   671.19), SIMDE_FLOAT32_C(   578.25), SIMDE_FLOAT32_C(     2.07) } },
    { { SIMDE_FLOAT32_C(  -410.77), SIMDE_FLOAT32_C(   308.04), SIMDE_FLOAT32_C(   181.99), SIMDE_FLOAT32_C(   912.72) },
      UINT8_C(239),
      { SIMDE_FLOAT32_C(   -57.60), SIMDE_FLOAT32_C(   428.64), SIMDE_FLOAT32_C(  -816.03), SIMDE_FLOAT32_C(   849.63) },
      { SIMDE_FLOAT32_C(   869.21), SIMDE_FLOAT32_C(  -551.74), SIMDE_FLOAT32_C(  -710.79), SIMDE_FLOAT32_C(   311.21) },
      { SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(  -512.01), SIMDE_FLOAT32_C(     2.25) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[i])); i++) {
    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_loadu_ps(test_vec[i].r);
    simde_assert_m128_close(simde_mm_mask_and_ps(src, k, a, b), r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(-1000.0, 1000.0);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(-1000.0, 1000.0);
    simde__m128 b = simde_test_x86_random_f32x4(-1000.0, 1000.0);
    simde__m128 r = simde_mm_mask_and_ps(src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_and_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde__mmask8 k;
    float a[4];
    float b[4];
    float r[4];
  } test_vec[8] = {
    { UINT8_C(183),
      { SIMDE_FLOAT32_C(  -383.76), SIMDE_FLOAT32_C(   668.63), SIMDE_FLOAT32_C(   207.10), SIMDE_FLOAT32_C(  -491.02) },
      { SIMDE_FLOAT32_C(   742.13), SIMDE_FLOAT32_C(   996.58), SIMDE_FLOAT32_C(   439.30), SIMDE_FLOAT32_C(  -125.55) },
      { SIMDE_FLOAT32_C(     2.90), SIMDE_FLOAT32_C(   644.50), SIMDE_FLOAT32_C(   203.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(197),
      { SIMDE_FLOAT32_C(   570.96), SIMDE_FLOAT32_C(  -368.01), SIMDE_FLOAT32_C(  -852.50), SIMDE_FLOAT32_C(  -669.98) },
      { SIMDE_FLOAT32_C(  -250.51), SIMDE_FLOAT32_C(  -233.80), SIMDE_FLOAT32_C(   642.48), SIMDE_FLOAT32_C(   490.77) },
      { SIMDE_FLOAT32_C(     2.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   512.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(226),
      { SIMDE_FLOAT32_C(  -964.13), SIMDE_FLOAT32_C(   550.14), SIMDE_FLOAT32_C(  -422.55), SIMDE_FLOAT32_C(   512.90) },
      { SIMDE_FLOAT32_C(   257.97), SIMDE_FLOAT32_C(  -636.23), SIMDE_FLOAT32_C(  -528.29), SIMDE_FLOAT32_C(   817.12) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   548.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(235),
      { SIMDE_FLOAT32_C(   471.21), SIMDE_FLOAT32_C(   930.51), SIMDE_FLOAT32_C(   957.59), SIMDE_FLOAT32_C(  -961.07) },
      { SIMDE_FLOAT32_C(  -453.26), SIMDE_FLOAT32_C(   626.21), SIMDE_FLOAT32_C(   246.03), SIMDE_FLOAT32_C(    55.72) },
      { SIMDE_FLOAT32_C(   453.00), SIMDE_FLOAT32_C(   546.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     3.25) } },
    { UINT8_C( 19),
      { SIMDE_FLOAT32_C(   242.61), SIMDE_FLOAT32_C(  -504.98), SIMDE_FLOAT32_C(  -757.21), SIMDE_FLOAT32_C(  -279.90) },
      { SIMDE_FLOAT32_C(  -934.02), SIMDE_FLOAT32_C(  -125.21), SIMDE_FLOAT32_C(  -132.41), SIMDE_FLOAT32_C(  -604.00) },
      { SIMDE_FLOAT32_C(     3.51), SIMDE_FLOAT32_C(  -124.21), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(252),
      { SIMDE_FLOAT32_C(   633.79), SIMDE_FLOAT32_C(  -961.52), SIMDE_FLOAT32_C(   115.05), SIMDE_FLOAT32_C(  -364.33) },
      { SIMDE_FLOAT32_C(  -925.65), SIMDE_FLOAT32_C(  -334.81), SIMDE_FLOAT32_C(   213.11), SIMDE_FLOAT32_C(   587.25) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    49.02), SIMDE_FLOAT32_C(     2.28) } },
    { UINT8_C(145),
      { SIMDE_FLOAT32_C(   576.88), SIMDE_FLOAT32_C(  -941.04), SIMDE_FLOAT32_C(   740.28), SIMDE_FLOAT32_C(   202.49) },
      { SIMDE_FLOAT32_C(   530.17), SIMDE_FLOAT32_C(   670.79), SIMDE_FLOAT32_C(   160.08), SIMDE_FLOAT32_C(   569.10) },
      { SIMDE_FLOAT32_C(   512.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(167),
      { SIMDE_FLOAT32_C(  -213.70), SIMDE_FLOAT32_C(  -184.87), SIMDE_FLOAT32_C(   273.26), SIMDE_FLOAT32_C(  -845.36) },
      { SIMDE_FLOAT32_C(  -942.26), SIMDE_FLOAT32_C(   768.27), SIMDE_FLOAT32_C(  -602.57), SIMDE_FLOAT32_C(  -222.17) },
      { SIMDE_FLOAT32_C(    -3.02), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[i])); i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_loadu_ps(test_vec[i].r);
    simde_assert_m128_close(simde_mm_maskz_and_ps(k, a, b), r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(-1000.0, 1000.0);
    simde__m128 b = simde_test_x86_random_f32x4(-1000.0, 1000.0);
    simde__m128 r = simde_mm_maskz_and_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_and_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    int32_t src[4];
    simde__mmask8 k;
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[8] = {
    { { -INT32_C(  1073740740), -INT32_C(  1398210822),  INT32_C(   227193586), -INT32_C(  2069622047) },
      UINT8_C(226),
      { -INT32_C(   536143014),  INT32_C(    96622923), -INT32_C(  1320799415), -INT32_C(   185791248) },
      {  INT32_C(   200191245),  INT32_C(   134060885),  INT32_C(   938019365),  INT32_C(   152726959) },
      { -INT32_C(  1073740740),  INT32_C(    96475457),  INT32_C(   227193586), -INT32_C(  2069622047) } },
    { { -INT32_C(   739695224), -INT32_C(   942101634), -INT32_C(   814211361),  INT32_C(   952329515) },
      UINT8_C( 18),
      {  INT32_C(  1298613170),  INT32_C(  1265790528), -INT32_C(   990205609), -INT32_C(   397605949) },
      { -INT32_C(  1738137364),  INT32_C(   393686521),  INT32_C(   172115621), -INT32_C(  1155761655) },
      { -INT32_C(   739695224),  INT32_C(    57814080), -INT32_C(   814211361),  INT32_C(   952329515) } },
    { { -INT32_C(    32996419),  INT32_C(  1229552370), -INT32_C(   418495708),  INT32_C(   852515654) },
      UINT8_C(123),
      {  INT32_C(  1685375542), -INT32_C(  2029417407),  INT32_C(  1234244814), -INT32_C(  1274655696) },
      { -INT32_C(   811203499), -INT32_C(  1863061683),  INT32_C(  1490476029), -INT32_C(   506197589) },
      {  INT32_C(  1143210004), -INT32_C(  2147382207), -INT32_C(   418495708), -INT32_C(  1610348512) } },
    { {  INT32_C(   356862163), -INT32_C(  1550037036), -INT32_C(  1813238429), -INT32_C(   817368454) },
      UINT8_C(247),
      { -INT32_C(   582705427),  INT32_C(  1843058066), -INT32_C(  1273482325),  INT32_C(  1334376711) },
      { -INT32_C(  1910203073),  INT32_C(  1743898425), -INT32_C(  1511947085), -INT32_C(  1180913460) },
      { -INT32_C(  1945854931),  INT32_C(  1708180752), -INT32_C(  1543503709), -INT32_C(   817368454) } },
    { { -INT32_C(   526982834),  INT32_C(  1632465334), -INT32_C(  1424595548), -INT32_C(  1627742625) },
      UINT8_C( 59),
      { -INT32_C(   445371362), -INT32_C(  1583817955),  INT32_C(  1819098812), -INT32_C(  1145362470) },
      {  INT32_C(   779197373),  INT32_C(  1322439657), -INT32_C(  2018673175), -INT32_C(  1765651592) },
      {  INT32_C(   611321884),  INT32_C(     9491209), -INT32_C(  1424595548), -INT32_C(  1836973224) } },
    { { -INT32_C(  1803798921), -INT32_C(   835316718),  INT32_C(   758883154), -INT32_C(  1997998390) },
      UINT8_C(145),
      {  INT32_C(   763016794),  INT32_C(   102156681), -INT32_C(  1031889546), -INT32_C(  1791421089) },
      { -INT32_C(  1515729263), -INT32_C(  1476889084), -INT32_C(  1485691471),  INT32_C(  1731787277) },
      {  INT32_C(   623019536), -INT32_C(   835316718),  INT32_C(   758883154), -INT32_C(  1997998390) } },
    { {  INT32_C(   966046640), -INT32_C(   230643076), -INT32_C(  1498104249),  INT32_C(  1681714899) },
      UINT8_C(188),
      {  INT32_C(  1505757923),  INT32_C(   654993154), -INT32_C(   751521319), -INT32_C(  1652253462) },
      { -INT32_C(   619070160), -INT32_C(  1138619395), -INT32_C(  1366308416), -INT32_C(   395643899) },
      {  INT32_C(   966046640), -INT32_C(   230643076), -INT32_C(  2113633856), -INT32_C(  2013228032) } },
    { {  INT32_C(     4336382),  INT32_C(  1797737617), -INT32_C(   398566402),  INT32_C(   679854839) },
      UINT8_C(128),
      { -INT32_C(  1451424866), -INT32_C(   295093979), -INT32_C(  1108142135), -INT32_C(  1413751679) },
      {  INT32_C(  1782430494),  INT32_C(  1030269154), -INT32_C(  1456123674),  INT32_C(  1932090837) },
      {  INT32_C(     4336382),  INT32_C(  1797737617), -INT32_C(   398566402),  INT32_C(   679854839) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i src = simde_mm_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_loadu_epi32(test_vec[i].r);
    simde_assert_m128i_i32(simde_mm_mask_and_epi32(src, k, a, b), ==, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask_and_epi32(src, k, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_and_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde__mmask8 k;
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[8] = {
    { UINT8_C( 97),
      { -INT32_C(   986241401), -INT32_C(   283956133),  INT32_C(  1810069530), -INT32_C(   443299443) },
      {  INT32_C(  1776717286), -INT32_C(   807786218), -INT32_C(   586481400),  INT32_C(  1581175255) },
      {  INT32_C(  1093010566),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(247),
      { -INT32_C(  1588452491), -INT32_C(  1363394250), -INT32_C(   298113243),  INT32_C(  1205084346) },
      {  INT32_C(   794705414),  INT32_C(   423046424),  INT32_C(   166728760), -INT32_C(   939504045) },
      {  INT32_C(   559030788),  INT32_C(   137625872),  INT32_C(   137364512),  INT32_C(           0) } },
    { UINT8_C(113),
      { -INT32_C(  1817744814),  INT32_C(  1303926054), -INT32_C(  1324898671), -INT32_C(  1179103621) },
      { -INT32_C(   640555092),  INT32_C(   856812063),  INT32_C(   696654555),  INT32_C(  1822117658) },
      { -INT32_C(  1853791744),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(185),
      { -INT32_C(  1730215870),  INT32_C(  1596533944), -INT32_C(  2116363725),  INT32_C(  2049872786) },
      {  INT32_C(  1318651748),  INT32_C(   858377241), -INT32_C(  1571925165),  INT32_C(   811317998) },
      {  INT32_C(   144244800),  INT32_C(           0),  INT32_C(           0),  INT32_C(   805999234) } },
    { UINT8_C(186),
      {  INT32_C(  1718863930), -INT32_C(   862334223),  INT32_C(  1063131820),  INT32_C(  1352915016) },
      {  INT32_C(  1047130481),  INT32_C(  1855036443), -INT32_C(  1520684054), -INT32_C(   933262194) },
      {  INT32_C(           0),  INT32_C(  1284608017),  INT32_C(           0),  INT32_C(  1073973256) } },
    { UINT8_C( 85),
      { -INT32_C(  1538904366), -INT32_C(   514846009),  INT32_C(  1227526001),  INT32_C(   616266290) },
      {  INT32_C(  2134899171), -INT32_C(  1117082230), -INT32_C(  1790243063),  INT32_C(  1105859438) },
      {  INT32_C(   604383426),  INT32_C(           0),  INT32_C(    17436417),  INT32_C(           0) } },
    { UINT8_C( 65),
      {  INT32_C(  1124656433), -INT32_C(   977999562), -INT32_C(  1913061869), -INT32_C(  1301275463) },
      {  INT32_C(   138211419),  INT32_C(  1762785626),  INT32_C(  1473750596), -INT32_C(  1030219631) },
      {  INT32_C(      581649),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(254),
      { -INT32_C(  1993079392), -INT32_C(  1197606470),  INT32_C(   225520369), -INT32_C(  1956109413) },
      {  INT32_C(  1491431519),  INT32_C(   681332353),  INT32_C(  1052373797),  INT32_C(   725384075) },
      {  INT32_C(           0),  INT32_C(   681330816),  INT32_C(   204546593),  INT32_C(   187179915) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_loadu_epi32(test_vec[i].r);
    simde_assert_m128i_i32(simde_mm_maskz_and_epi32(k, a, b), ==, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maskz_and_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_and_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    int64_t src[2];
    simde__mmask8 k;
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[8] = {
    { { -INT64_C( 1944515373323709404),  INT64_C( 6856545209998348532) },
      UINT8_C(118),
      { -INT64_C( 7051833149891194334),  INT64_C(  189791024934245902) },
      {  INT64_C( 4588457386688424711),  INT64_C( 8331985110409226708) },
      { -INT64_C( 1944515373323709404),  INT64_C(  189151459944759300) } },
    { { -INT64_C(  849671908751832454),  INT64_C( 5017314818574710961) },
      UINT8_C(192),
      { -INT64_C( 3205809036151816907),  INT64_C( 6420329112004767094) },
      { -INT64_C( 2460034237101788977),  INT64_C( 5943449814054960038) },
      { -INT64_C(  849671908751832454),  INT64_C( 5017314818574710961) } },
    { {  INT64_C(  998817902067050846),  INT64_C( 7411171916304351281) },
      UINT8_C(117),
      { -INT64_C( 1661204369974324967),  INT64_C( 1301918699112213843) },
      { -INT64_C(  716715594301760935), -INT64_C( 9179194316117144222) },
      { -INT64_C( 2305783204813467623),  INT64_C( 7411171916304351281) } },
    { { -INT64_C( 9089742689547782524), -INT64_C( 8023367006596833428) },
      UINT8_C( 96),
      {  INT64_C(  606099711834090832),  INT64_C( 2545078244423471321) },
      { -INT64_C(  222978636778487109),  INT64_C( 8335534141230775303) },
      { -INT64_C( 9089742689547782524), -INT64_C( 8023367006596833428) } },
    { {  INT64_C( 2932936614155453233), -INT64_C( 3619973733458632077) },
      UINT8_C(136),
      { -INT64_C( 6129785919489423595), -INT64_C( 1456561636737467436) },
      {  INT64_C( 5336592010016617658), -INT64_C( 8636732608868470953) },
      {  INT64_C( 2932936614155453233), -INT64_C( 3619973733458632077) } },
    { {  INT64_C( 4416164717352962416),  INT64_C( 1255833969800583065) },
      UINT8_C( 19),
      {  INT64_C( 7881727869842075304), -INT64_C( 1478473557240381727) },
      {  INT64_C( 8849452747600501463),  INT64_C( 7357161871584153960) },
      {  INT64_C( 7512426532654090880),  INT64_C( 7068786789326016608) } },
    { { -INT64_C( 4918824857917893487), -INT64_C( 2603572045048013616) },
      UINT8_C( 91),
      {  INT64_C( 3543833594356961587), -INT64_C( 6737290145530170357) },
      {  INT64_C( 2840144687237222343),  INT64_C( 8041746936156085758) },
      {  INT64_C( 2389784676831854851),  INT64_C( 2485993635102528522) } },
    { { -INT64_C( 7194390926155491305),  INT64_C( 3857345651768236183) },
      UINT8_C(218),
      { -INT64_C( 7693682840249709052),  INT64_C( 7842244779668765111) },
      {  INT64_C(  968162825606122613), -INT64_C( 2230776201361009371) },
      { -INT64_C( 7194390926155491305),  INT64_C( 6917529101466161445) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i src = simde_mm_loadu_epi64(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_loadu_epi64(test_vec[i].r);
    simde_assert_m128i_i32(simde_mm_mask_and_epi64(src, k, a, b), ==, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_and_epi64(src, k, a, b);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_and_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde__mmask8 k;
    int64_t a[4];
    int64_t b[4];
    int64_t r[4];
  } test_vec[8] = {
    { UINT8_C(198),
      {  INT64_C( 6787175370868818929),  INT64_C( 3557906188044989237) },
      {  INT64_C( 1304538274618338704),  INT64_C( 8753126893949317892) },
      {  INT64_C(                   0),  INT64_C( 3557870646115726084) } },
    { UINT8_C(221),
      { -INT64_C( 3567617426467607964), -INT64_C( 7159365858221797413) },
      {  INT64_C( 6341725671592807000), -INT64_C( 7831097642173024998) },
      {  INT64_C( 5188222363367606848),  INT64_C(                   0) } },
    { UINT8_C(  4),
      { -INT64_C( 6387322150392505543), -INT64_C( 2488253009938125235) },
      {  INT64_C( 3361403276938606134), -INT64_C( 6460149317400454406) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(203),
      { -INT64_C( 1210964169870596809),  INT64_C( 4488926404532064289) },
      { -INT64_C( 7442791580505286752), -INT64_C( 7350813153069627071) },
      { -INT64_C( 8632907901739858656),  INT64_C( 1749800463001190401) } },
    { UINT8_C(208),
      { -INT64_C(  140948947139003361),  INT64_C( 4881906858505674817) },
      {  INT64_C( 4170431316023671482),  INT64_C( 3375505155592753757) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(176),
      {  INT64_C( 4947586972787808296),  INT64_C(  279490942987192354) },
      {  INT64_C( 8244801603114270644),  INT64_C( 8352961572015993606) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(198),
      {  INT64_C( 5604499408540064585),  INT64_C( 5586390766300032478) },
      {  INT64_C( 8177727676147929867), -INT64_C( 1507526501598447713) },
      {  INT64_C(                   0),  INT64_C( 5261348407700923806) } },
    { UINT8_C( 11),
      {  INT64_C( 4902974510825771262), -INT64_C(  750307411065905998) },
      {  INT64_C( 4740713197583207436),  INT64_C( 3124881510036084770) },
      {  INT64_C( 4614576639472304140),  INT64_C( 2383617101677074466) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_loadu_epi64(test_vec[i].r);
    simde_assert_m128i_i64(simde_mm_maskz_and_epi64(k, a, b), ==, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_and_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_and_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    double src[4];
    simde__mmask8 k;
    double a[4];
    double b[4];
    double r[4];
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C(     9.18), SIMDE_FLOAT64_C(   143.78), SIMDE_FLOAT64_C(   -79.98), SIMDE_FLOAT64_C(  -954.68) },
      UINT8_C( 13),
      { SIMDE_FLOAT64_C(  -726.05), SIMDE_FLOAT64_C(   -99.06), SIMDE_FLOAT64_C(  -862.91), SIMDE_FLOAT64_C(  -890.62) },
      { SIMDE_FLOAT64_C(   788.86), SIMDE_FLOAT64_C(   343.59), SIMDE_FLOAT64_C(  -913.14), SIMDE_FLOAT64_C(   306.89) },
      { SIMDE_FLOAT64_C(   532.05), SIMDE_FLOAT64_C(   143.78), SIMDE_FLOAT64_C(  -784.13), SIMDE_FLOAT64_C(     2.38) } },
    { { SIMDE_FLOAT64_C(  -195.23), SIMDE_FLOAT64_C(  -556.02), SIMDE_FLOAT64_C(   729.31), SIMDE_FLOAT64_C(  -504.08) },
      UINT8_C(  1),
      { SIMDE_FLOAT64_C(   -94.78), SIMDE_FLOAT64_C(  -614.55), SIMDE_FLOAT64_C(   574.33), SIMDE_FLOAT64_C(  -628.65) },
      { SIMDE_FLOAT64_C(   704.38), SIMDE_FLOAT64_C(  -408.12), SIMDE_FLOAT64_C(   443.98), SIMDE_FLOAT64_C(  -411.20) },
      { SIMDE_FLOAT64_C(     2.75), SIMDE_FLOAT64_C(  -556.02), SIMDE_FLOAT64_C(   729.31), SIMDE_FLOAT64_C(  -504.08) } },
    { { SIMDE_FLOAT64_C(  -217.96), SIMDE_FLOAT64_C(   -51.59), SIMDE_FLOAT64_C(   756.63), SIMDE_FLOAT64_C(  -293.64) },
      UINT8_C(125),
      { SIMDE_FLOAT64_C(  -234.19), SIMDE_FLOAT64_C(   850.14), SIMDE_FLOAT64_C(  -957.56), SIMDE_FLOAT64_C(  -188.87) },
      { SIMDE_FLOAT64_C(   972.70), SIMDE_FLOAT64_C(  -683.61), SIMDE_FLOAT64_C(   712.07), SIMDE_FLOAT64_C(  -890.21) },
      { SIMDE_FLOAT64_C(     3.53), SIMDE_FLOAT64_C(   -51.59), SIMDE_FLOAT64_C(   648.01), SIMDE_FLOAT64_C(    -2.45) } },
    { { SIMDE_FLOAT64_C(  -574.23), SIMDE_FLOAT64_C(   500.94), SIMDE_FLOAT64_C(   453.38), SIMDE_FLOAT64_C(  -487.37) },
      UINT8_C( 23),
      { SIMDE_FLOAT64_C(  -741.85), SIMDE_FLOAT64_C(   -43.39), SIMDE_FLOAT64_C(  -462.87), SIMDE_FLOAT64_C(  -245.93) },
      { SIMDE_FLOAT64_C(   336.96), SIMDE_FLOAT64_C(   442.36), SIMDE_FLOAT64_C(   139.51), SIMDE_FLOAT64_C(   -88.71) },
      { SIMDE_FLOAT64_C(     2.63), SIMDE_FLOAT64_C(    35.26), SIMDE_FLOAT64_C(   131.01), SIMDE_FLOAT64_C(  -487.37) } },
    { { SIMDE_FLOAT64_C(   813.71), SIMDE_FLOAT64_C(  -156.10), SIMDE_FLOAT64_C(   503.17), SIMDE_FLOAT64_C(   257.69) },
      UINT8_C(225),
      { SIMDE_FLOAT64_C(  -714.79), SIMDE_FLOAT64_C(  -793.90), SIMDE_FLOAT64_C(   189.32), SIMDE_FLOAT64_C(    -8.43) },
      { SIMDE_FLOAT64_C(   328.52), SIMDE_FLOAT64_C(   955.13), SIMDE_FLOAT64_C(  -158.29), SIMDE_FLOAT64_C(   370.97) },
      { SIMDE_FLOAT64_C(     2.50), SIMDE_FLOAT64_C(  -156.10), SIMDE_FLOAT64_C(   503.17), SIMDE_FLOAT64_C(   257.69) } },
    { { SIMDE_FLOAT64_C(  -233.74), SIMDE_FLOAT64_C(  -185.59), SIMDE_FLOAT64_C(   687.36), SIMDE_FLOAT64_C(  -521.66) },
      UINT8_C(146),
      { SIMDE_FLOAT64_C(  -886.87), SIMDE_FLOAT64_C(   979.27), SIMDE_FLOAT64_C(  -622.42), SIMDE_FLOAT64_C(  -374.24) },
      { SIMDE_FLOAT64_C(  -212.90), SIMDE_FLOAT64_C(  -364.27), SIMDE_FLOAT64_C(   582.36), SIMDE_FLOAT64_C(   324.23) },
      { SIMDE_FLOAT64_C(  -233.74), SIMDE_FLOAT64_C(     2.81), SIMDE_FLOAT64_C(   687.36), SIMDE_FLOAT64_C(  -521.66) } },
    { { SIMDE_FLOAT64_C(   389.80), SIMDE_FLOAT64_C(   -80.68), SIMDE_FLOAT64_C(  -233.41), SIMDE_FLOAT64_C(  -470.69) },
      UINT8_C( 27),
      { SIMDE_FLOAT64_C(  -419.70), SIMDE_FLOAT64_C(   373.21), SIMDE_FLOAT64_C(   333.77), SIMDE_FLOAT64_C(   837.99) },
      { SIMDE_FLOAT64_C(  -194.10), SIMDE_FLOAT64_C(   618.99), SIMDE_FLOAT64_C(  -955.91), SIMDE_FLOAT64_C(   995.22) },
      { SIMDE_FLOAT64_C(  -192.10), SIMDE_FLOAT64_C(     2.42), SIMDE_FLOAT64_C(  -233.41), SIMDE_FLOAT64_C(   833.22) } },
    { { SIMDE_FLOAT64_C(  -389.44), SIMDE_FLOAT64_C(   372.61), SIMDE_FLOAT64_C(   950.35), SIMDE_FLOAT64_C(   452.27) },
      UINT8_C( 25),
      { SIMDE_FLOAT64_C(  -283.39), SIMDE_FLOAT64_C(  -733.32), SIMDE_FLOAT64_C(  -569.07), SIMDE_FLOAT64_C(   194.94) },
      { SIMDE_FLOAT64_C(   190.88), SIMDE_FLOAT64_C(  -455.94), SIMDE_FLOAT64_C(   174.21), SIMDE_FLOAT64_C(   568.47) },
      { SIMDE_FLOAT64_C(   140.63), SIMDE_FLOAT64_C(   372.61), SIMDE_FLOAT64_C(   950.35), SIMDE_FLOAT64_C(     2.03) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[i])); i++) {
    simde__m256d src = simde_mm256_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_loadu_pd(test_vec[i].r);
    simde_assert_m256d_close(simde_mm256_mask_and_pd(src, k, a, b), r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d src = simde_test_x86_random_f64x4(-1000.0, 1000.0);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(-1000.0, 1000.0);
    simde__m256d b = simde_test_x86_random_f64x4(-1000.0, 1000.0);
    simde__m256d r = simde_mm256_mask_and_pd(src, k, a, b);

    simde_test_x86_write_f64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_and_pd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde__mmask8 k;
    double a[4];
    double b[4];
    double r[4];
  } test_vec[8] = {
    { UINT8_C(102),
      { SIMDE_FLOAT64_C(   201.42), SIMDE_FLOAT64_C(  -199.12), SIMDE_FLOAT64_C(   178.44), SIMDE_FLOAT64_C(   241.20) },
      { SIMDE_FLOAT64_C(  -312.90), SIMDE_FLOAT64_C(  -895.77), SIMDE_FLOAT64_C(  -900.45), SIMDE_FLOAT64_C(   846.01) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -3.11), SIMDE_FLOAT64_C(     2.50), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 96),
      { SIMDE_FLOAT64_C(  -344.38), SIMDE_FLOAT64_C(   993.17), SIMDE_FLOAT64_C(  -377.65), SIMDE_FLOAT64_C(  -572.00) },
      { SIMDE_FLOAT64_C(  -111.41), SIMDE_FLOAT64_C(  -644.35), SIMDE_FLOAT64_C(   764.16), SIMDE_FLOAT64_C(   147.48) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(123),
      { SIMDE_FLOAT64_C(  -781.54), SIMDE_FLOAT64_C(  -405.88), SIMDE_FLOAT64_C(  -280.85), SIMDE_FLOAT64_C(   770.16) },
      { SIMDE_FLOAT64_C(   842.26), SIMDE_FLOAT64_C(   956.81), SIMDE_FLOAT64_C(   901.91), SIMDE_FLOAT64_C(   -95.59) },
      { SIMDE_FLOAT64_C(   776.01), SIMDE_FLOAT64_C(     3.16), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     2.00) } },
    { UINT8_C(  0),
      { SIMDE_FLOAT64_C(   844.81), SIMDE_FLOAT64_C(   -88.37), SIMDE_FLOAT64_C(  -909.21), SIMDE_FLOAT64_C(  -412.60) },
      { SIMDE_FLOAT64_C(  -886.94), SIMDE_FLOAT64_C(  -108.33), SIMDE_FLOAT64_C(   765.84), SIMDE_FLOAT64_C(   354.26) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(109),
      { SIMDE_FLOAT64_C(   870.06), SIMDE_FLOAT64_C(   453.81), SIMDE_FLOAT64_C(   424.77), SIMDE_FLOAT64_C(   838.42) },
      { SIMDE_FLOAT64_C(  -890.57), SIMDE_FLOAT64_C(   417.94), SIMDE_FLOAT64_C(  -539.24), SIMDE_FLOAT64_C(  -462.57) },
      { SIMDE_FLOAT64_C(   866.01), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     2.07), SIMDE_FLOAT64_C(     3.02) } },
    { UINT8_C( 11),
      { SIMDE_FLOAT64_C(  -183.58), SIMDE_FLOAT64_C(  -698.41), SIMDE_FLOAT64_C(   454.01), SIMDE_FLOAT64_C(   541.35) },
      { SIMDE_FLOAT64_C(  -479.95), SIMDE_FLOAT64_C(  -951.87), SIMDE_FLOAT64_C(  -739.50), SIMDE_FLOAT64_C(  -709.79) },
      { SIMDE_FLOAT64_C(  -167.56), SIMDE_FLOAT64_C(  -690.28), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   517.28) } },
    { UINT8_C( 27),
      { SIMDE_FLOAT64_C(  -782.69), SIMDE_FLOAT64_C(  -807.87), SIMDE_FLOAT64_C(  -205.20), SIMDE_FLOAT64_C(  -273.56) },
      { SIMDE_FLOAT64_C(  -963.06), SIMDE_FLOAT64_C(   706.43), SIMDE_FLOAT64_C(  -182.77), SIMDE_FLOAT64_C(  -375.67) },
      { SIMDE_FLOAT64_C(  -770.00), SIMDE_FLOAT64_C(   514.30), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -273.54) } },
    { UINT8_C(125),
      { SIMDE_FLOAT64_C(   708.90), SIMDE_FLOAT64_C(  -609.83), SIMDE_FLOAT64_C(   173.75), SIMDE_FLOAT64_C(   287.66) },
      { SIMDE_FLOAT64_C(  -739.77), SIMDE_FLOAT64_C(  -372.45), SIMDE_FLOAT64_C(  -287.57), SIMDE_FLOAT64_C(  -901.35) },
      { SIMDE_FLOAT64_C(   704.77), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   141.75), SIMDE_FLOAT64_C(     2.02) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[i])); i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_loadu_pd(test_vec[i].r);
    simde_assert_m256d_close(simde_mm256_maskz_and_pd(k, a, b), r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(-1000.0, 1000.0);
    simde__m256d b = simde_test_x86_random_f64x4(-1000.0, 1000.0);
    simde__m256d r = simde_mm256_maskz_and_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_and_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    float src[8];
    simde__mmask8 k;
    float a[8];
    float b[8];
    float r[8];
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(  -660.75), SIMDE_FLOAT32_C(  -605.54), SIMDE_FLOAT32_C(   -84.10), SIMDE_FLOAT32_C(   898.40),
        SIMDE_FLOAT32_C(   950.92), SIMDE_FLOAT32_C(   162.97), SIMDE_FLOAT32_C(  -964.77), SIMDE_FLOAT32_C(  -650.55) },
      UINT8_C(111),
      { SIMDE_FLOAT32_C(   -44.02), SIMDE_FLOAT32_C(   -36.26), SIMDE_FLOAT32_C(   692.54), SIMDE_FLOAT32_C(    92.04),
        SIMDE_FLOAT32_C(  -825.63), SIMDE_FLOAT32_C(  -818.24), SIMDE_FLOAT32_C(  -677.47), SIMDE_FLOAT32_C(   491.29) },
      { SIMDE_FLOAT32_C(   514.34), SIMDE_FLOAT32_C(   447.79), SIMDE_FLOAT32_C(  -804.43), SIMDE_FLOAT32_C(  -468.87),
        SIMDE_FLOAT32_C(  -183.31), SIMDE_FLOAT32_C(   482.98), SIMDE_FLOAT32_C(   159.26), SIMDE_FLOAT32_C(   743.21) },
      { SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(    36.25), SIMDE_FLOAT32_C(   548.04), SIMDE_FLOAT32_C(    84.01),
        SIMDE_FLOAT32_C(   950.92), SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(     2.14), SIMDE_FLOAT32_C(  -650.55) } },
    { { SIMDE_FLOAT32_C(  -678.18), SIMDE_FLOAT32_C(  -830.79), SIMDE_FLOAT32_C(   641.52), SIMDE_FLOAT32_C(   476.99),
        SIMDE_FLOAT32_C(   285.80), SIMDE_FLOAT32_C(  -994.87), SIMDE_FLOAT32_C(   816.24), SIMDE_FLOAT32_C(   680.26) },
      UINT8_C( 40),
      { SIMDE_FLOAT32_C(   714.64), SIMDE_FLOAT32_C(   631.18), SIMDE_FLOAT32_C(  -916.00), SIMDE_FLOAT32_C(   749.87),
        SIMDE_FLOAT32_C(   980.64), SIMDE_FLOAT32_C(  -885.39), SIMDE_FLOAT32_C(  -294.15), SIMDE_FLOAT32_C(   -55.62) },
      { SIMDE_FLOAT32_C(   807.15), SIMDE_FLOAT32_C(   797.89), SIMDE_FLOAT32_C(   118.75), SIMDE_FLOAT32_C(   988.91),
        SIMDE_FLOAT32_C(  -879.58), SIMDE_FLOAT32_C(  -389.96), SIMDE_FLOAT32_C(   503.26), SIMDE_FLOAT32_C(   568.20) },
      { SIMDE_FLOAT32_C(  -678.18), SIMDE_FLOAT32_C(  -830.79), SIMDE_FLOAT32_C(   641.52), SIMDE_FLOAT32_C(   716.78),
        SIMDE_FLOAT32_C(   285.80), SIMDE_FLOAT32_C(    -3.01), SIMDE_FLOAT32_C(   816.24), SIMDE_FLOAT32_C(   680.26) } },
    { { SIMDE_FLOAT32_C(  -194.39), SIMDE_FLOAT32_C(  -965.62), SIMDE_FLOAT32_C(  -615.11), SIMDE_FLOAT32_C(  -711.41),
        SIMDE_FLOAT32_C(   193.64), SIMDE_FLOAT32_C(  -871.91), SIMDE_FLOAT32_C(  -389.59), SIMDE_FLOAT32_C(   362.85) },
      UINT8_C(  9),
      { SIMDE_FLOAT32_C(  -912.61), SIMDE_FLOAT32_C(  -351.35), SIMDE_FLOAT32_C(   774.74), SIMDE_FLOAT32_C(   903.63),
        SIMDE_FLOAT32_C(  -671.09), SIMDE_FLOAT32_C(  -304.22), SIMDE_FLOAT32_C(   618.26), SIMDE_FLOAT32_C(   960.10) },
      { SIMDE_FLOAT32_C(  -220.23), SIMDE_FLOAT32_C(   368.13), SIMDE_FLOAT32_C(   940.74), SIMDE_FLOAT32_C(  -105.61),
        SIMDE_FLOAT32_C(  -926.02), SIMDE_FLOAT32_C(  -114.88), SIMDE_FLOAT32_C(  -298.46), SIMDE_FLOAT32_C(   871.86) },
      { SIMDE_FLOAT32_C(    -3.06), SIMDE_FLOAT32_C(  -965.62), SIMDE_FLOAT32_C(  -615.11), SIMDE_FLOAT32_C(     3.02),
        SIMDE_FLOAT32_C(   193.64), SIMDE_FLOAT32_C(  -871.91), SIMDE_FLOAT32_C(  -389.59), SIMDE_FLOAT32_C(   362.85) } },
    { { SIMDE_FLOAT32_C(  -996.13), SIMDE_FLOAT32_C(  -309.55), SIMDE_FLOAT32_C(   992.28), SIMDE_FLOAT32_C(  -386.09),
        SIMDE_FLOAT32_C(  -806.29), SIMDE_FLOAT32_C(   560.48), SIMDE_FLOAT32_C(   419.52), SIMDE_FLOAT32_C(  -771.91) },
      UINT8_C( 75),
      { SIMDE_FLOAT32_C(   708.11), SIMDE_FLOAT32_C(   421.74), SIMDE_FLOAT32_C(  -926.54), SIMDE_FLOAT32_C(  -681.49),
        SIMDE_FLOAT32_C(  -215.42), SIMDE_FLOAT32_C(   843.07), SIMDE_FLOAT32_C(  -594.10), SIMDE_FLOAT32_C(   433.24) },
      { SIMDE_FLOAT32_C(   617.82), SIMDE_FLOAT32_C(  -690.47), SIMDE_FLOAT32_C(   762.15), SIMDE_FLOAT32_C(  -686.41),
        SIMDE_FLOAT32_C(   927.80), SIMDE_FLOAT32_C(   722.24), SIMDE_FLOAT32_C(    93.37), SIMDE_FLOAT32_C(   295.93) },
      { SIMDE_FLOAT32_C(   576.06), SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(   992.28), SIMDE_FLOAT32_C(  -680.41),
        SIMDE_FLOAT32_C(  -806.29), SIMDE_FLOAT32_C(   560.48), SIMDE_FLOAT32_C(     2.26), SIMDE_FLOAT32_C(  -771.91) } },
    { { SIMDE_FLOAT32_C(   662.98), SIMDE_FLOAT32_C(   987.75), SIMDE_FLOAT32_C(   369.91), SIMDE_FLOAT32_C(  -451.90),
        SIMDE_FLOAT32_C(  -310.71), SIMDE_FLOAT32_C(   241.77), SIMDE_FLOAT32_C(  -448.03), SIMDE_FLOAT32_C(   379.75) },
      UINT8_C(106),
      { SIMDE_FLOAT32_C(   165.88), SIMDE_FLOAT32_C(   573.46), SIMDE_FLOAT32_C(  -205.47), SIMDE_FLOAT32_C(  -414.60),
        SIMDE_FLOAT32_C(   801.55), SIMDE_FLOAT32_C(  -260.10), SIMDE_FLOAT32_C(  -706.50), SIMDE_FLOAT32_C(   223.29) },
      { SIMDE_FLOAT32_C(  -186.64), SIMDE_FLOAT32_C(  -387.99), SIMDE_FLOAT32_C(  -992.13), SIMDE_FLOAT32_C(  -343.57),
        SIMDE_FLOAT32_C(    17.92), SIMDE_FLOAT32_C(   441.11), SIMDE_FLOAT32_C(  -725.76), SIMDE_FLOAT32_C(   327.45) },
      { SIMDE_FLOAT32_C(   662.98), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(   369.91), SIMDE_FLOAT32_C(  -278.57),
        SIMDE_FLOAT32_C(  -310.71), SIMDE_FLOAT32_C(   256.09), SIMDE_FLOAT32_C(  -704.50), SIMDE_FLOAT32_C(   379.75) } },
    { { SIMDE_FLOAT32_C(   203.25), SIMDE_FLOAT32_C(  -412.16), SIMDE_FLOAT32_C(   255.25), SIMDE_FLOAT32_C(   -74.50),
        SIMDE_FLOAT32_C(   681.20), SIMDE_FLOAT32_C(  -448.83), SIMDE_FLOAT32_C(  -411.53), SIMDE_FLOAT32_C(   668.96) },
      UINT8_C(218),
      { SIMDE_FLOAT32_C(   136.57), SIMDE_FLOAT32_C(  -641.75), SIMDE_FLOAT32_C(   162.85), SIMDE_FLOAT32_C(   688.54),
        SIMDE_FLOAT32_C(   738.00), SIMDE_FLOAT32_C(  -603.10), SIMDE_FLOAT32_C(  -145.58), SIMDE_FLOAT32_C(   311.46) },
      { SIMDE_FLOAT32_C(   191.43), SIMDE_FLOAT32_C(   439.81), SIMDE_FLOAT32_C(   113.01), SIMDE_FLOAT32_C(   931.33),
        SIMDE_FLOAT32_C(   733.32), SIMDE_FLOAT32_C(  -663.71), SIMDE_FLOAT32_C(  -255.31), SIMDE_FLOAT32_C(  -654.67) },
      { SIMDE_FLOAT32_C(   203.25), SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(   255.25), SIMDE_FLOAT32_C(   672.00),
        SIMDE_FLOAT32_C(   704.00), SIMDE_FLOAT32_C(  -448.83), SIMDE_FLOAT32_C(  -145.02), SIMDE_FLOAT32_C(     2.06) } },
    { { SIMDE_FLOAT32_C(  -655.83), SIMDE_FLOAT32_C(   401.11), SIMDE_FLOAT32_C(   363.25), SIMDE_FLOAT32_C(   785.27),
        SIMDE_FLOAT32_C(   675.36), SIMDE_FLOAT32_C(  -309.30), SIMDE_FLOAT32_C(   -11.48), SIMDE_FLOAT32_C(  -736.81) },
      UINT8_C( 16),
      { SIMDE_FLOAT32_C(   914.02), SIMDE_FLOAT32_C(   944.40), SIMDE_FLOAT32_C(  -502.88), SIMDE_FLOAT32_C(  -497.51),
        SIMDE_FLOAT32_C(   613.35), SIMDE_FLOAT32_C(  -581.80), SIMDE_FLOAT32_C(   639.06), SIMDE_FLOAT32_C(   971.60) },
      { SIMDE_FLOAT32_C(   581.05), SIMDE_FLOAT32_C(   327.60), SIMDE_FLOAT32_C(   709.60), SIMDE_FLOAT32_C(   977.95),
        SIMDE_FLOAT32_C(  -817.98), SIMDE_FLOAT32_C(    21.06), SIMDE_FLOAT32_C(   169.38), SIMDE_FLOAT32_C(   621.83) },
      { SIMDE_FLOAT32_C(  -655.83), SIMDE_FLOAT32_C(   401.11), SIMDE_FLOAT32_C(   363.25), SIMDE_FLOAT32_C(   785.27),
        SIMDE_FLOAT32_C(   545.35), SIMDE_FLOAT32_C(  -309.30), SIMDE_FLOAT32_C(   -11.48), SIMDE_FLOAT32_C(  -736.81) } },
    { { SIMDE_FLOAT32_C(  -865.94), SIMDE_FLOAT32_C(   100.71), SIMDE_FLOAT32_C(   355.15), SIMDE_FLOAT32_C(  -529.64),
        SIMDE_FLOAT32_C(   845.39), SIMDE_FLOAT32_C(   700.48), SIMDE_FLOAT32_C(  -185.48), SIMDE_FLOAT32_C(   246.51) },
      UINT8_C(161),
      { SIMDE_FLOAT32_C(  -400.20), SIMDE_FLOAT32_C(   -78.14), SIMDE_FLOAT32_C(   754.43), SIMDE_FLOAT32_C(   588.32),
        SIMDE_FLOAT32_C(   185.06), SIMDE_FLOAT32_C(   700.38), SIMDE_FLOAT32_C(   502.34), SIMDE_FLOAT32_C(   129.45) },
      { SIMDE_FLOAT32_C(  -802.50), SIMDE_FLOAT32_C(  -995.16), SIMDE_FLOAT32_C(  -257.19), SIMDE_FLOAT32_C(  -384.31),
        SIMDE_FLOAT32_C(   643.90), SIMDE_FLOAT32_C(  -285.59), SIMDE_FLOAT32_C(  -803.26), SIMDE_FLOAT32_C(   -28.50) },
      { SIMDE_FLOAT32_C(    -3.12), SIMDE_FLOAT32_C(   100.71), SIMDE_FLOAT32_C(   355.15), SIMDE_FLOAT32_C(  -529.64),
        SIMDE_FLOAT32_C(   845.39), SIMDE_FLOAT32_C(     2.22), SIMDE_FLOAT32_C(  -185.48), SIMDE_FLOAT32_C(     8.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[i])); i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_loadu_ps(test_vec[i].r);
    simde_assert_m256_close(simde_mm256_mask_and_ps(src, k, a, b), r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(-1000.0, 1000.0);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(-1000.0, 1000.0);
    simde__m256 b = simde_test_x86_random_f32x8(-1000.0, 1000.0);
    simde__m256 r = simde_mm256_mask_and_ps(src, k, a, b);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_and_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde__mmask8 k;
    float a[8];
    float b[8];
    float r[8];
  } test_vec[8] = {
    { UINT8_C(171),
      { SIMDE_FLOAT32_C(  -507.06), SIMDE_FLOAT32_C(  -326.36), SIMDE_FLOAT32_C(   709.86), SIMDE_FLOAT32_C(   272.95),
        SIMDE_FLOAT32_C(  -110.83), SIMDE_FLOAT32_C(    18.31), SIMDE_FLOAT32_C(  -578.99), SIMDE_FLOAT32_C(  -322.81) },
      { SIMDE_FLOAT32_C(   452.71), SIMDE_FLOAT32_C(  -465.95), SIMDE_FLOAT32_C(  -661.31), SIMDE_FLOAT32_C(  -275.30),
        SIMDE_FLOAT32_C(   768.36), SIMDE_FLOAT32_C(   719.22), SIMDE_FLOAT32_C(  -510.20), SIMDE_FLOAT32_C(   941.11) },
      { SIMDE_FLOAT32_C(   448.02), SIMDE_FLOAT32_C(  -320.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   272.25),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.52) } },
    { UINT8_C( 33),
      { SIMDE_FLOAT32_C(  -983.28), SIMDE_FLOAT32_C(   460.58), SIMDE_FLOAT32_C(   142.85), SIMDE_FLOAT32_C(  -784.34),
        SIMDE_FLOAT32_C(  -837.18), SIMDE_FLOAT32_C(   521.65), SIMDE_FLOAT32_C(   740.67), SIMDE_FLOAT32_C(  -821.71) },
      { SIMDE_FLOAT32_C(  -327.80), SIMDE_FLOAT32_C(  -140.30), SIMDE_FLOAT32_C(   766.16), SIMDE_FLOAT32_C(   891.52),
        SIMDE_FLOAT32_C(   676.90), SIMDE_FLOAT32_C(  -988.51), SIMDE_FLOAT32_C(  -615.54), SIMDE_FLOAT32_C(  -649.46) },
      { SIMDE_FLOAT32_C(    -2.53), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   520.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(179),
      { SIMDE_FLOAT32_C(   657.41), SIMDE_FLOAT32_C(   239.71), SIMDE_FLOAT32_C(  -260.34), SIMDE_FLOAT32_C(  -921.58),
        SIMDE_FLOAT32_C(   916.90), SIMDE_FLOAT32_C(  -807.63), SIMDE_FLOAT32_C(  -387.54), SIMDE_FLOAT32_C(  -744.40) },
      { SIMDE_FLOAT32_C(   -82.93), SIMDE_FLOAT32_C(  -619.18), SIMDE_FLOAT32_C(   974.82), SIMDE_FLOAT32_C(   406.87),
        SIMDE_FLOAT32_C(  -678.07), SIMDE_FLOAT32_C(  -191.94), SIMDE_FLOAT32_C(   423.59), SIMDE_FLOAT32_C(   782.50) },
      { SIMDE_FLOAT32_C(     2.57), SIMDE_FLOAT32_C(     2.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   644.00), SIMDE_FLOAT32_C(    -2.15), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   520.00) } },
    { UINT8_C( 85),
      { SIMDE_FLOAT32_C(   639.25), SIMDE_FLOAT32_C(   945.32), SIMDE_FLOAT32_C(   472.56), SIMDE_FLOAT32_C(   379.92),
        SIMDE_FLOAT32_C(  -876.39), SIMDE_FLOAT32_C(  -855.24), SIMDE_FLOAT32_C(  -760.38), SIMDE_FLOAT32_C(   889.77) },
      { SIMDE_FLOAT32_C(  -963.72), SIMDE_FLOAT32_C(   916.52), SIMDE_FLOAT32_C(   901.26), SIMDE_FLOAT32_C(  -579.25),
        SIMDE_FLOAT32_C(  -732.94), SIMDE_FLOAT32_C(   622.62), SIMDE_FLOAT32_C(  -921.84), SIMDE_FLOAT32_C(   506.77) },
      { SIMDE_FLOAT32_C(   579.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     3.50), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -588.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -664.25), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(148),
      { SIMDE_FLOAT32_C(  -843.43), SIMDE_FLOAT32_C(   423.67), SIMDE_FLOAT32_C(  -445.35), SIMDE_FLOAT32_C(  -230.96),
        SIMDE_FLOAT32_C(   679.27), SIMDE_FLOAT32_C(   471.72), SIMDE_FLOAT32_C(   149.86), SIMDE_FLOAT32_C(   654.09) },
      { SIMDE_FLOAT32_C(  -121.41), SIMDE_FLOAT32_C(   471.79), SIMDE_FLOAT32_C(  -537.85), SIMDE_FLOAT32_C(  -697.83),
        SIMDE_FLOAT32_C(   254.29), SIMDE_FLOAT32_C(  -586.94), SIMDE_FLOAT32_C(   941.43), SIMDE_FLOAT32_C(   199.61) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -2.10), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.05) } },
    { UINT8_C( 23),
      { SIMDE_FLOAT32_C(   321.35), SIMDE_FLOAT32_C(   323.22), SIMDE_FLOAT32_C(  -969.61), SIMDE_FLOAT32_C(   560.97),
        SIMDE_FLOAT32_C(   212.99), SIMDE_FLOAT32_C(  -933.33), SIMDE_FLOAT32_C(   477.49), SIMDE_FLOAT32_C(   114.25) },
      { SIMDE_FLOAT32_C(  -512.58), SIMDE_FLOAT32_C(   744.56), SIMDE_FLOAT32_C(  -263.13), SIMDE_FLOAT32_C(  -434.43),
        SIMDE_FLOAT32_C(   251.33), SIMDE_FLOAT32_C(    99.15), SIMDE_FLOAT32_C(  -277.86), SIMDE_FLOAT32_C(  -325.00) },
      { SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(    -2.03), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   208.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(225),
      { SIMDE_FLOAT32_C(   491.18), SIMDE_FLOAT32_C(  -645.73), SIMDE_FLOAT32_C(   125.52), SIMDE_FLOAT32_C(  -358.96),
        SIMDE_FLOAT32_C(  -991.64), SIMDE_FLOAT32_C(  -995.89), SIMDE_FLOAT32_C(  -887.17), SIMDE_FLOAT32_C(  -529.49) },
      { SIMDE_FLOAT32_C(  -693.72), SIMDE_FLOAT32_C(   367.12), SIMDE_FLOAT32_C(  -116.43), SIMDE_FLOAT32_C(  -752.29),
        SIMDE_FLOAT32_C(  -433.27), SIMDE_FLOAT32_C(  -230.80), SIMDE_FLOAT32_C(   569.06), SIMDE_FLOAT32_C(   889.95) },
      { SIMDE_FLOAT32_C(     2.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -3.51), SIMDE_FLOAT32_C(   561.04), SIMDE_FLOAT32_C(   529.44) } },
    { UINT8_C(  6),
      { SIMDE_FLOAT32_C(   130.03), SIMDE_FLOAT32_C(   102.94), SIMDE_FLOAT32_C(  -133.75), SIMDE_FLOAT32_C(  -392.48),
        SIMDE_FLOAT32_C(  -782.81), SIMDE_FLOAT32_C(   353.67), SIMDE_FLOAT32_C(  -647.92), SIMDE_FLOAT32_C(   -45.94) },
      { SIMDE_FLOAT32_C(   919.24), SIMDE_FLOAT32_C(   603.40), SIMDE_FLOAT32_C(  -946.78), SIMDE_FLOAT32_C(  -358.61),
        SIMDE_FLOAT32_C(  -721.59), SIMDE_FLOAT32_C(   707.02), SIMDE_FLOAT32_C(  -867.43), SIMDE_FLOAT32_C(  -367.32) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(    -2.07), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[i])); i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_loadu_ps(test_vec[i].r);
    simde_assert_m256_close(simde_mm256_maskz_and_ps(k, a, b), r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(-1000.0, 1000.0);
    simde__m256 b = simde_test_x86_random_f32x8(-1000.0, 1000.0);
    simde__m256 r = simde_mm256_maskz_and_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_and_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    int32_t src[8];
    simde__mmask8 k;
    int32_t a[8];
    int32_t b[8];
    int32_t r[8];
  } test_vec[8] = {
    { {  INT32_C(  1609349328), -INT32_C(   122429675), -INT32_C(  2085072494),  INT32_C(  1975683674),  INT32_C(  1854630250), -INT32_C(  1477002589),  INT32_C(    58722856),  INT32_C(  1083694192) },
      UINT8_C(148),
      {  INT32_C(  1672060803), -INT32_C(  1527406253), -INT32_C(   453019302), -INT32_C(  1521585093), -INT32_C(  1169638145), -INT32_C(  1109200973),  INT32_C(  1278076272),  INT32_C(    14708092) },
      {  INT32_C(  1617135885), -INT32_C(  2063312853),  INT32_C(   224986065),  INT32_C(  2008201079),  INT32_C(   657586804),  INT32_C(  1508119529),  INT32_C(  1956975352), -INT32_C(  1938520705) },
      {  INT32_C(  1609349328), -INT32_C(   122429675),  INT32_C(    73990480),  INT32_C(  1975683674),  INT32_C(   570472564), -INT32_C(  1477002589),  INT32_C(    58722856),  INT32_C(     6292860) } },
    { {  INT32_C(   988600079),  INT32_C(    29356336),  INT32_C(  1812867316),  INT32_C(  1407434975), -INT32_C(  1535503174),  INT32_C(   536698663), -INT32_C(   258759823),  INT32_C(   930940968) },
      UINT8_C(223),
      {  INT32_C(  1510961513),  INT32_C(  1481576752), -INT32_C(   533152993), -INT32_C(  1298494562),  INT32_C(  1708736006), -INT32_C(   539559876), -INT32_C(  1828206965), -INT32_C(  1384956093) },
      { -INT32_C(   519601488), -INT32_C(  1288087917), -INT32_C(  1349291759),  INT32_C(    56700413), -INT32_C(  1469564308), -INT32_C(  1098432974),  INT32_C(  1213304324),  INT32_C(  2130035917) },
      {  INT32_C(  1074200608),  INT32_C(   269029392), -INT32_C(  1609551599),  INT32_C(    33556892),  INT32_C(   541604356),  INT32_C(   536698663),  INT32_C(       99840),  INT32_C(   745604161) } },
    { { -INT32_C(   631243705),  INT32_C(  1687001171),  INT32_C(   118759434), -INT32_C(  1173719730), -INT32_C(   496864592), -INT32_C(  1264522832),  INT32_C(  1174205047), -INT32_C(    37490250) },
      UINT8_C(238),
      { -INT32_C(  1170089950), -INT32_C(  2033932955),  INT32_C(   802474937),  INT32_C(  1205833429), -INT32_C(   638074384),  INT32_C(  1414573154), -INT32_C(  1710582360),  INT32_C(  2055735384) },
      {  INT32_C(  1161152992),  INT32_C(   684456302), -INT32_C(  1705533499),  INT32_C(   501364269),  INT32_C(  1509349879),  INT32_C(   783107973),  INT32_C(   902346972), -INT32_C(  1599123264) },
      { -INT32_C(   631243705),  INT32_C(    12624228),  INT32_C(   173312897),  INT32_C(    96601605), -INT32_C(   496864592),  INT32_C(    67109888),  INT32_C(   268996744),  INT32_C(   545783872) } },
    { { -INT32_C(  2014976999), -INT32_C(  1548766754),  INT32_C(  2117928528),  INT32_C(   882581308),  INT32_C(  2123207417), -INT32_C(  1247003687), -INT32_C(  1276480269), -INT32_C(   581723452) },
      UINT8_C(126),
      { -INT32_C(   379820744),  INT32_C(   456851220),  INT32_C(  1549252669), -INT32_C(   447378605),  INT32_C(  1421792281), -INT32_C(   179866496), -INT32_C(   122029474), -INT32_C(  2055760051) },
      {  INT32_C(   275764220),  INT32_C(   271296979), -INT32_C(  1267956895),  INT32_C(   664453646),  INT32_C(   377182358),  INT32_C(   722191052),  INT32_C(   153339324),  INT32_C(  1485806172) },
      { -INT32_C(  2014976999),  INT32_C(   271231248),  INT32_C(   340033569),  INT32_C(   621838850),  INT32_C(   339365904),  INT32_C(   553861248),  INT32_C(   136429596), -INT32_C(   581723452) } },
    { {  INT32_C(  1097399918),  INT32_C(   139564199),  INT32_C(   633126167),  INT32_C(   357389951),  INT32_C(  2066532527),  INT32_C(  1202075531),  INT32_C(  1481755388), -INT32_C(   760160156) },
      UINT8_C(222),
      { -INT32_C(  1383787751),  INT32_C(   583306596), -INT32_C(  1600001719), -INT32_C(    11552970),  INT32_C(   445303523),  INT32_C(   991416689),  INT32_C(    44003106),  INT32_C(   971010592) },
      { -INT32_C(   353999483),  INT32_C(  1007463154), -INT32_C(   891507309),  INT32_C(  1204366180),  INT32_C(  1717720053),  INT32_C(  1201764644),  INT32_C(   139018728),  INT32_C(   943794867) },
      {  INT32_C(  1097399918),  INT32_C(   537167968), -INT32_C(  2139051775),  INT32_C(  1195975460),  INT32_C(    33702625),  INT32_C(  1202075531),  INT32_C(      606496),  INT32_C(   943727136) } },
    { { -INT32_C(  2111690865),  INT32_C(  1706962641),  INT32_C(  1076861660), -INT32_C(  1165428539),  INT32_C(  1864493643),  INT32_C(  1270268515), -INT32_C(  1236008957), -INT32_C(  1175481046) },
      UINT8_C(189),
      {  INT32_C(  1083063057), -INT32_C(  1826819079),  INT32_C(   441998370), -INT32_C(   832236572), -INT32_C(   164506316), -INT32_C(  1946518133),  INT32_C(  1723183313), -INT32_C(  1323077729) },
      { -INT32_C(  1527663958), -INT32_C(   935916123),  INT32_C(  1323470953), -INT32_C(   686012253), -INT32_C(  1462940131), -INT32_C(  1674262581),  INT32_C(   386066808),  INT32_C(    63448664) },
      {  INT32_C(     8401408),  INT32_C(  1706962641),  INT32_C(   171970592), -INT32_C(   972816224), -INT32_C(  1610529772), -INT32_C(  2010102389), -INT32_C(  1236008957),  INT32_C(    16786968) } },
    { {  INT32_C(  2108144088),  INT32_C(   809885382),  INT32_C(   293480558), -INT32_C(  1914135952), -INT32_C(  1288325400), -INT32_C(   179345027), -INT32_C(  1425190317),  INT32_C(  1353635192) },
      UINT8_C(143),
      {  INT32_C(   878038357),  INT32_C(  1000506643), -INT32_C(  1632914429),  INT32_C(  1384528028), -INT32_C(   674219411), -INT32_C(   617953911), -INT32_C(  1470900782), -INT32_C(   650665084) },
      { -INT32_C(  2079486863),  INT32_C(   364883986),  INT32_C(    11758180),  INT32_C(   257112738), -INT32_C(    35249292), -INT32_C(  1143402264),  INT32_C(  1784884454),  INT32_C(  1094949584) },
      {  INT32_C(    67472465),  INT32_C(   295862290),  INT32_C(    10690560),  INT32_C(    33699968), -INT32_C(  1288325400), -INT32_C(   179345027), -INT32_C(  1425190317),  INT32_C(  1090749056) } },
    { {  INT32_C(   952455462),  INT32_C(  1699644417), -INT32_C(  1872428562), -INT32_C(  1348487109), -INT32_C(   995260709),  INT32_C(  2088732310), -INT32_C(  2098797902), -INT32_C(  1564267908) },
      UINT8_C(123),
      {  INT32_C(   209509256),  INT32_C(   721084713), -INT32_C(    10057146), -INT32_C(  1327885014),  INT32_C(  1212587714), -INT32_C(      277731), -INT32_C(   746881623), -INT32_C(   917627327) },
      {  INT32_C(   584502009), -INT32_C(   229846869), -INT32_C(  2047757733), -INT32_C(  1976185912), -INT32_C(  2016183446), -INT32_C(   393753026), -INT32_C(  1933901237),  INT32_C(   425069088) },
      {  INT32_C(     5556872),  INT32_C(   575193129), -INT32_C(  1872428562), -INT32_C(  2146434808),  INT32_C(     4332098), -INT32_C(   394018276), -INT32_C(  2143617015), -INT32_C(  1564267908) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i src = simde_mm256_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_loadu_epi32(test_vec[i].r);
    simde_assert_m256i_i32(simde_mm256_mask_and_epi32(src, k, a, b), ==, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_and_epi32(src, k, a, b);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_and_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde__mmask8 k;
    int32_t a[8];
    int32_t b[8];
    int32_t r[8];
  } test_vec[8] = {
    { UINT8_C(  8),
      { -INT32_C(   729626035),  INT32_C(    73185265),  INT32_C(  2075207522),  INT32_C(   236826847), -INT32_C(    86728075), -INT32_C(  1718502737), -INT32_C(   748114453), -INT32_C(   639935604) },
      {  INT32_C(   380460325),  INT32_C(  1998260500),  INT32_C(   284347441), -INT32_C(   232910980),  INT32_C(  1642918577), -INT32_C(  1728414291), -INT32_C(  1234410710), -INT32_C(   477149250) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    35389532),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(165),
      {  INT32_C(  1186593340), -INT32_C(   512282603),  INT32_C(   845055779), -INT32_C(  1746644827), -INT32_C(  1186708164), -INT32_C(  1562059457), -INT32_C(  1872717239),  INT32_C(  1714766890) },
      {  INT32_C(  1403842366),  INT32_C(  1110713119),  INT32_C(  1333105322),  INT32_C(   518478306), -INT32_C(   573035618),  INT32_C(  1367391240), -INT32_C(  2132615082),  INT32_C(  1659311908) },
      {  INT32_C(  1118366268),  INT32_C(           0),  INT32_C(    39092770),  INT32_C(           0),  INT32_C(           0),  INT32_C(     8428552),  INT32_C(           0),  INT32_C(  1646593056) } },
    { UINT8_C(  6),
      { -INT32_C(  1222199917),  INT32_C(  2086758634),  INT32_C(   912241117), -INT32_C(  1009484392),  INT32_C(   298627669),  INT32_C(   308813106),  INT32_C(   389540095),  INT32_C(  1662884303) },
      {  INT32_C(   958022479), -INT32_C(  1984595028), -INT32_C(   994044884), -INT32_C(   410479470),  INT32_C(  2029605958),  INT32_C(  1904959857),  INT32_C(   428393033), -INT32_C(  1434671781) },
      {  INT32_C(           0),  INT32_C(   136407208),  INT32_C(    71307276),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(233),
      {  INT32_C(   295035798), -INT32_C(  1388437863),  INT32_C(  1933509342), -INT32_C(   558291062), -INT32_C(  2125450720),  INT32_C(  2143994301), -INT32_C(   287644855), -INT32_C(   170424993) },
      {  INT32_C(    17263720),  INT32_C(  1773094283), -INT32_C(   757273017),  INT32_C(   900765205), -INT32_C(  2051669816),  INT32_C(   168067521), -INT32_C(   990257564), -INT32_C(   860237725) },
      {  INT32_C(    17129472),  INT32_C(           0),  INT32_C(           0),  INT32_C(   347080192),  INT32_C(           0),  INT32_C(   167805313), -INT32_C(   992427456), -INT32_C(   997097405) } },
    { UINT8_C( 61),
      {  INT32_C(    97045952),  INT32_C(  1800221052), -INT32_C(  1535107314), -INT32_C(   798181681), -INT32_C(   309202580), -INT32_C(   749560587),  INT32_C(  1698109077), -INT32_C(  1868430385) },
      {  INT32_C(  1301637840), -INT32_C(  1430723940), -INT32_C(   783403007),  INT32_C(  1537325806), -INT32_C(  1605881173),  INT32_C(  1668520654), -INT32_C(  2134267216),  INT32_C(  2115005357) },
      {  INT32_C(    92293312),  INT32_C(           0), -INT32_C(  2147477504),  INT32_C(  1344320206), -INT32_C(  1610600408),  INT32_C(  1129486532),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(214),
      { -INT32_C(  2005742683), -INT32_C(  1148642173),  INT32_C(   615144042),  INT32_C(   785319419), -INT32_C(   386109619), -INT32_C(  1919393566), -INT32_C(  1808132055), -INT32_C(   831866840) },
      {  INT32_C(   106355843),  INT32_C(  1656938488),  INT32_C(   898001978), -INT32_C(  1100786319), -INT32_C(  1482268476), -INT32_C(   382451776), -INT32_C(  2139263401), -INT32_C(  1437669337) },
      {  INT32_C(           0),  INT32_C(   578821248),  INT32_C(   612517930),  INT32_C(           0), -INT32_C(  1599840188),  INT32_C(           0), -INT32_C(  2143811583), -INT32_C(  1974818784) } },
    { UINT8_C(196),
      { -INT32_C(  2084720220), -INT32_C(   541253773), -INT32_C(    78580826), -INT32_C(  1228927402), -INT32_C(   193566795),  INT32_C(   155934619), -INT32_C(   986657827), -INT32_C(  1115038951) },
      { -INT32_C(    12499316),  INT32_C(   215940710),  INT32_C(  1208430321), -INT32_C(   234961092), -INT32_C(   907709138), -INT32_C(  1311559212),  INT32_C(   376833020),  INT32_C(  1792213214) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1207968416),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    70255580),  INT32_C(   679542808) } },
    { UINT8_C( 70),
      {  INT32_C(   330066196),  INT32_C(  1963243591), -INT32_C(  2018358080), -INT32_C(  1061772469), -INT32_C(  1164673143),  INT32_C(  1454786130), -INT32_C(  1137390404), -INT32_C(  1274830944) },
      {  INT32_C(  1355263752),  INT32_C(   684051560),  INT32_C(  1672443672), -INT32_C(  1541184229),  INT32_C(   928954597), -INT32_C(  1165159170), -INT32_C(  2122857759),  INT32_C(  1765112417) },
      {  INT32_C(           0),  INT32_C(   537167936),  INT32_C(    60965888),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2144026464),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_loadu_epi32(test_vec[i].r);
    simde_assert_m256i_i32(simde_mm256_maskz_and_epi32(k, a, b), ==, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_and_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_and_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    int64_t src[4];
    simde__mmask8 k;
    int64_t a[4];
    int64_t b[4];
    int64_t r[4];
  } test_vec[8] = {
    { { -INT64_C( 5622584852095140270), -INT64_C( 4636869636498172520), -INT64_C( 4758047597486247339), -INT64_C( 4564827659925780983) },
      UINT8_C(247),
      { -INT64_C( 1139545277404503290),  INT64_C( 4980225633458138432),  INT64_C( 8271967291477947582),  INT64_C( 4439880968540557357) },
      {  INT64_C( 4093213474456629827),  INT64_C( 7874856961445945136), -INT64_C( 7606304441797477743),  INT64_C( 3746954142581280907) },
      {  INT64_C( 3462706896896795138),  INT64_C( 4974525418294021376),  INT64_C( 1315308826813100176), -INT64_C( 4564827659925780983) } },
    { {  INT64_C(  467213097704215372),  INT64_C( 2907728421403130686),  INT64_C( 1066111227079854541),  INT64_C( 3317412273220225254) },
      UINT8_C(163),
      {  INT64_C( 7509612663244747034),  INT64_C(  552298429661783178), -INT64_C( 5491407832072134578), -INT64_C( 4333092134877552535) },
      {  INT64_C( 7100755867829294901), -INT64_C(   27889449236985577),  INT64_C( 2966092867428361930), -INT64_C( 5208061662365303219) },
      {  INT64_C( 6918233561731977488),  INT64_C(  542727944225619970),  INT64_C( 1066111227079854541),  INT64_C( 3317412273220225254) } },
    { {  INT64_C( 9209970538160158102), -INT64_C( 4351127078824570900),  INT64_C( 8989011333483168215), -INT64_C(  551360681527336416) },
      UINT8_C(161),
      {  INT64_C( 5008716603111138866),  INT64_C( 4477988416574660766), -INT64_C( 7079964847048377285), -INT64_C( 1429339026195783589) },
      {  INT64_C( 6545987266358162269),  INT64_C( 6134129307329042212), -INT64_C( 3340631378097894006), -INT64_C(  668640947611262447) },
      {  INT64_C( 4647715041217487376), -INT64_C( 4351127078824570900),  INT64_C( 8989011333483168215), -INT64_C(  551360681527336416) } },
    { {  INT64_C( 7119173131298224821), -INT64_C( 3537186890438183559), -INT64_C( 7045750167821820688), -INT64_C( 3987337052073324262) },
      UINT8_C( 92),
      {  INT64_C( 8795525698192816435),  INT64_C( 7463463538858566207), -INT64_C( 4327515920345531808), -INT64_C( 9044461363969743363) },
      {  INT64_C( 5789138803685332439),  INT64_C(  125124016661009865),  INT64_C( 4717180056141148545), -INT64_C( 4521090749640455057) },
      {  INT64_C( 7119173131298224821), -INT64_C( 3537186890438183559),  INT64_C( 4715411748848447488), -INT64_C( 9204906520242813843) } },
    { {  INT64_C( 5283274867525704176),  INT64_C( 5597512321512391947), -INT64_C( 4498684456864807156), -INT64_C( 4869022537306017342) },
      UINT8_C( 26),
      {  INT64_C( 5984689129157999884), -INT64_C( 1087218633096054142), -INT64_C( 4925806823010584212), -INT64_C( 3864295470771253116) },
      {  INT64_C( 6801237926447216896),  INT64_C( 6551933641763291540), -INT64_C( 5124285811881332643), -INT64_C( 6000381655670494926) },
      {  INT64_C( 5283274867525704176),  INT64_C( 5830231225412583552), -INT64_C( 4498684456864807156), -INT64_C( 8639521826595848192) } },
    { { -INT64_C(  896184031153256875),  INT64_C( 5613700585278720926),  INT64_C( 4033632096365126670), -INT64_C( 6333502177513310271) },
      UINT8_C(103),
      {  INT64_C( 3859789844864031189),  INT64_C( 2924931846806773163), -INT64_C( 3890998120075634201),  INT64_C( 6689470006987419020) },
      {  INT64_C(  161530726549724318), -INT64_C( 4888619101573127428),  INT64_C( 5159150152907970043),  INT64_C( 1750926615769363816) },
      {  INT64_C(    4673203595548820),  INT64_C( 2882341162092396712),  INT64_C( 4755908486433952227), -INT64_C( 6333502177513310271) } },
    { {  INT64_C( 8538927674177919783),  INT64_C( 2904995678255451071), -INT64_C( 5839604907581748237),  INT64_C( 6617453839242930755) },
      UINT8_C(134),
      {  INT64_C( 7211237554367027702),  INT64_C( 4791190051424937964), -INT64_C( 3855021768929956945),  INT64_C(  668320635599928789) },
      { -INT64_C( 6272828475357510092), -INT64_C( 1418722680849136874), -INT64_C( 2033751200391047205),  INT64_C( 5982162528629933544) },
      {  INT64_C( 8538927674177919783),  INT64_C( 4633545636867769092), -INT64_C( 4431504648980397173),  INT64_C( 6617453839242930755) } },
    { { -INT64_C( 1831887729145585617),  INT64_C( 5728652893992830294),  INT64_C( 4326852395163953691), -INT64_C( 4086669658726879274) },
      UINT8_C(156),
      {  INT64_C(  744028824004244010),  INT64_C( 1271649413902559046), -INT64_C( 8574674632615539175),  INT64_C( 7544066204162455001) },
      { -INT64_C( 5266474399092630118),  INT64_C( 5627499750317123488), -INT64_C(  498078631865057869), -INT64_C( 5109968059430455442) },
      { -INT64_C( 1831887729145585617),  INT64_C( 5728652893992830294), -INT64_C( 8574818394331657199),  INT64_C( 2887273682990806344) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i src = simde_mm256_loadu_epi64(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_loadu_epi64(test_vec[i].r);
    simde_assert_m256i_i32(simde_mm256_mask_and_epi64(src, k, a, b), ==, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_and_epi64(src, k, a, b);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_and_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde__mmask8 k;
    int64_t a[4];
    int64_t b[4];
    int64_t r[4];
  } test_vec[8] = {
    { UINT8_C( 87),
      {  INT64_C( 6370394293983455551),  INT64_C( 6466085924317052977), -INT64_C(   81672145783098074), -INT64_C( 1853627449083977917) },
      { -INT64_C( 5263834378320849472),  INT64_C( 5951261906485708378),  INT64_C( 4589706762517226518),  INT64_C( 8653232064175153289) },
      {  INT64_C( 1179954653819961600),  INT64_C( 5806301142136651792),  INT64_C( 4508597567835874310),  INT64_C(                   0) } },
    { UINT8_C(201),
      {  INT64_C(  954205702485578697),  INT64_C( 4008638055097924458),  INT64_C( 2669069997626774680),  INT64_C( 1935796122041465503) },
      { -INT64_C( 7314906615533196440), -INT64_C( 2882085779962219081),  INT64_C( 4919167349058843418), -INT64_C( 2519143360412311137) },
      {  INT64_C(  593350352083616584),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1731656395122811039) } },
    { UINT8_C( 96),
      {  INT64_C( 9077616138045639687), -INT64_C(  634560303526395056), -INT64_C( 5263336232009903632), -INT64_C(  735483194539973577) },
      { -INT64_C( 2910395703279199146), -INT64_C( 2183928125997557002),  INT64_C( 7186946948924329073),  INT64_C( 5256152608532261134) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(246),
      {  INT64_C( 6724529567030929194),  INT64_C(  780300026391628867), -INT64_C( 9179293064282842524), -INT64_C( 5406646626230757273) },
      {  INT64_C(  901392590988932130),  INT64_C( 7149257692437008495),  INT64_C( 7869352083373255965), -INT64_C( 8762766392313272282) },
      {  INT64_C(                   0),  INT64_C(  149747694645870659),  INT64_C(    5779061103151108),  INT64_C(                   0) } },
    { UINT8_C(219),
      { -INT64_C(  123936749479744395),  INT64_C( 1765235868168975391),  INT64_C( 1298879933180687441), -INT64_C( 8053283739604175109) },
      { -INT64_C( 5776236435431956311), -INT64_C( 8869679814402780380), -INT64_C( 8267928789805955387),  INT64_C( 6830601317232130080) },
      { -INT64_C( 5888843537388101599),  INT64_C(   29273549010194436),  INT64_C(                   0),  INT64_C( 1155218457972092960) } },
    { UINT8_C( 12),
      { -INT64_C( 2375846660172663245), -INT64_C( 4200566805647665571), -INT64_C( 2412270076627000326), -INT64_C( 4680380700324282156) },
      {  INT64_C( 5842200007949854760), -INT64_C( 5331148448836082304),  INT64_C( 1502970002131278807), -INT64_C( 8598744562395812256) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1477608389479646162), -INT64_C( 8643795264637550528) } },
    { UINT8_C(199),
      { -INT64_C(  831181518872527794),  INT64_C( 1448020226039920204),  INT64_C( 6809558017128011136),  INT64_C( 7305479712271199356) },
      {  INT64_C( 8559324367922470148),  INT64_C( 6798411091546634378), -INT64_C( 7984039819678405149),  INT64_C( 4388632735249133930) },
      {  INT64_C( 8376699747151977476),  INT64_C( 1447984899933876232),  INT64_C( 1153035922541118848),  INT64_C(                   0) } },
    { UINT8_C(171),
      {  INT64_C( 5810571335756484676), -INT64_C( 1318556055890893055), -INT64_C( 6164138467522345205),  INT64_C( 2520361976855721664) },
      {  INT64_C( 2042345159407685423),  INT64_C( 2086185947882096070),  INT64_C( 5370993947561096486), -INT64_C( 5003618433936823152) },
      {  INT64_C( 1153847396494540804),  INT64_C(  915229080917148928),  INT64_C(                   0),  INT64_C( 2488823224507327616) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_loadu_epi64(test_vec[i].r);
    simde_assert_m256i_i64(simde_mm256_maskz_and_epi64(k, a, b), ==, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_and_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_and_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   260.00), SIMDE_FLOAT32_C(   472.07), SIMDE_FLOAT32_C(   343.37), SIMDE_FLOAT32_C(   668.63),
                         SIMDE_FLOAT32_C(    74.64), SIMDE_FLOAT32_C(  -166.33), SIMDE_FLOAT32_C(   962.01), SIMDE_FLOAT32_C(   120.25),
                         SIMDE_FLOAT32_C(  -633.54), SIMDE_FLOAT32_C(  -160.44), SIMDE_FLOAT32_C(  -754.35), SIMDE_FLOAT32_C(   920.06),
                         SIMDE_FLOAT32_C(  -752.65), SIMDE_FLOAT32_C(   -15.27), SIMDE_FLOAT32_C(   736.97), SIMDE_FLOAT32_C(   591.25)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   968.14), SIMDE_FLOAT32_C(   728.35), SIMDE_FLOAT32_C(  -574.47), SIMDE_FLOAT32_C(   770.03),
                         SIMDE_FLOAT32_C(  -456.43), SIMDE_FLOAT32_C(   727.04), SIMDE_FLOAT32_C(   -89.84), SIMDE_FLOAT32_C(   288.08),
                         SIMDE_FLOAT32_C(  -720.94), SIMDE_FLOAT32_C(  -964.02), SIMDE_FLOAT32_C(   974.54), SIMDE_FLOAT32_C(  -246.99),
                         SIMDE_FLOAT32_C(  -603.24), SIMDE_FLOAT32_C(  -592.85), SIMDE_FLOAT32_C(  -351.71), SIMDE_FLOAT32_C(   472.50)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.03), SIMDE_FLOAT32_C(     2.56), SIMDE_FLOAT32_C(     2.18), SIMDE_FLOAT32_C(   512.00),
                         SIMDE_FLOAT32_C(    66.01), SIMDE_FLOAT32_C(     2.57), SIMDE_FLOAT32_C(     2.76), SIMDE_FLOAT32_C(    72.00),
                         SIMDE_FLOAT32_C(  -592.50), SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(   706.03), SIMDE_FLOAT32_C(     3.59),
                         SIMDE_FLOAT32_C(  -592.14), SIMDE_FLOAT32_C(    -2.31), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     2.00)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -440.60), SIMDE_FLOAT32_C(   215.95), SIMDE_FLOAT32_C(  -449.65), SIMDE_FLOAT32_C(   426.70),
                         SIMDE_FLOAT32_C(   107.08), SIMDE_FLOAT32_C(  -345.64), SIMDE_FLOAT32_C(   226.40), SIMDE_FLOAT32_C(   712.58),
                         SIMDE_FLOAT32_C(  -396.23), SIMDE_FLOAT32_C(  -256.01), SIMDE_FLOAT32_C(   622.69), SIMDE_FLOAT32_C(  -188.83),
                         SIMDE_FLOAT32_C(   358.20), SIMDE_FLOAT32_C(  -542.16), SIMDE_FLOAT32_C(   982.13), SIMDE_FLOAT32_C(   702.83)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   347.10), SIMDE_FLOAT32_C(  -175.94), SIMDE_FLOAT32_C(   817.30), SIMDE_FLOAT32_C(  -721.72),
                         SIMDE_FLOAT32_C(   775.39), SIMDE_FLOAT32_C(  -218.71), SIMDE_FLOAT32_C(   919.20), SIMDE_FLOAT32_C(  -300.97),
                         SIMDE_FLOAT32_C(   919.48), SIMDE_FLOAT32_C(   -61.84), SIMDE_FLOAT32_C(   121.47), SIMDE_FLOAT32_C(   499.98),
                         SIMDE_FLOAT32_C(   538.40), SIMDE_FLOAT32_C(  -622.49), SIMDE_FLOAT32_C(  -852.24), SIMDE_FLOAT32_C(   445.35)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   280.10), SIMDE_FLOAT32_C(   135.94), SIMDE_FLOAT32_C(     3.01), SIMDE_FLOAT32_C(     2.32),
                         SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(  -136.57), SIMDE_FLOAT32_C(     3.50), SIMDE_FLOAT32_C(     2.28),
                         SIMDE_FLOAT32_C(     3.06), SIMDE_FLOAT32_C(   -32.00), SIMDE_FLOAT32_C(     2.29), SIMDE_FLOAT32_C(   184.83),
                         SIMDE_FLOAT32_C(     2.03), SIMDE_FLOAT32_C(  -526.16), SIMDE_FLOAT32_C(   852.13), SIMDE_FLOAT32_C(     2.23)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -590.91), SIMDE_FLOAT32_C(  -663.88), SIMDE_FLOAT32_C(  -394.32), SIMDE_FLOAT32_C(  -991.87),
                         SIMDE_FLOAT32_C(   385.94), SIMDE_FLOAT32_C(  -349.46), SIMDE_FLOAT32_C(  -786.25), SIMDE_FLOAT32_C(   192.19),
                         SIMDE_FLOAT32_C(  -594.16), SIMDE_FLOAT32_C(  -602.03), SIMDE_FLOAT32_C(   176.16), SIMDE_FLOAT32_C(  -458.14),
                         SIMDE_FLOAT32_C(   335.26), SIMDE_FLOAT32_C(  -272.70), SIMDE_FLOAT32_C(   585.90), SIMDE_FLOAT32_C(  -571.61)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   530.04), SIMDE_FLOAT32_C(  -606.85), SIMDE_FLOAT32_C(   112.20), SIMDE_FLOAT32_C(  -437.59),
                         SIMDE_FLOAT32_C(  -396.36), SIMDE_FLOAT32_C(  -280.58), SIMDE_FLOAT32_C(   819.31), SIMDE_FLOAT32_C(  -726.73),
                         SIMDE_FLOAT32_C(  -263.24), SIMDE_FLOAT32_C(  -511.40), SIMDE_FLOAT32_C(  -175.25), SIMDE_FLOAT32_C(   728.37),
                         SIMDE_FLOAT32_C(   881.16), SIMDE_FLOAT32_C(   -49.97), SIMDE_FLOAT32_C(   618.76), SIMDE_FLOAT32_C(  -518.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   514.03), SIMDE_FLOAT32_C(  -534.75), SIMDE_FLOAT32_C(    96.06), SIMDE_FLOAT32_C(    -3.29),
                         SIMDE_FLOAT32_C(   384.31), SIMDE_FLOAT32_C(  -280.08), SIMDE_FLOAT32_C(   786.25), SIMDE_FLOAT32_C(     2.00),
                         SIMDE_FLOAT32_C(    -2.01), SIMDE_FLOAT32_C(    -2.35), SIMDE_FLOAT32_C(   160.00), SIMDE_FLOAT32_C(     2.56),
                         SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   -32.06), SIMDE_FLOAT32_C(   584.76), SIMDE_FLOAT32_C(  -514.56)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   515.17), SIMDE_FLOAT32_C(   324.54), SIMDE_FLOAT32_C(    91.18), SIMDE_FLOAT32_C(  -165.19),
                         SIMDE_FLOAT32_C(  -882.22), SIMDE_FLOAT32_C(   833.89), SIMDE_FLOAT32_C(   476.02), SIMDE_FLOAT32_C(   887.60),
                         SIMDE_FLOAT32_C(   229.74), SIMDE_FLOAT32_C(   342.64), SIMDE_FLOAT32_C(   541.23), SIMDE_FLOAT32_C(  -642.89),
                         SIMDE_FLOAT32_C(   701.90), SIMDE_FLOAT32_C(   393.90), SIMDE_FLOAT32_C(  -103.65), SIMDE_FLOAT32_C(   243.25)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    21.91), SIMDE_FLOAT32_C(  -134.28), SIMDE_FLOAT32_C(   125.14), SIMDE_FLOAT32_C(  -667.85),
                         SIMDE_FLOAT32_C(  -778.80), SIMDE_FLOAT32_C(  -220.75), SIMDE_FLOAT32_C(   348.36), SIMDE_FLOAT32_C(    29.88),
                         SIMDE_FLOAT32_C(  -634.89), SIMDE_FLOAT32_C(  -148.88), SIMDE_FLOAT32_C(   827.50), SIMDE_FLOAT32_C(  -532.87),
                         SIMDE_FLOAT32_C(  -762.33), SIMDE_FLOAT32_C(   247.69), SIMDE_FLOAT32_C(  -238.64), SIMDE_FLOAT32_C(   244.40)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(   130.27), SIMDE_FLOAT32_C(    89.13), SIMDE_FLOAT32_C(    -2.57),
                         SIMDE_FLOAT32_C(  -770.03), SIMDE_FLOAT32_C(     3.25), SIMDE_FLOAT32_C(   348.02), SIMDE_FLOAT32_C(     3.20),
                         SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(   128.26), SIMDE_FLOAT32_C(   537.00), SIMDE_FLOAT32_C(  -512.76),
                         SIMDE_FLOAT32_C(   696.27), SIMDE_FLOAT32_C(   196.69), SIMDE_FLOAT32_C(   -51.50), SIMDE_FLOAT32_C(   240.25)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   139.73), SIMDE_FLOAT32_C(   808.22), SIMDE_FLOAT32_C(  -888.67), SIMDE_FLOAT32_C(   -90.81),
                         SIMDE_FLOAT32_C(    58.51), SIMDE_FLOAT32_C(  -297.55), SIMDE_FLOAT32_C(  -246.77), SIMDE_FLOAT32_C(  -391.18),
                         SIMDE_FLOAT32_C(   887.15), SIMDE_FLOAT32_C(   997.52), SIMDE_FLOAT32_C(   873.12), SIMDE_FLOAT32_C(  -969.73),
                         SIMDE_FLOAT32_C(   721.30), SIMDE_FLOAT32_C(  -128.28), SIMDE_FLOAT32_C(  -264.35), SIMDE_FLOAT32_C(  -432.42)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -80.65), SIMDE_FLOAT32_C(   -15.71), SIMDE_FLOAT32_C(    54.64), SIMDE_FLOAT32_C(  -420.79),
                         SIMDE_FLOAT32_C(  -573.45), SIMDE_FLOAT32_C(   578.20), SIMDE_FLOAT32_C(  -393.34), SIMDE_FLOAT32_C(   -79.47),
                         SIMDE_FLOAT32_C(  -837.77), SIMDE_FLOAT32_C(   169.23), SIMDE_FLOAT32_C(   110.87), SIMDE_FLOAT32_C(   428.31),
                         SIMDE_FLOAT32_C(   944.93), SIMDE_FLOAT32_C(   222.75), SIMDE_FLOAT32_C(  -792.23), SIMDE_FLOAT32_C(  -269.27)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    32.26), SIMDE_FLOAT32_C(     3.16), SIMDE_FLOAT32_C(     3.41), SIMDE_FLOAT32_C(   -72.01),
                         SIMDE_FLOAT32_C(     2.16), SIMDE_FLOAT32_C(     2.26), SIMDE_FLOAT32_C(  -196.50), SIMDE_FLOAT32_C(   -65.28),
                         SIMDE_FLOAT32_C(   837.02), SIMDE_FLOAT32_C(     2.64), SIMDE_FLOAT32_C(     3.38), SIMDE_FLOAT32_C(     3.28),
                         SIMDE_FLOAT32_C(   656.30), SIMDE_FLOAT32_C(   128.25), SIMDE_FLOAT32_C(    -2.06), SIMDE_FLOAT32_C(  -256.25)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -807.89), SIMDE_FLOAT32_C(  -195.99), SIMDE_FLOAT32_C(  -460.22), SIMDE_FLOAT32_C(  -214.31),
                         SIMDE_FLOAT32_C(  -242.49), SIMDE_FLOAT32_C(   293.67), SIMDE_FLOAT32_C(   209.36), SIMDE_FLOAT32_C(   -28.16),
                         SIMDE_FLOAT32_C(   861.78), SIMDE_FLOAT32_C(  -349.18), SIMDE_FLOAT32_C(  -840.98), SIMDE_FLOAT32_C(   667.88),
                         SIMDE_FLOAT32_C(  -431.60), SIMDE_FLOAT32_C(  -312.68), SIMDE_FLOAT32_C(   469.25), SIMDE_FLOAT32_C(   584.01)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   881.42), SIMDE_FLOAT32_C(   703.51), SIMDE_FLOAT32_C(   112.91), SIMDE_FLOAT32_C(    92.78),
                         SIMDE_FLOAT32_C(   506.44), SIMDE_FLOAT32_C(   923.94), SIMDE_FLOAT32_C(  -577.40), SIMDE_FLOAT32_C(  -437.14),
                         SIMDE_FLOAT32_C(  -379.29), SIMDE_FLOAT32_C(   791.05), SIMDE_FLOAT32_C(   859.09), SIMDE_FLOAT32_C(   612.11),
                         SIMDE_FLOAT32_C(   687.78), SIMDE_FLOAT32_C(   712.98), SIMDE_FLOAT32_C(  -143.15), SIMDE_FLOAT32_C(  -972.86)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   801.39), SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   112.03), SIMDE_FLOAT32_C(    36.01),
                         SIMDE_FLOAT32_C(   240.22), SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(     2.26), SIMDE_FLOAT32_C(   -24.00),
                         SIMDE_FLOAT32_C(     2.33), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(   840.07), SIMDE_FLOAT32_C(   512.00),
                         SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(   138.12), SIMDE_FLOAT32_C(   584.00)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   278.01), SIMDE_FLOAT32_C(  -815.62), SIMDE_FLOAT32_C(   752.91), SIMDE_FLOAT32_C(   710.22),
                         SIMDE_FLOAT32_C(  -124.40), SIMDE_FLOAT32_C(  -338.82), SIMDE_FLOAT32_C(  -853.49), SIMDE_FLOAT32_C(   731.62),
                         SIMDE_FLOAT32_C(   168.07), SIMDE_FLOAT32_C(  -402.61), SIMDE_FLOAT32_C(  -908.62), SIMDE_FLOAT32_C(   912.24),
                         SIMDE_FLOAT32_C(   241.90), SIMDE_FLOAT32_C(   493.82), SIMDE_FLOAT32_C(  -948.44), SIMDE_FLOAT32_C(   522.79)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -401.28), SIMDE_FLOAT32_C(   383.51), SIMDE_FLOAT32_C(  -854.57), SIMDE_FLOAT32_C(  -237.48),
                         SIMDE_FLOAT32_C(  -426.55), SIMDE_FLOAT32_C(  -605.26), SIMDE_FLOAT32_C(   140.00), SIMDE_FLOAT32_C(  -626.79),
                         SIMDE_FLOAT32_C(   473.63), SIMDE_FLOAT32_C(   968.53), SIMDE_FLOAT32_C(  -767.62), SIMDE_FLOAT32_C(  -339.51),
                         SIMDE_FLOAT32_C(   144.17), SIMDE_FLOAT32_C(   -47.64), SIMDE_FLOAT32_C(  -130.89), SIMDE_FLOAT32_C(   -19.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   272.01), SIMDE_FLOAT32_C(     2.18), SIMDE_FLOAT32_C(   592.50), SIMDE_FLOAT32_C(     2.52),
                         SIMDE_FLOAT32_C(  -104.13), SIMDE_FLOAT32_C(    -2.02), SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   594.54),
                         SIMDE_FLOAT32_C(   168.07), SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(  -652.62), SIMDE_FLOAT32_C(     2.50),
                         SIMDE_FLOAT32_C(   144.13), SIMDE_FLOAT32_C(    45.63), SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.03)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   491.53), SIMDE_FLOAT32_C(   985.75), SIMDE_FLOAT32_C(  -390.64), SIMDE_FLOAT32_C(   517.90),
                         SIMDE_FLOAT32_C(  -725.16), SIMDE_FLOAT32_C(     9.87), SIMDE_FLOAT32_C(   943.82), SIMDE_FLOAT32_C(   279.49),
                         SIMDE_FLOAT32_C(  -942.01), SIMDE_FLOAT32_C(    63.94), SIMDE_FLOAT32_C(   920.28), SIMDE_FLOAT32_C(   132.72),
                         SIMDE_FLOAT32_C(   502.41), SIMDE_FLOAT32_C(   855.02), SIMDE_FLOAT32_C(   610.59), SIMDE_FLOAT32_C(   860.61)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -675.66), SIMDE_FLOAT32_C(   128.22), SIMDE_FLOAT32_C(  -915.29), SIMDE_FLOAT32_C(  -679.65),
                         SIMDE_FLOAT32_C(   537.51), SIMDE_FLOAT32_C(  -484.11), SIMDE_FLOAT32_C(   502.40), SIMDE_FLOAT32_C(  -785.39),
                         SIMDE_FLOAT32_C(  -128.17), SIMDE_FLOAT32_C(   101.31), SIMDE_FLOAT32_C(  -990.73), SIMDE_FLOAT32_C(  -514.82),
                         SIMDE_FLOAT32_C(   231.21), SIMDE_FLOAT32_C(   964.21), SIMDE_FLOAT32_C(  -258.81), SIMDE_FLOAT32_C(   355.88)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(    -3.00), SIMDE_FLOAT32_C(   517.65),
                         SIMDE_FLOAT32_C(   529.00), SIMDE_FLOAT32_C(     9.00), SIMDE_FLOAT32_C(     3.67), SIMDE_FLOAT32_C(     2.00),
                         SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(    50.63), SIMDE_FLOAT32_C(   920.01), SIMDE_FLOAT32_C(     2.01),
                         SIMDE_FLOAT32_C(   227.20), SIMDE_FLOAT32_C(   836.02), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.27)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_and_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_and_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  266.26), SIMDE_FLOAT64_C(  537.32),
                         SIMDE_FLOAT64_C( -326.88), SIMDE_FLOAT64_C( -882.50),
                         SIMDE_FLOAT64_C(  -89.28), SIMDE_FLOAT64_C( -631.60),
                         SIMDE_FLOAT64_C( -243.67), SIMDE_FLOAT64_C(   78.08)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -676.48), SIMDE_FLOAT64_C( -545.20),
                         SIMDE_FLOAT64_C(  963.41), SIMDE_FLOAT64_C(  343.81),
                         SIMDE_FLOAT64_C( -406.87), SIMDE_FLOAT64_C( -689.93),
                         SIMDE_FLOAT64_C( -169.12), SIMDE_FLOAT64_C( -796.89)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(  513.07),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    2.13),
                         SIMDE_FLOAT64_C(  -65.03), SIMDE_FLOAT64_C( -561.53),
                         SIMDE_FLOAT64_C( -161.04), SIMDE_FLOAT64_C(    2.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -354.59), SIMDE_FLOAT64_C( -334.01),
                         SIMDE_FLOAT64_C( -406.82), SIMDE_FLOAT64_C( -535.93),
                         SIMDE_FLOAT64_C(  534.72), SIMDE_FLOAT64_C(  276.86),
                         SIMDE_FLOAT64_C(  401.00), SIMDE_FLOAT64_C(  921.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -20.44), SIMDE_FLOAT64_C( -778.21),
                         SIMDE_FLOAT64_C(  -61.28), SIMDE_FLOAT64_C(  788.42),
                         SIMDE_FLOAT64_C(  286.07), SIMDE_FLOAT64_C(  772.65),
                         SIMDE_FLOAT64_C( -788.54), SIMDE_FLOAT64_C(  755.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -20.13), SIMDE_FLOAT64_C(   -2.03),
                         SIMDE_FLOAT64_C(  -48.26), SIMDE_FLOAT64_C(  532.41),
                         SIMDE_FLOAT64_C(    2.08), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  657.31)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  197.60), SIMDE_FLOAT64_C( -669.73),
                         SIMDE_FLOAT64_C(  859.82), SIMDE_FLOAT64_C( -638.20),
                         SIMDE_FLOAT64_C( -808.24), SIMDE_FLOAT64_C(  961.25),
                         SIMDE_FLOAT64_C(  916.37), SIMDE_FLOAT64_C( -473.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.21), SIMDE_FLOAT64_C(   10.30),
                         SIMDE_FLOAT64_C(  402.59), SIMDE_FLOAT64_C( -919.31),
                         SIMDE_FLOAT64_C(  484.80), SIMDE_FLOAT64_C(  567.35),
                         SIMDE_FLOAT64_C( -979.89), SIMDE_FLOAT64_C(  784.39)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.08), SIMDE_FLOAT64_C(    2.57),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C( -534.01),
                         SIMDE_FLOAT64_C(    3.03), SIMDE_FLOAT64_C(  513.25),
                         SIMDE_FLOAT64_C(  912.26), SIMDE_FLOAT64_C(    3.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  188.83), SIMDE_FLOAT64_C( -479.33),
                         SIMDE_FLOAT64_C(  811.81), SIMDE_FLOAT64_C( -322.50),
                         SIMDE_FLOAT64_C(  884.11), SIMDE_FLOAT64_C(  808.53),
                         SIMDE_FLOAT64_C( -174.95), SIMDE_FLOAT64_C(  -68.05)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -882.86), SIMDE_FLOAT64_C( -939.93),
                         SIMDE_FLOAT64_C( -855.90), SIMDE_FLOAT64_C(  170.22),
                         SIMDE_FLOAT64_C(  115.99), SIMDE_FLOAT64_C(  297.62),
                         SIMDE_FLOAT64_C( -527.76), SIMDE_FLOAT64_C(  219.88)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.45), SIMDE_FLOAT64_C(   -3.67),
                         SIMDE_FLOAT64_C(  771.77), SIMDE_FLOAT64_C(  160.00),
                         SIMDE_FLOAT64_C(    3.08), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(   -2.05), SIMDE_FLOAT64_C(   34.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -659.02), SIMDE_FLOAT64_C(  607.91),
                         SIMDE_FLOAT64_C( -268.25), SIMDE_FLOAT64_C(  240.07),
                         SIMDE_FLOAT64_C(  471.39), SIMDE_FLOAT64_C( -501.59),
                         SIMDE_FLOAT64_C(  984.94), SIMDE_FLOAT64_C( -801.62)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -165.03), SIMDE_FLOAT64_C(  382.49),
                         SIMDE_FLOAT64_C( -663.11), SIMDE_FLOAT64_C(  675.92),
                         SIMDE_FLOAT64_C( -427.89), SIMDE_FLOAT64_C( -312.23),
                         SIMDE_FLOAT64_C(   47.19), SIMDE_FLOAT64_C( -273.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -2.56), SIMDE_FLOAT64_C(    2.36),
                         SIMDE_FLOAT64_C(   -2.06), SIMDE_FLOAT64_C(    2.50),
                         SIMDE_FLOAT64_C(  387.39), SIMDE_FLOAT64_C( -304.07),
                         SIMDE_FLOAT64_C(    2.81), SIMDE_FLOAT64_C(   -2.13)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -449.51), SIMDE_FLOAT64_C( -396.24),
                         SIMDE_FLOAT64_C( -106.23), SIMDE_FLOAT64_C( -648.77),
                         SIMDE_FLOAT64_C(  178.69), SIMDE_FLOAT64_C( -996.05),
                         SIMDE_FLOAT64_C(  315.07), SIMDE_FLOAT64_C( -247.28)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  515.02), SIMDE_FLOAT64_C(  228.66),
                         SIMDE_FLOAT64_C(  419.85), SIMDE_FLOAT64_C( -810.27),
                         SIMDE_FLOAT64_C(  162.64), SIMDE_FLOAT64_C(  495.48),
                         SIMDE_FLOAT64_C( -567.27), SIMDE_FLOAT64_C(  755.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  196.03),
                         SIMDE_FLOAT64_C(  104.20), SIMDE_FLOAT64_C( -520.27),
                         SIMDE_FLOAT64_C(  162.63), SIMDE_FLOAT64_C(    3.77),
                         SIMDE_FLOAT64_C(    2.21), SIMDE_FLOAT64_C(    2.82)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -506.18), SIMDE_FLOAT64_C(  153.12),
                         SIMDE_FLOAT64_C( -217.93), SIMDE_FLOAT64_C(    6.73),
                         SIMDE_FLOAT64_C(  358.11), SIMDE_FLOAT64_C( -136.37),
                         SIMDE_FLOAT64_C(  141.08), SIMDE_FLOAT64_C( -860.28)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -303.86), SIMDE_FLOAT64_C( -938.78),
                         SIMDE_FLOAT64_C(  386.83), SIMDE_FLOAT64_C( -590.09),
                         SIMDE_FLOAT64_C( -517.39), SIMDE_FLOAT64_C( -324.41),
                         SIMDE_FLOAT64_C(  515.48), SIMDE_FLOAT64_C(  674.62)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -298.05), SIMDE_FLOAT64_C(    2.13),
                         SIMDE_FLOAT64_C(  193.41), SIMDE_FLOAT64_C(    2.30),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C( -128.08),
                         SIMDE_FLOAT64_C(    2.00), SIMDE_FLOAT64_C(  512.03)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -571.57), SIMDE_FLOAT64_C( -865.77),
                         SIMDE_FLOAT64_C( -691.63), SIMDE_FLOAT64_C( -182.56),
                         SIMDE_FLOAT64_C(  -67.70), SIMDE_FLOAT64_C( -166.11),
                         SIMDE_FLOAT64_C( -833.08), SIMDE_FLOAT64_C( -401.07)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  341.96), SIMDE_FLOAT64_C(  615.56),
                         SIMDE_FLOAT64_C(  144.45), SIMDE_FLOAT64_C(  211.78),
                         SIMDE_FLOAT64_C(  -86.51), SIMDE_FLOAT64_C(  594.64),
                         SIMDE_FLOAT64_C(  523.21), SIMDE_FLOAT64_C( -747.41)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.17), SIMDE_FLOAT64_C(  609.52),
                         SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  146.53),
                         SIMDE_FLOAT64_C(  -66.51), SIMDE_FLOAT64_C(    2.06),
                         SIMDE_FLOAT64_C(  513.08), SIMDE_FLOAT64_C(   -2.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_and_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_and_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -343.60), SIMDE_FLOAT32_C(  -192.26), SIMDE_FLOAT32_C(  -375.10), SIMDE_FLOAT32_C(   810.28),
                         SIMDE_FLOAT32_C(  -388.15), SIMDE_FLOAT32_C(    15.81), SIMDE_FLOAT32_C(   547.95), SIMDE_FLOAT32_C(   151.06),
                         SIMDE_FLOAT32_C(  -920.74), SIMDE_FLOAT32_C(  -676.14), SIMDE_FLOAT32_C(  -545.26), SIMDE_FLOAT32_C(   -14.56),
                         SIMDE_FLOAT32_C(  -393.14), SIMDE_FLOAT32_C(   768.60), SIMDE_FLOAT32_C(  -177.89), SIMDE_FLOAT32_C(  -467.51)),
      UINT16_C(45944),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -651.37), SIMDE_FLOAT32_C(    37.95), SIMDE_FLOAT32_C(  -182.79), SIMDE_FLOAT32_C(   255.51),
                         SIMDE_FLOAT32_C(   476.70), SIMDE_FLOAT32_C(   371.61), SIMDE_FLOAT32_C(  -494.45), SIMDE_FLOAT32_C(    72.18),
                         SIMDE_FLOAT32_C(  -723.25), SIMDE_FLOAT32_C(   604.60), SIMDE_FLOAT32_C(   545.32), SIMDE_FLOAT32_C(  -399.73),
                         SIMDE_FLOAT32_C(  -975.39), SIMDE_FLOAT32_C(   419.30), SIMDE_FLOAT32_C(  -736.37), SIMDE_FLOAT32_C(   655.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -330.93), SIMDE_FLOAT32_C(   963.24), SIMDE_FLOAT32_C(   -62.45), SIMDE_FLOAT32_C(   625.74),
                         SIMDE_FLOAT32_C(  -826.45), SIMDE_FLOAT32_C(  -884.51), SIMDE_FLOAT32_C(   544.59), SIMDE_FLOAT32_C(   -22.39),
                         SIMDE_FLOAT32_C(   750.16), SIMDE_FLOAT32_C(  -751.51), SIMDE_FLOAT32_C(  -211.00), SIMDE_FLOAT32_C(   886.29),
                         SIMDE_FLOAT32_C(   666.91), SIMDE_FLOAT32_C(     8.70), SIMDE_FLOAT32_C(  -362.66), SIMDE_FLOAT32_C(  -451.03)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -2.51), SIMDE_FLOAT32_C(  -192.26), SIMDE_FLOAT32_C(   -44.20), SIMDE_FLOAT32_C(     2.44),
                         SIMDE_FLOAT32_C(  -388.15), SIMDE_FLOAT32_C(    15.81), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     4.50),
                         SIMDE_FLOAT32_C(  -920.74), SIMDE_FLOAT32_C(   588.50), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     3.09),
                         SIMDE_FLOAT32_C(   650.38), SIMDE_FLOAT32_C(   768.60), SIMDE_FLOAT32_C(  -177.89), SIMDE_FLOAT32_C(  -467.51)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -702.08), SIMDE_FLOAT32_C(   457.26), SIMDE_FLOAT32_C(   193.10), SIMDE_FLOAT32_C(   655.72),
                         SIMDE_FLOAT32_C(   205.91), SIMDE_FLOAT32_C(   807.77), SIMDE_FLOAT32_C(  -545.40), SIMDE_FLOAT32_C(  -364.12),
                         SIMDE_FLOAT32_C(   -42.22), SIMDE_FLOAT32_C(  -523.42), SIMDE_FLOAT32_C(  -308.90), SIMDE_FLOAT32_C(    22.20),
                         SIMDE_FLOAT32_C(  -114.47), SIMDE_FLOAT32_C(  -738.11), SIMDE_FLOAT32_C(   189.09), SIMDE_FLOAT32_C(  -448.58)),
      UINT16_C(10313),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -177.43), SIMDE_FLOAT32_C(   -28.38), SIMDE_FLOAT32_C(  -846.37), SIMDE_FLOAT32_C(   912.26),
                         SIMDE_FLOAT32_C(  -370.39), SIMDE_FLOAT32_C(   988.78), SIMDE_FLOAT32_C(  -359.74), SIMDE_FLOAT32_C(  -281.72),
                         SIMDE_FLOAT32_C(   166.18), SIMDE_FLOAT32_C(  -100.50), SIMDE_FLOAT32_C(  -909.51), SIMDE_FLOAT32_C(   -85.95),
                         SIMDE_FLOAT32_C(  -710.91), SIMDE_FLOAT32_C(  -813.11), SIMDE_FLOAT32_C(  -799.86), SIMDE_FLOAT32_C(  -823.45)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   329.92), SIMDE_FLOAT32_C(   113.21), SIMDE_FLOAT32_C(   300.37), SIMDE_FLOAT32_C(  -777.20),
                         SIMDE_FLOAT32_C(   193.77), SIMDE_FLOAT32_C(  -864.32), SIMDE_FLOAT32_C(   579.99), SIMDE_FLOAT32_C(   488.59),
                         SIMDE_FLOAT32_C(  -684.28), SIMDE_FLOAT32_C(   -65.28), SIMDE_FLOAT32_C(   876.26), SIMDE_FLOAT32_C(   378.65),
                         SIMDE_FLOAT32_C(  -964.10), SIMDE_FLOAT32_C(   626.06), SIMDE_FLOAT32_C(    97.19), SIMDE_FLOAT32_C(   612.33)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -702.08), SIMDE_FLOAT32_C(   457.26), SIMDE_FLOAT32_C(     2.28), SIMDE_FLOAT32_C(   655.72),
                         SIMDE_FLOAT32_C(   129.00), SIMDE_FLOAT32_C(   807.77), SIMDE_FLOAT32_C(  -545.40), SIMDE_FLOAT32_C(  -364.12),
                         SIMDE_FLOAT32_C(   -42.22), SIMDE_FLOAT32_C(   -64.00), SIMDE_FLOAT32_C(  -308.90), SIMDE_FLOAT32_C(    22.20),
                         SIMDE_FLOAT32_C(  -708.03), SIMDE_FLOAT32_C(  -738.11), SIMDE_FLOAT32_C(   189.09), SIMDE_FLOAT32_C(   548.31)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   153.13), SIMDE_FLOAT32_C(    47.64), SIMDE_FLOAT32_C(  -104.37), SIMDE_FLOAT32_C(  -453.36),
                         SIMDE_FLOAT32_C(   -57.32), SIMDE_FLOAT32_C(  -673.06), SIMDE_FLOAT32_C(  -857.97), SIMDE_FLOAT32_C(  -158.69),
                         SIMDE_FLOAT32_C(   504.22), SIMDE_FLOAT32_C(   774.61), SIMDE_FLOAT32_C(   -50.26), SIMDE_FLOAT32_C(  -594.62),
                         SIMDE_FLOAT32_C(   628.86), SIMDE_FLOAT32_C(   362.00), SIMDE_FLOAT32_C(   770.65), SIMDE_FLOAT32_C(  -621.70)),
      UINT16_C( 5674),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -181.31), SIMDE_FLOAT32_C(  -271.84), SIMDE_FLOAT32_C(   138.26), SIMDE_FLOAT32_C(    59.10),
                         SIMDE_FLOAT32_C(   703.12), SIMDE_FLOAT32_C(   374.71), SIMDE_FLOAT32_C(  -674.86), SIMDE_FLOAT32_C(  -198.23),
                         SIMDE_FLOAT32_C(   769.31), SIMDE_FLOAT32_C(  -859.16), SIMDE_FLOAT32_C(   111.69), SIMDE_FLOAT32_C(  -420.38),
                         SIMDE_FLOAT32_C(   345.23), SIMDE_FLOAT32_C(  -263.27), SIMDE_FLOAT32_C(   122.33), SIMDE_FLOAT32_C(   -11.31)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    13.03), SIMDE_FLOAT32_C(   510.73), SIMDE_FLOAT32_C(    -6.19), SIMDE_FLOAT32_C(  -107.87),
                         SIMDE_FLOAT32_C(  -441.23), SIMDE_FLOAT32_C(   120.22), SIMDE_FLOAT32_C(   331.67), SIMDE_FLOAT32_C(  -661.48),
                         SIMDE_FLOAT32_C(   626.32), SIMDE_FLOAT32_C(   505.21), SIMDE_FLOAT32_C(  -161.83), SIMDE_FLOAT32_C(  -671.34),
                         SIMDE_FLOAT32_C(   514.06), SIMDE_FLOAT32_C(  -807.61), SIMDE_FLOAT32_C(  -556.61), SIMDE_FLOAT32_C(  -451.72)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   153.13), SIMDE_FLOAT32_C(    47.64), SIMDE_FLOAT32_C(  -104.37), SIMDE_FLOAT32_C(    49.04),
                         SIMDE_FLOAT32_C(   -57.32), SIMDE_FLOAT32_C(    88.16), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(  -158.69),
                         SIMDE_FLOAT32_C(   504.22), SIMDE_FLOAT32_C(   774.61), SIMDE_FLOAT32_C(    32.31), SIMDE_FLOAT32_C(  -594.62),
                         SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(   362.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(  -621.70)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -175.84), SIMDE_FLOAT32_C(   968.44), SIMDE_FLOAT32_C(    85.61), SIMDE_FLOAT32_C(  -394.33),
                         SIMDE_FLOAT32_C(   358.35), SIMDE_FLOAT32_C(   605.54), SIMDE_FLOAT32_C(  -698.35), SIMDE_FLOAT32_C(  -764.09),
                         SIMDE_FLOAT32_C(   164.55), SIMDE_FLOAT32_C(  -893.53), SIMDE_FLOAT32_C(   171.50), SIMDE_FLOAT32_C(   629.19),
                         SIMDE_FLOAT32_C(    42.86), SIMDE_FLOAT32_C(    22.57), SIMDE_FLOAT32_C(   198.87), SIMDE_FLOAT32_C(  -209.78)),
      UINT16_C(35386),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -72.35), SIMDE_FLOAT32_C(  -549.59), SIMDE_FLOAT32_C(   102.63), SIMDE_FLOAT32_C(   834.67),
                         SIMDE_FLOAT32_C(     4.81), SIMDE_FLOAT32_C(   910.94), SIMDE_FLOAT32_C(   192.67), SIMDE_FLOAT32_C(   180.42),
                         SIMDE_FLOAT32_C(   349.29), SIMDE_FLOAT32_C(   183.58), SIMDE_FLOAT32_C(   366.06), SIMDE_FLOAT32_C(  -157.87),
                         SIMDE_FLOAT32_C(  -312.42), SIMDE_FLOAT32_C(   182.79), SIMDE_FLOAT32_C(  -978.11), SIMDE_FLOAT32_C(    90.48)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   175.13), SIMDE_FLOAT32_C(  -712.55), SIMDE_FLOAT32_C(  -809.33), SIMDE_FLOAT32_C(   698.74),
                         SIMDE_FLOAT32_C(   142.25), SIMDE_FLOAT32_C(  -727.89), SIMDE_FLOAT32_C(  -520.56), SIMDE_FLOAT32_C(   353.74),
                         SIMDE_FLOAT32_C(  -705.41), SIMDE_FLOAT32_C(  -196.42), SIMDE_FLOAT32_C(   407.84), SIMDE_FLOAT32_C(  -285.59),
                         SIMDE_FLOAT32_C(   496.15), SIMDE_FLOAT32_C(   800.83), SIMDE_FLOAT32_C(  -740.01), SIMDE_FLOAT32_C(   769.91)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    32.03), SIMDE_FLOAT32_C(   968.44), SIMDE_FLOAT32_C(    85.61), SIMDE_FLOAT32_C(  -394.33),
                         SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(   605.54), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(  -764.09),
                         SIMDE_FLOAT32_C(   164.55), SIMDE_FLOAT32_C(  -893.53), SIMDE_FLOAT32_C(   262.03), SIMDE_FLOAT32_C(  -140.79),
                         SIMDE_FLOAT32_C(   304.13), SIMDE_FLOAT32_C(    22.57), SIMDE_FLOAT32_C(  -704.00), SIMDE_FLOAT32_C(  -209.78)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -273.10), SIMDE_FLOAT32_C(  -193.08), SIMDE_FLOAT32_C(   823.95), SIMDE_FLOAT32_C(   970.90),
                         SIMDE_FLOAT32_C(   -50.31), SIMDE_FLOAT32_C(   755.59), SIMDE_FLOAT32_C(  -119.92), SIMDE_FLOAT32_C(  -895.51),
                         SIMDE_FLOAT32_C(   692.21), SIMDE_FLOAT32_C(   544.09), SIMDE_FLOAT32_C(   740.64), SIMDE_FLOAT32_C(   817.79),
                         SIMDE_FLOAT32_C(   131.04), SIMDE_FLOAT32_C(   190.96), SIMDE_FLOAT32_C(   289.64), SIMDE_FLOAT32_C(  -908.35)),
      UINT16_C( 1662),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   563.69), SIMDE_FLOAT32_C(   374.34), SIMDE_FLOAT32_C(  -459.61), SIMDE_FLOAT32_C(   786.82),
                         SIMDE_FLOAT32_C(   257.72), SIMDE_FLOAT32_C(  -220.73), SIMDE_FLOAT32_C(  -903.10), SIMDE_FLOAT32_C(   520.58),
                         SIMDE_FLOAT32_C(  -858.27), SIMDE_FLOAT32_C(   784.57), SIMDE_FLOAT32_C(   832.81), SIMDE_FLOAT32_C(  -909.15),
                         SIMDE_FLOAT32_C(   909.58), SIMDE_FLOAT32_C(  -162.79), SIMDE_FLOAT32_C(   177.63), SIMDE_FLOAT32_C(    25.46)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   749.97), SIMDE_FLOAT32_C(   -58.76), SIMDE_FLOAT32_C(   952.36), SIMDE_FLOAT32_C(   549.26),
                         SIMDE_FLOAT32_C(   390.25), SIMDE_FLOAT32_C(  -490.70), SIMDE_FLOAT32_C(   974.89), SIMDE_FLOAT32_C(   114.95),
                         SIMDE_FLOAT32_C(   932.36), SIMDE_FLOAT32_C(  -895.93), SIMDE_FLOAT32_C(  -880.84), SIMDE_FLOAT32_C(  -351.20),
                         SIMDE_FLOAT32_C(  -500.77), SIMDE_FLOAT32_C(    42.49), SIMDE_FLOAT32_C(   588.62), SIMDE_FLOAT32_C(    67.54)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -273.10), SIMDE_FLOAT32_C(  -193.08), SIMDE_FLOAT32_C(   823.95), SIMDE_FLOAT32_C(   970.90),
                         SIMDE_FLOAT32_C(   -50.31), SIMDE_FLOAT32_C(  -212.10), SIMDE_FLOAT32_C(   902.01), SIMDE_FLOAT32_C(  -895.51),
                         SIMDE_FLOAT32_C(   692.21), SIMDE_FLOAT32_C(   784.50), SIMDE_FLOAT32_C(   832.78), SIMDE_FLOAT32_C(    -2.55),
                         SIMDE_FLOAT32_C(     3.54), SIMDE_FLOAT32_C(    40.19), SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(  -908.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   882.37), SIMDE_FLOAT32_C(   -29.48), SIMDE_FLOAT32_C(   208.93), SIMDE_FLOAT32_C(  -103.96),
                         SIMDE_FLOAT32_C(  -740.71), SIMDE_FLOAT32_C(   -48.33), SIMDE_FLOAT32_C(   -73.48), SIMDE_FLOAT32_C(   839.05),
                         SIMDE_FLOAT32_C(  -578.39), SIMDE_FLOAT32_C(  -527.30), SIMDE_FLOAT32_C(   808.78), SIMDE_FLOAT32_C(   273.31),
                         SIMDE_FLOAT32_C(  -212.18), SIMDE_FLOAT32_C(   358.44), SIMDE_FLOAT32_C(  -429.58), SIMDE_FLOAT32_C(   641.01)),
      UINT16_C(51954),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   159.89), SIMDE_FLOAT32_C(  -431.59), SIMDE_FLOAT32_C(   692.24), SIMDE_FLOAT32_C(  -189.31),
                         SIMDE_FLOAT32_C(    84.37), SIMDE_FLOAT32_C(  -971.33), SIMDE_FLOAT32_C(    50.60), SIMDE_FLOAT32_C(  -980.81),
                         SIMDE_FLOAT32_C(   362.99), SIMDE_FLOAT32_C(   722.54), SIMDE_FLOAT32_C(   564.98), SIMDE_FLOAT32_C(   242.21),
                         SIMDE_FLOAT32_C(  -393.24), SIMDE_FLOAT32_C(   738.28), SIMDE_FLOAT32_C(   192.78), SIMDE_FLOAT32_C(  -360.32)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -421.96), SIMDE_FLOAT32_C(  -741.98), SIMDE_FLOAT32_C(  -791.19), SIMDE_FLOAT32_C(   363.28),
                         SIMDE_FLOAT32_C(   168.15), SIMDE_FLOAT32_C(  -247.26), SIMDE_FLOAT32_C(   113.19), SIMDE_FLOAT32_C(   128.76),
                         SIMDE_FLOAT32_C(  -773.73), SIMDE_FLOAT32_C(   125.25), SIMDE_FLOAT32_C(   337.69), SIMDE_FLOAT32_C(  -644.22),
                         SIMDE_FLOAT32_C(   869.52), SIMDE_FLOAT32_C(   681.99), SIMDE_FLOAT32_C(   444.36), SIMDE_FLOAT32_C(   361.44)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   146.89), SIMDE_FLOAT32_C(    -2.27), SIMDE_FLOAT32_C(   208.93), SIMDE_FLOAT32_C(  -103.96),
                         SIMDE_FLOAT32_C(    42.04), SIMDE_FLOAT32_C(   -48.33), SIMDE_FLOAT32_C(    48.59), SIMDE_FLOAT32_C(   839.05),
                         SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     2.76), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(     2.50),
                         SIMDE_FLOAT32_C(  -212.18), SIMDE_FLOAT32_C(   358.44), SIMDE_FLOAT32_C(   192.02), SIMDE_FLOAT32_C(   641.01)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -829.72), SIMDE_FLOAT32_C(   349.95), SIMDE_FLOAT32_C(   480.03), SIMDE_FLOAT32_C(  -584.69),
                         SIMDE_FLOAT32_C(   943.11), SIMDE_FLOAT32_C(  -148.79), SIMDE_FLOAT32_C(  -861.78), SIMDE_FLOAT32_C(  -270.87),
                         SIMDE_FLOAT32_C(  -593.74), SIMDE_FLOAT32_C(  -232.02), SIMDE_FLOAT32_C(  -553.31), SIMDE_FLOAT32_C(   693.33),
                         SIMDE_FLOAT32_C(  -533.82), SIMDE_FLOAT32_C(  -527.51), SIMDE_FLOAT32_C(  -140.16), SIMDE_FLOAT32_C(   631.76)),
      UINT16_C(50263),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   173.33), SIMDE_FLOAT32_C(  -281.34), SIMDE_FLOAT32_C(   -45.38), SIMDE_FLOAT32_C(  -230.23),
                         SIMDE_FLOAT32_C(  -937.39), SIMDE_FLOAT32_C(    53.86), SIMDE_FLOAT32_C(  -719.43), SIMDE_FLOAT32_C(   465.60),
                         SIMDE_FLOAT32_C(   111.60), SIMDE_FLOAT32_C(   156.01), SIMDE_FLOAT32_C(  -703.23), SIMDE_FLOAT32_C(   763.33),
                         SIMDE_FLOAT32_C(   119.12), SIMDE_FLOAT32_C(  -295.56), SIMDE_FLOAT32_C(   313.51), SIMDE_FLOAT32_C(  -193.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   396.81), SIMDE_FLOAT32_C(  -330.26), SIMDE_FLOAT32_C(  -500.01), SIMDE_FLOAT32_C(  -117.27),
                         SIMDE_FLOAT32_C(   805.35), SIMDE_FLOAT32_C(   722.55), SIMDE_FLOAT32_C(   274.82), SIMDE_FLOAT32_C(    32.73),
                         SIMDE_FLOAT32_C(  -564.66), SIMDE_FLOAT32_C(   180.25), SIMDE_FLOAT32_C(  -307.87), SIMDE_FLOAT32_C(   888.96),
                         SIMDE_FLOAT32_C(   806.77), SIMDE_FLOAT32_C(  -526.35), SIMDE_FLOAT32_C(   889.50), SIMDE_FLOAT32_C(   196.92)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   132.27), SIMDE_FLOAT32_C(  -264.26), SIMDE_FLOAT32_C(   480.03), SIMDE_FLOAT32_C(  -584.69),
                         SIMDE_FLOAT32_C(   943.11), SIMDE_FLOAT32_C(     2.31), SIMDE_FLOAT32_C(  -861.78), SIMDE_FLOAT32_C(  -270.87),
                         SIMDE_FLOAT32_C(  -593.74), SIMDE_FLOAT32_C(   148.00), SIMDE_FLOAT32_C(  -553.31), SIMDE_FLOAT32_C(   632.33),
                         SIMDE_FLOAT32_C(  -533.82), SIMDE_FLOAT32_C(    -2.06), SIMDE_FLOAT32_C(     2.44), SIMDE_FLOAT32_C(   192.13)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   425.40), SIMDE_FLOAT32_C(  -281.85), SIMDE_FLOAT32_C(   596.53), SIMDE_FLOAT32_C(   231.55),
                         SIMDE_FLOAT32_C(  -189.24), SIMDE_FLOAT32_C(   962.54), SIMDE_FLOAT32_C(   598.72), SIMDE_FLOAT32_C(  -728.82),
                         SIMDE_FLOAT32_C(   -31.34), SIMDE_FLOAT32_C(  -498.28), SIMDE_FLOAT32_C(  -106.48), SIMDE_FLOAT32_C(  -850.40),
                         SIMDE_FLOAT32_C(  -763.83), SIMDE_FLOAT32_C(   176.55), SIMDE_FLOAT32_C(   356.84), SIMDE_FLOAT32_C(   827.17)),
      UINT16_C(54643),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   761.43), SIMDE_FLOAT32_C(    95.69), SIMDE_FLOAT32_C(   888.39), SIMDE_FLOAT32_C(  -555.84),
                         SIMDE_FLOAT32_C(    40.33), SIMDE_FLOAT32_C(   358.74), SIMDE_FLOAT32_C(  -948.08), SIMDE_FLOAT32_C(   313.44),
                         SIMDE_FLOAT32_C(  -166.07), SIMDE_FLOAT32_C(  -218.95), SIMDE_FLOAT32_C(   360.34), SIMDE_FLOAT32_C(   989.68),
                         SIMDE_FLOAT32_C(   653.42), SIMDE_FLOAT32_C(   345.37), SIMDE_FLOAT32_C(   978.06), SIMDE_FLOAT32_C(   493.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   109.54), SIMDE_FLOAT32_C(   122.35), SIMDE_FLOAT32_C(   770.11), SIMDE_FLOAT32_C(   306.89),
                         SIMDE_FLOAT32_C(  -347.63), SIMDE_FLOAT32_C(   772.43), SIMDE_FLOAT32_C(   958.72), SIMDE_FLOAT32_C(  -435.18),
                         SIMDE_FLOAT32_C(  -680.27), SIMDE_FLOAT32_C(  -653.21), SIMDE_FLOAT32_C(   453.00), SIMDE_FLOAT32_C(   299.53),
                         SIMDE_FLOAT32_C(  -837.12), SIMDE_FLOAT32_C(    -8.00), SIMDE_FLOAT32_C(   561.63), SIMDE_FLOAT32_C(  -594.20)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.41), SIMDE_FLOAT32_C(    90.06), SIMDE_FLOAT32_C(   596.53), SIMDE_FLOAT32_C(     2.13),
                         SIMDE_FLOAT32_C(  -189.24), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(   598.72), SIMDE_FLOAT32_C(   305.13),
                         SIMDE_FLOAT32_C(   -31.34), SIMDE_FLOAT32_C(    -2.04), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(     2.33),
                         SIMDE_FLOAT32_C(  -763.83), SIMDE_FLOAT32_C(   176.55), SIMDE_FLOAT32_C(   528.01), SIMDE_FLOAT32_C(     2.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_and_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_and_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -128.09), SIMDE_FLOAT64_C( -302.68),
                         SIMDE_FLOAT64_C(  129.66), SIMDE_FLOAT64_C( -400.28),
                         SIMDE_FLOAT64_C( -687.60), SIMDE_FLOAT64_C( -568.06),
                         SIMDE_FLOAT64_C( -974.67), SIMDE_FLOAT64_C(  814.47)),
      UINT8_C( 92),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -854.57), SIMDE_FLOAT64_C(  353.06),
                         SIMDE_FLOAT64_C(  903.81), SIMDE_FLOAT64_C( -723.16),
                         SIMDE_FLOAT64_C( -194.97), SIMDE_FLOAT64_C(  114.89),
                         SIMDE_FLOAT64_C(  497.66), SIMDE_FLOAT64_C( -446.09)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -876.89), SIMDE_FLOAT64_C( -283.08),
                         SIMDE_FLOAT64_C(  642.58), SIMDE_FLOAT64_C( -973.49),
                         SIMDE_FLOAT64_C(  853.14), SIMDE_FLOAT64_C(  647.44),
                         SIMDE_FLOAT64_C(  237.52), SIMDE_FLOAT64_C( -333.12)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -128.09), SIMDE_FLOAT64_C(  257.02),
                         SIMDE_FLOAT64_C(  129.66), SIMDE_FLOAT64_C( -705.16),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(    2.53),
                         SIMDE_FLOAT64_C( -974.67), SIMDE_FLOAT64_C(  814.47)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   61.63), SIMDE_FLOAT64_C(  987.28),
                         SIMDE_FLOAT64_C( -845.84), SIMDE_FLOAT64_C( -822.08),
                         SIMDE_FLOAT64_C( -946.95), SIMDE_FLOAT64_C( -157.17),
                         SIMDE_FLOAT64_C(  808.43), SIMDE_FLOAT64_C(  716.34)),
      UINT8_C(128),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.33),
                         SIMDE_FLOAT64_C(  842.44), SIMDE_FLOAT64_C( -417.76),
                         SIMDE_FLOAT64_C( -171.61), SIMDE_FLOAT64_C(  -96.79),
                         SIMDE_FLOAT64_C(   45.73), SIMDE_FLOAT64_C(  312.19)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   54.70), SIMDE_FLOAT64_C( -228.57),
                         SIMDE_FLOAT64_C( -133.57), SIMDE_FLOAT64_C( -803.47),
                         SIMDE_FLOAT64_C(  821.61), SIMDE_FLOAT64_C(  198.21),
                         SIMDE_FLOAT64_C(  476.20), SIMDE_FLOAT64_C(  925.71)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.41), SIMDE_FLOAT64_C(  987.28),
                         SIMDE_FLOAT64_C( -845.84), SIMDE_FLOAT64_C( -822.08),
                         SIMDE_FLOAT64_C( -946.95), SIMDE_FLOAT64_C( -157.17),
                         SIMDE_FLOAT64_C(  808.43), SIMDE_FLOAT64_C(  716.34)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  -24.63), SIMDE_FLOAT64_C( -758.53),
                         SIMDE_FLOAT64_C(  216.18), SIMDE_FLOAT64_C( -869.86),
                         SIMDE_FLOAT64_C( -556.61), SIMDE_FLOAT64_C( -869.93),
                         SIMDE_FLOAT64_C(  935.72), SIMDE_FLOAT64_C(  467.65)),
      UINT8_C(132),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -373.41), SIMDE_FLOAT64_C(  558.94),
                         SIMDE_FLOAT64_C( -966.64), SIMDE_FLOAT64_C( -741.87),
                         SIMDE_FLOAT64_C( -915.12), SIMDE_FLOAT64_C( -226.56),
                         SIMDE_FLOAT64_C(  374.42), SIMDE_FLOAT64_C(  490.85)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  143.45), SIMDE_FLOAT64_C(   16.49),
                         SIMDE_FLOAT64_C(  323.05), SIMDE_FLOAT64_C( -564.38),
                         SIMDE_FLOAT64_C( -932.37), SIMDE_FLOAT64_C( -126.95),
                         SIMDE_FLOAT64_C(   46.50), SIMDE_FLOAT64_C(  812.07)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  138.19), SIMDE_FLOAT64_C( -758.53),
                         SIMDE_FLOAT64_C(  216.18), SIMDE_FLOAT64_C( -869.86),
                         SIMDE_FLOAT64_C( -556.61), SIMDE_FLOAT64_C(  -56.13),
                         SIMDE_FLOAT64_C(  935.72), SIMDE_FLOAT64_C(  467.65)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -587.51), SIMDE_FLOAT64_C( -331.04),
                         SIMDE_FLOAT64_C(  711.75), SIMDE_FLOAT64_C( -149.95),
                         SIMDE_FLOAT64_C( -625.31), SIMDE_FLOAT64_C(  387.07),
                         SIMDE_FLOAT64_C(  510.51), SIMDE_FLOAT64_C( -791.87)),
      UINT8_C(197),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -995.18), SIMDE_FLOAT64_C(  720.96),
                         SIMDE_FLOAT64_C(  859.59), SIMDE_FLOAT64_C(   20.65),
                         SIMDE_FLOAT64_C( -207.40), SIMDE_FLOAT64_C( -632.30),
                         SIMDE_FLOAT64_C( -783.67), SIMDE_FLOAT64_C(  389.24)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -619.09), SIMDE_FLOAT64_C(  681.55),
                         SIMDE_FLOAT64_C(  914.89), SIMDE_FLOAT64_C(  240.13),
                         SIMDE_FLOAT64_C(   14.06), SIMDE_FLOAT64_C( -669.70),
                         SIMDE_FLOAT64_C(  554.04), SIMDE_FLOAT64_C( -602.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -611.02), SIMDE_FLOAT64_C(  640.52),
                         SIMDE_FLOAT64_C(  711.75), SIMDE_FLOAT64_C( -149.95),
                         SIMDE_FLOAT64_C( -625.31), SIMDE_FLOAT64_C( -536.00),
                         SIMDE_FLOAT64_C(  510.51), SIMDE_FLOAT64_C(    2.04)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   28.17), SIMDE_FLOAT64_C( -545.33),
                         SIMDE_FLOAT64_C( -993.85), SIMDE_FLOAT64_C( -636.74),
                         SIMDE_FLOAT64_C(  315.22), SIMDE_FLOAT64_C( -560.48),
                         SIMDE_FLOAT64_C( -264.88), SIMDE_FLOAT64_C(  866.66)),
      UINT8_C(152),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -378.42), SIMDE_FLOAT64_C( -112.43),
                         SIMDE_FLOAT64_C( -147.85), SIMDE_FLOAT64_C(  481.16),
                         SIMDE_FLOAT64_C(  980.68), SIMDE_FLOAT64_C(  999.62),
                         SIMDE_FLOAT64_C( -784.92), SIMDE_FLOAT64_C( -245.05)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  838.26), SIMDE_FLOAT64_C( -863.14),
                         SIMDE_FLOAT64_C(  336.07), SIMDE_FLOAT64_C(  237.32),
                         SIMDE_FLOAT64_C( -803.75), SIMDE_FLOAT64_C(  816.96),
                         SIMDE_FLOAT64_C(  217.54), SIMDE_FLOAT64_C( -660.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.27), SIMDE_FLOAT64_C( -545.33),
                         SIMDE_FLOAT64_C( -993.85), SIMDE_FLOAT64_C(  224.06),
                         SIMDE_FLOAT64_C(  768.50), SIMDE_FLOAT64_C( -560.48),
                         SIMDE_FLOAT64_C( -264.88), SIMDE_FLOAT64_C(  866.66)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  106.10), SIMDE_FLOAT64_C(  605.57),
                         SIMDE_FLOAT64_C(  481.85), SIMDE_FLOAT64_C(  491.86),
                         SIMDE_FLOAT64_C(  -77.86), SIMDE_FLOAT64_C( -839.61),
                         SIMDE_FLOAT64_C(  936.76), SIMDE_FLOAT64_C( -659.60)),
      UINT8_C(  7),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  505.82), SIMDE_FLOAT64_C( -629.98),
                         SIMDE_FLOAT64_C( -555.91), SIMDE_FLOAT64_C( -911.21),
                         SIMDE_FLOAT64_C(  603.24), SIMDE_FLOAT64_C(  -95.72),
                         SIMDE_FLOAT64_C(  864.74), SIMDE_FLOAT64_C(  280.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  570.36), SIMDE_FLOAT64_C(  765.47),
                         SIMDE_FLOAT64_C(  327.71), SIMDE_FLOAT64_C( -605.34),
                         SIMDE_FLOAT64_C(  509.13), SIMDE_FLOAT64_C( -583.43),
                         SIMDE_FLOAT64_C( -208.99), SIMDE_FLOAT64_C(  835.11)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  106.10), SIMDE_FLOAT64_C(  605.57),
                         SIMDE_FLOAT64_C(  481.85), SIMDE_FLOAT64_C(  491.86),
                         SIMDE_FLOAT64_C(  -77.86), SIMDE_FLOAT64_C(   -2.27),
                         SIMDE_FLOAT64_C(    3.25), SIMDE_FLOAT64_C(    2.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -925.64), SIMDE_FLOAT64_C(  122.27),
                         SIMDE_FLOAT64_C( -971.29), SIMDE_FLOAT64_C( -200.64),
                         SIMDE_FLOAT64_C(  268.43), SIMDE_FLOAT64_C(  995.23),
                         SIMDE_FLOAT64_C(  958.62), SIMDE_FLOAT64_C( -530.89)),
      UINT8_C(252),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -311.17), SIMDE_FLOAT64_C( -787.17),
                         SIMDE_FLOAT64_C( -427.34), SIMDE_FLOAT64_C(  839.17),
                         SIMDE_FLOAT64_C( -404.83), SIMDE_FLOAT64_C(  559.72),
                         SIMDE_FLOAT64_C(  982.82), SIMDE_FLOAT64_C( -251.36)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  643.61), SIMDE_FLOAT64_C(  953.53),
                         SIMDE_FLOAT64_C( -469.49), SIMDE_FLOAT64_C(   -8.31),
                         SIMDE_FLOAT64_C(  325.63), SIMDE_FLOAT64_C( -753.50),
                         SIMDE_FLOAT64_C( -462.28), SIMDE_FLOAT64_C( -779.29)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  785.01),
                         SIMDE_FLOAT64_C( -385.33), SIMDE_FLOAT64_C(    2.01),
                         SIMDE_FLOAT64_C(  260.50), SIMDE_FLOAT64_C(  545.50),
                         SIMDE_FLOAT64_C(  958.62), SIMDE_FLOAT64_C( -530.89)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  -62.82), SIMDE_FLOAT64_C(  -95.66),
                         SIMDE_FLOAT64_C(  484.39), SIMDE_FLOAT64_C( -736.85),
                         SIMDE_FLOAT64_C(  893.63), SIMDE_FLOAT64_C( -173.06),
                         SIMDE_FLOAT64_C(  113.69), SIMDE_FLOAT64_C(  198.15)),
      UINT8_C(239),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  440.07), SIMDE_FLOAT64_C(  639.74),
                         SIMDE_FLOAT64_C(  566.84), SIMDE_FLOAT64_C(  207.87),
                         SIMDE_FLOAT64_C( -578.31), SIMDE_FLOAT64_C( -772.29),
                         SIMDE_FLOAT64_C(   70.78), SIMDE_FLOAT64_C(  181.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -750.95), SIMDE_FLOAT64_C(  172.27),
                         SIMDE_FLOAT64_C( -538.71), SIMDE_FLOAT64_C( -512.10),
                         SIMDE_FLOAT64_C( -406.87), SIMDE_FLOAT64_C( -470.10),
                         SIMDE_FLOAT64_C( -652.40), SIMDE_FLOAT64_C( -121.85)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.38), SIMDE_FLOAT64_C(    2.19),
                         SIMDE_FLOAT64_C(  530.58), SIMDE_FLOAT64_C( -736.85),
                         SIMDE_FLOAT64_C(   -2.00), SIMDE_FLOAT64_C(   -3.02),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(   44.41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_and_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_and_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
   {  UINT16_C(57131),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   399.48), SIMDE_FLOAT32_C(  -238.06), SIMDE_FLOAT32_C(  -893.32), SIMDE_FLOAT32_C(  -435.26),
                         SIMDE_FLOAT32_C(   522.86), SIMDE_FLOAT32_C(  -612.44), SIMDE_FLOAT32_C(   652.00), SIMDE_FLOAT32_C(   895.17),
                         SIMDE_FLOAT32_C(  -820.93), SIMDE_FLOAT32_C(   533.04), SIMDE_FLOAT32_C(   403.71), SIMDE_FLOAT32_C(   282.24),
                         SIMDE_FLOAT32_C(   883.67), SIMDE_FLOAT32_C(    22.67), SIMDE_FLOAT32_C(   804.53), SIMDE_FLOAT32_C(   307.97)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   932.69), SIMDE_FLOAT32_C(   912.86), SIMDE_FLOAT32_C(   409.21), SIMDE_FLOAT32_C(   585.68),
                         SIMDE_FLOAT32_C(   -59.99), SIMDE_FLOAT32_C(  -146.01), SIMDE_FLOAT32_C(   160.06), SIMDE_FLOAT32_C(  -248.23),
                         SIMDE_FLOAT32_C(   780.27), SIMDE_FLOAT32_C(  -642.04), SIMDE_FLOAT32_C(   -94.76), SIMDE_FLOAT32_C(   563.52),
                         SIMDE_FLOAT32_C(  -953.85), SIMDE_FLOAT32_C(  -735.06), SIMDE_FLOAT32_C(   312.07), SIMDE_FLOAT32_C(  -630.77)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.02), SIMDE_FLOAT32_C(     3.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.25),
                         SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(    -2.25), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     3.38),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    68.75), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   817.54), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(     2.40)) },
   {  UINT16_C(37107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   145.79), SIMDE_FLOAT32_C(  -588.79), SIMDE_FLOAT32_C(   895.99), SIMDE_FLOAT32_C(  -454.35),
                         SIMDE_FLOAT32_C(   444.71), SIMDE_FLOAT32_C(   343.63), SIMDE_FLOAT32_C(   -33.93), SIMDE_FLOAT32_C(  -461.47),
                         SIMDE_FLOAT32_C(   -87.51), SIMDE_FLOAT32_C(  -587.34), SIMDE_FLOAT32_C(   -54.40), SIMDE_FLOAT32_C(  -339.84),
                         SIMDE_FLOAT32_C(  -976.14), SIMDE_FLOAT32_C(   850.15), SIMDE_FLOAT32_C(  -700.02), SIMDE_FLOAT32_C(  -579.46)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   720.42), SIMDE_FLOAT32_C(  -585.67), SIMDE_FLOAT32_C(  -388.81), SIMDE_FLOAT32_C(   165.49),
                         SIMDE_FLOAT32_C(   525.65), SIMDE_FLOAT32_C(   441.42), SIMDE_FLOAT32_C(   424.69), SIMDE_FLOAT32_C(   567.94),
                         SIMDE_FLOAT32_C(  -243.26), SIMDE_FLOAT32_C(   977.37), SIMDE_FLOAT32_C(  -705.87), SIMDE_FLOAT32_C(   365.97),
                         SIMDE_FLOAT32_C(  -511.37), SIMDE_FLOAT32_C(   335.33), SIMDE_FLOAT32_C(  -871.52), SIMDE_FLOAT32_C(  -805.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   161.17),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   -40.75), SIMDE_FLOAT32_C(   577.34), SIMDE_FLOAT32_C(    -2.25), SIMDE_FLOAT32_C(   321.81),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -548.02), SIMDE_FLOAT32_C(  -513.07)) },
   {  UINT16_C(56908),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   813.26), SIMDE_FLOAT32_C(  -716.74), SIMDE_FLOAT32_C(  -548.55), SIMDE_FLOAT32_C(   -83.12),
                         SIMDE_FLOAT32_C(   301.84), SIMDE_FLOAT32_C(  -843.69), SIMDE_FLOAT32_C(  -236.76), SIMDE_FLOAT32_C(   -34.42),
                         SIMDE_FLOAT32_C(  -591.83), SIMDE_FLOAT32_C(    11.80), SIMDE_FLOAT32_C(   521.39), SIMDE_FLOAT32_C(  -937.14),
                         SIMDE_FLOAT32_C(  -662.16), SIMDE_FLOAT32_C(  -974.03), SIMDE_FLOAT32_C(   576.46), SIMDE_FLOAT32_C(   704.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   914.44), SIMDE_FLOAT32_C(  -904.34), SIMDE_FLOAT32_C(    -4.84), SIMDE_FLOAT32_C(   -59.72),
                         SIMDE_FLOAT32_C(  -523.01), SIMDE_FLOAT32_C(   236.78), SIMDE_FLOAT32_C(    88.72), SIMDE_FLOAT32_C(  -251.99),
                         SIMDE_FLOAT32_C(  -782.65), SIMDE_FLOAT32_C(   -38.86), SIMDE_FLOAT32_C(   670.53), SIMDE_FLOAT32_C(   706.52),
                         SIMDE_FLOAT32_C(   990.40), SIMDE_FLOAT32_C(  -812.48), SIMDE_FLOAT32_C(  -152.33), SIMDE_FLOAT32_C(   172.86)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   768.25), SIMDE_FLOAT32_C(  -648.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -41.53),
                         SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(     3.01), SIMDE_FLOAT32_C(    40.06), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   662.13), SIMDE_FLOAT32_C(  -780.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(13045),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -696.33), SIMDE_FLOAT32_C(  -640.98), SIMDE_FLOAT32_C(  -234.04), SIMDE_FLOAT32_C(   691.30),
                         SIMDE_FLOAT32_C(   422.16), SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(   150.98), SIMDE_FLOAT32_C(  -727.93),
                         SIMDE_FLOAT32_C(  -292.95), SIMDE_FLOAT32_C(  -168.48), SIMDE_FLOAT32_C(   430.75), SIMDE_FLOAT32_C(   298.75),
                         SIMDE_FLOAT32_C(  -938.39), SIMDE_FLOAT32_C(   166.50), SIMDE_FLOAT32_C(   295.10), SIMDE_FLOAT32_C(   -66.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   725.67), SIMDE_FLOAT32_C(   691.57), SIMDE_FLOAT32_C(   408.92), SIMDE_FLOAT32_C(  -190.91),
                         SIMDE_FLOAT32_C(   682.56), SIMDE_FLOAT32_C(   311.99), SIMDE_FLOAT32_C(  -213.61), SIMDE_FLOAT32_C(  -160.20),
                         SIMDE_FLOAT32_C(  -421.91), SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(   657.47), SIMDE_FLOAT32_C(   816.91),
                         SIMDE_FLOAT32_C(   267.68), SIMDE_FLOAT32_C(   898.52), SIMDE_FLOAT32_C(   -80.12), SIMDE_FLOAT32_C(  -724.23)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   200.00), SIMDE_FLOAT32_C(     2.70),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   148.59), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -292.88), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(     2.06),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -2.08)) },
   {  UINT16_C(11913),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   315.17), SIMDE_FLOAT32_C(  -863.78), SIMDE_FLOAT32_C(   344.73), SIMDE_FLOAT32_C(  -570.00),
                         SIMDE_FLOAT32_C(  -265.79), SIMDE_FLOAT32_C(   403.67), SIMDE_FLOAT32_C(   -62.80), SIMDE_FLOAT32_C(   251.47),
                         SIMDE_FLOAT32_C(   143.15), SIMDE_FLOAT32_C(   960.55), SIMDE_FLOAT32_C(  -156.81), SIMDE_FLOAT32_C(   258.89),
                         SIMDE_FLOAT32_C(    14.13), SIMDE_FLOAT32_C(   117.08), SIMDE_FLOAT32_C(  -266.20), SIMDE_FLOAT32_C(   383.43)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -568.28), SIMDE_FLOAT32_C(  -745.49), SIMDE_FLOAT32_C(  -964.75), SIMDE_FLOAT32_C(   259.38),
                         SIMDE_FLOAT32_C(   750.99), SIMDE_FLOAT32_C(  -521.20), SIMDE_FLOAT32_C(   513.21), SIMDE_FLOAT32_C(   787.79),
                         SIMDE_FLOAT32_C(   316.72), SIMDE_FLOAT32_C(   -19.08), SIMDE_FLOAT32_C(  -845.60), SIMDE_FLOAT32_C(   815.31),
                         SIMDE_FLOAT32_C(  -301.01), SIMDE_FLOAT32_C(   479.36), SIMDE_FLOAT32_C(  -159.67), SIMDE_FLOAT32_C(  -155.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   142.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     8.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   155.69)) },
   {  UINT16_C(38742),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -500.21), SIMDE_FLOAT32_C(  -899.42), SIMDE_FLOAT32_C(   770.51), SIMDE_FLOAT32_C(   777.58),
                         SIMDE_FLOAT32_C(   547.07), SIMDE_FLOAT32_C(   747.18), SIMDE_FLOAT32_C(    16.17), SIMDE_FLOAT32_C(   859.01),
                         SIMDE_FLOAT32_C(    78.72), SIMDE_FLOAT32_C(  -378.16), SIMDE_FLOAT32_C(  -980.04), SIMDE_FLOAT32_C(   143.56),
                         SIMDE_FLOAT32_C(  -706.63), SIMDE_FLOAT32_C(  -986.84), SIMDE_FLOAT32_C(  -673.32), SIMDE_FLOAT32_C(  -774.96)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -321.38), SIMDE_FLOAT32_C(  -244.51), SIMDE_FLOAT32_C(   579.94), SIMDE_FLOAT32_C(   895.47),
                         SIMDE_FLOAT32_C(  -321.30), SIMDE_FLOAT32_C(    92.97), SIMDE_FLOAT32_C(  -270.40), SIMDE_FLOAT32_C(  -439.43),
                         SIMDE_FLOAT32_C(   971.85), SIMDE_FLOAT32_C(   799.33), SIMDE_FLOAT32_C(   -17.61), SIMDE_FLOAT32_C(  -762.15),
                         SIMDE_FLOAT32_C(  -813.48), SIMDE_FLOAT32_C(   494.42), SIMDE_FLOAT32_C(   374.64), SIMDE_FLOAT32_C(  -744.47)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -320.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   777.06),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.89), SIMDE_FLOAT32_C(    16.13), SIMDE_FLOAT32_C(     3.29),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.23),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     3.85), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(53846),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   400.20), SIMDE_FLOAT32_C(   275.50), SIMDE_FLOAT32_C(   916.86), SIMDE_FLOAT32_C(  -531.67),
                         SIMDE_FLOAT32_C(  -909.37), SIMDE_FLOAT32_C(   993.65), SIMDE_FLOAT32_C(   633.64), SIMDE_FLOAT32_C(  -178.42),
                         SIMDE_FLOAT32_C(   412.35), SIMDE_FLOAT32_C(  -571.03), SIMDE_FLOAT32_C(   345.26), SIMDE_FLOAT32_C(   493.12),
                         SIMDE_FLOAT32_C(  -719.68), SIMDE_FLOAT32_C(   769.35), SIMDE_FLOAT32_C(  -373.84), SIMDE_FLOAT32_C(  -540.22)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -282.19), SIMDE_FLOAT32_C(  -584.18), SIMDE_FLOAT32_C(   433.06), SIMDE_FLOAT32_C(   752.23),
                         SIMDE_FLOAT32_C(  -792.10), SIMDE_FLOAT32_C(   940.65), SIMDE_FLOAT32_C(  -237.54), SIMDE_FLOAT32_C(  -796.45),
                         SIMDE_FLOAT32_C(   821.11), SIMDE_FLOAT32_C(  -769.48), SIMDE_FLOAT32_C(   951.19), SIMDE_FLOAT32_C(   526.89),
                         SIMDE_FLOAT32_C(   481.01), SIMDE_FLOAT32_C(  -678.70), SIMDE_FLOAT32_C(   690.79), SIMDE_FLOAT32_C(  -617.07)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   272.19), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   528.17),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.19), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -513.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.04),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   512.07), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(45516),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -637.18), SIMDE_FLOAT32_C(   934.54), SIMDE_FLOAT32_C(   112.29), SIMDE_FLOAT32_C(   139.60),
                         SIMDE_FLOAT32_C(  -371.31), SIMDE_FLOAT32_C(  -676.65), SIMDE_FLOAT32_C(  -607.44), SIMDE_FLOAT32_C(  -108.80),
                         SIMDE_FLOAT32_C(  -631.32), SIMDE_FLOAT32_C(   553.47), SIMDE_FLOAT32_C(  -653.07), SIMDE_FLOAT32_C(  -272.71),
                         SIMDE_FLOAT32_C(  -438.05), SIMDE_FLOAT32_C(   -69.28), SIMDE_FLOAT32_C(   220.30), SIMDE_FLOAT32_C(  -879.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   695.29), SIMDE_FLOAT32_C(  -288.10), SIMDE_FLOAT32_C(     8.22), SIMDE_FLOAT32_C(   267.50),
                         SIMDE_FLOAT32_C(  -160.08), SIMDE_FLOAT32_C(   251.69), SIMDE_FLOAT32_C(   416.95), SIMDE_FLOAT32_C(   429.19),
                         SIMDE_FLOAT32_C(  -938.09), SIMDE_FLOAT32_C(  -996.83), SIMDE_FLOAT32_C(   772.01), SIMDE_FLOAT32_C(   -88.73),
                         SIMDE_FLOAT32_C(  -661.22), SIMDE_FLOAT32_C(  -945.44), SIMDE_FLOAT32_C(   528.59), SIMDE_FLOAT32_C(   677.63)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   565.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(   129.50),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   104.30),
                         SIMDE_FLOAT32_C(  -546.07), SIMDE_FLOAT32_C(   544.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -2.02), SIMDE_FLOAT32_C(    -2.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_maskz_and_ps(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_and_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
   {  UINT8_C( 62),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  337.23), SIMDE_FLOAT64_C( -706.51),
                         SIMDE_FLOAT64_C(  -51.03), SIMDE_FLOAT64_C(  -11.12),
                         SIMDE_FLOAT64_C(  780.39), SIMDE_FLOAT64_C(  482.32),
                         SIMDE_FLOAT64_C( -313.20), SIMDE_FLOAT64_C(  986.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -459.33), SIMDE_FLOAT64_C(  566.75),
                         SIMDE_FLOAT64_C(  454.16), SIMDE_FLOAT64_C( -566.29),
                         SIMDE_FLOAT64_C(  217.01), SIMDE_FLOAT64_C( -444.68),
                         SIMDE_FLOAT64_C(  725.53), SIMDE_FLOAT64_C( -673.17)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(   48.02), SIMDE_FLOAT64_C(   -2.02),
                         SIMDE_FLOAT64_C(    3.02), SIMDE_FLOAT64_C(  416.00),
                         SIMDE_FLOAT64_C(    2.31), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(178),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  988.70), SIMDE_FLOAT64_C(  952.56),
                         SIMDE_FLOAT64_C( -917.57), SIMDE_FLOAT64_C( -161.93),
                         SIMDE_FLOAT64_C(  553.05), SIMDE_FLOAT64_C(  358.83),
                         SIMDE_FLOAT64_C( -335.21), SIMDE_FLOAT64_C(  243.33)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  368.67), SIMDE_FLOAT64_C( -326.68),
                         SIMDE_FLOAT64_C( -767.44), SIMDE_FLOAT64_C( -965.45),
                         SIMDE_FLOAT64_C(  160.34), SIMDE_FLOAT64_C( -153.49),
                         SIMDE_FLOAT64_C(  842.87), SIMDE_FLOAT64_C( -959.77)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.75), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -661.06), SIMDE_FLOAT64_C(   -2.52),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    2.04), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(233),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  789.99), SIMDE_FLOAT64_C(   -0.83),
                         SIMDE_FLOAT64_C( -595.87), SIMDE_FLOAT64_C( -556.04),
                         SIMDE_FLOAT64_C( -673.58), SIMDE_FLOAT64_C(  820.52),
                         SIMDE_FLOAT64_C(  763.24), SIMDE_FLOAT64_C(  747.54)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -863.51), SIMDE_FLOAT64_C(  297.93),
                         SIMDE_FLOAT64_C(  664.70), SIMDE_FLOAT64_C(   43.00),
                         SIMDE_FLOAT64_C(  283.69), SIMDE_FLOAT64_C( -882.73),
                         SIMDE_FLOAT64_C(   56.70), SIMDE_FLOAT64_C( -683.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  789.50), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  528.57), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    2.13), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  683.04)) },
   {  UINT8_C( 29),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -942.62), SIMDE_FLOAT64_C(  810.42),
                         SIMDE_FLOAT64_C( -781.08), SIMDE_FLOAT64_C(  565.31),
                         SIMDE_FLOAT64_C( -528.23), SIMDE_FLOAT64_C( -642.03),
                         SIMDE_FLOAT64_C( -124.04), SIMDE_FLOAT64_C(  -13.65)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   20.85), SIMDE_FLOAT64_C( -517.24),
                         SIMDE_FLOAT64_C(  -21.32), SIMDE_FLOAT64_C(  729.98),
                         SIMDE_FLOAT64_C( -763.15), SIMDE_FLOAT64_C(  885.38),
                         SIMDE_FLOAT64_C(  783.63), SIMDE_FLOAT64_C(  470.19)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  529.29),
                         SIMDE_FLOAT64_C( -528.13), SIMDE_FLOAT64_C(  512.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   12.63)) },
   {  UINT8_C(102),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -36.60), SIMDE_FLOAT64_C(  -71.02),
                         SIMDE_FLOAT64_C(  654.55), SIMDE_FLOAT64_C( -335.18),
                         SIMDE_FLOAT64_C( -889.86), SIMDE_FLOAT64_C( -624.64),
                         SIMDE_FLOAT64_C(  369.01), SIMDE_FLOAT64_C(  798.90)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -217.14), SIMDE_FLOAT64_C( -334.27),
                         SIMDE_FLOAT64_C(  522.28), SIMDE_FLOAT64_C(  754.78),
                         SIMDE_FLOAT64_C( -987.63), SIMDE_FLOAT64_C(  746.58),
                         SIMDE_FLOAT64_C(  358.61), SIMDE_FLOAT64_C( -154.14)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  -67.00),
                         SIMDE_FLOAT64_C(  522.02), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  608.50),
                         SIMDE_FLOAT64_C(  352.00), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(126),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -16.31), SIMDE_FLOAT64_C(  -95.18),
                         SIMDE_FLOAT64_C(  860.06), SIMDE_FLOAT64_C(  464.41),
                         SIMDE_FLOAT64_C(  822.39), SIMDE_FLOAT64_C(  185.79),
                         SIMDE_FLOAT64_C(  959.83), SIMDE_FLOAT64_C(  -98.41)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -560.42), SIMDE_FLOAT64_C( -521.57),
                         SIMDE_FLOAT64_C( -947.45), SIMDE_FLOAT64_C(   99.55),
                         SIMDE_FLOAT64_C(  108.53), SIMDE_FLOAT64_C(  194.26),
                         SIMDE_FLOAT64_C(  449.89), SIMDE_FLOAT64_C(  718.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -2.04),
                         SIMDE_FLOAT64_C(  784.01), SIMDE_FLOAT64_C(   96.03),
                         SIMDE_FLOAT64_C(    3.14), SIMDE_FLOAT64_C(  128.26),
                         SIMDE_FLOAT64_C(    3.51), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(231),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -343.46), SIMDE_FLOAT64_C(  643.05),
                         SIMDE_FLOAT64_C(  758.23), SIMDE_FLOAT64_C(  243.41),
                         SIMDE_FLOAT64_C( -569.27), SIMDE_FLOAT64_C(   62.99),
                         SIMDE_FLOAT64_C(  403.36), SIMDE_FLOAT64_C( -111.26)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  594.69), SIMDE_FLOAT64_C(  416.92),
                         SIMDE_FLOAT64_C(  294.94), SIMDE_FLOAT64_C( -386.69),
                         SIMDE_FLOAT64_C(  444.27), SIMDE_FLOAT64_C(  112.48),
                         SIMDE_FLOAT64_C(  775.25), SIMDE_FLOAT64_C(  973.66)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(    2.27), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   56.24),
                         SIMDE_FLOAT64_C(    3.02), SIMDE_FLOAT64_C(    3.28)) },
   {  UINT8_C(248),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  559.94), SIMDE_FLOAT64_C( -177.36),
                         SIMDE_FLOAT64_C(  459.52), SIMDE_FLOAT64_C(  151.00),
                         SIMDE_FLOAT64_C( -261.20), SIMDE_FLOAT64_C(  619.75),
                         SIMDE_FLOAT64_C( -541.43), SIMDE_FLOAT64_C( -420.37)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  279.51), SIMDE_FLOAT64_C(  143.05),
                         SIMDE_FLOAT64_C(  835.37), SIMDE_FLOAT64_C( -486.11),
                         SIMDE_FLOAT64_C(  461.53), SIMDE_FLOAT64_C(  410.57),
                         SIMDE_FLOAT64_C( -362.30), SIMDE_FLOAT64_C( -345.54)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.18), SIMDE_FLOAT64_C(  129.05),
                         SIMDE_FLOAT64_C(    3.01), SIMDE_FLOAT64_C(  147.00),
                         SIMDE_FLOAT64_C(  261.01), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_maskz_and_pd(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_and_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 2103907232), INT32_C(-1995421302), INT32_C( 1328084931), INT32_C( -379562245),
                            INT32_C( 1144599747), INT32_C(-1418414219), INT32_C( 1379143176), INT32_C(-2075387410),
                            INT32_C(-1152868472), INT32_C( 1425101887), INT32_C(-1626225579), INT32_C( 2014677400),
                            INT32_C( 1108777022), INT32_C(  877429697), INT32_C( 1558575022), INT32_C(  651318578)),
      simde_mm512_set_epi32(INT32_C( -803993576), INT32_C(  163813867), INT32_C(-1017884831), INT32_C(-1258992440),
                            INT32_C( 1182354404), INT32_C(-1425047283), INT32_C( 1708628167), INT32_C(-2051115159),
                            INT32_C(  143410800), INT32_C(-1041180848), INT32_C(-1023702255), INT32_C( -240255997),
                            INT32_C(  978107452), INT32_C(-1343783755), INT32_C( -880122145), INT32_C( 1183808039)),
      simde_mm512_set_epi32(INT32_C( 1342439424), INT32_C(  150997386), INT32_C( 1124091713), INT32_C(-1604303672),
                            INT32_C( 1144586432), INT32_C(-1425768187), INT32_C( 1075054592), INT32_C(-2079583896),
                            INT32_C(  134743552), INT32_C( 1089491984), INT32_C(-2112782319), INT32_C( 1879410688),
                            INT32_C(   33855548), INT32_C(  608436353), INT32_C( 1216374414), INT32_C(  109203490)) },
    { simde_mm512_set_epi32(INT32_C( 1231278072), INT32_C(  832865002), INT32_C(-1694490420), INT32_C( -466764866),
                            INT32_C( 1702721236), INT32_C( 2092439418), INT32_C(  611933067), INT32_C(-1184445720),
                            INT32_C(-1689922195), INT32_C(-1140532352), INT32_C(  158346875), INT32_C( 1089717474),
                            INT32_C( 1230253618), INT32_C( 1504968720), INT32_C(  653725328), INT32_C( 1822881045)),
      simde_mm512_set_epi32(INT32_C(-1605590998), INT32_C( 1810066171), INT32_C(  -10167007), INT32_C( 1359569321),
                            INT32_C(-1430119757), INT32_C(  256064867), INT32_C(  788618356), INT32_C( -392789188),
                            INT32_C( -613873031), INT32_C(  773158597), INT32_C( -194106681), INT32_C(  165465349),
                            INT32_C(-1346434037), INT32_C(-1412186885), INT32_C( -632750822), INT32_C( 1966832804)),
      simde_mm512_set_epi32(INT32_C(    4227112), INT32_C(  564134634), INT32_C(-1694498816), INT32_C( 1074340264),
                            INT32_C(  541069968), INT32_C(  201332066), INT32_C(  604067840), INT32_C(-1475968472),
                            INT32_C(-1690238871), INT32_C(  738480768), INT32_C(    6302275), INT32_C(   13681664),
                            INT32_C(  152308738), INT32_C(  160432144), INT32_C(   37751824), INT32_C( 1679979524)) },
    { simde_mm512_set_epi32(INT32_C(-1888865381), INT32_C(   15541452), INT32_C( -670396349), INT32_C(-1090081489),
                            INT32_C(  116025329), INT32_C(  130963716), INT32_C(  230354364), INT32_C( 1174065929),
                            INT32_C( 1971493681), INT32_C(-1343257591), INT32_C(-1419733408), INT32_C(  659096905),
                            INT32_C(  183711411), INT32_C( -298263182), INT32_C(-1286938208), INT32_C(  537660993)),
      simde_mm512_set_epi32(INT32_C( 1616282233), INT32_C(-2132390836), INT32_C( -153917613), INT32_C(  736513734),
                            INT32_C(-1311057544), INT32_C(  505476811), INT32_C( 1767695145), INT32_C(  157469724),
                            INT32_C( -371725260), INT32_C( 1996701751), INT32_C(-1377678442), INT32_C( -132601652),
                            INT32_C( -903948497), INT32_C( -794660034), INT32_C(  173952757), INT32_C( 1507611872)),
      simde_mm512_set_epi32(INT32_C(    4325913), INT32_C(   14943308), INT32_C( -805175229), INT32_C(  721816582),
                            INT32_C(   13255024), INT32_C(  100683776), INT32_C(  152625448), INT32_C(   23248904),
                            INT32_C( 1635944496), INT32_C(  654508033), INT32_C(-1453325824), INT32_C(  537395272),
                            INT32_C(  168957475), INT32_C(-1071623886), INT32_C(   38420640), INT32_C(     787520)) },
    { simde_mm512_set_epi32(INT32_C( -748350470), INT32_C( 1755197901), INT32_C( 1090059253), INT32_C( 1329426651),
                            INT32_C(-1604442789), INT32_C(  878047098), INT32_C(-1682276633), INT32_C(  -78811559),
                            INT32_C( -973139496), INT32_C(   91517188), INT32_C(   37440120), INT32_C(  829401648),
                            INT32_C(  860279707), INT32_C(  218373799), INT32_C( -362113249), INT32_C( -694086277)),
      simde_mm512_set_epi32(INT32_C(  892006932), INT32_C(-1158010747), INT32_C( -700127305), INT32_C(-1058033333),
                            INT32_C( 2135825335), INT32_C( -510043422), INT32_C( -139544800), INT32_C(   95748631),
                            INT32_C( 1671238992), INT32_C( 1305915968), INT32_C( -582790199), INT32_C( 1758236157),
                            INT32_C(  986405639), INT32_C( 1121234438), INT32_C( -731393712), INT32_C( -784753228)),
      simde_mm512_set_epi32(INT32_C(  287314448), INT32_C(  681189509), INT32_C( 1077994421), INT32_C( 1076703307),
                            INT32_C(  541982995), INT32_C(  538004066), INT32_C(-1817561568), INT32_C(   17105425),
                            INT32_C( 1100812624), INT32_C(   89403392), INT32_C(     213576), INT32_C(  541886512),
                            INT32_C(  843207427), INT32_C(     265734), INT32_C(-1067282160), INT32_C( -803138256)) },
    { simde_mm512_set_epi32(INT32_C( 1347900829), INT32_C(-1792354715), INT32_C( -371177698), INT32_C(  255088013),
                            INT32_C( 1961231505), INT32_C( -659343095), INT32_C( 1620234692), INT32_C(  843561067),
                            INT32_C( 1265300992), INT32_C(-1675104490), INT32_C( -873664156), INT32_C(-2045109653),
                            INT32_C( 2057630636), INT32_C(  335188274), INT32_C( 1272591061), INT32_C( -327494197)),
      simde_mm512_set_epi32(INT32_C(-2095740678), INT32_C(-1857753563), INT32_C(-1236342636), INT32_C( 1439297909),
                            INT32_C( -576201057), INT32_C( 1488873085), INT32_C(-1369304746), INT32_C(  567848046),
                            INT32_C( 1335236564), INT32_C( -942680632), INT32_C(-1512916560), INT32_C( -697747292),
                            INT32_C(-1779695782), INT32_C(  491327584), INT32_C( -563681080), INT32_C( 1527319596)),
      simde_mm512_set_epi32(INT32_C(    1376408), INT32_C(-1862220251), INT32_C(-1606402028), INT32_C(   83906821),
                            INT32_C( 1420166289), INT32_C( 1488068617), INT32_C(  537006404), INT32_C(  541108330),
                            INT32_C( 1258427904), INT32_C(-2079865600), INT32_C(-2118078176), INT32_C(-2046289888),
                            INT32_C(  278983432), INT32_C(  289935392), INT32_C( 1245847744), INT32_C( 1208484872)) },
    { simde_mm512_set_epi32(INT32_C(  131205926), INT32_C( 2061955170), INT32_C(   37003574), INT32_C( 1649229141),
                            INT32_C(  612060260), INT32_C(-1402263233), INT32_C( -513572270), INT32_C(  701923816),
                            INT32_C(  511549547), INT32_C(  969083331), INT32_C( 1364542630), INT32_C( -822209230),
                            INT32_C(-1549704264), INT32_C(-1157339218), INT32_C(-2025137124), INT32_C(-1631723043)),
      simde_mm512_set_epi32(INT32_C(  424825857), INT32_C(  434716327), INT32_C( 1663095683), INT32_C( 1730428966),
                            INT32_C( -252943126), INT32_C(  373990324), INT32_C( 2100741912), INT32_C(-1005385937),
                            INT32_C(-1470990839), INT32_C(-1200692008), INT32_C(-2098508971), INT32_C(  488824783),
                            INT32_C( 1647236603), INT32_C(-1221154150), INT32_C(-1012750616), INT32_C( 1849794587)),
      simde_mm512_set_epi32(INT32_C(   22151168), INT32_C(  417345570), INT32_C(   35684610), INT32_C( 1644429316),
                            INT32_C(  543704160), INT32_C(   71967028), INT32_C( 1629651472), INT32_C(    1179944),
                            INT32_C(  139468809), INT32_C(  943849664), INT32_C(    4276228), INT32_C(  203560194),
                            INT32_C(  572539320), INT32_C(-1291574646), INT32_C(-2096987128), INT32_C(  234987545)) },
    { simde_mm512_set_epi32(INT32_C(-2080136983), INT32_C( -623547588), INT32_C( 1015056564), INT32_C(-1333355305),
                            INT32_C( 1925062912), INT32_C(  330138155), INT32_C( -444195598), INT32_C(  874806560),
                            INT32_C(  319126943), INT32_C(  475403370), INT32_C( -873396634), INT32_C(-1835948135),
                            INT32_C(-1570208244), INT32_C( -244400530), INT32_C( 1126824505), INT32_C( 1036340167)),
      simde_mm512_set_epi32(INT32_C(-1989715102), INT32_C( 1785805415), INT32_C( 1739507553), INT32_C(-1932540399),
                            INT32_C( -641363523), INT32_C(   72499486), INT32_C(-2005610208), INT32_C( -497730582),
                            INT32_C(  312611747), INT32_C(  793357988), INT32_C(  607421194), INT32_C(-1375787856),
                            INT32_C( 1799684145), INT32_C( -551549754), INT32_C( 1249951615), INT32_C( 1447553529)),
      simde_mm512_set_epi32(INT32_C(-2147286944), INT32_C( 1246833188), INT32_C(  612401184), INT32_C(-2138668015),
                            INT32_C( 1350828288), INT32_C(         10), INT32_C(-2147217376), INT32_C(  537147680),
                            INT32_C(  301994371), INT32_C(  205521952), INT32_C(    3146242), INT32_C(-2137971568),
                            INT32_C(  574619648), INT32_C( -786430906), INT32_C( 1107343929), INT32_C(  340085185)) },
    { simde_mm512_set_epi32(INT32_C(  423295425), INT32_C( -460615607), INT32_C( 1208771148), INT32_C(-2128303155),
                            INT32_C( -738338972), INT32_C( 2110676823), INT32_C(-1405320678), INT32_C(-2007459833),
                            INT32_C( 1043638626), INT32_C( -542891463), INT32_C(  629803756), INT32_C(-1216921331),
                            INT32_C( -301860714), INT32_C(  317296385), INT32_C( 1833800187), INT32_C( -645353377)),
      simde_mm512_set_epi32(INT32_C( -257851255), INT32_C( -479522767), INT32_C(  745275629), INT32_C(-1783480446),
                            INT32_C(-1431666964), INT32_C( -422291816), INT32_C( -309252994), INT32_C(-2112946871),
                            INT32_C(-2123521230), INT32_C( -883174176), INT32_C( -332498316), INT32_C(  142889340),
                            INT32_C( 1231002435), INT32_C( 1681334055), INT32_C(  138372594), INT32_C( -878588971)),
      simde_mm512_set_epi32(INT32_C(  270565505), INT32_C( -536145919), INT32_C(  135004236), INT32_C(-2128598144),
                            INT32_C(-2102897052), INT32_C( 1690588688), INT32_C(-1408237542), INT32_C(-2146920447),
                            INT32_C(    2400546), INT32_C( -889192416), INT32_C(  604637796), INT32_C(     278796),
                            INT32_C( 1208064002), INT32_C(    2166529), INT32_C(  135070194), INT32_C( -914325419)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_and_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_and_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 2103907232), INT32_C(-1995421302), INT32_C( 1328084931), INT32_C( -379562245),
                            INT32_C( 1144599747), INT32_C(-1418414219), INT32_C( 1379143176), INT32_C(-2075387410),
                            INT32_C(-1152868472), INT32_C( 1425101887), INT32_C(-1626225579), INT32_C( 2014677400),
                            INT32_C( 1108777022), INT32_C(  877429697), INT32_C( 1558575022), INT32_C(  651318578)),
      UINT16_C(31271),
      simde_mm512_set_epi32(INT32_C( 1822881045), INT32_C( -803993576), INT32_C(  163813867), INT32_C(-1017884831),
                            INT32_C(-1258992440), INT32_C( 1182354404), INT32_C(-1425047283), INT32_C( 1708628167),
                            INT32_C(-2051115159), INT32_C(  143410800), INT32_C(-1041180848), INT32_C(-1023702255),
                            INT32_C( -240255997), INT32_C(  978107452), INT32_C(-1343783755), INT32_C( -880122145)),
      simde_mm512_set_epi32(INT32_C( 1966832804), INT32_C( 1231278072), INT32_C(  832865002), INT32_C(-1694490420),
                            INT32_C( -466764866), INT32_C( 1702721236), INT32_C( 2092439418), INT32_C(  611933067),
                            INT32_C(-1184445720), INT32_C(-1689922195), INT32_C(-1140532352), INT32_C(  158346875),
                            INT32_C( 1089717474), INT32_C( 1230253618), INT32_C( 1504968720), INT32_C(  653725328)),
      simde_mm512_set_epi32(INT32_C( 2103907232), INT32_C( 1073743896), INT32_C(   25198826), INT32_C(-2097151936),
                            INT32_C(-1541076856), INT32_C(-1418414219), INT32_C(  671613192), INT32_C(-2075387410),
                            INT32_C(-1152868472), INT32_C( 1425101887), INT32_C(-2147429632), INT32_C( 2014677400),
                            INT32_C( 1108777022), INT32_C(  138685488), INT32_C(  161742864), INT32_C(   42075792)) },
    { simde_mm512_set_epi32(INT32_C(  537660993), INT32_C(-1605590998), INT32_C( 1810066171), INT32_C(  -10167007),
                            INT32_C( 1359569321), INT32_C(-1430119757), INT32_C(  256064867), INT32_C(  788618356),
                            INT32_C( -392789188), INT32_C( -613873031), INT32_C(  773158597), INT32_C( -194106681),
                            INT32_C(  165465349), INT32_C(-1346434037), INT32_C(-1412186885), INT32_C( -632750822)),
      UINT16_C(57760),
      simde_mm512_set_epi32(INT32_C(  173952757), INT32_C( 1507611872), INT32_C(-1888865381), INT32_C(   15541452),
                            INT32_C( -670396349), INT32_C(-1090081489), INT32_C(  116025329), INT32_C(  130963716),
                            INT32_C(  230354364), INT32_C( 1174065929), INT32_C( 1971493681), INT32_C(-1343257591),
                            INT32_C(-1419733408), INT32_C(  659096905), INT32_C(  183711411), INT32_C( -298263182)),
      simde_mm512_set_epi32(INT32_C( -362113249), INT32_C( -694086277), INT32_C( 1616282233), INT32_C(-2132390836),
                            INT32_C( -153917613), INT32_C(  736513734), INT32_C(-1311057544), INT32_C(  505476811),
                            INT32_C( 1767695145), INT32_C(  157469724), INT32_C( -371725260), INT32_C( 1996701751),
                            INT32_C(-1377678442), INT32_C( -132601652), INT32_C( -903948497), INT32_C( -794660034)),
      simde_mm512_set_epi32(INT32_C(  172623381), INT32_C( 1350571104), INT32_C(    4325913), INT32_C(  -10167007),
                            INT32_C( 1359569321), INT32_C(-1430119757), INT32_C(  256064867), INT32_C(  100683776),
                            INT32_C(  152625448), INT32_C( -613873031), INT32_C( 1635944496), INT32_C( -194106681),
                            INT32_C(  165465349), INT32_C(-1346434037), INT32_C(-1412186885), INT32_C( -632750822)) },
    { simde_mm512_set_epi32(INT32_C( -731393712), INT32_C( -784753228), INT32_C( -748350470), INT32_C( 1755197901),
                            INT32_C( 1090059253), INT32_C( 1329426651), INT32_C(-1604442789), INT32_C(  878047098),
                            INT32_C(-1682276633), INT32_C(  -78811559), INT32_C( -973139496), INT32_C(   91517188),
                            INT32_C(   37440120), INT32_C(  829401648), INT32_C(  860279707), INT32_C(  218373799)),
      UINT16_C(44550),
      simde_mm512_set_epi32(INT32_C(  335188274), INT32_C( 1272591061), INT32_C( -327494197), INT32_C(  892006932),
                            INT32_C(-1158010747), INT32_C( -700127305), INT32_C(-1058033333), INT32_C( 2135825335),
                            INT32_C( -510043422), INT32_C( -139544800), INT32_C(   95748631), INT32_C( 1671238992),
                            INT32_C( 1305915968), INT32_C( -582790199), INT32_C( 1758236157), INT32_C(  986405639)),
      simde_mm512_set_epi32(INT32_C(  491327584), INT32_C( -563681080), INT32_C( 1527319596), INT32_C( 1347900829),
                            INT32_C(-1792354715), INT32_C( -371177698), INT32_C(  255088013), INT32_C( 1961231505),
                            INT32_C( -659343095), INT32_C( 1620234692), INT32_C(  843561067), INT32_C( 1265300992),
                            INT32_C(-1675104490), INT32_C( -873664156), INT32_C(-2045109653), INT32_C( 2057630636)),
      simde_mm512_set_epi32(INT32_C(  289935392), INT32_C( -784753228), INT32_C( 1208484872), INT32_C( 1755197901),
                            INT32_C(-1876295675), INT32_C(-1069529322), INT32_C(    2363657), INT32_C(  878047098),
                            INT32_C(-1682276633), INT32_C(  -78811559), INT32_C( -973139496), INT32_C(   91517188),
                            INT32_C(   37440120), INT32_C( -918531776), INT32_C(     526441), INT32_C(  218373799)) },
    { simde_mm512_set_epi32(INT32_C(-1157339218), INT32_C(-2025137124), INT32_C(-1631723043), INT32_C(-2095740678),
                            INT32_C(-1857753563), INT32_C(-1236342636), INT32_C( 1439297909), INT32_C( -576201057),
                            INT32_C( 1488873085), INT32_C(-1369304746), INT32_C(  567848046), INT32_C( 1335236564),
                            INT32_C( -942680632), INT32_C(-1512916560), INT32_C( -697747292), INT32_C(-1779695782)),
      UINT16_C(25528),
      simde_mm512_set_epi32(INT32_C( 1647236603), INT32_C(-1221154150), INT32_C(-1012750616), INT32_C( 1849794587),
                            INT32_C(  131205926), INT32_C( 2061955170), INT32_C(   37003574), INT32_C( 1649229141),
                            INT32_C(  612060260), INT32_C(-1402263233), INT32_C( -513572270), INT32_C(  701923816),
                            INT32_C(  511549547), INT32_C(  969083331), INT32_C( 1364542630), INT32_C( -822209230)),
      simde_mm512_set_epi32(INT32_C(-1570208244), INT32_C( -244400530), INT32_C( 1126824505), INT32_C( 1036340167),
                            INT32_C(  424825857), INT32_C(  434716327), INT32_C( 1663095683), INT32_C( 1730428966),
                            INT32_C( -252943126), INT32_C(  373990324), INT32_C( 2100741912), INT32_C(-1005385937),
                            INT32_C(-1470990839), INT32_C(-1200692008), INT32_C(-2098508971), INT32_C(  488824783)),
      simde_mm512_set_epi32(INT32_C(-1157339218), INT32_C(-1322866166), INT32_C( 1126212136), INT32_C(-2095740678),
                            INT32_C(-1857753563), INT32_C(-1236342636), INT32_C(   35684610), INT32_C( 1644429316),
                            INT32_C(  543704160), INT32_C(-1369304746), INT32_C( 1629651472), INT32_C(    1179944),
                            INT32_C(  139468809), INT32_C(-1512916560), INT32_C( -697747292), INT32_C(-1779695782)) },
    { simde_mm512_set_epi32(INT32_C( 1799684145), INT32_C( -551549754), INT32_C( 1249951615), INT32_C( 1447553529),
                            INT32_C(-2080136983), INT32_C( -623547588), INT32_C( 1015056564), INT32_C(-1333355305),
                            INT32_C( 1925062912), INT32_C(  330138155), INT32_C( -444195598), INT32_C(  874806560),
                            INT32_C(  319126943), INT32_C(  475403370), INT32_C( -873396634), INT32_C(-1835948135)),
      UINT16_C( 9392),
      simde_mm512_set_epi32(INT32_C(-1216921331), INT32_C( -301860714), INT32_C(  317296385), INT32_C( 1833800187),
                            INT32_C( -645353377), INT32_C(-1989715102), INT32_C( 1785805415), INT32_C( 1739507553),
                            INT32_C(-1932540399), INT32_C( -641363523), INT32_C(   72499486), INT32_C(-2005610208),
                            INT32_C( -497730582), INT32_C(  312611747), INT32_C(  793357988), INT32_C(  607421194)),
      simde_mm512_set_epi32(INT32_C(  142889340), INT32_C( 1231002435), INT32_C( 1681334055), INT32_C(  138372594),
                            INT32_C( -878588971), INT32_C(  423295425), INT32_C( -460615607), INT32_C( 1208771148),
                            INT32_C(-2128303155), INT32_C( -738338972), INT32_C( 2110676823), INT32_C(-1405320678),
                            INT32_C(-2007459833), INT32_C( 1043638626), INT32_C( -542891463), INT32_C(  629803756)),
      simde_mm512_set_epi32(INT32_C( 1799684145), INT32_C( -551549754), INT32_C(    2166529), INT32_C( 1447553529),
                            INT32_C(-2080136983), INT32_C(  153246016), INT32_C( 1015056564), INT32_C(-1333355305),
                            INT32_C(-2147188223), INT32_C(  330138155), INT32_C(   71450902), INT32_C(-2009825280),
                            INT32_C(  319126943), INT32_C(  475403370), INT32_C( -873396634), INT32_C(-1835948135)) },
    { simde_mm512_set_epi32(INT32_C(  861635987), INT32_C( 1823839521), INT32_C( 1391000031), INT32_C(   73229946),
                            INT32_C(  -53693878), INT32_C( -257851255), INT32_C( -479522767), INT32_C(  745275629),
                            INT32_C(-1783480446), INT32_C(-1431666964), INT32_C( -422291816), INT32_C( -309252994),
                            INT32_C(-2112946871), INT32_C(-2123521230), INT32_C( -883174176), INT32_C( -332498316)),
      UINT16_C(31381),
      simde_mm512_set_epi32(INT32_C( -410707923), INT32_C( -804790801), INT32_C( -675940069), INT32_C(  717543141),
                            INT32_C( 1610339352), INT32_C(  785451213), INT32_C(  -67248356), INT32_C(-1147482606),
                            INT32_C(  877778312), INT32_C( 1833609670), INT32_C( 1105011960), INT32_C(-1909564752),
                            INT32_C(-2137129603), INT32_C(-1991115340), INT32_C( -941377596), INT32_C(-1151664921)),
      simde_mm512_set_epi32(INT32_C( -605598510), INT32_C( 1332169075), INT32_C(  829771204), INT32_C(  806631323),
                            INT32_C(  -62111889), INT32_C( 1452741835), INT32_C(  921236435), INT32_C(-1348081811),
                            INT32_C( -883327193), INT32_C(-1324808596), INT32_C(-2119312832), INT32_C(-1371509978),
                            INT32_C(-1887676953), INT32_C(   42335263), INT32_C(  818544934), INT32_C(-1864687690)),
      simde_mm512_set_epi32(INT32_C(  861635987), INT32_C( 1074219363), INT32_C(  288704768), INT32_C(  537138817),
                            INT32_C( 1548227592), INT32_C( -257851255), INT32_C(  854119184), INT32_C(  745275629),
                            INT32_C(    5330176), INT32_C(-1431666964), INT32_C( -422291816), INT32_C(-1912583648),
                            INT32_C(-2112946871), INT32_C(     130068), INT32_C( -883174176), INT32_C(-1873142618)) },
    { simde_mm512_set_epi32(INT32_C( 1456151906), INT32_C( -346366427), INT32_C(  534496658), INT32_C( 1981510934),
                            INT32_C( -935678271), INT32_C( 1523008579), INT32_C(   -6105095), INT32_C( 2115600842),
                            INT32_C( -420343454), INT32_C(  652783640), INT32_C( -871055383), INT32_C(  142253075),
                            INT32_C(  557825344), INT32_C(  707825888), INT32_C(  944883191), INT32_C( 1704858885)),
      UINT16_C(19039),
      simde_mm512_set_epi32(INT32_C( 1893303454), INT32_C( 1567616976), INT32_C( 1190892677), INT32_C( 1594451864),
                            INT32_C(-1033342432), INT32_C( -738674203), INT32_C(-1847547828), INT32_C( 1893640833),
                            INT32_C(   26320713), INT32_C( 1830669951), INT32_C( 1304924639), INT32_C( -277717409),
                            INT32_C(-1566722863), INT32_C( 1534951086), INT32_C( -925669609), INT32_C(  359322092)),
      simde_mm512_set_epi32(INT32_C( 1160904262), INT32_C(  732990033), INT32_C(  138388028), INT32_C( 1168180194),
                            INT32_C( 1057944486), INT32_C( 1875512725), INT32_C( -910818137), INT32_C( -743685110),
                            INT32_C( -947775444), INT32_C( 1458691146), INT32_C( 1273454073), INT32_C(  927814838),
                            INT32_C(-1840329583), INT32_C( -789758267), INT32_C( -870216121), INT32_C(  449327093)),
      simde_mm512_set_epi32(INT32_C( 1456151906), INT32_C(  153127504), INT32_C(  534496658), INT32_C( 1981510934),
                            INT32_C(   34107936), INT32_C( 1523008579), INT32_C(-2120220668), INT32_C( 2115600842),
                            INT32_C( -420343454), INT32_C( 1142017098), INT32_C( -871055383), INT32_C(  658527254),
                            INT32_C(-2113108847), INT32_C( 1349336708), INT32_C( -939457017), INT32_C(  273154532)) },
    { simde_mm512_set_epi32(INT32_C(-1055194531), INT32_C( 1846727705), INT32_C(  335680535), INT32_C( -610713755),
                            INT32_C(  944256620), INT32_C(  697979892), INT32_C(   49552843), INT32_C( -460412596),
                            INT32_C(-2060335241), INT32_C(  135497979), INT32_C( -331098630), INT32_C( -140680021),
                            INT32_C(-1676162464), INT32_C(  626483741), INT32_C(  170885439), INT32_C(  230851400)),
      UINT16_C(10528),
      simde_mm512_set_epi32(INT32_C(-1447071985), INT32_C( -310464227), INT32_C( -679161042), INT32_C( -527096592),
                            INT32_C( 1833269922), INT32_C(-1164990327), INT32_C( 1955493691), INT32_C( 1263046717),
                            INT32_C( 1122048689), INT32_C( 2074234443), INT32_C(  723669938), INT32_C(  284884896),
                            INT32_C( -458264538), INT32_C(  514387150), INT32_C(-1369468153), INT32_C( 1859652102)),
      simde_mm512_set_epi32(INT32_C(-1315612420), INT32_C( -330188185), INT32_C(     890374), INT32_C( -958458643),
                            INT32_C( 2023887571), INT32_C(  226435011), INT32_C(    1929100), INT32_C(-1975437469),
                            INT32_C(  871389437), INT32_C(-2041059805), INT32_C(  636566673), INT32_C( -485819928),
                            INT32_C(  904524629), INT32_C(-1963695561), INT32_C( -297278672), INT32_C(-1666020030)),
      simde_mm512_set_epi32(INT32_C(-1055194531), INT32_C( 1846727705), INT32_C(     299526), INT32_C( -610713755),
                            INT32_C( 1744835202), INT32_C(  697979892), INT32_C(   49552843), INT32_C(  171970593),
                            INT32_C(-2060335241), INT32_C(  135497979), INT32_C(  555749520), INT32_C( -140680021),
                            INT32_C(-1676162464), INT32_C(  626483741), INT32_C(  170885439), INT32_C(  230851400)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_and_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_and_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { UINT16_C(21810),
      simde_mm512_set_epi32(INT32_C( 1183808039), INT32_C( 2103907232), INT32_C(-1995421302), INT32_C( 1328084931),
                            INT32_C( -379562245), INT32_C( 1144599747), INT32_C(-1418414219), INT32_C( 1379143176),
                            INT32_C(-2075387410), INT32_C(-1152868472), INT32_C( 1425101887), INT32_C(-1626225579),
                            INT32_C( 2014677400), INT32_C( 1108777022), INT32_C(  877429697), INT32_C( 1558575022)),
      simde_mm512_set_epi32(INT32_C( 1822881045), INT32_C( -803993576), INT32_C(  163813867), INT32_C(-1017884831),
                            INT32_C(-1258992440), INT32_C( 1182354404), INT32_C(-1425047283), INT32_C( 1708628167),
                            INT32_C(-2051115159), INT32_C(  143410800), INT32_C(-1041180848), INT32_C(-1023702255),
                            INT32_C( -240255997), INT32_C(  978107452), INT32_C(-1343783755), INT32_C( -880122145)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 1342439424), INT32_C(          0), INT32_C( 1124091713),
                            INT32_C(          0), INT32_C( 1144586432), INT32_C(          0), INT32_C( 1075054592),
                            INT32_C(          0), INT32_C(          0), INT32_C( 1089491984), INT32_C(-2112782319),
                            INT32_C(          0), INT32_C(          0), INT32_C(  608436353), INT32_C(          0)) },
    { UINT16_C( 3728),
      simde_mm512_set_epi32(INT32_C( -632750822), INT32_C( 1966832804), INT32_C( 1231278072), INT32_C(  832865002),
                            INT32_C(-1694490420), INT32_C( -466764866), INT32_C( 1702721236), INT32_C( 2092439418),
                            INT32_C(  611933067), INT32_C(-1184445720), INT32_C(-1689922195), INT32_C(-1140532352),
                            INT32_C(  158346875), INT32_C( 1089717474), INT32_C( 1230253618), INT32_C( 1504968720)),
      simde_mm512_set_epi32(INT32_C(-1286938208), INT32_C(  537660993), INT32_C(-1605590998), INT32_C( 1810066171),
                            INT32_C(  -10167007), INT32_C( 1359569321), INT32_C(-1430119757), INT32_C(  256064867),
                            INT32_C(  788618356), INT32_C( -392789188), INT32_C( -613873031), INT32_C(  773158597),
                            INT32_C( -194106681), INT32_C(  165465349), INT32_C(-1346434037), INT32_C(-1412186885)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1694498816), INT32_C( 1074340264), INT32_C(  541069968), INT32_C(          0),
                            INT32_C(  604067840), INT32_C(          0), INT32_C(          0), INT32_C(  738480768),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { UINT16_C(56690),
      simde_mm512_set_epi32(INT32_C( -794660034), INT32_C(  173952757), INT32_C( 1507611872), INT32_C(-1888865381),
                            INT32_C(   15541452), INT32_C( -670396349), INT32_C(-1090081489), INT32_C(  116025329),
                            INT32_C(  130963716), INT32_C(  230354364), INT32_C( 1174065929), INT32_C( 1971493681),
                            INT32_C(-1343257591), INT32_C(-1419733408), INT32_C(  659096905), INT32_C(  183711411)),
      simde_mm512_set_epi32(INT32_C(  218373799), INT32_C( -362113249), INT32_C( -694086277), INT32_C( 1616282233),
                            INT32_C(-2132390836), INT32_C( -153917613), INT32_C(  736513734), INT32_C(-1311057544),
                            INT32_C(  505476811), INT32_C( 1767695145), INT32_C(  157469724), INT32_C( -371725260),
                            INT32_C( 1996701751), INT32_C(-1377678442), INT32_C( -132601652), INT32_C( -903948497)),
      simde_mm512_set_epi32(INT32_C(       4646), INT32_C(  172623381), INT32_C(          0), INT32_C(    4325913),
                            INT32_C(   14943308), INT32_C( -805175229), INT32_C(          0), INT32_C(   13255024),
                            INT32_C(          0), INT32_C(  152625448), INT32_C(   23248904), INT32_C( 1635944496),
                            INT32_C(          0), INT32_C(          0), INT32_C(  537395272), INT32_C(          0)) },
    { UINT16_C(54171),
      simde_mm512_set_epi32(INT32_C(  986405639), INT32_C( 1121234438), INT32_C( -731393712), INT32_C( -784753228),
                            INT32_C( -748350470), INT32_C( 1755197901), INT32_C( 1090059253), INT32_C( 1329426651),
                            INT32_C(-1604442789), INT32_C(  878047098), INT32_C(-1682276633), INT32_C(  -78811559),
                            INT32_C( -973139496), INT32_C(   91517188), INT32_C(   37440120), INT32_C(  829401648)),
      simde_mm512_set_epi32(INT32_C( 2057630636), INT32_C(  335188274), INT32_C( 1272591061), INT32_C( -327494197),
                            INT32_C(  892006932), INT32_C(-1158010747), INT32_C( -700127305), INT32_C(-1058033333),
                            INT32_C( 2135825335), INT32_C( -510043422), INT32_C( -139544800), INT32_C(   95748631),
                            INT32_C( 1671238992), INT32_C( 1305915968), INT32_C( -582790199), INT32_C( 1758236157)),
      simde_mm512_set_epi32(INT32_C(  981488388), INT32_C(   47218690), INT32_C(          0), INT32_C(-1070033536),
                            INT32_C(          0), INT32_C(          0), INT32_C( 1077994421), INT32_C( 1076703307),
                            INT32_C(  541982995), INT32_C(          0), INT32_C(          0), INT32_C(   17105425),
                            INT32_C( 1100812624), INT32_C(          0), INT32_C(     213576), INT32_C(  541886512)) },
    { UINT16_C( 6763),
      simde_mm512_set_epi32(INT32_C( -697747292), INT32_C(-1779695782), INT32_C(  491327584), INT32_C( -563681080),
                            INT32_C( 1527319596), INT32_C( 1347900829), INT32_C(-1792354715), INT32_C( -371177698),
                            INT32_C(  255088013), INT32_C( 1961231505), INT32_C( -659343095), INT32_C( 1620234692),
                            INT32_C(  843561067), INT32_C( 1265300992), INT32_C(-1675104490), INT32_C( -873664156)),
      simde_mm512_set_epi32(INT32_C( -822209230), INT32_C(-1549704264), INT32_C(-1157339218), INT32_C(-2025137124),
                            INT32_C(-1631723043), INT32_C(-2095740678), INT32_C(-1857753563), INT32_C(-1236342636),
                            INT32_C( 1439297909), INT32_C( -576201057), INT32_C( 1488873085), INT32_C(-1369304746),
                            INT32_C(  567848046), INT32_C( 1335236564), INT32_C( -942680632), INT32_C(-1512916560)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-2042443768),
                            INT32_C(  436797452), INT32_C(          0), INT32_C(-1862220251), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1420166289), INT32_C( 1488068617), INT32_C(          0),
                            INT32_C(  541108330), INT32_C(          0), INT32_C(-2079865600), INT32_C(-2118078176)) },
    { UINT16_C(17574),
      simde_mm512_set_epi32(INT32_C(-2098508971), INT32_C(  488824783), INT32_C( 1647236603), INT32_C(-1221154150),
                            INT32_C(-1012750616), INT32_C( 1849794587), INT32_C(  131205926), INT32_C( 2061955170),
                            INT32_C(   37003574), INT32_C( 1649229141), INT32_C(  612060260), INT32_C(-1402263233),
                            INT32_C( -513572270), INT32_C(  701923816), INT32_C(  511549547), INT32_C(  969083331)),
      simde_mm512_set_epi32(INT32_C( -873396634), INT32_C(-1835948135), INT32_C(-1570208244), INT32_C( -244400530),
                            INT32_C( 1126824505), INT32_C( 1036340167), INT32_C(  424825857), INT32_C(  434716327),
                            INT32_C( 1663095683), INT32_C( 1730428966), INT32_C( -252943126), INT32_C(  373990324),
                            INT32_C( 2100741912), INT32_C(-1005385937), INT32_C(-1470990839), INT32_C(-1200692008)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  268470153), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(  742457347), INT32_C(          0), INT32_C(          0),
                            INT32_C(   35684610), INT32_C(          0), INT32_C(  543704160), INT32_C(          0),
                            INT32_C(          0), INT32_C(    1179944), INT32_C(  139468809), INT32_C(          0)) },
    { UINT16_C( 5226),
      simde_mm512_set_epi32(INT32_C(  793357988), INT32_C(  607421194), INT32_C(-1375787856), INT32_C( 1799684145),
                            INT32_C( -551549754), INT32_C( 1249951615), INT32_C( 1447553529), INT32_C(-2080136983),
                            INT32_C( -623547588), INT32_C( 1015056564), INT32_C(-1333355305), INT32_C( 1925062912),
                            INT32_C(  330138155), INT32_C( -444195598), INT32_C(  874806560), INT32_C(  319126943)),
      simde_mm512_set_epi32(INT32_C( -542891463), INT32_C(  629803756), INT32_C(-1216921331), INT32_C( -301860714),
                            INT32_C(  317296385), INT32_C( 1833800187), INT32_C( -645353377), INT32_C(-1989715102),
                            INT32_C( 1785805415), INT32_C( 1739507553), INT32_C(-1932540399), INT32_C( -641363523),
                            INT32_C(   72499486), INT32_C(-2005610208), INT32_C( -497730582), INT32_C(  312611747)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( 1778450448),
                            INT32_C(          0), INT32_C( 1207996795), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(  612401184), INT32_C(-2138668015), INT32_C(          0),
                            INT32_C(         10), INT32_C(          0), INT32_C(  537147680), INT32_C(          0)) },
    { UINT16_C(43362),
      simde_mm512_set_epi32(INT32_C(-2123521230), INT32_C( -883174176), INT32_C( -332498316), INT32_C(  142889340),
                            INT32_C( 1231002435), INT32_C( 1681334055), INT32_C(  138372594), INT32_C( -878588971),
                            INT32_C(  423295425), INT32_C( -460615607), INT32_C( 1208771148), INT32_C(-2128303155),
                            INT32_C( -738338972), INT32_C( 2110676823), INT32_C(-1405320678), INT32_C(-2007459833)),
      simde_mm512_set_epi32(INT32_C( -941377596), INT32_C(-1151664921), INT32_C( -656770411), INT32_C(  861635987),
                            INT32_C( 1823839521), INT32_C( 1391000031), INT32_C(   73229946), INT32_C(  -53693878),
                            INT32_C( -257851255), INT32_C( -479522767), INT32_C(  745275629), INT32_C(-1783480446),
                            INT32_C(-1431666964), INT32_C( -422291816), INT32_C( -309252994), INT32_C(-2112946871)),
      simde_mm512_set_epi32(INT32_C(-2124307712), INT32_C(          0), INT32_C( -938837484), INT32_C(          0),
                            INT32_C( 1209372929), INT32_C(          0), INT32_C(          0), INT32_C( -931102144),
                            INT32_C(          0), INT32_C( -536145919), INT32_C(  135004236), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1408237542), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_and_epi32(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_and_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 9036212757557430666), INT64_C( 5704081348870821627),
                            INT64_C( 4916018483251427189), INT64_C( 5923374839641151982),
                            INT64_C(-4951532382404389825), INT64_C(-6984585675708986984),
                            INT64_C( 4762161048923702209), INT64_C( 6694028748503799090)),
      simde_mm512_set_epi64(INT64_C(-3453126114950276629), INT64_C(-4371782057203512120),
                            INT64_C( 5078173500331491597), INT64_C( 7338502100533278569),
                            INT64_C(  615944699146983248), INT64_C(-4396767702011741181),
                            INT64_C( 4200939521265073333), INT64_C(-3780095828076561881)),
      simde_mm512_set_epi64(INT64_C( 5765733423092074890), INT64_C( 4827937147730281672),
                            INT64_C( 4915961295754526981), INT64_C( 4617324316270006632),
                            INT64_C(  578719150276367376), INT64_C(-9074330961792628736),
                            INT64_C(  145408472056594561), INT64_C( 5224288327930368034)) },
    { simde_mm512_set_epi64(INT64_C( 5288299052354798314), INT64_C(-7277780933457101890),
                            INT64_C( 7313132024917137274), INT64_C( 2628232513216498408),
                            INT64_C(-7258160557155099776), INT64_C(  680094650638517474),
                            INT64_C( 5283899056600645648), INT64_C( 2807728906149754133)),
      simde_mm512_set_epi64(INT64_C(-6895960825351935237), INT64_C(  -43666961203633751),
                            INT64_C(-6142317585422402205), INT64_C( 3387090051947463484),
                            INT64_C(-2636564591268235579), INT64_C( -833681846664639227),
                            INT64_C(-5782890152253473541), INT64_C(-2717644085040284508)),
      simde_mm512_set_epi64(INT64_C(   18155308360663786), INT64_C(-7277816996756381272),
                            INT64_C( 2323877817609098594), INT64_C( 2594451620184359464),
                            INT64_C(-7259520672634482048), INT64_C(   27068065029080064),
                            INT64_C(  654161048765464592), INT64_C(  162142851124327428)) },
    { simde_mm512_set_epi64(INT64_C(-8112615037926038324), INT64_C(-2879330391107916497),
                            INT64_C(  498324993693604100), INT64_C(  989364461044945673),
                            INT64_C( 8467500887117366281), INT64_C(-6097708555739527863),
                            INT64_C(  789034506143718770), INT64_C(-5527357514795184575)),
      simde_mm512_set_epi64(INT64_C( 6941879334003428428), INT64_C( -661071113376870714),
                            INT64_C(-5630949274148604213), INT64_C( 7592192837230447644),
                            INT64_C(-1596547832800395209), INT64_C(-5917083848631867188),
                            INT64_C(-3882429228383046850), INT64_C(  747121403871646944)),
      simde_mm512_set_epi64(INT64_C(   18579654875284556), INT64_C(-3458201275382494202),
                            INT64_C(   56929894688378880), INT64_C(  655521307720597512),
                            INT64_C( 7026328109045710849), INT64_C(-6241986883974856632),
                            INT64_C(  725666832763081010), INT64_C(  165015392292176960)) },
    { simde_mm512_set_epi64(INT64_C(-3214140792841031219), INT64_C( 4681768843666616539),
                            INT64_C(-6891029306179981446), INT64_C(-7225323117343838631),
                            INT64_C(-4179602309674405628), INT64_C(  160804091787717168),
                            INT64_C( 3694873207195836071), INT64_C(-1555264558302423685)),
      simde_mm512_set_epi64(INT64_C( 3831140603882252421), INT64_C(-3007023874774683317),
                            INT64_C( 9173299967578168034), INT64_C( -599340352231112169),
                            INT64_C( 7177916815745921600), INT64_C(-2503064843376095747),
                            INT64_C( 4236579961216216582), INT64_C(-3141312070029828684)),
      simde_mm512_set_epi64(INT64_C( 1234006158509482117), INT64_C( 4629950784542158923),
                            INT64_C( 2327799239051135586), INT64_C(-7806367493009374703),
                            INT64_C( 4727954219193348096), INT64_C(     917302477097008),
                            INT64_C( 3621548322709573126), INT64_C(-4583941969312410320)) },
    { simde_mm512_set_epi64(INT64_C( 5789189981308900965), INT64_C(-1594196073659476595),
                            INT64_C( 8423425177495484681), INT64_C( 6958855014828193899),
                            INT64_C( 5434426382856220438), INT64_C(-3752358975457584533),
                            INT64_C( 8837456289202868530), INT64_C( 5465736992144414155)),
      simde_mm512_set_epi64(INT64_C(-9001137670469652955), INT64_C(-5310051186831134347),
                            INT64_C(-2474764694246758787), INT64_C(-5881119101759738770),
                            INT64_C( 5734797378155697608), INT64_C(-6497927143179601756),
                            INT64_C(-7643735180027817888), INT64_C(-2420991802446640084)),
      simde_mm512_set_epi64(INT64_C(    5911629778699813), INT64_C(-6899444174404169467),
                            INT64_C( 6099567767624753161), INT64_C( 2306424943463671914),
                            INT64_C( 5404906694268929280), INT64_C(-9097076494042654688),
                            INT64_C( 1198224716855775264), INT64_C( 5350875317483865096)) },
    { simde_mm512_set_epi64(INT64_C(  563525163273351266), INT64_C(  158929141814345045),
                            INT64_C( 2628778802773961023), INT64_C(-2205776103080558104),
                            INT64_C( 2197088575617698243), INT64_C( 5860665973320586546),
                            INT64_C(-6655929129214122066), INT64_C(-8697897714832252451)),
      simde_mm512_set_epi64(INT64_C( 1824613162744888999), INT64_C( 7142941570334212134),
                            INT64_C(-1086382453544016972), INT64_C( 9022617812666091311),
                            INT64_C(-6317857543126326056), INT64_C(-9013027400318787633),
                            INT64_C( 7074827341732948634), INT64_C(-4349730772874059749)),
      simde_mm512_set_epi64(INT64_C(   95138542545547298), INT64_C(  153264234564943876),
                            INT64_C( 2335191585971118388), INT64_C( 6999299776119439656),
                            INT64_C(  599013974410920128), INT64_C(   18366259613799682),
                            INT64_C( 2459037658077471370), INT64_C(-9006491134657978343)) },
    { simde_mm512_set_epi64(INT64_C(-8934120309513688260), INT64_C( 4359634748931742935),
                            INT64_C( 8268082250112664107), INT64_C(-1907805565562356448),
                            INT64_C( 1370639783932859498), INT64_C(-3751209977007462503),
                            INT64_C(-6743993051839021458), INT64_C( 4839674398342728647)),
      simde_mm512_set_epi64(INT64_C(-8545761289661498777), INT64_C( 7471128053642413585),
                            INT64_C(-2754635356059844322), INT64_C(-8614030248086520854),
                            INT64_C( 1342657230503784100), INT64_C( 2608854166046450864),
                            INT64_C( 7729584549648139462), INT64_C( 5368501309454936569)),
      simde_mm512_set_epi64(INT64_C(-9222527198360950236), INT64_C( 2630243059467977745),
                            INT64_C( 5801763319471669258), INT64_C(-9222228406785787616),
                            INT64_C( 1297055947226612768), INT64_C(   13513008652297360),
                            INT64_C( 2467972599307568198), INT64_C( 4756005960819231169)) },
    { simde_mm512_set_epi64(INT64_C( 1818040010755772489), INT64_C( 5191632551175039949),
                            INT64_C(-3171141735991582889), INT64_C(-6035806350115039225),
                            INT64_C( 4482393771264451129), INT64_C( 2704986537996009741),
                            INT64_C(-1296481894259912959), INT64_C( 7876111834213298271)),
      simde_mm512_set_epi64(INT64_C(-1107462703642111951), INT64_C( 3200934455572316034),
                            INT64_C(-6148962785270933864), INT64_C(-1328231493238063799),
                            INT64_C(-9120454231799900960), INT64_C(-1428069393052184196),
                            INT64_C( 5287115201302699815), INT64_C(  594305769309064149)),
      simde_mm512_set_epi64(INT64_C( 1162069999159545857), INT64_C(  579838780607835008),
                            INT64_C(-9031874063504222704), INT64_C(-6048334185741379583),
                            INT64_C(   10310269968318496), INT64_C( 2596899559745798412),
                            INT64_C( 5188595380067045121), INT64_C(  580122069275017301)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_and_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_and_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 9036212757557430666), INT64_C( 5704081348870821627),
                            INT64_C( 4916018483251427189), INT64_C( 5923374839641151982),
                            INT64_C(-4951532382404389825), INT64_C(-6984585675708986984),
                            INT64_C( 4762161048923702209), INT64_C( 6694028748503799090)),
      UINT8_C( 39),
      simde_mm512_set_epi64(INT64_C( 7829214476264278040), INT64_C(  703575204673376097),
                            INT64_C(-5407331354528887836), INT64_C(-6120531474030028601),
                            INT64_C(-8809472528091429264), INT64_C(-4471837688110281967),
                            INT64_C(-1031891648804766660), INT64_C(-5771507277206231329)),
      simde_mm512_set_epi64(INT64_C( 8447482571111256056), INT64_C( 3577127948173451468),
                            INT64_C(-2004739832689101100), INT64_C( 8986958869783206795),
                            INT64_C(-5087155628682128019), INT64_C(-4898549151711613317),
                            INT64_C( 4680300913939983922), INT64_C( 6463791434556706448)),
      simde_mm512_set_epi64(INT64_C( 9036212757557430666), INT64_C( 5704081348870821627),
                            INT64_C(-6618874695993703740), INT64_C( 5923374839641151982),
                            INT64_C(-4951532382404389825), INT64_C(-9223140039893972463),
                            INT64_C( 4657219002685467696), INT64_C(  694680311283451536)) },
    { simde_mm512_set_epi64(INT64_C( 2309236383959261226), INT64_C( 7774175012325743905),
                            INT64_C( 5839305773204773555), INT64_C( 1099790230208207988),
                            INT64_C(-1687016713001301383), INT64_C( 3320690892837104327),
                            INT64_C(  710668265524759563), INT64_C(-6065296483252896486)),
      UINT8_C(160),
      simde_mm512_set_epi64(INT64_C(  747121403871646944), INT64_C(-8112615037926038324),
                            INT64_C(-2879330391107916497), INT64_C(  498324993693604100),
                            INT64_C(  989364461044945673), INT64_C( 8467500887117366281),
                            INT64_C(-6097708555739527863), INT64_C(  789034506143718770)),
      simde_mm512_set_epi64(INT64_C(-1555264558302423685), INT64_C( 6941879334003428428),
                            INT64_C( -661071113376870714), INT64_C(-5630949274148604213),
                            INT64_C( 7592192837230447644), INT64_C(-1596547832800395209),
                            INT64_C(-5917083848631867188), INT64_C(-3882429228383046850)),
      simde_mm512_set_epi64(INT64_C(  741411777270518880), INT64_C( 7774175012325743905),
                            INT64_C(-3458201275382494202), INT64_C( 1099790230208207988),
                            INT64_C(-1687016713001301383), INT64_C( 3320690892837104327),
                            INT64_C(  710668265524759563), INT64_C(-6065296483252896486)) },
    { simde_mm512_set_epi64(INT64_C(-3141312070029828684), INT64_C(-3214140792841031219),
                            INT64_C( 4681768843666616539), INT64_C(-6891029306179981446),
                            INT64_C(-7225323117343838631), INT64_C(-4179602309674405628),
                            INT64_C(  160804091787717168), INT64_C( 3694873207195836071)),
      UINT8_C(  6),
      simde_mm512_set_epi64(INT64_C( 1439622676105278165), INT64_C(-1406576864852774380),
                            INT64_C(-4973618283186690121), INT64_C(-4544218561177052233),
                            INT64_C(-2190619812874504416), INT64_C(  411237240453010768),
                            INT64_C( 5608866377596359625), INT64_C( 7551566793946127111)),
      simde_mm512_set_epi64(INT64_C( 2110235908633979080), INT64_C( 6559787716707833245),
                            INT64_C(-7698104879832611042), INT64_C( 1095594675397854353),
                            INT64_C(-2831857028248186428), INT64_C( 3623067196209165824),
                            INT64_C(-7194518998511455900), INT64_C(-8783679074311277652)),
      simde_mm512_set_epi64(INT64_C(-3141312070029828684), INT64_C(-3214140792841031219),
                            INT64_C( 4681768843666616539), INT64_C(-6891029306179981446),
                            INT64_C(-7225323117343838631), INT64_C(    1407388893058048),
                            INT64_C(  866558102575534400), INT64_C( 3694873207195836071)) },
    { simde_mm512_set_epi64(INT64_C(-4970734089418384356), INT64_C(-7008197103615375110),
                            INT64_C(-7978990794053850988), INT64_C( 6181737452074950303),
                            INT64_C( 6394661210895290710), INT64_C( 2438888788002740180),
                            INT64_C(-4048782482230560336), INT64_C(-2996801797497290918)),
      UINT8_C(184),
      simde_mm512_set_epi64(INT64_C( 7074827341732948634), INT64_C(-4349730772874059749),
                            INT64_C(  563525163273351266), INT64_C(  158929141814345045),
                            INT64_C( 2628778802773961023), INT64_C(-2205776103080558104),
                            INT64_C( 2197088575617698243), INT64_C( 5860665973320586546)),
      simde_mm512_set_epi64(INT64_C(-6743993051839021458), INT64_C( 4839674398342728647),
                            INT64_C( 1824613162744888999), INT64_C( 7142941570334212134),
                            INT64_C(-1086382453544016972), INT64_C( 9022617812666091311),
                            INT64_C(-6317857543126326056), INT64_C(-9013027400318787633)),
      simde_mm512_set_epi64(INT64_C( 2461362369224681994), INT64_C(-7008197103615375110),
                            INT64_C(   95138542545547298), INT64_C(  153264234564943876),
                            INT64_C( 2335191585971118388), INT64_C( 2438888788002740180),
                            INT64_C(-4048782482230560336), INT64_C(-2996801797497290918)) },
    { simde_mm512_set_epi64(INT64_C( 7729584549648139462), INT64_C( 5368501309454936569),
                            INT64_C(-8934120309513688260), INT64_C( 4359634748931742935),
                            INT64_C( 8268082250112664107), INT64_C(-1907805565562356448),
                            INT64_C( 1370639783932859498), INT64_C(-3751209977007462503)),
      UINT8_C(176),
      simde_mm512_set_epi64(INT64_C(-5226637314456684394), INT64_C( 1362777598547825147),
                            INT64_C(-2771771646272906398), INT64_C( 7669975856184215393),
                            INT64_C(-8300197808250187331), INT64_C(  311382923636166944),
                            INT64_C(-2137736571596434525), INT64_C( 3407446613087781642)),
      simde_mm512_set_epi64(INT64_C(  613705043478027075), INT64_C( 7221274780014437874),
                            INT64_C(-3773510896647996991), INT64_C(-1978328966883417524),
                            INT64_C(-9140992443141990556), INT64_C( 9065287930099827226),
                            INT64_C(-8621974329724982942), INT64_C(-2331701078232790292)),
      simde_mm512_set_epi64(INT64_C(    1197420910319618), INT64_C( 5368501309454936569),
                            INT64_C(-3926997772353251008), INT64_C( 6917828375051256384),
                            INT64_C( 8268082250112664107), INT64_C(-1907805565562356448),
                            INT64_C( 1370639783932859498), INT64_C(-3751209977007462503)) },
    { simde_mm512_set_epi64(INT64_C( 3700698387045520673), INT64_C( 5974299641953216122),
                            INT64_C( -230613445968297847), INT64_C(-2059534601207152403),
                            INT64_C(-7659990185762193684), INT64_C(-1813729535102735234),
                            INT64_C(-9075037706959084750), INT64_C(-3793204198629279116)),
      UINT8_C(149),
      simde_mm512_set_epi64(INT64_C(-1763977094002909713), INT64_C(-2903140489693440283),
                            INT64_C( 6916354853087283405), INT64_C( -288829486582280686),
                            INT64_C( 3770029145011694022), INT64_C( 4745990232274262704),
                            INT64_C(-9178901749894611532), INT64_C(-4043185984863798041)),
      simde_mm512_set_epi64(INT64_C(-2601025793624159885), INT64_C( 3563840185149175707),
                            INT64_C( -266768530495040309), INT64_C( 3956680363155515245),
                            INT64_C(-3793861402632321428), INT64_C(-9102379300509684954),
                            INT64_C(-8107510778505593825), INT64_C( 3515623724266758070)),
      simde_mm512_set_epi64(INT64_C(-4358068267243845277), INT64_C( 5974299641953216122),
                            INT64_C( -230613445968297847), INT64_C( 3668413965043549696),
                            INT64_C(-7659990185762193684), INT64_C(  111745843014421024),
                            INT64_C(-9075037706959084750), INT64_C(   54607264595188902)) },
    { simde_mm512_set_epi64(INT64_C( 6254124818226667045), INT64_C( 2295645667912807702),
                            INT64_C(-4018707571999816637), INT64_C(  -26221181248372278),
                            INT64_C(-1805361387364896744), INT64_C(-3741154382847501293),
                            INT64_C( 2395841610067775712), INT64_C( 4058242405589980421)),
      UINT8_C( 95),
      simde_mm512_set_epi64(INT64_C( 8131676417901457360), INT64_C( 5114845102355343256),
                            INT64_C(-4438171947452810779), INT64_C(-7935157497162192255),
                            INT64_C(  113046603373071999), INT64_C( 5604608652266856031),
                            INT64_C(-6729023456945537362), INT64_C(-3975720697196785172)),
      simde_mm512_set_epi64(INT64_C( 4986045839810005585), INT64_C(  594372055586112482),
                            INT64_C( 4543836970229042581), INT64_C(-3911934107467365366),
                            INT64_C(-4070664534473188278), INT64_C( 5469443597420811446),
                            INT64_C(-7904155369341108539), INT64_C(-3737549779697651723)),
      simde_mm512_set_epi64(INT64_C( 6254124818226667045), INT64_C(   16747779451847552),
                            INT64_C(-4018707571999816637), INT64_C(-9106278428011921408),
                            INT64_C(  108112814837713994), INT64_C( 5316237509498262550),
                            INT64_C(-9075733389403931004), INT64_C(-4034937163739561500)) },
    { simde_mm512_set_epi64(INT64_C(-4532025999716330471), INT64_C( 1441736923413036901),
                            INT64_C( 4055551302629479412), INT64_C(  212827843943377228),
                            INT64_C(-8849072478755780357), INT64_C(-1422057783446117205),
                            INT64_C(-7199062965036293603), INT64_C(  733947372098454344)),
      UINT8_C( 32),
      simde_mm512_set_epi64(INT64_C(-6215126846548299491), INT64_C(-2916974460339411728),
                            INT64_C( 7873834362860447881), INT64_C( 8398781451642376253),
                            INT64_C( 4819162425848909387), INT64_C( 3108138717093232544),
                            INT64_C(-1968231203112162098), INT64_C(-5881820928188872186)),
      simde_mm512_set_epi64(INT64_C(-5650512314146637209), INT64_C(    3824130547717357),
                            INT64_C( 8692530928452313027), INT64_C(    8285423730243427),
                            INT64_C( 3742589136248759843), INT64_C( 2734033046067673576),
                            INT64_C( 3884903702312804919), INT64_C(-1276802171409363646)),
      simde_mm512_set_epi64(INT64_C(-4532025999716330471), INT64_C( 1441736923413036901),
                            INT64_C( 7494010129634756737), INT64_C(  212827843943377228),
                            INT64_C(-8849072478755780357), INT64_C(-1422057783446117205),
                            INT64_C(-7199062965036293603), INT64_C(  733947372098454344)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_and_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_and_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { UINT8_C( 50),
      simde_mm512_set_epi64(INT64_C( 5084416814350799776), INT64_C(-8570269232503654461),
                            INT64_C(-1630207427926739773), INT64_C(-6092042681407238648),
                            INT64_C(-8913721049338044536), INT64_C( 6120766000801629269),
                            INT64_C( 8652973546099087422), INT64_C( 3768531854712764334)),
      simde_mm512_set_epi64(INT64_C( 7829214476264278040), INT64_C(  703575204673376097),
                            INT64_C(-5407331354528887836), INT64_C(-6120531474030028601),
                            INT64_C(-8809472528091429264), INT64_C(-4471837688110281967),
                            INT64_C(-1031891648804766660), INT64_C(-5771507277206231329)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-6890431802948124480), INT64_C(-6123627733767157760),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 8072007440746715196), INT64_C(                   0)) },
    { UINT8_C(144),
      simde_mm512_set_epi64(INT64_C(-2717644085040284508), INT64_C( 5288299052354798314),
                            INT64_C(-7277780933457101890), INT64_C( 7313132024917137274),
                            INT64_C( 2628232513216498408), INT64_C(-7258160557155099776),
                            INT64_C(  680094650638517474), INT64_C( 5283899056600645648)),
      simde_mm512_set_epi64(INT64_C(-5527357514795184575), INT64_C(-6895960825351935237),
                            INT64_C(  -43666961203633751), INT64_C(-6142317585422402205),
                            INT64_C( 3387090051947463484), INT64_C(-2636564591268235579),
                            INT64_C( -833681846664639227), INT64_C(-5782890152253473541)),
      simde_mm512_set_epi64(INT64_C(-7905821755195257856), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 2323877817609098594),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C(114),
      simde_mm512_set_epi64(INT64_C(-3413038857294295307), INT64_C( 6475143687707440027),
                            INT64_C(   66750031696924739), INT64_C(-4681864345113958415),
                            INT64_C(  562484877412986300), INT64_C( 5042574770374351665),
                            INT64_C(-5769247420573510048), INT64_C( 2830799652053530291)),
      simde_mm512_set_epi64(INT64_C(  937908328941131551), INT64_C(-2981077858701114759),
                            INT64_C(-9158548898769049773), INT64_C( 3163302403568753016),
                            INT64_C( 2171006373899068201), INT64_C(  676327318613388340),
                            INT64_C( 8575768723328224150), INT64_C( -569519755344554193)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C( 5800658722606940697),
                            INT64_C(   64181022643847235), INT64_C( 3100178613413757296),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 2811090599545930240), INT64_C(                   0)) },
    { UINT8_C(155),
      simde_mm512_set_epi64(INT64_C( 4236579961216216582), INT64_C(-3141312070029828684),
                            INT64_C(-3214140792841031219), INT64_C( 4681768843666616539),
                            INT64_C(-6891029306179981446), INT64_C(-7225323117343838631),
                            INT64_C(-4179602309674405628), INT64_C(  160804091787717168)),
      simde_mm512_set_epi64(INT64_C( 8837456289202868530), INT64_C( 5465736992144414155),
                            INT64_C( 3831140603882252421), INT64_C(-3007023874774683317),
                            INT64_C( 9173299967578168034), INT64_C( -599340352231112169),
                            INT64_C( 7177916815745921600), INT64_C(-2503064843376095747)),
      simde_mm512_set_epi64(INT64_C( 4215460527910977538), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 4629950784542158923),
                            INT64_C( 2327799239051135586), INT64_C(                   0),
                            INT64_C( 4727954219193348096), INT64_C(     917302477097008)) },
    { UINT8_C(107),
      simde_mm512_set_epi64(INT64_C(-2996801797497290918), INT64_C( 2110235908633979080),
                            INT64_C( 6559787716707833245), INT64_C(-7698104879832611042),
                            INT64_C( 1095594675397854353), INT64_C(-2831857028248186428),
                            INT64_C( 3623067196209165824), INT64_C(-7194518998511455900)),
      simde_mm512_set_epi64(INT64_C(-3531361750574079048), INT64_C(-4970734089418384356),
                            INT64_C(-7008197103615375110), INT64_C(-7978990794053850988),
                            INT64_C( 6181737452074950303), INT64_C( 6394661210895290710),
                            INT64_C( 2438888788002740180), INT64_C(-4048782482230560336)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C( 1801439990639675400),
                            INT64_C( 1876030771317506200), INT64_C(                   0),
                            INT64_C(  360377053526492305), INT64_C(                   0),
                            INT64_C( 2324042582201603584), INT64_C(-8932954729898528480)) },
    { UINT8_C(166),
      simde_mm512_set_epi64(INT64_C(-9013027400318787633), INT64_C( 7074827341732948634),
                            INT64_C(-4349730772874059749), INT64_C(  563525163273351266),
                            INT64_C(  158929141814345045), INT64_C( 2628778802773961023),
                            INT64_C(-2205776103080558104), INT64_C( 2197088575617698243)),
      simde_mm512_set_epi64(INT64_C(-3751209977007462503), INT64_C(-6743993051839021458),
                            INT64_C( 4839674398342728647), INT64_C( 1824613162744888999),
                            INT64_C( 7142941570334212134), INT64_C(-1086382453544016972),
                            INT64_C( 9022617812666091311), INT64_C(-6317857543126326056)),
      simde_mm512_set_epi64(INT64_C(-9015922487669520503), INT64_C(                   0),
                            INT64_C( 4837044293220761603), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 2335191585971118388),
                            INT64_C( 6999299776119439656), INT64_C(                   0)) },
    { UINT8_C(106),
      simde_mm512_set_epi64(INT64_C( 3407446613087781642), INT64_C(-5908963845954273231),
                            INT64_C(-2368888154296893569), INT64_C( 6217195068479217897),
                            INT64_C(-2678116496944625484), INT64_C(-5726717426998042368),
                            INT64_C( 1417932582737550578), INT64_C( 3757265565845388703)),
      simde_mm512_set_epi64(INT64_C(-2331701078232790292), INT64_C(-5226637314456684394),
                            INT64_C( 1362777598547825147), INT64_C(-2771771646272906398),
                            INT64_C( 7669975856184215393), INT64_C(-8300197808250187331),
                            INT64_C(  311382923636166944), INT64_C(-2137736571596434525)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(-6523745533444423664),
                            INT64_C( 1306048291191951739), INT64_C(                   0),
                            INT64_C( 5355107766639820832), INT64_C(                   0),
                            INT64_C(         45097422880), INT64_C(                   0)) },
    { UINT8_C( 98),
      simde_mm512_set_epi64(INT64_C(-9120454231799900960), INT64_C(-1428069393052184196),
                            INT64_C( 5287115201302699815), INT64_C(  594305769309064149),
                            INT64_C( 1818040010755772489), INT64_C( 5191632551175039949),
                            INT64_C(-3171141735991582889), INT64_C(-6035806350115039225)),
      simde_mm512_set_epi64(INT64_C(-4043185984863798041), INT64_C(-2820807435363842669),
                            INT64_C( 7833331097238305247), INT64_C(  314520227399119434),
                            INT64_C(-1107462703642111951), INT64_C( 3200934455572316034),
                            INT64_C(-6148962785270933864), INT64_C(-1328231493238063799)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(-4032276290038922992),
                            INT64_C( 5194217179798575367), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-9031874063504222704), INT64_C(                   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_and_epi64(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_and_si512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 1762603276), INT32_C(-1316946536), INT32_C( -409636803), INT32_C(-1096492450),
                            INT32_C( 1487241173), INT32_C(-1940071138), INT32_C( 1116126146), INT32_C( -916337722),
                            INT32_C(   52488417), INT32_C( 1044081507), INT32_C(-1035184013), INT32_C(-1384518181),
                            INT32_C(-1687535487), INT32_C(-1003450758), INT32_C(  131212491), INT32_C(-1389162000)),
      simde_mm512_set_epi32(INT32_C(-1226890085), INT32_C(  294090078), INT32_C( 1993383303), INT32_C( 2117895966),
                            INT32_C( -579088274), INT32_C( 1336927221), INT32_C(   43647960), INT32_C( 1458493074),
                            INT32_C( -558283956), INT32_C(  428402022), INT32_C(  974860288), INT32_C( -624769004),
                            INT32_C(-1594949458), INT32_C(  -55819000), INT32_C(  423209449), INT32_C( -449605661)),
      simde_mm512_set_epi32(INT32_C(  537862152), INT32_C(  293631256), INT32_C( 1720717317), INT32_C( 1042579998),
                            INT32_C( 1478578244), INT32_C(  202162452), INT32_C(   42075072), INT32_C( 1080083074),
                            INT32_C(   35668032), INT32_C(  403202402), INT32_C(   34082816), INT32_C(-2009020400),
                            INT32_C(-2140536704), INT32_C(-1004534776), INT32_C(   17834185), INT32_C(-1523383840)) },
    { simde_mm512_set_epi32(INT32_C(-1226448376), INT32_C( 1927095485), INT32_C( 1303264402), INT32_C(  926300607),
                            INT32_C( 2116494628), INT32_C(-1100758331), INT32_C(  853434891), INT32_C( 1856581548),
                            INT32_C( 1730450085), INT32_C(-1233336711), INT32_C(  410802607), INT32_C(-1458345357),
                            INT32_C(-1414257532), INT32_C(-1908909941), INT32_C(  216004947), INT32_C(-1153616267)),
      simde_mm512_set_epi32(INT32_C(-1170743204), INT32_C( 1817377482), INT32_C(  934231558), INT32_C( -128119768),
                            INT32_C(  674694491), INT32_C( 1902405145), INT32_C(-1438313883), INT32_C( -508947384),
                            INT32_C( -334819615), INT32_C(-1499616800), INT32_C( -300643115), INT32_C(-1687918613),
                            INT32_C(  204696129), INT32_C( -790552335), INT32_C( -837803722), INT32_C(-1569322126)),
      simde_mm512_set_epi32(INT32_C(-1306140664), INT32_C( 1615863944), INT32_C(   95304706), INT32_C(  806619176),
                            INT32_C(  673645824), INT32_C(  811614721), INT32_C(  574882305), INT32_C( 1621623816),
                            INT32_C( 1677722273), INT32_C(-1508081568), INT32_C(  135530629), INT32_C(-1996463517),
                            INT32_C(  137371648), INT32_C(-2145386367), INT32_C(  202383634), INT32_C(-1573649808)) },
    { simde_mm512_set_epi32(INT32_C( -967914791), INT32_C( 1028004547), INT32_C( 1106145634), INT32_C(-2126623640),
                            INT32_C(   -6485699), INT32_C( -256904631), INT32_C(-1220204919), INT32_C(  917835787),
                            INT32_C( 1623427491), INT32_C( -222464855), INT32_C( -472879958), INT32_C( -762982604),
                            INT32_C(-1085405824), INT32_C( 1812599478), INT32_C( -613988136), INT32_C(  621554720)),
      simde_mm512_set_epi32(INT32_C( 1377438428), INT32_C( 1201451322), INT32_C(  619734582), INT32_C(-1992526637),
                            INT32_C( -868585296), INT32_C( 1439924174), INT32_C( 1656419868), INT32_C(-1390170089),
                            INT32_C( 1058692615), INT32_C( -836785520), INT32_C(-1830636694), INT32_C(  554982917),
                            INT32_C(-1514534388), INT32_C( -747673601), INT32_C( -692811287), INT32_C(-1799571639)),
      simde_mm512_set_epi32(INT32_C( 1107954392), INT32_C(   84152322), INT32_C(   14704674), INT32_C(-2126756800),
                            INT32_C( -870842320), INT32_C( 1350791752), INT32_C(  570435080), INT32_C(  606146563),
                            INT32_C(  537004035), INT32_C(-1038278528), INT32_C(-2101338070), INT32_C(     282116),
                            INT32_C(-1526071296), INT32_C( 1074397878), INT32_C( -769390392), INT32_C(   67904512)) },
    { simde_mm512_set_epi32(INT32_C(-1436950998), INT32_C(-1742059387), INT32_C( 1377677769), INT32_C(-2097193192),
                            INT32_C( 1556973207), INT32_C(   58040738), INT32_C(-1875805492), INT32_C( -452882923),
                            INT32_C(-2070651162), INT32_C(-1417594324), INT32_C( -990171302), INT32_C(  444234765),
                            INT32_C( -651701039), INT32_C( -296257488), INT32_C( 1302666953), INT32_C( 1243668562)),
      simde_mm512_set_epi32(INT32_C( -228023402), INT32_C( 1737651280), INT32_C(  890037909), INT32_C(  822465192),
                            INT32_C( 1525557148), INT32_C( 1672658803), INT32_C( 1808682106), INT32_C( 1316739447),
                            INT32_C(  903813947), INT32_C(  221590740), INT32_C( 1668581990), INT32_C(-1092503304),
                            INT32_C( 1369460064), INT32_C( 1353181098), INT32_C(  652356799), INT32_C( -684439573)),
      simde_mm512_set_epi32(INT32_C(-1572306430), INT32_C(     147456), INT32_C(  269262977), INT32_C(     348680),
                            INT32_C( 1489766036), INT32_C(   53518626), INT32_C(      18504), INT32_C( 1140951061),
                            INT32_C(   76814882), INT32_C(  151072772), INT32_C( 1081084482), INT32_C(  442513416),
                            INT32_C( 1361069120), INT32_C( 1074225184), INT32_C(   77597833), INT32_C( 1109409858)) },
    { simde_mm512_set_epi32(INT32_C(-1043054173), INT32_C( -396216896), INT32_C(-1145802326), INT32_C( -804000246),
                            INT32_C( -145399860), INT32_C( -890427310), INT32_C( -401401997), INT32_C(  802016776),
                            INT32_C( 1929893502), INT32_C(   73827769), INT32_C(-1971097644), INT32_C(-1831682098),
                            INT32_C(  546355465), INT32_C( -199725455), INT32_C(  931867413), INT32_C(-1496909535)),
      simde_mm512_set_epi32(INT32_C(-1796636811), INT32_C(-1576316556), INT32_C( 1080356179), INT32_C(-1830141457),
                            INT32_C(-1444813077), INT32_C( 1282909316), INT32_C(  814589845), INT32_C(  563073613),
                            INT32_C( -161574330), INT32_C( 1115054069), INT32_C(-1922096352), INT32_C( 1283172543),
                            INT32_C( 1028016376), INT32_C( 1652445236), INT32_C( 1602581177), INT32_C(-1986713581)),
      simde_mm512_set_epi32(INT32_C(-2134884063), INT32_C(-1610477248), INT32_C(    2384130), INT32_C(-1878900726),
                            INT32_C(-1589557560), INT32_C( 1214586880), INT32_C(  536938257), INT32_C(  562938376),
                            INT32_C( 1913033286), INT32_C(    6686129), INT32_C(-2013060352), INT32_C(    5417102),
                            INT32_C(  536872968), INT32_C( 1612202032), INT32_C(  394338833), INT32_C(-2138822655)) },
    { simde_mm512_set_epi32(INT32_C(  213329535), INT32_C( -522060385), INT32_C( -710729699), INT32_C(  911515198),
                            INT32_C(-1475915599), INT32_C(-1846311235), INT32_C(-1624654725), INT32_C( -496488954),
                            INT32_C(-2105881976), INT32_C( -863113580), INT32_C( -870973395), INT32_C(-2135017149),
                            INT32_C( 1179500895), INT32_C(  102238134), INT32_C( 1890546920), INT32_C( 1651955955)),
      simde_mm512_set_epi32(INT32_C(-1460720620), INT32_C(-1283988079), INT32_C( 2139823103), INT32_C(-2058406982),
                            INT32_C( -677653135), INT32_C(  526832430), INT32_C(  918576849), INT32_C(-1987609349),
                            INT32_C( -819905099), INT32_C( 2043707434), INT32_C( 1005516756), INT32_C(  646673888),
                            INT32_C( -792085599), INT32_C(  923333390), INT32_C(  549762390), INT32_C( 1063027034)),
      simde_mm512_set_epi32(INT32_C(  145171476), INT32_C(-1604196975), INT32_C( 1434648605), INT32_C(   71569978),
                            INT32_C(-2147266511), INT32_C(  291668524), INT32_C(  369106001), INT32_C(-2147472382),
                            INT32_C(-2111829888), INT32_C( 1216380928), INT32_C(  134610948), INT32_C(    9056576),
                            INT32_C( 1078558977), INT32_C(  101188358), INT32_C(  545535040), INT32_C(  575963218)) },
    { simde_mm512_set_epi32(INT32_C(-1614227898), INT32_C(-1072924213), INT32_C(-2048516742), INT32_C(-1735505047),
                            INT32_C(  409846045), INT32_C( -501166301), INT32_C(  385735082), INT32_C(-1379445210),
                            INT32_C( 1301699864), INT32_C( -237316746), INT32_C( -173549926), INT32_C(-1638681430),
                            INT32_C( 1204990643), INT32_C( -623938106), INT32_C(  621663116), INT32_C(-2139715294)),
      simde_mm512_set_epi32(INT32_C( 1168648208), INT32_C(  679514223), INT32_C(-1255159953), INT32_C(-2016174737),
                            INT32_C( -817087094), INT32_C( 1605116212), INT32_C(  684814447), INT32_C( 1274003485),
                            INT32_C( 1881744290), INT32_C(  579021373), INT32_C( -658206082), INT32_C( 1152351107),
                            INT32_C( -539739024), INT32_C( 1438387923), INT32_C( -569943597), INT32_C(  -79238784)),
      simde_mm512_set_epi32(INT32_C(   92798976), INT32_C(       4171), INT32_C(-2061105814), INT32_C(-2138961559),
                            INT32_C(  139198728), INT32_C( 1109393696), INT32_C(   13717546), INT32_C(  164052996),
                            INT32_C( 1073742080), INT32_C(  545390644), INT32_C( -796618214), INT32_C(   67317890),
                            INT32_C( 1204826160), INT32_C( 1351353538), INT32_C(   67457408), INT32_C(-2142861056)) },
    { simde_mm512_set_epi32(INT32_C( -593800358), INT32_C( -124181915), INT32_C( 2110561848), INT32_C( 1255401496),
                            INT32_C( -282522813), INT32_C( -286538666), INT32_C(-2011412362), INT32_C(-1839527164),
                            INT32_C(-1330408299), INT32_C( 1769934774), INT32_C( -358481155), INT32_C( -123958768),
                            INT32_C( 1676106379), INT32_C(-1305862521), INT32_C( 1797940107), INT32_C(  653525737)),
      simde_mm512_set_epi32(INT32_C(-1432835313), INT32_C( 1661538833), INT32_C( 1372337273), INT32_C(-1604084834),
                            INT32_C( -921184393), INT32_C(-1395990480), INT32_C( 1258870002), INT32_C( -947895097),
                            INT32_C(-1351881935), INT32_C(   99634026), INT32_C( 2033361976), INT32_C( 1231716550),
                            INT32_C( -228173591), INT32_C(-1552770129), INT32_C( -338049103), INT32_C(-1393391283)),
      simde_mm512_set_epi32(INT32_C(-2003303670), INT32_C( 1611203073), INT32_C( 1372329016), INT32_C(    4425752),
                            INT32_C( -922680509), INT32_C(-1395998704), INT32_C(  134758514), INT32_C(-2113929212),
                            INT32_C(-1608286191), INT32_C(   24120098), INT32_C( 1747058744), INT32_C( 1208516608),
                            INT32_C( 1650874505), INT32_C(-1574823289), INT32_C( 1795703681), INT32_C(  619708489)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_and_si512(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_and_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_and_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_and_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_and_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_and_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_and_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_and_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_and_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_and_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_and_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_and_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_and_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_and_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_and_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_and_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_and_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_and_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_and_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_and_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_and_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_and_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_and_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_and_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_and_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_and_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_and_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_and_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_and_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_and_si512)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
