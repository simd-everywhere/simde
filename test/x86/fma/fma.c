/* Copyright (c) 2018, 2019 Evan Nemerson <evan@nemerson.com>
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

#include "../x86-internal.h"
#include "../../../simde/x86/fma.h"

static MunitResult
test_simde_mm_fmadd_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_fmadd_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmadd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_fmadd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm_fmadd_pd),
  TEST_FUNC(mm256_fmadd_pd),
  TEST_FUNC(mm_fmadd_ps),
  TEST_FUNC(mm256_fmadd_ps),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_fma_test_suite simde_fma_emul_test_suite
#endif

MunitSuite simde_fma_test_suite = {
  (char*) "/fma",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
