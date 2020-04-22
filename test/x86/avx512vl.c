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

#if defined(SIMDE_AVX512VL_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

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

#endif /* defined(SIMDE_avx512vl_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

#if HEDLEY_HAS_WARNING("-Wold-style-cast")
  #pragma clang diagnostic ignored "-Wold-style-cast"
#endif
#if HEDLEY_HAS_WARNING("-Wzero-as-null-pointer-constant")
  #pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_AVX512VL_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsepi16_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtsepi16_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsepi32_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsepi32_epi16),

  SIMDE_TESTS_DEFINE_TEST(mm_mask_mov_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_mask_mov_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_mask_mov_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_mask_mov_epi64),

#endif /* defined(SIMDE_AVX512vl_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */
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
