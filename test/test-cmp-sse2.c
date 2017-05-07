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
#include <stdio.h>

#if defined(__SSE2__)
#define SIMDE_SSE2_NO_NATIVE
#include "../sse2.h"
#include <emmintrin.h>

#include "test-cmp.h"

define_test_cmp_VT_2xVT(_m128i, mm_add_epi8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_add_epi16, i8)
define_test_cmp_VT_2xVT(_m128i, mm_add_epi32, i8)
define_test_cmp_VT_2xVT(_m128i, mm_add_epi64, i8)
define_test_cmp_f64_VT_2xVT(_m128d, mm_add_pd)
define_test_cmp_f64_VT_2xVT(_m128d, mm_add_sd)
define_test_cmp_VT_2xVT(_m128i, mm_adds_epi8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_adds_epi16, i8)
define_test_cmp_VT_2xVT(_m128i, mm_adds_epu8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_adds_epu16, i8)
define_test_cmp_f64_VT_2xVT(_m128d, mm_and_pd)
define_test_cmp_f64_VT_2xVT(_m128d, mm_andnot_pd)
define_test_cmp_VT_2xVT(_m128i, mm_avg_epu8, u8)
define_test_cmp_VT_2xVT(_m128i, mm_avg_epu16, u16)
define_test_cmp_VT_2xVT(_m128i, mm_sub_epi8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_sub_epi16, i8)
define_test_cmp_VT_2xVT(_m128i, mm_sub_epi32, i8)
define_test_cmp_VT_2xVT(_m128i, mm_sub_epi64, i8)
define_test_cmp_f64_VT_2xVT(_m128d, mm_sub_pd)
define_test_cmp_f64_VT_2xVT(_m128d, mm_sub_sd)
define_test_cmp_VT_2xVT(_m128i, mm_subs_epi8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_subs_epi16, i8)
define_test_cmp_VT_2xVT(_m128i, mm_subs_epu8, i8)
define_test_cmp_VT_2xVT(_m128i, mm_subs_epu16, i8)

static MunitTest test_suite_tests[] = {
  { (char*) "/mm_add_epi8",       test_simde_mm_add_epi8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_epi16",      test_simde_mm_add_epi16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_epi32",      test_simde_mm_add_epi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_epi64",      test_simde_mm_add_epi64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_pd",         test_simde_mm_add_pd,         NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_sd",         test_simde_mm_add_sd,         NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_epi8",      test_simde_mm_adds_epi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_epi16",     test_simde_mm_adds_epi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_epu8",      test_simde_mm_adds_epu8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_epu16",     test_simde_mm_adds_epu16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_and_pd",         test_simde_mm_and_pd,         NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_andnot_pd",      test_simde_mm_andnot_pd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_avg_epu8",       test_simde_mm_avg_epu8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_avg_epu16",      test_simde_mm_avg_epu16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_epi8",       test_simde_mm_sub_epi8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_epi16",      test_simde_mm_sub_epi16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_epi32",      test_simde_mm_sub_epi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_epi64",      test_simde_mm_sub_epi64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_pd",         test_simde_mm_sub_pd,         NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_sd",         test_simde_mm_sub_sd,         NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_epi8",      test_simde_mm_subs_epi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_epi16",     test_simde_mm_subs_epi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_epu8",      test_simde_mm_subs_epu8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_epu16",     test_simde_mm_subs_epu16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#else
static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#endif

const MunitSuite simde_sse2_test_suite = {
  (char*) "/sse2",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
