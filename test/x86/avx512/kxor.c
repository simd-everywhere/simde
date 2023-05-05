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

#define SIMDE_TEST_X86_AVX512_INSN kxor

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/kxor.h>

static int
test_simde_kxor_mask8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 a;
    const simde__mmask8 b;
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(180),
      UINT8_C(253),
      UINT8_C( 73) },
    { UINT8_C( 16),
      UINT8_C( 50),
      UINT8_C( 34) },
    { UINT8_C(181),
      UINT8_C(122),
      UINT8_C(207) },
    { UINT8_C( 81),
      UINT8_C( 92),
      UINT8_C( 13) },
    { UINT8_C( 21),
      UINT8_C(159),
      UINT8_C(138) },
    { UINT8_C(254),
      UINT8_C(236),
      UINT8_C( 18) },
    { UINT8_C(101),
      UINT8_C(123),
      UINT8_C( 30) },
    { UINT8_C(122),
      UINT8_C(180),
      UINT8_C(206) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 r = simde_kxor_mask8(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 a = simde_test_x86_random_mmask8();
    simde__mmask8 b = simde_test_x86_random_mmask8();
    simde__mmask8 r = simde_kxor_mask8(a, b);

    simde_test_x86_write_mmask8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_kxor_mask16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 a;
    const simde__mmask16 b;
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 5117),
      UINT16_C(43689),
      UINT16_C(47444) },
    { UINT16_C(32526),
      UINT16_C(40254),
      UINT16_C(57904) },
    { UINT16_C( 9192),
      UINT16_C(52494),
      UINT16_C(61158) },
    { UINT16_C(22597),
      UINT16_C(18227),
      UINT16_C( 8054) },
    { UINT16_C(29104),
      UINT16_C(25853),
      UINT16_C( 5453) },
    { UINT16_C(23320),
      UINT16_C(54041),
      UINT16_C(34817) },
    { UINT16_C(22991),
      UINT16_C(47721),
      UINT16_C(58278) },
    { UINT16_C(11519),
      UINT16_C(64553),
      UINT16_C(53462) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 r = simde_kxor_mask16(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 a = simde_test_x86_random_mmask16();
    simde__mmask16 b = simde_test_x86_random_mmask16();
    simde__mmask16 r = simde_kxor_mask16(a, b);

    simde_test_x86_write_mmask16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_kxor (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 a;
    const simde__mmask16 b;
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(22659),
      UINT16_C(15183),
      UINT16_C(25548) },
    { UINT16_C(64429),
      UINT16_C(37846),
      UINT16_C(26747) },
    { UINT16_C(26767),
      UINT16_C(29157),
      UINT16_C( 6506) },
    { UINT16_C( 8933),
      UINT16_C(26186),
      UINT16_C(17583) },
    { UINT16_C(22529),
      UINT16_C(46653),
      UINT16_C(60988) },
    { UINT16_C(42932),
      UINT16_C(46173),
      UINT16_C( 5097) },
    { UINT16_C(29882),
      UINT16_C(38464),
      UINT16_C(58106) },
    { UINT16_C(42475),
      UINT16_C(28355),
      UINT16_C(52008) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 r = simde_mm512_kxor(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 a = simde_test_x86_random_mmask16();
    simde__mmask16 b = simde_test_x86_random_mmask16();
    simde__mmask16 r = simde_mm512_kxor(a, b);

    simde_test_x86_write_mmask16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_kxor_mask32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 a;
    const simde__mmask32 b;
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(1319621183),
      UINT32_C( 988538194),
      UINT32_C(1951151981) },
    { UINT32_C(1292368392),
      UINT32_C(  60045906),
      UINT32_C(1318305882) },
    { UINT32_C(3295122091),
      UINT32_C(3164045549),
      UINT32_C(2028999238) },
    { UINT32_C(3648454874),
      UINT32_C(1825939500),
      UINT32_C(3047334134) },
    { UINT32_C(3300555890),
      UINT32_C(1778296161),
      UINT32_C(2906970387) },
    { UINT32_C(4072080799),
      UINT32_C(3958721344),
      UINT32_C( 423775967) },
    { UINT32_C(3400490205),
      UINT32_C(3079096029),
      UINT32_C(2099780096) },
    { UINT32_C(1938882118),
      UINT32_C( 283075998),
      UINT32_C(1666161624) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 r = simde_kxor_mask32(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 a = simde_test_x86_random_mmask32();
    simde__mmask32 b = simde_test_x86_random_mmask32();
    simde__mmask32 r = simde_kxor_mask32(a, b);

    simde_test_x86_write_mmask32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_kxor_mask64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 a;
    const simde__mmask64 b;
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C(16045713311770450402),
      UINT64_C(10161464015097717977),
      UINT64_C( 6028374389748530491) },
    { UINT64_C( 4734935752840295457),
      UINT64_C(10199408145817945564),
      UINT64_C(14717285644810580477) },
    { UINT64_C(  885094986567147564),
      UINT64_C(18383177860084209889),
      UINT64_C(17534298883154606285) },
    { UINT64_C( 3465998565237421534),
      UINT64_C(10101633752882728440),
      UINT64_C(13558514613629663270) },
    { UINT64_C( 6977834486443999638),
      UINT64_C(  230826133395995480),
      UINT64_C( 7197368326119946958) },
    { UINT64_C(15927531924707095172),
      UINT64_C( 9273107251932017859),
      UINT64_C( 6753503951651178055) },
    { UINT64_C( 4508419775504426930),
      UINT64_C( 1532535115017912859),
      UINT64_C( 3158632437299094953) },
    { UINT64_C(15608903556322435290),
      UINT64_C( 9373588207016091307),
      UINT64_C( 6523565052813000305) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 r = simde_kxor_mask64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 a = simde_test_x86_random_mmask64();
    simde__mmask64 b = simde_test_x86_random_mmask64();
    simde__mmask64 r = simde_kxor_mask64(a, b);

    simde_test_x86_write_mmask64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(kxor_mask8)
  SIMDE_TEST_FUNC_LIST_ENTRY(kxor_mask16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_kxor)
  SIMDE_TEST_FUNC_LIST_ENTRY(kxor_mask32)
  SIMDE_TEST_FUNC_LIST_ENTRY(kxor_mask64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
