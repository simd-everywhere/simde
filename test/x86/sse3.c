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

#define SIMDE_TESTS_CURRENT_ISAX sse3
#include <simde/x86/sse3.h>
#include <test/x86/test-sse2.h>

#if defined(SIMDE_SSE3_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm_addsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  476.02,  -639.97),
      simde_mm_set_pd(  710.19,   -41.14),
      simde_mm_set_pd( 1186.21,  -598.83) },
    { simde_mm_set_pd(  650.79,  -848.27),
      simde_mm_set_pd(  773.15,   711.98),
      simde_mm_set_pd( 1423.94, -1560.25) },
    { simde_mm_set_pd( -904.77,  -447.30),
      simde_mm_set_pd( -414.59,  -690.17),
      simde_mm_set_pd(-1319.36,   242.87) },
    { simde_mm_set_pd(  727.10,   -46.44),
      simde_mm_set_pd( -635.38,    20.27),
      simde_mm_set_pd(   91.72,   -66.71) },
    { simde_mm_set_pd(   74.87,  -444.69),
      simde_mm_set_pd( -222.00,   809.16),
      simde_mm_set_pd( -147.13, -1253.85) },
    { simde_mm_set_pd(  468.30,  -546.58),
      simde_mm_set_pd(  629.89,   504.95),
      simde_mm_set_pd( 1098.19, -1051.53) },
    { simde_mm_set_pd(  908.04,  -977.41),
      simde_mm_set_pd(  521.23,  -249.10),
      simde_mm_set_pd( 1429.27,  -728.31) },
    { simde_mm_set_pd(  107.41,  -431.12),
      simde_mm_set_pd(   91.73,   142.37),
      simde_mm_set_pd(  199.14,  -573.49) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_addsub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_addsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(  827.09f,   888.55f,   270.24f,   512.98f),
      simde_mm_set_ps(  691.09f,   805.07f,   343.35f,   695.79f),
      simde_mm_set_ps( 1518.18f,    83.48f,   613.59f,  -182.81f) },
    { simde_mm_set_ps( -122.09f,   678.17f,  -910.24f,  -995.98f),
      simde_mm_set_ps( -197.90f,   177.04f,  -469.81f,  -451.24f),
      simde_mm_set_ps( -319.99f,   501.13f, -1380.05f,  -544.74f) },
    { simde_mm_set_ps(  589.86f,  -922.72f,   221.54f,  -598.55f),
      simde_mm_set_ps( -751.93f,   480.30f,   218.06f,   103.71f),
      simde_mm_set_ps( -162.07f, -1403.02f,   439.60f,  -702.26f) },
    { simde_mm_set_ps( -375.10f,   590.75f,   672.39f,   216.94f),
      simde_mm_set_ps(  184.12f,   575.54f,  -189.52f,   591.53f),
      simde_mm_set_ps( -190.98f,    15.21f,   482.87f,  -374.59f) },
    { simde_mm_set_ps(  838.92f,  -777.48f,  -357.82f,   473.60f),
      simde_mm_set_ps(  655.27f,  -960.61f,   194.84f,   470.24f),
      simde_mm_set_ps( 1494.19f,   183.13f,  -162.98f,     3.36f) },
    { simde_mm_set_ps(  141.50f,   865.93f,   836.92f,   780.12f),
      simde_mm_set_ps(  237.78f,  -664.15f,   934.51f,   175.34f),
      simde_mm_set_ps(  379.28f,  1530.08f,  1771.43f,   604.78f) },
    { simde_mm_set_ps( -146.63f,   845.58f,  -575.02f,  -435.05f),
      simde_mm_set_ps(   46.98f,   315.33f,  -622.74f,  -392.97f),
      simde_mm_set_ps(  -99.65f,   530.25f, -1197.76f,   -42.08f) },
    { simde_mm_set_ps( -588.54f,   208.80f,    44.42f,  -534.81f),
      simde_mm_set_ps(  849.82f,  -315.73f,  -758.03f,   754.33f),
      simde_mm_set_ps(  261.28f,   524.53f,  -713.61f, -1289.14f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_addsub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hadd_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(   44.10,  -542.35),
      simde_mm_set_pd( -346.60,  -427.89),
      simde_mm_set_pd( -774.49,  -498.25) },
    { simde_mm_set_pd(  716.10,   840.74),
      simde_mm_set_pd( -654.24,  -672.74),
      simde_mm_set_pd(-1326.98,  1556.84) },
    { simde_mm_set_pd( -397.69,   265.98),
      simde_mm_set_pd( -595.53,   562.15),
      simde_mm_set_pd(  -33.38,  -131.71) },
    { simde_mm_set_pd(  416.44,   929.19),
      simde_mm_set_pd( -225.30,  -546.63),
      simde_mm_set_pd( -771.93,  1345.63) },
    { simde_mm_set_pd(  506.73,   886.11),
      simde_mm_set_pd(  344.49,   957.84),
      simde_mm_set_pd( 1302.33,  1392.84) },
    { simde_mm_set_pd(  886.60,  -404.84),
      simde_mm_set_pd(  386.06,  -275.34),
      simde_mm_set_pd(  110.72,   481.76) },
    { simde_mm_set_pd(    4.86,   401.30),
      simde_mm_set_pd(  316.75,   350.77),
      simde_mm_set_pd(  667.52,   406.16) },
    { simde_mm_set_pd( -409.95,   357.27),
      simde_mm_set_pd( -949.43,  -786.56),
      simde_mm_set_pd(-1735.99,   -52.68) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_hadd_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hadd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(  732.68f,  -915.27f,  -191.77f,  -862.58f),
      simde_mm_set_ps(   81.80f,   547.56f,   259.82f,    55.94f),
      simde_mm_set_ps(  629.36f,   315.76f,  -182.59f, -1054.35f) },
    { simde_mm_set_ps(  429.35f,  -314.15f,  -691.69f,  -113.96f),
      simde_mm_set_ps( -636.15f,   881.85f,   515.05f,  -694.57f),
      simde_mm_set_ps(  245.70f,  -179.52f,   115.20f,  -805.65f) },
    { simde_mm_set_ps(  163.17f,   585.35f,   889.94f,   989.94f),
      simde_mm_set_ps(  558.88f,  -287.71f,   978.54f,  -729.07f),
      simde_mm_set_ps(  271.17f,   249.47f,   748.52f,  1879.88f) },
    { simde_mm_set_ps(  396.52f,   255.51f,   531.47f,  -510.49f),
      simde_mm_set_ps( -162.17f,   929.03f,  -176.85f,   827.75f),
      simde_mm_set_ps(  766.86f,   650.90f,   652.03f,    20.98f) },
    { simde_mm_set_ps(  348.14f,  -946.97f,  -177.74f,   520.68f),
      simde_mm_set_ps(  339.94f,   653.25f,   168.00f,   216.81f),
      simde_mm_set_ps(  993.19f,   384.81f,  -598.83f,   342.94f) },
    { simde_mm_set_ps( -341.20f,  -395.72f,  -751.71f,   483.71f),
      simde_mm_set_ps(  214.25f,   187.29f,   627.65f,  -993.70f),
      simde_mm_set_ps(  401.54f,  -366.05f,  -736.92f,  -268.00f) },
    { simde_mm_set_ps( -117.08f,  -155.79f,   327.94f,  -604.45f),
      simde_mm_set_ps( -924.11f,    -3.93f,  -496.48f,  -281.24f),
      simde_mm_set_ps( -928.04f,  -777.72f,  -272.87f,  -276.51f) },
    { simde_mm_set_ps( -207.92f,   955.09f,   949.83f,  -476.81f),
      simde_mm_set_ps( -883.98f,   810.86f,   947.09f,  -558.58f),
      simde_mm_set_ps(  -73.12f,   388.51f,   747.17f,   473.02f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_hadd_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  -15.50,   258.33),
      simde_mm_set_pd(  484.94,  -432.56),
      simde_mm_set_pd( -917.50,   273.83) },
    { simde_mm_set_pd(   50.11,  -735.38),
      simde_mm_set_pd(   70.36,   538.50),
      simde_mm_set_pd(  468.14,  -785.49) },
    { simde_mm_set_pd(  140.13,  -672.00),
      simde_mm_set_pd( -602.17,  -745.12),
      simde_mm_set_pd( -142.95,  -812.13) },
    { simde_mm_set_pd(    1.89,  -114.93),
      simde_mm_set_pd(  125.81,   137.32),
      simde_mm_set_pd(   11.51,  -116.82) },
    { simde_mm_set_pd( -579.13,  -899.36),
      simde_mm_set_pd(  893.51,   328.15),
      simde_mm_set_pd( -565.36,  -320.23) },
    { simde_mm_set_pd( -275.68,  -217.61),
      simde_mm_set_pd(  167.25,   -93.39),
      simde_mm_set_pd( -260.64,    58.07) },
    { simde_mm_set_pd(  312.59,   137.63),
      simde_mm_set_pd(  589.59,   751.69),
      simde_mm_set_pd(  162.10,  -174.96) },
    { simde_mm_set_pd(  359.94,  -880.43),
      simde_mm_set_pd(  239.69,  -581.16),
      simde_mm_set_pd( -820.85, -1240.37) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_hsub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(   50.11f,  -735.38f,   -15.50f,   258.33f),
      simde_mm_set_ps(   70.36f,   538.50f,   484.94f,  -432.56f),
      simde_mm_set_ps(  468.14f,  -917.50f,  -785.49f,   273.83f) },
    { simde_mm_set_ps(    1.89f,  -114.93f,   140.13f,  -672.00f),
      simde_mm_set_ps(  125.81f,   137.32f,  -602.17f,  -745.12f),
      simde_mm_set_ps(   11.51f,  -142.95f,  -116.82f,  -812.13f) },
    { simde_mm_set_ps( -275.68f,  -217.61f,  -579.13f,  -899.36f),
      simde_mm_set_ps(  167.25f,   -93.39f,   893.51f,   328.15f),
      simde_mm_set_ps( -260.64f,  -565.36f,    58.07f,  -320.23f) },
    { simde_mm_set_ps(  359.94f,  -880.43f,   312.59f,   137.63f),
      simde_mm_set_ps(  239.69f,  -581.16f,   589.59f,   751.69f),
      simde_mm_set_ps( -820.85f,   162.10f, -1240.37f,  -174.96f) },
    { simde_mm_set_ps(  923.43f,   905.56f,  -615.92f,   454.60f),
      simde_mm_set_ps(  375.63f,   326.29f,  -819.79f,  -550.42f),
      simde_mm_set_ps(  -49.34f,   269.37f,   -17.87f,  1070.52f) },
    { simde_mm_set_ps(  344.96f,   -84.73f,  -925.77f,   984.26f),
      simde_mm_set_ps(  584.98f,   981.58f,  -824.48f,   268.25f),
      simde_mm_set_ps(  396.60f,  1092.73f,  -429.69f,  1910.03f) },
    { simde_mm_set_ps(  405.32f,   -74.19f,   712.30f,   820.93f),
      simde_mm_set_ps( -939.26f,  -768.80f,  -854.21f,   -69.68f),
      simde_mm_set_ps(  170.46f,   784.53f,  -479.51f,   108.63f) },
    { simde_mm_set_ps( -199.94f,   783.57f,   779.03f,   578.25f),
      simde_mm_set_ps(  177.19f,  -819.96f,   -14.40f,   361.82f),
      simde_mm_set_ps( -997.15f,   376.22f,   983.51f,  -200.78f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_hsub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_lddqu_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-112), INT8_C( 117), INT8_C( -34), INT8_C(  65), INT8_C(  -1), INT8_C(  38), INT8_C(  89), INT8_C(-126),
                        INT8_C(  67), INT8_C( -47), INT8_C( -14), INT8_C( -14), INT8_C( -36), INT8_C(  93), INT8_C(  67), INT8_C( -57)),
      simde_mm_set_epi8(INT8_C(-112), INT8_C( 117), INT8_C( -34), INT8_C(  65), INT8_C(  -1), INT8_C(  38), INT8_C(  89), INT8_C(-126),
                        INT8_C(  67), INT8_C( -47), INT8_C( -14), INT8_C( -14), INT8_C( -36), INT8_C(  93), INT8_C(  67), INT8_C( -57)) },
    { simde_mm_set_epi8(INT8_C(  35), INT8_C( -25), INT8_C(  29), INT8_C(-117), INT8_C( -37), INT8_C( 120), INT8_C(-105), INT8_C( 106),
                        INT8_C(   4), INT8_C(  73), INT8_C( -55), INT8_C( -70), INT8_C(  11), INT8_C( -15), INT8_C( -35), INT8_C(-116)),
      simde_mm_set_epi8(INT8_C(  35), INT8_C( -25), INT8_C(  29), INT8_C(-117), INT8_C( -37), INT8_C( 120), INT8_C(-105), INT8_C( 106),
                        INT8_C(   4), INT8_C(  73), INT8_C( -55), INT8_C( -70), INT8_C(  11), INT8_C( -15), INT8_C( -35), INT8_C(-116)) },
    { simde_mm_set_epi8(INT8_C(-101), INT8_C(-119), INT8_C(  63), INT8_C(-115), INT8_C( -96), INT8_C( -31), INT8_C( -21), INT8_C(  40),
                        INT8_C(  85), INT8_C( 109), INT8_C(-125), INT8_C( -15), INT8_C(  21), INT8_C( -59), INT8_C( -50), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C(-101), INT8_C(-119), INT8_C(  63), INT8_C(-115), INT8_C( -96), INT8_C( -31), INT8_C( -21), INT8_C(  40),
                        INT8_C(  85), INT8_C( 109), INT8_C(-125), INT8_C( -15), INT8_C(  21), INT8_C( -59), INT8_C( -50), INT8_C( 101)) },
    { simde_mm_set_epi8(INT8_C( -59), INT8_C( 124), INT8_C(  14), INT8_C( -11), INT8_C(   3), INT8_C( -21), INT8_C(  36), INT8_C(-103),
                        INT8_C( -34), INT8_C( -66), INT8_C(  35), INT8_C(  90), INT8_C(  43), INT8_C( -21), INT8_C( -53), INT8_C( -61)),
      simde_mm_set_epi8(INT8_C( -59), INT8_C( 124), INT8_C(  14), INT8_C( -11), INT8_C(   3), INT8_C( -21), INT8_C(  36), INT8_C(-103),
                        INT8_C( -34), INT8_C( -66), INT8_C(  35), INT8_C(  90), INT8_C(  43), INT8_C( -21), INT8_C( -53), INT8_C( -61)) },
    { simde_mm_set_epi8(INT8_C( -66), INT8_C( -33), INT8_C(  33), INT8_C( -43), INT8_C(  92), INT8_C( -19), INT8_C( -42), INT8_C(-112),
                        INT8_C( -49), INT8_C(  23), INT8_C(  30), INT8_C(  67), INT8_C( -77), INT8_C( 104), INT8_C(  55), INT8_C( -77)),
      simde_mm_set_epi8(INT8_C( -66), INT8_C( -33), INT8_C(  33), INT8_C( -43), INT8_C(  92), INT8_C( -19), INT8_C( -42), INT8_C(-112),
                        INT8_C( -49), INT8_C(  23), INT8_C(  30), INT8_C(  67), INT8_C( -77), INT8_C( 104), INT8_C(  55), INT8_C( -77)) },
    { simde_mm_set_epi8(INT8_C(-109), INT8_C( -50), INT8_C(-103), INT8_C( -95), INT8_C(  10), INT8_C(  39), INT8_C( -20), INT8_C( -38),
                        INT8_C( -87), INT8_C( -89), INT8_C(-100), INT8_C( -30), INT8_C(   0), INT8_C(  13), INT8_C(  36), INT8_C(-101)),
      simde_mm_set_epi8(INT8_C(-109), INT8_C( -50), INT8_C(-103), INT8_C( -95), INT8_C(  10), INT8_C(  39), INT8_C( -20), INT8_C( -38),
                        INT8_C( -87), INT8_C( -89), INT8_C(-100), INT8_C( -30), INT8_C(   0), INT8_C(  13), INT8_C(  36), INT8_C(-101)) },
    { simde_mm_set_epi8(INT8_C( 112), INT8_C( 112), INT8_C( -55), INT8_C( -93), INT8_C( -81), INT8_C(  57), INT8_C(  84), INT8_C(  -3),
                        INT8_C( -51), INT8_C(  -7), INT8_C(   0), INT8_C(-102), INT8_C(  82), INT8_C( -68), INT8_C( 109), INT8_C( 126)),
      simde_mm_set_epi8(INT8_C( 112), INT8_C( 112), INT8_C( -55), INT8_C( -93), INT8_C( -81), INT8_C(  57), INT8_C(  84), INT8_C(  -3),
                        INT8_C( -51), INT8_C(  -7), INT8_C(   0), INT8_C(-102), INT8_C(  82), INT8_C( -68), INT8_C( 109), INT8_C( 126)) },
    { simde_mm_set_epi8(INT8_C(  85), INT8_C(  18), INT8_C(  96), INT8_C( -54), INT8_C( -78), INT8_C( 122), INT8_C(-109), INT8_C(  31),
                        INT8_C( 104), INT8_C( -42), INT8_C(  93), INT8_C( -40), INT8_C( -73), INT8_C( 110), INT8_C( -72), INT8_C( -16)),
      simde_mm_set_epi8(INT8_C(  85), INT8_C(  18), INT8_C(  96), INT8_C( -54), INT8_C( -78), INT8_C( 122), INT8_C(-109), INT8_C(  31),
                        INT8_C( 104), INT8_C( -42), INT8_C(  93), INT8_C( -40), INT8_C( -73), INT8_C( 110), INT8_C( -72), INT8_C( -16)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_lddqu_si128(&test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movedup_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
   { simde_mm_set_pd(  850.06,   701.47),
      simde_mm_set_pd(  701.47,   701.47) },
    { simde_mm_set_pd( -959.23,   823.21),
      simde_mm_set_pd(  823.21,   823.21) },
    { simde_mm_set_pd(   37.96,   501.12),
      simde_mm_set_pd(  501.12,   501.12) },
    { simde_mm_set_pd(  288.76,  -831.45),
      simde_mm_set_pd( -831.45,  -831.45) },
    { simde_mm_set_pd(  -93.81,   587.70),
      simde_mm_set_pd(  587.70,   587.70) },
    { simde_mm_set_pd(  524.72,   282.96),
      simde_mm_set_pd(  282.96,   282.96) },
    { simde_mm_set_pd( -824.72,   818.07),
      simde_mm_set_pd(  818.07,   818.07) },
    { simde_mm_set_pd(  136.95,  -565.46),
      simde_mm_set_pd( -565.46,  -565.46) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_movedup_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movehdup_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( -122.14f,   610.86f,  -649.87f,   155.05f),
      simde_mm_set_ps( -122.14f,  -122.14f,  -649.87f,  -649.87f) },
    { simde_mm_set_ps(  559.30f,   847.22f,   946.27f,   786.62f),
      simde_mm_set_ps(  559.30f,   559.30f,   946.27f,   946.27f) },
    { simde_mm_set_ps( -110.32f,    87.26f,   -69.05f,   -39.46f),
      simde_mm_set_ps( -110.32f,  -110.32f,   -69.05f,   -69.05f) },
    { simde_mm_set_ps(  -91.69f,  -770.73f,   838.47f,   700.02f),
      simde_mm_set_ps(  -91.69f,   -91.69f,   838.47f,   838.47f) },
    { simde_mm_set_ps(   54.77f,  -632.77f,    -6.45f,  -696.48f),
      simde_mm_set_ps(   54.77f,    54.77f,    -6.45f,    -6.45f) },
    { simde_mm_set_ps( -313.08f,   792.67f,  -389.34f,  -153.47f),
      simde_mm_set_ps( -313.08f,  -313.08f,  -389.34f,  -389.34f) },
    { simde_mm_set_ps( -873.54f,   935.41f,  -178.48f,   320.54f),
      simde_mm_set_ps( -873.54f,  -873.54f,  -178.48f,  -178.48f) },
    { simde_mm_set_ps(  886.69f,  -558.71f,   768.00f,   565.76f),
      simde_mm_set_ps(  886.69f,   886.69f,   768.00f,   768.00f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_movehdup_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_moveldup_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( -122.14f,   610.86f,  -649.87f,   155.05f),
      simde_mm_set_ps(  610.86f,   610.86f,   155.05f,   155.05f) },
    { simde_mm_set_ps(  559.30f,   847.22f,   946.27f,   786.62f),
      simde_mm_set_ps(  847.22f,   847.22f,   786.62f,   786.62f) },
    { simde_mm_set_ps( -110.32f,    87.26f,   -69.05f,   -39.46f),
      simde_mm_set_ps(   87.26f,    87.26f,   -39.46f,   -39.46f) },
    { simde_mm_set_ps(  -91.69f,  -770.73f,   838.47f,   700.02f),
      simde_mm_set_ps( -770.73f,  -770.73f,   700.02f,   700.02f) },
    { simde_mm_set_ps(   54.77f,  -632.77f,    -6.45f,  -696.48f),
      simde_mm_set_ps( -632.77f,  -632.77f,  -696.48f,  -696.48f) },
    { simde_mm_set_ps( -313.08f,   792.67f,  -389.34f,  -153.47f),
      simde_mm_set_ps(  792.67f,   792.67f,  -153.47f,  -153.47f) },
    { simde_mm_set_ps( -873.54f,   935.41f,  -178.48f,   320.54f),
      simde_mm_set_ps(  935.41f,   935.41f,   320.54f,   320.54f) },
    { simde_mm_set_ps(  886.69f,  -558.71f,   768.00f,   565.76f),
      simde_mm_set_ps( -558.71f,  -558.71f,   565.76f,   565.76f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_moveldup_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

#endif /* defined(SIMDE_SSE3_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_SSE3_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm_addsub_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_addsub_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_hadd_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_hadd_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_hsub_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_hsub_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_lddqu_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_movedup_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_movehdup_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_moveldup_ps),
#endif /* defined(SIMDE_SSE3_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(suite)(void) {
  static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}

#if defined(SIMDE_TESTS_SINGLE_ISAX)
int main(int argc, char* argv[HEDLEY_ARRAY_PARAM(argc + 1)]) {
  static MunitSuite suite = { "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return munit_suite_main(&suite, NULL, argc, argv);
}
#endif /* defined(SIMDE_TESTS_SINGLE_ISAX) */

HEDLEY_DIAGNOSTIC_POP
