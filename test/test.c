/* Copyright (c) 2018 Evan Nemerson <evan@nemerson.com>
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

#if !defined(DISABLE_X86)
#  include "x86/x86-internal.h"
#endif
#if !defined(DISABLE_ARM)
#  include "arm/arm-internal.h"
#endif
#include "simd-js/simd-js.h"

#include <fenv.h>
#include <math.h>

static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  MunitSuite x86_test_suites[] = {
#if !defined(DISABLE_X86)
    simde_mmx_test_suite,
    simde_mmx_emul_test_suite,
    simde_mmx_cmp_test_suite,

    simde_sse_test_suite,
    simde_sse_emul_test_suite,
    simde_sse_cmp_test_suite,

    simde_sse2_test_suite,
    simde_sse2_emul_test_suite,
    simde_sse2_cmp_test_suite,

    simde_sse3_test_suite,
    simde_sse3_emul_test_suite,

    simde_ssse3_test_suite,
    simde_ssse3_emul_test_suite,

    simde_sse4_1_test_suite,
    simde_sse4_1_emul_test_suite,

    simde_sse4_2_test_suite,
    simde_sse4_2_emul_test_suite,

    simde_avx_test_suite,
    simde_avx_emul_test_suite,

    simde_avx2_test_suite,
    simde_avx2_emul_test_suite,
#endif

    { 0, },
  };

  MunitSuite simd_js_test_suites[] = {
    simde_simd_js_int32x4_test_suite,
    simde_simd_js_int32x4_emul_test_suite,
    simde_simd_js_int32x4_cmp_test_suite,
    simde_simd_js_float32x4_test_suite,
    { 0, },
  };

  MunitSuite arm_test_suites[] = {
#if !defined(DISABLE_ARM)
    simde_neon_vadd_test_suite,
    simde_neon_vadd_emul_test_suite,

    simde_neon_vdup_n_test_suite,
    simde_neon_vdup_n_emul_test_suite,
#endif
    { 0, },
  };

  MunitSuite test_suites[] = {
    { (char*) "/x86",
      NULL,
      x86_test_suites,
      1,
      MUNIT_SUITE_OPTION_NONE },

    { (char*) "/simd-js",
      NULL,
      simd_js_test_suites,
      1,
      MUNIT_SUITE_OPTION_NONE },

    { (char*) "/arm",
      NULL,
      arm_test_suites,
      1,
      MUNIT_SUITE_OPTION_NONE },
    { 0, },
  };

  MunitSuite test_suite = {
    NULL,
    test_suite_tests,
    test_suites,
    1,
    MUNIT_SUITE_OPTION_NONE
  };

  return munit_suite_main(&test_suite, NULL, argc, argv);
}
