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

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   simde__m128i_private a, r;

  //   munit_rand_memory(sizeof(a), (uint8_t*) &a);
  //   for (size_t j = 0 ; j < (sizeof(a.i16) / sizeof(a.i16[0])) ; j++) {
  //       a.i16[j] >>= munit_rand_int_range(0, 15);
  //   }

  //   r = simde__m128i_to_private(simde_mm_cvtsepi16_epi8(simde__m128i_from_private(a)));

  //   printf("    { simde_mm_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //    "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
  //          a.i16[7], a.i16[6], a.i16[5], a.i16[4], a.i16[3], a.i16[2], a.i16[1], a.i16[0]);
  //   printf("      simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //    "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //    "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //    "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
  //          r.i8[15], r.i8[14], r.i8[13], r.i8[12], r.i8[11], r.i8[10], r.i8[ 9], r.i8[ 8],
  //          r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  // }
  // return MUNIT_FAIL;

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

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   simde__m256i_private a;
  //   simde__m128i_private r;

  //   munit_rand_memory(sizeof(a), (uint8_t*) &a);
  //   for (size_t j = 0 ; j < (sizeof(a.i16) / sizeof(a.i16[0])) ; j++) {
  //       a.i16[j] >>= munit_rand_int_range(0, 15);
  //   }

  //   r = simde__m128i_to_private(simde_mm256_cvtsepi16_epi8(simde__m256i_from_private(a)));

  //   printf("    { simde_mm256_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
  //          a.i16[15], a.i16[14], a.i16[13], a.i16[12], a.i16[11], a.i16[10], a.i16[ 9], a.i16[ 8],
  //          a.i16[ 7], a.i16[ 6], a.i16[ 5], a.i16[ 4], a.i16[ 3], a.i16[ 2], a.i16[ 1], a.i16[ 0]);
  //   printf("      simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //    "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //    "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //    "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
  //          r.i8[15], r.i8[14], r.i8[13], r.i8[12], r.i8[11], r.i8[10], r.i8[ 9], r.i8[ 8],
  //          r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvtsepi16_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_cvtsepi16_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

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

  // printf("\n");
  // for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
  //   simde__m512i_private a;
  //   simde__m256i_private r;

  //   munit_rand_memory(sizeof(a), (uint8_t*) &a);
  //   for (size_t j = 0 ; j < (sizeof(a.i16) / sizeof(a.i16[0])) ; j++) {
  //       a.i16[j] >>= munit_rand_int_range(0, 15);
  //   }

  //   r = simde__m256i_to_private(simde_mm512_cvtsepi16_epi8(simde__m512i_from_private(a)));

  //   printf("    { simde_mm512_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
  //          "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
  //          a.i16[31], a.i16[30], a.i16[29], a.i16[28], a.i16[27], a.i16[26], a.i16[25], a.i16[24],
  //          a.i16[23], a.i16[22], a.i16[21], a.i16[20], a.i16[19], a.i16[18], a.i16[17], a.i16[16],
  //          a.i16[15], a.i16[14], a.i16[13], a.i16[12], a.i16[11], a.i16[10], a.i16[ 9], a.i16[ 8],
  //          a.i16[ 7], a.i16[ 6], a.i16[ 5], a.i16[ 4], a.i16[ 3], a.i16[ 2], a.i16[ 1], a.i16[ 0]);
  //   printf("      simde_mm256_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
  //          "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
  //          r.i8[31], r.i8[30], r.i8[29], r.i8[28], r.i8[27], r.i8[26], r.i8[25], r.i8[24],
  //          r.i8[23], r.i8[22], r.i8[21], r.i8[20], r.i8[19], r.i8[18], r.i8[17], r.i8[16],
  //          r.i8[15], r.i8[14], r.i8[13], r.i8[12], r.i8[11], r.i8[10], r.i8[ 9], r.i8[ 8],
  //          r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  // }
  // return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_cvtsepi16_epi8(test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
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
  SIMDE_TESTS_DEFINE_TEST(mm512_cvtsepi16_epi8),

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
