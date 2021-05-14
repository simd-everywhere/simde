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
 *   2020      kitegi <kitegi@users.noreply.github.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN fmsub

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/fmsub.h>

static int
test_simde_mm256_mask3_fmsub_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 c[4];
    const simde__mmask8 k;
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -954.42), SIMDE_FLOAT64_C(  -453.32), SIMDE_FLOAT64_C(  -202.19), SIMDE_FLOAT64_C(  -856.55) },
      { SIMDE_FLOAT64_C(   617.91), SIMDE_FLOAT64_C(   844.52), SIMDE_FLOAT64_C(  -195.80), SIMDE_FLOAT64_C(   367.41) },
      { SIMDE_FLOAT64_C(   809.85), SIMDE_FLOAT64_C(  -324.84), SIMDE_FLOAT64_C(   457.53), SIMDE_FLOAT64_C(   131.49) },
      UINT8_C( 88),
      { SIMDE_FLOAT64_C(   809.85), SIMDE_FLOAT64_C(  -324.84), SIMDE_FLOAT64_C(   457.53), SIMDE_FLOAT64_C(-314836.53) } },
    { { SIMDE_FLOAT64_C(   836.65), SIMDE_FLOAT64_C(   763.53), SIMDE_FLOAT64_C(   194.01), SIMDE_FLOAT64_C(   -41.39) },
      { SIMDE_FLOAT64_C(  -329.34), SIMDE_FLOAT64_C(   298.74), SIMDE_FLOAT64_C(  -519.73), SIMDE_FLOAT64_C(  -460.87) },
      { SIMDE_FLOAT64_C(   478.28), SIMDE_FLOAT64_C(   152.02), SIMDE_FLOAT64_C(   235.10), SIMDE_FLOAT64_C(   904.68) },
      UINT8_C(107),
      { SIMDE_FLOAT64_C(-276020.59), SIMDE_FLOAT64_C(227944.93), SIMDE_FLOAT64_C(   235.10), SIMDE_FLOAT64_C( 18170.73) } },
    { { SIMDE_FLOAT64_C(   -36.65), SIMDE_FLOAT64_C(   588.02), SIMDE_FLOAT64_C(   822.54), SIMDE_FLOAT64_C(   882.45) },
      { SIMDE_FLOAT64_C(   159.85), SIMDE_FLOAT64_C(   868.13), SIMDE_FLOAT64_C(  -570.87), SIMDE_FLOAT64_C(   957.66) },
      { SIMDE_FLOAT64_C(  -988.43), SIMDE_FLOAT64_C(  -952.96), SIMDE_FLOAT64_C(   802.18), SIMDE_FLOAT64_C(  -184.23) },
      UINT8_C(218),
      { SIMDE_FLOAT64_C(  -988.43), SIMDE_FLOAT64_C(511430.76), SIMDE_FLOAT64_C(   802.18), SIMDE_FLOAT64_C(845271.30) } },
    { { SIMDE_FLOAT64_C(   612.03), SIMDE_FLOAT64_C(   490.93), SIMDE_FLOAT64_C(  -128.01), SIMDE_FLOAT64_C(  -256.48) },
      { SIMDE_FLOAT64_C(   611.73), SIMDE_FLOAT64_C(  -291.36), SIMDE_FLOAT64_C(  -492.95), SIMDE_FLOAT64_C(  -194.26) },
      { SIMDE_FLOAT64_C(   667.25), SIMDE_FLOAT64_C(   177.71), SIMDE_FLOAT64_C(  -895.52), SIMDE_FLOAT64_C(  -852.48) },
      UINT8_C( 92),
      { SIMDE_FLOAT64_C(   667.25), SIMDE_FLOAT64_C(   177.71), SIMDE_FLOAT64_C( 63998.05), SIMDE_FLOAT64_C( 50676.28) } },
    { { SIMDE_FLOAT64_C(   582.76), SIMDE_FLOAT64_C(   299.54), SIMDE_FLOAT64_C(   -48.07), SIMDE_FLOAT64_C(   487.43) },
      { SIMDE_FLOAT64_C(   493.05), SIMDE_FLOAT64_C(   915.28), SIMDE_FLOAT64_C(    75.46), SIMDE_FLOAT64_C(   315.60) },
      { SIMDE_FLOAT64_C(   797.73), SIMDE_FLOAT64_C(  -764.70), SIMDE_FLOAT64_C(   183.72), SIMDE_FLOAT64_C(  -773.14) },
      UINT8_C( 99),
      { SIMDE_FLOAT64_C(286532.09), SIMDE_FLOAT64_C(274927.67), SIMDE_FLOAT64_C(   183.72), SIMDE_FLOAT64_C(  -773.14) } },
    { { SIMDE_FLOAT64_C(   195.30), SIMDE_FLOAT64_C(  -726.10), SIMDE_FLOAT64_C(   995.14), SIMDE_FLOAT64_C(  -988.93) },
      { SIMDE_FLOAT64_C(   688.35), SIMDE_FLOAT64_C(   607.17), SIMDE_FLOAT64_C(   502.00), SIMDE_FLOAT64_C(  -439.67) },
      { SIMDE_FLOAT64_C(  -649.31), SIMDE_FLOAT64_C(   113.73), SIMDE_FLOAT64_C(   268.97), SIMDE_FLOAT64_C(  -142.26) },
      UINT8_C(195),
      { SIMDE_FLOAT64_C(135084.07), SIMDE_FLOAT64_C(-440979.87), SIMDE_FLOAT64_C(   268.97), SIMDE_FLOAT64_C(  -142.26) } },
    { { SIMDE_FLOAT64_C(   -63.77), SIMDE_FLOAT64_C(  -964.56), SIMDE_FLOAT64_C(  -976.06), SIMDE_FLOAT64_C(    83.75) },
      { SIMDE_FLOAT64_C(   752.28), SIMDE_FLOAT64_C(   606.70), SIMDE_FLOAT64_C(  -616.71), SIMDE_FLOAT64_C(  -295.79) },
      { SIMDE_FLOAT64_C(    94.13), SIMDE_FLOAT64_C(   876.35), SIMDE_FLOAT64_C(  -380.51), SIMDE_FLOAT64_C(  -830.42) },
      UINT8_C(252),
      { SIMDE_FLOAT64_C(    94.13), SIMDE_FLOAT64_C(   876.35), SIMDE_FLOAT64_C(602326.47), SIMDE_FLOAT64_C(-23941.99) } },
    { { SIMDE_FLOAT64_C(  -582.78), SIMDE_FLOAT64_C(  -595.11), SIMDE_FLOAT64_C(  -624.34), SIMDE_FLOAT64_C(  -355.92) },
      { SIMDE_FLOAT64_C(  -402.15), SIMDE_FLOAT64_C(   570.96), SIMDE_FLOAT64_C(   -82.02), SIMDE_FLOAT64_C(  -407.00) },
      { SIMDE_FLOAT64_C(   582.03), SIMDE_FLOAT64_C(  -393.67), SIMDE_FLOAT64_C(  -799.83), SIMDE_FLOAT64_C(    84.03) },
      UINT8_C(168),
      { SIMDE_FLOAT64_C(   582.03), SIMDE_FLOAT64_C(  -393.67), SIMDE_FLOAT64_C(  -799.83), SIMDE_FLOAT64_C(144775.41) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d c = simde_mm256_loadu_pd(test_vec[i].c);
    simde__m256d r = simde_mm256_mask3_fmsub_pd(a, b, c, test_vec[i].k);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d c = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d r = simde_mm256_mask3_fmsub_pd(a, b, c, k);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_fmsub_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const simde__mmask8 k;
    const simde_float64 b[4];
    const simde_float64 c[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   679.94), SIMDE_FLOAT64_C(  -650.92), SIMDE_FLOAT64_C(  -451.39), SIMDE_FLOAT64_C(   782.22) },
      UINT8_C(247),
      { SIMDE_FLOAT64_C(  -298.33), SIMDE_FLOAT64_C(   981.11), SIMDE_FLOAT64_C(  -715.76), SIMDE_FLOAT64_C(   567.16) },
      { SIMDE_FLOAT64_C(   977.82), SIMDE_FLOAT64_C(   -15.46), SIMDE_FLOAT64_C(   580.37), SIMDE_FLOAT64_C(   684.51) },
      { SIMDE_FLOAT64_C(-203824.32), SIMDE_FLOAT64_C(-638608.66), SIMDE_FLOAT64_C(322506.54), SIMDE_FLOAT64_C(   782.22) } },
    { { SIMDE_FLOAT64_C(   427.00), SIMDE_FLOAT64_C(  -211.11), SIMDE_FLOAT64_C(  -196.66), SIMDE_FLOAT64_C(   942.46) },
      UINT8_C(  6),
      { SIMDE_FLOAT64_C(   760.51), SIMDE_FLOAT64_C(   834.79), SIMDE_FLOAT64_C(   915.81), SIMDE_FLOAT64_C(   632.36) },
      { SIMDE_FLOAT64_C(  -813.85), SIMDE_FLOAT64_C(   615.59), SIMDE_FLOAT64_C(   177.28), SIMDE_FLOAT64_C(  -429.10) },
      { SIMDE_FLOAT64_C(   427.00), SIMDE_FLOAT64_C(-176848.11), SIMDE_FLOAT64_C(-180280.47), SIMDE_FLOAT64_C(   942.46) } },
    { { SIMDE_FLOAT64_C(  -557.62), SIMDE_FLOAT64_C(   876.64), SIMDE_FLOAT64_C(  -592.31), SIMDE_FLOAT64_C(   192.97) },
      UINT8_C(  7),
      { SIMDE_FLOAT64_C(  -912.37), SIMDE_FLOAT64_C(   542.05), SIMDE_FLOAT64_C(   794.79), SIMDE_FLOAT64_C(   869.85) },
      { SIMDE_FLOAT64_C(  -648.72), SIMDE_FLOAT64_C(  -503.53), SIMDE_FLOAT64_C(   850.96), SIMDE_FLOAT64_C(  -364.48) },
      { SIMDE_FLOAT64_C(509404.48), SIMDE_FLOAT64_C(475686.24), SIMDE_FLOAT64_C(-471613.02), SIMDE_FLOAT64_C(   192.97) } },
    { { SIMDE_FLOAT64_C(  -936.37), SIMDE_FLOAT64_C(   828.79), SIMDE_FLOAT64_C(   620.07), SIMDE_FLOAT64_C(   644.01) },
      UINT8_C( 86),
      { SIMDE_FLOAT64_C(    47.06), SIMDE_FLOAT64_C(  -567.11), SIMDE_FLOAT64_C(  -683.37), SIMDE_FLOAT64_C(   -10.48) },
      { SIMDE_FLOAT64_C(  -691.38), SIMDE_FLOAT64_C(  -922.86), SIMDE_FLOAT64_C(  -175.69), SIMDE_FLOAT64_C(  -775.57) },
      { SIMDE_FLOAT64_C(  -936.37), SIMDE_FLOAT64_C(-469092.24), SIMDE_FLOAT64_C(-423561.55), SIMDE_FLOAT64_C(   644.01) } },
    { { SIMDE_FLOAT64_C(   709.51), SIMDE_FLOAT64_C(    10.46), SIMDE_FLOAT64_C(   840.02), SIMDE_FLOAT64_C(  -113.21) },
      UINT8_C( 27),
      { SIMDE_FLOAT64_C(  -717.60), SIMDE_FLOAT64_C(  -236.58), SIMDE_FLOAT64_C(   989.06), SIMDE_FLOAT64_C(   475.37) },
      { SIMDE_FLOAT64_C(  -990.39), SIMDE_FLOAT64_C(  -923.31), SIMDE_FLOAT64_C(    17.42), SIMDE_FLOAT64_C(   804.41) },
      { SIMDE_FLOAT64_C(-508153.99), SIMDE_FLOAT64_C( -1551.32), SIMDE_FLOAT64_C(   840.02), SIMDE_FLOAT64_C(-54621.05) } },
    { { SIMDE_FLOAT64_C(   946.54), SIMDE_FLOAT64_C(   368.70), SIMDE_FLOAT64_C(  -699.12), SIMDE_FLOAT64_C(   797.51) },
      UINT8_C(148),
      { SIMDE_FLOAT64_C(  -635.49), SIMDE_FLOAT64_C(   626.29), SIMDE_FLOAT64_C(   624.29), SIMDE_FLOAT64_C(  -991.49) },
      { SIMDE_FLOAT64_C(   139.59), SIMDE_FLOAT64_C(  -328.65), SIMDE_FLOAT64_C(  -558.59), SIMDE_FLOAT64_C(   456.22) },
      { SIMDE_FLOAT64_C(   946.54), SIMDE_FLOAT64_C(   368.70), SIMDE_FLOAT64_C(-435895.03), SIMDE_FLOAT64_C(   797.51) } },
    { { SIMDE_FLOAT64_C(   660.87), SIMDE_FLOAT64_C(  -249.98), SIMDE_FLOAT64_C(   533.36), SIMDE_FLOAT64_C(  -514.82) },
      UINT8_C(206),
      { SIMDE_FLOAT64_C(   242.87), SIMDE_FLOAT64_C(   495.64), SIMDE_FLOAT64_C(  -185.53), SIMDE_FLOAT64_C(  -870.34) },
      { SIMDE_FLOAT64_C(    77.00), SIMDE_FLOAT64_C(    96.87), SIMDE_FLOAT64_C(  -106.92), SIMDE_FLOAT64_C(    66.06) },
      { SIMDE_FLOAT64_C(   660.87), SIMDE_FLOAT64_C(-123996.96), SIMDE_FLOAT64_C(-98847.36), SIMDE_FLOAT64_C(448002.38) } },
    { { SIMDE_FLOAT64_C(  -427.76), SIMDE_FLOAT64_C(   -97.30), SIMDE_FLOAT64_C(   142.74), SIMDE_FLOAT64_C(   589.66) },
      UINT8_C(211),
      { SIMDE_FLOAT64_C(    89.28), SIMDE_FLOAT64_C(   -41.64), SIMDE_FLOAT64_C(     7.98), SIMDE_FLOAT64_C(  -113.21) },
      { SIMDE_FLOAT64_C(   -37.42), SIMDE_FLOAT64_C(   372.49), SIMDE_FLOAT64_C(  -486.92), SIMDE_FLOAT64_C(  -413.14) },
      { SIMDE_FLOAT64_C(-38152.99), SIMDE_FLOAT64_C(  3679.08), SIMDE_FLOAT64_C(   142.74), SIMDE_FLOAT64_C(   589.66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d c = simde_mm256_loadu_pd(test_vec[i].c);
    simde__m256d r = simde_mm256_mask_fmsub_pd(a, test_vec[i].k, b, c);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d c = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_mask_fmsub_pd(a, k, b, c);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_fmsub_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 c[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C( 25),
      { SIMDE_FLOAT64_C(   232.69), SIMDE_FLOAT64_C(    64.70), SIMDE_FLOAT64_C(  -891.95), SIMDE_FLOAT64_C(  -994.97) },
      { SIMDE_FLOAT64_C(  -220.84), SIMDE_FLOAT64_C(  -581.73), SIMDE_FLOAT64_C(  -763.36), SIMDE_FLOAT64_C(   140.20) },
      { SIMDE_FLOAT64_C(  -188.54), SIMDE_FLOAT64_C(   795.19), SIMDE_FLOAT64_C(  -191.89), SIMDE_FLOAT64_C(  -597.31) },
      { SIMDE_FLOAT64_C(-51198.72), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-138897.48) } },
    { UINT8_C(126),
      { SIMDE_FLOAT64_C(  -417.76), SIMDE_FLOAT64_C(  -376.20), SIMDE_FLOAT64_C(  -480.75), SIMDE_FLOAT64_C(   587.20) },
      { SIMDE_FLOAT64_C(   654.93), SIMDE_FLOAT64_C(   320.39), SIMDE_FLOAT64_C(  -333.82), SIMDE_FLOAT64_C(  -841.08) },
      { SIMDE_FLOAT64_C(  -684.25), SIMDE_FLOAT64_C(   264.60), SIMDE_FLOAT64_C(   239.65), SIMDE_FLOAT64_C(  -504.73) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-120795.32), SIMDE_FLOAT64_C(160244.32), SIMDE_FLOAT64_C(-493377.45) } },
    { UINT8_C(109),
      { SIMDE_FLOAT64_C(   758.39), SIMDE_FLOAT64_C(  -246.89), SIMDE_FLOAT64_C(   128.18), SIMDE_FLOAT64_C(   432.15) },
      { SIMDE_FLOAT64_C(  -342.44), SIMDE_FLOAT64_C(  -639.14), SIMDE_FLOAT64_C(  -503.15), SIMDE_FLOAT64_C(  -234.38) },
      { SIMDE_FLOAT64_C(  -634.10), SIMDE_FLOAT64_C(   276.01), SIMDE_FLOAT64_C(   183.88), SIMDE_FLOAT64_C(  -397.47) },
      { SIMDE_FLOAT64_C(-259068.97), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-64677.65), SIMDE_FLOAT64_C(-100889.85) } },
    { UINT8_C( 93),
      { SIMDE_FLOAT64_C(   995.34), SIMDE_FLOAT64_C(  -602.28), SIMDE_FLOAT64_C(   224.32), SIMDE_FLOAT64_C(  -601.97) },
      { SIMDE_FLOAT64_C(  -911.34), SIMDE_FLOAT64_C(   806.56), SIMDE_FLOAT64_C(    21.83), SIMDE_FLOAT64_C(  -392.09) },
      { SIMDE_FLOAT64_C(   393.76), SIMDE_FLOAT64_C(  -323.24), SIMDE_FLOAT64_C(   928.30), SIMDE_FLOAT64_C(  -940.06) },
      { SIMDE_FLOAT64_C(-907486.92), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  3968.61), SIMDE_FLOAT64_C(236966.48) } },
    { UINT8_C( 91),
      { SIMDE_FLOAT64_C(  -755.95), SIMDE_FLOAT64_C(   324.54), SIMDE_FLOAT64_C(  -924.67), SIMDE_FLOAT64_C(  -260.68) },
      { SIMDE_FLOAT64_C(  -253.16), SIMDE_FLOAT64_C(   833.72), SIMDE_FLOAT64_C(   492.43), SIMDE_FLOAT64_C(   875.02) },
      { SIMDE_FLOAT64_C(   265.87), SIMDE_FLOAT64_C(  -850.00), SIMDE_FLOAT64_C(  -764.12), SIMDE_FLOAT64_C(   762.72) },
      { SIMDE_FLOAT64_C(191110.43), SIMDE_FLOAT64_C(271425.49), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-228862.93) } },
    { UINT8_C( 13),
      { SIMDE_FLOAT64_C(  -398.22), SIMDE_FLOAT64_C(    38.73), SIMDE_FLOAT64_C(  -900.51), SIMDE_FLOAT64_C(   204.31) },
      { SIMDE_FLOAT64_C(   454.94), SIMDE_FLOAT64_C(  -905.17), SIMDE_FLOAT64_C(   602.03), SIMDE_FLOAT64_C(  -320.74) },
      { SIMDE_FLOAT64_C(  -507.13), SIMDE_FLOAT64_C(   690.69), SIMDE_FLOAT64_C(  -514.18), SIMDE_FLOAT64_C(   514.70) },
      { SIMDE_FLOAT64_C(-180659.08), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-541619.86), SIMDE_FLOAT64_C(-66045.09) } },
    { UINT8_C(114),
      { SIMDE_FLOAT64_C(   879.58), SIMDE_FLOAT64_C(  -808.55), SIMDE_FLOAT64_C(  -773.10), SIMDE_FLOAT64_C(   939.51) },
      { SIMDE_FLOAT64_C(    27.13), SIMDE_FLOAT64_C(  -529.04), SIMDE_FLOAT64_C(   264.05), SIMDE_FLOAT64_C(   102.46) },
      { SIMDE_FLOAT64_C(   210.28), SIMDE_FLOAT64_C(  -989.11), SIMDE_FLOAT64_C(   -63.82), SIMDE_FLOAT64_C(  -297.29) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(428744.40), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(228),
      { SIMDE_FLOAT64_C(  -797.95), SIMDE_FLOAT64_C(  -147.29), SIMDE_FLOAT64_C(  -878.21), SIMDE_FLOAT64_C(   964.77) },
      { SIMDE_FLOAT64_C(   768.32), SIMDE_FLOAT64_C(  -276.43), SIMDE_FLOAT64_C(     3.50), SIMDE_FLOAT64_C(   867.81) },
      { SIMDE_FLOAT64_C(   927.88), SIMDE_FLOAT64_C(  -541.56), SIMDE_FLOAT64_C(   962.65), SIMDE_FLOAT64_C(   529.91) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C( -4036.39), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d c = simde_mm256_loadu_pd(test_vec[i].c);
    simde__m256d r = simde_mm256_maskz_fmsub_pd(test_vec[i].k, a, b, c);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d c = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_maskz_fmsub_pd(k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask3_fmsub_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 c[2];
    const simde__mmask8 k;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   487.95), SIMDE_FLOAT64_C(   974.14) },
      { SIMDE_FLOAT64_C(   218.01), SIMDE_FLOAT64_C(  -532.31) },
      { SIMDE_FLOAT64_C(   262.30), SIMDE_FLOAT64_C(  -672.99) },
      UINT8_C(137),
      { SIMDE_FLOAT64_C(106115.68), SIMDE_FLOAT64_C(  -672.99) } },
    { { SIMDE_FLOAT64_C(   -47.66), SIMDE_FLOAT64_C(   274.55) },
      { SIMDE_FLOAT64_C(  -634.93), SIMDE_FLOAT64_C(  -690.86) },
      { SIMDE_FLOAT64_C(  -817.46), SIMDE_FLOAT64_C(   844.40) },
      UINT8_C( 30),
      { SIMDE_FLOAT64_C(  -817.46), SIMDE_FLOAT64_C(-190520.01) } },
    { { SIMDE_FLOAT64_C(   735.27), SIMDE_FLOAT64_C(   -23.68) },
      { SIMDE_FLOAT64_C(  -790.02), SIMDE_FLOAT64_C(  -627.96) },
      { SIMDE_FLOAT64_C(  -178.61), SIMDE_FLOAT64_C(   799.75) },
      UINT8_C( 62),
      { SIMDE_FLOAT64_C(  -178.61), SIMDE_FLOAT64_C( 14070.34) } },
    { { SIMDE_FLOAT64_C(  -281.07), SIMDE_FLOAT64_C(  -249.44) },
      { SIMDE_FLOAT64_C(  -363.18), SIMDE_FLOAT64_C(   -49.00) },
      { SIMDE_FLOAT64_C(  -545.91), SIMDE_FLOAT64_C(  -837.74) },
      UINT8_C(189),
      { SIMDE_FLOAT64_C(102624.91), SIMDE_FLOAT64_C(  -837.74) } },
    { { SIMDE_FLOAT64_C(  -192.42), SIMDE_FLOAT64_C(  -886.89) },
      { SIMDE_FLOAT64_C(   112.78), SIMDE_FLOAT64_C(  -704.47) },
      { SIMDE_FLOAT64_C(  -912.75), SIMDE_FLOAT64_C(  -669.21) },
      UINT8_C( 93),
      { SIMDE_FLOAT64_C(-20788.38), SIMDE_FLOAT64_C(  -669.21) } },
    { { SIMDE_FLOAT64_C(   349.56), SIMDE_FLOAT64_C(  -342.21) },
      { SIMDE_FLOAT64_C(  -284.85), SIMDE_FLOAT64_C(  -698.11) },
      { SIMDE_FLOAT64_C(   932.35), SIMDE_FLOAT64_C(    80.22) },
      UINT8_C(115),
      { SIMDE_FLOAT64_C(-100504.52), SIMDE_FLOAT64_C(238820.00) } },
    { { SIMDE_FLOAT64_C(  -885.11), SIMDE_FLOAT64_C(   -75.37) },
      { SIMDE_FLOAT64_C(  -400.13), SIMDE_FLOAT64_C(   850.16) },
      { SIMDE_FLOAT64_C(   900.94), SIMDE_FLOAT64_C(  -190.15) },
      UINT8_C(190),
      { SIMDE_FLOAT64_C(   900.94), SIMDE_FLOAT64_C(-63886.41) } },
    { { SIMDE_FLOAT64_C(  -277.66), SIMDE_FLOAT64_C(  -390.39) },
      { SIMDE_FLOAT64_C(  -507.69), SIMDE_FLOAT64_C(   441.27) },
      { SIMDE_FLOAT64_C(   360.17), SIMDE_FLOAT64_C(   129.12) },
      UINT8_C(  2),
      { SIMDE_FLOAT64_C(   360.17), SIMDE_FLOAT64_C(-172396.52) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d c = simde_mm_loadu_pd(test_vec[i].c);
    simde__m128d r = simde_mm_mask3_fmsub_pd(a, b, c, test_vec[i].k);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d c = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d r = simde_mm_mask3_fmsub_pd(a, b, c, k);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_fmsub_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde__mmask8 k;
    const simde_float64 b[2];
    const simde_float64 c[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   819.06), SIMDE_FLOAT64_C(   -89.62) },
      UINT8_C( 20),
      { SIMDE_FLOAT64_C(   863.60), SIMDE_FLOAT64_C(   956.60) },
      { SIMDE_FLOAT64_C(   184.19), SIMDE_FLOAT64_C(  -173.26) },
      { SIMDE_FLOAT64_C(   819.06), SIMDE_FLOAT64_C(   -89.62) } },
    { { SIMDE_FLOAT64_C(  -907.16), SIMDE_FLOAT64_C(    78.38) },
      UINT8_C(253),
      { SIMDE_FLOAT64_C(   510.70), SIMDE_FLOAT64_C(  -694.94) },
      { SIMDE_FLOAT64_C(   141.48), SIMDE_FLOAT64_C(  -897.93) },
      { SIMDE_FLOAT64_C(-463428.09), SIMDE_FLOAT64_C(    78.38) } },
    { { SIMDE_FLOAT64_C(  -315.81), SIMDE_FLOAT64_C(   993.53) },
      UINT8_C( 80),
      { SIMDE_FLOAT64_C(   423.85), SIMDE_FLOAT64_C(   561.78) },
      { SIMDE_FLOAT64_C(   178.61), SIMDE_FLOAT64_C(   606.93) },
      { SIMDE_FLOAT64_C(  -315.81), SIMDE_FLOAT64_C(   993.53) } },
    { { SIMDE_FLOAT64_C(  -282.73), SIMDE_FLOAT64_C(   374.02) },
      UINT8_C(234),
      { SIMDE_FLOAT64_C(   382.75), SIMDE_FLOAT64_C(    69.97) },
      { SIMDE_FLOAT64_C(   987.46), SIMDE_FLOAT64_C(  -743.87) },
      { SIMDE_FLOAT64_C(  -282.73), SIMDE_FLOAT64_C( 26914.05) } },
    { { SIMDE_FLOAT64_C(  -650.14), SIMDE_FLOAT64_C(   792.18) },
      UINT8_C(215),
      { SIMDE_FLOAT64_C(  -831.08), SIMDE_FLOAT64_C(  -297.44) },
      { SIMDE_FLOAT64_C(   908.88), SIMDE_FLOAT64_C(  -967.48) },
      { SIMDE_FLOAT64_C(539409.47), SIMDE_FLOAT64_C(-234658.54) } },
    { { SIMDE_FLOAT64_C(  -340.84), SIMDE_FLOAT64_C(    93.07) },
      UINT8_C(198),
      { SIMDE_FLOAT64_C(  -248.00), SIMDE_FLOAT64_C(  -828.55) },
      { SIMDE_FLOAT64_C(  -776.88), SIMDE_FLOAT64_C(  -737.30) },
      { SIMDE_FLOAT64_C(  -340.84), SIMDE_FLOAT64_C(-76375.85) } },
    { { SIMDE_FLOAT64_C(  -523.49), SIMDE_FLOAT64_C(   364.60) },
      UINT8_C(236),
      { SIMDE_FLOAT64_C(   160.70), SIMDE_FLOAT64_C(   358.13) },
      { SIMDE_FLOAT64_C(  -902.39), SIMDE_FLOAT64_C(  -415.45) },
      { SIMDE_FLOAT64_C(  -523.49), SIMDE_FLOAT64_C(   364.60) } },
    { { SIMDE_FLOAT64_C(   -80.09), SIMDE_FLOAT64_C(   276.22) },
      UINT8_C( 89),
      { SIMDE_FLOAT64_C(   637.18), SIMDE_FLOAT64_C(  -349.76) },
      { SIMDE_FLOAT64_C(    41.52), SIMDE_FLOAT64_C(    19.94) },
      { SIMDE_FLOAT64_C(-51073.27), SIMDE_FLOAT64_C(   276.22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d c = simde_mm_loadu_pd(test_vec[i].c);
    simde__m128d r = simde_mm_mask_fmsub_pd(a, test_vec[i].k, b, c);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d c = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_mask_fmsub_pd(a, k, b, c);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_fmsub_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 c[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C( 95),
      { SIMDE_FLOAT64_C(   920.64), SIMDE_FLOAT64_C(   725.81) },
      { SIMDE_FLOAT64_C(   360.26), SIMDE_FLOAT64_C(   687.84) },
      { SIMDE_FLOAT64_C(   262.25), SIMDE_FLOAT64_C(   878.73) },
      { SIMDE_FLOAT64_C(331407.52), SIMDE_FLOAT64_C(498362.42) } },
    { UINT8_C(142),
      { SIMDE_FLOAT64_C(  -320.65), SIMDE_FLOAT64_C(  -354.71) },
      { SIMDE_FLOAT64_C(   942.15), SIMDE_FLOAT64_C(   899.30) },
      { SIMDE_FLOAT64_C(   212.41), SIMDE_FLOAT64_C(   995.00) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-319985.70) } },
    { UINT8_C(220),
      { SIMDE_FLOAT64_C(  -851.11), SIMDE_FLOAT64_C(  -551.67) },
      { SIMDE_FLOAT64_C(   695.44), SIMDE_FLOAT64_C(   899.92) },
      { SIMDE_FLOAT64_C(   350.71), SIMDE_FLOAT64_C(   416.83) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(163),
      { SIMDE_FLOAT64_C(   836.16), SIMDE_FLOAT64_C(  -798.79) },
      { SIMDE_FLOAT64_C(   679.77), SIMDE_FLOAT64_C(    47.52) },
      { SIMDE_FLOAT64_C(  -961.36), SIMDE_FLOAT64_C(  -234.63) },
      { SIMDE_FLOAT64_C(569357.84), SIMDE_FLOAT64_C(-37723.87) } },
    { UINT8_C(112),
      { SIMDE_FLOAT64_C(  -847.67), SIMDE_FLOAT64_C(  -617.07) },
      { SIMDE_FLOAT64_C(  -319.47), SIMDE_FLOAT64_C(  -927.03) },
      { SIMDE_FLOAT64_C(  -891.26), SIMDE_FLOAT64_C(  -959.21) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 59),
      { SIMDE_FLOAT64_C(   370.99), SIMDE_FLOAT64_C(   919.51) },
      { SIMDE_FLOAT64_C(   339.75), SIMDE_FLOAT64_C(  -949.67) },
      { SIMDE_FLOAT64_C(  -435.19), SIMDE_FLOAT64_C(   281.89) },
      { SIMDE_FLOAT64_C(126479.04), SIMDE_FLOAT64_C(-873512.95) } },
    { UINT8_C( 15),
      { SIMDE_FLOAT64_C(   777.22), SIMDE_FLOAT64_C(   276.89) },
      { SIMDE_FLOAT64_C(  -243.21), SIMDE_FLOAT64_C(   926.10) },
      { SIMDE_FLOAT64_C(   725.23), SIMDE_FLOAT64_C(  -547.77) },
      { SIMDE_FLOAT64_C(-189752.91), SIMDE_FLOAT64_C(256975.60) } },
    { UINT8_C(202),
      { SIMDE_FLOAT64_C(    75.93), SIMDE_FLOAT64_C(   869.06) },
      { SIMDE_FLOAT64_C(  -988.11), SIMDE_FLOAT64_C(   -87.90) },
      { SIMDE_FLOAT64_C(  -929.73), SIMDE_FLOAT64_C(   691.66) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-77082.03) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d c = simde_mm_loadu_pd(test_vec[i].c);
    simde__m128d r = simde_mm_maskz_fmsub_pd(test_vec[i].k, a, b, c);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d c = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_maskz_fmsub_pd(k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask3_fmsub_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 c[8];
    const simde__mmask8 k;
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   652.59), SIMDE_FLOAT32_C(   -65.81), SIMDE_FLOAT32_C(  -587.88), SIMDE_FLOAT32_C(   591.56),
        SIMDE_FLOAT32_C(   981.92), SIMDE_FLOAT32_C(   460.71), SIMDE_FLOAT32_C(   160.98), SIMDE_FLOAT32_C(  -198.70) },
      { SIMDE_FLOAT32_C(   831.07), SIMDE_FLOAT32_C(     2.11), SIMDE_FLOAT32_C(   287.80), SIMDE_FLOAT32_C(  -865.37),
        SIMDE_FLOAT32_C(   984.61), SIMDE_FLOAT32_C(  -509.15), SIMDE_FLOAT32_C(   535.44), SIMDE_FLOAT32_C(  -822.80) },
      { SIMDE_FLOAT32_C(   697.16), SIMDE_FLOAT32_C(  -953.29), SIMDE_FLOAT32_C(  -349.92), SIMDE_FLOAT32_C(   768.86),
        SIMDE_FLOAT32_C(  -907.91), SIMDE_FLOAT32_C(   546.96), SIMDE_FLOAT32_C(   176.82), SIMDE_FLOAT32_C(  -900.99) },
      UINT8_C( 95),
      { SIMDE_FLOAT32_C(541650.81), SIMDE_FLOAT32_C(   814.43), SIMDE_FLOAT32_C(-168841.94), SIMDE_FLOAT32_C(-512687.12),
        SIMDE_FLOAT32_C(967716.12), SIMDE_FLOAT32_C(   546.96), SIMDE_FLOAT32_C( 86018.31), SIMDE_FLOAT32_C(  -900.99) } },
    { { SIMDE_FLOAT32_C(  -246.16), SIMDE_FLOAT32_C(   965.54), SIMDE_FLOAT32_C(   831.57), SIMDE_FLOAT32_C(   414.39),
        SIMDE_FLOAT32_C(   787.88), SIMDE_FLOAT32_C(   810.49), SIMDE_FLOAT32_C(    66.98), SIMDE_FLOAT32_C(  -277.94) },
      { SIMDE_FLOAT32_C(  -777.39), SIMDE_FLOAT32_C(  -341.46), SIMDE_FLOAT32_C(  -296.02), SIMDE_FLOAT32_C(   683.31),
        SIMDE_FLOAT32_C(   819.52), SIMDE_FLOAT32_C(   505.28), SIMDE_FLOAT32_C(   514.38), SIMDE_FLOAT32_C(  -178.37) },
      { SIMDE_FLOAT32_C(  -206.92), SIMDE_FLOAT32_C(   649.02), SIMDE_FLOAT32_C(  -193.76), SIMDE_FLOAT32_C(   283.93),
        SIMDE_FLOAT32_C(   184.46), SIMDE_FLOAT32_C(   -16.56), SIMDE_FLOAT32_C(   -18.91), SIMDE_FLOAT32_C(   231.16) },
      UINT8_C( 77),
      { SIMDE_FLOAT32_C(191569.25), SIMDE_FLOAT32_C(   649.02), SIMDE_FLOAT32_C(-245967.58), SIMDE_FLOAT32_C(282872.91),
        SIMDE_FLOAT32_C(   184.46), SIMDE_FLOAT32_C(   -16.56), SIMDE_FLOAT32_C( 34472.09), SIMDE_FLOAT32_C(   231.16) } },
    { { SIMDE_FLOAT32_C(  -250.05), SIMDE_FLOAT32_C(   323.26), SIMDE_FLOAT32_C(   180.47), SIMDE_FLOAT32_C(   926.77),
        SIMDE_FLOAT32_C(   422.27), SIMDE_FLOAT32_C(   -45.19), SIMDE_FLOAT32_C(  -319.39), SIMDE_FLOAT32_C(   387.80) },
      { SIMDE_FLOAT32_C(  -213.62), SIMDE_FLOAT32_C(  -905.00), SIMDE_FLOAT32_C(   175.68), SIMDE_FLOAT32_C(  -403.13),
        SIMDE_FLOAT32_C(   161.99), SIMDE_FLOAT32_C(   897.74), SIMDE_FLOAT32_C(  -180.52), SIMDE_FLOAT32_C(   820.53) },
      { SIMDE_FLOAT32_C(  -398.28), SIMDE_FLOAT32_C(  -497.21), SIMDE_FLOAT32_C(   640.04), SIMDE_FLOAT32_C(  -893.00),
        SIMDE_FLOAT32_C(  -982.83), SIMDE_FLOAT32_C(  -538.33), SIMDE_FLOAT32_C(   -99.92), SIMDE_FLOAT32_C(   666.19) },
      UINT8_C(113),
      { SIMDE_FLOAT32_C( 53813.96), SIMDE_FLOAT32_C(  -497.21), SIMDE_FLOAT32_C(   640.04), SIMDE_FLOAT32_C(  -893.00),
        SIMDE_FLOAT32_C( 69386.35), SIMDE_FLOAT32_C(-40030.54), SIMDE_FLOAT32_C( 57756.21), SIMDE_FLOAT32_C(   666.19) } },
    { { SIMDE_FLOAT32_C(  -815.99), SIMDE_FLOAT32_C(  -149.35), SIMDE_FLOAT32_C(  -748.65), SIMDE_FLOAT32_C(   165.11),
        SIMDE_FLOAT32_C(  -918.19), SIMDE_FLOAT32_C(   884.86), SIMDE_FLOAT32_C(   915.06), SIMDE_FLOAT32_C(   405.07) },
      { SIMDE_FLOAT32_C(    65.34), SIMDE_FLOAT32_C(   841.83), SIMDE_FLOAT32_C(  -172.67), SIMDE_FLOAT32_C(  -979.85),
        SIMDE_FLOAT32_C(  -477.56), SIMDE_FLOAT32_C(  -784.86), SIMDE_FLOAT32_C(  -193.47), SIMDE_FLOAT32_C(  -382.56) },
      { SIMDE_FLOAT32_C(   390.82), SIMDE_FLOAT32_C(   403.39), SIMDE_FLOAT32_C(   779.43), SIMDE_FLOAT32_C(   288.56),
        SIMDE_FLOAT32_C(  -777.13), SIMDE_FLOAT32_C(   599.96), SIMDE_FLOAT32_C(   890.28), SIMDE_FLOAT32_C(  -274.34) },
      UINT8_C(155),
      { SIMDE_FLOAT32_C(-53707.60), SIMDE_FLOAT32_C(-126130.71), SIMDE_FLOAT32_C(   779.43), SIMDE_FLOAT32_C(-162071.59),
        SIMDE_FLOAT32_C(439267.94), SIMDE_FLOAT32_C(   599.96), SIMDE_FLOAT32_C(   890.28), SIMDE_FLOAT32_C(-154689.23) } },
    { { SIMDE_FLOAT32_C(   997.29), SIMDE_FLOAT32_C(  -257.17), SIMDE_FLOAT32_C(   701.68), SIMDE_FLOAT32_C(  -102.63),
        SIMDE_FLOAT32_C(  -590.98), SIMDE_FLOAT32_C(   -30.41), SIMDE_FLOAT32_C(    81.39), SIMDE_FLOAT32_C(   259.67) },
      { SIMDE_FLOAT32_C(   220.94), SIMDE_FLOAT32_C(  -753.51), SIMDE_FLOAT32_C(   341.48), SIMDE_FLOAT32_C(   105.80),
        SIMDE_FLOAT32_C(  -838.45), SIMDE_FLOAT32_C(  -253.45), SIMDE_FLOAT32_C(  -828.87), SIMDE_FLOAT32_C(  -996.62) },
      { SIMDE_FLOAT32_C(   573.89), SIMDE_FLOAT32_C(  -808.72), SIMDE_FLOAT32_C(  -474.18), SIMDE_FLOAT32_C(   789.02),
        SIMDE_FLOAT32_C(    -2.19), SIMDE_FLOAT32_C(   143.26), SIMDE_FLOAT32_C(   179.84), SIMDE_FLOAT32_C(  -598.80) },
      UINT8_C( 96),
      { SIMDE_FLOAT32_C(   573.89), SIMDE_FLOAT32_C(  -808.72), SIMDE_FLOAT32_C(  -474.18), SIMDE_FLOAT32_C(   789.02),
        SIMDE_FLOAT32_C(    -2.19), SIMDE_FLOAT32_C(  7564.15), SIMDE_FLOAT32_C(-67641.57), SIMDE_FLOAT32_C(  -598.80) } },
    { { SIMDE_FLOAT32_C(  -531.60), SIMDE_FLOAT32_C(  -375.93), SIMDE_FLOAT32_C(  -477.35), SIMDE_FLOAT32_C(  -641.32),
        SIMDE_FLOAT32_C(   349.73), SIMDE_FLOAT32_C(   762.65), SIMDE_FLOAT32_C(  -644.03), SIMDE_FLOAT32_C(  -907.44) },
      { SIMDE_FLOAT32_C(   464.33), SIMDE_FLOAT32_C(   253.35), SIMDE_FLOAT32_C(  -498.42), SIMDE_FLOAT32_C(  -566.08),
        SIMDE_FLOAT32_C(  -665.27), SIMDE_FLOAT32_C(   761.25), SIMDE_FLOAT32_C(   654.85), SIMDE_FLOAT32_C(  -418.77) },
      { SIMDE_FLOAT32_C(   102.73), SIMDE_FLOAT32_C(  -239.35), SIMDE_FLOAT32_C(  -257.22), SIMDE_FLOAT32_C(   849.29),
        SIMDE_FLOAT32_C(   -68.22), SIMDE_FLOAT32_C(  -253.84), SIMDE_FLOAT32_C(   423.17), SIMDE_FLOAT32_C(   123.07) },
      UINT8_C(225),
      { SIMDE_FLOAT32_C(-246940.55), SIMDE_FLOAT32_C(  -239.35), SIMDE_FLOAT32_C(  -257.22), SIMDE_FLOAT32_C(   849.29),
        SIMDE_FLOAT32_C(   -68.22), SIMDE_FLOAT32_C(580821.19), SIMDE_FLOAT32_C(-422166.22), SIMDE_FLOAT32_C(379885.56) } },
    { { SIMDE_FLOAT32_C(   212.19), SIMDE_FLOAT32_C(  -879.13), SIMDE_FLOAT32_C(  -584.76), SIMDE_FLOAT32_C(  -607.97),
        SIMDE_FLOAT32_C(  -477.92), SIMDE_FLOAT32_C(   337.93), SIMDE_FLOAT32_C(  -139.57), SIMDE_FLOAT32_C(   146.15) },
      { SIMDE_FLOAT32_C(   860.58), SIMDE_FLOAT32_C(   219.12), SIMDE_FLOAT32_C(  -504.12), SIMDE_FLOAT32_C(   623.23),
        SIMDE_FLOAT32_C(   575.09), SIMDE_FLOAT32_C(  -411.56), SIMDE_FLOAT32_C(    87.56), SIMDE_FLOAT32_C(  -171.56) },
      { SIMDE_FLOAT32_C(    90.03), SIMDE_FLOAT32_C(   521.48), SIMDE_FLOAT32_C(   163.17), SIMDE_FLOAT32_C(  -148.72),
        SIMDE_FLOAT32_C(   176.33), SIMDE_FLOAT32_C(   744.40), SIMDE_FLOAT32_C(   954.01), SIMDE_FLOAT32_C(   936.98) },
      UINT8_C( 28),
      { SIMDE_FLOAT32_C(    90.03), SIMDE_FLOAT32_C(   521.48), SIMDE_FLOAT32_C(294626.03), SIMDE_FLOAT32_C(-378756.41),
        SIMDE_FLOAT32_C(-275023.38), SIMDE_FLOAT32_C(   744.40), SIMDE_FLOAT32_C(   954.01), SIMDE_FLOAT32_C(   936.98) } },
    { { SIMDE_FLOAT32_C(   803.30), SIMDE_FLOAT32_C(  -131.24), SIMDE_FLOAT32_C(   233.34), SIMDE_FLOAT32_C(   226.47),
        SIMDE_FLOAT32_C(   991.83), SIMDE_FLOAT32_C(  -494.68), SIMDE_FLOAT32_C(  -561.34), SIMDE_FLOAT32_C(  -887.30) },
      { SIMDE_FLOAT32_C(   -79.44), SIMDE_FLOAT32_C(  -169.31), SIMDE_FLOAT32_C(  -365.22), SIMDE_FLOAT32_C(  -741.51),
        SIMDE_FLOAT32_C(   691.13), SIMDE_FLOAT32_C(   780.93), SIMDE_FLOAT32_C(  -880.93), SIMDE_FLOAT32_C(   -89.76) },
      { SIMDE_FLOAT32_C(  -723.19), SIMDE_FLOAT32_C(   742.31), SIMDE_FLOAT32_C(  -514.67), SIMDE_FLOAT32_C(  -134.75),
        SIMDE_FLOAT32_C(  -170.13), SIMDE_FLOAT32_C(   313.77), SIMDE_FLOAT32_C(   955.28), SIMDE_FLOAT32_C(  -648.65) },
      UINT8_C(253),
      { SIMDE_FLOAT32_C(-63090.96), SIMDE_FLOAT32_C(   742.31), SIMDE_FLOAT32_C(-84705.77), SIMDE_FLOAT32_C(-167795.02),
        SIMDE_FLOAT32_C(685653.62), SIMDE_FLOAT32_C(-386624.22), SIMDE_FLOAT32_C(493546.00), SIMDE_FLOAT32_C( 80292.70) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 c = simde_mm256_loadu_ps(test_vec[i].c);
    simde__m256 r = simde_mm256_mask3_fmsub_ps(a, b, c, test_vec[i].k);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 c = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 r = simde_mm256_mask3_fmsub_ps(a, b, c, k);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_fmsub_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde__mmask8 k;
    const simde_float32 b[8];
    const simde_float32 c[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   760.80), SIMDE_FLOAT32_C(  -869.71), SIMDE_FLOAT32_C(   650.39), SIMDE_FLOAT32_C(  -704.52),
        SIMDE_FLOAT32_C(  -365.12), SIMDE_FLOAT32_C(  -720.70), SIMDE_FLOAT32_C(  -182.13), SIMDE_FLOAT32_C(   336.49) },
      UINT8_C(235),
      { SIMDE_FLOAT32_C(  -819.89), SIMDE_FLOAT32_C(  -357.32), SIMDE_FLOAT32_C(   -17.10), SIMDE_FLOAT32_C(  -725.98),
        SIMDE_FLOAT32_C(  -252.19), SIMDE_FLOAT32_C(   625.68), SIMDE_FLOAT32_C(   369.39), SIMDE_FLOAT32_C(   314.52) },
      { SIMDE_FLOAT32_C(   348.46), SIMDE_FLOAT32_C(   164.55), SIMDE_FLOAT32_C(   456.93), SIMDE_FLOAT32_C(   475.55),
        SIMDE_FLOAT32_C(  -663.97), SIMDE_FLOAT32_C(  -697.06), SIMDE_FLOAT32_C(  -282.66), SIMDE_FLOAT32_C(   -30.80) },
      { SIMDE_FLOAT32_C(-624120.75), SIMDE_FLOAT32_C(310600.25), SIMDE_FLOAT32_C(   650.39), SIMDE_FLOAT32_C(510991.88),
        SIMDE_FLOAT32_C(  -365.12), SIMDE_FLOAT32_C(-450230.53), SIMDE_FLOAT32_C(-66994.34), SIMDE_FLOAT32_C(105863.62) } },
    { { SIMDE_FLOAT32_C(  -684.38), SIMDE_FLOAT32_C(   338.18), SIMDE_FLOAT32_C(  -475.07), SIMDE_FLOAT32_C(   194.10),
        SIMDE_FLOAT32_C(   633.33), SIMDE_FLOAT32_C(  -519.45), SIMDE_FLOAT32_C(   -45.10), SIMDE_FLOAT32_C(   763.62) },
      UINT8_C( 51),
      { SIMDE_FLOAT32_C(   250.38), SIMDE_FLOAT32_C(  -601.50), SIMDE_FLOAT32_C(  -589.77), SIMDE_FLOAT32_C(  -931.75),
        SIMDE_FLOAT32_C(   734.99), SIMDE_FLOAT32_C(  -989.98), SIMDE_FLOAT32_C(  -751.64), SIMDE_FLOAT32_C(  -622.33) },
      { SIMDE_FLOAT32_C(    -7.08), SIMDE_FLOAT32_C(  -477.62), SIMDE_FLOAT32_C(   125.48), SIMDE_FLOAT32_C(  -381.41),
        SIMDE_FLOAT32_C(   891.77), SIMDE_FLOAT32_C(  -560.00), SIMDE_FLOAT32_C(   967.05), SIMDE_FLOAT32_C(    56.31) },
      { SIMDE_FLOAT32_C(-171347.98), SIMDE_FLOAT32_C(-202937.64), SIMDE_FLOAT32_C(  -475.07), SIMDE_FLOAT32_C(   194.10),
        SIMDE_FLOAT32_C(464599.44), SIMDE_FLOAT32_C(514805.12), SIMDE_FLOAT32_C(   -45.10), SIMDE_FLOAT32_C(   763.62) } },
    { { SIMDE_FLOAT32_C(   896.92), SIMDE_FLOAT32_C(   442.60), SIMDE_FLOAT32_C(   392.34), SIMDE_FLOAT32_C(  -800.14),
        SIMDE_FLOAT32_C(  -840.06), SIMDE_FLOAT32_C(  -638.46), SIMDE_FLOAT32_C(  -484.52), SIMDE_FLOAT32_C(   498.12) },
      UINT8_C( 14),
      { SIMDE_FLOAT32_C(   709.58), SIMDE_FLOAT32_C(   131.45), SIMDE_FLOAT32_C(   367.02), SIMDE_FLOAT32_C(  -335.52),
        SIMDE_FLOAT32_C(  -104.93), SIMDE_FLOAT32_C(   497.96), SIMDE_FLOAT32_C(   914.86), SIMDE_FLOAT32_C(   293.57) },
      { SIMDE_FLOAT32_C(   908.19), SIMDE_FLOAT32_C(   983.11), SIMDE_FLOAT32_C(    28.57), SIMDE_FLOAT32_C(   918.21),
        SIMDE_FLOAT32_C(  -768.53), SIMDE_FLOAT32_C(   406.24), SIMDE_FLOAT32_C(   -88.87), SIMDE_FLOAT32_C(  -246.15) },
      { SIMDE_FLOAT32_C(   896.92), SIMDE_FLOAT32_C( 57196.66), SIMDE_FLOAT32_C(143968.05), SIMDE_FLOAT32_C(267544.75),
        SIMDE_FLOAT32_C(  -840.06), SIMDE_FLOAT32_C(  -638.46), SIMDE_FLOAT32_C(  -484.52), SIMDE_FLOAT32_C(   498.12) } },
    { { SIMDE_FLOAT32_C(  -468.28), SIMDE_FLOAT32_C(   529.72), SIMDE_FLOAT32_C(  -354.38), SIMDE_FLOAT32_C(   -28.29),
        SIMDE_FLOAT32_C(   496.77), SIMDE_FLOAT32_C(   701.94), SIMDE_FLOAT32_C(  -131.36), SIMDE_FLOAT32_C(   -60.63) },
      UINT8_C(124),
      { SIMDE_FLOAT32_C(    68.50), SIMDE_FLOAT32_C(    99.31), SIMDE_FLOAT32_C(   455.82), SIMDE_FLOAT32_C(   583.98),
        SIMDE_FLOAT32_C(  -402.57), SIMDE_FLOAT32_C(  -657.71), SIMDE_FLOAT32_C(   293.57), SIMDE_FLOAT32_C(   728.88) },
      { SIMDE_FLOAT32_C(   709.31), SIMDE_FLOAT32_C(   958.05), SIMDE_FLOAT32_C(  -376.05), SIMDE_FLOAT32_C(   207.27),
        SIMDE_FLOAT32_C(   872.91), SIMDE_FLOAT32_C(   917.52), SIMDE_FLOAT32_C(   115.46), SIMDE_FLOAT32_C(   856.02) },
      { SIMDE_FLOAT32_C(  -468.28), SIMDE_FLOAT32_C(   529.72), SIMDE_FLOAT32_C(-161157.45), SIMDE_FLOAT32_C(-16728.06),
        SIMDE_FLOAT32_C(-200857.61), SIMDE_FLOAT32_C(-462590.50), SIMDE_FLOAT32_C(-38678.82), SIMDE_FLOAT32_C(   -60.63) } },
    { { SIMDE_FLOAT32_C(   -53.91), SIMDE_FLOAT32_C(    33.67), SIMDE_FLOAT32_C(  -912.51), SIMDE_FLOAT32_C(  -647.67),
        SIMDE_FLOAT32_C(   944.80), SIMDE_FLOAT32_C(  -158.65), SIMDE_FLOAT32_C(  -115.96), SIMDE_FLOAT32_C(   474.52) },
      UINT8_C( 81),
      { SIMDE_FLOAT32_C(   855.75), SIMDE_FLOAT32_C(   -28.71), SIMDE_FLOAT32_C(   188.90), SIMDE_FLOAT32_C(  -275.61),
        SIMDE_FLOAT32_C(   910.66), SIMDE_FLOAT32_C(  -716.82), SIMDE_FLOAT32_C(   792.89), SIMDE_FLOAT32_C(     9.98) },
      { SIMDE_FLOAT32_C(   739.00), SIMDE_FLOAT32_C(   376.87), SIMDE_FLOAT32_C(   607.41), SIMDE_FLOAT32_C(  -918.71),
        SIMDE_FLOAT32_C(  -329.56), SIMDE_FLOAT32_C(   336.28), SIMDE_FLOAT32_C(   790.60), SIMDE_FLOAT32_C(  -371.52) },
      { SIMDE_FLOAT32_C(-46872.48), SIMDE_FLOAT32_C(    33.67), SIMDE_FLOAT32_C(  -912.51), SIMDE_FLOAT32_C(  -647.67),
        SIMDE_FLOAT32_C(860721.06), SIMDE_FLOAT32_C(  -158.65), SIMDE_FLOAT32_C(-92734.12), SIMDE_FLOAT32_C(   474.52) } },
    { { SIMDE_FLOAT32_C(   960.23), SIMDE_FLOAT32_C(    -2.14), SIMDE_FLOAT32_C(  -498.61), SIMDE_FLOAT32_C(   877.75),
        SIMDE_FLOAT32_C(  -886.68), SIMDE_FLOAT32_C(  -642.59), SIMDE_FLOAT32_C(  -176.16), SIMDE_FLOAT32_C(   146.99) },
      UINT8_C(110),
      { SIMDE_FLOAT32_C(   176.16), SIMDE_FLOAT32_C(    91.79), SIMDE_FLOAT32_C(   286.25), SIMDE_FLOAT32_C(  -939.79),
        SIMDE_FLOAT32_C(  -433.69), SIMDE_FLOAT32_C(  -226.78), SIMDE_FLOAT32_C(   915.96), SIMDE_FLOAT32_C(   537.60) },
      { SIMDE_FLOAT32_C(   962.13), SIMDE_FLOAT32_C(  -359.65), SIMDE_FLOAT32_C(   448.26), SIMDE_FLOAT32_C(  -754.69),
        SIMDE_FLOAT32_C(  -566.76), SIMDE_FLOAT32_C(  -541.77), SIMDE_FLOAT32_C(   984.31), SIMDE_FLOAT32_C(   810.11) },
      { SIMDE_FLOAT32_C(   960.23), SIMDE_FLOAT32_C(   163.22), SIMDE_FLOAT32_C(-143175.38), SIMDE_FLOAT32_C(-824145.94),
        SIMDE_FLOAT32_C(  -886.68), SIMDE_FLOAT32_C(146268.33), SIMDE_FLOAT32_C(-162339.83), SIMDE_FLOAT32_C(   146.99) } },
    { { SIMDE_FLOAT32_C(  -934.36), SIMDE_FLOAT32_C(  -934.40), SIMDE_FLOAT32_C(  -519.45), SIMDE_FLOAT32_C(   401.92),
        SIMDE_FLOAT32_C(   856.20), SIMDE_FLOAT32_C(   109.03), SIMDE_FLOAT32_C(   362.15), SIMDE_FLOAT32_C(  -145.94) },
      UINT8_C(125),
      { SIMDE_FLOAT32_C(   239.90), SIMDE_FLOAT32_C(   -32.61), SIMDE_FLOAT32_C(   967.84), SIMDE_FLOAT32_C(  -936.26),
        SIMDE_FLOAT32_C(  -885.62), SIMDE_FLOAT32_C(  -587.25), SIMDE_FLOAT32_C(   239.91), SIMDE_FLOAT32_C(   206.16) },
      { SIMDE_FLOAT32_C(   699.00), SIMDE_FLOAT32_C(   300.11), SIMDE_FLOAT32_C(   772.47), SIMDE_FLOAT32_C(  -527.77),
        SIMDE_FLOAT32_C(   216.07), SIMDE_FLOAT32_C(   310.07), SIMDE_FLOAT32_C(  -565.65), SIMDE_FLOAT32_C(   856.43) },
      { SIMDE_FLOAT32_C(-224851.95), SIMDE_FLOAT32_C(  -934.40), SIMDE_FLOAT32_C(-503516.97), SIMDE_FLOAT32_C(-375773.88),
        SIMDE_FLOAT32_C(-758483.94), SIMDE_FLOAT32_C(-64337.94), SIMDE_FLOAT32_C( 87449.05), SIMDE_FLOAT32_C(  -145.94) } },
    { { SIMDE_FLOAT32_C(  -241.67), SIMDE_FLOAT32_C(  -320.34), SIMDE_FLOAT32_C(  -710.33), SIMDE_FLOAT32_C(   216.56),
        SIMDE_FLOAT32_C(  -336.02), SIMDE_FLOAT32_C(  -900.22), SIMDE_FLOAT32_C(   282.20), SIMDE_FLOAT32_C(  -270.42) },
      UINT8_C(149),
      { SIMDE_FLOAT32_C(  -315.88), SIMDE_FLOAT32_C(  -414.22), SIMDE_FLOAT32_C(   689.36), SIMDE_FLOAT32_C(  -953.73),
        SIMDE_FLOAT32_C(   439.85), SIMDE_FLOAT32_C(   299.78), SIMDE_FLOAT32_C(   286.18), SIMDE_FLOAT32_C(  -592.77) },
      { SIMDE_FLOAT32_C(   267.62), SIMDE_FLOAT32_C(   349.92), SIMDE_FLOAT32_C(  -478.39), SIMDE_FLOAT32_C(   680.37),
        SIMDE_FLOAT32_C(  -410.18), SIMDE_FLOAT32_C(   727.77), SIMDE_FLOAT32_C(   379.37), SIMDE_FLOAT32_C(   889.94) },
      { SIMDE_FLOAT32_C( 76071.10), SIMDE_FLOAT32_C(  -320.34), SIMDE_FLOAT32_C(-489194.69), SIMDE_FLOAT32_C(   216.56),
        SIMDE_FLOAT32_C(-147388.22), SIMDE_FLOAT32_C(  -900.22), SIMDE_FLOAT32_C(   282.20), SIMDE_FLOAT32_C(159406.94) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 c = simde_mm256_loadu_ps(test_vec[i].c);
    simde__m256 r = simde_mm256_mask_fmsub_ps(a, test_vec[i].k, b, c);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 c = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_mask_fmsub_ps(a, k, b, c);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_fmsub_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 c[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(241),
      { SIMDE_FLOAT32_C(  -894.70), SIMDE_FLOAT32_C(  -318.54), SIMDE_FLOAT32_C(   690.66), SIMDE_FLOAT32_C(  -902.45),
        SIMDE_FLOAT32_C(  -599.03), SIMDE_FLOAT32_C(   385.31), SIMDE_FLOAT32_C(  -662.85), SIMDE_FLOAT32_C(   949.38) },
      { SIMDE_FLOAT32_C(   -41.50), SIMDE_FLOAT32_C(  -230.23), SIMDE_FLOAT32_C(  -619.36), SIMDE_FLOAT32_C(  -932.10),
        SIMDE_FLOAT32_C(   694.10), SIMDE_FLOAT32_C(   357.34), SIMDE_FLOAT32_C(  -490.89), SIMDE_FLOAT32_C(   404.47) },
      { SIMDE_FLOAT32_C(    97.18), SIMDE_FLOAT32_C(   -45.79), SIMDE_FLOAT32_C(   163.45), SIMDE_FLOAT32_C(  -463.68),
        SIMDE_FLOAT32_C(  -742.60), SIMDE_FLOAT32_C(  -196.27), SIMDE_FLOAT32_C(   186.61), SIMDE_FLOAT32_C(  -938.11) },
      { SIMDE_FLOAT32_C( 37032.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-415044.12), SIMDE_FLOAT32_C(137882.94), SIMDE_FLOAT32_C(325199.81), SIMDE_FLOAT32_C(384933.84) } },
    { UINT8_C(219),
      { SIMDE_FLOAT32_C(   559.49), SIMDE_FLOAT32_C(   -58.33), SIMDE_FLOAT32_C(   654.48), SIMDE_FLOAT32_C(  -999.12),
        SIMDE_FLOAT32_C(  -656.50), SIMDE_FLOAT32_C(  -460.74), SIMDE_FLOAT32_C(  -893.81), SIMDE_FLOAT32_C(    24.96) },
      { SIMDE_FLOAT32_C(  -770.08), SIMDE_FLOAT32_C(  -796.26), SIMDE_FLOAT32_C(   425.93), SIMDE_FLOAT32_C(   615.23),
        SIMDE_FLOAT32_C(  -459.10), SIMDE_FLOAT32_C(   375.32), SIMDE_FLOAT32_C(  -426.27), SIMDE_FLOAT32_C(   310.66) },
      { SIMDE_FLOAT32_C(   755.96), SIMDE_FLOAT32_C(  -358.37), SIMDE_FLOAT32_C(     4.76), SIMDE_FLOAT32_C(   113.30),
        SIMDE_FLOAT32_C(   150.74), SIMDE_FLOAT32_C(  -590.77), SIMDE_FLOAT32_C(  -789.53), SIMDE_FLOAT32_C(  -895.06) },
      { SIMDE_FLOAT32_C(-431608.03), SIMDE_FLOAT32_C( 46804.22), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-614801.88),
        SIMDE_FLOAT32_C(301248.41), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(381793.91), SIMDE_FLOAT32_C(  8649.13) } },
    { UINT8_C( 31),
      { SIMDE_FLOAT32_C(  -253.21), SIMDE_FLOAT32_C(  -637.65), SIMDE_FLOAT32_C(  -623.59), SIMDE_FLOAT32_C(   933.40),
        SIMDE_FLOAT32_C(  -575.76), SIMDE_FLOAT32_C(   563.65), SIMDE_FLOAT32_C(   492.89), SIMDE_FLOAT32_C(   365.91) },
      { SIMDE_FLOAT32_C(   218.13), SIMDE_FLOAT32_C(   493.78), SIMDE_FLOAT32_C(   709.40), SIMDE_FLOAT32_C(   757.39),
        SIMDE_FLOAT32_C(   599.96), SIMDE_FLOAT32_C(  -265.63), SIMDE_FLOAT32_C(   987.30), SIMDE_FLOAT32_C(   803.71) },
      { SIMDE_FLOAT32_C(  -839.70), SIMDE_FLOAT32_C(   602.53), SIMDE_FLOAT32_C(  -655.40), SIMDE_FLOAT32_C(   535.62),
        SIMDE_FLOAT32_C(  -823.73), SIMDE_FLOAT32_C(   655.27), SIMDE_FLOAT32_C(   291.58), SIMDE_FLOAT32_C(  -182.10) },
      { SIMDE_FLOAT32_C(-54393.00), SIMDE_FLOAT32_C(-315461.34), SIMDE_FLOAT32_C(-441719.38), SIMDE_FLOAT32_C(706412.25),
        SIMDE_FLOAT32_C(-344609.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(129),
      { SIMDE_FLOAT32_C(  -595.13), SIMDE_FLOAT32_C(   968.63), SIMDE_FLOAT32_C(    69.26), SIMDE_FLOAT32_C(  -384.65),
        SIMDE_FLOAT32_C(  -926.42), SIMDE_FLOAT32_C(  -358.05), SIMDE_FLOAT32_C(   362.14), SIMDE_FLOAT32_C(  -564.08) },
      { SIMDE_FLOAT32_C(    18.36), SIMDE_FLOAT32_C(   295.54), SIMDE_FLOAT32_C(  -139.84), SIMDE_FLOAT32_C(  -417.99),
        SIMDE_FLOAT32_C(  -211.57), SIMDE_FLOAT32_C(  -773.93), SIMDE_FLOAT32_C(   800.14), SIMDE_FLOAT32_C(  -717.79) },
      { SIMDE_FLOAT32_C(   935.47), SIMDE_FLOAT32_C(   557.52), SIMDE_FLOAT32_C(   882.18), SIMDE_FLOAT32_C(  -330.16),
        SIMDE_FLOAT32_C(   544.82), SIMDE_FLOAT32_C(   685.88), SIMDE_FLOAT32_C(  -169.86), SIMDE_FLOAT32_C(   147.36) },
      { SIMDE_FLOAT32_C(-11862.06), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(404743.62) } },
    { UINT8_C(135),
      { SIMDE_FLOAT32_C(  -634.24), SIMDE_FLOAT32_C(   323.62), SIMDE_FLOAT32_C(   685.75), SIMDE_FLOAT32_C(   657.33),
        SIMDE_FLOAT32_C(  -858.48), SIMDE_FLOAT32_C(  -654.22), SIMDE_FLOAT32_C(  -937.79), SIMDE_FLOAT32_C(  -889.85) },
      { SIMDE_FLOAT32_C(   415.04), SIMDE_FLOAT32_C(  -322.45), SIMDE_FLOAT32_C(  -816.27), SIMDE_FLOAT32_C(  -943.01),
        SIMDE_FLOAT32_C(  -960.31), SIMDE_FLOAT32_C(  -380.35), SIMDE_FLOAT32_C(    75.35), SIMDE_FLOAT32_C(   335.23) },
      { SIMDE_FLOAT32_C(   479.81), SIMDE_FLOAT32_C(   657.36), SIMDE_FLOAT32_C(  -876.33), SIMDE_FLOAT32_C(   705.88),
        SIMDE_FLOAT32_C(   457.50), SIMDE_FLOAT32_C(  -594.12), SIMDE_FLOAT32_C(   641.35), SIMDE_FLOAT32_C(    15.02) },
      { SIMDE_FLOAT32_C(-263714.78), SIMDE_FLOAT32_C(-105008.63), SIMDE_FLOAT32_C(-558880.81), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-298319.44) } },
    { UINT8_C(250),
      { SIMDE_FLOAT32_C(  -688.81), SIMDE_FLOAT32_C(  -440.15), SIMDE_FLOAT32_C(   973.94), SIMDE_FLOAT32_C(   141.33),
        SIMDE_FLOAT32_C(   707.20), SIMDE_FLOAT32_C(  -995.58), SIMDE_FLOAT32_C(   507.09), SIMDE_FLOAT32_C(    30.82) },
      { SIMDE_FLOAT32_C(   690.18), SIMDE_FLOAT32_C(   164.42), SIMDE_FLOAT32_C(   172.34), SIMDE_FLOAT32_C(  -964.04),
        SIMDE_FLOAT32_C(   226.62), SIMDE_FLOAT32_C(   282.50), SIMDE_FLOAT32_C(   451.00), SIMDE_FLOAT32_C(   904.18) },
      { SIMDE_FLOAT32_C(   466.22), SIMDE_FLOAT32_C(   507.99), SIMDE_FLOAT32_C(   943.87), SIMDE_FLOAT32_C(  -914.12),
        SIMDE_FLOAT32_C(  -416.66), SIMDE_FLOAT32_C(   279.10), SIMDE_FLOAT32_C(   565.69), SIMDE_FLOAT32_C(  -759.30) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-72877.45), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-135333.66),
        SIMDE_FLOAT32_C(160682.33), SIMDE_FLOAT32_C(-281530.47), SIMDE_FLOAT32_C(228131.89), SIMDE_FLOAT32_C( 28626.13) } },
    { UINT8_C( 26),
      { SIMDE_FLOAT32_C(   271.57), SIMDE_FLOAT32_C(   698.20), SIMDE_FLOAT32_C(   808.65), SIMDE_FLOAT32_C(   -87.07),
        SIMDE_FLOAT32_C(  -286.78), SIMDE_FLOAT32_C(  -903.30), SIMDE_FLOAT32_C(   224.12), SIMDE_FLOAT32_C(   273.06) },
      { SIMDE_FLOAT32_C(  -929.36), SIMDE_FLOAT32_C(  -634.55), SIMDE_FLOAT32_C(   -19.73), SIMDE_FLOAT32_C(  -924.93),
        SIMDE_FLOAT32_C(   872.54), SIMDE_FLOAT32_C(  -988.91), SIMDE_FLOAT32_C(   765.24), SIMDE_FLOAT32_C(    36.96) },
      { SIMDE_FLOAT32_C(   183.43), SIMDE_FLOAT32_C(   801.20), SIMDE_FLOAT32_C(  -736.42), SIMDE_FLOAT32_C(  -534.07),
        SIMDE_FLOAT32_C(   252.20), SIMDE_FLOAT32_C(  -832.24), SIMDE_FLOAT32_C(   932.15), SIMDE_FLOAT32_C(  -239.82) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-443844.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( 81067.73),
        SIMDE_FLOAT32_C(-250479.22), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(190),
      { SIMDE_FLOAT32_C(  -981.97), SIMDE_FLOAT32_C(   343.52), SIMDE_FLOAT32_C(   390.73), SIMDE_FLOAT32_C(   583.72),
        SIMDE_FLOAT32_C(   584.22), SIMDE_FLOAT32_C(  -206.50), SIMDE_FLOAT32_C(  -144.71), SIMDE_FLOAT32_C(   282.42) },
      { SIMDE_FLOAT32_C(  -397.85), SIMDE_FLOAT32_C(   768.21), SIMDE_FLOAT32_C(   995.64), SIMDE_FLOAT32_C(  -301.14),
        SIMDE_FLOAT32_C(    -7.67), SIMDE_FLOAT32_C(   268.70), SIMDE_FLOAT32_C(  -230.50), SIMDE_FLOAT32_C(   357.78) },
      { SIMDE_FLOAT32_C(  -751.04), SIMDE_FLOAT32_C(  -155.43), SIMDE_FLOAT32_C(   230.32), SIMDE_FLOAT32_C(  -739.94),
        SIMDE_FLOAT32_C(  -390.19), SIMDE_FLOAT32_C(  -732.72), SIMDE_FLOAT32_C(   443.49), SIMDE_FLOAT32_C(  -588.99) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(264050.94), SIMDE_FLOAT32_C(388796.12), SIMDE_FLOAT32_C(-175041.50),
        SIMDE_FLOAT32_C( -4090.78), SIMDE_FLOAT32_C(-54753.83), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(101633.22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 c = simde_mm256_loadu_ps(test_vec[i].c);
    simde__m256 r = simde_mm256_maskz_fmsub_ps(test_vec[i].k, a, b, c);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 c = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256 r = simde_mm256_maskz_fmsub_ps(k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask3_fmsub_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 c[4];
    const simde__mmask8 k;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   240.91), SIMDE_FLOAT32_C(   -54.50), SIMDE_FLOAT32_C(  -637.17), SIMDE_FLOAT32_C(   388.12) },
      { SIMDE_FLOAT32_C(  -792.37), SIMDE_FLOAT32_C(  -885.59), SIMDE_FLOAT32_C(   487.51), SIMDE_FLOAT32_C(   603.37) },
      { SIMDE_FLOAT32_C(  -728.21), SIMDE_FLOAT32_C(   576.82), SIMDE_FLOAT32_C(   999.18), SIMDE_FLOAT32_C(   128.93) },
      UINT8_C(152),
      { SIMDE_FLOAT32_C(  -728.21), SIMDE_FLOAT32_C(   576.82), SIMDE_FLOAT32_C(   999.18), SIMDE_FLOAT32_C(234051.03) } },
    { { SIMDE_FLOAT32_C(   465.73), SIMDE_FLOAT32_C(   515.39), SIMDE_FLOAT32_C(  -683.78), SIMDE_FLOAT32_C(   180.15) },
      { SIMDE_FLOAT32_C(  -414.45), SIMDE_FLOAT32_C(    47.55), SIMDE_FLOAT32_C(   164.21), SIMDE_FLOAT32_C(   638.68) },
      { SIMDE_FLOAT32_C(   124.40), SIMDE_FLOAT32_C(   -10.14), SIMDE_FLOAT32_C(  -750.03), SIMDE_FLOAT32_C(    99.19) },
      UINT8_C(232),
      { SIMDE_FLOAT32_C(   124.40), SIMDE_FLOAT32_C(   -10.14), SIMDE_FLOAT32_C(  -750.03), SIMDE_FLOAT32_C(114959.01) } },
    { { SIMDE_FLOAT32_C(   -96.47), SIMDE_FLOAT32_C(  -394.08), SIMDE_FLOAT32_C(   145.35), SIMDE_FLOAT32_C(   876.06) },
      { SIMDE_FLOAT32_C(   981.90), SIMDE_FLOAT32_C(  -613.74), SIMDE_FLOAT32_C(  -178.44), SIMDE_FLOAT32_C(  -655.27) },
      { SIMDE_FLOAT32_C(   774.38), SIMDE_FLOAT32_C(    29.19), SIMDE_FLOAT32_C(  -540.86), SIMDE_FLOAT32_C(   261.90) },
      UINT8_C(133),
      { SIMDE_FLOAT32_C(-95498.27), SIMDE_FLOAT32_C(    29.19), SIMDE_FLOAT32_C(-25395.39), SIMDE_FLOAT32_C(   261.90) } },
    { { SIMDE_FLOAT32_C(  -269.06), SIMDE_FLOAT32_C(  -161.29), SIMDE_FLOAT32_C(  -368.26), SIMDE_FLOAT32_C(   859.86) },
      { SIMDE_FLOAT32_C(   884.53), SIMDE_FLOAT32_C(  -902.54), SIMDE_FLOAT32_C(   375.25), SIMDE_FLOAT32_C(  -799.25) },
      { SIMDE_FLOAT32_C(   277.62), SIMDE_FLOAT32_C(   960.80), SIMDE_FLOAT32_C(   248.30), SIMDE_FLOAT32_C(  -558.17) },
      UINT8_C(228),
      { SIMDE_FLOAT32_C(   277.62), SIMDE_FLOAT32_C(   960.80), SIMDE_FLOAT32_C(-138437.88), SIMDE_FLOAT32_C(  -558.17) } },
    { { SIMDE_FLOAT32_C(  -627.30), SIMDE_FLOAT32_C(   431.69), SIMDE_FLOAT32_C(   849.45), SIMDE_FLOAT32_C(   471.89) },
      { SIMDE_FLOAT32_C(   633.66), SIMDE_FLOAT32_C(  -247.01), SIMDE_FLOAT32_C(  -922.19), SIMDE_FLOAT32_C(  -220.99) },
      { SIMDE_FLOAT32_C(  -370.95), SIMDE_FLOAT32_C(  -940.29), SIMDE_FLOAT32_C(   165.27), SIMDE_FLOAT32_C(   450.61) },
      UINT8_C(203),
      { SIMDE_FLOAT32_C(-397123.94), SIMDE_FLOAT32_C(-105691.45), SIMDE_FLOAT32_C(   165.27), SIMDE_FLOAT32_C(-104733.59) } },
    { { SIMDE_FLOAT32_C(   -60.34), SIMDE_FLOAT32_C(  -520.20), SIMDE_FLOAT32_C(  -136.42), SIMDE_FLOAT32_C(  -798.45) },
      { SIMDE_FLOAT32_C(   112.36), SIMDE_FLOAT32_C(   594.52), SIMDE_FLOAT32_C(    40.26), SIMDE_FLOAT32_C(   744.09) },
      { SIMDE_FLOAT32_C(   454.39), SIMDE_FLOAT32_C(   -75.20), SIMDE_FLOAT32_C(   841.56), SIMDE_FLOAT32_C(  -170.36) },
      UINT8_C(176),
      { SIMDE_FLOAT32_C(   454.39), SIMDE_FLOAT32_C(   -75.20), SIMDE_FLOAT32_C(   841.56), SIMDE_FLOAT32_C(  -170.36) } },
    { { SIMDE_FLOAT32_C(   119.18), SIMDE_FLOAT32_C(  -209.56), SIMDE_FLOAT32_C(  -626.16), SIMDE_FLOAT32_C(   561.00) },
      { SIMDE_FLOAT32_C(  -610.08), SIMDE_FLOAT32_C(  -253.46), SIMDE_FLOAT32_C(    -7.31), SIMDE_FLOAT32_C(  -760.62) },
      { SIMDE_FLOAT32_C(  -781.56), SIMDE_FLOAT32_C(  -373.65), SIMDE_FLOAT32_C(    -7.64), SIMDE_FLOAT32_C(  -703.75) },
      UINT8_C(104),
      { SIMDE_FLOAT32_C(  -781.56), SIMDE_FLOAT32_C(  -373.65), SIMDE_FLOAT32_C(    -7.64), SIMDE_FLOAT32_C(-426004.06) } },
    { { SIMDE_FLOAT32_C(   621.41), SIMDE_FLOAT32_C(  -644.04), SIMDE_FLOAT32_C(  -429.37), SIMDE_FLOAT32_C(    72.02) },
      { SIMDE_FLOAT32_C(  -239.60), SIMDE_FLOAT32_C(   510.28), SIMDE_FLOAT32_C(   551.82), SIMDE_FLOAT32_C(   623.98) },
      { SIMDE_FLOAT32_C(   711.83), SIMDE_FLOAT32_C(  -335.82), SIMDE_FLOAT32_C(   218.50), SIMDE_FLOAT32_C(  -247.90) },
      UINT8_C(135),
      { SIMDE_FLOAT32_C(-149601.66), SIMDE_FLOAT32_C(-328304.91), SIMDE_FLOAT32_C(-237153.45), SIMDE_FLOAT32_C(  -247.90) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 c = simde_mm_loadu_ps(test_vec[i].c);
    simde__m128 r = simde_mm_mask3_fmsub_ps(a, b, c, test_vec[i].k);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 c = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 r = simde_mm_mask3_fmsub_ps(a, b, c, k);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_fmsub_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde__mmask8 k;
    const simde_float32 b[4];
    const simde_float32 c[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -467.30), SIMDE_FLOAT32_C(   -97.89), SIMDE_FLOAT32_C(   613.57), SIMDE_FLOAT32_C(   530.60) },
      UINT8_C( 50),
      { SIMDE_FLOAT32_C(  -607.55), SIMDE_FLOAT32_C(  -702.66), SIMDE_FLOAT32_C(   709.68), SIMDE_FLOAT32_C(   121.97) },
      { SIMDE_FLOAT32_C(    76.84), SIMDE_FLOAT32_C(  -579.92), SIMDE_FLOAT32_C(  -412.78), SIMDE_FLOAT32_C(  -324.84) },
      { SIMDE_FLOAT32_C(  -467.30), SIMDE_FLOAT32_C( 69363.30), SIMDE_FLOAT32_C(   613.57), SIMDE_FLOAT32_C(   530.60) } },
    { { SIMDE_FLOAT32_C(   623.05), SIMDE_FLOAT32_C(   228.16), SIMDE_FLOAT32_C(   749.42), SIMDE_FLOAT32_C(  -113.00) },
      UINT8_C( 99),
      { SIMDE_FLOAT32_C(   474.58), SIMDE_FLOAT32_C(   621.99), SIMDE_FLOAT32_C(  -360.00), SIMDE_FLOAT32_C(  -226.66) },
      { SIMDE_FLOAT32_C(  -631.29), SIMDE_FLOAT32_C(   160.93), SIMDE_FLOAT32_C(   873.78), SIMDE_FLOAT32_C(   653.70) },
      { SIMDE_FLOAT32_C(296318.34), SIMDE_FLOAT32_C(141752.31), SIMDE_FLOAT32_C(   749.42), SIMDE_FLOAT32_C(  -113.00) } },
    { { SIMDE_FLOAT32_C(  -866.75), SIMDE_FLOAT32_C(  -352.64), SIMDE_FLOAT32_C(  -395.86), SIMDE_FLOAT32_C(  -884.71) },
      UINT8_C( 96),
      { SIMDE_FLOAT32_C(   136.84), SIMDE_FLOAT32_C(    17.40), SIMDE_FLOAT32_C(   376.10), SIMDE_FLOAT32_C(  -332.56) },
      { SIMDE_FLOAT32_C(  -337.18), SIMDE_FLOAT32_C(   768.55), SIMDE_FLOAT32_C(   -35.22), SIMDE_FLOAT32_C(  -627.50) },
      { SIMDE_FLOAT32_C(  -866.75), SIMDE_FLOAT32_C(  -352.64), SIMDE_FLOAT32_C(  -395.86), SIMDE_FLOAT32_C(  -884.71) } },
    { { SIMDE_FLOAT32_C(  -109.48), SIMDE_FLOAT32_C(  -958.37), SIMDE_FLOAT32_C(  -207.41), SIMDE_FLOAT32_C(   477.74) },
      UINT8_C(251),
      { SIMDE_FLOAT32_C(  -584.37), SIMDE_FLOAT32_C(  -294.09), SIMDE_FLOAT32_C(  -533.80), SIMDE_FLOAT32_C(   302.63) },
      { SIMDE_FLOAT32_C(   839.32), SIMDE_FLOAT32_C(   940.79), SIMDE_FLOAT32_C(   -75.39), SIMDE_FLOAT32_C(  -520.68) },
      { SIMDE_FLOAT32_C( 63137.51), SIMDE_FLOAT32_C(280906.25), SIMDE_FLOAT32_C(  -207.41), SIMDE_FLOAT32_C(145099.14) } },
    { { SIMDE_FLOAT32_C(  -285.88), SIMDE_FLOAT32_C(   293.32), SIMDE_FLOAT32_C(   640.24), SIMDE_FLOAT32_C(  -412.09) },
      UINT8_C(194),
      { SIMDE_FLOAT32_C(   773.49), SIMDE_FLOAT32_C(   235.27), SIMDE_FLOAT32_C(   551.16), SIMDE_FLOAT32_C(   888.78) },
      { SIMDE_FLOAT32_C(    -2.20), SIMDE_FLOAT32_C(  -312.00), SIMDE_FLOAT32_C(   -93.83), SIMDE_FLOAT32_C(  -626.10) },
      { SIMDE_FLOAT32_C(  -285.88), SIMDE_FLOAT32_C( 69321.40), SIMDE_FLOAT32_C(   640.24), SIMDE_FLOAT32_C(  -412.09) } },
    { { SIMDE_FLOAT32_C(   355.44), SIMDE_FLOAT32_C(   569.00), SIMDE_FLOAT32_C(  -857.55), SIMDE_FLOAT32_C(  -679.77) },
      UINT8_C(216),
      { SIMDE_FLOAT32_C(    32.97), SIMDE_FLOAT32_C(  -638.15), SIMDE_FLOAT32_C(  -265.91), SIMDE_FLOAT32_C(  -489.28) },
      { SIMDE_FLOAT32_C(    78.64), SIMDE_FLOAT32_C(   149.72), SIMDE_FLOAT32_C(   216.62), SIMDE_FLOAT32_C(   544.84) },
      { SIMDE_FLOAT32_C(   355.44), SIMDE_FLOAT32_C(   569.00), SIMDE_FLOAT32_C(  -857.55), SIMDE_FLOAT32_C(332053.03) } },
    { { SIMDE_FLOAT32_C(  -547.66), SIMDE_FLOAT32_C(    55.95), SIMDE_FLOAT32_C(   485.63), SIMDE_FLOAT32_C(   376.96) },
      UINT8_C(205),
      { SIMDE_FLOAT32_C(  -800.25), SIMDE_FLOAT32_C(  -329.72), SIMDE_FLOAT32_C(   175.51), SIMDE_FLOAT32_C(  -212.34) },
      { SIMDE_FLOAT32_C(   617.30), SIMDE_FLOAT32_C(   -51.00), SIMDE_FLOAT32_C(  -977.07), SIMDE_FLOAT32_C(   168.46) },
      { SIMDE_FLOAT32_C(437647.59), SIMDE_FLOAT32_C(    55.95), SIMDE_FLOAT32_C( 86209.99), SIMDE_FLOAT32_C(-80212.14) } },
    { { SIMDE_FLOAT32_C(  -162.22), SIMDE_FLOAT32_C(    20.73), SIMDE_FLOAT32_C(   856.47), SIMDE_FLOAT32_C(   743.95) },
      UINT8_C(134),
      { SIMDE_FLOAT32_C(   211.91), SIMDE_FLOAT32_C(   312.95), SIMDE_FLOAT32_C(   537.08), SIMDE_FLOAT32_C(   532.14) },
      { SIMDE_FLOAT32_C(   254.45), SIMDE_FLOAT32_C(  -429.95), SIMDE_FLOAT32_C(   893.99), SIMDE_FLOAT32_C(   988.53) },
      { SIMDE_FLOAT32_C(  -162.22), SIMDE_FLOAT32_C(  6917.40), SIMDE_FLOAT32_C(459098.91), SIMDE_FLOAT32_C(   743.95) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 c = simde_mm_loadu_ps(test_vec[i].c);
    simde__m128 r = simde_mm_mask_fmsub_ps(a, test_vec[i].k, b, c);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 c = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 r = simde_mm_mask_fmsub_ps(a, k, b, c);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_fmsub_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 c[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(156),
      { SIMDE_FLOAT32_C(   917.71), SIMDE_FLOAT32_C(    74.36), SIMDE_FLOAT32_C(  -951.19), SIMDE_FLOAT32_C(  -856.64) },
      { SIMDE_FLOAT32_C(   344.94), SIMDE_FLOAT32_C(   345.27), SIMDE_FLOAT32_C(  -815.67), SIMDE_FLOAT32_C(   154.88) },
      { SIMDE_FLOAT32_C(   515.87), SIMDE_FLOAT32_C(  -190.94), SIMDE_FLOAT32_C(  -775.96), SIMDE_FLOAT32_C(  -306.64) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(776633.06), SIMDE_FLOAT32_C(-132369.77) } },
    { UINT8_C(211),
      { SIMDE_FLOAT32_C(  -299.56), SIMDE_FLOAT32_C(  -428.64), SIMDE_FLOAT32_C(  -152.45), SIMDE_FLOAT32_C(   -15.13) },
      { SIMDE_FLOAT32_C(  -343.82), SIMDE_FLOAT32_C(  -484.97), SIMDE_FLOAT32_C(   189.45), SIMDE_FLOAT32_C(  -897.15) },
      { SIMDE_FLOAT32_C(   661.07), SIMDE_FLOAT32_C(  -705.49), SIMDE_FLOAT32_C(   153.63), SIMDE_FLOAT32_C(  -846.44) },
      { SIMDE_FLOAT32_C(102333.65), SIMDE_FLOAT32_C(208583.03), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(250),
      { SIMDE_FLOAT32_C(   609.45), SIMDE_FLOAT32_C(   278.71), SIMDE_FLOAT32_C(  -466.57), SIMDE_FLOAT32_C(   -54.72) },
      { SIMDE_FLOAT32_C(  -107.34), SIMDE_FLOAT32_C(  -548.86), SIMDE_FLOAT32_C(  -980.36), SIMDE_FLOAT32_C(   -58.53) },
      { SIMDE_FLOAT32_C(  -405.51), SIMDE_FLOAT32_C(   364.58), SIMDE_FLOAT32_C(  -713.26), SIMDE_FLOAT32_C(  -221.17) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-153337.34), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  3423.93) } },
    { UINT8_C( 20),
      { SIMDE_FLOAT32_C(   802.61), SIMDE_FLOAT32_C(   587.88), SIMDE_FLOAT32_C(  -256.50), SIMDE_FLOAT32_C(  -504.02) },
      { SIMDE_FLOAT32_C(  -353.28), SIMDE_FLOAT32_C(   443.94), SIMDE_FLOAT32_C(    67.33), SIMDE_FLOAT32_C(   494.27) },
      { SIMDE_FLOAT32_C(  -571.18), SIMDE_FLOAT32_C(   723.51), SIMDE_FLOAT32_C(  -990.70), SIMDE_FLOAT32_C(   618.26) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-16279.45), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 50),
      { SIMDE_FLOAT32_C(   670.36), SIMDE_FLOAT32_C(   912.78), SIMDE_FLOAT32_C(   -20.02), SIMDE_FLOAT32_C(   823.92) },
      { SIMDE_FLOAT32_C(   843.54), SIMDE_FLOAT32_C(  -410.57), SIMDE_FLOAT32_C(   102.63), SIMDE_FLOAT32_C(  -623.02) },
      { SIMDE_FLOAT32_C(   534.71), SIMDE_FLOAT32_C(   995.30), SIMDE_FLOAT32_C(  -171.89), SIMDE_FLOAT32_C(   554.35) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-375755.41), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(172),
      { SIMDE_FLOAT32_C(   422.61), SIMDE_FLOAT32_C(   -81.07), SIMDE_FLOAT32_C(   223.51), SIMDE_FLOAT32_C(  -798.56) },
      { SIMDE_FLOAT32_C(   438.40), SIMDE_FLOAT32_C(    26.12), SIMDE_FLOAT32_C(   789.32), SIMDE_FLOAT32_C(  -818.10) },
      { SIMDE_FLOAT32_C(   522.09), SIMDE_FLOAT32_C(  -563.96), SIMDE_FLOAT32_C(   625.85), SIMDE_FLOAT32_C(  -410.57) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(175795.06), SIMDE_FLOAT32_C(653712.50) } },
    { UINT8_C( 18),
      { SIMDE_FLOAT32_C(  -945.33), SIMDE_FLOAT32_C(  -687.07), SIMDE_FLOAT32_C(   939.60), SIMDE_FLOAT32_C(   672.93) },
      { SIMDE_FLOAT32_C(  -860.71), SIMDE_FLOAT32_C(   609.96), SIMDE_FLOAT32_C(   585.71), SIMDE_FLOAT32_C(   119.27) },
      { SIMDE_FLOAT32_C(   433.89), SIMDE_FLOAT32_C(   429.25), SIMDE_FLOAT32_C(   708.70), SIMDE_FLOAT32_C(  -463.48) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-419514.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(  5),
      { SIMDE_FLOAT32_C(   243.41), SIMDE_FLOAT32_C(  -468.18), SIMDE_FLOAT32_C(  -365.66), SIMDE_FLOAT32_C(  -202.24) },
      { SIMDE_FLOAT32_C(   468.58), SIMDE_FLOAT32_C(  -943.05), SIMDE_FLOAT32_C(   716.69), SIMDE_FLOAT32_C(  -307.91) },
      { SIMDE_FLOAT32_C(  -741.62), SIMDE_FLOAT32_C(   155.09), SIMDE_FLOAT32_C(   718.21), SIMDE_FLOAT32_C(  -952.30) },
      { SIMDE_FLOAT32_C(114798.68), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-262783.09), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 c = simde_mm_loadu_ps(test_vec[i].c);
    simde__m128 r = simde_mm_maskz_fmsub_ps(test_vec[i].k, a, b, c);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 c = simde_test_x86_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128 r = simde_mm_maskz_fmsub_ps(k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_fmsub_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 c[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    39.18), SIMDE_FLOAT32_C(    72.95), SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(   -99.28),
        SIMDE_FLOAT32_C(   -27.76), SIMDE_FLOAT32_C(    78.92), SIMDE_FLOAT32_C(    97.46), SIMDE_FLOAT32_C(   -75.13),
        SIMDE_FLOAT32_C(   -78.86), SIMDE_FLOAT32_C(    62.73), SIMDE_FLOAT32_C(    46.15), SIMDE_FLOAT32_C(   -15.69),
        SIMDE_FLOAT32_C(   -66.26), SIMDE_FLOAT32_C(    -2.97), SIMDE_FLOAT32_C(    64.58), SIMDE_FLOAT32_C(   -96.46) },
      { SIMDE_FLOAT32_C(    87.93), SIMDE_FLOAT32_C(   -57.28), SIMDE_FLOAT32_C(   -38.98), SIMDE_FLOAT32_C(    16.76),
        SIMDE_FLOAT32_C(    -7.19), SIMDE_FLOAT32_C(   -49.24), SIMDE_FLOAT32_C(   -45.18), SIMDE_FLOAT32_C(    16.45),
        SIMDE_FLOAT32_C(   -68.84), SIMDE_FLOAT32_C(   -51.68), SIMDE_FLOAT32_C(    46.34), SIMDE_FLOAT32_C(    24.50),
        SIMDE_FLOAT32_C(   -28.63), SIMDE_FLOAT32_C(   -74.05), SIMDE_FLOAT32_C(   -21.93), SIMDE_FLOAT32_C(   -89.45) },
      { SIMDE_FLOAT32_C(    98.91), SIMDE_FLOAT32_C(    80.47), SIMDE_FLOAT32_C(   -88.73), SIMDE_FLOAT32_C(   -28.86),
        SIMDE_FLOAT32_C(    59.39), SIMDE_FLOAT32_C(   -91.27), SIMDE_FLOAT32_C(    -3.99), SIMDE_FLOAT32_C(    80.52),
        SIMDE_FLOAT32_C(    71.46), SIMDE_FLOAT32_C(   -57.84), SIMDE_FLOAT32_C(   -35.17), SIMDE_FLOAT32_C(   -94.81),
        SIMDE_FLOAT32_C(    39.19), SIMDE_FLOAT32_C(   -70.59), SIMDE_FLOAT32_C(   -91.26), SIMDE_FLOAT32_C(    27.12) },
      { SIMDE_FLOAT32_C(  3346.19), SIMDE_FLOAT32_C( -4259.05), SIMDE_FLOAT32_C(    -4.43), SIMDE_FLOAT32_C( -1635.07),
        SIMDE_FLOAT32_C(   140.20), SIMDE_FLOAT32_C( -3794.75), SIMDE_FLOAT32_C( -4399.25), SIMDE_FLOAT32_C( -1316.41),
        SIMDE_FLOAT32_C(  5357.26), SIMDE_FLOAT32_C( -3184.05), SIMDE_FLOAT32_C(  2173.76), SIMDE_FLOAT32_C(  -289.60),
        SIMDE_FLOAT32_C(  1857.83), SIMDE_FLOAT32_C(   290.52), SIMDE_FLOAT32_C( -1324.98), SIMDE_FLOAT32_C(  8601.23) } },
    { { SIMDE_FLOAT32_C(   -27.87), SIMDE_FLOAT32_C(   -30.25), SIMDE_FLOAT32_C(   -56.12), SIMDE_FLOAT32_C(    64.94),
        SIMDE_FLOAT32_C(    20.51), SIMDE_FLOAT32_C(    -1.30), SIMDE_FLOAT32_C(   -18.61), SIMDE_FLOAT32_C(    51.67),
        SIMDE_FLOAT32_C(    47.02), SIMDE_FLOAT32_C(   -72.27), SIMDE_FLOAT32_C(   -23.83), SIMDE_FLOAT32_C(   -81.60),
        SIMDE_FLOAT32_C(   -46.31), SIMDE_FLOAT32_C(    54.24), SIMDE_FLOAT32_C(   -71.05), SIMDE_FLOAT32_C(   -47.41) },
      { SIMDE_FLOAT32_C(    34.71), SIMDE_FLOAT32_C(   -59.79), SIMDE_FLOAT32_C(    23.73), SIMDE_FLOAT32_C(    -5.90),
        SIMDE_FLOAT32_C(   -51.06), SIMDE_FLOAT32_C(   -80.26), SIMDE_FLOAT32_C(   -25.38), SIMDE_FLOAT32_C(   -79.60),
        SIMDE_FLOAT32_C(   -38.10), SIMDE_FLOAT32_C(    39.45), SIMDE_FLOAT32_C(   -74.41), SIMDE_FLOAT32_C(   -98.91),
        SIMDE_FLOAT32_C(    68.87), SIMDE_FLOAT32_C(   -65.67), SIMDE_FLOAT32_C(    28.21), SIMDE_FLOAT32_C(   -59.01) },
      { SIMDE_FLOAT32_C(     4.08), SIMDE_FLOAT32_C(    72.09), SIMDE_FLOAT32_C(   -94.06), SIMDE_FLOAT32_C(   -75.41),
        SIMDE_FLOAT32_C(   -29.20), SIMDE_FLOAT32_C(   -12.67), SIMDE_FLOAT32_C(    76.26), SIMDE_FLOAT32_C(   -82.18),
        SIMDE_FLOAT32_C(    15.06), SIMDE_FLOAT32_C(   -47.57), SIMDE_FLOAT32_C(   -63.79), SIMDE_FLOAT32_C(    68.75),
        SIMDE_FLOAT32_C(   -93.33), SIMDE_FLOAT32_C(   -34.84), SIMDE_FLOAT32_C(   -78.66), SIMDE_FLOAT32_C(    41.38) },
      { SIMDE_FLOAT32_C(  -971.45), SIMDE_FLOAT32_C(  1736.56), SIMDE_FLOAT32_C( -1237.67), SIMDE_FLOAT32_C(  -307.74),
        SIMDE_FLOAT32_C( -1018.04), SIMDE_FLOAT32_C(   117.01), SIMDE_FLOAT32_C(   396.06), SIMDE_FLOAT32_C( -4030.75),
        SIMDE_FLOAT32_C( -1806.52), SIMDE_FLOAT32_C( -2803.48), SIMDE_FLOAT32_C(  1836.98), SIMDE_FLOAT32_C(  8002.31),
        SIMDE_FLOAT32_C( -3096.04), SIMDE_FLOAT32_C( -3527.10), SIMDE_FLOAT32_C( -1925.66), SIMDE_FLOAT32_C(  2756.28) } },
    { { SIMDE_FLOAT32_C(     5.37), SIMDE_FLOAT32_C(    45.08), SIMDE_FLOAT32_C(   -64.53), SIMDE_FLOAT32_C(    54.31),
        SIMDE_FLOAT32_C(    64.82), SIMDE_FLOAT32_C(    10.09), SIMDE_FLOAT32_C(    74.71), SIMDE_FLOAT32_C(   -73.28),
        SIMDE_FLOAT32_C(   -50.46), SIMDE_FLOAT32_C(   -99.70), SIMDE_FLOAT32_C(   -72.19), SIMDE_FLOAT32_C(   -81.59),
        SIMDE_FLOAT32_C(   -65.37), SIMDE_FLOAT32_C(    56.02), SIMDE_FLOAT32_C(   -40.60), SIMDE_FLOAT32_C(    38.71) },
      { SIMDE_FLOAT32_C(    28.11), SIMDE_FLOAT32_C(   -34.66), SIMDE_FLOAT32_C(    63.29), SIMDE_FLOAT32_C(    98.90),
        SIMDE_FLOAT32_C(    52.67), SIMDE_FLOAT32_C(    39.55), SIMDE_FLOAT32_C(   -83.28), SIMDE_FLOAT32_C(   -32.27),
        SIMDE_FLOAT32_C(    91.98), SIMDE_FLOAT32_C(   -47.07), SIMDE_FLOAT32_C(   -63.52), SIMDE_FLOAT32_C(    98.65),
        SIMDE_FLOAT32_C(    18.09), SIMDE_FLOAT32_C(   -42.18), SIMDE_FLOAT32_C(    40.03), SIMDE_FLOAT32_C(   -76.54) },
      { SIMDE_FLOAT32_C(   -97.10), SIMDE_FLOAT32_C(    75.50), SIMDE_FLOAT32_C(    77.78), SIMDE_FLOAT32_C(    67.71),
        SIMDE_FLOAT32_C(   -14.41), SIMDE_FLOAT32_C(    52.49), SIMDE_FLOAT32_C(    94.43), SIMDE_FLOAT32_C(    35.13),
        SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(   -77.76), SIMDE_FLOAT32_C(    53.54), SIMDE_FLOAT32_C(    87.41),
        SIMDE_FLOAT32_C(    78.26), SIMDE_FLOAT32_C(   -87.05), SIMDE_FLOAT32_C(    26.12), SIMDE_FLOAT32_C(     6.37) },
      { SIMDE_FLOAT32_C(   248.05), SIMDE_FLOAT32_C( -1637.97), SIMDE_FLOAT32_C( -4161.88), SIMDE_FLOAT32_C(  5303.55),
        SIMDE_FLOAT32_C(  3428.48), SIMDE_FLOAT32_C(   346.57), SIMDE_FLOAT32_C( -6316.28), SIMDE_FLOAT32_C(  2329.62),
        SIMDE_FLOAT32_C( -4694.10), SIMDE_FLOAT32_C(  4770.64), SIMDE_FLOAT32_C(  4531.97), SIMDE_FLOAT32_C( -8136.26),
        SIMDE_FLOAT32_C( -1260.80), SIMDE_FLOAT32_C( -2275.87), SIMDE_FLOAT32_C( -1651.34), SIMDE_FLOAT32_C( -2969.23) } },
    { { SIMDE_FLOAT32_C(   -21.71), SIMDE_FLOAT32_C(   -10.59), SIMDE_FLOAT32_C(     5.27), SIMDE_FLOAT32_C(   -69.04),
        SIMDE_FLOAT32_C(   -71.03), SIMDE_FLOAT32_C(    22.00), SIMDE_FLOAT32_C(    -1.31), SIMDE_FLOAT32_C(   -79.05),
        SIMDE_FLOAT32_C(    74.93), SIMDE_FLOAT32_C(    35.16), SIMDE_FLOAT32_C(   -80.40), SIMDE_FLOAT32_C(    -6.98),
        SIMDE_FLOAT32_C(    92.98), SIMDE_FLOAT32_C(    59.62), SIMDE_FLOAT32_C(    16.48), SIMDE_FLOAT32_C(    95.88) },
      { SIMDE_FLOAT32_C(    35.12), SIMDE_FLOAT32_C(    -5.74), SIMDE_FLOAT32_C(    63.59), SIMDE_FLOAT32_C(   -79.29),
        SIMDE_FLOAT32_C(   -53.25), SIMDE_FLOAT32_C(    58.02), SIMDE_FLOAT32_C(    55.85), SIMDE_FLOAT32_C(    99.54),
        SIMDE_FLOAT32_C(    80.26), SIMDE_FLOAT32_C(     9.39), SIMDE_FLOAT32_C(    86.95), SIMDE_FLOAT32_C(    58.52),
        SIMDE_FLOAT32_C(    22.34), SIMDE_FLOAT32_C(    13.07), SIMDE_FLOAT32_C(   -35.11), SIMDE_FLOAT32_C(   -99.37) },
      { SIMDE_FLOAT32_C(   -97.51), SIMDE_FLOAT32_C(    70.17), SIMDE_FLOAT32_C(   -68.42), SIMDE_FLOAT32_C(   -68.55),
        SIMDE_FLOAT32_C(    -7.84), SIMDE_FLOAT32_C(    30.27), SIMDE_FLOAT32_C(   -47.60), SIMDE_FLOAT32_C(   -32.91),
        SIMDE_FLOAT32_C(   -34.57), SIMDE_FLOAT32_C(   -28.00), SIMDE_FLOAT32_C(    60.11), SIMDE_FLOAT32_C(   -41.59),
        SIMDE_FLOAT32_C(   -68.38), SIMDE_FLOAT32_C(   -23.41), SIMDE_FLOAT32_C(   -45.71), SIMDE_FLOAT32_C(    66.75) },
      { SIMDE_FLOAT32_C(  -664.95), SIMDE_FLOAT32_C(    -9.38), SIMDE_FLOAT32_C(   403.54), SIMDE_FLOAT32_C(  5542.73),
        SIMDE_FLOAT32_C(  3790.19), SIMDE_FLOAT32_C(  1246.17), SIMDE_FLOAT32_C(   -25.56), SIMDE_FLOAT32_C( -7835.73),
        SIMDE_FLOAT32_C(  6048.45), SIMDE_FLOAT32_C(   358.15), SIMDE_FLOAT32_C( -7050.89), SIMDE_FLOAT32_C(  -366.88),
        SIMDE_FLOAT32_C(  2145.55), SIMDE_FLOAT32_C(   802.64), SIMDE_FLOAT32_C(  -532.90), SIMDE_FLOAT32_C( -9594.35) } },
    { { SIMDE_FLOAT32_C(    70.85), SIMDE_FLOAT32_C(   -82.11), SIMDE_FLOAT32_C(    87.46), SIMDE_FLOAT32_C(   -82.40),
        SIMDE_FLOAT32_C(    75.91), SIMDE_FLOAT32_C(    43.31), SIMDE_FLOAT32_C(   -82.86), SIMDE_FLOAT32_C(    56.17),
        SIMDE_FLOAT32_C(   -47.30), SIMDE_FLOAT32_C(   -95.91), SIMDE_FLOAT32_C(    14.69), SIMDE_FLOAT32_C(    75.04),
        SIMDE_FLOAT32_C(    17.16), SIMDE_FLOAT32_C(    79.59), SIMDE_FLOAT32_C(    75.66), SIMDE_FLOAT32_C(    19.64) },
      { SIMDE_FLOAT32_C(    49.75), SIMDE_FLOAT32_C(   -92.75), SIMDE_FLOAT32_C(    51.10), SIMDE_FLOAT32_C(   -58.08),
        SIMDE_FLOAT32_C(    37.51), SIMDE_FLOAT32_C(   -96.50), SIMDE_FLOAT32_C(     9.01), SIMDE_FLOAT32_C(   -97.06),
        SIMDE_FLOAT32_C(   -24.50), SIMDE_FLOAT32_C(   -30.88), SIMDE_FLOAT32_C(   -38.64), SIMDE_FLOAT32_C(     7.12),
        SIMDE_FLOAT32_C(    45.71), SIMDE_FLOAT32_C(    15.65), SIMDE_FLOAT32_C(   -26.14), SIMDE_FLOAT32_C(    16.56) },
      { SIMDE_FLOAT32_C(    33.54), SIMDE_FLOAT32_C(   -38.68), SIMDE_FLOAT32_C(    34.16), SIMDE_FLOAT32_C(     9.45),
        SIMDE_FLOAT32_C(   -95.37), SIMDE_FLOAT32_C(    51.30), SIMDE_FLOAT32_C(   -34.38), SIMDE_FLOAT32_C(   -42.67),
        SIMDE_FLOAT32_C(    55.39), SIMDE_FLOAT32_C(    80.31), SIMDE_FLOAT32_C(   -67.64), SIMDE_FLOAT32_C(   -27.46),
        SIMDE_FLOAT32_C(    59.90), SIMDE_FLOAT32_C(   -91.97), SIMDE_FLOAT32_C(    92.19), SIMDE_FLOAT32_C(     9.65) },
      { SIMDE_FLOAT32_C(  3491.25), SIMDE_FLOAT32_C(  7654.38), SIMDE_FLOAT32_C(  4435.05), SIMDE_FLOAT32_C(  4776.34),
        SIMDE_FLOAT32_C(  2942.75), SIMDE_FLOAT32_C( -4230.71), SIMDE_FLOAT32_C(  -712.19), SIMDE_FLOAT32_C( -5409.19),
        SIMDE_FLOAT32_C(  1103.46), SIMDE_FLOAT32_C(  2881.39), SIMDE_FLOAT32_C(  -499.98), SIMDE_FLOAT32_C(   561.74),
        SIMDE_FLOAT32_C(   724.48), SIMDE_FLOAT32_C(  1337.55), SIMDE_FLOAT32_C( -2069.94), SIMDE_FLOAT32_C(   315.59) } },
    { { SIMDE_FLOAT32_C(   -84.73), SIMDE_FLOAT32_C(    43.28), SIMDE_FLOAT32_C(    51.57), SIMDE_FLOAT32_C(    52.79),
        SIMDE_FLOAT32_C(    46.78), SIMDE_FLOAT32_C(   -39.42), SIMDE_FLOAT32_C(    55.73), SIMDE_FLOAT32_C(   -77.72),
        SIMDE_FLOAT32_C(    29.69), SIMDE_FLOAT32_C(   -82.91), SIMDE_FLOAT32_C(    29.40), SIMDE_FLOAT32_C(   -24.60),
        SIMDE_FLOAT32_C(    32.74), SIMDE_FLOAT32_C(   -96.74), SIMDE_FLOAT32_C(    91.96), SIMDE_FLOAT32_C(   -33.72) },
      { SIMDE_FLOAT32_C(   -35.42), SIMDE_FLOAT32_C(    26.13), SIMDE_FLOAT32_C(    75.73), SIMDE_FLOAT32_C(   -30.79),
        SIMDE_FLOAT32_C(   -22.57), SIMDE_FLOAT32_C(   -58.65), SIMDE_FLOAT32_C(    26.54), SIMDE_FLOAT32_C(   -67.19),
        SIMDE_FLOAT32_C(   -78.34), SIMDE_FLOAT32_C(    58.90), SIMDE_FLOAT32_C(     5.36), SIMDE_FLOAT32_C(    81.57),
        SIMDE_FLOAT32_C(    66.92), SIMDE_FLOAT32_C(    -2.46), SIMDE_FLOAT32_C(    -8.78), SIMDE_FLOAT32_C(    82.20) },
      { SIMDE_FLOAT32_C(   -59.17), SIMDE_FLOAT32_C(   -57.21), SIMDE_FLOAT32_C(    34.98), SIMDE_FLOAT32_C(    87.61),
        SIMDE_FLOAT32_C(     3.36), SIMDE_FLOAT32_C(    -9.29), SIMDE_FLOAT32_C(   -90.11), SIMDE_FLOAT32_C(   -66.95),
        SIMDE_FLOAT32_C(     7.80), SIMDE_FLOAT32_C(    39.28), SIMDE_FLOAT32_C(     8.46), SIMDE_FLOAT32_C(   -59.46),
        SIMDE_FLOAT32_C(    42.54), SIMDE_FLOAT32_C(     0.42), SIMDE_FLOAT32_C(     6.82), SIMDE_FLOAT32_C(   -92.87) },
      { SIMDE_FLOAT32_C(  3060.31), SIMDE_FLOAT32_C(  1188.12), SIMDE_FLOAT32_C(  3870.42), SIMDE_FLOAT32_C( -1713.01),
        SIMDE_FLOAT32_C( -1059.18), SIMDE_FLOAT32_C(  2321.27), SIMDE_FLOAT32_C(  1569.18), SIMDE_FLOAT32_C(  5288.96),
        SIMDE_FLOAT32_C( -2333.71), SIMDE_FLOAT32_C( -4922.68), SIMDE_FLOAT32_C(   149.12), SIMDE_FLOAT32_C( -1947.16),
        SIMDE_FLOAT32_C(  2148.42), SIMDE_FLOAT32_C(   237.56), SIMDE_FLOAT32_C(  -814.23), SIMDE_FLOAT32_C( -2678.91) } },
    { { SIMDE_FLOAT32_C(   -73.46), SIMDE_FLOAT32_C(   -17.45), SIMDE_FLOAT32_C(   -23.66), SIMDE_FLOAT32_C(     3.97),
        SIMDE_FLOAT32_C(    23.90), SIMDE_FLOAT32_C(   -97.13), SIMDE_FLOAT32_C(    36.78), SIMDE_FLOAT32_C(    45.56),
        SIMDE_FLOAT32_C(    61.77), SIMDE_FLOAT32_C(   -57.86), SIMDE_FLOAT32_C(    27.13), SIMDE_FLOAT32_C(    28.69),
        SIMDE_FLOAT32_C(    39.68), SIMDE_FLOAT32_C(   -81.65), SIMDE_FLOAT32_C(    10.89), SIMDE_FLOAT32_C(    80.51) },
      { SIMDE_FLOAT32_C(   -38.86), SIMDE_FLOAT32_C(   -54.13), SIMDE_FLOAT32_C(    68.12), SIMDE_FLOAT32_C(    64.50),
        SIMDE_FLOAT32_C(    36.58), SIMDE_FLOAT32_C(    78.01), SIMDE_FLOAT32_C(    97.56), SIMDE_FLOAT32_C(   -55.62),
        SIMDE_FLOAT32_C(    17.29), SIMDE_FLOAT32_C(     6.01), SIMDE_FLOAT32_C(   -15.08), SIMDE_FLOAT32_C(   -40.17),
        SIMDE_FLOAT32_C(   -93.57), SIMDE_FLOAT32_C(    91.74), SIMDE_FLOAT32_C(   -33.04), SIMDE_FLOAT32_C(   -67.03) },
      { SIMDE_FLOAT32_C(   -25.71), SIMDE_FLOAT32_C(    43.29), SIMDE_FLOAT32_C(    36.94), SIMDE_FLOAT32_C(    98.19),
        SIMDE_FLOAT32_C(    46.17), SIMDE_FLOAT32_C(   -26.28), SIMDE_FLOAT32_C(    43.76), SIMDE_FLOAT32_C(     7.94),
        SIMDE_FLOAT32_C(    15.86), SIMDE_FLOAT32_C(   -29.11), SIMDE_FLOAT32_C(   -63.37), SIMDE_FLOAT32_C(   -44.46),
        SIMDE_FLOAT32_C(   -10.77), SIMDE_FLOAT32_C(    47.52), SIMDE_FLOAT32_C(   -63.95), SIMDE_FLOAT32_C(    50.37) },
      { SIMDE_FLOAT32_C(  2880.37), SIMDE_FLOAT32_C(   901.28), SIMDE_FLOAT32_C( -1648.66), SIMDE_FLOAT32_C(   157.88),
        SIMDE_FLOAT32_C(   828.09), SIMDE_FLOAT32_C( -7550.83), SIMDE_FLOAT32_C(  3544.50), SIMDE_FLOAT32_C( -2541.99),
        SIMDE_FLOAT32_C(  1052.14), SIMDE_FLOAT32_C(  -318.63), SIMDE_FLOAT32_C(  -345.75), SIMDE_FLOAT32_C( -1108.02),
        SIMDE_FLOAT32_C( -3702.09), SIMDE_FLOAT32_C( -7538.09), SIMDE_FLOAT32_C(  -295.86), SIMDE_FLOAT32_C( -5446.96) } },
    { { SIMDE_FLOAT32_C(    93.39), SIMDE_FLOAT32_C(   -95.84), SIMDE_FLOAT32_C(    14.87), SIMDE_FLOAT32_C(    29.97),
        SIMDE_FLOAT32_C(    82.17), SIMDE_FLOAT32_C(    12.43), SIMDE_FLOAT32_C(    74.35), SIMDE_FLOAT32_C(    -0.54),
        SIMDE_FLOAT32_C(   -81.56), SIMDE_FLOAT32_C(   -40.72), SIMDE_FLOAT32_C(    59.29), SIMDE_FLOAT32_C(   -75.13),
        SIMDE_FLOAT32_C(   -48.98), SIMDE_FLOAT32_C(   -73.75), SIMDE_FLOAT32_C(   -42.16), SIMDE_FLOAT32_C(    25.31) },
      { SIMDE_FLOAT32_C(    69.55), SIMDE_FLOAT32_C(    94.78), SIMDE_FLOAT32_C(    23.51), SIMDE_FLOAT32_C(    15.71),
        SIMDE_FLOAT32_C(   -31.49), SIMDE_FLOAT32_C(   -32.74), SIMDE_FLOAT32_C(   -76.35), SIMDE_FLOAT32_C(    84.37),
        SIMDE_FLOAT32_C(    38.15), SIMDE_FLOAT32_C(   -39.72), SIMDE_FLOAT32_C(   -60.09), SIMDE_FLOAT32_C(   -72.62),
        SIMDE_FLOAT32_C(   -92.20), SIMDE_FLOAT32_C(   -24.04), SIMDE_FLOAT32_C(    77.76), SIMDE_FLOAT32_C(   -98.81) },
      { SIMDE_FLOAT32_C(   -19.88), SIMDE_FLOAT32_C(    -7.37), SIMDE_FLOAT32_C(    31.16), SIMDE_FLOAT32_C(   -37.71),
        SIMDE_FLOAT32_C(   -94.94), SIMDE_FLOAT32_C(     5.51), SIMDE_FLOAT32_C(    61.75), SIMDE_FLOAT32_C(   -76.50),
        SIMDE_FLOAT32_C(    64.79), SIMDE_FLOAT32_C(    21.04), SIMDE_FLOAT32_C(   -51.63), SIMDE_FLOAT32_C(   -84.19),
        SIMDE_FLOAT32_C(    47.29), SIMDE_FLOAT32_C(     6.21), SIMDE_FLOAT32_C(    41.12), SIMDE_FLOAT32_C(    16.84) },
      { SIMDE_FLOAT32_C(  6515.15), SIMDE_FLOAT32_C( -9076.34), SIMDE_FLOAT32_C(   318.43), SIMDE_FLOAT32_C(   508.54),
        SIMDE_FLOAT32_C( -2492.59), SIMDE_FLOAT32_C(  -412.47), SIMDE_FLOAT32_C( -5738.37), SIMDE_FLOAT32_C(    30.94),
        SIMDE_FLOAT32_C( -3176.30), SIMDE_FLOAT32_C(  1596.36), SIMDE_FLOAT32_C( -3511.11), SIMDE_FLOAT32_C(  5540.13),
        SIMDE_FLOAT32_C(  4468.67), SIMDE_FLOAT32_C(  1766.74), SIMDE_FLOAT32_C( -3319.48), SIMDE_FLOAT32_C( -2517.72) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 c = simde_mm512_loadu_ps(test_vec[i].c);
    simde__m512 r = simde_mm512_fmsub_ps(a, b, c);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_fmsub_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 c[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -46.12), SIMDE_FLOAT64_C(   -61.46), SIMDE_FLOAT64_C(    12.22), SIMDE_FLOAT64_C(   -13.13),
        SIMDE_FLOAT64_C(    17.13), SIMDE_FLOAT64_C(    34.93), SIMDE_FLOAT64_C(    51.88), SIMDE_FLOAT64_C(    19.93) },
      { SIMDE_FLOAT64_C(    73.17), SIMDE_FLOAT64_C(   -90.86), SIMDE_FLOAT64_C(   -64.69), SIMDE_FLOAT64_C(    30.40),
        SIMDE_FLOAT64_C(   -78.85), SIMDE_FLOAT64_C(    -2.23), SIMDE_FLOAT64_C(    38.81), SIMDE_FLOAT64_C(   -25.38) },
      { SIMDE_FLOAT64_C(     6.25), SIMDE_FLOAT64_C(   -22.61), SIMDE_FLOAT64_C(     8.61), SIMDE_FLOAT64_C(   -27.29),
        SIMDE_FLOAT64_C(   -33.10), SIMDE_FLOAT64_C(    99.80), SIMDE_FLOAT64_C(   -95.28), SIMDE_FLOAT64_C(    59.13) },
      { SIMDE_FLOAT64_C( -3380.85), SIMDE_FLOAT64_C(  5606.87), SIMDE_FLOAT64_C(  -799.12), SIMDE_FLOAT64_C(  -371.86),
        SIMDE_FLOAT64_C( -1317.60), SIMDE_FLOAT64_C(  -177.69), SIMDE_FLOAT64_C(  2108.74), SIMDE_FLOAT64_C(  -564.95) } },
    { { SIMDE_FLOAT64_C(    28.50), SIMDE_FLOAT64_C(   -32.67), SIMDE_FLOAT64_C(   -95.72), SIMDE_FLOAT64_C(    21.20),
        SIMDE_FLOAT64_C(    40.97), SIMDE_FLOAT64_C(   -90.91), SIMDE_FLOAT64_C(    40.73), SIMDE_FLOAT64_C(    94.85) },
      { SIMDE_FLOAT64_C(   -52.37), SIMDE_FLOAT64_C(   -47.05), SIMDE_FLOAT64_C(   -18.28), SIMDE_FLOAT64_C(    64.76),
        SIMDE_FLOAT64_C(    87.88), SIMDE_FLOAT64_C(   -66.39), SIMDE_FLOAT64_C(   -15.31), SIMDE_FLOAT64_C(    61.05) },
      { SIMDE_FLOAT64_C(   -57.26), SIMDE_FLOAT64_C(    19.99), SIMDE_FLOAT64_C(    -8.55), SIMDE_FLOAT64_C(   -36.11),
        SIMDE_FLOAT64_C(   -82.23), SIMDE_FLOAT64_C(   -69.73), SIMDE_FLOAT64_C(    38.51), SIMDE_FLOAT64_C(    24.02) },
      { SIMDE_FLOAT64_C( -1435.28), SIMDE_FLOAT64_C(  1517.13), SIMDE_FLOAT64_C(  1758.31), SIMDE_FLOAT64_C(  1409.02),
        SIMDE_FLOAT64_C(  3682.67), SIMDE_FLOAT64_C(  6105.24), SIMDE_FLOAT64_C(  -662.09), SIMDE_FLOAT64_C(  5766.57) } },
    { { SIMDE_FLOAT64_C(     7.65), SIMDE_FLOAT64_C(   -52.88), SIMDE_FLOAT64_C(    96.73), SIMDE_FLOAT64_C(    74.56),
        SIMDE_FLOAT64_C(   -53.08), SIMDE_FLOAT64_C(   -98.55), SIMDE_FLOAT64_C(    33.69), SIMDE_FLOAT64_C(    75.41) },
      { SIMDE_FLOAT64_C(   -31.22), SIMDE_FLOAT64_C(    37.96), SIMDE_FLOAT64_C(    -3.39), SIMDE_FLOAT64_C(   -90.25),
        SIMDE_FLOAT64_C(    47.06), SIMDE_FLOAT64_C(   -62.65), SIMDE_FLOAT64_C(   -95.40), SIMDE_FLOAT64_C(    94.69) },
      { SIMDE_FLOAT64_C(    -9.70), SIMDE_FLOAT64_C(   -13.67), SIMDE_FLOAT64_C(    59.45), SIMDE_FLOAT64_C(   -21.82),
        SIMDE_FLOAT64_C(    19.93), SIMDE_FLOAT64_C(   -55.86), SIMDE_FLOAT64_C(   -60.77), SIMDE_FLOAT64_C(    62.67) },
      { SIMDE_FLOAT64_C(  -229.13), SIMDE_FLOAT64_C( -1993.65), SIMDE_FLOAT64_C(  -387.36), SIMDE_FLOAT64_C( -6707.22),
        SIMDE_FLOAT64_C( -2517.87), SIMDE_FLOAT64_C(  6230.02), SIMDE_FLOAT64_C( -3153.26), SIMDE_FLOAT64_C(  7077.90) } },
    { { SIMDE_FLOAT64_C(    64.13), SIMDE_FLOAT64_C(    30.68), SIMDE_FLOAT64_C(   -73.44), SIMDE_FLOAT64_C(    81.90),
        SIMDE_FLOAT64_C(    60.95), SIMDE_FLOAT64_C(    65.08), SIMDE_FLOAT64_C(     5.91), SIMDE_FLOAT64_C(   -31.40) },
      { SIMDE_FLOAT64_C(   -87.81), SIMDE_FLOAT64_C(     2.64), SIMDE_FLOAT64_C(   -56.84), SIMDE_FLOAT64_C(   -40.89),
        SIMDE_FLOAT64_C(     4.09), SIMDE_FLOAT64_C(    76.84), SIMDE_FLOAT64_C(   -65.48), SIMDE_FLOAT64_C(    72.87) },
      { SIMDE_FLOAT64_C(    14.81), SIMDE_FLOAT64_C(    31.14), SIMDE_FLOAT64_C(    82.62), SIMDE_FLOAT64_C(   -38.13),
        SIMDE_FLOAT64_C(    68.49), SIMDE_FLOAT64_C(    87.23), SIMDE_FLOAT64_C(   -43.44), SIMDE_FLOAT64_C(   -41.22) },
      { SIMDE_FLOAT64_C( -5646.07), SIMDE_FLOAT64_C(    49.86), SIMDE_FLOAT64_C(  4091.71), SIMDE_FLOAT64_C( -3310.76),
        SIMDE_FLOAT64_C(   180.80), SIMDE_FLOAT64_C(  4913.52), SIMDE_FLOAT64_C(  -343.55), SIMDE_FLOAT64_C( -2246.90) } },
    { { SIMDE_FLOAT64_C(   -26.44), SIMDE_FLOAT64_C(   -83.99), SIMDE_FLOAT64_C(    36.96), SIMDE_FLOAT64_C(    93.49),
        SIMDE_FLOAT64_C(   -39.85), SIMDE_FLOAT64_C(    76.19), SIMDE_FLOAT64_C(    56.16), SIMDE_FLOAT64_C(   -75.72) },
      { SIMDE_FLOAT64_C(     6.87), SIMDE_FLOAT64_C(    82.72), SIMDE_FLOAT64_C(   -93.82), SIMDE_FLOAT64_C(   -32.18),
        SIMDE_FLOAT64_C(    47.80), SIMDE_FLOAT64_C(    12.09), SIMDE_FLOAT64_C(    36.42), SIMDE_FLOAT64_C(    59.99) },
      { SIMDE_FLOAT64_C(   -85.27), SIMDE_FLOAT64_C(    79.58), SIMDE_FLOAT64_C(   -80.90), SIMDE_FLOAT64_C(    18.82),
        SIMDE_FLOAT64_C(    56.42), SIMDE_FLOAT64_C(   -46.38), SIMDE_FLOAT64_C(    -8.31), SIMDE_FLOAT64_C(   -28.77) },
      { SIMDE_FLOAT64_C(   -96.37), SIMDE_FLOAT64_C( -7027.23), SIMDE_FLOAT64_C( -3386.69), SIMDE_FLOAT64_C( -3027.33),
        SIMDE_FLOAT64_C( -1961.25), SIMDE_FLOAT64_C(   967.52), SIMDE_FLOAT64_C(  2053.66), SIMDE_FLOAT64_C( -4513.67) } },
    { { SIMDE_FLOAT64_C(    84.76), SIMDE_FLOAT64_C(   -25.68), SIMDE_FLOAT64_C(    33.09), SIMDE_FLOAT64_C(    53.25),
        SIMDE_FLOAT64_C(   -38.45), SIMDE_FLOAT64_C(    89.65), SIMDE_FLOAT64_C(   -87.97), SIMDE_FLOAT64_C(    35.10) },
      { SIMDE_FLOAT64_C(   -94.34), SIMDE_FLOAT64_C(    48.99), SIMDE_FLOAT64_C(    28.59), SIMDE_FLOAT64_C(   -34.19),
        SIMDE_FLOAT64_C(    25.18), SIMDE_FLOAT64_C(   -15.25), SIMDE_FLOAT64_C(    -9.91), SIMDE_FLOAT64_C(   -67.95) },
      { SIMDE_FLOAT64_C(   -32.53), SIMDE_FLOAT64_C(    -3.73), SIMDE_FLOAT64_C(    -0.13), SIMDE_FLOAT64_C(   -84.73),
        SIMDE_FLOAT64_C(   -91.64), SIMDE_FLOAT64_C(   -63.71), SIMDE_FLOAT64_C(    75.26), SIMDE_FLOAT64_C(   -76.91) },
      { SIMDE_FLOAT64_C( -7963.73), SIMDE_FLOAT64_C( -1254.33), SIMDE_FLOAT64_C(   946.17), SIMDE_FLOAT64_C( -1735.89),
        SIMDE_FLOAT64_C(  -876.53), SIMDE_FLOAT64_C( -1303.45), SIMDE_FLOAT64_C(   796.52), SIMDE_FLOAT64_C( -2308.14) } },
    { { SIMDE_FLOAT64_C(   -84.14), SIMDE_FLOAT64_C(    94.36), SIMDE_FLOAT64_C(    41.92), SIMDE_FLOAT64_C(    72.28),
        SIMDE_FLOAT64_C(   -52.01), SIMDE_FLOAT64_C(   -66.39), SIMDE_FLOAT64_C(   -56.49), SIMDE_FLOAT64_C(   -67.25) },
      { SIMDE_FLOAT64_C(     7.93), SIMDE_FLOAT64_C(    76.60), SIMDE_FLOAT64_C(    85.99), SIMDE_FLOAT64_C(    69.48),
        SIMDE_FLOAT64_C(    66.25), SIMDE_FLOAT64_C(    98.03), SIMDE_FLOAT64_C(     4.58), SIMDE_FLOAT64_C(    71.92) },
      { SIMDE_FLOAT64_C(    47.02), SIMDE_FLOAT64_C(   -66.83), SIMDE_FLOAT64_C(   -62.27), SIMDE_FLOAT64_C(   -27.80),
        SIMDE_FLOAT64_C(    17.92), SIMDE_FLOAT64_C(    27.82), SIMDE_FLOAT64_C(     4.25), SIMDE_FLOAT64_C(    85.39) },
      { SIMDE_FLOAT64_C(  -714.25), SIMDE_FLOAT64_C(  7294.81), SIMDE_FLOAT64_C(  3666.97), SIMDE_FLOAT64_C(  5049.81),
        SIMDE_FLOAT64_C( -3463.58), SIMDE_FLOAT64_C( -6536.03), SIMDE_FLOAT64_C(  -262.97), SIMDE_FLOAT64_C( -4922.01) } },
    { { SIMDE_FLOAT64_C(   -75.91), SIMDE_FLOAT64_C(   -95.88), SIMDE_FLOAT64_C(   -99.34), SIMDE_FLOAT64_C(   -67.54),
        SIMDE_FLOAT64_C(   -59.59), SIMDE_FLOAT64_C(    75.92), SIMDE_FLOAT64_C(   -44.45), SIMDE_FLOAT64_C(   -43.72) },
      { SIMDE_FLOAT64_C(    70.29), SIMDE_FLOAT64_C(    97.47), SIMDE_FLOAT64_C(   -71.44), SIMDE_FLOAT64_C(   -81.73),
        SIMDE_FLOAT64_C(   -68.92), SIMDE_FLOAT64_C(   -27.93), SIMDE_FLOAT64_C(   -48.98), SIMDE_FLOAT64_C(    39.01) },
      { SIMDE_FLOAT64_C(   -51.32), SIMDE_FLOAT64_C(   -62.98), SIMDE_FLOAT64_C(     8.48), SIMDE_FLOAT64_C(   -85.07),
        SIMDE_FLOAT64_C(   -64.96), SIMDE_FLOAT64_C(   -86.94), SIMDE_FLOAT64_C(    86.85), SIMDE_FLOAT64_C(    82.06) },
      { SIMDE_FLOAT64_C( -5284.39), SIMDE_FLOAT64_C( -9282.44), SIMDE_FLOAT64_C(  7088.37), SIMDE_FLOAT64_C(  5605.11),
        SIMDE_FLOAT64_C(  4171.90), SIMDE_FLOAT64_C( -2033.51), SIMDE_FLOAT64_C(  2090.31), SIMDE_FLOAT64_C( -1787.58) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d c = simde_mm512_loadu_pd(test_vec[i].c);
    simde__m512d r = simde_mm512_fmsub_pd(a, b, c);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask3_fmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_fmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_fmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask3_fmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_fmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_fmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask3_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask3_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fmsub_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
