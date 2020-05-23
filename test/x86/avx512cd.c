/* Copyright (c) 2018, 2019 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX avx512cd
#include <simde/x86/avx512cd.h>
#include <test/x86/test-avx512.h>

static int
test_simde_mm_lzcnt_epi32(void) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(           INT32_MAX,            INT32_MIN,          ~INT32_C(0), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          1), INT32_C(          0), INT32_C(          0), INT32_C(         32)) },
    { simde_mm_set_epi32(INT32_C(        179), INT32_C(     -17551), INT32_C(   -2202065), INT32_C(    -743837)),
      simde_mm_set_epi32(INT32_C(         24), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(      -2559), INT32_C(  388806146), INT32_C(    1927808), INT32_C(       -112)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          3), INT32_C(         11), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(         22), INT32_C(    -189678), INT32_C(        252), INT32_C(      27703)),
      simde_mm_set_epi32(INT32_C(         27), INT32_C(          0), INT32_C(         24), INT32_C(         17)) },
    { simde_mm_set_epi32(INT32_C(   -9106380), INT32_C(    8952567), INT32_C(         -4), INT32_C(     685169)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          8), INT32_C(          0), INT32_C(         12)) },
    { simde_mm_set_epi32(INT32_C(     267298), INT32_C(      -3422), INT32_C(          4), INT32_C(      31229)),
      simde_mm_set_epi32(INT32_C(         13), INT32_C(          0), INT32_C(         29), INT32_C(         17)) },
    { simde_mm_set_epi32(INT32_C(     167383), INT32_C(        214), INT32_C(          0), INT32_C(     -20257)),
      simde_mm_set_epi32(INT32_C(         14), INT32_C(         24), INT32_C(         32), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(       -147), INT32_C(   -1774263), INT32_C(     143922), INT32_C(    -914728)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         14), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_lzcnt_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_lzcnt_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
