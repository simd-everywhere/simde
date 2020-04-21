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

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   simde__m256i_private src, a, r;
  //   simde__mmask8 k;

  //   munit_rand_memory(sizeof(src), (uint8_t*) &src);
  //   munit_rand_memory(sizeof(k), (uint8_t*) &k);
  //   munit_rand_memory(sizeof(a), (uint8_t*) &a);
  //   k &= UINT8_C(0xff);

  //   r = simde__m256i_to_private(simde_mm256_mask_mov_epi32(simde__m256i_from_private(src), k, simde__m256i_from_private(a)));

  //   printf("    { simde_mm256_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
  //          "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
  //          src.i32[7], src.i32[6], src.i32[5], src.i32[4], src.i32[3], src.i32[2], src.i32[1], src.i32[0]);
  //   printf("      UINT8_C(%3" PRIu8 "),\n", HEDLEY_STATIC_CAST(uint8_t, k));
  //   printf("      simde_mm256_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
  //          "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
  //          a.i32[7], a.i32[6], a.i32[5], a.i32[4], a.i32[3], a.i32[2], a.i32[1], a.i32[0]);
  //   printf("      simde_mm256_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
  //          "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
  //          r.i32[7], r.i32[6], r.i32[5], r.i32[4], r.i32[3], r.i32[2], r.i32[1], r.i32[0]);
  // }
  // return MUNIT_FAIL;

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

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   simde__m256i_private src, a, r;
  //   simde__mmask8 k;

  //   munit_rand_memory(sizeof(src), (uint8_t*) &src);
  //   munit_rand_memory(sizeof(k), (uint8_t*) &k);
  //   munit_rand_memory(sizeof(a), (uint8_t*) &a);
  //   k &= UINT8_C(0xff);

  //   r = simde__m256i_to_private(simde_mm256_mask_mov_epi64(simde__m256i_from_private(src), k, simde__m256i_from_private(a)));

  //   printf("    { simde_mm256_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
  //          "                             INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
  //          src.i64[3], src.i64[2], src.i64[1], src.i64[0]);
  //   printf("      UINT8_C(%3" PRIu8 "),\n", HEDLEY_STATIC_CAST(uint8_t, k));
  //   printf("     simde_mm256_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
  //          "                             INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
  //          a.i64[3], a.i64[2], a.i64[1], a.i64[0]);
  //   printf("      simde_mm256_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
  //          "                             INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")) },\n",
  //          r.i64[3], r.i64[2], r.i64[1], r.i64[0]);
  // }
  // return MUNIT_FAIL;

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

#endif /* defined(SIMDE_avx512vl_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

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

  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_mask_mov_pd),

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
