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

#if defined(__SSE__)
#define SIMDE_SSE_NO_NATIVE
#include "../sse.h"
#include <xmmintrin.h>

#include "test-cmp.h"

define_test_cmp_f32_VT_2xVT(_m128, mm_add_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_add_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_and_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_andnot_ps)
define_test_cmp_VT_2xVT(_m64, mm_avg_pu16, u16)
define_test_cmp_VT_2xVT(_m64, mm_avg_pu8, u8)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpeq_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpeq_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpge_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpge_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpgt_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpgt_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmple_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmple_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmplt_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmplt_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpneq_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpneq_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpnge_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpnge_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpngt_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpngt_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpnle_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpnle_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpnlt_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpnlt_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpord_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpord_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpunord_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_cmpunord_ss)
define_test_cmp_s_2xVT(_m128, mm_comige_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_comigt_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_comile_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_comilt_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_comieq_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_comineq_ss, int, int)
define_test_cmp_VT_VT1_VT2(_m128, _m128, _m64, mm_cvt_pi2ps, u32)
define_test_cmp_f32_VT_2xVT(_m128, mm_div_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_div_ss)
define_test_cmp_f32_VT_VT(_m128, mm_sqrt_ps)
define_test_cmp_f32_VT_VT(_m128, mm_sqrt_ss)
define_test_cmp_f32_VT_2xVT(_m128, mm_sub_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_sub_ss)
define_test_cmp_s_2xVT(_m128, mm_ucomige_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_ucomigt_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_ucomile_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_ucomilt_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_ucomieq_ss, int, int)
define_test_cmp_s_2xVT(_m128, mm_ucomineq_ss, int, int)
define_test_cmp_f32_VT_2xVT(_m128, mm_unpackhi_ps)
define_test_cmp_f32_VT_2xVT(_m128, mm_unpacklo_ps)
define_test_cmp_VT_2xVT(_m128, mm_or_ps, u32)
define_test_cmp_VT_2xVT(_m128, mm_xor_ps, u32)

static MunitTest test_suite_tests[] = {
  { (char*) "/mm_add_ps",       test_simde_mm_add_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_ss",       test_simde_mm_add_ss,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_and_ps",       test_simde_mm_and_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_andnot_ps",    test_simde_mm_andnot_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_avg_pu16",     test_simde_mm_avg_pu16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_avg_pu8",      test_simde_mm_avg_pu8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_ps",     test_simde_mm_cmpeq_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_ss",     test_simde_mm_cmpeq_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpge_ps",     test_simde_mm_cmpge_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
#if !defined(__PGI)
  { (char*) "/mm_cmpge_ss",     test_simde_mm_cmpge_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_ss",     test_simde_mm_cmpgt_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnge_ss",    test_simde_mm_cmpnge_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpngt_ss",    test_simde_mm_cmpngt_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpunord_ss",  test_simde_mm_cmpunord_ss,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
#endif
  { (char*) "/mm_cmpgt_ps",     test_simde_mm_cmpgt_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmple_ps",     test_simde_mm_cmple_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmple_ss",     test_simde_mm_cmple_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmplt_ps",     test_simde_mm_cmplt_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmplt_ss",     test_simde_mm_cmplt_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpneq_ps",    test_simde_mm_cmpneq_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpneq_ss",    test_simde_mm_cmpneq_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnge_ps",    test_simde_mm_cmpnge_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpngt_ps",    test_simde_mm_cmpngt_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnle_ps",    test_simde_mm_cmpnle_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnle_ss",    test_simde_mm_cmpnle_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnlt_ps",    test_simde_mm_cmpnlt_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnlt_ss",    test_simde_mm_cmpnlt_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpord_ps",    test_simde_mm_cmpord_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpord_ss",    test_simde_mm_cmpord_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpunord_ps",  test_simde_mm_cmpunord_ps,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_comige_ss",    test_simde_mm_comige_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_comigt_ss",    test_simde_mm_comigt_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_comile_ss",    test_simde_mm_comile_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_comilt_ss",    test_simde_mm_comilt_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_comieq_ss",    test_simde_mm_comieq_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_comineq_ss",   test_simde_mm_comineq_ss,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvt_pi2ps",    test_simde_mm_cvt_pi2ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_div_ps",       test_simde_mm_div_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_div_ss",       test_simde_mm_div_ss,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sqrt_ps",      test_simde_mm_sqrt_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sqrt_ss",      test_simde_mm_sqrt_ss,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_ps",       test_simde_mm_sub_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_ss",       test_simde_mm_sub_ss,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_ucomige_ss",   test_simde_mm_ucomige_ss,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_ucomigt_ss",   test_simde_mm_ucomigt_ss,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_ucomile_ss",   test_simde_mm_ucomile_ss,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_ucomilt_ss",   test_simde_mm_ucomilt_ss,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_ucomieq_ss",   test_simde_mm_ucomieq_ss,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_ucomineq_ss",  test_simde_mm_ucomineq_ss,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_unpackhi_ps",  test_simde_mm_unpackhi_ps,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_unpacklo_ps",  test_simde_mm_unpacklo_ps,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_or_ps",        test_simde_mm_or_ps,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_xor_ps",       test_simde_mm_xor_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#else
static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#endif

MunitSuite simde_sse_test_suite = {
  (char*) "/sse",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
