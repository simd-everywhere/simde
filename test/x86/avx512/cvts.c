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
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN cvts

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cvts.h>

static int
test_simde_mm_cvtsepi16_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(  -385), INT16_C(-14682), INT16_C(    -6), INT16_C(   418),
                         INT16_C(     0), INT16_C(-24263), INT16_C(-21423), INT16_C(   -13)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(  -6), INT8_C( 127),
                        INT8_C(   0), INT8_C(-128), INT8_C(-128), INT8_C( -13)) },
    { simde_mm_set_epi16(INT16_C(    12), INT16_C( -1449), INT16_C(    -1), INT16_C(    -8),
                         INT16_C(   151), INT16_C(    68), INT16_C(  -857), INT16_C(    -1)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  12), INT8_C(-128), INT8_C(  -1), INT8_C(  -8),
                        INT8_C( 127), INT8_C(  68), INT8_C(-128), INT8_C(  -1)) },
    { simde_mm_set_epi16(INT16_C(  2343), INT16_C(-10678), INT16_C( -7895), INT16_C(-27557),
                         INT16_C(     4), INT16_C(  6853), INT16_C(    -1), INT16_C( -4386)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C(   4), INT8_C( 127), INT8_C(  -1), INT8_C(-128)) },
    { simde_mm_set_epi16(INT16_C(  2603), INT16_C(-10075), INT16_C(     1), INT16_C(    -1),
                         INT16_C(  -267), INT16_C(     0), INT16_C(     0), INT16_C(    -3)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C(   1), INT8_C(  -1),
                        INT8_C(-128), INT8_C(   0), INT8_C(   0), INT8_C(  -3)) },
    { simde_mm_set_epi16(INT16_C(   318), INT16_C(   609), INT16_C(   127), INT16_C(     2),
                         INT16_C(   326), INT16_C(    20), INT16_C(    -1), INT16_C(    -7)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(   2),
                        INT8_C( 127), INT8_C(  20), INT8_C(  -1), INT8_C(  -7)) },
    { simde_mm_set_epi16(INT16_C(   -57), INT16_C(  2093), INT16_C(  3059), INT16_C(    12),
                         INT16_C(    10), INT16_C(   274), INT16_C(    50), INT16_C(    -7)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( -57), INT8_C( 127), INT8_C( 127), INT8_C(  12),
                        INT8_C(  10), INT8_C( 127), INT8_C(  50), INT8_C(  -7)) },
    { simde_mm_set_epi16(INT16_C(     0), INT16_C( -3570), INT16_C(     1), INT16_C(     0),
                         INT16_C(   -36), INT16_C(     0), INT16_C(    54), INT16_C(    -5)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(-128), INT8_C(   1), INT8_C(   0),
                        INT8_C( -36), INT8_C(   0), INT8_C(  54), INT8_C(  -5)) },
    { simde_mm_set_epi16(INT16_C(    54), INT16_C(    92), INT16_C(     2), INT16_C(   185),
                         INT16_C(     4), INT16_C(  1983), INT16_C(  2567), INT16_C(   136)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  54), INT8_C(  92), INT8_C(   2), INT8_C( 127),
                        INT8_C(   4), INT8_C( 127), INT8_C( 127), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsepi16_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_cvtsepi16_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(   447), INT16_C( -3887), INT16_C(     9), INT16_C(  6277),
                            INT16_C(     2), INT16_C(  -314), INT16_C(  1617), INT16_C(    64),
                            INT16_C(     0), INT16_C(  1725), INT16_C(   801), INT16_C(    -2),
                            INT16_C(  -782), INT16_C(  -381), INT16_C(     0), INT16_C(    -1)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C(   9), INT8_C( 127),
                        INT8_C(   2), INT8_C(-128), INT8_C( 127), INT8_C(  64),
                        INT8_C(   0), INT8_C( 127), INT8_C( 127), INT8_C(  -2),
                        INT8_C(-128), INT8_C(-128), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm256_set_epi16(INT16_C( -1378), INT16_C(     1), INT16_C(  2482), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -2), INT16_C(  -107), INT16_C(  7074),
                            INT16_C(  -117), INT16_C(  3648), INT16_C(   -25), INT16_C(  -225),
                            INT16_C(   587), INT16_C(    15), INT16_C(   116), INT16_C(    -1)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C(   1), INT8_C( 127), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -2), INT8_C(-107), INT8_C( 127),
                        INT8_C(-117), INT8_C( 127), INT8_C( -25), INT8_C(-128),
                        INT8_C( 127), INT8_C(  15), INT8_C( 116), INT8_C(  -1)) },
    { simde_mm256_set_epi16(INT16_C(  -602), INT16_C( 22836), INT16_C(   -36), INT16_C(  -417),
                            INT16_C(  7314), INT16_C(  -135), INT16_C(     1), INT16_C( -1693),
                            INT16_C(  -121), INT16_C(  -342), INT16_C(     7), INT16_C(  3079),
                            INT16_C(    14), INT16_C(    56), INT16_C(   -16), INT16_C(   -10)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C( -36), INT8_C(-128),
                        INT8_C( 127), INT8_C(-128), INT8_C(   1), INT8_C(-128),
                        INT8_C(-121), INT8_C(-128), INT8_C(   7), INT8_C( 127),
                        INT8_C(  14), INT8_C(  56), INT8_C( -16), INT8_C( -10)) },
    { simde_mm256_set_epi16(INT16_C(  -171), INT16_C(   138), INT16_C(   235), INT16_C(    33),
                            INT16_C(   102), INT16_C(    -4), INT16_C(     2), INT16_C(   461),
                            INT16_C(   -30), INT16_C(  -120), INT16_C(    34), INT16_C(     1),
                            INT16_C(  1637), INT16_C(     2), INT16_C(     2), INT16_C(    -2)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(  33),
                        INT8_C( 102), INT8_C(  -4), INT8_C(   2), INT8_C( 127),
                        INT8_C( -30), INT8_C(-120), INT8_C(  34), INT8_C(   1),
                        INT8_C( 127), INT8_C(   2), INT8_C(   2), INT8_C(  -2)) },
    { simde_mm256_set_epi16(INT16_C(    -3), INT16_C(     0), INT16_C(-16994), INT16_C(   475),
                            INT16_C(     1), INT16_C(  5629), INT16_C(   -14), INT16_C(     3),
                            INT16_C( -1612), INT16_C(  2680), INT16_C(  -183), INT16_C(  -202),
                            INT16_C(     0), INT16_C(  -114), INT16_C( 11175), INT16_C(    -3)),
      simde_mm_set_epi8(INT8_C(  -3), INT8_C(   0), INT8_C(-128), INT8_C( 127),
                        INT8_C(   1), INT8_C( 127), INT8_C( -14), INT8_C(   3),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128),
                        INT8_C(   0), INT8_C(-114), INT8_C( 127), INT8_C(  -3)) },
    { simde_mm256_set_epi16(INT16_C(   -62), INT16_C(   -29), INT16_C(   -13), INT16_C(     0),
                            INT16_C(    -4), INT16_C(     6), INT16_C(    21), INT16_C(    -2),
                            INT16_C(   -55), INT16_C(     5), INT16_C( -7030), INT16_C(-31314),
                            INT16_C(    65), INT16_C( -7656), INT16_C(   -53), INT16_C(   -12)),
      simde_mm_set_epi8(INT8_C( -62), INT8_C( -29), INT8_C( -13), INT8_C(   0),
                        INT8_C(  -4), INT8_C(   6), INT8_C(  21), INT8_C(  -2),
                        INT8_C( -55), INT8_C(   5), INT8_C(-128), INT8_C(-128),
                        INT8_C(  65), INT8_C(-128), INT8_C( -53), INT8_C( -12)) },
    { simde_mm256_set_epi16(INT16_C(   -52), INT16_C(   250), INT16_C(    -4), INT16_C(   163),
                            INT16_C(    -1), INT16_C(   -72), INT16_C(  -689), INT16_C(   -98),
                            INT16_C(    -1), INT16_C(    27), INT16_C(-29046), INT16_C(   504),
                            INT16_C(     1), INT16_C(  -668), INT16_C(     6), INT16_C(  -130)),
      simde_mm_set_epi8(INT8_C( -52), INT8_C( 127), INT8_C(  -4), INT8_C( 127),
                        INT8_C(  -1), INT8_C( -72), INT8_C(-128), INT8_C( -98),
                        INT8_C(  -1), INT8_C(  27), INT8_C(-128), INT8_C( 127),
                        INT8_C(   1), INT8_C(-128), INT8_C(   6), INT8_C(-128)) },
    { simde_mm256_set_epi16(INT16_C(  3869), INT16_C(    -3), INT16_C(  3307), INT16_C(    -5),
                            INT16_C(   -61), INT16_C(    -5), INT16_C(   -43), INT16_C( -7512),
                            INT16_C(   226), INT16_C(    75), INT16_C(     0), INT16_C(    -1),
                            INT16_C(  1923), INT16_C(   -25), INT16_C(  4919), INT16_C(    -1)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(  -3), INT8_C( 127), INT8_C(  -5),
                        INT8_C( -61), INT8_C(  -5), INT8_C( -43), INT8_C(-128),
                        INT8_C( 127), INT8_C(  75), INT8_C(   0), INT8_C(  -1),
                        INT8_C( 127), INT8_C( -25), INT8_C( 127), INT8_C(  -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvtsepi16_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsepi32_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
        { simde_mm_set_epi32(INT32_C(-2145190814), INT32_C(  369095719), INT32_C(   35558368), INT32_C( -760875473)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi32(INT32_C( -891201105), INT32_C( 2065808871), INT32_C(  421929391), INT32_C(  587313056)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( 127)) },
    { simde_mm_set_epi32(INT32_C(-1908802801), INT32_C( -442332083), INT32_C(-1878740578), INT32_C(-1559213492)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_epi32(INT32_C(  615110155), INT32_C( -809405494), INT32_C( 1459512749), INT32_C( -889064834)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi32(INT32_C( -125398563), INT32_C( 1544839586), INT32_C(  657472508), INT32_C( -763651133)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi32(INT32_C( 1244639853), INT32_C(-1576601619), INT32_C(  458581376), INT32_C(-1764676112)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi32(INT32_C(-1516069112), INT32_C( 1985219066), INT32_C(  436268231), INT32_C( -342699987)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi32(INT32_C( -672406129), INT32_C( 1062677939), INT32_C(   54896059), INT32_C( -667800710)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(-128)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsepi32_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_cvtsepi32_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1740492550), INT32_C(  140736582), INT32_C( -304624647), INT32_C( 1856868246),
                            INT32_C(-1035207889), INT32_C( -259975534), INT32_C(  927209588), INT32_C( -783560978)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm256_set_epi32(INT32_C( 1448477867), INT32_C(-1308743699), INT32_C(-2012880494), INT32_C(-1194643628),
                            INT32_C(   66901057), INT32_C( 1866223729), INT32_C( 1843270593), INT32_C(-1834364931)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(-128)) },
    { simde_mm256_set_epi32(INT32_C( -227624299), INT32_C(  620224848), INT32_C(-1588616610), INT32_C( -511683185),
                            INT32_C(  -58755612), INT32_C(  729520635), INT32_C(-1442538979), INT32_C( -899237550)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128)) },
    { simde_mm256_set_epi32(INT32_C(-1758822725), INT32_C(  -49856508), INT32_C(-1924985834), INT32_C(   33750707),
                            INT32_C(-1943493798), INT32_C( -295278060), INT32_C(  589269723), INT32_C(  667584093)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C( 127)) },
    { simde_mm256_set_epi32(INT32_C(  675031972), INT32_C(-2141215046), INT32_C( 2136698513), INT32_C(-1948084218),
                            INT32_C( -864097131), INT32_C( -578863840), INT32_C( 1120830480), INT32_C(-1905153237)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm256_set_epi32(INT32_C(-1013885891), INT32_C( 2044207481), INT32_C( -247026840), INT32_C( 1877771374),
                            INT32_C(  239002947), INT32_C(  331448889), INT32_C( 1715894971), INT32_C(-1281958023)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(-128)) },
    { simde_mm256_set_epi32(INT32_C(  -97799786), INT32_C( -153068806), INT32_C( 1991567237), INT32_C(  909652836),
                            INT32_C( 1381550522), INT32_C(  725653218), INT32_C(-1527531673), INT32_C( 1671453787)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C( 127)) },
    { simde_mm256_set_epi32(INT32_C( 1505264140), INT32_C( -659446700), INT32_C( -504294088), INT32_C( -895465708),
                            INT32_C( -790990314), INT32_C(-2012027711), INT32_C(  606981184), INT32_C( -261121366)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvtsepi32_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsepi32_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  115673074), INT32_C(-1486060937), INT32_C( -104167420), INT32_C(   40162333)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C(-2128159397), INT32_C(-1560280329), INT32_C(  394598915), INT32_C(  425183512)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C( -746969032), INT32_C( -718350441), INT32_C( -917354043), INT32_C( -740787295)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm_set_epi32(INT32_C( 1489645447), INT32_C(  206085999), INT32_C(-1252698771), INT32_C( 1551612893)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C( -503631451), INT32_C( -997616848), INT32_C( -691694514), INT32_C( -383740168)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm_set_epi32(INT32_C(-1905774960), INT32_C(   -8801329), INT32_C( 1184144481), INT32_C( 1001484550)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767)) },
    { simde_mm_set_epi32(INT32_C( 1461694678), INT32_C( 2088398452), INT32_C(-1522574509), INT32_C(-1848551844)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm_set_epi32(INT32_C(  344147543), INT32_C( 1208328320), INT32_C(  846887925), INT32_C(-1224326570)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsepi32_epi16(test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_cvtsepi32_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(  293632982), INT32_C( -353952507), INT32_C( -369979604), INT32_C(-1836849217),
                            INT32_C( -251503260), INT32_C(-1183044723), INT32_C(-1145018690), INT32_C( 1658446911)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768),
                         INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm256_set_epi32(INT32_C( 2004115928), INT32_C(-2131417756), INT32_C(  420074936), INT32_C(  696094435),
                            INT32_C(-1971968852), INT32_C( 1786370502), INT32_C(-1223946451), INT32_C( 1160235100)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767),
                         INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm256_set_epi32(INT32_C(  275993791), INT32_C( -287244774), INT32_C(-1437747171), INT32_C(  389173048),
                            INT32_C(  902365137), INT32_C( 1626837983), INT32_C( -529930026), INT32_C( -839513231)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm256_set_epi32(INT32_C(  105733041), INT32_C( 1860469307), INT32_C( -229572975), INT32_C( 1382662419),
                            INT32_C( 1098864098), INT32_C( -335162889), INT32_C( -180211643), INT32_C(-1043436692)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767),
                         INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm256_set_epi32(INT32_C(  891400005), INT32_C(-1094002629), INT32_C( -334052966), INT32_C( 1506672550),
                            INT32_C( 1278355339), INT32_C(   30990556), INT32_C(-1937540327), INT32_C( 1090305372)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm256_set_epi32(INT32_C(  756031161), INT32_C( -626600217), INT32_C( -910464378), INT32_C( 1938343335),
                            INT32_C( -214510069), INT32_C( 2030441734), INT32_C(  196869826), INT32_C( 1790672058)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                         INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767)) },
    { simde_mm256_set_epi32(INT32_C( 1995451372), INT32_C(-1306372252), INT32_C(-1445161199), INT32_C(-1208121843),
                            INT32_C(  -34821446), INT32_C(-1602733180), INT32_C( -116240092), INT32_C( -493988056)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768),
                         INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm256_set_epi32(INT32_C( -324372118), INT32_C( 1343179053), INT32_C( -573491227), INT32_C(-1553210763),
                            INT32_C(-1920172306), INT32_C(-1677417189), INT32_C(  982179672), INT32_C(-2112317112)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768),
                         INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvtsepi32_epi16(test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cvtsepi64_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-7549065086020638499), INT64_C(-3321927609022761093)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_epi64x(INT64_C(-4277312397687066005), INT64_C( 2320456666692343657)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi64x(INT64_C( -103344442256467696), INT64_C( 2955664840703358830)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi64x(INT64_C( 5268893576481852159), INT64_C(-9185651458279974860)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi64x(INT64_C(-5896269746913404379), INT64_C( 7979713383766604250)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi64x(INT64_C(-2336810237452023823), INT64_C(-3290098590496967741)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_epi64x(INT64_C(-7739538779128774601), INT64_C( 8105208141968845994)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi64x(INT64_C( -871381348062974225), INT64_C( 3367136188494551863)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C( 127)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsepi64_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_cvtsepi64_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( 7571764882458171438), INT64_C(-5921591509803744983),
                             INT64_C( 6658090239555345361), INT64_C(-2357401607469764832)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm256_set_epi64x(INT64_C(-7394691671820149099), INT64_C(-5986584038912522225),
                             INT64_C(-6456224054777082128), INT64_C(-1619710544369908736)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(-128)) },
    { simde_mm256_set_epi64x(INT64_C(  253771227790268661), INT64_C(-8177257137918582254),
                             INT64_C( 9193080332106867266), INT64_C(-7500787245705959716)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm256_set_epi64x(INT64_C( -378633448466384692), INT64_C( 8377241746990476361),
                             INT64_C(-3577751476639945070), INT64_C( 3071274498813504095)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127)) },
    { simde_mm256_set_epi64x(INT64_C( 6831871583847420748), INT64_C( 3270263401510298982),
                             INT64_C( 7119350019975334051), INT64_C( 2198565260202909270)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C( 127)) },
    { simde_mm256_set_epi64x(INT64_C( 1387880433219135865), INT64_C( 3250534069269084917),
                             INT64_C(-1277711946882622375), INT64_C(-5810920510833024903)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-128)) },
    { simde_mm256_set_epi64x(INT64_C(-3285074807695571420), INT64_C(-5576331776659409304),
                             INT64_C( 3478574654500178090), INT64_C( 7240016417068788730)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C( 127)) },
    { simde_mm256_set_epi64x(INT64_C( -444210268504052724), INT64_C(-1278644105244443763),
                             INT64_C(-1392943174058285672), INT64_C( 6768383435631406852)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvtsepi64_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cvtsepi16_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
        { simde_mm512_set_epi16(INT16_C(  8002), INT16_C(   -42), INT16_C(   317), INT16_C(     3),
                            INT16_C(     2), INT16_C(    22), INT16_C(     2), INT16_C(   102),
                            INT16_C(     0), INT16_C(   130), INT16_C(   297), INT16_C(  4068),
                            INT16_C(  -202), INT16_C(  4593), INT16_C(  1545), INT16_C(    -2),
                            INT16_C( -4392), INT16_C( -3947), INT16_C(   301), INT16_C(-11526),
                            INT16_C(    -1), INT16_C(     1), INT16_C(  -437), INT16_C(     4),
                            INT16_C(  -139), INT16_C( -4859), INT16_C(    -1), INT16_C(    12),
                            INT16_C(  -591), INT16_C(   -40), INT16_C(  -269), INT16_C(   -24)),
      simde_mm256_set_epi8(INT8_C( 127), INT8_C( -42), INT8_C( 127), INT8_C(   3),
                           INT8_C(   2), INT8_C(  22), INT8_C(   2), INT8_C( 102),
                           INT8_C(   0), INT8_C( 127), INT8_C( 127), INT8_C( 127),
                           INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(  -2),
                           INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                           INT8_C(  -1), INT8_C(   1), INT8_C(-128), INT8_C(   4),
                           INT8_C(-128), INT8_C(-128), INT8_C(  -1), INT8_C(  12),
                           INT8_C(-128), INT8_C( -40), INT8_C(-128), INT8_C( -24)) },
    { simde_mm512_set_epi16(INT16_C(     2), INT16_C(    49), INT16_C(     2), INT16_C(   131),
                            INT16_C(     1), INT16_C(-15743), INT16_C(  1984), INT16_C(     9),
                            INT16_C(-20648), INT16_C( -5458), INT16_C(    -1), INT16_C(    -1),
                            INT16_C( -3713), INT16_C(   -60), INT16_C( -1328), INT16_C(     4),
                            INT16_C(   150), INT16_C(    -8), INT16_C(  1864), INT16_C(   -14),
                            INT16_C(    20), INT16_C(   194), INT16_C(     0), INT16_C(  5954),
                            INT16_C(   -13), INT16_C(  -288), INT16_C(  3162), INT16_C(     1),
                            INT16_C(    14), INT16_C(  2628), INT16_C(    -1), INT16_C(    -8)),
      simde_mm256_set_epi8(INT8_C(   2), INT8_C(  49), INT8_C(   2), INT8_C( 127),
                           INT8_C(   1), INT8_C(-128), INT8_C( 127), INT8_C(   9),
                           INT8_C(-128), INT8_C(-128), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(-128), INT8_C( -60), INT8_C(-128), INT8_C(   4),
                           INT8_C( 127), INT8_C(  -8), INT8_C( 127), INT8_C( -14),
                           INT8_C(  20), INT8_C( 127), INT8_C(   0), INT8_C( 127),
                           INT8_C( -13), INT8_C(-128), INT8_C( 127), INT8_C(   1),
                           INT8_C(  14), INT8_C( 127), INT8_C(  -1), INT8_C(  -8)) },
    { simde_mm512_set_epi16(INT16_C(  -562), INT16_C(    -4), INT16_C( 14830), INT16_C( 23439),
                            INT16_C(  -872), INT16_C(     2), INT16_C(  -152), INT16_C(    42),
                            INT16_C( 23882), INT16_C(    -7), INT16_C(-27326), INT16_C(  5025),
                            INT16_C(  7663), INT16_C(-14858), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    27), INT16_C(     3), INT16_C(    -6), INT16_C(    54),
                            INT16_C(   -16), INT16_C(  -120), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    50), INT16_C(    -3), INT16_C(     1), INT16_C(  -128),
                            INT16_C( -6425), INT16_C(     1), INT16_C(    -1), INT16_C(  -167)),
      simde_mm256_set_epi8(INT8_C(-128), INT8_C(  -4), INT8_C( 127), INT8_C( 127),
                           INT8_C(-128), INT8_C(   2), INT8_C(-128), INT8_C(  42),
                           INT8_C( 127), INT8_C(  -7), INT8_C(-128), INT8_C( 127),
                           INT8_C( 127), INT8_C(-128), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  27), INT8_C(   3), INT8_C(  -6), INT8_C(  54),
                           INT8_C( -16), INT8_C(-120), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  50), INT8_C(  -3), INT8_C(   1), INT8_C(-128),
                           INT8_C(-128), INT8_C(   1), INT8_C(  -1), INT8_C(-128)) },
    { simde_mm512_set_epi16(INT16_C(   117), INT16_C(    75), INT16_C(   -56), INT16_C(    -1),
                            INT16_C(    53), INT16_C(  -283), INT16_C(   138), INT16_C(     3),
                            INT16_C(    -1), INT16_C(  6705), INT16_C(   138), INT16_C( -3521),
                            INT16_C(    22), INT16_C(  1779), INT16_C(  2888), INT16_C(    -1),
                            INT16_C(  -189), INT16_C( 17712), INT16_C(   -18), INT16_C(   923),
                            INT16_C(     1), INT16_C(     1), INT16_C(  2605), INT16_C(   353),
                            INT16_C(   201), INT16_C(  -120), INT16_C(-28865), INT16_C(   -13),
                            INT16_C(  -701), INT16_C(   945), INT16_C( -2270), INT16_C(     0)),
      simde_mm256_set_epi8(INT8_C( 117), INT8_C(  75), INT8_C( -56), INT8_C(  -1),
                           INT8_C(  53), INT8_C(-128), INT8_C( 127), INT8_C(   3),
                           INT8_C(  -1), INT8_C( 127), INT8_C( 127), INT8_C(-128),
                           INT8_C(  22), INT8_C( 127), INT8_C( 127), INT8_C(  -1),
                           INT8_C(-128), INT8_C( 127), INT8_C( -18), INT8_C( 127),
                           INT8_C(   1), INT8_C(   1), INT8_C( 127), INT8_C( 127),
                           INT8_C( 127), INT8_C(-120), INT8_C(-128), INT8_C( -13),
                           INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(   0)) },
    { simde_mm512_set_epi16(INT16_C(   127), INT16_C(   406), INT16_C(    74), INT16_C(    -2),
                            INT16_C(   -12), INT16_C(   196), INT16_C(    -4), INT16_C( -4852),
                            INT16_C(    38), INT16_C(   -10), INT16_C(  -408), INT16_C(   453),
                            INT16_C( -6833), INT16_C(    37), INT16_C( -3464), INT16_C(    -2),
                            INT16_C(  -488), INT16_C(     0), INT16_C(   643), INT16_C(     6),
                            INT16_C(    51), INT16_C(     0), INT16_C(    -4), INT16_C(    -1),
                            INT16_C(-14928), INT16_C(   -46), INT16_C(    58), INT16_C(    -3),
                            INT16_C(     0), INT16_C(  -343), INT16_C(-10019), INT16_C(     0)),
      simde_mm256_set_epi8(INT8_C( 127), INT8_C( 127), INT8_C(  74), INT8_C(  -2),
                           INT8_C( -12), INT8_C( 127), INT8_C(  -4), INT8_C(-128),
                           INT8_C(  38), INT8_C( -10), INT8_C(-128), INT8_C( 127),
                           INT8_C(-128), INT8_C(  37), INT8_C(-128), INT8_C(  -2),
                           INT8_C(-128), INT8_C(   0), INT8_C( 127), INT8_C(   6),
                           INT8_C(  51), INT8_C(   0), INT8_C(  -4), INT8_C(  -1),
                           INT8_C(-128), INT8_C( -46), INT8_C(  58), INT8_C(  -3),
                           INT8_C(   0), INT8_C(-128), INT8_C(-128), INT8_C(   0)) },
    { simde_mm512_set_epi16(INT16_C(    -1), INT16_C(  -378), INT16_C(  3797), INT16_C(     1),
                            INT16_C(   -61), INT16_C( -6468), INT16_C(     0), INT16_C(-18745),
                            INT16_C(     3), INT16_C(    -5), INT16_C(    -1), INT16_C(  4066),
                            INT16_C(    -1), INT16_C(   -11), INT16_C(    -2), INT16_C(   881),
                            INT16_C(  -116), INT16_C(    22), INT16_C(     1), INT16_C( -1127),
                            INT16_C(    15), INT16_C(  2276), INT16_C(  -149), INT16_C(  7345),
                            INT16_C(   850), INT16_C(   -84), INT16_C(    -2), INT16_C(     0),
                            INT16_C(    -6), INT16_C( -3696), INT16_C(    -2), INT16_C(  2136)),
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C(-128), INT8_C( 127), INT8_C(   1),
                           INT8_C( -61), INT8_C(-128), INT8_C(   0), INT8_C(-128),
                           INT8_C(   3), INT8_C(  -5), INT8_C(  -1), INT8_C( 127),
                           INT8_C(  -1), INT8_C( -11), INT8_C(  -2), INT8_C( 127),
                           INT8_C(-116), INT8_C(  22), INT8_C(   1), INT8_C(-128),
                           INT8_C(  15), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                           INT8_C( 127), INT8_C( -84), INT8_C(  -2), INT8_C(   0),
                           INT8_C(  -6), INT8_C(-128), INT8_C(  -2), INT8_C( 127)) },
    { simde_mm512_set_epi16(INT16_C(  -368), INT16_C( -1403), INT16_C(   -10), INT16_C(  2787),
                            INT16_C(  6145), INT16_C(  -228), INT16_C(  2519), INT16_C(    -1),
                            INT16_C(  -244), INT16_C(    10), INT16_C(    14), INT16_C(   113),
                            INT16_C(    23), INT16_C(     1), INT16_C( 21613), INT16_C(    -2),
                            INT16_C(    -2), INT16_C(   -29), INT16_C(  9866), INT16_C(   356),
                            INT16_C(  -254), INT16_C(   -21), INT16_C(     9), INT16_C(     9),
                            INT16_C(   249), INT16_C(  3052), INT16_C( -8880), INT16_C(     7),
                            INT16_C(     0), INT16_C( -4602), INT16_C( -8839), INT16_C( 18288)),
      simde_mm256_set_epi8(INT8_C(-128), INT8_C(-128), INT8_C( -10), INT8_C( 127),
                           INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(  -1),
                           INT8_C(-128), INT8_C(  10), INT8_C(  14), INT8_C( 113),
                           INT8_C(  23), INT8_C(   1), INT8_C( 127), INT8_C(  -2),
                           INT8_C(  -2), INT8_C( -29), INT8_C( 127), INT8_C( 127),
                           INT8_C(-128), INT8_C( -21), INT8_C(   9), INT8_C(   9),
                           INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(   7),
                           INT8_C(   0), INT8_C(-128), INT8_C(-128), INT8_C( 127)) },
    { simde_mm512_set_epi16(INT16_C(   502), INT16_C(    22), INT16_C(    -4), INT16_C(     1),
                            INT16_C(     2), INT16_C( -1148), INT16_C(     1), INT16_C(     8),
                            INT16_C(    25), INT16_C(  8616), INT16_C(    -1), INT16_C(     0),
                            INT16_C(  1091), INT16_C(  -370), INT16_C(     0), INT16_C(    -1),
                            INT16_C( -1549), INT16_C(    12), INT16_C(    -2), INT16_C(     4),
                            INT16_C( -3952), INT16_C(  1681), INT16_C(     3), INT16_C(    35),
                            INT16_C(    -6), INT16_C(     0), INT16_C(    -2), INT16_C(    51),
                            INT16_C(     0), INT16_C(  3760), INT16_C(    -1), INT16_C(    -1)),
      simde_mm256_set_epi8(INT8_C( 127), INT8_C(  22), INT8_C(  -4), INT8_C(   1),
                           INT8_C(   2), INT8_C(-128), INT8_C(   1), INT8_C(   8),
                           INT8_C(  25), INT8_C( 127), INT8_C(  -1), INT8_C(   0),
                           INT8_C( 127), INT8_C(-128), INT8_C(   0), INT8_C(  -1),
                           INT8_C(-128), INT8_C(  12), INT8_C(  -2), INT8_C(   4),
                           INT8_C(-128), INT8_C( 127), INT8_C(   3), INT8_C(  35),
                           INT8_C(  -6), INT8_C(   0), INT8_C(  -2), INT8_C(  51),
                           INT8_C(   0), INT8_C( 127), INT8_C(  -1), INT8_C(  -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_cvtsepi16_epi8(test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cvtsepi16_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i src;
    simde__mmask32 k;
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( -40), INT8_C(  93), INT8_C( -64), INT8_C( 127),
                           INT8_C(-121), INT8_C( -33), INT8_C( -51), INT8_C(  86),
                           INT8_C(-123), INT8_C(-117), INT8_C(-108), INT8_C( -18),
                           INT8_C(  37), INT8_C(  26), INT8_C( -88), INT8_C(  80),
                           INT8_C(  30), INT8_C(  81), INT8_C(-126), INT8_C( 115),
                           INT8_C(-113), INT8_C(  80), INT8_C( -70), INT8_C(  14),
                           INT8_C(  67), INT8_C(-122), INT8_C( -52), INT8_C( -49),
                           INT8_C( -61), INT8_C( -10), INT8_C( -10), INT8_C(   9)),
      UINT32_C(   9464246),
      simde_mm512_set_epi16(INT16_C(  2661), INT16_C(  8241), INT16_C(-31365), INT16_C(-28794),
                            INT16_C( 31420), INT16_C(  5279), INT16_C(-11307), INT16_C(  8621),
                            INT16_C( 25450), INT16_C(-29219), INT16_C(  7142), INT16_C(  6454),
                            INT16_C( 22666), INT16_C( 22972), INT16_C( 22678), INT16_C(-10349),
                            INT16_C( 26453), INT16_C(-25565), INT16_C(-27471), INT16_C(-25692),
                            INT16_C( 24633), INT16_C(-12996), INT16_C( -7464), INT16_C(  6163),
                            INT16_C(-14301), INT16_C(  4709), INT16_C( 31142), INT16_C(-11353),
                            INT16_C(-11078), INT16_C( -7297), INT16_C( -6389), INT16_C(-27388)),
      simde_mm256_set_epi8(INT8_C( -40), INT8_C(  93), INT8_C( -64), INT8_C( 127),
                           INT8_C(-121), INT8_C( -33), INT8_C( -51), INT8_C(  86),
                           INT8_C( 127), INT8_C(-117), INT8_C(-108), INT8_C( 127),
                           INT8_C(  37), INT8_C(  26), INT8_C( -88), INT8_C(  80),
                           INT8_C(  30), INT8_C(-128), INT8_C(-128), INT8_C( 115),
                           INT8_C( 127), INT8_C(  80), INT8_C( -70), INT8_C( 127),
                           INT8_C(-128), INT8_C(-122), INT8_C( 127), INT8_C(-128),
                           INT8_C( -61), INT8_C(-128), INT8_C(-128), INT8_C(   9)) },
    { simde_mm256_set_epi8(INT8_C(-127), INT8_C(  79), INT8_C( -17), INT8_C( -57),
                           INT8_C(  84), INT8_C(  25), INT8_C( -42), INT8_C( -98),
                           INT8_C( -48), INT8_C( -88), INT8_C(  64), INT8_C(-126),
                           INT8_C(  55), INT8_C(  85), INT8_C(  23), INT8_C( 101),
                           INT8_C(  98), INT8_C( -22), INT8_C(  51), INT8_C(  32),
                           INT8_C( -91), INT8_C(  43), INT8_C( 124), INT8_C( -87),
                           INT8_C( -45), INT8_C( 117), INT8_C( -35), INT8_C(  88),
                           INT8_C(  36), INT8_C(  62), INT8_C( -51), INT8_C(  54)),
      UINT32_C(  16139739),
      simde_mm512_set_epi16(INT16_C( 29247), INT16_C( -8471), INT16_C( -1085), INT16_C( 30870),
                            INT16_C( 25891), INT16_C(-21158), INT16_C( 12488), INT16_C( -6908),
                            INT16_C( -1323), INT16_C(-29158), INT16_C( 19744), INT16_C( -9433),
                            INT16_C( 32012), INT16_C(-30047), INT16_C( 12083), INT16_C(  5703),
                            INT16_C(-23507), INT16_C(  9265), INT16_C(  9307), INT16_C( 19873),
                            INT16_C( -2618), INT16_C( -1149), INT16_C( 18681), INT16_C(  7098),
                            INT16_C(-13814), INT16_C( 19632), INT16_C(-21387), INT16_C(-19281),
                            INT16_C(-23963), INT16_C(-20730), INT16_C(-32754), INT16_C(-15371)),
      simde_mm256_set_epi8(INT8_C(-127), INT8_C(  79), INT8_C( -17), INT8_C( -57),
                           INT8_C(  84), INT8_C(  25), INT8_C( -42), INT8_C( -98),
                           INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                           INT8_C(  55), INT8_C(-128), INT8_C( 127), INT8_C( 101),
                           INT8_C(  98), INT8_C( 127), INT8_C(  51), INT8_C(  32),
                           INT8_C( -91), INT8_C(-128), INT8_C( 124), INT8_C( 127),
                           INT8_C(-128), INT8_C( 127), INT8_C( -35), INT8_C(-128),
                           INT8_C(-128), INT8_C(  62), INT8_C(-128), INT8_C(-128)) },
    { simde_mm256_set_epi8(INT8_C(-113), INT8_C( -29), INT8_C( -74), INT8_C(-125),
                           INT8_C(  84), INT8_C( 106), INT8_C(-102), INT8_C(-121),
                           INT8_C(-106), INT8_C(   7), INT8_C(  31), INT8_C( -22),
                           INT8_C(   0), INT8_C( -95), INT8_C( -48), INT8_C(-118),
                           INT8_C(  70), INT8_C( -51), INT8_C(  81), INT8_C( -73),
                           INT8_C(   6), INT8_C( -50), INT8_C( -28), INT8_C(-105),
                           INT8_C(  13), INT8_C( -36), INT8_C( 105), INT8_C( -99),
                           INT8_C( -94), INT8_C( -98), INT8_C( -55), INT8_C( 107)),
      UINT32_C(    885729),
      simde_mm512_set_epi16(INT16_C( 27294), INT16_C( 16674), INT16_C( -5346), INT16_C(-13180),
                            INT16_C( -6683), INT16_C( 30235), INT16_C(-31280), INT16_C( -5669),
                            INT16_C( 12288), INT16_C(-24546), INT16_C(  9831), INT16_C(-31819),
                            INT16_C( 14268), INT16_C(-17608), INT16_C(  4735), INT16_C( 29092),
                            INT16_C(  3348), INT16_C( 20490), INT16_C(  9048), INT16_C(-14230),
                            INT16_C(-24731), INT16_C(-20916), INT16_C( 15138), INT16_C( 30554),
                            INT16_C( 12356), INT16_C(-12154), INT16_C( -1803), INT16_C( -2954),
                            INT16_C( -6857), INT16_C( -6626), INT16_C(-23034), INT16_C( 23374)),
      simde_mm256_set_epi8(INT8_C(-113), INT8_C( -29), INT8_C( -74), INT8_C(-125),
                           INT8_C(  84), INT8_C( 106), INT8_C(-102), INT8_C(-121),
                           INT8_C(-106), INT8_C(   7), INT8_C(  31), INT8_C( -22),
                           INT8_C( 127), INT8_C(-128), INT8_C( -48), INT8_C( 127),
                           INT8_C( 127), INT8_C( -51), INT8_C(  81), INT8_C( -73),
                           INT8_C(   6), INT8_C( -50), INT8_C( 127), INT8_C( 127),
                           INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( -99),
                           INT8_C( -94), INT8_C( -98), INT8_C( -55), INT8_C( 127)) },
    { simde_mm256_set_epi8(INT8_C( 106), INT8_C( 125), INT8_C(  -9), INT8_C( -42),
                           INT8_C(  10), INT8_C( -67), INT8_C( -69), INT8_C( -15),
                           INT8_C(-128), INT8_C( -93), INT8_C( -51), INT8_C(  63),
                           INT8_C( -48), INT8_C( -19), INT8_C( -88), INT8_C(   0),
                           INT8_C(  21), INT8_C(-113), INT8_C(  68), INT8_C(  50),
                           INT8_C(  14), INT8_C( -17), INT8_C( -38), INT8_C(  21),
                           INT8_C(  68), INT8_C(  38), INT8_C( -14), INT8_C(-115),
                           INT8_C(  96), INT8_C( -92), INT8_C( -38), INT8_C(  61)),
      UINT32_C(  14868571),
      simde_mm512_set_epi16(INT16_C( -4902), INT16_C(-30912), INT16_C( -9873), INT16_C( -3317),
                            INT16_C( 28529), INT16_C( 10810), INT16_C( 14756), INT16_C(-11980),
                            INT16_C(  8230), INT16_C( 14663), INT16_C(-28044), INT16_C( 14810),
                            INT16_C(  3087), INT16_C( 22573), INT16_C(-19115), INT16_C( 26647),
                            INT16_C(  3404), INT16_C(-13826), INT16_C( 16604), INT16_C( 11097),
                            INT16_C( 31149), INT16_C(-30463), INT16_C(-25032), INT16_C(-30305),
                            INT16_C( 14499), INT16_C(-27532), INT16_C(-28183), INT16_C( 13580),
                            INT16_C( 32147), INT16_C(-28462), INT16_C( 24823), INT16_C( 22687)),
      simde_mm256_set_epi8(INT8_C( 106), INT8_C( 125), INT8_C(  -9), INT8_C( -42),
                           INT8_C(  10), INT8_C( -67), INT8_C( -69), INT8_C( -15),
                           INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(  63),
                           INT8_C( -48), INT8_C( -19), INT8_C(-128), INT8_C(   0),
                           INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(  50),
                           INT8_C(  14), INT8_C( -17), INT8_C( -38), INT8_C(  21),
                           INT8_C(  68), INT8_C(-128), INT8_C( -14), INT8_C( 127),
                           INT8_C( 127), INT8_C( -92), INT8_C( 127), INT8_C( 127)) },
    { simde_mm256_set_epi8(INT8_C(   2), INT8_C(  -9), INT8_C( -57), INT8_C( 115),
                           INT8_C(  59), INT8_C(  73), INT8_C(  48), INT8_C( -68),
                           INT8_C(  25), INT8_C(  22), INT8_C( 111), INT8_C( -11),
                           INT8_C(  15), INT8_C(  80), INT8_C( -28), INT8_C( 103),
                           INT8_C( 112), INT8_C(  70), INT8_C( -85), INT8_C(  93),
                           INT8_C( 119), INT8_C( 109), INT8_C( -22), INT8_C(  25),
                           INT8_C( -22), INT8_C(  45), INT8_C( -15), INT8_C( -72),
                           INT8_C( 118), INT8_C( -32), INT8_C( -96), INT8_C(  60)),
      UINT32_C(   8515470),
      simde_mm512_set_epi16(INT16_C(-15796), INT16_C( 30043), INT16_C( 18714), INT16_C(-25916),
                            INT16_C( 32734), INT16_C( -8707), INT16_C(  8469), INT16_C(  -164),
                            INT16_C( 16857), INT16_C(  3751), INT16_C(-17844), INT16_C( 25466),
                            INT16_C( 11414), INT16_C(-10297), INT16_C( 19393), INT16_C(-20590),
                            INT16_C(-15444), INT16_C(-25233), INT16_C( 18470), INT16_C(-31576),
                            INT16_C(-31191), INT16_C(-25805), INT16_C( 18489), INT16_C(-13757),
                            INT16_C( 25106), INT16_C(  2901), INT16_C( 15043), INT16_C(  7932),
                            INT16_C( 16442), INT16_C(-31838), INT16_C(  6259), INT16_C( -3601)),
      simde_mm256_set_epi8(INT8_C(   2), INT8_C(  -9), INT8_C( -57), INT8_C( 115),
                           INT8_C(  59), INT8_C(  73), INT8_C(  48), INT8_C( -68),
                           INT8_C( 127), INT8_C(  22), INT8_C( 111), INT8_C( -11),
                           INT8_C(  15), INT8_C(  80), INT8_C( -28), INT8_C(-128),
                           INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(  93),
                           INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                           INT8_C( 127), INT8_C(  45), INT8_C( -15), INT8_C( -72),
                           INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(  60)) },
    { simde_mm256_set_epi8(INT8_C(  -4), INT8_C(  -3), INT8_C(  85), INT8_C( -85),
                           INT8_C( -30), INT8_C( -90), INT8_C(  17), INT8_C(  33),
                           INT8_C(  39), INT8_C(-100), INT8_C( -52), INT8_C( 125),
                           INT8_C( -92), INT8_C( -97), INT8_C(  56), INT8_C( -59),
                           INT8_C( -44), INT8_C( -99), INT8_C( 111), INT8_C( -71),
                           INT8_C( -30), INT8_C(  31), INT8_C( -11), INT8_C( 118),
                           INT8_C(   7), INT8_C(-107), INT8_C(  79), INT8_C(   3),
                           INT8_C(  24), INT8_C( -11), INT8_C(  32), INT8_C(  -4)),
      UINT32_C(   6113317),
      simde_mm512_set_epi16(INT16_C( 11384), INT16_C(-29809), INT16_C( 14601), INT16_C(-32436),
                            INT16_C(  2836), INT16_C( 23731), INT16_C( 16401), INT16_C(  1507),
                            INT16_C( -6852), INT16_C( 24555), INT16_C(-18463), INT16_C(  1023),
                            INT16_C(-29174), INT16_C( 23081), INT16_C( 30328), INT16_C(-13892),
                            INT16_C( -2629), INT16_C( -6761), INT16_C( -2701), INT16_C(  4637),
                            INT16_C( 12641), INT16_C( 27159), INT16_C( -5860), INT16_C( 17953),
                            INT16_C(  4257), INT16_C( 13148), INT16_C(-26937), INT16_C(  3270),
                            INT16_C(-27177), INT16_C( -7723), INT16_C(-15174), INT16_C(-31459)),
      simde_mm256_set_epi8(INT8_C(  -4), INT8_C(  -3), INT8_C(  85), INT8_C( -85),
                           INT8_C( -30), INT8_C( -90), INT8_C(  17), INT8_C(  33),
                           INT8_C(  39), INT8_C( 127), INT8_C( -52), INT8_C( 127),
                           INT8_C(-128), INT8_C( 127), INT8_C(  56), INT8_C(-128),
                           INT8_C( -44), INT8_C(-128), INT8_C( 111), INT8_C( -71),
                           INT8_C( 127), INT8_C(  31), INT8_C( -11), INT8_C( 118),
                           INT8_C(   7), INT8_C(-107), INT8_C(-128), INT8_C(   3),
                           INT8_C(  24), INT8_C(-128), INT8_C(  32), INT8_C(-128)) },
    { simde_mm256_set_epi8(INT8_C(  81), INT8_C( -88), INT8_C( -80), INT8_C(   3),
                           INT8_C(  13), INT8_C(-121), INT8_C(  22), INT8_C(  32),
                           INT8_C( -40), INT8_C( 127), INT8_C( -26), INT8_C(  -3),
                           INT8_C( 106), INT8_C( -33), INT8_C( -31), INT8_C(-105),
                           INT8_C(  59), INT8_C( -77), INT8_C(  -5), INT8_C(-117),
                           INT8_C(  83), INT8_C(  56), INT8_C( -44), INT8_C( -77),
                           INT8_C( 117), INT8_C(  36), INT8_C( -73), INT8_C( -39),
                           INT8_C(   3), INT8_C( -92), INT8_C(  31), INT8_C( -95)),
      UINT32_C(  10953837),
      simde_mm512_set_epi16(INT16_C(-11142), INT16_C(-22777), INT16_C( -6414), INT16_C(  9569),
                            INT16_C( 17271), INT16_C( -3594), INT16_C( 10850), INT16_C(-11973),
                            INT16_C(  9012), INT16_C( 10724), INT16_C(-16786), INT16_C( -2912),
                            INT16_C( -9979), INT16_C(-18969), INT16_C(  4915), INT16_C( 10628),
                            INT16_C(  8002), INT16_C(  -445), INT16_C(  4038), INT16_C(  -403),
                            INT16_C( -4668), INT16_C(-24641), INT16_C(-17959), INT16_C(  5928),
                            INT16_C(-23858), INT16_C(-14464), INT16_C( 22098), INT16_C(-14446),
                            INT16_C(-19436), INT16_C(-24649), INT16_C(-32418), INT16_C( 13277)),
      simde_mm256_set_epi8(INT8_C(  81), INT8_C( -88), INT8_C( -80), INT8_C(   3),
                           INT8_C(  13), INT8_C(-121), INT8_C(  22), INT8_C(  32),
                           INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(  -3),
                           INT8_C( 106), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                           INT8_C(  59), INT8_C( -77), INT8_C( 127), INT8_C(-117),
                           INT8_C(  83), INT8_C(-128), INT8_C( -44), INT8_C( -77),
                           INT8_C( 117), INT8_C(-128), INT8_C( 127), INT8_C( -39),
                           INT8_C(-128), INT8_C(-128), INT8_C(  31), INT8_C( 127)) },
    { simde_mm256_set_epi8(INT8_C(  83), INT8_C( 121), INT8_C(  87), INT8_C(  97),
                           INT8_C(  69), INT8_C(  33), INT8_C( -12), INT8_C(-117),
                           INT8_C(  99), INT8_C( -61), INT8_C(  40), INT8_C( -77),
                           INT8_C(  19), INT8_C( -55), INT8_C(   3), INT8_C( -96),
                           INT8_C( -32), INT8_C( -61), INT8_C(  -5), INT8_C( -43),
                           INT8_C( -47), INT8_C( 118), INT8_C(  58), INT8_C(  64),
                           INT8_C( 116), INT8_C( -63), INT8_C( 114), INT8_C( -16),
                           INT8_C(  31), INT8_C(  76), INT8_C( -13), INT8_C(-112)),
      UINT32_C(   4699534),
      simde_mm512_set_epi16(INT16_C( 27075), INT16_C( -2643), INT16_C(-27919), INT16_C( 22926),
                            INT16_C( -6606), INT16_C(  2828), INT16_C( -5375), INT16_C(-23218),
                            INT16_C(   -30), INT16_C( -9639), INT16_C( 28038), INT16_C( 11270),
                            INT16_C(-27543), INT16_C( 22578), INT16_C( 30460), INT16_C( 13726),
                            INT16_C( 28595), INT16_C( -2815), INT16_C(-21539), INT16_C(-25818),
                            INT16_C(  5191), INT16_C( 18511), INT16_C( 23592), INT16_C( 27668),
                            INT16_C(-21627), INT16_C(-28967), INT16_C(-19124), INT16_C( 27342),
                            INT16_C( 10864), INT16_C(-23627), INT16_C( 10714), INT16_C(-29389)),
      simde_mm256_set_epi8(INT8_C(  83), INT8_C( 121), INT8_C(  87), INT8_C(  97),
                           INT8_C(  69), INT8_C(  33), INT8_C( -12), INT8_C(-117),
                           INT8_C(  99), INT8_C(-128), INT8_C(  40), INT8_C( -77),
                           INT8_C(  19), INT8_C( 127), INT8_C( 127), INT8_C( 127),
                           INT8_C( 127), INT8_C( -61), INT8_C(-128), INT8_C(-128),
                           INT8_C( -47), INT8_C( 127), INT8_C(  58), INT8_C( 127),
                           INT8_C(-128), INT8_C( -63), INT8_C( 114), INT8_C( -16),
                           INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-112)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_mask_cvtsepi16_epi8(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_cvtsepi16_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask32 k;
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { UINT32_C(  16184841),
      simde_mm512_set_epi16(INT16_C( 26453), INT16_C(-25565), INT16_C(-27471), INT16_C(-25692),
                            INT16_C( 24633), INT16_C(-12996), INT16_C( -7464), INT16_C(  6163),
                            INT16_C(-14301), INT16_C(  4709), INT16_C( 31142), INT16_C(-11353),
                            INT16_C(-11078), INT16_C( -7297), INT16_C( -6389), INT16_C(-27388),
                            INT16_C( 18739), INT16_C(-14274), INT16_C(-17264), INT16_C( 27062),
                            INT16_C(-10147), INT16_C(-16257), INT16_C(-30753), INT16_C(-12970),
                            INT16_C(-31349), INT16_C(-27410), INT16_C(  9498), INT16_C(-22448),
                            INT16_C(  7761), INT16_C(-32141), INT16_C(-28848), INT16_C(-17906)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(-128),
                           INT8_C(   0), INT8_C(-128), INT8_C(-128), INT8_C(   0),
                           INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                           INT8_C(   0), INT8_C(-128), INT8_C(-128), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C( 127), INT8_C(   0), INT8_C(   0), INT8_C(-128)) },
    { UINT32_C(   9885587),
      simde_mm512_set_epi16(INT16_C(-16097), INT16_C(  -410), INT16_C( -7690), INT16_C( 17883),
                            INT16_C(-32433), INT16_C( -4153), INT16_C( 21529), INT16_C(-10594),
                            INT16_C(-12120), INT16_C( 16514), INT16_C( 14165), INT16_C(  5989),
                            INT16_C( 25322), INT16_C( 13088), INT16_C(-23253), INT16_C( 31913),
                            INT16_C(-11403), INT16_C( -8872), INT16_C(  9278), INT16_C(-13002),
                            INT16_C(  2661), INT16_C(  8241), INT16_C(-31365), INT16_C(-28794),
                            INT16_C( 31420), INT16_C(  5279), INT16_C(-11307), INT16_C(  8621),
                            INT16_C( 25450), INT16_C(-29219), INT16_C(  7142), INT16_C(  6454)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(-128), INT8_C(   0), INT8_C(   0), INT8_C( 127),
                           INT8_C(   0), INT8_C( 127), INT8_C(-128), INT8_C(   0),
                           INT8_C(-128), INT8_C(-128), INT8_C(   0), INT8_C(-128),
                           INT8_C(   0), INT8_C( 127), INT8_C(-128), INT8_C(-128),
                           INT8_C( 127), INT8_C(   0), INT8_C(   0), INT8_C( 127),
                           INT8_C(   0), INT8_C(   0), INT8_C( 127), INT8_C( 127)) },
    { UINT32_C(    967669),
      simde_mm512_set_epi16(INT16_C(  3548), INT16_C( 27037), INT16_C(-23906), INT16_C(-13973),
                            INT16_C( 29247), INT16_C( -8471), INT16_C( -1085), INT16_C( 30870),
                            INT16_C( 25891), INT16_C(-21158), INT16_C( 12488), INT16_C( -6908),
                            INT16_C( -1323), INT16_C(-29158), INT16_C( 19744), INT16_C( -9433),
                            INT16_C( 32012), INT16_C(-30047), INT16_C( 12083), INT16_C(  5703),
                            INT16_C(-23507), INT16_C(  9265), INT16_C(  9307), INT16_C( 19873),
                            INT16_C( -2618), INT16_C( -1149), INT16_C( 18681), INT16_C(  7098),
                            INT16_C(-13814), INT16_C( 19632), INT16_C(-21387), INT16_C(-19281)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(   0),
                           INT8_C( 127), INT8_C(-128), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( 127), INT8_C( 127),
                           INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                           INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C(-128)) },
    { UINT32_C(  13558935),
      simde_mm512_set_epi16(INT16_C( 14268), INT16_C(-17608), INT16_C(  4735), INT16_C( 29092),
                            INT16_C(  3348), INT16_C( 20490), INT16_C(  9048), INT16_C(-14230),
                            INT16_C(-24731), INT16_C(-20916), INT16_C( 15138), INT16_C( 30554),
                            INT16_C( 12356), INT16_C(-12154), INT16_C( -1803), INT16_C( -2954),
                            INT16_C( -6857), INT16_C( -6626), INT16_C(-23034), INT16_C( 23374),
                            INT16_C( 26785), INT16_C(-11163), INT16_C( 28429), INT16_C(-31775),
                            INT16_C(-28701), INT16_C(-18813), INT16_C( 21610), INT16_C(-25977),
                            INT16_C(-27129), INT16_C(  8170), INT16_C(   161), INT16_C(-12150)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(-128), INT8_C(-128), INT8_C(   0), INT8_C(   0),
                           INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(   0),
                           INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(   0),
                           INT8_C(   0), INT8_C(-128), INT8_C(   0), INT8_C(   0),
                           INT8_C(-128), INT8_C(   0), INT8_C(   0), INT8_C(-128),
                           INT8_C(   0), INT8_C( 127), INT8_C( 127), INT8_C(-128)) },
    { UINT32_C(   6783925),
      simde_mm512_set_epi16(INT16_C( 32147), INT16_C(-28462), INT16_C( 24823), INT16_C( 22687),
                            INT16_C(-15505), INT16_C(  -251), INT16_C( -9246), INT16_C( -8101),
                            INT16_C( 27261), INT16_C( -2090), INT16_C(  2749), INT16_C(-17423),
                            INT16_C(-32605), INT16_C(-12993), INT16_C(-12051), INT16_C(-22528),
                            INT16_C(  5519), INT16_C( 17458), INT16_C(  3823), INT16_C( -9707),
                            INT16_C( 17446), INT16_C( -3443), INT16_C( 24740), INT16_C( -9667),
                            INT16_C( 27294), INT16_C( 16674), INT16_C( -5346), INT16_C(-13180),
                            INT16_C( -6683), INT16_C( 30235), INT16_C(-31280), INT16_C( -5669)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(-128), INT8_C( 127), INT8_C(   0),
                           INT8_C(   0), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                           INT8_C( 127), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( 127), INT8_C(-128),
                           INT8_C( 127), INT8_C(   0), INT8_C(-128), INT8_C(-128),
                           INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C(-128)) },
    { UINT32_C(  15283468),
      simde_mm512_set_epi16(INT16_C( 28742), INT16_C(-21667), INT16_C( 30573), INT16_C( -5607),
                            INT16_C( -5587), INT16_C( -3656), INT16_C( 30432), INT16_C(-24516),
                            INT16_C( -4902), INT16_C(-30912), INT16_C( -9873), INT16_C( -3317),
                            INT16_C( 28529), INT16_C( 10810), INT16_C( 14756), INT16_C(-11980),
                            INT16_C(  8230), INT16_C( 14663), INT16_C(-28044), INT16_C( 14810),
                            INT16_C(  3087), INT16_C( 22573), INT16_C(-19115), INT16_C( 26647),
                            INT16_C(  3404), INT16_C(-13826), INT16_C( 16604), INT16_C( 11097),
                            INT16_C( 31149), INT16_C(-30463), INT16_C(-25032), INT16_C(-30305)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(   0),
                           INT8_C( 127), INT8_C(   0), INT8_C(   0), INT8_C(-128),
                           INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C( 127),
                           INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C( 127),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C( 127), INT8_C(-128), INT8_C(   0), INT8_C(   0)) },
    { UINT32_C(   5301351),
      simde_mm512_set_epi16(INT16_C( 16857), INT16_C(  3751), INT16_C(-17844), INT16_C( 25466),
                            INT16_C( 11414), INT16_C(-10297), INT16_C( 19393), INT16_C(-20590),
                            INT16_C(-15444), INT16_C(-25233), INT16_C( 18470), INT16_C(-31576),
                            INT16_C(-31191), INT16_C(-25805), INT16_C( 18489), INT16_C(-13757),
                            INT16_C( 25106), INT16_C(  2901), INT16_C( 15043), INT16_C(  7932),
                            INT16_C( 16442), INT16_C(-31838), INT16_C(  6259), INT16_C( -3601),
                            INT16_C( 27012), INT16_C( 21875), INT16_C(-15231), INT16_C( -4210),
                            INT16_C(   759), INT16_C(-14477), INT16_C( 15177), INT16_C( 12476)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(-128), INT8_C(   0), INT8_C(-128),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(   0),
                           INT8_C(   0), INT8_C(-128), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( 127), INT8_C(-128), INT8_C(   0),
                           INT8_C(   0), INT8_C(-128), INT8_C( 127), INT8_C( 127)) },
    { UINT32_C(   1441628),
      simde_mm512_set_epi16(INT16_C(  4257), INT16_C( 13148), INT16_C(-26937), INT16_C(  3270),
                            INT16_C(-27177), INT16_C( -7723), INT16_C(-15174), INT16_C(-31459),
                            INT16_C(-29502), INT16_C(-16960), INT16_C(  -675), INT16_C( 18469),
                            INT16_C(  -771), INT16_C( 21931), INT16_C( -7514), INT16_C(  4385),
                            INT16_C( 10140), INT16_C(-13187), INT16_C(-23393), INT16_C( 14533),
                            INT16_C(-11107), INT16_C( 28601), INT16_C( -7649), INT16_C( -2698),
                            INT16_C(  1941), INT16_C( 20227), INT16_C(  6389), INT16_C(  8444),
                            INT16_C(-15796), INT16_C( 30043), INT16_C( 18714), INT16_C(-25916)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( 127),
                           INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C( 127),
                           INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                           INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128),
                           INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C( 127),
                           INT8_C(-128), INT8_C( 127), INT8_C(   0), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_maskz_cvtsepi16_epi8(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cvtsepi32_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  699026811), INT32_C( -375318237), INT32_C(  900674930), INT32_C( -532379219),
                            INT32_C(  259624037), INT32_C( -680802854), INT32_C( 1547540196), INT32_C( -396867814),
                            INT32_C( -680186334), INT32_C( -646546417), INT32_C( 1050185959), INT32_C(  210164141),
                            INT32_C( -363246440), INT32_C( -713541510), INT32_C(-2055712079), INT32_C( 1173262878)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C( 127)) },
    { simde_mm512_set_epi32(INT32_C( -577654055), INT32_C( 1305263210), INT32_C(-1667480872), INT32_C(-1872423369),
                            INT32_C( 1597611840), INT32_C( 1615412737), INT32_C( -741695305), INT32_C(-2095777141),
                            INT32_C(-1892042790), INT32_C(  882313442), INT32_C( -646755171), INT32_C(  911535864),
                            INT32_C( 1767815726), INT32_C( 1917649804), INT32_C(-2128748387), INT32_C( -486061354)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-128),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-128)) },
    { simde_mm512_set_epi32(INT32_C( 1571463905), INT32_C(  -29910853), INT32_C( -395190633), INT32_C(-1244489996),
                            INT32_C( -209986706), INT32_C( 1448112069), INT32_C(  665030078), INT32_C( -422459827),
                            INT32_C(  944452940), INT32_C( -118153072), INT32_C(-1276500342), INT32_C( -169030554),
                            INT32_C( -426966016), INT32_C(-1701128651), INT32_C( 2062590869), INT32_C( -398665788)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(-128),
                        INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm512_set_epi32(INT32_C(-1419625975), INT32_C(-1694295907), INT32_C( 1865288725), INT32_C(-1595213023),
                            INT32_C( 1905686792), INT32_C(  988618194), INT32_C(  317245247), INT32_C( 1735742912),
                            INT32_C(-1998627679), INT32_C( 1116885338), INT32_C(-1515593887), INT32_C( 2092259348),
                            INT32_C(-1378434205), INT32_C(-1489378877), INT32_C(-2045535759), INT32_C( -659443643)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(-128)) },
    { simde_mm512_set_epi32(INT32_C(-2129053891), INT32_C( 1544504796), INT32_C( -507196434), INT32_C( 1930810889),
                            INT32_C(  483646719), INT32_C(-1089855428), INT32_C( 2145343900), INT32_C( -881615810),
                            INT32_C( 1970504702), INT32_C( 1583273127), INT32_C( 1163729707), INT32_C(-2126388173),
                            INT32_C( -806581107), INT32_C(-1698532218), INT32_C(-1392314532), INT32_C(-1512591869)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(-128)) },
    { simde_mm512_set_epi32(INT32_C( 1328977658), INT32_C(  842060052), INT32_C(-1244029168), INT32_C(  509188382),
                            INT32_C(  982259454), INT32_C(-1037867093), INT32_C(  686186344), INT32_C(  324188035),
                            INT32_C( 1498892321), INT32_C(  508595369), INT32_C( -602085962), INT32_C(-1205094693),
                            INT32_C( -758631374), INT32_C(-1994460640), INT32_C( 1443985396), INT32_C(-1807079691)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm512_set_epi32(INT32_C( 1080310926), INT32_C(-1355901593), INT32_C(  256636159), INT32_C( 1796880446),
                            INT32_C(-1357394192), INT32_C( 1762335377), INT32_C( -735301194), INT32_C(  230956482),
                            INT32_C( 1868400485), INT32_C(  -33472709), INT32_C( 1961785078), INT32_C( 1853410726),
                            INT32_C(-1472588796), INT32_C( 1430279086), INT32_C( -445655125), INT32_C( 1987885572)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127)) },
    { simde_mm512_set_epi32(INT32_C(  270394269), INT32_C( -407998192), INT32_C(-1084410926), INT32_C(-1333891767),
                            INT32_C( 1497122895), INT32_C( -215247173), INT32_C(-1835983824), INT32_C(  -84201182),
                            INT32_C(-1074778144), INT32_C( 1293769723), INT32_C( 1950241896), INT32_C(-1359838077),
                            INT32_C(  595655233), INT32_C( 2095576879), INT32_C(-1995468186), INT32_C(-1602668019)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-128)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_cvtsepi32_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cvtsepi32_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(   4), INT8_C( 110), INT8_C(   8), INT8_C( 124),
                        INT8_C( -85), INT8_C( -65), INT8_C( -62), INT8_C(-114),
                        INT8_C( 110), INT8_C(  33), INT8_C( -28), INT8_C( 106),
                        INT8_C( 107), INT8_C( 102), INT8_C(  89), INT8_C( 124)),
      UINT16_C(12710),
      simde_mm512_set_epi32(INT32_C(-1797606071), INT32_C(  433393018), INT32_C(  712958933), INT32_C( -930490644),
                            INT32_C(  760893683), INT32_C(-2027734617), INT32_C( 1683947105), INT32_C( -424320007),
                            INT32_C(  107722959), INT32_C(  -13745640), INT32_C(-1276316442), INT32_C(-1722135079),
                            INT32_C( 1405989540), INT32_C(-1209232739), INT32_C(  265793764), INT32_C(-1369604571)),
      simde_mm_set_epi8(INT8_C(   4), INT8_C( 110), INT8_C( 127), INT8_C(-128),
                        INT8_C( -85), INT8_C( -65), INT8_C( -62), INT8_C(-128),
                        INT8_C( 127), INT8_C(  33), INT8_C(-128), INT8_C( 106),
                        INT8_C( 107), INT8_C(-128), INT8_C( 127), INT8_C( 124)) },
    { simde_mm_set_epi8(INT8_C(-103), INT8_C(-117), INT8_C(  21), INT8_C( -66),
                        INT8_C(   4), INT8_C( 101), INT8_C(-112), INT8_C( -12),
                        INT8_C(  -5), INT8_C( -50), INT8_C(  26), INT8_C( -76),
                        INT8_C( -83), INT8_C( -93), INT8_C(  76), INT8_C( -53)),
      UINT16_C(12983),
      simde_mm512_set_epi32(INT32_C( -521071455), INT32_C( -376568333), INT32_C(-1920414563), INT32_C(-1600156196),
                            INT32_C( -699126682), INT32_C(  420932189), INT32_C(  368322579), INT32_C(  983236120),
                            INT32_C(  564176453), INT32_C( -258554655), INT32_C(-1141343253), INT32_C(  -63087550),
                            INT32_C( 1360677357), INT32_C(-1430308733), INT32_C( -736696329), INT32_C(  172239397)),
      simde_mm_set_epi8(INT8_C(-103), INT8_C(-117), INT8_C(-128), INT8_C(-128),
                        INT8_C(   4), INT8_C( 101), INT8_C( 127), INT8_C( -12),
                        INT8_C( 127), INT8_C( -50), INT8_C(-128), INT8_C(-128),
                        INT8_C( -83), INT8_C(-128), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi8(INT8_C( 103), INT8_C( -24), INT8_C( -57), INT8_C( -16),
                        INT8_C( -92), INT8_C( -81), INT8_C(-124), INT8_C(  85),
                        INT8_C(  75), INT8_C(  77), INT8_C(  63), INT8_C(  75),
                        INT8_C( 108), INT8_C( -84), INT8_C( -66), INT8_C( -39)),
      UINT16_C(58066),
      simde_mm512_set_epi32(INT32_C(  123157162), INT32_C(  -87325004), INT32_C(  -74930983), INT32_C( 1838315906),
                            INT32_C(  -81455038), INT32_C( -220592487), INT32_C( 1565085824), INT32_C(   60698648),
                            INT32_C( 1617237598), INT32_C( 1724869908), INT32_C( 1766262170), INT32_C(-1382435444),
                            INT32_C(  -17747961), INT32_C( -126136440), INT32_C( -844801591), INT32_C(-1631191639)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( -16),
                        INT8_C( -92), INT8_C( -81), INT8_C( 127), INT8_C(  85),
                        INT8_C( 127), INT8_C( 127), INT8_C(  63), INT8_C(-128),
                        INT8_C( 108), INT8_C( -84), INT8_C(-128), INT8_C( -39)) },
    { simde_mm_set_epi8(INT8_C(  26), INT8_C(-116), INT8_C( -21), INT8_C( -72),
                        INT8_C(  76), INT8_C( -52), INT8_C( -71), INT8_C( 116),
                        INT8_C(  41), INT8_C(-107), INT8_C( -34), INT8_C(  88),
                        INT8_C(  29), INT8_C( 112), INT8_C(  89), INT8_C( 127)),
      UINT16_C(63967),
      simde_mm512_set_epi32(INT32_C(-1851657392), INT32_C(  834971347), INT32_C(   96523257), INT32_C( 1786925287),
                            INT32_C( -210779015), INT32_C( 1982975326), INT32_C( 1450447838), INT32_C( 2089131393),
                            INT32_C(-1680682639), INT32_C( -651728462), INT32_C(-1976749038), INT32_C(-1119382179),
                            INT32_C(  674486709), INT32_C(  -51017687), INT32_C(  -85403955), INT32_C( -771014813)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C( -52), INT8_C( -71), INT8_C( 127),
                        INT8_C(-128), INT8_C(-128), INT8_C( -34), INT8_C(-128),
                        INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C( -70), INT8_C( -89), INT8_C(  47), INT8_C(  24),
                        INT8_C( 102), INT8_C(  -2), INT8_C(  77), INT8_C(  93),
                        INT8_C(   8), INT8_C(-121), INT8_C(-101), INT8_C(  37),
                        INT8_C(  18), INT8_C(-107), INT8_C(  62), INT8_C( -51)),
      UINT16_C(26024),
      simde_mm512_set_epi32(INT32_C( 1802290864), INT32_C(-1214702907), INT32_C(  821368379), INT32_C( 1594494278),
                            INT32_C(  958208413), INT32_C(-1231281503), INT32_C(  509306793), INT32_C( 1685930534),
                            INT32_C( -983619151), INT32_C(  293070963), INT32_C( 1991494863), INT32_C( 1867270897),
                            INT32_C(-1968548850), INT32_C(-1694953429), INT32_C(  342647810), INT32_C(  475783090)),
      simde_mm_set_epi8(INT8_C( -70), INT8_C(-128), INT8_C( 127), INT8_C(  24),
                        INT8_C( 102), INT8_C(-128), INT8_C(  77), INT8_C( 127),
                        INT8_C(-128), INT8_C(-121), INT8_C( 127), INT8_C(  37),
                        INT8_C(-128), INT8_C(-107), INT8_C(  62), INT8_C( -51)) },
    { simde_mm_set_epi8(INT8_C(  39), INT8_C( 109), INT8_C( 102), INT8_C( -61),
                        INT8_C( -24), INT8_C(  15), INT8_C( 101), INT8_C( -27),
                        INT8_C(  60), INT8_C(-116), INT8_C(  88), INT8_C(   9),
                        INT8_C(  98), INT8_C( -87), INT8_C( -42), INT8_C(  93)),
      UINT16_C(31919),
      simde_mm512_set_epi32(INT32_C(-2040024665), INT32_C(  961434729), INT32_C(-1271404275), INT32_C( 1259406574),
                            INT32_C(-1600364807), INT32_C( 1013354479), INT32_C(  720414379), INT32_C( -600382162),
                            INT32_C( 1552024491), INT32_C(-1608825765), INT32_C( 1791475411), INT32_C(  664867443),
                            INT32_C(  674611871), INT32_C( 2098484402), INT32_C(-1985583060), INT32_C(-2005775341)),
      simde_mm_set_epi8(INT8_C(  39), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C( 101), INT8_C( -27),
                        INT8_C( 127), INT8_C(-116), INT8_C( 127), INT8_C(   9),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C( -81), INT8_C(  41), INT8_C(  25), INT8_C(  -5),
                        INT8_C( -64), INT8_C(  70), INT8_C( 124), INT8_C( -34),
                        INT8_C(  -2), INT8_C(-101), INT8_C(  45), INT8_C( -46),
                        INT8_C(  80), INT8_C(  30), INT8_C( -59), INT8_C(-110)),
      UINT16_C(11111),
      simde_mm512_set_epi32(INT32_C( -897513851), INT32_C(  631520322), INT32_C(  634536018), INT32_C(-2012793591),
                            INT32_C( 1627606334), INT32_C(-1721387558), INT32_C(-1230866277), INT32_C(-1212419278),
                            INT32_C(  577821894), INT32_C( 1429584547), INT32_C(-2040986931), INT32_C( 2040118421),
                            INT32_C(  936070741), INT32_C(  920738578), INT32_C(-1305390023), INT32_C(-1363026646)),
      simde_mm_set_epi8(INT8_C( -81), INT8_C(  41), INT8_C( 127), INT8_C(  -5),
                        INT8_C( 127), INT8_C(  70), INT8_C(-128), INT8_C(-128),
                        INT8_C(  -2), INT8_C( 127), INT8_C(-128), INT8_C( -46),
                        INT8_C(  80), INT8_C( 127), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C(-107), INT8_C( -52), INT8_C(  65), INT8_C(  94),
                        INT8_C( -32), INT8_C( -76), INT8_C(  70), INT8_C( -85),
                        INT8_C( -67), INT8_C(  72), INT8_C(  36), INT8_C( -31),
                        INT8_C(  47), INT8_C( 126), INT8_C(  14), INT8_C(-117)),
      UINT16_C(53720),
      simde_mm512_set_epi32(INT32_C( -215671891), INT32_C( 1165933857), INT32_C(  229060973), INT32_C(-1525363693),
                            INT32_C(-1670687960), INT32_C(  159553420), INT32_C( -802431529), INT32_C(-1862869598),
                            INT32_C(-1575511501), INT32_C( 1180622586), INT32_C( 1144679036), INT32_C( 1714786815),
                            INT32_C( 1463480444), INT32_C( 1916349718), INT32_C( -744963447), INT32_C(-1790859765)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C(  65), INT8_C(-128),
                        INT8_C( -32), INT8_C( -76), INT8_C(  70), INT8_C(-128),
                        INT8_C(-128), INT8_C( 127), INT8_C(  36), INT8_C( 127),
                        INT8_C( 127), INT8_C( 126), INT8_C(  14), INT8_C(-117)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_mask_cvtsepi32_epi8(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_cvtsepi32_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { UINT16_C(22908),
      simde_mm512_set_epi32(INT32_C(  760893683), INT32_C(-2027734617), INT32_C( 1683947105), INT32_C( -424320007),
                            INT32_C(  107722959), INT32_C(  -13745640), INT32_C(-1276316442), INT32_C(-1722135079),
                            INT32_C( 1405989540), INT32_C(-1209232739), INT32_C(  265793764), INT32_C(-1369604571),
                            INT32_C( -598522698), INT32_C( 1529360806), INT32_C(   74319996), INT32_C(-1413496178)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(-128), INT8_C(   0), INT8_C(-128),
                        INT8_C( 127), INT8_C(   0), INT8_C(   0), INT8_C(-128),
                        INT8_C(   0), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C(-128), INT8_C( 127), INT8_C(   0), INT8_C(   0)) },
    { UINT16_C(55020),
      simde_mm512_set_epi32(INT32_C(  564176453), INT32_C( -258554655), INT32_C(-1141343253), INT32_C(  -63087550),
                            INT32_C( 1360677357), INT32_C(-1430308733), INT32_C( -736696329), INT32_C(  172239397),
                            INT32_C(  696452905), INT32_C( 1625371319), INT32_C(-1718938178), INT32_C(   73765108),
                            INT32_C(  -70378828), INT32_C(-1381806901), INT32_C(-1797606071), INT32_C(  433393018)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C(   0), INT8_C(-128),
                        INT8_C(   0), INT8_C(-128), INT8_C(-128), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(   0), INT8_C(   0)) },
    { UINT16_C(65048),
      simde_mm512_set_epi32(INT32_C(  -17747961), INT32_C( -126136440), INT32_C( -844801591), INT32_C(-1631191639),
                            INT32_C( 1959138923), INT32_C( 1255989970), INT32_C( 1743308784), INT32_C(-1532001195),
                            INT32_C( 1263353675), INT32_C( 1823260377), INT32_C( -521071455), INT32_C( -376568333),
                            INT32_C(-1920414563), INT32_C(-1600156196), INT32_C( -699126682), INT32_C(  420932189)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(-128),
                        INT8_C(-128), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { UINT16_C(46476),
      simde_mm512_set_epi32(INT32_C( 1491415646), INT32_C( -327353889), INT32_C(  445443000), INT32_C( 1288485236),
                            INT32_C(  697687640), INT32_C(  493902207), INT32_C(  123157162), INT32_C(  -87325004),
                            INT32_C(  -74930983), INT32_C( 1838315906), INT32_C(  -81455038), INT32_C( -220592487),
                            INT32_C( 1565085824), INT32_C(   60698648), INT32_C( 1617237598), INT32_C( 1724869908)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(   0), INT8_C( 127), INT8_C( 127),
                        INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C(-128),
                        INT8_C(-128), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C(   0), INT8_C(   0)) },
    { UINT16_C(16227),
      simde_mm512_set_epi32(INT32_C(  143104805), INT32_C(  311770829), INT32_C(-1851657392), INT32_C(  834971347),
                            INT32_C(   96523257), INT32_C( 1786925287), INT32_C( -210779015), INT32_C( 1982975326),
                            INT32_C( 1450447838), INT32_C( 2089131393), INT32_C(-1680682639), INT32_C( -651728462),
                            INT32_C(-1976749038), INT32_C(-1119382179), INT32_C(  674486709), INT32_C(  -51017687)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C(   0), INT8_C( 127), INT8_C(-128), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C( 127), INT8_C(-128)) },
    { UINT16_C(19805),
      simde_mm512_set_epi32(INT32_C(  821368379), INT32_C( 1594494278), INT32_C(  958208413), INT32_C(-1231281503),
                            INT32_C(  509306793), INT32_C( 1685930534), INT32_C( -983619151), INT32_C(  293070963),
                            INT32_C( 1991494863), INT32_C( 1867270897), INT32_C(-1968548850), INT32_C(-1694953429),
                            INT32_C(  342647810), INT32_C(  475783090), INT32_C(-1901860575), INT32_C(-1695455832)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C(   0), INT8_C( 127),
                        INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C(   0), INT8_C(-128)) },
    { UINT16_C( 6853),
      simde_mm512_set_epi32(INT32_C(  720414379), INT32_C( -600382162), INT32_C( 1552024491), INT32_C(-1608825765),
                            INT32_C( 1791475411), INT32_C(  664867443), INT32_C(  674611871), INT32_C( 2098484402),
                            INT32_C(-1985583060), INT32_C(-2005775341), INT32_C(-1904713988), INT32_C(  -21726033),
                            INT32_C(  661481155), INT32_C( -401644059), INT32_C( 1015830537), INT32_C( 1655297629)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(-128),
                        INT8_C( 127), INT8_C(   0), INT8_C( 127), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(-128), INT8_C(   0), INT8_C( 127)) },
    { UINT16_C(36847),
      simde_mm512_set_epi32(INT32_C(-2040986931), INT32_C( 2040118421), INT32_C(  936070741), INT32_C(  920738578),
                            INT32_C(-1305390023), INT32_C(-1363026646), INT32_C(  965440518), INT32_C(-1619252377),
                            INT32_C(-1356260869), INT32_C(-1069122338), INT32_C(  -23384622), INT32_C( 1344193938),
                            INT32_C(-2040024665), INT32_C(  961434729), INT32_C(-1271404275), INT32_C( 1259406574)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_maskz_cvtsepi32_epi8(test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cvtsepi32_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( -633826313), INT32_C( -624858207), INT32_C( 1490386470), INT32_C(-2098903851),
                            INT32_C(-1539984349), INT32_C( 1958536651), INT32_C(-1468703883), INT32_C( -330293651),
                            INT32_C( 2111698546), INT32_C(-1712476271), INT32_C( 1928035775), INT32_C(  815855626),
                            INT32_C(-1671100889), INT32_C(-1198252639), INT32_C(-1543874579), INT32_C(  564524240)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768),
                            INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768),
                            INT16_C( 32767), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767),
                            INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm512_set_epi32(INT32_C( 1797360798), INT32_C(  205569425), INT32_C( 1156136221), INT32_C( 1772840561),
                            INT32_C( 2126360842), INT32_C( 1592304637), INT32_C( 1062735606), INT32_C( -473740091),
                            INT32_C( 1443682851), INT32_C( -765250611), INT32_C( -738272039), INT32_C( 1732082686),
                            INT32_C( -881631866), INT32_C(  -99399017), INT32_C(  252546807), INT32_C(-1695736037)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                            INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768)) },
    { simde_mm512_set_epi32(INT32_C( -260564878), INT32_C(  427961207), INT32_C(-1056239301), INT32_C( 1225809734),
                            INT32_C(  213123881), INT32_C(  379025644), INT32_C( 1973103858), INT32_C(-2053346996),
                            INT32_C(-1954883006), INT32_C(  667947760), INT32_C(  184139306), INT32_C(  168675179),
                            INT32_C(-1651207657), INT32_C(-1932451475), INT32_C(  207773420), INT32_C(-1587464239)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                            INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767),
                            INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768)) },
    { simde_mm512_set_epi32(INT32_C( -301891179), INT32_C( 1118988231), INT32_C(  -81115331), INT32_C(   95289597),
                            INT32_C(   79711365), INT32_C( -252265140), INT32_C(-1901421271), INT32_C(  -86214221),
                            INT32_C(  494361026), INT32_C( 1393707090), INT32_C( 1367330444), INT32_C( 1529415750),
                            INT32_C( -219576728), INT32_C(  785923707), INT32_C(-1615246269), INT32_C( -860551446)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767),
                            INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm512_set_epi32(INT32_C( -668182583), INT32_C(  778563571), INT32_C( 1803655402), INT32_C(  668307371),
                            INT32_C(  166146078), INT32_C( 2089905810), INT32_C(     540370), INT32_C( -610320208),
                            INT32_C( -644851790), INT32_C( 1731401690), INT32_C( 1162165084), INT32_C( -702531425),
                            INT32_C( 1412040872), INT32_C( -506509249), INT32_C(-1429255709), INT32_C( 1954724351)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                            INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm512_set_epi32(INT32_C(  895849603), INT32_C( 1425609255), INT32_C(  649927889), INT32_C( 1727611756),
                            INT32_C( 1297009704), INT32_C(-1218308449), INT32_C(-1305018130), INT32_C( 1967276695),
                            INT32_C( -413179024), INT32_C(-1726322338), INT32_C( 1840183236), INT32_C(  284256212),
                            INT32_C( 1788242258), INT32_C(  806002384), INT32_C( -365421949), INT32_C(-2081268803)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                            INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm512_set_epi32(INT32_C( -850026299), INT32_C(  763115562), INT32_C( -698858672), INT32_C(-2063362395),
                            INT32_C(-1349430084), INT32_C(  963716730), INT32_C( 1798713564), INT32_C(-1893101926),
                            INT32_C(  662898969), INT32_C(  188387073), INT32_C( -332183490), INT32_C(-1234385790),
                            INT32_C(  839752488), INT32_C( 1421488669), INT32_C(  544371590), INT32_C(  832408505)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768),
                            INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767)) },
    { simde_mm512_set_epi32(INT32_C( 1070222476), INT32_C( 1830989582), INT32_C(  732250943), INT32_C(-1460385002),
                            INT32_C(-1298211555), INT32_C(-1342658291), INT32_C(  646581591), INT32_C(-2104719353),
                            INT32_C( 1887679149), INT32_C( 1571180495), INT32_C( 1241438931), INT32_C(   97459949),
                            INT32_C( 1558770394), INT32_C(-1780666235), INT32_C( 1621650638), INT32_C( -918750867)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                            INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767),
                            INT16_C( 32767), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_cvtsepi32_epi16(test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cvtsepi32_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(  4055), INT16_C(-20252), INT16_C(-20899), INT16_C( 32293),
                            INT16_C( -9133), INT16_C( 17590), INT16_C( 23336), INT16_C( 12710),
                            INT16_C(  1134), INT16_C(  2172), INT16_C(-21569), INT16_C(-15730),
                            INT16_C( 28193), INT16_C( -7062), INT16_C( 27494), INT16_C( 22908)),
      UINT16_C(37533),
      simde_mm512_set_epi32(INT32_C(-1718938178), INT32_C(   73765108), INT32_C(  -70378828), INT32_C(-1381806901),
                            INT32_C(-1797606071), INT32_C(  433393018), INT32_C(  712958933), INT32_C( -930490644),
                            INT32_C(  760893683), INT32_C(-2027734617), INT32_C( 1683947105), INT32_C( -424320007),
                            INT32_C(  107722959), INT32_C(  -13745640), INT32_C(-1276316442), INT32_C(-1722135079)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C(-20252), INT16_C(-20899), INT16_C(-32768),
                            INT16_C( -9133), INT16_C( 17590), INT16_C( 32767), INT16_C( 12710),
                            INT16_C( 32767), INT16_C(  2172), INT16_C(-21569), INT16_C(-32768),
                            INT16_C( 32767), INT16_C(-32768), INT16_C( 27494), INT16_C(-32768)) },
    { simde_mm256_set_epi16(INT16_C(-17416), INT16_C( 31723), INT16_C(  -963), INT16_C( 23618),
                            INT16_C( 20762), INT16_C( 18925), INT16_C(-21825), INT16_C( 14467),
                            INT16_C(-11242), INT16_C( -6153), INT16_C(  2628), INT16_C( 10789),
                            INT16_C( 10627), INT16_C(  1833), INT16_C( 24801), INT16_C( 12983)),
      UINT16_C(50401),
      simde_mm512_set_epi32(INT32_C( -844801591), INT32_C(-1631191639), INT32_C( 1959138923), INT32_C( 1255989970),
                            INT32_C( 1743308784), INT32_C(-1532001195), INT32_C( 1263353675), INT32_C( 1823260377),
                            INT32_C( -521071455), INT32_C( -376568333), INT32_C(-1920414563), INT32_C(-1600156196),
                            INT32_C( -699126682), INT32_C(  420932189), INT32_C(  368322579), INT32_C(  983236120)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C(-32768), INT16_C(  -963), INT16_C( 23618),
                            INT16_C( 20762), INT16_C(-32768), INT16_C(-21825), INT16_C( 14467),
                            INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C( 10789),
                            INT16_C( 10627), INT16_C(  1833), INT16_C( 24801), INT16_C( 32767)) },
    { simde_mm256_set_epi16(INT16_C( 23881), INT16_C( 20608), INT16_C(   926), INT16_C( 12312),
                            INT16_C( 24677), INT16_C(  5726), INT16_C( 26319), INT16_C( 27924),
                            INT16_C( 26951), INT16_C(  1434), INT16_C(-21095), INT16_C(-19060),
                            INT16_C(  -271), INT16_C( 12295), INT16_C( -1925), INT16_C( 20360)),
      UINT16_C( 1689),
      simde_mm512_set_epi32(INT32_C(-1976749038), INT32_C(-1119382179), INT32_C(  674486709), INT32_C(  -51017687),
                            INT32_C(  -85403955), INT32_C( -771014813), INT32_C( 1491415646), INT32_C( -327353889),
                            INT32_C(  445443000), INT32_C( 1288485236), INT32_C(  697687640), INT32_C(  493902207),
                            INT32_C(  123157162), INT32_C(  -87325004), INT32_C(  -74930983), INT32_C( 1838315906)),
      simde_mm256_set_epi16(INT16_C( 23881), INT16_C( 20608), INT16_C(   926), INT16_C( 12312),
                            INT16_C( 24677), INT16_C(-32768), INT16_C( 32767), INT16_C( 27924),
                            INT16_C( 32767), INT16_C(  1434), INT16_C(-21095), INT16_C( 32767),
                            INT16_C( 32767), INT16_C( 12295), INT16_C( -1925), INT16_C( 32767)) },
    { simde_mm256_set_epi16(INT16_C(  1472), INT16_C(-11271), INT16_C( 27266), INT16_C( 20711),
                            INT16_C( -3217), INT16_C(-15239), INT16_C( 30257), INT16_C(-12962),
                            INT16_C( 22132), INT16_C(  5086), INT16_C( 31877), INT16_C(-25215),
                            INT16_C(-25646), INT16_C(-11919), INT16_C( -9945), INT16_C( 27058)),
      UINT16_C(42707),
      simde_mm512_set_epi32(INT32_C(  509306793), INT32_C( 1685930534), INT32_C( -983619151), INT32_C(  293070963),
                            INT32_C( 1991494863), INT32_C( 1867270897), INT32_C(-1968548850), INT32_C(-1694953429),
                            INT32_C(  342647810), INT32_C(  475783090), INT32_C(-1901860575), INT32_C(-1695455832),
                            INT32_C(-1163448552), INT32_C( 1727941981), INT32_C(  143104805), INT32_C(  311770829)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C(-11271), INT16_C(-32768), INT16_C( 20711),
                            INT16_C( -3217), INT16_C( 32767), INT16_C(-32768), INT16_C(-12962),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 31877), INT16_C(-32768),
                            INT16_C(-25646), INT16_C(-11919), INT16_C( 32767), INT16_C( 32767)) },
    { simde_mm256_set_epi16(INT16_C( 15500), INT16_C( 22537), INT16_C( 25257), INT16_C(-10659),
                            INT16_C( 27500), INT16_C(-14672), INT16_C(-18535), INT16_C(  6853),
                            INT16_C( 12533), INT16_C(  5691), INT16_C( 24330), INT16_C(  3398),
                            INT16_C( 14621), INT16_C(  6557), INT16_C(-18788), INT16_C(  8865)),
      UINT16_C(26085),
      simde_mm512_set_epi32(INT32_C(-1271404275), INT32_C( 1259406574), INT32_C(-1600364807), INT32_C( 1013354479),
                            INT32_C(  720414379), INT32_C( -600382162), INT32_C( 1552024491), INT32_C(-1608825765),
                            INT32_C( 1791475411), INT32_C(  664867443), INT32_C(  674611871), INT32_C( 2098484402),
                            INT32_C(-1985583060), INT32_C(-2005775341), INT32_C(-1904713988), INT32_C(  -21726033)),
      simde_mm256_set_epi16(INT16_C( 15500), INT16_C( 32767), INT16_C(-32768), INT16_C(-10659),
                            INT16_C( 27500), INT16_C(-32768), INT16_C(-18535), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(  3398),
                            INT16_C( 14621), INT16_C(-32768), INT16_C(-18788), INT16_C(-32768)) },
    { simde_mm256_set_epi16(INT16_C( 14731), INT16_C( 29702), INT16_C(-24708), INT16_C( 11111),
                            INT16_C(-20695), INT16_C(  6651), INT16_C(-16314), INT16_C( 31966),
                            INT16_C(  -357), INT16_C( 11730), INT16_C( 20510), INT16_C(-14958),
                            INT16_C(-31129), INT16_C(-20057), INT16_C( 14670), INT16_C( 21609)),
      UINT16_C(56618),
      simde_mm512_set_epi32(INT32_C(-1119345439), INT32_C(  796790411), INT32_C( -897513851), INT32_C(  631520322),
                            INT32_C(  634536018), INT32_C(-2012793591), INT32_C( 1627606334), INT32_C(-1721387558),
                            INT32_C(-1230866277), INT32_C(-1212419278), INT32_C(  577821894), INT32_C( 1429584547),
                            INT32_C(-2040986931), INT32_C( 2040118421), INT32_C(  936070741), INT32_C(  920738578)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C(-24708), INT16_C( 32767),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(-16314), INT16_C(-32768),
                            INT16_C(  -357), INT16_C( 11730), INT16_C( 32767), INT16_C(-14958),
                            INT16_C(-32768), INT16_C(-20057), INT16_C( 32767), INT16_C( 21609)) },
    { simde_mm256_set_epi16(INT16_C( 22330), INT16_C( -3972), INT16_C( 29241), INT16_C( 11542),
                            INT16_C(-11368), INT16_C(-15735), INT16_C(-27327), INT16_C(-23029),
                            INT16_C( -8383), INT16_C(-32273), INT16_C(  3895), INT16_C(-11816),
                            INT16_C(-27188), INT16_C( 16734), INT16_C( -8012), INT16_C( 18091)),
      UINT16_C(37375),
      simde_mm512_set_epi32(INT32_C( -221392236), INT32_C( -711063988), INT32_C( 2133711027), INT32_C(  509873922),
                            INT32_C( 1729615213), INT32_C( -831792372), INT32_C( -215671891), INT32_C( 1165933857),
                            INT32_C(  229060973), INT32_C(-1525363693), INT32_C(-1670687960), INT32_C(  159553420),
                            INT32_C( -802431529), INT32_C(-1862869598), INT32_C(-1575511501), INT32_C( 1180622586)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C( -3972), INT16_C( 29241), INT16_C( 32767),
                            INT16_C(-11368), INT16_C(-15735), INT16_C(-27327), INT16_C( 32767),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                            INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm256_set_epi16(INT16_C(  -456), INT16_C( -6277), INT16_C(-13154), INT16_C( 20424),
                            INT16_C(  7701), INT16_C(  9153), INT16_C( 18208), INT16_C(  1720),
                            INT16_C(-14211), INT16_C( 26958), INT16_C( 27767), INT16_C(-15259),
                            INT16_C(-16868), INT16_C(-31112), INT16_C( -6815), INT16_C( 21503)),
      UINT16_C(29475),
      simde_mm512_set_epi32(INT32_C(  441964111), INT32_C(-1041336788), INT32_C( 1240459905), INT32_C( 1190379131),
                            INT32_C(  660048661), INT32_C(  992314379), INT32_C(   13012539), INT32_C(-1751743734),
                            INT32_C(-1323762798), INT32_C(  640110239), INT32_C( 1866432721), INT32_C(-1867947321),
                            INT32_C(-2066921506), INT32_C(  704072659), INT32_C(  929476148), INT32_C(-1455589491)),
      simde_mm256_set_epi16(INT16_C(  -456), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767),
                            INT16_C(  7701), INT16_C(  9153), INT16_C( 32767), INT16_C(-32768),
                            INT16_C(-14211), INT16_C( 26958), INT16_C( 32767), INT16_C(-15259),
                            INT16_C(-16868), INT16_C(-31112), INT16_C( 32767), INT16_C(-32768)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_mask_cvtsepi32_epi16(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_cvtsepi32_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { UINT16_C(22908),
      simde_mm512_set_epi32(INT32_C(  760893683), INT32_C(-2027734617), INT32_C( 1683947105), INT32_C( -424320007),
                            INT32_C(  107722959), INT32_C(  -13745640), INT32_C(-1276316442), INT32_C(-1722135079),
                            INT32_C( 1405989540), INT32_C(-1209232739), INT32_C(  265793764), INT32_C(-1369604571),
                            INT32_C( -598522698), INT32_C( 1529360806), INT32_C(   74319996), INT32_C(-1413496178)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(-32768), INT16_C(     0), INT16_C(-32768),
                            INT16_C( 32767), INT16_C(     0), INT16_C(     0), INT16_C(-32768),
                            INT16_C(     0), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768),
                            INT16_C(-32768), INT16_C( 32767), INT16_C(     0), INT16_C(     0)) },
    { UINT16_C(55020),
      simde_mm512_set_epi32(INT32_C(  564176453), INT32_C( -258554655), INT32_C(-1141343253), INT32_C(  -63087550),
                            INT32_C( 1360677357), INT32_C(-1430308733), INT32_C( -736696329), INT32_C(  172239397),
                            INT32_C(  696452905), INT32_C( 1625371319), INT32_C(-1718938178), INT32_C(   73765108),
                            INT32_C(  -70378828), INT32_C(-1381806901), INT32_C(-1797606071), INT32_C(  433393018)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(     0), INT16_C(-32768),
                            INT16_C(     0), INT16_C(-32768), INT16_C(-32768), INT16_C(     0),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(     0),
                            INT16_C(-32768), INT16_C(-32768), INT16_C(     0), INT16_C(     0)) },
    { UINT16_C(65048),
      simde_mm512_set_epi32(INT32_C(  -17747961), INT32_C( -126136440), INT32_C( -844801591), INT32_C(-1631191639),
                            INT32_C( 1959138923), INT32_C( 1255989970), INT32_C( 1743308784), INT32_C(-1532001195),
                            INT32_C( 1263353675), INT32_C( 1823260377), INT32_C( -521071455), INT32_C( -376568333),
                            INT32_C(-1920414563), INT32_C(-1600156196), INT32_C( -699126682), INT32_C(  420932189)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(-32768),
                            INT16_C(-32768), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT16_C(46476),
      simde_mm512_set_epi32(INT32_C( 1491415646), INT32_C( -327353889), INT32_C(  445443000), INT32_C( 1288485236),
                            INT32_C(  697687640), INT32_C(  493902207), INT32_C(  123157162), INT32_C(  -87325004),
                            INT32_C(  -74930983), INT32_C( 1838315906), INT32_C(  -81455038), INT32_C( -220592487),
                            INT32_C( 1565085824), INT32_C(   60698648), INT32_C( 1617237598), INT32_C( 1724869908)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C(     0), INT16_C( 32767), INT16_C( 32767),
                            INT16_C(     0), INT16_C( 32767), INT16_C(     0), INT16_C(-32768),
                            INT16_C(-32768), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(     0), INT16_C(     0)) },
    { UINT16_C(16227),
      simde_mm512_set_epi32(INT32_C(  143104805), INT32_C(  311770829), INT32_C(-1851657392), INT32_C(  834971347),
                            INT32_C(   96523257), INT32_C( 1786925287), INT32_C( -210779015), INT32_C( 1982975326),
                            INT32_C( 1450447838), INT32_C( 2089131393), INT32_C(-1680682639), INT32_C( -651728462),
                            INT32_C(-1976749038), INT32_C(-1119382179), INT32_C(  674486709), INT32_C(  -51017687)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(-32768), INT16_C( 32767),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767),
                            INT16_C(     0), INT16_C( 32767), INT16_C(-32768), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C( 32767), INT16_C(-32768)) },
    { UINT16_C(19805),
      simde_mm512_set_epi32(INT32_C(  821368379), INT32_C( 1594494278), INT32_C(  958208413), INT32_C(-1231281503),
                            INT32_C(  509306793), INT32_C( 1685930534), INT32_C( -983619151), INT32_C(  293070963),
                            INT32_C( 1991494863), INT32_C( 1867270897), INT32_C(-1968548850), INT32_C(-1694953429),
                            INT32_C(  342647810), INT32_C(  475783090), INT32_C(-1901860575), INT32_C(-1695455832)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C( 32767), INT16_C(     0), INT16_C(     0),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(     0), INT16_C( 32767),
                            INT16_C(     0), INT16_C( 32767), INT16_C(     0), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(     0), INT16_C(-32768)) },
    { UINT16_C( 6853),
      simde_mm512_set_epi32(INT32_C(  720414379), INT32_C( -600382162), INT32_C( 1552024491), INT32_C(-1608825765),
                            INT32_C( 1791475411), INT32_C(  664867443), INT32_C(  674611871), INT32_C( 2098484402),
                            INT32_C(-1985583060), INT32_C(-2005775341), INT32_C(-1904713988), INT32_C(  -21726033),
                            INT32_C(  661481155), INT32_C( -401644059), INT32_C( 1015830537), INT32_C( 1655297629)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(-32768),
                            INT16_C( 32767), INT16_C(     0), INT16_C( 32767), INT16_C(     0),
                            INT16_C(-32768), INT16_C(-32768), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(-32768), INT16_C(     0), INT16_C( 32767)) },
    { UINT16_C(36847),
      simde_mm512_set_epi32(INT32_C(-2040986931), INT32_C( 2040118421), INT32_C(  936070741), INT32_C(  920738578),
                            INT32_C(-1305390023), INT32_C(-1363026646), INT32_C(  965440518), INT32_C(-1619252377),
                            INT32_C(-1356260869), INT32_C(-1069122338), INT32_C(  -23384622), INT32_C( 1344193938),
                            INT32_C(-2040024665), INT32_C(  961434729), INT32_C(-1271404275), INT32_C( 1259406574)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768),
                            INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C(     0),
                            INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_maskz_cvtsepi32_epi16(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cvtsepi64_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
     { simde_mm512_set_epi64(INT64_C( 5688878986790062607), INT64_C( -507006338933993777),
                            INT64_C( 2731700857838766689), INT64_C( 5038766546414012764),
                            INT64_C( 8031668245477288096), INT64_C( 8558843731862564067),
                            INT64_C( 1445459848667085535), INT64_C(  -83609451038325995)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(-128)) },
    { simde_mm512_set_epi64(INT64_C( 8541199063845314870), INT64_C( 6183904058691300593),
                            INT64_C( 4987917255037318931), INT64_C(-6461883516210235787),
                            INT64_C(-2290177652468594952), INT64_C( -292256871616436513),
                            INT64_C( 8655434451305349549), INT64_C( 2098144080369590904)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C( 127)) },
    { simde_mm512_set_epi64(INT64_C( 8921116119188857611), INT64_C(-7689618306950712122),
                            INT64_C( 1518593000980919604), INT64_C( 4285824591643310377),
                            INT64_C(-5934398452121416225), INT64_C( 3925581736765257012),
                            INT64_C(-1280589966661740296), INT64_C(-6610380819072272984)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128)) },
    { simde_mm512_set_epi64(INT64_C(-7117386000751069153), INT64_C(-4042166984900833962),
                            INT64_C( 5586053217269340515), INT64_C(-7584975210127513398),
                            INT64_C( 3657404296828616096), INT64_C(-2770219948143520502),
                            INT64_C( 4495347402256698165), INT64_C( -398794429961863290)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm512_set_epi64(INT64_C(-7309298589786727464), INT64_C( 6351016797136664888),
                            INT64_C( -796932205202576292), INT64_C( 5974868289408841942),
                            INT64_C(-5246045528720698174), INT64_C( 5897717133320969396),
                            INT64_C( 8855007060554502516), INT64_C( 1795078486534561817)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( 127)) },
    { simde_mm512_set_epi64(INT64_C(-8235362769944622173), INT64_C(-1394979073669202107),
                            INT64_C(-1990341901794640861), INT64_C(-5381553921365904442),
                            INT64_C( 2258222102802041167), INT64_C( 8110919934642332525),
                            INT64_C( 3859146607814864086), INT64_C( 5989226152769229183)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C( 127)) },
    { simde_mm512_set_epi64(INT64_C( 7694422639508462949), INT64_C(-2072064725478552758),
                            INT64_C( 3296208651842008367), INT64_C(-5674066605955291159),
                            INT64_C( 5400731755389512823), INT64_C( 4001845542455980591),
                            INT64_C( 1263947732552642640), INT64_C( 1152590716152552703)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(-128),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C( 127)) },
    { simde_mm512_set_epi64(INT64_C(-5372614012128921165), INT64_C(-2041172040005057172),
                            INT64_C(-8233280709947200170), INT64_C( 1449409854914395254),
                            INT64_C( 6224671476337807114), INT64_C( 4022680139615958951),
                            INT64_C( -277976409085756360), INT64_C(-4710983618327201696)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-128)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_cvtsepi64_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cvtsepi64_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -98), INT8_C(-118), INT8_C( -55), INT8_C(  84),
                        INT8_C( -38), INT8_C(-100), INT8_C(  69), INT8_C( -11),
                        INT8_C( -76), INT8_C( -44), INT8_C( 111), INT8_C(  57),
                        INT8_C(-108), INT8_C( 117), INT8_C( -94), INT8_C(  99)),
      UINT8_C( 89),
      simde_mm512_set_epi64(INT64_C(-6464916445333598184), INT64_C(-9074050598773963479),
                            INT64_C(-6773163771856001287), INT64_C( 8528895860955669022),
                            INT64_C(  743395091751495893), INT64_C(-5753646205421077345),
                            INT64_C( 6781795189594641427), INT64_C( 7308036127418939455)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( -76), INT8_C(-128), INT8_C( 111), INT8_C( 127),
                        INT8_C( 127), INT8_C( 117), INT8_C( -94), INT8_C( 127)) },
    { simde_mm_set_epi8(INT8_C( -29), INT8_C( -88), INT8_C(  59), INT8_C( -11),
                        INT8_C(-100), INT8_C(-112), INT8_C(  21), INT8_C( -50),
                        INT8_C(  53), INT8_C( -68), INT8_C(-121), INT8_C(  94),
                        INT8_C(-100), INT8_C( -25), INT8_C( 102), INT8_C( 120)),
      UINT8_C(108),
      simde_mm512_set_epi64(INT64_C(-8224370586313845882), INT64_C(-1993121323347227003),
                            INT64_C( 8831696545371448920), INT64_C( 2185815767663877612),
                            INT64_C( -270570670623534210), INT64_C(-7835605414239696560),
                            INT64_C(-1637430132815230795), INT64_C( 7232010829548987022)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  53), INT8_C(-128), INT8_C( 127), INT8_C(  94),
                        INT8_C(-128), INT8_C(-128), INT8_C( 102), INT8_C( 120)) },
    { simde_mm_set_epi8(INT8_C( -93), INT8_C( -72), INT8_C(   3), INT8_C( -86),
                        INT8_C(-106), INT8_C(  54), INT8_C( -93), INT8_C(  77),
                        INT8_C( 111), INT8_C(-126), INT8_C(  23), INT8_C( -40),
                        INT8_C(  -4), INT8_C(  -3), INT8_C( -74), INT8_C(   6)),
      UINT8_C(212),
      simde_mm512_set_epi64(INT64_C(-3956629285800542954), INT64_C( 7768661847448918660),
                            INT64_C( 8414129281940348180), INT64_C(-3282225164507364365),
                            INT64_C( 3972788221445796445), INT64_C(-1066584669561441235),
                            INT64_C( 2182845185502488635), INT64_C(-2591044625591562731)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C( 127), INT8_C(  23), INT8_C(-128),
                        INT8_C(  -4), INT8_C(-128), INT8_C( -74), INT8_C(   6)) },
    { simde_mm_set_epi8(INT8_C(  95), INT8_C( 126), INT8_C( 102), INT8_C(  -2),
                        INT8_C(  37), INT8_C( -94), INT8_C(  95), INT8_C( -94),
                        INT8_C(-125), INT8_C(  -9), INT8_C( -95), INT8_C(  41),
                        INT8_C(  -4), INT8_C( -36), INT8_C( -88), INT8_C(  79)),
      UINT8_C( 80),
      simde_mm512_set_epi64(INT64_C( 5062048906197334415), INT64_C( -115992959878725320),
                            INT64_C( 1136786795492082678), INT64_C(-1948109654186813959),
                            INT64_C(  120681793319816518), INT64_C(-3982161075345546564),
                            INT64_C(-4623140196798581694), INT64_C(-1633613586256931500)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-125), INT8_C(-128), INT8_C( -95), INT8_C(-128),
                        INT8_C(  -4), INT8_C( -36), INT8_C( -88), INT8_C(  79)) },
    { simde_mm_set_epi8(INT8_C( -59), INT8_C( -75), INT8_C( -72), INT8_C( -42),
                        INT8_C( -55), INT8_C(-119), INT8_C( -60), INT8_C(  67),
                        INT8_C( 109), INT8_C( -73), INT8_C(  91), INT8_C(  51),
                        INT8_C(  78), INT8_C(  83), INT8_C(-115), INT8_C(  62)),
      UINT8_C(249),
      simde_mm512_set_epi64(INT64_C( 5851174439164188465), INT64_C(-6319779881941429071),
                            INT64_C( 1879763181654775792), INT64_C( 4044922446109520806),
                            INT64_C( 1345671618220988839), INT64_C(-8367274893382946539),
                            INT64_C( 4386554571925238747), INT64_C(-2885812676818812761)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C( 127), INT8_C(  83), INT8_C(-115), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C(  79), INT8_C(  39), INT8_C(  96), INT8_C(  42),
                        INT8_C( -85), INT8_C( 114), INT8_C(  97), INT8_C( -62),
                        INT8_C(   8), INT8_C(  38), INT8_C(  93), INT8_C( 127),
                        INT8_C(-112), INT8_C( 122), INT8_C(-125), INT8_C( -69)),
      UINT8_C( 46),
      simde_mm512_set_epi64(INT64_C(-5543414139022216695), INT64_C(-7351051862345725962),
                            INT64_C( 7765938089573807601), INT64_C(-8520500957815241015),
                            INT64_C(-4114690540063739335), INT64_C( 2127377446843006162),
                            INT64_C( 4629741254325605495), INT64_C( 6283226406328232321)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   8), INT8_C(  38), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( -69)) },
    { simde_mm_set_epi8(INT8_C( -81), INT8_C(-127), INT8_C( -86), INT8_C(  87),
                        INT8_C(  54), INT8_C(  74), INT8_C(  -3), INT8_C(  90),
                        INT8_C( -47), INT8_C( -23), INT8_C(  73), INT8_C(  26),
                        INT8_C(  65), INT8_C(  65), INT8_C(  86), INT8_C(-128)),
      UINT8_C(244),
      simde_mm512_set_epi64(INT64_C( 3168330803816226018), INT64_C(-5665190690683619181),
                            INT64_C(-6479275574786056503), INT64_C(-4854337280374936929),
                            INT64_C( 9110007504327473973), INT64_C( 2306966881245130829),
                            INT64_C( 3371747741827789856), INT64_C( 4883552887250537067)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128),
                        INT8_C(  65), INT8_C( 127), INT8_C(  86), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C( -36), INT8_C( -15), INT8_C(  94), INT8_C(  96),
                        INT8_C(  41), INT8_C(  71), INT8_C(-125), INT8_C(  50),
                        INT8_C(  -5), INT8_C( -42), INT8_C(   6), INT8_C(  31),
                        INT8_C( -82), INT8_C(  -3), INT8_C( -84), INT8_C( 118)),
      UINT8_C( 84),
      simde_mm512_set_epi64(INT64_C(-5802305007366524132), INT64_C( 6368102336095963395),
                            INT64_C(   26715019440636716), INT64_C( 3396530625665467524),
                            INT64_C( 4010180268457941346), INT64_C( 5473964637387956828),
                            INT64_C( 6527063328512873018), INT64_C( 7600981363267795639)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -5), INT8_C( 127), INT8_C(   6), INT8_C( 127),
                        INT8_C( -82), INT8_C( 127), INT8_C( -84), INT8_C( 118)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_mask_cvtsepi64_epi8(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_cvtsepi64_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { UINT8_C( 99),
      simde_mm512_set_epi64(INT64_C(-6773163771856001287), INT64_C( 8528895860955669022),
                            INT64_C(  743395091751495893), INT64_C(-5753646205421077345),
                            INT64_C( 6781795189594641427), INT64_C( 7308036127418939455),
                            INT64_C(  616165601606027604), INT64_C(-2694201555471274183)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C( 127), INT8_C( 127), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C( 127), INT8_C(-128)) },
    { UINT8_C( 41),
      simde_mm512_set_epi64(INT64_C( -270570670623534210), INT64_C(-7835605414239696560),
                            INT64_C(-1637430132815230795), INT64_C( 7232010829548987022),
                            INT64_C(  564423766678453237), INT64_C(-7165203031737464994),
                            INT64_C(-7140626015800786754), INT64_C(-2499691201975648498)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C(   0),
                        INT8_C( 127), INT8_C(   0), INT8_C(   0), INT8_C(-128)) },
    { UINT8_C(236),
      simde_mm512_set_epi64(INT64_C( 2182845185502488635), INT64_C(-2591044625591562731),
                            INT64_C(  634126652413576106), INT64_C(-7622725766299379752),
                            INT64_C( -216817067777774970), INT64_C(-4785193871492054345),
                            INT64_C( 7467476729839254839), INT64_C( 3956665538785416156)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(   0),
                        INT8_C(-128), INT8_C(-128), INT8_C(   0), INT8_C(   0)) },
    { UINT8_C( 45),
      simde_mm512_set_epi64(INT64_C(-8852586683955255554), INT64_C( 2711835077233844521),
                            INT64_C( -226120820645741920), INT64_C(-5768129162479938358),
                            INT64_C( 4995224830392729088), INT64_C(-9204129394426957414),
                            INT64_C( 6102592944456478166), INT64_C(-5538879581396485404)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C(   0),
                        INT8_C( 127), INT8_C(-128), INT8_C(   0), INT8_C(-128)) },
    { UINT8_C( 84),
      simde_mm512_set_epi64(INT64_C( 5644010056631452329), INT64_C(  687917764947732740),
                            INT64_C( 9077991551678197137), INT64_C( 5379835588808993943),
                            INT64_C( 5669915352590237555), INT64_C(-7084358722419653223),
                            INT64_C(-5646349838748004740), INT64_C( 5115442951238204697)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C( 127), INT8_C(   0), INT8_C( 127),
                        INT8_C(   0), INT8_C(-128), INT8_C(   0), INT8_C(   0)) },
    { UINT8_C( 51),
      simde_mm512_set_epi64(INT64_C( 6212879174325387943), INT64_C(-9195198218682338424),
                            INT64_C(-6314975051621021387), INT64_C(  316124606243108816),
                            INT64_C(-1018533604686287836), INT64_C( 7455766202425772200),
                            INT64_C( -151643922692032263), INT64_C(-4200247844809358269)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C( 127),
                        INT8_C(   0), INT8_C(   0), INT8_C(-128), INT8_C(-128)) },
    { UINT8_C(174),
      simde_mm512_set_epi64(INT64_C(-4824473637125509439), INT64_C( 2222300162020472452),
                            INT64_C( 4485933577556469028), INT64_C( 3606420641901871392),
                            INT64_C( 7533512282749681966), INT64_C( 5703633189469315522),
                            INT64_C(  587259603884606395), INT64_C( 5851174439164188465)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(   0), INT8_C( 127), INT8_C(   0),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(   0)) },
    { UINT8_C(133),
      simde_mm512_set_epi64(INT64_C(-2795345254402041164), INT64_C( -585762482098414214),
                            INT64_C( 1037739329164009972), INT64_C(-5800167553526727334),
                            INT64_C(-3321042873096251776), INT64_C(-5543414139022216695),
                            INT64_C(-7351051862345725962), INT64_C( 7765938089573807601)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(-128), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(-128), INT8_C(   0), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_maskz_cvtsepi64_epi8(test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cvtsepi64_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-2030970610590957423), INT64_C(-6407881172688895992),
                            INT64_C( 5763311992085393311), INT64_C( 5413217893862876377),
                            INT64_C( 2736248102150189299), INT64_C(-3905239043220002295),
                            INT64_C(-8525695447592722282), INT64_C( 8985359849763220184)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767),
                         INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm512_set_epi64(INT64_C( 5528142976218439915), INT64_C( 2800801417967116565),
                            INT64_C(-5498223206200113790), INT64_C(-7735651953136898344),
                            INT64_C(  -45944962922223273), INT64_C( 7270573409050727432),
                            INT64_C(-3005715738589766193), INT64_C(    8104807772879505)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768),
                         INT16_C(-32768), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm512_set_epi64(INT64_C( 1914743572707752888), INT64_C(-1522220651072788958),
                            INT64_C(  774824395663784136), INT64_C(-5948238846445238616),
                            INT64_C(-6703970016956217448), INT64_C(-4949181030820609545),
                            INT64_C(-1484143836373726158), INT64_C( 7023453391392224586)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C( 32767), INT16_C(-32768),
                         INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm512_set_epi64(INT64_C(  877787331628902271), INT64_C(-4271522850214152795),
                            INT64_C(  -36139528410486948), INT64_C( 8221636509979881717),
                            INT64_C( 8317903343708448256), INT64_C(  273589563704309286),
                            INT64_C(-3793565254975032249), INT64_C(-8693302524009918115)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C(-32768)) },
    { simde_mm512_set_epi64(INT64_C( 8982303740345517000), INT64_C( 3826887655534630950),
                            INT64_C( 3239767036578666476), INT64_C(-6247325025317220634),
                            INT64_C( 7671225941352774255), INT64_C(-4520433707995010156),
                            INT64_C( -202556859458160671), INT64_C( 8376976669674082741)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768),
                         INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm512_set_epi64(INT64_C(-6735519140496673702), INT64_C(-3340797945830539185),
                            INT64_C(-4234248954061729169), INT64_C(-8216832367433725114),
                            INT64_C( 7806307918239696158), INT64_C( 1170496629302395613),
                            INT64_C(-6389283806078878937), INT64_C( 6713220048127768064)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768),
                         INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm512_set_epi64(INT64_C( 4236272701979881947), INT64_C( 3804598066273696798),
                            INT64_C(-3344748723935369850), INT64_C( 1825331027945283861),
                            INT64_C(  238286709106496427), INT64_C( 5804239832581888150),
                            INT64_C(  140213339004639903), INT64_C(-8021982786001039013)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(-32768)) },
    { simde_mm512_set_epi64(INT64_C(-4062543779038977729), INT64_C( 2624543651353099153),
                            INT64_C( 8730480163779377063), INT64_C( 1087955593743156912),
                            INT64_C(-7352034341207303173), INT64_C( -816150536575471214),
                            INT64_C(  427511002321984596), INT64_C( 6609731989001691179)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C( 32767),
                         INT16_C(-32768), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_cvtsepi64_epi16(test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cvtsepi64_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-24950), INT16_C(-13996), INT16_C( -9572), INT16_C( 17909),
                         INT16_C(-19244), INT16_C( 28473), INT16_C(-27531), INT16_C(-23965)),
      UINT8_C( 89),
      simde_mm512_set_epi64(INT64_C(-6464916445333598184), INT64_C(-9074050598773963479),
                            INT64_C(-6773163771856001287), INT64_C( 8528895860955669022),
                            INT64_C(  743395091751495893), INT64_C(-5753646205421077345),
                            INT64_C( 6781795189594641427), INT64_C( 7308036127418939455)),
      simde_mm_set_epi16(INT16_C(-24950), INT16_C(-32768), INT16_C( -9572), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 28473), INT16_C(-27531), INT16_C( 32767)) },
    { simde_mm_set_epi16(INT16_C( -7256), INT16_C( 15349), INT16_C(-25456), INT16_C(  5582),
                         INT16_C( 13756), INT16_C(-30882), INT16_C(-25369), INT16_C( 26232)),
      UINT8_C(108),
      simde_mm512_set_epi64(INT64_C(-8224370586313845882), INT64_C(-1993121323347227003),
                            INT64_C( 8831696545371448920), INT64_C( 2185815767663877612),
                            INT64_C( -270570670623534210), INT64_C(-7835605414239696560),
                            INT64_C(-1637430132815230795), INT64_C( 7232010829548987022)),
      simde_mm_set_epi16(INT16_C( -7256), INT16_C(-32768), INT16_C( 32767), INT16_C(  5582),
                         INT16_C(-32768), INT16_C(-32768), INT16_C(-25369), INT16_C( 26232)) },
    { simde_mm_set_epi16(INT16_C(-23624), INT16_C(   938), INT16_C(-27082), INT16_C(-23731),
                         INT16_C( 28546), INT16_C(  6104), INT16_C(  -771), INT16_C(-18938)),
      UINT8_C(212),
      simde_mm512_set_epi64(INT64_C(-3956629285800542954), INT64_C( 7768661847448918660),
                            INT64_C( 8414129281940348180), INT64_C(-3282225164507364365),
                            INT64_C( 3972788221445796445), INT64_C(-1066584669561441235),
                            INT64_C( 2182845185502488635), INT64_C(-2591044625591562731)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C(-27082), INT16_C(-32768),
                         INT16_C( 28546), INT16_C(-32768), INT16_C(  -771), INT16_C(-18938)) },
    { simde_mm_set_epi16(INT16_C( 24446), INT16_C( 26366), INT16_C(  9634), INT16_C( 24482),
                         INT16_C(-31753), INT16_C(-24279), INT16_C(  -804), INT16_C(-22449)),
      UINT8_C( 80),
      simde_mm512_set_epi64(INT64_C( 5062048906197334415), INT64_C( -115992959878725320),
                            INT64_C( 1136786795492082678), INT64_C(-1948109654186813959),
                            INT64_C(  120681793319816518), INT64_C(-3982161075345546564),
                            INT64_C(-4623140196798581694), INT64_C(-1633613586256931500)),
      simde_mm_set_epi16(INT16_C( 24446), INT16_C(-32768), INT16_C(  9634), INT16_C(-32768),
                         INT16_C(-31753), INT16_C(-24279), INT16_C(  -804), INT16_C(-22449)) },
    { simde_mm_set_epi16(INT16_C(-14923), INT16_C(-18218), INT16_C(-13943), INT16_C(-15293),
                         INT16_C( 28087), INT16_C( 23347), INT16_C( 20051), INT16_C(-29378)),
      UINT8_C(249),
      simde_mm512_set_epi64(INT64_C( 5851174439164188465), INT64_C(-6319779881941429071),
                            INT64_C( 1879763181654775792), INT64_C( 4044922446109520806),
                            INT64_C( 1345671618220988839), INT64_C(-8367274893382946539),
                            INT64_C( 4386554571925238747), INT64_C(-2885812676818812761)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C( 32767), INT16_C( 32767),
                         INT16_C( 32767), INT16_C( 23347), INT16_C( 20051), INT16_C(-32768)) },
    { simde_mm_set_epi16(INT16_C( 20263), INT16_C( 24618), INT16_C(-21646), INT16_C( 25026),
                         INT16_C(  2086), INT16_C( 23935), INT16_C(-28550), INT16_C(-31813)),
      UINT8_C( 46),
      simde_mm512_set_epi64(INT64_C(-5543414139022216695), INT64_C(-7351051862345725962),
                            INT64_C( 7765938089573807601), INT64_C(-8520500957815241015),
                            INT64_C(-4114690540063739335), INT64_C( 2127377446843006162),
                            INT64_C( 4629741254325605495), INT64_C( 6283226406328232321)),
      simde_mm_set_epi16(INT16_C( 20263), INT16_C( 24618), INT16_C( 32767), INT16_C( 25026),
                         INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C(-31813)) },
    { simde_mm_set_epi16(INT16_C(-20607), INT16_C(-21929), INT16_C( 13898), INT16_C(  -678),
                         INT16_C(-11799), INT16_C( 18714), INT16_C( 16705), INT16_C( 22144)),
      UINT8_C(244),
      simde_mm512_set_epi64(INT64_C( 3168330803816226018), INT64_C(-5665190690683619181),
                            INT64_C(-6479275574786056503), INT64_C(-4854337280374936929),
                            INT64_C( 9110007504327473973), INT64_C( 2306966881245130829),
                            INT64_C( 3371747741827789856), INT64_C( 4883552887250537067)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768),
                         INT16_C(-11799), INT16_C( 32767), INT16_C( 16705), INT16_C( 22144)) },
    { simde_mm_set_epi16(INT16_C( -8975), INT16_C( 24160), INT16_C( 10567), INT16_C(-31950),
                         INT16_C( -1066), INT16_C(  1567), INT16_C(-20739), INT16_C(-21386)),
      UINT8_C( 84),
      simde_mm512_set_epi64(INT64_C(-5802305007366524132), INT64_C( 6368102336095963395),
                            INT64_C(   26715019440636716), INT64_C( 3396530625665467524),
                            INT64_C( 4010180268457941346), INT64_C( 5473964637387956828),
                            INT64_C( 6527063328512873018), INT64_C( 7600981363267795639)),
      simde_mm_set_epi16(INT16_C( -8975), INT16_C( 32767), INT16_C( 10567), INT16_C( 32767),
                         INT16_C( -1066), INT16_C( 32767), INT16_C(-20739), INT16_C(-21386)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_mask_cvtsepi64_epi16(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_cvtsepi64_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m128i r;
  } test_vec[8] = {
    { UINT8_C( 99),
      simde_mm512_set_epi64(INT64_C(-6773163771856001287), INT64_C( 8528895860955669022),
                            INT64_C(  743395091751495893), INT64_C(-5753646205421077345),
                            INT64_C( 6781795189594641427), INT64_C( 7308036127418939455),
                            INT64_C(  616165601606027604), INT64_C(-2694201555471274183)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C( 32767), INT16_C( 32767), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C( 32767), INT16_C(-32768)) },
    { UINT8_C( 41),
      simde_mm512_set_epi64(INT64_C( -270570670623534210), INT64_C(-7835605414239696560),
                            INT64_C(-1637430132815230795), INT64_C( 7232010829548987022),
                            INT64_C(  564423766678453237), INT64_C(-7165203031737464994),
                            INT64_C(-7140626015800786754), INT64_C(-2499691201975648498)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(-32768), INT16_C(     0),
                         INT16_C( 32767), INT16_C(     0), INT16_C(     0), INT16_C(-32768)) },
    { UINT8_C(236),
      simde_mm512_set_epi64(INT64_C( 2182845185502488635), INT64_C(-2591044625591562731),
                            INT64_C(  634126652413576106), INT64_C(-7622725766299379752),
                            INT64_C( -216817067777774970), INT64_C(-4785193871492054345),
                            INT64_C( 7467476729839254839), INT64_C( 3956665538785416156)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(-32768), INT16_C( 32767), INT16_C(     0),
                         INT16_C(-32768), INT16_C(-32768), INT16_C(     0), INT16_C(     0)) },
    { UINT8_C( 45),
      simde_mm512_set_epi64(INT64_C(-8852586683955255554), INT64_C( 2711835077233844521),
                            INT64_C( -226120820645741920), INT64_C(-5768129162479938358),
                            INT64_C( 4995224830392729088), INT64_C(-9204129394426957414),
                            INT64_C( 6102592944456478166), INT64_C(-5538879581396485404)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(-32768), INT16_C(     0),
                         INT16_C( 32767), INT16_C(-32768), INT16_C(     0), INT16_C(-32768)) },
    { UINT8_C( 84),
      simde_mm512_set_epi64(INT64_C( 5644010056631452329), INT64_C(  687917764947732740),
                            INT64_C( 9077991551678197137), INT64_C( 5379835588808993943),
                            INT64_C( 5669915352590237555), INT64_C(-7084358722419653223),
                            INT64_C(-5646349838748004740), INT64_C( 5115442951238204697)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C( 32767), INT16_C(     0), INT16_C( 32767),
                         INT16_C(     0), INT16_C(-32768), INT16_C(     0), INT16_C(     0)) },
    { UINT8_C( 51),
      simde_mm512_set_epi64(INT64_C( 6212879174325387943), INT64_C(-9195198218682338424),
                            INT64_C(-6314975051621021387), INT64_C(  316124606243108816),
                            INT64_C(-1018533604686287836), INT64_C( 7455766202425772200),
                            INT64_C( -151643922692032263), INT64_C(-4200247844809358269)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(-32768), INT16_C( 32767),
                         INT16_C(     0), INT16_C(     0), INT16_C(-32768), INT16_C(-32768)) },
    { UINT8_C(174),
      simde_mm512_set_epi64(INT64_C(-4824473637125509439), INT64_C( 2222300162020472452),
                            INT64_C( 4485933577556469028), INT64_C( 3606420641901871392),
                            INT64_C( 7533512282749681966), INT64_C( 5703633189469315522),
                            INT64_C(  587259603884606395), INT64_C( 5851174439164188465)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C(     0), INT16_C( 32767), INT16_C(     0),
                         INT16_C( 32767), INT16_C( 32767), INT16_C( 32767), INT16_C(     0)) },
    { UINT8_C(133),
      simde_mm512_set_epi64(INT64_C(-2795345254402041164), INT64_C( -585762482098414214),
                            INT64_C( 1037739329164009972), INT64_C(-5800167553526727334),
                            INT64_C(-3321042873096251776), INT64_C(-5543414139022216695),
                            INT64_C(-7351051862345725962), INT64_C( 7765938089573807601)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(-32768), INT16_C(     0), INT16_C( 32767)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm512_maskz_cvtsepi64_epi16(test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cvtsepi64_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(   -1385298216494496), INT64_C(       -996445051636),
                            INT64_C(             3207004), INT64_C(    -651667828674554),
                            INT64_C(   -3476602607657036), INT64_C(            -4627787),
                            INT64_C(   -2474879574406724), INT64_C(  508842849663014820)),
      simde_mm256_set_epi32(          INT32_MIN ,           INT32_MIN , INT32_C(    3207004),           INT32_MIN ,
                                      INT32_MIN , INT32_C(   -4627787),           INT32_MIN ,           INT32_MAX ) },
    { simde_mm512_set_epi64(INT64_C(                  -2), INT64_C(               -7621),
                            INT64_C(        296832081577), INT64_C(              -10040),
                            INT64_C(               10421), INT64_C(           316486368),
                            INT64_C(                -279), INT64_C(          1776399948)),
      simde_mm256_set_epi32(INT32_C(         -2), INT32_C(      -7621),           INT32_MAX , INT32_C(     -10040),
                            INT32_C(      10421), INT32_C(  316486368), INT32_C(       -279), INT32_C( 1776399948)) },
    { simde_mm512_set_epi64(INT64_C(   69786007435882969), INT64_C(-6327619736082157669),
                            INT64_C(      24285899089645), INT64_C(           -54009961),
                            INT64_C(        216203910725), INT64_C(               34664),
                            INT64_C(              760577), INT64_C(         52093180175)),
      simde_mm256_set_epi32(          INT32_MAX ,           INT32_MIN ,           INT32_MAX , INT32_C(  -54009961),
                                      INT32_MAX , INT32_C(      34664), INT32_C(     760577),           INT32_MAX ) },
    { simde_mm512_set_epi64(INT64_C(       -212538005711), INT64_C(                1541),
                            INT64_C(                  -1), INT64_C(  700703313895845440),
                            INT64_C(               -2820), INT64_C(  -13888321195009228),
                            INT64_C( -125614148245680479), INT64_C(                -251)),
      simde_mm256_set_epi32(          INT32_MIN , INT32_C(       1541), INT32_C(         -1),           INT32_MAX ,
                            INT32_C(      -2820),           INT32_MIN ,           INT32_MIN , INT32_C(       -251)) },
    { simde_mm512_set_epi64(INT64_C(          8722215763), INT64_C(   69834045587926754),
                            INT64_C(      14995086304428), INT64_C(               32908),
                            INT64_C(                  36), INT64_C(                   3),
                            INT64_C(           480756836), INT64_C(                  20)),
      simde_mm256_set_epi32(          INT32_MAX ,           INT32_MAX ,           INT32_MAX , INT32_C(      32908),
                            INT32_C(         36), INT32_C(          3), INT32_C(  480756836), INT32_C(         20)) },
    { simde_mm512_set_epi64(INT64_C(              393479), INT64_C(           -33215582),
                            INT64_C(           220007333), INT64_C(                  93),
                            INT64_C(            53663901), INT64_C(     456460283212472),
                            INT64_C(-4461760402649505374), INT64_C(       1569855624019)),
      simde_mm256_set_epi32(INT32_C(     393479), INT32_C(  -33215582), INT32_C(  220007333), INT32_C(         93),
                            INT32_C(   53663901),           INT32_MAX ,           INT32_MIN ,           INT32_MAX ) },
    { simde_mm512_set_epi64(INT64_C(             -360269), INT64_C(             -838041),
                            INT64_C(      68701792440150), INT64_C(      -8279642051532),
                            INT64_C(         12194321408), INT64_C(  -16610408706990781),
                            INT64_C(         31156899843), INT64_C(      -1087719579897)),
      simde_mm256_set_epi32(INT32_C(    -360269), INT32_C(    -838041),           INT32_MAX ,           INT32_MIN ,
                                      INT32_MAX ,           INT32_MIN ,           INT32_MAX ,           INT32_MIN ) },
    { simde_mm512_set_epi64(INT64_C(          -583546092), INT64_C(         -1051671055),
                            INT64_C(         -4042501098), INT64_C(        -81260673017),
                            INT64_C(               16230), INT64_C(                  -3),
                            INT64_C(      15889333151091), INT64_C(       -747559120874)),
      simde_mm256_set_epi32(INT32_C( -583546092), INT32_C(-1051671055),           INT32_MIN ,           INT32_MIN ,
                            INT32_C(      16230), INT32_C(         -3),           INT32_MAX ,           INT32_MIN ) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_cvtsepi64_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cvtsepi64_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -783872818), INT32_C(  224826276), INT32_C(  833953142), INT32_C(  704393899),
                            INT32_C(-1282792525), INT32_C(-1682931810), INT32_C( 1715663188), INT32_C(-1736532826)),
      UINT8_C(184),
      simde_mm512_set_epi64(INT64_C( -304424330925858839), INT64_C( 6920061078002113788),
                            INT64_C( 5392365268250659625), INT64_C( 7451707948021880068),
                            INT64_C(-8094918606566868518), INT64_C( 4039990350021559518),
                            INT64_C(-5079608809355355713), INT64_C( 4544449552448075830)),
      simde_mm256_set_epi32(INT32_MIN, INT32_C(  224826276), INT32_C( 2147483647), INT32_C( 2147483647),
                            INT32_MIN, INT32_C(-1682931810), INT32_C( 1715663188), INT32_C(-1736532826)) },
    { simde_mm256_set_epi32(INT32_C(  228147153), INT32_C( 1769984359), INT32_C( -876802121), INT32_C( -647616802),
                            INT32_C(-1031550247), INT32_C( -304505632), INT32_C(  452449791), INT32_C( -324230599)),
      UINT8_C( 65),
      simde_mm512_set_epi64(INT64_C(    7961945492670935), INT64_C(-8501526825185861704),
                            INT64_C( 8872615053841923423), INT64_C( -146553742277366704),
                            INT64_C(  634942473771684266), INT64_C(-8149949883580988621),
                            INT64_C(-5593558253107684500), INT64_C( -775182801274770337)),
      simde_mm256_set_epi32(INT32_C(  228147153), INT32_MIN, INT32_C( -876802121), INT32_C( -647616802),
                            INT32_C(-1031550247), INT32_C( -304505632), INT32_C(  452449791), INT32_MIN) },
    { simde_mm256_set_epi32(INT32_C( 1131322125), INT32_C(-1676568554), INT32_C( -296320699), INT32_C( 1382446137),
                            INT32_C( 1414899713), INT32_C(  334199932), INT32_C( -144765655), INT32_C( 1792521151)),
      UINT8_C( 87),
      simde_mm512_set_epi64(INT64_C( 5926848964672818106), INT64_C( 5125881974217215893),
                            INT64_C(-4592732829056100767), INT64_C(-5617139660166741281),
                            INT64_C( 8408189234922807969), INT64_C(   46860512120483389),
                            INT64_C( 4524750203780244200), INT64_C(-5543529261566757021)),
      simde_mm256_set_epi32(INT32_C( 1131322125), INT32_C( 2147483647), INT32_C( -296320699), INT32_MIN,
                            INT32_C( 1414899713), INT32_C( 2147483647), INT32_C( 2147483647), INT32_MIN) },
    { simde_mm256_set_epi32(INT32_C(  492196155), INT32_C(  311401987), INT32_C(-1826918634), INT32_C(  466373339),
                            INT32_C(  793993811), INT32_C( -275847262), INT32_C( 1108600799), INT32_C( -126394960)),
      UINT8_C(202),
      simde_mm512_set_epi64(INT64_C( 5858518275788586214), INT64_C( 6325882691723539358),
                            INT64_C( 1467602667059784657), INT64_C(-5469777716636073985),
                            INT64_C(-4718566456661627980), INT64_C(-8823362601370356535),
                            INT64_C( 3910769586217516674), INT64_C( 5379736184341507060)),
      simde_mm256_set_epi32(INT32_C( 2147483647), INT32_C( 2147483647), INT32_C(-1826918634), INT32_C(  466373339),
                            INT32_MIN, INT32_C( -275847262), INT32_C( 2147483647), INT32_C( -126394960)) },
    { simde_mm256_set_epi32(INT32_C( 1821029326), INT32_C( 1839096524), INT32_C(  594162196), INT32_C(-2140380523),
                            INT32_C(  445328546), INT32_C( 1418264985), INT32_C(  986213431), INT32_C(-1974658128)),
      UINT8_C(130),
      simde_mm512_set_epi64(INT64_C( 4654693694425511327), INT64_C( 4987555405601157538),
                            INT64_C(-3482406609442521151), INT64_C(  -74847652664381928),
                            INT64_C( 8566618987618331801), INT64_C( 7168824261247067964),
                            INT64_C( 3636052218697288232), INT64_C( 1769491692739488645)),
      simde_mm256_set_epi32(INT32_C( 2147483647), INT32_C( 1839096524), INT32_C(  594162196), INT32_C(-2140380523),
                            INT32_C(  445328546), INT32_C( 1418264985), INT32_C( 2147483647), INT32_C(-1974658128)) },
    { simde_mm256_set_epi32(INT32_C( -386374366), INT32_C( 1264203001), INT32_C(  448591089), INT32_C( -477219931),
                            INT32_C(  412806942), INT32_C( 1851486104), INT32_C(-1806146323), INT32_C(  -50243203)),
      UINT8_C(  4),
      simde_mm512_set_epi64(INT64_C( 2504249540805731307), INT64_C(-4838934383064989013),
                            INT64_C( 8244741120151641494), INT64_C( 4465455276942587795),
                            INT64_C(-6984757728940989206), INT64_C(-6611841259510994786),
                            INT64_C(-5737746940667504182), INT64_C( 5990707151189672678)),
      simde_mm256_set_epi32(INT32_C( -386374366), INT32_C( 1264203001), INT32_C(  448591089), INT32_C( -477219931),
                            INT32_C(  412806942), INT32_MIN, INT32_C(-1806146323), INT32_C(  -50243203)) },
    { simde_mm256_set_epi32(INT32_C(  694739216), INT32_C( -856286446), INT32_C( 1100751549), INT32_C(-1569791268),
                            INT32_C(-1217857754), INT32_C(-1399806754), INT32_C(  531097456), INT32_C(-1371358872)),
      UINT8_C( 39),
      simde_mm512_set_epi64(INT64_C( 5846906676369557746), INT64_C(-2200894904770223764),
                            INT64_C( 3050515010749934860), INT64_C( 1771796209347881841),
                            INT64_C(-8449543381956761958), INT64_C(-8910958770806120087),
                            INT64_C( 4697259477864506225), INT64_C( 1343234160387478022)),
      simde_mm256_set_epi32(INT32_C(  694739216), INT32_C( -856286446), INT32_C( 2147483647), INT32_C(-1569791268),
                            INT32_C(-1217857754), INT32_MIN, INT32_C( 2147483647), INT32_C( 2147483647)) },
    { simde_mm256_set_epi32(INT32_C(-1373417385), INT32_C(  748657731), INT32_C( 1483755877), INT32_C( 2104018565),
                            INT32_C(-1239060882), INT32_C( 1131976241), INT32_C( 1213166902), INT32_C( 1657511546)),
      UINT8_C( 72),
      simde_mm512_set_epi64(INT64_C( 8062252864411540983), INT64_C(-8797914700722318653),
                            INT64_C(-7262681553986948486), INT64_C( 5851217154060748384),
                            INT64_C(-8009878144581101693), INT64_C(-5600336949614751156),
                            INT64_C( 6240654256081358479), INT64_C(-7094305606247183129)),
      simde_mm256_set_epi32(INT32_C(-1373417385), INT32_MIN, INT32_C( 1483755877), INT32_C( 2104018565),
                            INT32_MIN, INT32_C( 1131976241), INT32_C( 1213166902), INT32_C( 1657511546)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_mask_cvtsepi64_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_cvtsepi64_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { UINT8_C(166),
      simde_mm512_set_epi64(INT64_C(-8094918606566868518), INT64_C( 4039990350021559518),
                            INT64_C(-5079608809355355713), INT64_C( 4544449552448075830),
                            INT64_C(  214030627736325326), INT64_C(  965621503535422838),
                            INT64_C( 3025348762719101875), INT64_C(-7228137083632422572)),
      simde_mm256_set_epi32(INT32_MIN, INT32_C(          0), INT32_MIN, INT32_C(          0),
                            INT32_C(          0), INT32_C( 2147483647), INT32_C( 2147483647), INT32_C(          0)) },
    { UINT8_C(  4),
      simde_mm512_set_epi64(INT64_C(-2040127053262929967), INT64_C( 7602024939754688439),
                            INT64_C(-2781492981666690343), INT64_C(-1307841730435361281),
                            INT64_C(-1392559814843402321), INT64_C( 1598109267473792738),
                            INT64_C(-1562013513342941276), INT64_C( 4124183631221082341)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( 2147483647), INT32_C(          0), INT32_C(          0)) },
    { UINT8_C( 95),
      simde_mm512_set_epi64(INT64_C( 7698819720935131480), INT64_C(-1959125385312173467),
                            INT64_C( 4636349956089830497), INT64_C(-2231536501614225883),
                            INT64_C(-2662282344960899888), INT64_C(-2740420949015425086),
                            INT64_C(-2599910470561320857), INT64_C(-7129238424086773927)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_MIN, INT32_C(          0), INT32_MIN,
                            INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN) },
    { UINT8_C( 41),
      simde_mm512_set_epi64(INT64_C( 7926549609163252623), INT64_C(-8658624789933032605),
                            INT64_C( 3670203061911626838), INT64_C( 5886946783247035777),
                            INT64_C(-1561491900908529833), INT64_C( 4858991530734622742),
                            INT64_C(-1272687709950413767), INT64_C( 6076947994788985980)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C( 2147483647), INT32_C(          0),
                            INT32_MIN, INT32_C(          0), INT32_C(          0), INT32_C( 2147483647)) },
    { UINT8_C( 61),
      simde_mm512_set_epi64(INT64_C( 9006543894860367562), INT64_C( 2113966389253348867),
                            INT64_C(-7846555785016620325), INT64_C( 3410177455490525090),
                            INT64_C( 4761404180193041840), INT64_C( 5926848964672818106),
                            INT64_C( 5125881974217215893), INT64_C(-4592732829056100767)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_MIN, INT32_C( 2147483647),
                            INT32_C( 2147483647), INT32_C( 2147483647), INT32_C(          0), INT32_MIN) },
    { UINT8_C(142),
      simde_mm512_set_epi64(INT64_C( 4235754435341261744), INT64_C( 5858518275788586214),
                            INT64_C( 6325882691723539358), INT64_C( 1467602667059784657),
                            INT64_C(-5469777716636073985), INT64_C(-4718566456661627980),
                            INT64_C(-8823362601370356535), INT64_C( 3910769586217516674)),
      simde_mm256_set_epi32(INT32_C( 2147483647), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_MIN, INT32_MIN, INT32_MIN, INT32_C(          0)) },
    { UINT8_C(153),
      simde_mm512_set_epi64(INT64_C(  -74847652664381928), INT64_C( 8566618987618331801),
                            INT64_C( 7168824261247067964), INT64_C( 3636052218697288232),
                            INT64_C( 1769491692739488645), INT64_C(-4519209933294881842),
                            INT64_C( 7898859425361441300), INT64_C(-9192864346835047262)),
      simde_mm256_set_epi32(INT32_MIN, INT32_C(          0), INT32_C(          0), INT32_C( 2147483647),
                            INT32_C( 2147483647), INT32_C(          0), INT32_C(          0), INT32_MIN) },
    { UINT8_C(193),
      simde_mm512_set_epi64(INT64_C( 5990707151189672678), INT64_C( 2863208564165993762),
                            INT64_C( 5429710545248646385), INT64_C(-2049643996231569634),
                            INT64_C( 7952072268167275757), INT64_C( -215792912647533760),
                            INT64_C(-2126906703336744137), INT64_C( 6372507310579515811)),
      simde_mm256_set_epi32(INT32_C( 2147483647), INT32_C( 2147483647), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( 2147483647)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_maskz_cvtsepi64_epi32(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsepi32_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsepi32_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsepi64_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtsepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtsepi32_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtsepi32_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtsepi64_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtsepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cvtsepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_cvtsepi16_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtsepi32_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cvtsepi32_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_cvtsepi32_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtsepi32_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cvtsepi32_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_cvtsepi32_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtsepi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cvtsepi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_cvtsepi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtsepi64_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cvtsepi64_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_cvtsepi64_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtsepi64_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cvtsepi64_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_cvtsepi64_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
