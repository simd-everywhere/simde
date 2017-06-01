/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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
 */

#include <test/simd-js/simd-js.h>
#include <simde/simd-js/simd-js.h>

#include <math.h>

static void
simde_assert_float32x4_equal_(simde_float32 precision, simde_em_float32x4 a, simde_em_float32x4 b, int line, const char* a_, const char* b_) {
  for (size_t i = 0 ; i < (sizeof(a.v) / sizeof(a.v[0])) ; i++) {
    const simde_float32 diff = ((a.v[i] - b.v[i]) < 0) ?
      (b.v[i] - a.v[i]) :
      (a.v[i] - b.v[i]);
    if (MUNIT_UNLIKELY(diff > (1.0 / precision))) {
      fprintf(stderr, "a: %8.2f %8.2f  %8.2f %8.2f\n", a.v[0], a.v[1], a.v[2], a.v[3]);
      fprintf(stderr, "b: %8.2f %8.2f  %8.2f %8.2f\n", b.v[0], b.v[1], b.v[2], b.v[3]);
      munit_errorf("assertion failed at line %d: %s[%" MUNIT_SIZE_MODIFIER "u] == %s[%" MUNIT_SIZE_MODIFIER "u] (%f == %f)",
		   line, a_, i, b_, i, a.v[i], b.v[i]);
    }
  }
}

#define simde_assert_float32x4_equal(precision, a, b) \
  simde_assert_float32x4_equal_(precision, a, b, __LINE__, #a, #b)

static MunitResult
test_simde_em_float32x4_set(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a[4];
    simde_em_float32x4 r;
  } test_vec[8] = {
    {                      { SIMDE_FLOAT32_C( 404.63), SIMDE_FLOAT32_C( 234.68), SIMDE_FLOAT32_C( 286.84), SIMDE_FLOAT32_C( 743.61) },
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 404.63), SIMDE_FLOAT32_C( 234.68), SIMDE_FLOAT32_C( 286.84), SIMDE_FLOAT32_C( 743.61)) },
    {                      { SIMDE_FLOAT32_C( 750.85), SIMDE_FLOAT32_C(-462.67), SIMDE_FLOAT32_C(-841.88), SIMDE_FLOAT32_C( -59.14) },
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 750.85), SIMDE_FLOAT32_C(-462.67), SIMDE_FLOAT32_C(-841.88), SIMDE_FLOAT32_C( -59.14)) },
    {                      { SIMDE_FLOAT32_C(-101.29), SIMDE_FLOAT32_C(-113.38), SIMDE_FLOAT32_C( 841.41), SIMDE_FLOAT32_C(-810.17) },
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-101.29), SIMDE_FLOAT32_C(-113.38), SIMDE_FLOAT32_C( 841.41), SIMDE_FLOAT32_C(-810.17)) },
    {                      { SIMDE_FLOAT32_C( 235.00), SIMDE_FLOAT32_C(-536.61), SIMDE_FLOAT32_C(-981.12), SIMDE_FLOAT32_C( 849.56) },
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 235.00), SIMDE_FLOAT32_C(-536.61), SIMDE_FLOAT32_C(-981.12), SIMDE_FLOAT32_C( 849.56)) },
    {                      { SIMDE_FLOAT32_C(-249.12), SIMDE_FLOAT32_C(-945.93), SIMDE_FLOAT32_C( -47.40), SIMDE_FLOAT32_C(-337.87) },
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-249.12), SIMDE_FLOAT32_C(-945.93), SIMDE_FLOAT32_C( -47.40), SIMDE_FLOAT32_C(-337.87)) },
    {                      { SIMDE_FLOAT32_C( 269.50), SIMDE_FLOAT32_C( 727.85), SIMDE_FLOAT32_C( 881.86), SIMDE_FLOAT32_C( 318.29) },
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 269.50), SIMDE_FLOAT32_C( 727.85), SIMDE_FLOAT32_C( 881.86), SIMDE_FLOAT32_C( 318.29)) },
    {                      { SIMDE_FLOAT32_C( 945.79), SIMDE_FLOAT32_C(  -1.67), SIMDE_FLOAT32_C(-567.06), SIMDE_FLOAT32_C(-908.28) },
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 945.79), SIMDE_FLOAT32_C(  -1.67), SIMDE_FLOAT32_C(-567.06), SIMDE_FLOAT32_C(-908.28)) },
    {                      { SIMDE_FLOAT32_C(-843.00), SIMDE_FLOAT32_C(-900.38), SIMDE_FLOAT32_C( 621.29), SIMDE_FLOAT32_C( 962.44) },
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-843.00), SIMDE_FLOAT32_C(-900.38), SIMDE_FLOAT32_C( 621.29), SIMDE_FLOAT32_C( 962.44)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_set(test_vec[i].a[0], test_vec[i].a[1], test_vec[i].a[2], test_vec[i].a[3]);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_splat(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde_em_float32x4 r;
  } test_vec[8] = {
    {                        SIMDE_FLOAT32_C( 719.43),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 719.43), SIMDE_FLOAT32_C( 719.43), SIMDE_FLOAT32_C( 719.43), SIMDE_FLOAT32_C( 719.43)) },
    {                        SIMDE_FLOAT32_C(-986.29),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-986.29), SIMDE_FLOAT32_C(-986.29), SIMDE_FLOAT32_C(-986.29), SIMDE_FLOAT32_C(-986.29)) },
    {                        SIMDE_FLOAT32_C(-213.37),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-213.37), SIMDE_FLOAT32_C(-213.37), SIMDE_FLOAT32_C(-213.37), SIMDE_FLOAT32_C(-213.37)) },
    {                        SIMDE_FLOAT32_C(  11.75),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  11.75), SIMDE_FLOAT32_C(  11.75), SIMDE_FLOAT32_C(  11.75), SIMDE_FLOAT32_C(  11.75)) },
    {                        SIMDE_FLOAT32_C( 980.41),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 980.41), SIMDE_FLOAT32_C( 980.41), SIMDE_FLOAT32_C( 980.41), SIMDE_FLOAT32_C( 980.41)) },
    {                        SIMDE_FLOAT32_C( 189.58),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 189.58), SIMDE_FLOAT32_C( 189.58), SIMDE_FLOAT32_C( 189.58), SIMDE_FLOAT32_C( 189.58)) },
    {                        SIMDE_FLOAT32_C( 766.21),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 766.21), SIMDE_FLOAT32_C( 766.21), SIMDE_FLOAT32_C( 766.21), SIMDE_FLOAT32_C( 766.21)) },
    {                        SIMDE_FLOAT32_C(-340.70),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-340.70), SIMDE_FLOAT32_C(-340.70), SIMDE_FLOAT32_C(-340.70), SIMDE_FLOAT32_C(-340.70)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_splat(test_vec[i].a);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_add(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 b;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-830.61), SIMDE_FLOAT32_C( -120.33), SIMDE_FLOAT32_C(  764.57), SIMDE_FLOAT32_C(  954.33)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 518.18), SIMDE_FLOAT32_C(  410.47), SIMDE_FLOAT32_C( -896.99), SIMDE_FLOAT32_C(  617.59)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-312.43), SIMDE_FLOAT32_C(  290.14), SIMDE_FLOAT32_C( -132.42), SIMDE_FLOAT32_C( 1571.92)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-770.86), SIMDE_FLOAT32_C( -315.57), SIMDE_FLOAT32_C(  -14.23), SIMDE_FLOAT32_C(  743.19)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 949.10), SIMDE_FLOAT32_C( -680.45), SIMDE_FLOAT32_C( -574.82), SIMDE_FLOAT32_C(  302.79)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 178.24), SIMDE_FLOAT32_C( -996.02), SIMDE_FLOAT32_C( -589.05), SIMDE_FLOAT32_C( 1045.98)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 629.82), SIMDE_FLOAT32_C(  938.17), SIMDE_FLOAT32_C( -579.84), SIMDE_FLOAT32_C( -347.97)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-256.37), SIMDE_FLOAT32_C(  947.23), SIMDE_FLOAT32_C( -975.04), SIMDE_FLOAT32_C( -277.65)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 373.45), SIMDE_FLOAT32_C( 1885.40), SIMDE_FLOAT32_C(-1554.88), SIMDE_FLOAT32_C( -625.62)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 349.82), SIMDE_FLOAT32_C( -675.10), SIMDE_FLOAT32_C(  819.46), SIMDE_FLOAT32_C(  527.76)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 734.84), SIMDE_FLOAT32_C( -265.17), SIMDE_FLOAT32_C( -771.61), SIMDE_FLOAT32_C(  812.61)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(1084.66), SIMDE_FLOAT32_C( -940.27), SIMDE_FLOAT32_C(   47.85), SIMDE_FLOAT32_C( 1340.37)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-786.91), SIMDE_FLOAT32_C(  856.69), SIMDE_FLOAT32_C(  127.21), SIMDE_FLOAT32_C( -495.46)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-209.48), SIMDE_FLOAT32_C(  351.08), SIMDE_FLOAT32_C( -635.55), SIMDE_FLOAT32_C( -151.53)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-996.39), SIMDE_FLOAT32_C( 1207.77), SIMDE_FLOAT32_C( -508.34), SIMDE_FLOAT32_C( -646.99)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-585.65), SIMDE_FLOAT32_C( -152.87), SIMDE_FLOAT32_C( -468.40), SIMDE_FLOAT32_C(  319.48)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 496.22), SIMDE_FLOAT32_C(  428.17), SIMDE_FLOAT32_C(  378.21), SIMDE_FLOAT32_C( -946.08)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -89.43), SIMDE_FLOAT32_C(  275.30), SIMDE_FLOAT32_C(  -90.19), SIMDE_FLOAT32_C( -626.60)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-461.54), SIMDE_FLOAT32_C(  643.88), SIMDE_FLOAT32_C(  -80.76), SIMDE_FLOAT32_C( -642.03)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-167.58), SIMDE_FLOAT32_C( -918.24), SIMDE_FLOAT32_C( -418.74), SIMDE_FLOAT32_C(  265.85)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-629.12), SIMDE_FLOAT32_C( -274.36), SIMDE_FLOAT32_C( -499.50), SIMDE_FLOAT32_C( -376.18)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 621.31), SIMDE_FLOAT32_C(  920.65), SIMDE_FLOAT32_C( -657.19), SIMDE_FLOAT32_C( -591.79)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-685.20), SIMDE_FLOAT32_C( -986.56), SIMDE_FLOAT32_C(   71.12), SIMDE_FLOAT32_C( -230.90)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -63.89), SIMDE_FLOAT32_C(  -65.91), SIMDE_FLOAT32_C( -586.07), SIMDE_FLOAT32_C( -822.69)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_add(test_vec[i].a, test_vec[i].b);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_sub(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 b;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  678.96), SIMDE_FLOAT32_C(  599.66),
			     SIMDE_FLOAT32_C( -843.45), SIMDE_FLOAT32_C(  13.44)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  235.79), SIMDE_FLOAT32_C( -446.91),
			     SIMDE_FLOAT32_C(  -55.38), SIMDE_FLOAT32_C(  982.69)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  443.17), SIMDE_FLOAT32_C( 1046.57),
			     SIMDE_FLOAT32_C( -788.07), SIMDE_FLOAT32_C( -969.25)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( -887.89), SIMDE_FLOAT32_C( -753.69),
			     SIMDE_FLOAT32_C(  -88.13), SIMDE_FLOAT32_C( -408.47)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  265.85), SIMDE_FLOAT32_C(  -43.11),
			     SIMDE_FLOAT32_C( -327.06), SIMDE_FLOAT32_C(  232.90)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-1153.74), SIMDE_FLOAT32_C( -710.58),
			     SIMDE_FLOAT32_C(  238.93), SIMDE_FLOAT32_C( -641.37)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( -682.14), SIMDE_FLOAT32_C( -961.44),
			     SIMDE_FLOAT32_C(  638.73), SIMDE_FLOAT32_C(  796.97)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  237.23), SIMDE_FLOAT32_C(   19.65),
			     SIMDE_FLOAT32_C(  377.57), SIMDE_FLOAT32_C(  350.27)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -919.37), SIMDE_FLOAT32_C( -981.09),
			     SIMDE_FLOAT32_C(  261.16), SIMDE_FLOAT32_C(  446.70)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  140.04), SIMDE_FLOAT32_C(  258.87),
			     SIMDE_FLOAT32_C( -251.75), SIMDE_FLOAT32_C( -343.99)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -797.56), SIMDE_FLOAT32_C(  871.26),
			     SIMDE_FLOAT32_C( -555.47), SIMDE_FLOAT32_C(  750.81)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  937.60), SIMDE_FLOAT32_C( -612.39),
			     SIMDE_FLOAT32_C(  303.72), SIMDE_FLOAT32_C(-1094.80)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( -716.17), SIMDE_FLOAT32_C(  119.97),
			     SIMDE_FLOAT32_C( -336.21), SIMDE_FLOAT32_C(   68.81)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  622.27), SIMDE_FLOAT32_C( -761.35),
			     SIMDE_FLOAT32_C( -255.09), SIMDE_FLOAT32_C(  966.51)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-1338.44), SIMDE_FLOAT32_C(  881.32),
			     SIMDE_FLOAT32_C(  -81.12), SIMDE_FLOAT32_C( -897.70)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( -469.23), SIMDE_FLOAT32_C( -594.03),
			     SIMDE_FLOAT32_C(  188.15), SIMDE_FLOAT32_C( -996.40)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  493.52), SIMDE_FLOAT32_C(  444.99),
			     SIMDE_FLOAT32_C( -482.25), SIMDE_FLOAT32_C(  345.36)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -962.75), SIMDE_FLOAT32_C(-1039.02),
			     SIMDE_FLOAT32_C(  670.40), SIMDE_FLOAT32_C(-1341.76)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( -637.13), SIMDE_FLOAT32_C( -619.25),
			     SIMDE_FLOAT32_C(  350.47), SIMDE_FLOAT32_C(  645.63)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -700.88), SIMDE_FLOAT32_C( -408.50),
			     SIMDE_FLOAT32_C( -582.48), SIMDE_FLOAT32_C(  557.37)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   63.75), SIMDE_FLOAT32_C( -210.75),
			     SIMDE_FLOAT32_C(  932.95), SIMDE_FLOAT32_C(   88.26)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( -619.39), SIMDE_FLOAT32_C(  215.55),
			     SIMDE_FLOAT32_C(  201.10), SIMDE_FLOAT32_C( -714.73)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  420.23), SIMDE_FLOAT32_C( -835.72),
			     SIMDE_FLOAT32_C(  496.41), SIMDE_FLOAT32_C( -535.52)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-1039.62), SIMDE_FLOAT32_C( 1051.27),
			     SIMDE_FLOAT32_C( -295.31), SIMDE_FLOAT32_C( -179.21)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_sub(test_vec[i].a, test_vec[i].b);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_mul(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 b;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(   -820.57), SIMDE_FLOAT32_C(    872.03),
			     SIMDE_FLOAT32_C(     36.57), SIMDE_FLOAT32_C(     51.79)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   -176.39), SIMDE_FLOAT32_C(   -152.79),
			     SIMDE_FLOAT32_C(   -176.35), SIMDE_FLOAT32_C(   -560.55)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 144740.34), SIMDE_FLOAT32_C(-133237.47),
			     SIMDE_FLOAT32_C(  -6449.12), SIMDE_FLOAT32_C(-29030.88)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(   -693.03), SIMDE_FLOAT32_C(   -159.50),
			     SIMDE_FLOAT32_C(   -310.78), SIMDE_FLOAT32_C(    704.89)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(     62.32), SIMDE_FLOAT32_C(   -795.36),
			     SIMDE_FLOAT32_C(   -506.14), SIMDE_FLOAT32_C(   -676.79)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -43189.63), SIMDE_FLOAT32_C( 126859.91),
			     SIMDE_FLOAT32_C( 157298.19), SIMDE_FLOAT32_C(-477062.50)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(    164.24), SIMDE_FLOAT32_C(    272.96),
			     SIMDE_FLOAT32_C(    238.69), SIMDE_FLOAT32_C(    704.38)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   -940.33), SIMDE_FLOAT32_C(    162.96),
			     SIMDE_FLOAT32_C(    863.21), SIMDE_FLOAT32_C(    311.69)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-154439.81), SIMDE_FLOAT32_C(  44481.56),
			     SIMDE_FLOAT32_C( 206039.61), SIMDE_FLOAT32_C( 219548.20)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(   -504.80), SIMDE_FLOAT32_C(    635.76),
			     SIMDE_FLOAT32_C(   -866.83), SIMDE_FLOAT32_C(   -625.52)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   -629.76), SIMDE_FLOAT32_C(    970.05),
			     SIMDE_FLOAT32_C(   -416.47), SIMDE_FLOAT32_C(     75.79)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 317902.84), SIMDE_FLOAT32_C( 616719.00),
			     SIMDE_FLOAT32_C( 361008.69), SIMDE_FLOAT32_C( -47408.16)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(    150.80), SIMDE_FLOAT32_C(   -847.78),
			     SIMDE_FLOAT32_C(    -63.33), SIMDE_FLOAT32_C(    795.79)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   -148.59), SIMDE_FLOAT32_C(   -778.33),
			     SIMDE_FLOAT32_C(   -661.10), SIMDE_FLOAT32_C(    231.61)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -22407.37), SIMDE_FLOAT32_C( 659852.62),
			     SIMDE_FLOAT32_C(  41867.46), SIMDE_FLOAT32_C( 184312.92)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(    332.65), SIMDE_FLOAT32_C(    -82.10),
			     SIMDE_FLOAT32_C(   -162.60), SIMDE_FLOAT32_C(    482.09)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(    437.81), SIMDE_FLOAT32_C(    310.52),
			     SIMDE_FLOAT32_C(    564.10), SIMDE_FLOAT32_C(   -975.60)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 145637.50), SIMDE_FLOAT32_C( -25493.69),
			     SIMDE_FLOAT32_C( -91722.66), SIMDE_FLOAT32_C(-470327.00)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(   -781.95), SIMDE_FLOAT32_C(    303.09),
			     SIMDE_FLOAT32_C(    692.95), SIMDE_FLOAT32_C(   -326.78)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(    -18.02), SIMDE_FLOAT32_C(   -683.58),
			     SIMDE_FLOAT32_C(   -857.66), SIMDE_FLOAT32_C(    -88.60)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  14090.74), SIMDE_FLOAT32_C(-207186.27),
			     SIMDE_FLOAT32_C(-594315.50), SIMDE_FLOAT32_C(  28952.71)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(     69.36), SIMDE_FLOAT32_C(    339.57),
			     SIMDE_FLOAT32_C(    797.99), SIMDE_FLOAT32_C(   -654.75)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   -891.44), SIMDE_FLOAT32_C(    999.45),
			     SIMDE_FLOAT32_C(    621.64), SIMDE_FLOAT32_C(   -977.90)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -61830.28), SIMDE_FLOAT32_C( 339383.25),
			     SIMDE_FLOAT32_C( 496062.50), SIMDE_FLOAT32_C( 640280.06)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_mul(test_vec[i].a, test_vec[i].b);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_div(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 b;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-354.38), SIMDE_FLOAT32_C(-807.20), SIMDE_FLOAT32_C(-847.78), SIMDE_FLOAT32_C( 589.49)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-613.87), SIMDE_FLOAT32_C(-679.86), SIMDE_FLOAT32_C(-705.95), SIMDE_FLOAT32_C( 464.70)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.58), SIMDE_FLOAT32_C(   1.19), SIMDE_FLOAT32_C(   1.20), SIMDE_FLOAT32_C(   1.27)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  51.77), SIMDE_FLOAT32_C(-234.24), SIMDE_FLOAT32_C( 923.12), SIMDE_FLOAT32_C( 892.75)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 739.26), SIMDE_FLOAT32_C(-207.22), SIMDE_FLOAT32_C(-814.16), SIMDE_FLOAT32_C( 412.98)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.07), SIMDE_FLOAT32_C(   1.13), SIMDE_FLOAT32_C(  -1.13), SIMDE_FLOAT32_C(   2.16)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-209.70), SIMDE_FLOAT32_C(  67.97), SIMDE_FLOAT32_C( 614.33), SIMDE_FLOAT32_C(-752.60)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 160.18), SIMDE_FLOAT32_C(  81.81), SIMDE_FLOAT32_C(-489.27), SIMDE_FLOAT32_C(-375.43)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  -1.31), SIMDE_FLOAT32_C(   0.83), SIMDE_FLOAT32_C(  -1.26), SIMDE_FLOAT32_C(   2.00)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 599.82), SIMDE_FLOAT32_C(-245.12), SIMDE_FLOAT32_C(-888.60), SIMDE_FLOAT32_C(-268.23)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 662.62), SIMDE_FLOAT32_C(-503.09), SIMDE_FLOAT32_C(-549.33), SIMDE_FLOAT32_C(-408.19)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.91), SIMDE_FLOAT32_C(   0.49), SIMDE_FLOAT32_C(   1.62), SIMDE_FLOAT32_C(   0.66)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-795.27), SIMDE_FLOAT32_C( 426.41), SIMDE_FLOAT32_C( 501.86), SIMDE_FLOAT32_C( 635.44)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 234.01), SIMDE_FLOAT32_C(-552.32), SIMDE_FLOAT32_C(-476.37), SIMDE_FLOAT32_C( 203.59)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  -3.40), SIMDE_FLOAT32_C(  -0.77), SIMDE_FLOAT32_C(  -1.05), SIMDE_FLOAT32_C(   3.12)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-360.62), SIMDE_FLOAT32_C(  69.35), SIMDE_FLOAT32_C( 194.81), SIMDE_FLOAT32_C(-387.44)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 687.00), SIMDE_FLOAT32_C( 649.94), SIMDE_FLOAT32_C( 375.22), SIMDE_FLOAT32_C( 466.86)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  -0.52), SIMDE_FLOAT32_C(   0.11), SIMDE_FLOAT32_C(   0.52), SIMDE_FLOAT32_C(  -0.83)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 130.74), SIMDE_FLOAT32_C(-830.83), SIMDE_FLOAT32_C(-193.86), SIMDE_FLOAT32_C( 612.78)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-278.50), SIMDE_FLOAT32_C( 810.95), SIMDE_FLOAT32_C( 536.50), SIMDE_FLOAT32_C( 472.87)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  -0.47), SIMDE_FLOAT32_C(  -1.02), SIMDE_FLOAT32_C(  -0.36), SIMDE_FLOAT32_C(   1.30)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-599.75), SIMDE_FLOAT32_C(-792.86), SIMDE_FLOAT32_C(  24.13), SIMDE_FLOAT32_C(-355.67)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-479.03), SIMDE_FLOAT32_C( 540.32), SIMDE_FLOAT32_C( 975.13), SIMDE_FLOAT32_C(-830.02)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   1.25), SIMDE_FLOAT32_C(  -1.47), SIMDE_FLOAT32_C(   0.02), SIMDE_FLOAT32_C(   0.43)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_div(test_vec[i].a, test_vec[i].b);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_max(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 b;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 432.91), SIMDE_FLOAT32_C(-482.18), SIMDE_FLOAT32_C(-116.19), SIMDE_FLOAT32_C( 952.52)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-673.77), SIMDE_FLOAT32_C(  31.47), SIMDE_FLOAT32_C( 588.43), SIMDE_FLOAT32_C( 619.90)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 432.91), SIMDE_FLOAT32_C(  31.47), SIMDE_FLOAT32_C( 588.43), SIMDE_FLOAT32_C( 952.52)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( -53.02), SIMDE_FLOAT32_C(-848.78), SIMDE_FLOAT32_C(-792.32), SIMDE_FLOAT32_C(-338.87)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  35.40), SIMDE_FLOAT32_C( 714.73), SIMDE_FLOAT32_C( 790.02), SIMDE_FLOAT32_C(-647.23)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  35.40), SIMDE_FLOAT32_C( 714.73), SIMDE_FLOAT32_C( 790.02), SIMDE_FLOAT32_C(-338.87)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-206.00), SIMDE_FLOAT32_C(  93.27), SIMDE_FLOAT32_C(-418.86), SIMDE_FLOAT32_C(-109.82)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 161.59), SIMDE_FLOAT32_C( 323.38), SIMDE_FLOAT32_C( 898.41), SIMDE_FLOAT32_C(-120.65)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 161.59), SIMDE_FLOAT32_C( 323.38), SIMDE_FLOAT32_C( 898.41), SIMDE_FLOAT32_C(-109.82)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 939.47), SIMDE_FLOAT32_C( 462.47), SIMDE_FLOAT32_C( 909.38), SIMDE_FLOAT32_C( 467.33)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 618.68), SIMDE_FLOAT32_C(-623.25), SIMDE_FLOAT32_C( 962.98), SIMDE_FLOAT32_C( 410.83)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 939.47), SIMDE_FLOAT32_C( 462.47), SIMDE_FLOAT32_C( 962.98), SIMDE_FLOAT32_C( 467.33)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 151.52), SIMDE_FLOAT32_C(-924.93), SIMDE_FLOAT32_C(-789.84), SIMDE_FLOAT32_C( 320.82)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-292.22), SIMDE_FLOAT32_C(-281.13), SIMDE_FLOAT32_C( 398.07), SIMDE_FLOAT32_C( 131.45)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 151.52), SIMDE_FLOAT32_C(-281.13), SIMDE_FLOAT32_C( 398.07), SIMDE_FLOAT32_C( 320.82)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-368.63), SIMDE_FLOAT32_C(-516.55), SIMDE_FLOAT32_C(-715.60), SIMDE_FLOAT32_C( 723.13)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -76.14), SIMDE_FLOAT32_C(  88.20), SIMDE_FLOAT32_C( 162.02), SIMDE_FLOAT32_C(-544.52)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -76.14), SIMDE_FLOAT32_C(  88.20), SIMDE_FLOAT32_C( 162.02), SIMDE_FLOAT32_C( 723.13)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  77.20), SIMDE_FLOAT32_C( 571.94), SIMDE_FLOAT32_C(-286.20), SIMDE_FLOAT32_C(-797.72)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 189.85), SIMDE_FLOAT32_C(-424.87), SIMDE_FLOAT32_C( 248.47), SIMDE_FLOAT32_C(-779.50)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 189.85), SIMDE_FLOAT32_C( 571.94), SIMDE_FLOAT32_C( 248.47), SIMDE_FLOAT32_C(-779.50)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 320.02), SIMDE_FLOAT32_C( 343.29), SIMDE_FLOAT32_C(-215.90), SIMDE_FLOAT32_C( 655.24)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 207.15), SIMDE_FLOAT32_C( -85.03), SIMDE_FLOAT32_C(-895.73), SIMDE_FLOAT32_C(-476.08)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 320.02), SIMDE_FLOAT32_C( 343.29), SIMDE_FLOAT32_C(-215.90), SIMDE_FLOAT32_C( 655.24)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_max(test_vec[i].a, test_vec[i].b);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_min(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 b;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-435.99), SIMDE_FLOAT32_C(-108.37), SIMDE_FLOAT32_C( -89.43), SIMDE_FLOAT32_C( -55.75)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 633.11), SIMDE_FLOAT32_C( 231.25), SIMDE_FLOAT32_C(-554.75), SIMDE_FLOAT32_C(-314.94)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-435.99), SIMDE_FLOAT32_C(-108.37), SIMDE_FLOAT32_C(-554.75), SIMDE_FLOAT32_C(-314.94)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 850.86), SIMDE_FLOAT32_C(-181.58), SIMDE_FLOAT32_C(-310.44), SIMDE_FLOAT32_C(-897.02)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 266.02), SIMDE_FLOAT32_C(-877.05), SIMDE_FLOAT32_C( 270.14), SIMDE_FLOAT32_C(-232.01)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 266.02), SIMDE_FLOAT32_C(-877.05), SIMDE_FLOAT32_C(-310.44), SIMDE_FLOAT32_C(-897.02)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 545.90), SIMDE_FLOAT32_C(-430.58), SIMDE_FLOAT32_C(-451.55), SIMDE_FLOAT32_C( -44.58)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 637.26), SIMDE_FLOAT32_C( 564.78), SIMDE_FLOAT32_C( 540.72), SIMDE_FLOAT32_C(-610.66)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 545.90), SIMDE_FLOAT32_C(-430.58), SIMDE_FLOAT32_C(-451.55), SIMDE_FLOAT32_C(-610.66)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 155.43), SIMDE_FLOAT32_C(-166.71), SIMDE_FLOAT32_C(-454.26), SIMDE_FLOAT32_C( 968.58)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 260.06), SIMDE_FLOAT32_C( 958.43), SIMDE_FLOAT32_C( 678.56), SIMDE_FLOAT32_C(-694.81)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 155.43), SIMDE_FLOAT32_C(-166.71), SIMDE_FLOAT32_C(-454.26), SIMDE_FLOAT32_C(-694.81)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 247.27), SIMDE_FLOAT32_C( 438.61), SIMDE_FLOAT32_C( 745.02), SIMDE_FLOAT32_C(-358.04)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-376.29), SIMDE_FLOAT32_C(-660.54), SIMDE_FLOAT32_C(-129.97), SIMDE_FLOAT32_C( 311.61)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-376.29), SIMDE_FLOAT32_C(-660.54), SIMDE_FLOAT32_C(-129.97), SIMDE_FLOAT32_C(-358.04)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-842.65), SIMDE_FLOAT32_C( 815.74), SIMDE_FLOAT32_C(-578.05), SIMDE_FLOAT32_C( 892.30)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 739.43), SIMDE_FLOAT32_C( 701.36), SIMDE_FLOAT32_C( 515.50), SIMDE_FLOAT32_C( 772.96)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-842.65), SIMDE_FLOAT32_C( 701.36), SIMDE_FLOAT32_C(-578.05), SIMDE_FLOAT32_C( 772.96)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 429.09), SIMDE_FLOAT32_C( 953.62), SIMDE_FLOAT32_C(-808.31), SIMDE_FLOAT32_C(-538.66)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-497.17), SIMDE_FLOAT32_C( -56.85), SIMDE_FLOAT32_C( 230.75), SIMDE_FLOAT32_C( 484.02)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-497.17), SIMDE_FLOAT32_C( -56.85), SIMDE_FLOAT32_C(-808.31), SIMDE_FLOAT32_C(-538.66)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 376.77), SIMDE_FLOAT32_C(-289.88), SIMDE_FLOAT32_C(-758.65), SIMDE_FLOAT32_C( -15.32)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-510.34), SIMDE_FLOAT32_C(-354.62), SIMDE_FLOAT32_C(-286.08), SIMDE_FLOAT32_C( 671.82)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-510.34), SIMDE_FLOAT32_C(-354.62), SIMDE_FLOAT32_C(-758.65), SIMDE_FLOAT32_C( -15.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_min(test_vec[i].a, test_vec[i].b);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_neg(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  74.67), SIMDE_FLOAT32_C(-979.92), SIMDE_FLOAT32_C( 858.73), SIMDE_FLOAT32_C( 464.55)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -74.67), SIMDE_FLOAT32_C( 979.92), SIMDE_FLOAT32_C(-858.73), SIMDE_FLOAT32_C(-464.55)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( -10.96), SIMDE_FLOAT32_C( 587.16), SIMDE_FLOAT32_C(  70.24), SIMDE_FLOAT32_C(-599.92)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  10.96), SIMDE_FLOAT32_C(-587.16), SIMDE_FLOAT32_C( -70.24), SIMDE_FLOAT32_C( 599.92)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 773.74), SIMDE_FLOAT32_C( 105.61), SIMDE_FLOAT32_C( 213.77), SIMDE_FLOAT32_C( 239.05)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-773.74), SIMDE_FLOAT32_C(-105.61), SIMDE_FLOAT32_C(-213.77), SIMDE_FLOAT32_C(-239.05)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 579.81), SIMDE_FLOAT32_C( 950.75), SIMDE_FLOAT32_C(-721.37), SIMDE_FLOAT32_C(-565.23)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-579.81), SIMDE_FLOAT32_C(-950.75), SIMDE_FLOAT32_C( 721.37), SIMDE_FLOAT32_C( 565.23)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  -2.99), SIMDE_FLOAT32_C( 957.13), SIMDE_FLOAT32_C(-308.61), SIMDE_FLOAT32_C( 175.10)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   2.99), SIMDE_FLOAT32_C(-957.13), SIMDE_FLOAT32_C( 308.61), SIMDE_FLOAT32_C(-175.10)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-983.57), SIMDE_FLOAT32_C( 710.26), SIMDE_FLOAT32_C(-380.24), SIMDE_FLOAT32_C(-756.98)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 983.57), SIMDE_FLOAT32_C(-710.26), SIMDE_FLOAT32_C( 380.24), SIMDE_FLOAT32_C( 756.98)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 155.97), SIMDE_FLOAT32_C( 739.35), SIMDE_FLOAT32_C( 570.57), SIMDE_FLOAT32_C( 716.80)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-155.97), SIMDE_FLOAT32_C(-739.35), SIMDE_FLOAT32_C(-570.57), SIMDE_FLOAT32_C(-716.80)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 970.64), SIMDE_FLOAT32_C(-457.47), SIMDE_FLOAT32_C( 154.68), SIMDE_FLOAT32_C(  63.43)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(-970.64), SIMDE_FLOAT32_C( 457.47), SIMDE_FLOAT32_C(-154.68), SIMDE_FLOAT32_C( -63.43)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_neg(test_vec[i].a);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_sqrt(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 765.37), SIMDE_FLOAT32_C( 863.20), SIMDE_FLOAT32_C( 617.64), SIMDE_FLOAT32_C( 541.74)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  27.67), SIMDE_FLOAT32_C(  29.38), SIMDE_FLOAT32_C(  24.85), SIMDE_FLOAT32_C(  23.28)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 358.64), SIMDE_FLOAT32_C( 457.66), SIMDE_FLOAT32_C( 659.02), SIMDE_FLOAT32_C( 934.27)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  18.94), SIMDE_FLOAT32_C(  21.39), SIMDE_FLOAT32_C(  25.67), SIMDE_FLOAT32_C(  30.57)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 849.39), SIMDE_FLOAT32_C( 691.72), SIMDE_FLOAT32_C(  18.74), SIMDE_FLOAT32_C( 613.87)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  29.14), SIMDE_FLOAT32_C(  26.30), SIMDE_FLOAT32_C(   4.33), SIMDE_FLOAT32_C(  24.78)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 806.26), SIMDE_FLOAT32_C( 130.97), SIMDE_FLOAT32_C( 943.29), SIMDE_FLOAT32_C( 628.32)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  28.39), SIMDE_FLOAT32_C(  11.44), SIMDE_FLOAT32_C(  30.71), SIMDE_FLOAT32_C(  25.07)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 580.90), SIMDE_FLOAT32_C( 996.93), SIMDE_FLOAT32_C( 347.03), SIMDE_FLOAT32_C( 423.10)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  24.10), SIMDE_FLOAT32_C(  31.57), SIMDE_FLOAT32_C(  18.63), SIMDE_FLOAT32_C(  20.57)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  65.77), SIMDE_FLOAT32_C( 725.86), SIMDE_FLOAT32_C(  47.94), SIMDE_FLOAT32_C( 650.87)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   8.11), SIMDE_FLOAT32_C(  26.94), SIMDE_FLOAT32_C(   6.92), SIMDE_FLOAT32_C(  25.51)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  89.29), SIMDE_FLOAT32_C( 407.90), SIMDE_FLOAT32_C( 966.93), SIMDE_FLOAT32_C( 955.92)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   9.45), SIMDE_FLOAT32_C(  20.20), SIMDE_FLOAT32_C(  31.10), SIMDE_FLOAT32_C(  30.92)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 922.66), SIMDE_FLOAT32_C( 645.97), SIMDE_FLOAT32_C( 743.28), SIMDE_FLOAT32_C( 497.99)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  30.38), SIMDE_FLOAT32_C(  25.42), SIMDE_FLOAT32_C(  27.26), SIMDE_FLOAT32_C(  22.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_sqrt(test_vec[i].a);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_reciprocalApproximation(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 93.40), SIMDE_FLOAT32_C(-80.40), SIMDE_FLOAT32_C( 32.70), SIMDE_FLOAT32_C( 28.20)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  0.01), SIMDE_FLOAT32_C( -0.01), SIMDE_FLOAT32_C(  0.03), SIMDE_FLOAT32_C(  0.04)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 86.80), SIMDE_FLOAT32_C( 41.60), SIMDE_FLOAT32_C( 53.30), SIMDE_FLOAT32_C(-39.00)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  0.01), SIMDE_FLOAT32_C(  0.02), SIMDE_FLOAT32_C(  0.02), SIMDE_FLOAT32_C( -0.03)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 22.90), SIMDE_FLOAT32_C(  2.10), SIMDE_FLOAT32_C( 23.70), SIMDE_FLOAT32_C(-73.20)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  0.04), SIMDE_FLOAT32_C(  0.48), SIMDE_FLOAT32_C(  0.04), SIMDE_FLOAT32_C( -0.01)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-12.30), SIMDE_FLOAT32_C(-12.40), SIMDE_FLOAT32_C( 61.70), SIMDE_FLOAT32_C( 69.20)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -0.08), SIMDE_FLOAT32_C( -0.08), SIMDE_FLOAT32_C(  0.02), SIMDE_FLOAT32_C(  0.01)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 89.10), SIMDE_FLOAT32_C(-50.90), SIMDE_FLOAT32_C(-88.90), SIMDE_FLOAT32_C(-42.00)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  0.01), SIMDE_FLOAT32_C( -0.02), SIMDE_FLOAT32_C( -0.01), SIMDE_FLOAT32_C( -0.02)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-77.90), SIMDE_FLOAT32_C(  3.10), SIMDE_FLOAT32_C(-34.10), SIMDE_FLOAT32_C(  2.20)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( -0.01), SIMDE_FLOAT32_C(  0.32), SIMDE_FLOAT32_C( -0.03), SIMDE_FLOAT32_C(  0.45)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 57.90), SIMDE_FLOAT32_C(-75.40), SIMDE_FLOAT32_C(  5.80), SIMDE_FLOAT32_C(-54.70)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  0.02), SIMDE_FLOAT32_C( -0.01), SIMDE_FLOAT32_C(  0.17), SIMDE_FLOAT32_C( -0.02)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 25.20), SIMDE_FLOAT32_C(-20.20), SIMDE_FLOAT32_C(-82.60), SIMDE_FLOAT32_C(-60.90)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(  0.04), SIMDE_FLOAT32_C( -0.05), SIMDE_FLOAT32_C( -0.01), SIMDE_FLOAT32_C( -0.02)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_reciprocalApproximation(test_vec[i].a);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_reciprocalSqrtApproximation(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 136.29), SIMDE_FLOAT32_C( 576.78), SIMDE_FLOAT32_C( 500.50), SIMDE_FLOAT32_C(  60.17)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.09), SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.13)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 568.27), SIMDE_FLOAT32_C( 931.10), SIMDE_FLOAT32_C( 853.10), SIMDE_FLOAT32_C( 406.71)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.03), SIMDE_FLOAT32_C(   0.03), SIMDE_FLOAT32_C(   0.05)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 598.71), SIMDE_FLOAT32_C( 521.78), SIMDE_FLOAT32_C( 949.45), SIMDE_FLOAT32_C( 545.63)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.03), SIMDE_FLOAT32_C(   0.04)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  71.28), SIMDE_FLOAT32_C( 896.24), SIMDE_FLOAT32_C( 742.99), SIMDE_FLOAT32_C( 443.78)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.12), SIMDE_FLOAT32_C(   0.03), SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.05)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  43.13), SIMDE_FLOAT32_C( 635.56), SIMDE_FLOAT32_C( 426.51), SIMDE_FLOAT32_C( 234.59)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.15), SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.05), SIMDE_FLOAT32_C(   0.07)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 191.86), SIMDE_FLOAT32_C( 726.59), SIMDE_FLOAT32_C( 914.65), SIMDE_FLOAT32_C( 169.94)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.07), SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.03), SIMDE_FLOAT32_C(   0.08)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(  66.83), SIMDE_FLOAT32_C( 839.00), SIMDE_FLOAT32_C( 848.78), SIMDE_FLOAT32_C( 611.06)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.12), SIMDE_FLOAT32_C(   0.03), SIMDE_FLOAT32_C(   0.03), SIMDE_FLOAT32_C(   0.04)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 680.19), SIMDE_FLOAT32_C( 409.14), SIMDE_FLOAT32_C( 300.51), SIMDE_FLOAT32_C( 993.37)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C(   0.04), SIMDE_FLOAT32_C(   0.05), SIMDE_FLOAT32_C(   0.06), SIMDE_FLOAT32_C(   0.03)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_reciprocalSqrtApproximation(test_vec[i].a);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_abs(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 r;
  } test_vec[8] = {
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-152.20), SIMDE_FLOAT32_C( 509.30), SIMDE_FLOAT32_C(-580.67), SIMDE_FLOAT32_C( 546.00)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 152.20), SIMDE_FLOAT32_C( 509.30), SIMDE_FLOAT32_C( 580.67), SIMDE_FLOAT32_C( 546.00)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 656.71), SIMDE_FLOAT32_C( -86.31), SIMDE_FLOAT32_C( 879.41), SIMDE_FLOAT32_C(-442.83)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 656.71), SIMDE_FLOAT32_C(  86.31), SIMDE_FLOAT32_C( 879.41), SIMDE_FLOAT32_C( 442.83)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 169.84), SIMDE_FLOAT32_C(-276.03), SIMDE_FLOAT32_C( 183.86), SIMDE_FLOAT32_C( 287.01)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 169.84), SIMDE_FLOAT32_C( 276.03), SIMDE_FLOAT32_C( 183.86), SIMDE_FLOAT32_C( 287.01)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-586.98), SIMDE_FLOAT32_C(-188.06), SIMDE_FLOAT32_C(-580.08), SIMDE_FLOAT32_C( 400.07)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 586.98), SIMDE_FLOAT32_C( 188.06), SIMDE_FLOAT32_C( 580.08), SIMDE_FLOAT32_C( 400.07)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 950.23), SIMDE_FLOAT32_C(-168.08), SIMDE_FLOAT32_C( 240.73), SIMDE_FLOAT32_C(-561.21)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 950.23), SIMDE_FLOAT32_C( 168.08), SIMDE_FLOAT32_C( 240.73), SIMDE_FLOAT32_C( 561.21)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C(-934.10), SIMDE_FLOAT32_C( 778.47), SIMDE_FLOAT32_C( 565.90), SIMDE_FLOAT32_C(-685.84)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 934.10), SIMDE_FLOAT32_C( 778.47), SIMDE_FLOAT32_C( 565.90), SIMDE_FLOAT32_C( 685.84)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 452.91), SIMDE_FLOAT32_C( 488.67), SIMDE_FLOAT32_C( 364.78), SIMDE_FLOAT32_C( 193.29)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 452.91), SIMDE_FLOAT32_C( 488.67), SIMDE_FLOAT32_C( 364.78), SIMDE_FLOAT32_C( 193.29)) },
    { simde_em_float32x4_set(SIMDE_FLOAT32_C( 960.01), SIMDE_FLOAT32_C(-748.39), SIMDE_FLOAT32_C(-307.93), SIMDE_FLOAT32_C( 386.62)),
      simde_em_float32x4_set(SIMDE_FLOAT32_C( 960.01), SIMDE_FLOAT32_C( 748.39), SIMDE_FLOAT32_C( 307.93), SIMDE_FLOAT32_C( 386.62)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_abs(test_vec[i].a);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  SIMD_JS_TEST_FUNC(float32x4, set),
  SIMD_JS_TEST_FUNC(float32x4, splat),
  SIMD_JS_TEST_FUNC(float32x4, add),
  SIMD_JS_TEST_FUNC(float32x4, sub),
  SIMD_JS_TEST_FUNC(float32x4, mul),
  SIMD_JS_TEST_FUNC(float32x4, div),
  SIMD_JS_TEST_FUNC(float32x4, max),
  SIMD_JS_TEST_FUNC(float32x4, min),
  SIMD_JS_TEST_FUNC(float32x4, neg),
  SIMD_JS_TEST_FUNC(float32x4, sqrt),
  SIMD_JS_TEST_FUNC(float32x4, reciprocalApproximation),
  SIMD_JS_TEST_FUNC(float32x4, reciprocalSqrtApproximation),
  SIMD_JS_TEST_FUNC(float32x4, abs),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_simd_js_float32x4_test_suite simde_simd_js_float32x4_emul_test_suite
#endif

MunitSuite simde_simd_js_float32x4_test_suite = {
  (char*) "/float32x4",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
