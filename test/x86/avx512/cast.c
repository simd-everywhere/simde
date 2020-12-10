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
 */

#define SIMDE_TEST_X86_AVX512_INSN cast

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/cast.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/mov.h>

static int
test_simde_mm512_castpd512_pd128(SIMDE_MUNIT_TEST_ARGS) {
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

  return 0;
}

static int
test_simde_mm512_castpd512_pd256(SIMDE_MUNIT_TEST_ARGS) {
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

  return 0;
}

static int
test_simde_mm512_castpd128_pd512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  605.48), SIMDE_FLOAT64_C(  349.95)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  605.48), SIMDE_FLOAT64_C(  349.95)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  125.01), SIMDE_FLOAT64_C(  -52.81)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  125.01), SIMDE_FLOAT64_C(  -52.81)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -137.83), SIMDE_FLOAT64_C( -367.46)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -137.83), SIMDE_FLOAT64_C( -367.46)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -706.70), SIMDE_FLOAT64_C(  -54.57)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -706.70), SIMDE_FLOAT64_C(  -54.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -477.44), SIMDE_FLOAT64_C( -678.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -477.44), SIMDE_FLOAT64_C( -678.80)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -750.01), SIMDE_FLOAT64_C(  943.83)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -750.01), SIMDE_FLOAT64_C(  943.83)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  329.32), SIMDE_FLOAT64_C(  600.02)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  329.32), SIMDE_FLOAT64_C(  600.02)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  495.92), SIMDE_FLOAT64_C(  855.97)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  495.92), SIMDE_FLOAT64_C(  855.97)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_castpd128_pd512(test_vec[i].a);
    r=simde_mm512_maskz_mov_pd(UINT8_C(3), r);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_castpd256_pd512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256d a;
    simde__m512d r;
  } test_vec[8] = {
        { simde_mm256_set_pd(SIMDE_FLOAT64_C( -610.76), SIMDE_FLOAT64_C( -445.99),
                         SIMDE_FLOAT64_C( -292.19), SIMDE_FLOAT64_C(  327.18)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -610.76), SIMDE_FLOAT64_C( -445.99),
                         SIMDE_FLOAT64_C( -292.19), SIMDE_FLOAT64_C(  327.18)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  498.95), SIMDE_FLOAT64_C(  765.72),
                         SIMDE_FLOAT64_C( -978.89), SIMDE_FLOAT64_C( -427.55)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  498.95), SIMDE_FLOAT64_C(  765.72),
                         SIMDE_FLOAT64_C( -978.89), SIMDE_FLOAT64_C( -427.55)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -991.71), SIMDE_FLOAT64_C(  -66.46),
                         SIMDE_FLOAT64_C(  -87.69), SIMDE_FLOAT64_C(  225.73)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -991.71), SIMDE_FLOAT64_C(  -66.46),
                         SIMDE_FLOAT64_C(  -87.69), SIMDE_FLOAT64_C(  225.73)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -983.02), SIMDE_FLOAT64_C(  768.15),
                         SIMDE_FLOAT64_C(  423.32), SIMDE_FLOAT64_C( -601.96)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -983.02), SIMDE_FLOAT64_C(  768.15),
                         SIMDE_FLOAT64_C(  423.32), SIMDE_FLOAT64_C( -601.96)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  269.59), SIMDE_FLOAT64_C(  -12.98),
                         SIMDE_FLOAT64_C(  833.22), SIMDE_FLOAT64_C( -167.34)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  269.59), SIMDE_FLOAT64_C(  -12.98),
                         SIMDE_FLOAT64_C(  833.22), SIMDE_FLOAT64_C( -167.34)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -976.56), SIMDE_FLOAT64_C( -631.12),
                         SIMDE_FLOAT64_C( -613.64), SIMDE_FLOAT64_C( -574.89)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -976.56), SIMDE_FLOAT64_C( -631.12),
                         SIMDE_FLOAT64_C( -613.64), SIMDE_FLOAT64_C( -574.89)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  900.29), SIMDE_FLOAT64_C(  197.75),
                         SIMDE_FLOAT64_C( -976.11), SIMDE_FLOAT64_C( -958.45)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  900.29), SIMDE_FLOAT64_C(  197.75),
                         SIMDE_FLOAT64_C( -976.11), SIMDE_FLOAT64_C( -958.45)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -467.55), SIMDE_FLOAT64_C( -302.23),
                         SIMDE_FLOAT64_C(  207.74), SIMDE_FLOAT64_C( -217.89)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -467.55), SIMDE_FLOAT64_C( -302.23),
                         SIMDE_FLOAT64_C(  207.74), SIMDE_FLOAT64_C( -217.89)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_castpd256_pd512(test_vec[i].a);
    r=simde_mm512_maskz_mov_pd(UINT8_C(15), r);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_castps512_ps128(SIMDE_MUNIT_TEST_ARGS) {
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

  return 0;
}

static int
test_simde_mm512_castps512_ps256(SIMDE_MUNIT_TEST_ARGS) {
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

  return 0;
}

static int
test_simde_mm512_castps_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -475.09), SIMDE_FLOAT32_C(   736.84), SIMDE_FLOAT32_C(  -702.97), SIMDE_FLOAT32_C(  -433.94),
                         SIMDE_FLOAT32_C(   854.93), SIMDE_FLOAT32_C(  -157.11), SIMDE_FLOAT32_C(    43.61), SIMDE_FLOAT32_C(  -310.79),
                         SIMDE_FLOAT32_C(  -893.63), SIMDE_FLOAT32_C(    37.00), SIMDE_FLOAT32_C(   245.96), SIMDE_FLOAT32_C(   381.92),
                         SIMDE_FLOAT32_C(  -702.80), SIMDE_FLOAT32_C(   931.47), SIMDE_FLOAT32_C(   429.22), SIMDE_FLOAT32_C(  -639.06)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -475.09), SIMDE_FLOAT32_C(   736.84), SIMDE_FLOAT32_C(  -702.97), SIMDE_FLOAT32_C(  -433.94),
                         SIMDE_FLOAT32_C(   854.93), SIMDE_FLOAT32_C(  -157.11), SIMDE_FLOAT32_C(    43.61), SIMDE_FLOAT32_C(  -310.79),
                         SIMDE_FLOAT32_C(  -893.63), SIMDE_FLOAT32_C(    37.00), SIMDE_FLOAT32_C(   245.96), SIMDE_FLOAT32_C(   381.92),
                         SIMDE_FLOAT32_C(  -702.80), SIMDE_FLOAT32_C(   931.47), SIMDE_FLOAT32_C(   429.22), SIMDE_FLOAT32_C(  -639.06)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -147.89), SIMDE_FLOAT32_C(   347.19), SIMDE_FLOAT32_C(   203.54), SIMDE_FLOAT32_C(  -988.99),
                         SIMDE_FLOAT32_C(   306.65), SIMDE_FLOAT32_C(   641.36), SIMDE_FLOAT32_C(  -965.49), SIMDE_FLOAT32_C(  -587.11),
                         SIMDE_FLOAT32_C(   724.40), SIMDE_FLOAT32_C(  -636.19), SIMDE_FLOAT32_C(  -368.06), SIMDE_FLOAT32_C(   887.68),
                         SIMDE_FLOAT32_C(  -970.41), SIMDE_FLOAT32_C(  -566.45), SIMDE_FLOAT32_C(   791.35), SIMDE_FLOAT32_C(  -284.64)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -147.89), SIMDE_FLOAT32_C(   347.19), SIMDE_FLOAT32_C(   203.54), SIMDE_FLOAT32_C(  -988.99),
                         SIMDE_FLOAT32_C(   306.65), SIMDE_FLOAT32_C(   641.36), SIMDE_FLOAT32_C(  -965.49), SIMDE_FLOAT32_C(  -587.11),
                         SIMDE_FLOAT32_C(   724.40), SIMDE_FLOAT32_C(  -636.19), SIMDE_FLOAT32_C(  -368.06), SIMDE_FLOAT32_C(   887.68),
                         SIMDE_FLOAT32_C(  -970.41), SIMDE_FLOAT32_C(  -566.45), SIMDE_FLOAT32_C(   791.35), SIMDE_FLOAT32_C(  -284.64)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -73.77), SIMDE_FLOAT32_C(  -499.31), SIMDE_FLOAT32_C(   113.82), SIMDE_FLOAT32_C(  -847.95),
                         SIMDE_FLOAT32_C(  -593.73), SIMDE_FLOAT32_C(   978.06), SIMDE_FLOAT32_C(   354.00), SIMDE_FLOAT32_C(  -120.89),
                         SIMDE_FLOAT32_C(  -554.86), SIMDE_FLOAT32_C(  -105.83), SIMDE_FLOAT32_C(   247.41), SIMDE_FLOAT32_C(   728.79),
                         SIMDE_FLOAT32_C(  -359.78), SIMDE_FLOAT32_C(  -375.68), SIMDE_FLOAT32_C(  -456.84), SIMDE_FLOAT32_C(  -859.51)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -73.77), SIMDE_FLOAT32_C(  -499.31), SIMDE_FLOAT32_C(   113.82), SIMDE_FLOAT32_C(  -847.95),
                         SIMDE_FLOAT32_C(  -593.73), SIMDE_FLOAT32_C(   978.06), SIMDE_FLOAT32_C(   354.00), SIMDE_FLOAT32_C(  -120.89),
                         SIMDE_FLOAT32_C(  -554.86), SIMDE_FLOAT32_C(  -105.83), SIMDE_FLOAT32_C(   247.41), SIMDE_FLOAT32_C(   728.79),
                         SIMDE_FLOAT32_C(  -359.78), SIMDE_FLOAT32_C(  -375.68), SIMDE_FLOAT32_C(  -456.84), SIMDE_FLOAT32_C(  -859.51)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -892.63), SIMDE_FLOAT32_C(   554.75), SIMDE_FLOAT32_C(   786.31), SIMDE_FLOAT32_C(   695.92),
                         SIMDE_FLOAT32_C(  -629.78), SIMDE_FLOAT32_C(   376.00), SIMDE_FLOAT32_C(   490.47), SIMDE_FLOAT32_C(  -658.22),
                         SIMDE_FLOAT32_C(  -993.58), SIMDE_FLOAT32_C(   931.16), SIMDE_FLOAT32_C(   896.06), SIMDE_FLOAT32_C(  -621.22),
                         SIMDE_FLOAT32_C(   936.87), SIMDE_FLOAT32_C(  -330.96), SIMDE_FLOAT32_C(   683.22), SIMDE_FLOAT32_C(   273.63)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -892.63), SIMDE_FLOAT32_C(   554.75), SIMDE_FLOAT32_C(   786.31), SIMDE_FLOAT32_C(   695.92),
                         SIMDE_FLOAT32_C(  -629.78), SIMDE_FLOAT32_C(   376.00), SIMDE_FLOAT32_C(   490.47), SIMDE_FLOAT32_C(  -658.22),
                         SIMDE_FLOAT32_C(  -993.58), SIMDE_FLOAT32_C(   931.16), SIMDE_FLOAT32_C(   896.06), SIMDE_FLOAT32_C(  -621.22),
                         SIMDE_FLOAT32_C(   936.87), SIMDE_FLOAT32_C(  -330.96), SIMDE_FLOAT32_C(   683.22), SIMDE_FLOAT32_C(   273.63)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -464.48), SIMDE_FLOAT32_C(   711.99), SIMDE_FLOAT32_C(   146.80), SIMDE_FLOAT32_C(  -790.19),
                         SIMDE_FLOAT32_C(  -196.31), SIMDE_FLOAT32_C(   -19.08), SIMDE_FLOAT32_C(   390.50), SIMDE_FLOAT32_C(  -693.04),
                         SIMDE_FLOAT32_C(   121.41), SIMDE_FLOAT32_C(  -677.25), SIMDE_FLOAT32_C(   840.59), SIMDE_FLOAT32_C(   653.82),
                         SIMDE_FLOAT32_C(  -341.60), SIMDE_FLOAT32_C(  -152.67), SIMDE_FLOAT32_C(  -910.13), SIMDE_FLOAT32_C(   648.18)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -464.48), SIMDE_FLOAT32_C(   711.99), SIMDE_FLOAT32_C(   146.80), SIMDE_FLOAT32_C(  -790.19),
                         SIMDE_FLOAT32_C(  -196.31), SIMDE_FLOAT32_C(   -19.08), SIMDE_FLOAT32_C(   390.50), SIMDE_FLOAT32_C(  -693.04),
                         SIMDE_FLOAT32_C(   121.41), SIMDE_FLOAT32_C(  -677.25), SIMDE_FLOAT32_C(   840.59), SIMDE_FLOAT32_C(   653.82),
                         SIMDE_FLOAT32_C(  -341.60), SIMDE_FLOAT32_C(  -152.67), SIMDE_FLOAT32_C(  -910.13), SIMDE_FLOAT32_C(   648.18)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   610.99), SIMDE_FLOAT32_C(   354.13), SIMDE_FLOAT32_C(  -805.98), SIMDE_FLOAT32_C(   470.53),
                         SIMDE_FLOAT32_C(   848.62), SIMDE_FLOAT32_C(  -853.14), SIMDE_FLOAT32_C(   898.19), SIMDE_FLOAT32_C(  -186.52),
                         SIMDE_FLOAT32_C(  -954.10), SIMDE_FLOAT32_C(   887.52), SIMDE_FLOAT32_C(   607.34), SIMDE_FLOAT32_C(    42.34),
                         SIMDE_FLOAT32_C(  -842.20), SIMDE_FLOAT32_C(   627.26), SIMDE_FLOAT32_C(   417.38), SIMDE_FLOAT32_C(  -300.32)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   610.99), SIMDE_FLOAT32_C(   354.13), SIMDE_FLOAT32_C(  -805.98), SIMDE_FLOAT32_C(   470.53),
                         SIMDE_FLOAT32_C(   848.62), SIMDE_FLOAT32_C(  -853.14), SIMDE_FLOAT32_C(   898.19), SIMDE_FLOAT32_C(  -186.52),
                         SIMDE_FLOAT32_C(  -954.10), SIMDE_FLOAT32_C(   887.52), SIMDE_FLOAT32_C(   607.34), SIMDE_FLOAT32_C(    42.34),
                         SIMDE_FLOAT32_C(  -842.20), SIMDE_FLOAT32_C(   627.26), SIMDE_FLOAT32_C(   417.38), SIMDE_FLOAT32_C(  -300.32)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   -91.92), SIMDE_FLOAT32_C(  -128.53), SIMDE_FLOAT32_C(  -157.39), SIMDE_FLOAT32_C(   922.31),
                         SIMDE_FLOAT32_C(    68.36), SIMDE_FLOAT32_C(  -842.81), SIMDE_FLOAT32_C(    60.56), SIMDE_FLOAT32_C(   689.02),
                         SIMDE_FLOAT32_C(   -70.29), SIMDE_FLOAT32_C(  -753.33), SIMDE_FLOAT32_C(  -999.31), SIMDE_FLOAT32_C(    72.69),
                         SIMDE_FLOAT32_C(    47.99), SIMDE_FLOAT32_C(   903.18), SIMDE_FLOAT32_C(    -5.05), SIMDE_FLOAT32_C(  -435.35)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -91.92), SIMDE_FLOAT32_C(  -128.53), SIMDE_FLOAT32_C(  -157.39), SIMDE_FLOAT32_C(   922.31),
                         SIMDE_FLOAT32_C(    68.36), SIMDE_FLOAT32_C(  -842.81), SIMDE_FLOAT32_C(    60.56), SIMDE_FLOAT32_C(   689.02),
                         SIMDE_FLOAT32_C(   -70.29), SIMDE_FLOAT32_C(  -753.33), SIMDE_FLOAT32_C(  -999.31), SIMDE_FLOAT32_C(    72.69),
                         SIMDE_FLOAT32_C(    47.99), SIMDE_FLOAT32_C(   903.18), SIMDE_FLOAT32_C(    -5.05), SIMDE_FLOAT32_C(  -435.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -687.13), SIMDE_FLOAT32_C(  -562.12), SIMDE_FLOAT32_C(  -564.90), SIMDE_FLOAT32_C(  -948.64),
                         SIMDE_FLOAT32_C(   287.72), SIMDE_FLOAT32_C(   -13.16), SIMDE_FLOAT32_C(   706.69), SIMDE_FLOAT32_C(    62.48),
                         SIMDE_FLOAT32_C(    15.33), SIMDE_FLOAT32_C(  -938.52), SIMDE_FLOAT32_C(  -548.66), SIMDE_FLOAT32_C(   893.31),
                         SIMDE_FLOAT32_C(  -166.31), SIMDE_FLOAT32_C(     3.21), SIMDE_FLOAT32_C(  -121.90), SIMDE_FLOAT32_C(  -237.87)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -687.13), SIMDE_FLOAT32_C(  -562.12), SIMDE_FLOAT32_C(  -564.90), SIMDE_FLOAT32_C(  -948.64),
                         SIMDE_FLOAT32_C(   287.72), SIMDE_FLOAT32_C(   -13.16), SIMDE_FLOAT32_C(   706.69), SIMDE_FLOAT32_C(    62.48),
                         SIMDE_FLOAT32_C(    15.33), SIMDE_FLOAT32_C(  -938.52), SIMDE_FLOAT32_C(  -548.66), SIMDE_FLOAT32_C(   893.31),
                         SIMDE_FLOAT32_C(  -166.31), SIMDE_FLOAT32_C(     3.21), SIMDE_FLOAT32_C(  -121.90), SIMDE_FLOAT32_C(  -237.87)) }
  };
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
  simde__m512 r = simde_mm512_castpd_ps(simde_mm512_castps_pd(test_vec[i].a));
  simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_castsi512_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 1318886849), INT32_C( -963615992), INT32_C( 1168255165), INT32_C(-1910220907),
                            INT32_C( -362848940), INT32_C( 1228894571), INT32_C( -604141281), INT32_C( -310556576),
                            INT32_C( -195291453), INT32_C(-1762187610), INT32_C(  785462248), INT32_C(-1654799886),
                            INT32_C(  443157727), INT32_C(  291457152), INT32_C( -673220379), INT32_C( 1588648097)),
      simde_mm512_set_epi32(INT32_C( 1318886849), INT32_C( -963615992), INT32_C( 1168255165), INT32_C(-1910220907),
                            INT32_C( -362848940), INT32_C( 1228894571), INT32_C( -604141281), INT32_C( -310556576),
                            INT32_C( -195291453), INT32_C(-1762187610), INT32_C(  785462248), INT32_C(-1654799886),
                            INT32_C(  443157727), INT32_C(  291457152), INT32_C( -673220379), INT32_C( 1588648097)) },
    { simde_mm512_set_epi32(INT32_C(  388365668), INT32_C( 1922479678), INT32_C(-1025869072), INT32_C( 1053113602),
                            INT32_C( -948060413), INT32_C( 1300260897), INT32_C(  723694906), INT32_C( 1579982945),
                            INT32_C(  551168292), INT32_C( 2117629385), INT32_C( 1278333888), INT32_C(-1219831740),
                            INT32_C( 1012175805), INT32_C(-2142193359), INT32_C(-1234937614), INT32_C(  296489222)),
      simde_mm512_set_epi32(INT32_C(  388365668), INT32_C( 1922479678), INT32_C(-1025869072), INT32_C( 1053113602),
                            INT32_C( -948060413), INT32_C( 1300260897), INT32_C(  723694906), INT32_C( 1579982945),
                            INT32_C(  551168292), INT32_C( 2117629385), INT32_C( 1278333888), INT32_C(-1219831740),
                            INT32_C( 1012175805), INT32_C(-2142193359), INT32_C(-1234937614), INT32_C(  296489222)) },
    { simde_mm512_set_epi32(INT32_C( 1558252976), INT32_C( -896391163), INT32_C( -282653026), INT32_C( -261252112),
                            INT32_C(-1886684518), INT32_C( -792082029), INT32_C(-1821569388), INT32_C(  452082945),
                            INT32_C( 1996286767), INT32_C( -816391022), INT32_C(   52318481), INT32_C( -732357064),
                            INT32_C(-1730294171), INT32_C( 1249707888), INT32_C( 1882801706), INT32_C( -348126448)),
      simde_mm512_set_epi32(INT32_C( 1558252976), INT32_C( -896391163), INT32_C( -282653026), INT32_C( -261252112),
                            INT32_C(-1886684518), INT32_C( -792082029), INT32_C(-1821569388), INT32_C(  452082945),
                            INT32_C( 1996286767), INT32_C( -816391022), INT32_C(   52318481), INT32_C( -732357064),
                            INT32_C(-1730294171), INT32_C( 1249707888), INT32_C( 1882801706), INT32_C( -348126448)) },
    { simde_mm512_set_epi32(INT32_C(-1306007403), INT32_C(  -14823844), INT32_C(   68140915), INT32_C(-1279691583),
                            INT32_C( -366833324), INT32_C( 1029809788), INT32_C(  398169753), INT32_C( 1644631001),
                            INT32_C(-1495643320), INT32_C( -349662299), INT32_C(  337000079), INT32_C(-1599869755),
                            INT32_C( -326525511), INT32_C( 2145777358), INT32_C( -671246537), INT32_C(-1483766126)),
      simde_mm512_set_epi32(INT32_C(-1306007403), INT32_C(  -14823844), INT32_C(   68140915), INT32_C(-1279691583),
                            INT32_C( -366833324), INT32_C( 1029809788), INT32_C(  398169753), INT32_C( 1644631001),
                            INT32_C(-1495643320), INT32_C( -349662299), INT32_C(  337000079), INT32_C(-1599869755),
                            INT32_C( -326525511), INT32_C( 2145777358), INT32_C( -671246537), INT32_C(-1483766126)) },
    { simde_mm512_set_epi32(INT32_C( 1306718049), INT32_C( -481786167), INT32_C( 1036658403), INT32_C(-1275842496),
                            INT32_C(-1384128337), INT32_C( 1110346848), INT32_C( 1633808121), INT32_C(  818679772),
                            INT32_C(  528120539), INT32_C( 1454269875), INT32_C(-1309905851), INT32_C(  195834431),
                            INT32_C( 1710057355), INT32_C(-1286641516), INT32_C( -825070396), INT32_C(-1314661204)),
      simde_mm512_set_epi32(INT32_C( 1306718049), INT32_C( -481786167), INT32_C( 1036658403), INT32_C(-1275842496),
                            INT32_C(-1384128337), INT32_C( 1110346848), INT32_C( 1633808121), INT32_C(  818679772),
                            INT32_C(  528120539), INT32_C( 1454269875), INT32_C(-1309905851), INT32_C(  195834431),
                            INT32_C( 1710057355), INT32_C(-1286641516), INT32_C( -825070396), INT32_C(-1314661204)) },
    { simde_mm512_set_epi32(INT32_C(  897666230), INT32_C(-1247200387), INT32_C(-1594960612), INT32_C(  784358708),
                            INT32_C( -639715103), INT32_C( 1722588202), INT32_C( -957042730), INT32_C( 1748493888),
                            INT32_C(-1424605467), INT32_C( 1715503797), INT32_C(-1877902145), INT32_C( 1433291829),
                            INT32_C(-1672795293), INT32_C( -125523250), INT32_C(  817060741), INT32_C(-1940108057)),
      simde_mm512_set_epi32(INT32_C(  897666230), INT32_C(-1247200387), INT32_C(-1594960612), INT32_C(  784358708),
                            INT32_C( -639715103), INT32_C( 1722588202), INT32_C( -957042730), INT32_C( 1748493888),
                            INT32_C(-1424605467), INT32_C( 1715503797), INT32_C(-1877902145), INT32_C( 1433291829),
                            INT32_C(-1672795293), INT32_C( -125523250), INT32_C(  817060741), INT32_C(-1940108057)) },
    { simde_mm512_set_epi32(INT32_C( -771897847), INT32_C(   51088448), INT32_C(  731748986), INT32_C(-2010019631),
                            INT32_C(-1805256328), INT32_C( -982668321), INT32_C(-1986983933), INT32_C( -806537017),
                            INT32_C( 2103732941), INT32_C(-1950119891), INT32_C( -262758582), INT32_C( -704905824),
                            INT32_C( -298698020), INT32_C( -290664422), INT32_C( -169474404), INT32_C( -381923585)),
      simde_mm512_set_epi32(INT32_C( -771897847), INT32_C(   51088448), INT32_C(  731748986), INT32_C(-2010019631),
                            INT32_C(-1805256328), INT32_C( -982668321), INT32_C(-1986983933), INT32_C( -806537017),
                            INT32_C( 2103732941), INT32_C(-1950119891), INT32_C( -262758582), INT32_C( -704905824),
                            INT32_C( -298698020), INT32_C( -290664422), INT32_C( -169474404), INT32_C( -381923585)) },
    { simde_mm512_set_epi32(INT32_C(-1424890095), INT32_C( -662922774), INT32_C( 1172732731), INT32_C(  220940559),
                            INT32_C(  736508018), INT32_C(-1201335155), INT32_C( -747976663), INT32_C( 1864271935),
                            INT32_C( 1893933430), INT32_C(  214467364), INT32_C(-1230640603), INT32_C(-1529352277),
                            INT32_C(  301681975), INT32_C(  -86355089), INT32_C( 1945634979), INT32_C( 1310017249)),
      simde_mm512_set_epi32(INT32_C(-1424890095), INT32_C( -662922774), INT32_C( 1172732731), INT32_C(  220940559),
                            INT32_C(  736508018), INT32_C(-1201335155), INT32_C( -747976663), INT32_C( 1864271935),
                            INT32_C( 1893933430), INT32_C(  214467364), INT32_C(-1230640603), INT32_C(-1529352277),
                            INT32_C(  301681975), INT32_C(  -86355089), INT32_C( 1945634979), INT32_C( 1310017249)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castps_si512(simde_mm512_castsi512_ps(test_vec[i].a));
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_castpd_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -499.76), SIMDE_FLOAT64_C(   568.93), SIMDE_FLOAT64_C(   465.37), SIMDE_FLOAT64_C(  -672.01),
        SIMDE_FLOAT64_C(  -851.41), SIMDE_FLOAT64_C(  -865.69), SIMDE_FLOAT64_C(  -361.86), SIMDE_FLOAT64_C(  -897.41) },
      { SIMDE_FLOAT64_C(  -499.76), SIMDE_FLOAT64_C(   568.93), SIMDE_FLOAT64_C(   465.37), SIMDE_FLOAT64_C(  -672.01),
        SIMDE_FLOAT64_C(  -851.41), SIMDE_FLOAT64_C(  -865.69), SIMDE_FLOAT64_C(  -361.86), SIMDE_FLOAT64_C(  -897.41) } },
    { { SIMDE_FLOAT64_C(   538.51), SIMDE_FLOAT64_C(  -244.20), SIMDE_FLOAT64_C(   337.99), SIMDE_FLOAT64_C(  -687.18),
        SIMDE_FLOAT64_C(   145.70), SIMDE_FLOAT64_C(   844.87), SIMDE_FLOAT64_C(   753.87), SIMDE_FLOAT64_C(   452.47) },
      { SIMDE_FLOAT64_C(   538.51), SIMDE_FLOAT64_C(  -244.20), SIMDE_FLOAT64_C(   337.99), SIMDE_FLOAT64_C(  -687.18),
        SIMDE_FLOAT64_C(   145.70), SIMDE_FLOAT64_C(   844.87), SIMDE_FLOAT64_C(   753.87), SIMDE_FLOAT64_C(   452.47) } },
    { { SIMDE_FLOAT64_C(  -653.48), SIMDE_FLOAT64_C(  -270.86), SIMDE_FLOAT64_C(  -547.24), SIMDE_FLOAT64_C(  -931.09),
        SIMDE_FLOAT64_C(   -78.54), SIMDE_FLOAT64_C(   915.72), SIMDE_FLOAT64_C(   958.51), SIMDE_FLOAT64_C(  -819.67) },
      { SIMDE_FLOAT64_C(  -653.48), SIMDE_FLOAT64_C(  -270.86), SIMDE_FLOAT64_C(  -547.24), SIMDE_FLOAT64_C(  -931.09),
        SIMDE_FLOAT64_C(   -78.54), SIMDE_FLOAT64_C(   915.72), SIMDE_FLOAT64_C(   958.51), SIMDE_FLOAT64_C(  -819.67) } },
    { { SIMDE_FLOAT64_C(   251.01), SIMDE_FLOAT64_C(   551.04), SIMDE_FLOAT64_C(   -32.00), SIMDE_FLOAT64_C(  -266.08),
        SIMDE_FLOAT64_C(   853.30), SIMDE_FLOAT64_C(   460.19), SIMDE_FLOAT64_C(   322.00), SIMDE_FLOAT64_C(  -646.46) },
      { SIMDE_FLOAT64_C(   251.01), SIMDE_FLOAT64_C(   551.04), SIMDE_FLOAT64_C(   -32.00), SIMDE_FLOAT64_C(  -266.08),
        SIMDE_FLOAT64_C(   853.30), SIMDE_FLOAT64_C(   460.19), SIMDE_FLOAT64_C(   322.00), SIMDE_FLOAT64_C(  -646.46) } },
    { { SIMDE_FLOAT64_C(    29.12), SIMDE_FLOAT64_C(  -212.62), SIMDE_FLOAT64_C(  -318.47), SIMDE_FLOAT64_C(   177.72),
        SIMDE_FLOAT64_C(   -78.31), SIMDE_FLOAT64_C(   319.66), SIMDE_FLOAT64_C(   280.31), SIMDE_FLOAT64_C(  -539.80) },
      { SIMDE_FLOAT64_C(    29.12), SIMDE_FLOAT64_C(  -212.62), SIMDE_FLOAT64_C(  -318.47), SIMDE_FLOAT64_C(   177.72),
        SIMDE_FLOAT64_C(   -78.31), SIMDE_FLOAT64_C(   319.66), SIMDE_FLOAT64_C(   280.31), SIMDE_FLOAT64_C(  -539.80) } },
    { { SIMDE_FLOAT64_C(  -924.54), SIMDE_FLOAT64_C(  -381.70), SIMDE_FLOAT64_C(  -226.98), SIMDE_FLOAT64_C(   221.16),
        SIMDE_FLOAT64_C(  -536.83), SIMDE_FLOAT64_C(  -473.11), SIMDE_FLOAT64_C(  -326.37), SIMDE_FLOAT64_C(  -190.32) },
      { SIMDE_FLOAT64_C(  -924.54), SIMDE_FLOAT64_C(  -381.70), SIMDE_FLOAT64_C(  -226.98), SIMDE_FLOAT64_C(   221.16),
        SIMDE_FLOAT64_C(  -536.83), SIMDE_FLOAT64_C(  -473.11), SIMDE_FLOAT64_C(  -326.37), SIMDE_FLOAT64_C(  -190.32) } },
    { { SIMDE_FLOAT64_C(   256.03), SIMDE_FLOAT64_C(   126.39), SIMDE_FLOAT64_C(  -121.40), SIMDE_FLOAT64_C(  -822.51),
        SIMDE_FLOAT64_C(    42.11), SIMDE_FLOAT64_C(  -162.89), SIMDE_FLOAT64_C(  -642.18), SIMDE_FLOAT64_C(  -706.89) },
      { SIMDE_FLOAT64_C(   256.03), SIMDE_FLOAT64_C(   126.39), SIMDE_FLOAT64_C(  -121.40), SIMDE_FLOAT64_C(  -822.51),
        SIMDE_FLOAT64_C(    42.11), SIMDE_FLOAT64_C(  -162.89), SIMDE_FLOAT64_C(  -642.18), SIMDE_FLOAT64_C(  -706.89) } },
    { { SIMDE_FLOAT64_C(  -611.85), SIMDE_FLOAT64_C(   325.82), SIMDE_FLOAT64_C(    27.04), SIMDE_FLOAT64_C(  -758.55),
        SIMDE_FLOAT64_C(  -213.98), SIMDE_FLOAT64_C(  -650.96), SIMDE_FLOAT64_C(  -405.01), SIMDE_FLOAT64_C(   815.14) },
      { SIMDE_FLOAT64_C(  -611.85), SIMDE_FLOAT64_C(   325.82), SIMDE_FLOAT64_C(    27.04), SIMDE_FLOAT64_C(  -758.55),
        SIMDE_FLOAT64_C(  -213.98), SIMDE_FLOAT64_C(  -650.96), SIMDE_FLOAT64_C(  -405.01), SIMDE_FLOAT64_C(   815.14) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d r = simde_mm512_castps_pd(simde_mm512_castpd_ps(a));
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_castpd_si512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-2932283473482861325), INT64_C(-7551244776617231168),
                            INT64_C(-7807931705287408960), INT64_C(-5709657210396534887),
                            INT64_C(-5733822187822983321), INT64_C(-6449026762131886574),
                            INT64_C(-4469461462291751367), INT64_C(-1966061413581863839)),
      simde_mm512_set_epi64(INT64_C(-2932283473482861325), INT64_C(-7551244776617231168),
                            INT64_C(-7807931705287408960), INT64_C(-5709657210396534887),
                            INT64_C(-5733822187822983321), INT64_C(-6449026762131886574),
                            INT64_C(-4469461462291751367), INT64_C(-1966061413581863839)) },
    { simde_mm512_set_epi64(INT64_C( 1279499818540525091), INT64_C( 7861921123166401201),
                            INT64_C(-7776868620274070112), INT64_C( 1282257894426558327),
                            INT64_C( 7845161632627040500), INT64_C(-5240804517978550546),
                            INT64_C( 5302531798719229176), INT64_C(-5843726612220411524)),
      simde_mm512_set_epi64(INT64_C( 1279499818540525091), INT64_C( 7861921123166401201),
                            INT64_C(-7776868620274070112), INT64_C( 1282257894426558327),
                            INT64_C( 7845161632627040500), INT64_C(-5240804517978550546),
                            INT64_C( 5302531798719229176), INT64_C(-5843726612220411524)) },
    { simde_mm512_set_epi64(INT64_C( 8264653255264008622), INT64_C(  162552689407469387),
                            INT64_C(-6727945509653055258), INT64_C(-8051656683653588284),
                            INT64_C(-3673194952315675544), INT64_C(-6715795272606770523),
                            INT64_C( 4713570617590173150), INT64_C(-1460297597223426823)),
      simde_mm512_set_epi64(INT64_C( 8264653255264008622), INT64_C(  162552689407469387),
                            INT64_C(-6727945509653055258), INT64_C(-8051656683653588284),
                            INT64_C(-3673194952315675544), INT64_C(-6715795272606770523),
                            INT64_C( 4713570617590173150), INT64_C(-1460297597223426823)) },
    { simde_mm512_set_epi64(INT64_C( 8052472118589501494), INT64_C(-9124867990213523455),
                            INT64_C( 8236047422487698023), INT64_C( 5945811080038499438),
                            INT64_C( 6518955141271267147), INT64_C( 2853045589014014838),
                            INT64_C( 2581043198697401036), INT64_C( 3427873189039658818)),
      simde_mm512_set_epi64(INT64_C( 8052472118589501494), INT64_C(-9124867990213523455),
                            INT64_C( 8236047422487698023), INT64_C( 5945811080038499438),
                            INT64_C( 6518955141271267147), INT64_C( 2853045589014014838),
                            INT64_C( 2581043198697401036), INT64_C( 3427873189039658818)) },
    { simde_mm512_set_epi64(INT64_C(-3824716377022324243), INT64_C( 2673669294054155970),
                            INT64_C(-3539125802254885907), INT64_C(-2325147789690797111),
                            INT64_C(-8959458229056338743), INT64_C( 8174617038106487054),
                            INT64_C( 2599971863369021204), INT64_C(-4237128038265732285)),
      simde_mm512_set_epi64(INT64_C(-3824716377022324243), INT64_C( 2673669294054155970),
                            INT64_C(-3539125802254885907), INT64_C(-2325147789690797111),
                            INT64_C(-8959458229056338743), INT64_C( 8174617038106487054),
                            INT64_C( 2599971863369021204), INT64_C(-4237128038265732285)) },
    { simde_mm512_set_epi64(INT64_C(  467193351903391999), INT64_C( 4360504692705357109),
                            INT64_C( 9013482442495432840), INT64_C(-2009950226490426066),
                            INT64_C(  483507342486254018), INT64_C(  183419223247078674),
                            INT64_C( 2287275646029180906), INT64_C(-3986540516598251529)),
      simde_mm512_set_epi64(INT64_C(  467193351903391999), INT64_C( 4360504692705357109),
                            INT64_C( 9013482442495432840), INT64_C(-2009950226490426066),
                            INT64_C(  483507342486254018), INT64_C(  183419223247078674),
                            INT64_C( 2287275646029180906), INT64_C(-3986540516598251529)) },
    { simde_mm512_set_epi64(INT64_C(-3077645007853633163), INT64_C(-1572779564739653348),
                            INT64_C(-9063178373150191806), INT64_C(-7245631614198864513),
                            INT64_C(-8737364776584512923), INT64_C(-2892458838054920588),
                            INT64_C(  471547968378055740), INT64_C(  775209234293426283)),
      simde_mm512_set_epi64(INT64_C(-3077645007853633163), INT64_C(-1572779564739653348),
                            INT64_C(-9063178373150191806), INT64_C(-7245631614198864513),
                            INT64_C(-8737364776584512923), INT64_C(-2892458838054920588),
                            INT64_C(  471547968378055740), INT64_C(  775209234293426283)) },
    { simde_mm512_set_epi64(INT64_C(-6041628496323364468), INT64_C(-9137870096902224131),
                            INT64_C(-1573113398564050163), INT64_C( 8854240990059664398),
                            INT64_C(-2186298020810705372), INT64_C(-2128579590201805820),
                            INT64_C( 2972790510556186969), INT64_C(-3293272700939969964)),
      simde_mm512_set_epi64(INT64_C(-6041628496323364468), INT64_C(-9137870096902224131),
                            INT64_C(-1573113398564050163), INT64_C( 8854240990059664398),
                            INT64_C(-2186298020810705372), INT64_C(-2128579590201805820),
                            INT64_C( 2972790510556186969), INT64_C(-3293272700939969964)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castpd_si512(simde_mm512_castsi512_pd(test_vec[i].a));
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_castsi512_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-2932283473482861325), INT64_C(-7551244776617231168),
                            INT64_C(-7807931705287408960), INT64_C(-5709657210396534887),
                            INT64_C(-5733822187822983321), INT64_C(-6449026762131886574),
                            INT64_C(-4469461462291751367), INT64_C(-1966061413581863839)),
      simde_mm512_set_epi64(INT64_C(-2932283473482861325), INT64_C(-7551244776617231168),
                            INT64_C(-7807931705287408960), INT64_C(-5709657210396534887),
                            INT64_C(-5733822187822983321), INT64_C(-6449026762131886574),
                            INT64_C(-4469461462291751367), INT64_C(-1966061413581863839)) },
    { simde_mm512_set_epi64(INT64_C( 1279499818540525091), INT64_C( 7861921123166401201),
                            INT64_C(-7776868620274070112), INT64_C( 1282257894426558327),
                            INT64_C( 7845161632627040500), INT64_C(-5240804517978550546),
                            INT64_C( 5302531798719229176), INT64_C(-5843726612220411524)),
      simde_mm512_set_epi64(INT64_C( 1279499818540525091), INT64_C( 7861921123166401201),
                            INT64_C(-7776868620274070112), INT64_C( 1282257894426558327),
                            INT64_C( 7845161632627040500), INT64_C(-5240804517978550546),
                            INT64_C( 5302531798719229176), INT64_C(-5843726612220411524)) },
    { simde_mm512_set_epi64(INT64_C( 8264653255264008622), INT64_C(  162552689407469387),
                            INT64_C(-6727945509653055258), INT64_C(-8051656683653588284),
                            INT64_C(-3673194952315675544), INT64_C(-6715795272606770523),
                            INT64_C( 4713570617590173150), INT64_C(-1460297597223426823)),
      simde_mm512_set_epi64(INT64_C( 8264653255264008622), INT64_C(  162552689407469387),
                            INT64_C(-6727945509653055258), INT64_C(-8051656683653588284),
                            INT64_C(-3673194952315675544), INT64_C(-6715795272606770523),
                            INT64_C( 4713570617590173150), INT64_C(-1460297597223426823)) },
    { simde_mm512_set_epi64(INT64_C( 8052472118589501494), INT64_C(-9124867990213523455),
                            INT64_C( 8236047422487698023), INT64_C( 5945811080038499438),
                            INT64_C( 6518955141271267147), INT64_C( 2853045589014014838),
                            INT64_C( 2581043198697401036), INT64_C( 3427873189039658818)),
      simde_mm512_set_epi64(INT64_C( 8052472118589501494), INT64_C(-9124867990213523455),
                            INT64_C( 8236047422487698023), INT64_C( 5945811080038499438),
                            INT64_C( 6518955141271267147), INT64_C( 2853045589014014838),
                            INT64_C( 2581043198697401036), INT64_C( 3427873189039658818)) },
    { simde_mm512_set_epi64(INT64_C(-3824716377022324243), INT64_C( 2673669294054155970),
                            INT64_C(-3539125802254885907), INT64_C(-2325147789690797111),
                            INT64_C(-8959458229056338743), INT64_C( 8174617038106487054),
                            INT64_C( 2599971863369021204), INT64_C(-4237128038265732285)),
      simde_mm512_set_epi64(INT64_C(-3824716377022324243), INT64_C( 2673669294054155970),
                            INT64_C(-3539125802254885907), INT64_C(-2325147789690797111),
                            INT64_C(-8959458229056338743), INT64_C( 8174617038106487054),
                            INT64_C( 2599971863369021204), INT64_C(-4237128038265732285)) },
    { simde_mm512_set_epi64(INT64_C(  467193351903391999), INT64_C( 4360504692705357109),
                            INT64_C( 9013482442495432840), INT64_C(-2009950226490426066),
                            INT64_C(  483507342486254018), INT64_C(  183419223247078674),
                            INT64_C( 2287275646029180906), INT64_C(-3986540516598251529)),
      simde_mm512_set_epi64(INT64_C(  467193351903391999), INT64_C( 4360504692705357109),
                            INT64_C( 9013482442495432840), INT64_C(-2009950226490426066),
                            INT64_C(  483507342486254018), INT64_C(  183419223247078674),
                            INT64_C( 2287275646029180906), INT64_C(-3986540516598251529)) },
    { simde_mm512_set_epi64(INT64_C(-3077645007853633163), INT64_C(-1572779564739653348),
                            INT64_C(-9063178373150191806), INT64_C(-7245631614198864513),
                            INT64_C(-8737364776584512923), INT64_C(-2892458838054920588),
                            INT64_C(  471547968378055740), INT64_C(  775209234293426283)),
      simde_mm512_set_epi64(INT64_C(-3077645007853633163), INT64_C(-1572779564739653348),
                            INT64_C(-9063178373150191806), INT64_C(-7245631614198864513),
                            INT64_C(-8737364776584512923), INT64_C(-2892458838054920588),
                            INT64_C(  471547968378055740), INT64_C(  775209234293426283)) },
    { simde_mm512_set_epi64(INT64_C(-6041628496323364468), INT64_C(-9137870096902224131),
                            INT64_C(-1573113398564050163), INT64_C( 8854240990059664398),
                            INT64_C(-2186298020810705372), INT64_C(-2128579590201805820),
                            INT64_C( 2972790510556186969), INT64_C(-3293272700939969964)),
      simde_mm512_set_epi64(INT64_C(-6041628496323364468), INT64_C(-9137870096902224131),
                            INT64_C(-1573113398564050163), INT64_C( 8854240990059664398),
                            INT64_C(-2186298020810705372), INT64_C(-2128579590201805820),
                            INT64_C( 2972790510556186969), INT64_C(-3293272700939969964)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castpd_si512(simde_mm512_castsi512_pd(test_vec[i].a));
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_castsi128_si512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1668834023), INT32_C(-1352312258), INT32_C(  556637397), INT32_C( -245835434)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1668834023), INT32_C(-1352312258), INT32_C(  556637397), INT32_C( -245835434)) },
    { simde_mm_set_epi32(INT32_C( 1624943139), INT32_C( -461116292), INT32_C(-2119913042), INT32_C( -900874486)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1624943139), INT32_C( -461116292), INT32_C(-2119913042), INT32_C( -900874486)) },
    { simde_mm_set_epi32(INT32_C( -483029339), INT32_C( 1367342572), INT32_C( 1717714414), INT32_C( -425758846)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -483029339), INT32_C( 1367342572), INT32_C( 1717714414), INT32_C( -425758846)) },
    { simde_mm_set_epi32(INT32_C( -911211301), INT32_C(  327710477), INT32_C( -375455356), INT32_C(-1057936365)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -911211301), INT32_C(  327710477), INT32_C( -375455356), INT32_C(-1057936365)) },
    { simde_mm_set_epi32(INT32_C(  275440871), INT32_C(  641107064), INT32_C( 1055988271), INT32_C(  449906430)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  275440871), INT32_C(  641107064), INT32_C( 1055988271), INT32_C(  449906430)) },
    { simde_mm_set_epi32(INT32_C( -222973014), INT32_C( -356035719), INT32_C( -568690768), INT32_C( 1550764475)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -222973014), INT32_C( -356035719), INT32_C( -568690768), INT32_C( 1550764475)) },
    { simde_mm_set_epi32(INT32_C( 1024653484), INT32_C(-1114765609), INT32_C(  501755487), INT32_C( 1011153625)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1024653484), INT32_C(-1114765609), INT32_C(  501755487), INT32_C( 1011153625)) },
    { simde_mm_set_epi32(INT32_C( 1112995048), INT32_C( 1174048979), INT32_C(  979704874), INT32_C( -581442043)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1112995048), INT32_C( 1174048979), INT32_C(  979704874), INT32_C( -581442043)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castsi128_si512(test_vec[i].a);
    r=simde_mm512_maskz_mov_epi32(UINT8_C(15), r);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_castsi256_si512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -627018310), INT32_C( -732773372), INT32_C(-1935004141), INT32_C( 1864732488),
                            INT32_C(  140289699), INT32_C(-1570899663), INT32_C(-1630998993), INT32_C(  818347323)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -627018310), INT32_C( -732773372), INT32_C(-1935004141), INT32_C( 1864732488),
                            INT32_C(  140289699), INT32_C(-1570899663), INT32_C(-1630998993), INT32_C(  818347323)) },
    { simde_mm256_set_epi32(INT32_C( -208321892), INT32_C(-1091642607), INT32_C(  600758994), INT32_C(  251226426),
                            INT32_C( -263819406), INT32_C(-1881495622), INT32_C( 1833100173), INT32_C(-1639467184)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -208321892), INT32_C(-1091642607), INT32_C(  600758994), INT32_C(  251226426),
                            INT32_C( -263819406), INT32_C(-1881495622), INT32_C( 1833100173), INT32_C(-1639467184)) },
    { simde_mm256_set_epi32(INT32_C(-1754784817), INT32_C( -579924690), INT32_C(  661573432), INT32_C(-1181370591),
                            INT32_C(   60095626), INT32_C(  956226137), INT32_C( -117371256), INT32_C(-1481124874)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1754784817), INT32_C( -579924690), INT32_C(  661573432), INT32_C(-1181370591),
                            INT32_C(   60095626), INT32_C(  956226137), INT32_C( -117371256), INT32_C(-1481124874)) },
    { simde_mm256_set_epi32(INT32_C( 2059950650), INT32_C(  100086839), INT32_C( 1040622382), INT32_C(  188824341),
                            INT32_C( 1391404675), INT32_C(-2134538567), INT32_C( 1420659092), INT32_C( 1719736439)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 2059950650), INT32_C(  100086839), INT32_C( 1040622382), INT32_C(  188824341),
                            INT32_C( 1391404675), INT32_C(-2134538567), INT32_C( 1420659092), INT32_C( 1719736439)) },
    { simde_mm256_set_epi32(INT32_C(  -72277944), INT32_C(    -175328), INT32_C( 1214469435), INT32_C( -481210186),
                            INT32_C( 1755907779), INT32_C( 1941862792), INT32_C(  -53966731), INT32_C(  177508362)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  -72277944), INT32_C(    -175328), INT32_C( 1214469435), INT32_C( -481210186),
                            INT32_C( 1755907779), INT32_C( 1941862792), INT32_C(  -53966731), INT32_C(  177508362)) },
    { simde_mm256_set_epi32(INT32_C( -579195101), INT32_C(  394175316), INT32_C( 2062674518), INT32_C(-2146728292),
                            INT32_C(   67273180), INT32_C(-1275684351), INT32_C(  245156584), INT32_C(  382170563)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -579195101), INT32_C(  394175316), INT32_C( 2062674518), INT32_C(-2146728292),
                            INT32_C(   67273180), INT32_C(-1275684351), INT32_C(  245156584), INT32_C(  382170563)) },
    { simde_mm256_set_epi32(INT32_C(-1725634605), INT32_C(-1992977299), INT32_C( -692965094), INT32_C( 1390281908),
                            INT32_C( 1056328531), INT32_C(  448471511), INT32_C(  676963201), INT32_C( -471721601)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1725634605), INT32_C(-1992977299), INT32_C( -692965094), INT32_C( 1390281908),
                            INT32_C( 1056328531), INT32_C(  448471511), INT32_C(  676963201), INT32_C( -471721601)) },
    { simde_mm256_set_epi32(INT32_C(  868040614), INT32_C( -210101311), INT32_C( 1711471891), INT32_C(  -87087404),
                            INT32_C(-1569971706), INT32_C(-1573190685), INT32_C( 1472943366), INT32_C(-1700287741)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  868040614), INT32_C( -210101311), INT32_C( 1711471891), INT32_C(  -87087404),
                            INT32_C(-1569971706), INT32_C(-1573190685), INT32_C( 1472943366), INT32_C(-1700287741)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castsi256_si512(test_vec[i].a);
    r=simde_mm512_maskz_mov_epi32(UINT8_C(255), r);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_castps_si512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 1318886849), INT32_C( -963615992), INT32_C( 1168255165), INT32_C(-1910220907),
                            INT32_C( -362848940), INT32_C( 1228894571), INT32_C( -604141281), INT32_C( -310556576),
                            INT32_C( -195291453), INT32_C(-1762187610), INT32_C(  785462248), INT32_C(-1654799886),
                            INT32_C(  443157727), INT32_C(  291457152), INT32_C( -673220379), INT32_C( 1588648097)),
      simde_mm512_set_epi32(INT32_C( 1318886849), INT32_C( -963615992), INT32_C( 1168255165), INT32_C(-1910220907),
                            INT32_C( -362848940), INT32_C( 1228894571), INT32_C( -604141281), INT32_C( -310556576),
                            INT32_C( -195291453), INT32_C(-1762187610), INT32_C(  785462248), INT32_C(-1654799886),
                            INT32_C(  443157727), INT32_C(  291457152), INT32_C( -673220379), INT32_C( 1588648097)) },
    { simde_mm512_set_epi32(INT32_C(  388365668), INT32_C( 1922479678), INT32_C(-1025869072), INT32_C( 1053113602),
                            INT32_C( -948060413), INT32_C( 1300260897), INT32_C(  723694906), INT32_C( 1579982945),
                            INT32_C(  551168292), INT32_C( 2117629385), INT32_C( 1278333888), INT32_C(-1219831740),
                            INT32_C( 1012175805), INT32_C(-2142193359), INT32_C(-1234937614), INT32_C(  296489222)),
      simde_mm512_set_epi32(INT32_C(  388365668), INT32_C( 1922479678), INT32_C(-1025869072), INT32_C( 1053113602),
                            INT32_C( -948060413), INT32_C( 1300260897), INT32_C(  723694906), INT32_C( 1579982945),
                            INT32_C(  551168292), INT32_C( 2117629385), INT32_C( 1278333888), INT32_C(-1219831740),
                            INT32_C( 1012175805), INT32_C(-2142193359), INT32_C(-1234937614), INT32_C(  296489222)) },
    { simde_mm512_set_epi32(INT32_C( 1558252976), INT32_C( -896391163), INT32_C( -282653026), INT32_C( -261252112),
                            INT32_C(-1886684518), INT32_C( -792082029), INT32_C(-1821569388), INT32_C(  452082945),
                            INT32_C( 1996286767), INT32_C( -816391022), INT32_C(   52318481), INT32_C( -732357064),
                            INT32_C(-1730294171), INT32_C( 1249707888), INT32_C( 1882801706), INT32_C( -348126448)),
      simde_mm512_set_epi32(INT32_C( 1558252976), INT32_C( -896391163), INT32_C( -282653026), INT32_C( -261252112),
                            INT32_C(-1886684518), INT32_C( -792082029), INT32_C(-1821569388), INT32_C(  452082945),
                            INT32_C( 1996286767), INT32_C( -816391022), INT32_C(   52318481), INT32_C( -732357064),
                            INT32_C(-1730294171), INT32_C( 1249707888), INT32_C( 1882801706), INT32_C( -348126448)) },
    { simde_mm512_set_epi32(INT32_C(-1306007403), INT32_C(  -14823844), INT32_C(   68140915), INT32_C(-1279691583),
                            INT32_C( -366833324), INT32_C( 1029809788), INT32_C(  398169753), INT32_C( 1644631001),
                            INT32_C(-1495643320), INT32_C( -349662299), INT32_C(  337000079), INT32_C(-1599869755),
                            INT32_C( -326525511), INT32_C( 2145777358), INT32_C( -671246537), INT32_C(-1483766126)),
      simde_mm512_set_epi32(INT32_C(-1306007403), INT32_C(  -14823844), INT32_C(   68140915), INT32_C(-1279691583),
                            INT32_C( -366833324), INT32_C( 1029809788), INT32_C(  398169753), INT32_C( 1644631001),
                            INT32_C(-1495643320), INT32_C( -349662299), INT32_C(  337000079), INT32_C(-1599869755),
                            INT32_C( -326525511), INT32_C( 2145777358), INT32_C( -671246537), INT32_C(-1483766126)) },
    { simde_mm512_set_epi32(INT32_C( 1306718049), INT32_C( -481786167), INT32_C( 1036658403), INT32_C(-1275842496),
                            INT32_C(-1384128337), INT32_C( 1110346848), INT32_C( 1633808121), INT32_C(  818679772),
                            INT32_C(  528120539), INT32_C( 1454269875), INT32_C(-1309905851), INT32_C(  195834431),
                            INT32_C( 1710057355), INT32_C(-1286641516), INT32_C( -825070396), INT32_C(-1314661204)),
      simde_mm512_set_epi32(INT32_C( 1306718049), INT32_C( -481786167), INT32_C( 1036658403), INT32_C(-1275842496),
                            INT32_C(-1384128337), INT32_C( 1110346848), INT32_C( 1633808121), INT32_C(  818679772),
                            INT32_C(  528120539), INT32_C( 1454269875), INT32_C(-1309905851), INT32_C(  195834431),
                            INT32_C( 1710057355), INT32_C(-1286641516), INT32_C( -825070396), INT32_C(-1314661204)) },
    { simde_mm512_set_epi32(INT32_C(  897666230), INT32_C(-1247200387), INT32_C(-1594960612), INT32_C(  784358708),
                            INT32_C( -639715103), INT32_C( 1722588202), INT32_C( -957042730), INT32_C( 1748493888),
                            INT32_C(-1424605467), INT32_C( 1715503797), INT32_C(-1877902145), INT32_C( 1433291829),
                            INT32_C(-1672795293), INT32_C( -125523250), INT32_C(  817060741), INT32_C(-1940108057)),
      simde_mm512_set_epi32(INT32_C(  897666230), INT32_C(-1247200387), INT32_C(-1594960612), INT32_C(  784358708),
                            INT32_C( -639715103), INT32_C( 1722588202), INT32_C( -957042730), INT32_C( 1748493888),
                            INT32_C(-1424605467), INT32_C( 1715503797), INT32_C(-1877902145), INT32_C( 1433291829),
                            INT32_C(-1672795293), INT32_C( -125523250), INT32_C(  817060741), INT32_C(-1940108057)) },
    { simde_mm512_set_epi32(INT32_C( -771897847), INT32_C(   51088448), INT32_C(  731748986), INT32_C(-2010019631),
                            INT32_C(-1805256328), INT32_C( -982668321), INT32_C(-1986983933), INT32_C( -806537017),
                            INT32_C( 2103732941), INT32_C(-1950119891), INT32_C( -262758582), INT32_C( -704905824),
                            INT32_C( -298698020), INT32_C( -290664422), INT32_C( -169474404), INT32_C( -381923585)),
      simde_mm512_set_epi32(INT32_C( -771897847), INT32_C(   51088448), INT32_C(  731748986), INT32_C(-2010019631),
                            INT32_C(-1805256328), INT32_C( -982668321), INT32_C(-1986983933), INT32_C( -806537017),
                            INT32_C( 2103732941), INT32_C(-1950119891), INT32_C( -262758582), INT32_C( -704905824),
                            INT32_C( -298698020), INT32_C( -290664422), INT32_C( -169474404), INT32_C( -381923585)) },
    { simde_mm512_set_epi32(INT32_C(-1424890095), INT32_C( -662922774), INT32_C( 1172732731), INT32_C(  220940559),
                            INT32_C(  736508018), INT32_C(-1201335155), INT32_C( -747976663), INT32_C( 1864271935),
                            INT32_C( 1893933430), INT32_C(  214467364), INT32_C(-1230640603), INT32_C(-1529352277),
                            INT32_C(  301681975), INT32_C(  -86355089), INT32_C( 1945634979), INT32_C( 1310017249)),
      simde_mm512_set_epi32(INT32_C(-1424890095), INT32_C( -662922774), INT32_C( 1172732731), INT32_C(  220940559),
                            INT32_C(  736508018), INT32_C(-1201335155), INT32_C( -747976663), INT32_C( 1864271935),
                            INT32_C( 1893933430), INT32_C(  214467364), INT32_C(-1230640603), INT32_C(-1529352277),
                            INT32_C(  301681975), INT32_C(  -86355089), INT32_C( 1945634979), INT32_C( 1310017249)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_castps_si512(simde_mm512_castsi512_ps(test_vec[i].a));
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_castps128_ps512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -124.41), SIMDE_FLOAT32_C(   994.42), SIMDE_FLOAT32_C(  -888.56), SIMDE_FLOAT32_C(  -241.67)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -124.41), SIMDE_FLOAT32_C(   994.42), SIMDE_FLOAT32_C(  -888.56), SIMDE_FLOAT32_C(  -241.67)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -472.63), SIMDE_FLOAT32_C(  -923.61), SIMDE_FLOAT32_C(  -185.31), SIMDE_FLOAT32_C(   531.85)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -472.63), SIMDE_FLOAT32_C(  -923.61), SIMDE_FLOAT32_C(  -185.31), SIMDE_FLOAT32_C(   531.85)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -636.73), SIMDE_FLOAT32_C(  -810.98), SIMDE_FLOAT32_C(  -952.52), SIMDE_FLOAT32_C(   896.08)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -636.73), SIMDE_FLOAT32_C(  -810.98), SIMDE_FLOAT32_C(  -952.52), SIMDE_FLOAT32_C(   896.08)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   142.17), SIMDE_FLOAT32_C(  -205.03), SIMDE_FLOAT32_C(  -269.17), SIMDE_FLOAT32_C(  -426.17)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   142.17), SIMDE_FLOAT32_C(  -205.03), SIMDE_FLOAT32_C(  -269.17), SIMDE_FLOAT32_C(  -426.17)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   149.14), SIMDE_FLOAT32_C(  -672.83), SIMDE_FLOAT32_C(  -162.76), SIMDE_FLOAT32_C(  -647.13)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   149.14), SIMDE_FLOAT32_C(  -672.83), SIMDE_FLOAT32_C(  -162.76), SIMDE_FLOAT32_C(  -647.13)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -915.60), SIMDE_FLOAT32_C(    75.79), SIMDE_FLOAT32_C(   831.71), SIMDE_FLOAT32_C(   144.92)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -915.60), SIMDE_FLOAT32_C(    75.79), SIMDE_FLOAT32_C(   831.71), SIMDE_FLOAT32_C(   144.92)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -748.69), SIMDE_FLOAT32_C(  -492.84), SIMDE_FLOAT32_C(  -132.48), SIMDE_FLOAT32_C(  -765.52)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -748.69), SIMDE_FLOAT32_C(  -492.84), SIMDE_FLOAT32_C(  -132.48), SIMDE_FLOAT32_C(  -765.52)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   346.51), SIMDE_FLOAT32_C(   297.54), SIMDE_FLOAT32_C(   196.93), SIMDE_FLOAT32_C(  -729.98)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   346.51), SIMDE_FLOAT32_C(   297.54), SIMDE_FLOAT32_C(   196.93), SIMDE_FLOAT32_C(  -729.98)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_castps128_ps512(test_vec[i].a);
    r=simde_mm512_maskz_mov_ps(UINT8_C(15), r);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_castps256_ps512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256 a;
    simde__m512 r;
  } test_vec[8] = {
     { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -144.51), SIMDE_FLOAT32_C(   522.85),
                         SIMDE_FLOAT32_C(   259.94), SIMDE_FLOAT32_C(   889.02),
                         SIMDE_FLOAT32_C(    47.86), SIMDE_FLOAT32_C(   181.02),
                         SIMDE_FLOAT32_C(   389.89), SIMDE_FLOAT32_C(   -27.36)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -144.51), SIMDE_FLOAT32_C(   522.85), SIMDE_FLOAT32_C(   259.94), SIMDE_FLOAT32_C(   889.02),
                         SIMDE_FLOAT32_C(    47.86), SIMDE_FLOAT32_C(   181.02), SIMDE_FLOAT32_C(   389.89), SIMDE_FLOAT32_C(   -27.36)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -477.70), SIMDE_FLOAT32_C(  -298.40),
                         SIMDE_FLOAT32_C(  -730.62), SIMDE_FLOAT32_C(   379.73),
                         SIMDE_FLOAT32_C(   223.22), SIMDE_FLOAT32_C(  -917.34),
                         SIMDE_FLOAT32_C(  -268.46), SIMDE_FLOAT32_C(  -361.61)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -477.70), SIMDE_FLOAT32_C(  -298.40), SIMDE_FLOAT32_C(  -730.62), SIMDE_FLOAT32_C(   379.73),
                         SIMDE_FLOAT32_C(   223.22), SIMDE_FLOAT32_C(  -917.34), SIMDE_FLOAT32_C(  -268.46), SIMDE_FLOAT32_C(  -361.61)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   995.68), SIMDE_FLOAT32_C(   377.56),
                         SIMDE_FLOAT32_C(  -263.10), SIMDE_FLOAT32_C(   880.58),
                         SIMDE_FLOAT32_C(    61.47), SIMDE_FLOAT32_C(   993.95),
                         SIMDE_FLOAT32_C(   -45.95), SIMDE_FLOAT32_C(  -445.12)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   995.68), SIMDE_FLOAT32_C(   377.56), SIMDE_FLOAT32_C(  -263.10), SIMDE_FLOAT32_C(   880.58),
                         SIMDE_FLOAT32_C(    61.47), SIMDE_FLOAT32_C(   993.95), SIMDE_FLOAT32_C(   -45.95), SIMDE_FLOAT32_C(  -445.12)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   391.67), SIMDE_FLOAT32_C(  -695.88),
                         SIMDE_FLOAT32_C(   312.22), SIMDE_FLOAT32_C(   389.64),
                         SIMDE_FLOAT32_C(    81.09), SIMDE_FLOAT32_C(   745.89),
                         SIMDE_FLOAT32_C(  -178.17), SIMDE_FLOAT32_C(  -269.92)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   391.67), SIMDE_FLOAT32_C(  -695.88), SIMDE_FLOAT32_C(   312.22), SIMDE_FLOAT32_C(   389.64),
                         SIMDE_FLOAT32_C(    81.09), SIMDE_FLOAT32_C(   745.89), SIMDE_FLOAT32_C(  -178.17), SIMDE_FLOAT32_C(  -269.92)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   498.47), SIMDE_FLOAT32_C(  -985.97),
                         SIMDE_FLOAT32_C(   802.71), SIMDE_FLOAT32_C(   -28.60),
                         SIMDE_FLOAT32_C(  -781.89), SIMDE_FLOAT32_C(  -410.06),
                         SIMDE_FLOAT32_C(  -602.74), SIMDE_FLOAT32_C(  -353.26)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   498.47), SIMDE_FLOAT32_C(  -985.97), SIMDE_FLOAT32_C(   802.71), SIMDE_FLOAT32_C(   -28.60),
                         SIMDE_FLOAT32_C(  -781.89), SIMDE_FLOAT32_C(  -410.06), SIMDE_FLOAT32_C(  -602.74), SIMDE_FLOAT32_C(  -353.26)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   265.34), SIMDE_FLOAT32_C(  -587.26),
                         SIMDE_FLOAT32_C(  -801.19), SIMDE_FLOAT32_C(    -4.56),
                         SIMDE_FLOAT32_C(  -900.49), SIMDE_FLOAT32_C(   391.40),
                         SIMDE_FLOAT32_C(  -416.15), SIMDE_FLOAT32_C(  -286.27)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   265.34), SIMDE_FLOAT32_C(  -587.26), SIMDE_FLOAT32_C(  -801.19), SIMDE_FLOAT32_C(    -4.56),
                         SIMDE_FLOAT32_C(  -900.49), SIMDE_FLOAT32_C(   391.40), SIMDE_FLOAT32_C(  -416.15), SIMDE_FLOAT32_C(  -286.27)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   167.27), SIMDE_FLOAT32_C(  -483.42),
                         SIMDE_FLOAT32_C(   759.82), SIMDE_FLOAT32_C(  -560.80),
                         SIMDE_FLOAT32_C(  -968.24), SIMDE_FLOAT32_C(  -534.87),
                         SIMDE_FLOAT32_C(  -698.82), SIMDE_FLOAT32_C(  -382.24)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   167.27), SIMDE_FLOAT32_C(  -483.42), SIMDE_FLOAT32_C(   759.82), SIMDE_FLOAT32_C(  -560.80),
                         SIMDE_FLOAT32_C(  -968.24), SIMDE_FLOAT32_C(  -534.87), SIMDE_FLOAT32_C(  -698.82), SIMDE_FLOAT32_C(  -382.24)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -792.23), SIMDE_FLOAT32_C(   994.18),
                         SIMDE_FLOAT32_C(  -632.41), SIMDE_FLOAT32_C(   872.87),
                         SIMDE_FLOAT32_C(  -406.41), SIMDE_FLOAT32_C(   989.00),
                         SIMDE_FLOAT32_C(   781.89), SIMDE_FLOAT32_C(   609.26)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -792.23), SIMDE_FLOAT32_C(   994.18), SIMDE_FLOAT32_C(  -632.41), SIMDE_FLOAT32_C(   872.87),
                         SIMDE_FLOAT32_C(  -406.41), SIMDE_FLOAT32_C(   989.00), SIMDE_FLOAT32_C(   781.89), SIMDE_FLOAT32_C(   609.26)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_castps256_ps512(test_vec[i].a);
    r=simde_mm512_maskz_mov_ps(UINT8_C(255), r);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_castsi512_si128(SIMDE_MUNIT_TEST_ARGS) {
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

  return 0;
}

static int
test_simde_mm512_castsi512_si256(SIMDE_MUNIT_TEST_ARGS) {
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

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castpd512_pd128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castpd512_pd256)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castpd128_pd512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castpd256_pd512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castpd_si512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castps_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castpd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castps_si512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castps128_ps512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castps256_ps512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castps512_ps128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castps512_ps256)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castsi512_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castsi128_si512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castsi512_si256)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castsi256_si512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castsi512_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_castsi512_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
