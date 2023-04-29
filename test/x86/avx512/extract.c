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
 *   2020      Christopher Moore <moore@free.fr>
 */

#define SIMDE_TEST_X86_AVX512_INSN extract

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/extract.h>

static int
test_simde_mm512_extractf32x4_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512 a;
    simde__m128 r0;
    simde__m128 r1;
    simde__m128 r2;
    simde__m128 r3;
  } test_vec[8] = {
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -563.83), SIMDE_FLOAT32_C(   799.30), SIMDE_FLOAT32_C(   938.85), SIMDE_FLOAT32_C(  -576.01),
                         SIMDE_FLOAT32_C(  -465.05), SIMDE_FLOAT32_C(   439.15), SIMDE_FLOAT32_C(  -104.57), SIMDE_FLOAT32_C(   -28.15),
                         SIMDE_FLOAT32_C(  -431.26), SIMDE_FLOAT32_C(   481.25), SIMDE_FLOAT32_C(   -57.75), SIMDE_FLOAT32_C(  -784.26),
                         SIMDE_FLOAT32_C(   438.04), SIMDE_FLOAT32_C(   549.03), SIMDE_FLOAT32_C(   729.46), SIMDE_FLOAT32_C(   582.53)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   438.04), SIMDE_FLOAT32_C(   549.03), SIMDE_FLOAT32_C(   729.46), SIMDE_FLOAT32_C(   582.53)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -431.26), SIMDE_FLOAT32_C(   481.25), SIMDE_FLOAT32_C(   -57.75), SIMDE_FLOAT32_C(  -784.26)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -465.05), SIMDE_FLOAT32_C(   439.15), SIMDE_FLOAT32_C(  -104.57), SIMDE_FLOAT32_C(   -28.15)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -563.83), SIMDE_FLOAT32_C(   799.30), SIMDE_FLOAT32_C(   938.85), SIMDE_FLOAT32_C(  -576.01)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   120.10), SIMDE_FLOAT32_C(   -64.06), SIMDE_FLOAT32_C(  -620.03), SIMDE_FLOAT32_C(   559.81),
                         SIMDE_FLOAT32_C(   185.23), SIMDE_FLOAT32_C(  -423.61), SIMDE_FLOAT32_C(   -11.91), SIMDE_FLOAT32_C(   407.56),
                         SIMDE_FLOAT32_C(   355.11), SIMDE_FLOAT32_C(  -787.72), SIMDE_FLOAT32_C(   472.82), SIMDE_FLOAT32_C(  -703.51),
                         SIMDE_FLOAT32_C(  -202.49), SIMDE_FLOAT32_C(  -470.36), SIMDE_FLOAT32_C(   966.37), SIMDE_FLOAT32_C(   135.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -202.49), SIMDE_FLOAT32_C(  -470.36), SIMDE_FLOAT32_C(   966.37), SIMDE_FLOAT32_C(   135.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   355.11), SIMDE_FLOAT32_C(  -787.72), SIMDE_FLOAT32_C(   472.82), SIMDE_FLOAT32_C(  -703.51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   185.23), SIMDE_FLOAT32_C(  -423.61), SIMDE_FLOAT32_C(   -11.91), SIMDE_FLOAT32_C(   407.56)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   120.10), SIMDE_FLOAT32_C(   -64.06), SIMDE_FLOAT32_C(  -620.03), SIMDE_FLOAT32_C(   559.81)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   193.01), SIMDE_FLOAT32_C(  -435.27), SIMDE_FLOAT32_C(   -84.06), SIMDE_FLOAT32_C(   298.40),
                         SIMDE_FLOAT32_C(   208.07), SIMDE_FLOAT32_C(   -94.60), SIMDE_FLOAT32_C(   834.28), SIMDE_FLOAT32_C(   260.50),
                         SIMDE_FLOAT32_C(  -859.51), SIMDE_FLOAT32_C(   -69.45), SIMDE_FLOAT32_C(    40.36), SIMDE_FLOAT32_C(    95.61),
                         SIMDE_FLOAT32_C(  -743.10), SIMDE_FLOAT32_C(  -688.01), SIMDE_FLOAT32_C(   442.76), SIMDE_FLOAT32_C(   931.17)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -743.10), SIMDE_FLOAT32_C(  -688.01), SIMDE_FLOAT32_C(   442.76), SIMDE_FLOAT32_C(   931.17)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -859.51), SIMDE_FLOAT32_C(   -69.45), SIMDE_FLOAT32_C(    40.36), SIMDE_FLOAT32_C(    95.61)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   208.07), SIMDE_FLOAT32_C(   -94.60), SIMDE_FLOAT32_C(   834.28), SIMDE_FLOAT32_C(   260.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   193.01), SIMDE_FLOAT32_C(  -435.27), SIMDE_FLOAT32_C(   -84.06), SIMDE_FLOAT32_C(   298.40)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   664.52), SIMDE_FLOAT32_C(  -224.13), SIMDE_FLOAT32_C(   633.65), SIMDE_FLOAT32_C(  -834.15),
                         SIMDE_FLOAT32_C(  -157.33), SIMDE_FLOAT32_C(  -819.46), SIMDE_FLOAT32_C(   541.44), SIMDE_FLOAT32_C(   112.81),
                         SIMDE_FLOAT32_C(   -98.08), SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(   711.12), SIMDE_FLOAT32_C(   282.83),
                         SIMDE_FLOAT32_C(  -774.08), SIMDE_FLOAT32_C(   841.24), SIMDE_FLOAT32_C(  -414.07), SIMDE_FLOAT32_C(    79.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -774.08), SIMDE_FLOAT32_C(   841.24), SIMDE_FLOAT32_C(  -414.07), SIMDE_FLOAT32_C(    79.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -98.08), SIMDE_FLOAT32_C(   464.19), SIMDE_FLOAT32_C(   711.12), SIMDE_FLOAT32_C(   282.83)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -157.33), SIMDE_FLOAT32_C(  -819.46), SIMDE_FLOAT32_C(   541.44), SIMDE_FLOAT32_C(   112.81)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   664.52), SIMDE_FLOAT32_C(  -224.13), SIMDE_FLOAT32_C(   633.65), SIMDE_FLOAT32_C(  -834.15)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   141.08), SIMDE_FLOAT32_C(  -832.50), SIMDE_FLOAT32_C(  -990.15), SIMDE_FLOAT32_C(   438.46),
                         SIMDE_FLOAT32_C(  -887.47), SIMDE_FLOAT32_C(   336.35), SIMDE_FLOAT32_C(  -396.24), SIMDE_FLOAT32_C(    99.21),
                         SIMDE_FLOAT32_C(    -2.60), SIMDE_FLOAT32_C(   -38.88), SIMDE_FLOAT32_C(   165.88), SIMDE_FLOAT32_C(   218.73),
                         SIMDE_FLOAT32_C(   375.27), SIMDE_FLOAT32_C(  -966.90), SIMDE_FLOAT32_C(  -512.98), SIMDE_FLOAT32_C(  -737.78)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   375.27), SIMDE_FLOAT32_C(  -966.90), SIMDE_FLOAT32_C(  -512.98), SIMDE_FLOAT32_C(  -737.78)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    -2.60), SIMDE_FLOAT32_C(   -38.88), SIMDE_FLOAT32_C(   165.88), SIMDE_FLOAT32_C(   218.73)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -887.47), SIMDE_FLOAT32_C(   336.35), SIMDE_FLOAT32_C(  -396.24), SIMDE_FLOAT32_C(    99.21)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   141.08), SIMDE_FLOAT32_C(  -832.50), SIMDE_FLOAT32_C(  -990.15), SIMDE_FLOAT32_C(   438.46)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -179.98), SIMDE_FLOAT32_C(   258.23), SIMDE_FLOAT32_C(   246.22), SIMDE_FLOAT32_C(    97.85),
                         SIMDE_FLOAT32_C(   666.32), SIMDE_FLOAT32_C(   364.80), SIMDE_FLOAT32_C(   759.27), SIMDE_FLOAT32_C(  -524.19),
                         SIMDE_FLOAT32_C(  -726.51), SIMDE_FLOAT32_C(   381.71), SIMDE_FLOAT32_C(   819.12), SIMDE_FLOAT32_C(   145.28),
                         SIMDE_FLOAT32_C(   -99.37), SIMDE_FLOAT32_C(  -151.02), SIMDE_FLOAT32_C(   551.65), SIMDE_FLOAT32_C(   155.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -99.37), SIMDE_FLOAT32_C(  -151.02), SIMDE_FLOAT32_C(   551.65), SIMDE_FLOAT32_C(   155.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -726.51), SIMDE_FLOAT32_C(   381.71), SIMDE_FLOAT32_C(   819.12), SIMDE_FLOAT32_C(   145.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   666.32), SIMDE_FLOAT32_C(   364.80), SIMDE_FLOAT32_C(   759.27), SIMDE_FLOAT32_C(  -524.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -179.98), SIMDE_FLOAT32_C(   258.23), SIMDE_FLOAT32_C(   246.22), SIMDE_FLOAT32_C(    97.85)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(   254.48), SIMDE_FLOAT32_C(  -211.73), SIMDE_FLOAT32_C(   755.70), SIMDE_FLOAT32_C(   908.31),
                         SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(  -144.11), SIMDE_FLOAT32_C(   789.10), SIMDE_FLOAT32_C(  -343.92),
                         SIMDE_FLOAT32_C(   344.74), SIMDE_FLOAT32_C(   961.65), SIMDE_FLOAT32_C(   652.93), SIMDE_FLOAT32_C(   754.42),
                         SIMDE_FLOAT32_C(   184.91), SIMDE_FLOAT32_C(  -432.97), SIMDE_FLOAT32_C(  -455.33), SIMDE_FLOAT32_C(   164.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   184.91), SIMDE_FLOAT32_C(  -432.97), SIMDE_FLOAT32_C(  -455.33), SIMDE_FLOAT32_C(   164.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   344.74), SIMDE_FLOAT32_C(   961.65), SIMDE_FLOAT32_C(   652.93), SIMDE_FLOAT32_C(   754.42)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(  -144.11), SIMDE_FLOAT32_C(   789.10), SIMDE_FLOAT32_C(  -343.92)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   254.48), SIMDE_FLOAT32_C(  -211.73), SIMDE_FLOAT32_C(   755.70), SIMDE_FLOAT32_C(   908.31)) },
    { simde_mm512_set_ps(SIMDE_FLOAT32_C(  -985.32), SIMDE_FLOAT32_C(   485.76), SIMDE_FLOAT32_C(   234.60), SIMDE_FLOAT32_C(   786.03),
                         SIMDE_FLOAT32_C(   859.59), SIMDE_FLOAT32_C(   489.95), SIMDE_FLOAT32_C(  -409.35), SIMDE_FLOAT32_C(   796.52),
                         SIMDE_FLOAT32_C(  -846.10), SIMDE_FLOAT32_C(  -248.07), SIMDE_FLOAT32_C(  -411.92), SIMDE_FLOAT32_C(   -88.91),
                         SIMDE_FLOAT32_C(   481.68), SIMDE_FLOAT32_C(   170.00), SIMDE_FLOAT32_C(  -341.91), SIMDE_FLOAT32_C(   366.57)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   481.68), SIMDE_FLOAT32_C(   170.00), SIMDE_FLOAT32_C(  -341.91), SIMDE_FLOAT32_C(   366.57)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -846.10), SIMDE_FLOAT32_C(  -248.07), SIMDE_FLOAT32_C(  -411.92), SIMDE_FLOAT32_C(   -88.91)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   859.59), SIMDE_FLOAT32_C(   489.95), SIMDE_FLOAT32_C(  -409.35), SIMDE_FLOAT32_C(   796.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -985.32), SIMDE_FLOAT32_C(   485.76), SIMDE_FLOAT32_C(   234.60), SIMDE_FLOAT32_C(   786.03)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r;
    r = simde_mm512_extractf32x4_ps(test_vec[i].a, 0);
    simde_assert_m128_close(r, test_vec[i].r0, 1);
    r = simde_mm512_extractf32x4_ps(test_vec[i].a, 1);
    simde_assert_m128_close(r, test_vec[i].r1, 1);
    r = simde_mm512_extractf32x4_ps(test_vec[i].a, 2);
    simde_assert_m128_close(r, test_vec[i].r2, 1);
    r = simde_mm512_extractf32x4_ps(test_vec[i].a, 3);
    simde_assert_m128_close(r, test_vec[i].r3, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_extractf32x4_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 src;
    simde__mmask8 k;
    simde__m512 a;
    simde__m128 r0;
    simde__m128 r1;
    simde__m128 r2;
    simde__m128 r3;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -172.36), SIMDE_FLOAT32_C(   393.53), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(  -135.52)),
      UINT8_C( 25),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   903.50), SIMDE_FLOAT32_C(   -43.35), SIMDE_FLOAT32_C(   309.91), SIMDE_FLOAT32_C(   846.15),
                         SIMDE_FLOAT32_C(  -514.56), SIMDE_FLOAT32_C(  -860.98), SIMDE_FLOAT32_C(  -280.30), SIMDE_FLOAT32_C(   128.51),
                         SIMDE_FLOAT32_C(   522.06), SIMDE_FLOAT32_C(  -932.28), SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(  -491.12),
                         SIMDE_FLOAT32_C(  -139.11), SIMDE_FLOAT32_C(  -268.86), SIMDE_FLOAT32_C(   -71.72), SIMDE_FLOAT32_C(    98.47)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -139.11), SIMDE_FLOAT32_C(   393.53), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(    98.47)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   522.06), SIMDE_FLOAT32_C(   393.53), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(  -491.12)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -514.56), SIMDE_FLOAT32_C(   393.53), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(   128.51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   903.50), SIMDE_FLOAT32_C(   393.53), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(   846.15)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -895.71), SIMDE_FLOAT32_C(  -736.92), SIMDE_FLOAT32_C(   283.06), SIMDE_FLOAT32_C(  -333.94)),
      UINT8_C( 61),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   337.35), SIMDE_FLOAT32_C(  -278.32), SIMDE_FLOAT32_C(  -744.41), SIMDE_FLOAT32_C(    39.32),
                         SIMDE_FLOAT32_C(    29.68), SIMDE_FLOAT32_C(  -490.28), SIMDE_FLOAT32_C(   841.53), SIMDE_FLOAT32_C(   526.21),
                         SIMDE_FLOAT32_C(  -203.04), SIMDE_FLOAT32_C(   -80.71), SIMDE_FLOAT32_C(   632.01), SIMDE_FLOAT32_C(   456.89),
                         SIMDE_FLOAT32_C(    51.33), SIMDE_FLOAT32_C(  -868.59), SIMDE_FLOAT32_C(  -921.00), SIMDE_FLOAT32_C(  -471.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    51.33), SIMDE_FLOAT32_C(  -868.59), SIMDE_FLOAT32_C(   283.06), SIMDE_FLOAT32_C(  -471.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -203.04), SIMDE_FLOAT32_C(   -80.71), SIMDE_FLOAT32_C(   283.06), SIMDE_FLOAT32_C(   456.89)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    29.68), SIMDE_FLOAT32_C(  -490.28), SIMDE_FLOAT32_C(   283.06), SIMDE_FLOAT32_C(   526.21)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   337.35), SIMDE_FLOAT32_C(  -278.32), SIMDE_FLOAT32_C(   283.06), SIMDE_FLOAT32_C(    39.32)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(  -934.92), SIMDE_FLOAT32_C(  -657.02), SIMDE_FLOAT32_C(  -629.37)),
      UINT8_C(214),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -207.87), SIMDE_FLOAT32_C(  -765.42), SIMDE_FLOAT32_C(   138.83), SIMDE_FLOAT32_C(   699.07),
                         SIMDE_FLOAT32_C(  -143.73), SIMDE_FLOAT32_C(   709.96), SIMDE_FLOAT32_C(  -767.34), SIMDE_FLOAT32_C(  -588.28),
                         SIMDE_FLOAT32_C(   586.29), SIMDE_FLOAT32_C(  -760.88), SIMDE_FLOAT32_C(  -617.12), SIMDE_FLOAT32_C(  -751.58),
                         SIMDE_FLOAT32_C(   907.23), SIMDE_FLOAT32_C(  -359.60), SIMDE_FLOAT32_C(  -213.75), SIMDE_FLOAT32_C(   403.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(  -359.60), SIMDE_FLOAT32_C(  -213.75), SIMDE_FLOAT32_C(  -629.37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(  -760.88), SIMDE_FLOAT32_C(  -617.12), SIMDE_FLOAT32_C(  -629.37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(   709.96), SIMDE_FLOAT32_C(  -767.34), SIMDE_FLOAT32_C(  -629.37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   957.37), SIMDE_FLOAT32_C(  -765.42), SIMDE_FLOAT32_C(   138.83), SIMDE_FLOAT32_C(  -629.37)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(  -820.22), SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   268.99)),
      UINT8_C(196),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -659.70), SIMDE_FLOAT32_C(   493.30), SIMDE_FLOAT32_C(   831.29), SIMDE_FLOAT32_C(  -619.50),
                         SIMDE_FLOAT32_C(   952.47), SIMDE_FLOAT32_C(  -492.61), SIMDE_FLOAT32_C(   -68.16), SIMDE_FLOAT32_C(   717.69),
                         SIMDE_FLOAT32_C(  -663.74), SIMDE_FLOAT32_C(   179.29), SIMDE_FLOAT32_C(   989.70), SIMDE_FLOAT32_C(  -695.21),
                         SIMDE_FLOAT32_C(  -786.23), SIMDE_FLOAT32_C(   873.30), SIMDE_FLOAT32_C(   241.45), SIMDE_FLOAT32_C(  -432.13)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(   873.30), SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   268.99)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(   179.29), SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   268.99)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(  -492.61), SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   268.99)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(   493.30), SIMDE_FLOAT32_C(  -959.11), SIMDE_FLOAT32_C(   268.99)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -789.54), SIMDE_FLOAT32_C(  -790.16), SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   994.61)),
      UINT8_C(  8),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -388.47), SIMDE_FLOAT32_C(  -643.43), SIMDE_FLOAT32_C(  -331.34), SIMDE_FLOAT32_C(    72.67),
                         SIMDE_FLOAT32_C(  -870.79), SIMDE_FLOAT32_C(  -722.44), SIMDE_FLOAT32_C(   529.44), SIMDE_FLOAT32_C(  -949.73),
                         SIMDE_FLOAT32_C(   280.87), SIMDE_FLOAT32_C(   380.83), SIMDE_FLOAT32_C(  -236.67), SIMDE_FLOAT32_C(  -211.91),
                         SIMDE_FLOAT32_C(  -925.76), SIMDE_FLOAT32_C(  -915.62), SIMDE_FLOAT32_C(   -30.05), SIMDE_FLOAT32_C(   -70.79)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -925.76), SIMDE_FLOAT32_C(  -790.16), SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   994.61)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   280.87), SIMDE_FLOAT32_C(  -790.16), SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   994.61)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -870.79), SIMDE_FLOAT32_C(  -790.16), SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   994.61)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -388.47), SIMDE_FLOAT32_C(  -790.16), SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   994.61)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -352.24), SIMDE_FLOAT32_C(  -479.79), SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(     2.55)),
      UINT8_C( 60),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -607.82), SIMDE_FLOAT32_C(   296.47), SIMDE_FLOAT32_C(  -327.04), SIMDE_FLOAT32_C(   -23.06),
                         SIMDE_FLOAT32_C(   -95.21), SIMDE_FLOAT32_C(    10.75), SIMDE_FLOAT32_C(  -668.43), SIMDE_FLOAT32_C(  -210.00),
                         SIMDE_FLOAT32_C(   915.68), SIMDE_FLOAT32_C(   -53.79), SIMDE_FLOAT32_C(   703.31), SIMDE_FLOAT32_C(   930.79),
                         SIMDE_FLOAT32_C(   111.33), SIMDE_FLOAT32_C(  -176.75), SIMDE_FLOAT32_C(  -316.94), SIMDE_FLOAT32_C(   639.68)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   111.33), SIMDE_FLOAT32_C(  -176.75), SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(     2.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   915.68), SIMDE_FLOAT32_C(   -53.79), SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(     2.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -95.21), SIMDE_FLOAT32_C(    10.75), SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(     2.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -607.82), SIMDE_FLOAT32_C(   296.47), SIMDE_FLOAT32_C(   602.83), SIMDE_FLOAT32_C(     2.55)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -334.42), SIMDE_FLOAT32_C(   660.53), SIMDE_FLOAT32_C(   748.73), SIMDE_FLOAT32_C(   996.15)),
      UINT8_C( 47),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   383.31), SIMDE_FLOAT32_C(   641.22), SIMDE_FLOAT32_C(  -747.07), SIMDE_FLOAT32_C(  -762.67),
                         SIMDE_FLOAT32_C(   744.11), SIMDE_FLOAT32_C(   350.11), SIMDE_FLOAT32_C(   409.27), SIMDE_FLOAT32_C(   481.83),
                         SIMDE_FLOAT32_C(   601.37), SIMDE_FLOAT32_C(  -660.24), SIMDE_FLOAT32_C(  -675.56), SIMDE_FLOAT32_C(  -194.09),
                         SIMDE_FLOAT32_C(   149.22), SIMDE_FLOAT32_C(   161.52), SIMDE_FLOAT32_C(   632.78), SIMDE_FLOAT32_C(   346.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   149.22), SIMDE_FLOAT32_C(   161.52), SIMDE_FLOAT32_C(   632.78), SIMDE_FLOAT32_C(   346.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   601.37), SIMDE_FLOAT32_C(  -660.24), SIMDE_FLOAT32_C(  -675.56), SIMDE_FLOAT32_C(  -194.09)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   744.11), SIMDE_FLOAT32_C(   350.11), SIMDE_FLOAT32_C(   409.27), SIMDE_FLOAT32_C(   481.83)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   383.31), SIMDE_FLOAT32_C(   641.22), SIMDE_FLOAT32_C(  -747.07), SIMDE_FLOAT32_C(  -762.67)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   122.69), SIMDE_FLOAT32_C(    65.13), SIMDE_FLOAT32_C(  -972.27), SIMDE_FLOAT32_C(   628.22)),
      UINT8_C(171),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -653.71), SIMDE_FLOAT32_C(   371.73), SIMDE_FLOAT32_C(   757.18), SIMDE_FLOAT32_C(   214.84),
                         SIMDE_FLOAT32_C(   830.24), SIMDE_FLOAT32_C(   903.53), SIMDE_FLOAT32_C(  -831.08), SIMDE_FLOAT32_C(   815.07),
                         SIMDE_FLOAT32_C(   196.06), SIMDE_FLOAT32_C(   -83.06), SIMDE_FLOAT32_C(   687.82), SIMDE_FLOAT32_C(  -517.82),
                         SIMDE_FLOAT32_C(  -294.36), SIMDE_FLOAT32_C(   702.71), SIMDE_FLOAT32_C(  -920.22), SIMDE_FLOAT32_C(  -923.04)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -294.36), SIMDE_FLOAT32_C(    65.13), SIMDE_FLOAT32_C(  -920.22), SIMDE_FLOAT32_C(  -923.04)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   196.06), SIMDE_FLOAT32_C(    65.13), SIMDE_FLOAT32_C(   687.82), SIMDE_FLOAT32_C(  -517.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   830.24), SIMDE_FLOAT32_C(    65.13), SIMDE_FLOAT32_C(  -831.08), SIMDE_FLOAT32_C(   815.07)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -653.71), SIMDE_FLOAT32_C(    65.13), SIMDE_FLOAT32_C(   757.18), SIMDE_FLOAT32_C(   214.84)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r;
    r = simde_mm512_mask_extractf32x4_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a, 0);
    simde_assert_m128_close(r, test_vec[i].r0, 1);
    r = simde_mm512_mask_extractf32x4_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a, 1);
    simde_assert_m128_close(r, test_vec[i].r1, 1);
    r = simde_mm512_mask_extractf32x4_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a, 2);
    simde_assert_m128_close(r, test_vec[i].r2, 1);
    r = simde_mm512_mask_extractf32x4_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a, 3);
    simde_assert_m128_close(r, test_vec[i].r3, 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_extractf32x4_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512 a;
    simde__m128 r0;
    simde__m128 r1;
    simde__m128 r2;
    simde__m128 r3;
  } test_vec[8] = {
    { UINT8_C( 63),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   522.06), SIMDE_FLOAT32_C(   160.98), SIMDE_FLOAT32_C(  -932.28), SIMDE_FLOAT32_C(   391.82),
                         SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(  -569.99), SIMDE_FLOAT32_C(  -491.12), SIMDE_FLOAT32_C(  -327.63),
                         SIMDE_FLOAT32_C(  -139.11), SIMDE_FLOAT32_C(  -172.36), SIMDE_FLOAT32_C(  -268.86), SIMDE_FLOAT32_C(   393.53),
                         SIMDE_FLOAT32_C(   -71.72), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(    98.47), SIMDE_FLOAT32_C(  -135.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -71.72), SIMDE_FLOAT32_C(    36.69), SIMDE_FLOAT32_C(    98.47), SIMDE_FLOAT32_C(  -135.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -139.11), SIMDE_FLOAT32_C(  -172.36), SIMDE_FLOAT32_C(  -268.86), SIMDE_FLOAT32_C(   393.53)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   600.12), SIMDE_FLOAT32_C(  -569.99), SIMDE_FLOAT32_C(  -491.12), SIMDE_FLOAT32_C(  -327.63)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   522.06), SIMDE_FLOAT32_C(   160.98), SIMDE_FLOAT32_C(  -932.28), SIMDE_FLOAT32_C(   391.82)) },
    { UINT8_C(157),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   483.08), SIMDE_FLOAT32_C(   903.50), SIMDE_FLOAT32_C(   232.04), SIMDE_FLOAT32_C(   -43.35),
                         SIMDE_FLOAT32_C(   774.81), SIMDE_FLOAT32_C(   309.91), SIMDE_FLOAT32_C(  -599.01), SIMDE_FLOAT32_C(   846.15),
                         SIMDE_FLOAT32_C(    69.04), SIMDE_FLOAT32_C(  -514.56), SIMDE_FLOAT32_C(  -149.02), SIMDE_FLOAT32_C(  -860.98),
                         SIMDE_FLOAT32_C(   240.79), SIMDE_FLOAT32_C(  -280.30), SIMDE_FLOAT32_C(  -839.80), SIMDE_FLOAT32_C(   128.51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   240.79), SIMDE_FLOAT32_C(  -280.30), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   128.51)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    69.04), SIMDE_FLOAT32_C(  -514.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -860.98)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   774.81), SIMDE_FLOAT32_C(   309.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   846.15)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   483.08), SIMDE_FLOAT32_C(   903.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -43.35)) },
    { UINT8_C( 33),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -835.53), SIMDE_FLOAT32_C(  -203.04), SIMDE_FLOAT32_C(   571.79), SIMDE_FLOAT32_C(   -80.71),
                         SIMDE_FLOAT32_C(   675.92), SIMDE_FLOAT32_C(   632.01), SIMDE_FLOAT32_C(   490.41), SIMDE_FLOAT32_C(   456.89),
                         SIMDE_FLOAT32_C(    47.59), SIMDE_FLOAT32_C(    51.33), SIMDE_FLOAT32_C(  -895.71), SIMDE_FLOAT32_C(  -868.59),
                         SIMDE_FLOAT32_C(  -736.92), SIMDE_FLOAT32_C(  -921.00), SIMDE_FLOAT32_C(   283.06), SIMDE_FLOAT32_C(  -471.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -471.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -868.59)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   456.89)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -80.71)) },
    { UINT8_C(176),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -629.37), SIMDE_FLOAT32_C(  -198.67), SIMDE_FLOAT32_C(   337.35), SIMDE_FLOAT32_C(   447.98),
                         SIMDE_FLOAT32_C(  -278.32), SIMDE_FLOAT32_C(  -925.69), SIMDE_FLOAT32_C(  -744.41), SIMDE_FLOAT32_C(   717.83),
                         SIMDE_FLOAT32_C(    39.32), SIMDE_FLOAT32_C(  -489.88), SIMDE_FLOAT32_C(    29.68), SIMDE_FLOAT32_C(   -37.49),
                         SIMDE_FLOAT32_C(  -490.28), SIMDE_FLOAT32_C(  -373.66), SIMDE_FLOAT32_C(   841.53), SIMDE_FLOAT32_C(  -292.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { UINT8_C(169),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -588.28), SIMDE_FLOAT32_C(   846.67), SIMDE_FLOAT32_C(   586.29), SIMDE_FLOAT32_C(   670.52),
                         SIMDE_FLOAT32_C(  -760.88), SIMDE_FLOAT32_C(   149.72), SIMDE_FLOAT32_C(  -617.12), SIMDE_FLOAT32_C(   213.24),
                         SIMDE_FLOAT32_C(  -751.58), SIMDE_FLOAT32_C(  -577.36), SIMDE_FLOAT32_C(   907.23), SIMDE_FLOAT32_C(   957.37),
                         SIMDE_FLOAT32_C(  -359.60), SIMDE_FLOAT32_C(  -934.92), SIMDE_FLOAT32_C(  -213.75), SIMDE_FLOAT32_C(  -657.02)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -359.60), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -657.02)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -751.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   957.37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -760.88), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   213.24)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -588.28), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   670.52)) },
    { UINT8_C( 52),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -432.13), SIMDE_FLOAT32_C(   268.99), SIMDE_FLOAT32_C(  -842.15), SIMDE_FLOAT32_C(  -207.87),
                         SIMDE_FLOAT32_C(   908.84), SIMDE_FLOAT32_C(  -765.42), SIMDE_FLOAT32_C(  -315.78), SIMDE_FLOAT32_C(   138.83),
                         SIMDE_FLOAT32_C(   -86.06), SIMDE_FLOAT32_C(   699.07), SIMDE_FLOAT32_C(  -413.85), SIMDE_FLOAT32_C(  -143.73),
                         SIMDE_FLOAT32_C(   752.26), SIMDE_FLOAT32_C(   709.96), SIMDE_FLOAT32_C(   609.29), SIMDE_FLOAT32_C(  -767.34)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   709.96), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   699.07), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -765.42), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   268.99), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { UINT8_C(217),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   180.78), SIMDE_FLOAT32_C(   717.69), SIMDE_FLOAT32_C(  -289.23), SIMDE_FLOAT32_C(  -663.74),
                         SIMDE_FLOAT32_C(   918.52), SIMDE_FLOAT32_C(   179.29), SIMDE_FLOAT32_C(  -422.76), SIMDE_FLOAT32_C(   989.70),
                         SIMDE_FLOAT32_C(  -433.33), SIMDE_FLOAT32_C(  -695.21), SIMDE_FLOAT32_C(    48.49), SIMDE_FLOAT32_C(  -786.23),
                         SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(   873.30), SIMDE_FLOAT32_C(  -820.22), SIMDE_FLOAT32_C(   241.45)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   799.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   241.45)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -433.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -786.23)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   918.52), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   989.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   180.78), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -663.74)) },
    { UINT8_C(237),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   -70.79), SIMDE_FLOAT32_C(   994.61), SIMDE_FLOAT32_C(   493.65),
                         SIMDE_FLOAT32_C(  -659.70), SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(   493.30), SIMDE_FLOAT32_C(   835.54),
                         SIMDE_FLOAT32_C(   831.29), SIMDE_FLOAT32_C(  -712.24), SIMDE_FLOAT32_C(  -619.50), SIMDE_FLOAT32_C(   518.12),
                         SIMDE_FLOAT32_C(   952.47), SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(  -492.61), SIMDE_FLOAT32_C(   487.08)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   952.47), SIMDE_FLOAT32_C(  -173.80), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   487.08)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   831.29), SIMDE_FLOAT32_C(  -712.24), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   518.12)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -659.70), SIMDE_FLOAT32_C(    52.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   835.54)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   -70.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   493.65)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r;
    r = simde_mm512_maskz_extractf32x4_ps(test_vec[i].k, test_vec[i].a, 0);
    simde_assert_m128_close(r, test_vec[i].r0, 1);
    r = simde_mm512_maskz_extractf32x4_ps(test_vec[i].k, test_vec[i].a, 1);
    simde_assert_m128_close(r, test_vec[i].r1, 1);
    r = simde_mm512_maskz_extractf32x4_ps(test_vec[i].k, test_vec[i].a, 2);
    simde_assert_m128_close(r, test_vec[i].r2, 1);
    r = simde_mm512_maskz_extractf32x4_ps(test_vec[i].k, test_vec[i].a, 3);
    simde_assert_m128_close(r, test_vec[i].r3, 1);
  }

  return 0;
}

static int
test_simde_mm512_extractf32x8_ps(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    simde_float32 a[16];
    simde_float32 r0[8];
    simde_float32 r1[8];
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(  -912.95), SIMDE_FLOAT32_C(   306.91), SIMDE_FLOAT32_C(  -167.78), SIMDE_FLOAT32_C(   996.72),
        SIMDE_FLOAT32_C(  -677.32), SIMDE_FLOAT32_C(  -693.43), SIMDE_FLOAT32_C(   773.51), SIMDE_FLOAT32_C(   890.73),
        SIMDE_FLOAT32_C(   407.16), SIMDE_FLOAT32_C(   411.07), SIMDE_FLOAT32_C(  -686.96), SIMDE_FLOAT32_C(   165.05),
        SIMDE_FLOAT32_C(  -183.16), SIMDE_FLOAT32_C(  -543.66), SIMDE_FLOAT32_C(   960.76), SIMDE_FLOAT32_C(  -123.22) },
      { SIMDE_FLOAT32_C(  -912.95), SIMDE_FLOAT32_C(   306.91), SIMDE_FLOAT32_C(  -167.78), SIMDE_FLOAT32_C(   996.72),
        SIMDE_FLOAT32_C(  -677.32), SIMDE_FLOAT32_C(  -693.43), SIMDE_FLOAT32_C(   773.51), SIMDE_FLOAT32_C(   890.73) },
      { SIMDE_FLOAT32_C(   407.16), SIMDE_FLOAT32_C(   411.07), SIMDE_FLOAT32_C(  -686.96), SIMDE_FLOAT32_C(   165.05),
        SIMDE_FLOAT32_C(  -183.16), SIMDE_FLOAT32_C(  -543.66), SIMDE_FLOAT32_C(   960.76), SIMDE_FLOAT32_C(  -123.22) } },
    { { SIMDE_FLOAT32_C(  -995.16), SIMDE_FLOAT32_C(  -739.23), SIMDE_FLOAT32_C(  -156.50), SIMDE_FLOAT32_C(  -456.71),
        SIMDE_FLOAT32_C(   956.69), SIMDE_FLOAT32_C(  -734.68), SIMDE_FLOAT32_C(   325.52), SIMDE_FLOAT32_C(  -515.39),
        SIMDE_FLOAT32_C(  -858.67), SIMDE_FLOAT32_C(  -158.37), SIMDE_FLOAT32_C(   442.04), SIMDE_FLOAT32_C(  -120.80),
        SIMDE_FLOAT32_C(  -186.22), SIMDE_FLOAT32_C(   439.75), SIMDE_FLOAT32_C(   843.07), SIMDE_FLOAT32_C(   -99.17) },
      { SIMDE_FLOAT32_C(  -995.16), SIMDE_FLOAT32_C(  -739.23), SIMDE_FLOAT32_C(  -156.50), SIMDE_FLOAT32_C(  -456.71),
        SIMDE_FLOAT32_C(   956.69), SIMDE_FLOAT32_C(  -734.68), SIMDE_FLOAT32_C(   325.52), SIMDE_FLOAT32_C(  -515.39) },
      { SIMDE_FLOAT32_C(  -858.67), SIMDE_FLOAT32_C(  -158.37), SIMDE_FLOAT32_C(   442.04), SIMDE_FLOAT32_C(  -120.80),
        SIMDE_FLOAT32_C(  -186.22), SIMDE_FLOAT32_C(   439.75), SIMDE_FLOAT32_C(   843.07), SIMDE_FLOAT32_C(   -99.17) } },
    { { SIMDE_FLOAT32_C(  -253.35), SIMDE_FLOAT32_C(  -324.72), SIMDE_FLOAT32_C(  -102.45), SIMDE_FLOAT32_C(    69.33),
        SIMDE_FLOAT32_C(   -18.15), SIMDE_FLOAT32_C(  -328.94), SIMDE_FLOAT32_C(   -39.94), SIMDE_FLOAT32_C(  -610.99),
        SIMDE_FLOAT32_C(  -917.87), SIMDE_FLOAT32_C(   273.10), SIMDE_FLOAT32_C(   554.07), SIMDE_FLOAT32_C(  -101.03),
        SIMDE_FLOAT32_C(   729.44), SIMDE_FLOAT32_C(   514.83), SIMDE_FLOAT32_C(   775.75), SIMDE_FLOAT32_C(   734.28) },
      { SIMDE_FLOAT32_C(  -253.35), SIMDE_FLOAT32_C(  -324.72), SIMDE_FLOAT32_C(  -102.45), SIMDE_FLOAT32_C(    69.33),
        SIMDE_FLOAT32_C(   -18.15), SIMDE_FLOAT32_C(  -328.94), SIMDE_FLOAT32_C(   -39.94), SIMDE_FLOAT32_C(  -610.99) },
      { SIMDE_FLOAT32_C(  -917.87), SIMDE_FLOAT32_C(   273.10), SIMDE_FLOAT32_C(   554.07), SIMDE_FLOAT32_C(  -101.03),
        SIMDE_FLOAT32_C(   729.44), SIMDE_FLOAT32_C(   514.83), SIMDE_FLOAT32_C(   775.75), SIMDE_FLOAT32_C(   734.28) } },
    { { SIMDE_FLOAT32_C(   775.60), SIMDE_FLOAT32_C(  -380.75), SIMDE_FLOAT32_C(  -722.43), SIMDE_FLOAT32_C(   732.29),
        SIMDE_FLOAT32_C(  -115.42), SIMDE_FLOAT32_C(   603.09), SIMDE_FLOAT32_C(  -783.11), SIMDE_FLOAT32_C(    25.91),
        SIMDE_FLOAT32_C(  -555.28), SIMDE_FLOAT32_C(   658.93), SIMDE_FLOAT32_C(   905.10), SIMDE_FLOAT32_C(   258.49),
        SIMDE_FLOAT32_C(    98.68), SIMDE_FLOAT32_C(   748.17), SIMDE_FLOAT32_C(  -840.67), SIMDE_FLOAT32_C(   845.34) },
      { SIMDE_FLOAT32_C(   775.60), SIMDE_FLOAT32_C(  -380.75), SIMDE_FLOAT32_C(  -722.43), SIMDE_FLOAT32_C(   732.29),
        SIMDE_FLOAT32_C(  -115.42), SIMDE_FLOAT32_C(   603.09), SIMDE_FLOAT32_C(  -783.11), SIMDE_FLOAT32_C(    25.91) },
      { SIMDE_FLOAT32_C(  -555.28), SIMDE_FLOAT32_C(   658.93), SIMDE_FLOAT32_C(   905.10), SIMDE_FLOAT32_C(   258.49),
        SIMDE_FLOAT32_C(    98.68), SIMDE_FLOAT32_C(   748.17), SIMDE_FLOAT32_C(  -840.67), SIMDE_FLOAT32_C(   845.34) } },
    { { SIMDE_FLOAT32_C(  -576.54), SIMDE_FLOAT32_C(    56.88), SIMDE_FLOAT32_C(   -85.33), SIMDE_FLOAT32_C(   405.31),
        SIMDE_FLOAT32_C(   727.94), SIMDE_FLOAT32_C(   874.73), SIMDE_FLOAT32_C(   794.32), SIMDE_FLOAT32_C(   810.07),
        SIMDE_FLOAT32_C(   147.83), SIMDE_FLOAT32_C(   348.39), SIMDE_FLOAT32_C(  -290.97), SIMDE_FLOAT32_C(  -122.73),
        SIMDE_FLOAT32_C(  -136.78), SIMDE_FLOAT32_C(  -515.22), SIMDE_FLOAT32_C(  -388.45), SIMDE_FLOAT32_C(  -361.18) },
      { SIMDE_FLOAT32_C(  -576.54), SIMDE_FLOAT32_C(    56.88), SIMDE_FLOAT32_C(   -85.33), SIMDE_FLOAT32_C(   405.31),
        SIMDE_FLOAT32_C(   727.94), SIMDE_FLOAT32_C(   874.73), SIMDE_FLOAT32_C(   794.32), SIMDE_FLOAT32_C(   810.07) },
      { SIMDE_FLOAT32_C(   147.83), SIMDE_FLOAT32_C(   348.39), SIMDE_FLOAT32_C(  -290.97), SIMDE_FLOAT32_C(  -122.73),
        SIMDE_FLOAT32_C(  -136.78), SIMDE_FLOAT32_C(  -515.22), SIMDE_FLOAT32_C(  -388.45), SIMDE_FLOAT32_C(  -361.18) } },
    { { SIMDE_FLOAT32_C(   104.03), SIMDE_FLOAT32_C(  -110.89), SIMDE_FLOAT32_C(  -628.90), SIMDE_FLOAT32_C(   988.61),
        SIMDE_FLOAT32_C(  -507.80), SIMDE_FLOAT32_C(  -412.00), SIMDE_FLOAT32_C(    14.52), SIMDE_FLOAT32_C(   -63.08),
        SIMDE_FLOAT32_C(  -753.07), SIMDE_FLOAT32_C(   -80.38), SIMDE_FLOAT32_C(  -804.59), SIMDE_FLOAT32_C(   345.61),
        SIMDE_FLOAT32_C(  -332.21), SIMDE_FLOAT32_C(  -645.26), SIMDE_FLOAT32_C(   190.95), SIMDE_FLOAT32_C(    91.25) },
      { SIMDE_FLOAT32_C(   104.03), SIMDE_FLOAT32_C(  -110.89), SIMDE_FLOAT32_C(  -628.90), SIMDE_FLOAT32_C(   988.61),
        SIMDE_FLOAT32_C(  -507.80), SIMDE_FLOAT32_C(  -412.00), SIMDE_FLOAT32_C(    14.52), SIMDE_FLOAT32_C(   -63.08) },
      { SIMDE_FLOAT32_C(  -753.07), SIMDE_FLOAT32_C(   -80.38), SIMDE_FLOAT32_C(  -804.59), SIMDE_FLOAT32_C(   345.61),
        SIMDE_FLOAT32_C(  -332.21), SIMDE_FLOAT32_C(  -645.26), SIMDE_FLOAT32_C(   190.95), SIMDE_FLOAT32_C(    91.25) } },
    { { SIMDE_FLOAT32_C(   411.62), SIMDE_FLOAT32_C(  -894.38), SIMDE_FLOAT32_C(  -503.45), SIMDE_FLOAT32_C(   139.56),
        SIMDE_FLOAT32_C(   980.35), SIMDE_FLOAT32_C(  -709.13), SIMDE_FLOAT32_C(   -50.38), SIMDE_FLOAT32_C(   128.18),
        SIMDE_FLOAT32_C(   639.26), SIMDE_FLOAT32_C(   658.66), SIMDE_FLOAT32_C(  -994.55), SIMDE_FLOAT32_C(  -497.52),
        SIMDE_FLOAT32_C(  -856.57), SIMDE_FLOAT32_C(  -383.00), SIMDE_FLOAT32_C(   141.29), SIMDE_FLOAT32_C(   247.46) },
      { SIMDE_FLOAT32_C(   411.62), SIMDE_FLOAT32_C(  -894.38), SIMDE_FLOAT32_C(  -503.45), SIMDE_FLOAT32_C(   139.56),
        SIMDE_FLOAT32_C(   980.35), SIMDE_FLOAT32_C(  -709.13), SIMDE_FLOAT32_C(   -50.38), SIMDE_FLOAT32_C(   128.18) },
      { SIMDE_FLOAT32_C(   639.26), SIMDE_FLOAT32_C(   658.66), SIMDE_FLOAT32_C(  -994.55), SIMDE_FLOAT32_C(  -497.52),
        SIMDE_FLOAT32_C(  -856.57), SIMDE_FLOAT32_C(  -383.00), SIMDE_FLOAT32_C(   141.29), SIMDE_FLOAT32_C(   247.46) } },
    { { SIMDE_FLOAT32_C(   506.11), SIMDE_FLOAT32_C(   512.40), SIMDE_FLOAT32_C(   236.07), SIMDE_FLOAT32_C(   998.32),
        SIMDE_FLOAT32_C(  -899.61), SIMDE_FLOAT32_C(  -749.41), SIMDE_FLOAT32_C(   -64.76), SIMDE_FLOAT32_C(  -652.67),
        SIMDE_FLOAT32_C(   170.21), SIMDE_FLOAT32_C(   130.65), SIMDE_FLOAT32_C(   692.94), SIMDE_FLOAT32_C(   838.00),
        SIMDE_FLOAT32_C(   485.39), SIMDE_FLOAT32_C(  -116.11), SIMDE_FLOAT32_C(   -70.75), SIMDE_FLOAT32_C(  -102.99) },
      { SIMDE_FLOAT32_C(   506.11), SIMDE_FLOAT32_C(   512.40), SIMDE_FLOAT32_C(   236.07), SIMDE_FLOAT32_C(   998.32),
        SIMDE_FLOAT32_C(  -899.61), SIMDE_FLOAT32_C(  -749.41), SIMDE_FLOAT32_C(   -64.76), SIMDE_FLOAT32_C(  -652.67) },
      { SIMDE_FLOAT32_C(   170.21), SIMDE_FLOAT32_C(   130.65), SIMDE_FLOAT32_C(   692.94), SIMDE_FLOAT32_C(   838.00),
        SIMDE_FLOAT32_C(   485.39), SIMDE_FLOAT32_C(  -116.11), SIMDE_FLOAT32_C(   -70.75), SIMDE_FLOAT32_C(  -102.99) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r;
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    r = simde_mm512_extractf32x8_ps(a, 0);
    simde_assert_m256_close(r, simde_mm256_loadu_ps(test_vec[i].r0), 1);
    r = simde_mm512_extractf32x8_ps(a, 1);
    simde_assert_m256_close(r, simde_mm256_loadu_ps(test_vec[i].r1), 1);
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r0 = simde_mm512_extractf32x8_ps(a, 0);
    simde__m256 r1 = simde_mm512_extractf32x8_ps(a, 1);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_mm512_extractf64x4_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512d a;
    simde__m256d r0;
    simde__m256d r1;
  } test_vec[8] = {
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -431.26), SIMDE_FLOAT64_C(  481.25),
                         SIMDE_FLOAT64_C(  -57.75), SIMDE_FLOAT64_C( -784.26),
                         SIMDE_FLOAT64_C(  438.04), SIMDE_FLOAT64_C(  549.03),
                         SIMDE_FLOAT64_C(  729.46), SIMDE_FLOAT64_C(  582.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  438.04), SIMDE_FLOAT64_C(  549.03),
                         SIMDE_FLOAT64_C(  729.46), SIMDE_FLOAT64_C(  582.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -431.26), SIMDE_FLOAT64_C(  481.25),
                         SIMDE_FLOAT64_C(  -57.75), SIMDE_FLOAT64_C( -784.26)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -563.83), SIMDE_FLOAT64_C(  799.30),
                         SIMDE_FLOAT64_C(  938.85), SIMDE_FLOAT64_C( -576.01),
                         SIMDE_FLOAT64_C( -465.05), SIMDE_FLOAT64_C(  439.15),
                         SIMDE_FLOAT64_C( -104.57), SIMDE_FLOAT64_C(  -28.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -465.05), SIMDE_FLOAT64_C(  439.15),
                         SIMDE_FLOAT64_C( -104.57), SIMDE_FLOAT64_C(  -28.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -563.83), SIMDE_FLOAT64_C(  799.30),
                         SIMDE_FLOAT64_C(  938.85), SIMDE_FLOAT64_C( -576.01)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  355.11), SIMDE_FLOAT64_C( -787.72),
                         SIMDE_FLOAT64_C(  472.82), SIMDE_FLOAT64_C( -703.51),
                         SIMDE_FLOAT64_C( -202.49), SIMDE_FLOAT64_C( -470.36),
                         SIMDE_FLOAT64_C(  966.37), SIMDE_FLOAT64_C(  135.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -202.49), SIMDE_FLOAT64_C( -470.36),
                         SIMDE_FLOAT64_C(  966.37), SIMDE_FLOAT64_C(  135.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  355.11), SIMDE_FLOAT64_C( -787.72),
                         SIMDE_FLOAT64_C(  472.82), SIMDE_FLOAT64_C( -703.51)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  120.10), SIMDE_FLOAT64_C(  -64.06),
                         SIMDE_FLOAT64_C( -620.03), SIMDE_FLOAT64_C(  559.81),
                         SIMDE_FLOAT64_C(  185.23), SIMDE_FLOAT64_C( -423.61),
                         SIMDE_FLOAT64_C(  -11.91), SIMDE_FLOAT64_C(  407.56)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  185.23), SIMDE_FLOAT64_C( -423.61),
                         SIMDE_FLOAT64_C(  -11.91), SIMDE_FLOAT64_C(  407.56)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  120.10), SIMDE_FLOAT64_C(  -64.06),
                         SIMDE_FLOAT64_C( -620.03), SIMDE_FLOAT64_C(  559.81)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C( -859.51), SIMDE_FLOAT64_C(  -69.45),
                         SIMDE_FLOAT64_C(   40.36), SIMDE_FLOAT64_C(   95.61),
                         SIMDE_FLOAT64_C( -743.10), SIMDE_FLOAT64_C( -688.01),
                         SIMDE_FLOAT64_C(  442.76), SIMDE_FLOAT64_C(  931.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -743.10), SIMDE_FLOAT64_C( -688.01),
                         SIMDE_FLOAT64_C(  442.76), SIMDE_FLOAT64_C(  931.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -859.51), SIMDE_FLOAT64_C(  -69.45),
                         SIMDE_FLOAT64_C(   40.36), SIMDE_FLOAT64_C(   95.61)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  193.01), SIMDE_FLOAT64_C( -435.27),
                         SIMDE_FLOAT64_C(  -84.06), SIMDE_FLOAT64_C(  298.40),
                         SIMDE_FLOAT64_C(  208.07), SIMDE_FLOAT64_C(  -94.60),
                         SIMDE_FLOAT64_C(  834.28), SIMDE_FLOAT64_C(  260.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  208.07), SIMDE_FLOAT64_C(  -94.60),
                         SIMDE_FLOAT64_C(  834.28), SIMDE_FLOAT64_C(  260.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  193.01), SIMDE_FLOAT64_C( -435.27),
                         SIMDE_FLOAT64_C(  -84.06), SIMDE_FLOAT64_C(  298.40)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  -98.08), SIMDE_FLOAT64_C(  464.19),
                         SIMDE_FLOAT64_C(  711.12), SIMDE_FLOAT64_C(  282.83),
                         SIMDE_FLOAT64_C( -774.08), SIMDE_FLOAT64_C(  841.24),
                         SIMDE_FLOAT64_C( -414.07), SIMDE_FLOAT64_C(   79.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -774.08), SIMDE_FLOAT64_C(  841.24),
                         SIMDE_FLOAT64_C( -414.07), SIMDE_FLOAT64_C(   79.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -98.08), SIMDE_FLOAT64_C(  464.19),
                         SIMDE_FLOAT64_C(  711.12), SIMDE_FLOAT64_C(  282.83)) },
    { simde_mm512_set_pd(SIMDE_FLOAT64_C(  664.52), SIMDE_FLOAT64_C( -224.13),
                         SIMDE_FLOAT64_C(  633.65), SIMDE_FLOAT64_C( -834.15),
                         SIMDE_FLOAT64_C( -157.33), SIMDE_FLOAT64_C( -819.46),
                         SIMDE_FLOAT64_C(  541.44), SIMDE_FLOAT64_C(  112.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -157.33), SIMDE_FLOAT64_C( -819.46),
                         SIMDE_FLOAT64_C(  541.44), SIMDE_FLOAT64_C(  112.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  664.52), SIMDE_FLOAT64_C( -224.13),
                         SIMDE_FLOAT64_C(  633.65), SIMDE_FLOAT64_C( -834.15)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;
    r = simde_mm512_extractf64x4_pd(test_vec[i].a, 0);
    simde_assert_m256d_close(r, test_vec[i].r0, 1);
    r = simde_mm512_extractf64x4_pd(test_vec[i].a, 1);
    simde_assert_m256d_close(r, test_vec[i].r1, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_extractf64x4_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m256d r0;
    simde__m256d r1;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -172.36), SIMDE_FLOAT64_C(  393.53),
                         SIMDE_FLOAT64_C(   36.69), SIMDE_FLOAT64_C( -135.52)),
      UINT8_C( 63),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  522.06), SIMDE_FLOAT64_C( -932.28),
                         SIMDE_FLOAT64_C(  600.12), SIMDE_FLOAT64_C( -491.12),
                         SIMDE_FLOAT64_C( -139.11), SIMDE_FLOAT64_C( -268.86),
                         SIMDE_FLOAT64_C(  -71.72), SIMDE_FLOAT64_C(   98.47)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -139.11), SIMDE_FLOAT64_C( -268.86),
                         SIMDE_FLOAT64_C(  -71.72), SIMDE_FLOAT64_C(   98.47)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  522.06), SIMDE_FLOAT64_C( -932.28),
                         SIMDE_FLOAT64_C(  600.12), SIMDE_FLOAT64_C( -491.12)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -514.56), SIMDE_FLOAT64_C( -860.98),
                         SIMDE_FLOAT64_C( -280.30), SIMDE_FLOAT64_C(  128.51)),
      UINT8_C(157),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  483.08), SIMDE_FLOAT64_C(  232.04),
                         SIMDE_FLOAT64_C(  774.81), SIMDE_FLOAT64_C( -599.01),
                         SIMDE_FLOAT64_C(   69.04), SIMDE_FLOAT64_C( -149.02),
                         SIMDE_FLOAT64_C(  240.79), SIMDE_FLOAT64_C( -839.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   69.04), SIMDE_FLOAT64_C( -149.02),
                         SIMDE_FLOAT64_C( -280.30), SIMDE_FLOAT64_C( -839.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  483.08), SIMDE_FLOAT64_C(  232.04),
                         SIMDE_FLOAT64_C( -280.30), SIMDE_FLOAT64_C( -599.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   51.33), SIMDE_FLOAT64_C( -868.59),
                         SIMDE_FLOAT64_C( -921.00), SIMDE_FLOAT64_C( -471.60)),
      UINT8_C( 33),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -835.53), SIMDE_FLOAT64_C(  571.79),
                         SIMDE_FLOAT64_C(  675.92), SIMDE_FLOAT64_C(  490.41),
                         SIMDE_FLOAT64_C(   47.59), SIMDE_FLOAT64_C( -895.71),
                         SIMDE_FLOAT64_C( -736.92), SIMDE_FLOAT64_C(  283.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   51.33), SIMDE_FLOAT64_C( -868.59),
                         SIMDE_FLOAT64_C( -921.00), SIMDE_FLOAT64_C(  283.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   51.33), SIMDE_FLOAT64_C( -868.59),
                         SIMDE_FLOAT64_C( -921.00), SIMDE_FLOAT64_C(  490.41)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -489.88), SIMDE_FLOAT64_C(  -37.49),
                         SIMDE_FLOAT64_C( -373.66), SIMDE_FLOAT64_C( -292.35)),
      UINT8_C(176),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -629.37), SIMDE_FLOAT64_C(  337.35),
                         SIMDE_FLOAT64_C( -278.32), SIMDE_FLOAT64_C( -744.41),
                         SIMDE_FLOAT64_C(   39.32), SIMDE_FLOAT64_C(   29.68),
                         SIMDE_FLOAT64_C( -490.28), SIMDE_FLOAT64_C(  841.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -489.88), SIMDE_FLOAT64_C(  -37.49),
                         SIMDE_FLOAT64_C( -373.66), SIMDE_FLOAT64_C( -292.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -489.88), SIMDE_FLOAT64_C(  -37.49),
                         SIMDE_FLOAT64_C( -373.66), SIMDE_FLOAT64_C( -292.35)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -577.36), SIMDE_FLOAT64_C(  957.37),
                         SIMDE_FLOAT64_C( -934.92), SIMDE_FLOAT64_C( -657.02)),
      UINT8_C(169),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -588.28), SIMDE_FLOAT64_C(  586.29),
                         SIMDE_FLOAT64_C( -760.88), SIMDE_FLOAT64_C( -617.12),
                         SIMDE_FLOAT64_C( -751.58), SIMDE_FLOAT64_C(  907.23),
                         SIMDE_FLOAT64_C( -359.60), SIMDE_FLOAT64_C( -213.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -751.58), SIMDE_FLOAT64_C(  957.37),
                         SIMDE_FLOAT64_C( -934.92), SIMDE_FLOAT64_C( -213.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -588.28), SIMDE_FLOAT64_C(  957.37),
                         SIMDE_FLOAT64_C( -934.92), SIMDE_FLOAT64_C( -617.12)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  699.07), SIMDE_FLOAT64_C( -143.73),
                         SIMDE_FLOAT64_C(  709.96), SIMDE_FLOAT64_C( -767.34)),
      UINT8_C( 52),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -432.13), SIMDE_FLOAT64_C( -842.15),
                         SIMDE_FLOAT64_C(  908.84), SIMDE_FLOAT64_C( -315.78),
                         SIMDE_FLOAT64_C(  -86.06), SIMDE_FLOAT64_C( -413.85),
                         SIMDE_FLOAT64_C(  752.26), SIMDE_FLOAT64_C(  609.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  699.07), SIMDE_FLOAT64_C( -413.85),
                         SIMDE_FLOAT64_C(  709.96), SIMDE_FLOAT64_C( -767.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  699.07), SIMDE_FLOAT64_C( -842.15),
                         SIMDE_FLOAT64_C(  709.96), SIMDE_FLOAT64_C( -767.34)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -695.21), SIMDE_FLOAT64_C( -786.23),
                         SIMDE_FLOAT64_C(  873.30), SIMDE_FLOAT64_C(  241.45)),
      UINT8_C(217),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  180.78), SIMDE_FLOAT64_C( -289.23),
                         SIMDE_FLOAT64_C(  918.52), SIMDE_FLOAT64_C( -422.76),
                         SIMDE_FLOAT64_C( -433.33), SIMDE_FLOAT64_C(   48.49),
                         SIMDE_FLOAT64_C(  799.57), SIMDE_FLOAT64_C( -820.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -433.33), SIMDE_FLOAT64_C( -786.23),
                         SIMDE_FLOAT64_C(  873.30), SIMDE_FLOAT64_C( -820.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  180.78), SIMDE_FLOAT64_C( -786.23),
                         SIMDE_FLOAT64_C(  873.30), SIMDE_FLOAT64_C( -422.76)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -712.24), SIMDE_FLOAT64_C(  518.12),
                         SIMDE_FLOAT64_C( -173.80), SIMDE_FLOAT64_C(  487.08)),
      UINT8_C(237),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -415.61), SIMDE_FLOAT64_C(  994.61),
                         SIMDE_FLOAT64_C( -659.70), SIMDE_FLOAT64_C(  493.30),
                         SIMDE_FLOAT64_C(  831.29), SIMDE_FLOAT64_C( -619.50),
                         SIMDE_FLOAT64_C(  952.47), SIMDE_FLOAT64_C( -492.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  831.29), SIMDE_FLOAT64_C( -619.50),
                         SIMDE_FLOAT64_C( -173.80), SIMDE_FLOAT64_C( -492.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -415.61), SIMDE_FLOAT64_C(  994.61),
                         SIMDE_FLOAT64_C( -173.80), SIMDE_FLOAT64_C(  493.30)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;
    r = simde_mm512_mask_extractf64x4_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a, 0);
    simde_assert_m256d_close(r, test_vec[i].r0, 1);
    r = simde_mm512_mask_extractf64x4_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a, 1);
    simde_assert_m256d_close(r, test_vec[i].r1, 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_extractf64x4_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512d a;
    simde__m256d r0;
    simde__m256d r1;
  } test_vec[8] = {
    { UINT8_C( 21),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -139.11), SIMDE_FLOAT64_C( -172.36),
                         SIMDE_FLOAT64_C( -268.86), SIMDE_FLOAT64_C(  393.53),
                         SIMDE_FLOAT64_C(  -71.72), SIMDE_FLOAT64_C(   36.69),
                         SIMDE_FLOAT64_C(   98.47), SIMDE_FLOAT64_C( -135.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   36.69),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -135.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -172.36),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  393.53)) },
    { UINT8_C(150),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -556.90), SIMDE_FLOAT64_C(  522.06),
                         SIMDE_FLOAT64_C(  160.98), SIMDE_FLOAT64_C( -932.28),
                         SIMDE_FLOAT64_C(  391.82), SIMDE_FLOAT64_C(  600.12),
                         SIMDE_FLOAT64_C( -569.99), SIMDE_FLOAT64_C( -491.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  600.12),
                         SIMDE_FLOAT64_C( -569.99), SIMDE_FLOAT64_C(    0.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  522.06),
                         SIMDE_FLOAT64_C(  160.98), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(132),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  846.15), SIMDE_FLOAT64_C(   69.04),
                         SIMDE_FLOAT64_C( -514.56), SIMDE_FLOAT64_C( -149.02),
                         SIMDE_FLOAT64_C( -860.98), SIMDE_FLOAT64_C(  240.79),
                         SIMDE_FLOAT64_C( -280.30), SIMDE_FLOAT64_C( -839.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  240.79),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   69.04),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(158),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -471.60), SIMDE_FLOAT64_C( -333.94),
                         SIMDE_FLOAT64_C(  483.08), SIMDE_FLOAT64_C(  903.50),
                         SIMDE_FLOAT64_C(  232.04), SIMDE_FLOAT64_C(  -43.35),
                         SIMDE_FLOAT64_C(  774.81), SIMDE_FLOAT64_C(  309.91)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  232.04), SIMDE_FLOAT64_C(  -43.35),
                         SIMDE_FLOAT64_C(  774.81), SIMDE_FLOAT64_C(    0.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -471.60), SIMDE_FLOAT64_C( -333.94),
                         SIMDE_FLOAT64_C(  483.08), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(192),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  490.41), SIMDE_FLOAT64_C(  456.89),
                         SIMDE_FLOAT64_C(   47.59), SIMDE_FLOAT64_C(   51.33),
                         SIMDE_FLOAT64_C( -895.71), SIMDE_FLOAT64_C( -868.59),
                         SIMDE_FLOAT64_C( -736.92), SIMDE_FLOAT64_C( -921.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { UINT8_C(209),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  841.53), SIMDE_FLOAT64_C( -292.35),
                         SIMDE_FLOAT64_C(  526.21), SIMDE_FLOAT64_C( -835.53),
                         SIMDE_FLOAT64_C( -203.04), SIMDE_FLOAT64_C(  571.79),
                         SIMDE_FLOAT64_C(  -80.71), SIMDE_FLOAT64_C(  675.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  675.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -835.53)) },
    { UINT8_C( 43),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -925.69), SIMDE_FLOAT64_C( -744.41),
                         SIMDE_FLOAT64_C(  717.83), SIMDE_FLOAT64_C(   39.32),
                         SIMDE_FLOAT64_C( -489.88), SIMDE_FLOAT64_C(   29.68),
                         SIMDE_FLOAT64_C(  -37.49), SIMDE_FLOAT64_C( -490.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -489.88), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  -37.49), SIMDE_FLOAT64_C( -490.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -925.69), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  717.83), SIMDE_FLOAT64_C(   39.32)) },
    { UINT8_C(120),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -934.92), SIMDE_FLOAT64_C( -213.75),
                         SIMDE_FLOAT64_C( -657.02), SIMDE_FLOAT64_C(  403.00),
                         SIMDE_FLOAT64_C( -629.37), SIMDE_FLOAT64_C( -198.67),
                         SIMDE_FLOAT64_C(  337.35), SIMDE_FLOAT64_C(  447.98)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -629.37), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -934.92), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;
    r = simde_mm512_maskz_extractf64x4_pd(test_vec[i].k, test_vec[i].a, 0);
    simde_assert_m256d_close(r, test_vec[i].r0, 1);
    r = simde_mm512_maskz_extractf64x4_pd(test_vec[i].k, test_vec[i].a, 1);
    simde_assert_m256d_close(r, test_vec[i].r1, 1);
  }

  return 0;
}

static int
test_simde_mm512_extracti32x4_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m128i r0;
    simde__m128i r1;
    simde__m128i r2;
    simde__m128i r3;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  936676195), INT32_C( -430989686), INT32_C( -131327474), INT32_C(  910508384),
                            INT32_C( 1148801293), INT32_C(-1204409147), INT32_C( 1922921929), INT32_C( 2087027240),
                            INT32_C( 1221368626), INT32_C(-1114006136), INT32_C( 2023469730), INT32_C(  463308257),
                            INT32_C(-1206798920), INT32_C( -968449396), INT32_C( -580990777), INT32_C( -896508445)),
      simde_mm_set_epi32(INT32_C(-1206798920), INT32_C( -968449396), INT32_C( -580990777), INT32_C( -896508445)),
      simde_mm_set_epi32(INT32_C( 1221368626), INT32_C(-1114006136), INT32_C( 2023469730), INT32_C(  463308257)),
      simde_mm_set_epi32(INT32_C( 1148801293), INT32_C(-1204409147), INT32_C( 1922921929), INT32_C( 2087027240)),
      simde_mm_set_epi32(INT32_C(  936676195), INT32_C( -430989686), INT32_C( -131327474), INT32_C(  910508384)) },
    { simde_mm512_set_epi32(INT32_C(-1889562474), INT32_C( 2009910179), INT32_C(  815981096), INT32_C( -945310665),
                            INT32_C(-1749696319), INT32_C( 1237778758), INT32_C( 2121903540), INT32_C(-1272250958),
                            INT32_C(-1384883580), INT32_C(  455864550), INT32_C(-1132110758), INT32_C(  636699315),
                            INT32_C( 1712647786), INT32_C( 1137382661), INT32_C(  -72212648), INT32_C(-1857153584)),
      simde_mm_set_epi32(INT32_C( 1712647786), INT32_C( 1137382661), INT32_C(  -72212648), INT32_C(-1857153584)),
      simde_mm_set_epi32(INT32_C(-1384883580), INT32_C(  455864550), INT32_C(-1132110758), INT32_C(  636699315)),
      simde_mm_set_epi32(INT32_C(-1749696319), INT32_C( 1237778758), INT32_C( 2121903540), INT32_C(-1272250958)),
      simde_mm_set_epi32(INT32_C(-1889562474), INT32_C( 2009910179), INT32_C(  815981096), INT32_C( -945310665)) },
    { simde_mm512_set_epi32(INT32_C(-1732993162), INT32_C( 1212743926), INT32_C( 1966971402), INT32_C(-1506668774),
                            INT32_C(-1700657265), INT32_C( 1944327234), INT32_C( -355879099), INT32_C(-1588067414),
                            INT32_C(  301696052), INT32_C( 1998339065), INT32_C(-2060809025), INT32_C(-1942156019),
                            INT32_C(  551689125), INT32_C(  669995747), INT32_C(-1196653219), INT32_C( -147816939)),
      simde_mm_set_epi32(INT32_C(  551689125), INT32_C(  669995747), INT32_C(-1196653219), INT32_C( -147816939)),
      simde_mm_set_epi32(INT32_C(  301696052), INT32_C( 1998339065), INT32_C(-2060809025), INT32_C(-1942156019)),
      simde_mm_set_epi32(INT32_C(-1700657265), INT32_C( 1944327234), INT32_C( -355879099), INT32_C(-1588067414)),
      simde_mm_set_epi32(INT32_C(-1732993162), INT32_C( 1212743926), INT32_C( 1966971402), INT32_C(-1506668774)) },
    { simde_mm512_set_epi32(INT32_C( -720429002), INT32_C( 1666176035), INT32_C( -786738545), INT32_C(  356149527),
                            INT32_C( 1809623523), INT32_C(  387697241), INT32_C( -984752565), INT32_C(-1905225073),
                            INT32_C( 1936855390), INT32_C(-1150638889), INT32_C( -620356961), INT32_C(-1540113901),
                            INT32_C(  485150966), INT32_C( -340934070), INT32_C( 1258270405), INT32_C(-1976197296)),
      simde_mm_set_epi32(INT32_C(  485150966), INT32_C( -340934070), INT32_C( 1258270405), INT32_C(-1976197296)),
      simde_mm_set_epi32(INT32_C( 1936855390), INT32_C(-1150638889), INT32_C( -620356961), INT32_C(-1540113901)),
      simde_mm_set_epi32(INT32_C( 1809623523), INT32_C(  387697241), INT32_C( -984752565), INT32_C(-1905225073)),
      simde_mm_set_epi32(INT32_C( -720429002), INT32_C( 1666176035), INT32_C( -786738545), INT32_C(  356149527)) },
    { simde_mm512_set_epi32(INT32_C(-1844524534), INT32_C(  359706932), INT32_C(   21147132), INT32_C(-1205907433),
                            INT32_C(  241660444), INT32_C(-1425169590), INT32_C( 1296561443), INT32_C(-1934442075),
                            INT32_C( 2141890625), INT32_C( 2063982974), INT32_C(-1791266937), INT32_C(-1677757015),
                            INT32_C(-1341587157), INT32_C(   71085124), INT32_C( 1045857655), INT32_C(  563120574)),
      simde_mm_set_epi32(INT32_C(-1341587157), INT32_C(   71085124), INT32_C( 1045857655), INT32_C(  563120574)),
      simde_mm_set_epi32(INT32_C( 2141890625), INT32_C( 2063982974), INT32_C(-1791266937), INT32_C(-1677757015)),
      simde_mm_set_epi32(INT32_C(  241660444), INT32_C(-1425169590), INT32_C( 1296561443), INT32_C(-1934442075)),
      simde_mm_set_epi32(INT32_C(-1844524534), INT32_C(  359706932), INT32_C(   21147132), INT32_C(-1205907433)) },
    { simde_mm512_set_epi32(INT32_C( 1760980702), INT32_C(-1592941833), INT32_C(-1618734568), INT32_C(-1937346052),
                            INT32_C( -716563340), INT32_C(-1364071584), INT32_C( -516953475), INT32_C( 1021791773),
                            INT32_C(  587319712), INT32_C(-1327772936), INT32_C( -388433125), INT32_C(-1835488163),
                            INT32_C( 1934085090), INT32_C( 1823172786), INT32_C( -962834173), INT32_C(-1813383694)),
      simde_mm_set_epi32(INT32_C( 1934085090), INT32_C( 1823172786), INT32_C( -962834173), INT32_C(-1813383694)),
      simde_mm_set_epi32(INT32_C(  587319712), INT32_C(-1327772936), INT32_C( -388433125), INT32_C(-1835488163)),
      simde_mm_set_epi32(INT32_C( -716563340), INT32_C(-1364071584), INT32_C( -516953475), INT32_C( 1021791773)),
      simde_mm_set_epi32(INT32_C( 1760980702), INT32_C(-1592941833), INT32_C(-1618734568), INT32_C(-1937346052)) },
    { simde_mm512_set_epi32(INT32_C(-1600993635), INT32_C( 1692797667), INT32_C( -524624106), INT32_C( -196896874),
                            INT32_C( 1365949044), INT32_C( 1838002887), INT32_C( -452898509), INT32_C( 1408911553),
                            INT32_C(-1407150071), INT32_C(  -82352116), INT32_C( -745337283), INT32_C( -527368953),
                            INT32_C(-1750389986), INT32_C( 1217697098), INT32_C( 1169663592), INT32_C(-1794175196)),
      simde_mm_set_epi32(INT32_C(-1750389986), INT32_C( 1217697098), INT32_C( 1169663592), INT32_C(-1794175196)),
      simde_mm_set_epi32(INT32_C(-1407150071), INT32_C(  -82352116), INT32_C( -745337283), INT32_C( -527368953)),
      simde_mm_set_epi32(INT32_C( 1365949044), INT32_C( 1838002887), INT32_C( -452898509), INT32_C( 1408911553)),
      simde_mm_set_epi32(INT32_C(-1600993635), INT32_C( 1692797667), INT32_C( -524624106), INT32_C( -196896874)) },
    { simde_mm512_set_epi32(INT32_C(   31532768), INT32_C(-1104316005), INT32_C(-1643683522), INT32_C( -459507150),
                            INT32_C( -301521916), INT32_C(-1095317885), INT32_C( 1268414902), INT32_C( -436965349),
                            INT32_C(  330503221), INT32_C( 1614750696), INT32_C( 1262893786), INT32_C( 1956553172),
                            INT32_C(-1113093793), INT32_C(-1782413198), INT32_C( 1413241306), INT32_C(-1360271723)),
      simde_mm_set_epi32(INT32_C(-1113093793), INT32_C(-1782413198), INT32_C( 1413241306), INT32_C(-1360271723)),
      simde_mm_set_epi32(INT32_C(  330503221), INT32_C( 1614750696), INT32_C( 1262893786), INT32_C( 1956553172)),
      simde_mm_set_epi32(INT32_C( -301521916), INT32_C(-1095317885), INT32_C( 1268414902), INT32_C( -436965349)),
      simde_mm_set_epi32(INT32_C(   31532768), INT32_C(-1104316005), INT32_C(-1643683522), INT32_C( -459507150)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    r = simde_mm512_extracti32x4_epi32(test_vec[i].a, 0);
    simde_assert_m128i_i32(r, ==, test_vec[i].r0);
    r = simde_mm512_extracti32x4_epi32(test_vec[i].a, 1);
    simde_assert_m128i_i32(r, ==, test_vec[i].r1);
    r = simde_mm512_extracti32x4_epi32(test_vec[i].a, 2);
    simde_assert_m128i_i32(r, ==, test_vec[i].r2);
    r = simde_mm512_extracti32x4_epi32(test_vec[i].a, 3);
    simde_assert_m128i_i32(r, ==, test_vec[i].r3);
  }

  return 0;
}

static int
test_simde_mm512_mask_extracti32x4_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m128i r0;
    simde__m128i r1;
    simde__m128i r2;
    simde__m128i r3;
  } test_vec[8] = {
    {  simde_mm_set_epi32(INT32_C( 1993455974), INT32_C(-2068684593), INT32_C(-1936012201), INT32_C( 1856459607)),
      UINT8_C(  6),
      simde_mm512_set_epi32(INT32_C(-1630396605), INT32_C( 1545554432), INT32_C(  344023940), INT32_C(-1871515754),
                            INT32_C(  951544639), INT32_C(-1026363374), INT32_C(-1801776439), INT32_C(  145438126),
                            INT32_C(-1306064352), INT32_C( -858736392), INT32_C(  923442479), INT32_C( 1092805562),
                            INT32_C( 1443901717), INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1570116932)),
      simde_mm_set_epi32(INT32_C( 1993455974), INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1856459607)),
      simde_mm_set_epi32(INT32_C( 1993455974), INT32_C( -858736392), INT32_C(  923442479), INT32_C( 1856459607)),
      simde_mm_set_epi32(INT32_C( 1993455974), INT32_C(-1026363374), INT32_C(-1801776439), INT32_C( 1856459607)),
      simde_mm_set_epi32(INT32_C( 1993455974), INT32_C( 1545554432), INT32_C(  344023940), INT32_C( 1856459607)) },
    {  simde_mm_set_epi32(INT32_C(-1999224530), INT32_C( 1042470181), INT32_C( 1827473477), INT32_C(  298546792)),
      UINT8_C(109),
      simde_mm512_set_epi32(INT32_C(-2045280751), INT32_C(-2037261521), INT32_C(  223952317), INT32_C(  282198336),
                            INT32_C(  564965997), INT32_C(  169645898), INT32_C(-1539616610), INT32_C( 1134735685),
                            INT32_C( 1430356381), INT32_C(-1110068455), INT32_C( -207240031), INT32_C(-1649179267),
                            INT32_C( 2054398444), INT32_C( -483586503), INT32_C(-1481960002), INT32_C(  861125508)),
      simde_mm_set_epi32(INT32_C( 2054398444), INT32_C( -483586503), INT32_C( 1827473477), INT32_C(  861125508)),
      simde_mm_set_epi32(INT32_C( 1430356381), INT32_C(-1110068455), INT32_C( 1827473477), INT32_C(-1649179267)),
      simde_mm_set_epi32(INT32_C(  564965997), INT32_C(  169645898), INT32_C( 1827473477), INT32_C( 1134735685)),
      simde_mm_set_epi32(INT32_C(-2045280751), INT32_C(-2037261521), INT32_C( 1827473477), INT32_C(  282198336)) },
    {  simde_mm_set_epi32(INT32_C( -695949043), INT32_C( -790242624), INT32_C(-1094331335), INT32_C(-1166320093)),
      UINT8_C(181),
      simde_mm512_set_epi32(INT32_C( 1549802795), INT32_C(  159583350), INT32_C(  548883180), INT32_C( -605945909),
                            INT32_C(-2063050181), INT32_C( 1095467003), INT32_C(-2083755741), INT32_C( 2066979701),
                            INT32_C( 1094609712), INT32_C( 1345059025), INT32_C( -340318359), INT32_C( 1519671047),
                            INT32_C(-1017461983), INT32_C(  353198331), INT32_C( 1711460779), INT32_C( -919570191)),
      simde_mm_set_epi32(INT32_C( -695949043), INT32_C(  353198331), INT32_C(-1094331335), INT32_C( -919570191)),
      simde_mm_set_epi32(INT32_C( -695949043), INT32_C( 1345059025), INT32_C(-1094331335), INT32_C( 1519671047)),
      simde_mm_set_epi32(INT32_C( -695949043), INT32_C( 1095467003), INT32_C(-1094331335), INT32_C( 2066979701)),
      simde_mm_set_epi32(INT32_C( -695949043), INT32_C(  159583350), INT32_C(-1094331335), INT32_C( -605945909)) },
    {  simde_mm_set_epi32(INT32_C(  795925067), INT32_C( 1720852541), INT32_C(-1423023772), INT32_C(-1185448755)),
      UINT8_C(176),
      simde_mm512_set_epi32(INT32_C(  884163960), INT32_C( -329275629), INT32_C( -888441293), INT32_C( -707551350),
                            INT32_C(  513515868), INT32_C(-1825967755), INT32_C(  822222164), INT32_C(-1689559027),
                            INT32_C(  533478787), INT32_C(  907615417), INT32_C( -199229058), INT32_C(  -91537812),
                            INT32_C( 1375258232), INT32_C(  139748399), INT32_C( 1688468565), INT32_C(  736544549)),
      simde_mm_set_epi32(INT32_C(  795925067), INT32_C( 1720852541), INT32_C(-1423023772), INT32_C(-1185448755)),
      simde_mm_set_epi32(INT32_C(  795925067), INT32_C( 1720852541), INT32_C(-1423023772), INT32_C(-1185448755)),
      simde_mm_set_epi32(INT32_C(  795925067), INT32_C( 1720852541), INT32_C(-1423023772), INT32_C(-1185448755)),
      simde_mm_set_epi32(INT32_C(  795925067), INT32_C( 1720852541), INT32_C(-1423023772), INT32_C(-1185448755)) },
    {  simde_mm_set_epi32(INT32_C( -622852205), INT32_C( -839037220), INT32_C(  499633910), INT32_C( -260167255)),
      UINT8_C( 21),
      simde_mm512_set_epi32(INT32_C( -272088075), INT32_C(  386072301), INT32_C(-1628984154), INT32_C(   87817524),
                            INT32_C( 1219490517), INT32_C(-1569831145), INT32_C(  338985942), INT32_C( 1701079465),
                            INT32_C( -195770682), INT32_C(  503748315), INT32_C( 1469355417), INT32_C(-1849349632),
                            INT32_C( 1962664621), INT32_C( -646247370), INT32_C( 1258747662), INT32_C( 1838830023)),
      simde_mm_set_epi32(INT32_C( -622852205), INT32_C( -646247370), INT32_C(  499633910), INT32_C( 1838830023)),
      simde_mm_set_epi32(INT32_C( -622852205), INT32_C(  503748315), INT32_C(  499633910), INT32_C(-1849349632)),
      simde_mm_set_epi32(INT32_C( -622852205), INT32_C(-1569831145), INT32_C(  499633910), INT32_C( 1701079465)),
      simde_mm_set_epi32(INT32_C( -622852205), INT32_C(  386072301), INT32_C(  499633910), INT32_C(   87817524)) },
    {  simde_mm_set_epi32(INT32_C(  654527510), INT32_C(-2043358500), INT32_C(  459072440), INT32_C( -430427651)),
      UINT8_C(229),
      simde_mm512_set_epi32(INT32_C(  617951303), INT32_C(  817116152), INT32_C(-1034835761), INT32_C( -102069057),
                            INT32_C( 1774242298), INT32_C( 1089620040), INT32_C(-1101477862), INT32_C( 2001101785),
                            INT32_C(-1759250988), INT32_C( -606254738), INT32_C( 1526367108), INT32_C(  722122834),
                            INT32_C( -174985661), INT32_C(-1762469023), INT32_C( 1239606494), INT32_C(  -22119232)),
      simde_mm_set_epi32(INT32_C(  654527510), INT32_C(-1762469023), INT32_C(  459072440), INT32_C(  -22119232)),
      simde_mm_set_epi32(INT32_C(  654527510), INT32_C( -606254738), INT32_C(  459072440), INT32_C(  722122834)),
      simde_mm_set_epi32(INT32_C(  654527510), INT32_C( 1089620040), INT32_C(  459072440), INT32_C( 2001101785)),
      simde_mm_set_epi32(INT32_C(  654527510), INT32_C(  817116152), INT32_C(  459072440), INT32_C( -102069057)) },
    {  simde_mm_set_epi32(INT32_C(-2034110695), INT32_C(-1088138491), INT32_C( -353174912), INT32_C( -362301616)),
      UINT8_C( 42),
      simde_mm512_set_epi32(INT32_C(  204417556), INT32_C(-1329665093), INT32_C(-2039025377), INT32_C( 1639231015),
                            INT32_C( 1541217841), INT32_C( 1692413538), INT32_C(  738521275), INT32_C(  159429100),
                            INT32_C(  451955897), INT32_C(  181201098), INT32_C(  450627934), INT32_C( 2082954477),
                            INT32_C( 1254960767), INT32_C( 1995459397), INT32_C(  -11572946), INT32_C(-1087388220)),
      simde_mm_set_epi32(INT32_C( 1254960767), INT32_C(-1088138491), INT32_C(  -11572946), INT32_C( -362301616)),
      simde_mm_set_epi32(INT32_C(  451955897), INT32_C(-1088138491), INT32_C(  450627934), INT32_C( -362301616)),
      simde_mm_set_epi32(INT32_C( 1541217841), INT32_C(-1088138491), INT32_C(  738521275), INT32_C( -362301616)),
      simde_mm_set_epi32(INT32_C(  204417556), INT32_C(-1088138491), INT32_C(-2039025377), INT32_C( -362301616)) },
    {  simde_mm_set_epi32(INT32_C(-1687118128), INT32_C(  107945377), INT32_C( 1174128677), INT32_C(-1544325740)),
      UINT8_C(132),
      simde_mm512_set_epi32(INT32_C( -852914371), INT32_C( -773785464), INT32_C(-2142007253), INT32_C(  466013192),
                            INT32_C( 1313258175), INT32_C( 1928049651), INT32_C(  765730488), INT32_C(  -85899231),
                            INT32_C( 1435935141), INT32_C(-2098236580), INT32_C(-1991433794), INT32_C( 1298943776),
                            INT32_C(  277470244), INT32_C(-1834748849), INT32_C(  596054477), INT32_C( 1827419510)),
      simde_mm_set_epi32(INT32_C(-1687118128), INT32_C(-1834748849), INT32_C( 1174128677), INT32_C(-1544325740)),
      simde_mm_set_epi32(INT32_C(-1687118128), INT32_C(-2098236580), INT32_C( 1174128677), INT32_C(-1544325740)),
      simde_mm_set_epi32(INT32_C(-1687118128), INT32_C( 1928049651), INT32_C( 1174128677), INT32_C(-1544325740)),
      simde_mm_set_epi32(INT32_C(-1687118128), INT32_C( -773785464), INT32_C( 1174128677), INT32_C(-1544325740)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    r = simde_mm512_mask_extracti32x4_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a, 0);
    simde_assert_m128i_i32(r, ==, test_vec[i].r0);
    r = simde_mm512_mask_extracti32x4_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a, 1);
    simde_assert_m128i_i32(r, ==, test_vec[i].r1);
    r = simde_mm512_mask_extracti32x4_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a, 2);
    simde_assert_m128i_i32(r, ==, test_vec[i].r2);
    r = simde_mm512_mask_extracti32x4_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a, 3);
    simde_assert_m128i_i32(r, ==, test_vec[i].r3);
  }

  return 0;
}

static int
test_simde_mm512_maskz_extracti32x4_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m128i r0;
    simde__m128i r1;
    simde__m128i r2;
    simde__m128i r3;
  } test_vec[8] = {
    { UINT8_C( 87),
      simde_mm512_set_epi32(INT32_C(  951544639), INT32_C(-1026363374), INT32_C(-1801776439), INT32_C(  145438126),
                            INT32_C(-1306064352), INT32_C( -858736392), INT32_C(  923442479), INT32_C( 1092805562),
                            INT32_C( 1443901717), INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1570116932),
                            INT32_C(-1302383354), INT32_C( 1993455974), INT32_C(-2068684593), INT32_C(-1936012201)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( 1993455974), INT32_C(-2068684593), INT32_C(-1936012201)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( 1848749100), INT32_C( 1777333881), INT32_C( 1570116932)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( -858736392), INT32_C(  923442479), INT32_C( 1092805562)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(-1026363374), INT32_C(-1801776439), INT32_C(  145438126)) },
    { UINT8_C(150),
      simde_mm512_set_epi32(INT32_C( 1430356381), INT32_C(-1110068455), INT32_C( -207240031), INT32_C(-1649179267),
                            INT32_C( 2054398444), INT32_C( -483586503), INT32_C(-1481960002), INT32_C(  861125508),
                            INT32_C( -330381203), INT32_C(-1999224530), INT32_C( 1042470181), INT32_C( 1827473477),
                            INT32_C(  298546792), INT32_C(-1630396605), INT32_C( 1545554432), INT32_C(  344023940)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(-1630396605), INT32_C( 1545554432), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(-1999224530), INT32_C( 1042470181), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( -483586503), INT32_C(-1481960002), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(-1110068455), INT32_C( -207240031), INT32_C(          0)) },
    { UINT8_C( 69),
      simde_mm512_set_epi32(INT32_C(-1017461983), INT32_C(  353198331), INT32_C( 1711460779), INT32_C( -919570191),
                            INT32_C( 1974152373), INT32_C( -695949043), INT32_C( -790242624), INT32_C(-1094331335),
                            INT32_C(-1166320093), INT32_C(-2045280751), INT32_C(-2037261521), INT32_C(  223952317),
                            INT32_C(  282198336), INT32_C(  564965997), INT32_C(  169645898), INT32_C(-1539616610)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(  564965997), INT32_C(          0), INT32_C(-1539616610)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(-2045280751), INT32_C(          0), INT32_C(  223952317)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( -695949043), INT32_C(          0), INT32_C(-1094331335)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(  353198331), INT32_C(          0), INT32_C( -919570191)) },
    { UINT8_C(  7),
      simde_mm512_set_epi32(INT32_C(-1282057552), INT32_C(  795925067), INT32_C( 1720852541), INT32_C(-1423023772),
                            INT32_C(-1185448755), INT32_C( 1549802795), INT32_C(  159583350), INT32_C(  548883180),
                            INT32_C( -605945909), INT32_C(-2063050181), INT32_C( 1095467003), INT32_C(-2083755741),
                            INT32_C( 2066979701), INT32_C( 1094609712), INT32_C( 1345059025), INT32_C( -340318359)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( 1094609712), INT32_C( 1345059025), INT32_C( -340318359)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(-2063050181), INT32_C( 1095467003), INT32_C(-2083755741)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( 1549802795), INT32_C(  159583350), INT32_C(  548883180)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(  795925067), INT32_C( 1720852541), INT32_C(-1423023772)) },
    { UINT8_C( 37),
      simde_mm512_set_epi32(INT32_C( -260167255), INT32_C(  884163960), INT32_C( -329275629), INT32_C( -888441293),
                            INT32_C( -707551350), INT32_C(  513515868), INT32_C(-1825967755), INT32_C(  822222164),
                            INT32_C(-1689559027), INT32_C(  533478787), INT32_C(  907615417), INT32_C( -199229058),
                            INT32_C(  -91537812), INT32_C( 1375258232), INT32_C(  139748399), INT32_C( 1688468565)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( 1375258232), INT32_C(          0), INT32_C( 1688468565)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(  533478787), INT32_C(          0), INT32_C( -199229058)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(  513515868), INT32_C(          0), INT32_C(  822222164)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(  884163960), INT32_C(          0), INT32_C( -888441293)) },
    { UINT8_C(246),
      simde_mm512_set_epi32(INT32_C(   87817524), INT32_C( 1219490517), INT32_C(-1569831145), INT32_C(  338985942),
                            INT32_C( 1701079465), INT32_C( -195770682), INT32_C(  503748315), INT32_C( 1469355417),
                            INT32_C(-1849349632), INT32_C( 1962664621), INT32_C( -646247370), INT32_C( 1258747662),
                            INT32_C( 1838830023), INT32_C( -532007659), INT32_C( -622852205), INT32_C( -839037220)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( -532007659), INT32_C( -622852205), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( 1962664621), INT32_C( -646247370), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( -195770682), INT32_C(  503748315), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( 1219490517), INT32_C(-1569831145), INT32_C(          0)) },
    { UINT8_C(166),
      simde_mm512_set_epi32(INT32_C( 2001101785), INT32_C(-1759250988), INT32_C( -606254738), INT32_C( 1526367108),
                            INT32_C(  722122834), INT32_C( -174985661), INT32_C(-1762469023), INT32_C( 1239606494),
                            INT32_C(  -22119232), INT32_C( 1216907749), INT32_C(  654527510), INT32_C(-2043358500),
                            INT32_C(  459072440), INT32_C( -430427651), INT32_C( -272088075), INT32_C(  386072301)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( -430427651), INT32_C( -272088075), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( 1216907749), INT32_C(  654527510), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C( -174985661), INT32_C(-1762469023), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(-1759250988), INT32_C( -606254738), INT32_C(          0)) },
    { UINT8_C( 26),
      simde_mm512_set_epi32(INT32_C( 2082954477), INT32_C( 1254960767), INT32_C( 1995459397), INT32_C(  -11572946),
                            INT32_C(-1087388220), INT32_C(  730787370), INT32_C(-2034110695), INT32_C(-1088138491),
                            INT32_C( -353174912), INT32_C( -362301616), INT32_C(  617951303), INT32_C(  817116152),
                            INT32_C(-1034835761), INT32_C( -102069057), INT32_C( 1774242298), INT32_C( 1089620040)),
      simde_mm_set_epi32(INT32_C(-1034835761), INT32_C(          0), INT32_C( 1774242298), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C( -353174912), INT32_C(          0), INT32_C(  617951303), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(-1087388220), INT32_C(          0), INT32_C(-2034110695), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C( 2082954477), INT32_C(          0), INT32_C( 1995459397), INT32_C(          0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    r = simde_mm512_maskz_extracti32x4_epi32(test_vec[i].k, test_vec[i].a, 0);
    simde_assert_m128i_i32(r, ==, test_vec[i].r0);
    r = simde_mm512_maskz_extracti32x4_epi32(test_vec[i].k, test_vec[i].a, 1);
    simde_assert_m128i_i32(r, ==, test_vec[i].r1);
    r = simde_mm512_maskz_extracti32x4_epi32(test_vec[i].k, test_vec[i].a, 2);
    simde_assert_m128i_i32(r, ==, test_vec[i].r2);
    r = simde_mm512_maskz_extracti32x4_epi32(test_vec[i].k, test_vec[i].a, 3);
    simde_assert_m128i_i32(r, ==, test_vec[i].r3);
  }

  return 0;
}

static int
test_simde_mm512_extracti64x4_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m256i r0;
    simde__m256i r1;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 4022993628330696330), INT64_C( -564047204985781920),
                            INT64_C( 4934063986128071877), INT64_C( 8258886799903261224),
                            INT64_C( 5245738308211416456), INT64_C( 8690736315259258337),
                            INT64_C(-5183161890921602420), INT64_C(-2495336383094170141)),
      simde_mm256_set_epi64x(INT64_C( 5245738308211416456), INT64_C( 8690736315259258337),
                             INT64_C(-5183161890921602420), INT64_C(-2495336383094170141)),
      simde_mm256_set_epi64x(INT64_C( 4022993628330696330), INT64_C( -564047204985781920),
                             INT64_C( 4934063986128071877), INT64_C( 8258886799903261224)) },
    { simde_mm512_set_epi64(INT64_C(-8115609027568940125), INT64_C( 3504612124823893047),
                            INT64_C(-7514888466798804666), INT64_C( 9113506312589344178),
                            INT64_C(-5948029684411535130), INT64_C(-4862378680423071053),
                            INT64_C( 7355766231574189317), INT64_C( -310150959079746096)),
      simde_mm256_set_epi64x(INT64_C(-5948029684411535130), INT64_C(-4862378680423071053),
                             INT64_C( 7355766231574189317), INT64_C( -310150959079746096)),
      simde_mm256_set_epi64x(INT64_C(-8115609027568940125), INT64_C( 3504612124823893047),
                             INT64_C(-7514888466798804666), INT64_C( 9113506312589344178)) },
    { simde_mm512_set_epi64(INT64_C(-7443148953768886026), INT64_C( 8448077846545567514),
                            INT64_C(-7304267332935478206), INT64_C(-1528489088828046422),
                            INT64_C( 1295774678670654457), INT64_C(-8851107363323835123),
                            INT64_C( 2369486750103851747), INT64_C(-5139586436110975467)),
      simde_mm256_set_epi64x(INT64_C( 1295774678670654457), INT64_C(-8851107363323835123),
                             INT64_C( 2369486750103851747), INT64_C(-5139586436110975467)),
      simde_mm256_set_epi64x(INT64_C(-7443148953768886026), INT64_C( 8448077846545567514),
                             INT64_C(-7304267332935478206), INT64_C(-1528489088828046422)) },
    { simde_mm512_set_epi64(INT64_C(-3094219001013742557), INT64_C(-3379016320921474793),
                            INT64_C( 7772273849745001049), INT64_C(-4229480058937372017),
                            INT64_C( 8318730560275653847), INT64_C(-2664412856586094061),
                            INT64_C( 2083707536546841162), INT64_C( 5404230241318444880)),
      simde_mm256_set_epi64x(INT64_C( 8318730560275653847), INT64_C(-2664412856586094061),
                             INT64_C( 2083707536546841162), INT64_C( 5404230241318444880)),
      simde_mm256_set_epi64x(INT64_C(-3094219001013742557), INT64_C(-3379016320921474793),
                             INT64_C( 7772273849745001049), INT64_C(-4229480058937372017)) },
    { simde_mm512_set_epi64(INT64_C(-7922172549839933132), INT64_C(   90826243433254935),
                            INT64_C( 1037923706586637130), INT64_C( 5568688997300093349),
                            INT64_C( 9199350188047982974), INT64_C(-7693432910203882071),
                            INT64_C(-5762072963977532348), INT64_C( 4491924425059371454)),
      simde_mm256_set_epi64x(INT64_C( 9199350188047982974), INT64_C(-7693432910203882071),
                             INT64_C(-5762072963977532348), INT64_C( 4491924425059371454)),
      simde_mm256_set_epi64x(INT64_C(-7922172549839933132), INT64_C(   90826243433254935),
                             INT64_C( 1037923706586637130), INT64_C( 5568688997300093349)) },
    { simde_mm512_set_epi64(INT64_C( 7563354526679147255), INT64_C(-6952412028107066884),
                            INT64_C(-3077616107881632928), INT64_C(-2220298267656761827),
                            INT64_C( 2522518958303333112), INT64_C(-1668307566098600867),
                            INT64_C( 8306832211054389426), INT64_C(-4135341282024622606)),
      simde_mm256_set_epi64x(INT64_C( 2522518958303333112), INT64_C(-1668307566098600867),
                             INT64_C( 8306832211054389426), INT64_C(-4135341282024622606)),
      simde_mm256_set_epi64x(INT64_C( 7563354526679147255), INT64_C(-6952412028107066884),
                             INT64_C(-3077616107881632928), INT64_C(-2220298267656761827)) },
    { simde_mm512_set_epi64(INT64_C(-6876215301736363293), INT64_C(-2253243373865166954),
                            INT64_C( 5866706473820467911), INT64_C(-1945184283153250111),
                            INT64_C(-6043663531296462836), INT64_C(-3201199251206898425),
                            INT64_C(-7517867743898200758), INT64_C( 5023666877462679332)),
      simde_mm256_set_epi64x(INT64_C(-6043663531296462836), INT64_C(-3201199251206898425),
                             INT64_C(-7517867743898200758), INT64_C( 5023666877462679332)),
      simde_mm256_set_epi64x(INT64_C(-6876215301736363293), INT64_C(-2253243373865166954),
                             INT64_C( 5866706473820467911), INT64_C(-1945184283153250111)) },
    { simde_mm512_set_epi64(INT64_C(  135432210503006619), INT64_C(-7059566968128636366),
                            INT64_C(-1295026765047609725), INT64_C( 5447800525707046939),
                            INT64_C( 1419500527032411112), INT64_C( 5424087511148175828),
                            INT64_C(-4780701435803039630), INT64_C( 6069825193561024149)),
      simde_mm256_set_epi64x(INT64_C( 1419500527032411112), INT64_C( 5424087511148175828),
                             INT64_C(-4780701435803039630), INT64_C( 6069825193561024149)),
      simde_mm256_set_epi64x(INT64_C(  135432210503006619), INT64_C(-7059566968128636366),
                             INT64_C(-1295026765047609725), INT64_C( 5447800525707046939)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    r = simde_mm512_extracti64x4_epi64(test_vec[i].a, 0);
    simde_assert_m256i_i64(r, ==, test_vec[i].r0);
    r = simde_mm512_extracti64x4_epi64(test_vec[i].a, 1);
    simde_assert_m256i_i64(r, ==, test_vec[i].r1);
  }

  return 0;
}

static int
test_simde_mm512_mask_extracti64x4_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m256i r0;
    simde__m256i r1;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( 7940316924786767481), INT64_C( 6743600876828439814),
                             INT64_C( 8561828216572109007), INT64_C(-8315109086095518889)),
      UINT8_C( 21),
      simde_mm512_set_epi64(INT64_C(-8586603972668500699), INT64_C( 7848938818320954984),
                            INT64_C(-7002500096438875648), INT64_C( 1477571573764517782),
                            INT64_C( 4086853108457730066), INT64_C(-7738570880062900818),
                            INT64_C(-5609503674875201288), INT64_C( 3966155248134972346)),
      simde_mm256_set_epi64x(INT64_C( 7940316924786767481), INT64_C(-7738570880062900818),
                             INT64_C( 8561828216572109007), INT64_C( 3966155248134972346)),
      simde_mm256_set_epi64x(INT64_C( 7940316924786767481), INT64_C( 7848938818320954984),
                             INT64_C( 8561828216572109007), INT64_C( 1477571573764517782)) },
    { simde_mm256_set_epi64x(INT64_C(-4767707706458520415), INT64_C(-7083171014951853588),
                             INT64_C(-2076988212358998594), INT64_C( 3698505898575972461)),
      UINT8_C(157),
      simde_mm512_set_epi64(INT64_C( 1516975282358243755), INT64_C(-3949523894747321163),
                            INT64_C(-2989078375862773056), INT64_C(-4700117291684372957),
                            INT64_C(-8784413934425613521), INT64_C(  961867877660623168),
                            INT64_C( 2426510480636680010), INT64_C(-6612602987193650875)),
      simde_mm256_set_epi64x(INT64_C(-8784413934425613521), INT64_C(  961867877660623168),
                             INT64_C(-2076988212358998594), INT64_C(-6612602987193650875)),
      simde_mm256_set_epi64x(INT64_C( 1516975282358243755), INT64_C(-3949523894747321163),
                             INT64_C(-2076988212358998594), INT64_C(-4700117291684372957)) },
    { simde_mm256_set_epi64x(INT64_C( 4704994953943345443), INT64_C( 8877610218385468208),
                             INT64_C( 5776984527519295337), INT64_C( 6526937450820584225)),
      UINT8_C( 59),
      simde_mm512_set_epi64(INT64_C( 3898178537456140670), INT64_C( -393151907512138120),
                            INT64_C(  600214805061827669), INT64_C( 3163434753014979248),
                            INT64_C( 3418472134552461373), INT64_C(-6111840559061041971),
                            INT64_C( 6656352319933975670), INT64_C( 2357435311113502667)),
      simde_mm256_set_epi64x(INT64_C( 3418472134552461373), INT64_C( 8877610218385468208),
                             INT64_C( 6656352319933975670), INT64_C( 2357435311113502667)),
      simde_mm256_set_epi64x(INT64_C( 3898178537456140670), INT64_C( 8877610218385468208),
                             INT64_C(  600214805061827669), INT64_C( 3163434753014979248)) },
    { simde_mm256_set_epi64x(INT64_C(-1414228054518303181), INT64_C(-3038909907977133732),
                             INT64_C(-7842471790453318316), INT64_C(-7256600765093102205)),
      UINT8_C(120),
      simde_mm512_set_epi64(INT64_C(-6742373427678247978), INT64_C( 7306080674171373254),
                            INT64_C( 2163582539809461657), INT64_C(-7942896186346970451),
                            INT64_C(-2775611318017263858), INT64_C( 7897714815450887445),
                            INT64_C(-2675129847260557604), INT64_C( 2145911307457407401)),
      simde_mm256_set_epi64x(INT64_C(-2775611318017263858), INT64_C(-3038909907977133732),
                             INT64_C(-7842471790453318316), INT64_C(-7256600765093102205)),
      simde_mm256_set_epi64x(INT64_C(-6742373427678247978), INT64_C(-3038909907977133732),
                             INT64_C(-7842471790453318316), INT64_C(-7256600765093102205)) },
    { simde_mm256_set_epi64x(INT64_C(-8776157931044543560), INT64_C(-1848672680316222475),
                             INT64_C( 1658167909352451238), INT64_C(  377173394815185621)),
      UINT8_C( 22),
      simde_mm512_set_epi64(INT64_C( 3509487153133496527), INT64_C( -438383259974317574),
                            INT64_C( 4679882440059701274), INT64_C( 8594666725077939668),
                            INT64_C(-2603844271228681340), INT64_C( 3101493959844818499),
                            INT64_C(-7569746812758465314), INT64_C(  -95001376835728923)),
      simde_mm256_set_epi64x(INT64_C(-8776157931044543560), INT64_C( 3101493959844818499),
                             INT64_C(-7569746812758465314), INT64_C(  377173394815185621)),
      simde_mm256_set_epi64x(INT64_C(-8776157931044543560), INT64_C( -438383259974317574),
                             INT64_C( 4679882440059701274), INT64_C(  377173394815185621)) },
    { simde_mm256_set_epi64x(INT64_C(  -49705421380794940), INT64_C( 3138707856740708121),
                             INT64_C(-4673519228421997952), INT64_C(-1556073591389999033)),
      UINT8_C( 69),
      simde_mm512_set_epi64(INT64_C(  463621865143519269), INT64_C(-6632828547466581484),
                            INT64_C(-5710868086811856609), INT64_C( 7040443601555103281),
                            INT64_C( 7268860797756174523), INT64_C(  684742770982669497),
                            INT64_C(  778252790359918942), INT64_C( 8946221359026744959)),
      simde_mm256_set_epi64x(INT64_C(  -49705421380794940), INT64_C(  684742770982669497),
                             INT64_C(-4673519228421997952), INT64_C( 8946221359026744959)),
      simde_mm256_set_epi64x(INT64_C(  -49705421380794940), INT64_C(-6632828547466581484),
                             INT64_C(-4673519228421997952), INT64_C( 7040443601555103281)) },
    { simde_mm256_set_epi64x(INT64_C(-8553143016080257248), INT64_C( 1191725626053358671),
                             INT64_C( 2560034487176803702), INT64_C(-4340183042637127984)),
      UINT8_C( 92),
      simde_mm512_set_epi64(INT64_C( -638332694652688568), INT64_C(-8196543121330681227),
                            INT64_C( 7593109912492073141), INT64_C( 6300090425305304893),
                            INT64_C(-3323383259847225301), INT64_C( 2001511420457827007),
                            INT64_C( 8280910196874944184), INT64_C( -368934386460614235)),
      simde_mm256_set_epi64x(INT64_C(-3323383259847225301), INT64_C( 2001511420457827007),
                             INT64_C( 2560034487176803702), INT64_C(-4340183042637127984)),
      simde_mm256_set_epi64x(INT64_C( -638332694652688568), INT64_C(-8196543121330681227),
                             INT64_C( 2560034487176803702), INT64_C(-4340183042637127984)) },
    { simde_mm256_set_epi64x(INT64_C( 7286481320132913626), INT64_C( -777692308098335861),
                             INT64_C( 8727238559278288416), INT64_C(-2736507802934917164)),
      UINT8_C(160),
      simde_mm512_set_epi64(INT64_C(-6023807055599376167), INT64_C( 2056379472574346663),
                            INT64_C(-3486865648830471282), INT64_C( 8151787653682140580),
                            INT64_C( -831601358278995789), INT64_C(-2800664419916301039),
                            INT64_C( 3280702275774868225), INT64_C(-4735905134864699368)),
      simde_mm256_set_epi64x(INT64_C( 7286481320132913626), INT64_C( -777692308098335861),
                             INT64_C( 8727238559278288416), INT64_C(-2736507802934917164)),
      simde_mm256_set_epi64x(INT64_C( 7286481320132913626), INT64_C( -777692308098335861),
                             INT64_C( 8727238559278288416), INT64_C(-2736507802934917164)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    r = simde_mm512_mask_extracti64x4_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a, 0);
    simde_assert_m256i_i64(r, ==, test_vec[i].r0);
    r = simde_mm512_mask_extracti64x4_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a, 1);
    simde_assert_m256i_i64(r, ==, test_vec[i].r1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_extracti64x4_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m256i r0;
    simde__m256i r1;
  } test_vec[8] = {
    { UINT8_C( 87),
      simde_mm512_set_epi64(INT64_C( 4086853108457730066), INT64_C(-7738570880062900818),
                            INT64_C(-5609503674875201288), INT64_C( 3966155248134972346),
                            INT64_C( 6201510655001996332), INT64_C( 7633590894537872708),
                            INT64_C(-5593693910291334810), INT64_C(-8884932670315115433)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 7633590894537872708),
                             INT64_C(-5593693910291334810), INT64_C(-8884932670315115433)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(-7738570880062900818),
                             INT64_C(-5609503674875201288), INT64_C( 3966155248134972346)) },
    { UINT8_C(150),
      simde_mm512_set_epi64(INT64_C( 6143333881204814617), INT64_C( -890089152921238147),
                            INT64_C( 8823574133744668217), INT64_C(-6364969741708969084),
                            INT64_C(-1418976459802394322), INT64_C( 4477375336277674053),
                            INT64_C( 1282248710630285123), INT64_C( 6638105739971879812)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 4477375336277674053),
                             INT64_C( 1282248710630285123), INT64_C(                   0)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( -890089152921238147),
                             INT64_C( 8823574133744668217), INT64_C(                   0)) },
    { UINT8_C( 69),
      simde_mm512_set_epi64(INT64_C(-4369965941555109637), INT64_C( 7350668077567080689),
                            INT64_C( 8478919882954811661), INT64_C(-3394066222784588743),
                            INT64_C(-5009306653852991983), INT64_C(-8749971605870264899),
                            INT64_C( 1212032624670585453), INT64_C(  728623586565902494)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(-8749971605870264899),
                             INT64_C(                   0), INT64_C(  728623586565902494)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 7350668077567080689),
                             INT64_C(                   0), INT64_C(-3394066222784588743)) },
    { UINT8_C(  7),
      simde_mm512_set_epi64(INT64_C(-5506395256633894325), INT64_C( 7391005387705442660),
                            INT64_C(-5091463632259113685), INT64_C(  685405269785004780),
                            INT64_C(-2602517860068074949), INT64_C( 4704994953943345443),
                            INT64_C( 8877610218385468208), INT64_C( 5776984527519295337)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 4704994953943345443),
                             INT64_C( 8877610218385468208), INT64_C( 5776984527519295337)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 7391005387705442660),
                             INT64_C(-5091463632259113685), INT64_C(  685405269785004780)) },
    { UINT8_C( 37),
      simde_mm512_set_epi64(INT64_C(-1117409850830928520), INT64_C(-1414228054518303181),
                            INT64_C(-3038909907977133732), INT64_C(-7842471790453318316),
                            INT64_C(-7256600765093102205), INT64_C( 3898178537456140670),
                            INT64_C( -393151907512138120), INT64_C(  600214805061827669)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 3898178537456140670),
                             INT64_C(                   0), INT64_C(  600214805061827669)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(-1414228054518303181),
                             INT64_C(                   0), INT64_C(-7842471790453318316)) },
    { UINT8_C(246),
      simde_mm512_set_epi64(INT64_C(  377173394815185621), INT64_C(-6742373427678247978),
                            INT64_C( 7306080674171373254), INT64_C( 2163582539809461657),
                            INT64_C(-7942896186346970451), INT64_C(-2775611318017263858),
                            INT64_C( 7897714815450887445), INT64_C(-2675129847260557604)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(-2775611318017263858),
                             INT64_C( 7897714815450887445), INT64_C(                   0)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(-6742373427678247978),
                             INT64_C( 7306080674171373254), INT64_C(                   0)) },
    { UINT8_C(166),
      simde_mm512_set_epi64(INT64_C( 8594666725077939668), INT64_C(-2603844271228681340),
                            INT64_C( 3101493959844818499), INT64_C(-7569746812758465314),
                            INT64_C(  -95001376835728923), INT64_C( 2811174252033921756),
                            INT64_C( 1971701120159461885), INT64_C(-1168609383370522899)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 2811174252033921756),
                             INT64_C( 1971701120159461885), INT64_C(                   0)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(-2603844271228681340),
                             INT64_C( 3101493959844818499), INT64_C(                   0)) },
    { UINT8_C( 26),
      simde_mm512_set_epi64(INT64_C( 8946221359026744959), INT64_C( 8570432854894274862),
                            INT64_C(-4670296842224865750), INT64_C(-8736438908262001915),
                            INT64_C(-1516874692875012272), INT64_C( 2654080637722702840),
                            INT64_C(-4444585746033374017), INT64_C( 7620312646179506248)),
      simde_mm256_set_epi64x(INT64_C(-1516874692875012272), INT64_C(                   0),
                             INT64_C(-4444585746033374017), INT64_C(                   0)),
      simde_mm256_set_epi64x(INT64_C( 8946221359026744959), INT64_C(                   0),
                             INT64_C(-4670296842224865750), INT64_C(                   0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    r = simde_mm512_maskz_extracti64x4_epi64(test_vec[i].k, test_vec[i].a, 0);
    simde_assert_m256i_i64(r, ==, test_vec[i].r0);
    r = simde_mm512_maskz_extracti64x4_epi64(test_vec[i].k, test_vec[i].a, 1);
    simde_assert_m256i_i64(r, ==, test_vec[i].r1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_extractf32x4_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_extractf32x4_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_extractf32x4_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_extractf32x8_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_extractf64x4_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_extractf64x4_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_extractf64x4_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_extracti32x4_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_extracti32x4_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_extracti32x4_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_extracti64x4_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_extracti64x4_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_extracti64x4_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
