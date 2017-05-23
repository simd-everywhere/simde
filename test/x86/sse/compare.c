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

#if defined(__SSE__)
#define SIMDE_SSE_NO_NATIVE
#include <simde/x86/sse.h>
#include <xmmintrin.h>

#include <test/x86/compare.h>

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

#define TEST_FUNC_CMP(name) \
  { (char*) "/" #name "/cmp", test_simde_##name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

static MunitTest test_suite_tests[] = {
  TEST_FUNC_CMP(mm_add_ps),
  TEST_FUNC_CMP(mm_add_ss),
  TEST_FUNC_CMP(mm_and_ps),
  TEST_FUNC_CMP(mm_andnot_ps),
  TEST_FUNC_CMP(mm_avg_pu16),
  TEST_FUNC_CMP(mm_avg_pu8),
  TEST_FUNC_CMP(mm_cmpeq_ps),
  TEST_FUNC_CMP(mm_cmpeq_ss),
  TEST_FUNC_CMP(mm_cmpge_ps),
#if !defined(__PGI)
  TEST_FUNC_CMP(mm_cmpge_ss),
  TEST_FUNC_CMP(mm_cmpgt_ss),
  TEST_FUNC_CMP(mm_cmpnge_ss),
  TEST_FUNC_CMP(mm_cmpngt_ss),
  TEST_FUNC_CMP(mm_cmpunord_ss),
#endif
  TEST_FUNC_CMP(mm_cmpgt_ps),
  TEST_FUNC_CMP(mm_cmple_ps),
  TEST_FUNC_CMP(mm_cmple_ss),
  TEST_FUNC_CMP(mm_cmplt_ps),
  TEST_FUNC_CMP(mm_cmplt_ss),
  TEST_FUNC_CMP(mm_cmpneq_ps),
  TEST_FUNC_CMP(mm_cmpneq_ss),
  TEST_FUNC_CMP(mm_cmpnge_ps),
  TEST_FUNC_CMP(mm_cmpngt_ps),
  TEST_FUNC_CMP(mm_cmpnle_ps),
  TEST_FUNC_CMP(mm_cmpnle_ss),
  TEST_FUNC_CMP(mm_cmpnlt_ps),
  TEST_FUNC_CMP(mm_cmpnlt_ss),
  TEST_FUNC_CMP(mm_cmpord_ps),
  TEST_FUNC_CMP(mm_cmpord_ss),
  TEST_FUNC_CMP(mm_cmpunord_ps),
  TEST_FUNC_CMP(mm_comige_ss),
  TEST_FUNC_CMP(mm_comigt_ss),
  TEST_FUNC_CMP(mm_comile_ss),
  TEST_FUNC_CMP(mm_comilt_ss),
  TEST_FUNC_CMP(mm_comieq_ss),
  TEST_FUNC_CMP(mm_comineq_ss),
  TEST_FUNC_CMP(mm_cvt_pi2ps),
  TEST_FUNC_CMP(mm_div_ps),
  TEST_FUNC_CMP(mm_div_ss),
  TEST_FUNC_CMP(mm_sqrt_ps),
  TEST_FUNC_CMP(mm_sqrt_ss),
  TEST_FUNC_CMP(mm_sub_ps),
  TEST_FUNC_CMP(mm_sub_ss),
  TEST_FUNC_CMP(mm_ucomige_ss),
  TEST_FUNC_CMP(mm_ucomigt_ss),
  TEST_FUNC_CMP(mm_ucomile_ss),
  TEST_FUNC_CMP(mm_ucomilt_ss),
  TEST_FUNC_CMP(mm_ucomieq_ss),
  TEST_FUNC_CMP(mm_ucomineq_ss),
  TEST_FUNC_CMP(mm_unpackhi_ps),
  TEST_FUNC_CMP(mm_unpacklo_ps),
  TEST_FUNC_CMP(mm_or_ps),
  TEST_FUNC_CMP(mm_xor_ps),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#else
static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#endif

MunitSuite simde_sse_cmp_test_suite = {
  (char*) "/sse",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
