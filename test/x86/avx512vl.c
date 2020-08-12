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

#define SIMDE_TESTS_CURRENT_ISAX avx512vl
#include <simde/x86/avx512vl.h>
#include <test/x86/test-avx512.h>

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
test_simde_mm_mask_abs_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C( 115), -INT8_C(  14), -INT8_C(  39), -INT8_C(  78),  INT8_C(  20), -INT8_C( 119),  INT8_C(  90), -INT8_C(  11),
         INT8_C(  38),  INT8_C(  60),  INT8_C(  35),  INT8_C(  25), -INT8_C(  81),  INT8_C(  45),  INT8_C(  59), -INT8_C(  89) },
      UINT16_C(61702),
      { -INT8_C( 102),  INT8_C(  16), -INT8_C( 119), -INT8_C(   7),  INT8_C(  26),  INT8_C( 102),  INT8_C(  48), -INT8_C( 119),
         INT8_C(  49), -INT8_C(  12), -INT8_C(  14),  INT8_C( 101), -INT8_C(  13), -INT8_C( 109),  INT8_C(  16), -INT8_C(  69) },
      {  INT8_C( 115),  INT8_C(  16),  INT8_C( 119), -INT8_C(  78),  INT8_C(  20), -INT8_C( 119),  INT8_C(  90), -INT8_C(  11),
         INT8_C(  49),  INT8_C(  60),  INT8_C(  35),  INT8_C(  25),  INT8_C(  13),  INT8_C( 109),  INT8_C(  16),  INT8_C(  69) } },
    { {  INT8_C( 105), -INT8_C( 125),  INT8_C(  57), -INT8_C(  42),  INT8_C( 112),  INT8_C(   9),  INT8_C(  90),  INT8_C(  60),
        -INT8_C(  44), -INT8_C(  15),  INT8_C( 105), -INT8_C(  88), -INT8_C(  21),  INT8_C(  36), -INT8_C(  54), -INT8_C(   5) },
      UINT16_C(16140),
      {  INT8_C(  85), -INT8_C(  80),  INT8_C(  35), -INT8_C( 120), -INT8_C(   2), -INT8_C( 126),  INT8_C(   4),  INT8_C(   2),
         INT8_C(  53), -INT8_C(  97), -INT8_C(  98), -INT8_C(  97), -INT8_C(   5),      INT8_MAX,  INT8_C(  32),  INT8_C(   2) },
      {  INT8_C( 105), -INT8_C( 125),  INT8_C(  35),  INT8_C( 120),  INT8_C( 112),  INT8_C(   9),  INT8_C(  90),  INT8_C(  60),
         INT8_C(  53),  INT8_C(  97),  INT8_C(  98),  INT8_C(  97),  INT8_C(   5),      INT8_MAX, -INT8_C(  54), -INT8_C(   5) } },
    { {  INT8_C(  57),  INT8_C(  51),  INT8_C(  59), -INT8_C(  24), -INT8_C(  59), -INT8_C( 127),  INT8_C( 102), -INT8_C(  27),
         INT8_C(  72),  INT8_C( 126),  INT8_C(  55),  INT8_C(   1),  INT8_C( 102),  INT8_C(  38), -INT8_C(   4),  INT8_C(  93) },
      UINT16_C(22560),
      { -INT8_C(  37), -INT8_C(  17), -INT8_C( 118),  INT8_C(  37), -INT8_C( 112), -INT8_C(  73), -INT8_C(  20), -INT8_C(   3),
         INT8_C(  65),  INT8_C(   0), -INT8_C(  19),  INT8_C(  33),  INT8_C(  99),  INT8_C(  38), -INT8_C(  14), -INT8_C(  68) },
      {  INT8_C(  57),  INT8_C(  51),  INT8_C(  59), -INT8_C(  24), -INT8_C(  59),  INT8_C(  73),  INT8_C( 102), -INT8_C(  27),
         INT8_C(  72),  INT8_C( 126),  INT8_C(  55),  INT8_C(  33),  INT8_C(  99),  INT8_C(  38),  INT8_C(  14),  INT8_C(  93) } },
    { { -INT8_C(  81),  INT8_C( 103), -INT8_C(  37),  INT8_C(  36), -INT8_C(  58), -INT8_C(  71),  INT8_C(  10), -INT8_C(   8),
        -INT8_C(  90), -INT8_C(  33), -INT8_C(  34),  INT8_C(  31),  INT8_C( 116), -INT8_C(   1), -INT8_C(  63), -INT8_C(   2) },
      UINT16_C(16195),
      {  INT8_C( 106),  INT8_C(  92), -INT8_C(  34), -INT8_C(  79), -INT8_C(  62),  INT8_C(  72), -INT8_C(   3),  INT8_C(  17),
         INT8_C( 107), -INT8_C(  70), -INT8_C(  97), -INT8_C( 103), -INT8_C(  45), -INT8_C( 123), -INT8_C(   5), -INT8_C(  87) },
      {  INT8_C( 106),  INT8_C(  92), -INT8_C(  37),  INT8_C(  36), -INT8_C(  58), -INT8_C(  71),  INT8_C(   3), -INT8_C(   8),
         INT8_C( 107),  INT8_C(  70),  INT8_C(  97),  INT8_C( 103),  INT8_C(  45),  INT8_C( 123), -INT8_C(  63), -INT8_C(   2) } },
    { { -INT8_C( 117), -INT8_C(  50), -INT8_C(   3),  INT8_C(  21), -INT8_C(  14), -INT8_C( 123),  INT8_C(  98),  INT8_C( 119),
        -INT8_C( 121), -INT8_C(  35),  INT8_C(  12), -INT8_C(  82), -INT8_C(  93),  INT8_C(  40),  INT8_C(  26), -INT8_C(  79) },
      UINT16_C(29568),
      { -INT8_C(  44),  INT8_C(  14),  INT8_C(  65), -INT8_C( 112),  INT8_C(  49),  INT8_C(  81),  INT8_C(  38),  INT8_C(  71),
         INT8_C(  11),  INT8_C(  26), -INT8_C(  44),  INT8_C(  39),  INT8_C( 116),  INT8_C(  41), -INT8_C( 105), -INT8_C(  71) },
      { -INT8_C( 117), -INT8_C(  50), -INT8_C(   3),  INT8_C(  21), -INT8_C(  14), -INT8_C( 123),  INT8_C(  98),  INT8_C(  71),
         INT8_C(  11),  INT8_C(  26),  INT8_C(  12), -INT8_C(  82),  INT8_C( 116),  INT8_C(  41),  INT8_C( 105), -INT8_C(  79) } },
    { { -INT8_C( 122), -INT8_C(  67),      INT8_MIN,  INT8_C( 104),  INT8_C(  85),      INT8_MIN, -INT8_C(  85), -INT8_C(  90),
        -INT8_C( 123),  INT8_C(  72),  INT8_C( 109),  INT8_C(  61), -INT8_C(   9),  INT8_C(  22),  INT8_C(  63),  INT8_C(   2) },
      UINT16_C(24034),
      { -INT8_C(  77),  INT8_C(  93),  INT8_C( 122),  INT8_C(  26),  INT8_C(  53), -INT8_C(   6), -INT8_C(  88), -INT8_C( 106),
        -INT8_C(  81),  INT8_C(  24),  INT8_C( 109), -INT8_C( 113),  INT8_C(  69), -INT8_C(  26), -INT8_C(  67),  INT8_C(  26) },
      { -INT8_C( 122),  INT8_C(  93),      INT8_MIN,  INT8_C( 104),  INT8_C(  85),  INT8_C(   6),  INT8_C(  88),  INT8_C( 106),
         INT8_C(  81),  INT8_C(  72),  INT8_C( 109),  INT8_C( 113),  INT8_C(  69),  INT8_C(  22),  INT8_C(  67),  INT8_C(   2) } },
    { {  INT8_C(  61), -INT8_C( 112), -INT8_C(  20),  INT8_C( 115),  INT8_C(  91), -INT8_C(  47), -INT8_C(  94), -INT8_C(  48),
         INT8_C(  13),  INT8_C(  17), -INT8_C( 121), -INT8_C(  53),  INT8_C(  98), -INT8_C(   9), -INT8_C(  39), -INT8_C(  82) },
      UINT16_C(34747),
      { -INT8_C( 105), -INT8_C(  92),  INT8_C(  17), -INT8_C(  55), -INT8_C( 127), -INT8_C(  14),  INT8_C(  79),  INT8_C( 123),
        -INT8_C(  78),  INT8_C(  70),  INT8_C(  37),  INT8_C(  87), -INT8_C(  52),  INT8_C(  75), -INT8_C(  98), -INT8_C(  26) },
      {  INT8_C( 105),  INT8_C(  92), -INT8_C(  20),  INT8_C(  55),      INT8_MAX,  INT8_C(  14), -INT8_C(  94),  INT8_C( 123),
         INT8_C(  78),  INT8_C(  70),  INT8_C(  37), -INT8_C(  53),  INT8_C(  98), -INT8_C(   9), -INT8_C(  39),  INT8_C(  26) } },
    { { -INT8_C(  89), -INT8_C(  81),  INT8_C(  27), -INT8_C(  66), -INT8_C( 104),  INT8_C(  27),  INT8_C(  70),  INT8_C( 113),
         INT8_C( 106), -INT8_C( 107), -INT8_C( 123),  INT8_C(  49),  INT8_C(  96), -INT8_C(  86),  INT8_C(  88), -INT8_C(  26) },
      UINT16_C(19488),
      { -INT8_C(  47),  INT8_C( 126),      INT8_MAX, -INT8_C(  96),  INT8_C(  81), -INT8_C(  29),  INT8_C(   8), -INT8_C(  35),
         INT8_C(  14),  INT8_C(  19), -INT8_C( 126),  INT8_C( 125), -INT8_C(  16),  INT8_C(  66), -INT8_C(  59), -INT8_C(  53) },
      { -INT8_C(  89), -INT8_C(  81),  INT8_C(  27), -INT8_C(  66), -INT8_C( 104),  INT8_C(  29),  INT8_C(  70),  INT8_C( 113),
         INT8_C( 106), -INT8_C( 107),  INT8_C( 126),  INT8_C( 125),  INT8_C(  96), -INT8_C(  86),  INT8_C(  59), -INT8_C(  26) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi8(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_mask_abs_epi8(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_abs_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(57432),
      {  INT8_C(  44),  INT8_C(  47), -INT8_C( 120),  INT8_C( 111), -INT8_C(  65),  INT8_C(  87),  INT8_C(  90),  INT8_C(  38),
         INT8_C(  10),  INT8_C(  24), -INT8_C(  56), -INT8_C(  43), -INT8_C( 119),  INT8_C( 102), -INT8_C(  58),  INT8_C(  89) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111),  INT8_C(  65),  INT8_C(   0),  INT8_C(  90),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 102),  INT8_C(  58),  INT8_C(  89) } },
    { UINT16_C(21485),
      {  INT8_C(  28),  INT8_C(  88),  INT8_C(  30), -INT8_C(  28), -INT8_C(  93), -INT8_C(  61),  INT8_C(  19),  INT8_C(  71),
        -INT8_C(  40), -INT8_C(   4), -INT8_C( 116), -INT8_C(  23), -INT8_C(   3), -INT8_C(  67),  INT8_C( 102),  INT8_C(  23) },
      {  INT8_C(  28),  INT8_C(   0),  INT8_C(  30),  INT8_C(  28),  INT8_C(   0),  INT8_C(  61),  INT8_C(  19),  INT8_C(  71),
         INT8_C(  40),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C( 102),  INT8_C(   0) } },
    { UINT16_C(21564),
      {  INT8_C(   2), -INT8_C(  52),  INT8_C( 110), -INT8_C(  13),  INT8_C(  53), -INT8_C( 127),  INT8_C(  61), -INT8_C(  25),
         INT8_C( 101), -INT8_C(   7), -INT8_C( 107),  INT8_C(  67),  INT8_C(  59),  INT8_C( 123),  INT8_C(  35), -INT8_C( 120) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C( 110),  INT8_C(  13),  INT8_C(  53),      INT8_MAX,  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 107),  INT8_C(   0),  INT8_C(  59),  INT8_C(   0),  INT8_C(  35),  INT8_C(   0) } },
    { UINT16_C(51548),
      { -INT8_C(  64),  INT8_C(  83),  INT8_C( 100), -INT8_C(  30),  INT8_C(  81), -INT8_C(  69),  INT8_C( 123),  INT8_C(  41),
         INT8_C(  60),  INT8_C(  42),  INT8_C(  78),  INT8_C(  33),  INT8_C(  84), -INT8_C(   1),  INT8_C(  94),  INT8_C(  63) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C( 100),  INT8_C(  30),  INT8_C(  81),  INT8_C(   0),  INT8_C( 123),  INT8_C(   0),
         INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(  33),  INT8_C(   0),  INT8_C(   0),  INT8_C(  94),  INT8_C(  63) } },
    { UINT16_C(13397),
      { -INT8_C( 105),  INT8_C(  53), -INT8_C(  18), -INT8_C( 116), -INT8_C( 108),  INT8_C(  36),  INT8_C(  83),  INT8_C( 110),
        -INT8_C(  23), -INT8_C(  15),  INT8_C(  70),  INT8_C(   2), -INT8_C( 110), -INT8_C( 126),  INT8_C( 110),  INT8_C( 117) },
      {  INT8_C( 105),  INT8_C(   0),  INT8_C(  18),  INT8_C(   0),  INT8_C( 108),  INT8_C(   0),  INT8_C(  83),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  70),  INT8_C(   0),  INT8_C( 110),  INT8_C( 126),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(25039),
      { -INT8_C( 113),  INT8_C(  73), -INT8_C(  72), -INT8_C(  54),  INT8_C(  79),  INT8_C(  50), -INT8_C(  17), -INT8_C(  75),
        -INT8_C( 121),  INT8_C( 107),  INT8_C(  94), -INT8_C( 105), -INT8_C(  33),  INT8_C( 111),  INT8_C(  57), -INT8_C(  24) },
      {  INT8_C( 113),  INT8_C(  73),  INT8_C(  72),  INT8_C(  54),  INT8_C(   0),  INT8_C(   0),  INT8_C(  17),  INT8_C(  75),
         INT8_C( 121),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111),  INT8_C(  57),  INT8_C(   0) } },
    { UINT16_C(40507),
      { -INT8_C(  10), -INT8_C(  56),  INT8_C(   2), -INT8_C( 109),  INT8_C(  40), -INT8_C(  13),  INT8_C(  16),  INT8_C(  50),
        -INT8_C(  69),  INT8_C(  97), -INT8_C(  32),  INT8_C(  88), -INT8_C(  63),  INT8_C(  58),  INT8_C(  62), -INT8_C(  97) },
      {  INT8_C(  10),  INT8_C(  56),  INT8_C(   0),  INT8_C( 109),  INT8_C(  40),  INT8_C(  13),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  97),  INT8_C(  32),  INT8_C(  88),  INT8_C(  63),  INT8_C(   0),  INT8_C(   0),  INT8_C(  97) } },
    { UINT16_C(31988),
      { -INT8_C(  68),  INT8_C(   6),  INT8_C(  10),  INT8_C(  17),  INT8_C(  92),  INT8_C(  60), -INT8_C(  95), -INT8_C(  56),
         INT8_C( 106), -INT8_C( 113),  INT8_C(  12), -INT8_C(  97), -INT8_C(  56), -INT8_C(  73),  INT8_C(  21), -INT8_C(  95) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  10),  INT8_C(   0),  INT8_C(  92),  INT8_C(  60),  INT8_C(  95),  INT8_C(  56),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(  97),  INT8_C(  56),  INT8_C(  73),  INT8_C(  21),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_abs_epi8(test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_abs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  8153),  INT16_C( 16161),  INT16_C(  6855), -INT16_C( 17824), -INT16_C( 10464), -INT16_C( 18024), -INT16_C( 25775),  INT16_C( 32280) },
      UINT8_C( 66),
      {  INT16_C( 13385), -INT16_C( 15752),  INT16_C( 13235), -INT16_C( 19058),  INT16_C( 19462), -INT16_C(  3246), -INT16_C( 30050), -INT16_C(  6596) },
      {  INT16_C(  8153),  INT16_C( 15752),  INT16_C(  6855), -INT16_C( 17824), -INT16_C( 10464), -INT16_C( 18024),  INT16_C( 30050),  INT16_C( 32280) } },
    { {  INT16_C( 15536), -INT16_C( 28087), -INT16_C( 28835),  INT16_C( 17732),  INT16_C( 28497),  INT16_C(  9121),  INT16_C( 28628), -INT16_C( 30221) },
      UINT8_C( 56),
      {  INT16_C( 15263), -INT16_C( 25944), -INT16_C( 12189), -INT16_C(   659),  INT16_C( 23072),  INT16_C( 14027),  INT16_C( 26184),  INT16_C( 13567) },
      {  INT16_C( 15536), -INT16_C( 28087), -INT16_C( 28835),  INT16_C(   659),  INT16_C( 23072),  INT16_C( 14027),  INT16_C( 28628), -INT16_C( 30221) } },
    { { -INT16_C(  3774), -INT16_C(  7245),  INT16_C(  3049),  INT16_C(  7497), -INT16_C( 12617),  INT16_C( 28131),  INT16_C( 10527),  INT16_C(  6521) },
      UINT8_C(182),
      {  INT16_C( 23186), -INT16_C( 32513), -INT16_C( 16007),  INT16_C( 28358), -INT16_C(  7161), -INT16_C( 29226), -INT16_C( 31719),  INT16_C( 24598) },
      { -INT16_C(  3774),  INT16_C( 32513),  INT16_C( 16007),  INT16_C(  7497),  INT16_C(  7161),  INT16_C( 29226),  INT16_C( 10527),  INT16_C( 24598) } },
    { {  INT16_C( 28985), -INT16_C( 21137),  INT16_C(  9114), -INT16_C(   587),  INT16_C( 10616), -INT16_C( 12703), -INT16_C( 31567),  INT16_C( 22068) },
      UINT8_C( 76),
      {  INT16_C(  4627),  INT16_C( 12178), -INT16_C( 14639),  INT16_C( 24171), -INT16_C(  9608),  INT16_C( 30857), -INT16_C(   739), -INT16_C( 22827) },
      {  INT16_C( 28985), -INT16_C( 21137),  INT16_C( 14639),  INT16_C( 24171),  INT16_C( 10616), -INT16_C( 12703),  INT16_C(   739),  INT16_C( 22068) } },
    { { -INT16_C(  1171),  INT16_C(  7354), -INT16_C(  1877),  INT16_C( 16390), -INT16_C(  6177), -INT16_C(   784),  INT16_C( 22452),  INT16_C( 15509) },
      UINT8_C(230),
      {  INT16_C(  4801),  INT16_C(   872),  INT16_C( 16760), -INT16_C(  8622),  INT16_C( 24650), -INT16_C(  6092), -INT16_C( 25601), -INT16_C( 17682) },
      { -INT16_C(  1171),  INT16_C(   872),  INT16_C( 16760),  INT16_C( 16390), -INT16_C(  6177),  INT16_C(  6092),  INT16_C( 25601),  INT16_C( 17682) } },
    { { -INT16_C( 20314),  INT16_C( 14303), -INT16_C( 10837), -INT16_C( 17361), -INT16_C( 17869),  INT16_C(  9635), -INT16_C( 26066), -INT16_C( 16289) },
      UINT8_C(245),
      {  INT16_C(    14),  INT16_C(  8028), -INT16_C( 21476),  INT16_C( 17146), -INT16_C( 11337),  INT16_C( 20019), -INT16_C( 17783), -INT16_C(  6419) },
      {  INT16_C(    14),  INT16_C( 14303),  INT16_C( 21476), -INT16_C( 17361),  INT16_C( 11337),  INT16_C( 20019),  INT16_C( 17783),  INT16_C(  6419) } },
    { {  INT16_C(  4307),  INT16_C( 28142),  INT16_C( 27919),  INT16_C( 11490), -INT16_C(  8387), -INT16_C( 13172), -INT16_C( 10842),  INT16_C( 13655) },
      UINT8_C( 62),
      {  INT16_C( 26887),  INT16_C( 10704), -INT16_C(  3529), -INT16_C(  7720),  INT16_C( 27957), -INT16_C(  9436), -INT16_C(  7956), -INT16_C( 29431) },
      {  INT16_C(  4307),  INT16_C( 10704),  INT16_C(  3529),  INT16_C(  7720),  INT16_C( 27957),  INT16_C(  9436), -INT16_C( 10842),  INT16_C( 13655) } },
    { {  INT16_C( 29302), -INT16_C( 19446), -INT16_C( 25972),  INT16_C( 16877), -INT16_C(   505), -INT16_C(  4405),  INT16_C( 25296), -INT16_C( 23565) },
      UINT8_C(201),
      {  INT16_C(  9477),  INT16_C( 32174), -INT16_C( 29767),  INT16_C( 24616), -INT16_C(  3737), -INT16_C( 24240), -INT16_C( 27071),  INT16_C( 29624) },
      {  INT16_C(  9477), -INT16_C( 19446), -INT16_C( 25972),  INT16_C( 24616), -INT16_C(   505), -INT16_C(  4405),  INT16_C( 27071),  INT16_C( 29624) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_mask_abs_epi16(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_abs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(  9),
      { -INT16_C( 18170),  INT16_C(  3543), -INT16_C(  6732),  INT16_C(  2591),  INT16_C( 16089),  INT16_C( 25611), -INT16_C( 22208), -INT16_C( 26321) },
      {  INT16_C( 18170),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2591),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(246),
      {  INT16_C( 18289), -INT16_C( 24027), -INT16_C( 29991), -INT16_C(  1982),  INT16_C( 32714), -INT16_C(   354), -INT16_C( 22665),  INT16_C(  9312) },
      {  INT16_C(     0),  INT16_C( 24027),  INT16_C( 29991),  INT16_C(     0),  INT16_C( 32714),  INT16_C(   354),  INT16_C( 22665),  INT16_C(  9312) } },
    { UINT8_C(207),
      {  INT16_C( 11566),  INT16_C( 22926),  INT16_C( 14011), -INT16_C(  7358), -INT16_C( 18332),  INT16_C( 15086),  INT16_C( 13877),  INT16_C( 27416) },
      {  INT16_C( 11566),  INT16_C( 22926),  INT16_C( 14011),  INT16_C(  7358),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13877),  INT16_C( 27416) } },
    { UINT8_C( 86),
      { -INT16_C(  2382), -INT16_C(  5907),  INT16_C( 22152),  INT16_C( 19099),  INT16_C( 30599),  INT16_C(  3850), -INT16_C(  4906),  INT16_C(  4835) },
      {  INT16_C(     0),  INT16_C(  5907),  INT16_C( 22152),  INT16_C(     0),  INT16_C( 30599),  INT16_C(     0),  INT16_C(  4906),  INT16_C(     0) } },
    { UINT8_C(119),
      { -INT16_C( 32551), -INT16_C( 10402), -INT16_C( 27415), -INT16_C( 17203), -INT16_C( 15129),  INT16_C( 10840), -INT16_C(  3485), -INT16_C( 22834) },
      {  INT16_C( 32551),  INT16_C( 10402),  INT16_C( 27415),  INT16_C(     0),  INT16_C( 15129),  INT16_C( 10840),  INT16_C(  3485),  INT16_C(     0) } },
    { UINT8_C(  9),
      { -INT16_C( 16078), -INT16_C(  4277),  INT16_C(  6446), -INT16_C( 24958), -INT16_C(  6732), -INT16_C(  8610), -INT16_C( 25530),  INT16_C( 24833) },
      {  INT16_C( 16078),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24958),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(136),
      {  INT16_C(  2458),  INT16_C( 11322), -INT16_C( 10557),  INT16_C( 10157), -INT16_C( 13767),  INT16_C( 17938),  INT16_C( 29253), -INT16_C( 10355) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10157),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10355) } },
    { UINT8_C( 67),
      {  INT16_C(  3514), -INT16_C( 28361),  INT16_C( 31771),  INT16_C(  5728), -INT16_C(  9840),  INT16_C( 11002), -INT16_C(  7475), -INT16_C(  5133) },
      {  INT16_C(  3514),  INT16_C( 28361),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  7475),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_abs_epi16(test_vec[i].k, a);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_abs_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   688398243),  INT32_C(  2117596500), -INT32_C(   750842275),  INT32_C(   366535198) },
      UINT8_C(131),
      { -INT32_C(  1004016930), -INT32_C(  1077141926), -INT32_C(  2083644661),  INT32_C(   399895044) },
      {  INT32_C(  1004016930),  INT32_C(  1077141926), -INT32_C(   750842275),  INT32_C(   366535198) } },
    { {  INT32_C(  1632121691),  INT32_C(   483536164), -INT32_C(   526963188), -INT32_C(  1230342708) },
      UINT8_C(  2),
      {  INT32_C(  2145654124), -INT32_C(  1724078204), -INT32_C(   190821781), -INT32_C(  1219539762) },
      {  INT32_C(  1632121691),  INT32_C(  1724078204), -INT32_C(   526963188), -INT32_C(  1230342708) } },
    { { -INT32_C(   780236771),  INT32_C(  1976716971),  INT32_C(  1074971562),  INT32_C(  1213854368) },
      UINT8_C( 82),
      { -INT32_C(   767166523),  INT32_C(  1085468303), -INT32_C(   295595563),  INT32_C(   669742458) },
      { -INT32_C(   780236771),  INT32_C(  1085468303),  INT32_C(  1074971562),  INT32_C(  1213854368) } },
    { { -INT32_C(  1066078121),  INT32_C(  1916170187), -INT32_C(  1589423098), -INT32_C(   746781550) },
      UINT8_C(136),
      { -INT32_C(   802933306), -INT32_C(   186975219), -INT32_C(  1081305950),  INT32_C(  1075243371) },
      { -INT32_C(  1066078121),  INT32_C(  1916170187), -INT32_C(  1589423098),  INT32_C(  1075243371) } },
    { {  INT32_C(   955441731), -INT32_C(  1927520383),  INT32_C(   841960739), -INT32_C(  1971983518) },
      UINT8_C( 63),
      { -INT32_C(  1129031646), -INT32_C(  1553699482), -INT32_C(  1621136138), -INT32_C(   791151103) },
      {  INT32_C(  1129031646),  INT32_C(  1553699482),  INT32_C(  1621136138),  INT32_C(   791151103) } },
    { {  INT32_C(  2072269077),  INT32_C(  1390338014), -INT32_C(   681233355), -INT32_C(   586259273) },
      UINT8_C( 73),
      {  INT32_C(   289225178), -INT32_C(  1951535354), -INT32_C(  1646281947), -INT32_C(   283269702) },
      {  INT32_C(   289225178),  INT32_C(  1390338014), -INT32_C(   681233355),  INT32_C(   283269702) } },
    { {  INT32_C(   352437480), -INT32_C(   669662064), -INT32_C(  1349420366),  INT32_C(  1478068007) },
      UINT8_C( 52),
      { -INT32_C(  1411603801), -INT32_C(  1980243425),  INT32_C(   161641122), -INT32_C(  1088019476) },
      {  INT32_C(   352437480), -INT32_C(   669662064),  INT32_C(   161641122),  INT32_C(  1478068007) } },
    { { -INT32_C(   968386477), -INT32_C(   888428856), -INT32_C(   552543373), -INT32_C(  1460967715) },
      UINT8_C(167),
      { -INT32_C(  1057832772), -INT32_C(  1469689236), -INT32_C(   300347505), -INT32_C(    52757827) },
      {  INT32_C(  1057832772),  INT32_C(  1469689236),  INT32_C(   300347505), -INT32_C(  1460967715) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_mask_abs_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_abs_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(145),
      {  INT32_C(    29805490), -INT32_C(  2083285805),  INT32_C(   753740199), -INT32_C(  1343338556) },
      {  INT32_C(    29805490),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 58),
      { -INT32_C(  2072344551), -INT32_C(   137560356), -INT32_C(   577438960), -INT32_C(  1224979635) },
      {  INT32_C(           0),  INT32_C(   137560356),  INT32_C(           0),  INT32_C(  1224979635) } },
    { UINT8_C(109),
      {  INT32_C(   815986804), -INT32_C(   520418861), -INT32_C(  1705291520), -INT32_C(  1422986918) },
      {  INT32_C(   815986804),  INT32_C(           0),  INT32_C(  1705291520),  INT32_C(  1422986918) } },
    { UINT8_C(145),
      { -INT32_C(  1602009068),  INT32_C(   676272594),  INT32_C(  1754227610),  INT32_C(   567182279) },
      {  INT32_C(  1602009068),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(195),
      {  INT32_C(  1694336367),  INT32_C(   738012218),  INT32_C(    87416787), -INT32_C(  2145881269) },
      {  INT32_C(  1694336367),  INT32_C(   738012218),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 97),
      { -INT32_C(   444185248), -INT32_C(   216805061),  INT32_C(   376077454),  INT32_C(   835265240) },
      {  INT32_C(   444185248),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    {    UINT8_MAX,
      { -INT32_C(  1160186485),  INT32_C(  1353662651),  INT32_C(  2034799586), -INT32_C(   705717215) },
      {  INT32_C(  1160186485),  INT32_C(  1353662651),  INT32_C(  2034799586),  INT32_C(   705717215) } },
    { UINT8_C(168),
      {  INT32_C(  1699267364),  INT32_C(   479861968), -INT32_C(   177248900), -INT32_C(  1180950087) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1180950087) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_abs_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_abs_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 3102401361918078941),  INT64_C( 5987331142896800384) },
      {  INT64_C( 3102401361918078941),  INT64_C( 5987331142896800384) } },
    { { -INT64_C( 6165271089019809896), -INT64_C( 1488269006246725939) },
      {  INT64_C( 6165271089019809896),  INT64_C( 1488269006246725939) } },
    { { -INT64_C(  287912670071654876),  INT64_C( 3376558256458965752) },
      {  INT64_C(  287912670071654876),  INT64_C( 3376558256458965752) } },
    { { -INT64_C( 1699690728377702014),  INT64_C( 2927647255755636771) },
      {  INT64_C( 1699690728377702014),  INT64_C( 2927647255755636771) } },
    { { -INT64_C( 8959542323819455163),  INT64_C( 3365246129411480893) },
      {  INT64_C( 8959542323819455163),  INT64_C( 3365246129411480893) } },
    { {  INT64_C( 4227824362795330185),  INT64_C( 6194577401110150880) },
      {  INT64_C( 4227824362795330185),  INT64_C( 6194577401110150880) } },
    { {  INT64_C( 6873617928876373866),  INT64_C( 1262142814710839683) },
      {  INT64_C( 6873617928876373866),  INT64_C( 1262142814710839683) } },
    { {  INT64_C(  722086948698055913), -INT64_C( 4941936896584979953) },
      {  INT64_C(  722086948698055913),  INT64_C( 4941936896584979953) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_abs_epi64(a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_abs_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4845332346535929233),  INT64_C( 1700698435022438078) },
      UINT8_C(130),
      { -INT64_C( 6803045812735068648), -INT64_C( 7443449697644586270) },
      {  INT64_C( 4845332346535929233),  INT64_C( 7443449697644586270) } },
    { { -INT64_C( 6421298693609969513), -INT64_C( 6160319844260546176) },
      UINT8_C( 59),
      { -INT64_C( 4351657591194229711), -INT64_C( 8627740096035247728) },
      {  INT64_C( 4351657591194229711),  INT64_C( 8627740096035247728) } },
    { { -INT64_C( 8180037481821730213),  INT64_C( 7219960493591948494) },
      UINT8_C( 49),
      { -INT64_C( 6441345642108472215),  INT64_C( 4350044603238480648) },
      {  INT64_C( 6441345642108472215),  INT64_C( 7219960493591948494) } },
    { {  INT64_C( 4684076903763347163),  INT64_C( 6497802772857514833) },
      UINT8_C(205),
      { -INT64_C( 4870124432114791231),  INT64_C( 4454143856972221582) },
      {  INT64_C( 4870124432114791231),  INT64_C( 6497802772857514833) } },
    { { -INT64_C(  838855374297144746), -INT64_C( 2942560270663534524) },
      UINT8_C(120),
      {  INT64_C( 5641214509537388547),  INT64_C( 4712163805488714118) },
      { -INT64_C(  838855374297144746), -INT64_C( 2942560270663534524) } },
    { {  INT64_C( 7176515612344537603), -INT64_C( 8643734220088015145) },
      UINT8_C(168),
      { -INT64_C( 3490178188729363300),  INT64_C( 7993754077794638996) },
      {  INT64_C( 7176515612344537603), -INT64_C( 8643734220088015145) } },
    { { -INT64_C( 1529783215006713101), -INT64_C( 1978515024379923929) },
      UINT8_C(204),
      { -INT64_C( 8261273454123855187), -INT64_C(  408440238321563495) },
      { -INT64_C( 1529783215006713101), -INT64_C( 1978515024379923929) } },
    { { -INT64_C( 3158447172117950868), -INT64_C( 3303403632531072544) },
      UINT8_C( 84),
      { -INT64_C( 5291873217680795087),  INT64_C( 4801197429913235623) },
      { -INT64_C( 3158447172117950868), -INT64_C( 3303403632531072544) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_mask_abs_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_abs_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(158),
      { -INT64_C( 6298226099324920239), -INT64_C( 5000322151057574458) },
      {  INT64_C(                   0),  INT64_C( 5000322151057574458) } },
    { UINT8_C( 43),
      {  INT64_C( 2636038210509465369),  INT64_C( 7020928684628243752) },
      {  INT64_C( 2636038210509465369),  INT64_C( 7020928684628243752) } },
    { UINT8_C( 64),
      {  INT64_C( 7649134006013225985),  INT64_C( 2078749890811515096) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(207),
      {  INT64_C(  941032990317475364), -INT64_C( 6013459460053205151) },
      {  INT64_C(  941032990317475364),  INT64_C( 6013459460053205151) } },
    { UINT8_C(103),
      { -INT64_C( 1560295149959329567), -INT64_C( 3971587257135282239) },
      {  INT64_C( 1560295149959329567),  INT64_C( 3971587257135282239) } },
    { UINT8_C( 38),
      { -INT64_C( 5243445501069980794),  INT64_C( 4885633393584462144) },
      {  INT64_C(                   0),  INT64_C( 4885633393584462144) } },
    { UINT8_C( 94),
      {  INT64_C( 7243498660887455097),  INT64_C( 8890095449815425622) },
      {  INT64_C(                   0),  INT64_C( 8890095449815425622) } },
    { UINT8_C( 14),
      {  INT64_C( 7759806299451765498), -INT64_C( 6445959026453494579) },
      {  INT64_C(                   0),  INT64_C( 6445959026453494579) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_abs_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_abs_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( 2298255581870375211), INT64_C(-3544843370875867424),
                             INT64_C( 3174188203889017774), INT64_C(-2855144460944446932)),
      simde_mm256_set_epi64x(INT64_C( 2298255581870375211), INT64_C( 3544843370875867424),
                             INT64_C( 3174188203889017774), INT64_C( 2855144460944446932)) },
    { simde_mm256_set_epi64x(INT64_C(-2343577668018514218), INT64_C( 6125961421606078258),
                             INT64_C(-3940514899539048661), INT64_C(-1443470135985810906)),
      simde_mm256_set_epi64x(INT64_C( 2343577668018514218), INT64_C( 6125961421606078258),
                             INT64_C( 3940514899539048661), INT64_C( 1443470135985810906)) },
    { simde_mm256_set_epi64x(INT64_C(-5113251846863269416), INT64_C( 4963302814062391174),
                             INT64_C(-8692429813673586920), INT64_C(-1299515304381535234)),
      simde_mm256_set_epi64x(INT64_C( 5113251846863269416), INT64_C( 4963302814062391174),
                             INT64_C( 8692429813673586920), INT64_C( 1299515304381535234)) },
    { simde_mm256_set_epi64x(INT64_C( 8282900993993562890), INT64_C( -871234380790935570),
                             INT64_C( 1016547295723275308), INT64_C( 2445109086053031177)),
      simde_mm256_set_epi64x(INT64_C( 8282900993993562890), INT64_C(  871234380790935570),
                             INT64_C( 1016547295723275308), INT64_C( 2445109086053031177)) },
    { simde_mm256_set_epi64x(INT64_C( 2885698025168517941), INT64_C( 4164132731831874360),
                             INT64_C( 5579124789695570138), INT64_C(-5071075354474953440)),
      simde_mm256_set_epi64x(INT64_C( 2885698025168517941), INT64_C( 4164132731831874360),
                             INT64_C( 5579124789695570138), INT64_C( 5071075354474953440)) },
    { simde_mm256_set_epi64x(INT64_C(-3829241843042224259), INT64_C(-5265306480458209716),
                             INT64_C( -199503262700073332), INT64_C(-3406476690611433698)),
      simde_mm256_set_epi64x(INT64_C( 3829241843042224259), INT64_C( 5265306480458209716),
                             INT64_C(  199503262700073332), INT64_C( 3406476690611433698)) },
    { simde_mm256_set_epi64x(INT64_C(-8511077884182051912), INT64_C(-2833485123520542356),
                             INT64_C(-8333607306604449051), INT64_C(-3068466298309072119)),
      simde_mm256_set_epi64x(INT64_C( 8511077884182051912), INT64_C( 2833485123520542356),
                             INT64_C( 8333607306604449051), INT64_C( 3068466298309072119)) },
    { simde_mm256_set_epi64x(INT64_C( 2822112346803664079), INT64_C(  298455952410199790),
                             INT64_C(  966686671017309845), INT64_C( 9214147743026689710)),
      simde_mm256_set_epi64x(INT64_C( 2822112346803664079), INT64_C(  298455952410199790),
                             INT64_C(  966686671017309845), INT64_C( 9214147743026689710)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_abs_epi64(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_mask_abs_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i src;
    simde__mmask8 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(  623879162816280883), INT64_C(-3225900025883395735),
                             INT64_C(  411040496809638529), INT64_C(-7584870799288762128)),
      UINT8_C( 62),
      simde_mm256_set_epi64x(INT64_C(-4625946001506527479), INT64_C(-2791937557159189467),
                             INT64_C(-5209880226959401821), INT64_C(-2130118807554140301)),
      simde_mm256_set_epi64x(INT64_C( 4625946001506527479), INT64_C( 2791937557159189467),
                             INT64_C( 5209880226959401821), INT64_C(-7584870799288762128)) },
    { simde_mm256_set_epi64x(INT64_C( 8448739575006176562), INT64_C( 3518346377803159044),
                             INT64_C(  844328342996800488), INT64_C( 8434264651311772530)),
      UINT8_C(156),
      simde_mm256_set_epi64x(INT64_C(-2671163103984174033), INT64_C( 4562965894666802973),
                             INT64_C(-8366536480676858800), INT64_C( 6120742655549907249)),
      simde_mm256_set_epi64x(INT64_C( 2671163103984174033), INT64_C( 4562965894666802973),
                             INT64_C(  844328342996800488), INT64_C( 8434264651311772530)) },
    { simde_mm256_set_epi64x(INT64_C(-7191173410794127611), INT64_C( 3688037766287492394),
                             INT64_C( 1547230041795852910), INT64_C( 3059339057736759292)),
      UINT8_C(119),
      simde_mm256_set_epi64x(INT64_C(-6542580348328468330), INT64_C(   44667239404533068),
                             INT64_C( 2360079993551421998), INT64_C(  219045572964647829)),
      simde_mm256_set_epi64x(INT64_C(-7191173410794127611), INT64_C(   44667239404533068),
                             INT64_C( 2360079993551421998), INT64_C(  219045572964647829)) },
    { simde_mm256_set_epi64x(INT64_C( 4128283011258120213), INT64_C( -108361944871310768),
                             INT64_C(-7759705295173963093), INT64_C(-2624902131704570248)),
      UINT8_C( 75),
      simde_mm256_set_epi64x(INT64_C(-5879975501041972673), INT64_C( 4967758226257621489),
                             INT64_C( 7728804239548221103), INT64_C( 8515647311939165123)),
      simde_mm256_set_epi64x(INT64_C( 5879975501041972673), INT64_C( -108361944871310768),
                             INT64_C( 7728804239548221103), INT64_C( 8515647311939165123)) },
    { simde_mm256_set_epi64x(INT64_C(-2790757822212524741), INT64_C( 4593245805939314417),
                             INT64_C(  507611866393274703), INT64_C( 3764810505633876098)),
      UINT8_C(205),
      simde_mm256_set_epi64x(INT64_C(-8403106197018531632), INT64_C( 4361313410194959167),
                             INT64_C(-3471819223171854464), INT64_C(-1064109494582275885)),
      simde_mm256_set_epi64x(INT64_C( 8403106197018531632), INT64_C( 4361313410194959167),
                             INT64_C(  507611866393274703), INT64_C( 1064109494582275885)) },
    { simde_mm256_set_epi64x(INT64_C(-7284244723237547041), INT64_C(-2704891057065522880),
                             INT64_C( 2088703461327613834), INT64_C(-6691637034812206656)),
      UINT8_C( 53),
      simde_mm256_set_epi64x(INT64_C( 7087054034507278743), INT64_C(-1904829140491124246),
                             INT64_C(-8979305972799046958), INT64_C(-9028640504948081950)),
      simde_mm256_set_epi64x(INT64_C(-7284244723237547041), INT64_C( 1904829140491124246),
                             INT64_C( 2088703461327613834), INT64_C( 9028640504948081950)) },
    { simde_mm256_set_epi64x(INT64_C(-6774164690615400180), INT64_C(  169354612478585762),
                             INT64_C(-2560732297798063552), INT64_C(-5440475278226442040)),
      UINT8_C(226),
      simde_mm256_set_epi64x(INT64_C( 4140219913643893074), INT64_C( 8233690702404220943),
                             INT64_C(-8119230973072356120), INT64_C( 5725416174942475460)),
      simde_mm256_set_epi64x(INT64_C(-6774164690615400180), INT64_C(  169354612478585762),
                             INT64_C( 8119230973072356120), INT64_C(-5440475278226442040)) },
    { simde_mm256_set_epi64x(INT64_C(-3618167506666580601), INT64_C(-3565111142066299914),
                             INT64_C( 4487949165835396675), INT64_C( 3493476883354981965)),
      UINT8_C(162),
      simde_mm256_set_epi64x(INT64_C(-4298605512042857739), INT64_C(-8701289307647237142),
                             INT64_C(-3191212805157153492), INT64_C( 6189308541761658990)),
      simde_mm256_set_epi64x(INT64_C(-3618167506666580601), INT64_C(-3565111142066299914),
                             INT64_C( 3191212805157153492), INT64_C( 3493476883354981965)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_mask_abs_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_maskz_abs_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
  {  UINT8_C( 51),
     simde_mm256_set_epi64x(INT64_C(-5558947899438156608), INT64_C(-5328111225624005045),
                             INT64_C(-5266448436194518899), INT64_C(-3023513724998191945)),
     simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C( 5266448436194518899), INT64_C( 3023513724998191945)) },
  {  UINT8_C(192),
     simde_mm256_set_epi64x(INT64_C( 1820775813457202726), INT64_C( 8407143534854112894),
                             INT64_C( 1164468631328972115), INT64_C( 3847858140267031773)),
     simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)) },
  {  UINT8_C(150),
     simde_mm256_set_epi64x(INT64_C( 1329935347622458589), INT64_C(-6552239731915331500),
                             INT64_C(-5727672039115289046), INT64_C( 2814104926627850068)),
     simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 6552239731915331500),
                             INT64_C( 5727672039115289046), INT64_C(                   0)) },
  {  UINT8_C( 62),
     simde_mm256_set_epi64x(INT64_C(-5313485292314620515), INT64_C(-8562444952160280220),
                             INT64_C(-6743839490299418176), INT64_C(  -90311038632227591)),
     simde_mm256_set_epi64x(INT64_C( 5313485292314620515), INT64_C( 8562444952160280220),
                             INT64_C( 6743839490299418176), INT64_C(                   0)) },
  {  UINT8_C(146),
     simde_mm256_set_epi64x(INT64_C(  134169414195672899), INT64_C(-3653740064081149177),
                             INT64_C(-3907455768376978765), INT64_C(-2357591052420787867)),
     simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C( 3907455768376978765), INT64_C(                   0)) },
  {  UINT8_C( 80),
     simde_mm256_set_epi64x(INT64_C(-4112624575699262364), INT64_C( -503713654380207790),
                             INT64_C(-1026806857675583448), INT64_C( 3708988589081863948)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)) },
  {  UINT8_C( 70),
     simde_mm256_set_epi64x(INT64_C( 5155483861531614212), INT64_C(-1432515770334784350),
                             INT64_C( 5951616937413531378), INT64_C( 3407818380382978160)),
     simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 1432515770334784350),
                             INT64_C( 5951616937413531378), INT64_C(                   0)) },
  {  UINT8_C(215),
     simde_mm256_set_epi64x(INT64_C( 1187658108632559622), INT64_C( 3381325771936787939),
                             INT64_C(-4190080085529007037), INT64_C( 1815625056621359018)),
     simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 3381325771936787939),
                             INT64_C( 4190080085529007037), INT64_C( 1815625056621359018)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_maskz_abs_epi64(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mask_add_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
           { { -INT8_C(  27), -INT8_C( 117), -INT8_C(   6),  INT8_C(  88), -INT8_C(  46),  INT8_C(  97), -INT8_C(  33),  INT8_C(  41),
        -INT8_C(  39), -INT8_C(   6), -INT8_C(  94),  INT8_C(  57), -INT8_C(  33),  INT8_C(  58),  INT8_C( 124), -INT8_C(  31) },
      UINT16_C( 5189),
      {  INT8_C( 116),  INT8_C(  54), -INT8_C(  13),  INT8_C(   7), -INT8_C(  49), -INT8_C(  33), -INT8_C( 119),  INT8_C(  78),
         INT8_C(  14), -INT8_C(  94),  INT8_C(  14), -INT8_C(  68), -INT8_C(  88),  INT8_C(  20),  INT8_C(  70), -INT8_C( 115) },
      {  INT8_C(   9), -INT8_C( 104), -INT8_C(  11), -INT8_C( 116), -INT8_C(  58), -INT8_C(  28),  INT8_C(  17), -INT8_C( 115),
        -INT8_C(  25), -INT8_C( 123), -INT8_C(  27),  INT8_C(  40),  INT8_C(  24), -INT8_C(  71), -INT8_C(  96), -INT8_C(  45) },
      {  INT8_C( 125), -INT8_C( 117), -INT8_C(  24),  INT8_C(  88), -INT8_C(  46),  INT8_C(  97), -INT8_C( 102),  INT8_C(  41),
        -INT8_C(  39), -INT8_C(   6), -INT8_C(  13),  INT8_C(  57), -INT8_C(  64),  INT8_C(  58),  INT8_C( 124), -INT8_C(  31) } },
    { { -INT8_C(  98), -INT8_C(  92), -INT8_C(  38), -INT8_C(  68), -INT8_C(  41),  INT8_C( 122), -INT8_C(  22), -INT8_C(  38),
         INT8_C(  27), -INT8_C(  33),  INT8_C( 109), -INT8_C(  84), -INT8_C(  65), -INT8_C(  97), -INT8_C(  87), -INT8_C(  26) },
      UINT16_C(48315),
      {  INT8_C(  33), -INT8_C(  21),  INT8_C( 102),  INT8_C( 107), -INT8_C(  24),  INT8_C( 118), -INT8_C(  19), -INT8_C( 100),
         INT8_C(  41),  INT8_C(  78), -INT8_C(  81),  INT8_C(  11),  INT8_C(  38), -INT8_C( 101),  INT8_C(  39), -INT8_C( 103) },
      {  INT8_C(  68), -INT8_C(  83),      INT8_MIN,  INT8_C( 118), -INT8_C( 117),  INT8_C( 112), -INT8_C(  32), -INT8_C( 114),
         INT8_C(  16), -INT8_C(  45),  INT8_C(  93),  INT8_C(  38), -INT8_C(  71), -INT8_C(  60),  INT8_C(  99), -INT8_C(  64) },
      {  INT8_C( 101), -INT8_C( 104), -INT8_C(  38), -INT8_C(  31),  INT8_C( 115), -INT8_C(  26), -INT8_C(  22),  INT8_C(  42),
         INT8_C(  27), -INT8_C(  33),  INT8_C(  12),  INT8_C(  49), -INT8_C(  33),  INT8_C(  95), -INT8_C(  87),  INT8_C(  89) } },
    { { -INT8_C(  32), -INT8_C(  57),  INT8_C(  78), -INT8_C(  38), -INT8_C(  31), -INT8_C(  49), -INT8_C(   2), -INT8_C(  91),
         INT8_C( 122), -INT8_C( 124),  INT8_C(  43),  INT8_C( 111),  INT8_C(  13), -INT8_C(  53), -INT8_C(  99), -INT8_C(   7) },
      UINT16_C(55519),
      { -INT8_C( 112),  INT8_C(  59),  INT8_C(  27), -INT8_C(  75), -INT8_C(  30),  INT8_C(  46),  INT8_C(  88), -INT8_C(  37),
         INT8_C(  68), -INT8_C(  86), -INT8_C(  84), -INT8_C(  81),  INT8_C(  73), -INT8_C(  81),  INT8_C( 111),  INT8_C(  71) },
      {  INT8_C(  75),  INT8_C( 105),  INT8_C(  40), -INT8_C(  50), -INT8_C(  66),  INT8_C( 107), -INT8_C(  47),  INT8_C( 108),
        -INT8_C(  44), -INT8_C(  70), -INT8_C( 126),  INT8_C(  70),  INT8_C(  82), -INT8_C(  48), -INT8_C(  16), -INT8_C(  11) },
      { -INT8_C(  37), -INT8_C(  92),  INT8_C(  67), -INT8_C( 125), -INT8_C(  96), -INT8_C(  49),  INT8_C(  41),  INT8_C(  71),
         INT8_C( 122), -INT8_C( 124),  INT8_C(  43), -INT8_C(  11), -INT8_C( 101), -INT8_C(  53),  INT8_C(  95),  INT8_C(  60) } },
    { { -INT8_C(  10),  INT8_C(  74),  INT8_C(  22),      INT8_MAX, -INT8_C(  86), -INT8_C(  38), -INT8_C(  55), -INT8_C(  34),
         INT8_C(  37), -INT8_C(  93),  INT8_C( 113),  INT8_C(  90), -INT8_C(  22),  INT8_C(  95), -INT8_C(  30),  INT8_C(  36) },
      UINT16_C(49528),
      { -INT8_C(  86), -INT8_C(  18),  INT8_C(   8), -INT8_C(  80),  INT8_C(  64), -INT8_C( 123), -INT8_C(  65),  INT8_C(  70),
         INT8_C(  76), -INT8_C(  38),  INT8_C(  79),  INT8_C(   7), -INT8_C( 112), -INT8_C(  51),  INT8_C(  59),  INT8_C(  55) },
      { -INT8_C( 115), -INT8_C(  53), -INT8_C( 116), -INT8_C( 104),  INT8_C(  80),  INT8_C(  21),  INT8_C(  61),  INT8_C(   7),
        -INT8_C(  99), -INT8_C(  92), -INT8_C(  35),  INT8_C(  32), -INT8_C(   2),  INT8_C(  80),  INT8_C( 120), -INT8_C(  12) },
      { -INT8_C(  10),  INT8_C(  74),  INT8_C(  22),  INT8_C(  72), -INT8_C( 112), -INT8_C( 102), -INT8_C(   4), -INT8_C(  34),
        -INT8_C(  23), -INT8_C(  93),  INT8_C( 113),  INT8_C(  90), -INT8_C(  22),  INT8_C(  95), -INT8_C(  77),  INT8_C(  43) } },
    { {  INT8_C(   4),      INT8_MIN, -INT8_C(  71), -INT8_C(  17), -INT8_C(  48), -INT8_C(   5),      INT8_MAX,  INT8_C( 111),
         INT8_C( 107), -INT8_C( 122), -INT8_C( 126), -INT8_C(  76), -INT8_C( 121), -INT8_C(  65), -INT8_C( 115), -INT8_C(  46) },
      UINT16_C(28165),
      {  INT8_C(  27), -INT8_C(  48), -INT8_C(  86),  INT8_C(  54), -INT8_C(  32),  INT8_C(  59),  INT8_C( 122), -INT8_C(  12),
        -INT8_C(   6),  INT8_C(  28),  INT8_C(  89),  INT8_C(  69),  INT8_C(  57), -INT8_C(  19), -INT8_C(  99), -INT8_C(  37) },
      {  INT8_C(  97), -INT8_C(  39),  INT8_C( 120),  INT8_C( 103), -INT8_C(  90),  INT8_C(  20),  INT8_C( 101),  INT8_C(  30),
         INT8_C(  57),  INT8_C(  57), -INT8_C(  13),  INT8_C(  10),  INT8_C(  41), -INT8_C(  13), -INT8_C(  53),  INT8_C(  21) },
      {  INT8_C( 124),      INT8_MIN,  INT8_C(  34), -INT8_C(  17), -INT8_C(  48), -INT8_C(   5),      INT8_MAX,  INT8_C( 111),
         INT8_C( 107),  INT8_C(  85),  INT8_C(  76),  INT8_C(  79), -INT8_C( 121), -INT8_C(  32),  INT8_C( 104), -INT8_C(  46) } },
    { { -INT8_C( 125),  INT8_C( 109),  INT8_C(  50),  INT8_C(  49),  INT8_C(  76),  INT8_C(  38),  INT8_C(  43),  INT8_C(  37),
        -INT8_C( 125), -INT8_C(  52),  INT8_C( 115),  INT8_C( 100),  INT8_C(  45),  INT8_C(  74), -INT8_C(   5), -INT8_C( 110) },
      UINT16_C(47574),
      { -INT8_C(  76),  INT8_C(  26), -INT8_C( 112), -INT8_C(  90), -INT8_C(  73), -INT8_C( 123),  INT8_C(  15), -INT8_C(  19),
        -INT8_C(  57), -INT8_C(  58), -INT8_C(  79),  INT8_C(   7), -INT8_C(  26),  INT8_C(  47), -INT8_C(  11),      INT8_MAX },
      { -INT8_C(  44),  INT8_C(  76), -INT8_C(   8),  INT8_C(  91),  INT8_C(  64),  INT8_C(  42), -INT8_C(  48),  INT8_C(  22),
        -INT8_C(  10),  INT8_C(   4),  INT8_C(  93), -INT8_C(  57), -INT8_C(  42), -INT8_C(  31),  INT8_C( 109),  INT8_C(  88) },
      { -INT8_C( 125),  INT8_C( 102), -INT8_C( 120),  INT8_C(  49), -INT8_C(   9),  INT8_C(  38), -INT8_C(  33),  INT8_C(   3),
        -INT8_C(  67), -INT8_C(  52),  INT8_C( 115), -INT8_C(  50), -INT8_C(  68),  INT8_C(  16), -INT8_C(   5), -INT8_C(  41) } },
    { {  INT8_C(  20),  INT8_C(  50),  INT8_C(   9),  INT8_C(  94), -INT8_C(  69),  INT8_C(  31),  INT8_C(  50),  INT8_C(  65),
        -INT8_C(  79),  INT8_C( 123), -INT8_C(  96),  INT8_C(  34), -INT8_C(  70), -INT8_C(  37), -INT8_C(   3),  INT8_C(  22) },
      UINT16_C(58436),
      {  INT8_C( 126), -INT8_C(  47), -INT8_C( 126), -INT8_C(  42),  INT8_C(  30),  INT8_C( 111), -INT8_C(  34),  INT8_C(  96),
        -INT8_C(  65),  INT8_C(  94), -INT8_C(  39), -INT8_C(  47), -INT8_C(  73),  INT8_C( 120),  INT8_C(  10),  INT8_C(  18) },
      {  INT8_C(  72),  INT8_C(  25),  INT8_C(  71),  INT8_C(  82),  INT8_C( 115), -INT8_C(  50),  INT8_C(  16),  INT8_C(  21),
        -INT8_C(  37), -INT8_C(  92),  INT8_C(  58),  INT8_C(  57),  INT8_C(  41), -INT8_C(  77), -INT8_C( 116),  INT8_C(  92) },
      {  INT8_C(  20),  INT8_C(  50), -INT8_C(  55),  INT8_C(  94), -INT8_C(  69),  INT8_C(  31), -INT8_C(  18),  INT8_C(  65),
        -INT8_C(  79),  INT8_C( 123),  INT8_C(  19),  INT8_C(  34), -INT8_C(  70),  INT8_C(  43), -INT8_C( 106),  INT8_C( 110) } },
    { {  INT8_C(  29), -INT8_C(  38), -INT8_C(  54), -INT8_C( 111), -INT8_C(  23), -INT8_C(  86), -INT8_C(   8),  INT8_C(  21),
         INT8_C(  98),  INT8_C(  54),  INT8_C( 102), -INT8_C(  84),  INT8_C(  14),  INT8_C(  23),  INT8_C(  88),  INT8_C(  42) },
      UINT16_C(45295),
      {  INT8_C(   4),  INT8_C(  61),  INT8_C(  20), -INT8_C(  59),  INT8_C(  94),  INT8_C(  39), -INT8_C(  42),  INT8_C(  68),
        -INT8_C( 116),  INT8_C(  24), -INT8_C(  43), -INT8_C(  18),  INT8_C(  50),  INT8_C(  74), -INT8_C(  67),  INT8_C( 123) },
      { -INT8_C(   6),  INT8_C(   9),  INT8_C(  16), -INT8_C(  80), -INT8_C(  95),  INT8_C( 115), -INT8_C(  62),  INT8_C(  63),
        -INT8_C(  62), -INT8_C( 105),  INT8_C( 107), -INT8_C( 107), -INT8_C(  91), -INT8_C(  56), -INT8_C(  62), -INT8_C(  15) },
      { -INT8_C(   2),  INT8_C(  70),  INT8_C(  36),  INT8_C( 117), -INT8_C(  23), -INT8_C( 102), -INT8_C( 104), -INT8_C( 125),
         INT8_C(  98),  INT8_C(  54),  INT8_C( 102), -INT8_C(  84), -INT8_C(  41),  INT8_C(  18),  INT8_C(  88),  INT8_C( 108) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi8(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask_add_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_add_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(19804),
      {  INT8_C(  27),  INT8_C(  33), -INT8_C(  11),  INT8_C(  13), -INT8_C(  52),  INT8_C(  94),  INT8_C(  66),  INT8_C(  86),
         INT8_C(  52),  INT8_C(  23),  INT8_C(  93), -INT8_C(  33),  INT8_C(  78), -INT8_C(  48), -INT8_C(  30),  INT8_C(  75) },
      { -INT8_C(  37), -INT8_C(  52), -INT8_C(  84),  INT8_C( 110), -INT8_C(  15), -INT8_C(  31), -INT8_C(  23), -INT8_C(  34),
        -INT8_C( 103), -INT8_C(  38),  INT8_C(  65),  INT8_C(  33), -INT8_C(  16), -INT8_C(  52),  INT8_C(  35),  INT8_C( 109) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  95),  INT8_C( 123), -INT8_C(  67),  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),
        -INT8_C(  51),  INT8_C(   0), -INT8_C(  98),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0) } },
    { UINT16_C(50023),
      { -INT8_C(  40),  INT8_C(  67), -INT8_C(  16),  INT8_C(  53),  INT8_C(  73), -INT8_C(  64), -INT8_C(  41),  INT8_C( 124),
         INT8_C(  97), -INT8_C( 126),  INT8_C(  77), -INT8_C(  78), -INT8_C(  92), -INT8_C( 116),  INT8_C(  16), -INT8_C( 126) },
      {  INT8_C(  76), -INT8_C( 111),      INT8_MIN, -INT8_C(  99), -INT8_C(  91),  INT8_C( 102),  INT8_C(  51), -INT8_C(  30),
         INT8_C(  45), -INT8_C(  47),  INT8_C(  25),  INT8_C(  16),  INT8_C( 104), -INT8_C(  95), -INT8_C( 111),  INT8_C(  93) },
      {  INT8_C(  36), -INT8_C(  44),  INT8_C( 112),  INT8_C(   0),  INT8_C(   0),  INT8_C(  38),  INT8_C(  10),  INT8_C(   0),
        -INT8_C( 114),  INT8_C(  83),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  95), -INT8_C(  33) } },
    { UINT16_C( 6986),
      {  INT8_C( 119), -INT8_C(  75), -INT8_C( 115),  INT8_C( 108), -INT8_C(  41), -INT8_C(  83),  INT8_C(  24),  INT8_C( 118),
         INT8_C( 117),  INT8_C(  98), -INT8_C(  80),  INT8_C( 105), -INT8_C(  62), -INT8_C( 104), -INT8_C(  75),  INT8_C(  22) },
      {      INT8_MAX,  INT8_C( 109), -INT8_C(  49),  INT8_C( 103), -INT8_C(  97), -INT8_C(  46), -INT8_C(  64),  INT8_C(  44),
        -INT8_C( 126), -INT8_C( 107), -INT8_C(  14),  INT8_C(   2), -INT8_C(  58),  INT8_C(  69), -INT8_C(  19), -INT8_C(  91) },
      {  INT8_C(   0),  INT8_C(  34),  INT8_C(   0), -INT8_C(  45),  INT8_C(   0),  INT8_C(   0), -INT8_C(  40),  INT8_C(   0),
        -INT8_C(   9), -INT8_C(   9),  INT8_C(   0),  INT8_C( 107), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(36448),
      { -INT8_C(   7),  INT8_C( 119),  INT8_C( 107),  INT8_C(  82),  INT8_C( 101),  INT8_C(  83), -INT8_C(  83),  INT8_C( 116),
         INT8_C(  14),  INT8_C(  72),  INT8_C( 114),  INT8_C(   3), -INT8_C(  28), -INT8_C(   7),  INT8_C( 124), -INT8_C(  77) },
      { -INT8_C(  10), -INT8_C( 106),  INT8_C(  24),  INT8_C( 124), -INT8_C(  82), -INT8_C(  56), -INT8_C(  50),  INT8_C( 105),
         INT8_C(  61), -INT8_C( 116),  INT8_C(  93),  INT8_C(   9),  INT8_C(  50),  INT8_C(  96),  INT8_C(  92),  INT8_C(   3) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  27),  INT8_C( 123),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  44), -INT8_C(  49),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  74) } },
    { UINT16_C(37475),
      {  INT8_C(  88),  INT8_C(   7), -INT8_C(  30),  INT8_C(  23),  INT8_C(  11), -INT8_C(  12),  INT8_C(  22), -INT8_C( 112),
         INT8_C(   7),  INT8_C( 103), -INT8_C(  62),  INT8_C(  79),  INT8_C(  13), -INT8_C(   6),  INT8_C(   3),  INT8_C( 110) },
      { -INT8_C( 109),  INT8_C(  83), -INT8_C( 125), -INT8_C(  26), -INT8_C(  64),  INT8_C( 118), -INT8_C( 108),  INT8_C( 120),
         INT8_C(  65),  INT8_C(  56),  INT8_C( 108), -INT8_C(  19), -INT8_C(  92), -INT8_C(  43),  INT8_C(  59), -INT8_C(  82) },
      { -INT8_C(  21),  INT8_C(  90),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106), -INT8_C(  86),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  97),  INT8_C(   0),  INT8_C(   0), -INT8_C(  79),  INT8_C(   0),  INT8_C(   0),  INT8_C(  28) } },
    { UINT16_C(60868),
      { -INT8_C(  85),  INT8_C(  98), -INT8_C( 119),  INT8_C(  28), -INT8_C(  52),  INT8_C(  36), -INT8_C(  38),  INT8_C(  97),
        -INT8_C(  23),  INT8_C(  33),  INT8_C( 101),  INT8_C(  30), -INT8_C(  56),  INT8_C(  67), -INT8_C(  69), -INT8_C(  85) },
      { -INT8_C(  92),  INT8_C(  56),  INT8_C(   8),  INT8_C( 111),  INT8_C(  68), -INT8_C(  19), -INT8_C(  66),  INT8_C(  42),
         INT8_C(   1),  INT8_C(  32),  INT8_C( 112),  INT8_C(  10),  INT8_C(  11),  INT8_C( 114),  INT8_C( 126), -INT8_C( 127) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C( 111),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104), -INT8_C( 117),
        -INT8_C(  22),  INT8_C(   0), -INT8_C(  43),  INT8_C(  40),  INT8_C(   0), -INT8_C(  75),  INT8_C(  57),  INT8_C(  44) } },
    { UINT16_C(25877),
      {  INT8_C(  40), -INT8_C(  65),  INT8_C(  46), -INT8_C(  42), -INT8_C(  23),  INT8_C( 101),  INT8_C(  37),  INT8_C(  87),
         INT8_C( 109), -INT8_C(  69),  INT8_C(  80), -INT8_C(  44), -INT8_C(  53),  INT8_C(  53),  INT8_C(  52),  INT8_C( 114) },
      { -INT8_C( 100),  INT8_C(   3), -INT8_C(  25), -INT8_C(  36), -INT8_C(  90), -INT8_C(  81), -INT8_C( 115), -INT8_C( 101),
         INT8_C(  18),  INT8_C( 125), -INT8_C(  12),  INT8_C( 115), -INT8_C(  22), -INT8_C(   9),  INT8_C( 117),  INT8_C(  27) },
      { -INT8_C(  60),  INT8_C(   0),  INT8_C(  21),  INT8_C(   0), -INT8_C( 113),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
             INT8_MAX,  INT8_C(   0),  INT8_C(  68),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44), -INT8_C(  87),  INT8_C(   0) } },
    { UINT16_C( 8536),
      { -INT8_C(  44), -INT8_C(  95), -INT8_C(  28), -INT8_C(  36), -INT8_C( 103), -INT8_C(   7),  INT8_C(  72),  INT8_C(  25),
        -INT8_C( 117), -INT8_C( 114), -INT8_C(  95),  INT8_C(  17),  INT8_C(   7),  INT8_C(   1), -INT8_C(  44), -INT8_C(  70) },
      { -INT8_C(  68), -INT8_C(   8),  INT8_C(  12),  INT8_C(  65),  INT8_C( 102),  INT8_C(  62), -INT8_C(  99),  INT8_C( 118),
         INT8_C(   8), -INT8_C(  26),  INT8_C(  94),  INT8_C(  54),  INT8_C(   0), -INT8_C(  68),      INT8_MAX, -INT8_C( 126) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  29), -INT8_C(   1),  INT8_C(   0), -INT8_C(  27),  INT8_C(   0),
        -INT8_C( 109),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  67),  INT8_C(   0),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_add_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 17817), -INT16_C(  2243), -INT16_C( 28883), -INT16_C(  7874),  INT16_C(   338), -INT16_C( 12748), -INT16_C(  9412),  INT16_C(   228) },
      UINT8_C( 66),
      { -INT16_C( 13625), -INT16_C(   511), -INT16_C(  9176), -INT16_C( 32360), -INT16_C( 18674), -INT16_C( 29571), -INT16_C( 32208),  INT16_C(  4749) },
      { -INT16_C( 26006), -INT16_C( 12496),  INT16_C( 20326), -INT16_C(   234), -INT16_C( 21928), -INT16_C(  3464), -INT16_C( 18163), -INT16_C(  1715) },
      {  INT16_C( 17817), -INT16_C( 13007), -INT16_C( 28883), -INT16_C(  7874),  INT16_C(   338), -INT16_C( 12748),  INT16_C( 15165),  INT16_C(   228) } },
    { { -INT16_C( 31056), -INT16_C( 22914),  INT16_C( 26105), -INT16_C( 10738),  INT16_C(   397),  INT16_C( 25565), -INT16_C( 22215), -INT16_C( 22166) },
      UINT8_C( 95),
      { -INT16_C( 29933), -INT16_C(  7224),  INT16_C( 20985),  INT16_C(  6509), -INT16_C( 25426), -INT16_C( 14506), -INT16_C( 26474), -INT16_C( 16323) },
      { -INT16_C( 17906),  INT16_C(  4756), -INT16_C( 20982),  INT16_C(  9519), -INT16_C( 15356), -INT16_C( 11051),  INT16_C( 26863), -INT16_C( 25274) },
      {  INT16_C( 17697), -INT16_C(  2468),  INT16_C(     3),  INT16_C( 16028),  INT16_C( 24754),  INT16_C( 25565),  INT16_C(   389), -INT16_C( 22166) } },
    { { -INT16_C(  4880),  INT16_C(  8735),  INT16_C(  8130),  INT16_C( 26938), -INT16_C(  8020), -INT16_C( 31347),  INT16_C(  8055),  INT16_C(  9966) },
      UINT8_C(190),
      {  INT16_C(  1808),  INT16_C( 20344),  INT16_C(  2923), -INT16_C( 23307), -INT16_C( 27990), -INT16_C(  8377), -INT16_C( 32088), -INT16_C( 20615) },
      {  INT16_C( 25028), -INT16_C( 30164),  INT16_C( 13304),  INT16_C( 19564), -INT16_C( 24947),  INT16_C(  1894), -INT16_C(  6448), -INT16_C( 24485) },
      { -INT16_C(  4880), -INT16_C(  9820),  INT16_C( 16227), -INT16_C(  3743),  INT16_C( 12599), -INT16_C(  6483),  INT16_C(  8055),  INT16_C( 20436) } },
    { {  INT16_C( 13221), -INT16_C( 19991),  INT16_C( 21448),  INT16_C(  9585),  INT16_C( 18335),  INT16_C( 18834),  INT16_C( 31996), -INT16_C(  1809) },
      UINT8_C(131),
      {  INT16_C(  1798),  INT16_C( 26660), -INT16_C( 21916), -INT16_C( 14369),  INT16_C( 18610),  INT16_C( 19226), -INT16_C( 32140),  INT16_C(  6089) },
      { -INT16_C( 10658),  INT16_C( 26610),  INT16_C(  5435),  INT16_C( 22284),  INT16_C(  1294),  INT16_C( 25864),  INT16_C( 31360),  INT16_C( 29206) },
      { -INT16_C(  8860), -INT16_C( 12266),  INT16_C( 21448),  INT16_C(  9585),  INT16_C( 18335),  INT16_C( 18834),  INT16_C( 31996), -INT16_C( 30241) } },
    { {  INT16_C(  3819),  INT16_C(  7886), -INT16_C(  2308), -INT16_C( 23812), -INT16_C(    53),  INT16_C(  7661), -INT16_C(  6086), -INT16_C( 20132) },
      UINT8_C(126),
      {  INT16_C(  1025), -INT16_C(  1747),  INT16_C( 13483),  INT16_C( 15025),  INT16_C( 17328), -INT16_C( 14874),  INT16_C(  6565),  INT16_C( 14071) },
      { -INT16_C( 12931), -INT16_C( 25527), -INT16_C( 11161),  INT16_C( 18125), -INT16_C(  1194), -INT16_C( 29538), -INT16_C(  3219), -INT16_C( 14390) },
      {  INT16_C(  3819), -INT16_C( 27274),  INT16_C(  2322), -INT16_C( 32386),  INT16_C( 16134),  INT16_C( 21124),  INT16_C(  3346), -INT16_C( 20132) } },
    { {  INT16_C( 22971), -INT16_C( 32214), -INT16_C( 27903),  INT16_C( 14508),  INT16_C( 16600), -INT16_C( 22707), -INT16_C(  5461), -INT16_C( 11019) },
      UINT8_C( 35),
      {  INT16_C( 16262), -INT16_C( 24435),  INT16_C( 14751),  INT16_C( 27015), -INT16_C( 24225), -INT16_C(   541), -INT16_C(  9613),  INT16_C(  4216) },
      { -INT16_C(  1057),  INT16_C( 24640),  INT16_C( 27675),  INT16_C( 25767),  INT16_C(  8263),  INT16_C( 28018), -INT16_C( 30242),  INT16_C(  6202) },
      {  INT16_C( 15205),  INT16_C(   205), -INT16_C( 27903),  INT16_C( 14508),  INT16_C( 16600),  INT16_C( 27477), -INT16_C(  5461), -INT16_C( 11019) } },
    { {  INT16_C(  9473), -INT16_C( 12490),  INT16_C( 26373), -INT16_C( 31879), -INT16_C( 12795),  INT16_C( 27285),  INT16_C( 20597), -INT16_C(  2226) },
      UINT8_C( 62),
      { -INT16_C(  1230), -INT16_C( 11593),  INT16_C( 18697), -INT16_C(  8764), -INT16_C(  7130),  INT16_C( 25580), -INT16_C(  4090), -INT16_C( 25505) },
      {  INT16_C( 19431), -INT16_C( 14954), -INT16_C( 27621),  INT16_C( 15919), -INT16_C( 16076), -INT16_C( 32362), -INT16_C( 25322),  INT16_C( 25848) },
      {  INT16_C(  9473), -INT16_C( 26547), -INT16_C(  8924),  INT16_C(  7155), -INT16_C( 23206), -INT16_C(  6782),  INT16_C( 20597), -INT16_C(  2226) } },
    { { -INT16_C( 16798), -INT16_C( 16061),  INT16_C( 28632),  INT16_C( 12716),  INT16_C( 10145),  INT16_C( 23704),  INT16_C( 13844), -INT16_C(  1453) },
      UINT8_C( 10),
      {  INT16_C(  4456),  INT16_C(  1455), -INT16_C( 11882), -INT16_C( 21010), -INT16_C( 14517),  INT16_C(  9453),  INT16_C( 19422),  INT16_C( 22787) },
      {  INT16_C(  9815), -INT16_C(  4177), -INT16_C( 17752),  INT16_C(  8643), -INT16_C( 14132), -INT16_C( 28981),  INT16_C(  3734), -INT16_C(  2203) },
      { -INT16_C( 16798), -INT16_C(  2722),  INT16_C( 28632), -INT16_C( 12367),  INT16_C( 10145),  INT16_C( 23704),  INT16_C( 13844), -INT16_C(  1453) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask_add_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(134),
      {  INT16_C( 12554), -INT16_C( 17057), -INT16_C( 28311), -INT16_C( 28428), -INT16_C( 15318), -INT16_C( 10100), -INT16_C( 18852), -INT16_C( 16229) },
      { -INT16_C( 31990),  INT16_C( 29908),  INT16_C( 15111), -INT16_C(  4862),  INT16_C( 23252), -INT16_C( 12060), -INT16_C( 25385), -INT16_C( 12982) },
      {  INT16_C(     0),  INT16_C( 12851), -INT16_C( 13200),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 29211) } },
    { UINT8_C(157),
      {  INT16_C(  1408),  INT16_C( 17385), -INT16_C( 25707), -INT16_C(  3037),  INT16_C(  2190), -INT16_C( 16188),  INT16_C(  9347), -INT16_C(  7492) },
      { -INT16_C( 31565),  INT16_C( 13950), -INT16_C( 23827),  INT16_C(  2179),  INT16_C(  5735),  INT16_C(  2100), -INT16_C( 26139), -INT16_C(  8740) },
      { -INT16_C( 30157),  INT16_C(     0),  INT16_C( 16002), -INT16_C(   858),  INT16_C(  7925),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16232) } },
    { UINT8_C( 24),
      { -INT16_C( 18498), -INT16_C( 16851), -INT16_C(  8942),  INT16_C( 29587), -INT16_C( 30777), -INT16_C( 18973), -INT16_C( 17141),  INT16_C( 22434) },
      { -INT16_C(  7638),  INT16_C(   677), -INT16_C( 15883),  INT16_C( 16066),  INT16_C( 29995), -INT16_C( 27669),  INT16_C(  7858), -INT16_C( 16674) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 19883), -INT16_C(   782),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(157),
      { -INT16_C( 30517), -INT16_C(  8546),  INT16_C( 22395),  INT16_C( 25788), -INT16_C(  9860),  INT16_C( 13172),  INT16_C( 13481),  INT16_C(  7362) },
      {  INT16_C( 20929), -INT16_C(    87), -INT16_C( 17569), -INT16_C( 31496),  INT16_C( 15928), -INT16_C(  7297),  INT16_C( 24667),  INT16_C( 21390) },
      { -INT16_C(  9588),  INT16_C(     0),  INT16_C(  4826), -INT16_C(  5708),  INT16_C(  6068),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28752) } },
    { UINT8_C(204),
      { -INT16_C(  7807), -INT16_C( 18593),  INT16_C(  5789),  INT16_C( 10188), -INT16_C(   320), -INT16_C( 16671), -INT16_C( 20439), -INT16_C( 18566) },
      { -INT16_C( 19073), -INT16_C( 12901),  INT16_C( 26791),  INT16_C( 16857), -INT16_C( 21045), -INT16_C(  9971),  INT16_C(  2843),  INT16_C( 25436) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 32580),  INT16_C( 27045),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17596),  INT16_C(  6870) } },
    { UINT8_C(237),
      { -INT16_C( 16461), -INT16_C(  6930),  INT16_C( 16169), -INT16_C( 32323),  INT16_C(  2552),  INT16_C(  1679), -INT16_C( 26974),  INT16_C( 14036) },
      {  INT16_C(  2376), -INT16_C( 18722),  INT16_C(  3134),  INT16_C( 10788),  INT16_C(  9045),  INT16_C( 14703),  INT16_C( 12911),  INT16_C( 27034) },
      { -INT16_C( 14085),  INT16_C(     0),  INT16_C( 19303), -INT16_C( 21535),  INT16_C(     0),  INT16_C( 16382), -INT16_C( 14063), -INT16_C( 24466) } },
    { UINT8_C( 42),
      {  INT16_C( 26325),  INT16_C(  6988),  INT16_C( 23545), -INT16_C( 22647),  INT16_C( 31625), -INT16_C(  3414),  INT16_C( 10045), -INT16_C( 17949) },
      {  INT16_C(  1997), -INT16_C( 13645), -INT16_C(  8378),  INT16_C( 19517),  INT16_C( 12495), -INT16_C( 25023),  INT16_C( 24234), -INT16_C( 25731) },
      {  INT16_C(     0), -INT16_C(  6657),  INT16_C(     0), -INT16_C(  3130),  INT16_C(     0), -INT16_C( 28437),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(211),
      {  INT16_C( 12889),  INT16_C( 28312),  INT16_C( 22010),  INT16_C(  4663), -INT16_C( 15800), -INT16_C( 32484), -INT16_C( 11389),  INT16_C( 13519) },
      {  INT16_C( 15116), -INT16_C( 28247),  INT16_C(   679),  INT16_C( 25752), -INT16_C( 15591),  INT16_C( 22603), -INT16_C( 32111), -INT16_C( 14859) },
      {  INT16_C( 28005),  INT16_C(    65),  INT16_C(     0),  INT16_C(     0), -INT16_C( 31391),  INT16_C(     0),  INT16_C( 22036), -INT16_C(  1340) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_add_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1958227227),  INT32_C(  1842333829), -INT32_C(  2080453323), -INT32_C(   249177196) },
      UINT8_C(155),
      {  INT32_C(   553106004), -INT32_C(  1372587746), -INT32_C(  1712075801),  INT32_C(   993452127) },
      {  INT32_C(   777515607), -INT32_C(   712684129),  INT32_C(   223497663), -INT32_C(   489447286) },
      {  INT32_C(  1330621611), -INT32_C(  2085271875), -INT32_C(  2080453323),  INT32_C(   504004841) } },
    { {  INT32_C(   697251714), -INT32_C(   951749739),  INT32_C(   836834350), -INT32_C(   346279314) },
      UINT8_C(111),
      { -INT32_C(   885142141), -INT32_C(   194598295), -INT32_C(  1261452693),  INT32_C(   375114831) },
      {  INT32_C(  1479180836), -INT32_C(  1604991616), -INT32_C(  1780092987),  INT32_C(   634429248) },
      {  INT32_C(   594038695), -INT32_C(  1799589911),  INT32_C(  1253421616),  INT32_C(  1009544079) } },
    { {  INT32_C(  1249061656),  INT32_C(   406248213),  INT32_C(  1546568796),  INT32_C(   345790387) },
      UINT8_C(173),
      {  INT32_C(  1116067984), -INT32_C(   306617666),  INT32_C(  1471337118),  INT32_C(  1742516687) },
      {  INT32_C(  1421198449),  INT32_C(  1861843318), -INT32_C(  2139880994),  INT32_C(   418138440) },
      { -INT32_C(  1757700863),  INT32_C(   406248213), -INT32_C(   668543876), -INT32_C(  2134312169) } },
    { { -INT32_C(   455875920), -INT32_C(  1805739296), -INT32_C(   834127167), -INT32_C(   193385963) },
      UINT8_C(243),
      {  INT32_C(   397937177),  INT32_C(   447724867), -INT32_C(  1604479719), -INT32_C(  1556316088) },
      {  INT32_C(   764118341),  INT32_C(    33168795), -INT32_C(   931609255),  INT32_C(  2093992876) },
      {  INT32_C(  1162055518),  INT32_C(   480893662), -INT32_C(   834127167), -INT32_C(   193385963) } },
    { {  INT32_C(   227843937), -INT32_C(  1816959923),  INT32_C(   110120824), -INT32_C(  1826017770) },
      UINT8_C(242),
      {  INT32_C(   598721326), -INT32_C(  1962044123), -INT32_C(  1919813583), -INT32_C(  1281349718) },
      { -INT32_C(  1464369420),  INT32_C(  1889351967), -INT32_C(   174840084), -INT32_C(  1849263339) },
      {  INT32_C(   227843937), -INT32_C(    72692156),  INT32_C(   110120824), -INT32_C(  1826017770) } },
    { {  INT32_C(   585486166), -INT32_C(  1881648464), -INT32_C(  1741597697),  INT32_C(  1501172127) },
      UINT8_C(177),
      { -INT32_C(  2072152845),  INT32_C(  1678312837),  INT32_C(   175231240),  INT32_C(   639313595) },
      {  INT32_C(  1844718395),  INT32_C(  1747844119), -INT32_C(  1642309052), -INT32_C(  1463847021) },
      { -INT32_C(   227434450), -INT32_C(  1881648464), -INT32_C(  1741597697),  INT32_C(  1501172127) } },
    { {  INT32_C(  1282734968), -INT32_C(  1805890056), -INT32_C(   170454139),  INT32_C(   939566096) },
      UINT8_C(  1),
      {  INT32_C(   373441333),  INT32_C(  1967739279),  INT32_C(   363886263), -INT32_C(  1478106109) },
      { -INT32_C(  1988739640),  INT32_C(   299055662),  INT32_C(   830616967),  INT32_C(   503576578) },
      { -INT32_C(  1615298307), -INT32_C(  1805890056), -INT32_C(   170454139),  INT32_C(   939566096) } },
    { {  INT32_C(  1100203671), -INT32_C(   234656697), -INT32_C(  2035991414),  INT32_C(  1938166869) },
      UINT8_C( 44),
      { -INT32_C(    77918946), -INT32_C(   927432354), -INT32_C(  2008458249),  INT32_C(  1379220591) },
      { -INT32_C(   261431271), -INT32_C(  1794574077),  INT32_C(  1874265007),  INT32_C(   695196668) },
      {  INT32_C(  1100203671), -INT32_C(   234656697), -INT32_C(   134193242),  INT32_C(  2074417259) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask_add_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 26),
      {  INT32_C(  1100397714),  INT32_C(  1720147146),  INT32_C(   782659498),  INT32_C(   164614002) },
      {  INT32_C(  1362429759), -INT32_C(   135924898),  INT32_C(  1277782591),  INT32_C(  1455600660) },
      {  INT32_C(           0),  INT32_C(  1584222248),  INT32_C(           0),  INT32_C(  1620214662) } },
    { UINT8_C(104),
      { -INT32_C(   511491329),  INT32_C(  2145361873), -INT32_C(   681927889), -INT32_C(  1760116045) },
      { -INT32_C(  1818488330), -INT32_C(  1227468567), -INT32_C(   914908373), -INT32_C(   761443622) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1773407629) } },
    { UINT8_C( 38),
      { -INT32_C(  1756543294), -INT32_C(  1924529315),  INT32_C(   753287628),  INT32_C(   821606796) },
      {  INT32_C(  1995981071),  INT32_C(  1941095443), -INT32_C(   997134313),  INT32_C(  1414962996) },
      {  INT32_C(           0),  INT32_C(    16566128), -INT32_C(   243846685),  INT32_C(           0) } },
    { UINT8_C( 11),
      {  INT32_C(  1936642854),  INT32_C(  1476527496), -INT32_C(  1916837668),  INT32_C(  1565927957) },
      {  INT32_C(   819891483),  INT32_C(    24098982),  INT32_C(  1427042923),  INT32_C(   967231402) },
      { -INT32_C(  1538432959),  INT32_C(  1500626478),  INT32_C(           0), -INT32_C(  1761807937) } },
    { UINT8_C(136),
      {  INT32_C(  2025931821), -INT32_C(  1602308853), -INT32_C(  1584066603),  INT32_C(  2144498786) },
      { -INT32_C(    32030623), -INT32_C(   522392968),  INT32_C(  2136840774),  INT32_C(   707776301) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1442692209) } },
    { UINT8_C( 16),
      {  INT32_C(   615979771),  INT32_C(    91372444), -INT32_C(  1715689431),  INT32_C(  1732560282) },
      {  INT32_C(  1582515072), -INT32_C(   566478811), -INT32_C(  1915644371), -INT32_C(   936530095) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(152),
      { -INT32_C(  1815019322),  INT32_C(  2115824139), -INT32_C(   541094950), -INT32_C(   308634405) },
      { -INT32_C(   923734690),  INT32_C(   926178071),  INT32_C(  1920079652), -INT32_C(  1332173880) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1640808285) } },
    { UINT8_C( 27),
      {  INT32_C(  1575440202),  INT32_C(  1941889206),  INT32_C(    41623433), -INT32_C(    28396641) },
      {  INT32_C(     7451246), -INT32_C(  1374405146),  INT32_C(  1597383244), -INT32_C(  1478059980) },
      {  INT32_C(  1582891448),  INT32_C(   567484060),  INT32_C(           0), -INT32_C(  1506456621) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_add_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8201918233897001447),  INT64_C(  363962166077692400) },
      UINT8_C(116),
      { -INT64_C( 2929372668825588728), -INT64_C( 3656510824753645306) },
      {  INT64_C( 2121463196383157106), -INT64_C( 2712448646012699723) },
      {  INT64_C( 8201918233897001447),  INT64_C(  363962166077692400) } },
    { { -INT64_C( 7660056023431247569), -INT64_C( 8800573589908441802) },
      UINT8_C( 26),
      { -INT64_C( 5155283151088348406), -INT64_C( 6777794566593036429) },
      {  INT64_C( 8217194832092526134), -INT64_C( 6988787196078811595) },
      { -INT64_C( 7660056023431247569),  INT64_C( 4680162311037703592) } },
    { { -INT64_C( 5177610656632927949), -INT64_C( 7835688890176823491) },
      UINT8_C( 38),
      {  INT64_C( 8694329990162064366), -INT64_C( 7553465337537219517) },
      {  INT64_C( 5861342603890327684),  INT64_C( 8969888432361565647) },
      { -INT64_C( 5177610656632927949),  INT64_C( 1416423094824346130) } },
    { {  INT64_C( 1563207507706856527), -INT64_C(  371485882345723171) },
      UINT8_C(246),
      { -INT64_C( 8155582183645986764), -INT64_C( 8042754456252808652) },
      { -INT64_C(  996858152082936078),  INT64_C(  999238294551887019) },
      {  INT64_C( 1563207507706856527), -INT64_C( 7043516161700921633) } },
    { {  INT64_C( 2269651972621910057),  INT64_C( 8122205111827084555) },
      UINT8_C(109),
      {  INT64_C( 5898016879431101179),  INT64_C( 8196109586946188276) },
      { -INT64_C( 3927996688380496977), -INT64_C( 8700540345223695011) },
      {  INT64_C( 1970020191050604202),  INT64_C( 8122205111827084555) } },
    { {  INT64_C( 8953512102049709771),  INT64_C( 4073568780934150804) },
      UINT8_C( 55),
      { -INT64_C( 8698567697690688449),  INT64_C( 2011128588034496860) },
      {  INT64_C( 4050759086289972052), -INT64_C( 4209687100771601707) },
      { -INT64_C( 4647808611400716397), -INT64_C( 2198558512737104847) } },
    { { -INT64_C( 2003310644913083277),  INT64_C( 3614518035412058723) },
      UINT8_C(247),
      {  INT64_C( 1202266463040515144),  INT64_C( 2203879785493297747) },
      { -INT64_C( 6903979043742968285),  INT64_C(  286701945599558971) },
      { -INT64_C( 5701712580702453141),  INT64_C( 2490581731092856718) } },
    { {  INT64_C( 9179970759417586743), -INT64_C(  419587667919506800) },
      UINT8_C( 88),
      { -INT64_C( 5871315755711329534), -INT64_C( 2058360122490679194) },
      {  INT64_C( 1804735659384354964),  INT64_C( 3266572330366650128) },
      {  INT64_C( 9179970759417586743), -INT64_C(  419587667919506800) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_mask_add_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(150),
      { -INT64_C(  993872781162934343),  INT64_C( 9134756112190127784) },
      { -INT64_C( 2891573308549781280), -INT64_C( 9143568260559188007) },
      {  INT64_C(                   0), -INT64_C(    8812148369060223) } },
    { UINT8_C(196),
      {  INT64_C( 6550556420904536135),  INT64_C( 8490360445651406694) },
      { -INT64_C( 1739704569367854626),  INT64_C( 4245131661435093091) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 52),
      { -INT64_C( 2760535867334763843),  INT64_C( 7115030050339329677) },
      {  INT64_C( 7188684116250616331), -INT64_C( 2471133335336396754) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(  5),
      {  INT64_C( 3814106451400715087),  INT64_C( 6178810664702908734) },
      {  INT64_C( 1820139726703884269), -INT64_C( 2876452185216044984) },
      {  INT64_C( 5634246178104599356),  INT64_C(                   0) } },
    { UINT8_C( 77),
      { -INT64_C( 7349641843913850521),  INT64_C( 3200744105211371253) },
      {  INT64_C(  228621185812703474),  INT64_C( 6391631982896984822) },
      { -INT64_C( 7121020658101147047),  INT64_C(                   0) } },
    { UINT8_C(254),
      {  INT64_C( 5885620942751936373),  INT64_C( 3334511588433406542) },
      { -INT64_C(  254487071634799123),  INT64_C( 3127732574282601076) },
      {  INT64_C(                   0),  INT64_C( 6462244162716007618) } },
    { UINT8_C(174),
      { -INT64_C( 2725183470148505474),  INT64_C( 8524564968923083055) },
      {  INT64_C( 3417677596325229905), -INT64_C( 1448789787674024211) },
      {  INT64_C(                   0),  INT64_C( 7075775181249058844) } },
    { UINT8_C( 60),
      {  INT64_C( 5475088381666832271),  INT64_C( 2253690732183149705) },
      {  INT64_C( 9160715340915633356), -INT64_C( 3092667301170657521) },
      {  INT64_C(                   0),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_add_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtsepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsepi32_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtsepi32_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsepi32_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtsepi32_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtsepi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtsepi64_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_abs_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_abs_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_abs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_abs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_abs_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_abs_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_abs_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_abs_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_abs_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_abs_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_abs_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_abs_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
