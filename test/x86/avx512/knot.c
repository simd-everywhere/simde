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

#define SIMDE_TEST_X86_AVX512_INSN knot

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/knot.h>

static int
test_simde_knot_mask8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 a;
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(244),
      UINT8_C( 11) },
    { UINT8_C(142),
      UINT8_C(113) },
    { UINT8_C( 46),
      UINT8_C(209) },
    { UINT8_C( 74),
      UINT8_C(181) },
    { UINT8_C(116),
      UINT8_C(139) },
    { UINT8_C(192),
      UINT8_C( 63) },
    { UINT8_C( 51),
      UINT8_C(204) },
    { UINT8_C(206),
      UINT8_C( 49) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 r = simde_knot_mask8(test_vec[i].a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 a = simde_test_x86_random_mmask8();
    simde__mmask8 r = simde_knot_mask8(a);

    simde_test_x86_write_mmask8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_knot_mask16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 a;
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(50766),
      UINT16_C(14769) },
    { UINT16_C( 2645),
      UINT16_C(62890) },
    { UINT16_C( 2583),
      UINT16_C(62952) },
    { UINT16_C(60343),
      UINT16_C( 5192) },
    { UINT16_C(21746),
      UINT16_C(43789) },
    { UINT16_C(61769),
      UINT16_C( 3766) },
    { UINT16_C(37441),
      UINT16_C(28094) },
    { UINT16_C(18375),
      UINT16_C(47160) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 r = simde_knot_mask16(test_vec[i].a);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 a = simde_test_x86_random_mmask16();
    simde__mmask16 r = simde_knot_mask16(a);

    simde_test_x86_write_mmask16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_knot (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 a;
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(54112),
      UINT16_C(11423) },
    { UINT16_C(42070),
      UINT16_C(23465) },
    { UINT16_C(14863),
      UINT16_C(50672) },
    { UINT16_C(  968),
      UINT16_C(64567) },
    { UINT16_C(63176),
      UINT16_C( 2359) },
    { UINT16_C(15437),
      UINT16_C(50098) },
    { UINT16_C(32950),
      UINT16_C(32585) },
    { UINT16_C( 1034),
      UINT16_C(64501) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 r = simde_mm512_knot(test_vec[i].a);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 a = simde_test_x86_random_mmask16();
    simde__mmask16 r = simde_mm512_knot(a);

    simde_test_x86_write_mmask16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_knot_mask32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 a;
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(1561222982),
      UINT32_C(2733744313) },
    { UINT32_C(1548338794),
      UINT32_C(2746628501) },
    { UINT32_C(1531810330),
      UINT32_C(2763156965) },
    { UINT32_C(2242057253),
      UINT32_C(2052910042) },
    { UINT32_C(4130011623),
      UINT32_C( 164955672) },
    { UINT32_C(4227461683),
      UINT32_C(  67505612) },
    { UINT32_C(2671265512),
      UINT32_C(1623701783) },
    { UINT32_C( 228803271),
      UINT32_C(4066164024) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 r = simde_knot_mask32(test_vec[i].a);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 a = simde_test_x86_random_mmask32();
    simde__mmask32 r = simde_knot_mask32(a);

    simde_test_x86_write_mmask32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_knot_mask64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 a;
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C(10549880554812846754),
      UINT64_C( 7896863518896704861) },
    { UINT64_C(12822189912680740166),
      UINT64_C( 5624554161028811449) },
    { UINT64_C(17706360490389150602),
      UINT64_C(  740383583320401013) },
    { UINT64_C(15473304218673410536),
      UINT64_C( 2973439855036141079) },
    { UINT64_C( 2518720397724231658),
      UINT64_C(15928023675985319957) },
    { UINT64_C(18337389343536964351),
      UINT64_C(  109354730172587264) },
    { UINT64_C(12437945758361854873),
      UINT64_C( 6008798315347696742) },
    { UINT64_C( 5940556221040504935),
      UINT64_C(12506187852669046680) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 r = simde_knot_mask64(test_vec[i].a);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 a = simde_test_x86_random_mmask64();
    simde__mmask64 r = simde_knot_mask64(a);

    simde_test_x86_write_mmask64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(knot_mask8)
  SIMDE_TEST_FUNC_LIST_ENTRY(knot_mask16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_knot)
  SIMDE_TEST_FUNC_LIST_ENTRY(knot_mask32)
  SIMDE_TEST_FUNC_LIST_ENTRY(knot_mask64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
