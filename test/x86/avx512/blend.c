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
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN blend

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/blend.h>

static int
test_simde_mm_mask_blend_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(41706),
      {  INT8_C(  58),  INT8_C( 123),  INT8_C(  55), -INT8_C( 105),  INT8_C(  66), -INT8_C(   8),  INT8_C(  94),  INT8_C(  11),
        -INT8_C(  11),  INT8_C( 101), -INT8_C( 122), -INT8_C(  31),  INT8_C(  88),  INT8_C(  88), -INT8_C(  62), -INT8_C( 113) },
      {  INT8_C( 103),  INT8_C(  85),  INT8_C(   7),  INT8_C(  69), -INT8_C(  53),  INT8_C(  39),  INT8_C(  12),  INT8_C(  74),
         INT8_C( 112),  INT8_C(  47), -INT8_C( 127), -INT8_C(  29), -INT8_C(  72),  INT8_C( 107), -INT8_C( 123), -INT8_C(  13) },
      {  INT8_C(  58),  INT8_C(  85),  INT8_C(  55),  INT8_C(  69),  INT8_C(  66),  INT8_C(  39),  INT8_C(  12),  INT8_C(  74),
        -INT8_C(  11),  INT8_C(  47), -INT8_C( 122), -INT8_C(  31),  INT8_C(  88),  INT8_C( 107), -INT8_C(  62), -INT8_C(  13) } },
    { UINT16_C(48358),
      { -INT8_C( 118),  INT8_C(  41), -INT8_C(  75), -INT8_C(  24),  INT8_C(  52), -INT8_C(  86),  INT8_C(  78), -INT8_C(  70),
        -INT8_C( 117), -INT8_C(  90),  INT8_C(  19),  INT8_C(  77),  INT8_C(  53),  INT8_C( 122), -INT8_C(  94),  INT8_C(  60) },
      { -INT8_C(  64),  INT8_C( 109),  INT8_C(  99), -INT8_C(  52), -INT8_C(  73), -INT8_C(  45), -INT8_C(   5),  INT8_C(  57),
        -INT8_C(  74), -INT8_C(  77), -INT8_C(  92),  INT8_C(  59), -INT8_C(  90), -INT8_C( 117), -INT8_C(   8),  INT8_C(  49) },
      { -INT8_C( 118),  INT8_C( 109),  INT8_C(  99), -INT8_C(  24),  INT8_C(  52), -INT8_C(  45), -INT8_C(   5),  INT8_C(  57),
        -INT8_C( 117), -INT8_C(  90), -INT8_C(  92),  INT8_C(  59), -INT8_C(  90), -INT8_C( 117), -INT8_C(  94),  INT8_C(  49) } },
    { UINT16_C(44468),
      {  INT8_C(  25), -INT8_C(  24),  INT8_C(  87),  INT8_C( 103), -INT8_C(  93), -INT8_C(  30),  INT8_C(  13), -INT8_C(  74),
         INT8_C(  47),  INT8_C(  66),  INT8_C(  48), -INT8_C(  46),      INT8_MAX, -INT8_C(  16),  INT8_C(  63), -INT8_C(  30) },
      { -INT8_C(  68), -INT8_C(   9), -INT8_C(  74), -INT8_C(  73),  INT8_C(  48),  INT8_C( 108),  INT8_C( 107), -INT8_C(  44),
        -INT8_C(  88),  INT8_C(  17),  INT8_C(  95), -INT8_C(  96),  INT8_C(  66),  INT8_C(  19),  INT8_C(  77),  INT8_C(  92) },
      {  INT8_C(  25), -INT8_C(  24), -INT8_C(  74),  INT8_C( 103),  INT8_C(  48),  INT8_C( 108),  INT8_C(  13), -INT8_C(  44),
        -INT8_C(  88),  INT8_C(  66),  INT8_C(  95), -INT8_C(  96),      INT8_MAX,  INT8_C(  19),  INT8_C(  63),  INT8_C(  92) } },
    { UINT16_C(42236),
      { -INT8_C(  61), -INT8_C(  97), -INT8_C( 122), -INT8_C(  47),  INT8_C(  85), -INT8_C(  75),  INT8_C(  19), -INT8_C( 123),
        -INT8_C( 121), -INT8_C( 110),  INT8_C( 118), -INT8_C(  57),  INT8_C( 117),  INT8_C(  50), -INT8_C(  66),  INT8_C(  43) },
      { -INT8_C(  22), -INT8_C(  18), -INT8_C( 105),  INT8_C(  85), -INT8_C(  62),  INT8_C(  63),  INT8_C( 102),  INT8_C(  34),
        -INT8_C(  33), -INT8_C(  87),  INT8_C(  53),  INT8_C(  44),  INT8_C(   5),  INT8_C(  49), -INT8_C(  48), -INT8_C(  56) },
      { -INT8_C(  61), -INT8_C(  97), -INT8_C( 105),  INT8_C(  85), -INT8_C(  62),  INT8_C(  63),  INT8_C( 102),  INT8_C(  34),
        -INT8_C( 121), -INT8_C( 110),  INT8_C(  53), -INT8_C(  57),  INT8_C( 117),  INT8_C(  49), -INT8_C(  66), -INT8_C(  56) } },
    { UINT16_C(22224),
      { -INT8_C( 103),  INT8_C(  37),  INT8_C(  12), -INT8_C(  83), -INT8_C(  85), -INT8_C( 109),  INT8_C(  63),  INT8_C(  33),
         INT8_C(  90), -INT8_C(  76),  INT8_C(  83),  INT8_C(  24), -INT8_C(  33),  INT8_C(  61),  INT8_C(   6),  INT8_C( 119) },
      { -INT8_C( 110), -INT8_C(  55), -INT8_C(  74), -INT8_C(   7), -INT8_C(  21), -INT8_C( 106), -INT8_C(  94),  INT8_C(  32),
        -INT8_C(  62), -INT8_C(  89),  INT8_C(  82), -INT8_C( 109),  INT8_C( 111),  INT8_C(  34), -INT8_C(  23),  INT8_C(   9) },
      { -INT8_C( 103),  INT8_C(  37),  INT8_C(  12), -INT8_C(  83), -INT8_C(  21), -INT8_C( 109), -INT8_C(  94),  INT8_C(  32),
         INT8_C(  90), -INT8_C(  89),  INT8_C(  82),  INT8_C(  24),  INT8_C( 111),  INT8_C(  61), -INT8_C(  23),  INT8_C( 119) } },
    { UINT16_C(62792),
      { -INT8_C(  74), -INT8_C(  13), -INT8_C( 119), -INT8_C(  11),  INT8_C(  20), -INT8_C(  29), -INT8_C(  86),  INT8_C( 103),
        -INT8_C(   4), -INT8_C( 119), -INT8_C(  91),  INT8_C(   2),  INT8_C(   0),  INT8_C(  55), -INT8_C(  53), -INT8_C(  73) },
      {  INT8_C(  48), -INT8_C(  74),  INT8_C(  77), -INT8_C(  46), -INT8_C(  41),  INT8_C(  15),  INT8_C( 121),  INT8_C(  41),
        -INT8_C(  94), -INT8_C(  23),  INT8_C(  75), -INT8_C( 116), -INT8_C(  14), -INT8_C( 109), -INT8_C( 127), -INT8_C(  88) },
      { -INT8_C(  74), -INT8_C(  13), -INT8_C( 119), -INT8_C(  46),  INT8_C(  20), -INT8_C(  29),  INT8_C( 121),  INT8_C( 103),
        -INT8_C(  94), -INT8_C( 119),  INT8_C(  75),  INT8_C(   2), -INT8_C(  14), -INT8_C( 109), -INT8_C( 127), -INT8_C(  88) } },
    { UINT16_C( 2694),
      { -INT8_C(  99), -INT8_C( 102), -INT8_C(  18),  INT8_C(  71),  INT8_C(   2), -INT8_C(  22), -INT8_C(  47), -INT8_C(  89),
        -INT8_C(  20), -INT8_C(  47), -INT8_C(  34), -INT8_C(  72), -INT8_C( 120),  INT8_C(  15),  INT8_C( 110), -INT8_C(  43) },
      { -INT8_C(  31),  INT8_C(  69), -INT8_C(  27),  INT8_C(  91),  INT8_C( 110), -INT8_C( 121),  INT8_C(  68), -INT8_C(  70),
         INT8_C(  19),  INT8_C(  54),  INT8_C(  77), -INT8_C( 107), -INT8_C(  34), -INT8_C(  44), -INT8_C(  97),  INT8_C( 123) },
      { -INT8_C(  99),  INT8_C(  69), -INT8_C(  27),  INT8_C(  71),  INT8_C(   2), -INT8_C(  22), -INT8_C(  47), -INT8_C(  70),
        -INT8_C(  20),  INT8_C(  54), -INT8_C(  34), -INT8_C( 107), -INT8_C( 120),  INT8_C(  15),  INT8_C( 110), -INT8_C(  43) } },
    { UINT16_C(36206),
      { -INT8_C(  61),  INT8_C( 112),  INT8_C( 119), -INT8_C( 108),  INT8_C(  23),  INT8_C( 100),  INT8_C( 101), -INT8_C(  10),
         INT8_C(  28), -INT8_C(  18),  INT8_C(   5), -INT8_C( 118), -INT8_C(  61), -INT8_C(  26), -INT8_C(  48), -INT8_C(  88) },
      {  INT8_C(  65),  INT8_C(  62),  INT8_C(  48), -INT8_C( 123), -INT8_C(   8),  INT8_C(  67), -INT8_C(  69),  INT8_C(  70),
        -INT8_C(  40), -INT8_C( 103),  INT8_C(  26),  INT8_C( 120),  INT8_C(  21), -INT8_C( 120),  INT8_C(   5), -INT8_C(  40) },
      { -INT8_C(  61),  INT8_C(  62),  INT8_C(  48), -INT8_C( 123),  INT8_C(  23),  INT8_C(  67), -INT8_C(  69), -INT8_C(  10),
        -INT8_C(  40), -INT8_C(  18),  INT8_C(  26),  INT8_C( 120), -INT8_C(  61), -INT8_C(  26), -INT8_C(  48), -INT8_C(  40) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask_blend_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_mask_blend_epi8(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_blend_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(249),
      {  INT16_C( 27773), -INT16_C(  7920),  INT16_C(  1745), -INT16_C( 16387), -INT16_C( 30965), -INT16_C(  3453),  INT16_C( 11095), -INT16_C( 27085) },
      { -INT16_C( 18085), -INT16_C( 24690), -INT16_C( 11148),  INT16_C(  3703), -INT16_C(  4114),  INT16_C( 30499), -INT16_C(  1035),  INT16_C( 29296) },
      { -INT16_C( 18085), -INT16_C(  7920),  INT16_C(  1745),  INT16_C(  3703), -INT16_C(  4114),  INT16_C( 30499), -INT16_C(  1035),  INT16_C( 29296) } },
    { UINT8_C(103),
      {  INT16_C( 21376), -INT16_C( 30920), -INT16_C(  1968), -INT16_C( 10350), -INT16_C( 31621), -INT16_C( 22993), -INT16_C( 14920),  INT16_C( 28930) },
      { -INT16_C( 24237),  INT16_C( 10469), -INT16_C(  3304),  INT16_C(  2070), -INT16_C( 29418),  INT16_C(  4605),  INT16_C( 28669),  INT16_C( 32376) },
      { -INT16_C( 24237),  INT16_C( 10469), -INT16_C(  3304), -INT16_C( 10350), -INT16_C( 31621),  INT16_C(  4605),  INT16_C( 28669),  INT16_C( 28930) } },
    { UINT8_C(194),
      {  INT16_C(  1457), -INT16_C( 22254), -INT16_C(  5737),  INT16_C(  7204), -INT16_C( 13800), -INT16_C(  8748),  INT16_C( 17868),  INT16_C( 27953) },
      {  INT16_C( 22826),  INT16_C(  7814), -INT16_C( 29073), -INT16_C(   716),  INT16_C( 18059), -INT16_C(  1286),  INT16_C( 30910),  INT16_C( 28604) },
      {  INT16_C(  1457),  INT16_C(  7814), -INT16_C(  5737),  INT16_C(  7204), -INT16_C( 13800), -INT16_C(  8748),  INT16_C( 30910),  INT16_C( 28604) } },
    { UINT8_C(125),
      {  INT16_C(  6350), -INT16_C( 18667),  INT16_C( 12604),  INT16_C(  2000), -INT16_C( 21243),  INT16_C( 19155),  INT16_C( 16862),  INT16_C( 14196) },
      { -INT16_C( 27961),  INT16_C( 21927), -INT16_C( 23353),  INT16_C(  3552), -INT16_C(  9570),  INT16_C(  6091),  INT16_C( 15254),  INT16_C( 25748) },
      { -INT16_C( 27961), -INT16_C( 18667), -INT16_C( 23353),  INT16_C(  3552), -INT16_C(  9570),  INT16_C(  6091),  INT16_C( 15254),  INT16_C( 14196) } },
    { UINT8_C( 83),
      {  INT16_C(  7081), -INT16_C(  9584), -INT16_C( 26645), -INT16_C( 26145),  INT16_C( 10602), -INT16_C( 21641), -INT16_C( 20578),  INT16_C( 12402) },
      { -INT16_C( 14506), -INT16_C(  1289),  INT16_C(  1191), -INT16_C( 32360), -INT16_C( 20528),  INT16_C(  2839),  INT16_C( 31556), -INT16_C(  4770) },
      { -INT16_C( 14506), -INT16_C(  1289), -INT16_C( 26645), -INT16_C( 26145), -INT16_C( 20528), -INT16_C( 21641),  INT16_C( 31556),  INT16_C( 12402) } },
    { UINT8_C(151),
      { -INT16_C( 14098), -INT16_C( 31358),  INT16_C(  7079), -INT16_C( 11792), -INT16_C( 25709),  INT16_C( 17007), -INT16_C( 24818), -INT16_C( 10856) },
      { -INT16_C( 28009), -INT16_C( 25731), -INT16_C(   470), -INT16_C(  9621),  INT16_C( 30230), -INT16_C( 28386),  INT16_C(  3029), -INT16_C( 15576) },
      { -INT16_C( 28009), -INT16_C( 25731), -INT16_C(   470), -INT16_C( 11792),  INT16_C( 30230),  INT16_C( 17007), -INT16_C( 24818), -INT16_C( 15576) } },
    { UINT8_C(211),
      {  INT16_C( 18859), -INT16_C( 14725),  INT16_C( 19513), -INT16_C( 11175), -INT16_C( 25669),  INT16_C( 23266), -INT16_C( 18381), -INT16_C( 14863) },
      { -INT16_C( 29387),  INT16_C( 13296), -INT16_C( 13576),  INT16_C( 28489), -INT16_C(  9240), -INT16_C(  3260),  INT16_C(  1795), -INT16_C( 20793) },
      { -INT16_C( 29387),  INT16_C( 13296),  INT16_C( 19513), -INT16_C( 11175), -INT16_C(  9240),  INT16_C( 23266),  INT16_C(  1795), -INT16_C( 20793) } },
    { UINT8_C( 80),
      {  INT16_C( 30018), -INT16_C( 29047),  INT16_C( 24270),  INT16_C( 27209), -INT16_C( 23744), -INT16_C(  1891),  INT16_C( 25493),  INT16_C(  8749) },
      {  INT16_C( 24915),  INT16_C(  7450), -INT16_C( 30294), -INT16_C( 31483), -INT16_C(  1843), -INT16_C( 10871),  INT16_C( 14271),  INT16_C(   293) },
      {  INT16_C( 30018), -INT16_C( 29047),  INT16_C( 24270),  INT16_C( 27209), -INT16_C(  1843), -INT16_C(  1891),  INT16_C( 14271),  INT16_C(  8749) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask_blend_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask_blend_epi16(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_blend_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 50),
      { -INT32_C(  1370076836), -INT32_C(   960805400),  INT32_C(  2002808766),  INT32_C(    17942020) },
      {  INT32_C(   955999198),  INT32_C(   934509133),  INT32_C(   143229169), -INT32_C(  1606769852) },
      { -INT32_C(  1370076836),  INT32_C(   934509133),  INT32_C(  2002808766),  INT32_C(    17942020) } },
    { UINT8_C(236),
      { -INT32_C(   690729328),  INT32_C(  2023004681), -INT32_C(  1048835077),  INT32_C(  2141158684) },
      { -INT32_C(   221456520),  INT32_C(   182649994),  INT32_C(   810544013), -INT32_C(  1239617754) },
      { -INT32_C(   690729328),  INT32_C(  2023004681),  INT32_C(   810544013), -INT32_C(  1239617754) } },
    { UINT8_C( 62),
      { -INT32_C(  1958245135),  INT32_C(   730251296), -INT32_C(  1169733828), -INT32_C(  1120745498) },
      { -INT32_C(  1756945005), -INT32_C(   198880760), -INT32_C(  1877322335),  INT32_C(  1674498162) },
      { -INT32_C(  1958245135), -INT32_C(   198880760), -INT32_C(  1877322335),  INT32_C(  1674498162) } },
    { UINT8_C( 93),
      { -INT32_C(   696390122), -INT32_C(  1139627659), -INT32_C(  1214001936),  INT32_C(   608919807) },
      { -INT32_C(    97721688),  INT32_C(  1570447367),  INT32_C(   198126394),  INT32_C(   275264250) },
      { -INT32_C(    97721688), -INT32_C(  1139627659),  INT32_C(   198126394),  INT32_C(   275264250) } },
    { UINT8_C( 32),
      { -INT32_C(  1902778651), -INT32_C(   981511432),  INT32_C(  1438922485),  INT32_C(  1694361729) },
      {  INT32_C(   896268052), -INT32_C(  1099970414), -INT32_C(   910656873), -INT32_C(   924137246) },
      { -INT32_C(  1902778651), -INT32_C(   981511432),  INT32_C(  1438922485),  INT32_C(  1694361729) } },
    { UINT8_C(174),
      { -INT32_C(   777628033),  INT32_C(   214330325),  INT32_C(   395123759),  INT32_C(   288157977) },
      {  INT32_C(   631464285),  INT32_C(  1270702544), -INT32_C(   517110247), -INT32_C(   259000976) },
      { -INT32_C(   777628033),  INT32_C(  1270702544), -INT32_C(   517110247), -INT32_C(   259000976) } },
    { UINT8_C( 76),
      { -INT32_C(  1591623370), -INT32_C(  1529795192), -INT32_C(  1396840261),  INT32_C(  1963576852) },
      { -INT32_C(   750375054),  INT32_C(  1928172012), -INT32_C(  1260138818), -INT32_C(  1811885218) },
      { -INT32_C(  1591623370), -INT32_C(  1529795192), -INT32_C(  1260138818), -INT32_C(  1811885218) } },
    { UINT8_C(148),
      {  INT32_C(  1327248673), -INT32_C(   284508154),  INT32_C(  1275311742), -INT32_C(   272729664) },
      {  INT32_C(  1356567231),  INT32_C(  1292782975),  INT32_C(    61588016), -INT32_C(   459784254) },
      {  INT32_C(  1327248673), -INT32_C(   284508154),  INT32_C(    61588016), -INT32_C(   272729664) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask_blend_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask_blend_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_blend_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(117),
      { -INT64_C(  868233490955816012), -INT64_C( 8023546470421282962) },
      { -INT64_C( 4036531465351072131),  INT64_C( 5457357344973913864) },
      { -INT64_C( 4036531465351072131), -INT64_C( 8023546470421282962) } },
    { UINT8_C(160),
      { -INT64_C(  932014553403899848), -INT64_C( 7807973341973579900) },
      {  INT64_C( 7706889779473313680),  INT64_C( 3528091987569884392) },
      { -INT64_C(  932014553403899848), -INT64_C( 7807973341973579900) } },
    { UINT8_C( 13),
      { -INT64_C( 2654392715038370860),  INT64_C( 7256720621612585124) },
      { -INT64_C( 3248439389745864028),  INT64_C(  906625645223297338) },
      { -INT64_C( 3248439389745864028),  INT64_C( 7256720621612585124) } },
    { UINT8_C(206),
      {  INT64_C( 3147046207213449556),  INT64_C( 3005454041982489093) },
      { -INT64_C( 1889098808231413676),  INT64_C( 3974191252607160157) },
      {  INT64_C( 3147046207213449556),  INT64_C( 3974191252607160157) } },
    { UINT8_C(218),
      { -INT64_C( 4725154603078434855), -INT64_C( 1452288612773823232) },
      {  INT64_C( 9016053822695368239),  INT64_C( 8761356837411911826) },
      { -INT64_C( 4725154603078434855),  INT64_C( 8761356837411911826) } },
    { UINT8_C(215),
      { -INT64_C( 3950922088230690997), -INT64_C( 1268634622804315962) },
      { -INT64_C( 4792224427882568073),  INT64_C( 2047121126703512313) },
      { -INT64_C( 4792224427882568073),  INT64_C( 2047121126703512313) } },
    { UINT8_C(181),
      {  INT64_C( 2554325437316614187),  INT64_C( 3613182180302039237) },
      { -INT64_C( 3942280737969467209),  INT64_C( 7934135569143749521) },
      { -INT64_C( 3942280737969467209),  INT64_C( 3613182180302039237) } },
    { UINT8_C(254),
      {  INT64_C( 3795291543367195164), -INT64_C( 8317177106714765247) },
      {  INT64_C(  626250131139388395),  INT64_C( 5634769709070751613) },
      {  INT64_C( 3795291543367195164),  INT64_C( 5634769709070751613) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_mask_blend_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_blend_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_blend_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C( 39),
      { SIMDE_FLOAT32_C(  -639.84), SIMDE_FLOAT32_C(   741.44), SIMDE_FLOAT32_C(   755.52), SIMDE_FLOAT32_C(  -503.25) },
      { SIMDE_FLOAT32_C(    89.71), SIMDE_FLOAT32_C(   206.49), SIMDE_FLOAT32_C(  -233.67), SIMDE_FLOAT32_C(  -362.60) },
      { SIMDE_FLOAT32_C(    89.71), SIMDE_FLOAT32_C(   206.49), SIMDE_FLOAT32_C(  -233.67), SIMDE_FLOAT32_C(  -503.25) } },
    { UINT8_C(205),
      { SIMDE_FLOAT32_C(   180.01), SIMDE_FLOAT32_C(   348.51), SIMDE_FLOAT32_C(   413.37), SIMDE_FLOAT32_C(   694.90) },
      { SIMDE_FLOAT32_C(   865.39), SIMDE_FLOAT32_C(   331.86), SIMDE_FLOAT32_C(  -871.02), SIMDE_FLOAT32_C(  -715.35) },
      { SIMDE_FLOAT32_C(   865.39), SIMDE_FLOAT32_C(   348.51), SIMDE_FLOAT32_C(  -871.02), SIMDE_FLOAT32_C(  -715.35) } },
    { UINT8_C(136),
      { SIMDE_FLOAT32_C(   381.28), SIMDE_FLOAT32_C(  -125.11), SIMDE_FLOAT32_C(  -174.63), SIMDE_FLOAT32_C(   503.75) },
      { SIMDE_FLOAT32_C(   922.00), SIMDE_FLOAT32_C(  -613.33), SIMDE_FLOAT32_C(  -404.48), SIMDE_FLOAT32_C(   984.72) },
      { SIMDE_FLOAT32_C(   381.28), SIMDE_FLOAT32_C(  -125.11), SIMDE_FLOAT32_C(  -174.63), SIMDE_FLOAT32_C(   984.72) } },
    { UINT8_C( 37),
      { SIMDE_FLOAT32_C(   562.47), SIMDE_FLOAT32_C(  -146.22), SIMDE_FLOAT32_C(   -88.35), SIMDE_FLOAT32_C(  -849.23) },
      { SIMDE_FLOAT32_C(   213.94), SIMDE_FLOAT32_C(  -346.91), SIMDE_FLOAT32_C(   906.29), SIMDE_FLOAT32_C(   710.69) },
      { SIMDE_FLOAT32_C(   213.94), SIMDE_FLOAT32_C(  -146.22), SIMDE_FLOAT32_C(   906.29), SIMDE_FLOAT32_C(  -849.23) } },
    { UINT8_C( 24),
      { SIMDE_FLOAT32_C(   112.78), SIMDE_FLOAT32_C(  -522.98), SIMDE_FLOAT32_C(  -619.80), SIMDE_FLOAT32_C(  -869.27) },
      { SIMDE_FLOAT32_C(   657.03), SIMDE_FLOAT32_C(   728.71), SIMDE_FLOAT32_C(   544.09), SIMDE_FLOAT32_C(   351.94) },
      { SIMDE_FLOAT32_C(   112.78), SIMDE_FLOAT32_C(  -522.98), SIMDE_FLOAT32_C(  -619.80), SIMDE_FLOAT32_C(   351.94) } },
    { UINT8_C(213),
      { SIMDE_FLOAT32_C(  -124.04), SIMDE_FLOAT32_C(   480.92), SIMDE_FLOAT32_C(   878.75), SIMDE_FLOAT32_C(   551.80) },
      { SIMDE_FLOAT32_C(  -137.80), SIMDE_FLOAT32_C(  -246.36), SIMDE_FLOAT32_C(  -622.83), SIMDE_FLOAT32_C(  -634.06) },
      { SIMDE_FLOAT32_C(  -137.80), SIMDE_FLOAT32_C(   480.92), SIMDE_FLOAT32_C(  -622.83), SIMDE_FLOAT32_C(   551.80) } },
    { UINT8_C(143),
      { SIMDE_FLOAT32_C(  -236.16), SIMDE_FLOAT32_C(   -38.53), SIMDE_FLOAT32_C(  -339.64), SIMDE_FLOAT32_C(  -945.28) },
      { SIMDE_FLOAT32_C(  -476.06), SIMDE_FLOAT32_C(   514.14), SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(  -325.30) },
      { SIMDE_FLOAT32_C(  -476.06), SIMDE_FLOAT32_C(   514.14), SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(  -325.30) } },
    { UINT8_C(118),
      { SIMDE_FLOAT32_C(   619.46), SIMDE_FLOAT32_C(  -419.01), SIMDE_FLOAT32_C(  -561.23), SIMDE_FLOAT32_C(   362.26) },
      { SIMDE_FLOAT32_C(   693.78), SIMDE_FLOAT32_C(   -84.21), SIMDE_FLOAT32_C(   742.46), SIMDE_FLOAT32_C(   824.50) },
      { SIMDE_FLOAT32_C(   619.46), SIMDE_FLOAT32_C(   -84.21), SIMDE_FLOAT32_C(   742.46), SIMDE_FLOAT32_C(   362.26) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_mask_blend_ps(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 r = simde_mm_mask_blend_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_blend_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C( 47),
      { SIMDE_FLOAT64_C(   471.17), SIMDE_FLOAT64_C(   368.60) },
      { SIMDE_FLOAT64_C(   924.77), SIMDE_FLOAT64_C(    65.27) },
      { SIMDE_FLOAT64_C(   924.77), SIMDE_FLOAT64_C(    65.27) } },
    { UINT8_C(112),
      { SIMDE_FLOAT64_C(   405.68), SIMDE_FLOAT64_C(   -55.98) },
      { SIMDE_FLOAT64_C(   796.35), SIMDE_FLOAT64_C(  -732.12) },
      { SIMDE_FLOAT64_C(   405.68), SIMDE_FLOAT64_C(   -55.98) } },
    { UINT8_C( 18),
      { SIMDE_FLOAT64_C(  -826.48), SIMDE_FLOAT64_C(  -366.18) },
      { SIMDE_FLOAT64_C(  -626.69), SIMDE_FLOAT64_C(   -62.63) },
      { SIMDE_FLOAT64_C(  -826.48), SIMDE_FLOAT64_C(   -62.63) } },
    { UINT8_C( 11),
      { SIMDE_FLOAT64_C(    33.67), SIMDE_FLOAT64_C(    -7.91) },
      { SIMDE_FLOAT64_C(  -880.77), SIMDE_FLOAT64_C(  -452.19) },
      { SIMDE_FLOAT64_C(  -880.77), SIMDE_FLOAT64_C(  -452.19) } },
    { UINT8_C(  2),
      { SIMDE_FLOAT64_C(  -206.07), SIMDE_FLOAT64_C(   275.89) },
      { SIMDE_FLOAT64_C(   577.92), SIMDE_FLOAT64_C(   374.93) },
      { SIMDE_FLOAT64_C(  -206.07), SIMDE_FLOAT64_C(   374.93) } },
    { UINT8_C(106),
      { SIMDE_FLOAT64_C(   -59.82), SIMDE_FLOAT64_C(    68.70) },
      { SIMDE_FLOAT64_C(  -369.54), SIMDE_FLOAT64_C(  -317.37) },
      { SIMDE_FLOAT64_C(   -59.82), SIMDE_FLOAT64_C(  -317.37) } },
    { UINT8_C( 48),
      { SIMDE_FLOAT64_C(   203.29), SIMDE_FLOAT64_C(  -846.20) },
      { SIMDE_FLOAT64_C(  -738.20), SIMDE_FLOAT64_C(   128.05) },
      { SIMDE_FLOAT64_C(   203.29), SIMDE_FLOAT64_C(  -846.20) } },
    { UINT8_C( 75),
      { SIMDE_FLOAT64_C(  -493.65), SIMDE_FLOAT64_C(  -466.26) },
      { SIMDE_FLOAT64_C(  -836.91), SIMDE_FLOAT64_C(  -697.29) },
      { SIMDE_FLOAT64_C(  -836.91), SIMDE_FLOAT64_C(  -697.29) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_mask_blend_pd(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_mask_blend_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_blend_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT16_C(13581),
      { -INT8_C( 103),  INT8_C( 106), -INT8_C(  31), -INT8_C(   9),  INT8_C(  61), -INT8_C(  60),  INT8_C(  24),  INT8_C(  51),
         INT8_C( 122),  INT8_C(  46),  INT8_C(  31), -INT8_C(  47),  INT8_C(  18),  INT8_C(  56),  INT8_C(  37), -INT8_C(   4),
         INT8_C(  97),  INT8_C( 104),  INT8_C(  26),  INT8_C(  25), -INT8_C( 127), -INT8_C(  20),  INT8_C(  67),  INT8_C(  22),
         INT8_C(  74), -INT8_C(  12), -INT8_C(  58), -INT8_C(   7),  INT8_C(  16), -INT8_C(  45),  INT8_C(  46), -INT8_C(  87) },
      {  INT8_C(  61),  INT8_C(  16), -INT8_C(  95),  INT8_C( 122), -INT8_C(  44), -INT8_C(  71), -INT8_C(  83),  INT8_C(  78),
        -INT8_C(  25), -INT8_C(  52),  INT8_C(  32), -INT8_C(   6),  INT8_C(   4),  INT8_C(  69), -INT8_C(  10),  INT8_C( 102),
        -INT8_C(  83),  INT8_C(  17),      INT8_MAX,  INT8_C(  46), -INT8_C(   3), -INT8_C(  62),  INT8_C(  68),  INT8_C(  71),
        -INT8_C(  73),  INT8_C(  10),  INT8_C(  65), -INT8_C(  57), -INT8_C(  35),  INT8_C( 111),  INT8_C( 113),  INT8_C(  26) },
      {  INT8_C(  61),  INT8_C( 106), -INT8_C(  95),  INT8_C( 122),  INT8_C(  61), -INT8_C(  60),  INT8_C(  24),  INT8_C(  51),
        -INT8_C(  25),  INT8_C(  46),  INT8_C(  32), -INT8_C(  47),  INT8_C(   4),  INT8_C(  69),  INT8_C(  37), -INT8_C(   4),
         INT8_C(  97),  INT8_C( 104),  INT8_C(  26),  INT8_C(  25), -INT8_C( 127), -INT8_C(  20),  INT8_C(  67),  INT8_C(  22),
         INT8_C(  74), -INT8_C(  12), -INT8_C(  58), -INT8_C(   7),  INT8_C(  16), -INT8_C(  45),  INT8_C(  46), -INT8_C(  87) } },
    { UINT16_C( 4735),
      { -INT8_C( 107),  INT8_C(  83), -INT8_C(  53),  INT8_C(  66), -INT8_C(  94), -INT8_C(  77),  INT8_C(  15), -INT8_C(  62),
        -INT8_C(  83),  INT8_C(  19),  INT8_C(   7), -INT8_C(  93),  INT8_C( 121), -INT8_C(  76), -INT8_C(  76), -INT8_C(   8),
        -INT8_C(  30), -INT8_C(  79), -INT8_C(  69),  INT8_C(  38), -INT8_C(   7),  INT8_C( 114),  INT8_C(  48),  INT8_C(  58),
         INT8_C(  57),  INT8_C(  13), -INT8_C(  87), -INT8_C(  86),  INT8_C(  39),  INT8_C(  41), -INT8_C(  68), -INT8_C(  68) },
      {  INT8_C( 124), -INT8_C( 120), -INT8_C(   1),  INT8_C(  30),  INT8_C(  59),  INT8_C(  14), -INT8_C(  32), -INT8_C(  24),
         INT8_C(  33), -INT8_C(  25), -INT8_C( 117), -INT8_C( 101), -INT8_C( 101),  INT8_C(  64), -INT8_C( 109),  INT8_C( 125),
        -INT8_C(  15),  INT8_C(  78), -INT8_C(  93), -INT8_C(  22), -INT8_C(  64), -INT8_C(  45),  INT8_C(  36), -INT8_C(   6),
        -INT8_C(  32), -INT8_C(  50), -INT8_C(  92),  INT8_C(   8), -INT8_C(   9),  INT8_C(  97), -INT8_C(  60),  INT8_C( 115) },
      {  INT8_C( 124), -INT8_C( 120), -INT8_C(   1),  INT8_C(  30),  INT8_C(  59),  INT8_C(  14), -INT8_C(  32), -INT8_C(  62),
        -INT8_C(  83), -INT8_C(  25),  INT8_C(   7), -INT8_C(  93), -INT8_C( 101), -INT8_C(  76), -INT8_C(  76), -INT8_C(   8),
        -INT8_C(  30), -INT8_C(  79), -INT8_C(  69),  INT8_C(  38), -INT8_C(   7),  INT8_C( 114),  INT8_C(  48),  INT8_C(  58),
         INT8_C(  57),  INT8_C(  13), -INT8_C(  87), -INT8_C(  86),  INT8_C(  39),  INT8_C(  41), -INT8_C(  68), -INT8_C(  68) } },
    { UINT16_C(50153),
      { -INT8_C( 110),  INT8_C(  36), -INT8_C(  47),  INT8_C( 114),  INT8_C(  12), -INT8_C(  13),  INT8_C(  90), -INT8_C( 105),
        -INT8_C( 114), -INT8_C(  11), -INT8_C(  41),  INT8_C(  33),  INT8_C( 115), -INT8_C(  55),  INT8_C( 112),  INT8_C(  22),
        -INT8_C(  77),  INT8_C(  48), -INT8_C(  22), -INT8_C(  40),  INT8_C(  42), -INT8_C(  54), -INT8_C(  90), -INT8_C(  49),
        -INT8_C(  46), -INT8_C(  99),  INT8_C(  48), -INT8_C( 105),  INT8_C(  16),  INT8_C(  25),  INT8_C(  90), -INT8_C(  94) },
      {  INT8_C(  61),  INT8_C(  44),  INT8_C(  21),  INT8_C(  73),  INT8_C(  31),  INT8_C( 111), -INT8_C(  32), -INT8_C(  83),
         INT8_C( 100), -INT8_C(  72), -INT8_C(  50), -INT8_C(  41), -INT8_C( 127),  INT8_C(  62), -INT8_C(  18),  INT8_C(  52),
         INT8_C( 111), -INT8_C(  40),  INT8_C(  12), -INT8_C( 103), -INT8_C(  94), -INT8_C(  78),  INT8_C( 104),  INT8_C( 117),
         INT8_C(  79), -INT8_C( 104),  INT8_C(  12),  INT8_C(  96), -INT8_C(  79),  INT8_C( 102),  INT8_C(   2), -INT8_C(  18) },
      {  INT8_C(  61),  INT8_C(  36), -INT8_C(  47),  INT8_C(  73),  INT8_C(  12),  INT8_C( 111), -INT8_C(  32), -INT8_C(  83),
         INT8_C( 100), -INT8_C(  72), -INT8_C(  41),  INT8_C(  33),  INT8_C( 115), -INT8_C(  55), -INT8_C(  18),  INT8_C(  52),
        -INT8_C(  77),  INT8_C(  48), -INT8_C(  22), -INT8_C(  40),  INT8_C(  42), -INT8_C(  54), -INT8_C(  90), -INT8_C(  49),
        -INT8_C(  46), -INT8_C(  99),  INT8_C(  48), -INT8_C( 105),  INT8_C(  16),  INT8_C(  25),  INT8_C(  90), -INT8_C(  94) } },
    { UINT16_C( 6034),
      {  INT8_C(  55), -INT8_C(  79), -INT8_C( 122),  INT8_C(  24),  INT8_C(  94), -INT8_C(  21), -INT8_C(  48),  INT8_C(  45),
        -INT8_C(  62),  INT8_C(  81),  INT8_C( 107), -INT8_C(  80), -INT8_C( 123), -INT8_C(  38), -INT8_C( 120), -INT8_C( 110),
         INT8_C( 116),  INT8_C(  43),  INT8_C(  68), -INT8_C(  36), -INT8_C(  96), -INT8_C( 108),  INT8_C( 117), -INT8_C(  84),
        -INT8_C(  12),  INT8_C(  38),  INT8_C(  18), -INT8_C(  10),  INT8_C(  21), -INT8_C(  91),  INT8_C(  14),  INT8_C(  76) },
      {  INT8_C(  86), -INT8_C( 108),  INT8_C( 100), -INT8_C(  75),      INT8_MAX,  INT8_C(  52), -INT8_C(  30),  INT8_C(  66),
        -INT8_C( 123),  INT8_C(  77), -INT8_C(  14),  INT8_C(  11),  INT8_C(  40),  INT8_C( 123), -INT8_C(  99), -INT8_C( 100),
        -INT8_C(  90), -INT8_C(  31),  INT8_C( 120),  INT8_C(  70),  INT8_C( 117), -INT8_C(  19), -INT8_C(  14),  INT8_C( 105),
         INT8_C(  20),  INT8_C(   4),  INT8_C(  96),  INT8_C(  41), -INT8_C(  87),  INT8_C( 110),  INT8_C( 117),  INT8_C(   0) },
      {  INT8_C(  55), -INT8_C( 108), -INT8_C( 122),  INT8_C(  24),      INT8_MAX, -INT8_C(  21), -INT8_C(  48),  INT8_C(  66),
        -INT8_C( 123),  INT8_C(  77), -INT8_C(  14), -INT8_C(  80),  INT8_C(  40), -INT8_C(  38), -INT8_C( 120), -INT8_C( 110),
         INT8_C( 116),  INT8_C(  43),  INT8_C(  68), -INT8_C(  36), -INT8_C(  96), -INT8_C( 108),  INT8_C( 117), -INT8_C(  84),
        -INT8_C(  12),  INT8_C(  38),  INT8_C(  18), -INT8_C(  10),  INT8_C(  21), -INT8_C(  91),  INT8_C(  14),  INT8_C(  76) } },
    { UINT16_C(55810),
      { -INT8_C(  75), -INT8_C( 126),  INT8_C(  14), -INT8_C( 105), -INT8_C(  60), -INT8_C( 108), -INT8_C(  28), -INT8_C(  74),
        -INT8_C(  97),  INT8_C(  12),  INT8_C(  49),  INT8_C(  60), -INT8_C(  88), -INT8_C(  41),  INT8_C(  29),  INT8_C(  33),
         INT8_C(  29), -INT8_C( 109),  INT8_C(  14),  INT8_C(  15), -INT8_C(   4),  INT8_C(  34),  INT8_C(  20),  INT8_C(  92),
         INT8_C(  75), -INT8_C(  67), -INT8_C(  54), -INT8_C(  63), -INT8_C(  67), -INT8_C(  51), -INT8_C( 101),  INT8_C( 114) },
      {  INT8_C(  79), -INT8_C(  87),  INT8_C(   9),  INT8_C(  19),  INT8_C(  61), -INT8_C(  18), -INT8_C(  55), -INT8_C(  36),
        -INT8_C(   6), -INT8_C(   5),  INT8_C(  24), -INT8_C(  93), -INT8_C(  46),  INT8_C(  54), -INT8_C(  60), -INT8_C(  16),
        -INT8_C(  55), -INT8_C(  46), -INT8_C(   1), -INT8_C(  59), -INT8_C(  11),  INT8_C(  19),  INT8_C(  34),  INT8_C(  64),
        -INT8_C(  47), -INT8_C(  20),  INT8_C(   1), -INT8_C( 114), -INT8_C(  71), -INT8_C( 100),  INT8_C(   1),  INT8_C(   8) },
      { -INT8_C(  75), -INT8_C(  87),  INT8_C(  14), -INT8_C( 105), -INT8_C(  60), -INT8_C( 108), -INT8_C(  28), -INT8_C(  74),
        -INT8_C(  97), -INT8_C(   5),  INT8_C(  49), -INT8_C(  93), -INT8_C(  46), -INT8_C(  41), -INT8_C(  60), -INT8_C(  16),
         INT8_C(  29), -INT8_C( 109),  INT8_C(  14),  INT8_C(  15), -INT8_C(   4),  INT8_C(  34),  INT8_C(  20),  INT8_C(  92),
         INT8_C(  75), -INT8_C(  67), -INT8_C(  54), -INT8_C(  63), -INT8_C(  67), -INT8_C(  51), -INT8_C( 101),  INT8_C( 114) } },
    { UINT16_C( 2630),
      {  INT8_C(  27), -INT8_C( 125), -INT8_C(   8), -INT8_C(  27),  INT8_C(  96), -INT8_C(  13), -INT8_C(  32),  INT8_C( 120),
        -INT8_C( 106), -INT8_C(  78), -INT8_C(  82),  INT8_C(  90), -INT8_C(  94),  INT8_C( 119),  INT8_C(  44), -INT8_C(  94),
         INT8_C(  61),  INT8_C(  33), -INT8_C(  75),  INT8_C(  95),  INT8_C(  98), -INT8_C( 122),  INT8_C(  75),  INT8_C(  99),
         INT8_C(  21),  INT8_C(   5),  INT8_C(   0),  INT8_C(  22),  INT8_C(  13),  INT8_C(  70),  INT8_C(  32),  INT8_C(  41) },
      { -INT8_C(  55),  INT8_C(  25),  INT8_C(  14),  INT8_C(  41),  INT8_C(  12), -INT8_C(  18), -INT8_C(  94), -INT8_C(  94),
        -INT8_C(  96),  INT8_C(  80), -INT8_C(   4),  INT8_C(  67), -INT8_C(  56),  INT8_C(  40), -INT8_C(  27),  INT8_C(   5),
         INT8_C(  74), -INT8_C( 102),  INT8_C( 100), -INT8_C(  84),  INT8_C(  33), -INT8_C(  81),  INT8_C(  15),  INT8_C(  54),
        -INT8_C(  76),  INT8_C(  15),  INT8_C(  76), -INT8_C(  62),  INT8_C(  85),  INT8_C( 108), -INT8_C(  21),  INT8_C(  31) },
      {  INT8_C(  27),  INT8_C(  25),  INT8_C(  14), -INT8_C(  27),  INT8_C(  96), -INT8_C(  13), -INT8_C(  94),  INT8_C( 120),
        -INT8_C( 106),  INT8_C(  80), -INT8_C(  82),  INT8_C(  67), -INT8_C(  94),  INT8_C( 119),  INT8_C(  44), -INT8_C(  94),
         INT8_C(  61),  INT8_C(  33), -INT8_C(  75),  INT8_C(  95),  INT8_C(  98), -INT8_C( 122),  INT8_C(  75),  INT8_C(  99),
         INT8_C(  21),  INT8_C(   5),  INT8_C(   0),  INT8_C(  22),  INT8_C(  13),  INT8_C(  70),  INT8_C(  32),  INT8_C(  41) } },
    { UINT16_C(63877),
      {  INT8_C(  72), -INT8_C( 111), -INT8_C(  25), -INT8_C(  22),  INT8_C(  51), -INT8_C( 121),  INT8_C(  59),  INT8_C(  47),
        -INT8_C(  54),  INT8_C(   3),  INT8_C(  88), -INT8_C(  81),  INT8_C(   8), -INT8_C(  94),  INT8_C(  74),  INT8_C( 108),
         INT8_C(  78),  INT8_C( 107),  INT8_C(  27),  INT8_C(  93), -INT8_C(  95), -INT8_C(  48),  INT8_C( 109), -INT8_C(  19),
        -INT8_C( 110), -INT8_C(  62),  INT8_C(  89),  INT8_C( 125), -INT8_C(  31), -INT8_C(  33),  INT8_C( 118),  INT8_C(  42) },
      {  INT8_C( 112),  INT8_C(  93),  INT8_C(  20), -INT8_C(  92), -INT8_C(  28),  INT8_C(  79), -INT8_C(  45), -INT8_C(  81),
         INT8_C(  82),  INT8_C(  43),  INT8_C(  94),  INT8_C(  90), -INT8_C(  51), -INT8_C(  88), -INT8_C(  58),  INT8_C(  27),
         INT8_C(  19), -INT8_C(  30),  INT8_C( 121), -INT8_C(  76), -INT8_C(  78), -INT8_C(  26), -INT8_C(  95),  INT8_C(  68),
        -INT8_C(  88), -INT8_C(   5), -INT8_C(  63), -INT8_C( 118), -INT8_C(  38),  INT8_C(  55), -INT8_C(  76),  INT8_C(  74) },
      {  INT8_C( 112), -INT8_C( 111),  INT8_C(  20), -INT8_C(  22),  INT8_C(  51), -INT8_C( 121),  INT8_C(  59), -INT8_C(  81),
         INT8_C(  82),  INT8_C(   3),  INT8_C(  88),  INT8_C(  90), -INT8_C(  51), -INT8_C(  88), -INT8_C(  58),  INT8_C(  27),
         INT8_C(  78),  INT8_C( 107),  INT8_C(  27),  INT8_C(  93), -INT8_C(  95), -INT8_C(  48),  INT8_C( 109), -INT8_C(  19),
        -INT8_C( 110), -INT8_C(  62),  INT8_C(  89),  INT8_C( 125), -INT8_C(  31), -INT8_C(  33),  INT8_C( 118),  INT8_C(  42) } },
    { UINT16_C(51348),
      { -INT8_C(  18),  INT8_C( 120),  INT8_C(  24), -INT8_C(  62),  INT8_C(  39),  INT8_C( 106), -INT8_C(  19), -INT8_C( 122),
        -INT8_C(  59), -INT8_C(  69),  INT8_C(  46), -INT8_C( 117), -INT8_C(  42),  INT8_C(  66),  INT8_C( 109),  INT8_C(  79),
        -INT8_C(  10),  INT8_C(  31),  INT8_C(  53), -INT8_C( 104),  INT8_C(  99), -INT8_C(  34), -INT8_C( 109),  INT8_C(  36),
         INT8_C( 104),  INT8_C( 109),  INT8_C(  91),  INT8_C(  28), -INT8_C(  73), -INT8_C(  17), -INT8_C(  28), -INT8_C(  90) },
      {  INT8_C( 104), -INT8_C(   4),  INT8_C( 104), -INT8_C( 113),  INT8_C( 103),  INT8_C(  85),  INT8_C(  21),  INT8_C(  44),
         INT8_C(  16),  INT8_C(  68), -INT8_C(  73), -INT8_C(  25), -INT8_C( 122),  INT8_C(  37),  INT8_C(  54),  INT8_C( 124),
         INT8_C(  68),  INT8_C( 108),  INT8_C(  20), -INT8_C(  88),  INT8_C(  74), -INT8_C(  89), -INT8_C(  52), -INT8_C(  78),
         INT8_C(  20),  INT8_C(  40), -INT8_C(  50), -INT8_C(  52),  INT8_C(  23), -INT8_C(  78),  INT8_C( 114),      INT8_MAX },
      { -INT8_C(  18),  INT8_C( 120),  INT8_C( 104), -INT8_C(  62),  INT8_C( 103),  INT8_C( 106), -INT8_C(  19),  INT8_C(  44),
        -INT8_C(  59), -INT8_C(  69),  INT8_C(  46), -INT8_C(  25), -INT8_C(  42),  INT8_C(  66),  INT8_C(  54),  INT8_C( 124),
        -INT8_C(  10),  INT8_C(  31),  INT8_C(  53), -INT8_C( 104),  INT8_C(  99), -INT8_C(  34), -INT8_C( 109),  INT8_C(  36),
         INT8_C( 104),  INT8_C( 109),  INT8_C(  91),  INT8_C(  28), -INT8_C(  73), -INT8_C(  17), -INT8_C(  28), -INT8_C(  90) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_blend_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_mask_blend_epi8(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_blend_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(24266),
      { -INT16_C( 14738), -INT16_C( 25037),  INT16_C(  7320),  INT16_C(  5650),  INT16_C( 31105),  INT16_C( 30204),  INT16_C(  6032),  INT16_C(  1329),
         INT16_C( 15938),  INT16_C( 20922), -INT16_C( 27944), -INT16_C( 14965),  INT16_C(  4067),  INT16_C(  8408), -INT16_C( 23954), -INT16_C(  9090) },
      { -INT16_C( 19864),  INT16_C(   122), -INT16_C( 29234),  INT16_C( 20247),  INT16_C(  4870), -INT16_C( 26939), -INT16_C(  2518),  INT16_C( 27803),
         INT16_C( 21812),  INT16_C(  3261),  INT16_C( 18920), -INT16_C( 13359), -INT16_C( 21928), -INT16_C( 14613),  INT16_C( 26956), -INT16_C( 19038) },
      { -INT16_C( 14738),  INT16_C(   122),  INT16_C(  7320),  INT16_C( 20247),  INT16_C( 31105),  INT16_C( 30204), -INT16_C(  2518),  INT16_C( 27803),
         INT16_C( 15938),  INT16_C(  3261),  INT16_C( 18920), -INT16_C( 13359), -INT16_C( 21928),  INT16_C(  8408),  INT16_C( 26956), -INT16_C(  9090) } },
    { UINT16_C( 7451),
      { -INT16_C(  5707), -INT16_C( 13142), -INT16_C( 20423), -INT16_C(   289),  INT16_C(  2630), -INT16_C(  7692),  INT16_C( 10614),  INT16_C( 13367),
         INT16_C(  7989),  INT16_C(  1917), -INT16_C( 10774), -INT16_C( 10831), -INT16_C(   613),  INT16_C( 15678),  INT16_C( 23218),  INT16_C( 26714) },
      {  INT16_C(  1091),  INT16_C( 31796),  INT16_C(  5300), -INT16_C(  1414),  INT16_C( 28446), -INT16_C( 27428),  INT16_C(  5016), -INT16_C( 12856),
         INT16_C( 17714),  INT16_C(  7380), -INT16_C( 31462), -INT16_C( 18959),  INT16_C( 12163),  INT16_C( 13811),  INT16_C( 19849), -INT16_C( 12899) },
      {  INT16_C(  1091),  INT16_C( 31796), -INT16_C( 20423), -INT16_C(  1414),  INT16_C( 28446), -INT16_C(  7692),  INT16_C( 10614),  INT16_C( 13367),
         INT16_C( 17714),  INT16_C(  1917), -INT16_C( 31462), -INT16_C( 18959),  INT16_C( 12163),  INT16_C( 15678),  INT16_C( 23218),  INT16_C( 26714) } },
    { UINT16_C(53842),
      {  INT16_C(  1609), -INT16_C( 15130),  INT16_C(  1025), -INT16_C(  8909), -INT16_C( 13416),  INT16_C( 25072),  INT16_C(  8856),  INT16_C( 28070),
        -INT16_C( 16066),  INT16_C( 12274),  INT16_C( 30070),  INT16_C( 26974), -INT16_C(  5973),  INT16_C( 18615),  INT16_C(  2485), -INT16_C(   486) },
      {  INT16_C(    15),  INT16_C(  4290), -INT16_C(  2812), -INT16_C( 25107), -INT16_C(  8768),  INT16_C( 23038), -INT16_C( 23297),  INT16_C( 15814),
        -INT16_C( 18331), -INT16_C(  9108), -INT16_C( 13522), -INT16_C(  9915), -INT16_C(   845),  INT16_C( 26657),  INT16_C( 15365),  INT16_C(  5478) },
      {  INT16_C(  1609),  INT16_C(  4290),  INT16_C(  1025), -INT16_C(  8909), -INT16_C(  8768),  INT16_C( 25072), -INT16_C( 23297),  INT16_C( 28070),
        -INT16_C( 16066), -INT16_C(  9108),  INT16_C( 30070),  INT16_C( 26974), -INT16_C(   845),  INT16_C( 18615),  INT16_C( 15365),  INT16_C(  5478) } },
    { UINT16_C(10556),
      {  INT16_C( 16677),  INT16_C(  4894), -INT16_C(  8226), -INT16_C(  8976), -INT16_C(  4040), -INT16_C(   384), -INT16_C(  6611), -INT16_C( 25930),
        -INT16_C(  6974),  INT16_C(  1893),  INT16_C(  6333), -INT16_C(  8444),  INT16_C(  2432), -INT16_C(  6629),  INT16_C( 22302),  INT16_C( 17423) },
      {  INT16_C( 11928),  INT16_C( 30295),  INT16_C( 18189),  INT16_C( 17746), -INT16_C( 11465),  INT16_C( 25923), -INT16_C(  1607),  INT16_C( 31743),
         INT16_C( 25822), -INT16_C( 25726), -INT16_C( 31108), -INT16_C(   902), -INT16_C( 27248), -INT16_C( 20766), -INT16_C(  3347), -INT16_C( 31246) },
      {  INT16_C( 16677),  INT16_C(  4894),  INT16_C( 18189),  INT16_C( 17746), -INT16_C( 11465),  INT16_C( 25923), -INT16_C(  6611), -INT16_C( 25930),
         INT16_C( 25822),  INT16_C(  1893),  INT16_C(  6333), -INT16_C(   902),  INT16_C(  2432), -INT16_C( 20766),  INT16_C( 22302),  INT16_C( 17423) } },
    { UINT16_C(18720),
      {  INT16_C( 11772),  INT16_C( 20113), -INT16_C( 14222), -INT16_C( 19167), -INT16_C(  9683),  INT16_C( 11438), -INT16_C( 29611), -INT16_C( 10096),
         INT16_C(  3112), -INT16_C( 23970), -INT16_C(  4600), -INT16_C(  5320),  INT16_C(  9629), -INT16_C( 28707), -INT16_C(   598), -INT16_C( 22823) },
      {  INT16_C( 27178), -INT16_C( 25355),  INT16_C(  5682),  INT16_C( 24657), -INT16_C(    15),  INT16_C( 18060),  INT16_C(  7564), -INT16_C( 19426),
         INT16_C( 32041),  INT16_C( 12886), -INT16_C( 29077),  INT16_C(  2077), -INT16_C(  1357),  INT16_C( 24216),  INT16_C( 29175),  INT16_C(  8452) },
      {  INT16_C( 11772),  INT16_C( 20113), -INT16_C( 14222), -INT16_C( 19167), -INT16_C(  9683),  INT16_C( 18060), -INT16_C( 29611), -INT16_C( 10096),
         INT16_C( 32041), -INT16_C( 23970), -INT16_C(  4600),  INT16_C(  2077),  INT16_C(  9629), -INT16_C( 28707),  INT16_C( 29175), -INT16_C( 22823) } },
    { UINT16_C(63963),
      {  INT16_C(  3517),  INT16_C(  3600),  INT16_C(   365), -INT16_C(  1523), -INT16_C( 26297),  INT16_C( 26135),  INT16_C( 16461), -INT16_C( 23325),
         INT16_C( 20082), -INT16_C( 28878), -INT16_C(  6569), -INT16_C(  4215), -INT16_C( 32700),  INT16_C( 18528),  INT16_C( 15265),  INT16_C( 24130) },
      {  INT16_C( 21064), -INT16_C( 18836),  INT16_C( 31315), -INT16_C( 25936), -INT16_C( 14573),  INT16_C( 24832), -INT16_C(  7417),  INT16_C( 31237),
         INT16_C( 14130), -INT16_C( 30455), -INT16_C( 27875),  INT16_C( 24952), -INT16_C( 10221), -INT16_C( 19030), -INT16_C(  5101),  INT16_C( 23315) },
      {  INT16_C( 21064), -INT16_C( 18836),  INT16_C(   365), -INT16_C( 25936), -INT16_C( 14573),  INT16_C( 26135), -INT16_C(  7417),  INT16_C( 31237),
         INT16_C( 14130), -INT16_C( 28878), -INT16_C(  6569),  INT16_C( 24952), -INT16_C( 10221), -INT16_C( 19030), -INT16_C(  5101),  INT16_C( 23315) } },
    { UINT16_C(32830),
      { -INT16_C( 28399), -INT16_C( 15878),  INT16_C(  3371),  INT16_C( 11400), -INT16_C( 28562),  INT16_C( 29455),  INT16_C( 16650),  INT16_C(  5035),
        -INT16_C( 14134),  INT16_C( 17062), -INT16_C( 17878), -INT16_C( 11238),  INT16_C( 11631), -INT16_C( 32064), -INT16_C(   375), -INT16_C( 26110) },
      { -INT16_C(   881), -INT16_C( 17828), -INT16_C(  7158),  INT16_C( 30950), -INT16_C(  2444),  INT16_C( 32492), -INT16_C( 26825),  INT16_C(   658),
         INT16_C( 14431), -INT16_C( 30396),  INT16_C( 24562),  INT16_C( 24925),  INT16_C(  7564),  INT16_C(  5604), -INT16_C(  6629), -INT16_C( 21840) },
      { -INT16_C( 28399), -INT16_C( 17828), -INT16_C(  7158),  INT16_C( 30950), -INT16_C(  2444),  INT16_C( 32492),  INT16_C( 16650),  INT16_C(  5035),
        -INT16_C( 14134),  INT16_C( 17062), -INT16_C( 17878), -INT16_C( 11238),  INT16_C( 11631), -INT16_C( 32064), -INT16_C(   375), -INT16_C( 21840) } },
    { UINT16_C( 3299),
      { -INT16_C(  4763),  INT16_C( 19440),  INT16_C( 25957),  INT16_C( 20801),  INT16_C( 31203),  INT16_C( 30184),  INT16_C( 18555), -INT16_C( 16466),
        -INT16_C( 24367),  INT16_C( 12062), -INT16_C( 21758), -INT16_C(  6580),  INT16_C( 26816),  INT16_C( 28876), -INT16_C( 20718),  INT16_C( 30588) },
      {  INT16_C( 28060),  INT16_C(   707),  INT16_C(  1234), -INT16_C( 19117),  INT16_C( 15485), -INT16_C(  2005), -INT16_C(  9852),  INT16_C( 21944),
        -INT16_C( 10631),  INT16_C( 31620), -INT16_C( 11903),  INT16_C( 16993),  INT16_C( 11833),  INT16_C( 19378),  INT16_C( 12253),  INT16_C( 31427) },
      {  INT16_C( 28060),  INT16_C(   707),  INT16_C( 25957),  INT16_C( 20801),  INT16_C( 31203), -INT16_C(  2005), -INT16_C(  9852),  INT16_C( 21944),
        -INT16_C( 24367),  INT16_C( 12062), -INT16_C( 11903),  INT16_C( 16993),  INT16_C( 26816),  INT16_C( 28876), -INT16_C( 20718),  INT16_C( 30588) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_blend_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask_blend_epi16(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_blend_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(163),
      {  INT32_C(  2132484462), -INT32_C(   747366511),  INT32_C(   375182036),  INT32_C(   479607640), -INT32_C(   491675589),  INT32_C(   215550418), -INT32_C(  1895874057), -INT32_C(  1674407122) },
      {  INT32_C(  1176194484),  INT32_C(   957976677), -INT32_C(  1169132190), -INT32_C(   321395023),  INT32_C(  1506707591), -INT32_C(  2006538351),  INT32_C(   387343849), -INT32_C(  1380759304) },
      {  INT32_C(  1176194484),  INT32_C(   957976677),  INT32_C(   375182036),  INT32_C(   479607640), -INT32_C(   491675589), -INT32_C(  2006538351), -INT32_C(  1895874057), -INT32_C(  1380759304) } },
    { UINT8_C(150),
      {  INT32_C(  1593570254), -INT32_C(  2101267444),  INT32_C(  1798536068), -INT32_C(   621666478), -INT32_C(  1804907539),  INT32_C(   394130353),  INT32_C(  1376752650),  INT32_C(   384351303) },
      { -INT32_C(  1133190225), -INT32_C(  1673644776),  INT32_C(    50819505),  INT32_C(  2111764880), -INT32_C(   166639291),  INT32_C(  1192070973),  INT32_C(  1805196579), -INT32_C(  1988001063) },
      {  INT32_C(  1593570254), -INT32_C(  1673644776),  INT32_C(    50819505), -INT32_C(   621666478), -INT32_C(   166639291),  INT32_C(   394130353),  INT32_C(  1376752650), -INT32_C(  1988001063) } },
    { UINT8_C(101),
      {  INT32_C(   729630197), -INT32_C(   186901885),  INT32_C(   461692705),  INT32_C(   123732413), -INT32_C(  1589357038), -INT32_C(  2117760156), -INT32_C(  1504038876), -INT32_C(  1509104719) },
      { -INT32_C(  1412331224), -INT32_C(   979391069),  INT32_C(  1256203149),  INT32_C(   928071716), -INT32_C(    86469226),  INT32_C(  1165729056),  INT32_C(  2129385165), -INT32_C(   500828231) },
      { -INT32_C(  1412331224), -INT32_C(   186901885),  INT32_C(  1256203149),  INT32_C(   123732413), -INT32_C(  1589357038),  INT32_C(  1165729056),  INT32_C(  2129385165), -INT32_C(  1509104719) } },
    { UINT8_C(129),
      { -INT32_C(  1541108234),  INT32_C(  1345448237),  INT32_C(   158694345),  INT32_C(  1654697165),  INT32_C(   579050116), -INT32_C(   319829994), -INT32_C(  1415221581), -INT32_C(  1993570413) },
      {  INT32_C(  1110265877),  INT32_C(    59924026), -INT32_C(  1492318246),  INT32_C(   940158387),  INT32_C(  1566215239),  INT32_C(   139020628),  INT32_C(  1253306295), -INT32_C(  1948983434) },
      {  INT32_C(  1110265877),  INT32_C(  1345448237),  INT32_C(   158694345),  INT32_C(  1654697165),  INT32_C(   579050116), -INT32_C(   319829994), -INT32_C(  1415221581), -INT32_C(  1948983434) } },
    { UINT8_C( 47),
      {  INT32_C(  1617546497),  INT32_C(  1731882336),  INT32_C(   656138618),  INT32_C(  2003719146), -INT32_C(   154415955),  INT32_C(    78566165),  INT32_C(  1702623366), -INT32_C(   829094196) },
      {  INT32_C(   875495124), -INT32_C(   442800021),  INT32_C(   856471113), -INT32_C(  1230341367),  INT32_C(  1554871879), -INT32_C(   798926007),  INT32_C(   540400723), -INT32_C(  1225864478) },
      {  INT32_C(   875495124), -INT32_C(   442800021),  INT32_C(   856471113), -INT32_C(  1230341367), -INT32_C(   154415955), -INT32_C(   798926007),  INT32_C(  1702623366), -INT32_C(   829094196) } },
    { UINT8_C(201),
      { -INT32_C(  2076906980),  INT32_C(  1020074630), -INT32_C(  1589247962),  INT32_C(   568917163),  INT32_C(    74073513), -INT32_C(  2108147034),  INT32_C(   979662960), -INT32_C(  2113725594) },
      { -INT32_C(  1962526715),  INT32_C(  2026427218),  INT32_C(  2115636947), -INT32_C(  1264647670), -INT32_C(   306705849), -INT32_C(  1267789756), -INT32_C(   286272376), -INT32_C(   193924369) },
      { -INT32_C(  1962526715),  INT32_C(  1020074630), -INT32_C(  1589247962), -INT32_C(  1264647670),  INT32_C(    74073513), -INT32_C(  2108147034), -INT32_C(   286272376), -INT32_C(   193924369) } },
    { UINT8_C( 42),
      {  INT32_C(  1232896118),  INT32_C(  1444803912),  INT32_C(   291543823),  INT32_C(  1163465787), -INT32_C(   578206003), -INT32_C(  1973010762),  INT32_C(   528045101),  INT32_C(   994733509) },
      {  INT32_C(   897959661), -INT32_C(   896818501),  INT32_C(  2027744317), -INT32_C(   843238144),  INT32_C(   833308539), -INT32_C(  1296363131),  INT32_C(   718353509), -INT32_C(  1889133662) },
      {  INT32_C(  1232896118), -INT32_C(   896818501),  INT32_C(   291543823), -INT32_C(   843238144), -INT32_C(   578206003), -INT32_C(  1296363131),  INT32_C(   528045101),  INT32_C(   994733509) } },
    { UINT8_C(226),
      { -INT32_C(  1919040021),  INT32_C(  1019897936),  INT32_C(  2034058052),  INT32_C(  1207175680), -INT32_C(   959699275),  INT32_C(   372014817),  INT32_C(  1807242832), -INT32_C(  1488107588) },
      {  INT32_C(  1563749132), -INT32_C(  1751515309),  INT32_C(  1108399682), -INT32_C(  1769339679),  INT32_C(   207443498),  INT32_C(   623020501), -INT32_C(  1668228385),  INT32_C(   776199713) },
      { -INT32_C(  1919040021), -INT32_C(  1751515309),  INT32_C(  2034058052),  INT32_C(  1207175680), -INT32_C(   959699275),  INT32_C(   623020501), -INT32_C(  1668228385),  INT32_C(   776199713) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_blend_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_blend_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_blend_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(201),
      { -INT64_C(  308018130299614344), -INT64_C( 2525830522092061757), -INT64_C(  416347531116413233), -INT64_C( 8138768587312868250) },
      { -INT64_C( 6920695771569968684),  INT64_C( 1305016133113860283),  INT64_C(  752561435714440535), -INT64_C( 6188688236356924298) },
      { -INT64_C( 6920695771569968684), -INT64_C( 2525830522092061757), -INT64_C(  416347531116413233), -INT64_C( 6188688236356924298) } },
    { UINT8_C(133),
      {  INT64_C( 7466406984093442852), -INT64_C( 3956204483172966552), -INT64_C( 8268760645077528794),  INT64_C( 1127604060231552453) },
      {  INT64_C( 8264264789584382129),  INT64_C( 4338176000236214896), -INT64_C( 2564442544032865828), -INT64_C( 8427179542245946350) },
      {  INT64_C( 8264264789584382129), -INT64_C( 3956204483172966552), -INT64_C( 2564442544032865828),  INT64_C( 1127604060231552453) } },
    { UINT8_C(172),
      { -INT64_C( 2521970146282122241),  INT64_C( 4721233250972035933), -INT64_C( 7454242660181056971), -INT64_C( 7600952917491545550) },
      { -INT64_C( 4669909134846051888), -INT64_C( 8470445899461876335),  INT64_C( 3653705726872111952), -INT64_C(  916046964237720036) },
      { -INT64_C( 2521970146282122241),  INT64_C( 4721233250972035933),  INT64_C( 3653705726872111952), -INT64_C(  916046964237720036) } },
    { UINT8_C(197),
      { -INT64_C( 7050412182245718161), -INT64_C( 7597715734445991856), -INT64_C( 8849071482113447038), -INT64_C( 7123678462616214319) },
      { -INT64_C( 8936731338221597725), -INT64_C( 1363656740049850958),  INT64_C( 4891528711540746749),  INT64_C(  784686428748614167) },
      { -INT64_C( 8936731338221597725), -INT64_C( 7597715734445991856),  INT64_C( 4891528711540746749), -INT64_C( 7123678462616214319) } },
    { UINT8_C( 15),
      {  INT64_C( 5630278406940747286),  INT64_C( 6761494806443696262), -INT64_C( 6993225919858003543),  INT64_C( 3640823970439379379) },
      {  INT64_C( 1433486689512376373), -INT64_C( 1263892717404184988),  INT64_C(  766664538745095409),  INT64_C( 7729311888806340598) },
      {  INT64_C( 1433486689512376373), -INT64_C( 1263892717404184988),  INT64_C(  766664538745095409),  INT64_C( 7729311888806340598) } },
    { UINT8_C(208),
      { -INT64_C( 9002854097877204506), -INT64_C( 2302264527912687782),  INT64_C( 1960263980206723456),  INT64_C( 8258120175318026178) },
      { -INT64_C( 4528883555939518531),  INT64_C( 2797271543470354260),  INT64_C(  849095971951610104), -INT64_C( 7791947714046584353) },
      { -INT64_C( 9002854097877204506), -INT64_C( 2302264527912687782),  INT64_C( 1960263980206723456),  INT64_C( 8258120175318026178) } },
    { UINT8_C(103),
      {  INT64_C( 5510874724287002362),  INT64_C( 4920771090712718186), -INT64_C( 2813737395725404293),  INT64_C( 3838828557303176814) },
      {  INT64_C( 1018330989910037624), -INT64_C( 6430671693439560895),  INT64_C( 6141130776168255137), -INT64_C( 6738094050257869044) },
      {  INT64_C( 1018330989910037624), -INT64_C( 6430671693439560895),  INT64_C( 6141130776168255137),  INT64_C( 3838828557303176814) } },
    { UINT8_C(143),
      { -INT64_C( 5984930301473490983),  INT64_C( 9146102965131964065),  INT64_C( 7994095526614486326), -INT64_C( 8216191123138856977) },
      {  INT64_C( 1150157806066544049),  INT64_C( 9172503448356834460),  INT64_C( 6595894848746926229),  INT64_C(  850546298980737419) },
      {  INT64_C( 1150157806066544049),  INT64_C( 9172503448356834460),  INT64_C( 6595894848746926229),  INT64_C(  850546298980737419) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_blend_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_blend_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_blend_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(145),
      { SIMDE_FLOAT32_C(  -666.04), SIMDE_FLOAT32_C(  -910.73), SIMDE_FLOAT32_C(   105.35), SIMDE_FLOAT32_C(  -622.43),
        SIMDE_FLOAT32_C(  -805.58), SIMDE_FLOAT32_C(  -324.90), SIMDE_FLOAT32_C(   657.71), SIMDE_FLOAT32_C(  -101.07) },
      { SIMDE_FLOAT32_C(   407.96), SIMDE_FLOAT32_C(   118.11), SIMDE_FLOAT32_C(   128.03), SIMDE_FLOAT32_C(  -679.02),
        SIMDE_FLOAT32_C(   825.56), SIMDE_FLOAT32_C(  -692.56), SIMDE_FLOAT32_C(   -84.89), SIMDE_FLOAT32_C(   217.59) },
      { SIMDE_FLOAT32_C(   407.96), SIMDE_FLOAT32_C(  -910.73), SIMDE_FLOAT32_C(   105.35), SIMDE_FLOAT32_C(  -622.43),
        SIMDE_FLOAT32_C(   825.56), SIMDE_FLOAT32_C(  -324.90), SIMDE_FLOAT32_C(   657.71), SIMDE_FLOAT32_C(   217.59) } },
    { UINT8_C( 44),
      { SIMDE_FLOAT32_C(  -959.89), SIMDE_FLOAT32_C(   319.48), SIMDE_FLOAT32_C(   787.79), SIMDE_FLOAT32_C(  -711.80),
        SIMDE_FLOAT32_C(   905.92), SIMDE_FLOAT32_C(   145.58), SIMDE_FLOAT32_C(    75.27), SIMDE_FLOAT32_C(  -317.71) },
      { SIMDE_FLOAT32_C(   332.64), SIMDE_FLOAT32_C(  -857.18), SIMDE_FLOAT32_C(  -296.21), SIMDE_FLOAT32_C(  -979.65),
        SIMDE_FLOAT32_C(   338.40), SIMDE_FLOAT32_C(   320.07), SIMDE_FLOAT32_C(  -645.69), SIMDE_FLOAT32_C(   427.67) },
      { SIMDE_FLOAT32_C(  -959.89), SIMDE_FLOAT32_C(   319.48), SIMDE_FLOAT32_C(  -296.21), SIMDE_FLOAT32_C(  -979.65),
        SIMDE_FLOAT32_C(   905.92), SIMDE_FLOAT32_C(   320.07), SIMDE_FLOAT32_C(    75.27), SIMDE_FLOAT32_C(  -317.71) } },
    { UINT8_C(171),
      { SIMDE_FLOAT32_C(  -268.12), SIMDE_FLOAT32_C(   622.08), SIMDE_FLOAT32_C(   100.51), SIMDE_FLOAT32_C(  -610.41),
        SIMDE_FLOAT32_C(  -478.98), SIMDE_FLOAT32_C(  -491.52), SIMDE_FLOAT32_C(   507.70), SIMDE_FLOAT32_C(   649.05) },
      { SIMDE_FLOAT32_C(  -170.54), SIMDE_FLOAT32_C(   333.25), SIMDE_FLOAT32_C(   956.49), SIMDE_FLOAT32_C(   744.56),
        SIMDE_FLOAT32_C(  -449.15), SIMDE_FLOAT32_C(   446.24), SIMDE_FLOAT32_C(   784.67), SIMDE_FLOAT32_C(   870.32) },
      { SIMDE_FLOAT32_C(  -170.54), SIMDE_FLOAT32_C(   333.25), SIMDE_FLOAT32_C(   100.51), SIMDE_FLOAT32_C(   744.56),
        SIMDE_FLOAT32_C(  -478.98), SIMDE_FLOAT32_C(   446.24), SIMDE_FLOAT32_C(   507.70), SIMDE_FLOAT32_C(   870.32) } },
    { UINT8_C(177),
      { SIMDE_FLOAT32_C(  -927.13), SIMDE_FLOAT32_C(   776.24), SIMDE_FLOAT32_C(  -620.39), SIMDE_FLOAT32_C(   148.14),
        SIMDE_FLOAT32_C(  -541.47), SIMDE_FLOAT32_C(   712.26), SIMDE_FLOAT32_C(   290.97), SIMDE_FLOAT32_C(   162.32) },
      { SIMDE_FLOAT32_C(   732.61), SIMDE_FLOAT32_C(  -370.63), SIMDE_FLOAT32_C(  -517.61), SIMDE_FLOAT32_C(  -913.08),
        SIMDE_FLOAT32_C(  -942.96), SIMDE_FLOAT32_C(   -92.20), SIMDE_FLOAT32_C(  -181.20), SIMDE_FLOAT32_C(   679.12) },
      { SIMDE_FLOAT32_C(   732.61), SIMDE_FLOAT32_C(   776.24), SIMDE_FLOAT32_C(  -620.39), SIMDE_FLOAT32_C(   148.14),
        SIMDE_FLOAT32_C(  -942.96), SIMDE_FLOAT32_C(   -92.20), SIMDE_FLOAT32_C(   290.97), SIMDE_FLOAT32_C(   679.12) } },
    { UINT8_C( 48),
      { SIMDE_FLOAT32_C(   208.39), SIMDE_FLOAT32_C(  -799.86), SIMDE_FLOAT32_C(  -483.20), SIMDE_FLOAT32_C(  -283.92),
        SIMDE_FLOAT32_C(   849.19), SIMDE_FLOAT32_C(   346.25), SIMDE_FLOAT32_C(  -950.66), SIMDE_FLOAT32_C(   805.68) },
      { SIMDE_FLOAT32_C(    90.82), SIMDE_FLOAT32_C(  -399.82), SIMDE_FLOAT32_C(   251.91), SIMDE_FLOAT32_C(  -124.51),
        SIMDE_FLOAT32_C(  -529.50), SIMDE_FLOAT32_C(  -514.06), SIMDE_FLOAT32_C(   -51.64), SIMDE_FLOAT32_C(  -753.25) },
      { SIMDE_FLOAT32_C(   208.39), SIMDE_FLOAT32_C(  -799.86), SIMDE_FLOAT32_C(  -483.20), SIMDE_FLOAT32_C(  -283.92),
        SIMDE_FLOAT32_C(  -529.50), SIMDE_FLOAT32_C(  -514.06), SIMDE_FLOAT32_C(  -950.66), SIMDE_FLOAT32_C(   805.68) } },
    { UINT8_C(184),
      { SIMDE_FLOAT32_C(  -903.50), SIMDE_FLOAT32_C(  -294.72), SIMDE_FLOAT32_C(  -422.18), SIMDE_FLOAT32_C(   387.47),
        SIMDE_FLOAT32_C(   867.60), SIMDE_FLOAT32_C(  -689.57), SIMDE_FLOAT32_C(  -983.16), SIMDE_FLOAT32_C(  -650.02) },
      { SIMDE_FLOAT32_C(  -602.65), SIMDE_FLOAT32_C(  -926.12), SIMDE_FLOAT32_C(   257.79), SIMDE_FLOAT32_C(   216.14),
        SIMDE_FLOAT32_C(   753.00), SIMDE_FLOAT32_C(   266.10), SIMDE_FLOAT32_C(  -575.47), SIMDE_FLOAT32_C(   953.14) },
      { SIMDE_FLOAT32_C(  -903.50), SIMDE_FLOAT32_C(  -294.72), SIMDE_FLOAT32_C(  -422.18), SIMDE_FLOAT32_C(   216.14),
        SIMDE_FLOAT32_C(   753.00), SIMDE_FLOAT32_C(   266.10), SIMDE_FLOAT32_C(  -983.16), SIMDE_FLOAT32_C(   953.14) } },
    { UINT8_C( 73),
      { SIMDE_FLOAT32_C(   140.61), SIMDE_FLOAT32_C(   802.33), SIMDE_FLOAT32_C(   129.15), SIMDE_FLOAT32_C(   189.95),
        SIMDE_FLOAT32_C(   608.01), SIMDE_FLOAT32_C(  -780.03), SIMDE_FLOAT32_C(   790.13), SIMDE_FLOAT32_C(  -140.08) },
      { SIMDE_FLOAT32_C(    95.46), SIMDE_FLOAT32_C(  -739.36), SIMDE_FLOAT32_C(   345.87), SIMDE_FLOAT32_C(  -956.18),
        SIMDE_FLOAT32_C(  -492.61), SIMDE_FLOAT32_C(  -788.58), SIMDE_FLOAT32_C(  -859.67), SIMDE_FLOAT32_C(   212.67) },
      { SIMDE_FLOAT32_C(    95.46), SIMDE_FLOAT32_C(   802.33), SIMDE_FLOAT32_C(   129.15), SIMDE_FLOAT32_C(  -956.18),
        SIMDE_FLOAT32_C(   608.01), SIMDE_FLOAT32_C(  -780.03), SIMDE_FLOAT32_C(  -859.67), SIMDE_FLOAT32_C(  -140.08) } },
    { UINT8_C(212),
      { SIMDE_FLOAT32_C(   527.80), SIMDE_FLOAT32_C(    80.27), SIMDE_FLOAT32_C(    99.67), SIMDE_FLOAT32_C(   544.64),
        SIMDE_FLOAT32_C(   430.25), SIMDE_FLOAT32_C(   497.01), SIMDE_FLOAT32_C(   618.52), SIMDE_FLOAT32_C(  -311.96) },
      { SIMDE_FLOAT32_C(  -286.84), SIMDE_FLOAT32_C(   371.52), SIMDE_FLOAT32_C(   954.14), SIMDE_FLOAT32_C(   137.69),
        SIMDE_FLOAT32_C(   324.66), SIMDE_FLOAT32_C(   737.04), SIMDE_FLOAT32_C(  -721.70), SIMDE_FLOAT32_C(   127.00) },
      { SIMDE_FLOAT32_C(   527.80), SIMDE_FLOAT32_C(    80.27), SIMDE_FLOAT32_C(   954.14), SIMDE_FLOAT32_C(   544.64),
        SIMDE_FLOAT32_C(   324.66), SIMDE_FLOAT32_C(   497.01), SIMDE_FLOAT32_C(  -721.70), SIMDE_FLOAT32_C(   127.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_mask_blend_ps(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r = simde_mm256_mask_blend_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_blend_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(157),
      { SIMDE_FLOAT64_C(   468.25), SIMDE_FLOAT64_C(  -265.00), SIMDE_FLOAT64_C(    86.16), SIMDE_FLOAT64_C(   258.38) },
      { SIMDE_FLOAT64_C(   594.93), SIMDE_FLOAT64_C(  -818.38), SIMDE_FLOAT64_C(   519.02), SIMDE_FLOAT64_C(   -59.21) },
      { SIMDE_FLOAT64_C(   594.93), SIMDE_FLOAT64_C(  -265.00), SIMDE_FLOAT64_C(   519.02), SIMDE_FLOAT64_C(   -59.21) } },
    { UINT8_C(212),
      { SIMDE_FLOAT64_C(  -973.59), SIMDE_FLOAT64_C(   152.22), SIMDE_FLOAT64_C(  -634.23), SIMDE_FLOAT64_C(   239.07) },
      { SIMDE_FLOAT64_C(   941.46), SIMDE_FLOAT64_C(   893.57), SIMDE_FLOAT64_C(  -680.66), SIMDE_FLOAT64_C(    41.12) },
      { SIMDE_FLOAT64_C(  -973.59), SIMDE_FLOAT64_C(   152.22), SIMDE_FLOAT64_C(  -680.66), SIMDE_FLOAT64_C(   239.07) } },
    { UINT8_C(209),
      { SIMDE_FLOAT64_C(   749.59), SIMDE_FLOAT64_C(  -461.86), SIMDE_FLOAT64_C(    56.73), SIMDE_FLOAT64_C(  -562.37) },
      { SIMDE_FLOAT64_C(   251.29), SIMDE_FLOAT64_C(  -571.74), SIMDE_FLOAT64_C(  -608.23), SIMDE_FLOAT64_C(  -611.02) },
      { SIMDE_FLOAT64_C(   251.29), SIMDE_FLOAT64_C(  -461.86), SIMDE_FLOAT64_C(    56.73), SIMDE_FLOAT64_C(  -562.37) } },
    { UINT8_C(219),
      { SIMDE_FLOAT64_C(  -871.20), SIMDE_FLOAT64_C(  -332.71), SIMDE_FLOAT64_C(  -120.08), SIMDE_FLOAT64_C(    -5.01) },
      { SIMDE_FLOAT64_C(  -864.46), SIMDE_FLOAT64_C(   614.92), SIMDE_FLOAT64_C(  -918.85), SIMDE_FLOAT64_C(   393.92) },
      { SIMDE_FLOAT64_C(  -864.46), SIMDE_FLOAT64_C(   614.92), SIMDE_FLOAT64_C(  -120.08), SIMDE_FLOAT64_C(   393.92) } },
    { UINT8_C( 99),
      { SIMDE_FLOAT64_C(  -737.23), SIMDE_FLOAT64_C(   -87.06), SIMDE_FLOAT64_C(  -849.36), SIMDE_FLOAT64_C(  -511.78) },
      { SIMDE_FLOAT64_C(   -60.65), SIMDE_FLOAT64_C(   302.86), SIMDE_FLOAT64_C(  -146.01), SIMDE_FLOAT64_C(  -821.58) },
      { SIMDE_FLOAT64_C(   -60.65), SIMDE_FLOAT64_C(   302.86), SIMDE_FLOAT64_C(  -849.36), SIMDE_FLOAT64_C(  -511.78) } },
    { UINT8_C( 72),
      { SIMDE_FLOAT64_C(  -252.44), SIMDE_FLOAT64_C(  -502.24), SIMDE_FLOAT64_C(  -714.56), SIMDE_FLOAT64_C(  -814.23) },
      { SIMDE_FLOAT64_C(  -752.65), SIMDE_FLOAT64_C(  -176.43), SIMDE_FLOAT64_C(   242.51), SIMDE_FLOAT64_C(  -315.02) },
      { SIMDE_FLOAT64_C(  -252.44), SIMDE_FLOAT64_C(  -502.24), SIMDE_FLOAT64_C(  -714.56), SIMDE_FLOAT64_C(  -315.02) } },
    { UINT8_C( 85),
      { SIMDE_FLOAT64_C(   670.77), SIMDE_FLOAT64_C(    76.74), SIMDE_FLOAT64_C(  -536.15), SIMDE_FLOAT64_C(   423.69) },
      { SIMDE_FLOAT64_C(   205.55), SIMDE_FLOAT64_C(   131.14), SIMDE_FLOAT64_C(  -696.40), SIMDE_FLOAT64_C(  -799.46) },
      { SIMDE_FLOAT64_C(   205.55), SIMDE_FLOAT64_C(    76.74), SIMDE_FLOAT64_C(  -696.40), SIMDE_FLOAT64_C(   423.69) } },
    { UINT8_C(104),
      { SIMDE_FLOAT64_C(   918.52), SIMDE_FLOAT64_C(  -718.30), SIMDE_FLOAT64_C(  -339.40), SIMDE_FLOAT64_C(   128.37) },
      { SIMDE_FLOAT64_C(  -455.53), SIMDE_FLOAT64_C(   573.54), SIMDE_FLOAT64_C(   279.01), SIMDE_FLOAT64_C(    32.69) },
      { SIMDE_FLOAT64_C(   918.52), SIMDE_FLOAT64_C(  -718.30), SIMDE_FLOAT64_C(  -339.40), SIMDE_FLOAT64_C(    32.69) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_mask_blend_pd(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_mask_blend_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_blend_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C(  426401881765016573),
      {  INT8_C(  93), -INT8_C(   1),  INT8_C(  35), -INT8_C(  77), -INT8_C(  39),  INT8_C(  19),  INT8_C( 126),  INT8_C(  59),
         INT8_C(   6), -INT8_C( 107),  INT8_C(   0), -INT8_C(   1),  INT8_C(   9), -INT8_C( 116), -INT8_C(  27), -INT8_C(  68),
        -INT8_C(  96), -INT8_C(  78),  INT8_C(  98), -INT8_C( 106),  INT8_C(  39), -INT8_C(  47),  INT8_C( 120),  INT8_C(  37),
         INT8_C(  69), -INT8_C(  94), -INT8_C(  69), -INT8_C( 123), -INT8_C( 124), -INT8_C(  91), -INT8_C( 118), -INT8_C(  31),
        -INT8_C(  92), -INT8_C(  83), -INT8_C( 107),  INT8_C( 126), -INT8_C(  63),  INT8_C(  19), -INT8_C(  71), -INT8_C(  57),
        -INT8_C(  88), -INT8_C(  71), -INT8_C(  58), -INT8_C(  79),  INT8_C(  69), -INT8_C(  85),  INT8_C( 109), -INT8_C(  27),
         INT8_C(  93), -INT8_C(  48),  INT8_C( 123), -INT8_C( 123), -INT8_C(  95), -INT8_C(  12), -INT8_C(  86), -INT8_C(  26),
        -INT8_C( 106),  INT8_C( 101),  INT8_C( 108),  INT8_C(  26),  INT8_C(  11), -INT8_C(  10), -INT8_C(   4), -INT8_C(  81) },
      { -INT8_C(  92), -INT8_C( 111),  INT8_C(  45),  INT8_C( 101), -INT8_C(  92), -INT8_C(  25),  INT8_C(  44),  INT8_C(  76),
        -INT8_C(  96), -INT8_C(  14), -INT8_C(   2), -INT8_C(  26), -INT8_C(  99),  INT8_C( 107), -INT8_C(  53), -INT8_C(   6),
         INT8_C(  59),  INT8_C(  71),      INT8_MAX, -INT8_C(  35),  INT8_C(  59),  INT8_C(  41), -INT8_C(  61), -INT8_C(  47),
        -INT8_C( 113),  INT8_C(  47), -INT8_C(  21), -INT8_C( 102),  INT8_C(  38), -INT8_C(  25),  INT8_C(  73), -INT8_C(  54),
         INT8_C( 120),  INT8_C( 119),  INT8_C(  47),  INT8_C(  28),  INT8_C(  94),  INT8_C(  91),  INT8_C( 105), -INT8_C(   2),
         INT8_C(  77),  INT8_C( 103), -INT8_C(  28), -INT8_C(  22), -INT8_C(  46), -INT8_C(  80), -INT8_C(  28),  INT8_C(  14),
        -INT8_C(   9),  INT8_C( 100), -INT8_C(  21),  INT8_C(  50), -INT8_C( 115), -INT8_C(  82),  INT8_C(   3),  INT8_C(  28),
        -INT8_C(  34), -INT8_C(  18), -INT8_C(  74),  INT8_C(   4), -INT8_C(  42),  INT8_C(   0), -INT8_C(  50),  INT8_C(  78) },
      { -INT8_C(  92), -INT8_C(   1),  INT8_C(  45),  INT8_C( 101), -INT8_C(  92), -INT8_C(  25),  INT8_C(  44),  INT8_C(  76),
        -INT8_C(  96), -INT8_C(  14),  INT8_C(   0), -INT8_C(   1), -INT8_C(  99),  INT8_C( 107), -INT8_C(  53), -INT8_C(  68),
         INT8_C(  59), -INT8_C(  78),  INT8_C(  98), -INT8_C(  35),  INT8_C(  39),  INT8_C(  41),  INT8_C( 120),  INT8_C(  37),
         INT8_C(  69),  INT8_C(  47), -INT8_C(  21), -INT8_C( 123),  INT8_C(  38), -INT8_C(  91), -INT8_C( 118), -INT8_C(  54),
        -INT8_C(  92), -INT8_C(  83), -INT8_C( 107),  INT8_C( 126), -INT8_C(  63),  INT8_C(  19),  INT8_C( 105), -INT8_C(  57),
        -INT8_C(  88),  INT8_C( 103), -INT8_C(  58), -INT8_C(  79),  INT8_C(  69), -INT8_C(  80), -INT8_C(  28),  INT8_C(  14),
         INT8_C(  93),  INT8_C( 100),  INT8_C( 123),  INT8_C(  50), -INT8_C(  95), -INT8_C(  82),  INT8_C(   3),  INT8_C(  28),
        -INT8_C(  34),  INT8_C( 101), -INT8_C(  74),  INT8_C(  26),  INT8_C(  11), -INT8_C(  10), -INT8_C(   4), -INT8_C(  81) } },
    { UINT64_C(11949127714346892663),
      {  INT8_C(  59), -INT8_C(  72), -INT8_C( 113),  INT8_C(  13),  INT8_C( 104),  INT8_C( 115),  INT8_C(  27),  INT8_C(  95),
        -INT8_C(  41),  INT8_C(   6), -INT8_C( 111),  INT8_C( 101), -INT8_C(  75), -INT8_C( 108), -INT8_C( 127), -INT8_C( 109),
        -INT8_C( 126),  INT8_C(  56), -INT8_C( 105),  INT8_C(  88),  INT8_C(  56),  INT8_C( 101), -INT8_C(  89), -INT8_C(  81),
         INT8_C(  98),  INT8_C(  18), -INT8_C( 124), -INT8_C(  70), -INT8_C(  26),  INT8_C(  87),  INT8_C(  95),  INT8_C(  33),
         INT8_C(  15), -INT8_C(  18),  INT8_C(  46),  INT8_C( 119),  INT8_C(  97),  INT8_C(  74), -INT8_C(  42),  INT8_C(  57),
         INT8_C(  80),  INT8_C( 103), -INT8_C(  98),  INT8_C(   5), -INT8_C(   5),  INT8_C(  31), -INT8_C( 104),  INT8_C( 126),
         INT8_C(  87),  INT8_C(  47), -INT8_C(  42), -INT8_C( 113), -INT8_C( 108),  INT8_C( 125),  INT8_C(  62), -INT8_C(  10),
        -INT8_C( 113), -INT8_C(  62), -INT8_C(  80),  INT8_C( 117),  INT8_C(  26),  INT8_C(  15), -INT8_C( 106),  INT8_C(  41) },
      { -INT8_C(   3), -INT8_C(  59), -INT8_C(  95),  INT8_C(  95),  INT8_C(  15),  INT8_C( 119), -INT8_C( 104),  INT8_C(  95),
        -INT8_C(  33),  INT8_C(  54),  INT8_C( 101), -INT8_C(  38),  INT8_C(  85), -INT8_C(   3),  INT8_C(  88), -INT8_C(  83),
         INT8_C(  45),  INT8_C(  47),  INT8_C(  60), -INT8_C(  63), -INT8_C(  84),  INT8_C( 123), -INT8_C(  72),  INT8_C(  60),
         INT8_C(  61),  INT8_C( 104), -INT8_C(  79),  INT8_C(  87),  INT8_C( 120),  INT8_C(  72), -INT8_C( 127),  INT8_C( 117),
         INT8_C(  13),  INT8_C(  34), -INT8_C(  44),  INT8_C(  28), -INT8_C( 103),  INT8_C( 108),  INT8_C( 123),  INT8_C( 120),
        -INT8_C(  94), -INT8_C(  32),  INT8_C(  83), -INT8_C(   8), -INT8_C(  34), -INT8_C(  85), -INT8_C(  91),  INT8_C(  11),
        -INT8_C(  38), -INT8_C(  31), -INT8_C(  52), -INT8_C( 121),  INT8_C(  92), -INT8_C( 124), -INT8_C(  61), -INT8_C( 102),
        -INT8_C(  19),  INT8_C( 116), -INT8_C(  15),  INT8_C( 101), -INT8_C(  68),  INT8_C( 114), -INT8_C(  38), -INT8_C(  55) },
      { -INT8_C(   3), -INT8_C(  59), -INT8_C(  95),  INT8_C(  13),  INT8_C(  15),  INT8_C( 119), -INT8_C( 104),  INT8_C(  95),
        -INT8_C(  33),  INT8_C(   6),  INT8_C( 101), -INT8_C(  38),  INT8_C(  85), -INT8_C(   3),  INT8_C(  88), -INT8_C(  83),
         INT8_C(  45),  INT8_C(  47), -INT8_C( 105), -INT8_C(  63),  INT8_C(  56),  INT8_C( 123), -INT8_C(  72), -INT8_C(  81),
         INT8_C(  61),  INT8_C(  18), -INT8_C(  79), -INT8_C(  70),  INT8_C( 120),  INT8_C(  87), -INT8_C( 127),  INT8_C( 117),
         INT8_C(  15), -INT8_C(  18),  INT8_C(  46),  INT8_C(  28), -INT8_C( 103),  INT8_C(  74),  INT8_C( 123),  INT8_C(  57),
         INT8_C(  80),  INT8_C( 103),  INT8_C(  83),  INT8_C(   5), -INT8_C(  34),  INT8_C(  31), -INT8_C(  91),  INT8_C(  11),
        -INT8_C(  38), -INT8_C(  31), -INT8_C(  42), -INT8_C( 113),  INT8_C(  92),  INT8_C( 125), -INT8_C(  61), -INT8_C( 102),
        -INT8_C(  19), -INT8_C(  62), -INT8_C(  15),  INT8_C( 117),  INT8_C(  26),  INT8_C( 114), -INT8_C( 106), -INT8_C(  55) } },
    { UINT64_C(13737774482719092628),
      {  INT8_C(  65), -INT8_C(   7), -INT8_C(  74),  INT8_C(  31), -INT8_C(  91),  INT8_C(  91),  INT8_C(  42),      INT8_MAX,
         INT8_C(  60), -INT8_C(   9),  INT8_C(   6), -INT8_C( 103),  INT8_C( 123), -INT8_C(  55),  INT8_C(  51),  INT8_C( 104),
         INT8_C(  62),  INT8_C(  36), -INT8_C(  51), -INT8_C(   6), -INT8_C( 105), -INT8_C(  88), -INT8_C(  60),  INT8_C(  43),
         INT8_C(  87), -INT8_C(  87),  INT8_C(  89),  INT8_C( 114),  INT8_C(  10),  INT8_C(   0),  INT8_C(  48),  INT8_C(  76),
        -INT8_C(   7), -INT8_C(  26),  INT8_C( 107), -INT8_C(  98),  INT8_C(  65), -INT8_C( 106),  INT8_C(  30),  INT8_C( 126),
        -INT8_C( 115),  INT8_C(  36),  INT8_C(  23),  INT8_C(   8), -INT8_C(  18),  INT8_C(  74),  INT8_C( 113),  INT8_C(  44),
         INT8_C( 110),  INT8_C(  62),  INT8_C(  38),  INT8_C(   5), -INT8_C(  26), -INT8_C(  22),  INT8_C(  49),  INT8_C(  61),
        -INT8_C( 108), -INT8_C( 118), -INT8_C(  80), -INT8_C(  98), -INT8_C( 118), -INT8_C(  32), -INT8_C(  22), -INT8_C( 124) },
      { -INT8_C(  57),  INT8_C(  86),  INT8_C(  34),  INT8_C(   8), -INT8_C(  20),  INT8_C(  64), -INT8_C( 122),  INT8_C( 121),
         INT8_C( 101), -INT8_C(  99), -INT8_C( 127),  INT8_C(  83), -INT8_C(  25), -INT8_C(  14),      INT8_MAX,  INT8_C(  86),
         INT8_C(  49), -INT8_C(  91),  INT8_C(  91),  INT8_C(  23), -INT8_C( 112), -INT8_C( 116),  INT8_C(  85),  INT8_C(  36),
         INT8_C(  23),  INT8_C(   5), -INT8_C(  62), -INT8_C(  95), -INT8_C(  27), -INT8_C(  83),  INT8_C(  37), -INT8_C(  84),
         INT8_C(   3),  INT8_C(  72), -INT8_C(  75), -INT8_C(  17), -INT8_C( 120),  INT8_C(  59),  INT8_C( 104), -INT8_C(  19),
        -INT8_C(  39), -INT8_C(  23),  INT8_C(  64), -INT8_C(  64), -INT8_C(  36), -INT8_C(  65),  INT8_C(  22),  INT8_C(  13),
         INT8_C( 101),  INT8_C( 114),  INT8_C(  36), -INT8_C(  11), -INT8_C(   2),  INT8_C( 121),  INT8_C(  25),  INT8_C(  21),
         INT8_C( 126), -INT8_C(  37), -INT8_C(  73),  INT8_C( 100), -INT8_C( 120), -INT8_C(  36),  INT8_C(  16), -INT8_C( 117) },
      {  INT8_C(  65), -INT8_C(   7),  INT8_C(  34),  INT8_C(  31), -INT8_C(  20),  INT8_C(  91),  INT8_C(  42),  INT8_C( 121),
         INT8_C( 101), -INT8_C(  99), -INT8_C( 127),  INT8_C(  83),  INT8_C( 123), -INT8_C(  14),  INT8_C(  51),  INT8_C(  86),
         INT8_C(  49),  INT8_C(  36),  INT8_C(  91), -INT8_C(   6), -INT8_C( 105), -INT8_C( 116),  INT8_C(  85),  INT8_C(  36),
         INT8_C(  87),  INT8_C(   5), -INT8_C(  62), -INT8_C(  95),  INT8_C(  10), -INT8_C(  83),  INT8_C(  48),  INT8_C(  76),
         INT8_C(   3),  INT8_C(  72),  INT8_C( 107), -INT8_C(  17), -INT8_C( 120), -INT8_C( 106),  INT8_C(  30),  INT8_C( 126),
        -INT8_C(  39),  INT8_C(  36),  INT8_C(  23),  INT8_C(   8), -INT8_C(  18), -INT8_C(  65),  INT8_C(  22),  INT8_C(  44),
         INT8_C( 110),  INT8_C( 114),  INT8_C(  36),  INT8_C(   5), -INT8_C(  26),  INT8_C( 121),  INT8_C(  49),  INT8_C(  21),
        -INT8_C( 108), -INT8_C(  37), -INT8_C(  73),  INT8_C( 100), -INT8_C( 120), -INT8_C(  36), -INT8_C(  22), -INT8_C( 117) } },
    { UINT64_C(15752151143515079972),
      { -INT8_C(  52), -INT8_C(  37), -INT8_C( 102), -INT8_C(  88), -INT8_C( 102), -INT8_C(  79), -INT8_C(  75), -INT8_C(   1),
         INT8_C(  35), -INT8_C(  39), -INT8_C(  12),  INT8_C(  33),  INT8_C(  83),  INT8_C(  13),  INT8_C(  55), -INT8_C(  47),
        -INT8_C(  23), -INT8_C(  18),  INT8_C(  53),  INT8_C( 113), -INT8_C(  54),  INT8_C(  70), -INT8_C(   3), -INT8_C(  17),
         INT8_C(  11),  INT8_C( 119), -INT8_C( 100),  INT8_C(  12),  INT8_C(  90),  INT8_C(  54), -INT8_C(  26),  INT8_C(  38),
         INT8_C(  17), -INT8_C( 127), -INT8_C(  50), -INT8_C(  84),  INT8_C(  50), -INT8_C( 125), -INT8_C(  85),  INT8_C(  85),
         INT8_C(  92), -INT8_C(  96),  INT8_C( 118), -INT8_C(  81), -INT8_C(  83), -INT8_C(  83), -INT8_C( 127), -INT8_C( 106),
        -INT8_C( 101), -INT8_C(  74),  INT8_C(   8),  INT8_C( 102), -INT8_C(   4),  INT8_C(   5),  INT8_C(  85),  INT8_C(   8),
         INT8_C( 124), -INT8_C(  15),  INT8_C(  20), -INT8_C(  42),  INT8_C(  39), -INT8_C(   5), -INT8_C(   4),  INT8_C(  57) },
      {  INT8_C( 124), -INT8_C(  54), -INT8_C(  27), -INT8_C(  82),  INT8_C(  77), -INT8_C( 112),  INT8_C(   3), -INT8_C(  86),
         INT8_C(  48),  INT8_C( 121),  INT8_C(  89), -INT8_C(  34),  INT8_C(  39), -INT8_C(  38),  INT8_C( 116), -INT8_C(  62),
        -INT8_C( 111),  INT8_C( 124),  INT8_C(  40), -INT8_C( 115), -INT8_C( 127),  INT8_C( 125), -INT8_C( 107), -INT8_C(   2),
         INT8_C( 110), -INT8_C(  86), -INT8_C(  44), -INT8_C( 106), -INT8_C(  91), -INT8_C(  47), -INT8_C(  49),  INT8_C(  33),
        -INT8_C( 101), -INT8_C(  76), -INT8_C(  49), -INT8_C(  23),  INT8_C(  68), -INT8_C(  46), -INT8_C( 109),  INT8_C( 117),
         INT8_C(  75), -INT8_C(  20),  INT8_C(  83),  INT8_C( 114), -INT8_C(  57), -INT8_C(  57),  INT8_C(  53),  INT8_C(  88),
         INT8_C(  68),  INT8_C(  93), -INT8_C(  27), -INT8_C(  59), -INT8_C(  37),  INT8_C( 123), -INT8_C(  61),  INT8_C(  73),
         INT8_C(  37), -INT8_C( 104), -INT8_C(  33), -INT8_C(  54),  INT8_C( 105), -INT8_C(  82), -INT8_C(  21),  INT8_C(   4) },
      { -INT8_C(  52), -INT8_C(  37), -INT8_C(  27), -INT8_C(  88), -INT8_C( 102), -INT8_C( 112), -INT8_C(  75), -INT8_C(   1),
         INT8_C(  48), -INT8_C(  39),  INT8_C(  89),  INT8_C(  33),  INT8_C(  83),  INT8_C(  13),  INT8_C( 116), -INT8_C(  62),
        -INT8_C(  23),  INT8_C( 124),  INT8_C(  53), -INT8_C( 115), -INT8_C( 127),  INT8_C( 125), -INT8_C( 107), -INT8_C(  17),
         INT8_C( 110),  INT8_C( 119), -INT8_C(  44), -INT8_C( 106),  INT8_C(  90), -INT8_C(  47), -INT8_C(  26),  INT8_C(  33),
        -INT8_C( 101), -INT8_C( 127), -INT8_C(  50), -INT8_C(  84),  INT8_C(  50), -INT8_C( 125), -INT8_C(  85),  INT8_C(  85),
         INT8_C(  92), -INT8_C(  20),  INT8_C( 118), -INT8_C(  81), -INT8_C(  83), -INT8_C(  57),  INT8_C(  53),  INT8_C(  88),
        -INT8_C( 101),  INT8_C(  93),  INT8_C(   8), -INT8_C(  59), -INT8_C(  37),  INT8_C(   5),  INT8_C(  85),  INT8_C(  73),
         INT8_C( 124), -INT8_C( 104),  INT8_C(  20), -INT8_C(  54),  INT8_C( 105), -INT8_C(   5), -INT8_C(  21),  INT8_C(   4) } },
    { UINT64_C(15500405359103556194),
      {  INT8_C( 109),  INT8_C( 111),  INT8_C(  74),  INT8_C(  52),  INT8_C(  54),      INT8_MAX, -INT8_C( 116),  INT8_C( 122),
        -INT8_C(  36),  INT8_C( 113),  INT8_C(  64), -INT8_C(  73), -INT8_C(  20),  INT8_C(   3),  INT8_C(   1),  INT8_C(  17),
        -INT8_C( 101), -INT8_C(  32), -INT8_C(  37),  INT8_C(   4), -INT8_C( 113), -INT8_C(  58),  INT8_C(   9), -INT8_C(  15),
             INT8_MIN, -INT8_C(  10), -INT8_C( 104),  INT8_C(  12),  INT8_C( 119), -INT8_C(  76), -INT8_C(  28), -INT8_C(  28),
         INT8_C(  35),  INT8_C(  46),  INT8_C(  24),  INT8_C(  90), -INT8_C(  83), -INT8_C(  92), -INT8_C(  44), -INT8_C( 119),
         INT8_C(  21),  INT8_C(  20),  INT8_C(  65),  INT8_C(   2),  INT8_C(  24),  INT8_C(  66),  INT8_C(  19), -INT8_C(  77),
         INT8_C(  34), -INT8_C(  17), -INT8_C(  72), -INT8_C(  79), -INT8_C(  75), -INT8_C(  63), -INT8_C(  93),  INT8_C(  54),
        -INT8_C(  73),  INT8_C(  59),  INT8_C(  66),  INT8_C(  46), -INT8_C(  16),  INT8_C(  38),  INT8_C(  18),  INT8_C(  19) },
      {  INT8_C(  84),  INT8_C(  42),  INT8_C( 109),  INT8_C(   1), -INT8_C(  50),  INT8_C(  66), -INT8_C( 117), -INT8_C(  28),
         INT8_C(  86), -INT8_C(  52), -INT8_C(  26),  INT8_C( 110),  INT8_C(  14), -INT8_C(   7),  INT8_C(  34),  INT8_C(  48),
        -INT8_C(  24), -INT8_C(  38), -INT8_C(  30), -INT8_C(  98), -INT8_C( 101), -INT8_C( 123), -INT8_C(  44),  INT8_C(  82),
        -INT8_C(  64),  INT8_C(  22), -INT8_C( 127), -INT8_C(  80),  INT8_C(  61), -INT8_C( 109), -INT8_C(  60), -INT8_C( 111),
        -INT8_C(  66),  INT8_C(  49), -INT8_C( 109), -INT8_C( 116),  INT8_C( 115),  INT8_C(  30),  INT8_C( 112), -INT8_C(  54),
        -INT8_C(  22),  INT8_C(  86),  INT8_C(  56), -INT8_C(   8),  INT8_C(  80),  INT8_C(  90),  INT8_C(  40),  INT8_C(  56),
         INT8_C(  52),  INT8_C(  10), -INT8_C(  42), -INT8_C(  49), -INT8_C( 113), -INT8_C(  86),  INT8_C(  34),  INT8_C(  80),
        -INT8_C(  63), -INT8_C(  93),  INT8_C(   0), -INT8_C(   2),  INT8_C(  54), -INT8_C(  60), -INT8_C( 113), -INT8_C(  12) },
      {  INT8_C( 109),  INT8_C(  42),  INT8_C(  74),  INT8_C(  52),  INT8_C(  54),  INT8_C(  66), -INT8_C( 117),  INT8_C( 122),
        -INT8_C(  36), -INT8_C(  52),  INT8_C(  64),  INT8_C( 110),  INT8_C(  14), -INT8_C(   7),  INT8_C(   1),  INT8_C(  48),
        -INT8_C(  24), -INT8_C(  32), -INT8_C(  30), -INT8_C(  98), -INT8_C( 113), -INT8_C( 123), -INT8_C(  44),  INT8_C(  82),
        -INT8_C(  64),  INT8_C(  22), -INT8_C( 127),  INT8_C(  12),  INT8_C( 119), -INT8_C( 109), -INT8_C(  28), -INT8_C( 111),
         INT8_C(  35),  INT8_C(  46), -INT8_C( 109), -INT8_C( 116), -INT8_C(  83), -INT8_C(  92), -INT8_C(  44), -INT8_C(  54),
         INT8_C(  21),  INT8_C(  20),  INT8_C(  65),  INT8_C(   2),  INT8_C(  24),  INT8_C(  66),  INT8_C(  19),  INT8_C(  56),
         INT8_C(  34), -INT8_C(  17), -INT8_C(  42), -INT8_C(  49), -INT8_C( 113), -INT8_C(  63), -INT8_C(  93),  INT8_C(  54),
        -INT8_C(  63), -INT8_C(  93),  INT8_C(   0),  INT8_C(  46),  INT8_C(  54),  INT8_C(  38), -INT8_C( 113), -INT8_C(  12) } },
    { UINT64_C( 3041039432355488502),
      {  INT8_C(  72),  INT8_C( 108),  INT8_C(  34), -INT8_C( 104), -INT8_C(  58),  INT8_C(  75), -INT8_C(  48), -INT8_C(   5),
         INT8_C(  85), -INT8_C(  89), -INT8_C(  54), -INT8_C(  27),  INT8_C(  81), -INT8_C(  20),  INT8_C(  53),  INT8_C(  18),
        -INT8_C( 113),  INT8_C(  53),  INT8_C(  16), -INT8_C(  58), -INT8_C(   6), -INT8_C(  96), -INT8_C(  70), -INT8_C(  16),
        -INT8_C(  62),  INT8_C(  59),  INT8_C(  89),  INT8_C(   3),  INT8_C(  45), -INT8_C( 115),  INT8_C(  45),  INT8_C( 117),
        -INT8_C(   7),  INT8_C(  80),  INT8_C(  13), -INT8_C(  65), -INT8_C( 101), -INT8_C(  35), -INT8_C(  70), -INT8_C(  16),
        -INT8_C( 124), -INT8_C( 123), -INT8_C(  43), -INT8_C(  42),  INT8_C( 113),  INT8_C(  10), -INT8_C(  24),  INT8_C(   1),
         INT8_C(  64), -INT8_C(   7), -INT8_C(  57),  INT8_C(  58), -INT8_C( 103), -INT8_C( 127),  INT8_C(  42),  INT8_C(  91),
        -INT8_C(  67), -INT8_C( 125),  INT8_C(  94), -INT8_C(  22),  INT8_C(  16), -INT8_C( 116),  INT8_C(  95),  INT8_C(   9) },
      { -INT8_C(  36),  INT8_C( 108), -INT8_C(  55),  INT8_C( 119),  INT8_C(  73), -INT8_C( 125),  INT8_C( 103), -INT8_C(  50),
         INT8_C(   8),  INT8_C(  61), -INT8_C(  92),  INT8_C( 122),  INT8_C(  71), -INT8_C( 116),  INT8_C( 123), -INT8_C( 121),
        -INT8_C( 123),  INT8_C(  66), -INT8_C(  63),  INT8_C(  30), -INT8_C(  61), -INT8_C(  21),  INT8_C( 122),      INT8_MIN,
         INT8_C( 111), -INT8_C(  40),  INT8_C( 106),      INT8_MAX,  INT8_C( 100), -INT8_C(  55), -INT8_C( 119),  INT8_C(  64),
         INT8_C(  53),  INT8_C(  82), -INT8_C(  73),      INT8_MAX, -INT8_C(  43),  INT8_C(  31),  INT8_C(  77), -INT8_C(  34),
         INT8_C(  92), -INT8_C(  15),  INT8_C(  88), -INT8_C(  93),  INT8_C( 125), -INT8_C(  45),  INT8_C(  43),  INT8_C(   3),
         INT8_C(  21), -INT8_C(  20),  INT8_C(  33), -INT8_C(  40), -INT8_C(  40), -INT8_C( 101),  INT8_C(  89),  INT8_C(  71),
         INT8_C( 116), -INT8_C(  61), -INT8_C(  58), -INT8_C(  40), -INT8_C( 115),  INT8_C(  79),  INT8_C(  25), -INT8_C(  62) },
      {  INT8_C(  72),  INT8_C( 108), -INT8_C(  55), -INT8_C( 104),  INT8_C(  73), -INT8_C( 125),  INT8_C( 103), -INT8_C(  50),
         INT8_C(  85),  INT8_C(  61), -INT8_C(  54), -INT8_C(  27),  INT8_C(  81), -INT8_C( 116),  INT8_C(  53),  INT8_C(  18),
        -INT8_C( 123),  INT8_C(  53),  INT8_C(  16), -INT8_C(  58), -INT8_C(   6), -INT8_C(  96), -INT8_C(  70),      INT8_MIN,
         INT8_C( 111),  INT8_C(  59),  INT8_C(  89),      INT8_MAX,  INT8_C(  45), -INT8_C(  55), -INT8_C( 119),  INT8_C( 117),
        -INT8_C(   7),  INT8_C(  80),  INT8_C(  13), -INT8_C(  65), -INT8_C( 101), -INT8_C(  35),  INT8_C(  77), -INT8_C(  16),
         INT8_C(  92), -INT8_C( 123), -INT8_C(  43), -INT8_C(  42),  INT8_C( 125), -INT8_C(  45),  INT8_C(  43),  INT8_C(   3),
         INT8_C(  21), -INT8_C(  20), -INT8_C(  57),  INT8_C(  58), -INT8_C(  40), -INT8_C( 101),  INT8_C(  42),  INT8_C(  91),
        -INT8_C(  67), -INT8_C(  61),  INT8_C(  94), -INT8_C(  40),  INT8_C(  16),  INT8_C(  79),  INT8_C(  95),  INT8_C(   9) } },
    { UINT64_C( 5428402085014130849),
      {      INT8_MAX, -INT8_C(  83), -INT8_C(  17), -INT8_C(   3),      INT8_MIN,  INT8_C(  26),  INT8_C(   0), -INT8_C( 107),
         INT8_C(   6),  INT8_C(  33),  INT8_C( 109), -INT8_C(  34), -INT8_C(  67), -INT8_C(  58),  INT8_C(  37),  INT8_C(  49),
        -INT8_C( 118), -INT8_C(  20),  INT8_C(   9),  INT8_C(  23),  INT8_C(  59),  INT8_C(  34), -INT8_C(  39), -INT8_C(  35),
        -INT8_C(  13),  INT8_C(  27),  INT8_C(  84), -INT8_C(  30), -INT8_C(  87), -INT8_C(  87),  INT8_C(  46),  INT8_C(  41),
         INT8_C(  86),  INT8_C(  29),  INT8_C(  38), -INT8_C(  42),  INT8_C(  55),  INT8_C(  38),  INT8_C( 107),  INT8_C(  61),
         INT8_C(  71), -INT8_C(  40),  INT8_C(  28),  INT8_C(   4), -INT8_C(  97),  INT8_C(  65),  INT8_C(  53),  INT8_C(  41),
         INT8_C(  45),  INT8_C(  63),  INT8_C(  64),  INT8_C( 105),  INT8_C(  97),  INT8_C(  25),  INT8_C(  70),  INT8_C(  84),
         INT8_C(  52), -INT8_C( 102),  INT8_C(  55), -INT8_C(  34),  INT8_C(  67),  INT8_C( 101),  INT8_C(   7), -INT8_C( 103) },
      { -INT8_C( 126),  INT8_C(  45),  INT8_C( 111), -INT8_C(  71),  INT8_C(  83), -INT8_C(  38), -INT8_C(  10), -INT8_C( 102),
        -INT8_C(  78),  INT8_C(  18), -INT8_C(  97),  INT8_C(  81),  INT8_C(  84), -INT8_C(  44),  INT8_C( 122), -INT8_C( 127),
         INT8_C(  19), -INT8_C(  70), -INT8_C(  22),  INT8_C( 117), -INT8_C(  44),  INT8_C(  48), -INT8_C(  55),  INT8_C(   8),
        -INT8_C(  54),  INT8_C(   0), -INT8_C(  26),  INT8_C(  13),  INT8_C( 101), -INT8_C(  19), -INT8_C(  90), -INT8_C(  25),
         INT8_C(  26),  INT8_C(  21), -INT8_C(  96),  INT8_C( 109), -INT8_C(  17), -INT8_C( 105),  INT8_C(   8), -INT8_C(  94),
        -INT8_C(  87), -INT8_C(  89), -INT8_C(  13), -INT8_C(   3),  INT8_C( 123),  INT8_C( 110),      INT8_MAX, -INT8_C( 113),
         INT8_C(  40),  INT8_C( 105),  INT8_C(   4), -INT8_C(   4), -INT8_C( 102), -INT8_C(  51),  INT8_C(   5),  INT8_C( 100),
        -INT8_C(  50), -INT8_C(  21),  INT8_C( 114),  INT8_C(  51), -INT8_C(  39),  INT8_C(  24),  INT8_C(  27), -INT8_C(  13) },
      { -INT8_C( 126), -INT8_C(  83), -INT8_C(  17), -INT8_C(   3),      INT8_MIN, -INT8_C(  38),  INT8_C(   0), -INT8_C( 102),
         INT8_C(   6),  INT8_C(  33),  INT8_C( 109), -INT8_C(  34),  INT8_C(  84), -INT8_C(  58),  INT8_C( 122), -INT8_C( 127),
         INT8_C(  19), -INT8_C(  20),  INT8_C(   9),  INT8_C(  23),  INT8_C(  59),  INT8_C(  34), -INT8_C(  55), -INT8_C(  35),
        -INT8_C(  54),  INT8_C(   0), -INT8_C(  26), -INT8_C(  30),  INT8_C( 101), -INT8_C(  19), -INT8_C(  90),  INT8_C(  41),
         INT8_C(  26),  INT8_C(  21), -INT8_C(  96),  INT8_C( 109),  INT8_C(  55), -INT8_C( 105),  INT8_C(   8), -INT8_C(  94),
         INT8_C(  71), -INT8_C(  89), -INT8_C(  13), -INT8_C(   3), -INT8_C(  97),  INT8_C(  65),  INT8_C(  53), -INT8_C( 113),
         INT8_C(  40),  INT8_C(  63),  INT8_C(   4),  INT8_C( 105), -INT8_C( 102),  INT8_C(  25),  INT8_C(   5),  INT8_C(  84),
        -INT8_C(  50), -INT8_C(  21),  INT8_C(  55),  INT8_C(  51),  INT8_C(  67),  INT8_C( 101),  INT8_C(  27), -INT8_C( 103) } },
    { UINT64_C(18212391219510754094),
      {  INT8_C(  16), -INT8_C(  77), -INT8_C(   7), -INT8_C( 117),  INT8_C(  33),  INT8_C( 120),  INT8_C(  26),  INT8_C(  73),
        -INT8_C(  30),  INT8_C(  30),  INT8_C(  70),  INT8_C( 124), -INT8_C(  20),  INT8_C(  75), -INT8_C(  32), -INT8_C(  70),
         INT8_C(  54),  INT8_C(  82), -INT8_C(  19),  INT8_C(  15),  INT8_C( 107),  INT8_C(   8),  INT8_C(   3), -INT8_C( 103),
        -INT8_C(  60),  INT8_C( 100), -INT8_C(  74),  INT8_C(  22), -INT8_C(  51),  INT8_C( 118),  INT8_C(  18), -INT8_C(  35),
         INT8_C(  41),  INT8_C(  12),  INT8_C( 104),  INT8_C(  74), -INT8_C( 124), -INT8_C( 125), -INT8_C( 109),  INT8_C( 102),
        -INT8_C(  95), -INT8_C(  39), -INT8_C(  30), -INT8_C( 115),  INT8_C(  36), -INT8_C(  61),  INT8_C(  71),  INT8_C(  91),
         INT8_C(  21),  INT8_C(  53),  INT8_C( 106),      INT8_MIN,  INT8_C(  61),  INT8_C( 109),  INT8_C(  25),  INT8_C(   1),
        -INT8_C(  47), -INT8_C(  48),  INT8_C(  24), -INT8_C(  98),  INT8_C(  70),  INT8_C(  42),  INT8_C( 123),  INT8_C( 111) },
      {  INT8_C(  54), -INT8_C(  28), -INT8_C(  71), -INT8_C(  69),  INT8_C( 103),  INT8_C(  76),  INT8_C(  33),  INT8_C(   8),
         INT8_C(  38),  INT8_C(   4), -INT8_C( 106),  INT8_C(  74), -INT8_C(  57), -INT8_C(  35), -INT8_C(  91), -INT8_C(  36),
         INT8_C(  18),  INT8_C(  16),  INT8_C(  93),  INT8_C(  80),  INT8_C( 125),  INT8_C( 118),  INT8_C(  81),  INT8_C(  79),
         INT8_C(  70),  INT8_C( 105), -INT8_C(  19), -INT8_C( 116), -INT8_C( 108),  INT8_C( 105), -INT8_C(   5), -INT8_C(  54),
         INT8_C(  77), -INT8_C(  76), -INT8_C( 123), -INT8_C(  76),  INT8_C(   1), -INT8_C(  89), -INT8_C(  68),  INT8_C(  39),
        -INT8_C(  85),  INT8_C(  82),  INT8_C( 113),  INT8_C( 114),  INT8_C(  48),  INT8_C(  23),  INT8_C(  78),  INT8_C(  66),
         INT8_C(  39), -INT8_C(  85), -INT8_C( 110), -INT8_C(  92),  INT8_C(  34), -INT8_C(  28), -INT8_C(  13),  INT8_C( 104),
         INT8_C(  77), -INT8_C(  31), -INT8_C(  11), -INT8_C(  31),  INT8_C(  74), -INT8_C(  16), -INT8_C(  84), -INT8_C( 105) },
      {  INT8_C(  16), -INT8_C(  28), -INT8_C(  71), -INT8_C(  69),  INT8_C(  33),  INT8_C(  76),  INT8_C(  26),  INT8_C(  73),
         INT8_C(  38),  INT8_C(   4),  INT8_C(  70),  INT8_C(  74), -INT8_C(  57), -INT8_C(  35), -INT8_C(  32), -INT8_C(  36),
         INT8_C(  18),  INT8_C(  82), -INT8_C(  19),  INT8_C(  15),  INT8_C( 107),  INT8_C( 118),  INT8_C(  81), -INT8_C( 103),
         INT8_C(  70),  INT8_C( 100), -INT8_C(  19), -INT8_C( 116), -INT8_C( 108),  INT8_C( 118),  INT8_C(  18), -INT8_C(  35),
         INT8_C(  41), -INT8_C(  76),  INT8_C( 104),  INT8_C(  74),  INT8_C(   1), -INT8_C( 125), -INT8_C(  68),  INT8_C( 102),
        -INT8_C(  85), -INT8_C(  39), -INT8_C(  30),  INT8_C( 114),  INT8_C(  36),  INT8_C(  23),  INT8_C(  78),  INT8_C(  91),
         INT8_C(  39), -INT8_C(  85), -INT8_C( 110), -INT8_C(  92),  INT8_C(  34), -INT8_C(  28),  INT8_C(  25),  INT8_C( 104),
        -INT8_C(  47), -INT8_C(  48), -INT8_C(  11), -INT8_C(  31),  INT8_C(  74), -INT8_C(  16), -INT8_C(  84), -INT8_C( 105) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_blend_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_mask_blend_epi8(k, a, b);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_blend_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(3621238078),
      { -INT16_C( 16557), -INT16_C(  3372),  INT16_C( 11384),  INT16_C( 26031), -INT16_C( 28252), -INT16_C( 29324), -INT16_C( 23149),  INT16_C( 23418),
        -INT16_C( 18991), -INT16_C(   196),  INT16_C( 29968),  INT16_C( 16008),  INT16_C( 22588),  INT16_C( 31351),  INT16_C( 19981),  INT16_C( 24914),
         INT16_C(  9742), -INT16_C( 31149),  INT16_C(   850), -INT16_C(  2069),  INT16_C( 24724),  INT16_C( 10116), -INT16_C(   507), -INT16_C( 10622),
        -INT16_C( 16461), -INT16_C( 15403),  INT16_C( 23860),  INT16_C( 28674),  INT16_C( 31157), -INT16_C( 15381),  INT16_C( 15816), -INT16_C( 10716) },
      {  INT16_C( 30563), -INT16_C( 18852),  INT16_C( 18554),  INT16_C(  4013),  INT16_C( 12712), -INT16_C( 21194), -INT16_C( 18128), -INT16_C(  7293),
         INT16_C( 22648), -INT16_C( 21337), -INT16_C( 22091),  INT16_C( 27165),  INT16_C(  2082), -INT16_C(  5587),  INT16_C( 20805), -INT16_C( 22336),
         INT16_C(  7625),  INT16_C( 17246),  INT16_C(  2917),  INT16_C(  3410), -INT16_C( 30403),  INT16_C( 28090),  INT16_C( 15682), -INT16_C( 17840),
        -INT16_C(  2155),  INT16_C( 19046), -INT16_C( 31840), -INT16_C( 15436), -INT16_C(  7541), -INT16_C( 12115),  INT16_C( 28211), -INT16_C(   903) },
      { -INT16_C( 16557), -INT16_C( 18852),  INT16_C( 18554),  INT16_C(  4013),  INT16_C( 12712), -INT16_C( 21194), -INT16_C( 23149),  INT16_C( 23418),
         INT16_C( 22648), -INT16_C(   196), -INT16_C( 22091),  INT16_C( 16008),  INT16_C(  2082), -INT16_C(  5587),  INT16_C( 19981), -INT16_C( 22336),
         INT16_C(  7625),  INT16_C( 17246),  INT16_C(  2917), -INT16_C(  2069), -INT16_C( 30403),  INT16_C( 10116),  INT16_C( 15682), -INT16_C( 17840),
        -INT16_C(  2155),  INT16_C( 19046), -INT16_C( 31840),  INT16_C( 28674), -INT16_C(  7541), -INT16_C( 15381),  INT16_C( 28211), -INT16_C(   903) } },
    { UINT32_C(4030781323),
      { -INT16_C( 27933),  INT16_C(  8445), -INT16_C( 18661),  INT16_C( 23949), -INT16_C(  8716), -INT16_C( 30441),  INT16_C( 32469),  INT16_C( 30163),
        -INT16_C( 30975), -INT16_C( 29384), -INT16_C(  6551), -INT16_C( 25251), -INT16_C( 10668), -INT16_C(  8295), -INT16_C(  9810), -INT16_C( 28209),
        -INT16_C( 13204), -INT16_C( 30799),  INT16_C( 16003),  INT16_C( 30693), -INT16_C(   997), -INT16_C(  4096), -INT16_C( 11398),  INT16_C( 31846),
        -INT16_C( 24998), -INT16_C( 15351),  INT16_C( 26244), -INT16_C( 10143), -INT16_C(  1475), -INT16_C(  5193), -INT16_C( 31020),  INT16_C( 16508) },
      {  INT16_C( 11602), -INT16_C( 10809), -INT16_C( 21397), -INT16_C( 31156),  INT16_C( 19625),  INT16_C(  9079), -INT16_C(  8929),  INT16_C( 31391),
        -INT16_C( 22405),  INT16_C(    62), -INT16_C( 24817),  INT16_C( 19672), -INT16_C( 28519),  INT16_C( 27959), -INT16_C( 19690),  INT16_C( 27053),
         INT16_C( 30176),  INT16_C( 19262), -INT16_C( 29919), -INT16_C( 13615),  INT16_C( 18647), -INT16_C(  2066), -INT16_C( 29403), -INT16_C( 24207),
        -INT16_C( 20682),  INT16_C( 17825),  INT16_C( 31054), -INT16_C(  6255), -INT16_C( 14327),  INT16_C(  8277),  INT16_C(   635),  INT16_C( 23433) },
      {  INT16_C( 11602), -INT16_C( 10809), -INT16_C( 18661), -INT16_C( 31156), -INT16_C(  8716), -INT16_C( 30441),  INT16_C( 32469),  INT16_C( 31391),
        -INT16_C( 22405),  INT16_C(    62), -INT16_C( 24817), -INT16_C( 25251), -INT16_C( 28519), -INT16_C(  8295), -INT16_C( 19690),  INT16_C( 27053),
        -INT16_C( 13204), -INT16_C( 30799),  INT16_C( 16003),  INT16_C( 30693), -INT16_C(   997), -INT16_C(  4096), -INT16_C( 29403),  INT16_C( 31846),
        -INT16_C( 24998), -INT16_C( 15351),  INT16_C( 26244), -INT16_C( 10143), -INT16_C( 14327),  INT16_C(  8277),  INT16_C(   635),  INT16_C( 23433) } },
    { UINT32_C(2577844087),
      {  INT16_C( 30546),  INT16_C( 10851),  INT16_C( 20928), -INT16_C(  6879), -INT16_C( 27937),  INT16_C(  5510),  INT16_C( 10049), -INT16_C( 28838),
        -INT16_C(  5215), -INT16_C( 21898), -INT16_C( 13389),  INT16_C( 11978),  INT16_C( 21454),  INT16_C( 17801),  INT16_C( 12059),  INT16_C( 28126),
         INT16_C( 17062),  INT16_C( 26263), -INT16_C( 18285),  INT16_C( 29260), -INT16_C( 11702), -INT16_C( 29817), -INT16_C(  7686), -INT16_C( 25830),
        -INT16_C( 28212),  INT16_C( 32581),  INT16_C(  4188),  INT16_C( 10925),  INT16_C( 13923),  INT16_C( 32368),  INT16_C( 20069),  INT16_C(  3308) },
      { -INT16_C( 31856),  INT16_C(  9330), -INT16_C( 16836), -INT16_C( 31082),  INT16_C(  7825), -INT16_C( 29934),  INT16_C( 11519), -INT16_C( 13274),
         INT16_C( 27581),  INT16_C(  6731), -INT16_C(  1669), -INT16_C(  8380), -INT16_C( 19409), -INT16_C( 27299),  INT16_C( 18691), -INT16_C( 27743),
         INT16_C(  5069),  INT16_C(  2487),  INT16_C( 20178),  INT16_C( 25487), -INT16_C( 24212),  INT16_C( 27630),  INT16_C(  5326), -INT16_C( 29897),
        -INT16_C( 31873), -INT16_C(  1115), -INT16_C(  5508), -INT16_C( 21542),  INT16_C( 14238), -INT16_C( 24256), -INT16_C(  7807),  INT16_C( 20021) },
      { -INT16_C( 31856),  INT16_C(  9330), -INT16_C( 16836), -INT16_C(  6879),  INT16_C(  7825), -INT16_C( 29934),  INT16_C( 11519), -INT16_C( 28838),
         INT16_C( 27581),  INT16_C(  6731), -INT16_C(  1669),  INT16_C( 11978),  INT16_C( 21454),  INT16_C( 17801),  INT16_C( 18691), -INT16_C( 27743),
         INT16_C( 17062),  INT16_C(  2487),  INT16_C( 20178),  INT16_C( 29260), -INT16_C( 11702),  INT16_C( 27630), -INT16_C(  7686), -INT16_C( 29897),
        -INT16_C( 31873),  INT16_C( 32581),  INT16_C(  4188), -INT16_C( 21542),  INT16_C( 14238),  INT16_C( 32368),  INT16_C( 20069),  INT16_C( 20021) } },
    { UINT32_C(3344428277),
      { -INT16_C(  6598), -INT16_C( 22998),  INT16_C(  6280),  INT16_C( 22034),  INT16_C( 18732), -INT16_C( 21535), -INT16_C( 30772),  INT16_C( 18598),
        -INT16_C( 32655),  INT16_C(  4084),  INT16_C( 13496),  INT16_C( 14769), -INT16_C(  6634),  INT16_C(  2951), -INT16_C(  8494),  INT16_C(  3538),
        -INT16_C(   828),  INT16_C( 19635), -INT16_C( 15084),  INT16_C( 16546), -INT16_C( 31729), -INT16_C(  9237), -INT16_C( 28149),  INT16_C( 31780),
         INT16_C(  6162), -INT16_C( 13685),  INT16_C( 15436),  INT16_C( 25091), -INT16_C( 30174), -INT16_C(  2707),  INT16_C( 16232),  INT16_C( 11522) },
      { -INT16_C( 19141),  INT16_C( 20345),  INT16_C(  7291), -INT16_C( 30065),  INT16_C( 31648), -INT16_C( 21659), -INT16_C( 30451),  INT16_C(  7975),
        -INT16_C( 19807), -INT16_C(  4374), -INT16_C(  4625),  INT16_C(  4432), -INT16_C( 16776), -INT16_C(  8186),  INT16_C(  2301),  INT16_C( 14605),
        -INT16_C( 30786),  INT16_C( 14728),  INT16_C(  6307),  INT16_C( 17347),  INT16_C( 10387), -INT16_C( 24338),  INT16_C(  5554),  INT16_C( 21439),
        -INT16_C( 22073), -INT16_C( 18879), -INT16_C( 28009),  INT16_C(  4040), -INT16_C( 12720),  INT16_C( 19951), -INT16_C(   553), -INT16_C( 27258) },
      { -INT16_C( 19141), -INT16_C( 22998),  INT16_C(  7291),  INT16_C( 22034),  INT16_C( 31648), -INT16_C( 21659), -INT16_C( 30451),  INT16_C(  7975),
        -INT16_C( 32655),  INT16_C(  4084), -INT16_C(  4625),  INT16_C(  4432), -INT16_C(  6634), -INT16_C(  8186),  INT16_C(  2301),  INT16_C( 14605),
        -INT16_C( 30786),  INT16_C( 14728),  INT16_C(  6307),  INT16_C( 16546),  INT16_C( 10387), -INT16_C(  9237),  INT16_C(  5554),  INT16_C( 31780),
        -INT16_C( 22073), -INT16_C( 18879), -INT16_C( 28009),  INT16_C( 25091), -INT16_C( 30174), -INT16_C(  2707), -INT16_C(   553), -INT16_C( 27258) } },
    { UINT32_C( 667815812),
      { -INT16_C( 28377), -INT16_C( 17814),  INT16_C( 22713),  INT16_C( 27482),  INT16_C(  6509),  INT16_C( 13503),  INT16_C(   195),  INT16_C( 23275),
        -INT16_C( 19566), -INT16_C(  7575),  INT16_C( 22657),  INT16_C( 22576), -INT16_C( 18859), -INT16_C(  9747), -INT16_C( 17467), -INT16_C(  5120),
         INT16_C( 27212),  INT16_C(  1702),  INT16_C(   194),  INT16_C( 12145),  INT16_C( 12314), -INT16_C(  8860),  INT16_C( 20273), -INT16_C( 15561),
        -INT16_C( 24574), -INT16_C( 31834), -INT16_C( 10504),  INT16_C( 20188), -INT16_C( 13940),  INT16_C( 21031),  INT16_C( 10373), -INT16_C( 11970) },
      { -INT16_C(  6766),  INT16_C( 21975),  INT16_C( 18917), -INT16_C(   124), -INT16_C(  6023), -INT16_C( 21796),  INT16_C(  4919),  INT16_C( 14702),
         INT16_C(  5299), -INT16_C( 21315), -INT16_C( 26134),  INT16_C( 30458),  INT16_C(  8546), -INT16_C(  6200),  INT16_C(  1865), -INT16_C(  9031),
        -INT16_C( 28436), -INT16_C( 11983), -INT16_C( 18983),  INT16_C( 21457), -INT16_C( 21090), -INT16_C( 10755),  INT16_C( 27585),  INT16_C( 29711),
        -INT16_C( 13185),  INT16_C( 26912),  INT16_C(  6757), -INT16_C( 14368), -INT16_C( 22468), -INT16_C( 31313),  INT16_C( 26799), -INT16_C( 25759) },
      { -INT16_C( 28377), -INT16_C( 17814),  INT16_C( 18917),  INT16_C( 27482),  INT16_C(  6509),  INT16_C( 13503),  INT16_C(   195),  INT16_C( 14702),
         INT16_C(  5299), -INT16_C( 21315), -INT16_C( 26134),  INT16_C( 30458), -INT16_C( 18859), -INT16_C(  9747), -INT16_C( 17467), -INT16_C(  5120),
         INT16_C( 27212), -INT16_C( 11983), -INT16_C( 18983),  INT16_C( 21457),  INT16_C( 12314), -INT16_C(  8860),  INT16_C( 27585),  INT16_C( 29711),
        -INT16_C( 13185),  INT16_C( 26912),  INT16_C(  6757),  INT16_C( 20188), -INT16_C( 13940), -INT16_C( 31313),  INT16_C( 10373), -INT16_C( 11970) } },
    { UINT32_C(3530396408),
      {  INT16_C( 15944), -INT16_C(  6619),  INT16_C(  8939), -INT16_C( 21317), -INT16_C( 13682),  INT16_C(  3361),  INT16_C( 16790), -INT16_C(  1161),
         INT16_C( 22364), -INT16_C( 26429),  INT16_C( 29439), -INT16_C( 20707),  INT16_C( 32730), -INT16_C( 11702), -INT16_C( 18671),  INT16_C( 22948),
        -INT16_C( 13835), -INT16_C(  7873), -INT16_C(  1044),  INT16_C( 31373), -INT16_C( 20795),  INT16_C( 23687), -INT16_C(   272),  INT16_C( 19543),
         INT16_C(  6741),  INT16_C( 21988),  INT16_C(   396),  INT16_C( 26116),  INT16_C( 20096), -INT16_C( 28103), -INT16_C(  8954), -INT16_C(  1045) },
      {  INT16_C( 11175), -INT16_C( 27684),  INT16_C( 27174), -INT16_C(  5363), -INT16_C( 27624),  INT16_C(  2119), -INT16_C( 24685), -INT16_C(  6060),
         INT16_C( 14521),  INT16_C( 17981),  INT16_C( 16698), -INT16_C( 17748), -INT16_C(  6768), -INT16_C( 27060),  INT16_C( 14531),  INT16_C( 27281),
         INT16_C( 28259), -INT16_C( 30211),  INT16_C(  2776), -INT16_C(  3980), -INT16_C( 17250),  INT16_C( 12793),  INT16_C( 19803),  INT16_C(  5146),
         INT16_C( 22406), -INT16_C( 16294),  INT16_C(  1945),  INT16_C( 10618), -INT16_C( 14356), -INT16_C( 20545),  INT16_C( 20735),  INT16_C( 25113) },
      {  INT16_C( 15944), -INT16_C(  6619),  INT16_C(  8939), -INT16_C(  5363), -INT16_C( 27624),  INT16_C(  2119), -INT16_C( 24685), -INT16_C(  6060),
         INT16_C( 22364),  INT16_C( 17981),  INT16_C( 29439), -INT16_C( 20707), -INT16_C(  6768), -INT16_C( 11702), -INT16_C( 18671),  INT16_C( 27281),
         INT16_C( 28259), -INT16_C(  7873),  INT16_C(  2776), -INT16_C(  3980), -INT16_C( 20795),  INT16_C( 12793),  INT16_C( 19803),  INT16_C( 19543),
         INT16_C(  6741), -INT16_C( 16294),  INT16_C(   396),  INT16_C( 26116), -INT16_C( 14356), -INT16_C( 28103),  INT16_C( 20735),  INT16_C( 25113) } },
    { UINT32_C(2531989182),
      {  INT16_C( 24352), -INT16_C( 16505), -INT16_C( 32741),  INT16_C( 30448),  INT16_C(  2765),  INT16_C( 21387), -INT16_C(  6814), -INT16_C(  1261),
        -INT16_C( 28948), -INT16_C(  9948), -INT16_C(  7339),  INT16_C( 21640), -INT16_C( 24013), -INT16_C(  3402), -INT16_C( 24136), -INT16_C(  9848),
         INT16_C(  3840),  INT16_C(  7320), -INT16_C( 30577),  INT16_C( 23954),  INT16_C(  7571), -INT16_C(  2640), -INT16_C( 15357), -INT16_C(  4112),
         INT16_C(  5202), -INT16_C( 22584),  INT16_C( 20983),  INT16_C( 11003), -INT16_C( 19981), -INT16_C( 21732), -INT16_C( 23214),  INT16_C( 21124) },
      {  INT16_C(  7348),  INT16_C( 17518),  INT16_C(   421),  INT16_C( 14497),  INT16_C( 20766),  INT16_C(  8493),  INT16_C(  7445),  INT16_C( 26385),
        -INT16_C(  9935),  INT16_C( 10254),  INT16_C(  2346),  INT16_C(  7506),  INT16_C( 28602),  INT16_C(  3273),  INT16_C( 19732), -INT16_C( 14241),
        -INT16_C( 12950),  INT16_C(  3852), -INT16_C( 21042), -INT16_C(  4793),  INT16_C( 29951),  INT16_C(  5134),  INT16_C(  8081), -INT16_C( 15748),
        -INT16_C( 29959),  INT16_C(  9194),  INT16_C( 15508),  INT16_C( 20033),  INT16_C(  2731), -INT16_C( 16549), -INT16_C( 17833), -INT16_C( 15992) },
      {  INT16_C( 24352),  INT16_C( 17518),  INT16_C(   421),  INT16_C( 14497),  INT16_C( 20766),  INT16_C(  8493), -INT16_C(  6814),  INT16_C( 26385),
        -INT16_C( 28948),  INT16_C( 10254),  INT16_C(  2346),  INT16_C( 21640),  INT16_C( 28602), -INT16_C(  3402), -INT16_C( 24136), -INT16_C(  9848),
        -INT16_C( 12950),  INT16_C(  3852), -INT16_C( 30577), -INT16_C(  4793),  INT16_C(  7571),  INT16_C(  5134),  INT16_C(  8081), -INT16_C( 15748),
         INT16_C(  5202),  INT16_C(  9194),  INT16_C( 15508),  INT16_C( 11003),  INT16_C(  2731), -INT16_C( 21732), -INT16_C( 23214), -INT16_C( 15992) } },
    { UINT32_C(1456510087),
      {  INT16_C(  5954),  INT16_C( 16707),  INT16_C( 20875),  INT16_C(  7253), -INT16_C( 11919),  INT16_C( 27358), -INT16_C( 14244), -INT16_C(  3955),
        -INT16_C( 12795), -INT16_C( 20418), -INT16_C( 26152),  INT16_C( 12400), -INT16_C(  1965), -INT16_C(  9231), -INT16_C( 15732), -INT16_C( 12751),
         INT16_C( 29913),  INT16_C( 25871),  INT16_C( 26053),  INT16_C( 13953),  INT16_C( 24630), -INT16_C( 28000),  INT16_C( 11816),  INT16_C( 11650),
        -INT16_C( 15876), -INT16_C( 10786),  INT16_C( 20058), -INT16_C( 20987), -INT16_C(  2490), -INT16_C( 11639), -INT16_C( 17736), -INT16_C( 27999) },
      { -INT16_C( 20434), -INT16_C(  3081),  INT16_C( 30741),  INT16_C( 19498), -INT16_C( 13608),  INT16_C(   478),  INT16_C( 25080), -INT16_C(  2770),
         INT16_C(  3106),  INT16_C( 31946), -INT16_C( 12454), -INT16_C( 24534), -INT16_C( 19515),  INT16_C( 32371),  INT16_C(  5229), -INT16_C( 25840),
         INT16_C(  1988), -INT16_C(  9585), -INT16_C( 18049),  INT16_C( 22566),  INT16_C(  1155),  INT16_C( 31833), -INT16_C( 30875), -INT16_C( 30863),
         INT16_C( 15252), -INT16_C(  4604),  INT16_C( 11786), -INT16_C( 12401),  INT16_C(   738),  INT16_C( 20301),  INT16_C( 23830), -INT16_C(  9493) },
      { -INT16_C( 20434), -INT16_C(  3081),  INT16_C( 30741),  INT16_C(  7253), -INT16_C( 11919),  INT16_C( 27358), -INT16_C( 14244), -INT16_C(  2770),
        -INT16_C( 12795), -INT16_C( 20418), -INT16_C( 12454),  INT16_C( 12400), -INT16_C( 19515), -INT16_C(  9231), -INT16_C( 15732), -INT16_C( 25840),
         INT16_C( 29913),  INT16_C( 25871),  INT16_C( 26053),  INT16_C( 13953),  INT16_C(  1155), -INT16_C( 28000), -INT16_C( 30875), -INT16_C( 30863),
        -INT16_C( 15876), -INT16_C(  4604),  INT16_C( 11786), -INT16_C( 20987),  INT16_C(   738), -INT16_C( 11639),  INT16_C( 23830), -INT16_C( 27999) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_blend_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_blend_epi16(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_blend_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { UINT16_C(12684),
      simde_mm512_set_epi32(INT32_C( 2139597246), INT32_C(-2035467821), INT32_C(-1381016544), INT32_C( -293624181),
                            INT32_C( 1610331725), INT32_C(  134146865), INT32_C(  837546022), INT32_C(-1561535917),
                            INT32_C(  522767958), INT32_C(  350987310), INT32_C( 1200416302), INT32_C( 1035712103),
                            INT32_C( -697441354), INT32_C(-1209277994), INT32_C( 1905768221), INT32_C(  941422574)),
      simde_mm512_set_epi32(INT32_C( -854245863), INT32_C(   77819890), INT32_C( -597706880), INT32_C(  -28687979),
                            INT32_C( 1384494246), INT32_C(-1885694903), INT32_C(  479641666), INT32_C(  436747778),
                            INT32_C( 1142933685), INT32_C(  -36150185), INT32_C(  234764144), INT32_C( -925516387),
                            INT32_C( 1528722995), INT32_C( 1957265461), INT32_C( -558613563), INT32_C(  535737103)),
      simde_mm512_set_epi32(INT32_C( 2139597246), INT32_C(-2035467821), INT32_C( -597706880), INT32_C(  -28687979),
                            INT32_C( 1610331725), INT32_C(  134146865), INT32_C(  837546022), INT32_C(  436747778),
                            INT32_C( 1142933685), INT32_C(  350987310), INT32_C( 1200416302), INT32_C( 1035712103),
                            INT32_C( 1528722995), INT32_C( 1957265461), INT32_C( 1905768221), INT32_C(  941422574)) },
    { UINT16_C(12889),
      simde_mm512_set_epi32(INT32_C(-1009854213), INT32_C(   19207470), INT32_C( 2053019824), INT32_C( 1679893080),
                            INT32_C( -761309092), INT32_C(-1797634461), INT32_C( 1499461014), INT32_C( -349931656),
                            INT32_C( 1308377490), INT32_C(-1862232386), INT32_C( -706282442), INT32_C( 1752887042),
                            INT32_C( 1045610342), INT32_C(   88096217), INT32_C(-1144289151), INT32_C( 1410502196)),
      simde_mm512_set_epi32(INT32_C( 1437842356), INT32_C(-1817562257), INT32_C(  808924311), INT32_C( 1765692072),
                            INT32_C(-1346910557), INT32_C(  -92284700), INT32_C( 1533217965), INT32_C( 1732689820),
                            INT32_C(-1401128233), INT32_C( -762168473), INT32_C(   97276971), INT32_C( 2145432631),
                            INT32_C(-1561525899), INT32_C(-2005427238), INT32_C( -455460474), INT32_C( -933959435)),
      simde_mm512_set_epi32(INT32_C(-1009854213), INT32_C(   19207470), INT32_C(  808924311), INT32_C( 1765692072),
                            INT32_C( -761309092), INT32_C(-1797634461), INT32_C( 1533217965), INT32_C( -349931656),
                            INT32_C( 1308377490), INT32_C( -762168473), INT32_C( -706282442), INT32_C( 2145432631),
                            INT32_C(-1561525899), INT32_C(   88096217), INT32_C(-1144289151), INT32_C( -933959435)) },
    { UINT16_C(18390),
      simde_mm512_set_epi32(INT32_C(  191788932), INT32_C(  410937469), INT32_C(  218604234), INT32_C( -632545043),
                            INT32_C(  246082482), INT32_C( 2029197195), INT32_C( 1188965621), INT32_C( -844747875),
                            INT32_C(  989502056), INT32_C( 2119540790), INT32_C(-1766179858), INT32_C(-1109416221),
                            INT32_C(-1963025204), INT32_C( -932958949), INT32_C(   47867627), INT32_C( -567270366)),
      simde_mm512_set_epi32(INT32_C(  558500028), INT32_C( 1400907983), INT32_C(-1581715774), INT32_C(  -29022872),
                            INT32_C( 1773849857), INT32_C( -311975417), INT32_C( 1183760637), INT32_C(-1160252785),
                            INT32_C( 2107838031), INT32_C( 1909470743), INT32_C(-2018375211), INT32_C(  267812095),
                            INT32_C( -225335539), INT32_C( -871226308), INT32_C( -872412082), INT32_C( 1435481672)),
      simde_mm512_set_epi32(INT32_C(  191788932), INT32_C( 1400907983), INT32_C(  218604234), INT32_C( -632545043),
                            INT32_C(  246082482), INT32_C( -311975417), INT32_C( 1183760637), INT32_C(-1160252785),
                            INT32_C( 2107838031), INT32_C( 1909470743), INT32_C(-1766179858), INT32_C(  267812095),
                            INT32_C(-1963025204), INT32_C( -871226308), INT32_C( -872412082), INT32_C( -567270366)) },
    { UINT16_C(46409),
      simde_mm512_set_epi32(INT32_C( -239336968), INT32_C( 1154172094), INT32_C( 1382102779), INT32_C(-1946237060),
                            INT32_C( -995869857), INT32_C( 1050338310), INT32_C(-2047829467), INT32_C( -881484106),
                            INT32_C(  -67227529), INT32_C( -510303256), INT32_C( -387177060), INT32_C( 2007995362),
                            INT32_C( 1596393504), INT32_C( 1716443052), INT32_C( 1056333857), INT32_C( -879795312)),
      simde_mm512_set_epi32(INT32_C(-1321156942), INT32_C(-1763902924), INT32_C( -145319736), INT32_C(  356975558),
                            INT32_C(  109934631), INT32_C( 1326272066), INT32_C(  723198088), INT32_C(-1812908400),
                            INT32_C( 1665386649), INT32_C( 1770577849), INT32_C(-2015166919), INT32_C(-1565649496),
                            INT32_C( 1045296779), INT32_C( 1401153164), INT32_C( -294475079), INT32_C(  378377774)),
      simde_mm512_set_epi32(INT32_C(-1321156942), INT32_C( 1154172094), INT32_C( -145319736), INT32_C(  356975558),
                            INT32_C( -995869857), INT32_C( 1326272066), INT32_C(-2047829467), INT32_C(-1812908400),
                            INT32_C(  -67227529), INT32_C( 1770577849), INT32_C( -387177060), INT32_C( 2007995362),
                            INT32_C( 1045296779), INT32_C( 1716443052), INT32_C( 1056333857), INT32_C(  378377774)) },
    { UINT16_C(35033),
      simde_mm512_set_epi32(INT32_C(  576121858), INT32_C(  -83274089), INT32_C( 1081604364), INT32_C( 1853977291),
                            INT32_C(-1408149319), INT32_C(-1793071292), INT32_C( -580417531), INT32_C( 1708989591),
                            INT32_C(-1803428364), INT32_C(-1884594628), INT32_C(-1049896819), INT32_C( 1351777033),
                            INT32_C( -543435799), INT32_C(   45073785), INT32_C(  310971883), INT32_C(  586295496)),
      simde_mm512_set_epi32(INT32_C(  274706498), INT32_C( 1339140311), INT32_C(  773365916), INT32_C( -407443831),
                            INT32_C(  -44487881), INT32_C( -363465063), INT32_C( -778555208), INT32_C( -640038352),
                            INT32_C( -428291654), INT32_C(-1080717955), INT32_C(  906661653), INT32_C( 1353353955),
                            INT32_C(-1311936279), INT32_C( 1168846380), INT32_C(  -71806717), INT32_C(  617275327)),
      simde_mm512_set_epi32(INT32_C(  274706498), INT32_C(  -83274089), INT32_C( 1081604364), INT32_C( 1853977291),
                            INT32_C(  -44487881), INT32_C(-1793071292), INT32_C( -580417531), INT32_C( 1708989591),
                            INT32_C( -428291654), INT32_C(-1080717955), INT32_C(-1049896819), INT32_C( 1353353955),
                            INT32_C(-1311936279), INT32_C(   45073785), INT32_C(  310971883), INT32_C(  617275327)) },
    { UINT16_C(62826),
      simde_mm512_set_epi32(INT32_C( -943712419), INT32_C( -981833223), INT32_C( 2020022414), INT32_C(  630972788),
                            INT32_C( 1615502534), INT32_C(  991949979), INT32_C(  601817641), INT32_C(-2063962607),
                            INT32_C(-1545145030), INT32_C( 1626575612), INT32_C(-1511315708), INT32_C( 1422623346),
                            INT32_C( 1496301111), INT32_C(-1751918881), INT32_C(  333195983), INT32_C( 1655699275)),
      simde_mm512_set_epi32(INT32_C(-1770653828), INT32_C( -674401292), INT32_C(-2023667251), INT32_C( 1038799540),
                            INT32_C(-1877506849), INT32_C(  791301479), INT32_C(-2115975814), INT32_C( 1430860109),
                            INT32_C(-2123570597), INT32_C(-2010985064), INT32_C( 1367050649), INT32_C( -268988786),
                            INT32_C( 1975120887), INT32_C(   83320183), INT32_C( 2120549505), INT32_C(  163195572)),
      simde_mm512_set_epi32(INT32_C(-1770653828), INT32_C( -674401292), INT32_C(-2023667251), INT32_C( 1038799540),
                            INT32_C( 1615502534), INT32_C(  791301479), INT32_C(  601817641), INT32_C( 1430860109),
                            INT32_C(-1545145030), INT32_C(-2010985064), INT32_C( 1367050649), INT32_C( 1422623346),
                            INT32_C( 1975120887), INT32_C(-1751918881), INT32_C( 2120549505), INT32_C( 1655699275)) },
    { UINT16_C( 2185),
      simde_mm512_set_epi32(INT32_C( 1990735603), INT32_C( -226564964), INT32_C( 2030923034), INT32_C( 1100474296),
                            INT32_C( 1370205128), INT32_C( 1609607637), INT32_C( -586788969), INT32_C( 1072075481),
                            INT32_C( -723316478), INT32_C(-1331909036), INT32_C(-1524508879), INT32_C( -832646284),
                            INT32_C(-1636241911), INT32_C(  215718784), INT32_C(  478814832), INT32_C( 1231303010)),
      simde_mm512_set_epi32(INT32_C(   96871414), INT32_C(  245175863), INT32_C( 1584772139), INT32_C( 1604795180),
                            INT32_C(-1972440261), INT32_C(-1471456371), INT32_C( 1108051273), INT32_C(   -4141330),
                            INT32_C(-1064630270), INT32_C( -911670021), INT32_C(-1808660435), INT32_C(-2035294308),
                            INT32_C(-2014140232), INT32_C(-1194657062), INT32_C(-1732550793), INT32_C(-1643523135)),
      simde_mm512_set_epi32(INT32_C( 1990735603), INT32_C( -226564964), INT32_C( 2030923034), INT32_C( 1100474296),
                            INT32_C(-1972440261), INT32_C( 1609607637), INT32_C( -586788969), INT32_C( 1072075481),
                            INT32_C(-1064630270), INT32_C(-1331909036), INT32_C(-1524508879), INT32_C( -832646284),
                            INT32_C(-2014140232), INT32_C(  215718784), INT32_C(  478814832), INT32_C(-1643523135)) },
    { UINT16_C(11244),
      simde_mm512_set_epi32(INT32_C( 1605800253), INT32_C( 1825375434), INT32_C( -280209407), INT32_C( 1616462798),
                            INT32_C( 1380939760), INT32_C( 1670822362), INT32_C(-1872387325), INT32_C(  451486273),
                            INT32_C( -978012107), INT32_C( -718128180), INT32_C(-1625787118), INT32_C( -879101117),
                            INT32_C(  173600397), INT32_C( 1426384314), INT32_C( -517748272), INT32_C(   76760759)),
      simde_mm512_set_epi32(INT32_C(  805228357), INT32_C(  980137697), INT32_C( -555168446), INT32_C(-2016549382),
                            INT32_C(  927860791), INT32_C(-1515288559), INT32_C( -918296563), INT32_C(-1858382028),
                            INT32_C( 1365882699), INT32_C(  616589376), INT32_C(-1573056329), INT32_C( 1014781400),
                            INT32_C( -260360112), INT32_C( -953114112), INT32_C( 1191757764), INT32_C( -706360509)),
      simde_mm512_set_epi32(INT32_C( 1605800253), INT32_C( 1825375434), INT32_C( -555168446), INT32_C( 1616462798),
                            INT32_C(  927860791), INT32_C( 1670822362), INT32_C( -918296563), INT32_C(-1858382028),
                            INT32_C( 1365882699), INT32_C(  616589376), INT32_C(-1573056329), INT32_C( -879101117),
                            INT32_C( -260360112), INT32_C( -953114112), INT32_C( -517748272), INT32_C(   76760759)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_blend_epi32(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_blend_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {
    { UINT8_C(140),
      simde_mm512_set_epi64(INT64_C(-8742267720341431264), INT64_C(-1261106253099452851),
                            INT64_C(  576156398873473062), INT64_C(-6706745694521602474),
                            INT64_C( 1507479018961430062), INT64_C( 4448349614053909430),
                            INT64_C(-5193809434096716003), INT64_C( 4043379170809950035)),
      simde_mm512_set_epi64(INT64_C(  334233886225577856), INT64_C( -123213930208840538),
                            INT64_C(-8098997938139250622), INT64_C( 1875817424253601973),
                            INT64_C( -155263862084585616), INT64_C(-3975062612548356557),
                            INT64_C( 8406391148321717189), INT64_C( 2300973338778380734)),
      simde_mm512_set_epi64(INT64_C(  334233886225577856), INT64_C(-1261106253099452851),
                            INT64_C(  576156398873473062), INT64_C(-6706745694521602474),
                            INT64_C( -155263862084585616), INT64_C(-3975062612548356557),
                            INT64_C(-5193809434096716003), INT64_C( 4043379170809950035)) },
    { UINT8_C( 25),
      simde_mm512_set_epi64(INT64_C( 8817653003799568984), INT64_C(-3269797649790122397),
                            INT64_C( 6440136020702033784), INT64_C( 5619438532805301950),
                            INT64_C(-3033459988376129790), INT64_C( 4490862223337471449),
                            INT64_C(-4914684479302103500), INT64_C(  357175739365339737)),
      simde_mm512_set_epi64(INT64_C( 3474303462450025128), INT64_C(-5784936788749461276),
                            INT64_C( 6585121019047362460), INT64_C(-6017799934704469145),
                            INT64_C(  417801411244373047), INT64_C(-6706702665772459046),
                            INT64_C(-1956187837089650443), INT64_C(-4337290818543610578)),
      simde_mm512_set_epi64(INT64_C( 8817653003799568984), INT64_C(-3269797649790122397),
                            INT64_C( 6440136020702033784), INT64_C(-6017799934704469145),
                            INT64_C(  417801411244373047), INT64_C( 4490862223337471449),
                            INT64_C(-4914684479302103500), INT64_C(-4337290818543610578)) },
    { UINT8_C(111),
      simde_mm512_set_epi64(INT64_C(-2716760272685831246), INT64_C( 8715335590848900341),
                            INT64_C(-3628164495500993944), INT64_C( 9103358378116791278),
                            INT64_C(-4764906384514966324), INT64_C(-4007028174417664277),
                            INT64_C(-2436407666547579589), INT64_C( 1334270375494925236)),
      simde_mm512_set_epi64(INT64_C( -124652284302144255), INT64_C(-1339924211987201795),
                            INT64_C(-4983247764560081329), INT64_C( 8201114396130413013),
                            INT64_C( 1150244193567876877), INT64_C(-3741888496852267954),
                            INT64_C( 6165346835439187844), INT64_C( 1764962990274618058)),
      simde_mm512_set_epi64(INT64_C(-2716760272685831246), INT64_C(-1339924211987201795),
                            INT64_C(-4983247764560081329), INT64_C( 9103358378116791278),
                            INT64_C( 1150244193567876877), INT64_C(-3741888496852267954),
                            INT64_C( 6165346835439187844), INT64_C( 1764962990274618058)) },
    { UINT8_C(194),
      simde_mm512_set_epi64(INT64_C(-4277228465836858362), INT64_C(-8795360585136628042),
                            INT64_C( -288740034661227544), INT64_C(-1662912808453434398),
                            INT64_C( 6856457892943288236), INT64_C( 4536919372887712656),
                            INT64_C(-1781208167188155063), INT64_C( 2398739356475992271)),
      simde_mm512_set_epi64(INT64_C(  472165646169099842), INT64_C( 3106112138971788944),
                            INT64_C( 7152781194420608953), INT64_C(-8655076010356763224),
                            INT64_C( 4489515481820292748), INT64_C(-1264760833413638610),
                            INT64_C(-1027944449129626434), INT64_C( 5936086237864445820)),
      simde_mm512_set_epi64(INT64_C(  472165646169099842), INT64_C( 3106112138971788944),
                            INT64_C( -288740034661227544), INT64_C(-1662912808453434398),
                            INT64_C( 6856457892943288236), INT64_C( 4536919372887712656),
                            INT64_C(-1027944449129626434), INT64_C( 2398739356475992271)) },
    { UINT8_C(198),
      simde_mm512_set_epi64(INT64_C(-7701182554821916667), INT64_C( 7340054405040954868),
                            INT64_C(-8094272290232215411), INT64_C( 5805838151970444265),
                            INT64_C(  193590432792907243), INT64_C( 2518119983696523684),
                            INT64_C(-7781788212556415310), INT64_C(-7575905367749125944)),
      simde_mm512_set_epi64(INT64_C(-1561070555307167560), INT64_C(-2748943786159060550),
                            INT64_C(-4641648272018338027), INT64_C( 5812610979620286697),
                            INT64_C( 5020156980371149059), INT64_C( 2651177342668827650),
                            INT64_C( -357659487777588980), INT64_C( 7962771835258493113)),
      simde_mm512_set_epi64(INT64_C(-1561070555307167560), INT64_C(-2748943786159060550),
                            INT64_C(-8094272290232215411), INT64_C( 5805838151970444265),
                            INT64_C(  193590432792907243), INT64_C( 2651177342668827650),
                            INT64_C( -357659487777588980), INT64_C(-7575905367749125944)) },
    { UINT8_C( 55),
      simde_mm512_set_epi64(INT64_C( 2584787088481873425), INT64_C(-6636347369800363268),
                            INT64_C(-6491051538368462222), INT64_C( 6426564339256514271),
                            INT64_C( 1431065851799271243), INT64_C(-5052971989011532438),
                            INT64_C( 1179855426247829719), INT64_C( 3321581320948606601)),
      simde_mm512_set_epi64(INT64_C(-9088046918826118835), INT64_C(-9120666262578213480),
                            INT64_C( 5871437833456553614), INT64_C( 8483079615394831735),
                            INT64_C( 9107690773687184052), INT64_C(-4053213973120914951),
                            INT64_C( 8675930205947945332), INT64_C( 6938530551127078043)),
      simde_mm512_set_epi64(INT64_C( 2584787088481873425), INT64_C(-6636347369800363268),
                            INT64_C( 5871437833456553614), INT64_C( 8483079615394831735),
                            INT64_C( 1431065851799271243), INT64_C(-4053213973120914951),
                            INT64_C( 8675930205947945332), INT64_C( 6938530551127078043)) },
    { UINT8_C(103),
      simde_mm512_set_epi64(INT64_C( 4604529133310120194), INT64_C(-5720505748096428239),
                            INT64_C(-3576188556257202679), INT64_C(  926505122891702896),
                            INT64_C( 5288406162053320871), INT64_C(-5908713324082235524),
                            INT64_C(-2896531491248846387), INT64_C( 4461610053817304287)),
      simde_mm512_set_epi64(INT64_C(  -17786873681606654), INT64_C(-3915592922452326355),
                            INT64_C(-8741522488314124104), INT64_C(-5131013008663027849),
                            INT64_C(-7058878113053657357), INT64_C( -973089108768494310),
                            INT64_C( 4726501112778828744), INT64_C( 6913212164015017879)),
      simde_mm512_set_epi64(INT64_C( 4604529133310120194), INT64_C(-3915592922452326355),
                            INT64_C(-8741522488314124104), INT64_C(  926505122891702896),
                            INT64_C( 5288406162053320871), INT64_C( -973089108768494310),
                            INT64_C( 4726501112778828744), INT64_C( 6913212164015017879)) },
    { UINT8_C( 73),
      simde_mm512_set_epi64(INT64_C(-4200530011080213556), INT64_C(-6982702498652226749),
                            INT64_C(  745608029114000826), INT64_C(-2223711895723751753),
                            INT64_C( 4918324162995104748), INT64_C(  416059555292452407),
                            INT64_C( 6806544510221761324), INT64_C(-8471566411485193331)),
      simde_mm512_set_epi64(INT64_C( 5866421522993801280), INT64_C(-6756225486806034984),
                            INT64_C(-1118238162881043968), INT64_C( 5118560624722692931),
                            INT64_C( 6896859572368901322), INT64_C(-1203490237480090674),
                            INT64_C( 5931091108616911322), INT64_C(-8041842325868436927)),
      simde_mm512_set_epi64(INT64_C(-4200530011080213556), INT64_C(-6756225486806034984),
                            INT64_C(  745608029114000826), INT64_C(-2223711895723751753),
                            INT64_C( 6896859572368901322), INT64_C(  416059555292452407),
                            INT64_C( 6806544510221761324), INT64_C(-8041842325868436927)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_blend_epi64(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_blend_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {
    { UINT16_C(28658),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   986.64), SIMDE_FLOAT32_C(   121.90), SIMDE_FLOAT32_C(  -796.62), SIMDE_FLOAT32_C(   983.17),
                         SIMDE_FLOAT32_C(   569.02), SIMDE_FLOAT32_C(   -88.58), SIMDE_FLOAT32_C(  -750.53), SIMDE_FLOAT32_C(    52.16),
                         SIMDE_FLOAT32_C(   863.27), SIMDE_FLOAT32_C(  -937.53), SIMDE_FLOAT32_C(   272.85), SIMDE_FLOAT32_C(  -836.56),
                         SIMDE_FLOAT32_C(  -517.71), SIMDE_FLOAT32_C(   436.89), SIMDE_FLOAT32_C(  -561.62), SIMDE_FLOAT32_C(  -796.29)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   721.67), SIMDE_FLOAT32_C(  -355.29), SIMDE_FLOAT32_C(  -776.65), SIMDE_FLOAT32_C(  -467.78),
                         SIMDE_FLOAT32_C(  -890.68), SIMDE_FLOAT32_C(  -288.13), SIMDE_FLOAT32_C(   739.88), SIMDE_FLOAT32_C(    -3.67),
                         SIMDE_FLOAT32_C(   356.91), SIMDE_FLOAT32_C(  -250.13), SIMDE_FLOAT32_C(  -609.99), SIMDE_FLOAT32_C(  -756.57),
                         SIMDE_FLOAT32_C(  -441.01), SIMDE_FLOAT32_C(   675.23), SIMDE_FLOAT32_C(  -112.56), SIMDE_FLOAT32_C(   752.66)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   986.64), SIMDE_FLOAT32_C(  -355.29), SIMDE_FLOAT32_C(  -776.65), SIMDE_FLOAT32_C(   983.17),
                         SIMDE_FLOAT32_C(  -890.68), SIMDE_FLOAT32_C(  -288.13), SIMDE_FLOAT32_C(   739.88), SIMDE_FLOAT32_C(    -3.67),
                         SIMDE_FLOAT32_C(   356.91), SIMDE_FLOAT32_C(  -250.13), SIMDE_FLOAT32_C(  -609.99), SIMDE_FLOAT32_C(  -756.57),
                         SIMDE_FLOAT32_C(  -517.71), SIMDE_FLOAT32_C(   436.89), SIMDE_FLOAT32_C(  -112.56), SIMDE_FLOAT32_C(  -796.29)) },
    { UINT16_C(13167),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -177.79), SIMDE_FLOAT32_C(   957.03), SIMDE_FLOAT32_C(  -193.15), SIMDE_FLOAT32_C(   645.09),
                         SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(    66.15), SIMDE_FLOAT32_C(   565.09), SIMDE_FLOAT32_C(  -991.06),
                         SIMDE_FLOAT32_C(  -217.74), SIMDE_FLOAT32_C(   162.91), SIMDE_FLOAT32_C(   837.05), SIMDE_FLOAT32_C(   132.83),
                         SIMDE_FLOAT32_C(  -183.75), SIMDE_FLOAT32_C(  -958.98), SIMDE_FLOAT32_C(  -343.18), SIMDE_FLOAT32_C(  -412.04)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -623.32), SIMDE_FLOAT32_C(   372.80), SIMDE_FLOAT32_C(  -286.04), SIMDE_FLOAT32_C(   347.55),
                         SIMDE_FLOAT32_C(  -954.70), SIMDE_FLOAT32_C(   272.86), SIMDE_FLOAT32_C(   787.91), SIMDE_FLOAT32_C(   529.75),
                         SIMDE_FLOAT32_C(   -43.99), SIMDE_FLOAT32_C(   645.49), SIMDE_FLOAT32_C(  -301.76), SIMDE_FLOAT32_C(  -390.74),
                         SIMDE_FLOAT32_C(   671.11), SIMDE_FLOAT32_C(  -513.10), SIMDE_FLOAT32_C(   467.15), SIMDE_FLOAT32_C(  -961.27)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -177.79), SIMDE_FLOAT32_C(   957.03), SIMDE_FLOAT32_C(  -286.04), SIMDE_FLOAT32_C(   347.55),
                         SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(    66.15), SIMDE_FLOAT32_C(   787.91), SIMDE_FLOAT32_C(   529.75),
                         SIMDE_FLOAT32_C(  -217.74), SIMDE_FLOAT32_C(   645.49), SIMDE_FLOAT32_C(  -301.76), SIMDE_FLOAT32_C(   132.83),
                         SIMDE_FLOAT32_C(   671.11), SIMDE_FLOAT32_C(  -513.10), SIMDE_FLOAT32_C(   467.15), SIMDE_FLOAT32_C(  -961.27)) },
    { UINT16_C(10447),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   986.49), SIMDE_FLOAT32_C(   854.73), SIMDE_FLOAT32_C(   459.72), SIMDE_FLOAT32_C(  -110.83),
                         SIMDE_FLOAT32_C(  -875.29), SIMDE_FLOAT32_C(   594.30), SIMDE_FLOAT32_C(  -331.55), SIMDE_FLOAT32_C(  -808.64),
                         SIMDE_FLOAT32_C(   705.45), SIMDE_FLOAT32_C(   -55.08), SIMDE_FLOAT32_C(   606.63), SIMDE_FLOAT32_C(   -13.01),
                         SIMDE_FLOAT32_C(   483.39), SIMDE_FLOAT32_C(   565.56), SIMDE_FLOAT32_C(   735.84), SIMDE_FLOAT32_C(  -855.34)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   263.46), SIMDE_FLOAT32_C(  -173.99), SIMDE_FLOAT32_C(  -448.77), SIMDE_FLOAT32_C(   -18.46),
                         SIMDE_FLOAT32_C(    60.12), SIMDE_FLOAT32_C(   895.07), SIMDE_FLOAT32_C(   593.75), SIMDE_FLOAT32_C(  -910.69),
                         SIMDE_FLOAT32_C(  -898.20), SIMDE_FLOAT32_C(  -885.41), SIMDE_FLOAT32_C(  -446.34), SIMDE_FLOAT32_C(  -539.23),
                         SIMDE_FLOAT32_C(   177.56), SIMDE_FLOAT32_C(    85.90), SIMDE_FLOAT32_C(  -977.71), SIMDE_FLOAT32_C(   589.01)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   986.49), SIMDE_FLOAT32_C(   854.73), SIMDE_FLOAT32_C(  -448.77), SIMDE_FLOAT32_C(  -110.83),
                         SIMDE_FLOAT32_C(    60.12), SIMDE_FLOAT32_C(   594.30), SIMDE_FLOAT32_C(  -331.55), SIMDE_FLOAT32_C(  -808.64),
                         SIMDE_FLOAT32_C(  -898.20), SIMDE_FLOAT32_C(  -885.41), SIMDE_FLOAT32_C(   606.63), SIMDE_FLOAT32_C(   -13.01),
                         SIMDE_FLOAT32_C(   177.56), SIMDE_FLOAT32_C(    85.90), SIMDE_FLOAT32_C(  -977.71), SIMDE_FLOAT32_C(   589.01)) },
    { UINT16_C(64052),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -833.77), SIMDE_FLOAT32_C(  -382.41), SIMDE_FLOAT32_C(   155.80), SIMDE_FLOAT32_C(  -175.51),
                         SIMDE_FLOAT32_C(   270.94), SIMDE_FLOAT32_C(  -347.54), SIMDE_FLOAT32_C(  -823.80), SIMDE_FLOAT32_C(  -462.55),
                         SIMDE_FLOAT32_C(    93.71), SIMDE_FLOAT32_C(  -510.90), SIMDE_FLOAT32_C(   589.53), SIMDE_FLOAT32_C(   762.37),
                         SIMDE_FLOAT32_C(   -64.95), SIMDE_FLOAT32_C(  -200.72), SIMDE_FLOAT32_C(   590.31), SIMDE_FLOAT32_C(   904.10)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   932.33), SIMDE_FLOAT32_C(  -948.81), SIMDE_FLOAT32_C(  -663.23), SIMDE_FLOAT32_C(  -224.49),
                         SIMDE_FLOAT32_C(    61.61), SIMDE_FLOAT32_C(  -513.25), SIMDE_FLOAT32_C(   862.87), SIMDE_FLOAT32_C(   888.55),
                         SIMDE_FLOAT32_C(  -356.41), SIMDE_FLOAT32_C(   536.26), SIMDE_FLOAT32_C(    46.41), SIMDE_FLOAT32_C(   968.69),
                         SIMDE_FLOAT32_C(   819.71), SIMDE_FLOAT32_C(  -256.62), SIMDE_FLOAT32_C(  -508.11), SIMDE_FLOAT32_C(   806.88)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   932.33), SIMDE_FLOAT32_C(  -948.81), SIMDE_FLOAT32_C(  -663.23), SIMDE_FLOAT32_C(  -224.49),
                         SIMDE_FLOAT32_C(    61.61), SIMDE_FLOAT32_C(  -347.54), SIMDE_FLOAT32_C(   862.87), SIMDE_FLOAT32_C(  -462.55),
                         SIMDE_FLOAT32_C(    93.71), SIMDE_FLOAT32_C(  -510.90), SIMDE_FLOAT32_C(    46.41), SIMDE_FLOAT32_C(   968.69),
                         SIMDE_FLOAT32_C(   -64.95), SIMDE_FLOAT32_C(  -256.62), SIMDE_FLOAT32_C(   590.31), SIMDE_FLOAT32_C(   904.10)) },
    { UINT16_C(43223),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   810.27), SIMDE_FLOAT32_C(   830.75), SIMDE_FLOAT32_C(   701.96), SIMDE_FLOAT32_C(   496.75),
                         SIMDE_FLOAT32_C(  -369.80), SIMDE_FLOAT32_C(  -455.71), SIMDE_FLOAT32_C(  -712.56), SIMDE_FLOAT32_C(   961.22),
                         SIMDE_FLOAT32_C(  -136.67), SIMDE_FLOAT32_C(   165.04), SIMDE_FLOAT32_C(  -204.19), SIMDE_FLOAT32_C(   122.42),
                         SIMDE_FLOAT32_C(  -370.53), SIMDE_FLOAT32_C(  -979.01), SIMDE_FLOAT32_C(  -726.98), SIMDE_FLOAT32_C(   156.30)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -639.87), SIMDE_FLOAT32_C(   979.28), SIMDE_FLOAT32_C(   637.46), SIMDE_FLOAT32_C(   800.56),
                         SIMDE_FLOAT32_C(  -577.80), SIMDE_FLOAT32_C(   389.08), SIMDE_FLOAT32_C(   966.56), SIMDE_FLOAT32_C(  -731.72),
                         SIMDE_FLOAT32_C(  -496.34), SIMDE_FLOAT32_C(   344.28), SIMDE_FLOAT32_C(   729.72), SIMDE_FLOAT32_C(   160.21),
                         SIMDE_FLOAT32_C(   511.10), SIMDE_FLOAT32_C(   746.94), SIMDE_FLOAT32_C(  -855.19), SIMDE_FLOAT32_C(   203.47)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -639.87), SIMDE_FLOAT32_C(   830.75), SIMDE_FLOAT32_C(   637.46), SIMDE_FLOAT32_C(   496.75),
                         SIMDE_FLOAT32_C(  -577.80), SIMDE_FLOAT32_C(  -455.71), SIMDE_FLOAT32_C(  -712.56), SIMDE_FLOAT32_C(   961.22),
                         SIMDE_FLOAT32_C(  -496.34), SIMDE_FLOAT32_C(   344.28), SIMDE_FLOAT32_C(  -204.19), SIMDE_FLOAT32_C(   160.21),
                         SIMDE_FLOAT32_C(  -370.53), SIMDE_FLOAT32_C(   746.94), SIMDE_FLOAT32_C(  -855.19), SIMDE_FLOAT32_C(   203.47)) },
    { UINT16_C(29684),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -516.27), SIMDE_FLOAT32_C(  -631.52), SIMDE_FLOAT32_C(  -333.70), SIMDE_FLOAT32_C(    63.56),
                         SIMDE_FLOAT32_C(   874.74), SIMDE_FLOAT32_C(  -961.20), SIMDE_FLOAT32_C(  -924.01), SIMDE_FLOAT32_C(   542.80),
                         SIMDE_FLOAT32_C(  -706.18), SIMDE_FLOAT32_C(  -538.09), SIMDE_FLOAT32_C(    38.89), SIMDE_FLOAT32_C(  -242.57),
                         SIMDE_FLOAT32_C(  -337.54), SIMDE_FLOAT32_C(   184.20), SIMDE_FLOAT32_C(  -229.00), SIMDE_FLOAT32_C(  -133.06)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    57.66), SIMDE_FLOAT32_C(   125.72), SIMDE_FLOAT32_C(    14.67), SIMDE_FLOAT32_C(    11.14),
                         SIMDE_FLOAT32_C(  -363.42), SIMDE_FLOAT32_C(   -80.26), SIMDE_FLOAT32_C(   -12.54), SIMDE_FLOAT32_C(   560.55),
                         SIMDE_FLOAT32_C(   -59.35), SIMDE_FLOAT32_C(  -247.72), SIMDE_FLOAT32_C(  -719.76), SIMDE_FLOAT32_C(   280.49),
                         SIMDE_FLOAT32_C(   296.24), SIMDE_FLOAT32_C(  -303.23), SIMDE_FLOAT32_C(  -844.84), SIMDE_FLOAT32_C(   452.16)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -516.27), SIMDE_FLOAT32_C(   125.72), SIMDE_FLOAT32_C(    14.67), SIMDE_FLOAT32_C(    11.14),
                         SIMDE_FLOAT32_C(   874.74), SIMDE_FLOAT32_C(  -961.20), SIMDE_FLOAT32_C(   -12.54), SIMDE_FLOAT32_C(   560.55),
                         SIMDE_FLOAT32_C(   -59.35), SIMDE_FLOAT32_C(  -247.72), SIMDE_FLOAT32_C(  -719.76), SIMDE_FLOAT32_C(   280.49),
                         SIMDE_FLOAT32_C(  -337.54), SIMDE_FLOAT32_C(  -303.23), SIMDE_FLOAT32_C(  -229.00), SIMDE_FLOAT32_C(  -133.06)) },
    { UINT16_C( 5687),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -252.71), SIMDE_FLOAT32_C(   314.80), SIMDE_FLOAT32_C(   998.07), SIMDE_FLOAT32_C(   575.47),
                         SIMDE_FLOAT32_C(    52.24), SIMDE_FLOAT32_C(   443.69), SIMDE_FLOAT32_C(   234.67), SIMDE_FLOAT32_C(   894.50),
                         SIMDE_FLOAT32_C(  -487.55), SIMDE_FLOAT32_C(  -250.47), SIMDE_FLOAT32_C(  -500.78), SIMDE_FLOAT32_C(   379.78),
                         SIMDE_FLOAT32_C(   612.27), SIMDE_FLOAT32_C(  -899.55), SIMDE_FLOAT32_C(  -426.63), SIMDE_FLOAT32_C(   359.38)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -262.03), SIMDE_FLOAT32_C(    81.51), SIMDE_FLOAT32_C(  -484.02), SIMDE_FLOAT32_C(   504.24),
                         SIMDE_FLOAT32_C(   157.78), SIMDE_FLOAT32_C(    62.09), SIMDE_FLOAT32_C(   193.22), SIMDE_FLOAT32_C(   -72.99),
                         SIMDE_FLOAT32_C(   -54.28), SIMDE_FLOAT32_C(  -361.95), SIMDE_FLOAT32_C(   726.76), SIMDE_FLOAT32_C(   663.18),
                         SIMDE_FLOAT32_C(   290.10), SIMDE_FLOAT32_C(   238.07), SIMDE_FLOAT32_C(  -777.03), SIMDE_FLOAT32_C(   227.93)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -252.71), SIMDE_FLOAT32_C(   314.80), SIMDE_FLOAT32_C(   998.07), SIMDE_FLOAT32_C(   504.24),
                         SIMDE_FLOAT32_C(    52.24), SIMDE_FLOAT32_C(    62.09), SIMDE_FLOAT32_C(   193.22), SIMDE_FLOAT32_C(   894.50),
                         SIMDE_FLOAT32_C(  -487.55), SIMDE_FLOAT32_C(  -250.47), SIMDE_FLOAT32_C(   726.76), SIMDE_FLOAT32_C(   663.18),
                         SIMDE_FLOAT32_C(   612.27), SIMDE_FLOAT32_C(   238.07), SIMDE_FLOAT32_C(  -777.03), SIMDE_FLOAT32_C(   227.93)) },
    { UINT16_C(46817),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(    60.97), SIMDE_FLOAT32_C(   294.39), SIMDE_FLOAT32_C(   134.62), SIMDE_FLOAT32_C(  -712.88),
                         SIMDE_FLOAT32_C(  -527.46), SIMDE_FLOAT32_C(   556.17), SIMDE_FLOAT32_C(   671.08), SIMDE_FLOAT32_C(  -149.99),
                         SIMDE_FLOAT32_C(  -247.28), SIMDE_FLOAT32_C(  -221.96), SIMDE_FLOAT32_C(  -789.76), SIMDE_FLOAT32_C(   665.60),
                         SIMDE_FLOAT32_C(   590.64), SIMDE_FLOAT32_C(  -335.79), SIMDE_FLOAT32_C(  -964.26), SIMDE_FLOAT32_C(   137.06)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   741.48), SIMDE_FLOAT32_C(  -567.93), SIMDE_FLOAT32_C(   572.38), SIMDE_FLOAT32_C(  -363.96),
                         SIMDE_FLOAT32_C(   267.49), SIMDE_FLOAT32_C(   878.76), SIMDE_FLOAT32_C(  -445.04), SIMDE_FLOAT32_C(  -252.24),
                         SIMDE_FLOAT32_C(   869.52), SIMDE_FLOAT32_C(  -356.95), SIMDE_FLOAT32_C(   128.10), SIMDE_FLOAT32_C(   544.58),
                         SIMDE_FLOAT32_C(   242.93), SIMDE_FLOAT32_C(  -919.16), SIMDE_FLOAT32_C(   758.90), SIMDE_FLOAT32_C(  -466.75)),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   741.48), SIMDE_FLOAT32_C(   294.39), SIMDE_FLOAT32_C(   572.38), SIMDE_FLOAT32_C(  -363.96),
                         SIMDE_FLOAT32_C(  -527.46), SIMDE_FLOAT32_C(   878.76), SIMDE_FLOAT32_C(  -445.04), SIMDE_FLOAT32_C(  -149.99),
                         SIMDE_FLOAT32_C(   869.52), SIMDE_FLOAT32_C(  -356.95), SIMDE_FLOAT32_C(   128.10), SIMDE_FLOAT32_C(   665.60),
                         SIMDE_FLOAT32_C(   590.64), SIMDE_FLOAT32_C(  -335.79), SIMDE_FLOAT32_C(  -964.26), SIMDE_FLOAT32_C(  -466.75)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_blend_ps(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_blend_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {
    { UINT8_C(211),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  863.27), SIMDE_FLOAT64_C( -937.53),
                         SIMDE_FLOAT64_C(  272.85), SIMDE_FLOAT64_C( -836.56),
                         SIMDE_FLOAT64_C( -517.71), SIMDE_FLOAT64_C(  436.89),
                         SIMDE_FLOAT64_C( -561.62), SIMDE_FLOAT64_C( -796.29)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  356.91), SIMDE_FLOAT64_C( -250.13),
                         SIMDE_FLOAT64_C( -609.99), SIMDE_FLOAT64_C( -756.57),
                         SIMDE_FLOAT64_C( -441.01), SIMDE_FLOAT64_C(  675.23),
                         SIMDE_FLOAT64_C( -112.56), SIMDE_FLOAT64_C(  752.66)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  356.91), SIMDE_FLOAT64_C( -250.13),
                         SIMDE_FLOAT64_C(  272.85), SIMDE_FLOAT64_C( -756.57),
                         SIMDE_FLOAT64_C( -517.71), SIMDE_FLOAT64_C(  436.89),
                         SIMDE_FLOAT64_C( -112.56), SIMDE_FLOAT64_C(  752.66)) },
    { UINT8_C( 25),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  721.67), SIMDE_FLOAT64_C( -355.29),
                         SIMDE_FLOAT64_C( -776.65), SIMDE_FLOAT64_C( -467.78),
                         SIMDE_FLOAT64_C( -890.68), SIMDE_FLOAT64_C( -288.13),
                         SIMDE_FLOAT64_C(  739.88), SIMDE_FLOAT64_C(   -3.67)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -963.76), SIMDE_FLOAT64_C(  986.64),
                         SIMDE_FLOAT64_C(  121.90), SIMDE_FLOAT64_C( -796.62),
                         SIMDE_FLOAT64_C(  983.17), SIMDE_FLOAT64_C(  569.02),
                         SIMDE_FLOAT64_C(  -88.58), SIMDE_FLOAT64_C( -750.53)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  721.67), SIMDE_FLOAT64_C( -355.29),
                         SIMDE_FLOAT64_C( -776.65), SIMDE_FLOAT64_C( -796.62),
                         SIMDE_FLOAT64_C(  983.17), SIMDE_FLOAT64_C( -288.13),
                         SIMDE_FLOAT64_C(  739.88), SIMDE_FLOAT64_C( -750.53)) },
    { UINT8_C( 46),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -217.74), SIMDE_FLOAT64_C(  162.91),
                         SIMDE_FLOAT64_C(  837.05), SIMDE_FLOAT64_C(  132.83),
                         SIMDE_FLOAT64_C( -183.75), SIMDE_FLOAT64_C( -958.98),
                         SIMDE_FLOAT64_C( -343.18), SIMDE_FLOAT64_C( -412.04)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  -43.99), SIMDE_FLOAT64_C(  645.49),
                         SIMDE_FLOAT64_C( -301.76), SIMDE_FLOAT64_C( -390.74),
                         SIMDE_FLOAT64_C(  671.11), SIMDE_FLOAT64_C( -513.10),
                         SIMDE_FLOAT64_C(  467.15), SIMDE_FLOAT64_C( -961.27)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -217.74), SIMDE_FLOAT64_C(  162.91),
                         SIMDE_FLOAT64_C( -301.76), SIMDE_FLOAT64_C(  132.83),
                         SIMDE_FLOAT64_C(  671.11), SIMDE_FLOAT64_C( -513.10),
                         SIMDE_FLOAT64_C(  467.15), SIMDE_FLOAT64_C( -412.04)) },
    { UINT8_C(180),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -623.32), SIMDE_FLOAT64_C(  372.80),
                         SIMDE_FLOAT64_C( -286.04), SIMDE_FLOAT64_C(  347.55),
                         SIMDE_FLOAT64_C( -954.70), SIMDE_FLOAT64_C(  272.86),
                         SIMDE_FLOAT64_C(  787.91), SIMDE_FLOAT64_C(  529.75)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  153.63), SIMDE_FLOAT64_C( -177.79),
                         SIMDE_FLOAT64_C(  957.03), SIMDE_FLOAT64_C( -193.15),
                         SIMDE_FLOAT64_C(  645.09), SIMDE_FLOAT64_C(   -0.96),
                         SIMDE_FLOAT64_C(   66.15), SIMDE_FLOAT64_C(  565.09)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  153.63), SIMDE_FLOAT64_C(  372.80),
                         SIMDE_FLOAT64_C(  957.03), SIMDE_FLOAT64_C( -193.15),
                         SIMDE_FLOAT64_C( -954.70), SIMDE_FLOAT64_C(   -0.96),
                         SIMDE_FLOAT64_C(  787.91), SIMDE_FLOAT64_C(  529.75)) },
    { UINT8_C(125),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  705.45), SIMDE_FLOAT64_C(  -55.08),
                         SIMDE_FLOAT64_C(  606.63), SIMDE_FLOAT64_C(  -13.01),
                         SIMDE_FLOAT64_C(  483.39), SIMDE_FLOAT64_C(  565.56),
                         SIMDE_FLOAT64_C(  735.84), SIMDE_FLOAT64_C( -855.34)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -898.20), SIMDE_FLOAT64_C( -885.41),
                         SIMDE_FLOAT64_C( -446.34), SIMDE_FLOAT64_C( -539.23),
                         SIMDE_FLOAT64_C(  177.56), SIMDE_FLOAT64_C(   85.90),
                         SIMDE_FLOAT64_C( -977.71), SIMDE_FLOAT64_C(  589.01)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  705.45), SIMDE_FLOAT64_C( -885.41),
                         SIMDE_FLOAT64_C( -446.34), SIMDE_FLOAT64_C( -539.23),
                         SIMDE_FLOAT64_C(  177.56), SIMDE_FLOAT64_C(   85.90),
                         SIMDE_FLOAT64_C(  735.84), SIMDE_FLOAT64_C(  589.01)) },
    { UINT8_C(188),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  263.46), SIMDE_FLOAT64_C( -173.99),
                         SIMDE_FLOAT64_C( -448.77), SIMDE_FLOAT64_C(  -18.46),
                         SIMDE_FLOAT64_C(   60.12), SIMDE_FLOAT64_C(  895.07),
                         SIMDE_FLOAT64_C(  593.75), SIMDE_FLOAT64_C( -910.69)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -347.65), SIMDE_FLOAT64_C(  986.49),
                         SIMDE_FLOAT64_C(  854.73), SIMDE_FLOAT64_C(  459.72),
                         SIMDE_FLOAT64_C( -110.83), SIMDE_FLOAT64_C( -875.29),
                         SIMDE_FLOAT64_C(  594.30), SIMDE_FLOAT64_C( -331.55)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -347.65), SIMDE_FLOAT64_C( -173.99),
                         SIMDE_FLOAT64_C(  854.73), SIMDE_FLOAT64_C(  459.72),
                         SIMDE_FLOAT64_C( -110.83), SIMDE_FLOAT64_C( -875.29),
                         SIMDE_FLOAT64_C(  593.75), SIMDE_FLOAT64_C( -910.69)) },
    { UINT8_C(190),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(   93.71), SIMDE_FLOAT64_C( -510.90),
                         SIMDE_FLOAT64_C(  589.53), SIMDE_FLOAT64_C(  762.37),
                         SIMDE_FLOAT64_C(  -64.95), SIMDE_FLOAT64_C( -200.72),
                         SIMDE_FLOAT64_C(  590.31), SIMDE_FLOAT64_C(  904.10)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -356.41), SIMDE_FLOAT64_C(  536.26),
                         SIMDE_FLOAT64_C(   46.41), SIMDE_FLOAT64_C(  968.69),
                         SIMDE_FLOAT64_C(  819.71), SIMDE_FLOAT64_C( -256.62),
                         SIMDE_FLOAT64_C( -508.11), SIMDE_FLOAT64_C(  806.88)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -356.41), SIMDE_FLOAT64_C( -510.90),
                         SIMDE_FLOAT64_C(   46.41), SIMDE_FLOAT64_C(  968.69),
                         SIMDE_FLOAT64_C(  819.71), SIMDE_FLOAT64_C( -256.62),
                         SIMDE_FLOAT64_C( -508.11), SIMDE_FLOAT64_C(  904.10)) },
    { UINT8_C(178),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  932.33), SIMDE_FLOAT64_C( -948.81),
                         SIMDE_FLOAT64_C( -663.23), SIMDE_FLOAT64_C( -224.49),
                         SIMDE_FLOAT64_C(   61.61), SIMDE_FLOAT64_C( -513.25),
                         SIMDE_FLOAT64_C(  862.87), SIMDE_FLOAT64_C(  888.55)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  178.62), SIMDE_FLOAT64_C( -833.77),
                         SIMDE_FLOAT64_C( -382.41), SIMDE_FLOAT64_C(  155.80),
                         SIMDE_FLOAT64_C( -175.51), SIMDE_FLOAT64_C(  270.94),
                         SIMDE_FLOAT64_C( -347.54), SIMDE_FLOAT64_C( -823.80)),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  178.62), SIMDE_FLOAT64_C( -948.81),
                         SIMDE_FLOAT64_C( -382.41), SIMDE_FLOAT64_C(  155.80),
                         SIMDE_FLOAT64_C(   61.61), SIMDE_FLOAT64_C( -513.25),
                         SIMDE_FLOAT64_C( -347.54), SIMDE_FLOAT64_C(  888.55)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_blend_pd(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_blend_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_blend_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_blend_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_blend_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_blend_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_blend_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_blend_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_blend_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_blend_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_blend_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_blend_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_blend_pd)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_blend_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_blend_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_blend_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_blend_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_blend_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_blend_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
