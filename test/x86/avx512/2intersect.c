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

#define SIMDE_TEST_X86_AVX512_INSN 2intersect

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/2intersect.h>

static int
test_simde_mm_2intersect_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 k1;
    const simde__mmask8 k2;
  } test_vec[] = {
    { {  INT32_C(  1933024678),  INT32_C(  1654182574),  INT32_C(  2112578681),  INT32_C(  1940886531) },
      { -INT32_C(  1741466723),  INT32_C(  1850577758),  INT32_C(  1878396937),  INT32_C(  1834180551) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { { -INT32_C(  1411347460), -INT32_C(   686982819), -INT32_C(   531302179),  INT32_C(   693306508) },
      { -INT32_C(  1245608361),  INT32_C(   589499930), -INT32_C(   426632674),  INT32_C(  1968432505) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { { -INT32_C(   836750224), -INT32_C(  1968886355), -INT32_C(  1318389467),  INT32_C(  1440398845) },
      {  INT32_C(  1560976195), -INT32_C(   931123542), -INT32_C(  1045556664),  INT32_C(  1748370168) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { { -INT32_C(   482977994), -INT32_C(  1435640956), -INT32_C(   765732907), -INT32_C(   685295980) },
      {  INT32_C(  2067083985), -INT32_C(  1471892128), -INT32_C(  1066798392),  INT32_C(   707305460) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { {  INT32_C(  2064474102),  INT32_C(   254114362), -INT32_C(   438140847), -INT32_C(  2000877130) },
      { -INT32_C(  1694240197),  INT32_C(  1866680231),  INT32_C(   774876218),  INT32_C(  1113151564) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { { -INT32_C(   239245641),  INT32_C(   838984417),  INT32_C(   421061475),  INT32_C(   681694700) },
      {  INT32_C(  1858315719),  INT32_C(   652085228), -INT32_C(    11203149),  INT32_C(   474132069) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { { -INT32_C(   183566572),  INT32_C(  1160253410), -INT32_C(   564248334), -INT32_C(   603586539) },
      { -INT32_C(  1857369435), -INT32_C(  2068305711), -INT32_C(  1685844682), -INT32_C(   809974085) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { { -INT32_C(  1480210747), -INT32_C(   940773931),  INT32_C(  1118128941), -INT32_C(   266425269) },
      {  INT32_C(  1199663222), -INT32_C(   942982767),  INT32_C(    23220038), -INT32_C(   607053291) },
      UINT8_C(  0),
      UINT8_C(  0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 k1, k2;
    simde_mm_2intersect_epi32(a, b, &k1, &k2);

    simde_assert_equal_u8(k1, test_vec[i].k1);
    simde_assert_equal_u8(k2, test_vec[i].k2);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__mmask8 k1, k2;

    simde_mm_2intersect_epi32(a, b, &k1, &k2);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, k2, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_2intersect_epi32)
  // SIMDE_TEST_FUNC_LIST_ENTRY(mm_2intersect_epi64)

  // SIMDE_TEST_FUNC_LIST_ENTRY(mm256_2intersect_epi32)
  // SIMDE_TEST_FUNC_LIST_ENTRY(mm256_2intersect_epi64)

  // SIMDE_TEST_FUNC_LIST_ENTRY(mm512_2intersect_epi32)
  // SIMDE_TEST_FUNC_LIST_ENTRY(mm512_2intersect_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
