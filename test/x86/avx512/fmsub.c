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
 *   2020      kitegi <kitegi@users.noreply.github.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN fmsub

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/fmsub.h>

static int
test_simde_mm512_fmsub_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 c[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    39.18), SIMDE_FLOAT32_C(    72.95), SIMDE_FLOAT32_C(     2.39), SIMDE_FLOAT32_C(   -99.28),
        SIMDE_FLOAT32_C(   -27.76), SIMDE_FLOAT32_C(    78.92), SIMDE_FLOAT32_C(    97.46), SIMDE_FLOAT32_C(   -75.13),
        SIMDE_FLOAT32_C(   -78.86), SIMDE_FLOAT32_C(    62.73), SIMDE_FLOAT32_C(    46.15), SIMDE_FLOAT32_C(   -15.69),
        SIMDE_FLOAT32_C(   -66.26), SIMDE_FLOAT32_C(    -2.97), SIMDE_FLOAT32_C(    64.58), SIMDE_FLOAT32_C(   -96.46) },
      { SIMDE_FLOAT32_C(    87.93), SIMDE_FLOAT32_C(   -57.28), SIMDE_FLOAT32_C(   -38.98), SIMDE_FLOAT32_C(    16.76),
        SIMDE_FLOAT32_C(    -7.19), SIMDE_FLOAT32_C(   -49.24), SIMDE_FLOAT32_C(   -45.18), SIMDE_FLOAT32_C(    16.45),
        SIMDE_FLOAT32_C(   -68.84), SIMDE_FLOAT32_C(   -51.68), SIMDE_FLOAT32_C(    46.34), SIMDE_FLOAT32_C(    24.50),
        SIMDE_FLOAT32_C(   -28.63), SIMDE_FLOAT32_C(   -74.05), SIMDE_FLOAT32_C(   -21.93), SIMDE_FLOAT32_C(   -89.45) },
      { SIMDE_FLOAT32_C(    98.91), SIMDE_FLOAT32_C(    80.47), SIMDE_FLOAT32_C(   -88.73), SIMDE_FLOAT32_C(   -28.86),
        SIMDE_FLOAT32_C(    59.39), SIMDE_FLOAT32_C(   -91.27), SIMDE_FLOAT32_C(    -3.99), SIMDE_FLOAT32_C(    80.52),
        SIMDE_FLOAT32_C(    71.46), SIMDE_FLOAT32_C(   -57.84), SIMDE_FLOAT32_C(   -35.17), SIMDE_FLOAT32_C(   -94.81),
        SIMDE_FLOAT32_C(    39.19), SIMDE_FLOAT32_C(   -70.59), SIMDE_FLOAT32_C(   -91.26), SIMDE_FLOAT32_C(    27.12) },
      { SIMDE_FLOAT32_C(  3346.19), SIMDE_FLOAT32_C( -4259.05), SIMDE_FLOAT32_C(    -4.43), SIMDE_FLOAT32_C( -1635.07),
        SIMDE_FLOAT32_C(   140.20), SIMDE_FLOAT32_C( -3794.75), SIMDE_FLOAT32_C( -4399.25), SIMDE_FLOAT32_C( -1316.41),
        SIMDE_FLOAT32_C(  5357.26), SIMDE_FLOAT32_C( -3184.05), SIMDE_FLOAT32_C(  2173.76), SIMDE_FLOAT32_C(  -289.60),
        SIMDE_FLOAT32_C(  1857.83), SIMDE_FLOAT32_C(   290.52), SIMDE_FLOAT32_C( -1324.98), SIMDE_FLOAT32_C(  8601.23) } },
    { { SIMDE_FLOAT32_C(   -27.87), SIMDE_FLOAT32_C(   -30.25), SIMDE_FLOAT32_C(   -56.12), SIMDE_FLOAT32_C(    64.94),
        SIMDE_FLOAT32_C(    20.51), SIMDE_FLOAT32_C(    -1.30), SIMDE_FLOAT32_C(   -18.61), SIMDE_FLOAT32_C(    51.67),
        SIMDE_FLOAT32_C(    47.02), SIMDE_FLOAT32_C(   -72.27), SIMDE_FLOAT32_C(   -23.83), SIMDE_FLOAT32_C(   -81.60),
        SIMDE_FLOAT32_C(   -46.31), SIMDE_FLOAT32_C(    54.24), SIMDE_FLOAT32_C(   -71.05), SIMDE_FLOAT32_C(   -47.41) },
      { SIMDE_FLOAT32_C(    34.71), SIMDE_FLOAT32_C(   -59.79), SIMDE_FLOAT32_C(    23.73), SIMDE_FLOAT32_C(    -5.90),
        SIMDE_FLOAT32_C(   -51.06), SIMDE_FLOAT32_C(   -80.26), SIMDE_FLOAT32_C(   -25.38), SIMDE_FLOAT32_C(   -79.60),
        SIMDE_FLOAT32_C(   -38.10), SIMDE_FLOAT32_C(    39.45), SIMDE_FLOAT32_C(   -74.41), SIMDE_FLOAT32_C(   -98.91),
        SIMDE_FLOAT32_C(    68.87), SIMDE_FLOAT32_C(   -65.67), SIMDE_FLOAT32_C(    28.21), SIMDE_FLOAT32_C(   -59.01) },
      { SIMDE_FLOAT32_C(     4.08), SIMDE_FLOAT32_C(    72.09), SIMDE_FLOAT32_C(   -94.06), SIMDE_FLOAT32_C(   -75.41),
        SIMDE_FLOAT32_C(   -29.20), SIMDE_FLOAT32_C(   -12.67), SIMDE_FLOAT32_C(    76.26), SIMDE_FLOAT32_C(   -82.18),
        SIMDE_FLOAT32_C(    15.06), SIMDE_FLOAT32_C(   -47.57), SIMDE_FLOAT32_C(   -63.79), SIMDE_FLOAT32_C(    68.75),
        SIMDE_FLOAT32_C(   -93.33), SIMDE_FLOAT32_C(   -34.84), SIMDE_FLOAT32_C(   -78.66), SIMDE_FLOAT32_C(    41.38) },
      { SIMDE_FLOAT32_C(  -971.45), SIMDE_FLOAT32_C(  1736.56), SIMDE_FLOAT32_C( -1237.67), SIMDE_FLOAT32_C(  -307.74),
        SIMDE_FLOAT32_C( -1018.04), SIMDE_FLOAT32_C(   117.01), SIMDE_FLOAT32_C(   396.06), SIMDE_FLOAT32_C( -4030.75),
        SIMDE_FLOAT32_C( -1806.52), SIMDE_FLOAT32_C( -2803.48), SIMDE_FLOAT32_C(  1836.98), SIMDE_FLOAT32_C(  8002.31),
        SIMDE_FLOAT32_C( -3096.04), SIMDE_FLOAT32_C( -3527.10), SIMDE_FLOAT32_C( -1925.66), SIMDE_FLOAT32_C(  2756.28) } },
    { { SIMDE_FLOAT32_C(     5.37), SIMDE_FLOAT32_C(    45.08), SIMDE_FLOAT32_C(   -64.53), SIMDE_FLOAT32_C(    54.31),
        SIMDE_FLOAT32_C(    64.82), SIMDE_FLOAT32_C(    10.09), SIMDE_FLOAT32_C(    74.71), SIMDE_FLOAT32_C(   -73.28),
        SIMDE_FLOAT32_C(   -50.46), SIMDE_FLOAT32_C(   -99.70), SIMDE_FLOAT32_C(   -72.19), SIMDE_FLOAT32_C(   -81.59),
        SIMDE_FLOAT32_C(   -65.37), SIMDE_FLOAT32_C(    56.02), SIMDE_FLOAT32_C(   -40.60), SIMDE_FLOAT32_C(    38.71) },
      { SIMDE_FLOAT32_C(    28.11), SIMDE_FLOAT32_C(   -34.66), SIMDE_FLOAT32_C(    63.29), SIMDE_FLOAT32_C(    98.90),
        SIMDE_FLOAT32_C(    52.67), SIMDE_FLOAT32_C(    39.55), SIMDE_FLOAT32_C(   -83.28), SIMDE_FLOAT32_C(   -32.27),
        SIMDE_FLOAT32_C(    91.98), SIMDE_FLOAT32_C(   -47.07), SIMDE_FLOAT32_C(   -63.52), SIMDE_FLOAT32_C(    98.65),
        SIMDE_FLOAT32_C(    18.09), SIMDE_FLOAT32_C(   -42.18), SIMDE_FLOAT32_C(    40.03), SIMDE_FLOAT32_C(   -76.54) },
      { SIMDE_FLOAT32_C(   -97.10), SIMDE_FLOAT32_C(    75.50), SIMDE_FLOAT32_C(    77.78), SIMDE_FLOAT32_C(    67.71),
        SIMDE_FLOAT32_C(   -14.41), SIMDE_FLOAT32_C(    52.49), SIMDE_FLOAT32_C(    94.43), SIMDE_FLOAT32_C(    35.13),
        SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(   -77.76), SIMDE_FLOAT32_C(    53.54), SIMDE_FLOAT32_C(    87.41),
        SIMDE_FLOAT32_C(    78.26), SIMDE_FLOAT32_C(   -87.05), SIMDE_FLOAT32_C(    26.12), SIMDE_FLOAT32_C(     6.37) },
      { SIMDE_FLOAT32_C(   248.05), SIMDE_FLOAT32_C( -1637.97), SIMDE_FLOAT32_C( -4161.88), SIMDE_FLOAT32_C(  5303.55),
        SIMDE_FLOAT32_C(  3428.48), SIMDE_FLOAT32_C(   346.57), SIMDE_FLOAT32_C( -6316.28), SIMDE_FLOAT32_C(  2329.62),
        SIMDE_FLOAT32_C( -4694.10), SIMDE_FLOAT32_C(  4770.64), SIMDE_FLOAT32_C(  4531.97), SIMDE_FLOAT32_C( -8136.26),
        SIMDE_FLOAT32_C( -1260.80), SIMDE_FLOAT32_C( -2275.87), SIMDE_FLOAT32_C( -1651.34), SIMDE_FLOAT32_C( -2969.23) } },
    { { SIMDE_FLOAT32_C(   -21.71), SIMDE_FLOAT32_C(   -10.59), SIMDE_FLOAT32_C(     5.27), SIMDE_FLOAT32_C(   -69.04),
        SIMDE_FLOAT32_C(   -71.03), SIMDE_FLOAT32_C(    22.00), SIMDE_FLOAT32_C(    -1.31), SIMDE_FLOAT32_C(   -79.05),
        SIMDE_FLOAT32_C(    74.93), SIMDE_FLOAT32_C(    35.16), SIMDE_FLOAT32_C(   -80.40), SIMDE_FLOAT32_C(    -6.98),
        SIMDE_FLOAT32_C(    92.98), SIMDE_FLOAT32_C(    59.62), SIMDE_FLOAT32_C(    16.48), SIMDE_FLOAT32_C(    95.88) },
      { SIMDE_FLOAT32_C(    35.12), SIMDE_FLOAT32_C(    -5.74), SIMDE_FLOAT32_C(    63.59), SIMDE_FLOAT32_C(   -79.29),
        SIMDE_FLOAT32_C(   -53.25), SIMDE_FLOAT32_C(    58.02), SIMDE_FLOAT32_C(    55.85), SIMDE_FLOAT32_C(    99.54),
        SIMDE_FLOAT32_C(    80.26), SIMDE_FLOAT32_C(     9.39), SIMDE_FLOAT32_C(    86.95), SIMDE_FLOAT32_C(    58.52),
        SIMDE_FLOAT32_C(    22.34), SIMDE_FLOAT32_C(    13.07), SIMDE_FLOAT32_C(   -35.11), SIMDE_FLOAT32_C(   -99.37) },
      { SIMDE_FLOAT32_C(   -97.51), SIMDE_FLOAT32_C(    70.17), SIMDE_FLOAT32_C(   -68.42), SIMDE_FLOAT32_C(   -68.55),
        SIMDE_FLOAT32_C(    -7.84), SIMDE_FLOAT32_C(    30.27), SIMDE_FLOAT32_C(   -47.60), SIMDE_FLOAT32_C(   -32.91),
        SIMDE_FLOAT32_C(   -34.57), SIMDE_FLOAT32_C(   -28.00), SIMDE_FLOAT32_C(    60.11), SIMDE_FLOAT32_C(   -41.59),
        SIMDE_FLOAT32_C(   -68.38), SIMDE_FLOAT32_C(   -23.41), SIMDE_FLOAT32_C(   -45.71), SIMDE_FLOAT32_C(    66.75) },
      { SIMDE_FLOAT32_C(  -664.95), SIMDE_FLOAT32_C(    -9.38), SIMDE_FLOAT32_C(   403.54), SIMDE_FLOAT32_C(  5542.73),
        SIMDE_FLOAT32_C(  3790.19), SIMDE_FLOAT32_C(  1246.17), SIMDE_FLOAT32_C(   -25.56), SIMDE_FLOAT32_C( -7835.73),
        SIMDE_FLOAT32_C(  6048.45), SIMDE_FLOAT32_C(   358.15), SIMDE_FLOAT32_C( -7050.89), SIMDE_FLOAT32_C(  -366.88),
        SIMDE_FLOAT32_C(  2145.55), SIMDE_FLOAT32_C(   802.64), SIMDE_FLOAT32_C(  -532.90), SIMDE_FLOAT32_C( -9594.35) } },
    { { SIMDE_FLOAT32_C(    70.85), SIMDE_FLOAT32_C(   -82.11), SIMDE_FLOAT32_C(    87.46), SIMDE_FLOAT32_C(   -82.40),
        SIMDE_FLOAT32_C(    75.91), SIMDE_FLOAT32_C(    43.31), SIMDE_FLOAT32_C(   -82.86), SIMDE_FLOAT32_C(    56.17),
        SIMDE_FLOAT32_C(   -47.30), SIMDE_FLOAT32_C(   -95.91), SIMDE_FLOAT32_C(    14.69), SIMDE_FLOAT32_C(    75.04),
        SIMDE_FLOAT32_C(    17.16), SIMDE_FLOAT32_C(    79.59), SIMDE_FLOAT32_C(    75.66), SIMDE_FLOAT32_C(    19.64) },
      { SIMDE_FLOAT32_C(    49.75), SIMDE_FLOAT32_C(   -92.75), SIMDE_FLOAT32_C(    51.10), SIMDE_FLOAT32_C(   -58.08),
        SIMDE_FLOAT32_C(    37.51), SIMDE_FLOAT32_C(   -96.50), SIMDE_FLOAT32_C(     9.01), SIMDE_FLOAT32_C(   -97.06),
        SIMDE_FLOAT32_C(   -24.50), SIMDE_FLOAT32_C(   -30.88), SIMDE_FLOAT32_C(   -38.64), SIMDE_FLOAT32_C(     7.12),
        SIMDE_FLOAT32_C(    45.71), SIMDE_FLOAT32_C(    15.65), SIMDE_FLOAT32_C(   -26.14), SIMDE_FLOAT32_C(    16.56) },
      { SIMDE_FLOAT32_C(    33.54), SIMDE_FLOAT32_C(   -38.68), SIMDE_FLOAT32_C(    34.16), SIMDE_FLOAT32_C(     9.45),
        SIMDE_FLOAT32_C(   -95.37), SIMDE_FLOAT32_C(    51.30), SIMDE_FLOAT32_C(   -34.38), SIMDE_FLOAT32_C(   -42.67),
        SIMDE_FLOAT32_C(    55.39), SIMDE_FLOAT32_C(    80.31), SIMDE_FLOAT32_C(   -67.64), SIMDE_FLOAT32_C(   -27.46),
        SIMDE_FLOAT32_C(    59.90), SIMDE_FLOAT32_C(   -91.97), SIMDE_FLOAT32_C(    92.19), SIMDE_FLOAT32_C(     9.65) },
      { SIMDE_FLOAT32_C(  3491.25), SIMDE_FLOAT32_C(  7654.38), SIMDE_FLOAT32_C(  4435.05), SIMDE_FLOAT32_C(  4776.34),
        SIMDE_FLOAT32_C(  2942.75), SIMDE_FLOAT32_C( -4230.71), SIMDE_FLOAT32_C(  -712.19), SIMDE_FLOAT32_C( -5409.19),
        SIMDE_FLOAT32_C(  1103.46), SIMDE_FLOAT32_C(  2881.39), SIMDE_FLOAT32_C(  -499.98), SIMDE_FLOAT32_C(   561.74),
        SIMDE_FLOAT32_C(   724.48), SIMDE_FLOAT32_C(  1337.55), SIMDE_FLOAT32_C( -2069.94), SIMDE_FLOAT32_C(   315.59) } },
    { { SIMDE_FLOAT32_C(   -84.73), SIMDE_FLOAT32_C(    43.28), SIMDE_FLOAT32_C(    51.57), SIMDE_FLOAT32_C(    52.79),
        SIMDE_FLOAT32_C(    46.78), SIMDE_FLOAT32_C(   -39.42), SIMDE_FLOAT32_C(    55.73), SIMDE_FLOAT32_C(   -77.72),
        SIMDE_FLOAT32_C(    29.69), SIMDE_FLOAT32_C(   -82.91), SIMDE_FLOAT32_C(    29.40), SIMDE_FLOAT32_C(   -24.60),
        SIMDE_FLOAT32_C(    32.74), SIMDE_FLOAT32_C(   -96.74), SIMDE_FLOAT32_C(    91.96), SIMDE_FLOAT32_C(   -33.72) },
      { SIMDE_FLOAT32_C(   -35.42), SIMDE_FLOAT32_C(    26.13), SIMDE_FLOAT32_C(    75.73), SIMDE_FLOAT32_C(   -30.79),
        SIMDE_FLOAT32_C(   -22.57), SIMDE_FLOAT32_C(   -58.65), SIMDE_FLOAT32_C(    26.54), SIMDE_FLOAT32_C(   -67.19),
        SIMDE_FLOAT32_C(   -78.34), SIMDE_FLOAT32_C(    58.90), SIMDE_FLOAT32_C(     5.36), SIMDE_FLOAT32_C(    81.57),
        SIMDE_FLOAT32_C(    66.92), SIMDE_FLOAT32_C(    -2.46), SIMDE_FLOAT32_C(    -8.78), SIMDE_FLOAT32_C(    82.20) },
      { SIMDE_FLOAT32_C(   -59.17), SIMDE_FLOAT32_C(   -57.21), SIMDE_FLOAT32_C(    34.98), SIMDE_FLOAT32_C(    87.61),
        SIMDE_FLOAT32_C(     3.36), SIMDE_FLOAT32_C(    -9.29), SIMDE_FLOAT32_C(   -90.11), SIMDE_FLOAT32_C(   -66.95),
        SIMDE_FLOAT32_C(     7.80), SIMDE_FLOAT32_C(    39.28), SIMDE_FLOAT32_C(     8.46), SIMDE_FLOAT32_C(   -59.46),
        SIMDE_FLOAT32_C(    42.54), SIMDE_FLOAT32_C(     0.42), SIMDE_FLOAT32_C(     6.82), SIMDE_FLOAT32_C(   -92.87) },
      { SIMDE_FLOAT32_C(  3060.31), SIMDE_FLOAT32_C(  1188.12), SIMDE_FLOAT32_C(  3870.42), SIMDE_FLOAT32_C( -1713.01),
        SIMDE_FLOAT32_C( -1059.18), SIMDE_FLOAT32_C(  2321.27), SIMDE_FLOAT32_C(  1569.18), SIMDE_FLOAT32_C(  5288.96),
        SIMDE_FLOAT32_C( -2333.71), SIMDE_FLOAT32_C( -4922.68), SIMDE_FLOAT32_C(   149.12), SIMDE_FLOAT32_C( -1947.16),
        SIMDE_FLOAT32_C(  2148.42), SIMDE_FLOAT32_C(   237.56), SIMDE_FLOAT32_C(  -814.23), SIMDE_FLOAT32_C( -2678.91) } },
    { { SIMDE_FLOAT32_C(   -73.46), SIMDE_FLOAT32_C(   -17.45), SIMDE_FLOAT32_C(   -23.66), SIMDE_FLOAT32_C(     3.97),
        SIMDE_FLOAT32_C(    23.90), SIMDE_FLOAT32_C(   -97.13), SIMDE_FLOAT32_C(    36.78), SIMDE_FLOAT32_C(    45.56),
        SIMDE_FLOAT32_C(    61.77), SIMDE_FLOAT32_C(   -57.86), SIMDE_FLOAT32_C(    27.13), SIMDE_FLOAT32_C(    28.69),
        SIMDE_FLOAT32_C(    39.68), SIMDE_FLOAT32_C(   -81.65), SIMDE_FLOAT32_C(    10.89), SIMDE_FLOAT32_C(    80.51) },
      { SIMDE_FLOAT32_C(   -38.86), SIMDE_FLOAT32_C(   -54.13), SIMDE_FLOAT32_C(    68.12), SIMDE_FLOAT32_C(    64.50),
        SIMDE_FLOAT32_C(    36.58), SIMDE_FLOAT32_C(    78.01), SIMDE_FLOAT32_C(    97.56), SIMDE_FLOAT32_C(   -55.62),
        SIMDE_FLOAT32_C(    17.29), SIMDE_FLOAT32_C(     6.01), SIMDE_FLOAT32_C(   -15.08), SIMDE_FLOAT32_C(   -40.17),
        SIMDE_FLOAT32_C(   -93.57), SIMDE_FLOAT32_C(    91.74), SIMDE_FLOAT32_C(   -33.04), SIMDE_FLOAT32_C(   -67.03) },
      { SIMDE_FLOAT32_C(   -25.71), SIMDE_FLOAT32_C(    43.29), SIMDE_FLOAT32_C(    36.94), SIMDE_FLOAT32_C(    98.19),
        SIMDE_FLOAT32_C(    46.17), SIMDE_FLOAT32_C(   -26.28), SIMDE_FLOAT32_C(    43.76), SIMDE_FLOAT32_C(     7.94),
        SIMDE_FLOAT32_C(    15.86), SIMDE_FLOAT32_C(   -29.11), SIMDE_FLOAT32_C(   -63.37), SIMDE_FLOAT32_C(   -44.46),
        SIMDE_FLOAT32_C(   -10.77), SIMDE_FLOAT32_C(    47.52), SIMDE_FLOAT32_C(   -63.95), SIMDE_FLOAT32_C(    50.37) },
      { SIMDE_FLOAT32_C(  2880.37), SIMDE_FLOAT32_C(   901.28), SIMDE_FLOAT32_C( -1648.66), SIMDE_FLOAT32_C(   157.88),
        SIMDE_FLOAT32_C(   828.09), SIMDE_FLOAT32_C( -7550.83), SIMDE_FLOAT32_C(  3544.50), SIMDE_FLOAT32_C( -2541.99),
        SIMDE_FLOAT32_C(  1052.14), SIMDE_FLOAT32_C(  -318.63), SIMDE_FLOAT32_C(  -345.75), SIMDE_FLOAT32_C( -1108.02),
        SIMDE_FLOAT32_C( -3702.09), SIMDE_FLOAT32_C( -7538.09), SIMDE_FLOAT32_C(  -295.86), SIMDE_FLOAT32_C( -5446.96) } },
    { { SIMDE_FLOAT32_C(    93.39), SIMDE_FLOAT32_C(   -95.84), SIMDE_FLOAT32_C(    14.87), SIMDE_FLOAT32_C(    29.97),
        SIMDE_FLOAT32_C(    82.17), SIMDE_FLOAT32_C(    12.43), SIMDE_FLOAT32_C(    74.35), SIMDE_FLOAT32_C(    -0.54),
        SIMDE_FLOAT32_C(   -81.56), SIMDE_FLOAT32_C(   -40.72), SIMDE_FLOAT32_C(    59.29), SIMDE_FLOAT32_C(   -75.13),
        SIMDE_FLOAT32_C(   -48.98), SIMDE_FLOAT32_C(   -73.75), SIMDE_FLOAT32_C(   -42.16), SIMDE_FLOAT32_C(    25.31) },
      { SIMDE_FLOAT32_C(    69.55), SIMDE_FLOAT32_C(    94.78), SIMDE_FLOAT32_C(    23.51), SIMDE_FLOAT32_C(    15.71),
        SIMDE_FLOAT32_C(   -31.49), SIMDE_FLOAT32_C(   -32.74), SIMDE_FLOAT32_C(   -76.35), SIMDE_FLOAT32_C(    84.37),
        SIMDE_FLOAT32_C(    38.15), SIMDE_FLOAT32_C(   -39.72), SIMDE_FLOAT32_C(   -60.09), SIMDE_FLOAT32_C(   -72.62),
        SIMDE_FLOAT32_C(   -92.20), SIMDE_FLOAT32_C(   -24.04), SIMDE_FLOAT32_C(    77.76), SIMDE_FLOAT32_C(   -98.81) },
      { SIMDE_FLOAT32_C(   -19.88), SIMDE_FLOAT32_C(    -7.37), SIMDE_FLOAT32_C(    31.16), SIMDE_FLOAT32_C(   -37.71),
        SIMDE_FLOAT32_C(   -94.94), SIMDE_FLOAT32_C(     5.51), SIMDE_FLOAT32_C(    61.75), SIMDE_FLOAT32_C(   -76.50),
        SIMDE_FLOAT32_C(    64.79), SIMDE_FLOAT32_C(    21.04), SIMDE_FLOAT32_C(   -51.63), SIMDE_FLOAT32_C(   -84.19),
        SIMDE_FLOAT32_C(    47.29), SIMDE_FLOAT32_C(     6.21), SIMDE_FLOAT32_C(    41.12), SIMDE_FLOAT32_C(    16.84) },
      { SIMDE_FLOAT32_C(  6515.15), SIMDE_FLOAT32_C( -9076.34), SIMDE_FLOAT32_C(   318.43), SIMDE_FLOAT32_C(   508.54),
        SIMDE_FLOAT32_C( -2492.59), SIMDE_FLOAT32_C(  -412.47), SIMDE_FLOAT32_C( -5738.37), SIMDE_FLOAT32_C(    30.94),
        SIMDE_FLOAT32_C( -3176.30), SIMDE_FLOAT32_C(  1596.36), SIMDE_FLOAT32_C( -3511.11), SIMDE_FLOAT32_C(  5540.13),
        SIMDE_FLOAT32_C(  4468.67), SIMDE_FLOAT32_C(  1766.74), SIMDE_FLOAT32_C( -3319.48), SIMDE_FLOAT32_C( -2517.72) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 c = simde_mm512_loadu_ps(test_vec[i].c);
    simde__m512 r = simde_mm512_fmsub_ps(a, b, c);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_fmsub_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 c[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -46.12), SIMDE_FLOAT64_C(   -61.46), SIMDE_FLOAT64_C(    12.22), SIMDE_FLOAT64_C(   -13.13),
        SIMDE_FLOAT64_C(    17.13), SIMDE_FLOAT64_C(    34.93), SIMDE_FLOAT64_C(    51.88), SIMDE_FLOAT64_C(    19.93) },
      { SIMDE_FLOAT64_C(    73.17), SIMDE_FLOAT64_C(   -90.86), SIMDE_FLOAT64_C(   -64.69), SIMDE_FLOAT64_C(    30.40),
        SIMDE_FLOAT64_C(   -78.85), SIMDE_FLOAT64_C(    -2.23), SIMDE_FLOAT64_C(    38.81), SIMDE_FLOAT64_C(   -25.38) },
      { SIMDE_FLOAT64_C(     6.25), SIMDE_FLOAT64_C(   -22.61), SIMDE_FLOAT64_C(     8.61), SIMDE_FLOAT64_C(   -27.29),
        SIMDE_FLOAT64_C(   -33.10), SIMDE_FLOAT64_C(    99.80), SIMDE_FLOAT64_C(   -95.28), SIMDE_FLOAT64_C(    59.13) },
      { SIMDE_FLOAT64_C( -3380.85), SIMDE_FLOAT64_C(  5606.87), SIMDE_FLOAT64_C(  -799.12), SIMDE_FLOAT64_C(  -371.86),
        SIMDE_FLOAT64_C( -1317.60), SIMDE_FLOAT64_C(  -177.69), SIMDE_FLOAT64_C(  2108.74), SIMDE_FLOAT64_C(  -564.95) } },
    { { SIMDE_FLOAT64_C(    28.50), SIMDE_FLOAT64_C(   -32.67), SIMDE_FLOAT64_C(   -95.72), SIMDE_FLOAT64_C(    21.20),
        SIMDE_FLOAT64_C(    40.97), SIMDE_FLOAT64_C(   -90.91), SIMDE_FLOAT64_C(    40.73), SIMDE_FLOAT64_C(    94.85) },
      { SIMDE_FLOAT64_C(   -52.37), SIMDE_FLOAT64_C(   -47.05), SIMDE_FLOAT64_C(   -18.28), SIMDE_FLOAT64_C(    64.76),
        SIMDE_FLOAT64_C(    87.88), SIMDE_FLOAT64_C(   -66.39), SIMDE_FLOAT64_C(   -15.31), SIMDE_FLOAT64_C(    61.05) },
      { SIMDE_FLOAT64_C(   -57.26), SIMDE_FLOAT64_C(    19.99), SIMDE_FLOAT64_C(    -8.55), SIMDE_FLOAT64_C(   -36.11),
        SIMDE_FLOAT64_C(   -82.23), SIMDE_FLOAT64_C(   -69.73), SIMDE_FLOAT64_C(    38.51), SIMDE_FLOAT64_C(    24.02) },
      { SIMDE_FLOAT64_C( -1435.28), SIMDE_FLOAT64_C(  1517.13), SIMDE_FLOAT64_C(  1758.31), SIMDE_FLOAT64_C(  1409.02),
        SIMDE_FLOAT64_C(  3682.67), SIMDE_FLOAT64_C(  6105.24), SIMDE_FLOAT64_C(  -662.09), SIMDE_FLOAT64_C(  5766.57) } },
    { { SIMDE_FLOAT64_C(     7.65), SIMDE_FLOAT64_C(   -52.88), SIMDE_FLOAT64_C(    96.73), SIMDE_FLOAT64_C(    74.56),
        SIMDE_FLOAT64_C(   -53.08), SIMDE_FLOAT64_C(   -98.55), SIMDE_FLOAT64_C(    33.69), SIMDE_FLOAT64_C(    75.41) },
      { SIMDE_FLOAT64_C(   -31.22), SIMDE_FLOAT64_C(    37.96), SIMDE_FLOAT64_C(    -3.39), SIMDE_FLOAT64_C(   -90.25),
        SIMDE_FLOAT64_C(    47.06), SIMDE_FLOAT64_C(   -62.65), SIMDE_FLOAT64_C(   -95.40), SIMDE_FLOAT64_C(    94.69) },
      { SIMDE_FLOAT64_C(    -9.70), SIMDE_FLOAT64_C(   -13.67), SIMDE_FLOAT64_C(    59.45), SIMDE_FLOAT64_C(   -21.82),
        SIMDE_FLOAT64_C(    19.93), SIMDE_FLOAT64_C(   -55.86), SIMDE_FLOAT64_C(   -60.77), SIMDE_FLOAT64_C(    62.67) },
      { SIMDE_FLOAT64_C(  -229.13), SIMDE_FLOAT64_C( -1993.65), SIMDE_FLOAT64_C(  -387.36), SIMDE_FLOAT64_C( -6707.22),
        SIMDE_FLOAT64_C( -2517.87), SIMDE_FLOAT64_C(  6230.02), SIMDE_FLOAT64_C( -3153.26), SIMDE_FLOAT64_C(  7077.90) } },
    { { SIMDE_FLOAT64_C(    64.13), SIMDE_FLOAT64_C(    30.68), SIMDE_FLOAT64_C(   -73.44), SIMDE_FLOAT64_C(    81.90),
        SIMDE_FLOAT64_C(    60.95), SIMDE_FLOAT64_C(    65.08), SIMDE_FLOAT64_C(     5.91), SIMDE_FLOAT64_C(   -31.40) },
      { SIMDE_FLOAT64_C(   -87.81), SIMDE_FLOAT64_C(     2.64), SIMDE_FLOAT64_C(   -56.84), SIMDE_FLOAT64_C(   -40.89),
        SIMDE_FLOAT64_C(     4.09), SIMDE_FLOAT64_C(    76.84), SIMDE_FLOAT64_C(   -65.48), SIMDE_FLOAT64_C(    72.87) },
      { SIMDE_FLOAT64_C(    14.81), SIMDE_FLOAT64_C(    31.14), SIMDE_FLOAT64_C(    82.62), SIMDE_FLOAT64_C(   -38.13),
        SIMDE_FLOAT64_C(    68.49), SIMDE_FLOAT64_C(    87.23), SIMDE_FLOAT64_C(   -43.44), SIMDE_FLOAT64_C(   -41.22) },
      { SIMDE_FLOAT64_C( -5646.07), SIMDE_FLOAT64_C(    49.86), SIMDE_FLOAT64_C(  4091.71), SIMDE_FLOAT64_C( -3310.76),
        SIMDE_FLOAT64_C(   180.80), SIMDE_FLOAT64_C(  4913.52), SIMDE_FLOAT64_C(  -343.55), SIMDE_FLOAT64_C( -2246.90) } },
    { { SIMDE_FLOAT64_C(   -26.44), SIMDE_FLOAT64_C(   -83.99), SIMDE_FLOAT64_C(    36.96), SIMDE_FLOAT64_C(    93.49),
        SIMDE_FLOAT64_C(   -39.85), SIMDE_FLOAT64_C(    76.19), SIMDE_FLOAT64_C(    56.16), SIMDE_FLOAT64_C(   -75.72) },
      { SIMDE_FLOAT64_C(     6.87), SIMDE_FLOAT64_C(    82.72), SIMDE_FLOAT64_C(   -93.82), SIMDE_FLOAT64_C(   -32.18),
        SIMDE_FLOAT64_C(    47.80), SIMDE_FLOAT64_C(    12.09), SIMDE_FLOAT64_C(    36.42), SIMDE_FLOAT64_C(    59.99) },
      { SIMDE_FLOAT64_C(   -85.27), SIMDE_FLOAT64_C(    79.58), SIMDE_FLOAT64_C(   -80.90), SIMDE_FLOAT64_C(    18.82),
        SIMDE_FLOAT64_C(    56.42), SIMDE_FLOAT64_C(   -46.38), SIMDE_FLOAT64_C(    -8.31), SIMDE_FLOAT64_C(   -28.77) },
      { SIMDE_FLOAT64_C(   -96.37), SIMDE_FLOAT64_C( -7027.23), SIMDE_FLOAT64_C( -3386.69), SIMDE_FLOAT64_C( -3027.33),
        SIMDE_FLOAT64_C( -1961.25), SIMDE_FLOAT64_C(   967.52), SIMDE_FLOAT64_C(  2053.66), SIMDE_FLOAT64_C( -4513.67) } },
    { { SIMDE_FLOAT64_C(    84.76), SIMDE_FLOAT64_C(   -25.68), SIMDE_FLOAT64_C(    33.09), SIMDE_FLOAT64_C(    53.25),
        SIMDE_FLOAT64_C(   -38.45), SIMDE_FLOAT64_C(    89.65), SIMDE_FLOAT64_C(   -87.97), SIMDE_FLOAT64_C(    35.10) },
      { SIMDE_FLOAT64_C(   -94.34), SIMDE_FLOAT64_C(    48.99), SIMDE_FLOAT64_C(    28.59), SIMDE_FLOAT64_C(   -34.19),
        SIMDE_FLOAT64_C(    25.18), SIMDE_FLOAT64_C(   -15.25), SIMDE_FLOAT64_C(    -9.91), SIMDE_FLOAT64_C(   -67.95) },
      { SIMDE_FLOAT64_C(   -32.53), SIMDE_FLOAT64_C(    -3.73), SIMDE_FLOAT64_C(    -0.13), SIMDE_FLOAT64_C(   -84.73),
        SIMDE_FLOAT64_C(   -91.64), SIMDE_FLOAT64_C(   -63.71), SIMDE_FLOAT64_C(    75.26), SIMDE_FLOAT64_C(   -76.91) },
      { SIMDE_FLOAT64_C( -7963.73), SIMDE_FLOAT64_C( -1254.33), SIMDE_FLOAT64_C(   946.17), SIMDE_FLOAT64_C( -1735.89),
        SIMDE_FLOAT64_C(  -876.53), SIMDE_FLOAT64_C( -1303.45), SIMDE_FLOAT64_C(   796.52), SIMDE_FLOAT64_C( -2308.14) } },
    { { SIMDE_FLOAT64_C(   -84.14), SIMDE_FLOAT64_C(    94.36), SIMDE_FLOAT64_C(    41.92), SIMDE_FLOAT64_C(    72.28),
        SIMDE_FLOAT64_C(   -52.01), SIMDE_FLOAT64_C(   -66.39), SIMDE_FLOAT64_C(   -56.49), SIMDE_FLOAT64_C(   -67.25) },
      { SIMDE_FLOAT64_C(     7.93), SIMDE_FLOAT64_C(    76.60), SIMDE_FLOAT64_C(    85.99), SIMDE_FLOAT64_C(    69.48),
        SIMDE_FLOAT64_C(    66.25), SIMDE_FLOAT64_C(    98.03), SIMDE_FLOAT64_C(     4.58), SIMDE_FLOAT64_C(    71.92) },
      { SIMDE_FLOAT64_C(    47.02), SIMDE_FLOAT64_C(   -66.83), SIMDE_FLOAT64_C(   -62.27), SIMDE_FLOAT64_C(   -27.80),
        SIMDE_FLOAT64_C(    17.92), SIMDE_FLOAT64_C(    27.82), SIMDE_FLOAT64_C(     4.25), SIMDE_FLOAT64_C(    85.39) },
      { SIMDE_FLOAT64_C(  -714.25), SIMDE_FLOAT64_C(  7294.81), SIMDE_FLOAT64_C(  3666.97), SIMDE_FLOAT64_C(  5049.81),
        SIMDE_FLOAT64_C( -3463.58), SIMDE_FLOAT64_C( -6536.03), SIMDE_FLOAT64_C(  -262.97), SIMDE_FLOAT64_C( -4922.01) } },
    { { SIMDE_FLOAT64_C(   -75.91), SIMDE_FLOAT64_C(   -95.88), SIMDE_FLOAT64_C(   -99.34), SIMDE_FLOAT64_C(   -67.54),
        SIMDE_FLOAT64_C(   -59.59), SIMDE_FLOAT64_C(    75.92), SIMDE_FLOAT64_C(   -44.45), SIMDE_FLOAT64_C(   -43.72) },
      { SIMDE_FLOAT64_C(    70.29), SIMDE_FLOAT64_C(    97.47), SIMDE_FLOAT64_C(   -71.44), SIMDE_FLOAT64_C(   -81.73),
        SIMDE_FLOAT64_C(   -68.92), SIMDE_FLOAT64_C(   -27.93), SIMDE_FLOAT64_C(   -48.98), SIMDE_FLOAT64_C(    39.01) },
      { SIMDE_FLOAT64_C(   -51.32), SIMDE_FLOAT64_C(   -62.98), SIMDE_FLOAT64_C(     8.48), SIMDE_FLOAT64_C(   -85.07),
        SIMDE_FLOAT64_C(   -64.96), SIMDE_FLOAT64_C(   -86.94), SIMDE_FLOAT64_C(    86.85), SIMDE_FLOAT64_C(    82.06) },
      { SIMDE_FLOAT64_C( -5284.39), SIMDE_FLOAT64_C( -9282.44), SIMDE_FLOAT64_C(  7088.37), SIMDE_FLOAT64_C(  5605.11),
        SIMDE_FLOAT64_C(  4171.90), SIMDE_FLOAT64_C( -2033.51), SIMDE_FLOAT64_C(  2090.31), SIMDE_FLOAT64_C( -1787.58) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d c = simde_mm512_loadu_pd(test_vec[i].c);
    simde__m512d r = simde_mm512_fmsub_pd(a, b, c);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fmsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fmsub_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
