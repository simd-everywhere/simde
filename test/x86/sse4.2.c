/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX sse4_2
#include <test/x86/test-x86-internal.h>
#include <simde/x86/sse4.2.h>

#if defined(SIMDE_SSE4_2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm_cmpgt_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-2149331112921330677), INT64_C( 3189038460188560982)),
      simde_mm_set_epi64x(INT64_C( -996047549682722220), INT64_C(-3995545326609437904)),
      simde_mm_set_epi64x( INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C( 3213898448913237846), INT64_C( 9188286366666087308)),
      simde_mm_set_epi64x(INT64_C( 2918885787365950970), INT64_C( 6780053140456787494)),
      simde_mm_set_epi64x(~INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C(-6480415937191367948), INT64_C( 6434069133602920016)),
      simde_mm_set_epi64x(INT64_C( 8054577307931165184), INT64_C( 2226222084862743618)),
      simde_mm_set_epi64x( INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C(-6197561420805751907), INT64_C( 4778870285233423339)),
      simde_mm_set_epi64x(INT64_C( 1839658993612937599), INT64_C( -902367911293731861)),
      simde_mm_set_epi64x( INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C( 5091127324004768664), INT64_C(-2002251908801446460)),
      simde_mm_set_epi64x(INT64_C(-9056506211008935561), INT64_C(-6487933609077704174)),
      simde_mm_set_epi64x(~INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C(-4743149223868910453), INT64_C(-4137271544350199785)),
      simde_mm_set_epi64x(INT64_C( 4762909370147937560), INT64_C( 6560801355595049799)),
      simde_mm_set_epi64x( INT64_C(0),  INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C(  913044205052582612), INT64_C(-2362244502684338485)),
      simde_mm_set_epi64x(INT64_C( -603710511502052754), INT64_C(-3179203207537477667)),
      simde_mm_set_epi64x(~INT64_C(0), ~INT64_C(0)) },
    { simde_mm_set_epi64x(INT64_C( 6753725813089147170), INT64_C( 7031124288307654085)),
      simde_mm_set_epi64x(INT64_C( 5046765831366456160), INT64_C( 6981054579474564569)),
      simde_mm_set_epi64x(~INT64_C(0), ~INT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpgt_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

#endif /* defined(SIMDE_SSE4_2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_SSE4_2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_epi64),
#endif /* defined(SIMDE_SSE4_2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

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
