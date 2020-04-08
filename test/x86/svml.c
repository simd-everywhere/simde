/* Permission is hereby granted, free of charge, to any person
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
 */

#define SIMDE_TESTS_CURRENT_ISAX svml
#include <test/x86/test-x86-internal.h>
#include <simde/x86/svml.h>

#if defined(SIMDE_SVML_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm_div_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  80), INT8_C(  26), INT8_C( -96), INT8_C(  63),
                        INT8_C(  84), INT8_C(   0), INT8_C(  86), INT8_C( -92),
                        INT8_C(  19), INT8_C(  73), INT8_C(  49), INT8_C(  84),
                        INT8_C(  93), INT8_C( -26), INT8_C(  48), INT8_C( -85)),
      simde_mm_set_epi8(INT8_C(   4), INT8_C(   4), INT8_C(   3), INT8_C(  27),
                        INT8_C(  44), INT8_C(  48), INT8_C(   3), INT8_C(  53),
                        INT8_C(  11), INT8_C(   6), INT8_C(   2), INT8_C(  14),
                        INT8_C(  89), INT8_C(  10), INT8_C(   3), INT8_C(   1)),
      simde_mm_set_epi8(INT8_C(  20), INT8_C(   6), INT8_C( -32), INT8_C(   2),
                        INT8_C(   1), INT8_C(   0), INT8_C(  28), INT8_C(  -1),
                        INT8_C(   1), INT8_C(  12), INT8_C(  24), INT8_C(   6),
                        INT8_C(   1), INT8_C(  -2), INT8_C(  16), INT8_C( -85)) },
    { simde_mm_set_epi8(INT8_C( -53), INT8_C(-123), INT8_C(  83), INT8_C(  82),
                        INT8_C( -17), INT8_C(  32), INT8_C( -32), INT8_C(  68),
                        INT8_C( -20), INT8_C(   5), INT8_C(  -1), INT8_C( -23),
                        INT8_C( 118), INT8_C(-101), INT8_C(  53), INT8_C(   4)),
      simde_mm_set_epi8(INT8_C(   9), INT8_C(   1), INT8_C( -68), INT8_C(   1),
                        INT8_C(   1), INT8_C(   1), INT8_C(  22), INT8_C(  17),
                        INT8_C(   4), INT8_C(   8), INT8_C(   6), INT8_C(  10),
                        INT8_C(  55), INT8_C(   3), INT8_C(  14), INT8_C(  14)),
      simde_mm_set_epi8(INT8_C(  -5), INT8_C(-123), INT8_C(  -1), INT8_C(  82),
                        INT8_C( -17), INT8_C(  32), INT8_C(  -1), INT8_C(   4),
                        INT8_C(  -5), INT8_C(   0), INT8_C(   0), INT8_C(  -2),
                        INT8_C(   2), INT8_C( -33), INT8_C(   3), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( 122), INT8_C( 103), INT8_C(  28), INT8_C(-102),
                        INT8_C( -41), INT8_C(-105), INT8_C( -14), INT8_C(-120),
                        INT8_C( -71), INT8_C(  84), INT8_C(  90), INT8_C(   8),
                        INT8_C(  84), INT8_C( 120), INT8_C( -59), INT8_C(   9)),
      simde_mm_set_epi8(INT8_C(  59), INT8_C( -21), INT8_C(  22), INT8_C(  53),
                        INT8_C(  22), INT8_C(   3), INT8_C(   5), INT8_C(   6),
                        INT8_C(   2), INT8_C(  21), INT8_C(   3), INT8_C(   3),
                        INT8_C(   2), INT8_C(  10), INT8_C(  10), INT8_C(   3)),
      simde_mm_set_epi8(INT8_C(   2), INT8_C(  -4), INT8_C(   1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C( -35), INT8_C(  -2), INT8_C( -20),
                        INT8_C( -35), INT8_C(   4), INT8_C(  30), INT8_C(   2),
                        INT8_C(  42), INT8_C(  12), INT8_C(  -5), INT8_C(   3)) },
    { simde_mm_set_epi8(INT8_C( 121), INT8_C( -15), INT8_C(-123), INT8_C(  80),
                        INT8_C(  43), INT8_C(  58), INT8_C( 119), INT8_C( -49),
                        INT8_C( 107), INT8_C( -94), INT8_C(  51), INT8_C(-118),
                        INT8_C(  68), INT8_C( 112), INT8_C( -56), INT8_C(-103)),
      simde_mm_set_epi8(INT8_C(  44), INT8_C(  13), INT8_C(  14), INT8_C(   8),
                        INT8_C( -24), INT8_C(  77), INT8_C( 118), INT8_C(  21),
                        INT8_C(   1), INT8_C( -34), INT8_C(   2), INT8_C(  29),
                        INT8_C(  14), INT8_C(  53), INT8_C(   1), INT8_C(  54)),
      simde_mm_set_epi8(INT8_C(   2), INT8_C(  -1), INT8_C(  -8), INT8_C(  10),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   1), INT8_C(  -2),
                        INT8_C( 107), INT8_C(   2), INT8_C(  25), INT8_C(  -4),
                        INT8_C(   4), INT8_C(   2), INT8_C( -56), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C( -42), INT8_C(  14), INT8_C(-113), INT8_C(  62),
                        INT8_C( -34), INT8_C( -16), INT8_C(-103), INT8_C(-122),
                        INT8_C(-128), INT8_C( -77), INT8_C( -15), INT8_C( -38),
                        INT8_C(  87), INT8_C( -72), INT8_C(  57), INT8_C( -40)),
      simde_mm_set_epi8(INT8_C(  30), INT8_C( 124), INT8_C( -94), INT8_C(   4),
                        INT8_C(  46), INT8_C(  11), INT8_C(   3), INT8_C( -54),
                        INT8_C(  11), INT8_C(   8), INT8_C(-114), INT8_C(   3),
                        INT8_C(   6), INT8_C(   1), INT8_C(-121), INT8_C(   4)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   1), INT8_C(  15),
                        INT8_C(   0), INT8_C(  -1), INT8_C( -34), INT8_C(   2),
                        INT8_C( -11), INT8_C(  -9), INT8_C(   0), INT8_C( -12),
                        INT8_C(  14), INT8_C( -72), INT8_C(   0), INT8_C( -10)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C( -82), INT8_C(  64), INT8_C( -67),
                        INT8_C(-120), INT8_C(  26), INT8_C(-105), INT8_C(  40),
                        INT8_C(  59), INT8_C( -83), INT8_C(  64), INT8_C( -39),
                        INT8_C(  99), INT8_C( -73), INT8_C( -97), INT8_C(  -1)),
      simde_mm_set_epi8(INT8_C( -27), INT8_C( 114), INT8_C(-109), INT8_C(   8),
                        INT8_C(  12), INT8_C(   4), INT8_C(   2), INT8_C(   2),
                        INT8_C(   3), INT8_C(  11), INT8_C(   3), INT8_C(  11),
                        INT8_C(  82), INT8_C(  14), INT8_C( 120), INT8_C(-107)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -8),
                        INT8_C( -10), INT8_C(   6), INT8_C( -52), INT8_C(  20),
                        INT8_C(  19), INT8_C(  -7), INT8_C(  21), INT8_C(  -3),
                        INT8_C(   1), INT8_C(  -5), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -57), INT8_C(  53), INT8_C( 114), INT8_C( -35),
                        INT8_C( -22), INT8_C( -59), INT8_C(  52), INT8_C( 113),
                        INT8_C(  25), INT8_C(  16), INT8_C(  -8), INT8_C( -67),
                        INT8_C(   7), INT8_C( -33), INT8_C(  51), INT8_C( 118)),
      simde_mm_set_epi8(INT8_C(  14), INT8_C(  15), INT8_C(  24), INT8_C(  83),
                        INT8_C(   4), INT8_C(  45), INT8_C(   4), INT8_C(  34),
                        INT8_C(   9), INT8_C(  19), INT8_C(   4), INT8_C(  11),
                        INT8_C(   8), INT8_C(  14), INT8_C( 102), INT8_C( -88)),
      simde_mm_set_epi8(INT8_C(  -4), INT8_C(   3), INT8_C(   4), INT8_C(   0),
                        INT8_C(  -5), INT8_C(  -1), INT8_C(  13), INT8_C(   3),
                        INT8_C(   2), INT8_C(   0), INT8_C(  -2), INT8_C(  -6),
                        INT8_C(   0), INT8_C(  -2), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C( -69), INT8_C(  57), INT8_C(   3), INT8_C( 127),
                        INT8_C( -28), INT8_C( -47), INT8_C(-127), INT8_C( -14),
                        INT8_C( -28), INT8_C(  68), INT8_C( -27), INT8_C( -44),
                        INT8_C( -16), INT8_C(   1), INT8_C( -44), INT8_C( 112)),
      simde_mm_set_epi8(INT8_C(  57), INT8_C(   1), INT8_C( -43), INT8_C( 103),
                        INT8_C(   4), INT8_C(   1), INT8_C(   2), INT8_C(  96),
                        INT8_C(   9), INT8_C(  57), INT8_C(  54), INT8_C( 105),
                        INT8_C(   1), INT8_C(  31), INT8_C( -85), INT8_C( 104)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  57), INT8_C(   0), INT8_C(   1),
                        INT8_C(  -7), INT8_C( -47), INT8_C( -63), INT8_C(   0),
                        INT8_C(  -3), INT8_C(   1), INT8_C(   0), INT8_C(   0),
                        INT8_C( -16), INT8_C(   0), INT8_C(   0), INT8_C(   1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(  7569), INT16_C(-21774), INT16_C(  5125), INT16_C( 21356),
                         INT16_C(  9222), INT16_C(  7511), INT16_C(-21561), INT16_C( 29102)),
      simde_mm_set_epi16(INT16_C(  6450), INT16_C(    -2), INT16_C(   190), INT16_C(   -44),
                         INT16_C(    -3), INT16_C(    -9), INT16_C(  -911), INT16_C(     3)),
      simde_mm_set_epi16(INT16_C(     1), INT16_C( 10887), INT16_C(    26), INT16_C(  -485),
                         INT16_C( -3074), INT16_C(  -834), INT16_C(    23), INT16_C(  9700)) },
    { simde_mm_set_epi16(INT16_C( 14790), INT16_C(-17845), INT16_C( 12471), INT16_C( 16666),
                         INT16_C( -4541), INT16_C( 18926), INT16_C(  4112), INT16_C( 26905)),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -8), INT16_C(    15), INT16_C(   -16),
                         INT16_C(    -1), INT16_C(   -28), INT16_C( -3387), INT16_C(    -5)),
      simde_mm_set_epi16(INT16_C(-14790), INT16_C(  2230), INT16_C(   831), INT16_C( -1041),
                         INT16_C(  4541), INT16_C(  -675), INT16_C(    -1), INT16_C( -5381)) },
    { simde_mm_set_epi16(INT16_C( 24700), INT16_C( 18820), INT16_C( -6493), INT16_C(-11852),
                         INT16_C(  7293), INT16_C( 18330), INT16_C(-13423), INT16_C( 30834)),
      simde_mm_set_epi16(INT16_C(  9411), INT16_C(    -2), INT16_C(    -2), INT16_C(   -10),
                         INT16_C(   942), INT16_C(  5062), INT16_C(  3712), INT16_C(-24297)),
      simde_mm_set_epi16(INT16_C(     2), INT16_C( -9410), INT16_C(  3246), INT16_C(  1185),
                         INT16_C(     7), INT16_C(     3), INT16_C(    -3), INT16_C(    -1)) },
    { simde_mm_set_epi16(INT16_C( -8188), INT16_C( -5752), INT16_C( -6400), INT16_C(-18754),
                         INT16_C( 26203), INT16_C( 11990), INT16_C( 27655), INT16_C( 30479)),
      simde_mm_set_epi16(INT16_C( -2891), INT16_C(    -9), INT16_C(     1), INT16_C(    24),
                         INT16_C(  1410), INT16_C( -7348), INT16_C(    56), INT16_C(    -8)),
      simde_mm_set_epi16(INT16_C(     2), INT16_C(   639), INT16_C( -6400), INT16_C(  -781),
                         INT16_C(    18), INT16_C(    -1), INT16_C(   493), INT16_C( -3809)) },
    { simde_mm_set_epi16(INT16_C( 27464), INT16_C( 30742), INT16_C(-17463), INT16_C(  5584),
                         INT16_C( 16882), INT16_C(-13221), INT16_C(-30009), INT16_C( 27529)),
      simde_mm_set_epi16(INT16_C(    92), INT16_C(  -245), INT16_C(    87), INT16_C(  2027),
                         INT16_C(  -218), INT16_C(   181), INT16_C(     1), INT16_C(  -448)),
      simde_mm_set_epi16(INT16_C(   298), INT16_C(  -125), INT16_C(  -200), INT16_C(     2),
                         INT16_C(   -77), INT16_C(   -73), INT16_C(-30009), INT16_C(   -61)) },
    { simde_mm_set_epi16(INT16_C(-28312), INT16_C( -6464), INT16_C(  7438), INT16_C(-24771),
                         INT16_C( 27969), INT16_C( 18884), INT16_C( 17235), INT16_C( 31019)),
      simde_mm_set_epi16(INT16_C( -3989), INT16_C(     8), INT16_C(    -1), INT16_C(   -27),
                         INT16_C(    53), INT16_C(   -58), INT16_C(  2274), INT16_C(    -9)),
      simde_mm_set_epi16(INT16_C(     7), INT16_C(  -808), INT16_C( -7438), INT16_C(   917),
                         INT16_C(   527), INT16_C(  -325), INT16_C(     7), INT16_C( -3446)) },
    { simde_mm_set_epi16(INT16_C(-31090), INT16_C( 20346), INT16_C( 14276), INT16_C(-27653),
                         INT16_C( 19203), INT16_C(-24798), INT16_C(-17826), INT16_C( 16379)),
      simde_mm_set_epi16(INT16_C(     3), INT16_C(     8), INT16_C(   -60), INT16_C(    14),
                         INT16_C(  -435), INT16_C(    -1), INT16_C(  -395), INT16_C( -1532)),
      simde_mm_set_epi16(INT16_C(-10363), INT16_C(  2543), INT16_C(  -237), INT16_C( -1975),
                         INT16_C(   -44), INT16_C( 24798), INT16_C(    45), INT16_C(   -10)) },
    { simde_mm_set_epi16(INT16_C( -4012), INT16_C( 17981), INT16_C( 26341), INT16_C(-11451),
                         INT16_C(-22746), INT16_C(-13246), INT16_C( -6273), INT16_C( 15936)),
      simde_mm_set_epi16(INT16_C(    -5), INT16_C(   325), INT16_C(    10), INT16_C( -2018),
                         INT16_C(-26192), INT16_C(   -15), INT16_C(   -29), INT16_C(  2009)),
      simde_mm_set_epi16(INT16_C(   802), INT16_C(    55), INT16_C(  2634), INT16_C(     5),
                         INT16_C(     0), INT16_C(   883), INT16_C(   216), INT16_C(     7)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-2101284579), INT32_C( 1788896628), INT32_C(  742774378), INT32_C( -512831871)),
      simde_mm_set_epi32(INT32_C(       -173), INT32_C(  -20613654), INT32_C(      28772), INT32_C(        118)),
      simde_mm_set_epi32(INT32_C(   12146153), INT32_C(        -86), INT32_C(      25815), INT32_C(   -4346032)) },
    { simde_mm_set_epi32(INT32_C(  505370509), INT32_C( -307733024), INT32_C( -192358019), INT32_C( -299231491)),
      simde_mm_set_epi32(INT32_C(      34268), INT32_C(         -6), INT32_C(       6850), INT32_C(    1214711)),
      simde_mm_set_epi32(INT32_C(      14747), INT32_C(   51288837), INT32_C(     -28081), INT32_C(       -246)) },
    { simde_mm_set_epi32(INT32_C(-1154189768), INT32_C(   94538029), INT32_C(  423884488), INT32_C( 1619435962)),
      simde_mm_set_epi32(INT32_C(       -565), INT32_C(    -128659), INT32_C(        -59), INT32_C( -208397178)),
      simde_mm_set_epi32(INT32_C(    2042813), INT32_C(       -734), INT32_C(   -7184482), INT32_C(         -7)) },
    { simde_mm_set_epi32(INT32_C(-1938127942), INT32_C( -553846699), INT32_C(  685427224), INT32_C(  -86375451)),
      simde_mm_set_epi32(INT32_C( 1223981911), INT32_C(    -108113), INT32_C(          3), INT32_C(      -3698)),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(       5122), INT32_C(  228475741), INT32_C(      23357)) },
    { simde_mm_set_epi32(INT32_C(-1690889220), INT32_C( -667367235), INT32_C( 1220206139), INT32_C(-1217543723)),
      simde_mm_set_epi32(INT32_C(        299), INT32_C(       7724), INT32_C(         -1), INT32_C(  173051558)),
      simde_mm_set_epi32(INT32_C(   -5655147), INT32_C(     -86401), INT32_C(-1220206139), INT32_C(         -7)) },
    { simde_mm_set_epi32(INT32_C(   93323521), INT32_C( 1996592708), INT32_C( 2087305602), INT32_C(   27568495)),
      simde_mm_set_epi32(INT32_C(         -2), INT32_C(   15626723), INT32_C(       1507), INT32_C(       5412)),
      simde_mm_set_epi32(INT32_C(  -46661760), INT32_C(        127), INT32_C(    1385073), INT32_C(       5093)) },
    { simde_mm_set_epi32(INT32_C( 1825211631), INT32_C( 1750705004), INT32_C( 1935103134), INT32_C(-1042289581)),
      simde_mm_set_epi32(INT32_C(     -20153), INT32_C( -109992928), INT32_C(         -4), INT32_C(          3)),
      simde_mm_set_epi32(INT32_C(     -90567), INT32_C(        -15), INT32_C( -483775783), INT32_C( -347429860)) },
    { simde_mm_set_epi32(INT32_C( -836927167), INT32_C(-2031963629), INT32_C( 1244477192), INT32_C(  662038781)),
      simde_mm_set_epi32(INT32_C(       -226), INT32_C(        320), INT32_C(   17085036), INT32_C(       -883)),
      simde_mm_set_epi32(INT32_C(    3703217), INT32_C(   -6349886), INT32_C(         72), INT32_C(    -749760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-8762915026342605517), INT64_C( 6327019035084041530)),
      simde_mm_set_epi64x(INT64_C( 1040172869250133860), INT64_C(         -3393154419)),
      simde_mm_set_epi64x(INT64_C(                  -8), INT64_C(         -1864642233)) },
    { simde_mm_set_epi64x(INT64_C( 7086115847005357544), INT64_C( 7169462887889416879)),
      simde_mm_set_epi64x(INT64_C(             -402272), INT64_C(            -6362438)),
      simde_mm_set_epi64x(INT64_C(     -17615235082246), INT64_C(      -1126842082844)) },
    { simde_mm_set_epi64x(INT64_C( 3227829673356714047), INT64_C( 5122063021698718134)),
      simde_mm_set_epi64x(INT64_C(              290796), INT64_C(             -647054)),
      simde_mm_set_epi64x(INT64_C(      11099979619240), INT64_C(      -7915974588981)) },
    { simde_mm_set_epi64x(INT64_C( -712959233727550094), INT64_C( 8175697730423622547)),
      simde_mm_set_epi64x(INT64_C(          -114108996), INT64_C(           727492806)),
      simde_mm_set_epi64x(INT64_C(          6248054568), INT64_C(         11238183612)) },
    { simde_mm_set_epi64x(INT64_C( 7475816922473172733), INT64_C(-1631503293395556188)),
      simde_mm_set_epi64x(INT64_C(                   5), INT64_C(        -24770378177)),
      simde_mm_set_epi64x(INT64_C( 1495163384494634546), INT64_C(            65865094)) },
    { simde_mm_set_epi64x(INT64_C(-7220293124938945390), INT64_C( 5345879758546587877)),
      simde_mm_set_epi64x(INT64_C(                -716), INT64_C(             1692902)),
      simde_mm_set_epi64x(INT64_C(   10084208275054393), INT64_C(       3157819979270)) },
    { simde_mm_set_epi64x(INT64_C(-2100788141468237692), INT64_C( 1869244361192362281)),
      simde_mm_set_epi64x(INT64_C(                  -1), INT64_C(         27867346395)),
      simde_mm_set_epi64x(INT64_C( 2100788141468237692), INT64_C(            67076510)) },
    { simde_mm_set_epi64x(INT64_C(-4218200756000910912), INT64_C( 8429274423139369867)),
      simde_mm_set_epi64x(INT64_C(                  25), INT64_C(        -63869567732)),
      simde_mm_set_epi64x(INT64_C( -168728030240036436), INT64_C(          -131976381)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C( 15), UINT8_C( 75), UINT8_C(224), UINT8_C(156),
                          UINT8_C(  1), UINT8_C( 34), UINT8_C( 35), UINT8_C(127),
                          UINT8_C(127), UINT8_C(120), UINT8_C(177), UINT8_C( 31),
                          UINT8_C(136), UINT8_C(180), UINT8_C(141), UINT8_C(206)),
      simde_x_mm_set_epu8(UINT8_C( 45), UINT8_C(  8), UINT8_C(  9), UINT8_C( 13),
                          UINT8_C(246), UINT8_C(  1), UINT8_C( 15), UINT8_C(  2),
                          UINT8_C(152), UINT8_C( 45), UINT8_C( 56), UINT8_C( 26),
                          UINT8_C(  1), UINT8_C(  1), UINT8_C( 16), UINT8_C( 15)),
      simde_x_mm_set_epu8(UINT8_C(  0), UINT8_C(  9), UINT8_C( 24), UINT8_C( 12),
                          UINT8_C(  0), UINT8_C( 34), UINT8_C(  2), UINT8_C( 63),
                          UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  1),
                          UINT8_C(136), UINT8_C(180), UINT8_C(  8), UINT8_C( 13)) },
    { simde_x_mm_set_epu8(UINT8_C( 75), UINT8_C(233), UINT8_C(186), UINT8_C(216),
                          UINT8_C(224), UINT8_C( 45), UINT8_C( 40), UINT8_C(134),
                          UINT8_C(  1), UINT8_C( 47), UINT8_C( 23), UINT8_C(119),
                          UINT8_C(229), UINT8_C(107), UINT8_C(175), UINT8_C( 79)),
      simde_x_mm_set_epu8(UINT8_C(  9), UINT8_C( 12), UINT8_C( 46), UINT8_C( 39),
                          UINT8_C( 11), UINT8_C( 15), UINT8_C( 32), UINT8_C( 13),
                          UINT8_C( 21), UINT8_C(239), UINT8_C(  5), UINT8_C(  2),
                          UINT8_C(  1), UINT8_C( 26), UINT8_C(182), UINT8_C( 29)),
      simde_x_mm_set_epu8(UINT8_C(  8), UINT8_C( 19), UINT8_C(  4), UINT8_C(  5),
                          UINT8_C( 20), UINT8_C(  3), UINT8_C(  1), UINT8_C( 10),
                          UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C( 59),
                          UINT8_C(229), UINT8_C(  4), UINT8_C(  0), UINT8_C(  2)) },
    { simde_x_mm_set_epu8(UINT8_C( 75), UINT8_C(109), UINT8_C( 28), UINT8_C(204),
                          UINT8_C( 53), UINT8_C(255), UINT8_C(143), UINT8_C(254),
                          UINT8_C( 82), UINT8_C(109), UINT8_C(205), UINT8_C( 21),
                          UINT8_C( 16), UINT8_C( 18), UINT8_C(221), UINT8_C(119)),
      simde_x_mm_set_epu8(UINT8_C(210), UINT8_C(108), UINT8_C( 89), UINT8_C( 21),
                          UINT8_C(154), UINT8_C( 52), UINT8_C( 17), UINT8_C(  8),
                          UINT8_C( 90), UINT8_C(  6), UINT8_C(  1), UINT8_C(  5),
                          UINT8_C(  1), UINT8_C(201), UINT8_C( 23), UINT8_C(  2)),
      simde_x_mm_set_epu8(UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  9),
                          UINT8_C(  0), UINT8_C(  4), UINT8_C(  8), UINT8_C( 31),
                          UINT8_C(  0), UINT8_C( 18), UINT8_C(205), UINT8_C(  4),
                          UINT8_C( 16), UINT8_C(  0), UINT8_C(  9), UINT8_C( 59)) },
    { simde_x_mm_set_epu8(UINT8_C( 23), UINT8_C(229), UINT8_C(200), UINT8_C( 62),
                          UINT8_C(169), UINT8_C(116), UINT8_C(131), UINT8_C(205),
                          UINT8_C(117), UINT8_C( 49), UINT8_C(130), UINT8_C( 21),
                          UINT8_C( 91), UINT8_C(138), UINT8_C(101), UINT8_C(205)),
      simde_x_mm_set_epu8(UINT8_C( 43), UINT8_C( 65), UINT8_C( 28), UINT8_C( 61),
                          UINT8_C( 12), UINT8_C(  4), UINT8_C( 37), UINT8_C(  4),
                          UINT8_C(237), UINT8_C( 25), UINT8_C( 38), UINT8_C( 15),
                          UINT8_C(  9), UINT8_C(  6), UINT8_C(140), UINT8_C( 10)),
      simde_x_mm_set_epu8(UINT8_C(  0), UINT8_C(  3), UINT8_C(  7), UINT8_C(  1),
                          UINT8_C( 14), UINT8_C( 29), UINT8_C(  3), UINT8_C( 51),
                          UINT8_C(  0), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1),
                          UINT8_C( 10), UINT8_C( 23), UINT8_C(  0), UINT8_C( 20)) },
    { simde_x_mm_set_epu8(UINT8_C(140), UINT8_C(170), UINT8_C(150), UINT8_C(208),
                          UINT8_C( 64), UINT8_C(  6), UINT8_C(116), UINT8_C(102),
                          UINT8_C(200), UINT8_C(110), UINT8_C(136), UINT8_C(125),
                          UINT8_C(201), UINT8_C( 22), UINT8_C(166), UINT8_C(235)),
      simde_x_mm_set_epu8(UINT8_C(  1), UINT8_C(  7), UINT8_C( 23), UINT8_C(  2),
                          UINT8_C( 12), UINT8_C(103), UINT8_C( 24), UINT8_C( 18),
                          UINT8_C(234), UINT8_C( 11), UINT8_C(  6), UINT8_C(  2),
                          UINT8_C(  5), UINT8_C( 34), UINT8_C( 60), UINT8_C( 13)),
      simde_x_mm_set_epu8(UINT8_C(140), UINT8_C( 24), UINT8_C(  6), UINT8_C(104),
                          UINT8_C(  5), UINT8_C(  0), UINT8_C(  4), UINT8_C(  5),
                          UINT8_C(  0), UINT8_C( 10), UINT8_C( 22), UINT8_C( 62),
                          UINT8_C( 40), UINT8_C(  0), UINT8_C(  2), UINT8_C( 18)) },
    { simde_x_mm_set_epu8(UINT8_C(143), UINT8_C( 77), UINT8_C(114), UINT8_C( 66),
                          UINT8_C( 82), UINT8_C(133), UINT8_C( 93), UINT8_C(122),
                          UINT8_C(225), UINT8_C(230), UINT8_C(202), UINT8_C(147),
                          UINT8_C(170), UINT8_C(252), UINT8_C(163), UINT8_C(161)),
      simde_x_mm_set_epu8(UINT8_C(  5), UINT8_C(  8), UINT8_C( 15), UINT8_C( 99),
                          UINT8_C( 10), UINT8_C(  4), UINT8_C(  1), UINT8_C(  1),
                          UINT8_C( 15), UINT8_C( 21), UINT8_C(  3), UINT8_C(  1),
                          UINT8_C(  2), UINT8_C( 18), UINT8_C( 18), UINT8_C(  2)),
      simde_x_mm_set_epu8(UINT8_C( 28), UINT8_C(  9), UINT8_C(  7), UINT8_C(  0),
                          UINT8_C(  8), UINT8_C( 33), UINT8_C( 93), UINT8_C(122),
                          UINT8_C( 15), UINT8_C( 10), UINT8_C( 67), UINT8_C(147),
                          UINT8_C( 85), UINT8_C( 14), UINT8_C(  9), UINT8_C( 80)) },
    { simde_x_mm_set_epu8(UINT8_C(125), UINT8_C(134), UINT8_C(114), UINT8_C( 16),
                          UINT8_C(101), UINT8_C( 75), UINT8_C( 71), UINT8_C(136),
                          UINT8_C(137), UINT8_C(104), UINT8_C(249), UINT8_C(115),
                          UINT8_C(110), UINT8_C(132), UINT8_C(229), UINT8_C( 48)),
      simde_x_mm_set_epu8(UINT8_C( 69), UINT8_C( 11), UINT8_C(  3), UINT8_C(  2),
                          UINT8_C(  2), UINT8_C( 21), UINT8_C(  3), UINT8_C(  1),
                          UINT8_C(  5), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2),
                          UINT8_C(  1), UINT8_C(163), UINT8_C(  1), UINT8_C(  2)),
      simde_x_mm_set_epu8(UINT8_C(  1), UINT8_C( 12), UINT8_C( 38), UINT8_C(  8),
                          UINT8_C( 50), UINT8_C(  3), UINT8_C( 23), UINT8_C(136),
                          UINT8_C( 27), UINT8_C(104), UINT8_C( 83), UINT8_C( 57),
                          UINT8_C(110), UINT8_C(  0), UINT8_C(229), UINT8_C( 24)) },
    { simde_x_mm_set_epu8(UINT8_C( 72), UINT8_C(139), UINT8_C(120), UINT8_C(127),
                          UINT8_C(102), UINT8_C(165), UINT8_C( 82), UINT8_C( 63),
                          UINT8_C(192), UINT8_C( 18), UINT8_C(103), UINT8_C(151),
                          UINT8_C( 81), UINT8_C(222), UINT8_C(212), UINT8_C(  1)),
      simde_x_mm_set_epu8(UINT8_C(  7), UINT8_C( 26), UINT8_C( 32), UINT8_C(  1),
                          UINT8_C(  1), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2),
                          UINT8_C( 65), UINT8_C( 24), UINT8_C(  1), UINT8_C( 97),
                          UINT8_C( 14), UINT8_C(  8), UINT8_C( 89), UINT8_C( 11)),
      simde_x_mm_set_epu8(UINT8_C( 10), UINT8_C(  5), UINT8_C(  3), UINT8_C(127),
                          UINT8_C(102), UINT8_C(165), UINT8_C( 27), UINT8_C( 31),
                          UINT8_C(  2), UINT8_C(  0), UINT8_C(103), UINT8_C(  1),
                          UINT8_C(  5), UINT8_C( 27), UINT8_C(  2), UINT8_C(  0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(27566), UINT16_C(40504), UINT16_C( 4629), UINT16_C(53715),
                           UINT16_C( 9716), UINT16_C( 9411), UINT16_C(47476), UINT16_C(41385)),
      simde_x_mm_set_epu16(UINT16_C(   13), UINT16_C( 6506), UINT16_C( 2031), UINT16_C( 2041),
                           UINT16_C(   41), UINT16_C( 3089), UINT16_C( 4707), UINT16_C(    3)),
      simde_x_mm_set_epu16(UINT16_C( 2120), UINT16_C(    6), UINT16_C(    2), UINT16_C(   26),
                           UINT16_C(  236), UINT16_C(    3), UINT16_C(   10), UINT16_C(13795)) },
    { simde_x_mm_set_epu16(UINT16_C( 9353), UINT16_C(  761), UINT16_C( 3256), UINT16_C(15648),
                           UINT16_C(54529), UINT16_C(37909), UINT16_C( 6524), UINT16_C(24806)),
      simde_x_mm_set_epu16(UINT16_C(17088), UINT16_C( 3660), UINT16_C(    3), UINT16_C(    9),
                           UINT16_C(  186), UINT16_C(    2), UINT16_C(    7), UINT16_C( 1856)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C(    0), UINT16_C( 1085), UINT16_C( 1738),
                           UINT16_C(  293), UINT16_C(18954), UINT16_C(  932), UINT16_C(   13)) },
    { simde_x_mm_set_epu16(UINT16_C(19795), UINT16_C(45332), UINT16_C(60579), UINT16_C(32327),
                           UINT16_C(25905), UINT16_C(63671), UINT16_C(  930), UINT16_C(32017)),
      simde_x_mm_set_epu16(UINT16_C(    8), UINT16_C(30488), UINT16_C(   26), UINT16_C( 3397),
                           UINT16_C( 1518), UINT16_C(    2), UINT16_C(   20), UINT16_C(    6)),
      simde_x_mm_set_epu16(UINT16_C( 2474), UINT16_C(    1), UINT16_C( 2329), UINT16_C(    9),
                           UINT16_C(   17), UINT16_C(31835), UINT16_C(   46), UINT16_C( 5336)) },
    { simde_x_mm_set_epu16(UINT16_C(29801), UINT16_C(62435), UINT16_C(31106), UINT16_C(58247),
                           UINT16_C(47275), UINT16_C(34875), UINT16_C(63847), UINT16_C( 8602)),
      simde_x_mm_set_epu16(UINT16_C(    5), UINT16_C(    1), UINT16_C(  842), UINT16_C( 1634),
                           UINT16_C(   11), UINT16_C(   25), UINT16_C( 3640), UINT16_C(  932)),
      simde_x_mm_set_epu16(UINT16_C( 5960), UINT16_C(62435), UINT16_C(   36), UINT16_C(   35),
                           UINT16_C( 4297), UINT16_C( 1395), UINT16_C(   17), UINT16_C(    9)) },
    { simde_x_mm_set_epu16(UINT16_C(41564), UINT16_C(16940), UINT16_C(39647), UINT16_C(59460),
                           UINT16_C(17425), UINT16_C(59711), UINT16_C(30880), UINT16_C(42139)),
      simde_x_mm_set_epu16(UINT16_C(25139), UINT16_C( 3416), UINT16_C(   43), UINT16_C(    6),
                           UINT16_C(    4), UINT16_C( 1256), UINT16_C(   60), UINT16_C(  129)),
      simde_x_mm_set_epu16(UINT16_C(    1), UINT16_C(    4), UINT16_C(  922), UINT16_C( 9910),
                           UINT16_C( 4356), UINT16_C(   47), UINT16_C(  514), UINT16_C(  326)) },
    { simde_x_mm_set_epu16(UINT16_C(39593), UINT16_C(41522), UINT16_C(58894), UINT16_C( 6383),
                           UINT16_C(39956), UINT16_C( 2820), UINT16_C(20260), UINT16_C(57360)),
      simde_x_mm_set_epu16(UINT16_C(    1), UINT16_C(10468), UINT16_C(    2), UINT16_C(   79),
                           UINT16_C(    5), UINT16_C( 1166), UINT16_C(    2), UINT16_C(    3)),
      simde_x_mm_set_epu16(UINT16_C(39593), UINT16_C(    3), UINT16_C(29447), UINT16_C(   80),
                           UINT16_C( 7991), UINT16_C(    2), UINT16_C(10130), UINT16_C(19120)) },
    { simde_x_mm_set_epu16(UINT16_C(58633), UINT16_C(30014), UINT16_C(57061), UINT16_C(60439),
                           UINT16_C(22536), UINT16_C(20868), UINT16_C(20870), UINT16_C(13916)),
      simde_x_mm_set_epu16(UINT16_C(   15), UINT16_C(  490), UINT16_C( 2338), UINT16_C(   64),
                           UINT16_C(  876), UINT16_C(  706), UINT16_C(   65), UINT16_C(  320)),
      simde_x_mm_set_epu16(UINT16_C( 3908), UINT16_C(   61), UINT16_C(   24), UINT16_C(  944),
                           UINT16_C(   25), UINT16_C(   29), UINT16_C(  321), UINT16_C(   43)) },
    { simde_x_mm_set_epu16(UINT16_C( 6697), UINT16_C(21906), UINT16_C(59582), UINT16_C(44845),
                           UINT16_C(35883), UINT16_C(64682), UINT16_C(55100), UINT16_C(57711)),
      simde_x_mm_set_epu16(UINT16_C( 7058), UINT16_C(   10), UINT16_C(60566), UINT16_C(    1),
                           UINT16_C(    1), UINT16_C(  872), UINT16_C(  109), UINT16_C(    1)),
      simde_x_mm_set_epu16(UINT16_C(    0), UINT16_C( 2190), UINT16_C(    0), UINT16_C(44845),
                           UINT16_C(35883), UINT16_C(   74), UINT16_C(  505), UINT16_C(57711)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(3152261024), UINT32_C(2598586578), UINT32_C(1610828679), UINT32_C(3536337768)),
      simde_x_mm_set_epu32(UINT32_C(     14157), UINT32_C(       947), UINT32_C(1043337665), UINT32_C(     97937)),
      simde_x_mm_set_epu32(UINT32_C(    222664), UINT32_C(   2744019), UINT32_C(         1), UINT32_C(     36108)) },
    { simde_x_mm_set_epu32(UINT32_C(  75140339), UINT32_C(1941562012), UINT32_C( 857740081), UINT32_C(1336535286)),
      simde_x_mm_set_epu32(UINT32_C(        22), UINT32_C(      1682), UINT32_C(        11), UINT32_C(         2)),
      simde_x_mm_set_epu32(UINT32_C(   3415469), UINT32_C(   1154317), UINT32_C(  77976371), UINT32_C( 668267643)) },
    { simde_x_mm_set_epu32(UINT32_C( 948661264), UINT32_C(1195769225), UINT32_C( 694120276), UINT32_C(3517239447)),
      simde_x_mm_set_epu32(UINT32_C(      3949), UINT32_C(       275), UINT32_C(  12430067), UINT32_C(     15794)),
      simde_x_mm_set_epu32(UINT32_C(    240228), UINT32_C(   4348251), UINT32_C(        55), UINT32_C(    222694)) },
    { simde_x_mm_set_epu32(UINT32_C(3023938951), UINT32_C(4109050401), UINT32_C( 287757059), UINT32_C(2648669825)),
      simde_x_mm_set_epu32(UINT32_C(     57756), UINT32_C(        40), UINT32_C(1080216164), UINT32_C(    173312)),
      simde_x_mm_set_epu32(UINT32_C(     52357), UINT32_C( 102726260), UINT32_C(         0), UINT32_C(     15282)) },
    { simde_x_mm_set_epu32(UINT32_C( 864299658), UINT32_C(2427378437), UINT32_C( 823539242), UINT32_C(1758563044)),
      simde_x_mm_set_epu32(UINT32_C(       225), UINT32_C(        75), UINT32_C(     11529), UINT32_C( 119418298)),
      simde_x_mm_set_epu32(UINT32_C(   3841331), UINT32_C(  32365045), UINT32_C(     71431), UINT32_C(        14)) },
    { simde_x_mm_set_epu32(UINT32_C(2662820398), UINT32_C(1208068616), UINT32_C(2158211537), UINT32_C(3417661837)),
      simde_x_mm_set_epu32(UINT32_C(      2367), UINT32_C(    126619), UINT32_C(     55203), UINT32_C(       155)),
      simde_x_mm_set_epu32(UINT32_C(   1124976), UINT32_C(      9540), UINT32_C(     39095), UINT32_C(  22049431)) },
    { simde_x_mm_set_epu32(UINT32_C(1097247740), UINT32_C(3448507951), UINT32_C(4106436665), UINT32_C(3017338787)),
      simde_x_mm_set_epu32(UINT32_C(  61963115), UINT32_C( 238397327), UINT32_C(    245318), UINT32_C(   3312135)),
      simde_x_mm_set_epu32(UINT32_C(        17), UINT32_C(        14), UINT32_C(     16739), UINT32_C(       910)) },
    { simde_x_mm_set_epu32(UINT32_C(3006363325), UINT32_C(2983927188), UINT32_C(2177891039), UINT32_C(1117727917)),
      simde_x_mm_set_epu32(UINT32_C(        24), UINT32_C(        12), UINT32_C(1067413818), UINT32_C(       206)),
      simde_x_mm_set_epu32(UINT32_C( 125265138), UINT32_C( 248660599), UINT32_C(         2), UINT32_C(   5425863)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu64x(UINT64_C(14823946846053138543), UINT64_C( 2773213006356142856)),
      simde_x_mm_set_epu64x(UINT64_C(   22806630538915743), UINT64_C(                1295)),
      simde_x_mm_set_epu64x(UINT64_C(                 649), UINT64_C(    2141477224985438)) },
    { simde_x_mm_set_epu64x(UINT64_C(16338394746286416599), UINT64_C( 4395568244008230294)),
      simde_x_mm_set_epu64x(UINT64_C(                1610), UINT64_C(         68247035008)),
      simde_x_mm_set_epu64x(UINT64_C(   10148071270985351), UINT64_C(            64406728)) },
    { simde_x_mm_set_epu64x(UINT64_C( 6431957656146818365), UINT64_C(14710883493083458909)),
      simde_x_mm_set_epu64x(UINT64_C(       2399266305377), UINT64_C(   16092627197291141)),
      simde_x_mm_set_epu64x(UINT64_C(             2680801), UINT64_C(                 914)) },
    { simde_x_mm_set_epu64x(UINT64_C( 7920700281052633117), UINT64_C(15482760419196872328)),
      simde_x_mm_set_epu64x(UINT64_C(         45928957131), UINT64_C(              837231)),
      simde_x_mm_set_epu64x(UINT64_C(           172455478), UINT64_C(      18492817895176)) },
    { simde_x_mm_set_epu64x(UINT64_C(  230158309193392347), UINT64_C(18390356791266391163)),
      simde_x_mm_set_epu64x(UINT64_C(                2253), UINT64_C(       1691141090999)),
      simde_x_mm_set_epu64x(UINT64_C(     102156373365908), UINT64_C(            10874525)) },
    { simde_x_mm_set_epu64x(UINT64_C(12307531484633875995), UINT64_C(16695234188854570094)),
      simde_x_mm_set_epu64x(UINT64_C(           131150029), UINT64_C(  516657134296053652)),
      simde_x_mm_set_epu64x(UINT64_C(         93843147260), UINT64_C(                  32)) },
    { simde_x_mm_set_epu64x(UINT64_C(11764896934406933200), UINT64_C(18439918542668248477)),
      simde_x_mm_set_epu64x(UINT64_C(        306481550847), UINT64_C(  776223621938168297)),
      simde_x_mm_set_epu64x(UINT64_C(            38386966), UINT64_C(                  23)) },
    { simde_x_mm_set_epu64x(UINT64_C(15338454595408931369), UINT64_C(14530768559531423502)),
      simde_x_mm_set_epu64x(UINT64_C(                3408), UINT64_C(                   2)),
      simde_x_mm_set_epu64x(UINT64_C(    4500720245131728), UINT64_C( 7265384279765711751)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_div_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( -27), INT8_C(  46), INT8_C(-122), INT8_C(  87),
                           INT8_C(  34), INT8_C( -53), INT8_C(  64), INT8_C( -70),
                           INT8_C(  25), INT8_C( -17), INT8_C(  56), INT8_C(   3),
                           INT8_C( -75), INT8_C( -17), INT8_C( -12), INT8_C(  60),
                           INT8_C( 100), INT8_C(  -7), INT8_C(-102), INT8_C(  -6),
                           INT8_C( -10), INT8_C(-111), INT8_C( 106), INT8_C( -43),
                           INT8_C( -28), INT8_C( -46), INT8_C(  42), INT8_C( -58),
                           INT8_C(  85), INT8_C( -33), INT8_C(-106), INT8_C(-106)),
      simde_mm256_set_epi8(INT8_C(   1), INT8_C(   4), INT8_C( -31), INT8_C(   6),
                           INT8_C(  13), INT8_C(  15), INT8_C(  20), INT8_C(   3),
                           INT8_C( -77), INT8_C(  32), INT8_C(   5), INT8_C(  55),
                           INT8_C(   5), INT8_C(   1), INT8_C(  16), INT8_C(  49),
                           INT8_C(  43), INT8_C(  83), INT8_C(   5), INT8_C(  16),
                           INT8_C(  34), INT8_C(  20), INT8_C(   2), INT8_C(  13),
                           INT8_C(   8), INT8_C(   2), INT8_C(  90), INT8_C(   2),
                           INT8_C(  23), INT8_C(  12), INT8_C(   2), INT8_C(   5)),
      simde_mm256_set_epi8(INT8_C( -27), INT8_C(  11), INT8_C(   3), INT8_C(  14),
                           INT8_C(   2), INT8_C(  -3), INT8_C(   3), INT8_C( -23),
                           INT8_C(   0), INT8_C(   0), INT8_C(  11), INT8_C(   0),
                           INT8_C( -15), INT8_C( -17), INT8_C(   0), INT8_C(   1),
                           INT8_C(   2), INT8_C(   0), INT8_C( -20), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -5), INT8_C(  53), INT8_C(  -3),
                           INT8_C(  -3), INT8_C( -23), INT8_C(   0), INT8_C( -29),
                           INT8_C(   3), INT8_C(  -2), INT8_C( -53), INT8_C( -21)) },
    { simde_mm256_set_epi8(INT8_C(  64), INT8_C(-114), INT8_C(  66), INT8_C( -73),
                           INT8_C( -80), INT8_C(  97), INT8_C( 103), INT8_C( -46),
                           INT8_C( -83), INT8_C( 104), INT8_C(  22), INT8_C( -39),
                           INT8_C( 114), INT8_C( -82), INT8_C(  83), INT8_C( 122),
                           INT8_C(   1), INT8_C(  51), INT8_C(  75), INT8_C(-100),
                           INT8_C(  17), INT8_C(  37), INT8_C(  53), INT8_C( -57),
                           INT8_C( 121), INT8_C( -35), INT8_C( 108), INT8_C( -68),
                           INT8_C(  25), INT8_C( -78), INT8_C( -54), INT8_C(-104)),
      simde_mm256_set_epi8(INT8_C(  91), INT8_C(  10), INT8_C( -96), INT8_C(  14),
                           INT8_C(  21), INT8_C(  23), INT8_C(   1), INT8_C(   8),
                           INT8_C(   9), INT8_C(   2), INT8_C(   8), INT8_C(  30),
                           INT8_C(   1), INT8_C( -75), INT8_C(  15), INT8_C(   1),
                           INT8_C(  27), INT8_C(   5), INT8_C( 104), INT8_C(  48),
                           INT8_C(  11), INT8_C(   4), INT8_C(  31), INT8_C(   3),
                           INT8_C(  20), INT8_C( 118), INT8_C(   1), INT8_C(  18),
                           INT8_C(   1), INT8_C(  22), INT8_C(  20), INT8_C(  33)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C( -11), INT8_C(   0), INT8_C(  -5),
                           INT8_C(  -3), INT8_C(   4), INT8_C( 103), INT8_C(  -5),
                           INT8_C(  -9), INT8_C(  52), INT8_C(   2), INT8_C(  -1),
                           INT8_C( 114), INT8_C(   1), INT8_C(   5), INT8_C( 122),
                           INT8_C(   0), INT8_C(  10), INT8_C(   0), INT8_C(  -2),
                           INT8_C(   1), INT8_C(   9), INT8_C(   1), INT8_C( -19),
                           INT8_C(   6), INT8_C(   0), INT8_C( 108), INT8_C(  -3),
                           INT8_C(  25), INT8_C(  -3), INT8_C(  -2), INT8_C(  -3)) },
    { simde_mm256_set_epi8(INT8_C( 123), INT8_C(  92), INT8_C( -58), INT8_C(  47),
                           INT8_C(  51), INT8_C(  47), INT8_C(  69), INT8_C(  12),
                           INT8_C(  68), INT8_C( -99), INT8_C(  76), INT8_C(  32),
                           INT8_C(  85), INT8_C( -81), INT8_C(  -3), INT8_C(  -4),
                           INT8_C( -35), INT8_C( -48), INT8_C(  17), INT8_C( -73),
                           INT8_C( 109), INT8_C(  88), INT8_C( -56), INT8_C( -99),
                           INT8_C(-114), INT8_C( 127), INT8_C(  26), INT8_C( -29),
                           INT8_C( -48), INT8_C( -28), INT8_C(  93), INT8_C( -85)),
      simde_mm256_set_epi8(INT8_C(  86), INT8_C(  12), INT8_C(  90), INT8_C(  46),
                           INT8_C(  10), INT8_C(  18), INT8_C(   1), INT8_C(  58),
                           INT8_C( -94), INT8_C(   4), INT8_C(   2), INT8_C(   1),
                           INT8_C(  20), INT8_C(  20), INT8_C(   1), INT8_C(  10),
                           INT8_C(   4), INT8_C(  13), INT8_C(   1), INT8_C(   1),
                           INT8_C(   1), INT8_C(   3), INT8_C(  16), INT8_C(   4),
                           INT8_C(   4), INT8_C(   2), INT8_C(   8), INT8_C( -96),
                           INT8_C(   1), INT8_C(   5), INT8_C( -98), INT8_C(  11)),
      simde_mm256_set_epi8(INT8_C(   1), INT8_C(   7), INT8_C(   0), INT8_C(   1),
                           INT8_C(   5), INT8_C(   2), INT8_C(  69), INT8_C(   0),
                           INT8_C(   0), INT8_C( -24), INT8_C(  38), INT8_C(  32),
                           INT8_C(   4), INT8_C(  -4), INT8_C(  -3), INT8_C(   0),
                           INT8_C(  -8), INT8_C(  -3), INT8_C(  17), INT8_C( -73),
                           INT8_C( 109), INT8_C(  29), INT8_C(  -3), INT8_C( -24),
                           INT8_C( -28), INT8_C(  63), INT8_C(   3), INT8_C(   0),
                           INT8_C( -48), INT8_C(  -5), INT8_C(   0), INT8_C(  -7)) },
    { simde_mm256_set_epi8(INT8_C( -83), INT8_C(   8), INT8_C(  39), INT8_C(  32),
                           INT8_C( -68), INT8_C(   0), INT8_C(  93), INT8_C(   7),
                           INT8_C( -26), INT8_C( -37), INT8_C(   3), INT8_C( -23),
                           INT8_C(  38), INT8_C( -61), INT8_C(  87), INT8_C(  32),
                           INT8_C(  65), INT8_C(  24), INT8_C( -17), INT8_C( -19),
                           INT8_C( 113), INT8_C( -25), INT8_C(  58), INT8_C(   4),
                           INT8_C(-127), INT8_C(  41), INT8_C( -74), INT8_C( 113),
                           INT8_C(  49), INT8_C( -39), INT8_C( -48), INT8_C( 114)),
      simde_mm256_set_epi8(INT8_C(-102), INT8_C(   1), INT8_C(  22), INT8_C(   1),
                           INT8_C(  15), INT8_C(   2), INT8_C(  19), INT8_C(  69),
                           INT8_C(   1), INT8_C(  49), INT8_C(  66), INT8_C(   2),
                           INT8_C(   1), INT8_C(   2), INT8_C(  10), INT8_C(   8),
                           INT8_C(   1), INT8_C(   1), INT8_C(   4), INT8_C(  66),
                           INT8_C(  11), INT8_C(  22), INT8_C(-126), INT8_C(  49),
                           INT8_C(   1), INT8_C(  38), INT8_C(   1), INT8_C(   3),
                           INT8_C(   7), INT8_C(   3), INT8_C(  21), INT8_C(  21)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   8), INT8_C(   1), INT8_C(  32),
                           INT8_C(  -4), INT8_C(   0), INT8_C(   4), INT8_C(   0),
                           INT8_C( -26), INT8_C(   0), INT8_C(   0), INT8_C( -11),
                           INT8_C(  38), INT8_C( -30), INT8_C(   8), INT8_C(   4),
                           INT8_C(  65), INT8_C(  24), INT8_C(  -4), INT8_C(   0),
                           INT8_C(  10), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(-127), INT8_C(   1), INT8_C( -74), INT8_C(  37),
                           INT8_C(   7), INT8_C( -13), INT8_C(  -2), INT8_C(   5)) },
    { simde_mm256_set_epi8(INT8_C(  66), INT8_C( 127), INT8_C(  41), INT8_C(-124),
                           INT8_C( -90), INT8_C(  28), INT8_C(-118), INT8_C(  18),
                           INT8_C(  79), INT8_C(  17), INT8_C( 126), INT8_C( -43),
                           INT8_C( -78), INT8_C(  78), INT8_C(  76), INT8_C(  46),
                           INT8_C(  60), INT8_C(-126), INT8_C( -41), INT8_C( -77),
                           INT8_C( -62), INT8_C(-116), INT8_C(-115), INT8_C(  55),
                           INT8_C(  19), INT8_C( 104), INT8_C(-104), INT8_C( -29),
                           INT8_C(  54), INT8_C(-118), INT8_C( -40), INT8_C( -58)),
      simde_mm256_set_epi8(INT8_C(   3), INT8_C(  53), INT8_C(  28), INT8_C( -96),
                           INT8_C(   1), INT8_C(  91), INT8_C(   7), INT8_C(   1),
                           INT8_C(  29), INT8_C(  30), INT8_C(   1), INT8_C(  10),
                           INT8_C(   1), INT8_C(  36), INT8_C(   7), INT8_C(   1),
                           INT8_C(-101), INT8_C(   5), INT8_C(  13), INT8_C(   5),
                           INT8_C(  85), INT8_C(  11), INT8_C(  34), INT8_C(  48),
                           INT8_C(  17), INT8_C(  42), INT8_C(   3), INT8_C(  87),
                           INT8_C(   1), INT8_C(   2), INT8_C(  74), INT8_C(   8)),
      simde_mm256_set_epi8(INT8_C(  22), INT8_C(   2), INT8_C(   1), INT8_C(   1),
                           INT8_C( -90), INT8_C(   0), INT8_C( -16), INT8_C(  18),
                           INT8_C(   2), INT8_C(   0), INT8_C( 126), INT8_C(  -4),
                           INT8_C( -78), INT8_C(   2), INT8_C(  10), INT8_C(  46),
                           INT8_C(   0), INT8_C( -25), INT8_C(  -3), INT8_C( -15),
                           INT8_C(   0), INT8_C( -10), INT8_C(  -3), INT8_C(   1),
                           INT8_C(   1), INT8_C(   2), INT8_C( -34), INT8_C(   0),
                           INT8_C(  54), INT8_C( -59), INT8_C(   0), INT8_C(  -7)) },
    { simde_mm256_set_epi8(INT8_C(  79), INT8_C( -60), INT8_C( 106), INT8_C( -93),
                           INT8_C(-111), INT8_C( 118), INT8_C( -87), INT8_C( -78),
                           INT8_C( -28), INT8_C( 107), INT8_C( -12), INT8_C( -54),
                           INT8_C( 101), INT8_C( -62), INT8_C(   4), INT8_C( -51),
                           INT8_C( -90), INT8_C(-114), INT8_C(  14), INT8_C( 124),
                           INT8_C( -67), INT8_C(  47), INT8_C(  41), INT8_C(  37),
                           INT8_C( 126), INT8_C( -20), INT8_C( 119), INT8_C( 105),
                           INT8_C( -17), INT8_C(  95), INT8_C( -41), INT8_C(  19)),
      simde_mm256_set_epi8(INT8_C( -34), INT8_C(   4), INT8_C(  32), INT8_C(   1),
                           INT8_C(   4), INT8_C(  10), INT8_C(   7), INT8_C(   5),
                           INT8_C( 120), INT8_C(   1), INT8_C(   1), INT8_C(   1),
                           INT8_C(  26), INT8_C(   6), INT8_C(  44), INT8_C(   2),
                           INT8_C(  55), INT8_C(  14), INT8_C(   4), INT8_C(  41),
                           INT8_C(  41), INT8_C(   6), INT8_C(  10), INT8_C(   7),
                           INT8_C(   7), INT8_C(  21), INT8_C( 126), INT8_C(  59),
                           INT8_C(  13), INT8_C(   8), INT8_C(   2), INT8_C(   6)),
      simde_mm256_set_epi8(INT8_C(  -2), INT8_C( -15), INT8_C(   3), INT8_C( -93),
                           INT8_C( -27), INT8_C(  11), INT8_C( -12), INT8_C( -15),
                           INT8_C(   0), INT8_C( 107), INT8_C( -12), INT8_C( -54),
                           INT8_C(   3), INT8_C( -10), INT8_C(   0), INT8_C( -25),
                           INT8_C(  -1), INT8_C(  -8), INT8_C(   3), INT8_C(   3),
                           INT8_C(  -1), INT8_C(   7), INT8_C(   4), INT8_C(   5),
                           INT8_C(  18), INT8_C(   0), INT8_C(   0), INT8_C(   1),
                           INT8_C(  -1), INT8_C(  11), INT8_C( -20), INT8_C(   3)) },
    { simde_mm256_set_epi8(INT8_C( -48), INT8_C( -29), INT8_C(  23), INT8_C(  39),
                           INT8_C( 106), INT8_C( -37), INT8_C(   1), INT8_C(  62),
                           INT8_C( -21), INT8_C(  -4), INT8_C( -92), INT8_C( -12),
                           INT8_C(  78), INT8_C( -93), INT8_C(  36), INT8_C( -10),
                           INT8_C( -84), INT8_C( 102), INT8_C(   9), INT8_C(  70),
                           INT8_C( -16), INT8_C( -90), INT8_C(  82), INT8_C(-124),
                           INT8_C( -78), INT8_C(  58), INT8_C(  35), INT8_C( 108),
                           INT8_C(-105), INT8_C( -72), INT8_C( -16), INT8_C(-103)),
      simde_mm256_set_epi8(INT8_C(   2), INT8_C(   4), INT8_C(  28), INT8_C( 120),
                           INT8_C(   1), INT8_C(   5), INT8_C(   2), INT8_C(  61),
                           INT8_C(   1), INT8_C(  33), INT8_C( 110), INT8_C(   1),
                           INT8_C( 102), INT8_C(   3), INT8_C(   3), INT8_C(   1),
                           INT8_C(   1), INT8_C(  26), INT8_C(  11), INT8_C(   7),
                           INT8_C(  75), INT8_C(   3), INT8_C(   5), INT8_C(  19),
                           INT8_C(   3), INT8_C( -26), INT8_C(  56), INT8_C(   5),
                           INT8_C(   7), INT8_C(   6), INT8_C(   2), INT8_C(   5)),
      simde_mm256_set_epi8(INT8_C( -24), INT8_C(  -7), INT8_C(   0), INT8_C(   0),
                           INT8_C( 106), INT8_C(  -7), INT8_C(   0), INT8_C(   1),
                           INT8_C( -21), INT8_C(   0), INT8_C(   0), INT8_C( -12),
                           INT8_C(   0), INT8_C( -31), INT8_C(  12), INT8_C( -10),
                           INT8_C( -84), INT8_C(   3), INT8_C(   0), INT8_C(  10),
                           INT8_C(   0), INT8_C( -30), INT8_C(  16), INT8_C(  -6),
                           INT8_C( -26), INT8_C(  -2), INT8_C(   0), INT8_C(  21),
                           INT8_C( -15), INT8_C( -12), INT8_C(  -8), INT8_C( -20)) },
    { simde_mm256_set_epi8(INT8_C( 110), INT8_C(  56), INT8_C(-120), INT8_C( -32),
                           INT8_C( -22), INT8_C(  97), INT8_C( -56), INT8_C(  55),
                           INT8_C( -90), INT8_C(  33), INT8_C(  92), INT8_C(  89),
                           INT8_C(-107), INT8_C(  55), INT8_C( -50), INT8_C( -88),
                           INT8_C(  35), INT8_C(  21), INT8_C(  54), INT8_C(  26),
                           INT8_C(-122), INT8_C( 103), INT8_C(  76), INT8_C(  38),
                           INT8_C(-110), INT8_C(  11), INT8_C(  26), INT8_C( -11),
                           INT8_C(   0), INT8_C(   3), INT8_C(  30), INT8_C(  59)),
      simde_mm256_set_epi8(INT8_C( -31), INT8_C( -83), INT8_C( 101), INT8_C(  17),
                           INT8_C(   8), INT8_C(  15), INT8_C(   2), INT8_C(   7),
                           INT8_C(  37), INT8_C(  84), INT8_C( -52), INT8_C(  25),
                           INT8_C(  42), INT8_C( -27), INT8_C(   1), INT8_C(  10),
                           INT8_C(   7), INT8_C(  37), INT8_C(  54), INT8_C(  31),
                           INT8_C(  54), INT8_C(  62), INT8_C(  11), INT8_C(  54),
                           INT8_C(  43), INT8_C(   1), INT8_C(   4), INT8_C(   5),
                           INT8_C(  93), INT8_C( 124), INT8_C(   2), INT8_C(   3)),
      simde_mm256_set_epi8(INT8_C(  -3), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -2), INT8_C(   6), INT8_C( -28), INT8_C(   7),
                           INT8_C(  -2), INT8_C(   0), INT8_C(  -1), INT8_C(   3),
                           INT8_C(  -2), INT8_C(  -2), INT8_C( -50), INT8_C(  -8),
                           INT8_C(   5), INT8_C(   0), INT8_C(   1), INT8_C(   0),
                           INT8_C(  -2), INT8_C(   1), INT8_C(   6), INT8_C(   0),
                           INT8_C(  -2), INT8_C(  11), INT8_C(   6), INT8_C(  -2),
                           INT8_C(   0), INT8_C(   0), INT8_C(  15), INT8_C(  19)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(-29867), INT16_C(  9314), INT16_C(  7980), INT16_C(  8102),
                            INT16_C(-24663), INT16_C(  4367), INT16_C(-15443), INT16_C( -5657),
                            INT16_C(-20080), INT16_C(-10092), INT16_C(-31734), INT16_C(  6262),
                            INT16_C(  3510), INT16_C(-31811), INT16_C( -4053), INT16_C( -6124)),
      simde_mm256_set_epi16(INT16_C(     1), INT16_C(  1438), INT16_C(    -9), INT16_C(   435),
                            INT16_C(   -11), INT16_C(     2), INT16_C(  -496), INT16_C( 10321),
                            INT16_C( -1000), INT16_C(   -27), INT16_C(    -4), INT16_C(   453),
                            INT16_C(    -2), INT16_C( 19741), INT16_C(  -615), INT16_C( -3265)),
      simde_mm256_set_epi16(INT16_C(-29867), INT16_C(     6), INT16_C(  -886), INT16_C(    18),
                            INT16_C(  2242), INT16_C(  2183), INT16_C(    31), INT16_C(     0),
                            INT16_C(    20), INT16_C(   373), INT16_C(  7933), INT16_C(    13),
                            INT16_C( -1755), INT16_C(    -1), INT16_C(     6), INT16_C(     1)) },
    { simde_mm256_set_epi16(INT16_C( -6800), INT16_C( 13259), INT16_C( -2233), INT16_C(  1354),
                            INT16_C( -8106), INT16_C(-17039), INT16_C(  9504), INT16_C( 22255),
                            INT16_C( 12402), INT16_C( -2677), INT16_C(  4463), INT16_C( 28303),
                            INT16_C(-12322), INT16_C(-19201), INT16_C( 30668), INT16_C( 15284)),
      simde_mm256_set_epi16(INT16_C( 16270), INT16_C(-26534), INT16_C(   -13), INT16_C(   -20),
                            INT16_C(   -12), INT16_C(  -182), INT16_C(   -13), INT16_C(    -2),
                            INT16_C(   399), INT16_C(  -245), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -3), INT16_C(    59), INT16_C(    11), INT16_C( -9799)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(   171), INT16_C(   -67),
                            INT16_C(   675), INT16_C(    93), INT16_C(  -731), INT16_C(-11127),
                            INT16_C(    31), INT16_C(    10), INT16_C( -4463), INT16_C(-28303),
                            INT16_C(  4107), INT16_C(  -325), INT16_C(  2788), INT16_C(    -1)) },
    { simde_mm256_set_epi16(INT16_C( 23535), INT16_C( 10930), INT16_C( 30193), INT16_C( -8194),
                            INT16_C( -8688), INT16_C(  2183), INT16_C(-14596), INT16_C(-28144),
                            INT16_C(-10670), INT16_C(  1107), INT16_C( 31427), INT16_C( -7322),
                            INT16_C( 17038), INT16_C(-32679), INT16_C( 23368), INT16_C(-24524)),
      simde_mm256_set_epi16(INT16_C(    19), INT16_C(  -388), INT16_C(    -1), INT16_C( -2261),
                            INT16_C( -7651), INT16_C(  1639), INT16_C(   -50), INT16_C( -2059),
                            INT16_C(   -25), INT16_C(   -57), INT16_C(  -952), INT16_C(    17),
                            INT16_C( -4528), INT16_C(  -764), INT16_C(  -925), INT16_C(   -20)),
      simde_mm256_set_epi16(INT16_C(  1238), INT16_C(   -28), INT16_C(-30193), INT16_C(     3),
                            INT16_C(     1), INT16_C(     1), INT16_C(   291), INT16_C(    13),
                            INT16_C(   426), INT16_C(   -19), INT16_C(   -33), INT16_C(  -430),
                            INT16_C(    -3), INT16_C(    42), INT16_C(   -25), INT16_C(  1226)) },
    { simde_mm256_set_epi16(INT16_C( 22767), INT16_C( 28543), INT16_C(-30401), INT16_C( 25623),
                            INT16_C(  2206), INT16_C(-16640), INT16_C(-13607), INT16_C(-30899),
                            INT16_C( -2384), INT16_C( -1714), INT16_C( 12691), INT16_C(  9427),
                            INT16_C( 11864), INT16_C( 29526), INT16_C(  8259), INT16_C(  6808)),
      simde_mm256_set_epi16(INT16_C( 15244), INT16_C(     1), INT16_C(    -1), INT16_C(    -3),
                            INT16_C(   -18), INT16_C(   -10), INT16_C(-15299), INT16_C(  -824),
                            INT16_C(  2005), INT16_C(   471), INT16_C(  2069), INT16_C(   204),
                            INT16_C(    25), INT16_C(   -13), INT16_C(    -3), INT16_C(    11)),
      simde_mm256_set_epi16(INT16_C(     1), INT16_C( 28543), INT16_C( 30401), INT16_C( -8541),
                            INT16_C(  -122), INT16_C(  1664), INT16_C(     0), INT16_C(    37),
                            INT16_C(    -1), INT16_C(    -3), INT16_C(     6), INT16_C(    46),
                            INT16_C(   474), INT16_C( -2271), INT16_C( -2753), INT16_C(   618)) },
    { simde_mm256_set_epi16(INT16_C(-16585), INT16_C(-25277), INT16_C( -4139), INT16_C(-27065),
                            INT16_C(-28777), INT16_C( -9487), INT16_C(-18713), INT16_C(-30387),
                            INT16_C(-14811), INT16_C( 24102), INT16_C(-10162), INT16_C(  7921),
                            INT16_C( 29417), INT16_C( 15464), INT16_C( 24785), INT16_C( -1285)),
      simde_mm256_set_epi16(INT16_C(  -121), INT16_C(   328), INT16_C(    10), INT16_C(  -385),
                            INT16_C(    -1), INT16_C(     4), INT16_C(   388), INT16_C(    -1),
                            INT16_C(     1), INT16_C(  4863), INT16_C(  -499), INT16_C(     3),
                            INT16_C(  -226), INT16_C(-15244), INT16_C(     5), INT16_C(    -5)),
      simde_mm256_set_epi16(INT16_C(   137), INT16_C(   -77), INT16_C(  -413), INT16_C(    70),
                            INT16_C( 28777), INT16_C( -2371), INT16_C(   -48), INT16_C( 30387),
                            INT16_C(-14811), INT16_C(     4), INT16_C(    20), INT16_C(  2640),
                            INT16_C(  -130), INT16_C(    -1), INT16_C(  4957), INT16_C(   257)) },
    { simde_mm256_set_epi16(INT16_C( -8831), INT16_C(-12421), INT16_C( 28092), INT16_C(-15215),
                            INT16_C(  5495), INT16_C( 15560), INT16_C(  8747), INT16_C( 22186),
                            INT16_C(-22634), INT16_C(-23262), INT16_C(   360), INT16_C(-18340),
                            INT16_C(-15939), INT16_C(-18429), INT16_C(-10641), INT16_C(-25953)),
      simde_mm256_set_epi16(INT16_C(  6646), INT16_C(  -440), INT16_C(     5), INT16_C(     9),
                            INT16_C(  5230), INT16_C( 14027), INT16_C(  -115), INT16_C(    -1),
                            INT16_C(  -118), INT16_C(  -466), INT16_C(  -288), INT16_C(    -9),
                            INT16_C(   114), INT16_C( -2656), INT16_C( -2539), INT16_C(  1803)),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    28), INT16_C(  5618), INT16_C( -1690),
                            INT16_C(     1), INT16_C(     1), INT16_C(   -76), INT16_C(-22186),
                            INT16_C(   191), INT16_C(    49), INT16_C(    -1), INT16_C(  2037),
                            INT16_C(  -139), INT16_C(     6), INT16_C(     4), INT16_C(   -14)) },
    { simde_mm256_set_epi16(INT16_C(  2118), INT16_C( 26269), INT16_C( 31059), INT16_C( 17912),
                            INT16_C(-28141), INT16_C(  5202), INT16_C( 30957), INT16_C(-32121),
                            INT16_C( -2609), INT16_C(-12316), INT16_C(-10959), INT16_C( 17018),
                            INT16_C(  4376), INT16_C(  1963), INT16_C( 14912), INT16_C(  8031)),
      simde_mm256_set_epi16(INT16_C( -2197), INT16_C(    11), INT16_C(   -18), INT16_C( -3745),
                            INT16_C(    -1), INT16_C(    -3), INT16_C(     4), INT16_C(  3362),
                            INT16_C( -1965), INT16_C(     2), INT16_C(   574), INT16_C(  1347),
                            INT16_C(  -888), INT16_C(   -15), INT16_C(  1260), INT16_C(  -640)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(  2388), INT16_C( -1725), INT16_C(    -4),
                            INT16_C( 28141), INT16_C( -1734), INT16_C(  7739), INT16_C(    -9),
                            INT16_C(     1), INT16_C( -6158), INT16_C(   -19), INT16_C(    12),
                            INT16_C(    -4), INT16_C(  -130), INT16_C(    11), INT16_C(   -12)) },
    { simde_mm256_set_epi16(INT16_C(-28159), INT16_C(  7162), INT16_C(-24830), INT16_C(  4589),
                            INT16_C(  7038), INT16_C(  3178), INT16_C(  4246), INT16_C( -8357),
                            INT16_C( -4695), INT16_C( -9928), INT16_C( -5517), INT16_C(-27023),
                            INT16_C( 18843), INT16_C(   726), INT16_C( 30135), INT16_C( -4871)),
      simde_mm256_set_epi16(INT16_C(   -48), INT16_C(   767), INT16_C(    10), INT16_C(    14),
                            INT16_C( -2039), INT16_C(    -2), INT16_C(   -53), INT16_C(    -1),
                            INT16_C( -1865), INT16_C( -5344), INT16_C(    63), INT16_C(  -505),
                            INT16_C(  2993), INT16_C(-14674), INT16_C(     3), INT16_C(    -2)),
      simde_mm256_set_epi16(INT16_C(   586), INT16_C(     9), INT16_C( -2483), INT16_C(   327),
                            INT16_C(    -3), INT16_C( -1589), INT16_C(   -80), INT16_C(  8357),
                            INT16_C(     2), INT16_C(     1), INT16_C(   -87), INT16_C(    53),
                            INT16_C(     6), INT16_C(     0), INT16_C( 10045), INT16_C(  2435)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1220357195), INT32_C( 1053623553), INT32_C( 1487300768), INT32_C(-1113593972),
                            INT32_C( -270466921), INT32_C( 1339961381), INT32_C(  586340423), INT32_C( 1641199948)),
      simde_mm256_set_epi32(INT32_C(  119685834), INT32_C(         18), INT32_C(   13175516), INT32_C(    2634495),
                            INT32_C(         17), INT32_C(      43789), INT32_C(        -89), INT32_C(         14)),
      simde_mm256_set_epi32(INT32_C(         10), INT32_C(   58534641), INT32_C(        112), INT32_C(       -422),
                            INT32_C(  -15909818), INT32_C(      30600), INT32_C(   -6588094), INT32_C(  117228567)) },
    { simde_mm256_set_epi32(INT32_C( 1446174898), INT32_C( 1812297946), INT32_C(-2020316623), INT32_C(  843765864),
                            INT32_C(-1892632155), INT32_C( -473868741), INT32_C( -150363910), INT32_C(-1673359813)),
      simde_mm256_set_epi32(INT32_C(    2569135), INT32_C(       8168), INT32_C(   -4111977), INT32_C(       -322),
                            INT32_C(  -34091386), INT32_C(       6306), INT32_C(     363174), INT32_C(     -37460)),
      simde_mm256_set_epi32(INT32_C(        562), INT32_C(     221877), INT32_C(        491), INT32_C(   -2620390),
                            INT32_C(         55), INT32_C(     -75145), INT32_C(       -414), INT32_C(      44670)) },
    { simde_mm256_set_epi32(INT32_C( 1015973964), INT32_C( -637033789), INT32_C(-1269659180), INT32_C(-1847076164),
                            INT32_C(  841308417), INT32_C(-1365136816), INT32_C( -621262370), INT32_C( -734285761)),
      simde_mm256_set_epi32(INT32_C(   -1597720), INT32_C(     192391), INT32_C(    2145556), INT32_C(      -4054),
                            INT32_C(         -1), INT32_C(      63753), INT32_C(   24015328), INT32_C(        267)),
      simde_mm256_set_epi32(INT32_C(       -635), INT32_C(      -3311), INT32_C(       -591), INT32_C(     455618),
                            INT32_C( -841308417), INT32_C(     -21412), INT32_C(        -25), INT32_C(   -2750133)) },
    { simde_mm256_set_epi32(INT32_C(   55709148), INT32_C( 1036348942), INT32_C( 1622954205), INT32_C( 1464937075),
                            INT32_C(  309602207), INT32_C(  765487752), INT32_C(-1883826060), INT32_C(  396580110)),
      simde_mm256_set_epi32(INT32_C(      81348), INT32_C(     130432), INT32_C(   -2896201), INT32_C(     130033),
                            INT32_C(       2659), INT32_C(      12656), INT32_C(        -49), INT32_C(      -3976)),
      simde_mm256_set_epi32(INT32_C(        684), INT32_C(       7945), INT32_C(       -560), INT32_C(      11265),
                            INT32_C(     116435), INT32_C(      60484), INT32_C(   38445429), INT32_C(     -99743)) },
    { simde_mm256_set_epi32(INT32_C( -679308904), INT32_C( 1402916027), INT32_C( -568259373), INT32_C( -151984025),
                            INT32_C(-1276596492), INT32_C(  897258790), INT32_C( 1125465930), INT32_C(-1843912592)),
      simde_mm256_set_epi32(INT32_C(        -32), INT32_C(      -3810), INT32_C(        -77), INT32_C(     -56604),
                            INT32_C(       2670), INT32_C(      -7949), INT32_C(       3200), INT32_C(      22045)),
      simde_mm256_set_epi32(INT32_C(   21228403), INT32_C(    -368219), INT32_C(    7379991), INT32_C(       2685),
                            INT32_C(    -478126), INT32_C(    -112876), INT32_C(     351708), INT32_C(     -83643)) },
    { simde_mm256_set_epi32(INT32_C(-2128829075), INT32_C( -944286219), INT32_C(-1801390937), INT32_C( 1597729863),
                            INT32_C( -919883082), INT32_C(  243529930), INT32_C(-1346833089), INT32_C( -703593878)),
      simde_mm256_set_epi32(INT32_C(    -702474), INT32_C(       -505), INT32_C(  -33538370), INT32_C(         98),
                            INT32_C(    -989384), INT32_C(   -3405840), INT32_C(    1441037), INT32_C(         13)),
      simde_mm256_set_epi32(INT32_C(       3030), INT32_C(    1869873), INT32_C(         53), INT32_C(   16303365),
                            INT32_C(        929), INT32_C(        -71), INT32_C(       -934), INT32_C(  -54122606)) },
    { simde_mm256_set_epi32(INT32_C( 2104898600), INT32_C( 1858378377), INT32_C(  427610695), INT32_C( 1702051599),
                            INT32_C( 1832473397), INT32_C(  333005662), INT32_C( 2145787203), INT32_C(-1223503753)),
      simde_mm256_set_epi32(INT32_C( -558822192), INT32_C(   -1119473), INT32_C(         71), INT32_C(         -1),
                            INT32_C(      83208), INT32_C(        -24), INT32_C(        490), INT32_C(    1423105)),
      simde_mm256_set_epi32(INT32_C(         -3), INT32_C(      -1660), INT32_C(    6022685), INT32_C(-1702051599),
                            INT32_C(      22022), INT32_C(  -13875235), INT32_C(    4379157), INT32_C(       -859)) },
    { simde_mm256_set_epi32(INT32_C( 1485879823), INT32_C( -139198096), INT32_C(  325243915), INT32_C( 1406493107),
                            INT32_C(  631640676), INT32_C( -221831503), INT32_C(-1100348538), INT32_C(-1615759789)),
      simde_mm256_set_epi32(INT32_C(         -5), INT32_C(    6019751), INT32_C(  240957918), INT32_C(     -11512),
                            INT32_C(        598), INT32_C(      -2086), INT32_C(       -398), INT32_C(   57524929)),
      simde_mm256_set_epi32(INT32_C( -297175964), INT32_C(        -23), INT32_C(          1), INT32_C(    -122176),
                            INT32_C(    1056255), INT32_C(     106343), INT32_C(    2764694), INT32_C(        -28)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-3334573923423752375), INT64_C( 5523377417165557950),
                             INT64_C( 8907494989684855351), INT64_C(-7237415305059575746)),
      simde_mm256_set_epi64x(INT64_C(      -9171626596647), INT64_C(       -528646059918),
                             INT64_C(             -547414), INT64_C(                -408)),
      simde_mm256_set_epi64x(INT64_C(              363574), INT64_C(           -10448157),
                             INT64_C(     -16271953201205), INT64_C(   17738763002596999)) },
    { simde_mm256_set_epi64x(INT64_C( 1061533355853207499), INT64_C(-6945701440990101118),
                             INT64_C( 2574461366811200995), INT64_C( 5644549884645175906)),
      simde_mm256_set_epi64x(INT64_C(            -7767261), INT64_C(                  10),
                             INT64_C(           703320391), INT64_C(               12482)),
      simde_mm256_set_epi64x(INT64_C(       -136667656185), INT64_C( -694570144099010111),
                             INT64_C(          3660438968), INT64_C(     452215180631723)) },
    { simde_mm256_set_epi64x(INT64_C( 6574854431853233270), INT64_C(-4435882974713226150),
                             INT64_C(-7281891715377237835), INT64_C( 5757222003030846963)),
      simde_mm256_set_epi64x(INT64_C(   -6789037658203169), INT64_C(              -17570),
                             INT64_C(   13607885161437703), INT64_C(            -3435095)),
      simde_mm256_set_epi64x(INT64_C(                -968), INT64_C(     252469150524372),
                             INT64_C(                -535), INT64_C(      -1676000810175)) },
    { simde_mm256_set_epi64x(INT64_C( 8744553519166698091), INT64_C( 1287292031192317940),
                             INT64_C( 3174243940922689145), INT64_C( 1491394686146555130)),
      simde_mm256_set_epi64x(INT64_C( 4922490686897444762), INT64_C(         39224412374),
                             INT64_C(     408105256075342), INT64_C(       -123591096713)),
      simde_mm256_set_epi64x(INT64_C(                   1), INT64_C(            32818644),
                             INT64_C(                7778), INT64_C(           -12067169)) },
    { simde_mm256_set_epi64x(INT64_C( 7799483112595335323), INT64_C(-7884857912053188380),
                             INT64_C( 7107489308993436793), INT64_C( 8695475100908985079)),
      simde_mm256_set_epi64x(INT64_C(                  87), INT64_C(             9826793),
                             INT64_C(          -161255109), INT64_C(   -1858599442623445)),
      simde_mm256_set_epi64x(INT64_C(   89649231179256727), INT64_C(       -802383637474),
                             INT64_C(        -44076056585), INT64_C(               -4678)) },
    { simde_mm256_set_epi64x(INT64_C(-7825910496387937639), INT64_C( -900763466419687908),
                             INT64_C(-4456690812175475739), INT64_C(-5053240277275181299)),
      simde_mm256_set_epi64x(INT64_C(      -6606649764768), INT64_C(              -57398),
                             INT64_C( -568604113828926107), INT64_C(             4737239)),
      simde_mm256_set_epi64x(INT64_C(             1184550), INT64_C(      15693290121950),
                             INT64_C(                   7), INT64_C(      -1066705791553)) },
    { simde_mm256_set_epi64x(INT64_C(-3221953081539923764), INT64_C(-1956032791701614517),
                             INT64_C( 7374977017813000944), INT64_C( 1124803906659433418)),
      simde_mm256_set_epi64x(INT64_C( -339969907608416876), INT64_C(              -15370),
                             INT64_C(         -1321351535), INT64_C(                  -7)),
      simde_mm256_set_epi64x(INT64_C(                   9), INT64_C(     127263031340378),
                             INT64_C(         -5581389072), INT64_C( -160686272379919059)) },
    { simde_mm256_set_epi64x(INT64_C( 2535418176622027197), INT64_C(-1425521063377864898),
                             INT64_C( 5027060343823160394), INT64_C(-2416798548878703366)),
      simde_mm256_set_epi64x(INT64_C(                -250), INT64_C(                  51),
                             INT64_C(                3355), INT64_C(      22043462023905)),
      simde_mm256_set_epi64x(INT64_C(  -10141672706488108), INT64_C(  -27951393399565978),
                             INT64_C(    1498378641974116), INT64_C(             -109637)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu8(UINT8_C(236), UINT8_C(194), UINT8_C(120), UINT8_C(  0),
                             UINT8_C(238), UINT8_C(197), UINT8_C(223), UINT8_C( 50),
                             UINT8_C(177), UINT8_C( 51), UINT8_C( 14), UINT8_C(208),
                             UINT8_C(118), UINT8_C(136), UINT8_C(234), UINT8_C(162),
                             UINT8_C( 34), UINT8_C(152), UINT8_C( 32), UINT8_C( 62),
                             UINT8_C( 35), UINT8_C(101), UINT8_C( 72), UINT8_C(  2),
                             UINT8_C(139), UINT8_C(150), UINT8_C(255), UINT8_C(  2),
                             UINT8_C( 37), UINT8_C(232), UINT8_C(  3), UINT8_C(210)),
      simde_x_mm256_set_epu8(UINT8_C(218), UINT8_C( 43), UINT8_C(  2), UINT8_C(  2),
                             UINT8_C( 29), UINT8_C( 90), UINT8_C( 30), UINT8_C( 31),
                             UINT8_C( 20), UINT8_C(  1), UINT8_C( 24), UINT8_C( 92),
                             UINT8_C(  3), UINT8_C(  1), UINT8_C( 33), UINT8_C(  6),
                             UINT8_C( 14), UINT8_C( 38), UINT8_C(  5), UINT8_C(  4),
                             UINT8_C( 13), UINT8_C(  2), UINT8_C( 11), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C( 25), UINT8_C(242), UINT8_C(  3),
                             UINT8_C( 12), UINT8_C( 59), UINT8_C( 75), UINT8_C(192)),
      simde_x_mm256_set_epu8(UINT8_C(  1), UINT8_C(  4), UINT8_C( 60), UINT8_C(  0),
                             UINT8_C(  8), UINT8_C(  2), UINT8_C(  7), UINT8_C(  1),
                             UINT8_C(  8), UINT8_C( 51), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C( 39), UINT8_C(136), UINT8_C(  7), UINT8_C( 27),
                             UINT8_C(  2), UINT8_C(  4), UINT8_C(  6), UINT8_C( 15),
                             UINT8_C(  2), UINT8_C( 50), UINT8_C(  6), UINT8_C(  2),
                             UINT8_C(139), UINT8_C(  6), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  3), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1)) },
    { simde_x_mm256_set_epu8(UINT8_C(223), UINT8_C(136), UINT8_C(181), UINT8_C(189),
                             UINT8_C(144), UINT8_C(162), UINT8_C( 60), UINT8_C(122),
                             UINT8_C(180), UINT8_C(157), UINT8_C(255), UINT8_C(  4),
                             UINT8_C(248), UINT8_C( 71), UINT8_C( 45), UINT8_C(231),
                             UINT8_C(108), UINT8_C(100), UINT8_C( 13), UINT8_C(181),
                             UINT8_C(158), UINT8_C(251), UINT8_C(141), UINT8_C( 49),
                             UINT8_C(175), UINT8_C( 90), UINT8_C(251), UINT8_C( 13),
                             UINT8_C(151), UINT8_C(233), UINT8_C(181), UINT8_C(181)),
      simde_x_mm256_set_epu8(UINT8_C(  2), UINT8_C(  7), UINT8_C(  2), UINT8_C(  7),
                             UINT8_C(  6), UINT8_C( 23), UINT8_C(  1), UINT8_C( 22),
                             UINT8_C(  9), UINT8_C( 21), UINT8_C(  6), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C( 27), UINT8_C(  1), UINT8_C(254),
                             UINT8_C( 30), UINT8_C( 92), UINT8_C(  8), UINT8_C( 13),
                             UINT8_C(  7), UINT8_C(  4), UINT8_C( 29), UINT8_C( 24),
                             UINT8_C(  1), UINT8_C( 15), UINT8_C( 31), UINT8_C(  1),
                             UINT8_C(190), UINT8_C(  1), UINT8_C( 20), UINT8_C(  8)),
      simde_x_mm256_set_epu8(UINT8_C(111), UINT8_C( 19), UINT8_C( 90), UINT8_C( 27),
                             UINT8_C( 24), UINT8_C(  7), UINT8_C( 60), UINT8_C(  5),
                             UINT8_C( 20), UINT8_C(  7), UINT8_C( 42), UINT8_C(  4),
                             UINT8_C(248), UINT8_C(  2), UINT8_C( 45), UINT8_C(  0),
                             UINT8_C(  3), UINT8_C(  1), UINT8_C(  1), UINT8_C( 13),
                             UINT8_C( 22), UINT8_C( 62), UINT8_C(  4), UINT8_C(  2),
                             UINT8_C(175), UINT8_C(  6), UINT8_C(  8), UINT8_C( 13),
                             UINT8_C(  0), UINT8_C(233), UINT8_C(  9), UINT8_C( 22)) },
    { simde_x_mm256_set_epu8(UINT8_C(162), UINT8_C(  7), UINT8_C(145), UINT8_C(154),
                             UINT8_C(168), UINT8_C(175), UINT8_C( 61), UINT8_C(  3),
                             UINT8_C( 93), UINT8_C(  6), UINT8_C(114), UINT8_C( 59),
                             UINT8_C( 17), UINT8_C(165), UINT8_C(240), UINT8_C(189),
                             UINT8_C(201), UINT8_C( 90), UINT8_C( 72), UINT8_C( 56),
                             UINT8_C( 98), UINT8_C(155), UINT8_C( 93), UINT8_C(190),
                             UINT8_C( 59), UINT8_C(174), UINT8_C(136), UINT8_C(  6),
                             UINT8_C(153), UINT8_C(172), UINT8_C(102), UINT8_C(120)),
      simde_x_mm256_set_epu8(UINT8_C(110), UINT8_C( 41), UINT8_C(  3), UINT8_C( 12),
                             UINT8_C(210), UINT8_C(  1), UINT8_C(  5), UINT8_C(  6),
                             UINT8_C( 47), UINT8_C( 58), UINT8_C( 48), UINT8_C( 20),
                             UINT8_C(109), UINT8_C(  3), UINT8_C( 34), UINT8_C(  3),
                             UINT8_C(  8), UINT8_C(  5), UINT8_C(  3), UINT8_C(  1),
                             UINT8_C( 20), UINT8_C( 14), UINT8_C(  1), UINT8_C(  6),
                             UINT8_C( 15), UINT8_C(  3), UINT8_C( 95), UINT8_C(  1),
                             UINT8_C(  4), UINT8_C(  1), UINT8_C(  7), UINT8_C(  1)),
      simde_x_mm256_set_epu8(UINT8_C(  1), UINT8_C(  0), UINT8_C( 48), UINT8_C( 12),
                             UINT8_C(  0), UINT8_C(175), UINT8_C( 12), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C( 55), UINT8_C(  7), UINT8_C( 63),
                             UINT8_C( 25), UINT8_C( 18), UINT8_C( 24), UINT8_C( 56),
                             UINT8_C(  4), UINT8_C( 11), UINT8_C( 93), UINT8_C( 31),
                             UINT8_C(  3), UINT8_C( 58), UINT8_C(  1), UINT8_C(  6),
                             UINT8_C( 38), UINT8_C(172), UINT8_C( 14), UINT8_C(120)) },
    { simde_x_mm256_set_epu8(UINT8_C(  3), UINT8_C( 62), UINT8_C(201), UINT8_C( 91),
                             UINT8_C( 81), UINT8_C(108), UINT8_C(219), UINT8_C(124),
                             UINT8_C(107), UINT8_C(229), UINT8_C(194), UINT8_C(  6),
                             UINT8_C(247), UINT8_C(122), UINT8_C( 69), UINT8_C(216),
                             UINT8_C(192), UINT8_C(132), UINT8_C( 14), UINT8_C(210),
                             UINT8_C(242), UINT8_C(228), UINT8_C( 76), UINT8_C(247),
                             UINT8_C(164), UINT8_C(249), UINT8_C(124), UINT8_C(200),
                             UINT8_C(141), UINT8_C(206), UINT8_C(142), UINT8_C(235)),
      simde_x_mm256_set_epu8(UINT8_C(182), UINT8_C(  3), UINT8_C( 13), UINT8_C( 91),
                             UINT8_C( 12), UINT8_C( 10), UINT8_C(  1), UINT8_C(  3),
                             UINT8_C(  4), UINT8_C(  8), UINT8_C( 93), UINT8_C(  1),
                             UINT8_C(  2), UINT8_C( 38), UINT8_C(  3), UINT8_C(172),
                             UINT8_C( 38), UINT8_C( 15), UINT8_C( 55), UINT8_C( 26),
                             UINT8_C(  4), UINT8_C( 16), UINT8_C( 28), UINT8_C( 54),
                             UINT8_C( 21), UINT8_C( 30), UINT8_C(  3), UINT8_C( 39),
                             UINT8_C( 14), UINT8_C(171), UINT8_C(  2), UINT8_C(  4)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C( 20), UINT8_C( 15), UINT8_C(  1),
                             UINT8_C(  6), UINT8_C( 10), UINT8_C(219), UINT8_C( 41),
                             UINT8_C( 26), UINT8_C( 28), UINT8_C(  2), UINT8_C(  6),
                             UINT8_C(123), UINT8_C(  3), UINT8_C( 23), UINT8_C(  1),
                             UINT8_C(  5), UINT8_C(  8), UINT8_C(  0), UINT8_C(  8),
                             UINT8_C( 60), UINT8_C( 14), UINT8_C(  2), UINT8_C(  4),
                             UINT8_C(  7), UINT8_C(  8), UINT8_C( 41), UINT8_C(  5),
                             UINT8_C( 10), UINT8_C(  1), UINT8_C( 71), UINT8_C( 58)) },
    { simde_x_mm256_set_epu8(UINT8_C(168), UINT8_C(  0), UINT8_C(141), UINT8_C(215),
                             UINT8_C( 23), UINT8_C(105), UINT8_C(153), UINT8_C(228),
                             UINT8_C(144), UINT8_C(204), UINT8_C(214), UINT8_C(202),
                             UINT8_C(227), UINT8_C(255), UINT8_C( 22), UINT8_C(115),
                             UINT8_C(131), UINT8_C(142), UINT8_C( 73), UINT8_C(133),
                             UINT8_C( 47), UINT8_C(243), UINT8_C(254), UINT8_C(234),
                             UINT8_C( 91), UINT8_C(217), UINT8_C(119), UINT8_C(247),
                             UINT8_C(245), UINT8_C( 31), UINT8_C( 46), UINT8_C( 19)),
      simde_x_mm256_set_epu8(UINT8_C(  1), UINT8_C(248), UINT8_C(  3), UINT8_C(  9),
                             UINT8_C(  3), UINT8_C( 87), UINT8_C(117), UINT8_C( 58),
                             UINT8_C( 18), UINT8_C(  9), UINT8_C(  7), UINT8_C( 77),
                             UINT8_C( 11), UINT8_C( 11), UINT8_C( 28), UINT8_C( 49),
                             UINT8_C( 64), UINT8_C( 46), UINT8_C(  5), UINT8_C(  1),
                             UINT8_C(115), UINT8_C(  2), UINT8_C(  1), UINT8_C(  1),
                             UINT8_C( 86), UINT8_C( 10), UINT8_C(  3), UINT8_C( 12),
                             UINT8_C( 49), UINT8_C(155), UINT8_C(  1), UINT8_C(  3)),
      simde_x_mm256_set_epu8(UINT8_C(168), UINT8_C(  0), UINT8_C( 47), UINT8_C( 23),
                             UINT8_C(  7), UINT8_C(  1), UINT8_C(  1), UINT8_C(  3),
                             UINT8_C(  8), UINT8_C( 22), UINT8_C( 30), UINT8_C(  2),
                             UINT8_C( 20), UINT8_C( 23), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C(  2), UINT8_C(  3), UINT8_C( 14), UINT8_C(133),
                             UINT8_C(  0), UINT8_C(121), UINT8_C(254), UINT8_C(234),
                             UINT8_C(  1), UINT8_C( 21), UINT8_C( 39), UINT8_C( 20),
                             UINT8_C(  5), UINT8_C(  0), UINT8_C( 46), UINT8_C(  6)) },
    { simde_x_mm256_set_epu8(UINT8_C(163), UINT8_C(117), UINT8_C( 13), UINT8_C( 71),
                             UINT8_C(173), UINT8_C(230), UINT8_C(206), UINT8_C(  2),
                             UINT8_C( 15), UINT8_C(252), UINT8_C( 14), UINT8_C(197),
                             UINT8_C(249), UINT8_C(198), UINT8_C( 30), UINT8_C(180),
                             UINT8_C(128), UINT8_C( 78), UINT8_C(184), UINT8_C(254),
                             UINT8_C(184), UINT8_C(231), UINT8_C(238), UINT8_C( 30),
                             UINT8_C(194), UINT8_C( 37), UINT8_C(226), UINT8_C( 86),
                             UINT8_C(140), UINT8_C( 24), UINT8_C(144), UINT8_C( 16)),
      simde_x_mm256_set_epu8(UINT8_C( 48), UINT8_C(  1), UINT8_C(  7), UINT8_C(  6),
                             UINT8_C(119), UINT8_C( 41), UINT8_C(111), UINT8_C(  8),
                             UINT8_C(135), UINT8_C(  2), UINT8_C( 23), UINT8_C(  1),
                             UINT8_C( 88), UINT8_C( 15), UINT8_C( 65), UINT8_C( 79),
                             UINT8_C( 29), UINT8_C(  5), UINT8_C(  5), UINT8_C(  6),
                             UINT8_C( 44), UINT8_C( 21), UINT8_C(  2), UINT8_C(  3),
                             UINT8_C( 15), UINT8_C(  1), UINT8_C(  3), UINT8_C(  3),
                             UINT8_C(  1), UINT8_C( 10), UINT8_C(  1), UINT8_C( 55)),
      simde_x_mm256_set_epu8(UINT8_C(  3), UINT8_C(117), UINT8_C(  1), UINT8_C( 11),
                             UINT8_C(  1), UINT8_C(  5), UINT8_C(  1), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(126), UINT8_C(  0), UINT8_C(197),
                             UINT8_C(  2), UINT8_C( 13), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C(  4), UINT8_C( 15), UINT8_C( 36), UINT8_C( 42),
                             UINT8_C(  4), UINT8_C( 11), UINT8_C(119), UINT8_C( 10),
                             UINT8_C( 12), UINT8_C( 37), UINT8_C( 75), UINT8_C( 28),
                             UINT8_C(140), UINT8_C(  2), UINT8_C(144), UINT8_C(  0)) },
    { simde_x_mm256_set_epu8(UINT8_C(239), UINT8_C(204), UINT8_C( 51), UINT8_C(246),
                             UINT8_C( 77), UINT8_C(149), UINT8_C( 40), UINT8_C( 86),
                             UINT8_C( 29), UINT8_C(  8), UINT8_C(140), UINT8_C(202),
                             UINT8_C(138), UINT8_C(208), UINT8_C(142), UINT8_C( 95),
                             UINT8_C(247), UINT8_C(102), UINT8_C( 63), UINT8_C(232),
                             UINT8_C(115), UINT8_C(187), UINT8_C(122), UINT8_C(179),
                             UINT8_C( 81), UINT8_C(192), UINT8_C( 47), UINT8_C( 34),
                             UINT8_C( 24), UINT8_C(133), UINT8_C( 98), UINT8_C(208)),
      simde_x_mm256_set_epu8(UINT8_C( 11), UINT8_C(  8), UINT8_C(  2), UINT8_C( 10),
                             UINT8_C(  3), UINT8_C(  7), UINT8_C( 38), UINT8_C( 21),
                             UINT8_C(247), UINT8_C( 14), UINT8_C(  4), UINT8_C(  3),
                             UINT8_C( 85), UINT8_C( 59), UINT8_C( 41), UINT8_C(  1),
                             UINT8_C(  1), UINT8_C(250), UINT8_C(  1), UINT8_C(  2),
                             UINT8_C(  6), UINT8_C(  8), UINT8_C(  6), UINT8_C( 40),
                             UINT8_C(136), UINT8_C( 10), UINT8_C( 29), UINT8_C(  7),
                             UINT8_C( 36), UINT8_C(  8), UINT8_C(  1), UINT8_C(  7)),
      simde_x_mm256_set_epu8(UINT8_C( 21), UINT8_C( 25), UINT8_C( 25), UINT8_C( 24),
                             UINT8_C( 25), UINT8_C( 21), UINT8_C(  1), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C( 35), UINT8_C( 67),
                             UINT8_C(  1), UINT8_C(  3), UINT8_C(  3), UINT8_C( 95),
                             UINT8_C(247), UINT8_C(  0), UINT8_C( 63), UINT8_C(116),
                             UINT8_C( 19), UINT8_C( 23), UINT8_C( 20), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C( 19), UINT8_C(  1), UINT8_C(  4),
                             UINT8_C(  0), UINT8_C( 16), UINT8_C( 98), UINT8_C( 29)) },
    { simde_x_mm256_set_epu8(UINT8_C(179), UINT8_C(197), UINT8_C(124), UINT8_C(228),
                             UINT8_C(210), UINT8_C(205), UINT8_C(251), UINT8_C( 37),
                             UINT8_C( 37), UINT8_C( 57), UINT8_C( 27), UINT8_C( 38),
                             UINT8_C( 13), UINT8_C(212), UINT8_C(201), UINT8_C(125),
                             UINT8_C( 84), UINT8_C(229), UINT8_C( 76), UINT8_C(128),
                             UINT8_C(139), UINT8_C(203), UINT8_C(238), UINT8_C(218),
                             UINT8_C( 40), UINT8_C( 95), UINT8_C(243), UINT8_C(110),
                             UINT8_C( 74), UINT8_C(  0), UINT8_C(215), UINT8_C( 43)),
      simde_x_mm256_set_epu8(UINT8_C(  2), UINT8_C(  2), UINT8_C(  4), UINT8_C(  5),
                             UINT8_C(  7), UINT8_C(  2), UINT8_C(195), UINT8_C(  2),
                             UINT8_C( 30), UINT8_C(  1), UINT8_C(  9), UINT8_C( 24),
                             UINT8_C(  6), UINT8_C(  7), UINT8_C( 28), UINT8_C( 58),
                             UINT8_C(  3), UINT8_C( 77), UINT8_C( 90), UINT8_C( 51),
                             UINT8_C( 13), UINT8_C( 12), UINT8_C(  7), UINT8_C( 91),
                             UINT8_C(243), UINT8_C( 40), UINT8_C(  1), UINT8_C( 45),
                             UINT8_C( 77), UINT8_C( 45), UINT8_C( 60), UINT8_C(  3)),
      simde_x_mm256_set_epu8(UINT8_C( 89), UINT8_C( 98), UINT8_C( 31), UINT8_C( 45),
                             UINT8_C( 30), UINT8_C(102), UINT8_C(  1), UINT8_C( 18),
                             UINT8_C(  1), UINT8_C( 57), UINT8_C(  3), UINT8_C(  1),
                             UINT8_C(  2), UINT8_C( 30), UINT8_C(  7), UINT8_C(  2),
                             UINT8_C( 28), UINT8_C(  2), UINT8_C(  0), UINT8_C(  2),
                             UINT8_C( 10), UINT8_C( 16), UINT8_C( 34), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  2), UINT8_C(243), UINT8_C(  2),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  3), UINT8_C( 14)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu16(UINT16_C( 50042), UINT16_C( 33648), UINT16_C(  7535), UINT16_C( 12279),
                              UINT16_C( 36071), UINT16_C( 18107), UINT16_C( 48674), UINT16_C( 48206),
                              UINT16_C(  9011), UINT16_C( 45275), UINT16_C(  7845), UINT16_C( 54048),
                              UINT16_C( 27322), UINT16_C( 31657), UINT16_C( 43497), UINT16_C( 33598)),
      simde_x_mm256_set_epu16(UINT16_C( 12011), UINT16_C(   249), UINT16_C(     5), UINT16_C(     2),
                              UINT16_C(  1870), UINT16_C(  2904), UINT16_C(  1530), UINT16_C( 42479),
                              UINT16_C( 63442), UINT16_C(  1039), UINT16_C(    54), UINT16_C(     1),
                              UINT16_C(    98), UINT16_C(  7948), UINT16_C(  2053), UINT16_C(    29)),
      simde_x_mm256_set_epu16(UINT16_C(     4), UINT16_C(   135), UINT16_C(  1507), UINT16_C(  6139),
                              UINT16_C(    19), UINT16_C(     6), UINT16_C(    31), UINT16_C(     1),
                              UINT16_C(     0), UINT16_C(    43), UINT16_C(   145), UINT16_C( 54048),
                              UINT16_C(   278), UINT16_C(     3), UINT16_C(    21), UINT16_C(  1158)) },
    { simde_x_mm256_set_epu16(UINT16_C( 31411), UINT16_C( 55001), UINT16_C( 38051), UINT16_C( 20389),
                              UINT16_C( 61351), UINT16_C( 22045), UINT16_C( 61939), UINT16_C( 10168),
                              UINT16_C( 65482), UINT16_C( 32951), UINT16_C( 59114), UINT16_C(  9472),
                              UINT16_C( 21787), UINT16_C(  1387), UINT16_C( 60519), UINT16_C( 39038)),
      simde_x_mm256_set_epu16(UINT16_C( 11771), UINT16_C(     1), UINT16_C(   490), UINT16_C( 32408),
                              UINT16_C(  2225), UINT16_C(   134), UINT16_C( 13968), UINT16_C(     1),
                              UINT16_C(   387), UINT16_C( 14591), UINT16_C(    24), UINT16_C(    46),
                              UINT16_C(  8450), UINT16_C(  1053), UINT16_C(   908), UINT16_C(  5686)),
      simde_x_mm256_set_epu16(UINT16_C(     2), UINT16_C( 55001), UINT16_C(    77), UINT16_C(     0),
                              UINT16_C(    27), UINT16_C(   164), UINT16_C(     4), UINT16_C( 10168),
                              UINT16_C(   169), UINT16_C(     2), UINT16_C(  2463), UINT16_C(   205),
                              UINT16_C(     2), UINT16_C(     1), UINT16_C(    66), UINT16_C(     6)) },
    { simde_x_mm256_set_epu16(UINT16_C( 22899), UINT16_C(   630), UINT16_C( 34558), UINT16_C(  7884),
                              UINT16_C( 39724), UINT16_C( 33230), UINT16_C( 54475), UINT16_C( 22805),
                              UINT16_C( 61755), UINT16_C( 34661), UINT16_C( 28373), UINT16_C( 58279),
                              UINT16_C( 22187), UINT16_C( 56981), UINT16_C( 43877), UINT16_C(  3469)),
      simde_x_mm256_set_epu16(UINT16_C( 12306), UINT16_C(   182), UINT16_C( 29239), UINT16_C(  4194),
                              UINT16_C(   818), UINT16_C(    16), UINT16_C(     5), UINT16_C(    38),
                              UINT16_C( 42688), UINT16_C(     8), UINT16_C(     1), UINT16_C(    96),
                              UINT16_C(     3), UINT16_C(     1), UINT16_C(   508), UINT16_C(     1)),
      simde_x_mm256_set_epu16(UINT16_C(     1), UINT16_C(     3), UINT16_C(     1), UINT16_C(     1),
                              UINT16_C(    48), UINT16_C(  2076), UINT16_C( 10895), UINT16_C(   600),
                              UINT16_C(     1), UINT16_C(  4332), UINT16_C( 28373), UINT16_C(   607),
                              UINT16_C(  7395), UINT16_C( 56981), UINT16_C(    86), UINT16_C(  3469)) },
    { simde_x_mm256_set_epu16(UINT16_C( 29363), UINT16_C( 50584), UINT16_C( 56168), UINT16_C( 44370),
                              UINT16_C( 62910), UINT16_C( 23255), UINT16_C( 39479), UINT16_C( 21044),
                              UINT16_C(  7491), UINT16_C( 25737), UINT16_C(  6938), UINT16_C( 40142),
                              UINT16_C( 22210), UINT16_C( 63545), UINT16_C( 33358), UINT16_C(  9014)),
      simde_x_mm256_set_epu16(UINT16_C(    61), UINT16_C(   274), UINT16_C(   365), UINT16_C( 58937),
                              UINT16_C(     2), UINT16_C(   172), UINT16_C(   432), UINT16_C(     2),
                              UINT16_C(   957), UINT16_C(   351), UINT16_C(    18), UINT16_C( 12717),
                              UINT16_C(     4), UINT16_C(   417), UINT16_C(     1), UINT16_C( 10550)),
      simde_x_mm256_set_epu16(UINT16_C(   481), UINT16_C(   184), UINT16_C(   153), UINT16_C(     0),
                              UINT16_C( 31455), UINT16_C(   135), UINT16_C(    91), UINT16_C( 10522),
                              UINT16_C(     7), UINT16_C(    73), UINT16_C(   385), UINT16_C(     3),
                              UINT16_C(  5552), UINT16_C(   152), UINT16_C( 33358), UINT16_C(     0)) },
    { simde_x_mm256_set_epu16(UINT16_C( 22208), UINT16_C( 58940), UINT16_C( 24739), UINT16_C( 29405),
                              UINT16_C(  9863), UINT16_C( 41917), UINT16_C( 30045), UINT16_C( 40634),
                              UINT16_C( 50211), UINT16_C(  4668), UINT16_C( 42314), UINT16_C( 29370),
                              UINT16_C( 57744), UINT16_C( 37787), UINT16_C( 17171), UINT16_C( 34222)),
      simde_x_mm256_set_epu16(UINT16_C(  4256), UINT16_C( 23971), UINT16_C(   171), UINT16_C(    12),
                              UINT16_C(  8070), UINT16_C(  2906), UINT16_C(    22), UINT16_C(   107),
                              UINT16_C(     3), UINT16_C(     1), UINT16_C( 28355), UINT16_C(  2210),
                              UINT16_C(     1), UINT16_C(  1161), UINT16_C(   613), UINT16_C( 51426)),
      simde_x_mm256_set_epu16(UINT16_C(     5), UINT16_C(     2), UINT16_C(   144), UINT16_C(  2450),
                              UINT16_C(     1), UINT16_C(    14), UINT16_C(  1365), UINT16_C(   379),
                              UINT16_C( 16737), UINT16_C(  4668), UINT16_C(     1), UINT16_C(    13),
                              UINT16_C( 57744), UINT16_C(    32), UINT16_C(    28), UINT16_C(     0)) },
    { simde_x_mm256_set_epu16(UINT16_C(  9143), UINT16_C( 55963), UINT16_C( 46820), UINT16_C( 55354),
                              UINT16_C( 21540), UINT16_C( 21596), UINT16_C( 49435), UINT16_C( 42142),
                              UINT16_C( 28170), UINT16_C(  3714), UINT16_C( 39462), UINT16_C( 28043),
                              UINT16_C( 45359), UINT16_C( 22609), UINT16_C( 55149), UINT16_C( 21886)),
      simde_x_mm256_set_epu16(UINT16_C(  3121), UINT16_C(   103), UINT16_C(     1), UINT16_C(   283),
                              UINT16_C(   201), UINT16_C(    53), UINT16_C( 25996), UINT16_C(  3169),
                              UINT16_C(     1), UINT16_C(     2), UINT16_C(    38), UINT16_C(    24),
                              UINT16_C(    55), UINT16_C( 25444), UINT16_C(  5182), UINT16_C(     9)),
      simde_x_mm256_set_epu16(UINT16_C(     2), UINT16_C(   543), UINT16_C( 46820), UINT16_C(   195),
                              UINT16_C(   107), UINT16_C(   407), UINT16_C(     1), UINT16_C(    13),
                              UINT16_C( 28170), UINT16_C(  1857), UINT16_C(  1038), UINT16_C(  1168),
                              UINT16_C(   824), UINT16_C(     0), UINT16_C(    10), UINT16_C(  2431)) },
    { simde_x_mm256_set_epu16(UINT16_C( 51894), UINT16_C(  1840), UINT16_C( 33552), UINT16_C( 50070),
                              UINT16_C( 16848), UINT16_C( 13340), UINT16_C( 25356), UINT16_C( 34016),
                              UINT16_C( 61275), UINT16_C( 22886), UINT16_C( 28292), UINT16_C( 37845),
                              UINT16_C(  1481), UINT16_C(   559), UINT16_C( 12899), UINT16_C( 38851)),
      simde_x_mm256_set_epu16(UINT16_C( 16266), UINT16_C(   376), UINT16_C( 62048), UINT16_C(     8),
                              UINT16_C(    53), UINT16_C(  1573), UINT16_C(     8), UINT16_C(   212),
                              UINT16_C( 15505), UINT16_C(     1), UINT16_C(    10), UINT16_C(  2744),
                              UINT16_C(     2), UINT16_C(     5), UINT16_C(  4478), UINT16_C( 12656)),
      simde_x_mm256_set_epu16(UINT16_C(     3), UINT16_C(     4), UINT16_C(     0), UINT16_C(  6258),
                              UINT16_C(   317), UINT16_C(     8), UINT16_C(  3169), UINT16_C(   160),
                              UINT16_C(     3), UINT16_C( 22886), UINT16_C(  2829), UINT16_C(    13),
                              UINT16_C(   740), UINT16_C(   111), UINT16_C(     2), UINT16_C(     3)) },
    { simde_x_mm256_set_epu16(UINT16_C( 40946), UINT16_C( 11832), UINT16_C( 52869), UINT16_C( 41324),
                              UINT16_C( 41064), UINT16_C( 57085), UINT16_C( 14204), UINT16_C( 23869),
                              UINT16_C( 30467), UINT16_C( 20149), UINT16_C( 58844), UINT16_C( 49602),
                              UINT16_C( 36092), UINT16_C( 39146), UINT16_C( 62840), UINT16_C( 19573)),
      simde_x_mm256_set_epu16(UINT16_C(  7725), UINT16_C(  5897), UINT16_C(    81), UINT16_C(   199),
                              UINT16_C( 33008), UINT16_C( 55443), UINT16_C(   925), UINT16_C(  4043),
                              UINT16_C(   362), UINT16_C(   156), UINT16_C(  2592), UINT16_C(    29),
                              UINT16_C(   213), UINT16_C(    14), UINT16_C(    39), UINT16_C(   178)),
      simde_x_mm256_set_epu16(UINT16_C(     5), UINT16_C(     2), UINT16_C(   652), UINT16_C(   207),
                              UINT16_C(     1), UINT16_C(     1), UINT16_C(    15), UINT16_C(     5),
                              UINT16_C(    84), UINT16_C(   129), UINT16_C(    22), UINT16_C(  1710),
                              UINT16_C(   169), UINT16_C(  2796), UINT16_C(  1611), UINT16_C(   109)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu32(UINT32_C( 621216267), UINT32_C(2973447507), UINT32_C(1814279233), UINT32_C(3673557536),
                              UINT32_C(4015780858), UINT32_C(1070914538), UINT32_C(2707640519), UINT32_C(3041291274)),
      simde_x_mm256_set_epu32(UINT32_C(    122731), UINT32_C(  51630147), UINT32_C(    152670), UINT32_C(   7731229),
                              UINT32_C(    711400), UINT32_C(   1744981), UINT32_C( 164943127), UINT32_C(    169494)),
      simde_x_mm256_set_epu32(UINT32_C(      5061), UINT32_C(        57), UINT32_C(     11883), UINT32_C(       475),
                              UINT32_C(      5644), UINT32_C(       613), UINT32_C(        16), UINT32_C(     17943)) },
    { simde_x_mm256_set_epu32(UINT32_C(1084014678), UINT32_C(1666523830), UINT32_C(3454667769), UINT32_C(4029614313),
                              UINT32_C(3425016021), UINT32_C(2449839571), UINT32_C(1601532569), UINT32_C(1519388398)),
      simde_x_mm256_set_epu32(UINT32_C(    130157), UINT32_C(   5585515), UINT32_C(  62691231), UINT32_C(     37123),
                              UINT32_C(   2515600), UINT32_C( 106484982), UINT32_C(4168501606), UINT32_C(   2781814)),
      simde_x_mm256_set_epu32(UINT32_C(      8328), UINT32_C(       298), UINT32_C(        55), UINT32_C(    108547),
                              UINT32_C(      1361), UINT32_C(        23), UINT32_C(         0), UINT32_C(       546)) },
    { simde_x_mm256_set_epu32(UINT32_C(2187853776), UINT32_C( 131263503), UINT32_C(  20338031), UINT32_C(3062800456),
                              UINT32_C(1802896354), UINT32_C(  22231847), UINT32_C(3438214155), UINT32_C(1776513196)),
      simde_x_mm256_set_epu32(UINT32_C(  28353115), UINT32_C(  92496104), UINT32_C(  15335526), UINT32_C(  99105532),
                              UINT32_C(   5905009), UINT32_C(     27824), UINT32_C(     28986), UINT32_C(  12459911)),
      simde_x_mm256_set_epu32(UINT32_C(        77), UINT32_C(         1), UINT32_C(         1), UINT32_C(        30),
                              UINT32_C(       305), UINT32_C(       799), UINT32_C(    118616), UINT32_C(       142)) },
    { simde_x_mm256_set_epu32(UINT32_C( 524596333), UINT32_C(3965897825), UINT32_C(1593754725), UINT32_C( 694203496),
                              UINT32_C(1917650066), UINT32_C(2692610113), UINT32_C(1620259645), UINT32_C( 607116294)),
      simde_x_mm256_set_epu32(UINT32_C(  29757558), UINT32_C(     80117), UINT32_C( 412054571), UINT32_C(    878110),
                              UINT32_C(4124070325), UINT32_C(   8250706), UINT32_C(   7930575), UINT32_C(     51813)),
      simde_x_mm256_set_epu32(UINT32_C(        17), UINT32_C(     49501), UINT32_C(         3), UINT32_C(       790),
                              UINT32_C(         0), UINT32_C(       326), UINT32_C(       204), UINT32_C(     11717)) },
    { simde_x_mm256_set_epu32(UINT32_C( 625862951), UINT32_C( 793130310), UINT32_C(2489185635), UINT32_C(2468815203),
                              UINT32_C(3079066921), UINT32_C( 802958712), UINT32_C(1537818066), UINT32_C(1678295724)),
      simde_x_mm256_set_epu32(UINT32_C(   8259237), UINT32_C(    229091), UINT32_C(   7899398), UINT32_C(  41009690),
                              UINT32_C(  26030333), UINT32_C(    228627), UINT32_C(1200021710), UINT32_C(    186204)),
      simde_x_mm256_set_epu32(UINT32_C(        75), UINT32_C(      3462), UINT32_C(       315), UINT32_C(        60),
                              UINT32_C(       118), UINT32_C(      3512), UINT32_C(         1), UINT32_C(      9013)) },
    { simde_x_mm256_set_epu32(UINT32_C(3334078645), UINT32_C(2226952893), UINT32_C(1901933944), UINT32_C(3456551705),
                              UINT32_C(3394846076), UINT32_C(2592342753), UINT32_C(1822000161), UINT32_C(3060682219)),
      simde_x_mm256_set_epu32(UINT32_C(     55529), UINT32_C(     95077), UINT32_C(  61849330), UINT32_C(     77269),
                              UINT32_C(    181901), UINT32_C(     66287), UINT32_C(     46407), UINT32_C(      1962)),
      simde_x_mm256_set_epu32(UINT32_C(     60042), UINT32_C(     23422), UINT32_C(        30), UINT32_C(     44734),
                              UINT32_C(     18663), UINT32_C(     39107), UINT32_C(     39261), UINT32_C(   1559980)) },
    { simde_x_mm256_set_epu32(UINT32_C(2418478797), UINT32_C(3856569345), UINT32_C(2562700829), UINT32_C(2670510577),
                              UINT32_C(3958231909), UINT32_C(3386864730), UINT32_C(2249491002), UINT32_C( 367242130)),
      simde_x_mm256_set_epu32(UINT32_C( 106591767), UINT32_C( 591565864), UINT32_C(    241208), UINT32_C(    384474),
                              UINT32_C(  63569588), UINT32_C(1007016971), UINT32_C( 701090048), UINT32_C(   4482965)),
      simde_x_mm256_set_epu32(UINT32_C(        22), UINT32_C(         6), UINT32_C(     10624), UINT32_C(      6945),
                              UINT32_C(        62), UINT32_C(         3), UINT32_C(         3), UINT32_C(        81)) },
    { simde_x_mm256_set_epu32(UINT32_C(3497551851), UINT32_C(3538232808), UINT32_C(3581222707), UINT32_C(2092274030),
                              UINT32_C(1202922035), UINT32_C(3381143079), UINT32_C(1645890362), UINT32_C(2497764821)),
      simde_x_mm256_set_epu32(UINT32_C(   7255461), UINT32_C(    387871), UINT32_C( 216379987), UINT32_C(   1108325),
                              UINT32_C(   9779926), UINT32_C( 265173482), UINT32_C(    305369), UINT32_C(1628979148)),
      simde_x_mm256_set_epu32(UINT32_C(       482), UINT32_C(      9122), UINT32_C(        16), UINT32_C(      1887),
                              UINT32_C(       122), UINT32_C(        12), UINT32_C(      5389), UINT32_C(         1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu64x(UINT64_C(10385902570114433083), UINT64_C(14228451038995253976),
                               UINT64_C( 3524803476344021799), UINT64_C( 9008088981795720991)),
      simde_x_mm256_set_epu64x(UINT64_C(      11435629647830), UINT64_C(        134705148152),
                               UINT64_C(                1685), UINT64_C(         72468903699)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744073708846728), UINT64_C(18446744073678236607),
                               UINT64_C(    2091871499313959), UINT64_C(           124302818)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 2776707612149100363), UINT64_C(15446686956822865619),
                               UINT64_C( 8116027459326381863), UINT64_C(10577862568627142107)),
      simde_x_mm256_set_epu64x(UINT64_C(              160900), UINT64_C(                 876),
                               UINT64_C(             6656645), UINT64_C(                 198)),
      simde_x_mm256_set_epu64x(UINT64_C(      17257349982281), UINT64_C(18443319350973379601),
                               UINT64_C(       1219236936824), UINT64_C(18407002247926307124)) },
    { simde_x_mm256_set_epu64x(UINT64_C(17966513918331168112), UINT64_C(15404442576328540960),
                               UINT64_C( 1544001744444053712), UINT64_C(12311626015854130554)),
      simde_x_mm256_set_epu64x(UINT64_C(         73453582701), UINT64_C(       2241703492778),
                               UINT64_C(                 149), UINT64_C(    1898802076338580)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744073703013744), UINT64_C(18446744073708194478),
                               UINT64_C(   10362427815060763), UINT64_C(18446744073709548385)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 4996618049503500636), UINT64_C( 3587306346705364576),
                               UINT64_C( 1416661578746677042), UINT64_C(18012200189266188151)),
      simde_x_mm256_set_epu64x(UINT64_C(       9141117518131), UINT64_C(  259684114065326460),
                               UINT64_C(          3735868918), UINT64_C(      13028085907926)),
      simde_x_mm256_set_epu64x(UINT64_C(              546609), UINT64_C(                  13),
                               UINT64_C(           379205376), UINT64_C(18446744073709518262)) },
    { simde_x_mm256_set_epu64x(UINT64_C(17900245410321819662), UINT64_C(   86463307544105486),
                               UINT64_C( 7004808110937624000), UINT64_C( 5352056724630121100)),
      simde_x_mm256_set_epu64x(UINT64_C(           574976069), UINT64_C(   26168849408611714),
                               UINT64_C(           479458176), UINT64_C(         85883846687)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744072759079601), UINT64_C(                   3),
                               UINT64_C(         14609841820), UINT64_C(            62317384)) },
    { simde_x_mm256_set_epu64x(UINT64_C(18191047755947595201), UINT64_C(11274709867061747164),
                               UINT64_C( 4957427800472277352), UINT64_C( 2636046644056480855)),
      simde_x_mm256_set_epu64x(UINT64_C(           455513034), UINT64_C( 4176708352330988763),
                               UINT64_C(              255407), UINT64_C(   77468887445572755)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744073148214621), UINT64_C(18446744073709551615),
                               UINT64_C(      19409913590748), UINT64_C(                  34)) },
    { simde_x_mm256_set_epu64x(UINT64_C(17236629464649076584), UINT64_C( 6716520602983844465),
                               UINT64_C(12794135593178656259), UINT64_C( 3865374743078695737)),
      simde_x_mm256_set_epu64x(UINT64_C(      13893724010244), UINT64_C(                   1),
                               UINT64_C(           142890905), UINT64_C(        135073488234)),
      simde_x_mm256_set_epu64x(UINT64_C(18446744073709464519), UINT64_C( 6716520602983844465),
                               UINT64_C(18446744034150641408), UINT64_C(            28616827)) },
    { simde_x_mm256_set_epu64x(UINT64_C( 3248934010021333275), UINT64_C( 8464322280604302303),
                               UINT64_C(10783963704762759650), UINT64_C(14288989654597257942)),
      simde_x_mm256_set_epu64x(UINT64_C(      37187973814779), UINT64_C(           988730192),
                               UINT64_C(       9409064941619), UINT64_C(           554649997)),
      simde_x_mm256_set_epu64x(UINT64_C(               87365), UINT64_C(          8560800862),
                               UINT64_C(18446744073708737212), UINT64_C(18446744066213374853)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_div_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

#endif /* defined(SIMDE_SVML_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_SVML_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm_div_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm_div_epu64),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_epu64),
#endif /* defined(SIMDE_SVML_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

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
