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

#include "test.h"

#include "../sse.h"

#include <fenv.h>
#include <math.h>

static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  MunitSuite test_suites[] = {
    simde_mmx_test_suite,
    simde_sse_test_suite,
    /* simde_sse2_test_suite, */
    { 0, },
  };

  MunitSuite test_suite = {
    (char*) "/cmp",
    test_suite_tests,
    test_suites,
    TEST_PREFERRED_ITERATIONS,
    MUNIT_SUITE_OPTION_NONE
  };

  /* Set the SSE rounding mode to match the CPU rounding mode. */
#if defined(SIMDE__SSE_NATIVE)
  switch (fegetround()) {
#if defined(FE_TONEAREST)
    case FE_TONEAREST:
      simde_MM_SET_ROUNDING_MODE(_MM_ROUND_NEAREST);
      break;
#endif
#if defined(FE_DOWNWARD)
    case FE_DOWNWARD:
      simde_MM_SET_ROUNDING_MODE(_MM_ROUND_DOWN);
      break;
#endif
#if defined(FE_UPWARD)
    case FE_UPWARD:
      simde_MM_SET_ROUNDING_MODE(_MM_ROUND_UP);
      break;
#endif
#if defined(FE_TOWARDZERO)
    case FE_TOWARDZERO:
      simde_MM_SET_ROUNDING_MODE(_MM_ROUND_TOWARD_ZERO);
      break;
#endif
  }
#endif

  return munit_suite_main(&test_suite, NULL, argc, argv);
}
