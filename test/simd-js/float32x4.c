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
      fprintf(stderr, "b: %8.2f %8.2f  %8.2f %8.2f\n", a.v[0], a.v[1], a.v[2], a.v[3]);
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

static MunitTest test_suite_tests[] = {
  SIMD_JS_TEST_FUNC(float32x4, set),
  SIMD_JS_TEST_FUNC(float32x4, splat),
  SIMD_JS_TEST_FUNC(float32x4, add),
  SIMD_JS_TEST_FUNC(float32x4, sub),
  SIMD_JS_TEST_FUNC(float32x4, mul),
  SIMD_JS_TEST_FUNC(float32x4, neg),

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
