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

#define SIMDE_TESTS_CURRENT_ISAX avx512f
#include <simde/x86/avx512f.h>
#include <test/x86/test-avx512.h>

#if defined(SIMDE_AVX512F_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm512_castpd512_pd128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -503.58), SIMDE_FLOAT64_C(  409.99),
                         SIMDE_FLOAT64_C(  882.79), SIMDE_FLOAT64_C(  967.41),
                         SIMDE_FLOAT64_C(  644.16), SIMDE_FLOAT64_C(   22.93),
                         SIMDE_FLOAT64_C(  629.49), SIMDE_FLOAT64_C(  -19.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  629.49), SIMDE_FLOAT64_C(  -19.16)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -371.76), SIMDE_FLOAT64_C( -903.70),
                         SIMDE_FLOAT64_C( -183.89), SIMDE_FLOAT64_C(   -1.20),
                         SIMDE_FLOAT64_C(  -62.86), SIMDE_FLOAT64_C(  444.19),
                         SIMDE_FLOAT64_C(  672.79), SIMDE_FLOAT64_C(  471.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  672.79), SIMDE_FLOAT64_C(  471.18)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -771.58), SIMDE_FLOAT64_C(  494.03),
                         SIMDE_FLOAT64_C(  138.84), SIMDE_FLOAT64_C( -195.59),
                         SIMDE_FLOAT64_C( -760.58), SIMDE_FLOAT64_C( -773.64),
                         SIMDE_FLOAT64_C(  870.25), SIMDE_FLOAT64_C(  314.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  870.25), SIMDE_FLOAT64_C(  314.25)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   -2.05), SIMDE_FLOAT64_C( -418.62),
                         SIMDE_FLOAT64_C( -507.96), SIMDE_FLOAT64_C( -261.33),
                         SIMDE_FLOAT64_C( -683.39), SIMDE_FLOAT64_C(  -27.96),
                         SIMDE_FLOAT64_C(  534.55), SIMDE_FLOAT64_C(  185.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  534.55), SIMDE_FLOAT64_C(  185.44)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  596.68), SIMDE_FLOAT64_C( -902.04),
                         SIMDE_FLOAT64_C(  847.76), SIMDE_FLOAT64_C(  134.78),
                         SIMDE_FLOAT64_C(  116.62), SIMDE_FLOAT64_C(    7.30),
                         SIMDE_FLOAT64_C(  382.57), SIMDE_FLOAT64_C(  434.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  382.57), SIMDE_FLOAT64_C(  434.75)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  688.01), SIMDE_FLOAT64_C(  829.27),
                         SIMDE_FLOAT64_C( -970.03), SIMDE_FLOAT64_C(  528.04),
                         SIMDE_FLOAT64_C( -386.08), SIMDE_FLOAT64_C(  603.97),
                         SIMDE_FLOAT64_C( -132.68), SIMDE_FLOAT64_C(  463.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -132.68), SIMDE_FLOAT64_C(  463.66)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  235.78), SIMDE_FLOAT64_C( -244.37),
                         SIMDE_FLOAT64_C(  846.69), SIMDE_FLOAT64_C(  794.12),
                         SIMDE_FLOAT64_C(  672.11), SIMDE_FLOAT64_C( -445.78),
                         SIMDE_FLOAT64_C(  396.01), SIMDE_FLOAT64_C( -284.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  396.01), SIMDE_FLOAT64_C( -284.10)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  603.46), SIMDE_FLOAT64_C( -988.15),
                         SIMDE_FLOAT64_C( -342.31), SIMDE_FLOAT64_C( -282.11),
                         SIMDE_FLOAT64_C(  379.72), SIMDE_FLOAT64_C( -680.63),
                         SIMDE_FLOAT64_C( -541.51), SIMDE_FLOAT64_C(  -40.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -541.51), SIMDE_FLOAT64_C(  -40.90)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm512_castpd512_pd128(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_castpd512_pd256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  414.39), SIMDE_FLOAT64_C(  -15.63),
                         SIMDE_FLOAT64_C(  546.05), SIMDE_FLOAT64_C( -960.01),
                         SIMDE_FLOAT64_C( -752.11), SIMDE_FLOAT64_C( -702.83),
                         SIMDE_FLOAT64_C( -642.16), SIMDE_FLOAT64_C(  617.65)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -752.11), SIMDE_FLOAT64_C( -702.83),
                         SIMDE_FLOAT64_C( -642.16), SIMDE_FLOAT64_C(  617.65)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -964.21), SIMDE_FLOAT64_C( -388.73),
                         SIMDE_FLOAT64_C(  322.52), SIMDE_FLOAT64_C(  699.65),
                         SIMDE_FLOAT64_C(  390.02), SIMDE_FLOAT64_C( -490.64),
                         SIMDE_FLOAT64_C( -297.41), SIMDE_FLOAT64_C(  563.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  390.02), SIMDE_FLOAT64_C( -490.64),
                         SIMDE_FLOAT64_C( -297.41), SIMDE_FLOAT64_C(  563.23)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  920.55), SIMDE_FLOAT64_C(   39.56),
                         SIMDE_FLOAT64_C(  750.72), SIMDE_FLOAT64_C(  440.72),
                         SIMDE_FLOAT64_C( -246.45), SIMDE_FLOAT64_C(  981.88),
                         SIMDE_FLOAT64_C( -299.81), SIMDE_FLOAT64_C(  -98.82)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -246.45), SIMDE_FLOAT64_C(  981.88),
                         SIMDE_FLOAT64_C( -299.81), SIMDE_FLOAT64_C(  -98.82)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -471.70), SIMDE_FLOAT64_C( -359.51),
                         SIMDE_FLOAT64_C(  724.77), SIMDE_FLOAT64_C( -820.10),
                         SIMDE_FLOAT64_C(  777.44), SIMDE_FLOAT64_C( -220.31),
                         SIMDE_FLOAT64_C(  567.27), SIMDE_FLOAT64_C(  977.08)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  777.44), SIMDE_FLOAT64_C( -220.31),
                         SIMDE_FLOAT64_C(  567.27), SIMDE_FLOAT64_C(  977.08)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  438.55), SIMDE_FLOAT64_C( -230.11),
                         SIMDE_FLOAT64_C(  759.60), SIMDE_FLOAT64_C(  615.37),
                         SIMDE_FLOAT64_C( -356.18), SIMDE_FLOAT64_C(  777.70),
                         SIMDE_FLOAT64_C( -385.32), SIMDE_FLOAT64_C( -478.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -356.18), SIMDE_FLOAT64_C(  777.70),
                         SIMDE_FLOAT64_C( -385.32), SIMDE_FLOAT64_C( -478.17)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -337.84), SIMDE_FLOAT64_C( -274.76),
                         SIMDE_FLOAT64_C(  865.32), SIMDE_FLOAT64_C( -257.44),
                         SIMDE_FLOAT64_C(  325.76), SIMDE_FLOAT64_C(  -67.76),
                         SIMDE_FLOAT64_C( -238.87), SIMDE_FLOAT64_C( -384.04)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  325.76), SIMDE_FLOAT64_C(  -67.76),
                         SIMDE_FLOAT64_C( -238.87), SIMDE_FLOAT64_C( -384.04)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  120.04), SIMDE_FLOAT64_C(  416.14),
                         SIMDE_FLOAT64_C(  299.72), SIMDE_FLOAT64_C(  991.84),
                         SIMDE_FLOAT64_C(  325.55), SIMDE_FLOAT64_C(  685.94),
                         SIMDE_FLOAT64_C( -182.11), SIMDE_FLOAT64_C(  943.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  325.55), SIMDE_FLOAT64_C(  685.94),
                         SIMDE_FLOAT64_C( -182.11), SIMDE_FLOAT64_C(  943.15)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  556.40), SIMDE_FLOAT64_C( -775.19),
                         SIMDE_FLOAT64_C( -814.91), SIMDE_FLOAT64_C(   73.06),
                         SIMDE_FLOAT64_C(  317.95), SIMDE_FLOAT64_C( -552.86),
                         SIMDE_FLOAT64_C( -767.41), SIMDE_FLOAT64_C(  130.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  317.95), SIMDE_FLOAT64_C( -552.86),
                         SIMDE_FLOAT64_C( -767.41), SIMDE_FLOAT64_C(  130.66)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm512_castpd512_pd256(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_castps512_ps128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   764.32), SIMDE_FLOAT32_C(  -951.31), SIMDE_FLOAT32_C(   179.06), SIMDE_FLOAT32_C(  -437.66),
                         SIMDE_FLOAT32_C(   402.64), SIMDE_FLOAT32_C(   734.29), SIMDE_FLOAT32_C(   267.34), SIMDE_FLOAT32_C(   208.00),
                         SIMDE_FLOAT32_C(   587.55), SIMDE_FLOAT32_C(  -635.96), SIMDE_FLOAT32_C(  -958.84), SIMDE_FLOAT32_C(  -271.31),
                         SIMDE_FLOAT32_C(   711.90), SIMDE_FLOAT32_C(   959.36), SIMDE_FLOAT32_C(   988.07), SIMDE_FLOAT32_C(  -648.23)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   711.90), SIMDE_FLOAT32_C(   959.36), SIMDE_FLOAT32_C(   988.07), SIMDE_FLOAT32_C(  -648.23)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   193.72), SIMDE_FLOAT32_C(  -347.47), SIMDE_FLOAT32_C(   437.71), SIMDE_FLOAT32_C(  -756.77),
                         SIMDE_FLOAT32_C(  -591.14), SIMDE_FLOAT32_C(  -431.84), SIMDE_FLOAT32_C(  -564.12), SIMDE_FLOAT32_C(   252.26),
                         SIMDE_FLOAT32_C(  -784.50), SIMDE_FLOAT32_C(   149.30), SIMDE_FLOAT32_C(  -246.02), SIMDE_FLOAT32_C(   -60.58),
                         SIMDE_FLOAT32_C(   384.90), SIMDE_FLOAT32_C(   156.04), SIMDE_FLOAT32_C(  -595.88), SIMDE_FLOAT32_C(  -574.45)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   384.90), SIMDE_FLOAT32_C(   156.04), SIMDE_FLOAT32_C(  -595.88), SIMDE_FLOAT32_C(  -574.45)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -425.80), SIMDE_FLOAT32_C(   886.22), SIMDE_FLOAT32_C(  -478.46), SIMDE_FLOAT32_C(  -993.15),
                         SIMDE_FLOAT32_C(  -912.29), SIMDE_FLOAT32_C(  -564.52), SIMDE_FLOAT32_C(   -25.07), SIMDE_FLOAT32_C(  -469.67),
                         SIMDE_FLOAT32_C(   828.84), SIMDE_FLOAT32_C(  -525.49), SIMDE_FLOAT32_C(  -521.07), SIMDE_FLOAT32_C(   132.36),
                         SIMDE_FLOAT32_C(   368.34), SIMDE_FLOAT32_C(   996.83), SIMDE_FLOAT32_C(   514.03), SIMDE_FLOAT32_C(   350.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   368.34), SIMDE_FLOAT32_C(   996.83), SIMDE_FLOAT32_C(   514.03), SIMDE_FLOAT32_C(   350.58)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -806.26), SIMDE_FLOAT32_C(  -958.10), SIMDE_FLOAT32_C(   -61.10), SIMDE_FLOAT32_C(   698.78),
                         SIMDE_FLOAT32_C(   893.49), SIMDE_FLOAT32_C(  -774.73), SIMDE_FLOAT32_C(  -469.54), SIMDE_FLOAT32_C(    88.88),
                         SIMDE_FLOAT32_C(  -797.01), SIMDE_FLOAT32_C(  -143.15), SIMDE_FLOAT32_C(  -201.38), SIMDE_FLOAT32_C(  -439.08),
                         SIMDE_FLOAT32_C(   122.21), SIMDE_FLOAT32_C(   251.76), SIMDE_FLOAT32_C(   853.77), SIMDE_FLOAT32_C(  -306.48)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   122.21), SIMDE_FLOAT32_C(   251.76), SIMDE_FLOAT32_C(   853.77), SIMDE_FLOAT32_C(  -306.48)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   995.27), SIMDE_FLOAT32_C(   762.38), SIMDE_FLOAT32_C(   849.07), SIMDE_FLOAT32_C(   533.84),
                         SIMDE_FLOAT32_C(   128.75), SIMDE_FLOAT32_C(   581.04), SIMDE_FLOAT32_C(   680.92), SIMDE_FLOAT32_C(    97.54),
                         SIMDE_FLOAT32_C(   183.54), SIMDE_FLOAT32_C(    89.55), SIMDE_FLOAT32_C(  -801.20), SIMDE_FLOAT32_C(  -458.50),
                         SIMDE_FLOAT32_C(  -944.26), SIMDE_FLOAT32_C(  -648.24), SIMDE_FLOAT32_C(  -216.16), SIMDE_FLOAT32_C(   273.51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -944.26), SIMDE_FLOAT32_C(  -648.24), SIMDE_FLOAT32_C(  -216.16), SIMDE_FLOAT32_C(   273.51)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   563.30), SIMDE_FLOAT32_C(  -488.59), SIMDE_FLOAT32_C(   -41.61), SIMDE_FLOAT32_C(  -745.38),
                         SIMDE_FLOAT32_C(  -156.54), SIMDE_FLOAT32_C(  -651.09), SIMDE_FLOAT32_C(   393.55), SIMDE_FLOAT32_C(  -610.90),
                         SIMDE_FLOAT32_C(   656.44), SIMDE_FLOAT32_C(   254.16), SIMDE_FLOAT32_C(   -27.43), SIMDE_FLOAT32_C(  -862.48),
                         SIMDE_FLOAT32_C(   639.71), SIMDE_FLOAT32_C(  -674.10), SIMDE_FLOAT32_C(  -151.15), SIMDE_FLOAT32_C(  -736.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   639.71), SIMDE_FLOAT32_C(  -674.10), SIMDE_FLOAT32_C(  -151.15), SIMDE_FLOAT32_C(  -736.28)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -997.30), SIMDE_FLOAT32_C(   958.88), SIMDE_FLOAT32_C(   414.33), SIMDE_FLOAT32_C(  -486.71),
                         SIMDE_FLOAT32_C(   347.81), SIMDE_FLOAT32_C(   -73.64), SIMDE_FLOAT32_C(   301.45), SIMDE_FLOAT32_C(  -935.75),
                         SIMDE_FLOAT32_C(   554.43), SIMDE_FLOAT32_C(   239.85), SIMDE_FLOAT32_C(  -172.14), SIMDE_FLOAT32_C(  -200.20),
                         SIMDE_FLOAT32_C(   383.84), SIMDE_FLOAT32_C(    -4.79), SIMDE_FLOAT32_C(   659.24), SIMDE_FLOAT32_C(   178.95)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   383.84), SIMDE_FLOAT32_C(    -4.79), SIMDE_FLOAT32_C(   659.24), SIMDE_FLOAT32_C(   178.95)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   282.49), SIMDE_FLOAT32_C(  -287.66), SIMDE_FLOAT32_C(  -300.74), SIMDE_FLOAT32_C(  -282.12),
                         SIMDE_FLOAT32_C(   228.49), SIMDE_FLOAT32_C(   194.42), SIMDE_FLOAT32_C(   232.99), SIMDE_FLOAT32_C(   312.60),
                         SIMDE_FLOAT32_C(    59.18), SIMDE_FLOAT32_C(   591.94), SIMDE_FLOAT32_C(   490.41), SIMDE_FLOAT32_C(   768.05),
                         SIMDE_FLOAT32_C(   628.85), SIMDE_FLOAT32_C(   497.59), SIMDE_FLOAT32_C(   700.20), SIMDE_FLOAT32_C(  -694.51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   628.85), SIMDE_FLOAT32_C(   497.59), SIMDE_FLOAT32_C(   700.20), SIMDE_FLOAT32_C(  -694.51)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm512_castps512_ps128(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_castps512_ps256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   516.61), SIMDE_FLOAT32_C(   494.30), SIMDE_FLOAT32_C(   266.21), SIMDE_FLOAT32_C(   450.63),
                         SIMDE_FLOAT32_C(  -862.95), SIMDE_FLOAT32_C(  -528.18), SIMDE_FLOAT32_C(   206.23), SIMDE_FLOAT32_C(  -212.40),
                         SIMDE_FLOAT32_C(   805.40), SIMDE_FLOAT32_C(  -902.72), SIMDE_FLOAT32_C(  -631.10), SIMDE_FLOAT32_C(  -480.24),
                         SIMDE_FLOAT32_C(   577.49), SIMDE_FLOAT32_C(   490.33), SIMDE_FLOAT32_C(  -227.96), SIMDE_FLOAT32_C(   938.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   805.40), SIMDE_FLOAT32_C(  -902.72),
                         SIMDE_FLOAT32_C(  -631.10), SIMDE_FLOAT32_C(  -480.24),
                         SIMDE_FLOAT32_C(   577.49), SIMDE_FLOAT32_C(   490.33),
                         SIMDE_FLOAT32_C(  -227.96), SIMDE_FLOAT32_C(   938.93)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   205.80), SIMDE_FLOAT32_C(  -896.03), SIMDE_FLOAT32_C(  -533.62), SIMDE_FLOAT32_C(  -495.13),
                         SIMDE_FLOAT32_C(   100.81), SIMDE_FLOAT32_C(   789.28), SIMDE_FLOAT32_C(   976.66), SIMDE_FLOAT32_C(  -300.54),
                         SIMDE_FLOAT32_C(  -430.09), SIMDE_FLOAT32_C(   725.00), SIMDE_FLOAT32_C(    80.84), SIMDE_FLOAT32_C(   -71.63),
                         SIMDE_FLOAT32_C(   804.31), SIMDE_FLOAT32_C(   798.70), SIMDE_FLOAT32_C(   251.20), SIMDE_FLOAT32_C(   -32.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -430.09), SIMDE_FLOAT32_C(   725.00),
                         SIMDE_FLOAT32_C(    80.84), SIMDE_FLOAT32_C(   -71.63),
                         SIMDE_FLOAT32_C(   804.31), SIMDE_FLOAT32_C(   798.70),
                         SIMDE_FLOAT32_C(   251.20), SIMDE_FLOAT32_C(   -32.38)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   635.87), SIMDE_FLOAT32_C(    20.88), SIMDE_FLOAT32_C(   462.09), SIMDE_FLOAT32_C(   342.91),
                         SIMDE_FLOAT32_C(  -645.79), SIMDE_FLOAT32_C(   103.74), SIMDE_FLOAT32_C(  -376.41), SIMDE_FLOAT32_C(   439.99),
                         SIMDE_FLOAT32_C(   895.02), SIMDE_FLOAT32_C(   204.80), SIMDE_FLOAT32_C(     1.77), SIMDE_FLOAT32_C(   909.62),
                         SIMDE_FLOAT32_C(  -446.42), SIMDE_FLOAT32_C(     7.95), SIMDE_FLOAT32_C(  -614.77), SIMDE_FLOAT32_C(   315.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   895.02), SIMDE_FLOAT32_C(   204.80),
                         SIMDE_FLOAT32_C(     1.77), SIMDE_FLOAT32_C(   909.62),
                         SIMDE_FLOAT32_C(  -446.42), SIMDE_FLOAT32_C(     7.95),
                         SIMDE_FLOAT32_C(  -614.77), SIMDE_FLOAT32_C(   315.09)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -372.65), SIMDE_FLOAT32_C(   316.64), SIMDE_FLOAT32_C(   -78.40), SIMDE_FLOAT32_C(   677.31),
                         SIMDE_FLOAT32_C(   299.82), SIMDE_FLOAT32_C(   452.58), SIMDE_FLOAT32_C(   876.09), SIMDE_FLOAT32_C(   746.57),
                         SIMDE_FLOAT32_C(   916.69), SIMDE_FLOAT32_C(  -811.99), SIMDE_FLOAT32_C(   637.74), SIMDE_FLOAT32_C(   -83.23),
                         SIMDE_FLOAT32_C(   289.79), SIMDE_FLOAT32_C(  -689.87), SIMDE_FLOAT32_C(   493.07), SIMDE_FLOAT32_C(   108.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   916.69), SIMDE_FLOAT32_C(  -811.99),
                         SIMDE_FLOAT32_C(   637.74), SIMDE_FLOAT32_C(   -83.23),
                         SIMDE_FLOAT32_C(   289.79), SIMDE_FLOAT32_C(  -689.87),
                         SIMDE_FLOAT32_C(   493.07), SIMDE_FLOAT32_C(   108.56)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -296.96), SIMDE_FLOAT32_C(   756.35), SIMDE_FLOAT32_C(  -395.61), SIMDE_FLOAT32_C(  -521.80),
                         SIMDE_FLOAT32_C(  -721.04), SIMDE_FLOAT32_C(   -68.70), SIMDE_FLOAT32_C(  -334.12), SIMDE_FLOAT32_C(   -56.72),
                         SIMDE_FLOAT32_C(    59.02), SIMDE_FLOAT32_C(   -66.01), SIMDE_FLOAT32_C(  -767.54), SIMDE_FLOAT32_C(   502.66),
                         SIMDE_FLOAT32_C(  -591.60), SIMDE_FLOAT32_C(  -826.33), SIMDE_FLOAT32_C(  -334.73), SIMDE_FLOAT32_C(   -13.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    59.02), SIMDE_FLOAT32_C(   -66.01),
                         SIMDE_FLOAT32_C(  -767.54), SIMDE_FLOAT32_C(   502.66),
                         SIMDE_FLOAT32_C(  -591.60), SIMDE_FLOAT32_C(  -826.33),
                         SIMDE_FLOAT32_C(  -334.73), SIMDE_FLOAT32_C(   -13.18)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(    -2.88), SIMDE_FLOAT32_C(  -966.98), SIMDE_FLOAT32_C(   854.50), SIMDE_FLOAT32_C(   668.99),
                         SIMDE_FLOAT32_C(   259.81), SIMDE_FLOAT32_C(   -77.24), SIMDE_FLOAT32_C(  -462.32), SIMDE_FLOAT32_C(   688.88),
                         SIMDE_FLOAT32_C(   754.80), SIMDE_FLOAT32_C(   986.78), SIMDE_FLOAT32_C(   961.39), SIMDE_FLOAT32_C(   850.00),
                         SIMDE_FLOAT32_C(   721.06), SIMDE_FLOAT32_C(   -70.04), SIMDE_FLOAT32_C(   136.98), SIMDE_FLOAT32_C(   949.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   754.80), SIMDE_FLOAT32_C(   986.78),
                         SIMDE_FLOAT32_C(   961.39), SIMDE_FLOAT32_C(   850.00),
                         SIMDE_FLOAT32_C(   721.06), SIMDE_FLOAT32_C(   -70.04),
                         SIMDE_FLOAT32_C(   136.98), SIMDE_FLOAT32_C(   949.65)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   841.78), SIMDE_FLOAT32_C(  -315.64), SIMDE_FLOAT32_C(   747.52), SIMDE_FLOAT32_C(   946.88),
                         SIMDE_FLOAT32_C(   871.78), SIMDE_FLOAT32_C(   775.22), SIMDE_FLOAT32_C(  -159.38), SIMDE_FLOAT32_C(   270.48),
                         SIMDE_FLOAT32_C(  -276.64), SIMDE_FLOAT32_C(   602.71), SIMDE_FLOAT32_C(  -825.17), SIMDE_FLOAT32_C(  -882.05),
                         SIMDE_FLOAT32_C(   -12.61), SIMDE_FLOAT32_C(  -809.78), SIMDE_FLOAT32_C(  -114.18), SIMDE_FLOAT32_C(   260.44)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -276.64), SIMDE_FLOAT32_C(   602.71),
                         SIMDE_FLOAT32_C(  -825.17), SIMDE_FLOAT32_C(  -882.05),
                         SIMDE_FLOAT32_C(   -12.61), SIMDE_FLOAT32_C(  -809.78),
                         SIMDE_FLOAT32_C(  -114.18), SIMDE_FLOAT32_C(   260.44)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   258.67), SIMDE_FLOAT32_C(   265.23), SIMDE_FLOAT32_C(   761.29), SIMDE_FLOAT32_C(  -932.57),
                         SIMDE_FLOAT32_C(   366.86), SIMDE_FLOAT32_C(  -726.22), SIMDE_FLOAT32_C(   179.78), SIMDE_FLOAT32_C(   965.96),
                         SIMDE_FLOAT32_C(  -420.83), SIMDE_FLOAT32_C(  -371.51), SIMDE_FLOAT32_C(   392.50), SIMDE_FLOAT32_C(   925.30),
                         SIMDE_FLOAT32_C(   990.85), SIMDE_FLOAT32_C(   -34.78), SIMDE_FLOAT32_C(   -24.58), SIMDE_FLOAT32_C(  -150.35)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -420.83), SIMDE_FLOAT32_C(  -371.51),
                         SIMDE_FLOAT32_C(   392.50), SIMDE_FLOAT32_C(   925.30),
                         SIMDE_FLOAT32_C(   990.85), SIMDE_FLOAT32_C(   -34.78),
                         SIMDE_FLOAT32_C(   -24.58), SIMDE_FLOAT32_C(  -150.35)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm512_castps512_ps256(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_castsi512_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 1658575222), INT32_C(-1117261553), INT32_C(-1839997259), INT32_C( -299852262),
                            INT32_C( -856912374), INT32_C( 2142936567), INT32_C( -954684084), INT32_C( 1657017766),
                            INT32_C( -348123015), INT32_C( -101609698), INT32_C(  554693435), INT32_C(-1533582435),
                            INT32_C( -400642696), INT32_C( 1776297700), INT32_C( 1392524409), INT32_C(  398537104)),
      simde_mm_set_epi32(INT32_C( -400642696), INT32_C( 1776297700), INT32_C( 1392524409), INT32_C(  398537104)) },
    { simde_mm512_set_epi32(INT32_C(  776372316), INT32_C(  831674978), INT32_C(   55416914), INT32_C(  243273534),
                            INT32_C( -792877249), INT32_C( -771344813), INT32_C( -310546031), INT32_C(-2107743643),
                            INT32_C(-2024392408), INT32_C(-1627000847), INT32_C( 2079816508), INT32_C(  371701407),
                            INT32_C(-1936589526), INT32_C(-1276131185), INT32_C(-2091159003), INT32_C(  424652427)),
      simde_mm_set_epi32(INT32_C(-1936589526), INT32_C(-1276131185), INT32_C(-2091159003), INT32_C(  424652427)) },
    { simde_mm512_set_epi32(INT32_C( 1173201274), INT32_C( 2136038971), INT32_C( 1938580455), INT32_C( 1481503254),
                            INT32_C( -900987494), INT32_C(  381103974), INT32_C( -844512348), INT32_C(  585017509),
                            INT32_C(  711603246), INT32_C(-1519792959), INT32_C( 1933920466), INT32_C(-1698769431),
                            INT32_C(-1782976050), INT32_C(-1748575141), INT32_C(-1460360861), INT32_C( -334769088)),
      simde_mm_set_epi32(INT32_C(-1782976050), INT32_C(-1748575141), INT32_C(-1460360861), INT32_C( -334769088)) },
    { simde_mm512_set_epi32(INT32_C( 1804169520), INT32_C(-1929398298), INT32_C( 1527159056), INT32_C(  779300869),
                            INT32_C(-1718101462), INT32_C( -324959902), INT32_C(  356284621), INT32_C(  259973358),
                            INT32_C(  -85521098), INT32_C( 1509969945), INT32_C( -146300380), INT32_C(-1326146169),
                            INT32_C( -222527512), INT32_C( 2102498956), INT32_C(   21770579), INT32_C(  799947456)),
      simde_mm_set_epi32(INT32_C( -222527512), INT32_C( 2102498956), INT32_C(   21770579), INT32_C(  799947456)) },
    { simde_mm512_set_epi32(INT32_C(   21446459), INT32_C( -874117397), INT32_C(-1237626592), INT32_C(-1776987073),
                            INT32_C(-1868633440), INT32_C( 1756862535), INT32_C(  992623093), INT32_C( 2049114875),
                            INT32_C(-1780158792), INT32_C( -396995291), INT32_C( 1019180338), INT32_C(-1532238028),
                            INT32_C( 1367863842), INT32_C(-1092466184), INT32_C( 1828179807), INT32_C( -163821277)),
      simde_mm_set_epi32(INT32_C( 1367863842), INT32_C(-1092466184), INT32_C( 1828179807), INT32_C( -163821277)) },
    { simde_mm512_set_epi32(INT32_C(  430786946), INT32_C( -784387301), INT32_C(-1254472927), INT32_C(-1743072668),
                            INT32_C(  651286019), INT32_C(-1388487554), INT32_C(  757390683), INT32_C( 1947676255),
                            INT32_C(  969518281), INT32_C(  -72978072), INT32_C(  760758773), INT32_C( 1573392247),
                            INT32_C(  865448841), INT32_C( 1831180971), INT32_C(-1639739355), INT32_C(   75957511)),
      simde_mm_set_epi32(INT32_C(  865448841), INT32_C( 1831180971), INT32_C(-1639739355), INT32_C(   75957511)) },
    { simde_mm512_set_epi32(INT32_C( 2143921197), INT32_C( -566618658), INT32_C( -232811985), INT32_C( -646802339),
                            INT32_C(-1178364835), INT32_C( 1276977735), INT32_C(  767086016), INT32_C( -313594533),
                            INT32_C(-1508762742), INT32_C(   64124631), INT32_C(-1825241034), INT32_C(  688272909),
                            INT32_C(  217977439), INT32_C(  193086834), INT32_C( -334037547), INT32_C(  -96078706)),
      simde_mm_set_epi32(INT32_C(  217977439), INT32_C(  193086834), INT32_C( -334037547), INT32_C(  -96078706)) },
    { simde_mm512_set_epi32(INT32_C(-1446801805), INT32_C( 1701962052), INT32_C( 2110825600), INT32_C( 1003088425),
                            INT32_C(-1369466226), INT32_C( -588712121), INT32_C(-1911969632), INT32_C( 1166459977),
                            INT32_C(-1912318103), INT32_C( -539596217), INT32_C(-1472577858), INT32_C( -435893517),
                            INT32_C( 1340330175), INT32_C( 1762005905), INT32_C(-1553204174), INT32_C( -839776889)),
      simde_mm_set_epi32(INT32_C( 1340330175), INT32_C( 1762005905), INT32_C(-1553204174), INT32_C( -839776889)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_castsi512_si128(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_castsi512_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 1313023361), INT32_C( -284143420), INT32_C(  762022716), INT32_C( -109476439),
                            INT32_C( -377196873), INT32_C(  289021876), INT32_C(-1835156104), INT32_C(-2032178077),
                            INT32_C(-1821500948), INT32_C(  676317044), INT32_C( 1400280404), INT32_C(-1176819357),
                            INT32_C( -771867753), INT32_C(-1499090744), INT32_C(  845761822), INT32_C( 1051767340)),
      simde_mm256_set_epi32(INT32_C(-1821500948), INT32_C(  676317044), INT32_C( 1400280404), INT32_C(-1176819357),
                            INT32_C( -771867753), INT32_C(-1499090744), INT32_C(  845761822), INT32_C( 1051767340)) },
    { simde_mm512_set_epi32(INT32_C(  584849517), INT32_C( 1957310042), INT32_C( 1025237717), INT32_C( -771085485),
                            INT32_C(  578687068), INT32_C(   23449370), INT32_C(-1748604352), INT32_C( 1528872918),
                            INT32_C(  331610618), INT32_C( 1589449489), INT32_C(-1723663783), INT32_C( -274890341),
                            INT32_C( 1614271470), INT32_C(-1087921179), INT32_C(  318041946), INT32_C(-1241918784)),
      simde_mm256_set_epi32(INT32_C(  331610618), INT32_C( 1589449489), INT32_C(-1723663783), INT32_C( -274890341),
                            INT32_C( 1614271470), INT32_C(-1087921179), INT32_C(  318041946), INT32_C(-1241918784)) },
    { simde_mm512_set_epi32(INT32_C(-1852610712), INT32_C( 1069895831), INT32_C(-1772412775), INT32_C( 1674180593),
                            INT32_C( 1091612022), INT32_C( 2100501546), INT32_C(  179298125), INT32_C( -696375983),
                            INT32_C(  697782088), INT32_C(  360978520), INT32_C( -569372444), INT32_C(-1688535258),
                            INT32_C(  857372618), INT32_C( 1720533351), INT32_C(  174096645), INT32_C(  -27592678)),
      simde_mm256_set_epi32(INT32_C(  697782088), INT32_C(  360978520), INT32_C( -569372444), INT32_C(-1688535258),
                            INT32_C(  857372618), INT32_C( 1720533351), INT32_C(  174096645), INT32_C(  -27592678)) },
    { simde_mm512_set_epi32(INT32_C( 1588790835), INT32_C( 1641509494), INT32_C(-1255607211), INT32_C(  325546446),
                            INT32_C( -545478700), INT32_C( 1405876195), INT32_C(-1090548279), INT32_C(-1934286399),
                            INT32_C(-1145918593), INT32_C( -667441949), INT32_C(  804839434), INT32_C( 1326022329),
                            INT32_C(  307496614), INT32_C(-1108181850), INT32_C( 1980353111), INT32_C( 2112031083)),
      simde_mm256_set_epi32(INT32_C(-1145918593), INT32_C( -667441949), INT32_C(  804839434), INT32_C( 1326022329),
                            INT32_C(  307496614), INT32_C(-1108181850), INT32_C( 1980353111), INT32_C( 2112031083)) },
    { simde_mm512_set_epi32(INT32_C(-1042067236), INT32_C(-1304341967), INT32_C(  157202478), INT32_C(  335492980),
                            INT32_C( 1721471627), INT32_C( -970374929), INT32_C(-1215103856), INT32_C(  804236438),
                            INT32_C(  763203116), INT32_C( 1650455375), INT32_C(  191870396), INT32_C(-1509651897),
                            INT32_C( 1356692638), INT32_C(-1388072975), INT32_C(-1822839305), INT32_C(  511824893)),
      simde_mm256_set_epi32(INT32_C(  763203116), INT32_C( 1650455375), INT32_C(  191870396), INT32_C(-1509651897),
                            INT32_C( 1356692638), INT32_C(-1388072975), INT32_C(-1822839305), INT32_C(  511824893)) },
    { simde_mm512_set_epi32(INT32_C( -321038022), INT32_C( 1580565478), INT32_C( 1887212628), INT32_C( -321448210),
                            INT32_C( 1646995861), INT32_C(  223122732), INT32_C(-1757872907), INT32_C(-1745139814),
                            INT32_C( 1574697064), INT32_C( 1593370323), INT32_C( 1019611869), INT32_C( 1148772416),
                            INT32_C(   41212650), INT32_C( 1180707726), INT32_C(-1448405590), INT32_C( -480086797)),
      simde_mm256_set_epi32(INT32_C( 1574697064), INT32_C( 1593370323), INT32_C( 1019611869), INT32_C( 1148772416),
                            INT32_C(   41212650), INT32_C( 1180707726), INT32_C(-1448405590), INT32_C( -480086797)) },
    { simde_mm512_set_epi32(INT32_C(-2123925649), INT32_C(-1300783990), INT32_C( 1491522954), INT32_C(-1497225833),
                            INT32_C(  264593112), INT32_C(-1577295575), INT32_C( 1721102182), INT32_C( -406919611),
                            INT32_C( -248074414), INT32_C(-1644442090), INT32_C(-1586232899), INT32_C(  -62204050),
                            INT32_C(  356135618), INT32_C(-1239722051), INT32_C( 1765867002), INT32_C(-2007643147)),
      simde_mm256_set_epi32(INT32_C( -248074414), INT32_C(-1644442090), INT32_C(-1586232899), INT32_C(  -62204050),
                            INT32_C(  356135618), INT32_C(-1239722051), INT32_C( 1765867002), INT32_C(-2007643147)) },
    { simde_mm512_set_epi32(INT32_C( 1712658433), INT32_C( 1782026188), INT32_C( 1026238577), INT32_C(  999831740),
                            INT32_C( 1890262543), INT32_C( -282267234), INT32_C( -314081065), INT32_C( 1258071145),
                            INT32_C(  -96847849), INT32_C(  -33628993), INT32_C( -700755553), INT32_C( 1395877145),
                            INT32_C( 1943621426), INT32_C( 1606414493), INT32_C(  234520793), INT32_C( 1932887352)),
      simde_mm256_set_epi32(INT32_C(  -96847849), INT32_C(  -33628993), INT32_C( -700755553), INT32_C( 1395877145),
                            INT32_C( 1943621426), INT32_C( 1606414493), INT32_C(  234520793), INT32_C( 1932887352)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_castsi512_si256(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_mov_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(-1748841636), INT32_C(  600342911), INT32_C( 1346502861), INT32_C(-1119296012),
                            INT32_C(  542725165), INT32_C(  811581991), INT32_C(-1753809264), INT32_C(-2095888677),
                            INT32_C(   21844621), INT32_C( -668859652), INT32_C(  304402382), INT32_C( 1173008100),
                            INT32_C( -727866068), INT32_C(     599757), INT32_C( 1586862788), INT32_C(-1998308703)),
      UINT16_C(60467),
      simde_mm512_set_epi32(INT32_C(  646279344), INT32_C(-1381858570), INT32_C( 1528846110), INT32_C( -686931066),
                            INT32_C( 1116827472), INT32_C(-1909789352), INT32_C( 1965198777), INT32_C(  743332806),
                            INT32_C( -485827488), INT32_C(-1346955971), INT32_C(  625279893), INT32_C(  390045432),
                            INT32_C( 1242706406), INT32_C( -451702195), INT32_C( -797642518), INT32_C( 1682577743)),
      simde_mm512_set_epi32(INT32_C(  646279344), INT32_C(-1381858570), INT32_C( 1528846110), INT32_C(-1119296012),
                            INT32_C( 1116827472), INT32_C(-1909789352), INT32_C(-1753809264), INT32_C(-2095888677),
                            INT32_C(   21844621), INT32_C( -668859652), INT32_C(  625279893), INT32_C(  390045432),
                            INT32_C( -727866068), INT32_C(     599757), INT32_C( -797642518), INT32_C( 1682577743)) },
    { simde_mm512_set_epi32(INT32_C(  478337815), INT32_C( -537978403), INT32_C(-1351889488), INT32_C( 1090048308),
                            INT32_C( 1261235095), INT32_C(-1289893124), INT32_C( -387446550), INT32_C(-1938729505),
                            INT32_C(-1389958008), INT32_C( 1730413171), INT32_C( 1087827160), INT32_C( 1023459790),
                            INT32_C(-1481706049), INT32_C(  911835427), INT32_C(-1124770978), INT32_C( 1212776438)),
      UINT16_C(65510),
      simde_mm512_set_epi32(INT32_C( -876793269), INT32_C(  354193822), INT32_C(-1942817736), INT32_C(   48337666),
                            INT32_C(-1069034730), INT32_C( -258187388), INT32_C(-1735480646), INT32_C( 1239662333),
                            INT32_C(-1087348321), INT32_C(  777072035), INT32_C( -223191004), INT32_C( -671373205),
                            INT32_C( -333775053), INT32_C( 1946636837), INT32_C(  875386084), INT32_C(   41135181)),
      simde_mm512_set_epi32(INT32_C( -876793269), INT32_C(  354193822), INT32_C(-1942817736), INT32_C(   48337666),
                            INT32_C(-1069034730), INT32_C( -258187388), INT32_C(-1735480646), INT32_C( 1239662333),
                            INT32_C(-1087348321), INT32_C(  777072035), INT32_C( -223191004), INT32_C( 1023459790),
                            INT32_C(-1481706049), INT32_C( 1946636837), INT32_C(  875386084), INT32_C( 1212776438)) },
    { simde_mm512_set_epi32(INT32_C(  739047763), INT32_C( 1498945773), INT32_C( 1776295699), INT32_C( 1298376143),
                            INT32_C(-1413206606), INT32_C(-1101195004), INT32_C( 1096357047), INT32_C( 1201409099),
                            INT32_C(-1184934080), INT32_C(-1142871559), INT32_C(-1331799428), INT32_C( 2127606263),
                            INT32_C( 1810587941), INT32_C(-1568035201), INT32_C(-1514801640), INT32_C( 1754146272)),
      UINT16_C(17782),
      simde_mm512_set_epi32(INT32_C(-1637684250), INT32_C( 1624419961), INT32_C(-1721698305), INT32_C( 1216991175),
                            INT32_C( 1086797293), INT32_C( -544515074), INT32_C(-1866991972), INT32_C( 1497966040),
                            INT32_C(  183681068), INT32_C( 1846911046), INT32_C(  396433769), INT32_C( 1567943719),
                            INT32_C( 1544652060), INT32_C( 1999507462), INT32_C( -389522003), INT32_C(  660842170)),
      simde_mm512_set_epi32(INT32_C(  739047763), INT32_C( 1624419961), INT32_C( 1776295699), INT32_C( 1298376143),
                            INT32_C(-1413206606), INT32_C( -544515074), INT32_C( 1096357047), INT32_C( 1497966040),
                            INT32_C(-1184934080), INT32_C( 1846911046), INT32_C(  396433769), INT32_C( 1567943719),
                            INT32_C( 1810587941), INT32_C( 1999507462), INT32_C( -389522003), INT32_C( 1754146272)) },
    { simde_mm512_set_epi32(INT32_C(-1787060903), INT32_C( 1591528199), INT32_C( 1360730903), INT32_C( -392663993),
                            INT32_C( 1833403381), INT32_C(  667948495), INT32_C(-1351186880), INT32_C(-1869951013),
                            INT32_C(-1764668962), INT32_C( 1727501907), INT32_C(-1699520398), INT32_C(-2078068732),
                            INT32_C(-1191187391), INT32_C(  809086335), INT32_C( -915516374), INT32_C( 2044786719)),
      UINT16_C(19153),
      simde_mm512_set_epi32(INT32_C(-1124863619), INT32_C( -733840886), INT32_C(  225375619), INT32_C( 2033345748),
                            INT32_C(   62836182), INT32_C(-1797131359), INT32_C( -791707937), INT32_C(-1161020437),
                            INT32_C( 1933148289), INT32_C(-1354039663), INT32_C(  533923030), INT32_C(  457770626),
                            INT32_C(-2130199261), INT32_C( -201626469), INT32_C( 1603256738), INT32_C(  385840376)),
      simde_mm512_set_epi32(INT32_C(-1787060903), INT32_C( -733840886), INT32_C( 1360730903), INT32_C( -392663993),
                            INT32_C(   62836182), INT32_C(  667948495), INT32_C( -791707937), INT32_C(-1869951013),
                            INT32_C( 1933148289), INT32_C(-1354039663), INT32_C(-1699520398), INT32_C(  457770626),
                            INT32_C(-1191187391), INT32_C(  809086335), INT32_C( -915516374), INT32_C(  385840376)) },
    { simde_mm512_set_epi32(INT32_C(-1844996035), INT32_C( -483918772), INT32_C(-1530619556), INT32_C( -447486042),
                            INT32_C( -153016391), INT32_C( 1772993408), INT32_C(-1557466731), INT32_C( 1884729185),
                            INT32_C(-1170473640), INT32_C( -231873321), INT32_C( 1063107119), INT32_C( 1409583343),
                            INT32_C(  131479252), INT32_C(-1464445699), INT32_C(-1859507666), INT32_C( 1142318206)),
      UINT16_C(39686),
      simde_mm512_set_epi32(INT32_C(-1710909147), INT32_C( 1655743921), INT32_C(-1520991125), INT32_C(-1200934587),
                            INT32_C( -721899112), INT32_C( 1216881740), INT32_C( -481496777), INT32_C( -893026644),
                            INT32_C(-2035526652), INT32_C( -294630589), INT32_C(-1446210787), INT32_C( -547573265),
                            INT32_C( 1911285838), INT32_C(-1067024301), INT32_C(-1545394687), INT32_C( 1507767747)),
      simde_mm512_set_epi32(INT32_C(-1710909147), INT32_C( -483918772), INT32_C(-1530619556), INT32_C(-1200934587),
                            INT32_C( -721899112), INT32_C( 1772993408), INT32_C( -481496777), INT32_C( -893026644),
                            INT32_C(-1170473640), INT32_C( -231873321), INT32_C( 1063107119), INT32_C( 1409583343),
                            INT32_C(  131479252), INT32_C(-1067024301), INT32_C(-1545394687), INT32_C( 1142318206)) },
    { simde_mm512_set_epi32(INT32_C( 2003854537), INT32_C(  316518418), INT32_C(-2128378506), INT32_C( -814023178),
                            INT32_C( 2134095257), INT32_C( -273917753), INT32_C(  269941696), INT32_C(-1761573676),
                            INT32_C( -504711162), INT32_C( 1086943646), INT32_C( -304633534), INT32_C( -905159738),
                            INT32_C(-1025692186), INT32_C(-2082862175), INT32_C(-1626855678), INT32_C(-1231176910)),
      UINT16_C(13329),
      simde_mm512_set_epi32(INT32_C(  838273890), INT32_C( 1209103370), INT32_C(  947433971), INT32_C(   91213725),
                            INT32_C(  749577280), INT32_C(  157602752), INT32_C( 2125537515), INT32_C( -782796801),
                            INT32_C( -120430288), INT32_C( -810448185), INT32_C( -659512402), INT32_C(  419195007),
                            INT32_C( -830103963), INT32_C( -756234442), INT32_C(  376291679), INT32_C( -610488282)),
      simde_mm512_set_epi32(INT32_C( 2003854537), INT32_C(  316518418), INT32_C(  947433971), INT32_C(   91213725),
                            INT32_C( 2134095257), INT32_C(  157602752), INT32_C(  269941696), INT32_C(-1761573676),
                            INT32_C( -504711162), INT32_C( 1086943646), INT32_C( -304633534), INT32_C(  419195007),
                            INT32_C(-1025692186), INT32_C(-2082862175), INT32_C(-1626855678), INT32_C( -610488282)) },
    { simde_mm512_set_epi32(INT32_C( -974755823), INT32_C(  -98121742), INT32_C( 1561555936), INT32_C(-1281058782),
                            INT32_C(-2008886211), INT32_C( 1568326299), INT32_C( 1232828554), INT32_C(  127919997),
                            INT32_C( 1015818460), INT32_C( -681833659), INT32_C(  340145717), INT32_C( 1048452961),
                            INT32_C(  749206991), INT32_C( 1290937767), INT32_C(-1150545818), INT32_C(  -48881570)),
      UINT16_C(55435),
      simde_mm512_set_epi32(INT32_C( 1177945769), INT32_C(-1878447950), INT32_C( -271391312), INT32_C(-2014500164),
                            INT32_C(-2080120479), INT32_C( 1195569010), INT32_C(-1583493780), INT32_C( 1466155853),
                            INT32_C( -735473338), INT32_C( 1922464741), INT32_C( -224185100), INT32_C( -929578437),
                            INT32_C(  831459587), INT32_C(-1105963780), INT32_C(-1360707796), INT32_C( -211781248)),
      simde_mm512_set_epi32(INT32_C( 1177945769), INT32_C(-1878447950), INT32_C( 1561555936), INT32_C(-2014500164),
                            INT32_C(-2080120479), INT32_C( 1568326299), INT32_C( 1232828554), INT32_C(  127919997),
                            INT32_C( -735473338), INT32_C( -681833659), INT32_C(  340145717), INT32_C( 1048452961),
                            INT32_C(  831459587), INT32_C( 1290937767), INT32_C(-1360707796), INT32_C( -211781248)) },
    { simde_mm512_set_epi32(INT32_C( 1583932216), INT32_C(-1528139164), INT32_C(  665399981), INT32_C(  718332631),
                            INT32_C( -984331868), INT32_C(-1317077859), INT32_C(-1440392153), INT32_C(-1978382578),
                            INT32_C(  828185710), INT32_C( 1905160582), INT32_C(  120938992), INT32_C( 1613459128),
                            INT32_C( -812252493), INT32_C(-1503952372), INT32_C(  231875300), INT32_C( -885498028)),
      UINT16_C(45743),
      simde_mm512_set_epi32(INT32_C(-1033540577), INT32_C( -995705628), INT32_C(-2098565905), INT32_C(-1609941379),
                            INT32_C(  451122481), INT32_C(  898911803), INT32_C( -918933314), INT32_C( 1301755496),
                            INT32_C(  654535343), INT32_C( 1915381036), INT32_C( -595265918), INT32_C( -204141630),
                            INT32_C(-1824782722), INT32_C(-1457642917), INT32_C(-1358921472), INT32_C( 1013008616)),
      simde_mm512_set_epi32(INT32_C(-1033540577), INT32_C(-1528139164), INT32_C(-2098565905), INT32_C(-1609941379),
                            INT32_C( -984331868), INT32_C(-1317077859), INT32_C( -918933314), INT32_C(-1978382578),
                            INT32_C(  654535343), INT32_C( 1905160582), INT32_C( -595265918), INT32_C( 1613459128),
                            INT32_C(-1824782722), INT32_C(-1457642917), INT32_C(-1358921472), INT32_C( 1013008616)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_mov_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_mov_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 8729250599109288206), INT64_C(  925123000700261284),
                            INT64_C( -996462675499144949), INT64_C(-5486361937319788764),
                            INT64_C(-1619246833501834651), INT64_C(-1914665916415518359),
                            INT64_C( 4596079613709719053), INT64_C(-1669293344454375632)),
      UINT8_C(136),
      simde_mm512_set_epi64(INT64_C(-2718786087636304341), INT64_C( 6271007050593066413),
                            INT64_C( 7325428114350079264), INT64_C( 8373606416957659495),
                            INT64_C( 8585702140748752091), INT64_C(-6106352141912550191),
                            INT64_C(-7415158757307660945), INT64_C(-4168322686232168747)),
      simde_mm512_set_epi64(INT64_C(-2718786087636304341), INT64_C(  925123000700261284),
                            INT64_C( -996462675499144949), INT64_C(-5486361937319788764),
                            INT64_C( 8585702140748752091), INT64_C(-1914665916415518359),
                            INT64_C( 4596079613709719053), INT64_C(-1669293344454375632)) },
    { simde_mm512_set_epi64(INT64_C( 8240025841211248490), INT64_C( 2437990159450284908),
                            INT64_C( 2201815834941113848), INT64_C( 7879550161691977002),
                            INT64_C( 3825487759520775297), INT64_C( 6674403996216424931),
                            INT64_C(-5802137669857725171), INT64_C( 5686996017309487110)),
      UINT8_C(227),
      simde_mm512_set_epi64(INT64_C(  120730317606372397), INT64_C(-1410770079656234556),
                            INT64_C( 4532617684378198659), INT64_C( 9004023903916376139),
                            INT64_C( 7206885247739448460), INT64_C(-6411218032719574536),
                            INT64_C( -962636034832057562), INT64_C(-6211267245753502041)),
      simde_mm512_set_epi64(INT64_C(  120730317606372397), INT64_C(-1410770079656234556),
                            INT64_C( 4532617684378198659), INT64_C( 7879550161691977002),
                            INT64_C( 3825487759520775297), INT64_C( 6674403996216424931),
                            INT64_C( -962636034832057562), INT64_C(-6211267245753502041)) },
    { simde_mm512_set_epi64(INT64_C( 4674722797399239366), INT64_C( 2000178744548395677),
                            INT64_C(-3230169679464817239), INT64_C( 6675942378016655726),
                            INT64_C(-4074632284771109640), INT64_C(-1969073951075376054),
                            INT64_C(-7309602967246577272), INT64_C( 6746883208360816464)),
      UINT8_C(189),
      simde_mm512_set_epi64(INT64_C( 7111791735729821232), INT64_C(-6377956101145598745),
                            INT64_C(-4955467359912007508), INT64_C( -340840922408165844),
                            INT64_C( 3280430708356940081), INT64_C(  400669322893233577),
                            INT64_C( 6742772793155919855), INT64_C(-1365845768056837484)),
      simde_mm512_set_epi64(INT64_C( 7111791735729821232), INT64_C( 2000178744548395677),
                            INT64_C(-4955467359912007508), INT64_C( -340840922408165844),
                            INT64_C( 3280430708356940081), INT64_C(  400669322893233577),
                            INT64_C(-7309602967246577272), INT64_C(-1365845768056837484)) },
    { simde_mm512_set_epi64(INT64_C(-5185665192936807952), INT64_C( 2873887117219468065),
                            INT64_C(  944218707053685182), INT64_C(-6471325153303919649),
                            INT64_C(-1551809186210791512), INT64_C( 8676397618641344048),
                            INT64_C(-1480083839359048471), INT64_C(-2573286236881012052)),
      UINT8_C(135),
      simde_mm512_set_epi64(INT64_C( 4851071406626175825), INT64_C( 2006733877612279017),
                            INT64_C( 9148059701805005067), INT64_C( 3484083856858518164),
                            INT64_C( -542612751996632572), INT64_C( 6154040976669554118),
                            INT64_C( 4310055852136225460), INT64_C( 6666177398356729891)),
      simde_mm512_set_epi64(INT64_C( 4851071406626175825), INT64_C( 2873887117219468065),
                            INT64_C(  944218707053685182), INT64_C(-6471325153303919649),
                            INT64_C(-1551809186210791512), INT64_C( 6154040976669554118),
                            INT64_C( 4310055852136225460), INT64_C( 6666177398356729891)) },
    { simde_mm512_set_epi64(INT64_C(-6362423492218583699), INT64_C( 4052676248150053459),
                            INT64_C(-1785632160509127109), INT64_C( 4504790352522402260),
                            INT64_C(  214305831990150369), INT64_C( 4122674741194642780),
                            INT64_C(-9061446978520477770), INT64_C( -925260945734331795)),
      UINT8_C( 88),
      simde_mm512_set_epi64(INT64_C( 7816755513219693536), INT64_C(-8078701368125426812),
                            INT64_C( 5999276564615449517), INT64_C(-3747208296317683129),
                            INT64_C(-3767121149493822975), INT64_C( 3269862772677933078),
                            INT64_C(-1274534447611012205), INT64_C(  367478185734650139)),
      simde_mm512_set_epi64(INT64_C(-6362423492218583699), INT64_C(-8078701368125426812),
                            INT64_C(-1785632160509127109), INT64_C(-3747208296317683129),
                            INT64_C(-3767121149493822975), INT64_C( 4122674741194642780),
                            INT64_C(-9061446978520477770), INT64_C( -925260945734331795)) },
    { simde_mm512_set_epi64(INT64_C(-6749425177074609965), INT64_C( 8453995530571484051),
                            INT64_C(-7619559937003101591), INT64_C( 3005943923235484348),
                            INT64_C( 4327678115781969631), INT64_C( 5990841649027118513),
                            INT64_C(-1241607161778990291), INT64_C(  -91855491071654622)),
      UINT8_C( 22),
      simde_mm512_set_epi64(INT64_C( 4461859928182214174), INT64_C(-5186049742858346871),
                            INT64_C( -636993447067685727), INT64_C( 8339698509359201789),
                            INT64_C( 4598711567911914631), INT64_C( 7428996315725576873),
                            INT64_C( 6513452752711502515), INT64_C(-6603414145042292282)),
      simde_mm512_set_epi64(INT64_C(-6749425177074609965), INT64_C( 8453995530571484051),
                            INT64_C(-7619559937003101591), INT64_C( 8339698509359201789),
                            INT64_C( 4327678115781969631), INT64_C( 7428996315725576873),
                            INT64_C( 6513452752711502515), INT64_C(  -91855491071654622)) },
    { simde_mm512_set_epi64(INT64_C(-7023609179598013523), INT64_C(-2166290313032224989),
                            INT64_C(-1367963225958164233), INT64_C(-9082538196892642083),
                            INT64_C(-7482977792619995502), INT64_C( 4800709110944492165),
                            INT64_C( 3082355013095664677), INT64_C(-4286500001112695437)),
      UINT8_C( 42),
      simde_mm512_set_epi64(INT64_C(  522664068472938939), INT64_C(-5622535385140832229),
                            INT64_C( 4829749372798053845), INT64_C( -330958976268778895),
                            INT64_C(-2657198631452288613), INT64_C(-3805394135151266272),
                            INT64_C( 4429043998616724751), INT64_C( 4131511442627175760)),
      simde_mm512_set_epi64(INT64_C(-7023609179598013523), INT64_C(-2166290313032224989),
                            INT64_C( 4829749372798053845), INT64_C(-9082538196892642083),
                            INT64_C(-2657198631452288613), INT64_C( 4800709110944492165),
                            INT64_C( 4429043998616724751), INT64_C(-4286500001112695437)) },
    { simde_mm512_set_epi64(INT64_C(-5567656428388000347), INT64_C( -971128712423557311),
                            INT64_C( 3761317547504069574), INT64_C( 6096071933426825544),
                            INT64_C( 3108166743366703612), INT64_C(-3435283790563075237),
                            INT64_C( 3598996591046999900), INT64_C( 2520744130071328064)),
      UINT8_C( 13),
      simde_mm512_set_epi64(INT64_C( -976144998301952820), INT64_C( 5304141922221069696),
                            INT64_C( 1153833608356774417), INT64_C(-5431879705444140176),
                            INT64_C(-4200442870371425874), INT64_C( 9118970466689378415),
                            INT64_C( 7182201605874776129), INT64_C( 6344954152679193639)),
      simde_mm512_set_epi64(INT64_C(-5567656428388000347), INT64_C( -971128712423557311),
                            INT64_C( 3761317547504069574), INT64_C( 6096071933426825544),
                            INT64_C(-4200442870371425874), INT64_C( 9118970466689378415),
                            INT64_C( 3598996591046999900), INT64_C( 6344954152679193639)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_mov_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_mov_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -278.44), SIMDE_FLOAT32_C(   958.04), SIMDE_FLOAT32_C(  -686.18), SIMDE_FLOAT32_C(  -120.52),
                         SIMDE_FLOAT32_C(   759.91), SIMDE_FLOAT32_C(   470.87), SIMDE_FLOAT32_C(  -723.57), SIMDE_FLOAT32_C(   170.04),
                         SIMDE_FLOAT32_C(   559.73), SIMDE_FLOAT32_C(   984.13), SIMDE_FLOAT32_C(   -84.72), SIMDE_FLOAT32_C(  -543.95),
                         SIMDE_FLOAT32_C(   998.02), SIMDE_FLOAT32_C(  -559.31), SIMDE_FLOAT32_C(   134.12), SIMDE_FLOAT32_C(  -230.64)),
      UINT16_C(    0),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -161.72), SIMDE_FLOAT32_C(   540.27), SIMDE_FLOAT32_C(  -745.55), SIMDE_FLOAT32_C(   623.14),
                         SIMDE_FLOAT32_C(  -272.95), SIMDE_FLOAT32_C(   176.76), SIMDE_FLOAT32_C(  -957.12), SIMDE_FLOAT32_C(  -720.97),
                         SIMDE_FLOAT32_C(  -491.62), SIMDE_FLOAT32_C(   442.72), SIMDE_FLOAT32_C(    94.42), SIMDE_FLOAT32_C(  -425.44),
                         SIMDE_FLOAT32_C(   378.60), SIMDE_FLOAT32_C(  -248.93), SIMDE_FLOAT32_C(   638.30), SIMDE_FLOAT32_C(  -857.32)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -278.44), SIMDE_FLOAT32_C(   958.04), SIMDE_FLOAT32_C(  -686.18), SIMDE_FLOAT32_C(  -120.52),
                         SIMDE_FLOAT32_C(   759.91), SIMDE_FLOAT32_C(   470.87), SIMDE_FLOAT32_C(  -723.57), SIMDE_FLOAT32_C(   170.04),
                         SIMDE_FLOAT32_C(   559.73), SIMDE_FLOAT32_C(   984.13), SIMDE_FLOAT32_C(   -84.72), SIMDE_FLOAT32_C(  -543.95),
                         SIMDE_FLOAT32_C(   998.02), SIMDE_FLOAT32_C(  -559.31), SIMDE_FLOAT32_C(   134.12), SIMDE_FLOAT32_C(  -230.64)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -455.21), SIMDE_FLOAT32_C(  -180.02), SIMDE_FLOAT32_C(  -110.74), SIMDE_FLOAT32_C(  -586.50),
                         SIMDE_FLOAT32_C(    -9.89), SIMDE_FLOAT32_C(  -597.54), SIMDE_FLOAT32_C(   553.79), SIMDE_FLOAT32_C(   611.64),
                         SIMDE_FLOAT32_C(   717.03), SIMDE_FLOAT32_C(  -381.85), SIMDE_FLOAT32_C(   862.32), SIMDE_FLOAT32_C(   302.29),
                         SIMDE_FLOAT32_C(   146.86), SIMDE_FLOAT32_C(  -693.40), SIMDE_FLOAT32_C(  -247.57), SIMDE_FLOAT32_C(  -469.49)),
      UINT16_C(    0),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   842.67), SIMDE_FLOAT32_C(  -856.89), SIMDE_FLOAT32_C(  -490.76), SIMDE_FLOAT32_C(   922.81),
                         SIMDE_FLOAT32_C(   -69.36), SIMDE_FLOAT32_C(   380.23), SIMDE_FLOAT32_C(  -846.01), SIMDE_FLOAT32_C(  -485.23),
                         SIMDE_FLOAT32_C(  -171.14), SIMDE_FLOAT32_C(   602.88), SIMDE_FLOAT32_C(  -717.33), SIMDE_FLOAT32_C(   336.05),
                         SIMDE_FLOAT32_C(  -432.71), SIMDE_FLOAT32_C(  -881.01), SIMDE_FLOAT32_C(  -255.82), SIMDE_FLOAT32_C(   168.04)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -455.21), SIMDE_FLOAT32_C(  -180.02), SIMDE_FLOAT32_C(  -110.74), SIMDE_FLOAT32_C(  -586.50),
                         SIMDE_FLOAT32_C(    -9.89), SIMDE_FLOAT32_C(  -597.54), SIMDE_FLOAT32_C(   553.79), SIMDE_FLOAT32_C(   611.64),
                         SIMDE_FLOAT32_C(   717.03), SIMDE_FLOAT32_C(  -381.85), SIMDE_FLOAT32_C(   862.32), SIMDE_FLOAT32_C(   302.29),
                         SIMDE_FLOAT32_C(   146.86), SIMDE_FLOAT32_C(  -693.40), SIMDE_FLOAT32_C(  -247.57), SIMDE_FLOAT32_C(  -469.49)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -694.40), SIMDE_FLOAT32_C(  -404.01), SIMDE_FLOAT32_C(   766.51), SIMDE_FLOAT32_C(  -392.19),
                         SIMDE_FLOAT32_C(  -908.15), SIMDE_FLOAT32_C(  -690.12), SIMDE_FLOAT32_C(  -262.73), SIMDE_FLOAT32_C(  -353.25),
                         SIMDE_FLOAT32_C(  -451.03), SIMDE_FLOAT32_C(   -88.58), SIMDE_FLOAT32_C(   658.99), SIMDE_FLOAT32_C(  -961.05),
                         SIMDE_FLOAT32_C(  -743.39), SIMDE_FLOAT32_C(   747.85), SIMDE_FLOAT32_C(  -989.89), SIMDE_FLOAT32_C(   -48.62)),
      UINT16_C(    0),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -585.79), SIMDE_FLOAT32_C(  -884.44), SIMDE_FLOAT32_C(  -722.53), SIMDE_FLOAT32_C(   296.99),
                         SIMDE_FLOAT32_C(   791.87), SIMDE_FLOAT32_C(   514.23), SIMDE_FLOAT32_C(   110.66), SIMDE_FLOAT32_C(  -891.24),
                         SIMDE_FLOAT32_C(  -893.87), SIMDE_FLOAT32_C(   597.88), SIMDE_FLOAT32_C(  -561.25), SIMDE_FLOAT32_C(  -182.63),
                         SIMDE_FLOAT32_C(   -91.96), SIMDE_FLOAT32_C(   272.32), SIMDE_FLOAT32_C(   -87.60), SIMDE_FLOAT32_C(    34.84)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -694.40), SIMDE_FLOAT32_C(  -404.01), SIMDE_FLOAT32_C(   766.51), SIMDE_FLOAT32_C(  -392.19),
                         SIMDE_FLOAT32_C(  -908.15), SIMDE_FLOAT32_C(  -690.12), SIMDE_FLOAT32_C(  -262.73), SIMDE_FLOAT32_C(  -353.25),
                         SIMDE_FLOAT32_C(  -451.03), SIMDE_FLOAT32_C(   -88.58), SIMDE_FLOAT32_C(   658.99), SIMDE_FLOAT32_C(  -961.05),
                         SIMDE_FLOAT32_C(  -743.39), SIMDE_FLOAT32_C(   747.85), SIMDE_FLOAT32_C(  -989.89), SIMDE_FLOAT32_C(   -48.62)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   706.89), SIMDE_FLOAT32_C(   473.35), SIMDE_FLOAT32_C(   525.10), SIMDE_FLOAT32_C(    58.51),
                         SIMDE_FLOAT32_C(  -849.29), SIMDE_FLOAT32_C(   830.92), SIMDE_FLOAT32_C(   666.67), SIMDE_FLOAT32_C(   510.60),
                         SIMDE_FLOAT32_C(   494.95), SIMDE_FLOAT32_C(  -644.02), SIMDE_FLOAT32_C(   666.48), SIMDE_FLOAT32_C(   728.99),
                         SIMDE_FLOAT32_C(    57.50), SIMDE_FLOAT32_C(  -509.99), SIMDE_FLOAT32_C(   -86.32), SIMDE_FLOAT32_C(   945.97)),
      UINT16_C(    0),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   396.65), SIMDE_FLOAT32_C(  -337.05), SIMDE_FLOAT32_C(    13.39), SIMDE_FLOAT32_C(   374.11),
                         SIMDE_FLOAT32_C(   941.83), SIMDE_FLOAT32_C(   -80.39), SIMDE_FLOAT32_C(  -533.82), SIMDE_FLOAT32_C(   -81.97),
                         SIMDE_FLOAT32_C(   -76.37), SIMDE_FLOAT32_C(  -466.22), SIMDE_FLOAT32_C(  -527.13), SIMDE_FLOAT32_C(   285.31),
                         SIMDE_FLOAT32_C(  -159.19), SIMDE_FLOAT32_C(  -769.18), SIMDE_FLOAT32_C(   908.64), SIMDE_FLOAT32_C(  -647.66)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   706.89), SIMDE_FLOAT32_C(   473.35), SIMDE_FLOAT32_C(   525.10), SIMDE_FLOAT32_C(    58.51),
                         SIMDE_FLOAT32_C(  -849.29), SIMDE_FLOAT32_C(   830.92), SIMDE_FLOAT32_C(   666.67), SIMDE_FLOAT32_C(   510.60),
                         SIMDE_FLOAT32_C(   494.95), SIMDE_FLOAT32_C(  -644.02), SIMDE_FLOAT32_C(   666.48), SIMDE_FLOAT32_C(   728.99),
                         SIMDE_FLOAT32_C(    57.50), SIMDE_FLOAT32_C(  -509.99), SIMDE_FLOAT32_C(   -86.32), SIMDE_FLOAT32_C(   945.97)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   305.38), SIMDE_FLOAT32_C(   354.29), SIMDE_FLOAT32_C(   625.78), SIMDE_FLOAT32_C(   840.33),
                         SIMDE_FLOAT32_C(   398.08), SIMDE_FLOAT32_C(  -775.15), SIMDE_FLOAT32_C(  -749.75), SIMDE_FLOAT32_C(  -579.50),
                         SIMDE_FLOAT32_C(   326.67), SIMDE_FLOAT32_C(  -369.97), SIMDE_FLOAT32_C(  -888.36), SIMDE_FLOAT32_C(  -369.43),
                         SIMDE_FLOAT32_C(   587.01), SIMDE_FLOAT32_C(  -977.20), SIMDE_FLOAT32_C(  -154.58), SIMDE_FLOAT32_C(  -264.71)),
      UINT16_C(    0),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   472.46), SIMDE_FLOAT32_C(  -814.28), SIMDE_FLOAT32_C(   331.94), SIMDE_FLOAT32_C(   -36.35),
                         SIMDE_FLOAT32_C(   -98.00), SIMDE_FLOAT32_C(   862.68), SIMDE_FLOAT32_C(  -130.24), SIMDE_FLOAT32_C(    65.39),
                         SIMDE_FLOAT32_C(  -826.35), SIMDE_FLOAT32_C(    92.38), SIMDE_FLOAT32_C(  -698.83), SIMDE_FLOAT32_C(   457.07),
                         SIMDE_FLOAT32_C(  -472.97), SIMDE_FLOAT32_C(  -117.57), SIMDE_FLOAT32_C(  -498.77), SIMDE_FLOAT32_C(   798.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   305.38), SIMDE_FLOAT32_C(   354.29), SIMDE_FLOAT32_C(   625.78), SIMDE_FLOAT32_C(   840.33),
                         SIMDE_FLOAT32_C(   398.08), SIMDE_FLOAT32_C(  -775.15), SIMDE_FLOAT32_C(  -749.75), SIMDE_FLOAT32_C(  -579.50),
                         SIMDE_FLOAT32_C(   326.67), SIMDE_FLOAT32_C(  -369.97), SIMDE_FLOAT32_C(  -888.36), SIMDE_FLOAT32_C(  -369.43),
                         SIMDE_FLOAT32_C(   587.01), SIMDE_FLOAT32_C(  -977.20), SIMDE_FLOAT32_C(  -154.58), SIMDE_FLOAT32_C(  -264.71)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   845.06), SIMDE_FLOAT32_C(  -527.19), SIMDE_FLOAT32_C(  -753.05), SIMDE_FLOAT32_C(  -867.95),
                         SIMDE_FLOAT32_C(   -98.38), SIMDE_FLOAT32_C(   -90.28), SIMDE_FLOAT32_C(   321.06), SIMDE_FLOAT32_C(  -308.74),
                         SIMDE_FLOAT32_C(   969.13), SIMDE_FLOAT32_C(  -263.02), SIMDE_FLOAT32_C(  -517.54), SIMDE_FLOAT32_C(   566.67),
                         SIMDE_FLOAT32_C(  -321.03), SIMDE_FLOAT32_C(   -19.45), SIMDE_FLOAT32_C(  -773.18), SIMDE_FLOAT32_C(  -562.24)),
      UINT16_C(    0),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -313.43), SIMDE_FLOAT32_C(  -900.90), SIMDE_FLOAT32_C(  -480.72), SIMDE_FLOAT32_C(   288.15),
                         SIMDE_FLOAT32_C(   603.38), SIMDE_FLOAT32_C(   964.29), SIMDE_FLOAT32_C(   140.98), SIMDE_FLOAT32_C(   269.46),
                         SIMDE_FLOAT32_C(   960.77), SIMDE_FLOAT32_C(  -220.33), SIMDE_FLOAT32_C(   524.23), SIMDE_FLOAT32_C(  -633.14),
                         SIMDE_FLOAT32_C(  -680.30), SIMDE_FLOAT32_C(   880.56), SIMDE_FLOAT32_C(   661.76), SIMDE_FLOAT32_C(  -794.03)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   845.06), SIMDE_FLOAT32_C(  -527.19), SIMDE_FLOAT32_C(  -753.05), SIMDE_FLOAT32_C(  -867.95),
                         SIMDE_FLOAT32_C(   -98.38), SIMDE_FLOAT32_C(   -90.28), SIMDE_FLOAT32_C(   321.06), SIMDE_FLOAT32_C(  -308.74),
                         SIMDE_FLOAT32_C(   969.13), SIMDE_FLOAT32_C(  -263.02), SIMDE_FLOAT32_C(  -517.54), SIMDE_FLOAT32_C(   566.67),
                         SIMDE_FLOAT32_C(  -321.03), SIMDE_FLOAT32_C(   -19.45), SIMDE_FLOAT32_C(  -773.18), SIMDE_FLOAT32_C(  -562.24)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -595.71), SIMDE_FLOAT32_C(   923.49), SIMDE_FLOAT32_C(  -968.66), SIMDE_FLOAT32_C(   136.30),
                         SIMDE_FLOAT32_C(   658.04), SIMDE_FLOAT32_C(    31.08), SIMDE_FLOAT32_C(   664.79), SIMDE_FLOAT32_C(   525.95),
                         SIMDE_FLOAT32_C(   643.61), SIMDE_FLOAT32_C(  -559.86), SIMDE_FLOAT32_C(  -291.18), SIMDE_FLOAT32_C(    35.13),
                         SIMDE_FLOAT32_C(  -188.19), SIMDE_FLOAT32_C(   767.03), SIMDE_FLOAT32_C(  -828.01), SIMDE_FLOAT32_C(   801.09)),
      UINT16_C(    0),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -750.17), SIMDE_FLOAT32_C(   128.67), SIMDE_FLOAT32_C(   441.75), SIMDE_FLOAT32_C(   625.42),
                         SIMDE_FLOAT32_C(   865.73), SIMDE_FLOAT32_C(  -522.43), SIMDE_FLOAT32_C(   871.78), SIMDE_FLOAT32_C(   736.62),
                         SIMDE_FLOAT32_C(   -52.49), SIMDE_FLOAT32_C(  -188.89), SIMDE_FLOAT32_C(   163.52), SIMDE_FLOAT32_C(   743.65),
                         SIMDE_FLOAT32_C(  -912.98), SIMDE_FLOAT32_C(  -904.70), SIMDE_FLOAT32_C(   973.06), SIMDE_FLOAT32_C(  -214.13)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -595.71), SIMDE_FLOAT32_C(   923.49), SIMDE_FLOAT32_C(  -968.66), SIMDE_FLOAT32_C(   136.30),
                         SIMDE_FLOAT32_C(   658.04), SIMDE_FLOAT32_C(    31.08), SIMDE_FLOAT32_C(   664.79), SIMDE_FLOAT32_C(   525.95),
                         SIMDE_FLOAT32_C(   643.61), SIMDE_FLOAT32_C(  -559.86), SIMDE_FLOAT32_C(  -291.18), SIMDE_FLOAT32_C(    35.13),
                         SIMDE_FLOAT32_C(  -188.19), SIMDE_FLOAT32_C(   767.03), SIMDE_FLOAT32_C(  -828.01), SIMDE_FLOAT32_C(   801.09)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -351.95), SIMDE_FLOAT32_C(   902.78), SIMDE_FLOAT32_C(  -172.20), SIMDE_FLOAT32_C(   540.77),
                         SIMDE_FLOAT32_C(  -431.24), SIMDE_FLOAT32_C(   243.87), SIMDE_FLOAT32_C(   216.07), SIMDE_FLOAT32_C(   747.45),
                         SIMDE_FLOAT32_C(  -864.81), SIMDE_FLOAT32_C(  -982.67), SIMDE_FLOAT32_C(  -710.14), SIMDE_FLOAT32_C(  -539.39),
                         SIMDE_FLOAT32_C(  -100.27), SIMDE_FLOAT32_C(  -988.79), SIMDE_FLOAT32_C(  -220.83), SIMDE_FLOAT32_C(   489.72)),
      UINT16_C(    0),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   688.70), SIMDE_FLOAT32_C(  -942.30), SIMDE_FLOAT32_C(  -353.35), SIMDE_FLOAT32_C(  -645.42),
                         SIMDE_FLOAT32_C(   206.41), SIMDE_FLOAT32_C(   546.87), SIMDE_FLOAT32_C(  -878.90), SIMDE_FLOAT32_C(   614.84),
                         SIMDE_FLOAT32_C(   757.82), SIMDE_FLOAT32_C(   388.29), SIMDE_FLOAT32_C(  -767.39), SIMDE_FLOAT32_C(   567.68),
                         SIMDE_FLOAT32_C(   464.76), SIMDE_FLOAT32_C(  -828.44), SIMDE_FLOAT32_C(   843.54), SIMDE_FLOAT32_C(   504.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -351.95), SIMDE_FLOAT32_C(   902.78), SIMDE_FLOAT32_C(  -172.20), SIMDE_FLOAT32_C(   540.77),
                         SIMDE_FLOAT32_C(  -431.24), SIMDE_FLOAT32_C(   243.87), SIMDE_FLOAT32_C(   216.07), SIMDE_FLOAT32_C(   747.45),
                         SIMDE_FLOAT32_C(  -864.81), SIMDE_FLOAT32_C(  -982.67), SIMDE_FLOAT32_C(  -710.14), SIMDE_FLOAT32_C(  -539.39),
                         SIMDE_FLOAT32_C(  -100.27), SIMDE_FLOAT32_C(  -988.79), SIMDE_FLOAT32_C(  -220.83), SIMDE_FLOAT32_C(   489.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_mov_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_mov_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -997.43), SIMDE_FLOAT64_C(  -24.75),
                         SIMDE_FLOAT64_C(  811.92), SIMDE_FLOAT64_C(  716.01),
                         SIMDE_FLOAT64_C( -286.81), SIMDE_FLOAT64_C(  360.81),
                         SIMDE_FLOAT64_C( -618.94), SIMDE_FLOAT64_C(  103.41)),
      UINT8_C( 17),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  779.73), SIMDE_FLOAT64_C(  -71.34),
                         SIMDE_FLOAT64_C(   74.67), SIMDE_FLOAT64_C(  569.44),
                         SIMDE_FLOAT64_C(  765.94), SIMDE_FLOAT64_C(  114.94),
                         SIMDE_FLOAT64_C(   85.69), SIMDE_FLOAT64_C(  982.40)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -997.43), SIMDE_FLOAT64_C(  -24.75),
                         SIMDE_FLOAT64_C(  811.92), SIMDE_FLOAT64_C(  569.44),
                         SIMDE_FLOAT64_C( -286.81), SIMDE_FLOAT64_C(  360.81),
                         SIMDE_FLOAT64_C( -618.94), SIMDE_FLOAT64_C(  982.40)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -989.28), SIMDE_FLOAT64_C( -906.64),
                         SIMDE_FLOAT64_C( -211.36), SIMDE_FLOAT64_C( -108.84),
                         SIMDE_FLOAT64_C(  211.05), SIMDE_FLOAT64_C( -602.13),
                         SIMDE_FLOAT64_C(   19.95), SIMDE_FLOAT64_C( -745.56)),
      UINT8_C(115),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -995.20), SIMDE_FLOAT64_C(   66.82),
                         SIMDE_FLOAT64_C(  747.55), SIMDE_FLOAT64_C(  590.56),
                         SIMDE_FLOAT64_C(  522.53), SIMDE_FLOAT64_C(  340.37),
                         SIMDE_FLOAT64_C( -323.43), SIMDE_FLOAT64_C( -598.33)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -989.28), SIMDE_FLOAT64_C(   66.82),
                         SIMDE_FLOAT64_C(  747.55), SIMDE_FLOAT64_C(  590.56),
                         SIMDE_FLOAT64_C(  211.05), SIMDE_FLOAT64_C( -602.13),
                         SIMDE_FLOAT64_C( -323.43), SIMDE_FLOAT64_C( -598.33)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  435.94), SIMDE_FLOAT64_C( -117.09),
                         SIMDE_FLOAT64_C( -343.63), SIMDE_FLOAT64_C( -686.94),
                         SIMDE_FLOAT64_C( -632.13), SIMDE_FLOAT64_C(  520.11),
                         SIMDE_FLOAT64_C(  584.62), SIMDE_FLOAT64_C(  269.90)),
      UINT8_C(142),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -307.53), SIMDE_FLOAT64_C(  533.35),
                         SIMDE_FLOAT64_C( -283.32), SIMDE_FLOAT64_C(  860.26),
                         SIMDE_FLOAT64_C( -955.05), SIMDE_FLOAT64_C( -767.10),
                         SIMDE_FLOAT64_C( -553.49), SIMDE_FLOAT64_C(  540.17)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -307.53), SIMDE_FLOAT64_C( -117.09),
                         SIMDE_FLOAT64_C( -343.63), SIMDE_FLOAT64_C( -686.94),
                         SIMDE_FLOAT64_C( -955.05), SIMDE_FLOAT64_C( -767.10),
                         SIMDE_FLOAT64_C( -553.49), SIMDE_FLOAT64_C(  269.90)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  591.80), SIMDE_FLOAT64_C( -733.65),
                         SIMDE_FLOAT64_C(  371.96), SIMDE_FLOAT64_C( -998.26),
                         SIMDE_FLOAT64_C(   61.01), SIMDE_FLOAT64_C( -918.19),
                         SIMDE_FLOAT64_C( -797.48), SIMDE_FLOAT64_C(   81.07)),
      UINT8_C(155),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  378.17), SIMDE_FLOAT64_C(  574.36),
                         SIMDE_FLOAT64_C(  687.12), SIMDE_FLOAT64_C( -618.22),
                         SIMDE_FLOAT64_C(  388.77), SIMDE_FLOAT64_C( -731.92),
                         SIMDE_FLOAT64_C(  958.30), SIMDE_FLOAT64_C(   51.30)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  378.17), SIMDE_FLOAT64_C( -733.65),
                         SIMDE_FLOAT64_C(  371.96), SIMDE_FLOAT64_C( -618.22),
                         SIMDE_FLOAT64_C(  388.77), SIMDE_FLOAT64_C( -918.19),
                         SIMDE_FLOAT64_C(  958.30), SIMDE_FLOAT64_C(   51.30)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  721.16), SIMDE_FLOAT64_C(   21.28),
                         SIMDE_FLOAT64_C( -269.14), SIMDE_FLOAT64_C( -241.41),
                         SIMDE_FLOAT64_C( -307.10), SIMDE_FLOAT64_C(   78.73),
                         SIMDE_FLOAT64_C(  336.91), SIMDE_FLOAT64_C( -793.36)),
      UINT8_C(174),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  944.42), SIMDE_FLOAT64_C(  986.58),
                         SIMDE_FLOAT64_C( -765.43), SIMDE_FLOAT64_C(  392.41),
                         SIMDE_FLOAT64_C(  229.44), SIMDE_FLOAT64_C(   52.87),
                         SIMDE_FLOAT64_C( -238.79), SIMDE_FLOAT64_C(  440.21)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  944.42), SIMDE_FLOAT64_C(   21.28),
                         SIMDE_FLOAT64_C( -765.43), SIMDE_FLOAT64_C( -241.41),
                         SIMDE_FLOAT64_C(  229.44), SIMDE_FLOAT64_C(   52.87),
                         SIMDE_FLOAT64_C( -238.79), SIMDE_FLOAT64_C( -793.36)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  456.66), SIMDE_FLOAT64_C( -366.58),
                         SIMDE_FLOAT64_C(  715.22), SIMDE_FLOAT64_C(  -16.79),
                         SIMDE_FLOAT64_C( -320.68), SIMDE_FLOAT64_C(  273.81),
                         SIMDE_FLOAT64_C( -581.56), SIMDE_FLOAT64_C(  277.97)),
      UINT8_C(205),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.81), SIMDE_FLOAT64_C(  801.66),
                         SIMDE_FLOAT64_C(  310.16), SIMDE_FLOAT64_C(  634.68),
                         SIMDE_FLOAT64_C( -889.89), SIMDE_FLOAT64_C( -998.37),
                         SIMDE_FLOAT64_C( -493.27), SIMDE_FLOAT64_C(  120.40)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.81), SIMDE_FLOAT64_C(  801.66),
                         SIMDE_FLOAT64_C(  715.22), SIMDE_FLOAT64_C(  -16.79),
                         SIMDE_FLOAT64_C( -889.89), SIMDE_FLOAT64_C( -998.37),
                         SIMDE_FLOAT64_C( -581.56), SIMDE_FLOAT64_C(  120.40)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   44.26), SIMDE_FLOAT64_C(  891.25),
                         SIMDE_FLOAT64_C(  290.62), SIMDE_FLOAT64_C(  -70.18),
                         SIMDE_FLOAT64_C(   -3.54), SIMDE_FLOAT64_C(  783.54),
                         SIMDE_FLOAT64_C( -718.82), SIMDE_FLOAT64_C(  922.75)),
      UINT8_C( 72),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -286.94), SIMDE_FLOAT64_C( -573.68),
                         SIMDE_FLOAT64_C( -931.52), SIMDE_FLOAT64_C(  249.22),
                         SIMDE_FLOAT64_C(  735.88), SIMDE_FLOAT64_C(  653.72),
                         SIMDE_FLOAT64_C(  732.59), SIMDE_FLOAT64_C(  161.45)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   44.26), SIMDE_FLOAT64_C( -573.68),
                         SIMDE_FLOAT64_C(  290.62), SIMDE_FLOAT64_C(  -70.18),
                         SIMDE_FLOAT64_C(  735.88), SIMDE_FLOAT64_C(  783.54),
                         SIMDE_FLOAT64_C( -718.82), SIMDE_FLOAT64_C(  922.75)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  729.70), SIMDE_FLOAT64_C( -950.99),
                         SIMDE_FLOAT64_C(  115.61), SIMDE_FLOAT64_C( -132.19),
                         SIMDE_FLOAT64_C(  834.99), SIMDE_FLOAT64_C(  471.53),
                         SIMDE_FLOAT64_C(   54.12), SIMDE_FLOAT64_C(  238.73)),
      UINT8_C(209),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -345.93), SIMDE_FLOAT64_C(  598.65),
                         SIMDE_FLOAT64_C(  954.89), SIMDE_FLOAT64_C( -441.90),
                         SIMDE_FLOAT64_C(  845.52), SIMDE_FLOAT64_C( -659.44),
                         SIMDE_FLOAT64_C( -844.59), SIMDE_FLOAT64_C(  331.33)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -345.93), SIMDE_FLOAT64_C(  598.65),
                         SIMDE_FLOAT64_C(  115.61), SIMDE_FLOAT64_C( -441.90),
                         SIMDE_FLOAT64_C(  834.99), SIMDE_FLOAT64_C(  471.53),
                         SIMDE_FLOAT64_C(   54.12), SIMDE_FLOAT64_C(  331.33)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_mov_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_maskz_mov_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { UINT16_C(23562),
      simde_mm512_set_epi32(INT32_C(  413218138), INT32_C(-2056039012), INT32_C(  359898417), INT32_C(  503742711),
                            INT32_C( -964140572), INT32_C( 1845540628), INT32_C( 1555270769), INT32_C(  276306907),
                            INT32_C(  923961977), INT32_C( 2070870327), INT32_C( -106769082), INT32_C(   21505510),
                            INT32_C(-1894191102), INT32_C(  -61868066), INT32_C(-1022555483), INT32_C(  842262872)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(-2056039012), INT32_C(          0), INT32_C(  503742711),
                            INT32_C( -964140572), INT32_C( 1845540628), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1894191102), INT32_C(          0), INT32_C(-1022555483), INT32_C(          0)) },
    { UINT16_C(36203),
      simde_mm512_set_epi32(INT32_C(-1836353351), INT32_C(-1955161161), INT32_C( 1387065895), INT32_C(  829477081),
                            INT32_C( 1194773762), INT32_C( 1305535140), INT32_C(  692999175), INT32_C(-1162293370),
                            INT32_C( 1281198604), INT32_C( -270591140), INT32_C(   23870431), INT32_C(-1469107120),
                            INT32_C( 1859513610), INT32_C(-1425966851), INT32_C(  381161214), INT32_C(  706499700)),
      simde_mm512_set_epi32(INT32_C(-1836353351), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1194773762), INT32_C( 1305535140), INT32_C(          0), INT32_C(-1162293370),
                            INT32_C(          0), INT32_C( -270591140), INT32_C(   23870431), INT32_C(          0),
                            INT32_C( 1859513610), INT32_C(          0), INT32_C(  381161214), INT32_C(  706499700)) },
    { UINT16_C(61846),
      simde_mm512_set_epi32(INT32_C(-1731705333), INT32_C( 1975072423), INT32_C( -536413935), INT32_C( 1477835290),
                            INT32_C( 1453154713), INT32_C( -133697355), INT32_C( 1038848393), INT32_C(  897042603),
                            INT32_C( 1474696001), INT32_C( 1692444627), INT32_C(-1157569404), INT32_C(-1969459150),
                            INT32_C(  120064093), INT32_C(-1121934893), INT32_C( 1895180026), INT32_C( 1628067999)),
      simde_mm512_set_epi32(INT32_C(-1731705333), INT32_C( 1975072423), INT32_C( -536413935), INT32_C( 1477835290),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  897042603),
                            INT32_C( 1474696001), INT32_C(          0), INT32_C(          0), INT32_C(-1969459150),
                            INT32_C(          0), INT32_C(-1121934893), INT32_C( 1895180026), INT32_C(          0)) },
    { UINT16_C( 9005),
      simde_mm512_set_epi32(INT32_C(  317112464), INT32_C(  741023218), INT32_C(-1717304973), INT32_C( 1768422162),
                            INT32_C(-1938535542), INT32_C( -593182598), INT32_C( -560734377), INT32_C(-1833964883),
                            INT32_C(-2069017846), INT32_C( 1509337971), INT32_C(-1663080670), INT32_C( -363349477),
                            INT32_C( -761414190), INT32_C( 1575734613), INT32_C(  758160476), INT32_C(  434110055)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(-1717304973), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C( -560734377), INT32_C(-1833964883),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1663080670), INT32_C(          0),
                            INT32_C( -761414190), INT32_C( 1575734613), INT32_C(          0), INT32_C(  434110055)) },
    { UINT16_C(16381),
      simde_mm512_set_epi32(INT32_C(-1241873035), INT32_C(-1720080742), INT32_C( 1575508697), INT32_C(  644418481),
                            INT32_C( -191348066), INT32_C( 1363259829), INT32_C( -969945370), INT32_C(-1662256156),
                            INT32_C( -483657475), INT32_C( 1693775573), INT32_C( -588936550), INT32_C( -831491481),
                            INT32_C(-1533494499), INT32_C(  690127328), INT32_C( 1408818770), INT32_C( 1154640340)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C( 1575508697), INT32_C(  644418481),
                            INT32_C( -191348066), INT32_C( 1363259829), INT32_C( -969945370), INT32_C(-1662256156),
                            INT32_C( -483657475), INT32_C( 1693775573), INT32_C( -588936550), INT32_C( -831491481),
                            INT32_C(-1533494499), INT32_C(  690127328), INT32_C(          0), INT32_C( 1154640340)) },
    { UINT16_C(37447),
      simde_mm512_set_epi32(INT32_C(-2077483324), INT32_C( -857673646), INT32_C(  754202712), INT32_C(  120435698),
                            INT32_C(-1765652094), INT32_C( -229167588), INT32_C(-1388415734), INT32_C( -902383521),
                            INT32_C(-1071136130), INT32_C(  575343777), INT32_C( 2007077268), INT32_C( -686416210),
                            INT32_C( -979195146), INT32_C( -793664277), INT32_C( 1970531286), INT32_C( -266532300)),
      simde_mm512_set_epi32(INT32_C(-2077483324), INT32_C(          0), INT32_C(          0), INT32_C(  120435698),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1388415734), INT32_C(          0),
                            INT32_C(          0), INT32_C(  575343777), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( -793664277), INT32_C( 1970531286), INT32_C( -266532300)) },
    { UINT16_C(31625),
      simde_mm512_set_epi32(INT32_C(-1558092593), INT32_C(  725220263), INT32_C( 2072028486), INT32_C(-1343089166),
                            INT32_C(  151067474), INT32_C( 1411237194), INT32_C(-1069461255), INT32_C(   79796340),
                            INT32_C(  -81868792), INT32_C( -238630197), INT32_C(-1945013502), INT32_C( -908401887),
                            INT32_C( 1836974186), INT32_C(-1548825981), INT32_C( 1873806111), INT32_C(-2038561806)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  725220263), INT32_C( 2072028486), INT32_C(-1343089166),
                            INT32_C(  151067474), INT32_C(          0), INT32_C(-1069461255), INT32_C(   79796340),
                            INT32_C(  -81868792), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1836974186), INT32_C(          0), INT32_C(          0), INT32_C(-2038561806)) },
    { UINT16_C(29945),
      simde_mm512_set_epi32(INT32_C( 1874437031), INT32_C( 1791346696), INT32_C( 1351362877), INT32_C( 1434624201),
                            INT32_C( 1114612735), INT32_C(-2006574951), INT32_C( 1470768291), INT32_C( 1700301025),
                            INT32_C(  677818674), INT32_C( -624147248), INT32_C(  795562156), INT32_C(-1625864242),
                            INT32_C( -323693444), INT32_C(  242932397), INT32_C( 1315868789), INT32_C(-1134215759)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 1791346696), INT32_C( 1351362877), INT32_C( 1434624201),
                            INT32_C(          0), INT32_C(-2006574951), INT32_C(          0), INT32_C(          0),
                            INT32_C(  677818674), INT32_C( -624147248), INT32_C(  795562156), INT32_C(-1625864242),
                            INT32_C( -323693444), INT32_C(          0), INT32_C(          0), INT32_C(-1134215759)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_mov_epi32(test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_maskz_mov_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { UINT8_C(248),
      simde_mm512_set_epi64(INT64_C( 2197185227781835820), INT64_C(   15935016481556146),
                            INT64_C(-7676897351944758395), INT64_C( -396609189869225788),
                            INT64_C( 2033032872247713203), INT64_C(  196856286260699291),
                            INT64_C(-5445071775966286746), INT64_C( 4145146436042188996)),
      simde_mm512_set_epi64(INT64_C( 2197185227781835820), INT64_C(   15935016481556146),
                            INT64_C(-7676897351944758395), INT64_C( -396609189869225788),
                            INT64_C( 2033032872247713203), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C( 50),
      simde_mm512_set_epi64(INT64_C(-5159763787063667600), INT64_C( -806315631695634460),
                            INT64_C( 8295852346035342936), INT64_C(-3045923053405968902),
                            INT64_C( 8238548627246121972), INT64_C( 6711306137119169451),
                            INT64_C( 8909631005256860390), INT64_C(-3863575863957815519)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 8295852346035342936), INT64_C(-3045923053405968902),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 8909631005256860390), INT64_C(                   0)) },
    { UINT8_C(205),
      simde_mm512_set_epi64(INT64_C( -364876834429138531), INT64_C(-8701118401174655403),
                            INT64_C(-4225146583063624142), INT64_C( 1748175868453859972),
                            INT64_C(-2146322958238101234), INT64_C( 5260281165058225920),
                            INT64_C( 6150323032540537551), INT64_C( 7787131310828538951)),
      simde_mm512_set_epi64(INT64_C( -364876834429138531), INT64_C(-8701118401174655403),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-2146322958238101234), INT64_C( 5260281165058225920),
                            INT64_C(                   0), INT64_C( 7787131310828538951)) },
    { UINT8_C( 37),
      simde_mm512_set_epi64(INT64_C( 5789616018161199708), INT64_C( -189925922123546982),
                            INT64_C(-5486743783379366456), INT64_C(  576479268129213490),
                            INT64_C( 6799755442903924910), INT64_C( 8415809909668152758),
                            INT64_C(-5111257061290341882), INT64_C( -197393302827860380)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-5486743783379366456), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 8415809909668152758),
                            INT64_C(                   0), INT64_C( -197393302827860380)) },
    { UINT8_C( 88),
      simde_mm512_set_epi64(INT64_C(-1554832219963971622), INT64_C(-7375448098764531208),
                            INT64_C( 8161779997769921522), INT64_C( -561105360908971667),
                            INT64_C(-3236710360814756666), INT64_C( 5084844885557932166),
                            INT64_C(-5492461044876086653), INT64_C(-7792360489043648145)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(-7375448098764531208),
                            INT64_C(                   0), INT64_C( -561105360908971667),
                            INT64_C(-3236710360814756666), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C( 37),
      simde_mm512_set_epi64(INT64_C( 6519579675176262812), INT64_C(-7940748567058253670),
                            INT64_C( 6289445638826848684), INT64_C( 1300334437315413424),
                            INT64_C(-2416059830887765317), INT64_C(-5031784341515283026),
                            INT64_C( 8433369475758597766), INT64_C( 5881534320792150012)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 6289445638826848684), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(-5031784341515283026),
                            INT64_C(                   0), INT64_C( 5881534320792150012)) },
    { UINT8_C( 16),
      simde_mm512_set_epi64(INT64_C(-5091799924273173479), INT64_C(  326582266571623592),
                            INT64_C(-3763964521506166714), INT64_C( 4584033432636860229),
                            INT64_C(-1921935435734596553), INT64_C( 3382451871995350760),
                            INT64_C(  531323325001255908), INT64_C(-5053470530677804405)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( 4584033432636860229),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C( 33),
      simde_mm512_set_epi64(INT64_C(-6532064902097701697), INT64_C(-2430912179372724686),
                            INT64_C( 3177343060104491288), INT64_C(-7094318047719451166),
                            INT64_C(-3484792886859817284), INT64_C( -117759466073012358),
                            INT64_C( 8855057132598654557), INT64_C( -457984409854209760)),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 3177343060104491288), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C( -457984409854209760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_mov_epi64(test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_maskz_mov_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { UINT16_C(42363),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    27.87), SIMDE_FLOAT32_C(  -816.11), SIMDE_FLOAT32_C(   100.70), SIMDE_FLOAT32_C(  -687.21),
                         SIMDE_FLOAT32_C(   641.77), SIMDE_FLOAT32_C(   431.46), SIMDE_FLOAT32_C(  -432.41), SIMDE_FLOAT32_C(   128.97),
                         SIMDE_FLOAT32_C(   877.42), SIMDE_FLOAT32_C(   723.11), SIMDE_FLOAT32_C(   773.77), SIMDE_FLOAT32_C(   562.67),
                         SIMDE_FLOAT32_C(  -364.27), SIMDE_FLOAT32_C(   912.16), SIMDE_FLOAT32_C(  -872.01), SIMDE_FLOAT32_C(  -172.46)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    27.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   100.70), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   431.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   128.97),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   723.11), SIMDE_FLOAT32_C(   773.77), SIMDE_FLOAT32_C(   562.67),
                         SIMDE_FLOAT32_C(  -364.27), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -872.01), SIMDE_FLOAT32_C(  -172.46)) },
    { UINT16_C(38549),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   618.21), SIMDE_FLOAT32_C(   498.90), SIMDE_FLOAT32_C(  -849.91), SIMDE_FLOAT32_C(   -52.66),
                         SIMDE_FLOAT32_C(   545.34), SIMDE_FLOAT32_C(   794.02), SIMDE_FLOAT32_C(  -461.31), SIMDE_FLOAT32_C(   114.20),
                         SIMDE_FLOAT32_C(    86.28), SIMDE_FLOAT32_C(  -885.12), SIMDE_FLOAT32_C(   172.95), SIMDE_FLOAT32_C(   554.47),
                         SIMDE_FLOAT32_C(  -747.12), SIMDE_FLOAT32_C(  -745.25), SIMDE_FLOAT32_C(  -281.94), SIMDE_FLOAT32_C(   206.58)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   618.21), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -52.66),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   794.02), SIMDE_FLOAT32_C(  -461.31), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    86.28), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   554.47),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -745.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   206.58)) },
    { UINT16_C(52704),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   502.41), SIMDE_FLOAT32_C(   880.11), SIMDE_FLOAT32_C(  -557.95), SIMDE_FLOAT32_C(  -268.94),
                         SIMDE_FLOAT32_C(   733.29), SIMDE_FLOAT32_C(   706.04), SIMDE_FLOAT32_C(   -93.63), SIMDE_FLOAT32_C(  -582.14),
                         SIMDE_FLOAT32_C(  -836.38), SIMDE_FLOAT32_C(   744.38), SIMDE_FLOAT32_C(   -45.29), SIMDE_FLOAT32_C(  -703.39),
                         SIMDE_FLOAT32_C(  -540.13), SIMDE_FLOAT32_C(   467.24), SIMDE_FLOAT32_C(  -527.36), SIMDE_FLOAT32_C(   198.48)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   502.41), SIMDE_FLOAT32_C(   880.11), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   733.29), SIMDE_FLOAT32_C(   706.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -582.14),
                         SIMDE_FLOAT32_C(  -836.38), SIMDE_FLOAT32_C(   744.38), SIMDE_FLOAT32_C(   -45.29), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { UINT16_C(22254),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -71.03), SIMDE_FLOAT32_C(   476.98), SIMDE_FLOAT32_C(   846.87), SIMDE_FLOAT32_C(   538.39),
                         SIMDE_FLOAT32_C(   819.31), SIMDE_FLOAT32_C(  -703.74), SIMDE_FLOAT32_C(    35.79), SIMDE_FLOAT32_C(  -913.43),
                         SIMDE_FLOAT32_C(   774.49), SIMDE_FLOAT32_C(  -248.35), SIMDE_FLOAT32_C(  -966.82), SIMDE_FLOAT32_C(  -517.72),
                         SIMDE_FLOAT32_C(  -427.16), SIMDE_FLOAT32_C(  -808.81), SIMDE_FLOAT32_C(   888.05), SIMDE_FLOAT32_C(  -556.04)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   476.98), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   538.39),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -703.74), SIMDE_FLOAT32_C(    35.79), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   774.49), SIMDE_FLOAT32_C(  -248.35), SIMDE_FLOAT32_C(  -966.82), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -427.16), SIMDE_FLOAT32_C(  -808.81), SIMDE_FLOAT32_C(   888.05), SIMDE_FLOAT32_C(     0.00)) },
    { UINT16_C(52364),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   995.54), SIMDE_FLOAT32_C(   221.44), SIMDE_FLOAT32_C(   899.46), SIMDE_FLOAT32_C(   449.06),
                         SIMDE_FLOAT32_C(  -950.30), SIMDE_FLOAT32_C(  -151.76), SIMDE_FLOAT32_C(  -841.60), SIMDE_FLOAT32_C(    17.37),
                         SIMDE_FLOAT32_C(  -167.30), SIMDE_FLOAT32_C(  -256.21), SIMDE_FLOAT32_C(  -735.57), SIMDE_FLOAT32_C(  -164.68),
                         SIMDE_FLOAT32_C(   752.38), SIMDE_FLOAT32_C(   507.77), SIMDE_FLOAT32_C(  -277.52), SIMDE_FLOAT32_C(     4.35)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   995.54), SIMDE_FLOAT32_C(   221.44), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -950.30), SIMDE_FLOAT32_C(  -151.76), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -167.30), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   752.38), SIMDE_FLOAT32_C(   507.77), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { UINT16_C( 1779),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -523.28), SIMDE_FLOAT32_C(  -985.42), SIMDE_FLOAT32_C(    56.90), SIMDE_FLOAT32_C(   872.34),
                         SIMDE_FLOAT32_C(  -127.19), SIMDE_FLOAT32_C(   894.80), SIMDE_FLOAT32_C(   377.19), SIMDE_FLOAT32_C(  -135.98),
                         SIMDE_FLOAT32_C(   185.79), SIMDE_FLOAT32_C(   425.67), SIMDE_FLOAT32_C(  -947.39), SIMDE_FLOAT32_C(  -417.93),
                         SIMDE_FLOAT32_C(   872.23), SIMDE_FLOAT32_C(   491.12), SIMDE_FLOAT32_C(   994.51), SIMDE_FLOAT32_C(    86.62)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   894.80), SIMDE_FLOAT32_C(   377.19), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   185.79), SIMDE_FLOAT32_C(   425.67), SIMDE_FLOAT32_C(  -947.39), SIMDE_FLOAT32_C(  -417.93),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   994.51), SIMDE_FLOAT32_C(    86.62)) },
    { UINT16_C(13470),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   900.57), SIMDE_FLOAT32_C(   485.77), SIMDE_FLOAT32_C(   272.94), SIMDE_FLOAT32_C(  -275.02),
                         SIMDE_FLOAT32_C(  -912.01), SIMDE_FLOAT32_C(  -611.34), SIMDE_FLOAT32_C(   325.35), SIMDE_FLOAT32_C(  -148.93),
                         SIMDE_FLOAT32_C(  -884.16), SIMDE_FLOAT32_C(   545.87), SIMDE_FLOAT32_C(  -690.64), SIMDE_FLOAT32_C(   883.50),
                         SIMDE_FLOAT32_C(  -329.16), SIMDE_FLOAT32_C(  -369.50), SIMDE_FLOAT32_C(   429.82), SIMDE_FLOAT32_C(   530.37)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   272.94), SIMDE_FLOAT32_C(  -275.02),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -611.34), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -884.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   883.50),
                         SIMDE_FLOAT32_C(  -329.16), SIMDE_FLOAT32_C(  -369.50), SIMDE_FLOAT32_C(   429.82), SIMDE_FLOAT32_C(     0.00)) },
    { UINT16_C(25684),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   446.23), SIMDE_FLOAT32_C(  -618.66), SIMDE_FLOAT32_C(  -992.21), SIMDE_FLOAT32_C(  -692.36),
                         SIMDE_FLOAT32_C(  -952.61), SIMDE_FLOAT32_C(   923.35), SIMDE_FLOAT32_C(  -322.87), SIMDE_FLOAT32_C(   288.88),
                         SIMDE_FLOAT32_C(   653.23), SIMDE_FLOAT32_C(  -162.04), SIMDE_FLOAT32_C(   847.98), SIMDE_FLOAT32_C(  -826.91),
                         SIMDE_FLOAT32_C(  -738.77), SIMDE_FLOAT32_C(   279.48), SIMDE_FLOAT32_C(   397.18), SIMDE_FLOAT32_C(   127.10)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -618.66), SIMDE_FLOAT32_C(  -992.21), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   923.35), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -162.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -826.91),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   279.48), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_maskz_mov_ps(test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_maskz_mov_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {
    { UINT8_C(198),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -717.73), SIMDE_FLOAT64_C( -238.83),
                         SIMDE_FLOAT64_C( -181.88), SIMDE_FLOAT64_C( -183.39),
                         SIMDE_FLOAT64_C(  840.23), SIMDE_FLOAT64_C(  345.87),
                         SIMDE_FLOAT64_C(  630.37), SIMDE_FLOAT64_C(  306.75)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -717.73), SIMDE_FLOAT64_C( -238.83),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  345.87),
                         SIMDE_FLOAT64_C(  630.37), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(246),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -518.56), SIMDE_FLOAT64_C( -830.99),
                         SIMDE_FLOAT64_C(  129.34), SIMDE_FLOAT64_C(  771.89),
                         SIMDE_FLOAT64_C( -815.64), SIMDE_FLOAT64_C( -128.60),
                         SIMDE_FLOAT64_C( -244.79), SIMDE_FLOAT64_C( -568.94)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -518.56), SIMDE_FLOAT64_C( -830.99),
                         SIMDE_FLOAT64_C(  129.34), SIMDE_FLOAT64_C(  771.89),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -128.60),
                         SIMDE_FLOAT64_C( -244.79), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(141),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  637.67), SIMDE_FLOAT64_C(  322.55),
                         SIMDE_FLOAT64_C(  578.22), SIMDE_FLOAT64_C( -961.29),
                         SIMDE_FLOAT64_C(  737.15), SIMDE_FLOAT64_C(  475.09),
                         SIMDE_FLOAT64_C(  178.14), SIMDE_FLOAT64_C(  -60.04)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  637.67), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  737.15), SIMDE_FLOAT64_C(  475.09),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  -60.04)) },
    { UINT8_C(231),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  304.19), SIMDE_FLOAT64_C(  154.72),
                         SIMDE_FLOAT64_C(   74.11), SIMDE_FLOAT64_C(  -64.46),
                         SIMDE_FLOAT64_C(  202.28), SIMDE_FLOAT64_C( -444.38),
                         SIMDE_FLOAT64_C(  774.34), SIMDE_FLOAT64_C(  215.79)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  304.19), SIMDE_FLOAT64_C(  154.72),
                         SIMDE_FLOAT64_C(   74.11), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -444.38),
                         SIMDE_FLOAT64_C(  774.34), SIMDE_FLOAT64_C(  215.79)) },
    { UINT8_C( 62),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -983.34), SIMDE_FLOAT64_C(  259.69),
                         SIMDE_FLOAT64_C(  303.29), SIMDE_FLOAT64_C( -160.70),
                         SIMDE_FLOAT64_C( -787.06), SIMDE_FLOAT64_C(  198.77),
                         SIMDE_FLOAT64_C( -144.49), SIMDE_FLOAT64_C(  944.24)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  303.29), SIMDE_FLOAT64_C( -160.70),
                         SIMDE_FLOAT64_C( -787.06), SIMDE_FLOAT64_C(  198.77),
                         SIMDE_FLOAT64_C( -144.49), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(229),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -172.38), SIMDE_FLOAT64_C(  210.60),
                         SIMDE_FLOAT64_C(  840.69), SIMDE_FLOAT64_C(  875.33),
                         SIMDE_FLOAT64_C(  702.20), SIMDE_FLOAT64_C( -408.83),
                         SIMDE_FLOAT64_C(  172.51), SIMDE_FLOAT64_C(  896.66)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -172.38), SIMDE_FLOAT64_C(  210.60),
                         SIMDE_FLOAT64_C(  840.69), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -408.83),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  896.66)) },
    { UINT8_C( 93),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -853.39), SIMDE_FLOAT64_C(  281.51),
                         SIMDE_FLOAT64_C( -719.72), SIMDE_FLOAT64_C(  342.79),
                         SIMDE_FLOAT64_C( -679.92), SIMDE_FLOAT64_C( -623.46),
                         SIMDE_FLOAT64_C(  756.10), SIMDE_FLOAT64_C( -762.35)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  281.51),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  342.79),
                         SIMDE_FLOAT64_C( -679.92), SIMDE_FLOAT64_C( -623.46),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -762.35)) },
    { UINT8_C(156),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -853.45), SIMDE_FLOAT64_C(  527.42),
                         SIMDE_FLOAT64_C( -111.28), SIMDE_FLOAT64_C(  996.35),
                         SIMDE_FLOAT64_C(  374.30), SIMDE_FLOAT64_C(  314.59),
                         SIMDE_FLOAT64_C( -739.54), SIMDE_FLOAT64_C(  477.55)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -853.45), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  996.35),
                         SIMDE_FLOAT64_C(  374.30), SIMDE_FLOAT64_C(  314.59),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_maskz_mov_pd(test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_setzero_si512(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde_assert_m512i_i32(simde_mm512_setzero_si512(), ==, simde_mm512_set1_epi32(INT32_C(0)));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_setone_si512(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde_assert_m512i_i32(simde_mm512_setone_si512(), ==, simde_mm512_set1_epi32(~INT32_C(0)));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_test_epi32_mask(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask16 r;
  } test_vec[8] = {
    { UINT16_C(13733),
      simde_mm512_set_epi32(INT32_C(-1058044212), INT32_C( 1745554146), INT32_C( -938028173), INT32_C( 1123843978),
                            INT32_C(          0), INT32_C(  369104615), INT32_C(  288860030), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C( 1441724088), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C( -173456664), INT32_C(          0), INT32_C( 1847983972), INT32_C(          0),
                            INT32_C( 1618889484), INT32_C(-1607295283), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1566474746), INT32_C(          0), INT32_C(          0), INT32_C( -427236235),
                            INT32_C( 1934991438), INT32_C( -587656653), INT32_C(  -72145550), INT32_C(          0)),
      UINT16_C( 9216) },
    { UINT16_C(63633),
      simde_mm512_set_epi32(INT32_C( -839841286), INT32_C(          0), INT32_C(-1528318158), INT32_C(-1752243244),
                            INT32_C(          0), INT32_C(-1210241348), INT32_C(-1908519219), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(  521483609), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  543914332),
                            INT32_C( 2140721152), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      UINT16_C( 4096) },
    { UINT16_C(46032),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  329000619),
                            INT32_C(-1407469850), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -102278232), INT32_C(   43450551), INT32_C(          0), INT32_C( 1603148048),
                            INT32_C(          0), INT32_C(  306941628), INT32_C(          0), INT32_C( 1716086600)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( -262488052), INT32_C(          0), INT32_C( -979944078),
                            INT32_C(          0), INT32_C(          0), INT32_C( -671140903), INT32_C( 2141932562),
                            INT32_C( -937827627), INT32_C( -402281975), INT32_C( 1596901579), INT32_C(  735909604),
                            INT32_C(          0), INT32_C(-1202496908), INT32_C(          0), INT32_C( 1187626051)),
      UINT16_C( 4304) },
    { UINT16_C(22689),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C( 1163951893), INT32_C(          0),
                            INT32_C(          0), INT32_C( -972105386), INT32_C(          0), INT32_C( -189029459),
                            INT32_C( -225058862), INT32_C(-1537122616), INT32_C(          0), INT32_C(-1756788873),
                            INT32_C(          0), INT32_C(          0), INT32_C( -184793757), INT32_C( 1418114595)),
      simde_mm512_set_epi32(INT32_C(-1354385088), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1841164366), INT32_C(  -94325362), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(  594617140), INT32_C(          0),
                            INT32_C(  239227634), INT32_C(          0), INT32_C(  895132574), INT32_C( -123965580)),
      UINT16_C(    1) },
    { UINT16_C(25521),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 1916556758), INT32_C(  729046451), INT32_C(  516587379),
                            INT32_C( 1306886393), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( 2010256146), INT32_C( -351991039), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C(-1549799175), INT32_C( -926637576), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1633420708), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1070649171), INT32_C( -629074644),
                            INT32_C( -658686596), INT32_C( 1058031607), INT32_C(          0), INT32_C(  590507721)),
      UINT16_C(16416) },
    { UINT16_C(62461),
      simde_mm512_set_epi32(INT32_C(-1777930200), INT32_C(-2074304971), INT32_C(-1238248254), INT32_C(          0),
                            INT32_C(          0), INT32_C(-2126101806), INT32_C( 1488735838), INT32_C(-1941730876),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1287988933), INT32_C( -234166092),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( 1899039383)),
      simde_mm512_set_epi32(INT32_C(-2019508611), INT32_C(          0), INT32_C(  630346390), INT32_C( 1865079685),
                            INT32_C( -135665525), INT32_C(          0), INT32_C(  751170486), INT32_C(  580518147),
                            INT32_C(  875750845), INT32_C(  263799439), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( -889468036), INT32_C(  606319308), INT32_C(          0)),
      UINT16_C(41728) },
    { UINT16_C(64894),
      simde_mm512_set_epi32(INT32_C( 1983606396), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1668321234), INT32_C( 1230207891), INT32_C(-1334904081), INT32_C(-1369460101),
                            INT32_C(          0), INT32_C(          0), INT32_C(  556969985), INT32_C(  844640930),
                            INT32_C(-1447169687), INT32_C( -621740127), INT32_C( 1847803343), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( -578157153),
                            INT32_C(          0), INT32_C(-1740019927), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(  136767631), INT32_C(          0), INT32_C(-1994887012),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-1203448248)),
      UINT16_C( 1040) },
    { UINT16_C(   72),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( -302271050), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1073370549), INT32_C(  911478852), INT32_C( 2032788905), INT32_C(          0),
                            INT32_C(  398076492), INT32_C(  901163928), INT32_C(          0), INT32_C(-1022133203),
                            INT32_C( -345543230), INT32_C(          0), INT32_C( 2110415254), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 1062395075), INT32_C( -125220770), INT32_C(          0),
                            INT32_C(          0), INT32_C(-1603705335), INT32_C(-1563808089), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1591467282), INT32_C(  -57010818), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1904594022), INT32_C(          0), INT32_C( -170170916)),
      UINT16_C(   64) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_mask_test_epi32_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    munit_assert_uint16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_add_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( -620437579), INT32_C( -723756998), INT32_C( 2089862132), INT32_C(  928615324),
                            INT32_C( 1352582940), INT32_C( 1412449807), INT32_C( -180438223), INT32_C( 1987031180),
                            INT32_C( -515955035), INT32_C( 1724776466), INT32_C(  534751449), INT32_C(  -23608579),
                            INT32_C(-1857730421), INT32_C(-2108373984), INT32_C(-2047745621), INT32_C(-1616522706)),
      simde_mm512_set_epi32(INT32_C(-1828719907), INT32_C(-1665857743), INT32_C(  633675792), INT32_C(  -87619707),
                            INT32_C(  206282352), INT32_C(-1301173823), INT32_C(-1377624366), INT32_C(-1722858856),
                            INT32_C(-1747195587), INT32_C(-1421499089), INT32_C(-1466275595), INT32_C( 1005942821),
                            INT32_C(  653597122), INT32_C( 1511265780), INT32_C(-1057049813), INT32_C(  988582315)),
      simde_mm512_set_epi32(INT32_C( 1845809810), INT32_C( 1905352555), INT32_C(-1571429372), INT32_C(  840995617),
                            INT32_C( 1558865292), INT32_C(  111275984), INT32_C(-1558062589), INT32_C(  264172324),
                            INT32_C( 2031816674), INT32_C(  303277377), INT32_C( -931524146), INT32_C(  982334242),
                            INT32_C(-1204133299), INT32_C( -597108204), INT32_C( 1190171862), INT32_C( -627940391)) },
    { simde_mm512_set_epi32(INT32_C(-1937590036), INT32_C( -332801366), INT32_C( -471964647), INT32_C(-1821490876),
                            INT32_C( -730720612), INT32_C( -212155491), INT32_C(  557730573), INT32_C( 1419303203),
                            INT32_C( -649726768), INT32_C(-1343949182), INT32_C(  543388357), INT32_C( 2016683828),
                            INT32_C(-1787609785), INT32_C( 1170714264), INT32_C( 1838698095), INT32_C( -610530733)),
      simde_mm512_set_epi32(INT32_C(  -78760490), INT32_C(-1762700896), INT32_C(  743846170), INT32_C( 2011763261),
                            INT32_C( -319606822), INT32_C( -887822109), INT32_C(  843030788), INT32_C( 1100063012),
                            INT32_C( 1306201477), INT32_C( -328092402), INT32_C(  760791953), INT32_C( 1607075963),
                            INT32_C(-2029269339), INT32_C(-1246855319), INT32_C(  373846974), INT32_C(-2039859469)),
      simde_mm512_set_epi32(INT32_C(-2016350526), INT32_C(-2095502262), INT32_C(  271881523), INT32_C(  190272385),
                            INT32_C(-1050327434), INT32_C(-1099977600), INT32_C( 1400761361), INT32_C(-1775601081),
                            INT32_C(  656474709), INT32_C(-1672041584), INT32_C( 1304180310), INT32_C( -671207505),
                            INT32_C(  478088172), INT32_C(  -76141055), INT32_C(-2082422227), INT32_C( 1644577094)) },
    { simde_mm512_set_epi32(INT32_C(   57776624), INT32_C( 1788183002), INT32_C(-1974433832), INT32_C(-1794133389),
                            INT32_C(-1069162986), INT32_C(-1427272558), INT32_C(-1253805688), INT32_C( -660872028),
                            INT32_C(-1129884149), INT32_C(  173413635), INT32_C( 2028757327), INT32_C( 1565906228),
                            INT32_C(-2137992833), INT32_C(-1203890748), INT32_C(  706474135), INT32_C(-1778193688)),
      simde_mm512_set_epi32(INT32_C( -515592024), INT32_C( -146353312), INT32_C(  242268084), INT32_C( -988968038),
                            INT32_C(-2038559805), INT32_C(   54811004), INT32_C( 1173402348), INT32_C(  422621509),
                            INT32_C(  566804477), INT32_C( 1847170418), INT32_C( -922088165), INT32_C( -324583669),
                            INT32_C( 2069465832), INT32_C(-1437889074), INT32_C(  238343196), INT32_C( 1745183762)),
      simde_mm512_set_epi32(INT32_C( -457815400), INT32_C( 1641829690), INT32_C(-1732165748), INT32_C( 1511865869),
                            INT32_C( 1187244505), INT32_C(-1372461554), INT32_C(  -80403340), INT32_C( -238250519),
                            INT32_C( -563079672), INT32_C( 2020584053), INT32_C( 1106669162), INT32_C( 1241322559),
                            INT32_C(  -68527001), INT32_C( 1653187474), INT32_C(  944817331), INT32_C(  -33009926)) },
    { simde_mm512_set_epi32(INT32_C( 1004166983), INT32_C(-2037237484), INT32_C(  975969300), INT32_C(  221374965),
                            INT32_C( -878025387), INT32_C( 1166912453), INT32_C( 1981901973), INT32_C(  976355918),
                            INT32_C( 1384872269), INT32_C(  -15473064), INT32_C( -289026084), INT32_C( 1652811113),
                            INT32_C( 2056881111), INT32_C( 1621101202), INT32_C( 1517253606), INT32_C( 1625264348)),
      simde_mm512_set_epi32(INT32_C(-1184683174), INT32_C(  619504240), INT32_C(-1150416788), INT32_C(-1085597388),
                            INT32_C( 1766693029), INT32_C( 1152891465), INT32_C(-2035468310), INT32_C( 1319983622),
                            INT32_C(-1615386348), INT32_C(  261012444), INT32_C(  223560144), INT32_C(  331591481),
                            INT32_C(  -33325842), INT32_C( -398184636), INT32_C( 1301281245), INT32_C(-1280622867)),
      simde_mm512_set_epi32(INT32_C( -180516191), INT32_C(-1417733244), INT32_C( -174447488), INT32_C( -864222423),
                            INT32_C(  888667642), INT32_C(-1975163378), INT32_C(  -53566337), INT32_C(-1998627756),
                            INT32_C( -230514079), INT32_C(  245539380), INT32_C(  -65465940), INT32_C( 1984402594),
                            INT32_C( 2023555269), INT32_C( 1222916566), INT32_C(-1476432445), INT32_C(  344641481)) },
    { simde_mm512_set_epi32(INT32_C(  -99917228), INT32_C(  209251690), INT32_C(  108789393), INT32_C(-1056574639),
                            INT32_C(  178125384), INT32_C( 1688380363), INT32_C( -910324723), INT32_C( 1731780669),
                            INT32_C( 1989188149), INT32_C(  999202624), INT32_C(  198474190), INT32_C( 1270934715),
                            INT32_C( -715363116), INT32_C( 1839116730), INT32_C(  -53141198), INT32_C( -590771199)),
      simde_mm512_set_epi32(INT32_C(  -77041932), INT32_C(  927171423), INT32_C( -178390373), INT32_C(-1958045464),
                            INT32_C( 1172980373), INT32_C(-1805733723), INT32_C( -859792119), INT32_C( 1334306095),
                            INT32_C(-1717931855), INT32_C( -244574814), INT32_C( 1638507066), INT32_C( -551865858),
                            INT32_C( -152534880), INT32_C(-1198583052), INT32_C( -869344314), INT32_C(-1920653371)),
      simde_mm512_set_epi32(INT32_C( -176959160), INT32_C( 1136423113), INT32_C(  -69600980), INT32_C( 1280347193),
                            INT32_C( 1351105757), INT32_C( -117353360), INT32_C(-1770116842), INT32_C(-1228880532),
                            INT32_C(  271256294), INT32_C(  754627810), INT32_C( 1836981256), INT32_C(  719068857),
                            INT32_C( -867897996), INT32_C(  640533678), INT32_C( -922485512), INT32_C( 1783542726)) },
    { simde_mm512_set_epi32(INT32_C(-1801907952), INT32_C(  126986794), INT32_C( 2099256067), INT32_C(  915807861),
                            INT32_C( -313053214), INT32_C( 1205934161), INT32_C(   25151882), INT32_C( -823105542),
                            INT32_C(-1390117486), INT32_C(  385956806), INT32_C( 1986964939), INT32_C(   56415632),
                            INT32_C(-1186749471), INT32_C( 1048153466), INT32_C( 1387660497), INT32_C( 2108528480)),
      simde_mm512_set_epi32(INT32_C(-1572695910), INT32_C(  592114445), INT32_C(  -85836842), INT32_C(-1721616170),
                            INT32_C(  222979620), INT32_C( -376092888), INT32_C(  405576062), INT32_C(  902804532),
                            INT32_C( 2135373993), INT32_C( 1677980182), INT32_C(-1127993042), INT32_C( -771911734),
                            INT32_C(  -41719457), INT32_C(-1772059837), INT32_C(-1722167164), INT32_C(  812561930)),
      simde_mm512_set_epi32(INT32_C(  920363434), INT32_C(  719101239), INT32_C( 2013419225), INT32_C( -805808309),
                            INT32_C(  -90073594), INT32_C(  829841273), INT32_C(  430727944), INT32_C(   79698990),
                            INT32_C(  745256507), INT32_C( 2063936988), INT32_C(  858971897), INT32_C( -715496102),
                            INT32_C(-1228468928), INT32_C( -723906371), INT32_C( -334506667), INT32_C(-1373876886)) },
    { simde_mm512_set_epi32(INT32_C(  -87552733), INT32_C( -497247153), INT32_C( 1468487386), INT32_C( 1003068863),
                            INT32_C( 1747861143), INT32_C( -646367560), INT32_C( -755743025), INT32_C(  683078293),
                            INT32_C( 1090643160), INT32_C( 1972147188), INT32_C(-2077095609), INT32_C(  731411049),
                            INT32_C( -484220816), INT32_C( -672982839), INT32_C(  -64061145), INT32_C(-1731914804)),
      simde_mm512_set_epi32(INT32_C( 1287212577), INT32_C(  799931806), INT32_C(  620076827), INT32_C(  806976960),
                            INT32_C(-1787684636), INT32_C(  -68422538), INT32_C(  591651588), INT32_C( 2136172897),
                            INT32_C(  538232126), INT32_C( 1910632119), INT32_C(  280273419), INT32_C( 1179224181),
                            INT32_C( -178809858), INT32_C(-1741617588), INT32_C(-2045147428), INT32_C( 1639562384)),
      simde_mm512_set_epi32(INT32_C( 1199659844), INT32_C(  302684653), INT32_C( 2088564213), INT32_C( 1810045823),
                            INT32_C(  -39823493), INT32_C( -714790098), INT32_C( -164091437), INT32_C(-1475716106),
                            INT32_C( 1628875286), INT32_C( -412187989), INT32_C(-1796822190), INT32_C( 1910635230),
                            INT32_C( -663030674), INT32_C( 1880366869), INT32_C(-2109208573), INT32_C(  -92352420)) },
    { simde_mm512_set_epi32(INT32_C(  446376492), INT32_C( 1910481415), INT32_C(  625332216), INT32_C(  541212187),
                            INT32_C(  298536203), INT32_C(-1502376568), INT32_C( -699613431), INT32_C( -125340207),
                            INT32_C( -849753035), INT32_C( -538074567), INT32_C( 1356067945), INT32_C( 1088886620),
                            INT32_C(-1643178888), INT32_C(  855336737), INT32_C( 1638140255), INT32_C(-2120465324)),
      simde_mm512_set_epi32(INT32_C( 1091209248), INT32_C(-1950373665), INT32_C(-2108427702), INT32_C(  969460626),
                            INT32_C(  438255242), INT32_C( -807569468), INT32_C( -746566484), INT32_C( 1685713375),
                            INT32_C(   93210471), INT32_C( 1249365881), INT32_C(  945726578), INT32_C( 1471824111),
                            INT32_C( 1944720672), INT32_C(-1780061567), INT32_C( 1132193802), INT32_C(  151873348)),
      simde_mm512_set_epi32(INT32_C( 1537585740), INT32_C(  -39892250), INT32_C(-1483095486), INT32_C( 1510672813),
                            INT32_C(  736791445), INT32_C( 1985021260), INT32_C(-1446179915), INT32_C( 1560373168),
                            INT32_C( -756542564), INT32_C(  711291314), INT32_C(-1993172773), INT32_C(-1734256565),
                            INT32_C(  301541784), INT32_C( -924724830), INT32_C(-1524633239), INT32_C(-1968591976)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_add_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_add_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-1142113623186190173), INT64_C( 2669401519388559587),
                            INT64_C(-4041526363448340541), INT64_C( 8890984525115992605),
                            INT64_C( 3710059072002351182), INT64_C(   -8844419669430530),
                            INT64_C( -583435793687448962), INT64_C(-3776976191330287246)),
      simde_mm512_set_epi64(INT64_C(-2572258444501888207), INT64_C( 8010943607820280661),
                            INT64_C(-7896534424393030159), INT64_C( 8282192647960665352),
                            INT64_C(  811312670062340262), INT64_C(-8174776120225966748),
                            INT64_C( 4815827375621462801), INT64_C(-4343109153599957409)),
      simde_mm512_set_epi64(INT64_C(-3714372067688078380), INT64_C(-7766398946500711368),
                            INT64_C( 6508683285868180916), INT64_C(-1273566900632893659),
                            INT64_C( 4521371742064691444), INT64_C(-8183620539895397278),
                            INT64_C( 4232391581934013839), INT64_C(-8120085344930244655)) },
    { simde_mm512_set_epi64(INT64_C(-8907763853043432709), INT64_C(-7664489506315516041),
                            INT64_C( 7881121837601630619), INT64_C(-1123258072002783793),
                            INT64_C( 6852591379280896525), INT64_C(-3366432558441729450),
                            INT64_C(-5990500579016281828), INT64_C( 7624785959951223888)),
      simde_mm512_set_epi64(INT64_C(  530774369540308193), INT64_C( 4966843317235809520),
                            INT64_C(-4575853019860390176), INT64_C(-5468596229394507748),
                            INT64_C( 5016860099104730248), INT64_C(-4030848910458752721),
                            INT64_C(-5726415349997053878), INT64_C(-2689606844288066445)),
      simde_mm512_set_epi64(INT64_C(-8376989483503124516), INT64_C(-2697646189079706521),
                            INT64_C( 3305268817741240443), INT64_C(-6591854301397291541),
                            INT64_C(-6577292595323924843), INT64_C(-7397281468900482171),
                            INT64_C( 6729828144696215910), INT64_C( 4935179115663157443)) },
    { simde_mm512_set_epi64(INT64_C(-1147603065405303411), INT64_C(-7360179338648948250),
                            INT64_C( 8522846282553983063), INT64_C(-6411739365277986684),
                            INT64_C( 2565410720902708591), INT64_C(-6999797153964411090),
                            INT64_C(-4638909294820957529), INT64_C(-6689250119856274996)),
      simde_mm512_set_epi64(INT64_C( 5073596640780038992), INT64_C( 9103358253828460511),
                            INT64_C( -705008066916281166), INT64_C(-6536611133780086738),
                            INT64_C( 8265445360104219638), INT64_C( 3801153343625786085),
                            INT64_C( 2669262289718667251), INT64_C( 5656097673759919545)),
      simde_mm512_set_epi64(INT64_C( 3925993575374735581), INT64_C( 1743178915179512261),
                            INT64_C( 7817838215637701897), INT64_C( 5498393574651478194),
                            INT64_C(-7615887992702623387), INT64_C(-3198643810338625005),
                            INT64_C(-1969647005102290278), INT64_C(-1033152446096355451)) },
    { simde_mm512_set_epi64(INT64_C( 4726294533983517199), INT64_C(-3194102718522779616),
                            INT64_C( 7968557550946485055), INT64_C( 3231249301417879275),
                            INT64_C( 2730855362291069772), INT64_C(-7006805907158396614),
                            INT64_C( 7013656719434070104), INT64_C(-5111614041831206337)),
      simde_mm512_set_epi64(INT64_C( 8077331611956864824), INT64_C( 9219505211765165401),
                            INT64_C( -526170803618465025), INT64_C(-6117963664293386621),
                            INT64_C( 8138058063794249913), INT64_C(-6512904449490940829),
                            INT64_C(  474025353181411678), INT64_C(-7774133174508991700)),
      simde_mm512_set_epi64(INT64_C(-5643117927769169593), INT64_C( 6025402493242385785),
                            INT64_C( 7442386747328020030), INT64_C(-2886714362875507346),
                            INT64_C(-7577830647624231931), INT64_C( 4927033717060214173),
                            INT64_C( 7487682072615481782), INT64_C( 5560996857369353579)) },
    { simde_mm512_set_epi64(INT64_C(  193050968130854053), INT64_C( 8259941741302086974),
                            INT64_C( -453186687001595332), INT64_C( 7712011730228920808),
                            INT64_C(-6104336988767299426), INT64_C( 5308601606176372502),
                            INT64_C(-2287583704165123047), INT64_C( 5680091922249770976)),
      simde_mm512_set_epi64(INT64_C(-4961468284661849310), INT64_C( 9060485449513062801),
                            INT64_C( 6632655590889112567), INT64_C( 7501604346789135910),
                            INT64_C(-7298384925887684809), INT64_C( 2881824411969821346),
                            INT64_C(-8132400455203655002), INT64_C( 4133962836264448240)),
      simde_mm512_set_epi64(INT64_C(-4768417316530995257), INT64_C(-1126316882894401841),
                            INT64_C( 6179468903887517235), INT64_C(-3233127996691494898),
                            INT64_C( 5044022159054567381), INT64_C( 8190426018146193848),
                            INT64_C( 8026759914340773567), INT64_C(-8632689315195332400)) },
    { simde_mm512_set_epi64(INT64_C( 8956245117105388401), INT64_C(-1279259458875765791),
                            INT64_C(-4844132309560126483), INT64_C( 8020518294074851688),
                            INT64_C(-5641381585453289469), INT64_C(-7336114943591686134),
                            INT64_C( 7396026256462185783), INT64_C(-7159923149096431079)),
      simde_mm512_set_epi64(INT64_C( 7681308578881334632), INT64_C( 6762384852768739876),
                            INT64_C(-6630226433339556438), INT64_C(  895229301334345958),
                            INT64_C( 8748757877138934431), INT64_C(-3406024454166778034),
                            INT64_C(-1971110785327035786), INT64_C( 5257409320594533793)),
      simde_mm512_set_epi64(INT64_C(-1809190377722828583), INT64_C( 5483125393892974085),
                            INT64_C( 6972385330809868695), INT64_C( 8915747595409197646),
                            INT64_C( 3107376291685644962), INT64_C( 7704604675951087448),
                            INT64_C( 5424915471135149997), INT64_C(-1902513828501897286)) },
    { simde_mm512_set_epi64(INT64_C(-6379556098233125245), INT64_C(-7036815414983308437),
                            INT64_C( 6449458293699998062), INT64_C(-8662596582560742605),
                            INT64_C( 8559396047271930933), INT64_C( 8319158628050257118),
                            INT64_C( 2671429253434382084), INT64_C(-3771778240982532322)),
      simde_mm512_set_epi64(INT64_C( 4847839000068024729), INT64_C( 7410858097550413452),
                            INT64_C( -481636656067004168), INT64_C(  273087245529831397),
                            INT64_C( 2014413537357415871), INT64_C(-3897516487309028112),
                            INT64_C( 4133432427690444225), INT64_C(-7762159775807857014)),
      simde_mm512_set_epi64(INT64_C(-1531717098165100516), INT64_C(  374042682567105015),
                            INT64_C( 5967821637632993894), INT64_C(-8389509337030911208),
                            INT64_C(-7872934489080204812), INT64_C( 4421642140741229006),
                            INT64_C( 6804861681124826309), INT64_C( 6912806056919162280)) },
    { simde_mm512_set_epi64(INT64_C( 7044617451253925485), INT64_C( 8554512071902279421),
                            INT64_C(-5774887429267945902), INT64_C( 8744694126758591835),
                            INT64_C( 6726346195930174353), INT64_C(-3624175965481610004),
                            INT64_C(-2980185457068069894), INT64_C(-1599338563378690807)),
      simde_mm512_set_epi64(INT64_C( 7457111512897216818), INT64_C(-2685664891179263207),
                            INT64_C( 3286698240604454682), INT64_C( 1197616399803304076),
                            INT64_C(-5755426011606503746), INT64_C(-7010024580994263662),
                            INT64_C(-1798652028950367168), INT64_C( 1422740686196608462)),
      simde_mm512_set_epi64(INT64_C(-3945015109558409313), INT64_C( 5868847180723016214),
                            INT64_C(-2488189188663491220), INT64_C(-8504433547147655705),
                            INT64_C(  970920184323670607), INT64_C( 7812543527233677950),
                            INT64_C(-4778837486018437062), INT64_C( -176597877182082345)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_add_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_add_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -546.47), SIMDE_FLOAT32_C(  -401.21), SIMDE_FLOAT32_C(  -240.00), SIMDE_FLOAT32_C(  -513.10),
                         SIMDE_FLOAT32_C(  -121.28), SIMDE_FLOAT32_C(   728.43), SIMDE_FLOAT32_C(  -822.51), SIMDE_FLOAT32_C(     7.45),
                         SIMDE_FLOAT32_C(   960.90), SIMDE_FLOAT32_C(   805.67), SIMDE_FLOAT32_C(  -690.58), SIMDE_FLOAT32_C(   568.90),
                         SIMDE_FLOAT32_C(  -289.09), SIMDE_FLOAT32_C(  -506.27), SIMDE_FLOAT32_C(  -651.61), SIMDE_FLOAT32_C(   163.00)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   732.60), SIMDE_FLOAT32_C(   -88.88), SIMDE_FLOAT32_C(   508.96), SIMDE_FLOAT32_C(   -54.22),
                         SIMDE_FLOAT32_C(    -9.60), SIMDE_FLOAT32_C(   -95.16), SIMDE_FLOAT32_C(  -147.10), SIMDE_FLOAT32_C(   920.71),
                         SIMDE_FLOAT32_C(  -406.34), SIMDE_FLOAT32_C(   822.42), SIMDE_FLOAT32_C(    -9.72), SIMDE_FLOAT32_C(  -576.02),
                         SIMDE_FLOAT32_C(  -438.73), SIMDE_FLOAT32_C(  -733.21), SIMDE_FLOAT32_C(  -238.85), SIMDE_FLOAT32_C(   207.13)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   186.13), SIMDE_FLOAT32_C(  -490.09), SIMDE_FLOAT32_C(   268.96), SIMDE_FLOAT32_C(  -567.32),
                         SIMDE_FLOAT32_C(  -130.88), SIMDE_FLOAT32_C(   633.27), SIMDE_FLOAT32_C(  -969.61), SIMDE_FLOAT32_C(   928.16),
                         SIMDE_FLOAT32_C(   554.56), SIMDE_FLOAT32_C(  1628.09), SIMDE_FLOAT32_C(  -700.30), SIMDE_FLOAT32_C(    -7.12),
                         SIMDE_FLOAT32_C(  -727.82), SIMDE_FLOAT32_C( -1239.48), SIMDE_FLOAT32_C(  -890.46), SIMDE_FLOAT32_C(   370.13)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -926.20), SIMDE_FLOAT32_C(   375.14), SIMDE_FLOAT32_C(   940.73), SIMDE_FLOAT32_C(  -720.51),
                         SIMDE_FLOAT32_C(  -257.05), SIMDE_FLOAT32_C(   669.48), SIMDE_FLOAT32_C(    29.10), SIMDE_FLOAT32_C(   763.38),
                         SIMDE_FLOAT32_C(  -968.83), SIMDE_FLOAT32_C(   846.48), SIMDE_FLOAT32_C(  -399.89), SIMDE_FLOAT32_C(   648.70),
                         SIMDE_FLOAT32_C(   190.06), SIMDE_FLOAT32_C(  -421.71), SIMDE_FLOAT32_C(  -916.40), SIMDE_FLOAT32_C(   249.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -941.68), SIMDE_FLOAT32_C(  -700.28), SIMDE_FLOAT32_C(    37.43), SIMDE_FLOAT32_C(  -320.67),
                         SIMDE_FLOAT32_C(  -363.05), SIMDE_FLOAT32_C(   846.07), SIMDE_FLOAT32_C(   806.96), SIMDE_FLOAT32_C(   -60.84),
                         SIMDE_FLOAT32_C(   730.53), SIMDE_FLOAT32_C(   987.80), SIMDE_FLOAT32_C(   378.07), SIMDE_FLOAT32_C(  -394.92),
                         SIMDE_FLOAT32_C(   567.33), SIMDE_FLOAT32_C(   -54.37), SIMDE_FLOAT32_C(  -977.08), SIMDE_FLOAT32_C(  -714.42)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C( -1867.88), SIMDE_FLOAT32_C(  -325.14), SIMDE_FLOAT32_C(   978.16), SIMDE_FLOAT32_C( -1041.18),
                         SIMDE_FLOAT32_C(  -620.10), SIMDE_FLOAT32_C(  1515.55), SIMDE_FLOAT32_C(   836.06), SIMDE_FLOAT32_C(   702.54),
                         SIMDE_FLOAT32_C(  -238.30), SIMDE_FLOAT32_C(  1834.28), SIMDE_FLOAT32_C(   -21.82), SIMDE_FLOAT32_C(   253.78),
                         SIMDE_FLOAT32_C(   757.39), SIMDE_FLOAT32_C(  -476.08), SIMDE_FLOAT32_C( -1893.48), SIMDE_FLOAT32_C(  -464.73)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -240.64), SIMDE_FLOAT32_C(  -901.13), SIMDE_FLOAT32_C(   248.79), SIMDE_FLOAT32_C(  -761.42),
                         SIMDE_FLOAT32_C(   -34.99), SIMDE_FLOAT32_C(   819.20), SIMDE_FLOAT32_C(  -715.24), SIMDE_FLOAT32_C(  -958.36),
                         SIMDE_FLOAT32_C(  -876.64), SIMDE_FLOAT32_C(   224.96), SIMDE_FLOAT32_C(  -241.32), SIMDE_FLOAT32_C(  -833.06),
                         SIMDE_FLOAT32_C(  -928.34), SIMDE_FLOAT32_C(   822.01), SIMDE_FLOAT32_C(   -16.05), SIMDE_FLOAT32_C(  -241.91)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -998.98), SIMDE_FLOAT32_C(   951.38), SIMDE_FLOAT32_C(  -528.70), SIMDE_FLOAT32_C(  -961.34),
                         SIMDE_FLOAT32_C(  -781.68), SIMDE_FLOAT32_C(   919.38), SIMDE_FLOAT32_C(   660.71), SIMDE_FLOAT32_C(   -29.22),
                         SIMDE_FLOAT32_C(  -977.96), SIMDE_FLOAT32_C(  -923.68), SIMDE_FLOAT32_C(    -3.15), SIMDE_FLOAT32_C(  -732.59),
                         SIMDE_FLOAT32_C(  -504.08), SIMDE_FLOAT32_C(   111.05), SIMDE_FLOAT32_C(   700.38), SIMDE_FLOAT32_C(  -844.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C( -1239.62), SIMDE_FLOAT32_C(    50.25), SIMDE_FLOAT32_C(  -279.91), SIMDE_FLOAT32_C( -1722.76),
                         SIMDE_FLOAT32_C(  -816.67), SIMDE_FLOAT32_C(  1738.58), SIMDE_FLOAT32_C(   -54.53), SIMDE_FLOAT32_C(  -987.58),
                         SIMDE_FLOAT32_C( -1854.60), SIMDE_FLOAT32_C(  -698.72), SIMDE_FLOAT32_C(  -244.47), SIMDE_FLOAT32_C( -1565.65),
                         SIMDE_FLOAT32_C( -1432.42), SIMDE_FLOAT32_C(   933.06), SIMDE_FLOAT32_C(   684.33), SIMDE_FLOAT32_C( -1086.51)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   662.71), SIMDE_FLOAT32_C(   564.94), SIMDE_FLOAT32_C(  -317.08), SIMDE_FLOAT32_C(  -219.40),
                         SIMDE_FLOAT32_C(  -599.10), SIMDE_FLOAT32_C(  -944.25), SIMDE_FLOAT32_C(   691.43), SIMDE_FLOAT32_C(   -94.27),
                         SIMDE_FLOAT32_C(   505.61), SIMDE_FLOAT32_C(   476.10), SIMDE_FLOAT32_C(  -623.97), SIMDE_FLOAT32_C(  -863.44),
                         SIMDE_FLOAT32_C(   522.48), SIMDE_FLOAT32_C(   -79.88), SIMDE_FLOAT32_C(  -355.36), SIMDE_FLOAT32_C(  -248.57)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -575.57), SIMDE_FLOAT32_C(   909.53), SIMDE_FLOAT32_C(   384.99), SIMDE_FLOAT32_C(  -171.88),
                         SIMDE_FLOAT32_C(   -66.16), SIMDE_FLOAT32_C(  -405.98), SIMDE_FLOAT32_C(  -149.45), SIMDE_FLOAT32_C(  -972.01),
                         SIMDE_FLOAT32_C(    82.36), SIMDE_FLOAT32_C(  -907.67), SIMDE_FLOAT32_C(   832.44), SIMDE_FLOAT32_C(   -67.87),
                         SIMDE_FLOAT32_C(  -429.02), SIMDE_FLOAT32_C(  -820.79), SIMDE_FLOAT32_C(    81.64), SIMDE_FLOAT32_C(    69.75)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    87.14), SIMDE_FLOAT32_C(  1474.47), SIMDE_FLOAT32_C(    67.91), SIMDE_FLOAT32_C(  -391.28),
                         SIMDE_FLOAT32_C(  -665.26), SIMDE_FLOAT32_C( -1350.23), SIMDE_FLOAT32_C(   541.98), SIMDE_FLOAT32_C( -1066.28),
                         SIMDE_FLOAT32_C(   587.97), SIMDE_FLOAT32_C(  -431.57), SIMDE_FLOAT32_C(   208.47), SIMDE_FLOAT32_C(  -931.31),
                         SIMDE_FLOAT32_C(    93.46), SIMDE_FLOAT32_C(  -900.67), SIMDE_FLOAT32_C(  -273.72), SIMDE_FLOAT32_C(  -178.82)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -260.02), SIMDE_FLOAT32_C(  -334.14), SIMDE_FLOAT32_C(   105.88), SIMDE_FLOAT32_C(  -393.27),
                         SIMDE_FLOAT32_C(   549.30), SIMDE_FLOAT32_C(   752.10), SIMDE_FLOAT32_C(   339.34), SIMDE_FLOAT32_C(  -761.70),
                         SIMDE_FLOAT32_C(   564.82), SIMDE_FLOAT32_C(  -275.31), SIMDE_FLOAT32_C(  -952.67), SIMDE_FLOAT32_C(  -216.82),
                         SIMDE_FLOAT32_C(  -270.02), SIMDE_FLOAT32_C(   133.54), SIMDE_FLOAT32_C(   513.36), SIMDE_FLOAT32_C(   -92.17)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -669.70), SIMDE_FLOAT32_C(   -59.27), SIMDE_FLOAT32_C(   771.68), SIMDE_FLOAT32_C(   474.66),
                         SIMDE_FLOAT32_C(    41.08), SIMDE_FLOAT32_C(  -386.46), SIMDE_FLOAT32_C(   740.49), SIMDE_FLOAT32_C(   -90.54),
                         SIMDE_FLOAT32_C(   947.02), SIMDE_FLOAT32_C(  -119.81), SIMDE_FLOAT32_C(   259.70), SIMDE_FLOAT32_C(   -54.65),
                         SIMDE_FLOAT32_C(  -882.33), SIMDE_FLOAT32_C(  -869.82), SIMDE_FLOAT32_C(   646.89), SIMDE_FLOAT32_C(  -460.05)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -929.72), SIMDE_FLOAT32_C(  -393.41), SIMDE_FLOAT32_C(   877.56), SIMDE_FLOAT32_C(    81.39),
                         SIMDE_FLOAT32_C(   590.38), SIMDE_FLOAT32_C(   365.64), SIMDE_FLOAT32_C(  1079.83), SIMDE_FLOAT32_C(  -852.24),
                         SIMDE_FLOAT32_C(  1511.84), SIMDE_FLOAT32_C(  -395.12), SIMDE_FLOAT32_C(  -692.97), SIMDE_FLOAT32_C(  -271.47),
                         SIMDE_FLOAT32_C( -1152.35), SIMDE_FLOAT32_C(  -736.28), SIMDE_FLOAT32_C(  1160.25), SIMDE_FLOAT32_C(  -552.22)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   756.25), SIMDE_FLOAT32_C(   511.04), SIMDE_FLOAT32_C(   859.11), SIMDE_FLOAT32_C(  -867.90),
                         SIMDE_FLOAT32_C(  -479.94), SIMDE_FLOAT32_C(  -217.41), SIMDE_FLOAT32_C(  -447.63), SIMDE_FLOAT32_C(   911.19),
                         SIMDE_FLOAT32_C(  -709.58), SIMDE_FLOAT32_C(  -654.53), SIMDE_FLOAT32_C(  -416.78), SIMDE_FLOAT32_C(   728.12),
                         SIMDE_FLOAT32_C(  -682.52), SIMDE_FLOAT32_C(   389.98), SIMDE_FLOAT32_C(   929.37), SIMDE_FLOAT32_C(  -933.27)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   921.09), SIMDE_FLOAT32_C(    94.70), SIMDE_FLOAT32_C(  -824.20), SIMDE_FLOAT32_C(   359.66),
                         SIMDE_FLOAT32_C(  -948.58), SIMDE_FLOAT32_C(   259.61), SIMDE_FLOAT32_C(  -263.97), SIMDE_FLOAT32_C(   203.12),
                         SIMDE_FLOAT32_C(   565.73), SIMDE_FLOAT32_C(   268.27), SIMDE_FLOAT32_C(   574.31), SIMDE_FLOAT32_C(  -841.55),
                         SIMDE_FLOAT32_C(   681.29), SIMDE_FLOAT32_C(   574.95), SIMDE_FLOAT32_C(   623.04), SIMDE_FLOAT32_C(    56.66)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  1677.34), SIMDE_FLOAT32_C(   605.74), SIMDE_FLOAT32_C(    34.91), SIMDE_FLOAT32_C(  -508.24),
                         SIMDE_FLOAT32_C( -1428.52), SIMDE_FLOAT32_C(    42.20), SIMDE_FLOAT32_C(  -711.60), SIMDE_FLOAT32_C(  1114.31),
                         SIMDE_FLOAT32_C(  -143.85), SIMDE_FLOAT32_C(  -386.26), SIMDE_FLOAT32_C(   157.53), SIMDE_FLOAT32_C(  -113.43),
                         SIMDE_FLOAT32_C(    -1.23), SIMDE_FLOAT32_C(   964.93), SIMDE_FLOAT32_C(  1552.41), SIMDE_FLOAT32_C(  -876.61)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   437.52), SIMDE_FLOAT32_C(  -206.27), SIMDE_FLOAT32_C(   -27.72), SIMDE_FLOAT32_C(  -407.95),
                         SIMDE_FLOAT32_C(  -100.99), SIMDE_FLOAT32_C(   -27.12), SIMDE_FLOAT32_C(   232.25), SIMDE_FLOAT32_C(  -679.34),
                         SIMDE_FLOAT32_C(   493.07), SIMDE_FLOAT32_C(   235.84), SIMDE_FLOAT32_C(  -247.65), SIMDE_FLOAT32_C(   639.70),
                         SIMDE_FLOAT32_C(   408.65), SIMDE_FLOAT32_C(   173.51), SIMDE_FLOAT32_C(    33.96), SIMDE_FLOAT32_C(  -654.24)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   995.52), SIMDE_FLOAT32_C(   101.75), SIMDE_FLOAT32_C(  -157.89), SIMDE_FLOAT32_C(   762.54),
                         SIMDE_FLOAT32_C(  -359.84), SIMDE_FLOAT32_C(   895.91), SIMDE_FLOAT32_C(  -723.29), SIMDE_FLOAT32_C(  -396.31),
                         SIMDE_FLOAT32_C(  -209.52), SIMDE_FLOAT32_C(   465.97), SIMDE_FLOAT32_C(   723.67), SIMDE_FLOAT32_C(   -27.91),
                         SIMDE_FLOAT32_C(   178.75), SIMDE_FLOAT32_C(   111.72), SIMDE_FLOAT32_C(    49.88), SIMDE_FLOAT32_C(   -16.33)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  1433.04), SIMDE_FLOAT32_C(  -104.52), SIMDE_FLOAT32_C(  -185.61), SIMDE_FLOAT32_C(   354.59),
                         SIMDE_FLOAT32_C(  -460.83), SIMDE_FLOAT32_C(   868.79), SIMDE_FLOAT32_C(  -491.04), SIMDE_FLOAT32_C( -1075.65),
                         SIMDE_FLOAT32_C(   283.55), SIMDE_FLOAT32_C(   701.81), SIMDE_FLOAT32_C(   476.02), SIMDE_FLOAT32_C(   611.79),
                         SIMDE_FLOAT32_C(   587.40), SIMDE_FLOAT32_C(   285.23), SIMDE_FLOAT32_C(    83.84), SIMDE_FLOAT32_C(  -670.57)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -375.93), SIMDE_FLOAT32_C(   812.42), SIMDE_FLOAT32_C(   139.50), SIMDE_FLOAT32_C(  -189.29),
                         SIMDE_FLOAT32_C(   145.73), SIMDE_FLOAT32_C(  -679.16), SIMDE_FLOAT32_C(  -470.57), SIMDE_FLOAT32_C(   204.76),
                         SIMDE_FLOAT32_C(  -513.19), SIMDE_FLOAT32_C(   720.36), SIMDE_FLOAT32_C(   372.49), SIMDE_FLOAT32_C(   878.61),
                         SIMDE_FLOAT32_C(  -970.72), SIMDE_FLOAT32_C(   793.74), SIMDE_FLOAT32_C(   338.04), SIMDE_FLOAT32_C(  -645.89)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   929.83), SIMDE_FLOAT32_C(   319.52), SIMDE_FLOAT32_C(   731.40), SIMDE_FLOAT32_C(   721.97),
                         SIMDE_FLOAT32_C(  -865.47), SIMDE_FLOAT32_C(   180.74), SIMDE_FLOAT32_C(  -262.02), SIMDE_FLOAT32_C(   877.25),
                         SIMDE_FLOAT32_C(  -600.16), SIMDE_FLOAT32_C(  -927.22), SIMDE_FLOAT32_C(  -354.63), SIMDE_FLOAT32_C(  -776.27),
                         SIMDE_FLOAT32_C(  -950.90), SIMDE_FLOAT32_C(   958.35), SIMDE_FLOAT32_C(   483.36), SIMDE_FLOAT32_C(   612.98)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   553.90), SIMDE_FLOAT32_C(  1131.94), SIMDE_FLOAT32_C(   870.90), SIMDE_FLOAT32_C(   532.68),
                         SIMDE_FLOAT32_C(  -719.74), SIMDE_FLOAT32_C(  -498.42), SIMDE_FLOAT32_C(  -732.59), SIMDE_FLOAT32_C(  1082.01),
                         SIMDE_FLOAT32_C( -1113.35), SIMDE_FLOAT32_C(  -206.86), SIMDE_FLOAT32_C(    17.86), SIMDE_FLOAT32_C(   102.34),
                         SIMDE_FLOAT32_C( -1921.62), SIMDE_FLOAT32_C(  1752.09), SIMDE_FLOAT32_C(   821.40), SIMDE_FLOAT32_C(   -32.91)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_add_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_add_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -236.16), SIMDE_FLOAT64_C(   20.07),
                         SIMDE_FLOAT64_C(  257.66), SIMDE_FLOAT64_C(  863.96),
                         SIMDE_FLOAT64_C(  593.27), SIMDE_FLOAT64_C( -503.87),
                         SIMDE_FLOAT64_C( -362.00), SIMDE_FLOAT64_C(  273.73)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  196.72), SIMDE_FLOAT64_C(   63.78),
                         SIMDE_FLOAT64_C(  794.12), SIMDE_FLOAT64_C(  -29.20),
                         SIMDE_FLOAT64_C( -795.86), SIMDE_FLOAT64_C( -299.89),
                         SIMDE_FLOAT64_C(  346.27), SIMDE_FLOAT64_C(  203.60)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -39.44), SIMDE_FLOAT64_C(   83.85),
                         SIMDE_FLOAT64_C( 1051.78), SIMDE_FLOAT64_C(  834.76),
                         SIMDE_FLOAT64_C( -202.59), SIMDE_FLOAT64_C( -803.76),
                         SIMDE_FLOAT64_C(  -15.73), SIMDE_FLOAT64_C(  477.33)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  770.84), SIMDE_FLOAT64_C( -754.36),
                         SIMDE_FLOAT64_C(  737.96), SIMDE_FLOAT64_C( -529.83),
                         SIMDE_FLOAT64_C( -355.96), SIMDE_FLOAT64_C( -623.94),
                         SIMDE_FLOAT64_C(  550.26), SIMDE_FLOAT64_C(  883.81)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -87.42), SIMDE_FLOAT64_C( -548.47),
                         SIMDE_FLOAT64_C( -633.24), SIMDE_FLOAT64_C(  450.21),
                         SIMDE_FLOAT64_C(  645.87), SIMDE_FLOAT64_C( -366.47),
                         SIMDE_FLOAT64_C(  695.56), SIMDE_FLOAT64_C(  617.08)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  683.42), SIMDE_FLOAT64_C(-1302.83),
                         SIMDE_FLOAT64_C(  104.72), SIMDE_FLOAT64_C(  -79.62),
                         SIMDE_FLOAT64_C(  289.91), SIMDE_FLOAT64_C( -990.41),
                         SIMDE_FLOAT64_C( 1245.82), SIMDE_FLOAT64_C( 1500.89)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -504.50), SIMDE_FLOAT64_C( -227.85),
                         SIMDE_FLOAT64_C( -966.51), SIMDE_FLOAT64_C( -410.18),
                         SIMDE_FLOAT64_C(  -80.72), SIMDE_FLOAT64_C( -882.81),
                         SIMDE_FLOAT64_C( -139.97), SIMDE_FLOAT64_C(  617.51)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -598.19), SIMDE_FLOAT64_C(  737.33),
                         SIMDE_FLOAT64_C(  488.15), SIMDE_FLOAT64_C(  218.70),
                         SIMDE_FLOAT64_C(  134.86), SIMDE_FLOAT64_C( -311.92),
                         SIMDE_FLOAT64_C(  725.05), SIMDE_FLOAT64_C(  687.14)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(-1102.69), SIMDE_FLOAT64_C(  509.48),
                         SIMDE_FLOAT64_C( -478.36), SIMDE_FLOAT64_C( -191.48),
                         SIMDE_FLOAT64_C(   54.14), SIMDE_FLOAT64_C(-1194.73),
                         SIMDE_FLOAT64_C(  585.08), SIMDE_FLOAT64_C( 1304.65)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  472.12), SIMDE_FLOAT64_C( -365.98),
                         SIMDE_FLOAT64_C(  659.31), SIMDE_FLOAT64_C( -290.87),
                         SIMDE_FLOAT64_C( -373.51), SIMDE_FLOAT64_C( -669.26),
                         SIMDE_FLOAT64_C( -520.33), SIMDE_FLOAT64_C(  675.55)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  635.51), SIMDE_FLOAT64_C( -125.87),
                         SIMDE_FLOAT64_C( -802.87), SIMDE_FLOAT64_C(  655.14),
                         SIMDE_FLOAT64_C(  196.92), SIMDE_FLOAT64_C(  789.13),
                         SIMDE_FLOAT64_C(  116.39), SIMDE_FLOAT64_C( -455.20)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( 1107.63), SIMDE_FLOAT64_C( -491.85),
                         SIMDE_FLOAT64_C( -143.56), SIMDE_FLOAT64_C(  364.27),
                         SIMDE_FLOAT64_C( -176.59), SIMDE_FLOAT64_C(  119.87),
                         SIMDE_FLOAT64_C( -403.94), SIMDE_FLOAT64_C(  220.35)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  788.90), SIMDE_FLOAT64_C( -954.97),
                         SIMDE_FLOAT64_C(  125.34), SIMDE_FLOAT64_C(  169.40),
                         SIMDE_FLOAT64_C(  224.26), SIMDE_FLOAT64_C( -169.19),
                         SIMDE_FLOAT64_C(  154.36), SIMDE_FLOAT64_C( -652.64)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -435.33), SIMDE_FLOAT64_C( -537.34),
                         SIMDE_FLOAT64_C( -563.73), SIMDE_FLOAT64_C(  279.31),
                         SIMDE_FLOAT64_C( -443.50), SIMDE_FLOAT64_C(   -9.90),
                         SIMDE_FLOAT64_C(  404.97), SIMDE_FLOAT64_C(  991.70)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  353.57), SIMDE_FLOAT64_C(-1492.31),
                         SIMDE_FLOAT64_C( -438.39), SIMDE_FLOAT64_C(  448.71),
                         SIMDE_FLOAT64_C( -219.24), SIMDE_FLOAT64_C( -179.09),
                         SIMDE_FLOAT64_C(  559.33), SIMDE_FLOAT64_C(  339.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -409.86), SIMDE_FLOAT64_C( -564.70),
                         SIMDE_FLOAT64_C(  978.74), SIMDE_FLOAT64_C( -670.81),
                         SIMDE_FLOAT64_C( -437.36), SIMDE_FLOAT64_C( -920.10),
                         SIMDE_FLOAT64_C(   26.94), SIMDE_FLOAT64_C(  254.30)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   88.55), SIMDE_FLOAT64_C( -559.38),
                         SIMDE_FLOAT64_C( -420.16), SIMDE_FLOAT64_C(  439.30),
                         SIMDE_FLOAT64_C( -160.71), SIMDE_FLOAT64_C(  -56.82),
                         SIMDE_FLOAT64_C(   12.24), SIMDE_FLOAT64_C(  276.77)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -321.31), SIMDE_FLOAT64_C(-1124.08),
                         SIMDE_FLOAT64_C(  558.58), SIMDE_FLOAT64_C( -231.51),
                         SIMDE_FLOAT64_C( -598.07), SIMDE_FLOAT64_C( -976.92),
                         SIMDE_FLOAT64_C(   39.18), SIMDE_FLOAT64_C(  531.07)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -252.56), SIMDE_FLOAT64_C( -715.99),
                         SIMDE_FLOAT64_C( -694.53), SIMDE_FLOAT64_C(  556.76),
                         SIMDE_FLOAT64_C(  839.65), SIMDE_FLOAT64_C( -743.60),
                         SIMDE_FLOAT64_C( -343.44), SIMDE_FLOAT64_C( -212.93)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -450.77), SIMDE_FLOAT64_C(  107.13),
                         SIMDE_FLOAT64_C(  937.09), SIMDE_FLOAT64_C(  938.48),
                         SIMDE_FLOAT64_C( -943.33), SIMDE_FLOAT64_C( -298.38),
                         SIMDE_FLOAT64_C(  752.15), SIMDE_FLOAT64_C( -313.15)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -703.33), SIMDE_FLOAT64_C( -608.86),
                         SIMDE_FLOAT64_C(  242.56), SIMDE_FLOAT64_C( 1495.24),
                         SIMDE_FLOAT64_C( -103.68), SIMDE_FLOAT64_C(-1041.98),
                         SIMDE_FLOAT64_C(  408.71), SIMDE_FLOAT64_C( -526.08)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  940.55), SIMDE_FLOAT64_C(  673.86),
                         SIMDE_FLOAT64_C( -765.42), SIMDE_FLOAT64_C( -188.42),
                         SIMDE_FLOAT64_C( -980.28), SIMDE_FLOAT64_C( -223.74),
                         SIMDE_FLOAT64_C(  -19.52), SIMDE_FLOAT64_C( -256.77)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  128.08), SIMDE_FLOAT64_C(  862.66),
                         SIMDE_FLOAT64_C(  151.47), SIMDE_FLOAT64_C(  825.63),
                         SIMDE_FLOAT64_C( -245.57), SIMDE_FLOAT64_C( -364.98),
                         SIMDE_FLOAT64_C(  -60.78), SIMDE_FLOAT64_C(  224.87)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( 1068.63), SIMDE_FLOAT64_C( 1536.52),
                         SIMDE_FLOAT64_C( -613.95), SIMDE_FLOAT64_C(  637.21),
                         SIMDE_FLOAT64_C(-1225.85), SIMDE_FLOAT64_C( -588.72),
                         SIMDE_FLOAT64_C(  -80.30), SIMDE_FLOAT64_C(  -31.90)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_add_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_and_si512(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_andnot_si512(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( -335330897), INT32_C( 1860840666), INT32_C( -837102383), INT32_C( 1544121603),
                            INT32_C(  -31451516), INT32_C(  294501250), INT32_C( 1844141610), INT32_C(  711066163),
                            INT32_C( 1032767823), INT32_C(  466876164), INT32_C( 1432923079), INT32_C( -137339965),
                            INT32_C(-1216294439), INT32_C( 1110388055), INT32_C(  754234048), INT32_C( -712839683)),
      simde_mm512_set_epi32(INT32_C(  645969883), INT32_C(   45407696), INT32_C(-1431929981), INT32_C(-1744968675),
                            INT32_C( 1491740298), INT32_C( -669732847), INT32_C(-1678703719), INT32_C(-1110558488),
                            INT32_C(-1993251114), INT32_C( 1910816421), INT32_C( 2013403088), INT32_C(  882585036),
                            INT32_C( 1733706468), INT32_C( 1763057771), INT32_C(  303070795), INT32_C( -805966849)),
      simde_mm512_set_epi32(INT32_C(   41989712), INT32_C(    1364224), INT32_C(  547629826), INT32_C(-2081128420),
                            INT32_C(   13246474), INT32_C( -938475503), INT32_C(-1844444783), INT32_C(-1785972536),
                            INT32_C(-2144262512), INT32_C( 1612974241), INT32_C(  671224848), INT32_C(     730124),
                            INT32_C( 1079378468), INT32_C(  688914472), INT32_C(  302009355), INT32_C(  175440386)) },
    { simde_mm512_set_epi32(INT32_C( 1267266514), INT32_C(-1810114077), INT32_C(-1631053656), INT32_C(-1291259659),
                            INT32_C(-1797405973), INT32_C(-2052491824), INT32_C(  218690610), INT32_C(  434694077),
                            INT32_C(  322569513), INT32_C( -492306370), INT32_C( 1714124310), INT32_C(  757183592),
                            INT32_C( 1904845371), INT32_C( 1921390915), INT32_C( 1219016836), INT32_C( -491589854)),
      simde_mm512_set_epi32(INT32_C( -843887215), INT32_C(-1144045392), INT32_C( 1523671305), INT32_C( -687015924),
                            INT32_C( -651771268), INT32_C(-1812069901), INT32_C(  132880464), INT32_C( 1912329512),
                            INT32_C( -208209918), INT32_C(-1079631083), INT32_C( -134611197), INT32_C(-1062410635),
                            INT32_C( -896925558), INT32_C( -559765979), INT32_C( 1912148196), INT32_C( -437846049)),
      simde_mm512_set_epi32(INT32_C(-2077029375), INT32_C(  734265360), INT32_C( 1074880769), INT32_C( 1141114888),
                            INT32_C( 1226965012), INT32_C(  307626019), INT32_C(   48433216), INT32_C( 1611862016),
                            INT32_C( -528156670), INT32_C(  486941441), INT32_C(-1848604415), INT32_C(-1064549867),
                            INT32_C(-1979580288), INT32_C(-1944017372), INT32_C(  827392096), INT32_C(   88346845)) },
    { simde_mm512_set_epi32(INT32_C(  451034606), INT32_C(  160382101), INT32_C(-1268862602), INT32_C(  782115678),
                            INT32_C(-1160318793), INT32_C( -575355195), INT32_C( 1432838242), INT32_C(-2114154695),
                            INT32_C(-1020410376), INT32_C( -714076046), INT32_C(-1407849113), INT32_C(  996241684),
                            INT32_C(  481606881), INT32_C(-1834956523), INT32_C(  493396975), INT32_C(-1084672800)),
      simde_mm512_set_epi32(INT32_C( 1458493934), INT32_C( 1051105030), INT32_C( -836083742), INT32_C( 1407748874),
                            INT32_C(-1387312486), INT32_C(  776481471), INT32_C(  275093143), INT32_C( -137438390),
                            INT32_C( 1860284960), INT32_C(  540502552), INT32_C( 1411461258), INT32_C( 1517918194),
                            INT32_C( -266161178), INT32_C( 1269265702), INT32_C(  809771495), INT32_C(-1968711037)),
      simde_mm512_set_epi32(INT32_C( 1141686272), INT32_C(  908100354), INT32_C( 1243631232), INT32_C( 1365280768),
                            INT32_C(   84478472), INT32_C(  575154234), INT32_C(      38549), INT32_C( 1979863106),
                            INT32_C(  750793216), INT32_C(  537356808), INT32_C( 1344278664), INT32_C( 1075349218),
                            INT32_C( -536739066), INT32_C( 1225208866), INT32_C(  537133056), INT32_C(   10930691)) },
    { simde_mm512_set_epi32(INT32_C(-1562592645), INT32_C(  -32255724), INT32_C( -923416118), INT32_C(-2134713284),
                            INT32_C(-1313323965), INT32_C(-1729518909), INT32_C( 1286411285), INT32_C( -376910154),
                            INT32_C(-1786193108), INT32_C(-2035089818), INT32_C( 1552020826), INT32_C(  726998554),
                            INT32_C( 1864619074), INT32_C( 1828024315), INT32_C( -824341738), INT32_C(-1420030579)),
      simde_mm512_set_epi32(INT32_C( 1087836695), INT32_C(-2094233976), INT32_C( 1148487684), INT32_C(-1514127182),
                            INT32_C( -524459384), INT32_C(  725104708), INT32_C( 1787286694), INT32_C(-1533684832),
                            INT32_C(   46575098), INT32_C( 2086853653), INT32_C(  815292575), INT32_C(-1270435744),
                            INT32_C( 2014177347), INT32_C( 1099600134), INT32_C( -622983952), INT32_C(  822011154)),
      simde_mm512_set_epi32(INT32_C( 1073938436), INT32_C(   19662472), INT32_C(   67108868), INT32_C(  620757122),
                            INT32_C( 1074078344), INT32_C(  588257284), INT32_C(  570605730), INT32_C(   68489472),
                            INT32_C(   38151378), INT32_C( 2017460241), INT32_C(  538443909), INT32_C(-1811767200),
                            INT32_C(  269232129), INT32_C(   17469444), INT32_C(  268567776), INT32_C(  279109650)) },
    { simde_mm512_set_epi32(INT32_C(-1657115762), INT32_C( 1585840022), INT32_C(-1070898703), INT32_C( 1022031619),
                            INT32_C(-1380717315), INT32_C( 1086658406), INT32_C( -124039065), INT32_C(-1974944947),
                            INT32_C( 2044249149), INT32_C( 1638783653), INT32_C( 1466240446), INT32_C(-1803146403),
                            INT32_C( 1060682707), INT32_C(-1592428518), INT32_C(  156586666), INT32_C( -266957088)),
      simde_mm512_set_epi32(INT32_C( -703454581), INT32_C(  797686885), INT32_C( 1723425278), INT32_C( -158454369),
                            INT32_C(-1043830066), INT32_C(  709622512), INT32_C(-2136296570), INT32_C( -863350926),
                            INT32_C( 1844461284), INT32_C(  -21472306), INT32_C(-1932483198), INT32_C(-1320584016),
                            INT32_C( -370591173), INT32_C( -330170023), INT32_C( -975385097), INT32_C( -654562432)),
      simde_mm512_set_epi32(INT32_C( 1107296257), INT32_C(  554303585), INT32_C(  646971406), INT32_C(-1039923044),
                            INT32_C( 1078460930), INT32_C(  705357968), INT32_C(    2139008), INT32_C( 1149387826),
                            INT32_C(   69221056), INT32_C(-1643118262), INT32_C(-2003787776), INT32_C(  558453920),
                            INT32_C(-1061093336), INT32_C( 1279394113), INT32_C( -997683883), INT32_C(  149430528)) },
    { simde_mm512_set_epi32(INT32_C(  962558787), INT32_C(-1212292378), INT32_C(-1698562444), INT32_C(-1456708578),
                            INT32_C( 1605522258), INT32_C(-1389853810), INT32_C(  605095260), INT32_C(  449573803),
                            INT32_C(-1932095036), INT32_C( 1214045264), INT32_C(-1966228541), INT32_C(  484352026),
                            INT32_C(-1251622562), INT32_C(   97048183), INT32_C( 1801957969), INT32_C(   39148591)),
      simde_mm512_set_epi32(INT32_C( 1144673524), INT32_C(-1837539909), INT32_C(-1995926176), INT32_C( -775830454),
                            INT32_C( 1197039500), INT32_C(  605086417), INT32_C(-1681915928), INT32_C(-1694227594),
                            INT32_C(  250277648), INT32_C( 1517650405), INT32_C( -529860796), INT32_C(  319331129),
                            INT32_C( 1337610221), INT32_C( -515158609), INT32_C(-1958759875), INT32_C(  480005412)),
      simde_mm512_set_epi32(INT32_C( 1142949044), INT32_C(    4201753), INT32_C(   17301760), INT32_C( 1354858560),
                            INT32_C(    4787340), INT32_C(    1073233), INT32_C(-1683031392), INT32_C(-2130444204),
                            INT32_C(   36204048), INT32_C(  304152997), INT32_C( 1612858372), INT32_C(   50338593),
                            INT32_C( 1251610273), INT32_C( -536671864), INT32_C(-2145910740), INT32_C(  478675200)) },
    { simde_mm512_set_epi32(INT32_C(  477799556), INT32_C(  718106947), INT32_C( -702434720), INT32_C(  911156446),
                            INT32_C(  692922531), INT32_C( -634559193), INT32_C( -541024501), INT32_C(    6957260),
                            INT32_C(  891904501), INT32_C( 1674261328), INT32_C(  463285837), INT32_C(  465636281),
                            INT32_C( -567453998), INT32_C( -675807734), INT32_C( 1242869264), INT32_C(-2003535835)),
      simde_mm512_set_epi32(INT32_C( -440269466), INT32_C( 1069561863), INT32_C( -850138274), INT32_C( 1324108467),
                            INT32_C(  996083706), INT32_C(-1741332408), INT32_C(-1720688024), INT32_C( -195389802),
                            INT32_C( -122163269), INT32_C(-1678986062), INT32_C( -261742027), INT32_C(  147621305),
                            INT32_C( 1928957095), INT32_C(  647911914), INT32_C(-1231783784), INT32_C(-1597793099)),
      simde_mm512_set_epi32(INT32_C( -511704734), INT32_C(  352323588), INT32_C(  156387614), INT32_C( 1218464289),
                            INT32_C(  303171416), INT32_C(    1048648), INT32_C(    3170400), INT32_C( -200239598),
                            INT32_C( -929657334), INT32_C(-1742437214), INT32_C( -530448336), INT32_C(     820224),
                            INT32_C(  550537253), INT32_C(  537395680), INT32_C(-1266659192), INT32_C(  541295760)) },
    { simde_mm512_set_epi32(INT32_C(-1322452749), INT32_C(-1191485380), INT32_C(   61071601), INT32_C( -255981709),
                            INT32_C( 1745472557), INT32_C( 1521357726), INT32_C(-1111842070), INT32_C( 1783291089),
                            INT32_C(  718609371), INT32_C( -553071779), INT32_C(-1373014967), INT32_C(  751334079),
                            INT32_C( -828271800), INT32_C(-1578484948), INT32_C(-1597074675), INT32_C(  393018558)),
      simde_mm512_set_epi32(INT32_C(-1722624236), INT32_C( -955857282), INT32_C( 1790216473), INT32_C( -762838785),
                            INT32_C( -108799681), INT32_C( -975838651), INT32_C( 1961237228), INT32_C(   52752901),
                            INT32_C(-1440122977), INT32_C(-1167835972), INT32_C( 1345250484), INT32_C( 2101674065),
                            INT32_C( -149671798), INT32_C(  738167968), INT32_C( -764040824), INT32_C( -514982245)),
      simde_mm512_set_epi32(INT32_C(  139593476), INT32_C( 1191478850), INT32_C( 1746143496), INT32_C(   33554572),
                            INT32_C(-1853746926), INT32_C(-2058231743), INT32_C( 1078204420), INT32_C(   19145220),
                            INT32_C(-2144836604), INT32_C(  543437984), INT32_C( 1342603444), INT32_C( 1359282240),
                            INT32_C(  823402626), INT32_C(  169182336), INT32_C( 1378953344), INT32_C( -536804863)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_andnot_si512(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_cmpeq_epi32_mask(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask16 r;
  } test_vec[8] = {
    { UINT16_C(15798),
      simde_mm512_set_epi32(INT32_C(-1396783922), INT32_C( 2147469122), INT32_C(  245941047), INT32_C(-1608794680),
                            INT32_C( 1508622706), INT32_C( -820009589), INT32_C(-2056933337), INT32_C( 1399160559),
                            INT32_C( -781782717), INT32_C( -745938688), INT32_C( 1376412239), INT32_C(  358147007),
                            INT32_C(-2141927311), INT32_C(  -13921241), INT32_C(  993767039), INT32_C( 1399506469)),
      simde_mm512_set_epi32(INT32_C(-1396783922), INT32_C( 1246457300), INT32_C( 1479047358), INT32_C(  -46329110),
                            INT32_C( 1508622706), INT32_C( -820009589), INT32_C( 2080173402), INT32_C( 1937046285),
                            INT32_C( 1642337112), INT32_C(  717149471), INT32_C(  913865239), INT32_C(  358147007),
                            INT32_C( 1535690363), INT32_C(  -13921241), INT32_C(  993767039), INT32_C(  520030741)),
      UINT16_C( 3094) },
    { UINT16_C(11237),
      simde_mm512_set_epi32(INT32_C( -503773363), INT32_C(-1842967576), INT32_C(  214407733), INT32_C( 2136243689),
                            INT32_C(  619563347), INT32_C(-2046647578), INT32_C( -882198373), INT32_C( -832110086),
                            INT32_C(  828288790), INT32_C( 1819046419), INT32_C(  292064966), INT32_C( -747926472),
                            INT32_C( -881463995), INT32_C(-1469434386), INT32_C( -207196114), INT32_C(-1865668915)),
      simde_mm512_set_epi32(INT32_C(  261150369), INT32_C(-1842967576), INT32_C(-1148601855), INT32_C( 2136243689),
                            INT32_C(-2013121518), INT32_C(-2046647578), INT32_C(-1816537753), INT32_C( -832110086),
                            INT32_C(  828288790), INT32_C( 1801925150), INT32_C(  292064966), INT32_C(-1755078036),
                            INT32_C(-1190065823), INT32_C(  764421376), INT32_C( -207196114), INT32_C(-1865668915)),
      UINT16_C(  417) },
    { UINT16_C(   61),
      simde_mm512_set_epi32(INT32_C(  219790698), INT32_C(  346516102), INT32_C(-2082495343), INT32_C(  775700745),
                            INT32_C( -630025741), INT32_C( 1914162819), INT32_C( -226095226), INT32_C( -350619769),
                            INT32_C( 1825330894), INT32_C(  -79420124), INT32_C(  939662489), INT32_C(  667606641),
                            INT32_C(-1935137328), INT32_C(  247120548), INT32_C( -894861328), INT32_C(-1690188311)),
      simde_mm512_set_epi32(INT32_C(  400967600), INT32_C(  346516102), INT32_C(-2082495343), INT32_C(  775700745),
                            INT32_C( -630025741), INT32_C( 1914162819), INT32_C(-1771983812), INT32_C( -350619769),
                            INT32_C( 1825330894), INT32_C(-1887033010), INT32_C(  939662489), INT32_C( -440942769),
                            INT32_C(-1935137328), INT32_C(  247120548), INT32_C(-1352163534), INT32_C(-1690188311)),
      UINT16_C(   45) },
    { UINT16_C(40799),
      simde_mm512_set_epi32(INT32_C(-1103261115), INT32_C(-1530092257), INT32_C( -178076517), INT32_C( 1725180044),
                            INT32_C( -619562554), INT32_C(-2028225116), INT32_C( -516465044), INT32_C( -790492311),
                            INT32_C(  770588317), INT32_C(  966229539), INT32_C( 1696981823), INT32_C( 1846986452),
                            INT32_C(  201003704), INT32_C(  -88144749), INT32_C( -459260562), INT32_C(-1462493092)),
      simde_mm512_set_epi32(INT32_C(-1103261115), INT32_C(-1530092257), INT32_C( 1272329003), INT32_C( 1725180044),
                            INT32_C(-1714282865), INT32_C( 1964019033), INT32_C(   -6888948), INT32_C( -794446809),
                            INT32_C(  770588317), INT32_C(  966229539), INT32_C(-1587543669), INT32_C( 1846986452),
                            INT32_C(  201003704), INT32_C(  -88144749), INT32_C(-1549459108), INT32_C(-1462493092)),
      UINT16_C(36957) },
    { UINT16_C(18708),
      simde_mm512_set_epi32(INT32_C( 1654168369), INT32_C(-1358646009), INT32_C(  945188582), INT32_C( 1242452940),
                            INT32_C(-2068238117), INT32_C(  613827224), INT32_C( 1766050173), INT32_C(  788865946),
                            INT32_C( -226150288), INT32_C(   20626714), INT32_C(-1790747056), INT32_C(-1510999017),
                            INT32_C(-2059568770), INT32_C(  525242273), INT32_C(-1970979230), INT32_C( -983788353)),
      simde_mm512_set_epi32(INT32_C(-1802152524), INT32_C(-1358646009), INT32_C( 1400410557), INT32_C( 1242452940),
                            INT32_C(-2068238117), INT32_C(-1745049433), INT32_C(-1272787498), INT32_C(   36641197),
                            INT32_C( -226150288), INT32_C(-2087200149), INT32_C( -530182364), INT32_C(-1510999017),
                            INT32_C(-2082577633), INT32_C(  525242273), INT32_C(-1970979230), INT32_C( -983788353)),
      UINT16_C(18452) },
    { UINT16_C(48938),
      simde_mm512_set_epi32(INT32_C(-1802886705), INT32_C(  505130099), INT32_C( 1294359394), INT32_C(  564426410),
                            INT32_C( -813242663), INT32_C(-1097324530), INT32_C( 1599346411), INT32_C(-1815738445),
                            INT32_C( 2114996332), INT32_C( 2143192037), INT32_C(  342894910), INT32_C( 1933006347),
                            INT32_C(  215936041), INT32_C( 2138148935), INT32_C(-1975112588), INT32_C(-1313889253)),
      simde_mm512_set_epi32(INT32_C( 1272515820), INT32_C(-1571014987), INT32_C( 1294359394), INT32_C(  564426410),
                            INT32_C( -305474417), INT32_C(-2099686495), INT32_C(  217917259), INT32_C( 1770631752),
                            INT32_C( 2114996332), INT32_C( 2143192037), INT32_C(  -26985081), INT32_C(  603877714),
                            INT32_C( 1592556524), INT32_C(  420570241), INT32_C(-1975112588), INT32_C(-1313889253)),
      UINT16_C(12290) },
    { UINT16_C(14127),
      simde_mm512_set_epi32(INT32_C(  452796731), INT32_C( -256668338), INT32_C(-1710549095), INT32_C( 1982965424),
                            INT32_C( 1184306045), INT32_C( -221254467), INT32_C( 1420239721), INT32_C( 2028887361),
                            INT32_C(-1950932361), INT32_C( 1650853943), INT32_C(  239751123), INT32_C( 1018010808),
                            INT32_C( -248946240), INT32_C(  701510715), INT32_C(  824235240), INT32_C( 1829156606)),
      simde_mm512_set_epi32(INT32_C(  452796731), INT32_C( 1031814185), INT32_C(-1710549095), INT32_C(  406415467),
                            INT32_C( 1184306045), INT32_C( -221254467), INT32_C(  419739010), INT32_C( 1708161231),
                            INT32_C(-1950932361), INT32_C( 1650853943), INT32_C(  239751123), INT32_C( 1018010808),
                            INT32_C( -248946240), INT32_C(  701510715), INT32_C(-1571248435), INT32_C( 1829156606)),
      UINT16_C( 9261) },
    { UINT16_C(22801),
      simde_mm512_set_epi32(INT32_C( 1869800572), INT32_C(  184060195), INT32_C(   81710208), INT32_C( -451284065),
                            INT32_C(  397153235), INT32_C(  120564446), INT32_C(-2128920097), INT32_C( 1498011427),
                            INT32_C( -602736654), INT32_C( -931955343), INT32_C(  270436915), INT32_C( -984637478),
                            INT32_C( 2080482721), INT32_C( 1599947836), INT32_C(  374268618), INT32_C(  202341051)),
      simde_mm512_set_epi32(INT32_C( 1869800572), INT32_C(  350721255), INT32_C( 1725621650), INT32_C( 2020045509),
                            INT32_C(  397153235), INT32_C( 2059505832), INT32_C(-2128920097), INT32_C( 1498011427),
                            INT32_C(  884679844), INT32_C( -931955343), INT32_C(-1565261303), INT32_C( -984637478),
                            INT32_C( 1047792745), INT32_C(  969830078), INT32_C(  374268618), INT32_C(  202341051)),
      UINT16_C( 2321) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_mask_cmpeq_epi32_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    munit_assert_uint16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_cmpeq_epi64_mask(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask8 r;
  } test_vec[8] = {
        { UINT8_C(115),
      simde_mm512_set_epi64(INT64_C( 4348952865125743495), INT64_C( 8907195910428523966),
                            INT64_C( -555297846538684965), INT64_C(-3305530648028206455),
                            INT64_C(-7750293559254563173), INT64_C( 3951671133747219220),
                            INT64_C(-6894340476589447467), INT64_C(-6649909963138976644)),
      simde_mm512_set_epi64(INT64_C( 4348952865125743495), INT64_C( 8907195910428523966),
                            INT64_C( -555297846538684965), INT64_C(-3305530648028206455),
                            INT64_C(-7750293559254563173), INT64_C( 3951671133747219220),
                            INT64_C(-6894340476589447467), INT64_C(-6649909963138976644)),
      UINT8_C(115) },
    { UINT8_C(-76),
      simde_mm512_set_epi64(INT64_C( 8332689039597379656), INT64_C( 7900374814306981371),
                            INT64_C( 8206399506600781005), INT64_C( 5651642469092770755),
                            INT64_C(-5276468455074141063), INT64_C(-8150118994496756122),
                            INT64_C(-7287862621291629679), INT64_C(-7014745115456116381)),
      simde_mm512_set_epi64(INT64_C( 8332689039597379656), INT64_C( 7900374814306981371),
                            INT64_C( 8206399506600781005), INT64_C( 5651642469092770755),
                            INT64_C(-5276468455074141063), INT64_C(-8150118994496756122),
                            INT64_C(-7287862621291629679), INT64_C(-7014745115456116381)),
      UINT8_C(-76) },
    { UINT8_C(-63),
      simde_mm512_set_epi64(INT64_C( 7236527943385330401), INT64_C(  116767711029271574),
                            INT64_C(-7511779586429923581), INT64_C(-6281060612395620420),
                            INT64_C( 5334279149031160339), INT64_C(-6936295720905153933),
                            INT64_C(-5966594716147702422), INT64_C(-1960426401249106870)),
      simde_mm512_set_epi64(INT64_C( 7236527943385330401), INT64_C(  116767711029271574),
                            INT64_C(-7511779586429923581), INT64_C(-6281060612395620420),
                            INT64_C( 5334279149031160339), INT64_C(-6936295720905153933),
                            INT64_C(-5966594716147702422), INT64_C(-1960426401249106870)),
      UINT8_C(-63) },
    { UINT8_C(-84),
      simde_mm512_set_epi64(INT64_C(-5864293804910529760), INT64_C(-3722175850551863480),
                            INT64_C(-8053886984172274597), INT64_C( 3048643712698287401),
                            INT64_C(-5981380249797847044), INT64_C( 6321481295420220845),
                            INT64_C(-8336374294441003741), INT64_C(-2887412569475159777)),
      simde_mm512_set_epi64(INT64_C(-5864293804910529760), INT64_C(-3722175850551863480),
                            INT64_C(-8053886984172274597), INT64_C( 3048643712698287401),
                            INT64_C(-5981380249797847044), INT64_C( 6321481295420220845),
                            INT64_C(-8336374294441003741), INT64_C(-2887412569475159777)),
      UINT8_C(-84) },
    { UINT8_C( 45),
      simde_mm512_set_epi64(INT64_C(-8218522425751896277), INT64_C(-7149663222058875596),
                            INT64_C( 7080218830292627692), INT64_C(-2891890791734862434),
                            INT64_C(-4384954483828399512), INT64_C( 5089202243579551750),
                            INT64_C( 8788094759787406145), INT64_C( 2516149631495189439)),
      simde_mm512_set_epi64(INT64_C(-8218522425751896277), INT64_C(-7149663222058875596),
                            INT64_C( 7080218830292627692), INT64_C(-2891890791734862434),
                            INT64_C(-4384954483828399512), INT64_C( 5089202243579551750),
                            INT64_C( 8788094759787406145), INT64_C( 2516149631495189439)),
      UINT8_C( 45) },
    { UINT8_C(  5),
      simde_mm512_set_epi64(INT64_C(  145485199714092362), INT64_C(-6393141610170469507),
                            INT64_C( 6963948246838738659), INT64_C(-3054749802931710588),
                            INT64_C( 7143515638979898745), INT64_C( 5488354241753951512),
                            INT64_C(-8770740517788982559), INT64_C( 8702399781297211582)),
      simde_mm512_set_epi64(INT64_C(  145485199714092362), INT64_C(-6393141610170469507),
                            INT64_C( 6963948246838738659), INT64_C(-3054749802931710588),
                            INT64_C( 7143515638979898745), INT64_C( 5488354241753951512),
                            INT64_C(-8770740517788982559), INT64_C( 8702399781297211582)),
      UINT8_C(  5) },
    { UINT8_C(-21),
      simde_mm512_set_epi64(INT64_C(-5030350574792405138), INT64_C(-5869985682998891384),
                            INT64_C(  426998328212293206), INT64_C(  101893104830552023),
                            INT64_C( 8651938035012127638), INT64_C(-1100263997520040250),
                            INT64_C(-3650059882502291796), INT64_C(-7140055842343107022)),
      simde_mm512_set_epi64(INT64_C(-5030350574792405138), INT64_C(-5869985682998891384),
                            INT64_C(  426998328212293206), INT64_C(  101893104830552023),
                            INT64_C( 8651938035012127638), INT64_C(-1100263997520040250),
                            INT64_C(-3650059882502291796), INT64_C(-7140055842343107022)),
      UINT8_C(-21) },
    { UINT8_C( 68),
      simde_mm512_set_epi64(INT64_C( 8442527567647714662), INT64_C(  727604365565743398),
                            INT64_C(-6275868973810648590), INT64_C(-1924585950205499234),
                            INT64_C( 6250201510427211416), INT64_C( -915789535162288486),
                            INT64_C( -862130374921112102), INT64_C(-4678769352213486102)),
      simde_mm512_set_epi64(INT64_C( 8442527567647714662), INT64_C(  727604365565743398),
                            INT64_C(-6275868973810648590), INT64_C(-1924585950205499234),
                            INT64_C( 6250201510427211416), INT64_C( -915789535162288486),
                            INT64_C( -862130374921112102), INT64_C(-4678769352213486102)),
      UINT8_C( 68) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_mask_cmpeq_epi64_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    munit_assert_uint8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cvtepi8_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(   6), INT8_C(  33), INT8_C( 124), INT8_C(-128),
                        INT8_C(  38), INT8_C(  59), INT8_C( -37), INT8_C( 121),
                        INT8_C(  67), INT8_C( 112), INT8_C(  62), INT8_C(-113),
                        INT8_C(-121), INT8_C( -89), INT8_C(  63), INT8_C( -72)),
      simde_mm512_set_epi32(INT32_C(          6), INT32_C(         33), INT32_C(        124), INT32_C(       -128),
                            INT32_C(         38), INT32_C(         59), INT32_C(        -37), INT32_C(        121),
                            INT32_C(         67), INT32_C(        112), INT32_C(         62), INT32_C(       -113),
                            INT32_C(       -121), INT32_C(        -89), INT32_C(         63), INT32_C(        -72)) },
    { simde_mm_set_epi8(INT8_C( -94), INT8_C( 125), INT8_C( 105), INT8_C( -92),
                        INT8_C(-107), INT8_C( -69), INT8_C(  25), INT8_C(-125),
                        INT8_C( -11), INT8_C( -44), INT8_C(  60), INT8_C( -96),
                        INT8_C( 119), INT8_C( -40), INT8_C(  29), INT8_C(   9)),
      simde_mm512_set_epi32(INT32_C(        -94), INT32_C(        125), INT32_C(        105), INT32_C(        -92),
                            INT32_C(       -107), INT32_C(        -69), INT32_C(         25), INT32_C(       -125),
                            INT32_C(        -11), INT32_C(        -44), INT32_C(         60), INT32_C(        -96),
                            INT32_C(        119), INT32_C(        -40), INT32_C(         29), INT32_C(          9)) },
    { simde_mm_set_epi8(INT8_C(  47), INT8_C(  -9), INT8_C(-127), INT8_C(  66),
                        INT8_C( 126), INT8_C( -95), INT8_C(  99), INT8_C( -25),
                        INT8_C( -19), INT8_C(  84), INT8_C( -96), INT8_C( -77),
                        INT8_C( -34), INT8_C(-108), INT8_C( -33), INT8_C(  62)),
      simde_mm512_set_epi32(INT32_C(         47), INT32_C(         -9), INT32_C(       -127), INT32_C(         66),
                            INT32_C(        126), INT32_C(        -95), INT32_C(         99), INT32_C(        -25),
                            INT32_C(        -19), INT32_C(         84), INT32_C(        -96), INT32_C(        -77),
                            INT32_C(        -34), INT32_C(       -108), INT32_C(        -33), INT32_C(         62)) },
    { simde_mm_set_epi8(INT8_C(  93), INT8_C(-106), INT8_C(  61), INT8_C(  64),
                        INT8_C( -98), INT8_C(  31), INT8_C( -75), INT8_C( -23),
                        INT8_C( 113), INT8_C( -94), INT8_C( -70), INT8_C( -73),
                        INT8_C(  66), INT8_C( -84), INT8_C(  92), INT8_C(-113)),
      simde_mm512_set_epi32(INT32_C(         93), INT32_C(       -106), INT32_C(         61), INT32_C(         64),
                            INT32_C(        -98), INT32_C(         31), INT32_C(        -75), INT32_C(        -23),
                            INT32_C(        113), INT32_C(        -94), INT32_C(        -70), INT32_C(        -73),
                            INT32_C(         66), INT32_C(        -84), INT32_C(         92), INT32_C(       -113)) },
    { simde_mm_set_epi8(INT8_C( -92), INT8_C( -17), INT8_C( -42), INT8_C( 103),
                        INT8_C( 111), INT8_C( -23), INT8_C(  14), INT8_C(-122),
                        INT8_C( -61), INT8_C(   1), INT8_C(  16), INT8_C(-124),
                        INT8_C( -62), INT8_C(  59), INT8_C( 106), INT8_C(-105)),
      simde_mm512_set_epi32(INT32_C(        -92), INT32_C(        -17), INT32_C(        -42), INT32_C(        103),
                            INT32_C(        111), INT32_C(        -23), INT32_C(         14), INT32_C(       -122),
                            INT32_C(        -61), INT32_C(          1), INT32_C(         16), INT32_C(       -124),
                            INT32_C(        -62), INT32_C(         59), INT32_C(        106), INT32_C(       -105)) },
    { simde_mm_set_epi8(INT8_C(  71), INT8_C(  82), INT8_C( -83), INT8_C( 118),
                        INT8_C( 127), INT8_C(  -5), INT8_C(  43), INT8_C( -48),
                        INT8_C(  67), INT8_C(-117), INT8_C( -15), INT8_C( 105),
                        INT8_C( -88), INT8_C( 127), INT8_C(  85), INT8_C(-110)),
      simde_mm512_set_epi32(INT32_C(         71), INT32_C(         82), INT32_C(        -83), INT32_C(        118),
                            INT32_C(        127), INT32_C(         -5), INT32_C(         43), INT32_C(        -48),
                            INT32_C(         67), INT32_C(       -117), INT32_C(        -15), INT32_C(        105),
                            INT32_C(        -88), INT32_C(        127), INT32_C(         85), INT32_C(       -110)) },
    { simde_mm_set_epi8(INT8_C(   8), INT8_C(  35), INT8_C( -44), INT8_C(  18),
                        INT8_C(   3), INT8_C(  -7), INT8_C(  34), INT8_C(  98),
                        INT8_C(  43), INT8_C(  97), INT8_C(-127), INT8_C( 121),
                        INT8_C( -47), INT8_C( -94), INT8_C( -74), INT8_C( -59)),
      simde_mm512_set_epi32(INT32_C(          8), INT32_C(         35), INT32_C(        -44), INT32_C(         18),
                            INT32_C(          3), INT32_C(         -7), INT32_C(         34), INT32_C(         98),
                            INT32_C(         43), INT32_C(         97), INT32_C(       -127), INT32_C(        121),
                            INT32_C(        -47), INT32_C(        -94), INT32_C(        -74), INT32_C(        -59)) },
    { simde_mm_set_epi8(INT8_C(  79), INT8_C(  98), INT8_C(  70), INT8_C( -29),
                        INT8_C(  61), INT8_C( 100), INT8_C( -92), INT8_C(  10),
                        INT8_C(-107), INT8_C( -13), INT8_C(  83), INT8_C(-102),
                        INT8_C( -54), INT8_C(  80), INT8_C(  43), INT8_C(  56)),
      simde_mm512_set_epi32(INT32_C(         79), INT32_C(         98), INT32_C(         70), INT32_C(        -29),
                            INT32_C(         61), INT32_C(        100), INT32_C(        -92), INT32_C(         10),
                            INT32_C(       -107), INT32_C(        -13), INT32_C(         83), INT32_C(       -102),
                            INT32_C(        -54), INT32_C(         80), INT32_C(         43), INT32_C(         56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_cvtepi8_epi32(test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cvtepi8_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  40), INT8_C( -85), INT8_C(  94), INT8_C(  35),
                        INT8_C( -54), INT8_C( -71), INT8_C(-106), INT8_C(-127),
                        INT8_C(  11), INT8_C( 105), INT8_C(  37), INT8_C(-105),
                        INT8_C(   6), INT8_C( -65), INT8_C(  17), INT8_C(  29)),
      simde_mm512_set_epi64(INT64_C(                  11), INT64_C(                 105),
                            INT64_C(                  37), INT64_C(                -105),
                            INT64_C(                   6), INT64_C(                 -65),
                            INT64_C(                  17), INT64_C(                  29)) },
    { simde_mm_set_epi8(INT8_C(  65), INT8_C( -98), INT8_C( -80), INT8_C( -71),
                        INT8_C( -32), INT8_C(  61), INT8_C( -91), INT8_C(   2),
                        INT8_C(  62), INT8_C(  86), INT8_C( -39), INT8_C( -20),
                        INT8_C(  65), INT8_C( -87), INT8_C( 116), INT8_C(-112)),
      simde_mm512_set_epi64(INT64_C(                  62), INT64_C(                  86),
                            INT64_C(                 -39), INT64_C(                 -20),
                            INT64_C(                  65), INT64_C(                 -87),
                            INT64_C(                 116), INT64_C(                -112)) },
    { simde_mm_set_epi8(INT8_C( -35), INT8_C(  91), INT8_C(  95), INT8_C( -91),
                        INT8_C(-120), INT8_C( -72), INT8_C(   6), INT8_C( 127),
                        INT8_C( -64), INT8_C(  43), INT8_C( -93), INT8_C(   8),
                        INT8_C( 105), INT8_C( -16), INT8_C(  39), INT8_C( 125)),
      simde_mm512_set_epi64(INT64_C(                 -64), INT64_C(                  43),
                            INT64_C(                 -93), INT64_C(                   8),
                            INT64_C(                 105), INT64_C(                 -16),
                            INT64_C(                  39), INT64_C(                 125)) },
    { simde_mm_set_epi8(INT8_C( 108), INT8_C( 105), INT8_C(  98), INT8_C( -57),
                        INT8_C( -42), INT8_C( -18), INT8_C( -55), INT8_C(  -1),
                        INT8_C( -97), INT8_C( -26), INT8_C( -21), INT8_C(-119),
                        INT8_C(  95), INT8_C(  83), INT8_C( -95), INT8_C(  86)),
      simde_mm512_set_epi64(INT64_C(                 -97), INT64_C(                 -26),
                            INT64_C(                 -21), INT64_C(                -119),
                            INT64_C(                  95), INT64_C(                  83),
                            INT64_C(                 -95), INT64_C(                  86)) },
    { simde_mm_set_epi8(INT8_C(  63), INT8_C(-119), INT8_C(  65), INT8_C( 108),
                        INT8_C( -17), INT8_C( -16), INT8_C(  -4), INT8_C(  16),
                        INT8_C(-117), INT8_C( -62), INT8_C( -96), INT8_C(   5),
                        INT8_C( 116), INT8_C( -58), INT8_C( -56), INT8_C(-121)),
      simde_mm512_set_epi64(INT64_C(                -117), INT64_C(                 -62),
                            INT64_C(                 -96), INT64_C(                   5),
                            INT64_C(                 116), INT64_C(                 -58),
                            INT64_C(                 -56), INT64_C(                -121)) },
    { simde_mm_set_epi8(INT8_C( -69), INT8_C(  98), INT8_C(  52), INT8_C( -73),
                        INT8_C(  71), INT8_C(  44), INT8_C( -92), INT8_C(  54),
                        INT8_C( 126), INT8_C(  88), INT8_C(  32), INT8_C(-122),
                        INT8_C( -69), INT8_C( -55), INT8_C(-123), INT8_C(  79)),
      simde_mm512_set_epi64(INT64_C(                 126), INT64_C(                  88),
                            INT64_C(                  32), INT64_C(                -122),
                            INT64_C(                 -69), INT64_C(                 -55),
                            INT64_C(                -123), INT64_C(                  79)) },
    { simde_mm_set_epi8(INT8_C(-110), INT8_C( -17), INT8_C( -48), INT8_C( -64),
                        INT8_C(   9), INT8_C(  96), INT8_C( 113), INT8_C( -55),
                        INT8_C( -45), INT8_C(  -9), INT8_C( 104), INT8_C( -61),
                        INT8_C( 127), INT8_C( 121), INT8_C(  70), INT8_C( -22)),
      simde_mm512_set_epi64(INT64_C(                 -45), INT64_C(                  -9),
                            INT64_C(                 104), INT64_C(                 -61),
                            INT64_C(                 127), INT64_C(                 121),
                            INT64_C(                  70), INT64_C(                 -22)) },
    { simde_mm_set_epi8(INT8_C(  68), INT8_C( -24), INT8_C(  90), INT8_C( -28),
                        INT8_C(  55), INT8_C( -48), INT8_C(  13), INT8_C(  95),
                        INT8_C(  10), INT8_C( -72), INT8_C( 109), INT8_C( -27),
                        INT8_C(  94), INT8_C( 121), INT8_C(  33), INT8_C(  52)),
      simde_mm512_set_epi64(INT64_C(                  10), INT64_C(                 -72),
                            INT64_C(                 109), INT64_C(                 -27),
                            INT64_C(                  94), INT64_C(                 121),
                            INT64_C(                  33), INT64_C(                  52)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_cvtepi8_epi64(test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cvtepi32_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(         -2), INT32_C(         -4), INT32_C( -120451969), INT32_C(      14509),
                            INT32_C(      -1510), INT32_C(      98804), INT32_C(       1802), INT32_C(     -32352),
                            INT32_C(      14540), INT32_C(         -2), INT32_C(        222), INT32_C(        152),
                            INT32_C(     -48720), INT32_C(     250746), INT32_C(         15), INT32_C(         -2)),
      simde_mm_set_epi8(INT8_C(  -2), INT8_C(  -4), INT8_C( 127), INT8_C( -83),
                        INT8_C(  26), INT8_C( -12), INT8_C(  10), INT8_C( -96),
                        INT8_C( -52), INT8_C(  -2), INT8_C( -34), INT8_C(-104),
                        INT8_C( -80), INT8_C( 122), INT8_C(  15), INT8_C(  -2)) },
    { simde_mm512_set_epi32(INT32_C(   -2537924), INT32_C(          0), INT32_C(       3842), INT32_C(    -439330),
                            INT32_C(      39001), INT32_C(         -1), INT32_C(   32480192), INT32_C(          0),
                            INT32_C(          4), INT32_C(  -11661865), INT32_C(          0), INT32_C(          2),
                            INT32_C(      63322), INT32_C(        -33), INT32_C(      14448), INT32_C(          2)),
      simde_mm_set_epi8(INT8_C(  60), INT8_C(   0), INT8_C(   2), INT8_C( -34),
                        INT8_C(  89), INT8_C(  -1), INT8_C( -64), INT8_C(   0),
                        INT8_C(   4), INT8_C( -41), INT8_C(   0), INT8_C(   2),
                        INT8_C(  90), INT8_C( -33), INT8_C( 112), INT8_C(   2)) },
    { simde_mm512_set_epi32(INT32_C(        -18), INT32_C(   -2011647), INT32_C(   -7768922), INT32_C( -921783558),
                            INT32_C(   -1941821), INT32_C(          0), INT32_C(    -647690), INT32_C(      -5119),
                            INT32_C(         -1), INT32_C(        343), INT32_C(  113610714), INT32_C(          3),
                            INT32_C(      38353), INT32_C(        246), INT32_C(  -10559231), INT32_C(       8543)),
      simde_mm_set_epi8(INT8_C( -18), INT8_C(   1), INT8_C( -90), INT8_C(  -6),
                        INT8_C( -61), INT8_C(   0), INT8_C( -10), INT8_C(   1),
                        INT8_C(  -1), INT8_C(  87), INT8_C( -38), INT8_C(   3),
                        INT8_C( -47), INT8_C( -10), INT8_C(   1), INT8_C(  95)) },
    { simde_mm512_set_epi32(INT32_C( -177879544), INT32_C(         -4), INT32_C(         -1), INT32_C(      -1874),
                            INT32_C(         -4), INT32_C( -469598096), INT32_C(      -1647), INT32_C(     129553),
                            INT32_C(    9710669), INT32_C(          3), INT32_C(    1473856), INT32_C(  134714256),
                            INT32_C(   70527996), INT32_C(    2339642), INT32_C(     148218), INT32_C(  -32767248)),
      simde_mm_set_epi8(INT8_C(   8), INT8_C(  -4), INT8_C(  -1), INT8_C( -82),
                        INT8_C(  -4), INT8_C( 112), INT8_C(-111), INT8_C(  17),
                        INT8_C(  77), INT8_C(   3), INT8_C(  64), INT8_C(-112),
                        INT8_C(  -4), INT8_C(  58), INT8_C(  -6), INT8_C( -16)) },
    { simde_mm512_set_epi32(INT32_C(   -1418204), INT32_C(    -122943), INT32_C(     799821), INT32_C(        -51),
                            INT32_C(     207931), INT32_C(  -11778782), INT32_C(      66993), INT32_C(     -15812),
                            INT32_C(   55345677), INT32_C( -194873886), INT32_C(      -3955), INT32_C(        -22),
                            INT32_C(       1761), INT32_C(        751), INT32_C(         19), INT32_C(         -4)),
      simde_mm_set_epi8(INT8_C(  36), INT8_C( -63), INT8_C(  77), INT8_C( -51),
                        INT8_C(  59), INT8_C(  34), INT8_C( -79), INT8_C(  60),
                        INT8_C(  13), INT8_C( -30), INT8_C(-115), INT8_C( -22),
                        INT8_C( -31), INT8_C( -17), INT8_C(  19), INT8_C(  -4)) },
    { simde_mm512_set_epi32(INT32_C(        -17), INT32_C(        -26), INT32_C(     854285), INT32_C(         51),
                            INT32_C(  -60746537), INT32_C(    3687234), INT32_C(   52848365), INT32_C(   26958727),
                            INT32_C(          2), INT32_C(        104), INT32_C(    4725058), INT32_C(     -56297),
                            INT32_C(       5336), INT32_C(     443041), INT32_C(        -35), INT32_C(     229612)),
      simde_mm_set_epi8(INT8_C( -17), INT8_C( -26), INT8_C(  13), INT8_C(  51),
                        INT8_C( -41), INT8_C(  66), INT8_C( -19), INT8_C(-121),
                        INT8_C(   2), INT8_C( 104), INT8_C(  66), INT8_C(  23),
                        INT8_C( -40), INT8_C( -95), INT8_C( -35), INT8_C( -20)) },
    { simde_mm512_set_epi32(INT32_C(        -27), INT32_C(  127397292), INT32_C(   29325489), INT32_C(        691),
                            INT32_C(       -978), INT32_C(    -559751), INT32_C(   -3037707), INT32_C(     189833),
                            INT32_C(         11), INT32_C(   -4085970), INT32_C(      -3499), INT32_C(     -16323),
                            INT32_C(     732682), INT32_C(     108115), INT32_C(   29565452), INT32_C( -145574324)),
      simde_mm_set_epi8(INT8_C( -27), INT8_C( -84), INT8_C( -79), INT8_C( -77),
                        INT8_C(  46), INT8_C( 121), INT8_C( -11), INT8_C(-119),
                        INT8_C(  11), INT8_C(  46), INT8_C(  85), INT8_C(  61),
                        INT8_C(  10), INT8_C(  83), INT8_C(  12), INT8_C(  76)) },
    { simde_mm512_set_epi32(INT32_C(        -14), INT32_C(    6208981), INT32_C(  133763173), INT32_C(  -30227251),
                            INT32_C(  -17898651), INT32_C( -197203605), INT32_C(         -4), INT32_C(         13),
                            INT32_C(   -1312564), INT32_C(         -3), INT32_C(    5632807), INT32_C(       2549),
                            INT32_C(         -3), INT32_C(      -2772), INT32_C(      -1504), INT32_C(          1)),
      simde_mm_set_epi8(INT8_C( -14), INT8_C( -43), INT8_C( 101), INT8_C( -51),
                        INT8_C( 101), INT8_C( 107), INT8_C(  -4), INT8_C(  13),
                        INT8_C( -52), INT8_C(  -3), INT8_C(  39), INT8_C( -11),
                        INT8_C(  -3), INT8_C(  44), INT8_C(  32), INT8_C(   1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_cvtepi32_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cvtepi64_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(              273955), INT64_C(               -4013),
                            INT64_C(            -7033556), INT64_C(      -1383025729160),
                            INT64_C(          -218214744), INT64_C(   -9402863842296753),
                            INT64_C(                   0), INT64_C(          -240066712)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  35), INT8_C(  83), INT8_C(  44), INT8_C( 120),
                        INT8_C( -88), INT8_C(  79), INT8_C(   0), INT8_C( 104)) },
    { simde_mm512_set_epi64(INT64_C(               50833), INT64_C(           484208564),
                            INT64_C(                -124), INT64_C(         -8907018595),
                            INT64_C(         -1053135968), INT64_C(    2128258677497261),
                            INT64_C(                   3), INT64_C(  263107913893504060)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-111), INT8_C( -76), INT8_C(-124), INT8_C( -99),
                        INT8_C( -96), INT8_C( -83), INT8_C(   3), INT8_C(  60)) },
    { simde_mm512_set_epi64(INT64_C(    6119961081599912), INT64_C(                 949),
                            INT64_C(  761714638418543261), INT64_C(         -7281666562),
                            INT64_C(         -3399190417), INT64_C(                 231),
                            INT64_C(-1217801394263696454), INT64_C(                  43)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( -88), INT8_C( -75), INT8_C( -99), INT8_C(  -2),
                        INT8_C( 111), INT8_C( -25), INT8_C( -70), INT8_C(  43)) },
    { simde_mm512_set_epi64(INT64_C(     -74999030828832), INT64_C(       3805264232880),
                            INT64_C(              321542), INT64_C(        -18067967511),
                            INT64_C(      21602392348127), INT64_C(          -482358781),
                            INT64_C(              -12189), INT64_C(   16807900958735709)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( -32), INT8_C( -80), INT8_C(   6), INT8_C( -23),
                        INT8_C( -33), INT8_C(   3), INT8_C(  99), INT8_C(  93)) },
    { simde_mm512_set_epi64(INT64_C(               11997), INT64_C(                 192),
                            INT64_C(        -32039837063), INT64_C(               39788),
                            INT64_C(           684970521), INT64_C(     361409660761858),
                            INT64_C(   27655177518327113), INT64_C(         -7050752136)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( -35), INT8_C( -64), INT8_C( 121), INT8_C( 108),
                        INT8_C(  25), INT8_C(   2), INT8_C(  73), INT8_C( 120)) },
    { simde_mm512_set_epi64(INT64_C(    -131967536383739), INT64_C(                 -32),
                            INT64_C(                 -54), INT64_C(                -245),
                            INT64_C(              -42658), INT64_C(                   3),
                            INT64_C(         26934708458), INT64_C(               -6255)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   5), INT8_C( -32), INT8_C( -54), INT8_C(  11),
                        INT8_C(  94), INT8_C(   3), INT8_C( -22), INT8_C(-111)) },
    { simde_mm512_set_epi64(INT64_C(                   0), INT64_C(-4069220464223700234),
                            INT64_C(                   0), INT64_C(-8071151262900075656),
                            INT64_C(                  -1), INT64_C(          4132460747),
                            INT64_C(                 -27), INT64_C(            -7116923)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C( -10), INT8_C(   0), INT8_C( 120),
                        INT8_C(  -1), INT8_C( -53), INT8_C( -27), INT8_C(-123)) },
    { simde_mm512_set_epi64(INT64_C(         54634445793), INT64_C(         63569905620),
                            INT64_C(            20981054), INT64_C(             2614918),
                            INT64_C(         11917164823), INT64_C(   15401551242937960),
                            INT64_C(                  -1), INT64_C(        366397165244)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( -31), INT8_C( -44), INT8_C(  62), INT8_C(-122),
                        INT8_C(  23), INT8_C( 104), INT8_C(  -1), INT8_C( -68)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_cvtepi64_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

#endif /* defined(SIMDE_avx512f_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_AVX512F_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm512_castpd512_pd128),
  SIMDE_TESTS_DEFINE_TEST(mm512_castpd512_pd256),
  SIMDE_TESTS_DEFINE_TEST(mm512_castps512_ps128),
  SIMDE_TESTS_DEFINE_TEST(mm512_castps512_ps256),
  SIMDE_TESTS_DEFINE_TEST(mm512_castsi512_si128),
  SIMDE_TESTS_DEFINE_TEST(mm512_castsi512_si256),

  SIMDE_TESTS_DEFINE_TEST(mm512_mask_mov_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_mov_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_mov_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_mov_pd),

  SIMDE_TESTS_DEFINE_TEST(mm512_maskz_mov_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm512_maskz_mov_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm512_maskz_mov_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_maskz_mov_pd),

  SIMDE_TESTS_DEFINE_TEST(mm512_setzero_si512),
  SIMDE_TESTS_DEFINE_TEST(mm512_setone_si512),

  SIMDE_TESTS_DEFINE_TEST(mm512_mask_test_epi32_mask),

  SIMDE_TESTS_DEFINE_TEST(mm512_add_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm512_add_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm512_add_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_add_pd),

  SIMDE_TESTS_DEFINE_TEST(mm512_and_si512),
  SIMDE_TESTS_DEFINE_TEST(mm512_andnot_si512),

  SIMDE_TESTS_DEFINE_TEST(mm512_mask_cmpeq_epi32_mask),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_cmpeq_epi64_mask),

  SIMDE_TESTS_DEFINE_TEST(mm512_cvtepi8_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm512_cvtepi8_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm512_cvtepi32_epi8),

  SIMDE_TESTS_DEFINE_TEST(mm512_cvtepi64_epi8),

#endif /* defined(SIMDE_AVX512f_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */
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
