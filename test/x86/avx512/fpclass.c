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

#define SIMDE_TEST_X86_AVX512_INSN fpclass

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/fpclass.h>

static int
test_simde_mm256_fpclass_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde_float32 sNaNf = simde_uint32_as_float32(0xff800011),
                denormalf = simde_uint32_as_float32(0x007fffff);
  simde__m256 a = simde_mm256_set_ps(
      SIMDE_MATH_NANF        , SIMDE_FLOAT32_C(0.0),
      -SIMDE_FLOAT32_C(0.0)  , SIMDE_MATH_INFINITYF,
      -SIMDE_MATH_INFINITYF  , denormalf,
      -SIMDE_FLOAT32_C(42.23), sNaNf);
  simde_assert_equal_mmask8(simde_mm256_fpclass_ps_mask(a, 0x01), 128);
  simde_assert_equal_mmask8(simde_mm256_fpclass_ps_mask(a, 0x02), 64);
  simde_assert_equal_mmask8(simde_mm256_fpclass_ps_mask(a, 0x04), 32);
  simde_assert_equal_mmask8(simde_mm256_fpclass_ps_mask(a, 0x08), 16);
  simde_assert_equal_mmask8(simde_mm256_fpclass_ps_mask(a, 0x10), 8);
  simde_assert_equal_mmask8(simde_mm256_fpclass_ps_mask(a, 0x20), 4);
  simde_assert_equal_mmask8(simde_mm256_fpclass_ps_mask(a, 0x40), 2);
  simde_assert_equal_mmask8(simde_mm256_fpclass_ps_mask(a, 0x80), 1);

  return 0;
#else
  fputc('\n', stdout);

  simde_float32 sNaNf = simde_uint32_as_float32(0xff800011),
                denormalf = simde_uint32_as_float32(0x007fffff);
  simde__m256 a = simde_mm256_set_ps(
      SIMDE_MATH_NANF        , SIMDE_FLOAT32_C(0.0),
      -SIMDE_FLOAT32_C(0.0)  , SIMDE_MATH_INFINITYF,
      -SIMDE_MATH_INFINITYF  , denormalf,
      -SIMDE_FLOAT32_C(42.23), sNaNf);
  simde__mmask8 r0 = simde_mm256_fpclass_ps_mask(a, SIMDE_MATH_FP_QNAN);
  simde__mmask8 r1 = simde_mm256_fpclass_ps_mask(a, SIMDE_MATH_FP_PZERO);
  simde__mmask8 r2 = simde_mm256_fpclass_ps_mask(a, SIMDE_MATH_FP_NZERO);
  simde__mmask8 r3 = simde_mm256_fpclass_ps_mask(a, SIMDE_MATH_FP_PINF);
  simde__mmask8 r4 = simde_mm256_fpclass_ps_mask(a, SIMDE_MATH_FP_NINF);
  simde__mmask8 r5 = simde_mm256_fpclass_ps_mask(a, SIMDE_MATH_FP_DENORMAL);
  simde__mmask8 r6 = simde_mm256_fpclass_ps_mask(a, SIMDE_MATH_FP_NEGATIVE);
  simde__mmask8 r7 = simde_mm256_fpclass_ps_mask(a, SIMDE_MATH_FP_SNAN);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_mmask8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  return 1;
#endif
}

static int
test_simde_mm512_fpclass_ph_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde_float16 qNaN = SIMDE_NANHF,
                denormal = simde_uint16_as_float16(0x0001),
                pzero = simde_uint16_as_float16(0x0000),
                nzero = simde_uint16_as_float16(0x8000),
                pinfinity = SIMDE_INFINITYHF, //simde_uint16_as_float16(0x7C00),
                ninfinity = SIMDE_NINFINITYHF, //simde_uint16_as_float16(0xFC00),
                sNaN = simde_uint16_as_float16(0x7C01);
  simde__m512h a = simde_mm512_set_ph(
      SIMDE_FLOAT16_VALUE(    31.00), SIMDE_FLOAT16_VALUE(    30.00), SIMDE_FLOAT16_VALUE(    29.00), SIMDE_FLOAT16_VALUE(    28.00),
      SIMDE_FLOAT16_VALUE(    27.00), SIMDE_FLOAT16_VALUE(    26.00), SIMDE_FLOAT16_VALUE(    25.00), SIMDE_FLOAT16_VALUE(    24.00),
      SIMDE_FLOAT16_VALUE(    23.00), SIMDE_FLOAT16_VALUE(    22.00), SIMDE_FLOAT16_VALUE(    21.00), SIMDE_FLOAT16_VALUE(    20.00),
      SIMDE_FLOAT16_VALUE(    19.00), SIMDE_FLOAT16_VALUE(    18.00), SIMDE_FLOAT16_VALUE(    17.00), SIMDE_FLOAT16_VALUE(    16.00),
      SIMDE_FLOAT16_VALUE(    15.00), SIMDE_FLOAT16_VALUE(    14.00), SIMDE_FLOAT16_VALUE(    13.00), SIMDE_FLOAT16_VALUE(    12.00),
      SIMDE_FLOAT16_VALUE(    11.00), SIMDE_FLOAT16_VALUE(    10.00), SIMDE_FLOAT16_VALUE(     9.00), SIMDE_FLOAT16_VALUE(     8.00),
      qNaN                       , pzero,
      nzero                      , pinfinity,
      ninfinity                  , denormal,
      SIMDE_FLOAT16_VALUE(-42.23), sNaN);
  #if !defined(SIMDE_ARCH_ARM_CHECK) || !SIMDE_ARCH_ARM_CHECK(4, 0)
    simde_assert_equal_mmask32(simde_mm512_fpclass_ph_mask(a, 0x01), 128);
    // armel silently converts the signaling NaN to a quiet one???
  #endif
  simde_assert_equal_mmask32(simde_mm512_fpclass_ph_mask(a, 0x02), 64);
  simde_assert_equal_mmask32(simde_mm512_fpclass_ph_mask(a, 0x04), 32);
  simde_assert_equal_mmask32(simde_mm512_fpclass_ph_mask(a, 0x08), 16);
  simde_assert_equal_mmask32(simde_mm512_fpclass_ph_mask(a, 0x10), 8);
  simde_assert_equal_mmask32(simde_mm512_fpclass_ph_mask(a, 0x20), 4);
  simde_assert_equal_mmask32(simde_mm512_fpclass_ph_mask(a, 0x40), 2);
  #if !defined(SIMDE_ARCH_ARM_CHECK) || !SIMDE_ARCH_ARM_CHECK(4, 0)
    simde_assert_equal_mmask32(simde_mm512_fpclass_ph_mask(a, 0x80), 1);
  #endif

  return 0;
#else
  fputc('\n', stdout);

  simde_float16 qNaN = simde_uint16_as_float16(0x7E00),
                denormal = simde_uint16_as_float16(0x0001),
                pzero = simde_uint16_as_float16(0x0000),
                nzero = simde_uint16_as_float16(0x8000),
                pinfinity = simde_uint16_as_float16(0x7C00),
                ninfinity = simde_uint16_as_float16(0xFC00),
                sNaN = simde_uint16_as_float16(0x7C01);
  simde__m512h a = simde_mm512_set_ph(
      SIMDE_FLOAT16_VALUE(    31.00), SIMDE_FLOAT16_VALUE(    30.00), SIMDE_FLOAT16_VALUE(    29.00), SIMDE_FLOAT16_VALUE(    28.00),
      SIMDE_FLOAT16_VALUE(    27.00), SIMDE_FLOAT16_VALUE(    26.00), SIMDE_FLOAT16_VALUE(    25.00), SIMDE_FLOAT16_VALUE(    24.00),
      SIMDE_FLOAT16_VALUE(    23.00), SIMDE_FLOAT16_VALUE(    22.00), SIMDE_FLOAT16_VALUE(    21.00), SIMDE_FLOAT16_VALUE(    20.00),
      SIMDE_FLOAT16_VALUE(    19.00), SIMDE_FLOAT16_VALUE(    18.00), SIMDE_FLOAT16_VALUE(    17.00), SIMDE_FLOAT16_VALUE(    16.00),
      SIMDE_FLOAT16_VALUE(    15.00), SIMDE_FLOAT16_VALUE(    14.00), SIMDE_FLOAT16_VALUE(    13.00), SIMDE_FLOAT16_VALUE(    12.00),
      SIMDE_FLOAT16_VALUE(    11.00), SIMDE_FLOAT16_VALUE(    10.00), SIMDE_FLOAT16_VALUE(     9.00), SIMDE_FLOAT16_VALUE(     8.00),
      qNaN                       , pzero,
      nzero                      , pinfinity,
      ninfinity                  , denormal,
      SIMDE_FLOAT16_VALUE(-42.23), sNaN);
  simde__mmask32 r0 = simde_mm512_fpclass_ph_mask(a, SIMDE_MATH_FP_QNAN);
  simde__mmask32 r1 = simde_mm512_fpclass_ph_mask(a, SIMDE_MATH_FP_PZERO);
  simde__mmask32 r2 = simde_mm512_fpclass_ph_mask(a, SIMDE_MATH_FP_NZERO);
  simde__mmask32 r3 = simde_mm512_fpclass_ph_mask(a, SIMDE_MATH_FP_PINF);
  simde__mmask32 r4 = simde_mm512_fpclass_ph_mask(a, SIMDE_MATH_FP_NINF);
  simde__mmask32 r5 = simde_mm512_fpclass_ph_mask(a, SIMDE_MATH_FP_DENORMAL);
  simde__mmask32 r6 = simde_mm512_fpclass_ph_mask(a, SIMDE_MATH_FP_NEGATIVE);
  simde__mmask32 r7 = simde_mm512_fpclass_ph_mask(a, SIMDE_MATH_FP_SNAN);

  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_mmask32(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r7, SIMDE_TEST_VEC_POS_LAST);
  return 1;
#endif
}


static int
test_simde_mm512_fpclass_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde_float64 sNaNf = simde_uint64_as_float64(0x7FF0000000000001),
                denormalf = simde_uint64_as_float64(0x0000000000000001);
  simde__m512d a = simde_mm512_set_pd(
      SIMDE_MATH_NAN         , SIMDE_FLOAT64_C(0.0),
      -SIMDE_FLOAT64_C(0.0)  , SIMDE_MATH_INFINITY,
      -SIMDE_MATH_INFINITY   , denormalf,
      -SIMDE_FLOAT64_C(42.23), sNaNf);
  simde_assert_equal_mmask8(simde_mm512_fpclass_pd_mask(a, 0x01), 128);
  simde_assert_equal_mmask8(simde_mm512_fpclass_pd_mask(a, 0x02), 64);
  simde_assert_equal_mmask8(simde_mm512_fpclass_pd_mask(a, 0x04), 32);
  simde_assert_equal_mmask8(simde_mm512_fpclass_pd_mask(a, 0x08), 16);
  simde_assert_equal_mmask8(simde_mm512_fpclass_pd_mask(a, 0x10), 8);
  simde_assert_equal_mmask8(simde_mm512_fpclass_pd_mask(a, 0x20), 4);
  simde_assert_equal_mmask8(simde_mm512_fpclass_pd_mask(a, 0x40), 2);
  simde_assert_equal_mmask8(simde_mm512_fpclass_pd_mask(a, 0x80), 1);

  return 0;
#else
  fputc('\n', stdout);

  simde_float64 sNaNf = simde_uint64_as_float64(0x7FF0000000000001),
                denormalf = simde_uint64_as_float64(0x0000000000000001);
  simde__m512d a = simde_mm512_set_pd(
      SIMDE_MATH_NAN         , SIMDE_FLOAT64_C(0.0),
      -SIMDE_FLOAT64_C(0.0)  , SIMDE_MATH_INFINITY,
      -SIMDE_MATH_INFINITY   , denormalf,
      -SIMDE_FLOAT64_C(42.23), sNaNf);
  simde__mmask8 r0 = simde_mm512_fpclass_pd_mask(a, SIMDE_MATH_FP_QNAN);
  simde__mmask8 r1 = simde_mm512_fpclass_pd_mask(a, SIMDE_MATH_FP_PZERO);
  simde__mmask8 r2 = simde_mm512_fpclass_pd_mask(a, SIMDE_MATH_FP_NZERO);
  simde__mmask8 r3 = simde_mm512_fpclass_pd_mask(a, SIMDE_MATH_FP_PINF);
  simde__mmask8 r4 = simde_mm512_fpclass_pd_mask(a, SIMDE_MATH_FP_NINF);
  simde__mmask8 r5 = simde_mm512_fpclass_pd_mask(a, SIMDE_MATH_FP_DENORMAL);
  simde__mmask8 r6 = simde_mm512_fpclass_pd_mask(a, SIMDE_MATH_FP_NEGATIVE);
  simde__mmask8 r7 = simde_mm512_fpclass_pd_mask(a, SIMDE_MATH_FP_SNAN);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_mmask8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fpclass_ps_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fpclass_ph_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fpclass_pd_mask)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
