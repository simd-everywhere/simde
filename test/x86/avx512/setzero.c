/* SPDX-License-Identifier: MIT
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
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN setzero

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/set1.h>
#include <simde/x86/avx512/setzero.h>

static int
test_simde_mm512_setzero_si512(SIMDE_MUNIT_TEST_ARGS) {
  simde_assert_m512i_i32(simde_mm512_setzero_si512(), ==, simde_mm512_set1_epi32(INT32_C(0)));

  return 0;
}

static int
test_simde_mm512_setzero_ps(SIMDE_MUNIT_TEST_ARGS) {
  simde_assert_m512_close(simde_mm512_setzero_ps(), simde_mm512_set1_ps(SIMDE_FLOAT32_C(0.0)), 1);

  return 0;
}

static int
test_simde_mm512_setzero_pd(SIMDE_MUNIT_TEST_ARGS) {
  simde_assert_m512d_close(simde_mm512_setzero_pd(), simde_mm512_set1_pd(SIMDE_FLOAT64_C(0.0)), 1);

  return 0;
}

static int
test_simde_mm512_setzero_ph(SIMDE_MUNIT_TEST_ARGS) {
  simde_test_x86_assert_equal_f16x32(simde_mm512_setzero_ph(), simde_mm512_set1_ph(SIMDE_FLOAT16_VALUE(0.0)), 1);

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_setzero_si512)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_setzero_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_setzero_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_setzero_ph)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
