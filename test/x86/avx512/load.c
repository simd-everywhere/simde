#define SIMDE_TEST_X86_AVX512_INSN load

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/load.h>

static int
test_simde_mm512_load_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512d) const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -253.55), SIMDE_FLOAT64_C(   122.33), SIMDE_FLOAT64_C(   714.59), SIMDE_FLOAT64_C(   472.69),
        SIMDE_FLOAT64_C(   730.86), SIMDE_FLOAT64_C(  -657.71), SIMDE_FLOAT64_C(  -337.19), SIMDE_FLOAT64_C(   908.99) },
      { SIMDE_FLOAT64_C(  -253.55), SIMDE_FLOAT64_C(   122.33), SIMDE_FLOAT64_C(   714.59), SIMDE_FLOAT64_C(   472.69),
        SIMDE_FLOAT64_C(   730.86), SIMDE_FLOAT64_C(  -657.71), SIMDE_FLOAT64_C(  -337.19), SIMDE_FLOAT64_C(   908.99) } },
    { { SIMDE_FLOAT64_C(   652.40), SIMDE_FLOAT64_C(  -405.37), SIMDE_FLOAT64_C(  -747.52), SIMDE_FLOAT64_C(  -594.32),
        SIMDE_FLOAT64_C(  -157.96), SIMDE_FLOAT64_C(   -25.12), SIMDE_FLOAT64_C(  -954.50), SIMDE_FLOAT64_C(   522.33) },
      { SIMDE_FLOAT64_C(   652.40), SIMDE_FLOAT64_C(  -405.37), SIMDE_FLOAT64_C(  -747.52), SIMDE_FLOAT64_C(  -594.32),
        SIMDE_FLOAT64_C(  -157.96), SIMDE_FLOAT64_C(   -25.12), SIMDE_FLOAT64_C(  -954.50), SIMDE_FLOAT64_C(   522.33) } },
    { { SIMDE_FLOAT64_C(   448.17), SIMDE_FLOAT64_C(  -106.02), SIMDE_FLOAT64_C(  -964.80), SIMDE_FLOAT64_C(  -263.76),
        SIMDE_FLOAT64_C(   856.22), SIMDE_FLOAT64_C(   360.56), SIMDE_FLOAT64_C(  -550.45), SIMDE_FLOAT64_C(  -630.22) },
      { SIMDE_FLOAT64_C(   448.17), SIMDE_FLOAT64_C(  -106.02), SIMDE_FLOAT64_C(  -964.80), SIMDE_FLOAT64_C(  -263.76),
        SIMDE_FLOAT64_C(   856.22), SIMDE_FLOAT64_C(   360.56), SIMDE_FLOAT64_C(  -550.45), SIMDE_FLOAT64_C(  -630.22) } },
    { { SIMDE_FLOAT64_C(   324.58), SIMDE_FLOAT64_C(  -210.48), SIMDE_FLOAT64_C(   200.62), SIMDE_FLOAT64_C(  -125.87),
        SIMDE_FLOAT64_C(  -878.01), SIMDE_FLOAT64_C(   831.18), SIMDE_FLOAT64_C(   -34.08), SIMDE_FLOAT64_C(  -131.56) },
      { SIMDE_FLOAT64_C(   324.58), SIMDE_FLOAT64_C(  -210.48), SIMDE_FLOAT64_C(   200.62), SIMDE_FLOAT64_C(  -125.87),
        SIMDE_FLOAT64_C(  -878.01), SIMDE_FLOAT64_C(   831.18), SIMDE_FLOAT64_C(   -34.08), SIMDE_FLOAT64_C(  -131.56) } },
    { { SIMDE_FLOAT64_C(   -46.49), SIMDE_FLOAT64_C(  -319.49), SIMDE_FLOAT64_C(  -658.87), SIMDE_FLOAT64_C(  -315.63),
        SIMDE_FLOAT64_C(    22.81), SIMDE_FLOAT64_C(     3.93), SIMDE_FLOAT64_C(  -406.65), SIMDE_FLOAT64_C(  -324.80) },
      { SIMDE_FLOAT64_C(   -46.49), SIMDE_FLOAT64_C(  -319.49), SIMDE_FLOAT64_C(  -658.87), SIMDE_FLOAT64_C(  -315.63),
        SIMDE_FLOAT64_C(    22.81), SIMDE_FLOAT64_C(     3.93), SIMDE_FLOAT64_C(  -406.65), SIMDE_FLOAT64_C(  -324.80) } },
    { { SIMDE_FLOAT64_C(   598.56), SIMDE_FLOAT64_C(  -154.17), SIMDE_FLOAT64_C(    80.88), SIMDE_FLOAT64_C(  -559.40),
        SIMDE_FLOAT64_C(   820.71), SIMDE_FLOAT64_C(   126.38), SIMDE_FLOAT64_C(   962.93), SIMDE_FLOAT64_C(   268.89) },
      { SIMDE_FLOAT64_C(   598.56), SIMDE_FLOAT64_C(  -154.17), SIMDE_FLOAT64_C(    80.88), SIMDE_FLOAT64_C(  -559.40),
        SIMDE_FLOAT64_C(   820.71), SIMDE_FLOAT64_C(   126.38), SIMDE_FLOAT64_C(   962.93), SIMDE_FLOAT64_C(   268.89) } },
    { { SIMDE_FLOAT64_C(  -979.63), SIMDE_FLOAT64_C(   998.13), SIMDE_FLOAT64_C(  -994.87), SIMDE_FLOAT64_C(   876.59),
        SIMDE_FLOAT64_C(   358.68), SIMDE_FLOAT64_C(  -545.32), SIMDE_FLOAT64_C(  -753.64), SIMDE_FLOAT64_C(  -316.74) },
      { SIMDE_FLOAT64_C(  -979.63), SIMDE_FLOAT64_C(   998.13), SIMDE_FLOAT64_C(  -994.87), SIMDE_FLOAT64_C(   876.59),
        SIMDE_FLOAT64_C(   358.68), SIMDE_FLOAT64_C(  -545.32), SIMDE_FLOAT64_C(  -753.64), SIMDE_FLOAT64_C(  -316.74) } },
    { { SIMDE_FLOAT64_C(   244.20), SIMDE_FLOAT64_C(   446.98), SIMDE_FLOAT64_C(   557.39), SIMDE_FLOAT64_C(   366.19),
        SIMDE_FLOAT64_C(   278.17), SIMDE_FLOAT64_C(  -476.69), SIMDE_FLOAT64_C(  -765.37), SIMDE_FLOAT64_C(  -768.32) },
      { SIMDE_FLOAT64_C(   244.20), SIMDE_FLOAT64_C(   446.98), SIMDE_FLOAT64_C(   557.39), SIMDE_FLOAT64_C(   366.19),
        SIMDE_FLOAT64_C(   278.17), SIMDE_FLOAT64_C(  -476.69), SIMDE_FLOAT64_C(  -765.37), SIMDE_FLOAT64_C(  -768.32) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d r = simde_mm512_load_pd(test_vec[i].a);
    simde_assert_m512d_close(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = a;

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_load_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512) const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   397.85), SIMDE_FLOAT32_C(   280.50), SIMDE_FLOAT32_C(  -482.10), SIMDE_FLOAT32_C(  -764.38),
        SIMDE_FLOAT32_C(   375.26), SIMDE_FLOAT32_C(  -613.57), SIMDE_FLOAT32_C(    56.03), SIMDE_FLOAT32_C(   417.16),
        SIMDE_FLOAT32_C(  -424.36), SIMDE_FLOAT32_C(    64.48), SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(   101.24),
        SIMDE_FLOAT32_C(  -965.83), SIMDE_FLOAT32_C(   916.49), SIMDE_FLOAT32_C(   799.09), SIMDE_FLOAT32_C(   628.08) },
      { SIMDE_FLOAT32_C(   397.85), SIMDE_FLOAT32_C(   280.50), SIMDE_FLOAT32_C(  -482.10), SIMDE_FLOAT32_C(  -764.38),
        SIMDE_FLOAT32_C(   375.26), SIMDE_FLOAT32_C(  -613.57), SIMDE_FLOAT32_C(    56.03), SIMDE_FLOAT32_C(   417.16),
        SIMDE_FLOAT32_C(  -424.36), SIMDE_FLOAT32_C(    64.48), SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(   101.24),
        SIMDE_FLOAT32_C(  -965.83), SIMDE_FLOAT32_C(   916.49), SIMDE_FLOAT32_C(   799.09), SIMDE_FLOAT32_C(   628.08) } },
    { { SIMDE_FLOAT32_C(  -588.70), SIMDE_FLOAT32_C(   688.61), SIMDE_FLOAT32_C(   202.01), SIMDE_FLOAT32_C(  -610.64),
        SIMDE_FLOAT32_C(   838.07), SIMDE_FLOAT32_C(  -733.40), SIMDE_FLOAT32_C(  -127.00), SIMDE_FLOAT32_C(   993.35),
        SIMDE_FLOAT32_C(  -249.66), SIMDE_FLOAT32_C(   -45.23), SIMDE_FLOAT32_C(   849.71), SIMDE_FLOAT32_C(   -85.52),
        SIMDE_FLOAT32_C(   193.59), SIMDE_FLOAT32_C(  -257.46), SIMDE_FLOAT32_C(   827.23), SIMDE_FLOAT32_C(  -408.56) },
      { SIMDE_FLOAT32_C(  -588.70), SIMDE_FLOAT32_C(   688.61), SIMDE_FLOAT32_C(   202.01), SIMDE_FLOAT32_C(  -610.64),
        SIMDE_FLOAT32_C(   838.07), SIMDE_FLOAT32_C(  -733.40), SIMDE_FLOAT32_C(  -127.00), SIMDE_FLOAT32_C(   993.35),
        SIMDE_FLOAT32_C(  -249.66), SIMDE_FLOAT32_C(   -45.23), SIMDE_FLOAT32_C(   849.71), SIMDE_FLOAT32_C(   -85.52),
        SIMDE_FLOAT32_C(   193.59), SIMDE_FLOAT32_C(  -257.46), SIMDE_FLOAT32_C(   827.23), SIMDE_FLOAT32_C(  -408.56) } },
    { { SIMDE_FLOAT32_C(  -976.96), SIMDE_FLOAT32_C(  -654.87), SIMDE_FLOAT32_C(  -172.94), SIMDE_FLOAT32_C(   398.29),
        SIMDE_FLOAT32_C(  -268.45), SIMDE_FLOAT32_C(   883.09), SIMDE_FLOAT32_C(  -184.55), SIMDE_FLOAT32_C(   307.20),
        SIMDE_FLOAT32_C(   -52.43), SIMDE_FLOAT32_C(   816.29), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   732.78), SIMDE_FLOAT32_C(  -792.48), SIMDE_FLOAT32_C(  -390.18), SIMDE_FLOAT32_C(  -855.92) },
      { SIMDE_FLOAT32_C(  -976.96), SIMDE_FLOAT32_C(  -654.87), SIMDE_FLOAT32_C(  -172.94), SIMDE_FLOAT32_C(   398.29),
        SIMDE_FLOAT32_C(  -268.45), SIMDE_FLOAT32_C(   883.09), SIMDE_FLOAT32_C(  -184.55), SIMDE_FLOAT32_C(   307.20),
        SIMDE_FLOAT32_C(   -52.43), SIMDE_FLOAT32_C(   816.29), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   732.78), SIMDE_FLOAT32_C(  -792.48), SIMDE_FLOAT32_C(  -390.18), SIMDE_FLOAT32_C(  -855.92) } },
    { { SIMDE_FLOAT32_C(   896.13), SIMDE_FLOAT32_C(   811.83), SIMDE_FLOAT32_C(  -466.56), SIMDE_FLOAT32_C(   734.20),
        SIMDE_FLOAT32_C(  -921.57), SIMDE_FLOAT32_C(   406.44), SIMDE_FLOAT32_C(   727.55), SIMDE_FLOAT32_C(  -171.23),
        SIMDE_FLOAT32_C(  -638.79), SIMDE_FLOAT32_C(   577.26), SIMDE_FLOAT32_C(   743.25), SIMDE_FLOAT32_C(   554.80),
        SIMDE_FLOAT32_C(  -680.21), SIMDE_FLOAT32_C(   570.48), SIMDE_FLOAT32_C(  -853.75), SIMDE_FLOAT32_C(  -657.17) },
      { SIMDE_FLOAT32_C(   896.13), SIMDE_FLOAT32_C(   811.83), SIMDE_FLOAT32_C(  -466.56), SIMDE_FLOAT32_C(   734.20),
        SIMDE_FLOAT32_C(  -921.57), SIMDE_FLOAT32_C(   406.44), SIMDE_FLOAT32_C(   727.55), SIMDE_FLOAT32_C(  -171.23),
        SIMDE_FLOAT32_C(  -638.79), SIMDE_FLOAT32_C(   577.26), SIMDE_FLOAT32_C(   743.25), SIMDE_FLOAT32_C(   554.80),
        SIMDE_FLOAT32_C(  -680.21), SIMDE_FLOAT32_C(   570.48), SIMDE_FLOAT32_C(  -853.75), SIMDE_FLOAT32_C(  -657.17) } },
    { { SIMDE_FLOAT32_C(   915.61), SIMDE_FLOAT32_C(   -26.70), SIMDE_FLOAT32_C(   741.12), SIMDE_FLOAT32_C(  -352.84),
        SIMDE_FLOAT32_C(  -143.61), SIMDE_FLOAT32_C(  -443.43), SIMDE_FLOAT32_C(   954.36), SIMDE_FLOAT32_C(   803.96),
        SIMDE_FLOAT32_C(  -627.14), SIMDE_FLOAT32_C(  -637.21), SIMDE_FLOAT32_C(  -214.30), SIMDE_FLOAT32_C(  -894.36),
        SIMDE_FLOAT32_C(  -429.68), SIMDE_FLOAT32_C(   395.52), SIMDE_FLOAT32_C(  -750.28), SIMDE_FLOAT32_C(  -533.55) },
      { SIMDE_FLOAT32_C(   915.61), SIMDE_FLOAT32_C(   -26.70), SIMDE_FLOAT32_C(   741.12), SIMDE_FLOAT32_C(  -352.84),
        SIMDE_FLOAT32_C(  -143.61), SIMDE_FLOAT32_C(  -443.43), SIMDE_FLOAT32_C(   954.36), SIMDE_FLOAT32_C(   803.96),
        SIMDE_FLOAT32_C(  -627.14), SIMDE_FLOAT32_C(  -637.21), SIMDE_FLOAT32_C(  -214.30), SIMDE_FLOAT32_C(  -894.36),
        SIMDE_FLOAT32_C(  -429.68), SIMDE_FLOAT32_C(   395.52), SIMDE_FLOAT32_C(  -750.28), SIMDE_FLOAT32_C(  -533.55) } },
    { { SIMDE_FLOAT32_C(   207.35), SIMDE_FLOAT32_C(  -216.84), SIMDE_FLOAT32_C(  -799.36), SIMDE_FLOAT32_C(   285.78),
        SIMDE_FLOAT32_C(  -810.40), SIMDE_FLOAT32_C(   928.19), SIMDE_FLOAT32_C(  -885.45), SIMDE_FLOAT32_C(  -449.19),
        SIMDE_FLOAT32_C(   505.45), SIMDE_FLOAT32_C(   857.81), SIMDE_FLOAT32_C(  -894.39), SIMDE_FLOAT32_C(   825.24),
        SIMDE_FLOAT32_C(   428.29), SIMDE_FLOAT32_C(  -748.14), SIMDE_FLOAT32_C(  -831.93), SIMDE_FLOAT32_C(   343.89) },
      { SIMDE_FLOAT32_C(   207.35), SIMDE_FLOAT32_C(  -216.84), SIMDE_FLOAT32_C(  -799.36), SIMDE_FLOAT32_C(   285.78),
        SIMDE_FLOAT32_C(  -810.40), SIMDE_FLOAT32_C(   928.19), SIMDE_FLOAT32_C(  -885.45), SIMDE_FLOAT32_C(  -449.19),
        SIMDE_FLOAT32_C(   505.45), SIMDE_FLOAT32_C(   857.81), SIMDE_FLOAT32_C(  -894.39), SIMDE_FLOAT32_C(   825.24),
        SIMDE_FLOAT32_C(   428.29), SIMDE_FLOAT32_C(  -748.14), SIMDE_FLOAT32_C(  -831.93), SIMDE_FLOAT32_C(   343.89) } },
    { { SIMDE_FLOAT32_C(   225.16), SIMDE_FLOAT32_C(   909.19), SIMDE_FLOAT32_C(   991.05), SIMDE_FLOAT32_C(  -918.45),
        SIMDE_FLOAT32_C(  -534.23), SIMDE_FLOAT32_C(   945.41), SIMDE_FLOAT32_C(   885.51), SIMDE_FLOAT32_C(  -161.37),
        SIMDE_FLOAT32_C(  -691.80), SIMDE_FLOAT32_C(  -328.80), SIMDE_FLOAT32_C(   -55.73), SIMDE_FLOAT32_C(  -121.48),
        SIMDE_FLOAT32_C(  -933.28), SIMDE_FLOAT32_C(   193.99), SIMDE_FLOAT32_C(   344.96), SIMDE_FLOAT32_C(   274.08) },
      { SIMDE_FLOAT32_C(   225.16), SIMDE_FLOAT32_C(   909.19), SIMDE_FLOAT32_C(   991.05), SIMDE_FLOAT32_C(  -918.45),
        SIMDE_FLOAT32_C(  -534.23), SIMDE_FLOAT32_C(   945.41), SIMDE_FLOAT32_C(   885.51), SIMDE_FLOAT32_C(  -161.37),
        SIMDE_FLOAT32_C(  -691.80), SIMDE_FLOAT32_C(  -328.80), SIMDE_FLOAT32_C(   -55.73), SIMDE_FLOAT32_C(  -121.48),
        SIMDE_FLOAT32_C(  -933.28), SIMDE_FLOAT32_C(   193.99), SIMDE_FLOAT32_C(   344.96), SIMDE_FLOAT32_C(   274.08) } },
    { { SIMDE_FLOAT32_C(   977.14), SIMDE_FLOAT32_C(   545.61), SIMDE_FLOAT32_C(  -440.14), SIMDE_FLOAT32_C(  -833.26),
        SIMDE_FLOAT32_C(   473.80), SIMDE_FLOAT32_C(  -325.59), SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(   -20.75),
        SIMDE_FLOAT32_C(  -467.78), SIMDE_FLOAT32_C(  -176.84), SIMDE_FLOAT32_C(  -195.51), SIMDE_FLOAT32_C(   960.51),
        SIMDE_FLOAT32_C(    75.02), SIMDE_FLOAT32_C(   -27.44), SIMDE_FLOAT32_C(   304.40), SIMDE_FLOAT32_C(  -699.82) },
      { SIMDE_FLOAT32_C(   977.14), SIMDE_FLOAT32_C(   545.61), SIMDE_FLOAT32_C(  -440.14), SIMDE_FLOAT32_C(  -833.26),
        SIMDE_FLOAT32_C(   473.80), SIMDE_FLOAT32_C(  -325.59), SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(   -20.75),
        SIMDE_FLOAT32_C(  -467.78), SIMDE_FLOAT32_C(  -176.84), SIMDE_FLOAT32_C(  -195.51), SIMDE_FLOAT32_C(   960.51),
        SIMDE_FLOAT32_C(    75.02), SIMDE_FLOAT32_C(   -27.44), SIMDE_FLOAT32_C(   304.40), SIMDE_FLOAT32_C(  -699.82) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 r = simde_mm512_load_ps(test_vec[i].a);
    simde_assert_m512_close(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

#if defined(SIMDE_FLOAT16_IS_SCALAR)
static int
test_simde_mm512_load_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512h) const simde_float16 a[32];
    const simde_float16 r[32];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    62.34), SIMDE_FLOAT16_VALUE(  -929.00), SIMDE_FLOAT16_VALUE(   875.00), SIMDE_FLOAT16_VALUE(   429.25),
        SIMDE_FLOAT16_VALUE(   438.75), SIMDE_FLOAT16_VALUE(   920.00), SIMDE_FLOAT16_VALUE(  -110.75), SIMDE_FLOAT16_VALUE(  -687.50),
        SIMDE_FLOAT16_VALUE(   436.25), SIMDE_FLOAT16_VALUE(  -462.00), SIMDE_FLOAT16_VALUE(   658.00), SIMDE_FLOAT16_VALUE(   687.00),
        SIMDE_FLOAT16_VALUE(   571.50), SIMDE_FLOAT16_VALUE(  -648.50), SIMDE_FLOAT16_VALUE(  -857.00), SIMDE_FLOAT16_VALUE(   484.00),
        SIMDE_FLOAT16_VALUE(   390.25), SIMDE_FLOAT16_VALUE(   290.25), SIMDE_FLOAT16_VALUE(  -618.00), SIMDE_FLOAT16_VALUE(   207.88),
        SIMDE_FLOAT16_VALUE(   211.00), SIMDE_FLOAT16_VALUE(  -151.88), SIMDE_FLOAT16_VALUE(  -582.00), SIMDE_FLOAT16_VALUE(   165.12),
        SIMDE_FLOAT16_VALUE(   986.00), SIMDE_FLOAT16_VALUE(   260.00), SIMDE_FLOAT16_VALUE(  -352.50), SIMDE_FLOAT16_VALUE(   331.00),
        SIMDE_FLOAT16_VALUE(   463.00), SIMDE_FLOAT16_VALUE(   537.50), SIMDE_FLOAT16_VALUE(   182.75), SIMDE_FLOAT16_VALUE(  -474.75) },
      { SIMDE_FLOAT16_VALUE(    62.34), SIMDE_FLOAT16_VALUE(  -929.00), SIMDE_FLOAT16_VALUE(   875.00), SIMDE_FLOAT16_VALUE(   429.25),
        SIMDE_FLOAT16_VALUE(   438.75), SIMDE_FLOAT16_VALUE(   920.00), SIMDE_FLOAT16_VALUE(  -110.75), SIMDE_FLOAT16_VALUE(  -687.50),
        SIMDE_FLOAT16_VALUE(   436.25), SIMDE_FLOAT16_VALUE(  -462.00), SIMDE_FLOAT16_VALUE(   658.00), SIMDE_FLOAT16_VALUE(   687.00),
        SIMDE_FLOAT16_VALUE(   571.50), SIMDE_FLOAT16_VALUE(  -648.50), SIMDE_FLOAT16_VALUE(  -857.00), SIMDE_FLOAT16_VALUE(   484.00),
        SIMDE_FLOAT16_VALUE(   390.25), SIMDE_FLOAT16_VALUE(   290.25), SIMDE_FLOAT16_VALUE(  -618.00), SIMDE_FLOAT16_VALUE(   207.88),
        SIMDE_FLOAT16_VALUE(   211.00), SIMDE_FLOAT16_VALUE(  -151.88), SIMDE_FLOAT16_VALUE(  -582.00), SIMDE_FLOAT16_VALUE(   165.12),
        SIMDE_FLOAT16_VALUE(   986.00), SIMDE_FLOAT16_VALUE(   260.00), SIMDE_FLOAT16_VALUE(  -352.50), SIMDE_FLOAT16_VALUE(   331.00),
        SIMDE_FLOAT16_VALUE(   463.00), SIMDE_FLOAT16_VALUE(   537.50), SIMDE_FLOAT16_VALUE(   182.75), SIMDE_FLOAT16_VALUE(  -474.75) } },
    { { SIMDE_FLOAT16_VALUE(   608.50), SIMDE_FLOAT16_VALUE(    57.62), SIMDE_FLOAT16_VALUE(   954.50), SIMDE_FLOAT16_VALUE(    47.22),
        SIMDE_FLOAT16_VALUE(   -22.30), SIMDE_FLOAT16_VALUE(  -156.25), SIMDE_FLOAT16_VALUE(   360.00), SIMDE_FLOAT16_VALUE(  -586.00),
        SIMDE_FLOAT16_VALUE(   381.75), SIMDE_FLOAT16_VALUE(    17.98), SIMDE_FLOAT16_VALUE(  -899.00), SIMDE_FLOAT16_VALUE(   -46.62),
        SIMDE_FLOAT16_VALUE(   369.25), SIMDE_FLOAT16_VALUE(  -756.50), SIMDE_FLOAT16_VALUE(  -562.50), SIMDE_FLOAT16_VALUE(  -240.50),
        SIMDE_FLOAT16_VALUE(   534.00), SIMDE_FLOAT16_VALUE(  -180.62), SIMDE_FLOAT16_VALUE(   967.50), SIMDE_FLOAT16_VALUE(  -255.12),
        SIMDE_FLOAT16_VALUE(   667.50), SIMDE_FLOAT16_VALUE(  -614.50), SIMDE_FLOAT16_VALUE(   910.00), SIMDE_FLOAT16_VALUE(   653.50),
        SIMDE_FLOAT16_VALUE(   645.50), SIMDE_FLOAT16_VALUE(  -442.50), SIMDE_FLOAT16_VALUE(   -15.32), SIMDE_FLOAT16_VALUE(   108.25),
        SIMDE_FLOAT16_VALUE(  -905.00), SIMDE_FLOAT16_VALUE(  -832.50), SIMDE_FLOAT16_VALUE(   633.50), SIMDE_FLOAT16_VALUE(   703.50) },
      { SIMDE_FLOAT16_VALUE(   608.50), SIMDE_FLOAT16_VALUE(    57.62), SIMDE_FLOAT16_VALUE(   954.50), SIMDE_FLOAT16_VALUE(    47.22),
        SIMDE_FLOAT16_VALUE(   -22.30), SIMDE_FLOAT16_VALUE(  -156.25), SIMDE_FLOAT16_VALUE(   360.00), SIMDE_FLOAT16_VALUE(  -586.00),
        SIMDE_FLOAT16_VALUE(   381.75), SIMDE_FLOAT16_VALUE(    17.98), SIMDE_FLOAT16_VALUE(  -899.00), SIMDE_FLOAT16_VALUE(   -46.62),
        SIMDE_FLOAT16_VALUE(   369.25), SIMDE_FLOAT16_VALUE(  -756.50), SIMDE_FLOAT16_VALUE(  -562.50), SIMDE_FLOAT16_VALUE(  -240.50),
        SIMDE_FLOAT16_VALUE(   534.00), SIMDE_FLOAT16_VALUE(  -180.62), SIMDE_FLOAT16_VALUE(   967.50), SIMDE_FLOAT16_VALUE(  -255.12),
        SIMDE_FLOAT16_VALUE(   667.50), SIMDE_FLOAT16_VALUE(  -614.50), SIMDE_FLOAT16_VALUE(   910.00), SIMDE_FLOAT16_VALUE(   653.50),
        SIMDE_FLOAT16_VALUE(   645.50), SIMDE_FLOAT16_VALUE(  -442.50), SIMDE_FLOAT16_VALUE(   -15.32), SIMDE_FLOAT16_VALUE(   108.25),
        SIMDE_FLOAT16_VALUE(  -905.00), SIMDE_FLOAT16_VALUE(  -832.50), SIMDE_FLOAT16_VALUE(   633.50), SIMDE_FLOAT16_VALUE(   703.50) } },
    { { SIMDE_FLOAT16_VALUE(   225.12), SIMDE_FLOAT16_VALUE(   588.00), SIMDE_FLOAT16_VALUE(  -249.25), SIMDE_FLOAT16_VALUE(  -797.00),
        SIMDE_FLOAT16_VALUE(  -568.00), SIMDE_FLOAT16_VALUE(  -889.00), SIMDE_FLOAT16_VALUE(  -383.25), SIMDE_FLOAT16_VALUE(   813.50),
        SIMDE_FLOAT16_VALUE(   128.75), SIMDE_FLOAT16_VALUE(  -282.50), SIMDE_FLOAT16_VALUE(  -233.12), SIMDE_FLOAT16_VALUE(  -502.00),
        SIMDE_FLOAT16_VALUE(   -38.66), SIMDE_FLOAT16_VALUE(   204.25), SIMDE_FLOAT16_VALUE(   257.50), SIMDE_FLOAT16_VALUE(  -504.75),
        SIMDE_FLOAT16_VALUE(  -976.50), SIMDE_FLOAT16_VALUE(   225.00), SIMDE_FLOAT16_VALUE(   240.25), SIMDE_FLOAT16_VALUE(   691.50),
        SIMDE_FLOAT16_VALUE(   610.50), SIMDE_FLOAT16_VALUE(   150.25), SIMDE_FLOAT16_VALUE(   345.00), SIMDE_FLOAT16_VALUE(   255.75),
        SIMDE_FLOAT16_VALUE(   708.00), SIMDE_FLOAT16_VALUE(  -670.50), SIMDE_FLOAT16_VALUE(  -636.00), SIMDE_FLOAT16_VALUE(   803.00),
        SIMDE_FLOAT16_VALUE(  -503.00), SIMDE_FLOAT16_VALUE(   997.50), SIMDE_FLOAT16_VALUE(   506.75), SIMDE_FLOAT16_VALUE(   722.00) },
      { SIMDE_FLOAT16_VALUE(   225.12), SIMDE_FLOAT16_VALUE(   588.00), SIMDE_FLOAT16_VALUE(  -249.25), SIMDE_FLOAT16_VALUE(  -797.00),
        SIMDE_FLOAT16_VALUE(  -568.00), SIMDE_FLOAT16_VALUE(  -889.00), SIMDE_FLOAT16_VALUE(  -383.25), SIMDE_FLOAT16_VALUE(   813.50),
        SIMDE_FLOAT16_VALUE(   128.75), SIMDE_FLOAT16_VALUE(  -282.50), SIMDE_FLOAT16_VALUE(  -233.12), SIMDE_FLOAT16_VALUE(  -502.00),
        SIMDE_FLOAT16_VALUE(   -38.66), SIMDE_FLOAT16_VALUE(   204.25), SIMDE_FLOAT16_VALUE(   257.50), SIMDE_FLOAT16_VALUE(  -504.75),
        SIMDE_FLOAT16_VALUE(  -976.50), SIMDE_FLOAT16_VALUE(   225.00), SIMDE_FLOAT16_VALUE(   240.25), SIMDE_FLOAT16_VALUE(   691.50),
        SIMDE_FLOAT16_VALUE(   610.50), SIMDE_FLOAT16_VALUE(   150.25), SIMDE_FLOAT16_VALUE(   345.00), SIMDE_FLOAT16_VALUE(   255.75),
        SIMDE_FLOAT16_VALUE(   708.00), SIMDE_FLOAT16_VALUE(  -670.50), SIMDE_FLOAT16_VALUE(  -636.00), SIMDE_FLOAT16_VALUE(   803.00),
        SIMDE_FLOAT16_VALUE(  -503.00), SIMDE_FLOAT16_VALUE(   997.50), SIMDE_FLOAT16_VALUE(   506.75), SIMDE_FLOAT16_VALUE(   722.00) } },
    { { SIMDE_FLOAT16_VALUE(   585.50), SIMDE_FLOAT16_VALUE(  -742.50), SIMDE_FLOAT16_VALUE(   925.00), SIMDE_FLOAT16_VALUE(  -982.50),
        SIMDE_FLOAT16_VALUE(  -631.50), SIMDE_FLOAT16_VALUE(  -458.25), SIMDE_FLOAT16_VALUE(   831.00), SIMDE_FLOAT16_VALUE(   497.00),
        SIMDE_FLOAT16_VALUE(   259.25), SIMDE_FLOAT16_VALUE(  -402.25), SIMDE_FLOAT16_VALUE(   995.00), SIMDE_FLOAT16_VALUE(  -779.50),
        SIMDE_FLOAT16_VALUE(   802.00), SIMDE_FLOAT16_VALUE(   252.75), SIMDE_FLOAT16_VALUE(  -284.00), SIMDE_FLOAT16_VALUE(   826.00),
        SIMDE_FLOAT16_VALUE(  -522.00), SIMDE_FLOAT16_VALUE(   956.00), SIMDE_FLOAT16_VALUE(   517.00), SIMDE_FLOAT16_VALUE(  -912.00),
        SIMDE_FLOAT16_VALUE(   106.50), SIMDE_FLOAT16_VALUE(  -138.12), SIMDE_FLOAT16_VALUE(   343.75), SIMDE_FLOAT16_VALUE(  -185.62),
        SIMDE_FLOAT16_VALUE(   191.50), SIMDE_FLOAT16_VALUE(   708.00), SIMDE_FLOAT16_VALUE(  -382.50), SIMDE_FLOAT16_VALUE(   688.50),
        SIMDE_FLOAT16_VALUE(   705.50), SIMDE_FLOAT16_VALUE(  -876.00), SIMDE_FLOAT16_VALUE(   410.75), SIMDE_FLOAT16_VALUE(   291.00) },
      { SIMDE_FLOAT16_VALUE(   585.50), SIMDE_FLOAT16_VALUE(  -742.50), SIMDE_FLOAT16_VALUE(   925.00), SIMDE_FLOAT16_VALUE(  -982.50),
        SIMDE_FLOAT16_VALUE(  -631.50), SIMDE_FLOAT16_VALUE(  -458.25), SIMDE_FLOAT16_VALUE(   831.00), SIMDE_FLOAT16_VALUE(   497.00),
        SIMDE_FLOAT16_VALUE(   259.25), SIMDE_FLOAT16_VALUE(  -402.25), SIMDE_FLOAT16_VALUE(   995.00), SIMDE_FLOAT16_VALUE(  -779.50),
        SIMDE_FLOAT16_VALUE(   802.00), SIMDE_FLOAT16_VALUE(   252.75), SIMDE_FLOAT16_VALUE(  -284.00), SIMDE_FLOAT16_VALUE(   826.00),
        SIMDE_FLOAT16_VALUE(  -522.00), SIMDE_FLOAT16_VALUE(   956.00), SIMDE_FLOAT16_VALUE(   517.00), SIMDE_FLOAT16_VALUE(  -912.00),
        SIMDE_FLOAT16_VALUE(   106.50), SIMDE_FLOAT16_VALUE(  -138.12), SIMDE_FLOAT16_VALUE(   343.75), SIMDE_FLOAT16_VALUE(  -185.62),
        SIMDE_FLOAT16_VALUE(   191.50), SIMDE_FLOAT16_VALUE(   708.00), SIMDE_FLOAT16_VALUE(  -382.50), SIMDE_FLOAT16_VALUE(   688.50),
        SIMDE_FLOAT16_VALUE(   705.50), SIMDE_FLOAT16_VALUE(  -876.00), SIMDE_FLOAT16_VALUE(   410.75), SIMDE_FLOAT16_VALUE(   291.00) } },
    { { SIMDE_FLOAT16_VALUE(  -618.50), SIMDE_FLOAT16_VALUE(   335.50), SIMDE_FLOAT16_VALUE(   308.25), SIMDE_FLOAT16_VALUE(  -250.12),
        SIMDE_FLOAT16_VALUE(   877.50), SIMDE_FLOAT16_VALUE(   139.25), SIMDE_FLOAT16_VALUE(  -753.00), SIMDE_FLOAT16_VALUE(   136.62),
        SIMDE_FLOAT16_VALUE(   737.00), SIMDE_FLOAT16_VALUE(  -758.00), SIMDE_FLOAT16_VALUE(   357.25), SIMDE_FLOAT16_VALUE(   539.00),
        SIMDE_FLOAT16_VALUE(   494.75), SIMDE_FLOAT16_VALUE(  -927.00), SIMDE_FLOAT16_VALUE(   364.75), SIMDE_FLOAT16_VALUE(   972.50),
        SIMDE_FLOAT16_VALUE(  -970.50), SIMDE_FLOAT16_VALUE(  -118.06), SIMDE_FLOAT16_VALUE(  -939.50), SIMDE_FLOAT16_VALUE(   135.88),
        SIMDE_FLOAT16_VALUE(   744.00), SIMDE_FLOAT16_VALUE(   404.50), SIMDE_FLOAT16_VALUE(   950.50), SIMDE_FLOAT16_VALUE(   -64.69),
        SIMDE_FLOAT16_VALUE(   112.38), SIMDE_FLOAT16_VALUE(  -432.25), SIMDE_FLOAT16_VALUE(  -376.25), SIMDE_FLOAT16_VALUE(  -182.25),
        SIMDE_FLOAT16_VALUE(  -308.00), SIMDE_FLOAT16_VALUE(  -965.50), SIMDE_FLOAT16_VALUE(  -891.50), SIMDE_FLOAT16_VALUE(    73.62) },
      { SIMDE_FLOAT16_VALUE(  -618.50), SIMDE_FLOAT16_VALUE(   335.50), SIMDE_FLOAT16_VALUE(   308.25), SIMDE_FLOAT16_VALUE(  -250.12),
        SIMDE_FLOAT16_VALUE(   877.50), SIMDE_FLOAT16_VALUE(   139.25), SIMDE_FLOAT16_VALUE(  -753.00), SIMDE_FLOAT16_VALUE(   136.62),
        SIMDE_FLOAT16_VALUE(   737.00), SIMDE_FLOAT16_VALUE(  -758.00), SIMDE_FLOAT16_VALUE(   357.25), SIMDE_FLOAT16_VALUE(   539.00),
        SIMDE_FLOAT16_VALUE(   494.75), SIMDE_FLOAT16_VALUE(  -927.00), SIMDE_FLOAT16_VALUE(   364.75), SIMDE_FLOAT16_VALUE(   972.50),
        SIMDE_FLOAT16_VALUE(  -970.50), SIMDE_FLOAT16_VALUE(  -118.06), SIMDE_FLOAT16_VALUE(  -939.50), SIMDE_FLOAT16_VALUE(   135.88),
        SIMDE_FLOAT16_VALUE(   744.00), SIMDE_FLOAT16_VALUE(   404.50), SIMDE_FLOAT16_VALUE(   950.50), SIMDE_FLOAT16_VALUE(   -64.69),
        SIMDE_FLOAT16_VALUE(   112.38), SIMDE_FLOAT16_VALUE(  -432.25), SIMDE_FLOAT16_VALUE(  -376.25), SIMDE_FLOAT16_VALUE(  -182.25),
        SIMDE_FLOAT16_VALUE(  -308.00), SIMDE_FLOAT16_VALUE(  -965.50), SIMDE_FLOAT16_VALUE(  -891.50), SIMDE_FLOAT16_VALUE(    73.62) } },
    { { SIMDE_FLOAT16_VALUE(   370.00), SIMDE_FLOAT16_VALUE(   417.00), SIMDE_FLOAT16_VALUE(   823.50), SIMDE_FLOAT16_VALUE(   247.38),
        SIMDE_FLOAT16_VALUE(  -443.75), SIMDE_FLOAT16_VALUE(  -929.50), SIMDE_FLOAT16_VALUE(  -616.00), SIMDE_FLOAT16_VALUE(  -706.50),
        SIMDE_FLOAT16_VALUE(  -687.50), SIMDE_FLOAT16_VALUE(   741.00), SIMDE_FLOAT16_VALUE(   832.50), SIMDE_FLOAT16_VALUE(   807.50),
        SIMDE_FLOAT16_VALUE(   814.50), SIMDE_FLOAT16_VALUE(   197.25), SIMDE_FLOAT16_VALUE(   780.00), SIMDE_FLOAT16_VALUE(   844.00),
        SIMDE_FLOAT16_VALUE(  -921.00), SIMDE_FLOAT16_VALUE(   840.50), SIMDE_FLOAT16_VALUE(   -20.16), SIMDE_FLOAT16_VALUE(   823.00),
        SIMDE_FLOAT16_VALUE(   245.12), SIMDE_FLOAT16_VALUE(   -69.81), SIMDE_FLOAT16_VALUE(  -241.62), SIMDE_FLOAT16_VALUE(  -642.50),
        SIMDE_FLOAT16_VALUE(   498.00), SIMDE_FLOAT16_VALUE(   382.25), SIMDE_FLOAT16_VALUE(   175.12), SIMDE_FLOAT16_VALUE(  -810.00),
        SIMDE_FLOAT16_VALUE(   416.75), SIMDE_FLOAT16_VALUE(   283.75), SIMDE_FLOAT16_VALUE(   263.75), SIMDE_FLOAT16_VALUE(  -213.25) },
      { SIMDE_FLOAT16_VALUE(   370.00), SIMDE_FLOAT16_VALUE(   417.00), SIMDE_FLOAT16_VALUE(   823.50), SIMDE_FLOAT16_VALUE(   247.38),
        SIMDE_FLOAT16_VALUE(  -443.75), SIMDE_FLOAT16_VALUE(  -929.50), SIMDE_FLOAT16_VALUE(  -616.00), SIMDE_FLOAT16_VALUE(  -706.50),
        SIMDE_FLOAT16_VALUE(  -687.50), SIMDE_FLOAT16_VALUE(   741.00), SIMDE_FLOAT16_VALUE(   832.50), SIMDE_FLOAT16_VALUE(   807.50),
        SIMDE_FLOAT16_VALUE(   814.50), SIMDE_FLOAT16_VALUE(   197.25), SIMDE_FLOAT16_VALUE(   780.00), SIMDE_FLOAT16_VALUE(   844.00),
        SIMDE_FLOAT16_VALUE(  -921.00), SIMDE_FLOAT16_VALUE(   840.50), SIMDE_FLOAT16_VALUE(   -20.16), SIMDE_FLOAT16_VALUE(   823.00),
        SIMDE_FLOAT16_VALUE(   245.12), SIMDE_FLOAT16_VALUE(   -69.81), SIMDE_FLOAT16_VALUE(  -241.62), SIMDE_FLOAT16_VALUE(  -642.50),
        SIMDE_FLOAT16_VALUE(   498.00), SIMDE_FLOAT16_VALUE(   382.25), SIMDE_FLOAT16_VALUE(   175.12), SIMDE_FLOAT16_VALUE(  -810.00),
        SIMDE_FLOAT16_VALUE(   416.75), SIMDE_FLOAT16_VALUE(   283.75), SIMDE_FLOAT16_VALUE(   263.75), SIMDE_FLOAT16_VALUE(  -213.25) } },
    { { SIMDE_FLOAT16_VALUE(  -299.25), SIMDE_FLOAT16_VALUE(    87.19), SIMDE_FLOAT16_VALUE(  -966.00), SIMDE_FLOAT16_VALUE(   257.00),
        SIMDE_FLOAT16_VALUE(   157.62), SIMDE_FLOAT16_VALUE(  -582.00), SIMDE_FLOAT16_VALUE(   550.50), SIMDE_FLOAT16_VALUE(   470.00),
        SIMDE_FLOAT16_VALUE(  -840.50), SIMDE_FLOAT16_VALUE(   382.75), SIMDE_FLOAT16_VALUE(   277.50), SIMDE_FLOAT16_VALUE(   974.00),
        SIMDE_FLOAT16_VALUE(  -420.00), SIMDE_FLOAT16_VALUE(    57.22), SIMDE_FLOAT16_VALUE(   818.00), SIMDE_FLOAT16_VALUE(  -340.75),
        SIMDE_FLOAT16_VALUE(  -102.25), SIMDE_FLOAT16_VALUE(  -202.38), SIMDE_FLOAT16_VALUE(  -517.50), SIMDE_FLOAT16_VALUE(  -857.00),
        SIMDE_FLOAT16_VALUE(   728.00), SIMDE_FLOAT16_VALUE(   240.75), SIMDE_FLOAT16_VALUE(  -499.75), SIMDE_FLOAT16_VALUE(   225.75),
        SIMDE_FLOAT16_VALUE(  -377.00), SIMDE_FLOAT16_VALUE(   675.50), SIMDE_FLOAT16_VALUE(   415.75), SIMDE_FLOAT16_VALUE(  -960.50),
        SIMDE_FLOAT16_VALUE(   -40.75), SIMDE_FLOAT16_VALUE(  -320.50), SIMDE_FLOAT16_VALUE(  -173.50), SIMDE_FLOAT16_VALUE(   660.00) },
      { SIMDE_FLOAT16_VALUE(  -299.25), SIMDE_FLOAT16_VALUE(    87.19), SIMDE_FLOAT16_VALUE(  -966.00), SIMDE_FLOAT16_VALUE(   257.00),
        SIMDE_FLOAT16_VALUE(   157.62), SIMDE_FLOAT16_VALUE(  -582.00), SIMDE_FLOAT16_VALUE(   550.50), SIMDE_FLOAT16_VALUE(   470.00),
        SIMDE_FLOAT16_VALUE(  -840.50), SIMDE_FLOAT16_VALUE(   382.75), SIMDE_FLOAT16_VALUE(   277.50), SIMDE_FLOAT16_VALUE(   974.00),
        SIMDE_FLOAT16_VALUE(  -420.00), SIMDE_FLOAT16_VALUE(    57.22), SIMDE_FLOAT16_VALUE(   818.00), SIMDE_FLOAT16_VALUE(  -340.75),
        SIMDE_FLOAT16_VALUE(  -102.25), SIMDE_FLOAT16_VALUE(  -202.38), SIMDE_FLOAT16_VALUE(  -517.50), SIMDE_FLOAT16_VALUE(  -857.00),
        SIMDE_FLOAT16_VALUE(   728.00), SIMDE_FLOAT16_VALUE(   240.75), SIMDE_FLOAT16_VALUE(  -499.75), SIMDE_FLOAT16_VALUE(   225.75),
        SIMDE_FLOAT16_VALUE(  -377.00), SIMDE_FLOAT16_VALUE(   675.50), SIMDE_FLOAT16_VALUE(   415.75), SIMDE_FLOAT16_VALUE(  -960.50),
        SIMDE_FLOAT16_VALUE(   -40.75), SIMDE_FLOAT16_VALUE(  -320.50), SIMDE_FLOAT16_VALUE(  -173.50), SIMDE_FLOAT16_VALUE(   660.00) } },
    { { SIMDE_FLOAT16_VALUE(   766.50), SIMDE_FLOAT16_VALUE(  -139.38), SIMDE_FLOAT16_VALUE(   -82.88), SIMDE_FLOAT16_VALUE(   -75.81),
        SIMDE_FLOAT16_VALUE(   278.75), SIMDE_FLOAT16_VALUE(  -532.50), SIMDE_FLOAT16_VALUE(  -605.50), SIMDE_FLOAT16_VALUE(   438.25),
        SIMDE_FLOAT16_VALUE(   850.50), SIMDE_FLOAT16_VALUE(   671.50), SIMDE_FLOAT16_VALUE(   412.00), SIMDE_FLOAT16_VALUE(  -569.50),
        SIMDE_FLOAT16_VALUE(  -271.25), SIMDE_FLOAT16_VALUE(   229.75), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(   626.50),
        SIMDE_FLOAT16_VALUE(  -972.50), SIMDE_FLOAT16_VALUE(   572.00), SIMDE_FLOAT16_VALUE(   769.50), SIMDE_FLOAT16_VALUE(   755.00),
        SIMDE_FLOAT16_VALUE(  -187.38), SIMDE_FLOAT16_VALUE(  -730.50), SIMDE_FLOAT16_VALUE(   -19.11), SIMDE_FLOAT16_VALUE(   435.50),
        SIMDE_FLOAT16_VALUE(   945.00), SIMDE_FLOAT16_VALUE(  -603.50), SIMDE_FLOAT16_VALUE(   475.25), SIMDE_FLOAT16_VALUE(   -95.62),
        SIMDE_FLOAT16_VALUE(    76.06), SIMDE_FLOAT16_VALUE(  -698.00), SIMDE_FLOAT16_VALUE(  -435.50), SIMDE_FLOAT16_VALUE(  -157.38) },
      { SIMDE_FLOAT16_VALUE(   766.50), SIMDE_FLOAT16_VALUE(  -139.38), SIMDE_FLOAT16_VALUE(   -82.88), SIMDE_FLOAT16_VALUE(   -75.81),
        SIMDE_FLOAT16_VALUE(   278.75), SIMDE_FLOAT16_VALUE(  -532.50), SIMDE_FLOAT16_VALUE(  -605.50), SIMDE_FLOAT16_VALUE(   438.25),
        SIMDE_FLOAT16_VALUE(   850.50), SIMDE_FLOAT16_VALUE(   671.50), SIMDE_FLOAT16_VALUE(   412.00), SIMDE_FLOAT16_VALUE(  -569.50),
        SIMDE_FLOAT16_VALUE(  -271.25), SIMDE_FLOAT16_VALUE(   229.75), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(   626.50),
        SIMDE_FLOAT16_VALUE(  -972.50), SIMDE_FLOAT16_VALUE(   572.00), SIMDE_FLOAT16_VALUE(   769.50), SIMDE_FLOAT16_VALUE(   755.00),
        SIMDE_FLOAT16_VALUE(  -187.38), SIMDE_FLOAT16_VALUE(  -730.50), SIMDE_FLOAT16_VALUE(   -19.11), SIMDE_FLOAT16_VALUE(   435.50),
        SIMDE_FLOAT16_VALUE(   945.00), SIMDE_FLOAT16_VALUE(  -603.50), SIMDE_FLOAT16_VALUE(   475.25), SIMDE_FLOAT16_VALUE(   -95.62),
        SIMDE_FLOAT16_VALUE(    76.06), SIMDE_FLOAT16_VALUE(  -698.00), SIMDE_FLOAT16_VALUE(  -435.50), SIMDE_FLOAT16_VALUE(  -157.38) } },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512h r = simde_mm512_load_ph(test_vec[i].a);
    simde_test_x86_assert_equal_f16x32(r, simde_mm512_loadu_ph(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512h a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
    simde__m512h r = a;

    simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_mm512_load_si512 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1085279312),  INT32_C(  1689654203), -INT32_C(  1704027444),  INT32_C(  1992004399),  INT32_C(  1598136076), -INT32_C(  1107314712),  INT32_C(  1634510512),  INT32_C(  2144272078),
        -INT32_C(  1405215247), -INT32_C(    65931984), -INT32_C(  1097433201),  INT32_C(   523522579), -INT32_C(   629246223), -INT32_C(   560497363), -INT32_C(   230751453), -INT32_C(   210694911) },
      { -INT32_C(  1085279312),  INT32_C(  1689654203), -INT32_C(  1704027444),  INT32_C(  1992004399),  INT32_C(  1598136076), -INT32_C(  1107314712),  INT32_C(  1634510512),  INT32_C(  2144272078),
        -INT32_C(  1405215247), -INT32_C(    65931984), -INT32_C(  1097433201),  INT32_C(   523522579), -INT32_C(   629246223), -INT32_C(   560497363), -INT32_C(   230751453), -INT32_C(   210694911) } },
    { {  INT32_C(  1537191723),  INT32_C(   878227620),  INT32_C(  1139994160),  INT32_C(   845293376), -INT32_C(   905125475), -INT32_C(  2102877346), -INT32_C(  1468733529),  INT32_C(   547087861),
         INT32_C(   964377492),  INT32_C(   460182507),  INT32_C(    39739330),  INT32_C(   590659974),  INT32_C(    15614114), -INT32_C(  1954375964),  INT32_C(  1932785278),  INT32_C(  1888735195) },
      {  INT32_C(  1537191723),  INT32_C(   878227620),  INT32_C(  1139994160),  INT32_C(   845293376), -INT32_C(   905125475), -INT32_C(  2102877346), -INT32_C(  1468733529),  INT32_C(   547087861),
         INT32_C(   964377492),  INT32_C(   460182507),  INT32_C(    39739330),  INT32_C(   590659974),  INT32_C(    15614114), -INT32_C(  1954375964),  INT32_C(  1932785278),  INT32_C(  1888735195) } },
    { { -INT32_C(   173470198), -INT32_C(  1542383902), -INT32_C(    56201355), -INT32_C(   769664208), -INT32_C(     2945765),  INT32_C(   579491236),  INT32_C(   664125004), -INT32_C(  1751701363),
         INT32_C(   411844662), -INT32_C(   860054186),  INT32_C(  1036542733),  INT32_C(  1494279998), -INT32_C(  1722162187), -INT32_C(  2068061384),  INT32_C(   783044769), -INT32_C(  1362803848) },
      { -INT32_C(   173470198), -INT32_C(  1542383902), -INT32_C(    56201355), -INT32_C(   769664208), -INT32_C(     2945765),  INT32_C(   579491236),  INT32_C(   664125004), -INT32_C(  1751701363),
         INT32_C(   411844662), -INT32_C(   860054186),  INT32_C(  1036542733),  INT32_C(  1494279998), -INT32_C(  1722162187), -INT32_C(  2068061384),  INT32_C(   783044769), -INT32_C(  1362803848) } },
    { { -INT32_C(   624471420), -INT32_C(    56196113),  INT32_C(   607809254),  INT32_C(  1266567766),  INT32_C(  1709496109),  INT32_C(  1558880186),  INT32_C(  1737135855),  INT32_C(  1561678041),
        -INT32_C(  1858544478),  INT32_C(  1183768160), -INT32_C(  1553217459),  INT32_C(  1072621842),  INT32_C(  2057622208),  INT32_C(  1624673905), -INT32_C(    20487900),  INT32_C(  1398529201) },
      { -INT32_C(   624471420), -INT32_C(    56196113),  INT32_C(   607809254),  INT32_C(  1266567766),  INT32_C(  1709496109),  INT32_C(  1558880186),  INT32_C(  1737135855),  INT32_C(  1561678041),
        -INT32_C(  1858544478),  INT32_C(  1183768160), -INT32_C(  1553217459),  INT32_C(  1072621842),  INT32_C(  2057622208),  INT32_C(  1624673905), -INT32_C(    20487900),  INT32_C(  1398529201) } },
    { {  INT32_C(   434410425), -INT32_C(  1084263822),  INT32_C(  1281542714),  INT32_C(  1938510003), -INT32_C(  1813106654), -INT32_C(   470563650), -INT32_C(   689849819),  INT32_C(  1328102550),
         INT32_C(  1114115792), -INT32_C(  1157511040),  INT32_C(  1174889362), -INT32_C(   709258317), -INT32_C(  2123847741), -INT32_C(  1855693972), -INT32_C(  1419229931),  INT32_C(  1392218498) },
      {  INT32_C(   434410425), -INT32_C(  1084263822),  INT32_C(  1281542714),  INT32_C(  1938510003), -INT32_C(  1813106654), -INT32_C(   470563650), -INT32_C(   689849819),  INT32_C(  1328102550),
         INT32_C(  1114115792), -INT32_C(  1157511040),  INT32_C(  1174889362), -INT32_C(   709258317), -INT32_C(  2123847741), -INT32_C(  1855693972), -INT32_C(  1419229931),  INT32_C(  1392218498) } },
    { {  INT32_C(   546595743), -INT32_C(  1092905685), -INT32_C(  1425743112),  INT32_C(   947961205), -INT32_C(   776279963),  INT32_C(  1482825283), -INT32_C(   435959196), -INT32_C(    80150948),
        -INT32_C(  1927558046),  INT32_C(  1498150497),  INT32_C(  1308905433),  INT32_C(  1921483789), -INT32_C(  1354546836), -INT32_C(  1022909089), -INT32_C(   861336976),  INT32_C(  1808261385) },
      {  INT32_C(   546595743), -INT32_C(  1092905685), -INT32_C(  1425743112),  INT32_C(   947961205), -INT32_C(   776279963),  INT32_C(  1482825283), -INT32_C(   435959196), -INT32_C(    80150948),
        -INT32_C(  1927558046),  INT32_C(  1498150497),  INT32_C(  1308905433),  INT32_C(  1921483789), -INT32_C(  1354546836), -INT32_C(  1022909089), -INT32_C(   861336976),  INT32_C(  1808261385) } },
    { {  INT32_C(   251192237), -INT32_C(  1301855015), -INT32_C(  1610519661),  INT32_C(  1527941359),  INT32_C(   671765961),  INT32_C(  1810633211),  INT32_C(   624399644),  INT32_C(   613482103),
        -INT32_C(  1154250527),  INT32_C(  1617795788), -INT32_C(   184521210), -INT32_C(  1085205514),  INT32_C(  1676172136), -INT32_C(  1982933907), -INT32_C(   525466263), -INT32_C(   452641276) },
      {  INT32_C(   251192237), -INT32_C(  1301855015), -INT32_C(  1610519661),  INT32_C(  1527941359),  INT32_C(   671765961),  INT32_C(  1810633211),  INT32_C(   624399644),  INT32_C(   613482103),
        -INT32_C(  1154250527),  INT32_C(  1617795788), -INT32_C(   184521210), -INT32_C(  1085205514),  INT32_C(  1676172136), -INT32_C(  1982933907), -INT32_C(   525466263), -INT32_C(   452641276) } },
    { { -INT32_C(  1818216250), -INT32_C(   655159598),  INT32_C(  1942942588),  INT32_C(  1865555718), -INT32_C(   405661062),  INT32_C(  1483776494), -INT32_C(  1439162714),  INT32_C(   596655452),
         INT32_C(  1219899509), -INT32_C(  1155487426), -INT32_C(  1557205348), -INT32_C(  2012061683),  INT32_C(  1768940667),  INT32_C(   750903429),  INT32_C(  1540815614), -INT32_C(  1384225225) },
      { -INT32_C(  1818216250), -INT32_C(   655159598),  INT32_C(  1942942588),  INT32_C(  1865555718), -INT32_C(   405661062),  INT32_C(  1483776494), -INT32_C(  1439162714),  INT32_C(   596655452),
         INT32_C(  1219899509), -INT32_C(  1155487426), -INT32_C(  1557205348), -INT32_C(  2012061683),  INT32_C(  1768940667),  INT32_C(   750903429),  INT32_C(  1540815614), -INT32_C(  1384225225) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i32x16(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = a;

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(mm512_load_pd)
SIMDE_TEST_FUNC_LIST_ENTRY(mm512_load_ps)
#if defined(SIMDE_FLOAT16_IS_SCALAR)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_load_ph)
#endif
SIMDE_TEST_FUNC_LIST_ENTRY(mm512_load_si512)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
