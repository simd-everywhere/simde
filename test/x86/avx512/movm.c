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

#define SIMDE_TEST_X86_AVX512_INSN movm

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/movm.h>

static int
test_simde_mm_movm_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m128i r;
  } test_vec[8] = {
    { UINT16_C(62934),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { UINT16_C( 3839),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT16_C(60519),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT16_C(28066),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { UINT16_C( 8975),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT16_C(35700),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { UINT16_C(45525),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1)) },
    { UINT16_C( 9017),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movm_epi8(test_vec[i].k);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_movm_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask32 k;
    simde__m256i r;
  } test_vec[8] = {
    { UINT32_C(3131962838),
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { UINT32_C(1926696703),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT32_C(2248141927),
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT32_C(1480879522),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { UINT32_C(1377641231),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT32_C( 395086708),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { UINT32_C(1313583573),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1)) },
    { UINT32_C(2432705337),
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_movm_epi8(test_vec[i].k);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movm_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask64 k;
    simde__m512i r;
  } test_vec[8] = {
    { UINT64_C( 4739015484227475748),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { UINT64_C( 9729215686767344119),
      simde_mm512_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT64_C(13732001478625865871),
      simde_mm512_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { UINT64_C( 1583258323140482986),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { UINT64_C(11672091627232461942),
      simde_mm512_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { UINT64_C( 2094101018860790606),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { UINT64_C( 4680871035071032016),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { UINT64_C( 4209047041590863189),
      simde_mm512_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                           INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                           INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_movm_epi8(test_vec[i].k);
    simde_assert_m512i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_movm_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m128i r;
  } test_vec[8] = {
    { UINT8_C(216),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT8_C( 89),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { UINT8_C(101),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { UINT8_C( 61),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { UINT8_C(225),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { UINT8_C(231),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                         INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1)) },
    { UINT8_C(114),
      simde_mm_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                         INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { UINT8_C(147),
      simde_mm_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                         INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movm_epi16(test_vec[i].k);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_movm_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m256i r;
  } test_vec[8] = {
    { UINT16_C( 9176),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT16_C( 7781),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { UINT16_C(51425),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { UINT16_C(64626),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { UINT16_C(41021),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { UINT16_C(29062),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { UINT16_C(12635),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1)) },
    { UINT16_C(14754),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_movm_epi16(test_vec[i].k);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movm_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask32 k;
    simde__m512i r;
  } test_vec[8] = {
    { UINT32_C(2805036472),
      simde_mm512_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT32_C(2266796856),
      simde_mm512_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(     0)) },
    { UINT32_C(3598176466),
      simde_mm512_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { UINT32_C( 689971098),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { UINT32_C(2581729150),
      simde_mm512_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
    { UINT32_C(1365267719),
      simde_mm512_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1)) },
    { UINT32_C(4094538289),
      simde_mm512_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
    { UINT32_C(3608627761),
      simde_mm512_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_movm_epi16(test_vec[i].k);
    simde_assert_m512i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_movm_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m128i r;
  } test_vec[8] = {
    { UINT8_C(  8),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { UINT8_C(  9),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(  5),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C( 13),
      simde_mm_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(  1),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(  7),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { UINT8_C(  2),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { UINT8_C(  3),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movm_epi32(test_vec[i].k);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_movm_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m256i r;
  } test_vec[8] = {
    { UINT8_C(216),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { UINT8_C( 89),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(101),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C( 61),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(225),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT8_C(231),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { UINT8_C(114),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { UINT8_C(147),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_movm_epi32(test_vec[i].k);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movm_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i r;
  } test_vec[8] = {
    { UINT16_C(30136),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { UINT16_C(37688),
      simde_mm512_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { UINT16_C(53458),
      simde_mm512_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { UINT16_C( 8090),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { UINT16_C( 3966),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) },
    { UINT16_C(21767),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)) },
    { UINT16_C(45617),
      simde_mm512_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { UINT16_C(18993),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0),
                            INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_movm_epi32(test_vec[i].k);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_movm_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m128i r;
  } test_vec[8] = {
    { UINT8_C(184),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C( 56),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C(210),
      simde_mm_set_epi64x(INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(154),
      simde_mm_set_epi64x(INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(126),
      simde_mm_set_epi64x(INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(  7),
      simde_mm_set_epi64x(INT64_C(                  -1), INT64_C(                  -1)) },
    { UINT8_C( 49),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(                  -1)) },
    { UINT8_C( 49),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(                  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movm_epi64(test_vec[i].k);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm256_movm_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m256i r;
  } test_vec[8] = {
    { UINT8_C(184),
      simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C( 56),
      simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C(210),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(154),
      simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                   0),
                             INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(126),
      simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                  -1),
                             INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(  7),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                  -1),
                             INT64_C(                  -1), INT64_C(                  -1)) },
    { UINT8_C( 49),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                  -1)) },
    { UINT8_C( 49),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_movm_epi64(test_vec[i].k);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movm_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i r;
  } test_vec[8] = {
    { UINT8_C(184),
      simde_mm512_set_epi64(INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                  -1),
                            INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C( 56),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                  -1),
                            INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { UINT8_C(210),
      simde_mm512_set_epi64(INT64_C(                  -1), INT64_C(                  -1),
                            INT64_C(                   0), INT64_C(                  -1),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(154),
      simde_mm512_set_epi64(INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                  -1),
                            INT64_C(                  -1), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(126),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                  -1),
                            INT64_C(                  -1), INT64_C(                  -1),
                            INT64_C(                  -1), INT64_C(                  -1),
                            INT64_C(                  -1), INT64_C(                   0)) },
    { UINT8_C(  7),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                  -1),
                            INT64_C(                  -1), INT64_C(                  -1)) },
    { UINT8_C( 49),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                  -1),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                  -1)) },
    { UINT8_C( 49),
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                  -1), INT64_C(                  -1),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                  -1)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_movm_epi64(test_vec[i].k);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movm_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_movm_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movm_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movm_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_movm_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movm_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movm_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_movm_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movm_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movm_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_movm_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movm_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
