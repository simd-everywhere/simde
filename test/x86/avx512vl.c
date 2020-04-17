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

#endif /* defined(SIMDE_avx512vl_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_AVX512VL_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

  SIMDE_TESTS_DEFINE_TEST(mm_cvtsepi16_epi8),

  SIMDE_TESTS_DEFINE_TEST(mm256_cvtsepi16_epi8),

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
