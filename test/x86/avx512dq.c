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

static MunitResult
test_simde_mm512_mask_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -343.60), SIMDE_FLOAT32_C(  -192.26), SIMDE_FLOAT32_C(  -375.10), SIMDE_FLOAT32_C(   810.28),
                         SIMDE_FLOAT32_C(  -388.15), SIMDE_FLOAT32_C(    15.81), SIMDE_FLOAT32_C(   547.95), SIMDE_FLOAT32_C(   151.06),
                         SIMDE_FLOAT32_C(  -920.74), SIMDE_FLOAT32_C(  -676.14), SIMDE_FLOAT32_C(  -545.26), SIMDE_FLOAT32_C(   -14.56),
                         SIMDE_FLOAT32_C(  -393.14), SIMDE_FLOAT32_C(   768.60), SIMDE_FLOAT32_C(  -177.89), SIMDE_FLOAT32_C(  -467.51)),
      UINT16_C(45944),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -651.37), SIMDE_FLOAT32_C(    37.95), SIMDE_FLOAT32_C(  -182.79), SIMDE_FLOAT32_C(   255.51),
                         SIMDE_FLOAT32_C(   476.70), SIMDE_FLOAT32_C(   371.61), SIMDE_FLOAT32_C(  -494.45), SIMDE_FLOAT32_C(    72.18),
                         SIMDE_FLOAT32_C(  -723.25), SIMDE_FLOAT32_C(   604.60), SIMDE_FLOAT32_C(   545.32), SIMDE_FLOAT32_C(  -399.73),
                         SIMDE_FLOAT32_C(  -975.39), SIMDE_FLOAT32_C(   419.30), SIMDE_FLOAT32_C(  -736.37), SIMDE_FLOAT32_C(   655.70)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -330.93), SIMDE_FLOAT32_C(   963.24), SIMDE_FLOAT32_C(   -62.45), SIMDE_FLOAT32_C(   625.74),
                         SIMDE_FLOAT32_C(  -826.45), SIMDE_FLOAT32_C(  -884.51), SIMDE_FLOAT32_C(   544.59), SIMDE_FLOAT32_C(   -22.39),
                         SIMDE_FLOAT32_C(   750.16), SIMDE_FLOAT32_C(  -751.51), SIMDE_FLOAT32_C(  -211.00), SIMDE_FLOAT32_C(   886.29),
                         SIMDE_FLOAT32_C(   666.91), SIMDE_FLOAT32_C(     8.70), SIMDE_FLOAT32_C(  -362.66), SIMDE_FLOAT32_C(  -451.03)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    -2.51), SIMDE_FLOAT32_C(  -192.26), SIMDE_FLOAT32_C(   -44.20), SIMDE_FLOAT32_C(     2.44),
                         SIMDE_FLOAT32_C(  -388.15), SIMDE_FLOAT32_C(    15.81), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     4.50),
                         SIMDE_FLOAT32_C(  -920.74), SIMDE_FLOAT32_C(   588.50), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     3.09),
                         SIMDE_FLOAT32_C(   650.38), SIMDE_FLOAT32_C(   768.60), SIMDE_FLOAT32_C(  -177.89), SIMDE_FLOAT32_C(  -467.51)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -702.08), SIMDE_FLOAT32_C(   457.26), SIMDE_FLOAT32_C(   193.10), SIMDE_FLOAT32_C(   655.72),
                         SIMDE_FLOAT32_C(   205.91), SIMDE_FLOAT32_C(   807.77), SIMDE_FLOAT32_C(  -545.40), SIMDE_FLOAT32_C(  -364.12),
                         SIMDE_FLOAT32_C(   -42.22), SIMDE_FLOAT32_C(  -523.42), SIMDE_FLOAT32_C(  -308.90), SIMDE_FLOAT32_C(    22.20),
                         SIMDE_FLOAT32_C(  -114.47), SIMDE_FLOAT32_C(  -738.11), SIMDE_FLOAT32_C(   189.09), SIMDE_FLOAT32_C(  -448.58)),
      UINT16_C(10313),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -177.43), SIMDE_FLOAT32_C(   -28.38), SIMDE_FLOAT32_C(  -846.37), SIMDE_FLOAT32_C(   912.26),
                         SIMDE_FLOAT32_C(  -370.39), SIMDE_FLOAT32_C(   988.78), SIMDE_FLOAT32_C(  -359.74), SIMDE_FLOAT32_C(  -281.72),
                         SIMDE_FLOAT32_C(   166.18), SIMDE_FLOAT32_C(  -100.50), SIMDE_FLOAT32_C(  -909.51), SIMDE_FLOAT32_C(   -85.95),
                         SIMDE_FLOAT32_C(  -710.91), SIMDE_FLOAT32_C(  -813.11), SIMDE_FLOAT32_C(  -799.86), SIMDE_FLOAT32_C(  -823.45)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   329.92), SIMDE_FLOAT32_C(   113.21), SIMDE_FLOAT32_C(   300.37), SIMDE_FLOAT32_C(  -777.20),
                         SIMDE_FLOAT32_C(   193.77), SIMDE_FLOAT32_C(  -864.32), SIMDE_FLOAT32_C(   579.99), SIMDE_FLOAT32_C(   488.59),
                         SIMDE_FLOAT32_C(  -684.28), SIMDE_FLOAT32_C(   -65.28), SIMDE_FLOAT32_C(   876.26), SIMDE_FLOAT32_C(   378.65),
                         SIMDE_FLOAT32_C(  -964.10), SIMDE_FLOAT32_C(   626.06), SIMDE_FLOAT32_C(    97.19), SIMDE_FLOAT32_C(   612.33)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -702.08), SIMDE_FLOAT32_C(   457.26), SIMDE_FLOAT32_C(     2.28), SIMDE_FLOAT32_C(   655.72),
                         SIMDE_FLOAT32_C(   129.00), SIMDE_FLOAT32_C(   807.77), SIMDE_FLOAT32_C(  -545.40), SIMDE_FLOAT32_C(  -364.12),
                         SIMDE_FLOAT32_C(   -42.22), SIMDE_FLOAT32_C(   -64.00), SIMDE_FLOAT32_C(  -308.90), SIMDE_FLOAT32_C(    22.20),
                         SIMDE_FLOAT32_C(  -708.03), SIMDE_FLOAT32_C(  -738.11), SIMDE_FLOAT32_C(   189.09), SIMDE_FLOAT32_C(   548.31)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   153.13), SIMDE_FLOAT32_C(    47.64), SIMDE_FLOAT32_C(  -104.37), SIMDE_FLOAT32_C(  -453.36),
                         SIMDE_FLOAT32_C(   -57.32), SIMDE_FLOAT32_C(  -673.06), SIMDE_FLOAT32_C(  -857.97), SIMDE_FLOAT32_C(  -158.69),
                         SIMDE_FLOAT32_C(   504.22), SIMDE_FLOAT32_C(   774.61), SIMDE_FLOAT32_C(   -50.26), SIMDE_FLOAT32_C(  -594.62),
                         SIMDE_FLOAT32_C(   628.86), SIMDE_FLOAT32_C(   362.00), SIMDE_FLOAT32_C(   770.65), SIMDE_FLOAT32_C(  -621.70)),
      UINT16_C( 5674),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -181.31), SIMDE_FLOAT32_C(  -271.84), SIMDE_FLOAT32_C(   138.26), SIMDE_FLOAT32_C(    59.10),
                         SIMDE_FLOAT32_C(   703.12), SIMDE_FLOAT32_C(   374.71), SIMDE_FLOAT32_C(  -674.86), SIMDE_FLOAT32_C(  -198.23),
                         SIMDE_FLOAT32_C(   769.31), SIMDE_FLOAT32_C(  -859.16), SIMDE_FLOAT32_C(   111.69), SIMDE_FLOAT32_C(  -420.38),
                         SIMDE_FLOAT32_C(   345.23), SIMDE_FLOAT32_C(  -263.27), SIMDE_FLOAT32_C(   122.33), SIMDE_FLOAT32_C(   -11.31)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    13.03), SIMDE_FLOAT32_C(   510.73), SIMDE_FLOAT32_C(    -6.19), SIMDE_FLOAT32_C(  -107.87),
                         SIMDE_FLOAT32_C(  -441.23), SIMDE_FLOAT32_C(   120.22), SIMDE_FLOAT32_C(   331.67), SIMDE_FLOAT32_C(  -661.48),
                         SIMDE_FLOAT32_C(   626.32), SIMDE_FLOAT32_C(   505.21), SIMDE_FLOAT32_C(  -161.83), SIMDE_FLOAT32_C(  -671.34),
                         SIMDE_FLOAT32_C(   514.06), SIMDE_FLOAT32_C(  -807.61), SIMDE_FLOAT32_C(  -556.61), SIMDE_FLOAT32_C(  -451.72)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   153.13), SIMDE_FLOAT32_C(    47.64), SIMDE_FLOAT32_C(  -104.37), SIMDE_FLOAT32_C(    49.04),
                         SIMDE_FLOAT32_C(   -57.32), SIMDE_FLOAT32_C(    88.16), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(  -158.69),
                         SIMDE_FLOAT32_C(   504.22), SIMDE_FLOAT32_C(   774.61), SIMDE_FLOAT32_C(    32.31), SIMDE_FLOAT32_C(  -594.62),
                         SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(   362.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(  -621.70)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -175.84), SIMDE_FLOAT32_C(   968.44), SIMDE_FLOAT32_C(    85.61), SIMDE_FLOAT32_C(  -394.33),
                         SIMDE_FLOAT32_C(   358.35), SIMDE_FLOAT32_C(   605.54), SIMDE_FLOAT32_C(  -698.35), SIMDE_FLOAT32_C(  -764.09),
                         SIMDE_FLOAT32_C(   164.55), SIMDE_FLOAT32_C(  -893.53), SIMDE_FLOAT32_C(   171.50), SIMDE_FLOAT32_C(   629.19),
                         SIMDE_FLOAT32_C(    42.86), SIMDE_FLOAT32_C(    22.57), SIMDE_FLOAT32_C(   198.87), SIMDE_FLOAT32_C(  -209.78)),
      UINT16_C(35386),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   -72.35), SIMDE_FLOAT32_C(  -549.59), SIMDE_FLOAT32_C(   102.63), SIMDE_FLOAT32_C(   834.67),
                         SIMDE_FLOAT32_C(     4.81), SIMDE_FLOAT32_C(   910.94), SIMDE_FLOAT32_C(   192.67), SIMDE_FLOAT32_C(   180.42),
                         SIMDE_FLOAT32_C(   349.29), SIMDE_FLOAT32_C(   183.58), SIMDE_FLOAT32_C(   366.06), SIMDE_FLOAT32_C(  -157.87),
                         SIMDE_FLOAT32_C(  -312.42), SIMDE_FLOAT32_C(   182.79), SIMDE_FLOAT32_C(  -978.11), SIMDE_FLOAT32_C(    90.48)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   175.13), SIMDE_FLOAT32_C(  -712.55), SIMDE_FLOAT32_C(  -809.33), SIMDE_FLOAT32_C(   698.74),
                         SIMDE_FLOAT32_C(   142.25), SIMDE_FLOAT32_C(  -727.89), SIMDE_FLOAT32_C(  -520.56), SIMDE_FLOAT32_C(   353.74),
                         SIMDE_FLOAT32_C(  -705.41), SIMDE_FLOAT32_C(  -196.42), SIMDE_FLOAT32_C(   407.84), SIMDE_FLOAT32_C(  -285.59),
                         SIMDE_FLOAT32_C(   496.15), SIMDE_FLOAT32_C(   800.83), SIMDE_FLOAT32_C(  -740.01), SIMDE_FLOAT32_C(   769.91)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    32.03), SIMDE_FLOAT32_C(   968.44), SIMDE_FLOAT32_C(    85.61), SIMDE_FLOAT32_C(  -394.33),
                         SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(   605.54), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(  -764.09),
                         SIMDE_FLOAT32_C(   164.55), SIMDE_FLOAT32_C(  -893.53), SIMDE_FLOAT32_C(   262.03), SIMDE_FLOAT32_C(  -140.79),
                         SIMDE_FLOAT32_C(   304.13), SIMDE_FLOAT32_C(    22.57), SIMDE_FLOAT32_C(  -704.00), SIMDE_FLOAT32_C(  -209.78)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -273.10), SIMDE_FLOAT32_C(  -193.08), SIMDE_FLOAT32_C(   823.95), SIMDE_FLOAT32_C(   970.90),
                         SIMDE_FLOAT32_C(   -50.31), SIMDE_FLOAT32_C(   755.59), SIMDE_FLOAT32_C(  -119.92), SIMDE_FLOAT32_C(  -895.51),
                         SIMDE_FLOAT32_C(   692.21), SIMDE_FLOAT32_C(   544.09), SIMDE_FLOAT32_C(   740.64), SIMDE_FLOAT32_C(   817.79),
                         SIMDE_FLOAT32_C(   131.04), SIMDE_FLOAT32_C(   190.96), SIMDE_FLOAT32_C(   289.64), SIMDE_FLOAT32_C(  -908.35)),
      UINT16_C( 1662),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   563.69), SIMDE_FLOAT32_C(   374.34), SIMDE_FLOAT32_C(  -459.61), SIMDE_FLOAT32_C(   786.82),
                         SIMDE_FLOAT32_C(   257.72), SIMDE_FLOAT32_C(  -220.73), SIMDE_FLOAT32_C(  -903.10), SIMDE_FLOAT32_C(   520.58),
                         SIMDE_FLOAT32_C(  -858.27), SIMDE_FLOAT32_C(   784.57), SIMDE_FLOAT32_C(   832.81), SIMDE_FLOAT32_C(  -909.15),
                         SIMDE_FLOAT32_C(   909.58), SIMDE_FLOAT32_C(  -162.79), SIMDE_FLOAT32_C(   177.63), SIMDE_FLOAT32_C(    25.46)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   749.97), SIMDE_FLOAT32_C(   -58.76), SIMDE_FLOAT32_C(   952.36), SIMDE_FLOAT32_C(   549.26),
                         SIMDE_FLOAT32_C(   390.25), SIMDE_FLOAT32_C(  -490.70), SIMDE_FLOAT32_C(   974.89), SIMDE_FLOAT32_C(   114.95),
                         SIMDE_FLOAT32_C(   932.36), SIMDE_FLOAT32_C(  -895.93), SIMDE_FLOAT32_C(  -880.84), SIMDE_FLOAT32_C(  -351.20),
                         SIMDE_FLOAT32_C(  -500.77), SIMDE_FLOAT32_C(    42.49), SIMDE_FLOAT32_C(   588.62), SIMDE_FLOAT32_C(    67.54)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -273.10), SIMDE_FLOAT32_C(  -193.08), SIMDE_FLOAT32_C(   823.95), SIMDE_FLOAT32_C(   970.90),
                         SIMDE_FLOAT32_C(   -50.31), SIMDE_FLOAT32_C(  -212.10), SIMDE_FLOAT32_C(   902.01), SIMDE_FLOAT32_C(  -895.51),
                         SIMDE_FLOAT32_C(   692.21), SIMDE_FLOAT32_C(   784.50), SIMDE_FLOAT32_C(   832.78), SIMDE_FLOAT32_C(    -2.55),
                         SIMDE_FLOAT32_C(     3.54), SIMDE_FLOAT32_C(    40.19), SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(  -908.35)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   882.37), SIMDE_FLOAT32_C(   -29.48), SIMDE_FLOAT32_C(   208.93), SIMDE_FLOAT32_C(  -103.96),
                         SIMDE_FLOAT32_C(  -740.71), SIMDE_FLOAT32_C(   -48.33), SIMDE_FLOAT32_C(   -73.48), SIMDE_FLOAT32_C(   839.05),
                         SIMDE_FLOAT32_C(  -578.39), SIMDE_FLOAT32_C(  -527.30), SIMDE_FLOAT32_C(   808.78), SIMDE_FLOAT32_C(   273.31),
                         SIMDE_FLOAT32_C(  -212.18), SIMDE_FLOAT32_C(   358.44), SIMDE_FLOAT32_C(  -429.58), SIMDE_FLOAT32_C(   641.01)),
      UINT16_C(51954),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   159.89), SIMDE_FLOAT32_C(  -431.59), SIMDE_FLOAT32_C(   692.24), SIMDE_FLOAT32_C(  -189.31),
                         SIMDE_FLOAT32_C(    84.37), SIMDE_FLOAT32_C(  -971.33), SIMDE_FLOAT32_C(    50.60), SIMDE_FLOAT32_C(  -980.81),
                         SIMDE_FLOAT32_C(   362.99), SIMDE_FLOAT32_C(   722.54), SIMDE_FLOAT32_C(   564.98), SIMDE_FLOAT32_C(   242.21),
                         SIMDE_FLOAT32_C(  -393.24), SIMDE_FLOAT32_C(   738.28), SIMDE_FLOAT32_C(   192.78), SIMDE_FLOAT32_C(  -360.32)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -421.96), SIMDE_FLOAT32_C(  -741.98), SIMDE_FLOAT32_C(  -791.19), SIMDE_FLOAT32_C(   363.28),
                         SIMDE_FLOAT32_C(   168.15), SIMDE_FLOAT32_C(  -247.26), SIMDE_FLOAT32_C(   113.19), SIMDE_FLOAT32_C(   128.76),
                         SIMDE_FLOAT32_C(  -773.73), SIMDE_FLOAT32_C(   125.25), SIMDE_FLOAT32_C(   337.69), SIMDE_FLOAT32_C(  -644.22),
                         SIMDE_FLOAT32_C(   869.52), SIMDE_FLOAT32_C(   681.99), SIMDE_FLOAT32_C(   444.36), SIMDE_FLOAT32_C(   361.44)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   146.89), SIMDE_FLOAT32_C(    -2.27), SIMDE_FLOAT32_C(   208.93), SIMDE_FLOAT32_C(  -103.96),
                         SIMDE_FLOAT32_C(    42.04), SIMDE_FLOAT32_C(   -48.33), SIMDE_FLOAT32_C(    48.59), SIMDE_FLOAT32_C(   839.05),
                         SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(     2.76), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(     2.50),
                         SIMDE_FLOAT32_C(  -212.18), SIMDE_FLOAT32_C(   358.44), SIMDE_FLOAT32_C(   192.02), SIMDE_FLOAT32_C(   641.01)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -829.72), SIMDE_FLOAT32_C(   349.95), SIMDE_FLOAT32_C(   480.03), SIMDE_FLOAT32_C(  -584.69),
                         SIMDE_FLOAT32_C(   943.11), SIMDE_FLOAT32_C(  -148.79), SIMDE_FLOAT32_C(  -861.78), SIMDE_FLOAT32_C(  -270.87),
                         SIMDE_FLOAT32_C(  -593.74), SIMDE_FLOAT32_C(  -232.02), SIMDE_FLOAT32_C(  -553.31), SIMDE_FLOAT32_C(   693.33),
                         SIMDE_FLOAT32_C(  -533.82), SIMDE_FLOAT32_C(  -527.51), SIMDE_FLOAT32_C(  -140.16), SIMDE_FLOAT32_C(   631.76)),
      UINT16_C(50263),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   173.33), SIMDE_FLOAT32_C(  -281.34), SIMDE_FLOAT32_C(   -45.38), SIMDE_FLOAT32_C(  -230.23),
                         SIMDE_FLOAT32_C(  -937.39), SIMDE_FLOAT32_C(    53.86), SIMDE_FLOAT32_C(  -719.43), SIMDE_FLOAT32_C(   465.60),
                         SIMDE_FLOAT32_C(   111.60), SIMDE_FLOAT32_C(   156.01), SIMDE_FLOAT32_C(  -703.23), SIMDE_FLOAT32_C(   763.33),
                         SIMDE_FLOAT32_C(   119.12), SIMDE_FLOAT32_C(  -295.56), SIMDE_FLOAT32_C(   313.51), SIMDE_FLOAT32_C(  -193.21)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   396.81), SIMDE_FLOAT32_C(  -330.26), SIMDE_FLOAT32_C(  -500.01), SIMDE_FLOAT32_C(  -117.27),
                         SIMDE_FLOAT32_C(   805.35), SIMDE_FLOAT32_C(   722.55), SIMDE_FLOAT32_C(   274.82), SIMDE_FLOAT32_C(    32.73),
                         SIMDE_FLOAT32_C(  -564.66), SIMDE_FLOAT32_C(   180.25), SIMDE_FLOAT32_C(  -307.87), SIMDE_FLOAT32_C(   888.96),
                         SIMDE_FLOAT32_C(   806.77), SIMDE_FLOAT32_C(  -526.35), SIMDE_FLOAT32_C(   889.50), SIMDE_FLOAT32_C(   196.92)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   132.27), SIMDE_FLOAT32_C(  -264.26), SIMDE_FLOAT32_C(   480.03), SIMDE_FLOAT32_C(  -584.69),
                         SIMDE_FLOAT32_C(   943.11), SIMDE_FLOAT32_C(     2.31), SIMDE_FLOAT32_C(  -861.78), SIMDE_FLOAT32_C(  -270.87),
                         SIMDE_FLOAT32_C(  -593.74), SIMDE_FLOAT32_C(   148.00), SIMDE_FLOAT32_C(  -553.31), SIMDE_FLOAT32_C(   632.33),
                         SIMDE_FLOAT32_C(  -533.82), SIMDE_FLOAT32_C(    -2.06), SIMDE_FLOAT32_C(     2.44), SIMDE_FLOAT32_C(   192.13)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   425.40), SIMDE_FLOAT32_C(  -281.85), SIMDE_FLOAT32_C(   596.53), SIMDE_FLOAT32_C(   231.55),
                         SIMDE_FLOAT32_C(  -189.24), SIMDE_FLOAT32_C(   962.54), SIMDE_FLOAT32_C(   598.72), SIMDE_FLOAT32_C(  -728.82),
                         SIMDE_FLOAT32_C(   -31.34), SIMDE_FLOAT32_C(  -498.28), SIMDE_FLOAT32_C(  -106.48), SIMDE_FLOAT32_C(  -850.40),
                         SIMDE_FLOAT32_C(  -763.83), SIMDE_FLOAT32_C(   176.55), SIMDE_FLOAT32_C(   356.84), SIMDE_FLOAT32_C(   827.17)),
      UINT16_C(54643),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   761.43), SIMDE_FLOAT32_C(    95.69), SIMDE_FLOAT32_C(   888.39), SIMDE_FLOAT32_C(  -555.84),
                         SIMDE_FLOAT32_C(    40.33), SIMDE_FLOAT32_C(   358.74), SIMDE_FLOAT32_C(  -948.08), SIMDE_FLOAT32_C(   313.44),
                         SIMDE_FLOAT32_C(  -166.07), SIMDE_FLOAT32_C(  -218.95), SIMDE_FLOAT32_C(   360.34), SIMDE_FLOAT32_C(   989.68),
                         SIMDE_FLOAT32_C(   653.42), SIMDE_FLOAT32_C(   345.37), SIMDE_FLOAT32_C(   978.06), SIMDE_FLOAT32_C(   493.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   109.54), SIMDE_FLOAT32_C(   122.35), SIMDE_FLOAT32_C(   770.11), SIMDE_FLOAT32_C(   306.89),
                         SIMDE_FLOAT32_C(  -347.63), SIMDE_FLOAT32_C(   772.43), SIMDE_FLOAT32_C(   958.72), SIMDE_FLOAT32_C(  -435.18),
                         SIMDE_FLOAT32_C(  -680.27), SIMDE_FLOAT32_C(  -653.21), SIMDE_FLOAT32_C(   453.00), SIMDE_FLOAT32_C(   299.53),
                         SIMDE_FLOAT32_C(  -837.12), SIMDE_FLOAT32_C(    -8.00), SIMDE_FLOAT32_C(   561.63), SIMDE_FLOAT32_C(  -594.20)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.41), SIMDE_FLOAT32_C(    90.06), SIMDE_FLOAT32_C(   596.53), SIMDE_FLOAT32_C(     2.13),
                         SIMDE_FLOAT32_C(  -189.24), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(   598.72), SIMDE_FLOAT32_C(   305.13),
                         SIMDE_FLOAT32_C(   -31.34), SIMDE_FLOAT32_C(    -2.04), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(     2.33),
                         SIMDE_FLOAT32_C(  -763.83), SIMDE_FLOAT32_C(   176.55), SIMDE_FLOAT32_C(   528.01), SIMDE_FLOAT32_C(     2.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_and_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_and_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -128.09), SIMDE_FLOAT64_C( -302.68),
                         SIMDE_FLOAT64_C(  129.66), SIMDE_FLOAT64_C( -400.28),
                         SIMDE_FLOAT64_C( -687.60), SIMDE_FLOAT64_C( -568.06),
                         SIMDE_FLOAT64_C( -974.67), SIMDE_FLOAT64_C(  814.47)),
      UINT8_C( 92),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -854.57), SIMDE_FLOAT64_C(  353.06),
                         SIMDE_FLOAT64_C(  903.81), SIMDE_FLOAT64_C( -723.16),
                         SIMDE_FLOAT64_C( -194.97), SIMDE_FLOAT64_C(  114.89),
                         SIMDE_FLOAT64_C(  497.66), SIMDE_FLOAT64_C( -446.09)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -876.89), SIMDE_FLOAT64_C( -283.08),
                         SIMDE_FLOAT64_C(  642.58), SIMDE_FLOAT64_C( -973.49),
                         SIMDE_FLOAT64_C(  853.14), SIMDE_FLOAT64_C(  647.44),
                         SIMDE_FLOAT64_C(  237.52), SIMDE_FLOAT64_C( -333.12)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -128.09), SIMDE_FLOAT64_C(  257.02),
                         SIMDE_FLOAT64_C(  129.66), SIMDE_FLOAT64_C( -705.16),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(    2.53),
                         SIMDE_FLOAT64_C( -974.67), SIMDE_FLOAT64_C(  814.47)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   61.63), SIMDE_FLOAT64_C(  987.28),
                         SIMDE_FLOAT64_C( -845.84), SIMDE_FLOAT64_C( -822.08),
                         SIMDE_FLOAT64_C( -946.95), SIMDE_FLOAT64_C( -157.17),
                         SIMDE_FLOAT64_C(  808.43), SIMDE_FLOAT64_C(  716.34)),
      UINT8_C(128),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.33),
                         SIMDE_FLOAT64_C(  842.44), SIMDE_FLOAT64_C( -417.76),
                         SIMDE_FLOAT64_C( -171.61), SIMDE_FLOAT64_C(  -96.79),
                         SIMDE_FLOAT64_C(   45.73), SIMDE_FLOAT64_C(  312.19)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   54.70), SIMDE_FLOAT64_C( -228.57),
                         SIMDE_FLOAT64_C( -133.57), SIMDE_FLOAT64_C( -803.47),
                         SIMDE_FLOAT64_C(  821.61), SIMDE_FLOAT64_C(  198.21),
                         SIMDE_FLOAT64_C(  476.20), SIMDE_FLOAT64_C(  925.71)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    3.41), SIMDE_FLOAT64_C(  987.28),
                         SIMDE_FLOAT64_C( -845.84), SIMDE_FLOAT64_C( -822.08),
                         SIMDE_FLOAT64_C( -946.95), SIMDE_FLOAT64_C( -157.17),
                         SIMDE_FLOAT64_C(  808.43), SIMDE_FLOAT64_C(  716.34)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  -24.63), SIMDE_FLOAT64_C( -758.53),
                         SIMDE_FLOAT64_C(  216.18), SIMDE_FLOAT64_C( -869.86),
                         SIMDE_FLOAT64_C( -556.61), SIMDE_FLOAT64_C( -869.93),
                         SIMDE_FLOAT64_C(  935.72), SIMDE_FLOAT64_C(  467.65)),
      UINT8_C(132),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -373.41), SIMDE_FLOAT64_C(  558.94),
                         SIMDE_FLOAT64_C( -966.64), SIMDE_FLOAT64_C( -741.87),
                         SIMDE_FLOAT64_C( -915.12), SIMDE_FLOAT64_C( -226.56),
                         SIMDE_FLOAT64_C(  374.42), SIMDE_FLOAT64_C(  490.85)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  143.45), SIMDE_FLOAT64_C(   16.49),
                         SIMDE_FLOAT64_C(  323.05), SIMDE_FLOAT64_C( -564.38),
                         SIMDE_FLOAT64_C( -932.37), SIMDE_FLOAT64_C( -126.95),
                         SIMDE_FLOAT64_C(   46.50), SIMDE_FLOAT64_C(  812.07)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  138.19), SIMDE_FLOAT64_C( -758.53),
                         SIMDE_FLOAT64_C(  216.18), SIMDE_FLOAT64_C( -869.86),
                         SIMDE_FLOAT64_C( -556.61), SIMDE_FLOAT64_C(  -56.13),
                         SIMDE_FLOAT64_C(  935.72), SIMDE_FLOAT64_C(  467.65)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -587.51), SIMDE_FLOAT64_C( -331.04),
                         SIMDE_FLOAT64_C(  711.75), SIMDE_FLOAT64_C( -149.95),
                         SIMDE_FLOAT64_C( -625.31), SIMDE_FLOAT64_C(  387.07),
                         SIMDE_FLOAT64_C(  510.51), SIMDE_FLOAT64_C( -791.87)),
      UINT8_C(197),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -995.18), SIMDE_FLOAT64_C(  720.96),
                         SIMDE_FLOAT64_C(  859.59), SIMDE_FLOAT64_C(   20.65),
                         SIMDE_FLOAT64_C( -207.40), SIMDE_FLOAT64_C( -632.30),
                         SIMDE_FLOAT64_C( -783.67), SIMDE_FLOAT64_C(  389.24)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -619.09), SIMDE_FLOAT64_C(  681.55),
                         SIMDE_FLOAT64_C(  914.89), SIMDE_FLOAT64_C(  240.13),
                         SIMDE_FLOAT64_C(   14.06), SIMDE_FLOAT64_C( -669.70),
                         SIMDE_FLOAT64_C(  554.04), SIMDE_FLOAT64_C( -602.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -611.02), SIMDE_FLOAT64_C(  640.52),
                         SIMDE_FLOAT64_C(  711.75), SIMDE_FLOAT64_C( -149.95),
                         SIMDE_FLOAT64_C( -625.31), SIMDE_FLOAT64_C( -536.00),
                         SIMDE_FLOAT64_C(  510.51), SIMDE_FLOAT64_C(    2.04)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(   28.17), SIMDE_FLOAT64_C( -545.33),
                         SIMDE_FLOAT64_C( -993.85), SIMDE_FLOAT64_C( -636.74),
                         SIMDE_FLOAT64_C(  315.22), SIMDE_FLOAT64_C( -560.48),
                         SIMDE_FLOAT64_C( -264.88), SIMDE_FLOAT64_C(  866.66)),
      UINT8_C(152),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -378.42), SIMDE_FLOAT64_C( -112.43),
                         SIMDE_FLOAT64_C( -147.85), SIMDE_FLOAT64_C(  481.16),
                         SIMDE_FLOAT64_C(  980.68), SIMDE_FLOAT64_C(  999.62),
                         SIMDE_FLOAT64_C( -784.92), SIMDE_FLOAT64_C( -245.05)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  838.26), SIMDE_FLOAT64_C( -863.14),
                         SIMDE_FLOAT64_C(  336.07), SIMDE_FLOAT64_C(  237.32),
                         SIMDE_FLOAT64_C( -803.75), SIMDE_FLOAT64_C(  816.96),
                         SIMDE_FLOAT64_C(  217.54), SIMDE_FLOAT64_C( -660.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.27), SIMDE_FLOAT64_C( -545.33),
                         SIMDE_FLOAT64_C( -993.85), SIMDE_FLOAT64_C(  224.06),
                         SIMDE_FLOAT64_C(  768.50), SIMDE_FLOAT64_C( -560.48),
                         SIMDE_FLOAT64_C( -264.88), SIMDE_FLOAT64_C(  866.66)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  106.10), SIMDE_FLOAT64_C(  605.57),
                         SIMDE_FLOAT64_C(  481.85), SIMDE_FLOAT64_C(  491.86),
                         SIMDE_FLOAT64_C(  -77.86), SIMDE_FLOAT64_C( -839.61),
                         SIMDE_FLOAT64_C(  936.76), SIMDE_FLOAT64_C( -659.60)),
      UINT8_C(  7),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  505.82), SIMDE_FLOAT64_C( -629.98),
                         SIMDE_FLOAT64_C( -555.91), SIMDE_FLOAT64_C( -911.21),
                         SIMDE_FLOAT64_C(  603.24), SIMDE_FLOAT64_C(  -95.72),
                         SIMDE_FLOAT64_C(  864.74), SIMDE_FLOAT64_C(  280.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  570.36), SIMDE_FLOAT64_C(  765.47),
                         SIMDE_FLOAT64_C(  327.71), SIMDE_FLOAT64_C( -605.34),
                         SIMDE_FLOAT64_C(  509.13), SIMDE_FLOAT64_C( -583.43),
                         SIMDE_FLOAT64_C( -208.99), SIMDE_FLOAT64_C(  835.11)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  106.10), SIMDE_FLOAT64_C(  605.57),
                         SIMDE_FLOAT64_C(  481.85), SIMDE_FLOAT64_C(  491.86),
                         SIMDE_FLOAT64_C(  -77.86), SIMDE_FLOAT64_C(   -2.27),
                         SIMDE_FLOAT64_C(    3.25), SIMDE_FLOAT64_C(    2.00)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -925.64), SIMDE_FLOAT64_C(  122.27),
                         SIMDE_FLOAT64_C( -971.29), SIMDE_FLOAT64_C( -200.64),
                         SIMDE_FLOAT64_C(  268.43), SIMDE_FLOAT64_C(  995.23),
                         SIMDE_FLOAT64_C(  958.62), SIMDE_FLOAT64_C( -530.89)),
      UINT8_C(252),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -311.17), SIMDE_FLOAT64_C( -787.17),
                         SIMDE_FLOAT64_C( -427.34), SIMDE_FLOAT64_C(  839.17),
                         SIMDE_FLOAT64_C( -404.83), SIMDE_FLOAT64_C(  559.72),
                         SIMDE_FLOAT64_C(  982.82), SIMDE_FLOAT64_C( -251.36)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  643.61), SIMDE_FLOAT64_C(  953.53),
                         SIMDE_FLOAT64_C( -469.49), SIMDE_FLOAT64_C(   -8.31),
                         SIMDE_FLOAT64_C(  325.63), SIMDE_FLOAT64_C( -753.50),
                         SIMDE_FLOAT64_C( -462.28), SIMDE_FLOAT64_C( -779.29)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(  785.01),
                         SIMDE_FLOAT64_C( -385.33), SIMDE_FLOAT64_C(    2.01),
                         SIMDE_FLOAT64_C(  260.50), SIMDE_FLOAT64_C(  545.50),
                         SIMDE_FLOAT64_C(  958.62), SIMDE_FLOAT64_C( -530.89)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  -62.82), SIMDE_FLOAT64_C(  -95.66),
                         SIMDE_FLOAT64_C(  484.39), SIMDE_FLOAT64_C( -736.85),
                         SIMDE_FLOAT64_C(  893.63), SIMDE_FLOAT64_C( -173.06),
                         SIMDE_FLOAT64_C(  113.69), SIMDE_FLOAT64_C(  198.15)),
      UINT8_C(239),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  440.07), SIMDE_FLOAT64_C(  639.74),
                         SIMDE_FLOAT64_C(  566.84), SIMDE_FLOAT64_C(  207.87),
                         SIMDE_FLOAT64_C( -578.31), SIMDE_FLOAT64_C( -772.29),
                         SIMDE_FLOAT64_C(   70.78), SIMDE_FLOAT64_C(  181.63)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -750.95), SIMDE_FLOAT64_C(  172.27),
                         SIMDE_FLOAT64_C( -538.71), SIMDE_FLOAT64_C( -512.10),
                         SIMDE_FLOAT64_C( -406.87), SIMDE_FLOAT64_C( -470.10),
                         SIMDE_FLOAT64_C( -652.40), SIMDE_FLOAT64_C( -121.85)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.38), SIMDE_FLOAT64_C(    2.19),
                         SIMDE_FLOAT64_C(  530.58), SIMDE_FLOAT64_C( -736.85),
                         SIMDE_FLOAT64_C(   -2.00), SIMDE_FLOAT64_C(   -3.02),
                         SIMDE_FLOAT64_C(    2.02), SIMDE_FLOAT64_C(   44.41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_and_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_maskz_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
   {  UINT16_C(57131),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   399.48), SIMDE_FLOAT32_C(  -238.06), SIMDE_FLOAT32_C(  -893.32), SIMDE_FLOAT32_C(  -435.26),
                         SIMDE_FLOAT32_C(   522.86), SIMDE_FLOAT32_C(  -612.44), SIMDE_FLOAT32_C(   652.00), SIMDE_FLOAT32_C(   895.17),
                         SIMDE_FLOAT32_C(  -820.93), SIMDE_FLOAT32_C(   533.04), SIMDE_FLOAT32_C(   403.71), SIMDE_FLOAT32_C(   282.24),
                         SIMDE_FLOAT32_C(   883.67), SIMDE_FLOAT32_C(    22.67), SIMDE_FLOAT32_C(   804.53), SIMDE_FLOAT32_C(   307.97)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   932.69), SIMDE_FLOAT32_C(   912.86), SIMDE_FLOAT32_C(   409.21), SIMDE_FLOAT32_C(   585.68),
                         SIMDE_FLOAT32_C(   -59.99), SIMDE_FLOAT32_C(  -146.01), SIMDE_FLOAT32_C(   160.06), SIMDE_FLOAT32_C(  -248.23),
                         SIMDE_FLOAT32_C(   780.27), SIMDE_FLOAT32_C(  -642.04), SIMDE_FLOAT32_C(   -94.76), SIMDE_FLOAT32_C(   563.52),
                         SIMDE_FLOAT32_C(  -953.85), SIMDE_FLOAT32_C(  -735.06), SIMDE_FLOAT32_C(   312.07), SIMDE_FLOAT32_C(  -630.77)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     3.02), SIMDE_FLOAT32_C(     3.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.25),
                         SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(    -2.25), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     3.38),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    68.75), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   817.54), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(     2.40)) },
   {  UINT16_C(37107),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   145.79), SIMDE_FLOAT32_C(  -588.79), SIMDE_FLOAT32_C(   895.99), SIMDE_FLOAT32_C(  -454.35),
                         SIMDE_FLOAT32_C(   444.71), SIMDE_FLOAT32_C(   343.63), SIMDE_FLOAT32_C(   -33.93), SIMDE_FLOAT32_C(  -461.47),
                         SIMDE_FLOAT32_C(   -87.51), SIMDE_FLOAT32_C(  -587.34), SIMDE_FLOAT32_C(   -54.40), SIMDE_FLOAT32_C(  -339.84),
                         SIMDE_FLOAT32_C(  -976.14), SIMDE_FLOAT32_C(   850.15), SIMDE_FLOAT32_C(  -700.02), SIMDE_FLOAT32_C(  -579.46)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   720.42), SIMDE_FLOAT32_C(  -585.67), SIMDE_FLOAT32_C(  -388.81), SIMDE_FLOAT32_C(   165.49),
                         SIMDE_FLOAT32_C(   525.65), SIMDE_FLOAT32_C(   441.42), SIMDE_FLOAT32_C(   424.69), SIMDE_FLOAT32_C(   567.94),
                         SIMDE_FLOAT32_C(  -243.26), SIMDE_FLOAT32_C(   977.37), SIMDE_FLOAT32_C(  -705.87), SIMDE_FLOAT32_C(   365.97),
                         SIMDE_FLOAT32_C(  -511.37), SIMDE_FLOAT32_C(   335.33), SIMDE_FLOAT32_C(  -871.52), SIMDE_FLOAT32_C(  -805.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     2.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   161.17),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   -40.75), SIMDE_FLOAT32_C(   577.34), SIMDE_FLOAT32_C(    -2.25), SIMDE_FLOAT32_C(   321.81),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -548.02), SIMDE_FLOAT32_C(  -513.07)) },
   {  UINT16_C(56908),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   813.26), SIMDE_FLOAT32_C(  -716.74), SIMDE_FLOAT32_C(  -548.55), SIMDE_FLOAT32_C(   -83.12),
                         SIMDE_FLOAT32_C(   301.84), SIMDE_FLOAT32_C(  -843.69), SIMDE_FLOAT32_C(  -236.76), SIMDE_FLOAT32_C(   -34.42),
                         SIMDE_FLOAT32_C(  -591.83), SIMDE_FLOAT32_C(    11.80), SIMDE_FLOAT32_C(   521.39), SIMDE_FLOAT32_C(  -937.14),
                         SIMDE_FLOAT32_C(  -662.16), SIMDE_FLOAT32_C(  -974.03), SIMDE_FLOAT32_C(   576.46), SIMDE_FLOAT32_C(   704.69)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   914.44), SIMDE_FLOAT32_C(  -904.34), SIMDE_FLOAT32_C(    -4.84), SIMDE_FLOAT32_C(   -59.72),
                         SIMDE_FLOAT32_C(  -523.01), SIMDE_FLOAT32_C(   236.78), SIMDE_FLOAT32_C(    88.72), SIMDE_FLOAT32_C(  -251.99),
                         SIMDE_FLOAT32_C(  -782.65), SIMDE_FLOAT32_C(   -38.86), SIMDE_FLOAT32_C(   670.53), SIMDE_FLOAT32_C(   706.52),
                         SIMDE_FLOAT32_C(   990.40), SIMDE_FLOAT32_C(  -812.48), SIMDE_FLOAT32_C(  -152.33), SIMDE_FLOAT32_C(   172.86)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   768.25), SIMDE_FLOAT32_C(  -648.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -41.53),
                         SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(     3.01), SIMDE_FLOAT32_C(    40.06), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   662.13), SIMDE_FLOAT32_C(  -780.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(13045),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -696.33), SIMDE_FLOAT32_C(  -640.98), SIMDE_FLOAT32_C(  -234.04), SIMDE_FLOAT32_C(   691.30),
                         SIMDE_FLOAT32_C(   422.16), SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(   150.98), SIMDE_FLOAT32_C(  -727.93),
                         SIMDE_FLOAT32_C(  -292.95), SIMDE_FLOAT32_C(  -168.48), SIMDE_FLOAT32_C(   430.75), SIMDE_FLOAT32_C(   298.75),
                         SIMDE_FLOAT32_C(  -938.39), SIMDE_FLOAT32_C(   166.50), SIMDE_FLOAT32_C(   295.10), SIMDE_FLOAT32_C(   -66.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   725.67), SIMDE_FLOAT32_C(   691.57), SIMDE_FLOAT32_C(   408.92), SIMDE_FLOAT32_C(  -190.91),
                         SIMDE_FLOAT32_C(   682.56), SIMDE_FLOAT32_C(   311.99), SIMDE_FLOAT32_C(  -213.61), SIMDE_FLOAT32_C(  -160.20),
                         SIMDE_FLOAT32_C(  -421.91), SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(   657.47), SIMDE_FLOAT32_C(   816.91),
                         SIMDE_FLOAT32_C(   267.68), SIMDE_FLOAT32_C(   898.52), SIMDE_FLOAT32_C(   -80.12), SIMDE_FLOAT32_C(  -724.23)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   200.00), SIMDE_FLOAT32_C(     2.70),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   148.59), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -292.88), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(     2.06),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -2.08)) },
   {  UINT16_C(11913),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   315.17), SIMDE_FLOAT32_C(  -863.78), SIMDE_FLOAT32_C(   344.73), SIMDE_FLOAT32_C(  -570.00),
                         SIMDE_FLOAT32_C(  -265.79), SIMDE_FLOAT32_C(   403.67), SIMDE_FLOAT32_C(   -62.80), SIMDE_FLOAT32_C(   251.47),
                         SIMDE_FLOAT32_C(   143.15), SIMDE_FLOAT32_C(   960.55), SIMDE_FLOAT32_C(  -156.81), SIMDE_FLOAT32_C(   258.89),
                         SIMDE_FLOAT32_C(    14.13), SIMDE_FLOAT32_C(   117.08), SIMDE_FLOAT32_C(  -266.20), SIMDE_FLOAT32_C(   383.43)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -568.28), SIMDE_FLOAT32_C(  -745.49), SIMDE_FLOAT32_C(  -964.75), SIMDE_FLOAT32_C(   259.38),
                         SIMDE_FLOAT32_C(   750.99), SIMDE_FLOAT32_C(  -521.20), SIMDE_FLOAT32_C(   513.21), SIMDE_FLOAT32_C(   787.79),
                         SIMDE_FLOAT32_C(   316.72), SIMDE_FLOAT32_C(   -19.08), SIMDE_FLOAT32_C(  -845.60), SIMDE_FLOAT32_C(   815.31),
                         SIMDE_FLOAT32_C(  -301.01), SIMDE_FLOAT32_C(   479.36), SIMDE_FLOAT32_C(  -159.67), SIMDE_FLOAT32_C(  -155.94)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   142.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     8.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   155.69)) },
   {  UINT16_C(38742),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -500.21), SIMDE_FLOAT32_C(  -899.42), SIMDE_FLOAT32_C(   770.51), SIMDE_FLOAT32_C(   777.58),
                         SIMDE_FLOAT32_C(   547.07), SIMDE_FLOAT32_C(   747.18), SIMDE_FLOAT32_C(    16.17), SIMDE_FLOAT32_C(   859.01),
                         SIMDE_FLOAT32_C(    78.72), SIMDE_FLOAT32_C(  -378.16), SIMDE_FLOAT32_C(  -980.04), SIMDE_FLOAT32_C(   143.56),
                         SIMDE_FLOAT32_C(  -706.63), SIMDE_FLOAT32_C(  -986.84), SIMDE_FLOAT32_C(  -673.32), SIMDE_FLOAT32_C(  -774.96)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -321.38), SIMDE_FLOAT32_C(  -244.51), SIMDE_FLOAT32_C(   579.94), SIMDE_FLOAT32_C(   895.47),
                         SIMDE_FLOAT32_C(  -321.30), SIMDE_FLOAT32_C(    92.97), SIMDE_FLOAT32_C(  -270.40), SIMDE_FLOAT32_C(  -439.43),
                         SIMDE_FLOAT32_C(   971.85), SIMDE_FLOAT32_C(   799.33), SIMDE_FLOAT32_C(   -17.61), SIMDE_FLOAT32_C(  -762.15),
                         SIMDE_FLOAT32_C(  -813.48), SIMDE_FLOAT32_C(   494.42), SIMDE_FLOAT32_C(   374.64), SIMDE_FLOAT32_C(  -744.47)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -320.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   777.06),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.89), SIMDE_FLOAT32_C(    16.13), SIMDE_FLOAT32_C(     3.29),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.23),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     3.85), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(53846),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   400.20), SIMDE_FLOAT32_C(   275.50), SIMDE_FLOAT32_C(   916.86), SIMDE_FLOAT32_C(  -531.67),
                         SIMDE_FLOAT32_C(  -909.37), SIMDE_FLOAT32_C(   993.65), SIMDE_FLOAT32_C(   633.64), SIMDE_FLOAT32_C(  -178.42),
                         SIMDE_FLOAT32_C(   412.35), SIMDE_FLOAT32_C(  -571.03), SIMDE_FLOAT32_C(   345.26), SIMDE_FLOAT32_C(   493.12),
                         SIMDE_FLOAT32_C(  -719.68), SIMDE_FLOAT32_C(   769.35), SIMDE_FLOAT32_C(  -373.84), SIMDE_FLOAT32_C(  -540.22)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -282.19), SIMDE_FLOAT32_C(  -584.18), SIMDE_FLOAT32_C(   433.06), SIMDE_FLOAT32_C(   752.23),
                         SIMDE_FLOAT32_C(  -792.10), SIMDE_FLOAT32_C(   940.65), SIMDE_FLOAT32_C(  -237.54), SIMDE_FLOAT32_C(  -796.45),
                         SIMDE_FLOAT32_C(   821.11), SIMDE_FLOAT32_C(  -769.48), SIMDE_FLOAT32_C(   951.19), SIMDE_FLOAT32_C(   526.89),
                         SIMDE_FLOAT32_C(   481.01), SIMDE_FLOAT32_C(  -678.70), SIMDE_FLOAT32_C(   690.79), SIMDE_FLOAT32_C(  -617.07)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   272.19), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   528.17),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.19), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -513.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.04),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   512.07), SIMDE_FLOAT32_C(     2.63), SIMDE_FLOAT32_C(     0.00)) },
   {  UINT16_C(45516),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -637.18), SIMDE_FLOAT32_C(   934.54), SIMDE_FLOAT32_C(   112.29), SIMDE_FLOAT32_C(   139.60),
                         SIMDE_FLOAT32_C(  -371.31), SIMDE_FLOAT32_C(  -676.65), SIMDE_FLOAT32_C(  -607.44), SIMDE_FLOAT32_C(  -108.80),
                         SIMDE_FLOAT32_C(  -631.32), SIMDE_FLOAT32_C(   553.47), SIMDE_FLOAT32_C(  -653.07), SIMDE_FLOAT32_C(  -272.71),
                         SIMDE_FLOAT32_C(  -438.05), SIMDE_FLOAT32_C(   -69.28), SIMDE_FLOAT32_C(   220.30), SIMDE_FLOAT32_C(  -879.60)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   695.29), SIMDE_FLOAT32_C(  -288.10), SIMDE_FLOAT32_C(     8.22), SIMDE_FLOAT32_C(   267.50),
                         SIMDE_FLOAT32_C(  -160.08), SIMDE_FLOAT32_C(   251.69), SIMDE_FLOAT32_C(   416.95), SIMDE_FLOAT32_C(   429.19),
                         SIMDE_FLOAT32_C(  -938.09), SIMDE_FLOAT32_C(  -996.83), SIMDE_FLOAT32_C(   772.01), SIMDE_FLOAT32_C(   -88.73),
                         SIMDE_FLOAT32_C(  -661.22), SIMDE_FLOAT32_C(  -945.44), SIMDE_FLOAT32_C(   528.59), SIMDE_FLOAT32_C(   677.63)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   565.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.01), SIMDE_FLOAT32_C(   129.50),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   104.30),
                         SIMDE_FLOAT32_C(  -546.07), SIMDE_FLOAT32_C(   544.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -2.02), SIMDE_FLOAT32_C(    -2.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_maskz_and_ps(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_maskz_and_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
   {  UINT8_C( 62),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  337.23), SIMDE_FLOAT64_C( -706.51),
                         SIMDE_FLOAT64_C(  -51.03), SIMDE_FLOAT64_C(  -11.12),
                         SIMDE_FLOAT64_C(  780.39), SIMDE_FLOAT64_C(  482.32),
                         SIMDE_FLOAT64_C( -313.20), SIMDE_FLOAT64_C(  986.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -459.33), SIMDE_FLOAT64_C(  566.75),
                         SIMDE_FLOAT64_C(  454.16), SIMDE_FLOAT64_C( -566.29),
                         SIMDE_FLOAT64_C(  217.01), SIMDE_FLOAT64_C( -444.68),
                         SIMDE_FLOAT64_C(  725.53), SIMDE_FLOAT64_C( -673.17)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(   48.02), SIMDE_FLOAT64_C(   -2.02),
                         SIMDE_FLOAT64_C(    3.02), SIMDE_FLOAT64_C(  416.00),
                         SIMDE_FLOAT64_C(    2.31), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(178),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  988.70), SIMDE_FLOAT64_C(  952.56),
                         SIMDE_FLOAT64_C( -917.57), SIMDE_FLOAT64_C( -161.93),
                         SIMDE_FLOAT64_C(  553.05), SIMDE_FLOAT64_C(  358.83),
                         SIMDE_FLOAT64_C( -335.21), SIMDE_FLOAT64_C(  243.33)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  368.67), SIMDE_FLOAT64_C( -326.68),
                         SIMDE_FLOAT64_C( -767.44), SIMDE_FLOAT64_C( -965.45),
                         SIMDE_FLOAT64_C(  160.34), SIMDE_FLOAT64_C( -153.49),
                         SIMDE_FLOAT64_C(  842.87), SIMDE_FLOAT64_C( -959.77)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.75), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -661.06), SIMDE_FLOAT64_C(   -2.52),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    2.04), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(233),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  789.99), SIMDE_FLOAT64_C(   -0.83),
                         SIMDE_FLOAT64_C( -595.87), SIMDE_FLOAT64_C( -556.04),
                         SIMDE_FLOAT64_C( -673.58), SIMDE_FLOAT64_C(  820.52),
                         SIMDE_FLOAT64_C(  763.24), SIMDE_FLOAT64_C(  747.54)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -863.51), SIMDE_FLOAT64_C(  297.93),
                         SIMDE_FLOAT64_C(  664.70), SIMDE_FLOAT64_C(   43.00),
                         SIMDE_FLOAT64_C(  283.69), SIMDE_FLOAT64_C( -882.73),
                         SIMDE_FLOAT64_C(   56.70), SIMDE_FLOAT64_C( -683.31)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  789.50), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  528.57), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    2.13), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  683.04)) },
   {  UINT8_C( 29),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -942.62), SIMDE_FLOAT64_C(  810.42),
                         SIMDE_FLOAT64_C( -781.08), SIMDE_FLOAT64_C(  565.31),
                         SIMDE_FLOAT64_C( -528.23), SIMDE_FLOAT64_C( -642.03),
                         SIMDE_FLOAT64_C( -124.04), SIMDE_FLOAT64_C(  -13.65)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   20.85), SIMDE_FLOAT64_C( -517.24),
                         SIMDE_FLOAT64_C(  -21.32), SIMDE_FLOAT64_C(  729.98),
                         SIMDE_FLOAT64_C( -763.15), SIMDE_FLOAT64_C(  885.38),
                         SIMDE_FLOAT64_C(  783.63), SIMDE_FLOAT64_C(  470.19)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  529.29),
                         SIMDE_FLOAT64_C( -528.13), SIMDE_FLOAT64_C(  512.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   12.63)) },
   {  UINT8_C(102),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -36.60), SIMDE_FLOAT64_C(  -71.02),
                         SIMDE_FLOAT64_C(  654.55), SIMDE_FLOAT64_C( -335.18),
                         SIMDE_FLOAT64_C( -889.86), SIMDE_FLOAT64_C( -624.64),
                         SIMDE_FLOAT64_C(  369.01), SIMDE_FLOAT64_C(  798.90)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -217.14), SIMDE_FLOAT64_C( -334.27),
                         SIMDE_FLOAT64_C(  522.28), SIMDE_FLOAT64_C(  754.78),
                         SIMDE_FLOAT64_C( -987.63), SIMDE_FLOAT64_C(  746.58),
                         SIMDE_FLOAT64_C(  358.61), SIMDE_FLOAT64_C( -154.14)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  -67.00),
                         SIMDE_FLOAT64_C(  522.02), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  608.50),
                         SIMDE_FLOAT64_C(  352.00), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(126),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -16.31), SIMDE_FLOAT64_C(  -95.18),
                         SIMDE_FLOAT64_C(  860.06), SIMDE_FLOAT64_C(  464.41),
                         SIMDE_FLOAT64_C(  822.39), SIMDE_FLOAT64_C(  185.79),
                         SIMDE_FLOAT64_C(  959.83), SIMDE_FLOAT64_C(  -98.41)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -560.42), SIMDE_FLOAT64_C( -521.57),
                         SIMDE_FLOAT64_C( -947.45), SIMDE_FLOAT64_C(   99.55),
                         SIMDE_FLOAT64_C(  108.53), SIMDE_FLOAT64_C(  194.26),
                         SIMDE_FLOAT64_C(  449.89), SIMDE_FLOAT64_C(  718.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -2.04),
                         SIMDE_FLOAT64_C(  784.01), SIMDE_FLOAT64_C(   96.03),
                         SIMDE_FLOAT64_C(    3.14), SIMDE_FLOAT64_C(  128.26),
                         SIMDE_FLOAT64_C(    3.51), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(231),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -343.46), SIMDE_FLOAT64_C(  643.05),
                         SIMDE_FLOAT64_C(  758.23), SIMDE_FLOAT64_C(  243.41),
                         SIMDE_FLOAT64_C( -569.27), SIMDE_FLOAT64_C(   62.99),
                         SIMDE_FLOAT64_C(  403.36), SIMDE_FLOAT64_C( -111.26)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  594.69), SIMDE_FLOAT64_C(  416.92),
                         SIMDE_FLOAT64_C(  294.94), SIMDE_FLOAT64_C( -386.69),
                         SIMDE_FLOAT64_C(  444.27), SIMDE_FLOAT64_C(  112.48),
                         SIMDE_FLOAT64_C(  775.25), SIMDE_FLOAT64_C(  973.66)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(    2.00),
                         SIMDE_FLOAT64_C(    2.27), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   56.24),
                         SIMDE_FLOAT64_C(    3.02), SIMDE_FLOAT64_C(    3.28)) },
   {  UINT8_C(248),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  559.94), SIMDE_FLOAT64_C( -177.36),
                         SIMDE_FLOAT64_C(  459.52), SIMDE_FLOAT64_C(  151.00),
                         SIMDE_FLOAT64_C( -261.20), SIMDE_FLOAT64_C(  619.75),
                         SIMDE_FLOAT64_C( -541.43), SIMDE_FLOAT64_C( -420.37)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  279.51), SIMDE_FLOAT64_C(  143.05),
                         SIMDE_FLOAT64_C(  835.37), SIMDE_FLOAT64_C( -486.11),
                         SIMDE_FLOAT64_C(  461.53), SIMDE_FLOAT64_C(  410.57),
                         SIMDE_FLOAT64_C( -362.30), SIMDE_FLOAT64_C( -345.54)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    2.18), SIMDE_FLOAT64_C(  129.05),
                         SIMDE_FLOAT64_C(    3.01), SIMDE_FLOAT64_C(  147.00),
                         SIMDE_FLOAT64_C(  261.01), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_maskz_and_pd(test_vec[i].k, test_vec[i].a, test_vec[i].b);
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
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_and_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_mask_and_pd),
  SIMDE_TESTS_DEFINE_TEST(mm512_maskz_and_ps),
  SIMDE_TESTS_DEFINE_TEST(mm512_maskz_and_pd),
  

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
