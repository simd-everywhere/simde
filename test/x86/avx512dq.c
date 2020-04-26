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

#define SIMDE_TESTS_CURRENT_ISAX avx512dq
#include <simde/x86/avx512dq.h>
#include <test/x86/test-avx512.h>

#if defined(SIMDE_AVX512DQ_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm512_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   260.00), SIMDE_FLOAT32_C(   472.07), SIMDE_FLOAT32_C(   343.37), SIMDE_FLOAT32_C(   668.63),
                         SIMDE_FLOAT32_C(    74.64), SIMDE_FLOAT32_C(  -166.33), SIMDE_FLOAT32_C(   962.01), SIMDE_FLOAT32_C(   120.25),
                         SIMDE_FLOAT32_C(  -633.54), SIMDE_FLOAT32_C(  -160.44), SIMDE_FLOAT32_C(  -754.35), SIMDE_FLOAT32_C(   920.06),
                         SIMDE_FLOAT32_C(  -752.65), SIMDE_FLOAT32_C(   -15.27), SIMDE_FLOAT32_C(   736.97), SIMDE_FLOAT32_C(   591.25)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   968.14), SIMDE_FLOAT32_C(   728.35), SIMDE_FLOAT32_C(  -574.47), SIMDE_FLOAT32_C(   770.03),
                         SIMDE_FLOAT32_C(  -456.43), SIMDE_FLOAT32_C(   727.04), SIMDE_FLOAT32_C(   -89.84), SIMDE_FLOAT32_C(   288.08),
                         SIMDE_FLOAT32_C(  -720.94), SIMDE_FLOAT32_C(  -964.02), SIMDE_FLOAT32_C(   974.54), SIMDE_FLOAT32_C(  -246.99),
                         SIMDE_FLOAT32_C(  -603.24), SIMDE_FLOAT32_C(  -592.85), SIMDE_FLOAT32_C(  -351.71), SIMDE_FLOAT32_C(   472.50)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.03), SIMDE_FLOAT32_C(     2.56), SIMDE_FLOAT32_C(     2.18), SIMDE_FLOAT32_C(   512.00),
                         SIMDE_FLOAT32_C(    66.01), SIMDE_FLOAT32_C(     2.57), SIMDE_FLOAT32_C(     2.76), SIMDE_FLOAT32_C(    72.00),
                         SIMDE_FLOAT32_C(  -592.50), SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(   706.03), SIMDE_FLOAT32_C(     3.59),
                         SIMDE_FLOAT32_C(  -592.14), SIMDE_FLOAT32_C(    -2.31), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     2.00)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -440.60), SIMDE_FLOAT32_C(   215.95), SIMDE_FLOAT32_C(  -449.65), SIMDE_FLOAT32_C(   426.70),
                         SIMDE_FLOAT32_C(   107.08), SIMDE_FLOAT32_C(  -345.64), SIMDE_FLOAT32_C(   226.40), SIMDE_FLOAT32_C(   712.58),
                         SIMDE_FLOAT32_C(  -396.23), SIMDE_FLOAT32_C(  -256.01), SIMDE_FLOAT32_C(   622.69), SIMDE_FLOAT32_C(  -188.83),
                         SIMDE_FLOAT32_C(   358.20), SIMDE_FLOAT32_C(  -542.16), SIMDE_FLOAT32_C(   982.13), SIMDE_FLOAT32_C(   702.83)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   347.10), SIMDE_FLOAT32_C(  -175.94), SIMDE_FLOAT32_C(   817.30), SIMDE_FLOAT32_C(  -721.72),
                         SIMDE_FLOAT32_C(   775.39), SIMDE_FLOAT32_C(  -218.71), SIMDE_FLOAT32_C(   919.20), SIMDE_FLOAT32_C(  -300.97),
                         SIMDE_FLOAT32_C(   919.48), SIMDE_FLOAT32_C(   -61.84), SIMDE_FLOAT32_C(   121.47), SIMDE_FLOAT32_C(   499.98),
                         SIMDE_FLOAT32_C(   538.40), SIMDE_FLOAT32_C(  -622.49), SIMDE_FLOAT32_C(  -852.24), SIMDE_FLOAT32_C(   445.35)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   280.10), SIMDE_FLOAT32_C(   135.94), SIMDE_FLOAT32_C(     3.01), SIMDE_FLOAT32_C(     2.32),
                         SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(  -136.57), SIMDE_FLOAT32_C(     3.50), SIMDE_FLOAT32_C(     2.28),
                         SIMDE_FLOAT32_C(     3.06), SIMDE_FLOAT32_C(   -32.00), SIMDE_FLOAT32_C(     2.29), SIMDE_FLOAT32_C(   184.83),
                         SIMDE_FLOAT32_C(     2.03), SIMDE_FLOAT32_C(  -526.16), SIMDE_FLOAT32_C(   852.13), SIMDE_FLOAT32_C(     2.23)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -590.91), SIMDE_FLOAT32_C(  -663.88), SIMDE_FLOAT32_C(  -394.32), SIMDE_FLOAT32_C(  -991.87),
                         SIMDE_FLOAT32_C(   385.94), SIMDE_FLOAT32_C(  -349.46), SIMDE_FLOAT32_C(  -786.25), SIMDE_FLOAT32_C(   192.19),
                         SIMDE_FLOAT32_C(  -594.16), SIMDE_FLOAT32_C(  -602.03), SIMDE_FLOAT32_C(   176.16), SIMDE_FLOAT32_C(  -458.14),
                         SIMDE_FLOAT32_C(   335.26), SIMDE_FLOAT32_C(  -272.70), SIMDE_FLOAT32_C(   585.90), SIMDE_FLOAT32_C(  -571.61)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   530.04), SIMDE_FLOAT32_C(  -606.85), SIMDE_FLOAT32_C(   112.20), SIMDE_FLOAT32_C(  -437.59),
                         SIMDE_FLOAT32_C(  -396.36), SIMDE_FLOAT32_C(  -280.58), SIMDE_FLOAT32_C(   819.31), SIMDE_FLOAT32_C(  -726.73),
                         SIMDE_FLOAT32_C(  -263.24), SIMDE_FLOAT32_C(  -511.40), SIMDE_FLOAT32_C(  -175.25), SIMDE_FLOAT32_C(   728.37),
                         SIMDE_FLOAT32_C(   881.16), SIMDE_FLOAT32_C(   -49.97), SIMDE_FLOAT32_C(   618.76), SIMDE_FLOAT32_C(  -518.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   514.03), SIMDE_FLOAT32_C(  -534.75), SIMDE_FLOAT32_C(    96.06), SIMDE_FLOAT32_C(    -3.29),
                         SIMDE_FLOAT32_C(   384.31), SIMDE_FLOAT32_C(  -280.08), SIMDE_FLOAT32_C(   786.25), SIMDE_FLOAT32_C(     2.00),
                         SIMDE_FLOAT32_C(    -2.01), SIMDE_FLOAT32_C(    -2.35), SIMDE_FLOAT32_C(   160.00), SIMDE_FLOAT32_C(     2.56),
                         SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   -32.06), SIMDE_FLOAT32_C(   584.76), SIMDE_FLOAT32_C(  -514.56)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   515.17), SIMDE_FLOAT32_C(   324.54), SIMDE_FLOAT32_C(    91.18), SIMDE_FLOAT32_C(  -165.19),
                         SIMDE_FLOAT32_C(  -882.22), SIMDE_FLOAT32_C(   833.89), SIMDE_FLOAT32_C(   476.02), SIMDE_FLOAT32_C(   887.60),
                         SIMDE_FLOAT32_C(   229.74), SIMDE_FLOAT32_C(   342.64), SIMDE_FLOAT32_C(   541.23), SIMDE_FLOAT32_C(  -642.89),
                         SIMDE_FLOAT32_C(   701.90), SIMDE_FLOAT32_C(   393.90), SIMDE_FLOAT32_C(  -103.65), SIMDE_FLOAT32_C(   243.25)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    21.91), SIMDE_FLOAT32_C(  -134.28), SIMDE_FLOAT32_C(   125.14), SIMDE_FLOAT32_C(  -667.85),
                         SIMDE_FLOAT32_C(  -778.80), SIMDE_FLOAT32_C(  -220.75), SIMDE_FLOAT32_C(   348.36), SIMDE_FLOAT32_C(    29.88),
                         SIMDE_FLOAT32_C(  -634.89), SIMDE_FLOAT32_C(  -148.88), SIMDE_FLOAT32_C(   827.50), SIMDE_FLOAT32_C(  -532.87),
                         SIMDE_FLOAT32_C(  -762.33), SIMDE_FLOAT32_C(   247.69), SIMDE_FLOAT32_C(  -238.64), SIMDE_FLOAT32_C(   244.40)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(   130.27), SIMDE_FLOAT32_C(    89.13), SIMDE_FLOAT32_C(    -2.57),
                         SIMDE_FLOAT32_C(  -770.03), SIMDE_FLOAT32_C(     3.25), SIMDE_FLOAT32_C(   348.02), SIMDE_FLOAT32_C(     3.20),
                         SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(   128.26), SIMDE_FLOAT32_C(   537.00), SIMDE_FLOAT32_C(  -512.76),
                         SIMDE_FLOAT32_C(   696.27), SIMDE_FLOAT32_C(   196.69), SIMDE_FLOAT32_C(   -51.50), SIMDE_FLOAT32_C(   240.25)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   139.73), SIMDE_FLOAT32_C(   808.22), SIMDE_FLOAT32_C(  -888.67), SIMDE_FLOAT32_C(   -90.81),
                         SIMDE_FLOAT32_C(    58.51), SIMDE_FLOAT32_C(  -297.55), SIMDE_FLOAT32_C(  -246.77), SIMDE_FLOAT32_C(  -391.18),
                         SIMDE_FLOAT32_C(   887.15), SIMDE_FLOAT32_C(   997.52), SIMDE_FLOAT32_C(   873.12), SIMDE_FLOAT32_C(  -969.73),
                         SIMDE_FLOAT32_C(   721.30), SIMDE_FLOAT32_C(  -128.28), SIMDE_FLOAT32_C(  -264.35), SIMDE_FLOAT32_C(  -432.42)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -80.65), SIMDE_FLOAT32_C(   -15.71), SIMDE_FLOAT32_C(    54.64), SIMDE_FLOAT32_C(  -420.79),
                         SIMDE_FLOAT32_C(  -573.45), SIMDE_FLOAT32_C(   578.20), SIMDE_FLOAT32_C(  -393.34), SIMDE_FLOAT32_C(   -79.47),
                         SIMDE_FLOAT32_C(  -837.77), SIMDE_FLOAT32_C(   169.23), SIMDE_FLOAT32_C(   110.87), SIMDE_FLOAT32_C(   428.31),
                         SIMDE_FLOAT32_C(   944.93), SIMDE_FLOAT32_C(   222.75), SIMDE_FLOAT32_C(  -792.23), SIMDE_FLOAT32_C(  -269.27)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    32.26), SIMDE_FLOAT32_C(     3.16), SIMDE_FLOAT32_C(     3.41), SIMDE_FLOAT32_C(   -72.01),
                         SIMDE_FLOAT32_C(     2.16), SIMDE_FLOAT32_C(     2.26), SIMDE_FLOAT32_C(  -196.50), SIMDE_FLOAT32_C(   -65.28),
                         SIMDE_FLOAT32_C(   837.02), SIMDE_FLOAT32_C(     2.64), SIMDE_FLOAT32_C(     3.38), SIMDE_FLOAT32_C(     3.28),
                         SIMDE_FLOAT32_C(   656.30), SIMDE_FLOAT32_C(   128.25), SIMDE_FLOAT32_C(    -2.06), SIMDE_FLOAT32_C(  -256.25)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -807.89), SIMDE_FLOAT32_C(  -195.99), SIMDE_FLOAT32_C(  -460.22), SIMDE_FLOAT32_C(  -214.31),
                         SIMDE_FLOAT32_C(  -242.49), SIMDE_FLOAT32_C(   293.67), SIMDE_FLOAT32_C(   209.36), SIMDE_FLOAT32_C(   -28.16),
                         SIMDE_FLOAT32_C(   861.78), SIMDE_FLOAT32_C(  -349.18), SIMDE_FLOAT32_C(  -840.98), SIMDE_FLOAT32_C(   667.88),
                         SIMDE_FLOAT32_C(  -431.60), SIMDE_FLOAT32_C(  -312.68), SIMDE_FLOAT32_C(   469.25), SIMDE_FLOAT32_C(   584.01)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   881.42), SIMDE_FLOAT32_C(   703.51), SIMDE_FLOAT32_C(   112.91), SIMDE_FLOAT32_C(    92.78),
                         SIMDE_FLOAT32_C(   506.44), SIMDE_FLOAT32_C(   923.94), SIMDE_FLOAT32_C(  -577.40), SIMDE_FLOAT32_C(  -437.14),
                         SIMDE_FLOAT32_C(  -379.29), SIMDE_FLOAT32_C(   791.05), SIMDE_FLOAT32_C(   859.09), SIMDE_FLOAT32_C(   612.11),
                         SIMDE_FLOAT32_C(   687.78), SIMDE_FLOAT32_C(   712.98), SIMDE_FLOAT32_C(  -143.15), SIMDE_FLOAT32_C(  -972.86)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   801.39), SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   112.03), SIMDE_FLOAT32_C(    36.01),
                         SIMDE_FLOAT32_C(   240.22), SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(     2.26), SIMDE_FLOAT32_C(   -24.00),
                         SIMDE_FLOAT32_C(     2.33), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(   840.07), SIMDE_FLOAT32_C(   512.00),
                         SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(   138.12), SIMDE_FLOAT32_C(   584.00)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   278.01), SIMDE_FLOAT32_C(  -815.62), SIMDE_FLOAT32_C(   752.91), SIMDE_FLOAT32_C(   710.22),
                         SIMDE_FLOAT32_C(  -124.40), SIMDE_FLOAT32_C(  -338.82), SIMDE_FLOAT32_C(  -853.49), SIMDE_FLOAT32_C(   731.62),
                         SIMDE_FLOAT32_C(   168.07), SIMDE_FLOAT32_C(  -402.61), SIMDE_FLOAT32_C(  -908.62), SIMDE_FLOAT32_C(   912.24),
                         SIMDE_FLOAT32_C(   241.90), SIMDE_FLOAT32_C(   493.82), SIMDE_FLOAT32_C(  -948.44), SIMDE_FLOAT32_C(   522.79)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -401.28), SIMDE_FLOAT32_C(   383.51), SIMDE_FLOAT32_C(  -854.57), SIMDE_FLOAT32_C(  -237.48),
                         SIMDE_FLOAT32_C(  -426.55), SIMDE_FLOAT32_C(  -605.26), SIMDE_FLOAT32_C(   140.00), SIMDE_FLOAT32_C(  -626.79),
                         SIMDE_FLOAT32_C(   473.63), SIMDE_FLOAT32_C(   968.53), SIMDE_FLOAT32_C(  -767.62), SIMDE_FLOAT32_C(  -339.51),
                         SIMDE_FLOAT32_C(   144.17), SIMDE_FLOAT32_C(   -47.64), SIMDE_FLOAT32_C(  -130.89), SIMDE_FLOAT32_C(   -19.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   272.01), SIMDE_FLOAT32_C(     2.18), SIMDE_FLOAT32_C(   592.50), SIMDE_FLOAT32_C(     2.52),
                         SIMDE_FLOAT32_C(  -104.13), SIMDE_FLOAT32_C(    -2.02), SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   594.54),
                         SIMDE_FLOAT32_C(   168.07), SIMDE_FLOAT32_C(     3.00), SIMDE_FLOAT32_C(  -652.62), SIMDE_FLOAT32_C(     2.50),
                         SIMDE_FLOAT32_C(   144.13), SIMDE_FLOAT32_C(    45.63), SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.03)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   491.53), SIMDE_FLOAT32_C(   985.75), SIMDE_FLOAT32_C(  -390.64), SIMDE_FLOAT32_C(   517.90),
                         SIMDE_FLOAT32_C(  -725.16), SIMDE_FLOAT32_C(     9.87), SIMDE_FLOAT32_C(   943.82), SIMDE_FLOAT32_C(   279.49),
                         SIMDE_FLOAT32_C(  -942.01), SIMDE_FLOAT32_C(    63.94), SIMDE_FLOAT32_C(   920.28), SIMDE_FLOAT32_C(   132.72),
                         SIMDE_FLOAT32_C(   502.41), SIMDE_FLOAT32_C(   855.02), SIMDE_FLOAT32_C(   610.59), SIMDE_FLOAT32_C(   860.61)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -675.66), SIMDE_FLOAT32_C(   128.22), SIMDE_FLOAT32_C(  -915.29), SIMDE_FLOAT32_C(  -679.65),
                         SIMDE_FLOAT32_C(   537.51), SIMDE_FLOAT32_C(  -484.11), SIMDE_FLOAT32_C(   502.40), SIMDE_FLOAT32_C(  -785.39),
                         SIMDE_FLOAT32_C(  -128.17), SIMDE_FLOAT32_C(   101.31), SIMDE_FLOAT32_C(  -990.73), SIMDE_FLOAT32_C(  -514.82),
                         SIMDE_FLOAT32_C(   231.21), SIMDE_FLOAT32_C(   964.21), SIMDE_FLOAT32_C(  -258.81), SIMDE_FLOAT32_C(   355.88)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(    -3.00), SIMDE_FLOAT32_C(   517.65),
                         SIMDE_FLOAT32_C(   529.00), SIMDE_FLOAT32_C(     9.00), SIMDE_FLOAT32_C(     3.67), SIMDE_FLOAT32_C(     2.00),
                         SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(    50.63), SIMDE_FLOAT32_C(   920.01), SIMDE_FLOAT32_C(     2.01),
                         SIMDE_FLOAT32_C(   227.20), SIMDE_FLOAT32_C(   836.02), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.27)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_and_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_and_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  266.26), SIMDE_FLOAT64_C(  537.32),
                         SIMDE_FLOAT64_C( -326.88), SIMDE_FLOAT64_C( -882.50),
                         SIMDE_FLOAT64_C(  -89.28), SIMDE_FLOAT64_C( -631.60),
                         SIMDE_FLOAT64_C( -243.67), SIMDE_FLOAT64_C(   78.08)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -676.48), SIMDE_FLOAT64_C( -545.20),
                         SIMDE_FLOAT64_C(  963.41), SIMDE_FLOAT64_C(  343.81),
                         SIMDE_FLOAT64_C( -406.87), SIMDE_FLOAT64_C( -689.93),
                         SIMDE_FLOAT64_C( -169.12), SIMDE_FLOAT64_C( -796.89)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(  513.07),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    2.13),
                         SIMDE_FLOAT64_C(  -65.03), SIMDE_FLOAT64_C( -561.53),
                         SIMDE_FLOAT64_C( -161.04), SIMDE_FLOAT64_C(    2.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -354.59), SIMDE_FLOAT64_C( -334.01),
                         SIMDE_FLOAT64_C( -406.82), SIMDE_FLOAT64_C( -535.93),
                         SIMDE_FLOAT64_C(  534.72), SIMDE_FLOAT64_C(  276.86),
                         SIMDE_FLOAT64_C(  401.00), SIMDE_FLOAT64_C(  921.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -20.44), SIMDE_FLOAT64_C( -778.21),
                         SIMDE_FLOAT64_C(  -61.28), SIMDE_FLOAT64_C(  788.42),
                         SIMDE_FLOAT64_C(  286.07), SIMDE_FLOAT64_C(  772.65),
                         SIMDE_FLOAT64_C( -788.54), SIMDE_FLOAT64_C(  755.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -20.13), SIMDE_FLOAT64_C(   -2.03),
                         SIMDE_FLOAT64_C(  -48.26), SIMDE_FLOAT64_C(  532.41),
                         SIMDE_FLOAT64_C(    2.08), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  657.31)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  197.60), SIMDE_FLOAT64_C( -669.73),
                         SIMDE_FLOAT64_C(  859.82), SIMDE_FLOAT64_C( -638.20),
                         SIMDE_FLOAT64_C( -808.24), SIMDE_FLOAT64_C(  961.25),
                         SIMDE_FLOAT64_C(  916.37), SIMDE_FLOAT64_C( -473.47)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.21), SIMDE_FLOAT64_C(   10.30),
                         SIMDE_FLOAT64_C(  402.59), SIMDE_FLOAT64_C( -919.31),
                         SIMDE_FLOAT64_C(  484.80), SIMDE_FLOAT64_C(  567.35),
                         SIMDE_FLOAT64_C( -979.89), SIMDE_FLOAT64_C(  784.39)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.08), SIMDE_FLOAT64_C(    2.57),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C( -534.01),
                         SIMDE_FLOAT64_C(    3.03), SIMDE_FLOAT64_C(  513.25),
                         SIMDE_FLOAT64_C(  912.26), SIMDE_FLOAT64_C(    3.06)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  188.83), SIMDE_FLOAT64_C( -479.33),
                         SIMDE_FLOAT64_C(  811.81), SIMDE_FLOAT64_C( -322.50),
                         SIMDE_FLOAT64_C(  884.11), SIMDE_FLOAT64_C(  808.53),
                         SIMDE_FLOAT64_C( -174.95), SIMDE_FLOAT64_C(  -68.05)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -882.86), SIMDE_FLOAT64_C( -939.93),
                         SIMDE_FLOAT64_C( -855.90), SIMDE_FLOAT64_C(  170.22),
                         SIMDE_FLOAT64_C(  115.99), SIMDE_FLOAT64_C(  297.62),
                         SIMDE_FLOAT64_C( -527.76), SIMDE_FLOAT64_C(  219.88)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.45), SIMDE_FLOAT64_C(   -3.67),
                         SIMDE_FLOAT64_C(  771.77), SIMDE_FLOAT64_C(  160.00),
                         SIMDE_FLOAT64_C(    3.08), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(   -2.05), SIMDE_FLOAT64_C(   34.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -659.02), SIMDE_FLOAT64_C(  607.91),
                         SIMDE_FLOAT64_C( -268.25), SIMDE_FLOAT64_C(  240.07),
                         SIMDE_FLOAT64_C(  471.39), SIMDE_FLOAT64_C( -501.59),
                         SIMDE_FLOAT64_C(  984.94), SIMDE_FLOAT64_C( -801.62)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -165.03), SIMDE_FLOAT64_C(  382.49),
                         SIMDE_FLOAT64_C( -663.11), SIMDE_FLOAT64_C(  675.92),
                         SIMDE_FLOAT64_C( -427.89), SIMDE_FLOAT64_C( -312.23),
                         SIMDE_FLOAT64_C(   47.19), SIMDE_FLOAT64_C( -273.76)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   -2.56), SIMDE_FLOAT64_C(    2.36),
                         SIMDE_FLOAT64_C(   -2.06), SIMDE_FLOAT64_C(    2.50),
                         SIMDE_FLOAT64_C(  387.39), SIMDE_FLOAT64_C( -304.07),
                         SIMDE_FLOAT64_C(    2.81), SIMDE_FLOAT64_C(   -2.13)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -449.51), SIMDE_FLOAT64_C( -396.24),
                         SIMDE_FLOAT64_C( -106.23), SIMDE_FLOAT64_C( -648.77),
                         SIMDE_FLOAT64_C(  178.69), SIMDE_FLOAT64_C( -996.05),
                         SIMDE_FLOAT64_C(  315.07), SIMDE_FLOAT64_C( -247.28)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  515.02), SIMDE_FLOAT64_C(  228.66),
                         SIMDE_FLOAT64_C(  419.85), SIMDE_FLOAT64_C( -810.27),
                         SIMDE_FLOAT64_C(  162.64), SIMDE_FLOAT64_C(  495.48),
                         SIMDE_FLOAT64_C( -567.27), SIMDE_FLOAT64_C(  755.82)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  196.03),
                         SIMDE_FLOAT64_C(  104.20), SIMDE_FLOAT64_C( -520.27),
                         SIMDE_FLOAT64_C(  162.63), SIMDE_FLOAT64_C(    3.77),
                         SIMDE_FLOAT64_C(    2.21), SIMDE_FLOAT64_C(    2.82)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -506.18), SIMDE_FLOAT64_C(  153.12),
                         SIMDE_FLOAT64_C( -217.93), SIMDE_FLOAT64_C(    6.73),
                         SIMDE_FLOAT64_C(  358.11), SIMDE_FLOAT64_C( -136.37),
                         SIMDE_FLOAT64_C(  141.08), SIMDE_FLOAT64_C( -860.28)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -303.86), SIMDE_FLOAT64_C( -938.78),
                         SIMDE_FLOAT64_C(  386.83), SIMDE_FLOAT64_C( -590.09),
                         SIMDE_FLOAT64_C( -517.39), SIMDE_FLOAT64_C( -324.41),
                         SIMDE_FLOAT64_C(  515.48), SIMDE_FLOAT64_C(  674.62)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -298.05), SIMDE_FLOAT64_C(    2.13),
                         SIMDE_FLOAT64_C(  193.41), SIMDE_FLOAT64_C(    2.30),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C( -128.08),
                         SIMDE_FLOAT64_C(    2.00), SIMDE_FLOAT64_C(  512.03)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -571.57), SIMDE_FLOAT64_C( -865.77),
                         SIMDE_FLOAT64_C( -691.63), SIMDE_FLOAT64_C( -182.56),
                         SIMDE_FLOAT64_C(  -67.70), SIMDE_FLOAT64_C( -166.11),
                         SIMDE_FLOAT64_C( -833.08), SIMDE_FLOAT64_C( -401.07)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  341.96), SIMDE_FLOAT64_C(  615.56),
                         SIMDE_FLOAT64_C(  144.45), SIMDE_FLOAT64_C(  211.78),
                         SIMDE_FLOAT64_C(  -86.51), SIMDE_FLOAT64_C(  594.64),
                         SIMDE_FLOAT64_C(  523.21), SIMDE_FLOAT64_C( -747.41)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.17), SIMDE_FLOAT64_C(  609.52),
                         SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  146.53),
                         SIMDE_FLOAT64_C(  -66.51), SIMDE_FLOAT64_C(    2.06),
                         SIMDE_FLOAT64_C(  513.08), SIMDE_FLOAT64_C(   -2.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_and_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

#endif /* defined(SIMDE_avx512dq_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

#if HEDLEY_HAS_WARNING("-Wold-style-cast")
  #pragma clang diagnostic ignored "-Wold-style-cast"
#endif
#if HEDLEY_HAS_WARNING("-Wzero-as-null-pointer-constant")
  #pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_AVX512DQ_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

  SIMDE_TESTS_DEFINE_TEST(mm512_and_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_and_pd),
  

#endif /* defined(SIMDE_AVX512dq_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */
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
