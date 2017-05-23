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

#if defined(__MMX__)
#define SIMDE_MMX_NO_NATIVE
#include <simde/x86/mmx.h>
#include <mmintrin.h>

#include <test/x86/compare.h>

define_test_cmp_VT_2xVT(_m64, mm_add_pi8,      i8)
define_test_cmp_VT_2xVT(_m64, mm_add_pi16,    i16)
define_test_cmp_VT_2xVT(_m64, mm_add_pi32,    i32)
define_test_cmp_VT_2xVT(_m64, mm_adds_pi8,     i8)
define_test_cmp_VT_2xVT(_m64, mm_adds_pi16,   i16)
define_test_cmp_VT_2xVT(_m64, mm_adds_pu8,     u8)
define_test_cmp_VT_2xVT(_m64, mm_adds_pu16,   u16)
define_test_cmp_VT_2xVT(_m64, mm_and_si64,    i64)
define_test_cmp_VT_2xVT(_m64, mm_andnot_si64, i64)
define_test_cmp_VT_2xVT(_m64, mm_cmpeq_pi8,    i8)
define_test_cmp_VT_2xVT(_m64, mm_cmpeq_pi16,  i16)
define_test_cmp_VT_2xVT(_m64, mm_cmpeq_pi32,  i32)
define_test_cmp_VT_2xVT(_m64, mm_cmpgt_pi8,    i8)
define_test_cmp_VT_2xVT(_m64, mm_cmpgt_pi16,  i16)
define_test_cmp_VT_2xVT(_m64, mm_cmpgt_pi32,  i32)
define_test_cmp_VT_2xVT(_m64, mm_madd_pi16,   i16)
define_test_cmp_VT_2xVT(_m64, mm_mulhi_pi16,  i16)
define_test_cmp_VT_2xVT(_m64, mm_mullo_pi16,  i16)
define_test_cmp_VT_2xVT(_m64, mm_or_si64,     i64)
define_test_cmp_VT_2xVT(_m64, mm_packs_pi16,  i16)
define_test_cmp_VT_2xVT(_m64, mm_packs_pi32,  i32)
define_test_cmp_VT_2xVT(_m64, mm_packs_pu16,  u16)

static MunitResult
test_simde_mm_sll_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m64 na, ncount, nr;
  simde__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ((int64_t*) &(ncount))[0] = munit_rand_int_range(0, 16);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = _mm_sll_pi16(na, ncount);
  er = simde_mm_sll_pi16(ea, ecount);

  simde_assert_m64_i16(nr, ==, er);

  _mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m64 na, ncount, nr;
  simde__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ((int64_t*) &(ncount))[0] = munit_rand_int_range(0, 32);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = _mm_sll_pi32(na, ncount);
  er = simde_mm_sll_pi32(ea, ecount);

  simde_assert_m64_i32(nr, ==, er);

  _mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m64 na, ncount, nr;
  simde__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ((int64_t*) &(ncount))[0] = munit_rand_int_range(0, 64);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = _mm_sll_si64(na, ncount);
  er = simde_mm_sll_si64(ea, ecount);

  simde_assert_m64_i64(nr, ==, er);

  _mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m64 na, ncount, nr;
  simde__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ((int64_t*) &(ncount))[0] = munit_rand_int_range(0, 16);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = _mm_srl_pi16(na, ncount);
  er = simde_mm_srl_pi16(ea, ecount);

  simde_assert_m64_i16(nr, ==, er);

  _mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m64 na, ncount, nr;
  simde__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ((int64_t*) &(ncount))[0] = munit_rand_int_range(0, 32);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = _mm_srl_pi32(na, ncount);
  er = simde_mm_srl_pi32(ea, ecount);

  simde_assert_m64_i32(nr, ==, er);

  _mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m64 na, ncount, nr;
  simde__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ((int64_t*) &(ncount))[0] = munit_rand_int_range(0, 64);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = _mm_srl_si64(na, ncount);
  er = simde_mm_srl_si64(ea, ecount);

  simde_assert_m64_i64(nr, ==, er);

  _mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sra_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m64 na, ncount, nr;
  simde__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ((int64_t*) &(ncount))[0] = munit_rand_int_range(0, 16);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = _mm_sra_pi16(na, ncount);
  er = simde_mm_sra_pi16(ea, ecount);

  simde_assert_m64_i16(nr, ==, er);

  _mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sra_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m64 na, ncount, nr;
  simde__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ((int64_t*) &(ncount))[0] = munit_rand_int_range(0, 32);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = _mm_sra_pi32(na, ncount);
  er = simde_mm_sra_pi32(ea, ecount);

  simde_assert_m64_i32(nr, ==, er);

  _mm_empty();
  return MUNIT_OK;
}

define_test_cmp_VT_2xVT(_m64, mm_sub_pi8,        i8)
define_test_cmp_VT_2xVT(_m64, mm_sub_pi16,      i16)
define_test_cmp_VT_2xVT(_m64, mm_sub_pi32,      i32)
define_test_cmp_VT_2xVT(_m64, mm_subs_pi8,       i8)
define_test_cmp_VT_2xVT(_m64, mm_subs_pi16,     i16)
define_test_cmp_VT_2xVT(_m64, mm_subs_pu8,       u8)
define_test_cmp_VT_2xVT(_m64, mm_subs_pu16,     u16)
define_test_cmp_VT_2xVT(_m64, mm_unpackhi_pi8,   i8)
define_test_cmp_VT_2xVT(_m64, mm_unpackhi_pi16, i16)
define_test_cmp_VT_2xVT(_m64, mm_unpackhi_pi32, i32)
define_test_cmp_VT_2xVT(_m64, mm_unpacklo_pi8,   i8)
define_test_cmp_VT_2xVT(_m64, mm_unpacklo_pi16, i16)
define_test_cmp_VT_2xVT(_m64, mm_unpacklo_pi32, i32)
define_test_cmp_VT_2xVT(_m64, mm_xor_si64,      i64)

static MunitTest test_suite_tests[] = {
  TEST_FUNC_CMP(mm_add_pi8),
  TEST_FUNC_CMP(mm_add_pi16),
  TEST_FUNC_CMP(mm_add_pi32),
  TEST_FUNC_CMP(mm_adds_pi8),
  TEST_FUNC_CMP(mm_adds_pi16),
  TEST_FUNC_CMP(mm_adds_pu8),
  TEST_FUNC_CMP(mm_adds_pu16),
  TEST_FUNC_CMP(mm_and_si64),
  TEST_FUNC_CMP(mm_andnot_si64),
  TEST_FUNC_CMP(mm_cmpeq_pi8),
  TEST_FUNC_CMP(mm_cmpeq_pi16),
  TEST_FUNC_CMP(mm_cmpeq_pi32),
  TEST_FUNC_CMP(mm_cmpgt_pi8),
  TEST_FUNC_CMP(mm_cmpgt_pi16),
  TEST_FUNC_CMP(mm_cmpgt_pi32),
  TEST_FUNC_CMP(mm_madd_pi16),
  TEST_FUNC_CMP(mm_mulhi_pi16),
  TEST_FUNC_CMP(mm_mullo_pi16),
  TEST_FUNC_CMP(mm_or_si64),
  TEST_FUNC_CMP(mm_packs_pi16),
  TEST_FUNC_CMP(mm_packs_pi32),
  TEST_FUNC_CMP(mm_packs_pu16),
  TEST_FUNC_CMP(mm_sll_pi16),
  TEST_FUNC_CMP(mm_sll_pi32),
  TEST_FUNC_CMP(mm_sll_si64),
  TEST_FUNC_CMP(mm_srl_pi16),
  TEST_FUNC_CMP(mm_srl_pi32),
  TEST_FUNC_CMP(mm_srl_si64),
  TEST_FUNC_CMP(mm_sra_pi16),
  TEST_FUNC_CMP(mm_sra_pi32),
  TEST_FUNC_CMP(mm_sub_pi8),
  TEST_FUNC_CMP(mm_sub_pi16),
  TEST_FUNC_CMP(mm_sub_pi32),
  TEST_FUNC_CMP(mm_subs_pi8),
  TEST_FUNC_CMP(mm_subs_pi16),
  TEST_FUNC_CMP(mm_subs_pu8),
  TEST_FUNC_CMP(mm_subs_pu16),
  TEST_FUNC_CMP(mm_unpackhi_pi8),
  TEST_FUNC_CMP(mm_unpackhi_pi16),
  TEST_FUNC_CMP(mm_unpackhi_pi32),
  TEST_FUNC_CMP(mm_unpacklo_pi8),
  TEST_FUNC_CMP(mm_unpacklo_pi16),
  TEST_FUNC_CMP(mm_unpacklo_pi32),
  TEST_FUNC_CMP(mm_xor_si64),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#else
static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#endif

MunitSuite simde_mmx_cmp_test_suite = {
  (char*) "/mmx",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
