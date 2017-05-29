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

#include <stdio.h>
#include <test/simd-js/simd-js.h>

#if defined(__EMSCRIPTEN__)
#define SIMDE_EM_NO_NATIVE
#include <simde/simd-js/simd-js.h>
#include <emscripten/vector.h>

SIMDE_JS_DEFINE_TEST_EM_BINARY (int32x4, add)
SIMDE_JS_DEFINE_TEST_EM_BINARY (int32x4, sub)
SIMDE_JS_DEFINE_TEST_EM_BINARY (int32x4, mul)
SIMDE_JS_DEFINE_TEST_EM_UNARY  (int32x4, neg)
SIMDE_JS_DEFINE_TEST_EM_BINARY (int32x4, and)
SIMDE_JS_DEFINE_TEST_EM_BINARY (int32x4, xor)
SIMDE_JS_DEFINE_TEST_EM_BINARY (int32x4, or)
SIMDE_JS_DEFINE_TEST_EM_COMPARE(int32x4, bool32x4, lessThan)
SIMDE_JS_DEFINE_TEST_EM_COMPARE(int32x4, bool32x4, lessThanOrEqual)
SIMDE_JS_DEFINE_TEST_EM_COMPARE(int32x4, bool32x4, greaterThan)
SIMDE_JS_DEFINE_TEST_EM_COMPARE(int32x4, bool32x4, greaterThanOrEqual)
SIMDE_JS_DEFINE_TEST_EM_COMPARE(int32x4, bool32x4, equal)
SIMDE_JS_DEFINE_TEST_EM_COMPARE(int32x4, bool32x4, notEqual)

static MunitTest test_suite_tests[] = {
  SIMD_JS_TEST_FUNC_CMP(int32x4, add),
  SIMD_JS_TEST_FUNC_CMP(int32x4, sub),
  SIMD_JS_TEST_FUNC_CMP(int32x4, mul),
  SIMD_JS_TEST_FUNC_CMP(int32x4, neg),
  SIMD_JS_TEST_FUNC_CMP(int32x4, and),
  SIMD_JS_TEST_FUNC_CMP(int32x4, xor),
  SIMD_JS_TEST_FUNC_CMP(int32x4, or),
  SIMD_JS_TEST_FUNC_CMP(int32x4, lessThan),
  SIMD_JS_TEST_FUNC_CMP(int32x4, lessThanOrEqual),
  SIMD_JS_TEST_FUNC_CMP(int32x4, greaterThan),
  SIMD_JS_TEST_FUNC_CMP(int32x4, greaterThanOrEqual),
  SIMD_JS_TEST_FUNC_CMP(int32x4, equal),
  SIMD_JS_TEST_FUNC_CMP(int32x4, notEqual),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#else
static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#endif

MunitSuite simde_simd_js_int32x4_cmp_test_suite = {
  (char*) "/int32x4",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
