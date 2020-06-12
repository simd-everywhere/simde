/* Copyright (c) 2019 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX fma
#include <simde/x86/fma.h>
#include <test/x86/test-avx.h>

static int
test_simde_mm_fmadd_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -364.57), SIMDE_FLOAT64_C( -702.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -890.80), SIMDE_FLOAT64_C( -433.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  486.26), SIMDE_FLOAT64_C( -304.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(325245.22), SIMDE_FLOAT64_C(304638.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  278.35), SIMDE_FLOAT64_C( -601.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -850.98), SIMDE_FLOAT64_C(   10.48)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -876.47), SIMDE_FLOAT64_C( -253.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-237746.75), SIMDE_FLOAT64_C(-6559.17)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -495.32), SIMDE_FLOAT64_C(  626.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  243.15), SIMDE_FLOAT64_C( -595.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  652.27), SIMDE_FLOAT64_C(  684.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-119784.79), SIMDE_FLOAT64_C(-372526.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -675.35), SIMDE_FLOAT64_C( -855.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  863.96), SIMDE_FLOAT64_C( -244.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  266.15), SIMDE_FLOAT64_C( -217.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-583209.24), SIMDE_FLOAT64_C(209362.65)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -945.02), SIMDE_FLOAT64_C( -266.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  248.34), SIMDE_FLOAT64_C( -754.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  686.19), SIMDE_FLOAT64_C(  201.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-234000.08), SIMDE_FLOAT64_C(201036.73)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -923.40), SIMDE_FLOAT64_C(  347.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -299.09), SIMDE_FLOAT64_C( -322.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -172.16), SIMDE_FLOAT64_C(  792.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(276007.55), SIMDE_FLOAT64_C(-111359.18)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -997.96), SIMDE_FLOAT64_C( -774.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  336.57), SIMDE_FLOAT64_C( -666.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   18.66), SIMDE_FLOAT64_C(  857.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-335864.74), SIMDE_FLOAT64_C(516798.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  425.15), SIMDE_FLOAT64_C( -554.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -602.50), SIMDE_FLOAT64_C( -329.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -208.43), SIMDE_FLOAT64_C(  819.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-256361.30), SIMDE_FLOAT64_C(183519.19)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmadd_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fmadd_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   463.71), SIMDE_FLOAT64_C(  -551.83),
                         SIMDE_FLOAT64_C(   568.05), SIMDE_FLOAT64_C(  -826.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   440.29), SIMDE_FLOAT64_C(   762.39),
                         SIMDE_FLOAT64_C(  -806.23), SIMDE_FLOAT64_C(  -848.48)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   222.93), SIMDE_FLOAT64_C(  -604.06),
                         SIMDE_FLOAT64_C(  -844.49), SIMDE_FLOAT64_C(   221.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(204389.81), SIMDE_FLOAT64_C(-421313.73),
                         SIMDE_FLOAT64_C(-458823.44), SIMDE_FLOAT64_C(701210.22)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   418.00), SIMDE_FLOAT64_C(  -725.82),
                         SIMDE_FLOAT64_C(   -54.90), SIMDE_FLOAT64_C(  -342.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   280.70), SIMDE_FLOAT64_C(   983.58),
                         SIMDE_FLOAT64_C(  -289.88), SIMDE_FLOAT64_C(   305.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -404.92), SIMDE_FLOAT64_C(  -664.17),
                         SIMDE_FLOAT64_C(   164.15), SIMDE_FLOAT64_C(  -785.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(116927.68), SIMDE_FLOAT64_C(-714566.21),
                         SIMDE_FLOAT64_C( 16078.56), SIMDE_FLOAT64_C(-105265.60)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   267.84), SIMDE_FLOAT64_C(   153.22),
                         SIMDE_FLOAT64_C(   565.53), SIMDE_FLOAT64_C(    45.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   253.29), SIMDE_FLOAT64_C(  -448.85),
                         SIMDE_FLOAT64_C(  -379.10), SIMDE_FLOAT64_C(   896.99)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   305.51), SIMDE_FLOAT64_C(   -18.42),
                         SIMDE_FLOAT64_C(   560.02), SIMDE_FLOAT64_C(  -441.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 68146.70), SIMDE_FLOAT64_C(-68791.22),
                         SIMDE_FLOAT64_C(-213832.40), SIMDE_FLOAT64_C( 40479.14)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   698.02), SIMDE_FLOAT64_C(  -282.65),
                         SIMDE_FLOAT64_C(  -531.77), SIMDE_FLOAT64_C(  -673.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -227.36), SIMDE_FLOAT64_C(   165.86),
                         SIMDE_FLOAT64_C(  -853.86), SIMDE_FLOAT64_C(   210.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -443.02), SIMDE_FLOAT64_C(  -362.32),
                         SIMDE_FLOAT64_C(   833.55), SIMDE_FLOAT64_C(   692.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-159144.85), SIMDE_FLOAT64_C(-47242.65),
                         SIMDE_FLOAT64_C(454890.68), SIMDE_FLOAT64_C(-140910.37)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -601.68), SIMDE_FLOAT64_C(   654.88),
                         SIMDE_FLOAT64_C(   957.42), SIMDE_FLOAT64_C(   563.37)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -958.65), SIMDE_FLOAT64_C(   523.00),
                         SIMDE_FLOAT64_C(  -211.18), SIMDE_FLOAT64_C(  -889.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   180.36), SIMDE_FLOAT64_C(   481.63),
                         SIMDE_FLOAT64_C(  -222.77), SIMDE_FLOAT64_C(   -51.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(576980.89), SIMDE_FLOAT64_C(342983.87),
                         SIMDE_FLOAT64_C(-202410.73), SIMDE_FLOAT64_C(-501044.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   731.42), SIMDE_FLOAT64_C(  -631.15),
                         SIMDE_FLOAT64_C(  -982.89), SIMDE_FLOAT64_C(  -397.65)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    69.37), SIMDE_FLOAT64_C(  -394.43),
                         SIMDE_FLOAT64_C(   -18.09), SIMDE_FLOAT64_C(   272.24)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   920.14), SIMDE_FLOAT64_C(  -196.58),
                         SIMDE_FLOAT64_C(   324.68), SIMDE_FLOAT64_C(  -193.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 51658.75), SIMDE_FLOAT64_C(248747.91),
                         SIMDE_FLOAT64_C( 18105.16), SIMDE_FLOAT64_C(-108449.86)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -561.20), SIMDE_FLOAT64_C(  -459.54),
                         SIMDE_FLOAT64_C(  -681.08), SIMDE_FLOAT64_C(   -49.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   197.69), SIMDE_FLOAT64_C(  -813.71),
                         SIMDE_FLOAT64_C(  -990.48), SIMDE_FLOAT64_C(  -180.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -453.27), SIMDE_FLOAT64_C(  -557.45),
                         SIMDE_FLOAT64_C(  -780.15), SIMDE_FLOAT64_C(   693.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-111396.90), SIMDE_FLOAT64_C(373374.84),
                         SIMDE_FLOAT64_C(673815.97), SIMDE_FLOAT64_C(  9675.73)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   297.04), SIMDE_FLOAT64_C(   950.40),
                         SIMDE_FLOAT64_C(  -454.41), SIMDE_FLOAT64_C(   419.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   303.25), SIMDE_FLOAT64_C(  -917.33),
                         SIMDE_FLOAT64_C(   128.78), SIMDE_FLOAT64_C(   208.96)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   735.53), SIMDE_FLOAT64_C(   976.90),
                         SIMDE_FLOAT64_C(   803.26), SIMDE_FLOAT64_C(   610.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 90812.91), SIMDE_FLOAT64_C(-870853.53),
                         SIMDE_FLOAT64_C(-57715.66), SIMDE_FLOAT64_C( 88210.75)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fmadd_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmadd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    68.47), SIMDE_FLOAT32_C(   -20.99), SIMDE_FLOAT32_C(  -768.39), SIMDE_FLOAT32_C(   464.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   297.92), SIMDE_FLOAT32_C(   902.90), SIMDE_FLOAT32_C(   496.10), SIMDE_FLOAT32_C(  -932.73)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -341.38), SIMDE_FLOAT32_C(  -852.40), SIMDE_FLOAT32_C(   426.68), SIMDE_FLOAT32_C(   755.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 20057.20), SIMDE_FLOAT32_C(-19804.27), SIMDE_FLOAT32_C(-380771.59), SIMDE_FLOAT32_C(-432516.62)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   969.18), SIMDE_FLOAT32_C(   318.32), SIMDE_FLOAT32_C(  -273.65), SIMDE_FLOAT32_C(    39.39)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   995.10), SIMDE_FLOAT32_C(   620.67), SIMDE_FLOAT32_C(   664.82), SIMDE_FLOAT32_C(   711.85)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   473.88), SIMDE_FLOAT32_C(   360.15), SIMDE_FLOAT32_C(  -250.82), SIMDE_FLOAT32_C(   -88.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(964904.88), SIMDE_FLOAT32_C(197931.83), SIMDE_FLOAT32_C(-182178.80), SIMDE_FLOAT32_C( 27951.01)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   164.14), SIMDE_FLOAT32_C(  -848.02), SIMDE_FLOAT32_C(   235.35), SIMDE_FLOAT32_C(  -999.97)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   466.54), SIMDE_FLOAT32_C(    41.59), SIMDE_FLOAT32_C(  -619.09), SIMDE_FLOAT32_C(   332.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -720.05), SIMDE_FLOAT32_C(    91.37), SIMDE_FLOAT32_C(     3.41), SIMDE_FLOAT32_C(  -151.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 75857.83), SIMDE_FLOAT32_C(-35177.78), SIMDE_FLOAT32_C(-145699.44), SIMDE_FLOAT32_C(-332331.78)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -664.98), SIMDE_FLOAT32_C(  -765.11), SIMDE_FLOAT32_C(  -950.95), SIMDE_FLOAT32_C(   967.68)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   463.42), SIMDE_FLOAT32_C(   310.01), SIMDE_FLOAT32_C(  -859.78), SIMDE_FLOAT32_C(  -247.59)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   372.25), SIMDE_FLOAT32_C(  -546.43), SIMDE_FLOAT32_C(   -18.65), SIMDE_FLOAT32_C(  -608.78)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-307792.78), SIMDE_FLOAT32_C(-237738.19), SIMDE_FLOAT32_C(817589.19), SIMDE_FLOAT32_C(-240196.67)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   739.81), SIMDE_FLOAT32_C(  -275.42), SIMDE_FLOAT32_C(  -462.27), SIMDE_FLOAT32_C(  -299.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -308.92), SIMDE_FLOAT32_C(   948.18), SIMDE_FLOAT32_C(  -344.73), SIMDE_FLOAT32_C(  -942.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   780.24), SIMDE_FLOAT32_C(   819.52), SIMDE_FLOAT32_C(  -913.65), SIMDE_FLOAT32_C(   715.95)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-227761.88), SIMDE_FLOAT32_C(-260328.23), SIMDE_FLOAT32_C(158444.69), SIMDE_FLOAT32_C(283038.81)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -766.06), SIMDE_FLOAT32_C(  -563.42), SIMDE_FLOAT32_C(  -122.27), SIMDE_FLOAT32_C(  -338.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   496.12), SIMDE_FLOAT32_C(  -751.97), SIMDE_FLOAT32_C(   655.86), SIMDE_FLOAT32_C(   174.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -985.27), SIMDE_FLOAT32_C(   574.75), SIMDE_FLOAT32_C(   212.10), SIMDE_FLOAT32_C(  -683.32)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-381042.97), SIMDE_FLOAT32_C(424249.66), SIMDE_FLOAT32_C(-79979.90), SIMDE_FLOAT32_C(-59630.52)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -663.22), SIMDE_FLOAT32_C(   549.14), SIMDE_FLOAT32_C(   733.90), SIMDE_FLOAT32_C(   785.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -149.60), SIMDE_FLOAT32_C(  -221.89), SIMDE_FLOAT32_C(  -452.29), SIMDE_FLOAT32_C(   -18.14)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   979.50), SIMDE_FLOAT32_C(  -484.31), SIMDE_FLOAT32_C(  -965.78), SIMDE_FLOAT32_C(  -291.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(100197.21), SIMDE_FLOAT32_C(-122332.99), SIMDE_FLOAT32_C(-332901.44), SIMDE_FLOAT32_C(-14544.97)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    82.89), SIMDE_FLOAT32_C(  -639.53), SIMDE_FLOAT32_C(   680.97), SIMDE_FLOAT32_C(  -745.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   377.68), SIMDE_FLOAT32_C(  -229.15), SIMDE_FLOAT32_C(   986.42), SIMDE_FLOAT32_C(  -430.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   506.24), SIMDE_FLOAT32_C(  -791.48), SIMDE_FLOAT32_C(  -896.55), SIMDE_FLOAT32_C(  -775.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 31812.13), SIMDE_FLOAT32_C(145756.81), SIMDE_FLOAT32_C(670825.81), SIMDE_FLOAT32_C(320549.81)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmadd_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fmadd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    39.90), SIMDE_FLOAT32_C(    46.80),
                         SIMDE_FLOAT32_C(   -90.30), SIMDE_FLOAT32_C(   -57.20),
                         SIMDE_FLOAT32_C(    71.50), SIMDE_FLOAT32_C(    75.00),
                         SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(    14.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -90.60), SIMDE_FLOAT32_C(   -15.30),
                         SIMDE_FLOAT32_C(   -46.70), SIMDE_FLOAT32_C(    73.50),
                         SIMDE_FLOAT32_C(   -27.40), SIMDE_FLOAT32_C(   -79.00),
                         SIMDE_FLOAT32_C(   -14.10), SIMDE_FLOAT32_C(    22.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -19.50), SIMDE_FLOAT32_C(    61.50),
                         SIMDE_FLOAT32_C(   -38.80), SIMDE_FLOAT32_C(   -19.20),
                         SIMDE_FLOAT32_C(    54.40), SIMDE_FLOAT32_C(   -71.00),
                         SIMDE_FLOAT32_C(   -11.30), SIMDE_FLOAT32_C(    -2.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -3634.44), SIMDE_FLOAT32_C(  -654.54),
                         SIMDE_FLOAT32_C(  4178.21), SIMDE_FLOAT32_C( -4223.40),
                         SIMDE_FLOAT32_C( -1904.70), SIMDE_FLOAT32_C( -5996.00),
                         SIMDE_FLOAT32_C(    -7.07), SIMDE_FLOAT32_C(   322.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    56.00), SIMDE_FLOAT32_C(   -61.10),
                         SIMDE_FLOAT32_C(   -84.20), SIMDE_FLOAT32_C(    -8.30),
                         SIMDE_FLOAT32_C(    96.60), SIMDE_FLOAT32_C(    92.70),
                         SIMDE_FLOAT32_C(   -19.40), SIMDE_FLOAT32_C(   -41.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -20.80), SIMDE_FLOAT32_C(   -77.90),
                         SIMDE_FLOAT32_C(    22.80), SIMDE_FLOAT32_C(   -62.40),
                         SIMDE_FLOAT32_C(    47.20), SIMDE_FLOAT32_C(    23.30),
                         SIMDE_FLOAT32_C(   -14.70), SIMDE_FLOAT32_C(     1.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(   -40.20),
                         SIMDE_FLOAT32_C(   -64.40), SIMDE_FLOAT32_C(    46.00),
                         SIMDE_FLOAT32_C(    19.60), SIMDE_FLOAT32_C(    30.00),
                         SIMDE_FLOAT32_C(    23.60), SIMDE_FLOAT32_C(    20.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -1167.30), SIMDE_FLOAT32_C(  4719.49),
                         SIMDE_FLOAT32_C( -1984.16), SIMDE_FLOAT32_C(   563.92),
                         SIMDE_FLOAT32_C(  4579.12), SIMDE_FLOAT32_C(  2189.91),
                         SIMDE_FLOAT32_C(   308.78), SIMDE_FLOAT32_C(   -53.74)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -73.60), SIMDE_FLOAT32_C(   -63.70),
                         SIMDE_FLOAT32_C(    -7.10), SIMDE_FLOAT32_C(   -70.90),
                         SIMDE_FLOAT32_C(    23.30), SIMDE_FLOAT32_C(    22.20),
                         SIMDE_FLOAT32_C(     4.90), SIMDE_FLOAT32_C(   -85.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    75.60), SIMDE_FLOAT32_C(    -6.90),
                         SIMDE_FLOAT32_C(    73.70), SIMDE_FLOAT32_C(   -85.70),
                         SIMDE_FLOAT32_C(   -25.90), SIMDE_FLOAT32_C(   -59.90),
                         SIMDE_FLOAT32_C(   -56.20), SIMDE_FLOAT32_C(   -30.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   -79.70),
                         SIMDE_FLOAT32_C(    71.20), SIMDE_FLOAT32_C(   -74.20),
                         SIMDE_FLOAT32_C(   -48.90), SIMDE_FLOAT32_C(    -7.20),
                         SIMDE_FLOAT32_C(   -59.10), SIMDE_FLOAT32_C(   -84.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -5510.16), SIMDE_FLOAT32_C(   359.83),
                         SIMDE_FLOAT32_C(  -452.07), SIMDE_FLOAT32_C(  6001.93),
                         SIMDE_FLOAT32_C(  -652.37), SIMDE_FLOAT32_C( -1336.98),
                         SIMDE_FLOAT32_C(  -334.48), SIMDE_FLOAT32_C(  2534.01)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    57.50), SIMDE_FLOAT32_C(    93.40),
                         SIMDE_FLOAT32_C(    -2.20), SIMDE_FLOAT32_C(    77.20),
                         SIMDE_FLOAT32_C(    79.40), SIMDE_FLOAT32_C(   -81.10),
                         SIMDE_FLOAT32_C(    25.80), SIMDE_FLOAT32_C(    -5.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -36.80), SIMDE_FLOAT32_C(   -46.10),
                         SIMDE_FLOAT32_C(    57.50), SIMDE_FLOAT32_C(    47.70),
                         SIMDE_FLOAT32_C(    38.00), SIMDE_FLOAT32_C(    48.30),
                         SIMDE_FLOAT32_C(    86.60), SIMDE_FLOAT32_C(    85.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    92.60), SIMDE_FLOAT32_C(    68.60),
                         SIMDE_FLOAT32_C(   -48.10), SIMDE_FLOAT32_C(   -53.80),
                         SIMDE_FLOAT32_C(   -45.80), SIMDE_FLOAT32_C(    33.60),
                         SIMDE_FLOAT32_C(    47.80), SIMDE_FLOAT32_C(    61.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -2023.40), SIMDE_FLOAT32_C( -4237.14),
                         SIMDE_FLOAT32_C(  -174.60), SIMDE_FLOAT32_C(  3628.64),
                         SIMDE_FLOAT32_C(  2971.40), SIMDE_FLOAT32_C( -3883.53),
                         SIMDE_FLOAT32_C(  2282.08), SIMDE_FLOAT32_C(  -400.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    39.30), SIMDE_FLOAT32_C(    47.70),
                         SIMDE_FLOAT32_C(   -46.40), SIMDE_FLOAT32_C(    22.40),
                         SIMDE_FLOAT32_C(   -47.70), SIMDE_FLOAT32_C(   -87.50),
                         SIMDE_FLOAT32_C(    56.70), SIMDE_FLOAT32_C(   -98.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    47.80), SIMDE_FLOAT32_C(    25.10),
                         SIMDE_FLOAT32_C(    86.40), SIMDE_FLOAT32_C(    20.80),
                         SIMDE_FLOAT32_C(   -68.30), SIMDE_FLOAT32_C(    -7.70),
                         SIMDE_FLOAT32_C(    87.10), SIMDE_FLOAT32_C(    24.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    30.50), SIMDE_FLOAT32_C(    80.40),
                         SIMDE_FLOAT32_C(   -81.20), SIMDE_FLOAT32_C(   -60.10),
                         SIMDE_FLOAT32_C(   -62.20), SIMDE_FLOAT32_C(    51.30),
                         SIMDE_FLOAT32_C(   -56.00), SIMDE_FLOAT32_C(   -52.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  1909.04), SIMDE_FLOAT32_C(  1277.67),
                         SIMDE_FLOAT32_C( -4090.16), SIMDE_FLOAT32_C(   405.82),
                         SIMDE_FLOAT32_C(  3195.71), SIMDE_FLOAT32_C(   725.05),
                         SIMDE_FLOAT32_C(  4882.57), SIMDE_FLOAT32_C( -2412.10)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    35.30), SIMDE_FLOAT32_C(   -51.40),
                         SIMDE_FLOAT32_C(   -71.80), SIMDE_FLOAT32_C(    28.30),
                         SIMDE_FLOAT32_C(    41.70), SIMDE_FLOAT32_C(   -29.90),
                         SIMDE_FLOAT32_C(    47.10), SIMDE_FLOAT32_C(   -23.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -72.20), SIMDE_FLOAT32_C(     5.10),
                         SIMDE_FLOAT32_C(    50.30), SIMDE_FLOAT32_C(     8.80),
                         SIMDE_FLOAT32_C(    10.30), SIMDE_FLOAT32_C(    88.00),
                         SIMDE_FLOAT32_C(   -32.10), SIMDE_FLOAT32_C(   -71.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    92.50), SIMDE_FLOAT32_C(   -22.70),
                         SIMDE_FLOAT32_C(   -32.50), SIMDE_FLOAT32_C(   -64.00),
                         SIMDE_FLOAT32_C(    53.40), SIMDE_FLOAT32_C(    57.00),
                         SIMDE_FLOAT32_C(    85.20), SIMDE_FLOAT32_C(    51.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -2456.16), SIMDE_FLOAT32_C(  -284.84),
                         SIMDE_FLOAT32_C( -3644.04), SIMDE_FLOAT32_C(   185.04),
                         SIMDE_FLOAT32_C(   482.91), SIMDE_FLOAT32_C( -2574.20),
                         SIMDE_FLOAT32_C( -1426.71), SIMDE_FLOAT32_C(  1739.20)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    62.00), SIMDE_FLOAT32_C(   -58.50),
                         SIMDE_FLOAT32_C(   -89.10), SIMDE_FLOAT32_C(    51.50),
                         SIMDE_FLOAT32_C(     2.30), SIMDE_FLOAT32_C(   -87.50),
                         SIMDE_FLOAT32_C(   -72.60), SIMDE_FLOAT32_C(    96.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -25.70), SIMDE_FLOAT32_C(    80.90),
                         SIMDE_FLOAT32_C(   -77.80), SIMDE_FLOAT32_C(     4.90),
                         SIMDE_FLOAT32_C(    70.20), SIMDE_FLOAT32_C(    32.70),
                         SIMDE_FLOAT32_C(   -60.70), SIMDE_FLOAT32_C(    68.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -99.00), SIMDE_FLOAT32_C(   -12.20),
                         SIMDE_FLOAT32_C(    41.70), SIMDE_FLOAT32_C(     9.80),
                         SIMDE_FLOAT32_C(   -34.40), SIMDE_FLOAT32_C(   -50.10),
                         SIMDE_FLOAT32_C(    35.40), SIMDE_FLOAT32_C(    62.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -1692.40), SIMDE_FLOAT32_C( -4744.85),
                         SIMDE_FLOAT32_C(  6973.68), SIMDE_FLOAT32_C(   262.15),
                         SIMDE_FLOAT32_C(   127.06), SIMDE_FLOAT32_C( -2911.35),
                         SIMDE_FLOAT32_C(  4442.22), SIMDE_FLOAT32_C(  6611.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -40.00), SIMDE_FLOAT32_C(    62.80),
                         SIMDE_FLOAT32_C(   -40.00), SIMDE_FLOAT32_C(    16.60),
                         SIMDE_FLOAT32_C(    60.10), SIMDE_FLOAT32_C(    22.60),
                         SIMDE_FLOAT32_C(   -12.40), SIMDE_FLOAT32_C(    91.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -98.70), SIMDE_FLOAT32_C(    17.00),
                         SIMDE_FLOAT32_C(   -23.90), SIMDE_FLOAT32_C(    29.60),
                         SIMDE_FLOAT32_C(   -52.60), SIMDE_FLOAT32_C(   -30.60),
                         SIMDE_FLOAT32_C(    43.40), SIMDE_FLOAT32_C(    76.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    61.00), SIMDE_FLOAT32_C(   -10.10),
                         SIMDE_FLOAT32_C(    48.20), SIMDE_FLOAT32_C(    50.20),
                         SIMDE_FLOAT32_C(    12.20), SIMDE_FLOAT32_C(    64.80),
                         SIMDE_FLOAT32_C(   -68.90), SIMDE_FLOAT32_C(   -86.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  4009.00), SIMDE_FLOAT32_C(  1057.50),
                         SIMDE_FLOAT32_C(  1004.20), SIMDE_FLOAT32_C(   541.56),
                         SIMDE_FLOAT32_C( -3149.06), SIMDE_FLOAT32_C(  -626.76),
                         SIMDE_FLOAT32_C(  -607.06), SIMDE_FLOAT32_C(  6898.45)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fmadd_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmadd_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   96.50), SIMDE_FLOAT64_C(  -99.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   16.90), SIMDE_FLOAT64_C(  -76.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   53.90), SIMDE_FLOAT64_C(    6.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   96.50), SIMDE_FLOAT64_C( 7648.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   53.00), SIMDE_FLOAT64_C(   -2.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -68.70), SIMDE_FLOAT64_C(  -11.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -76.30), SIMDE_FLOAT64_C(   62.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   53.00), SIMDE_FLOAT64_C(   87.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   34.00), SIMDE_FLOAT64_C(   30.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -42.50), SIMDE_FLOAT64_C(   32.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -36.20), SIMDE_FLOAT64_C(   36.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   34.00), SIMDE_FLOAT64_C( 1033.45)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -75.50), SIMDE_FLOAT64_C(  -58.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   29.70), SIMDE_FLOAT64_C(  -42.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   95.20), SIMDE_FLOAT64_C(   92.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -75.50), SIMDE_FLOAT64_C( 2545.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C(   12.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -84.80), SIMDE_FLOAT64_C(   50.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.20), SIMDE_FLOAT64_C(  -77.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C(  572.86)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   78.40), SIMDE_FLOAT64_C(  -77.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -76.10), SIMDE_FLOAT64_C(  -11.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    5.80), SIMDE_FLOAT64_C(  -75.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   78.40), SIMDE_FLOAT64_C(  771.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    6.70), SIMDE_FLOAT64_C(   47.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   24.30), SIMDE_FLOAT64_C(   93.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   93.40), SIMDE_FLOAT64_C(  -50.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    6.70), SIMDE_FLOAT64_C( 4405.26)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C(  -73.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.20), SIMDE_FLOAT64_C(   10.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   45.00), SIMDE_FLOAT64_C(  -86.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C( -886.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmadd_sd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmadd_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   29.70), SIMDE_FLOAT32_C(  -13.10), SIMDE_FLOAT32_C(  -92.70), SIMDE_FLOAT32_C(   44.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   25.90), SIMDE_FLOAT32_C(   67.70), SIMDE_FLOAT32_C(  -12.20), SIMDE_FLOAT32_C(   72.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   45.60), SIMDE_FLOAT32_C(   36.90), SIMDE_FLOAT32_C(  -98.40), SIMDE_FLOAT32_C(  -64.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   29.70), SIMDE_FLOAT32_C(  -13.10), SIMDE_FLOAT32_C(  -92.70), SIMDE_FLOAT32_C( 3169.76)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   16.70), SIMDE_FLOAT32_C(   85.50), SIMDE_FLOAT32_C(   89.70), SIMDE_FLOAT32_C(  -23.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   70.80), SIMDE_FLOAT32_C(   99.80), SIMDE_FLOAT32_C(  -87.00), SIMDE_FLOAT32_C(    9.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   42.40), SIMDE_FLOAT32_C(   38.10), SIMDE_FLOAT32_C(  -58.60), SIMDE_FLOAT32_C(  -71.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   16.70), SIMDE_FLOAT32_C(   85.50), SIMDE_FLOAT32_C(   89.70), SIMDE_FLOAT32_C( -285.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -85.70), SIMDE_FLOAT32_C(   66.60), SIMDE_FLOAT32_C(  -84.60), SIMDE_FLOAT32_C(  -90.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   61.30), SIMDE_FLOAT32_C(  -91.00), SIMDE_FLOAT32_C(  -35.60), SIMDE_FLOAT32_C(  -66.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   76.30), SIMDE_FLOAT32_C(  -46.00), SIMDE_FLOAT32_C(   54.10), SIMDE_FLOAT32_C(   17.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -85.70), SIMDE_FLOAT32_C(   66.60), SIMDE_FLOAT32_C(  -84.60), SIMDE_FLOAT32_C( 6017.75)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   14.40), SIMDE_FLOAT32_C(  -25.60), SIMDE_FLOAT32_C(  -65.60), SIMDE_FLOAT32_C(  -71.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   65.40), SIMDE_FLOAT32_C(   95.90), SIMDE_FLOAT32_C(   51.70), SIMDE_FLOAT32_C(  -84.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -47.60), SIMDE_FLOAT32_C(  -50.00), SIMDE_FLOAT32_C(   88.40), SIMDE_FLOAT32_C(  -28.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   14.40), SIMDE_FLOAT32_C(  -25.60), SIMDE_FLOAT32_C(  -65.60), SIMDE_FLOAT32_C( 5970.70)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   29.50), SIMDE_FLOAT32_C(  -26.70), SIMDE_FLOAT32_C(    8.30), SIMDE_FLOAT32_C(  -34.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   76.70), SIMDE_FLOAT32_C(  -34.90), SIMDE_FLOAT32_C(  -78.80), SIMDE_FLOAT32_C(   84.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   45.30), SIMDE_FLOAT32_C(  -18.40), SIMDE_FLOAT32_C(  -36.50), SIMDE_FLOAT32_C(  -89.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   29.50), SIMDE_FLOAT32_C(  -26.70), SIMDE_FLOAT32_C(    8.30), SIMDE_FLOAT32_C(-3021.15)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   64.00), SIMDE_FLOAT32_C(   46.60), SIMDE_FLOAT32_C(  -17.50), SIMDE_FLOAT32_C(   24.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -67.40), SIMDE_FLOAT32_C(  -16.40), SIMDE_FLOAT32_C(   38.30), SIMDE_FLOAT32_C(  -92.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -66.80), SIMDE_FLOAT32_C(   10.60), SIMDE_FLOAT32_C(   -6.70), SIMDE_FLOAT32_C(  -49.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   64.00), SIMDE_FLOAT32_C(   46.60), SIMDE_FLOAT32_C(  -17.50), SIMDE_FLOAT32_C(-2273.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -98.50), SIMDE_FLOAT32_C(   15.30), SIMDE_FLOAT32_C(  -33.40), SIMDE_FLOAT32_C(    4.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   97.00), SIMDE_FLOAT32_C(  -35.60), SIMDE_FLOAT32_C(   63.50), SIMDE_FLOAT32_C(  -94.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -9.90), SIMDE_FLOAT32_C(  -97.20), SIMDE_FLOAT32_C(  -13.80), SIMDE_FLOAT32_C(   11.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -98.50), SIMDE_FLOAT32_C(   15.30), SIMDE_FLOAT32_C(  -33.40), SIMDE_FLOAT32_C( -441.04)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -11.00), SIMDE_FLOAT32_C(  -65.00), SIMDE_FLOAT32_C(  -76.20), SIMDE_FLOAT32_C(   54.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   37.10), SIMDE_FLOAT32_C(  -97.90), SIMDE_FLOAT32_C(  -36.50), SIMDE_FLOAT32_C(   50.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -26.80), SIMDE_FLOAT32_C(  -74.90), SIMDE_FLOAT32_C(  -84.40), SIMDE_FLOAT32_C(   35.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -11.00), SIMDE_FLOAT32_C(  -65.00), SIMDE_FLOAT32_C(  -76.20), SIMDE_FLOAT32_C( 2814.06)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmadd_ss(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmaddsub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -72.20), SIMDE_FLOAT64_C(   74.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   41.60), SIMDE_FLOAT64_C(  -13.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   18.90), SIMDE_FLOAT64_C(   65.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-2984.62), SIMDE_FLOAT64_C(-1069.70)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   14.70), SIMDE_FLOAT64_C(   97.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   47.70), SIMDE_FLOAT64_C(   86.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   75.80), SIMDE_FLOAT64_C(   19.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  776.99), SIMDE_FLOAT64_C( 8443.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -24.00), SIMDE_FLOAT64_C(   39.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(   42.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -66.10), SIMDE_FLOAT64_C(  -55.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -66.10), SIMDE_FLOAT64_C( 1731.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -45.20), SIMDE_FLOAT64_C(   65.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -64.40), SIMDE_FLOAT64_C(   58.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   79.80), SIMDE_FLOAT64_C(   19.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2990.68), SIMDE_FLOAT64_C( 3756.50)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   14.50), SIMDE_FLOAT64_C(  -64.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   92.20), SIMDE_FLOAT64_C(  -68.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -2.50), SIMDE_FLOAT64_C(  -96.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 1334.40), SIMDE_FLOAT64_C( 4561.52)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   61.50), SIMDE_FLOAT64_C(   42.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   77.20), SIMDE_FLOAT64_C(   23.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   32.20), SIMDE_FLOAT64_C(   12.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 4780.00), SIMDE_FLOAT64_C(  975.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -38.20), SIMDE_FLOAT64_C(    8.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.10), SIMDE_FLOAT64_C(   98.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -14.20), SIMDE_FLOAT64_C(   22.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  371.62), SIMDE_FLOAT64_C(  776.06)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    8.40), SIMDE_FLOAT64_C(  -30.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -39.30), SIMDE_FLOAT64_C(   73.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   25.30), SIMDE_FLOAT64_C(    2.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -304.82), SIMDE_FLOAT64_C(-2256.28)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmaddsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fmaddsub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -52.10), SIMDE_FLOAT64_C(  -92.00),
                         SIMDE_FLOAT64_C(  -82.90), SIMDE_FLOAT64_C(  -49.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -49.30), SIMDE_FLOAT64_C(  -97.40),
                         SIMDE_FLOAT64_C(   58.80), SIMDE_FLOAT64_C(   67.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   23.30), SIMDE_FLOAT64_C(   87.10),
                         SIMDE_FLOAT64_C(   71.70), SIMDE_FLOAT64_C(   97.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 2591.83), SIMDE_FLOAT64_C( 8873.70),
                         SIMDE_FLOAT64_C(-4802.82), SIMDE_FLOAT64_C(-3409.50)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -83.80), SIMDE_FLOAT64_C(   50.40),
                         SIMDE_FLOAT64_C(  -94.80), SIMDE_FLOAT64_C(  -86.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    3.10), SIMDE_FLOAT64_C(  -46.80),
                         SIMDE_FLOAT64_C(   -3.10), SIMDE_FLOAT64_C(   83.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -11.70), SIMDE_FLOAT64_C(   76.10),
                         SIMDE_FLOAT64_C(   44.50), SIMDE_FLOAT64_C(   28.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -271.48), SIMDE_FLOAT64_C(-2434.82),
                         SIMDE_FLOAT64_C(  338.38), SIMDE_FLOAT64_C(-7232.40)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -64.40), SIMDE_FLOAT64_C(   40.90),
                         SIMDE_FLOAT64_C(   36.80), SIMDE_FLOAT64_C(   -1.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -57.50), SIMDE_FLOAT64_C(    5.00),
                         SIMDE_FLOAT64_C(  -21.50), SIMDE_FLOAT64_C(   -1.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   21.60), SIMDE_FLOAT64_C(  -36.20),
                         SIMDE_FLOAT64_C(  -67.50), SIMDE_FLOAT64_C(  -19.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 3724.60), SIMDE_FLOAT64_C(  240.70),
                         SIMDE_FLOAT64_C( -858.70), SIMDE_FLOAT64_C(   21.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -37.10), SIMDE_FLOAT64_C(    2.20),
                         SIMDE_FLOAT64_C(  -99.10), SIMDE_FLOAT64_C(   78.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -60.20), SIMDE_FLOAT64_C(   29.30),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(  -40.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   59.60), SIMDE_FLOAT64_C(  -28.40),
                         SIMDE_FLOAT64_C(   58.10), SIMDE_FLOAT64_C(   96.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 2293.02), SIMDE_FLOAT64_C(   92.86),
                         SIMDE_FLOAT64_C( -189.65), SIMDE_FLOAT64_C(-3232.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -88.70), SIMDE_FLOAT64_C(  -20.50),
                         SIMDE_FLOAT64_C(   28.00), SIMDE_FLOAT64_C(  -13.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -49.60), SIMDE_FLOAT64_C(  -13.90),
                         SIMDE_FLOAT64_C(   71.80), SIMDE_FLOAT64_C(  -29.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -95.70), SIMDE_FLOAT64_C(   48.30),
                         SIMDE_FLOAT64_C(   78.20), SIMDE_FLOAT64_C(   -6.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 4303.82), SIMDE_FLOAT64_C(  236.65),
                         SIMDE_FLOAT64_C( 2088.60), SIMDE_FLOAT64_C(  408.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   74.60), SIMDE_FLOAT64_C(   40.20),
                         SIMDE_FLOAT64_C(   -4.40), SIMDE_FLOAT64_C(   51.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   21.60), SIMDE_FLOAT64_C(  -83.50),
                         SIMDE_FLOAT64_C(   -2.00), SIMDE_FLOAT64_C(   -6.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   13.70), SIMDE_FLOAT64_C(   39.10),
                         SIMDE_FLOAT64_C(   92.60), SIMDE_FLOAT64_C(  -41.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1625.06), SIMDE_FLOAT64_C(-3395.80),
                         SIMDE_FLOAT64_C(  101.40), SIMDE_FLOAT64_C( -296.68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -14.60), SIMDE_FLOAT64_C(  -32.40),
                         SIMDE_FLOAT64_C(   94.80), SIMDE_FLOAT64_C(   -5.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   15.40), SIMDE_FLOAT64_C(  -34.50),
                         SIMDE_FLOAT64_C(   91.60), SIMDE_FLOAT64_C(  -58.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.70), SIMDE_FLOAT64_C(  -91.10),
                         SIMDE_FLOAT64_C(  -42.30), SIMDE_FLOAT64_C(   64.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -295.54), SIMDE_FLOAT64_C( 1208.90),
                         SIMDE_FLOAT64_C( 8641.38), SIMDE_FLOAT64_C(  240.02)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   68.20), SIMDE_FLOAT64_C(  -45.40),
                         SIMDE_FLOAT64_C(   33.10), SIMDE_FLOAT64_C(   17.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   52.00), SIMDE_FLOAT64_C(   24.80),
                         SIMDE_FLOAT64_C(    6.10), SIMDE_FLOAT64_C(   68.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   30.10), SIMDE_FLOAT64_C(   11.20),
                         SIMDE_FLOAT64_C(  -78.00), SIMDE_FLOAT64_C(  -47.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 3576.50), SIMDE_FLOAT64_C(-1137.12),
                         SIMDE_FLOAT64_C(  123.91), SIMDE_FLOAT64_C( 1223.98)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fmaddsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmaddsub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -75.30), SIMDE_FLOAT32_C(   37.60), SIMDE_FLOAT32_C(   76.00), SIMDE_FLOAT32_C(   -4.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -15.80), SIMDE_FLOAT32_C(   64.20), SIMDE_FLOAT32_C(   50.90), SIMDE_FLOAT32_C(   26.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   64.80), SIMDE_FLOAT32_C(  -10.00), SIMDE_FLOAT32_C(  -97.40), SIMDE_FLOAT32_C(  -90.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 1254.54), SIMDE_FLOAT32_C( 2423.92), SIMDE_FLOAT32_C( 3771.00), SIMDE_FLOAT32_C(  -19.32)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -48.70), SIMDE_FLOAT32_C(   50.40), SIMDE_FLOAT32_C(  -22.00), SIMDE_FLOAT32_C(   76.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -80.30), SIMDE_FLOAT32_C(  -99.30), SIMDE_FLOAT32_C(  -86.10), SIMDE_FLOAT32_C(   30.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -41.10), SIMDE_FLOAT32_C(   57.20), SIMDE_FLOAT32_C(  -41.90), SIMDE_FLOAT32_C(  -88.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3869.51), SIMDE_FLOAT32_C(-5061.92), SIMDE_FLOAT32_C( 1852.30), SIMDE_FLOAT32_C( 2388.14)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   99.70), SIMDE_FLOAT32_C(    2.10), SIMDE_FLOAT32_C(   41.80), SIMDE_FLOAT32_C(  -15.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   16.20), SIMDE_FLOAT32_C(  -74.30), SIMDE_FLOAT32_C(  -71.40), SIMDE_FLOAT32_C(   51.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   71.10), SIMDE_FLOAT32_C(  -90.60), SIMDE_FLOAT32_C(  -33.50), SIMDE_FLOAT32_C(  -68.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 1686.24), SIMDE_FLOAT32_C(  -65.43), SIMDE_FLOAT32_C(-3018.02), SIMDE_FLOAT32_C( -717.44)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   39.90), SIMDE_FLOAT32_C(   12.10), SIMDE_FLOAT32_C(  -93.10), SIMDE_FLOAT32_C(  -73.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -72.70), SIMDE_FLOAT32_C(  -61.90), SIMDE_FLOAT32_C(    1.90), SIMDE_FLOAT32_C(   89.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -63.40), SIMDE_FLOAT32_C(  -46.10), SIMDE_FLOAT32_C(   50.20), SIMDE_FLOAT32_C(  -74.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-2964.13), SIMDE_FLOAT32_C( -702.89), SIMDE_FLOAT32_C( -126.69), SIMDE_FLOAT32_C(-6494.10)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.90), SIMDE_FLOAT32_C(   16.10), SIMDE_FLOAT32_C(   65.80), SIMDE_FLOAT32_C(   65.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -95.90), SIMDE_FLOAT32_C(    9.30), SIMDE_FLOAT32_C(   33.70), SIMDE_FLOAT32_C(  -30.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    4.30), SIMDE_FLOAT32_C(  -27.90), SIMDE_FLOAT32_C(  -62.30), SIMDE_FLOAT32_C(  -71.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3638.91), SIMDE_FLOAT32_C(  177.63), SIMDE_FLOAT32_C( 2155.16), SIMDE_FLOAT32_C(-1936.76)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   40.20), SIMDE_FLOAT32_C(  -28.10), SIMDE_FLOAT32_C(  -39.20), SIMDE_FLOAT32_C(   15.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -33.70), SIMDE_FLOAT32_C(  -55.90), SIMDE_FLOAT32_C(   -9.80), SIMDE_FLOAT32_C(  -88.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    3.20), SIMDE_FLOAT32_C(  -50.90), SIMDE_FLOAT32_C(   35.30), SIMDE_FLOAT32_C(  -45.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-1351.54), SIMDE_FLOAT32_C( 1621.69), SIMDE_FLOAT32_C(  419.46), SIMDE_FLOAT32_C(-1277.70)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    2.60), SIMDE_FLOAT32_C(   70.50), SIMDE_FLOAT32_C(   56.20), SIMDE_FLOAT32_C(    5.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -66.40), SIMDE_FLOAT32_C(   95.00), SIMDE_FLOAT32_C(   95.50), SIMDE_FLOAT32_C(  -15.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -60.10), SIMDE_FLOAT32_C(  -25.30), SIMDE_FLOAT32_C(  -69.10), SIMDE_FLOAT32_C(  -77.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -232.74), SIMDE_FLOAT32_C( 6722.80), SIMDE_FLOAT32_C( 5298.00), SIMDE_FLOAT32_C(  -16.11)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -91.20), SIMDE_FLOAT32_C(   32.90), SIMDE_FLOAT32_C(   -8.90), SIMDE_FLOAT32_C(  -97.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -78.50), SIMDE_FLOAT32_C(   49.50), SIMDE_FLOAT32_C(   63.70), SIMDE_FLOAT32_C(  -83.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   10.30), SIMDE_FLOAT32_C(   73.30), SIMDE_FLOAT32_C(  -68.20), SIMDE_FLOAT32_C(   60.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 7169.50), SIMDE_FLOAT32_C( 1555.25), SIMDE_FLOAT32_C( -635.13), SIMDE_FLOAT32_C( 8015.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmaddsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fmaddsub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -61.10), SIMDE_FLOAT32_C(  -95.60),
                         SIMDE_FLOAT32_C(   56.00), SIMDE_FLOAT32_C(   46.30),
                         SIMDE_FLOAT32_C(  -62.80), SIMDE_FLOAT32_C(   38.90),
                         SIMDE_FLOAT32_C(  -92.60), SIMDE_FLOAT32_C(   65.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -38.30), SIMDE_FLOAT32_C(   -1.90),
                         SIMDE_FLOAT32_C(  -28.00), SIMDE_FLOAT32_C(  -43.20),
                         SIMDE_FLOAT32_C(  -19.40), SIMDE_FLOAT32_C(   57.60),
                         SIMDE_FLOAT32_C(  -97.20), SIMDE_FLOAT32_C(   81.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   93.20), SIMDE_FLOAT32_C(  -43.00),
                         SIMDE_FLOAT32_C(  -47.40), SIMDE_FLOAT32_C(  -77.00),
                         SIMDE_FLOAT32_C(  -59.90), SIMDE_FLOAT32_C(   17.90),
                         SIMDE_FLOAT32_C(   -9.60), SIMDE_FLOAT32_C(  -61.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 2433.33), SIMDE_FLOAT32_C(  224.64),
                         SIMDE_FLOAT32_C(-1615.40), SIMDE_FLOAT32_C(-1923.16),
                         SIMDE_FLOAT32_C( 1158.42), SIMDE_FLOAT32_C( 2222.74),
                         SIMDE_FLOAT32_C( 8991.12), SIMDE_FLOAT32_C( 5371.78)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -23.40), SIMDE_FLOAT32_C(  -24.60),
                         SIMDE_FLOAT32_C(   35.70), SIMDE_FLOAT32_C(   59.90),
                         SIMDE_FLOAT32_C(  -91.00), SIMDE_FLOAT32_C(  -25.40),
                         SIMDE_FLOAT32_C(  -88.30), SIMDE_FLOAT32_C(  -99.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -30.70), SIMDE_FLOAT32_C(   97.10),
                         SIMDE_FLOAT32_C(   86.90), SIMDE_FLOAT32_C(  -81.10),
                         SIMDE_FLOAT32_C(  -71.30), SIMDE_FLOAT32_C(  -61.20),
                         SIMDE_FLOAT32_C(  -26.10), SIMDE_FLOAT32_C(   31.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -74.30), SIMDE_FLOAT32_C(  -19.40),
                         SIMDE_FLOAT32_C(  -70.80), SIMDE_FLOAT32_C(  -13.00),
                         SIMDE_FLOAT32_C(   82.90), SIMDE_FLOAT32_C(  -75.70),
                         SIMDE_FLOAT32_C(  -31.50), SIMDE_FLOAT32_C(   73.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  644.08), SIMDE_FLOAT32_C(-2369.26),
                         SIMDE_FLOAT32_C( 3031.53), SIMDE_FLOAT32_C(-4844.89),
                         SIMDE_FLOAT32_C( 6571.20), SIMDE_FLOAT32_C( 1630.18),
                         SIMDE_FLOAT32_C( 2273.13), SIMDE_FLOAT32_C(-3227.18)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   70.20), SIMDE_FLOAT32_C(  -20.40),
                         SIMDE_FLOAT32_C(  -51.50), SIMDE_FLOAT32_C(   82.30),
                         SIMDE_FLOAT32_C(   31.30), SIMDE_FLOAT32_C(   17.80),
                         SIMDE_FLOAT32_C(  -39.60), SIMDE_FLOAT32_C(   66.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.50), SIMDE_FLOAT32_C(   52.00),
                         SIMDE_FLOAT32_C(  -54.80), SIMDE_FLOAT32_C(   14.00),
                         SIMDE_FLOAT32_C(   91.80), SIMDE_FLOAT32_C(  -80.70),
                         SIMDE_FLOAT32_C(  -97.90), SIMDE_FLOAT32_C(  -99.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -76.10), SIMDE_FLOAT32_C(   26.90),
                         SIMDE_FLOAT32_C(   24.90), SIMDE_FLOAT32_C(  -50.60),
                         SIMDE_FLOAT32_C(   66.90), SIMDE_FLOAT32_C(   82.40),
                         SIMDE_FLOAT32_C(   98.50), SIMDE_FLOAT32_C(    9.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-5165.60), SIMDE_FLOAT32_C(-1087.70),
                         SIMDE_FLOAT32_C( 2847.10), SIMDE_FLOAT32_C( 1202.80),
                         SIMDE_FLOAT32_C( 2940.24), SIMDE_FLOAT32_C(-1518.86),
                         SIMDE_FLOAT32_C( 3975.34), SIMDE_FLOAT32_C(-6622.80)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -28.40), SIMDE_FLOAT32_C(   22.80),
                         SIMDE_FLOAT32_C(   16.40), SIMDE_FLOAT32_C(   80.20),
                         SIMDE_FLOAT32_C(  -24.10), SIMDE_FLOAT32_C(  -83.00),
                         SIMDE_FLOAT32_C(  -74.10), SIMDE_FLOAT32_C(  -49.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -73.70), SIMDE_FLOAT32_C(   59.00),
                         SIMDE_FLOAT32_C(   36.90), SIMDE_FLOAT32_C(    7.50),
                         SIMDE_FLOAT32_C(  -74.80), SIMDE_FLOAT32_C(  -84.40),
                         SIMDE_FLOAT32_C(   79.60), SIMDE_FLOAT32_C(  -90.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -76.40), SIMDE_FLOAT32_C(   28.10),
                         SIMDE_FLOAT32_C(  -13.60), SIMDE_FLOAT32_C(  -71.50),
                         SIMDE_FLOAT32_C(  -52.20), SIMDE_FLOAT32_C(  -30.20),
                         SIMDE_FLOAT32_C(  -62.60), SIMDE_FLOAT32_C(    2.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 2016.68), SIMDE_FLOAT32_C( 1317.10),
                         SIMDE_FLOAT32_C(  591.56), SIMDE_FLOAT32_C(  673.00),
                         SIMDE_FLOAT32_C( 1750.48), SIMDE_FLOAT32_C( 7035.40),
                         SIMDE_FLOAT32_C(-5960.96), SIMDE_FLOAT32_C( 4496.42)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   74.80), SIMDE_FLOAT32_C(   79.60),
                         SIMDE_FLOAT32_C(  -91.30), SIMDE_FLOAT32_C(   86.60),
                         SIMDE_FLOAT32_C(   41.70), SIMDE_FLOAT32_C(  -74.30),
                         SIMDE_FLOAT32_C(  -75.60), SIMDE_FLOAT32_C(   28.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   96.00), SIMDE_FLOAT32_C(   10.10),
                         SIMDE_FLOAT32_C(  -63.40), SIMDE_FLOAT32_C(   96.90),
                         SIMDE_FLOAT32_C(   66.20), SIMDE_FLOAT32_C(  -75.30),
                         SIMDE_FLOAT32_C(  -11.80), SIMDE_FLOAT32_C(   30.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   31.70), SIMDE_FLOAT32_C(  -47.90),
                         SIMDE_FLOAT32_C(   27.70), SIMDE_FLOAT32_C(   40.70),
                         SIMDE_FLOAT32_C(  -22.80), SIMDE_FLOAT32_C(   35.80),
                         SIMDE_FLOAT32_C(  -30.10), SIMDE_FLOAT32_C(   88.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 7212.50), SIMDE_FLOAT32_C(  851.86),
                         SIMDE_FLOAT32_C( 5816.12), SIMDE_FLOAT32_C( 8350.84),
                         SIMDE_FLOAT32_C( 2737.74), SIMDE_FLOAT32_C( 5558.99),
                         SIMDE_FLOAT32_C(  861.98), SIMDE_FLOAT32_C(  786.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   91.80), SIMDE_FLOAT32_C(  -99.10),
                         SIMDE_FLOAT32_C(  -91.30), SIMDE_FLOAT32_C(   69.40),
                         SIMDE_FLOAT32_C(   38.40), SIMDE_FLOAT32_C(  -90.40),
                         SIMDE_FLOAT32_C(   62.20), SIMDE_FLOAT32_C(  -62.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   82.70), SIMDE_FLOAT32_C(  -63.90),
                         SIMDE_FLOAT32_C(   57.00), SIMDE_FLOAT32_C(  -53.70),
                         SIMDE_FLOAT32_C(  -62.00), SIMDE_FLOAT32_C(   87.90),
                         SIMDE_FLOAT32_C(  -60.70), SIMDE_FLOAT32_C(  -94.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   65.30), SIMDE_FLOAT32_C(   61.10),
                         SIMDE_FLOAT32_C(  -35.30), SIMDE_FLOAT32_C(  -37.60),
                         SIMDE_FLOAT32_C(    3.40), SIMDE_FLOAT32_C(   10.20),
                         SIMDE_FLOAT32_C(   25.70), SIMDE_FLOAT32_C(   31.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 7657.16), SIMDE_FLOAT32_C( 6271.39),
                         SIMDE_FLOAT32_C(-5239.40), SIMDE_FLOAT32_C(-3689.18),
                         SIMDE_FLOAT32_C(-2377.40), SIMDE_FLOAT32_C(-7956.36),
                         SIMDE_FLOAT32_C(-3749.84), SIMDE_FLOAT32_C( 5875.15)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -9.70), SIMDE_FLOAT32_C(   54.70),
                         SIMDE_FLOAT32_C(  -66.40), SIMDE_FLOAT32_C(  -34.70),
                         SIMDE_FLOAT32_C(  -27.90), SIMDE_FLOAT32_C(   92.40),
                         SIMDE_FLOAT32_C(  -11.40), SIMDE_FLOAT32_C(   14.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.90), SIMDE_FLOAT32_C(  -71.50),
                         SIMDE_FLOAT32_C(   67.00), SIMDE_FLOAT32_C(  -56.30),
                         SIMDE_FLOAT32_C(   74.40), SIMDE_FLOAT32_C(    9.80),
                         SIMDE_FLOAT32_C(   -5.30), SIMDE_FLOAT32_C(   63.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -47.10), SIMDE_FLOAT32_C(   81.20),
                         SIMDE_FLOAT32_C(   31.00), SIMDE_FLOAT32_C(   11.50),
                         SIMDE_FLOAT32_C(   67.80), SIMDE_FLOAT32_C(  -14.20),
                         SIMDE_FLOAT32_C(  -62.80), SIMDE_FLOAT32_C(   84.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -38.37), SIMDE_FLOAT32_C(-3992.25),
                         SIMDE_FLOAT32_C(-4417.80), SIMDE_FLOAT32_C( 1942.11),
                         SIMDE_FLOAT32_C(-2007.96), SIMDE_FLOAT32_C(  919.72),
                         SIMDE_FLOAT32_C(   -2.38), SIMDE_FLOAT32_C(  846.78)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -14.10), SIMDE_FLOAT32_C(  -90.60),
                         SIMDE_FLOAT32_C(   37.70), SIMDE_FLOAT32_C(   63.50),
                         SIMDE_FLOAT32_C(  -67.90), SIMDE_FLOAT32_C(  -75.70),
                         SIMDE_FLOAT32_C(   48.30), SIMDE_FLOAT32_C(   69.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   21.20), SIMDE_FLOAT32_C(  -56.80),
                         SIMDE_FLOAT32_C(  -51.20), SIMDE_FLOAT32_C(  -55.60),
                         SIMDE_FLOAT32_C(   65.10), SIMDE_FLOAT32_C(   21.30),
                         SIMDE_FLOAT32_C(  -29.20), SIMDE_FLOAT32_C(  -61.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   55.80), SIMDE_FLOAT32_C(  -16.50),
                         SIMDE_FLOAT32_C(   90.30), SIMDE_FLOAT32_C(   10.50),
                         SIMDE_FLOAT32_C(  -35.10), SIMDE_FLOAT32_C(    8.40),
                         SIMDE_FLOAT32_C(  -35.70), SIMDE_FLOAT32_C(   70.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -243.12), SIMDE_FLOAT32_C( 5162.58),
                         SIMDE_FLOAT32_C(-1839.94), SIMDE_FLOAT32_C(-3541.10),
                         SIMDE_FLOAT32_C(-4455.39), SIMDE_FLOAT32_C(-1620.81),
                         SIMDE_FLOAT32_C(-1446.06), SIMDE_FLOAT32_C(-4370.48)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fmaddsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmsub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -86.00), SIMDE_FLOAT64_C(  -88.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   79.20), SIMDE_FLOAT64_C(  -72.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   69.30), SIMDE_FLOAT64_C(  -94.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-6880.50), SIMDE_FLOAT64_C( 6543.29)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   29.00), SIMDE_FLOAT64_C(  -23.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   88.90), SIMDE_FLOAT64_C(   98.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -27.80), SIMDE_FLOAT64_C(  -64.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2605.90), SIMDE_FLOAT64_C(-2196.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -56.40), SIMDE_FLOAT64_C(   49.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   79.10), SIMDE_FLOAT64_C(  -51.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -66.70), SIMDE_FLOAT64_C(   16.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-4394.54), SIMDE_FLOAT64_C(-2596.43)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -73.50), SIMDE_FLOAT64_C(   25.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   95.60), SIMDE_FLOAT64_C(   38.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   96.40), SIMDE_FLOAT64_C(   40.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-7123.00), SIMDE_FLOAT64_C(  939.01)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   96.70), SIMDE_FLOAT64_C(  -25.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -31.20), SIMDE_FLOAT64_C(  -59.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -18.60), SIMDE_FLOAT64_C(  -15.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-2998.44), SIMDE_FLOAT64_C( 1567.31)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -63.20), SIMDE_FLOAT64_C(  -69.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -27.30), SIMDE_FLOAT64_C(   57.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   17.60), SIMDE_FLOAT64_C(   32.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 1707.76), SIMDE_FLOAT64_C(-4066.03)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -33.50), SIMDE_FLOAT64_C(   64.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -68.40), SIMDE_FLOAT64_C(  -49.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   44.70), SIMDE_FLOAT64_C(   88.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2246.70), SIMDE_FLOAT64_C(-3271.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -79.60), SIMDE_FLOAT64_C(  -61.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.20), SIMDE_FLOAT64_C(  -21.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -94.70), SIMDE_FLOAT64_C(  -26.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2419.02), SIMDE_FLOAT64_C( 1325.96)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fmsub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   34.80), SIMDE_FLOAT64_C(   57.60),
                         SIMDE_FLOAT64_C(   21.20), SIMDE_FLOAT64_C(   58.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -15.50), SIMDE_FLOAT64_C(  -85.90),
                         SIMDE_FLOAT64_C(   76.40), SIMDE_FLOAT64_C(   37.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -67.00), SIMDE_FLOAT64_C(  -15.40),
                         SIMDE_FLOAT64_C(   94.00), SIMDE_FLOAT64_C(  -95.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -472.40), SIMDE_FLOAT64_C(-4932.44),
                         SIMDE_FLOAT64_C( 1525.68), SIMDE_FLOAT64_C( 2290.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   79.40), SIMDE_FLOAT64_C(  -18.40),
                         SIMDE_FLOAT64_C(  -87.30), SIMDE_FLOAT64_C(  -43.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   46.70), SIMDE_FLOAT64_C(  -61.00),
                         SIMDE_FLOAT64_C(   22.50), SIMDE_FLOAT64_C(  -19.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -92.50), SIMDE_FLOAT64_C(   24.60),
                         SIMDE_FLOAT64_C(   48.50), SIMDE_FLOAT64_C(   81.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 3800.48), SIMDE_FLOAT64_C( 1097.80),
                         SIMDE_FLOAT64_C(-2012.75), SIMDE_FLOAT64_C(  762.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -53.30), SIMDE_FLOAT64_C(   37.50),
                         SIMDE_FLOAT64_C(  -12.20), SIMDE_FLOAT64_C(   77.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   44.30), SIMDE_FLOAT64_C(   68.70),
                         SIMDE_FLOAT64_C(   45.00), SIMDE_FLOAT64_C(  -94.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   10.90), SIMDE_FLOAT64_C(  -78.60),
                         SIMDE_FLOAT64_C(   59.40), SIMDE_FLOAT64_C(   54.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-2372.09), SIMDE_FLOAT64_C( 2654.85),
                         SIMDE_FLOAT64_C( -608.40), SIMDE_FLOAT64_C(-7380.98)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -45.20), SIMDE_FLOAT64_C(  -98.30),
                         SIMDE_FLOAT64_C(    6.30), SIMDE_FLOAT64_C(  -64.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   47.00), SIMDE_FLOAT64_C(  -17.30),
                         SIMDE_FLOAT64_C(   90.50), SIMDE_FLOAT64_C(   33.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -47.40), SIMDE_FLOAT64_C(  -48.00),
                         SIMDE_FLOAT64_C(   92.50), SIMDE_FLOAT64_C(  -62.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-2077.00), SIMDE_FLOAT64_C( 1748.59),
                         SIMDE_FLOAT64_C(  477.65), SIMDE_FLOAT64_C(-2069.14)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -66.50), SIMDE_FLOAT64_C(   50.50),
                         SIMDE_FLOAT64_C(  -60.50), SIMDE_FLOAT64_C(   97.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -77.70), SIMDE_FLOAT64_C(  -31.10),
                         SIMDE_FLOAT64_C(   56.50), SIMDE_FLOAT64_C(  -49.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -78.10), SIMDE_FLOAT64_C(  -33.20),
                         SIMDE_FLOAT64_C(   60.50), SIMDE_FLOAT64_C(   91.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 5245.15), SIMDE_FLOAT64_C(-1537.35),
                         SIMDE_FLOAT64_C(-3478.75), SIMDE_FLOAT64_C(-4956.45)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   97.80), SIMDE_FLOAT64_C(    3.10),
                         SIMDE_FLOAT64_C(   -8.70), SIMDE_FLOAT64_C(   56.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   88.60), SIMDE_FLOAT64_C(  -73.80),
                         SIMDE_FLOAT64_C(   92.30), SIMDE_FLOAT64_C(   21.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -81.80), SIMDE_FLOAT64_C(  -53.80),
                         SIMDE_FLOAT64_C(  -76.80), SIMDE_FLOAT64_C(  -90.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 8746.88), SIMDE_FLOAT64_C( -174.98),
                         SIMDE_FLOAT64_C( -726.21), SIMDE_FLOAT64_C( 1313.55)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -20.60), SIMDE_FLOAT64_C(  -46.30),
                         SIMDE_FLOAT64_C(   51.00), SIMDE_FLOAT64_C(   60.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -26.30), SIMDE_FLOAT64_C(  -65.50),
                         SIMDE_FLOAT64_C(  -31.40), SIMDE_FLOAT64_C(   -0.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -79.80), SIMDE_FLOAT64_C(   98.80),
                         SIMDE_FLOAT64_C(   31.60), SIMDE_FLOAT64_C(  -29.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  621.58), SIMDE_FLOAT64_C( 2933.85),
                         SIMDE_FLOAT64_C(-1633.00), SIMDE_FLOAT64_C(   16.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   73.70), SIMDE_FLOAT64_C(  -28.30),
                         SIMDE_FLOAT64_C(   -1.90), SIMDE_FLOAT64_C(  -61.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -19.60), SIMDE_FLOAT64_C(  -92.40),
                         SIMDE_FLOAT64_C(  -22.30), SIMDE_FLOAT64_C(  -53.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -75.90), SIMDE_FLOAT64_C(   72.50),
                         SIMDE_FLOAT64_C(  -50.10), SIMDE_FLOAT64_C(   18.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1368.62), SIMDE_FLOAT64_C( 2542.42),
                         SIMDE_FLOAT64_C(   92.47), SIMDE_FLOAT64_C( 3296.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fmsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmsub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -36.50), SIMDE_FLOAT32_C(   13.70), SIMDE_FLOAT32_C(   -3.10), SIMDE_FLOAT32_C(   21.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   80.60), SIMDE_FLOAT32_C(   11.30), SIMDE_FLOAT32_C(   96.80), SIMDE_FLOAT32_C(  -38.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -8.50), SIMDE_FLOAT32_C(  -28.20), SIMDE_FLOAT32_C(  -26.80), SIMDE_FLOAT32_C(  -95.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-2933.40), SIMDE_FLOAT32_C(  183.01), SIMDE_FLOAT32_C( -273.28), SIMDE_FLOAT32_C( -722.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   59.20), SIMDE_FLOAT32_C(   -6.20), SIMDE_FLOAT32_C(  -52.90), SIMDE_FLOAT32_C(  -75.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   61.80), SIMDE_FLOAT32_C(  -76.10), SIMDE_FLOAT32_C(  -87.70), SIMDE_FLOAT32_C(  -40.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   34.20), SIMDE_FLOAT32_C(   37.10), SIMDE_FLOAT32_C(    7.30), SIMDE_FLOAT32_C(   67.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3624.36), SIMDE_FLOAT32_C(  434.72), SIMDE_FLOAT32_C( 4632.03), SIMDE_FLOAT32_C( 2998.05)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -85.40), SIMDE_FLOAT32_C(   36.60), SIMDE_FLOAT32_C(  -55.80), SIMDE_FLOAT32_C(    5.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.10), SIMDE_FLOAT32_C(   37.80), SIMDE_FLOAT32_C(   -6.30), SIMDE_FLOAT32_C(   90.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   16.90), SIMDE_FLOAT32_C(  -83.90), SIMDE_FLOAT32_C(   82.90), SIMDE_FLOAT32_C(   23.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3151.44), SIMDE_FLOAT32_C( 1467.38), SIMDE_FLOAT32_C(  268.64), SIMDE_FLOAT32_C(  510.36)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   59.30), SIMDE_FLOAT32_C(   97.10), SIMDE_FLOAT32_C(   -5.30), SIMDE_FLOAT32_C(  -37.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -7.50), SIMDE_FLOAT32_C(   42.80), SIMDE_FLOAT32_C(  -32.50), SIMDE_FLOAT32_C(  -34.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   25.50), SIMDE_FLOAT32_C(   87.80), SIMDE_FLOAT32_C(   95.90), SIMDE_FLOAT32_C(  -68.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -470.25), SIMDE_FLOAT32_C( 4068.08), SIMDE_FLOAT32_C(   76.35), SIMDE_FLOAT32_C( 1362.34)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -87.90), SIMDE_FLOAT32_C(  -35.50), SIMDE_FLOAT32_C(  -15.00), SIMDE_FLOAT32_C(   72.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   78.40), SIMDE_FLOAT32_C(   83.00), SIMDE_FLOAT32_C(   34.70), SIMDE_FLOAT32_C(   -8.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   99.60), SIMDE_FLOAT32_C(   96.00), SIMDE_FLOAT32_C(   45.40), SIMDE_FLOAT32_C(  -79.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-6990.96), SIMDE_FLOAT32_C(-3042.50), SIMDE_FLOAT32_C( -565.90), SIMDE_FLOAT32_C( -538.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   26.30), SIMDE_FLOAT32_C(   69.80), SIMDE_FLOAT32_C(  -48.50), SIMDE_FLOAT32_C(  -58.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   85.00), SIMDE_FLOAT32_C(  -97.40), SIMDE_FLOAT32_C(   16.90), SIMDE_FLOAT32_C(  -37.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -22.30), SIMDE_FLOAT32_C(   21.90), SIMDE_FLOAT32_C(  -79.20), SIMDE_FLOAT32_C(  -99.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 2257.80), SIMDE_FLOAT32_C(-6820.42), SIMDE_FLOAT32_C( -740.45), SIMDE_FLOAT32_C( 2281.25)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   24.00), SIMDE_FLOAT32_C(   51.40), SIMDE_FLOAT32_C(  -24.70), SIMDE_FLOAT32_C(  -32.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   34.10), SIMDE_FLOAT32_C(   90.10), SIMDE_FLOAT32_C(   39.10), SIMDE_FLOAT32_C(  -33.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   63.90), SIMDE_FLOAT32_C(  -54.20), SIMDE_FLOAT32_C(  -27.60), SIMDE_FLOAT32_C(   31.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  754.50), SIMDE_FLOAT32_C( 4685.34), SIMDE_FLOAT32_C( -938.17), SIMDE_FLOAT32_C( 1044.05)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   45.70), SIMDE_FLOAT32_C(  -95.60), SIMDE_FLOAT32_C(   14.60), SIMDE_FLOAT32_C(   -3.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -90.50), SIMDE_FLOAT32_C(  -20.20), SIMDE_FLOAT32_C(   91.40), SIMDE_FLOAT32_C(   25.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -26.90), SIMDE_FLOAT32_C(   29.30), SIMDE_FLOAT32_C(   77.50), SIMDE_FLOAT32_C(  -80.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-4108.95), SIMDE_FLOAT32_C( 1901.82), SIMDE_FLOAT32_C( 1256.94), SIMDE_FLOAT32_C(   -5.34)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fmsub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   71.60), SIMDE_FLOAT32_C(   70.70),
                         SIMDE_FLOAT32_C(   40.60), SIMDE_FLOAT32_C(   -9.30),
                         SIMDE_FLOAT32_C(  -79.10), SIMDE_FLOAT32_C(   52.30),
                         SIMDE_FLOAT32_C(  -67.90), SIMDE_FLOAT32_C(   25.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -51.50), SIMDE_FLOAT32_C(   43.80),
                         SIMDE_FLOAT32_C(   41.70), SIMDE_FLOAT32_C(  -77.20),
                         SIMDE_FLOAT32_C(   -5.00), SIMDE_FLOAT32_C(   96.70),
                         SIMDE_FLOAT32_C(  -13.50), SIMDE_FLOAT32_C(   -2.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -28.70), SIMDE_FLOAT32_C(  -28.30),
                         SIMDE_FLOAT32_C(    1.80), SIMDE_FLOAT32_C(  -81.10),
                         SIMDE_FLOAT32_C(  -82.10), SIMDE_FLOAT32_C(  -69.80),
                         SIMDE_FLOAT32_C(   42.10), SIMDE_FLOAT32_C(   74.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-3658.70), SIMDE_FLOAT32_C( 3124.96),
                         SIMDE_FLOAT32_C( 1691.22), SIMDE_FLOAT32_C(  799.06),
                         SIMDE_FLOAT32_C(  477.60), SIMDE_FLOAT32_C( 5127.21),
                         SIMDE_FLOAT32_C(  874.55), SIMDE_FLOAT32_C( -144.09)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -49.00), SIMDE_FLOAT32_C(  -78.70),
                         SIMDE_FLOAT32_C(  -72.10), SIMDE_FLOAT32_C(   26.10),
                         SIMDE_FLOAT32_C(  -91.90), SIMDE_FLOAT32_C(    1.40),
                         SIMDE_FLOAT32_C(   89.80), SIMDE_FLOAT32_C(   94.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -13.70), SIMDE_FLOAT32_C(    0.70),
                         SIMDE_FLOAT32_C(   57.80), SIMDE_FLOAT32_C(   33.00),
                         SIMDE_FLOAT32_C(  -83.50), SIMDE_FLOAT32_C(   -8.10),
                         SIMDE_FLOAT32_C(   91.30), SIMDE_FLOAT32_C(   65.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -67.90), SIMDE_FLOAT32_C(  -56.40),
                         SIMDE_FLOAT32_C(    5.90), SIMDE_FLOAT32_C(    2.40),
                         SIMDE_FLOAT32_C(   91.80), SIMDE_FLOAT32_C(   50.80),
                         SIMDE_FLOAT32_C(   64.70), SIMDE_FLOAT32_C(  -56.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  739.20), SIMDE_FLOAT32_C(    1.31),
                         SIMDE_FLOAT32_C(-4173.28), SIMDE_FLOAT32_C(  858.90),
                         SIMDE_FLOAT32_C( 7581.85), SIMDE_FLOAT32_C(  -62.14),
                         SIMDE_FLOAT32_C( 8134.04), SIMDE_FLOAT32_C( 6197.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   40.00), SIMDE_FLOAT32_C(   -5.30),
                         SIMDE_FLOAT32_C(   85.00), SIMDE_FLOAT32_C(   83.70),
                         SIMDE_FLOAT32_C(   96.80), SIMDE_FLOAT32_C(  -59.70),
                         SIMDE_FLOAT32_C(  -72.50), SIMDE_FLOAT32_C(   -8.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   77.50), SIMDE_FLOAT32_C(   50.00),
                         SIMDE_FLOAT32_C(   72.40), SIMDE_FLOAT32_C(   98.40),
                         SIMDE_FLOAT32_C(   69.10), SIMDE_FLOAT32_C(   35.80),
                         SIMDE_FLOAT32_C(  -92.90), SIMDE_FLOAT32_C(   63.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   73.80), SIMDE_FLOAT32_C(  -94.30),
                         SIMDE_FLOAT32_C(  -79.50), SIMDE_FLOAT32_C(   64.60),
                         SIMDE_FLOAT32_C(   63.40), SIMDE_FLOAT32_C(  -65.00),
                         SIMDE_FLOAT32_C(   75.20), SIMDE_FLOAT32_C(   48.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 3026.20), SIMDE_FLOAT32_C( -170.70),
                         SIMDE_FLOAT32_C( 6233.50), SIMDE_FLOAT32_C( 8171.48),
                         SIMDE_FLOAT32_C( 6625.48), SIMDE_FLOAT32_C(-2072.26),
                         SIMDE_FLOAT32_C( 6660.05), SIMDE_FLOAT32_C( -564.67)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -82.20), SIMDE_FLOAT32_C(   93.30),
                         SIMDE_FLOAT32_C(    9.70), SIMDE_FLOAT32_C(   -2.70),
                         SIMDE_FLOAT32_C(   86.00), SIMDE_FLOAT32_C(  -20.80),
                         SIMDE_FLOAT32_C(   67.70), SIMDE_FLOAT32_C(  -47.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -83.70), SIMDE_FLOAT32_C(   12.00),
                         SIMDE_FLOAT32_C(   23.10), SIMDE_FLOAT32_C(  -42.00),
                         SIMDE_FLOAT32_C(   46.30), SIMDE_FLOAT32_C(   48.20),
                         SIMDE_FLOAT32_C(   86.90), SIMDE_FLOAT32_C(  -91.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -48.60), SIMDE_FLOAT32_C(   92.30),
                         SIMDE_FLOAT32_C(  -12.70), SIMDE_FLOAT32_C(  -48.20),
                         SIMDE_FLOAT32_C(   60.90), SIMDE_FLOAT32_C(   43.20),
                         SIMDE_FLOAT32_C(  -71.30), SIMDE_FLOAT32_C(  -56.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 6928.74), SIMDE_FLOAT32_C( 1027.30),
                         SIMDE_FLOAT32_C(  236.77), SIMDE_FLOAT32_C(  161.60),
                         SIMDE_FLOAT32_C( 3920.90), SIMDE_FLOAT32_C(-1045.76),
                         SIMDE_FLOAT32_C( 5954.43), SIMDE_FLOAT32_C( 4375.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   32.60), SIMDE_FLOAT32_C(   90.30),
                         SIMDE_FLOAT32_C(  -31.90), SIMDE_FLOAT32_C(   33.60),
                         SIMDE_FLOAT32_C(   47.40), SIMDE_FLOAT32_C(   49.30),
                         SIMDE_FLOAT32_C(  -73.00), SIMDE_FLOAT32_C(   55.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.60), SIMDE_FLOAT32_C(   34.70),
                         SIMDE_FLOAT32_C(   -8.30), SIMDE_FLOAT32_C(  -47.40),
                         SIMDE_FLOAT32_C(  -91.00), SIMDE_FLOAT32_C(  -99.10),
                         SIMDE_FLOAT32_C(  -84.60), SIMDE_FLOAT32_C(  -13.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -84.20), SIMDE_FLOAT32_C(   35.00),
                         SIMDE_FLOAT32_C(  -58.10), SIMDE_FLOAT32_C(   81.70),
                         SIMDE_FLOAT32_C(    1.20), SIMDE_FLOAT32_C(  -33.20),
                         SIMDE_FLOAT32_C(   36.00), SIMDE_FLOAT32_C(  -80.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-2282.56), SIMDE_FLOAT32_C( 3098.41),
                         SIMDE_FLOAT32_C(  322.87), SIMDE_FLOAT32_C(-1674.34),
                         SIMDE_FLOAT32_C(-4314.60), SIMDE_FLOAT32_C(-4852.43),
                         SIMDE_FLOAT32_C( 6139.80), SIMDE_FLOAT32_C( -672.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -58.90), SIMDE_FLOAT32_C(   53.10),
                         SIMDE_FLOAT32_C(  -76.60), SIMDE_FLOAT32_C(   83.00),
                         SIMDE_FLOAT32_C(   91.20), SIMDE_FLOAT32_C(  -33.50),
                         SIMDE_FLOAT32_C(  -65.20), SIMDE_FLOAT32_C(  -55.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -47.40), SIMDE_FLOAT32_C(  -20.10),
                         SIMDE_FLOAT32_C(  -89.40), SIMDE_FLOAT32_C(   87.90),
                         SIMDE_FLOAT32_C(  -65.50), SIMDE_FLOAT32_C(  -20.70),
                         SIMDE_FLOAT32_C(   88.30), SIMDE_FLOAT32_C(   20.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   50.40), SIMDE_FLOAT32_C(   75.40),
                         SIMDE_FLOAT32_C(   79.80), SIMDE_FLOAT32_C(    5.10),
                         SIMDE_FLOAT32_C(   -6.50), SIMDE_FLOAT32_C(  -47.90),
                         SIMDE_FLOAT32_C(   48.50), SIMDE_FLOAT32_C(  -69.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 2741.46), SIMDE_FLOAT32_C(-1142.71),
                         SIMDE_FLOAT32_C( 6768.24), SIMDE_FLOAT32_C( 7290.60),
                         SIMDE_FLOAT32_C(-5967.10), SIMDE_FLOAT32_C(  741.35),
                         SIMDE_FLOAT32_C(-5805.66), SIMDE_FLOAT32_C(-1052.10)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    8.30), SIMDE_FLOAT32_C(   22.80),
                         SIMDE_FLOAT32_C(  -55.20), SIMDE_FLOAT32_C(  -62.40),
                         SIMDE_FLOAT32_C(  -29.10), SIMDE_FLOAT32_C(   56.20),
                         SIMDE_FLOAT32_C(   96.20), SIMDE_FLOAT32_C(   45.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    9.40), SIMDE_FLOAT32_C(  -58.60),
                         SIMDE_FLOAT32_C(  -71.50), SIMDE_FLOAT32_C(   52.70),
                         SIMDE_FLOAT32_C(  -96.40), SIMDE_FLOAT32_C(   75.70),
                         SIMDE_FLOAT32_C(   -3.70), SIMDE_FLOAT32_C(   35.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -87.20), SIMDE_FLOAT32_C(  -73.80),
                         SIMDE_FLOAT32_C(  -51.80), SIMDE_FLOAT32_C(   49.30),
                         SIMDE_FLOAT32_C(    9.90), SIMDE_FLOAT32_C(   32.40),
                         SIMDE_FLOAT32_C(  -44.20), SIMDE_FLOAT32_C(   88.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  165.22), SIMDE_FLOAT32_C(-1262.28),
                         SIMDE_FLOAT32_C( 3998.60), SIMDE_FLOAT32_C(-3337.78),
                         SIMDE_FLOAT32_C( 2795.34), SIMDE_FLOAT32_C( 4221.94),
                         SIMDE_FLOAT32_C( -311.74), SIMDE_FLOAT32_C( 1545.54)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -71.10), SIMDE_FLOAT32_C(  -36.70),
                         SIMDE_FLOAT32_C(    2.00), SIMDE_FLOAT32_C(  -19.80),
                         SIMDE_FLOAT32_C(  -33.20), SIMDE_FLOAT32_C(   94.30),
                         SIMDE_FLOAT32_C(    1.20), SIMDE_FLOAT32_C(   43.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   91.40), SIMDE_FLOAT32_C(   40.00),
                         SIMDE_FLOAT32_C(   26.00), SIMDE_FLOAT32_C(   80.90),
                         SIMDE_FLOAT32_C(  -92.20), SIMDE_FLOAT32_C(  -86.10),
                         SIMDE_FLOAT32_C(   71.10), SIMDE_FLOAT32_C(   10.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   29.80), SIMDE_FLOAT32_C(  -33.80),
                         SIMDE_FLOAT32_C(  -52.50), SIMDE_FLOAT32_C(   52.00),
                         SIMDE_FLOAT32_C(  -20.10), SIMDE_FLOAT32_C(  -49.80),
                         SIMDE_FLOAT32_C(   36.10), SIMDE_FLOAT32_C(   37.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-6528.34), SIMDE_FLOAT32_C(-1434.20),
                         SIMDE_FLOAT32_C(  104.50), SIMDE_FLOAT32_C(-1653.82),
                         SIMDE_FLOAT32_C( 3081.14), SIMDE_FLOAT32_C(-8069.43),
                         SIMDE_FLOAT32_C(   49.22), SIMDE_FLOAT32_C(  402.35)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fmsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmsub_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   43.20), SIMDE_FLOAT64_C(  -60.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -12.80), SIMDE_FLOAT64_C(   56.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -27.10), SIMDE_FLOAT64_C(   60.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   43.20), SIMDE_FLOAT64_C(-3461.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -79.30), SIMDE_FLOAT64_C(   88.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   44.30), SIMDE_FLOAT64_C(   37.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   77.70), SIMDE_FLOAT64_C(   22.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -79.30), SIMDE_FLOAT64_C( 3302.86)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.70), SIMDE_FLOAT64_C(  -49.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   87.10), SIMDE_FLOAT64_C(  -41.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -71.70), SIMDE_FLOAT64_C(   16.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.70), SIMDE_FLOAT64_C( 2025.60)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -81.20), SIMDE_FLOAT64_C(   22.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -90.90), SIMDE_FLOAT64_C(   95.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -81.00), SIMDE_FLOAT64_C(  -21.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -81.20), SIMDE_FLOAT64_C( 2113.20)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   86.00), SIMDE_FLOAT64_C(   69.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -68.40), SIMDE_FLOAT64_C(  -83.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   95.80), SIMDE_FLOAT64_C(   94.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   86.00), SIMDE_FLOAT64_C(-5903.08)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -19.30), SIMDE_FLOAT64_C(  -49.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -62.80), SIMDE_FLOAT64_C(   42.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   30.00), SIMDE_FLOAT64_C(  -69.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -19.30), SIMDE_FLOAT64_C(-2001.60)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   23.40), SIMDE_FLOAT64_C(  -19.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   85.50), SIMDE_FLOAT64_C(   56.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   27.00), SIMDE_FLOAT64_C(  -47.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   23.40), SIMDE_FLOAT64_C(-1062.35)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.40), SIMDE_FLOAT64_C(   23.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.50), SIMDE_FLOAT64_C(   79.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   98.40), SIMDE_FLOAT64_C(  -48.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.40), SIMDE_FLOAT64_C( 1870.40)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmsub_sd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmsub_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   81.20), SIMDE_FLOAT32_C(   26.30), SIMDE_FLOAT32_C(   21.90), SIMDE_FLOAT32_C(   41.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   37.70), SIMDE_FLOAT32_C(   61.40), SIMDE_FLOAT32_C(   87.60), SIMDE_FLOAT32_C(  -37.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   85.80), SIMDE_FLOAT32_C(  -48.50), SIMDE_FLOAT32_C(   52.10), SIMDE_FLOAT32_C(   67.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   81.20), SIMDE_FLOAT32_C(   26.30), SIMDE_FLOAT32_C(   21.90), SIMDE_FLOAT32_C(-1622.66)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -23.60), SIMDE_FLOAT32_C(  -82.80), SIMDE_FLOAT32_C(   55.80), SIMDE_FLOAT32_C(  -90.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   53.10), SIMDE_FLOAT32_C(  -75.20), SIMDE_FLOAT32_C(  -26.00), SIMDE_FLOAT32_C(   93.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   47.50), SIMDE_FLOAT32_C(   39.90), SIMDE_FLOAT32_C(  -49.20), SIMDE_FLOAT32_C(  -86.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -23.60), SIMDE_FLOAT32_C(  -82.80), SIMDE_FLOAT32_C(   55.80), SIMDE_FLOAT32_C(-8383.24)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.90), SIMDE_FLOAT32_C(  -99.10), SIMDE_FLOAT32_C(   26.00), SIMDE_FLOAT32_C(   32.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   29.60), SIMDE_FLOAT32_C(  -93.20), SIMDE_FLOAT32_C(  -96.10), SIMDE_FLOAT32_C(   87.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   76.20), SIMDE_FLOAT32_C(  -98.50), SIMDE_FLOAT32_C(    4.10), SIMDE_FLOAT32_C(  -66.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.90), SIMDE_FLOAT32_C(  -99.10), SIMDE_FLOAT32_C(   26.00), SIMDE_FLOAT32_C( 2910.25)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -58.80), SIMDE_FLOAT32_C(    0.70), SIMDE_FLOAT32_C(  -50.10), SIMDE_FLOAT32_C(  -58.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   53.70), SIMDE_FLOAT32_C(  -83.00), SIMDE_FLOAT32_C(  -66.70), SIMDE_FLOAT32_C(   96.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -97.40), SIMDE_FLOAT32_C(   97.80), SIMDE_FLOAT32_C(   93.40), SIMDE_FLOAT32_C(  -82.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -58.80), SIMDE_FLOAT32_C(    0.70), SIMDE_FLOAT32_C(  -50.10), SIMDE_FLOAT32_C(-5578.26)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   26.20), SIMDE_FLOAT32_C(    0.50), SIMDE_FLOAT32_C(   53.40), SIMDE_FLOAT32_C(   40.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -60.30), SIMDE_FLOAT32_C(  -94.00), SIMDE_FLOAT32_C(   14.10), SIMDE_FLOAT32_C(  -94.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   75.80), SIMDE_FLOAT32_C(   16.70), SIMDE_FLOAT32_C(   -3.80), SIMDE_FLOAT32_C(  -98.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   26.20), SIMDE_FLOAT32_C(    0.50), SIMDE_FLOAT32_C(   53.40), SIMDE_FLOAT32_C(-3719.30)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    6.90), SIMDE_FLOAT32_C(   37.30), SIMDE_FLOAT32_C(   95.60), SIMDE_FLOAT32_C(   26.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    6.20), SIMDE_FLOAT32_C(   51.70), SIMDE_FLOAT32_C(  -27.80), SIMDE_FLOAT32_C(   35.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   96.60), SIMDE_FLOAT32_C(   16.30), SIMDE_FLOAT32_C(  -87.40), SIMDE_FLOAT32_C(   51.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    6.90), SIMDE_FLOAT32_C(   37.30), SIMDE_FLOAT32_C(   95.60), SIMDE_FLOAT32_C(  881.72)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -41.80), SIMDE_FLOAT32_C(  -50.90), SIMDE_FLOAT32_C(   94.30), SIMDE_FLOAT32_C(   92.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -51.70), SIMDE_FLOAT32_C(   66.70), SIMDE_FLOAT32_C(   35.70), SIMDE_FLOAT32_C(   84.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -89.60), SIMDE_FLOAT32_C(  -35.50), SIMDE_FLOAT32_C(  -45.20), SIMDE_FLOAT32_C(  -87.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -41.80), SIMDE_FLOAT32_C(  -50.90), SIMDE_FLOAT32_C(   94.30), SIMDE_FLOAT32_C( 7940.85)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   60.00), SIMDE_FLOAT32_C(   45.70), SIMDE_FLOAT32_C(   16.60), SIMDE_FLOAT32_C(   40.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -13.60), SIMDE_FLOAT32_C(  -11.50), SIMDE_FLOAT32_C(  -61.10), SIMDE_FLOAT32_C(  -64.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   96.70), SIMDE_FLOAT32_C(  -80.10), SIMDE_FLOAT32_C(   37.00), SIMDE_FLOAT32_C(   74.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   60.00), SIMDE_FLOAT32_C(   45.70), SIMDE_FLOAT32_C(   16.60), SIMDE_FLOAT32_C(-2687.64)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmsub_ss(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmsubadd_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.60), SIMDE_FLOAT64_C(  -67.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -79.80), SIMDE_FLOAT64_C(  -83.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   34.70), SIMDE_FLOAT64_C(  -10.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 4003.18), SIMDE_FLOAT64_C( 5567.60)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -31.80), SIMDE_FLOAT64_C(  -73.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -80.50), SIMDE_FLOAT64_C(   26.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.90), SIMDE_FLOAT64_C(  -36.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2570.80), SIMDE_FLOAT64_C(-1982.58)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    7.90), SIMDE_FLOAT64_C(  -20.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   91.90), SIMDE_FLOAT64_C(  -31.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.90), SIMDE_FLOAT64_C(  -72.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  743.91), SIMDE_FLOAT64_C(  579.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    0.90), SIMDE_FLOAT64_C(   20.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   75.20), SIMDE_FLOAT64_C(  -63.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   33.00), SIMDE_FLOAT64_C(   76.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   34.68), SIMDE_FLOAT64_C(-1240.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   45.60), SIMDE_FLOAT64_C(  -62.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -70.50), SIMDE_FLOAT64_C(   21.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -20.00), SIMDE_FLOAT64_C(   73.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-3194.80), SIMDE_FLOAT64_C(-1239.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.30), SIMDE_FLOAT64_C(  -71.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   63.70), SIMDE_FLOAT64_C(  -56.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -15.40), SIMDE_FLOAT64_C(   29.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -640.71), SIMDE_FLOAT64_C( 4083.15)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.00), SIMDE_FLOAT64_C(   -6.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -84.60), SIMDE_FLOAT64_C(  -37.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   53.20), SIMDE_FLOAT64_C(  -28.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   31.40), SIMDE_FLOAT64_C(  231.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -13.10), SIMDE_FLOAT64_C(   -9.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -34.00), SIMDE_FLOAT64_C(  -63.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   31.60), SIMDE_FLOAT64_C(  -13.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  413.80), SIMDE_FLOAT64_C(  561.30)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmsubadd_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fmsubadd_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -49.40), SIMDE_FLOAT64_C(  -57.60),
                         SIMDE_FLOAT64_C(  -73.20), SIMDE_FLOAT64_C(  -70.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.10), SIMDE_FLOAT64_C(   46.20),
                         SIMDE_FLOAT64_C(  -46.70), SIMDE_FLOAT64_C(  -70.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   79.00), SIMDE_FLOAT64_C(  -79.60),
                         SIMDE_FLOAT64_C(   19.80), SIMDE_FLOAT64_C(  -16.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -74.06), SIMDE_FLOAT64_C(-2740.72),
                         SIMDE_FLOAT64_C( 3398.64), SIMDE_FLOAT64_C( 4947.08)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -12.30), SIMDE_FLOAT64_C(   53.50),
                         SIMDE_FLOAT64_C(  -97.80), SIMDE_FLOAT64_C(  -85.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   67.10), SIMDE_FLOAT64_C(  -30.10),
                         SIMDE_FLOAT64_C(   -0.30), SIMDE_FLOAT64_C(  -23.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   49.80), SIMDE_FLOAT64_C(   87.30),
                         SIMDE_FLOAT64_C(  -23.10), SIMDE_FLOAT64_C(   15.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -875.13), SIMDE_FLOAT64_C(-1523.05),
                         SIMDE_FLOAT64_C(   52.44), SIMDE_FLOAT64_C( 2043.66)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -27.20), SIMDE_FLOAT64_C(  -72.40),
                         SIMDE_FLOAT64_C(   53.20), SIMDE_FLOAT64_C(   -9.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -71.40), SIMDE_FLOAT64_C(    0.20),
                         SIMDE_FLOAT64_C(  -61.10), SIMDE_FLOAT64_C(  -97.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   85.60), SIMDE_FLOAT64_C(   27.60),
                         SIMDE_FLOAT64_C(   19.30), SIMDE_FLOAT64_C(   46.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1856.48), SIMDE_FLOAT64_C(   13.12),
                         SIMDE_FLOAT64_C(-3269.82), SIMDE_FLOAT64_C(  970.95)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   42.40), SIMDE_FLOAT64_C(  -47.00),
                         SIMDE_FLOAT64_C(   57.40), SIMDE_FLOAT64_C(  -79.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -85.60), SIMDE_FLOAT64_C(  -55.10),
                         SIMDE_FLOAT64_C(    8.90), SIMDE_FLOAT64_C(   -9.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   78.80), SIMDE_FLOAT64_C(   18.80),
                         SIMDE_FLOAT64_C(  -90.80), SIMDE_FLOAT64_C(   46.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-3708.24), SIMDE_FLOAT64_C( 2608.50),
                         SIMDE_FLOAT64_C(  601.66), SIMDE_FLOAT64_C(  817.15)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   34.00), SIMDE_FLOAT64_C(   57.40),
                         SIMDE_FLOAT64_C(   76.30), SIMDE_FLOAT64_C(   99.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   74.30), SIMDE_FLOAT64_C(   64.30),
                         SIMDE_FLOAT64_C(  -88.20), SIMDE_FLOAT64_C(  -42.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -20.50), SIMDE_FLOAT64_C(   98.80),
                         SIMDE_FLOAT64_C(  -81.30), SIMDE_FLOAT64_C(    9.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 2546.70), SIMDE_FLOAT64_C( 3789.62),
                         SIMDE_FLOAT64_C(-6648.36), SIMDE_FLOAT64_C(-4196.38)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   26.30), SIMDE_FLOAT64_C(  -10.40),
                         SIMDE_FLOAT64_C(  -16.90), SIMDE_FLOAT64_C(  -91.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -5.60), SIMDE_FLOAT64_C(  -40.40),
                         SIMDE_FLOAT64_C(   57.90), SIMDE_FLOAT64_C(   93.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -66.10), SIMDE_FLOAT64_C(  -60.00),
                         SIMDE_FLOAT64_C(  -42.50), SIMDE_FLOAT64_C(  -45.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -81.18), SIMDE_FLOAT64_C(  360.16),
                         SIMDE_FLOAT64_C( -936.01), SIMDE_FLOAT64_C(-8628.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -77.70), SIMDE_FLOAT64_C(   79.90),
                         SIMDE_FLOAT64_C(   16.20), SIMDE_FLOAT64_C(  -77.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   18.40), SIMDE_FLOAT64_C(   71.60),
                         SIMDE_FLOAT64_C(  -95.70), SIMDE_FLOAT64_C(  -21.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -83.90), SIMDE_FLOAT64_C(   14.30),
                         SIMDE_FLOAT64_C(  -44.90), SIMDE_FLOAT64_C(   72.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1345.78), SIMDE_FLOAT64_C( 5735.14),
                         SIMDE_FLOAT64_C(-1505.44), SIMDE_FLOAT64_C( 1757.54)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   68.20), SIMDE_FLOAT64_C(   18.60),
                         SIMDE_FLOAT64_C(   38.50), SIMDE_FLOAT64_C(   98.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -61.10), SIMDE_FLOAT64_C(  -31.60),
                         SIMDE_FLOAT64_C(   70.50), SIMDE_FLOAT64_C(   85.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   94.30), SIMDE_FLOAT64_C(   91.40),
                         SIMDE_FLOAT64_C(  -28.70), SIMDE_FLOAT64_C(   64.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-4261.32), SIMDE_FLOAT64_C( -496.36),
                         SIMDE_FLOAT64_C( 2742.95), SIMDE_FLOAT64_C( 8456.80)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fmsubadd_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fmsubadd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -29.90), SIMDE_FLOAT32_C(  -50.10), SIMDE_FLOAT32_C(   13.10), SIMDE_FLOAT32_C(   52.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -63.90), SIMDE_FLOAT32_C(  -96.40), SIMDE_FLOAT32_C(   84.20), SIMDE_FLOAT32_C(  -48.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   53.80), SIMDE_FLOAT32_C(   -3.40), SIMDE_FLOAT32_C(   13.90), SIMDE_FLOAT32_C(  -46.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 1856.81), SIMDE_FLOAT32_C( 4826.24), SIMDE_FLOAT32_C( 1089.12), SIMDE_FLOAT32_C(-2566.86)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   35.60), SIMDE_FLOAT32_C(    8.10), SIMDE_FLOAT32_C(  -35.10), SIMDE_FLOAT32_C(   22.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   77.40), SIMDE_FLOAT32_C(  -43.50), SIMDE_FLOAT32_C(  -53.00), SIMDE_FLOAT32_C(   60.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   15.60), SIMDE_FLOAT32_C(   -4.70), SIMDE_FLOAT32_C(   24.20), SIMDE_FLOAT32_C(  -46.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 2739.84), SIMDE_FLOAT32_C( -357.05), SIMDE_FLOAT32_C( 1836.10), SIMDE_FLOAT32_C( 1309.14)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -92.90), SIMDE_FLOAT32_C(   31.90), SIMDE_FLOAT32_C(  -29.90), SIMDE_FLOAT32_C(  -95.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   46.90), SIMDE_FLOAT32_C(  -89.80), SIMDE_FLOAT32_C(   18.10), SIMDE_FLOAT32_C(  -72.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   79.60), SIMDE_FLOAT32_C(  -32.40), SIMDE_FLOAT32_C(   -3.60), SIMDE_FLOAT32_C(  -57.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-4436.61), SIMDE_FLOAT32_C(-2897.02), SIMDE_FLOAT32_C( -537.59), SIMDE_FLOAT32_C( 6871.21)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   68.50), SIMDE_FLOAT32_C(   48.90), SIMDE_FLOAT32_C(   86.30), SIMDE_FLOAT32_C(   72.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -80.00), SIMDE_FLOAT32_C(  -44.60), SIMDE_FLOAT32_C(   -3.60), SIMDE_FLOAT32_C(  -91.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -57.30), SIMDE_FLOAT32_C(    2.10), SIMDE_FLOAT32_C(  -33.70), SIMDE_FLOAT32_C(  -13.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-5422.70), SIMDE_FLOAT32_C(-2178.84), SIMDE_FLOAT32_C( -276.98), SIMDE_FLOAT32_C(-6581.91)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -38.10), SIMDE_FLOAT32_C(  -61.30), SIMDE_FLOAT32_C(   38.90), SIMDE_FLOAT32_C(  -79.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   64.20), SIMDE_FLOAT32_C(   71.60), SIMDE_FLOAT32_C(  -99.30), SIMDE_FLOAT32_C(  -87.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -46.40), SIMDE_FLOAT32_C(   45.20), SIMDE_FLOAT32_C(  -56.00), SIMDE_FLOAT32_C(    0.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-2399.62), SIMDE_FLOAT32_C(-4343.88), SIMDE_FLOAT32_C(-3806.77), SIMDE_FLOAT32_C( 6915.36)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -88.30), SIMDE_FLOAT32_C(  -23.50), SIMDE_FLOAT32_C(   48.80), SIMDE_FLOAT32_C(  -55.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -31.80), SIMDE_FLOAT32_C(   50.50), SIMDE_FLOAT32_C(  -24.10), SIMDE_FLOAT32_C(  -80.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -18.70), SIMDE_FLOAT32_C(  -24.70), SIMDE_FLOAT32_C(  -56.50), SIMDE_FLOAT32_C(   57.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 2826.64), SIMDE_FLOAT32_C(-1211.45), SIMDE_FLOAT32_C(-1119.58), SIMDE_FLOAT32_C( 4476.72)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   48.60), SIMDE_FLOAT32_C(   33.60), SIMDE_FLOAT32_C(    8.60), SIMDE_FLOAT32_C(   57.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   52.40), SIMDE_FLOAT32_C(    2.70), SIMDE_FLOAT32_C(   57.50), SIMDE_FLOAT32_C(  -10.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -26.60), SIMDE_FLOAT32_C(  -67.20), SIMDE_FLOAT32_C(    5.80), SIMDE_FLOAT32_C(   75.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 2573.24), SIMDE_FLOAT32_C(   23.52), SIMDE_FLOAT32_C(  488.70), SIMDE_FLOAT32_C( -527.16)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -25.60), SIMDE_FLOAT32_C(   57.60), SIMDE_FLOAT32_C(  -91.00), SIMDE_FLOAT32_C(   53.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -92.00), SIMDE_FLOAT32_C(   35.10), SIMDE_FLOAT32_C(    8.60), SIMDE_FLOAT32_C(    0.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -41.20), SIMDE_FLOAT32_C(  -81.00), SIMDE_FLOAT32_C(  -21.80), SIMDE_FLOAT32_C(  -49.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 2396.40), SIMDE_FLOAT32_C( 1940.76), SIMDE_FLOAT32_C( -760.80), SIMDE_FLOAT32_C(  -49.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmsubadd_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fmsubadd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   80.60), SIMDE_FLOAT32_C(  -80.20),
                         SIMDE_FLOAT32_C(   25.10), SIMDE_FLOAT32_C(   54.40),
                         SIMDE_FLOAT32_C(  -94.50), SIMDE_FLOAT32_C(  -99.70),
                         SIMDE_FLOAT32_C(   67.30), SIMDE_FLOAT32_C(   -5.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -98.10), SIMDE_FLOAT32_C(  -47.30),
                         SIMDE_FLOAT32_C(  -82.80), SIMDE_FLOAT32_C(  -26.80),
                         SIMDE_FLOAT32_C(   87.80), SIMDE_FLOAT32_C(   71.10),
                         SIMDE_FLOAT32_C(   92.80), SIMDE_FLOAT32_C(  -97.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -36.00), SIMDE_FLOAT32_C(  -59.40),
                         SIMDE_FLOAT32_C(  -69.40), SIMDE_FLOAT32_C(   50.50),
                         SIMDE_FLOAT32_C(   70.50), SIMDE_FLOAT32_C(   26.60),
                         SIMDE_FLOAT32_C(   29.70), SIMDE_FLOAT32_C(  -14.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-7870.86), SIMDE_FLOAT32_C( 3734.06),
                         SIMDE_FLOAT32_C(-2008.88), SIMDE_FLOAT32_C(-1407.42),
                         SIMDE_FLOAT32_C(-8367.60), SIMDE_FLOAT32_C(-7062.07),
                         SIMDE_FLOAT32_C( 6215.74), SIMDE_FLOAT32_C(  553.02)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -68.50), SIMDE_FLOAT32_C(  -56.10),
                         SIMDE_FLOAT32_C(   89.00), SIMDE_FLOAT32_C(  -96.30),
                         SIMDE_FLOAT32_C(   41.10), SIMDE_FLOAT32_C(  -67.50),
                         SIMDE_FLOAT32_C(   59.30), SIMDE_FLOAT32_C(  -62.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -50.40), SIMDE_FLOAT32_C(  -79.00),
                         SIMDE_FLOAT32_C(   93.10), SIMDE_FLOAT32_C(  -46.20),
                         SIMDE_FLOAT32_C(  -86.10), SIMDE_FLOAT32_C(   19.30),
                         SIMDE_FLOAT32_C(  -62.90), SIMDE_FLOAT32_C(  -49.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -28.70), SIMDE_FLOAT32_C(  -24.80),
                         SIMDE_FLOAT32_C(   30.30), SIMDE_FLOAT32_C(  -97.00),
                         SIMDE_FLOAT32_C(  -57.70), SIMDE_FLOAT32_C(  -32.40),
                         SIMDE_FLOAT32_C(   -8.20), SIMDE_FLOAT32_C(   75.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 3481.10), SIMDE_FLOAT32_C( 4407.10),
                         SIMDE_FLOAT32_C( 8255.60), SIMDE_FLOAT32_C( 4352.06),
                         SIMDE_FLOAT32_C(-3481.01), SIMDE_FLOAT32_C(-1335.15),
                         SIMDE_FLOAT32_C(-3721.77), SIMDE_FLOAT32_C( 3176.17)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -40.40), SIMDE_FLOAT32_C(   50.40),
                         SIMDE_FLOAT32_C(    3.90), SIMDE_FLOAT32_C(  -96.60),
                         SIMDE_FLOAT32_C(   84.00), SIMDE_FLOAT32_C(   63.30),
                         SIMDE_FLOAT32_C(   71.70), SIMDE_FLOAT32_C(   -5.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   88.10), SIMDE_FLOAT32_C(   75.30),
                         SIMDE_FLOAT32_C(  -17.10), SIMDE_FLOAT32_C(  -27.60),
                         SIMDE_FLOAT32_C(   47.20), SIMDE_FLOAT32_C(  -72.70),
                         SIMDE_FLOAT32_C(  -49.20), SIMDE_FLOAT32_C(  -33.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   96.20), SIMDE_FLOAT32_C(   64.10),
                         SIMDE_FLOAT32_C(   96.10), SIMDE_FLOAT32_C(  -18.70),
                         SIMDE_FLOAT32_C(  -31.60), SIMDE_FLOAT32_C(   43.60),
                         SIMDE_FLOAT32_C(  -90.90), SIMDE_FLOAT32_C(  -27.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-3655.44), SIMDE_FLOAT32_C( 3859.22),
                         SIMDE_FLOAT32_C( -162.79), SIMDE_FLOAT32_C( 2647.46),
                         SIMDE_FLOAT32_C( 3996.40), SIMDE_FLOAT32_C(-4558.31),
                         SIMDE_FLOAT32_C(-3436.74), SIMDE_FLOAT32_C(  151.44)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -59.60), SIMDE_FLOAT32_C(  -83.90),
                         SIMDE_FLOAT32_C(   58.10), SIMDE_FLOAT32_C(   -6.90),
                         SIMDE_FLOAT32_C(   99.80), SIMDE_FLOAT32_C(  -64.30),
                         SIMDE_FLOAT32_C(   87.70), SIMDE_FLOAT32_C(   55.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   53.60), SIMDE_FLOAT32_C(   89.30),
                         SIMDE_FLOAT32_C(  -70.60), SIMDE_FLOAT32_C(   99.70),
                         SIMDE_FLOAT32_C(   -5.30), SIMDE_FLOAT32_C(    5.60),
                         SIMDE_FLOAT32_C(   86.80), SIMDE_FLOAT32_C(   -0.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   15.90), SIMDE_FLOAT32_C(  -12.20),
                         SIMDE_FLOAT32_C(   93.70), SIMDE_FLOAT32_C(  -91.90),
                         SIMDE_FLOAT32_C(   34.20), SIMDE_FLOAT32_C(  -64.50),
                         SIMDE_FLOAT32_C(   97.10), SIMDE_FLOAT32_C(   -8.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-3210.46), SIMDE_FLOAT32_C(-7504.47),
                         SIMDE_FLOAT32_C(-4195.56), SIMDE_FLOAT32_C( -779.83),
                         SIMDE_FLOAT32_C( -563.14), SIMDE_FLOAT32_C( -424.58),
                         SIMDE_FLOAT32_C( 7515.26), SIMDE_FLOAT32_C(  -19.08)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   49.20), SIMDE_FLOAT32_C(  -59.10),
                         SIMDE_FLOAT32_C(  -10.90), SIMDE_FLOAT32_C(  -67.30),
                         SIMDE_FLOAT32_C(   52.90), SIMDE_FLOAT32_C(   -9.10),
                         SIMDE_FLOAT32_C(  -30.60), SIMDE_FLOAT32_C(  -79.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -82.90), SIMDE_FLOAT32_C(   24.10),
                         SIMDE_FLOAT32_C(    5.20), SIMDE_FLOAT32_C(   -4.60),
                         SIMDE_FLOAT32_C(  -64.40), SIMDE_FLOAT32_C(   -6.30),
                         SIMDE_FLOAT32_C(   88.20), SIMDE_FLOAT32_C(   59.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   59.30), SIMDE_FLOAT32_C(  -23.80),
                         SIMDE_FLOAT32_C(   86.10), SIMDE_FLOAT32_C(   45.80),
                         SIMDE_FLOAT32_C(  -77.20), SIMDE_FLOAT32_C(    3.40),
                         SIMDE_FLOAT32_C(   70.60), SIMDE_FLOAT32_C(  -87.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-4137.98), SIMDE_FLOAT32_C(-1448.11),
                         SIMDE_FLOAT32_C( -142.78), SIMDE_FLOAT32_C(  355.38),
                         SIMDE_FLOAT32_C(-3329.56), SIMDE_FLOAT32_C(   60.73),
                         SIMDE_FLOAT32_C(-2769.52), SIMDE_FLOAT32_C(-4769.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -41.90), SIMDE_FLOAT32_C(   60.40),
                         SIMDE_FLOAT32_C(  -79.60), SIMDE_FLOAT32_C(   95.50),
                         SIMDE_FLOAT32_C(   31.30), SIMDE_FLOAT32_C(  -95.40),
                         SIMDE_FLOAT32_C(   27.30), SIMDE_FLOAT32_C(   96.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   46.90), SIMDE_FLOAT32_C(  -42.30),
                         SIMDE_FLOAT32_C(   95.50), SIMDE_FLOAT32_C(  -75.00),
                         SIMDE_FLOAT32_C(   48.70), SIMDE_FLOAT32_C(   76.90),
                         SIMDE_FLOAT32_C(   81.90), SIMDE_FLOAT32_C(   70.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -69.40), SIMDE_FLOAT32_C(   89.00),
                         SIMDE_FLOAT32_C(  -88.50), SIMDE_FLOAT32_C(   76.60),
                         SIMDE_FLOAT32_C(  -55.90), SIMDE_FLOAT32_C(  -98.10),
                         SIMDE_FLOAT32_C(  -24.00), SIMDE_FLOAT32_C(  -35.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1895.71), SIMDE_FLOAT32_C(-2465.92),
                         SIMDE_FLOAT32_C(-7513.30), SIMDE_FLOAT32_C(-7085.90),
                         SIMDE_FLOAT32_C( 1580.21), SIMDE_FLOAT32_C(-7434.36),
                         SIMDE_FLOAT32_C( 2259.87), SIMDE_FLOAT32_C( 6756.89)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   12.90), SIMDE_FLOAT32_C(   65.20),
                         SIMDE_FLOAT32_C(   56.70), SIMDE_FLOAT32_C(   39.40),
                         SIMDE_FLOAT32_C(  -25.60), SIMDE_FLOAT32_C(   -1.40),
                         SIMDE_FLOAT32_C(   44.70), SIMDE_FLOAT32_C(  -72.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -49.00), SIMDE_FLOAT32_C(   97.00),
                         SIMDE_FLOAT32_C(  -63.50), SIMDE_FLOAT32_C(  -40.00),
                         SIMDE_FLOAT32_C(   48.40), SIMDE_FLOAT32_C(   30.20),
                         SIMDE_FLOAT32_C(  -73.80), SIMDE_FLOAT32_C(  -79.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    5.30), SIMDE_FLOAT32_C(   28.90),
                         SIMDE_FLOAT32_C(   61.30), SIMDE_FLOAT32_C(   -5.70),
                         SIMDE_FLOAT32_C(   39.10), SIMDE_FLOAT32_C(  -88.70),
                         SIMDE_FLOAT32_C(   17.20), SIMDE_FLOAT32_C(    0.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -637.40), SIMDE_FLOAT32_C( 6353.30),
                         SIMDE_FLOAT32_C(-3661.75), SIMDE_FLOAT32_C(-1581.70),
                         SIMDE_FLOAT32_C(-1278.14), SIMDE_FLOAT32_C( -130.98),
                         SIMDE_FLOAT32_C(-3316.06), SIMDE_FLOAT32_C( 5724.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    1.50), SIMDE_FLOAT32_C(  -69.70),
                         SIMDE_FLOAT32_C(  -80.70), SIMDE_FLOAT32_C(    7.80),
                         SIMDE_FLOAT32_C(  -92.30), SIMDE_FLOAT32_C(   11.90),
                         SIMDE_FLOAT32_C(   59.30), SIMDE_FLOAT32_C(  -21.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -78.70), SIMDE_FLOAT32_C(  -69.80),
                         SIMDE_FLOAT32_C(   38.10), SIMDE_FLOAT32_C(   22.10),
                         SIMDE_FLOAT32_C(  -96.20), SIMDE_FLOAT32_C(   60.20),
                         SIMDE_FLOAT32_C(   49.80), SIMDE_FLOAT32_C(  -68.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   52.80), SIMDE_FLOAT32_C(    2.20),
                         SIMDE_FLOAT32_C(  -17.20), SIMDE_FLOAT32_C(   60.50),
                         SIMDE_FLOAT32_C(  -86.40), SIMDE_FLOAT32_C(  -89.40),
                         SIMDE_FLOAT32_C(  -67.80), SIMDE_FLOAT32_C(    4.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -170.85), SIMDE_FLOAT32_C( 4867.26),
                         SIMDE_FLOAT32_C(-3057.47), SIMDE_FLOAT32_C(  232.88),
                         SIMDE_FLOAT32_C( 8965.66), SIMDE_FLOAT32_C(  626.98),
                         SIMDE_FLOAT32_C( 3020.94), SIMDE_FLOAT32_C( 1470.30)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fmsubadd_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fnmadd_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -93.70), SIMDE_FLOAT64_C(   14.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    8.90), SIMDE_FLOAT64_C(  -15.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -87.90), SIMDE_FLOAT64_C(  -34.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  746.03), SIMDE_FLOAT64_C(  194.16)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   38.10), SIMDE_FLOAT64_C(  -13.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   63.40), SIMDE_FLOAT64_C(  -68.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   13.30), SIMDE_FLOAT64_C(  -61.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-2402.24), SIMDE_FLOAT64_C( -969.76)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   94.40), SIMDE_FLOAT64_C(   89.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -60.60), SIMDE_FLOAT64_C(  -24.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -87.30), SIMDE_FLOAT64_C(   84.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 5633.34), SIMDE_FLOAT64_C( 2305.33)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -6.90), SIMDE_FLOAT64_C(   88.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    6.60), SIMDE_FLOAT64_C(  -57.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   35.50), SIMDE_FLOAT64_C(   30.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   81.04), SIMDE_FLOAT64_C( 5163.44)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   51.80), SIMDE_FLOAT64_C(   95.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.60), SIMDE_FLOAT64_C(  -59.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -97.40), SIMDE_FLOAT64_C(  -60.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2886.28), SIMDE_FLOAT64_C( 5650.60)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   71.70), SIMDE_FLOAT64_C(  -99.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   27.40), SIMDE_FLOAT64_C(   37.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   62.10), SIMDE_FLOAT64_C(   17.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1902.48), SIMDE_FLOAT64_C( 3785.16)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   43.60), SIMDE_FLOAT64_C(   78.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -37.30), SIMDE_FLOAT64_C(   -4.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -23.90), SIMDE_FLOAT64_C(   -9.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 1602.38), SIMDE_FLOAT64_C(  369.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   26.20), SIMDE_FLOAT64_C(  -96.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   57.90), SIMDE_FLOAT64_C(   91.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   97.90), SIMDE_FLOAT64_C(   18.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1419.08), SIMDE_FLOAT64_C( 8857.20)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fnmadd_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fnmadd_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   17.60), SIMDE_FLOAT64_C(  -99.20),
                         SIMDE_FLOAT64_C(   64.80), SIMDE_FLOAT64_C(  -66.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -84.50), SIMDE_FLOAT64_C(   62.70),
                         SIMDE_FLOAT64_C(   -1.00), SIMDE_FLOAT64_C(   62.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    6.20), SIMDE_FLOAT64_C(  -52.40),
                         SIMDE_FLOAT64_C(  -54.70), SIMDE_FLOAT64_C(   93.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1493.40), SIMDE_FLOAT64_C( 6167.44),
                         SIMDE_FLOAT64_C(   10.10), SIMDE_FLOAT64_C( 4210.10)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.30), SIMDE_FLOAT64_C(   67.00),
                         SIMDE_FLOAT64_C(   26.40), SIMDE_FLOAT64_C(   52.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    8.30), SIMDE_FLOAT64_C(   -6.70),
                         SIMDE_FLOAT64_C(  -38.30), SIMDE_FLOAT64_C(  -42.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   77.70), SIMDE_FLOAT64_C(   26.30),
                         SIMDE_FLOAT64_C(   10.50), SIMDE_FLOAT64_C(   36.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  661.19), SIMDE_FLOAT64_C(  475.20),
                         SIMDE_FLOAT64_C( 1021.62), SIMDE_FLOAT64_C( 2231.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -57.10), SIMDE_FLOAT64_C(   58.80),
                         SIMDE_FLOAT64_C(   93.20), SIMDE_FLOAT64_C(  -86.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   59.10), SIMDE_FLOAT64_C(   76.50),
                         SIMDE_FLOAT64_C(   45.10), SIMDE_FLOAT64_C(   67.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   60.20), SIMDE_FLOAT64_C(   65.10),
                         SIMDE_FLOAT64_C(  -17.00), SIMDE_FLOAT64_C(  -84.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 3434.81), SIMDE_FLOAT64_C(-4433.10),
                         SIMDE_FLOAT64_C(-4220.32), SIMDE_FLOAT64_C( 5791.96)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   34.60), SIMDE_FLOAT64_C(   -5.80),
                         SIMDE_FLOAT64_C(   89.80), SIMDE_FLOAT64_C(  -83.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   43.00), SIMDE_FLOAT64_C(    3.10),
                         SIMDE_FLOAT64_C(  -37.70), SIMDE_FLOAT64_C(  -40.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   26.40), SIMDE_FLOAT64_C(  -59.60),
                         SIMDE_FLOAT64_C(  -71.50), SIMDE_FLOAT64_C(   60.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1461.40), SIMDE_FLOAT64_C(  -41.62),
                         SIMDE_FLOAT64_C( 3313.96), SIMDE_FLOAT64_C(-3317.52)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   40.20), SIMDE_FLOAT64_C(  -24.50),
                         SIMDE_FLOAT64_C(  -31.60), SIMDE_FLOAT64_C(    3.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   39.80), SIMDE_FLOAT64_C(   32.70),
                         SIMDE_FLOAT64_C(   20.30), SIMDE_FLOAT64_C(   49.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   69.00), SIMDE_FLOAT64_C(    7.80),
                         SIMDE_FLOAT64_C(   99.70), SIMDE_FLOAT64_C(   49.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1530.96), SIMDE_FLOAT64_C(  808.95),
                         SIMDE_FLOAT64_C(  741.18), SIMDE_FLOAT64_C( -114.81)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -82.30), SIMDE_FLOAT64_C(   -8.50),
                         SIMDE_FLOAT64_C(  -80.50), SIMDE_FLOAT64_C(    9.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   52.10), SIMDE_FLOAT64_C(  -96.40),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  -86.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -93.70), SIMDE_FLOAT64_C(    8.90),
                         SIMDE_FLOAT64_C(   46.10), SIMDE_FLOAT64_C(  -50.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 4194.13), SIMDE_FLOAT64_C( -810.50),
                         SIMDE_FLOAT64_C(  287.60), SIMDE_FLOAT64_C(  731.70)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   72.30), SIMDE_FLOAT64_C(   96.70),
                         SIMDE_FLOAT64_C(  -51.00), SIMDE_FLOAT64_C(  -38.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   37.50), SIMDE_FLOAT64_C(   93.30),
                         SIMDE_FLOAT64_C(   79.70), SIMDE_FLOAT64_C(   71.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   54.00), SIMDE_FLOAT64_C(    6.80),
                         SIMDE_FLOAT64_C(  -77.40), SIMDE_FLOAT64_C(  -48.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-2657.25), SIMDE_FLOAT64_C(-9015.31),
                         SIMDE_FLOAT64_C( 3987.30), SIMDE_FLOAT64_C( 2665.10)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -52.40), SIMDE_FLOAT64_C(  -75.40),
                         SIMDE_FLOAT64_C(  -96.00), SIMDE_FLOAT64_C(  -23.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -21.90), SIMDE_FLOAT64_C(  -53.30),
                         SIMDE_FLOAT64_C(  -90.50), SIMDE_FLOAT64_C(  -18.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -63.30), SIMDE_FLOAT64_C(  -23.10),
                         SIMDE_FLOAT64_C(  -88.90), SIMDE_FLOAT64_C(   67.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1210.86), SIMDE_FLOAT64_C(-4041.92),
                         SIMDE_FLOAT64_C(-8776.90), SIMDE_FLOAT64_C( -355.63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fnmadd_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fnmadd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    5.20), SIMDE_FLOAT32_C(   59.60), SIMDE_FLOAT32_C(   87.70), SIMDE_FLOAT32_C(   47.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -48.20), SIMDE_FLOAT32_C(  -88.00), SIMDE_FLOAT32_C(   90.80), SIMDE_FLOAT32_C(  -22.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -19.00), SIMDE_FLOAT32_C(   40.90), SIMDE_FLOAT32_C(   74.00), SIMDE_FLOAT32_C(   71.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  231.64), SIMDE_FLOAT32_C( 5285.70), SIMDE_FLOAT32_C(-7889.16), SIMDE_FLOAT32_C( 1150.39)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   23.70), SIMDE_FLOAT32_C(   46.10), SIMDE_FLOAT32_C(   -5.90), SIMDE_FLOAT32_C(   49.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    6.50), SIMDE_FLOAT32_C(   83.40), SIMDE_FLOAT32_C(  -86.10), SIMDE_FLOAT32_C(   15.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -10.40), SIMDE_FLOAT32_C(  -37.00), SIMDE_FLOAT32_C(  -97.90), SIMDE_FLOAT32_C(   43.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -164.45), SIMDE_FLOAT32_C(-3881.74), SIMDE_FLOAT32_C( -605.89), SIMDE_FLOAT32_C( -725.28)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -41.10), SIMDE_FLOAT32_C(   98.60), SIMDE_FLOAT32_C(  -66.40), SIMDE_FLOAT32_C(   31.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   80.90), SIMDE_FLOAT32_C(  -40.10), SIMDE_FLOAT32_C(  -24.70), SIMDE_FLOAT32_C(    7.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   99.20), SIMDE_FLOAT32_C(  -40.90), SIMDE_FLOAT32_C(  -69.50), SIMDE_FLOAT32_C(    9.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3424.19), SIMDE_FLOAT32_C( 3912.96), SIMDE_FLOAT32_C(-1709.58), SIMDE_FLOAT32_C( -237.37)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.30), SIMDE_FLOAT32_C(   18.10), SIMDE_FLOAT32_C(  -38.40), SIMDE_FLOAT32_C(  -54.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -5.80), SIMDE_FLOAT32_C(   84.90), SIMDE_FLOAT32_C(  -77.80), SIMDE_FLOAT32_C(  -32.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -23.10), SIMDE_FLOAT32_C(    3.00), SIMDE_FLOAT32_C(    5.40), SIMDE_FLOAT32_C(   61.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -21.36), SIMDE_FLOAT32_C(-1533.69), SIMDE_FLOAT32_C(-2982.12), SIMDE_FLOAT32_C(-1714.11)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -95.30), SIMDE_FLOAT32_C(  -61.60), SIMDE_FLOAT32_C(  -95.50), SIMDE_FLOAT32_C(  -55.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -67.20), SIMDE_FLOAT32_C(   95.00), SIMDE_FLOAT32_C(   94.10), SIMDE_FLOAT32_C(   87.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   45.20), SIMDE_FLOAT32_C(  -12.10), SIMDE_FLOAT32_C(  -17.00), SIMDE_FLOAT32_C(  -48.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-6358.96), SIMDE_FLOAT32_C( 5839.90), SIMDE_FLOAT32_C( 8969.55), SIMDE_FLOAT32_C( 4767.04)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -85.20), SIMDE_FLOAT32_C(  -17.40), SIMDE_FLOAT32_C(    5.50), SIMDE_FLOAT32_C(   51.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   84.50), SIMDE_FLOAT32_C(    0.60), SIMDE_FLOAT32_C(   61.30), SIMDE_FLOAT32_C(   -9.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -44.50), SIMDE_FLOAT32_C(  -83.00), SIMDE_FLOAT32_C(  -17.60), SIMDE_FLOAT32_C(  -95.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 7154.90), SIMDE_FLOAT32_C(  -72.56), SIMDE_FLOAT32_C( -354.75), SIMDE_FLOAT32_C(  393.20)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   40.00), SIMDE_FLOAT32_C(  -99.20), SIMDE_FLOAT32_C(  -45.30), SIMDE_FLOAT32_C(   65.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    3.60), SIMDE_FLOAT32_C(  -27.50), SIMDE_FLOAT32_C(   92.40), SIMDE_FLOAT32_C(  -74.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   91.90), SIMDE_FLOAT32_C(   62.60), SIMDE_FLOAT32_C(   33.10), SIMDE_FLOAT32_C(   17.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -52.10), SIMDE_FLOAT32_C(-2665.40), SIMDE_FLOAT32_C( 4218.82), SIMDE_FLOAT32_C( 4842.10)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   46.00), SIMDE_FLOAT32_C(    7.80), SIMDE_FLOAT32_C(   62.40), SIMDE_FLOAT32_C(   98.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   60.60), SIMDE_FLOAT32_C(  -96.70), SIMDE_FLOAT32_C(   86.60), SIMDE_FLOAT32_C(   94.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   57.50), SIMDE_FLOAT32_C(  -34.30), SIMDE_FLOAT32_C(  -42.40), SIMDE_FLOAT32_C(  -32.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-2730.10), SIMDE_FLOAT32_C(  719.96), SIMDE_FLOAT32_C(-5446.24), SIMDE_FLOAT32_C(-9302.38)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fnmadd_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fnmadd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -74.50), SIMDE_FLOAT32_C(   76.00),
                         SIMDE_FLOAT32_C(  -65.60), SIMDE_FLOAT32_C(  -57.80),
                         SIMDE_FLOAT32_C(   48.90), SIMDE_FLOAT32_C(   17.90),
                         SIMDE_FLOAT32_C(   92.90), SIMDE_FLOAT32_C(   17.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -79.20), SIMDE_FLOAT32_C(   67.50),
                         SIMDE_FLOAT32_C(  -50.60), SIMDE_FLOAT32_C(   96.50),
                         SIMDE_FLOAT32_C(  -92.70), SIMDE_FLOAT32_C(   12.20),
                         SIMDE_FLOAT32_C(  -41.10), SIMDE_FLOAT32_C(  -24.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -20.70), SIMDE_FLOAT32_C(   76.20),
                         SIMDE_FLOAT32_C(  -47.10), SIMDE_FLOAT32_C(  -61.40),
                         SIMDE_FLOAT32_C(   55.90), SIMDE_FLOAT32_C(   79.30),
                         SIMDE_FLOAT32_C(  -95.40), SIMDE_FLOAT32_C(   98.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-5921.10), SIMDE_FLOAT32_C(-5053.80),
                         SIMDE_FLOAT32_C(-3366.46), SIMDE_FLOAT32_C( 5516.30),
                         SIMDE_FLOAT32_C( 4588.93), SIMDE_FLOAT32_C( -139.08),
                         SIMDE_FLOAT32_C( 3722.79), SIMDE_FLOAT32_C(  527.18)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   34.30), SIMDE_FLOAT32_C(   90.50),
                         SIMDE_FLOAT32_C(  -43.40), SIMDE_FLOAT32_C(  -95.00),
                         SIMDE_FLOAT32_C(  -62.70), SIMDE_FLOAT32_C(  -17.10),
                         SIMDE_FLOAT32_C(   30.50), SIMDE_FLOAT32_C(    1.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -23.20), SIMDE_FLOAT32_C(   28.90),
                         SIMDE_FLOAT32_C(   78.70), SIMDE_FLOAT32_C(    6.50),
                         SIMDE_FLOAT32_C(  -13.60), SIMDE_FLOAT32_C(    7.60),
                         SIMDE_FLOAT32_C(  -56.70), SIMDE_FLOAT32_C(   52.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -24.30), SIMDE_FLOAT32_C(   65.20),
                         SIMDE_FLOAT32_C(   27.90), SIMDE_FLOAT32_C(  -88.40),
                         SIMDE_FLOAT32_C(  -43.70), SIMDE_FLOAT32_C(   61.70),
                         SIMDE_FLOAT32_C(  -22.10), SIMDE_FLOAT32_C(  -51.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  771.46), SIMDE_FLOAT32_C(-2550.25),
                         SIMDE_FLOAT32_C( 3443.48), SIMDE_FLOAT32_C(  529.10),
                         SIMDE_FLOAT32_C( -896.42), SIMDE_FLOAT32_C(  191.66),
                         SIMDE_FLOAT32_C( 1707.25), SIMDE_FLOAT32_C( -104.10)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   95.30), SIMDE_FLOAT32_C(  -81.70),
                         SIMDE_FLOAT32_C(   51.00), SIMDE_FLOAT32_C(    6.50),
                         SIMDE_FLOAT32_C(   46.00), SIMDE_FLOAT32_C(   76.10),
                         SIMDE_FLOAT32_C(  -72.70), SIMDE_FLOAT32_C(   10.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   67.00), SIMDE_FLOAT32_C(  -43.80),
                         SIMDE_FLOAT32_C(    5.70), SIMDE_FLOAT32_C(    9.00),
                         SIMDE_FLOAT32_C(   39.70), SIMDE_FLOAT32_C(  -47.40),
                         SIMDE_FLOAT32_C(  -89.40), SIMDE_FLOAT32_C(  -69.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    5.10), SIMDE_FLOAT32_C(  -27.10),
                         SIMDE_FLOAT32_C(   24.30), SIMDE_FLOAT32_C(  -90.10),
                         SIMDE_FLOAT32_C(   48.70), SIMDE_FLOAT32_C(   91.00),
                         SIMDE_FLOAT32_C(   80.80), SIMDE_FLOAT32_C(  -24.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-6380.00), SIMDE_FLOAT32_C(-3605.56),
                         SIMDE_FLOAT32_C( -266.40), SIMDE_FLOAT32_C( -148.60),
                         SIMDE_FLOAT32_C(-1777.50), SIMDE_FLOAT32_C( 3698.14),
                         SIMDE_FLOAT32_C(-6418.58), SIMDE_FLOAT32_C(  673.31)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    5.80), SIMDE_FLOAT32_C(    2.80),
                         SIMDE_FLOAT32_C(   37.80), SIMDE_FLOAT32_C(  -55.50),
                         SIMDE_FLOAT32_C(   60.80), SIMDE_FLOAT32_C(  -46.40),
                         SIMDE_FLOAT32_C(  -53.70), SIMDE_FLOAT32_C(  -55.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   76.00), SIMDE_FLOAT32_C(   65.10),
                         SIMDE_FLOAT32_C(   67.70), SIMDE_FLOAT32_C(  -84.20),
                         SIMDE_FLOAT32_C(   63.00), SIMDE_FLOAT32_C(  -82.10),
                         SIMDE_FLOAT32_C(  -55.20), SIMDE_FLOAT32_C(   20.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   60.20), SIMDE_FLOAT32_C(  -85.50),
                         SIMDE_FLOAT32_C(   58.00), SIMDE_FLOAT32_C(   40.40),
                         SIMDE_FLOAT32_C(   31.70), SIMDE_FLOAT32_C(   -6.20),
                         SIMDE_FLOAT32_C(   83.70), SIMDE_FLOAT32_C(  -68.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -380.60), SIMDE_FLOAT32_C( -267.78),
                         SIMDE_FLOAT32_C(-2501.06), SIMDE_FLOAT32_C(-4632.70),
                         SIMDE_FLOAT32_C(-3798.70), SIMDE_FLOAT32_C(-3815.64),
                         SIMDE_FLOAT32_C(-2880.54), SIMDE_FLOAT32_C( 1051.07)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -30.40), SIMDE_FLOAT32_C(   81.70),
                         SIMDE_FLOAT32_C(  -68.60), SIMDE_FLOAT32_C(   46.50),
                         SIMDE_FLOAT32_C(   53.40), SIMDE_FLOAT32_C(   -1.10),
                         SIMDE_FLOAT32_C(  -70.80), SIMDE_FLOAT32_C(   10.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   99.90), SIMDE_FLOAT32_C(  -78.30),
                         SIMDE_FLOAT32_C(  -52.60), SIMDE_FLOAT32_C(   28.60),
                         SIMDE_FLOAT32_C(   62.90), SIMDE_FLOAT32_C(  -65.50),
                         SIMDE_FLOAT32_C(  -51.00), SIMDE_FLOAT32_C(   -0.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   25.50), SIMDE_FLOAT32_C(    2.70),
                         SIMDE_FLOAT32_C(   99.80), SIMDE_FLOAT32_C(  -76.10),
                         SIMDE_FLOAT32_C(   -4.50), SIMDE_FLOAT32_C(    7.40),
                         SIMDE_FLOAT32_C(   81.50), SIMDE_FLOAT32_C(    1.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 3062.46), SIMDE_FLOAT32_C( 6399.81),
                         SIMDE_FLOAT32_C(-3508.56), SIMDE_FLOAT32_C(-1406.00),
                         SIMDE_FLOAT32_C(-3363.36), SIMDE_FLOAT32_C(  -64.65),
                         SIMDE_FLOAT32_C(-3529.30), SIMDE_FLOAT32_C(    3.54)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   78.00), SIMDE_FLOAT32_C(   45.70),
                         SIMDE_FLOAT32_C(   59.30), SIMDE_FLOAT32_C(   35.50),
                         SIMDE_FLOAT32_C(   91.10), SIMDE_FLOAT32_C(  -96.00),
                         SIMDE_FLOAT32_C(  -93.90), SIMDE_FLOAT32_C(   -0.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -80.10), SIMDE_FLOAT32_C(   37.30),
                         SIMDE_FLOAT32_C(   94.60), SIMDE_FLOAT32_C(  -45.10),
                         SIMDE_FLOAT32_C(  -34.70), SIMDE_FLOAT32_C(  -33.50),
                         SIMDE_FLOAT32_C(  -17.00), SIMDE_FLOAT32_C(  -46.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.60), SIMDE_FLOAT32_C(   47.00),
                         SIMDE_FLOAT32_C(  -93.40), SIMDE_FLOAT32_C(  -34.90),
                         SIMDE_FLOAT32_C(   77.40), SIMDE_FLOAT32_C(  -96.40),
                         SIMDE_FLOAT32_C(   74.90), SIMDE_FLOAT32_C(   16.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 6175.20), SIMDE_FLOAT32_C(-1657.61),
                         SIMDE_FLOAT32_C(-5703.18), SIMDE_FLOAT32_C( 1566.15),
                         SIMDE_FLOAT32_C( 3238.57), SIMDE_FLOAT32_C(-3312.40),
                         SIMDE_FLOAT32_C(-1521.40), SIMDE_FLOAT32_C(   12.25)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -42.00), SIMDE_FLOAT32_C(  100.00),
                         SIMDE_FLOAT32_C(  -84.50), SIMDE_FLOAT32_C(   27.60),
                         SIMDE_FLOAT32_C(   27.10), SIMDE_FLOAT32_C(  -76.60),
                         SIMDE_FLOAT32_C(  -36.20), SIMDE_FLOAT32_C(   16.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   98.50), SIMDE_FLOAT32_C(  -46.90),
                         SIMDE_FLOAT32_C(  -21.70), SIMDE_FLOAT32_C(   90.80),
                         SIMDE_FLOAT32_C(   42.70), SIMDE_FLOAT32_C(   48.80),
                         SIMDE_FLOAT32_C(   91.30), SIMDE_FLOAT32_C(   90.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   74.40), SIMDE_FLOAT32_C(  -15.10),
                         SIMDE_FLOAT32_C(   42.70), SIMDE_FLOAT32_C(  -90.90),
                         SIMDE_FLOAT32_C(  -30.80), SIMDE_FLOAT32_C(   48.00),
                         SIMDE_FLOAT32_C(   12.60), SIMDE_FLOAT32_C(   59.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 4211.40), SIMDE_FLOAT32_C( 4674.90),
                         SIMDE_FLOAT32_C(-1790.95), SIMDE_FLOAT32_C(-2596.98),
                         SIMDE_FLOAT32_C(-1187.97), SIMDE_FLOAT32_C( 3786.08),
                         SIMDE_FLOAT32_C( 3317.66), SIMDE_FLOAT32_C(-1426.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -49.00), SIMDE_FLOAT32_C(   74.90),
                         SIMDE_FLOAT32_C(  -48.00), SIMDE_FLOAT32_C(   46.70),
                         SIMDE_FLOAT32_C(    4.40), SIMDE_FLOAT32_C(   44.70),
                         SIMDE_FLOAT32_C(  -68.40), SIMDE_FLOAT32_C(   74.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    8.00), SIMDE_FLOAT32_C(  -94.30),
                         SIMDE_FLOAT32_C(   -6.20), SIMDE_FLOAT32_C(  -21.50),
                         SIMDE_FLOAT32_C(   61.90), SIMDE_FLOAT32_C(   14.50),
                         SIMDE_FLOAT32_C(  -69.00), SIMDE_FLOAT32_C(  -34.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   11.20), SIMDE_FLOAT32_C(   22.30),
                         SIMDE_FLOAT32_C(  -35.00), SIMDE_FLOAT32_C(   30.60),
                         SIMDE_FLOAT32_C(   72.90), SIMDE_FLOAT32_C(   97.50),
                         SIMDE_FLOAT32_C(    2.70), SIMDE_FLOAT32_C(   72.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  403.20), SIMDE_FLOAT32_C( 7085.37),
                         SIMDE_FLOAT32_C( -332.60), SIMDE_FLOAT32_C( 1034.65),
                         SIMDE_FLOAT32_C( -199.46), SIMDE_FLOAT32_C( -550.65),
                         SIMDE_FLOAT32_C(-4716.90), SIMDE_FLOAT32_C( 2643.05)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fnmadd_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fnmadd_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   47.80), SIMDE_FLOAT64_C(  -80.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   55.10), SIMDE_FLOAT64_C(   17.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -52.00), SIMDE_FLOAT64_C(   -7.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   47.80), SIMDE_FLOAT64_C( 1388.51)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -16.50), SIMDE_FLOAT64_C(   77.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -98.70), SIMDE_FLOAT64_C(  -77.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -99.70), SIMDE_FLOAT64_C(   69.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -16.50), SIMDE_FLOAT64_C( 6099.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   40.70), SIMDE_FLOAT64_C(  -56.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -41.00), SIMDE_FLOAT64_C(  -43.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -9.90), SIMDE_FLOAT64_C(   48.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   40.70), SIMDE_FLOAT64_C(-2370.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -21.60), SIMDE_FLOAT64_C(  -51.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   91.50), SIMDE_FLOAT64_C(   24.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   83.10), SIMDE_FLOAT64_C(   15.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -21.60), SIMDE_FLOAT64_C( 1303.02)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   36.60), SIMDE_FLOAT64_C(   90.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   25.20), SIMDE_FLOAT64_C(  -17.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   21.60), SIMDE_FLOAT64_C(   29.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   36.60), SIMDE_FLOAT64_C( 1606.04)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   28.70), SIMDE_FLOAT64_C(  -13.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -49.50), SIMDE_FLOAT64_C(    1.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   78.40), SIMDE_FLOAT64_C(   70.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   28.70), SIMDE_FLOAT64_C(   95.08)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -83.30), SIMDE_FLOAT64_C(  -83.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   89.10), SIMDE_FLOAT64_C(    5.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.10), SIMDE_FLOAT64_C(   56.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -83.30), SIMDE_FLOAT64_C(  529.60)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -8.80), SIMDE_FLOAT64_C(   91.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   82.10), SIMDE_FLOAT64_C(  -69.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   92.70), SIMDE_FLOAT64_C(  -85.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -8.80), SIMDE_FLOAT64_C( 6255.45)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fnmadd_sd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fnmadd_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -92.60), SIMDE_FLOAT32_C(  -98.70), SIMDE_FLOAT32_C(   10.90), SIMDE_FLOAT32_C(  -61.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   48.20), SIMDE_FLOAT32_C(    4.60), SIMDE_FLOAT32_C(  -98.40), SIMDE_FLOAT32_C(   56.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -83.90), SIMDE_FLOAT32_C(   54.30), SIMDE_FLOAT32_C(   54.70), SIMDE_FLOAT32_C(   20.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -92.60), SIMDE_FLOAT32_C(  -98.70), SIMDE_FLOAT32_C(   10.90), SIMDE_FLOAT32_C( 3491.60)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -61.10), SIMDE_FLOAT32_C(  -33.00), SIMDE_FLOAT32_C(  -47.10), SIMDE_FLOAT32_C(   31.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   47.10), SIMDE_FLOAT32_C(  -73.50), SIMDE_FLOAT32_C(  -40.70), SIMDE_FLOAT32_C(  -95.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -73.00), SIMDE_FLOAT32_C(  -68.20), SIMDE_FLOAT32_C(   35.20), SIMDE_FLOAT32_C(   48.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -61.10), SIMDE_FLOAT32_C(  -33.00), SIMDE_FLOAT32_C(  -47.10), SIMDE_FLOAT32_C( 3053.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -17.60), SIMDE_FLOAT32_C(  -75.20), SIMDE_FLOAT32_C(  -94.50), SIMDE_FLOAT32_C(   95.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   56.20), SIMDE_FLOAT32_C(  -24.90), SIMDE_FLOAT32_C(    6.00), SIMDE_FLOAT32_C(  -33.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -8.10), SIMDE_FLOAT32_C(   95.10), SIMDE_FLOAT32_C(  -66.20), SIMDE_FLOAT32_C(   51.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -17.60), SIMDE_FLOAT32_C(  -75.20), SIMDE_FLOAT32_C(  -94.50), SIMDE_FLOAT32_C( 3222.10)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   15.40), SIMDE_FLOAT32_C(  -42.20), SIMDE_FLOAT32_C(  -38.90), SIMDE_FLOAT32_C(  -40.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -84.90), SIMDE_FLOAT32_C(  -51.00), SIMDE_FLOAT32_C(  -45.70), SIMDE_FLOAT32_C(   14.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -82.20), SIMDE_FLOAT32_C(   60.00), SIMDE_FLOAT32_C(  -19.40), SIMDE_FLOAT32_C(   90.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   15.40), SIMDE_FLOAT32_C(  -42.20), SIMDE_FLOAT32_C(  -38.90), SIMDE_FLOAT32_C(  667.54)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -29.00), SIMDE_FLOAT32_C(   45.90), SIMDE_FLOAT32_C(  -65.60), SIMDE_FLOAT32_C(   -2.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -46.90), SIMDE_FLOAT32_C(    6.70), SIMDE_FLOAT32_C(  -97.90), SIMDE_FLOAT32_C(  -72.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -7.70), SIMDE_FLOAT32_C(  -29.90), SIMDE_FLOAT32_C(   69.80), SIMDE_FLOAT32_C(  -66.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -29.00), SIMDE_FLOAT32_C(   45.90), SIMDE_FLOAT32_C(  -65.60), SIMDE_FLOAT32_C( -226.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -58.10), SIMDE_FLOAT32_C(  -47.10), SIMDE_FLOAT32_C(   68.70), SIMDE_FLOAT32_C(   33.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   40.90), SIMDE_FLOAT32_C(  -18.60), SIMDE_FLOAT32_C(  -92.90), SIMDE_FLOAT32_C(   19.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -14.90), SIMDE_FLOAT32_C(   50.40), SIMDE_FLOAT32_C(  -64.40), SIMDE_FLOAT32_C(   -4.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -58.10), SIMDE_FLOAT32_C(  -47.10), SIMDE_FLOAT32_C(   68.70), SIMDE_FLOAT32_C( -667.08)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -90.60), SIMDE_FLOAT32_C(  -45.50), SIMDE_FLOAT32_C(  -20.60), SIMDE_FLOAT32_C(  -95.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -94.80), SIMDE_FLOAT32_C(   21.50), SIMDE_FLOAT32_C(   77.40), SIMDE_FLOAT32_C(  -58.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -8.20), SIMDE_FLOAT32_C(   56.80), SIMDE_FLOAT32_C(   16.40), SIMDE_FLOAT32_C(  -52.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -90.60), SIMDE_FLOAT32_C(  -45.50), SIMDE_FLOAT32_C(  -20.60), SIMDE_FLOAT32_C(-5677.45)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   16.00), SIMDE_FLOAT32_C(  -22.20), SIMDE_FLOAT32_C(  -70.50), SIMDE_FLOAT32_C(  -57.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   86.70), SIMDE_FLOAT32_C(   31.60), SIMDE_FLOAT32_C(  -15.30), SIMDE_FLOAT32_C(  -77.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -72.10), SIMDE_FLOAT32_C(   13.20), SIMDE_FLOAT32_C(   17.70), SIMDE_FLOAT32_C(  -65.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   16.00), SIMDE_FLOAT32_C(  -22.20), SIMDE_FLOAT32_C(  -70.50), SIMDE_FLOAT32_C(-4512.02)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fnmadd_ss(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fnmsub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -85.20), SIMDE_FLOAT64_C(  -77.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   22.30), SIMDE_FLOAT64_C(   10.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   40.90), SIMDE_FLOAT64_C(   66.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 1859.06), SIMDE_FLOAT64_C(  709.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   12.10), SIMDE_FLOAT64_C(  -42.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -71.60), SIMDE_FLOAT64_C(  -43.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   73.80), SIMDE_FLOAT64_C(  -65.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  792.56), SIMDE_FLOAT64_C(-1809.03)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   47.90), SIMDE_FLOAT64_C(    8.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    4.00), SIMDE_FLOAT64_C(  -70.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -58.60), SIMDE_FLOAT64_C(  -21.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -133.00), SIMDE_FLOAT64_C(  637.26)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   70.80), SIMDE_FLOAT64_C(  -62.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   22.60), SIMDE_FLOAT64_C(  -27.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   58.00), SIMDE_FLOAT64_C(   35.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1658.08), SIMDE_FLOAT64_C(-1784.22)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C(  -26.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   10.40), SIMDE_FLOAT64_C(   -3.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -36.80), SIMDE_FLOAT64_C(  -20.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  656.64), SIMDE_FLOAT64_C(  -78.96)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   75.80), SIMDE_FLOAT64_C(  -40.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   82.60), SIMDE_FLOAT64_C(   14.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -69.00), SIMDE_FLOAT64_C(   52.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-6192.08), SIMDE_FLOAT64_C(  551.05)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -54.60), SIMDE_FLOAT64_C(    2.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   17.90), SIMDE_FLOAT64_C(   72.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   95.70), SIMDE_FLOAT64_C(   56.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  881.64), SIMDE_FLOAT64_C( -202.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   21.40), SIMDE_FLOAT64_C(   40.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.50), SIMDE_FLOAT64_C(   29.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   24.40), SIMDE_FLOAT64_C(  -57.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -933.90), SIMDE_FLOAT64_C(-1112.22)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fnmsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fnmsub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -97.30), SIMDE_FLOAT64_C(   40.60),
                         SIMDE_FLOAT64_C(  -78.70), SIMDE_FLOAT64_C(    0.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   43.40), SIMDE_FLOAT64_C(  -67.40),
                         SIMDE_FLOAT64_C(   62.50), SIMDE_FLOAT64_C(   -5.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   51.10), SIMDE_FLOAT64_C(   66.40),
                         SIMDE_FLOAT64_C(   79.40), SIMDE_FLOAT64_C(    4.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 4171.72), SIMDE_FLOAT64_C( 2670.04),
                         SIMDE_FLOAT64_C( 4839.35), SIMDE_FLOAT64_C(   -0.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -37.90), SIMDE_FLOAT64_C(  -91.10),
                         SIMDE_FLOAT64_C(   99.40), SIMDE_FLOAT64_C(  -64.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   55.70), SIMDE_FLOAT64_C(  -31.70),
                         SIMDE_FLOAT64_C(   33.10), SIMDE_FLOAT64_C(   94.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   18.80), SIMDE_FLOAT64_C(   56.10),
                         SIMDE_FLOAT64_C(  -19.80), SIMDE_FLOAT64_C(  -98.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 2092.23), SIMDE_FLOAT64_C(-2943.97),
                         SIMDE_FLOAT64_C(-3270.34), SIMDE_FLOAT64_C( 6190.28)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   44.20), SIMDE_FLOAT64_C(   98.00),
                         SIMDE_FLOAT64_C(  -20.60), SIMDE_FLOAT64_C(   99.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -36.50), SIMDE_FLOAT64_C(   37.70),
                         SIMDE_FLOAT64_C(   27.10), SIMDE_FLOAT64_C(  -85.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -54.80), SIMDE_FLOAT64_C(   46.70),
                         SIMDE_FLOAT64_C(  -59.70), SIMDE_FLOAT64_C(  -80.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1668.10), SIMDE_FLOAT64_C(-3741.30),
                         SIMDE_FLOAT64_C(  617.96), SIMDE_FLOAT64_C( 8512.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -13.40), SIMDE_FLOAT64_C(   16.00),
                         SIMDE_FLOAT64_C(  -82.10), SIMDE_FLOAT64_C(   27.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -41.30), SIMDE_FLOAT64_C(   84.40),
                         SIMDE_FLOAT64_C(  -52.10), SIMDE_FLOAT64_C(   16.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    7.30), SIMDE_FLOAT64_C(  -49.40),
                         SIMDE_FLOAT64_C(  -31.90), SIMDE_FLOAT64_C(   69.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -560.72), SIMDE_FLOAT64_C(-1301.00),
                         SIMDE_FLOAT64_C(-4245.51), SIMDE_FLOAT64_C( -524.14)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -16.80), SIMDE_FLOAT64_C(  -78.00),
                         SIMDE_FLOAT64_C(  -43.90), SIMDE_FLOAT64_C(  -53.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -11.30), SIMDE_FLOAT64_C(  -83.60),
                         SIMDE_FLOAT64_C(  -78.30), SIMDE_FLOAT64_C(   -1.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -94.20), SIMDE_FLOAT64_C(   36.20),
                         SIMDE_FLOAT64_C(   66.40), SIMDE_FLOAT64_C(   12.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -95.64), SIMDE_FLOAT64_C(-6557.00),
                         SIMDE_FLOAT64_C(-3503.77), SIMDE_FLOAT64_C(  -71.66)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   94.80), SIMDE_FLOAT64_C(   27.60),
                         SIMDE_FLOAT64_C(    5.70), SIMDE_FLOAT64_C(  -73.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   11.80), SIMDE_FLOAT64_C(  -83.40),
                         SIMDE_FLOAT64_C(   89.00), SIMDE_FLOAT64_C(   39.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   61.70), SIMDE_FLOAT64_C(   98.90),
                         SIMDE_FLOAT64_C(   -6.00), SIMDE_FLOAT64_C(  -89.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1180.34), SIMDE_FLOAT64_C( 2202.94),
                         SIMDE_FLOAT64_C( -501.30), SIMDE_FLOAT64_C( 2978.69)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -66.00), SIMDE_FLOAT64_C(  -99.10),
                         SIMDE_FLOAT64_C(  -51.20), SIMDE_FLOAT64_C(   98.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   58.10), SIMDE_FLOAT64_C(  -66.70),
                         SIMDE_FLOAT64_C(  -86.20), SIMDE_FLOAT64_C(   25.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -71.40), SIMDE_FLOAT64_C(   40.80),
                         SIMDE_FLOAT64_C(  -71.40), SIMDE_FLOAT64_C(    8.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 3906.00), SIMDE_FLOAT64_C(-6650.77),
                         SIMDE_FLOAT64_C(-4342.04), SIMDE_FLOAT64_C(-2493.36)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   63.90), SIMDE_FLOAT64_C(    7.50),
                         SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(  -97.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -39.10), SIMDE_FLOAT64_C(  -73.10),
                         SIMDE_FLOAT64_C(  -53.20), SIMDE_FLOAT64_C(   81.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -32.20), SIMDE_FLOAT64_C(   71.70),
                         SIMDE_FLOAT64_C(   39.30), SIMDE_FLOAT64_C(  -11.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 2530.69), SIMDE_FLOAT64_C(  476.55),
                         SIMDE_FLOAT64_C(  -39.30), SIMDE_FLOAT64_C( 7961.08)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fnmsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fnmsub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   18.60), SIMDE_FLOAT32_C(  -96.60), SIMDE_FLOAT32_C(  -17.10), SIMDE_FLOAT32_C(  -50.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    3.20), SIMDE_FLOAT32_C(  -15.90), SIMDE_FLOAT32_C(   83.80), SIMDE_FLOAT32_C(  -57.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -50.90), SIMDE_FLOAT32_C(  -53.70), SIMDE_FLOAT32_C(   66.30), SIMDE_FLOAT32_C(   53.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -8.62), SIMDE_FLOAT32_C(-1482.24), SIMDE_FLOAT32_C( 1366.68), SIMDE_FLOAT32_C(-2967.35)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   19.40), SIMDE_FLOAT32_C(   81.00), SIMDE_FLOAT32_C(    0.70), SIMDE_FLOAT32_C(   26.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -29.00), SIMDE_FLOAT32_C(   15.30), SIMDE_FLOAT32_C(  -89.70), SIMDE_FLOAT32_C(  -71.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   61.60), SIMDE_FLOAT32_C(  -84.00), SIMDE_FLOAT32_C(  -77.60), SIMDE_FLOAT32_C(   49.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  501.00), SIMDE_FLOAT32_C(-1155.30), SIMDE_FLOAT32_C(  140.39), SIMDE_FLOAT32_C( 1831.86)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   10.90), SIMDE_FLOAT32_C(  -73.80), SIMDE_FLOAT32_C(  -37.10), SIMDE_FLOAT32_C(   92.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   27.80), SIMDE_FLOAT32_C(   31.90), SIMDE_FLOAT32_C(  -77.70), SIMDE_FLOAT32_C(  -29.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   72.70), SIMDE_FLOAT32_C(   50.20), SIMDE_FLOAT32_C(  -64.40), SIMDE_FLOAT32_C(   81.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -375.72), SIMDE_FLOAT32_C( 2304.02), SIMDE_FLOAT32_C(-2818.27), SIMDE_FLOAT32_C( 2668.64)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   -2.50), SIMDE_FLOAT32_C(  -77.00), SIMDE_FLOAT32_C(  -97.10), SIMDE_FLOAT32_C(   -6.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    1.40), SIMDE_FLOAT32_C(   38.10), SIMDE_FLOAT32_C(   96.80), SIMDE_FLOAT32_C(  -90.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -31.70), SIMDE_FLOAT32_C(  -86.40), SIMDE_FLOAT32_C(  -62.20), SIMDE_FLOAT32_C(  -64.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   35.20), SIMDE_FLOAT32_C( 3020.10), SIMDE_FLOAT32_C( 9461.48), SIMDE_FLOAT32_C( -495.78)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -29.50), SIMDE_FLOAT32_C(  -45.60), SIMDE_FLOAT32_C(  -87.90), SIMDE_FLOAT32_C(  -82.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -16.40), SIMDE_FLOAT32_C(  -50.10), SIMDE_FLOAT32_C(  -30.70), SIMDE_FLOAT32_C(  -73.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   49.20), SIMDE_FLOAT32_C(   55.00), SIMDE_FLOAT32_C(   57.30), SIMDE_FLOAT32_C(  -33.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -533.00), SIMDE_FLOAT32_C(-2339.56), SIMDE_FLOAT32_C(-2755.83), SIMDE_FLOAT32_C(-6001.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -90.10), SIMDE_FLOAT32_C(   83.90), SIMDE_FLOAT32_C(  -87.40), SIMDE_FLOAT32_C(  -87.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -1.40), SIMDE_FLOAT32_C(  -10.10), SIMDE_FLOAT32_C(   29.30), SIMDE_FLOAT32_C(  -74.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -21.90), SIMDE_FLOAT32_C(   46.80), SIMDE_FLOAT32_C(  -76.50), SIMDE_FLOAT32_C(  -94.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -104.24), SIMDE_FLOAT32_C(  800.59), SIMDE_FLOAT32_C( 2637.32), SIMDE_FLOAT32_C(-6435.64)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -29.30), SIMDE_FLOAT32_C(  -94.30), SIMDE_FLOAT32_C(   -8.20), SIMDE_FLOAT32_C(  -67.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -39.50), SIMDE_FLOAT32_C(   47.60), SIMDE_FLOAT32_C(   50.70), SIMDE_FLOAT32_C(   19.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    2.50), SIMDE_FLOAT32_C(   40.50), SIMDE_FLOAT32_C(  -73.30), SIMDE_FLOAT32_C(    7.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-1159.85), SIMDE_FLOAT32_C( 4448.18), SIMDE_FLOAT32_C(  489.04), SIMDE_FLOAT32_C( 1309.86)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   15.30), SIMDE_FLOAT32_C(   14.60), SIMDE_FLOAT32_C(  -68.80), SIMDE_FLOAT32_C(   92.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -34.50), SIMDE_FLOAT32_C(   77.40), SIMDE_FLOAT32_C(   73.70), SIMDE_FLOAT32_C(  -25.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -70.20), SIMDE_FLOAT32_C(   -4.40), SIMDE_FLOAT32_C(  -93.70), SIMDE_FLOAT32_C(   16.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  598.05), SIMDE_FLOAT32_C(-1125.64), SIMDE_FLOAT32_C( 5164.26), SIMDE_FLOAT32_C( 2312.98)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fnmsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm256_fnmsub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -91.80), SIMDE_FLOAT32_C(  -53.10),
                         SIMDE_FLOAT32_C(  -79.10), SIMDE_FLOAT32_C(   50.50),
                         SIMDE_FLOAT32_C(  -81.20), SIMDE_FLOAT32_C(  -11.90),
                         SIMDE_FLOAT32_C(  -72.60), SIMDE_FLOAT32_C(   13.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   11.90), SIMDE_FLOAT32_C(   -8.00),
                         SIMDE_FLOAT32_C(   73.10), SIMDE_FLOAT32_C(   73.00),
                         SIMDE_FLOAT32_C(  -15.70), SIMDE_FLOAT32_C(   33.70),
                         SIMDE_FLOAT32_C(  -36.30), SIMDE_FLOAT32_C(  -25.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -90.00), SIMDE_FLOAT32_C(  -13.00),
                         SIMDE_FLOAT32_C(  -28.10), SIMDE_FLOAT32_C(  -49.40),
                         SIMDE_FLOAT32_C(  -74.60), SIMDE_FLOAT32_C(  -32.00),
                         SIMDE_FLOAT32_C(  -63.50), SIMDE_FLOAT32_C(  -18.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 1182.42), SIMDE_FLOAT32_C( -411.80),
                         SIMDE_FLOAT32_C( 5810.31), SIMDE_FLOAT32_C(-3637.10),
                         SIMDE_FLOAT32_C(-1200.24), SIMDE_FLOAT32_C(  433.03),
                         SIMDE_FLOAT32_C(-2571.88), SIMDE_FLOAT32_C(  369.78)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -57.30), SIMDE_FLOAT32_C(   71.50),
                         SIMDE_FLOAT32_C(   39.90), SIMDE_FLOAT32_C(  -77.10),
                         SIMDE_FLOAT32_C(   -9.90), SIMDE_FLOAT32_C(  -16.00),
                         SIMDE_FLOAT32_C(   74.80), SIMDE_FLOAT32_C(   77.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -53.60), SIMDE_FLOAT32_C(   49.60),
                         SIMDE_FLOAT32_C(   94.20), SIMDE_FLOAT32_C(    1.20),
                         SIMDE_FLOAT32_C(  -56.30), SIMDE_FLOAT32_C(   26.10),
                         SIMDE_FLOAT32_C(  -23.40), SIMDE_FLOAT32_C(  -47.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   82.40), SIMDE_FLOAT32_C(  -13.50),
                         SIMDE_FLOAT32_C(  -97.40), SIMDE_FLOAT32_C(   84.50),
                         SIMDE_FLOAT32_C(  -48.30), SIMDE_FLOAT32_C(   98.50),
                         SIMDE_FLOAT32_C(  -91.50), SIMDE_FLOAT32_C(   24.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-3153.68), SIMDE_FLOAT32_C(-3532.90),
                         SIMDE_FLOAT32_C(-3661.18), SIMDE_FLOAT32_C(    8.02),
                         SIMDE_FLOAT32_C( -509.07), SIMDE_FLOAT32_C(  319.10),
                         SIMDE_FLOAT32_C( 1841.82), SIMDE_FLOAT32_C( 3613.20)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   11.60), SIMDE_FLOAT32_C(   59.90),
                         SIMDE_FLOAT32_C(   -3.20), SIMDE_FLOAT32_C(    4.40),
                         SIMDE_FLOAT32_C(  -98.80), SIMDE_FLOAT32_C(   29.00),
                         SIMDE_FLOAT32_C(  -86.20), SIMDE_FLOAT32_C(   19.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   63.60), SIMDE_FLOAT32_C(  -94.60),
                         SIMDE_FLOAT32_C(  -81.40), SIMDE_FLOAT32_C(    9.90),
                         SIMDE_FLOAT32_C(  -69.00), SIMDE_FLOAT32_C(  -83.90),
                         SIMDE_FLOAT32_C(   22.00), SIMDE_FLOAT32_C(  -56.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   80.90), SIMDE_FLOAT32_C(   -7.90),
                         SIMDE_FLOAT32_C(  -92.10), SIMDE_FLOAT32_C(   65.40),
                         SIMDE_FLOAT32_C(  -26.30), SIMDE_FLOAT32_C(  -26.90),
                         SIMDE_FLOAT32_C(  -44.20), SIMDE_FLOAT32_C(  -39.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -818.66), SIMDE_FLOAT32_C( 5674.44),
                         SIMDE_FLOAT32_C( -168.38), SIMDE_FLOAT32_C( -108.96),
                         SIMDE_FLOAT32_C(-6790.90), SIMDE_FLOAT32_C( 2460.00),
                         SIMDE_FLOAT32_C( 1940.60), SIMDE_FLOAT32_C( 1137.45)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -73.70), SIMDE_FLOAT32_C(  -39.20),
                         SIMDE_FLOAT32_C(   40.90), SIMDE_FLOAT32_C(    0.60),
                         SIMDE_FLOAT32_C(  -64.50), SIMDE_FLOAT32_C(   35.70),
                         SIMDE_FLOAT32_C(  -58.10), SIMDE_FLOAT32_C(  -23.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   98.30), SIMDE_FLOAT32_C(   77.60),
                         SIMDE_FLOAT32_C(   33.80), SIMDE_FLOAT32_C(   94.20),
                         SIMDE_FLOAT32_C(    8.60), SIMDE_FLOAT32_C(  -96.70),
                         SIMDE_FLOAT32_C(  -22.70), SIMDE_FLOAT32_C(  -38.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -52.20), SIMDE_FLOAT32_C(  -35.80),
                         SIMDE_FLOAT32_C(   76.20), SIMDE_FLOAT32_C(  -32.30),
                         SIMDE_FLOAT32_C(  -84.60), SIMDE_FLOAT32_C(   76.00),
                         SIMDE_FLOAT32_C(  -84.30), SIMDE_FLOAT32_C(   87.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 7296.91), SIMDE_FLOAT32_C( 3077.72),
                         SIMDE_FLOAT32_C(-1458.62), SIMDE_FLOAT32_C(  -24.22),
                         SIMDE_FLOAT32_C(  639.30), SIMDE_FLOAT32_C( 3376.19),
                         SIMDE_FLOAT32_C(-1234.57), SIMDE_FLOAT32_C( -992.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -10.70), SIMDE_FLOAT32_C(   52.50),
                         SIMDE_FLOAT32_C(   95.50), SIMDE_FLOAT32_C(  -35.90),
                         SIMDE_FLOAT32_C(  -55.60), SIMDE_FLOAT32_C(    1.10),
                         SIMDE_FLOAT32_C(  -20.80), SIMDE_FLOAT32_C(  -55.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -20.50), SIMDE_FLOAT32_C(   25.80),
                         SIMDE_FLOAT32_C(   85.10), SIMDE_FLOAT32_C(  -30.10),
                         SIMDE_FLOAT32_C(   98.50), SIMDE_FLOAT32_C(  -42.90),
                         SIMDE_FLOAT32_C(   14.30), SIMDE_FLOAT32_C(   52.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   81.70), SIMDE_FLOAT32_C(   21.40),
                         SIMDE_FLOAT32_C(   41.10), SIMDE_FLOAT32_C(   65.30),
                         SIMDE_FLOAT32_C(  -66.60), SIMDE_FLOAT32_C(    6.20),
                         SIMDE_FLOAT32_C(   29.60), SIMDE_FLOAT32_C(   47.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -301.05), SIMDE_FLOAT32_C(-1375.90),
                         SIMDE_FLOAT32_C(-8168.15), SIMDE_FLOAT32_C(-1145.89),
                         SIMDE_FLOAT32_C( 5543.20), SIMDE_FLOAT32_C(   40.99),
                         SIMDE_FLOAT32_C(  267.84), SIMDE_FLOAT32_C( 2872.10)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -94.70), SIMDE_FLOAT32_C(   14.30),
                         SIMDE_FLOAT32_C(   36.30), SIMDE_FLOAT32_C(  -95.40),
                         SIMDE_FLOAT32_C(  -85.70), SIMDE_FLOAT32_C(   15.60),
                         SIMDE_FLOAT32_C(  -45.20), SIMDE_FLOAT32_C(  -87.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -75.50), SIMDE_FLOAT32_C(   52.00),
                         SIMDE_FLOAT32_C(   88.60), SIMDE_FLOAT32_C(  -12.10),
                         SIMDE_FLOAT32_C(  -27.40), SIMDE_FLOAT32_C(   41.00),
                         SIMDE_FLOAT32_C(  -70.80), SIMDE_FLOAT32_C(   22.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -14.10), SIMDE_FLOAT32_C(  -90.60),
                         SIMDE_FLOAT32_C(   84.80), SIMDE_FLOAT32_C(  -47.50),
                         SIMDE_FLOAT32_C(  -49.90), SIMDE_FLOAT32_C(   72.50),
                         SIMDE_FLOAT32_C(   90.90), SIMDE_FLOAT32_C(  -74.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-7135.75), SIMDE_FLOAT32_C( -653.00),
                         SIMDE_FLOAT32_C(-3300.98), SIMDE_FLOAT32_C(-1106.84),
                         SIMDE_FLOAT32_C(-2298.28), SIMDE_FLOAT32_C( -712.10),
                         SIMDE_FLOAT32_C(-3291.06), SIMDE_FLOAT32_C( 2052.10)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -59.20), SIMDE_FLOAT32_C(  -79.60),
                         SIMDE_FLOAT32_C(   47.00), SIMDE_FLOAT32_C(  -96.90),
                         SIMDE_FLOAT32_C(  -44.60), SIMDE_FLOAT32_C(   50.20),
                         SIMDE_FLOAT32_C(   10.60), SIMDE_FLOAT32_C(  -70.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -68.90), SIMDE_FLOAT32_C(   37.70),
                         SIMDE_FLOAT32_C(   58.60), SIMDE_FLOAT32_C(  -25.80),
                         SIMDE_FLOAT32_C(   57.80), SIMDE_FLOAT32_C(  -89.20),
                         SIMDE_FLOAT32_C(   27.50), SIMDE_FLOAT32_C(   46.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   61.30), SIMDE_FLOAT32_C(  -66.60),
                         SIMDE_FLOAT32_C(   75.60), SIMDE_FLOAT32_C(   -6.00),
                         SIMDE_FLOAT32_C(  -95.90), SIMDE_FLOAT32_C(   11.80),
                         SIMDE_FLOAT32_C(   59.10), SIMDE_FLOAT32_C(   34.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-4140.18), SIMDE_FLOAT32_C( 3067.52),
                         SIMDE_FLOAT32_C(-2829.80), SIMDE_FLOAT32_C(-2494.02),
                         SIMDE_FLOAT32_C( 2673.78), SIMDE_FLOAT32_C( 4466.04),
                         SIMDE_FLOAT32_C( -350.60), SIMDE_FLOAT32_C( 3264.38)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -53.00), SIMDE_FLOAT32_C(  -46.10),
                         SIMDE_FLOAT32_C(   53.90), SIMDE_FLOAT32_C(   19.20),
                         SIMDE_FLOAT32_C(  -73.10), SIMDE_FLOAT32_C(   23.40),
                         SIMDE_FLOAT32_C(   67.90), SIMDE_FLOAT32_C(  -74.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -80.10), SIMDE_FLOAT32_C(   56.30),
                         SIMDE_FLOAT32_C(  -45.20), SIMDE_FLOAT32_C(   32.20),
                         SIMDE_FLOAT32_C(  -17.90), SIMDE_FLOAT32_C(  -44.50),
                         SIMDE_FLOAT32_C(   62.10), SIMDE_FLOAT32_C(    8.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   30.70), SIMDE_FLOAT32_C(   11.70),
                         SIMDE_FLOAT32_C(  -61.10), SIMDE_FLOAT32_C(   76.30),
                         SIMDE_FLOAT32_C(   57.20), SIMDE_FLOAT32_C(   36.40),
                         SIMDE_FLOAT32_C(   67.50), SIMDE_FLOAT32_C(    2.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-4276.00), SIMDE_FLOAT32_C( 2583.73),
                         SIMDE_FLOAT32_C( 2497.38), SIMDE_FLOAT32_C( -694.54),
                         SIMDE_FLOAT32_C(-1365.69), SIMDE_FLOAT32_C( 1004.90),
                         SIMDE_FLOAT32_C(-4284.09), SIMDE_FLOAT32_C(  593.10)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fnmsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fnmsub_sd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -60.10), SIMDE_FLOAT64_C(  -84.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -22.80), SIMDE_FLOAT64_C(   63.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   81.10), SIMDE_FLOAT64_C(  -77.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -60.10), SIMDE_FLOAT64_C( 5386.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   37.60), SIMDE_FLOAT64_C(   78.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.00), SIMDE_FLOAT64_C(   53.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -88.70), SIMDE_FLOAT64_C(   54.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   37.60), SIMDE_FLOAT64_C(-4283.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -38.20), SIMDE_FLOAT64_C(   72.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -86.10), SIMDE_FLOAT64_C(   25.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -52.90), SIMDE_FLOAT64_C(  -86.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -38.20), SIMDE_FLOAT64_C(-1752.25)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    7.50), SIMDE_FLOAT64_C(   35.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    5.30), SIMDE_FLOAT64_C(   97.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -49.40), SIMDE_FLOAT64_C(  -58.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    7.50), SIMDE_FLOAT64_C(-3336.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   41.40), SIMDE_FLOAT64_C(  -46.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -70.70), SIMDE_FLOAT64_C(  -78.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   77.70), SIMDE_FLOAT64_C(  -33.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   41.40), SIMDE_FLOAT64_C(-3629.69)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -63.30), SIMDE_FLOAT64_C(  -78.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   58.80), SIMDE_FLOAT64_C(   11.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -18.00), SIMDE_FLOAT64_C(  -49.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -63.30), SIMDE_FLOAT64_C(  950.90)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -80.50), SIMDE_FLOAT64_C(   28.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -48.00), SIMDE_FLOAT64_C(   38.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -73.40), SIMDE_FLOAT64_C(  -29.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -80.50), SIMDE_FLOAT64_C(-1056.85)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   42.80), SIMDE_FLOAT64_C(  -10.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    8.60), SIMDE_FLOAT64_C(  -39.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -25.50), SIMDE_FLOAT64_C(   42.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.80), SIMDE_FLOAT64_C( -473.74)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fnmsub_sd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_fnmsub_ss(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   17.30), SIMDE_FLOAT32_C(   17.40), SIMDE_FLOAT32_C(   41.70), SIMDE_FLOAT32_C(   37.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   61.00), SIMDE_FLOAT32_C(   15.10), SIMDE_FLOAT32_C(    2.00), SIMDE_FLOAT32_C(   43.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   28.00), SIMDE_FLOAT32_C(   83.70), SIMDE_FLOAT32_C(   43.30), SIMDE_FLOAT32_C(  -38.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   17.30), SIMDE_FLOAT32_C(   17.40), SIMDE_FLOAT32_C(   41.70), SIMDE_FLOAT32_C(-1563.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.00), SIMDE_FLOAT32_C(  -28.20), SIMDE_FLOAT32_C(   12.60), SIMDE_FLOAT32_C(  -73.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    5.90), SIMDE_FLOAT32_C(   68.10), SIMDE_FLOAT32_C(   57.10), SIMDE_FLOAT32_C(   23.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   17.40), SIMDE_FLOAT32_C(   89.40), SIMDE_FLOAT32_C(   38.60), SIMDE_FLOAT32_C(  -36.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.00), SIMDE_FLOAT32_C(  -28.20), SIMDE_FLOAT32_C(   12.60), SIMDE_FLOAT32_C( 1785.80)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   35.60), SIMDE_FLOAT32_C(  -64.00), SIMDE_FLOAT32_C(   95.10), SIMDE_FLOAT32_C(  -83.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   90.40), SIMDE_FLOAT32_C(   58.10), SIMDE_FLOAT32_C(   -8.40), SIMDE_FLOAT32_C(  -87.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   26.50), SIMDE_FLOAT32_C(  -91.50), SIMDE_FLOAT32_C(   38.20), SIMDE_FLOAT32_C(   39.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   35.60), SIMDE_FLOAT32_C(  -64.00), SIMDE_FLOAT32_C(   95.10), SIMDE_FLOAT32_C(-7370.06)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   26.00), SIMDE_FLOAT32_C(   35.10), SIMDE_FLOAT32_C(   90.70), SIMDE_FLOAT32_C(  -77.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -18.70), SIMDE_FLOAT32_C(   97.20), SIMDE_FLOAT32_C(  -13.90), SIMDE_FLOAT32_C(    3.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -66.00), SIMDE_FLOAT32_C(  -38.90), SIMDE_FLOAT32_C(   92.90), SIMDE_FLOAT32_C(   44.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   26.00), SIMDE_FLOAT32_C(   35.10), SIMDE_FLOAT32_C(   90.70), SIMDE_FLOAT32_C(  233.72)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   63.90), SIMDE_FLOAT32_C(  -84.10), SIMDE_FLOAT32_C(   20.70), SIMDE_FLOAT32_C(  -87.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    2.30), SIMDE_FLOAT32_C(  -39.50), SIMDE_FLOAT32_C(  -17.30), SIMDE_FLOAT32_C(  -98.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -59.10), SIMDE_FLOAT32_C(  -12.50), SIMDE_FLOAT32_C(   12.60), SIMDE_FLOAT32_C(   34.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   63.90), SIMDE_FLOAT32_C(  -84.10), SIMDE_FLOAT32_C(   20.70), SIMDE_FLOAT32_C(-8613.10)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.30), SIMDE_FLOAT32_C(  -17.50), SIMDE_FLOAT32_C(  -37.30), SIMDE_FLOAT32_C(   -7.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   85.10), SIMDE_FLOAT32_C(  -93.00), SIMDE_FLOAT32_C(   -6.70), SIMDE_FLOAT32_C(   16.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   17.50), SIMDE_FLOAT32_C(  -83.60), SIMDE_FLOAT32_C(   98.60), SIMDE_FLOAT32_C(  -20.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.30), SIMDE_FLOAT32_C(  -17.50), SIMDE_FLOAT32_C(  -37.30), SIMDE_FLOAT32_C(  146.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -98.40), SIMDE_FLOAT32_C(   46.60), SIMDE_FLOAT32_C(  -57.20), SIMDE_FLOAT32_C(  -62.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   23.90), SIMDE_FLOAT32_C(   59.10), SIMDE_FLOAT32_C(   62.20), SIMDE_FLOAT32_C(   48.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -80.80), SIMDE_FLOAT32_C(  -51.00), SIMDE_FLOAT32_C(   63.40), SIMDE_FLOAT32_C(   30.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -98.40), SIMDE_FLOAT32_C(   46.60), SIMDE_FLOAT32_C(  -57.20), SIMDE_FLOAT32_C( 3017.12)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -52.30), SIMDE_FLOAT32_C(   90.80), SIMDE_FLOAT32_C(   10.20), SIMDE_FLOAT32_C(   40.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   25.10), SIMDE_FLOAT32_C(   -1.00), SIMDE_FLOAT32_C(   38.80), SIMDE_FLOAT32_C(    1.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -21.30), SIMDE_FLOAT32_C(  -30.30), SIMDE_FLOAT32_C(   80.90), SIMDE_FLOAT32_C(  -98.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -52.30), SIMDE_FLOAT32_C(   90.80), SIMDE_FLOAT32_C(   10.20), SIMDE_FLOAT32_C(   36.90)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fnmsub_ss(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmadd_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fmadd_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmadd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fmadd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmadd_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmadd_ss)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmaddsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fmaddsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmaddsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fmaddsub_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmsub_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmsub_ss)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmsubadd_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fmsubadd_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fmsubadd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fmsubadd_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fnmadd_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fnmadd_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fnmadd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fnmadd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fnmadd_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fnmadd_ss)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fnmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fnmsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fnmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fnmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fnmsub_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fnmsub_ss)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
