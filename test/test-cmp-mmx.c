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

static MunitResult
cmp_m64_2xm64(const MunitParameter params[], void* data,
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
test_simde_mm_add_pi8(const MunitParameter params[], void* data) {
  return cmp_m64_2xm64(params, data, &simde_mm_add_pi8, &simde_emul_mm_add_pi8);
}

static MunitTest test_suite_tests[] = {
  { (char*) "/mm_add_pi8",       test_simde_mm_add_pi8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

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
