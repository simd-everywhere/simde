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

#define SIMDE_TEST_X86_AVX512_INSN kshift

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/kshift.h>

#define GENERATE_VECTORS 0

#if GENERATE_VECTORS
  #define PROBABILITY 80
  #define probability(p) (rand() < ((HEDLEY_STATIC_CAST(int64_t, RAND_MAX) * (p)) / 100))
#endif

static int
test_simde_kshiftli_mask16 (SIMDE_MUNIT_TEST_ARGS) {
#if GENERATE_VECTORS
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 r;
    simde__mmask16 a = simde_test_x86_random_mmask16();
    unsigned int count = HEDLEY_STATIC_CAST(unsigned int, munit_rand_int_range(0, 255));
    if (probability(PROBABILITY)) count &= 15;

    SIMDE_CONSTIFY_16_(simde_kshiftli_mask16, r, 0, count, a);

    simde_test_x86_write_mmask16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, count, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#else
  static const struct {
    const simde__mmask16 a;
    const unsigned int count;
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(32998),
      UINT32_C(        98),
      UINT16_C(    0) },
    { UINT16_C(11635),
      UINT32_C(       226),
      UINT16_C(    0) },
    { UINT16_C(31681),
      UINT32_C(        10),
      UINT16_C( 1024) },
    { UINT16_C(20229),
      UINT32_C(        10),
      UINT16_C( 5120) },
    { UINT16_C( 3580),
      UINT32_C(        12),
      UINT16_C(49152) },
    { UINT16_C(47873),
      UINT32_C(         0),
      UINT16_C(47873) },
    { UINT16_C(50829),
      UINT32_C(         8),
      UINT16_C(36096) },
    { UINT16_C(36232),
      UINT32_C(        11),
      UINT16_C(16384) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 r;
    SIMDE_CONSTIFY_16_(simde_kshiftli_mask16, r, 0, test_vec[i].count, test_vec[i].a);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#endif
}

static int
test_simde_kshiftli_mask32 (SIMDE_MUNIT_TEST_ARGS) {
#if GENERATE_VECTORS
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 r;
    simde__mmask32 a = simde_test_x86_random_mmask32();
    unsigned int count = HEDLEY_STATIC_CAST(unsigned int, munit_rand_int_range(0, 255));
    if (probability(PROBABILITY)) count &= 31;

    SIMDE_CONSTIFY_32_(simde_kshiftli_mask32, r, 0, count, a);

    simde_test_x86_write_mmask32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, count, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#else
  static const struct {
    const simde__mmask32 a;
    const unsigned int count;
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(3866362599),
      UINT32_C(       178),
      UINT32_C(         0) },
    { UINT32_C(1420251803),
      UINT32_C(        18),
      UINT32_C(1248591872) },
    { UINT32_C(2944902744),
      UINT32_C(        25),
      UINT32_C(2952790016) },
    { UINT32_C( 515275237),
      UINT32_C(        12),
      UINT32_C(1738428416) },
    { UINT32_C(3507266298),
      UINT32_C(        29),
      UINT32_C(1073741824) },
    { UINT32_C(2178785751),
      UINT32_C(         7),
      UINT32_C(4006669184) },
    { UINT32_C(3901712499),
      UINT32_C(       213),
      UINT32_C(         0) },
    { UINT32_C( 866157452),
      UINT32_C(        18),
      UINT32_C( 238026752) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 r;
    SIMDE_CONSTIFY_32_(simde_kshiftli_mask32, r, 0, test_vec[i].count, test_vec[i].a);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#endif
}

static int
test_simde_kshiftli_mask64 (SIMDE_MUNIT_TEST_ARGS) {
#if GENERATE_VECTORS
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 r;
    simde__mmask64 a = simde_test_x86_random_mmask64();
    unsigned int count = HEDLEY_STATIC_CAST(unsigned int, munit_rand_int_range(0, 255));
    if (probability(PROBABILITY)) count &= 63;

    SIMDE_CONSTIFY_64_(simde_kshiftli_mask64, r, 0, count, a);

    simde_test_x86_write_mmask64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, count, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#else
  static const struct {
    const simde__mmask64 a;
    const unsigned int count;
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C( 1295334839708707992),
      UINT32_C(        50),
      UINT64_C(12853273336515395584) },
    { UINT64_C( 7249544805129316044),
      UINT32_C(        50),
      UINT64_C(11182437874760941568) },
    { UINT64_C(17573762057435916769),
      UINT32_C(       121),
      UINT64_C(                   0) },
    { UINT64_C( 9388101999642308565),
      UINT32_C(        44),
      UINT64_C(  503646694265585664) },
    { UINT64_C( 8448015434585439037),
      UINT32_C(        29),
      UINT64_C(16676670436032905216) },
    { UINT64_C( 3549407090849943755),
      UINT32_C(        39),
      UINT64_C(12576413559862329344) },
    { UINT64_C( 3228769676502045645),
      UINT32_C(        21),
      UINT64_C(11330967200335921152) },
    { UINT64_C(17289294451460437515),
      UINT32_C(        50),
      UINT64_C(15576825211167703040) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 r;
    SIMDE_CONSTIFY_64_(simde_kshiftli_mask64, r, 0, test_vec[i].count, test_vec[i].a);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#endif
}

static int
test_simde_kshiftli_mask8 (SIMDE_MUNIT_TEST_ARGS) {
#if GENERATE_VECTORS
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 r;
    simde__mmask8 a = simde_test_x86_random_mmask8();
    unsigned int count = HEDLEY_STATIC_CAST(unsigned int, munit_rand_int_range(0, 255));
    if (probability(PROBABILITY)) count &= 7;

    SIMDE_CONSTIFY_8_(simde_kshiftli_mask8, r, 0, count, a);

    simde_test_x86_write_mmask8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, count, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#else
  static const struct {
    const simde__mmask8 a;
    const unsigned int count;
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(193),
      UINT32_C(         2),
      UINT8_C(  4) },
    { UINT8_C(220),
      UINT32_C(         2),
      UINT8_C(112) },
    { UINT8_C(209),
      UINT32_C(         1),
      UINT8_C(162) },
    { UINT8_C( 18),
      UINT32_C(       108),
      UINT8_C(  0) },
    { UINT8_C( 96),
      UINT32_C(         5),
      UINT8_C(  0) },
    { UINT8_C(119),
      UINT32_C(        39),
      UINT8_C(  0) },
    { UINT8_C(156),
      UINT32_C(         5),
      UINT8_C(128) },
    { UINT8_C(250),
      UINT32_C(         2),
      UINT8_C(232) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 r;
    SIMDE_CONSTIFY_8_(simde_kshiftli_mask8, r, 0, test_vec[i].count, test_vec[i].a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#endif
}

static int
test_simde_kshiftri_mask16 (SIMDE_MUNIT_TEST_ARGS) {
#if GENERATE_VECTORS
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 r;
    simde__mmask16 a = simde_test_x86_random_mmask16();
    unsigned int count = HEDLEY_STATIC_CAST(unsigned int, munit_rand_int_range(0, 255));
    if (probability(PROBABILITY)) count &= 15;

    SIMDE_CONSTIFY_16_(simde_kshiftri_mask16, r, 0, count, a);

    simde_test_x86_write_mmask16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, count, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#else
  static const struct {
    const simde__mmask16 a;
    const unsigned int count;
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(48214),
      UINT32_C(         8),
      UINT16_C(  188) },
    { UINT16_C(62048),
      UINT32_C(         1),
      UINT16_C(31024) },
    { UINT16_C(60270),
      UINT32_C(        14),
      UINT16_C(    3) },
    { UINT16_C(61859),
      UINT32_C(       187),
      UINT16_C(    0) },
    { UINT16_C(48213),
      UINT32_C(        12),
      UINT16_C(   11) },
    { UINT16_C(27255),
      UINT32_C(         2),
      UINT16_C( 6813) },
    { UINT16_C(40508),
      UINT32_C(         8),
      UINT16_C(  158) },
    { UINT16_C(56544),
      UINT32_C(         9),
      UINT16_C(  110) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 r;
    SIMDE_CONSTIFY_16_(simde_kshiftri_mask16, r, 0, test_vec[i].count, test_vec[i].a);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#endif
}

static int
test_simde_kshiftri_mask32 (SIMDE_MUNIT_TEST_ARGS) {
#if GENERATE_VECTORS
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 r;
    simde__mmask32 a = simde_test_x86_random_mmask32();
    unsigned int count = HEDLEY_STATIC_CAST(unsigned int, munit_rand_int_range(0, 255));
    if (probability(PROBABILITY)) count &= 31;

    SIMDE_CONSTIFY_32_(simde_kshiftri_mask32, r, 0, count, a);

    simde_test_x86_write_mmask32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, count, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#else
  static const struct {
    const simde__mmask32 a;
    const unsigned int count;
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(2251082273),
      UINT32_C(         8),
      UINT32_C(   8793290) },
    { UINT32_C(4066024717),
      UINT32_C(       129),
      UINT32_C(         0) },
    { UINT32_C(1983822470),
      UINT32_C(        30),
      UINT32_C(         1) },
    { UINT32_C( 149028471),
      UINT32_C(        27),
      UINT32_C(         1) },
    { UINT32_C( 429851039),
      UINT32_C(        28),
      UINT32_C(         1) },
    { UINT32_C(2881428320),
      UINT32_C(        18),
      UINT32_C(     10991) },
    { UINT32_C( 827796637),
      UINT32_C(         1),
      UINT32_C( 413898318) },
    { UINT32_C( 418383038),
      UINT32_C(         9),
      UINT32_C(    817154) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 r;
    SIMDE_CONSTIFY_32_(simde_kshiftri_mask32, r, 0, test_vec[i].count, test_vec[i].a);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#endif
}

static int
test_simde_kshiftri_mask64 (SIMDE_MUNIT_TEST_ARGS) {
#if GENERATE_VECTORS
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 r;
    simde__mmask64 a = simde_test_x86_random_mmask64();
    unsigned int count = HEDLEY_STATIC_CAST(unsigned int, munit_rand_int_range(0, 255));
    if (probability(PROBABILITY)) count &= 63;

    SIMDE_CONSTIFY_64_(simde_kshiftri_mask64, r, 0, count, a);

    simde_test_x86_write_mmask64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, count, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#else
  static const struct {
    const simde__mmask64 a;
    const unsigned int count;
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C(12929489738497449333),
      UINT32_C(         8),
      UINT64_C(   50505819291005661) },
    { UINT64_C( 1761782705914904934),
      UINT32_C(         1),
      UINT64_C(  880891352957452467) },
    { UINT64_C(13413149345940726503),
      UINT32_C(        30),
      UINT64_C(         12491968782) },
    { UINT64_C( 7664406914680423996),
      UINT32_C(       187),
      UINT64_C(                   0) },
    { UINT64_C(11883749540069562403),
      UINT32_C(        28),
      UINT64_C(         44270416870) },
    { UINT64_C(11681796465351530248),
      UINT32_C(        18),
      UINT64_C(      44562517033964) },
    { UINT64_C( 3441339471496333362),
      UINT32_C(        56),
      UINT64_C(                  47) },
    { UINT64_C( 2277648988691598643),
      UINT32_C(        41),
      UINT64_C(             1035754) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 r;
    SIMDE_CONSTIFY_64_(simde_kshiftri_mask64, r, 0, test_vec[i].count, test_vec[i].a);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#endif
}

static int
test_simde_kshiftri_mask8 (SIMDE_MUNIT_TEST_ARGS) {
#if GENERATE_VECTORS
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 r;
    simde__mmask8 a = simde_test_x86_random_mmask8();
    unsigned int count = HEDLEY_STATIC_CAST(unsigned int, munit_rand_int_range(0, 255));
    if (probability(PROBABILITY)) count &= 7;

    SIMDE_CONSTIFY_8_(simde_kshiftri_mask8, r, 0, count, a);

    simde_test_x86_write_mmask8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, count, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#else
  static const struct {
    const simde__mmask8 a;
    const unsigned int count;
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 89),
      UINT32_C(       200),
      UINT8_C(  0) },
    { UINT8_C(165),
      UINT32_C(         1),
      UINT8_C( 82) },
    { UINT8_C(153),
      UINT32_C(         6),
      UINT8_C(  2) },
    { UINT8_C(170),
      UINT32_C(         3),
      UINT8_C( 21) },
    { UINT8_C( 93),
      UINT32_C(         4),
      UINT8_C(  5) },
    { UINT8_C(100),
      UINT32_C(         2),
      UINT8_C( 25) },
    { UINT8_C( 51),
      UINT32_C(         0),
      UINT8_C( 51) },
    { UINT8_C(163),
      UINT32_C(         1),
      UINT8_C( 81) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 r;
    SIMDE_CONSTIFY_8_(simde_kshiftri_mask8, r, 0, test_vec[i].count, test_vec[i].a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(kshiftli_mask16)
  SIMDE_TEST_FUNC_LIST_ENTRY(kshiftli_mask32)
  SIMDE_TEST_FUNC_LIST_ENTRY(kshiftli_mask64)
  SIMDE_TEST_FUNC_LIST_ENTRY(kshiftli_mask8)

  SIMDE_TEST_FUNC_LIST_ENTRY(kshiftri_mask16)
  SIMDE_TEST_FUNC_LIST_ENTRY(kshiftri_mask32)
  SIMDE_TEST_FUNC_LIST_ENTRY(kshiftri_mask64)
  SIMDE_TEST_FUNC_LIST_ENTRY(kshiftri_mask8)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
