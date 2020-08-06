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
test_simde_mm256_mask_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 18088),  INT16_C(  1606), -INT16_C(  7503),  INT16_C(  5992),  INT16_C( 28165),  INT16_C( 22274), -INT16_C( 26583), -INT16_C( 13076),
        -INT16_C( 12908),  INT16_C( 10372),  INT16_C( 29897),  INT16_C(   832),  INT16_C( 19766),  INT16_C( 21637), -INT16_C( 21677),  INT16_C( 16763) },
      UINT16_C(60084),
      {  INT16_C( 31188),  INT16_C( 10550), -INT16_C( 29740),  INT16_C( 24731), -INT16_C( 25844),  INT16_C( 20568), -INT16_C( 21197),  INT16_C( 13543),
        -INT16_C( 13074), -INT16_C(  5446),  INT16_C(  8264), -INT16_C( 22453), -INT16_C( 30162), -INT16_C(  8771),  INT16_C( 29554), -INT16_C(  6204) },
      {  INT16_C( 13652), -INT16_C(  1326), -INT16_C(  8634), -INT16_C( 16805), -INT16_C(  7376), -INT16_C(  1060), -INT16_C( 17004),  INT16_C(  3029),
        -INT16_C( 23256), -INT16_C( 24573), -INT16_C(  5392),  INT16_C(  9842),  INT16_C( 11581), -INT16_C( 25918), -INT16_C(  1929),  INT16_C(  6096) },
      { -INT16_C( 18088),  INT16_C(  1606),  INT16_C( 27162),  INT16_C(  5992),  INT16_C( 32316),  INT16_C( 19508), -INT16_C( 26583),  INT16_C( 16572),
        -INT16_C( 12908), -INT16_C( 30019),  INT16_C( 29897), -INT16_C( 12611),  INT16_C( 19766),  INT16_C( 30847),  INT16_C( 27625), -INT16_C(   108) } },
    { { -INT16_C( 28260),  INT16_C(  3355),  INT16_C( 30149),  INT16_C( 18841),  INT16_C(   897), -INT16_C( 18335), -INT16_C( 27856),  INT16_C( 31843),
         INT16_C( 24626), -INT16_C( 30048), -INT16_C(  8679),  INT16_C(  1167),  INT16_C(  9529),  INT16_C( 15283), -INT16_C( 18329),  INT16_C(  1611) },
      UINT16_C(36795),
      { -INT16_C( 20367),  INT16_C( 17977), -INT16_C( 10340),  INT16_C( 23796),  INT16_C(  4308), -INT16_C(  8548), -INT16_C( 31482), -INT16_C( 21319),
         INT16_C(    17), -INT16_C( 10987),  INT16_C( 12850),  INT16_C(  9166),  INT16_C(  5118), -INT16_C( 13916),  INT16_C( 27754), -INT16_C( 17049) },
      { -INT16_C( 29649),  INT16_C(  2250),  INT16_C( 31457),  INT16_C( 19428), -INT16_C( 17826),  INT16_C(  8517),  INT16_C(  3008), -INT16_C( 15739),
        -INT16_C(  3791), -INT16_C( 20340),  INT16_C( 28400),  INT16_C( 31847), -INT16_C( 20111),  INT16_C(  8560), -INT16_C(  3090), -INT16_C( 17728) },
      {  INT16_C( 15520),  INT16_C( 20227),  INT16_C( 30149), -INT16_C( 22312), -INT16_C( 13518), -INT16_C(    31), -INT16_C( 27856),  INT16_C( 28478),
        -INT16_C(  3774), -INT16_C( 31327), -INT16_C( 24286), -INT16_C( 24523),  INT16_C(  9529),  INT16_C( 15283), -INT16_C( 18329),  INT16_C( 30759) } },
    { {  INT16_C(  5027),  INT16_C( 31603), -INT16_C(  3038),  INT16_C( 25247),  INT16_C( 12894), -INT16_C(  2609),  INT16_C( 30080),  INT16_C( 22396),
        -INT16_C(  4776), -INT16_C(  7593), -INT16_C(  5922), -INT16_C( 20302),  INT16_C( 26389), -INT16_C(  2181),  INT16_C( 14645),  INT16_C(  6951) },
      UINT16_C(62936),
      { -INT16_C( 18607),  INT16_C( 18295), -INT16_C(  2304),  INT16_C( 28875), -INT16_C(  8411),  INT16_C(  2635),  INT16_C( 16083),  INT16_C(  5198),
        -INT16_C( 31435), -INT16_C(  4074),  INT16_C( 13887), -INT16_C(  4755),  INT16_C( 30885), -INT16_C(  1538), -INT16_C( 32035), -INT16_C(  4113) },
      {  INT16_C(  2642),  INT16_C(  4797), -INT16_C(  3564), -INT16_C( 27490),  INT16_C( 16589),  INT16_C( 10413),  INT16_C( 30700), -INT16_C(  8724),
         INT16_C( 25964),  INT16_C(  5287), -INT16_C( 19421),  INT16_C( 28120), -INT16_C( 30880), -INT16_C( 19119), -INT16_C( 19912), -INT16_C( 27324) },
      {  INT16_C(  5027),  INT16_C( 31603), -INT16_C(  3038),  INT16_C(  1385),  INT16_C(  8178), -INT16_C(  2609), -INT16_C( 18753), -INT16_C(  3526),
        -INT16_C(  5471), -INT16_C(  7593), -INT16_C(  5534), -INT16_C( 20302),  INT16_C(     5), -INT16_C( 20657),  INT16_C( 13589), -INT16_C( 31437) } },
    { {  INT16_C( 25041),  INT16_C( 25663),  INT16_C( 28102),  INT16_C( 28245),  INT16_C(  5599),  INT16_C( 24300), -INT16_C( 10886), -INT16_C(  9183),
         INT16_C(  3807),  INT16_C( 25125), -INT16_C( 25229), -INT16_C(  4659), -INT16_C( 15898),  INT16_C( 11743), -INT16_C( 28195),  INT16_C( 25686) },
      UINT16_C(55587),
      {  INT16_C(  2381), -INT16_C( 16078), -INT16_C( 27768),  INT16_C( 27601),  INT16_C( 16912),  INT16_C(  8673), -INT16_C( 29342), -INT16_C(  7031),
         INT16_C( 30710), -INT16_C(  7797), -INT16_C( 30252),  INT16_C( 23527), -INT16_C(  2137),  INT16_C( 31719),  INT16_C( 32572),  INT16_C( 32012) },
      { -INT16_C( 11761),  INT16_C( 10830), -INT16_C( 22217), -INT16_C( 26449), -INT16_C( 13353), -INT16_C(  6701), -INT16_C( 21906),  INT16_C( 26387),
         INT16_C( 28827), -INT16_C( 13374), -INT16_C(  1039), -INT16_C( 19312), -INT16_C(  2641),  INT16_C( 17473), -INT16_C( 21172), -INT16_C( 20086) },
      { -INT16_C(  9380), -INT16_C(  5248),  INT16_C( 28102),  INT16_C( 28245),  INT16_C(  5599),  INT16_C(  1972), -INT16_C( 10886), -INT16_C(  9183),
        -INT16_C(  5999),  INT16_C( 25125), -INT16_C( 25229),  INT16_C(  4215), -INT16_C(  4778),  INT16_C( 11743),  INT16_C( 11400),  INT16_C( 11926) } },
    { {  INT16_C( 12057),  INT16_C( 29150),  INT16_C( 23614),  INT16_C( 25130),  INT16_C( 10655), -INT16_C( 27568),  INT16_C( 28503), -INT16_C( 25443),
        -INT16_C( 10717), -INT16_C( 20322), -INT16_C( 29779), -INT16_C( 24431),  INT16_C( 27510), -INT16_C(  9356),  INT16_C(  4476),  INT16_C( 16174) },
      UINT16_C(36512),
      {  INT16_C( 19088),  INT16_C( 10128),  INT16_C( 13140),  INT16_C( 29098), -INT16_C(  3415),  INT16_C(  2524), -INT16_C( 20169), -INT16_C( 11551),
        -INT16_C( 26829),  INT16_C(  3366),  INT16_C( 12131),  INT16_C(  2463),  INT16_C( 30355),  INT16_C( 12022),  INT16_C( 19040),  INT16_C( 20815) },
      { -INT16_C( 24937),  INT16_C( 16359), -INT16_C(   602),  INT16_C( 32707), -INT16_C(  4799),  INT16_C( 16001),  INT16_C( 10569),  INT16_C(  2669),
         INT16_C(  8145), -INT16_C(   957),  INT16_C( 11518), -INT16_C( 18084), -INT16_C( 29708),  INT16_C(  9779),  INT16_C(   904), -INT16_C( 28159) },
      {  INT16_C( 12057),  INT16_C( 29150),  INT16_C( 23614),  INT16_C( 25130),  INT16_C( 10655),  INT16_C( 18525),  INT16_C( 28503), -INT16_C(  8882),
        -INT16_C( 10717),  INT16_C(  2409),  INT16_C( 23649), -INT16_C( 15621),  INT16_C( 27510), -INT16_C(  9356),  INT16_C(  4476), -INT16_C(  7344) } },
    { {  INT16_C( 13479),  INT16_C( 32082), -INT16_C(  1052), -INT16_C( 28178), -INT16_C(  5151),  INT16_C( 15355), -INT16_C( 21898), -INT16_C(  6248),
         INT16_C( 26798),  INT16_C( 24344), -INT16_C( 25169),  INT16_C( 15648), -INT16_C( 31017),  INT16_C(  1114), -INT16_C( 19793),  INT16_C( 27930) },
      UINT16_C( 8052),
      { -INT16_C( 26007),  INT16_C( 21812), -INT16_C( 28453), -INT16_C( 22252), -INT16_C(  2350),  INT16_C( 20554), -INT16_C(   112),  INT16_C( 28501),
         INT16_C( 20387),  INT16_C( 15898), -INT16_C(  4455),  INT16_C(  8743), -INT16_C(  3007),  INT16_C(  1364),  INT16_C( 26716), -INT16_C( 32024) },
      { -INT16_C( 26027), -INT16_C( 22945), -INT16_C( 11918), -INT16_C( 14268), -INT16_C( 11610), -INT16_C( 22539),  INT16_C(  6421), -INT16_C( 16498),
         INT16_C( 26152), -INT16_C( 22496), -INT16_C(  1902), -INT16_C( 10031),  INT16_C(  9340), -INT16_C( 16924), -INT16_C( 19351), -INT16_C( 25237) },
      {  INT16_C( 13479),  INT16_C( 32082),  INT16_C( 25165), -INT16_C( 28178), -INT16_C( 13960), -INT16_C(  1985),  INT16_C(  6309), -INT16_C(  6248),
        -INT16_C( 18997), -INT16_C(  6598), -INT16_C(  6357), -INT16_C(  1288),  INT16_C(  6333),  INT16_C(  1114), -INT16_C( 19793),  INT16_C( 27930) } },
    { { -INT16_C(  9402), -INT16_C(  4652),  INT16_C( 27455), -INT16_C( 17628),  INT16_C( 12568), -INT16_C(  6414), -INT16_C( 29207), -INT16_C(  1798),
        -INT16_C(  7113), -INT16_C( 19430),  INT16_C( 19790),  INT16_C( 17330), -INT16_C( 30097),  INT16_C( 28960),  INT16_C( 28059), -INT16_C( 12652) },
      UINT16_C(55494),
      {  INT16_C(  4668),  INT16_C( 21727),  INT16_C( 23842),  INT16_C(   859),  INT16_C( 24202), -INT16_C(  4733), -INT16_C( 18553), -INT16_C( 32032),
        -INT16_C( 22813),  INT16_C(   981), -INT16_C(  1521), -INT16_C( 13085), -INT16_C( 20947), -INT16_C(  1346), -INT16_C(  1102), -INT16_C( 30046) },
      {  INT16_C( 29305), -INT16_C( 30721),  INT16_C( 31389), -INT16_C(  1704),  INT16_C(  2370), -INT16_C( 31381),  INT16_C( 22976),  INT16_C(  6971),
         INT16_C(  2368),  INT16_C( 11549), -INT16_C(  7631), -INT16_C(  5582), -INT16_C( 17938), -INT16_C(  4477),  INT16_C( 28539), -INT16_C(  8234) },
      { -INT16_C(  9402), -INT16_C(  8994), -INT16_C( 10305), -INT16_C( 17628),  INT16_C( 12568), -INT16_C(  6414),  INT16_C(  4423), -INT16_C( 25061),
        -INT16_C(  7113), -INT16_C( 19430),  INT16_C( 19790), -INT16_C( 18667),  INT16_C( 26651),  INT16_C( 28960),  INT16_C( 27437),  INT16_C( 27256) } },
    { {  INT16_C( 17152), -INT16_C( 16650), -INT16_C( 14707),  INT16_C( 11632),  INT16_C( 19908), -INT16_C( 20810),  INT16_C(   377),  INT16_C( 15379),
        -INT16_C( 10283), -INT16_C( 26722), -INT16_C(   177), -INT16_C( 17760),  INT16_C(  8591),  INT16_C(  3646), -INT16_C( 16462),  INT16_C( 17616) },
      UINT16_C( 3229),
      {  INT16_C( 32634),  INT16_C( 32728),  INT16_C( 30084), -INT16_C( 23413), -INT16_C( 22910),  INT16_C( 20672),  INT16_C( 22735), -INT16_C( 29137),
        -INT16_C(  1705),  INT16_C(  5378),  INT16_C( 17391),  INT16_C( 15446), -INT16_C(  2220), -INT16_C(  3224), -INT16_C( 13014), -INT16_C( 19705) },
      {  INT16_C( 14637),  INT16_C( 15248), -INT16_C(  4954), -INT16_C( 14311), -INT16_C(   296), -INT16_C( 30474), -INT16_C(  5162), -INT16_C( 32073),
         INT16_C( 26895),  INT16_C( 18041), -INT16_C( 18825),  INT16_C(  9328),  INT16_C( 19262),  INT16_C(  3861), -INT16_C( 29853),  INT16_C( 17210) },
      { -INT16_C( 18265), -INT16_C( 16650),  INT16_C( 25130),  INT16_C( 27812), -INT16_C( 23206), -INT16_C( 20810),  INT16_C(   377),  INT16_C(  4326),
        -INT16_C( 10283), -INT16_C( 26722), -INT16_C(  1434),  INT16_C( 24774),  INT16_C(  8591),  INT16_C(  3646), -INT16_C( 16462),  INT16_C( 17616) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_add_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C( 4262),
      {  INT16_C( 17131),  INT16_C( 28575),  INT16_C( 26454),  INT16_C( 26097),  INT16_C( 13425),  INT16_C(  2916),  INT16_C( 18413), -INT16_C( 10307),
        -INT16_C( 22620),  INT16_C( 19835),  INT16_C( 24739),  INT16_C( 18854), -INT16_C(  6815), -INT16_C(  4094),  INT16_C( 31637),  INT16_C( 24951) },
      { -INT16_C( 29452),  INT16_C( 29154), -INT16_C( 24158),  INT16_C( 20005), -INT16_C( 21148),  INT16_C( 28846),  INT16_C( 22284), -INT16_C( 15662),
        -INT16_C(  9581), -INT16_C( 17953), -INT16_C( 18145), -INT16_C( 27296), -INT16_C( 29945), -INT16_C( 14925), -INT16_C( 22585),  INT16_C( 11545) },
      {  INT16_C(     0), -INT16_C(  7807),  INT16_C(  2296),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31762),  INT16_C(     0), -INT16_C( 25969),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28776),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(12070),
      { -INT16_C( 11840), -INT16_C( 15372),  INT16_C( 32629),  INT16_C( 21795), -INT16_C( 20660), -INT16_C( 29830), -INT16_C( 24024), -INT16_C( 29778),
        -INT16_C( 10477), -INT16_C( 11462),  INT16_C(  1337),  INT16_C(  5552),  INT16_C(  5961),  INT16_C( 23833), -INT16_C( 10057), -INT16_C( 19595) },
      { -INT16_C( 22405), -INT16_C( 25821), -INT16_C( 24191), -INT16_C(  3861), -INT16_C( 24777),  INT16_C( 24020),  INT16_C( 13500), -INT16_C( 20346),
        -INT16_C(   128),  INT16_C(  5177),  INT16_C( 12366), -INT16_C(  8346), -INT16_C(  7771), -INT16_C(  8032), -INT16_C( 11287), -INT16_C( 24811) },
      {  INT16_C(     0),  INT16_C( 24343),  INT16_C(  8438),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5810),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 10605), -INT16_C(  6285),  INT16_C( 13703), -INT16_C(  2794),  INT16_C(     0),  INT16_C( 15801),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(58512),
      { -INT16_C( 21753), -INT16_C( 12602), -INT16_C(  7088), -INT16_C( 15287),  INT16_C(  2851), -INT16_C(  3784), -INT16_C( 19644), -INT16_C(  3081),
         INT16_C( 27159),  INT16_C( 23080), -INT16_C( 12718), -INT16_C( 24689), -INT16_C( 17761),  INT16_C(  9682), -INT16_C( 30808), -INT16_C( 21236) },
      { -INT16_C( 30812),  INT16_C(  6629),  INT16_C( 21297), -INT16_C( 17253),  INT16_C( 32442),  INT16_C(  2260), -INT16_C(  2679), -INT16_C(  7556),
        -INT16_C( 10834), -INT16_C( 26189),  INT16_C(  2827), -INT16_C( 12197), -INT16_C( 13163),  INT16_C( 26769),  INT16_C( 21450),  INT16_C(  4191) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30243),  INT16_C(     0),  INT16_C(     0), -INT16_C( 10637),
         INT16_C(     0),  INT16_C(     0), -INT16_C(  9891),  INT16_C(     0),  INT16_C(     0), -INT16_C( 29085), -INT16_C(  9358), -INT16_C( 17045) } },
    { UINT16_C(26409),
      {  INT16_C( 23989), -INT16_C(  3893), -INT16_C( 10213), -INT16_C( 24561),  INT16_C( 24975), -INT16_C( 14143), -INT16_C( 26678), -INT16_C( 32272),
        -INT16_C( 25660),  INT16_C( 31804), -INT16_C( 10324),  INT16_C( 19769), -INT16_C( 22018), -INT16_C( 31803), -INT16_C( 22436),  INT16_C( 31880) },
      { -INT16_C( 13937),  INT16_C( 31205), -INT16_C( 12695),  INT16_C(  9893),  INT16_C( 19693), -INT16_C( 32334), -INT16_C( 25972),  INT16_C( 30977),
         INT16_C( 26854), -INT16_C( 10518), -INT16_C( 16582), -INT16_C( 26001), -INT16_C( 23041),  INT16_C(  5435),  INT16_C( 20892), -INT16_C(  8904) },
      {  INT16_C( 10052),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14668),  INT16_C(     0),  INT16_C( 19059),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  1194),  INT16_C( 21286), -INT16_C( 26906),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26368), -INT16_C(  1544),  INT16_C(     0) } },
    { UINT16_C(33734),
      { -INT16_C( 22559), -INT16_C(  8699), -INT16_C(  3315),  INT16_C( 30631),  INT16_C( 26186),  INT16_C(   646),  INT16_C( 32221), -INT16_C( 21902),
         INT16_C(  8809), -INT16_C(  9404), -INT16_C( 30818),  INT16_C(  9706), -INT16_C( 24086),  INT16_C( 10730), -INT16_C( 14587), -INT16_C( 12657) },
      { -INT16_C( 32121), -INT16_C( 14411), -INT16_C( 12619),  INT16_C( 32766), -INT16_C(  5886), -INT16_C( 28837), -INT16_C( 21424),  INT16_C(  1152),
         INT16_C( 18809), -INT16_C(  4130),  INT16_C(  7614), -INT16_C( 25916), -INT16_C( 21360),  INT16_C( 31629), -INT16_C( 21160), -INT16_C( 31719) },
      {  INT16_C(     0), -INT16_C( 23110), -INT16_C( 15934),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10797), -INT16_C( 20750),
         INT16_C( 27618), -INT16_C( 13534),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21160) } },
    { UINT16_C(12974),
      { -INT16_C(  9110), -INT16_C( 27434), -INT16_C(  6575), -INT16_C( 17103),  INT16_C( 10872), -INT16_C( 28881), -INT16_C(  1144),  INT16_C( 11533),
        -INT16_C( 28247),  INT16_C( 19770),  INT16_C( 10309), -INT16_C( 18656), -INT16_C(  7754),  INT16_C(  3438),  INT16_C(   758), -INT16_C( 19035) },
      { -INT16_C( 10315), -INT16_C(   614),  INT16_C(  9805),  INT16_C( 29426), -INT16_C( 17671),  INT16_C( 32637),  INT16_C( 32714),  INT16_C( 16551),
        -INT16_C( 22924), -INT16_C( 21545), -INT16_C(  9595), -INT16_C( 15050),  INT16_C(  9710),  INT16_C( 18424),  INT16_C(   172), -INT16_C(  1119) },
      {  INT16_C(     0), -INT16_C( 28048),  INT16_C(  3230),  INT16_C( 12323),  INT16_C(     0),  INT16_C(  3756),  INT16_C(     0),  INT16_C( 28084),
         INT16_C(     0), -INT16_C(  1775),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1956),  INT16_C( 21862),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(10927),
      {  INT16_C(  8380),  INT16_C( 25660),  INT16_C(  3043),  INT16_C( 26369), -INT16_C(  8173),  INT16_C( 10605),  INT16_C( 14118), -INT16_C(  4505),
        -INT16_C( 11066),  INT16_C( 28798), -INT16_C( 24766), -INT16_C( 11889), -INT16_C( 14630),  INT16_C( 31282), -INT16_C(  8140), -INT16_C(  9178) },
      {  INT16_C( 15994), -INT16_C( 30317), -INT16_C( 15077),  INT16_C( 17333), -INT16_C(  7916), -INT16_C( 24502),  INT16_C(  5769), -INT16_C( 29765),
        -INT16_C( 24127), -INT16_C( 29183), -INT16_C( 28892),  INT16_C( 13466),  INT16_C( 13695), -INT16_C(  4328),  INT16_C( 11614), -INT16_C( 16283) },
      {  INT16_C( 24374), -INT16_C(  4657), -INT16_C( 12034), -INT16_C( 21834),  INT16_C(     0), -INT16_C( 13897),  INT16_C(     0),  INT16_C( 31266),
         INT16_C(     0), -INT16_C(   385),  INT16_C(     0),  INT16_C(  1577),  INT16_C(     0),  INT16_C( 26954),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(24898),
      {  INT16_C( 31303), -INT16_C( 28888),  INT16_C( 32475), -INT16_C(  9009), -INT16_C( 21039),  INT16_C(  2463), -INT16_C(   235), -INT16_C( 27830),
         INT16_C( 12119), -INT16_C( 21538), -INT16_C( 26278), -INT16_C( 21134), -INT16_C( 12642), -INT16_C(  7297), -INT16_C( 26495),  INT16_C( 29429) },
      {  INT16_C( 31766),  INT16_C( 20949),  INT16_C(  1225),  INT16_C(  8709),  INT16_C( 22985), -INT16_C(  8523),  INT16_C( 31728), -INT16_C( 31368),
        -INT16_C( 17643), -INT16_C(  2286), -INT16_C( 26761),  INT16_C(  1099),  INT16_C( 26190), -INT16_C( 28221),  INT16_C( 25127), -INT16_C(  9460) },
      {  INT16_C(     0), -INT16_C(  7939),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31493),  INT16_C(     0),
        -INT16_C(  5524),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30018), -INT16_C(  1368),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_add_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(   426361587), -INT32_C(   443903963),  INT32_C(  1108332220),  INT32_C(  1919687830),  INT32_C(  1848164895), -INT32_C(  1877796598),  INT32_C(   483830142), -INT32_C(  2033377471) },
      UINT8_C(237),
      {  INT32_C(  1091358368),  INT32_C(   454097987),  INT32_C(   794389166),  INT32_C(   249974803),  INT32_C(   152267150),  INT32_C(   907080727), -INT32_C(  1733770061),  INT32_C(   220923521) },
      {  INT32_C(  1746020713),  INT32_C(  1017500003), -INT32_C(   803273524),  INT32_C(  1210396863),  INT32_C(   579828512), -INT32_C(   646644006),  INT32_C(  1430804319),  INT32_C(   926985775) },
      { -INT32_C(  1457588215), -INT32_C(   443903963), -INT32_C(     8884358),  INT32_C(  1460371666),  INT32_C(  1848164895),  INT32_C(   260436721), -INT32_C(   302965742),  INT32_C(  1147909296) } },
    { {  INT32_C(  1684912389),  INT32_C(  1461764767),  INT32_C(   531585245), -INT32_C(  1449055219),  INT32_C(  1704880266),  INT32_C(    70446890),  INT32_C(  2071901944), -INT32_C(   833618578) },
      UINT8_C(215),
      { -INT32_C(  1260280170),  INT32_C(    60784922),  INT32_C(  1789074221),  INT32_C(   506242865), -INT32_C(   265290717),  INT32_C(   773465711), -INT32_C(   249802610),  INT32_C(  1884100310) },
      { -INT32_C(  1123572585),  INT32_C(   950443465),  INT32_C(  1139858930), -INT32_C(  1387438223), -INT32_C(   995912866), -INT32_C(   783462299),  INT32_C(   568247403), -INT32_C(   175356258) },
      {  INT32_C(  1911114541),  INT32_C(  1011228387), -INT32_C(  1366034145), -INT32_C(  1449055219), -INT32_C(  1261203583),  INT32_C(    70446890),  INT32_C(   318444793),  INT32_C(  1708744052) } },
    { {  INT32_C(   683801390), -INT32_C(  1524037838),  INT32_C(   971777976), -INT32_C(   179262957), -INT32_C(   662180444),  INT32_C(  1746109353), -INT32_C(   120687010), -INT32_C(  1478304295) },
      UINT8_C(142),
      { -INT32_C(  1699645306),  INT32_C(  1703095819), -INT32_C(  1247556922), -INT32_C(   676606248), -INT32_C(  2057411672), -INT32_C(  2133453849),  INT32_C(  1277225381),  INT32_C(   895840639) },
      { -INT32_C(   241606211), -INT32_C(   714501803), -INT32_C(   395132250), -INT32_C(  1428661824),  INT32_C(  1298870179),  INT32_C(  1006598770), -INT32_C(  1667424466),  INT32_C(  1226468081) },
      {  INT32_C(   683801390),  INT32_C(   988594016), -INT32_C(  1642689172), -INT32_C(  2105268072), -INT32_C(   662180444),  INT32_C(  1746109353), -INT32_C(   120687010),  INT32_C(  2122308720) } },
    { { -INT32_C(  1854580385),  INT32_C(  1115024973), -INT32_C(   902732038),  INT32_C(  1105570825), -INT32_C(  2019220757),  INT32_C(  1567591273), -INT32_C(  1045989337),  INT32_C(   483693948) },
      UINT8_C( 16),
      { -INT32_C(  1622664288), -INT32_C(  1596764141),  INT32_C(  1531617719),  INT32_C(  2136124051), -INT32_C(   833907649),  INT32_C(   442458548), -INT32_C(  1966743074),  INT32_C(  1510510672) },
      {  INT32_C(  1995792121),  INT32_C(  1901624212), -INT32_C(   724913828),  INT32_C(   574753287), -INT32_C(   939006740),  INT32_C(  1662860686), -INT32_C(   798097367), -INT32_C(   819579665) },
      { -INT32_C(  1854580385),  INT32_C(  1115024973), -INT32_C(   902732038),  INT32_C(  1105570825), -INT32_C(  1772914389),  INT32_C(  1567591273), -INT32_C(  1045989337),  INT32_C(   483693948) } },
    { { -INT32_C(  2128119628),  INT32_C(   286644021), -INT32_C(   144034294), -INT32_C(   755119821),  INT32_C(   737304527), -INT32_C(   795896062), -INT32_C(  1306877446),  INT32_C(  2017207584) },
      UINT8_C( 39),
      { -INT32_C(   889153325),  INT32_C(  1946641334), -INT32_C(   394827187), -INT32_C(  1838628604), -INT32_C(  1114607536), -INT32_C(   988331075),  INT32_C(   505604917), -INT32_C(   158258489) },
      { -INT32_C(    19176166), -INT32_C(   739831540),  INT32_C(   812816619),  INT32_C(  1345615940),  INT32_C(   485266830), -INT32_C(  1880526201), -INT32_C(   347473235), -INT32_C(   631923023) },
      { -INT32_C(   908329491),  INT32_C(  1206809794),  INT32_C(   417989432), -INT32_C(   755119821),  INT32_C(   737304527),  INT32_C(  1426110020), -INT32_C(  1306877446),  INT32_C(  2017207584) } },
    { { -INT32_C(    35579584), -INT32_C(  1740792689),  INT32_C(  1827803830), -INT32_C(  1820729369), -INT32_C(  2037363614),  INT32_C(  1301089229),  INT32_C(  2117227785),  INT32_C(  1313930535) },
      UINT8_C( 29),
      {  INT32_C(   773440826), -INT32_C(    38988069), -INT32_C(   324201942),  INT32_C(   299194520), -INT32_C(   582542291),  INT32_C(   984927229),  INT32_C(   579334463),  INT32_C(   166931855) },
      { -INT32_C(  1529113807),  INT32_C(   521813891), -INT32_C(  1447212676),  INT32_C(  1970271572), -INT32_C(  1806503392),  INT32_C(  1956442032), -INT32_C(   878298291),  INT32_C(   934511007) },
      { -INT32_C(   755672981), -INT32_C(  1740792689), -INT32_C(  1771414618), -INT32_C(  2025501204),  INT32_C(  1905921613),  INT32_C(  1301089229),  INT32_C(  2117227785),  INT32_C(  1313930535) } },
    { {  INT32_C(  1988271902), -INT32_C(   928422277),  INT32_C(   751124781), -INT32_C(  1615080274), -INT32_C(  1457437893),  INT32_C(  1967921693), -INT32_C(   719093602),  INT32_C(  1590290629) },
      UINT8_C(184),
      { -INT32_C(   200700131), -INT32_C(  1501991200),  INT32_C(  1863812719), -INT32_C(  2110506296), -INT32_C(   281811570), -INT32_C(  1957556859), -INT32_C(   274670855),  INT32_C(   588775262) },
      {  INT32_C(    48549005), -INT32_C(  1189837525), -INT32_C(   246645075),  INT32_C(   710580162),  INT32_C(  1547365021), -INT32_C(  1190799946), -INT32_C(   758766312), -INT32_C(  1139192475) },
      {  INT32_C(  1988271902), -INT32_C(   928422277),  INT32_C(   751124781), -INT32_C(  1399926134),  INT32_C(  1265553451),  INT32_C(  1146610491), -INT32_C(   719093602), -INT32_C(   550417213) } },
    { { -INT32_C(  1607524027), -INT32_C(  1435945627), -INT32_C(  1834704498), -INT32_C(  2007313332), -INT32_C(  1883122106), -INT32_C(  1075124600),  INT32_C(  1649535565), -INT32_C(   868112955) },
      UINT8_C( 77),
      {  INT32_C(   441881310),  INT32_C(  1966218471),  INT32_C(  1844649392), -INT32_C(   321863841),  INT32_C(    26145081),  INT32_C(  2066060518), -INT32_C(  1310174374), -INT32_C(  1468908845) },
      {  INT32_C(   900269734),  INT32_C(  1516547149),  INT32_C(  1563014998),  INT32_C(    47500850), -INT32_C(  2090628180),  INT32_C(   430978017), -INT32_C(  2091637067),  INT32_C(  1915750227) },
      {  INT32_C(  1342151044), -INT32_C(  1435945627), -INT32_C(   887302906), -INT32_C(   274362991), -INT32_C(  1883122106), -INT32_C(  1075124600),  INT32_C(   893155855), -INT32_C(   868112955) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_add_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(101),
      { -INT32_C(   628298337),  INT32_C(   792924887), -INT32_C(  1672768632), -INT32_C(  1074053347), -INT32_C(  1064007895),  INT32_C(  1455536926), -INT32_C(  1219047864),  INT32_C(  1560140371) },
      {  INT32_C(  1960233098),  INT32_C(  1892059781), -INT32_C(  1373718700), -INT32_C(   352286831),  INT32_C(  1327327802),  INT32_C(   454025751),  INT32_C(  2093702863), -INT32_C(  1771120467) },
      {  INT32_C(  1331934761),  INT32_C(           0),  INT32_C(  1248479964),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1909562677),  INT32_C(   874654999),  INT32_C(           0) } },
    { UINT8_C( 88),
      { -INT32_C(   643482639),  INT32_C(  1022430836),  INT32_C(  1708754555), -INT32_C(  1303850341),  INT32_C(  1960699394),  INT32_C(   694659735),  INT32_C(   142013690),  INT32_C(   821320707) },
      { -INT32_C(   242563209),  INT32_C(  1657605631), -INT32_C(  1229937754),  INT32_C(  1696216758), -INT32_C(  1213277610), -INT32_C(   353040792),  INT32_C(   392990364),  INT32_C(  1905216013) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   392366417),  INT32_C(   747421784),  INT32_C(           0),  INT32_C(   535004054),  INT32_C(           0) } },
    { UINT8_C(212),
      { -INT32_C(  1571159102),  INT32_C(  2016749220), -INT32_C(  1981095890), -INT32_C(  1870763484), -INT32_C(   836082282), -INT32_C(   660363674), -INT32_C(  1962323400), -INT32_C(   143449086) },
      { -INT32_C(   765186109),  INT32_C(  1029534834),  INT32_C(     6988289),  INT32_C(  1621597364), -INT32_C(   789981577),  INT32_C(  1804329931),  INT32_C(  1186001858),  INT32_C(   883248384) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1974107601),  INT32_C(           0), -INT32_C(  1626063859),  INT32_C(           0), -INT32_C(   776321542),  INT32_C(   739799298) } },
    { UINT8_C(109),
      { -INT32_C(  1770917884), -INT32_C(   530889520), -INT32_C(   504237856), -INT32_C(  1597380183), -INT32_C(  1049867779), -INT32_C(   468326631),  INT32_C(   559503757),  INT32_C(   564004527) },
      {  INT32_C(  1698045997), -INT32_C(   820697417), -INT32_C(    38633790),  INT32_C(   881187224),  INT32_C(  1921955153),  INT32_C(   941315295),  INT32_C(   759745706), -INT32_C(  2126521994) },
      { -INT32_C(    72871887),  INT32_C(           0), -INT32_C(   542871646), -INT32_C(   716192959),  INT32_C(           0),  INT32_C(   472988664),  INT32_C(  1319249463),  INT32_C(           0) } },
    { UINT8_C(137),
      { -INT32_C(  1858814058), -INT32_C(  1042377463), -INT32_C(   887474565), -INT32_C(  2122945850),  INT32_C(  1667461733), -INT32_C(   205579704), -INT32_C(   975714158),  INT32_C(  1635367554) },
      { -INT32_C(  1057794330),  INT32_C(  1052274960), -INT32_C(    41436220),  INT32_C(   143840279), -INT32_C(  1906448242), -INT32_C(  1788921821),  INT32_C(    10365593),  INT32_C(    35226418) },
      {  INT32_C(  1378358908),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1979105571),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1670593972) } },
    { UINT8_C( 14),
      {  INT32_C(   955121944), -INT32_C(  1858149961),  INT32_C(   989283609), -INT32_C(  1140579072), -INT32_C(   447254547), -INT32_C(   109214975), -INT32_C(   782653276), -INT32_C(   848887013) },
      { -INT32_C(  1458708646), -INT32_C(    83883126),  INT32_C(  1994371146),  INT32_C(  1884018050), -INT32_C(  1630751337), -INT32_C(   235406036),  INT32_C(   301613089),  INT32_C(  1337287860) },
      {  INT32_C(           0), -INT32_C(  1942033087), -INT32_C(  1311312541),  INT32_C(   743438978),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 68),
      { -INT32_C(    17343115), -INT32_C(  1057582083),  INT32_C(  1925676355),  INT32_C(   513737506),  INT32_C(  1449532125),  INT32_C(   651379898),  INT32_C(   265490234),  INT32_C(  1273345831) },
      {  INT32_C(  1163851905), -INT32_C(  1572780827),  INT32_C(  1722687548),  INT32_C(  1425094090),  INT32_C(    16744716),  INT32_C(  1308498419), -INT32_C(   505877045), -INT32_C(   219979393) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   646603393),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   240386811),  INT32_C(           0) } },
    { UINT8_C(143),
      { -INT32_C(  1104597870), -INT32_C(   724590379),  INT32_C(  1429138415),  INT32_C(  1193975544),  INT32_C(  1467334920), -INT32_C(  1899396965),  INT32_C(  2086966300),  INT32_C(   710186623) },
      { -INT32_C(  1112373334),  INT32_C(   406415980), -INT32_C(  1125556542), -INT32_C(   990567746), -INT32_C(   543146280), -INT32_C(  1976533491), -INT32_C(   337560786),  INT32_C(   640868710) },
      {  INT32_C(  2077996092), -INT32_C(   318174399),  INT32_C(   303581873),  INT32_C(   203407798),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1351055333) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_add_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C(  360909485362196701),  INT64_C( 7148018188301179842),  INT64_C( 1649121149472017725),  INT64_C( 7018633285360450459) },
      UINT8_C(126),
      { -INT64_C( 2069953424375465822),  INT64_C( 2649419973831635918),  INT64_C( 6631995759656128229),  INT64_C( 9043749468674069294) },
      {  INT64_C( 9127572592675566832),  INT64_C( 3139630957469384257), -INT64_C( 5603674882213165495),  INT64_C( 5601563532454726799) },
      {  INT64_C(  360909485362196701),  INT64_C( 5789050931301020175),  INT64_C( 1028320877442962734), -INT64_C( 3801431072580755523) } },
    { {  INT64_C(  756376000083734984),  INT64_C( 9070926205802174906),  INT64_C( 8919263102054599581),  INT64_C( 7783409138876853393) },
      UINT8_C(148),
      {  INT64_C(  382287398418300828),  INT64_C( 1115930529724925645), -INT64_C( 2730316823403657925),  INT64_C(  770900165413777792) },
      {  INT64_C( 6713096438988588943),  INT64_C( 6664457870741226758),  INT64_C(  234662618570907527), -INT64_C(  313102228808514227) },
      {  INT64_C(  756376000083734984),  INT64_C( 9070926205802174906), -INT64_C( 2495654204832750398),  INT64_C( 7783409138876853393) } },
    { {  INT64_C( 1483073417317823758),  INT64_C( 8795153962326963887), -INT64_C( 4149002502104727210),  INT64_C( 8377900925383693364) },
      UINT8_C( 87),
      {  INT64_C( 9038467157306396791), -INT64_C( 9115228638979228790),  INT64_C( 3197974720961571240), -INT64_C( 4399071158149707528) },
      {  INT64_C( 4732531473964703663), -INT64_C( 5052728689924432136), -INT64_C( 7671229005429790575),  INT64_C( 8865457101011322896) },
      { -INT64_C( 4675745442438451162),  INT64_C( 4278786744805890690), -INT64_C( 4473254284468219335),  INT64_C( 8377900925383693364) } },
    { { -INT64_C( 1491568665462998214), -INT64_C( 3104012194786369954), -INT64_C( 7320413738587291346),  INT64_C( 2384471346820870965) },
      UINT8_C(225),
      {  INT64_C( 8948791811858071094),  INT64_C( 5692550040163038202),  INT64_C(  830789416759788308),  INT64_C( 8983297292243767262) },
      {  INT64_C( 1554136023168485625),  INT64_C( 4643374375046125828),  INT64_C( 1207394444856260247),  INT64_C( 1262475476216602754) },
      { -INT64_C( 7943816238682994897), -INT64_C( 3104012194786369954), -INT64_C( 7320413738587291346),  INT64_C( 2384471346820870965) } },
    { { -INT64_C( 2613596307693393920),  INT64_C( 3708150816535274390),  INT64_C( 8656585681334612292), -INT64_C( 4071969454335091598) },
      UINT8_C(205),
      {  INT64_C( 4385428620712312621), -INT64_C( 6056401822535469397), -INT64_C( 5800804598671026971), -INT64_C( 3092870165874030482) },
      { -INT64_C( 2397873348439446309),  INT64_C( 5910269085379428366), -INT64_C( 1513047638103079921),  INT64_C(   34238311786967204) },
      {  INT64_C( 1987555272272866312),  INT64_C( 3708150816535274390), -INT64_C( 7313852236774106892), -INT64_C( 3058631854087063278) } },
    { {  INT64_C( 8817443827781467208), -INT64_C( 6180758275292564870), -INT64_C( 4102290530891378202),  INT64_C( 1720054592936513257) },
      UINT8_C(101),
      {  INT64_C( 8678261917080766892),  INT64_C( 6939458579392878936), -INT64_C( 1907623884063940351), -INT64_C( 1780765326956861806) },
      {  INT64_C( 3690861860797904287),  INT64_C( 7163125489808023225), -INT64_C( 7713699132847182549), -INT64_C( 5838526841458117177) },
      { -INT64_C( 6077620295830880437), -INT64_C( 6180758275292564870),  INT64_C( 8825421056798428716),  INT64_C( 1720054592936513257) } },
    { { -INT64_C( 4226189128237357280), -INT64_C( 8943401384532428378),  INT64_C(  205521322776642791),  INT64_C( 8979119138226217421) },
      UINT8_C(100),
      {  INT64_C(   74791247571826988),  INT64_C( 6811658127022208365), -INT64_C( 2788904720803475790),  INT64_C( 2092431171636941532) },
      { -INT64_C( 4721001194988252981), -INT64_C( 5047893754993698744), -INT64_C( 9019989623988394261),  INT64_C( 6590525094843788764) },
      { -INT64_C( 4226189128237357280), -INT64_C( 8943401384532428378),  INT64_C( 6637849728917681565),  INT64_C( 8979119138226217421) } },
    { { -INT64_C( 5055154983797961474),  INT64_C(     708989412318452),  INT64_C( 3248858564412742665), -INT64_C( 1488234339305196330) },
      UINT8_C( 97),
      { -INT64_C( 1196281769919788973), -INT64_C( 5928234014316609444), -INT64_C( 3324535828431189494), -INT64_C( 5570270810707974551) },
      { -INT64_C( 1528923573651634989), -INT64_C( 8239253630832908272),  INT64_C(  446928026184942104), -INT64_C( 7452034225800619308) },
      { -INT64_C( 2725205343571423962),  INT64_C(     708989412318452),  INT64_C( 3248858564412742665), -INT64_C( 1488234339305196330) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_add_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(211),
      {  INT64_C( 5396742621358824656), -INT64_C( 5784837964580948014),  INT64_C(  745905599035155894),  INT64_C( 4432459820370420263) },
      { -INT64_C( 2375627515263830277),  INT64_C( 7298802839973142414), -INT64_C( 4614916525088736096), -INT64_C( 9037591478603085962) },
      {  INT64_C( 3021115106094994379),  INT64_C( 1513964875392194400),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(176),
      { -INT64_C( 3141262892297976873), -INT64_C( 2562411322036282317),  INT64_C( 3833520914396613866),  INT64_C( 2194941788560940840) },
      {  INT64_C(  901766347898667771),  INT64_C( 7724355933804345671), -INT64_C( 7464625842775737952), -INT64_C( 2080691623985024546) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(195),
      { -INT64_C( 6193321100419901660),  INT64_C( 8380227380500028405),  INT64_C( 6069563355255056514),  INT64_C( 7567844964561032724) },
      { -INT64_C( 2028429546419720554),  INT64_C( 5900094282335619633), -INT64_C( 3089803978563711891),  INT64_C(  365280098963395815) },
      { -INT64_C( 8221750646839622214), -INT64_C( 4166422410873903578),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 97),
      { -INT64_C( 6385959693145891606),  INT64_C( 5329109541483815658), -INT64_C( 2688882311189433873),  INT64_C( 9217817113255199635) },
      {  INT64_C( 1459731060611346300), -INT64_C( 3886780218327649651),  INT64_C( 7977890084846895501),  INT64_C( 4735556178160298813) },
      { -INT64_C( 4926228632534545306),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(134),
      {  INT64_C( 7860706032630943107),  INT64_C( 2484009629061100715),  INT64_C( 7509120629608935666), -INT64_C( 2386733518501817427) },
      {  INT64_C( 8447004062159754569), -INT64_C( 1567962289685365340), -INT64_C( 8386187512053637187), -INT64_C( 1215046594740082176) },
      {  INT64_C(                   0),  INT64_C(  916047339375735375), -INT64_C(  877066882444701521),  INT64_C(                   0) } },
    { UINT8_C(199),
      { -INT64_C( 2180470979029174228),  INT64_C( 6443804020022187526), -INT64_C( 6418035538474219843), -INT64_C( 5507798642899854187) },
      {  INT64_C( 2466999869382999871),  INT64_C(  996995031899642676), -INT64_C(   73336982042601123),  INT64_C( 6989615507504111215) },
      {  INT64_C(  286528890353825643),  INT64_C( 7440799051921830202), -INT64_C( 6491372520516820966),  INT64_C(                   0) } },
    { UINT8_C(  0),
      { -INT64_C( 8767112038748657730), -INT64_C( 7052635034042790208), -INT64_C( 6603890804231331725), -INT64_C( 3131137631410272858) },
      { -INT64_C( 1591887663143957093),  INT64_C( 8922603379407992151), -INT64_C(  206750837837817474),  INT64_C( 1015076583748941132) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(231),
      {  INT64_C( 6842434063541616318), -INT64_C( 6075517079359538540),  INT64_C( 1270586480222899316),  INT64_C( 7380126505793994543) },
      {  INT64_C( 8872434914943821287), -INT64_C( 6662427551341978491), -INT64_C( 3648454390316234397),  INT64_C( 6544313852933680065) },
      { -INT64_C( 2731875095224114011),  INT64_C( 5708799443008034585), -INT64_C( 2377867910093335081),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_add_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
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

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_abs_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_abs_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_abs_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_add_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
