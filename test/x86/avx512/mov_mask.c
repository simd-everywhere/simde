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

#define SIMDE_TEST_X86_AVX512_INSN mov_mask

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/mov_mask.h>

static int
test_simde_mm_movepi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT8_C(  83), -INT8_C(  56),  INT8_C(   2), -INT8_C( 120), -INT8_C(  72), -INT8_C( 102),  INT8_C(  37),  INT8_C(  73),
        -INT8_C(  17), -INT8_C(  44),  INT8_C(  52), -INT8_C( 102), -INT8_C( 118),  INT8_C( 122), -INT8_C( 126),  INT8_C( 106) },
      UINT16_C(23354) },
    { {  INT8_C(  41), -INT8_C(  40),  INT8_C(  58),  INT8_C(  91),  INT8_C(   1), -INT8_C(  24), -INT8_C(  78),  INT8_C(  57),
        -INT8_C(  57), -INT8_C(  64), -INT8_C(  68),  INT8_C(  88),  INT8_C(  44),  INT8_C( 115), -INT8_C(  97),      INT8_MAX },
      UINT16_C(18274) },
    { {  INT8_C(  59), -INT8_C(  94),  INT8_C(   7), -INT8_C(  12),  INT8_C(  60),  INT8_C(  44),  INT8_C(  61),  INT8_C(  43),
         INT8_C(   0),  INT8_C( 113), -INT8_C(  59), -INT8_C( 118), -INT8_C(  21),  INT8_C(  72), -INT8_C(  11),  INT8_C(  20) },
      UINT16_C(23562) },
    { {  INT8_C(  32),  INT8_C(  47),  INT8_C( 111),  INT8_C(  33),  INT8_C(  24),  INT8_C(  34),  INT8_C(  90), -INT8_C(  33),
        -INT8_C(  30),  INT8_C(  22),  INT8_C(  55),  INT8_C(  14), -INT8_C( 119), -INT8_C(  42), -INT8_C( 114), -INT8_C(  60) },
      UINT16_C(61824) },
    { {  INT8_C( 120), -INT8_C( 107), -INT8_C(  72), -INT8_C(  76), -INT8_C(  62), -INT8_C(  11), -INT8_C(  33), -INT8_C(  62),
         INT8_C( 103), -INT8_C(  91),  INT8_C(  77),  INT8_C(  82), -INT8_C(  19),  INT8_C(  66),  INT8_C( 103),  INT8_C(  13) },
      UINT16_C( 4862) },
    { {  INT8_C( 113), -INT8_C(  42),  INT8_C(  46), -INT8_C( 119), -INT8_C(   8), -INT8_C( 120),  INT8_C( 104), -INT8_C(  38),
        -INT8_C(  98), -INT8_C(  97), -INT8_C(  23),  INT8_C(  39),  INT8_C( 118),  INT8_C( 119), -INT8_C(  21), -INT8_C(  18) },
      UINT16_C(51130) },
    { {  INT8_C(  12), -INT8_C(  92), -INT8_C(  93), -INT8_C(  50), -INT8_C( 103), -INT8_C( 126), -INT8_C( 111),  INT8_C(   0),
         INT8_C(  39), -INT8_C(  34),  INT8_C(  83),  INT8_C(  20),  INT8_C(  32), -INT8_C(  70),  INT8_C(  33), -INT8_C( 111) },
      UINT16_C(41598) },
    { { -INT8_C( 112),  INT8_C(  79),  INT8_C(  27), -INT8_C( 119), -INT8_C(  41), -INT8_C( 125),  INT8_C(  99),  INT8_C( 117),
         INT8_C(  35),  INT8_C(  76), -INT8_C( 100), -INT8_C( 103), -INT8_C(  61), -INT8_C( 120), -INT8_C( 121), -INT8_C(  48) },
      UINT16_C(64569) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__mmask16 r = simde_mm_movepi8_mask(a);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__mmask16 r = simde_mm_movepi8_mask(a);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_movepi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT16_C(  5581), -INT16_C(  3782),  INT16_C( 30703),  INT16_C( 26376),  INT16_C( 15403),  INT16_C( 10089), -INT16_C( 29155), -INT16_C(  5741) },
      UINT8_C(195) },
    { {  INT16_C( 28768), -INT16_C( 25349), -INT16_C( 19427),  INT16_C( 32429),  INT16_C( 31304), -INT16_C( 15469), -INT16_C(   487),  INT16_C( 19546) },
      UINT8_C(102) },
    { { -INT16_C( 27416), -INT16_C( 10435),  INT16_C( 17932),  INT16_C( 14143), -INT16_C( 22398), -INT16_C( 24481), -INT16_C(  3530), -INT16_C( 26743) },
      UINT8_C(243) },
    { { -INT16_C( 31646), -INT16_C( 32717), -INT16_C(  8135), -INT16_C( 32258), -INT16_C( 28326),  INT16_C( 29765), -INT16_C( 24689),  INT16_C( 30656) },
      UINT8_C( 95) },
    { { -INT16_C(   460),  INT16_C( 16463), -INT16_C( 29116), -INT16_C( 14729), -INT16_C( 10698),  INT16_C( 27750), -INT16_C(  3896),  INT16_C( 11011) },
      UINT8_C( 93) },
    { {  INT16_C( 13940), -INT16_C( 21077), -INT16_C( 22250),  INT16_C( 28975),  INT16_C( 29754), -INT16_C( 13595), -INT16_C( 23277),  INT16_C( 18241) },
      UINT8_C(102) },
    { { -INT16_C( 28509), -INT16_C(  6265), -INT16_C(   226),  INT16_C( 21678),  INT16_C(  5333), -INT16_C( 24895), -INT16_C( 15356),  INT16_C( 31177) },
      UINT8_C(103) },
    { {  INT16_C( 29947),  INT16_C(  4390),  INT16_C( 21789),  INT16_C( 22402),  INT16_C( 26569), -INT16_C(  8927),  INT16_C( 25357), -INT16_C( 20444) },
      UINT8_C(160) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__mmask8 r = simde_mm_movepi16_mask(a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__mmask8 r = simde_mm_movepi16_mask(a);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_movepi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT32_C(   782608639), -INT32_C(   887178557), -INT32_C(  2094607728), -INT32_C(  1600281805) },
      UINT8_C( 15) },
    { {  INT32_C(  1082937331),  INT32_C(   699699582), -INT32_C(  1301359037), -INT32_C(   925751866) },
      UINT8_C( 12) },
    { {  INT32_C(  1083780221),  INT32_C(  1980479462), -INT32_C(  1124519543), -INT32_C(   950233132) },
      UINT8_C( 12) },
    { {  INT32_C(  1678305766), -INT32_C(  1098007430),  INT32_C(  1500576659), -INT32_C(  1641987551) },
      UINT8_C( 10) },
    { {  INT32_C(  1423882862), -INT32_C(    70588046), -INT32_C(   273103846),  INT32_C(  1102451803) },
      UINT8_C(  6) },
    { {  INT32_C(  2024193789),  INT32_C(   238433147),  INT32_C(  1348970031),  INT32_C(  1458473448) },
      UINT8_C(  0) },
    { { -INT32_C(  1247097789), -INT32_C(   810453835), -INT32_C(  1816237768),  INT32_C(  2077586813) },
      UINT8_C(  7) },
    { { -INT32_C(  1359774925), -INT32_C(   574871122), -INT32_C(  1221778225), -INT32_C(   267576403) },
      UINT8_C( 15) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__mmask8 r = simde_mm_movepi32_mask(a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__mmask8 r = simde_mm_movepi32_mask(a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_movepi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT64_C( 8985098879671146388), -INT64_C( 1774927821684719271) },
      UINT8_C(  3) },
    { { -INT64_C( 6374873338066020493), -INT64_C( 2178519056744984205) },
      UINT8_C(  3) },
    { {  INT64_C( 1364798191684170817),  INT64_C( 1905382897975129854) },
      UINT8_C(  0) },
    { {  INT64_C( 4809595702362958239), -INT64_C( 6609924829744198930) },
      UINT8_C(  2) },
    { {  INT64_C( 7913952024705741577), -INT64_C( 6613420582078202505) },
      UINT8_C(  2) },
    { { -INT64_C( 2710186300933353902),  INT64_C( 5876496338450740358) },
      UINT8_C(  1) },
    { {  INT64_C( 1590589390765399605), -INT64_C( 4157266161983812955) },
      UINT8_C(  2) },
    { {  INT64_C(  864774168005511738), -INT64_C(  839496098544009793) },
      UINT8_C(  2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__mmask8 r = simde_mm_movepi64_mask(a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__mmask8 r = simde_mm_movepi64_mask(a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_movepi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { -INT8_C(  88),  INT8_C(  21),  INT8_C(  41), -INT8_C( 119), -INT8_C(  58), -INT8_C(  90),      INT8_MIN, -INT8_C(  29),
         INT8_C(  74), -INT8_C(  83), -INT8_C(  42),  INT8_C(  27),  INT8_C(  59), -INT8_C(  53), -INT8_C(  76), -INT8_C(  12),
         INT8_C(  36), -INT8_C(  27),  INT8_C(  54),  INT8_C( 119), -INT8_C(  63), -INT8_C(  79), -INT8_C(  72), -INT8_C(  30),
         INT8_C(  35), -INT8_C(  62),  INT8_C(  69), -INT8_C(  29),  INT8_C(  72),  INT8_C(  50), -INT8_C(  80), -INT8_C(  16) },
      UINT32_C(3404916473) },
    { {  INT8_C(  71), -INT8_C(  39),  INT8_C( 121),  INT8_C(  13),      INT8_MIN, -INT8_C(   7), -INT8_C(  16), -INT8_C(  54),
        -INT8_C(  90), -INT8_C(  57), -INT8_C(  26), -INT8_C(  30), -INT8_C( 110), -INT8_C( 102), -INT8_C(  42), -INT8_C(  74),
             INT8_MAX,  INT8_C(  12),  INT8_C(  46),  INT8_C(  64), -INT8_C(  67), -INT8_C(  26),  INT8_C(  34), -INT8_C(  31),
        -INT8_C(  88),  INT8_C( 104), -INT8_C(  60), -INT8_C(  16), -INT8_C( 102),  INT8_C( 116), -INT8_C(  32), -INT8_C(  31) },
      UINT32_C(3719364594) },
    { {  INT8_C(  77),  INT8_C(  89), -INT8_C(  17), -INT8_C(  51),  INT8_C(  82), -INT8_C(  33), -INT8_C( 104), -INT8_C(   8),
        -INT8_C(  90),  INT8_C( 126), -INT8_C(  38),  INT8_C(  57),  INT8_C(  24), -INT8_C(  80), -INT8_C(  17), -INT8_C( 105),
        -INT8_C(  68),  INT8_C(  29), -INT8_C(  40),  INT8_C( 122),  INT8_C(   3), -INT8_C(   6),  INT8_C(  91), -INT8_C(  85),
         INT8_C(  98),  INT8_C(  31), -INT8_C( 101), -INT8_C(   4), -INT8_C( 109),  INT8_C( 123), -INT8_C(  34), -INT8_C(  32) },
      UINT32_C(3701859820) },
    { { -INT8_C(  44), -INT8_C(  51), -INT8_C(  82),  INT8_C(  38), -INT8_C(  84),  INT8_C(  70),  INT8_C(  31),  INT8_C(  83),
        -INT8_C(  60), -INT8_C(   7), -INT8_C( 116), -INT8_C(  36), -INT8_C(  86),  INT8_C( 123),  INT8_C( 115),  INT8_C( 102),
        -INT8_C( 103),  INT8_C(  75), -INT8_C(  32), -INT8_C( 100),  INT8_C(  70),  INT8_C(  59),  INT8_C(  72), -INT8_C(  88),
         INT8_C(  90), -INT8_C(  29), -INT8_C(  91), -INT8_C(  19),  INT8_C(  95), -INT8_C( 125), -INT8_C(  50),  INT8_C(  51) },
      UINT32_C(1854742295) },
    { {  INT8_C(  80),  INT8_C( 124),  INT8_C(  90), -INT8_C(   4), -INT8_C(  62),  INT8_C( 121),  INT8_C(  79), -INT8_C( 122),
         INT8_C( 114), -INT8_C(  37),  INT8_C(  98),  INT8_C(  28),  INT8_C(  87), -INT8_C(  43), -INT8_C( 125), -INT8_C(  16),
         INT8_C(  33),  INT8_C(  99), -INT8_C( 116),  INT8_C( 103), -INT8_C(  97), -INT8_C(  44),  INT8_C(  15), -INT8_C(   7),
        -INT8_C(  72), -INT8_C(  76), -INT8_C(  25),  INT8_C(  23),  INT8_C(  55), -INT8_C(  75),  INT8_C(  74), -INT8_C( 121) },
      UINT32_C(2813649560) },
    { {  INT8_C(  49), -INT8_C(  92), -INT8_C( 124), -INT8_C(  13),  INT8_C(  29), -INT8_C(  45),  INT8_C( 121), -INT8_C( 112),
        -INT8_C(  81), -INT8_C(  37), -INT8_C(  84),  INT8_C(   6), -INT8_C(  80),  INT8_C(  47), -INT8_C(  10), -INT8_C(  47),
        -INT8_C( 109), -INT8_C( 126),  INT8_C(  56),  INT8_C(  50),  INT8_C(  87),  INT8_C(  72),  INT8_C(  43),  INT8_C(  15),
        -INT8_C(   4),  INT8_C(  18),  INT8_C(  38),  INT8_C(  52), -INT8_C(  57),  INT8_C( 112), -INT8_C(  69), -INT8_C(   8) },
      UINT32_C(3506689966) },
    { {  INT8_C(  21),  INT8_C(  63), -INT8_C(  21),  INT8_C(  50),  INT8_C(  19),  INT8_C( 100), -INT8_C(  62), -INT8_C(  62),
         INT8_C(  63),  INT8_C( 111), -INT8_C(  56), -INT8_C(  16), -INT8_C(  98), -INT8_C(  66), -INT8_C(  63),  INT8_C(  49),
         INT8_C(  64), -INT8_C(   6),  INT8_C(  99), -INT8_C( 105),  INT8_C(  66), -INT8_C( 113), -INT8_C(  90),  INT8_C(  62),
        -INT8_C(  95), -INT8_C(  52),  INT8_C( 114),  INT8_C( 105),  INT8_C(  61),  INT8_C(  46),  INT8_C(  97),  INT8_C(  82) },
      UINT32_C(  57310404) },
    { {  INT8_C( 109),  INT8_C(  77), -INT8_C( 124),      INT8_MIN, -INT8_C(  79),  INT8_C(  71),  INT8_C(  66), -INT8_C(  15),
        -INT8_C(  74),  INT8_C(  10), -INT8_C(  31),  INT8_C(  84), -INT8_C(  56), -INT8_C(  94), -INT8_C( 122),  INT8_C(   9),
        -INT8_C( 100), -INT8_C(  23), -INT8_C(  96), -INT8_C(  34),  INT8_C( 120),  INT8_C(  71),  INT8_C(  29),  INT8_C(  26),
         INT8_C(  19), -INT8_C( 113), -INT8_C( 125),  INT8_C(  80), -INT8_C(  67), -INT8_C(  28), -INT8_C(  94),  INT8_C(  43) },
      UINT32_C(1980724636) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__mmask32 r = simde_mm256_movepi8_mask(a);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__mmask32 r = simde_mm256_movepi8_mask(a);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_movepi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT16_C( 23942), -INT16_C( 13964), -INT16_C( 15829), -INT16_C(  4752), -INT16_C( 32593), -INT16_C( 16422),  INT16_C(  6984),  INT16_C( 21147),
         INT16_C(  6830), -INT16_C(  8372),  INT16_C(  7384),  INT16_C( 13776), -INT16_C( 28383), -INT16_C(  1156),  INT16_C(  6875),  INT16_C( 25327) },
      UINT16_C(12862) },
    { {  INT16_C( 25463), -INT16_C( 24021), -INT16_C( 25818), -INT16_C( 10864),  INT16_C( 27164),  INT16_C( 25748),  INT16_C( 12421),  INT16_C( 13238),
         INT16_C(   586),  INT16_C(  8722), -INT16_C(  7394),  INT16_C( 16216), -INT16_C( 11148),  INT16_C( 20283),  INT16_C( 10990),  INT16_C( 26289) },
      UINT16_C( 5134) },
    { { -INT16_C(  9075), -INT16_C( 19704), -INT16_C( 26504), -INT16_C( 27511),  INT16_C(  7427), -INT16_C( 30472), -INT16_C( 20915), -INT16_C( 26692),
        -INT16_C( 12624), -INT16_C( 12614),  INT16_C(  4785),  INT16_C(  9485),  INT16_C( 18662), -INT16_C( 11147),  INT16_C(  9842),  INT16_C(    58) },
      UINT16_C( 9199) },
    { {  INT16_C( 17155),  INT16_C( 31667),  INT16_C( 15579), -INT16_C(  8689),  INT16_C(  1882), -INT16_C( 22681),  INT16_C(  9141),  INT16_C( 25919),
        -INT16_C(  1551), -INT16_C( 23757),  INT16_C( 16395), -INT16_C(  3640),  INT16_C( 15753), -INT16_C(  1083),  INT16_C(   100),  INT16_C( 26619) },
      UINT16_C(11048) },
    { { -INT16_C( 20669),  INT16_C(  7906), -INT16_C(  3605),  INT16_C( 17917),  INT16_C( 25848), -INT16_C( 21011),  INT16_C( 11399),  INT16_C( 30738),
         INT16_C( 17701),  INT16_C( 12315), -INT16_C(  7035),  INT16_C(  3617), -INT16_C(  6623), -INT16_C( 31478),  INT16_C(  1510),  INT16_C( 10732) },
      UINT16_C(13349) },
    { { -INT16_C( 12620), -INT16_C( 24504),  INT16_C( 17855), -INT16_C( 18459), -INT16_C( 11607),  INT16_C( 12388),  INT16_C( 30462),  INT16_C(  9128),
        -INT16_C( 15173),  INT16_C( 16723),  INT16_C( 29864), -INT16_C( 14001),  INT16_C( 22875),  INT16_C( 16719),  INT16_C( 15199),  INT16_C(  4971) },
      UINT16_C( 2331) },
    { { -INT16_C( 19702), -INT16_C( 13901), -INT16_C( 26120), -INT16_C( 24191), -INT16_C(  6805),  INT16_C( 27345),  INT16_C( 31068),  INT16_C(  6029),
        -INT16_C(  7875), -INT16_C(  6824), -INT16_C( 22443), -INT16_C( 20305), -INT16_C(   511),  INT16_C( 24818),  INT16_C( 23865),  INT16_C( 17268) },
      UINT16_C( 7967) },
    { {  INT16_C( 10000),  INT16_C(  2061), -INT16_C( 28992),  INT16_C( 11433),  INT16_C( 31347), -INT16_C( 12394),  INT16_C(  9203),  INT16_C( 12775),
         INT16_C( 16132),  INT16_C( 23062), -INT16_C( 14873), -INT16_C(  5878), -INT16_C(   829), -INT16_C(   695), -INT16_C( 17063),  INT16_C( 26944) },
      UINT16_C(31780) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__mmask16 r = simde_mm256_movepi16_mask(a);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__mmask16 r = simde_mm256_movepi16_mask(a);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_movepi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT32_C(  2142769029), -INT32_C(  1306321235),  INT32_C(   307118215), -INT32_C(  1222795281),  INT32_C(  1900491781),  INT32_C(   966748555), -INT32_C(    47661312), -INT32_C(   591974047) },
      UINT8_C(203) },
    { { -INT32_C(   832766431), -INT32_C(  1535082723), -INT32_C(  1346908224),  INT32_C(  1952896110), -INT32_C(  1813664504),  INT32_C(   399279127), -INT32_C(  1542130621),  INT32_C(  1199623205) },
      UINT8_C( 87) },
    { { -INT32_C(   417997366),  INT32_C(   478975580), -INT32_C(   741653659),  INT32_C(   524759319), -INT32_C(   156095009), -INT32_C(   183664975), -INT32_C(  1751571854), -INT32_C(  1193403666) },
      UINT8_C(245) },
    { {  INT32_C(  1403057399), -INT32_C(   277861238), -INT32_C(  2034091153),  INT32_C(  1285884525), -INT32_C(   398305481),  INT32_C(  1205686229),  INT32_C(  1608415089), -INT32_C(  2011644527) },
      UINT8_C(150) },
    { {  INT32_C(  1004255409),  INT32_C(  1395280868), -INT32_C(   187044729),  INT32_C(   759201526), -INT32_C(  1441365291),  INT32_C(  1139930065), -INT32_C(    73216150),  INT32_C(  1032043148) },
      UINT8_C( 84) },
    { {  INT32_C(  1450729330),  INT32_C(   833200810), -INT32_C(  2061139313), -INT32_C(   709663488), -INT32_C(  1182807577),  INT32_C(   670855356), -INT32_C(   870146496), -INT32_C(   888494503) },
      UINT8_C(220) },
    { { -INT32_C(  1356692987), -INT32_C(  1260270811),  INT32_C(  1312360014),  INT32_C(  1394928748),  INT32_C(  1913430965),  INT32_C(  1419315220),  INT32_C(     2145191),  INT32_C(  1724590689) },
      UINT8_C(  3) },
    { { -INT32_C(   770249299),  INT32_C(   126285753),  INT32_C(  1767227389),  INT32_C(  1639807404),  INT32_C(   835963165),  INT32_C(  2038787282), -INT32_C(  1988516568),  INT32_C(  2112898256) },
      UINT8_C( 65) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__mmask8 r = simde_mm256_movepi32_mask(a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__mmask8 r = simde_mm256_movepi32_mask(a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_movepi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT64_C( 1621470838541238162), -INT64_C( 2020267518521858509), -INT64_C(  140451368858056884), -INT64_C( 2778531396810572735) },
      UINT8_C( 15) },
    { {  INT64_C( 2067811840525109484), -INT64_C( 3583349620661817091), -INT64_C( 8493721512905259799), -INT64_C( 8179256404884720071) },
      UINT8_C( 14) },
    { { -INT64_C( 6197223924085336582), -INT64_C( 5383681940865127687), -INT64_C( 1123093167729051242), -INT64_C( 3017955061275530514) },
      UINT8_C( 15) },
    { {  INT64_C( 8699749956815779174), -INT64_C( 5790437138794035422),  INT64_C( 7087530517990374581),  INT64_C( 7355240209651527521) },
      UINT8_C(  2) },
    { { -INT64_C( 6378165230648111994),  INT64_C( 6972481154558881787), -INT64_C( 6157503399613148746),  INT64_C( 1548951913861971479) },
      UINT8_C(  5) },
    { {  INT64_C( 2806752101191513799),  INT64_C( 8796091663676770565),  INT64_C( 2036243881630424399), -INT64_C( 1417594688471094865) },
      UINT8_C(  8) },
    { {  INT64_C(  646313841939475880), -INT64_C( 9155313154145045580),  INT64_C( 8559472380443399848),  INT64_C( 6238620930062810500) },
      UINT8_C(  2) },
    { { -INT64_C( 6088547874471555979), -INT64_C( 5907011847308756396), -INT64_C(  150829383993844054),  INT64_C( 1956597046960299298) },
      UINT8_C(  7) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__mmask8 r = simde_mm256_movepi64_mask(a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__mmask8 r = simde_mm256_movepi64_mask(a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_movepi8_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask64 r;
  } test_vec[8] = {
    { simde_mm512_set_epi8(INT8_C(  75), INT8_C(  84), INT8_C( -79), INT8_C( 113),
                           INT8_C( -44), INT8_C( 119), INT8_C( -99), INT8_C(  -4),
                           INT8_C(  89), INT8_C(-108), INT8_C( -20), INT8_C(  38),
                           INT8_C(  62), INT8_C(-115), INT8_C( -29), INT8_C(  -6),
                           INT8_C( 109), INT8_C(  49), INT8_C( 126), INT8_C(  76),
                           INT8_C(  52), INT8_C( -99), INT8_C(  65), INT8_C(  -6),
                           INT8_C( -62), INT8_C( -30), INT8_C( 123), INT8_C(-120),
                           INT8_C( 125), INT8_C( -67), INT8_C(  19), INT8_C( -96),
                           INT8_C( -23), INT8_C(-114), INT8_C( -85), INT8_C(  24),
                           INT8_C( -96), INT8_C(  27), INT8_C( 107), INT8_C( -48),
                           INT8_C(  68), INT8_C(  79), INT8_C(-118), INT8_C(  69),
                           INT8_C(-100), INT8_C(  45), INT8_C(-127), INT8_C( -25),
                           INT8_C(   9), INT8_C( -99), INT8_C( -49), INT8_C(  57),
                           INT8_C( -33), INT8_C( -74), INT8_C(  36), INT8_C( -16),
                           INT8_C(   9), INT8_C(-119), INT8_C( -47), INT8_C( -40),
                           INT8_C(   1), INT8_C(-104), INT8_C( -83), INT8_C( -86)),
      UINT64_C( 3127474882530209143) },
    { simde_mm512_set_epi8(INT8_C( -83), INT8_C(  52), INT8_C(-122), INT8_C(  -1),
                           INT8_C( -37), INT8_C( -46), INT8_C( -20), INT8_C( -41),
                           INT8_C( -29), INT8_C( -98), INT8_C( -38), INT8_C( 119),
                           INT8_C( -30), INT8_C( -12), INT8_C(  38), INT8_C(   8),
                           INT8_C( -90), INT8_C( -98), INT8_C(  69), INT8_C(  44),
                           INT8_C( -98), INT8_C(  64), INT8_C(-113), INT8_C(  32),
                           INT8_C( -82), INT8_C(  31), INT8_C( -61), INT8_C(  74),
                           INT8_C(  55), INT8_C(  19), INT8_C( -15), INT8_C( -10),
                           INT8_C(  24), INT8_C(  71), INT8_C( -97), INT8_C( -89),
                           INT8_C(-113), INT8_C( -22), INT8_C(   7), INT8_C( -79),
                           INT8_C( 106), INT8_C(  -5), INT8_C(  74), INT8_C( -28),
                           INT8_C(-121), INT8_C( -90), INT8_C( -60), INT8_C( -53),
                           INT8_C(   0), INT8_C(-112), INT8_C( -95), INT8_C( 115),
                           INT8_C(-101), INT8_C(  14), INT8_C(-105), INT8_C( -35),
                           INT8_C(-121), INT8_C(  -9), INT8_C( 105), INT8_C(  14),
                           INT8_C(  36), INT8_C( 103), INT8_C( -76), INT8_C(  42)),
      UINT64_C(13829651358206094274) },
    { simde_mm512_set_epi8(INT8_C( -71), INT8_C( -56), INT8_C( -76), INT8_C(  52),
                           INT8_C(  20), INT8_C(-117), INT8_C( -18), INT8_C(-112),
                           INT8_C(  87), INT8_C(-104), INT8_C( 127), INT8_C(  76),
                           INT8_C(  77), INT8_C(  75), INT8_C( -19), INT8_C( -45),
                           INT8_C( -26), INT8_C( -13), INT8_C(  75), INT8_C( -95),
                           INT8_C(  -9), INT8_C(  77), INT8_C( -48), INT8_C( -15),
                           INT8_C( -67), INT8_C(  74), INT8_C(-118), INT8_C( -27),
                           INT8_C(  55), INT8_C( -43), INT8_C(  66), INT8_C(  14),
                           INT8_C(  -1), INT8_C(-106), INT8_C(-103), INT8_C(  31),
                           INT8_C( 121), INT8_C( -29), INT8_C(-102), INT8_C( -49),
                           INT8_C(  83), INT8_C( 107), INT8_C( 108), INT8_C(   3),
                           INT8_C(  22), INT8_C(   3), INT8_C( -29), INT8_C( -27),
                           INT8_C( 120), INT8_C( -58), INT8_C( 125), INT8_C(   0),
                           INT8_C(  -9), INT8_C(  -3), INT8_C(  15), INT8_C( -66),
                           INT8_C( -51), INT8_C( 101), INT8_C(  34), INT8_C( 126),
                           INT8_C(-112), INT8_C(-122), INT8_C(  95), INT8_C(  48)),
      UINT64_C(16664404616217316748) },
    { simde_mm512_set_epi8(INT8_C(-116), INT8_C(-100), INT8_C( -34), INT8_C(-123),
                           INT8_C( -47), INT8_C( -44), INT8_C( 113), INT8_C( -91),
                           INT8_C(  58), INT8_C( -81), INT8_C( -77), INT8_C( -24),
                           INT8_C(  21), INT8_C( -62), INT8_C(-107), INT8_C( 106),
                           INT8_C(-106), INT8_C( 105), INT8_C(  13), INT8_C(-125),
                           INT8_C( -31), INT8_C(  28), INT8_C( -32), INT8_C( -10),
                           INT8_C(  15), INT8_C(  23), INT8_C(  39), INT8_C(  16),
                           INT8_C( 122), INT8_C(  67), INT8_C(  -7), INT8_C(  68),
                           INT8_C( 116), INT8_C( -71), INT8_C( -82), INT8_C( -91),
                           INT8_C( -59), INT8_C( -18), INT8_C(-128), INT8_C(  16),
                           INT8_C( -63), INT8_C( 127), INT8_C( -98), INT8_C(  94),
                           INT8_C(  -2), INT8_C( -80), INT8_C( -35), INT8_C( -93),
                           INT8_C(  -5), INT8_C(   3), INT8_C( 126), INT8_C(  13),
                           INT8_C( -63), INT8_C(  43), INT8_C(  49), INT8_C(  77),
                           INT8_C(  30), INT8_C(  66), INT8_C(  35), INT8_C(-127),
                           INT8_C(  78), INT8_C(  40), INT8_C(   5), INT8_C(  66)),
      UINT64_C(18263955773865297936) },
    { simde_mm512_set_epi8(INT8_C( -92), INT8_C( -13), INT8_C(  48), INT8_C(  12),
                           INT8_C(  95), INT8_C(  98), INT8_C( 122), INT8_C( 111),
                           INT8_C(  27), INT8_C( -60), INT8_C( -86), INT8_C( -36),
                           INT8_C(  67), INT8_C(  45), INT8_C(  28), INT8_C(  89),
                           INT8_C(  36), INT8_C( -13), INT8_C( -96), INT8_C(  48),
                           INT8_C(  88), INT8_C(   9), INT8_C( -73), INT8_C(  80),
                           INT8_C( -52), INT8_C(-107), INT8_C( -78), INT8_C(  89),
                           INT8_C(-100), INT8_C( -11), INT8_C( 124), INT8_C(  50),
                           INT8_C(  52), INT8_C(  14), INT8_C(  84), INT8_C(  75),
                           INT8_C( -26), INT8_C(  56), INT8_C( -88), INT8_C(  97),
                           INT8_C(  48), INT8_C(  37), INT8_C(  28), INT8_C(  73),
                           INT8_C(  20), INT8_C( 113), INT8_C( -11), INT8_C(-118),
                           INT8_C( 118), INT8_C( -13), INT8_C( 119), INT8_C(  10),
                           INT8_C( 113), INT8_C(  86), INT8_C( -63), INT8_C(  67),
                           INT8_C(  52), INT8_C(  18), INT8_C(  22), INT8_C(  21),
                           INT8_C(  82), INT8_C( -77), INT8_C(  13), INT8_C(  -3)),
      UINT64_C(13866692018593546757) },
    { simde_mm512_set_epi8(INT8_C( -39), INT8_C( -32), INT8_C( -11), INT8_C(  52),
                           INT8_C(  61), INT8_C(  14), INT8_C(  35), INT8_C(  -8),
                           INT8_C(-119), INT8_C(-116), INT8_C( -41), INT8_C( -89),
                           INT8_C( -55), INT8_C( -86), INT8_C(  77), INT8_C(  46),
                           INT8_C(-121), INT8_C( -53), INT8_C( -15), INT8_C(  39),
                           INT8_C(  82), INT8_C( 120), INT8_C( -49), INT8_C(  93),
                           INT8_C( 100), INT8_C( 121), INT8_C(  31), INT8_C( -32),
                           INT8_C(  22), INT8_C( -32), INT8_C(  88), INT8_C( -52),
                           INT8_C(-102), INT8_C( -24), INT8_C(   9), INT8_C(  67),
                           INT8_C(-114), INT8_C(   4), INT8_C( 106), INT8_C(-121),
                           INT8_C( -75), INT8_C(  30), INT8_C(  16), INT8_C(  48),
                           INT8_C( 127), INT8_C(  71), INT8_C( -26), INT8_C( -22),
                           INT8_C( -63), INT8_C(  35), INT8_C( -80), INT8_C( -51),
                           INT8_C(  20), INT8_C( 120), INT8_C( 123), INT8_C(  28),
                           INT8_C(  25), INT8_C(  66), INT8_C( -14), INT8_C( -79),
                           INT8_C(  44), INT8_C(  96), INT8_C(  31), INT8_C( -24)),
      UINT64_C(16284138935867912241) },
    { simde_mm512_set_epi8(INT8_C(  -8), INT8_C(-106), INT8_C( -32), INT8_C(-125),
                           INT8_C(  -8), INT8_C(  59), INT8_C( 113), INT8_C( 106),
                           INT8_C( 124), INT8_C( 123), INT8_C( -45), INT8_C(  -6),
                           INT8_C( 110), INT8_C( -44), INT8_C( 116), INT8_C(  65),
                           INT8_C(-109), INT8_C(  54), INT8_C( -45), INT8_C(-108),
                           INT8_C( 113), INT8_C( -80), INT8_C( -25), INT8_C( -81),
                           INT8_C(  66), INT8_C(   5), INT8_C( -16), INT8_C(  69),
                           INT8_C(-120), INT8_C( 101), INT8_C(-120), INT8_C(-105),
                           INT8_C(  93), INT8_C(  26), INT8_C( 126), INT8_C( -64),
                           INT8_C( 107), INT8_C( 115), INT8_C(  -9), INT8_C(  38),
                           INT8_C(  67), INT8_C( -62), INT8_C(  22), INT8_C(  68),
                           INT8_C( -28), INT8_C( -64), INT8_C(  52), INT8_C(  39),
                           INT8_C(  38), INT8_C( -87), INT8_C(  -5), INT8_C(  99),
                           INT8_C(  33), INT8_C(   4), INT8_C(-101), INT8_C(-121),
                           INT8_C(-105), INT8_C(  71), INT8_C( -11), INT8_C( -20),
                           INT8_C(   0), INT8_C(  19), INT8_C(  16), INT8_C(-121)),
      UINT64_C(17885121415813555121) },
    { simde_mm512_set_epi8(INT8_C(-113), INT8_C(   2), INT8_C(  81), INT8_C( -78),
                           INT8_C(  -3), INT8_C(-106), INT8_C( -17), INT8_C(-117),
                           INT8_C(   2), INT8_C(  20), INT8_C(  53), INT8_C( -65),
                           INT8_C(  30), INT8_C(  26), INT8_C(  22), INT8_C(  99),
                           INT8_C(  -8), INT8_C( -85), INT8_C(  90), INT8_C( -79),
                           INT8_C( -92), INT8_C( -73), INT8_C( -12), INT8_C( -69),
                           INT8_C(  75), INT8_C(-113), INT8_C(  90), INT8_C(  28),
                           INT8_C(-109), INT8_C(-116), INT8_C(  79), INT8_C( -43),
                           INT8_C( -42), INT8_C( -70), INT8_C(  36), INT8_C( -40),
                           INT8_C(-104), INT8_C( 116), INT8_C( -91), INT8_C( -94),
                           INT8_C( 104), INT8_C( -96), INT8_C(  80), INT8_C( -49),
                           INT8_C(   7), INT8_C(  18), INT8_C(  11), INT8_C(  65),
                           INT8_C( -67), INT8_C(  98), INT8_C(  11), INT8_C( -90),
                           INT8_C( 109), INT8_C(-116), INT8_C( 101), INT8_C(  94),
                           INT8_C(  56), INT8_C( -34), INT8_C(  49), INT8_C(  75),
                           INT8_C(  63), INT8_C(-104), INT8_C(-118), INT8_C( -65)),
      UINT64_C(11461906577142879303) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask64 r = simde_mm512_movepi8_mask(test_vec[i].a);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movepi16_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask32 r;
  } test_vec[8] = {
    { simde_mm512_set_epi16(INT16_C(-17047), INT16_C(-27489), INT16_C(-15227), INT16_C( 31130),
                            INT16_C(  7900), INT16_C(  4229), INT16_C( 19494), INT16_C(  -313),
                            INT16_C( -7407), INT16_C(  6880), INT16_C( 31932), INT16_C(-13004),
                            INT16_C(-16593), INT16_C( 30037), INT16_C( 23370), INT16_C(-27033),
                            INT16_C( -6275), INT16_C(-24391), INT16_C( 19922), INT16_C(  9007),
                            INT16_C(-32282), INT16_C( 30675), INT16_C(-23274), INT16_C(-21419),
                            INT16_C( 30850), INT16_C(-11557), INT16_C(-13740), INT16_C(  3686),
                            INT16_C( 25062), INT16_C( -6498), INT16_C(-22187), INT16_C(  3349)),
      UINT32_C(3784952678) },
    { simde_mm512_set_epi16(INT16_C( 13923), INT16_C( 27595), INT16_C(-30758), INT16_C(  6795),
                            INT16_C( 23230), INT16_C( 13435), INT16_C( 30013), INT16_C(  -139),
                            INT16_C(-20677), INT16_C( 11858), INT16_C(  8955), INT16_C( 19017),
                            INT16_C(   604), INT16_C(-27923), INT16_C( -6277), INT16_C(-19699),
                            INT16_C( 25596), INT16_C( -5717), INT16_C(-26964), INT16_C( 16652),
                            INT16_C( 24642), INT16_C( 18959), INT16_C(-25136), INT16_C( -8754),
                            INT16_C( -5203), INT16_C(-23370), INT16_C(-26802), INT16_C(-30926),
                            INT16_C( 20471), INT16_C(-28596), INT16_C(-19925), INT16_C( 29562)),
      UINT32_C(562521078) },
    { simde_mm512_set_epi16(INT16_C(  1548), INT16_C( -4457), INT16_C( 28166), INT16_C(-19674),
                            INT16_C(  -618), INT16_C(-20513), INT16_C(-19054), INT16_C( -9253),
                            INT16_C(-13318), INT16_C( -7485), INT16_C( 29771), INT16_C( 24344),
                            INT16_C(  7181), INT16_C(-19395), INT16_C(-25613), INT16_C(-15382),
                            INT16_C( 11288), INT16_C( 15682), INT16_C( 21669), INT16_C( 20625),
                            INT16_C( 29057), INT16_C( -8121), INT16_C( -5440), INT16_C(  3057),
                            INT16_C( -7315), INT16_C(-18718), INT16_C(-26828), INT16_C( -6341),
                            INT16_C( -6106), INT16_C( -2348), INT16_C( 30905), INT16_C(-10037)),
      UINT32_C(1606878973) },
    { simde_mm512_set_epi16(INT16_C( 14148), INT16_C( 31053), INT16_C(-19743), INT16_C(-19340),
                            INT16_C(-12275), INT16_C( 27369), INT16_C(-24803), INT16_C(  5116),
                            INT16_C(-16383), INT16_C( 28006), INT16_C(-24294), INT16_C(-24984),
                            INT16_C( 12919), INT16_C(-17951), INT16_C( 31664), INT16_C(  7912),
                            INT16_C( 12196), INT16_C(-27188), INT16_C( 23535), INT16_C(-31330),
                            INT16_C(-27343), INT16_C( 14195), INT16_C(  5995), INT16_C( 10459),
                            INT16_C( 12832), INT16_C( 13655), INT16_C(-20140), INT16_C(-26343),
                            INT16_C(-13772), INT16_C( -9475), INT16_C(-28427), INT16_C(-11691)),
      UINT32_C(984897599) },
    { simde_mm512_set_epi16(INT16_C(-22300), INT16_C(-10421), INT16_C( -5153), INT16_C(  5119),
                            INT16_C( 12821), INT16_C( 17382), INT16_C( -4532), INT16_C(-11640),
                            INT16_C( -1430), INT16_C( 18534), INT16_C( -8310), INT16_C(-13530),
                            INT16_C( 24972), INT16_C(-18125), INT16_C( 24561), INT16_C( -2389),
                            INT16_C(-27012), INT16_C(-15171), INT16_C( 25076), INT16_C( 17208),
                            INT16_C(-10726), INT16_C(-14428), INT16_C( 18609), INT16_C( 16453),
                            INT16_C( 17590), INT16_C(   596), INT16_C(  5139), INT16_C(-28922),
                            INT16_C(-14748), INT16_C(-14808), INT16_C( 29503), INT16_C( 18271)),
      UINT32_C(3820342300) },
    { simde_mm512_set_epi16(INT16_C( -1922), INT16_C( 28045), INT16_C(  7072), INT16_C( -6655),
                            INT16_C(-10335), INT16_C(  3620), INT16_C(-24526), INT16_C( 22370),
                            INT16_C( 21531), INT16_C( 30935), INT16_C(  8939), INT16_C(-11772),
                            INT16_C( 17436), INT16_C(  5814), INT16_C(-22069), INT16_C( 15046),
                            INT16_C(  4673), INT16_C( 28770), INT16_C(   154), INT16_C(  3548),
                            INT16_C(-13962), INT16_C(-26257), INT16_C(  -315), INT16_C( 21241),
                            INT16_C( -5135), INT16_C(  2068), INT16_C(  4376), INT16_C(-32178),
                            INT16_C( 14170), INT16_C( -3876), INT16_C( 30653), INT16_C( 15729)),
      UINT32_C(2584874644) },
    { simde_mm512_set_epi16(INT16_C( 10719), INT16_C( 25050), INT16_C(-15358), INT16_C( -1679),
                            INT16_C(-13098), INT16_C(-28834), INT16_C( -9407), INT16_C(  1027),
                            INT16_C( -8964), INT16_C( 27458), INT16_C( 16082), INT16_C( 12178),
                            INT16_C(  1218), INT16_C(-18769), INT16_C(-25942), INT16_C(-28951),
                            INT16_C( 25249), INT16_C(-28972), INT16_C(-23822), INT16_C( 15695),
                            INT16_C( 24838), INT16_C( -7902), INT16_C( 17882), INT16_C( -8203),
                            INT16_C(-28681), INT16_C( -7333), INT16_C( 30548), INT16_C(-23603),
                            INT16_C( 15565), INT16_C(-21742), INT16_C( 12497), INT16_C( -3539)),
      UINT32_C(1049060821) },
    { simde_mm512_set_epi16(INT16_C( 27841), INT16_C(  5697), INT16_C( 21581), INT16_C(-21663),
                            INT16_C(-31814), INT16_C( 15339), INT16_C(-24806), INT16_C( 28625),
                            INT16_C( -2580), INT16_C(-27637), INT16_C( 20611), INT16_C( 26105),
                            INT16_C( 20780), INT16_C( 32638), INT16_C( 17822), INT16_C( 21576),
                            INT16_C( 16865), INT16_C(-18111), INT16_C( -8939), INT16_C(-14679),
                            INT16_C(-25963), INT16_C( -8164), INT16_C( -7364), INT16_C( 13563),
                            INT16_C(  4030), INT16_C(-20513), INT16_C(-30065), INT16_C(-30263),
                            INT16_C( 23452), INT16_C(  9713), INT16_C(-23717), INT16_C( -7690)),
      UINT32_C(448822899) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask32 r = simde_mm512_movepi16_mask(test_vec[i].a);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movepi32_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask16 r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  949963630), INT32_C( 1064968775), INT32_C(-1905189849), INT32_C(-1560216302),
                            INT32_C(-1667094448), INT32_C( 1432096084), INT32_C(  614973119), INT32_C( -938109633),
                            INT32_C( -573293838), INT32_C(-1613148160), INT32_C(  914563081), INT32_C( -664378047),
                            INT32_C(  580894207), INT32_C(   -5278152), INT32_C(-1290389695), INT32_C( 1268875821)),
      UINT16_C(14806) },
    { simde_mm512_set_epi32(INT32_C( 1744063513), INT32_C(  199551019), INT32_C( 2145427118), INT32_C( 2117462748),
                            INT32_C(-1526152394), INT32_C(-1859380110), INT32_C(-2006621963), INT32_C( 1533584129),
                            INT32_C(   86408218), INT32_C( 1744524288), INT32_C( 1245749395), INT32_C( 2117755472),
                            INT32_C( 1319846799), INT32_C(  684013019), INT32_C( -958932880), INT32_C(-1652765619)),
      UINT16_C(3587) },
    { simde_mm512_set_epi32(INT32_C( -357876242), INT32_C(-1625926758), INT32_C(-2123740483), INT32_C( -660511291),
                            INT32_C(-1776054627), INT32_C(  141209285), INT32_C(-1246421832), INT32_C( 1688546782),
                            INT32_C(  466911744), INT32_C( 1735300956), INT32_C(-1996452777), INT32_C( 2033250973),
                            INT32_C(  895403481), INT32_C(  890095351), INT32_C(-1050174441), INT32_C(  300665935)),
      UINT16_C(64034) },
    { simde_mm512_set_epi32(INT32_C( 1350930633), INT32_C(-2104240005), INT32_C(  -73808375), INT32_C( -223326096),
                            INT32_C(-1133084350), INT32_C(-2121661437), INT32_C( -195344417), INT32_C( -410489209),
                            INT32_C( 1846491503), INT32_C( 2122554983), INT32_C(  194022155), INT32_C(-1349250510),
                            INT32_C( 1589005094), INT32_C( -533309401), INT32_C(-1277337937), INT32_C(-1321119452)),
      UINT16_C(32535) },
    { simde_mm512_set_epi32(INT32_C(  918165817), INT32_C( 1913225422), INT32_C(-1721286233), INT32_C( 1673520973),
                            INT32_C( 1260386883), INT32_C( -845723997), INT32_C(  607206184), INT32_C(  655955271),
                            INT32_C( 1232293371), INT32_C( -686952046), INT32_C(  -38269764), INT32_C( 1897508883),
                            INT32_C(  232912531), INT32_C(  655019124), INT32_C( -684909810), INT32_C(  175412708)),
      UINT16_C(9314) },
    { simde_mm512_set_epi32(INT32_C( -167347570), INT32_C( 2106669082), INT32_C(  414695275), INT32_C( -187234329),
                            INT32_C(  687995662), INT32_C(-1870754825), INT32_C( -333242798), INT32_C(   41400550),
                            INT32_C(  956450496), INT32_C( -690912424), INT32_C(-1689027692), INT32_C( -582951840),
                            INT32_C( -348307758), INT32_C(-2091243549), INT32_C(-1450595733), INT32_C( 1635199293)),
      UINT16_C(38526) },
    { simde_mm512_set_epi32(INT32_C(  747298364), INT32_C( 1882006238), INT32_C( -996575344), INT32_C( 1843963633),
                            INT32_C(  705136482), INT32_C( 1503368131), INT32_C(-1576593524), INT32_C( 1439140790),
                            INT32_C( -402748742), INT32_C(  664771884), INT32_C(  747175899), INT32_C(  405982929),
                            INT32_C( 2131890450), INT32_C(-1594643895), INT32_C(-1014095286), INT32_C( 1590577530)),
      UINT16_C(8838) },
    { simde_mm512_set_epi32(INT32_C(  919103752), INT32_C(  840271230), INT32_C(  580240564), INT32_C(-1788774714),
                            INT32_C(  400169555), INT32_C(-1853738938), INT32_C(-1112922052), INT32_C(-1623445030),
                            INT32_C( 1270846818), INT32_C(-2065143748), INT32_C( 2058102073), INT32_C(  986096322),
                            INT32_C( 1628330811), INT32_C( 1467380999), INT32_C( -786808342), INT32_C(-1903665992)),
      UINT16_C(5955) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_movepi32_mask(test_vec[i].a);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movepi64_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask8 r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 4315835916621638572), INT64_C(-6674257362849511307),
                            INT64_C(-1762049467229420749), INT64_C(-8132359750587133268),
                            INT64_C( 6148678802780014396), INT64_C( 4664933343968897426),
                            INT64_C( 1014284963407527334), INT64_C( 3422825313800233729)),
      UINT8_C(112) },
    { simde_mm512_set_epi64(INT64_C(  574478659121970685), INT64_C(-6605171674412584848),
                            INT64_C( 4638820310774021553), INT64_C( 7174745169641818539),
                            INT64_C( 7314921907136775571), INT64_C(-2641502309573857208),
                            INT64_C( 6620802922844884113), INT64_C(-7711278827686512216)),
      UINT8_C(69) },
    { simde_mm512_set_epi64(INT64_C(-6147235395367117233), INT64_C( 6542122732864503940),
                            INT64_C(-4893279094642154374), INT64_C( -710603276995935312),
                            INT64_C(-6985907794246737252), INT64_C(-2323934421260723283),
                            INT64_C( 2081892758864471809), INT64_C(-1783091129455251103)),
      UINT8_C(189) },
    { simde_mm512_set_epi64(INT64_C(-7008686659697006374), INT64_C(-2302187120743568504),
                            INT64_C(-7431666373478318054), INT64_C(-1666370852874022248),
                            INT64_C(-5526045067730894819), INT64_C(-5366397760872850523),
                            INT64_C(-8148401067962473275), INT64_C( 6379593722474677948)),
      UINT8_C(254) },
    { simde_mm512_set_epi64(INT64_C( 5834225915365902233), INT64_C( 5212224477281615403),
                            INT64_C(-9044565203383400851), INT64_C(-7453762113383947542),
                            INT64_C( 7219309658228626013), INT64_C(-5724922725847615845),
                            INT64_C( 4784587912595387278), INT64_C( 2886700108880873396)),
      UINT8_C(52) },
    { simde_mm512_set_epi64(INT64_C( 1408273437008202704), INT64_C(-3431263432981659490),
                            INT64_C( -308854217089784545), INT64_C(-4251857914359021805),
                            INT64_C( 5524011446548464963), INT64_C( 7842350355250917332),
                            INT64_C( 1150922164682347155), INT64_C(-6938335843482793568)),
      UINT8_C(113) },
    { simde_mm512_set_epi64(INT64_C( 3466369033061057719), INT64_C( -853883159898808651),
                            INT64_C(-8837301080476701753), INT64_C( 1624970283957331834),
                            INT64_C( 8454378025299498630), INT64_C(-4025270946591081596),
                            INT64_C( 1760420628646065087), INT64_C(-7311372421099691274)),
      UINT8_C(101) },
    { simde_mm512_set_epi64(INT64_C( 6360525706956998040), INT64_C(-9084014240271266814),
                            INT64_C(-5488573213012393938), INT64_C( 9146279599643928313),
                            INT64_C(-2309198113695918692), INT64_C( 7647503988947974660),
                            INT64_C( -340783369849195617), INT64_C(-7174097298174507843)),
      UINT8_C(107) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_movepi64_mask(test_vec[i].a);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movepi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movepi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movepi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movepi64_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_movepi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_movepi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_movepi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_movepi64_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movepi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movepi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movepi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movepi64_mask)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
