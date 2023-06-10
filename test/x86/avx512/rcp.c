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
 *   2020      Christopher Moore <moore@free.fr>
 */

#define SIMDE_TEST_X86_AVX512_INSN rcp

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/rcp.h>

static int
test_simde_mm512_rcp14_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.31), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(     0.27),
        SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(     0.06), SIMDE_FLOAT32_C(     0.27),
        SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(     0.20), SIMDE_FLOAT32_C(     0.87), SIMDE_FLOAT32_C(     0.07),
        SIMDE_FLOAT32_C(    -0.76), SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(    -0.50) },
      { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     3.23), SIMDE_FLOAT32_C(    -4.17), SIMDE_FLOAT32_C(     3.70),
        SIMDE_FLOAT32_C(     2.94), SIMDE_FLOAT32_C(    -1.32), SIMDE_FLOAT32_C(    16.67), SIMDE_FLOAT32_C(     3.70),
        SIMDE_FLOAT32_C(    -1.19), SIMDE_FLOAT32_C(     5.00), SIMDE_FLOAT32_C(     1.15), SIMDE_FLOAT32_C(    14.29),
        SIMDE_FLOAT32_C(    -1.32), SIMDE_FLOAT32_C(     5.56), SIMDE_FLOAT32_C(    10.00), SIMDE_FLOAT32_C(    -2.00) } },
    { { SIMDE_FLOAT32_C(    -0.37), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(     0.34), SIMDE_FLOAT32_C(    -0.49),
        SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(    -0.04), SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(     0.95),
        SIMDE_FLOAT32_C(    -0.16), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    -0.21), SIMDE_FLOAT32_C(    -0.59),
        SIMDE_FLOAT32_C(     0.73), SIMDE_FLOAT32_C(    -0.65), SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(     0.73) },
      { SIMDE_FLOAT32_C(    -2.70), SIMDE_FLOAT32_C(     1.01), SIMDE_FLOAT32_C(     2.94), SIMDE_FLOAT32_C(    -2.04),
        SIMDE_FLOAT32_C(    -1.45), SIMDE_FLOAT32_C(   -25.00), SIMDE_FLOAT32_C(    -1.54), SIMDE_FLOAT32_C(     1.05),
        SIMDE_FLOAT32_C(    -6.25), SIMDE_FLOAT32_C(    -1.16), SIMDE_FLOAT32_C(    -4.76), SIMDE_FLOAT32_C(    -1.69),
        SIMDE_FLOAT32_C(     1.37), SIMDE_FLOAT32_C(    -1.54), SIMDE_FLOAT32_C(     1.64), SIMDE_FLOAT32_C(     1.37) } },
    { { SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(     0.33), SIMDE_FLOAT32_C(    -0.54), SIMDE_FLOAT32_C(     0.24),
        SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(     0.19), SIMDE_FLOAT32_C(     0.13),
        SIMDE_FLOAT32_C(    -0.05), SIMDE_FLOAT32_C(     0.98), SIMDE_FLOAT32_C(     0.54), SIMDE_FLOAT32_C(    -0.32),
        SIMDE_FLOAT32_C(    -0.67), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(    -0.59), SIMDE_FLOAT32_C(     0.99) },
      { SIMDE_FLOAT32_C(   -14.29), SIMDE_FLOAT32_C(     3.03), SIMDE_FLOAT32_C(    -1.85), SIMDE_FLOAT32_C(     4.17),
        SIMDE_FLOAT32_C(    -1.41), SIMDE_FLOAT32_C(    -5.26), SIMDE_FLOAT32_C(     5.26), SIMDE_FLOAT32_C(     7.69),
        SIMDE_FLOAT32_C(   -20.00), SIMDE_FLOAT32_C(     1.02), SIMDE_FLOAT32_C(     1.85), SIMDE_FLOAT32_C(    -3.12),
        SIMDE_FLOAT32_C(    -1.49), SIMDE_FLOAT32_C(     7.14), SIMDE_FLOAT32_C(    -1.69), SIMDE_FLOAT32_C(     1.01) } },
    { { SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(    -0.88),
        SIMDE_FLOAT32_C(     0.45), SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(    -0.12), SIMDE_FLOAT32_C(    -0.30),
        SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(    -0.29), SIMDE_FLOAT32_C(    -0.80), SIMDE_FLOAT32_C(    -0.29),
        SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(    -0.81), SIMDE_FLOAT32_C(    -0.34), SIMDE_FLOAT32_C(    -0.42) },
      { SIMDE_FLOAT32_C(     1.96), SIMDE_FLOAT32_C(     2.50), SIMDE_FLOAT32_C(  -100.00), SIMDE_FLOAT32_C(    -1.14),
        SIMDE_FLOAT32_C(     2.22), SIMDE_FLOAT32_C(     4.00), SIMDE_FLOAT32_C(    -8.33), SIMDE_FLOAT32_C(    -3.33),
        SIMDE_FLOAT32_C(     2.56), SIMDE_FLOAT32_C(    -3.45), SIMDE_FLOAT32_C(    -1.25), SIMDE_FLOAT32_C(    -3.45),
        SIMDE_FLOAT32_C(     1.54), SIMDE_FLOAT32_C(    -1.23), SIMDE_FLOAT32_C(    -2.94), SIMDE_FLOAT32_C(    -2.38) } },
    { { SIMDE_FLOAT32_C(     0.76), SIMDE_FLOAT32_C(    -0.49), SIMDE_FLOAT32_C(     0.49), SIMDE_FLOAT32_C(     0.55),
        SIMDE_FLOAT32_C(    -0.83), SIMDE_FLOAT32_C(    -0.95), SIMDE_FLOAT32_C(     0.91), SIMDE_FLOAT32_C(    -0.04),
        SIMDE_FLOAT32_C(     0.86), SIMDE_FLOAT32_C(    -0.87), SIMDE_FLOAT32_C(     0.15), SIMDE_FLOAT32_C(     0.88),
        SIMDE_FLOAT32_C(    -0.78), SIMDE_FLOAT32_C(    -0.39), SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(    -0.29) },
      { SIMDE_FLOAT32_C(     1.32), SIMDE_FLOAT32_C(    -2.04), SIMDE_FLOAT32_C(     2.04), SIMDE_FLOAT32_C(     1.82),
        SIMDE_FLOAT32_C(    -1.20), SIMDE_FLOAT32_C(    -1.05), SIMDE_FLOAT32_C(     1.10), SIMDE_FLOAT32_C(   -25.00),
        SIMDE_FLOAT32_C(     1.16), SIMDE_FLOAT32_C(    -1.15), SIMDE_FLOAT32_C(     6.67), SIMDE_FLOAT32_C(     1.14),
        SIMDE_FLOAT32_C(    -1.28), SIMDE_FLOAT32_C(    -2.56), SIMDE_FLOAT32_C(     1.54), SIMDE_FLOAT32_C(    -3.45) } },
    { { SIMDE_FLOAT32_C(     0.51), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(     0.80),
        SIMDE_FLOAT32_C(     0.93), SIMDE_FLOAT32_C(     0.01), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(    -0.12),
        SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(     0.56), SIMDE_FLOAT32_C(     0.31),
        SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(     0.97), SIMDE_FLOAT32_C(     0.31), SIMDE_FLOAT32_C(     0.12) },
      { SIMDE_FLOAT32_C(     1.96), SIMDE_FLOAT32_C(     8.33), SIMDE_FLOAT32_C(     1.22), SIMDE_FLOAT32_C(     1.25),
        SIMDE_FLOAT32_C(     1.08), SIMDE_FLOAT32_C(   100.00), SIMDE_FLOAT32_C(   -14.29), SIMDE_FLOAT32_C(    -8.33),
        SIMDE_FLOAT32_C(   -50.00), SIMDE_FLOAT32_C(    -1.89), SIMDE_FLOAT32_C(     1.79), SIMDE_FLOAT32_C(     3.23),
        SIMDE_FLOAT32_C(     1.64), SIMDE_FLOAT32_C(     1.03), SIMDE_FLOAT32_C(     3.23), SIMDE_FLOAT32_C(     8.33) } },
    { { SIMDE_FLOAT32_C(     0.37), SIMDE_FLOAT32_C(    -0.70), SIMDE_FLOAT32_C(     0.24), SIMDE_FLOAT32_C(    -0.18),
        SIMDE_FLOAT32_C(     0.55), SIMDE_FLOAT32_C(    -0.87), SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(    -0.06),
        SIMDE_FLOAT32_C(    -0.16), SIMDE_FLOAT32_C(     0.72), SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(    -0.51),
        SIMDE_FLOAT32_C(     0.91), SIMDE_FLOAT32_C(    -0.69), SIMDE_FLOAT32_C(     0.07), SIMDE_FLOAT32_C(     0.43) },
      { SIMDE_FLOAT32_C(     2.70), SIMDE_FLOAT32_C(    -1.43), SIMDE_FLOAT32_C(     4.17), SIMDE_FLOAT32_C(    -5.56),
        SIMDE_FLOAT32_C(     1.82), SIMDE_FLOAT32_C(    -1.15), SIMDE_FLOAT32_C(     1.89), SIMDE_FLOAT32_C(   -16.67),
        SIMDE_FLOAT32_C(    -6.25), SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(     1.54), SIMDE_FLOAT32_C(    -1.96),
        SIMDE_FLOAT32_C(     1.10), SIMDE_FLOAT32_C(    -1.45), SIMDE_FLOAT32_C(    14.29), SIMDE_FLOAT32_C(     2.33) } },
    { { SIMDE_FLOAT32_C(     0.42), SIMDE_FLOAT32_C(    -0.12), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.35),
        SIMDE_FLOAT32_C(     0.89), SIMDE_FLOAT32_C(    -0.84), SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    -0.12),
        SIMDE_FLOAT32_C(    -0.37), SIMDE_FLOAT32_C(     0.80), SIMDE_FLOAT32_C(    -0.81), SIMDE_FLOAT32_C(    -0.76),
        SIMDE_FLOAT32_C(     0.77), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(     0.14) },
      { SIMDE_FLOAT32_C(     2.38), SIMDE_FLOAT32_C(    -8.33), SIMDE_FLOAT32_C(     4.35), SIMDE_FLOAT32_C(     2.86),
        SIMDE_FLOAT32_C(     1.12), SIMDE_FLOAT32_C(    -1.19), SIMDE_FLOAT32_C(    -1.30), SIMDE_FLOAT32_C(    -8.33),
        SIMDE_FLOAT32_C(    -2.70), SIMDE_FLOAT32_C(     1.25), SIMDE_FLOAT32_C(    -1.23), SIMDE_FLOAT32_C(    -1.32),
        SIMDE_FLOAT32_C(     1.30), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(     2.78), SIMDE_FLOAT32_C(     7.14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 r = simde_mm512_rcp14_ps(a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1.0), SIMDE_FLOAT32_C(1.0));
    // TODO: generate smaller floating point numbers and test with greater accuracy
    // as rcp14 is defined as "The maximum relative error for this approximation is less than 2^-14."
    simde__m512 r = simde_mm512_rcp14_ps(a);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_rcp14_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
