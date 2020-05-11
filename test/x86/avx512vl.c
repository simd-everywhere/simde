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

#if defined(SIMDE_X86_AVX512VL_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm_cvtsepi16_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtsepi16_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsepi32_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtsepi32_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsepi32_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtsepi32_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsepi64_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtsepi64_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mask_mov_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i src;
    simde__mmask16 k;
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -98), INT8_C( -63), INT8_C( -58), INT8_C(  25),
                        INT8_C(   9), INT8_C(  49), INT8_C( -12), INT8_C( -31),
                        INT8_C( -48), INT8_C(   0), INT8_C( -99), INT8_C( -81),
                        INT8_C( -77), INT8_C(  27), INT8_C( -33), INT8_C(-124)),
      UINT16_C(64699),
     simde_mm_set_epi8(INT8_C(  79), INT8_C( 100), INT8_C(-123), INT8_C(  95),
                        INT8_C( -79), INT8_C(  48), INT8_C( 112), INT8_C(   8),
                        INT8_C(  69), INT8_C( -78), INT8_C(  54), INT8_C( -48),
                        INT8_C(-119), INT8_C(  -5), INT8_C( -97), INT8_C( -44)),
      simde_mm_set_epi8(INT8_C(  79), INT8_C( 100), INT8_C(-123), INT8_C(  95),
                        INT8_C( -79), INT8_C(  48), INT8_C( -12), INT8_C( -31),
                        INT8_C(  69), INT8_C(   0), INT8_C(  54), INT8_C( -48),
                        INT8_C(-119), INT8_C(  27), INT8_C( -97), INT8_C( -44)) },
    { simde_mm_set_epi8(INT8_C(  47), INT8_C(  36), INT8_C(  45), INT8_C( -44),
                        INT8_C(  27), INT8_C( -15), INT8_C( 105), INT8_C( -69),
                        INT8_C( -10), INT8_C(   1), INT8_C(  12), INT8_C( -44),
                        INT8_C( -32), INT8_C( 113), INT8_C( 105), INT8_C( -92)),
      UINT16_C(33046),
     simde_mm_set_epi8(INT8_C(-118), INT8_C( -61), INT8_C( 108), INT8_C(   4),
                        INT8_C(  56), INT8_C(  96), INT8_C( -73), INT8_C( -39),
                        INT8_C(-112), INT8_C(-115), INT8_C(-113), INT8_C( -74),
                        INT8_C( -79), INT8_C(-116), INT8_C( 117), INT8_C(  -3)),
      simde_mm_set_epi8(INT8_C(-118), INT8_C(  36), INT8_C(  45), INT8_C( -44),
                        INT8_C(  27), INT8_C( -15), INT8_C( 105), INT8_C( -39),
                        INT8_C( -10), INT8_C(   1), INT8_C(  12), INT8_C( -74),
                        INT8_C( -32), INT8_C(-116), INT8_C( 117), INT8_C( -92)) },
    { simde_mm_set_epi8(INT8_C(  41), INT8_C(-106), INT8_C( -67), INT8_C(-116),
                        INT8_C( -34), INT8_C(  21), INT8_C(  64), INT8_C(  44),
                        INT8_C(  97), INT8_C( -46), INT8_C( 122), INT8_C(  42),
                        INT8_C( -54), INT8_C( -79), INT8_C(  21), INT8_C(  59)),
      UINT16_C(27487),
     simde_mm_set_epi8(INT8_C(   6), INT8_C(-124), INT8_C(-111), INT8_C( -39),
                        INT8_C(  55), INT8_C( -55), INT8_C( -72), INT8_C(  77),
                        INT8_C(  51), INT8_C(-103), INT8_C( -80), INT8_C(  75),
                        INT8_C( -87), INT8_C(-120), INT8_C( -14), INT8_C(  99)),
      simde_mm_set_epi8(INT8_C(  41), INT8_C(-124), INT8_C(-111), INT8_C(-116),
                        INT8_C(  55), INT8_C(  21), INT8_C( -72), INT8_C(  77),
                        INT8_C(  97), INT8_C(-103), INT8_C( 122), INT8_C(  75),
                        INT8_C( -87), INT8_C(-120), INT8_C( -14), INT8_C(  99)) },
    { simde_mm_set_epi8(INT8_C(  31), INT8_C( -90), INT8_C(-127), INT8_C( 105),
                        INT8_C( -89), INT8_C(-121), INT8_C(-110), INT8_C( -58),
                        INT8_C( -95), INT8_C(-101), INT8_C( -56), INT8_C(  22),
                        INT8_C(  18), INT8_C(   2), INT8_C(  46), INT8_C(-125)),
      UINT16_C(48165),
     simde_mm_set_epi8(INT8_C( 103), INT8_C(  26), INT8_C( 108), INT8_C(   4),
                        INT8_C( -49), INT8_C( -62), INT8_C(-103), INT8_C( -42),
                        INT8_C( 103), INT8_C( 115), INT8_C( 126), INT8_C(-112),
                        INT8_C( -81), INT8_C( -35), INT8_C(-106), INT8_C(  45)),
      simde_mm_set_epi8(INT8_C( 103), INT8_C( -90), INT8_C( 108), INT8_C(   4),
                        INT8_C( -49), INT8_C( -62), INT8_C(-110), INT8_C( -58),
                        INT8_C( -95), INT8_C(-101), INT8_C( 126), INT8_C(  22),
                        INT8_C(  18), INT8_C( -35), INT8_C(  46), INT8_C(  45)) },
    { simde_mm_set_epi8(INT8_C( 106), INT8_C(  23), INT8_C( -78), INT8_C( -57),
                        INT8_C(  24), INT8_C(  56), INT8_C( -46), INT8_C( -15),
                        INT8_C( -33), INT8_C(  28), INT8_C( -40), INT8_C(-116),
                        INT8_C( -34), INT8_C(  92), INT8_C( 109), INT8_C(  33)),
      UINT16_C(14870),
     simde_mm_set_epi8(INT8_C( -75), INT8_C(  55), INT8_C(-127), INT8_C(  70),
                        INT8_C(  78), INT8_C( 126), INT8_C( -96), INT8_C( 119),
                        INT8_C( 108), INT8_C(  50), INT8_C(  17), INT8_C( -71),
                        INT8_C( 127), INT8_C(  91), INT8_C( 110), INT8_C( -90)),
      simde_mm_set_epi8(INT8_C( 106), INT8_C(  23), INT8_C(-127), INT8_C(  70),
                        INT8_C(  78), INT8_C(  56), INT8_C( -96), INT8_C( -15),
                        INT8_C( -33), INT8_C(  28), INT8_C( -40), INT8_C( -71),
                        INT8_C( -34), INT8_C(  91), INT8_C( 110), INT8_C(  33)) },
    { simde_mm_set_epi8(INT8_C( -21), INT8_C(-122), INT8_C(-127), INT8_C(  95),
                        INT8_C( -34), INT8_C( -51), INT8_C( 107), INT8_C(  75),
                        INT8_C(  63), INT8_C(-117), INT8_C(-118), INT8_C(  52),
                        INT8_C(  15), INT8_C( 123), INT8_C( -76), INT8_C(-117)),
      UINT16_C(54314),
     simde_mm_set_epi8(INT8_C( 124), INT8_C( -12), INT8_C(   0), INT8_C( -14),
                        INT8_C( -54), INT8_C(  92), INT8_C(  73), INT8_C(  69),
                        INT8_C( -47), INT8_C( -62), INT8_C( 113), INT8_C( 100),
                        INT8_C(  31), INT8_C( -98), INT8_C( -86), INT8_C(  19)),
      simde_mm_set_epi8(INT8_C( 124), INT8_C( -12), INT8_C(-127), INT8_C( -14),
                        INT8_C( -34), INT8_C(  92), INT8_C( 107), INT8_C(  75),
                        INT8_C(  63), INT8_C(-117), INT8_C( 113), INT8_C(  52),
                        INT8_C(  31), INT8_C( 123), INT8_C( -86), INT8_C(-117)) },
    { simde_mm_set_epi8(INT8_C(  -9), INT8_C( -43), INT8_C(  83), INT8_C(  21),
                        INT8_C(  88), INT8_C( -52), INT8_C(-115), INT8_C(  63),
                        INT8_C(  92), INT8_C( -15), INT8_C( -24), INT8_C( -84),
                        INT8_C(-120), INT8_C( -96), INT8_C(  46), INT8_C( -78)),
      UINT16_C(44998),
     simde_mm_set_epi8(INT8_C( -10), INT8_C(  79), INT8_C(-113), INT8_C( -93),
                        INT8_C(  24), INT8_C(  78), INT8_C(  40), INT8_C(  22),
                        INT8_C(  31), INT8_C( -15), INT8_C(  -8), INT8_C(  60),
                        INT8_C( 114), INT8_C( -85), INT8_C(-105), INT8_C( -47)),
      simde_mm_set_epi8(INT8_C( -10), INT8_C( -43), INT8_C(-113), INT8_C(  21),
                        INT8_C(  24), INT8_C(  78), INT8_C(  40), INT8_C(  22),
                        INT8_C(  31), INT8_C( -15), INT8_C( -24), INT8_C( -84),
                        INT8_C(-120), INT8_C( -85), INT8_C(-105), INT8_C( -78)) },
    { simde_mm_set_epi8(INT8_C( -62), INT8_C( 117), INT8_C(-114), INT8_C(   7),
                        INT8_C(  17), INT8_C( 123), INT8_C(  -2), INT8_C( -15),
                        INT8_C(-120), INT8_C(  77), INT8_C(  81), INT8_C( -39),
                        INT8_C(-114), INT8_C( -52), INT8_C(-119), INT8_C(  82)),
      UINT16_C(48425),
     simde_mm_set_epi8(INT8_C(  68), INT8_C( -65), INT8_C(  13), INT8_C( -27),
                        INT8_C(  55), INT8_C(   2), INT8_C( -43), INT8_C(   9),
                        INT8_C( -57), INT8_C(  65), INT8_C(-111), INT8_C( -60),
                        INT8_C(  75), INT8_C(  74), INT8_C(  16), INT8_C(  19)),
      simde_mm_set_epi8(INT8_C(  68), INT8_C( 117), INT8_C(  13), INT8_C( -27),
                        INT8_C(  55), INT8_C(   2), INT8_C(  -2), INT8_C(   9),
                        INT8_C(-120), INT8_C(  77), INT8_C(-111), INT8_C( -39),
                        INT8_C(  75), INT8_C( -52), INT8_C(-119), INT8_C(  19)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mask_mov_epi8(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mask_mov_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i src;
    simde__mmask8 k;
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-14576), INT16_C( 14205), INT16_C( -2433), INT16_C(-27972),
                         INT16_C(  6192), INT16_C(-29093), INT16_C( 24144), INT16_C(-19045)),
      UINT8_C(231),
      simde_mm_set_epi16(INT16_C(-16025), INT16_C( -5226), INT16_C( -6596), INT16_C(-11796),
                         INT16_C(-24692), INT16_C( 20335), INT16_C( 26237), INT16_C( 23499)),
      simde_mm_set_epi16(INT16_C(-16025), INT16_C( -5226), INT16_C( -6596), INT16_C(-27972),
                         INT16_C(  6192), INT16_C( 20335), INT16_C( 26237), INT16_C( 23499)) },
    { simde_mm_set_epi16(INT16_C(  -839), INT16_C(-10951), INT16_C(  1310), INT16_C( -6285),
                         INT16_C(-21252), INT16_C( -7582), INT16_C(-12381), INT16_C( 24902)),
      UINT8_C(  7),
      simde_mm_set_epi16(INT16_C( -3233), INT16_C( 25022), INT16_C(-12043), INT16_C( 17022),
                         INT16_C(-25543), INT16_C(-17145), INT16_C(  8881), INT16_C( 28844)),
      simde_mm_set_epi16(INT16_C(  -839), INT16_C(-10951), INT16_C(  1310), INT16_C( -6285),
                         INT16_C(-21252), INT16_C(-17145), INT16_C(  8881), INT16_C( 28844)) },
    { simde_mm_set_epi16(INT16_C( 30807), INT16_C( 12936), INT16_C(-14387), INT16_C(-15179),
                         INT16_C( 23907), INT16_C(-17160), INT16_C( 23916), INT16_C( 14132)),
      UINT8_C(139),
      simde_mm_set_epi16(INT16_C( -1315), INT16_C(-31661), INT16_C(-10075), INT16_C(-22609),
                         INT16_C(  9167), INT16_C(  6456), INT16_C( -7329), INT16_C( -8326)),
      simde_mm_set_epi16(INT16_C( -1315), INT16_C( 12936), INT16_C(-14387), INT16_C(-15179),
                         INT16_C(  9167), INT16_C(-17160), INT16_C( -7329), INT16_C( -8326)) },
    { simde_mm_set_epi16(INT16_C( 26421), INT16_C(-12708), INT16_C( 22525), INT16_C(-31426),
                         INT16_C( 15010), INT16_C(-27490), INT16_C(-12766), INT16_C(-25791)),
      UINT8_C( 65),
      simde_mm_set_epi16(INT16_C( -1553), INT16_C(-19304), INT16_C( 20094), INT16_C( -2808),
                         INT16_C(-12327), INT16_C( 15252), INT16_C( 25789), INT16_C(-23968)),
      simde_mm_set_epi16(INT16_C( 26421), INT16_C(-19304), INT16_C( 22525), INT16_C(-31426),
                         INT16_C( 15010), INT16_C(-27490), INT16_C(-12766), INT16_C(-23968)) },
    { simde_mm_set_epi16(INT16_C(  7823), INT16_C( 19443), INT16_C( 13219), INT16_C( 17015),
                         INT16_C(-11739), INT16_C(-13030), INT16_C(-14482), INT16_C(-27926)),
      UINT8_C(249),
      simde_mm_set_epi16(INT16_C(-25131), INT16_C( 30189), INT16_C(-22900), INT16_C( 28700),
                         INT16_C(  1116), INT16_C( 30184), INT16_C(-12164), INT16_C( -7443)),
      simde_mm_set_epi16(INT16_C(-25131), INT16_C( 30189), INT16_C(-22900), INT16_C( 28700),
                         INT16_C(  1116), INT16_C(-13030), INT16_C(-14482), INT16_C( -7443)) },
    { simde_mm_set_epi16(INT16_C(-26628), INT16_C( 25963), INT16_C(-26322), INT16_C( -8077),
                         INT16_C(-22868), INT16_C( 28633), INT16_C( -4168), INT16_C( 28595)),
      UINT8_C(112),
      simde_mm_set_epi16(INT16_C( 14185), INT16_C( -5351), INT16_C( -8435), INT16_C(-11233),
                         INT16_C( -8273), INT16_C(-29718), INT16_C( -8221), INT16_C( 18236)),
      simde_mm_set_epi16(INT16_C(-26628), INT16_C( -5351), INT16_C( -8435), INT16_C(-11233),
                         INT16_C(-22868), INT16_C( 28633), INT16_C( -4168), INT16_C( 28595)) },
    { simde_mm_set_epi16(INT16_C(-14557), INT16_C(-28064), INT16_C( 11696), INT16_C(-19213),
                         INT16_C( 15613), INT16_C( 26380), INT16_C( 30063), INT16_C( 26293)),
      UINT8_C( 24),
      simde_mm_set_epi16(INT16_C( 23790), INT16_C( 10772), INT16_C( -8418), INT16_C(-27527),
                         INT16_C(  -163), INT16_C( 10898), INT16_C(-12995), INT16_C(   287)),
      simde_mm_set_epi16(INT16_C(-14557), INT16_C(-28064), INT16_C( 11696), INT16_C(-27527),
                         INT16_C(  -163), INT16_C( 26380), INT16_C( 30063), INT16_C( 26293)) },
    { simde_mm_set_epi16(INT16_C(-14768), INT16_C(-23816), INT16_C(-22775), INT16_C( -4812),
                         INT16_C(-19595), INT16_C(-14349), INT16_C( 11039), INT16_C( 15081)),
      UINT8_C( 22),
      simde_mm_set_epi16(INT16_C( 27063), INT16_C(  8226), INT16_C(-13582), INT16_C( 14344),
                         INT16_C(-27643), INT16_C( -1125), INT16_C(-27147), INT16_C( -4132)),
      simde_mm_set_epi16(INT16_C(-14768), INT16_C(-23816), INT16_C(-22775), INT16_C( 14344),
                         INT16_C(-19595), INT16_C( -1125), INT16_C(-27147), INT16_C( 15081)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mask_mov_epi16(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mask_mov_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i src;
    simde__mmask8 k;
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
       { simde_mm_set_epi32(INT32_C(-1311777535), INT32_C(  871351059), INT32_C(-1795529748), INT32_C(-1018886524)),
      UINT8_C(193),
      simde_mm_set_epi32(INT32_C(-1402384713), INT32_C(  349677639), INT32_C(-2062419968), INT32_C(-2110667873)),
      simde_mm_set_epi32(INT32_C(-1311777535), INT32_C(  871351059), INT32_C(-1795529748), INT32_C(-2110667873)) },
    { simde_mm_set_epi32(INT32_C(  738895957), INT32_C(-2052149671), INT32_C( 1275190943), INT32_C(-1073987906)),
      UINT8_C(211),
      simde_mm_set_epi32(INT32_C(  899624021), INT32_C(-1740875066), INT32_C(  196568235), INT32_C(  146964985)),
      simde_mm_set_epi32(INT32_C(  738895957), INT32_C(-2052149671), INT32_C(  196568235), INT32_C(  146964985)) },
    { simde_mm_set_epi32(INT32_C(  692992965), INT32_C(  836600954), INT32_C(-1461227321), INT32_C( -625910795)),
      UINT8_C(122),
      simde_mm_set_epi32(INT32_C(-1617549669), INT32_C( 1989374100), INT32_C(-1502577107), INT32_C(-1017994073)),
      simde_mm_set_epi32(INT32_C(-1617549669), INT32_C(  836600954), INT32_C(-1502577107), INT32_C( -625910795)) },
    { simde_mm_set_epi32(INT32_C( 1143677167), INT32_C(  846204550), INT32_C( -804913221), INT32_C( 1445583278)),
      UINT8_C(231),
      simde_mm_set_epi32(INT32_C(-1730413187), INT32_C(-1695584840), INT32_C( -227526716), INT32_C(   -3425875)),
      simde_mm_set_epi32(INT32_C( 1143677167), INT32_C(-1695584840), INT32_C( -227526716), INT32_C(   -3425875)) },
    { simde_mm_set_epi32(INT32_C(  645689114), INT32_C(-2084714818), INT32_C( 1764055823), INT32_C(   52635923)),
      UINT8_C( 92),
      simde_mm_set_epi32(INT32_C(-1571852402), INT32_C(  630152776), INT32_C( -128726906), INT32_C( 1269444726)),
      simde_mm_set_epi32(INT32_C(-1571852402), INT32_C(  630152776), INT32_C( 1764055823), INT32_C(   52635923)) },
    { simde_mm_set_epi32(INT32_C(    1563221), INT32_C( -134802286), INT32_C(  714712077), INT32_C(-1827172967)),
      UINT8_C( 81),
      simde_mm_set_epi32(INT32_C( 1929131576), INT32_C(-1816110300), INT32_C( 1278219947), INT32_C( 1799312980)),
      simde_mm_set_epi32(INT32_C(    1563221), INT32_C( -134802286), INT32_C(  714712077), INT32_C( 1799312980)) },
    { simde_mm_set_epi32(INT32_C(  398082434), INT32_C(-1574168894), INT32_C(  -78364073), INT32_C(-1210427726)),
      UINT8_C( 81),
      simde_mm_set_epi32(INT32_C( -743499294), INT32_C(-2007549651), INT32_C(  404949426), INT32_C(-1228263526)),
      simde_mm_set_epi32(INT32_C(  398082434), INT32_C(-1574168894), INT32_C(  -78364073), INT32_C(-1228263526)) },
    { simde_mm_set_epi32(INT32_C( -588057094), INT32_C(-1885829296), INT32_C( 1969228625), INT32_C( 1326338893)),
      UINT8_C(219),
      simde_mm_set_epi32(INT32_C( 1932026039), INT32_C(-1013786585), INT32_C( 1485053584), INT32_C( 1979373999)),
      simde_mm_set_epi32(INT32_C( 1932026039), INT32_C(-1885829296), INT32_C( 1485053584), INT32_C( 1979373999)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mask_mov_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mask_mov_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i src;
    simde__mmask8 k;
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
       { simde_mm_set_epi64x(INT64_C( 2277107027088284737), INT64_C( -794576880036979785)),
      UINT8_C(133),
      simde_mm_set_epi64x(INT64_C( 8097713530582561529), INT64_C( 1585963766693842069)),
      simde_mm_set_epi64x(INT64_C( 2277107027088284737), INT64_C( 1585963766693842069)) },
    { simde_mm_set_epi64x(INT64_C(  386114209698075166), INT64_C( 5207265957388900927)),
      UINT8_C(158),
      simde_mm_set_epi64x(INT64_C( 8803705323655107871), INT64_C(-8422781366242531322)),
      simde_mm_set_epi64x(INT64_C( 8803705323655107871), INT64_C( 5207265957388900927)) },
    { simde_mm_set_epi64x(INT64_C(-2685854854617637911), INT64_C( 5000183764696508529)),
      UINT8_C(188),
      simde_mm_set_epi64x(INT64_C( 3366037084418714211), INT64_C(-4379786006937181803)),
      simde_mm_set_epi64x(INT64_C(-2685854854617637911), INT64_C( 5000183764696508529)) },
    { simde_mm_set_epi64x(INT64_C( 5087362917606608352), INT64_C( 7748994405920281726)),
      UINT8_C( 72),
      simde_mm_set_epi64x(INT64_C(-3993157906773187111), INT64_C( 5848124444216740966)),
      simde_mm_set_epi64x(INT64_C( 5087362917606608352), INT64_C( 7748994405920281726)) },
    { simde_mm_set_epi64x(INT64_C(-6262495515547444433), INT64_C( 3943684472219148405)),
      UINT8_C( 56),
      simde_mm_set_epi64x(INT64_C( 6021985363878171356), INT64_C(-9003751561505293092)),
      simde_mm_set_epi64x(INT64_C(-6262495515547444433), INT64_C( 3943684472219148405)) },
    { simde_mm_set_epi64x(INT64_C( 7378184861631570903), INT64_C( 5065745925883054243)),
      UINT8_C(107),
      simde_mm_set_epi64x(INT64_C( 3940656342452910480), INT64_C( 3350136105944417294)),
      simde_mm_set_epi64x(INT64_C( 3940656342452910480), INT64_C( 3350136105944417294)) },
    { simde_mm_set_epi64x(INT64_C( 4422823463426654219), INT64_C( 1827699444722609855)),
      UINT8_C( 23),
      simde_mm_set_epi64x(INT64_C(-2966751886069965026), INT64_C(-8494473672325004777)),
      simde_mm_set_epi64x(INT64_C(-2966751886069965026), INT64_C(-8494473672325004777)) },
    { simde_mm_set_epi64x(INT64_C(-8917676865649705108), INT64_C( 6229148348133862992)),
      UINT8_C( 48),
      simde_mm_set_epi64x(INT64_C(-7968457113297908477), INT64_C(-6793891334661924961)),
      simde_mm_set_epi64x(INT64_C(-8917676865649705108), INT64_C( 6229148348133862992)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mask_mov_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskz_mov_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    {  UINT16_C(54402),
       simde_mm_set_epi8(INT8_C(  36), INT8_C(  97), INT8_C(-122), INT8_C(  62),
                        INT8_C( -43), INT8_C( -34), INT8_C( -14), INT8_C(-126),
                        INT8_C(  82), INT8_C( -27), INT8_C(-110), INT8_C( -49),
                        INT8_C(  86), INT8_C(  99), INT8_C( 100), INT8_C( -41)),
       simde_mm_set_epi8(INT8_C(  36), INT8_C(  97), INT8_C(   0), INT8_C(  62),
                        INT8_C(   0), INT8_C( -34), INT8_C(   0), INT8_C(   0),
                        INT8_C(  82), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C( 100), INT8_C(   0)) },
    {  UINT16_C( 9320),
       simde_mm_set_epi8(INT8_C(  42), INT8_C( -13), INT8_C(  59), INT8_C( -76),
                        INT8_C(  44), INT8_C(-127), INT8_C( -33), INT8_C(-116),
                        INT8_C(  13), INT8_C(   9), INT8_C( -47), INT8_C(  53),
                        INT8_C( -56), INT8_C(  87), INT8_C( -89), INT8_C(  72)),
       simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  59), INT8_C(   0),
                        INT8_C(   0), INT8_C(-127), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   9), INT8_C( -47), INT8_C(   0),
                        INT8_C( -56), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    {  UINT16_C( 7828),
       simde_mm_set_epi8(INT8_C( -41), INT8_C( -58), INT8_C(  78), INT8_C( -99),
                        INT8_C( -79), INT8_C(  93), INT8_C(  74), INT8_C(   5),
                        INT8_C(  40), INT8_C( -62), INT8_C( 109), INT8_C( -74),
                        INT8_C(   1), INT8_C( -60), INT8_C(  94), INT8_C(  12)),
       simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -99),
                        INT8_C( -79), INT8_C(  93), INT8_C(  74), INT8_C(   0),
                        INT8_C(  40), INT8_C(   0), INT8_C(   0), INT8_C( -74),
                        INT8_C(   0), INT8_C( -60), INT8_C(   0), INT8_C(   0)) },
    {  UINT16_C(55181),
       simde_mm_set_epi8(INT8_C(  37), INT8_C(  84), INT8_C( -36), INT8_C(-122),
                        INT8_C(  25), INT8_C( 108), INT8_C(  27), INT8_C(  95),
                        INT8_C( -44), INT8_C(-128), INT8_C( 110), INT8_C( -66),
                        INT8_C(  74), INT8_C( -16), INT8_C( 122), INT8_C( -30)),
       simde_mm_set_epi8(INT8_C(  37), INT8_C(  84), INT8_C(   0), INT8_C(-122),
                        INT8_C(   0), INT8_C( 108), INT8_C(  27), INT8_C(  95),
                        INT8_C( -44), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  74), INT8_C( -16), INT8_C(   0), INT8_C( -30)) },
    {  UINT16_C(57564),
       simde_mm_set_epi8(INT8_C( -26), INT8_C(  -5), INT8_C(   7), INT8_C( -63),
                        INT8_C(  47), INT8_C(  32), INT8_C(  62), INT8_C(-108),
                        INT8_C(  26), INT8_C(  67), INT8_C( -45), INT8_C(  32),
                        INT8_C( -38), INT8_C(  61), INT8_C(-123), INT8_C(-123)),
       simde_mm_set_epi8(INT8_C( -26), INT8_C(  -5), INT8_C(   7), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  26), INT8_C(  67), INT8_C(   0), INT8_C(  32),
                        INT8_C( -38), INT8_C(  61), INT8_C(   0), INT8_C(   0)) },
    {  UINT16_C(58988),
       simde_mm_set_epi8(INT8_C( 108), INT8_C(   5), INT8_C(-115), INT8_C( -87),
                        INT8_C( 112), INT8_C(  24), INT8_C(  18), INT8_C( -62),
                        INT8_C( 120), INT8_C(  62), INT8_C( -22), INT8_C( -32),
                        INT8_C(  32), INT8_C( -91), INT8_C(  65), INT8_C(  79)),
       simde_mm_set_epi8(INT8_C( 108), INT8_C(   5), INT8_C(-115), INT8_C(   0),
                        INT8_C(   0), INT8_C(  24), INT8_C(  18), INT8_C(   0),
                        INT8_C(   0), INT8_C(  62), INT8_C( -22), INT8_C(   0),
                        INT8_C(  32), INT8_C( -91), INT8_C(   0), INT8_C(   0)) },
    {  UINT16_C(50535),
       simde_mm_set_epi8(INT8_C(-119), INT8_C( -52), INT8_C(-117), INT8_C( 112),
                        INT8_C( -70), INT8_C(-108), INT8_C(  -6), INT8_C(  88),
                        INT8_C(   5), INT8_C( -84), INT8_C(  11), INT8_C( -55),
                        INT8_C(-116), INT8_C(   8), INT8_C(  68), INT8_C(-111)),
       simde_mm_set_epi8(INT8_C(-119), INT8_C( -52), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(-108), INT8_C(   0), INT8_C(  88),
                        INT8_C(   0), INT8_C( -84), INT8_C(  11), INT8_C(   0),
                        INT8_C(   0), INT8_C(   8), INT8_C(  68), INT8_C(-111)) },
    {  UINT16_C(21029),
       simde_mm_set_epi8(INT8_C(-123), INT8_C(-110), INT8_C(  43), INT8_C( -78),
                        INT8_C(-113), INT8_C(  -6), INT8_C( -22), INT8_C(-111),
                        INT8_C(-114), INT8_C(  91), INT8_C(  78), INT8_C(  20),
                        INT8_C(  94), INT8_C(   5), INT8_C( 125), INT8_C(  13)),
       simde_mm_set_epi8(INT8_C(   0), INT8_C(-110), INT8_C(   0), INT8_C( -78),
                        INT8_C(   0), INT8_C(   0), INT8_C( -22), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  78), INT8_C(   0),
                        INT8_C(   0), INT8_C(   5), INT8_C(   0), INT8_C(  13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_maskz_mov_epi8(test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskz_mov_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    {  UINT8_C(172),
      simde_mm_set_epi16(INT16_C( 31369), INT16_C( 24471), INT16_C( -2198), INT16_C( 13931),
                         INT16_C(  8708), INT16_C(-30158), INT16_C( 19991), INT16_C(-25642)),
      simde_mm_set_epi16(INT16_C( 31369), INT16_C(     0), INT16_C( -2198), INT16_C(     0),
                         INT16_C(  8708), INT16_C(-30158), INT16_C(     0), INT16_C(     0)) },
   {  UINT8_C(174),
      simde_mm_set_epi16(INT16_C( 15685), INT16_C( 28576), INT16_C( 31286), INT16_C( 30917),
                         INT16_C( 32368), INT16_C( -7767), INT16_C(  5413), INT16_C( -7264)),
      simde_mm_set_epi16(INT16_C( 15685), INT16_C(     0), INT16_C( 31286), INT16_C(     0),
                         INT16_C( 32368), INT16_C( -7767), INT16_C(  5413), INT16_C(     0)) },
   {  UINT8_C(204),
      simde_mm_set_epi16(INT16_C(-32746), INT16_C( 32574), INT16_C( 12624), INT16_C( 27372),
                         INT16_C(-30923), INT16_C( 29148), INT16_C(-21083), INT16_C( 14295)),
      simde_mm_set_epi16(INT16_C(-32746), INT16_C( 32574), INT16_C(     0), INT16_C(     0),
                         INT16_C(-30923), INT16_C( 29148), INT16_C(     0), INT16_C(     0)) },
   {  UINT8_C( 95),
      simde_mm_set_epi16(INT16_C(-30267), INT16_C(-15896), INT16_C( 22574), INT16_C(  2859),
                         INT16_C(  2365), INT16_C(  -901), INT16_C( 18813), INT16_C( 18335)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(-15896), INT16_C(     0), INT16_C(  2859),
                         INT16_C(  2365), INT16_C(  -901), INT16_C( 18813), INT16_C( 18335)) },
   {  UINT8_C( 67),
      simde_mm_set_epi16(INT16_C( 16076), INT16_C( 28949), INT16_C( 18472), INT16_C( 18435),
                         INT16_C(-29130), INT16_C(-15163), INT16_C(-12433), INT16_C( -3463)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C( 28949), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(-12433), INT16_C( -3463)) },
   {  UINT8_C( 73),
      simde_mm_set_epi16(INT16_C(-30899), INT16_C(-31361), INT16_C(-22956), INT16_C(-14855),
                         INT16_C(  -601), INT16_C(  2058), INT16_C( 17396), INT16_C(-31263)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(-31361), INT16_C(     0), INT16_C(     0),
                         INT16_C(  -601), INT16_C(     0), INT16_C(     0), INT16_C(-31263)) },
   {  UINT8_C(  1),
      simde_mm_set_epi16(INT16_C(  5707), INT16_C(-20763), INT16_C(  8635), INT16_C( -4245),
                         INT16_C( 27666), INT16_C(-18424), INT16_C(-22687), INT16_C( 15686)),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C( 15686)) },
   {  UINT8_C(172),
      simde_mm_set_epi16(INT16_C(  8809), INT16_C( 29917), INT16_C(   520), INT16_C(-12425),
                         INT16_C( 13592), INT16_C(-10913), INT16_C(-21871), INT16_C(  6317)),
      simde_mm_set_epi16(INT16_C(  8809), INT16_C(     0), INT16_C(   520), INT16_C(     0),
                         INT16_C( 13592), INT16_C(-10913), INT16_C(     0), INT16_C(     0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_maskz_mov_epi16(test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskz_mov_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
     {  UINT8_C(192),
        simde_mm_set_epi32(INT32_C(  656441296), INT32_C(-1852032257), INT32_C(  299494207), INT32_C(-1616873206)),
        simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
     {  UINT8_C(138),
        simde_mm_set_epi32(INT32_C(  707152322), INT32_C(-1311270924), INT32_C(-1503159730), INT32_C(-2099401846)),
        simde_mm_set_epi32(INT32_C(  707152322), INT32_C(          0), INT32_C(-1503159730), INT32_C(          0)) },
     {  UINT8_C(202),
        simde_mm_set_epi32(INT32_C(-1455100666), INT32_C(-2025285461), INT32_C( -179772388), INT32_C( 1367812127)),
        simde_mm_set_epi32(INT32_C(-1455100666), INT32_C(          0), INT32_C( -179772388), INT32_C(          0)) },
     {  UINT8_C(144),
        simde_mm_set_epi32(INT32_C(-1107178304), INT32_C(-1037282057), INT32_C(  779093870), INT32_C( 1250766721)),
        simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
     {  UINT8_C(121),
        simde_mm_set_epi32(INT32_C( -756555400), INT32_C( 1672370881), INT32_C( -263709411), INT32_C(  606108964)),
        simde_mm_set_epi32(INT32_C( -756555400), INT32_C(          0), INT32_C(          0), INT32_C(  606108964)) },
     {  UINT8_C( 11),
        simde_mm_set_epi32(INT32_C(  291215521), INT32_C(  371049029), INT32_C(  324114641), INT32_C( -986925670)),
        simde_mm_set_epi32(INT32_C(  291215521), INT32_C(          0), INT32_C(  324114641), INT32_C( -986925670)) },
     {  UINT8_C(200),
        simde_mm_set_epi32(INT32_C(-1248714533), INT32_C(  110176831), INT32_C(-1962006925), INT32_C( -973547490)),
        simde_mm_set_epi32(INT32_C(-1248714533), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
     {  UINT8_C(138),
        simde_mm_set_epi32(INT32_C( -971622476), INT32_C(  -95064376), INT32_C( -736538751), INT32_C(    7991884)),
        simde_mm_set_epi32(INT32_C( -971622476), INT32_C(          0), INT32_C( -736538751), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_maskz_mov_epi32(test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskz_mov_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
     {  UINT8_C(140),
        simde_mm_set_epi64x(INT64_C( 3798083087260184318), INT64_C( 5657333801282264243)),
        simde_mm_set_epi64x(INT64_C(                   0), INT64_C(                   0)) },
     {  UINT8_C( 59),
        simde_mm_set_epi64x(INT64_C( 6150838870455976373), INT64_C(-1888156961938500809)),
        simde_mm_set_epi64x(INT64_C( 6150838870455976373), INT64_C(-1888156961938500809)) },
     {  UINT8_C( 85),
        simde_mm_set_epi64x(INT64_C(-2963288110518582462), INT64_C( 4379558933354650160)),
        simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 4379558933354650160)) },
     {  UINT8_C(190),
        simde_mm_set_epi64x(INT64_C( 1293362407707663546), INT64_C( 3921888525347819158)),
        simde_mm_set_epi64x(INT64_C( 1293362407707663546), INT64_C(                   0)) },
     {  UINT8_C(114),
        simde_mm_set_epi64x(INT64_C(-7166753234573077348), INT64_C( 1514796214136072870)),
        simde_mm_set_epi64x(INT64_C(-7166753234573077348), INT64_C(                   0)) },
     {  UINT8_C( 57),
        simde_mm_set_epi64x(INT64_C(-5321356301108453394), INT64_C(-2450051547146928613)),
        simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-2450051547146928613)) },
     {  UINT8_C( 72),
        simde_mm_set_epi64x(INT64_C(-3635596340953309068), INT64_C(-4947516809045744754)),
        simde_mm_set_epi64x(INT64_C(                   0), INT64_C(                   0)) },
     {  UINT8_C( 27),
        simde_mm_set_epi64x(INT64_C(-4723518328184072824), INT64_C(-6365694246941149609)),
        simde_mm_set_epi64x(INT64_C(-4723518328184072824), INT64_C(-6365694246941149609)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_maskz_mov_epi64(test_vec[i].k, test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mask_mov_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i src;
    simde__mmask32 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( -82), INT8_C( -32), INT8_C( -73), INT8_C( -78),
                           INT8_C( -21), INT8_C(  76), INT8_C(  33), INT8_C(  90),
                           INT8_C( -57), INT8_C( -12), INT8_C(-121), INT8_C( 101),
                           INT8_C(   6), INT8_C( -36), INT8_C( -50), INT8_C( -33),
                           INT8_C( -83), INT8_C( -92), INT8_C(   2), INT8_C(  69),
                           INT8_C(  62), INT8_C(  89), INT8_C( 105), INT8_C(  58),
                           INT8_C( 125), INT8_C( -76), INT8_C(  27), INT8_C(  51),
                           INT8_C(  79), INT8_C( 101), INT8_C( -42), INT8_C( -69)),
      UINT32_C( 391141390),
      simde_mm256_set_epi8(INT8_C(  -9), INT8_C( -52), INT8_C(  27), INT8_C( -40),
                           INT8_C(  57), INT8_C( -80), INT8_C( -28), INT8_C(  64),
                           INT8_C(  70), INT8_C( -40), INT8_C(  14), INT8_C( -38),
                           INT8_C( -38), INT8_C( -99), INT8_C( -37), INT8_C( -35),
                           INT8_C( -82), INT8_C( -60), INT8_C( -40), INT8_C( -40),
                           INT8_C(  -5), INT8_C(   8), INT8_C( 109), INT8_C(  95),
                           INT8_C( 124), INT8_C(  34), INT8_C(  19), INT8_C( -65),
                           INT8_C(  -2), INT8_C( -92), INT8_C(  18), INT8_C( -33)),
      simde_mm256_set_epi8(INT8_C( -82), INT8_C( -32), INT8_C( -73), INT8_C( -40),
                           INT8_C( -21), INT8_C( -80), INT8_C( -28), INT8_C(  64),
                           INT8_C( -57), INT8_C( -40), INT8_C(-121), INT8_C( -38),
                           INT8_C(   6), INT8_C( -36), INT8_C( -50), INT8_C( -33),
                           INT8_C( -83), INT8_C( -60), INT8_C(   2), INT8_C( -40),
                           INT8_C(  -5), INT8_C(  89), INT8_C( 105), INT8_C(  58),
                           INT8_C( 125), INT8_C( -76), INT8_C(  27), INT8_C(  51),
                           INT8_C(  -2), INT8_C( -92), INT8_C(  18), INT8_C( -69)) },
    { simde_mm256_set_epi8(INT8_C( -54), INT8_C( -68), INT8_C(  19), INT8_C(  39),
                           INT8_C(  17), INT8_C( -32), INT8_C( -47), INT8_C( -26),
                           INT8_C( -23), INT8_C(  30), INT8_C(  98), INT8_C(   3),
                           INT8_C( -92), INT8_C( -30), INT8_C(  -8), INT8_C( -30),
                           INT8_C(  26), INT8_C(-116), INT8_C(  76), INT8_C( -76),
                           INT8_C( -29), INT8_C( -31), INT8_C( -31), INT8_C(  78),
                           INT8_C(  23), INT8_C(   6), INT8_C(  61), INT8_C(  68),
                           INT8_C( -53), INT8_C(-110), INT8_C(  53), INT8_C( -67)),
      UINT32_C( 757878650),
      simde_mm256_set_epi8(INT8_C(  36), INT8_C(-115), INT8_C( -95), INT8_C(   4),
                           INT8_C(  50), INT8_C( -54), INT8_C(  94), INT8_C(  54),
                           INT8_C( 109), INT8_C(-103), INT8_C(-124), INT8_C(  34),
                           INT8_C( -16), INT8_C(  97), INT8_C(  -7), INT8_C(  98),
                           INT8_C(-125), INT8_C( -49), INT8_C(   3), INT8_C( -91),
                           INT8_C( -99), INT8_C(  85), INT8_C( -25), INT8_C(   6),
                           INT8_C( -42), INT8_C(  44), INT8_C(  70), INT8_C( -24),
                           INT8_C( -86), INT8_C( 112), INT8_C( 116), INT8_C( -61)),
      simde_mm256_set_epi8(INT8_C( -54), INT8_C( -68), INT8_C( -95), INT8_C(  39),
                           INT8_C(  50), INT8_C( -54), INT8_C( -47), INT8_C(  54),
                           INT8_C( -23), INT8_C(  30), INT8_C(-124), INT8_C(   3),
                           INT8_C( -16), INT8_C(  97), INT8_C(  -8), INT8_C( -30),
                           INT8_C(  26), INT8_C( -49), INT8_C(  76), INT8_C( -76),
                           INT8_C( -99), INT8_C(  85), INT8_C( -25), INT8_C(   6),
                           INT8_C(  23), INT8_C(  44), INT8_C(  70), INT8_C( -24),
                           INT8_C( -86), INT8_C(-110), INT8_C( 116), INT8_C( -67)) },
    { simde_mm256_set_epi8(INT8_C(  48), INT8_C( -19), INT8_C( -87), INT8_C( 100),
                           INT8_C( -44), INT8_C( -79), INT8_C( -72), INT8_C(  73),
                           INT8_C( -36), INT8_C(  58), INT8_C(-113), INT8_C( -42),
                           INT8_C( -85), INT8_C( 123), INT8_C(-106), INT8_C( -57),
                           INT8_C( -53), INT8_C(  96), INT8_C(  40), INT8_C( -52),
                           INT8_C( -17), INT8_C(  -6), INT8_C(-108), INT8_C(  33),
                           INT8_C( -15), INT8_C( 113), INT8_C(  31), INT8_C( -14),
                           INT8_C( 124), INT8_C(  15), INT8_C(  90), INT8_C(   1)),
      UINT32_C(2771863762),
      simde_mm256_set_epi8(INT8_C(  72), INT8_C( -95), INT8_C( 104), INT8_C( -28),
                           INT8_C(  25), INT8_C(  84), INT8_C(  66), INT8_C(  19),
                           INT8_C(  79), INT8_C( -84), INT8_C(  46), INT8_C(  23),
                           INT8_C( -85), INT8_C(  12), INT8_C(   6), INT8_C(  -9),
                           INT8_C(-108), INT8_C(  14), INT8_C( 103), INT8_C(  32),
                           INT8_C(  25), INT8_C(-108), INT8_C( -56), INT8_C(-111),
                           INT8_C(  23), INT8_C( -20), INT8_C(   4), INT8_C(  81),
                           INT8_C(  39), INT8_C(  39), INT8_C(  82), INT8_C( -15)),
      simde_mm256_set_epi8(INT8_C(  72), INT8_C( -19), INT8_C( 104), INT8_C( 100),
                           INT8_C( -44), INT8_C(  84), INT8_C( -72), INT8_C(  19),
                           INT8_C( -36), INT8_C(  58), INT8_C(  46), INT8_C(  23),
                           INT8_C( -85), INT8_C(  12), INT8_C(   6), INT8_C(  -9),
                           INT8_C( -53), INT8_C(  14), INT8_C(  40), INT8_C( -52),
                           INT8_C(  25), INT8_C(  -6), INT8_C(-108), INT8_C(  33),
                           INT8_C(  23), INT8_C( -20), INT8_C(  31), INT8_C(  81),
                           INT8_C( 124), INT8_C(  15), INT8_C(  82), INT8_C(   1)) },
    { simde_mm256_set_epi8(INT8_C(  57), INT8_C( -52), INT8_C( 127), INT8_C( -70),
                           INT8_C(  97), INT8_C(  95), INT8_C( -96), INT8_C( -99),
                           INT8_C(  22), INT8_C(-112), INT8_C(  66), INT8_C( -76),
                           INT8_C(  79), INT8_C(-100), INT8_C( -47), INT8_C(-114),
                           INT8_C( -72), INT8_C(  67), INT8_C(   3), INT8_C(  -9),
                           INT8_C(  88), INT8_C(  -5), INT8_C(-111), INT8_C(-100),
                           INT8_C( -94), INT8_C( -72), INT8_C( -45), INT8_C( -95),
                           INT8_C( 119), INT8_C( -81), INT8_C(  38), INT8_C(-111)),
      UINT32_C(4224621908),
      simde_mm256_set_epi8(INT8_C(-112), INT8_C(  63), INT8_C(  75), INT8_C(  90),
                           INT8_C(  -7), INT8_C( 116), INT8_C(-123), INT8_C( -34),
                           INT8_C(  81), INT8_C( 114), INT8_C( -76), INT8_C( -63),
                           INT8_C(  30), INT8_C(  66), INT8_C(  18), INT8_C(-119),
                           INT8_C(  26), INT8_C(  28), INT8_C(  56), INT8_C( 127),
                           INT8_C( -81), INT8_C(  -7), INT8_C( -20), INT8_C( -35),
                           INT8_C(  -7), INT8_C(  37), INT8_C( -47), INT8_C(  78),
                           INT8_C( 114), INT8_C( -18), INT8_C(  72), INT8_C(  -8)),
      simde_mm256_set_epi8(INT8_C(-112), INT8_C(  63), INT8_C(  75), INT8_C(  90),
                           INT8_C(  -7), INT8_C(  95), INT8_C(-123), INT8_C( -34),
                           INT8_C(  81), INT8_C( 114), INT8_C(  66), INT8_C( -76),
                           INT8_C(  30), INT8_C(  66), INT8_C(  18), INT8_C(-114),
                           INT8_C(  26), INT8_C(  67), INT8_C(   3), INT8_C( 127),
                           INT8_C( -81), INT8_C(  -7), INT8_C(-111), INT8_C( -35),
                           INT8_C( -94), INT8_C(  37), INT8_C( -45), INT8_C(  78),
                           INT8_C( 119), INT8_C( -18), INT8_C(  38), INT8_C(-111)) },
    { simde_mm256_set_epi8(INT8_C( -29), INT8_C(-121), INT8_C( -23), INT8_C(  64),
                           INT8_C(  12), INT8_C(   5), INT8_C(  73), INT8_C(  52),
                           INT8_C( -53), INT8_C(  62), INT8_C(   8), INT8_C(-112),
                           INT8_C(  -8), INT8_C(  99), INT8_C( -12), INT8_C(-118),
                           INT8_C( -33), INT8_C( -37), INT8_C( -98), INT8_C( -94),
                           INT8_C(-119), INT8_C(  79), INT8_C( -25), INT8_C(  47),
                           INT8_C(  80), INT8_C(  89), INT8_C(   5), INT8_C(   9),
                           INT8_C( -36), INT8_C(  79), INT8_C(   8), INT8_C(  89)),
      UINT32_C(1663316267),
      simde_mm256_set_epi8(INT8_C( 103), INT8_C( -43), INT8_C(   6), INT8_C( 112),
                           INT8_C( -45), INT8_C(  82), INT8_C(  16), INT8_C(   3),
                           INT8_C(  34), INT8_C( -45), INT8_C(  75), INT8_C(-106),
                           INT8_C(-107), INT8_C( -45), INT8_C( -85), INT8_C( -53),
                           INT8_C(  11), INT8_C(  28), INT8_C( 126), INT8_C(  24),
                           INT8_C( -69), INT8_C(  35), INT8_C( -37), INT8_C(  95),
                           INT8_C(  85), INT8_C(   3), INT8_C( -77), INT8_C( -35),
                           INT8_C( -83), INT8_C(  -1), INT8_C( -73), INT8_C( -18)),
      simde_mm256_set_epi8(INT8_C( -29), INT8_C( -43), INT8_C(   6), INT8_C(  64),
                           INT8_C(  12), INT8_C(   5), INT8_C(  16), INT8_C(   3),
                           INT8_C( -53), INT8_C(  62), INT8_C(  75), INT8_C(-112),
                           INT8_C(  -8), INT8_C( -45), INT8_C( -12), INT8_C(-118),
                           INT8_C( -33), INT8_C( -37), INT8_C( 126), INT8_C(  24),
                           INT8_C(-119), INT8_C(  79), INT8_C( -25), INT8_C(  95),
                           INT8_C(  80), INT8_C(  89), INT8_C( -77), INT8_C(   9),
                           INT8_C( -83), INT8_C(  79), INT8_C( -73), INT8_C( -18)) },
    { simde_mm256_set_epi8(INT8_C( -15), INT8_C(  22), INT8_C( -61), INT8_C( -49),
                           INT8_C(  -4), INT8_C(  -4), INT8_C(  91), INT8_C( -15),
                           INT8_C(  47), INT8_C( -16), INT8_C(-118), INT8_C(  86),
                           INT8_C( -37), INT8_C( -51), INT8_C(  66), INT8_C( -18),
                           INT8_C( -38), INT8_C( -22), INT8_C(   6), INT8_C(  33),
                           INT8_C( 109), INT8_C(-110), INT8_C( -53), INT8_C(-118),
                           INT8_C(  48), INT8_C( -55), INT8_C(  70), INT8_C(  -1),
                           INT8_C(-125), INT8_C( -38), INT8_C( 109), INT8_C( -62)),
      UINT32_C(1252303865),
      simde_mm256_set_epi8(INT8_C(-103), INT8_C(-118), INT8_C(-127), INT8_C( -69),
                           INT8_C(  28), INT8_C(  82), INT8_C( -48), INT8_C(-119),
                           INT8_C( -31), INT8_C( -65), INT8_C(-127), INT8_C( -41),
                           INT8_C(  86), INT8_C( -70), INT8_C(  -6), INT8_C(  33),
                           INT8_C( -51), INT8_C(-122), INT8_C( -14), INT8_C( 119),
                           INT8_C(  75), INT8_C(  63), INT8_C( -36), INT8_C(  31),
                           INT8_C( -76), INT8_C(  48), INT8_C(  50), INT8_C(-113),
                           INT8_C(  15), INT8_C( -75), INT8_C( -26), INT8_C(  94)),
      simde_mm256_set_epi8(INT8_C( -15), INT8_C(-118), INT8_C( -61), INT8_C( -49),
                           INT8_C(  28), INT8_C(  -4), INT8_C( -48), INT8_C( -15),
                           INT8_C( -31), INT8_C( -16), INT8_C(-127), INT8_C(  86),
                           INT8_C( -37), INT8_C( -70), INT8_C(  66), INT8_C( -18),
                           INT8_C( -51), INT8_C( -22), INT8_C( -14), INT8_C(  33),
                           INT8_C( 109), INT8_C(-110), INT8_C( -36), INT8_C(  31),
                           INT8_C( -76), INT8_C(  48), INT8_C(  50), INT8_C(-113),
                           INT8_C(  15), INT8_C( -38), INT8_C( 109), INT8_C(  94)) },
    { simde_mm256_set_epi8(INT8_C(-106), INT8_C(  63), INT8_C( -91), INT8_C( -65),
                           INT8_C(-114), INT8_C( -79), INT8_C( 118), INT8_C(  65),
                           INT8_C(-123), INT8_C(  42), INT8_C( -51), INT8_C( 112),
                           INT8_C( -55), INT8_C( 120), INT8_C(  62), INT8_C( -91),
                           INT8_C( -74), INT8_C(  98), INT8_C( -26), INT8_C( -13),
                           INT8_C( -94), INT8_C( 105), INT8_C( -49), INT8_C( -31),
                           INT8_C(  18), INT8_C(  49), INT8_C( -11), INT8_C(  72),
                           INT8_C(  -9), INT8_C( -16), INT8_C( 100), INT8_C( -64)),
      UINT32_C( 648334209),
      simde_mm256_set_epi8(INT8_C(   1), INT8_C( -60), INT8_C( -73), INT8_C( -13),
                           INT8_C(  63), INT8_C(-117), INT8_C(-106), INT8_C(  -9),
                           INT8_C( -71), INT8_C(-116), INT8_C( -20), INT8_C(  61),
                           INT8_C(  48), INT8_C(-114), INT8_C(-114), INT8_C( -45),
                           INT8_C( -77), INT8_C( 123), INT8_C(-120), INT8_C(-126),
                           INT8_C( 112), INT8_C( -73), INT8_C( -89), INT8_C(   6),
                           INT8_C(-118), INT8_C(   2), INT8_C( 106), INT8_C( -46),
                           INT8_C( -87), INT8_C(  71), INT8_C( -71), INT8_C(  -5)),
      simde_mm256_set_epi8(INT8_C(-106), INT8_C(  63), INT8_C( -73), INT8_C( -65),
                           INT8_C(-114), INT8_C(-117), INT8_C(-106), INT8_C(  65),
                           INT8_C( -71), INT8_C(  42), INT8_C( -20), INT8_C( 112),
                           INT8_C( -55), INT8_C(-114), INT8_C(  62), INT8_C( -91),
                           INT8_C( -77), INT8_C( 123), INT8_C( -26), INT8_C( -13),
                           INT8_C( 112), INT8_C( 105), INT8_C( -89), INT8_C(   6),
                           INT8_C(-118), INT8_C(  49), INT8_C( -11), INT8_C(  72),
                           INT8_C(  -9), INT8_C( -16), INT8_C( 100), INT8_C(  -5)) },
    { simde_mm256_set_epi8(INT8_C( -48), INT8_C(-113), INT8_C(  21), INT8_C(  68),
                           INT8_C( 115), INT8_C(  93), INT8_C(  99), INT8_C( -68),
                           INT8_C(  -9), INT8_C(  34), INT8_C(  15), INT8_C( 118),
                           INT8_C(  54), INT8_C( -58), INT8_C(  11), INT8_C(  91),
                           INT8_C( 122), INT8_C(  59), INT8_C( 108), INT8_C( -59),
                           INT8_C( -39), INT8_C(  74), INT8_C( -25), INT8_C(   1),
                           INT8_C( -26), INT8_C( -59), INT8_C(  91), INT8_C( -81),
                           INT8_C(  -8), INT8_C(  -5), INT8_C( -55), INT8_C( -59)),
      UINT32_C(2027822108),
      simde_mm256_set_epi8(INT8_C( -93), INT8_C( -25), INT8_C(  14), INT8_C( -22),
                           INT8_C(  85), INT8_C( -47), INT8_C( -59), INT8_C( -81),
                           INT8_C(  94), INT8_C( -67), INT8_C( -69), INT8_C( -79),
                           INT8_C(  61), INT8_C(  49), INT8_C( -27), INT8_C( 124),
                           INT8_C(  89), INT8_C(  80), INT8_C(  55), INT8_C( -47),
                           INT8_C(  45), INT8_C(-120), INT8_C(  28), INT8_C( -89),
                           INT8_C( -69), INT8_C(-127), INT8_C(  65), INT8_C(  53),
                           INT8_C( -35), INT8_C( -30), INT8_C( -74), INT8_C( -10)),
      simde_mm256_set_epi8(INT8_C( -48), INT8_C( -25), INT8_C(  14), INT8_C( -22),
                           INT8_C(  85), INT8_C(  93), INT8_C(  99), INT8_C( -68),
                           INT8_C(  94), INT8_C( -67), INT8_C(  15), INT8_C( -79),
                           INT8_C(  61), INT8_C(  49), INT8_C( -27), INT8_C(  91),
                           INT8_C( 122), INT8_C(  59), INT8_C( 108), INT8_C( -47),
                           INT8_C(  45), INT8_C(-120), INT8_C( -25), INT8_C(   1),
                           INT8_C( -26), INT8_C( -59), INT8_C(  91), INT8_C(  53),
                           INT8_C( -35), INT8_C( -30), INT8_C( -55), INT8_C( -59)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_mask_mov_epi8(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mask_mov_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i src;
    simde__mmask16 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(-23030), INT16_C(  6803), INT16_C(-21055), INT16_C(  -910),
                            INT16_C( -6009), INT16_C( 10471), INT16_C(-29834), INT16_C(-14111),
                            INT16_C( -2981), INT16_C( 28733), INT16_C( 11699), INT16_C(  7781),
                            INT16_C( 29036), INT16_C( -8103), INT16_C(-21310), INT16_C(  9176)),
      UINT16_C(32768),
      simde_mm256_set_epi16(INT16_C( 30563), INT16_C( -5523), INT16_C(-18306), INT16_C( 14754),
                            INT16_C(-23068), INT16_C(-17313), INT16_C( 21598), INT16_C( 12635),
                            INT16_C( 17053), INT16_C(  3377), INT16_C( 28887), INT16_C( 29062),
                            INT16_C( 26146), INT16_C( -4849), INT16_C( 17375), INT16_C(-24515)),
      simde_mm256_set_epi16(INT16_C( 30563), INT16_C(  6803), INT16_C(-21055), INT16_C(  -910),
                            INT16_C( -6009), INT16_C( 10471), INT16_C(-29834), INT16_C(-14111),
                            INT16_C( -2981), INT16_C( 28733), INT16_C( 11699), INT16_C(  7781),
                            INT16_C( 29036), INT16_C( -8103), INT16_C(-21310), INT16_C(  9176)) },
    { simde_mm256_set_epi16(INT16_C(  9971), INT16_C( -9002), INT16_C(-22233), INT16_C(-13917),
                            INT16_C(-13732), INT16_C(  -199), INT16_C(  9707), INT16_C( 31342),
                            INT16_C(-13386), INT16_C(-15675), INT16_C( 10143), INT16_C( 19953),
                            INT16_C(-25473), INT16_C( 27175), INT16_C(-12968), INT16_C(-11899)),
      UINT16_C(15492),
      simde_mm256_set_epi16(INT16_C(-30515), INT16_C(-13927), INT16_C( 24112), INT16_C(  9227),
                            INT16_C(-20054), INT16_C(-11664), INT16_C( -7103), INT16_C(-13246),
                            INT16_C(  4285), INT16_C(-23471), INT16_C( 24470), INT16_C(-13226),
                            INT16_C(  4085), INT16_C( 10000), INT16_C(-17688), INT16_C( 28540)),
      simde_mm256_set_epi16(INT16_C(  9971), INT16_C( -9002), INT16_C( 24112), INT16_C(  9227),
                            INT16_C(-20054), INT16_C(-11664), INT16_C(  9707), INT16_C( 31342),
                            INT16_C(  4285), INT16_C(-15675), INT16_C( 10143), INT16_C( 19953),
                            INT16_C(-25473), INT16_C( 10000), INT16_C(-12968), INT16_C(-11899)) },
    { simde_mm256_set_epi16(INT16_C(-17362), INT16_C( -1830), INT16_C(-16587), INT16_C(-17056),
                            INT16_C(-14539), INT16_C(  7972), INT16_C(-26491), INT16_C( 20406),
                            INT16_C( 26939), INT16_C( 20968), INT16_C(-31196), INT16_C( 11313),
                            INT16_C(-25947), INT16_C( 19467), INT16_C( 22325), INT16_C( 14960)),
      UINT16_C(53867),
      simde_mm256_set_epi16(INT16_C( 15597), INT16_C(-30582), INT16_C(-21551), INT16_C(-25534),
                            INT16_C( 13374), INT16_C( 17137), INT16_C(-27681), INT16_C(-10912),
                            INT16_C(-10124), INT16_C(  1110), INT16_C(  1704), INT16_C(-17853),
                            INT16_C( -7561), INT16_C(-19432), INT16_C( 22127), INT16_C(-30033)),
      simde_mm256_set_epi16(INT16_C( 15597), INT16_C(-30582), INT16_C(-16587), INT16_C(-25534),
                            INT16_C(-14539), INT16_C(  7972), INT16_C(-27681), INT16_C( 20406),
                            INT16_C( 26939), INT16_C(  1110), INT16_C(  1704), INT16_C( 11313),
                            INT16_C( -7561), INT16_C( 19467), INT16_C( 22127), INT16_C(-30033)) },
    { simde_mm256_set_epi16(INT16_C( 14671), INT16_C( 16470), INT16_C( 30174), INT16_C( -7130),
                            INT16_C( 31852), INT16_C( 11282), INT16_C( 29705), INT16_C(-21158),
                            INT16_C( 16917), INT16_C( 10042), INT16_C(  5958), INT16_C( -4695),
                            INT16_C(-20590), INT16_C( 17528), INT16_C( -6738), INT16_C(-26754)),
      UINT16_C(25018),
      simde_mm256_set_epi16(INT16_C(-21192), INT16_C(  6104), INT16_C(-12947), INT16_C( 12440),
                            INT16_C( 12048), INT16_C( -8528), INT16_C(-31627), INT16_C( 26711),
                            INT16_C( -4678), INT16_C( 32013), INT16_C(   814), INT16_C( 19873),
                            INT16_C( 32199), INT16_C( -7421), INT16_C( 21197), INT16_C( 25563)),
      simde_mm256_set_epi16(INT16_C( 14671), INT16_C(  6104), INT16_C(-12947), INT16_C( -7130),
                            INT16_C( 31852), INT16_C( 11282), INT16_C( 29705), INT16_C( 26711),
                            INT16_C( -4678), INT16_C( 10042), INT16_C(   814), INT16_C( 19873),
                            INT16_C( 32199), INT16_C( 17528), INT16_C( 21197), INT16_C(-26754)) },
    { simde_mm256_set_epi16(INT16_C( 30594), INT16_C(-11819), INT16_C( 16854), INT16_C(  8281),
                            INT16_C( 32229), INT16_C( -2511), INT16_C(-10942), INT16_C(-28733),
                            INT16_C( -8714), INT16_C( -6616), INT16_C(  4922), INT16_C(  1537),
                            INT16_C( -8589), INT16_C(  6229), INT16_C(-12142), INT16_C( 12862)),
      UINT16_C(62562),
      simde_mm256_set_epi16(INT16_C( 28902), INT16_C( 31472), INT16_C( -9808), INT16_C(-22935),
                            INT16_C(  4498), INT16_C(-13447), INT16_C(-31030), INT16_C(-31086),
                            INT16_C(  6386), INT16_C(-11676), INT16_C(  9598), INT16_C(-30958),
                            INT16_C(-24145), INT16_C(-18452), INT16_C( -8547), INT16_C(-20619)),
      simde_mm256_set_epi16(INT16_C( 28902), INT16_C( 31472), INT16_C( -9808), INT16_C(-22935),
                            INT16_C( 32229), INT16_C(-13447), INT16_C(-10942), INT16_C(-28733),
                            INT16_C( -8714), INT16_C(-11676), INT16_C(  9598), INT16_C(  1537),
                            INT16_C( -8589), INT16_C(  6229), INT16_C( -8547), INT16_C( 12862)) },
    { simde_mm256_set_epi16(INT16_C( -1185), INT16_C( 28882), INT16_C(-25549), INT16_C(-18169),
                            INT16_C( -7221), INT16_C(  4400), INT16_C(-25724), INT16_C(-28761),
                            INT16_C(-20506), INT16_C(-24341), INT16_C(  5349), INT16_C( -9608),
                            INT16_C(-30698), INT16_C(  7741), INT16_C(  6648), INT16_C(  2085)),
      UINT16_C(40999),
      simde_mm256_set_epi16(INT16_C( 17256), INT16_C(-15790), INT16_C( 23704), INT16_C(-17336),
                            INT16_C( -4418), INT16_C( 28004), INT16_C(-27022), INT16_C( 29950),
                            INT16_C(-28093), INT16_C(   901), INT16_C(-13716), INT16_C(-16668),
                            INT16_C(-12954), INT16_C(  4373), INT16_C( 25556), INT16_C(-31530)),
      simde_mm256_set_epi16(INT16_C( 17256), INT16_C( 28882), INT16_C( 23704), INT16_C(-18169),
                            INT16_C( -7221), INT16_C(  4400), INT16_C(-25724), INT16_C(-28761),
                            INT16_C(-20506), INT16_C(-24341), INT16_C(-13716), INT16_C( -9608),
                            INT16_C(-30698), INT16_C(  4373), INT16_C( 25556), INT16_C(-31530)) },
    { simde_mm256_set_epi16(INT16_C( -2894), INT16_C(-32472), INT16_C( 11220), INT16_C(  6669),
                            INT16_C( 23064), INT16_C(-27024), INT16_C(-15827), INT16_C(-11722),
                            INT16_C(-26431), INT16_C(  6527), INT16_C(-14361), INT16_C(-27595),
                            INT16_C(-18051), INT16_C( -3890), INT16_C(-26121), INT16_C(-29481)),
      UINT16_C( 8894),
      simde_mm256_set_epi16(INT16_C( 18291), INT16_C( 26196), INT16_C(-27505), INT16_C( -8229),
                            INT16_C(-25273), INT16_C( -2374), INT16_C( 25602), INT16_C( 26391),
                            INT16_C( 16833), INT16_C(-18212), INT16_C(  6765), INT16_C( 22695),
                            INT16_C( 31217), INT16_C( 10116), INT16_C( 12733), INT16_C( 11434)),
      simde_mm256_set_epi16(INT16_C( -2894), INT16_C(-32472), INT16_C(-27505), INT16_C(  6669),
                            INT16_C( 23064), INT16_C(-27024), INT16_C( 25602), INT16_C(-11722),
                            INT16_C( 16833), INT16_C(  6527), INT16_C(  6765), INT16_C( 22695),
                            INT16_C( 31217), INT16_C( 10116), INT16_C( 12733), INT16_C(-29481)) },
    { simde_mm256_set_epi16(INT16_C( 31730), INT16_C(-24704), INT16_C( -9707), INT16_C(-27923),
                            INT16_C( 12026), INT16_C( -8313), INT16_C(-30875), INT16_C( -3866),
                            INT16_C( 13477), INT16_C( -8690), INT16_C(  7980), INT16_C( 29046),
                            INT16_C(-16244), INT16_C(-14526), INT16_C( -1470), INT16_C(  9637)),
      UINT16_C(47578),
      simde_mm256_set_epi16(INT16_C(-27085), INT16_C(-21439), INT16_C( -6499), INT16_C(-12213),
                            INT16_C( 32648), INT16_C(-16468), INT16_C(-15892), INT16_C( 21695),
                            INT16_C(-24474), INT16_C(  -770), INT16_C(-22665), INT16_C(-20908),
                            INT16_C(  -267), INT16_C( -8958), INT16_C( -8601), INT16_C( 15369)),
      simde_mm256_set_epi16(INT16_C(-27085), INT16_C(-24704), INT16_C( -6499), INT16_C(-12213),
                            INT16_C( 32648), INT16_C( -8313), INT16_C(-30875), INT16_C( 21695),
                            INT16_C(-24474), INT16_C(  -770), INT16_C(  7980), INT16_C(-20908),
                            INT16_C(  -267), INT16_C(-14526), INT16_C( -8601), INT16_C(  9637)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_mask_mov_epi16(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mask_mov_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i src;
    simde__mmask8 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
      { simde_mm256_set_epi32(INT32_C(-2051902106), INT32_C(-1489562810), INT32_C( -627115156), INT32_C(  913274595),
                            INT32_C(-1198634499), INT32_C(  139959001), INT32_C(-1600412710), INT32_C(  934654383)),
      UINT8_C(164),
      simde_mm256_set_epi32(INT32_C(-2030579644), INT32_C(  386335945), INT32_C( -809785463), INT32_C( 2050465670),
                            INT32_C(  458083110), INT32_C(  911315275), INT32_C(  438060664), INT32_C( 1293777364)),
      simde_mm256_set_epi32(INT32_C(-2030579644), INT32_C(-1489562810), INT32_C( -809785463), INT32_C(  913274595),
                            INT32_C(-1198634499), INT32_C(  911315275), INT32_C(-1600412710), INT32_C(  934654383)) },
    { simde_mm256_set_epi32(INT32_C( 1771679392), INT32_C(  747779042), INT32_C( 1568509396), INT32_C( -126295667),
                            INT32_C( 1160475018), INT32_C(  343988166), INT32_C( 1516295700), INT32_C(-1359069473)),
      UINT8_C(178),
      simde_mm256_set_epi32(INT32_C( 1326620113), INT32_C(-1696986714), INT32_C( -201743610), INT32_C( 1745319425),
                            INT32_C(-1761511775), INT32_C( 1270104738), INT32_C( 1013012890), INT32_C(  875163254)),
      simde_mm256_set_epi32(INT32_C( 1326620113), INT32_C(  747779042), INT32_C( -201743610), INT32_C( 1745319425),
                            INT32_C( 1160475018), INT32_C(  343988166), INT32_C( 1013012890), INT32_C(-1359069473)) },
    { simde_mm256_set_epi32(INT32_C(  518286759), INT32_C(-1532979566), INT32_C(-1858515332), INT32_C(  132974279),
                            INT32_C(  761595911), INT32_C(-1701198420), INT32_C( 1222823321), INT32_C( -238072978)),
      UINT8_C(112),
      simde_mm256_set_epi32(INT32_C( -801582728), INT32_C( 1471437069), INT32_C( 1970067030), INT32_C( 1007722212),
                            INT32_C( -224938211), INT32_C( -282706876), INT32_C( 1478523622), INT32_C(  630801793)),
      simde_mm256_set_epi32(INT32_C(  518286759), INT32_C( 1471437069), INT32_C( 1970067030), INT32_C( 1007722212),
                            INT32_C(  761595911), INT32_C(-1701198420), INT32_C( 1222823321), INT32_C( -238072978)) },
    { simde_mm256_set_epi32(INT32_C(-1331251138), INT32_C(-1232220609), INT32_C(  -83499690), INT32_C(-1933771795),
                            INT32_C( 1431588209), INT32_C(    9145992), INT32_C( 1554181542), INT32_C(-1595697445)),
      UINT8_C(209),
      simde_mm256_set_epi32(INT32_C(-1567962509), INT32_C(-1474212928), INT32_C(-1912431565), INT32_C( -269915367),
                            INT32_C( -487478944), INT32_C(-1785315433), INT32_C(-1130207739), INT32_C( -388075219)),
      simde_mm256_set_epi32(INT32_C(-1567962509), INT32_C(-1474212928), INT32_C(  -83499690), INT32_C( -269915367),
                            INT32_C( 1431588209), INT32_C(    9145992), INT32_C( 1554181542), INT32_C( -388075219)) },
    { simde_mm256_set_epi32(INT32_C( 1834864917), INT32_C( -675288826), INT32_C( 1896194121), INT32_C( 1512557303),
                            INT32_C( -545693873), INT32_C(  513757285), INT32_C( 1710853511), INT32_C(  367108805)),
      UINT8_C(141),
      simde_mm256_set_epi32(INT32_C(-1942300637), INT32_C( 1717002604), INT32_C( -236253831), INT32_C(  993211905),
                            INT32_C(  884769165), INT32_C( 1081163766), INT32_C( 1932456000), INT32_C( -153656708)),
      simde_mm256_set_epi32(INT32_C(-1942300637), INT32_C( -675288826), INT32_C( 1896194121), INT32_C( 1512557303),
                            INT32_C(  884769165), INT32_C( 1081163766), INT32_C( 1710853511), INT32_C( -153656708)) },
    { simde_mm256_set_epi32(INT32_C( 1057245798), INT32_C(-1988238659), INT32_C(  464652738), INT32_C(-1394070870),
                            INT32_C(  410687111), INT32_C(-1023380740), INT32_C(-1345956426), INT32_C( 1062641002)),
      UINT8_C( 23),
      simde_mm256_set_epi32(INT32_C(  804151705), INT32_C(-1030405330), INT32_C(-1199759874), INT32_C( 1385588241),
                            INT32_C(-1001762620), INT32_C( 1644327590), INT32_C( -999008446), INT32_C( 2086723218)),
      simde_mm256_set_epi32(INT32_C( 1057245798), INT32_C(-1988238659), INT32_C(  464652738), INT32_C( 1385588241),
                            INT32_C(  410687111), INT32_C( 1644327590), INT32_C( -999008446), INT32_C( 2086723218)) },
    { simde_mm256_set_epi32(INT32_C( 1481764690), INT32_C(  749562747), INT32_C( 1739109341), INT32_C( 1504825630),
                            INT32_C(-1715949382), INT32_C( -901153926), INT32_C( -433640108), INT32_C( -201965406)),
      UINT8_C( 20),
      simde_mm256_set_epi32(INT32_C(  657000670), INT32_C(   71096321), INT32_C(  324839890), INT32_C( 1620447032),
                            INT32_C( 1126601222), INT32_C(-1962686585), INT32_C(  174027827), INT32_C( 1092631470)),
      simde_mm256_set_epi32(INT32_C( 1481764690), INT32_C(  749562747), INT32_C( 1739109341), INT32_C( 1620447032),
                            INT32_C(-1715949382), INT32_C(-1962686585), INT32_C( -433640108), INT32_C( -201965406)) },
    { simde_mm256_set_epi32(INT32_C( 1112858374), INT32_C( 1689862137), INT32_C(-1548199384), INT32_C(  560346027),
                            INT32_C(-1831151558), INT32_C( 1961484348), INT32_C( 1845841537), INT32_C(-1490051864)),
      UINT8_C( 81),
      simde_mm256_set_epi32(INT32_C( 1782794803), INT32_C(-1212843470), INT32_C(  702145811), INT32_C(  712189474),
                            INT32_C( 1538408527), INT32_C( 1714734347), INT32_C(  509188796), INT32_C( 1218928521)),
      simde_mm256_set_epi32(INT32_C( 1112858374), INT32_C(-1212843470), INT32_C(-1548199384), INT32_C(  712189474),
                            INT32_C(-1831151558), INT32_C( 1961484348), INT32_C( 1845841537), INT32_C( 1218928521)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_mask_mov_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mask_mov_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i src;
    simde__mmask8 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( -211287979567135941), INT64_C(-9075367401252635211),
                             INT64_C(  960243121462097108), INT64_C( 2005878706758239899)),
      UINT8_C( 32),
     simde_mm256_set_epi64x(INT64_C(-6608524325915548957), INT64_C(-1314544444369440805),
                             INT64_C( 1510534294895689397), INT64_C( 1845655456785432498)),
      simde_mm256_set_epi64x(INT64_C( -211287979567135941), INT64_C(-9075367401252635211),
                             INT64_C(  960243121462097108), INT64_C( 2005878706758239899)) },
    { simde_mm256_set_epi64x(INT64_C(-1723084715644559301), INT64_C(-2080563230649448126),
                             INT64_C( 5959215642275768669), INT64_C( 2475827768754845699)),
      UINT8_C(214),
     simde_mm256_set_epi64x(INT64_C( 5190090124690883989), INT64_C(-4089440710650942034),
                             INT64_C(-9158432549634317510), INT64_C( 8190130421956302558)),
      simde_mm256_set_epi64x(INT64_C(-1723084715644559301), INT64_C(-4089440710650942034),
                             INT64_C(-9158432549634317510), INT64_C( 2475827768754845699)) },
    { simde_mm256_set_epi64x(INT64_C(-3369675545100032670), INT64_C(-5453194687323465101),
                             INT64_C(-7873359915838041141), INT64_C(-2715603020778233064)),
      UINT8_C(169),
     simde_mm256_set_epi64x(INT64_C( 6972842025751468465), INT64_C(  -70349858703264913),
                             INT64_C( -274794754558770720), INT64_C(-4632650321932570335)),
      simde_mm256_set_epi64x(INT64_C( 6972842025751468465), INT64_C(-5453194687323465101),
                             INT64_C(-7873359915838041141), INT64_C(-4632650321932570335)) },
    { simde_mm256_set_epi64x(INT64_C( 6027108319237370493), INT64_C(-1242194223738253269),
                             INT64_C(-4627845169201021686), INT64_C( 6845596120956145572)),
      UINT8_C(143),
     simde_mm256_set_epi64x(INT64_C(-3877996964438243656), INT64_C(-4576357011277680458),
                             INT64_C( 6353148636895875717), INT64_C( 4412973294027016788)),
      simde_mm256_set_epi64x(INT64_C(-3877996964438243656), INT64_C(-4576357011277680458),
                             INT64_C( 6353148636895875717), INT64_C( 4412973294027016788)) },
    { simde_mm256_set_epi64x(INT64_C( 9142894596557299884), INT64_C( 8214900458994780454),
                             INT64_C( 8865669120860669544), INT64_C( 8653034493845742246)),
      UINT8_C(226),
     simde_mm256_set_epi64x(INT64_C( 1244643455152445841), INT64_C( 2297609102993095657),
                             INT64_C(-5233775572318758587), INT64_C(-7732116011616278804)),
      simde_mm256_set_epi64x(INT64_C( 9142894596557299884), INT64_C( 8214900458994780454),
                             INT64_C(-5233775572318758587), INT64_C( 8653034493845742246)) },
    { simde_mm256_set_epi64x(INT64_C( 4960786529412164795), INT64_C( 8678743560946050948),
                             INT64_C( 2843182024025655803), INT64_C(  -83887347445242653)),
      UINT8_C( 74),
     simde_mm256_set_epi64x(INT64_C( 3754067458265850846), INT64_C(-6092043402181917138),
                             INT64_C( 1306971064806148347), INT64_C(-5729735109094765451)),
      simde_mm256_set_epi64x(INT64_C( 3754067458265850846), INT64_C( 8678743560946050948),
                             INT64_C( 1306971064806148347), INT64_C(  -83887347445242653)) },
    { simde_mm256_set_epi64x(INT64_C( 2112902535792085455), INT64_C(-6619508989181003755),
                             INT64_C(-7221956771732279605), INT64_C( 6287623589682049686)),
      UINT8_C(191),
     simde_mm256_set_epi64x(INT64_C( 3797901248692596665), INT64_C( 7828643831964461331),
                             INT64_C( 1067056404383166060), INT64_C(-2361551563160303879)),
      simde_mm256_set_epi64x(INT64_C( 3797901248692596665), INT64_C( 7828643831964461331),
                             INT64_C( 1067056404383166060), INT64_C(-2361551563160303879)) },
    { simde_mm256_set_epi64x(INT64_C( 6637695700610981441), INT64_C( 8064523188707259542),
                             INT64_C(-3039387732265680328), INT64_C( 5125314073625570095)),
      UINT8_C(100),
     simde_mm256_set_epi64x(INT64_C( 4453523714429879071), INT64_C(-2274204535440821687),
                             INT64_C(-3167205970195665497), INT64_C( 3325113155733044170)),
      simde_mm256_set_epi64x(INT64_C( 6637695700610981441), INT64_C(-2274204535440821687),
                             INT64_C(-3039387732265680328), INT64_C( 5125314073625570095)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_mask_mov_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mask_mov_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 src;
    simde__mmask8 k;
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -555.53), SIMDE_FLOAT32_C(   800.80),
                         SIMDE_FLOAT32_C(   174.96), SIMDE_FLOAT32_C(    12.40),
                         SIMDE_FLOAT32_C(  -124.14), SIMDE_FLOAT32_C(   378.54),
                         SIMDE_FLOAT32_C(  -864.83), SIMDE_FLOAT32_C(   821.24)),
      UINT8_C(222),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   486.82), SIMDE_FLOAT32_C(   716.60),
                         SIMDE_FLOAT32_C(   497.18), SIMDE_FLOAT32_C(  -260.12),
                         SIMDE_FLOAT32_C(   283.83), SIMDE_FLOAT32_C(   297.46),
                         SIMDE_FLOAT32_C(   984.87), SIMDE_FLOAT32_C(    59.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   486.82), SIMDE_FLOAT32_C(   716.60),
                         SIMDE_FLOAT32_C(   174.96), SIMDE_FLOAT32_C(  -260.12),
                         SIMDE_FLOAT32_C(   283.83), SIMDE_FLOAT32_C(   297.46),
                         SIMDE_FLOAT32_C(   984.87), SIMDE_FLOAT32_C(   821.24)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -111.85), SIMDE_FLOAT32_C(  -140.93),
                         SIMDE_FLOAT32_C(    91.77), SIMDE_FLOAT32_C(   175.59),
                         SIMDE_FLOAT32_C(  -358.15), SIMDE_FLOAT32_C(  -375.20),
                         SIMDE_FLOAT32_C(   580.39), SIMDE_FLOAT32_C(   459.07)),
      UINT8_C(207),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   315.52), SIMDE_FLOAT32_C(  -581.86),
                         SIMDE_FLOAT32_C(   639.05), SIMDE_FLOAT32_C(   298.85),
                         SIMDE_FLOAT32_C(  -373.24), SIMDE_FLOAT32_C(  -178.13),
                         SIMDE_FLOAT32_C(    98.66), SIMDE_FLOAT32_C(  -334.34)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   315.52), SIMDE_FLOAT32_C(  -581.86),
                         SIMDE_FLOAT32_C(    91.77), SIMDE_FLOAT32_C(   175.59),
                         SIMDE_FLOAT32_C(  -373.24), SIMDE_FLOAT32_C(  -178.13),
                         SIMDE_FLOAT32_C(    98.66), SIMDE_FLOAT32_C(  -334.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   869.24), SIMDE_FLOAT32_C(   558.63),
                         SIMDE_FLOAT32_C(   500.11), SIMDE_FLOAT32_C(   448.62),
                         SIMDE_FLOAT32_C(   -66.45), SIMDE_FLOAT32_C(  -429.13),
                         SIMDE_FLOAT32_C(  -688.99), SIMDE_FLOAT32_C(  -828.86)),
      UINT8_C(106),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -209.77), SIMDE_FLOAT32_C(    87.73),
                         SIMDE_FLOAT32_C(   807.71), SIMDE_FLOAT32_C(  -161.53),
                         SIMDE_FLOAT32_C(  -720.29), SIMDE_FLOAT32_C(  -841.34),
                         SIMDE_FLOAT32_C(  -679.61), SIMDE_FLOAT32_C(  -751.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   869.24), SIMDE_FLOAT32_C(    87.73),
                         SIMDE_FLOAT32_C(   807.71), SIMDE_FLOAT32_C(   448.62),
                         SIMDE_FLOAT32_C(  -720.29), SIMDE_FLOAT32_C(  -429.13),
                         SIMDE_FLOAT32_C(  -679.61), SIMDE_FLOAT32_C(  -828.86)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   648.52), SIMDE_FLOAT32_C(  -621.11),
                         SIMDE_FLOAT32_C(    44.58), SIMDE_FLOAT32_C(   173.55),
                         SIMDE_FLOAT32_C(   227.71), SIMDE_FLOAT32_C(  -831.29),
                         SIMDE_FLOAT32_C(   210.07), SIMDE_FLOAT32_C(   469.94)),
      UINT8_C(209),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -457.88), SIMDE_FLOAT32_C(  -345.53),
                         SIMDE_FLOAT32_C(   -52.29), SIMDE_FLOAT32_C(   652.21),
                         SIMDE_FLOAT32_C(   802.89), SIMDE_FLOAT32_C(   706.42),
                         SIMDE_FLOAT32_C(    63.40), SIMDE_FLOAT32_C(   904.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -457.88), SIMDE_FLOAT32_C(  -345.53),
                         SIMDE_FLOAT32_C(    44.58), SIMDE_FLOAT32_C(   652.21),
                         SIMDE_FLOAT32_C(   227.71), SIMDE_FLOAT32_C(  -831.29),
                         SIMDE_FLOAT32_C(   210.07), SIMDE_FLOAT32_C(   904.43)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   592.24), SIMDE_FLOAT32_C(  -735.22),
                         SIMDE_FLOAT32_C(   596.55), SIMDE_FLOAT32_C(  -541.18),
                         SIMDE_FLOAT32_C(  -342.66), SIMDE_FLOAT32_C(    98.60),
                         SIMDE_FLOAT32_C(   188.58), SIMDE_FLOAT32_C(  -720.97)),
      UINT8_C( 39),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -832.08), SIMDE_FLOAT32_C(   690.51),
                         SIMDE_FLOAT32_C(   197.88), SIMDE_FLOAT32_C(  -345.06),
                         SIMDE_FLOAT32_C(  -603.10), SIMDE_FLOAT32_C(   528.02),
                         SIMDE_FLOAT32_C(  -679.70), SIMDE_FLOAT32_C(  -757.75)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   592.24), SIMDE_FLOAT32_C(  -735.22),
                         SIMDE_FLOAT32_C(   197.88), SIMDE_FLOAT32_C(  -541.18),
                         SIMDE_FLOAT32_C(  -342.66), SIMDE_FLOAT32_C(   528.02),
                         SIMDE_FLOAT32_C(  -679.70), SIMDE_FLOAT32_C(  -757.75)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   630.75), SIMDE_FLOAT32_C(  -765.52),
                         SIMDE_FLOAT32_C(   644.64), SIMDE_FLOAT32_C(  -522.11),
                         SIMDE_FLOAT32_C(  -647.87), SIMDE_FLOAT32_C(   408.91),
                         SIMDE_FLOAT32_C(  -874.53), SIMDE_FLOAT32_C(   777.74)),
      UINT8_C( 55),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -382.40), SIMDE_FLOAT32_C(   204.65),
                         SIMDE_FLOAT32_C(   263.52), SIMDE_FLOAT32_C(   553.68),
                         SIMDE_FLOAT32_C(   482.50), SIMDE_FLOAT32_C(  -416.62),
                         SIMDE_FLOAT32_C(   194.15), SIMDE_FLOAT32_C(  -653.83)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   630.75), SIMDE_FLOAT32_C(  -765.52),
                         SIMDE_FLOAT32_C(   263.52), SIMDE_FLOAT32_C(   553.68),
                         SIMDE_FLOAT32_C(  -647.87), SIMDE_FLOAT32_C(  -416.62),
                         SIMDE_FLOAT32_C(   194.15), SIMDE_FLOAT32_C(  -653.83)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -84.63), SIMDE_FLOAT32_C(   440.56),
                         SIMDE_FLOAT32_C(   471.24), SIMDE_FLOAT32_C(   544.90),
                         SIMDE_FLOAT32_C(  -133.99), SIMDE_FLOAT32_C(  -169.40),
                         SIMDE_FLOAT32_C(   397.71), SIMDE_FLOAT32_C(   495.33)),
      UINT8_C(147),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -417.11), SIMDE_FLOAT32_C(  -321.70),
                         SIMDE_FLOAT32_C(   929.20), SIMDE_FLOAT32_C(  -973.32),
                         SIMDE_FLOAT32_C(   120.89), SIMDE_FLOAT32_C(   122.15),
                         SIMDE_FLOAT32_C(   252.56), SIMDE_FLOAT32_C(   335.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -417.11), SIMDE_FLOAT32_C(   440.56),
                         SIMDE_FLOAT32_C(   471.24), SIMDE_FLOAT32_C(  -973.32),
                         SIMDE_FLOAT32_C(  -133.99), SIMDE_FLOAT32_C(  -169.40),
                         SIMDE_FLOAT32_C(   252.56), SIMDE_FLOAT32_C(   335.57)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   637.95), SIMDE_FLOAT32_C(   655.37),
                         SIMDE_FLOAT32_C(   156.29), SIMDE_FLOAT32_C(   -73.51),
                         SIMDE_FLOAT32_C(  -940.14), SIMDE_FLOAT32_C(    79.12),
                         SIMDE_FLOAT32_C(  -920.60), SIMDE_FLOAT32_C(   773.77)),
      UINT8_C(111),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -286.54), SIMDE_FLOAT32_C(  -686.34),
                         SIMDE_FLOAT32_C(   368.35), SIMDE_FLOAT32_C(  -817.20),
                         SIMDE_FLOAT32_C(  -376.39), SIMDE_FLOAT32_C(   454.17),
                         SIMDE_FLOAT32_C(   819.05), SIMDE_FLOAT32_C(   500.81)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   637.95), SIMDE_FLOAT32_C(  -686.34),
                         SIMDE_FLOAT32_C(   368.35), SIMDE_FLOAT32_C(   -73.51),
                         SIMDE_FLOAT32_C(  -376.39), SIMDE_FLOAT32_C(   454.17),
                         SIMDE_FLOAT32_C(   819.05), SIMDE_FLOAT32_C(   500.81)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_mask_mov_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mask_mov_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d src;
    simde__mmask8 k;
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  774.53), SIMDE_FLOAT64_C(  377.61),
                         SIMDE_FLOAT64_C(  717.45), SIMDE_FLOAT64_C(  713.04)),
      UINT8_C( 22),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  723.04), SIMDE_FLOAT64_C(  343.93),
                         SIMDE_FLOAT64_C(  199.28), SIMDE_FLOAT64_C( -711.48)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  774.53), SIMDE_FLOAT64_C(  343.93),
                         SIMDE_FLOAT64_C(  199.28), SIMDE_FLOAT64_C(  713.04)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -510.02), SIMDE_FLOAT64_C(  340.82),
                         SIMDE_FLOAT64_C(  576.36), SIMDE_FLOAT64_C(  -95.74)),
      UINT8_C(255),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  918.58), SIMDE_FLOAT64_C(  109.09),
                         SIMDE_FLOAT64_C( -879.13), SIMDE_FLOAT64_C(  336.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  918.58), SIMDE_FLOAT64_C(  109.09),
                         SIMDE_FLOAT64_C( -879.13), SIMDE_FLOAT64_C(  336.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  409.63), SIMDE_FLOAT64_C( -297.52),
                         SIMDE_FLOAT64_C(  108.73), SIMDE_FLOAT64_C(  228.30)),
      UINT8_C(234),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -549.30), SIMDE_FLOAT64_C( -400.24),
                         SIMDE_FLOAT64_C( -459.77), SIMDE_FLOAT64_C( -392.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -549.30), SIMDE_FLOAT64_C( -297.52),
                         SIMDE_FLOAT64_C( -459.77), SIMDE_FLOAT64_C(  228.30)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -1.67), SIMDE_FLOAT64_C( -827.28),
                         SIMDE_FLOAT64_C(  295.95), SIMDE_FLOAT64_C(  558.58)),
      UINT8_C(192),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  320.94), SIMDE_FLOAT64_C( -669.22),
                         SIMDE_FLOAT64_C(  941.71), SIMDE_FLOAT64_C( -772.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -1.67), SIMDE_FLOAT64_C( -827.28),
                         SIMDE_FLOAT64_C(  295.95), SIMDE_FLOAT64_C(  558.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -393.08), SIMDE_FLOAT64_C(   83.20),
                         SIMDE_FLOAT64_C(  408.44), SIMDE_FLOAT64_C(  326.57)),
      UINT8_C( 97),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -490.95), SIMDE_FLOAT64_C(  526.06),
                         SIMDE_FLOAT64_C( -564.61), SIMDE_FLOAT64_C( -582.24)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -393.08), SIMDE_FLOAT64_C(   83.20),
                         SIMDE_FLOAT64_C(  408.44), SIMDE_FLOAT64_C( -582.24)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -808.43), SIMDE_FLOAT64_C(   58.34),
                         SIMDE_FLOAT64_C( -379.04), SIMDE_FLOAT64_C(   54.10)),
      UINT8_C( 14),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  450.27), SIMDE_FLOAT64_C( -128.64),
                         SIMDE_FLOAT64_C( -995.13), SIMDE_FLOAT64_C(  479.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  450.27), SIMDE_FLOAT64_C( -128.64),
                         SIMDE_FLOAT64_C( -995.13), SIMDE_FLOAT64_C(   54.10)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  322.73), SIMDE_FLOAT64_C(  175.90),
                         SIMDE_FLOAT64_C( -940.90), SIMDE_FLOAT64_C( -692.98)),
      UINT8_C(117),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -758.62), SIMDE_FLOAT64_C(   71.29),
                         SIMDE_FLOAT64_C(  788.39), SIMDE_FLOAT64_C( -310.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  322.73), SIMDE_FLOAT64_C(   71.29),
                         SIMDE_FLOAT64_C( -940.90), SIMDE_FLOAT64_C( -310.18)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -378.45), SIMDE_FLOAT64_C(  288.81),
                         SIMDE_FLOAT64_C(  695.49), SIMDE_FLOAT64_C( -580.49)),
      UINT8_C( 27),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  130.47), SIMDE_FLOAT64_C(  632.45),
                         SIMDE_FLOAT64_C(  808.39), SIMDE_FLOAT64_C(  627.49)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  130.47), SIMDE_FLOAT64_C(  288.81),
                         SIMDE_FLOAT64_C(  808.39), SIMDE_FLOAT64_C(  627.49)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_mask_mov_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskz_mov_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask32 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { UINT32_C(1332074171),
      simde_mm256_set_epi8(INT8_C( 121), INT8_C(  75), INT8_C(  39), INT8_C(-100),
                           INT8_C(  23), INT8_C(  80), INT8_C(  88), INT8_C(  14),
                           INT8_C( -82), INT8_C( -32), INT8_C( -73), INT8_C( -78),
                           INT8_C( -21), INT8_C(  76), INT8_C(  33), INT8_C(  90),
                           INT8_C( -57), INT8_C( -12), INT8_C(-121), INT8_C( 101),
                           INT8_C(   6), INT8_C( -36), INT8_C( -50), INT8_C( -33),
                           INT8_C( -83), INT8_C( -92), INT8_C(   2), INT8_C(  69),
                           INT8_C(  62), INT8_C(  89), INT8_C( 105), INT8_C(  58)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  75), INT8_C(   0), INT8_C(   0),
                           INT8_C(  23), INT8_C(  80), INT8_C(  88), INT8_C(  14),
                           INT8_C(   0), INT8_C( -32), INT8_C( -73), INT8_C(   0),
                           INT8_C(   0), INT8_C(  76), INT8_C(   0), INT8_C(  90),
                           INT8_C( -57), INT8_C( -12), INT8_C(   0), INT8_C( 101),
                           INT8_C(   0), INT8_C( -36), INT8_C( -50), INT8_C(   0),
                           INT8_C( -83), INT8_C(   0), INT8_C(   2), INT8_C(  69),
                           INT8_C(  62), INT8_C(   0), INT8_C( 105), INT8_C(  58)) },
    { UINT32_C(4272165599),
      simde_mm256_set_epi8(INT8_C(  23), INT8_C(   6), INT8_C(  61), INT8_C(  68),
                           INT8_C( -53), INT8_C(-110), INT8_C(  53), INT8_C( -67),
                           INT8_C(  -9), INT8_C( -52), INT8_C(  27), INT8_C( -40),
                           INT8_C(  57), INT8_C( -80), INT8_C( -28), INT8_C(  64),
                           INT8_C(  70), INT8_C( -40), INT8_C(  14), INT8_C( -38),
                           INT8_C( -38), INT8_C( -99), INT8_C( -37), INT8_C( -35),
                           INT8_C( -82), INT8_C( -60), INT8_C( -40), INT8_C( -40),
                           INT8_C(  -5), INT8_C(   8), INT8_C( 109), INT8_C(  95)),
      simde_mm256_set_epi8(INT8_C(  23), INT8_C(   6), INT8_C(  61), INT8_C(  68),
                           INT8_C( -53), INT8_C(-110), INT8_C(  53), INT8_C(   0),
                           INT8_C(  -9), INT8_C(   0), INT8_C(  27), INT8_C(   0),
                           INT8_C(   0), INT8_C( -80), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -38),
                           INT8_C(   0), INT8_C(   0), INT8_C( -37), INT8_C(   0),
                           INT8_C( -82), INT8_C( -60), INT8_C(   0), INT8_C( -40),
                           INT8_C(  -5), INT8_C(   8), INT8_C( 109), INT8_C(  95)) },
    { UINT32_C(3823231310),
      simde_mm256_set_epi8(INT8_C( -42), INT8_C(  44), INT8_C(  70), INT8_C( -24),
                           INT8_C( -86), INT8_C( 112), INT8_C( 116), INT8_C( -61),
                           INT8_C(  94), INT8_C( -56), INT8_C( -83), INT8_C(  37),
                           INT8_C(  45), INT8_C(  44), INT8_C(  79), INT8_C( 122),
                           INT8_C( -54), INT8_C( -68), INT8_C(  19), INT8_C(  39),
                           INT8_C(  17), INT8_C( -32), INT8_C( -47), INT8_C( -26),
                           INT8_C( -23), INT8_C(  30), INT8_C(  98), INT8_C(   3),
                           INT8_C( -92), INT8_C( -30), INT8_C(  -8), INT8_C( -30)),
      simde_mm256_set_epi8(INT8_C( -42), INT8_C(  44), INT8_C(  70), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( 116), INT8_C( -61),
                           INT8_C(  94), INT8_C( -56), INT8_C( -83), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( 122),
                           INT8_C( -54), INT8_C( -68), INT8_C(  19), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -26),
                           INT8_C(   0), INT8_C(  30), INT8_C(   0), INT8_C(   0),
                           INT8_C( -92), INT8_C( -30), INT8_C(  -8), INT8_C(   0)) },
    { UINT32_C(2639652614),
      simde_mm256_set_epi8(INT8_C( -53), INT8_C(  96), INT8_C(  40), INT8_C( -52),
                           INT8_C( -17), INT8_C(  -6), INT8_C(-108), INT8_C(  33),
                           INT8_C( -15), INT8_C( 113), INT8_C(  31), INT8_C( -14),
                           INT8_C( 124), INT8_C(  15), INT8_C(  90), INT8_C(   1),
                           INT8_C(  36), INT8_C(-115), INT8_C( -95), INT8_C(   4),
                           INT8_C(  50), INT8_C( -54), INT8_C(  94), INT8_C(  54),
                           INT8_C( 109), INT8_C(-103), INT8_C(-124), INT8_C(  34),
                           INT8_C( -16), INT8_C(  97), INT8_C(  -7), INT8_C(  98)),
      simde_mm256_set_epi8(INT8_C( -53), INT8_C(   0), INT8_C(   0), INT8_C( -52),
                           INT8_C( -17), INT8_C(  -6), INT8_C(   0), INT8_C(  33),
                           INT8_C(   0), INT8_C( 113), INT8_C(   0), INT8_C( -14),
                           INT8_C(   0), INT8_C(  15), INT8_C(   0), INT8_C(   1),
                           INT8_C(  36), INT8_C(-115), INT8_C( -95), INT8_C(   0),
                           INT8_C(   0), INT8_C( -54), INT8_C(  94), INT8_C(  54),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  97), INT8_C(  -7), INT8_C(   0)) },
    { UINT32_C(2877003463),
      simde_mm256_set_epi8(INT8_C(-108), INT8_C(  14), INT8_C( 103), INT8_C(  32),
                           INT8_C(  25), INT8_C(-108), INT8_C( -56), INT8_C(-111),
                           INT8_C(  23), INT8_C( -20), INT8_C(   4), INT8_C(  81),
                           INT8_C(  39), INT8_C(  39), INT8_C(  82), INT8_C( -15),
                           INT8_C( -87), INT8_C(  90), INT8_C( -91), INT8_C(   3),
                           INT8_C( -91), INT8_C(  55), INT8_C(  72), INT8_C( -46),
                           INT8_C(  48), INT8_C( -19), INT8_C( -87), INT8_C( 100),
                           INT8_C( -44), INT8_C( -79), INT8_C( -72), INT8_C(  73)),
      simde_mm256_set_epi8(INT8_C(-108), INT8_C(   0), INT8_C( 103), INT8_C(   0),
                           INT8_C(  25), INT8_C(   0), INT8_C( -56), INT8_C(-111),
                           INT8_C(   0), INT8_C( -20), INT8_C(   4), INT8_C(  81),
                           INT8_C(  39), INT8_C(   0), INT8_C(  82), INT8_C( -15),
                           INT8_C( -87), INT8_C(   0), INT8_C(   0), INT8_C(   3),
                           INT8_C(   0), INT8_C(  55), INT8_C(  72), INT8_C(   0),
                           INT8_C(  48), INT8_C( -19), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( -79), INT8_C( -72), INT8_C(  73)) },
    { UINT32_C(2869692151),
      simde_mm256_set_epi8(INT8_C(  22), INT8_C(-112), INT8_C(  66), INT8_C( -76),
                           INT8_C(  79), INT8_C(-100), INT8_C( -47), INT8_C(-114),
                           INT8_C( -72), INT8_C(  67), INT8_C(   3), INT8_C(  -9),
                           INT8_C(  88), INT8_C(  -5), INT8_C(-111), INT8_C(-100),
                           INT8_C( -94), INT8_C( -72), INT8_C( -45), INT8_C( -95),
                           INT8_C( 119), INT8_C( -81), INT8_C(  38), INT8_C(-111),
                           INT8_C(  72), INT8_C( -95), INT8_C( 104), INT8_C( -28),
                           INT8_C(  25), INT8_C(  84), INT8_C(  66), INT8_C(  19)),
      simde_mm256_set_epi8(INT8_C(  22), INT8_C(   0), INT8_C(  66), INT8_C(   0),
                           INT8_C(  79), INT8_C(   0), INT8_C( -47), INT8_C(-114),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  88), INT8_C(  -5), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( -81), INT8_C(  38), INT8_C(   0),
                           INT8_C(  72), INT8_C( -95), INT8_C( 104), INT8_C( -28),
                           INT8_C(   0), INT8_C(  84), INT8_C(  66), INT8_C(  19)) },
    { UINT32_C(1633656989),
      simde_mm256_set_epi8(INT8_C(  81), INT8_C( 114), INT8_C( -76), INT8_C( -63),
                           INT8_C(  30), INT8_C(  66), INT8_C(  18), INT8_C(-119),
                           INT8_C(  26), INT8_C(  28), INT8_C(  56), INT8_C( 127),
                           INT8_C( -81), INT8_C(  -7), INT8_C( -20), INT8_C( -35),
                           INT8_C(  -7), INT8_C(  37), INT8_C( -47), INT8_C(  78),
                           INT8_C( 114), INT8_C( -18), INT8_C(  72), INT8_C(  -8),
                           INT8_C(-101), INT8_C( -13), INT8_C(  76), INT8_C(  -5),
                           INT8_C(  -5), INT8_C( -50), INT8_C( -99), INT8_C(  84)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C( 114), INT8_C( -76), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(-119),
                           INT8_C(   0), INT8_C(  28), INT8_C(   0), INT8_C( 127),
                           INT8_C( -81), INT8_C(  -7), INT8_C( -20), INT8_C( -35),
                           INT8_C(  -7), INT8_C(   0), INT8_C( -47), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(-101), INT8_C(   0), INT8_C(   0), INT8_C(  -5),
                           INT8_C(  -5), INT8_C( -50), INT8_C(   0), INT8_C(  84)) },
    { UINT32_C(4185163230),
      simde_mm256_set_epi8(INT8_C( -29), INT8_C(-121), INT8_C( -23), INT8_C(  64),
                           INT8_C(  12), INT8_C(   5), INT8_C(  73), INT8_C(  52),
                           INT8_C( -53), INT8_C(  62), INT8_C(   8), INT8_C(-112),
                           INT8_C(  -8), INT8_C(  99), INT8_C( -12), INT8_C(-118),
                           INT8_C( -33), INT8_C( -37), INT8_C( -98), INT8_C( -94),
                           INT8_C(-119), INT8_C(  79), INT8_C( -25), INT8_C(  47),
                           INT8_C(  80), INT8_C(  89), INT8_C(   5), INT8_C(   9),
                           INT8_C( -36), INT8_C(  79), INT8_C(   8), INT8_C(  89)),
      simde_mm256_set_epi8(INT8_C( -29), INT8_C(-121), INT8_C( -23), INT8_C(  64),
                           INT8_C(  12), INT8_C(   0), INT8_C(   0), INT8_C(  52),
                           INT8_C(   0), INT8_C(  62), INT8_C(   8), INT8_C(-112),
                           INT8_C(   0), INT8_C(  99), INT8_C(   0), INT8_C(   0),
                           INT8_C( -33), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  79), INT8_C(   0), INT8_C(  47),
                           INT8_C(  80), INT8_C(  89), INT8_C(   0), INT8_C(   9),
                           INT8_C( -36), INT8_C(  79), INT8_C(   8), INT8_C(   0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_maskz_mov_epi8(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskz_mov_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { UINT16_C(41021),
      simde_mm256_set_epi16(INT16_C(-23030), INT16_C(  6803), INT16_C(-21055), INT16_C(  -910),
                            INT16_C( -6009), INT16_C( 10471), INT16_C(-29834), INT16_C(-14111),
                            INT16_C( -2981), INT16_C( 28733), INT16_C( 11699), INT16_C(  7781),
                            INT16_C( 29036), INT16_C( -8103), INT16_C(-21310), INT16_C(  9176)),
      simde_mm256_set_epi16(INT16_C(-23030), INT16_C(     0), INT16_C(-21055), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C( 11699), INT16_C(  7781),
                            INT16_C( 29036), INT16_C( -8103), INT16_C(     0), INT16_C(  9176)) },
    { UINT16_C(53637),
      simde_mm256_set_epi16(INT16_C(-17353), INT16_C(-24912), INT16_C(-16017), INT16_C(-32768),
                            INT16_C( 30563), INT16_C( -5523), INT16_C(-18306), INT16_C( 14754),
                            INT16_C(-23068), INT16_C(-17313), INT16_C( 21598), INT16_C( 12635),
                            INT16_C( 17053), INT16_C(  3377), INT16_C( 28887), INT16_C( 29062)),
      simde_mm256_set_epi16(INT16_C(-17353), INT16_C(-24912), INT16_C(     0), INT16_C(-32768),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C( 14754),
                            INT16_C(-23068), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(  3377), INT16_C(     0), INT16_C( 29062)) },
    { UINT16_C(52310),
      simde_mm256_set_epi16(INT16_C(  4085), INT16_C( 10000), INT16_C(-17688), INT16_C( 28540),
                            INT16_C(  9971), INT16_C( -9002), INT16_C(-22233), INT16_C(-13917),
                            INT16_C(-13732), INT16_C(  -199), INT16_C(  9707), INT16_C( 31342),
                            INT16_C(-13386), INT16_C(-15675), INT16_C( 10143), INT16_C( 19953)),
      simde_mm256_set_epi16(INT16_C(  4085), INT16_C( 10000), INT16_C(     0), INT16_C(     0),
                            INT16_C(  9971), INT16_C( -9002), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(  -199), INT16_C(     0), INT16_C( 31342),
                            INT16_C(     0), INT16_C(-15675), INT16_C( 10143), INT16_C(     0)) },
    { UINT16_C(11313),
      simde_mm256_set_epi16(INT16_C(-25947), INT16_C( 19467), INT16_C( 22325), INT16_C( 14960),
                            INT16_C( 16296), INT16_C(-12892), INT16_C(  9434), INT16_C( 15492),
                            INT16_C(-30515), INT16_C(-13927), INT16_C( 24112), INT16_C(  9227),
                            INT16_C(-20054), INT16_C(-11664), INT16_C( -7103), INT16_C(-13246)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C( 22325), INT16_C(     0),
                            INT16_C( 16296), INT16_C(-12892), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C( 24112), INT16_C(  9227),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(-13246)) },
    { UINT16_C(54624),
      simde_mm256_set_epi16(INT16_C(-10124), INT16_C(  1110), INT16_C(  1704), INT16_C(-17853),
                            INT16_C( -7561), INT16_C(-19432), INT16_C( 22127), INT16_C(-30033),
                            INT16_C(-17362), INT16_C( -1830), INT16_C(-16587), INT16_C(-17056),
                            INT16_C(-14539), INT16_C(  7972), INT16_C(-26491), INT16_C( 20406)),
      simde_mm256_set_epi16(INT16_C(-10124), INT16_C(  1110), INT16_C(     0), INT16_C(-17853),
                            INT16_C(     0), INT16_C(-19432), INT16_C(     0), INT16_C(-30033),
                            INT16_C(     0), INT16_C( -1830), INT16_C(-16587), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT16_C(44378),
      simde_mm256_set_epi16(INT16_C( 16917), INT16_C( 10042), INT16_C(  5958), INT16_C( -4695),
                            INT16_C(-20590), INT16_C( 17528), INT16_C( -6738), INT16_C(-26754),
                            INT16_C( 30496), INT16_C(  8574), INT16_C(  3335), INT16_C(-11669),
                            INT16_C( 15597), INT16_C(-30582), INT16_C(-21551), INT16_C(-25534)),
      simde_mm256_set_epi16(INT16_C( 16917), INT16_C(     0), INT16_C(  5958), INT16_C(     0),
                            INT16_C(-20590), INT16_C( 17528), INT16_C(     0), INT16_C(-26754),
                            INT16_C(     0), INT16_C(  8574), INT16_C(     0), INT16_C(-11669),
                            INT16_C( 15597), INT16_C(     0), INT16_C(-21551), INT16_C(     0)) },
    { UINT16_C(12440),
      simde_mm256_set_epi16(INT16_C( 12048), INT16_C( -8528), INT16_C(-31627), INT16_C( 26711),
                            INT16_C( -4678), INT16_C( 32013), INT16_C(   814), INT16_C( 19873),
                            INT16_C( 32199), INT16_C( -7421), INT16_C( 21197), INT16_C( 25563),
                            INT16_C( 14671), INT16_C( 16470), INT16_C( 30174), INT16_C( -7130)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(-31627), INT16_C( 26711),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C( 32199), INT16_C(     0), INT16_C(     0), INT16_C( 25563),
                            INT16_C( 14671), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT16_C( 8281),
      simde_mm256_set_epi16(INT16_C( 32229), INT16_C( -2511), INT16_C(-10942), INT16_C(-28733),
                            INT16_C( -8714), INT16_C( -6616), INT16_C(  4922), INT16_C(  1537),
                            INT16_C( -8589), INT16_C(  6229), INT16_C(-12142), INT16_C( 12862),
                            INT16_C(-16969), INT16_C( 25143), INT16_C(-29570), INT16_C( 25018)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(-10942), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(  6229), INT16_C(     0), INT16_C( 12862),
                            INT16_C(-16969), INT16_C(     0), INT16_C(     0), INT16_C( 25018)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_maskz_mov_epi16(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskz_mov_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
   {  UINT8_C(205),
      simde_mm256_set_epi32(INT32_C( -433311806), INT32_C(  408583050), INT32_C( -306453652), INT32_C( -661693879),
                            INT32_C( 1329919822), INT32_C(  -49396337), INT32_C( -975523137), INT32_C(  228489302)),
      simde_mm256_set_epi32(INT32_C( -433311806), INT32_C(  408583050), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1329919822), INT32_C(  -49396337), INT32_C(          0), INT32_C(  228489302)) },
   {  UINT8_C( 99),
      simde_mm256_set_epi32(INT32_C( 1010695071), INT32_C(  737167817), INT32_C( 1850343310), INT32_C( 1216609214),
                            INT32_C(-1976576002), INT32_C( 1498708626), INT32_C( -621595293), INT32_C(-2111598997)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(  737167817), INT32_C( 1850343310), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C( -621595293), INT32_C(-2111598997)) },
   {  UINT8_C(174),
      simde_mm256_set_epi32(INT32_C( 2023987434), INT32_C( 1558325646), INT32_C( 2137381681), INT32_C(-1489350015),
                            INT32_C(-2044242394), INT32_C(  856733879), INT32_C( 1335704151), INT32_C(-1346912573)),
      simde_mm256_set_epi32(INT32_C( 2023987434), INT32_C(          0), INT32_C( 2137381681), INT32_C(          0),
                            INT32_C(-2044242394), INT32_C(  856733879), INT32_C( 1335704151), INT32_C(          0)) },
   {  UINT8_C(179),
      simde_mm256_set_epi32(INT32_C( 1148504404), INT32_C( -491209584), INT32_C( -163352510), INT32_C(  998745259),
                            INT32_C(-1986870978), INT32_C(  -69159531), INT32_C(-1702010863), INT32_C( -273027352)),
      simde_mm256_set_epi32(INT32_C( 1148504404), INT32_C(          0), INT32_C( -163352510), INT32_C(  998745259),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1702010863), INT32_C( -273027352)) },
   {  UINT8_C(187),
      simde_mm256_set_epi32(INT32_C( -272101695), INT32_C(-1695498890), INT32_C(  700753329), INT32_C(-1444122689),
                            INT32_C(  460626918), INT32_C( 1352716216), INT32_C( -651553055), INT32_C(-1336685992)),
      simde_mm256_set_epi32(INT32_C( -272101695), INT32_C(          0), INT32_C(  700753329), INT32_C(-1444122689),
                            INT32_C(  460626918), INT32_C(          0), INT32_C( -651553055), INT32_C(-1336685992)) },
   {  UINT8_C(119),
      simde_mm256_set_epi32(INT32_C(-1143505851), INT32_C(  669916850), INT32_C( -262251672), INT32_C(  470970928),
                            INT32_C( 1041120150), INT32_C(-1070284133), INT32_C(  347280872), INT32_C( -305201154)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(  669916850), INT32_C( -262251672), INT32_C(  470970928),
                            INT32_C(          0), INT32_C(-1070284133), INT32_C(  347280872), INT32_C( -305201154)) },
   {  UINT8_C( 36),
      simde_mm256_set_epi32(INT32_C( 1927265424), INT32_C(-1184012473), INT32_C( 1473357439), INT32_C( 1217146407),
                            INT32_C( 1884345776), INT32_C( -662443681), INT32_C( -457310112), INT32_C(-2074706314)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C( 1473357439), INT32_C(          0),
                            INT32_C(          0), INT32_C( -662443681), INT32_C(          0), INT32_C(          0)) },
   {  UINT8_C(161),
      simde_mm256_set_epi32(INT32_C(  454256305), INT32_C(  -89518858), INT32_C(  575434377), INT32_C( -363661293),
                            INT32_C( -271203820), INT32_C( -624953581), INT32_C( 1626853978), INT32_C(-1012779406)),
      simde_mm256_set_epi32(INT32_C(  454256305), INT32_C(          0), INT32_C(  575434377), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-1012779406)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_maskz_mov_epi32(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskz_mov_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
  {  UINT8_C(109),
     simde_mm256_set_epi64x(INT64_C( 7572002691338055356), INT64_C(-6931202421771137023),
                             INT64_C(-6376895216110561530), INT64_C(  101010879856088318)),
      simde_mm256_set_epi64x(INT64_C( 7572002691338055356), INT64_C(-6931202421771137023),
                             INT64_C(                   0), INT64_C(  101010879856088318)) },
  {  UINT8_C( 84),
     simde_mm256_set_epi64x(INT64_C( 4863930517396634884), INT64_C( 1339559436234782312),
                             INT64_C(-4687477333083103994), INT64_C( 2317514132307922590)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 1339559436234782312),
                             INT64_C(                   0), INT64_C(                   0)) },
  {  UINT8_C(  4),
     simde_mm256_set_epi64x(INT64_C(-4280812707612271736), INT64_C( 1352195411881071619),
                             INT64_C( 4401292390121558915), INT64_C( 1447000045443016421)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C( 1352195411881071619),
                             INT64_C(                   0), INT64_C(                   0)) },
  {  UINT8_C(243),
     simde_mm256_set_epi64x(INT64_C(-1554191220639548558), INT64_C(-1009828379214636119),
                             INT64_C(   87598411827204486), INT64_C( 8494576712865778531)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(   87598411827204486), INT64_C( 8494576712865778531)) },
  {  UINT8_C(102),
     simde_mm256_set_epi64x(INT64_C(-3199853677394167840), INT64_C(-8026951806327199947),
                             INT64_C( 4533073424512347513), INT64_C( -348644671563309757)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(-8026951806327199947),
                             INT64_C( 4533073424512347513), INT64_C(                   0)) },
  {  UINT8_C( 38),
     simde_mm256_set_epi64x(INT64_C(-8077475266882793195), INT64_C(-1380937485015239307),
                             INT64_C(-3426685195142795196), INT64_C( 4855530362388048180)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(-1380937485015239307),
                             INT64_C(-3426685195142795196), INT64_C(                   0)) },
  {  UINT8_C(232),
     simde_mm256_set_epi64x(INT64_C(-4833519388014243665), INT64_C( 2573974298093740422),
                             INT64_C( 3628954985408843732), INT64_C(-4157981558961121913)),
      simde_mm256_set_epi64x(INT64_C(-4833519388014243665), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)) },
  {  UINT8_C(158),
     simde_mm256_set_epi64x(INT64_C( 8860262502878217231), INT64_C(-7256652440967705311),
                             INT64_C( 8973660985157671450), INT64_C(-1395962117275720873)),
      simde_mm256_set_epi64x(INT64_C( 8860262502878217231), INT64_C(-7256652440967705311),
                             INT64_C( 8973660985157671450), INT64_C(                   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_maskz_mov_epi64(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskz_mov_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { UINT8_C(230),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -916.16), SIMDE_FLOAT32_C(   -17.54),
                         SIMDE_FLOAT32_C(    72.07), SIMDE_FLOAT32_C(   358.38),
                         SIMDE_FLOAT32_C(  -323.81), SIMDE_FLOAT32_C(  -500.50),
                         SIMDE_FLOAT32_C(  -957.58), SIMDE_FLOAT32_C(    95.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -916.16), SIMDE_FLOAT32_C(   -17.54),
                         SIMDE_FLOAT32_C(    72.07), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -500.50),
                         SIMDE_FLOAT32_C(  -957.58), SIMDE_FLOAT32_C(     0.00)) },
    { UINT8_C(248),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   820.20), SIMDE_FLOAT32_C(  -882.62),
                         SIMDE_FLOAT32_C(   245.98), SIMDE_FLOAT32_C(   520.70),
                         SIMDE_FLOAT32_C(   947.17), SIMDE_FLOAT32_C(  -801.95),
                         SIMDE_FLOAT32_C(   523.33), SIMDE_FLOAT32_C(    88.74)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   820.20), SIMDE_FLOAT32_C(  -882.62),
                         SIMDE_FLOAT32_C(   245.98), SIMDE_FLOAT32_C(   520.70),
                         SIMDE_FLOAT32_C(   947.17), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { UINT8_C( 91),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   382.59), SIMDE_FLOAT32_C(  -104.90),
                         SIMDE_FLOAT32_C(   437.21), SIMDE_FLOAT32_C(   669.80),
                         SIMDE_FLOAT32_C(   475.78), SIMDE_FLOAT32_C(   291.58),
                         SIMDE_FLOAT32_C(   932.63), SIMDE_FLOAT32_C(    75.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -104.90),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   669.80),
                         SIMDE_FLOAT32_C(   475.78), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   932.63), SIMDE_FLOAT32_C(    75.72)) },
    { UINT8_C( 28),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   325.29), SIMDE_FLOAT32_C(    66.25),
                         SIMDE_FLOAT32_C(   309.27), SIMDE_FLOAT32_C(    48.25),
                         SIMDE_FLOAT32_C(  -685.79), SIMDE_FLOAT32_C(   793.84),
                         SIMDE_FLOAT32_C(   -42.51), SIMDE_FLOAT32_C(  -431.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    48.25),
                         SIMDE_FLOAT32_C(  -685.79), SIMDE_FLOAT32_C(   793.84),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { UINT8_C( 95),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -193.68), SIMDE_FLOAT32_C(  -614.23),
                         SIMDE_FLOAT32_C(   420.74), SIMDE_FLOAT32_C(   824.23),
                         SIMDE_FLOAT32_C(   818.32), SIMDE_FLOAT32_C(  -457.30),
                         SIMDE_FLOAT32_C(  -144.19), SIMDE_FLOAT32_C(    78.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -614.23),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   824.23),
                         SIMDE_FLOAT32_C(   818.32), SIMDE_FLOAT32_C(  -457.30),
                         SIMDE_FLOAT32_C(  -144.19), SIMDE_FLOAT32_C(    78.38)) },
    { UINT8_C(213),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -960.32), SIMDE_FLOAT32_C(  -433.91),
                         SIMDE_FLOAT32_C(   640.12), SIMDE_FLOAT32_C(   816.31),
                         SIMDE_FLOAT32_C(  -667.16), SIMDE_FLOAT32_C(  -891.50),
                         SIMDE_FLOAT32_C(   639.25), SIMDE_FLOAT32_C(   310.94)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -960.32), SIMDE_FLOAT32_C(  -433.91),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   816.31),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -891.50),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   310.94)) },
    { UINT8_C(210),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    20.36), SIMDE_FLOAT32_C(   -24.88),
                         SIMDE_FLOAT32_C(   118.89), SIMDE_FLOAT32_C(   166.69),
                         SIMDE_FLOAT32_C(   470.98), SIMDE_FLOAT32_C(  -195.06),
                         SIMDE_FLOAT32_C(  -643.26), SIMDE_FLOAT32_C(  -611.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    20.36), SIMDE_FLOAT32_C(   -24.88),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   166.69),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -643.26), SIMDE_FLOAT32_C(     0.00)) },
    { UINT8_C(247),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     3.65), SIMDE_FLOAT32_C(   -38.51),
                         SIMDE_FLOAT32_C(  -896.47), SIMDE_FLOAT32_C(   773.97),
                         SIMDE_FLOAT32_C(  -241.05), SIMDE_FLOAT32_C(  -597.57),
                         SIMDE_FLOAT32_C(   632.97), SIMDE_FLOAT32_C(  -804.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     3.65), SIMDE_FLOAT32_C(   -38.51),
                         SIMDE_FLOAT32_C(  -896.47), SIMDE_FLOAT32_C(   773.97),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -597.57),
                         SIMDE_FLOAT32_C(   632.97), SIMDE_FLOAT32_C(  -804.93)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_maskz_mov_ps(test_vec[i].k, test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskz_mov_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    {  UINT8_C(156),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -797.63), SIMDE_FLOAT64_C(  550.96),
                         SIMDE_FLOAT64_C(  215.70), SIMDE_FLOAT64_C(  -51.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -797.63), SIMDE_FLOAT64_C(  550.96),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(232),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  603.95), SIMDE_FLOAT64_C(   89.69),
                         SIMDE_FLOAT64_C(  726.92), SIMDE_FLOAT64_C(  286.27)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  603.95), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C(  7),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -753.25), SIMDE_FLOAT64_C(  973.27),
                         SIMDE_FLOAT64_C(  154.94), SIMDE_FLOAT64_C(  621.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  973.27),
                         SIMDE_FLOAT64_C(  154.94), SIMDE_FLOAT64_C(  621.42)) },
   {  UINT8_C( 98),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -339.86), SIMDE_FLOAT64_C( -506.40),
                         SIMDE_FLOAT64_C(  409.52), SIMDE_FLOAT64_C(  202.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  409.52), SIMDE_FLOAT64_C(    0.00)) },
   {  UINT8_C( 85),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  205.42), SIMDE_FLOAT64_C( -996.69),
                         SIMDE_FLOAT64_C( -560.92), SIMDE_FLOAT64_C(  347.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -996.69),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  347.34)) },
   {  UINT8_C(149),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  226.47), SIMDE_FLOAT64_C(  459.36),
                         SIMDE_FLOAT64_C(  864.34), SIMDE_FLOAT64_C( -365.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  459.36),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -365.19)) },
   {  UINT8_C( 67),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -158.13), SIMDE_FLOAT64_C( -903.74),
                         SIMDE_FLOAT64_C(  370.86), SIMDE_FLOAT64_C( -800.55)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  370.86), SIMDE_FLOAT64_C( -800.55)) },
   {  UINT8_C(168),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -868.95), SIMDE_FLOAT64_C(  674.80),
                         SIMDE_FLOAT64_C( -866.19), SIMDE_FLOAT64_C( -917.43)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -868.95), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_maskz_mov_pd(test_vec[i].k, test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movm_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m128i r;
  } test_vec[8] = {
    { UINT16_C(62934),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { UINT16_C( 3839),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT16_C(60519),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT16_C(28066),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { UINT16_C( 8975),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT16_C(35700),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { UINT16_C(45525),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1)) },
    { UINT16_C( 9017),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movm_epi8(test_vec[i].k);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movm_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask32 k;
    simde__m256i r;
  } test_vec[8] = {
    { UINT32_C(3131962838),
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { UINT32_C(1926696703),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT32_C(2248141927),
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT32_C(1480879522),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { UINT32_C(1377641231),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT32_C( 395086708),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { UINT32_C(1313583573),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1)) },
    { UINT32_C(2432705337),
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_movm_epi8(test_vec[i].k);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_movm_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask64 k;
    simde__m512i r;
  } test_vec[8] = {
    { UINT64_C( 4739015484227475748),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { UINT64_C( 9729215686767344119),
      simde_mm512_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT64_C(13732001478625865871),
      simde_mm512_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT64_C( 1583258323140482986),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { UINT64_C(11672091627232461942),
      simde_mm512_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { UINT64_C( 2094101018860790606),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { UINT64_C( 4680871035071032016),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { UINT64_C( 4209047041590863189),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_movm_epi8(test_vec[i].k);
    simde_assert_m512i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movm_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m128i r;
  } test_vec[8] = {
    { UINT8_C(216),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT8_C( 89),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { UINT8_C(101),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { UINT8_C( 61),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { UINT8_C(225),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { UINT8_C(231),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1)) },
    { UINT8_C(114),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { UINT8_C(147),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movm_epi16(test_vec[i].k);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movm_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m256i r;
  } test_vec[8] = {
    { UINT16_C( 9176),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT16_C( 7781),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { UINT16_C(51425),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { UINT16_C(64626),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { UINT16_C(41021),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { UINT16_C(29062),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { UINT16_C(12635),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1)) },
    { UINT16_C(14754),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_movm_epi16(test_vec[i].k);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movm_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m128i r;
  } test_vec[8] = {
    { UINT8_C(  8),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { UINT8_C(  9),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(  5),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C( 13),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(  1),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(  7),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { UINT8_C(  2),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { UINT8_C(  3),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movm_epi32(test_vec[i].k);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movm_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m256i r;
  } test_vec[8] = {
    { UINT8_C(216),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { UINT8_C( 89),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(101),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C( 61),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(225),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(231),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { UINT8_C(114),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { UINT8_C(147),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_movm_epi32(test_vec[i].k);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_abs_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mask_abs_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskz_abs_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  return MUNIT_OK;
}

#endif /* defined(SIMDE_X86_avx512vl_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

#if HEDLEY_HAS_WARNING("-Wold-style-cast")
  #pragma clang diagnostic ignored "-Wold-style-cast"
#endif
#if HEDLEY_HAS_WARNING("-Wzero-as-null-pointer-constant")
  #pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_X86_AVX512VL_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsepi16_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtsepi16_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsepi32_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtsepi32_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsepi32_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtsepi32_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsepi64_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtsepi64_epi8),

  SIMDE_TESTS_DEFINE_TEST(mm_mask_mov_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_mask_mov_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_mask_mov_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_mask_mov_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm_maskz_mov_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_maskz_mov_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_maskz_mov_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_maskz_mov_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_maskz_mov_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskz_mov_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskz_mov_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskz_mov_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskz_mov_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskz_mov_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_movm_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_movm_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm512_movm_epi8),

  SIMDE_TESTS_DEFINE_TEST(mm_movm_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_movm_epi16),

  SIMDE_TESTS_DEFINE_TEST(mm_movm_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_movm_epi32),

  SIMDE_TESTS_DEFINE_TEST(mm256_abs_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_abs_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskz_abs_epi64),

#endif /* defined(SIMDE_X86_AVX512vl_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */
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
