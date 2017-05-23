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

#include <test/x86/x86-internal.h>
#include <stdio.h>

#if defined(__SSE2__)
#define SIMDE_SSE2_NO_NATIVE
#include <simde/x86/sse2.h>
#include <emmintrin.h>

#include <test/x86/compare.h>

define_test_cmp_VT_2xVT(_m128i, mm_add_epi8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_add_epi16, i16)
define_test_cmp_VT_2xVT(_m128i, mm_add_epi32, i32)
define_test_cmp_VT_2xVT(_m128i, mm_add_epi64, i64)
define_test_cmp_f64_VT_2xVT(_m128d, mm_add_pd)
define_test_cmp_f64_VT_2xVT(_m128d, mm_add_sd)
define_test_cmp_VT_2xVT(_m128i, mm_adds_epi8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_adds_epi16, i16)
define_test_cmp_VT_2xVT(_m128i, mm_adds_epu8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_adds_epu16, i16)
define_test_cmp_f64_VT_2xVT(_m128d, mm_and_pd)
define_test_cmp_f64_VT_2xVT(_m128d, mm_andnot_pd)
define_test_cmp_VT_2xVT(_m128i, mm_avg_epu8, u8)
define_test_cmp_VT_2xVT(_m128i, mm_avg_epu16, u16)
define_test_cmp_VT_2xVT(_m128i, mm_sub_epi8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_sub_epi16, i16)
define_test_cmp_VT_2xVT(_m128i, mm_sub_epi32, i32)
define_test_cmp_VT_2xVT(_m128i, mm_sub_epi64, i64)
define_test_cmp_f64_VT_2xVT(_m128d, mm_sub_pd)
define_test_cmp_f64_VT_2xVT(_m128d, mm_sub_sd)
define_test_cmp_VT_2xVT(_m128i, mm_subs_epi8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_subs_epi16, i16)
define_test_cmp_VT_2xVT(_m128i, mm_subs_epu8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_subs_epu16, i16)
define_test_cmp_VT_2xVT(_m128i, mm_madd_epi16, i32)
define_test_cmp_VT_2xVT(_m128i, mm_min_epi16, i16)
define_test_cmp_VT_2xVT(_m128i, mm_min_epu8, i8)
define_test_cmp_f64_VT_2xVT(_m128d, mm_min_pd)
define_test_cmp_f64_VT_2xVT(_m128d, mm_min_sd)
define_test_cmp_VT_2xVT(_m128i, mm_max_epi16, i16)
define_test_cmp_VT_2xVT(_m128i, mm_max_epu8, i8)
define_test_cmp_f64_VT_2xVT(_m128d, mm_max_pd)
define_test_cmp_f64_VT_2xVT(_m128d, mm_max_sd)

static MunitTest test_suite_tests[] = {
  TEST_FUNC_CMP(mm_add_epi8),
  TEST_FUNC_CMP(mm_add_epi16),
  TEST_FUNC_CMP(mm_add_epi32),
  TEST_FUNC_CMP(mm_add_epi64),
  TEST_FUNC_CMP(mm_add_pd),
  TEST_FUNC_CMP(mm_add_sd),
  TEST_FUNC_CMP(mm_adds_epi8),
  TEST_FUNC_CMP(mm_adds_epi16),
  TEST_FUNC_CMP(mm_adds_epu8),
  TEST_FUNC_CMP(mm_adds_epu16),
  TEST_FUNC_CMP(mm_and_pd),
  TEST_FUNC_CMP(mm_andnot_pd),
  TEST_FUNC_CMP(mm_avg_epu8),
  TEST_FUNC_CMP(mm_avg_epu16),
  TEST_FUNC_CMP(mm_madd_epi16),
  TEST_FUNC_CMP(mm_min_epi16),
  TEST_FUNC_CMP(mm_min_epu8),
  TEST_FUNC_CMP(mm_min_pd),
  TEST_FUNC_CMP(mm_min_sd),
  TEST_FUNC_CMP(mm_max_epi16),
  TEST_FUNC_CMP(mm_max_epu8),
  TEST_FUNC_CMP(mm_max_pd),
  TEST_FUNC_CMP(mm_max_sd),
  TEST_FUNC_CMP(mm_sub_epi8),
  TEST_FUNC_CMP(mm_sub_epi16),
  TEST_FUNC_CMP(mm_sub_epi32),
  TEST_FUNC_CMP(mm_sub_epi64),
  TEST_FUNC_CMP(mm_sub_pd),
  TEST_FUNC_CMP(mm_sub_sd),
  TEST_FUNC_CMP(mm_subs_epi8),
  TEST_FUNC_CMP(mm_subs_epi16),
  TEST_FUNC_CMP(mm_subs_epu8),
  TEST_FUNC_CMP(mm_subs_epu16),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#else
static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#endif

MunitSuite simde_sse2_cmp_test_suite = {
  (char*) "/sse2",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
