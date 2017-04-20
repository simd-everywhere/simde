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

#include "../mmx.h"
#if defined(SIMDE_MMX_NATIVE)
#  define SIMDE_TEST_MMX_NATIVE
#  undef SIMDE_PREFIX
#  define SIMDE_PREFIX simde_emul_
#  define SIMDE_NO_NATIVE
#  define SIMDE_MULTIPLE_INCLUDES
#  include "../mmx.h"

enum {
  TEST_ELEMENT_TYPE_U8,
  TEST_ELEMENT_TYPE_U16,
  TEST_ELEMENT_TYPE_U32,
  TEST_ELEMENT_TYPE_U64,
  TEST_ELEMENT_TYPE_I8,
  TEST_ELEMENT_TYPE_I16,
  TEST_ELEMENT_TYPE_I32,
  TEST_ELEMENT_TYPE_I64,
  TEST_ELEMENT_TYPE_F32,
} TestElementType;

static MunitResult
cmp_i8_m64_2xm64(const MunitParameter params[], void* data,
		 simde__m64 (* native_func)(simde__m64 a, simde__m64 b),
		 simde_emul__m64 (* emul_func)(simde_emul__m64 a, simde_emul__m64 b)) {
  (void) params;
  (void) data;

  simde__m64 na, nb, nr;
  simde_emul__m64 ea, eb, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  munit_rand_memory(sizeof(nb), (uint8_t*) &nb);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&eb, &nb, sizeof(nb));

  nr = native_func(na, nb);
  er = emul_func(ea, eb);

  simde_assert_m64_i8(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
cmp_i16_m64_2xm64(const MunitParameter params[], void* data,
		  simde__m64 (* native_func)(simde__m64 a, simde__m64 b),
		  simde_emul__m64 (* emul_func)(simde_emul__m64 a, simde_emul__m64 b)) {
  (void) params;
  (void) data;

  simde__m64 na, nb, nr;
  simde_emul__m64 ea, eb, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  munit_rand_memory(sizeof(nb), (uint8_t*) &nb);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&eb, &nb, sizeof(nb));

  nr = native_func(na, nb);
  er = emul_func(ea, eb);

  simde_assert_m64_i16(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
cmp_i32_m64_2xm64(const MunitParameter params[], void* data,
		  simde__m64 (* native_func)(simde__m64 a, simde__m64 b),
		  simde_emul__m64 (* emul_func)(simde_emul__m64 a, simde_emul__m64 b)) {
  (void) params;
  (void) data;

  simde__m64 na, nb, nr;
  simde_emul__m64 ea, eb, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  munit_rand_memory(sizeof(nb), (uint8_t*) &nb);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&eb, &nb, sizeof(nb));

  nr = native_func(na, nb);
  er = emul_func(ea, eb);

  simde_assert_m64_i32(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
cmp_i64_m64_2xm64(const MunitParameter params[], void* data,
		  simde__m64 (* native_func)(simde__m64 a, simde__m64 b),
		  simde_emul__m64 (* emul_func)(simde_emul__m64 a, simde_emul__m64 b)) {
  (void) params;
  (void) data;

  simde__m64 na, nb, nr;
  simde_emul__m64 ea, eb, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  munit_rand_memory(sizeof(nb), (uint8_t*) &nb);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&eb, &nb, sizeof(nb));

  nr = native_func(na, nb);
  er = emul_func(ea, eb);

  simde_assert_m64_i64(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_pi8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_add_pi8, &simde_emul_mm_add_pi8);
}

static MunitResult
test_simde_mm_add_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_add_pi16, &simde_emul_mm_add_pi16);
}

static MunitResult
test_simde_mm_add_pi32(const MunitParameter params[], void* data) {
  return cmp_i32_m64_2xm64(params, data, &simde_mm_add_pi32, &simde_emul_mm_add_pi32);
}

static MunitResult
test_simde_mm_adds_pi8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_adds_pi8, &simde_emul_mm_adds_pi8);
}

static MunitResult
test_simde_mm_adds_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_adds_pi16, &simde_emul_mm_adds_pi16);
}

static MunitResult
test_simde_mm_adds_pu8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_adds_pu8, &simde_emul_mm_adds_pu8);
}

static MunitResult
test_simde_mm_adds_pu16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_adds_pu16, &simde_emul_mm_adds_pu16);
}

static MunitResult
test_simde_mm_and_si64(const MunitParameter params[], void* data) {
  return cmp_i64_m64_2xm64(params, data, &simde_mm_and_si64, &simde_emul_mm_and_si64);
}

static MunitResult
test_simde_mm_andnot_si64(const MunitParameter params[], void* data) {
  return cmp_i64_m64_2xm64(params, data, &simde_mm_andnot_si64, &simde_emul_mm_andnot_si64);
}

static MunitResult
test_simde_mm_cmpeq_pi8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_cmpeq_pi8, &simde_emul_mm_cmpeq_pi8);
}

static MunitResult
test_simde_mm_cmpeq_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_cmpeq_pi16, &simde_emul_mm_cmpeq_pi16);
}

static MunitResult
test_simde_mm_cmpeq_pi32(const MunitParameter params[], void* data) {
  return cmp_i32_m64_2xm64(params, data, &simde_mm_cmpeq_pi32, &simde_emul_mm_cmpeq_pi32);
}

static MunitResult
test_simde_mm_cmpgt_pi8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_cmpgt_pi8, &simde_emul_mm_cmpgt_pi8);
}

static MunitResult
test_simde_mm_cmpgt_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_cmpgt_pi16, &simde_emul_mm_cmpgt_pi16);
}

static MunitResult
test_simde_mm_cmpgt_pi32(const MunitParameter params[], void* data) {
  return cmp_i32_m64_2xm64(params, data, &simde_mm_cmpgt_pi32, &simde_emul_mm_cmpgt_pi32);
}

static MunitResult
test_simde_mm_madd_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_madd_pi16, &simde_emul_mm_madd_pi16);
}

static MunitResult
test_simde_mm_mulhi_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_mulhi_pi16, &simde_emul_mm_mulhi_pi16);
}

static MunitResult
test_simde_mm_mullo_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_mullo_pi16, &simde_emul_mm_mullo_pi16);
}

static MunitResult
test_simde_mm_or_si64(const MunitParameter params[], void* data) {
  return cmp_i64_m64_2xm64(params, data, &simde_mm_or_si64, &simde_emul_mm_or_si64);
}

static MunitResult
test_simde_mm_packs_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_packs_pi16, &simde_emul_mm_packs_pi16);
}

static MunitResult
test_simde_mm_packs_pi32(const MunitParameter params[], void* data) {
  return cmp_i32_m64_2xm64(params, data, &simde_mm_packs_pi32, &simde_emul_mm_packs_pi32);
}

static MunitResult
test_simde_mm_packs_pu16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_packs_pu16, &simde_emul_mm_packs_pu16);
}

static MunitResult
test_simde_mm_sll_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m64 na, ncount, nr;
  simde_emul__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ncount.i64[0] = munit_rand_int_range(0, 16);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = simde_mm_sll_pi16(na, ncount);
  er = simde_emul_mm_sll_pi16(ea, ecount);

  simde_assert_m64_i16(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m64 na, ncount, nr;
  simde_emul__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ncount.i64[0] = munit_rand_int_range(0, 32);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = simde_mm_sll_pi32(na, ncount);
  er = simde_emul_mm_sll_pi32(ea, ecount);

  simde_assert_m64_i32(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m64 na, ncount, nr;
  simde_emul__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ncount.i64[0] = munit_rand_int_range(0, 64);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = simde_mm_sll_si64(na, ncount);
  er = simde_emul_mm_sll_si64(ea, ecount);

  simde_assert_m64_i64(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m64 na, ncount, nr;
  simde_emul__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ncount.i64[0] = munit_rand_int_range(0, 16);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = simde_mm_srl_pi16(na, ncount);
  er = simde_emul_mm_srl_pi16(ea, ecount);

  simde_assert_m64_i16(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m64 na, ncount, nr;
  simde_emul__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ncount.i64[0] = munit_rand_int_range(0, 32);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = simde_mm_srl_pi32(na, ncount);
  er = simde_emul_mm_srl_pi32(ea, ecount);

  simde_assert_m64_i32(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m64 na, ncount, nr;
  simde_emul__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ncount.i64[0] = munit_rand_int_range(0, 64);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = simde_mm_srl_si64(na, ncount);
  er = simde_emul_mm_srl_si64(ea, ecount);

  simde_assert_m64_i64(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sra_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m64 na, ncount, nr;
  simde_emul__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ncount.i64[0] = munit_rand_int_range(0, 16);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = simde_mm_sra_pi16(na, ncount);
  er = simde_emul_mm_sra_pi16(ea, ecount);

  simde_assert_m64_i16(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sra_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m64 na, ncount, nr;
  simde_emul__m64 ea, ecount, er;

  munit_rand_memory(sizeof(na), (uint8_t*) &na);
  ncount.i64[0] = munit_rand_int_range(0, 32);
  memcpy(&ea, &na, sizeof(na));
  memcpy(&ecount, &ncount, sizeof(ncount));

  nr = simde_mm_sra_pi32(na, ncount);
  er = simde_emul_mm_sra_pi32(ea, ecount);

  debug_array_u32("\nna", sizeof(na.u32) / sizeof(na.u32[0]), (uint32_t*) &na);
  fprintf(stderr, "nc: %ld\n", ncount.i64[0]);
  debug_array_u32("nr", sizeof(nr.u32) / sizeof(nr.u32[0]), (uint32_t*) &nr);
  debug_array_u32("er", sizeof(er.u32) / sizeof(er.u32[0]), (uint32_t*) &er);

  simde_assert_m64_i32(nr, ==, er);

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_pi8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_sub_pi8, &simde_emul_mm_sub_pi8);
}

static MunitResult
test_simde_mm_sub_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_sub_pi16, &simde_emul_mm_sub_pi16);
}

static MunitResult
test_simde_mm_sub_pi32(const MunitParameter params[], void* data) {
  return cmp_i32_m64_2xm64(params, data, &simde_mm_sub_pi32, &simde_emul_mm_sub_pi32);
}

static MunitResult
test_simde_mm_subs_pi8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_subs_pi8, &simde_emul_mm_subs_pi8);
}

static MunitResult
test_simde_mm_subs_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_subs_pi16, &simde_emul_mm_subs_pi16);
}

static MunitResult
test_simde_mm_subs_pu8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_subs_pu8, &simde_emul_mm_subs_pu8);
}

static MunitResult
test_simde_mm_subs_pu16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_subs_pu16, &simde_emul_mm_subs_pu16);
}

static MunitResult
test_simde_mm_unpackhi_pi8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_unpackhi_pi8, &simde_emul_mm_unpackhi_pi8);
}

static MunitResult
test_simde_mm_unpackhi_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_unpackhi_pi16, &simde_emul_mm_unpackhi_pi16);
}

static MunitResult
test_simde_mm_unpackhi_pi32(const MunitParameter params[], void* data) {
  return cmp_i32_m64_2xm64(params, data, &simde_mm_unpackhi_pi32, &simde_emul_mm_unpackhi_pi32);
}

static MunitResult
test_simde_mm_unpacklo_pi8(const MunitParameter params[], void* data) {
  return cmp_i8_m64_2xm64(params, data, &simde_mm_unpacklo_pi8, &simde_emul_mm_unpacklo_pi8);
}

static MunitResult
test_simde_mm_unpacklo_pi16(const MunitParameter params[], void* data) {
  return cmp_i16_m64_2xm64(params, data, &simde_mm_unpacklo_pi16, &simde_emul_mm_unpacklo_pi16);
}

static MunitResult
test_simde_mm_unpacklo_pi32(const MunitParameter params[], void* data) {
  return cmp_i32_m64_2xm64(params, data, &simde_mm_unpacklo_pi32, &simde_emul_mm_unpacklo_pi32);
}

static MunitResult
test_simde_mm_xor_si64(const MunitParameter params[], void* data) {
  return cmp_i64_m64_2xm64(params, data, &simde_mm_xor_si64, &simde_emul_mm_xor_si64);
}

static MunitTest test_suite_tests[] = {
  { (char*) "/mm_add_pi8",       test_simde_mm_add_pi8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_pi16",      test_simde_mm_add_pi16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_pi32",      test_simde_mm_add_pi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_pi8",      test_simde_mm_adds_pi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_pi16",     test_simde_mm_adds_pi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_pu8",      test_simde_mm_adds_pu8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_pu16",     test_simde_mm_adds_pu16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_and_si64",      test_simde_mm_and_si64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_andnot_si64",   test_simde_mm_andnot_si64,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_pi8",     test_simde_mm_cmpeq_pi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_pi16",    test_simde_mm_cmpeq_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_pi32",    test_simde_mm_cmpeq_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_pi8",     test_simde_mm_cmpgt_pi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_pi16",    test_simde_mm_cmpgt_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_pi32",    test_simde_mm_cmpgt_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_madd_pi16",     test_simde_mm_madd_pi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_mulhi_pi16",    test_simde_mm_mulhi_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_mullo_pi16",    test_simde_mm_mullo_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_or_si64",       test_simde_mm_or_si64,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_packs_pi16",    test_simde_mm_packs_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_packs_pi32",    test_simde_mm_packs_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_packs_pu16",    test_simde_mm_packs_pu16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sll_pi16",      test_simde_mm_sll_pi16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sll_pi32",      test_simde_mm_sll_pi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sll_si64",      test_simde_mm_sll_si64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srl_pi16",      test_simde_mm_srl_pi16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srl_pi32",      test_simde_mm_srl_pi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srl_si64",      test_simde_mm_srl_si64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sra_pi16",      test_simde_mm_sra_pi16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sra_pi32",      test_simde_mm_sra_pi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_pi8",       test_simde_mm_sub_pi8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_pi16",      test_simde_mm_sub_pi16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_pi32",      test_simde_mm_sub_pi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_pi8",      test_simde_mm_subs_pi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_pi16",     test_simde_mm_subs_pi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_pu8",      test_simde_mm_subs_pu8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_pu16",     test_simde_mm_subs_pu16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_unpackhi_pi8",  test_simde_mm_unpackhi_pi8,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_unpackhi_pi16", test_simde_mm_unpackhi_pi16, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_unpackhi_pi32", test_simde_mm_unpackhi_pi32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_unpacklo_pi8",  test_simde_mm_unpacklo_pi8,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_unpacklo_pi16", test_simde_mm_unpacklo_pi16, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_unpacklo_pi32", test_simde_mm_unpacklo_pi32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_xor_si64",      test_simde_mm_xor_si64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#else
static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
#endif

const MunitSuite simde_mmx_test_suite = {
  (char*) "/mmx",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
