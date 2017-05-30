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
      munit_errorf("assertion failed: %s[%" MUNIT_SIZE_MODIFIER "u] == %s[%" MUNIT_SIZE_MODIFIER "u] (%f == %f)",
		   a_, i, b_, i, a.v[i], b.v[i]);
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
    {                       { 404.63f,  234.68f,  286.84f,  743.61f},
      simde_em_float32x4_set( 404.63f,  234.68f,  286.84f,  743.61f) },
    {                       { 750.85f, -462.67f, -841.88f,  -59.14f},
      simde_em_float32x4_set( 750.85f, -462.67f, -841.88f,  -59.14f) },
    {                       {-101.29f, -113.38f,  841.41f, -810.17f},
      simde_em_float32x4_set(-101.29f, -113.38f,  841.41f, -810.17f) },
    {                       { 235.00f, -536.61f, -981.12f,  849.56f},
      simde_em_float32x4_set( 235.00f, -536.61f, -981.12f,  849.56f) },
    {                       {-249.12f, -945.93f,  -47.40f, -337.87f},
      simde_em_float32x4_set(-249.12f, -945.93f,  -47.40f, -337.87f) },
    {                       { 269.50f,  727.85f,  881.86f,  318.29f},
      simde_em_float32x4_set( 269.50f,  727.85f,  881.86f,  318.29f) },
    {                       { 945.79f,   -1.67f, -567.06f, -908.28f},
      simde_em_float32x4_set( 945.79f,   -1.67f, -567.06f, -908.28f) },
    {                       {-843.00f, -900.38f,  621.29f,  962.44f},
      simde_em_float32x4_set(-843.00f, -900.38f,  621.29f,  962.44f) }
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
    {  -40.27f, simde_em_float32x4_set( -40.00f,  -40.00f,  -40.00f,  -40.00f) },
    {   99.66f, simde_em_float32x4_set(  99.00f,   99.00f,   99.00f,   99.00f) },
    { -851.90f, simde_em_float32x4_set(-851.00f, -851.00f, -851.00f, -851.00f) },
    { -766.49f, simde_em_float32x4_set(-766.00f, -766.00f, -766.00f, -766.00f) },
    { -996.34f, simde_em_float32x4_set(-996.00f, -996.00f, -996.00f, -996.00f) },
    {  173.37f, simde_em_float32x4_set( 173.00f,  173.00f,  173.00f,  173.00f) },
    { -377.02f, simde_em_float32x4_set(-377.00f, -377.00f, -377.00f, -377.00f) },
    {  -45.45f, simde_em_float32x4_set( -45.00f,  -45.00f,  -45.00f,  -45.00f) }
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
    { simde_em_float32x4_set( -830.61f,  -120.33f,   764.57f,   954.33f),
      simde_em_float32x4_set(  518.18f,   410.47f,  -896.99f,   617.59f),
      simde_em_float32x4_set( -312.43f,   290.14f,  -132.42f,  1571.92f) },
    { simde_em_float32x4_set( -770.86f,  -315.57f,   -14.23f,   743.19f),
      simde_em_float32x4_set(  949.10f,  -680.45f,  -574.82f,   302.79f),
      simde_em_float32x4_set(  178.24f,  -996.02f,  -589.05f,  1045.98f) },
    { simde_em_float32x4_set(  629.82f,   938.17f,  -579.84f,  -347.97f),
      simde_em_float32x4_set( -256.37f,   947.23f,  -975.04f,  -277.65f),
      simde_em_float32x4_set(  373.45f,  1885.40f, -1554.88f,  -625.62f) },
    { simde_em_float32x4_set(  349.82f,  -675.10f,   819.46f,   527.76f),
      simde_em_float32x4_set(  734.84f,  -265.17f,  -771.61f,   812.61f),
      simde_em_float32x4_set( 1084.66f,  -940.27f,    47.85f,  1340.37f) },
    { simde_em_float32x4_set( -786.91f,   856.69f,   127.21f,  -495.46f),
      simde_em_float32x4_set( -209.48f,   351.08f,  -635.55f,  -151.53f),
      simde_em_float32x4_set( -996.39f,  1207.77f,  -508.34f,  -646.99f) },
    { simde_em_float32x4_set( -585.65f,  -152.87f,  -468.40f,   319.48f),
      simde_em_float32x4_set(  496.22f,   428.17f,   378.21f,  -946.08f),
      simde_em_float32x4_set(  -89.43f,   275.30f,   -90.19f,  -626.60f) },
    { simde_em_float32x4_set( -461.54f,   643.88f,   -80.76f,  -642.03f),
      simde_em_float32x4_set( -167.58f,  -918.24f,  -418.74f,   265.85f),
      simde_em_float32x4_set( -629.12f,  -274.36f,  -499.50f,  -376.18f) },
    { simde_em_float32x4_set(  621.31f,   920.65f,  -657.19f,  -591.79f),
      simde_em_float32x4_set( -685.20f,  -986.56f,    71.12f,  -230.90f),
      simde_em_float32x4_set(  -63.89f,   -65.91f,  -586.07f,  -822.69f) }
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
    { simde_em_float32x4_set(  678.96f,   599.66f,  -843.45f,    13.44f),
      simde_em_float32x4_set(  235.79f,  -446.91f,   -55.38f,   982.69f),
      simde_em_float32x4_set(  443.17f,  1046.57f,  -788.07f,  -969.25f) },
    { simde_em_float32x4_set( -887.89f,  -753.69f,   -88.13f,  -408.47f),
      simde_em_float32x4_set(  265.85f,   -43.11f,  -327.06f,   232.90f),
      simde_em_float32x4_set(-1153.74f,  -710.58f,   238.93f,  -641.37f) },
    { simde_em_float32x4_set( -682.14f,  -961.44f,   638.73f,   796.97f),
      simde_em_float32x4_set(  237.23f,    19.65f,   377.57f,   350.27f),
      simde_em_float32x4_set( -919.37f,  -981.09f,   261.16f,   446.70f) },
    { simde_em_float32x4_set(  140.04f,   258.87f,  -251.75f,  -343.99f),
      simde_em_float32x4_set( -797.56f,   871.26f,  -555.47f,   750.81f),
      simde_em_float32x4_set(  937.60f,  -612.39f,   303.72f, -1094.80f) },
    { simde_em_float32x4_set( -716.17f,   119.97f,  -336.21f,    68.81f),
      simde_em_float32x4_set(  622.27f,  -761.35f,  -255.09f,   966.51f),
      simde_em_float32x4_set(-1338.44f,   881.32f,   -81.12f,  -897.70f) },
    { simde_em_float32x4_set( -469.23f,  -594.03f,   188.15f,  -996.40f),
      simde_em_float32x4_set(  493.52f,   444.99f,  -482.25f,   345.36f),
      simde_em_float32x4_set( -962.75f, -1039.02f,   670.40f, -1341.76f) },
    { simde_em_float32x4_set( -637.13f,  -619.25f,   350.47f,   645.63f),
      simde_em_float32x4_set( -700.88f,  -408.50f,  -582.48f,   557.37f),
      simde_em_float32x4_set(   63.75f,  -210.75f,   932.95f,    88.26f) },
    { simde_em_float32x4_set( -619.39f,   215.55f,   201.10f,  -714.73f),
      simde_em_float32x4_set(  420.23f,  -835.72f,   496.41f,  -535.52f),
      simde_em_float32x4_set(-1039.62f,  1051.27f,  -295.31f,  -179.21f) }
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
    { simde_em_float32x4_set(  -820.57f,    872.03f,     36.57f,     51.79f),
      simde_em_float32x4_set(  -176.39f,   -152.79f,   -176.35f,   -560.55f),
      simde_em_float32x4_set(144740.34f, -133237.47f,  -6449.12f, -29030.88f) },
    { simde_em_float32x4_set(  -693.03f,   -159.50f,   -310.78f,    704.89f),
      simde_em_float32x4_set(    62.32f,   -795.36f,   -506.14f,   -676.79f),
      simde_em_float32x4_set(-43189.63f, 126859.91f, 157298.19f, -477062.50f) },
    { simde_em_float32x4_set(   164.24f,    272.96f,    238.69f,    704.38f),
      simde_em_float32x4_set(  -940.33f,    162.96f,    863.21f,    311.69f),
      simde_em_float32x4_set(-154439.81f,  44481.56f, 206039.61f, 219548.20f) },
    { simde_em_float32x4_set(  -504.80f,    635.76f,   -866.83f,   -625.52f),
      simde_em_float32x4_set(  -629.76f,    970.05f,   -416.47f,     75.79f),
      simde_em_float32x4_set(317902.84f, 616719.00f, 361008.69f, -47408.16f) },
    { simde_em_float32x4_set(   150.80f,   -847.78f,    -63.33f,    795.79f),
      simde_em_float32x4_set(  -148.59f,   -778.33f,   -661.10f,    231.61f),
      simde_em_float32x4_set(-22407.37f, 659852.62f,  41867.46f, 184312.92f) },
    { simde_em_float32x4_set(   332.65f,    -82.10f,   -162.60f,    482.09f),
      simde_em_float32x4_set(   437.81f,    310.52f,    564.10f,   -975.60f),
      simde_em_float32x4_set(145637.50f, -25493.69f, -91722.66f, -470327.00f) },
    { simde_em_float32x4_set(  -781.95f,    303.09f,    692.95f,   -326.78f),
      simde_em_float32x4_set(   -18.02f,   -683.58f,   -857.66f,    -88.60f),
      simde_em_float32x4_set( 14090.74f, -207186.27f, -594315.50f,  28952.71f) },
    { simde_em_float32x4_set(    69.36f,    339.57f,    797.99f,   -654.75f),
      simde_em_float32x4_set(  -891.44f,    999.45f,    621.64f,   -977.90f),
      simde_em_float32x4_set(-61830.28f, 339383.25f, 496062.50f, 640280.06f) }
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
    { simde_em_float32x4_set( 174.53,  589.72,  126.11,  783.16),
      simde_em_float32x4_set( 365.14, -305.45, -915.07,  861.88),
      simde_em_float32x4_set(   0.48,   -1.93,   -0.14,    0.91) },
    { simde_em_float32x4_set(-671.87, -523.51,  416.45,  657.80),
      simde_em_float32x4_set( -36.67, -261.08, -414.96, -389.37),
      simde_em_float32x4_set(  18.32,    2.01,   -1.00,   -1.69) },
    { simde_em_float32x4_set(-245.49,  511.70, -254.98,  337.57),
      simde_em_float32x4_set(-553.82,  951.63, -803.16,  198.14),
      simde_em_float32x4_set(   0.44,    0.54,    0.32,    1.70) },
    { simde_em_float32x4_set( 772.61, -444.55, -922.71,  140.78),
      simde_em_float32x4_set( 866.48,  410.81,  661.80, -542.62),
      simde_em_float32x4_set(   0.89,   -1.08,   -1.39,   -0.26) },
    { simde_em_float32x4_set(-629.54, -880.50, -575.75,  393.64),
      simde_em_float32x4_set(-570.90, -967.32, -391.88,  442.98),
      simde_em_float32x4_set(   1.10,    0.91,    1.47,    0.89) },
    { simde_em_float32x4_set( 147.62, -703.04, -358.60, -433.16),
      simde_em_float32x4_set( 495.05, -195.88,  227.39, -122.80),
      simde_em_float32x4_set(   0.30,    3.59,   -1.58,    3.53) },
    { simde_em_float32x4_set(-252.47,  138.37,  460.35, -286.62),
      simde_em_float32x4_set(-293.89, -257.43, -540.44,  752.87),
      simde_em_float32x4_set(   0.86,   -0.54,   -0.85,   -0.38) },
    { simde_em_float32x4_set( 748.77,  551.14, -315.72,  712.78),
      simde_em_float32x4_set( 686.27,   48.29,  609.68,  323.46),
      simde_em_float32x4_set(   1.09,   11.41,   -0.52,    2.20) }
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
    { simde_em_float32x4_set( 351.79, -991.10, -974.91,  547.84),
      simde_em_float32x4_set(-799.63,  473.61, -367.79, -731.89),
      simde_em_float32x4_set( 351.79,  473.61, -367.79,  547.84) },
    { simde_em_float32x4_set( 541.66,  779.90,  630.79,  694.34),
      simde_em_float32x4_set(-347.62,  997.13,  -31.67,  978.45),
      simde_em_float32x4_set( 541.66,  997.13,  630.79,  978.45) },
    { simde_em_float32x4_set(-163.03, -917.39, -676.54, -531.65),
      simde_em_float32x4_set( 531.90, -880.53, -338.38, -804.75),
      simde_em_float32x4_set( 531.90, -880.53, -338.38, -531.65) },
    { simde_em_float32x4_set( -81.16, -467.70, -993.29, -662.90),
      simde_em_float32x4_set(-132.21,  630.89, -934.35,  317.85),
      simde_em_float32x4_set( -81.16,  630.89, -934.35,  317.85) },
    { simde_em_float32x4_set( 242.81,  315.49,  204.21,  404.36),
      simde_em_float32x4_set( 175.26,  203.56, -600.36, -177.21),
      simde_em_float32x4_set( 242.81,  315.49,  204.21,  404.36) },
    { simde_em_float32x4_set(-432.56, -782.58,  273.39,   49.06),
      simde_em_float32x4_set(-884.62,  125.20,  546.47,   95.38),
      simde_em_float32x4_set(-432.56,  125.20,  546.47,   95.38) },
    { simde_em_float32x4_set(-876.55,  562.09,    7.56,  165.49),
      simde_em_float32x4_set( -64.93, -368.10,  479.79, -923.54),
      simde_em_float32x4_set( -64.93,  562.09,  479.79,  165.49) },
    { simde_em_float32x4_set( 482.98, -883.06,  312.21,  977.07),
      simde_em_float32x4_set(-943.70,  252.49,  430.60,  698.90),
      simde_em_float32x4_set( 482.98,  252.49,  430.60,  977.07) }
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
    { simde_em_float32x4_set( 719.13, -763.38,   86.07, -837.88),
      simde_em_float32x4_set(  12.77, -864.63,  417.28, -952.55),
      simde_em_float32x4_set(  12.77, -864.63,   86.07, -952.55) },
    { simde_em_float32x4_set(-403.31,  -43.43,  813.50, -347.96),
      simde_em_float32x4_set( 291.95, -295.88,  540.56,   56.18),
      simde_em_float32x4_set(-403.31, -295.88,  540.56, -347.96) },
    { simde_em_float32x4_set(-724.58,  837.92, -350.25, -116.61),
      simde_em_float32x4_set(  68.77, -895.80,  402.41,  902.84),
      simde_em_float32x4_set(-724.58, -895.80, -350.25, -116.61) },
    { simde_em_float32x4_set(-259.60,  357.34, -450.05,  117.02),
      simde_em_float32x4_set(-932.80, -262.20,  970.91, -667.85),
      simde_em_float32x4_set(-932.80, -262.20, -450.05, -667.85) },
    { simde_em_float32x4_set(-458.74, -592.88,  785.83,  -89.14),
      simde_em_float32x4_set( 944.07, -671.55, -103.93, -936.31),
      simde_em_float32x4_set(-458.74, -671.55, -103.93, -936.31) },
    { simde_em_float32x4_set(  39.15,  572.17, -143.64,  134.64),
      simde_em_float32x4_set( 941.26,  459.48,  328.60, -507.30),
      simde_em_float32x4_set(  39.15,  459.48, -143.64, -507.30) },
    { simde_em_float32x4_set( -68.59, -600.82,  612.46,  152.37),
      simde_em_float32x4_set(-380.92, -151.36,   70.58,  336.05),
      simde_em_float32x4_set(-380.92, -600.82,   70.58,  152.37) },
    { simde_em_float32x4_set(-110.87,  435.53,  134.99,  349.38),
      simde_em_float32x4_set( 817.34, -672.00,  960.93,  771.14),
      simde_em_float32x4_set(-110.87, -672.00,  134.99,  349.38) }
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
    { simde_em_float32x4_set( -542.09,   -38.92,   622.71,   561.46),
      simde_em_float32x4_set(  542.09,    38.92,  -622.71,  -561.46) },
    { simde_em_float32x4_set(  271.22,  -323.14,  -716.79,   746.60),
      simde_em_float32x4_set( -271.22,   323.14,   716.79,  -746.60) },
    { simde_em_float32x4_set(  -96.69,   127.05,  -663.87,   -86.26),
      simde_em_float32x4_set(   96.69,  -127.05,   663.87,    86.26) },
    { simde_em_float32x4_set( -608.08,   501.30,   964.38,  -864.80),
      simde_em_float32x4_set(  608.08,  -501.30,  -964.38,   864.80) },
    { simde_em_float32x4_set(  556.32,   346.15,   -39.01,   163.09),
      simde_em_float32x4_set( -556.32,  -346.15,    39.01,  -163.09) },
    { simde_em_float32x4_set(  247.25,   621.85,   982.44,   465.74),
      simde_em_float32x4_set( -247.25,  -621.85,  -982.44,  -465.74) },
    { simde_em_float32x4_set(  202.48,  -428.69,   -13.37,  -831.32),
      simde_em_float32x4_set( -202.48,   428.69,    13.37,   831.32) },
    { simde_em_float32x4_set(   97.41,  -404.66,    53.41,   405.89),
      simde_em_float32x4_set(  -97.41,   404.66,   -53.41,  -405.89) }
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
    { simde_em_float32x4_set(592.28, 201.57, 831.38, 716.38),
      simde_em_float32x4_set( 24.34,  14.20,  28.83,  26.77) },
    { simde_em_float32x4_set(828.99, 185.53,  12.52, 997.92),
      simde_em_float32x4_set( 28.79,  13.62,   3.54,  31.59) },
    { simde_em_float32x4_set(640.39, 739.78, 751.16, 408.06),
      simde_em_float32x4_set( 25.31,  27.20,  27.41,  20.20) },
    { simde_em_float32x4_set(441.60, 653.06, 949.93, 996.81),
      simde_em_float32x4_set( 21.01,  25.56,  30.82,  31.57) },
    { simde_em_float32x4_set(533.29, 826.83, 957.35, 649.17),
      simde_em_float32x4_set( 23.09,  28.75,  30.94,  25.48) },
    { simde_em_float32x4_set(137.46,  53.06, 859.32, 683.49),
      simde_em_float32x4_set( 11.72,   7.28,  29.31,  26.14) },
    { simde_em_float32x4_set(345.43, 286.01, 583.82, 455.58),
      simde_em_float32x4_set( 18.59,  16.91,  24.16,  21.34) },
    { simde_em_float32x4_set(327.74,  69.69, 384.37, 951.57),
      simde_em_float32x4_set( 18.10,   8.35,  19.61,  30.85) }
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
    { simde_em_float32x4_set( -590.54,   -52.74,  -155.37,  -122.51),
      simde_em_float32x4_set(   -0.00,    -0.02,    -0.01,    -0.01) },
    { simde_em_float32x4_set( -692.64,    39.44,  -818.15,   550.54),
      simde_em_float32x4_set(   -0.00,     0.03,    -0.00,     0.00) },
    { simde_em_float32x4_set(  843.46,  -916.67,  -556.75,   345.52),
      simde_em_float32x4_set(    0.00,    -0.00,    -0.00,     0.00) },
    { simde_em_float32x4_set( -570.25,  -590.37,   161.05,   317.58),
      simde_em_float32x4_set(   -0.00,    -0.00,     0.01,     0.00) },
    { simde_em_float32x4_set(   86.44,  -710.63,  -269.99,   895.79),
      simde_em_float32x4_set(    0.01,    -0.00,    -0.00,     0.00) },
    { simde_em_float32x4_set(  796.62,  -446.44,   495.30,  -108.28),
      simde_em_float32x4_set(    0.00,    -0.00,     0.00,    -0.01) },
    { simde_em_float32x4_set( -682.29,  -425.52,  -534.07,  -645.66),
      simde_em_float32x4_set(   -0.00,    -0.00,    -0.00,    -0.00) },
    { simde_em_float32x4_set( -456.79,   391.79,  -752.69,  -273.82),
      simde_em_float32x4_set(   -0.00,     0.00,    -0.00,    -0.00) }
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
    { simde_em_float32x4_set(170.38, 295.38, 762.40, 382.38),
      simde_em_float32x4_set(  0.08,   0.06,   0.04,   0.05) },
    { simde_em_float32x4_set(112.04, 798.81,  23.63, 690.92),
      simde_em_float32x4_set(  0.09,   0.04,   0.21,   0.04) },
    { simde_em_float32x4_set(613.95, 938.56, 239.42, 333.33),
      simde_em_float32x4_set(  0.04,   0.03,   0.06,   0.05) },
    { simde_em_float32x4_set(858.90, 269.40, 719.68, 523.91),
      simde_em_float32x4_set(  0.03,   0.06,   0.04,   0.04) },
    { simde_em_float32x4_set(453.36,  24.25, 397.32, 894.42),
      simde_em_float32x4_set(  0.05,   0.20,   0.05,   0.03) },
    { simde_em_float32x4_set(446.54, 671.26, 635.99, 794.66),
      simde_em_float32x4_set(  0.05,   0.04,   0.04,   0.04) },
    { simde_em_float32x4_set(687.70, 323.54, 997.05, 129.72),
      simde_em_float32x4_set(  0.04,   0.06,   0.03,   0.09) },
    { simde_em_float32x4_set(743.90, 245.13, 398.54, 649.75),
      simde_em_float32x4_set(  0.04,   0.06,   0.05,   0.04) }
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
    { simde_em_float32x4_set( 337.22,  531.25, -582.00,  724.58),
      simde_em_float32x4_set( 337.22,  531.25,  582.00,  724.58) },
    { simde_em_float32x4_set(-260.26,  504.92,  159.80,  235.10),
      simde_em_float32x4_set( 260.26,  504.92,  159.80,  235.10) },
    { simde_em_float32x4_set(  94.14, -135.81, -255.39,  202.16),
      simde_em_float32x4_set(  94.14,  135.81,  255.39,  202.16) },
    { simde_em_float32x4_set(  13.09, -713.07,   26.09,  475.48),
      simde_em_float32x4_set(  13.09,  713.07,   26.09,  475.48) },
    { simde_em_float32x4_set(-907.50,  627.28, -963.83,  566.55),
      simde_em_float32x4_set( 907.50,  627.28,  963.83,  566.55) },
    { simde_em_float32x4_set( 890.68, -524.61,  628.68, -220.49),
      simde_em_float32x4_set( 890.68,  524.61,  628.68,  220.49) },
    { simde_em_float32x4_set(-273.99, -202.14,  831.07, -643.02),
      simde_em_float32x4_set( 273.99,  202.14,  831.07,  643.02) },
    { simde_em_float32x4_set( 953.46, -884.05,  645.13, -364.98),
      simde_em_float32x4_set( 953.46,  884.05,  645.13,  364.98) }
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
