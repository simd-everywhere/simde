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
 *   2023      Michael R. Crusoe <crusoe@debian.org>
 */

#define SIMDE_TEST_X86_AVX512_INSN knand

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/kand.h>

static int
test_simde_mm512_kand (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 a;
    const simde__mmask16 b;
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(33740),
      UINT16_C(60209),
      UINT16_C(33536) },
    { UINT16_C(46020),
      UINT16_C(24332),
      UINT16_C( 4868) },
    { UINT16_C(13269),
      UINT16_C(65007),
      UINT16_C(12741) },
    { UINT16_C(64804),
      UINT16_C( 8743),
      UINT16_C( 8228) },
    { UINT16_C(58611),
      UINT16_C(55107),
      UINT16_C(50243) },
    { UINT16_C(60104),
      UINT16_C(13905),
      UINT16_C( 8768) },
    { UINT16_C(24513),
      UINT16_C(17751),
      UINT16_C(17729) },
    { UINT16_C(15289),
      UINT16_C(34084),
      UINT16_C(  288) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 r = simde_mm512_kand(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 a = simde_test_x86_random_mmask16();
    simde__mmask16 b = simde_test_x86_random_mmask16();
    simde__mmask16 r = simde_mm512_kand(a, b);

    simde_test_x86_write_mmask16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_kand)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
