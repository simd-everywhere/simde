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
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 */

#define SIMDE_TEST_X86_AVX512_INSN set1

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set1.h>

static int
test_simde_mm512_set1_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a;
    const simde_float32 r[16];
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -130.28),
      { SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28),
        SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28),
        SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28),
        SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28), SIMDE_FLOAT32_C(  -130.28) } },
    { SIMDE_FLOAT32_C(   996.56),
      { SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56),
        SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56),
        SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56),
        SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56), SIMDE_FLOAT32_C(   996.56) } },
    { SIMDE_FLOAT32_C(  -437.56),
      { SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56),
        SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56),
        SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56),
        SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56), SIMDE_FLOAT32_C(  -437.56) } },
    { SIMDE_FLOAT32_C(  -653.34),
      { SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34),
        SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34),
        SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34),
        SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34), SIMDE_FLOAT32_C(  -653.34) } },
    { SIMDE_FLOAT32_C(  -547.09),
      { SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09),
        SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09),
        SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09),
        SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -547.09) } },
    { SIMDE_FLOAT32_C(  -670.08),
      { SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08),
        SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08),
        SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08),
        SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08), SIMDE_FLOAT32_C(  -670.08) } },
    { SIMDE_FLOAT32_C(  -380.10),
      { SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10),
        SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10),
        SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10),
        SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10), SIMDE_FLOAT32_C(  -380.10) } },
    { SIMDE_FLOAT32_C(   -89.44),
      { SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44),
        SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44),
        SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44),
        SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44), SIMDE_FLOAT32_C(   -89.44) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 r = simde_mm512_set1_ps(test_vec[i].a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_set1_ps(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_set1_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64 a;
    simde__m512d r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C( -426.34),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -426.34), SIMDE_FLOAT64_C( -426.34),
                         SIMDE_FLOAT64_C( -426.34), SIMDE_FLOAT64_C( -426.34),
                         SIMDE_FLOAT64_C( -426.34), SIMDE_FLOAT64_C( -426.34),
                         SIMDE_FLOAT64_C( -426.34), SIMDE_FLOAT64_C( -426.34)) },
    { SIMDE_FLOAT64_C(  122.65),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  122.65), SIMDE_FLOAT64_C(  122.65),
                         SIMDE_FLOAT64_C(  122.65), SIMDE_FLOAT64_C(  122.65),
                         SIMDE_FLOAT64_C(  122.65), SIMDE_FLOAT64_C(  122.65),
                         SIMDE_FLOAT64_C(  122.65), SIMDE_FLOAT64_C(  122.65)) },
    { SIMDE_FLOAT64_C(  879.85),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  879.85), SIMDE_FLOAT64_C(  879.85),
                         SIMDE_FLOAT64_C(  879.85), SIMDE_FLOAT64_C(  879.85),
                         SIMDE_FLOAT64_C(  879.85), SIMDE_FLOAT64_C(  879.85),
                         SIMDE_FLOAT64_C(  879.85), SIMDE_FLOAT64_C(  879.85)) },
    { SIMDE_FLOAT64_C(  301.17),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  301.17), SIMDE_FLOAT64_C(  301.17),
                         SIMDE_FLOAT64_C(  301.17), SIMDE_FLOAT64_C(  301.17),
                         SIMDE_FLOAT64_C(  301.17), SIMDE_FLOAT64_C(  301.17),
                         SIMDE_FLOAT64_C(  301.17), SIMDE_FLOAT64_C(  301.17)) },
    { SIMDE_FLOAT64_C( -341.96),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -341.96), SIMDE_FLOAT64_C( -341.96),
                         SIMDE_FLOAT64_C( -341.96), SIMDE_FLOAT64_C( -341.96),
                         SIMDE_FLOAT64_C( -341.96), SIMDE_FLOAT64_C( -341.96),
                         SIMDE_FLOAT64_C( -341.96), SIMDE_FLOAT64_C( -341.96)) },
    { SIMDE_FLOAT64_C( -854.60),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -854.60), SIMDE_FLOAT64_C( -854.60),
                         SIMDE_FLOAT64_C( -854.60), SIMDE_FLOAT64_C( -854.60),
                         SIMDE_FLOAT64_C( -854.60), SIMDE_FLOAT64_C( -854.60),
                         SIMDE_FLOAT64_C( -854.60), SIMDE_FLOAT64_C( -854.60)) },
    { SIMDE_FLOAT64_C(  711.48),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  711.48), SIMDE_FLOAT64_C(  711.48),
                         SIMDE_FLOAT64_C(  711.48), SIMDE_FLOAT64_C(  711.48),
                         SIMDE_FLOAT64_C(  711.48), SIMDE_FLOAT64_C(  711.48),
                         SIMDE_FLOAT64_C(  711.48), SIMDE_FLOAT64_C(  711.48)) },
    { SIMDE_FLOAT64_C( -146.85),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -146.85), SIMDE_FLOAT64_C( -146.85),
                         SIMDE_FLOAT64_C( -146.85), SIMDE_FLOAT64_C( -146.85),
                         SIMDE_FLOAT64_C( -146.85), SIMDE_FLOAT64_C( -146.85),
                         SIMDE_FLOAT64_C( -146.85), SIMDE_FLOAT64_C( -146.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_set1_pd(test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_set1_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int8_t a;
    simde__m512i r;
  } test_vec[8] = {
    {   15,
      simde_mm512_set_epi8(INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
                           INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15)) },
    {  124,
      simde_mm512_set_epi8(INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124),
                           INT8_C( 124), INT8_C( 124), INT8_C( 124), INT8_C( 124)) },
    {  -93,
      simde_mm512_set_epi8(INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93),
                           INT8_C( -93), INT8_C( -93), INT8_C( -93), INT8_C( -93)) },
    {  121,
      simde_mm512_set_epi8(INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121),
                           INT8_C( 121), INT8_C( 121), INT8_C( 121), INT8_C( 121)) },
    {  117,
      simde_mm512_set_epi8(INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117),
                           INT8_C( 117), INT8_C( 117), INT8_C( 117), INT8_C( 117)) },
    {   93,
      simde_mm512_set_epi8(INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93),
                           INT8_C(  93), INT8_C(  93), INT8_C(  93), INT8_C(  93)) },
    {   88,
      simde_mm512_set_epi8(INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88),
                           INT8_C(  88), INT8_C(  88), INT8_C(  88), INT8_C(  88)) },
    {  -73,
      simde_mm512_set_epi8(INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73)) }
  };


  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_set1_epi8(test_vec[i].a);
    simde_assert_m512i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_set1_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask64 k;
    int8_t a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi8(INT8_C(  80), INT8_C(  13), INT8_C( -86), INT8_C( 103),
                           INT8_C(  30), INT8_C(  88), INT8_C( -63), INT8_C( -16),
                           INT8_C( -68), INT8_C( -20), INT8_C(  48), INT8_C( -36),
                           INT8_C( -97), INT8_C(-103), INT8_C(-104), INT8_C( -61),
                           INT8_C(-122), INT8_C( -83), INT8_C(  -3), INT8_C(-115),
                           INT8_C(  29), INT8_C(-112), INT8_C( 118), INT8_C(  53),
                           INT8_C(-107), INT8_C(-126), INT8_C(  41), INT8_C(-117),
                           INT8_C(  -4), INT8_C( -72), INT8_C(  -9), INT8_C(   2),
                           INT8_C(  10), INT8_C( -61), INT8_C( 116), INT8_C(   1),
                           INT8_C(  35), INT8_C( -78), INT8_C(  17), INT8_C( -82),
                           INT8_C( -14), INT8_C( 120), INT8_C( 120), INT8_C(  33),
                           INT8_C(  97), INT8_C(   4), INT8_C(-104), INT8_C(  67),
                           INT8_C( -86), INT8_C( -90), INT8_C( -95), INT8_C(  51),
                           INT8_C( -83), INT8_C(-120), INT8_C( 123), INT8_C(  -4),
                           INT8_C(  51), INT8_C( -66), INT8_C( -91), INT8_C(  51),
                           INT8_C(  -1), INT8_C(  32), INT8_C(  30), INT8_C(  92)),
      UINT64_C(12701675613368776088),
      INT8_C( -94),
      simde_mm512_set_epi8(INT8_C( -94), INT8_C(  13), INT8_C( -94), INT8_C( -94),
                           INT8_C(  30), INT8_C(  88), INT8_C( -63), INT8_C( -16),
                           INT8_C( -68), INT8_C( -94), INT8_C(  48), INT8_C( -36),
                           INT8_C( -97), INT8_C( -94), INT8_C(-104), INT8_C( -94),
                           INT8_C(-122), INT8_C( -94), INT8_C( -94), INT8_C(-115),
                           INT8_C( -94), INT8_C(-112), INT8_C( -94), INT8_C(  53),
                           INT8_C( -94), INT8_C(-126), INT8_C( -94), INT8_C(-117),
                           INT8_C( -94), INT8_C( -94), INT8_C(  -9), INT8_C(   2),
                           INT8_C( -94), INT8_C( -61), INT8_C( 116), INT8_C(   1),
                           INT8_C( -94), INT8_C( -78), INT8_C( -94), INT8_C( -94),
                           INT8_C( -14), INT8_C( 120), INT8_C( 120), INT8_C( -94),
                           INT8_C(  97), INT8_C( -94), INT8_C( -94), INT8_C(  67),
                           INT8_C( -86), INT8_C( -94), INT8_C( -94), INT8_C( -94),
                           INT8_C( -83), INT8_C( -94), INT8_C( 123), INT8_C( -94),
                           INT8_C( -94), INT8_C( -66), INT8_C( -91), INT8_C( -94),
                           INT8_C( -94), INT8_C(  32), INT8_C(  30), INT8_C(  92)) },
    { simde_mm512_set_epi8(INT8_C( -64), INT8_C( -80), INT8_C(  33), INT8_C(  -9),
                           INT8_C(   3), INT8_C(  93), INT8_C(  13), INT8_C( -28),
                           INT8_C(  79), INT8_C(  10), INT8_C( -42), INT8_C(-127),
                           INT8_C( 114), INT8_C(  78), INT8_C(  61), INT8_C(  67),
                           INT8_C(  95), INT8_C(  14), INT8_C(  28), INT8_C(  56),
                           INT8_C(  43), INT8_C( -20), INT8_C( -77), INT8_C(  83),
                           INT8_C( -68), INT8_C(  87), INT8_C( -96), INT8_C(  13),
                           INT8_C(  40), INT8_C( 107), INT8_C( -63), INT8_C(  -1),
                           INT8_C(  77), INT8_C(  21), INT8_C( -46), INT8_C( -12),
                           INT8_C(  42), INT8_C(  69), INT8_C(  51), INT8_C(  11),
                           INT8_C(-120), INT8_C(  65), INT8_C( -70), INT8_C( -19),
                           INT8_C( -95), INT8_C(  43), INT8_C(  -2), INT8_C( -62),
                           INT8_C( -16), INT8_C(  28), INT8_C(  29), INT8_C( -11),
                           INT8_C(  17), INT8_C( -18), INT8_C( 105), INT8_C(-119),
                           INT8_C(  60), INT8_C( 120), INT8_C(  38), INT8_C( -41),
                           INT8_C(  20), INT8_C( -30), INT8_C(  15), INT8_C( 112)),
      UINT64_C(15052494645983188959),
      INT8_C( -73),
      simde_mm512_set_epi8(INT8_C( -73), INT8_C( -73), INT8_C(  33), INT8_C( -73),
                           INT8_C(   3), INT8_C(  93), INT8_C(  13), INT8_C( -28),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C(-127),
                           INT8_C( 114), INT8_C( -73), INT8_C(  61), INT8_C( -73),
                           INT8_C(  95), INT8_C(  14), INT8_C( -73), INT8_C( -73),
                           INT8_C(  43), INT8_C( -73), INT8_C( -77), INT8_C(  83),
                           INT8_C( -68), INT8_C(  87), INT8_C( -73), INT8_C(  13),
                           INT8_C(  40), INT8_C( 107), INT8_C( -63), INT8_C( -73),
                           INT8_C(  77), INT8_C(  21), INT8_C( -46), INT8_C( -12),
                           INT8_C(  42), INT8_C( -73), INT8_C(  51), INT8_C( -73),
                           INT8_C(-120), INT8_C( -73), INT8_C( -70), INT8_C( -19),
                           INT8_C( -73), INT8_C( -73), INT8_C(  -2), INT8_C( -62),
                           INT8_C( -16), INT8_C(  28), INT8_C(  29), INT8_C( -73),
                           INT8_C(  17), INT8_C( -73), INT8_C( -73), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C(  38), INT8_C( -73),
                           INT8_C( -73), INT8_C( -73), INT8_C( -73), INT8_C( -73)) },
    { simde_mm512_set_epi8(INT8_C( 107), INT8_C( 126), INT8_C( -33), INT8_C(  83),
                           INT8_C(  46), INT8_C(  62), INT8_C( -81), INT8_C(  33),
                           INT8_C( -68), INT8_C(-126), INT8_C( -41), INT8_C( 125),
                           INT8_C( -96), INT8_C( -20), INT8_C(  62), INT8_C( -19),
                           INT8_C(  29), INT8_C( -96), INT8_C(  68), INT8_C( 119),
                           INT8_C( -36), INT8_C( -62), INT8_C( -27), INT8_C(-112),
                           INT8_C(-123), INT8_C(  55), INT8_C(-119), INT8_C(  -4),
                           INT8_C(  58), INT8_C(  28), INT8_C( -84), INT8_C( -38),
                           INT8_C(   1), INT8_C( -25), INT8_C( 107), INT8_C( -63),
                           INT8_C( -86), INT8_C(  88), INT8_C(  36), INT8_C(  53),
                           INT8_C( 109), INT8_C( -36), INT8_C( -70), INT8_C(-125),
                           INT8_C(  -3), INT8_C(-109), INT8_C( 121), INT8_C( -63),
                           INT8_C( 113), INT8_C( -92), INT8_C(  -4), INT8_C(-105),
                           INT8_C( -65), INT8_C(  26), INT8_C( -36), INT8_C(  87),
                           INT8_C(-101), INT8_C( -70), INT8_C(  -3), INT8_C(  26),
                           INT8_C( -88), INT8_C( -51), INT8_C(-123), INT8_C(  93)),
      UINT64_C( 2985661334514035835),
      INT8_C( 111),
      simde_mm512_set_epi8(INT8_C( 107), INT8_C( 126), INT8_C( 111), INT8_C(  83),
                           INT8_C( 111), INT8_C(  62), INT8_C( -81), INT8_C( 111),
                           INT8_C( -68), INT8_C( 111), INT8_C( 111), INT8_C( 125),
                           INT8_C( 111), INT8_C( 111), INT8_C( 111), INT8_C( 111),
                           INT8_C(  29), INT8_C( -96), INT8_C( 111), INT8_C( 111),
                           INT8_C( -36), INT8_C( -62), INT8_C( 111), INT8_C( 111),
                           INT8_C(-123), INT8_C(  55), INT8_C( 111), INT8_C(  -4),
                           INT8_C( 111), INT8_C(  28), INT8_C( 111), INT8_C( -38),
                           INT8_C(   1), INT8_C( -25), INT8_C( 111), INT8_C( 111),
                           INT8_C( 111), INT8_C( 111), INT8_C( 111), INT8_C( 111),
                           INT8_C( 109), INT8_C( 111), INT8_C( -70), INT8_C( 111),
                           INT8_C(  -3), INT8_C(-109), INT8_C( 111), INT8_C( 111),
                           INT8_C( 111), INT8_C( 111), INT8_C( 111), INT8_C(-105),
                           INT8_C( 111), INT8_C( 111), INT8_C( -36), INT8_C(  87),
                           INT8_C(-101), INT8_C( 111), INT8_C( 111), INT8_C( 111),
                           INT8_C( 111), INT8_C( -51), INT8_C( 111), INT8_C( 111)) },
    { simde_mm512_set_epi8(INT8_C( -63), INT8_C(  92), INT8_C( -41), INT8_C( -80),
                           INT8_C(-101), INT8_C(  86), INT8_C(  45), INT8_C(  45),
                           INT8_C( -41), INT8_C(-113), INT8_C( -17), INT8_C(-101),
                           INT8_C(-113), INT8_C( -69), INT8_C(  73), INT8_C(-124),
                           INT8_C(  90), INT8_C(-118), INT8_C(  31), INT8_C(-124),
                           INT8_C( -88), INT8_C(-116), INT8_C(   8), INT8_C( -37),
                           INT8_C( -41), INT8_C(  93), INT8_C( -86), INT8_C(  61),
                           INT8_C( -70), INT8_C( -88), INT8_C(  44), INT8_C( -34),
                           INT8_C( -21), INT8_C(-121), INT8_C(-124), INT8_C(-114),
                           INT8_C(  73), INT8_C(  92), INT8_C( -92), INT8_C(-115),
                           INT8_C(   6), INT8_C(-120), INT8_C(  89), INT8_C(-102),
                           INT8_C( -43), INT8_C(  33), INT8_C(  15), INT8_C(  -6),
                           INT8_C(-105), INT8_C(  66), INT8_C( -60), INT8_C(  54),
                           INT8_C( -95), INT8_C(  49), INT8_C(   1), INT8_C( 118),
                           INT8_C( -33), INT8_C( -35), INT8_C( -34), INT8_C( -10),
                           INT8_C( -70), INT8_C(  74), INT8_C( -10), INT8_C(  97)),
      UINT64_C(12556192675989742329),
      INT8_C(-120),
      simde_mm512_set_epi8(INT8_C(-120), INT8_C(  92), INT8_C(-120), INT8_C( -80),
                           INT8_C(-120), INT8_C(-120), INT8_C(-120), INT8_C(  45),
                           INT8_C( -41), INT8_C(-120), INT8_C( -17), INT8_C(-101),
                           INT8_C(-113), INT8_C( -69), INT8_C(  73), INT8_C(-124),
                           INT8_C(-120), INT8_C(-118), INT8_C(  31), INT8_C(-124),
                           INT8_C(-120), INT8_C(-120), INT8_C(-120), INT8_C( -37),
                           INT8_C(-120), INT8_C(  93), INT8_C(-120), INT8_C(-120),
                           INT8_C( -70), INT8_C(-120), INT8_C(-120), INT8_C( -34),
                           INT8_C(-120), INT8_C(-121), INT8_C(-124), INT8_C(-120),
                           INT8_C(  73), INT8_C(-120), INT8_C(-120), INT8_C(-120),
                           INT8_C(-120), INT8_C(-120), INT8_C(-120), INT8_C(-120),
                           INT8_C(-120), INT8_C(  33), INT8_C(-120), INT8_C(  -6),
                           INT8_C(-120), INT8_C(-120), INT8_C(-120), INT8_C(  54),
                           INT8_C( -95), INT8_C(  49), INT8_C(-120), INT8_C( 118),
                           INT8_C(-120), INT8_C(-120), INT8_C(-120), INT8_C(-120),
                           INT8_C(-120), INT8_C(  74), INT8_C( -10), INT8_C(-120)) },
    { simde_mm512_set_epi8(INT8_C(  21), INT8_C(  17), INT8_C(  22), INT8_C(-115),
                           INT8_C( 101), INT8_C(  -2), INT8_C( -32), INT8_C( -27),
                           INT8_C( -14), INT8_C(  47), INT8_C( 110), INT8_C( -88),
                           INT8_C(  23), INT8_C( -87), INT8_C( -20), INT8_C( 115),
                           INT8_C( 108), INT8_C( -54), INT8_C(-105), INT8_C( -94),
                           INT8_C(  96), INT8_C(-110), INT8_C( -87), INT8_C( 119),
                           INT8_C( 110), INT8_C( -13), INT8_C(  53), INT8_C( -27),
                           INT8_C( -59), INT8_C(  57), INT8_C( -46), INT8_C( -24),
                           INT8_C(  35), INT8_C(  26), INT8_C( 124), INT8_C( -28),
                           INT8_C( -68), INT8_C( -57), INT8_C(  75), INT8_C( -25),
                           INT8_C(-112), INT8_C( 112), INT8_C( 123), INT8_C(-108),
                           INT8_C( 115), INT8_C(  -6), INT8_C(  43), INT8_C(  52),
                           INT8_C( -91), INT8_C( -17), INT8_C(  93), INT8_C(  -2),
                           INT8_C( 116), INT8_C( -51), INT8_C(  70), INT8_C(  98),
                           INT8_C( 104), INT8_C( -69), INT8_C(-102), INT8_C(  77),
                           INT8_C(  82), INT8_C( 125), INT8_C(  42), INT8_C(  83)),
      UINT64_C(12090133344763257330),
      INT8_C(  55),
      simde_mm512_set_epi8(INT8_C(  55), INT8_C(  17), INT8_C(  55), INT8_C(-115),
                           INT8_C( 101), INT8_C(  55), INT8_C(  55), INT8_C(  55),
                           INT8_C(  55), INT8_C(  55), INT8_C( 110), INT8_C( -88),
                           INT8_C(  55), INT8_C( -87), INT8_C( -20), INT8_C( 115),
                           INT8_C(  55), INT8_C(  55), INT8_C(-105), INT8_C( -94),
                           INT8_C(  55), INT8_C(-110), INT8_C( -87), INT8_C( 119),
                           INT8_C( 110), INT8_C( -13), INT8_C(  55), INT8_C(  55),
                           INT8_C(  55), INT8_C(  57), INT8_C( -46), INT8_C( -24),
                           INT8_C(  55), INT8_C(  26), INT8_C( 124), INT8_C( -28),
                           INT8_C( -68), INT8_C(  55), INT8_C(  75), INT8_C(  55),
                           INT8_C(  55), INT8_C( 112), INT8_C(  55), INT8_C(  55),
                           INT8_C(  55), INT8_C(  -6), INT8_C(  43), INT8_C(  52),
                           INT8_C( -91), INT8_C( -17), INT8_C(  55), INT8_C(  -2),
                           INT8_C( 116), INT8_C( -51), INT8_C(  70), INT8_C(  55),
                           INT8_C(  55), INT8_C(  55), INT8_C(  55), INT8_C(  55),
                           INT8_C(  82), INT8_C( 125), INT8_C(  55), INT8_C(  83)) },
    { simde_mm512_set_epi8(INT8_C(-124), INT8_C( -37), INT8_C( -61), INT8_C( -35),
                           INT8_C( -22), INT8_C( -85), INT8_C(-117), INT8_C(-105),
                           INT8_C(  99), INT8_C( -62), INT8_C( 102), INT8_C( -31),
                           INT8_C(  82), INT8_C(  39), INT8_C(  49), INT8_C(  43),
                           INT8_C(  21), INT8_C(  16), INT8_C(  12), INT8_C(-125),
                           INT8_C(   2), INT8_C(-106), INT8_C(  -4), INT8_C( 100),
                           INT8_C( -12), INT8_C(  30), INT8_C( -39), INT8_C( -37),
                           INT8_C(  92), INT8_C( -43), INT8_C(  33), INT8_C(-124),
                           INT8_C(  48), INT8_C(   4), INT8_C(  31), INT8_C(  78),
                           INT8_C(-113), INT8_C( 115), INT8_C( 116), INT8_C( -62),
                           INT8_C(-109), INT8_C( -66), INT8_C(  43), INT8_C(-118),
                           INT8_C(-105), INT8_C( -11), INT8_C( 100), INT8_C(  41),
                           INT8_C(-104), INT8_C(-114), INT8_C(-105), INT8_C(  88),
                           INT8_C( -33), INT8_C(  -8), INT8_C(  41), INT8_C(  16),
                           INT8_C(   4), INT8_C(  89), INT8_C(  66), INT8_C(  27),
                           INT8_C( -63), INT8_C(  30), INT8_C( -95), INT8_C(  33)),
      UINT64_C(13436704833767296949),
      INT8_C(  18),
      simde_mm512_set_epi8(INT8_C(  18), INT8_C( -37), INT8_C(  18), INT8_C(  18),
                           INT8_C(  18), INT8_C( -85), INT8_C(  18), INT8_C(-105),
                           INT8_C(  99), INT8_C(  18), INT8_C(  18), INT8_C(  18),
                           INT8_C(  18), INT8_C(  39), INT8_C(  49), INT8_C(  43),
                           INT8_C(  18), INT8_C(  18), INT8_C(  12), INT8_C(-125),
                           INT8_C(   2), INT8_C(-106), INT8_C(  18), INT8_C(  18),
                           INT8_C(  18), INT8_C(  18), INT8_C( -39), INT8_C(  18),
                           INT8_C(  18), INT8_C( -43), INT8_C(  18), INT8_C(  18),
                           INT8_C(  48), INT8_C(   4), INT8_C(  31), INT8_C(  78),
                           INT8_C(  18), INT8_C( 115), INT8_C( 116), INT8_C( -62),
                           INT8_C(-109), INT8_C(  18), INT8_C(  18), INT8_C(  18),
                           INT8_C(  18), INT8_C( -11), INT8_C( 100), INT8_C(  18),
                           INT8_C(-104), INT8_C(  18), INT8_C(-105), INT8_C(  88),
                           INT8_C(  18), INT8_C(  18), INT8_C(  18), INT8_C(  18),
                           INT8_C(  18), INT8_C(  89), INT8_C(  18), INT8_C(  18),
                           INT8_C( -63), INT8_C(  18), INT8_C( -95), INT8_C(  18)) },
    { simde_mm512_set_epi8(INT8_C( -30), INT8_C( 101), INT8_C(  64), INT8_C( 107),
                           INT8_C( -34), INT8_C( -67), INT8_C( -96), INT8_C(  35),
                           INT8_C( 117), INT8_C(  76), INT8_C( 106), INT8_C( -82),
                           INT8_C( -48), INT8_C(  63), INT8_C(  11), INT8_C(  22),
                           INT8_C(  41), INT8_C(  95), INT8_C(-123), INT8_C( -90),
                           INT8_C(  67), INT8_C( -76), INT8_C(-105), INT8_C(  -7),
                           INT8_C( 115), INT8_C( 121), INT8_C( -52), INT8_C( -95),
                           INT8_C(-101), INT8_C(  64), INT8_C( -67), INT8_C( 107),
                           INT8_C(-104), INT8_C(  56), INT8_C(  89), INT8_C( -95),
                           INT8_C(  21), INT8_C( -42), INT8_C( -75), INT8_C(  45),
                           INT8_C( -86), INT8_C(  32), INT8_C(  27), INT8_C(-119),
                           INT8_C( -68), INT8_C(   5), INT8_C( -78), INT8_C( -36),
                           INT8_C( 125), INT8_C( 117), INT8_C( -63), INT8_C( -68),
                           INT8_C( -45), INT8_C( -77), INT8_C(   6), INT8_C(  68),
                           INT8_C(  79), INT8_C( -92), INT8_C(  67), INT8_C(  61),
                           INT8_C(  42), INT8_C(  26), INT8_C(-117), INT8_C( -55)),
      UINT64_C(14020412538477965079),
      INT8_C( -46),
      simde_mm512_set_epi8(INT8_C( -46), INT8_C( -46), INT8_C(  64), INT8_C( 107),
                           INT8_C( -34), INT8_C( -67), INT8_C( -46), INT8_C(  35),
                           INT8_C( -46), INT8_C(  76), INT8_C( 106), INT8_C( -46),
                           INT8_C( -48), INT8_C(  63), INT8_C( -46), INT8_C(  22),
                           INT8_C( -46), INT8_C(  95), INT8_C(-123), INT8_C( -90),
                           INT8_C(  67), INT8_C( -76), INT8_C( -46), INT8_C(  -7),
                           INT8_C( -46), INT8_C( -46), INT8_C( -46), INT8_C( -95),
                           INT8_C( -46), INT8_C(  64), INT8_C( -46), INT8_C( -46),
                           INT8_C( -46), INT8_C(  56), INT8_C( -46), INT8_C( -95),
                           INT8_C(  21), INT8_C( -42), INT8_C( -75), INT8_C(  45),
                           INT8_C( -86), INT8_C( -46), INT8_C( -46), INT8_C(-119),
                           INT8_C( -46), INT8_C(   5), INT8_C( -78), INT8_C( -46),
                           INT8_C( 125), INT8_C( -46), INT8_C( -46), INT8_C( -68),
                           INT8_C( -46), INT8_C( -46), INT8_C( -46), INT8_C( -46),
                           INT8_C(  79), INT8_C( -92), INT8_C(  67), INT8_C( -46),
                           INT8_C(  42), INT8_C( -46), INT8_C( -46), INT8_C( -46)) },
    { simde_mm512_set_epi8(INT8_C( -83), INT8_C( -73), INT8_C( -22), INT8_C(  98),
                           INT8_C( 126), INT8_C(  41), INT8_C( -28), INT8_C( 126),
                           INT8_C( -75), INT8_C(  91), INT8_C( -33), INT8_C( 103),
                           INT8_C( -63), INT8_C(  62), INT8_C(  83), INT8_C(   4),
                           INT8_C(  65), INT8_C( -22), INT8_C( 107), INT8_C(   8),
                           INT8_C(  31), INT8_C(-111), INT8_C(-114), INT8_C(-118),
                           INT8_C(   2), INT8_C(  76), INT8_C(  19), INT8_C( 127),
                           INT8_C( -37), INT8_C( -41), INT8_C(  91), INT8_C( -64),
                           INT8_C(-105), INT8_C( 127), INT8_C(-121), INT8_C(  84),
                           INT8_C( 124), INT8_C(  50), INT8_C( -86), INT8_C(-101),
                           INT8_C( -82), INT8_C( 121), INT8_C(  18), INT8_C( -17),
                           INT8_C( -55), INT8_C(-102), INT8_C( -81), INT8_C( -54),
                           INT8_C( -56), INT8_C(  -2), INT8_C( -68), INT8_C( 105),
                           INT8_C( -48), INT8_C( -90), INT8_C( -46), INT8_C(  63),
                           INT8_C( 126), INT8_C( -93), INT8_C(  46), INT8_C(-114),
                           INT8_C(  58), INT8_C( 110), INT8_C( 102), INT8_C( -93)),
      UINT64_C(14839809536761107867),
      INT8_C( 106),
      simde_mm512_set_epi8(INT8_C( 106), INT8_C( 106), INT8_C( -22), INT8_C(  98),
                           INT8_C( 106), INT8_C( 106), INT8_C( -28), INT8_C( 106),
                           INT8_C( 106), INT8_C( 106), INT8_C( 106), INT8_C( 106),
                           INT8_C( -63), INT8_C(  62), INT8_C(  83), INT8_C( 106),
                           INT8_C( 106), INT8_C( -22), INT8_C( 107), INT8_C( 106),
                           INT8_C( 106), INT8_C(-111), INT8_C(-114), INT8_C(-118),
                           INT8_C(   2), INT8_C(  76), INT8_C( 106), INT8_C( 127),
                           INT8_C( -37), INT8_C( 106), INT8_C( 106), INT8_C( -64),
                           INT8_C(-105), INT8_C( 127), INT8_C( 106), INT8_C(  84),
                           INT8_C( 124), INT8_C( 106), INT8_C( -86), INT8_C( 106),
                           INT8_C( -82), INT8_C( 121), INT8_C(  18), INT8_C( 106),
                           INT8_C( 106), INT8_C(-102), INT8_C( -81), INT8_C( 106),
                           INT8_C( 106), INT8_C(  -2), INT8_C( -68), INT8_C( 106),
                           INT8_C( -48), INT8_C( 106), INT8_C( -46), INT8_C( 106),
                           INT8_C( 106), INT8_C( -93), INT8_C(  46), INT8_C( 106),
                           INT8_C( 106), INT8_C( 110), INT8_C( 106), INT8_C( 106)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_set1_epi8(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_set1_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask64 k;
    int8_t a;
    simde__m512i r;
  } test_vec[8] = {
   { UINT64_C( 2901368310709582274),
      INT8_C( -37),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C( -37), INT8_C(   0),
                           INT8_C( -37), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( -37), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -37), INT8_C( -37),
                           INT8_C( -37), INT8_C(   0), INT8_C( -37), INT8_C( -37),
                           INT8_C( -37), INT8_C(   0), INT8_C( -37), INT8_C( -37),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -37),
                           INT8_C( -37), INT8_C(   0), INT8_C( -37), INT8_C( -37),
                           INT8_C(   0), INT8_C( -37), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -37), INT8_C(   0),
                           INT8_C(   0), INT8_C( -37), INT8_C( -37), INT8_C(   0),
                           INT8_C( -37), INT8_C(   0), INT8_C( -37), INT8_C( -37),
                           INT8_C(   0), INT8_C( -37), INT8_C( -37), INT8_C( -37),
                           INT8_C( -37), INT8_C(   0), INT8_C(   0), INT8_C( -37),
                           INT8_C( -37), INT8_C( -37), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -37), INT8_C(   0)) },
    { UINT64_C(15800639674747260058),
      INT8_C(  63),
      simde_mm512_set_epi8(INT8_C(  63), INT8_C(  63), INT8_C(   0), INT8_C(  63),
                           INT8_C(  63), INT8_C(   0), INT8_C(  63), INT8_C(  63),
                           INT8_C(   0), INT8_C(  63), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  63), INT8_C(  63), INT8_C(  63),
                           INT8_C(   0), INT8_C(   0), INT8_C(  63), INT8_C(   0),
                           INT8_C(   0), INT8_C(  63), INT8_C(  63), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  63),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  63),
                           INT8_C(  63), INT8_C(   0), INT8_C(   0), INT8_C(  63),
                           INT8_C(  63), INT8_C(  63), INT8_C(   0), INT8_C(  63),
                           INT8_C(   0), INT8_C(  63), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  63),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  63), INT8_C(  63), INT8_C(   0), INT8_C(   0),
                           INT8_C(  63), INT8_C(   0), INT8_C(   0), INT8_C(  63),
                           INT8_C(  63), INT8_C(   0), INT8_C(  63), INT8_C(   0)) },
    { UINT64_C(12860739080443979541),
      INT8_C(  53),
      simde_mm512_set_epi8(INT8_C(  53), INT8_C(   0), INT8_C(  53), INT8_C(  53),
                           INT8_C(   0), INT8_C(   0), INT8_C(  53), INT8_C(   0),
                           INT8_C(   0), INT8_C(  53), INT8_C(  53), INT8_C(  53),
                           INT8_C(  53), INT8_C(   0), INT8_C(  53), INT8_C(   0),
                           INT8_C(  53), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  53), INT8_C(  53), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  53), INT8_C(  53), INT8_C(   0), INT8_C(  53),
                           INT8_C(  53), INT8_C(  53), INT8_C(  53), INT8_C(  53),
                           INT8_C(   0), INT8_C(  53), INT8_C(  53), INT8_C(   0),
                           INT8_C(  53), INT8_C(  53), INT8_C(   0), INT8_C(  53),
                           INT8_C(  53), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  53), INT8_C(  53), INT8_C(  53), INT8_C(   0),
                           INT8_C(   0), INT8_C(  53), INT8_C(  53), INT8_C(  53),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  53),
                           INT8_C(   0), INT8_C(  53), INT8_C(   0), INT8_C(  53)) },
    { UINT64_C( 2595884503750725802),
      INT8_C(  78),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  78), INT8_C(   0),
                           INT8_C(   0), INT8_C(  78), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  78), INT8_C(  78), INT8_C(   0),
                           INT8_C(   0), INT8_C(  78), INT8_C(  78), INT8_C(   0),
                           INT8_C(  78), INT8_C(  78), INT8_C(  78), INT8_C(  78),
                           INT8_C(   0), INT8_C(   0), INT8_C(  78), INT8_C(  78),
                           INT8_C(   0), INT8_C(   0), INT8_C(  78), INT8_C(  78),
                           INT8_C(  78), INT8_C(  78), INT8_C(   0), INT8_C(  78),
                           INT8_C(  78), INT8_C(  78), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  78), INT8_C(  78), INT8_C(   0), INT8_C(  78),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  78), INT8_C(   0), INT8_C(  78), INT8_C(   0),
                           INT8_C(  78), INT8_C(   0), INT8_C(  78), INT8_C(   0)) },
    { UINT64_C(13286373173549182748),
      INT8_C( -67),
      simde_mm512_set_epi8(INT8_C( -67), INT8_C(   0), INT8_C( -67), INT8_C( -67),
                           INT8_C( -67), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( -67), INT8_C( -67), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -67), INT8_C(   0),
                           INT8_C( -67), INT8_C(   0), INT8_C( -67), INT8_C(   0),
                           INT8_C( -67), INT8_C( -67), INT8_C( -67), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -67),
                           INT8_C( -67), INT8_C( -67), INT8_C(   0), INT8_C( -67),
                           INT8_C(   0), INT8_C(   0), INT8_C( -67), INT8_C(   0),
                           INT8_C( -67), INT8_C(   0), INT8_C( -67), INT8_C(   0),
                           INT8_C( -67), INT8_C( -67), INT8_C(   0), INT8_C( -67),
                           INT8_C( -67), INT8_C(   0), INT8_C( -67), INT8_C(   0),
                           INT8_C( -67), INT8_C( -67), INT8_C( -67), INT8_C( -67),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -67),
                           INT8_C( -67), INT8_C( -67), INT8_C(   0), INT8_C(   0)) },
    { UINT64_C(16804997844821669286),
      INT8_C( -98),
      simde_mm512_set_epi8(INT8_C( -98), INT8_C( -98), INT8_C( -98), INT8_C(   0),
                           INT8_C( -98), INT8_C(   0), INT8_C(   0), INT8_C( -98),
                           INT8_C(   0), INT8_C(   0), INT8_C( -98), INT8_C( -98),
                           INT8_C(   0), INT8_C( -98), INT8_C( -98), INT8_C( -98),
                           INT8_C(   0), INT8_C( -98), INT8_C(   0), INT8_C( -98),
                           INT8_C( -98), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C( -98), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C( -98), INT8_C( -98), INT8_C(   0), INT8_C(   0),
                           INT8_C( -98), INT8_C( -98), INT8_C( -98), INT8_C( -98),
                           INT8_C( -98), INT8_C( -98), INT8_C(   0), INT8_C(   0),
                           INT8_C( -98), INT8_C( -98), INT8_C(   0), INT8_C(   0),
                           INT8_C( -98), INT8_C( -98), INT8_C( -98), INT8_C( -98),
                           INT8_C(   0), INT8_C( -98), INT8_C(   0), INT8_C( -98),
                           INT8_C( -98), INT8_C(   0), INT8_C( -98), INT8_C(   0),
                           INT8_C(   0), INT8_C( -98), INT8_C( -98), INT8_C(   0)) },
    { UINT64_C(14388383136321922859),
      INT8_C( -31),
      simde_mm512_set_epi8(INT8_C( -31), INT8_C( -31), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( -31), INT8_C( -31), INT8_C( -31),
                           INT8_C( -31), INT8_C(   0), INT8_C( -31), INT8_C(   0),
                           INT8_C( -31), INT8_C( -31), INT8_C(   0), INT8_C( -31),
                           INT8_C( -31), INT8_C( -31), INT8_C(   0), INT8_C(   0),
                           INT8_C( -31), INT8_C( -31), INT8_C( -31), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -31), INT8_C( -31),
                           INT8_C( -31), INT8_C(   0), INT8_C( -31), INT8_C(   0),
                           INT8_C( -31), INT8_C( -31), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( -31), INT8_C(   0), INT8_C(   0),
                           INT8_C( -31), INT8_C(   0), INT8_C( -31), INT8_C( -31),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( -31), INT8_C( -31), INT8_C(   0),
                           INT8_C(   0), INT8_C( -31), INT8_C( -31), INT8_C( -31),
                           INT8_C(   0), INT8_C(   0), INT8_C( -31), INT8_C(   0),
                           INT8_C( -31), INT8_C(   0), INT8_C( -31), INT8_C( -31)) },
    { UINT64_C( 9693935732927043828),
      INT8_C(  57),
      simde_mm512_set_epi8(INT8_C(  57), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  57), INT8_C(  57), INT8_C(   0),
                           INT8_C(  57), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  57), INT8_C(  57), INT8_C(  57),
                           INT8_C(  57), INT8_C(  57), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  57), INT8_C(  57), INT8_C(  57),
                           INT8_C(   0), INT8_C(   0), INT8_C(  57), INT8_C(  57),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  57), INT8_C(  57),
                           INT8_C(  57), INT8_C(  57), INT8_C(   0), INT8_C(   0),
                           INT8_C(  57), INT8_C(   0), INT8_C(   0), INT8_C(  57),
                           INT8_C(   0), INT8_C(  57), INT8_C(   0), INT8_C(  57),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  57),
                           INT8_C(  57), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  57), INT8_C(  57), INT8_C(  57), INT8_C(  57),
                           INT8_C(   0), INT8_C(  57), INT8_C(   0), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_set1_epi8(test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_set1_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int16_t a;
    simde__m512i r;
  } test_vec[8] = {
    {   -334,
      simde_mm512_set_epi16(INT16_C(  -334), INT16_C(  -334), INT16_C(  -334), INT16_C(  -334),
                            INT16_C(  -334), INT16_C(  -334), INT16_C(  -334), INT16_C(  -334),
                            INT16_C(  -334), INT16_C(  -334), INT16_C(  -334), INT16_C(  -334),
                            INT16_C(  -334), INT16_C(  -334), INT16_C(  -334), INT16_C(  -334),
                            INT16_C(  -334), INT16_C(  -334), INT16_C(  -334), INT16_C(  -334),
                            INT16_C(  -334), INT16_C(  -334), INT16_C(  -334), INT16_C(  -334),
                            INT16_C(  -334), INT16_C(  -334), INT16_C(  -334), INT16_C(  -334),
                            INT16_C(  -334), INT16_C(  -334), INT16_C(  -334), INT16_C(  -334)) },
    {  27900,
      simde_mm512_set_epi16(INT16_C( 27900), INT16_C( 27900), INT16_C( 27900), INT16_C( 27900),
                            INT16_C( 27900), INT16_C( 27900), INT16_C( 27900), INT16_C( 27900),
                            INT16_C( 27900), INT16_C( 27900), INT16_C( 27900), INT16_C( 27900),
                            INT16_C( 27900), INT16_C( 27900), INT16_C( 27900), INT16_C( 27900),
                            INT16_C( 27900), INT16_C( 27900), INT16_C( 27900), INT16_C( 27900),
                            INT16_C( 27900), INT16_C( 27900), INT16_C( 27900), INT16_C( 27900),
                            INT16_C( 27900), INT16_C( 27900), INT16_C( 27900), INT16_C( 27900),
                            INT16_C( 27900), INT16_C( 27900), INT16_C( 27900), INT16_C( 27900)) },
    {   9352,
      simde_mm512_set_epi16(INT16_C(  9352), INT16_C(  9352), INT16_C(  9352), INT16_C(  9352),
                            INT16_C(  9352), INT16_C(  9352), INT16_C(  9352), INT16_C(  9352),
                            INT16_C(  9352), INT16_C(  9352), INT16_C(  9352), INT16_C(  9352),
                            INT16_C(  9352), INT16_C(  9352), INT16_C(  9352), INT16_C(  9352),
                            INT16_C(  9352), INT16_C(  9352), INT16_C(  9352), INT16_C(  9352),
                            INT16_C(  9352), INT16_C(  9352), INT16_C(  9352), INT16_C(  9352),
                            INT16_C(  9352), INT16_C(  9352), INT16_C(  9352), INT16_C(  9352),
                            INT16_C(  9352), INT16_C(  9352), INT16_C(  9352), INT16_C(  9352)) },
    { -21903,
      simde_mm512_set_epi16(INT16_C(-21903), INT16_C(-21903), INT16_C(-21903), INT16_C(-21903),
                            INT16_C(-21903), INT16_C(-21903), INT16_C(-21903), INT16_C(-21903),
                            INT16_C(-21903), INT16_C(-21903), INT16_C(-21903), INT16_C(-21903),
                            INT16_C(-21903), INT16_C(-21903), INT16_C(-21903), INT16_C(-21903),
                            INT16_C(-21903), INT16_C(-21903), INT16_C(-21903), INT16_C(-21903),
                            INT16_C(-21903), INT16_C(-21903), INT16_C(-21903), INT16_C(-21903),
                            INT16_C(-21903), INT16_C(-21903), INT16_C(-21903), INT16_C(-21903),
                            INT16_C(-21903), INT16_C(-21903), INT16_C(-21903), INT16_C(-21903)) },
    {  32371,
      simde_mm512_set_epi16(INT16_C( 32371), INT16_C( 32371), INT16_C( 32371), INT16_C( 32371),
                            INT16_C( 32371), INT16_C( 32371), INT16_C( 32371), INT16_C( 32371),
                            INT16_C( 32371), INT16_C( 32371), INT16_C( 32371), INT16_C( 32371),
                            INT16_C( 32371), INT16_C( 32371), INT16_C( 32371), INT16_C( 32371),
                            INT16_C( 32371), INT16_C( 32371), INT16_C( 32371), INT16_C( 32371),
                            INT16_C( 32371), INT16_C( 32371), INT16_C( 32371), INT16_C( 32371),
                            INT16_C( 32371), INT16_C( 32371), INT16_C( 32371), INT16_C( 32371),
                            INT16_C( 32371), INT16_C( 32371), INT16_C( 32371), INT16_C( 32371)) },
    {    -49,
      simde_mm512_set_epi16(INT16_C(   -49), INT16_C(   -49), INT16_C(   -49), INT16_C(   -49),
                            INT16_C(   -49), INT16_C(   -49), INT16_C(   -49), INT16_C(   -49),
                            INT16_C(   -49), INT16_C(   -49), INT16_C(   -49), INT16_C(   -49),
                            INT16_C(   -49), INT16_C(   -49), INT16_C(   -49), INT16_C(   -49),
                            INT16_C(   -49), INT16_C(   -49), INT16_C(   -49), INT16_C(   -49),
                            INT16_C(   -49), INT16_C(   -49), INT16_C(   -49), INT16_C(   -49),
                            INT16_C(   -49), INT16_C(   -49), INT16_C(   -49), INT16_C(   -49),
                            INT16_C(   -49), INT16_C(   -49), INT16_C(   -49), INT16_C(   -49)) },
    {  18491,
      simde_mm512_set_epi16(INT16_C( 18491), INT16_C( 18491), INT16_C( 18491), INT16_C( 18491),
                            INT16_C( 18491), INT16_C( 18491), INT16_C( 18491), INT16_C( 18491),
                            INT16_C( 18491), INT16_C( 18491), INT16_C( 18491), INT16_C( 18491),
                            INT16_C( 18491), INT16_C( 18491), INT16_C( 18491), INT16_C( 18491),
                            INT16_C( 18491), INT16_C( 18491), INT16_C( 18491), INT16_C( 18491),
                            INT16_C( 18491), INT16_C( 18491), INT16_C( 18491), INT16_C( 18491),
                            INT16_C( 18491), INT16_C( 18491), INT16_C( 18491), INT16_C( 18491),
                            INT16_C( 18491), INT16_C( 18491), INT16_C( 18491), INT16_C( 18491)) },
    {  25038,
      simde_mm512_set_epi16(INT16_C( 25038), INT16_C( 25038), INT16_C( 25038), INT16_C( 25038),
                            INT16_C( 25038), INT16_C( 25038), INT16_C( 25038), INT16_C( 25038),
                            INT16_C( 25038), INT16_C( 25038), INT16_C( 25038), INT16_C( 25038),
                            INT16_C( 25038), INT16_C( 25038), INT16_C( 25038), INT16_C( 25038),
                            INT16_C( 25038), INT16_C( 25038), INT16_C( 25038), INT16_C( 25038),
                            INT16_C( 25038), INT16_C( 25038), INT16_C( 25038), INT16_C( 25038),
                            INT16_C( 25038), INT16_C( 25038), INT16_C( 25038), INT16_C( 25038),
                            INT16_C( 25038), INT16_C( 25038), INT16_C( 25038), INT16_C( 25038)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_set1_epi16(test_vec[i].a);
    simde_assert_m512i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_set1_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask32 k;
    int16_t a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi16(INT16_C(   874), INT16_C( 15357), INT16_C(  3602), INT16_C( 11090),
                            INT16_C( 31475), INT16_C( 20808), INT16_C(-26328), INT16_C(-21794),
                            INT16_C(-24829), INT16_C(-15530), INT16_C( -9785), INT16_C( 22806),
                            INT16_C( -6385), INT16_C(-26604), INT16_C(-15351), INT16_C(-18936),
                            INT16_C( 28985), INT16_C( 24045), INT16_C(-25535), INT16_C(-25436),
                            INT16_C(   749), INT16_C( 15517), INT16_C(-24369), INT16_C(-27864),
                            INT16_C(  6864), INT16_C( 16553), INT16_C(  -407), INT16_C(-28514),
                            INT16_C( -9423), INT16_C(-29018), INT16_C(-11420), INT16_C(-22112)),
      UINT32_C(1121120418),
      INT16_C(-24380),
      simde_mm512_set_epi16(INT16_C(   874), INT16_C(-24380), INT16_C(  3602), INT16_C( 11090),
                            INT16_C( 31475), INT16_C( 20808), INT16_C(-24380), INT16_C(-21794),
                            INT16_C(-24380), INT16_C(-24380), INT16_C( -9785), INT16_C(-24380),
                            INT16_C( -6385), INT16_C(-26604), INT16_C(-24380), INT16_C(-18936),
                            INT16_C(-24380), INT16_C(-24380), INT16_C(-24380), INT16_C(-24380),
                            INT16_C(   749), INT16_C( 15517), INT16_C(-24369), INT16_C(-27864),
                            INT16_C(-24380), INT16_C( 16553), INT16_C(-24380), INT16_C(-28514),
                            INT16_C( -9423), INT16_C(-29018), INT16_C(-24380), INT16_C(-22112)) },
    { simde_mm512_set_epi16(INT16_C( 21630), INT16_C(    53), INT16_C(-30787), INT16_C( 11298),
                            INT16_C( 13120), INT16_C(-15891), INT16_C( 20834), INT16_C(  5170),
                            INT16_C( 11237), INT16_C(-32025), INT16_C(  2036), INT16_C(-32146),
                            INT16_C(  6820), INT16_C( 29964), INT16_C(-20673), INT16_C( -6255),
                            INT16_C( 12677), INT16_C(  5934), INT16_C( 18392), INT16_C(-16008),
                            INT16_C( -6967), INT16_C(-23263), INT16_C( 28759), INT16_C(  4932),
                            INT16_C(-20928), INT16_C(-12287), INT16_C(-21100), INT16_C(-15604),
                            INT16_C(-25734), INT16_C(-27889), INT16_C( 22154), INT16_C( 16749)),
      UINT32_C( 442706120),
      INT16_C(-18045),
      simde_mm512_set_epi16(INT16_C( 21630), INT16_C(    53), INT16_C(-30787), INT16_C(-18045),
                            INT16_C(-18045), INT16_C(-15891), INT16_C(-18045), INT16_C(  5170),
                            INT16_C( 11237), INT16_C(-18045), INT16_C(-18045), INT16_C(-32146),
                            INT16_C(  6820), INT16_C( 29964), INT16_C(-18045), INT16_C(-18045),
                            INT16_C( 12677), INT16_C(  5934), INT16_C(-18045), INT16_C(-16008),
                            INT16_C(-18045), INT16_C(-23263), INT16_C( 28759), INT16_C(  4932),
                            INT16_C(-18045), INT16_C(-18045), INT16_C(-21100), INT16_C(-15604),
                            INT16_C(-18045), INT16_C(-27889), INT16_C( 22154), INT16_C( 16749)) },
    { simde_mm512_set_epi16(INT16_C(-12675), INT16_C(-13885), INT16_C( -4000), INT16_C( 31908),
                            INT16_C( 16178), INT16_C( -8662), INT16_C(-27877), INT16_C(-11427),
                            INT16_C(-10847), INT16_C(  7965), INT16_C(-13767), INT16_C( 14192),
                            INT16_C( -3024), INT16_C(-20651), INT16_C(  1677), INT16_C(-14378),
                            INT16_C( 13823), INT16_C(-21716), INT16_C(-14569), INT16_C( 19205),
                            INT16_C(-19335), INT16_C( 31769), INT16_C(-13133), INT16_C(-12032),
                            INT16_C(-27851), INT16_C(-12954), INT16_C(-30941), INT16_C( 26210),
                            INT16_C( 10250), INT16_C(-12883), INT16_C(-31618), INT16_C(  -328)),
      UINT32_C(3083705480),
      INT16_C(  4440),
      simde_mm512_set_epi16(INT16_C(  4440), INT16_C(-13885), INT16_C(  4440), INT16_C(  4440),
                            INT16_C( 16178), INT16_C(  4440), INT16_C(  4440), INT16_C(  4440),
                            INT16_C(  4440), INT16_C(  4440), INT16_C(-13767), INT16_C( 14192),
                            INT16_C(  4440), INT16_C(  4440), INT16_C(  1677), INT16_C(  4440),
                            INT16_C(  4440), INT16_C(-21716), INT16_C(-14569), INT16_C(  4440),
                            INT16_C(  4440), INT16_C(  4440), INT16_C(-13133), INT16_C(-12032),
                            INT16_C(  4440), INT16_C(-12954), INT16_C(-30941), INT16_C( 26210),
                            INT16_C(  4440), INT16_C(-12883), INT16_C(-31618), INT16_C(  -328)) },
    { simde_mm512_set_epi16(INT16_C(-23201), INT16_C(  4909), INT16_C(-10596), INT16_C( 25003),
                            INT16_C( 25193), INT16_C(-28193), INT16_C(  7484), INT16_C( 22842),
                            INT16_C( 12827), INT16_C(-21490), INT16_C(-19021), INT16_C( 17939),
                            INT16_C( 14187), INT16_C( 31294), INT16_C(-22999), INT16_C( 25206),
                            INT16_C(-22002), INT16_C( 23505), INT16_C(-20713), INT16_C( 22238),
                            INT16_C( 29284), INT16_C( 28054), INT16_C(-21727), INT16_C( 30369),
                            INT16_C( 19358), INT16_C(  -623), INT16_C(  2386), INT16_C(  9395),
                            INT16_C(-11819), INT16_C( 28599), INT16_C(-11863), INT16_C( -4500)),
      UINT32_C(1729799485),
      INT16_C(   -51),
      simde_mm512_set_epi16(INT16_C(-23201), INT16_C(   -51), INT16_C(   -51), INT16_C( 25003),
                            INT16_C( 25193), INT16_C(   -51), INT16_C(   -51), INT16_C(   -51),
                            INT16_C( 12827), INT16_C(-21490), INT16_C(-19021), INT16_C(   -51),
                            INT16_C(   -51), INT16_C( 31294), INT16_C(   -51), INT16_C( 25206),
                            INT16_C(   -51), INT16_C( 23505), INT16_C(   -51), INT16_C( 22238),
                            INT16_C( 29284), INT16_C(   -51), INT16_C(-21727), INT16_C(   -51),
                            INT16_C( 19358), INT16_C(  -623), INT16_C(   -51), INT16_C(   -51),
                            INT16_C(   -51), INT16_C(   -51), INT16_C(-11863), INT16_C(   -51)) },
    { simde_mm512_set_epi16(INT16_C(-12929), INT16_C( -9559), INT16_C( -1255), INT16_C(-25300),
                            INT16_C( 24130), INT16_C( 22555), INT16_C(-26496), INT16_C(  4179),
                            INT16_C( 25227), INT16_C( 31028), INT16_C( 12492), INT16_C(-27096),
                            INT16_C( 22382), INT16_C( -5113), INT16_C(-30455), INT16_C( 15691),
                            INT16_C(-18605), INT16_C( -4278), INT16_C( 11441), INT16_C(-26478),
                            INT16_C( 11388), INT16_C(-27754), INT16_C(   607), INT16_C( -1601),
                            INT16_C(-14454), INT16_C(  1251), INT16_C( 27178), INT16_C( 11399),
                            INT16_C(  -184), INT16_C( 17990), INT16_C(-12132), INT16_C(-20400)),
      UINT32_C(3701546889),
      INT16_C( 26765),
      simde_mm512_set_epi16(INT16_C( 26765), INT16_C( 26765), INT16_C( -1255), INT16_C( 26765),
                            INT16_C( 26765), INT16_C( 26765), INT16_C(-26496), INT16_C(  4179),
                            INT16_C( 26765), INT16_C( 31028), INT16_C( 26765), INT16_C(-27096),
                            INT16_C( 22382), INT16_C( -5113), INT16_C(-30455), INT16_C( 26765),
                            INT16_C(-18605), INT16_C( -4278), INT16_C( 11441), INT16_C( 26765),
                            INT16_C( 26765), INT16_C( 26765), INT16_C( 26765), INT16_C( 26765),
                            INT16_C( 26765), INT16_C(  1251), INT16_C( 27178), INT16_C( 11399),
                            INT16_C( 26765), INT16_C( 17990), INT16_C(-12132), INT16_C( 26765)) },
    { simde_mm512_set_epi16(INT16_C( 23556), INT16_C( 11192), INT16_C(-13439), INT16_C( -2357),
                            INT16_C(   858), INT16_C( 27575), INT16_C( 20368), INT16_C(-20256),
                            INT16_C(-11019), INT16_C( -7073), INT16_C(-32385), INT16_C( 27749),
                            INT16_C( 17332), INT16_C(-28131), INT16_C( 22510), INT16_C(  -872),
                            INT16_C( 20986), INT16_C(-25896), INT16_C(  7561), INT16_C(-22951),
                            INT16_C( -9997), INT16_C( 18542), INT16_C( -1921), INT16_C(-16319),
                            INT16_C(-24759), INT16_C( 10467), INT16_C(  8453), INT16_C(  5278),
                            INT16_C(-22217), INT16_C( 17080), INT16_C( 16797), INT16_C( -9777)),
      UINT32_C(3298748633),
      INT16_C( -5240),
      simde_mm512_set_epi16(INT16_C( -5240), INT16_C( -5240), INT16_C(-13439), INT16_C( -2357),
                            INT16_C(   858), INT16_C( -5240), INT16_C( 20368), INT16_C(-20256),
                            INT16_C( -5240), INT16_C( -7073), INT16_C(-32385), INT16_C( -5240),
                            INT16_C( -5240), INT16_C( -5240), INT16_C( -5240), INT16_C(  -872),
                            INT16_C( -5240), INT16_C( -5240), INT16_C( -5240), INT16_C(-22951),
                            INT16_C( -5240), INT16_C( 18542), INT16_C( -1921), INT16_C(-16319),
                            INT16_C( -5240), INT16_C( -5240), INT16_C(  8453), INT16_C( -5240),
                            INT16_C( -5240), INT16_C( 17080), INT16_C( 16797), INT16_C( -5240)) },
    { simde_mm512_set_epi16(INT16_C(  -894), INT16_C( 15324), INT16_C(-23364), INT16_C( 25648),
                            INT16_C(  -512), INT16_C( 12172), INT16_C(-27706), INT16_C(-10514),
                            INT16_C(  1026), INT16_C( 20384), INT16_C(-25471), INT16_C( -3464),
                            INT16_C( 14827), INT16_C( 18045), INT16_C(-25826), INT16_C( 12664),
                            INT16_C(-16682), INT16_C( 16498), INT16_C( 29333), INT16_C(  -511),
                            INT16_C( 15382), INT16_C(-19710), INT16_C(-14139), INT16_C( 14459),
                            INT16_C( 16092), INT16_C(-12889), INT16_C(  -337), INT16_C( 29893),
                            INT16_C(-29467), INT16_C( -8274), INT16_C( 30322), INT16_C(-19138)),
      UINT32_C(3605268017),
      INT16_C(-14523),
      simde_mm512_set_epi16(INT16_C(-14523), INT16_C(-14523), INT16_C(-23364), INT16_C(-14523),
                            INT16_C(  -512), INT16_C(-14523), INT16_C(-14523), INT16_C(-10514),
                            INT16_C(-14523), INT16_C(-14523), INT16_C(-14523), INT16_C( -3464),
                            INT16_C( 14827), INT16_C(-14523), INT16_C(-25826), INT16_C( 12664),
                            INT16_C(-16682), INT16_C( 16498), INT16_C( 29333), INT16_C(  -511),
                            INT16_C( 15382), INT16_C(-14523), INT16_C(-14523), INT16_C( 14459),
                            INT16_C( 16092), INT16_C(-12889), INT16_C(-14523), INT16_C(-14523),
                            INT16_C(-29467), INT16_C( -8274), INT16_C( 30322), INT16_C(-14523)) },
    { simde_mm512_set_epi16(INT16_C( -6967), INT16_C(-20070), INT16_C( -8289), INT16_C(  -479),
                            INT16_C(-18969), INT16_C( -6012), INT16_C( 11721), INT16_C( 13564),
                            INT16_C( 19765), INT16_C( 23581), INT16_C(-21527), INT16_C( -2847),
                            INT16_C( 23178), INT16_C(-14967), INT16_C( 17682), INT16_C( 28255),
                            INT16_C(  8882), INT16_C( 14691), INT16_C(-27903), INT16_C( 28973),
                            INT16_C(   619), INT16_C(-10329), INT16_C( 25572), INT16_C(-13439),
                            INT16_C( -3930), INT16_C(  5659), INT16_C(  -675), INT16_C(-18004),
                            INT16_C(-26191), INT16_C(  5303), INT16_C(-13369), INT16_C( 21695)),
      UINT32_C( 349570055),
      INT16_C( 24210),
      simde_mm512_set_epi16(INT16_C( -6967), INT16_C(-20070), INT16_C( -8289), INT16_C( 24210),
                            INT16_C(-18969), INT16_C( 24210), INT16_C( 11721), INT16_C( 13564),
                            INT16_C( 24210), INT16_C( 24210), INT16_C(-21527), INT16_C( 24210),
                            INT16_C( 23178), INT16_C( 24210), INT16_C( 24210), INT16_C( 28255),
                            INT16_C(  8882), INT16_C( 14691), INT16_C(-27903), INT16_C( 28973),
                            INT16_C(   619), INT16_C( 24210), INT16_C( 25572), INT16_C(-13439),
                            INT16_C( -3930), INT16_C(  5659), INT16_C(  -675), INT16_C(-18004),
                            INT16_C(-26191), INT16_C( 24210), INT16_C( 24210), INT16_C( 24210)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_set1_epi16(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_set1_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask32 k;
    int16_t a;
    simde__m512i r;
  } test_vec[8] = {
   {  UINT32_C( 693683203),
      INT16_C(-16188),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(-16188), INT16_C(     0),
                            INT16_C(-16188), INT16_C(     0), INT16_C(     0), INT16_C(-16188),
                            INT16_C(     0), INT16_C(-16188), INT16_C(     0), INT16_C(-16188),
                            INT16_C(-16188), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(-16188), INT16_C(-16188), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(-16188), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(-16188), INT16_C(-16188)) },
   {  UINT32_C(2322862674),
      INT16_C(-31832),
      simde_mm512_set_epi16(INT16_C(-31832), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(-31832), INT16_C(     0), INT16_C(-31832), INT16_C(     0),
                            INT16_C(     0), INT16_C(-31832), INT16_C(-31832), INT16_C(-31832),
                            INT16_C(     0), INT16_C(-31832), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(-31832),
                            INT16_C(     0), INT16_C(     0), INT16_C(-31832), INT16_C(     0),
                            INT16_C(     0), INT16_C(-31832), INT16_C(     0), INT16_C(-31832),
                            INT16_C(     0), INT16_C(     0), INT16_C(-31832), INT16_C(     0)) },
   {  UINT32_C(3196780114),
      INT16_C(  8083),
      simde_mm512_set_epi16(INT16_C(  8083), INT16_C(     0), INT16_C(  8083), INT16_C(  8083),
                            INT16_C(  8083), INT16_C(  8083), INT16_C(  8083), INT16_C(     0),
                            INT16_C(  8083), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(  8083), INT16_C(     0), INT16_C(  8083), INT16_C(     0),
                            INT16_C(  8083), INT16_C(  8083), INT16_C(  8083), INT16_C(  8083),
                            INT16_C(  8083), INT16_C(  8083), INT16_C(  8083), INT16_C(     0),
                            INT16_C(     0), INT16_C(  8083), INT16_C(     0), INT16_C(  8083),
                            INT16_C(     0), INT16_C(     0), INT16_C(  8083), INT16_C(     0)) },
   {  UINT32_C( 962615778),
      INT16_C( 10134),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C( 10134), INT16_C( 10134),
                            INT16_C( 10134), INT16_C(     0), INT16_C(     0), INT16_C( 10134),
                            INT16_C(     0), INT16_C( 10134), INT16_C( 10134), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C( 10134), INT16_C(     0), INT16_C( 10134),
                            INT16_C( 10134), INT16_C(     0), INT16_C(     0), INT16_C( 10134),
                            INT16_C( 10134), INT16_C( 10134), INT16_C( 10134), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C( 10134), INT16_C(     0)) },
   {  UINT32_C(3651012064),
      INT16_C(-28841),
      simde_mm512_set_epi16(INT16_C(-28841), INT16_C(-28841), INT16_C(     0), INT16_C(-28841),
                            INT16_C(-28841), INT16_C(     0), INT16_C(     0), INT16_C(-28841),
                            INT16_C(-28841), INT16_C(     0), INT16_C(     0), INT16_C(-28841),
                            INT16_C(-28841), INT16_C(-28841), INT16_C(-28841), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(-28841), INT16_C(     0), INT16_C(-28841),
                            INT16_C(-28841), INT16_C(-28841), INT16_C(-28841), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
   {  UINT32_C(1153035128),
      INT16_C(  9546),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C(  9546), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(  9546), INT16_C(     0), INT16_C(     0),
                            INT16_C(  9546), INT16_C(     0), INT16_C(  9546), INT16_C(  9546),
                            INT16_C(  9546), INT16_C(     0), INT16_C(     0), INT16_C(  9546),
                            INT16_C(  9546), INT16_C(  9546), INT16_C(  9546), INT16_C(     0),
                            INT16_C(  9546), INT16_C(     0), INT16_C(  9546), INT16_C(  9546),
                            INT16_C(     0), INT16_C(  9546), INT16_C(  9546), INT16_C(  9546),
                            INT16_C(  9546), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
   {  UINT32_C(2648275992),
      INT16_C(-29002),
      simde_mm512_set_epi16(INT16_C(-29002), INT16_C(     0), INT16_C(     0), INT16_C(-29002),
                            INT16_C(-29002), INT16_C(-29002), INT16_C(     0), INT16_C(-29002),
                            INT16_C(-29002), INT16_C(-29002), INT16_C(     0), INT16_C(-29002),
                            INT16_C(-29002), INT16_C(     0), INT16_C(     0), INT16_C(-29002),
                            INT16_C(     0), INT16_C(-29002), INT16_C(-29002), INT16_C(-29002),
                            INT16_C(-29002), INT16_C(-29002), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(-29002),
                            INT16_C(-29002), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
   {  UINT32_C(1548742660),
      INT16_C( 11362),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C( 11362), INT16_C(     0), INT16_C( 11362),
                            INT16_C( 11362), INT16_C( 11362), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C( 11362), INT16_C(     0), INT16_C(     0),
                            INT16_C( 11362), INT16_C( 11362), INT16_C( 11362), INT16_C( 11362),
                            INT16_C( 11362), INT16_C( 11362), INT16_C( 11362), INT16_C( 11362),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C( 11362), INT16_C(     0), INT16_C(     0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_set1_epi16(test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_set1_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int32_t a;
    simde__m512i r;
  } test_vec[8] = {
    {  1727286739,
      simde_mm512_set_epi32(INT32_C( 1727286739), INT32_C( 1727286739), INT32_C( 1727286739), INT32_C( 1727286739),
                            INT32_C( 1727286739), INT32_C( 1727286739), INT32_C( 1727286739), INT32_C( 1727286739),
                            INT32_C( 1727286739), INT32_C( 1727286739), INT32_C( 1727286739), INT32_C( 1727286739),
                            INT32_C( 1727286739), INT32_C( 1727286739), INT32_C( 1727286739), INT32_C( 1727286739)) },
    {  1944050466,
      simde_mm512_set_epi32(INT32_C( 1944050466), INT32_C( 1944050466), INT32_C( 1944050466), INT32_C( 1944050466),
                            INT32_C( 1944050466), INT32_C( 1944050466), INT32_C( 1944050466), INT32_C( 1944050466),
                            INT32_C( 1944050466), INT32_C( 1944050466), INT32_C( 1944050466), INT32_C( 1944050466),
                            INT32_C( 1944050466), INT32_C( 1944050466), INT32_C( 1944050466), INT32_C( 1944050466)) },
    { -1212539061,
      simde_mm512_set_epi32(INT32_C(-1212539061), INT32_C(-1212539061), INT32_C(-1212539061), INT32_C(-1212539061),
                            INT32_C(-1212539061), INT32_C(-1212539061), INT32_C(-1212539061), INT32_C(-1212539061),
                            INT32_C(-1212539061), INT32_C(-1212539061), INT32_C(-1212539061), INT32_C(-1212539061),
                            INT32_C(-1212539061), INT32_C(-1212539061), INT32_C(-1212539061), INT32_C(-1212539061)) },
    { -1654733061,
      simde_mm512_set_epi32(INT32_C(-1654733061), INT32_C(-1654733061), INT32_C(-1654733061), INT32_C(-1654733061),
                            INT32_C(-1654733061), INT32_C(-1654733061), INT32_C(-1654733061), INT32_C(-1654733061),
                            INT32_C(-1654733061), INT32_C(-1654733061), INT32_C(-1654733061), INT32_C(-1654733061),
                            INT32_C(-1654733061), INT32_C(-1654733061), INT32_C(-1654733061), INT32_C(-1654733061)) },
    { -1048158621,
      simde_mm512_set_epi32(INT32_C(-1048158621), INT32_C(-1048158621), INT32_C(-1048158621), INT32_C(-1048158621),
                            INT32_C(-1048158621), INT32_C(-1048158621), INT32_C(-1048158621), INT32_C(-1048158621),
                            INT32_C(-1048158621), INT32_C(-1048158621), INT32_C(-1048158621), INT32_C(-1048158621),
                            INT32_C(-1048158621), INT32_C(-1048158621), INT32_C(-1048158621), INT32_C(-1048158621)) },
    {  -676031020,
      simde_mm512_set_epi32(INT32_C( -676031020), INT32_C( -676031020), INT32_C( -676031020), INT32_C( -676031020),
                            INT32_C( -676031020), INT32_C( -676031020), INT32_C( -676031020), INT32_C( -676031020),
                            INT32_C( -676031020), INT32_C( -676031020), INT32_C( -676031020), INT32_C( -676031020),
                            INT32_C( -676031020), INT32_C( -676031020), INT32_C( -676031020), INT32_C( -676031020)) },
    {   651688918,
      simde_mm512_set_epi32(INT32_C(  651688918), INT32_C(  651688918), INT32_C(  651688918), INT32_C(  651688918),
                            INT32_C(  651688918), INT32_C(  651688918), INT32_C(  651688918), INT32_C(  651688918),
                            INT32_C(  651688918), INT32_C(  651688918), INT32_C(  651688918), INT32_C(  651688918),
                            INT32_C(  651688918), INT32_C(  651688918), INT32_C(  651688918), INT32_C(  651688918)) },
    { -1051556258,
      simde_mm512_set_epi32(INT32_C(-1051556258), INT32_C(-1051556258), INT32_C(-1051556258), INT32_C(-1051556258),
                            INT32_C(-1051556258), INT32_C(-1051556258), INT32_C(-1051556258), INT32_C(-1051556258),
                            INT32_C(-1051556258), INT32_C(-1051556258), INT32_C(-1051556258), INT32_C(-1051556258),
                            INT32_C(-1051556258), INT32_C(-1051556258), INT32_C(-1051556258), INT32_C(-1051556258)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_set1_epi32(test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_set1_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask16 k;
    int32_t a;
    simde__m512i r;
  } test_vec[8] = {
      { simde_mm512_set_epi32(INT32_C(-2133842294), INT32_C( 1453587049), INT32_C( 2146642803), INT32_C(-1231323727),
                            INT32_C( 1853533908), INT32_C(-1907653908), INT32_C(  564694133), INT32_C(-1137944481),
                            INT32_C(  355997036), INT32_C(   15257739), INT32_C( 1494729649), INT32_C( 1029796613),
                            INT32_C( 2106354400), INT32_C( 1763331885), INT32_C( -506942576), INT32_C( -586993838)),
      UINT16_C( 2584),
       -447334412,
      simde_mm512_set_epi32(INT32_C(-2133842294), INT32_C( 1453587049), INT32_C( 2146642803), INT32_C(-1231323727),
                            INT32_C( -447334412), INT32_C(-1907653908), INT32_C( -447334412), INT32_C(-1137944481),
                            INT32_C(  355997036), INT32_C(   15257739), INT32_C( 1494729649), INT32_C( -447334412),
                            INT32_C( -447334412), INT32_C( 1763331885), INT32_C( -506942576), INT32_C( -586993838)) },
    { simde_mm512_set_epi32(INT32_C( -998613800), INT32_C(  131555600), INT32_C( -778207920), INT32_C(-1881674086),
                            INT32_C(  920672518), INT32_C(-1753434445), INT32_C(  982638267), INT32_C( 1856541033),
                            INT32_C( -869506663), INT32_C( -394635465), INT32_C(-1596048192), INT32_C(  274218308),
                            INT32_C(  757893716), INT32_C(-2119306902), INT32_C(  364747827), INT32_C( -200526147)),
      UINT16_C(52133),
        749362876,
      simde_mm512_set_epi32(INT32_C(  749362876), INT32_C(  749362876), INT32_C( -778207920), INT32_C(-1881674086),
                            INT32_C(  749362876), INT32_C(-1753434445), INT32_C(  749362876), INT32_C(  749362876),
                            INT32_C(  749362876), INT32_C( -394635465), INT32_C(  749362876), INT32_C(  274218308),
                            INT32_C(  757893716), INT32_C(  749362876), INT32_C(  364747827), INT32_C(  749362876)) },
    { simde_mm512_set_epi32(INT32_C(-2009617550), INT32_C( 1354406381), INT32_C( 2028903938), INT32_C(-1425115920),
                            INT32_C(-1833209985), INT32_C( -485232115), INT32_C( -246273875), INT32_C(-1220668381),
                            INT32_C( 1710154952), INT32_C(-1764069342), INT32_C( -426734827), INT32_C(-1603498425),
                            INT32_C(-1463214772), INT32_C(-1312774926), INT32_C(  714085999), INT32_C( -352604741)),
      UINT16_C(50570),
        722829713,
      simde_mm512_set_epi32(INT32_C(  722829713), INT32_C(  722829713), INT32_C( 2028903938), INT32_C(-1425115920),
                            INT32_C(-1833209985), INT32_C(  722829713), INT32_C( -246273875), INT32_C(  722829713),
                            INT32_C(  722829713), INT32_C(-1764069342), INT32_C( -426734827), INT32_C(-1603498425),
                            INT32_C(  722829713), INT32_C(-1312774926), INT32_C(  722829713), INT32_C( -352604741)) },
    { simde_mm512_set_epi32(INT32_C(-1600817970), INT32_C( -289243644), INT32_C(  742005878), INT32_C( -612930926),
                            INT32_C(  717430896), INT32_C( 1787140065), INT32_C(-1405808293), INT32_C(  816556317),
                            INT32_C( 1747379900), INT32_C(-1006412100), INT32_C( 2116251350), INT32_C(-1238632202),
                            INT32_C( 1684739890), INT32_C( 1414060999), INT32_C(-2081867445), INT32_C( 1952705540)),
      UINT16_C(15423),
       1968604658,
      simde_mm512_set_epi32(INT32_C(-1600817970), INT32_C( -289243644), INT32_C( 1968604658), INT32_C( 1968604658),
                            INT32_C( 1968604658), INT32_C( 1968604658), INT32_C(-1405808293), INT32_C(  816556317),
                            INT32_C( 1747379900), INT32_C(-1006412100), INT32_C( 1968604658), INT32_C( 1968604658),
                            INT32_C( 1968604658), INT32_C( 1968604658), INT32_C( 1968604658), INT32_C( 1968604658)) },
    { simde_mm512_set_epi32(INT32_C( -666739030), INT32_C(-1370874438), INT32_C(-1476494318), INT32_C(-1101994537),
                            INT32_C(  338919471), INT32_C( -523657701), INT32_C( 1918205933), INT32_C( -933363441),
                            INT32_C(  191279486), INT32_C( -793805997), INT32_C(-1611569913), INT32_C(-1249963897),
                            INT32_C(-1384621234), INT32_C( 1593832662), INT32_C(  656079206), INT32_C(-1000644982)),
      UINT16_C(34631),
        997675190,
      simde_mm512_set_epi32(INT32_C(  997675190), INT32_C(-1370874438), INT32_C(-1476494318), INT32_C(-1101994537),
                            INT32_C(  338919471), INT32_C(  997675190), INT32_C(  997675190), INT32_C(  997675190),
                            INT32_C(  191279486), INT32_C(  997675190), INT32_C(-1611569913), INT32_C(-1249963897),
                            INT32_C(-1384621234), INT32_C(  997675190), INT32_C(  997675190), INT32_C(  997675190)) },
    { simde_mm512_set_epi32(INT32_C(  121649236), INT32_C( 1078857855), INT32_C( -789079366), INT32_C(  720922870),
                            INT32_C( 2041256669), INT32_C( -203208947), INT32_C( 1607011101), INT32_C(-1156829654),
                            INT32_C(  230848793), INT32_C( 1678224863), INT32_C( 2110278578), INT32_C(-1808926794),
                            INT32_C( 1395318189), INT32_C(  331190146), INT32_C(  150534496), INT32_C(  511594435)),
      UINT16_C(61391),
      -1035845727,
      simde_mm512_set_epi32(INT32_C(-1035845727), INT32_C(-1035845727), INT32_C(-1035845727), INT32_C(  720922870),
                            INT32_C(-1035845727), INT32_C(-1035845727), INT32_C(-1035845727), INT32_C(-1035845727),
                            INT32_C(-1035845727), INT32_C(-1035845727), INT32_C( 2110278578), INT32_C(-1808926794),
                            INT32_C(-1035845727), INT32_C(-1035845727), INT32_C(-1035845727), INT32_C(-1035845727)) },
    { simde_mm512_set_epi32(INT32_C( -439673063), INT32_C(  281345174), INT32_C( 1703672409), INT32_C( 1433894072),
                            INT32_C(-1374287391), INT32_C(-2054374124), INT32_C(-2087863688), INT32_C(  775409014),
                            INT32_C(  684629778), INT32_C(-1498533524), INT32_C( -208955538), INT32_C( 1063127700),
                            INT32_C(  429182470), INT32_C(-1892329828), INT32_C(  837229295), INT32_C( -115373033)),
      UINT16_C( 2879),
      -1796290912,
      simde_mm512_set_epi32(INT32_C( -439673063), INT32_C(  281345174), INT32_C( 1703672409), INT32_C( 1433894072),
                            INT32_C(-1796290912), INT32_C(-2054374124), INT32_C(-1796290912), INT32_C(-1796290912),
                            INT32_C(  684629778), INT32_C(-1498533524), INT32_C(-1796290912), INT32_C(-1796290912),
                            INT32_C(-1796290912), INT32_C(-1796290912), INT32_C(-1796290912), INT32_C(-1796290912)) },
    { simde_mm512_set_epi32(INT32_C(  211854878), INT32_C( 1120217162), INT32_C( 1399020352), INT32_C(-1730262794),
                            INT32_C( -217750907), INT32_C(-1958971298), INT32_C( 1308051941), INT32_C(  659156948),
                            INT32_C( -413755412), INT32_C(-1891691945), INT32_C(-1613764989), INT32_C( 1818229349),
                            INT32_C( 1838020027), INT32_C( 1546326520), INT32_C( 1564338027), INT32_C( 1340948138)),
      UINT16_C(26109),
        154532243,
      simde_mm512_set_epi32(INT32_C(  211854878), INT32_C(  154532243), INT32_C(  154532243), INT32_C(-1730262794),
                            INT32_C( -217750907), INT32_C(  154532243), INT32_C( 1308051941), INT32_C(  154532243),
                            INT32_C(  154532243), INT32_C(  154532243), INT32_C(  154532243), INT32_C(  154532243),
                            INT32_C(  154532243), INT32_C(  154532243), INT32_C( 1564338027), INT32_C(  154532243)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_set1_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_set1_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    int32_t a;
    simde__m512i r;
  } test_vec[8] = {
   {  UINT16_C(55449),
       1161879327,
      simde_mm512_set_epi32(INT32_C( 1161879327), INT32_C( 1161879327), INT32_C(          0), INT32_C( 1161879327),
                            INT32_C( 1161879327), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1161879327), INT32_C(          0), INT32_C(          0), INT32_C( 1161879327),
                            INT32_C( 1161879327), INT32_C(          0), INT32_C(          0), INT32_C( 1161879327)) },
   {  UINT16_C(42205),
        491258437,
      simde_mm512_set_epi32(INT32_C(  491258437), INT32_C(          0), INT32_C(  491258437), INT32_C(          0),
                            INT32_C(          0), INT32_C(  491258437), INT32_C(          0), INT32_C(          0),
                            INT32_C(  491258437), INT32_C(  491258437), INT32_C(          0), INT32_C(  491258437),
                            INT32_C(  491258437), INT32_C(  491258437), INT32_C(          0), INT32_C(  491258437)) },
   {  UINT16_C(46294),
       1464671644,
      simde_mm512_set_epi32(INT32_C( 1464671644), INT32_C(          0), INT32_C( 1464671644), INT32_C( 1464671644),
                            INT32_C(          0), INT32_C( 1464671644), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1464671644), INT32_C( 1464671644), INT32_C(          0), INT32_C( 1464671644),
                            INT32_C(          0), INT32_C( 1464671644), INT32_C( 1464671644), INT32_C(          0)) },
   {  UINT16_C(57846),
       1382569562,
      simde_mm512_set_epi32(INT32_C( 1382569562), INT32_C( 1382569562), INT32_C( 1382569562), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( 1382569562),
                            INT32_C( 1382569562), INT32_C( 1382569562), INT32_C( 1382569562), INT32_C( 1382569562),
                            INT32_C(          0), INT32_C( 1382569562), INT32_C( 1382569562), INT32_C(          0)) },
   {  UINT16_C(64688),
        417592133,
      simde_mm512_set_epi32(INT32_C(  417592133), INT32_C(  417592133), INT32_C(  417592133), INT32_C(  417592133),
                            INT32_C(  417592133), INT32_C(  417592133), INT32_C(          0), INT32_C(          0),
                            INT32_C(  417592133), INT32_C(          0), INT32_C(  417592133), INT32_C(  417592133),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
   {  UINT16_C(40468),
        103154350,
      simde_mm512_set_epi32(INT32_C(  103154350), INT32_C(          0), INT32_C(          0), INT32_C(  103154350),
                            INT32_C(  103154350), INT32_C(  103154350), INT32_C(  103154350), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  103154350),
                            INT32_C(          0), INT32_C(  103154350), INT32_C(          0), INT32_C(          0)) },
   {  UINT16_C(20696),
        487897671,
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(  487897671), INT32_C(          0), INT32_C(  487897671),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  487897671), INT32_C(  487897671), INT32_C(          0), INT32_C(  487897671),
                            INT32_C(  487897671), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
   {  UINT16_C(47493),
        643357764,
      simde_mm512_set_epi32(INT32_C(  643357764), INT32_C(          0), INT32_C(  643357764), INT32_C(  643357764),
                            INT32_C(  643357764), INT32_C(          0), INT32_C(          0), INT32_C(  643357764),
                            INT32_C(  643357764), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(  643357764), INT32_C(          0), INT32_C(  643357764)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_set1_epi32(test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_set1_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int64_t a;
    simde__m512i r;
  } test_vec[8] = {
    { -8789375007372599774,
      simde_mm512_set_epi64(INT64_C(-8789375007372599774), INT64_C(-8789375007372599774),
                            INT64_C(-8789375007372599774), INT64_C(-8789375007372599774),
                            INT64_C(-8789375007372599774), INT64_C(-8789375007372599774),
                            INT64_C(-8789375007372599774), INT64_C(-8789375007372599774)) },
    { -4285935604177939284,
      simde_mm512_set_epi64(INT64_C(-4285935604177939284), INT64_C(-4285935604177939284),
                            INT64_C(-4285935604177939284), INT64_C(-4285935604177939284),
                            INT64_C(-4285935604177939284), INT64_C(-4285935604177939284),
                            INT64_C(-4285935604177939284), INT64_C(-4285935604177939284)) },
    { -1541935515905504488,
      simde_mm512_set_epi64(INT64_C(-1541935515905504488), INT64_C(-1541935515905504488),
                            INT64_C(-1541935515905504488), INT64_C(-1541935515905504488),
                            INT64_C(-1541935515905504488), INT64_C(-1541935515905504488),
                            INT64_C(-1541935515905504488), INT64_C(-1541935515905504488)) },
    {  5952985382071947058,
      simde_mm512_set_epi64(INT64_C( 5952985382071947058), INT64_C( 5952985382071947058),
                            INT64_C( 5952985382071947058), INT64_C( 5952985382071947058),
                            INT64_C( 5952985382071947058), INT64_C( 5952985382071947058),
                            INT64_C( 5952985382071947058), INT64_C( 5952985382071947058)) },
    { -7162660555270519798,
      simde_mm512_set_epi64(INT64_C(-7162660555270519798), INT64_C(-7162660555270519798),
                            INT64_C(-7162660555270519798), INT64_C(-7162660555270519798),
                            INT64_C(-7162660555270519798), INT64_C(-7162660555270519798),
                            INT64_C(-7162660555270519798), INT64_C(-7162660555270519798)) },
    {  8404097979084250521,
      simde_mm512_set_epi64(INT64_C( 8404097979084250521), INT64_C( 8404097979084250521),
                            INT64_C( 8404097979084250521), INT64_C( 8404097979084250521),
                            INT64_C( 8404097979084250521), INT64_C( 8404097979084250521),
                            INT64_C( 8404097979084250521), INT64_C( 8404097979084250521)) },
    {   274863432779804064,
      simde_mm512_set_epi64(INT64_C(  274863432779804064), INT64_C(  274863432779804064),
                            INT64_C(  274863432779804064), INT64_C(  274863432779804064),
                            INT64_C(  274863432779804064), INT64_C(  274863432779804064),
                            INT64_C(  274863432779804064), INT64_C(  274863432779804064)) },
    { -6073562903357076278,
      simde_mm512_set_epi64(INT64_C(-6073562903357076278), INT64_C(-6073562903357076278),
                            INT64_C(-6073562903357076278), INT64_C(-6073562903357076278),
                            INT64_C(-6073562903357076278), INT64_C(-6073562903357076278),
                            INT64_C(-6073562903357076278), INT64_C(-6073562903357076278)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_set1_epi64(test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_set1_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i src;
    simde__mmask8 k;
    int64_t a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 1045216498523672669), INT64_C(-6036444540175881058),
                            INT64_C(-5911148920502355606), INT64_C(-7577028982327639795),
                            INT64_C(-2741592730704877834), INT64_C(-6453831303076951346),
                            INT64_C(-6689489276565790355), INT64_C(  202845396246057443)),
      UINT8_C(230),
        147395854529182590,
      simde_mm512_set_epi64(INT64_C(  147395854529182590), INT64_C(  147395854529182590),
                            INT64_C(  147395854529182590), INT64_C(-7577028982327639795),
                            INT64_C(-2741592730704877834), INT64_C(  147395854529182590),
                            INT64_C(  147395854529182590), INT64_C(  202845396246057443)) },
    { simde_mm512_set_epi64(INT64_C(-7718401035083209663), INT64_C(-3076780457048070953),
                            INT64_C( 6475016072843370494), INT64_C(-8381463578250516776),
                            INT64_C( 7440179812526306236), INT64_C(-1565233080792835049),
                            INT64_C(-3520705077242655190), INT64_C(  711599945422741640)),
      UINT8_C(183),
       7896918852801948623,
      simde_mm512_set_epi64(INT64_C( 7896918852801948623), INT64_C(-3076780457048070953),
                            INT64_C( 7896918852801948623), INT64_C( 7896918852801948623),
                            INT64_C( 7440179812526306236), INT64_C( 7896918852801948623),
                            INT64_C( 7896918852801948623), INT64_C( 7896918852801948623)) },
    { simde_mm512_set_epi64(INT64_C( 4486030894140599897), INT64_C( 6422628958957749227),
                            INT64_C(-5036188723709908563), INT64_C( 7249692644755604208),
                            INT64_C(-7968846935772652304), INT64_C(-1019958922473354647),
                            INT64_C( 5481721181155050457), INT64_C( 3220728135426515219)),
      UINT8_C(250),
       6737731418145878376,
      simde_mm512_set_epi64(INT64_C( 6737731418145878376), INT64_C( 6737731418145878376),
                            INT64_C( 6737731418145878376), INT64_C( 6737731418145878376),
                            INT64_C( 6737731418145878376), INT64_C(-1019958922473354647),
                            INT64_C( 6737731418145878376), INT64_C( 3220728135426515219)) },
    { simde_mm512_set_epi64(INT64_C(-6396453660831390526), INT64_C( 8933529613499491135),
                            INT64_C( -583608444119273487), INT64_C( 2774349158822651995),
                            INT64_C( 5342483589547515588), INT64_C(  169032945576329978),
                            INT64_C(-6862029605560509115), INT64_C( 6948715933942990141)),
      UINT8_C(144),
       5224961598009568585,
      simde_mm512_set_epi64(INT64_C( 5224961598009568585), INT64_C( 8933529613499491135),
                            INT64_C( -583608444119273487), INT64_C( 5224961598009568585),
                            INT64_C( 5342483589547515588), INT64_C(  169032945576329978),
                            INT64_C(-6862029605560509115), INT64_C( 6948715933942990141)) },
    { simde_mm512_set_epi64(INT64_C(-4346308446834850778), INT64_C( 2749670639259677889),
                            INT64_C(-1682235429196139261), INT64_C(-8570560540139381802),
                            INT64_C(-7853283901496397391), INT64_C(  153768084219711829),
                            INT64_C(-3210037353748455743), INT64_C(-4029896259883002015)),
      UINT8_C(214),
      -5146489163462262224,
      simde_mm512_set_epi64(INT64_C(-5146489163462262224), INT64_C(-5146489163462262224),
                            INT64_C(-1682235429196139261), INT64_C(-5146489163462262224),
                            INT64_C(-7853283901496397391), INT64_C(-5146489163462262224),
                            INT64_C(-5146489163462262224), INT64_C(-4029896259883002015)) },
    { simde_mm512_set_epi64(INT64_C( 6394437943527522650), INT64_C(-6125470791748892618),
                            INT64_C(-5975035781359101837), INT64_C( 4399409063692409934),
                            INT64_C(-8019209045639092618), INT64_C(-3157603671849839607),
                            INT64_C(-6814419689115640150), INT64_C( 5538401471960412489)),
      UINT8_C( 88),
       -748084489617986997,
      simde_mm512_set_epi64(INT64_C( 6394437943527522650), INT64_C( -748084489617986997),
                            INT64_C(-5975035781359101837), INT64_C( -748084489617986997),
                            INT64_C( -748084489617986997), INT64_C(-3157603671849839607),
                            INT64_C(-6814419689115640150), INT64_C( 5538401471960412489)) },
    { simde_mm512_set_epi64(INT64_C( 6475451416366061513), INT64_C( 3128457729014411682),
                            INT64_C( 4167134861407868007), INT64_C( 2076318686723048286),
                            INT64_C(  764926893292127387), INT64_C(-3471922167199587188),
                            INT64_C(-1007473193319966067), INT64_C(-7587900950013848349)),
      UINT8_C( 14),
      -3095861881784422408,
      simde_mm512_set_epi64(INT64_C( 6475451416366061513), INT64_C( 3128457729014411682),
                            INT64_C( 4167134861407868007), INT64_C( 2076318686723048286),
                            INT64_C(-3095861881784422408), INT64_C(-3095861881784422408),
                            INT64_C(-3095861881784422408), INT64_C(-7587900950013848349)) },
    { simde_mm512_set_epi64(INT64_C(-8918688664014182717), INT64_C(-5923824341695687917),
                            INT64_C(  597335319340416274), INT64_C(-6405873593024845306),
                            INT64_C( 9156616106305782892), INT64_C(-3930771615997737816),
                            INT64_C(-3489614562807589194), INT64_C(-6234599678791232286)),
      UINT8_C( 48),
      -2201472844397108415,
      simde_mm512_set_epi64(INT64_C(-8918688664014182717), INT64_C(-5923824341695687917),
                            INT64_C(-2201472844397108415), INT64_C(-2201472844397108415),
                            INT64_C( 9156616106305782892), INT64_C(-3930771615997737816),
                            INT64_C(-3489614562807589194), INT64_C(-6234599678791232286)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_set1_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_set1_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    int64_t a;
    simde__m512i r;
  } test_vec[8] = {
    { UINT8_C(207),
       9161374966470958313,
      simde_mm512_set_epi64(INT64_C( 9161374966470958313), INT64_C( 9161374966470958313),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C( 9161374966470958313), INT64_C( 9161374966470958313),
                            INT64_C( 9161374966470958313), INT64_C( 9161374966470958313)) },
    { UINT8_C( 52),
      -5504071340329784539,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-5504071340329784539), INT64_C(-5504071340329784539),
                            INT64_C(                   0), INT64_C(-5504071340329784539),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C( 37),
      -4694012945600318045,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-4694012945600318045), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(-4694012945600318045),
                            INT64_C(                   0), INT64_C(-4694012945600318045)) },
    { UINT8_C( 77),
      -4616382267006571958,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(-4616382267006571958),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-4616382267006571958), INT64_C(-4616382267006571958),
                            INT64_C(                   0), INT64_C(-4616382267006571958)) },
    { UINT8_C( 33),
      -7296455954195359480,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-7296455954195359480), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(-7296455954195359480)) },
    { UINT8_C( 47),
      -8949112185126954032,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-8949112185126954032), INT64_C(                   0),
                            INT64_C(-8949112185126954032), INT64_C(-8949112185126954032),
                            INT64_C(-8949112185126954032), INT64_C(-8949112185126954032)) },
    { UINT8_C( 80),
       8577224771648710248,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C( 8577224771648710248),
                            INT64_C(                   0), INT64_C( 8577224771648710248),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C(  2),
      -5341779416438471199,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(-5341779416438471199), INT64_C(                   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_maskz_set1_epi64(test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

#if defined(SIMDE_FLOAT16_IS_SCALAR)
static int
test_simde_mm512_set1_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float16 a;
    const simde_float16 r[32];
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(   -85.88),
      { SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88),
        SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88),
        SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88),
        SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88),
        SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88),
        SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88),
        SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88),
        SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   -85.88) } },
    { SIMDE_FLOAT16_VALUE(   -49.66),
      { SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66),
        SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66),
        SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66),
        SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66),
        SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66),
        SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66),
        SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66),
        SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66), SIMDE_FLOAT16_VALUE(   -49.66) } },
    { SIMDE_FLOAT16_VALUE(    22.06),
      { SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06),
        SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06),
        SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06),
        SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06),
        SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06),
        SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06),
        SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06),
        SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    22.06) } },
    { SIMDE_FLOAT16_VALUE(   -38.62),
      { SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62),
        SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62),
        SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62),
        SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62),
        SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62),
        SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62),
        SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62),
        SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62), SIMDE_FLOAT16_VALUE(   -38.62) } },
    { SIMDE_FLOAT16_VALUE(    89.62),
      { SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62),
        SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62),
        SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62),
        SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62),
        SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62),
        SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62),
        SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62),
        SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62), SIMDE_FLOAT16_VALUE(    89.62) } },
    { SIMDE_FLOAT16_VALUE(   -97.06),
      { SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06),
        SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06),
        SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06),
        SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06),
        SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06),
        SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06),
        SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06),
        SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06), SIMDE_FLOAT16_VALUE(   -97.06) } },
    { SIMDE_FLOAT16_VALUE(    72.44),
      { SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44),
        SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44),
        SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44),
        SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44),
        SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44),
        SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44),
        SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44),
        SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    72.44) } },
    { SIMDE_FLOAT16_VALUE(    81.69),
      { SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69),
        SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69),
        SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69),
        SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69),
        SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69),
        SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69),
        SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69),
        SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    81.69) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512h r = simde_mm512_set1_ph(test_vec[i].a);
    simde_test_x86_assert_equal_f16x32(r, simde_mm512_loadu_ph(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16 a = simde_test_codegen_random_f16(SIMDE_FLOAT16_VALUE(-100.0), SIMDE_FLOAT16_VALUE(100.0));
    simde__m512h r = simde_mm512_set1_ph(a);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set1_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_set1_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_set1_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_set1_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_set1_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set1_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set1_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_set1_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_set1_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set1_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_set1_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_set1_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set1_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set1_pd)
  #if defined(SIMDE_FLOAT16_IS_SCALAR)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set1_ph)
  #endif
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
